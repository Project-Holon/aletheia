/*
 * file:     btl_server.c
 * unit:     yes
 * function: func_021B8CB0, func_021B8CE8, func_021B8CFC, func_021B8D08, func_021B8D38, func_021B8D8C, func_021B8DC0, func_021B8DDC, func_021B8DE4, func_021B8DEC, func_021B8E28, func_021B8E70, func_021B8ED8, func_021B8F38, func_021B8F5C, func_021B8F7C, func_021B8FC0, func_021B8FE4, func_021B8FF4, func_021B9000, func_021B9010, func_021B902C, func_021B904C, func_021B9064, func_021B9090, func_021B90BC, func_021B90E8, func_021B90F0, func_021B90F8, func_021B9114, func_021B911C, func_021B9120, func_021B916C, func_021B917C, func_021B9184, func_021B919C, func_021B91E4, func_021B9210, func_021B9234, func_021B9244, func_021B92A0, func_021B92B0, func_021B92D4, func_021B9358, func_021B937C, func_021B93E0, func_021B9424, func_021B9460, func_021B9634, func_021B9674, func_021B969C, func_021B97A0, func_021B985C, func_021B9864, func_021B98A4, func_021B98AC, func_021B990C, func_021B9920, func_021B9934, func_021B9940, func_021B994C, func_021B997C, func_021B99B8, func_021B99C0, func_021B99E0, func_021B99F0, func_021B9A00, func_021B9A24, func_021B9A40, func_021B9A50, func_021B9A5C, func_021B9A6C, func_021B9AB0, func_021B9AC8, func_021B9AE0, func_021B9AEC, func_021B9AF8, func_021B9B04, func_021B9B10, func_021B9B40, func_021B9B54, func_021B9B60, func_021B9B94, func_021B9B98, func_021B9BC4, func_021B9BF0, func_021B9C00, func_021B9C10, func_021B9C24, func_021B9C50, func_021B9C98, func_021B9CBC, func_021B9CE8, func_021B9D10, func_021B9DB8, func_021B9DE8, func_021B9E38, func_021B9E7C, func_021B9EF0, func_021B9F70, func_021B9F84, func_021B9FAC, func_021B9FBC, func_021BA004, func_021BA020, func_021BA02C, func_021BA064, func_021BA080, func_021BA08C, func_021BA094, func_021BA0CC, func_021BA128, func_021BA178, func_021BA1A8, func_021BA1B4, func_021BA1CC, func_021BA1E4, func_021BA1EC, func_021BA20C, func_021BA238, func_021BA250, func_021BA2D4, func_021BA2E4, func_021BA534, func_021BA54C, func_021BA5C4, func_021BA5D0, func_021BA5D8, func_021BA618, func_021BA648, func_021BA670, func_021BA698, func_021BA6C0, func_021BA710, func_021BA73C, func_021BA7F8, func_021BA820, func_021BA82C, func_021BA878, func_021BA9C8, func_021BAA94, func_021BAACC, func_021BAB10, func_021BAB40, func_021BAB5C, func_021BAB9C, func_021BABDC, func_021BABEC, func_021BABF4, func_021BAC04, func_021BACAC, func_021BAE60, func_021BAEF8, func_021BB040, func_021BB0A0, func_021BB0E0, func_021BB208, func_021BB280, func_021BB320, func_021BB368, func_021BB3B0, func_021BB3F8, func_021BB43C, func_021BB484, func_021BB4E0, func_021BB56C, func_021BB570, func_021BB5FC, func_021BB628, func_021BB650, func_021BB6A8, func_021BB718, func_021BB724, func_021BB768, func_021BB798, func_021BB7D0, func_021BB7FC, func_021BB828, func_021BB830, func_021BB840, func_021BB848, func_021BB85C, func_021BB878, func_021BB890, func_021BB8A8, func_021BB8B0, func_021BB8BC, func_021BB8DC, func_021BB908, func_021BB914, func_021BB920, func_021BB930, func_021BB964, func_021BB968, func_021BB9D0, func_021BB9D8, func_021BBB48, func_021BBB60, func_021BBC34, func_021BBC44, func_021BBCD4, func_021BBD20, func_021BBD2C, func_021BBD80, func_021BBD8C, func_021BBFA8, func_021BC0E8, func_021BC220, func_021BC2B0, func_021BC310, func_021BC360, func_021BC390, func_021BC3B0, func_021BC418, func_021BC4DC, func_021BC550, func_021BC55C, func_021BC568, func_021BC610, func_021BC874, func_021BC8EC, func_021BC948, func_021BCA08, func_021BCA50, func_021BCAAC, func_021BCB14, func_021BCB68, func_021BCB98, func_021BCC50, func_021BCCE0, func_021BCEFC, func_021BCF34, func_021BCF70, func_021BCFAC, func_021BD080, func_021BD0C0, func_021BD148, func_021BD170, func_021BD1B0, func_021BD1D0, func_021BD1E0, func_021BD200, func_021BD2B4, func_021BD338, func_021BD34C, func_021BD3E8, func_021BD43C, func_021BD4E4, func_021BD518, func_021BD554, func_021BD584, func_021BD60C, func_021BD6B8, func_021BD708, func_021BD850, func_021BD8AC, func_021BD8F0, func_021BD9D4, func_021BDA00, func_021BDB88, func_021BDBB8, func_021BDBEC, func_021BDC0C, func_021BDC2C, func_021BDC58, func_021BDC78, func_021BDC98, func_021BDD00, func_021BDD7C, func_021BDE18, func_021BDE48, func_021BDE98, func_021BE3A8, func_021BE400, func_021BE518, func_021BE52C, func_021BE550, func_021BE620, func_021BE66C, func_021BE6A8, func_021BE6EC, func_021BE7E4, func_021BE878, func_021BE8C4, func_021BE8F4, func_021BE924, func_021BE95C, func_021BE994, func_021BE9D0, func_021BEA14, func_021BEA60, func_021BEAB4, func_021BEB14, func_021BEBD8, func_021BEC08, func_021BEC2C, func_021BEC58, func_021BF04C, func_021BF0E4, func_021BF168, func_021BF1B4, func_021BF244, func_021BF27C, func_021BF2B4, func_021BF2EC, func_021BF324, func_021BF3D8, func_021BF4AC, func_021BF6E8, func_021BF78C, func_021BF83C, func_021BF8D4, func_021BF9A4, func_021BFA00, func_021BFA60, func_021BFBD0, func_021BFC08, func_021BFD24, func_021BFE60, func_021BFEAC, func_021BFF60, func_021C001C, func_021C024C, func_021C0274, func_021C02CC, func_021C031C, func_021C03AC, func_021C03D8, func_021C0404, func_021C0450, func_021C0520, func_021C0780, func_021C07AC, func_021C07D4, func_021C0898, func_021C08CC, func_021C091C, func_021C0A4C, func_021C0C34, func_021C0C38, func_021C0CB4, func_021C0CE8, func_021C0D70, func_021C0D90, func_021C0F24, func_021C1184, func_021C1194, func_021C1198, func_021C11A4, func_021C11F0, func_021C14E0, func_021C15AC, func_021C15D4, func_021C15E8, func_021C1624, func_021C1678, func_021C16F8, func_021C1758, func_021C1788, func_021C17CC, func_021C1828, func_021C1880, func_021C18D4, func_021C1910, func_021C195C, func_021C199C, func_021C19D8, func_021C1A10, func_021C1A54, func_021C1B5C, func_021C1C88, func_021C1CCC, func_021C1CE4, func_021C1D60, func_021C1DCC, func_021C1E14, func_021C1E74, func_021C2048, func_021C20BC, func_021C20D0, func_021C2128, func_021C2204, func_021C2250, func_021C2314, func_021C232C, func_021C236C, func_021C2488, func_021C25A4, func_021C264C, func_021C26A8, func_021C26FC, func_021C2758, func_021C27A0, func_021C282C, func_021C2910, func_021C2AB0, func_021C2AF0, func_021C2B3C, func_021C2BA4, func_021C2BF0, func_021C2C50, func_021C2CA8, func_021C2CD8, func_021C2D10, func_021C2DC4, func_021C2E4C, func_021C2E64, func_021C2F70, func_021C3008, func_021C312C, func_021C3184, func_021C3274, func_021C334C, func_021C3370, func_021C3394, func_021C33E8, func_021C3438, func_021C36A0, func_021C36E8, func_021C3720, func_021C376C, func_021C3810, func_021C39CC, func_021C39F4, func_021C3A4C, func_021C3AA8, func_021C3B68, func_021C3B8C, func_021C3BB8, func_021C3BE0, func_021C3C10, func_021C3C60, func_021C3CCC, func_021C3D08, func_021C3E0C, func_021C3FDC, func_021C4034, func_021C4104, func_021C41C0, func_021C4218, func_021C4268, func_021C4304, func_021C43F0, func_021C446C, func_021C4614, func_021C4744, func_021C4838, func_021C4910, func_021C493C, func_021C4A64, func_021C4B3C, func_021C4B8C, func_021C4B9C, func_021C4BAC, func_021C4C24, func_021C4C40, func_021C4C50, func_021C4D1C, func_021C4E38, func_021C4EA4, func_021C4F64, func_021C5098, func_021C5108, func_021C51D0, func_021C5200, func_021C5308, func_021C5350, func_021C5418, func_021C5474, func_021C5480, func_021C54BC, func_021C54C8, func_021C54FC, func_021C5540, func_021C557C, func_021C5604, func_021C5620, func_021C56A8, func_021C5718, func_021C572C, func_021C5750, func_021C5774, func_021C5798, func_021C5840, func_021C59C4, func_021C5A1C, func_021C5A34, func_021C5A4C, func_021C5A8C, func_021C5B74, func_021C5BE4, func_021C5C1C, func_021C5C74, func_021C5D88, func_021C5DAC, func_021C5E48, func_021C5EFC, func_021C5F98, func_021C604C, func_021C6080, func_021C60D4, func_021C60EC, func_021C6110, func_021C6134, func_021C6158, func_021C6190, func_021C62D8, func_021C6350, func_021C6394, func_021C63D0, func_021C6458, func_021C64B4, func_021C6564, func_021C65A8, func_021C6668, func_021C66AC, func_021C6720, func_021C676C, func_021C6848, func_021C6878, func_021C68A8, func_021C6948, func_021C69B8, func_021C6A04, func_021C6A9C, func_021C6B5C, func_021C6BB8, func_021C6BF8, func_021C6CAC, func_021C6DD0, func_021C6E00, func_021C6E3C, func_021C6F0C, func_021C6F34, func_021C6FC0, func_021C7008, func_021C7038, func_021C70E4, func_021C7194, func_021C71E0, func_021C728C, func_021C7330, func_021C7374, func_021C7474, func_021C75EC, func_021C7664, func_021C76F4, func_021C7780, func_021C77B0, func_021C7820, func_021C785C, func_021C78A8, func_021C78F4, func_021C7998, func_021C79E0, func_021C7A54, func_021C7AA0, func_021C7AD0, func_021C7B0C, func_021C7B3C, func_021C7B7C, func_021C7BA8, func_021C7BF8, func_021C7C18, func_021C7C24, func_021C7CBC, func_021C7CC8, func_021C7CD4, func_021C7CDC, func_021C7CE8, func_021C7CF4, func_021C7D00, func_021C7D34, func_021C7D44, func_021C7D54, func_021C7DAC, func_021C7E14, func_021C7EC4, func_021C7ED8, func_021C7EEC, func_021C7F04, func_021C7F24, func_021C7F4C, func_021C7F68, func_021C7FCC, func_021C7FE0, func_021C8010, func_021C8020, func_021C8030, func_021C804C, func_021C80AC, func_021C8114, func_021C8120, func_021C812C, func_021C8130, func_021C8138, func_021C8140, func_021C814C, func_021C815C, func_021C8168, func_021C8174, func_021C8180, func_021C818C, func_021C81C8, func_021C81D0, func_021C8234, func_021C824C, func_021C8288, func_021C8290, func_021C82B8, func_021C82C4, func_021C82D0, func_021C82F4, func_021C8300, func_021C830C, func_021C831C, func_021C8338, func_021C8348, func_021C8374, func_021C83A0, func_021C83CC, func_021C83D4, func_021C83DC, func_021C83E8, func_021C8408, func_021C8434, func_021C846C, func_021C8494, func_021C84AC, func_021C84D0, func_021C84D8, func_021C84E0, func_021C84E8, func_021C84F4, func_021C8534, func_021C8588, func_021C859C, func_021C85B8, func_021C85D4, func_021C8810, func_021C8828, func_021C8838, func_021C8860, func_021C888C, func_021C88A4, func_021C88B4, func_021C88C8, func_021C88E4, func_021C8910, func_021C8918, func_021C8C6C, func_021C8CBC, func_021C8D0C, func_021C8D2C, func_021C8DE4, func_021C8E58, func_021C8F24, func_021C8FA4, func_021C9010, func_021C9068, func_021C9178, func_021C9250, func_021C9394, func_021C9448, func_021C947C, func_021C94C8, func_021C95D0, func_021C962C, func_021C96D4, func_021C9728, func_021C9750, func_021C9778, func_021C97A4, func_021C97D0, func_021C9828, func_021C9898, func_021C98C4, func_021C98E4, func_021C99A0, func_021C9A24, func_021C9A60, func_021C9BB8, func_021C9CC0, func_021C9DCC, func_021C9DE8, func_021C9E3C, func_021C9ECC, func_021C9F0C, func_021C9F4C, func_021C9F6C, func_021CA128, func_021CA158, func_021CA1D0, func_021CA248, func_021CA270, func_021CA2E8, func_021CA318, func_021CA370, func_021CA394, func_021CA3AC, func_021CA3D0, func_021CA47C, func_021CA570, func_021CA5CC, func_021CA6C4, func_021CA6FC, func_021CA738, func_021CA748, func_021CA7C4, func_021CA7D4, func_021CA7F4, func_021CA8F8, func_021CAA24, func_021CAA58, func_021CACF4, func_021CAFD8, func_021CB174, func_021CB1A4, func_021CB1D4, func_021CB214, func_021CB274, func_021CB2D4, func_021CB55C, func_021CB5F0, func_021CB730, func_021CBA40, func_021CBB34, func_021CBCF4, func_021CBD48, func_021CBEA8, func_021CBF30, func_021CBF40, func_021CBF50, func_021CBF60, func_021CBF70, func_021CBF80, func_021CBF90, func_021CBFA0, func_021CC008, func_021CC098, func_021CC0A8, func_021CC0B8, func_021CC0C8, func_021CC0D8, func_021CC0E8, func_021CC0F8, func_021CC178, func_021CC214, func_021CC2C0, func_021CC350, func_021CC398, func_021CC438, func_021CC4AC, func_021CC508, func_021CC558, func_021CC5F4, func_021CC668, func_021CC768, func_021CC800, func_021CC8A0, func_021CC8B0, func_021CC8B8, func_021CC8C0, func_021CC8C8, func_021CC8D8, func_021CC918, func_021CC95C, func_021CC960, func_021CC96C, func_021CC974, func_021CC99C, func_021CC9A4, func_021CC9AC, func_021CCA74, func_021CCAA8, func_021CCAD4, func_021CCAE0, func_021CCB18, func_021CCB34, func_021CCB78, func_021CCB98, func_021CCBE8, func_021CCC0C, func_021CD0F0, func_021CD4B0, func_021CD4FC, func_021CD568, func_021CD5E0, func_021CD63C, func_021CD644, func_021CD64C, func_021CD6AC, func_021CD6EC, func_021CD6F0, func_021CD8E0, func_021CD914, func_021CD924, func_021CD938, func_021CD95C, func_021CD960, func_021CD978, func_021CD97C, func_021CD984, func_021CD9B0, func_021CD9C8, func_021CD9DC, func_021CD9E0, func_021CD9F4, func_021CDA0C, func_021CDA18, func_021CDC0C, func_021CDD34, func_021CDD50, func_021CDD94, func_021CDDA0, func_021CDDCC, func_021CDDDC, func_021CDE8C, func_021CDECC, func_021CDEE8, func_021CDF1C, func_021CDF58, func_021CDFE4, func_021CE040, func_021CE044, func_021CE068, func_021CE08C, func_021CE0BC, func_021CE0E0, func_021CE0F8, func_021CE150, func_021CE160, func_021CE170, func_021CE1B0, func_021CE2E8, func_021CE308, func_021CE3B4, func_021CE3C8, func_021CE4D0, func_021CE7D4, func_021CE8F0, func_021CEA94, func_021CECB4, func_021CED4C, func_021CEDC0, func_021CEEB8, func_021CEFFC, func_021CF078, func_021CF220, func_021CF2F0, func_021CF360, func_021CF37C, func_021CF3B8, func_021CF3F8, func_021CF41C, func_021CF430, func_021CF448, func_021CF470, func_021CF524, func_021CF58C, func_021CF5B0, func_021CF81C, func_021CF89C, func_021CF8D4, func_021CF918, func_021CF9B4, func_021CFAC4, func_021CFADC, func_021CFB8C, func_021CFBA4, func_021CFBBC, func_021CFBE0, func_021CFBF0, func_021CFD50, func_021CFDCC, func_021CFE08, func_021CFE98, func_021CFFAC, func_021D0100, func_021D0248, func_021D0304, func_021D04E4, func_021D055C, func_021D05C4, func_021D0644, func_021D06C8, func_021D0770, func_021D0980, func_021D09E0, func_021D0B10, func_021D0B6C, func_021D0BB0, func_021D0C78, func_021D0CC4, func_021D0D38, func_021D0D44, func_021D0D50, func_021D0E7C, func_021D102C, func_021D1058, func_021D10B8, func_021D123C, func_021D127C, func_021D1290, func_021D13A4, func_021D13FC, func_021D1410, func_021D1708, func_021D171C, func_021D185C, func_021D18EC, func_021D1960, func_021D1A18, func_021D1A60, func_021D1A74, func_021D1BD0, func_021D1C40, func_021D1CAC, func_021D1CF4, func_021D1DF4, func_021D1E6C, func_021D1EB4, func_021D1F10, func_021D1F58, func_021D1FB4, func_021D2000, func_021D2030, func_021D20BC, func_021D210C, func_021D215C, func_021D21D4, func_021D2234, func_021D2278, func_021D2320, func_021D2374, func_021D23B8, func_021D2424, func_021D2490, func_021D2510, func_021D2580, func_021D25C4, func_021D2628, func_021D266C, func_021D2700, func_021D2814, func_021D284C, func_021D28AC, func_021D2930, func_021D2990, func_021D299C, func_021D29CC, func_021D2A20, func_021D2C7C, func_021D2CA8, func_021D2FD8, func_021D3138, func_021D31A0, func_021D324C, func_021D32E0, func_021D344C, func_021D34B0, func_021D34E8
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
 *   func_02018480 0x02018480 thumb
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021B85A0 0x021B85A0 thumb ov093
 *   func_02018488 0x02018488 thumb
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
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D7394 0x021D7394 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D73D4 0x021D73D4 thumb ov093
 *   d_021EFDB8 0x021EFDB8 data a2
 *   func_021D6E74 0x021D6E74 thumb ov093
 *   func_021D6E40 0x021D6E40 thumb ov093
 *   func_0201C1BC 0x0201C1BC thumb
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
 *   func_0201C314 0x0201C314 thumb
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
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_0689CCF8 0x0689CCF8 thumb ov095
 *   func_0689CCB4 0x0689CCB4 thumb ov095
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D7B3C  0x021D7B3C  thumb  ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D7A44 0x021D7A44 thumb ov093
 *   func_021D7C38 0x021D7C38 thumb ov093
 *   func_021D7A6C 0x021D7A6C thumb ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021D6730  0x021D6730  thumb  ov093
 *   sub_0201BF58 0x0201BF58 thumb
 *   func_021D7C70 0x021D7C70 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_0689C364 0x0689C364 thumb ov095
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021EF884  0x021EF884  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_0201C020 0x0201C020 thumb
 *   sub_0201C0BC  0x0201C0BC  thumb
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D5FB8  0x021D5FB8  thumb  ov093
 *   func_021D6D90  0x021D6D90  thumb  ov093
 *   func_0689C7A4 0x0689C7A4 thumb ov095
 *   func_0201C184  0x0201C184  thumb
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
 *   func_0202E7E0 0x0202E7E0 thumb
 *   func_0202E7E4 0x0202E7E4 thumb
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
 *   sub_0201C1C8   0x0201C1C8  thumb
 *   sub_0201C1E8   0x0201C1E8  thumb
 *   sub_0201C1F4  0x0201C1F4  thumb
 *   sub_0201C284  0x0201C284  thumb
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
 *   func_0201C1D8  0x0201C1D8  thumb
 *   func_021D5AD8 0x021D5AD8 thumb ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7B2C  0x021D7B2C  thumb  ov093
 *   func_021B86A0 0x021B86A0 thumb ov093
 *   func_0689D5F4 0x0689D5F4 thumb ov095
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_0201B718 0x0201B718 thumb
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
 *   func_02011168 0x02011168 thumb arm9
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C7B4  0x0207C7B4  arm
 *   func_021D6B6C  0x021D6B6C  thumb  ov093
 *   g_021EFDC0      0x021EFDC0  data  ov093
 *   func_02019C90   0x02019C90  thumb arm9
 *   func_02017D30   0x02017D30  thumb arm9
 *   func_02017D70   0x02017D70  thumb arm9
 *   data_021EFDE4 0x021EFDE4 data a4
 *   func_021B8724 0x021B8724 thumb ov093
 *   func_021D6E24 0x021D6E24 thumb ov093
 *   func_020111BC 0x020111BC thumb
 *   FX_Div 0x0207C768 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021B873C  0x021B873C  thumb  ov093
 *   func_020113F0 0x020113F0 thumb
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
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006740 0x02006740 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_02006734 0x02006734 thumb
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   func_02005DF8 0x02005DF8 thumb
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
 *   func_02005E30 0x02005E30 thumb
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
 *   func_0201C1C8 0x0201C1C8 thumb
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
 *   func_02005D28 0x02005D28 thumb
 *   func_021F878C   0x021F878C  thumb ov094
 *   func_021EA600 0x021EA600 thumb ov093
 *   func_02024450  0x02024450  thumb
 *   func_0202435C  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   sub_02045808   0x02045808  arm
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
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_021EADA4 0x021EADA4 thumb ov093
 *   func_021EADB4 0x021EADB4 thumb ov093
 *   func_021EADC4 0x021EADC4 thumb ov093
 *   func_021EADD4 0x021EADD4 thumb ov093
 *   func_021EADE4 0x021EADE4 thumb ov093
 *   func_021EADF4 0x021EADF4 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 *   func_02006254 0x02006254 thumb
 *   func_020181F4   0x020181F4  thumb
 *   func_02018328   0x02018328  thumb
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
extern void func_021D787C(void *);
extern void func_021B68D8(u8 *s, struct T *t);
extern void func_021E9034(char *p);
extern void func_021E8E28(void *p);
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern u8 func_021D54B4(u8 *p);
extern void *func_02030734(u16, unsigned int, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_021EEAE0(void *p);
extern u8 func_021B86C0(u8 **p);
extern u32 func_021EEB64(struct QW *p, u32 *out);
extern int func_021B85A8(u8 *);
extern u32 func_021D8454(Action *);
extern u8 *func_021EE9A4(u8 *p, unsigned int *out);
extern u16 func_021B86DC(void **);
extern void func_02005D90(u32, u32);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021EE9B4(u8 *, void *, int);
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
extern void func_0689CFF0(void *);
extern void func_0689D118(void *);
extern void func_0689D1FC(void *, void *, void *, u32);
extern void func_02082BCC(void *, int, u32);
extern void func_021D8230(u8 *p);
extern void func_06898BFC(void *);
extern void func_02049238(u32);
extern void func_021B8750(char *p, unsigned char k, void *m);
extern void func_0689D134(u8 *);
extern void func_021D6EE8(void);
extern void func_021D74E4(void);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_0689D174(void *, int);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern u8 func_0689D558(u8 *, u8, u8 *);
extern int func_021EF948(int k);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021D8548(void *p);
extern void func_021DCFB4(void *p);
extern void func_0689D338(u8 *, int, int, u8 *, u8 *);
extern int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
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
extern int func_0689D588(u8 *, u8);
extern int func_021B86E4(unsigned int **p);
extern u8 func_021D69AC(u8 *, int);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern int func_021B871C(char *);
extern int func_02018480(void *, int);
extern u8 func_021B85A0(u8 **p);
extern void func_021D7630(int key, u32 val);
extern u8 func_0689D5C8(u8 *, int);
extern void func_021D82FC(Action *p, int sub);
extern int func_0689CD40(void *);
extern u32 func_0689CD38(void *);
extern void *func_0689CC70(void *, u32);
extern void func_0689D4F0(u8 *, int, int);
extern int func_021D58A8(u8 *p, int k);
extern void func_021D8244(struct B *p, int n);
extern void func_0689C68C(Server *, u8 *);
extern void *func_021D8484(void *a);
extern void *func_021DCF5C(void *p);
extern void func_021D63EC(u8 *p, u16 n);
extern void func_021D6580(void *);
extern void func_0689D320(void *, int, u8, void *);
extern void func_0689CB3C(void *);
extern void func_0689CB48(void *, void *);
extern void func_0689CF24(void *, Server *);
extern void func_0689CC84(void *);
extern void *func_0689CC8C(void *);
extern void func_021D70FC(int a, int b, int c);
extern void func_021D64F0(u8 *a);
extern void func_0689D2F8(void *, int);
extern union Slot func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Slot v);
extern int func_021D55A0(struct UtilWork *p, int id);
extern u32 func_021D5C08(struct UtilWork *p);
extern u8 func_021D80BC(void *p, int a, int m, u16 move);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern void func_0689CEE4(void *);
extern void func_0689CD78(void *, void *);
extern void func_0689CD48(void *, int);
extern void func_0689D01C(void *, u16, u32, u32);
extern void func_021D6744(u8 *, u8, int, u8, u16, u16);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_0201BEB8(void *bag, int item);
extern void func_021D7394(int kind);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D73D4(int kind);
extern u32 func_021D6E74(u8 *p);
extern void func_021D6E40(u8 *, u8, u16);
extern u32 func_0201C1BC(u16);
extern int func_0689CD50(void *);
extern void func_0689D050(struct O *);
extern void func_0689CC14(void *, void *);
extern u32 func_021D6D7C(u8 *p);
extern int func_0689D59C(u8 *, int, u32);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021D7704(int, int);
extern unsigned char func_021D7908(int a, int i);
extern union Slot func_021E896C(int, int);
extern int func_021D5C30(struct UtilWork *p);
extern union Slot func_021E899C(u32 a);
extern u32 func_021D5584(struct UtilWork *p, u32 i);
extern u16 func_021D67B8(u8 *);
extern u16 func_021D67A8(struct QL *p);
extern u32 func_0201C314(void *p);
extern int func_021EF91C(void *, u8 *, u16);
extern int func_021D7AF0(u32);
extern int func_021D61A8(struct UtilSlots *p);
extern int func_021D6130(struct UtilSlots *p);
extern union Slot func_021D7D18(int);
extern void func_021D69A0(u8 *base, int idx, u8 val);
extern void func_021D5608(struct UtilWork *p, int i, u8 n);
extern void func_021D56CC(struct Work *p, int i);
extern void func_0689CDCC(u8 *, u8 *, u8 *);
extern void func_0689CE58(u8 *, u8 *, u8 *);
extern unsigned int func_021B8590(unsigned char *p);
extern void func_0689CBB8(void *, void *, u16, int);
extern void func_021D6848(u8 *c, struct Rec_p09 *r);
extern u32 sub_0201C1BC(u16 move);
extern u16 func_021D5B40(struct QI *p);
extern int func_0689CCF8(u8 *, u8 *, u32 *);
extern int func_0689CCB4(u8 *, u8 *, u32 *);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 func_021D7B3C(u32 a, u32 b);
extern int func_0201C1E8(int a);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D7C38(int a, int b);
extern u32 func_021D7A6C(u32, u32);
extern void func_021D5B44(struct QI *p, u16 v);
extern void func_021DCF24(u8 *a);
extern void func_021D6730(struct QK *p, u16 v);
extern W_021C312C sub_0201BF58(u16);
extern void func_021D7C70(W_021C312C, u32, union Slot *);
extern u16 func_021D57FC(void *);
extern int func_021E8D24(int x, int k);
extern void func_0689C364(int, union Slot, u8 *, struct Msg *);
extern void func_021D8510(void *p);
extern void func_021D66D8(void *, u8);
extern int func_021D7D6C(int);
extern int func_021EF884(void);
extern void func_021D70E4(void *a, int id);
extern u8 func_0201C020(u16);
extern u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
extern int func_021D5D14(s8 *p, int i, int sign);
extern int func_021D5B48(u8 *p);
extern int func_021D7AD4(int);
extern void func_021D5FB8(u8 *p);
extern int func_021D6D90(u8 *p);
extern void func_0689C7A4(Server *, u8 *);
extern u32 func_0201C184(int id);
extern int func_021EF894(void);
extern void func_021EF8A4(u32, u32);
extern int func_021EF8C8(int a, union Slot c);
extern int func_021E8A98(union Slot c);
extern void func_021EF8F8(int a, int r);
extern int func_0689C954(u16);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021D8564(int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021D6D5C(u8 *a, u16 v);
extern int func_021D6D9C(u8 *c, u16 *d);
extern void func_021D6D70(u8 *p);
extern void func_021D6408(u8 *);
extern void func_021D6E88(u8 *);
extern void func_021D701C(void);
extern u32 func_021B8630(u32 **p);
extern u32 func_0202E7E0(Server *);
extern u32 func_0203F0A8(void);
extern void func_0202E7E4(void *);
extern u8 *func_0689C9F8(u32);
extern void func_0689B7A8(u8 *, u8 *, union Slot, u32, Server *);
extern int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed);
extern u32 func_021D806C(const u8 *p);
extern void func_0689B8CC(u8 *, u8 *, u32);
extern void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
extern int func_021EF934(int, int);
extern void func_021C4C40(int, void *);
extern u32 func_021EF8B8(void);
extern int func_021D7BD4(void *, int);
extern void func_0689D15C(u8 *, u8);
extern void func_021D646C(u8 *);
extern unsigned int func_021B8640(unsigned int **p);
extern int func_0689D5FC(u8 *, u8);
extern void func_021D8538(void *p);
extern void func_021DCFA4(void *p);
extern void func_021E0434(u8 *);
extern void func_021D6264(struct UtilSlots *p, int v);
extern int func_021EF90C(int a);
extern int func_021B85EC(u32 **p);
extern int func_0689D1A0(u8 *, int, u8);
extern int func_0689D184(u8 *, int, u8);
extern void func_0689D1BC(u8 *, int, u8);
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern void func_021D61F0(struct UtilSlots *p);
extern void func_021D6238(struct UtilSlots *p, int k);
extern int func_021D7E10(struct Unk021D62A8 *p);
extern u8 func_021D5DC0(s8 *p, int i, u8 n);
extern u8 func_021D5E38(s8 *p, int i, u8 n);
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern void func_021D6034(u8 *a, int k, union Slot s);
extern int func_021E8A78(union Slot s);
extern void func_021D5F90(u8 *, u16);
extern void func_021D56A0(u8 *a, int b, int c);
extern void func_021D5674(u8 *a, int b, int c);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern void func_021D6008(u8 *, unsigned int);
extern u8 sub_0201C1C8(void *p);
extern int sub_0201C1E8(int a);
extern u32 sub_0201C1F4(u16 id);
extern u8 func_021D5F14(struct UtilWork *p);
extern int func_021D7930(int i);
extern u32 sub_0201C284(u16 id);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int);
extern int func_021E8DA8(int);
extern int func_021D79E8(int, int);
extern int func_021D5814(void *p, int k);
extern void func_0689C6E4(Server *, u8 *);
extern void func_0689C540(Server *, u8 *);
extern int func_021D794C(int a, int b);
extern int func_021D7BA4(int a);
extern u16 func_0201C1D8(void *p);
extern int func_021D5AD8(u8 *, int);
extern int func_021D76BC(int key, u32 val);
extern u32 func_021D7B2C(u32 a, u32 b);
extern int func_021B86A0(unsigned int **, unsigned int);
extern int func_0689D5F4(u8 *, int);
unsigned int func_021B8670(unsigned int **p);
extern unsigned int func_0201B718(void *, unsigned int, unsigned int, unsigned int);
int func_06898CF4(int a, int b);
extern int func_06898CE0(unsigned int, int);
extern int func_068982AC(int);
extern u16 func_021D67E8(u8 *p);
extern int func_021D55D8(u8 *p, int i, int s);
extern int func_0689C464(int, union Slot, u8 *, unsigned long, struct Msg *);
extern void func_021D5EA8(u8 *p, int i, u8 n);
extern int func_021D5EFC(char *);
extern void func_021D5F08(char *p);
extern void func_021D5970(u8 *, int, u16);
extern int func_0689C9C0(int);
extern void func_021D66B0(u8 *p, int n);
extern void func_021D6440(u8 *p, u32 n);
extern void *func_06898C10(u8, int, Word_021CAA58_td);
extern int func_06898D10(u32, u32);
extern int func_021EF8E8(int);
extern int func_068981F0(u32, u8, u8, const void *, u8);
extern int func_0689C974(u16);
extern void func_021D6738(u8 *);
extern void *func_021DCF78(void *p, unsigned int k);
extern void func_021DCF9C(void *n);
extern void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c);
extern void func_021D65C8(struct Work *p, struct Work *q);
extern void func_021D67D8(u8 *, u32);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern int func_021D6D54(struct R5 *p);
extern u8 func_021B8C38(u8, u8);
extern u32 func_021D7F00(u32);
extern u8 func_021B8C50(char **p, u32 v, int k);
extern u32 func_021D7EB4(void *a);
extern unsigned char func_021D6E04(unsigned char *p);
extern u8 func_021D6E0C(u8 *p, u32 i);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_02011168(u32);
extern int func_0207C7B4(int x);
extern u32 func_021D6B6C(u8 *p);
extern u32 func_02019C90(u32 a, u32 b, u32 c);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern int func_021B8724(char *p, void *m);
extern void func_021D6E24(void **p, int value);
extern int func_020111BC(int);
extern int FX_Div(int, int);
extern int FX_Sqrt(int);
extern u32 func_021B873C(char **p);
extern int func_020113F0(int row, int col);
extern int func_0689C9A0(u16);
extern Word_021CAA58_td func_021E8940(int v);
extern int func_021D5F38(struct S_p14 *p, int n);
extern u8 func_021D5450(struct Work *p);
extern u8 func_021D5568(u8 *p, u32 i);
extern u32 func_021D54D0(u8 *p, u8 i);
extern u32 func_0689C9E4(int);
extern int func_0689C8FC(u16);
extern int func_021E869C(void *p, int id);
extern int func_0689D1D4(void *);
extern void func_02034714(const char *expr, u32 line, const char *file);
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
extern void func_02006734(u8);
extern int func_021D3F98(u8 *);
extern void func_021EAE24(u8 *p);
extern void func_02005DF8(u32 a);
extern void func_021F88BC(int);
extern void *func_021F8678(void);
extern int func_021EAE34(u8 *p);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern int func_021F8524(int);
extern void func_021E90A0(unsigned int *o, unsigned int key);
extern int func_021E90D0(struct S_p14 *s);
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
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern void func_021D8434(u32 *p);
extern void func_021EAE44(void *);
extern int func_021EAE54(void *);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_021D81F8(void *,void *,void *,u32,void *);
extern void func_021EA65C(char *p, struct H *h);
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
extern void func_02005E30(u32);
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
extern u8 func_0201C1C8(void *p);
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
extern void func_02005D28(void);
extern void func_021F878C(u32 a);
extern void func_021EA600(char *p);
extern int func_02024450(const u16 *p);
extern void *func_0202435C(void *slots, unsigned int heap);
extern void func_021EA5E4(unsigned char *p, void *src);
extern void sub_02045808(struct U16Vec *vec);
extern void func_021EA5F0(char *p, struct H *h);
extern void func_02082A90(const void *, void *, u32);
extern void func_021EA824(char *p);
extern void func_021EA458(char *ctx, u16 a, u16 b);
extern int func_021EA478(u32 *p);
extern void func_021EA488(struct S *s, u8 a, u8 b, u8 c);
extern int func_021EA4C4(struct S *s);
extern void func_021EA678(char *p, u16 k, int *c);
extern void func_020061E4(unsigned int arg);
extern void func_021EA694(char *p, u16 k, int *c);
extern void func_021EA6F4(void *p, u8 b, u16 c);
extern int func_021D80A8(void *p);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(u32 *p);
extern void func_021EA354(void *ctx, int a, int b);
extern void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c);
extern int func_021EA120(struct S *s);
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
extern void func_021EA1B8(struct S *s, u32 a, int b, int c);
extern int func_021EA1F0(struct S *s);
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
extern void func_02005DE4(void *);
extern int func_02005E64(void);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern void func_021EADA4(u8 *, int, struct T *);
extern int func_021EADB4(u8 *);
extern void func_021EADC4(u8 *);
extern int func_021EADD4(u8 *);
extern void func_021EADE4(u8 *);
extern int func_021EADF4(u8 *);
extern int func_02006254(unsigned int);
extern u16 func_02018328(void *p, u32 *idx, u32 heap);
extern void func_021EA638(char *p, struct H *h, int c);
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
void func_021BB4E0(Obj_td *p, void *src, int n);
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
void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, void *t);
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
int func_021BEAB4(Server *p, u8 *a, int b, void *c, u8 *q);
int func_021BEB14(int a, u8 *b, int c, void *d, u8 *e, u8 *g);
void func_021BEBD8(Server *p,u8 *a,int c,int d);
int func_021BEC08(Server *p,u8 *a);
void func_021BEC2C(Server *p,u8 *a,int c);
int func_021BEC58(Server *p, u8 *a, u16 key, u8 *d);
void func_021BF04C(Server *p, u16 *b, int s, void *c);
void func_021BF0E4(int u, u8 *b, void *c, u8 *d, int e);
int func_021BF168(Server *p, u16 *a, u8 *b);
void func_021BF1B4(int u, u16 *b, u8 *s, void *c, int e);
void func_021BF244(Server *p, u32 a, u32 b);
void func_021BF27C(Server *p, u32 a, u32 b);
void func_021BF2B4(Server *p, u32 a, u32 b);
void func_021BF2EC(Server *p, u32 a, u32 b, int k);
int func_021BF324(Server *p, u8 *a, u8 *b);
void func_021BF3D8(Server *p, int b, u8 *a, void *d, void *arr);
void func_021BF4AC(Server *p, u8 *b, u8 *a, void *d, void *e);
int func_021BF6E8(Server *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1);
int func_021BF78C(Server *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h);
void func_021BF83C(Server *p, u16 *b, u8 *c, void *d);
void func_021BF8D4(Server *p, u16 *b, u8 *c, void *d);
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
int func_021C07AC(Server *p, u8 *a, u16 c, u16 d, void *e);
int func_021C07D4(Server *p, u8 *a, u16 c, u16 d, void *e);
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
void func_021C2488(Server *p, u16 id, u8 *a, void *c);
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
void func_021C2DC4(Server *p, u32 a, u32 b, void *c);
u32 func_021C2E4C(Server *p);
int func_021C2E64(Server *p, const u16 *q, u8 *a, u8 *b, int k);
void func_021C2F70(Server *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2);
int func_021C3008(Server *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j);
int func_021C312C(Server *p, u8 *a, enum Kind b, u8 c, u16 e, int d);
void func_021C3184(Server *p, const u16 *q, u32 r, void *c);
void func_021C3274(Server *p, u32 q, u32 b, void *c);
int func_021C334C(Server *p, u8 *q, int a, int b);
int func_021C3370(Server *p, void *q);
int func_021C3394(Server *p, u8 *q, int r);
void func_021C33E8(Server *a, u8 *b, int c);
void func_021C3438(Server *p, u16 *q, u8 *a, u8 *out);
void func_021C36A0(Server *p, u8 *a, u16 *b, int c);
void func_021C36E8(Server *p, u8 *q, u16 *r, int a, int b, u16 c);
u16 func_021C3720(Server *p, u8 *a, u16 *b, int c);
void func_021C376C(Server *p, u16 a1, int b, void *it);
int func_021C3810(Server *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);
BOOL func_021C39CC(Server *p);
int func_021C39F4(Server *a, u8 *b);
int func_021C3A4C(Server *p, int unused, u8 *a);
void func_021C3AA8(Server *p, u16 *a, u8 *b);
int func_021C3B68(Server *p, int a, u8 b);
BOOL func_021C3B8C(Server *p, u32 a, u32 b);
void func_021C3BB8(Server *p, u32 a, u32 b);
void func_021C3BE0(Server *p, u32 a);
u8 func_021C3C10(Server *p, int k, u8 *a);
int func_021C3C60(Server *p, int a, union Slot c, int d);
void func_021C3CCC(Server *p, u8 *b, int c);
void func_021C3D08(Server *p, u16 *b, u8 *a, u8 *c);
void func_021C3E0C(Server *p, u8 *a, u8 *c);
void func_021C3FDC(Server *p, u8 *a);
int func_021C4034(Server *p, u8 *a);
u16 func_021C4104(Server *p, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e);
void func_021C41C0(Server *p, u8 *a);
void func_021C4218(Server *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
void func_021C4268(Server *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
int func_021C4304(Server *p, u16 *b, u8 *a, u8 *c, int *out);
void func_021C43F0(Server *p, u8 *a);
int func_021C446C(Server *p);
void func_021C4614(Server *p);
void func_021C4744(Server *p);
int func_021C4838(Server *p, u8 *a, u8 *b);
void func_021C4910(Server *p, u32 a, int k);
int func_021C493C(Server *p, u8 *a);
void func_021C4A64(Server *p, u8 *a, u32 b, u32 c);
int func_021C4B3C(Server *p, u8 *a, u32 b, u32 c);
void func_021C4B8C(Server *p);
void func_021C4B9C(int v, int k, Server *p);
void func_021C4BAC(Server *p, int k, int v);
void func_021C4C24(Server *p);
void CallbackForJpeg(int result, void *arg);
void func_021C4C50(Server *p, int k);
int func_021C4D1C(Server *p, void *it);
int func_021C4E38(Server *p, u8 *a, u32 b, u32 c);
void func_021C4EA4(Server *p, u8 *a, int k, int n);
int func_021C4F64(Server *p, u8 *a);
u32 func_021C5098(Server *p);
void func_021C5108(Server *p, u8 *a, int b);
void func_021C51D0(Server *p, u8 *a);
int func_021C5200(Server *p);
int func_021C5308(Server *p, u8 *a);
int func_021C5350(Server *p, u8 *g, const struct Entry_p11 *q);
int func_021C5418(Server *p, u8 *a, int b);
void *func_021C5474(char *p);
void func_021C5480(Server *p, u8 *a, int b);
void func_021C54BC(Server *p, u8 *a);
void func_021C54C8(Server *p, u8 *a);
void func_021C54FC(Server *p, u8 *a);
void func_021C5540(Server *p, u8 *a, int c);
void func_021C557C(Server *p, u8 *a, int k, int flag);
void func_021C5604(Server *p, u8 *a, int b);
void func_021C5620(Server *p, u8 *a, int k, union Slot *out);
int func_021C56A8(u8 *p, int *pv);
void func_021C5718(Server *p, u8 *a, u32 b);
void func_021C572C(Server *p, u8 *a, u32 v);
void func_021C5750(Server *p, u8 *a);
void func_021C5774(Server *p, u8 *a);
void func_021C5798(Server *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2);
void func_021C5840(Server *p, u32 count, int *v, u8 **a, int flag);
void func_021C59C4(Server *p, u32 n, u8 **a, u8 *b, int flag);
void func_021C5A1C(Server *p, u8 *a);
void func_021C5A34(Server *p, u8 *a);
void func_021C5A4C(Server *p, u8 *a, int b, int c);
void func_021C5A8C(Server *p, u8 *a, int c, int d, u16 msg, int flag);
void func_021C5B74(Server *p, u8 *a, int c, int d);
void func_021C5BE4(Server *p, u8 *a, int c);
void func_021C5C1C(Server *p, u8 *a, int k, union Slot s);
void func_021C5C74(Server *p, u8 *a, int kind, u32 v);
void func_021C5D88(Server *p, u8 *a, int b);
void func_021C5DAC(Server *p, u32 a, int n, const int *v);
void func_021C5E48(Server *p, u32 a, u32 b, int n, int *v);
void func_021C5EFC(Server *p, u32 a, int n, const int *v);
void func_021C5F98(Server *p, u32 a, u32 b, int n, int *v);
void func_021C604C(Server *p, u8 *a, int n);
void func_021C6080(Server *p, u8 *a, int b, int c, int d);
void func_021C60D4(Server *p, u8 *a);
void func_021C60EC(Server *p, u8 *a, u32 n);
void func_021C6110(Server *p, u8 *a, unsigned int n);
void func_021C6134(Server *p, u8 *a, unsigned int n);
void func_021C6158(Server *p, u8 *a);
int func_021C6190(Server *p, u8 *a);
int func_021C62D8(Server *p, u8 *a, u32 unused, u32 c, struct O_p11 *out);
u8 func_021C6350(Server *p, u8 *a);
void func_021C6394(Server *p, u8 *a, unsigned int n);
u32 func_021C63D0(Server *p, u8 *q);
int func_021C6458(Server *p, u8 *a, u32 c, u32 d, u8 *e);
void func_021C64B4(Server *p, u16 q, u8 *a, struct Out64B4 *out);
void func_021C6564(Server *p, u8 *a, u32 c, u32 d);
int func_021C65A8(Server *p, u8 *a, u32 e, u8 *d);
int func_021C6668(Server *p, u8 *a, u8 *a2, u16 a3);
int func_021C66AC(Server *p, u8 *a, void *c);
int func_021C6720(Server *p, u8 *a, u32 c);
int func_021C676C(Server *p, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32);
void func_021C6848(Server *p, u8 *a);
void func_021C6878(Server *p, u8 *a, int a2);
int func_021C68A8(Server *p, u8 *a, u8 *d, u16 a3);
int func_021C6948(Server *p, u8 *a, u8 *b, u32 v);
int func_021C69B8(Server *p, u8 *a, u32 c, u16 id);
int func_021C6A04(Server *p, u8 *a, u8 *b, struct Q *q);
int func_021C6A9C(Server *p, u8 *a, u8 *b, u16 id);
int func_021C6B5C(Server *p, u8 *a, u8 *b, u8 *q);
void func_021C6BB8(Server *p, u8 *a, u8 *b);
int func_021C6BF8(Server *p, u8 *a, u8 *b, u16 q);
int func_021C6CAC(Server *p, u8 *a, u16 b, int amount, int *out);
void func_021C6DD0(Server *p, u8 *a);
void func_021C6E00(Server *p, u8 *a, u8 k);
int func_021C6E3C(Server *p, u8 *a, u8 *b, u8 *q, int flag);
int func_021C6F0C(Server *p, u8 *a, int k);
int func_021C6F34(Server *p, u8 *a, int f);
void func_021C6FC0(Server *p, u8 *q);
void func_021C7008(Server *p, u8 *a);
int func_021C7038(Server *p, u8 *a, u8 *b, u32 q, u8 s);
void func_021C70E4(Server *p, int a, int b, int c, int e, u32 f);
int func_021C7194(Server *p, u8 *a, u32 v);
int func_021C71E0(Server *p, u8 *a, u32 x, u8 *out);
u16 func_021C728C(Server *p, u8 *a, u8 *b, const u8 *s);
int func_021C7330(Server *p, u8 *a);
u16 func_021C7374(Server *p, u8 *a, u8 *b, const u8 *c, int flag);
u16 func_021C7474(Server *p, u8 *a, u8 *b, const u8 *c, u32 flag);
int func_021C75EC(Server *p, u8 *a, int k);
int func_021C7664(Server *p, u32 x, u8 *a);
int func_021C76F4(Server *p, u8 *a, u32 k);
void func_021C7780(Server *p, u8 *a);
int func_021C77B0(Server *p, u8 *a, u32 b, u32 c, u32 d, u32 e);
void func_021C7820(Server *p, u8 *a, u32 k);
void func_021C785C(Server *p, u32 a, u8 *b, u32 c, u32 d);
void func_021C78A8(Server *p, u8 *a, u32 b, u32 c, u32 d);
u16 func_021C78F4(Server *p, u8 *a, u8 *b, u32 s);
void func_021C7998(Server *p, u32 x);
u32 func_021C79E0(Server *p, u32 x, u8 *a);
int func_021C7A54(Server *p, u8 *a, u32 c);
void func_021C7AA0(Server *p, u8 *a);
void func_021C7AD0(Server *p, u8 *a, u32 k);
void func_021C7B0C(Server *p, u8 *a);
void func_021C7B3C(Server *p, u32 a, u16 b, u16 c);
void func_021C7B7C(Server *p, unsigned int i);
void func_021C7BA8(Server *p, u8 a, u32 b, u32 c, u32 *out);
void func_021C7BF8(Server *p);
void func_021C7C18(void *p);
void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e);
u16 func_021C7CBC(u8 *p);
u16 func_021C7CC8(u8 *p);
u16 func_021C7CD4(struct Q6 *p);
u16 func_021C7CDC(u8 *p);
u16 func_021C7CE8(u8 *p);
void *func_021C7CF4(int *p, int i);
int func_021C7D00(u8 *p, int b);
int func_021C7D34(char *p, int i);
int func_021C7D44(char *p, u8 i);
u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
int func_021C7DAC(Server *p, int a, int b, u16 c);
u16 func_021C7E14(Server *p, u8 a, u8 b, u16 c, int e0, int e1);
u32 func_021C7EC4(u8 *p);
int func_021C7ED8(u8 *p, int i);
int func_021C7EEC(u8 *p, int i);
int func_021C7F04(u8 *p, int i);
int func_021C7F24(u8 *p, int i);
int func_021C7F4C(struct Flag *p);
u8 func_021C7F68(Server *p, int b, u8 *out);
char *func_021C7FCC(u8 *p, int i);
char *func_021C7FE0(u8 *p, int v);
int func_021C8010(Server *p, unsigned int v);
u8 func_021C8020(u8 *p, u8 v);
int func_021C8030(u8 *p, int v, u16 k);
int func_021C804C(S_td *p, u8 key, u32 *out);
int func_021C80AC(u8 *p, int key);
u16 func_021C8114(u8 *p);
u8 *func_021C8120(u8 *p, int b);
u8 *func_021C812C(u8 *p);
u8 *func_021C8130(u8 *p);
u16 func_021C8138(struct Q7 *p);
unsigned char func_021C8140(char *p, int i);
int func_021C814C(u8 *p, u8 v);
int func_021C815C(int *p);
void func_021C8168(int *p);
int func_021C8174(int *p);
int func_021C8180(int *p);
int func_021C818C(u8 *p, int v);
u16 func_021C81C8(Server *p, u8 *x, int flag);
u16 func_021C81D0(Server *p, u8 *a, u32 y);
int func_021C8234(Server *p, int i);
int func_021C824C(u8 *p, int v);
int func_021C8288(Server *p);
int func_021C8290(Server *p, int a, int b, void *item);
int func_021C82B8(Server *p, int z);
int func_021C82C4(int a, int b, int c);
int func_021C82D0(int unused, unsigned int v, int k);
int func_021C82F4(int a, int b, int c);
u32 func_021C8300(int *p, u8 k);
unsigned int func_021C830C(u8 *p);
void func_021C831C(u8 *p, int v);
int func_021C8338(Server *p, int i);
int func_021C8348(Server *p, int i);
int func_021C8374(Server *p, int i);
u32 func_021C83A0(u8 *p, int i);
u32 func_021C83CC(Server *p);
int func_021C83D4(Server *p);
void func_021C83DC(char *p, int x);
int func_021C83E8(unsigned char *p, int i, int b);
void func_021C8408(u8 *p, int a);
void func_021C8434(u8 *p, int a, int b);
int func_021C846C(Server *p, int a, int b, int *out);
void func_021C8494(Server *p, int i);
int func_021C84AC(Server *p, u8 *a, u8 *out);
void func_021C84D0(Server *p, u8 *a);
int func_021C84D8(u8 *p);
void func_021C84E0(Server *p, unsigned int v);
void func_021C84E8(Server *p);
void func_021C84F4(Server *p, unsigned int v);
int func_021C8534(Server *p);
void func_021C8588(Server *p);
void func_021C859C(Server *p);
void func_021C85B8(Server *p);
void func_021C85D4(Server *p, int index, int clear);
void func_021C8810(u8 *p);
u32 func_021C8828(u8 *p);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S_p12 *p, u32 val);
void func_021C888C(u8 *p, u32 v);
void *func_021C88A4(Server *p, int a, int b);
void func_021C88B4(Server *a, int k, int b);
void func_021C88C8(Server *a, void *b);
int func_021C88E4(Server *p);
int func_021C8910(Server *p);
void func_021C8918(Server *s, void *cmd);
u8 func_021C8C6C(Server *a, BtlCmd *e);
u8 func_021C8CBC(Server *a, Ent_021C8CBC *e);
u8 func_021C8D0C(Server *p, Ent_021C8D0C *e);
u8 func_021C8D2C(Server *p, const Ent_021C8D2C *e, int c);
u8 func_021C8DE4(Server *p, const Ent_021C8DE4 *e, int unused);
u8 func_021C8E58(Server *p, const Ent_021C8E58 *e);
u8 func_021C8F24(Server *p, const Ent_021C8F24 *e);
u8 func_021C8FA4(Server *p, const Ent_021C8FA4 *e, int unused);
u8 func_021C9010(Server *p, const Ent_021C9010 *e, int unused);
u8 func_021C9068(Server *p, const Ent_021C9068 *e, u16 arg);
u8 func_021C9178(Server *p, const Ent_021C9178 *e);
u8 func_021C9250(Server *p, const Ent_021C9250 *e, u16 arg);
u8 func_021C9394(Server *p, const Ent_021C9394 *e);
u8 func_021C9448(Server *p, u8 *e);
u8 func_021C947C(Server *p, const Ent_021C9448 *e);
u8 func_021C94C8(Server *p, const Ent_021C94C8 *e);
u8 func_021C95D0(Server *p, const Ent_021C95D0 *e);
u8 func_021C962C(Server *p, const Ent_021C962C *e);
u8 func_021C96D4(Server *w, struct Cmd_021C96D4 *c);
u8 func_021C9728(Server *p, u8 *q);
u8 func_021C9750(Server *p, u8 *q);
u8 func_021C9778(Server *p, u8 *q);
u8 func_021C97A4(Server *p, u8 *q);
u8 func_021C97D0(Server *w, const struct Cmd_021C97D0 *c);
u8 func_021C9828(Server *w, u8 *s);
u8 func_021C9898(Server *p, u8 *q);
u8 func_021C98C4(Server *p, u8 *q);
u8 func_021C98E4(Server *w, struct Cmd_021C98E4 *c);
int func_021C99A0(Server *w, const struct Msg *m);
u8 func_021C9A24(Server *p, const struct Cmd_021C9A24 *q);
u8 func_021C9A60(Server *p, const Ent_021C9A60 *e);
u8 func_021C9BB8(Server *p, const Ent_021C9BB8 *e);
u8 func_021C9CC0(Server *p, const Ent_021C9CC0 *e);
u8 func_021C9DCC(Server *p, u8 *q);
u8 func_021C9DE8(Server *w, struct Cmd_021C9DE8 *c);
u8 func_021C9E3C(Server *w, struct Cmd_021C9E3C *c);
u8 func_021C9ECC(Server *w, struct Cmd_021C9ECC *c);
u8 func_021C9F0C(Server *w, const struct Cmd_021C9F0C *c);
u8 func_021C9F4C(Server *p, u8 *q);
u8 func_021C9F6C(Server *p, u8 *q);
u8 func_021CA128(Server *p, struct Bits_p13 *q);
u8 func_021CA158(Server *w, struct Cmd_021CA158 *c);
u8 func_021CA1D0(Server *w, const struct Cmd_021CA1D0 *c);
u8 func_021CA248(Server *p, const u8 *q);
u8 func_021CA270(Server *w, const struct Cmd_021CA248 *c);
u8 func_021CA2E8(Server *p, const u8 *q);
u8 func_021CA318(Server *p, const struct Q_021C95D0 *q);
u8 func_021CA370(Server *p, const u8 *q);
u8 func_021CA394(Server *p, const u8 *q);
u8 func_021CA3AC(Server *p, const u8 *q);
u8 func_021CA3D0(Server *p, u8 *q);
u8 func_021CA47C(Server *p, struct Cmd_021CA2E8 *q);
u8 func_021CA570(Server *p, u8 *q);
u8 func_021CA5CC(Server *p, const struct Cmd *q);
u8 func_021CA6C4(Server *p, const u8 *q);
u8 func_021CA6FC(Server *p, const u8 *q);
u8 func_021CA738(Server *p, void *unused);
u8 func_021CA748(Server *p, const struct Q_021CA5CC *q);
u8 func_021CA7C4(Server *s, u8 *cmd);
u8 func_021CA7D4(Server *s, void *cmd);
int func_021CA7F4(Server *p, u8 *a, u8 b, const u8 *q, void *out);
int func_021CA8F8(Server *p, u8 *a, int unused, u8 *q, int id, void *out);
u8 func_021CAA24(Server *p, u8 *q, int m, u8 n, u8 value);
int func_021CAA58(Server *p, u8 *a, u8 move, u8 *q, int id, void *out);
int func_021CACF4(Server *p, u8 *a, u8 move, u8 *q, long id, void *out);
int func_021CAFD8(Server *p, u32 mode, void *m, const u16 *item, u8 self, void *out);
void *func_021CB174(Server *p, u8 n, int k);
void *func_021CB1A4(Server *p, u8 n);
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
u32 func_021CC918(Bf_td *p, u32 v, int unused);
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
void func_021D0B6C(u8 *g, u8 *s);
void func_021D0BB0(u8 *p);
u8 func_021D0C78(BattleSeq_021D0B6C *s, u8 *out);
int func_021D0CC4(BattleSeq_021D0B6C *s, int *state);
int func_021D0D38(u8 *p, int *state);
int func_021D0D44(u8 *p, int *state);
int func_021D0D50(u8 *p);
int func_021D0E74(u8 *p,int *state);
int func_021D0E7C(u8 *p, int *state, u8 param);
int func_021D102C(char *p);
int func_021D1058(u8 *s, void *q);
int func_021D10B8(u8 *p, int *state);
int func_021D123C(int a);
int func_021D127C(u8 *p, int *state);
int func_021D1290(u8 *p, int *state, void *a2);
int func_021D13A4(BattleSeq_021D123C *s);
int func_021D13FC(u8 *p, int *state);
int func_021D1410(BattleSeq_021D123C *s, int *state, void *q);
int func_021D1708(u8 *p, int *state);
int func_021D171C(u8 *p, int *state, void *a2);
void func_021D185C(BattleSeq_021D123C *s, int a, int b);
int func_021D18EC(BattleSeq_021D123C *s, int *state);
int func_021D1960(BattleSeq_021D123C *s, int *state);
int func_021D1A18(BattleSeq_021D123C *s, int *state);
int func_021D1A60(u8 *p, int *state);
int func_021D1A74(u8 *p, int *state, void *a2);
int func_021D1BD0(BattleSeq_021D123C *s, int *state, int *pp);
int func_021D1C40(BattleSeq_021D123C *s, u8 x, int *out);
int func_021D1CAC(BattleSeq_021D123C *s, int *state, int *pp);
int func_021D1CF4(u8 *p, int *state, const u32 *params);
int func_021D1DF4(BattleSeq_021D123C *s);
int func_021D1E6C(Seq_021D123C *s, int *state, u32 *a);
int func_021D1EB4(Seq_021D123C *s, int *state, u32 *a);
int func_021D1F10(Seq_021D123C *s, int *state, u32 *a);
int func_021D1F58(Seq_021D123C *s, int *state, u32 *a);
int func_021D1FB4(Seq_021D123C *s, int *state, u32 *a);
u32 func_021D2000(Seq_021D2030 *p, u32 k, u8 b);
int func_021D2030(Seq_021D2030 *s, int *state, const u32 *a);
int func_021D20BC(Seq_021D20BC *s, int *state, u32 *a);
int func_021D210C(Seq_021D210C *s, int *state, u32 *a);
int func_021D215C(Seq_021D215C *s, int *state, u32 *a);
int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a);
int func_021D2234(Seq_021D2234 *s, int *state, u32 *a);
int func_021D2278(Seq_021D2030 *s, int *state, u32 *a);
int func_021D2320(u8 *p, int *st, u32 *c);
int func_021D2374(u8 *p, int *st, u32 *c);
int func_021D23B8(u8 *p, int *st, u32 *c);
int func_021D2424(u8 *p, int *st, u32 *c);
int func_021D2490(u8 *p, int *st, u32 *c);
int func_021D2510(u8 *p, int *st, u32 *c);
int func_021D2580(u8 *p, int *st, u32 *c);
int func_021D25C4(u8 *p, int *st, u32 *c);
int func_021D2628(u8 *p, int *st, u32 *c);
int func_021D266C(u8 *p, int *st, u32 *c);
int func_021D2700(u32 *p, int *st, u32 *c);
int func_021D2814(char *p, int *state, unsigned int *q);
int func_021D284C(u8 *p, int *st, u32 *c);
int func_021D28AC(u8 *p, int *st, u32 *c);
int func_021D2930(u32 *a, int *b, u32 *c);
int func_021D2990(int a, int b, int *c);
int func_021D299C(char *p, int *state);
int func_021D29CC(u32 *a, int b, u32 *c);
int func_021D2A20(u8 *p, int *state, u32 *args);
int func_021D2C7C(int n);
int func_021D2CA8(LearnSeq_021D2C7C *s, int *state, void *mon);
int func_021D2FD8(u32 *a, int *b, const u32 *c);
int func_021D3138(u32 *a, int *b, u32 *c);
int func_021D31A0(u32 *a, int *b, u32 *c);
int func_021D324C(u32 *a, int *b, u32 *c);
int func_021D32E0(u32 *a, int *b, u32 *c);
int func_021D344C(u32 *a, int *b, u32 *c);
int func_021D34B0(char *p, int *state, unsigned int *q);
int func_021D34E8(u32 *a, int *b, u32 *c);
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
    y = (int)func_021EEA58(b, c, 1, ((struct Obj13288 *)p)->fCC0);
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

















void func_021BB4E0(Obj_td *p, void *src, int n)
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
 * func_021C5474 leaves its input in r0 for the following func_06898BFC.
 */
void func_021BB9D8(Server *p)
{
    func_021D6EAC();
    func_021EF874(0);
    func_0689CFF0(p->w1c);
    func_0689D118(p->g3e0);
    func_0689D1FC(p->w1ab8, p->f4, p->f8, func_021B8588(p->f4));
    func_02082BCC(p->w7a9, 0, 0x18);
    func_02082BCC(p->flags, 0, 0x18);
    func_02082BCC(p->w7d9, 0, 4);
    func_02082BCC(p->w4d4, 0, 0x2a0);
    func_021C7C18(p->w1f7c);
    func_021C8588(p);
    func_021D8230(p->w4b8);
    func_021CC8C8(&p->lock);
    func_06898BFC(func_021C5474((char *)p->w1b50));
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
        func_0689D134(p->g3e0);
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
        saved = func_0689D174(p->g3e0, 0);
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
    if (saved == func_0689D174(p->g3e0, 0)) {
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
        present = func_0689D174((u8 *)p->g3e0, 0);
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
    u8 x[4];
    u32 v;

    if (p->f18 == 1) {
        for (i = 0; i < 4; i++) {
            if (func_021BB890(p->f0, i) != 0) {
                if (func_021B8588(p->f4) != 2)
                    v = 1;
                else
                    v = func_0689D558(p->w1ab8, i, x) + 1;
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
    func_0689D338(p->w1ab8, b, a, v2, p->f8);
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
        n = func_0689D558(p->w1ab8, i, buf);
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
        if (b.full.type != 6 && func_0689D588(p->w1ab8, func_021D5440(a)) == 0) goto end;
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
            func_021D82FC(&e->b, func_0689D5C8(p->w1ab8, y));
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











void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, void *t)
{
    int r = func_0689CD40(t);
    p->f2 = func_0689D5C8(q->w1ab8, func_021D5440(a));
    p->f3 = 6;
    p->b0 = 0;
    p->b1 = 0;
    if (r == 1 && func_0689CD38(t)) {
        p->f3 = func_0689D5C8(q->w1ab8, func_021D5440(func_0689CC70(t, 0)));
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
    func_0689D4F0(p->w1ab8, x, y);
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
    func_0689C68C(p, a);
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
    func_0689D320(p->w1ab8, func_021B8BEC((u8 *)p->f4, i, a), id, p->f8);
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
    func_0689CB3C((u8 *)p + q);
    func_021BD2B4((u8 *)(&cursor), (u8 **)p);
    while (func_021BD34C((u8 *)(&cursor), (u8 **)p, &out) != 0) {
        flag = (u8 *)p + func_021D5440(out);
        if (flag[0x7c1] != 0) {
            func_0689CB48((u8 *)p + q, out);
            flag[0x7c1] = 0;
        }
    }
    func_0689CF24((u8 *)p + q, p);
    lock = func_021CC8D8(&p->lock, 3096);
    func_021BDBEC(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C(&p->lock, lock, 3102);
    func_0689CC84((u8 *)p + q);
    out = func_0689CC8C((u8 *)p + q);
    while (out != 0) {
        lock = func_021CC8D8(&p->lock, 3108);
        func_021BDB88(p, out);
        if (func_021C88E4(p) != 0) result = 1;
        func_021CC95C(&p->lock, lock, 3114);
        out = func_0689CC8C((u8 *)p + q);
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
    func_0689D2F8(p->w1ab8, n);
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
        func_021C07AC(p, a, id, pr, p->f850);
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
            func_021C07AC(p, a, id, pr, p->f850);
            flag = 1;
            goto end;
        }
    } else {
        *(struct Cell *)p->f1ab0 = *(struct Cell *)p->f1ab4;
    }
    func_0689CB3C(p->f850);
    func_0689CB3C(p->f854);
    func_021CA7F4(p, a, sel, p->f1ab0, p->f850);
    {
        u32 v = (u8)func_0689CD40(p->f850);
        func_0689CEE4(p->f850);
        func_0689CD78(p->f850, p->f854);
        func_0689CD48(p->f854, v);
    }
    if (chk1 == 0 && chk2 == 0 && pr != 4) {
        func_021C07AC(p, a, id, pr, p->f850);
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
        func_0689D01C(p->w1c, id2, p->f10, func_021D5440(a));
        func_021BE66C(p, a, p->f1ab0, 0x23);
        if (func_021BEAB4(p, a, id2, p->f854, p->f4ac) != 0) {
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
int func_021BEAB4(Server *p, u8 *a, int b, void *c, u8 *q)
{
    u8 buf[2];
    buf[1] = 0x1F;
    buf[0] = 0x1F;
    func_021BEB14((int)p, a, b, c, &buf[1], &buf[0]);
    if (buf[1] != 0x1F) {
        q[7] = (buf[0] != 0x1F) ? func_0689D5C8(p->w1ab8, buf[0]) : 6;
        q[1] = buf[1];
        q[0] = 1;
        return 1;
    }
    return 0;
}





















int func_021BEB14(int a, u8 *b, int c, void *d, u8 *e, u8 *g)
{
    u32 n;
    u32 i;
    n = func_0689CD38(d);
    func_021D74F8(4136);
    func_021D75EC(0x12, c);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(5, n);
    for (i = 0; i < n; i++)
        func_021D75EC(6 + i, func_021D5440(func_0689CC70(d, i)));
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
    func_0689CB3C(p->f860);
    pos = func_021CD4FC(p->fC, 0x30);
    func_021BD200((struct Unk021BD1E0 *)((struct State * )p->f4a8), p, a, d);
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
    func_0689CEE4((struct S *)d);
    func_021BF04C(p, p->f1ab0, (int)a, d);
    func_021BF0E4((int)p, a, d, p->f1ab0, execute);
    if (func_0689CD50((struct S *)d)) {
        if (((struct Bits78A *)&p->f78a)->skip == 0) func_021C5718(p, a, key);
        active = 0;
    }
    if (active != 0) {
        if (action != 9) func_021BF83C(p, p->f1ab0, a, d);
        func_021CC8A0((u32 *)p->w1f88);
        if (forced != 0 || func_021BF168(p, p->f1ab0, a))
            func_021BF3D8(p, (int)p->f1ab0, a, d, p->w1f88);
        func_021BF4AC(p, p->f1ab0, a, d, p->w1f88);
        if (action != 9) func_021BF8D4(p, p->f1ab0, a, d);
        if (func_0689CD50((struct S *)d)) {
            func_021BF27C(p, id, key);
            active = 0;
        } else {
            func_021BF1B4((int)p, p->f1ab0, a, d, forced);
            if (func_0689CD50((struct S *)d)) {
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
            case 2: func_021C2DC4(p, (u32)p->f1ab0, (u32)a, d); break;
            case 1: func_021C2488(p, key, a, d); break;
            case 5: func_021C3184(p, p->f1ab0, (u32)a, d); break;
            case 9: func_021C3438(p, p->f1ab0, a, d); break;
            case 12: func_021C376C(p, key, (int)a, d); break;
            case 3: func_021C3274(p, key, (u32)a, d); break;
            case 10: func_021C3AA8(p, p->f1ab0, a); break;
            case 11: case 13: func_021C3D08(p, p->f1ab0, a, d); break;
            }
        }
        s = (struct State * )p->f4a8;
        if (s->a != 0) {
            if (s->b == 0) func_021BFBD0(p, key, p->f4a8, pos);
            func_0689D050((struct O *)p->w1c);
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



















void func_021BF04C(Server *p, u16 *b, int s, void *c)
{
    u8 *x;
    func_0689CC84(c);
    x = func_0689CC8C(c);
    while (x != 0) {
        if (func_021BFA00(p, (u8 *)s, x, (void *)(*b)) != 0) {
            func_0689CC14(c, x);
            func_021C572C(p, x, *b);
            p->f78a.raw |= 0x10;
        }
        x = func_0689CC8C(c);
    }
}


















void func_021BF0E4(int u, u8 *b, void *c, u8 *d, int e)
{
    u8 *x;
    if (func_0689CD40(c) == 1) {
        x = func_0689CC70(c, 0);
        if (x != 0) {
            if (func_021D5440(x) == func_021D5440(b)) {
                if (((struct Obj21056 *)d)->fC != 7) {
                    if (func_021D5BB0((struct UtilWork *)b, 12) != 0 || e != 0)
                        func_0689CC14(c, x);
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


















void func_021BF1B4(int u, u16 *b, u8 *s, void *c, int e)
{
    u8 *x;
    func_0689CC84(c);
    x = func_0689CC8C(c);
    while (x != 0) {
        if (s != x && func_021D6D7C(x) != 0 && e == 0 && (u32)func_0201BEB8((void *)((u16)((void *)*b)), (int)0xd) == 0)
            func_0689CC14(c, x);
        x = func_0689CC8C(c);
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
    if (func_0689D59C(p->w1ab8, (int)p->f4, func_021D5440(a)) != 0) {
        if (func_021D59B4(a, 0x11) == 0x63)
            return 1;
    }
    if (func_0689D59C(p->w1ab8, (int)p->f4, func_021D5440(b)) != 0) {
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















void func_021BF3D8(Server *p, int b, u8 *a, void *d, void *arr)
{
    u8 *x;
    int r;
    int e;
    func_021CC8A0(arr);
    func_0689CC84(d);
    x = func_0689CC8C(d);
    while (x != 0) {
        r = func_021C6E3C(p, a, x, (u8 *)b, 1);
        func_021CC8B0(arr, func_021D5440(x), r);
        if (r == 0) {
            func_0689CC14(d, x);
            func_021C7C24((u16 *)p->w1f7c, (int)p, a, x, 0);
            e = func_021B8DDC(func_021D5440(a));
            if (e == func_021B8FF4(p->f4))
                func_021BA1B4((char **)(p->f4), 0x4b);
        }
        x = func_0689CC8C(d);
    }
}













void func_021BF4AC(Server *p, u8 *b, u8 *a, void *d, void *e)
{
    u8 *q;
    func_0689CC84(d);
    q = func_0689CC8C(d);
    while (q) {
        if (func_021BF324(p, a, q) == 0 && func_021BF6E8(p, b, a, q, e, 43))
            func_0689CC14(d, q);
        q = func_0689CC8C(d);
    }
    func_0689CC84(d);
    q = func_0689CC8C(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 44)) func_0689CC14(d, q);
        q = func_0689CC8C(d);
    }
    if ((u32)func_0201BEB8((void *)(((struct Obj04358 *)b)->f0), (int)3)) {
        func_0689CC84(d);
        q = func_0689CC8C(d);
        while (q) {
            if (func_021D5BB0((struct UtilWork *)q, 7) && func_021C6668(p, a, q, ((struct Obj04358 *)b)->f0) == 0) {
                func_0689CC14(d, q);
                func_021CD64C(p->fC, 91, 523, func_021D5440(q), 0xffff0000);
            }
            q = func_0689CC8C(d);
        }
    }
    func_0689CC84(d);
    q = func_0689CC8C(d);
    while (q) {
        if (func_021BF6E8(p, b, a, q, e, 45)) func_0689CC14(d, q);
        q = func_0689CC8C(d);
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















void func_021BF83C(Server *p, u16 *b, u8 *c, void *d)
{
    u8 *x;
    func_0689CC84(d);
    x = func_0689CC8C(d);
    while (x != 0) {
        if (func_021BF324(p, c, x) == 0) {
            if (func_021C6948(p, c, x, *b) != 0) {
                func_0689CC14(d, x);
                func_021C572C(p, x, *b);
            }
        }
        x = func_0689CC8C(d);
    }
}












void func_021BF8D4(Server *p, u16 *b, u8 *c, void *d)
{
    u8 *x;
    if (func_0689CD40(d) == 1 && func_0689CC70(d, 0) == c)
        return;
    func_0689CC84(d);
    x = func_0689CC8C(d);
    while (x != 0) {
        if (func_021BF9A4(p, c, x, b) == 0 && func_021BFA60(p, c, x, (struct Q *)b) == 0) {
            func_0689CC14(d, x);
            func_021C572C(p, x, *b);
        }
        x = func_0689CC8C(d);
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
        if (func_021C66AC(p, q, d)) {
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
        if (func_0689CD38(d))
            n = func_0689D5C8(p->w1ab8, func_021D5440(func_0689CC70(d, 0)));
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
            if (func_0689D588(p->w1ab8, k) != 0) {
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
int func_021C07AC(Server *p, u8 *a, u16 c, u16 d, void *e)
{
    u8 result = func_021C07D4(p, a, d, c, e);
    return func_021C0898(p, a, d, result);
}











/*
 * c and d are narrow parameters: their home stores (`str r2,[sp]` first,
 * `str r3,[sp,#4]` after `adds r7,r1`) sit where the narrow-parameter idiom
 * puts them; as u32 both sink below `ldr r5`. u8 and u16 compile the same
 * (any mix of the two); nothing in the image fixes the width, u16 chosen.
 * The calls to func_0689CD38 and func_0689CC70 go through linker veneers
 * (021C0868/0878/0888) that the linker makes.
 * `i = 0;` as its own statement before the func_0689CD38 call puts
 * `movs r4,#0` between `adds r0,r5` and that bl.
 */
int func_021C07D4(Server *p, u8 *a, u16 c, u16 d, void *e)
{
    int i;
    u8 *r;
    int res;
    func_021D74F8(0x16ef);
    i = 0;
    func_021D75EC(5, func_0689CD38(e));
    r = func_0689CC70(e, 0);
    if (r != 0) {
        do {
            func_021D75EC(i + 6, func_021D5440(r));
            i++;
            r = func_0689CC70(e, i);
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
    func_0689CB3C(p->f860);
    func_021C71E0(p, a, ((struct Obj04358 *)q)->f0, p->f4b4);
    func_021C14E0(p, a, (int)q, b);
    if (func_0689CD38(b) != 0) {
        if (func_021C1194(p->f4b4) != 0 && func_0689CD40(b) == 1) {
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
    func_0689CC84(b);
    r = func_0689CC8C(b);
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
            r = func_0689CC8C(b);
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
    if (func_0689CD40(b) == 1) k = 0x1000;
    else k = 0xc00;
    result = 0;
    f.bits.a = func_0689CD38(b) > 1;
    f.bits.b = d;
    func_0689CDCC(b, a, p->f858);
    func_0689CE58(b, a, p->f85c);
    func_021C0A4C(p, a, p->f858, q, c, k, p->f86c);
    func_021C0A4C(p, a, p->f85c, q, c, k, p->f870);
    *out = func_021CD4FC(p->fC, 0x30);
    if (func_0689CD38(p->f858) != 0) {
        result += func_021C11A4(p, (u16 *)q, a, p->f858, p->f86c, p->f4b4, k, f);
        if (result != 0 && func_021BEC08(p, a) != 0)
            func_021BA1B4((char **)(p->f4), 0x4d);
    }
    if (func_0689CD38(p->f85c) != 0)
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
    u8 *b = (u8 *)func_0689CC70(d, 0);
    struct State_p06 *s;
    CallFlags f;
    p->f789 = func_021D5440(b);
    if (func_021B8590(p->f4)) {
        tag = func_0689D5C8(p->w1ab8, func_021D5440(b));
        if (tag != 6) {
            func_021CD4B0(p->fC, 0x4e,
                func_0689D5C8(p->w1ab8, func_021D5440(a)), tag, 0x27e);
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
            func_0689D5C8(p->w1ab8, func_021D5440(a)), 0x291);
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
    u16 h;
    int i;
    int j;
    int flag;

    v28 = func_0689D5C8(p->w1ab8, func_021D5440(x));
    sum = func_021C0D70(y);
    cnt = func_021C0C38(p, (List_td *)y, (u32 *)d_021F3B38, (u16 *)d_021F3B26, (u32 *)d_021F3B2C, (u8 *)d_021F3B20);
    for (i = 0; i < cnt; i++) {
        if (func_021D6D7C(d_021F3B38[i])) {
            h = func_021C4104(p, x, d_021F3B38[i], d_021F3B26[i], d_021F3B2C[i], d_021F3B20[i], e);
            func_0689CBB8(p->f860, d_021F3B38[i], h, 1);
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
        func_0689CBB8(p->f860, d_021F3B38[j], d_021F3B26[j], 0);
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
    func_0689CC84(c);
    r = func_0689CC8C(c);
    if (r != 0) {
        do {
            if (func_021C6B5C(p, a, r, (u8 *)b) != 0) {
                struct St *st = (struct St * )p->f4a8;
                if (st->f == 0) st->f = 1;
                s = func_021CC8D8(&p->lock, 0x197b);
                func_021C6BB8(p, a, r);
                func_021CC95C(&p->lock, s, 0x197f);
                func_0689CC14(c, r);
            }
            r = func_0689CC8C(c);
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
    func_0689CC84(c);
    x = func_0689CC8C(c);
    while (x) {
        func_021C195C(p, x, 1);
        x = func_0689CC8C(c);
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
    n = func_0689CD38(b);
    sum = 0;
    got = 0;
    func_021D74F8(0x1b2b);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, d);
    func_021D75EC(0x12, ((struct Obj13325 *)c)->f0);
    func_021D75EC(0x16, c[6]);
    for (i = 0; i < n; i++) {
        x = func_0689CC70(b, i);
        if (e) ok = func_0689CCF8(b, x, &v);
        else ok = func_0689CCB4(b, x, &v);
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
        func_0689CC84(w);
        t = func_0689CC8C(w);
        while (t) {
            int k = 3;
            if (func_021D62A8((struct Unk021D62A8 *)t) == 3 && func_021D6D7C(t) == 0) {
                func_021C557C(p, t, k, 1);
            }
            t = func_0689CC8C(w);
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
    if (func_0689D588(p->w1ab8, func_021D5440(a))) {
        s = func_021CC8D8(&p->lock, 0x1cea);
        if (func_021C2204(p, a, (u16)t) == 0) result = 1;
        if (result) {
            pos = func_021CD4FC(p->fC, 0x42);
            v = func_021CC918((Bf_td *)&p->lock, (u16)t, 0x1cf4);
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









void func_021C2488(Server *p, u16 id, u8 *a, void *c)
{
    u32 s;
    W_021C312C w;
    union Slot out;
    u8 *t;
    int got;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    got = 0;
    if (func_0689CD38(c)) {
        func_0689CC84(c);
        for (t = func_0689CC8C(c); t; t = func_0689CC8C(c)) {
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
        func_0689C364(kind, value, a, (struct Msg *)p->w1ae4);
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








void func_021C2DC4(Server *p, u32 a, u32 b, void *c)
{
    u8 *t;
    func_0689CC84(c);
    for (t = func_0689CC8C(c); t != 0; t = func_0689CC8C(c)) {
        if (func_021C2E64(p, (const u16 *)a, (u8 *)b, t, 1) != 0) {
            BF_021C2AB0 *f = (BF_021C2AB0 * )p->f4a8;
            if (!f->f)
                f->f = 1;
        }
    }
}






























u32 func_021C2E4C(Server *p)
{
    if (++p->f778 == 0)
        p->f778 = 1;
    return p->f778;
}































/*
 * lever: enum Kind keeps the output guard in r0 and reloads it into r3 at the call.
 */
int func_021C2E64(Server *p, const u16 *q, u8 *a, u8 *b, int k)
{
    u8 id;
    int result;
    u32 count, i;
    u32 serial;
    enum Kind kind;
    s32 value;
    int ok;
    u8 j;
    u32 lock;
    result = 0;
    id = func_021D5440(a);
    serial = func_021C2E4C(p);
    count = func_0201C020(*q);
    for (i = 0; i < count; i++) {
        ok = 0;
        func_021C2F70(p, *q, i, a, b, (s32 *)&kind, &value);
        if (kind != 0) {
            if (kind != 10) {
                ok = func_021C3008(p, id, b, kind, value, id, ok, serial, k, 1);
            } else {
                for (j = 1; j < 6; j++) {
                    if (func_021C3008(p, id, b, j, value, id, 0, serial, k, 1)) ok = 1;
                }
            }
            if (ok) {
                lock = func_021CC8D8((struct Lock *)&p->lock, 8247);
                func_021C78A8(p, b, *q, kind, value);
                func_021CC95C(&p->lock, lock, 8249);
                result = 1;
            }
        }
    }
    return result;
}
































void func_021C2F70(Server *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2)
{
    u32 m;
    *s1 = sub_0201C0BC(x, y, s2);
    func_021D74F8(8275);
    func_021D75EC(3, func_021D5440(c));
    func_021D75EC(4, func_021D5440(s0));
    func_021D75A8(0x1F, *s1);
    func_021D75A8(0x20, *s2);
    func_021D75A8(0x35, 1);
    func_021D70F0(p, 0x59);
    *s1 = func_021D775C(0x1F);
    *s2 = func_021D775C(0x20);
    m = (u8)func_021D775C(0x35);
    if (m > 1)
        *s2 = *s2 * m;
    func_021D7540(8290);
    if (*s1 == 8)
        *s1 = 0;
}





























/*
 * lever: reassigning value to the transformed result keeps it in its incoming register.
 */
int func_021C3008(Server *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j)
{
    int result;
    u32 lock;
    value = func_021C312C(p, a, kind, f, g, value);
    if (!func_021D5D14((s8 *)a, kind, value)) {
        if (i) {
            func_021C5A4C(p, a, kind, value);
            p->f78a.raw |= 0x10;
        }
        return 0;
    }
    if (func_021D6D7C(a)) {
        u8 id;
        id = func_021D5440(a);
        if (b != id) {
            if (i) func_021CD64C(p->fC, 0x5b, 0xd2, id, 0xffff0000);
            return 0;
        }
    }
    result = 1;
    if (func_021C77B0(p, a, kind, b, value, h)) {
        func_021C5A8C(p, a, kind, value, g, j);
        lock = func_021CC8D8(&p->lock, 8349);
        func_021C785C(p, b, a, kind, value);
        func_021CC95C(&p->lock, lock, 8351);
    } else {
        if (i) {
            lock = func_021CC8D8(&p->lock, 8358);
            func_021C7820(p, a, h);
            func_021CC95C(&p->lock, lock, 8360);
        }
        result = 0;
    }
    return result;
}






























/*
 * Note (final push 2026-10-05 G4L8): the script result is written back into the
 * stack parameter d (the caller func_021C3008 does value = func_021C312C(..., value)).
 * Assigning to a stack-passed parameter, instead of a fresh local r, keeps the end
 * line as its own pool word (no ldr + adds #7 fold). Both --lang c99 and c EXACT.
 */
int func_021C312C(Server *p, u8 *a, enum Kind b, u8 c, u16 e, int d)
{
    func_021D74F8(8385);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, c);
    func_021D75EC(0x1F, b);
    func_021D7630(0x20, d);
    func_021D70F0(p, 0x5A);
    d = func_021D775C(0x20);
    func_021D7540(8392);
    return d;
}






























/*
 * sub_0201BF58 is declared here as returning a one-halfword struct (the
 * store of r0 with no sign extension and the dead-looking second strh are
 * the struct-return temp plus its copy); its own file says s16.
 * func_021D7C70's first argument and func_021C25A4's sixth are structs
 * passed by value.
 */
void func_021C3184(Server *p, const u16 *q, u32 r, void *c)
{
    u8 *t;
    u32 s;
    union Slot out;
    W_021C312C v;
    s = sub_0201BD28(*q, 0xB);
    v = sub_0201BF58(*q);
    func_021D7C70(v, r, &out);
    func_0689CC84(c);
    for (t = func_0689CC8C(c); t != 0; t = func_0689CC8C(c)) {
        if (func_021C2E64(p, (const u16 *)((u32)q), (u8 *)r, t, 1) != 0) {
            BF *f = (BF * )p->f4a8;
            if (!f->f)
                f->f = 1;
        }
        if (func_021C25A4(p, (u8 *)r, t, *q, s, out, 1) != 0) {
            BF *f = (BF * )p->f4a8;
            if (!f->f)
                f->f = 1;
        }
    }
}




























void func_021C3274(Server *p, u32 q, u32 b, void *c)
{
    u8 *t;
    func_0689CC84(c);
    for (t = func_0689CC8C(c); t != 0; t = func_0689CC8C(c)) {
        u8 m = func_021D5440(t);
        if (func_021C3370(p, (void *)t) == 0) {
            if (func_021C334C(p, t, (u16)func_021C79E0(p, q, t), 1) != 0) {
                BF *f = (BF * )p->f4a8;
                if (!f->f)
                    f->f = 1;
                func_021CD64C(p->fC, 0x5b, 387, m, 0xffff0000);
            }
        } else if (func_021D5B48(t) != 0) {
            func_021CD64C(p->fC, 0x5b, 893, m, 0xffff0000);
        }
    }
}




























int func_021C334C(Server *p, u8 *q, int a, int b)
{
    if (func_021C3394(p, q, b) == 0) {
        func_021C33E8(p, q, a);
        return 1;
    }
    return 0;
}




























int func_021C3370(Server *p, void *q)
{
    if (func_021D5B7C(q) == 0) return 1;
    if (func_021D5B48(q) != 0) return 1;
    return 0;
}





























int func_021C3394(Server *p, u8 *q, int r)
{
    if (func_021D62C4((struct Unk021D62A8 *)q, 15) != 0) {
        if (r != 0) {
            func_021CD64C(p->fC, 0x5b, 887, func_021D5440(q), 0xffff0000);
            p->f78a.raw |= 0x20;
        }
        return 1;
    }
    return 0;
}





























void func_021C33E8(Server *a, u8 *b, int c)
{
    int v = func_0689D5C8(a->w1ab8, func_021D5440(b));
    if (v != 6)
        func_021CD4B0((void *)((int)a->fC), 0x4d, v, 0x263);
    func_021C5B74(a, (u8 *)b, c, 1);
}


























void func_021C3438(Server *p, u16 *q, u8 *a, u8 *out)
{
    u8 speed;
    u8 *b;
    u8 id;
    u32 item;
    u32 lock;
    u8 tag;
    int category;
    int event1, event2;
    u32 i;
    u16 half;
    struct Flags_021C2E4C *flags;
    i = 0;
    speed = (u8)func_021D59B4(a, 15);
    for (;;) {
        int kind;
        b = (u8 *)func_0689CC70(out, i++);
        if (b == 0) break;
        if (func_021D5B68(b)) continue;
        id = func_021D5440(b);
        if (!func_021BF324(p, a, b)) {
            if (func_021C6948(p, a, b, *q)) {
                func_021C572C(p, b, *q);
                continue;
            }
        }
        if (func_021BFA00(p, a, b, (void *)(u32)*q)) {
            func_021C572C(p, b, *q);
            continue;
        }
        if (speed < (u8)func_021D59B4(b, 15)) {
            func_021C5774(p, b);
            continue;
        }
        item = func_021CC8B8((u32 *)p->w1f88, id);
        if (item == 0) {
            func_021C5774(p, b);
            continue;
        }
        lock = func_021CC8D8(&p->lock, 0x216b);
        if (func_021C6A9C(p, a, b, *q)) {
            tag = func_0689D5C8(p->w1ab8, func_021D5440(a));
            half = func_021D59B4(b, 13);
            category = func_021D7AD4(item);
            event1 = 0;
            event2 = 0;
            flags = (struct Flags_021C2E4C * )p->f4a8;
            if (!flags->a) flags->a = 1;
            if (func_021D6D7C(b)) {
                half = func_021C3720(p, b, q, category);
                func_0689CBB8(out, b, half, 1);
                event1 = 1;
            } else {
                kind = func_021C1678(p, a, b, 1, &half);
                if (kind == 0) {
                    func_021C36A0(p, b, q, category);
                } else {
                    func_021C36E8(p, b, q, category, kind, half);
                    func_0689CBB8(out, b, half, 0);
                    event2 = 1;
                }
            }
            if (!event1) func_021C1828(p, tag, a, b, (u8 *)q, half);
            func_021C4218(p, a, b, (u8 *)q, item, half, 0, event1);
            if (event2 || event1) func_021C1C88(p, a, (u32)out, (u8 *)q, 0);
            func_021C4F64(p, b);
        } else if (!func_021C88E4(p)) {
            func_021C572C(p, b, *q);
        }
        func_021CC95C(&p->lock, lock, 0x219c);
    }
}


























void func_021C36A0(Server *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(p->fC, 3, i);
    func_021CD4B0(p->fC, 0x32, i, (u8)c, *b);
    func_021CD4B0(p->fC, 0x34, i);
}


























/*
 * The final 00 00 at 0x021C371E is alignment padding before 0x021C3720.
 * A separate call-result local keeps the halfword load before that call.
 */
void func_021C36E8(Server *p, u8 *q, u16 *r, int a, int b, u16 c)
{
    int n;
    int v;
    func_021C604C(p, q, c);
    n = *r;
    v = func_021D5440(q);
    func_021CD4B0(p->fC, 0x32, v, (u8)a, n);
    func_021C16F8(p, q, b);
}



























u16 func_021C3720(Server *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    u16 v = func_021D6D90(a);
    func_021CD4B0(p->fC, 0x34, i);
    func_021CD4B0(p->fC, 0x32, i, (u8)c, *b);
    func_021C41C0(p, a);
    return v;
}



























void func_021C376C(Server *p, u16 a1, int b, void *it)
{
    int v = 0;
    u8 *r;
    func_0689CC84(it);
    r = func_0689CC8C(it);
    while (r) {
        if (func_021C3810(p, (u8 *)b, r, 0, &v, 0, 0, 0)) {
            Q_p10 *q = (Q_p10 * )p->f4a8;
            if (!q->f)
                q->f = 1;
        } else if (v == 0) {
            func_021C5718(p, (u8 *)b, a1);
        }
        r = func_0689CC8C(it);
    }
}
























static inline u8 rule(u8 n)
{
    if (n != 0) {
        n--;
        if (n < 24) return n;
    }
    return 31;
}
























int func_021C3810(Server *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg)
{
    enum Mode mode;
    u8 position;
    u32 lock;
    u8 blocked;
    struct Pair pair;
    *out = 0;
    if (force) mode = M1;
    else mode = func_021C39CC(p);
    if (mode == M2) return 0;
    position = func_021B8D8C(p->f4, p->f8, func_021D5440(b));
    if (position == 6) return 0;
    if (func_021D5B68(b)) return 0;
    if (func_021D62C4((struct Unk021D62A8 *)b, 33)) return 0;
    if (rule(func_021D69AC(b, 4)) != 31) return 0;
    lock = func_021CC8D8(&p->lock, 8732);
    blocked = func_021C3A4C(p, (int)a, b);
    if (blocked && func_021C88E4(p)) *out = 1;
    func_021CC95C(&p->lock, lock, 8740);
    if (blocked) return 0;
    func_021B8E28(p->f4, position, &pair.id, &pair.count);
    if (mode == M1) {
        u8 id;
        mode = func_021C39F4(p, func_021BB85C(p->f0, pair.id));
        if (mode >= 0) {
            id = func_021D5440((u8 *)func_021B990C((char *)((u32)p->f8), pair.id, (u8)mode));
            func_021BDD7C(p, b, move);
            if (msg) func_021C99A0(p, msg);
            func_021BD9D4(p, pair.id, pair.count, (u8)mode, 0);
            func_021CD64C(p->fC, 0x5b, 845, id, 0xffff0000);
            func_021BDA00(p);
        } else return 0;
    } else {
        int slot;
        slot = func_021B8DDC(func_021D5440(a));
        if (!ignore) {
            u8 speed;
            speed = (u8)func_021D59B4(a, 15);
            if ((u8)func_021D59B4(b, 15) > speed) return 0;
        }
        func_021D8244((struct B *)p->w4b8, slot);
        func_021BDD7C(p, b, move);
        p->f14 = 5;
    }
    return 1;
}
























BOOL func_021C39CC(Server *p)
{
    u32 a;
    void *b;
    a = func_021B8588(p->f4);
    b = func_021B86B8(p->f4);
    if (a == 0) {
        if (b == 0) {
            return FALSE;
        } else {
            return TRUE;
        }
    }
    return TRUE;
}

























int func_021C39F4(Server *a, u8 *b)
{
    u8 buf[8];
    u32 n;
    u32 i;
    int c;

    n = func_021B9B94(((struct Obj09971 *)b)->f4);
    i = func_021B99C0(a->f4, b[0xb]);
    c = 0;
    for (; i < n; i++) {
        if (func_021D5B7C(func_021B9C00(((struct Obj09971 *)b)->f4, (u8)i))) {
            buf[c] = i;
            c++;
        }
    }
    if (c != 0) {
        return buf[func_021D78AC(c)];
    }
    return -1;
}

























int func_021C3A4C(Server *p, int unused, u8 *a)
{
    int r;
    func_021D74F8(8877);
    func_021D7630(0x41, 0);
    func_021D75EC(4, func_021D5440(a));
    func_021D70F0(p, 0x8b);
    func_0689C7A4(p, a);
    r = func_021D775C(0x41);
    func_021D7540(8883);
    return r;
}

























void func_021C3AA8(Server *p, u16 *a, u8 *b)
{
    u8 k = func_0201C184(*a);
    if (k) {
        int x = func_021C3C10(p, k, b);
        if (func_021C3B68(p, k, (u8)(x + 5))) {
            Q_p10 *q = (Q_p10 * )p->f4a8;
            if (!q->f)
                q->f = 1;
            return;
        }
        func_021C5718(p, (u8 *)b, *a);
    } else {
        u32 s;
        int e;
        s = func_021CC8D8(&p->lock, 0x22c8);
        func_021C3CCC(p, b, *a);
        e = (func_021C88E4(p) == 2);
        func_021CC95C(&p->lock, s, 0x22cc);
        if (e) {
            Q_p10 *q = (Q_p10 * )p->f4a8;
            if (!q->f)
                q->f = 1;
        } else {
            func_021C5718(p, (u8 *)b, *a);
        }
    }
}
























int func_021C3B68(Server *p, int a, u8 b)
{
    if (func_021C3B8C(p, a, b)) {
        func_021C3BB8(p, a, b);
        return 1;
    }
    return 0;
}
























BOOL func_021C3B8C(Server *p, u32 a, u32 b)
{
    if (a >= 5) return FALSE;
    if (a == func_021EF884() && (b != 255 || func_021EF894() == 255)) {
        return FALSE;
    }
    return TRUE;
}
























void func_021C3BB8(Server *p, u32 a, u32 b)
{
    func_021EF8A4(a, b);
    func_021CD4B0(p->fC, 0x3f, a, b);
    func_021C3BE0(p, a);
}
























/*
 * interface: Lock scalar word return preserves the complete r0 payload,
 * as in matched caller 021C3810; restore consumes the same word.
 */
void func_021C3BE0(Server *p, u32 a)
{
    u32 old;
    int line = 0x2303;
    old = func_021CC8D8(&p->lock, line);
    func_021C7998(p, a);
    func_021CC95C(&p->lock, old, line + 2);
}

























u8 func_021C3C10(Server *p, int k, u8 *a)
{
    u8 r;
    func_021D74F8(8983);
    func_021D75EC(0x39, k);
    func_021D75EC(3, func_021D5440(a));
    func_021D75A8(0x24, 0);
    func_021D70F0(p, 0x7c);
    r = func_021D775C(0x24);
    func_021D7540(8989);
    return r;
}

























/*
 * The handed address 0x021C3C62 is the second label after `push {r0-r3}`
 * (0x021C3C60). The third parameter is a one-word struct passed by value
 * (its home slot is read through `add r7, sp, #0x20`).
 */
int func_021C3C60(Server *p, int a, union Slot c, int d)
{
    int r;
    if (func_021EF8C8(a, c)) {
        func_021CD4B0(p->fC, 0x21, (u8)a, c.raw);
        return 1;
    }
    if (d) {
        r = func_021E8A98(c);
        if (r != 0x1f) {
            func_021EF8F8(a, r);
            func_021CD4B0(p->fC, 0x22, (u8)a, r);
            return 1;
        }
    }
    return 0;
}
























void func_021C3CCC(Server *p, u8 *b, int c)
{
    int line = 0x2360;
    func_021D74F8(line);
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x12, c);
    func_021D70F0(p, 0x9e);
    func_021D7540(line + 4);
}























void func_021C3D08(Server *p, u16 *b, u8 *a, u8 *c)
{
    int out;
    u32 s, r;
    Flag_td *f;
    if (func_0689CD50(c) != 0) return;
    switch (*b) {
    case 0x11d:
        func_021C3E0C(p, a, c);
        return;
    case 0xa4:
        if (func_021C4034(p, a)) {
            f = (Flag_td * )p->f4a8;
            if (f->a == 0) {
                f->a = 1;
                f->b = 1;
            }
        }
        return;
    default:
        s = func_021CC8D8(&p->lock, 9087);
        r = func_021C88E4(p);
        if (func_021C4304(p, b, a, c, &out)) {
            r = func_021C88E4(p);
            if (r == 2) {
                f = (Flag_td * )p->f4a8;
                if (f->a == 0) f->a = 1;
            }
        }
        if (r <= 1 && out != 0 && ((ByteFlag *)&p->f78a)->b == 0) {
            func_021CD64C(p->fC, 0x5a, 0x47, 0xffff0000);
        }
        func_021CC95C(&p->lock, s, 9113);
    }
}





















void func_021C3E0C(Server *p, u8 *a, u8 *c)
{
    u8 *b;
    u32 x, y, ai, bi;
    u32 s, t;
    int line;
    Flag_td *f;
    b = func_0689CC70(c, 0);
    x = func_021D59B4(a, 16);
    y = func_021D59B4(b, 16);
    if (x != y && !func_0689C954(x) && !func_0689C954(y)) {
        ai = func_021D5440(a);
        bi = func_021D5440(b);
        f = (Flag_td * )p->f4a8;
        if (f->a == 0) f->a = 1;
        func_021CD4B0(p->fC, 0x4a, ai, bi, (u16)y, (u16)x);
        func_021CD64C(p->fC, 0x5b, 0x1fc, ai, 0xffff0000);
        line = 9140;
        s = func_021CC8D8(&p->lock, line);
        func_021C7B3C(p, ai, x, y);
        func_021C7B3C(p, bi, y, x);
        func_021CC95C(&p->lock, s, line + 3);
        func_021D66D0((struct QJ *)a, y);
        func_021D66D0((struct QJ *)b, x);
        func_021D8564((int)a, (int)b);
        func_021CD4B0(p->fC, 0x58, ai);
        func_021CD4B0(p->fC, 0x58, bi);
        if (x != y) {
            t = func_021CC8D8(&p->lock, line + 16);
            func_021C7B7C(p, ai);
            func_021C7B7C(p, bi);
            line += 19;
            func_021CC95C(&p->lock, t, line);
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 16) == 0) {
            if (x == 0x67) func_021C195C(p, a, 0);
            if (x == 0x7f) func_021C3FDC(p, a);
        }
        if (func_021D62C4((struct Unk021D62A8 *)b, 16) == 0) {
            if (y == 0x67) func_021C195C(p, b, 0);
            if (y == 0x7f) func_021C3FDC(p, b);
        }
    } else {
        func_021CD64C(p->fC, 0x5a, 0x47, 0xffff0000);
    }
}






















void func_021C3FDC(Server *p, u8 *a)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &cur)) {
        if (func_021B9A24(k, func_021D5440(cur)) == 0)
            func_021C195C(p, cur, 0);
    }
}






















int func_021C4034(Server *p, u8 *a)
{
    int n;
    int r;
    if (func_021D6D7C(a) == 0) {
        n = func_021D7B74(a, 4);
        if (func_021D59B4(a, 0xd) > n) {
            r = func_0689D5C8(p->w1ab8, func_021D5440(a));
            if (r != 6) {
                func_021C5B74(p, a, -n, 1);
                func_021C195C(p, a, 1);
                func_021D6D5C(a, n);
                func_021CD4B0(p->fC, 0x27, func_021D5440(a), (u16)n);
                func_021CD4B0(p->fC, 0x51, r);
                func_021CD64C(p->fC, 0x5b, 0x311, func_021D5440(a), 0xffff0000);
                return 1;
            }
        }
        func_021C5DAC(p, 0x7b, 0, 0);
    } else {
        func_021C5D88(p, a, 0x314);
    }
    return 0;
}





















/*
 * Opens with `push {r0-r3}`: the address of parameters 3-6 is taken; the
 * fifth and sixth parameters are one 8-byte struct passed by value.
 */
u16 func_021C4104(Server *p, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e)
{
    u16 ev = *e;
    u8 sav = sa;
    int m = func_021D5440(c);
    func_021CD4B0(p->fC, 0x54, m, sav, ev);
    func_021C5D88(p, c, 0x317);
    func_021C5840(p, 1, (int *)(&sa), &c, 0);
    func_021C59C4(p, 1, &c, &sb, 0);
    if (func_021D6D9C(c, &d))
        func_021C41C0(p, c);
    func_021C1DCC(p, (u8 *)e, (u32)q, c, d);
    func_021C1880(p, (u8 *)e, q, c, d, 1);
    func_021C4218(p, q, c, (u8 *)e, sa, d, sb, 1);
    return d;
}





















void func_021C41C0(Server *p, u8 *a)
{
    int i = func_021D5440(a);
    int r = func_0689D5C8(p->w1ab8, i);
    func_021C5D88(p, a, 0x31a);
    func_021D6D70(a);
    func_021CD4B0(p->fC, 0x28, i);
    func_021CD4B0(p->fC, 0x52, r);
}




















void func_021C4218(Server *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u32 s = func_021CC8D8(&p->lock, 9310);
    func_021C4268(p, a, b, c, s0, s1, s2, s3);
    func_021CC95C(&p->lock, s, 9313);
}





















void func_021C4268(Server *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u8 x = func_021D5440(b);
    func_021D74F8(9335);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, x);
    func_021D75EC(0x14, ((struct Obj07754 *)c)->f2);
    func_021D75EC(0x12, ((struct Obj07754 *)c)->f0);
    func_021D75EC(0x38, s0);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, ((struct Obj07754 *)c)->f8);
    func_021D75EC(0x32, s1);
    func_021D75EC(0x45, s2);
    func_021D75EC(0x46, s3);
    func_021D7630(0x47, 0);
    func_021D70F0(p, 0x4a);
    func_021D70F0(p, 0x4b);
    func_021D70F0(p, 0x4c);
    func_021D7540(9352);
}





















int func_021C4304(Server *p, u16 *b, u8 *a, u8 *c, int *out)
{
    u8 n1;
    u8 n2;
    u8 i;
    func_021D74F8(9370);
    func_021D75EC(3, func_021D5440(a));
    n1 = func_0689CD40(c);
    n2 = func_0689CD38(c);
    func_021D75EC(5, n2);
    func_021D7630(0x51, 1);
    for (i = 0; i < n2; i++) {
        func_021D75EC(i + 6, func_021D5440(func_0689CC70(c, i)));
    }
    func_021D75EC(0x12, *b);
    if (n1 != 0) {
        if (n2 != 0) {
            func_021D70F0(p, 0xa0);
        }
    } else {
        func_021D70F0(p, 0xa1);
    }
    *out = func_021D775C(0x51);
    func_021D7540(9402);
    if (func_021C88E4(p) != 0) {
        return 1;
    }
    return 0;
}


















void func_021C43F0(Server *p, u8 *a)
{
    u32 it;
    u8 *x;
    func_0689CB3C(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        func_0689CB48(a, x);
    }
    func_0689CF24(a, p);
}
















int func_021C446C(Server *p)
{
    u8 *a;
    u8 *q;
    int result = 0;
    a = p->f854;
    if (p->f77e == 0) {
        func_021C43F0(p, a);
        p->f77e = 1;
        func_021C4744(p);
    }
    switch (p->f77e) {
    case 0: break;
    case 1:
        p->f77e++;
        func_021CD4B0(p->fC, 0x56, 0);
        result = 0;
        if (func_021C4D1C(p, a)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 2:
        p->f77e++;
        if (func_021C4838(p, a, (u8 *)0x76)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 3:
        p->f77e++;
        if (func_021C493C(p, a)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 4:
        p->f77e++;
        func_021C4B8C(p);
        func_021C4C24(p);
    case 5:
        p->f77e++;
        if (func_021C4838(p, a, (u8 *)0x77)) { result = 1; break; }
        if (func_021BC2B0(p)) return 0;
    case 6:
        func_021C4838(p, a, (u8 *)0x78);
        p->f77e++;
        func_0689CC84(a);
        q = func_0689CC8C(a);
        while (q) {
            func_021D6408(q);
            func_021D6E88(q);
            func_021CD4B0(p->fC, 0x2e, func_021D5440(q));
            q = func_0689CC8C(a);
        }
        func_021C4614(p);
        func_021D701C();
        if (p->f10 < 9999) (p->f10)++;
        p->f77e = 0;
        p->f774 = 0;
        return 0;
    default: break;
    }
    return result;
}















void func_021C4614(Server *p)
{
    u32 first, a, b;
    char *x, *y;
    u8 *m, *n;
    u32 mi, ni;
    u8 s, t;
    u8 v, w;
    if (func_021B8588(p->f4) != 2) return;
    a = func_021B8FF4(p->f4);
    first = a;
    b = (u8)func_021B9064(p->f4, a, 0);
    if (a > b) { first = b; b = a; }
    x = func_021B9AEC(p->f8, first);
    y = func_021B9AEC(p->f8, b);
    if (func_021B9B98((u8 *)x) != 1) return;
    if (func_021B9B98((u8 *)y) != 1) return;
    m = func_021B9CE8((u8 *)x);
    n = func_021B9CE8((u8 *)y);
    mi = func_021D5440(m);
    ni = func_021D5440(n);
    s = func_0689D5C8(p->w1ab8, mi);
    t = func_0689D5C8(p->w1ab8, ni);
    if (s == 6 || t == 6) return;
    v = func_021B8DEC(p->f4, s);
    w = func_021B8DEC(p->f4, t);
    if (v != w) return;
    if (func_021B99F0(s) != 0) return;
    func_021CD4B0(p->fC, 0x50, first, v, b, w);
    func_021BD43C(p, first, v, 1, 1);
    func_021BD43C(p, b, w, 1, 1);
    func_021BD4E4(p, first, v, 1);
    func_021BD4E4(p, b, w, 1);
}















/*
 * Verified with one --thumb without region, dsi/1.1p1 -O4,p:
 * typedef unsigned int u32;
 * typedef struct { u32 a[8]; } Block;
 * typedef struct { u32 mode, old, other; Block current, previous; } State;
 * 0x0202E7E0 EXACT: u32 func_0202E7E0(State *p) { return p->mode; }
 * 0x0202E7E4 EXACT: void func_0202E7E4(State *p) {
 *     p->old = p->mode; p->previous = p->current; p->mode = 3;
 * }
 * lever: a u64 draw and a separate u32 slot preserve the high-product register.
 * note 2026-10-05 (D8 lane16): witnesses func_0202E7E0 and func_0202E7E4 filed as src/matched/arm9/func_0202E7E0.c and func_0202E7E4.c (both EXACT); this file becomes EXACT once the integrator seeds them.
 */
void func_021C4744(Server *p)
{
    u8 list[4];
    u8 i, n;
    void *work;
    u32 mode, side;
    u8 *desc, *m;
    u32 value, slot;
    u64 draw;
    u8 id;
    int live;
    work = (void *)func_021B8630(p->f4);
    if (work == 0) return;
    mode = func_0202E7E0(work);
    if (mode == 0 || mode == 3) return;
    side = func_021B8FF4(p->f4);
    desc = func_021BB85C(p->f0, (int)side);
    i = 0;
    n = 0;
    for (; i < desc[9]; i++) {
        m = func_021B990C(p->f8, side, (u8)i);
        if (m != 0) {
            if (func_021D5B68(m) == 0) live = 1;
            else live = 0;
        } else live = 0;
        if (live) {
            if (func_021D5B48(m) == 0) list[n++] = func_021D5440(m);
        }
    }
    if (n == 0) return;
    draw = func_0203F0A8();
    slot = (u32)draw;
    if (n != 0) slot = (u32)((draw * (u32)n) >> 32);
    id = list[slot];
    m = func_021B9934(p->f8, id);
    value = (u32)func_021D59B4(m, 14);
    if (mode == 1) value >>= 1;
    if (value == 0) return;
    if (func_021C334C(p, m, (u16)value, (u32)0)) {
        func_021CD64C(p->fC, (u32)0x5a, 0x53, 4, id, 0xffff0000);
        func_0202E7E4(work);
    }
}
















int func_021C4838(Server *p, u8 *a, u8 *b)
{
    u32 s;
    u8 *q;
    func_0689CC84(a);
    s = func_021CC8D8(&p->lock, 9644);
    func_021C4910(p, 0x1f, (int)b);
    func_021CC95C(&p->lock, s, 9646);
    if (func_021BC2B0(p) == 0) {
        q = func_0689CC8C(a);
        if (q != 0) {
            do {
                s = func_021CC8D8(&p->lock, 9652);
                func_021C4910(p, func_021D5440(q), (int)b);
                func_021CC95C(&p->lock, s, 9654);
                func_021C4F64(p, q);
                if (func_021BC2B0(p) != 0) {
                    break;
                }
                q = func_0689CC8C(a);
            } while (q != 0);
        }
    }
    return func_021C5200(p);
}














void func_021C4910(Server *p, u32 a, int k)
{
    func_021D74F8(9667);
    func_021D75EC(2, a);
    func_021D70F0(p, k);
    func_021D7540(9670);
}














/*
 * lever: the first out-value is a one-word struct passed by value.
 */
int func_021C493C(Server *p, u8 *a)
{
    u8 list[6];
    union Slot y;
    u32 x;
    u32 i, n, k, s;
    u8 *q, *m;
    list[0] = 0;
    list[1] = 0;
    list[2] = 0;
    list[3] = 0;
    list[4] = 3;
    list[5] = 0;
    i = 0;
    n = func_0689CD38(a);
    for (; i < n; i++) list[i] = func_021D5440(func_0689CC70(a, i));
    k = 0;
    for (;;) {
        q = func_0689C9F8(k++);
        if (q == 0) break;
        for (i = 0; i < n; i++) {
            m = func_021B9934(p->f8, list[i]);
            if (func_021D5B68(m) == 0) {
                if (func_021D6064(m, (u32)q, (union Slot *)(&y), (int *)(&x))) {
                    s = func_021CC8D8(&p->lock, 9719);
                    func_0689B7A8(m, q, y, x, p);
                    func_021CC95C(&p->lock, s, 9721);
                }
            }
        }
        if (func_021BC2B0(p)) break;
    }
    func_021CD4B0(p->fC, 0x15, (u8)n, (u8)k, func_021D806C(list));
    return func_021C5200(p);
}












void func_021C4A64(Server *p, u8 *a, u32 b, u32 c)
{
    u32 lock;
    int r;
    lock = func_021CC8D8(&p->lock, 0x261b);
    r = func_021C4B3C(p, a, b, c);
    if (r && func_021C20BC(p, a, r)) {
        switch (b) {
        case 0: case 1: case 2: case 3: break;
        case 5: func_021C5480(p, a, 0x257); break;
        case 4: func_021C5480(p, a, 0x258); break;
        case 6: case 7: case 8: break;
        case 10: func_021C5480(p, a, 0x273); break;
        case 9: func_021C5480(p, a, 0x274); break;
        }
        func_021C8810(p->w1ae4);
        func_0689B8CC(p->w1ae4, a, b);
        func_021C20D0(p, a, r, p->w1ae4);
    }
    func_021CC95C(&p->lock, lock, 0x263b);
}














int func_021C4B3C(Server *p, u8 *a, u32 b, u32 c)
{
    int r;
    func_021D74F8(9801);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x1d, b);
    func_021D75A8(0x32, c);
    func_021D70F0(p, 0x6b);
    r = func_021D775C(0x32);
    func_021D7540(9807);
    return r;
}















/*
 * C tail call through r3 into the ov095 walker func_06898D54 (ov095 is
 * loaded in VRAM at 0x0689xxxx), with the ov093 callback func_021C4B9C.
 * Earlier notes called this a linker thunk; it is plain mwcc C.
 * 2026-10-05 (D9r lane16): every byte right; MATCH only because the ABS32
 * to func_021C4B9C needs that file's manifest shard (filed EXACT this wave).
 * Re-run after the shard lands; expected EXACT, then move to src/matched/ov.
 */
void func_021C4B8C(Server *p)
{
    func_06898D54((void (*)(u8,  u32,  u32))func_021C4B9C, (u32)p);
}















void func_021C4B9C(int v, int k, Server *p)
{
    func_021C4BAC(p, k, v);
}















void func_021C4BAC(Server *p, int k, int v)
{
    int r = -1;
    switch (k) {
    case 0: r = 0x7e; break;
    case 1: r = 0x82; break;
    case 2: r = 0x86; break;
    case 3: r = 0x8a; break;
    case 4: r = 0x8e; break;
    case 5: r = 0x92; break;
    case 6: r = 0x96; break;
    case 7: r = 0x9a; break;
    case 8: r = 0x9e; break;
    case 9: break;
    case 10: break;
    case 11: r = 0xa6; break;
    case 12: r = 0xaa; break;
    case 13: r = 0xae; break;
    }
    if (r >= 0) {
        func_021CD64C(p->fC, 0x5a, r, v, 0xffff0000);
    }
}














/*
 * The extent continues into the existing SDK CallbackForJpeg at 021C4C40.
 * DWC_StartUtilityEx takes two full-word payloads; the original passes
 * the callback address and p unchanged in r0/r1.
 */
void func_021C4C24(Server *p)
{
    func_021EF934((int)func_021C4C40, (int)p);
    func_021CD4B0(p->fC, 47, 0);
}














void CallbackForJpeg(int result, void *arg)
{
    func_021C4C50(arg, result);
}














void func_021C4C50(Server *p, int k)
{
    int r = -1;
    u8 *q;
    switch (k) {
    case 0: break;
    case 1: r = 0x74; break;
    case 2: r = 0x76; break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: r = 0xb3; break;
    case 7: r = 0xb5; break;
    }
    if (r >= 0) {
        func_021CD64C(p->fC, 0x5a, r, 0xffff0000);
    }
    func_021CD4B0(p->fC, 0x24, (u8)k);
    if (k == 7) {
        func_021C43F0(p, p->f868);
        func_0689CC84(p->f868);
        q = func_0689CC8C(p->f868);
        while (q) {
            if (func_021D5B7C(q)) {
                func_021C195C(p, q, 0);
            }
            q = func_0689CC8C(p->f868);
        }
    }
}










int func_021C4D1C(Server *p, void *it)
{
    int r;
    int changed;
    int mode;
    u8 *a;
    u32 lock;
    int line;
    r = func_021EF8B8();
    if (r) {
        func_021CD4B0(p->fC, 0x40, r);
        func_021C3BE0(p, 0);
        return 0;
    }
    changed = 0;
    mode = func_021C2AB0(p);
    func_0689CC84(it);
    a = func_0689CC8C(it);
    if (a) {
        line = 0x26c6;
        line += 12;
        do {
            if (!func_021D5B68(a) && !func_021D5BDC((struct UtilWork *)a, 5) && !func_021D5BDC((struct UtilWork *)a, 4)) {
                lock = func_021CC8D8(&p->lock, 0x26c6);
                r = func_021C4E38(p, a, mode, func_021D7BD4(a, mode));
                if (r) {
                    func_021C4EA4(p, a, mode, r);
                    changed = 1;
                }
                func_021CC95C(&p->lock, lock, line);
                func_021C4F64(p, a);
            }
            a = func_0689CC8C(it);
        } while (a);
    }
    if (changed) func_021C70E4(p, 0x255, 6, 6, 0, 0);
    return func_021C5200(p);
}











int func_021C4E38(Server *p, u8 *a, u32 b, u32 c)
{
    u8 f;
    int r;
    int s;
    func_021D74F8(9960);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x39, b);
    r = 0;
    func_021D7630(0x41, 0);
    func_021D75A8(0x32, c);
    func_021D70F0(p, 0x7f);
    s = func_021D775C(0x32);
    f = func_021D775C(0x41);
    func_021D7540(9969);
    if (f == 0) {
        r = s;
    }
    return r;
}












void func_021C4EA4(Server *p, u8 *a, int k, int n)
{
    u8 x = func_021D5440(a);
    switch (k) {
    case 4:
        func_021C8838(p->w1ae4, 2, 396);
        func_021C8860((struct S_p12 *)p->w1ae4, x);
        break;
    case 3:
        func_021C8838(p->w1ae4, 2, 399);
        func_021C8860((struct S_p12 *)p->w1ae4, x);
        break;
    default:
        func_021C8810(p->w1ae4);
        break;
    }
    if (n > 0 && func_021C20BC(p, a, n) != 0) {
        func_021C99A0(p, (const struct Msg *)p->w1ae4);
        func_021C8810(p->w1ae4);
        func_021C70E4(p, 0x290, func_021C8010(p, x), 6, 0, 0);
        if ((int)func_021D59B4(a, 0xd) <= n) {
            func_021C70E4(p, 0x255, 6, 6, 0, 0);
        }
        func_021C20D0(p, a, n, 0);
    }
}











/*
 * note: 2026-10-05 recoup: `ok = 0;` written after the call to func_021C5108 (it is
 * only read by the later compare), not before it; this puts the zero store in r2 as in the
 * original. EXACT in c99 and c. Callees: func_021D59B4 and func_021BA1A8 return int,
 * func_021B8DDC (unlabelled in ov093 matched set) returns u8, func_021C5108 and
 * func_021B92B0 are void with three arguments.
 */
int func_021C4F64(Server *p, u8 *a)
{
    u8 k = func_021D5440(a);
    u8 *flags = p->w7a9;
    int ok;
    int side;
    int health;
    if (!flags[k] && func_021D5B68(a)) {
    flags[k] = 1;
    func_0689D15C(p->g3e0, k);
    if (!(func_021BA1A8(p->f4, 0x200) && func_021B8DDC(k) != 0) && p->f789 != k)
        func_021CD64C(p->fC, 0x5b, 0, k, 0xffff0000);
    func_021CD4B0(p->fC, 0x39, k);
    func_021C5108(p, a, 0);
    ok = 0;
    func_021D646C(a);
    side = func_021B8DDC(k);
    if (side == func_021B8FF4(p->f4)) {
        health = func_021D59B4(a, 15);
        if (health + 30 <= (int)func_021C5098(p)) ok = 1;
        func_021B92B0((char *)(p->f4), a, ok);
    }
    func_0689D2F8(p->w1ab8, k);
    side = func_021B8DDC(k);
    {
        int current = func_021B8FF4(p->f4);
        if (side == current) {
            func_021BA1B4((char **)(p->f4), 0x4c);
        } else if (!func_021B902C(side, current)) {
            func_021BA1B4((char **)(p->f4), 0x19);
            func_021BA1B4((char **)(p->f4), 0x52);
        }
    }
    return 1;
    }
    return 0;
}









u32 func_021C5098(Server *p)
{
    u32 best = 1;
    u32 n = func_021B8640((unsigned int **)(p->f4));
    u8 x = func_021B8FF4(p->f4);
    u32 i;
    for (i = 0; i <= n; i++) {
        if (func_021B902C(x, func_021B8DE4((char *)(p->f4), (u8)i)) == 0) {
            int r = func_0689D5FC(p->w1ab8, i);
            if (r != 0x1f) {
                u32 t = func_021D59B4((u8 *)func_021B9934(p->f8, r), 0xf);
                if (t > best) {
                    best = t;
                }
            }
        }
    }
    return best;
}









/*
 * extent: 198 compiled bytes followed by two zero padding bytes at 021C51CE.
 */
void func_021C5108(Server *p, u8 *a, int b)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021C51D0(p, a);
    func_021BFF60(p, a, 0);
    if (b == 0) {
        func_021D8510(a);
        func_021DCF24(a);
    } else {
        func_021D8538(a);
        func_021DCFA4(a);
    }
    func_021E0434(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    func_021BD338((u8 *)&it, p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &cur)) {
        func_021D6264((struct UtilSlots *)cur, k);
        func_021CD4B0(p->fC, 0x2c, func_021D5440(cur), k);
    }
    func_021EF90C(k);
    func_021CD4B0(p->fC, 0x23, k);
    if (!func_021BC2B0(p) && (u16)func_021D59B4(a, 0x11) == 0x7f)
        func_021C3FDC(p, a);
}









void func_021C51D0(Server *p, u8 *a)
{
    int line = 0x27DF;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D70F0(p, 0xA3);
    func_021D7540(line + 3);
}








int func_021C5200(Server *p)
{
    int result = 0;
    u32 i;
    u32 count;
    u8 *a;
    if (func_021B85EC(p->f4)) {
        count = func_0689D174(p->g3e0, 0);
        for (i = 0; i < count; i++) {
            if (!func_0689D1A0(p->g3e0, 0, i)) {
                a = func_021B9934((char *)(p->f8), func_0689D184(p->g3e0, 0, i));
                if (!func_021B86B8(p->f4) && !((struct Flags_021C5108 *)&p->f78a)->b && func_021BC2B0(p) && func_021BC310(p)) {
                    func_021CD4B0(p->fC, 0x55, func_021B86DC(p->f4));
                    ((struct Flags_021C5108 *)&p->f78a)->b = 1;
                }
                if (func_021C5308(p, a)) result = 1;
                func_0689D1BC(p->g3e0, 0, i);
            }
        }
    }
    return result;
}

















int func_021C5308(Server *p, u8 *a)
{
    char *g;
    if (func_021B9A40(func_021D5440(a)) == 1) {
        g = func_021B9AEC(p->f8, func_021B8FF4(p->f4));
        func_021CB2D4(p, (u8 *)g, (u32)a, (Rec_021CAA58 *)p->w1b08);
        return func_021C5350(p, (u8 *)g, (const struct Entry_p11 *)p->w1b08);
    }
    return 0;
}

















/*
 * lever: const entry source schedules byte arguments early; k precedes entry in declarations.
 */
int func_021C5350(Server *p, u8 *g, const struct Entry_p11 *q)
{
    u32 i;
    int result = 0;
    u8 *a;
    int k;
    u32 value;
    int cmd;
    const struct Entry_p11 *entry;
    u32 remaining;
    for (i = 0; i < 6; i++) {
        entry = &q[i];
        if (!entry->value) continue;
        a = (u8 *)func_021B9BF0((struct S2 *)g, (u8)i);
        if (func_021D59B4(a, 15) >= 100) continue;
        value = entry->value;
        cmd = entry->flag ? 0x2b : 0x2a;
        k = func_021D5440(a);
        func_021CD64C(p->fC, 0x5a, (u16)cmd, k, value, 0xffff0000);
        func_021CD4B0(p->fC, 0x3e, k, q->a, q->b, q->c, q->d, q->e, q->f);
        remaining = value;
        while (func_021D69B8((struct Obj *)a, &remaining, (struct Result *)p->w4c0)) {}
        func_021CD4B0(p->fC, 0x45, k, value);
        func_021BA1CC(p->f4, 0x1b, value);
        result = 1;
    }
    return result;
}


















int func_021C5418(Server *p, u8 *a, int b)
{
    u8 n;
    if (func_021D5BDC((struct UtilWork *)a, b)) {
        n = func_021D5440(a);
        func_021C6110(p, a, b);
        b = 0x1a;
        if (func_021D62C4((struct Unk021D62A8 *)a, 0x1a)) {
            func_021C5620(p, a, b, 0);
        }
        func_021CD4B0(p->fC, 0x31, n, 0);
        func_021BD1D0(p, n);
        return 1;
    }
    return 0;
}


















void *func_021C5474(char *p)
{
    ((struct Obj21097 *)p)->f220 = 0;
    return p;
}


















void func_021C5480(Server *p, u8 *a, int b)
{
    int r = func_0689D5C8(p->w1ab8, func_021D5440(a));
    if (r != 6) {
        func_021CD4B0(p->fC, 0x4d, r, b);
    }
}


















/*
 * leaf: Sole blocker of func_021BCCE0; ordinary default-argument tail call.
 * extent: Next function 021C54C8 is already separately matched; 12-byte leaf.
 * semantics: Forwards both pointer inputs unchanged; literal argument 0x350.
 */
void func_021C54BC(Server *p, u8 *a)
{
    func_021C5D88(p, a, 0x350);
}



















void func_021C54C8(Server *p, u8 *a)
{
    func_021C5480(p, a, 0x25B);
    func_021CD64C(p->fC, 0x5b, 0x15C, func_021D5440(a), 0xffff0000);
}



















void func_021C54FC(Server *p, u8 *a)
{
    u8 v = func_021D62D8((struct UtilSlots *)a, 7);
    func_021C5480(p, a, 0x25C);
    func_021CD64C(p->fC, 0x5b, 0x14d, func_021D5440(a), v, 0xffff0000);
}


















void func_021C5540(Server *p, u8 *a, int c)
{
    int n;
    n = func_021D5440(a);
    func_021CD4B0(p->fC, 0x36, n);
    func_021C5B74(p, a, (int)(0u - (u32)c), 1);
    func_021CD64C(p->fC, 0x5a, 0x50, n, 0xffff0000);
}



















void func_021C557C(Server *p, u8 *a, int k, int flag)
{
    u8 n = func_021D5440(a);
    func_021D61F0((struct UtilSlots *)a);
    func_021CD4B0(p->fC, 0x10, n);
    func_021CD4B0(p->fC, 0x35, n, 0);
    if (flag != 0) {
        switch (k) {
        case 2:
            func_021CD64C(p->fC, 0x5b, 0x138, n, 0xffff0000);
            break;
        case 3:
            func_021CD64C(p->fC, 0x5b, 0x126, n, 0xffff0000);
            break;
        default:
            func_021CD64C(p->fC, 0x5b, 0x156, n, 0xffff0000);
            break;
        }
    }
}



















void func_021C5604(Server *p, u8 *a, int b)
{
    func_021CD4B0(p->fC, 0x59, func_021D5440(a), b);
}
















void func_021C5620(Server *p, u8 *a, int k, union Slot *out)
{
    u8 n;
    if (k != 0) {
        n = func_021D5440(a);
        if (out != 0) *out = func_021D6314(a, k);
        if (k < 6) {
            func_021D61F0((struct UtilSlots *)a);
            func_021CD4B0(p->fC, 0x10, n);
            if (func_0689D5C8(p->w1ab8, n) != 6) {
                func_021CD4B0(p->fC, 0x35, n, 0);
            }
        } else {
            func_021D6238((struct UtilSlots *)a, k);
            func_021CD4B0(p->fC, 0x11, n, (u16)k);
        }
    }
}

















int func_021C56A8(u8 *p, int *pv)
{
    int ret = 0;
    int r = func_021D62A8((struct Unk021D62A8 *)p);
    int t;
    switch (*pv) {
    case 0:
        break;
    case 0x24:
        if (r) ret = r;
        *pv = 0;
        break;
    case 0x25:
        if (r) {
            ret = r;
            *pv = 6;
        } else {
            if (func_021D62C4((struct Unk021D62A8 *)p, 6)) ret = 6;
            *pv = 0;
        }
        break;
    case 0x26:
        t = func_021D7E10((struct Unk021D62A8 *)p);
        if (t) return t;
        *pv = ret;
        return t;
    default:
        if (func_021D62C4((struct Unk021D62A8 *)p, *pv)) ret = *pv;
        *pv = 0;
        break;
    }
    return ret;
}

















/* 021C5718  4-arg call, field 0xc and the pool constant 0xffff0000 */
void func_021C5718(Server *p, u8 *a, u32 b)
{
    func_021CD64C((void *)(p->fC), 0x5a, 0x47, 0xffff0000);
}



















void func_021C572C(Server *p, u8 *a, u32 v)
{
    func_021CD64C(p->fC, 0x5b, 213, func_021D5440(a), 0xffff0000);
}



















void func_021C5750(Server *p, u8 *a)
{
    func_021CD64C(p->fC, 0x5b, 210, func_021D5440(a), 0xffff0000);
}



















void func_021C5774(Server *p, u8 *a)
{
    func_021CD64C(p->fC, 0x5b, 216, func_021D5440(a), 0xffff0000);
}




















void func_021C5798(Server *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2)
{
    u32 i;
    u8 hi;
    u8 lo;
    int k;
    lo = 0;
    hi = 0;
    for (i = 0; i < n; i++) {
        func_021C604C(p, ptrs[i], vals[i]);
        if (arr[i] > 3) hi++;
        if (arr[i] < 3) lo++;
    }
    if (hi) k = 2;
    else if (lo) k = 3;
    else k = 1;
    func_021CD4B0(p->fC, 0x33, (u8)n, (u8)k, *a);
    for (i = 0; i < n; i++) {
        func_021CD63C(p->fC, func_021D5440(ptrs[i]));
    }
}



















void func_021C5840(Server *p, u32 count, int *v, u8 **a, int flag)
{
    u8 low = 0;
    u8 high = 0;
    u32 i;
    u8 list[3];
    for (i = 0; i < count; i++) {
        if (v[i] > 3) high++;
        if (v[i] < 3) low++;
    }
    if (flag) {
        if (high) {
            u8 n = 0;
            for (i = 0; i < count; i++) {
                if (v[i] > 3) list[n++] = func_021D5440(a[i]);
            }
            switch (high) {
            case 1: func_021CD64C(p->fC, 0x5b, 6, list[0], 0xffff0000); break;
            case 2: func_021CD64C(p->fC, 0x5b, 9, list[0], list[1], 0xffff0000); break;
            case 3: func_021CD64C(p->fC, 0x5b, 12, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
        if (low) {
            u8 n;
            i = 0;
            n = 0;
            for (; i < count; i++) {
                if (v[i] < 3) list[n++] = func_021D5440(a[i]);
            }
            switch (low) {
            case 1: func_021CD64C(p->fC, 0x5b, 15, list[0], 0xffff0000); break;
            case 2: func_021CD64C(p->fC, 0x5b, 18, list[0], list[1], 0xffff0000); break;
            case 3: func_021CD64C(p->fC, 0x5b, 21, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
    } else {
        if (high) func_021CD64C(p->fC, 0x5a, 78, 0xffff0000);
        else if (low) func_021CD64C(p->fC, 0x5a, 79, 0xffff0000);
    }
}




















void func_021C59C4(Server *p, u32 n, u8 **a, u8 *b, int flag)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (b[i]) {
            if (flag) {
                func_021CD64C(p->fC, 0x5b, 0x180, func_021D5440(a[i]), 0xffff0000);
            } else {
                func_021CD64C(p->fC, 0x5a, 0x51, 0xffff0000);
            }
        }
    }
}


















void func_021C5A1C(Server *p, u8 *a)
{
    func_021CD4B0(p->fC, 0x57, func_021D5440(a));
}


















void func_021C5A34(Server *p, u8 *a)
{
    func_021CD4B0(p->fC, 0x58, func_021D5440(a));
}



















void func_021C5A4C(Server *p, u8 *a, int b, int c)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021CD64C(p->fC, 0x5b, 0x99, n, b, 0xffff0000);
    } else {
        func_021CD64C(p->fC, 0x5b, 0xae, n, b, 0xffff0000);
    }
}

















void func_021C5A8C(Server *p, u8 *a, int c, int d, u16 msg, int flag)
{
    u8 n = func_021D5440(a);
    if (d > 0) {
        int x = func_021D5DC0((s8 *)a, c, d);
        u8 t = x;
        func_021CD4B0(p->fC, 9, n, (u8)c, t);
        func_021CD4B0(p->fC, 0x37, n, (u8)c, t);
        if (flag) {
            if (msg == 0) func_021CD64C(p->fC, 0x5b, 0x1b, n, c, x, 0xffff0000);
            else func_021CD64C(p->fC, 0x5b, 0x3aa, n, msg, c, x, 0xffff0000);
        }
    } else {
        int x = func_021D5E38((s8 *)a, c, -d);
        u8 t = x;
        func_021CD4B0(p->fC, 10, n, (u8)c, t);
        func_021CD4B0(p->fC, 0x38, n, (u8)c, t);
        func_021CD64C(p->fC, 0x5b, 0x5a, n, c, x, 0xffff0000);
    }
}


















void func_021C5B74(Server *p, u8 *a, int c, int d)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021D5FA4((struct Unk021D5FA4 *)a, (u16)c);
        func_021CD4B0(p->fC, 2, n, (u16)c);
    } else if (c < 0) {
        func_021C604C(p, a, -c);
    }
    if (d) {
        if (func_0689D5C8(p->w1ab8, n) != 6) {
            func_021CD4B0(p->fC, 0x41, n);
        }
    }
}
















void func_021C5BE4(Server *p, u8 *a, int c)
{
    int n;
    func_021D59B4(a, 13);
    n = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(p->fC, 3, n);
    func_021CD4B0(p->fC, 0x43, n, c);
}

















void func_021C5C1C(Server *p, u8 *a, int k, union Slot s)
{
    u8 n = func_021D5440(a);
    func_021D6034(a, k, s);
    func_021CD4B0(p->fC, 0xf, n, (u8)k, s.raw);
    if (k < 6) {
        if (k == 5 && func_021E8A78(s)) k = 6;
        func_021CD4B0(p->fC, 0x35, n, k);
    }
}
















void func_021C5C74(Server *p, u8 *a, int kind, u32 v)
{
    u8 n = func_021D5440(a);
    switch (kind) {
    case 1:
        switch (v) {
        case 5: func_021CD64C(p->fC, 0x5b, 0xf9, n, 0xffff0000); break;
        case 4: func_021CD64C(p->fC, 0x5b, 0x10b, n, 0xffff0000); break;
        case 1: func_021CD64C(p->fC, 0x5b, 0x11a, n, 0xffff0000); break;
        case 2: func_021CD64C(p->fC, 0x5b, 0x13b, n, 0xffff0000); break;
        case 3: func_021CD64C(p->fC, 0x5b, 0x129, n, 0xffff0000); break;
        case 6: func_021CD64C(p->fC, 0x5b, 0x162, n, 0xffff0000); break;
        case 15: func_021CD64C(p->fC, 0x5b, 0x18, n, 0xffff0000); break;
        case 20: return;
        default: func_021CD64C(p->fC, 0x5a, 0x47, 0xffff0000); break;
        }
        p->f78a.raw |= 0x10;
        break;
    case 2:
        func_021CD64C(p->fC, 0x5b, 0xd2, n, 0xffff0000);
        p->f78a.raw |= 0x10;
        break;
    default:
        func_021CD64C(p->fC, 0x5a, 0x47, 0xffff0000);
        p->f78a.raw |= 0x10;
        break;
    }
}

















void func_021C5D88(Server *p, u8 *a, int b)
{
    func_021CD64C(p->fC, 0x5b, b, func_021D5440(a), 0xffff0000);
}

















void func_021C5DAC(Server *p, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        func_021CD64C(p->fC, 0x5a, a, 0xffff0000);
        break;
    case 1:
        func_021CD64C(p->fC, 0x5a, a, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(p->fC, 0x5a, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(p->fC, 0x5a, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(p->fC, 0x5a, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}

















void func_021C5E48(Server *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(p->fC, 0x5c, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(p->fC, 0x5c, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(p->fC, 0x5c, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(p->fC, 0x5c, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(p->fC, 0x5c, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}

















void func_021C5EFC(Server *p, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        func_021CD64C(p->fC, 0x5b, a, 0xffff0000);
        break;
    case 1:
        func_021CD64C(p->fC, 0x5b, a, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(p->fC, 0x5b, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(p->fC, 0x5b, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(p->fC, 0x5b, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}

















void func_021C5F98(Server *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(p->fC, 0x5d, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(p->fC, 0x5d, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(p->fC, 0x5d, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(p->fC, 0x5d, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(p->fC, 0x5d, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}
















void func_021C604C(Server *p, u8 *a, int n)
{
    if (func_021B911C(p->f4, 4) == 0) {
        func_021D5F90(a, n);
        func_021CD4B0(p->fC, 1, func_021D5440(a), (u16)n);
    }
}

















void func_021C6080(Server *p, u8 *a, int b, int c, int d)
{
    u8 n = func_021D5440(a);
    if (d) {
        func_021D56A0(a, b, c);
        func_021CD4B0(p->fC, 8, n, b, c);
    } else {
        func_021D5674(a, b, c);
        func_021CD4B0(p->fC, 7, n, b, c);
    }
}
















void func_021C60D4(Server *p, u8 *a)
{
    func_021CD4B0(p->fC, 0x42, func_021D5440(a));
}
















void func_021C60EC(Server *p, u8 *a, u32 n)
{
    func_021D5FE4(a, n);
    func_021CD4B0(p->fC, 0x19, func_021D5440(a), n);
}
















void func_021C6110(Server *p, u8 *a, unsigned int n)
{
    func_021D6008(a, n);
    func_021CD4B0(p->fC, 0x1a, func_021D5440(a), n);
}
















void func_021C6134(Server *p, u8 *a, unsigned int n)
{
    func_021D5FC0((struct UtilWork *)a, n);
    func_021CD4B0(p->fC, 0x1b, func_021D5440(a), n);
}
















void func_021C6158(Server *p, u8 *a)
{
    unsigned int i;
    struct Arr *arr;
    for (i = 0; i < a[0]; i++) {
        arr = (struct Arr *)func_021B9AEC(p->f8, a[i + 1]);
        func_021CD4B0(p->fC, 0x2a, a[i + 1]);
        func_021B9D10(p->f4, arr, a[i + 1]);
    }
}
















static inline u16 entry_key(Entry *e)
{
    if (e->b.full.type == 1) return e->b.full.move;
    return 0;
}
















int func_021C6190(Server *p, u8 *a)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        u16 key;
        if (p->e[i].a == a) continue;
        if (p->e[i].done) continue;
        key = entry_key(&p->e[i]);
        if (key == 228) {
            if (func_021E02DC(p->e[i].a, key, func_021D59B4(p->e[i].a, 12)))
                p->e[i].f = 1;
        }
    }
    p->f788 = 0;
    func_021D74F8(11288);
    func_021D75EC(6, func_021D5440(a));
    func_021D70F0(p, 0x53);
    func_021D7540(11291);
    for (i = 0; i < p->n; i++) {
        u16 key;
        if (p->e[i].f) {
            key = entry_key(&p->e[i]);
            if (key == 228) func_021E03D8(p->e[i].a, key);
            p->e[i].f = 0;
        }
    }
    return p->f788;
}
















int func_021C62D8(Server *p, u8 *a, u32 unused, u32 c, struct O_p11 *out)
{
    int t;
    int line = 11327;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0xE, c);
    func_021D75A8(0x12, 0);
    func_021D75A8(0xD, 6);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x18);
    out->h = func_021D775C(0x12);
    out->b = func_021D775C(0xD);
    t = func_021D775C(0x41);
    func_021D7540(line + 13);
    return t == 0;
}
















u8 func_021C6350(Server *p, u8 *a)
{
    u8 r;
    func_021D74F8(11357);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x11, 1);
    func_021D70F0(p, 0xF);
    r = func_021D775C(0x11);
    func_021D7540(11362);
    return r;
}















void func_021C6394(Server *p, u8 *a, unsigned int n)
{
    func_021D74F8(11378);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(0x12, n);
    func_021D70F0(p, 0x15);
    func_021D7540(11382);
}
















u32 func_021C63D0(Server *p, u8 *q)
{
    u16 dmg;
    int r;
    int a = func_021D59B4(q, 8);
    int b = func_021D59B4(q, 9);
    int c = func_021D59B4(q, 0xF);

    dmg = func_021D7A44(0x28, a, c, b);
    dmg = _u32_div_f((100 - func_021D78AC(16)) * dmg, 100);
    if (dmg == 0) {
        dmg = 1;
    }
    r = func_021C1678(p, q, q, 0, &dmg);
    func_021C5540(p, q, dmg);
    if (r != 0) {
        func_021C16F8(p, q, r);
    }
    return dmg;
}
















int func_021C6458(Server *p, u8 *a, u32 c, u32 d, u8 *e)
{
    int r;
    int line = 11440;
    func_021C8810(e);
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, d);
    func_021D75EC(0x3F, (u32)e);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x19);
    r = func_021D775C(0x51);
    func_021D7540(line + 7);
    return r;
}
















/*
 * Byte-correct except the call to the unlabelled arm9 leaf 0x0201C1E8,
 * which has no witness outside this function (evidence class: none until the
 * leaf is filed; it is the integrator's, inside a labelled arm9 region). Verified C for
 * that leaf (`one` --thumb, no --region, EXACT, 12 bytes):
 *
 *   extern u32 sub_0201BD28(void *p, u32 id);   // symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 sub_0201C1E8(void *p) { return sub_0201BD28(p, 2); }
 *
 * Once the leaf's shard exists re-run this file; it should go EXACT.
 */
void func_021C64B4(Server *p, u16 q, u8 *a, struct Out64B4 *out)
{
    int line = 11464;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x16, sub_0201C1C8((void *)q));
    func_021D75A8(0x1C, func_021D57FC(a));
    func_021D75A8(0x1A, sub_0201C1E8(q));
    func_021D75A8(0x1B, sub_0201BD28(q, 0x1B));
    func_021D7630(0x4B, 0);
    func_021D70F0(p, 0x28);
    out->h0 = q;
    out->h2 = q;
    out->b6 = func_021D775C(0x16);
    out->h4 = func_021D775C(0x1C);
    out->w8 = func_021D775C(0x1A);
    out->wC = func_021D775C(0x1B);
    out->w10 = 0;
    if (func_021D775C(0x4B) != 0) {
        out->b6 = 0x11;
    }
    func_021D7540(11493);
}
















void func_021C6564(Server *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(11508);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x22, d);
    func_021D70F0(p, 0x21);
    func_021D7540(11513);
}
















int func_021C65A8(Server *p, u8 *a, u32 e, u8 *d)
{
    u32 n;
    u32 i;
    int r;
    u16 t;
    n = func_0689CD38(d);
    func_021D74F8(11533);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, e);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_0689CC70(d, i)));
    }
    func_021D7630(0x3E, 0);
    func_021D7630(0x13, 0);
    func_021D70F0(p, 0x24);
    r = func_021D775C(0x3E);
    t = func_021D775C(0x13);
    func_021D7540(11550);
    if (t != 0) {
        *(u16 *)p->f4a8 = t;
    }
    return r;
}














int func_021C6668(Server *p, u8 *a, u8 *a2, u16 a3)
{
    int r;
    func_021D74F8(11574);
    func_021D75A8(3, func_021D5440(a));
    func_021D75A8(0x51, 0);
    func_021D70F0(p, 0x2E);
    r = func_021D775C(0x51);
    func_021D7540(11579);
    return r;
}














int func_021C66AC(Server *p, u8 *a, void *c)
{
    u8 *q;
    int r;
    q = func_0689CC70(c, 0);
    func_021D74F8(11599);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, q ? func_021D5440(q) : 0x1F);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x93);
    r = func_021D775C(0x41);
    func_021D7540(11605);
    return r;
}













int func_021C6720(Server *p, u8 *a, u32 c)
{
    int r;
    func_021D74F8(11622);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x94);
    r = func_021D775C(0x51);
    func_021D7540(11628);
    return r;
}













int func_021C676C(Server *p, u8 *a, u8 *d, u16 unused, u8 *out8, u32 *out32)
{
    u32 n;
    u32 i;
    int t;
    n = func_0689CD38(d);
    func_021D74F8(11648);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(5, n);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            func_021D75EC(i + 6, func_021D5440(func_0689CC70(d, i)));
        }
    } else {
        func_021D75EC(6, 0x1F);
    }
    func_021D7630(0x41, 0);
    func_021D7630(0x51, 0);
    func_021D7630(0x4F, 0);
    func_021D70F0(p, 0x95);
    if (func_021D775C(0x51) != 0) {
        *out8 = func_021D775C(6);
    } else {
        *out8 = 0x1F;
    }
    *out32 = func_021D775C(0x4F);
    t = func_021D775C(0x41);
    func_021D7540(11677);
    return t == 0;
}












void func_021C6848(Server *p, u8 *a)
{
    func_021D74F8(11692);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x96);
    func_021D7540(11695);
}












void func_021C6878(Server *p, u8 *a, int a2)
{
    func_021D74F8(11709);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x97);
    func_021D7540(11712);
}












int func_021C68A8(Server *p, u8 *a, u8 *d, u16 a3)
{
    u32 n;
    u32 i;
    u8 t;
    n = func_0689CD38(d);
    func_021D74F8(11731);
    func_021D75EC(3, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_0689CC70(d, i)));
    }
    func_021D70F0(p, 0x98);
    t = func_021D775C(0x41);
    func_021D7540(11742);
    return t == 0;
}













int func_021C6948(Server *p, u8 *a, u8 *b, u32 v)
{
    int r = 0;
    u32 t = func_021D5C08((struct UtilWork *)b);
    if (t != 0x10) {
        func_021D74F8(11765);
        func_021D75EC(3, func_021D5440(a));
        func_021D75EC(4, func_021D5440(b));
        func_021D75EC(0x21, t);
        func_021D7630(0x42, 1);
        func_021D70F0(p, 0x99);
        if (func_021D775C(0x42)) r = 1;
        func_021D7540(11775);
    }
    return r;
}














int func_021C69B8(Server *p, u8 *a, u32 c, u16 id)
{
    int r = sub_0201C1F4(id);
    if (r == 0) {
        func_021D74F8(0x2E15);
        func_021D75EC(3, func_021D5440(a));
        func_021D7630(0x51, 0);
        func_021D70F0(p, 0x32);
        r = func_021D775C(0x51);
        func_021D7540(0x2E1A);
    }
    return r;
}














int func_021C6A04(Server *p, u8 *a, u8 *b, struct Q *q)
{
    int x, y;
    u32 t = sub_0201BD28(q->h0, 4);
    func_021D74F8(0x2E2F);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, q->h0);
    func_021D75EC(0x1a, q->w8);
    func_021D7630(0x2b, t);
    func_021D7674(0x35, 4 << 10, 0x19A, 4 << 15);
    func_021D70F0(p, 0x34);
    x = func_021D775C(0x2b);
    y = func_021D775C(0x35);
    func_021D7540(0x2E39);
    return func_021D7B10(x, y);
}














int func_021C6A9C(Server *p, u8 *a, u8 *b, u16 id)
{
    u8 x, y, c;
    int r, t;
    x = func_021D59B4(a, 15);
    y = func_021D59B4(b, 15);
    if (x < y) return 0;
    func_021D74F8(0x2E5A);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    r = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x70);
    t = func_021D775C(0x41);
    func_021D7540(0x2E60);
    if (t) return r;
    if (func_021BF324(p, a, b)) {
        r = 1;
    } else {
        c = sub_0201BD28(id, 4);
        c += (u8)(x - y);
        if (func_021D78AC(100) < c) r = 1;
    }
    return r;
}














int func_021C6B5C(Server *p, u8 *a, u8 *b, u8 *q)
{
    int r;
    func_021D74F8(11907);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x16, q[6]);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x30);
    r = func_021D775C(0x51);
    func_021D7540(11914);
    return r;
}














void func_021C6BB8(Server *p, u8 *a, u8 *b)
{
    func_021D74F8(11928);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D70F0(p, 0x31);
    func_021D7540(11932);
}














#pragma opt_lifetimes off













/*
 * note 2026-10-05 (wave P13 B10): the older DIFF (12 B, p and h/r in each other's
 *   r4/r5) closed with #pragma opt_lifetimes off around the function, see
 *   docs/idioms/a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.md.
 *   Source is unchanged from the old draft. Plain literals already (11952, 0x2c).
 *   Callees: func_021D5F14 returns u8, func_021D7930 takes u8 (both matched);
 *   sub_0201BD28 and sub_0201C284 return u32 (matched arm9 units).
 */
int func_021C6BF8(Server *p, u8 *a, u8 *b, u16 q)
{
    int r, n;
    u16 h;
    h = sub_0201BD28(q, 7);
    h = h + func_021D5F14((struct UtilWork *)a);
    func_021D74F8(11952);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75A8(0x2c, h);
    r = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x36);
    if (func_021D775C(0x41) == 0) {
        if (sub_0201C284(q)) {
            r = 1;
        } else {
            n = func_021D775C(0x2c);
            if (n > 4) n = 4;
            r = func_021D7930((u8)((u16)n));
        }
        if (func_021B911C((void *)((int)p->f4), 3)) r = 1;
    }
    func_021D7540(11975);
    return r;
}














#pragma opt_lifetimes reset













/*
 * note 2026-10-05 (wave P8): earlier DIFF (288 vs 292 B) closed by local declaration
 *   order (line, n, v, t, y, z, x, then kind); spill slots follow it. Plain literals
 *   12019 and 12032 are EXACT, so no line local. Also EXACT with --lang c.
 */
int func_021C6CAC(Server *p, u8 *a, u16 b, int amount, int *out)
{
    u8 n, v;
    u8 t, y, z, x;
    int kind;
    n = func_021D5440(a);
    v = func_0201BD28((u32)b, 30);
    kind = 0;
    *out = kind;
    if (v) kind = KIND_FIRST;
    else {
        v = func_0201BD28((u32)b, 31);
        if (v) kind = KIND_SECOND;
    }
    if (func_0201C1BC(b) == 8) return 0;
    func_021D74F8(12019);
    func_021D75EC(3, n);
    func_021D75A8(0x35, v);
    func_021D75A8(0x36, 0);
    func_021D7630(0x41, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x50);
    x = func_021D775C(0x35);
    y = func_021D775C(0x41);
    z = func_021D775C(0x51);
    t = func_021D775C(0x36);
    func_021D7540(12032);
    if (z == 0 && y == 1) return 0;
    x += t;
    if (x) {
        if (kind == KIND_SECOND) {
            amount = func_021D7B3C(func_021D59B4(a, 14), x);
            if (amount < 1) amount = 1;
        } else if (amount != 0) {
            amount = func_021D7B3C(amount, x);
            if (amount < 1) amount = 1;
        }
        *out = z;
        return amount;
    }
    return 0;
}












void func_021C6DD0(Server *p, u8 *a)
{
    int line = 12077;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 114);
    func_021D7540(line + 3);
}












void func_021C6E00(Server *p, u8 *a, u8 k)
{
    int line = 12093;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(3, k);
    func_021D70E4(p, 115);
    func_021D7540(line + 4);
}












int func_021C6E3C(Server *p, u8 *a, u8 *b, u8 *q, int flag)
{
    int r, x;
    int changed = 0;
    if (q[6] == 17) return 3;
    x = func_021D57FC(b);
    r = func_021C7038(p, a, b, q[6], func_021E8CFC(x));
    if (func_021E8DA8(x) == 0)
        r = func_021D79E8(r, func_021C7038(p, a, b, q[6], func_021E8D04(x)));
    if (r != 0) {
        if (q[6] != 4) return r;
        changed = func_021C6F0C(p, b, 0);
        if (changed == 0) return r;
        r = 0;
    } else if (q[6] == 4) {
        if (func_021C6F0C(p, b, 1) == 0) return 3;
    }
    if (r == 0 && flag != 0) {
        if (changed == 0) func_021C5750(p, b);
        else func_021C6FC0(p, b);
    }
    return r;
}












int func_021C6F0C(Server *p, u8 *a, int k)
{
    if (func_021EF948(2) == 0 && func_021C6F34(p, a, k) != 0)
        return 1;
    return 0;
}











int func_021C6F34(Server *p, u8 *a, int f)
{
    int t;
    u8 x, y;
    if (f) {
        t = func_021D5814(a, 2);
    } else {
        t = 0;
    }
    func_021D74F8(12220);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, (u8)t);
    func_021D7630(0x41, (u8)0);
    func_021D70F0(p, 0x12);
    func_0689C6E4(p, a);
    x = func_021D775C(0x51);
    y = func_021D775C(0x41);
    func_021D7540(12228);
    if (y) return 0;
    return x;
}










void func_021C6FC0(Server *p, u8 *q)
{
    u32 v = func_021CC8D8(&p->lock, 12246);
    func_021C7008(p, q);
    if (func_021C88E4(p) != 2) func_021C5750(p, q);
    func_021CC95C(&p->lock, v, 12253);
}










void func_021C7008(Server *p, u8 *a)
{
    int line = 12265;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 27);
    func_021D7540(line + 3);
}











int func_021C7038(Server *p, u8 *a, u8 *b, u32 q, u8 s)
{
    int x, y, r;
    func_021D74F8(12290);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x15, s);
    func_021D75EC(0x16, q);
    func_021D7630(0x4b, 0);
    func_021D7630(0x4c, 0);
    func_0689C540(p, b);
    func_021D70F0(p, 0x3e);
    x = func_021D775C(0x4b);
    y = func_021D775C(0x4c);
    func_021D7540(12303);
    if (y) return 3;
    r = func_021D794C(q, s);
    if (r == 0 && x) r = 3;
    return r;
}











void func_021C70E4(Server *p, int a, int b, int c, int e, u32 f)
{
    int m;
    if (c != 6) {
        m = 2;
    } else {
        m = 1;
        if (b == 6) m = 0;
    }
    if (e) {
        switch (m) {
        case 0: func_021CD568(p->fC, f, 0x4c, a); return;
        case 1: func_021CD568(p->fC, f, 0x4d, b, a); return;
        case 2: func_021CD568(p->fC, f, 0x4e, b, c, a); return;
        }
    } else {
        switch (m) {
        case 0: func_021CD4B0(p->fC, 0x4c, a); return;
        case 1: func_021CD4B0(p->fC, 0x4d, b, a); return;
        case 2: func_021CD4B0(p->fC, 0x4e, b, c, a); return;
        }
    }
}











int func_021C7194(Server *p, u8 *a, u32 v)
{
    int r;
    func_021D74F8(12399);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x17, v);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x4f);
    r = func_021D775C(0x51);
    func_021D7540(12405);
    return r;
}











int func_021C71E0(Server *p, u8 *a, u32 x, u8 *out)
{
    u8 id = func_0201BD28(x, 8);
    u32 r;

    out[1] = 0;
    out[5] = 3;
    if (id > 1) {
        r = func_021D7BA4(id);
        func_021D74F8(12432);
        func_021D75EC(3, func_021D5440(a));
        func_021D75EC(0x29, id);
        func_021D75A8(0x2a, r);
        func_021D7630(0x51, 0);
        func_021D7630(0x42, 0);
        func_021D70F0(p, 0x35);
        if (id <= 5 && func_021D775C(0x51) != 0) {
            out[0] = id;
            out[2] = 0;
        } else {
            out[0] = func_021D775C(0x2a);
            out[2] = func_021D775C(0x42);
        }
        out[3] = 1;
        func_021D7540(12455);
        return 1;
    }
    out[0] = 1;
    out[2] = 0;
    out[3] = 0;
    return 0;
}











u16 func_021C728C(Server *p, u8 *a, u8 *b, const u8 *s)
{
    u32 t = func_0201C1D8((void *)(((struct Obj07759 *)s)->f0));
    u16 x;
    u32 y;

    func_021D74F8(12487);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, ((struct Obj07759 *)s)->f0);
    func_021D75EC(0x16, s[6]);
    func_021D75EC(0x1a, ((struct Obj07759 *)s)->f8);
    func_021D7630(0x30, t);
    func_021D70F0(p, 0x37);
    func_021D7674(0x31, 0x1000, 0x29, 0x200000);
    func_021D70F0(p, 0x38);
    x = func_021D775C(0x30);
    y = func_021D775C(0x31);
    func_021D7540(12500);
    return func_021D7B10(x, y);
}











int func_021C7330(Server *p, u8 *a)
{
    int r;
    func_021D74F8(12521);
    func_021D75EC(4, func_021D5440(a));
    func_021D7630(0x51, 1);
    func_021D70F0(p, 0x80);
    r = func_021D775C(0x51);
    func_021D7540(12526);
    return r;
}











/*
 *   no witness outside this caller (7374-r2.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: bind the category call result before initialising k to prevent
 *   its constant assignment moving before the call.
 */
u16 func_021C7374(Server *p, u8 *a, u8 *b, const u8 *c, int flag)
{
    int k;
    u16 value;
    u8 index;
    int mode = func_0201C1E8(*(u16 *)c);
    k = 10;
    if (mode != 2) k = 8;
    func_021D74F8(12542);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75A8(0x3b, 0x1f);
    func_021D75A8(0x51, 0);
    func_021D70F0(p, 0x39);
    index = func_021D775C(0x3b);
    if (index != 0x1f) a = (u8 *)func_021B9934(p->f8, index);
    if (func_021D775C(0x51)) value = func_021D58A8(a, k);
    else if (flag) value = func_021D5AD8(a, k);
    else value = func_021D59B4(a, k);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, *(u32 *)(c + 8));
    func_021D75A8(0x33, value);
    func_021D7674(0x35, 1 << 12, 410, 1 << 17);
    func_021D70F0(p, 0x3b);
    value = func_021D775C(0x33);
    value = func_021D7B10(value, func_021D775C(0x35));
    func_021D7540(12579);
    return value;
}











/*
 *   no witness outside this caller (7474-r1.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 */
u16 func_021C7474(Server *p, u8 *a, u8 *b, const u8 *c, u32 flag)
{
    int k;
    u32 field;
    u16 value;
    u8 other;
    int scale;
    int mode = func_0201C1E8(*(u16 *)c);
    k = 11;
    if (mode != 2) k = 9;
    field = *(u32 *)(c + 8);
    func_021D74F8(12595);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x3c, k);
    func_021D75A8(0x3d, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x3a);
    if (func_021D775C(0x3d) & 1) {
        if (k == 9) k = 11;
        else k = 9;
        if (k == 9) field = 1;
        else field = 2;
    }
    other = func_021D775C(0x51);
    func_021D7540(12610);
    if (other) value = func_021D58A8(b, k);
    else if (flag) value = func_021D5AD8(b, k);
    else value = func_021D59B4(b, k);
    if (func_021C2AB0(p) == 4 && func_021D5814(b, 5) && k == 11)
        value = func_021D7B10(value, 6 << 10);
    func_021D74F8(12631);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x1a, field);
    func_021D75A8(0x34, value);
    func_021D7674(0x35, 4 << 10, 410, 4 << 15);
    func_021D70F0(p, 0x3c);
    value = func_021D775C(0x34);
    scale = func_021D775C(0x35);
    func_021D7540(12642);
    return func_021D7B10(value, scale);
}











int func_021C75EC(Server *p, u8 *a, int k)
{
    int f = func_021D5814(a, k);
    u32 v = 0x1000;
    int x;
    int r;

    func_021D74F8(12664);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x51, f);
    func_021D70F0(p, 0x40);
    x = func_021D775C(0x51);
    if (x != 0)
        v = 0x1800;
    func_021D75EC(0x44, x);
    func_021D75A8(0x35, v);
    func_021D70F0(p, 0x41);
    r = func_021D775C(0x35);
    func_021D7540(12681);
    return r;
}











int func_021C7664(Server *p, u32 x, u8 *a)
{
    int c41;
    int c45;
    int c26;
    int s;

    s = func_0201BD28(x, 10);
    func_021D74F8(12701);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x25, s);
    func_021D7630(0x45, 0);
    func_021D7630(0x41, 0);
    func_021D75A8(0x26, 0);
    func_021D70F0(p, 0x6c);
    c41 = func_021D775C(0x41);
    c45 = func_021D775C(0x45);
    c26 = func_021D775C(0x26);
    func_021D7540(12712);
    if (c41 != 0 && s != 0)
        return 0;
    if (s == 0)
        s = s + c26;
    if (c45 != 0)
        s = s << 1;
    return s;
}











int func_021C76F4(Server *p, u8 *a, u32 k)
{
    int res;
    int c26;
    int c41;

    func_021D74F8(12745);
    func_021D75EC(4, func_021D5440(a));
    func_021D75A8(0x26, k);
    func_021D7630(0x41, 0);
    res = 0;
    func_021D70F0(p, 0x6d);
    c26 = func_021D775C(0x26);
    c41 = func_021D775C(0x41);
    func_021D7540(12753);
    if (c41 != 0)
        return 0;
    if (c26 != 0) {
        if (func_021C82B8(p, res) != 0)
            return 1;
        if (func_021D78AC(100) < (u8)c26)
            res = 1;
        return res;
    }
    return res;
}










void func_021C7780(Server *p, u8 *a)
{
    int line = 12778;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D70F0(p, 110);
    func_021D7540(line + 3);
}











int func_021C77B0(Server *p, u8 *a, u32 b, u32 c, u32 d, u32 e)
{
    int r;
    int res;

    func_021D74F8(12801);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, c);
    func_021D75EC(0x1f, b);
    func_021D75EC(0x20, d);
    func_021D75EC(0x19, e);
    res = 0;
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x5b);
    r = func_021D775C(0x41);
    func_021D7540(12810);
    if (r == 0)
        res = 1;
    return res;
}










void func_021C7820(Server *p, u8 *a, u32 k)
{
    int line = 12826;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(25, k);
    func_021D70F0(p, 92);
    func_021D7540(line + 4);
}











void func_021C785C(Server *p, u32 a, u8 *b, u32 c, u32 d)
{
    func_021D74F8(12846);
    func_021D75EC(3, a);
    func_021D75EC(2, func_021D5440(b));
    func_021D75EC(0x1f, c);
    func_021D75EC(0x20, d);
    func_021D70F0(p, 0x5d);
    func_021D7540(12852);
}











void func_021C78A8(Server *p, u8 *a, u32 b, u32 c, u32 d)
{
    func_021D74F8(12868);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, b);
    func_021D75EC(0x1f, c);
    func_021D75EC(0x20, d);
    func_021D70F0(p, 0x5e);
    func_021D7540(12874);
}











u16 func_021C78F4(Server *p, u8 *a, u8 *b, u32 s)
{
    int k;
    u32 y;
    u16 r;

    if (b != 0)
        k = func_021D5440(b);
    else
        k = 0x1f;
    func_021D74F8(12894);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, (u8)k);
    func_021D7674(0x35, 0x1000, 410, 0x20000);
    func_021D75A8(0x20, s);
    func_021D70F0(p, 0x8c);
    s = (u16)func_021D775C(0x20);
    y = func_021D775C(0x35);
    if (s != 0)
        s = (u16)func_021D7B2C(s, y);
    func_021D76BC(0x20, s);
    func_021D70F0(p, 0x8d);
    r = func_021D775C(0x20);
    func_021D7540(12911);
    return r;
}











void func_021C7998(Server *p, u32 x)
{
    func_021D74F8(12930);
    func_021D75EC(0x39, x);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x7d);
    if (func_021D775C(0x41) == 0)
        func_021D70F0(p, 0x7e);
    func_021D7540(12938);
}











u32 func_021C79E0(Server *p, u32 x, u8 *a)
{
    u32 s = func_0201BD28(x, 0x1a);
    int c;
    u32 m;
    u32 r;

    func_021D74F8(12956);
    func_021D75EC(2, func_021D5440(a));
    func_021D75A8(0x35, 0);
    func_021D70F0(p, 0x8f);
    c = func_021D775C(0x35);
    func_021D7540(12961);
    m = func_021D59B4(a, 0xe);
    if (c != 0)
        r = func_021D7B10(m, c);
    else
        r = func_021D7B3C(m, s);
    if (r == 0)
        return 1;
    if (r > m)
        r = m;
    return r;
}











int func_021C7A54(Server *p, u8 *a, u32 c)
{
    int r;
    func_021D74F8(12996);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x2d, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x9a);
    r = func_021D775C(0x41);
    func_021D7540(13002);
    return r;
}










void func_021C7AA0(Server *p, u8 *a)
{
    int line = 13017;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 155);
    func_021D7540(line + 3);
}










void func_021C7AD0(Server *p, u8 *a, u32 k)
{
    int line = 13033;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(45, k);
    func_021D70F0(p, 156);
    func_021D7540(line + 4);
}










void func_021C7B0C(Server *p, u8 *a)
{
    int line = 13050;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 157);
    func_021D7540(line + 3);
}











void func_021C7B3C(Server *p, u32 a, u16 b, u16 c)
{
    func_021D74F8(13068);
    func_021D75EC(2, a);
    func_021D75EC(0xf, b);
    func_021D75EC(0x10, c);
    func_021D70F0(p, 0x89);
    func_021D7540(13073);
}










void func_021C7B7C(Server *p, unsigned int i) { func_021D74F8(13085); func_021D75EC(2,i); func_021D70F0(p,138); func_021D7540(13088); }











void func_021C7BA8(Server *p, u8 a, u32 b, u32 c, u32 *out)
{
    func_021D74F8(13102);
    func_021D75EC(2, a);
    func_021D75EC(0x52, c);
    func_021D75EC(0x53, b);
    func_021D75A8(0x1e, *out);
    func_021D70F0(p, 0x9f);
    *out = func_021D775C(0x1e);
    func_021D7540(13109);
}










void func_021C7BF8(Server *p) { func_021D74F8(13123); func_021D70F0(p, 121); func_021D7540(13125); }











void func_021C7C18(void *p)
{
    func_02082BCC(p, 0, (u32)0xc);
}











void func_021C7C24(u16 *p, int unused, u8 *b, u8 *c, int e)
{
    u8 x = func_021D5440(b);
    u8 y = func_021D5440(c);
    int mx = func_021B8DDC(x);
    int my = func_021B8DDC(y);
    u8 same = (func_021B9A24(x, y) == 0);
    u16 *q = 0;
    if (mx == 0) {
        if (same) {
            if (e == 0) {
                q = p;
            } else if (e > 3) {
                q = p + 1;
            } else if (e < 3) {
                q = p + 2;
            }
        }
    } else if (my == 0) {
        if (same) {
            if (e == 0) {
                q = p + 3;
            } else if (e > 3) {
                q = p + 4;
            } else if (e < 3) {
                q = p + 5;
            }
        }
    }
    if (q != 0) {
        if (*q < 9999) {
            *q += 1;
        }
    }
}











/*
 * ldrh at #0x1f7c (pool constant)
 */
u16 func_021C7CBC(u8 *p)
{
    return ((struct Obj18319 *)p)->f1F7C;
}











/*
 * ldrh at #0x1f7e (pool constant)
 */
u16 func_021C7CC8(u8 *p)
{
    return ((struct Obj18320 *)p)->f1F7E;
}










/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x7e; lsls r1, r1, #6; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021C7CD4(struct Q6 *p) { return p->v; }











/*
 * ldrh at #0x1f82 (pool constant)
 */
u16 func_021C7CDC(u8 *p)
{
    return ((struct Obj18322 *)p)->f1F82;
}











u16 func_021C7CE8(u8 *p)
{
    return ((struct Obj18323 *)p)->f1F86;
}










/*
 * Forwarding tail call: p[2] and the caller's i go to func_021B9934, whose
 * listing reads both (lsls r1, r1, #2), and its result is returned.
 */
void *func_021C7CF4(int *p, int i)
{
    return func_021B9934((char *)p[2], i);
}









int func_021C7D00(u8 *p, int b) { int i = func_0689D5C8(p + 0x1ab8, b); if (!func_021B86A0(*(unsigned int ** *)&((struct Obj00003 *)p)->f4, i)) i = 6; return i; }
















/*
 * witness: owned verified ov095 leaf 0x0689D5F4 resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5F4 + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D34(char *p, int i) { return func_0689D5F4((u8 *)(p + 0x1ab8), i); }
















/*
 * witness: owned verified ov095 leaf 0x0689D5FC resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5FC + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 */
int func_021C7D44(char *p, u8 i) { return func_0689D5FC((u8 *)(p + 0x1ab8), i); }

















u8 func_021C7D54(u8 *p, u8 *k, u8 *out)
{
    u32 it;
    u8 *x;
    u8 n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (func_021B9A24((u32)k, func_021D5440(x)) == 0) {
            out[n++] = func_021D5440(x);
        }
    }
    return n;
}

















int func_021C7DAC(Server *p, int a, int b, u16 c)
{
    int buf[5];
    int r;
    u8 *x = func_021B9934(p->f8, a);
    u8 *y = func_021B9934(p->f8, b);
    p->f774 += 1;
    if (func_021D6C24((struct R4 *)y)) {
        y = func_021B937C(p->f4, p->f8, y);
    }
    func_021C64B4(p, c, x, (struct Out64B4 *)buf);
    r = func_021C6E3C(p, x, y, (u8 *)buf, 0);
    p->f774 -= 1;
    return r;
}

















u16 func_021C7E14(Server *p, u8 a, u8 b, u16 c, int e0, int e1)
{
    int buf[5];
    u16 o;
    u8 *x;
    u8 *y;
    int z;
    if (c != 0 && func_0201C314((void *)c) != 0) {
        x = func_021B9934(p->f8, a);
        y = func_021B9934(p->f8, b);
        p->f774 += 1;
        if (func_021D6C24((struct R4 *)y)) {
            y = func_021B937C(p->f4, p->f8, y);
        }
        if (e0) {
            z = func_021C7DAC(p, a, b, c);
        } else {
            z = 3;
        }
        func_021C64B4(p, c, x, (struct Out64B4 *)buf);
        func_021C1E74(p, x, y, (u8 *)buf, z, 0x1000, 0, e1 == 0, &o);
        p->f774 -= 1;
        return o;
    }
    return 0;
}

















/* 021C7EC4  nonzero test of the pooled offset 0x774 */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021C7ED4; ldr r0, [r0, r1]; cmp r0, #0; beq loc_021C7ED0; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C7EC4(u8 *p)
{
    return (((struct Obj18325 *)p)->f774 != 0);
}
















int func_021C7ED8(u8 *p, int i) { return func_021B997C(*(u8 * *)&((struct Obj21110 *)p)->f4, func_021B8DDC(i)); }
















int func_021C7EEC(u8 *p, int i) { return func_021BB85C(*(u8 * *)&((struct Obj21111 *)p)->f0, func_021B8DDC(i))[9]; }
















int func_021C7F04(u8 *p, int i) { if (func_021B8588(((struct Obj00003 *)p)->f4) != 3) return func_021C7EEC(p, i); return 3; }
















int func_021C7F24(u8 *p, int i) { char *q = func_021C7FCC(p, i); if (func_021B9BC4((u8 *)q, func_021C7F04(p, i))) return 1; return 0; }















int func_021C7F4C(struct Flag *p) { if (p->set) return 0; p->set = 1; return 1; }
















/*
 * Named by the parked ov093 file func_021D85F4.c.  Builds a candidate list in
 * a local buffer and copies the accepted entries to `out`.  EXACT*: the
 * completed extent runs into an unlabelled follower.  Three levers: `n` must
 * be volatile (it is spilled/reloaded around the loop calls), the boolean is
 * materialised through a `?:` rather than a bare `&&`, and the `u8` locals
 * are declared `j` before `i` with both initialised in the for-clause.
 */
u8 func_021C7F68(Server *p, int b, u8 *out)
{
    u8 buf[8];
    volatile u32 n = (u32)func_021B8778((struct Unk021B8CB0 **)p->f4, b, buf);
    u8 j;
    u8 i;

    for (i = 0, j = 0; i < n; i++) {
        u8 *x = func_021B98A4((char *const *)p->f8, buf[i]);
        int ok = (x != 0) ? (func_021D5B68(x) == 0) : 0;

        if (ok)
            out[j++] = func_021D5440(x);
    }
    return j;
}















char *func_021C7FCC(u8 *p, int i) { return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8, func_021B8DDC(i)); }















/*
 * extent: two bytes alignment padding follow.
 * ABI: original forwards full-word B8DDC/B9010 results without narrowing;
 * widen B9010 and B8B9C input declarations relative to narrow legacy sources.
 */
char *func_021C7FE0(u8 *p, int v) { u8 k; k=func_021B9010(*(u8 * *)&((struct Obj00003 *)p)->f4, func_021B8DDC(v)); if(func_021B8B9C(*(u8 * *)&((struct Obj00003 *)p)->f4,k)) return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8,k); return 0; }















int func_021C8010(Server *p, unsigned int v) { return func_021B8D8C(p->f4, p->f8, v); }















/*
 * extent: two bytes alignment padding follow.
 */
u8 func_021C8020(u8 *p, u8 v) { return func_021D5440((u8 *)func_021B98AC(*(char *const * *)&((struct Obj00003 *)p)->f8, v)); }















int func_021C8030(u8 *p, int v, u16 k) { return func_021D80BC(((struct Obj00003 *)p)->f4, *(int *)&((struct Obj00003 *)p)->f8, (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,v), k); }
















/*
 * Levers: the record array read as p->e[i] of the twins' S (func_021BCA08,
 * func_021BCAAC), which keeps i*16 live and recomputes p+i*16 for the second
 * load; the second word as a union of u32 and a 4-bit bitfield read in place
 * (a union local takes a stack slot); key as a u8 parameter, which puts its
 * spill ahead of the count load (int/u32 key leave it after).
 */
int func_021C804C(S_td *p, u8 key, u32 *out)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (key == func_021D5440(p->e[i].a)) {
            if (p->e[i].b.w.lo != 6) {
                *out = p->e[i].b.u;
                return 1;
            }
        }
    }
    return 0;
}
















int func_021C80AC(u8 *p, int key)
{
    u32 i;
    u32 total;
    u32 flagged;
    flagged = 0;
    total = 0;
    for (i = 0; i < p[0x782]; i++) {
        u8 *e = p + i * 16;
        if (key != func_021D5440(*(u8 * *)&((struct Obj13340 *)e)->f7E0)) {
            total++;
            if (e[0x7ed] != 0) {
                flagged++;
            }
        }
    }
    return total == flagged;
}
















/*
 * ldrh at #0x1f74 (pool constant)
 */
u16 func_021C8114(u8 *p)
{
    return ((struct Obj18333 *)p)->f1F74;
}
















/*
 * pointer add #0x1fec
 */
u8 *func_021C8120(u8 *p, int b)
{
    return p + 0x1fec;
}
















/* 021C812C  adds r0,#0x1c */
u8 *func_021C812C(u8 *p) { return p + 0x1c; }
















/* 021C8130  movs r1,#0x3e; lsls r1,#4; adds r0,r0,r1 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x3e; lsls r1, r1, #4; adds r0, r0, r1; bx lr.
 */
u8 *func_021C8130(u8 *p) { return p + 0x3e0; }















/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0, #0x10]; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 func_021C8138(struct Q7 *p) { return (u16)p->v; }















unsigned char func_021C8140(char *p, int i)
{
    return *(unsigned char *)(p + i + 0x7d9);
}














/*
 * ABI: ov095 D588 forwards the same table pointer and key to D5C8;
 * original keeps r1 live and has no narrowing, so retain a full-word key.
 */
int func_021C814C(u8 *p, u8 v) { return func_0689D588(p+0x1ab8,v); }















/*
 * Two tail thunks forwarding p->field4 to distinct callees.
 */
int func_021C815C(int *p)
{
    return func_021B8588((void **)(((struct Obj26329 *)p)->f4));
}















void func_021C8168(int *p)
{
    func_021B86B8((void ***)(((struct Obj26330 *)p)->f4));
}















int func_021C8174(int *p)
{
    return ((struct Obj18336 *)((char *)func_021B8714((char **)(((struct Obj18335 *)p)->f4))))->f4;
}















int func_021C8180(int *p)
{
    return func_021B8670((unsigned int **)(((struct Obj18337 *)p)->f4));
}














int func_021C818C(u8 *p, int v) { unsigned int species; u16 i; species=func_021D5444((struct QF *)func_021B9934(*(char * *)&((struct Obj13341 *)p)->f8,v)); for(i=0;i<7;i++) { if(func_0201B718(((struct Obj13341 *)p)->f4A4,species,0,i)) return 1; } return 0; }















u16 func_021C81C8(Server *p, u8 *x, int flag)
{
    return func_021BC948(p, x, flag);
}















u16 func_021C81D0(Server *p, u8 *a, u32 y)
{
    u32 it;
    u8 *x;
    u16 n;
    u32 base = func_021C81C8(p, a, y);
    int k = func_021D5440(a);
    n = 0;
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        if (k != func_021D5440(x)) {
            if (func_021C81C8(p, x, y) > base) {
                n++;
            }
        }
    }
    return n;
}














/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
int func_021C8234(Server *p, int i) { return func_021C6F0C(p, func_021B9934(p->f8, i), 1); }













int func_021C824C(u8 *p, int v) { void *m; m=func_021B9934(*(char * *)&((struct Obj21115 *)p)->f8,v); if(func_021D59B4(m,17)==103) return 0; if(func_021D62C4(m,19)) return 0; if(func_021EF948(7)==0) return 1; return 0; }














/*
 * tail-call thunk to func_021C2AB0
 */
int func_021C8288(Server *p)
{
    return func_021C2AB0(p);
}













int func_021C8290(Server *p, int a, int b, void *item) { u8 *x; x=func_021B9934(p->f8,a); return func_021BFA00(p,x,func_021B9934(p->f8,b),item); }













int func_021C82B8(Server *p, int z)
{
    return func_021B911C(p->f4, z);
}













int func_021C82C4(int a, int b, int c)
{
    (void)a;
    return func_06898CF4(b, c);
}










/*
 * extent: two bytes alignment padding precede non-C veneer 021C82E4.
 */
int func_021C82D0(int unused, unsigned int v, int k) { return func_06898CE0(func_021B9AE0(v),k); }













/*
 * Tail-call stub: mov r0, r2; bx to the pool word 0x068982AD (a thumb
 * target in the 0x06xxxxxx window, not an image address).
 */
int func_021C82F4(int a, int b, int c)
{
    return func_068982AC(c);
}














u32 func_021C8300(int *p, u8 k)
{
    return func_021B9010((u8 *)p[1], k);
}













/*
 * lever: unsigned-char bitfield gives the byte load and 31-bit shift pair.
 */
unsigned int func_021C830C(u8 *p) { return ((struct Bits *)(p+0x78a))->a; }













/*
 * lever: add the byte index to the base before applying the constant offset.
 */
void func_021C831C(u8 *p, int v) { unsigned int n; n=p[0x788]; if(n<6) { p[0x788]=n+1; (p+n)[0x78b]=v; } }













/*
 * extent: Two bytes of alignment padding follow the 14-byte function.
 */
int func_021C8338(Server *p, int i)
{
    return func_021D5C30((struct UtilWork *)func_021B9934(p->f8, i));
}













/*
 * extent: Two bytes of alignment padding follow the 42-byte function.
 */
int func_021C8348(Server *p, int i)
{
    u8 n = func_021D69AC(func_021B9934(p->f8, i), 4);
    if (n != 0) {
        n--;
        if (n < 24) goto done;
    }
    n = 31;
done:
    if (n != 31) return 1;
    return 0;
}













int func_021C8374(Server *p, int i)
{
    if (func_021C8348(p, i)) return 1;
    if (func_021D62C4((struct Unk021D62A8 *)func_021B9934(p->f8, i), 33)) return 1;
    return 0;
}













u32 func_021C83A0(u8 *p, int i)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj21119 *)p)->f8, i);
    int b = func_021C2AF0(p, a);
    u32 r = func_021D7B10(func_021D67E8(a), b);
    if (r < 1) r = 1;
    return r;
}













/*
 * tail-call thunk to func_021C2E4C
 */
u32 func_021C83CC(Server *p)
{
    return func_021C2E4C(p);
}













/*
 * tail-call thunk to func_021BC2B0
 */
int func_021C83D4(Server *p)
{
    return func_021BC2B0(p);
}













void func_021C83DC(char *p, int x)
{
    *(char *)(((struct Obj21120 *)p)->f4A8 + 4) = x;
}












/*
 * evidence: Original loads r1 for func_021BB908 even though its body ignores it.
 */
int func_021C83E8(unsigned char *p, int i, int b)
{
    if ((unsigned int)func_021B86B8(*(void *** *)&((struct Obj13342 *)p)->f4) <= 1) {
        func_021BB908(*(int * *)&((struct Obj13342 *)p)->f0, i);
        return 1;
    }
    return 0;
}











void func_021C8408(u8 *p, int a)
{
    unsigned int t = (unsigned int)func_021B86B8(*(void *** *)&((struct Obj09974 *)p)->f4);
    int k = func_021B8DDC(a);
    if (t <= 1 && k == func_021B8FF4(*(u8 * *)&((struct Obj09974 *)p)->f4)) func_021BB914(*(int * *)&((struct Obj09974 *)p)->f0);
}











void func_021C8434(u8 *p, int a, int b)
{
    int c = func_0689D5C8(p + 0x1ab8, b);
    func_021BE52C(*(u8 * *)&((struct Obj21121 *)p)->f4B0, a, b, c);
}










/*
 * extent: Two bytes of alignment padding follow the 38-byte function.
 */
int func_021C846C(Server *p, int a, int b, int *out)
{
    u8 *x = func_021B9934(p->f8, a);
    u8 *y = func_021B9934(p->f8, b);
    return func_021BFEAC(p, x, y, out);
}











/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021C8494(Server *p, int i) { func_021BFF60(p, func_021B9934(p->f8, i), 1); }










int func_021C84AC(Server *p, u8 *a, u8 *out)
{
    int r;
    ((struct Flags_021C7D34 *)&p->f78a)->flag = 0;
    r = func_021C2128(p, a);
    *out = ((struct Flags_021C7D34 *)&p->f78a)->flag;
    return r;
}











/*
 * tail-call thunk to func_021BDBB8
 */
void func_021C84D0(Server *p, u8 *a)
{
    func_021BDBB8(p, a);
}











/*
 * tail-call thunk to func_021CC668
 */
int func_021C84D8(u8 *p)
{
    return func_021CC668(p);
}











/*
 * Was MATCH (pool word to the unlabelled 0x021C84F4 had no witness); the
 * matched func_021C84F4 now resolves it, verified EXACT.
 */
void func_021C84E0(Server *p, unsigned int v)
{
    func_021C84F4(p, v);
}











void func_021C84E8(Server *p)
{
    p->f785 = 0;
}










/*
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021C84F4..0x021C8534
 * (64 bytes, including a 2-byte pool-alignment nop and two pool words).
 * Searches the u8 set at p+0x791 for v; if absent and i < 0x18, appends v
 * and bumps the count at p+0x785.
 */
void func_021C84F4(Server *p, unsigned int v)
{
    unsigned int i;
    unsigned int n = p->f785;

    for (i = 0; i < n; i++) {
        if (v == p->set[i])
            return;
    }
    if (i < 0x18) {
        p->set[i] = v;
        p->f785 = p->f785 + 1;
    }
}











int func_021C8534(Server *p)
{
    u32 i;
    u8 buf[4];
    for (i = 0; i < p->f785; i++) {
        if (func_0689D558(p->w1ab8, func_021B8DDC(p->set[i]), buf)) {
            return 1;
        }
    }
    return 0;
}








void func_021C8588(Server *p)
{
    *(int *)&p->f1a64 = 0;
    func_021C85D4(p, 0, 1);
}








void func_021C859C(Server *p)
{
    if (p->f1a64 < 6) {
        ++p->f1a64;
        func_021C85D4(p, p->f1a64, 1);
    }
}








void func_021C85B8(Server *p)
{
    if (p->f1a64 != 0) {
        --p->f1a64;
        func_021C85D4(p, p->f1a64, 0);
    }
}









void func_021C85D4(Server *p, int index, int clear)
{
    u8 *q = p->w874 + index * 0x290;
    p->f850 = q;
    p->f854 = q + 0x48;
    p->f858 = q + 0x90;
    p->f85c = q + 0xd8;
    p->f860 = q + 0x120;
    p->f864 = q + 0x168;
    p->f868 = q + 0x1b0;
    p->f4a8 = q + 0x1f8;
    p->f1ab0 = q + 0x200;
    p->f1ab4 = q + 0x214;
    p->f4b4 = q + 0x228;
    p->f4ac = q + 0x22e;
    p->f4b0 = q + 0x241;
    p->f86c = q + 0x254;
    p->f870 = q + 0x270;
    p->f77f = q[0x28c];
    ((struct Flags_021C8588 *)&p->f78a)->a = q[0x28d];
    ((struct Flags_021C8588 *)&p->f78a)->b = q[0x28e];
    if (clear) {
        func_0689CB3C(q);
        func_0689CB3C(p->f854);
        func_0689CB3C(p->f858);
        func_0689CB3C(p->f85c);
        func_0689CB3C(p->f860);
        func_0689CB3C(p->f864);
        func_0689CB3C(p->f868);
        func_021BD1E0((struct Unk021BD1E0 * )p->f4a8);
        func_02082BCC(p->f1ab0, 0, 0x14);
        func_02082BCC(p->f1ab4, 0, 0x14);
        func_02082BCC(p->f4b4, 0, 6);
        func_02082BCC(p->f4ac, 0, 0x13);
        func_02082BCC(p->f4b0, 0, 0x13);
        func_02082BCC(p->f86c, 0, 0x1c);
        func_02082BCC(p->f870, 0, 0x1c);
        p->f77f = 6;
        ((struct Flags_021C8588 *)&p->f78a)->a = 0;
        ((struct Flags_021C8588 *)&p->f78a)->b = 0;
    }
}









void func_021C8810(u8 *p)
{
    func_02082BCC(p, 0, 0x24);
    ((struct Packed021C8810 *)(p + 2))->low = 0;
}










/* 021C8828  u8 of the low halfword, != 0 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrh r0, [r0, #2]; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; beq loc_021C8834; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021C8828(u8 *p)
{
    return ((u8)((struct Obj18339 *)p)->f2 != 0);
}










/*
 * Named by the parked ov093 files (func_021DF0C4 / func_021DFABC /
 * func_021E7388).  Low byte of the +2 halfword <- (u8)a; +0 halfword <- b;
 * then bits 8..14 of the +2 halfword are cleared.  `(u8)(u16)a` and the
 * `(int)` cast before `~0x7F00` are both load-bearing: the first gives the
 * double narrowing, the second keeps the mask sign-extended (0xFFFF80FF) so
 * the pooled word matches.
 */
void func_021C8838(void *p, int a, int b)
{
    u16 *h = (u16 *)((u8 *)p + 2);
    u8 av = (u8)(u16)a;

    *h = (*h & ~0xff) | av;
    ((struct Obj21124 *)p)->f0 = (u16)b;
    *h = (u16)((int)*h & ~0x7F00);
}










/*
 * Named by the parked ov093 files (func_021DF0C4 / func_021DFABC /
 * func_021E7388).  Appends `val` to the record at p: the count in bits 8..14
 * of the +2 halfword (max 7 entries) is incremented and `val` stored at
 * p + 4 + idx*4.  The 7-bit unsigned bitfield is what makes the count
 * unsigned (`bhs`, not `bge`) and produces the lsl/lsr extraction pair.
 */
void func_021C8860(struct S_p12 *p, u32 val)
{
    unsigned int idx = p->n;

    if (idx >= 8)
        return;
    p->n = idx + 1;
    p->arr[idx] = val;
}









/*
 * extent: two-byte alignment padding at 0x021C88A2.
 */
void func_021C888C(u8 *p, u32 v)
{
    if (((struct Packed021C888C *)(p + 2))->index < 8) {
        ((struct Obj21125 *)p)->f20 = v;
        ((struct Packed021C888C *)(p + 2))->active = 1;
    }
}










/*
 * word at +0x0C names 0x021CC9AC.  That address is real Thumb code in ov093
 * (a 176-byte unlabelled bitfield packer, disasm prints it as a `.word` run)
 * but no listing labels it and no branch or pool word anywhere outside this
 * range names it, so `label`, `literal`, `sole-ref/code` and `matched` all
 * refuse.  It can only be witnessed by matching it bottom-up.  Passing the
 * full (char*, int, int) arity through to the callee is what makes the two
 * loads schedule as the original (add before the target load).
 *
 * Named by five parked pending files (func_021D85F4 / func_021DF0C4 /
 * func_021DFABC / func_021E4A70 / func_021E7388).
 *
 * 2026-10-05 (D9 lane 02): unchanged. 0x021CC9AC is a 176-byte packer, not a tiny leaf, and ov093 below 0x021D4000 is pengy's, so no witness filed. Needs the integrator seed.
 * 2026-10-05 (D9r lane 14): callee 0x021CC9AC is now matched EXACT as
 * src/matched/ov/ov093_func_021CC9AC.c (user-approved). Re-verified MATCH: the
 * relocation still waits on that file's shard (integrator manifest), then this
 * should verify EXACT with no source change.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021CC9AC is a real 176-byte Thumb bitfield packer (bitfield insert into a table with 0x3b-entry byte lookup), not a veneer and not tiny; not filed in this lane. Needs bottom-up match or integrator seed.
 */
void *func_021C88A4(Server *p, int a, int b)
{
    return func_021CC9AC((struct Pack *)&p->lock, a, b);
}










/*
 * Named by the parked ov093 files (func_021D85F4 / func_021DF0C4 /
 * func_021DFABC / func_021E4A70 / func_021E7388).  EXACT*: both calls resolve
 * (func_021C88A4 by `label`, func_021C88C8 by `label`), the extent runs two
 * bytes long into the unlabelled follower.
 */
void func_021C88B4(Server *a, int k, int b)
{
    func_021C88C8(a, func_021C88A4(a, k, b));
}










/*
 * Unlabelled-record helper reached from the five ov093 packets that name it
 * (func_021DFABC / func_021E4A70 / func_021D85F4 / func_021E7388 /
 * func_021DF0C4).  Runs the battle-command dispatcher on (`a`, `b`), then
 * dispatches the same command through the record `a + 0x1D74`.
 */
void func_021C88C8(Server *a, void *b)
{
    func_021C8918(a, b);
    func_021CCA74((QueueA *)&a->lock, (QueueB *)b);
}










int func_021C88E4(Server *p)
{
    if (func_021CC96C((struct Q9 *)&p->lock) != 0) {
        if (func_021CC9A4(&p->lock) != 0) return 2;
        return 1;
    }
    return 0;
}










/*
 * tail-call thunk to func_021C88E4
 */
int func_021C8910(Server *p)
{
    return func_021C88E4(p);
}










void func_021C8918(Server *s, void *cmd)
{
    u16 arg = func_021CC960((struct S_p14 *)&s->lock);
    u8 r;

    if (func_021CC96C((struct Q9 *)&s->lock))
        r = func_021CC99C((struct Q10 *)&s->lock);
    else
        r = 1;

    if (((BtlCmd *)cmd)->ignoreIfBusy && r == 0)
        return;
    if (((BtlCmd *)cmd)->checkFainted && func_021D5B68(func_021B9940(s->f8, ((BtlCmd *)cmd)->client)))
        return;

    switch (((BtlCmd *)cmd)->id) {
    case 1:
        r = func_021C8C6C(s, cmd);
        break;
    case 2:
        r = func_021C8CBC(s, cmd);
        break;
    case 3:
        r = func_021C8D0C(s, cmd);
        break;
    case 0:
        r = func_021C9DE8(s, cmd);
        break;
    case 5:
        r = func_021C8D2C(s, (Ent_021C8D2C *)cmd, arg);
        break;
    case 6:
        r = func_021C8DE4(s, cmd, arg);
        break;
    case 7:
        r = func_021C8E58(s, cmd);
        break;
    case 8:
        r = func_021C8F24(s, cmd);
        break;
    case 9:
        r = func_021C8FA4(s, cmd, arg);
        break;
    case 10:
        r = func_021C9010(s, cmd, arg);
        break;
    case 11:
        r = func_021C9068(s, cmd, arg);
        break;
    case 12:
        r = func_021C9178(s, cmd);
        break;
    case 14:
        r = func_021C9250(s, cmd, arg);
        break;
    case 15:
        r = func_021C9394(s, cmd);
        break;
    case 18:
        r = func_021C9448(s, cmd);
        break;
    case 16:
        r = func_021C947C(s, cmd);
        break;
    case 17:
        r = func_021C94C8(s, cmd);
        break;
    case 19:
        r = func_021C95D0(s, cmd);
        break;
    case 20:
        r = func_021C962C(s, cmd);
        break;
    case 4:
        r = func_021C96D4(s, cmd);
        break;
    case 21:
        r = func_021C9728(s, cmd);
        break;
    case 22:
        r = func_021C9750(s, cmd);
        break;
    case 23:
        r = func_021C9778(s, cmd);
        break;
    case 24:
        r = func_021C97A4(s, cmd);
        break;
    case 25:
        r = func_021C97D0(s, cmd);
        break;
    case 26:
        r = func_021C9828(s, cmd);
        break;
    case 27:
        r = func_021C9898(s, cmd);
        break;
    case 29:
        r = func_021C98E4(s, cmd);
        break;
    case 28:
        r = func_021C98C4(s, cmd);
        break;
    case 30:
        r = func_021C9A24(s, cmd);
        break;
    case 31:
        r = func_021C9A60(s, cmd);
        break;
    case 32:
        r = func_021C9BB8(s, cmd);
        break;
    case 33:
        r = func_021C9DCC(s, cmd);
        break;
    case 34:
        r = func_021C9E3C(s, cmd);
        break;
    case 35:
        r = func_021C9ECC(s, cmd);
        break;
    case 36:
        r = func_021C9CC0(s, cmd);
        break;
    case 37:
        r = func_021C9F0C(s, cmd);
        break;
    case 38:
        r = func_021C9F4C(s, cmd);
        break;
    case 39:
        r = func_021C9F6C(s, cmd);
        break;
    case 40:
        r = func_021CA128(s, cmd);
        break;
    case 41:
        r = func_021CA158(s, cmd);
        break;
    case 42:
        r = func_021CA1D0(s, cmd);
        break;
    case 43:
        r = func_021CA248(s, cmd);
        break;
    case 44:
        r = func_021CA270(s, cmd);
        break;
    case 45:
        r = func_021CA2E8(s, cmd);
        break;
    case 46:
        r = func_021CA318(s, cmd);
        break;
    case 47:
        r = func_021CA370(s, cmd);
        break;
    case 48:
        r = func_021CA394(s, cmd);
        break;
    case 49:
        r = func_021CA3AC(s, cmd);
        break;
    case 50:
        r = func_021CA3D0(s, cmd);
        break;
    case 51:
        r = func_021CA47C(s, cmd);
        break;
    case 52:
        r = func_021CA570(s, cmd);
        break;
    case 53:
        r = func_021CA5CC(s, cmd);
        break;
    case 54:
        r = func_021CA6C4(s, cmd);
        break;
    case 55:
        r = func_021CA6FC(s, cmd);
        break;
    case 56:
        r = func_021CA738(s, cmd);
        break;
    case 57:
        r = func_021CA748(s, cmd);
        break;
    case 58:
        r = func_021CA7C4(s, cmd);
        break;
    case 59:
        r = func_021CA7D4(s, cmd);
        break;
    }
    func_021CC974((Word_021CC768 *)&s->lock, r);
}








u8 func_021C8C6C(Server *a, BtlCmd *e)
{
    if (func_0689D588(a->w1ab8, e->client)) {
        func_021C60D4(a, func_021B9934(a->f8, (u8)e->client));
        return 1;
    }
    return 0;
}









u8 func_021C8CBC(Server *a, Ent_021C8CBC *e)
{
    if (func_0689D588(a->w1ab8, e->idx)) {
        func_021C5A1C(a, func_021B9934((char *)a->f8, (u8)e->idx));
        return 1;
    }
    return 0;
}










/*
 * note: caller narrows index to u8 before func_021B9934.
 */
u8 func_021C8D0C(Server *p, Ent_021C8D0C *e)
{
    func_021C5A34(p, func_021B9934((char *)p->f8, (u8)e->idx));
    return 1;
}











u8 func_021C8D2C(Server *p, const Ent_021C8D2C *e, int c)
{
    u8 r = 0;
    u8 *a = func_021B9934((char *)p->f8, (u8)e->idx);
    u8 *b = func_021B9934((char *)p->f8, e->b6);

    if (func_021C3370(p, b) == 0) {
        if (e->fl)
            func_021C5A1C(p, a);
        if (e->b7 == 0) {
            r = !func_021C3394(p, b, 1);
        } else {
            r = 1;
        }
        if (r) {
            func_021C33E8(p, b, e->h4);
            if ((u8)e->ha)
                func_021C99A0(p, (void *)&e->h8);
            else if (c)
                func_021CD64C(p->fC, 0x5b, 0x38c, e->b6, c, 0xffff0000);
        }
        if (e->fl)
            func_021C5A34(p, a);
    }
    return r;
}










u8 func_021C8DE4(Server *p, const Ent_021C8DE4 *e, int unused)
{
    int s = 0;
    int t;

    if (e->b7 != 0x1f)
        s = (int)func_021B9934((char *)p->f8, e->b7);
    if (func_0689D588(p->w1ab8, e->b6)) {
        t = (int)func_021B9934((char *)p->f8, e->b6);
        if (func_021D5B68((void *)t) == 0 && func_021C1E14(p, (u8 *)t, s, e->h4)) {
            if ((u8)e->ha)
                func_021C99A0(p, (void *)&e->h8);
            return 1;
        }
    }
    return 0;
}










u8 func_021C8E58(Server *p, const Ent_021C8E58 *e)
{
    int a;
    u8 *b;
    u32 i;

    if (func_0689D588(p->w1ab8, e->b6)) {
        a = (int)func_021B9934((char *)p->f8, e->b6);
        b = 0;
        i = e->idx;
        if (i != 0x1f)
            b = func_021B9934((char *)p->f8, (u8)i);
        if (func_021D5B68((void *)a) == 0) {
            if (!e->f7a || func_021D5C30((struct UtilWork *)a) == 0) {
                if (func_021C20BC(p, (u8 *)a, e->h4)) {
                    if (e->fl)
                        func_021C5A1C(p, b);
                    if (e->f7b)
                        func_021C70E4(p, e->h8, e->ba, e->bb, 0, 0);
                    func_021C20D0(p, (u8 *)a, e->h4, (void *)((u8 *)e + 0xc));
                    if (e->fl)
                        func_021C5A34(p, b);
                    return 1;
                }
            }
        }
    }
    return 0;
}










u8 func_021C8F24(Server *p, const Ent_021C8F24 *e)
{
    u8 r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        if (func_0689D588(p->w1ab8, e->ids[i])) {
            a = func_021B9934(p->f8, e->ids[i]);
            if (func_021D5B68(a) == 0) {
                func_021C5B74(p, a, e->v[i], !e->b5);
                if (e->b6 == 0)
                    func_021C195C(p, a, 1);
                r = 1;
            }
        }
    }
    return r;
}











u8 func_021C8FA4(Server *p, const Ent_021C8FA4 *e, int unused)
{
    u8 *a;
    int r;

    func_021B9934((char *)p->f8, (u8)e->idx);
    a = func_021B9934((char *)p->f8, e->b5);
    if (func_021D5B7C(a) || e->f7b) {
        r = !e->f7a;
        if (func_021D55D8(a, e->b6, r) == 0) {
            func_021C6080(p, a, e->b6, e->b4, r);
            func_021C99A0(p, (void *)((u8 *)e + 8));
            return 1;
        }
    }
    return 0;
}











u8 func_021C9010(Server *p, const Ent_021C9010 *e, int unused)
{
    int a;

    a = (int)func_021B9934((char *)p->f8, e->b5);
    if (func_021D5B68((void *)a) == 0 || e->f7b) {
        if (func_021C0898(p, (u8 *)a, e->b6, e->b4)) {
            func_021C99A0(p, (void *)((u8 *)e + 8));
            if (func_021C7194(p, (u8 *)a, e->b6))
                func_021C2128(p, (u8 *)a);
        }
        return 1;
    }
    return 0;
}










/*
 * checks: 1 own B9934/C5620/C56A8/C99A0 bodies rederived, original
 *   B9934 narrowing and five-argument 9168 veneer setup preserved;
 *   2 matched C8E58/C8FA4 bodies refreshed, no exact twin;
 *   3 full-word unsigned-long veneer argument compiles unchanged at256/18;
 *   4 long-index, loop-invariant and typed-address idioms read;
 *   5 full idiom directory relisted, C8FA4 refreshed, Slot frame agrees.
 * residual: 256/256 bytes, 8 concrete bytes; 13/13 relocations resolve.
 *   Only the pool load + adds r7 (p+0x1ae4) versus movs #1/str result order at +70..76 differs.
 * retry: wave76 R8,4 compiles. Long arg and long i each retain18;
 *   integer-spelled msg address hoists both addresses and regresses to73;
 *   three nonshrinking changes stopped iteration; check 3 wide veneer
 *   argument retains18. Pointer msg spelling restored in best C.
 * permuter: prior once300 --types consumed; expand(work x3) improved64
 *   to18 and match.py agreed. No search repeated. Prior inner work local,
 *   enum arg and redundant work assignment gave65/18/64 respectively.
 * proof: original passes the full fourth argument word; no narrowing,
 *   volatile, invented defaults or altered control flow accepted.
 * recoup 2026-10-05 (lane X6, no pending file existed; started from the
 *   docs/notes draft, 18 B off, 12 compiles): callee return types checked,
 *   all match the draft (B9934 u8*, 5A1C/5A34/5620 void, 56A8 int, 99A0 int,
 *   8810 void, 195C void); 9168 is a veneer, no definition. Tried:
 *   (1) arg as u16/u8 with u16 callee param: store of r2 moves to the top of
 *   the entry (original has it after the first lsls), 18 B, other residue same;
 *   arg as int: same as unsigned long, 18 B. (2) work address in a local w
 *   (struct Msg *): compiler hoists msg and w to the for-body top, 64 B.
 *   (3) result as int: 32 B (extra uxtb at return). (4) result = 1 before msg:
 *   22 B. (5) const Ent_021C9068 *e, pragma scheduling off, opt_lifetimes off: 18 B
 *   unchanged. opt_propagation off: 198 B. (6) callee B9934 declared (char *,
 *   int): drops the u8 narrowing, 225 B. (7) idx in a u8 local: 18 B.
 *   Residue: entry spill str r2,[sp,#8] sits after the first lsls in the
 *   original, after the call args in ours; and the pool load + adds r7 for
 *   p+0x1ae4 comes before movs #1/str result in the original, after it in ours.
 *   Idioms read: a-later-parameters-width-reorders-the-entry-spill-stores,
 *   a-copy-and-a-pointer-step-hoisted-above-a-call-are-written-before-it,
 *   a-local-declared-at-its-first-use-schedules-its-store-there,
 *   a-spilled-pointer-plus-constant-argument-is-the-sum-stored-in-the-local,
 *   a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies.
 * final push 2026-10-05 G5L5 (37 compiles, 3 rounds, 18 B -> 8 B): the entry spill residue is closed
 *   by the shape of matched func_021C9250 (same prologue): p as u8 * with raw offsets
 *   (*(char **)(p + 8), p + 0x1ae4), const Ent_021C9068 *e, u16 arg with the callee still taking unsigned long.
 *   Any one of the three alone keeps 18 B (struct p with const e and u16 arg: 18 B; u16 arg without const e: 18 B).
 *   Remaining: the original computes the work address (ldr pool; adds r7) before movs #1/str result;
 *   ours emits the loop-invariant store first. Tried with no change (8 B): result = 1 at the top, the end,
 *   after func_021C5620 or inside the do body (the store is hoisted to the same place); a named work
 *   local (u8 *w = p; w += 0x1ae4 before result) is propagated, a typed Msg * local hoists the msg and
 *   work setup to the top of the for body (54 to 64 B); &p[0x1ae4] and a struct view; callee 9168 with const
 *   Msg *; pragmas scheduling, opt_lifetimes, opt_common_subs off (8 B each); opt_propagation off (188 B);
 *   while (k) form instead of if + do-while (146 to 154 B); int result with return (u8) (22 B).
 *   Matched-assembly search for ldr pool; adds rN,r5,r0; movs; str over ov093.s: only this function.
 *   Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no change),
 *   opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores (188 B).
 * pass 2 2026-10-06 P2L18: EXACT (256/256). The work buffer passed to func_0689C464 is a named
 *   local w assigned at the top of the do body and used only in that call; the two calls after it
 *   spell p + 0x1ae4 again (they CSE onto w), and result = 1 is written after the if/else in the
 *   body. Both named assignments are hoisted into the inner preheader in source order (w before
 *   result), which gives the original pool load + adds r7 before movs #1/str. A w used in all three
 *   calls is hoisted out of the outer for loop (54 B); the expression form puts the hoisted
 *   address after result (8 B).
 */
u8 func_021C9068(Server *p, const Ent_021C9068 *e, u16 arg)
{
    const struct Msg *msg;
    u8 *first;
    u8 result;
    unsigned long i;
    u8 *a;
    int value;
    int k;
    union Slot slot;
    struct Msg *w;
    first = (u8 *)func_021B9934((char *)p->f8, (u8)e->idx);
    result = 0;
    if (e->fl) func_021C5A1C(p, first);
    for (i = 0; i < e->count; i++) {
        a = (u8 *)func_021B9934((char *)p->f8, (u8)e->targets[i]);
        if (func_021D5B7C(a)) {
          value = e->value;
          k = func_021C56A8(a, &value);
          if (k) {
          msg = &e->msg;
          do {
            w = (struct Msg *)p->w1ae4;
            func_021C5620(p, a, k, &slot);
            if (!e->flag) {
                if (func_0689C464(k, slot, a, arg, w)) {
                    func_021C99A0(p, (struct Msg *)p->w1ae4);
                    func_021C8810((u8 *)p->w1ae4);
                }
            } else {
                func_021C99A0(p, msg);
            }
            result = 1;
            if (k == 0x13) func_021C195C(p, a, 0);
            k = func_021C56A8(a, &value);
          } while (k);
          }
        }
    }
    if (e->fl) func_021C5A34(p, first);
    return result;
}









u8 func_021C9178(Server *p, const Ent_021C9178 *e)
{
    u8 *a;
    u8 f;
    u8 *b;
    if (e->index != 31) a = func_021B9934(p->f8, (u8)e->index);
    else a = 0;
    f = (int)func_021C8828((u8 *)e->msg) == 0 && e->b == 0;
    if (func_0689D588(p->w1ab8, e->id)) {
        b = func_021B9934(p->f8, (u8)e->id);
        if (!func_021D5B68(b)) {
            if (!func_021C27A0(p, b, a, e->kind, e->value, e->d, e->a)) {
                if (e->flag) func_021C5A1C(p, a);
                func_021C2910(p, b, a, e->kind, e->value, f, e->c, e->msg);
                if (e->flag) func_021C5A34(p, a);
                return 1;
            }
        }
    }
    return 0;
}









u8 func_021C9250(Server *p, const Ent_021C9250 *e, u16 arg)
{
    u8 *a;
    int f;
    u8 result;
    u32 i;
    u8 *b;
    const u8 *m;
    a = func_021B9934(p->f8, (u8)e->index);
    f = 0;
    result = 0;
    for (i = 0; i < e->count; i++) {
        if (func_0689D588(p->w1ab8, e->ids[i])) {
            b = func_021B9934(p->f8, (u8)e->ids[i]);
            if (!func_021D5B68(b)) {
                if (func_021D5D14((s8 *)b, (u32)e->kind, e->a)) {
                    f = 1;
                    break;
                }
            }
        }
    }
    if (f && e->flag) func_021C5A1C(p, a);
    m = (const u8 *)e;
    m += 24;
    for (i = 0; i < e->count; i++) {
        if (func_0689D588(p->w1ab8, e->ids[i])) {
            b = func_021B9934(p->f8, (u8)e->ids[i]);
            if (!func_021D5B68(b)) {
                if (func_021C3008(p, e->index, b, e->kind, e->a, 31, arg, e->value, e->c, e->b == 0)) {
                    func_021C99A0(p, (const struct Msg *)m);
                    result = 1;
                }
            }
        }
    }
    if (f && e->flag) func_021C5A34(p, a);
    return result;
}









u8 func_021C9394(Server *p, const Ent_021C9394 *e)
{
    u8 *a;

    if (func_0689D588(p->w1ab8, e->b[0])) {
        a = func_021B9934((char *)p->f8, e->b[0]);
        if (func_021D5B68(a) == 0) {
            func_021D5EA8(a, 1, e->b[1]);
            func_021D5EA8(a, 2, e->b[2]);
            func_021D5EA8(a, 3, e->b[3]);
            func_021D5EA8(a, 4, e->b[4]);
            func_021D5EA8(a, 5, e->b[5]);
            func_021D5EA8(a, 6, e->b[6]);
            func_021D5EA8(a, 7, e->b[7]);
            func_021CD4B0(p->fC, 0xb, e->b[0], e->b[1], e->b[2], e->b[3], e->b[4], e->b[5], e->b[6], e->b[7]);
            return 1;
        }
    }
    return 0;
}









/*
 * extent: compiled 50 bytes; 021C947A..021C947C is alignment padding.
 * note: caller consumes live r0 after void-declared func_021D5EFC;
 *       return interface follows its explicit u8 truncation at 021C9470.
 */
u8 func_021C9448(Server *p, u8 *e)
{
    char *a;
    a = (char *)func_021B9934((char *)p->f8, e[4]);
    if (func_021D5B68(a) == 0) {
        func_021CD4B0(p->fC, 12, e[4]);
        return (u8)func_021D5EFC(a);
    }
    return 0;
}










u8 func_021C947C(Server *p, const Ent_021C9448 *e)
{
    u8 r = 0;
    u32 i;
    u8 *a;

    for (i = 0; i < e->n; i++) {
        a = func_021B9934(p->f8, e->ids[i]);
        if (func_021D5B68(a) == 0) {
            func_021CD4B0(p->fC, 0xd, e->ids[i]);
            func_021D5F08((char *)a);
            r = 1;
        }
    }
    return r;
}








u8 func_021C94C8(Server *p, const Ent_021C94C8 *e)
{
    u8 *a;
    if (func_0689D588(p->w1ab8, e->id)) {
        a = func_021B9934(p->f8, e->id);
        if (e->f0) { func_021D5970(a, 8, e->values[0]); func_021CD4B0(p->fC, 19, e->id, 8, (u8)e->values[0]); }
        if (e->f1) { func_021D5970(a, 9, e->values[1]); func_021CD4B0(p->fC, 19, e->id, 9, (u8)e->values[1]); }
        if (e->f2) { func_021D5970(a, 10, e->values[2]); func_021CD4B0(p->fC, 19, e->id, 10, (u8)e->values[2]); }
        if (e->f3) { func_021D5970(a, 11, e->values[3]); func_021CD4B0(p->fC, 19, e->id, 11, (u8)e->values[3]); }
        if (e->f4) { func_021D5970(a, 12, e->values[4]); func_021CD4B0(p->fC, 19, e->id, 12, (u8)e->values[4]); }
        func_021C99A0(p, (const struct Msg *)e->msg);
        return 1;
    }
    return 0;
}

















u8 func_021C95D0(Server *p, const Ent_021C95D0 *e)
{
    int a;

    if (func_0689D588(p->w1ab8, e->b4)) {
        a = (int)func_021B9934((char *)p->f8, e->b4);
        if (func_021D5B68((void *)a) == 0 || e->b5) {
            func_021C99A0(p, (void *)((u8 *)e + 8));
            func_021C2314(p, (u8 *)a);
            return 1;
        }
    }
    return 0;
}

















u8 func_021C962C(Server *p, const Ent_021C962C *e)
{
    int a;

    if (func_0689D588(p->w1ab8, e->b6)) {
        a = (int)func_021B9934((char *)p->f8, e->b6);
        if (func_021D5B68((void *)a) == 0 && func_0689C9C0(func_021D5444((void *)a)) == 0) {
            func_021CD4B0(p->fC, 0x16, e->b6, e->h4);
            func_021D66B0((void *)a, e->h4);
            if (e->b7 == 0 && func_021E8DA8(e->h4))
                func_021CD64C(p->fC, 0x5b, 0x380, e->b6, func_021E8CFC(e->h4), 0xffff0000);
            return 1;
        }
    }
    return 0;
}


















u8 func_021C96D4(Server *w, struct Cmd_021C96D4 *c)
{
    u8 *r = 0;
    int id = c->id;
    if (id != 0x1F) {
        r = func_021B9934((char *)w->f8, (u8)id);
    }
    if (c->flag && r) func_021C5A1C(w, r);
    func_021C99A0(w, (const struct Msg *)((u8 *)c + 4));
    if (c->flag && r) func_021C5A34(w, r);
    return 1;
}


















/*
 * extent: two bytes of trailing alignment padding.
 */
u8 func_021C9728(Server *p, u8 *q)
{
    u8 *a = func_021B9934((char *)p->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D5FC0((struct UtilWork *)a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}


















u8 func_021C9750(Server *p, u8 *q)
{
    u8 *a = func_021B9934((char *)p->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D6440(a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}


















u8 func_021C9778(Server *p, u8 *q)
{
    u8 *a = func_021B9934((char *)p->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C60EC(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}


















u8 func_021C97A4(Server *p, u8 *q)
{
    u8 *a = func_021B9934((char *)p->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C6110(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}

















u8 func_021C97D0(Server *w, const struct Cmd_021C97D0 *c)
{
    u32 v;
    void *pv;
    v = c->w8;
    pv = &v;
    func_021C7BA8(w, c->id, c->w4, c->b12, pv);
    if (func_06898C10(c->b12, c->w4, *(Word_021CAA58_td *)pv) != 0) {
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 0x10));
        return 1;
    }
    return 0;
}















static inline int test(u8 *s, u32 i)
{
    u8 idx = (i >> 3) + 1;
    u8 bit = i & 7;
    if (idx < s[4]) {
        if ((1 << bit) & s[4 + idx]) return 1;
        else return 0;
    }
    return 0;
}















u8 func_021C9828(Server *w, u8 *s)
{
    u8 r = 0;
    u32 i;
    for (i = 0; i < 14; i++) {
        if (test(s, i) && func_06898D10(s[7], i)) {
            func_021C4BAC(w, i, s[7]);
            r = 1;
        }
    }
    return r;
}














/*
 * extent: two bytes of trailing alignment padding.
 */
u8 func_021C9898(Server *p, u8 *q)
{
    if (func_021C3C60(p, *(int *)(q + 4), *(union Slot *)(q + 8), q[12])) {
        func_021C99A0(p, (const struct Msg *)(q + 16));
        return 1;
    }
    return 0;
}















u8 func_021C98C4(Server *p, u8 *q)
{
    if (func_021EF8E8(*(int *)(q + 4))) {
        func_021C4C50(p, *(int *)(q + 4));
        return 1;
    }
    return 0;
}
















u8 func_021C98E4(Server *w, struct Cmd_021C98E4 *c)
{
    u8 *id = func_021B9934((char *)w->f8, (u8)c->id);
    int r = 0;
    u32 s;
    if (c->b4 != 0) {
        if (func_021C3B8C(w, c->b4, c->b5) != 0) {
            if (c->flag) func_021C5A1C(w, id);
            func_021C3BB8(w, c->b4, c->b5);
            func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
            r = 1;
            if (c->flag) func_021C5A34(w, id);
        }
    } else if (c->b6 != 0) {
        if (c->flag) func_021C5A1C(w, id);
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
        s = func_021CC8D8(&w->lock, 15467);
        func_021C7BF8(w);
        func_021CC95C((u32 *)&w->lock, s, 15469);
        r = 1;
        if (c->flag) func_021C5A34(w, id);
    }
    return r;
}
















int func_021C99A0(Server *w, const struct Msg *m)
{
    if (!m->flag) {
        switch (m->kind) {
        case 1:
            func_021C5DAC(w, m->a, m->n, (const int *)m->data);
            return 1;
        case 2:
            func_021C5EFC(w, m->a, m->n, (const int *)m->data);
            return 1;
        }
    } else {
        u16 x = m->w20;
        switch (m->kind) {
        case 1:
            func_021C5E48(w, m->a, x, m->n, (int *)m->data);
            return 1;
        case 2:
            func_021C5F98(w, m->a, x, m->n, (int *)m->data);
            return 1;
        }
    }
    return 0;
}















/*
 * lever: const source pointer hoists the id load before the outgoing
 * stack-argument store; mutable source gave 16 scheduling bytes different.
 */
u8 func_021C9A24(Server *p, const struct Cmd_021C9A24 *q)
{
    int r;
    if (func_068981F0(q->w4, q->b8, q->id, q->data, q->b28)) r = 1;
    else r = 0;
    return r;
}












u8 func_021C9A60(Server *p, const Ent_021C9A60 *e)
{
    u8 *a;
    u16 x;
    int line;
    u32 s;
    u32 t;
    a = func_021B9934(p->f8, e->id);
    x = func_021D59B4(a, 16);
    if (func_0689C974(x)) return 0;
    if (func_021D5B68(a)) return 0;
    if (e->a || e->value != x) {
        if (e->flag) func_021CD4B0(p->fC, 87, (u8)e->index);
        func_021CD4B0(p->fC, 73, e->id, e->value);
        func_021C99A0(p, (const struct Msg *)e->msg);
        line = 15561;
        s = func_021CC8D8(&p->lock, line);
        func_021C7B3C(p, e->id, x, e->value);
        func_021CC95C((u32 *)&p->lock, s, line + 2);
        func_021D8510(a);
        func_021D66D0((struct QJ *)a, e->value);
        func_021CD4B0(p->fC, 29, e->id, e->value);
        func_021D8484(a);
        func_021CD4B0(p->fC, 88, e->id);
        if (x != e->value) {
            t = func_021CC8D8(&p->lock, line + 16);
            func_021C7B7C(p, e->id);
            line += 18;
            func_021CC95C((u32 *)&p->lock, t, line);
        }
        if (e->flag) func_021CD4B0(p->fC, 88, (u8)e->index);
        if (!func_021D62C4((struct Unk021D62A8 *)a, 16)) {
            if (x == 103) func_021C195C(p, a, 0);
            if (x == 127) func_021C3FDC(p, a);
        }
        return 1;
    }
    return 0;
}















u8 func_021C9BB8(Server *p, const Ent_021C9BB8 *e)
{
    u8 *a;
    int line;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(p->f8, e->id);
    if (e->index != e->id) {
        line = 15615;
        s = func_021CC8D8(&p->lock, line);
        f = func_021C7A54(p, a, e->value);
        func_021CC95C((u32 *)&p->lock, s, line + 2);
        if (f) {
            t = func_021CC8D8(&p->lock, line + 6);
            func_021C7AA0(p, a);
            func_021CC95C((u32 *)&p->lock, t, line + 8);
            return 0;
        }
    }
    if (e->flag) func_021CD4B0(p->fC, 87, (u8)e->index);
    func_021C99A0(p, (const struct Msg *)e->msg);
    func_021C2250(p, a, e->value, 0);
    if (e->flag) func_021CD4B0(p->fC, 88, (u8)e->index);
    if (e->a) {
        func_021D6738(a);
        func_021CD4B0(p->fC, 43, e->id);
    }
    if (e->b) {
        func_021D6738(func_021B9934(p->f8, e->c));
        func_021CD4B0(p->fC, 43, e->c);
    }
    func_021C195C(p, a, 0);
    return 1;
}
















/*
 * lever: truncated accessor results live in u32 locals; u16 locals rotate seven spill offsets.
 */
u8 func_021C9CC0(Server *p, const Ent_021C9CC0 *e)
{
    u8 *a;
    u8 *b;
    u16 x;
    u16 y;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(p->f8, (u8)e->id);
    b = func_021B9934(p->f8, (u8)e->index);
    x = (u16)(int)func_021D5B40((struct QI *)b);
    y = (u16)(int)func_021D5B40((struct QI *)a);
    s = func_021CC8D8(&p->lock, 15671);
    f = func_021C7A54(p, a, x);
    func_021CC95C((u32 *)&p->lock, s, 15673);
    if (f) {
        t = func_021CC8D8(&p->lock, 15676);
        func_021C7AA0(p, a);
        func_021CC95C((u32 *)&p->lock, t, 15678);
        return 0;
    }
    if (e->flag) func_021C5A1C(p, b);
    func_021C99A0(p, (const struct Msg *)e->msg);
    func_021C99A0(p, (const struct Msg *)(e->msg + 36));
    func_021C99A0(p, (const struct Msg *)(e->msg + 72));
    if (e->flag) func_021C5A34(p, b);
    func_021C2250(p, b, y, 0);
    func_021C2250(p, a, x, 0);
    func_021C195C(p, b, 0);
    func_021C195C(p, a, 0);
    return 1;
}
















u8 func_021C9DCC(Server *p, u8 *q)
{
    u8 *a = func_021B9934((char *)p->f8, q[4]);
    func_021C195C(p, a, *(u32 *)(q + 8));
    return 1;
}
















u8 func_021C9DE8(Server *w, struct Cmd_021C9DE8 *c)
{
    u8 *r = func_021B9934((char *)w->f8, (u8)c->id);
    if (func_021D5B68(r) == 0 || c->f1) {
        if (c->f0 && func_021D5B48(r) != 0) return 0;
        if (func_021C2128(w, r) != 0) return 1;
    }
    return 0;
}
















u8 func_021C9E3C(Server *w, struct Cmd_021C9E3C *c)
{
    int r = (int)func_021B9934((char *)w->f8, c->b4);
    int x;
    u16 t;
    u32 s;
    if (func_021D5B68((void *)r) == 0) {
        x = (int)func_021DCF78((void *)r, c->h6);
        if (x != 0) {
            t = func_021CD4FC(w->fC, 0x42);
            s = func_021CC8D8(&w->lock, 15755);
            func_021C6E00(w, (u8 *)r, c->id);
            if (func_021C88E4(w) == 2) {
                func_021CD568(w->fC, t, 0x42, c->b4);
            }
            func_021CC95C((u32 *)&w->lock, s, 15762);
            func_021DCF9C((void *)x);
            return 1;
        }
    }
    return 0;
}
















u8 func_021C9ECC(Server *w, struct Cmd_021C9ECC *c)
{
    u8 *r = func_021B9934((char *)w->f8, (u8)c->id);
    if (c->w4 == 0) {
        func_021C60D4(w, r);
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    }
    func_021C2250(w, r, 0, 1);
    return 1;
}
















u8 func_021C9F0C(Server *w, const struct Cmd_021C9F0C *c)
{
    u8 *r = func_021B9934((char *)w->f8, c->b4);
    func_021CD4B0(w->fC, 0x1F, c->b4, c->b5, c->b6, c->b7, c->h8);
    func_021D5734(r, c->b5, c->h8, c->b6, c->b7);
    return 1;
}













u8 func_021C9F4C(Server *p, u8 *q)
{
    u8 *a = func_021B9934((char *)p->f8, q[4]);
    func_021C0780(p, a, q[5], q[6]);
    return 1;
}












u8 func_021C9F6C(Server *p, u8 *q)
{
    u8 work[28];
    struct Out *out = (struct Out *)(work + 8);
    u16 *saved;
    u8 *a = func_021B9934((char *)p->f8, q[4]);
    u8 *b = func_021B9934((char *)p->f8, q[5]);
    struct State_p13 *state;
    u32 flag;
    func_021C64B4(p, *(u16 *)(q + 6), a, (struct Out64B4 *)out);
    func_0689CB3C(p->f860);
    func_0689CB3C(p->f868);
    func_0689CB48(p->f868, b);
    func_0689CD48(p->f868, 1);
    func_0689CEE4(p->f868);
    if (func_0689CD50(p->f868)) {
        func_021C5718(p, a, ((u16 *)work)[4]);
        return 0;
    }
    func_021BF83C(p, (u16 *)out, a, p->f868);
    func_021BF3D8(p, (int)out, a, p->f868, p->w1f88);
    func_021BF4AC(p, (u8 *)out, a, p->f868, p->w1f88);
    func_021BF8D4(p, (u16 *)out, a, p->f868);
    if (func_0689CD50(p->f868)) return 0;
    state = (struct State_p13 *)p->f4a8;
    saved = (u16 *)work;
    saved[0] = ((struct Obj05194 *)state)->f0;
    saved[1] = ((struct Obj05194 *)state)->f2;
    saved[2] = ((struct Obj05194 *)state)->f4;
    func_021BD1E0((struct Unk021BD1E0 *)state);
    func_021BD200((struct Unk021BD1E0 *)((struct State_p13 *)p->f4a8), p, a, p->f868);
    ((struct State_p13 *)p->f4a8)->b4 = 1;
    func_021C091C(p, (u8 *)out, a, (u8 *)p->f868, (const u32 *)p->w1f88, 1);
    state = (struct State_p13 *)p->f4a8;
    flag = state->flag;
    ((struct Obj05194 *)state)->f0 = saved[0];
    ((struct Obj05194 *)state)->f2 = saved[1];
    ((struct Obj05194 *)state)->f4 = saved[2];
    return flag;
}











u8 func_021CA128(Server *p, struct Bits_p13 *q)
{
    u8 *a = func_021B9934((char *)p->f8, (u8)q->index);
    if (func_021BD60C(p, a, 1)) {
        p->f14 = 5;
        return 1;
    }
    return 0;
}













u8 func_021CA158(Server *w, struct Cmd_021CA158 *c)
{
    u8 *r = func_021B9934((char *)w->f8, c->b4c);
    if (func_021BC2B0(w) == 0 && func_021C8374(w, c->b4c) == 0 && w->f14 == 0) {
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 4));
        if (func_021BDD00(w, r, c->b4d) != 0) {
            func_021BB930(w->f0, func_021B8D8C(w->f4, w->f8, c->b4c));
            func_021C99A0(w, (const struct Msg *)((u8 *)c + 0x28));
            w->f14 = 1;
            return 1;
        }
    }
    return 0;
}













u8 func_021CA1D0(Server *w, const struct Cmd_021CA1D0 *c)
{
    u8 *a = func_021B9934((char *)w->f8, c->b4);
    u8 *b = func_021B9934((char *)w->f8, c->b5);
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x10) != 0) func_021C2CA8(w, b);
    func_021D65C8((struct Work *)b, (struct Work *)a);
    func_021CD4B0(w->fC, 0x26, c->b4, c->b5);
    if (func_021D6D7C(b) != 0) {
        int r = func_0689D5C8(w->w1ab8, c->b5);
        func_021CD4B0(w->fC, 0x51, r);
    }
    return 1;
}











u8 func_021CA248(Server *p, const u8 *q)
{
    u8 r;
    if (func_021C1D60(p, func_021B9934((char *)p->f8, q[4]), q[5])) r = 1;
    else r = 0;
    return r;
}












u8 func_021CA270(Server *w, const struct Cmd_021CA248 *c)
{
    u8 s;
    u8 a;
    u8 b;
    func_021D5FA4((struct Unk021D5FA4 *)func_021B9934((char *)w->f8, c->b4), c->h6);
    func_021CD4B0(w->fC, 2, c->b4, c->h6);
    w->w7a9[c->b4] = 0;
    func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    s = func_021B8D8C(w->f4, w->f8, c->b4);
    if (s != 6) {
        a = func_021B8DDC(c->b4);
        b = func_021B8DEC((char *)w->f4, s);
        func_021BD9D4(w, a, b, b, 1);
        func_021BDA00(w);
    }
    return 1;
}











/*
 * extent: two zero bytes at 021CA316 are alignment padding.
 */
u8 func_021CA2E8(Server *p, const u8 *q)
{
    func_021D67D8(func_021B9934((char *)p->f8, q[4]), *(const u16 *)(q + 6));
    func_021CD4B0(p->fC, 20, q[4], *(const u16 *)(q + 6));
    func_021C99A0(p, (const struct Msg *)(q + 8));
    return 1;
}












u8 func_021CA318(Server *p, const struct Q_021C95D0 *q)
{
    int out[1];
    u8 *a = func_021B9934((char *)p->f8, q->f);
    u8 *b = func_021B9934((char *)p->f8, (u8)q->b);
    if (func_021C3810(p, b, a, q->lo, out, q->e, q->hi, (const struct Msg *)((u8 *)q + 8))) return 1;
    return 0;
}











/*
 * extent: two zero bytes at 021CA392 are alignment padding.
 */
u8 func_021CA370(Server *p, const u8 *q)
{
    if (func_021BD148(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}











u8 func_021CA394(Server *p, const u8 *q)
{
    u8 r;
    if (func_021BD170(p, *(const u16 *)&((struct Obj21127 *)q)->f4)) r = 1;
    else r = 0;
    return r;
}











/*
 * extent: two zero bytes at 021CA3CE are alignment padding.
 */
u8 func_021CA3AC(Server *p, const u8 *q)
{
    if (func_021BD1B0(p, q[4])) {
        func_021C99A0(p, (const struct Msg *)(q + 8));
        return 1;
    }
    return 0;
}












u8 func_021CA3D0(Server *p, u8 *q)
{
    int a, b;
    u8 *m1, *m2;
    char *o;
    s16 i, j;
    if (q[4] != q[5]) {
        a = func_021B8DDC(q[4]);
        b = func_021B8DDC(q[5]);
        if (a == b) {
            m1 = func_021B9934((char *)p->f8, q[4]);
            m2 = func_021B9934((char *)p->f8, q[5]);
            if (!func_021D5B68(m1) && !func_021D5B68(m2)) {
                o = func_021B9AEC((char *)p->f8, a);
                i = func_021B9C98((u8 *)o, (u32)m1);
                j = func_021B9C98((u8 *)o, (u32)m2);
                if (i >= 0 && j >= 0) {
                    func_021BD43C(p, a, i, j, 0);
                    func_021C99A0(p, (const struct Msg *)(q + 8));
                    func_021BD4E4(p, a, i, j);
                    return 1;
                }
            }
        }
    }
    return 0;
}











u8 func_021CA47C(Server *p, struct Cmd_021CA2E8 *q)
{
    u8 *a = func_021B9934((char *)p->f8, (u8)q->id);
    u8 *b = func_021B9934((char *)p->f8, (u8)q->target);
    u16 k;
    int x, y;
    u32 lock;
    if (!func_021D6C24((struct R4 *)a) && !func_021D6C24((struct R4 *)b) && !func_021D5C30((struct UtilWork *)a)) {
        k = func_021D59B4(a, 16);
        if (func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b)) {
            x = func_021D5440(a);
            y = func_021D5440(b);
            if (q->flag) func_021C5A1C(p, a);
            func_021E0434(a);
            func_021D8510(a);
            func_021D8484(a);
            func_021CD4B0(p->fC, 0x53, x, y);
            func_021C99A0(p, (const struct Msg *)((u8 *)q + 8));
            if (q->flag) func_021C5A34(p, a);
            if (k != func_021D59B4(a, 17)) {
                lock = func_021CC8D8(&p->lock, 0x3f0a);
                func_021C7B7C(p, x);
                func_021CC95C((u32 *)&p->lock, lock, 0x3f0c);
            }
            return 1;
        }
    }
    return 0;
}












u8 func_021CA570(Server *p, u8 *q)
{
    u8 *m;
    if (func_0689D588(p->w1ab8, q[4])) {
        m = func_021B9934(p->f8, q[4]);
        if (func_021D6C24((struct R4 *)m)) {
            func_021D6C2C((struct Unk021D6C2C *)m);
            func_021CD4B0(p->fC, 0x4b, q[4]);
            func_021C99A0(p, (const struct Msg *)(q + 8));
            return 1;
        }
    }
    return 0;
}










/*
 * lever: C7F68 returns its normalized u8 j, and u8 n restores the count reload.
 */
u8 func_021CA5CC(Server *p, const struct Cmd *q)
{
    u8 buf[8];
    u8 n;
    u8 i;
    u8 *a;
    int changed;
    u8 t;
    n = func_021C7F68(p, (u16)(func_021B8D8C(p->f4, p->f8, (u8)q->id) | 0x800), buf);
    i = 0;
    if (i >= n) goto done;
loop:
    {
        a = (u8 *)func_021B9934((char *)p->f8, buf[i]);
        changed = 0;
        if (func_021D5BDC((struct UtilWork *)a, 3)) {
            func_021C5418(p, a, 3);
            t = func_021D69AC(a, 4);
            if (!(t && (t = (u8)(t - 1)) < 24)) t = 31;
            if (t != 31) func_0203EFC8((const u8 *)p, a, 1);
            changed = 1;
        }
        if (func_021C6F34(p, a, 1)) changed = 1;
        if (func_021D62C4((struct Unk021D62A8 *)a, 30)) {
            func_021C5620(p, a, 30, 0);
            changed = 1;
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 32)) {
            func_021C5620(p, a, 32, 0);
            changed = 1;
        }
        if (changed) func_021CD64C(p->fC, 0x5b, 0x43b, buf[i], 0xffff0000);
    }
    i++;
    if (i < n) goto loop;
done:
    return 1;
}










u8 func_021CA6C4(Server *p, const u8 *q)
{
    u8 *m = func_021B9934((char *)p->f8, q[4]);
    if (!func_021D5B68(m) && func_021C5418(p, m, *(const int *)(q + 8))) {
        func_021C99A0(p, (const struct Msg *)(q + 12));
        return 1;
    }
    return 0;
}










u8 func_021CA6FC(Server *p, const u8 *q)
{
    if (q[11]) func_021CD4B0(p->fC, 86, 0);
    func_021C70E4(p, *(const u16 *)(q + 4), q[6], q[7], q[10], *(const u16 *)(q + 8));
    func_021C99A0(p, (const struct Msg *)(q + 12));
    return 1;
}











/* 021CA738  3-arg call on field 0xc, then returns 1 */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; ldr r0, [r0, #0xc]; movs r1, #0x56; movs r2, #0; bl func_021CD4B0; movs r0, #1; pop {r3, pc}.
 */
u8 func_021CA738(Server *p, void *unused)
{
    func_021CD4B0((void *)(p->fC), 0x56, 0);
    return 1;
}













/*
 * The listing extent (172 bytes) runs on into func_021CA7C4 and func_021CA7D4,
 * which are filed separately.
 */
u8 func_021CA748(Server *p, const struct Q_021CA5CC *q)
{
    u8 t;
    void *m = func_021B9934((char *)p->f8, ((u8 *)q)[4]);
    if (!func_021D5B68(m) && !func_021D6D54(m)) {
        t = func_021D59B4(m, 0x13);
        if (t != ((u8 *)q)[5]) {
            if (q->f) func_021C5A1C(p, m);
            func_021D66D8(m, ((u8 *)q)[5]);
            func_021CD4B0(p->fC, 0x4f, ((u8 *)q)[4], ((u8 *)q)[5]);
            func_021C99A0(p, (const struct Msg *)((u8 *)q + 8));
            if (q->f) func_021C5A34(p, m);
            return 1;
        }
    }
    return 0;
}














/* command handler: copy the argument byte of the command into the state block */
u8 func_021CA7C4(Server *s, u8 *cmd)
{
    s->f4a8[4] = cmd[4];
    return 1;
}














/* command handler: latch the state flag once */
u8 func_021CA7D4(Server *s, void *cmd)
{
    BattleState *st = (BattleState *)s->f4a8;

    if (!st->flag)
        st->flag = 1;
    return 1;
}











int func_021CA7F4(Server *p, u8 *a, u8 b, const u8 *q, void *out)
{
    u32 mode = func_021B8588(p->f4);
    u32 id = 31;
    if (!((struct Flags *)(q + 16))->a) id = func_021CB214(p, a, (u8 *)q);
    func_0689CB3C(out);
    p->f77f = 6;
    switch (mode) {
    case 0: default:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    case 1:
        id = func_021CAA58(p, a, b, (u8 *)q, id, out);
        break;
    case 2:
        id = func_021CACF4(p, a, b, (u8 *)q, id, out);
        break;
    case 3:
        id = func_021CA8F8(p, a, b, (u8 *)q, id, out);
        break;
    }
    if (id == 1) {
        u8 *m = func_0689CC70(out, 0);
        if (m) p->f77f = func_0689D5F4(p->w1ab8, func_021D5440(m));
        if (!func_021CAFD8(p, mode, a, (const u16 *)q, b, out)) id = 0;
    }
    return id;
}







int func_021CA8F8(Server *p, u8 *a, int unused, u8 *q, int id, void *out)
{
    u8 n = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
    u8 *b;
    switch (*(u32 *)(q + 12)) {
    case 0: case 3: case 4: case 5: case 9:
        if (id == 31) b = func_021CB174(p, n, 0);
        else b = (u8 *)func_021B9934((char *)p->f8, id);
        func_0689CB48(out, b);
        return 1;
    case 1: case 7:
        if (id == 31) func_0689CB48(out, a);
        else func_0689CB48(out, (void *)func_021B9934((char *)p->f8, id));
        return 1;
    case 8:
        func_0689CB48(out, a);
        func_0689CB48(out, func_021CB174(p, n, 0));
        return 2;
    case 13:
        if (id != 31) {
            func_0689CB48(out, (void *)func_021B9934((char *)p->f8, id));
            return 1;
        }
        return 0;
    case 2: case 6: case 10: case 11: case 12: default:
        return 0;
    }
}






u8 func_021CAA24(Server *p, u8 *q, int m, u8 n, u8 value)
{
    if (((struct Obj09977 *)q)->f0 == 174) {
        if (((struct Obj09977 *)q)->fC == 0) {
            if (n == value || value == 6)
                return func_021D80BC(p->f4, (int)p->f8, m, 174);
        } else if (((struct Obj09977 *)q)->fC == 7 && n != value) {
            value = n;
        }
    }
    return value;
}








int func_021CAA58(Server *p, u8 *a, u8 move, u8 *q, int id, void *out)
{
    u8 n = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
    u8 key = func_021CAA24(p, q, (int)a, n, move);
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
        b = func_021CB174(p, n, (u8)func_021D78AC(2));
        break;
    case 5:
        func_0689CB48(out, func_021CB174(p, n, (u8)0));
        func_0689CB48(out, func_021CB174(p, n, (u8)1));
        return 2;
    case 4:
        func_0689CB48(out, func_021CB1A4(p, n));
        func_0689CB48(out, func_021CB174(p, n, (u8)0));
        func_0689CB48(out, func_021CB174(p, n, (u8)1));
        return 3;
    case 8:
        func_0689CB48(out, a);
        func_0689CB48(out, func_021CB1A4(p, n));
        func_0689CB48(out, func_021CB174(p, n, (u8)0));
        func_0689CB48(out, func_021CB174(p, n, (u8)1));
        return 3;
    case 7:
        if (id == 31) func_0689CB48(out, a);
        else func_0689CB48(out, (void *)func_021B9934((char *)p->f8, id));
        return 1;
    case 1:
        func_0689CB48(out, func_021B98A4(p->f8, key));
        return 1;
    case 2:
        func_0689CB48(out, func_021CB1A4(p, n));
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
        func_0689CB48(out, b);
        return 1;
    }
    return 0;
}










int func_021CACF4(Server *p, u8 *a, u8 move, u8 *q, long id, void *out)
{
    u32 i, count;
    u8 n = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
    u8 *b = (u8 *)func_021B99E0(n);
    u8 key = func_021CAA24(p, q, (int)a, n, move);
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
            func_0689CB48(out, func_021B98A4(p->f8, b[4 + i]));
        return (u8)*(u16 *)b;
    case 4: {
        long j;
        i = 0;
        count = 0;
        for (; i < *(u16 *)b; i++) {
            func_0689CB48(out, func_021B98A4(p->f8, b[4 + i]));
            count++;
        }
        for (j = 0; (u32)j < *(u16 *)(b + 2); j++) {
            if (n != b[7 + j]) {
                func_0689CB48(out, func_021B98A4(p->f8, b[7 + j]));
                count++;
            }
        }
        return (u8)count;
    }
    case 8:
        func_0689CB48(out, a);
        for (i = 0; i < 3; i++) {
            selected = func_021B8C38(n, (u8)i);
            if (selected != n) func_0689CB48(out, func_021B98A4(p->f8, selected));
        }
        func_0689CB48(out, func_021CB174(p, n, 0));
        func_0689CB48(out, func_021CB174(p, n, 1));
        func_0689CB48(out, func_021CB174(p, n, 2));
        return 6;
    case 7:
        if (id == 31) func_0689CB48(out, a);
        else func_0689CB48(out, (void *)func_021B9934((char *)p->f8, id));
        return 1;
    case 1:
        func_0689CB48(out, func_021B98A4(p->f8, key));
        return 1;
    case 2:
        func_0689CB48(out, func_021B98A4(p->f8, key));
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
        func_0689CB48(out, b);
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
    if (func_021D7F00(mode) <= 1 || func_0689CD38(out) != 1) goto fail;
    previous = func_0689CC70(out, 0);
    if (!func_021D5B68(previous)) goto fail;
    if (func_021B9A24(func_021D5440(m), func_021D5440(previous))) goto fail;
    position = func_021B8D8C(p->f4, p->f8, func_021D5440(m));
    func_0689CC14(out, previous);
    if (func_0201BEB8((void *)*item, 0xb)) target = 0x600 | position;
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
    if (members[choice]) { func_0689CB48(out, (void *)members[choice]); return 1; }
fail:
    return 0;
}











/*
 * interface: func_021B8C50 forwards live r1/r2 to func_021B8C20 and returns r0.
 */
void *func_021CB174(Server *p, u8 n, int k)
{
    u8 out[2];
    func_021B8E28((u8 *)p->f4, func_021B8C50(p->f4, n, k), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(func_021BB85C(p->f0, out[1]) + 4), out[0]);
}











void *func_021CB1A4(Server *p, u8 n)
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
    state = func_0689D5C8(p->w1ab8, monId);
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
        if (func_0689C9A0(*(int *)t)) {
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
    u8 m;
    u8 *w;
    Word_021CAA58_td t;
    m = func_021B9A40(func_021D5440(q));
    t = func_021E8940(5);
    if (func_06898C10(m, 3, t)) {
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
        if (func_0689D588(p->w1ab8, func_021D5440(m)) == 0) {
            ret = 0;
            i = 0;
            for (;;) {
                k = func_0689C9E4(i++);
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
    if (func_0689D5C8(p->w1ab8, id) != 6) {
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

    if (func_0689C8FC((u16)(u32)func_021D5B40(m)) == 0) {
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
        k = func_0689D1D4(p+0x3e0);
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











u32 func_021CC918(Bf_td *p, u32 v, int unused)
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
    int flag;
    u16 n;
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
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 owner: the integrator). Integrator: seed label.
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
                    if (func_021D8454((Action *)(p + 0x124 + p[0x11D] * 4)) == 3)
                        func_0689CB08(p + 0x190);
                    if (func_021D8454((Action *)(p + 0x124 + p[0x11D] * 4)) == 2)
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
            k = func_021D8454(*(Action * *)&((struct Obj00434 *)p)->fC);
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
                        k = func_021D8340((Action *)(p + 0xc0));
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
    u32 r;
    u8 n;
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
            if (func_0689CB14(p + 0x190) == 0) {
                n = func_0689CB1C(p + 0x190);
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
    if (func_021D62C4(m, 0xf) && func_0201BEB8((void *)move, 0xc)) {
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
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) && func_0201BEB8((void *)move, 9)) {
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
    if (func_021D5B68(func_021B9C00(g->list, (u8)(int)func_021B9AB0(2))) == 0) {
        buf[cnt++] = 2;
    }
    if (func_021D5B68(func_021B9C00(g->list, (u8)(int)func_021B9AB0(3))) == 0) {
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
    u8 sel;
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
            sel = func_021D06C8((struct G *)p);
            if (sel != 1) {
                sub = func_021B9AB0(sel);
                func_021D83FC((u32 *)(*(u8 **)(p+12)),sel);
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
    func_0689CA98(q, ((struct Obj13364 *)p)->f118, b, a);
    func_0689CAB0(q, p[0x11c]);
    func_0689CAE0(out, q);
}







void func_021D0B6C(u8 *g, u8 *s)
{
    u8 i;

    for (i = 0; i < s[6]; i++)
        func_021D8394(g + 0x124 + i * 4, s[i + 3], s[i]);
    *(u8 * *)&((struct Obj13365 *)g)->fD8 = g + 0x124;
    ((struct Obj13365 *)g)->fDC = s[6] << 2;
}






void func_021D0BB0(u8 *p)
{
    u8 pair[2];
    u8 start;
    u8 count;
    u32 n;
    u32 i;
    u32 j;
    count = 0;
    n = func_021B9B94(((struct Obj03198 *)p)->f118);
    start = func_021B99C0(((struct Obj03198 *)p)->f0, p[0x1a6]);
    for (i = 0; i < p[0x1b3]; i++) {
        func_021B8E28(*(u8 * *)&((struct Obj03198 *)p)->f0, p[0x1b5 + i], &pair[1], &pair[0]);
        for (j = start; j < n; j++) {
            if (!func_021D5B68(func_021B9C00(((struct Obj03198 *)p)->f118, (u8)j))) {
                func_021D8394(p + 0x124 + count++ * 4, pair[0], j);
                start = j + 1;
                break;
            }
        }
    }
    ((struct Obj03198 *)p)->fD8 = p + 0x124;
    ((struct Obj03198 *)p)->fDC = count * 4;
}







u8 func_021D0C78(BattleSeq_021D0B6C *s, u8 *out)
{
    u8 *arr;
    u8 n;
    u32 i;
    u32 cnt;

    n = func_021EEC20(((struct Obj09995 *)s)->f50, &arr);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        if (s->unk1A6 == func_021B8DE4(s->battle, arr[i])) {
            out[cnt] = arr[i];
            cnt++;
        }
    }
    return cnt;
}







int func_021D0CC4(BattleSeq_021D0B6C *s, int *state)
{
    int t;
    u8 *q;
    u8 f;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 3, 5);
        func_021EAF18((struct L *)((u8 *)s + 0x7c), 3, 1);
        func_021EABC4(s->msgWin, (u32)s->msg, (u32)((u8 *)s + 0x7c), 0);
        (*state)++;
        break;
    case 1:
        if (func_021EAC54(s->msgWin, &t)) {
            f = 0;
            if (t != 0)
                f = 1;
            q = (u8 *)s + 0x1ac;
            *q = f;
            *(u8 * *)&((struct Obj05202 *)s)->fD8 = q;
            ((struct Obj05202 *)s)->fDC = 1;
            return 1;
        }
        break;
    }
    return 0;
}





int func_021D0D38(u8 *p, int *state)
{
    return func_021D0E7C(p, state, 2);
}





int func_021D0D44(u8 *p, int *state)
{
    return func_021D0E7C(p, state, 1);
}






/*
 * lever: separate order[6] then pair[2] stack arrays keep the order base
 * at sp+6 and the index in the ldrb register offset; one buffer or a
 * struct member array reassociates this into a base+index and immediate 2.
 * follower: 021D0E74 is an eight-byte tail-call stub to func_021CE1B0;
 * included in this complete 300-byte unit after parent ownership audit.
 */
int func_021D0D50(u8 *p)
{
    u8 order[6];
    u8 pair[2];
    u8 count;
    u8 n;
    u8 i;
    u8 *target;
    int result;
    p[0x1b3] = func_021D0C78((BattleSeq_021D0B6C *)p, p+0x1b5);
    if (p[0x1b3]) {
        n = func_021D0980(p,order);
        if (n) {
            count = p[0x1b3];
            target = func_021CFD50((struct G_021CFD50 *)p,p[0x1b5]);
            if (target) func_021D09E0(p,order,n,target);
            if (count > n) {
                if (func_021B8588(*(void ** *)&((struct Obj01236 *)p)->f0) == 3) {
                    result = func_021D1058(p,p+0x124);
                    if (result) {
                        *(int *)&((struct Obj01236 *)p)->fDC = result;
                        ((struct Obj01236 *)p)->fD8 = p+0x124;
                        return 1;
                    }
                }
                count = n;
            }
            for (i=0;i<count;i++) {
                func_021B8E28(*(u8 * *)&((struct Obj01236 *)p)->f0,p[0x1b5+i],pair,pair+1);
                func_021D8394(p+0x124+i*4,pair[1],order[i]);
            }
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = count*4;
        } else {
            if (func_021D102C((char *)p)) {
                result = func_021D1058(p,p+0x124);
                if (result) {
                    *(int *)&((struct Obj01236 *)p)->fDC = result;
                    ((struct Obj01236 *)p)->fD8 = p+0x124;
                    return 1;
                }
            }
            func_021D83C4((u32 *)(p+0x124));
            ((struct Obj01236 *)p)->fD8 = p+0x124;
            ((struct Obj01236 *)p)->fDC = 4;
        }
    } else {
        func_021D8434((u32 *)(p+0x124));
        ((struct Obj01236 *)p)->fD8 = p+0x124;
        ((struct Obj01236 *)p)->fDC = 4;
    }
    return 1;
}






int func_021D0E74(u8 *p,int *state)
{
    return func_021CE1B0(p,state);
}






/*
 * lever: the state-0 fallbacks and single-mon path set state 4, not 6;
 * duplicating the state-4 assignment inside both fallback arms preserves
 * the late cross-jump of D8/DC stores. Factoring it outside adds 12 bytes.
 * volatile: count at 021D0EB2 is reread at 021D0EB6 and 021D0ECC.
 */
int func_021D0E7C(u8 *p, int *state, u8 param)
{
    u8 order[6];
    u8 pair[2];
    u32 n;
    u32 count;
    int mode;
    void *mon;
    switch (*state) {
    case 0:
        ((CountField *)p)->count = func_021D0C78((BattleSeq_021D0B6C *)p, p + 0x1B5);
        if (((CountField *)p)->count != 0) {
            n = func_021D0980(p, order);
            if (n != 0) {
                count = ((CountField *)p)->count;
                if (count > n) count = n;
                if (func_021D102C((char *)p) != 0) {
                    mon = func_021B9C00(((struct Obj00819 *)p)->f118, 0);
                    if (n == 1 && func_021D5B68(mon) != 0) {
                        func_021D8394(p + 0x124, 0, order[0]);
                        *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                        ((struct Obj00819 *)p)->fDC = 4;
                        *state = 4;
                        break;
                    }
                }
                func_021B8E28(*(u8 * *)&((struct Obj00819 *)p)->f0, p[0x1B5], &pair[1], &pair[0]);
                func_021D0B10(p, param, count, p + 0x184, p + 0x190);
                func_021E9A78(((struct Obj00819 *)p)->f54, p + 0x184, pair[0], 0, p + 0x190);
                func_021CE068(p);
                *state = 1;
            } else {
                if (func_021D102C((char *)p) != 0 && (mode = func_021D1058(p, p + 0x124)) != 0) {
                    ((struct Obj00819 *)p)->fDC = mode;
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    *state = 4;
                } else {
                    func_021D83C4((u32 *)(p + 0x124));
                    *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
                    ((struct Obj00819 *)p)->fDC = 4;
                    *state = 4;
                }
            }
        } else {
            func_021D8434((u32 *)(p + 0x124));
            *(u8 * *)&((struct Obj00819 *)p)->fD8 = p + 0x124;
            ((struct Obj00819 *)p)->fDC = 4;
            *state = 4;
        }
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021E9B14(((struct Obj00819 *)p)->f54);
            *state = 2;
        } else if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            func_021D0B6C(p, p + 0x190);
            *state = 3;
        }
        break;
    case 2:
        if (func_021E9B20(((struct Obj00819 *)p)->f54) != 0) {
            func_021D0BB0(p);
            *state = 3;
        }
        break;
    case 3:
        func_021CE0E0(p);
        *state = 4;
        break;
    case 4:
        if (func_021B86C0(((struct Obj00819 *)p)->f0) != 0) {
            p[0x1A9] = 1;
            func_021EA7FC(((struct Obj00819 *)p)->f54);
            *state = 5;
        } else {
            *state = 6;
        }
        break;
    case 5:
        if (func_021EA814(((struct Obj00819 *)p)->f54) != 0) {
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
int func_021D102C(char *p)
{
    if (func_021B8588(((struct Obj13368 *)p)->f0) == 3 && func_021D5B68(func_021B9C00(((struct Obj13368 *)p)->f118, 0)) != 0) return 1;
    return 0;
}







int func_021D1058(u8 *s, void *q)
{
    int k;

    k = 2;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)(int)func_021B9AB0(2))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    k = 3;
    if (func_021D5B68(func_021B9C00(((struct Obj13369 *)s)->f118, (u8)(int)func_021B9AB0(3))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    return 0;
}



int func_021D10B8(u8 *p, int *state)
{
    u8 *args;
    int choice;
    u8 count;
    switch (*state) {
    case 0:
        func_021EEC20(*(int *)(p + 0x50), &args);
        if (args[0] != 0x1F) {
            func_021EAF18((struct L *)(p + 0x58), 1, 0x14);
            func_021EAF50((struct L *)(p + 0x58), 1);
            func_021EAF50((struct L *)(p + 0x58), args[0]);
            func_021EAF78(p + 0x58, 0xFF);
            func_021EA614(*(void **)(p + 0x54), (struct H *)(p + 0x58));
            *state = 1;
        } else *state = 4;
        break;
    case 1:
        func_021EA710(*(void **)(p + 0x54));
        if (func_021EA720(*(void **)(p + 0x54)) != 0) {
            func_021EAF18((struct L *)(p + 0x58), 3, 6);
            func_021EAF18((struct L *)(p + 0x7C), 3, 7);
            func_021EABC4(*(void **)(p + 0x54), (u32)(p + 0x58), (u32)(p + 0x7C), 1);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(*(void **)(p + 0x54)) != 0) {
            if (func_021EAC54(*(void **)(p + 0x54), &choice) != 0) {
                if (choice == 0) {
                    func_021D0B10(p, 0, 1, p + 0x184, p + 0x190);
                    func_021E9A78(*(void **)(p + 0x54), p + 0x184, 0, 0, p + 0x190);
                    *state = 3;
                } else *state = 4;
            }
        }
        break;
    case 3:
        if (func_021E9B20(*(void **)(p + 0x54)) != 0) {
            if (func_0689CB14(p + 0x190) == 0) {
                count = func_0689CB1C(p + 0x190);
                if (count != 0 && count < 6) {
                    func_021D8394(p + 0x124, 0, count);
                    *state = 5;
                } else {
invalid:
                    *state = 4;
                }
            } else goto invalid;
        }
        break;
    case 4:
        func_021D8434((u32 *)(p + 0x124));
        *state = 5;
    case 5:
        *(u8 **)(p + 0xD8) = p + 0x124;
        *(int *)(p + 0xDC) = 4;
        return 1;
    }
    return 0;
}











int func_021D123C(int a)
{
    u8 *tmp;
    int r4 = func_021EEC20(((struct Obj05203 *)a)->f50, &tmp);
    if (((struct Obj05203 *)a)->f10 != 0)
        func_021EE608((u8 *)(((struct Obj05203 *)a)->f10), (const u8 *)tmp, r4);
    if (((struct Obj05203 *)a)->fA0 != 0) {
        func_021BB4E0((Obj_td *)((struct Obj05203 *)a)->fA0, tmp, r4);
        ((struct Obj05203 *)a)->f1AE = func_021EE638((u8 *)tmp);
    }
    return 1;
}










/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D127C(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1290(p, state, q);
    return 1;
}









/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, not a shifted integer mask.
 */
int func_021D1290(u8 *p, int *state, void *a2)
{
    int idx;
    int mode;
    u8 flag;
    u16 msg;
    switch (*state) {
    case 0:
        if (((Flags_p15 *)p)->flag != 0)
            return 1;
        idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
        mode = func_021D13A4((BattleSeq_021D123C *)p);
        flag = func_021B86C8((unsigned char **)(*(u8 * *)&((struct Obj00066 *)p)->f0));
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        switch (mode) {
        case 1: msg = flag != 0 ? 0x31 : 0x30; break;
        case 0: msg = flag != 0 ? 0x33 : 0x32; break;
        case 2: msg = flag != 0 ? 0x35 : 0x34; break;
        default: return 1;
        }
        func_021EAF18((struct L *)(p + 0x58), 1, msg);
        func_021EAF50((struct L *)(p + 0x58), idx);
        if (flag != 0)
            func_021EAF50((struct L *)(p + 0x58), func_021B904C(((struct Obj00066 *)p)->f0, 1));
        func_021EA614(((struct Obj00066 *)p)->f54, (struct H *)(p + 0x58));
        if (mode == 1) {
            func_02005D90(func_021B86DC(((struct Obj00066 *)p)->f0), 0xFFFF);
            (*state)++;
        } else {
            func_02005E30(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            return 1;
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            (*state)++;
        break;
    case 3:
        if (func_02005E50() == 0) {
            func_02005D28();
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D13A4(BattleSeq_021D123C *s)
{
    u16 *q;

    func_021EEC20(((struct Obj00066 *)s)->f50, (u8 **)&q);
    switch (q[1]) {
    case 0:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 1;
        break;
    case 1:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 0;
        break;
    }
    return q[1];
}







int func_021D13FC(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1410((BattleSeq_021D123C *)p, state, q);
    return 1;
}











int func_021D1410(BattleSeq_021D123C *s, int *state, void *q)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021D13A4(s) == 1) {
            func_021F878C(func_021B86DC(s->battle));
            a = func_021B904C(s->battle, 0);
            b = func_021B904C(s->battle, 1);
            if (a == b) {
                func_021EAF18((struct L *)s->msg, 1, 44);
                func_021EAF50((struct L *)s->msg, a);
            } else {
                func_021EAF18((struct L *)s->msg, 1, 45);
                func_021EAF50((struct L *)s->msg, a);
                func_021EAF50((struct L *)s->msg, b);
            }
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 1;
        } else if (func_021BA1A8(s->battle, 0x100) == 0) {
            a = func_021B8FF4(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 54);
            func_021EAF50((struct L *)s->msg, a);
            func_021EAF50((struct L *)s->msg, a);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 9;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA710(s->msgWin)) {
            a = func_021B904C(s->battle, 0);
            func_021F7F58(func_021BA020(s->battle, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 2;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 0);
            func_021EA6B0(s->msgWin, func_021BA004(s->battle, a), 1);
            *state = 3;
        }
        break;
    case 3:
        if (func_021EA710(s->msgWin)) {
            a = func_021B904C(s->battle, 0);
            if (a != func_021B904C(s->battle, 1)) {
                func_021F7998(0x271);
                *state = 4;
            } else {
                *state = 7;
            }
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 1);
            func_021F7F58(func_021BA020(s->battle, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 5;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 1);
            func_021EA6B0(s->msgWin, func_021BA004(s->battle, a), 1);
            *state = 6;
        }
        break;
    case 6:
        if (func_021EA710(s->msgWin))
            *state = 7;
        break;
    case 7:
        a = func_021B919C(s->battle);
        if (a) {
            b = func_021B8FF4(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 58);
            func_021EAF50((struct L *)s->msg, b);
            func_021EAF50((struct L *)s->msg, a);
            func_021EA614(s->msgWin, (struct H *)s->msg);
        }
        if (func_021B9210(s->battle) == 0)
            *state = 11;
        else
            *state = 8;
        break;
    case 8:
        if (func_021EA710(s->msgWin)) {
            a = func_021B9210(s->battle);
            if (a) {
                b = func_021B8FF4(s->battle);
                func_021EAF18((struct L *)s->msg, 1, 59);
                func_021EAF50((struct L *)s->msg, b);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            *state = 11;
        }
        break;
    case 9:
        if (func_021EA710(s->msgWin)) {
            a = func_021B9244(s->battle);
            if (a) {
                func_021EAF18((struct L *)s->msg, 1, 56);
                func_021EAF50((struct L *)s->msg, s->unk1A6);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            *state = 10;
        }
        break;
    case 10:
        if (func_021EA710(s->msgWin)) {
            func_021EAF18((struct L *)s->msg, 1, 57);
            func_021EAF50((struct L *)s->msg, s->unk1A6);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EA710(s->msgWin))
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
int func_021D1708(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D171C(p, state, q);
    return 1;
}











/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 */
int func_021D171C(u8 *p, int *state, void *a2)
{
    u32 mode;
    int idx;
    switch (*state) {
    case 0:
        if (((Flags_021D1410 *)p)->flag != 0) return 1;
        mode = func_021D13A4((BattleSeq_021D123C *)p);
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        if (mode == 1) func_021F878C(func_021B86DC(((struct Obj00066 *)p)->f0));
        if (mode <= 1) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C((BattleSeq_021D123C *)p, mode, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            if (idx == func_021B904C(((struct Obj00066 *)p)->f0, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            mode = func_021D13A4((BattleSeq_021D123C *)p);
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 1);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C((BattleSeq_021D123C *)p, mode, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}











/*
 * Verified C for it (match.py one --thumb, no --region, EXACT, 20 bytes):
 *   int func_02024450(u16 *p) { return *p != 0xffff; }
 */
void func_021D185C(BattleSeq_021D123C *s, int a, int b)
{
    int idx;
    void *p;
    void *r;
    int v;

    idx = func_021B904C(s->battle, b);
    p = func_021BA02C(s->battle, idx, a);
    if (p != 0 && func_02024450(p) != 0) {
        r = func_0202435C(p, (u16)((*(u16 *)((u8 *)s + 0x19a) & 0x7fff) | 0x8000));
        func_021EA5E4(s->msgWin, r);
        sub_02045808(r);
        return;
    }
    v = func_021BA004(s->battle, idx);
    if (v != 0) {
        func_021EAF18((struct L *)s->msg, 7, (int)0);
        func_021EAF50((struct L *)s->msg, (int)v);
        func_021EAF50((struct L *)s->msg, (int)a);
        func_021EA5F0(s->msgWin, (struct H *)s->msg);
    }
}











int func_021D18EC(BattleSeq_021D123C *s, int *state)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021BA1A8(s->battle, 0x200) == 0) {
            a = func_021B9210(s->battle);
            if (a != 0) {
                b = func_021B8FF4(s->battle);
                func_021EAF18((struct L *)s->msg, 1, 0x3b);
                func_021EAF50((struct L *)s->msg, b);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
        }
        (*state)++;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}











int func_021D1960(BattleSeq_021D123C *s, int *state)
{
    int a;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, 0x36);
        func_021EAF50((struct L *)s->msg, s->unk1A6);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0) {
            a = func_021B9244(s->battle);
            if (a != 0) {
                func_021EAF18((struct L *)s->msg, 1, 0x37);
                func_021EAF50((struct L *)s->msg, s->unk1A6);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(s->msgWin) != 0) {
            func_021EAF18((struct L *)s->msg, 1, 0x39);
            func_021EAF50((struct L *)s->msg, s->unk1A6);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            (*state)++;
        }
        break;
    case 3:
        if (func_021EA710(s->msgWin) != 0)
            (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}











int func_021D1A18(BattleSeq_021D123C *s, int *state)
{
    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, 0xb7);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}









int func_021D1A60(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj01237 *)p)->f54;
    if (q != 0) return func_021D1A74(p, state, q);
    return 1;
}









int func_021D1A74(u8 *p, int *state, void *a2)
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
        size = func_021EEC20(((struct Obj01237 *)p)->f50, &args);
        if (*(u8 * *)&((struct Obj01237 *)p)->fA0 != 0 && p[0x1AE] != 0 && ((Flags_021D1A60 *)p)->flag != 0) {
            if (func_021BB570(*(u8 * *)&((struct Obj01237 *)p)->fA0, p[0x1AE], args, size) != 0) {
                func_021B9184(((struct Obj01237 *)p)->f0);
                ((Flags_021D1A60 *)p)->flag = 0;
            }
            p[0x1AE] = 0;
        }
        buf = *(Buf_021CC768 * *)&((struct Obj01237 *)p)->f134;
        len = size;
        func_02082A90(args, buf->buf, len);
        buf->wpos = len;
        buf->rpos = 0;
        if (p[0x1A9] != 0) {
            p[0x1A9] = 0;
            func_021EA824(((struct Obj01237 *)p)->f54);
        }
        (*state)++;
    case 1:
        buf = *(Buf_021CC768 * *)&((struct Obj01237 *)p)->f134;
        if (buf->rpos == buf->wpos) {
            *state = 4;
            return 1;
        }
        if (func_021D3F4C(p + 0x18) != 0) return 1;
        (*state)++;
    case 2:
        code = func_021CD5E0(*(Buf_021CC768 * *)&((struct Obj01237 *)p)->f134, (s32 *)(p + 0x138));
        ((struct Obj01237 *)p)->f178 = code;
        if (code == 0x5E) return 1;
        for (i = 0; i < 0x5D; i++) {
            if (code == d_021F00DC[i].code) break;
        }
        if (i == 0x5D) {
            *state = 1;
            goto again;
        }
        *(Callback *)&((struct Obj01237 *)p)->f17C = d_021F00DC[i].fn;
        ((struct Obj01237 *)p)->f180 = 0;
        (*state)++;
    case 3:
        if ((*(Callback *)(p + 0x17C))(p, (int *)(p + 0x180), (s32 *)(p + 0x138)) != 0) {
            *state = 1;
            goto again;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}








int func_021D1BD0(BattleSeq_021D123C *s, int *state, int *pp)
{
    int t;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, func_021D1C40(s, pp[0], &t));
        if (t != 0)
            func_021EAF50((struct L *)s->msg, pp[0]);
        func_021EAF50((struct L *)s->msg, pp[1]);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}











int func_021D1C40(BattleSeq_021D123C *s, u8 x, int *out)
{
    u32 v;

    if (x == s->unk1A6) {
        *out = 0;
        if (func_021B8588(s->battle) == 0 && func_021B86C0(s->battle) == 0) {
            v = func_021CDEE8((u8 *)s);
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
    if (func_021B9F70(s->battle, x) != 0)
        return 0x1e;
    return 0x1f;
}











int func_021D1CAC(BattleSeq_021D123C *s, int *state, int *pp)
{
    switch (*state) {
    case 0:
        func_021EA458(s->msgWin, func_021B8E70(s->battle, (u8)pp[0]), (u16)pp[1]);
        (*state)++;
        break;
    case 1:
        if (func_021EA478(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}









static inline void message(u8 *p, int code, u32 value, u32 id)
{
    func_021EAF18((struct L *)(p + 0x58), 1, code);
    func_021EAF50((struct L *)(p + 0x58), value);
    func_021EAF50((struct L *)(p + 0x58), id);
    func_021EA614(((struct Obj21146 *)p)->f54, (struct H *)(p + 0x58));
}









/*
 * lever: append-id and send are written in every message arm; the inline
 * helper includes that tail. Factoring it outside the conditional merges
 * the initialisation call too early and loses 16 bytes.
 */
int func_021D1CF4(u8 *p, int *state, const u32 *params)
{
    u8 a = params[0];
    u8 b = params[1];
    u8 flag = params[3];
    u8 id;
    switch (*state) {
    case 0:
        if (flag != 0) {
            id = func_021D5440(func_021B9920(((struct Obj01691 *)p)->f4, a, b));
            if (func_021B8CE8((int)(((struct Obj01691 *)p)->f0), p[0x1A6], a) == 0) {
                if (p[0x1A6] == a) {
                    func_021EAF18((struct L *)(p + 0x58), 1, func_021D1DF4((BattleSeq_021D123C *)p));
                    func_021EAF50((struct L *)(p + 0x58), id);
                    func_021EA614(((struct Obj01691 *)p)->f54, (struct H *)(p + 0x58));
                } else {
                    message(p, 0x11, a, id);
                }
            } else if (func_021B9F70(((struct Obj01691 *)p)->f0, a) != 0) {
                message(p, 0xE, a, id);
            } else {
                message(p, 0x11, a, id);
            }
        }
        (*state)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj01691 *)p)->f54) != 0) {
            func_021EA488(((struct Obj01691 *)p)->f54, func_021B8BEC(*(u8 * *)&((struct Obj01691 *)p)->f0, a, b), a, b);
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA4C4(((struct Obj01691 *)p)->f54) != 0) {
            func_021CDECC(p);
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1DF4(BattleSeq_021D123C *s)
{
    u8 *m;
    u8 t;
    int v;

    if (func_021B8588(s->battle) == 0) {
        t = func_021B9064(s->battle, s->unk1A6, 0);
        m = func_021B9920(s->unk04, t, 0);
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









int func_021D1E6C(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1EB4(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1F10(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 1));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D1F58(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}








int func_021D1FB4(Seq_021D123C *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA6F4(s->win, a[0], a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}








/*
 * Unlabelled leaf (filed for the blocker of func_021D2030, lane S15).
 */
u32 func_021D2000(Seq_021D2030 *p, u32 k, u8 b)
{
    u8 *r;

    if (k != 0xAE) {
        return func_0201BD28(k, 0x1B);
    }
    r = func_021B98AC((char *const *)p->unk04, b);
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
int func_021D2030(Seq_021D2030 *s, int *state, const u32 *a)
{
    u32 t2;
    u8 v;
    u32 t1;
    u32 t3;
    u32 result;
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        if (func_021B8590((unsigned char *)s->unk00)) {
            v = (u8)a[0];
            t1 = (u8)a[1];
            t2 = (u16)a[2];
            t3 = (u8)a[3];
            result = func_021D2000(s, t2, v);
            func_021EA0A0(s->win, v, t1, t2, result, t3, 0);
            *state = *state + 1;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D20BC(Seq_021D20BC *s, int *state, u32 *a)
{
    u32 t;

    switch (*state) {
    case 0:
        t = (u32)func_021B8DC0((unsigned char *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA354(s->win, t, a[1] != 0);
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










int func_021D210C(Seq_021D210C *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA0F4(s->win, (u16)a[2], t, (u8)a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D215C(Seq_021D215C *s, int *state, u32 *a)
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
            buf[i] = func_021CD644((u8 *)s->unk134);
        }
        func_021EA280(s->win, n, p1, buf, p2);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        func_021EA384(s->win, func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA3A0(s->win)) {
            func_021EA678(s->win, 0x61, (int *)a);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}










int func_021D2234(Seq_021D2234 *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021F81D0(a[1], func_021B8E70((u8 *)s->unk00, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}









int func_021D2278(Seq_021D2030 *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s) == 0) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            func_021EA0A0(s->win, t, t, 1, func_0201BD28(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            if (func_021CD9E0((u8 *)s) == 0) {
                func_020061E4(0x564);
            }
            func_021EA0F4(s->win, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D2320(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA40C(((struct Obj06240 *)p)->f54, func_021B8D8C(((struct Obj06240 *)p)->f0, ((struct Obj06240 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA428(((struct Obj06240 *)p)->f54)) {
            func_021D646C(func_021B9934(((struct Obj06240 *)p)->f4, (u8)(*c)));
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D2374(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA438(((struct Obj07782 *)p)->f54, func_021B8D8C(((struct Obj07782 *)p)->f0, ((struct Obj07782 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA448(((struct Obj07782 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}









int func_021D23B8(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05206 *)p)->f0, func_021B8D8C(((struct Obj05206 *)p)->f0, ((struct Obj05206 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05206 *)p)->f0))
            return 1;
        func_021EA7C8(((struct Obj05206 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05206 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}









int func_021D2424(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05207 *)p)->f0, func_021B8D8C(((struct Obj05207 *)p)->f0, ((struct Obj05207 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05207 *)p)->f0))
            return 1;
        func_021EA7D8(((struct Obj05207 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05207 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}









int func_021D2490(u8 *p, int *st, u32 *c)
{
    u8 id = c[0];

    switch (*st) {
    case 0:
        func_021EF9C0(((struct Obj10019 *)p)->f34, (u8)id, (u16)c[1]);
        if (func_021CD9E0(p))
            return 1;
        if (id < 5)
            func_021F7998(d_021EFFAE[id].b);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(((struct Obj10019 *)p)->f54, d_021EFFAE[id].a, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj10019 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}









int func_021D2510(u8 *p, int *st, u32 *c)
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
        func_021EA678(((struct Obj10021 *)p)->f54, v, 0);
        (*st)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj10021 *)p)->f54)) {
            func_021EF9C8(((struct Obj10021 *)p)->f34);
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D2580(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07783 *)p)->f54, func_021B8D8C(((struct Obj07783 *)p)->f0, ((struct Obj07783 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07783 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}









int func_021D25C4(u8 *p, int *st, u32 *c)
{
    int t = func_021B8D8C(((struct Obj06241 *)p)->f0, ((struct Obj06241 *)p)->f4, (u8)(*c));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj06241 *)p)->f0))
            return 1;
        func_021EA838(((struct Obj06241 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA850(((struct Obj06241 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}









int func_021D2628(u8 *p, int *st, u32 *c)
{
    u8 id = *c;

    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07784 *)p)->f54, func_021B8D8C(((struct Obj07784 *)p)->f0, ((struct Obj07784 *)p)->f4, id));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07784 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}









int func_021D266C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 a = c[0];
        u8 b = c[1];
        u8 d = c[2];
        int x = func_021B8DEC(((struct Obj04364 *)p)->f0, b);
        int y = func_021B8DEC(((struct Obj04364 *)p)->f0, d);
        u32 m = func_021B8E70(((struct Obj04364 *)p)->f0, b);
        u32 n = func_021B8E70(((struct Obj04364 *)p)->f0, d);
        func_021B9C10((u32 *)func_021B9AEC(((struct Obj04364 *)p)->f4, a), x, y);
        func_021EA904(((struct Obj04364 *)p)->f54, a, m, n, x, y);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA950(((struct Obj04364 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}








int func_021D2700(u32 *p, int *st, u32 *c)
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
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA950((void *)p[21])) {
            u8 a = c[2], b = c[3];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 3:
        if (func_021EA950((void *)p[21])) return 1;
        break;
    }
    return 0;
}








/*
 * evidence: Thumb 01 49 02 4b 18 47 c0 46; pools 0x26e and 0x021F7A29. No ARM9/SDK blocker work.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F7E94 is an ov094 Thumb tail stub (pool 0x26E, 0x021F7A29); other overlay, not filed. Integrator: seed label.
 */
int func_021D2814(char *p, int *state, unsigned int *q)
{
    switch (*state) {
    case 0:
        func_021F7E94((u8)func_021B8E70(*(void **)p, (u8)q[0]));
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) return 1;
        break;
    }
    return 0;
}









int func_021D284C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u32 t = func_021B8E70(((struct Obj21158 *)p)->f0, (u8)(*c));
        if (func_021CD9E0(p))
            func_021F88BC(1);
        func_021F7EA4(t);
        (*st)++;
        break;
    }
    case 1:
        if (!func_021F7EB4()) {
            if (func_021CD9E0(p))
                func_021F88BC(0);
            return 1;
        }
        break;
    }
    return 0;
}









int func_021D28AC(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 *a = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[0]);
        u8 *b = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[1]);
        int d = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[0]);
        int e = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[1]);
        func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b);
        func_021EA8B4(((struct Obj03693 *)p)->f54, d, e);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA8D4(((struct Obj03693 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}








int func_021D2930(u32 *a, int *b, u32 *c)
{
    int t;

    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) == 0) {
            t = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
            func_021EA1B8((struct S *)a[0x15], (u16)c[2], t, func_021D7AD4(c[1]));
            (*b)++;
            break;
        }
        return 1;
    case 1:
        if (func_021EA1F0((struct S *)a[0x15]) != 0) {
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







int func_021D299C(char *p, int *state)
{
    switch (*state) {
    case 0:
        func_021EA8E4(((struct Obj13398 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EA8F4(((struct Obj13398 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}







int func_021D29CC(u32 *a, int b, u32 *c)
{
    void *m;
    u32 i;
    int k;
    u32 v;

    m = func_021D5844(func_021B9934((char *)a[1], (u8)c[0]));
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
int func_021D2A20(u8 *p, int *state, u32 *args)
{
    void *obj;
    int id;
    int index;
    int enabled;
    u32 remaining;
    id = (u8)args[0];
    obj = func_021B9934(*(char * *)&((struct Obj00268 *)p)->f4, id);
    index = func_021B8DC0(((struct Obj00268 *)p)->f0, ((struct Obj00268 *)p)->f4, id);
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
            func_021EA3B8(((struct Obj00268 *)p)->f54, index, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA3D4(((struct Obj00268 *)p)->f54)) *state = 6;
        break;
    case 6:
        func_021EAF18((struct L *)(p + 0x58), 1, 0x3c);
        func_021EAF50((struct L *)(p + 0x58), (int)id);
        func_021EAF50((struct L *)(p + 0x58), (int)d_021F3B64.s.result[0]);
        func_021EA614(((struct Obj00268 *)p)->f54, (struct H *)(p + 0x58));
        *state = 7;
        break;
    case 7:
        if (func_021EA720(((struct Obj00268 *)p)->f54)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xffff);
        }
        if (func_021EA710(((struct Obj00268 *)p)->f54) && !func_02005F38()) {
            func_02005E9C();
            func_02005DE4(0);
            d_021F3B64.s.counter = 0;
            *state = 8;
        }
        break;
    case 8:
        d_021F3B64.s.counter++;
        if ((func_020362DC() & 3) || func_02035C60() || d_021F3B64.s.counter > 80) {
            d_021F3B64.s.counter = 0;
            func_021BA238(((struct Obj00268 *)p)->f0, obj);
            func_021EADA4(*(u8 * *)&((struct Obj00268 *)p)->f54, (int)obj, (struct T *)d_021F3B64.s.result);
            *state = 9;
        }
        break;
    case 9:
        if (func_021EADB4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADC4(((struct Obj00268 *)p)->f54);
            *state = 10;
        }
        break;
    case 10:
        if (func_021EADD4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADE4(((struct Obj00268 *)p)->f54);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EADF4(((struct Obj00268 *)p)->f54)) {
            d_021F3B64.s.counter = 0;
            *state = 12;
        }
        break;
    case 12:
        if (func_021D2CA8((LearnSeq_021D2C7C *)p, &d_021F3B64.s.counter, obj)) *state = 1;
        break;
    case 13:
        func_021B9358(((struct Obj00268 *)p)->f0, id);
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
        if (func_02006254(0x56b) != 0) return 1;
        break;
    }
    return 0;
}






int func_021D2CA8(LearnSeq_021D2C7C *s, int *state, void *mon)
{
    int idx = func_021D5440(mon);

    switch (*state) {
    case 0:
        g_021F3B64.iter = 0;
        g_021F3B64.move = 0;
        *state = 1;
    case 1:
        g_021F3B64.move = func_02018328(func_021D5844(mon), &g_021F3B64.iter, s->level);
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
        void *p = func_021B9934(s->party, idx);
        func_021D5844(p);
        func_021D6BFC(p);
        func_021EAF18((struct L *)(&s->msg), 5, 3);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 3;
    }
    case 3:
        if (func_021EA720(s->msgWin)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xFFFF);
        }
        if (func_021EA710(s->msgWin))
            *state = 4;
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
            *state = 1;
        }
        break;
    case 5:
        func_021EAF18((struct L *)(&s->msg), 5, 4);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 6;
    case 6:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 2);
            func_021EAF18((struct L *)(&no), 6, 3);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 7;
        break;
    case 7: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAC64(s->msgWin, func_021B9CBC((u8 *)func_021B9AF8(s->party, s->side), idx), g_021F3B64.move);
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
        if (func_021EAC80(s->msgWin, &slot) == 0)
            break;
        if (slot == 4) {
            *state = 5;
            break;
        }
        pp = func_021D5844(func_021B9934(s->party, idx));
        old = func_02017E1C(pp, slot + 54, 0);
        func_020181F4(pp, g_021F3B64.move, slot);
        func_021EAF18((struct L *)(&s->msg), 5, 5);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), old);
        func_021EA638(s->msgWin, (struct H *)(&s->msg), (int)((void (*)(void))func_021D2C7C));
        *state = 9;
        break;
    }
    case 9:
        if (func_021EA710(s->msgWin))
            *state = 2;
        break;
    case 10:
        func_021EAF18((struct L *)(&s->msg), 5, 7);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 11;
        break;
    case 11:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 4);
            func_021EAF50((struct L *)(&yes), g_021F3B64.move);
            func_021EAF18((struct L *)(&no), 6, 5);
            func_021EAF50((struct L *)(&no), g_021F3B64.move);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 12;
        break;
    case 12: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAF18((struct L *)(&s->msg), 5, 8);
                func_021EAF50((struct L *)(&s->msg), idx);
                func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
                func_021EA614(s->msgWin, (struct H *)(&s->msg));
                *state = 13;
            } else {
                *state = 5;
            }
        }
        break;
    }
    case 13:
        if (func_021EA710(s->msgWin))
            *state = 1;
        break;
    }
    return 0;
}





/*
 * lever: const on the read-only descriptor schedules c[1] before the
 * stack-argument store in the first arm.
 */
int func_021D2FD8(u32 *a, int *b, const u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7CFC(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[5], (u8)c[1], c[2], c[4]);
        (*b)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            if (c[2]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x41);
                func_021EAF50((struct L *)((u8 *)a + 0x58), func_021D5440(p));
                func_021F883C(0x518);
            } else {
                int msg;
                if (c[1] < 4) msg = d_021EFF80[c[1]];
                else msg = 0x3d;
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, msg);
            }
            func_021EA614((char *)a[21], (struct H *)((u8 *)a + 0x58));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[21])) {
            if (c[2]) {
                func_021BA2D4((u32)((void *)a[0]), (u32 *)func_021B98AC((char *const *)a[1], (u8)c[0]));
                (*b)++;
            } else return 1;
        }
        break;
    case 3:
        if (!func_02005F38()) {
            func_021F7C0C();
            func_02005D90(0x47c, 0xffff);
            func_021B92A0((u8 *)a[0]);
            if (c[3]) {
                u8 *p = func_021B98AC((char *const *)a[1], (u8)c[0]);
                func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x42);
                func_021EAF50((struct L *)((u8 *)a + 0x58), func_021D5440(p));
                func_021EA614((char *)a[21], (struct H *)((u8 *)a + 0x58));
                (*b)++;
            } else return 1;
        }
        break;
    case 4:
        if (func_021EA710((u32 *)a[21])) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}






int func_021D3138(u32 *a, int *b, u32 *c)
{
    switch (*b) {
    case 0:
        func_021F7D44(func_021B8E70((u8 *)a[0], (u8)c[0]), (u16)c[1]);
        (*b)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EAF18((struct L *)((u8 *)a + 0x58), 1, 0x43);
            func_021EA614((char *)a[0x15], (struct H *)((u8 *)a + 0x58));
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}






static inline u16 sel(u32 u, u32 k)
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
int func_021D31A0(u32 *a, int *b, u32 *c)
{
    u8 v;
    int u;
    u8 k;
    char *p;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        v = (u8)c[1];
        p = func_021B9AEC((char *)a[1], u);
        func_021B9C50((u8 **)p, v, 0, 0);
        func_021EAA6C(a[0x15], u, v);
        (*b)++;
        break;
    case 1:
        if (func_021EAAD8(a[0x15]) != 0) {
            u = (u8)c[1];
            if (u == 1) {
                return 1;
            }
            k = func_021B9F70((u8 *)a[0], (u8)c[0]);
            func_021EA678((char *)a[0x15], sel(u, k), (int *)c);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA710((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}






int func_021D324C(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;

    u = (u8)c[0];
    s = func_021B8D8C((void *)a[0], (void *)a[1], u);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) != 0) {
            func_021D66D0((struct QJ *)func_021B9934((char *)a[1], u), c[1]);
            return 1;
        }
        func_021EA768((u32 *)a[0x15], s, 0);
        (*b)++;
        break;
    case 1:
        if (func_021EA778((u32 *)a[0x15], s) != 0) {
            func_021D66D0((struct QJ *)func_021B9934((char *)a[1], u), c[1]);
            func_021EA7A8((u32 *)a[0x15], s);
            (*b)++;
        }
        break;
    case 2:
        if (func_021EA7B8((u32 *)a[0x15], s) != 0) {
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
int func_021D32E0(u32 *a, int *b, u32 *c)
{
    u32 u, v;
    u16 x, y;
    int s, t;
    u8 *p, *q;
    u = (u8)c[0];
    v = (u8)c[1];
    x = (u16)c[2];
    y = (u16)c[3];
    s = func_021B8D8C((void *)a[0], (void *)a[1], u);
    t = func_021B8D8C((void *)a[0], (void *)a[1], v);
    p = func_021B9934((char *)a[1], u);
    q = func_021B9934((char *)a[1], v);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        if (func_021B9A24(u, v)) {
            func_021D66D0((struct QJ *)p, x);
            func_021D66D0((struct QJ *)q, y);
            return 1;
        }
        func_021EA768((u32 *)((int)a[21]), s, 0);
        d_021F3B64.w[1] = 8;
        (*b)++;
        break;
    case 1:
        func_021EA778((u32 *)a[21], s);
        if (d_021F3B64.w[1]) d_021F3B64.w[1]--;
        else {
            func_021EA768((u32 *)a[21], t, 0);
            (*b)++;
        }
        break;
    case 2: {
        u8 r, z;
        r = func_021EA778((u32 *)a[21], s);
        z = func_021EA778((u32 *)a[21], t);
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
            func_021EA7A8((u32 *)a[21], s);
            (*b)++;
        }
        break;
    case 5:
        if (func_021EA7B8((u32 *)a[21], s)) {
            func_021EA7A8((u32 *)a[21], t);
            (*b)++;
        }
        break;
    case 6:
        if (func_021EA7B8((u32 *)a[21], t)) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}






int func_021D344C(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;
    u8 *m;
    int f;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        s = func_021B8D8C((void *)a[0], (void *)a[1], u);
        m = func_021B9934((char *)a[1], u);
        f = func_021CD9E0((u8 *)a);
        func_021D6C2C((struct Unk021D6C2C *)m);
        func_021EA868((u32 *)a[0x15], s, f);
        (*b)++;
        break;
    case 1:
        if (func_021EA878((u32 *)a[0x15]) != 0) {
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
int func_021D34B0(char *p, int *state, unsigned int *q)
{
    if (*state == 0) {
        if (func_021CD9E0((u8 *)p) != 0) return 1;
        func_021F7998(q[0]);
        (*state)++;
    } else {
        if (func_021F7EB4() == 0) return 1;
    }
    return 0;
}






int func_021D34E8(u32 *a, int *b, u32 *c)
{
    u8 k;

    k = func_021B8E70((u8 *)a[0], (u8)c[0]);
    if (*b == 0) {
        if (func_021CD9E0((u8 *)a) != 0) {
            return 1;
        }
        if (func_021B8590((unsigned char *)a[0]) == 0) {
            if (func_0689C9D4((u16)c[1]) != 0) {
                return 1;
            }
        }
        func_021EA3B8((char *)a[0x15], k, (u16)c[1]);
        (*b)++;
    } else {
        if (func_021EA3D4((void *)a[0x15]) != 0) {
            return 1;
        }
    }
    return 0;
}
