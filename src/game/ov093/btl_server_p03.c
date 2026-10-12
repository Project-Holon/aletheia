/*
 * file:     btl_server_p03.c
 * unit:     yes
 * function: func_021C2E4C, func_021C2E64, func_021C2F70, func_021C3008, func_021C312C, func_021C3184, func_021C3274, func_021C334C, func_021C3370, func_021C3394, func_021C33E8, func_021C3438, func_021C36A0, func_021C36E8, func_021C3720, func_021C376C, func_021C3810, func_021C39CC, func_021C39F4, func_021C3A4C, func_021C3AA8, func_021C3B68, func_021C3B8C, func_021C3BB8, func_021C3BE0, func_021C3C10, func_021C3C60, func_021C3CCC, func_021C3D08, func_021C3E0C, func_021C3FDC, func_021C4034, func_021C4104, func_021C41C0, func_021C4218, func_021C4268, func_021C4304, func_021C43F0, func_021C446C, func_021C4614, func_021C4744, func_021C4838, func_021C4910, func_021C493C, func_021C4A64, func_021C4B3C, func_021C4B8C, func_021C4B9C, func_021C4BAC, func_021C4C24, func_021C4C40, func_021C4C50, func_021C4D1C, func_021C4E38, func_021C4EA4, func_021C4F64, func_021C5098, func_021C5108, func_021C51D0, func_021C5200, func_021C5308, func_021C5350, func_021C5418, func_021C5474, func_021C5480, func_021C54BC, func_021C54C8, func_021C54FC, func_021C5540, func_021C557C, func_021C5604, func_021C5620, func_021C56A8, func_021C5718, func_021C572C, func_021C5750, func_021C5774, func_021C5798, func_021C5840, func_021C59C4, func_021C5A1C, func_021C5A34, func_021C5A4C, func_021C5A8C, func_021C5B74, func_021C5BE4, func_021C5C1C, func_021C5C74, func_021C5D88, func_021C5DAC, func_021C5E48, func_021C5EFC, func_021C5F98, func_021C604C, func_021C6080, func_021C60D4, func_021C60EC, func_021C6110, func_021C6134, func_021C6158, func_021C6190, func_021C62D8, func_021C6350, func_021C6394, func_021C63D0, func_021C6458, func_021C64B4, func_021C6564, func_021C65A8, func_021C6668, func_021C66AC, func_021C6720, func_021C676C, func_021C6848, func_021C6878, func_021C68A8, func_021C6948, func_021C69B8, func_021C6A04, func_021C6A9C, func_021C6B5C, func_021C6BB8, func_021C6BF8, func_021C6CAC, func_021C6DD0, func_021C6E00, func_021C6E3C, func_021C6F0C, func_021C6F34, func_021C6FC0, func_021C7008, func_021C7038, func_021C70E4, func_021C7194, func_021C71E0, func_021C728C, func_021C7330, func_021C7374, func_021C7474, func_021C75EC, func_021C7664, func_021C76F4, func_021C7780, func_021C77B0, func_021C7820, func_021C785C, func_021C78A8, func_021C78F4, func_021C7998, func_021C79E0, func_021C7A54, func_021C7AA0, func_021C7AD0, func_021C7B0C, func_021C7B3C, func_021C7B7C, func_021C7BA8, func_021C7BF8, func_021C7C18, func_021C7C24, func_021C7CBC, func_021C7CC8, func_021C7CD4, func_021C7CDC, func_021C7CE8, func_021C7CF4, func_021C7D00, func_021C7D34, func_021C7D44, func_021C7D54, func_021C7DAC, func_021C7E14, func_021C7EC4, func_021C7ED8, func_021C7EEC, func_021C7F04, func_021C7F24, func_021C7F4C, func_021C7F68, func_021C7FCC, func_021C7FE0, func_021C8010, func_021C8020, func_021C8030, func_021C804C, func_021C80AC, func_021C8114, func_021C8120, func_021C812C, func_021C8130, func_021C8138, func_021C8140, func_021C814C, func_021C815C, func_021C8168, func_021C8174, func_021C8180, func_021C818C, func_021C81C8, func_021C81D0, func_021C8234, func_021C824C, func_021C8288, func_021C8290, func_021C82B8, func_021C82C4, func_021C82D0, func_021C82F4, func_021C8300, func_021C830C, func_021C831C, func_021C8338, func_021C8348, func_021C8374, func_021C83A0, func_021C83CC, func_021C83D4, func_021C83DC, func_021C83E8, func_021C8408, func_021C8434, func_021C846C, func_021C8494, func_021C84AC, func_021C84D0, func_021C84D8, func_021C84E0, func_021C84E8, func_021C84F4, func_021C8534, func_021C8588, func_021C859C, func_021C85B8, func_021C85D4, func_021C8810, func_021C8828, func_021C8838, func_021C8860, func_021C888C, func_021C88A4, func_021C88B4, func_021C88C8, func_021C88E4, func_021C8910, func_021C8918, func_021C8C6C, func_021C8CBC, func_021C8D0C, func_021C8D2C, func_021C8DE4, func_021C8E58, func_021C8F24, func_021C8FA4, func_021C9010, func_021C9068, func_021C9178, func_021C9250, func_021C9394, func_021C9448, func_021C947C, func_021C94C8, func_021C95D0, func_021C962C, func_021C96D4, func_021C9728, func_021C9750, func_021C9778, func_021C97A4, func_021C97D0, func_021C9828, func_021C9898, func_021C98C4, func_021C98E4, func_021C99A0, func_021C9A24, func_021C9A60, func_021C9BB8, func_021C9CC0, func_021C9DCC, func_021C9DE8, func_021C9E3C, func_021C9ECC, func_021C9F0C, func_021C9F4C, func_021C9F6C, func_021CA128, func_021CA158, func_021CA1D0, func_021CA248, func_021CA270, func_021CA2E8, func_021CA318, func_021CA370, func_021CA394, func_021CA3AC, func_021CA3D0, func_021CA47C, func_021CA570, func_021CA5CC, func_021CA6C4, func_021CA6FC, func_021CA738, func_021CA748, func_021CA7C4, func_021CA7D4, func_021CA7F4, func_021CA8F8, func_021CAA24
 * address:  0x021C2E4C
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
 *   func_0201C020 0x0201C020 thumb
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   sub_0201C0BC  0x0201C0BC  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   sub_0201BD28  0x0201BD28  thumb
 *   sub_0201BF58  0x0201BF58  thumb
 *   func_021D7C70  0x021D7C70  thumb  ov093
 *   func_021C3244  0x021C3244  thumb  ov093
 *   func_021C3254  0x021C3254  thumb  ov093
 *   func_021C3264  0x021C3264  thumb  ov093
 *   func_021C25A4  0x021C25A4  thumb  ov093
 *   func_021C331C  0x021C331C  thumb  ov093
 *   func_021C332C  0x021C332C  thumb  ov093
 *   func_021C333C  0x021C333C  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C3428  0x021C3428  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C3660 0x021C3660 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021BF324 0x021BF324 thumb ov093
 *   func_021BFA00 0x021BFA00 thumb ov093
 *   func_021CC8B8 0x021CC8B8 thumb ov093
 *   func_021C3670 0x021C3670 thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021C3680 0x021C3680 thumb ov093
 *   func_021C1678 0x021C1678 thumb ov093
 *   func_021C3690 0x021C3690 thumb ov093
 *   func_021C1828 0x021C1828 thumb ov093
 *   func_021C1C88 0x021C1C88 thumb ov093
 *   func_021D5FB8  0x021D5FB8  thumb  ov093
 *   func_021C16F8 0x021C16F8 thumb ov093
 *   func_021D6D90  0x021D6D90  thumb  ov093
 *   func_021C37E0  0x021C37E0  thumb  ov093
 *   func_021C37F0  0x021C37F0  thumb  ov093
 *   func_021C3800  0x021C3800  thumb  ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021BDD7C 0x021BDD7C thumb ov093
 *   func_021BD9D4 0x021BD9D4 thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021D8244 0x021D8244 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B99C0  0x021B99C0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021C3A98  0x021C3A98  thumb  ov093
 *   func_0201C184  0x0201C184  thumb
 *   func_021EF884 0x021EF884 thumb ov093
 *   func_021EF894 0x021EF894 thumb ov093
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   func_021EF8C8  0x021EF8C8  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021EF8F8  0x021EF8F8  thumb  ov093
 *   func_021C3DFC 0x021C3DFC thumb ov093
 *   func_021C3FAC 0x021C3FAC thumb ov093
 *   func_021C3FBC 0x021C3FBC thumb ov093
 *   func_021C3FCC 0x021C3FCC thumb ov093
 *   func_021D66D0 0x021D66D0 thumb ov093
 *   func_021D8564 0x021D8564 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C40F4  0x021C40F4  thumb  ov093
 *   func_021D6D5C  0x021D6D5C  thumb  ov093
 *   func_021D6D9C  0x021D6D9C  thumb  ov093
 *   func_021C1DCC  0x021C1DCC  thumb  ov093
 *   func_021C1880  0x021C1880  thumb  ov093
 *   func_021C4208  0x021C4208  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021C43C0  0x021C43C0  thumb  ov093
 *   func_021C43D0  0x021C43D0  thumb  ov093
 *   func_021C43E0  0x021C43E0  thumb  ov093
 *   func_021C443C  0x021C443C  thumb  ov093
 *   func_021C444C  0x021C444C  thumb  ov093
 *   func_021C445C  0x021C445C  thumb  ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021C45E4 0x021C45E4 thumb ov093
 *   func_021C45F4 0x021C45F4 thumb ov093
 *   func_021C4604 0x021C4604 thumb ov093
 *   func_021D6408 0x021D6408 thumb ov093
 *   func_021D6E88 0x021D6E88 thumb ov093
 *   func_021D701C 0x021D701C thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021B9CE8 0x021B9CE8 thumb ov093
 *   func_021C4724 0x021C4724 thumb ov093
 *   func_021C4734 0x021C4734 thumb ov093
 *   func_021B8DEC 0x021B8DEC thumb ov093
 *   func_021B99F0 0x021B99F0 thumb ov093
 *   func_021BD43C 0x021BD43C thumb ov093
 *   func_021BD4E4 0x021BD4E4 thumb ov093
 *   func_021B8630 0x021B8630 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_0202E7E0 0x0202E7E0 thumb
 *   func_0202E7E4 0x0202E7E4 thumb
 *   func_021C48E0  0x021C48E0  thumb  ov093
 *   func_021C48F0  0x021C48F0  thumb  ov093
 *   func_021C4900  0x021C4900  thumb  ov093
 *   func_021C4A24 0x021C4A24 thumb ov093
 *   func_021C4A34 0x021C4A34 thumb ov093
 *   func_021C4A44 0x021C4A44 thumb ov093
 *   func_021C4A54 0x021C4A54 thumb ov093
 *   func_021D6064 0x021D6064 thumb ov093
 *   func_021D806C 0x021D806C thumb ov093
 *   func_021C20BC 0x021C20BC thumb ov093
 *   func_021C4B2C 0x021C4B2C thumb ov093
 *   func_021C20D0 0x021C20D0 thumb ov093
 *   func_06898D54 0x06898D54 thumb ov095
 *   func_021EF934 0x021EF934 thumb ov093
 *   func_021C4C40 0x021C4C40 thumb ov093
 *   func_021C4CEC  0x021C4CEC  thumb  ov093
 *   func_021C4CFC  0x021C4CFC  thumb  ov093
 *   func_021C4D0C  0x021C4D0C  thumb  ov093
 *   func_021EF8B8 0x021EF8B8 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021C4E08 0x021C4E08 thumb ov093
 *   func_021C4E18 0x021C4E18 thumb ov093
 *   func_021C4E28 0x021C4E28 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021D7BD4 0x021D7BD4 thumb ov093
 *   func_021C5078 0x021C5078 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021D646C 0x021D646C thumb ov093
 *   func_021B92B0 0x021B92B0 thumb ov093
 *   func_021C5088 0x021C5088 thumb ov093
 *   func_021B902C 0x021B902C thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021B8640  0x021B8640  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021C50F8  0x021C50F8  thumb  ov093
 *   func_021BFF60 0x021BFF60 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021DCF24 0x021DCF24 thumb ov093
 *   func_021D8538 0x021D8538 thumb ov093
 *   func_021DCFA4 0x021DCFA4 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   func_021BD338 0x021BD338 thumb ov093
 *   func_021D6264 0x021D6264 thumb ov093
 *   func_021EF90C 0x021EF90C thumb ov093
 *   func_021B85EC 0x021B85EC thumb ov093
 *   func_021C52C8 0x021C52C8 thumb ov093
 *   func_021C52D8 0x021C52D8 thumb ov093
 *   func_021C52E8 0x021C52E8 thumb ov093
 *   func_021BC310 0x021BC310 thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021C52F8 0x021C52F8 thumb ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021CB2D4  0x021CB2D4  thumb  ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021BA1CC 0x021BA1CC thumb ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 *   func_021C54AC  0x021C54AC  thumb  ov093
 *   func_021D62D8  0x021D62D8  thumb  ov093
 *   func_021D61F0  0x021D61F0  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021C5698  0x021C5698  thumb  ov093
 *   func_021D6238  0x021D6238  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7E10  0x021D7E10  thumb  ov093
 *   func_021CD63C  0x021CD63C  thumb  ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021C5BD4  0x021C5BD4  thumb  ov093
 *   func_021D6034  0x021D6034  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 *   func_021D56A0  0x021D56A0  thumb  ov093
 *   func_021D5674  0x021D5674  thumb  ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D6008 0x021D6008 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D7A44  0x021D7A44  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   sub_0201C1C8   0x0201C1C8  thumb
 *   sub_0201C1E8   0x0201C1E8  thumb
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021C6648  0x021C6648  thumb  ov093
 *   func_021C6658  0x021C6658  thumb  ov093
 *   func_021C6710  0x021C6710  thumb  ov093
 *   func_021C6828  0x021C6828  thumb  ov093
 *   func_021C6838  0x021C6838  thumb  ov093
 *   func_021C6928  0x021C6928  thumb  ov093
 *   func_021C6938  0x021C6938  thumb  ov093
 *   func_021D5C08  0x021D5C08  thumb  ov093
 *   sub_0201C1F4  0x0201C1F4  thumb
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   sub_0201C284  0x0201C284  thumb
 *   func_021D5F14  0x021D5F14  thumb  ov093
 *   func_021D7930  0x021D7930  thumb  ov093
 *   func_0201BD28 0x0201BD28 thumb
 *   func_0201C1BC 0x0201C1BC thumb
 *   func_021D7B3C 0x021D7B3C thumb ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_021E8DA8 0x021E8DA8 thumb ov093
 *   func_021D79E8 0x021D79E8 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021C6FB0  0x021C6FB0  thumb  ov093
 *   func_021C70D4  0x021C70D4  thumb  ov093
 *   func_021D794C  0x021D794C  thumb  ov093
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021D7BA4  0x021D7BA4  thumb  ov093
 *   func_0201C1D8  0x0201C1D8  thumb
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021D5AD8 0x021D5AD8 thumb ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7B2C  0x021D7B2C  thumb  ov093
 *   func_02082BCC  0x02082BCC  arm
 *   func_021C7D24 0x021C7D24 thumb ov093
 *   func_021B86A0 0x021B86A0 thumb ov093
 *   func_0689D5F4 0x0689D5F4 thumb ov095
 *   func_0689D5FC 0x0689D5FC thumb ov095
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021C1E74  0x021C1E74  thumb  ov093
 *   func_021B997C 0x021B997C thumb ov093
 *   func_021B9BC4 0x021B9BC4 thumb ov093
 *   func_021B8778   0x021B8778  thumb  ov093
 *   func_021B98A4   0x021B98A4  thumb  ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9010 0x021B9010 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_0689D588 0x0689D588 thumb ov095
 *   func_021B8714  0x021B8714  thumb  ov093
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0201B718 0x0201B718 thumb
 *   func_021BC948   0x021BC948  thumb ov093
 *   func_06898CF4  0x06898CF4  thumb  ov095
 *   func_021B9AE0 0x021B9AE0 thumb ov093
 *   func_021C82E4 0x021C82E4 thumb ov093
 *   func_068982AC  0x068982AC  thumb
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021C2AF0 0x021C2AF0 thumb ov093
 *   func_021D67E8 0x021D67E8 thumb ov093
 *   func_021BB908 0x021BB908 thumb ov093
 *   func_021BB914 0x021BB914 thumb ov093
 *   func_021C845C 0x021C845C thumb ov093
 *   func_021BE52C 0x021BE52C thumb ov093
 *   func_021BFEAC 0x021BFEAC thumb ov093
 *   func_021C2128 0x021C2128 thumb ov093
 *   func_021BDBB8   0x021BDBB8  thumb ov093
 *   func_021CC668   0x021CC668  thumb ov093
 *   func_021C8578  0x021C8578  thumb  ov093
 *   func_021C87A0 0x021C87A0 thumb ov093
 *   func_021C87B0 0x021C87B0 thumb ov093
 *   func_021C87C0 0x021C87C0 thumb ov093
 *   func_021C87D0 0x021C87D0 thumb ov093
 *   func_021C87E0 0x021C87E0 thumb ov093
 *   func_021C87F0 0x021C87F0 thumb ov093
 *   func_021C8800 0x021C8800 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021CC9AC   0x021CC9AC  thumb  ov093
 *   func_021CCA74   0x021CCA74  thumb  ov093
 *   func_021CC96C  0x021CC96C  thumb  ov093
 *   func_021CC9A4  0x021CC9A4  thumb  ov093
 *   func_021B9940   0x021B9940  thumb ov093
 *   func_021CC960   0x021CC960  thumb ov093
 *   func_021CC974   0x021CC974  thumb ov093
 *   func_021CC99C   0x021CC99C  thumb ov093
 *   func_021C8CAC  0x021C8CAC  thumb  ov093
 *   func_021C8CFC  0x021C8CFC  thumb  ov093
 *   func_021C8E48  0x021C8E48  thumb  ov093
 *   func_021C1E14  0x021C1E14  thumb  ov093
 *   func_021C8F14  0x021C8F14  thumb  ov093
 *   func_021C8F94  0x021C8F94  thumb  ov093
 *   func_021D55D8  0x021D55D8  thumb  ov093
 *   func_021C0898  0x021C0898  thumb  ov093
 *   func_021C9168 0x021C9168 thumb ov093
 *   func_021C9240 0x021C9240 thumb ov093
 *   func_021C27A0 0x021C27A0 thumb ov093
 *   func_021C2910 0x021C2910 thumb ov093
 *   func_021C9374 0x021C9374 thumb ov093
 *   func_021C9384 0x021C9384 thumb ov093
 *   func_021C9438  0x021C9438  thumb  ov093
 *   func_021D5EA8  0x021D5EA8  thumb  ov093
 *   func_021D5EFC 0x021D5EFC thumb ov093
 *   func_021D5F08  0x021D5F08  thumb  ov093
 *   func_021C95C0 0x021C95C0 thumb ov093
 *   func_021D5970 0x021D5970 thumb ov093
 *   func_021C961C  0x021C961C  thumb  ov093
 *   func_021C2314  0x021C2314  thumb  ov093
 *   func_021C96B4  0x021C96B4  thumb  ov093
 *   func_021C96C4  0x021C96C4  thumb  ov093
 *   func_021D66B0  0x021D66B0  thumb  ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_021C9818  0x021C9818  thumb  ov093
 *   func_021C9888  0x021C9888  thumb  ov093
 *   func_021EF8E8 0x021EF8E8 thumb ov093
 *   func_021C9A50 0x021C9A50 thumb ov093
 *   func_021C9BA8 0x021C9BA8 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021C2250 0x021C2250 thumb ov093
 *   func_021D6738 0x021D6738 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021DCF78  0x021DCF78  thumb  ov093
 *   func_021DCF9C  0x021DCF9C  thumb  ov093
 *   func_021CD4FC  0x021CD4FC  thumb  ov093
 *   func_021D5734  0x021D5734  thumb  ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021CA0B8 0x021CA0B8 thumb ov093
 *   func_021CA0C8 0x021CA0C8 thumb ov093
 *   func_021CA0D8 0x021CA0D8 thumb ov093
 *   func_021CA0E8 0x021CA0E8 thumb ov093
 *   func_021CA0F8 0x021CA0F8 thumb ov093
 *   func_021CA108 0x021CA108 thumb ov093
 *   func_021BF83C 0x021BF83C thumb ov093
 *   func_021BF3D8 0x021BF3D8 thumb ov093
 *   func_021BF4AC 0x021BF4AC thumb ov093
 *   func_021BF8D4 0x021BF8D4 thumb ov093
 *   func_021CA118 0x021CA118 thumb ov093
 *   func_021BD200 0x021BD200 thumb ov093
 *   func_021C091C 0x021C091C thumb ov093
 *   func_021BD60C 0x021BD60C thumb ov093
 *   func_021BDD00  0x021BDD00  thumb  ov093
 *   func_021BB930  0x021BB930  thumb  ov093
 *   func_021C2CA8  0x021C2CA8  thumb  ov093
 *   func_021D65C8  0x021D65C8  thumb  ov093
 *   func_021CA238  0x021CA238  thumb  ov093
 *   func_021C1D60 0x021C1D60 thumb ov093
 *   func_021D67D8 0x021D67D8 thumb ov093
 *   func_021BD148 0x021BD148 thumb ov093
 *   func_021BD170 0x021BD170 thumb ov093
 *   func_021BD1B0 0x021BD1B0 thumb ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021D6C50 0x021D6C50 thumb ov093
 *   func_021CA5BC  0x021CA5BC  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021D66D8  0x021D66D8  thumb  ov093
 *   func_021CB214 0x021CB214 thumb ov093
 *   func_021CA8C8 0x021CA8C8 thumb ov093
 *   func_021CAA58 0x021CAA58 thumb ov093
 *   func_021CACF4 0x021CACF4 thumb ov093
 *   func_021CA8D8 0x021CA8D8 thumb ov093
 *   func_021CA8E8 0x021CA8E8 thumb ov093
 *   func_021CAFD8 0x021CAFD8 thumb ov093
 *   func_021CB174 0x021CB174 thumb ov093
 *   func_021CA9D4 0x021CA9D4 thumb ov093
 *   func_021CA9E4 0x021CA9E4 thumb ov093
 *   func_021CA9F4 0x021CA9F4 thumb ov093
 *   func_021CAA04 0x021CAA04 thumb ov093
 *   func_021CAA14 0x021CAA14 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
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
#include "btl_server_types.h"
#include "../../matched/include/Obj05193.h"
#include "../../matched/include/Obj21097.h"
#include "../../matched/include/Obj06227.h"
#include "../../matched/include/Obj18306.h"
#include "../../matched/include/Obj07752.h"
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

struct Unk021D62A8;
struct Msg;
struct B;
struct Q1;
struct S_021C2E4C;
struct S2;
struct QJ;
struct UtilWork;
struct S_p12;
struct UtilSlots;
struct Entry_p11;
struct Obj;
struct Result;
struct Unk021D5FA4;
struct Arr;
struct R4;
struct Out64B4;
struct Unk021B8CB0;
struct QF;
struct Pack;
struct Rec;
struct Q9;
struct Cmd;
struct Q;
struct Q10;
struct S_p14;
struct QI;
struct Unk021BD1E0;
struct Work;
struct Unk021D6C50;
struct Unk021D6C2C;
struct R5;
typedef struct { u32 x; } W_021C2E4C;

typedef struct { u8 pad[5]; u8 f : 1; } BF;

struct Flags_021C2E4C { u8 pad[5]; u8 a:1; u8 rest:7; };

typedef struct { u8 pad[5]; u8 f : 1; } Q_p10;

enum Mode { M0, M1, M2, Mneg = -1 };

struct Pair { u8 count, id; };

typedef struct { u8 pad[5]; u8 a:1,b:1,c:6; } Flag_td;

typedef struct { u8 a:4,b:1,c:3; } ByteFlag;

typedef unsigned long long u64;

struct Flags_021C5108 { u8 a:1; u8 b:1; u8 rest:6; };

struct Entry_p11 { u32 value; u8 flag; u8 a, b, c, d, e, f, pad; };

struct O_p11 { u16 h; u8 b; };

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

extern u8 func_021D5440(u8 *p);
extern u8 func_0201C020(u16);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 func_021D6D7C(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern void func_021D7630(int key, u32 val);
extern u32 sub_0201BD28(u16 id, u32 field);
extern W_021C312C sub_0201BF58(u16 id);
extern void func_021D7C70(W_021C312C, u32, union Slot *);
extern void func_021C3244(u32 c);
extern u32 func_021C3254(u32 c);
extern u32 func_021C3264(u32 c);
extern int func_021C25A4(Server *p, u8 *a, u8 *b, u32 unused, u32 s0, union Slot s1, u32 s2);
extern void func_021C331C(u32 c);
extern u32 func_021C332C(u32 c);
extern u32 func_021C333C(u32 c);
extern int func_021D5B48(u8 *p);
extern int func_021D5B7C(void *);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021C3428(u8 *, int);
extern void func_021CD4B0(void *w, u32 id, ...);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021C3660(void *, u32);
extern int func_021D5B68(void *);
extern int func_021BF324(Server *, u8 *, u8 *);
extern int func_021BFA00(Server *, u8 *, u8 *, void *);
extern u32 func_021CC8B8(u32 *, u32);
extern u8 func_021C3670(u8 *, u8);
extern int func_021D7AD4(int);
extern void func_021C3680(void *, u32, u16, int);
extern int func_021C1678(Server *, u8 *, u8 *, u32, u16 *);
extern void func_021C3690(void *, u32, u16, int);
extern void func_021C1828(Server *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
extern void func_021C1C88(Server *, u8 *, u32, u8 *, u32);
extern void func_021D5FB8(u8 *p);
extern void func_021C16F8(Server *, u8 *, int);
extern int func_021D6D90(u8 *p);
extern void func_021C37E0(int it);
extern int func_021C37F0(int it);
extern int func_021C3800(int it);
extern u8 func_021B8D8C(void *, void *, u32);
extern u8 func_021D69AC(u8 *, int);
extern void func_021B8E28(u8 *, int, u8 *, u8 *);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern void func_021BDD7C(Server *, u8 *, u32);
extern void func_021BD9D4(Server *p, u8 i, u8 a, u8 b, int c);
extern int func_021BDA00(Server *);
extern u8 func_021B8DDC(u32 x);
extern void func_021D8244(struct B *p, int n);
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***);
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021B99C0(struct S_021C2E4C **p, u32 b);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u32 func_021D78AC(u32 range);
extern void func_021C3A98(Server *p, u8 *a);
extern u32 func_0201C184(int id);
extern int func_021EF884(void);
extern int func_021EF894(void);
extern void func_021EF8A4(u32, u32);
extern int func_021EF8C8(int a, union Slot c);
extern int func_021E8A98(union Slot c);
extern void func_021EF8F8(int a, int r);
extern int func_021C3DFC(u8 *);
extern u8 *func_021C3FAC(u8 *, int);
extern int func_021C3FBC(u16);
extern int func_021C3FCC(u16);
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021D8564(int a, int b);
extern void func_021C195C(Server *p, u8 *q, u32 n);
extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021C40F4(u8 *p, int i);
extern void func_021D6D5C(u8 *a, u16 v);
extern int func_021D6D9C(u8 *c, u16 *d);
extern void func_021C1DCC(Server *p, u8 *q, u32 a, u8 *b, u32 s);
extern void func_021C1880(Server *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
extern int func_021C4208(u8 *p, int i);
extern void func_021D6D70(u8 *p);
extern int func_021C43C0(u8 *c);
extern int func_021C43D0(u8 *c);
extern u8 *func_021C43E0(u8 *c, u8 i);
extern void func_021C443C(u8 *a);
extern void func_021C444C(u8 *a, u8 *x);
extern void func_021C445C(u8 *a, Server *p);
extern int func_021BC2B0(Server *);
extern void func_021C45E4(u8 *);
extern u8 *func_021C45F4(u8 *);
extern u8 *func_021C4604(u8 *);
extern void func_021D6408(u8 *);
extern void func_021D6E88(u8 *);
extern void func_021D701C(void);
extern u8 func_021B8FF4(u8 *);
extern u32 func_021B9064(u8 *p, int k, int x);
extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B9B98(u8 *p);
extern void *func_021B9CE8(u8 *p);
extern u32 func_021C4724(u8 *, u32);
extern u32 func_021C4734(u8 *, u32);
extern u8 func_021B8DEC(void *, int);
extern u32 func_021B99F0(u32);
extern void func_021BD43C(Server *, int, u8, u8, int);
extern void func_021BD4E4(Server *, int, u8, u8);
extern u32 func_021B8630(u32 **p);
extern u32 func_0202E7E0(Server *);
extern u32 func_0203F0A8(void);
extern u8 *func_021B9934(char *, int);
extern void func_0202E7E4(void *);
extern void func_021C48E0(u8 *a);
extern u8 *func_021C48F0(u8 *a);
extern u8 *func_021C4900(u8 *a);
extern u32 func_021C4A24(u8 *);
extern u8 *func_021C4A34(u8 *, u32);
extern u8 *func_021C4A44(u32);
extern void func_021C4A54(u8 *, u8 *, union Slot, u32, Server *);
extern int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed);
extern u32 func_021D806C(const u8 *p);
extern int func_021C20BC(Server *, u8 *, int);
extern void func_021C4B2C(u8 *, u8 *, u32);
extern int func_021C20D0(Server *p, u8 *a, int c, u8 *l);
extern void func_06898D54(void (*cb)(u8, u32, u32), u32 arg);
extern int func_021EF934(int, int);
extern void func_021C4C40(int, void *);
extern void func_021C4CEC(u8 *a);
extern u8 *func_021C4CFC(u8 *a);
extern u8 *func_021C4D0C(u8 *a);
extern u32 func_021EF8B8(void);
extern int func_021C2AB0(Server *);
extern void func_021C4E08(void *);
extern u8 *func_021C4E18(void *);
extern u8 *func_021C4E28(void *);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021D7BD4(void *, int);
extern void func_021C5078(u8 *, u8);
extern int func_021BA1A8(char **p, int m);
extern void func_021D646C(u8 *);
extern void func_021B92B0(char *p, void *m, int k);
extern void func_021C5088(u8 *, u8);
extern int func_021B902C(int, int);
extern void func_021BA1B4(char **p, int i);
extern unsigned int func_021B8640(unsigned int **p);
extern u8 func_021B8DE4(char *p, int i);
extern u8 func_021C50F8(u8 *q, u8 i);
extern void func_021BFF60(Server *, u8 *, int);
extern void func_021D8510(void *p);
extern void func_021DCF24(u8 *);
extern void func_021D8538(void *p);
extern void func_021DCFA4(void *p);
extern void func_021E0434(u8 *);
extern void func_021BD338(u8 *, Server *);
extern void func_021D6264(struct UtilSlots *p, int v);
extern int func_021EF90C(int a);
extern int func_021B85EC(u32 **p);
extern u32 func_021C52C8(u8 *, int);
extern int func_021C52D8(u8 *, int, u8);
extern int func_021C52E8(u8 *, int, u8);
extern int func_021BC310(Server *);
extern u16 func_021B86DC(void **p);
extern void func_021C52F8(u8 *, int, u8);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021CB2D4(Server *p, u8 *a, u32 b, Rec_021CAA58 *rec);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern void func_021BA1CC(char **p, int i, u32 delta);
extern void func_021BD1D0(Server *p, u8 n);
extern int func_021C54AC(void *p, int v);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern void func_021D61F0(struct UtilSlots *p);
extern union Slot func_021D6314(u8 *p, int i);
extern int func_021C5698(void *p, int v);
extern void func_021D6238(struct UtilSlots *p, int k);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D7E10(struct Unk021D62A8 *p);
extern void func_021CD63C(void *p, int v);
extern u8 func_021D5DC0(s8 *p, int i, u8 n);
extern u8 func_021D5E38(s8 *p, int i, u8 n);
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern int func_021C5BD4(void *p, int v);
extern void func_021D6034(u8 *a, int k, union Slot s);
extern int func_021E8A78(union Slot s);
extern int func_021B911C(void *, int);
extern void func_021D5F90(u8 *, u16);
extern void func_021D56A0(u8 *a, int b, int c);
extern void func_021D5674(u8 *a, int b, int c);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern void func_021D6008(u8 *, unsigned int);
extern void func_021D5FC0(struct UtilWork *, unsigned int);
extern void func_021B9D10(char *, struct Arr *, int);
extern int func_021E02DC(u8 *, u16, u32);
extern void func_021E03D8(u8 *a, int b);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 _u32_div_f(u32, u32);
extern u8 sub_0201C1C8(void *p);
extern int sub_0201C1E8(int a);
extern u16 func_021D57FC(void *p);
extern u32 func_021C6648(u8 *d);
extern u8 *func_021C6658(u8 *d, u32 i);
extern u8 *func_021C6710(u32 a, int b);
extern u32 func_021C6828(u8 *d);
extern u8 *func_021C6838(u8 *d, u32 i);
extern u32 func_021C6928(u8 *d);
extern u8 *func_021C6938(u8 *d, u32 i);
extern u32 func_021D5C08(struct UtilWork *p);
extern u32 sub_0201C1F4(u16 id);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern u32 func_021D7B10(u32 a, u32 b);
extern u8 func_021D5F14(struct UtilWork *p);
extern int func_021D7930(int i);
extern u32 sub_0201C284(u16 id);
extern u32 func_0201BD28(u32 v, u32 n);
extern u32 func_0201C1BC(u16);
extern u32 func_021D7B3C(u32, u32);
extern void func_021D70E4(void *a, int id);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int);
extern int func_021E8DA8(int);
extern int func_021D79E8(int, int);
extern int func_021EF948(int);
extern int func_021D5814(void *p, int k);
extern void func_021C6FB0(Server *p, u8 *a);
extern void func_021C70D4(Server *p, u8 *b);
extern int func_021D794C(int a, int b);
extern void func_021CD568(void *w, u16 v, u32 id, ...);
extern int func_021D7BA4(int a);
extern u16 func_0201C1D8(void *p);
extern int func_0201C1E8(int a);
extern int func_021D58A8(u8 *, int);
extern int func_021D5AD8(u8 *, int);
extern int func_021D76BC(int key, u32 val);
extern u32 func_021D7B2C(u32 a, u32 b);
void func_02082BCC(void *, int, u32);
extern int func_021C7D24(u8 *);
extern int func_021B86A0(unsigned int **, unsigned int);
extern int func_0689D5F4(u8 *p, int i);
extern int func_0689D5FC(u8 *p, int i);
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(void *a, char *b, u8 *c);
extern u32 func_0201C314(void *p);
extern int func_021C1E74(Server *p, u8 *a, u8 *b, const u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
extern int func_021B997C(u8 *, unsigned int);
extern u8 func_021B9BC4(u8 *, int);
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern char *func_021B9AF8(char *, int);
extern u8 func_021B9010(u8 *p, u8 k);
extern int func_021B8B9C(u8 *, unsigned int);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D80BC(void *, int, int, u16);
extern int func_0689D588(u8 *, int);
char *func_021B8714(char **p);
unsigned int func_021B8670(unsigned int **p);
extern u16 func_021D5444(struct QF *p);
extern unsigned int func_0201B718(void *, unsigned int, unsigned int, unsigned int);
extern u16 func_021BC948(Server *p, u8 *x, int flag);
int func_06898CF4(int a, int b);
extern u8 func_021B9AE0(unsigned int);
extern int func_021C82E4(unsigned int, int);
extern int func_068982AC(int);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021C2AF0(u8 *, u8 *);
extern u16 func_021D67E8(u8 *p);
extern void func_021BB908(int *, int);
extern void func_021BB914(int *);
extern int func_021C845C(u8 *, int);
extern void func_021BE52C(u8 *, int, int, int);
extern int func_021BFEAC(Server *, u8 *, u8 *, int *);
extern int func_021C2128(Server *p, u8 *a);
extern void func_021BDBB8(Server *p, u8 *a);
extern int func_021CC668(u8 *p);
extern int func_021C8578(u8 *p, int v, u32 *out);
extern void func_021C87A0(void *);
extern void func_021C87B0(void *);
extern void func_021C87C0(void *);
extern void func_021C87D0(void *);
extern void func_021C87E0(void *);
extern void func_021C87F0(void *);
extern void func_021C8800(void *);
extern void func_021BD1E0(struct Unk021BD1E0 *);
extern struct Rec *func_021CC9AC(struct Pack *p, int id, int b);
extern void func_021CCA74(QueueA *s, QueueB *cmd);
extern int func_021CC96C(struct Q9 *p);
extern u32 func_021CC9A4(u32 *p);
extern unsigned short func_021CC960(struct S_p14 *p);
extern int func_021CC99C(struct Q10 *p);
extern void func_021CC974(Word_021CC768 *q, int r);
extern u8 *func_021B9940(char *p, u8 i);
extern int func_021C8CAC(int a, u8 b);
extern int func_021C8CFC(u8 *a, u8 b);
extern int func_021C8E48(u8 *a, u8 b);
extern int func_021C1E14(Server *p, u8 *q, u32 a, u32 b);
extern int func_021C8F14(u8 *a, u8 b);
extern int func_021C8F94(u8 *a, u8 b);
extern int func_021D55D8(u8 *p, int i, int s);
extern int func_021C0898(Server *p, u8 *a, u32 b, u32 c);
extern int func_021C9168(int, union Slot, u8 *, unsigned long, struct Msg *);
extern int func_021C9240(void *, u8);
extern int func_021C27A0(Server *, u8 *, u8 *, u32, union Slot, u8, u32);
extern void func_021C2910(Server *, u8 *, u8 *, int, union Slot, int, int, const void *);
extern int func_021C9374(void *, u8);
extern int func_021C9384(void *, u8);
extern int func_021C9438(u8 *a, u8 b);
extern void func_021D5EA8(u8 *p, int i, u8 n);
extern int func_021D5EFC(char *);
extern void func_021D5F08(char *p);
extern int func_021C95C0(void *, u8);
extern void func_021D5970(u8 *, int, u16);
extern int func_021C961C(u8 *a, u8 b);
extern int func_021C2314(Server *p, u8 *a);
extern int func_021C96B4(u8 *a, u8 b);
extern int func_021C96C4(int a);
extern void func_021D66B0(u8 *p, int n);
extern void func_021D6440(u8 *p, u32 n);
extern int func_021C9818(u32 b, u32 a, u32 v);
extern int func_021C9888(u32 a, u32 i);
extern int func_021EF8E8(int);
extern int func_021C9A50(u32, u8, u8, const void *, u8);
extern int func_021C9BA8(u16);
extern void *func_021D8484(void *);
extern void func_021C2250(Server *p, u8 *a, u16 b, u32 c);
extern void func_021D6738(u8 *);
extern u16 func_021D5B40(struct QI *p);
extern void *func_021DCF78(void *p, unsigned int k);
extern void func_021DCF9C(void *n);
extern u16 func_021CD4FC(void *p, int k);
extern void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c);
extern void func_021C0780(Server *, u8 *, int, u8);
extern void func_021CA0B8(void *);
extern void func_021CA0C8(void *);
extern void func_021CA0D8(void *, u8 *);
extern void func_021CA0E8(void *, int);
extern void func_021CA0F8(void *);
extern int func_021CA108(void *);
extern void func_021BF83C(Server *, u16 *, u8 *, int);
extern void func_021BF3D8(Server *, int, u8 *, int, void *);
extern void func_021BF4AC(Server *, u8 *, u8 *, void *, void *);
extern void func_021BF8D4(Server *, u16 *, u8 *, int);
extern int func_021CA118(void *);
extern void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t);
extern void func_021C091C(Server *, u8 *, u8 *, u8 *, const u32 *, u32);
extern int func_021BD60C(Server *, u8 *, u8);
extern int func_021BDD00(Server *p, u8 *a, int c);
extern void func_021BB930(u8 *p, u32 value);
extern void func_021C2CA8(Server *p, u8 *a);
extern void func_021D65C8(struct Work *p, struct Work *q);
extern int func_021CA238(void *p, u8 i);
extern int func_021C1D60(Server *, u8 *, u32);
extern void func_021D67D8(u8 *, u32);
extern int func_021BD148(Server *, u8);
extern int func_021BD170(Server *, u8 *);
extern int func_021BD1B0(Server *, u8);
extern int func_021B9C98(u8 *p, u32 v);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern int func_021CA5BC(u8 *p, int k);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_021D6D54(struct R5 *p);
extern void func_021D66D8(void *m, int v);
extern u8 func_021CB214(Server *p, u8 *a, u8 *b);
extern void func_021CA8C8(void *);
extern int func_021CAA58(Server *p, u8 *a, u16 move, u8 *q, int id, void *out);
extern int func_021CACF4(Server *p, u8 *a, u16 move, u8 *q, long id, void *out);
extern u8 *func_021CA8D8(void *, int);
extern u8 func_021CA8E8(void *, u8);
extern int func_021CAFD8(Server *, u32, void *, const u16 *, u8, void *);
extern void *func_021CB174(Server *p, unsigned int n, int k);
extern void func_021CA9D4(void *, void *);
extern void func_021CA9E4(void *, void *);
extern void func_021CA9F4(void *, void *);
extern void func_021CAA04(void *, void *);
extern void func_021CAA14(void *, void *);
u32 func_021C2E4C(Server *p);
int func_021C2E64(Server *p, const u16 *q, u8 *a, u8 *b, int k);
void func_021C2F70(Server *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2);
int func_021C3008(Server *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j);
int func_021C312C(Server *p, u8 *a, enum Kind b, u8 c, u16 e, int d);
void func_021C3184(Server *p, const u16 *q, u32 r, u32 c);
void func_021C3274(Server *p, u32 q, u32 b, u32 c);
int func_021C334C(Server *p, u8 *q, int a, int b);
int func_021C3370(Server *p, void *q);
int func_021C3394(Server *p, u8 *q, int r);
void func_021C33E8(Server *a, u8 *b, int c);
void func_021C3438(Server *p, u16 *q, u8 *a, u8 *out);
void func_021C36A0(Server *p, u8 *a, u16 *b, int c);
void func_021C36E8(Server *p, u8 *q, u16 *r, int a, int b, u16 c);
u16 func_021C3720(Server *p, u8 *a, u16 *b, int c);
void func_021C376C(Server *p, u16 a1, int b, int it);
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
int func_021C66AC(Server *p, u8 *a, u32 c);
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
int func_021C7D44(char *p, int i);
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
int func_021C814C(u8 *p, int v);
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
int func_021CAA24(Server *p, u8 *q, int m, int n, int value);



























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
void func_021C3184(Server *p, const u16 *q, u32 r, u32 c)
{
    u32 t, s;
    union Slot out;
    W_021C312C v;
    s = sub_0201BD28(*q, 0xB);
    v = sub_0201BF58(*q);
    func_021D7C70(v, r, &out);
    func_021C3244(c);
    for (t = func_021C3254(c); t != 0; t = func_021C3264(c)) {
        if (func_021C2E64(p, (const u16 *)((u32)q), (u8 *)r, (u8 *)t, 1) != 0) {
            BF *f = (BF * )p->f4a8;
            if (!f->f)
                f->f = 1;
        }
        if (func_021C25A4(p, (u8 *)r, (u8 *)t, *q, s, out, 1) != 0) {
            BF *f = (BF * )p->f4a8;
            if (!f->f)
                f->f = 1;
        }
    }
}

























void func_021C3274(Server *p, u32 q, u32 b, u32 c)
{
    u32 t;
    func_021C331C(c);
    for (t = func_021C332C(c); t != 0; t = func_021C333C(c)) {
        u8 m = func_021D5440((u8 *)t);
        if (func_021C3370(p, (void *)t) == 0) {
            if (func_021C334C(p, (u8 *)t, (u16)func_021C79E0(p, q, (u8 *)t), 1) != 0) {
                BF *f = (BF * )p->f4a8;
                if (!f->f)
                    f->f = 1;
                func_021CD64C(p->fC, 0x5b, 387, m, 0xffff0000);
            }
        } else if (func_021D5B48((u8 *)t) != 0) {
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
    int v = func_021C3428(a->w1ab8, func_021D5440(b));
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
        b = (u8 *)func_021C3660(out, i++);
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
            tag = func_021C3670(p->w1ab8, func_021D5440(a));
            half = func_021D59B4(b, 13);
            category = func_021D7AD4(item);
            event1 = 0;
            event2 = 0;
            flags = (struct Flags_021C2E4C * )p->f4a8;
            if (!flags->a) flags->a = 1;
            if (func_021D6D7C(b)) {
                half = func_021C3720(p, b, q, category);
                func_021C3680(out, (u32)b, half, 1);
                event1 = 1;
            } else {
                kind = func_021C1678(p, a, b, 1, &half);
                if (kind == 0) {
                    func_021C36A0(p, b, q, category);
                } else {
                    func_021C36E8(p, b, q, category, kind, half);
                    func_021C3690(out, (u32)b, half, 0);
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
























void func_021C376C(Server *p, u16 a1, int b, int it)
{
    int v = 0;
    int r;
    func_021C37E0(it);
    r = func_021C37F0(it);
    while (r) {
        if (func_021C3810(p, (u8 *)b, (u8 *)r, 0, &v, 0, 0, 0)) {
            Q_p10 *q = (Q_p10 * )p->f4a8;
            if (!q->f)
                q->f = 1;
        } else if (v == 0) {
            func_021C5718(p, (u8 *)b, a1);
        }
        r = func_021C3800(it);
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





















/*
 * lever: func_021B8E28 receives the full position int; its own u8 signature adds an absent truncation.
 */
int func_021C3810(Server *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg)
{
    enum Mode mode;
    int position;
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
    func_021C3A98(p, a);
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
    if (func_021C3DFC(c) != 0) return;
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
    b = func_021C3FAC(c, 0);
    x = func_021D59B4(a, 16);
    y = func_021D59B4(b, 16);
    if (x != y && !func_021C3FBC(x) && !func_021C3FCC(y)) {
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
            r = func_021C40F4(p->w1ab8, func_021D5440(a));
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
    int r = func_021C4208(p->w1ab8, i);
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
    n1 = func_021C43C0(c);
    n2 = func_021C43D0(c);
    func_021D75EC(5, n2);
    func_021D7630(0x51, 1);
    for (i = 0; i < n2; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C43E0(c, i)));
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
    func_021C443C(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &x)) {
        func_021C444C(a, x);
    }
    func_021C445C(a, p);
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
        func_021C45E4(a);
        q = func_021C45F4(a);
        while (q) {
            func_021D6408(q);
            func_021D6E88(q);
            func_021CD4B0(p->fC, 0x2e, func_021D5440(q));
            q = func_021C4604(a);
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
    u32 mi, ni, s, t;
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
    s = func_021C4724(p->w1ab8, mi);
    t = func_021C4734(p->w1ab8, ni);
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
    func_021C48E0(a);
    s = func_021CC8D8(&p->lock, 9644);
    func_021C4910(p, 0x1f, (int)b);
    func_021CC95C(&p->lock, s, 9646);
    if (func_021BC2B0(p) == 0) {
        q = func_021C48F0(a);
        if (q != 0) {
            do {
                s = func_021CC8D8(&p->lock, 9652);
                func_021C4910(p, func_021D5440(q), (int)b);
                func_021CC95C(&p->lock, s, 9654);
                func_021C4F64(p, q);
                if (func_021BC2B0(p) != 0) {
                    break;
                }
                q = func_021C4900(a);
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
    n = func_021C4A24(a);
    for (; i < n; i++) list[i] = func_021D5440(func_021C4A34(a, i));
    k = 0;
    for (;;) {
        q = func_021C4A44(k++);
        if (q == 0) break;
        for (i = 0; i < n; i++) {
            m = func_021B9934(p->f8, list[i]);
            if (func_021D5B68(m) == 0) {
                if (func_021D6064(m, (u32)q, (union Slot *)(&y), (int *)(&x))) {
                    s = func_021CC8D8(&p->lock, 9719);
                    func_021C4A54(m, q, y, x, p);
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
        func_021C4B2C(p->w1ae4, a, b);
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
        func_021C4CEC(p->f868);
        q = func_021C4CFC(p->f868);
        while (q) {
            if (func_021D5B7C(q)) {
                func_021C195C(p, q, 0);
            }
            q = func_021C4D0C(p->f868);
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
    func_021C4E08(it);
    a = func_021C4E18(it);
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
            a = func_021C4E28(it);
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
    func_021C5078(p->g3e0, k);
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
    func_021C5088(p->w1ab8, k);
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
            int r = func_021C50F8(p->w1ab8, i);
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
        count = func_021C52C8(p->g3e0, 0);
        for (i = 0; i < count; i++) {
            if (!func_021C52D8(p->g3e0, 0, i)) {
                a = func_021B9934((char *)(p->f8), func_021C52E8(p->g3e0, 0, i));
                if (!func_021B86B8(p->f4) && !((struct Flags_021C5108 *)&p->f78a)->b && func_021BC2B0(p) && func_021BC310(p)) {
                    func_021CD4B0(p->fC, 0x55, func_021B86DC(p->f4));
                    ((struct Flags_021C5108 *)&p->f78a)->b = 1;
                }
                if (func_021C5308(p, a)) result = 1;
                func_021C52F8(p->g3e0, 0, i);
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
    int r = func_021C54AC(p->w1ab8, func_021D5440(a));
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
            if (func_021C5698(p->w1ab8, n) != 6) {
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
        if (func_021C5BD4(p->w1ab8, n) != 6) {
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
 * leaf is filed; it is Ilias's, inside a labelled arm9 region). Verified C for
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
    n = func_021C6648(d);
    func_021D74F8(11533);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, e);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C6658(d, i)));
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











int func_021C66AC(Server *p, u8 *a, u32 c)
{
    u8 *q;
    int r;
    q = func_021C6710(c, 0);
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
    n = func_021C6828(d);
    func_021D74F8(11648);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(5, n);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            func_021D75EC(i + 6, func_021D5440(func_021C6838(d, i)));
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
    n = func_021C6928(d);
    func_021D74F8(11731);
    func_021D75EC(3, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C6938(d, i)));
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
    func_021C6FB0(p, a);
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
    func_021C70D4(p, b);
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






int func_021C7D00(u8 *p, int b) { int i = func_021C7D24(p + 0x1ab8); if (!func_021B86A0(*(unsigned int ** *)&((struct Obj00003 *)p)->f4, i)) i = 6; return i; }













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
int func_021C7D44(char *p, int i) { return func_0689D5FC((u8 *)(p + 0x1ab8), i); }














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
char *func_021C7FE0(u8 *p, int v) { unsigned int k; k=func_021B9010(*(u8 * *)&((struct Obj00003 *)p)->f4, func_021B8DDC(v)); if(func_021B8B9C(*(u8 * *)&((struct Obj00003 *)p)->f4,k)) return func_021B9AF8(*(char * *)&((struct Obj00003 *)p)->f8,k); return 0; }












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
int func_021C814C(u8 *p, int v) { return func_0689D588(p+0x1ab8,v); }












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
int func_021C82D0(int unused, unsigned int v, int k) { return func_021C82E4(func_021B9AE0(v),k); }










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
    int c = func_021C845C(p + 0x1ab8, b);
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
    u32 buf;
    for (i = 0; i < p->f785; i++) {
        if (func_021C8578(p->w1ab8, func_021B8DDC(p->set[i]), &buf)) {
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
        func_021C87A0(q);
        func_021C87B0(p->f854);
        func_021C87C0(p->f858);
        func_021C87D0(p->f85c);
        func_021C87E0(p->f860);
        func_021C87F0(p->f864);
        func_021C8800(p->f868);
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
    if (func_021C8CAC((int)a->w1ab8, e->client)) {
        func_021C60D4(a, func_021B9934(a->f8, (u8)e->client));
        return 1;
    }
    return 0;
}






u8 func_021C8CBC(Server *a, Ent_021C8CBC *e)
{
    if (func_021C8CFC(a->w1ab8, e->idx)) {
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
    if (func_021C8E48(p->w1ab8, e->b6)) {
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

    if (func_021C8F14(p->w1ab8, e->b6)) {
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
        if (func_021C8F94(p->w1ab8, e->ids[i])) {
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
 * pass 2 2026-10-06 P2L18: EXACT (256/256). The work buffer passed to func_021C9168 is a named
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
                if (func_021C9168(k, slot, a, arg, w)) {
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
    if (func_021C9240(p->w1ab8, e->id)) {
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
        if (func_021C9374(p->w1ab8, e->ids[i])) {
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
        if (func_021C9384(p->w1ab8, e->ids[i])) {
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

    if (func_021C9438(p->w1ab8, e->b[0])) {
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
    if (func_021C95C0(p->w1ab8, e->id)) {
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

    if (func_021C961C(p->w1ab8, e->b4)) {
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

    if (func_021C96B4(p->w1ab8, e->b6)) {
        a = (int)func_021B9934((char *)p->f8, e->b6);
        if (func_021D5B68((void *)a) == 0 && func_021C96C4(func_021D5444((void *)a)) == 0) {
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
    if (func_021C9818(c->b12, c->w4, ((struct Obj09973 *)pv)->f0) != 0) {
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
        if (test(s, i) && func_021C9888(s[7], i)) {
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
    if (func_021C9A50(q->w4, q->b8, q->id, q->data, q->b28)) r = 1;
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
    if (func_021C9BA8(x)) return 0;
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
    func_021CA0B8(p->f860);
    func_021CA0C8(p->f868);
    func_021CA0D8(p->f868, b);
    func_021CA0E8(p->f868, 1);
    func_021CA0F8(p->f868);
    if (func_021CA108(p->f868)) {
        func_021C5718(p, a, ((u16 *)work)[4]);
        return 0;
    }
    func_021BF83C(p, (u16 *)out, a, (int)p->f868);
    func_021BF3D8(p, (int)out, a, (int)p->f868, p->w1f88);
    func_021BF4AC(p, (u8 *)out, a, p->f868, p->w1f88);
    func_021BF8D4(p, (u16 *)out, a, (int)p->f868);
    if (func_021CA118(p->f868)) return 0;
    state = (struct State_p13 *)p->f4a8;
    saved = (u16 *)work;
    saved[0] = ((struct Obj05194 *)state)->f0;
    saved[1] = ((struct Obj05194 *)state)->f2;
    saved[2] = ((struct Obj05194 *)state)->f4;
    func_021BD1E0((struct Unk021BD1E0 *)state);
    func_021BD200((struct Unk021BD1E0 *)((struct State_p13 *)p->f4a8), p, a, (int)p->f868);
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
        int r = func_021CA238(w->w1ab8, c->b5);
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








/*
 * interface: r1 is the halfword loaded at 021CA396; cast preserves the
 * original payload while retaining the callee's pointer prototype.
 */
u8 func_021CA394(Server *p, const u8 *q)
{
    u8 r;
    if (func_021BD170(p, (u8 *)(u32)*(const u16 *)&((struct Obj21127 *)q)->f4)) r = 1;
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
    if (func_021CA5BC(p->w1ab8, q[4])) {
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
    func_021CA8C8(out);
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
        u8 *m = func_021CA8D8(out, 0);
        if (m) p->f77f = func_021CA8E8(p->w1ab8, func_021D5440(m));
        if (!func_021CAFD8(p, mode, a, (const u16 *)q, b, out)) id = 0;
    }
    return id;
}




int func_021CA8F8(Server *p, u8 *a, int unused, u8 *q, int id, void *out)
{
    int n = func_021B8D8C(p->f4, p->f8, func_021D5440(a));
    u8 *b;
    switch (*(u32 *)(q + 12)) {
    case 0: case 3: case 4: case 5: case 9:
        if (id == 31) b = func_021CB174(p, n, 0);
        else b = (u8 *)func_021B9934((char *)p->f8, id);
        func_021CA9D4(out, b);
        return 1;
    case 1: case 7:
        if (id == 31) func_021CA9E4(out, a);
        else func_021CA9E4(out, (void *)func_021B9934((char *)p->f8, id));
        return 1;
    case 8:
        func_021CA9F4(out, a);
        func_021CAA04(out, func_021CB174(p, n, 0));
        return 2;
    case 13:
        if (id != 31) {
            func_021CAA14(out, (void *)func_021B9934((char *)p->f8, id));
            return 1;
        }
        return 0;
    case 2: case 6: case 10: case 11: case 12: default:
        return 0;
    }
}



int func_021CAA24(Server *p, u8 *q, int m, int n, int value)
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
