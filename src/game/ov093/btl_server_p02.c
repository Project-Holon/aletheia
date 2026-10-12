/*
 * file:     btl_server_p02.c
 * unit:     yes
 * function: func_021BDB88, func_021BDBB8, func_021BDBEC, func_021BDC0C, func_021BDC2C, func_021BDC58, func_021BDC78, func_021BDC98, func_021BDD00, func_021BDD7C, func_021BDE18, func_021BDE48, func_021BDE98, func_021BE3A8, func_021BE400, func_021BE518, func_021BE52C, func_021BE550, func_021BE620, func_021BE66C, func_021BE6A8, func_021BE6EC, func_021BE7E4, func_021BE878, func_021BE8C4, func_021BE8F4, func_021BE924, func_021BE95C, func_021BE994, func_021BE9D0, func_021BEA14, func_021BEA60, func_021BEAB4, func_021BEB14, func_021BEBD8, func_021BEC08, func_021BEC2C, func_021BEC58, func_021BF04C, func_021BF0E4, func_021BF168, func_021BF1B4, func_021BF244, func_021BF27C, func_021BF2B4, func_021BF2EC, func_021BF324, func_021BF3D8, func_021BF4AC, func_021BF6E8, func_021BF78C, func_021BF83C, func_021BF8D4, func_021BF9A4, func_021BFA00, func_021BFA60, func_021BFBD0, func_021BFC08, func_021BFD24, func_021BFE60, func_021BFEAC, func_021BFF60, func_021C001C, func_021C024C, func_021C0274, func_021C02CC, func_021C031C, func_021C03AC, func_021C03D8, func_021C0404, func_021C0450, func_021C0520, func_021C0780, func_021C07AC, func_021C07D4, func_021C0898, func_021C08CC, func_021C091C, func_021C0A4C, func_021C0C34, func_021C0C38, func_021C0CB4, func_021C0CE8, func_021C0D70, func_021C0D90, func_021C0F24, func_021C1184, func_021C1194, func_021C1198, func_021C11A4, func_021C11F0, func_021C14E0, func_021C15AC, func_021C15D4, func_021C15E8, func_021C1624, func_021C1678, func_021C16F8, func_021C1758, func_021C1788, func_021C17CC, func_021C1828, func_021C1880, func_021C18D4, func_021C1910, func_021C195C, func_021C199C, func_021C19D8, func_021C1A10, func_021C1A54, func_021C1B5C, func_021C1C88, func_021C1CCC, func_021C1CE4, func_021C1D60, func_021C1DCC, func_021C1E14, func_021C1E74, func_021C2048, func_021C20BC, func_021C20D0, func_021C2128, func_021C2204, func_021C2250, func_021C2314, func_021C232C, func_021C236C, func_021C2488, func_021C25A4, func_021C264C, func_021C26A8, func_021C26FC, func_021C2758, func_021C27A0, func_021C282C, func_021C2910, func_021C2AB0, func_021C2AF0, func_021C2B3C, func_021C2BA4, func_021C2BF0, func_021C2C50, func_021C2CA8, func_021C2CD8, func_021C2D10, func_021C2DC4
 * address:  0x021BDB88
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
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D70FC 0x021D70FC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E28  0x021B8E28  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021C6190  0x021C6190  thumb  ov093
 *   func_021BD0C0  0x021BD0C0  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 *   func_021C5108  0x021C5108  thumb  ov093
 *   func_021D64F0  0x021D64F0  thumb  ov093
 *   func_021BDE08  0x021BDE08  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
 *   func_021D5C08 0x021D5C08 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
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
 *   func_021C5620 0x021C5620 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021E0394 0x021E0394 thumb ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021D7394 0x021D7394 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D73D4 0x021D73D4 thumb ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   d_021EFDB8 0x021EFDB8 data a2
 *   func_021D6E74 0x021D6E74 thumb ov093
 *   func_021BCB14 0x021BCB14 thumb ov093
 *   func_021BCB68 0x021BCB68 thumb ov093
 *   func_021D6E40 0x021D6E40 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021BD148 0x021BD148 thumb ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021BEB04 0x021BEB04 thumb ov093
 *   func_021BEBB8  0x021BEBB8  thumb  ov093
 *   func_021BEBC8  0x021BEBC8  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_0201C1BC 0x0201C1BC thumb
 *   func_021BEFEC 0x021BEFEC thumb ov093
 *   func_021BEFFC 0x021BEFFC thumb ov093
 *   func_021BF00C 0x021BF00C thumb ov093
 *   func_021BF01C 0x021BF01C thumb ov093
 *   func_021BF02C 0x021BF02C thumb ov093
 *   func_021BF03C 0x021BF03C thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021BD200 0x021BD200 thumb ov093
 *   func_021C65A8 0x021C65A8 thumb ov093
 *   func_021CC8A0 0x021CC8A0 thumb ov093
 *   func_021C3184 0x021C3184 thumb ov093
 *   func_021C3438 0x021C3438 thumb ov093
 *   func_021C376C 0x021C376C thumb ov093
 *   func_021C3274 0x021C3274 thumb ov093
 *   func_021C3AA8 0x021C3AA8 thumb ov093
 *   func_021C3D08 0x021C3D08 thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
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
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B9A6C  0x021B9A6C  thumb  ov093
 *   func_021C69B8 0x021C69B8 thumb ov093
 *   func_021C6A04 0x021C6A04 thumb ov093
 *   func_021D7674 0x021D7674 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D7908 0x021D7908 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
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
 *   func_021C6110  0x021C6110  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021C000C  0x021C000C  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_021D62A8 0x021D62A8 thumb ov093
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
 *   func_021BC2B0 0x021BC2B0 thumb ov093
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
 *   _u32_div_f 0x0209C2B0 arm
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
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021C7AD0  0x021C7AD0  thumb  ov093
 *   func_021C7B0C  0x021C7B0C  thumb  ov093
 *   func_021C6134  0x021C6134  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021DCF5C  0x021DCF5C  thumb  ov093
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
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021EF884  0x021EF884  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021C2E64 0x021C2E64 thumb ov093
 *   func_021C2E1C  0x021C2E1C  thumb  ov093
 *   func_021C2E2C  0x021C2E2C  thumb  ov093
 *   func_021C2E3C  0x021C2E3C  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
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
#include "btl_server_types.h"
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

struct Unk021D62A8;
struct UtilWork;
struct Msg;
struct O;
struct Out64B4;
struct Unk021BD1E0;
struct Unk021BE518;
struct Unk021D82D0;
struct UtilSlots;
struct Q;
struct QL;
struct Work;
struct QI;
struct S_p12;
struct Q_021C0CB4;
struct Q_021C0CE8;
struct QK;
struct QF;
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

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern void func_021D70FC(int a, int b, int c);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 func_021B8DDC(u32 x);
extern void func_021CD4B0(void *w, u32 id, ...);
extern u8 func_021B8D8C(void *p, void *a, u32 b);
extern void func_021B8E28(u8 *p, u8 n, u8 *out, u8 *cnt_out);
extern void func_021BD9D4(Server *p, u8 i, u8 a, u8 b, int c);
extern int func_021C6190(Server *p, u8 *a);
extern int func_021BD0C0(Server *p, u8 x, u32 y);
extern int func_021D5B68(void *p);
extern void func_021BD1D0(Server *p, u32 n);
extern void func_021C5108(Server *p, u8 *a, int z);
extern void func_021D64F0(u8 *a);
extern void func_021BDE08(u8 *p, u32 n);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Slot func_021D6314(void *p, int i);
extern u16 func_021E8B80(union Slot v);
extern int func_021D55A0(struct UtilWork *p, int id);
extern u32 func_021D5C08(struct UtilWork *p);
extern void func_021BD1E0(struct Unk021BD1E0 *p);
extern int func_021D80BC(void *p, int a, int m, u16 move);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern int func_021E02DC(u8 *, u16, u32);
extern int func_021C62D8(Server *p, u8 *a, u32 unused, u32 c, struct O *out);
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
extern void func_021C5620(Server *p, u8 *a, int k, union Slot *out);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern void func_021D6744(u8 *, u8, int, u8, u16, u16);
extern u8 func_021D69AC(u8 *, int);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void func_021E0394(u8 *, int);
extern int func_0201BEB8(void *bag, int item);
extern int func_021EF948(int k);
extern u8 *func_021B9934(char *, int);
extern int func_021D5B7C(void *);
extern void func_021D7394(int kind);
extern int func_021D59B4(u8 *p, int k);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D73D4(int kind);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern u32 func_021D6E74(u8 *p);
extern Entry *func_021BCB14(Server *, u16, u8, u32);
extern int func_021BCB68(Server *p, Entry *cur);
extern void func_021D6E40(u8 *, u8, u16);
extern void func_021CD64C(void *, u8, ...);
extern int func_021BD148(Server *p, u8 x);
extern int func_021C88E4(Server *p);
extern void func_021C5718(Server *p, u8 *a, u32 b);
extern u8 func_021BEB04(u8 *p, int selector);
extern u32 func_021BEBB8(int d);
extern u8 *func_021BEBC8(int d, u32 i);
extern void func_021D75A8(int key, u32 val);
extern u8 func_021B8FF4(u8 *);
extern void func_021BA1B4(char **p, int i);
extern u32 func_0201C1BC(u16);
extern void func_021BEFEC(void *);
extern void func_021BEFFC(struct S *);
extern int func_021BF00C(struct S *);
extern int func_021BF01C(struct S *);
extern int func_021BF02C(struct S *);
extern void func_021BF03C(struct O *);
extern u16 func_021CD4FC(u8 *, u32);
extern void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t);
extern int func_021C65A8(Server *, u8 *, u32, u8 *);
extern void func_021CC8A0(u32 *p);
extern void func_021C3184(Server *, const u16 *, u32, u32);
extern void func_021C3438(Server *, u16 *, u8 *, u8 *);
extern void func_021C376C(Server *, u16, int, int);
extern void func_021C3274(Server *, u32, u32, u32);
extern void func_021C3AA8(Server *, u16 *, u8 *);
extern void func_021C3D08(Server *, u16 *, u8 *, u8 *);
extern void func_021C60EC(Server *p, u8 *a, u32 n);
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
extern u32 func_021B8588(void **p);
extern int func_021B9A6C(int a, u32 b);
extern int func_021C69B8(Server *, u8 *, u32, u16);
extern int func_021C6A04(Server *, u8 *, u8 *, struct Q *);
extern void func_021D7674(int, u32, u32, u32);
extern void func_021D7704(int, int);
extern unsigned char func_021D7908(int a, int i);
extern u32 func_021D7B10(u32, u32);
extern int func_021B911C(void *, int);
extern u32 func_021D78AC(u32);
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
extern void func_021C6110(Server *p, u8 *a, unsigned int n);
extern union Slot func_021E899C(u32 a);
extern int func_021C000C(u8 *p, int k);
extern void func_021C5D88(Server *p, u8 *a, int b);
extern int func_021D62A8(struct Unk021D62A8 *p);
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
extern int func_021BC2B0(Server *);
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
extern int func_021C6CAC(Server *p, u8 *a, u32 b, u32 c, int *out);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S_p12 *l, u32 v);
extern int func_021C7330(Server *, u8 *);
extern void func_021C5B74(Server *p, u8 *a, int c, int k);
extern int func_021C21F4(void *, u32);
extern u32 func_021CC918(void *, u16, int);
extern void func_021C6DD0(Server *, u8 *);
extern u32 func_021D805C(void *p, u32 n);
extern void func_021D5B44(struct QI *p, u16 v);
extern void func_021C7AD0(Server *p, u8 *a, u32 b);
extern void func_021C7B0C(Server *p, u8 *a);
extern void func_021C6134(Server *p, u8 *a, unsigned int n);
extern void func_021DCF24(u8 *a);
extern void *func_021DCF5C(void *p);
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
extern u16 func_021D5444(struct QF *p);
extern void func_021D8510(void *p);
extern void func_021D66D8(void *, u8);
extern void *func_021D8484(void *a);
extern int func_021D7D6C(int);
extern void func_021C3FDC(Server *, u8 *);
extern int func_021EF884(void);
extern void func_021D70E4(void *a, int id);
extern int func_021C2E64(Server *, const u16 *, u8 *, u8 *, int);
extern void func_021C2E1C(u32 c);
extern u32 func_021C2E2C(u32 c);
extern u32 func_021C2E3C(u32 c);
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
void func_021C2048(Server *p, u8 *a, u32 b, u32 c);
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
void func_021C2910(Server *p, u8 *a, u8 *b, int kind, union Slot value, int f, int g, const struct Msg *m);
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
extern const u16 d_021EFDB8[3];
extern u32 d_021F3B2C[];
extern u8 d_021F3B20[];
extern u8 *d_021F3B38[];
extern u16 d_021F3B26[];
extern u8 d_021F3B23[];
extern u32 d_021F3B20b[];




















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
    u32 n = func_021D5440(a);
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
    if (func_021C62D8(p, a, id, sel, (struct O *)(&o.c2)) == 0) {
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








void func_021C2048(Server *p, u8 *a, u32 b, u32 c)
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





void func_021C2910(Server *p, u8 *a, u8 *b, int kind, union Slot value, int f, int g, const struct Msg *m)
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
