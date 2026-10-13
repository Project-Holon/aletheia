/*
 * file:     btl_client.c
 * unit:     yes
 * function: func_021CD6F0, func_021CD8E0, func_021CD914, func_021CD924, func_021CD938, func_021CD95C, func_021CD960, func_021CD978, func_021CD97C, func_021CD984, func_021CD9B0, func_021CD9C8, func_021CD9DC, func_021CD9E0, func_021CD9F4, func_021CDA0C, func_021CDA18, func_021CDC0C, func_021CDD34, func_021CDD50, func_021CDD94, func_021CDDA0, func_021CDDCC, func_021CDDDC, func_021CDE8C, func_021CDECC, func_021CDEE8, func_021CDF1C, func_021CDF58, func_021CDFE4, func_021CE040, func_021CE044, func_021CE068, func_021CE08C, func_021CE0BC, func_021CE0E0, func_021CE0F8, func_021CE150, func_021CE160, func_021CE170, func_021CE1B0, func_021CE2E8, func_021CE308, func_021CE3B4, func_021CE3C8, func_021CE4D0, func_021CE7D4, func_021CE8F0, func_021CEA94, func_021CECB4, func_021CED4C, func_021CEDC0, func_021CEEB8, func_021CEFFC, func_021CF078, func_021CF220, func_021CF2F0, func_021CF360, func_021CF37C, func_021CF3B8, func_021CF3F8, func_021CF41C, func_021CF430, func_021CF448, func_021CF470, func_021CF524, func_021CF58C, func_021CF5B0, func_021CF81C, func_021CF89C, func_021CF8D4, func_021CF918, func_021CF9B4, func_021CFAC4, func_021CFADC, func_021CFB8C, func_021CFBA4, func_021CFBBC, func_021CFBE0, func_021CFBF0, func_021CFD50, func_021CFDCC, func_021CFE08, func_021CFE98, func_021CFFAC, func_021D0100, func_021D0248, func_021D0304, func_021D04E4, func_021D055C, func_021D05C4, func_021D0644, func_021D06C8, func_021D0770, func_021D0980, func_021D09E0, func_021D0B10, func_021D0B6C, func_021D0BB0, func_021D0C78, func_021D0CC4, func_021D0D38, func_021D0D44, func_021D0D50, func_021D0E7C, func_021D102C, func_021D1058, func_021D10B8, func_021D123C, func_021D127C, func_021D1290, func_021D13A4, func_021D13FC, func_021D1410, func_021D1708, func_021D171C, func_021D185C, func_021D18EC, func_021D1960, func_021D1A18, func_021D1A60, func_021D1A74, func_021D1BD0, func_021D1C40, func_021D1CAC, func_021D1CF4, func_021D1DF4, func_021D1E6C, func_021D1EB4, func_021D1F10, func_021D1F58, func_021D1FB4, func_021D2000, func_021D2030, func_021D20BC, func_021D210C, func_021D215C, func_021D21D4, func_021D2234, func_021D2278, func_021D2320, func_021D2374, func_021D23B8, func_021D2424, func_021D2490, func_021D2510, func_021D2580, func_021D25C4, func_021D2628, func_021D266C, func_021D2700, func_021D2814, func_021D284C, func_021D28AC, func_021D2930, func_021D2990, func_021D299C, func_021D29CC, func_021D2A20, func_021D2C7C, func_021D2CA8, func_021D2FD8, func_021D3138, func_021D31A0, func_021D324C, func_021D32E0, func_021D344C, func_021D34B0, func_021D34E8
 * address:  0x021CD6F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from btl_server.c (lane L189): __FILE__ anchor 021CD8CC (d_021F3A88 "btl_client.c") used by the 0x1b8-byte BtlClient constructor 021CD6F0, which is the first function of the file.
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
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   func_021B8D38  0x021B8D38  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8DC0  0x021B8DC0  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021B8E28  0x021B8E28  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B902C  0x021B902C  thumb  ov093
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021B9064  0x021B9064  thumb  ov093
 *   func_021B9090  0x021B9090  thumb  ov093
 *   func_021B90BC  0x021B90BC  thumb  ov093
 *   func_021B90F8  0x021B90F8  thumb  ov093
 *   func_021B916C  0x021B916C  thumb  ov093
 *   func_021B9184  0x021B9184  thumb  ov093
 *   func_021B919C  0x021B919C  thumb  ov093
 *   func_021B9210  0x021B9210  thumb  ov093
 *   func_021B9244  0x021B9244  thumb  ov093
 *   func_021B92A0  0x021B92A0  thumb  ov093
 *   func_021B9358  0x021B9358  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021B990C  0x021B990C  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B99C0  0x021B99C0  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021B9C50  0x021B9C50  thumb  ov093
 *   func_021B9CBC  0x021B9CBC  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B9FBC  0x021B9FBC  thumb  ov093
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021BA020  0x021BA020  thumb  ov093
 *   func_021BA02C  0x021BA02C  thumb  ov093
 *   func_021BA08C  0x021BA08C  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021BA1EC  0x021BA1EC  thumb  ov093
 *   func_021BA238  0x021BA238  thumb  ov093
 *   func_021BA2D4  0x021BA2D4  thumb  ov093
 *   func_021BA5C4  0x021BA5C4  thumb  ov093
 *   func_021BA5D0  0x021BA5D0  thumb  ov093
 *   func_021BA73C  0x021BA73C  thumb  ov093
 *   func_021BA7F8  0x021BA7F8  thumb  ov093
 *   func_021BA820  0x021BA820  thumb  ov093
 *   func_021BB4E0  0x021BB4E0  thumb  ov093
 *   func_021BB570  0x021BB570  thumb  ov093
 *   func_021CD5E0  0x021CD5E0  thumb  ov093
 *   func_021CD644  0x021CD644  thumb  ov093
 */
#include "btl_server_types.h"
#include "../../matched/include/G_StateData.h"

#define ENTRY(i) (&e[i])
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct Unk021B8CB0;
struct R4;
struct S2;
struct Q1;
struct S_021B8CB0;
struct Party;
struct U16Vec;
struct Rec8;
struct Buf;
struct Sub02008C20Obj;
struct Unk021D62A8;
struct Flags;
struct T;
struct QA;
struct Q5;
struct Q7;
struct Q6;
struct Q4;
struct UtilWork;
struct Unk021D82FC;
struct Arr;
struct Msg;
struct O;
struct Out64B4;
struct Unk021BE518;
struct Unk021D82D0;
struct UtilSlots;
struct QL;
struct QI;
struct S_p12;
struct Q_021C0CB4;
struct Q_021C0CE8;
struct QJ;
struct Entry_p11;
struct Obj;
struct Result;
struct Pack;
struct Rec;
struct Q9;
struct Cmd;
struct Q10;
struct S_p14;
struct Unk021D6C50;
struct Unk021D6C2C;
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

typedef unsigned long long u64;

#include "btl_client_types.h"

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

/* 021BA5D0  movs r1,#0x11; lsls r1,#6; ldrh r0,[r0,r1] */
struct Q3 { u8 pad[0x440]; u16 v; };

struct T {
    int w[6];
};

/* 021BB840  strb r1,[r0,#0xb]; str r2,[r0]; strb r3,[r0,#0xa] */
struct Q4 { u32 w; u8 pad[6]; u8 c; u8 b; };

/* 021BB964  ldr r0,[r0,#0x44] */
struct Q5 { u8 pad[0x44]; u32 v; };

struct Unk021BE518 { u8 f0; u8 f1[6]; };

struct Buf { u32 wpos, rpos; };

struct S { u32 id[6]; u16 a[6], b[6]; u8 c[6]; u16 d[6]; u8 n, max, f44, f45; };

struct Rec { u32 value; u16 kind; u8 data, flag; };

struct O { u32 pos; struct Rec r[120]; };

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

/* 021C8138  ldr r0,[r0,#0x10]; lsls r0,#0x10; lsrs r0,#0x10 */
struct Q7 { u8 pad[0x10]; u32 v; };

struct S_p12 {
    u16 x;
    u16 y : 8;
    u16 n : 7;
    u16 z : 1;
    u32 arr[8];
};

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

struct Cmd { u32 a:8; u32 id:5; u32 b:19; };

struct Flags { u32 a:1; u32 b:31; };

struct T6 { u8 f0; u8 f1; u16 f2; u16 f4; };

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

struct Pack {
    u32 lo : 10;
    u32 off : 9;
    u32 rest : 13;
    u8 data[500];
};

/* 021CD95C  str r1,[r0,#0x54] */
struct QA { u8 pad[0x54]; u32 v; };

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };

typedef struct { u8 id; u8 flag; u16 pad; BtlClientStepFn callbacks[3]; } Entry_021CC768;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;

struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };

typedef enum { OFFSET = 0x19a } Off;

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

struct Row { u8 kind; u8 pad; u16 ids[4]; };

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

typedef struct { u8 pad[0x1B3]; volatile u8 count; } CountField;

typedef struct { int code; BtlClientSeqFn fn; } CodeEntry;

typedef struct { u16 a; u16 b; } Pair16;

struct StateDataL { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };

union DView { struct StateDataL s; u32 w[9]; };

extern int func_021D5B68(void *m);
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern int func_021B86C8(unsigned char **p);
extern void *func_021B86B8(void ***p);
extern void *func_021D5844(void *m);
extern int func_021D6C24(struct R4 *p);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void POKEPARTY_Init(struct Party *p);
extern u32 func_021B8588(void **p);
extern int func_021D5B7C(void *);
extern u32 func_020307B0(void *p);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern u32 sub_02008DF0(struct Sub02008C20Obj *, int);
extern u32 sub_02008DAC(struct Sub02008C20Obj *, int, u32);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_021D805C(void *p, u32 n);
extern u32 _u32_div_f(u32, u32);
extern void *func_02030734(u16, unsigned int, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern void func_021EEAE0(void *p);
extern u8 func_021B86C0(u8 **p);
extern u32 func_021D8454(Action *);
extern u16 func_021B86DC(void **);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_02082BCC(void *, int, u32);
extern void func_021D8230(u8 *p);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_0201BD28(u32 v, u32 n);
extern u32 func_021D8340(Action *m);
extern int func_021B86E4(unsigned int **p);
extern union Slot func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Slot v);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int WAZA_TOOL_GetFlag(void *bag, int item);
extern u32 WAZA_TOOL_GetCategory(u16);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern int func_021D5C30(struct UtilWork *p);
extern u32 func_021D5584(struct UtilWork *p, u32 i);
extern u16 func_021D67B8(u8 *);
extern u16 func_021D67A8(struct QL *p);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern unsigned int func_021B8590(unsigned char *p);
extern u32 WAZA_TOOL_GetCategory(u16 move);
extern u16 func_021D5B40(struct QI *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern u16 func_021D57FC(void *);
extern int func_021D5B48(u8 *p);
extern int func_021D7AD4(int);
extern void func_021D66D0(struct QJ *p, u32 v);
extern u32 func_0203F0A8(void);
extern void func_021D646C(u8 *);
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern u8 WAZA_TOOL_GetType(void *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern int func_021D5814(void *p, int k);
extern u16 WAZA_TOOL_GetPower(void *p);
unsigned int func_021B8670(unsigned int **p);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void func_021D3F04(u8 *);
extern void func_021D3D9C(u8 *);
extern void *func_02187F00(void **, u32, u32, u32, u16);
extern void *func_021EE5E4(u32);
extern void func_021EE600(void *);
extern void func_02188080(void *);
extern u16 *func_021EE63C(u16 *, u32 *);
extern u32 func_021EE830(void *);
extern void func_021D3F48(u8 *,u32);
extern void func_021EE674(void *);
extern void func_021EEBDC(void *);
extern void func_021D3F64(u8 *,u16);
extern void func_021D3F88(void *p);
extern void func_021D3FDC(u8 *p, struct Qd *q);
extern u8 func_021EEBE8(void *);
extern int func_021EEC20(int, void *);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int func_021EEC4C(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern int GFL_USE_IsBgmFading(void);
extern u16 func_021D3FA8(u8 *p);
extern void PM_VOICE_SetMasterVolume(u8);
extern int func_021D3F98(u8 *);
extern void func_021EAE24(u8 *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void func_021F88BC(int);
extern void *func_021F8678(void);
extern int func_021EAE34(u8 *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern int func_021F8524(int);
extern void func_021E90A0(unsigned int *o, unsigned int key);
extern int func_021E90D0(void *s);
extern void func_021F84E8(int a, int b);
extern void func_021F8504(u32 a, u32 b, u32 c);
extern void func_021EAEA8(u8 *p, int v);
extern int func_021EE688(int, int);
extern void func_021D3F54(u8 *p);
extern void func_021EAA00(u8 *p, u8 v);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *o, u8 v);
extern u32 *func_021EE6B8(void *,u8,u8 *,u8 *);
extern void func_021D3FD0(unsigned char *p);
extern void func_021EA614(char *p, void *h);
extern int func_021EA710(u32 *p);
extern void func_021D8434(u32 *p);
extern void func_021EAE44(void *);
extern int func_021EAE54(void *);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_021D81F8(void *,void *,void *,u32,void *);
extern void func_021EA65C(char *p, void *h);
extern void func_021E9760(char *, u8 *, int, int);
extern void func_021E979C(char *p);
extern int func_021E97A4(char *p);
extern void func_021E9964(u32);
extern void func_0689CB08(u8 *);
extern int func_021E9974(u32);
extern void func_021E9954(void *);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern int func_021EA6B0(char *, u16, u16);
extern int func_021D7F38(u32 n);
extern void func_021F87EC(u32);
extern int func_021F8774(void);
extern void GFL_USE_FadeOutBgm(u32);
extern int func_021F7EB4(void);
extern u32 func_0202A298(u32,u32,u32);
extern u32 func_021D7B60(void *p, u32 b);
extern void func_021E97BC(char *p, u8 *a, int b);
extern void func_021E9808(char *p, u32 *q, int c);
extern void func_021E98AC(void *);
extern u32 func_021E98B4(void *);
extern u32 func_021D832C(struct Unk021D82FC *p);
extern void func_021D83FC(u32 *p, u32 sub);
extern u32 func_021D7EF0(u32);
extern void func_021E98BC(char *p, u8 *a, int b);
extern void func_021E9920(void *);
extern int func_021E98E8(char *p);
extern void func_021E9858(char *p);
extern u8 func_021D5448(struct QG *p);
extern void func_021E9CE0(u8 *p, u8 a, u8 b);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021E9A78(char *, const u8 *, int, int, u8 *);
extern int func_0689CB14(void *);
extern u8 func_0689CB1C(void *);
extern void func_021D8394(void *, u8, u8);
extern void func_021E9D04(void *, int, int, int, u32, u32);
extern void func_021E9E70(u8 *p);
extern int func_021E9E80(u8 *p);
extern u16 func_021EA01C(u8 *p);
extern u8 func_021EA044(struct QV *p);
extern u8 func_021EA030(u8 *p);
extern u8 func_021EA04C(u8 *p);
extern void func_021D8358(u32 *p, u32 id, u32 sub, u32 val);
extern void func_021EA058(char *p);
extern int func_021EA720(u32 *p);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *, int *);
extern void func_021D8414(u32 *p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
extern void func_021D8444(u32 *p);
extern u8 func_021D67C4(u8 *p);
extern int func_021D5750(void *, u32);
extern void *func_021EFCE4(char *arg0, int arg1);
extern int func_021EFC1C(int, int, void *, u32);
extern u8 func_021E8AFC(union Slot);
extern u8 func_021D631C(u8 *p, int i);
extern u8 WAZA_TOOL_GetType(void *p);
extern int func_021D799C(int, u16);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021D5C44(struct Rat *p);
extern u8 func_021D7F2C(u32 a, u8 b);
extern u32 func_021D3DC4(u8 *, void *, void *);
extern void func_021880BC(int, u8 *, int);
extern int func_02187FB0(u8 *);
extern u8 func_02188134(u8 *);
extern u8 func_02188140(u8 *);
extern void func_0689CA98(void *, u32, u32, u32);
extern void func_0689CAB0(void *, u32);
extern void func_0689CAE0(void *, void *);
extern void func_021D83C4(u32 *p);
extern void func_021EE608(u8 *p, const u8 *src, int n);
extern u8 func_021EE638(u8 *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_021F878C(u32 a);
extern void func_021EA600(char *p);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern void func_021EA5E4(unsigned char *p, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021EA5F0(char *p, void *h);
extern void func_02082A90(const void *, void *, u32);
extern void func_021EA824(char *p);
extern void func_021EA458(char *ctx, u16 a, u16 b);
extern int func_021EA478(u32 *p);
extern void func_021EA488(void *s, u8 a, u8 b, u8 c);
extern int func_021EA4C4(void *s);
extern void func_021EA678(char *p, u16 k, int *c);
extern void func_020061E4(unsigned int arg);
extern void func_021EA694(char *p, u16 k, int *c);
extern void func_021EA6F4(void *p, u8 b, u16 c);
extern int func_021D80A8(void *p);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(u32 *p);
extern void func_021EA354(void *ctx, int a, int b);
extern void func_021EA0F4(void *s, u32 a, u32 b, u32 c);
extern int func_021EA120(void *s);
extern void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e);
extern int func_021EA2BC(char *ctx);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);
extern void func_021F81D0(u32 a, u32 b);
extern void func_021EA40C(char *ctx, int a);
extern int func_021EA428(u32 *p);
extern void func_021EA438(u32 *p, u32 a2);
extern int func_021EA448(u32 *p);
extern void func_021EA7C8(void *ctx, int a);
extern int func_021EA7E8(void *w, int v);
extern void func_021EA7D8(void *ctx, int a);
extern int *func_021EF9C0(int *p, int a, int b);
extern void func_021EF9C8(int *p);
extern void func_021EA838(u32 *p, u32 k);
extern int func_021EA850(u32 *p, u32 k);
extern void func_021EA904(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int func_021EA950(void *w);
extern void func_021F7E94(int a);
extern void func_021F7EA4(u32 v);
extern void func_021EA8B4(char *ctx, u32 a, u32 b);
extern int func_021EA8D4(u32 *p);
extern void func_021EA1B8(void *s, u32 a, int b, int c);
extern int func_021EA1F0(void *s);
extern void func_021EA8E4(u32 *p);
extern int func_021EA8F4(u32 *p);
extern int func_021F8204(int);
extern void func_021F8134(int, u32);
extern int func_021F8180(void);
extern void func_021D6EA0(void *);
extern void func_021D6BFC(u8 *p);
extern void func_021F8150(int, void *);
extern int func_02006238(void);
extern void func_021EA3B8(char *ctx, int a, int b);
extern int func_021EA3D4(void *);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern int GFL_USE_PushBgm(void);
extern int func_02005F38(void);
extern int GFL_USE_PopBgm(void);
extern void func_021EADA4(u8 *, int, void *);
extern int func_021EADB4(u8 *);
extern void func_021EADC4(u8 *);
extern int func_021EADD4(u8 *);
extern void func_021EADE4(u8 *);
extern int func_021EADF4(u8 *);
extern int GFL_USE_IsSeqPlaying(unsigned int);
extern u16 POKE_TOOL_GetLevelUpMove(void *p, u32 *idx, u32 heap);
extern void func_021EA638(char *p, void *h, int c);
extern void func_021EAC64(u8 *p, u8 a, int c);
extern int func_021EAC80(u8 *p, u8 *out);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern void func_021F7CFC(u32, u16, u8, int, int);
extern void func_021F883C(u32);
extern void func_021F7C0C(void);
extern void func_021F7D44(int a, u16 b);
extern void func_021EAA6C(u32 a, int b, int c);
extern int func_021EAAD8(u32 a);
extern void func_021EA768(u32 *p, u32 a2, u32 a3);
extern int func_021EA778(u32 *p, u32 a2);
extern void func_021EA7A8(u32 *p, u32 a2);
extern int func_021EA7B8(u32 *p, u32 a2);
extern void func_021EA868(u32 *p, u32 a2, u32 a3);
extern int func_021EA878(u32 *p);
extern int func_0689C9D4(u16);
int func_021B8CE8(int a, int b, int c);
u8 func_021B8D38(void *p, int a, int k, u8 *out);
u8 func_021B8D8C(void *p, void *a, u32 b);
unsigned char func_021B8DC0(unsigned char *p,void *a,unsigned int b);
u8 func_021B8DE4(char *p, int i);
unsigned char func_021B8DEC(char *p,unsigned char k);
void func_021B8E28(u8 *p, u8 n, u8 *out, u8 *cnt_out);
u8 func_021B8E70(u8 *p, u32 k);
u8 func_021B8FF4(u8 *p);
int func_021B902C(int a, int b);
u8 func_021B904C(u8 *p,int k);
u32 func_021B9064(u8 *p, int k, int x);
void func_021B9090(u8 *p, u32 k, u32 x);
void func_021B90BC(u8 *p,u8 k,u32 x);
int func_021B90F8(u8 *p);
void func_021B916C(u8 *p,u32 x);
void func_021B9184(Flags_021B9184 **p);
u32 func_021B919C(u8 *p);
u32 func_021B9210(u8 *p);
u32 func_021B9244(char *p);
void func_021B92A0(u8 *p);
void func_021B9358(char *p, int i);
u8 *func_021B937C(void *a, char *b, u8 *c);
u8 *func_021B98AC(char *const *q, u8 b);
void *func_021B990C(char *p, unsigned int i, unsigned int j);
u8 *func_021B9920(void *p, u32 i, u8 j);
u8 *func_021B9934(char *p, int i);
int func_021B99B8(void *pp, unsigned int b);
u8 func_021B99C0(void **p, u32 b);
int func_021B9A24(unsigned int a, unsigned int b);
u8 func_021B9AB0(u8 x);
char *func_021B9AEC(char *p, int i);
char *func_021B9AF8(char *p, int i);
u8 func_021B9B94(void *p);
u8 func_021B9B98(u8 *p);
u8 *func_021B9C00(void *p, u32 i);
void func_021B9C10(u32 *p, int a, int b);
void func_021B9C50(u8 **p, u8 k, u8 **o1, u8 **o2);
int func_021B9CBC(u8 *p, int v);
int func_021B9F70(u8 *p, int i);
int func_021B9FBC(char *p, int i);
u16 func_021BA004(char *p, int i);
unsigned short func_021BA020(char *p, int i);
void *func_021BA02C(char *p, int i, int mode);
u32 func_021BA08C(void *p);
int func_021BA1A8(char **p, int m);
BOOL func_021BA1EC(char **p);
void func_021BA238(char *p, void *m);
void func_021BA2D4(u32 p, u32 *q);
u16 func_021BA5C4(u8 *p);
u16 func_021BA5D0(void *p);
void func_021BA73C(char *p, u16 x);
void func_021BA7F8(char *p);
u32 func_021BA820(int *p);
void func_021BB4E0(Obj_td *p, void *src, int n);
int func_021BB570(u8 *p, int sel, void *data, u32 n);
int func_021CD5E0(Buf_021CC768 *r, s32 *a);
u8 func_021CD644(u8 *p);
BtlClient *func_021CD6F0(u8 *battleMain, u8 *sideSet, int netEnabled, int netSystem, u16 clientIndex, u16 slotTotal, u8 clientKind, int isCommBattle, int isReplay, BtlClientRng *rngInit, u16 heapId);
void func_021CD8E0(BtlClient *client);
void func_021CD914(BtlClient *client);
u16 *func_021CD924(BtlClient *client, u32 *out);
void func_021CD938(BtlClient *client, void *a);
void func_021CD95C(BtlClient *client, u32 v);
void func_021CD960(BtlClient *client, u32 v);
u32 func_021CD978(BtlClient *client);
void func_021CD97C(BtlClient *client);
void func_021CD984(BtlClient *client, u16 n);
void func_021CD9B0(BtlClient *client);
u32 func_021CD9C8(BtlClient *client);
u16 func_021CD9DC(BtlClient *client);
u32 func_021CD9E0(BtlClient *client);
void func_021CD9F4(BtlClient *client, u8 n);
void func_021CDA0C(BtlClient *client, u32 v);
int func_021CDA18(BtlClient *client);
int func_021CDC0C(BtlClient *client);
void func_021CDD34(BtlClient *client);
BtlClientStepFn func_021CDD50(BtlClient *client, u32 id, int *out);
void func_021CDD94(BtlClient *client, int *o);
int func_021CDDA0(BtlClient *client);
u32 func_021CDDCC(BtlClient *client);
int func_021CDDDC(BtlClient *client, int *st);
int func_021CDE8C(BtlClient *client, int b);
void func_021CDECC(BtlClient *client);
u32 func_021CDEE8(BtlClient *client);
void *func_021CDF1C(BtlClient *client);
int func_021CDF58(BtlClient *client, int *st);
u32 func_021CDFE4(u32 mode);
int func_021CE040(void);
void func_021CE044(BtlClient *client);
void func_021CE068(BtlClient *client);
int func_021CE08C(BtlClient *client);
int func_021CE0BC(BtlClient *client, void *q);
void func_021CE0E0(BtlClient *client);
void func_021CE0F8(BtlClient *client, u8 *q, u8 *o);
void func_021CE150(BtlClient *client, void *q);
u32 func_021CE160(BtlClient *client);
u32 func_021CE170(BtlClient *client, s32 *st);
int func_021CE1B0(BtlClient *client, int *state);
void func_021CE2E8(BtlClient *client);
u32 func_021CE308(BtlClient *client);
void func_021CE3B4(BtlClient *client, void *q);
int func_021CE3C8(BtlClient *client, int *state);
int func_021CE4D0(BtlClient *client, u32 *st);
u32 func_021CE7D4(BtlClient *client, int *st);
u32 func_021CE8F0(BtlClient *client, u16 *out);
int func_021CEA94(BtlClient *client, u32 *state);
void func_021CECB4(BtlClient *client, Ent_021CECB4 *out);
u32 func_021CED4C(BtlClient *client, s32 *st);
u32 func_021CEDC0(BtlClient *client, int *st);
u32 func_021CEEB8(BtlClient *client, int *st);
u32 func_021CEFFC(BtlClient *client);
u32 func_021CF078(BtlClient *client, u32 *st);
u32 func_021CF220(BtlClient *client, int *st);
u32 func_021CF2F0(BtlClient *client, s32 *st);
void func_021CF360(BtlClient *client);
void func_021CF37C(BtlClient *client, u32 i, u32 v);
void func_021CF3B8(BtlClient *client, u32 i);
void func_021CF3F8(BtlClient *client);
void func_021CF41C(BtlClient *client);
void func_021CF430(BtlClient *client, u32 i, u32 v);
u8 func_021CF43C(BtlClient *client, u32 i);
u8 func_021CF448(BtlClient *client);
u32 func_021CF470(u8 *p, void *q, u8 *o);
u32 func_021CF524(BtlClient *client, void *q, u32 y);
void func_021CF58C(struct Unk021D82D0 *out, BtlClient *client, void *q);
int func_021CF5B0(BtlClient *client, void *m, u32 move, void *out);
u32 func_021CF81C(BtlClient *client, void *q, u8 *out);
int func_021CF89C(BtlClient *client, void *q);
u32 func_021CF8D4(BtlClient *client, void *q, u8 *a, u16 *b);
u32 func_021CF918(BtlClient *client, u8 *a, u16 *b);
u32 func_021CF9B4(BtlClient *client, void *m, u8 *a, u16 *b);
int func_021CFAC4(void *p, void *q);
int func_021CFADC(BtlClient *client, void *m);
int func_021CFB8C(void *p, void *q);
void func_021CFBA4(BtlClient *client);
int func_021CFBBC(BtlClient *client, int v);
void func_021CFBE0(BtlClient *client, u32 i, u32 v);
int func_021CFBF0(BtlClient *client, void *m, u32 slot, u8 *out);
u8 *func_021CFD50(BtlClient *client, int k);
int func_021CFDCC(void *p, void *q);
int func_021CFE08(BtlClient *client, void *a, void *b);
int func_021CFE98(BtlClient *client, void *a, void *b);
int func_021CFFAC(BtlClient *client, void *mon, void *target);
int func_021D0100(BtlClient *client, void *mon, void *target, u8 *out);
int func_021D0248(BtlClient *client, void *m, u8 *out);
int func_021D0304(BtlClient *client, void *mon, void *target, u8 *out);
int func_021D04E4(BtlClient *client, u16 a, u8 *out);
int func_021D055C(BtlClient *client, void *a, int b);
int func_021D05C4(BtlClient *client, u8 a, int b, u8 *out);
int func_021D0644(BtlClient *client, void *m, void *a, int b);
u8 func_021D06C8(BtlClient *client);
int func_021D0770(BtlClient *client, u32 *state);
u8 func_021D0980(BtlClient *client, u8 *out);
void func_021D09E0(BtlClient *client, u8 *order, u8 count, void *target);
void func_021D0B10(BtlClient *client, u32 a, u32 b, void *q, void *out);
void func_021D0B6C(BtlClient *client, u8 *s);
void func_021D0BB0(BtlClient *client);
u8 func_021D0C78(BtlClient *client, u8 *out);
int func_021D0CC4(BtlClient *client, int *state);
int func_021D0D38(BtlClient *client, int *state);
int func_021D0D44(BtlClient *client, int *state);
int func_021D0D50(BtlClient *client);
int func_021D0E74(BtlClient *client, int *state);
int func_021D0E7C(BtlClient *client, int *state, u8 param);
int func_021D102C(BtlClient *client);
int func_021D1058(BtlClient *client, void *q);
int func_021D10B8(BtlClient *client, int *state);
int func_021D123C(BtlClient *client);
int func_021D127C(BtlClient *client, int *state);
int func_021D1290(BtlClient *client, int *state, void *a2);
int func_021D13A4(BtlClient *client);
int func_021D13FC(BtlClient *client, int *state);
int func_021D1410(BtlClient *client, int *state, void *q);
int func_021D1708(BtlClient *client, int *state);
int func_021D171C(BtlClient *client, int *state, void *a2);
void func_021D185C(BtlClient *client, int a, int b);
int func_021D18EC(BtlClient *client, int *state);
int func_021D1960(BtlClient *client, int *state);
int func_021D1A18(BtlClient *client, int *state);
int func_021D1A60(BtlClient *client, int *state);
int func_021D1A74(BtlClient *client, int *state, void *a2);
int func_021D1BD0(BtlClient *client, int *state, int *pp);
int func_021D1C40(BtlClient *client, u8 x, int *out);
int func_021D1CAC(BtlClient *client, int *state, int *pp);
int func_021D1CF4(BtlClient *client, int *state, const u32 *params);
int func_021D1DF4(BtlClient *client);
int func_021D1E6C(BtlClient *client, int *state, u32 *a);
int func_021D1EB4(BtlClient *client, int *state, u32 *a);
int func_021D1F10(BtlClient *client, int *state, u32 *a);
int func_021D1F58(BtlClient *client, int *state, u32 *a);
int func_021D1FB4(BtlClient *client, int *state, u32 *a);
u32 func_021D2000(BtlClient *client, u32 k, u8 b);
int func_021D2030(BtlClient *client, int *state, const u32 *a);
int func_021D20BC(BtlClient *client, int *state, u32 *a);
int func_021D210C(BtlClient *client, int *state, u32 *a);
int func_021D215C(BtlClient *client, int *state, u32 *a);
int func_021D21D4(BtlClient *client, int *state, u32 *a);
int func_021D2234(BtlClient *client, int *state, u32 *a);
int func_021D2278(BtlClient *client, int *state, u32 *a);
int func_021D2320(BtlClient *client, int *st, u32 *c);
int func_021D2374(BtlClient *client, int *st, u32 *c);
int func_021D23B8(BtlClient *client, int *st, u32 *c);
int func_021D2424(BtlClient *client, int *st, u32 *c);
int func_021D2490(BtlClient *client, int *st, u32 *c);
int func_021D2510(BtlClient *client, int *st, u32 *c);
int func_021D2580(BtlClient *client, int *st, u32 *c);
int func_021D25C4(BtlClient *client, int *st, u32 *c);
int func_021D2628(BtlClient *client, int *st, u32 *c);
int func_021D266C(BtlClient *client, int *st, u32 *c);
int func_021D2700(BtlClient *client, int *st, u32 *c);
int func_021D2814(BtlClient *client, int *state, unsigned int *q);
int func_021D284C(BtlClient *client, int *st, u32 *c);
int func_021D28AC(BtlClient *client, int *st, u32 *c);
int func_021D2930(BtlClient *client, int *b, u32 *c);
int func_021D2990(int a, int b, int *c);
int func_021D299C(BtlClient *client, int *state);
int func_021D29CC(BtlClient *client, int b, u32 *c);
int func_021D2A20(BtlClient *client, int *state, u32 *args);
int func_021D2C7C(int n);
int func_021D2CA8(BtlClient *client, int *state, void *mon);
int func_021D2FD8(BtlClient *client, int *b, const u32 *c);
int func_021D3138(BtlClient *client, int *b, u32 *c);
int func_021D31A0(BtlClient *client, int *b, u32 *c);
int func_021D324C(BtlClient *client, int *b, u32 *c);
int func_021D32E0(BtlClient *client, int *b, u32 *c);
int func_021D344C(BtlClient *client, int *b, u32 *c);
int func_021D34B0(BtlClient *client, int *state, unsigned int *q);
int func_021D34E8(BtlClient *client, int *b, u32 *c);
extern struct Unk021EFD70 data_021EFD70[];
extern struct T6 g_021EFDC0[];
extern struct SizeEntry d_021EFE9C[0x3B];
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

BtlClient *func_021CD6F0(u8 *battleMain, u8 *sideSet, int netEnabled, int netSystem, u16 clientIndex, u16 slotTotal, u8 clientKind, int isCommBattle, int isReplay, BtlClientRng *rngInit, u16 heapId)
{
    BtlClient *client;
    u32 slot;
    int useNet, recordKey;
    client = func_02030734(heapId, 0x1b8, 1, (const char *)d_021F3A88, 0x209);
    useNet = 1;
    if (netEnabled == 0 || clientKind != 0)
        useNet = 0;
    client->clientId = clientIndex;
    client->heapId = heapId;
    client->kind = clientKind;
    client->netChannel = func_021EEA58(netSystem, (u8)clientIndex, useNet, heapId);
    client->sideData = func_021B9AF8((char *)sideSet, clientIndex);
    client->main = battleMain;
    client->side = sideSet;
    client->slotCount = slotTotal;
    client->slotIndex = 0;
    client->clientIdCopy = clientIndex;
    client->windowMode = 0;
    client->view = 0;
    client->lastMonValue = 0;
    client->workBuffer = func_02030734(heapId, 0xbc0, 1, (const char *)d_021F3A88, 0x21a);
    client->tickFn = (BtlClientTickFn)func_021CDA18;
    client->stepPhase = 0;
    client->requestParam = 0;
    client->flags.bit.requestSet = 0;
    client->requestId = 0;
    client->viewLocked = 0;
    client->pointCounter = 0;
    client->timeLimit = 0;
    client->timeElapsed = 0;
    client->limitReady = 0;
    client->flags.bit.resultPending = 0;
    client->flags.bit.commandIssued = 0;
    client->flags.bit.windowOpen = 0;
    client->flags.bit.windowDone = 0;
    *(u32 *)&client->battleField = func_021BA08C(battleMain);
    client->isComm = isCommBattle;
    func_021D8230((u8 *)&client->cursor);
    func_021D3F04(client->commandQueue);
    func_021D3D9C((u8 *)client);
    client->rng = *rngInit;
    if (client->kind == 1 && isReplay == 0) {
        recordKey = func_021B9FBC(client->main, client->clientId);
        client->recorder = func_02187F00(client->main, func_021BA820(client->main), (u32)client->side, recordKey, client->heapId);
    } else {
        client->recorder = 0;
    }
    for (slot = 0; slot < 4; slot++)
        client->chosenSlots[slot] = 0;
    if (client->kind == 0 && func_021B90F8(client->main))
        client->timeLimitTimer = func_021EE5E4(heapId);
    else
        client->timeLimitTimer = 0;
    return client;
}














void func_021CD8E0(BtlClient *client) {
 if(client->timeLimitTimer)func_021EE600(client->timeLimitTimer);
 if(client->recorder)func_02188080(client->recorder);
 func_020307B0(client->workBuffer);
 func_021EEAE0(client->netChannel);
 func_020307B0(client);
}














void func_021CD914(BtlClient *client) {*(u8 *)&client->flags|=2;}














u16 *func_021CD924(BtlClient *client, u32 *out) { if (client->timeLimitTimer) return func_021EE63C(client->timeLimitTimer,out); return 0; }














/*
 * Prototype: 021D3F48 stores only r1 low16; caller forwards full getter
 * result without truncation, so its extern argument is widened to u32.
 */
void func_021CD938(BtlClient *client, void *a) { client->kind=2; client->remoteLink=a; func_021D3F48(client->commandQueue,func_021EE830(a)); }














/*
 * Stores the second argument (a u32) into the field at #0x54.
 */
void func_021CD95C(BtlClient *client, u32 v) { *(u32 *)&client->view = v; }















void func_021CD960(BtlClient *client, u32 v) {
    client->requestParam = v;
    *(u8 *)&client->flags |= 8;
}














/*
 * Reads the u32 field at #0x50 of the argument and returns it.
 */
u32 func_021CD978(BtlClient *client) { return (u32)client->netChannel; }














/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: push {r3, lr}; ldr r1, [r0, #0x28]; blx r1; pop {r3, pc}.
 */
void func_021CD97C(BtlClient *client) { client->tickFn(client); }














/*
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 */
void func_021CD984(BtlClient *client, u16 n) { func_021EE674(client->remoteLink); func_021EEBDC(client->netChannel); func_021D3F64(client->commandQueue,n); func_021CDA0C(client,(u32)func_021CDC0C); }














void func_021CD9B0(BtlClient *client) { func_021D3F88(client->commandQueue); func_021CDA0C(client,(u32)func_021CDA18); }















/* 021CD9C8  byte field 0x1a7 == 2 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021CD9D8; ldrb r0, [r0, r1]; cmp r0, #2; bne loc_021CD9D4; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9C8(BtlClient *client)
{
    return (client->kind == 2);
}














/*
 * Reads the u16 field at #0x22 of the argument and returns it.
 */
u16 func_021CD9DC(BtlClient *client) { return *(u16 *)&client->commandQueue[10]; }















/* 021CD9E0  function-pointer slot 0x28 compared with 0x021CDC0D */
/*
 * 8 instructions, 16 bytes: ldr r1, [r0, #0x28]; ldr r0, pool_021CD9F0; cmp r1, r0; bne loc_021CD9EC; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9E0(BtlClient *client)
{
    return ((unsigned int)client->tickFn == 0x021CDC0D);
}














/*
 * u8 step preserves the low-byte result for every incoming word; no
 * signed int addition overflow. Wide step emits an extra narrowing pair.
 */
void func_021CD9F4(BtlClient *client, u8 n) { client->pointCounter+=n; if(client->pointCounter>14) client->pointCounter=14; }













void func_021CDA0C(BtlClient *client, u32 v)
{
    *(u32 *)&client->tickFn = v;
    client->stepPhase = 0;
}













int func_021CDA18(BtlClient *client)
{
    u32 id, *pair, x, y;
    int flag;
    u16 n;
    func_021D3FDC((u8 *)client,(struct Qd *)client->commandQueue);
    switch (client->stepPhase) {
    case 0:
        id = func_021EEBE8(client->netChannel);
        if (client->kind == 2 && (client->flags.bit.windowOpen || client->flags.bit.windowDone) && !id) return 0;
        func_021CDD34(client);
        if (id == 9) {
            func_021EEC20((int)client->netChannel,&pair);
            x = pair[0]; y = pair[1];
            client->cursor.y = y;
            client->cursor.x = x;
            client->stepState = 0;
            client->stepPhase = 3;
        } else if (id) {
            client->stepFn = func_021CDD50(client,id,&flag);
            if (flag) {
                if (!func_021D3FAC(client->commandQueue)) { client->stepPhase = 6; break; }
            } else func_021D3FC4(client->commandQueue);
            if (client->stepFn) {
                client->stepPhase = 1;
                client->stepState = 0;
            } else {
                client->stepState = 0;
                client->stepPhase = 2;
            }
        } else if (client->flags.bit.commandIssued) return 1;
        break;
    case 1:
        if ((client->stepFn)(client,&client->stepState)) {
            if (client->flags.bit.commandIssued) return 1;
            if (func_021D3F4C(client->commandQueue)) client->stepPhase = 4;
            else client->stepPhase = 2;
        }
        break;
    case 2:
        if (func_021EEC4C(client->netChannel,client->sendData,client->sendSize)) client->stepPhase = 0;
        if (client->flags.bit.commandIssued) return 1;
        break;
    case 3:
        if (func_021EEC4C(client->netChannel,client->sendData,client->sendSize)) client->stepPhase = 7;
        if (client->flags.bit.commandIssued) return 1;
        break;
    case 6:
        if (func_021D3F4C(client->commandQueue)) client->stepPhase = 4;
        break;
    case 4:
        if (func_021D3F60(client->commandQueue) == 1) client->stepPhase = 7;
        else {
            if (client->view) { GFL_USE_SetPlayersAudible(1,62); PM_VOICE_ResetMasterVolume(); }
            client->stepPhase = 5;
        }
        break;
    case 5:
        if (!GFL_USE_IsBgmFading()) {
            n = func_021D3FA8(client->commandQueue);
            GFL_USE_SetPlayersAudible(0,1);
            func_021BA73C(client->main,n);
            PM_VOICE_SetMasterVolume(0);
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}













/*
 * extent: The store-and-return follower at 0x021CDD34 is included here;
 * the larger lookup follower at 0x021CDD50 has its own verified shard.
 */
int func_021CDC0C(BtlClient *client)
{
    u32 id;
    u16 n;
    int zero;
    func_021D3FDC((u8 *)client,(struct Qd *)client->commandQueue);
    switch (client->stepPhase) {
    case 0:
        client->stepPhase = 1;
    case 1:
        if (!func_021D3F98(client->commandQueue)) {
            id = func_021EEBE8(client->netChannel);
            if (id) {
                zero = 0;
                client->stepFn = func_021CDD50(client,id,0);
                if (client->stepFn) {
                    client->stepPhase = 2;
                    client->stepState = zero;
                }
                else {
                    func_021CDD34(client);
                    client->stepPhase = 3;
                    client->stepState = zero;
                }
            }
        } else {
            if (client->view) {
                GFL_USE_SetPlayersAudible(1,1);
                func_021EAE24(client->view);
                GFL_USE_FadeInBgmFull(30);
                func_021F88BC(0);
                PM_VOICE_ResetMasterVolume();
            }
            client->stepPhase = 4;
        }
        break;
    case 2:
        if ((client->stepFn)(client,&client->stepState)) {
            client->stepPhase = 3;
            client->stepState = 0;
            if (func_021F8678()) func_021F88BC(1);
        }
        break;
    case 3:
        if (func_021EEC4C(client->netChannel,client->sendData,client->sendSize)) client->stepPhase = 1;
        break;
    case 4:
        if (client->view) {
            if (func_021EAE34(client->view)) {
                if (!GFL_USE_IsBgmFading()) {
                    n = (int)func_021D3FA8(client->commandQueue);
                    func_021EAE74(client->view,n,n);
                    func_021BA7F8(client->main);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}













void func_021CDD34(BtlClient *client)
{
    client->sendFlag = 0;
    client->sendData = (u8 *)&client->sendFlag;
    client->sendSize = 4;
}













BtlClientStepFn func_021CDD50(BtlClient *client, u32 id, int *out)
{
    u32 i;
    for (i=0; i<15; i++) {
        if (d_021EFFEC[i].id == id) {
            if (out) *out = d_021EFFEC[i].flag;
            return d_021EFFEC[i].callbacks[client->kind];
        }
    }
    return 0;
}














void func_021CDD94(BtlClient *client, int *o)
{
    *(BtlClientPoint *)o = client->cursor;
}













/*
 * unresolved THM_CALL at +0x14. Region hint ov094 does not supply a witness.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 belongs to another owner). Integrator: seed label.
 */
int func_021CDDA0(BtlClient *client) { if(client->kind!=2) { if(client->timeElapsed) return func_021F8524(0); return 0; } return client->flags.bit.windowOpen; }













u32 func_021CDDCC(BtlClient *client) { return client->flags.bit.windowDone; }













/*
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * func_021F84E8 takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; func_021D3FA8 is declared u32 here because
 * the original narrows its result before the u16 parameter of func_021EAEA8.
 */
int func_021CDDDC(BtlClient *client, int *st)
{
    switch (*st) {
    case 0:
        if ((int)func_021B86B8(client->main) != 4) {
            func_021E90A0(client->view, 0);
        } else {
            func_021E90A0(client->view, 1);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_021E90D0(client->view) == 0) {
            break;
        }
        client->timeLimit = func_021BA5C4(client->main);
        client->timeElapsed = func_021BA5D0(client->main);
        if (client->timeLimit != 0 || client->timeElapsed != 0) {
            func_021F84E8(client->timeElapsed, client->timeLimit);
            if (client->timeElapsed != 0) {
                func_021F8504(0, 1, 1);
            }
        }
        func_021CDECC(client);
        if (func_021CD9E0(client) != 0) {
            func_021EAEA8(client->view, (u16)((u32)func_021D3FA8(client->commandQueue)));
        }
        return 1;
    }
    return 0;
}













int func_021CDE8C(BtlClient *client, int b)
{
    int r4;
    if (client->view != 0) {
        r4 = func_021CDDDC(client, (int *)b);
        if (r4 != 0) {
            if (func_021EE688((int)client->remoteLink, client->clientId) != 0)
                func_021D3F54(client->commandQueue);
        }
        return r4;
    }
    func_021EE688((int)client->remoteLink, client->clientId);
    return 1;
}












void func_021CDECC(BtlClient *client) { void *a; a=func_021CDF1C(client); if(a) client->lastMonValue=func_021D59B4(a,13); }












u32 func_021CDEE8(BtlClient *client) { void *a; u32 now,old; a=func_021CDF1C(client); if(a) { now=func_021D59B4(a,13); old=client->lastMonValue; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }











/*
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 */
void *func_021CDF1C(BtlClient *client) { u8 side; if(func_021B8588(client->main)==0 && func_021B86C0(client->main)==0) { side=func_021B9064(client->main,client->clientId,0); return func_021B9920(client->side,side,0); } return 0; }












int func_021CDF58(BtlClient *client, int *st)
{
    u8 buf;

    switch (*st) {
    case 0:
        func_021EAA00(client->view, client->windowMode);
        func_021CE068(client);
        *st = *st + 1;
        break;
    case 1:
        if (func_021CE08C(client) != 0) {
            func_021EAA5C(client->view);
            *st = 2;
        } else if (func_021EAA34(client->view, &buf) != 0) {
            client->windowMode = buf;
            *st = 3;
        }
        break;
    case 2:
        client->windowMode = func_021CDFE4(client->windowMode);
        *st = *st + 1;
        break;
    case 3:
        func_021CE0E0(client);
        *st = *st + 1;
        break;
    case 4:
        client->sendData = &client->windowMode;
        client->sendSize = 1;
        return 1;
    }
    return 0;
}










/*
 * Lever: each switch arm writes its own `mode = (u8)t;` before `break`. The copies are
 * cross-jumped into `b join` after branch threading, so each arm's `blo` keeps landing on
 * its own hop (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md).
 * One shared `mode = (u8)t;` after the switch threads the hops away (4 bytes short).
 */
u32 func_021CDFE4(u32 mode)
{
    u32 v;
    int t;

    v = (u32)(((u64)func_0203F0A8() * 100) >> 32);
    if (mode == 0) {
        if (v < 0x1e) {
            mode = 3;
        } else if (v < 0x3c) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        switch (mode) {
        case 1:
        default:
            t = (v < 0x32) ? 2 : 3;
            mode = (u8)t;
            break;
        case 3:
            t = (v < 0x28) ? 2 : 1;
            mode = (u8)t;
            break;
        case 2:
            t = (v < 0x28) ? 3 : 1;
            mode = (u8)t;
            break;
        }
    }
    return mode;
}









int func_021CE040(void)
{
    return 1;
}









void func_021CE044(BtlClient *client) { client->windowMode=func_021CDFE4(client->windowMode); client->sendData=&client->windowMode; client->sendSize=1; }










void func_021CE068(BtlClient *client) { if(client->timeLimit) { func_021F8504(1,1,1); client->limitReady=0; } }










/*
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
int func_021CE08C(BtlClient *client) { if(client->timeLimit!=0) { if(client->limitReady==0) { if(func_021F8524(1)) client->limitReady=1; } return client->limitReady; } return 0; }










int func_021CE0BC(BtlClient *client, void *q) { if(func_021CE08C(client)) { if(q) func_021CE150(client,q); return 1; } return 0; }










void func_021CE0E0(BtlClient *client) { if(client->timeLimit!=0) func_021F8504(1,0,0); }











void func_021CE0F8(BtlClient *client, u8 *q, u8 *o)
{
    if (func_021B8588(client->main) != 3) {
        func_021EAF18((struct L *)o, 1, 0x45);
        func_021EAF50((struct L *)o, func_021D5440(q));
        func_021EAF78(o, 0);
    } else {
        func_021EAF18((struct L *)o, 1, 0x46);
        func_021EAF50((struct L *)o, client->clientId);
        func_021EAF78(o, 0);
    }
}










void func_021CE150(BtlClient *client, void *q) { client->subFn=q; client->subState=0; }











/* 021CE160  the receiver pointer is also the FIRST argument: the image keeps
 * r0 = p, puts p+0xd4 in r1 and the slot from [p+0xd0] in r2. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: push {r3, lr}; adds r2, r0, #0; adds r2, #0xd0; adds r1, r0, #0; ldr r2, [r2]; adds r1, #0xd4; blx r2; pop {r3, pc}.
 */
u32 func_021CE160(BtlClient *client)
{
    return client->subFn(client, &client->subState);
}










u32 func_021CE170(BtlClient *client, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CE150(client, (void *)((u32)func_021CE308));
        func_021CE068(client);
        *st = *st + 1;
        break;
    case 1:
        func_021CE08C(client);
        if (func_021CE160(client) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021CE1B0(BtlClient *client, int *state)
{
    u8 count;
    u8 flag;
    u32 *data;
    switch (*state) {
    case 0:
        if (client->flags.bit.windowDone) {
            func_021CE2E8(client);
            return 1;
        }
        data = func_021EE6B8(client->remoteLink,client->clientId,&count,&flag);
        if (flag) func_021D3F54(client->commandQueue);
        *(u32 * *)&client->sendData = data;
        client->sendSize = count * 4;
        if (((Command *)data)->kind == 8) {
            func_021D3FD0(client->commandQueue);
            if (client->view) {
                func_021EAF18((struct L *)&client->messageA,1,0xb7);
                func_021EA614(client->view,&client->messageA);
                (*state)++;
            } else {
                func_021CE2E8(client);
                *(u8 *)&client->flags |= 0x10;
                return 1;
            }
        } else if (((Command *)data)->kind == 9) {
            *(u8 *)&client->flags |= 0x20;
            func_021D3FD0(client->commandQueue);
            if (client->view) {
                func_021EAF18((struct L *)&client->messageA,1,0xb8);
                func_021EA614(client->view,&client->messageA);
                *state += 2;
            } else {
                func_021CE2E8(client);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            func_021CE2E8(client);
            *(u8 *)&client->flags |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (func_021EA710(client->view)) {
            func_021CE2E8(client);
            return 1;
        }
        break;
    }
    return 0;
}









void func_021CE2E8(BtlClient *client) { client->actionCursor=(u8 *)client->actions; func_021D8434(client->actions); client->sendData=client->actionCursor; client->sendSize=4; }










u32 func_021CE308(BtlClient *client)
{
    u32 i = 0;
    u32 w;
    client->slotIndex = 0;
    ((s8 *)client)[0x11e] = -1;
    client->slotsDone = 0;
    client->flags.bit.moveSelected = 0;
    func_021D0B10(client, 0, client->slotCount, client->slotChoices, client->choiceFlags);
    func_021CF41C(client);
    func_021CF360(client);
    for (i = 0; i < 3; i++) {
        func_021D8434((u32 *)((u8 *)client->actions + i * 4));
    }
    for (i = 0; i < client->slotCount; i++) {
        w = (u32)func_021B990C((char *)(client->side), client->clientId, (u8)i);
        if (func_021CF470((u8 *)client, (void *)w, 0) == 0) {
            client->slotsDone = i;
            break;
        }
    }
    func_021CE150(client, (void *)((u32)func_021CE4D0));
    return 0;
}









void func_021CE3B4(BtlClient *client, void *q) { func_021EA614(client->view,q); client->redrawRequest=1; }









int func_021CE3C8(BtlClient *client, int *state)
{
    u8 out[4];
    u32 i;
    u32 id;
    switch (*state) {
    case 0:
        func_021EAE44(client->view);
        (*state)++;
        break;
    case 1:
        if (func_021EAE54(client->view)) {
            for (; client->slotIndex < client->slotCount; client->slotIndex++) {
                client->activeMon = func_021B990C(client->side,client->clientId,client->slotIndex);
                client->actionCursor = (u8 *)client->actions+client->slotIndex*4;
                func_021D8434((u32 *)(client->actionCursor));
                if (!func_021CF470((u8 *)client,client->activeMon,client->actionCursor)) {
                    i = func_021CF81C(client,client->activeMon,out);
                    if (i < 4) {
                        id = func_021D54C0(client->activeMon,i);
                        func_021D82D0((struct Unk021D82D0 *)(client->actionCursor),id,func_021D81F8(client->main,client->side,client->activeMon,id,client->actionResult));
                    } else func_021CF58C((struct Unk021D82D0 *)(client->actionCursor),client,client->activeMon);
                }
            }
            (*state)++;
        }
        break;
    case 2:
        client->sendData = (u8 *)client->actions;
        client->sendSize = client->slotCount*4;
        func_021CE150(client,(void *)((u32)func_021CF2F0));
        break;
    }
    return 0;
}







/*
 * note 2026-10-05 (wave P26 lane 2): byte-identical to the original except that two call
 * relocations have no witness in the current index: func_021E979C and func_021E9954. Both
 * leaves are now filed (src/matched/ov/ov093_func_021E979C.c, ov093_func_021E9954.c, EXACT);
 * the verdict becomes EXACT once the integrator regenerates the index. The original extent is
 * 772 B: 756 B of C plus the 16 B linker veneer at 021CE7C4 (not C, resolved as a veneer witness).
 * Two changes closed the 253 B residue of the older draft: (1) no shared increment label and
 * no goto: each arm writes ++*st; break; so the compiler builds the single shared state store
 * and one epilogue (756 to 748 B, branch layout); (2) the countdown loop reads the index byte
 * through a struct field (struct L at 0x11D and 0x1A6) instead of a count pointer local, so
 * mwcc hoists three separate address computations (count pointer in r5, a copy in r6, a
 * stack copy for the loop test) as in the original.
 * Not tried again from the older note: unsigned-long state pointer, full-word countdown.
 * proof: full unsigned state dispatch <=8; byte selectors0..255; countdown assigned before reads; byte/state additions wrap at their original widths; fixed veneer is omitted from C.
 */
int func_021CE4D0(BtlClient *client, u32 *st)
{
    u32 result;
    switch (*st) {
    case 0:
        (client->activeMon) = func_021B990C((client->side), client->clientId, client->slotIndex);
        (client->actionCursor) = (u8 *)client->actions + client->slotIndex * 4;
        client->extraActionCount = 0;
        func_021D8434(((void *)client->actionCursor));
        if (func_021CF470((u8 *)client, (client->activeMon), (client->actionCursor))) {
            func_021CE150(client, (void *)((u32)func_021CF220));
            break;
        }
        if (func_021CE8F0(client, &client->receivedCode) == 1) {
            func_021CE150(client, (void *)((u32)func_021CE7D4));
            break;
        }
        ++*st; break;
    case 1:
        if (client->prevSlotIndex != client->slotIndex || client->redrawRequest) {
            func_021CE0F8(client, (client->activeMon), (u8 *)&client->messageA);
            func_021EA65C((client->view), &client->messageA);
            client->redrawRequest = 0;
            client->prevSlotIndex = client->slotIndex;
            ++*st; break;
        }
        *st += 2U;
        break;
    case 2:
        if (!func_021EA710((client->view))) return 0;
        ++*st;
        /* falls through */
    case 3:
        func_021E9760((client->view), (client->activeMon), client->slotIndex > client->slotsDone, (int)(client->actionCursor));
        ++*st; break;
    case 4:
        if (func_021CE0BC(client, (void *)((u32)func_021CE3C8))) {
            func_021E979C((client->view));
            return 0;
        }
        result = func_021E97A4((client->view));
        switch (result) {
        case 3:
            if (func_021D62C4((client->activeMon), 0x21)) {
                func_021E9964(((u32)client->view));
                *st = 6;
            } else {
                func_021CF430(client, client->slotIndex, 0);
                func_021CE150(client, (void *)((u32)func_021CEDC0));
            }
            break;
        case 1:
            func_021CF430(client, client->slotIndex, 0);
            func_021CE150(client, (void *)((u32)func_021CEA94));
            break;
        case 2:
            if (func_021D62C4((client->activeMon), 0x21)) *st = 6;
            else if (client->isComm == 1 && !func_021BA1EC((client->main))) {
                func_021E9964(((u32)client->view));
                *st = 5;
            } else func_021CE150(client, (void *)((u32)func_021CEEB8));
            break;
        case 4:
            if (client->slotIndex == client->slotsDone) {
                if (func_021D62C4((client->activeMon), 0x21) && func_021B86E4((client->main)) != 2) *st = 6;
                else {
                    func_021CF430(client, client->slotIndex, 0);
                    func_021CE150(client, (void *)((u32)func_021CF078));
                }
                break;
            }
            if (client->slotIndex == 0) break;
            do {
                --((struct L *)client)->idx;
                if (!func_021CF470((u8 *)client, func_021B990C((client->side), ((struct L *)client)->sel, ((struct L *)client)->idx), 0)) {
                    client->pointCounter += func_021CF43C(client, client->slotIndex);
                    if (func_021D8454((Action *)((u8 *)client->actions + client->slotIndex * 4)) == 3)
                        func_0689CB08(client->choiceFlags);
                    if (func_021D8454((Action *)((u8 *)client->actions + client->slotIndex * 4)) == 2)
                        func_021CF3B8(client, client->slotIndex);
                    func_021CE150(client, (void *)((u32)func_021CE4D0));
                    return 0;
                }
            } while (((struct L *)client)->idx != 0);
            break;
        }
        break;
    case 5:
        if (func_021E9974(((u32)client->view))) *st = 3;
        break;
    case 6:
        func_021E9954((client->view));
        ++*st; break;
    case 7:
        if (!func_021E9974(((u32)client->view))) break;
        func_021EAF18((struct L *)&client->messageA, 1, 0xC5);
        func_021EAF50((struct L *)&client->messageA, func_021D5440((client->activeMon)));
        func_021CE3B4(client, (u8 *)&client->messageA);
        ++*st; break;
    case 8:
        if (func_021EA710((client->view))) *st = 1;
        break;
    }
    return 0;
}










u32 func_021CE7D4(BtlClient *client, int *st)
{
    u32 i;
    u16 k;
    u32 z;
    switch (*st) {
    case 0:
        z = 0;
        i = func_021B904C(client->main, 0);
        k = func_021BA004(client->main, i);
        func_021F7F58(func_021BA020(client->main, i), 9, 0, 0, z);
        func_021F7998(0x270);
        func_021EA6B0(client->view, k, client->receivedCode);
        if ((u16)(client->receivedCode + 0xffed) <= 1 &&
            func_021D7F38(func_021BA020(client->main, i)) && !client->flags.bit.resultPending) {
            func_021F87EC(0x47b);
            if (!func_021F8774()) {
                GFL_USE_FadeOutBgm(8);
                *st = 1;
                break;
            }
        }
        *st = 2;
        break;
    case 1:
        if (!GFL_USE_IsBgmFading()) {
            GFL_USE_CancelChangeAndPlayBgm(0x47b, 0xffff);
            *(u8 *)&client->flags = (*(u8 *)&client->flags & ~1) | 1;
            ++*st;
        }
        break;
    case 2:
        if (!func_021F7EB4() && func_021EA710(client->view)) {
            func_021F7998(0x271);
            ++*st;
        }
        break;
    case 3:
        if (!func_021F7EB4()) func_021CE150(client, (void *)((u32)func_021CE4D0));
        break;
    }
    return 0;
}









static inline void initOffset(Off *value)
{
    *value = OFFSET;
    *value -= 0x88;
}









/*
 * lever: Six ordinary int offsets each receive 0x19a then 0x112;
 * a cached row pointer preserves their distinct stack homes and r5 base.
 * Reverse declarations and a full-word k local restore the spill order.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`invalid=0x19a;` before `invalid=0x112;`; `ok3=0x19a;` before
 * `ok3=0x112;` and 4 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
u32 func_021CE8F0(BtlClient *client, u16 *out)
{
    u32 entry;
    int result;
    u32 count;
    u32 k;
    u32 key;
    u32 id, i;
    int a, b;
    u8 *mon;
    u8 *row;
    int skip,ok0,ok1,ok2,ok3,invalid;
    if ((u32)func_021B86B8(client->main) != 1) goto fail;
    id = func_021B904C(client->main,0);
    k = func_021BA004(client->main,id);
    if (!k) goto fail;
    entry = (u32)func_021B9AEC(client->side,id);
    mon = func_021B990C(client->side,id,(u8)0);
    if (func_021D5B68(mon)) {
        count = func_021B99B8(client->main,id);
        for (i=1;i<count;i++) {
            mon = func_021B990C(client->side,id,(u8)i);
            if (!func_021D5B68(mon)) break;
        }
    }
    result = -1;
    invalid=0x112;
    ok3=0x112;
    ok2=0x112;
    ok1=0x112;
    ok0=0x112;
    skip=0x112;
    for (i=0;i<4;i++) {
        row = (u8 *)client + i;
        if (!row[skip]) {
            key = d_021EFF78[i];
            if (func_0202A298(k,key,client->heapId)) {
                switch (key - 0x11) {
                case 1:
                    a = func_021D59B4(mon,13);
                    if ((u32)a <= func_021D7B60(mon,2)) { result = i; row[ok0] = 1; }
                    break;
                case 0:
                    if (!func_021D5B48(mon)) { result = i; row[ok1] = 1; }
                    break;
                case 2:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((u8 *)entry) == 1) { result = i; row[ok2] = 1; }
                    break;
                case 3:
                    if (func_021B9B94((void *)entry) > 1 && func_021B9B98((u8 *)entry) == 1) {
                        b = func_021D59B4(mon,13);
                        if ((u32)b <= func_021D7B60(mon,2)) { result = i; row[ok3] = 1; }
                    }
                    break;
                }
            } else row[invalid] = 1;
        }
    }
    if (result >= 0) { *out = d_021EFF78[result]; return 1; }
fail:
    return 0;
}









/*
 * witnesses: four ov093 blocker leaves 021E98AC, 021E98B4,
 * 021D7EF0, 021E9920 filed and individually shard-verified first.
 * lever: packed unsigned bitfields plus narrow caller extern CF5B0 move;
 * record declared before sub settles r6/r7 allocation (one variant).
 * interface: CF5B0 own source takes u32 move, but original narrows id at
 * 021CEBC6/021CEBCC; u16 extern preserves observed caller truncation.
 * CE3B4 ignores r1 but caller explicitly supplies p+0x58, retained here.
 * semantics: word bitfields use unsigned shifts; all dynamic address adds
 * and scaling are u32 modulo 2^32, without assuming selector/index bounds.
 * Byte increment is promoted in 0..255 then narrowed; all locals initialized
 * on each path to a use. The branch to state 4 has no uninitialized outputs.
 */
int func_021CEA94(BtlClient *client, u32 *state)
{
    void *m;
    u32 slot, k;
    u32 *record;
    u8 sub;
    switch (*state) {
    case 0:
        if (func_021B8588(client->main) != 3) {
            if (func_021CF524(client, client->activeMon, (u32)client->actionCursor))
                func_021CE150(client, (void *)((u32)func_021CF220));
            else *state = 1;
        } else {
            func_021CECB4(client, (Ent_021CECB4 *)client->recvEntry);
            *state = 2;
        }
        break;
    case 1:
        func_021E97BC(client->view, (u8 *)(client->activeMon), (u32)client->actionCursor);
        *state = 3;
        break;
    case 2:
        func_021E9808(client->view, (u32 *)client->recvEntry, (int)client->actionCursor);
        *state = 3;
        break;
    case 3:
        if (func_021CE0BC(client, (void *)((u32)func_021CE3C8))) {
            func_021E98AC(client->view);
            return 0;
        }
        if (func_021E98B4(client->view)) {
            k = func_021D8454((Action *)client->actionCursor);
            if (k == 0) func_021CE150(client, (void *)((u32)func_021CE4D0));
            else if (k == 5) func_021CE150(client, (void *)((u32)func_021CF220));
            else {
                m = client->activeMon;
                record = (u32 *)client->actionCursor;
                sub = 0;
                slot = client->slotIndex;
                if (func_021B8588(client->main) == 3) {
                    sub = (u8)((Record_td *)&client->recordKey)->sub;
                    slot = func_021B9AB0(sub);
                    m = *(void **)((u32)client + slot * 8U + 0xa4U);
                }
                if (func_021D832C((struct Unk021D82FC *)record)) {
                    client->highlightSlot = slot;
                    client->highlightKind = func_021D5778(m, (u16)((Record_td *)record)->id);
                    if (client->highlightKind != 4) {
                        func_021CE150(client, (void *)((u32)func_021CED4C));
                        return 0;
                    }
                }
                if (func_021CF5B0(client, m, (u16)((Record_td *)record)->id, (u8 *)&client->messageA)) {
                    func_021EAF78((u8 *)&client->messageA, 0xff);
                    func_021CE3B4(client, (u8 *)&client->messageA);
                    *state = 7;
                } else {
                    if (func_021B8588(client->main) == 3 && sub != 0 && sub != 1 && !func_021D5B68(m)) {
                        k = func_021D8340((Action *)&client->actionKey);
                        record = (u32 *)client->actionCursor;
                        *(u32 *)&client->actionCursor = (u32)record + 4U;
                        func_021D83FC(record, sub);
                        func_021D82D0((void *)client->actionCursor, k, 6);
                        ++client->extraActionCount;
                    }
                    *state = 4;
                }
            }
        }
        break;
    case 4:
        if (func_021D7EF0(func_021B8588(client->main))) *state = 5;
        else func_021CE150(client, (void *)((u32)func_021CF220));
        break;
    case 5:
        func_021E98BC(client->view, (u8 *)(client->activeMon), (u32)client->actionCursor);
        *state = 6;
        break;
    case 6:
        if (func_021CE0BC(client, (void *)((u32)func_021CE3C8))) {
            func_021E9920(client->view);
            return 0;
        }
        k = func_021E98E8(client->view);
        if (k == 1) func_021CE150(client, (void *)((u32)func_021CF220));
        else if (k == 2) *state = 1;
        break;
    case 7:
        if (func_021EA710(client->view)) {
            func_021E9858(client->view);
            *state = 3;
        }
        break;
    }
    return 0;
}








void func_021CECB4(BtlClient *client, Ent_021CECB4 *out)
{
    u32 i;
    u32 j;
    u8 *q;
    u32 n;
    u32 k;
    Ent_021CECB4 *e;
    for (i = 0; i < 3; i++) {
        q = func_021B9C00(client->sideData, (u8)i);
        e = out + i;
        e->q = q;
        for (j = 0; j < 4; j++) {
            e->f[j] = 0;
        }
        if (func_021D5B68(q) == 0) {
            n = func_021D5448((struct QG *)q);
            for (k = 0; k < n; k++) {
                if (func_021D5584((struct UtilWork *)q, (u8)k) == 0 || func_021CF5B0(client, q, (u32)func_021D54C0(q, (u8)k), 0) != 0) {
                    e->f[k] = 0;
                } else {
                    e->f[k] = 1;
                }
            }
        }
    }
}








u32 func_021CED4C(BtlClient *client, s32 *st)
{
    u32 r;
    switch (*st) {
    case 0:
        func_021E9CE0((u8 *)(client->view), client->highlightSlot, client->highlightKind);
        *st = *st + 1;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(client, 0) != 0) {
            func_021E9B14((unsigned int *)(client->view));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(client->view)) != 0) {
            func_021CE150(client, (void *)((u32)func_021CEA94));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(client->view)) != 0) {
            func_021CE150(client, (void *)((u32)func_021CE3C8));
        }
        break;
    }
    return 0;
}








u32 func_021CEDC0(BtlClient *client, int *st)
{
    u8 a;
    u16 b;
    u32 r;
    u8 n;
    switch (*st) {
    case 0:
        r = 0;
        if ((u8)func_021CF8D4(client, client->activeMon, &a, &b) != 4 ||
            a == func_021D5440(client->activeMon)) r = 1;
        func_021E9A78(client->view, client->slotChoices, client->slotIndex, r, client->choiceFlags);
        ++*st;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(client, 0)) {
            func_021E9B14((unsigned int *)(client->view));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(client->view))) {
            if (func_0689CB14(client->choiceFlags) == 0) {
                n = func_0689CB1C(client->choiceFlags);
                if (n < 6) {
                    func_021D8394(client->actionCursor, client->slotIndex, n);
                    func_021CE150(client, (void *)((u32)func_021CF220));
                    break;
                }
            }
            func_021CE150(client, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(client->view))) func_021CE150(client, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}












static inline u8 isSameSlotIndex(BtlClient *client)
{
    return client->slotIndex == client->slotsDone ? 1 : 0;
}












/*
 * lever: u16 b/d retain the spilled reload and narrow only at the u8 call;
 *        enum same retains the early ternary truncation.
 */
u32 func_021CEEB8(BtlClient *client, int *st)
{
    u32 a, c, z;
    u16 b, d;
    Value same;
    u32 flag;
    switch (*st) {
    case 0:
        a = func_021CF448(client);
        same = isSameSlotIndex(client);
        flag = (u8)func_021CEFFC(client);
        func_021E9D04(client->view, client->isComm, client->pointCounter, a, same, flag);
        ++*st;
        break;
    case 1:
        z = 0;
        if (func_021CE0BC(client, 0)) {
            func_021E9E70(client->view);
            *st = 2;
            return z;
        }
        if (func_021E9E80(client->view)) {
            a = func_021EA01C(client->view);
            b = func_021EA044(client->view);
            if (a && b != 6) {
                c = func_021EA030(client->view);
                d = func_021EA04C(client->view);
                if (client->pointCounter >= c) client->pointCounter = client->pointCounter - c;
                else {
                    client->pointCounter = z;
                    c = client->pointCounter;
                }
                func_021CF430(client, client->slotIndex, c);
                func_021D8358((void *)client->actionCursor, a, (u8)b, (u8)d);
                func_021EA058(client->view);
                if (func_021D805C((void *)a, 0xf) == 4) *(u8 *)&client->flags |= 4;
                func_021CF37C(client, client->slotIndex, a);
                func_021CE150(client, (void *)((u32)func_021CF220));
            } else func_021CE150(client, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9E80(client->view)) func_021CE150(client, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}












u32 func_021CEFFC(BtlClient *client)
{
    char *arr;
    u32 lim;
    u32 flag;
    u32 i;
    u32 c;
    u8 *w;
    u32 cnt;
    if (func_021B86B8(client->main) == 0) {
        arr = func_021B9AF8(client->side, 1);
        cnt = func_021B9B94(arr);
        lim = func_021B8670((unsigned int **)(client->main));
        if (lim > cnt) {
            lim = cnt;
        }
        flag = 0;
        c = 0;
        for (i = 0; i < lim; i++) {
            w = func_021B9C00(arr, (u8)i);
            if (func_021D5B68(w) == 0) {
                c++;
                if (func_021D5C30((struct UtilWork *)w) != 0) {
                    flag = 1;
                }
            }
        }
        if (c == 1 && flag != 0) {
            return 1;
        }
    }
    return 0;
}











u32 func_021CF078(BtlClient *client, u32 *st)
{
    u8 id;
    u16 k;
    int result;
    switch (*st) {
    case 0:
        switch (func_021B86E4(client->main)) {
        default:
        case 0:
            if (func_021CF918(client, &id, &k) == 4) {
                *st = 5;
                break;
            }
            if (k) {
                func_021EAF18((struct L *)&client->messageA, 2, 0x365);
                func_021EAF50((struct L *)&client->messageA, id);
                func_021EAF50((struct L *)&client->messageA, k);
            } else {
                func_021EAF18((struct L *)&client->messageA, 1, 0x4a);
            }
            func_021CE3B4(client, (u8 *)&client->messageA);
            *st = 1;
            break;
        case 1:
            func_021EAF18((struct L *)&client->messageA, 1, 0x4c);
            func_021CE3B4(client, (u8 *)&client->messageA);
            *st = 1;
            break;
        case 2:
            func_021EAF18((struct L *)&client->messageA, 1, 0x4d);
            func_021EAF78((u8 *)&client->messageA, 0xff);
            func_021CE3B4(client, (u8 *)&client->messageA);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (func_021EA710(client->view)) {
            func_021CE0F8(client, client->activeMon, (u8 *)&client->messageA);
            func_021EA65C(client->view, &client->messageA);
            *st = 2;
        }
        break;
    case 2:
        if (func_021EA710(client->view))
            func_021CE150(client, (void *)((u32)func_021CE4D0));
        break;
    case 3:
        func_021EA710(client->view);
        if (func_021EA720(client->view)) {
            func_021EAF18((struct L *)&client->messageA, 3, 8);
            func_021EAF18((struct L *)&client->messageB, 3, 9);
            func_021EABC4(client->view, (u32)&client->messageA, (u32)&client->messageB, 1);
            *st = 4;
        }
        break;
    case 4:
        if (func_021EA710(client->view)) {
            if (func_021EAC54(client->view, &result)) {
                if (result == 0)
                    *st = 5;
                else
                    func_021CE150(client, (void *)((u32)func_021CE4D0));
            } else if (func_021CE08C(client)) {
                func_021CE150(client, (void *)((u32)func_021CE3C8));
            }
        }
        break;
    case 5:
        func_021D8414((void *)client->actionCursor);
        *(u8 *)&client->flags |= 4;
        func_021CE150(client, (void *)((u32)func_021CF220));
        break;
    }
    return 0;
}











u32 func_021CF220(BtlClient *client, int *st)
{
    u8 n;
    void *q;
    switch (*st) {
    case 0:
        func_021E9964((unsigned int)client->view);
        ++*st;
        break;
    case 1:
        if (func_021E9974((unsigned int)client->view)) {
            ++client->slotIndex;
            if (client->slotIndex < client->slotCount) {
                if ((((u32)*(u8 *)&client->flags << 29) >> 31) == 0) {
                    func_021CE150(client, (void *)((u32)func_021CE4D0));
                    break;
                }
                while (client->slotIndex < client->slotCount) {
                    q = func_021B990C((char *)(client->side), client->clientId, client->slotIndex);
                    if (!func_021CF470((u8 *)client, q, (u8 *)client->actions + client->slotIndex * 4))
                        func_021D8434((u32 *)((u8 *)client->actions + client->slotIndex * 4));
                    ++client->slotIndex;
                }
            }
            if (client->slotIndex >= client->slotCount) {
                n = client->slotCount + client->extraActionCount;
                client->extraActionCount = 0;
                client->sendData = (u8 *)client->actions;
                client->sendSize = n * 4;
                func_021CE150(client, (void *)((u32)func_021CF2F0));
            }
        }
        break;
    }
    return 0;
}












u32 func_021CF2F0(BtlClient *client, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CF3F8(client);
        if (func_021B86C0(client->main) != 0) {
            client->viewLocked = 1;
            func_021EA7FC((char *)(client->view));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (func_021EA814(client->view) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021CE0E0(client);
            *st = *st + 1;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}











void func_021CF360(BtlClient *client) { u32 i; for(i=0;i<3;i++) client->slotLinkWords[i]=0; }











void func_021CF37C(BtlClient *client, u32 i, u32 v) { if(client->isComm==0) { if(client->clientId==func_021B8FF4(client->main)) { client->slotLinkWords[i]=v; func_021B9090(client->main,client->clientId,v); } } }











/*
 * lever: func_021B90BC consumes the live r2 halfword as its third argument;
 * its matched body forwards it to func_02007E50.
 */
void func_021CF3B8(BtlClient *client, u32 i)
{
    if (client->isComm == 0) {
        if (client->clientId == func_021B8FF4(client->main)) {
            u16 *a = client->slotLinkWords;
            u32 v = a[i];
            if (v != 0) {
                a[i] = 0;
                func_021B90BC(client->main, client->clientId, v);
            }
        }
    }
}











void func_021CF3F8(BtlClient *client) { u32 i; if(client->isComm==0) for(i=0;i<3;i++) func_021CF3B8(client,(u8)i); }











void func_021CF41C(BtlClient *client) { func_02082BCC(client->slotFlags,0,3); }










/*
 * follower: unlabelled byte accessor at 0x021CF43C.
 */
void func_021CF430(BtlClient *client, u32 i, u32 v)
{
    client->slotFlags[i] = v;
}










u8 func_021CF43C(BtlClient *client, u32 i)
{
    return client->slotFlags[i];
}










u8 func_021CF448(BtlClient *client)
{
    u32 i;
    u32 sum;
    u32 n;
    sum = 0;
    n = client->slotIndex;
    i = 0;
    for (; i < n; i++) sum += client->slotFlags[i];
    return sum;
}











u32 func_021CF470(u8 *p, void *q, u8 *o)
{
    u32 id;
    u16 a;
    u32 b;
    union Slot t;
    if (func_021D5B68(q) != 0) {
        if (o != 0) {
            func_021D8434((u32 *)o);
        }
        return 1;
    }
    if (func_021D5BDC(q, 0xc) != 0) {
        if (o != 0) {
            func_021D8444((u32 *)o);
        }
        return 1;
    }
    id = 0x19;
    if (func_021D62C4(q, id) != 0) {
        t = func_021D6314(q, id);
        id = func_021E8B80(t);
        b = func_021D67C4(q);
        if (o != 0) {
            func_021D82D0((struct Unk021D82D0 *)o, id, b);
        }
        return 1;
    }
    if (func_021D62C4(q, 0x1a) != 0) {
        a = func_021D67A8(q);
        b = func_021D67C4(q);
        func_021D5778(q, a);
        if (o != 0) {
            func_021D82D0((struct Unk021D82D0 *)o, a, b);
        }
        return 1;
    }
    return 0;
}











u32 func_021CF524(BtlClient *client, void *q, u32 y)
{
    u32 n = func_021D5448(q);
    u32 c = 0;
    u32 i = 0;
    for (; i < n; i++) {
        if (func_021CF5B0(client, q, (u32)func_021D54C0(q, (u8)i), 0) == 0) {
            if ((u32)func_021D5584(q, (u8)i) != 0) {
                c++;
            }
        }
    }
    if (c == 0) {
        func_021CF58C((struct Unk021D82D0 *)y, client, q);
        return 1;
    }
    return 0;
}










void func_021CF58C(struct Unk021D82D0 *out, BtlClient *client, void *q)
{
    u32 v;
    v = func_021D81F8(client->main, client->side, q, 165, client->actionResult);
    func_021D82D0(out, 165, v);
}










int func_021CF5B0(BtlClient *client, void *m, u32 move, void *out)
{
    u32 k;
    u32 k2;
    union Slot w;
    if (move == 0xa5) return 0;
    if (func_021CF89C(client, m) && func_021D62C4(m, 0x1b)) {
        w = func_021D6314(m, 0x1b);
        k = func_021E8B80(w);
        if (func_021D5750(m, k) && k != move) {
            if (out) {
                func_021EAF18(out, 1, 0x63);
                func_021EAF50(out, func_021D5B40(m));
                func_021EAF50(out, k);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0x17)) {
        k2 = func_021E8B80(func_021D6314(m, 0x17));
        if (move != k2) {
            if (out) {
                func_021EAF18(out, 1, 0x64);
                func_021EAF50(out, func_021D5440(m));
                func_021EAF50(out, k2);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0xb) && WAZA_TOOL_IsDamaging((void *)move) == 0) {
        if (out) {
            func_021EAF18(out, 2, 0x23b);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xc) && move == func_021D67B8(m)) {
        if (out) {
            func_021EAF18(out, 2, 0x244);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xd) && move == func_021D62D8(m, 0xd) && move != 0xa5) {
        if (out) {
            func_021EAF18(out, 2, 0x253);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xf) && WAZA_TOOL_GetFlag((void *)move, 0xc)) {
        if (out) {
            func_021EAF18(out, 2, 0x37a);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(client->battleField), 3) && func_021EFC1C((int)client->battleField, (int)client->side, m, move)) {
        if (out) {
            func_021EAF18(out, 2, 0x24d);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(client->battleField), 2) && WAZA_TOOL_GetFlag((void *)move, 9)) {
        if (out) {
            func_021EAF18(out, 2, 0x43e);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    return 0;
}











u32 func_021CF81C(BtlClient *client, void *q, u8 *out)
{
    u8 n = func_021D5448(q);
    u32 r = 4;
    u8 i = 0;
    for (; i < n; i++) {
        if (func_021D5584(q, i) != 0) {
            out[i] = (func_021CF5B0(client, q, func_021D54C0(q, i), 0) == 0) ? 1 : 0;
            if (r == 4 && out[i] != 0) {
                r = i;
            }
        } else {
            out[i] = 0;
        }
    }
    for (; i < 4; i++) {
        out[i] = 0;
    }
    return r;
}










int func_021CF89C(BtlClient *client, void *q)
{
    if (func_021EFCE4(client->battleField, 7)) return 0;
    if (func_021D62C4(q, 19)) return 0;
    if (func_021D59B4(q, 17) != 103) return 1;
    return 0;
}











u32 func_021CF8D4(BtlClient *client, void *q, u8 *a, u16 *b)
{
    u32 r;
    if (func_021CF89C(client, q) != 0) {
        if (func_021D5B40(q) == 0x127) {
            return 4;
        }
    }
    r = func_021CF9B4(client, q, a, b);
    if (r == 4) {
        *a = 0x1f;
        *b = 0;
        r = 4;
    }
    return r;
}











u32 func_021CF918(BtlClient *client, u8 *a, u16 *b)
{
    u32 i;
    u8 *m;
    u32 r;

    for (i = 0; i < client->slotCount; i++) {
        m = func_021B9C00(client->sideData, (u8)i);
        if (func_021D5B68(m) == 0) {
            if (func_021CF89C(client, m) != 0 && func_021D5B40((struct QI *)m) == 0xe4)
                return 4;
            if (func_021D59B4(m, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < client->slotCount; i++) {
        r = func_021CF9B4(client, func_021B9C00(client->sideData, (u8)i), a, b);
        if (r != 4)
            return r;
    }
    return 4;
}










u32 func_021CF9B4(BtlClient *client, void *m, u8 *a, u16 *b)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *q;
    u16 k;
    n = func_021B8D38(client->main, (int)client->side, (u16)(func_021B8D8C(client->main, client->side, func_021D5440(m)) | 0x100), buf);
    for (i = 0; i < n; i++) {
        q = func_021B9934(client->side, buf[i]);
        k = func_021D59B4(q, 0x11);
        func_021D5440(q);
        if (k == 0x17 && func_021CFAC4(client, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x47 && func_021CFADC(client, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x2a && func_021CFB8C(client, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
    }
    if (func_021D62C4(m, 0x16) || func_021D62C4(m, 8) || func_021D62C4(m, 0x15)) {
        *a = func_021D5440(m);
        *b = 0;
        return 3;
    }
    return 4;
}










int func_021CFAC4(void *p, void *q)
{
    if (func_021D59B4(q, 17) != 23) return 1;
    return 0;
}











int func_021CFADC(BtlClient *client, void *m)
{
    u32 a;

    a = func_021CF89C(client, m);
    if (func_021EFCE4((char *)(client->battleField), 2) != 0)
        return 1;
    if (func_021D62C4(m, 0x1f) != 0)
        return 1;
    if (func_021D62C4(m, 0x15) != 0)
        return 1;
    if (a != 0 && func_021D5B40(m) == 0x116)
        return 1;
    if (func_021D59B4(m, 0x11) == 0x1a)
        return 0;
    if (func_021D5814(m, 2) != 0)
        return 0;
    if (func_021D62C4(m, 0x1e) != 0)
        return 0;
    if (func_021D62C4(m, 0x20) != 0)
        return 0;
    if (a != 0 && func_021D5B40(m) == 0x21d)
        return 0;
    return 1;
}










/*
 * extent: follower 0x021CFBA4 already has its own matched source/shard.
 */
int func_021CFB8C(void *p, void *q)
{
    if (func_021D5814(q, 8)) return 1;
    return 0;
}










/*
 * semantic: signed byte -1 has the original stored bits 0xff. The body
 *   only writes bytes and never reads through p. Six stores cover p10c..p111.
 */
void func_021CFBA4(BtlClient *client)
{
    u32 i = 0;
    s8 fill = -1;
    for (; i < 6; i++) client->slotOrder[i] = fill;
}









int func_021CFBBC(BtlClient *client, int v)
{
    u32 i = 0;
    for (; i < 6; i++) {
        if (client->slotOrder[i] == v) return 1;
    }
    return 0;
}









void func_021CFBE0(BtlClient *client, u32 i, u32 v)
{
    if (i < 6) client->slotOrder[i] = v;
}









int func_021CFBF0(BtlClient *client, void *m, u32 slot, u8 *out)
{
    u8 choice;
    u8 id;
    u16 k;
    u8 buf[6];
    u8 *q;
    u32 n;
    u32 i;
    u8 ok;
    choice = 6;
    if (func_021CF8D4(client, m, &id, &k) != 4) return 0;
    if (func_021B9B98(client->sideData) <= client->slotCount) return 0;
    q = func_021CFD50(client, func_021B8D8C(client->main, client->side, func_021D5440(m)));
    if (!q) return 0;
    if (func_021D6C24((struct R4 *)q))
        q = func_021B937C(client->main, client->side, q);
    if (func_021CFDCC(client, m)) ok = 1;
    else if (func_021CFE08(client, m, q)) ok = 1;
    else if (func_021CFE98(client, m, q)) ok = 1;
    else if (func_021CFFAC(client, m, q)) ok = 1;
    else if (func_021D0100(client, m, q, &choice)) ok = 1;
    else if (func_021D0248(client, m, &choice)) ok = 1;
    else if (func_021D0304(client, m, q, &choice)) ok = 1;
    else return 0;
    if (!ok) return 0;
    if (choice == 6) {
        n = func_021D0980(client, buf);
        func_021D09E0(client, buf, n, q);
        for (i = 0; i < n; i++) {
            if (!func_021CFBBC(client, buf[i])) {
                choice = buf[i];
                break;
            }
        }
    }
    if (choice == 6) return 0;
    func_021CFBE0(client, slot, choice);
    *out = choice;
    return 1;
}









u8 *func_021CFD50(BtlClient *client, int k)
{
    u8 buf[4];
    u8 n;
    u32 v;

    n = func_021B8D38(client->main, (int)client->side, (u16)(k | 0x100), buf);
    if (n) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if (n == 0) {
            v = (u32)(client->rng.seed >> 32);
        } else {
            v = (u32)(((client->rng.seed >> 32) * (u32)n) >> 32);
        }
        return func_021B9934(client->side, buf[(u8)v]);
    }
    return 0;
}








/*
 * lever: explicit aggregate return local reserves the original eight-byte frame;
 *   named incremented accessor result gives cmp r0,r4.
 */
int func_021CFDCC(void *p, void *q)
{
    u32 n;
    u32 id = 20;
    u32 m;
    union Slot t;
    if (func_021D62C4(q, id)) {
        t = func_021D6314(q, id);
        n = func_021E8AFC(t);
        m = func_021D631C(q, id) + 1;
        if (m == n) return 1;
    }
    return 0;
}









int func_021CFE08(BtlClient *client, void *a, void *b)
{
    if (func_021B8588(client->main) != 0)
        return 0;
    if (func_021D59B4(b, 0x11) == 0x19) {
        if (func_021D0644(client, a, b, 4) == 0 && func_021D055C(client, b, 4) != 0) {
            client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
            if ((u32)(((client->rng.seed >> 32) * 3) >> 32) < 2)
                return 1;
        }
    }
    return 0;
}








/*
 * extent: two zero padding bytes at 0x021CFFAA, followed by labelled func_021CFFAC.
 */
int func_021CFE98(BtlClient *client, void *a, void *b)
{
    u8 n;
    u16 k;
    u32 c;
    u32 i;
    u32 v;
    k = func_021D57FC(b);
    n = func_021D5448(a);
    c = 0;
    for (i = 0; i < n; i++) {
        v = (u32)func_021D54C0(a, (u8)i);
        if (WAZA_TOOL_IsDamaging((void *)v)) {
            if (func_021D799C(WAZA_TOOL_GetType((void *)v), k))
                return 0;
            c++;
        }
    }
    if (c >= 2) {
        if (func_021D055C(client, b, 4)) {
            client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
            return (u32)(((client->rng.seed >> 32) * 3) >> 32) < 2;
        }
        if (func_021D055C(client, b, 3)) {
            client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
            return (u32)(((client->rng.seed >> 32) * 2) >> 32) < 1;
        }
    }
    return 0;
}







int func_021CFFAC(BtlClient *client, void *mon, void *target)
{
    u32 id;
    int valid;
    u32 kind;
    union Slot slot;
    if (func_021D62C4(mon, 0x1b)) {
        slot = func_021D6314(mon, 0x1b);
        id = func_021E8B80(slot);
        if (id) {
            valid = WAZA_TOOL_IsDamaging((void *)id);
            kind = WAZA_TOOL_GetType((void *)id);
            if (func_021D799C(kind, func_021D57FC(target)) == 0 && valid) {
                if (func_021D055C(client, target, 4)) {
                    client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                    return (u32)(((client->rng.seed >> 32) * 3) >> 32) < 2;
                }
                if (func_021D055C(client, target, 3)) {
                    client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                    return (u32)(((client->rng.seed >> 32) * 2) >> 32) < 1;
                }
            }
            if (!valid) {
                client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                return (u32)(((client->rng.seed >> 32) * 2) >> 32) < 1;
            }
        }
    }
    return 0;
}







int func_021D0100(BtlClient *client, void *mon, void *target, u8 *out)
{
    u16 hist[5];
    u32 i;
    u8 pos;
    u32 j;
    const struct Row *row;
    pos = 0;
    if (func_021D0644(client, mon, target, 4)) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if ((u32)(((client->rng.seed >> 32) * 3) >> 32) == 0) return 0;
    }
    while (func_021D6940(mon, 1, pos++, hist + 1)) {
        for (i = 0; i < 4; i++) {
            row = &d_021EFFC2[i];
            if (((u8 *)hist)[6] == row->kind) {
                for (j = 0; j < 4; j++) {
                    if (!row->ids[j]) break;
                    if (func_021D04E4(client, row->ids[j], (u8 *)hist)) {
                        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                        if ((u32)(((client->rng.seed >> 32) * 2) >> 32) == 0) {
                            *out = ((u8 *)hist)[0];
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}








int func_021D0248(BtlClient *client, void *m, u8 *out)
{
    u16 t[4];
    u8 idx;

    if (func_021D59B4(m, 0x11) == 0x1e) {
        if (func_021D62C4(m, 2) || func_021D62C4(m, 3)) {
            if (func_021D5C44(m) >= 0x32000) {
                if (func_021D6940(m, 1, 0, t)) {
                    if (func_021D05C4(client, ((u8 *)t)[4], 2, &idx)) {
                        *out = idx;
                        return 1;
                    }
                } else {
                    client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                    return (u32)(((client->rng.seed >> 32) * 2) >> 32) ? 0 : 1;
                }
            }
        }
    }
    return 0;
}







int func_021D0304(BtlClient *client, void *mon, void *target, u8 *out)
{
    u16 hist[4];
    u32 sum;
    u32 i;
    u32 n;
    u8 *other;
    int affinity;
    if (func_021D0644(client, mon, target, 4)) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if ((u32)(((client->rng.seed >> 32) * 10) >> 32) != 0) return 0;
    }
    sum = 0;
    for (i = 1; i <= 7; i++) sum += func_021D59B4(mon, i);
    if (sum >= 4) return 0;
    if (func_021D6940(mon, 1, 0, hist)) {
        n = func_021B9B94(client->sideData);
        i = func_021D7F2C(func_021B8588(client->main), client->slotCount);
        for (; i < n; i++) {
            if (!func_021CFBBC(client, (u8)i)) {
                other = func_021B9C00(client->sideData, (u8)i);
                if (func_021D0644(client, other, target, 4)) {
                    affinity = func_021D799C(((u8 *)hist)[4], func_021D57FC(other));
                    if (affinity == 0) {
                        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                        if ((u32)(((client->rng.seed >> 32) * 2) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    } else if (affinity < 3) {
                        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
                        if ((u32)(((client->rng.seed >> 32) * 3) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}








int func_021D04E4(BtlClient *client, u16 a, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(client->sideData);
    i = func_021D7F2C(func_021B8588(client->main), client->slotCount);
    for (; i < n; i++) {
        if (func_021CFBBC(client, (u8)i) == 0) {
            m = func_021B9C00(client->sideData, (u8)i);
            if (func_021D5B68(m) == 0 && a == func_021D59B4(m, 0x11)) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}








int func_021D055C(BtlClient *client, void *a, int b)
{
    u32 n;
    u32 i;

    n = func_021B9B94(client->sideData);
    i = func_021D7F2C(func_021B8588(client->main), client->slotCount);
    for (; i < n; i++) {
        if (func_021CFBBC(client, (u8)i) == 0) {
            if (func_021D0644(client, func_021B9C00(client->sideData, (u8)i), a, b))
                return 1;
        }
    }
    return 0;
}








int func_021D05C4(BtlClient *client, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(client->sideData);
    i = func_021D7F2C(func_021B8588(client->main), client->slotCount);
    for (; i < n; i++) {
        if (func_021CFBBC(client, (u8)i) == 0) {
            m = func_021B9C00(client->sideData, (u8)i);
            if (func_021D5B7C(m) != 0 && func_021D799C(a, func_021D57FC(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}








int func_021D0644(BtlClient *client, void *m, void *a, int b)
{
    u16 x;
    u8 n;
    u32 i;
    u32 q;

    if (func_021D5B68(m) == 0) {
        x = func_021D57FC(a);
        n = func_021D5448(m);
        for (i = 0; i < n; i++) {
            q = func_021D54C0(m, (u8)i);
            if (func_021D5584(m, (u8)i) && WAZA_TOOL_IsDamaging((void *)q)
                && func_021CF5B0(client, m, q, 0) == 0) {
                if (func_021D799C(WAZA_TOOL_GetType((void *)q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}








u8 func_021D06C8(BtlClient *client)
{
    u8 buf[2];
    u32 cnt;
    u32 v;

    cnt = 1;
    buf[0] = 1;
    if (func_021D5B68(func_021B9C00(client->sideData, (u8)(int)func_021B9AB0(2))) == 0) {
        buf[cnt++] = 2;
    }
    if (func_021D5B68(func_021B9C00(client->sideData, (u8)(int)func_021B9AB0(3))) == 0) {
        buf[cnt++] = 3;
    }
    if (cnt > 1) {
        client->rng.seed = client->rng.mul * client->rng.seed + client->rng.add;
        if (cnt == 0) {
            v = (u32)(client->rng.seed >> 32);
        } else {
            v = (u32)(((client->rng.seed >> 32) * (u32)cnt) >> 32);
        }
        return buf[v];
    }
    return 1;
}







/*
 * lever: nested one-word aggregate return removes its extra frame word;
 *   named count/bytes reproduce original final read/store order. Three
 *   iteration runs, two scheduling variants; no prior compiles.
 * semantic: state/cursor arithmetic is unsigned; byte counters promote
 *   safely and narrow on store. CF81C writes all four availability bytes
 *   before return; CFBF0 writes the single output byte on every nonzero
 *   return path. Full-width pointer payloads retain their original bits.
 */
int func_021D0770(BtlClient *client, u32 *state)
{
    u8 available[4];
    u8 choice;
    u32 move;
    u32 slot;
    u8 sel;
    u32 sub;
    u32 result;
    u32 count;
    u32 bytes;
    switch (*state) {
    case 0:
        func_021CFBA4(client);
        client->slotIndex = 0;
        client->extraActionCount = 0;
        *state = 1;
    case 1:
        if (client->slotIndex >= client->slotCount) break;
        (client->activeMon) = func_021B9C00(client->sideData, client->slotIndex);
        (client->actionCursor) = (u8 *)client->actions+client->slotIndex*4;
        if (func_021D5B68((client->activeMon))) {
            func_021D8434((u32 *)(client->actionCursor));
            goto complete;
        }
        if (func_021CF470((u8 *)client,(client->activeMon),(client->actionCursor))) goto complete;
        move = func_021D3DC4((u8 *)client,(client->activeMon),client->sideData);
        if (move) {
            func_021D8358((u32 *)(client->actionCursor),move,client->slotIndex,0);
            goto complete;
        }
        if (func_021B86B8(client->main) && func_021CFBF0(client,(client->activeMon),client->slotIndex,&choice)) {
            func_021D8394((client->actionCursor),client->slotIndex,choice);
            goto complete;
        }
        if (func_021B8588(client->main) == 3) {
            sel = func_021D06C8(client);
            if (sel != 1) {
                sub = func_021B9AB0(sel);
                func_021D83FC((u32 *)(client->actionCursor),sel);
                (client->activeMon) = func_021B9C00(client->sideData,sub);
                client->extraActionCount = 1;
                (client->actionCursor) = (u8 *)((u32)(client->actionCursor)+4U);
            }
        }
        if (func_021D62C4((client->activeMon),0x19)) {
            move = func_021E8B80(func_021D6314((client->activeMon),0x19));
            result = func_021D81F8(client->main,client->side,(client->activeMon),move,(u8 *)&client->rng);
            func_021D82D0((struct Unk021D82D0 *)(client->actionCursor),move,result);
            goto complete;
        }
        if (func_021CF524(client,(client->activeMon),(u32)(client->actionCursor))) *state = 3;
        func_021D5448((client->activeMon));
        slot = func_021CF81C(client,(client->activeMon),available);
        if (slot != 4) {
            result = func_021B8D8C(client->main,client->side,func_021D5440((client->activeMon)));
            func_021880BC((int)client->recorder,available,result);
            *state = 2;
        } else {
            func_021CF58C((struct Unk021D82D0 *)((u32)(client->actionCursor)),client,(client->activeMon));
            goto complete;
        }
        break;
    case 2:
        if (func_02187FB0(client->recorder)) break;
        slot = func_02188134(client->recorder);
        if (slot != 4) {
            sub = func_02188140(client->recorder);
            move = func_021D54C0((client->activeMon),slot);
            func_021D82D0((struct Unk021D82D0 *)(client->actionCursor),move,sub);
        } else func_021D8414((u32 *)(client->actionCursor));
complete:
        *state = 3;
        break;
    case 3:
        client->slotIndex++;
        count = client->slotCount;
        if (client->slotIndex >= count) {
            bytes = (count+client->extraActionCount)*4;
            client->sendData = (u8 *)client->actions;
            client->sendSize = bytes;
            client->extraActionCount = 0;
            return 1;
        }
        *state = 1;
        break;
    }
    return 0;
}








u8 func_021D0980(BtlClient *client, u8 *out)
{
    u32 n;
    u8 c;
    u32 i;

    n = func_021B9B94(client->sideData);
    i = func_021D7F2C(func_021B8588(client->main), client->slotCount);
    c = 0;
    for (; i < n; i = (u8)(i + 1)) {
        if (func_021D5B7C(func_021B9C00(client->sideData, i))) {
            if (out)
                out[c] = i;
            c = (u8)(c + 1);
        }
    }
    return c;
}





/*
 * pass 6 2026-10-06 P6L01: EXACT* (302 B code plus 2 B pad), also EXACT* under -lang c99. The
 * closing change is u16 type with func_021D799C declared (int, u16). The callee
 * (ov093_func_021D799C.c) also matches EXACT with a u16 second parameter, so the prototype is consistent.
 * Why it closes (seen in a debugger capture of the post-RA scheduler of mwccarm): a word-sized spill of a
 * narrow variable gets the "narrow locals" alias set. With int type, the type store after the call
 * has its own alias, so the count home store has a height of 6 and 'adds r0,r3' (height 7) goes before
 * it. With u16 type (no int conversion, so no hoisted int temp), the type store is in the same set, the
 * count store gets an edge to it (height 7), and it issues second, as in the original. Passes 1 to 5
 * (all 5 B or more) tried every source shape of the entry block; none can change this edge.
 */
void func_021D09E0(BtlClient *client, u8 *order, u8 count, void *target)
{
    u16 scores[6];
    u16 type;
    u8 i;
    u8 j;
    void *mon;
    u16 move;
    u16 power;
    u16 temp;
    u8 tempid;
    type = func_021D57FC(target);
    for (i = 0; i < count; i++) {
        scores[i] = 0;
        mon = func_021B9C00(client->sideData, order[i]);
        if (!func_021D5B68(mon)) {
            u8 n;
            n = func_021D5448(mon);
            for (j = 0; j < n; j++) {
                if (func_021D5584(mon, j)) {
                    move = func_021D54C0(mon, j);
                    if (WAZA_TOOL_IsDamaging((void *)(u32)move)) {
                        int kind;
                        kind = WAZA_TOOL_GetType((void *)(u32)move);
                        power = WAZA_TOOL_GetPower((void *)(u32)move);
                        if (power < 10) power = 60;
                        switch (func_021D799C(kind, type)) {
                        case 5: power *= 4; break;
                        case 4: power *= 2; break;
                        case 2: power /= 2; break;
                        case 1: power /= 4; break;
                        case 0: power = 0; break;
                        case 3: break;
                        }
                        if (scores[i] < power) scores[i] = power;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
                tempid = order[i];
                order[i] = order[j];
                order[j] = tempid;
            }
        }
    }
}





void func_021D0B10(BtlClient *client, u32 a, u32 b, void *q, void *out)
{
    func_0689CA98(q, (unsigned int)client->sideData, b, a);
    func_0689CAB0(q, client->slotCount);
    func_0689CAE0(out, q);
}







void func_021D0B6C(BtlClient *client, u8 *s)
{
    u8 i;

    for (i = 0; i < s[6]; i++)
        func_021D8394((u8 *)client->actions + i * 4, s[i + 3], s[i]);
    client->sendData = (u8 *)client->actions;
    client->sendSize = s[6] << 2;
}






void func_021D0BB0(BtlClient *client)
{
    u8 pair[2];
    u8 start;
    u8 count;
    u32 n;
    u32 i;
    u32 j;
    count = 0;
    n = func_021B9B94(client->sideData);
    start = func_021B99C0(client->main, client->clientId);
    for (i = 0; i < client->pairCount; i++) {
        func_021B8E28(client->main, client->pairs[i], &pair[1], &pair[0]);
        for (j = start; j < n; j++) {
            if (!func_021D5B68(func_021B9C00(client->sideData, (u8)j))) {
                func_021D8394((u8 *)client->actions + count++ * 4, pair[0], j);
                start = j + 1;
                break;
            }
        }
    }
    *(void * *)&client->sendData = client->actions;
    client->sendSize = count * 4;
}







u8 func_021D0C78(BtlClient *client, u8 *out)
{
    u8 *arr;
    u8 n;
    u32 i;
    u32 cnt;

    n = func_021EEC20((int)client->netChannel, &arr);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        if (client->clientId == func_021B8DE4(client->main, arr[i])) {
            out[cnt] = arr[i];
            cnt++;
        }
    }
    return cnt;
}







int func_021D0CC4(BtlClient *client, int *state)
{
    int t;
    u8 *q;
    u8 f;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 3, 5);
        func_021EAF18((struct L *)((u8 *)&client->messageB), 3, 1);
        func_021EABC4(client->view, (u32)client->messageA.data, (u32)((u8 *)&client->messageB), 0);
        (*state)++;
        break;
    case 1:
        if (func_021EAC54(client->view, &t)) {
            f = 0;
            if (t != 0)
                f = 1;
            q = &client->sendByte;
            *q = f;
            client->sendData = q;
            client->sendSize = 1;
            return 1;
        }
        break;
    }
    return 0;
}





int func_021D0D38(BtlClient *client, int *state)
{
    return func_021D0E7C(client, state, 2);
}





int func_021D0D44(BtlClient *client, int *state)
{
    return func_021D0E7C(client, state, 1);
}






/*
 * lever: separate order[6] then pair[2] stack arrays keep the order base
 * at sp+6 and the index in the ldrb register offset; one buffer or a
 * struct member array reassociates this into a base+index and immediate 2.
 * follower: 021D0E74 is an eight-byte tail-call stub to func_021CE1B0;
 * included in this complete 300-byte unit after parent ownership audit.
 */
int func_021D0D50(BtlClient *client)
{
    u8 order[6];
    u8 pair[2];
    u8 count;
    u8 n;
    u8 i;
    u8 *target;
    int result;
    client->pairCount = func_021D0C78(client, client->pairs);
    if (client->pairCount) {
        n = func_021D0980(client,order);
        if (n) {
            count = client->pairCount;
            target = func_021CFD50(client,client->pairs[0]);
            if (target) func_021D09E0(client,order,n,target);
            if (count > n) {
                if (func_021B8588(client->main) == 3) {
                    result = func_021D1058(client,client->actions);
                    if (result) {
                        client->sendSize = result;
                        *(void * *)&client->sendData = client->actions;
                        return 1;
                    }
                }
                count = n;
            }
            for (i=0;i<count;i++) {
                func_021B8E28(client->main,client->pairs[i],pair,pair+1);
                func_021D8394((u8 *)client->actions+i*4,pair[1],order[i]);
            }
            *(void * *)&client->sendData = client->actions;
            client->sendSize = count*4;
        } else {
            if (func_021D102C(client)) {
                result = func_021D1058(client,client->actions);
                if (result) {
                    client->sendSize = result;
                    *(void * *)&client->sendData = client->actions;
                    return 1;
                }
            }
            func_021D83C4(client->actions);
            *(void * *)&client->sendData = client->actions;
            client->sendSize = 4;
        }
    } else {
        func_021D8434(client->actions);
        *(void * *)&client->sendData = client->actions;
        client->sendSize = 4;
    }
    return 1;
}






int func_021D0E74(BtlClient *client, int *state)
{
    return func_021CE1B0(client,state);
}






/*
 * lever: the state-0 fallbacks and single-mon path set state 4, not 6;
 * duplicating the state-4 assignment inside both fallback arms preserves
 * the late cross-jump of D8/DC stores. Factoring it outside adds 12 bytes.
 * volatile: count at 021D0EB2 is reread at 021D0EB6 and 021D0ECC.
 */
int func_021D0E7C(BtlClient *client, int *state, u8 param)
{
    u8 order[6];
    u8 pair[2];
    u32 n;
    u32 count;
    int mode;
    void *mon;
    switch (*state) {
    case 0:
        ((CountField *)client)->count = func_021D0C78(client, client->pairs);
        if (((CountField *)client)->count != 0) {
            n = func_021D0980(client, order);
            if (n != 0) {
                count = ((CountField *)client)->count;
                if (count > n) count = n;
                if (func_021D102C(client) != 0) {
                    mon = func_021B9C00(client->sideData, 0);
                    if (n == 1 && func_021D5B68(mon) != 0) {
                        func_021D8394(client->actions, 0, order[0]);
                        client->sendData = (u8 *)client->actions;
                        client->sendSize = 4;
                        *state = 4;
                        break;
                    }
                }
                func_021B8E28(client->main, client->pairs[0], &pair[1], &pair[0]);
                func_021D0B10(client, param, count, client->slotChoices, client->choiceFlags);
                func_021E9A78(client->view, client->slotChoices, pair[0], 0, client->choiceFlags);
                func_021CE068(client);
                *state = 1;
            } else {
                if (func_021D102C(client) != 0 && (mode = func_021D1058(client, client->actions)) != 0) {
                    client->sendSize = mode;
                    client->sendData = (u8 *)client->actions;
                    *state = 4;
                } else {
                    func_021D83C4(client->actions);
                    client->sendData = (u8 *)client->actions;
                    client->sendSize = 4;
                    *state = 4;
                }
            }
        } else {
            func_021D8434(client->actions);
            client->sendData = (u8 *)client->actions;
            client->sendSize = 4;
            *state = 4;
        }
        break;
    case 1:
        if (func_021CE08C(client) != 0) {
            func_021E9B14(client->view);
            *state = 2;
        } else if (func_021E9B20(client->view) != 0) {
            func_021D0B6C(client, client->choiceFlags);
            *state = 3;
        }
        break;
    case 2:
        if (func_021E9B20(client->view) != 0) {
            func_021D0BB0(client);
            *state = 3;
        }
        break;
    case 3:
        func_021CE0E0(client);
        *state = 4;
        break;
    case 4:
        if (func_021B86C0(client->main) != 0) {
            client->viewLocked = 1;
            func_021EA7FC(client->view);
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (func_021EA814(client->view) != 0) {
            *state = 6;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}






/*
 * extent: compiled 42 bytes followed by two zero alignment bytes.
 */
int func_021D102C(BtlClient *client)
{
    if (func_021B8588(client->main) == 3 && func_021D5B68(func_021B9C00(client->sideData, 0)) != 0) return 1;
    return 0;
}







int func_021D1058(BtlClient *client, void *q)
{
    int k;

    k = 2;
    if (func_021D5B68(func_021B9C00(client->sideData, (u8)(int)func_021B9AB0(2))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    k = 3;
    if (func_021D5B68(func_021B9C00(client->sideData, (u8)(int)func_021B9AB0(3))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    return 0;
}



int func_021D10B8(BtlClient *client, int *state)
{
    u8 *args;
    int choice;
    u8 count;
    switch (*state) {
    case 0:
        func_021EEC20((int)client->netChannel, &args);
        if (args[0] != 0x1F) {
            func_021EAF18((struct L *)&client->messageA, 1, 0x14);
            func_021EAF50((struct L *)&client->messageA, 1);
            func_021EAF50((struct L *)&client->messageA, args[0]);
            func_021EAF78((u8 *)&client->messageA, 0xFF);
            func_021EA614(client->view, &client->messageA);
            *state = 1;
        } else *state = 4;
        break;
    case 1:
        func_021EA710(client->view);
        if (func_021EA720(client->view) != 0) {
            func_021EAF18((struct L *)&client->messageA, 3, 6);
            func_021EAF18((struct L *)&client->messageB, 3, 7);
            func_021EABC4(client->view, (u32)&client->messageA, (u32)&client->messageB, 1);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            if (func_021EAC54(client->view, &choice) != 0) {
                if (choice == 0) {
                    func_021D0B10(client, 0, 1, client->slotChoices, client->choiceFlags);
                    func_021E9A78(client->view, client->slotChoices, 0, 0, client->choiceFlags);
                    *state = 3;
                } else *state = 4;
            }
        }
        break;
    case 3:
        if (func_021E9B20(client->view) != 0) {
            if (func_0689CB14(client->choiceFlags) == 0) {
                count = func_0689CB1C(client->choiceFlags);
                if (count != 0 && count < 6) {
                    func_021D8394(client->actions, 0, count);
                    *state = 5;
                } else {
invalid:
                    *state = 4;
                }
            } else goto invalid;
        }
        break;
    case 4:
        func_021D8434(client->actions);
        *state = 5;
    case 5:
        client->sendData = (u8 *)client->actions;
        client->sendSize = 4;
        return 1;
    }
    return 0;
}











int func_021D123C(BtlClient *client)
{
    u8 *tmp;
    int r4 = func_021EEC20((int)client->netChannel, &tmp);
    if (client->timeLimitTimer != 0)
        func_021EE608((u8 *)(client->timeLimitTimer), (const u8 *)tmp, r4);
    if (client->requestParam != 0) {
        func_021BB4E0((Obj_td *)client->requestParam, tmp, r4);
        client->requestId = func_021EE638((u8 *)tmp);
    }
    return 1;
}










/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D127C(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return func_021D1290(client, state, q);
    return 1;
}









/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, not a shifted integer mask.
 */
int func_021D1290(BtlClient *client, int *state, void *a2)
{
    int idx;
    int mode;
    u8 flag;
    u16 msg;
    switch (*state) {
    case 0:
        if (client->flags.bit.windowDone != 0)
            return 1;
        idx = func_021B904C(client->main, 0);
        mode = func_021D13A4(client);
        flag = func_021B86C8((unsigned char **)(client->main));
        func_021B916C(client->main, mode);
        switch (mode) {
        case 1: msg = flag != 0 ? 0x31 : 0x30; break;
        case 0: msg = flag != 0 ? 0x33 : 0x32; break;
        case 2: msg = flag != 0 ? 0x35 : 0x34; break;
        default: return 1;
        }
        func_021EAF18((struct L *)&client->messageA, 1, msg);
        func_021EAF50((struct L *)&client->messageA, idx);
        if (flag != 0)
            func_021EAF50((struct L *)&client->messageA, func_021B904C(client->main, 1));
        func_021EA614(client->view, &client->messageA);
        if (mode == 1) {
            GFL_USE_CancelChangeAndPlayBgm(func_021B86DC(client->main), 0xFFFF);
            (*state)++;
        } else {
            GFL_USE_FadeOutBgm(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (func_021EA710(client->view) != 0)
            return 1;
        break;
    case 2:
        if (func_021EA710(client->view) != 0)
            (*state)++;
        break;
    case 3:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D13A4(BtlClient *client)
{
    u16 *q;

    func_021EEC20((int)client->netChannel, (u8 **)&q);
    switch (q[1]) {
    case 0:
        if (func_021B902C((u8)q[0], client->clientId) == 0)
            return 1;
        break;
    case 1:
        if (func_021B902C((u8)q[0], client->clientId) == 0)
            return 0;
        break;
    }
    return q[1];
}







int func_021D13FC(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return func_021D1410(client, state, q);
    return 1;
}











int func_021D1410(BtlClient *client, int *state, void *q)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021D13A4(client) == 1) {
            func_021F878C(func_021B86DC(client->main));
            a = func_021B904C(client->main, 0);
            b = func_021B904C(client->main, 1);
            if (a == b) {
                func_021EAF18((struct L *)client->messageA.data, 1, 44);
                func_021EAF50((struct L *)client->messageA.data, a);
            } else {
                func_021EAF18((struct L *)client->messageA.data, 1, 45);
                func_021EAF50((struct L *)client->messageA.data, a);
                func_021EAF50((struct L *)client->messageA.data, b);
            }
            func_021EA614(client->view, client->messageA.data);
            *state = 1;
        } else if (func_021BA1A8(client->main, 0x100) == 0) {
            a = func_021B8FF4(client->main);
            func_021EAF18((struct L *)client->messageA.data, 1, 54);
            func_021EAF50((struct L *)client->messageA.data, a);
            func_021EAF50((struct L *)client->messageA.data, a);
            func_021EA614(client->view, client->messageA.data);
            *state = 9;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA710(client->view)) {
            a = func_021B904C(client->main, 0);
            func_021F7F58(func_021BA020(client->main, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 2;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(client->main, 0);
            func_021EA6B0(client->view, func_021BA004(client->main, a), 1);
            *state = 3;
        }
        break;
    case 3:
        if (func_021EA710(client->view)) {
            a = func_021B904C(client->main, 0);
            if (a != func_021B904C(client->main, 1)) {
                func_021F7998(0x271);
                *state = 4;
            } else {
                *state = 7;
            }
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(client->main, 1);
            func_021F7F58(func_021BA020(client->main, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 5;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(client->main, 1);
            func_021EA6B0(client->view, func_021BA004(client->main, a), 1);
            *state = 6;
        }
        break;
    case 6:
        if (func_021EA710(client->view))
            *state = 7;
        break;
    case 7:
        a = func_021B919C(client->main);
        if (a) {
            b = func_021B8FF4(client->main);
            func_021EAF18((struct L *)client->messageA.data, 1, 58);
            func_021EAF50((struct L *)client->messageA.data, b);
            func_021EAF50((struct L *)client->messageA.data, a);
            func_021EA614(client->view, client->messageA.data);
        }
        if (func_021B9210(client->main) == 0)
            *state = 11;
        else
            *state = 8;
        break;
    case 8:
        if (func_021EA710(client->view)) {
            a = func_021B9210(client->main);
            if (a) {
                b = func_021B8FF4(client->main);
                func_021EAF18((struct L *)client->messageA.data, 1, 59);
                func_021EAF50((struct L *)client->messageA.data, b);
                func_021EAF50((struct L *)client->messageA.data, a);
                func_021EA614(client->view, client->messageA.data);
            }
            *state = 11;
        }
        break;
    case 9:
        if (func_021EA710(client->view)) {
            a = func_021B9244(client->main);
            if (a) {
                func_021EAF18((struct L *)client->messageA.data, 1, 56);
                func_021EAF50((struct L *)client->messageA.data, client->clientId);
                func_021EAF50((struct L *)client->messageA.data, a);
                func_021EA614(client->view, client->messageA.data);
            }
            *state = 10;
        }
        break;
    case 10:
        if (func_021EA710(client->view)) {
            func_021EAF18((struct L *)client->messageA.data, 1, 57);
            func_021EAF50((struct L *)client->messageA.data, client->clientId);
            func_021EA614(client->view, client->messageA.data);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EA710(client->view))
            return 1;
        break;
    default:
        return 1;
    }
    return 0;
}











/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D1708(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return func_021D171C(client, state, q);
    return 1;
}











/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 */
int func_021D171C(BtlClient *client, int *state, void *a2)
{
    u32 mode;
    int idx;
    switch (*state) {
    case 0:
        if (client->flags.bit.windowDone != 0) return 1;
        mode = func_021D13A4(client);
        func_021B916C(client->main, mode);
        if (mode == 1) func_021F878C(func_021B86DC(client->main));
        if (mode <= 1) {
            idx = func_021B904C(client->main, 0);
            func_021F7F58(func_021BA020(client->main, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C(client, mode, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EA600(client->view);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            idx = func_021B904C(client->main, 0);
            if (idx == func_021B904C(client->main, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            mode = func_021D13A4(client);
            idx = func_021B904C(client->main, 1);
            func_021F7F58(func_021BA020(client->main, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C(client, mode, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            func_021EA600(client->view);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA710(client->view) != 0) return 1;
        break;
    }
    return 0;
}











/*
 * Verified C for it (match.py one --thumb, no --region, EXACT, 20 bytes):
 *   int PMSI_PARAM_IsEnabled(u16 *p) { return *p != 0xffff; }
 */
void func_021D185C(BtlClient *client, int a, int b)
{
    int idx;
    void *p;
    void *r;
    int v;

    idx = func_021B904C(client->main, b);
    p = func_021BA02C(client->main, idx, a);
    if (p != 0 && PMSI_PARAM_IsEnabled(p) != 0) {
        r = PMSI_PARAM_ToString(p, (u16)((client->heapId & 0x7fff) | 0x8000));
        func_021EA5E4(client->view, r);
        STRBUF_Delete(r);
        return;
    }
    v = func_021BA004(client->main, idx);
    if (v != 0) {
        func_021EAF18((struct L *)client->messageA.data, 7, (int)0);
        func_021EAF50((struct L *)client->messageA.data, (int)v);
        func_021EAF50((struct L *)client->messageA.data, (int)a);
        func_021EA5F0(client->view, client->messageA.data);
    }
}











int func_021D18EC(BtlClient *client, int *state)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021BA1A8(client->main, 0x200) == 0) {
            a = func_021B9210(client->main);
            if (a != 0) {
                b = func_021B8FF4(client->main);
                func_021EAF18((struct L *)client->messageA.data, 1, 0x3b);
                func_021EAF50((struct L *)client->messageA.data, b);
                func_021EAF50((struct L *)client->messageA.data, a);
                func_021EA614(client->view, client->messageA.data);
            }
        }
        (*state)++;
    case 1:
        if (func_021EA710(client->view) != 0)
            return 1;
        break;
    }
    return 0;
}











int func_021D1960(BtlClient *client, int *state)
{
    int a;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 1, 0x36);
        func_021EAF50((struct L *)client->messageA.data, client->clientId);
        func_021EA614(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0) {
            a = func_021B9244(client->main);
            if (a != 0) {
                func_021EAF18((struct L *)client->messageA.data, 1, 0x37);
                func_021EAF50((struct L *)client->messageA.data, client->clientId);
                func_021EAF50((struct L *)client->messageA.data, a);
                func_021EA614(client->view, client->messageA.data);
            }
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            func_021EAF18((struct L *)client->messageA.data, 1, 0x39);
            func_021EAF50((struct L *)client->messageA.data, client->clientId);
            func_021EA614(client->view, client->messageA.data);
            (*state)++;
        }
        break;
    case 3:
        if (func_021EA710(client->view) != 0)
            (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}











int func_021D1A18(BtlClient *client, int *state)
{
    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 1, 0xb7);
        func_021EA614(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0)
            (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}









int func_021D1A60(BtlClient *client, int *state)
{
    void *q;
    q = client->view;
    if (q != 0) return func_021D1A74(client, state, q);
    return 1;
}









int func_021D1A74(BtlClient *client, int *state, void *a2)
{
    u8 *args;
    int size;
    u16 len;
    Buf_021CC768 *buf;
    u32 i;
    int code;
again:
    switch (*state) {
    case 0:
        size = func_021EEC20((int)client->netChannel, &args);
        if (client->requestParam != 0 && client->requestId != 0 && client->flags.bit.requestSet != 0) {
            if (func_021BB570((u8 *)client->requestParam, client->requestId, args, size) != 0) {
                func_021B9184(client->main);
                client->flags.bit.requestSet = 0;
            }
            client->requestId = 0;
        }
        buf = client->workBuffer;
        len = size;
        func_02082A90(args, buf->buf, len);
        buf->wpos = len;
        buf->rpos = 0;
        if (client->viewLocked != 0) {
            client->viewLocked = 0;
            func_021EA824(client->view);
        }
        (*state)++;
    case 1:
        buf = client->workBuffer;
        if (buf->rpos == buf->wpos) {
            *state = 4;
            return 1;
        }
        if (func_021D3F4C(client->commandQueue) != 0) return 1;
        (*state)++;
    case 2:
        code = func_021CD5E0(client->workBuffer, (s32 *)client->seqCursorBuf);
        client->seqCode = code;
        if (code == 0x5E) return 1;
        for (i = 0; i < 0x5D; i++) {
            if (code == d_021F00DC[i].code) break;
        }
        if (i == 0x5D) {
            *state = 1;
            goto again;
        }
        client->seqFn = d_021F00DC[i].fn;
        client->seqState = 0;
        (*state)++;
    case 3:
        if ((client->seqFn)(client, &client->seqState, (s32 *)client->seqCursorBuf) != 0) {
            *state = 1;
            goto again;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}








int func_021D1BD0(BtlClient *client, int *state, int *pp)
{
    int t;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)client->messageA.data, 1, func_021D1C40(client, pp[0], &t));
        if (t != 0)
            func_021EAF50((struct L *)client->messageA.data, pp[0]);
        func_021EAF50((struct L *)client->messageA.data, pp[1]);
        func_021EA614(client->view, client->messageA.data);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0)
            return 1;
        break;
    }
    return 0;
}











int func_021D1C40(BtlClient *client, u8 x, int *out)
{
    u32 v;

    if (x == client->clientId) {
        *out = 0;
        if (func_021B8588(client->main) == 0 && func_021B86C0(client->main) == 0) {
            v = func_021CDEE8(client);
            if (v >= 0x4b)
                return 0x1d;
            if (v > 0x32)
                return 0x1c;
            if (v > 0x19)
                return 0x1b;
            if (v != 0)
                return 0x1a;
            return 0x19;
        }
        return 0x1a;
    }
    *out = 1;
    if (func_021B9F70(client->main, x) != 0)
        return 0x1e;
    return 0x1f;
}











int func_021D1CAC(BtlClient *client, int *state, int *pp)
{
    switch (*state) {
    case 0:
        func_021EA458(client->view, func_021B8E70(client->main, (u8)pp[0]), (u16)pp[1]);
        (*state)++;
        break;
    case 1:
        if (func_021EA478(client->view) != 0)
            return 1;
        break;
    }
    return 0;
}









static inline void setMessage(BtlClient *client, int code, u32 value, u32 id)
{
    func_021EAF18((struct L *)&client->messageA, 1, code);
    func_021EAF50((struct L *)&client->messageA, value);
    func_021EAF50((struct L *)&client->messageA, id);
    func_021EA614(client->view, &client->messageA);
}









/*
 * lever: append-id and send are written in every message arm; the inline
 * helper includes that tail. Factoring it outside the conditional merges
 * the initialisation call too early and loses 16 bytes.
 */
int func_021D1CF4(BtlClient *client, int *state, const u32 *params)
{
    u8 a = params[0];
    u8 b = params[1];
    u8 flag = params[3];
    u8 id;
    switch (*state) {
    case 0:
        if (flag != 0) {
            id = func_021D5440(func_021B9920(client->side, a, b));
            if (func_021B8CE8((int)(client->main), client->clientId, a) == 0) {
                if (client->clientId == a) {
                    func_021EAF18((struct L *)&client->messageA, 1, func_021D1DF4(client));
                    func_021EAF50((struct L *)&client->messageA, id);
                    func_021EA614(client->view, &client->messageA);
                } else {
                    setMessage(client, 0x11, a, id);
                }
            } else if (func_021B9F70(client->main, a) != 0) {
                setMessage(client, 0xE, a, id);
            } else {
                setMessage(client, 0x11, a, id);
            }
        }
        (*state)++;
        break;
    case 1:
        if (func_021EA710(client->view) != 0) {
            func_021EA488(client->view, func_021B8BEC(client->main, a, b), a, b);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA4C4(client->view) != 0) {
            func_021CDECC(client);
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1DF4(BtlClient *client)
{
    u8 *m;
    u8 t;
    int v;

    if (func_021B8588(client->main) == 0) {
        t = func_021B9064(client->main, client->clientId, 0);
        m = func_021B9920(client->side, t, 0);
        if (func_021D5B68(m) != 0)
            return 0xb;
        v = func_021D5C44((struct Rat *)m);
        if (v >= 0x4d800)
            return 0xb;
        if (v >= 0x37000)
            return 0x15;
        if (v >= 0x20800)
            return 0x16;
        if (v >= 0xa000)
            return 0x17;
        return 0x18;
    }
    return 0xb;
}









int func_021D1E6C(BtlClient *client, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0(client)) {
            return 1;
        }
        func_021EA678(client->view, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1EB4(BtlClient *client, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0(client)) {
            return 1;
        }
        func_021EA678(client->view, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(client->view)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1F10(BtlClient *client, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0(client)) {
            return 1;
        }
        func_021EA694(client->view, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1F58(BtlClient *client, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0(client)) {
            return 1;
        }
        func_021EA694(client->view, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(client->view)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D1FB4(BtlClient *client, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0(client)) {
            return 1;
        }
        func_021EA6F4(client->view, a[0], a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}








/*
 * Unlabelled leaf (filed for the blocker of func_021D2030, lane S15).
 */
u32 func_021D2000(BtlClient *client, u32 k, u8 b)
{
    u8 *r;

    if (k != 0xAE) {
        return func_0201BD28(k, 0x1B);
    }
    r = func_021B98AC((char *const *)client->side, b);
    if (r) {
        return func_021D80A8(r);
    }
    return func_0201BD28(k, 0x1B);
}









/*
 * lever: word locals with casts at the four descriptor loads, t2 before v
 * in declaration order, and a named nested-call result keep v in r7 and
 * t1/t2 in the original spill slots. The u8 b in the callee's own source
 * is widened here: the original caller has no second truncation after v.
 */
int func_021D2030(BtlClient *client, int *state, const u32 *a)
{
    u32 t2;
    u8 v;
    u32 t1;
    u32 t3;
    u32 result;
    switch (*state) {
    case 0:
        if (func_021CD9E0(client)) {
            return 1;
        }
        if (func_021B8590((unsigned char *)client->main)) {
            v = (u8)a[0];
            t1 = (u8)a[1];
            t2 = (u16)a[2];
            t3 = (u8)a[3];
            result = func_021D2000(client, t2, v);
            func_021EA0A0(client->view, v, t1, t2, result, t3, 0);
            *state = *state + 1;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA0E4(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D20BC(BtlClient *client, int *state, u32 *a)
{
    u32 t;

    switch (*state) {
    case 0:
        t = (u32)func_021B8DC0((unsigned char *)client->main, client->side, (u8)a[0]);
        func_021EA354(client->view, t, a[1] != 0);
        *state = *state + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}










int func_021D210C(BtlClient *client, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C(client->main, client->side, (u8)a[0]);
        func_021EA0F4(client->view, (u16)a[2], t, (u8)a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA120(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D215C(BtlClient *client, int *state, u32 *a)
{
    u8 buf[8];
    u8 i;
    u16 n;
    u32 p1;
    u16 p2;

    switch (*state) {
    case 0:
        n = a[0];
        p1 = a[1];
        p2 = a[2];
        for (i = 0; i < n; i++) {
            buf[i] = func_021CD644(client->workBuffer);
        }
        func_021EA280(client->view, n, p1, buf, p2);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D21D4(BtlClient *client, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        func_021EA384(client->view, func_021B8D8C(client->main, client->side, (u8)a[0]));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA3A0(client->view)) {
            func_021EA678(client->view, 0x61, (int *)a);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA710(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D2234(BtlClient *client, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C(client->main, client->side, (u8)a[0]);
        func_021F81D0(a[1], func_021B8E70(client->main, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}









int func_021D2278(BtlClient *client, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        if (func_021CD9E0(client) == 0) {
            t = func_021B8D8C(client->main, client->side, (u8)a[0]);
            func_021EA0A0(client->view, t, t, 1, func_0201BD28(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA0E4(client->view)) {
            t = func_021B8D8C(client->main, client->side, (u8)a[0]);
            if (func_021CD9E0(client) == 0) {
                func_020061E4(0x564);
            }
            func_021EA0F4(client->view, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA120(client->view)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D2320(BtlClient *client, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA40C(client->view, func_021B8D8C(client->main, client->side, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA428(client->view)) {
            func_021D646C(func_021B9934(client->side, (u8)(*c)));
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D2374(BtlClient *client, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA438(client->view, func_021B8D8C(client->main, client->side, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA448(client->view))
            return 1;
        break;
    }
    return 0;
}









int func_021D23B8(BtlClient *client, int *st, u32 *c)
{
    u32 t = func_021B8E70(client->main, func_021B8D8C(client->main, client->side, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(client))
            return 1;
        if (!func_021B8590(client->main))
            return 1;
        func_021EA7C8(client->view, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(client->view, t))
            return 1;
        break;
    }
    return 0;
}









int func_021D2424(BtlClient *client, int *st, u32 *c)
{
    u32 t = func_021B8E70(client->main, func_021B8D8C(client->main, client->side, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(client))
            return 1;
        if (!func_021B8590(client->main))
            return 1;
        func_021EA7D8(client->view, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(client->view, t))
            return 1;
        break;
    }
    return 0;
}









int func_021D2490(BtlClient *client, int *st, u32 *c)
{
    u8 id = c[0];

    switch (*st) {
    case 0:
        func_021EF9C0(client->battleField, (u8)id, (u16)c[1]);
        if (func_021CD9E0(client))
            return 1;
        if (id < 5)
            func_021F7998(d_021EFFAE[id].b);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(client->view, d_021EFFAE[id].a, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view))
            return 1;
        break;
    }
    return 0;
}









int func_021D2510(BtlClient *client, int *st, u32 *c)
{
    u16 v;

    switch (*st) {
    case 0:
        switch ((u8)c[0]) {
        case 1:
            v = 0x59;
            break;
        case 2:
            v = 0x5a;
            break;
        case 4:
            v = 0x5b;
            break;
        case 3:
            v = 0x5c;
            break;
        default:
            return 1;
        }
        func_021EA678(client->view, v, 0);
        (*st)++;
        break;
    case 1:
        if (func_021EA710(client->view)) {
            func_021EF9C8(client->battleField);
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D2580(BtlClient *client, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA384(client->view, func_021B8D8C(client->main, client->side, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(client->view))
            return 1;
        break;
    }
    return 0;
}









int func_021D25C4(BtlClient *client, int *st, u32 *c)
{
    int t = func_021B8D8C(client->main, client->side, (u8)(*c));

    switch (*st) {
    case 0:
        if (func_021CD9E0(client))
            return 1;
        if (!func_021B8590(client->main))
            return 1;
        func_021EA838(client->view, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA850(client->view, t))
            return 1;
        break;
    }
    return 0;
}









int func_021D2628(BtlClient *client, int *st, u32 *c)
{
    u8 id = *c;

    switch (*st) {
    case 0:
        func_021EA384(client->view, func_021B8D8C(client->main, client->side, id));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(client->view))
            return 1;
        break;
    }
    return 0;
}









int func_021D266C(BtlClient *client, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 a = c[0];
        u8 b = c[1];
        u8 d = c[2];
        int x = func_021B8DEC(client->main, b);
        int y = func_021B8DEC(client->main, d);
        u32 m = func_021B8E70(client->main, b);
        u32 n = func_021B8E70(client->main, d);
        func_021B9C10((u32 *)func_021B9AEC(client->side, a), x, y);
        func_021EA904(client->view, a, m, n, x, y);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA950(client->view))
            return 1;
        break;
    }
    return 0;
}








int func_021D2700(BtlClient *client, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021F7998(0x281);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            u8 a = c[0], b = c[1];
            u32 x, y, v, w;
            x = func_021B8BEC(client->main, a, b);
            y = func_021B8BEC(client->main, a, 1);
            v = func_021B8E70(client->main, x);
            w = func_021B8E70(client->main, y);
            func_021B9C10((u32 *)func_021B9AEC(client->side, a), b, 1);
            func_021EA904(client->view, a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA950(client->view)) {
            u8 a = c[2], b = c[3];
            u32 x, y, v, w;
            x = func_021B8BEC(client->main, a, b);
            y = func_021B8BEC(client->main, a, 1);
            v = func_021B8E70(client->main, x);
            w = func_021B8E70(client->main, y);
            func_021B9C10((u32 *)func_021B9AEC(client->side, a), b, 1);
            func_021EA904(client->view, a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 3:
        if (func_021EA950(client->view)) return 1;
        break;
    }
    return 0;
}








/*
 * evidence: Thumb 01 49 02 4b 18 47 c0 46; pools 0x26e and 0x021F7A29. No ARM9/SDK blocker work.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F7E94 is an ov094 Thumb tail stub (pool 0x26E, 0x021F7A29); other overlay, not filed. Integrator: seed label.
 */
int func_021D2814(BtlClient *client, int *state, unsigned int *q)
{
    switch (*state) {
    case 0:
        func_021F7E94((u8)func_021B8E70(client->main, (u8)q[0]));
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) return 1;
        break;
    }
    return 0;
}









int func_021D284C(BtlClient *client, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u32 t = func_021B8E70(client->main, (u8)(*c));
        if (func_021CD9E0(client))
            func_021F88BC(1);
        func_021F7EA4(t);
        (*st)++;
        break;
    }
    case 1:
        if (!func_021F7EB4()) {
            if (func_021CD9E0(client))
                func_021F88BC(0);
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D28AC(BtlClient *client, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 *a = func_021B9934(client->side, (u8)c[0]);
        u8 *b = func_021B9934(client->side, (u8)c[1]);
        int d = (int)func_021B8DC0(client->main, client->side, (u8)c[0]);
        int e = (int)func_021B8DC0(client->main, client->side, (u8)c[1]);
        func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b);
        func_021EA8B4(client->view, d, e);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA8D4(client->view))
            return 1;
        break;
    }
    return 0;
}








int func_021D2930(BtlClient *client, int *b, u32 *c)
{
    int t;

    switch (*b) {
    case 0:
        if (func_021CD9E0(client) == 0) {
            t = func_021B8D8C(client->main, client->side, (u8)c[0]);
            func_021EA1B8(client->view, (u16)c[2], t, func_021D7AD4(c[1]));
            (*b)++;
            break;
        }
        return 1;
    case 1:
        if (func_021EA1F0(client->view) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D2990(int a, int b, int *c)
{
    func_021F878C(*c);
    return 1;
}







int func_021D299C(BtlClient *client, int *state)
{
    switch (*state) {
    case 0:
        func_021EA8E4(client->view);
        (*state)++;
        break;
    case 1:
        if (func_021EA8F4(client->view) != 0) return 1;
        break;
    }
    return 0;
}







int func_021D29CC(BtlClient *client, int b, u32 *c)
{
    void *m;
    u32 i;
    int k;
    u32 v;

    m = func_021D5844(func_021B9934(client->side, (u8)c[0]));
    for (i = 0; i < 6; i++) {
        if (d_021EFF88[i + 1] != 0) {
            k = d_021EFF88[i];
            v = c[i + 1] + func_02017E1C(m, k, 0);
            if (v > 0xff) {
                v = 0xff;
            }
            func_02017E40(m, k, v);
        }
    }
    return 1;
}






/*
 * evidence: 43/43 relocations resolved after parent-coordinated overlay
 * leaf witnesses; all ARM9 calls resolve without new ARM9 files.
 * lever: int id loaded via (u8) cast fixes spill slots; widening the
 * func_021B8DC0 third extern parameter removes absent call truncation.
 * StateData fields keep counter updates on one global base.
 */
int func_021D2A20(BtlClient *client, int *state, u32 *args)
{
    void *obj;
    int id;
    int index;
    int enabled;
    u32 remaining;
    id = (u8)args[0];
    obj = func_021B9934(client->side, id);
    index = func_021B8DC0(client->main, client->side, id);
    enabled = 0;
    if (index != 0xff && func_021F8204(index)) enabled = 1;
    switch (*state) {
    case 0:
        d_021F3B64.s.remaining = args[1];
        d_021F3B64.s.counter = 0;
        *state = 1;
    case 1:
        if (d_021F3B64.s.remaining) {
            remaining = d_021F3B64.s.remaining;
            if (func_021D69B8(obj, &remaining, (struct Result *)d_021F3B64.s.result)) {
                *state = 3;
            } else {
                if (enabled) {
                    func_021F8134(index, d_021F3B64.s.remaining);
                    *state = 2;
                } else *state = 13;
                remaining = 0;
            }
            d_021F3B64.s.remaining = remaining;
        } else *state = 13;
        break;
    case 2:
        if (!func_021F8180()) *state = 13;
        break;
    case 3:
        func_021D6EA0(obj);
        func_021D6BFC(obj);
        if (enabled) {
            func_021F8150(index, obj);
            *state = 4;
        } else *state = 6;
        break;
    case 4:
        if (!func_021F8180() && !func_02006238()) {
            func_021EA3B8(client->view, index, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA3D4(client->view)) *state = 6;
        break;
    case 6:
        func_021EAF18((struct L *)&client->messageA, 1, 0x3c);
        func_021EAF50((struct L *)&client->messageA, (int)id);
        func_021EAF50((struct L *)&client->messageA, (int)d_021F3B64.s.result[0]);
        func_021EA614(client->view, &client->messageA);
        *state = 7;
        break;
    case 7:
        if (func_021EA720(client->view)) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        }
        if (func_021EA710(client->view) && !func_02005F38()) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            d_021F3B64.s.counter = 0;
            *state = 8;
        }
        break;
    case 8:
        d_021F3B64.s.counter++;
        if ((func_020362DC() & 3) || func_02035C60() || d_021F3B64.s.counter > 80) {
            d_021F3B64.s.counter = 0;
            func_021BA238(client->main, obj);
            func_021EADA4(client->view, (int)obj, d_021F3B64.s.result);
            *state = 9;
        }
        break;
    case 9:
        if (func_021EADB4(client->view) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADC4(client->view);
            *state = 10;
        }
        break;
    case 10:
        if (func_021EADD4(client->view) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADE4(client->view);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EADF4(client->view)) {
            d_021F3B64.s.counter = 0;
            *state = 12;
        }
        break;
    case 12:
        if (func_021D2CA8(client, &d_021F3B64.s.counter, obj)) *state = 1;
        break;
    case 13:
        func_021B9358(client->main, id);
        return 1;
    }
    return 0;
}





int func_021D2C7C(int n)
{
    switch (n) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (GFL_USE_IsSeqPlaying(0x56b) != 0) return 1;
        break;
    }
    return 0;
}






int func_021D2CA8(BtlClient *client, int *state, void *mon)
{
    int idx = func_021D5440(mon);

    switch (*state) {
    case 0:
        g_021F3B64.iter = 0;
        g_021F3B64.move = 0;
        *state = 1;
    case 1:
        g_021F3B64.move = POKE_TOOL_GetLevelUpMove(func_021D5844(mon), &g_021F3B64.iter, client->heapId);
        if (g_021F3B64.move == 0)
            return 1;
        if (g_021F3B64.move == 0xFFFE)
            break;
        if (g_021F3B64.move & 0x8000) {
            g_021F3B64.move &= 0x7FFF;
            *state = 5;
        } else {
            *state = 2;
        }
        break;
    case 2: {
        void *p = func_021B9934(client->side, idx);
        func_021D5844(p);
        func_021D6BFC(p);
        func_021EAF18((struct L *)(&client->messageA), 5, 3);
        func_021EAF50((struct L *)(&client->messageA), idx);
        func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
        func_021EA614(client->view, (&client->messageA));
        *state = 3;
    }
    case 3:
        if (func_021EA720(client->view)) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x515, 0xFFFF);
        }
        if (func_021EA710(client->view))
            *state = 4;
        break;
    case 4:
        if (func_02005F38() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            *state = 1;
        }
        break;
    case 5:
        func_021EAF18((struct L *)(&client->messageA), 5, 4);
        func_021EAF50((struct L *)(&client->messageA), idx);
        func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
        func_021EAF78((u8 *)(&client->messageA), 255);
        func_021EA614(client->view, (&client->messageA));
        *state = 6;
    case 6:
        if (func_021EA720(client->view)) {
            BtlClientMessage yes, no;
            func_021EAF18((struct L *)(&yes), 6, 2);
            func_021EAF18((struct L *)(&no), 6, 3);
            func_021EABC4(client->view, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(client->view))
            *state = 7;
        break;
    case 7: {
        int sel;
        if (func_021EAC54(client->view, &sel)) {
            if (sel == 0) {
                func_021EAC64(client->view, func_021B9CBC((u8 *)func_021B9AF8(client->side, client->clientId), idx), g_021F3B64.move);
                *state = 8;
            } else {
                *state = 10;
            }
        }
        break;
    }
    case 8: {
        u8 slot;
        void *pp;
        u16 old;
        if (func_021EAC80(client->view, &slot) == 0)
            break;
        if (slot == 4) {
            *state = 5;
            break;
        }
        pp = func_021D5844(func_021B9934(client->side, idx));
        old = func_02017E1C(pp, slot + 54, 0);
        func_020181F4(pp, g_021F3B64.move, slot);
        func_021EAF18((struct L *)(&client->messageA), 5, 5);
        func_021EAF50((struct L *)(&client->messageA), idx);
        func_021EAF50((struct L *)(&client->messageA), old);
        func_021EA638(client->view, (&client->messageA), (int)((void (*)(void))func_021D2C7C));
        *state = 9;
        break;
    }
    case 9:
        if (func_021EA710(client->view))
            *state = 2;
        break;
    case 10:
        func_021EAF18((struct L *)(&client->messageA), 5, 7);
        func_021EAF50((struct L *)(&client->messageA), idx);
        func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
        func_021EAF78((u8 *)(&client->messageA), 255);
        func_021EA614(client->view, (&client->messageA));
        *state = 11;
        break;
    case 11:
        if (func_021EA720(client->view)) {
            BtlClientMessage yes, no;
            func_021EAF18((struct L *)(&yes), 6, 4);
            func_021EAF50((struct L *)(&yes), g_021F3B64.move);
            func_021EAF18((struct L *)(&no), 6, 5);
            func_021EAF50((struct L *)(&no), g_021F3B64.move);
            func_021EABC4(client->view, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(client->view))
            *state = 12;
        break;
    case 12: {
        int sel;
        if (func_021EAC54(client->view, &sel)) {
            if (sel == 0) {
                func_021EAF18((struct L *)(&client->messageA), 5, 8);
                func_021EAF50((struct L *)(&client->messageA), idx);
                func_021EAF50((struct L *)(&client->messageA), g_021F3B64.move);
                func_021EA614(client->view, (&client->messageA));
                *state = 13;
            } else {
                *state = 5;
            }
        }
        break;
    }
    case 13:
        if (func_021EA710(client->view))
            *state = 1;
        break;
    }
    return 0;
}





/*
 * lever: const on the read-only descriptor schedules c[1] before the
 * stack-argument store in the first arm.
 */
int func_021D2FD8(BtlClient *client, int *b, const u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7CFC(func_021B8E70(client->main, (u8)c[0]), (u16)c[5], (u8)c[1], c[2], c[4]);
        (*b)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            if (c[2]) {
                u8 *p = func_021B98AC((char *const *)client->side, (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)&client->messageA), 1, 0x41);
                func_021EAF50((struct L *)((u8 *)&client->messageA), func_021D5440(p));
                func_021F883C(0x518);
            } else {
                int msg;
                if (c[1] < 4) msg = d_021EFF80[c[1]];
                else msg = 0x3d;
                func_021EAF18((struct L *)((u8 *)&client->messageA), 1, msg);
            }
            func_021EA614(client->view, ((u8 *)&client->messageA));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view)) {
            if (c[2]) {
                func_021BA2D4((u32)(client->main), (u32 *)func_021B98AC((char *const *)client->side, (u8)c[0]));
                (*b)++;
            } else return 1;
        }
        break;
    case 3:
        if (!func_02005F38()) {
            func_021F7C0C();
            GFL_USE_CancelChangeAndPlayBgm(0x47c, 0xffff);
            func_021B92A0(client->main);
            if (c[3]) {
                u8 *p = func_021B98AC((char *const *)client->side, (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)&client->messageA), 1, 0x42);
                func_021EAF50((struct L *)((u8 *)&client->messageA), func_021D5440(p));
                func_021EA614(client->view, ((u8 *)&client->messageA));
                (*b)++;
            } else return 1;
        }
        break;
    case 4:
        if (func_021EA710(client->view)) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}






int func_021D3138(BtlClient *client, int *b, u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7D44(func_021B8E70(client->main, (u8)c[0]), (u16)c[1]);
        (*b)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EAF18((struct L *)((u8 *)&client->messageA), 1, 0x43);
            func_021EA614(client->view, ((u8 *)&client->messageA));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}






static inline u16 selectValue(u32 u, u32 k)
{
    if (u == 3) {
        return (k != 0) ? 0x26 : 0x27;
    }
    return (k != 0) ? 0x28 : 0x29;
}






/*
 * Levers: the 0x26..0x29 selection is a `static inline u16` helper returning nested
 * ternaries; inlined, its result stays in r0 and each arm branches (the inner join of the
 * u == 3 arm is the unthreaded `b` hop). Written in the caller (ternary, if/else, nested
 * ternary, call in each arm) it is if-converted into r1, and a plain `static` helper is
 * not inlined. `u` is `int` (permuter: u32 put c[1] first into r7 in case 0).
 */
int func_021D31A0(BtlClient *client, int *b, u32 *c)
{
    u8 v;
    int u;
    u8 k;
    char *p;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        v = (u8)c[1];
        p = func_021B9AEC(client->side, u);
        func_021B9C50((u8 **)p, v, 0, 0);
        func_021EAA6C((u32)client->view, u, v);
        (*b)++;
        break;
    case 1:
        if (func_021EAAD8((u32)client->view) != 0) {
            u = (u8)c[1];
            if (u == 1) {
                return 1;
            }
            k = func_021B9F70(client->main, (u8)c[0]);
            func_021EA678(client->view, selectValue(u, k), (int *)c);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710(client->view) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}






int func_021D324C(BtlClient *client, int *b, u32 *c)
{
    u32 u;
    int s;

    u = (u8)c[0];
    s = func_021B8D8C(client->main, client->side, u);
    switch (*b) {
    case 0:
        if (func_021CD9E0(client) != 0) {
            func_021D66D0((struct QJ *)func_021B9934(client->side, u), c[1]);
            return 1;
        }
        func_021EA768(client->view, s, 0);
        (*b)++;
        break;
    case 1:
        if (func_021EA778(client->view, s) != 0) {
            func_021D66D0((struct QJ *)func_021B9934(client->side, u), c[1]);
            func_021EA7A8(client->view, s);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA7B8(client->view, s) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}





/*
 * pass 6 2026-10-06 P6L08: EXACT (364 B), also EXACT under -lang c99. The closing change is u16 x, y
 * with func_021D66D0 declared (void *, u16), non-const a, and source order u, v, x, y. The callee
 * (func_021D66D0.c, strh to a u16 field) also matches EXACT with a u16 parameter, so the prototype is
 * consistent. Why it closes (scheduler trace, scratchpad wD9r/p6_P6L08): the word spill of the narrow
 * variable x uses the unknown-memory alias set (AO1), not a fresh spill alias object. With non-const a,
 * the pointee of a is in that set, so `str x, [sp]` gets a memory edge to the a[1] load and the load
 * waits after it, as in the original. With const a, the pointee of a is not in the set (22 B).
 * Earlier passes (wave75 to pass 6 P6L04) stayed at 13 B with u32 locals.
 */
int func_021D32E0(BtlClient *client, int *b, u32 *c)
{
    u32 u, v;
    u16 x, y;
    int s, t;
    u8 *p, *q;
    u = (u8)c[0];
    v = (u8)c[1];
    x = (u16)c[2];
    y = (u16)c[3];
    s = func_021B8D8C(client->main, client->side, u);
    t = func_021B8D8C(client->main, client->side, v);
    p = func_021B9934(client->side, u);
    q = func_021B9934(client->side, v);
    switch (*b) {
    case 0:
        if (func_021CD9E0(client)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        if (func_021B9A24(u, v)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        func_021EA768((u32 *)(client->view), s, 0);
        d_021F3B64.w[1] = 8;
        (*b)++;
        break;
    case 1:
        func_021EA778(client->view, s);
        if (d_021F3B64.w[1]) d_021F3B64.w[1]--;
        else {
            func_021EA768(client->view, t, 0);
            (*b)++;
        }
        break;
    case 2: {
        u8 r, z;
        r = func_021EA778(client->view, s);
        z = func_021EA778(client->view, t);
        if (r && z) (*b)++;
        break;
    }
    case 3:
        func_021D66D0((struct QJ *)p, x);
        func_021D66D0((struct QJ *)q, y);
        d_021F3B64.w[1] = 0;
        (*b)++;
        break;
    case 4:
        d_021F3B64.w[1]++;
        if (d_021F3B64.w[1] > 8) {
            func_021EA7A8(client->view, s);
            (*b)++;
        }
        break;
    case 5:
        if (func_021EA7B8(client->view, s)) {
            func_021EA7A8(client->view, t);
            (*b)++;
        }
        break;
    case 6:
        if (func_021EA7B8(client->view, t)) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}






int func_021D344C(BtlClient *client, int *b, u32 *c)
{
    u32 u;
    int s;
    u8 *m;
    int f;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        s = func_021B8D8C(client->main, client->side, u);
        m = func_021B9934(client->side, u);
        f = func_021CD9E0(client);
        func_021D6C2C((struct Unk021D6C2C *)m);
        func_021EA868(client->view, s, f);
        (*b)++;
        break;
    case 1:
        if (func_021EA878(client->view) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}





/*
 * extent: compiled 54 bytes followed by two zero alignment bytes.
 */
int func_021D34B0(BtlClient *client, int *state, unsigned int *q)
{
    if (*state == 0) {
        if (func_021CD9E0(client) != 0) return 1;
        func_021F7998(q[0]);
        (*state)++;
    } else {
        if (func_021F7EB4() == 0) return 1;
    }
    return 0;
}






int func_021D34E8(BtlClient *client, int *b, u32 *c)
{
    u8 k;

    k = func_021B8E70(client->main, (u8)c[0]);
    if (*b == 0) {
        if (func_021CD9E0(client) != 0) {
            return 1;
        }
        if (func_021B8590((unsigned char *)client->main) == 0) {
            if (func_0689C9D4((u16)c[1]) != 0) {
                return 1;
            }
        }
        func_021EA3B8(client->view, k, (u16)c[1]);
        (*b)++;
    } else {
        if (func_021EA3D4(client->view) != 0) {
            return 1;
        }
    }
    return 0;
}
