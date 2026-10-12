/*
 * file:     btl_server_p04.c
 * unit:     yes
 * function: func_021CAA58, func_021CACF4, func_021CAFD8, func_021CB174, func_021CB1A4, func_021CB1D4, func_021CB214, func_021CB274, func_021CB2D4, func_021CB55C, func_021CB5F0, func_021CB730, func_021CBA40, func_021CBB34, func_021CBCF4, func_021CBD48, func_021CBEA8, func_021CBF30, func_021CBF40, func_021CBF50, func_021CBF60, func_021CBF70, func_021CBF80, func_021CBF90, func_021CBFA0, func_021CC008, func_021CC098, func_021CC0A8, func_021CC0B8, func_021CC0C8, func_021CC0D8, func_021CC0E8, func_021CC0F8, func_021CC178, func_021CC214, func_021CC2C0, func_021CC350, func_021CC398, func_021CC438, func_021CC4AC, func_021CC508, func_021CC558, func_021CC5F4, func_021CC668, func_021CC768, func_021CC800, func_021CC8A0, func_021CC8B0, func_021CC8B8, func_021CC8C0, func_021CC8C8, func_021CC8D8, func_021CC918, func_021CC95C, func_021CC960, func_021CC96C, func_021CC974, func_021CC99C, func_021CC9A4, func_021CC9AC, func_021CCA74, func_021CCAA8, func_021CCAD4, func_021CCAE0, func_021CCB18, func_021CCB34, func_021CCB78, func_021CCB98, func_021CCBE8, func_021CCC0C, func_021CD0F0, func_021CD4B0, func_021CD4FC, func_021CD568, func_021CD5E0, func_021CD63C, func_021CD644, func_021CD64C, func_021CD6AC, func_021CD6EC, func_021CD6F0, func_021CD8E0, func_021CD914, func_021CD924, func_021CD938, func_021CD95C, func_021CD960, func_021CD978, func_021CD97C, func_021CD984, func_021CD9B0, func_021CD9C8, func_021CD9DC, func_021CD9E0, func_021CD9F4, func_021CDA0C, func_021CDA18, func_021CDC0C, func_021CDD34, func_021CDD50, func_021CDD94, func_021CDDA0, func_021CDDCC, func_021CDDDC, func_021CDE8C, func_021CDECC, func_021CDEE8, func_021CDF1C, func_021CDF58, func_021CDFE4, func_021CE040, func_021CE044, func_021CE068, func_021CE08C, func_021CE0BC, func_021CE0E0, func_021CE0F8, func_021CE150, func_021CE160, func_021CE170, func_021CE1B0, func_021CE2E8, func_021CE308, func_021CE3B4, func_021CE3C8, func_021CE4D0, func_021CE7D4, func_021CE8F0, func_021CEA94, func_021CECB4, func_021CED4C, func_021CEDC0, func_021CEEB8, func_021CEFFC, func_021CF078, func_021CF220, func_021CF2F0, func_021CF360, func_021CF37C, func_021CF3B8, func_021CF3F8, func_021CF41C, func_021CF430, func_021CF448, func_021CF470, func_021CF524, func_021CF58C, func_021CF5B0, func_021CF81C, func_021CF89C, func_021CF8D4, func_021CF918, func_021CF9B4, func_021CFAC4, func_021CFADC, func_021CFB8C, func_021CFBA4, func_021CFBBC, func_021CFBE0, func_021CFBF0, func_021CFD50, func_021CFDCC, func_021CFE08, func_021CFE98, func_021CFFAC, func_021D0100, func_021D0248, func_021D0304, func_021D04E4, func_021D055C, func_021D05C4, func_021D0644, func_021D06C8, func_021D0770, func_021D0980, func_021D09E0, func_021D0B10
 * address:  0x021CAA58
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
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021CAA24 0x021CAA24 thumb ov093
 *   func_021B98A4 0x021B98A4 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021CAC24 0x021CAC24 thumb ov093
 *   func_021CAC34 0x021CAC34 thumb ov093
 *   func_021CAC44 0x021CAC44 thumb ov093
 *   func_021CAC54 0x021CAC54 thumb ov093
 *   func_021CAC64 0x021CAC64 thumb ov093
 *   func_021CAC74 0x021CAC74 thumb ov093
 *   func_021CAC84 0x021CAC84 thumb ov093
 *   func_021CAC94 0x021CAC94 thumb ov093
 *   func_021CACA4 0x021CACA4 thumb ov093
 *   func_021CACB4 0x021CACB4 thumb ov093
 *   func_021CACC4 0x021CACC4 thumb ov093
 *   func_021CACD4 0x021CACD4 thumb ov093
 *   func_021CACE4 0x021CACE4 thumb ov093
 *   func_021B99E0 0x021B99E0 thumb ov093
 *   func_021B8C38 0x021B8C38 thumb ov093
 *   func_021CAF18 0x021CAF18 thumb ov093
 *   func_021CAF28 0x021CAF28 thumb ov093
 *   func_021CAF38 0x021CAF38 thumb ov093
 *   func_021CAF48 0x021CAF48 thumb ov093
 *   func_021CAF58 0x021CAF58 thumb ov093
 *   func_021CAF68 0x021CAF68 thumb ov093
 *   func_021CAF78 0x021CAF78 thumb ov093
 *   func_021CAF88 0x021CAF88 thumb ov093
 *   func_021CAF98 0x021CAF98 thumb ov093
 *   func_021CAFA8 0x021CAFA8 thumb ov093
 *   func_021CAFB8 0x021CAFB8 thumb ov093
 *   func_021CAFC8 0x021CAFC8 thumb ov093
 *   func_021D7F00 0x021D7F00 thumb ov093
 *   func_021CB134 0x021CB134 thumb ov093
 *   func_021CB144 0x021CB144 thumb ov093
 *   func_021CB154 0x021CB154 thumb ov093
 *   func_021CB164 0x021CB164 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_021B8778 0x021B8778 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021B8C50 0x021B8C50 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021B8CB0 0x021B8CB0 thumb ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D7EB4 0x021D7EB4 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D6E04 0x021D6E04 thumb ov093
 *   func_021D6E0C 0x021D6E0C thumb ov093
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_02018480 0x02018480 thumb arm9
 *   func_02017E1C 0x02017E1C thumb arm9
 *   func_02008564 0x02008564 thumb arm9
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_02011168 0x02011168 thumb arm9
 *   _u32_div_f 0x0209C2B0 arm
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C7B4  0x0207C7B4  arm
 *   func_021D6B6C  0x021D6B6C  thumb  ov093
 *   g_021EFDC0      0x021EFDC0  data  ov093
 *   func_021D5444   0x021D5444  thumb ov093
 *   func_021D805C   0x021D805C  thumb ov093
 *   func_02019C90   0x02019C90  thumb arm9
 *   func_02017D30   0x02017D30  thumb arm9
 *   func_02017D70   0x02017D70  thumb arm9
 *   func_02017E40   0x02017E40  thumb arm9
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021CBA30 0x021CBA30 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B9090 0x021B9090 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021C8338 0x021C8338 thumb ov093
 *   func_021BA250 0x021BA250 thumb ov093
 *   data_021EFDE4 0x021EFDE4 data a4
 *   func_021B8724 0x021B8724 thumb ov093
 *   func_021D6E24 0x021D6E24 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_020111BC 0x020111BC thumb
 *   FX_Div 0x0207C768 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021B873C  0x021B873C  thumb  ov093
 *   func_021D5814 0x021D5814 thumb ov093
 *   func_021B8714 0x021B8714 thumb ov093
 *   func_020113F0 0x020113F0 thumb
 *   func_021CBE98 0x021CBE98 thumb ov093
 *   _fflt 0x0209BDBC arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021CBFF8  0x021CBFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C84E0  0x021C84E0  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D5FE4  0x021D5FE4  thumb  ov093
 *   func_021D5F38  0x021D5F38  thumb  ov093
 *   func_021D5450  0x021D5450  thumb  ov093
 *   func_021D5568  0x021D5568  thumb  ov093
 *   func_021D54D0  0x021D54D0  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021CC418  0x021CC418  thumb  ov093
 *   func_021CC428  0x021CC428  thumb  ov093
 *   func_021CC49C  0x021CC49C  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021CC4F8  0x021CC4F8  thumb  ov093
 *   func_021C84AC  0x021C84AC  thumb  ov093
 *   func_021C84D0  0x021C84D0  thumb  ov093
 *   func_021C8910  0x021C8910  thumb  ov093
 *   func_021E869C  0x021E869C  thumb  ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021B8BC4 0x021B8BC4 thumb ov093
 *   func_021BA534 0x021BA534 thumb ov093
 *   func_021CC758 0x021CC758 thumb ov093
 *   d_021EFE9C     0x021EFE9C  data  a4
 *   data_021F3A84 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 *   data_021EFF14  0x021EFF14  data  ov093
 *   data_021F3B44  0x021F3B44  data  ov093
 *   func_02030734 0x02030734 arm
 *   d_021F3A88 0x021F3A88 data a4
 *   func_021EEA58 0x021EEA58 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021BA08C 0x021BA08C thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021D3F04 0x021D3F04 thumb ov093
 *   func_021D3D9C 0x021D3D9C thumb ov093
 *   func_021B9FBC 0x021B9FBC thumb ov093
 *   func_021BA820 0x021BA820 thumb ov093
 *   func_02187F00 0x02187F00 thumb ov096
 *   func_021B90F8 0x021B90F8 thumb ov093
 *   func_021EE5E4 0x021EE5E4 thumb ov093
 *   func_021EE600 0x021EE600 thumb ov093
 *   func_02188080 0x02188080 thumb ov096
 *   func_020307B0 0x020307B0 arm
 *   func_021EEAE0 0x021EEAE0 thumb ov093
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
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006740 0x02006740 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_021BA73C 0x021BA73C thumb ov093
 *   func_02006734 0x02006734 thumb
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   func_02005DF8 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021EAE34 0x021EAE34 thumb ov093
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021BA7F8 0x021BA7F8 thumb ov093
 *   d_021EFFEC 0x021EFFEC data a4
 *   func_021F8524 0x021F8524 thumb ov094
 *   func_021E90A0  0x021E90A0  thumb  ov093
 *   func_021E90D0  0x021E90D0  thumb  ov093
 *   func_021BA5C4  0x021BA5C4  thumb  ov093
 *   func_021BA5D0  0x021BA5D0  thumb  ov093
 *   func_021F84E8  0x021F84E8  thumb  ov094
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021EAEA8  0x021EAEA8  thumb  ov093
 *   func_021EE688  0x021EE688  thumb  ov093
 *   func_021D3F54  0x021D3F54  thumb  ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9920 0x021B9920 thumb ov093
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   func_0203F0A8  0x0203F0A8  arm
 *   _ull_mul       0x0209C054  arm
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 *   func_021EE6B8 0x021EE6B8 thumb ov093
 *   func_021D3FD0 0x021D3FD0 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021B990C  0x021B990C  thumb  ov093
 *   func_021EAE44 0x021EAE44 thumb ov093
 *   func_021EAE54 0x021EAE54 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021E9760 0x021E9760 thumb ov093
 *   func_021E979C 0x021E979C thumb ov093
 *   func_021E97A4 0x021E97A4 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_021BA1EC 0x021BA1EC thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021CE7C4 0x021CE7C4 thumb ov093
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021E9954 0x021E9954 thumb ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021BA004 0x021BA004 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021EA6B0 0x021EA6B0 thumb ov093
 *   func_021D7F38 0x021D7F38 thumb ov093
 *   func_021F87EC 0x021F87EC thumb ov094
 *   func_021F8774 0x021F8774 thumb ov094
 *   func_02005E30 0x02005E30 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_0202A298 0x0202A298 thumb
 *   func_021D7B60 0x021D7B60 thumb ov093
 *   d_021EFF78 0x021EFF78 data ov093 a2
 *   func_021E97BC 0x021E97BC thumb ov093
 *   func_021E9808 0x021E9808 thumb ov093
 *   func_021E98AC 0x021E98AC thumb ov093
 *   func_021E98B4 0x021E98B4 thumb ov093
 *   func_021B9AB0 0x021B9AB0 thumb ov093
 *   func_021D832C 0x021D832C thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D8340 0x021D8340 thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021D7EF0 0x021D7EF0 thumb ov093
 *   func_021E98BC 0x021E98BC thumb ov093
 *   func_021E9920 0x021E9920 thumb ov093
 *   func_021E98E8 0x021E98E8 thumb ov093
 *   func_021E9858 0x021E9858 thumb ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021E9CE0  0x021E9CE0  thumb  ov093
 *   func_021E9B14  0x021E9B14  thumb  ov093
 *   func_021E9B20  0x021E9B20  thumb  ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CEE98 0x021CEE98 thumb ov093
 *   func_021CEEA8 0x021CEEA8 thumb ov093
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
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 *   func_021EA7FC  0x021EA7FC  thumb  ov093
 *   func_021EA814  0x021EA814  thumb  ov093
 *   func_021B90BC 0x021B90BC thumb ov093
 *   func_021D8444  0x021D8444  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D67C4  0x021D67C4  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D5750 0x021D5750 thumb ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D62D8 0x021D62D8 thumb ov093
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021EFC1C 0x021EFC1C thumb ov093
 *   func_021B8D38 0x021B8D38 thumb ov093
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021B937C 0x021B937C thumb ov093
 *   func_021E8AFC 0x021E8AFC thumb ov093
 *   func_021D631C 0x021D631C thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_0201C1C8 0x0201C1C8 thumb
 *   func_021D799C 0x021D799C thumb ov093
 *   func_021D6940 0x021D6940 thumb ov093
 *   d_021EFFC2 0x021EFFC2 data ov093 a2
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D7F2C 0x021D7F2C thumb ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D3DC4 0x021D3DC4 thumb ov093
 *   func_021880BC 0x021880BC thumb ov096
 *   func_02187FB0 0x02187FB0 thumb ov096
 *   func_02188134 0x02188134 thumb ov096
 *   func_02188140 0x02188140 thumb ov096
 *   func_0201C1D8 0x0201C1D8 thumb
 *   func_021D0B3C 0x021D0B3C thumb ov093
 *   func_021D0B4C 0x021D0B4C thumb ov093
 *   func_021D0B5C 0x021D0B5C thumb ov093
 */
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

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct Unk021EFD70;
struct Unk021B8CB0;
struct S2;
struct Q1;
struct QI;
struct Sub0200852CObj;
struct QF;
struct Sav;
struct Unk021D62A8;
struct S_p14;
struct UtilWork;
struct Work;
struct Q2;
struct QE;
struct Qd;
struct Q3;
struct L;
struct H;
struct Unk021D82D0;
struct Unk021D82FC;
struct QG;
struct QV;
struct QL;
struct UtilSlots;
struct G;
struct R4;
struct Rat;
#include "btl_server_types.h"



struct Record { u16 n0, n1; u8 ids[6]; };




typedef struct
{
  u32 value;
  u8 flag;
  u8 pad[7];
} Rec_021CAA58;

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



typedef struct {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
} Bf_td;

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

typedef unsigned long long u64;

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

extern u8 func_021D5440(u8 *);
extern u8 func_021B8D8C(void *, void *, u32);
extern int func_021CAA24(Server *p, u8 *q, int m, int n, int value);
extern u8 *func_021B98A4(char *const *q, int b);
extern u32 func_021D78AC(u32);
extern u8 *func_021B9934(char *p, int i);
extern void func_021CAC24(void *, void *);
extern void func_021CAC34(void *, void *);
extern void func_021CAC44(void *, void *);
extern void func_021CAC54(void *, void *);
extern void func_021CAC64(void *, void *);
extern void func_021CAC74(void *, void *);
extern void func_021CAC84(void *, void *);
extern void func_021CAC94(void *, void *);
extern void func_021CACA4(void *, void *);
extern void func_021CACB4(void *, void *);
extern void func_021CACC4(void *, void *);
extern void func_021CACD4(void *, void *);
extern void func_021CACE4(void *, void *);
extern struct Unk021EFD70 *func_021B99E0(int i);
extern u8 func_021B8C38(u32, u32);
extern void func_021CAF18(void *, void *);
extern void func_021CAF28(void *, void *);
extern void func_021CAF38(void *, void *);
extern void func_021CAF48(void *, void *);
extern void func_021CAF58(void *, void *);
extern void func_021CAF68(void *, void *);
extern void func_021CAF78(void *, void *);
extern void func_021CAF88(void *, void *);
extern void func_021CAF98(void *, void *);
extern void func_021CAFA8(void *, void *);
extern void func_021CAFB8(void *, void *);
extern void func_021CAFC8(void *, void *);
extern u32 func_021D7F00(u32);
extern u32 func_021CB134(void *);
extern void *func_021CB144(void *, int);
extern void func_021CB154(void *, void *);
extern void func_021CB164(void *, void *);
extern int func_021D5B68(void *);
extern int func_021B9A24(u32, u32);
extern int func_0201BEB8(u32, int);
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021B8C50(char **p, u32 v, int k);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern u8 *func_021BB85C(u8 *, unsigned int);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern u8 func_021B8CB0(struct Unk021B8CB0 **p, int x);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u32 func_021D7EB4(void *a);
extern u8 func_021B9B94(struct Q1 *p);
extern void *func_021B86B8(void ***p);
extern void func_02082BCC(void *, int, u32);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u16 func_021D5B40(struct QI *p);
extern unsigned char func_021D6E04(unsigned char *p);
extern u8 func_021D6E0C(u8 *p, u32 i);
extern int func_021B871C(char *p);
extern void *func_021D5844(void *);
extern int func_02018480(void *p, int q);
extern u32 func_02017E1C(void *, u32, u32);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_021D7B10(u32, u32);
extern u32 func_02011168(u32);
extern int func_0207C7B4(int x);
extern u32 func_021D6B6C(u8 *p);
extern u16 func_021D5444(struct QF *p);
extern u32 func_021D805C(void *p, u32 n);
extern u32 func_02019C90(u32 a, u32 b, u32 c);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u8 func_021B8DDC(u32);
extern char *func_021B9AEC(char *, int);
extern int func_021B99B8(void *, u32);
extern u32 func_021CBA30(void *, u32);
extern u32 func_021B8588(void **p);
extern void func_021B9090(u8 *, u32, u32);
extern u8 func_021B8FF4(u8 *);
extern void func_021BA1B4(char **p, int i);
extern int func_021C8338(Server *, int);
extern void func_021BA250(char *, u8 *, int);
extern int func_021B8724(char *p, void *m);
extern void func_021D6E24(void **p, int value);
extern int func_021BA1A8(char **p, int m);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_020111BC(int);
extern int FX_Div(int, int);
extern int FX_Sqrt(int);
extern u32 func_021B873C(char **p);
extern int func_021D5814(void *,int);
extern char *func_021B8714(char **);
extern int func_020113F0(int row, int col);
extern int func_021CBE98(u16);
extern unsigned char func_021B9A40(unsigned int x);
extern Word_021CAA58_td func_021E8940(int v);
extern int func_021CBFF8(int a, int b, Word_021CAA58_td c);
extern void *func_021C88A4(Server *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S_p12;
extern void func_021C8860(struct S_p12 *p, u32 val);
extern void func_021C88C8(Server *a, void *b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C84E0(Server *p, unsigned int v);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern int func_021D5F38(struct S_p14 *p, int n);
extern u8 func_021D5450(struct Work *p);
extern u8 func_021D5568(u8 *p, u32 i);
extern u32 func_021D54D0(u8 *p, u8 i);
extern int func_021D5B48(u8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021CC418(void *p, int id);
extern u32 func_021CC428(int i);
extern int func_021CC49C(void *p, int id);
extern int func_021D5D14(s8 *p, int i, int sign);
extern int func_021CC4F8(u16 v);
extern int func_021C84AC(Server *p, u8 *a, u8 *out);
extern void func_021C84D0(Server *p, u8 *a);
extern int func_021C8910(Server *p);
extern int func_021E869C(void *p, int id);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern u8 func_021B9B98(u8 *p);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern int func_021BA534(void ***p);
extern int func_021CC758(void *);
extern u32 _u32_div_f(u32, u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern char *func_021B9AF8(char *, int);
extern u32 func_021BA08C(struct Q2 *p);
extern void func_021D8230(u8 *);
extern void func_021D3F04(u8 *);
extern void func_021D3D9C(u8 *);
extern int func_021B9FBC(char *, int);
extern u32 func_021BA820(int *);
extern void *func_02187F00(void **, u32, u32, u32, u16);
extern int func_021B90F8(u8 *);
extern void *func_021EE5E4(u32);
extern void func_021EE600(void *);
extern void func_02188080(void *);
extern u32 func_020307B0(void *p);
extern void func_021EEAE0(void *);
extern u16 *func_021EE63C(u16 *, u32 *);
extern u32 func_021EE830(void *);
extern void func_021D3F48(u8 *,u32);
extern void func_021EE674(void *);
extern void func_021EEBDC(void *);
extern void func_021D3F64(u8 *,u16);
extern void func_021D3F88(struct S_p14 *p);
extern void func_021D3FDC(u8 *p, struct Qd *q);
extern u8 func_021EEBE8(void *);
extern int func_021EEC20(int, void *);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int func_021EEC4C(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void func_02005CA4(int,u32);
extern void func_02006740(void);
extern int func_02005E50(void);
extern u16 func_021D3FA8(u8 *p);
extern void func_021BA73C(char *,int);
extern void func_02006734(u8);
extern int func_021D3F98(u8 *);
extern void func_021EAE24(u8 *p);
extern void func_02005DF8(u32 a);
extern void func_021F88BC(int);
extern void *func_021F8678(void);
extern int func_021EAE34(u8 *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern void func_021BA7F8(char *p);
extern int func_021F8524(int);
extern void func_021E90A0(unsigned int *o, unsigned int key);
extern int func_021E90D0(struct S_p14 *s);
extern u16 func_021BA5C4(u8 *p);
extern u16 func_021BA5D0(struct Q3 *p);
extern void func_021F84E8(int a, int b);
extern void func_021F8504(u32 a, u32 b, u32 c);
extern void func_021EAEA8(u8 *p, int v);
extern int func_021EE688(int, int);
extern void func_021D3F54(u8 *p);
extern u8 func_021B86C0(u8 **);
extern u32 func_021B9064(u8 *p, int k, int x);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern void func_021EAA00(u8 *p, u8 v);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern u32 func_0203F0A8(void);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *o, u8 v);
extern u32 *func_021EE6B8(void *,u8,u8 *,u8 *);
extern void func_021D3FD0(unsigned char *p);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern void func_021D8434(u32 *p);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern void func_021EAE44(void *);
extern int func_021EAE54(void *);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_021D81F8(void *,void *,void *,u32,void *);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern void func_021EA65C(char *p, struct H *h);
extern void func_021E9760(char *, u8 *, int, int);
extern void func_021E979C(char *p);
extern int func_021E97A4(char *p);
extern void func_021E9964(u32);
extern int func_021BA1EC(char **p);
extern int func_021B86E4(unsigned int **p);
extern u32 func_021D8454(u32 *);
extern void func_021CE7C4(u8 *);
extern int func_021E9974(u32);
extern void func_021E9954(void *);
extern u8 func_021B904C(u8 *p, int k);
extern u16 func_021BA004(char *p, int i);
extern unsigned short func_021BA020(char *p, int i);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern int func_021EA6B0(char *, u16, u16);
extern int func_021D7F38(u32 n);
extern void func_021F87EC(u32);
extern int func_021F8774(void);
extern void func_02005E30(u32);
extern void func_02005D90(u16, u16);
extern int func_021F7EB4(void);
extern u32 func_0202A298(u32,u32,u32);
extern u32 func_021D7B60(void *p, u32 b);
extern void func_021E97BC(char *p, u8 *a, int b);
extern void func_021E9808(char *p, u32 *q, int c);
extern void func_021E98AC(void *);
extern u32 func_021E98B4(void *);
extern int func_021B9AB0(int);
extern u32 func_021D832C(struct Unk021D82FC *p);
extern u8 func_021D5778(void *q, u32 id);
extern u32 func_021D8340(u32 *);
extern void func_021D83FC(u32 *p, u32 sub);
extern u32 func_021D7EF0(u32);
extern void func_021E98BC(char *p, u8 *a, int b);
extern void func_021E9920(void *);
extern int func_021E98E8(char *p);
extern void func_021E9858(char *p);
extern u8 func_021D5448(struct QG *p);
extern u32 func_021D5584(struct UtilWork *p, u32 i);
extern void func_021E9CE0(u8 *p, u8 a, u8 b);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021E9A78(char *, const u8 *, int, int, u8 *);
extern u32 func_021CEE98(u8 *);
extern u32 func_021CEEA8(u8 *);
extern void func_021D8394(void *, u8, u32);
extern void func_021E9D04(void *, int, int, int, u32, u32);
extern void func_021E9E70(u8 *p);
extern int func_021E9E80(u8 *p);
extern u16 func_021EA01C(u8 *p);
extern u8 func_021EA044(struct QV *p);
extern u8 func_021EA030(u8 *p);
extern u8 func_021EA04C(u8 *p);
extern void func_021D8358(u32 *p, u32 id, u32 sub, u32 val);
extern void func_021EA058(char *p);
extern unsigned int func_021B8670(unsigned int **p);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021EA720(u32 *p);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *, int *);
extern void func_021D8414(u32 *p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
extern void func_021B90BC(u8 *p, u8 k, u32 v);
extern void func_021D8444(u32 *p);
extern union Slot func_021D6314(void *q, int i);
extern u16 func_021E8B80(union Slot v);
extern u8 func_021D67C4(u8 *p);
extern u16 func_021D67A8(struct QL *p);
extern int func_021D5750(void *, u32);
extern u32 func_0201C314(void *p);
extern u16 func_021D67B8(u8 *p);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void *func_021EFCE4(char *arg0, int arg1);
extern int func_021EFC1C(int, int, void *, u32);
extern u8 func_021B8D38(void *p, int a, int k, u8 *out);
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(void *, char *, u8 *);
extern u8 func_021E8AFC(union Slot);
extern u8 func_021D631C(u8 *p, int i);
extern u16 func_021D57FC(void *);
extern u8 func_0201C1C8(void *p);
extern int func_021D799C(int, u16);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021D5C44(struct Rat *p);
extern u8 func_021D7F2C(u32 a, u8 b);
extern int func_021D5B7C(void *m);
extern u32 func_021D3DC4(u8 *, void *, void *);
extern void func_021880BC(int, u8 *, int);
extern int func_02187FB0(u8 *);
extern u8 func_02188134(u8 *);
extern u8 func_02188140(u8 *);
extern u16 func_0201C1D8(void *);
extern void func_021D0B3C(void *, u32, u32, u32);
extern void func_021D0B4C(void *, u32);
extern void func_021D0B5C(void *, void *);
int func_021CAA58(Server *p, u8 *a, u16 move, u8 *q, int id, void *out);
int func_021CACF4(Server *p, u8 *a, u16 move, u8 *q, long id, void *out);
int func_021CAFD8(Server *p, u32 mode, void *m, const u16 *item, u8 self, void *out);
void *func_021CB174(Server *p, unsigned int n, int k);
void *func_021CB1A4(Server *p, int n);
u8 func_021CB1D4(Server *p, u8 *a, u8 *b, u32 d);
u8 func_021CB214(Server *p, u8 *a, u8 *b);
u8 func_021CB274(Server *p, u8 *a, u8 *b, u32 d);
void func_021CB2D4(Server *p, u8 *a, u32 b, Rec_021CAA58 *rec);
u32 func_021CB55C(void *p, u32 a, u16 b, u16 c);
void func_021CB5F0(u32 *a0, u8 *a1, u8 *a2);
int func_021CB730(Server *p, u8 *a, u16 move, u8 arg, u8 slot);
int func_021CBA40(Server *p, void *a, u16 b);
int func_021CBB34(Server *p, void *q, void *m, u16 mode, u8 *out, u8 *flag);
u32 func_021CBCF4(Server *p);
int func_021CBD48(Server *p, void *unused, void *q, int k);
int func_021CBEA8(Server *p, int x);
void func_021CBF30(Server *a, void *b, int c, int d);
void func_021CBF40(Server *a, void *b, int c, int d);
void func_021CBF50(Server *a, void *b, int c, int d);
void func_021CBF60(Server *a, void *b, int c, int d);
void func_021CBF70(Server *a, void *b, int c, int d);
void func_021CBF80(Server *a, void *b, int c, int d);
void func_021CBF90(Server *a, void *b, int c, int d);
int func_021CBFA0(Server *p, u8 *q);
int func_021CC008(Server *p, u8 *q, u16 s);
void func_021CC098(Server *a, void *b, int c, u8 d);
void func_021CC0A8(Server *a, void *b, int c, u8 d);
void func_021CC0B8(Server *a, void *b, int c, u8 d);
void func_021CC0C8(Server *a, void *b, int c, u8 d);
void func_021CC0D8(Server *a, void *b, int c, u8 d);
void func_021CC0E8(Server *a, void *b, int c, u8 d);
int func_021CC0F8(char *p, void *m, int c, int n);
int func_021CC178(Server *a, void *m, void *s, int d, u8 n);
int func_021CC214(Server *a, void *m, void *s);
int func_021CC2C0(Server *a, void *m, void *s);
int func_021CC350(Server *a, void *m, int c, int d, u32 v);
int func_021CC398(Server *p, void *m, int c, int d, u32 v);
int func_021CC438(Server *p, void *m, int c, u8 d, u32 e);
u8 func_021CC4AC(Server *a, void *m);
int func_021CC508(Server *p, void *m);
int func_021CC558(Server *p, void *m);
int func_021CC5F4(Server *p, void *m);
int func_021CC668(u8 *p);
int func_021CC768(void *a, u8 *p, u8 *q, int want);
void func_021CC800(u8 *a, u32 *out1, u32 *out2, u8 want);
void func_021CC8A0(u32 *p);
void func_021CC8B0(u32 *p, u32 i, u32 b);
u32 func_021CC8B8(u32 *p, u32 i);
u32 func_021CC8C0(u32 *p, u32 i);
void func_021CC8C8(u32 *p);
u32 func_021CC8D8(void *lock, int line);
u32 func_021CC918(Bf_td *p, u32 v);
void func_021CC95C(u32 *p, u32 v, int line);
unsigned short func_021CC960(struct S_p14 *p);
int func_021CC96C(struct Q9 *p);
void func_021CC974(Word_021CC768 *p,int flag);
int func_021CC99C(struct Q10 *p);
u32 func_021CC9A4(u32 *p);
struct Rec_p14 *func_021CC9AC(struct Pack *p, int id, int b);
void func_021CCA74(QueueA *p,QueueB *q);
void func_021CCAA8(Buf_021CC768 *p,u8 v);
u8 func_021CCAD4(u8 *p);
void func_021CCAE0(Buf_021CC768 *p,u16 v);
u32 func_021CCB18(Buf_021CC768 *p);
void func_021CCB34(Buf_021CC768 *w, u32 v);
u32 func_021CCB78(ByteStream *s);
void func_021CCB98(Buf_021CC768 *w, u32 v);
u32 func_021CCBE8(Buf_021CC768 *p);
void func_021CCC0C(void *w, u32 id, int cmd, s32 *a);
void func_021CD0F0(void *r, int cmd, s32 *a);
void func_021CD4B0(void *w, volatile u32 id, ...);
u16 func_021CD4FC(Buf_021CC768 *w, u32 id);
void func_021CD568(Buf_021CC768 *w, u16 x, u32 id, ...);
int func_021CD5E0(Buf_021CC768 *r, s32 *a);
void func_021CD63C(void *p, u8 v);
u8 func_021CD644(u8 *p);
void func_021CD64C(void *w, u8 id, ...);
void func_021CD6AC(void *r, u8 cmd, s32 *out);
void func_021CD6EC(void);
u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
void func_021CD8E0(u8 *p);
void func_021CD914(u8 *p);
u16 *func_021CD924(u8 *p, u32 *out);
void func_021CD938(u8 *p,void *a);
void func_021CD95C(struct QA *p, u32 v);
void func_021CD960(u8 *p, u32 v);
u32 func_021CD978(struct QB *p);
void func_021CD97C(struct R2 *p);
void func_021CD984(u8 *p,u16 n);
void func_021CD9B0(u8 *p);
u32 func_021CD9C8(u8 *p);
u16 func_021CD9DC(struct QD *p);
u32 func_021CD9E0(u8 *p);
void func_021CD9F4(u8 *p,u8 n);
void func_021CDA0C(struct QE *p, u32 v);
int func_021CDA18(u8 *p);
int func_021CDC0C(u8 *p);
void func_021CDD34(u8 *p);
Callback_021CC768 func_021CDD50(u8 *p,u32 id,int *out);
void func_021CDD94(char *p, int *o);
int func_021CDDA0(u8 *p);
u32 func_021CDDCC(struct Flags_021CDDCC *p);
int func_021CDDDC(u8 *p, int *st);
int func_021CDE8C(int a, int b);
void func_021CDECC(u8 *p);
u32 func_021CDEE8(u8 *p);
void *func_021CDF1C(u8 *p);
int func_021CDF58(u8 *p, int *st);
u32 func_021CDFE4(u32 mode);
int func_021CE040(void);
void func_021CE044(u8 *p);
void func_021CE068(u8 *p);
int func_021CE08C(u8 *p);
int func_021CE0BC(u8 *p,void *q);
void func_021CE0E0(u8 *p);
void func_021CE0F8(u8 *p, u8 *q, u8 *o);
void func_021CE150(u8 *p, void *q);
u32 func_021CE160(u8 *p);
u32 func_021CE170(u8 *p, s32 *st);
int func_021CE1B0(u8 *p,int *state);
void func_021CE2E8(u8 *p);
u32 func_021CE308(u8 *p);
void func_021CE3B4(u8 *p, void *q);
int func_021CE3C8(u8 *p,int *state);
int func_021CE4D0(u8 *p, u32 *st);
u32 func_021CE7D4(u8 *p, int *st);
u32 func_021CE8F0(const u8 *p, u16 *out);
int func_021CEA94(u8 *p, u32 *state);
void func_021CECB4(u8 *p, Ent_021CECB4 *out);
u32 func_021CED4C(u8 *p, s32 *st);
u32 func_021CEDC0(u8 *p, int *st);
u32 func_021CEEB8(u8 *p, int *st);
u32 func_021CEFFC(u8 *p);
u32 func_021CF078(u8 *p, u32 *st);
u32 func_021CF220(u8 *p, int *st);
u32 func_021CF2F0(u8 *p, s32 *st);
void func_021CF360(u8 *p);
void func_021CF37C(u8 *p,u32 i,u32 v);
void func_021CF3B8(u8 *p, u32 i);
void func_021CF3F8(u8 *p);
void func_021CF41C(u8 *p);
void func_021CF430(u8 *p, u32 i, u32 v);
u8 func_021CF43C(u8 *p, u32 i);
u8 func_021CF448(u8 *p);
u32 func_021CF470(u8 *p, void *q, u8 *o);
u32 func_021CF524(u32 x, void *q, u32 y);
void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
u32 func_021CF81C(u8 *p, void *q, u8 *out);
int func_021CF89C(u8 *p, void *q);
u32 func_021CF8D4(u8 *p, void *q, u8 *a, u16 *b);
u32 func_021CF918(u8 *g, u8 *a, u16 *b);
u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b);
int func_021CFAC4(void *p, void *q);
int func_021CFADC(u8 *g, void *m);
int func_021CFB8C(void *p, void *q);
void func_021CFBA4(s8 *p);
int func_021CFBBC(s8 *p, int v);
void func_021CFBE0(u8 *p, u32 i, u32 v);
int func_021CFBF0(u8 *g, void *m, u32 slot, u8 *out);
u8 *func_021CFD50(struct G_021CFD50 *g, int k);
int func_021CFDCC(void *p, void *q);
int func_021CFE08(struct G_021CFE08 *g, void *a, void *b);
int func_021CFE98(struct G_021CFE98 *g, void *a, void *b);
int func_021CFFAC(struct G_021CFFAC *g, void *mon, void *target);
int func_021D0100(struct G_021D0100 *g, void *mon, void *target, u8 *out);
int func_021D0248(struct G_021D0248 *g, void *m, u8 *out);
int func_021D0304(struct G_021D0304 *g, void *mon, void *target, u8 *out);
int func_021D04E4(u8 *g, u16 a, u8 *out);
int func_021D055C(u8 *g, void *a, int b);
int func_021D05C4(u8 *g, u8 a, int b, u8 *out);
int func_021D0644(void *g, void *m, void *a, int b);
u8 func_021D06C8(struct G *g);
int func_021D0770(u8 *p, u32 *state);
u8 func_021D0980(u8 *g, u8 *out);
void func_021D09E0(u8 *p, u8 *order, u8 count, void *target);
void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
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






int func_021CAA58(Server *p, u8 *a, u16 move, u8 *q, int id, void *out)
{
    int n = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
    int key = func_021CAA24(p, q, (int)a, n, move);
    u8 *b;
    u8 selected;
    switch (*(u32 *)(q + 12)) {
    case 0:
        b = func_021B98A4(p->f8, key);
        break;
    case 3:
        b = func_021B98A4(p->f8, key);
        break;
    case 9:
        b = func_021CB174(p, (int)n, (u8)func_021D78AC(2));
        break;
    case 5:
        func_021CAC24(out, func_021CB174(p, (int)n, (u8)0));
        func_021CAC34(out, func_021CB174(p, (int)n, (u8)1));
        return 2;
    case 4:
        func_021CAC44(out, func_021CB1A4(p, n));
        func_021CAC54(out, func_021CB174(p, (int)n, (u8)0));
        func_021CAC64(out, func_021CB174(p, (int)n, (u8)1));
        return 3;
    case 8:
        func_021CAC74(out, a);
        func_021CAC84(out, func_021CB1A4(p, n));
        func_021CAC94(out, func_021CB174(p, (int)n, (u8)0));
        func_021CACA4(out, func_021CB174(p, (int)n, (u8)1));
        return 3;
    case 7:
        if (id == 31) func_021CACB4(out, a);
        else func_021CACB4(out, (void *)func_021B9934((char *)p->f8, id));
        return 1;
    case 1:
        func_021CACC4(out, func_021B98A4(p->f8, key));
        return 1;
    case 2:
        func_021CACD4(out, func_021CB1A4(p, n));
        return 1;
    case 13:
        if (id != 31) {
            b = (u8 *)func_021B9934((char *)p->f8, id);
            break;
        }
        return 0;
    case 6: case 10: case 11: case 12: default:
        return 0;
    }
    if (b) {
        selected = func_021CB1D4(p, a, q, func_021D5440(b));
        if (selected != 31) b = (u8 *)func_021B9934((char *)p->f8, selected);
        func_021CACE4(out, b);
        return 1;
    }
    return 0;
}








int func_021CACF4(Server *p, u8 *a, u16 move, u8 *q, long id, void *out)
{
    u32 i, count;
    u32 n = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
    u8 *b = (u8 *)func_021B99E0(n);
    int key = func_021CAA24(p, q, (int)a, n, move);
    u8 selected;
    switch (*(u32 *)(q + 12)) {
    case 0:
        b = func_021B98A4(p->f8, key);
        break;
    case 3:
        b = func_021B98A4(p->f8, key);
        break;
    case 9:
        selected = func_021D78AC(*(u16 *)b);
        b = func_021B98A4(p->f8, ((struct Record *)b)->ids[selected]);
        break;
    case 5:
        for (i = 0; i < *(u16 *)b; i++)
            func_021CAF18(out, func_021B98A4(p->f8, b[4 + i]));
        return (u8)*(u16 *)b;
    case 4: {
        long j;
        i = 0;
        count = 0;
        for (; i < *(u16 *)b; i++) {
            func_021CAF28(out, func_021B98A4(p->f8, b[4 + i]));
            count++;
        }
        for (j = 0; (u32)j < *(u16 *)(b + 2); j++) {
            if (n != b[7 + j]) {
                func_021CAF38(out, func_021B98A4(p->f8, b[7 + j]));
                count++;
            }
        }
        return (u8)count;
    }
    case 8:
        func_021CAF48(out, a);
        for (i = 0; i < 3; i++) {
            selected = func_021B8C38(n, (u8)i);
            if (selected != n) func_021CAF58(out, func_021B98A4(p->f8, selected));
        }
        func_021CAF68(out, func_021CB174(p, n, 0));
        func_021CAF78(out, func_021CB174(p, n, 1));
        func_021CAF88(out, func_021CB174(p, n, 2));
        return 6;
    case 7:
        if (id == 31) func_021CAF98(out, a);
        else func_021CAF98(out, (void *)func_021B9934((char *)p->f8, id));
        return 1;
    case 1:
        func_021CAFA8(out, func_021B98A4(p->f8, key));
        return 1;
    case 2:
        func_021CAFB8(out, func_021B98A4(p->f8, key));
        return 1;
    case 13:
        if (id != 31) {
            b = (u8 *)func_021B9934((char *)p->f8, id);
            break;
        }
        return 0;
    case 6: case 10: case 11: case 12: default:
        return 0;
    }
    if (b) {
        selected = func_021CB1D4(p, a, q, func_021D5440(b));
        if (selected != 31) b = (u8 *)func_021B9934((char *)p->f8, selected);
        func_021CAFC8(out, b);
        return 1;
    }
    return 0;
}








int func_021CAFD8(Server *p, u32 mode, void *m, const u16 *item, u8 self, void *out)
{
    int count;
    u8 j;
    void *previous;
    int position;
    u16 target;
    u8 indices[6];
    int members[3];
    int d1;
    u8 i;
    u8 choice;
    int d0;
    u32 n;
    if (func_021D7F00(mode) <= 1 || func_021CB134(out) != 1) goto fail;
    previous = func_021CB144(out, 0);
    if (!func_021D5B68(previous)) goto fail;
    if (func_021B9A24(func_021D5440(m), func_021D5440(previous))) goto fail;
    position = func_021B8D8C(p->f4, p->f8, func_021D5440(m));
    func_021CB154(out, previous);
    if (func_0201BEB8(*item, 0xb)) target = 0x600 | position;
    else target = 0x100 | position;
    n = func_021B8778(p->f4, target, indices);
    for (j = 0; j < 3; j++) members[j] = 0;
    count = 0;
    for (i = count; i < n; i++) {
        members[count] = (int)func_021B98A4(p->f8, indices[i]);
        if (!func_021D5B68((void *)members[count])) {
            indices[count] = indices[i];
            count = (u8)(count + 1);
        }
    }
    if (!count) return 0;
    if (count != 2) choice = 0;
    else {
        d0 = indices[0] - self;
        if (d0 < 0) d0 *= -1;
        d1 = indices[1] - self;
        if (d1 < 0) d1 *= -1;
        if (d0 == d1) {
            d0 = func_021D59B4((void *)members[0], 13);
            d1 = func_021D59B4((void *)members[1], 13);
        }
        if (d0 < d1) choice = 0;
        else if (d1 < d0) choice = 1;
        else choice = func_021D78AC(2);
    }
    if (members[choice]) { func_021CB164(out, (void *)members[choice]); return 1; }
fail:
    return 0;
}









/*
 * interface: func_021B8C50 forwards live r1/r2 to func_021B8C20 and returns r0.
 */
void *func_021CB174(Server *p, unsigned int n, int k)
{
    u8 out[2];
    func_021B8E28((u8 *)p->f4, func_021B8C50(p->f4, n, k), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(func_021BB85C(p->f0, out[1]) + 4), out[0]);
}









void *func_021CB1A4(Server *p, int n)
{
    u8 out[2];
    func_021B8E28((u8 *)p->f4, func_021B8CB0(p->f4, n), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(func_021BB85C(p->f0, out[1]) + 4), out[0]);
}










u8 func_021CB1D4(Server *p, u8 *a, u8 *b, u32 d)
{
    u32 s = func_021CC8D8(&p->lock, 611);
    u8 r = func_021CB274(p, a, b, d);
    func_021CC95C((u32 *)&p->lock, s, 613);
    return r;
}










u8 func_021CB214(Server *p, u8 *a, u8 *b)
{
    u8 r;
    func_021D74F8(631);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x12, ((struct Obj13345 *)b)->f0);
    func_021D7630(4, 0x1f);
    func_021D7630(0x50, 0);
    func_021D70F0(p, 0x29);
    r = func_021D775C(4);
    func_021D7540(639);
    return r;
}










u8 func_021CB274(Server *p, u8 *a, u8 *b, u32 d)
{
    u8 r;
    func_021D74F8(656);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x12, ((struct Obj13346 *)b)->f0);
    func_021D7630(4, d);
    func_021D70F0(p, 0x2a);
    r = func_021D775C(4);
    func_021D7540(663);
    if (r == d) r = 0x1f;
    return r;
}









/*
 * note: final push 2026-10-05 G1R6: closed. The loop count n is a u16 local and
 *   func_021B9B94 is declared u8 (its matched definition returns u8). A narrow bound with
 *   narrow counters gives unsigned compares and keeps the loop-3 counter store before the
 *   bound reload. Earlier drafts kept n u32 (4 B off) or u8 (signed compares, 35 B off).
 *   Same shape as ov021 func_021922A4 (u16 bound, u16 counter). A separate u16 counter i3
 *   for loop 3 gives the spill slots of the counter and of id.
 */
void func_021CB2D4(Server *p, u8 *a, u32 b, Rec_021CAA58 *rec)
{
  u32 scale;
  u16 n;
  u32 share;
  u16 lvl;
  u16 lvl2;
  u32 k;
  u16 i;
  u8 id;
  u16 i3;
  u32 half;
  u16 cnt;
  u32 avg;
  int n2;
  u32 n3;
  u8 cnt2;
  u16 j;
  u16 m;
  u8 q;
  u8 *t;

  scale = func_021D7EB4((void *)b);
  n = func_021B9B94((struct Q1 *)a);
  cnt = 0;
  if (func_021B86B8(p->f4) == (void *) 1)
    scale = scale * 15 / 10;
  for (i = 0, j = 0; i < 6; i++)
    func_02082BCC(rec + i, j, 12);
  for (j = 0; j < n; j++)
  {
    t = func_021B9C00((struct S2 *)a, (u8) j);
    if (func_021D5B68(t) == 0 && (u32)func_021D5B40((struct QI *)t) == 0xd8)
      cnt++;
  }
  if (cnt)
  {
    half = scale >> 1;
    scale = scale - half;
    avg = half / cnt;
    if (avg == 0)
      avg = 1;
    for (j = 0; j < n; j++)
    {
      t = func_021B9C00((struct S2 *)a, (u8) j);
      if (func_021D5B68(t) == 0 && (u32)func_021D5B40((struct QI *)t) == 0xd8)
        rec[j].value = avg;
    }
  }
  n2 = (int)func_021D6E04((unsigned char *)b);
  cnt2 = 0;
  for (j = 0; j < n2; j++)
  {
    if (func_021D5B68(func_021B9934(p->f8, (u32)func_021D6E0C((u8 *)b, (u8) j))) == 0)
      cnt2++;
  }
  share = scale / cnt2;
  if (share == 0)
    share = 1;
  for (i3 = 0; i3 < n; i3++)
  {
    t = func_021B9C00((struct S2 *)a, (u8) i3);
    if (func_021D5B68(t) == 0)
    {
      id = func_021D5440(t);
      n3 = n2;
      for (q = 0; q < n3; q++)
      {
        if (id == (u32)func_021D6E0C((u8 *)b, q))
          rec[i3].value += share;
      }
    }
  }
  for (j = 0; j < n; j++)
  {
    if (rec[j].value != 0)
    {
      void *save;
      void *v28;
      u32 v24;

      v24 = (u32)func_021B871C(p->f4);
      t = func_021B9C00((struct S2 *)a, (u8) j);
      v28 = func_021D5844(t);
      lvl = func_021D59B4(t, 15);
      lvl2 = func_021D59B4((void *) b, 15);
      rec[j].value = func_021CB55C(t, rec[j].value, lvl, lvl2);
      if (func_02018480(v28, (u32)v24) == 0)
      {
        save = (void *) func_02017E1C(v28, 12, 0);
        if ((u32) save != func_02008564((const struct Sub0200852CObj *)v24))
          k = 0x1b33;
        else
          k = 0x1800;
        rec[j].value = func_021D7B10(rec[j].value, k);
        rec[j].flag = 1;
      }
      if ((u32)func_021D5B40((struct QI *)t) == 0xe7)
      {
        rec[j].value = func_021D7B10(rec[j].value, 0x1800);
        rec[j].flag = 1;
      }
      rec[j].value = func_02011168(rec[j].value);
    }
  }
  for (m = 0; m < n; m++)
  {
    if (rec[m].value != 0)
      func_021CB5F0((u32 *)func_021B9BF0((struct S2 *)a, (u8) m), (u8 *)b, (u8 *)(rec + m));
  }
}









/*
 * note: the second block squares y in place (y *= y) and then multiplies the
 *   root by y: the product lands in the root copy register as in the original.
 *   Found in final push 2026-10-05 G1R4 after the Product helper and every
 *   named-yy form kept the product in the squared register.
 */
u32 func_021CB55C(void *p, u32 a, u16 b, u16 c)
{
  int tmp;
  u32 tmp1;
  u32 r, lim;
  u32 x = (2 * c) + 10;
  u32 y = (c + b) + 10;
  u32 t1 = ((u32) (func_0207C7B4((int) ((x > 0) ? ((x * (1 << 12)) + 0.5f) : ((x * (1 << 12)) - 0.5f))) * (x * x))) >> 12;
  tmp = (int) ((y > 0) ? ((y * (1 << 12)) + 0.5f) : ((y * (1 << 12)) - 0.5f));
  tmp1 = func_0207C7B4(tmp);
  y *= y;
  r = ((a * t1) / ((y * tmp1) >> 12)) + 1;
  lim = func_021D6B6C(p);
  if (r > lim)
    r = lim;
  return r;
}










/*
 * Builds the six per-party "battle handicap" bytes and writes them to the
 * output record.  Reads the record's u16 fields 0xc and 0x13, asks the
 * battle dispatcher func_02019C90 for a base value per entry of the six
 * entry table at 0x021EFDC0 (6-byte records: u8 at +0, u16 at +2, u16 at
 * +4), doubles them when the mode field 0x12 is 0xd7, then walks the table
 * again to add func_021D805C's value for the entry whose +4 field matches
 * and to fold each result into the savedata record 0x97 through the
 * func_02017E1C/func_02017E40 read/write pair, clamped at 0xff.  The final
 * switch on the loop index is the image's, not a source choice: the table
 * at 0x021CB6F4 is six four-byte arms, case i storing the byte at
 * a2[5 + i].  Ends by releasing the savedata record.
 */
void func_021CB5F0(u32 *a0, u8 *a1, u8 *a2)
{
    u8 buf[6];
    u8 i;
    u16 v6;
    u32 m;
    u32 t;
    void *rec;
    u32 sv;

    m = func_021D5444((struct QF *)a1);
    v6 = (u16)func_021D59B4(a1, 0x13);
    for (i = 0; i < 6; i++) {
        buf[i] = (u8)func_02019C90(m, v6, g_021EFDC0[i].f0);
    }
    if (func_021D5B40((struct QI *)a0) == 0xd7) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        t = g_021EFDC0[i].f4;
        if (t == func_021D5B40((struct QI *)a0)) {
            buf[i] = (u8)(buf[i] + (u8)func_021D805C((void *)t, 2));
        }
    }
    rec = func_021D5844(a0);
    sv = func_02017D30(rec);
    if (func_02017E1C(rec, 0x97, 0) != 0) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        u8 v;
        u32 w;

        v = buf[i];
        if (v == 0) {
            continue;
        }
        t = g_021EFDC0[i].f2;
        w = func_02017E1C(rec, t, 0) + v;
        if (w > 0xff) {
            w = 0xff;
        }
        func_02017E40(rec, t, w);
        switch (i) {
        case 0: a2[5] = v; break;
        case 1: a2[6] = v; break;
        case 2: a2[7] = v; break;
        case 3: a2[8] = v; break;
        case 4: a2[9] = v; break;
        case 5: a2[0xa] = v; break;
        }
    }
    func_02017D70(rec, sv);
}









/*
 * lever: the local holding the u8 result of func_021B8DDC is a u8 (not int);
 *   its spill reload then stays below the outgoing stack-argument stores
 *   (ov093 021CD64C call at +0xDA) and the stack parameter load moves ahead
 *   of the p copy at entry. Both residues closed by this one type change.
 *   See docs/idioms/a-narrow-spilled-parameter-keeps-its-reload-below-a-store.md.
 * note: 2026-10-05 wave P2 lane Q8. Dropped the (void)(&pos) no-op from the
 *   older draft (it changed nothing).
 */
int func_021CB730(Server *p, u8 *a, u16 move, u8 arg, u8 slot)
{
  u32 n;
  char *party;
  u8 side;
  u32 monId;
  Condition initial;
  u8 condition;
  u8 *mon;
  unsigned long lock;
  u32 result;
  unsigned long state;
  u32 mark;
  u16 pos;
  u32 allowed;
  u32 i;
  const Entry_021CAA58 *e;
  u8 *tmp;
  u8 *tmp1;
  side = func_021B8DDC(func_021D5440(a));
  mon = 0;
  initial = 0;
  if (slot != 6)
  {
    party = func_021B9AEC(*((char **) &p->f8), side);
    n = func_021B99B8(*((void **) &p->f4), side);
    mon = (u8 *)func_021B9BF0((struct S2 *)party, slot);
    monId = func_021D5440(mon);
    state = func_021CBA30(p->w1ab8, monId);
    if (slot >= n)
      initial = 2;
    condition = (u8) initial;
    if (((func_021B8588(*((void **) &p->f4)) == 3) && (condition == 2)) && (slot < 3))
      condition = 1;
  }
  if ((*((u32 *) &p->f18)) != 1)
  {
    func_021CD64C(*((void **) &p->fC), 0x5a, 0x21, side, move, 0xffff0000);
    if (func_021D805C((void *)move, 15) == 4)
    {
      if (func_021CBA40(p, a, move))
        func_021B9090(*((u8 **) &p->f4), side, move);
      return 0;
    }
    if (func_021D805C((void *)move, 7) == 3)
    {
      func_021B9090(*((u8 **) &p->f4), side, move);
      return 1;
    }
  }
  else
  {
    func_021CD64C(*((void **) &p->fC), 0x5a, 0x24, side, monId, move, 0xffff0000);
    if (side == func_021B8FF4(*((u8 **) &p->f4)))
      func_021BA1B4(*((void **) &p->f4), 0x6f);
  }
  allowed = ((condition == 0) && (state != 6)) ? (1) : (0);
  if (!allowed)
  {
    for (i = 0; i < 23; i++)
    {
      e = data_021EFDE4;
      e = e + i;
      if ((e->exact && (move == e->id)) || ((!e->exact) && func_021D805C((void *)move, e->id)))
      {
        if (e->mode == 0)
        {
          allowed = 1;
          break;
        }
        if (((e->mode == 1) && (condition < 2)) && (state != 6))
        {
          allowed = 1;
          break;
        }
      }
    }

  }
  if (!allowed)
  {
    func_021CD64C(*((void **) &p->fC), 0x5a, 0xc4, 0xffff0000);
    return 0;
  }
  if ((*((u32 *) &p->f18)) == 1)
  {
    if (state != 6)
      func_021CD4B0(*((void **) &p->fC), 0x4d, state, 0x282);
    for (i = 0; i < 23; i++)
    {
      if (data_021EFDE4[i].exact && (move == data_021EFDE4[i].id))
      {
        result = 0;
        if (!func_021C8338(p, monId))
        {
          pos = func_021CD4FC(*((void **) &p->fC), 0x4d);
          result = data_021EFDE4[i].call(p, mon, move, 0, arg);
          if (result == 1)
          {
            func_021CD568(*((void **) &p->fC), pos, 0x4d, state, 0x25e);
            func_021CD4B0(*((void **) &p->fC), 0x4c, 0x236);
            return 0;
          }
        }
        if (result == 0)
          func_021CD64C(*((void **) &p->fC), 0x5a, 0x44, 0xffff0000);
        func_021CD4B0(*((void **) &p->fC), 0x4c, 0x236);
        return 0;
      }
    }

  }
  mark = 0;
  pos = func_021CD4FC(*((void **) &p->fC), 0x4d);
  lock = func_021CC8D8(&p->lock, 1217);
  for (i = 0; i < 23; i++)
  {
    e = data_021EFDE4 + i;
    result = func_021D805C((void *)move, e->id);
    if (result && e->call(p, mon, move, result, arg))
      mark = 1;
  }

  if (mark)
  {
    func_021CD568(*((void **) &p->fC), pos, 0x4d, state, (u16) ((state != 6) ? (0x25e) : (0x292)));
    if ((*((u32 *) &p->f18)) != 1)
    {
      func_021B9090(*((u8 **) &p->f4), side, move);
      func_021BA250(*((char **) &p->f4), mon, move);
    }
  }
  else
    func_021CD64C(*((void **) &p->fC), 0x5a, 0x44, 0xffff0000);
  func_021CC95C((u32 *)&p->lock, lock, 1246);
  func_021CD4B0(*((void **) &p->fC), 0x4c, 0x236);
  return 0;
}







/*
 * lever: Separate six-byte selection and two-byte output arrays reproduce
 * the unaligned stack base; a u16 third parameter pins its early home store.
 */
int func_021CBA40(Server *p, void *a, u16 b)
{
    void *m = 0;
    u8 chosen = 6;
    u8 buf[6];
    u8 out[2];
    u8 count;
    u8 i;
    u8 result;
    u8 flag;
    count = func_021B8778(p->f4, (unsigned short)((chosen << 8) | func_021B8D8C(p->f4, p->f8, func_021D5440(a))), buf);
    for (i = 0; i < count; i++) {
        m = func_021B98A4((char *const *)p->f8, buf[i]);
        if (!func_021D5B68(m)) { chosen = buf[i]; break; }
    }
    if (!func_021B86B8(p->f4)) {
        if (chosen != 6) {
            result = func_021CBB34(p, a, m, b, &out[1], &out[0]);
            if (result) {
                p->f14 = 6;
                p->f784 = chosen;
                flag = func_021B8724(p->f4, m) == 0 ? 1 : 0;
                func_021D6E24(m, b);
            } else { flag = 0; }
            func_021CD4B0(p->fC, 0x46, chosen, out[1], result, flag, out[0], b);
        }
        return 1;
    }
    if (chosen != 6) func_021CD4B0(p->fC, 0x47, chosen, b);
    return 0;
}







/*
 * lever: A u16 mode homes its spill early; named u16 form avoids an
 * argument copy. Ternary count selection shares the flag read across
 * the preceding threshold branch and settles the register allocation.
 */
int func_021CBB34(Server *p, void *q, void *m, u16 mode, u8 *out, u8 *flag)
{
    u32 a, t;
    int rate, factor, v;
    u32 count, i;
    u16 species, form;
    *flag = 0;
    if (mode == 1) { *out = 3; return 1; }
    a = func_021D59B4((void *)m, 14) * 3;
    t = a - func_021D59B4((void *)m, 13) * 2;
    v = (int)(t != 0 ? 0.5f + (float)(t << 12) : (float)(t << 12) - 0.5f);
    if (func_021BA1A8(p->f4, 32)) {
        factor = func_021CBCF4(p);
        v = ((s64)v * factor + 0x800) >> 12;
    }
    species = func_021D5444((void *)m);
    form = func_021D59B4((void *)m, 19);
    v *= (u16)func_02019C90(species, form, 8);
    factor = func_021CBD48(p, q, (void *)m, mode);
    v = ((s64)v * factor + 0x800) >> 12;
    v = (u32)v / a;
    switch (func_021D62A8((void *)m)) {
    case 2: case 3: v = ((s64)v * 0x2800 + 0x800) >> 12; break;
    case 1: case 4: case 5: v = ((s64)v * 0x1800 + 0x800) >> 12; break;
    }
    rate = func_020111BC(v);
    *flag = func_021CBEA8(p, rate);
    if (rate >= 0xff000) { *out = *flag ? 1 : 3; return 1; }
    count = *flag ? 1 : 3;
    rate = FX_Div(0x10000000, FX_Sqrt(FX_Sqrt(FX_Div(0xff000, rate)))) >> 12;
    *out = 0;
    for (i = 0; i < count; i++) {
        if (func_021D78AC(0x10000) < (u32)rate) (*out)++;
        else return 0;
    }
    return 1;
}








u32 func_021CBCF4(Server *p)
{
    u32 v = func_021B873C((char **)p->f4);
    if (v > 600) return 0x1000;
    if (v > 450) return 0xe66;
    if (v > 300) return 0xccd;
    if (v > 150) return 0xb33;
    if (v > 30) return 0x800;
    return 0x4cd;
}







/*
 * outside covered regions. Its call has no external witness; tu split
 * census reports zero witnesses and no viable partition. The trailing
 * 16 bytes are that veneer, not compiled C.
 */
int func_021CBD48(Server *p, void *unused, void *q, int k)
{
    u16 n;
    float f;
    int value;
    u8 flag;
    u8 *t;
    switch (k) {
    case 3: return 0x1800;
    case 2: return 0x2000;
    case 6:
        if (func_021D5814(q,10) || func_021D5814(q,6)) return 0x3000;
        break;
    case 7:
        if (func_021BA1A8(p->f4,1)) return 0x3800;
        if (*(int *)(func_021B8714((char **)p->f4)+4) == 6) return 0x3800;
        break;
    case 8:
        n = func_021D59B4(q,15);
        if (n < 30) {
            n = 41 - n;
            if (n > 40) n = 40;
            if (n != 0) f = 0.5f + (float)(n << 12);
            else f = (float)(n << 12) - 0.5f;
            return (int)f / 10;
        }
        break;
    case 9:
        if (func_021B8724(p->f4,q)) return 0x3000;
        break;
    case 10:
        value = p->f10*0x4cd+0x1000;
        if (value > 0x4000) value = 0x4000;
        return value;
    case 13:
        t = (u8 *)func_021B8714((char **)p->f4);
        flag = func_020113F0(t[9],t[12]);
        if ((unsigned)(*(int *)t - 4) <= 1) return 0x3800;
        if (func_021CBE98(*(int *)t)) {
            if ((u8)(flag + 253) <= 1) return 0x3800;
        }
        break;
    case 15:
        if (p->f10 == 0) return 0x5000;
        break;
    default: break;
    }
    return 0x1000;
}










/*
 * note:     the divide by 6 belongs to the fixed-point multiply's statement
 *           (`x = FX_MUL(x, k) / 6;`); the `>> 12` goes inside the compare.
 *           A separate `q = x / 6;` statement lets the compiler move the
 *           divide after the call, and a separate shift statement moves the
 *           shift before it.
 */
int func_021CBEA8(Server *p, int x)
{
    u32 v = func_021B873C((char **)p->f4);
    int k;
    if (v > 600) k = 0x2800;
    else if (v > 450) k = 0x2000;
    else if (v > 300) k = 0x1800;
    else if (v > 150) k = 0x1000;
    else if (v > 30) k = 0x800;
    else return 0;
    if (x > 0xff000) x = 0xff000;
    x = (int)(((long long)x * k + 0x800) >> 12) / 6;
    if (func_021D78AC(256) < (u32)(x >> 12))
        return 1;
    return 0;
}










/* 021CBF30  stack-arg wrapper: func_021CC350(a, b, c, d, 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF30(Server *a, void *b, int c, int d) { func_021CC350(a, b, c, d, 0x2); }










/* 021CBF40  stack-arg wrapper: func_021CC350(a, b, c, d, 0x5) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #5; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF40(Server *a, void *b, int c, int d) { func_021CC350(a, b, c, d, 0x5); }










/* 021CBF50  stack-arg wrapper: func_021CC350(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF50(Server *a, void *b, int c, int d) { func_021CC350(a, b, c, d, 0x4); }










/* 021CBF60  stack-arg wrapper: func_021CC350(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF60(Server *a, void *b, int c, int d) { func_021CC350(a, b, c, d, 0x3); }










/* 021CBF70  stack-arg wrapper: func_021CC350(a, b, c, d, 0x1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #1; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF70(Server *a, void *b, int c, int d) { func_021CC350(a, b, c, d, 0x1); }










/* 021CBF80  stack-arg wrapper: func_021CC350(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC350; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF80(Server *a, void *b, int c, int d) { func_021CC350(a, b, c, d, 0x6); }









/* 021CBF90  stack-arg wrapper: func_021CC398(a, b, c, d, 0x7) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021CC398; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF90(Server *a, void *b, int c, int d) { func_021CC398(a, b, c, d, 0x7); }









int func_021CBFA0(Server *p, u8 *q)
{
    int m;
    u8 *w;
    Word_021CAA58_td t;
    m = func_021B9A40(func_021D5440(q));
    t = func_021E8940(5);
    if (func_021CBFF8(m, 3, t)) {
        w = func_021C88A4(p, 4, 0x1f);
        func_021C8838(w + 4, 1, 0x88);
        func_021C8860((struct S_p12 *)(w + 4), m);
        func_021C88C8(p, w);
        return 1;
    }
    return 0;
}








/*
 * The switch stores into w+6 in every arm (as func_021CC2C0 does), which
 * lays the arms out as the original has them; the default arm calls
 * func_021D805C again. s is narrow: as u32 (or a pointer, as the sibling
 * handlers func_021CC2C0/CC178/CC214 declare it) its `ldr r0,[sp]` reload
 * is hoisted above `strb r7,[r4,#4]`; u16 and u8 both keep it below.
 * Nothing in the image fixes the width; u16 chosen. The function sits in
 * the handler table at 0x021EFE28.
 */
int func_021CC008(Server *p, u8 *q, u16 s)
{
    int id;
    u8 *w;
    u32 r;
    if (func_021D5B68(q)) {
        id = func_021D5440(q);
        w = func_021C88A4(p, 0x2c, id);
        w[4] = id;
        r = func_021D805C((void *)s, 0x3a);
        switch (r) {
        case 0xff:
            ((struct Obj06229 *)w)->f6 = func_021D59B4(q, 0xe);
            break;
        case 0xfe:
            ((struct Obj06229 *)w)->f6 = func_021D7B74(q, 2);
            break;
        case 0xfd:
            ((struct Obj06229 *)w)->f6 = func_021D7B74(q, 4);
            break;
        default:
            ((struct Obj06229 *)w)->f6 = func_021D805C((void *)s, 0x3a);
            break;
        }
        func_021C8838(w + 8, 2, 3);
        func_021C8860((struct S_p12 *)(w + 8), id);
        func_021C88C8(p, w);
        func_021C84E0(p, id);
        return 1;
    }
    return 0;
}








/* 021CC098  stack-arg wrapper: func_021CC438(a, b, c, d, 0x1) */
void func_021CC098(Server *a, void *b, int c, u8 d) { func_021CC438(a, b, c, d, 0x1); }








/* 021CC0A8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x2) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #2; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0A8(Server *a, void *b, int c, u8 d) { func_021CC438(a, b, c, d, 0x2); }








/* 021CC0B8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x3) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0B8(Server *a, void *b, int c, u8 d) { func_021CC438(a, b, c, d, 0x3); }








/* 021CC0C8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x4) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0C8(Server *a, void *b, int c, u8 d) { func_021CC438(a, b, c, d, 0x4); }








/* 021CC0D8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x5) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #5; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0D8(Server *a, void *b, int c, u8 d) { func_021CC438(a, b, c, d, 0x5); }








/* 021CC0E8  stack-arg wrapper: func_021CC438(a, b, c, d, 0x6) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #6; str r4, [sp]; bl func_021CC438; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CC0E8(Server *a, void *b, int c, u8 d) { func_021CC438(a, b, c, d, 0x6); }








int func_021CC0F8(char *p, void *m, int c, int n)
{
    int flag;

    flag = 0;
    if (func_021D5BDC(m, 9) == 0) {
        func_021D5FE4(m, 9);
        func_021CD4B0(((struct Obj09981 *)p)->fC, 0x19, func_021D5440(m), 9);
        flag = 1;
    }
    if (n > 1) {
        if (func_021D5F38(m, n - 1) != 0) {
            func_021CD4B0(((struct Obj09981 *)p)->fC, 0xe, func_021D5440(m), n - 1);
            flag = 1;
        }
    }
    if (flag) {
        func_021CD64C(((struct Obj09981 *)p)->fC, 0x5b, 0x411, func_021D5440(m), 0xffff0000);
        return 1;
    }
    return 0;
}








int func_021CC178(Server *a, void *m, void *s, int d, u8 n)
{
    u8 id;
    u32 cnt;
    u32 lim;
    u8 *r;

    if (func_021D5450(m) > n) {
        id = func_021D5440(m);
        cnt = func_021D5568(m, n);
        lim = (u8)func_021D805C(s, 0x3b);
        if (lim != 0x7f && cnt > lim)
            cnt = lim;
        if (cnt != 0) {
            r = (u8 *)func_021C88A4(a, 9, id);
            r[4] = cnt;
            r[5] = id;
            r[6] = n;
            r[7] |= 2;
            func_021C8838(r + 8, 2, 390);
            func_021C8860((struct S_p12 *)(r + 8), id);
            func_021C8860((struct S_p12 *)(r + 8), func_021D54D0(m, n));
            func_021C88C8(a, r);
            return 1;
        }
    }
    return 0;
}








int func_021CC214(Server *a, void *m, void *s)
{
    u8 id;
    u32 n;
    int ok;
    u32 lim;
    u32 c;
    u32 i;
    u8 *r;

    id = func_021D5440(m);
    lim = (u8)func_021D805C(s, 0x3b);
    ok = 0;
    n = func_021D5450(m);
    for (i = 0; i < n; i++) {
        c = (u32)func_021D5568(m, (u8)i);
        if (c > lim)
            c = lim;
        if (c != 0) {
            r = (u8 *)func_021C88A4(a, 9, id);
            r[6] = i;
            r[5] = id;
            r[4] = c;
            r[7] |= 2;
            func_021C88C8(a, r);
            ok = 1;
        }
    }
    if (ok) {
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, 393);
        func_021C8860((struct S_p12 *)(r + 4), id);
        func_021C88C8(a, r);
    }
    return ok;
}







int func_021CC2C0(Server *a, void *m, void *s)
{
    int id;
    u8 *r;
    u32 k;

    if (func_021D5B48(m) == 0 && func_021D5B68(m) == 0) {
        id = func_021D5440(m);
        r = (u8 *)func_021C88A4(a, 5, id);
        r[6] = id;
        r[7] = 1;
        k = func_021D805C(s, 0x3a);
        switch (k) {
        case 0xff:
            ((struct Obj05195 *)r)->f4 = func_021D59B4(m, 14);
            break;
        case 0xfe:
            ((struct Obj05195 *)r)->f4 = func_021D7B74(m, 2);
            break;
        case 0xfd:
            ((struct Obj05195 *)r)->f4 = func_021D7B74(m, 4);
            break;
        default:
            ((struct Obj05195 *)r)->f4 = k;
            break;
        }
        func_021C8838(r + 8, 2, 387);
        func_021C8860((struct S_p12 *)(r + 8), id);
        func_021C88C8(a, r);
        return 1;
    }
    return 0;
}







int func_021CC350(Server *a, void *m, int c, int d, u32 v)
{
    u8 id;
    Rec_021CC008_td *r;

    if (func_021D5B68(m) == 0 && func_021D62C4(m, v) != 0) {
        id = func_021D5440(m);
        r = (Rec_021CC008_td *)func_021C88A4(a, 11, id);
        r->f14 = 1;
        r->f08 = id;
        r->f04 = v;
        func_021C88C8(a, r);
        return 1;
    }
    return 0;
}







int func_021CC398(Server *p, void *m, int c, int d, u32 v)
{
    u32 k;
    int ret;
    int id;
    u8 *r;
    int i;

    if (func_021D5B68(m) == 0) {
        if (func_021CC418(p->w1ab8, func_021D5440(m)) == 0) {
            ret = 0;
            i = 0;
            for (;;) {
                k = func_021CC428(i++);
                if (k == 0)
                    break;
                if (func_021D62C4(m, k) != 0) {
                    id = func_021D5440(m);
                    r = (u8 *)func_021C88A4(p, 11, id);
                    r[0x14] = 1;
                    r[8] = id;
                    ((struct Obj09983 *)r)->f4 = k;
                    func_021C88C8(p, r);
                    ret = 1;
                }
            }
            return ret;
        }
    }
    return 0;
}






int func_021CC438(Server *p, void *m, int c, u8 d, u32 e)
{
    int id;
    u8 *r;

    id = func_021D5440(m);
    if (func_021CC49C(p->w1ab8, id) != 6) {
        if (func_021D5B68(m) == 0 && func_021D5D14(m, e, d) != 0) {
            r = (u8 *)func_021C88A4(p, 14, id);
            r[0xf] = 1;
            r[0x10] = id;
            ((struct Obj06230 *)r)->f4 = e;
            r[0xc] = d;
            r[0xe] = 1;
            func_021C88C8(p, r);
            return 1;
        }
    }
    return 0;
}






u8 func_021CC4AC(Server *a, void *m)
{
    u8 buf;

    if (func_021CC4F8((u16)(u32)func_021D5B40(m)) == 0) {
        func_021D5440(m);
        if ((u8)func_021C84AC(a, m, &buf) == 0) {
            return buf != 0 ? 2 : 0;
        }
        return 1;
    }
    return 0;
}







int func_021CC508(Server *p, void *m)
{
    u32 s;
    int r;

    if (func_021D59B4(m, 16) != 150) {
        s = func_021CC8D8(&p->lock, 1921);
        func_021C84D0(p, m);
        r = func_021C8910(p);
        func_021CC95C((u32 *)&p->lock, s, 1926);
        if (r == 2)
            return 1;
    }
    return 0;
}







int func_021CC558(Server *p, void *m)
{
    u32 s;
    int id;
    u32 t;
    char *q;

    if (func_021E869C(p, func_021D5440(m)) == 0) {
        t = (u16)(u32)func_021D5B40(m);
        if (t != 0) {
            s = func_021CC8D8(&p->lock, 1944);
            id = func_021D5440(m);
            q = (char *)func_021C88A4(p, 32, id);
            q[6] = id;
            ((struct Obj13347 *)q)->f4 = 0;
            func_021C8838(q + 12, 2, 225);
            func_021C8860((struct S_p12 *)(q + 12), id);
            func_021C8860((struct S_p12 *)(q + 12), t);
            func_021C88C8(p, q);
            func_021CC95C((u32 *)&p->lock, s, 1957);
            return 1;
        }
    }
    return 0;
}







int func_021CC5F4(Server *p, void *m)
{
    u32 s;
    int id;
    u8 *r;
    char *q;

    s = func_021CC8D8(&p->lock, 1968);
    id = func_021D5440(m);
    r = (u8 *)func_021C88A4(p, 16, id);
    r[4] = 1;
    r[5] = id;
    func_021C88C8(p, r);
    q = (char *)func_021C88A4(p, 4, id);
    func_021C8838(q + 4, 2, 228);
    func_021C8860((struct S_p12 *)(q + 4), id);
    func_021C88C8(p, q);
    func_021CC95C((u32 *)&p->lock, s, 1984);
    return 1;
}






int func_021CC668(u8 *p)
{
    u8 live[2];
    u8 counts[2];
    u32 i;
    char *list;
    u8 side;
    u8 other;
    int k;
    live[0] = live[1] = 0;
    counts[0] = counts[1] = 0;
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(((struct Obj05196 *)p)->f4, i)) {
            list = func_021B9AEC(*(char * *)&((struct Obj05196 *)p)->f8,i);
            if (func_021B9B94((struct Q1 *)list)) {
                side = func_021B8BC4((int)(((struct Obj05196 *)p)->f4),(u8)i);
                live[side] += func_021B9B98((u8 *)list);
                counts[side] += func_021B9B94((struct Q1 *)list);
            }
        }
    }
    side = func_021B8BC4((int)(((struct Obj05196 *)p)->f4),(u8)func_021B8FF4(((struct Obj05196 *)p)->f4));
    other = side ^ 1;
    if (live[side] == 0 && live[other] != 0) return 0;
    if (live[other] == 0 && live[side] != 0) return 1;
    if (!func_021BA534(((struct Obj05196 *)p)->f4)) return 2;
    if (live[0] == 0) {
        k = func_021CC758(p+0x3e0);
        if (k != 31) {
            k = func_021B9A40(k);
            if (k == side) return 1;
            return 0;
        }
        return 2;
    }
    return func_021CC768(p, live, counts, side);
}










int func_021CC768(void *a, u8 *p, u8 *q, int want)
{
    int d0;
    int d1;
    int res;
    int vc;
    int v8;
    int v4;
    int v0;

    d0 = q[0] - p[0];
    d1 = q[1] - p[1];
    if (d0 != d1) {
        res = 1;
        if (d0 < d1)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    func_021CC800(a, (u32 *)(&v8), (u32 *)(&v0), 0);
    func_021CC800(a, (u32 *)(&vc), (u32 *)(&v4), 1);
    if (v0 != v4) {
        res = 1;
        if (v0 > v4)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    if (v8 != vc) {
        res = 1;
        if (v8 > vc)
            res = 0;
        if ((u8)res == want)
            return 1;
        return 0;
    }
    return 2;
}










void func_021CC800(u8 *a, u32 *out1, u32 *out2, u8 want)
{
    u32 sum;
    u32 j;
    u32 i;
    char *p;
    u32 n;
    u8 *t;

    sum = 0;
    *out1 = 0;
    *out2 = 0;
    for (j = 0; j < 4; j++) {
        if (func_021B8B9C(((struct Obj09984 *)a)->f4, j) != 0 &&
            want == func_021B8BC4((int)(((struct Obj09984 *)a)->f4), (u8)j)) {
            p = func_021B9AEC(((struct Obj09984 *)a)->f8, j);
            n = func_021B9B94((struct Q1 *)p);
            for (i = 0; i < n; i++) {
                t = func_021B9C00((struct S2 *)p, (u8)i);
                sum += func_021D59B4(t, 14);
                *out1 += func_021D59B4(t, 13);
            }
        }
    }
    *out2 = _u32_div_f(*out1 * 100, sum);
}









void func_021CC8A0(u32 *p) { u32 i; for (i=0;i<24;i++) p[i]=6; }










void func_021CC8B0(u32 *p, u32 i, u32 b)
{
    *(u32 *)&p[i] = b;
}










/*
 * indexed load
 */
u32 func_021CC8B8(u32 *p, u32 i)
{
    return p[i];
}










u32 func_021CC8C0(u32 *p, u32 i)
{
    return p[i];
}








void func_021CC8C8(u32 *p) { *p++=0; func_02082BCC(p,0,500); }








u32 func_021CC8D8(void *lock, int line)
{
    struct Lock *p = lock;
    u32 old = *(u32 *)p;
    p->a = 0;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}









u32 func_021CC918(Bf_td *p, u32 v)
{
    u32 old = ((struct Obj21130 *)p)->f0;
    p->a = v;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}









/* 021CC95C  str r1,[r0] */
/*
 * Stores the second argument (a u32) into the field at offset 0.
 */
void func_021CC95C(u32 *p, u32 v, int line) { *p = v; }









unsigned short func_021CC960(struct S_p14 *p)
{
    return p->x;
}








/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #1; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC96C(struct Q9 *p) { return p->b; }








void func_021CC974(Word_021CC768 *p,int flag) { if(flag) {p->a=1;p->b=1;} else p->a=0; p->c=1; }








/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; lsls r0, r0, #3; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021CC99C(struct Q10 *p) { return p->b; }









u32 func_021CC9A4(u32 *p)
{
    return (((struct Obj18356 *)p)->f0 << 2) >> 31;
}









struct Rec_p14 *func_021CC9AC(struct Pack *p, int id, int b)
{
    u32 i;
    u32 size;
    u32 off;
    u32 j;
    struct Rec_p14 *rec;

    i = 0;
    size = 0;
    for (; i < 0x3B; i++) {
        if (id == d_021EFE9C[i].id) {
            size = d_021EFE9C[i].size;
            break;
        }
    }
    if (size != 0) {
        while (size & 3) {
            size++;
        }
        off = p->off;
        if (off + size <= 500) {
            rec = (struct Rec_p14 *)(p->data + off);
            for (j = 0; j < size; j++) {
                p->data[p->off + j] = 0;
            }
            rec->id = id;
            rec->size = size;
            rec->b = b;
            rec->x = 0;
            rec->y = 1;
            p->off = p->off + size;
            return rec;
        }
    }
    return 0;
}








void func_021CCA74(QueueA *p,QueueB *q) { unsigned a,b,t; a=p->size;b=q->size;if(b<=a) {t=(u32)q-((u32)p+4);t+=b;if(t==a) p->size=a-b;} }








void func_021CCAA8(Buf_021CC768 *p,u8 v) {if(p->wpos>=3000)func_02034714(data_021F3A84,0,data_021F3A84);p->buf[p->wpos++]=v;}









/* 021CCAD4  ldr r2,[r0,#4]; adds r1,r2,#1; str r1,[r0,#4]; adds r0,r0,r2;
 *           ldrb r0,[r0,#8] */
/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: ldr r2, [r0, #4]; adds r1, r2, #1; str r1, [r0, #4]; adds r0, r0, r2; ldrb r0, [r0, #8]; bx lr.
 */
u8 func_021CCAD4(u8 *p)
{
    u32 off = ((struct Obj01891 *)p)->f4;
    ((struct Obj01891 *)p)->f4 = off + 1;
    return *(u8 *)(p + off + 8);
}








void func_021CCAE0(Buf_021CC768 *p,u16 v) {if(p->wpos>=2999)func_02034714(data_021F3A84,0,data_021F3A84);p->buf[p->wpos++]=v>>8;p->buf[p->wpos++]=v;}









/*
 * lever: Once-300 permuter expands the byte-source local and binds rpos
 *        separately before the two loads; retain unsigned full-word cursor.
 *        The signed 32-bit temporary preserves its input bits; convert back
 *        to u32 before every modular address sum, then cast the final address.
 */
u32 func_021CCB18(Buf_021CC768 *p)
{
    const u8 *q;
    u16 v;
    int tmp;
    tmp = p->rpos;
    q = (const u8 *)((u32)p + p->rpos);
    v = (*(const u8 *)((u32)p + (u32)tmp + 8) << 8) |
        *(const u8 *)((u32)p + p->rpos + 9);
    p->rpos += 2;
    return v;
}









void func_021CCB34(Buf_021CC768 *w, u32 v)
{
    if (w->wpos >= 0xBB6) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    w->buf[w->wpos++] = v >> 16;
    w->buf[w->wpos++] = v >> 8;
    w->buf[w->wpos++] = v;
}









/* read a 24-bit big-endian value and advance the cursor */
u32 func_021CCB78(ByteStream *s)
{
    u32 pos = s->pos;
    u8 *p = (u8 *)s + pos;
    u32 v = (p[8] << 16) | (p[9] << 8) | p[10];

    s->pos = pos + 3;
    return v;
}









void func_021CCB98(Buf_021CC768 *w, u32 v)
{
    if (w->wpos >= 0xBB5) {
        func_02034714(data_021F3A84, 0, data_021F3A84);
    }
    w->buf[w->wpos++] = v >> 24;
    w->buf[w->wpos++] = v >> 16;
    w->buf[w->wpos++] = v >> 8;
    w->buf[w->wpos++] = v;
}








u32 func_021CCBE8(Buf_021CC768 *p) {u32 v;u8 *q;q=(u8*)p+p->rpos;v=((u32)q[8]<<24)|((u32)q[9]<<16)|((u32)q[10]<<8)|q[11];p->rpos+=4;return v;}









void func_021CCC0C(void *w, u32 id, int cmd, s32 *a)
{
    int i;

    func_021CCAE0(w, id);
    switch (cmd) {
    case 1:
        func_021CCAA8(w, a[0]);
        break;
    case 17:
        func_021CCAE0(w, a[0]);
        break;
    case 2:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        break;
    case 18:
        func_021CCAA8(w, a[0]);
        func_021CCAE0(w, a[1]);
        break;
    case 34:
        func_021CCAA8(w, a[0]);
        func_021CCB98(w, a[1]);
        break;
    case 50:
        func_021CCAA8(w, ((a[0] & 0xF) << 4) | (a[1] & 0xF));
        break;
    case 66:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        break;
    case 3:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        break;
    case 19:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAE0(w, a[2]);
        break;
    case 35:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        break;
    case 51:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        break;
    case 67:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        break;
    case 83:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCB98(w, a[2]);
        break;
    case 20:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, ((a[2] & 0x1F) << 3) | (a[3] & 7));
        break;
    case 4:
        func_021CCAA8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        func_021CCAA8(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 36:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAA8(w, a[3]);
        break;
    case 52:
        func_021CCB34(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        func_021CCAE0(w, a[3]);
        break;
    case 68:
        func_021CCAE0(w, (a[2] & 0x3F) | (((a[1] & 0x1F) << 6) | ((a[0] & 0x1F) << 11)));
        func_021CCAE0(w, a[3]);
        break;
    case 84:
        func_021CCAA8(w, a[0]);
        func_021CCAA8(w, a[1]);
        func_021CCAE0(w, a[2]);
        func_021CCAE0(w, a[3]);
        break;
    case 5:
        func_021CCAE0(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        func_021CCAE0(w, a[3]);
        func_021CCAE0(w, a[4]);
        break;
    case 21: {
        u8 hi = ((a[0] & 0x1F) << 3) | (a[1] & 7);
        u8 lo = ((a[2] & 0x7F) << 1) | (a[3] & 1);
        func_021CCAE0(w, hi);
        func_021CCAE0(w, lo);
        func_021CCAE0(w, a[4]);
        break;
    }
    case 37:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 7) << 2) | ((a[2] & 1) << 1) | (a[3] & 1));
        func_021CCAE0(w, a[4]);
        break;
    case 6: {
        u16 v0 = (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10));
        u16 v1 = (a[5] & 0x1F) | (((a[4] & 0x1F) << 5) | ((a[3] & 0x1F) << 10));
        func_021CCAE0(w, v0);
        func_021CCAE0(w, v1);
        break;
    }
    case 22:
        func_021CCAA8(w, ((a[0] & 7) << 5) | ((a[1] & 3) << 3) | ((a[2] & 1) << 2) | ((a[3] & 1) << 1) | (a[4] & 1));
        func_021CCAE0(w, a[5]);
        break;
    case 38:
        func_021CCB34(w, ((a[0] & 0x1F) << 15) | ((a[1] & 0x1F) << 10) | ((a[2] & 0x1F) << 5) | (a[3] & 0x1F));
        func_021CCAE0(w, a[4]);
        func_021CCAE0(w, a[5]);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            func_021CCAA8(w, a[i]);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            func_021CCAA8(w, a[i]);
        break;
    }
}









void func_021CD0F0(void *r, int cmd, s32 *a)
{
    u8 b;
    u32 h;
    u32 x;
    int i;

    switch (cmd) {
    case 1:
        a[0] = func_021CCAD4(r);
        break;
    case 17:
        a[0] = func_021CCB18(r);
        break;
    case 2:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        break;
    case 18:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCB18(r);
        break;
    case 34:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCBE8(r);
        break;
    case 50:
        b = func_021CCAD4(r);
        a[0] = (b >> 4) & 0xF;
        a[1] = b & 0xF;
        break;
    case 66:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        break;
    case 3:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        break;
    case 19:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCB18(r);
        break;
    case 35:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        break;
    case 51:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        break;
    case 67:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        break;
    case 83:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCBE8(r);
        break;
    case 20:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        b = func_021CCAD4(r);
        a[2] = (b >> 3) & 0x1F;
        a[3] = b & 7;
        break;
    case 4:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        a[3] = func_021CCB18(r);
        break;
    case 36:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCAD4(r);
        break;
    case 52:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCB18(r);
        break;
    case 68:
        h = func_021CCB18(r);
        a[0] = (h >> 11) & 0x1F;
        a[1] = (h >> 6) & 0x1F;
        a[2] = h & 0x3F;
        a[3] = func_021CCB18(r);
        break;
    case 84:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        a[3] = func_021CCB18(r);
        break;
    case 5:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        a[3] = func_021CCB18(r);
        a[4] = func_021CCB18(r);
        break;
    case 21: {
        u32 hi = func_021CCB18(r);
        u32 lo = func_021CCB18(r);
        a[0] = ((u8)hi >> 3) & 0x1F;
        a[1] = (u8)hi & 7;
        a[2] = ((u8)lo >> 1) & 0x7F;
        a[3] = (u8)lo & 1;
        a[4] = func_021CCB18(r);
        break;
    }
    case 37:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 2) & 7;
        a[2] = (x >> 1) & 1;
        a[3] = x & 1;
        a[4] = func_021CCB18(r);
        break;
    case 6: {
        u32 v0 = func_021CCB18(r);
        u32 v1 = func_021CCB18(r);
        a[0] = (v0 >> 10) & 0x1F;
        a[1] = (v0 >> 5) & 0x1F;
        a[2] = v0 & 0x1F;
        a[3] = (v1 >> 10) & 0x1F;
        a[4] = (v1 >> 5) & 0x1F;
        a[5] = v1 & 0x1F;
        break;
    }
    case 22:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 3) & 3;
        a[2] = (x >> 2) & 1;
        a[3] = (x >> 1) & 1;
        a[4] = x & 1;
        a[5] = func_021CCB18(r);
        break;
    case 38:
        x = func_021CCB78(r);
        a[0] = (x >> 15) & 0x1F;
        a[1] = (x >> 10) & 0x1F;
        a[2] = (x >> 5) & 0x1F;
        a[3] = x & 0x1F;
        a[4] = func_021CCB18(r);
        a[5] = func_021CCB18(r);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            a[i] = func_021CCAD4(r);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            a[i] = func_021CCAD4(r);
        break;
    }
}








void func_021CD4B0(void *w, volatile u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 cmd = data_021EFF14[id];
    u32 n = cmd & 0xF;
    va_start(ap, id);
    for (; i < n; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    func_021CCC0C(w, id, cmd, data_021F3B44);
}









u16 func_021CD4FC(Buf_021CC768 *w, u32 id)
{
    u8 cmd;
    u8 n;
    u8 i;
    u8 len;
    u16 pos;

    cmd = data_021EFF14[id];
    n = cmd & 0xf;
    i = 0;
    if (n != 0) {
        do {
            data_021F3B44[i] = 0;
            i++;
        } while (i < n);
    }
    pos = w->wpos;
    func_021CCC0C(w, id, cmd, data_021F3B44);
    len = w->wpos - pos;
    w->wpos = pos;
    func_021CCAE0(w, 0x5f);
    func_021CCAA8(w, len - 3);
    w->wpos = pos + len;
    return pos;
}









void func_021CD568(Buf_021CC768 *w, u16 x, u32 id, ...)
{
    va_list ap;
    u32 i = 0;
    u8 cmd = data_021EFF14[id];
    u32 n = cmd & 0xF;
    u16 pos;

    va_start(ap, id);
    for (; i < n; i++) {
        data_021F3B44[i] = va_arg(ap, s32);
    }
    pos = w->rpos;
    w->rpos = x;
    func_021CCB18(w);
    func_021CCAD4((u8 *)w);
    w->rpos = pos;
    if (id != 0x5f) {
        pos = w->wpos;
        w->wpos = x;
        func_021CCC0C(w, id, cmd, data_021F3B44);
        w->wpos = pos;
    }
}














int func_021CD5E0(Buf_021CC768 *r, s32 *a)
{
    int c;
    u8 k;

    c = func_021CCB18(r);
    while (c == 0x5f) {
        r->rpos += func_021CCAD4((u8 *)r);
        if (r->rpos >= r->wpos) {
            return 0x5e;
        }
        c = func_021CCB18(r);
    }
    k = data_021EFF14[c];
    if (k != 0 && k != 0x10) {
        func_021CD0F0(r, k, a);
    } else {
        func_021CD6AC(r, c, a);
    }
    return c;
}














/*
 * tail-call thunk to func_021CCAA8
 */
void func_021CD63C(void *p, u8 v)
{
    func_021CCAA8(p, v);
}














/*
 * tail-call thunk to func_021CCAD4
 */
u8 func_021CD644(u8 *p)
{
    return func_021CCAD4(p);
}














void func_021CD64C(void *w, u8 id, ...)
{
    va_list ap;
    u16 v;
    s32 x;

    va_start(ap, id);
    v = va_arg(ap, s32);
    func_021CCAE0(w, id);
    func_021CCAE0(w, v);
    if (id == 0x5C) {
        func_021CCAE0(w, va_arg(ap, s32));
    }
    do {
        x = va_arg(ap, s32);
        func_021CCB98(w, x);
    } while (x != (s32)0xFFFF0000);
}














void func_021CD6AC(void *r, u8 cmd, s32 *out)
{
    int i;

    i = 1;
    out[0] = func_021CCB18(r);
    if (cmd == 0x5c) {
        out[1] = func_021CCB18(r);
        i++;
    }
    for (; i < 16; i++) {
        out[i] = func_021CCBE8(r);
        if (out[i] == 0xFFFF0000) {
            break;
        }
    }
}














/*
 * empty function: bx lr
 */
void func_021CD6EC(void)
{
}













u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap)
{
    u8 *p;
    u32 i;
    int flag, k;
    p = func_02030734(heap, 0x1b8, 1, (const char *)d_021F3A88, 0x209);
    flag = 1;
    if (c == 0 || e != 0)
        flag = 0;
    p[0x1a6] = idx;
    *(u16 *)(p + 0x19a) = heap;
    p[0x1a7] = e;
    *(void **)(p + 0x50) = func_021EEA58(d, (u8)idx, flag, heap);
    *(char **)(p + 0x118) = func_021B9AF8((char *)b, idx);
    *(u8 **)p = a;
    *(u8 **)(p + 4) = b;
    p[0x11c] = kind;
    p[0x11d] = 0;
    p[0x121] = idx;
    p[0xc4] = 0;
    *(int *)(p + 0x54) = 0;
    *(u16 *)(p + 0x19c) = 0;
    *(void **)(p + 0x134) = func_02030734(heap, 0xbc0, 1, (const char *)d_021F3A88, 0x21a);
    *(void **)(p + 0x28) = (void *)func_021CDA18;
    p[0x1a8] = 0;
    *(int *)(p + 0xa0) = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f3 = 0;
    p[0x1ae] = 0;
    p[0x1a9] = 0;
    p[0x1ab] = 0;
    *(u16 *)(p + 0xe4) = 0;
    *(u16 *)(p + 0xe6) = 0;
    p[0x1ad] = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f0 = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f1 = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f4 = 0;
    ((Flags_021CC768 *)(p + 0x1b2))->f5 = 0;
    *(u32 *)(p + 0x34) = func_021BA08C((struct Q2 *)a);
    p[0x1aa] = f;
    func_021D8230(p + 0x2c);
    func_021D3F04(p + 0x18);
    func_021D3D9C(p);
    *(struct Copy24 *)(p + 0xf4) = *h;
    if (p[0x1a7] == 1 && g == 0) {
        k = func_021B9FBC(*(char **)p, p[0x1a6]);
        *(void **)(p + 0xf0) = func_02187F00(*(void ***)p, func_021BA820(*(int **)p), *(u32 *)(p + 4), k, *(u16 *)(p + 0x19a));
    } else {
        *(int *)(p + 0xf0) = 0;
    }
    for (i = 0; i < 4; i++)
        p[0x112 + i] = 0;
    if (p[0x1a7] == 0 && func_021B90F8(*(u8 **)p))
        *(void **)(p + 0x10) = func_021EE5E4(heap);
    else
        *(void **)(p + 0x10) = 0;
    return p;
}












void func_021CD8E0(u8 *p) {
 if(*(void* *)&((struct Obj05197 *)p)->f10)func_021EE600(*(void* *)&((struct Obj05197 *)p)->f10);
 if(*(void* *)&((struct Obj05197 *)p)->fF0)func_02188080(*(void* *)&((struct Obj05197 *)p)->fF0);
 func_020307B0(*(void* *)&((struct Obj05197 *)p)->f134);
 func_021EEAE0(*(void* *)&((struct Obj05197 *)p)->f50);
 func_020307B0(p);
}












void func_021CD914(u8 *p) {p[0x1b2]|=2;}












u16 *func_021CD924(u8 *p, u32 *out) { if (*(u16 * *)&((struct Obj13352 *)p)->f10) return func_021EE63C(*(u16 * *)&((struct Obj13352 *)p)->f10,out); return 0; }












/*
 * Prototype: 021D3F48 stores only r1 low16; caller forwards full getter
 * result without truncation, so its extern argument is widened to u32.
 */
void func_021CD938(u8 *p,void *a) { p[0x1a7]=2; ((struct Obj13353 *)p)->f14=a; func_021D3F48(p+0x18,func_021EE830(a)); }












/*
 * Stores the second argument (a u32) into the field at #0x54.
 */
void func_021CD95C(struct QA *p, u32 v) { p->v = v; }













void func_021CD960(u8 *p, u32 v) {
    *(u32 *)(p + 0xA0) = v;
    p[0x1B2] |= 8;
}












/*
 * Reads the u32 field at #0x50 of the argument and returns it.
 */
u32 func_021CD978(struct QB *p) { return p->v; }












/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: push {r3, lr}; ldr r1, [r0, #0x28]; blx r1; pop {r3, pc}.
 */
void func_021CD97C(struct R2 *p) { p->fn(p); }












/*
 * Prototype: 021CDA0C stores its r1 payload unchanged at +0x28; caller
 * passes a callback address. Pointer replaces legacy u32 for that payload.
 */
void func_021CD984(u8 *p,u16 n) { func_021EE674(((struct Obj07767 *)p)->f14); func_021EEBDC(((struct Obj07767 *)p)->f50); func_021D3F64(p+0x18,n); func_021CDA0C((struct QE *)p,(u32)func_021CDC0C); }












void func_021CD9B0(u8 *p) { func_021D3F88((struct S_p14 *)(p+0x18)); func_021CDA0C((struct QE *)p,(u32)func_021CDA18); }













/* 021CD9C8  byte field 0x1a7 == 2 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021CD9D8; ldrb r0, [r0, r1]; cmp r0, #2; bne loc_021CD9D4; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9C8(u8 *p)
{
    return (((struct Obj18365 *)p)->f1A7 == 2);
}












/*
 * Reads the u16 field at #0x22 of the argument and returns it.
 */
u16 func_021CD9DC(struct QD *p) { return p->v; }













/* 021CD9E0  function-pointer slot 0x28 compared with 0x021CDC0D */
/*
 * 8 instructions, 16 bytes: ldr r1, [r0, #0x28]; ldr r0, pool_021CD9F0; cmp r1, r0; bne loc_021CD9EC; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021CD9E0(u8 *p)
{
    return (((struct Obj18367 *)p)->f28 == 0x021CDC0D);
}












/*
 * u8 step preserves the low-byte result for every incoming word; no
 * signed int addition overflow. Wide step emits an extra narrowing pair.
 */
void func_021CD9F4(u8 *p,u8 n) { p[0x1ab]+=n; if(p[0x1ab]>14) p[0x1ab]=14; }











void func_021CDA0C(struct QE *p, u32 v)
{
    p->v = v;
    p->z = 0;
}











int func_021CDA18(u8 *p)
{
    u32 id, *pair, x, y;
    int flag, n;
    func_021D3FDC(p,(struct Qd *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        id = func_021EEBE8(((struct Obj00463 *)p)->f50);
        if (p[0x1a7] == 2 && (((Flags_021CDA18 *)(p+0x1b2))->f4 || ((Flags_021CDA18 *)(p+0x1b2))->f5) && !id) return 0;
        func_021CDD34(p);
        if (id == 9) {
            func_021EEC20(*(int *)&((struct Obj00463 *)p)->f50,&pair);
            x = pair[0]; y = pair[1];
            ((struct Obj00463 *)p)->f30 = y;
            ((struct Obj00463 *)p)->f2C = x;
            ((struct Obj00463 *)p)->fCC = 0;
            p[0x1a8] = 3;
        } else if (id) {
            *(Callback_021CC768 *)&((struct Obj00463 *)p)->fC8 = func_021CDD50(p,id,&flag);
            if (flag) {
                if (!func_021D3FAC(p+0x18)) { p[0x1a8] = 6; break; }
            } else func_021D3FC4(p+0x18);
            if (*(Callback_021CC768 *)&((struct Obj00463 *)p)->fC8) {
                p[0x1a8] = 1;
                ((struct Obj00463 *)p)->fCC = 0;
            } else {
                ((struct Obj00463 *)p)->fCC = 0;
                p[0x1a8] = 2;
            }
        } else if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 1:
        if ((*(Callback_021CC768 *)(p+0xc8))(p,(int *)(p+0xcc))) {
            if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
            if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
            else p[0x1a8] = 2;
        }
        break;
    case 2:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 0;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 7;
        if (((Flags_021CDA18 *)(p+0x1b2))->f1) return 1;
        break;
    case 6:
        if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
        break;
    case 4:
        if (func_021D3F60(p+0x18) == 1) p[0x1a8] = 7;
        else {
            if (((struct Obj00463 *)p)->f54) { func_02005CA4(1,62); func_02006740(); }
            p[0x1a8] = 5;
        }
        break;
    case 5:
        if (!func_02005E50()) {
            n = func_021D3FA8(p+0x18);
            func_02005CA4(0,1);
            func_021BA73C(*(char * *)&((struct Obj00463 *)p)->f0,n);
            func_02006734(0);
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
int func_021CDC0C(u8 *p)
{
    u32 id;
    u16 n;
    int zero;
    func_021D3FDC(p,(struct Qd *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        p[0x1a8] = 1;
    case 1:
        if (!func_021D3F98(p+0x18)) {
            id = func_021EEBE8(((struct Obj00818 *)p)->f50);
            if (id) {
                zero = 0;
                *(Callback_021CC768 *)&((struct Obj00818 *)p)->fC8 = func_021CDD50(p,id,0);
                if (*(Callback_021CC768 *)&((struct Obj00818 *)p)->fC8) {
                    p[0x1a8] = 2;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
                else {
                    func_021CDD34(p);
                    p[0x1a8] = 3;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
            }
        } else {
            if (((struct Obj00818 *)p)->f54) {
                func_02005CA4(1,1);
                func_021EAE24(((struct Obj00818 *)p)->f54);
                func_02005DF8(30);
                func_021F88BC(0);
                func_02006740();
            }
            p[0x1a8] = 4;
        }
        break;
    case 2:
        if ((*(Callback_021CC768 *)(p+0xc8))(p,(int *)(p+0xcc))) {
            p[0x1a8] = 3;
            ((struct Obj00818 *)p)->fCC = 0;
            if (func_021F8678()) func_021F88BC(1);
        }
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00818 *)p)->f50,((struct Obj00818 *)p)->fD8,((struct Obj00818 *)p)->fDC)) p[0x1a8] = 1;
        break;
    case 4:
        if (((struct Obj00818 *)p)->f54) {
            if (func_021EAE34(((struct Obj00818 *)p)->f54)) {
                if (!func_02005E50()) {
                    n = (int)func_021D3FA8(p+0x18);
                    func_021EAE74(((struct Obj00818 *)p)->f54,n,n);
                    func_021BA7F8(((struct Obj00818 *)p)->f0);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}











void func_021CDD34(u8 *p)
{
    ((struct Obj09986 *)p)->fE0 = 0;
    *(u8 * *)&((struct Obj09986 *)p)->fD8 = p+0xe0;
    ((struct Obj09986 *)p)->fDC = 4;
}











Callback_021CC768 func_021CDD50(u8 *p,u32 id,int *out)
{
    u32 i;
    for (i=0; i<15; i++) {
        if (d_021EFFEC[i].id == id) {
            if (out) *out = d_021EFFEC[i].flag;
            return d_021EFFEC[i].callbacks[p[0x1a7]];
        }
    }
    return 0;
}












void func_021CDD94(char *p, int *o)
{
    *(S_p14_td *)o = *(S_p14_td *)(p + 0x2c);
}











/*
 * unresolved THM_CALL at +0x14. Region hint ov094 does not supply a witness.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 owner Ilias). Integrator: seed label.
 */
int func_021CDDA0(u8 *p) { if(p[0x1a7]!=2) { if(*(u16 *)(p+0xe6)) return func_021F8524(0); return 0; } return ((struct Flags_021CDDA0 *)p)->flag; }











u32 func_021CDDCC(struct Flags_021CDDCC *p) { return p->flag; }











/*
 * Levers (from the DIFF note): case 0 is the call written in each arm, `!= 4` arm first
 * (a-boolean-argument-is-a-call-in-each-arm.md; a flag value hoists `movs r1,#1`);
 * func_021F84E8 takes two arguments as its own file says, the second being the 0xe4
 * halfword still live in r1 from the || test; func_021D3FA8 is declared u32 here because
 * the original narrows its result before the u16 parameter of func_021EAEA8.
 */
int func_021CDDDC(u8 *p, int *st)
{
    switch (*st) {
    case 0:
        if ((int)func_021B86B8(*(void *** *)&((struct Obj01689 *)p)->f0) != 4) {
            func_021E90A0(((struct Obj01689 *)p)->f54, 0);
        } else {
            func_021E90A0(((struct Obj01689 *)p)->f54, 1);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_021E90D0(((struct Obj01689 *)p)->f54) == 0) {
            break;
        }
        ((struct Obj01689 *)p)->fE4 = func_021BA5C4(((struct Obj01689 *)p)->f0);
        ((struct Obj01689 *)p)->fE6 = func_021BA5D0(((struct Obj01689 *)p)->f0);
        if (((struct Obj01689 *)p)->fE4 != 0 || ((struct Obj01689 *)p)->fE6 != 0) {
            func_021F84E8(((struct Obj01689 *)p)->fE6, ((struct Obj01689 *)p)->fE4);
            if (((struct Obj01689 *)p)->fE6 != 0) {
                func_021F8504(0, 1, 1);
            }
        }
        func_021CDECC(p);
        if (func_021CD9E0(p) != 0) {
            func_021EAEA8(((struct Obj01689 *)p)->f54, (u16)((u32)func_021D3FA8(p + 0x18)));
        }
        return 1;
    }
    return 0;
}











int func_021CDE8C(int a, int b)
{
    int r4;
    if (((struct Obj06232 *)a)->f54 != 0) {
        r4 = func_021CDDDC((u8 *)a, (int *)b);
        if (r4 != 0) {
            if (func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6) != 0)
                func_021D3F54((u8 *)(a + 0x18));
        }
        return r4;
    }
    func_021EE688(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6);
    return 1;
}










void func_021CDECC(u8 *p) { void *a; a=func_021CDF1C(p); if(a) ((struct Obj04362 *)p)->f19C=func_021D59B4(a,13); }










u32 func_021CDEE8(u8 *p) { void *a; u32 now,old; a=func_021CDF1C(p); if(a) { now=func_021D59B4(a,13); old=((struct Obj04362 *)p)->f19C; if(now>=old) return 0; return _u32_div_f((old-now)*100,now); } return 0; }









/*
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 */
void *func_021CDF1C(u8 *p) { u8 side; if(func_021B8588(*(void ** *)&((struct Obj04362 *)p)->f0)==0 && func_021B86C0(*(u8 ** *)&((struct Obj04362 *)p)->f0)==0) { side=func_021B9064(*(u8 * *)&((struct Obj04362 *)p)->f0,p[0x1a6],0); return func_021B9920(*(char * *)&((struct Obj04362 *)p)->f4,side,0); } return 0; }










int func_021CDF58(u8 *p, int *st)
{
    u8 buf;

    switch (*st) {
    case 0:
        func_021EAA00(((struct Obj01892 *)p)->f54, p[0xc4]);
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021EAA5C(((struct Obj01892 *)p)->f54);
            *st = 2;
        } else if (func_021EAA34(((struct Obj01892 *)p)->f54, &buf) != 0) {
            p[0xc4] = buf;
            *st = 3;
        }
        break;
    case 2:
        p[0xc4] = func_021CDFE4(p[0xc4]);
        *st = *st + 1;
        break;
    case 3:
        func_021CE0E0(p);
        *st = *st + 1;
        break;
    case 4:
        *(u8 * *)&((struct Obj01892 *)p)->fD8 = p + 0xc4;
        ((struct Obj01892 *)p)->fDC = 1;
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







void func_021CE044(u8 *p) { p[0xc4]=func_021CDFE4(p[0xc4]); *(u8 * *)&((struct Obj07768 *)p)->fD8=p+0xc4; ((struct Obj07768 *)p)->fDC=1; }








void func_021CE068(u8 *p) { if(((struct Obj01892 *)p)->fE4) { func_021F8504(1,1,1); p[0x1ad]=0; } }








/*
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
int func_021CE08C(u8 *p) { if(*(u16 *)(p+0xe4)!=0) { if(p[0x1ad]==0) { if(func_021F8524(1)) p[0x1ad]=1; } return p[0x1ad]; } return 0; }








int func_021CE0BC(u8 *p,void *q) { if(func_021CE08C(p)) { if(q) func_021CE150(p,q); return 1; } return 0; }








void func_021CE0E0(u8 *p) { if(((struct Obj21134 *)p)->fE4!=0) func_021F8504(1,0,0); }









void func_021CE0F8(u8 *p, u8 *q, u8 *o)
{
    if (func_021B8588(*(void ** *)&((struct Obj13355 *)p)->f0) != 3) {
        func_021EAF18((struct L *)o, 1, 0x45);
        func_021EAF50((struct L *)o, func_021D5440(q));
        func_021EAF78(o, 0);
    } else {
        func_021EAF18((struct L *)o, 1, 0x46);
        func_021EAF50((struct L *)o, p[0x1a6]);
        func_021EAF78(o, 0);
    }
}








void func_021CE150(u8 *p, void *q) { ((struct Obj01892 *)p)->fD0=q; ((struct Obj01892 *)p)->fD4=0; }









/* 021CE160  the receiver pointer is also the FIRST argument: the image keeps
 * r0 = p, puts p+0xd4 in r1 and the slot from [p+0xd0] in r2. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: push {r3, lr}; adds r2, r0, #0; adds r2, #0xd0; adds r1, r0, #0; ldr r2, [r2]; adds r1, #0xd4; blx r2; pop {r3, pc}.
 */
u32 func_021CE160(u8 *p)
{
    return ((u32 (*)(u8 *, u8 *)) * (u32 *)(p + 0xd0))(p, p + 0xd4);
}








u32 func_021CE170(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CE150(p, (void *)((u32)func_021CE308));
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        func_021CE08C(p);
        if (func_021CE160(p) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}







int func_021CE1B0(u8 *p,int *state)
{
    u8 count;
    u8 flag;
    u32 *data;
    switch (*state) {
    case 0:
        if (((Flags_021CE1B0 *)(p+0x1b2))->flag) {
            func_021CE2E8(p);
            return 1;
        }
        data = func_021EE6B8(((struct Obj01893 *)p)->f14,p[0x1a6],&count,&flag);
        if (flag) func_021D3F54(p+0x18);
        *(u32 * *)&((struct Obj01893 *)p)->fD8 = data;
        ((struct Obj01893 *)p)->fDC = count * 4;
        if (((Command *)data)->kind == 8) {
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb7);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                (*state)++;
            } else {
                func_021CE2E8(p);
                p[0x1b2] |= 0x10;
                return 1;
            }
        } else if (((Command *)data)->kind == 9) {
            p[0x1b2] |= 0x20;
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb8);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                *state += 2;
            } else {
                func_021CE2E8(p);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            p[0x1b2] |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            return 1;
        }
        break;
    }
    return 0;
}







void func_021CE2E8(u8 *p) { *(u8 * *)&((struct Obj07769 *)p)->fC=p+0x124; func_021D8434((u32 *)(p+0x124)); *(u8 * *)&((struct Obj07769 *)p)->fD8=*(u8 * *)&((struct Obj07769 *)p)->fC; ((struct Obj07769 *)p)->fDC=4; }








u32 func_021CE308(u8 *p)
{
    u32 i = 0;
    u32 w;
    p[0x11d] = 0;
    ((s8 *)p)[0x11e] = -1;
    p[0x11f] = 0;
    ((Flags_021CE308 *)(p + 0x1b2))->f = 0;
    func_021D0B10(p, 0, p[0x11c], p + 0x184, p + 0x190);
    func_021CF41C(p);
    func_021CF360(p);
    for (i = 0; i < 3; i++) {
        func_021D8434((u32 *)(p + 0x124 + i * 4));
    }
    for (i = 0; i < p[0x11c]; i++) {
        w = (u32)func_021B990C((char *)(((struct Obj03688 *)p)->f4), p[0x1a6], (u8)i);
        if (func_021CF470(p, (void *)w, 0) == 0) {
            p[0x11f] = i;
            break;
        }
    }
    func_021CE150(p, (void *)((u32)func_021CE4D0));
    return 0;
}







void func_021CE3B4(u8 *p, void *q) { func_021EA614(((struct Obj13356 *)p)->f54,q); p[0x120]=1; }







int func_021CE3C8(u8 *p,int *state)
{
    u8 out[4];
    u32 i;
    u32 id;
    switch (*state) {
    case 0:
        func_021EAE44(((struct Obj00662 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EAE54(((struct Obj00662 *)p)->f54)) {
            for (; p[0x11d] < p[0x11c]; p[0x11d]++) {
                ((struct Obj00662 *)p)->f8 = func_021B990C(((struct Obj00662 *)p)->f4,p[0x1a6],p[0x11d]);
                *(u8 * *)&((struct Obj00662 *)p)->fC = p+0x124+p[0x11d]*4;
                func_021D8434((u32 *)(*(u8 * *)&((struct Obj00662 *)p)->fC));
                if (!func_021CF470(p,((struct Obj00662 *)p)->f8,*(u8 * *)&((struct Obj00662 *)p)->fC)) {
                    i = func_021CF81C(p,((struct Obj00662 *)p)->f8,out);
                    if (i < 4) {
                        id = func_021D54C0(((struct Obj00662 *)p)->f8,i);
                        func_021D82D0((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),id,func_021D81F8(((struct Obj00662 *)p)->f0,((struct Obj00662 *)p)->f4,((struct Obj00662 *)p)->f8,id,p+0x38));
                    } else func_021CF58C((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),p,((struct Obj00662 *)p)->f8);
                }
            }
            (*state)++;
        }
        break;
    case 2:
        *(u8 * *)&((struct Obj00662 *)p)->fD8 = p+0x124;
        ((struct Obj00662 *)p)->fDC = p[0x11c]*4;
        func_021CE150(p,(void *)((u32)func_021CF2F0));
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
int func_021CE4D0(u8 *p, u32 *st)
{
    u32 result;
    switch (*st) {
    case 0:
        (*(void **)(p+8)) = func_021B990C((*(void **)(p+4)), p[0x1A6], p[0x11D]);
        (*(void **)(p+12)) = p + 0x124 + p[0x11D] * 4;
        p[0x1AF] = 0;
        func_021D8434((*(void **)(p+12)));
        if (func_021CF470(p, (*(void **)(p+8)), (*(void **)(p+12)))) {
            func_021CE150(p, (void *)((u32)func_021CF220));
            break;
        }
        if (func_021CE8F0(p, (unsigned short *)(p + 0x19E)) == 1) {
            func_021CE150(p, (void *)((u32)func_021CE7D4));
            break;
        }
        ++*st; break;
    case 1:
        if (*(signed char *)(p + 0x11E) != p[0x11D] || p[0x120]) {
            func_021CE0F8(p, (*(void **)(p+8)), p + 0x58);
            func_021EA65C((*(void **)(p+0x54)), (struct H *)(p + 0x58));
            p[0x120] = 0;
            p[0x11E] = p[0x11D];
            ++*st; break;
        }
        *st += 2U;
        break;
    case 2:
        if (!func_021EA710((*(void **)(p+0x54)))) return 0;
        ++*st;
        /* falls through */
    case 3:
        func_021E9760((*(void **)(p+0x54)), (*(void **)(p+8)), p[0x11D] > p[0x11F], (int)(*(void **)(p+12)));
        ++*st; break;
    case 4:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E979C((*(void **)(p+0x54)));
            return 0;
        }
        result = func_021E97A4((*(void **)(p+0x54)));
        switch (result) {
        case 3:
            if (func_021D62C4((*(void **)(p+8)), 0x21)) {
                func_021E9964((*(u32 *)(p+0x54)));
                *st = 6;
            } else {
                func_021CF430(p, p[0x11D], 0);
                func_021CE150(p, (void *)((u32)func_021CEDC0));
            }
            break;
        case 1:
            func_021CF430(p, p[0x11D], 0);
            func_021CE150(p, (void *)((u32)func_021CEA94));
            break;
        case 2:
            if (func_021D62C4((*(void **)(p+8)), 0x21)) *st = 6;
            else if (p[0x1AA] == 1 && !func_021BA1EC((*(void **)(p+0)))) {
                func_021E9964((*(u32 *)(p+0x54)));
                *st = 5;
            } else func_021CE150(p, (void *)((u32)func_021CEEB8));
            break;
        case 4:
            if (p[0x11D] == p[0x11F]) {
                if (func_021D62C4((*(void **)(p+8)), 0x21) && func_021B86E4((*(void **)(p+0))) != 2) *st = 6;
                else {
                    func_021CF430(p, p[0x11D], 0);
                    func_021CE150(p, (void *)((u32)func_021CF078));
                }
                break;
            }
            if (p[0x11D] == 0) break;
            do {
                --((struct L *)p)->idx;
                if (!func_021CF470(p, func_021B990C((*(void **)(p+4)), ((struct L *)p)->sel, ((struct L *)p)->idx), 0)) {
                    p[0x1AB] += func_021CF43C(p, p[0x11D]);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 3)
                        func_021CE7C4(p + 0x190);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 2)
                        func_021CF3B8(p, p[0x11D]);
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
                    return 0;
                }
            } while (((struct L *)p)->idx != 0);
            break;
        }
        break;
    case 5:
        if (func_021E9974((*(u32 *)(p+0x54)))) *st = 3;
        break;
    case 6:
        func_021E9954((*(void **)(p+0x54)));
        ++*st; break;
    case 7:
        if (!func_021E9974((*(u32 *)(p+0x54)))) break;
        func_021EAF18((struct L *)(p + 0x58), 1, 0xC5);
        func_021EAF50((struct L *)(p + 0x58), func_021D5440((*(void **)(p+8))));
        func_021CE3B4(p, p + 0x58);
        ++*st; break;
    case 8:
        if (func_021EA710((*(void **)(p+0x54)))) *st = 1;
        break;
    }
    return 0;
}








u32 func_021CE7D4(u8 *p, int *st)
{
    u32 i;
    u16 k;
    u32 z;
    switch (*st) {
    case 0:
        z = 0;
        i = func_021B904C(((struct Obj02785 *)p)->f0, 0);
        k = func_021BA004(((struct Obj02785 *)p)->f0, i);
        func_021F7F58(func_021BA020(((struct Obj02785 *)p)->f0, i), 9, 0, 0, z);
        func_021F7998(0x270);
        func_021EA6B0(*(char * *)&((struct Obj02785 *)p)->f54, k, ((struct Obj02785 *)p)->f19E);
        if ((u16)(((struct Obj02785 *)p)->f19E + 0xffed) <= 1 &&
            func_021D7F38(func_021BA020(((struct Obj02785 *)p)->f0, i)) && !((Flags_021CE7D4 *)(p + 0x1b2))->flag) {
            func_021F87EC(0x47b);
            if (!func_021F8774()) {
                func_02005E30(8);
                *st = 1;
                break;
            }
        }
        *st = 2;
        break;
    case 1:
        if (!func_02005E50()) {
            func_02005D90(0x47b, 0xffff);
            p[0x1b2] = (p[0x1b2] & ~1) | 1;
            ++*st;
        }
        break;
    case 2:
        if (!func_021F7EB4() && func_021EA710(((struct Obj02785 *)p)->f54)) {
            func_021F7998(0x271);
            ++*st;
        }
        break;
    case 3:
        if (!func_021F7EB4()) func_021CE150(p, (void *)((u32)func_021CE4D0));
        break;
    }
    return 0;
}







static inline void init_offset(Off *value)
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
u32 func_021CE8F0(const u8 *p, u16 *out)
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
    if ((u32)func_021B86B8(*(void *** *)&((struct Obj03689 *)p)->f0) != 1) goto fail;
    id = func_021B904C(((struct Obj03689 *)p)->f0,0);
    k = func_021BA004(((struct Obj03689 *)p)->f0,id);
    if (!k) goto fail;
    entry = (u32)func_021B9AEC(*(char * *)&((struct Obj03689 *)p)->f4,id);
    mon = func_021B990C(((struct Obj03689 *)p)->f4,id,(u8)0);
    if (func_021D5B68(mon)) {
        count = func_021B99B8(((struct Obj03689 *)p)->f0,id);
        for (i=1;i<count;i++) {
            mon = func_021B990C(((struct Obj03689 *)p)->f4,id,(u8)i);
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
        row = (u8 *)p + i;
        if (!row[skip]) {
            key = d_021EFF78[i];
            if (func_0202A298(k,key,((struct Obj03689 *)p)->f19A)) {
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
int func_021CEA94(u8 *p, u32 *state)
{
    void *m;
    u32 slot, k;
    u32 *record;
    u8 sub;
    switch (*state) {
    case 0:
        if (func_021B8588(((struct Obj00434 *)p)->f0) != 3) {
            if (func_021CF524((u32)p, ((struct Obj00434 *)p)->f8, *(u32 *)&((struct Obj00434 *)p)->fC))
                func_021CE150(p, (void *)((u32)func_021CF220));
            else *state = 1;
        } else {
            func_021CECB4(p, (Ent_021CECB4 *)(p + 0xa4));
            *state = 2;
        }
        break;
    case 1:
        func_021E97BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 2:
        func_021E9808(((struct Obj00434 *)p)->f54, (u32 *)(p + 0xa4), *(int *)&((struct Obj00434 *)p)->fC);
        *state = 3;
        break;
    case 3:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E98AC(((struct Obj00434 *)p)->f54);
            return 0;
        }
        if (func_021E98B4(((struct Obj00434 *)p)->f54)) {
            k = func_021D8454(*(u32 * *)&((struct Obj00434 *)p)->fC);
            if (k == 0) func_021CE150(p, (void *)((u32)func_021CE4D0));
            else if (k == 5) func_021CE150(p, (void *)((u32)func_021CF220));
            else {
                m = ((struct Obj00434 *)p)->f8;
                record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                sub = 0;
                slot = p[0x11d];
                if (func_021B8588(((struct Obj00434 *)p)->f0) == 3) {
                    sub = (u8)((Record_td *)(p + 0xbc))->sub;
                    slot = func_021B9AB0(sub);
                    m = *(void **)((u32)p + slot * 8U + 0xa4U);
                }
                if (func_021D832C((struct Unk021D82FC *)record)) {
                    p[0x1b0] = slot;
                    p[0x1b1] = func_021D5778(m, (u16)((Record_td *)record)->id);
                    if (p[0x1b1] != 4) {
                        func_021CE150(p, (void *)((u32)func_021CED4C));
                        return 0;
                    }
                }
                if (func_021CF5B0(p, m, (u16)((Record_td *)record)->id, p + 0x58)) {
                    func_021EAF78(p + 0x58, 0xff);
                    func_021CE3B4(p, p + 0x58);
                    *state = 7;
                } else {
                    if (func_021B8588(((struct Obj00434 *)p)->f0) == 3 && sub != 0 && sub != 1 && !func_021D5B68(m)) {
                        k = func_021D8340((u32 *)(p + 0xc0));
                        record = *(u32 * *)&((struct Obj00434 *)p)->fC;
                        *(u32 *)&((struct Obj00434 *)p)->fC = (u32)record + 4U;
                        func_021D83FC(record, sub);
                        func_021D82D0(((struct Obj00434 *)p)->fC, k, 6);
                        ++p[0x1af];
                    }
                    *state = 4;
                }
            }
        }
        break;
    case 4:
        if (func_021D7EF0(func_021B8588(((struct Obj00434 *)p)->f0))) *state = 5;
        else func_021CE150(p, (void *)((u32)func_021CF220));
        break;
    case 5:
        func_021E98BC(((struct Obj00434 *)p)->f54, (u8 *)(*(u32 *)&((struct Obj00434 *)p)->f8), *(u32 *)&((struct Obj00434 *)p)->fC);
        *state = 6;
        break;
    case 6:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E9920(((struct Obj00434 *)p)->f54);
            return 0;
        }
        k = func_021E98E8(((struct Obj00434 *)p)->f54);
        if (k == 1) func_021CE150(p, (void *)((u32)func_021CF220));
        else if (k == 2) *state = 1;
        break;
    case 7:
        if (func_021EA710(((struct Obj00434 *)p)->f54)) {
            func_021E9858(((struct Obj00434 *)p)->f54);
            *state = 3;
        }
        break;
    }
    return 0;
}






void func_021CECB4(u8 *p, Ent_021CECB4 *out)
{
    u32 i;
    u32 j;
    u8 *q;
    u32 n;
    u32 k;
    Ent_021CECB4 *e;
    for (i = 0; i < 3; i++) {
        q = func_021B9C00(((struct Obj21136 *)p)->f118, (u8)i);
        e = out + i;
        e->q = q;
        for (j = 0; j < 4; j++) {
            e->f[j] = 0;
        }
        if (func_021D5B68(q) == 0) {
            n = func_021D5448((struct QG *)q);
            for (k = 0; k < n; k++) {
                if (func_021D5584((struct UtilWork *)q, (u8)k) == 0 || func_021CF5B0(p, q, (u32)func_021D54C0(q, (u8)k), 0) != 0) {
                    e->f[k] = 0;
                } else {
                    e->f[k] = 1;
                }
            }
        }
    }
}






u32 func_021CED4C(u8 *p, s32 *st)
{
    u32 r;
    switch (*st) {
    case 0:
        func_021E9CE0((u8 *)(((struct Obj05199 *)p)->f54), p[0x1b0], p[0x1b1]);
        *st = *st + 1;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0) != 0) {
            func_021E9B14((unsigned int *)(((struct Obj05199 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CEA94));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CE3C8));
        }
        break;
    }
    return 0;
}






u32 func_021CEDC0(u8 *p, int *st)
{
    u8 a;
    u16 b;
    u32 r, n;
    switch (*st) {
    case 0:
        r = 0;
        if ((u8)func_021CF8D4(p, ((struct Obj03194 *)p)->f8, &a, &b) != 4 ||
            a == func_021D5440(((struct Obj03194 *)p)->f8)) r = 1;
        func_021E9A78(*(char * *)&((struct Obj03194 *)p)->f54, p + 0x184, p[0x11d], r, p + 0x190);
        ++*st;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9B14((unsigned int *)(*(u32 *)&((struct Obj03194 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) {
            if (func_021CEE98(p + 0x190) == 0) {
                n = func_021CEEA8(p + 0x190);
                if (n < 6) {
                    func_021D8394(((struct Obj03194 *)p)->fC, p[0x11d], n);
                    func_021CE150(p, (void *)((u32)func_021CF220));
                    break;
                }
            }
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}










static inline u8 same_index(u8 *p)
{
    return p[0x11d] == p[0x11f] ? 1 : 0;
}










/*
 * lever: u16 b/d retain the spilled reload and narrow only at the u8 call;
 *        enum same retains the early ternary truncation.
 */
u32 func_021CEEB8(u8 *p, int *st)
{
    u32 a, c, z;
    u16 b, d;
    Value same;
    u32 flag;
    switch (*st) {
    case 0:
        a = func_021CF448(p);
        same = same_index(p);
        flag = (u8)func_021CEFFC(p);
        func_021E9D04(((struct Obj00967 *)p)->f54, p[0x1aa], p[0x1ab], a, same, flag);
        ++*st;
        break;
    case 1:
        z = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9E70(((struct Obj00967 *)p)->f54);
            *st = 2;
            return z;
        }
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) {
            a = func_021EA01C(((struct Obj00967 *)p)->f54);
            b = func_021EA044(((struct Obj00967 *)p)->f54);
            if (a && b != 6) {
                c = func_021EA030(((struct Obj00967 *)p)->f54);
                d = func_021EA04C(((struct Obj00967 *)p)->f54);
                if (p[0x1ab] >= c) p[0x1ab] = p[0x1ab] - c;
                else {
                    p[0x1ab] = z;
                    c = p[0x1ab];
                }
                func_021CF430(p, p[0x11d], c);
                func_021D8358(((struct Obj00967 *)p)->fC, a, (u8)b, (u8)d);
                func_021EA058(((struct Obj00967 *)p)->f54);
                if (func_021D805C((void *)a, 0xf) == 4) p[0x1b2] |= 4;
                func_021CF37C(p, p[0x11d], a);
                func_021CE150(p, (void *)((u32)func_021CF220));
            } else func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}










u32 func_021CEFFC(u8 *p)
{
    char *arr;
    u32 lim;
    u32 flag;
    u32 i;
    u32 c;
    u8 *w;
    u32 cnt;
    if (func_021B86B8(*(void *** *)&((struct Obj09993 *)p)->f0) == 0) {
        arr = func_021B9AF8(*(char * *)&((struct Obj09993 *)p)->f4, 1);
        cnt = func_021B9B94((struct Q1 *)arr);
        lim = func_021B8670((unsigned int **)(*(void *** *)&((struct Obj09993 *)p)->f0));
        if (lim > cnt) {
            lim = cnt;
        }
        flag = 0;
        c = 0;
        for (i = 0; i < lim; i++) {
            w = func_021B9C00((struct S2 *)arr, (u8)i);
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









u32 func_021CF078(u8 *p, u32 *st)
{
    u8 id;
    u16 k;
    int result;
    switch (*st) {
    case 0:
        switch (func_021B86E4(((struct Obj02136 *)p)->f0)) {
        default:
        case 0:
            if (func_021CF918(p, &id, &k) == 4) {
                *st = 5;
                break;
            }
            if (k) {
                func_021EAF18((struct L *)(p + 0x58), 2, 0x365);
                func_021EAF50((struct L *)(p + 0x58), id);
                func_021EAF50((struct L *)(p + 0x58), k);
            } else {
                func_021EAF18((struct L *)(p + 0x58), 1, 0x4a);
            }
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 1:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4c);
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 2:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4d);
            func_021EAF78(p + 0x58, 0xff);
            func_021CE3B4(p, p + 0x58);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            func_021CE0F8(p, *(u8 * *)&((struct Obj02136 *)p)->f8, p + 0x58);
            func_021EA65C(((struct Obj02136 *)p)->f54, (struct H *)(p + 0x58));
            *st = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj02136 *)p)->f54))
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        break;
    case 3:
        func_021EA710(((struct Obj02136 *)p)->f54);
        if (func_021EA720(((struct Obj02136 *)p)->f54)) {
            func_021EAF18((struct L *)(p + 0x58), 3, 8);
            func_021EAF18((struct L *)(p + 0x7c), 3, 9);
            func_021EABC4(((struct Obj02136 *)p)->f54, (u32)(p + 0x58), (u32)(p + 0x7c), 1);
            *st = 4;
        }
        break;
    case 4:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            if (func_021EAC54(((struct Obj02136 *)p)->f54, &result)) {
                if (result == 0)
                    *st = 5;
                else
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
            } else if (func_021CE08C(p)) {
                func_021CE150(p, (void *)((u32)func_021CE3C8));
            }
        }
        break;
    case 5:
        func_021D8414(((struct Obj02136 *)p)->fC);
        p[0x1b2] |= 4;
        func_021CE150(p, (void *)((u32)func_021CF220));
        break;
    }
    return 0;
}









u32 func_021CF220(u8 *p, int *st)
{
    u8 n;
    void *q;
    switch (*st) {
    case 0:
        func_021E9964(((struct Obj00888 *)p)->f54);
        ++*st;
        break;
    case 1:
        if (func_021E9974(((struct Obj00888 *)p)->f54)) {
            ++p[0x11d];
            if (p[0x11d] < p[0x11c]) {
                if ((((u32)p[0x1b2] << 29) >> 31) == 0) {
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
                    break;
                }
                while (p[0x11d] < p[0x11c]) {
                    q = func_021B990C((char *)(((struct Obj00888 *)p)->f4), p[0x1a6], p[0x11d]);
                    if (!func_021CF470(p, q, p + 0x124 + p[0x11d] * 4))
                        func_021D8434((u32 *)(p + 0x124 + p[0x11d] * 4));
                    ++p[0x11d];
                }
            }
            if (p[0x11d] >= p[0x11c]) {
                n = p[0x11c] + p[0x1af];
                p[0x1af] = 0;
                *(u8 * *)&((struct Obj00888 *)p)->fD8 = p + 0x124;
                ((struct Obj00888 *)p)->fDC = n * 4;
                func_021CE150(p, (void *)((u32)func_021CF2F0));
            }
        }
        break;
    }
    return 0;
}










u32 func_021CF2F0(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CF3F8(p);
        if (func_021B86C0(*(u8 ** *)&((struct Obj07772 *)p)->f0) != 0) {
            p[0x1a9] = 1;
            func_021EA7FC((char *)(*(u32 *)&((struct Obj07772 *)p)->f54));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (func_021EA814(*(u32 * *)&((struct Obj07772 *)p)->f54) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021CE0E0(p);
            *st = *st + 1;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}









void func_021CF360(u8 *p) { u32 i; for(i=0;i<3;i++) *(u16 *)(p+0x1a0+i*2)=0; }









void func_021CF37C(u8 *p,u32 i,u32 v) { if(p[0x1aa]==0) { if(p[0x1a6]==func_021B8FF4(*(u8 * *)&((struct Obj06234 *)p)->f0)) { *(u16 *)(p+0x1a0+i*2)=v; func_021B9090(*(u8 * *)&((struct Obj06234 *)p)->f0,p[0x1a6],v); } } }









/*
 * lever: func_021B90BC consumes the live r2 halfword as its third argument;
 * its matched body forwards it to func_02007E50.
 */
void func_021CF3B8(u8 *p, u32 i)
{
    if (p[0x1aa] == 0) {
        if (p[0x1a6] == func_021B8FF4(*(u8 * *)&((struct Obj05200 *)p)->f0)) {
            u16 *a = (u16 *)(p + 0x1a0);
            u32 v = a[i];
            if (v != 0) {
                a[i] = 0;
                func_021B90BC(*(u8 * *)&((struct Obj05200 *)p)->f0, p[0x1a6], v);
            }
        }
    }
}









void func_021CF3F8(u8 *p) { u32 i; if(p[0x1aa]==0) for(i=0;i<3;i++) func_021CF3B8(p,(u8)i); }









void func_021CF41C(u8 *p) { func_02082BCC(p+0x130,0,3); }








/*
 * follower: unlabelled byte accessor at 0x021CF43C.
 */
void func_021CF430(u8 *p, u32 i, u32 v)
{
    (p + i)[0x130] = v;
}








u8 func_021CF43C(u8 *p, u32 i)
{
    return (p + i)[0x130];
}








u8 func_021CF448(u8 *p)
{
    u32 i;
    u32 sum;
    u32 n;
    sum = 0;
    n = p[0x11d];
    i = 0;
    for (; i < n; i++) sum += p[0x130+i];
    return sum;
}









u32 func_021CF470(u8 *p, void *q, u8 *o)
{
    u32 id;
    u32 a;
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









u32 func_021CF524(u32 x, void *q, u32 y)
{
    u32 n = func_021D5448(q);
    u32 c = 0;
    u32 i = 0;
    for (; i < n; i++) {
        if (func_021CF5B0((u8 *)x, q, (u32)func_021D54C0(q, (u8)i), 0) == 0) {
            if ((u32)func_021D5584(q, (u8)i) != 0) {
                c++;
            }
        }
    }
    if (c == 0) {
        func_021CF58C((struct Unk021D82D0 *)y, (u8 *)x, q);
        return 1;
    }
    return 0;
}








void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q)
{
    u32 v;
    v = func_021D81F8(((struct Obj01894 *)p)->f0, ((struct Obj01894 *)p)->f4, q, 165, p+0x38);
    func_021D82D0(out, 165, v);
}








int func_021CF5B0(u8 *g, void *m, u32 move, void *out)
{
    u32 k;
    u32 k2;
    union Slot w;
    if (move == 0xa5) return 0;
    if (func_021CF89C(g, m) && func_021D62C4(m, 0x1b)) {
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
    if (func_021D62C4(m, 0xb) && func_0201C314((void *)move) == 0) {
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
    if (func_021D62C4(m, 0xf) && func_0201BEB8(move, 0xc)) {
        if (out) {
            func_021EAF18(out, 2, 0x37a);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 3) && func_021EFC1C(*(int *)&((struct Obj01894 *)g)->f34, *(int *)&((struct Obj01894 *)g)->f4, m, move)) {
        if (out) {
            func_021EAF18(out, 2, 0x24d);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) && func_0201BEB8(move, 9)) {
        if (out) {
            func_021EAF18(out, 2, 0x43e);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    return 0;
}









u32 func_021CF81C(u8 *p, void *q, u8 *out)
{
    u8 n = func_021D5448(q);
    u32 r = 4;
    u8 i = 0;
    for (; i < n; i++) {
        if (func_021D5584(q, i) != 0) {
            out[i] = (func_021CF5B0(p, q, func_021D54C0(q, i), 0) == 0) ? 1 : 0;
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








int func_021CF89C(u8 *p, void *q)
{
    if (func_021EFCE4(*(char * *)&((struct Obj01894 *)p)->f34, 7)) return 0;
    if (func_021D62C4(q, 19)) return 0;
    if (func_021D59B4(q, 17) != 103) return 1;
    return 0;
}









u32 func_021CF8D4(u8 *p, void *q, u8 *a, u16 *b)
{
    u32 r;
    if (func_021CF89C(p, q) != 0) {
        if (func_021D5B40(q) == 0x127) {
            return 4;
        }
    }
    r = func_021CF9B4(p, q, a, b);
    if (r == 4) {
        *a = 0x1f;
        *b = 0;
        r = 4;
    }
    return r;
}









u32 func_021CF918(u8 *g, u8 *a, u16 *b)
{
    u32 i;
    u8 *m;
    u32 r;

    for (i = 0; i < g[0x11c]; i++) {
        m = func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i);
        if (func_021D5B68(m) == 0) {
            if (func_021CF89C(g, m) != 0 && func_021D5B40((struct QI *)m) == 0xe4)
                return 4;
            if (func_021D59B4(m, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < g[0x11c]; i++) {
        r = func_021CF9B4(g, func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i), a, b);
        if (r != 4)
            return r;
    }
    return 4;
}








u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *q;
    u16 k;
    n = func_021B8D38(((struct Obj01894 *)g)->f0, *(int *)&((struct Obj01894 *)g)->f4, (u16)(func_021B8D8C(((struct Obj01894 *)g)->f0, ((struct Obj01894 *)g)->f4, func_021D5440(m)) | 0x100), buf);
    for (i = 0; i < n; i++) {
        q = func_021B9934(((struct Obj01894 *)g)->f4, buf[i]);
        k = func_021D59B4(q, 0x11);
        func_021D5440(q);
        if (k == 0x17 && func_021CFAC4(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x47 && func_021CFADC(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x2a && func_021CFB8C(g, m)) {
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









int func_021CFADC(u8 *g, void *m)
{
    u32 a;

    a = func_021CF89C(g, m);
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) != 0)
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
void func_021CFBA4(s8 *p)
{
    u32 i = 0;
    s8 fill = -1;
    for (; i < 6; i++) p[0x10c+i] = fill;
}







int func_021CFBBC(s8 *p, int v)
{
    u32 i = 0;
    for (; i < 6; i++) {
        if ((p+i)[0x10c] == v) return 1;
    }
    return 0;
}







void func_021CFBE0(u8 *p, u32 i, u32 v)
{
    if (i < 6) (p + i)[0x10c] = v;
}







int func_021CFBF0(u8 *g, void *m, u32 slot, u8 *out)
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
    if (func_021CF8D4(g, m, &id, &k) != 4) return 0;
    if (func_021B9B98(((struct Obj00489 *)g)->f118) <= g[0x11c]) return 0;
    q = func_021CFD50((struct G_021CFD50 *)g, func_021B8D8C(((struct Obj00489 *)g)->f0, ((struct Obj00489 *)g)->f4, func_021D5440(m)));
    if (!q) return 0;
    if (func_021D6C24((struct R4 *)q))
        q = func_021B937C(*(void **)&((struct Obj00489 *)g)->f0, *(char * *)&((struct Obj00489 *)g)->f4, q);
    if (func_021CFDCC(g, m)) ok = 1;
    else if (func_021CFE08((struct G_021CFE08 *)g, m, q)) ok = 1;
    else if (func_021CFE98((struct G_021CFE98 *)g, m, q)) ok = 1;
    else if (func_021CFFAC((struct G_021CFFAC *)g, m, q)) ok = 1;
    else if (func_021D0100((struct G_021D0100 *)g, m, q, &choice)) ok = 1;
    else if (func_021D0248((struct G_021D0248 *)g, m, &choice)) ok = 1;
    else if (func_021D0304((struct G_021D0304 *)g, m, q, &choice)) ok = 1;
    else return 0;
    if (!ok) return 0;
    if (choice == 6) {
        n = func_021D0980(g, buf);
        func_021D09E0(g, buf, n, q);
        for (i = 0; i < n; i++) {
            if (!func_021CFBBC((s8 *)g, buf[i])) {
                choice = buf[i];
                break;
            }
        }
    }
    if (choice == 6) return 0;
    func_021CFBE0(g, slot, choice);
    *out = choice;
    return 1;
}







u8 *func_021CFD50(struct G_021CFD50 *g, int k)
{
    u8 buf[4];
    u8 n;
    u32 v;

    n = func_021B8D38(g->p0, (int)g->p1, (u16)(k | 0x100), buf);
    if (n) {
        g->seed = g->mul * g->seed + g->add;
        if (n == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)n) >> 32);
        }
        return func_021B9934(g->p1, buf[(u8)v]);
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







int func_021CFE08(struct G_021CFE08 *g, void *a, void *b)
{
    if (func_021B8588(g->p0) != 0)
        return 0;
    if (func_021D59B4(b, 0x11) == 0x19) {
        if (func_021D0644(g, a, b, 4) == 0 && func_021D055C((u8 *)g, b, 4) != 0) {
            g->seed = g->mul * g->seed + g->add;
            if ((u32)(((g->seed >> 32) * 3) >> 32) < 2)
                return 1;
        }
    }
    return 0;
}






/*
 * extent: two zero padding bytes at 0x021CFFAA, followed by labelled func_021CFFAC.
 */
int func_021CFE98(struct G_021CFE98 *g, void *a, void *b)
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
        if (func_0201C314((void *)v)) {
            if (func_021D799C(func_0201C1C8((void *)v), k))
                return 0;
            c++;
        }
    }
    if (c >= 2) {
        if (func_021D055C((u8 *)g, b, 4)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
        }
        if (func_021D055C((u8 *)g, b, 3)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
        }
    }
    return 0;
}





int func_021CFFAC(struct G_021CFFAC *g, void *mon, void *target)
{
    u32 id;
    int valid;
    u32 kind;
    union Slot slot;
    if (func_021D62C4(mon, 0x1b)) {
        slot = func_021D6314(mon, 0x1b);
        id = func_021E8B80(slot);
        if (id) {
            valid = func_0201C314((void *)id);
            kind = func_0201C1C8((void *)id);
            if (func_021D799C(kind, func_021D57FC(target)) == 0 && valid) {
                if (func_021D055C((u8 *)g, target, 4)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
                }
                if (func_021D055C((u8 *)g, target, 3)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
                }
            }
            if (!valid) {
                g->seed = g->mul * g->seed + g->add;
                return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
            }
        }
    }
    return 0;
}





int func_021D0100(struct G_021D0100 *g, void *mon, void *target, u8 *out)
{
    u16 hist[5];
    u32 i;
    u8 pos;
    u32 j;
    const struct Row *row;
    pos = 0;
    if (func_021D0644(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) return 0;
    }
    while (func_021D6940(mon, 1, pos++, hist + 1)) {
        for (i = 0; i < 4; i++) {
            row = &d_021EFFC2[i];
            if (((u8 *)hist)[6] == row->kind) {
                for (j = 0; j < 4; j++) {
                    if (!row->ids[j]) break;
                    if (func_021D04E4((u8 *)g, row->ids[j], (u8 *)hist)) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
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






int func_021D0248(struct G_021D0248 *g, void *m, u8 *out)
{
    u16 t[4];
    u8 idx;

    if (func_021D59B4(m, 0x11) == 0x1e) {
        if (func_021D62C4(m, 2) || func_021D62C4(m, 3)) {
            if (func_021D5C44(m) >= 0x32000) {
                if (func_021D6940(m, 1, 0, t)) {
                    if (func_021D05C4((u8 *)g, ((u8 *)t)[4], 2, &idx)) {
                        *out = idx;
                        return 1;
                    }
                } else {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) ? 0 : 1;
                }
            }
        }
    }
    return 0;
}





int func_021D0304(struct G_021D0304 *g, void *mon, void *target, u8 *out)
{
    u16 hist[4];
    u32 sum;
    u32 i;
    u32 n;
    u8 *other;
    int affinity;
    if (func_021D0644(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 10) >> 32) != 0) return 0;
    }
    sum = 0;
    for (i = 1; i <= 7; i++) sum += func_021D59B4(mon, i);
    if (sum >= 4) return 0;
    if (func_021D6940(mon, 1, 0, hist)) {
        n = func_021B9B94(g->list);
        i = func_021D7F2C(func_021B8588(g->p0), g->start);
        for (; i < n; i++) {
            if (!func_021CFBBC((s8 *)g, (u8)i)) {
                other = func_021B9C00(g->list, (u8)i);
                if (func_021D0644(g, other, target, 4)) {
                    affinity = func_021D799C(((u8 *)hist)[4], func_021D57FC(other));
                    if (affinity == 0) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    } else if (affinity < 3) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) {
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






int func_021D04E4(u8 *g, u16 a, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj01690 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj01690 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj01690 *)g)->f118, (u8)i);
            if (func_021D5B68(m) == 0 && a == func_021D59B4(m, 0x11)) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}






int func_021D055C(u8 *g, void *a, int b)
{
    u32 n;
    u32 i;

    n = func_021B9B94(((struct Obj00340 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj00340 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            if (func_021D0644(g, func_021B9C00(((struct Obj00340 *)g)->f118, (u8)i), a, b))
                return 1;
        }
    }
    return 0;
}






int func_021D05C4(u8 *g, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj03197 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj03197 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj03197 *)g)->f118, (u8)i);
            if (func_021D5B7C(m) != 0 && func_021D799C(a, func_021D57FC(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}






int func_021D0644(void *g, void *m, void *a, int b)
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
            if (func_021D5584(m, (u8)i) && func_0201C314((void *)q)
                && func_021CF5B0(g, m, q, 0) == 0) {
                if (func_021D799C(func_0201C1C8((void *)q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}






u8 func_021D06C8(struct G *g)
{
    u8 buf[2];
    u32 cnt;
    u32 v;

    cnt = 1;
    buf[0] = 1;
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(2))) == 0) {
        buf[cnt++] = 2;
    }
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(3))) == 0) {
        buf[cnt++] = 3;
    }
    if (cnt > 1) {
        g->seed = g->mul * g->seed + g->add;
        if (cnt == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)cnt) >> 32);
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
int func_021D0770(u8 *p, u32 *state)
{
    u8 available[4];
    u8 choice;
    u32 move;
    u32 slot;
    u32 sub;
    u32 result;
    u32 count;
    u32 bytes;
    switch (*state) {
    case 0:
        func_021CFBA4((s8 *)p);
        p[0x11d] = 0;
        p[0x1af] = 0;
        *state = 1;
    case 1:
        if (p[0x11d] >= p[0x11c]) break;
        (*(void **)(p+8)) = func_021B9C00(((struct Obj00464 *)p)->f118, p[0x11d]);
        (*(u8 **)(p+12)) = p+0x124+p[0x11d]*4;
        if (func_021D5B68((*(void **)(p+8)))) {
            func_021D8434((u32 *)(*(u8 **)(p+12)));
            goto complete;
        }
        if (func_021CF470(p,(*(void **)(p+8)),(*(u8 **)(p+12)))) goto complete;
        move = func_021D3DC4(p,(*(void **)(p+8)),((struct Obj00464 *)p)->f118);
        if (move) {
            func_021D8358((u32 *)(*(u8 **)(p+12)),move,p[0x11d],0);
            goto complete;
        }
        if (func_021B86B8(*(void *** *)&((struct Obj00464 *)p)->f0) && func_021CFBF0(p,(*(void **)(p+8)),p[0x11d],&choice)) {
            func_021D8394((*(u8 **)(p+12)),p[0x11d],choice);
            goto complete;
        }
        if (func_021B8588(((struct Obj00464 *)p)->f0) == 3) {
            slot = func_021D06C8((struct G *)p);
            if (slot != 1) {
                sub = func_021B9AB0(slot);
                func_021D83FC((u32 *)(*(u8 **)(p+12)),slot);
                (*(void **)(p+8)) = func_021B9C00(((struct Obj00464 *)p)->f118,sub);
                p[0x1af] = 1;
                (*(u8 **)(p+12)) = (u8 *)((u32)(*(u8 **)(p+12))+4U);
            }
        }
        if (func_021D62C4((*(void **)(p+8)),0x19)) {
            move = func_021E8B80(func_021D6314((*(void **)(p+8)),0x19));
            result = func_021D81F8(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,(*(void **)(p+8)),move,p+0xf4);
            func_021D82D0((struct Unk021D82D0 *)(*(u8 **)(p+12)),move,result);
            goto complete;
        }
        if (func_021CF524((u32)p,(*(void **)(p+8)),(u32)(*(u8 **)(p+12)))) *state = 3;
        func_021D5448((*(void **)(p+8)));
        slot = func_021CF81C(p,(*(void **)(p+8)),available);
        if (slot != 4) {
            result = func_021B8D8C(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,func_021D5440((*(void **)(p+8))));
            func_021880BC(*(int *)&((struct Obj00464 *)p)->fF0,available,result);
            *state = 2;
        } else {
            func_021CF58C((struct Unk021D82D0 *)((u32)(*(u8 **)(p+12))),(u8 *)((u32)p),(*(void **)(p+8)));
            goto complete;
        }
        break;
    case 2:
        if (func_02187FB0(*(u8 * *)&((struct Obj00464 *)p)->fF0)) break;
        slot = func_02188134(*(u8 * *)&((struct Obj00464 *)p)->fF0);
        if (slot != 4) {
            sub = func_02188140(*(u8 * *)&((struct Obj00464 *)p)->fF0);
            move = func_021D54C0((*(void **)(p+8)),slot);
            func_021D82D0((struct Unk021D82D0 *)(*(u8 **)(p+12)),move,sub);
        } else func_021D8414((u32 *)(*(u8 **)(p+12)));
complete:
        *state = 3;
        break;
    case 3:
        p[0x11d]++;
        count = p[0x11c];
        if (p[0x11d] >= count) {
            bytes = (count+p[0x1af])*4;
            *(u8 * *)&((struct Obj00464 *)p)->fD8 = p+0x124;
            ((struct Obj00464 *)p)->fDC = bytes;
            p[0x1af] = 0;
            return 1;
        }
        *state = 1;
        break;
    }
    return 0;
}






u8 func_021D0980(u8 *g, u8 *out)
{
    u32 n;
    u8 c;
    u32 i;

    n = func_021B9B94(((struct Obj00489 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj00489 *)g)->f0), g[0x11c]);
    c = 0;
    for (; i < n; i = (u8)(i + 1)) {
        if (func_021D5B7C(func_021B9C00(((struct Obj00489 *)g)->f118, i))) {
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
void func_021D09E0(u8 *p, u8 *order, u8 count, void *target)
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
        mon = func_021B9C00(*(void **)(p + 0x118), order[i]);
        if (!func_021D5B68(mon)) {
            u8 n;
            n = func_021D5448(mon);
            for (j = 0; j < n; j++) {
                if (func_021D5584(mon, j)) {
                    move = func_021D54C0(mon, j);
                    if (func_0201C314((void *)(u32)move)) {
                        int kind;
                        kind = func_0201C1C8((void *)(u32)move);
                        power = func_0201C1D8((void *)(u32)move);
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



void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out)
{
    func_021D0B3C(q, ((struct Obj13364 *)p)->f118, b, a);
    func_021D0B4C(q, p[0x11c]);
    func_021D0B5C(out, q);
}
