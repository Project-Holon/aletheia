/*
 * file:     scrcmd_screeneffects.c
 * unit:     yes
 * function: func_021AE66C, func_021AE6E0, func_021AE708, func_021AE724, func_021AE72C, func_021AE754, func_021AE79C, func_021AE7A8, func_021AE884, func_021AE890, func_021AE8B4, func_021AE8D4, func_021AE930, func_021AE948, func_021AE994, func_021AE9CC, func_021AE9F0, func_021AEA3C, func_021AEA8C, func_021AEABC, func_021AEB3C, func_021AEBB0, func_021AEC1C, func_021AEC40, func_021AEC84, func_021AECC0, func_021AED00, func_021AED24, func_021AEDAC, func_021AEDE0, func_021AEE28, func_021AEE78, func_021AEEC0, func_021AEEE0, func_021AEF00, func_021AEF10, func_021AEF60, func_021AEFA4, func_021AEFD8, func_021AF044, func_021AF0BC, func_021AF0F8, func_021AF130, func_021AF174, func_021AF1B0, func_021AF1D0, func_021AF1E8, func_021AF21C, func_021AF23C, func_021AF26C, func_021AF294, func_021AF2BC, func_021AF2CC, func_021AF2E4, func_021AF2F4, func_021AF324, func_021AF370, func_021AF380, func_021AF3D8, func_021AF430, func_021AF448, func_021AF458, func_021AF484, func_021AF4B0, func_021AF4E8, func_021AF544, func_021AF594, func_021AF5E4, func_021AF634, func_021AF684, func_021AF6C4, func_021AF6E8, func_021AF71C, func_021AF750, func_021AF75C, func_021AF794, func_021AF7C4, func_021AF7D4, func_021AF7E4, func_021AF844, func_021AF878, func_021AF8A8, func_021AF8D8, func_021AF908, func_021AF918, func_021AF928, func_021AF958, func_021AF9A4, func_021AF9F0, func_021AFA38, func_021AFA80, func_021AFAC8, func_021AFAFC, func_021AFB2C, func_021AFB5C, func_021AFB90, func_021AFBC4, func_021AFBEC, func_021AFC18, func_021AFC28, func_021AFC38, func_021AFC88, func_021AFCD8, func_021AFD44, func_021AFDAC, func_021AFE64, func_021AFECC, func_021AFEFC, func_021AFF7C, func_021B0000, func_021B0084, func_021B010C, func_021B0130, func_021B015C, func_021B01B8, func_021B01DC, func_021B024C, func_021B02C8, func_021B0344, func_021B0394, func_021B03BC, func_021B03E4, func_021B0480, func_021B04C0, func_021B04D8, func_021B0530, func_021B05AC, func_021B0624, func_021B0630, func_021B063C, func_021B0730, func_021B07E0, func_021B0808, func_021B090C, func_021B0960, func_021B09D8, func_021B09EC, func_021B0A40, func_021B0A60, func_021B0A88, func_021B0AB0, func_021B0ADC, func_021B0B08, func_021B0BAC, func_021B0CEC, func_021B0D14, func_021B0D74, func_021B0DF0, func_021B0E74, func_021B0EDC, func_021B0EE8, func_021B0EF4, func_021B0FF0, func_021B1008, func_021B10A4, func_021B10D0, func_021B10DC, func_021B10E8, func_021B10F4, func_021B1100, func_021B11D8, func_021B120C, func_021B1234, func_021B1240, func_021B1268, func_021B12B0, func_021B1334, func_021B13E0, func_021B13EC, func_021B13F8, func_021B1424, func_021B143C, func_021B14DC, func_021B14E8, func_021B14F4, func_021B1550, func_021B15B8, func_021B15C8, func_021B1604, func_021B162C, func_021B1668, func_021B1698, func_021B16DC, func_021B16F0, func_021B1700, func_021B1738, func_021B176C, func_021B17B4, func_021B17F8, func_021B181C, func_021B18B8, func_021B18E4, func_021B1950, func_021B19B0, func_021B19E0, func_021B1A20, func_021B1A44, func_021B1B08, func_021B1BB8, func_021B1BE8, func_021B1BF4, func_021B1C2C, func_021B1CB0, func_021B1CFC, func_021B1D20, func_021B1D64, func_021B1DEC, func_021B1E74, func_021B1E80, func_021B1F60, func_021B1FB8, func_021B2040, func_021B2070, func_021B20B0, func_021B2104, func_021B2154, func_021B21AC, func_021B2218, func_021B229C, func_021B2380, func_021B23B8, func_021B23E0, func_021B23F0, func_021B240C, func_021B2444, func_021B247C, func_021B24B8, func_021B24F4, func_021B252C, func_021B2568, func_021B25A4, func_021B25DC, func_021B2614, func_021B2650, func_021B268C, func_021B269C, func_021B26AC, func_021B26E4, func_021B271C, func_021B273C, func_021B277C, func_021B27B4, func_021B27F8, func_021B2830, func_021B2860, func_021B2874, func_021B2890, func_021B28E0, func_021B2910, func_021B2940, func_021B2970, func_021B29A0, func_021B29D0, func_021B2A00, func_021B2A30, func_021B2A60, func_021B2A90, func_021B2AA0, func_021B2AB0, func_021B2ADC, func_021B2B24, func_021B2B5C, func_021B2B94, func_021B2BD8, func_021B2BEC, func_021B2C08, func_021B2C5C, func_021B2CA0, func_021B2CE8, func_021B2D34, func_021B2D98, func_021B2DBC, func_021B2E08, func_021B2E3C, func_021B2E60, func_021B2E80, func_021B2EBC, func_021B2F18, func_021B2FB0, func_021B2FD8, func_021B30C8
 * address:  0x021AE66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   d_021D9348  0x021D9348  data
 *   func_020307B0  0x020307B0  arm
 *   func_0216D5A8  0x0216D5A8  thumb
 *   func_0216E434  0x0216E434  thumb
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021AE454  0x021AE454  thumb  ov021
 *   func_021AE430  0x021AE430  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_02158F8C  0x02158F8C  thumb  ov010
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0216E818  0x0216E818  thumb  ov010
 *   func_0215A4A0  0x0215A4A0  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 *   func_02029E20  0x02029E20  thumb
 *   func_02029AF4  0x02029AF4  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_0216EAB0  0x0216EAB0  thumb  ov010
 *   func_02014024  0x02014024  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_02029984  0x02029984  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028BA0  0x02028BA0  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02029A04  0x02029A04  thumb
 *   func_02029A74  0x02029A74  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02028A58  0x02028A58  thumb
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02028BDC  0x02028BDC  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02158F88  0x02158F88  thumb  ov010
 *   func_020289B8  0x020289B8  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215A6AC  0x0215A6AC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_02005C64  0x02005C64  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_0215A6B8  0x0215A6B8  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007F68  0x02007F68  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02021288  0x02021288  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EF5C  0x0201EF5C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EE84  0x0201EE84  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_02188D50  0x02188D50  thumb  ov021
 *   func_021C34F8  0x021C34F8  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F0F8  0x0201F0F8  thumb
 *   func_0201F124  0x0201F124  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 *   func_02012104  0x02012104  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_02185534  0x02185534  thumb  ov020
 *   func_02012844  0x02012844  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_02162A6C  0x02162A6C  thumb  ov010
 *   func_02184E40  0x02184E40  thumb  ov020
 *   func_021BB578  0x021BB578  thumb  ov021
 *   func_02185050  0x02185050  thumb  ov020
 *   func_021850A8  0x021850A8  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3E8  0x021BB3E8  thumb  ov021
 *   func_02184D90  0x02184D90  thumb  ov020
 *   func_02184DE8  0x02184DE8  thumb  ov020
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_0215A864  0x0215A864  thumb  ov010
 *   func_0215A990  0x0215A990  thumb  ov010
 *   func_0215A954  0x0215A954  thumb  ov010
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_0215A77C  0x0215A77C  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_0215A7F0  0x0215A7F0  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_0215A654  0x0215A654  thumb  ov010
 *   func_02190FA0  0x02190FA0  thumb  ov021
 *   func_0215A660  0x0215A660  thumb  ov010
 *   func_0215A614  0x0215A614  thumb  ov010
 *   func_02191008  0x02191008  thumb  ov021
 *   func_0215A630  0x0215A630  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   func_021910C0  0x021910C0  thumb  ov021
 *   func_02191084  0x02191084  thumb  ov021
 *   func_020113D0  0x020113D0  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02191184  0x02191184  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021911B4  0x021911B4  thumb  ov021
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02188D48  0x02188D48  thumb  ov021
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02188D4C  0x02188D4C  thumb  ov021
 *   func_02190758  0x02190758  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D9390     0x021D9390  data
 *   d_021D939C     0x021D939C  data
 *   func_02048B0C  0x02048B0C  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_0219131C  0x0219131C  thumb  ov021
 *   func_0219129C  0x0219129C  thumb  ov021
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A63C  0x0215A63C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0215A66C  0x0215A66C  thumb  ov010
 *   func_02191348  0x02191348  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215A678  0x0215A678  thumb  ov010
 *   func_02191388  0x02191388  thumb
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_02008550  0x02008550  thumb
 *   func_0202A310  0x0202A310  thumb
 *   func_021916E0  0x021916E0  thumb  ov021
 *   func_021915EC  0x021915EC  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_021916A8  0x021916A8  thumb  ov021
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_02191830  0x02191830  thumb  ov021
 *   func_021918DC  0x021918DC  thumb  ov021
 *   func_0219196C  0x0219196C  thumb  ov021
 *   func_021919AC  0x021919AC  thumb  ov021
 *   func_02191978  0x02191978  thumb  ov021
 *   func_02191BE8  0x02191BE8  thumb  ov021
 *   func_02191B14  0x02191B14  thumb  ov021
 *   func_02158F84  0x02158F84  thumb  ov010
 *   func_02158F80  0x02158F80  thumb  ov010
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02191A04  0x02191A04  thumb  ov021
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02191A10  0x02191A10  thumb  ov021
 *   func_02192628  0x02192628  thumb  ov021
 *   func_021926D8  0x021926D8  thumb  ov021
 *   func_0219270C  0x0219270C  thumb  ov021
 *   func_0219272C  0x0219272C  thumb  ov021
 *   func_02192570  0x02192570  thumb  ov021
 *   func_0219269C  0x0219269C  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02191134  0x02191134  thumb  ov021
 *   func_02191794  0x02191794  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_021904DC  0x021904DC  thumb  ov021
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0201134C  0x0201134C  thumb
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   func_0215A6DC  0x0215A6DC  thumb  ov010
 *   func_0215A6FC  0x0215A6FC  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E3D0  0x0216E3D0  thumb  ov010
 *   func_0216CE6C  0x0216CE6C  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEE4  0x0216CEE4  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_0216D5B0  0x0216D5B0  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0219BBA4  0x0219BBA4  thumb  ov021
 *   d_021EE71C     0x021EE71C  data  a1
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_021A32A8  0x021A32A8  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C78DC  0x021C78DC  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_021627C8  0x021627C8  thumb  ov010
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021618A0  0x021618A0  thumb  ov010
 *   d_021D93FC     0x021D93FC  data   a2
 *   d_021D9404     0x021D9404  data   a4
 *   d_021D940C     0x021D940C  data   a4
 *   d_021D9414     0x021D9414  data   a4
 *   d_021D941C     0x021D941C  data   a4
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_02161AC0  0x02161AC0  thumb  ov010
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B83FC  0x021B83FC  thumb  ov021
 *   func_021C474C  0x021C474C  thumb  ov021
 *   func_021B8484  0x021B8484  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   func_021C7878  0x021C7878  thumb  ov021
 *   func_021C7220  0x021C7220  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021C7684  0x021C7684  thumb  ov021
 *   d_021D9424     0x021D9424  data   a4
 *   func_021F3E24  0x021F3E24  thumb  ov039
 *   func_021F4134  0x021F4134  thumb  ov039
 *   func_021F3D74  0x021F3D74  thumb  ov039
 *   func_021F37A4  0x021F37A4  thumb  ov040
 *   func_021F37C8  0x021F37C8  thumb  ov040
 *   func_021F37EC  0x021F37EC  thumb  ov040
 *   func_021F3834  0x021F3834  thumb
 *   func_021F3888  0x021F3888  thumb  ov042
 *   func_021F4184  0x021F4184  thumb  ov039
 *   func_021F41B0  0x021F41B0  thumb  ov038
 *   func_021F41DC  0x021F41DC  thumb  ov038
 *   func_021F398C  0x021F398C  thumb  ov043
 *   func_021F3A28  0x021F3A28  thumb  ov043
 *   func_021F3770  0x021F3770  thumb  ov044
 *   func_021F42A8  0x021F42A8  thumb  ov043
 *   func_021F3970  0x021F3970  thumb  ov044
 *   func_021F384C  0x021F384C  thumb  ov045
 *   func_021F38C4  0x021F38C4  thumb  ov045
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_021F3B5C  0x021F3B5C  thumb  ov046
 *   func_021F3AD0  0x021F3AD0  thumb  ov046
 *   func_021F3B18  0x021F3B18  thumb  ov046
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02189A24  0x02189A24  thumb  ov021
 *   sub_020113D0   0x020113D0  thumb
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_021C0AA0  0x021C0AA0  thumb  ov021
 *   func_021C0820  0x021C0820  thumb  ov021
 *   func_021C978C  0x021C978C  thumb  ov021
 *   func_021C9828  0x021C9828  thumb  ov021
 *   func_021C98F4  0x021C98F4  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   func_0218C54C  0x0218C54C  thumb  ov021
 *   func_0218C574  0x0218C574  thumb  ov021
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218BACC  0x0218BACC  thumb  ov021
 *   func_0218BA98  0x0218BA98  thumb  ov021
 *   func_0218C860  0x0218C860  thumb
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_0218C990  0x0218C990  thumb  ov021
 *   func_0218C89C  0x0218C89C  thumb  ov021
 *   d_021EE720     0x021EE720  data  a2
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_0218C9A4  0x0218C9A4  thumb  ov021
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02189A1C  0x02189A1C  thumb  ov021
 *   d_021DE14C     0x021DE14C  data  a4
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_02188DB0 0x02188DB0 thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5A0  0x021BC5A0  thumb  ov021
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_020127C4  0x020127C4  thumb
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_020071CC  0x020071CC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_021B3158  0x021B3158  thumb  ov021
 *   func_021655D4  0x021655D4  thumb  ov010
 *   d_021DE210     0x021DE210  data   ov021  a1
 *   func_0218F1B4  0x0218F1B4  thumb
 *   func_0218F1AC  0x0218F1AC  thumb
 *   func_0218F848  0x0218F848  thumb
 *   func_0218ECE4  0x0218ECE4  thumb
 *   func_0218ECB4  0x0218ECB4  thumb
 *   func_0218EC54  0x0218EC54  thumb
 *   func_0218F918  0x0218F918  thumb
 *   d_021D9708     0x021D9708  data
 */
#include "../../matched/include/Obj09183.h"
#include "../../matched/include/Obj18089.h"
#include "../../matched/include/Obj18090.h"
#include "../../matched/include/Obj18091.h"
#include "../../matched/include/Obj12833.h"
#include "../../matched/include/Obj18092.h"
#include "../../matched/include/Obj18093.h"
#include "../../matched/include/Obj18094.h"
#include "../../matched/include/Obj18095.h"
#include "../../matched/include/Obj18096.h"

struct S_021AE72C;
struct Self;
struct BigObj;
struct Ctx_021AE66C;
struct Rec;
struct Desc;
struct Sub02008C20Obj;
struct Stream;
struct SoundSys;
struct Sys;
struct Obj;
struct WordSet;
struct Big;
struct Blk34;
struct Evt;
struct Obj00020;
struct VecFx32;
struct Handle;
struct U16Vec;
struct P;
struct Fx;
struct Obj2;
struct MsgBank;
struct Q_021B0000;
struct SaveBlock;
struct Light;
struct Actor;
struct Ent;
struct Q;
struct Sub0200852CObj;
struct R;
struct GfFont;
struct U;
struct T;
struct S;
struct Cursor;
struct Rec44;
struct Ctx;
struct Tri;
struct Node;
struct Sub020071CCCtrl;
typedef struct Task {
    int state;              /* 0x00 */
    int f04;
    void *f08;              /* 0x08 */
    int f0C[4];
    int f1C;                /* 0x1C */
    int f20;
    int f24;                /* 0x24 */
    int f28[3];
    unsigned char *f34;     /* 0x34 */
} Task;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct S { u32 f0; u8 pad[0x30]; u8 *f34; } S;

typedef struct S_021AE72C {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
} S_021AE72C;

typedef int (*StepFn)(S_021AE72C *s);

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;





typedef struct {
    u16 a;
    u16 b;
    u32 f4;
    u32 f8;
} Rec;

typedef struct Ctx_021AE66C { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u8 *pc; } Ctx_021AE66C;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

typedef signed int     s32;

typedef struct Ctx_021AFBEC {
    u32 a0;
    u16 *flag;
    u32 h;
    u8 padC[0x8];
    u8 *cur;
} Ctx_021AFBEC;

typedef struct Ctx_021AFC38 { unsigned int f0; unsigned int f4; unsigned int f8; unsigned int fc; unsigned int f10; u8 *pc; } Ctx_021AFC38;

typedef signed short   s16_021AFECC;

typedef short          s16_021AFF7C;

typedef struct { u16 f0; u16 f2; s16_021AFF7C f4; u16 f6; } Q_021AFC38;

typedef short          s16_021B0000;

typedef struct { u16 f0; u16 f2; s16_021B0000 f4; u16 f6; } Q_021B0000;


typedef signed short   s16_021B010C;

typedef signed short   s16_021B0130;

typedef struct Ctx_021B015C {
    int h;
    int flag;
    u8 pad8[0xC];
    u8 *p;
} Ctx_021B015C;

typedef signed short   s16_021B01B8;




typedef signed short   s16_021B0394;

typedef signed short   s16_021B03BC;

typedef signed short   s16_021B04C0;

typedef struct { s32 x, y, z; } VecFx32;

typedef struct { int x, y, z; } V;

typedef struct { int m[9]; } M;

typedef struct { int m[12]; } M43;

typedef struct T { int a; int b; int c; } T;

typedef struct Q { int f0; int f4; int f8; } Q;


typedef struct S_021B0960 {
    u16 id;
    u16 pad;
    V sum;
    V a;
    V b;
} S_021B0960;

typedef struct S_021B0BAC {
    u16 id;
    u16 flag;
    V sum;
    V a;
    V b;
} S_021B0BAC;

typedef int BOOL;

typedef struct V3_021B0D14 {
    int y;
    void *x;
    void *z;
} V3_021B0D14;

typedef struct S_021B0EF4 {
    u16 id;
    u16 flag;
    V3_021B0D14 sum;
    V3_021B0D14 a;
    V3_021B0D14 b;
} S_021B0EF4;

typedef struct { u16 v[4]; } Ids;


typedef signed short   s16_021B23E0;

typedef signed short   s16_021B23F0;

typedef signed short   s16_021B268C;

typedef signed short   s16_021B269C;

typedef signed short   s16_021B271C;

typedef signed short   s16_021B2860;

typedef signed short   s16_021B2874;

typedef signed short   s16_021B2BD8;

typedef struct Work {
    u8  state;
    u8  sub;
    u8  b2;
    u8  b3;
    u32 f04;
    u8  f08;
    u8  pad09[3];
    u16 f0C;
    u16 pad0E;
    u32 f10;
    u32 f14;
    void *f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Work;


typedef struct {
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;
    VecFx32 d;
    s32 e[5];
    s32 f;
} Param;

extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *x);
extern int func_0216D86C(void *x);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern u16 func_0216D5F8(void *p);
extern int func_0216D3CC(int a0);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a, int b);
extern int func_0216D454(void *a);
extern int func_0216D480(char *p);
extern int func_0216E0E8(int a0, int a1);
extern u32 func_020307B0(void *p);
extern u32 func_0216D5A8(u32);
extern u32 func_0216E434(u32);
extern void func_0216D828(u32 a, Vec3s *out);
extern s16 func_021641E8(u32 dir);
extern s16 func_021641F8(u32 dir);
extern int func_02163994(u32 a, int x, int y, int z, u32 dir);
extern int func_021AA900(struct Self *self, short *pos);
extern u32 func_0215A460(u32);
extern u32 func_0216D5B8(void *p);
extern void *func_020120F4(const struct Ctx_021AE66C *p);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned func_0215A4D8(void *a, unsigned b);
extern void *func_02188C80(void *p);
extern void *func_0216D67C(void *a0);
extern int func_0216DD1C(struct Ctx_021AE66C *c, struct Rec **out, u32 *iter);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u16 func_02159B10(void *a0, void *a1);
extern char *func_02159124(char *p, int i);
extern u16 func_0215A5CC(void *a0);
extern u32 func_021AE454(void *a, u32 b, u32 *c, u32 d);
extern void *func_0215A5DC(void *a0);
extern u32 func_021AE430(u32 a, u32 x, u32 y);
extern void func_0215897C(void *vm, void *task);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0216D588(void *p);
extern u16 func_02158F8C(u8 *p);
extern int func_0215A4C8(int a0);
extern int func_0215A4B4(int a0);
extern void *func_02158F54(void *p);
extern int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u32 func_0215A4A0(u32 a);
extern void *func_0215A5E4(void *a0);
extern u32 func_0202A230(void *a, u32 idx);
extern unsigned short func_02029E20(u32 k);
extern void *func_02029AF4(void *a, u32 b);
extern void *func_0201210C(const struct Ctx_021AE66C *p);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_0216EAB0(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 idx);
extern void *func_02012F2C(int *p);
extern u16 func_02188C9C(u8 *p);
extern int func_02014024(u32 a);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u16 func_02011330(struct Stream *s);
extern void *func_02029984(void *a, u32 b);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028BA0(u8 *o, u32 v);
extern void func_02159144(int n);
extern void *func_02029A04(void *a, u32 b, u16 c);
extern void *func_02029A74(void *a, u16 b);
extern int func_02005F38();
extern void func_020113D0(char *p, int val);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void func_02159168(int n);
extern u8 func_02012984(const struct BigObj *p);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u32 c, u32 d);
extern void func_02028BDC(struct S_021AE72C *s, u32 mask);
extern u8 *func_020295A4(u8 *p, u32 a);
extern void *func_02029620(void *a, u32 b, u32 c);
extern u8 *func_02158F88(void *p);
extern int func_02006224(u32 a0);
extern int func_02006148(u32 a);
extern void func_020061F8(int i);
extern void func_020061E4(u32 a);
extern void *func_02029830(void *a, u32 b);
extern u32 func_020289B8(struct Sys *s);
extern struct Desc *func_020122C0(void *a, void *b, void *c, unsigned int d);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02006BD0(u32);
extern u32 func_0215A6AC(u32, u32, u32, u32);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B578(u32 *p);
extern void func_0202C0D0(u8 *p, u32 a);
extern void func_0202C0E4(u8 *p, u32 a);
extern int func_0202C0F8(int a0, int a1);
extern int func_02005C64(void);
extern void func_02006CAC(void **out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void func_0215A6B8(u32 *a, u32 b);
extern void *func_0201292C(const struct BigObj *p);
extern u16 func_02007E50(void *a, u32 b, u32 c, u32 d);
extern u16 func_02007F1C(void *, u32, u32, u32);
extern u16 func_02007E3C(void *, u32, u32, u32);
extern u16 func_02007F68(void *, u32, u32, u32);
extern u16 func_02007FB8(void *, u32, u32);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern u32 func_02021288(u32 id);
extern void *func_02158F74(void *p);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF40();
extern void func_0201EF4C();
extern void func_0201EF5C(struct WordSet *p, u32 i, u32 v);
extern u32 func_020212B0(u32 a);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F020(struct WordSet *p, u32 i, u32 v);
extern void func_0201EE60();
extern void func_0201EEC4();
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *, u32);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void *func_02188D50(u8 *);
extern void *func_021C34F8(void *, u32);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_02013E4C(u32 a);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFC8(struct WordSet *p, u32 i, u32 v);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F198(struct WordSet *p, u32 i, u32 v);
extern void func_0201F1B0(struct WordSet *p, u32 i, u8 v);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern void func_0201F0F8();
extern void func_0201F124();
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern u32 func_0200C1DC(struct Blk34 *p);
extern u32 func_0200C1C4(struct Blk34 *p);
extern u32 func_02012104(const struct Ctx_021AFC38 *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02184D38();
extern void *func_02185534();
extern u32 func_02012844(const struct BigObj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02188CD0(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern struct Rec *func_0216282C(struct Ctx_021AFC38 *c, void *a, int *key, int mode);
extern void func_02162A6C(int a, int b);
extern void *func_02184E40();
extern void func_021BB578(int a, int b, int c, int d);
extern void *func_02185050();
extern u32 func_021850A8(u32 a, void *b);
extern void *func_021854B0();
extern u32 func_02188C5C(u8 *p);
extern int func_021BB3E8();
extern void *func_02184D90(void *p, void *unused, int a, const Q_021AFC38 *q, int s, int t);
extern void *func_02184DE8(void *p, void *unused, int a, const Q_021B0000 *q, int s, int t);
extern void func_0215A684(int *p, unsigned short v);
extern int func_0215A690(char *a0);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern void func_0215A864(int *p);
extern int func_0215A990(u8 *a);
extern int func_0215A954(u8 *a);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern u32 func_0215A77C(u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_0215A60C(u8 *p);
extern u32 func_02158F78(u8 *p);
extern u32 func_02158F7C(u8 *p);
extern void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);
extern int func_02159190(int a0);
extern int func_0215A61C(int a0);
extern void func_02191164(struct P *p);
extern u32 func_0215A654(u8 *p);
extern struct Obj2 *func_02190FA0(struct Fx *a, u32 b, u32 c);
extern void func_0215A660(u8 *p, u32 v);
extern u32 func_0215A614(u8 *p, u32 v);
extern int func_02191008(u32 a);
extern u32 func_0215A630(u8 *p);
extern void func_0202F038(u8 *p);
extern void func_0215A624(u8 *p, u32 v);
extern u32 func_021910C0(u32 *p);
extern void func_02191084(struct P *p, u32 b, u16 c, u32 d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02191184(struct Q_021B0000 *q, u32 b, int c, u32 d);
extern u16 func_02188C84(u8 *p);
extern u32 func_021911B4(u8 *p);
extern u32 func_020056BC(void);
extern u32 func_0202EE30(u32, u32, u32, u32, u32);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02188D48(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02012F08(int *p);
extern u32 func_0200C274(struct Blk34 *p);
extern int func_02190728(void *a);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern void func_02188D4C(u8 *p, u32 v);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02190788(u8 *p);
extern void func_02048AD0(struct Light *l);
extern void func_02048B30(void *cam, VecFx32 *out);
extern void func_02048AE8(void *cam, VecFx32 *out);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0207CCA4(const VecFx32 *a, VecFx32 *out);
extern void func_0207CAE8(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_0206DF3C(VecFx32 *pos, u32 *x, u32 *z);
extern void func_02048B0C(int, V *);
extern void func_0207BCA0(V *, V *, V *, M43 *);
extern void func_02082B60(M43 *, M *);
extern void func_0207B0A4(M *, M *);
extern void func_0207B51C(M *, M *, M *);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *t);
extern u32 func_021912F8(u32);
extern int func_021912D8(u32 a);
extern int func_0219131C(u32 a);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern void *func_0215A5EC(void *);
extern unsigned char *func_0215A63C(unsigned char *p);
extern void *func_0216DE94(void *map, u32 id);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern u8 func_0215A66C(u8 *p);
extern u32 func_02191348(u32 *a, u32 b);
extern void func_02082BCC(void *p, int v, int n);
extern void func_0215A678(u8 *p, u8 v);
extern u32 func_02191388(u32 *a);
extern void *func_02158F90(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0202A310(int key, int want, void *dest, u32 heap);
extern u32 func_021916E0(u32 *a);
extern void func_021915EC(struct R *r);
extern int func_02191558(int, int, int, int, int, int, int);
extern void func_021916A8(struct R *r, u32 b, u16 c, u32 d);
extern int func_021915B4(void *a);
extern void func_02191830(struct Q *q, u32 a, u8 *w, u8 *h);
extern void func_021918DC(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g);
extern void func_0219196C(u32, u32);
extern int func_021919AC(u8 *p);
extern void func_02191978(struct P *p);
extern u32 func_02191BE8(u32 *p, u32 b);
extern void func_02191B14(u32 *a);
extern u32 func_02158F84(u8 *p);
extern void func_02158F80(u8 *p, u32 v);
extern u32 func_0201D83C(void *ptr);
extern int func_02191A04(int, int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
extern u32 *func_02191A10(u16 *a, u32 b, u32 c);
extern void func_02192628(u32 *a);
extern int func_021926D8(struct U *u);
extern u32 func_0219270C(struct Q *q, int a, int n);
extern u32 func_0219272C(u16 *a, u32 b, u32 c);
extern u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f);
extern void func_0219269C(struct T *t, u16 b, u16 c, u32 d);
u32 func_020362DC(void);
void func_02191134(struct P *p);
void func_02191794(struct R *r);
void func_021914CC(struct S *s);
extern void func_021904DC(u8 *p, u8 v);
extern void *func_0216DE54(void *map, u32 kind);
unsigned int func_0201134C(struct Cursor *p);
int func_02197D3C(int a, int b);
void func_0215A6DC(int *p, int v);
extern u32 func_0215A6FC(u32, u32, u32, u32);
extern u16 func_0216D5A0(void *p);
int func_0216E3D0(int a, int b);
int func_0216CE6C(int a, s16 b, s16 c, int d, int e, int f, int g, int h);
void func_0216DAF8(void *a0);
extern void func_0216CF2C(u32);
u16 func_02162744(u8 *p);
unsigned short func_02012AC8(const struct Rec44 *p);
u32 func_02162740(u8 *p);
int func_0216CEE4(int a, int b, int c, int d, void *e, int f);
void func_0216E084(u32 m, s16 x, s16 y, s16 z, u32 e);
extern u16 func_0216D5B0(u8 *p);
int func_0216D63C(char *a0, int a1);
extern void func_0216DB80(unsigned int *p, unsigned int v);
int func_0216DA5C(void *a0);
int func_0219BBA4(int a);
void func_0216D9A0(void *map);
char *func_0216DB04(void *a0);
extern u32 *func_0216D9E4(void *c);
extern u16 func_021642A4(int i);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
void *func_02188C7C(unsigned char *p);
u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern int func_021A32A8(void *, u32);
extern int func_021A2F54(u8 *p);
extern void func_021A2F48(u8 *p, u32 a1);
extern u32 func_02188D38(u8 *p);
extern u32 func_021C78DC(u32, int, void *, void *);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern void *func_0216DEE0(void *a0);
extern struct Rec *func_021627C8(struct Ctx *c, void *a, int key, int mode);
extern u16 func_021A3050(u8 *p);
extern void *func_021618A0(void *p, int a1, int a2, int a3);
extern u32 func_021A3098(u8 *p);
extern void *func_02161AC0(void *p, void *a1, struct Tri *t, void *a3);
extern int func_021A3238(u8 *p);
extern void *func_0219E348(void *a);
extern void func_021B83FC(struct Obj *o, u16 *out0, u16 *out1, u16 *out2);
extern void *func_021C474C(void *a, u32 b, u32 c);
extern void func_021B8484(u8 *p, u32 a, u32 b, int c);
extern void func_021B7DC0(u32, void *);
extern void func_0219E2C0(void *a, void *r);
extern u32 func_021C7878(u32, u32, void *, u32);
extern void *func_021C7220(u32 a, u16 b, int c, u32 d);
extern int func_02163E58(u32 m, V *pos, int *h);
extern void func_0216D89C(u32, V *);
extern void func_0216D8C0(u32, V *);
extern void *func_021C7684(u32 a, u32 b, int c, int d);
extern int func_021F3E24(void *a, u32 b);
extern void func_021F4134(void *p, u32 i);
extern void func_021F3D74(u32 a);
extern void func_021F37A4(u8 *p);
extern int func_021F37C8(u8 *p);
extern void *func_021F37EC(void *p, u32 i);
extern u32 func_021F3834(void *, u8, u32);
extern int func_021F3888(void *a, u32 b);
extern u32 func_021F4184(void *, u16);
extern void *func_021F41B0(void *p, int v);
extern void *func_021F41DC(void *p, int v);
extern int func_021F398C(void *a, int b);
extern u32 func_021F3A28(void *, u32);
extern u32 func_021F3770(void *, u32);
extern void func_021F42A8(void *p);
extern void func_021F3970(void *a);
extern void *func_021F384C(void *a, int b);
extern void func_021F38C4(void *a0, int a1);
extern int func_021F3A88(int a0, int a1, int a2);
extern void *func_021F3B5C(void *a, int b);
extern int func_021F3AD0(void *a, int b, int c);
extern u32 func_021F3B18(void *, u32);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_02189A24(u8 *p);
extern void sub_020113D0(char *p, int val);
extern void *func_02158F50(void *p);
extern void *func_021C0AA0(void *p, int a1);
extern void *func_021C0820(void *p, int a1, u32 n);
extern u32 func_021C978C(u32 a, u32 b, u32 c);
extern u32 func_021C9828(u32, u32, u32);
extern u32 func_021C98F4(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C654(int a, int b, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
extern void func_0218C54C(int a, int b);
extern void func_0218C574(int a, int b, int c);
extern int func_0218C7D8(void *p, int b, int c);
extern int func_0218BACC(int a, int b);
extern u32 func_0218BA98(u32, u32);
extern void func_0218C860(u32);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern int func_0218C990(unsigned char *p, int v);
extern void func_0218C89C(unsigned char *p, int v);
extern int func_0218C8D8(void *p);
extern int func_0218C9A4(void *p);
extern u32 func_02188D30(u8 *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02030DA8(int, void (*)(), u32 *, u32);
extern void func_02189A1C(u8 *p, u32 v);
extern unsigned int func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(unsigned int planes);
extern void func_02188DB0(u8 *a);
extern void func_02030EAC(struct Node *n);
extern u32 func_02188D20(u8 *p);
extern void func_021BC5A0(void *p, int v);
extern void *func_02158FB4(void *p);
extern u8 *func_020127C4(void *p);
extern u32 func_021904AC(u8 *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern int func_021B3158(u32 a, u32 b);
extern void func_021655D4(void);
extern u8 func_0218F1B4(u8 *p);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218F848(u8 *a);
extern void func_0218ECE4(void *h, VecFx32 *out);
extern void func_0218ECB4(void *h, VecFx32 *out);
extern void func_0218EC54(u8 *p);
extern void func_0218F918(void *h, Param *p, int n);
int func_021AE66C(Task *p);
int func_021AE6E0(S *s);
int func_021AE708(u32 a, u32 b, u32 c, u32 d);
int func_021AE724(u32 *p);
int func_021AE72C(S_021AE72C *s);
int func_021AE754(u32 a, u32 b, u32 *c);
int func_021AE79C(u32 a);
int func_021AE7A8(u32 a, u32 dir, int n, void *p);
int func_021AE884(u32 a);
int func_021AE890(u32 a, u32 b);
void func_021AE8B4(S_021AE72C *s, u32 a, u32 b, u32 c);
u32 func_021AE8D4(u32 a, u16 b);
int func_021AE930(int a, u32 b);
int func_021AE948(u32 a, u32 b);
int func_021AE994(u32 a, u32 b);
int func_021AE9CC(u32 a, u32 b);
int func_021AE9F0(u32 a, u32 b);
int func_021AEA3C(u32 a, u32 b);
int func_021AEA8C(u32 a, u32 b);
int func_021AEABC(u32 a, u32 b);
int func_021AEB3C(u32 a, u32 b);
int func_021AEBB0(u32 a, u32 b);
int func_021AEC1C(u32 a, u32 b);
int func_021AEC40(u32 a, u32 b);
int func_021AEC84(u32 a, u32 b);
int func_021AECC0(u32 a, u32 b);
int func_021AED00(u32 a, u32 b);
int func_021AED24(u32 a, u32 b);
void func_021AEDAC(u32 a);
int func_021AEDE0(u32 a, u32 b);
int func_021AEE28(u32 a, u32 b);
int func_021AEE78(u32 a, u32 b);
int func_021AEEC0(u32 a, u32 b);
int func_021AEEE0(u32 a, u32 b, u32 c, u32 d);
int func_021AEF00(u32 a);
int func_021AEF10(u32 a, u32 b);
int func_021AEF60(u32 a, u32 b);
int func_021AEFA4(u32 *a, u32 *st);
int func_021AEFD8(u32 a, u32 b);
int func_021AF044(struct Stream *a, u32 b);
int func_021AF0BC(u32 a, u32 b);
int func_021AF0F8(u32 a, u32 b);
int func_021AF130(u32 a, u32 b);
int func_021AF174(S_021AE72C *s, u32 *st);
int func_021AF1B0(u32 a, u32 b, u32 c, u32 d);
int func_021AF1D0(u32 a, u32 b, u32 c, u32 d);
void func_021AF1E8(u32 a);
void func_021AF21C(u32 a, u32 b);
int func_021AF23C(u32 a);
void func_021AF26C(u32 a);
int func_021AF294(u32 a, u32 b);
int func_021AF2BC(u32 a, u32 b, u32 c, u32 d);
int func_021AF2CC(u32 a, u32 b, u32 c, u32 d);
int func_021AF2E4(u32 a);
int func_021AF2F4(u32 a, u32 b);
int func_021AF324(u32 a, u32 b);
int func_021AF370(u32 a);
int func_021AF380(u32 a, u32 b);
int func_021AF3D8(u32 a, u32 b);
int func_021AF430(u32 a, u32 b, u32 c, u32 d);
int func_021AF448(u32 a);
int func_021AF458(u32 a, u32 b);
int func_021AF484(u32 a, u32 b);
int func_021AF4B0(u32 a, u32 b);
int func_021AF4E8(u32 a, u32 b, Rec *c);
int func_021AF544(u32 a, u32 b);
int func_021AF594(u32 a, u32 b);
int func_021AF5E4(u32 a, u32 b);
int func_021AF634(u32 a, u32 b);
int func_021AF684(u32 a, u32 b);
int func_021AF6C4(u32 a, u32 b);
int func_021AF6E8(u32 a, u32 b);
int func_021AF71C(u32 a, u32 b);
int func_021AF750(u32 a);
int func_021AF75C(Ctx_021AE66C *s, u32 b);
int func_021AF794(Script *a, u32 b, void (*fn)());
int func_021AF7C4(Script *a, u32 b);
int func_021AF7D4(Script *a, u32 b);
void func_021AF7E4(Script *a, u32 b);
int func_021AF844(Ctx_021AE66C *s, u32 b);
int func_021AF878(Ctx_021AE66C *s, u32 b);
int func_021AF8A8(Ctx_021AE66C *s, u32 b);
int func_021AF8D8(Script *a, u32 b, void (*fn)());
int func_021AF908(Script *a, u32 b);
int func_021AF918(Script *a, u32 b);
int func_021AF928(Ctx_021AE66C *s, u32 b);
int func_021AF958(Script *a, u32 b);
int func_021AF9A4(Script *a, u32 b);
int func_021AF9F0(Script *a, u32 b);
int func_021AFA38(Script *a, u32 b);
int func_021AFA80(Script *a, u32 b);
int func_021AFAC8(Ctx_021AE66C *s, u32 b);
int func_021AFAFC(Ctx_021AE66C *s, u32 b);
int func_021AFB2C(Ctx_021AE66C *s, u32 b);
int func_021AFB5C(Ctx_021AE66C *s, u32 b);
int func_021AFB90(Ctx_021AE66C *s, u32 b);
int func_021AFBC4(Ctx_021AE66C *s, u32 b);
int func_021AFBEC(Ctx_021AFBEC *a0, int a1, void (*fn)());
int func_021AFC18(Ctx_021AFBEC *a, int b);
int func_021AFC28(Ctx_021AFBEC *a, int b);
int func_021AFC38(Ctx_021AFC38 *a0, int a1);
int func_021AFC88(Ctx_021AFC38 *a0, int a1);
int func_021AFCD8(int a0, int a1);
int func_021AFD44(int a0, int a1);
int func_021AFDAC(int a0, int a1);
int func_021AFE64(int a0, int a1);
int func_021AFECC(u32 a, u32 b);
int func_021AFEFC(int a0, int a1);
int func_021AFF7C(int a0, int a1);
int func_021B0000(int a0, int a1);
int func_021B0084(u32 a0, int *st, Ctx_021AFBEC *c);
u32 func_021B010C(u32 a, u32 x, u32 y);
int func_021B0130(u32 a, u32 b);
int func_021B015C(int a0, int *st, Ctx_021B015C *c);
u32 func_021B01B8(u32 a, u32 x, u32 y);
int func_021B01DC(Ctx_021B015C *c, u32 b);
int func_021B024C(Ctx_021B015C *c, u32 b);
int func_021B02C8(Ctx_021B015C *c, u32 b);
int func_021B0344(u32 a, u32 b);
int func_021B0394(u32 a, u32 b, u32 c, u32 d);
int func_021B03BC(u32 a, u32 b, u32 c, u32 d);
void func_021B03E4(u32 a, u32 b);
void func_021B0480(u32 a);
int func_021B04C0(u32 a, u32 b, u32 c, u32 d);
int func_021B04D8(u32 a, u32 b);
int func_021B0530(u32 a, u32 b);
int func_021B05AC(u32 a, u32 b);
int func_021B0624(u32 a, u32 b, u32 c, u32 d);
int func_021B0630(u8 *p);
int func_021B063C(u32 a, u32 b);
int func_021B0730(u32 a, u32 b);
int func_021B07E0(u32 a, u32 b);
void func_021B0808(const VecFx32 *src, VecFx32 *out, void *cam, int unused);
void func_021B090C(M *a, int b);
void func_021B0960(int a, VecFx32 *p, int q, int r3, u8 e);
void func_021B09D8(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_021B09EC(int sel, int *a, int *b);
int func_021B0A40(u32 a, Q *q);
int func_021B0A60(u32 a, u32 b, u32 c, u32 d);
void func_021B0A88(u32 a, u32 b);
void func_021B0AB0(u32 a);
void func_021B0ADC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_021B0B08(void *a, int b);
int func_021B0BAC(u32 b, u16 id, u16 c, u16 d, u16 e, int f);
int func_021B0CEC(int a, int b);
int func_021B0D14(int a, int b);
int func_021B0D74(int a, int b);
int func_021B0DF0(int a, int b);
int func_021B0E74(int a, int b);
u32 func_021B0EDC(u32 a, u32 b);
int func_021B0EE8(u8 *p);
int func_021B0EF4(void *a, int b);
int func_021B0FF0(u32 a, u32 b, u32 c, u32 d);
int func_021B1008(void *a, int b, int c);
void func_021B10A4(void *p);
int func_021B10D0(void *a, int b);
int func_021B10DC(void *a, int b);
int func_021B10E8(u32 a, u32 b, u32 c, u32 d);
int func_021B10F4(u8 *p);
int func_021B1100(void *a, u32 b);
int func_021B11D8(u32 a, u32 b);
void func_021B120C(u32 a);
int func_021B1234(u8 *p);
int func_021B1240(int a, int b);
void func_021B1268(void *p);
int func_021B12B0(int a, unsigned char *b);
int func_021B1334(int a, unsigned char *b);
int func_021B13E0(u32 a, u32 b, u32 c, u32 d);
int func_021B13EC(u8 *p);
void func_021B13F8(u32 a);
int func_021B1424(int a, int b, int c, int d);
int func_021B143C(void *a, int b);
int func_021B14DC(u32 a, u32 b, u32 c, u32 d);
int func_021B14E8(u8 *p);
int func_021B14F4(int a, int b);
int func_021B1550(int a, int b);
int func_021B15B8(u32 a);
int func_021B15C8(u32 a, u32 b);
int func_021B1604(u32 *a);
u32 func_021B162C(u32 a, u32 b, u32 c);
u32 func_021B1668(u32 a, u32 b);
int func_021B1698(int *a, int *b);
int func_021B16DC(u32 a, u32 b, u32 c, u32 d);
int func_021B16F0(u32 a);
int func_021B1700(u32 a, u32 b);
int func_021B1738(u32 a, u32 b);
int func_021B176C(int a, int b);
int func_021B17B4(int a, int b);
int func_021B17F8(u32 a, u32 b);
int func_021B181C(int a, int b);
int func_021B18B8(u32 a, u32 b);
int func_021B18E4(int a, int b);
int func_021B1950(int a, int b);
int func_021B19B0(u32 a, u32 b);
int func_021B19E0(int a, int b);
int func_021B1A20(u32 a, u32 b);
int func_021B1A44(int a, int b);
int func_021B1B08(int a, void *b);
int func_021B1BB8(int a, void *b);
int func_021B1BE8(u32 a, u32 b, u32 c, u32 d);
int func_021B1BF4(u32 a, u32 b);
int func_021B1C2C(int a, int b);
int func_021B1CB0(u32 a, u32 b);
int func_021B1CFC(u32 a, u32 b, u32 c, u32 d);
int func_021B1D20(u32 a, u32 b);
int func_021B1D64(u32 a, u32 b);
int func_021B1DEC(u32 a, u32 b);
int func_021B1E74(u32 a);
int func_021B1E80(void *a, u32 b);
int func_021B1F60(u32 a, u32 b);
int func_021B1FB8(u32 a, u32 b);
int func_021B2040(u32 a, u32 b);
int func_021B2070(u32 a, u32 b);
int func_021B20B0(u32 a, u32 b);
int func_021B2104(u32 a, u32 b);
int func_021B2154(u32 a, u32 b);
int func_021B21AC(u32 a, u32 b);
int func_021B2218(u32 a, u32 b);
int func_021B229C(u32 a, u32 b);
int func_021B2380(u32 a, u32 b);
int func_021B23B8(u32 a, u32 b);
int func_021B23E0(u32 a, u32 b, u32 c, u32 d);
int func_021B23F0(u32 a, u32 b, u32 c, u32 d);
int func_021B240C(u32 a, u32 b);
int func_021B2444(u32 a, u32 b);
int func_021B247C(u32 a, u32 b);
int func_021B24B8(u32 a, u32 b);
int func_021B24F4(u32 a, u32 b);
int func_021B252C(u32 a, u32 b);
int func_021B2568(u32 a, u32 b);
int func_021B25A4(u32 a, u32 b);
int func_021B25DC(u32 a, u32 b);
int func_021B2614(u32 a, u32 b);
int func_021B2650(u32 a, u32 b);
int func_021B268C(u32 a, u32 b, u32 c, u32 d);
int func_021B269C(u32 a, u32 b, u32 c, u32 d);
int func_021B26AC(u32 a, u32 b);
int func_021B26E4(u32 a, u32 b);
int func_021B271C(u32 a, u32 b, u32 c, u32 d);
int func_021B273C(int a, int b);
int func_021B277C(u32 a, u32 b);
int func_021B27B4(int a, int b);
int func_021B27F8(u32 a, u32 b);
int func_021B2830(u32 a);
int func_021B2860(u32 a, u32 b, u32 c, u32 d);
int func_021B2874(u32 a, u32 b, u32 c, u32 d);
int func_021B2890(u32 a, u32 b);
int func_021B28E0(u32 a, u32 b);
int func_021B2910(u32 a, u32 b);
int func_021B2940(u32 a, u32 b);
int func_021B2970(u32 a, u32 b);
int func_021B29A0(u32 a, u32 b);
int func_021B29D0(u32 a, u32 b);
int func_021B2A00(u32 a, u32 b);
int func_021B2A30(u32 a, u32 b);
int func_021B2A60(u32 a, u32 b);
int func_021B2A90(u32 a);
int func_021B2AA0(void *p);
int func_021B2AB0(u32 a, u32 b);
int func_021B2ADC(int a, int b);
int func_021B2B24(u32 a, u32 b);
int func_021B2B5C(u32 a, u32 b);
int func_021B2B94(int a, int b);
int func_021B2BD8(u32 a);
int func_021B2BEC(int a, int b, int c, int d);
int func_021B2C08(int a, int b);
int func_021B2C5C(int a, int b);
int func_021B2CA0(int a, int b);
int func_021B2CE8(int a, int b);
int func_021B2D34(int a, int b);
int func_021B2D98(u32 a, u32 b);
int func_021B2DBC(int a, int b);
int func_021B2E08(u32 a, u32 b);
int func_021B2E3C(u32 a, u32 b);
int func_021B2E60(u32 a, u32 b);
int func_021B2E80(u32 a, u32 b);
void func_021B2EBC(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021B2F18(int p, int *q);
int func_021B2FB0(u32 a, u32 b);
int func_021B2FD8(u32 a, u32 b);
void func_021B30C8(u32 *p, u32 b, void *h);
extern StepFn d_021D9348[];
extern const VecFx32 d_021D9390;
extern const VecFx32 d_021D939C[2][4];
extern u8 d_021EE71C;
extern Ids d_021D93FC;
extern u8 d_021D9404[];
extern u8 d_021D940C[];
extern u8 d_021D9414[];
extern u8 d_021D941C[];
extern const V d_021D9424;
extern u16 d_021EE720;
extern u8 d_021DE14C;
extern u8 d_021DE210[];
extern VecFx32 d_021D9708[];

















int func_021AE66C(Task *p)
{
    void *r4 = func_021A3074(p->f34);
    int r6 = func_0216D83C(r4);
    int r7 = func_0216D86C(r4);
    int t = func_0216D83C(p->f08);

    r6 = func_021642B4(r6, r7, t, func_0216D86C(p->f08));
    if (r6 != func_0216D5F8(r4) && (p->f24 == 0 || p->f1C == 2)) {
        if (func_0216D3CC((int)r4) == 1) {
            func_0216D410(r4, func_02197E7C(r6, 0));
            p->state = 0xf;
        }
    } else {
        p->state = 0x10;
    }
    return 0;
}

















int func_021AE6E0(S *s)
{
    void *t = func_021A3074(s->f34);

    if (func_0216D454(t) == 0)
        return 0;
    func_0216D480(t);
    s->f0 = 0x10;
    return 1;
}
















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE708(u32 a, u32 b, u32 c, u32 d)
{
func_0216D480((char *)(((struct Obj09183 *)((u8 *)(a)))->f8));
func_0216E0E8(((struct Obj09183 *)((u8 *)(a)))->f8, 0);
((struct Obj09183 *)((u8 *)(a)))->f0 = 17;
return 1;
}














int func_021AE724(u32 *p) { p[1] = 1; return 0; }



















int func_021AE72C(S_021AE72C *s)
{
    while (d_021D9348[s->f0](s) == 1)
        ;
    if (s->f4 == 1)
        return 1;
    return 0;
}




















/*
 * Addresses are Black-image addresses.
 */
int func_021AE754(u32 a, u32 b, u32 *c)
{
    if (c[0] != 0) {
        if (func_021AE72C((struct S_021AE72C *)c[0]) == 1) {
            func_020307B0((void *)c[0]);
            c[0] = 0;
        }
    }
    if (c[1] != 0) {
        if (func_021AE72C((struct S_021AE72C *)c[1]) == 1) {
            func_020307B0((void *)c[1]);
            c[1] = 0;
        }
    }
    if (c[0] == 0 && c[1] == 0) {
        return 1;
    }
    return 0;
}




















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D5A8 (0x0216D5A8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE79C(u32 a)
{
return func_0216E434(func_0216D5A8(a));
}




















int func_021AE7A8(u32 a, u32 dir, int n, void *p)
{
    Vec3s pos;
    s16 dx;
    s16 dz;
    int i;

    if (n != 0) {
        i = 0;
        func_0216D828(a, &pos);
        dx = func_021641E8(dir);
        dz = func_021641F8(dir);
        pos.x += dx;
        pos.z += dz;
        for (; i < n - 1; i++) {
            if ((func_02163994(a, pos.x, pos.y, pos.z, dir) & ~1) != 0)
                return 1;
            if (p != 0 && func_021AA900(p, (short int *)(&pos)) != 0)
                return 1;
            pos.x += dx;
            pos.z += dz;
        }
        if ((func_02163994(a, pos.x, pos.y, pos.z, dir) & ~1) != 4)
            return 1;
        if (p != 0 && func_021AA900(p, (short int *)(&pos)) != 0)
            return 1;
    }
    return 0;
}




















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A460 (0x0215A460) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE884(u32 a)
{
return func_0215A460(func_0216D5B8((void *)a));
}



















int func_021AE890(u32 a, u32 b)
{
return func_0215A4D8((void *)func_0201296C(func_020120F4((const struct Ctx_021AE66C *)func_02188C80((void *)a))), func_021AE884(b));
}



















void func_021AE8B4(S_021AE72C *s, u32 a, u32 b, u32 c)
{
    s->f4 = b;
    s->f8 = c;
    s->fc = func_0216D5B8((void *)a);
    s->f10 = func_021AE884(a);
    s->f0 = a;
}



















u32 func_021AE8D4(u32 a, u16 b)
{
    u32 out;
    u32 iter;
    u32 h;

    iter = 0;
    h = (u32)func_0216D67C((void *)a);
    while (func_0216DD1C((struct Ctx_021AE66C *)h, (struct Rec **)(&out), &iter) == 1) {
        if (out != a && (u16)(func_021AE79C(out) + 0xFFFF) <= 1 && b == func_021AE884(out)) {
            return out;
        }
    }
    return 0;
}



















int func_021AE930(int a, u32 b)
{
return (int)func_02158768((int)func_02188C80((void *)a), (226 << 4), b, 1);
}



















int func_021AE948(u32 a, u32 b)
{
    u32 k;
    void *p;
    u32 *q;
    u32 *e;

    p = func_0215A5F4((void *)b);
    q = (u32 *)func_02158F58((int)p);
    k = func_02159B10((void *)a, (void *)b);
    if (k == 0) {
        e = (u32 *)func_02159124(p, 0);
    } else if (k == 1) {
        e = (u32 *)func_02159124(p, 1);
    }
    e[6] = func_021AE454((void *)func_0215A5CC((void *)b), q[1], e, k);
    return 0;
}



















int func_021AE994(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    S_021AE72C *p = (S_021AE72C *)func_02159124(x, 0);
    S_021AE72C *q = (S_021AE72C *)func_02159124(x, 1);

    func_0215897C(x, (void *)func_021AE430((u32)func_0215A5DC((void *)b), p->f18, q->f18));
    return 1;
}



















int func_021AE9CC(u32 a, u32 b)
{
    S_021AE72C *p = (S_021AE72C *)func_02159124(func_0215A5F4((void *)b), 0);

    *func_02159AE8((void *)a, (void *)b) = p->f14;
    return 0;
}



















int func_021AE9F0(u32 a, u32 b)
{
    u32 k;
    void *p;
    u16 *out;
    u32 *e;

    p = func_0215A5F4((void *)b);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    e = 0;
    if (k == 0) {
        e = (u32 *)func_02159124(p, 0);
    } else if (k == 1) {
        e = (u32 *)func_02159124(p, 1);
    }
    *out = e ? e[4] : 0;
    return 0;
}



















int func_021AEA3C(u32 a, u32 b)
{
    u32 k;
    void *p;
    u16 *out;
    u32 *e;

    p = func_0215A5F4((void *)b);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    e = 0;
    if (k == 0) {
        e = (u32 *)func_02159124(p, 0);
    } else if (k == 1) {
        e = (u32 *)func_02159124(p, 1);
    }
    *out = e ? func_0216D588((void *)e[0]) : 0;
    return 0;
}


















int func_021AEA8C(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    u32 y;

    func_02158F58((int)x);
    y = func_02158F8C(x);
    *func_02159AE8((void *)a, (void *)b) = func_0215A460(y);
    return 0;
}


















int func_021AEABC(u32 a, u32 b)
{
    void *p;
    u32 x, y, z, w;

    p = func_0215A5F4((void *)b);
    func_02158F8C((unsigned char *)p);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    w = (u32)func_0215A4C8((u32)x);
    if (y == 0 && func_0215A4B4(x) == 1) {
        y = x;
    }
    func_0215897C(p, (void *)func_0216E818((int)func_02158F54(p), ((u32 *)func_02158F58((int)p))[1], w, 0, x, y, z));
    func_021AEDAC(b);
    return 1;
}


















int func_021AEB3C(u32 a, u32 b)
{
    u32 x, y, z, w;
    void *p;

    p = func_0215A5F4((void *)b);
    func_02158F8C((unsigned char *)p);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    w = func_02159B10((void *)a, (void *)b);
    func_0215897C(p, (void *)func_0216E818((int)func_02158F54(p), ((u32 *)func_02158F58((int)p))[1], 1, x, y, z, w));
    func_021AEDAC(b);
    return 1;
}


















int func_021AEBB0(u32 a, u32 b)
{
    u32 h;
    u16 *x, *y, *z;
    u32 v0, v1, v2;

    h = func_02158F8C((unsigned char *)func_0215A5F4((void *)b));
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    if ((u16)func_0215A4B4(func_0215A460(h)) == 0) {
        v0 = 0;
        v1 = 2;
        v2 = 24;
    } else if ((u16)func_0215A4A0(h) == 0) {
        v0 = 3;
        v1 = 5;
        v2 = 6;
    } else {
        v0 = 7;
        v1 = 9;
        v2 = 10;
    }
    *x = v0;
    *y = v1;
    *z = v2;
    return 0;
}


















int func_021AEC1C(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_0215A4C8(x);
    return 0;
}


















/*
 * Compiled 66 of a 68-byte extent: the trailing halfword is an unlabelled
 * follower.
 *
 * Addresses are Black-image addresses.
 */
int func_021AEC40(u32 a, u32 b)
{
    void *x;
    void *y;

    x = func_0215A5DC((void *)b);
    func_0215A5E4((void *)b);
    y = func_0215A5F4((void *)b);
    func_0215897C(y, func_02029AF4(x, func_02029E20(func_0202A230((void *)func_02159B10((void *)a, (void *)b), 1))));
    return 1;
}


















int func_021AEC84(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);

    func_0215897C(x, (void *)func_021BE92C(y, (int)func_0201210C((const struct Ctx_021AE66C *)((void *)y)), 0, 0, 1, 0, 0));
    return 1;
}


















int func_021AECC0(u32 a, u32 b)
{
    u32 x;
    u16 *out;
    u32 v;

    x = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    if (func_0202A230((void *)x, 9)) {
        v = 1;
    } else if (func_0202A230((void *)x, 11)) {
        v = 2;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}
















int func_021AED00(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_0202A230((void *)x, 0xb);
    return 0;
}




















/*
 * The four func_02159B10 results are u16 locals (the callee returns u16):
 * with u32 locals the stack-argument stores for func_0216EAB0 schedule
 * after the r1/r2 setup instead of before it.
 * Addresses are Black-image addresses.
 */
int func_021AED24(u32 a, u32 b)
{
    u32 t;
    void *p;
    u16 x, y, z, w;

    p = func_0215A5F4((void *)b);
    func_02158F8C((unsigned char *)p);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    w = func_02159B10((void *)a, (void *)b);
    t = func_0215A4C8(x);
    if (y == 0 && func_0215A4B4(x) == 1) {
        y = x;
    }
    func_0215897C(p, (void *)func_0216EAB0((void *)((u32)func_02158F54(p)), ((u32 *)func_02158F58((int)p))[1], t, 0, x, y, z, w));
    return 1;
}





















void func_021AEDAC(u32 a)
{
    S_021AE72C *p = (S_021AE72C *)func_02158F58((int)func_0215A5F4((void *)a));
    u32 q = (u32)func_02012F2C(func_0215A5E4((void *)a));

    if (func_02014024(func_02188C9C((u8 *)p->f4)) != 0)
        func_02008DF0((struct Sub02008C20Obj *)q, 0x20);
}





















int func_021AEDE0(u32 a, u32 b)
{
    void *x;
    void *y;

    x = func_0215A5DC((void *)b);
    y = func_0215A5F4((void *)b);
    func_0215897C(y, func_02029984(x, func_02011330((struct Stream *)a)));
    func_02028BA0((u8 *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx_021AE66C *)x)), 2);
    func_02159144(13);
    return 1;
}




















int func_021AEE28(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 z;

    x = func_0215A5DC((void *)b);
    y = func_0215A5F4((void *)b);
    z = (u32)func_02029A04(x, func_02011330((struct Stream *)a), func_02011330((struct Stream *)a));
    func_0215897C(y, (void *)z);
    func_02028BA0((u8 *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx_021AE66C *)x)), 2);
    func_02159144(13);
    return 1;
}




















int func_021AEE78(u32 a, u32 b)
{
    u32 z;
    void *x;
    void *y;

    x = func_0215A5DC((void *)b);
    y = func_0215A5F4((void *)b);
    z = (u32)func_02029A74(x, func_02011330((struct Stream *)a));
    func_0215897C(y, (void *)z);
    func_02028BA0((u8 *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx_021AE66C *)x)), 2);
    func_02159144(13);
    return 1;
}


















int func_021AEEC0(u32 a, u32 b)
{
    func_02011330((struct Stream *)a);
    *func_02159AE8((void *)a, (void *)b) = func_02005F38();
    return 0;
}


















int func_021AEEE0(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5DC((void *)b);
if (func_02005F38(func_0215A5F4((void *)b)) == 0) {
    return 1;
}
return 0;
}


















int func_021AEF00(u32 a)
{
    func_020113D0((char *)a, (int)func_021AEEE0);
    return 1;
}




















int func_021AEF10(u32 a, u32 b)
{
    u32 y, z;
    void *x;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4((const struct Ctx_021AE66C *)x);
    func_0201210C((const struct Ctx_021AE66C *)((void *)x));
    y = func_02012A30((const struct BigObj *)y);
    z = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    func_02028A58((struct SoundSys *)y, z, (u8)func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b))));
    func_02159144(12);
    return 0;
}




















int func_021AEF60(u32 a, u32 b)
{
    u32 y;
    void *x;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4((const struct Ctx_021AE66C *)x);
    func_0201210C((const struct Ctx_021AE66C *)((void *)x));
    y = func_02012A30((const struct BigObj *)y);
    func_02028A58((struct SoundSys *)y, 0x7f, (u8)func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b))));
    func_02159168(12);
    return 0;
}




















int func_021AEFA4(u32 *a, u32 *st)
{
    u32 r = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx_021AE66C *)(*a)));

    switch (*st) {
    case 0:
        func_02028A58((struct SoundSys *)r, 0x7f, 0);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}




















/*
 * .word 0x02029EB5) has no witness outside the range (evidence class: none;
 * arm9 leaf belongs to Ilias, not filed here).
 *
 * Addresses are Black-image addresses.
 */
int func_021AEFD8(u32 a, u32 b)
{
    u32 y, m, q, s;
    void *x;
    void *l;
    void *p;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4((const struct Ctx_021AE66C *)x);
    l = func_0201210C((const struct Ctx_021AE66C *)((void *)x));
    m = func_02012A30((const struct BigObj *)y);
    p = func_0215A5F4((void *)b);
    q = func_02012984((const struct BigObj *)y);
    s = func_02029DF4((void *)y, func_02188C9C(l), q);
    func_0215897C(p, (void *)func_020298A0(x, s, 0x5a, 0x3c));
    func_02028BDC((struct S_021AE72C *)m, 2);
    func_02159168(13);
    return 1;
}




















int func_021AF044(struct Stream *a, u32 b)
{
    u32 y, m, n, q, s;
    void *x;
    void *l;
    void *p;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4((const struct Ctx_021AE66C *)x);
    l = func_0201210C((const struct Ctx_021AE66C *)((void *)x));
    m = func_02012A30((const struct BigObj *)y);
    p = func_0215A5F4((void *)b);
    n = func_02011330(a);
    q = func_02012984((const struct BigObj *)y);
    s = func_02029DF4((void *)y, func_02188C9C(l), q);
    func_0215897C(p, (void *)func_020298A0(x, s, n, 0x3c));
    func_02028BDC((struct S_021AE72C *)m, 2);
    func_02159168(13);
    return 1;
}




















int func_021AF0BC(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x;

    func_020120F4((const struct Ctx_021AE66C *)y);
    func_0201210C((const struct Ctx_021AE66C *)((void *)y));
    x = func_0215A5F4((void *)b);
    func_0215897C(x, func_02029AF4(y, func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)))));
    return 1;
}




















int func_021AF0F8(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, func_020295A4(y, func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)))));
    func_02159144(10);
    return 1;
}




















int func_021AF130(u32 a, u32 b)
{
    u32 u;
    void *x;
    void *p;

    x = func_0215A5DC((void *)b);
    p = func_0215A5F4((void *)b);
    u = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    func_0215897C(p, (void *)func_02029620(x, u, func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)))));
    func_02159168(10);
    return 1;
}




















int func_021AF174(S_021AE72C *s, u32 *st)
{
    u32 x = s->f8;

    func_02158F58(x);
    switch (*st) {
    case 0:
        func_0215897C((void *)x, func_02029620((void *)s->f0, 0, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}




















int func_021AF1B0(u32 a, u32 b, u32 c, u32 d)
{
func_02028BDC((struct S_021AE72C *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)))), 2);
func_02159168(13);
return 0;
}




















int func_021AF1D0(u32 a, u32 b, u32 c, u32 d)
{
func_02028BDC((struct S_021AE72C *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx_021AE66C *)(((struct Obj18089 *)((u8 *)(a)))->f0))), 2);
return 1;
}




















/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
void func_021AF1E8(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88((void *)a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i)) {
            if (func_02006224(i) == 0)
                *p &= ~(1 << i);
        }
    }
}




















void func_021AF21C(u32 a, u32 b)
{
    u8 *p = func_02158F88((void *)a);

    *p |= 1 << func_02006148(b);
}




















int func_021AF23C(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88((void *)a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i)) {
            if (func_02006224(i) == 1)
                return 1;
        }
    }
    *p = 0;
    return 0;
}




















void func_021AF26C(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88((void *)a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i))
            func_020061F8(i);
    }
    *p = 0;
}




















int func_021AF294(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    void *y = func_0215A5F4((void *)b);

    func_021AF1E8((u32)y);
    func_020061E4(x);
    func_021AF21C((u32)y, x);
    return 0;
}




















int func_021AF2BC(u32 a, u32 b, u32 c, u32 d)
{
func_021AF26C((u32)func_0215A5F4((void *)b));
return 0;
}




















int func_021AF2CC(u32 a, u32 b, u32 c, u32 d)
{
if (func_021AF23C((u32)func_0215A5F4((void *)b)) == 0) {
    return 1;
}
return 0;
}




















int func_021AF2E4(u32 a)
{
    func_020113D0((char *)a, (int)func_021AF2CC);
    return 1;
}




















int func_021AF2F4(u32 a, u32 b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, func_02029830(y, func_02011330((struct Stream *)a)));
    return 1;
}




















int func_021AF324(u32 a, u32 b)
{
    u32 y;
    void *x;
    void *p;

    x = func_0215A5DC((void *)b);
    p = func_0215A5F4((void *)b);
    y = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx_021AE66C *)x));
    if (func_02005F38() == 0 && func_020289B8((struct Sys *)y) == 0) {
        func_0215897C(p, func_02029620(x, 0, 6));
        return 1;
    }
    return 0;
}




















int func_021AF370(u32 a)
{
    func_020113D0((char *)a, (int)func_021AF324);
    return 1;
}




















int func_021AF380(u32 a, u32 b)
{
    u32 u, v, h;
    void *p;
    void *x;
    Rec *r;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    u = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    v = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    h = (u32)func_020122C0(x, 0, (void *)func_021AF4E8, 12);
    r = func_020124E8((struct Obj *)h);
    r->a = u;
    r->b = v;
    r->f4 = 0;
    r->f8 = b;
    func_0215897C(p, (void *)h);
    return 1;
}




















int func_021AF3D8(u32 a, u32 b)
{
    u32 u, v, h;
    void *p;
    void *x;
    Rec *r;

    p = func_0215A5F4((void *)b);
    x = func_0215A5DC((void *)b);
    u = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    v = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    h = (u32)func_020122C0(x, 0, (void *)func_021AF4E8, 12);
    r = func_020124E8((struct Obj *)h);
    r->a = u;
    r->b = v;
    r->f4 = 1;
    r->f8 = b;
    func_0215897C(p, (void *)h);
    return 1;
}




















/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A6AC (0x0215A6AC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AF430(u32 a, u32 b, u32 c, u32 d)
{
if (func_02006BD0(func_0215A6AC(b, b, c, d)) == 0) {
    return 1;
}
return 0;
}




















int func_021AF448(u32 a)
{
    func_020113D0((char *)a, (int)func_021AF430);
    return 1;
}




















int func_021AF458(u32 a, u32 b)
{
    u32 x = func_0202B578((u32 *)func_02012134(func_0215A5DC((void *)b)));

    func_0202C0D0((u8 *)x, func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b))));
    return 0;
}




















int func_021AF484(u32 a, u32 b)
{
    u32 x = func_0202B578((u32 *)func_02012134(func_0215A5DC((void *)b)));

    func_0202C0E4((u8 *)x, func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b))));
    return 0;
}




















int func_021AF4B0(u32 a, u32 b)
{
    u32 x = func_0202B578((u32 *)func_02012134(func_0215A5DC((void *)b)));

    *func_02159AE8((void *)a, (void *)b) = func_0202C0F8(x, func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b))));
    return 0;
}




















int func_021AF4E8(u32 a, u32 b, Rec *c)
{
    u32 v, r;

    if (func_02005C64()) {
        return 0;
    }
    if (c->f4) {
        u32 x, y;
        y = c->b;
        x = c->a;
        func_02006CAC((void **)(&v));
        r = func_02006984(x, y, 0x40, 0, 0, 0, 0, (u32)(&v));
    } else {
        r = func_02006984(c->a, c->b, 0x40, 0, 0, 0, 0, 0);
    }
    func_0215A6B8((u32 *)c->f8, r);
    return 1;
}




















int func_021AF544(u32 a, u32 b)
{
    u32 p;
    void *x;
    u32 u, v;
    u16 *h;

    p = func_0215A5CC((void *)b);
    x = func_0201292C(func_0215A5E4((void *)b));
    u = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    v = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    h = func_02159AE8((void *)a, (void *)b);
    *h = func_02007E50(x, u, v, p);
    return 0;
}




















int func_021AF594(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e, f;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    f = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007F1C(d, e, f, c);
    return 0;
}




















int func_021AF5E4(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e, f;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    f = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007E3C(d, e, f, c);
    return 0;
}




















int func_021AF634(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e, f;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    f = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007F68(d, e, f, c);
    return 0;
}




















int func_021AF684(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007FB8(d, e, c);
    return 0;
}




















int func_021AF6C4(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));

    *func_02159AE8((void *)a, (void *)b) = func_021AF750(x);
    return 0;
}




















int func_021AF6E8(u32 a, u32 b)
{
    u32 y = func_0215A5CC((void *)b);
    u32 x = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));

    *func_02159AE8((void *)a, (void *)b) = func_02020FE4((void *)x, 5, y);
    return 0;
}




















int func_021AF71C(u32 a, u32 b)
{
    u32 y = func_0215A5CC((void *)b);
    u32 x = func_02159B10((void *)((u32)((void *)a)), (void *)((u32)((void *)b)));

    *func_02159AE8((void *)a, (void *)b) = func_02020FE4((void *)x, 0xf, y);
    return 0;
}



















int func_021AF750(u32 a)
{
return ((func_02021288(a) << 16) >> 16);
}



















static inline u8 Ctx_ReadByte(Ctx_021AE66C *s)
{
    u8 v = *s->pc;

    s->pc++;
    return v;
}



















int func_021AF75C(Ctx_021AE66C *s, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    u32 y;
    u32 w;

    func_02158F58((int)x);
    y = (u32)func_02012944(func_0215A5E4((void *)b));
    w = (u32)func_02158F74(x);
    func_0201F02C((struct WordSet *)w, Ctx_ReadByte(s), (void *)y);
    return 0;
}

















int func_021AF794(Script *a, u32 b, void (*fn)())
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    a->cur = p + 1;
    fn(x, v, func_02159B10((void *)((u32)a), (void *)((u32)((void *)b))));
    return 0;
}












int func_021AF7C4(Script *a, u32 b) { return func_021AF794(a, b, func_0201EF40); }











int func_021AF7D4(Script *a, u32 b) { return func_021AF794(a, b, func_0201EF4C); }












void func_021AF7E4(Script *a, u32 b)
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 y, n, flag;
    u8 *q;
    a->cur = p + 1;
    y = func_02159B10(a, (void *)b);
    n = func_02159B10(a, (void *)b);
    q = a->cur;
    flag = *q;
    a->cur = q + 1;
    if (n > 1) {
        func_0201EF5C((struct WordSet *)x, v, y);
    } else if (flag != 0) {
        func_0201EF4C((struct WordSet *)x, v, y);
    } else {
        func_0201EF40((struct WordSet *)x, v, y);
    }
}













int func_021AF844(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201EF34((struct WordSet *)w, c, func_020212B0(func_02159B10(s, (void *)b)));
    return 0;
}













int func_021AF878(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201EF34((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}













int func_021AF8A8(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F020((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}













int func_021AF8D8(Script *a, u32 b, void (*fn)())
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    a->cur = p + 1;
    fn(x, v, func_02159B10(a, (void *)b));
    return 0;
}









int func_021AF908(Script *a, u32 b) { return func_021AF8D8(a, b, func_0201EE60); }








int func_021AF918(Script *a, u32 b) { return func_021AF8D8(a, b, func_0201EEC4); }












int func_021AF928(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F14C((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}












int func_021AF958(Script *a, u32 b)
{
    void *c = func_0215A5F4((void *)b);
    void *d = func_0215A5E4((void *)b);
    u32 x = (u32)func_02158F74(c);
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EE84((void *)x, v, func_0201AB28(func_02012934((void *)d), e));
    return 0;
}












int func_021AF9A4(Script *a, u32 b)
{
    void *c = func_0215A5F4((void *)b);
    void *d = func_0215A5E4((void *)b);
    u32 x = (u32)func_02158F74(c);
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EEF4((void *)x, v, func_0201AB28(func_02012934((void *)d), e));
    return 0;
}












int func_021AF9F0(Script *a, u32 b)
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EE84((void *)x, v, func_021C34F8(func_02188D50(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)))), e));
    return 0;
}












int func_021AFA38(Script *a, u32 b)
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    func_0201EEF4((void *)x, v, func_021C34F8(func_02188D50(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)))), e));
    return 0;
}












int func_021AFA80(Script *a, u32 b)
{
    u32 x = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 *p = a->cur;
    u32 v = *p;
    u32 e, f;
    a->cur = p + 1;
    e = func_02159B10(a, (void *)b);
    f = func_02159B10(a, (void *)b);
    func_0201EFA4((struct WordSet *)x, v, e, f, 0, 1);
    return 0;
}












int func_021AFAC8(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F158((struct WordSet *)w, c, func_02013E4C(func_02159B10(s, (void *)b)));
    return 0;
}












int func_021AFAFC(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201EFC8((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}












int func_021AFB2C(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F048((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}











int func_021AFB5C(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F198((struct WordSet *)w, c, (u8)func_02159B10(s, (void *)b));
    return 0;
}











int func_021AFB90(Ctx_021AE66C *s, u32 b)
{
    u32 w = (u32)func_02158F74(func_0215A5F4((void *)b));
    u8 c = Ctx_ReadByte(s);

    func_0201F1B0((struct WordSet *)w, c, func_02159B10(s, (void *)b));
    return 0;
}










int func_021AFBC4(Ctx_021AE66C *s, u32 b)
{
    u8 c = Ctx_ReadByte(s);
    u32 x = func_02159B10(s, (void *)b);

    func_0201F184(func_02158F74(func_0215A5F4((void *)b)), c, x);
    return 0;
}










int func_021AFBEC(Ctx_021AFBEC *a0, int a1, void (*fn)())
{
    u8 *p = a0->cur;
    int b = *p;
    int t;

    a0->cur = p + 1;
    t = (int)func_02159B10(a0, (void *)a1);
    fn(func_02158F74(func_0215A5F4((void *)a1)), b, (u8)t);
    return 0;
}






int func_021AFC18(Ctx_021AFBEC *a, int b) { return func_021AFBEC(a, b, func_0201F0F8); }





int func_021AFC28(Ctx_021AFBEC *a, int b) { return func_021AFBEC(a, b, func_0201F124); }










int func_021AFC38(Ctx_021AFC38 *a0, int a1)
{
    void *t = func_0215A5F4((void *)a1);
    void *h;
    int r;
    u8 *p;
    int b;

    h = func_0200C0F0(func_02012EBC(func_0215A5E4((void *)a1)));
    r = (int)func_02158F74(t);
    p = a0->pc;
    b = *p;
    a0->pc = p + 1;
    func_0201EFA4((struct WordSet *)r, b, func_0200C1DC(h), 9, 1, 1);
    return 0;
}










int func_021AFC88(Ctx_021AFC38 *a0, int a1)
{
    void *t = func_0215A5F4((void *)a1);
    void *h;
    int r;
    u8 *p;
    int b;

    h = func_0200C0F0(func_02012EBC(func_0215A5E4((void *)a1)));
    r = (int)func_02158F74(t);
    p = a0->pc;
    b = *p;
    a0->pc = p + 1;
    func_0201EFA4((struct WordSet *)r, b, func_0200C1C4(h), 9, 1, 1);
    return 0;
}










int func_021AFCD8(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C((const struct Ctx_021AE66C *)h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104((const struct Ctx_021AFC38 *)h);
    func_02012374((struct Evt *)w, func_02184D38(h, a, b, arr, e, 0));
    return 1;
}










int func_021AFD44(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C((const struct Ctx_021AE66C *)h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104((const struct Ctx_021AFC38 *)h);
    func_02012374((struct Evt *)w, func_02185534(h, a, b, arr, e));
    return 1;
}










int func_021AFDAC(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    void *e;
    int f;
    void *g;
    int w;
    struct Rec *r;
    int out[3];
    int arr[3];
    int buf[3];

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C((const struct Ctx_021AE66C *)h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_020120F4((const struct Ctx_021AE66C *)h);
    f = func_02012844(e);
    g = (void *)func_0201296C(e);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)buf);
    r = func_0216282C((struct Ctx_021AFC38 *)f, (void *)g, buf, 9);
    if (r != 0)
        func_02162A6C((int)r, (int)out);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104((const struct Ctx_021AFC38 *)h);
    func_02012374((struct Evt *)w, func_02184E40(h, a, out, b, arr));
    g = func_021A3074(func_02188CB4((void *)a));
    func_021BB578(func_02188CD0(a), (int)g, 0, 1);
    return 1;
}










int func_021AFE64(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C((const struct Ctx_021AE66C *)h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104((const struct Ctx_021AFC38 *)h);
    func_02012374((struct Evt *)w, func_02185050(h, a, b, arr, e));
    return 1;
}










int func_021AFECC(u32 a, u32 b)
{
    u32 p = (u32)func_02158F54(func_0215A5F4((void *)b));
    void *q = func_0201210C((const struct Ctx_021AE66C *)((void *)p));
    u32 r = func_02012104((const struct Ctx_021AFC38 *)p);

    func_02012374((struct Evt *)r, (struct Evt **)func_021850A8(p, q));
    return 1;
}










int func_021AFEFC(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C((const struct Ctx_021AE66C *)h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    f = func_02011330((struct Stream *)a0);
    func_021A3074(func_02188CB4((void *)a));
    arr[0] = c << 16;
    arr[1] = d << 16;
    arr[2] = e << 16;
    w = func_02012104((const struct Ctx_021AFC38 *)h);
    func_02012374((struct Evt *)w, func_021854B0(h, a, b, arr, f));
    return 1;
}










int func_021AFF7C(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int w;
    int loc[2];

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C((const struct Ctx_021AE66C *)h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    f = func_02011330((struct Stream *)a0);
    w = func_02012104((const struct Ctx_021AFC38 *)h);
    func_021BB3E8(func_02188C5C(a), b, c, d, e, loc, 0x15);
    func_02012374((struct Evt *)w, func_02184D90(h, a, b, (const Q_021AFC38 *)loc, f, 0));
    return 1;
}










int func_021B0000(int a0, int a1)
{
    struct Ctx_021AFC38 *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int w;
    int loc[2];

    h = func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C((const struct Ctx_021AE66C *)h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    f = func_02011330((struct Stream *)a0);
    w = func_02012104((const struct Ctx_021AFC38 *)h);
    func_021BB3E8(func_02188C5C(a), b, c, d, e, loc, 0x15);
    func_02012374((struct Evt *)w, func_02184DE8(h, a, b, (const Q_021B0000 *)loc, f, 0));
    return 1;
}










/*
 * State 2 is a nested switch on func_02190C78's result (case 0, case 2
 * empty, default) with the flag store and the state increment written out
 * in each arm: the compiler cross-jumps the default arm into case 0's
 * tail, which is why `movs r1,#1; b` sits after the shared increment.
 * An if/else chain puts that arm inline. The listing extent includes two
 * bytes of padding.
 * Addresses are Black-image addresses.
 */
int func_021B0084(u32 a0, int *st, Ctx_021AFBEC *c)
{
    func_0215A5F4((void *)c->a0);
    switch (*st) {
    case 0:
        func_0215A684((int *)c->a0, 8);
        (*st)++;
    case 1:
        if (func_0215A690((char *)c->a0) == 1) {
            c->h = (u32)func_02190BE4((u16 *)func_02188C54(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)c->a0)))), 0);
            (*st)++;
        }
        break;
    case 2:
        switch (func_02190C78((struct Handle *)c->h)) {
        case 0:
            *c->flag = 0;
            (*st)++;
            break;
        case 2:
            break;
        default:
            *c->flag = 1;
            (*st)++;
            break;
        }
        break;
    case 3:
        func_021909BC((void *)c->h);
        return 1;
    }
    return 0;
}










u32 func_021B010C(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, func_021B0084, 0xc);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}










int func_021B0130(u32 a, u32 b)
{
    u16 *r = func_02159AE8((void *)a, (void *)b);
    void *x = func_0215A5F4((void *)b);

    func_0215897C(x, (void *)func_021B010C((u32)func_0215A5DC((void *)b), b, (u32)r));
    return 1;
}










int func_021B015C(int a0, int *st, Ctx_021B015C *c)
{
    int r;

    switch (*st) {
    case 0:
        func_0215A684((int *)c->h, 8);
        (*st)++;
    case 1:
        if (func_0215A690((char *)c->h) == 1) {
            func_0215A864((int *)c->h);
            (*st)++;
        }
        break;
    case 2:
        if (c->flag != 0)
            r = func_0215A990((u8 *)c->h);
        else
            r = func_0215A954((u8 *)c->h);
        if (r == 1)
            return 1;
        break;
    }
    return 0;
}










u32 func_021B01B8(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, func_021B015C, 8);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}










int func_021B01DC(Ctx_021B015C *c, u32 b)
{
    u8 *q;
    u32 v0, v1, v2, v3, r;
    void *t0;
    void *t1;

    t0 = func_0215A5F4((void *)b);
    t1 = func_0215A5E4((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = func_02159B10(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)func_02158FE0(t0, t1, func_02011330((struct Stream *)c));
    func_0215A77C(b, v0, v1, v2, v3, 0, r, (u32)func_02158F74(t0), 0);
    return 1;
}










int func_021B024C(Ctx_021B015C *c, u32 b)
{
    u8 *q;
    u32 v2, r;
    void *t0;
    void *t1;
    u8 v0, v1, v3;

    t0 = func_0215A5F4((void *)b);
    t1 = func_0215A5E4((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = func_02159B10(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)func_02158FE0(t0, t1, func_02011330((struct Stream *)c));
    func_0215A77C(b, v0, v1, v2, v3, 0, r, (u32)func_02158F74(t0), func_0215A60C((u8 *)b));
    return 1;
}










int func_021B02C8(Ctx_021B015C *c, u32 b)
{
    u8 *q;
    u32 v2, r;
    void *t0;
    void *t1;
    u8 v0, v1, v3;

    t0 = func_0215A5F4((void *)b);
    t1 = func_0215A5E4((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = func_02159B10(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)func_02158FE0(t0, t1, func_02011330((struct Stream *)c));
    func_0215A77C(b, v0, v1, v2, v3, 1, r, (u32)func_02158F74(t0), func_0215A60C((u8 *)b));
    return 1;
}










int func_021B0344(u32 a, u32 b)
{
    u32 x, y, z;
    void *t;

    t = func_0215A5F4((void *)b);
    x = func_02011330((struct Stream *)a);
    y = func_02011330((struct Stream *)a);
    z = func_02159B10((void *)a, (void *)b);
    func_0215A7F0((short unsigned int *)b, x, y, z, (struct U16Vec *)func_02158F78(t), (void *)func_02158F7C(t));
    return 0;
}










int func_021B0394(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4((void *)b), (void *)func_021B01B8((u32)func_0215A5DC((void *)b), b, 0));
return 1;
}










int func_021B03BC(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4((void *)b), (void *)func_021B01B8((u32)func_0215A5DC((void *)b), b, 0));
return 1;
}










void func_021B03E4(u32 a, u32 b)
{
    u32 x, r4, r5;
    u32 *p;

    r5 = 1;
    if (func_02159190(1)) {
        func_02191164((void *)func_0215A61C(a));
        return;
    }
    p = (u32 *)func_02158F58((int)func_0215A5F4((void *)a));
    x = func_0215A60C((u8 *)a);
    r4 = b;
    if (b == 1) {
    } else if (b == 2) {
        r5 = 0x13;
    } else if (b == 0) {
        switch (func_0215A654((u8 *)a)) {
        case 1:
        case 3:
        case 5:
            r4 = r5;
            break;
        case 2:
        case 4:
        case 6:
            r5 = 0x13;
            r4 = 2;
            break;
        case 7:
            r5 = 0x13;
            r4 = 2;
            break;
        default:
            r5 = 0x13;
            r4 = 2;
            break;
        }
    } else {
        r5 = 0x13;
        r4 = 2;
    }
    r5 = (u32)func_02190FA0((struct Fx *)(*p), x, r5);
    func_0215A660((u8 *)a, r4);
    func_0215A614((u8 *)a, r5);
    func_02159144(1);
}










void func_021B0480(u32 a)
{
    u32 t;

    if (func_02159190(1)) {
        func_02191008(func_0215A61C(a));
        t = func_0215A630((u8 *)a);
        if (t) {
            func_0202F038((void *)t);
            func_0215A624((u8 *)a, 0);
        }
        func_0215A614((u8 *)a, 0);
        func_02159168(1);
    }
}










int func_021B04C0(u32 a, u32 b, u32 c, u32 d)
{
if (func_021910C0((u32 *)func_0215A61C(b)) == 1) {
    return 1;
}
return 0;
}










int func_021B04D8(u32 a, u32 b)
{
    u32 x, y;
    void *t;

    t = func_0215A5F4((void *)b);
    x = func_02159B10((void *)a, (void *)b);
    func_021B03E4(b, (u8)func_02011330((struct Stream *)a));
    y = func_021B162C(b, (u32)t, x);
    func_02191084((struct P *)func_0215A61C(b), 0, 0, y);
    func_020113D0((char *)a, (u32)func_021B04C0);
    return 1;
}










int func_021B0530(u32 a, u32 b)
{
    u32 s, x, y, z, w;
    void *t;

    t = func_0215A5F4((void *)b);
    s = func_02158F78(t);
    x = func_02159B10((void *)a, (void *)b);
    func_021B03E4(b, (u8)func_02011330((struct Stream *)a));
    y = func_0215A60C((u8 *)b);
    z = (u32)func_02158F74(t);
    w = func_02158F7C(t);
    func_02045CAC((struct MsgBank *)y, x, (void *)w);
    func_0201F250((struct WordSet *)z, (void *)s, (void *)w);
    y = func_0215A61C(b);
    func_02191164((void *)y);
    func_02191184((struct Q_021B0000 *)y, 0, 0, s);
    return 0;
}









int func_021B05AC(u32 a, u32 b)
{
    u32 r6, r4, t0;

    r6 = func_02188C84(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b))));
    r4 = func_02159B10((void *)a, (void *)b);
    if (!func_02159190(1)) {
        return 0;
    }
    t0 = func_0215A630((u8 *)b);
    if (t0) {
        func_0202F038((void *)t0);
        func_0215A624((u8 *)b, 0);
    }
    if (r4 == 0) {
        u32 t = func_021911B4((u8 *)func_0215A61C(b));
        func_0215A624((u8 *)b, func_0202EE30(func_020056BC(), t, 0xf, 0x10, r6));
    }
    return 0;
}









int func_021B0624(u32 a, u32 b, u32 c, u32 d)
{
func_021B0480(b);
return 0;
}












/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0630(u8 *p)
{
    func_021B0480(((struct Obj18090 *)p)->f4);
    return 1;
}












int func_021B063C(u32 a, u32 b)
{
    u16 v1, v2;
    void *t;
    void *y;
    u32 x, m, w, r6, r7, h, z, obj, g;

    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    t = func_0215A5DC((void *)b);
    x = (u32)func_020120F4((const struct Ctx_021AE66C *)t);
    func_020127A4((struct SaveBlock *)x);
    y = func_0201210C((const struct Ctx_021AE66C *)t);
    m = func_02188C54(y);
    w = func_02188D48(y);
    t = func_0215A5F4((void *)b);
    r6 = (u32)func_02158F74(t);
    r7 = func_02158F7C(t);
    h = func_02188C84(y);
    z = (u32)func_02045B38(0, 3, 0x9e, h);
    h = (u32)func_020457B0(0x80, h);
    g = func_0200C274(func_02012F08((int *)x));
    if (w != 0)
        func_02190728((void *)w);
    obj = (u32)func_02190708((struct Fx *)m, z, (u16)(v1 - 9), (u16)v2, 9, 2);
    func_02188D4C(y, obj);
    func_0201EFA4((struct WordSet *)r6, 2, g, 7, 1, 1);
    func_02045CAC((struct MsgBank *)z, 1, (void *)r7);
    func_0201F250((struct WordSet *)r6, (void *)h, (void *)r7);
    func_02190758(obj, 0, 0, h);
    func_02045808((struct U16Vec *)h);
    func_02045C04((struct Rec *)z);
    return 0;
}












int func_021B0730(u32 a, u32 b)
{
    u32 x, r5, r6, r7, r4, z;
    void *y;
    void *t;

    t = func_0215A5DC((void *)b);
    x = (u32)func_020120F4((const struct Ctx_021AE66C *)t);
    func_020127A4((struct SaveBlock *)x);
    y = func_0201210C((const struct Ctx_021AE66C *)t);
    r5 = func_02188D48(y);
    t = func_0215A5F4((void *)b);
    r6 = (u32)func_02158F74(t);
    r7 = func_02158F7C(t);
    r4 = func_02188C84(y);
    z = (u32)func_02045B38(0, 3, 0x9e, r4);
    r4 = (u32)func_020457B0(0x80, r4);
    func_0201EFA4((struct WordSet *)r6, 2, func_0200C274(func_02012F08((int *)x)), 7, 1, 1);
    func_02045CAC((struct MsgBank *)z, 1, (void *)r7);
    func_0201F250((struct WordSet *)r6, (void *)r4, (void *)r7);
    func_02190788((u8 *)r5);
    func_02190758(r5, 0, 0, r4);
    func_02045808((struct U16Vec *)r4);
    func_02045C04((struct Rec *)z);
    return 0;
}












int func_021B07E0(u32 a, u32 b)
{
    void *x = func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)));
    u32 y = func_02188D48(x);

    if (y != 0) {
        func_02190728((void *)y);
        func_02188D4C(x, 0);
    }
    return 0;
}










/*
 * The quotient is written back into z (the address-taken output local)
 * rather than a fresh q: with a separate local the divisor 12 and the
 * table stride 12 pool into r6 across the _u32_div_f call.
 */
void func_021B0808(const VecFx32 *src, VecFx32 *out, void *cam, int unused)
{
    VecFx32 pos;
    VecFx32 c;
    VecFx32 d;
    VecFx32 e;
    VecFx32 f;
    VecFx32 b;
    VecFx32 a;
    u32 x;
    u32 z;
    u32 t;
    u32 r;

    pos = *src;
    func_02048AD0(cam);
    func_02048B30(cam, &a);
    func_02048AE8(cam, &b);
    func_0207CA00(&a, &b, &c);
    d = c;
    d.y = r = 0;
    func_0207CCA4(&d, &d);
    func_0207CAE8(&d, &d_021D9390, &e);
    func_0207CAE8(&c, &e, &f);
    func_0207CCA4(&f, &f);
    pos.x += f.x;
    pos.y += f.y;
    pos.z += f.z;
    func_0206DF3C(&pos, &x, &z);
    t = x >> 3;
    if (t < 10) {
        r = 0;
    } else if (t >= 10 && t <= 15) {
        r = 1;
    } else if (t >= 16 && t < 22) {
        r = 2;
    } else {
        r = 3;
    }
    z = (z >> 3) / 12;
    if (r < 4 && z < 2) {
        *out = d_021D939C[z][r];
    } else {
        VecFx32 zero = {0, 0, 0};
        *out = zero;
    }
}









void func_021B090C(M *a, int b)
{
    V v1, v2, v3;
    M43 m1;
    M m2;

    func_02048AE8((void *)b, (VecFx32 *)&v1);
    func_02048B0C(b, &v2);
    func_02048B30((void *)b, (VecFx32 *)&v3);
    func_0207BCA0(&v1, &v2, &v3, &m1);
    func_02082B60(&m1, &m2);
    func_0207B0A4(&m2, &m2);
    func_0207B51C(a, &m2, a);
}













void func_021B0960(int a, VecFx32 *p, int q, int r3, u8 e)
{
    int i = 0;
    int j = 0;

    switch (e) {
    case 3:
        i = 1;
        break;
    case 4:
        i = 1;
        j = 1;
        break;
    case 5:
        i = 2;
        break;
    case 6:
        i = 2;
        j = 1;
        break;
    case 0:
    case 1:
    case 2:
        func_021B0808((const VecFx32 *)a, p, (void *)q, r3);
        func_021B090C((M *)p, q);
        return;
    }
    *p = d_021D939C[j][i];
    func_021B090C((M *)p, q);
}













void func_021B09D8(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_021B0960(a, (VecFx32 *)b, c, d, e);
}












void func_021B09EC(int sel, int *a, int *b)
{
    *a = 0;
    *b = 0;
    switch (sel) {
    case 3:
        *b = 7;
        break;
    case 4:
        *a = 1;
        *b = 5;
        break;
    case 5:
        *b = 8;
        break;
    case 6:
        *a = 1;
        *b = 6;
        break;
    case 2:
        *a = 1;
        break;
    case 1:
        break;
    case 0:
        *a = 1;
        *b = 2;
        break;
    }
}













int func_021B0A40(u32 a, Q *q)
{
    T t;
    int r = 2;

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&t);
    if (q->f8 < t.c)
        r = 1;
    return r;
}












/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A614 (0x0215A614) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0A60(u32 a, u32 b, u32 c, u32 d)
{
if (func_021912F8(func_0215A61C(b)) == 1) {
    func_0215A614((u8 *)b, 0);
    func_02159168(2);
    return 1;
}
return 0;
}












void func_021B0A88(u32 a, u32 b)
{
    if (func_02159190(2) != 0) {
        func_021912D8(func_0215A61C(b));
        func_020113D0((char *)a, (int)func_021B0A60);
    }
}











void func_021B0AB0(u32 a)
{
    u32 id = 2;

    if (func_02159190(id)) {
        func_0219131C(func_0215A61C(a));
        func_0215A614((u8 *)((u32)((u8 *)a)), 0);
        func_02159168(id);
    }
}











void func_021B0ADC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_0215A614((u8 *)((u32)((u8 *)a)), (u32)func_0219129C((u8 *)b, c, d, e, f, g));
    func_02159144(2);
}











void func_021B0B08(void *a, int b)
{
    void *t = func_0215A5EC(a);
    S_021B0960 *s = (S_021B0960 *)func_0215A63C(a);
    void *o = func_0216DE94(t, s->id);
    V v;
    if (o != 0) {
        func_0216D5F8(o);
        func_0216D88C(o, (struct VecFx32 *)&v);
        if (b == 1 || v.x != s->a.x || v.y != s->a.y || v.z != s->a.z) {
            int p, q;
            s->a = v;
            p = (int)func_02188C58(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC(a))));
            q = func_0218EC2C((void *)p);
            func_021B0960((int)(&s->a), (VecFx32 *)(&s->b), q, p, func_0215A66C(a));
        }
        s->sum.x = s->a.x + s->b.x;
        s->sum.y = s->a.y + s->b.y;
        s->sum.z = s->a.z + s->b.z;
    }
}










int func_021B0BAC(u32 b, u16 id, u16 c, u16 d, u16 e, int f)
{
    u32 s28;
    void *o;
    u32 *q;
    u32 t, m20, m1c, r7, r18, r5, h;
    int sel;
    S_021B0BAC *s;
    V v;
    int oa, ob;

    sel = e;
    o = func_0215A5F4((void *)b);
    s28 = func_0215A60C((u8 *)b);
    q = (u32 *)func_02158F58((int)o);
    t = (u32)func_0215A5EC((void *)b);
    m20 = (u32)func_0216DE94((void *)t, 0xff);
    m1c = (u32)func_0216DE94((void *)t, id);
    if (m1c == 0) {
        return 0;
    }
    r7 = func_02158F78(o);
    r18 = (u32)func_02158F74(o);
    r5 = func_02158F7C(o);
    if (c == 0x400) {
        func_02045CAC((struct MsgBank *)s28, d, (void *)r5);
    } else {
        h = (u32)func_02045B38(0, 3, c, func_0215A5CC((void *)b));
        func_02045CAC((struct MsgBank *)h, d, (void *)r5);
        func_02045C04((struct Rec *)h);
    }
    func_0201F250((struct WordSet *)r18, (void *)r7, (void *)r5);
    s = (S_021B0BAC *)func_0215A63C((u8 *)b);
    if (func_02159190(2) != 0) {
        func_02191348((u32 *)func_0215A61C(b), r7);
    } else {
        func_02082BCC(s, 0, 0x28);
        s->id = id;
        if (e == 0) {
            func_0215A654((u8 *)b);
            func_0216D88C((const struct Actor *)m1c, (struct VecFx32 *)&v);
            sel = func_021B0A40(m20, (struct Q *)(&v));
        }
        func_021B09EC(sel, &oa, &ob);
        s->flag = oa;
        func_0215A660((u8 *)b, (u8)sel);
        func_0215A678((u8 *)b, e);
        func_021B0B08((void *)b, 1);
        func_021B0ADC(b, *q, oa, (u32)(&s->sum), r7, f, ob);
    }
    return 1;
}










int func_021B0CEC(int a, int b)
{
    u32 t;

    t = func_0215A61C(b);
    func_021B0B08((void *)b, 0);
    b = 0;
    if (func_02191388((u32 *)t) == 1) {
        b = 1;
    }
    return b;
}









int func_021B0D14(int a, int b)
{
    u16 v0, v1, v2, v3, v4;
    v0 = func_02159B10((void *)a, (void *)b);
    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    v4 = func_02159B10((void *)a, (void *)b);
    if (func_021B0BAC(b, v2, v0, v1, v3, v4) == 1) {
        func_020113D0((char *)a, (int)func_021B0CEC);
        return 1;
    }
    return 0;
}









int func_021B0D74(int a, int b)
{
    void *o;
    u16 v0, v1, v2, v3;
    unsigned char f;
    o = func_02158F90(func_0215A5F4((void *)b));
    v0 = func_02159B10((void *)a, (void *)b);
    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    if (o == 0) {
        return 1;
    }
    f = func_0216D588(o);
    if (func_021B0BAC(b, f, v0, v1, v2, v3) == 1) {
        func_020113D0((char *)a, (int)func_021B0CEC);
        return 1;
    }
    return 0;
}








int func_021B0DF0(int a, int b)
{
    u16 v0, v1, v2, v3, v4, v5;
    v0 = func_02159B10((void *)a, (void *)b);
    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    v4 = func_02159B10((void *)a, (void *)b);
    v5 = func_02159B10((void *)a, (void *)b);
    if (func_02008550((const struct Sub0200852CObj *)((char *)func_020127A4((struct SaveBlock *)(func_0215A5E4((void *)b))) + 0x20))) {
        v1 = v2;
    }
    if (func_021B0BAC(b, v3, v0, v1, v4, v5) == 1) {
        func_020113D0((char *)a, (int)func_021B0CEC);
        return 1;
    }
    return 0;
}









int func_021B0E74(int a, int b)
{
    u16 v0, v2, v3, v4, v5;
    v0 = func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    v4 = func_02159B10((void *)a, (void *)b);
    v5 = func_02159B10((void *)a, (void *)b);
    if (func_021B0BAC(b, v3, v0, v2, v4, v5) == 1) {
        func_020113D0((char *)a, (int)func_021B0CEC);
        return 1;
    }
    return 0;
}







/*
 * Calls func_021B0A88(a, b) and returns 0x1.
 */
/*
 * Calls func_021B0A88() and returns 0x1.
 */
u32 func_021B0EDC(u32 a, u32 b)
{
    func_021B0A88(a, b);

    return 0x1;
}










int func_021B0EE8(u8 *p)
{
    func_021B0AB0(((struct Obj18091 *)p)->f4);
    return 1;
}









int func_021B0EF4(void *a, int b)
{
    void *o;
    unsigned char **q;
    int k0, k1, k2, m, r, flag;
    int y;
    void *x;
    void *z;
    S_021B0EF4 *s;
    V3_021B0D14 v;

    o = func_0215A5F4((void *)b);
    q = (unsigned char **)func_02158F58((int)o);
    k0 = func_02159B10(a, (void *)b);
    k1 = func_02159B10(a, (void *)b);
    k2 = func_02159B10(a, (void *)b);
    m = func_02158F78(o);
    if (func_02159190(2) != 0) {
        return 1;
    }
    func_0202A310(k0, k1, (void *)m, func_0215A5CC((void *)b));
    if (func_0216DE94(func_0215A5EC((void *)b), k2) == 0) {
        k2 = 0xff;
    }
    s = (S_021B0EF4 *)func_0215A63C((u8 *)b);
    flag = 0;
    func_02082BCC(s, 0, 0x28);
    s->id = k2;
    x = func_02188CB4((struct Obj00020 *)q[1]);
    y = (int)func_0215A5EC((void *)b);
    z = func_021A3074((void *)x);
    func_0216D88C(func_0216DE94((void *)y, s->id), (struct VecFx32 *)&v);
    r = func_021B0A40((u32)z, (Q *)((struct Q *)(&v)));
    if (r != 1) {
        flag = 1;
    }
    s->flag = flag;
    func_021B0B08((void *)b, 1);
    func_021B0ADC(b, (u32)(*q), flag, (u32)(&s->sum), m, 0, 0);
    func_0215A660((u8 *)b, r);
    func_020113D0(a, (int)func_021B0CEC);
    return 1;
}









int func_021B0FF0(u32 a, u32 b, u32 c, u32 d)
{
if (func_021916E0((u32 *)func_0215A61C(b)) == 1) {
    return 1;
}
return 0;
}









int func_021B1008(void *a, int b, int c)
{
    void *o;
    int n, r, t, m;
    int *q;
    u8 *p;
    o = func_0215A5F4((void *)b);
    q = (int *)func_02158F58((int)o);
    t = func_02159B10(a, (void *)b);
    p = *(u8 * *)&((struct Obj12833 *)a)->f14;
    n = *p;
    *(u8 * *)&((struct Obj12833 *)a)->f14 = p + 1;
    r = 1;
    m = func_021B162C(b, (u32)o, t);
    if (n != 1) {
        r = 0x13;
    }
    if (func_02159190(3) != 0) {
        r = func_0215A61C(b);
        func_021915EC((struct R *)r);
    } else {
        r = func_02191558(*q, 0, c, 1, r, 0x1e, 4);
        func_0215A614((u8 *)b, r);
    }
    func_021916A8((struct R *)r, 8, 0, m);
    func_02159144(3);
    func_020113D0(a, (int)func_021B0FF0);
    return 1;
}









void func_021B10A4(void *p)
{
    int n = 3;
    if (func_02159190(3) != 0) {
        func_021915B4((void *)func_0215A61C((int)p));
        func_0215A614(p, 0);
        func_02159168(n);
    }
}



int func_021B10D0(void *a, int b) { return func_021B1008(a, b, 0); }


int func_021B10DC(void *a, int b) { return func_021B1008(a, b, 1); }
















int func_021B10E8(u32 a, u32 b, u32 c, u32 d)
{
func_021B10A4((void *)b);
return 0;
}
















int func_021B10F4(u8 *p)
{
    func_021B10A4((void *)(((struct Obj18092 *)p)->f4));
    return 1;
}
















int func_021B1100(void *a, u32 b)
{
    u32 h, y, z, w;
    void *o;
    u16 x1, x2;
    u16 **q;
    int k0, k1;
    u8 buf[2];
    u8 t;

    o = func_0215A5F4((void *)b);
    q = (u16 **)func_02158F58((int)o);
    x1 = func_02011330(a);
    k0 = func_02159B10(a, (void *)b);
    k1 = func_02159B10(a, (void *)b);
    x2 = func_02011330(a);
    buf[0] = 2;
    h = (u32)func_020457B0(0x40, func_0215A5CC((void *)b));
    y = func_0215A60C((u8 *)b);
    z = (u32)func_02158F74(o);
    w = func_02158F7C(o);
    func_02045CAC((struct MsgBank *)y, x1, (void *)w);
    func_0201F250((struct WordSet *)z, (void *)h, (void *)w);
    func_02191830((struct Q *)(*q), h, &buf[1], &buf[0]);
    t = buf[1];
    if (k0 + t > 0x1f) {
        k0 = (u16)(0x1f - t);
    }
    if (k1 + buf[0] > 0x18) {
        k1 = 4;
        buf[0] = k1;
    }
    func_021918DC(*q, h, x2, k0, k1, t, buf[0]);
    func_02045808((struct U16Vec *)h);
    func_02159144(5);
    return 0;
}
















int func_021B11D8(u32 a, u32 b)
{
    u32 *p = (u32 *)func_02158F58((int)func_0215A5F4((void *)b));

    func_0219196C(*p, func_02011330((struct Stream *)a));
    if (func_021919AC((u8 *)(*p)) == 0) {
        func_02159168(5);
    }
    return 0;
}
















void func_021B120C(u32 a)
{
    u32 id = 5;

    if (func_02159190(id)) {
        func_02191978((struct P *)(*((u32 *)func_02158F58((int)func_0215A5F4((void *)a)))));
        func_02159168(id);
    }
}
















int func_021B1234(u8 *p)
{
    func_021B120C(((struct Obj18093 *)p)->f4);
    return 1;
}
















int func_021B1240(int a, int b)
{
    u32 x = func_02158F78(func_0215A5F4((void *)b));

    if (func_02191BE8((u32 *)func_0215A61C(b), x) == 1) {
        return 1;
    }
    return 0;
}
















void func_021B1268(void *p)
{
    void *q = func_0215A5F4(p);
    void *r;
    if (func_02159190(4) != 0) {
        func_02191B14((void *)func_0215A61C((int)p));
        r = (void *)func_02158F84(q);
        func_02158F80(q, 0);
        if (r != 0) {
            func_0201D83C(r);
        }
        func_0215A614(p, 0);
        func_02159168(4);
    }
}
















int func_021B12B0(int a, unsigned char *b)
{
    void *o;
    int s0, s1, s2;
    int *q;
    int x, y, z;
    o = func_0215A5F4((void *)b);
    s0 = func_02011330((struct Stream *)a);
    s1 = func_02011330((struct Stream *)a);
    q = (int *)func_02158F58((int)o);
    s2 = func_0215A60C(b);
    func_0215A614(b, func_02191A04(*q, s1));
    x = func_02158F78(o);
    y = (int)func_02158F74(o);
    z = func_02158F7C(o);
    func_02045CAC((struct MsgBank *)s2, s0, (void *)z);
    func_0201F250((struct WordSet *)y, (void *)x, (void *)z);
    func_020113D0((char *)a, (int)func_021B1240);
    func_02159144(4);
    return 1;
}
















int func_021B1334(int a, unsigned char *b)
{
    void *o;
    int *q, *q2;
    int s0, s1, s2, h, m;
    int x, y, z;
    o = func_0215A5F4((void *)b);
    q = (int *)func_02158F58((int)o);
    s0 = func_02011330((struct Stream *)a);
    s1 = func_02011330((struct Stream *)a);
    h = func_02188C84((unsigned char *)q[1]);
    q2 = (int *)func_02158F58((int)o);
    s2 = func_0215A60C(b);
    m = (int)func_0201D7EC(0x17, 4, 0, 0, h);
    func_02158F80(o, m);
    func_0215A614((u8 *)b, (u32)func_02191A10((u16 *)(*q2), s1, m));
    x = func_02158F78(o);
    y = (int)func_02158F74(o);
    z = func_02158F7C(o);
    func_02045CAC((struct MsgBank *)s2, s0, (void *)z);
    func_0201F250((struct WordSet *)y, (void *)x, (void *)z);
    func_020113D0((char *)a, (int)func_021B1240);
    func_02159144(4);
    return 1;
}
















int func_021B13E0(u32 a, u32 b, u32 c, u32 d)
{
func_021B1268((void *)b);
return 0;
}
















int func_021B13EC(u8 *p)
{
    func_021B1268((void *)(((struct Obj18094 *)p)->f4));
    return 1;
}
















void func_021B13F8(u32 a)
{
    u32 id = 6;

    if (func_02159190(id)) {
        func_02192628((u32 *)func_0215A61C(a));
        func_0215A614((u8 *)a, 0);
        func_02159168(id);
    }
}
















int func_021B1424(int a, int b, int c, int d)
{
if (func_021926D8((struct U *)func_0215A61C(b)) == 1) {
    return 1;
}
return 0;
}
















int func_021B143C(void *a, int b)
{
    void *o;
    int s0, k, n;
    u8 s1, s2;
    int *q;
    u16 h0, h1;
    u8 *p;
    u8 **pp =(u8 **)((char *)a + 0x14);
    o = func_0215A5F4((void *)b);
    s0 = func_02011330(a);
    s1 = **pp;
    (*pp)++;
    s2 = **pp;
    (*pp)++;
    k = func_02011330(a);
    n = func_021B162C(b, (u32)o, s0);
    q = (int *)func_02158F58((int)o);
    h0 = func_0219270C((struct Q *)(*q), n, 4);
    h1 = func_0219272C((u16 *)(*q), n, 4);
    {
        int m = (int)func_02192570((u16 *)(*q), k, s1, s2, h0, h1);
        func_0215A614((u8 *)b, m);
        func_0219269C((struct T *)m, 4, 4, n);
    }
    func_020113D0(a, (int)func_021B1424);
    func_02159144(6);
    return 1;
}
















int func_021B14DC(u32 a, u32 b, u32 c, u32 d)
{
func_021B13F8(b);
return 0;
}
















int func_021B14E8(u8 *p)
{
    func_021B13F8(((struct Obj18095 *)p)->f4);
    return 1;
}
















int func_021B14F4(int a, int b)
{
    if (func_02159190(1)) {
        func_021B0480(b);
    }
    if (func_02159190(3)) {
        func_021B10A4((void *)b);
    }
    if (func_02159190(4)) {
        func_021B1268((void *)b);
    }
    if (func_02159190(6)) {
        func_021B13F8(b);
    }
    if (func_02159190(2)) {
        func_021B0A88(a, b);
    }
    return 1;
}
















int func_021B1550(int a, int b)
{
    int r5;
    int r4;

    r5 = func_020362DC();
    r4 = func_0215A61C(b);
    if (r5 & 3) {
        func_020061E4(0x547);
        return 1;
    }
    if (func_02159190(1)) {
        func_02191134((struct P *)r4);
    } else if (func_02159190(3)) {
        func_02191794((struct R *)r4);
    } else if (func_02159190(2)) {
        func_021914CC((struct S *)r4);
    } else {
        return 1;
    }
    return 0;
}
















int func_021B15B8(u32 a)
{
    func_020113D0((char *)a, (u32)func_021B1550);
    return 1;
}
















int func_021B15C8(u32 a, u32 b)
{
    u32 *p = (u32 *)func_02158F58((int)func_0215A5F4((void *)b));

    if (func_02011330((struct Stream *)a)) {
        func_021904DC((u8 *)(*p), 1);
        func_02159144(9);
    } else {
        func_021904DC((u8 *)(*p), 0);
        func_02159168(9);
    }
    return 0;
}
















int func_021B1604(u32 *a)
{
    u32 *p = (u32 *)func_02158F58(a[2]);
    u32 id = 9;

    if (func_02159190(id)) {
        func_021904DC((u8 *)(*p), 0);
        func_02159168(id);
    }
    return 1;
}















u32 func_021B162C(u32 a, u32 b, u32 c)
{
    u32 x, r, s, n;

    x = func_0215A60C((u8 *)a);
    r = func_02158F78((u8 *)b);
    s = (u32)func_02158F74((void *)b);
    n = func_02158F7C((u8 *)b);
    func_02045CAC((struct MsgBank *)x, c, (void *)n);
    func_0201F250((struct WordSet *)s, (void *)r, (void *)n);
    return r;
}















u32 func_021B1668(u32 a, u32 b)
{
    u32 t;
    u32 r;

    t = (u32)func_0215A5EC((void *)a);
    if (b == 0xf2) {
        r = (u32)func_0216DE54((void *)t, 0x30);
    } else if (b == 0xf1) {
        func_0215A5F4((void *)a);
    } else {
        r = (u32)func_0216DE94((void *)t, b);
    }
    return r;
}















int func_021B1698(int *a, int *b)
{
    int r7;
    int r6;
    int r0;

    func_0215A5F4((void *)b);
    r7 = func_02159B10(a, (void *)b);
    r6 = func_0201134C((struct Cursor *)a);
    r0 = func_021B1668((u32)b, r7);
    if (r0 == 0) {
        return 0;
    }
    func_0215A6DC(b, func_02197D3C(r0, a[5] + r6));
    return 0;
}















int func_021B16DC(u32 a, u32 b, u32 c, u32 d)
{
if (func_0215A6FC(b, b, c, d) == 0) {
    return 1;
}
return 0;
}














int func_021B16F0(u32 a)
{
    func_020113D0((char *)a, (u32)func_021B16DC);
    return 1;
}














int func_021B1700(u32 a, u32 b)
{
    u32 t = (u32)func_0215A5EC((void *)b);
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = 0;
    *o = func_0216D5A0(func_0216DE94((void *)t, func_02159B10((void *)a, (void *)b)));
    return 0;
}













int func_021B1738(u32 a, u32 b)
{
    u32 t = (u32)func_0215A5EC((void *)b);
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 y = func_02159B10((void *)a, (void *)b);

    func_0216E0E8((int)func_0216DE94((void *)t, x), y);
    return 0;
}













int func_021B176C(int a, int b)
{
    int r6;
    s16 *r7;
    s16 *r4;

    r6 = (int)func_0215A5EC((void *)b);
    r6 = (int)func_0216DE94((void *)r6, func_02159B10((void *)a, (void *)b));
    r7 = (s16 *)func_02159AE8((void *)a, (void *)b);
    r4 = (s16 *)func_02159AE8((void *)a, (void *)b);
    *r7 = func_0216D83C((void *)r6);
    *r4 = func_0216D86C((void *)r6);
    return 0;
}











int func_021B17B4(int a, int b)
{
    void *r5;
    s16 *r6;
    s16 *r4;

    r5 = func_021A3074(func_02188CB4((struct Obj00020 *)(((unsigned char **)func_02158F58((int)func_0215A5F4((void *)b)))[1])));
    r6 = (s16 *)func_02159AE8((void *)a, (void *)b);
    r4 = (s16 *)func_02159AE8((void *)a, (void *)b);
    *r6 = func_0216D83C(r5);
    *r4 = func_0216D86C(r5);
    return 0;
}










int func_021B17F8(u32 a, u32 b)
{
    u32 x = func_021B1E74(b);
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_0216D5F8((void *)x);
    return 0;
}










int func_021B181C(int a, int b)
{
    int r6;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int r7;
    int r5;
    int r0;

    r6 = (int)func_02158F58((int)func_0215A5F4((void *)b));
    v0 = func_02159B10((void *)a, (void *)b);
    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    v4 = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    r5 = func_02188C9C((u8 *)(((int *)r6)[1]));
    r6 = (int)func_0215A5EC((void *)b);
    r0 = func_0216E3D0(func_0201296C(func_0215A5E4((void *)b)), v4);
    r0 = func_0216CE6C(r6, v0, v1, v2, v3, r0, r7, r5);
    if (r0 != 0) {
        func_0216DAF8((void *)r0);
    }
    return 0;
}










int func_021B18B8(u32 a, u32 b)
{
    u32 t = (u32)func_0215A5EC((void *)b);
    u32 o = (u32)func_0216DE94((void *)t, func_02159B10((void *)a, (void *)b));

    if (o != 0) {
        func_0216CF2C(o);
    }
    return 0;
}









int func_021B18E4(int a, int b)
{
    void *r4;
    int r5;
    int r6;
    int s8;
    int sc;
    int s10;
    int r0;

    s8 = (int)func_0215A5EC((void *)b);
    r4 = func_0215A5E4((void *)b);
    sc = func_02012844(r4);
    r5 = func_02162744((u8 *)sc);
    s10 = func_02012AC8((const struct Rec44 *)func_020127A4(r4));
    r6 = func_02159B10((void *)a, (void *)b);
    if (r5 != 0) {
        r4 = (void *)func_0201296C(r4);
        r0 = func_0216CEE4(s8, func_02162740((u8 *)sc), s10, r5, r4, r6);
        if (r0 != 0) {
            func_0216DAF8((void *)r0);
        }
    }
    return 0;
}









int func_021B1950(int a, int b)
{
    int r0;
    int r2;
    s16 r1;
    s16 r7;
    s16 r6;
    int r4;

    r2 = func_02159B10((void *)a, (void *)b);
    r1 = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    r6 = func_02159B10((void *)a, (void *)b);
    r4 = func_02159B10((void *)a, (void *)b);
    r0 = (int)func_0216DE94(func_0215A5EC((void *)b), r2);
    if (r0) {
        func_0216E084(r0, r1, r7, r6, r4);
    }
    return 0;
}









int func_021B19B0(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u16 *p = func_02159AE8((void *)a, (void *)b);
    u32 o = (u32)func_0216DE94(func_0215A5EC((void *)b), x);

    if (o != 0) {
        *p = func_0216D5B0((u8 *)o);
    }
    return 0;
}









int func_021B19E0(int a, int b)
{
    int r7;
    unsigned int r4;
    u16 *r6;
    int r0;

    r7 = func_02159B10((void *)a, (void *)b);
    r4 = func_02159B10((void *)a, (void *)b);
    r6 = func_02159AE8((void *)a, (void *)b);
    r0 = (int)func_0216DE94(func_0215A5EC((void *)b), r7);
    if (r4 <= 2 && r0 != 0) {
        *r6 = func_0216D63C((char *)r0, r4);
    }
    return 0;
}









int func_021B1A20(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 o = (u32)func_0216DE94(func_0215A5EC((void *)b), x);

    if (o != 0) {
        func_0216DB80((unsigned int *)o, 1);
    }
    return 0;
}







int func_021B1A44(int a, int b)
{
    int r5;
    int r6;
    int r7;

    r5 = (int)func_02158F90(func_0215A5F4((void *)b));
    r6 = func_021B1E74(b);
    r7 = (int)func_0215A5EC((void *)b);
    if (d_021EE71C & 1) {
        if (func_0216D454((void *)r6) == 1) {
            func_0216DAF8((void *)r6);
            d_021EE71C &= 0xfe;
        }
    }
    if (d_021EE71C & 4) {
        if (func_0216DA5C((void *)r5) == 0) {
            func_0216DAF8((void *)r5);
            d_021EE71C &= 0xfb;
        }
    }
    if (d_021EE71C & 2) {
        r6 = (int)func_0216DE54((void *)r7, 0x30);
        if (func_0216DA5C((void *)r6) == 0) {
            func_0216DAF8((void *)r6);
            d_021EE71C &= 0xfd;
        }
    }
    if (d_021EE71C & 8) {
        r5 = func_0219BBA4(r5);
        if (r5 == 0) {
            d_021EE71C &= 0xf7;
        } else if (func_0216DA5C((void *)r5) == 0) {
            func_0216DAF8((void *)r5);
            d_021EE71C &= 0xf7;
        }
    }
    if (d_021EE71C == 0) {
        return 1;
    }
    return 0;
}






int func_021B1B08(int a, void *b)
{
    void *r4;
    void *r6;
    void *r7;

    r4 = func_0215A5F4(b);
    r6 = func_0215A5EC(b);
    r4 = func_02158F90(r4);
    r7 = (void *)func_021B1E74((u32)b);
    func_0216DE54(r6, 0x30);
    b = (void *)func_0219BBA4((int)r4);
    d_021EE71C = 0;
    func_0216D9A0(r6);
    if (func_0216D454((void *)((int)r7)) == 0) {
        d_021EE71C |= 1;
        func_0216DB04(r7);
    }
    if (r4 != 0) {
        if (func_0216DA5C(r4) == 1) {
            d_021EE71C |= 4;
            func_0216DB04(r4);
        }
    }
    if (b != 0) {
        if (func_0216DA5C(b) == 1) {
            d_021EE71C |= 8;
            func_0216DB04(b);
        }
    }
    func_020113D0((char *)a, (int)func_021B1A44);
    return 1;
}





int func_021B1BB8(int a, void *b)
{
    if (func_02158F90(func_0215A5F4(b)) == 0) {
        func_0216D9A0(func_0215A5EC(b));
    } else {
        return func_021B1B08(a, b);
    }
    return 0;
}






/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A5EC (0x0215A5EC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B1BE8(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D9E4((void *)(u32)func_0215A5EC((void *)a));
}







int func_021B1BF4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    u32 v = func_021642A4(func_0216D5F8((void *)func_021B1E74(b)));
    u32 o = (u32)func_02158F90(s);

    if (o != 0) {
        func_0216D5E0(o, v);
        func_0216D674((void *)o, 0);
    }
    return 0;
}







int func_021B1C2C(int a, int b)
{
    int r7;
    s16 *s8;
    s16 *r6;
    int sc;
    int s10;
    int r4;
    int r0;

    r7 = ((int *)func_02158F58((int)func_0215A5F4((void *)b)))[1];
    s8 = (s16 *)func_02159AE8((void *)a, (void *)b);
    r6 = (s16 *)func_02159AE8((void *)a, (void *)b);
    sc = func_02159B10((void *)a, (void *)b);
    s10 = func_02159B10((void *)a, (void *)b);
    r4 = func_02159B10((void *)a, (void *)b);
    r0 = (int)func_0216DDDC((u32)func_02188C7C((void *)r7), (s16)sc, (s16)r4, s10 << 16, 0x8000, (int)0);
    if (r0) {
        *r6 = 1;
        *s8 = func_0216D588((void *)r0);
    } else {
        *r6 = 0;
    }
    return 0;
}






int func_021B1CB0(u32 a, u32 b)
{
    void *h;
    u16 *p;
    u16 *q;
    int r;

    h = func_02188CB4(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b))));
    p = (u16 *)(s16 *)func_02159AE8((void *)a, (void *)b);
    q = (u16 *)(s16 *)func_02159AE8((void *)a, (void *)b);
    r = func_021A32A8(h, 0x8000);
    if (r != 0) {
        *q = 1;
        *p = func_0216D588((void *)r);
    } else {
        *q = 0;
    }
    return 0;
}






int func_021B1CFC(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A2F54(func_02188CB4(((struct Obj18096 *)((u8 *)(func_02158F58((int)func_0215A5F4((void *)b)))))->f4)) == 1) {
    return 1;
}
return 0;
}






int func_021B1D20(u32 a, u32 b)
{
    u32 *e;
    u32 v;
    void *o;

    e = (u32 *)func_02158F58((int)func_0215A5F4((void *)b));
    v = func_02011330((struct Stream *)a);
    o = func_02188CB4((struct Obj00020 *)e[1]);
    func_021A2F48(o, v);
    if (func_021A2F54(o) == 1)
        return 0;
    func_020113D0((char *)a, (int)func_021B1CFC);
    return 1;
}






int func_021B1D64(u32 a, u32 b)
{
    struct { int x, y, z; } v;
    u32 x;
    u32 y;
    int neg;
    int q;
    int p;
    int z;
    int zero;
    void *w;

    x = ((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1];
    y = func_02188D38((u8 *)x);
    neg = func_02159B10((void *)a, (void *)b);
    p = func_02159B10((void *)a, (void *)b);
    q = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    if (neg != 0)
        p = -p;
    if (z == 0) {
        zero = 0;
        v.x = zero;
        v.y = -q << 12;
        v.z = zero;
    } else {
        zero = 0;
        v.x = zero;
        v.y = q << 12;
        v.z = zero;
    }
    w = func_021A3074(func_02188CB4((void *)x));
    func_021C6DE0((u8 *)y, (u32 *)func_021C78DC(x, p, &v, w), 0);
    return 0;
}






int func_021B1DEC(u32 a, u32 b)
{
    struct { int x, y, z; } v;
    u32 x;
    u32 y;
    int neg;
    int q;
    int p;
    int z;
    int zero;
    void *w;

    x = ((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1];
    y = func_02188D38((u8 *)x);
    neg = func_02159B10((void *)a, (void *)b);
    p = func_02159B10((void *)a, (void *)b);
    q = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    if (neg != 0)
        p = -p;
    if (z == 0) {
        zero = 0;
        v.x = zero;
        v.y = -q << 12;
        v.z = zero;
    } else {
        zero = 0;
        v.x = zero;
        v.y = q << 12;
        v.z = zero;
    }
    w = func_021A3074(func_02188CB4((void *)x));
    func_021C6DE0((u8 *)y, (u32 *)func_021C78DC(x, p, &v, w), 0);
    return 0;
}






/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * (u32)func_0215A5EC ((void *)0x0215A5EC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B1E74(u32 a)
{
return (int)func_0216DEE0((void *)(u32)func_0215A5EC((void *)a));
}






int func_021B1E80(void *a, u32 b)
{
    void *o;
    int q;
    void *e;
    void *d;
    Ids ids;
    int i;
    u32 h, f;
    void *m;
    V pos;
    int id;
    int found;
    int k;
    u8 *tbl;

    o = func_0215A5F4((void *)b);
    q = ((int *)func_02158F58((int)o))[1];
    e = func_0215A5E4((void *)b);
    d = func_0215A5DC((void *)b);
    ids = d_021D93FC;
    h = func_02012844(e);
    f = func_0201296C(e);
    m = func_02188CB4((void *)q);
    func_021A3038(m, (struct VecFx32 *)&pos);
    for (i = 0; i < 4; i++) {
        id = ids.v[i];
        if (func_021627C8((struct Ctx *)h, (void *)f, (int)(&pos), id) != 0) {
            found = id;
            break;
        }
    }
    k = func_021A3050(m);
    if (k != found) {
        if (found == 0) {
            tbl = d_021D941C;
        } else if (found == 1) {
            tbl = d_021D9414;
        } else if (found == 2) {
            tbl = d_021D940C;
        } else if (found == 3) {
            tbl = d_021D9404;
        } else {
            return 0;
        }
        func_0215897C(o, func_021618A0(d, q, 0xff, (int)tbl));
        return 1;
    }
    return 0;
}






/*
 * Each arm stores its constant through o itself; cross-jumping merges the
 * stores, leaving cases 2 and 3 branching onto case 1's branch.
 */
int func_021B1F60(u32 a, u32 b)
{
    void *x = func_02188CB4((struct Obj00020 *)((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]);
    u16 *o = func_02159AE8((void *)a, (void *)b);

    switch (func_021A3098(x)) {
    case 0:
        *o = 0;
        break;
    case 1:
        *o = 1;
        break;
    case 2:
        *o = 2;
        break;
    case 3:
        *o = 3;
        break;
    default:
        *o = 0;
        break;
    }
    return 0;
}






int func_021B1FB8(u32 a, u32 b)
{
    int buf[3];
    int vec[3];
    void *t;
    int i;
    int x;
    int y;
    int z;
    u32 m;
    void *w;
    u32 o;

    t = func_0215A5F4((void *)b);
    i = func_02159B10((void *)a, (void *)b);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    m = (u32)(void *)(u32)func_0215A5EC((void *)((u32)((void *)b)));
    w = func_0215A5DC((void *)b);
    o = (u32)func_0216DE94((void *)m, i);
    func_0216D88C((const struct Actor *)o, (struct VecFx32 *)buf);
    vec[0] = (x << 16) + 0x8000;
    vec[1] = y << 16;
    vec[2] = (z << 16) + 0x8000;
    func_0215897C(t, func_02161AC0(w, (void *)o, (struct Tri *)buf, vec));
    return 1;
}






int func_021B2040(u32 a, u32 b)
{
    void *x = func_02188CB4((struct Obj00020 *)(((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]));
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_021A3238(x);
    return 0;
}






int func_021B2070(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = func_021B1E74(b);
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    func_021B83FC(func_0219E348((void *)h), x, y, z);
    return 0;
}





int func_021B20B0(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = (u32)func_0216DE94((void *)(u32)func_0215A5EC((void *)((u32)((void *)b))), func_02159B10((void *)a, (void *)b));
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    func_021B83FC(func_0219E348((void *)h), x, y, z);
    return 0;
}





int func_021B2104(u32 a, u32 b)
{
    void *t;
    u32 v;
    u32 m;
    u32 o;
    void *w;

    w = func_0215A5DC((void *)b);
    t = func_0215A5F4((void *)b);
    m = (u32)(void *)(u32)func_0215A5EC((void *)((u32)((void *)b)));
    o = (u32)func_0216DE94((void *)m, func_02159B10((void *)a, (void *)b));
    v = (u32)func_021C474C(w, ((u32 *)func_02158F58((int)t))[1], o);
    func_0215897C(t, (void *)v);
    return 1;
}





int func_021B2154(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = func_021B1E74(b);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0219E348((void *)h);
    func_021B8484((u8 *)o, x, y, z);
    func_021B7DC0(o, buf);
    func_0219E2C0((void *)h, buf);
    return 0;
}





int func_021B21AC(u32 a, u32 b)
{
    u16 buf[4];
    u32 h;
    u32 o;
    u32 x;
    u32 y;
    u32 z;

    h = (u32)func_0216DE94((void *)(u32)func_0215A5EC((void *)((u32)((void *)b))), func_02159B10((void *)a, (void *)b));
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0219E348((void *)h);
    func_021B8484((u8 *)o, x, y, z);
    func_021B7DC0(o, buf);
    func_0219E2C0((void *)h, buf);
    return 0;
}





int func_021B2218(u32 a, u32 b)
{
    int v[3];
    void *t;
    u32 o;
    u32 e;
    u32 g;
    u32 p;

    t = func_0215A5F4((void *)b);
    o = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0216DE94((void *)(u32)func_0215A5EC((void *)((u32)((void *)b))), o);
    e = ((u32 *)func_02158F58((int)t))[1];
    g = func_02188D38((u8 *)e);
    func_020061E4(0x676);
    v[0] = 0;
    v[1] = 0x96 << 12;
    v[2] = 0;
    p = func_021C7878(e, 0x18, v, o);
    func_021C6DE0((u8 *)g, (u32 *)func_021C7220(e, 0x18, 3, o), 0);
    func_021C6DE0((u8 *)g, (u32 *)p, 0);
    return 0;
}





int func_021B229C(u32 a, u32 b)
{
    V pos;
    V rot;
    int h;
    u32 k0, k1, k2, k3, o, e, g;
    void *t;

    t = func_0215A5F4((void *)b);
    k0 = func_02159B10((void *)a, (void *)b);
    k1 = func_02159B10((void *)a, (void *)b);
    k2 = func_02159B10((void *)a, (void *)b);
    k3 = func_02159B10((void *)a, (void *)b);
    o = (u32)func_0216DE94((void *)(u32)func_0215A5EC((void *)((u32)((void *)b))), k0);
    e = ((u32 *)func_02158F58((int)t))[1];
    g = func_02188D38((u8 *)e);
    if (o == 0) {
        return 0;
    }
    h = 0;
    pos.x = (k1 << 16) + 0x8000;
    pos.y = 0xFA000;
    pos.z = (k2 << 16) + 0x8000;
    func_02163E58(o, &pos, &h);
    pos.y = h;
    func_0216E084(o, k1, (pos.y >> 4) / 0x1000, k2, k3);
    func_0216D89C(o, &pos);
    rot = d_021D9424;
    func_0216D8C0(o, &rot);
    func_021C6DE0((u8 *)g, (u32 *)func_021C7684(e, o, 0x28, 0xfa), 0);
    return 0;
}





int func_021B2380(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = func_021F3E24(d, k);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B23B8(u32 a, u32 b)
{
    void *d;
    u8 k;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    k = func_02011330((struct Stream *)a);
    func_021F4134(d, k);
    return 0;
}





int func_021B23E0(u32 a, u32 b, u32 c, u32 d)
{
func_021F3D74((u32)func_0215A5DC((void *)b));
return 0;
}





int func_021B23F0(u32 a, u32 b, u32 c, u32 d)
{
func_0215A5F4((void *)b);
func_021F37A4(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b))));
return 0;
}





int func_021B240C(u32 a, u32 b)
{
    void *w;
    u16 *o;

    func_0215A5F4((void *)b);
    w = func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)));
    o = func_02159AE8((void *)a, (void *)b);
    if (func_021F37C8(w) != 0) {
        *o = 1;
    } else {
        *o = 0;
    }
    return 0;
}





int func_021B2444(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = (u32)func_021F37EC(d, k);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B247C(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 flag = 1;
    u32 r = func_021F3834(d, k, flag);

    if (r == 0) {
        return flag;
    }
    func_0215897C(s, (void *)r);
    return flag;
}





int func_021B24B8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = func_021F3834(d, k, 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B24F4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330((struct Stream *)a);
    u32 r = func_021F3888(d, k);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B252C(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F4184(d, *func_02159AE8((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B2568(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F41B0(d, *func_02159AE8((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B25A4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F41DC(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B25DC(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F398C(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B2614(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3A28(d, func_02011330((struct Stream *)a) ? 1 : 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B2650(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3770(d, func_02011330((struct Stream *)a) ? 1 : 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B268C(u32 a, u32 b, u32 c, u32 d)
{
func_021F42A8(func_0215A5DC((void *)b));
return 0;
}





int func_021B269C(u32 a, u32 b, u32 c, u32 d)
{
func_021F3970(func_0215A5DC((void *)b));
return 0;
}





int func_021B26AC(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F384C(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B26E4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3888(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B271C(u32 a, u32 b, u32 c, u32 d)
{
func_021F38C4(func_0215A5DC((void *)b), func_02011330((struct Stream *)a));
return 0;
}





int func_021B273C(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int p = func_02011330((struct Stream *)a);
    int q = func_02011330((struct Stream *)a);
    int r = func_021F3A88((int)y, p, q);

    if (r == 0) {
        return 1;
    }
    func_0215897C(x, (void *)r);
    return 1;
}





int func_021B277C(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = (u32)func_021F3B5C(d, func_02011330((struct Stream *)a));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B27B4(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = func_021F3AD0(y, p, q);

    if (r == 0) {
        return 1;
    }
    func_0215897C(x, (void *)r);
    return 1;
}





int func_021B27F8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F3B18(d, func_02159B10((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}





int func_021B2830(u32 a)
{
    u32 w = func_02011330((struct Stream *)a);
    u32 x = func_02011330((struct Stream *)a);
    u32 y = func_02011330((struct Stream *)a);
    u32 z = func_02011330((struct Stream *)a);

    func_0204E720(w, x, y, z);
    return 0;
}





int func_021B2860(u32 a, u32 b, u32 c, u32 d)
{
if (func_0204E804() != 1) {
    return 1;
}
return 0;
}





int func_021B2874(u32 a, u32 b, u32 c, u32 d)
{
if (func_02189A24(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)))) != 1) {
    return 1;
}
return 0;
}





/*
 * func_021BE92C reads its last two stack arguments with ldrb, so they are
 * u8 parameters: the narrowing then happens once at the call, scheduled
 * the way the original has it. A (u8) cast at the call site or a u8 local
 * feeding int parameters schedules the zero store after the shift pair.
 * Addresses are Black-image addresses.
 */
int func_021B2890(u32 a, u32 b)
{
    void *x;
    void *y;
    u32 p;
    void *q;
    u32 z;

    x = func_0215A5F4((void *)b);
    y = func_0215A5DC((void *)b);
    p = (u32)func_020120F4((const struct Ctx_021AE66C *)y);
    q = func_0201210C((const struct Ctx_021AE66C *)((void *)y));
    z = func_02012984((const struct BigObj *)p);
    func_0215897C(x, (void *)func_021BE92C(y, (int)q, 3, 0, 0, z, z));
    return 0;
}





int func_021B28E0(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 0, 0, 0);
    return 0;
}





int func_021B2910(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 0, 0, 0);
    return 0;
}





int func_021B2940(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 1, 0, 0);
    return 0;
}





int func_021B2970(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 0, 1, 0);
    return 0;
}





int func_021B29A0(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 1, 1, 0);
    return 0;
}





int func_021B29D0(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 2, 0, 0);
    return 0;
}





int func_021B2A00(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 3, 0, 0);
    return 0;
}





int func_021B2A30(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 2, 1, 0);
    return 0;
}





int func_021B2A60(u32 a, u32 b)
{
    void *d;

    func_0215A5F4((void *)b);
    d = func_0215A5DC((void *)b);
    func_021B2EBC((u32)d, (u32)func_0201210C((const struct Ctx_021AE66C *)((void *)d)), 3, 1, 0);
    return 0;
}





int func_021B2A90(u32 a)
{
    func_020113D0((char *)a, (u32)func_021B2860);
    return 1;
}





int func_021B2AA0(void *p)
{
    sub_020113D0(p, (int)func_021B2874);
    return 1;
}





int func_021B2AB0(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);

    func_0215897C(s, func_021C0AA0(d, (int)func_02158F50((void *)s)));
    return 1;
}





int func_021B2ADC(int a, int b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);
    int p = (int)func_02159B10((void *)a, (void *)b);

    func_02188CB4(func_0201210C((const struct Ctx_021AE66C *)((void *)y)));
    func_0215897C(x, func_021C0820(y, (int)func_02158F50((void *)x), (unsigned char)p));
    return 1;
}





int func_021B2B24(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);
    void *w = func_0201210C((const struct Ctx_021AE66C *)((void *)d));

    func_0215897C(s, (void *)func_021C978C((u32)func_02158F50((void *)s), (u32)d, (u32)w));
    return 1;
}





int func_021B2B5C(u32 a, u32 b)
{
    void *d = func_0215A5DC((void *)b);
    void *s = func_0215A5F4((void *)b);
    void *w = func_0201210C((const struct Ctx_021AE66C *)((void *)d));

    func_0215897C(s, (void *)func_021C9828((u32)func_02158F50((void *)s), (u32)d, (u32)w));
    return 1;
}





int func_021B2B94(int a, int b)
{
    void *y = func_0215A5DC((void *)b);
    void *x = func_0215A5F4((void *)b);
    void *t = func_0201210C((const struct Ctx_021AE66C *)((void *)y));
    int p = (int)func_02159B10((void *)a, (void *)b);

    func_0215897C(x, (void *)func_021C98F4((u32)func_02158F50((void *)x), (u32)y, (u32)t, p));
    return 1;
}





int func_021B2BD8(u32 a)
{
return func_0218DC6C((u8 *)func_02188C98(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)a)))));
}





/*
 * Leaf filed for lane S20 (blocker of 021B2C08 and friends).
 *
 * Addresses are Black-image addresses.
 */
int func_021B2BEC(int a, int b, int c, int d)
{
    int buf[3];

    buf[0] = c << 16;
    buf[1] = 0;
    buf[2] = d << 16;
    return func_0218C654(a, b, (int)buf);
}





int func_021B2C08(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C69C((unsigned char *)h, t, 0, 1);
        func_0218C69C((unsigned char *)h, t, 0, 3);
    }
    return 0;
}





int func_021B2C5C(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C69C((unsigned char *)h, t, 0, 2);
    }
    return 0;
}





int func_021B2CA0(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int s = (int)func_02159B10((void *)a, (void *)b);
    int t = func_021B2BEC(func_021B2BD8(b), p, q, r);

    if (t) {
        func_0218C54C(t, s);
    }
    return 0;
}





int func_021B2CE8(int a, int b)
{
    int p = (int)func_02159B10((void *)a, (void *)b);
    int q = (int)func_02159B10((void *)a, (void *)b);
    int r = (int)func_02159B10((void *)a, (void *)b);
    int s = (int)func_02159B10((void *)a, (void *)b);
    int h = func_021B2BD8(b);
    int t = func_021B2BEC(h, p, q, r);

    if (t) {
        func_0218C574(h, t, s);
    }
    return 0;
}





int func_021B2D34(int a, int b)
{
    unsigned short *out = func_02159AE8((void *)a, (void *)b);
    int f = func_02159B10((void *)a, (void *)b);
    int x = func_02159B10((void *)a, (void *)b);
    int y = func_02159B10((void *)a, (void *)b);
    int h;
    int buf[3];

    h = func_0218DC6C((u8 *)func_02188C98(func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)))));
    buf[0] = x << 16;
    buf[1] = 0;
    buf[2] = y << 16;
    *out = func_0218BACC(h, func_0218C7D8((void *)h, f, (int)buf));
    return 0;
}





int func_021B2D98(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 o = func_0218BA98(func_021B2BD8(b), x);

    if (o != 0) {
        func_0218C860(o);
    }
    return 0;
}





int func_021B2DBC(int a, int b)
{
    unsigned short v;
    int p = func_02159B10((void *)a, (void *)b);
    int q = func_02159B10((void *)a, (void *)b);
    int h = func_0218BA98(func_021B2BD8(b), p);

    if (h) {
        func_0218C88C((unsigned char *)h, q, 0);
        if (func_0218C990((unsigned char *)h, (int)(&v))) {
            func_020061E4(v);
        }
    }
    return 0;
}





int func_021B2E08(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 y = func_02159B10((void *)a, (void *)b);
    u32 o = func_0218BA98(func_021B2BD8(b), x);

    if (o != 0) {
        func_0218C88C((unsigned char *)o, y, 2);
    }
    return 0;
}





int func_021B2E3C(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 o = func_0218BA98(func_021B2BD8(b), x);

    if (o != 0) {
        func_0218C89C((unsigned char *)o, 3);
    }
    return 0;
}





int func_021B2E60(u32 a, u32 b)
{
    d_021EE720 = func_02159B10((void *)a, (void *)b);
    func_020113D0((char *)a, (u32)func_021B2E80);
    return 1;
}





int func_021B2E80(u32 a, u32 b)
{
    u32 o = func_0218BA98(func_021B2BD8(b), d_021EE720);

    if (o == 0) {
        return 1;
    }
    if (func_0218C8D8((void *)o) == 0) {
        return 0;
    }
    if (func_0218C9A4((void *)o) == 0) {
        return 1;
    }
    return 0;
}





void func_021B2EBC(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    int h = func_02188D30((u8 *)b);
    u32 *w = func_02030734(4, 0x18, 1, (const char *)&d_021DE14C, 0x369);

    func_02030DA8(h, func_021B2F18, w, 0);
    func_02189A1C((u8 *)b, 1);
    w[5] = 0;
    w[0] = a;
    w[1] = b;
    w[2] = d;
    w[3] = e;
    w[4] = c;
}





void func_021B2F18(int p, int *q)
{
    int x;
    int y;
    int z;
    int w;
    int c;
    void *t;

    switch (q[5]) {
    case 0:
        if ((unsigned int)q[4] <= 1) {
            x = -1;
        } else {
            x = 4;
        }
        if (q[4] == 0 || q[4] == 2) {
            y = 16;
            z = 0;
            t = (void *)func_02043658();
            func_02188DA0();
            func_02043534((unsigned int)t);
            func_02188DB0((u8 *)q[1]);
        } else {
            y = 0;
            z = 16;
        }
        if (q[2] == 0) {
            w = 3;
        } else {
            w = 12;
        }
        func_0204E720(w, y, z, x);
        q[5] = q[5] + 1;
        break;
    case 1:
        c = 0;
        if (q[3] == 1) {
            c = 1;
        }
        if (func_0204E804() == 0) {
            c = 1;
        }
        if (c) {
            func_02189A1C((u8 *)q[1], 0);
            func_02030EAC((struct Node *)p);
            func_020307B0(q);
        }
        break;
    }
}





int func_021B2FB0(u32 a, u32 b)
{
    void *w = func_0201210C((const struct Ctx_021AE66C *)(func_0215A5DC((void *)b)));
    u32 x = func_02188D20(w);

    func_021BC5A0((void *)x, func_02188C9C(w));
    return 0;
}





int func_021B2FD8(u32 a, u32 b)
{
    u32 v;
    void *t;
    u32 s;
    void *x;
    Work **slot;
    u32 y;
    u32 z;
    Work *w;

    v = func_02159B10((void *)a, (void *)b);
    func_02159AE8((void *)a, (void *)b);
    t = func_0215A5DC((void *)b);
    s = (u32)func_020120F4((const struct Ctx_021AE66C *)t);
    x = func_0201210C((const struct Ctx_021AE66C *)((void *)t));
    slot = func_02158FB4(func_0215A5F4((void *)b));
    y = func_02188C54(x);
    z = (u32)func_020127C4((void *)s);
    w = func_02030734(4, 0x214, 1, (const char *)d_021DE210, 0xFC);
    *slot = w;
    w->f10 = func_021904AC((u8 *)y);
    w->f14 = (u32)func_02012F08((int *)s);
    w->f0C = 0x15;
    w->f18 = func_0201292C((const struct BigObj *)s);
    w->f20 = (u32)func_020071CC((struct Sub020071CCCtrl *)func_02012EBC((struct Big *)s), 0x3a);
    w->f1C = (u32)func_02012F2C((int *)s);
    w->f24 = z;
    switch (v) {
    case 0xFF:
        w->b2 = v;
        break;
    case 0xFE:
        w->b2 = v;
        break;
    case 0xFD:
        w->b2 = v;
        break;
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
        w->b2 = v;
        break;
    default:
        w->b2 = (u8)v;
        w->b3 = (u8)v;
        break;
    }
    func_020113D0((char *)a, (int)func_021B3158);
    if (v != 0xFE && v != 0xFD) {
        func_021655D4();
    }
    return 1;
}





void func_021B30C8(u32 *p, u32 b, void *h)
{
    Param s;
    int i;

    p[1] = func_0218F1B4(h);
    func_0218F1AC(h, 0);
    func_0218F848(h);
    i = func_021A3050(func_02188CB4((void *)b));
    func_0218ECE4(h, &s.a);
    func_0218ECB4(h, &s.b);
    func_0218EC54(h);
    s.b.x += d_021D9708[i].x;
    s.b.y += d_021D9708[i].y;
    s.b.z += d_021D9708[i].z;
    s.e[0] = 0;
    s.e[1] = 0;
    s.e[2] = 0;
    s.e[3] = 0;
    s.e[4] = 0;
    s.f = 1;
    func_0218F918(h, &s, 10);
}
