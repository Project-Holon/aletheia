/*
 * file:     field_msgbg.c
 * unit:     yes
 * function: func_02189BBC, func_02189BD0, func_0218A074, func_0218A0E4, func_0218A240, func_0218A278, func_0218A4BC, func_0218A4E0, func_0218A6E8, func_0218A728, func_0218A738, func_0218A76C, func_0218A784, func_0218A7F0, func_0218A824, func_0218A878, func_0218A8BC, func_0218A9B0, func_0218AA2C, func_0218AA74, func_0218AAD0, func_0218AB0C, func_0218AB50, func_0218AB9C, func_0218AC08, func_0218AC4C, func_0218AC84, func_0218ACA8, func_0218ACD0, func_0218AD28, func_0218AD80, func_0218ADC8, func_0218AE04, func_0218AE48, func_0218AEAC, func_0218AECC, func_0218AED4, func_0218AF90, func_0218B0CC, func_0218B13C, func_0218B208, func_0218B24C, func_0218B2A8, func_0218B2E8, func_0218B310, func_0218B32C, func_0218B3DC, func_0218B408, func_0218B4B0, func_0218B53C, func_0218B56C, func_0218B630, func_0218B6AC, func_0218B6F8, func_0218B754, func_0218B7F8, func_0218B83C, func_0218B88C, func_0218B8AC, func_0218B910, func_0218B924, func_0218B930, func_0218B974, func_0218B9FC, func_0218BA04, func_0218BA48, func_0218BA70, func_0218BA98, func_0218BACC, func_0218BB04, func_0218BB0C, func_0218BB64, func_0218BB78, func_0218BBD0, func_0218BBF4, func_0218BC00, func_0218BC10, func_0218BC1C, func_0218BC40, func_0218BC6C, func_0218BC8C, func_0218BCAC, func_0218BCB0, func_0218BCE4, func_0218BCF4, func_0218BD20, func_0218BD24, func_0218BD28, func_0218BD94, func_0218BDD8, func_0218BE84, func_0218BEE8, func_0218BF84, func_0218BFB4, func_0218C02C, func_0218C040, func_0218C08C, func_0218C0D8, func_0218C124, func_0218C150, func_0218C154, func_0218C1A4, func_0218C1C4, func_0218C23C, func_0218C290, func_0218C2E4, func_0218C350, func_0218C388, func_0218C3B0, func_0218C3E0, func_0218C438, func_0218C43C, func_0218C47C, func_0218C490, func_0218C4A0, func_0218C4EC, func_0218C518, func_0218C530, func_0218C54C, func_0218C574, func_0218C584, func_0218C638, func_0218C654, func_0218C674, func_0218C69C, func_0218C6D0, func_0218C6F4, func_0218C724, func_0218C7D8, func_0218C7F0, func_0218C860, func_0218C88C, func_0218C89C, func_0218C8B0, func_0218C8D8, func_0218C8FC, func_0218C910, func_0218C924, func_0218C934, func_0218C944, func_0218C990, func_0218C9A4, func_0218C9C4, func_0218C9E8, func_0218CA4C, func_0218CA78, func_0218CB34, func_0218CC34, func_0218CC64, func_0218CD20, func_0218CEE0, func_0218CEE4, func_0218D05C, func_0218D0D8, func_0218D104, func_0218D13C, func_0218D158, func_0218D168, func_0218D1D0, func_0218D304, func_0218D444, func_0218D570, func_0218D7A8, func_0218D934, func_0218D970, func_0218D980, func_0218D9B8, func_0218D9C8, func_0218D9E8, func_0218DAEC, func_0218DBAC, func_0218DBD4, func_0218DC04, func_0218DC4C, func_0218DC5C, func_0218DC6C, func_0218DC70, func_0218DC74, func_0218DC84, func_0218DCF4, func_0218DCFC, func_0218DD04, func_0218DD08, func_0218DD0C, func_0218DD10, func_0218DD14, func_0218DD38, func_0218DD4C, func_0218DD5C, func_0218DD6C, func_0218DD70, func_0218DD80, func_0218DD84, func_0218DD98, func_0218DD9C, func_0218DDA4, func_0218DDB4, func_0218DE78, func_0218DEF0, func_0218DEFC, func_0218DF80, func_0218DFE0, func_0218E018, func_0218E0E4, func_0218E104, func_0218E124, func_0218E138, func_0218E13C, func_0218E160, func_0218E17C, func_0218E188, func_0218E18C, func_0218E260, func_0218E284, func_0218E298, func_0218E2B4, func_0218E358, func_0218E404, func_0218E4B0, func_0218E540, func_0218E58C, func_0218E5A0, func_0218E5B8, func_0218E5D0, func_0218E5EC, func_0218E5F4, func_0218E5FC, func_0218E610, func_0218E674, func_0218E6A4, func_0218E6F0, func_0218E73C, func_0218E764, func_0218E7DC, func_0218EC2C, func_0218EC30, func_0218EC54, func_0218EC5C, func_0218EC60, func_0218EC68, func_0218EC7C, func_0218EC90, func_0218ECB4, func_0218ECC4, func_0218ECD4, func_0218ECE4, func_0218ECF4, func_0218ED04, func_0218ED14, func_0218ED20, func_0218ED2C, func_0218ED34, func_0218ED3C, func_0218ED40, func_0218ED48, func_0218ED50, func_0218ED54, func_0218ED58, func_0218ED5C, func_0218ED64, func_0218ED9C, func_0218EEFC, func_0218EFD4, func_0218F004, func_0218F050, func_0218F05C, func_0218F0A8, func_0218F0D4, func_0218F0E8, func_0218F0F8, func_0218F114, func_0218F134, func_0218F14C, func_0218F18C, func_0218F19C, func_0218F1AC, func_0218F1B4, func_0218F1BC, func_0218F1DC, func_0218F1FC, func_0218F310, func_0218F460, func_0218F780, func_0218F7D0, func_0218F818, func_0218F848, func_0218F878, func_0218F89C, func_0218F900, func_0218F918, func_0218F930, func_0218F9C4, func_0218FA40, func_0218FB1C, func_0218FC80, func_0218FD88, func_0218FDD4, func_0218FDF0, func_0218FE40, func_0218FE50, func_0218FE70, func_0218FE78, func_0218FE80, func_0218FE98, func_0218FEA0, func_0218FEA4, func_0218FEC0, func_0218FF00, func_0218FF20, func_0218FF30, func_0218FF48, func_0218FF50, func_0218FF78, func_0218FFE8, func_02190000, func_02190058, func_021900A8, func_021900C4, func_02190110, func_0219014C, func_021901E4, func_021901E8, func_021901EC, func_02190270, func_0219027C, func_021902A4, func_021902AC, func_021902BC, func_02190344, func_02190378, func_02190398, func_021903CC, func_021903E0, func_0219047C, func_02190490, func_0219049C, func_021904A8, func_021904AC, func_021904B0, func_021904C8, func_021904D0, func_021904DC, func_021904EC, func_02190538, func_02190550, func_02190590, func_021905C8, func_02190604, func_0219061C, func_02190620, func_0219063C, func_02190678, func_0219067C, func_02190680, func_02190708, func_02190728, func_02190740, func_02190758, func_02190764, func_0219077C, func_02190788, func_02190794, func_021907A8, func_021907C0, func_021907C4, func_0219082C, func_02190844, func_02190854, func_02190860, func_02190938, func_02190960, func_0219097C, func_02190988, func_021909BC, func_021909E4, func_02190A14, func_02190A20, func_02190A28, func_02190A64, func_02190A6C, func_02190A74, func_02190AC4, func_02190ACC, func_02190AEC, func_02190B08, func_02190B1C, func_02190B2C, func_02190BE4, func_02190C78, func_02190C94, func_02190D08, func_02190D2C, func_02190D48, func_02190D5C, func_02190DCC, func_02190E40, func_02190E74, func_02190EB8, func_02190EF0, func_02190F64, func_02190F7C, func_02190F9C, func_02190FA0, func_02191008, func_0219103C, func_02191084, func_021910C0, func_02191134, func_02191164, func_02191184, func_021911B4, func_021911B8, func_0219129C, func_021912D8, func_021912F8, func_0219131C, func_02191348, func_02191388, func_021914CC, func_02191504, func_02191558, func_021915B4, func_021915EC, func_0219160C, func_0219161C, func_02191648, func_02191674, func_021916A8, func_021916E0, func_02191794, func_021917C0, func_021917C4, func_02191830, func_02191870, func_021918DC, func_0219194C, func_0219196C, func_02191978, func_021919AC, func_021919C8, func_02191A04, func_02191A10, func_02191B14, func_02191BE8, func_02191D88, func_02191DC8, func_02191FA0, func_02192138, func_0219214C, func_021921C8, func_02192244, func_02192264, func_021922A4, func_021924F0, func_02192570, func_02192628, func_0219269C, func_021926D8, func_0219270C, func_0219272C, func_02192788, func_021927B0, func_021927C0, func_021927E8, func_021927F8, func_021927FC
 * address:  0x02189BBC
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
 *   func_02189B28  0x02189B28  thumb  ov021
 *   d_021D373C     0x021D373C  data  a4
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021C868C  0x021C868C  thumb
 *   func_021AE0CC  0x021AE0CC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021A2F20  0x021A2F20  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   func_0217BFD8  0x0217BFD8  thumb  ov018
 *   func_0217CA84  0x0217CA84  thumb  ov018
 *   func_02026454  0x02026454  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_0217B810  0x0217B810  thumb  ov018
 *   func_0217689C  0x0217689C  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_0216B3A8  0x0216B3A8  thumb  ov010
 *   func_021754B4  0x021754B4  thumb  ov011
 *   func_021A2F6C  0x021A2F6C  thumb
 *   func_0217FC6C  0x0217FC6C  thumb  ov018
 *   func_0217BDE0  0x0217BDE0  thumb  ov018
 *   func_0217AFC4  0x0217AFC4  thumb  ov018
 *   func_0217FB5C  0x0217FB5C  thumb  ov018
 *   func_021A3050  0x021A3050  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_02158D90  0x02158D90  thumb  ov010
 *   func_0219F01C  0x0219F01C  thumb
 *   func_02162A54  0x02162A54  thumb  ov010
 *   func_02158768  0x02158768  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021CFAC0  0x021CFAC0  thumb
 *   func_021CFC14  0x021CFC14  thumb
 *   func_021CD440  0x021CD440  thumb
 *   func_02013FFC  0x02013FFC  thumb
 *   func_02162940  0x02162940  thumb  ov010
 *   func_020221A4  0x020221A4  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_0215FF34  0x0215FF34  thumb  ov010
 *   func_021A0ED4  0x021A0ED4  thumb
 *   func_0215FF54  0x0215FF54  thumb  ov010
 *   func_0201212C  0x0201212C  thumb
 *   func_021C06CC  0x021C06CC  thumb
 *   func_021A0F90  0x021A0F90  thumb
 *   func_0215FC40  0x0215FC40  thumb  ov010
 *   func_021A0EB0  0x021A0EB0  thumb
 *   func_0217B410  0x0217B410  thumb  ov018
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA8F8  0x021AA8F8  thumb  ov021
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC5BC  0x021BC5BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3550  0x021A3550  thumb  ov021
 *   func_021A356C  0x021A356C  thumb  ov021
 *   func_02189A70  0x02189A70  thumb  ov021
 *   func_021F3B10  0x021F3B10  thumb  ov053
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_021850FC  0x021850FC  thumb  ov020
 *   func_0217391C  0x0217391C  thumb  ov012
 *   func_02173928  0x02173928  thumb  ov012
 *   func_02026400  0x02026400  thumb
 *   func_0217B80C  0x0217B80C  thumb  ov019
 *   func_0217B83C  0x0217B83C  thumb  ov019
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0217AF38  0x0217AF38  thumb  ov019
 *   func_0215FCE0  0x0215FCE0  thumb  ov010
 *   func_0219E634  0x0219E634  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_02162958  0x02162958  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02162A5C  0x02162A5C  thumb  ov010
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C84  0x02188C84  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021A2FE4  0x021A2FE4  thumb
 *   func_021A3080  0x021A3080  thumb
 *   func_021A308C  0x021A308C  thumb
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02014478  0x02014478  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021A3584  0x021A3584  thumb
 *   func_021A1358  0x021A1358  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   func_021F2AB8  0x021F2AB8  thumb  ov029
 *   func_021F2AD4  0x021F2AD4  thumb  ov029
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02014474  0x02014474  thumb
 *   func_02158B00  0x02158B00  thumb  ov010
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB188  0x021AB188  thumb
 *   func_02162928  0x02162928  thumb  ov010
 *   func_021A2FA4  0x021A2FA4  thumb
 *   func_0217B4D8  0x0217B4D8  thumb ov018
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_021A3098  0x021A3098  thumb
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 *   func_02188C80  0x02188C80  thumb
 *   func_02008970  0x02008970  thumb
 *   func_0200896C  0x0200896C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3378  0x021C3378  thumb
 *   func_02008978  0x02008978  thumb
 *   func_02008980  0x02008980  thumb
 *   func_02008854  0x02008854  thumb
 *   func_021D220C  0x021D220C  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02008988  0x02008988  thumb
 *   func_0200D564  0x0200D564  thumb
 *   func_021AA944  0x021AA944  thumb
 *   func_021AA80C  0x021AA80C  thumb
 *   func_02010F18  0x02010F18  thumb
 *   func_020124AC  0x020124AC  thumb
 *   abs_id_83      0x00000053  data
 *   func_021F532C  0x021F532C  thumb  ov083
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_021C8A74  0x021C8A74  thumb
 *   func_021C8A30  0x021C8A30  thumb
 *   func_021C8CF0  0x021C8CF0  thumb
 *   func_021C8C88  0x021C8C88  thumb
 *   func_021626A8  0x021626A8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02185410  0x02185410  thumb  ov020
 *   func_02185360  0x02185360  thumb  ov020
 *   func_02014110  0x02014110  thumb
 *   func_02012878  0x02012878  thumb
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021626B8  0x021626B8  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021BE288  0x021BE288  thumb  ov021
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_021F38A4  0x021F38A4  thumb  ov051
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021F404C  0x021F404C  thumb  ov039
 *   func_021F37E0  0x021F37E0  thumb  ov041
 *   func_02162598  0x02162598  thumb  ov010
 *   func_02013DD0  0x02013DD0  thumb
 *   func_021AA248  0x021AA248  thumb
 *   func_021A9F40  0x021A9F40  thumb
 *   func_021BB188  0x021BB188  thumb
 *   func_0219E418  0x0219E418  thumb
 *   func_021C46F8  0x021C46F8  thumb
 *   func_02014134  0x02014134  thumb
 *   func_021626B0  0x021626B0  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb
 *   func_021ACBB8  0x021ACBB8  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_021A2F60  0x021A2F60  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021A2FD0  0x021A2FD0  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021A35A0  0x021A35A0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021A3364  0x021A3364  thumb
 *   func_021AB2E8  0x021AB2E8  thumb
 *   func_021A3460  0x021A3460  thumb
 *   func_02164294  0x02164294  thumb  ov010
 *   func_021AB194  0x021AB194  thumb
 *   func_02164240  0x02164240  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0219E570  0x0219E570  thumb  ov021
 *   func_021A3128  0x021A3128  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_021A3504  0x021A3504  thumb
 *   func_021A3524  0x021A3524  thumb
 *   data_021D3CE8  0x021D3CE8  data
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DD9CC     0x021DD9CC  data  ov021  a4
 *   func_020307B0  0x020307B0  arm
 *   func_02013B38  0x02013B38  thumb
 *   func_020140D8  0x020140D8  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204961C  0x0204961C  arm
 *   func_02049250  0x02049250  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02046DB8  0x02046DB8  arm
 *   func_020470A8  0x020470A8  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   d_021D3DC4     0x021D3DC4  data  a4
 *   func_020113D8  0x020113D8  thumb
 *   d_021D3D50     0x021D3D50  data  a4
 *   func_02046C94  0x02046C94  arm
 *   func_02046CE0  0x02046CE0  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   d_021D3D58     0x021D3D58  data   a4
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 *   func_0204779C  0x0204779C  arm
 *   func_02047790  0x02047790  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047788  0x02047788  arm
 *   func_02047738  0x02047738  arm
 *   func_02047504  0x02047504  arm
 *   d_021D3D5C     0x021D3D5C  data  a4
 *   func_02047910  0x02047910  arm
 *   func_020478B8  0x020478B8  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047674  0x02047674  arm
 *   func_020477D4  0x020477D4  arm
 *   func_02047828  0x02047828  arm
 *   func_021693D4  0x021693D4  thumb  ov010
 *   func_02169444  0x02169444  thumb  ov010
 *   func_0216940C  0x0216940C  thumb
 *   func_02169510  0x02169510  thumb
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0207AF1C  0x0207AF1C  thumb
 *   d_020A1B38     0x020A1B38  data   a2
 *   func_02047A60  0x02047A60  arm
 *   d_021D3D88     0x021D3D88  data   a2
 *   d_021D3D8A     0x021D3D8A  data   a2
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   d_021DD9EC     0x021DD9EC  data  ov021  a4
 *   func_021938AC  0x021938AC  thumb ov021
 *   func_021C05D4  0x021C05D4  thumb ov021
 *   func_021C0674  0x021C0674  thumb  ov021
 *   func_021938D4  0x021938D4  thumb  ov021
 *   func_0216932C  0x0216932C  thumb ov010
 *   sub_0207C768   0x0207C768  arm
 *   func_02169520  0x02169520  thumb  ov010
 *   func_02169308  0x02169308  thumb  ov010
 *   func_0207C768  0x0207C768  arm
 *   func_021A73DC  0x021A73DC  thumb  ov021
 *   func_02169500  0x02169500  thumb ov010
 *   func_02169354  0x02169354  thumb ov010
 *   func_02159BF4  0x02159BF4  thumb
 *   func_02159BF8  0x02159BF8  thumb
 *   func_02159BFC  0x02159BFC  thumb
 *   func_02159C20  0x02159C20  thumb
 *   func_02159C00  0x02159C00  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02012974  0x02012974  thumb
 *   d_021D3DDC     0x021D3DDC  data
 *   func_02169148  0x02169148  thumb  ov010
 *   func_0216937C  0x0216937C  thumb  ov010
 *   func_021693B4  0x021693B4  thumb  ov010
 *   func_021693C4  0x021693C4  thumb  ov010
 *   func_021693CC  0x021693CC  thumb ov010
 *   func_021693BC  0x021693BC  thumb ov010
 *   func_021693A0  0x021693A0  thumb ov010
 *   func_0216928C  0x0216928C  thumb ov010
 *   func_021A73C0  0x021A73C0  thumb ov021
 *   func_02022040  0x02022040  thumb
 *   func_021694FC  0x021694FC  thumb ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_021694F8  0x021694F8  thumb ov010
 *   func_021694D4  0x021694D4  thumb ov010
 *   func_02169470  0x02169470  thumb ov010
 *   func_02169800  0x02169800  thumb ov010
 *   func_021AB100  0x021AB100  thumb ov021
 *   func_02169848  0x02169848  thumb  ov010
 *   func_021697E0  0x021697E0  thumb ov010
 *   func_02193B04  0x02193B04  thumb  ov021
 *   d_021DD9E0     0x021DD9E0  data ov021 a2
 *   g_021DD9E0     0x021DD9E0  data ov021 a2
 *   func_021A7360  0x021A7360  thumb ov021
 *   func_021A7404  0x021A7404  thumb  ov021
 *   func_021A7418  0x021A7418  thumb
 *   d_021D3DD4     0x021D3DD4  data a2
 *   func_021C0688  0x021C0688  thumb ov021
 *   func_021C068C  0x021C068C  thumb ov021
 *   func_021C06B4  0x021C06B4  thumb ov021
 *   func_021C06A8  0x021C06A8  thumb ov021
 *   g_02FFFC3C  0x02FFFC3C  data  a4
 *   func_02169598  0x02169598  thumb ov010
 *   func_02169538  0x02169538  thumb ov010
 *   d_021DDA28     0x021DDA28  data  ov021  a4
 *   func_02048B78  0x02048B78  arm
 *   func_02048B88  0x02048B88  arm
 *   func_0207D184  0x0207D184  arm
 *   d_021DDA0C  0x021DDA0C  data  ov021  a4
 *   d_021DDA00  0x021DDA00  data  ov021  a4
 *   func_02046BE0  0x02046BE0  arm
 *   func_02048B80  0x02048B80  arm
 *   func_02048B94  0x02048B94  arm
 *   tbl_020A1B38   0x020A1B38  data
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048AFC  0x02048AFC  arm
 *   d_021D3E44  0x021D3E44  data  ov021  a4
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CA68  0x0207CA68  arm
 *   d_021D3E2C     0x021D3E2C  data   ov021  a4
 *   func_02048B20  0x02048B20  arm
 *   func_02048B0C  0x02048B0C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02082D44   0x02082D44  arm
 *   func_0204A380  0x0204A380  arm
 *   d_021DDA18  0x021DDA18  data  ov021  a4
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   VEC_Subtract     0x0207CA00  arm
 *   VEC_Mag          0x0207CBD0  arm
 *   FX_Modf          0x0207D14C  arm
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   d_021D3E38       0x021D3E38  data   a4
 *   d_021DDA38  0x021DDA38  data  ov021  a4
 *   func_02188C58  0x02188C58  thumb
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_02189A18  0x02189A18  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 *   func_021C7058  0x021C7058  thumb  ov021
 *   func_021C701C  0x021C701C  thumb  ov021
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7C10  0x021C7C10  thumb  ov021
 *   func_021C7AE4  0x021C7AE4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_021931F4  0x021931F4  thumb
 *   d_021DDA50  0x021DDA50  data  ov021  a4
 *   func_02192BD0  0x02192BD0  thumb
 *   func_02192CF0  0x02192CF0  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02192EB8  0x02192EB8  thumb
 *   func_02192FA4  0x02192FA4  thumb
 *   func_02192FEC  0x02192FEC  thumb  ov021
 *   func_02194798  0x02194798  thumb  ov021
 *   func_02031140  0x02031140  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02192E0C  0x02192E0C  thumb  ov021
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0219470C  0x0219470C  thumb  ov021
 *   func_02194760  0x02194760  thumb  ov021
 *   func_02194764  0x02194764  thumb  ov021
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02193208  0x02193208  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201C724  0x0201C724  thumb  arm9
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02043AF4  0x02043AF4  arm  arm9
 *   func_02192F74  0x02192F74  thumb  ov021
 *   func_02193044  0x02193044  thumb  ov021
 *   func_021930C0  0x021930C0  thumb  ov021
 *   func_02193144  0x02193144  thumb  ov021
 *   func_02193170  0x02193170  thumb  ov021
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02192B20  0x02192B20  thumb  ov021
 *   func_02192BC0  0x02192BC0  thumb  ov021
 *   func_0201FF30  0x0201FF30  thumb
 *   func_02020CF8  0x02020CF8  thumb
 *   func_02020D10  0x02020D10  thumb  arm9
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_020200CC  0x020200CC  thumb  arm9
 *   func_02020234  0x02020234  thumb
 *   func_0201F81C  0x0201F81C  thumb
 *   func_0201F878  0x0201F878  thumb  arm9
 *   func_0201F898  0x0201F898  thumb
 *   func_0201F8F4  0x0201F8F4  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201F91C  0x0201F91C  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021D3F38     0x021D3F38  data   ov021  a4
 *   d_021D3E68     0x021D3E68  data   ov021  a4
 *   func_0201CD10  0x0201CD10  thumb
 *   func_02193200  0x02193200  thumb  ov021
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_02006238  0x02006238  thumb  arm9
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE34  0x0201CE34  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_02193228  0x02193228  thumb  ov021
 *   func_02193260  0x02193260  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_021932A0  0x021932A0  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_02194848  0x02194848  thumb  ov021
 *   func_02194888  0x02194888  thumb  ov021
 *   func_021948CC  0x021948CC  thumb  ov021
 *   func_02194940  0x02194940  thumb  ov021
 *   func_02194950  0x02194950  thumb  ov021
 *   func_02194960  0x02194960  thumb  ov021
 *   func_0219492C  0x0219492C  thumb  ov021
 *   func_02194990  0x02194990  thumb  ov021
 *   func_0219499C  0x0219499C  thumb  ov021
 *   func_02194974  0x02194974  thumb  ov021
 *   func_02194984  0x02194984  thumb  ov021
 *   func_02040618  0x02040618  arm
 *   func_02194A00  0x02194A00  thumb  ov021
 *   func_02194A48  0x02194A48  thumb  ov021
 *   func_02194A34  0x02194A34  thumb  ov021
 *   func_021947E8  0x021947E8  thumb  ov021
 *   func_0201D42C  0x0201D42C  thumb  arm9
 *   func_0219319C  0x0219319C  thumb  ov021
 *   func_020458F8  0x020458F8  arm
 *   func_02045838  0x02045838  arm
 *   func_021931C4  0x021931C4  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02043678  0x02043678  arm
 *   func_02045374  0x02045374  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02041300  0x02041300  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_02043814  0x02043814  arm
 *   func_02049624  0x02049624  arm
 *   func_02049B90  0x02049B90  arm
 *   func_0201D37C  0x0201D37C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb  arm9
 *   func_020437DC  0x020437DC  arm  arm9
 *   func_020437E4  0x020437E4  arm  arm9
 *   func_020439A0  0x020439A0  arm  arm9
 *   func_020437D4  0x020437D4  arm  arm9
 *   func_0204A1BC  0x0204A1BC  arm  arm9
 *   func_02062A4C  0x02062A4C  arm  arm9
 *   func_02082EA4  0x02082EA4  arm  arm9
 *   func_0201DC80  0x0201DC80  thumb
 *   func_021928F8  0x021928F8  thumb  ov021
 *   func_02045874  0x02045874  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020436FC  0x020436FC  arm  arm9
 *   d_021D3E50     0x021D3E50  data   ov021  a1
 */
#include "../../matched/include/G__anon_Ent.h"
#include "../../matched/include/Obj04981.h"
#include "../../matched/include/Obj00705.h"
#include "../../matched/include/Obj04982.h"
#include "../../matched/include/Obj04983.h"
#include "../../matched/include/Obj09449.h"
#include "../../matched/include/Obj19510.h"
#include "../../matched/include/Obj05974.h"
#include "../../matched/include/Obj07410.h"
#include "../../matched/include/Obj19511.h"
#include "../../matched/include/Obj02071.h"
#include "../../matched/include/Obj12562.h"
#include "../../matched/include/Obj09453.h"
#include "../../matched/include/Obj17893.h"
#include "../../matched/include/Obj00572.h"
#include "../../matched/include/Obj01114.h"
#include "../../matched/include/Obj17894.h"
#include "../../matched/include/Obj17895.h"
#include "../../matched/include/Obj07411.h"
#include "../../matched/include/Obj04986.h"
#include "../../matched/include/Obj09454.h"
#include "../../matched/include/Obj19518.h"
#include "../../matched/include/G_Ops.h"
#include "../../matched/include/Obj04988.h"
#include "../../matched/include/Obj03573.h"
#include "../../matched/include/Obj09173.h"
#include "../../matched/include/Obj19535.h"
#include "../../matched/include/Obj19537.h"
#include "../../matched/include/Obj12572.h"
#include "../../matched/include/Obj12574.h"
#include "../../matched/include/Obj04199.h"
#include "../../matched/include/Obj04200.h"
#include "../../matched/include/Obj12576.h"
#include "../../matched/include/Obj09456.h"
#include "../../matched/include/Obj19538.h"
#include "../../matched/include/Obj19539.h"
#include "../../matched/include/Obj19540.h"
#include "../../matched/include/Obj19541.h"
#include "../../matched/include/Obj19544.h"
#include "../../matched/include/Obj19545.h"
#include "../../matched/include/Obj01115.h"
#include "../../matched/include/Obj05856.h"
#include "../../matched/include/Obj00806.h"
#include "../../matched/include/Obj00807.h"
#include "../../matched/include/Obj02072.h"
#include "../../matched/include/Obj19549.h"
#include "../../matched/include/Obj01208.h"
#include "../../matched/include/Obj12581.h"
#include "../../matched/include/Obj07415.h"
#include "../../matched/include/Obj19550.h"
#include "../../matched/include/Obj07416.h"
#include "../../matched/include/Obj01846.h"
#include "../../matched/include/Obj02687.h"
#include "../../matched/include/Obj01652.h"
#include "../../matched/include/Obj02688.h"
#include "../../matched/include/Obj05857.h"
#include "../../matched/include/Obj19551.h"
#include "../../matched/include/Obj02370.h"
#include "../../matched/include/Obj04201.h"
#include "../../matched/include/Obj12585.h"
#include "../../matched/include/Obj17896.h"
#include "../../matched/include/Obj17897.h"
#include "../../matched/include/Obj12063.h"
#include "../../matched/include/Obj17898.h"
#include "../../matched/include/Obj19552.h"
#include "../../matched/include/Obj19553.h"
#include "../../matched/include/Obj17899.h"
#include "../../matched/include/Obj00165.h"
#include "../../matched/include/Obj05978.h"
#include "../../matched/include/Obj07208.h"
#include "../../matched/include/Obj17902.h"
#include "../../matched/include/Obj17903.h"
#include "../../matched/include/Obj17904.h"
#include "../../matched/include/Obj09174.h"
#include "../../matched/include/Obj03107.h"
#include "../../matched/include/Obj12588.h"
#include "../../matched/include/Obj01847.h"
#include "../../matched/include/Obj19554.h"
#include "../../matched/include/Obj02689.h"
#include "../../matched/include/Obj04990.h"
#include "../../matched/include/Obj00519.h"
#include "../../matched/include/Obj04202.h"
#include "../../matched/include/Obj01653.h"
#include "../../matched/include/Obj19556.h"
#include "../../matched/include/Obj17905.h"
#include "../../matched/include/Obj19557.h"
#include "../../matched/include/Obj19558.h"
#include "../../matched/include/Obj01347.h"
#include "../../matched/include/Obj09175.h"
#include "../../matched/include/Obj00428.h"
#include "../../matched/include/Obj01848.h"
#include "../../matched/include/Obj17906.h"
#include "../../matched/include/Obj17907.h"
#include "../../matched/include/Obj17908.h"
#include "../../matched/include/Obj19562.h"
#include "../../matched/include/Obj19563.h"
#include "../../matched/include/Obj19564.h"
#include "../../matched/include/Obj19565.h"
#include "../../matched/include/Obj17909.h"
#include "../../matched/include/Obj17910.h"
#include "../../matched/include/Obj17911.h"
#include "../../matched/include/Obj17912.h"
#include "../../matched/include/Obj17913.h"
#include "../../matched/include/Obj17914.h"
#include "../../matched/include/Obj05979.h"
#include "../../matched/include/Obj12593.h"
#include "../../matched/include/Obj19566.h"
#include "../../matched/include/Obj19567.h"
#include "../../matched/include/Obj00612.h"
#include "../../matched/include/Obj09464.h"
#include "../../matched/include/Obj19568.h"
#include "../../matched/include/Obj19569.h"
#include "../../matched/include/Obj12594.h"
#include "../../matched/include/Obj19570.h"
#include "../../matched/include/Obj09465.h"
#include "../../matched/include/Obj17915.h"
#include "../../matched/include/Obj17916.h"
#include "../../matched/include/Obj02371.h"
#include "../../matched/include/Obj07419.h"
#include "../../matched/include/Obj07420.h"
#include "../../matched/include/Obj07423.h"
#include "../../matched/include/Obj07424.h"
#include "../../matched/include/Obj19572.h"
#include "../../matched/include/Obj05980.h"
#include "../../matched/include/Obj01117.h"
#include "../../matched/include/Obj12597.h"
#include "../../matched/include/Obj00752.h"
#include "../../matched/include/Obj01491.h"
#include "../../matched/include/Obj01348.h"
#include "../../matched/include/Obj19576.h"
#include "../../matched/include/Obj17917.h"
#include "../../matched/include/Obj02372.h"
#include "../../matched/include/Obj09470.h"
#include "../../matched/include/Obj17918.h"
#include "../../matched/include/Obj04204.h"
#include "../../matched/include/Obj12599.h"
#include "../../matched/include/Obj19578.h"
#include "../../matched/include/Obj19579.h"
#include "../../matched/include/Obj09472.h"
#include "../../matched/include/Obj19581.h"
#include "../../matched/include/Obj17919.h"
#include "../../matched/include/Obj17920.h"
#include "../../matched/include/Obj01849.h"
#include "../../matched/include/Obj12600.h"
#include "../../matched/include/Obj04205.h"
#include "../../matched/include/Obj09473.h"
#include "../../matched/include/Obj19582.h"
#include "../../matched/include/Obj19583.h"
#include "../../matched/include/Obj17921.h"
#include "../../matched/include/Obj17922.h"
#include "../../matched/include/Obj17923.h"
#include "../../matched/include/Obj17924.h"
#include "../../matched/include/Obj00126.h"
#include "../../matched/include/Obj12064.h"
#include "../../matched/include/Obj17926.h"
#include "../../matched/include/Obj12065.h"
#include "../../matched/include/Obj12066.h"
#include "../../matched/include/Obj17927.h"
#include "../../matched/include/Obj17928.h"
#include "../../matched/include/Obj17929.h"
#include "../../matched/include/Obj17930.h"
#include "../../matched/include/Obj12067.h"
#include "../../matched/include/Obj07430.h"
#include "../../matched/include/Obj19589.h"
#include "../../matched/include/Obj07209.h"
#include "../../matched/include/Obj19590.h"
#include "../../matched/include/Obj05858.h"
#include "../../matched/include/Obj17931.h"
#include "../../matched/include/Obj07432.h"
#include "../../matched/include/Obj07433.h"
#include "../../matched/include/Obj17932.h"
#include "../../matched/include/Obj04888.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj17934.h"
#include "../../matched/include/Obj03112.h"
#include "../../matched/include/Obj07210.h"
#include "../../matched/include/Obj17935.h"
#include "../../matched/include/Obj12612.h"
#include "../../matched/include/Obj19604.h"
#include "../../matched/include/Obj12068.h"
#include "../../matched/include/Obj17936.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct Obj00020;
struct Big;
struct Ctx738;
struct Ctx9B0;
struct FieldCtx_02189BBC;
struct BigObj;
struct Ctx;
struct Desc;
struct VecFx32;
struct Comm;
struct Ctx784;
struct Sub02014444Obj;
struct SoundSys;
struct Sub02008C20Obj;
struct Rec;
struct Sub02008828Obj;
struct Blk38;
struct Self;
struct Rec1C;
struct Q;
struct Obj_02189BBC;
struct Sub020140BCObj;
struct ArcFile;
struct Tagged;
struct S02046CE0;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct AnmCtl;
struct Owner;
struct V3_0218C518;
struct Arg;
struct Cam;
struct Cell_0218C518;
struct Obj;
struct Mgr;
struct D;
struct Light;
struct GfFont;
struct NitroFileHeader;
struct Tcbl;
struct PrintSys;
struct S02031140;
struct U16Vec;
struct Descriptor;
struct MsgBank;
struct CharBuf;
struct Bmp;
struct W;
struct Slot;
struct Obj_02190680;
struct Dst;
struct Obj_02190344;
struct Src;
struct Handle_02190344;
struct StrObj;
struct Pair;
struct Rec3;
struct G;
struct Cur;
struct Obj2;
struct Fx_0218E610;
struct E;
struct Cfg;
struct Obj020437AC;
struct Font;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

struct FieldInput_02189BBC {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    u32 f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
    u32 trg;
    u32 cont;
    u16 dir;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
};

typedef signed int     s32;

typedef struct Cell_02189BBC { u16 x, y, z, w; } Cell_02189BBC;

typedef signed char    s8;

struct FieldInput_0218A4E0 {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    void *f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
    u32 trg;
    u32 cont;
    u16 dir;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
};

struct Ctx738 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    char pad0C[0x1A];
    u16 f26;
};

struct Ctx784 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
};

struct FieldCtx_02189BBC {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    char pad10[0x08];
    void *f18;
    u32 f1C;
    char pad20[0x04];
    u16 f24;
    u16 f26;
    char pad28[0x04];
    u32 f2C;
};

struct BgEvent {
    u16 msg;
    char pad02[0x06];
    u16 f8;
    struct {
        u16 x;
        u16 z;
        u16 w;
        u16 h;
    } rect;
};

struct Ctx9B0 {
    char pad00[0x08];
    void *f8;
    char pad0C[0x04];
    u16 f10;
    char pad12[0x2A];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
};

struct FieldCtx_0218AD28 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

typedef struct Vec_02189BBC { int x, y, z; } Vec_02189BBC;

typedef struct Obj_02189BBC {
    char pad[0x24];
    unsigned short dir;     /* 0x24 */
    char pad26[0x34 - 0x26];
    Vec_02189BBC *pos;               /* 0x34 */
} Obj_02189BBC;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    void *f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
};

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

typedef struct {
    int f0;
    short f4;
    short f6;
    int f8;
    int fC;
} Ent_02189BBC;

struct FieldCtx_0218B4B0 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

struct FieldCtx_0218B56C {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x08];
    u16 f24;
};

struct TileMsg {
    int (*test)(u16 attr);
    u16 dir;
    u16 msg;
};

typedef struct {
    int cur;
    int prev;
    int changed;
    unsigned char val;
    unsigned char id;
} S_0218BCF4;

typedef struct {
    int f0;
    unsigned short id;
    short x;
    short y;
    short z;
} Ent_0218B924;

typedef struct {
    int x;
    int y;
    int z;
} Vec_0218B924;

typedef struct {
    int x;
    int y;
    int z;
    unsigned short w;
    unsigned char hi;
    unsigned char lo;
} Src_02189BBC;

typedef struct {
    int k;
    Vec_0218B924 pos;
    unsigned short w;
} Args_0218B924;

typedef struct {
    int k;
    int x;
    int y;
    int z;
    unsigned short w;
} Args_0218BA04;

typedef struct {
    void *key;
    int b;
    unsigned short c;
    unsigned short d;
    int e;
} EntSlot;


typedef struct {
    unsigned char b[16];
} Tbl;

typedef struct {
    int f0;
    void *f4;
    void *arr[4];
} S_0218BDD8;

typedef void (*Fn)(void *a, u32 *out);

typedef struct {
    Fn fn;
    u32 pad[2];
} Entry_02189BBC;

typedef struct {
    void (*f0)(void *p, void *s);
    void (*f4)(void *p, int idx, int c);
    void (*f8)(void);
} Ops;

typedef struct {
    int f0;
    int *f4;
} Obj_0218BDD8;

typedef struct {
    int h;
    int f4;
    int arr[4];
} S_0218C154;

typedef struct {
    int f0;
    int f4;
    short f8;
    short fA;
    int *fC;
} S_0218C54C;

typedef struct {
    int a, b, c;
    int *d;
} S_0218C574;

typedef struct {
    int x;
    int y;
    int z;
} Vec_0218C518;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Rect;

typedef struct {
    int obj;
    int pad[2];
    u8 *ref;
} Ent_0218C518;

typedef struct Blk {
    u32 w[15];
} Blk;

typedef struct {
    void *owner;
    int f4;
    void *f8;
    unsigned char fC[1];
} S_0218C518;

typedef struct FieldMsgbgWork {
    unsigned short f0;
    unsigned short f2;
    int f4;
    u8 pad08[0x18 - 0x8];
    unsigned int f18;
    unsigned char f1C[0x190];
    unsigned short f1AC;
    u8 pad1AE[0x1C8 - 0x1AE];
    unsigned int f1C8;
    unsigned char *f1CC;
    u8 pad1D0[0x1D4 - 0x1D0];
    unsigned int f1D4;
    unsigned char *f1D8;
    void *f1DC[7];
    EntSlot f1F8[0x120];
} FieldMsgbgWork;

typedef struct {
    int h;
    unsigned char pad[0x24];
} Ent_0218CC34;

typedef struct {
    unsigned char pad[0x1C];
    int f1C;
    int f20;
    Ent_0218CC34 *f24;
    unsigned char pad2[6];
    unsigned short n;
} S_0218CA78;

typedef struct {
    u32 v;
} Tile;

typedef struct {
    u8 pad0[0x18];
    u32 pos;
    u8 pad1[0x28 - 0x1C];
} Ent_0218CD20;

typedef struct {
    u16 heap;
    u8 pad0[0x12];
    u16 w;
    u16 h;
    u32 n;
    Tile *tiles;
    u32 pad1;
    Ent_0218CD20 *ents;
    u8 pad2[0x2E - 0x28];
    u16 nEnts;
    u32 pos;
} Map;

typedef struct Cfg {
    u32 size;
    u32 texSize;
    u32 f08;
    void *f0c;
    u32 f10;
    u16 nA;
    u16 nB;
    u32 f18;
    u32 f1c;
} Cfg;

typedef struct Src_0218C518 {
    int f00;
    int f04;
    u16 cols;
    u16 rows;
    u32 type;
    int f10;
    u16 f14;
    u16 f16;
    u32 n;
    int f1c;
    int f20;
    int f24[2];
    int f2c[2];
    int f34;
    u8 f38;
} Src_0218C518;

typedef struct Obj {
    u16 heap;
    u16 pad02;
    int f04;
    int f08;
    u32 type;
    int f10;
    u16 f14;
    u16 f16;
    u32 n;
    int f1c;
    int f20;
    u8 *f24;
    void *f28;
    u8 f2c;
    u8 f2d;
    u16 f2e;
    u8 pad30[0x40 - 0x30];
    u8 f40;
    u8 pad41;
    u8 f42;
    u8 f43;
    void *f44;
    u8 pad48[0x60 - 0x48];
    int f60;
    int f64;
    int f68;
} Obj;

typedef struct V3_0218C518 { s32 x, y, z; } V3_0218C518;

typedef struct T_02189BBC {
    char pad[0x34];
    V3_0218C518 v;
} T_02189BBC;

typedef long long fx64;

typedef struct Cell_0218C518 {
    u32 id;
    int x;
    int y;
    int z;
} Cell_0218C518;

typedef struct Cam {
    u32 f0;
    u32 pos;
} Cam;

typedef struct Obj_0218D570 {
    u16 heap;
    u8 pad02[2];
    s32 size;
    s32 height;
    u32 mode;
    u32 f10;
    u16 w;
    u16 h;
    u32 count;
} Obj_0218D570;

typedef struct Vec_0218D570 {
    int x;
    int y;
    int z;
} Vec_0218D570;

typedef struct Entry_0218C518 {
    int obj;            /* 0x00 */
    u8 desc[0x14];      /* 0x04 */
    Cell_0218C518 cell;          /* 0x18 */
} Entry_0218C518;

typedef struct Obj_0218D7A8 {
    u16 heap;           /* 0x00 */
    u8 pad02[2];
    int size;           /* 0x04 */
    int height;         /* 0x08 */
    u32 mode;           /* 0x0C */
    u32 f10;            /* 0x10 */
    u16 w;              /* 0x14 */
    u16 h;              /* 0x16 */
    u32 count;          /* 0x18 */
    int *table;         /* 0x1C */
    u32 f20;            /* 0x20 */
    Entry_0218C518 *entries;     /* 0x24 */
    Cell_0218C518 *f28;          /* 0x28 */
    u8 cols;            /* 0x2C */
    u8 rows;            /* 0x2D */
    u16 n;              /* 0x2E */
    u8 pad30[0x64 - 0x30];
    int f64;            /* 0x64 */
} Obj_0218D7A8;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    int d;
    int e;
} Ent_0218D570;

typedef struct {
    Ent_0218D570 e[16];
    u32 count;
} Hits;

typedef struct {
    Ent_0218D570 e[16];
    u16 count;
} List;

typedef struct { u16 a; u16 b; u16 c; u16 d; int p; int q; } E_0218D570;

typedef struct { E_0218D570 e[16]; u16 n; } B_02189BBC;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct Grid {
    u32 f00;
    s32 f04;            /* 0x04 cell size */
    u32 f08;
    u32 f0C;            /* 0x0C state */
    u32 f10;
    u16 f14;            /* 0x14 width in cells */
    u16 f16;            /* 0x16 depth in cells */
    u32 f18;
    void *f1C;          /* 0x1C */
} Grid;

typedef struct { int x, y, z; } V3_0218D570;

typedef struct { u32 a, b, c; } Vec3;

typedef struct { u16 a; u16 b; u16 c; } S6;

typedef void (*StateFunc_02189BBC)(void *a);

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    u8 e;
    u8 mode;
    u16 ang;
    int f;
    int g;
    int has;
    Vec v;
} Info;

typedef struct { int x, y, z; } V;

typedef void (*StateFunc_0218E58C)(void *a, u32 b);

typedef struct { s16 x, y, z; } VS;

typedef struct { u32 a, b, c; } Vec3_0218EC30;

typedef struct { u32 a, b, c; } Vec3_0218EC90;

typedef struct { u32 a, b, c; } Vec3_0218ECB4;

typedef struct { u32 a, b, c; } Vec3_0218ECC4;

typedef struct { u32 a, b, c; } Vec3_0218ECD4;

typedef struct { u32 a, b, c; } Vec3_0218ECE4;

typedef struct { u32 a, b, c; } Vec3_0218ECF4;

typedef struct Vec_0218ED04 {
    int x, y, z;
} Vec_0218ED04;

typedef struct {
    int x;
    int y;
    int z;
} Vec_0218ED9C;

typedef struct {
    int n;
    int rd;
    int wr;
    int delay;
    int full;
    int keepX;
    int keepY;
    int keepZ;
    Vec_0218ED9C *a;
    Vec_0218ED9C *b;
    int on;
    int hold;
} Delay;

typedef struct { int x, y, z; } Vec3_0218EEFC;

typedef struct {
    int count;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 flag1;
    u32 flag2;
    u32 flag4;
    Vec3_0218EEFC *bufA;
    Vec3_0218EEFC *bufB;
    u32 unk28;
    u32 unk2C;
} Track;

typedef void (*Handler)(void *a, u32 b, u32 c);

typedef struct {
    char pad00[8];
    int x0;
    int x1;
    int z0;
    int z1;
} Box;

typedef struct {
    char pad00[8];
    int cx;
    int cz;
    int rmax;
    u16 amax;
    u16 amin;
} Ring;

typedef struct { u32 a, b, c; } V3_0218E610;

typedef struct {
    u32 saved;
    u8 body[0x94];
    u32 active;
} Sub_0218E610;

typedef struct { u32 w[12]; } B48;

typedef struct { u32 w[6]; } B24;

typedef struct { u32 w[3]; } B12;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u16 pad0c[3];
    u16 h12;
    u32 pad14[2];
    u32 flag;
    B12 v;
} Rec;

typedef struct { int x, y, z; } Vec3_0218FD88;

typedef struct {
    u32 saved;
    u8 body[0x94];
    u32 active;
    u32 unk9c;
} Sub_0218F900;

typedef struct { u32 a, b, c; } Vec3_021900A8;

typedef struct {
    u16 h0;
    u16 h2;
    u32 w4;
    Vec3 v8;
    Vec3 v14;
} Params;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef struct Obj_0218E610 {
    u16  f00;
    u16  f02;
    u16  f04;
    u16  f06;
    u32  f08;
    u32  f0c;
    Slot slot[4];
} Obj_0218E610;

typedef struct Link_02190344 {
    u32  f00;
    u32  f04;
    u32  f08;
    u32  f0c;
    Slot slot[4];
    u32  f0a0[8];
} Link_02190344;

typedef struct Slot_021904EC {
    u32 *f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot_021904EC;

typedef struct Fx_0218E610 {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u32 f08;
} Fx_0218E610;

typedef struct Obj_02190680 {
    u32 id;
    u32 slot;
    Fx_0218E610 *owner;
} Obj_02190680;

typedef struct Obj_02190344 {
    u32 id;
    u32 slot;
    Fx_0218E610 *owner;
} Obj_02190344;

typedef struct {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0c;
    u8  pad10[0xc];
    u32 w1c;
    u8  pad20[4];
    u32 w24;
    u32 w28;
    u32 w2c;
    u32 w30;
} Tmpl;

typedef struct {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle_02190344;

typedef struct Pair {
    u32 a;
    u32 b;
} Pair;

typedef struct Src {
    u16 a00;
    u16 a02;
    u8  a04;
    u8  a05;
    u8  a06;
    u8  a07lo : 4;
    u8  a07hi : 4;
    u8  a08lo : 4;
    u8  a08hi : 4;
    u8  pad09;
    u16 a0a_lo : 3;
    u16 a0a_mid : 4;
    u16 a0a_hi : 9;
    int a0c : 2;
    int pad0c : 30;
    u16 a10;
    u16 a12;
    u8  pad14[8];
    u32 a1c;
} Src;

typedef struct Dst {
    u8  pad00[8];
    u32 d08;
    u8  pad0c[4];
    u16 d10;
    u16 d12;
    u8  d14;
    u8  d15;
    u8  d16;
    u8  d17lo : 4;
    u8  d17hi : 4;
    u8  d18lo : 4;
    u8  d18hi : 4;
    u8  pad19;
    u16 d1a_lo : 3;
    u16 d1a_mid : 4;
    u16 d1a_z : 2;
    u16 d1a_hi : 7;
    u8  pad1c[4];
    u16 d20;
    u16 d22;
} Dst;

typedef struct Blk32 { u32 w[8]; } Blk32;

typedef struct Blk16 { u32 w[4]; } Blk16;

typedef struct Handle_02190A28 {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle_02190A28;

typedef struct Obj2 {
    u32 id;
    u32 f04;
    u32 f08;
    u32 b;
    u32 f10;
    Fx_0218E610 *owner;
    u32 sub[2];
} Obj2;

typedef struct P_0218E610 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    Fx_0218E610 *f14;
} P_0218E610;

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

typedef struct { u32 x, y, z; } V3_02190344;

typedef struct { u32 f0; u32 f4; } S15C;

typedef struct A { u16 h[4]; u8 pad[0x15C - 8]; S15C s; } A;

typedef struct B_0218E610 {
    u8 f00;
    u8 mode;
    u16 f02;
    u32 f04;
    u32 f08;
    u32 f0c[2];
    A *a;
    V3_02190344 *v;
    V3_02190344 pos;
} B_0218E610;

typedef struct Ent {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad[0x28];
} Ent;

typedef struct S {
    u8  f00;
    u8  f01;
    u8  pad02[6];
    u32 f08;
    u32 sub[2];
    u8 *f14;
} S;

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx_0218E610 *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

typedef struct O {
    u32 f00;
} O;

typedef struct P_0219129C { u8 pad[0xA0]; volatile u32 arr[8]; } P_0219129C;

typedef struct CharData {
    u8  pad[0x14];
    u8 *raw;
} CharData;

typedef struct T_0218E610 {
    u32 f00;
    u32 f04;
    Fx_0218E610 *f08;
} T_0218E610;

typedef struct U {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 sub[2];
} U;

typedef struct G {
    u32 f00;
    u32 f04;
} G;

typedef struct Cur {
    u8 f00;
    u8 f01;
    u8 f02;
} Cur;

typedef struct Tri {
    u16 v[3];
} Tri;

unsigned int func_02189B28(unsigned int x);
extern u32 *func_02012ED0(void *p);
extern int func_021C868C(int a, char *b);
extern int func_021AE0CC(int a);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_021A2F20(u32 *p, int a, int b, int c);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void *func_021A3074(u8 *);
extern int func_0217BFD8(const struct Ctx *a, int b);
extern int func_0217CA84(void *sys, int v);
extern u32 func_02026454(void *obj);
extern int func_02012B70(const struct BigObj *p);
extern int func_0217C070(u8 *p);
extern void *func_0217B810(void *a, u8 *pos);
extern int func_0217689C(u8 *ctx, int arg);
extern int func_02012FB0(unsigned char *base);
extern struct Desc *func_0216B3A8(int a0, int a1, int a2);
extern int func_021754B4(u8 *p, int *out);
extern void func_021A2F6C(u32 *p);
extern void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e);
extern int func_0217BDE0(int a, u8 *b, int c);
extern int func_0217AFC4(int *a, u8 *b, int *out);
extern void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f);
extern u16 func_021A3050(u8 *p);
extern void func_021A3038(u8 *, struct VecFx32 *);
extern void func_02164208(int dir, int *p, int amt);
extern u32 func_0216D5B8(void *p);
extern int func_02158D90(u16 v);
extern int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u32 func_02162A54(void *p, void *q, int *pos, u32 d);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u16 func_02188C9C(u8 *p);
extern int func_021CFAC0(u8 *base, int a, int b, int c, int d);
extern void *func_021CFC14(void *a, void *unused, void *c);
extern int func_021CD440(void *a, u16 *out);
extern u32 func_02013FFC(u32 id);
extern u16 func_02162940(void *p, void *q, int key);
extern u32 func_020221A4(void);
extern u32 func_02188CCC(u8 *p);
extern int func_0215FF34(void *sys);
extern int func_021A0ED4(u32 a);
extern struct Desc *func_0215FF54(int a0, int a1, u16 a2);
extern u8 func_0201212C(const struct Ctx *p);
extern int func_021C06CC(void *sys, u8 *pos);
extern u32 func_021A0F90(u8 *p);
extern struct Desc *func_0215FC40(int a0, int a1, u16 a2);
extern int func_021A0EB0(u32 *p, u32 a);
extern int func_0217B410(int a0, int a1, int a2);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CE8(u8 *p);
extern void func_021AA8F8(void);
extern void func_021AA8EC(u8 *p);
extern u32 func_02188D20(u8 *p);
extern int func_021BC5BC(u8 *a);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3550(u32 *p, int a);
extern void func_021A356C(void **p);
extern u32 func_02189A70(u8 *p);
extern void func_021F3B10(void);
extern u32 func_02026474(void *obj);
extern u32 func_0200FB24(void);
extern void *func_021850FC(void *p, u8 *pos);
extern int func_0217391C(u8 *p);
extern int func_02173928(u8 *p);
extern void func_02026400(struct Comm *p);
extern int func_0217B80C(int a, int b);
extern int func_0217B83C(void *sys, void *pos);
extern int func_0217394C(const struct Ctx *p);
extern u16 func_0216D588(void *p);
extern int func_0217AF38(u16 a);
extern int func_0215FCE0(int a, int b, unsigned short c);
extern int func_0219E634(void *, int *);
extern void func_0219E2F4(void *o, void *out);
extern u16 func_02162958(void *c, void *a, int key);
extern u16 func_0216D5F8(void *obj);
extern u16 func_02162A5C(void *set, void *flags, const void *where, u16 type);
extern u32 func_02188CFC(u8 *p);
extern u32 func_02082BCC(void *, int, u32);
extern u16 func_02188C84(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_021A2FE4(u32 *p);
extern u32 func_021A3080(u8 *p);
extern u32 func_021A308C(u8 *p);
extern void *func_0216D888(void *p);
extern void *func_02012B38(const struct BigObj *p);
extern u16 func_02014478(struct Sub02014444Obj *o);
extern u32 func_021A30C8(void **ctx);
extern int func_021A3584(void *v);
extern u32 func_021A1358(u32 *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A70(struct SoundSys *sys);
extern int func_021F2AB8(char *p);
extern void func_021F2AD4(u8 *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *func_02012F2C(int *p);
extern void func_02014474(struct Sub02014444Obj *o, u16 v);
extern void *func_02158B00(void *a, u32 b);
extern u32 func_02188C98(u8 *);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB188(u16 id);
extern u16 func_02162928(void *p, void *q, int key, int mode);
extern u16 func_021A2FA4(u8 *p, u32 a1);
extern u32 func_02013D5C(u32 id);
extern void *func_0217B4D8(void *a, void *b, void *c, int *d, u16 e, int f);
extern struct Rec *func_0216282C(struct Ctx *c, void *a, int *key, int mode);
extern u32 func_021A3098(u8 *p);
extern u16 func_0216D7C4(u8 *p);
extern void *func_02188C80(void *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern void func_02008970(const struct Sub02008828Obj *obj, u32 *out);
extern void func_0200896C(struct Sub02008828Obj *obj, u32 value);
extern u32 func_02010FF4(u32 v);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02188D50(u8 *p);
extern int func_021C3378(void **p);
extern u16 func_02008978(const struct Sub02008828Obj *obj);
extern void func_02008980(struct Sub02008828Obj *obj, u16 value);
extern void func_0201B7EC(void *mon, int a, int b);
extern int func_021D220C(void *msg, u8 *pos);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern void func_02008988(struct Sub02008828Obj *obj, u16 value);
extern void *func_0200D418(void *p);
extern u32 func_0200D564(struct Blk38 *p);
extern int func_021AA944(struct Self *self);
extern void func_021AA80C(struct Ctx *ctx);
extern u8 func_02010F18(void);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_021F532C(void *p);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626EC(u16 *p);
extern int func_021C8A74(u32 a);
extern void *func_021C8A30(u32 prio, void *sys, struct Obj00020 *owner);
extern int func_021C8CF0(u32 a);
extern void *func_021C8C88(u32 prio, void *sys, struct Obj00020 *owner);
extern u16 func_021626A8(void *b, void *pos);
extern u8 func_021626E8(u8 *p);
extern void *func_02185410(void *p, int u, int a, int b);
extern void *func_02185360(void *p, int u, int a, int b);
extern void func_02014110(void *p, u16 a, s16 b, u16 c, u16 d, u32 e, u32 f, u32 g);
extern void func_02012878(struct BigObj *p, const struct Rec1C *src);
extern int func_02162564(char *p, struct Q *q);
int func_021626B8(char *a0, int a1);
extern u16 func_021AB0F8(u32 attr);
extern int func_021BE288(u8 *pos, int k);
extern int func_021F3A88(int a0, int a1, int a2);
extern int func_021F38A4(int a, int b);
extern int func_021AB310(u16 a);
extern int func_02163E58(void *m, Vec_02189BBC *pos, int *h);
extern int func_021F404C(void *a);
extern int func_021F37E0(void *a);
extern int func_02162598(char *p, struct Q *q);
extern int func_02013DD0(int a0);
extern int func_021AA248(struct Ctx *ctx, void *b);
extern int func_021A9F40(struct Ctx *ctx, int mode);
extern int func_021BB188(u16 a);
extern int func_0219E418(u32 a, u32 b);
extern u32 func_021C46F8(u32 a, u32 b, u32 c);
extern void func_02014134(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h);
extern u16 func_021626B0(void *b, void *q);
extern void *func_0216D67C(void *o);
extern void func_0216D9A0(void *o);
extern void func_0216D5E0(int a0, int a1);
extern u32 func_021A2F98(u8 *p);
extern void func_021ACBB8(u32 a, u8 v);
extern void func_021A2F48(u8 *p, u32 a1);
extern void func_021A2F60(int *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, int a);
extern int func_0216D454(void *o);
extern int func_021A2FD0(void *a);
extern u32 *func_0216D9E4(void *c);
extern void func_021A35A0(u32 *p, int a);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj_02189BBC *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB2E8(int a);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void func_02164294(int x, int y, int z, int *out);
extern int func_021AB194(u16 id);
extern void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
extern void *func_02188C7C(u8 *p);
extern u32 func_0216D8AC(void *p);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
u32 func_0219E570(u32 o, u32 k, u32 flag);
extern u32 func_021A3128(u32 *a, u32 b);
extern u32 func_02013E04(u32 id);
extern int func_021A3504(u8 *a, int b, int c);
extern int func_021A3524(u8 *a, int b, int c);
extern int func_0216D83C(void *o);
extern int func_0216D86C(void *o);
extern int func_021641E8(u16 d);
extern int func_021641F8(u16 d);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern void *func_02030734(u16, u32, u32, const void *, u32);
extern u32 func_020307B0(void *);
extern u32 func_02013B38(u32 id);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern void *func_020490F4(u32, u32);
extern u16 func_0204961C(void *obj);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void func_02049238(void *);
void *func_02046DB8(u32 a0, u32 a1);
u32 func_020470A8(void *p);
int func_020470D0(u32 *p);
void func_02046EFC(struct Tagged *p);
u32 func_020113D8(u32 row);
extern int func_02046C94(void);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern int func_0204779C(int *p);
extern int func_02047790(int *p, int i);
extern void func_0204762C(struct Rec *p);
extern int func_02047788(int *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern int func_02047674(int p);
int func_020477D4(struct Owner *owner, u32 index);
u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_021693D4(u8 *base, u8 *src, u32 idx);
extern u32 *func_02169444(u8 *base, u32 idx);
extern void func_0216940C(void *o, u32 i);
extern void func_02169510(int o, Vec_0218C518 *v);
extern void func_0207C9D0(void *, void *, void *);
extern void func_0207AF1C(void *m, int a, int b);
void func_02047A60(void *a0, struct Arg *a1);
int func_02006148(u32 a0);
int func_02006224(u32 a0);
extern void *func_021938AC(u32 heap);
extern int func_021C05D4(int a, int b);
extern u32 func_021938D4(void *a);
extern void func_021C0674(void **p);
extern int func_0216932C(int a0);
extern u32 sub_0207C768(u32 a, u32 b);
extern int func_02169520(int a0, int a1);
extern void func_02169308(u8 *p);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_021A73DC(u32 *s);
extern void func_02169500(u8 *p, u8 *q);
extern int func_02169354(int o, int a);
extern u16 func_02159BF4(void *p);
extern u16 func_02159BF8(void *p);
extern int func_02159BFC(void *p);
extern u32 *func_02159C20(void *p);
extern void func_02159C00(void *p, u8 w, u8 h);
extern u32 func_02012974(const struct BigObj *p);
extern struct Mgr *func_02169148(const struct Cfg *cfg, u32 heap);
extern void func_0216937C(u8 *p, int a, int b);
extern void func_021693B4(char *p, int v);
extern void func_021693C4(char *p, int v);
extern void func_021693CC(char *p);
extern void func_021693BC(char *p);
extern void func_021693A0(int o);
extern void func_0216928C(void *p);
extern void func_021A73C0(int p);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);
extern u16 func_021694FC(u8 *p);
extern void func_021694F8(u8 *p, u16 v);
extern void func_021694D4(int obj);
extern void func_02169470(u8 *obj, u32 member);
extern int func_0207C994(int a, int b);
extern void func_02169800(void *a, char *b, u32 c, u32 d);
extern int func_021AB100(u32 attr);
extern void func_02169848(void *a, u8 *b, u32 c, u32 d);
extern int func_021697E0(char *p);
extern int func_02193B04(u32 a, u32 b, u32 c, u32 d);
extern u32 *func_021A7360(const struct D *p, u32 c, u32 heap);
extern int func_021A7404(u8 *p, int a1);
extern void func_021A7418(void *p);
extern u32 func_021C0688(u8 *p);
extern int func_021C068C(int x, int z, int o, u8 i);
extern int func_021C06B4(u8 i, int o);
extern int func_021C06A8(u8 i, int o);
extern u32 func_02169598(u8 *p);
extern void func_02169538(unsigned char *a, int *out);
extern int func_02048B78(struct Light *l);
extern void func_02048B88(struct Light *l, unsigned int *out);
extern u16 func_0207D184(int a);
extern void func_02046BE0(u32 a, u32 b);
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *, u32, u32, u32, void *);
extern void func_0207CCA4(V *, V *);
extern void func_0207CEE4(int e, V *v, V *a, V *o);
extern void func_02048B44(int, void *);
extern void func_02048AFC(int, void *);
extern int func_0207CBD0(void *a);
extern int func_0207CFB8(int a, int b);
extern void func_0207CA00(void *, void *, void *);
extern int func_0207CA68(V *a, V *b);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048B20(u32 a, u32 b);
extern void func_02048B0C(u32 h, void *out);
extern void func_02048B30(int, void *);
extern void func_02048AE8(int, void *);
extern void func_02082D44(void *, void *, int);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern void VEC_Subtract(V *a, V *b, V *o);
extern int VEC_Mag(V *a);
extern int FX_Modf(int x, int *ip);
extern void VEC_Normalize(V *a, V *o);
extern void VEC_CrossProduct(V *a, V *b, V *o);
extern int VEC_DotProduct(V *a, V *b);
extern u16 FX_AcosIdx(int x);
extern void *func_02188C58(void *p);
extern u32 func_02188C5C(u8 *p);
extern void func_021BB260(u32 a, u32 b);
extern u32 func_02189A18(u8 *p);
extern void func_021AB75C(u8 *p, u32 v);
extern u32 func_021C7058(u32 a, u32 b, u32 c);
extern u32 func_021C701C(u32 a, u32 b, u32 c);
extern u32 func_021C6F00(u32 a, u16 b, u32 c);
extern u32 func_021C7C10(u32 a, u16 b, void *c, void *d);
extern u32 func_021C7AE4(u32 a, u32 b, void *c);
extern u32 func_02188D38(u8 *p);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_021931F4(u32 a);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_02192BD0(char *p, int flag);
extern void func_02192CF0(char *p, int flag);
extern void *func_020056A0(void (*fn)(void *, void *), void *arg, u32 pri);
extern void func_02192EB8(void *a, void *b);
extern void func_02192FA4(int a, int b);
extern void func_02192FEC(int a, int b, int c);
extern void func_02194798(unsigned char *a);
extern void func_02031140(struct S02031140 *p);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 i);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02192E0C(u32 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void func_020310C4(struct Tcbl *p);
extern void func_0219470C(unsigned char *a);
extern void func_02194760(u32 a);
extern void func_02194764(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02193208(u8 *p, u8 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020409B4(u32);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02192F74(struct W *w);
extern int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
extern void func_02193144(u32 heap);
extern void func_02193044(u32 v);
extern void func_02193170(u32 heap);
extern int func_02193130(struct Descriptor *a);
extern u32 func_02192B20(u8 a, u8 b, u8 c, u8 d, u32 e);
extern void func_02192BC0(u8 *p);
extern struct Obj_02190344 *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj_02190344 *p, int heap);
extern void func_02020D10(u8 *p, u32 v);
extern u32 func_0201F868(void *p);
extern void func_0202020C(struct Obj_02190344 *o, u16 *a, u16 *b);
extern s32 func_020200CC(struct Obj_02190344 *o);
extern void func_02020234(u8 *p);
extern u32 func_0201F81C(int n, u16 d);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 func_0201F898(u32, u32, u32, u32);
extern void func_0201F8F4(struct Slot *s);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201F91C(struct Slot *s);
extern u32 func_0201F73C(u32, u32, u32, u32);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern int func_02193200(u32 a);
extern void func_020061E4(u32 se);
extern int func_02006238(void);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201CE30(void *p);
extern u32 func_0201CE34(void *p);
extern void func_0201CE38(void *p);
extern int func_02193228(u8 *p);
extern int func_02193260(u8 *p, u32 q);
extern u8 func_0219320C(u8 *p);
extern void func_021932A0(u32 a, int f);
extern u32 func_02193210(u8 *p);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
extern void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
extern void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x);
extern void func_02194940(u8 *p, int i);
extern u32 func_02194950(u32, u32);
extern u32 func_02194960(u32, u32, u32, u32);
extern void func_0219492C(u8 *p, int i);
extern u32 func_02194990(u32, u32);
extern void func_0219499C(u8 *p, int i, u32 b, u32 c);
extern int func_02194974(u8 *p, int i);
extern u32 func_02194984(u32, u32);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_02194A00(u32, u8, u8, u8, u8, u32);
extern u32 func_02194A48(u32 a, struct Descriptor *b);
extern int func_02194A34(u32 a, u32 b);
extern void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern int func_0219319C(u8 *p, u32 v);
extern u16 func_020458F8(struct U16Vec *vec);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern struct E *func_021931C4(u8 *p, u32 v);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct Bmp *func_02043678(u32, u32, u32, u32);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041300(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B90(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u16 key);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082EA4(void *dst, void *src, u32 n);
extern u32 func_0201DC80(struct Font *p);
extern void func_021928F8(u8 *a, u32 b, u32 c);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void ENV_SetResourceSet(void *p);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
int func_02189BBC(int x);
int func_02189BD0(void *sys, struct Obj00020 *pos, int *outA, int *outB);
int func_0218A074(void *a, int b);
int func_0218A0E4(void *sys, struct Obj00020 *pos);
int func_0218A240(void *p, struct Obj00020 *pos);
int func_0218A278(void *sys, struct Obj00020 *pos);
int func_0218A4BC(u32 a, u32 b, u32 c, u32 d);
void func_0218A4E0(struct FieldInput_0218A4E0 *p, void *sys, struct Obj00020 *pos);
void func_0218A6E8(void *sys, void *q);
int func_0218A728(void *a);
int func_0218A738(struct Ctx738 *c);
int func_0218A76C(void *p);
int func_0218A784(struct Ctx784 *c, int a);
int func_0218A7F0(struct FieldCtx_02189BBC *p);
int func_0218A824(struct FieldCtx_02189BBC *p);
void *func_0218A878(u8 *p, void *a, void *b);
int func_0218A8BC(struct FieldCtx_02189BBC *p);
int func_0218A9B0(struct Ctx9B0 *p, u8 *pos);
int func_0218AA2C(void *party);
void func_0218AA74(void *party);
void func_0218AAD0(void *sys, void *party);
int func_0218AB0C(void *party);
int func_0218AB50(void *p, u8 *pos, void *msg, void *sys);
void func_0218AB9C(void *sys, u8 *pos);
int func_0218AC08(void *msg, u8 *pos, u16 id);
int func_0218AC4C(u8 *pos, void *msg, void *sys);
int func_0218AC84(u8 *pos, void *msg, void *sys);
struct Desc *func_0218ACA8(void *a);
int func_0218ACD0(u8 *p, void *a, void *arg);
void *func_0218AD28(struct FieldCtx_0218AD28 *p, struct Obj00020 *pos);
int func_0218AD80(u8 *p, void *a, int id, void *arg);
void func_0218ADC8(u8 *p, int id, u32 *pos);
u32 func_0218AE04(u8 *p, void *arg);
void func_0218AE48(struct Obj_02189BBC *p, struct Vec_02189BBC *out);
int func_0218AEAC(u8 *p);
int func_0218AECC(char *a0, int a1);
int func_0218AED4(char *p, int unused, void *a);
int func_0218AF90(struct FieldInput *p, void *a, u8 *pos);
int func_0218B0CC(char *p, void *unused, void *x);
int func_0218B13C(char *p, void *unused, void *x, int *alt);
int func_0218B208(struct FieldCtx *p, void *unused, u8 *pos);
int func_0218B24C(char *p, void *q, void *x);
void func_0218B2A8(char *p, int s, u16 *v);
int func_0218B2E8(char *p, void *x, int a, int *b);
int func_0218B310(void *a, unsigned char *s);
int func_0218B32C(void *unused, int *st, char *ctx);
int func_0218B3DC(int unused, int a, int b, int c, int d);
int func_0218B408(char *p, void *a, void *x);
int func_0218B4B0(struct FieldCtx *p, u8 *pos);
int func_0218B53C(unsigned char *p, void *b);
u16 func_0218B56C(struct FieldCtx_0218B56C *p, u8 *pos);
int func_0218B630(void *sys, u32 move);
int func_0218B6AC(void *ctx);
int func_0218B6F8(char *p, void *q);
char *func_0218B754(u16 a, void *b, u16 c);
void func_0218B7F8(char *p);
void func_0218B83C(char *p);
void func_0218B88C(unsigned char *p);
void func_0218B8AC(char *p, int a, int b, int c);
int func_0218B910(FieldMsgbgWork *p, u32 b);
int func_0218B924(u8 *p, u32 a1);
int func_0218B930(void *p, int a, Vec_0218B924 *pos, int *k);
int func_0218B974(void *p, int a, const Src_02189BBC *s, int n);
void func_0218B9FC(int a, int obj);
void func_0218BA04(void *p, int a, const Src_02189BBC *s, int d);
void func_0218BA48(FieldMsgbgWork *p, void *v);
void func_0218BA70(FieldMsgbgWork *p, void *v);
void *func_0218BA98(FieldMsgbgWork *p, int h);
unsigned short func_0218BACC(FieldMsgbgWork *p, void *v);
u8 *func_0218BB04(u8 *p);
void func_0218BB0C(u8 *s, u16 a, u32 n);
int func_0218BB64(char *a);
void func_0218BB78(u8 *s, int k);
int func_0218BBD0(FieldMsgbgWork *p, unsigned int i);
int func_0218BBF4(u32 a, u32 b);
char *func_0218BC00(char *p, int i);
u8 *func_0218BC10(u8 *a, int b);
unsigned short func_0218BC1C(int x);
void func_0218BC40(unsigned char *p, int a, int b, int c);
void func_0218BC6C(unsigned char *p);
int func_0218BC8C(int *p);
u8 *func_0218BCAC(u8 *p);
unsigned char func_0218BCB0(unsigned short *p);
void func_0218BCE4(S_0218BCF4 *p, u8 v);
void func_0218BCF4(S_0218BCF4 *p);
u32 func_0218BD20(u8 *p);
u8 func_0218BD24(u8 *p);
void func_0218BD28(FieldMsgbgWork *p, int arg);
void func_0218BD94(u8 *s);
void func_0218BDD8(u8 *s, u32 *out);
void func_0218BE84(u8 *s, u8 *e);
void func_0218BEE8(u8 *s, void **out, int x, int unused);
void func_0218BF84(S_0218BDD8 *p);
void func_0218BFB4(FieldMsgbgWork *a, u32 *out, u32 *st);
void func_0218C02C(void *a, u32 *out);
void func_0218C040(void *a, void **b);
void func_0218C08C(u8 *a, void **b);
void func_0218C0D8(void **s);
void func_0218C124(void *p, Obj_0218BDD8 *s);
void func_0218C150(void);
void func_0218C154(u8 *a, u32 *st);
void func_0218C1A4(int unused, int *s);
void func_0218C1C4(u32 unused, u32 *st);
void func_0218C23C(u32 *st, int n);
void func_0218C290(u32 *st, int n);
void func_0218C2E4(u32 *st, int n);
void func_0218C350(u32 *st, int n);
void func_0218C388(S_0218C154 *p);
void func_0218C3B0(Obj_0218BDD8 *p, int i, int c);
void func_0218C3E0(u32 *st, int n, int mode);
void func_0218C438(void);
int func_0218C43C(u32 *st, int i);
int func_0218C47C(int *p, int id);
void func_0218C490(void *unused, EntSlot *s);
u32 *func_0218C4A0(u8 *base, u32 a, void *b, int c);
void func_0218C4EC(unsigned char *p, void *key);
void func_0218C518(u8 *base, EntSlot *e);
u8 func_0218C530(int a);
void func_0218C54C(S_0218C54C *p, int save);
void func_0218C574(FieldMsgbgWork *a, S_0218C574 *s, int b);
Ent_0218C518 **func_0218C584(u8 *s, Rect *r, int kind, int *count);
int func_0218C638(int a, int b, int c);
int func_0218C654(int a, int b, int c);
int func_0218C674(unsigned char *p, int b);
void func_0218C69C(unsigned char *p, int b, int i, int c);
void func_0218C6D0(int *p, int b);
int func_0218C6F4(unsigned char *p, int b, int id);
u8 *func_0218C724(FieldMsgbgWork *owner, u32 *obj);
int func_0218C7D8(void *p, int b, int c);
u8 *func_0218C7F0(FieldMsgbgWork *owner, u32 x, Blk *src);
void func_0218C860(S_0218C518 *p);
void func_0218C88C(unsigned char *p, int v, int c);
void func_0218C89C(unsigned char *p, int v);
int func_0218C8B0(void *p, int v);
int func_0218C8D8(void *p);
int func_0218C8FC(unsigned char *p, int i);
int func_0218C910(unsigned char *p);
unsigned short func_0218C924(unsigned char *p);
void func_0218C934(unsigned char *p);
int func_0218C944(void *p, u32 idx, u16 *out);
int func_0218C990(unsigned char *p, int v);
int func_0218C9A4(void *p);
void func_0218C9C4(Rect *out, int *__restrict pos);
char *func_0218C9E8(u16 heap, u16 b);
int func_0218CA4C(void *a);
void func_0218CA78(char *p);
int func_0218CB34(char *p);
void func_0218CC34(S_0218CA78 *p);
void func_0218CC64(char *p, int a, int m);
int func_0218CD20(u32 a, Map *m, void *blk);
void *func_0218CEE0(void *p);
void func_0218CEE4(Obj *p, const Src_0218C518 *src, void *c);
void func_0218D05C(char *p);
int func_0218D0D8(void *a, void *b);
void func_0218D104(u8 *a, u8 *b, void *c);
void func_0218D13C(u8 *a);
void func_0218D158(T_02189BBC *dst, const V3_0218C518 *src);
int func_0218D168(char *p);
void func_0218D1D0(char *p, void *a, Cell_0218C518 *e);
void func_0218D304(char *p, int *v, Cell_0218C518 *e);
void func_0218D444(char *p, int *a, Cell_0218C518 *e);
void func_0218D570(Obj_0218D570 *p, Cam *cam, Cell_0218C518 *cells);
int func_0218D7A8(Obj_0218D7A8 *p, Cell_0218C518 *nc);
int func_0218D934(u32 a, int b, int c);
int func_0218D970(u32 a, int b, int c);
int func_0218D980(u32 a, int b, int c);
int func_0218D9B8(u32 a);
void func_0218D9C8(u8 *p);
int func_0218D9E8(char *p, int *pos, List *dst);
int func_0218DAEC(char *p, char *q, E_0218D570 *out);
int func_0218DBAC(u8 *a, int idx, u32 c, u8 *d);
int func_0218DBD4(char *p, int i);
int func_0218DC04(Grid *g, VecFx32 *pos);
void func_0218DC4C(char *o, V3_0218D570 *v);
void func_0218DC5C(u8 *a, Vec3 *b);
u32 func_0218DC6C(u8 *p);
void *func_0218DC70(u8 *p);
int func_0218DC74(u32 a, u32 b, u32 c);
int func_0218DC84(int a, int b, const int *q, int c);
int func_0218DCF4(u32 *a0);
int func_0218DCFC(u32 *a0);
int func_0218DD04(u8 *p);
int func_0218DD08(u8 *p);
int func_0218DD0C(u8 *p);
u16 func_0218DD10(u8 *p);
void func_0218DD14(int *dst, char *src, int a, int b);
void func_0218DD38(void **a);
void func_0218DD4C(void **a);
int func_0218DD5C(u32 *p);
u32 func_0218DD6C(u32 *p);
int func_0218DD70(u32 a);
void func_0218DD80(u8 *p, u32 v);
int func_0218DD84(u32 a);
u32 func_0218DD98(u8 *p);
Cell_0218C518 *func_0218DD9C(Cell_0218C518 *a, int x, int y, int z);
void func_0218DDA4(Cell_0218C518 *a, Vec_0218D570 *b);
void func_0218DDB4(const char *p, int *q, char *r);
void func_0218DE78(char *p);
void func_0218DEF0(char *p);
void func_0218DEFC(char *p, int o, int v);
void func_0218DF80(u8 *a);
int func_0218DFE0(u8 *a, u32 idx, int flag, u32 *out);
char *func_0218E018(int a0, int a1, struct Light *a2, int a3, u16 heap);
void func_0218E0E4(u8 *a);
void func_0218E104(u8 *a, u32 b);
void func_0218E124(u8 *a, u32 s);
u32 func_0218E138(u8 *p);
void func_0218E13C(u8 *a, u32 s);
int func_0218E160(u32 a);
void func_0218E17C(u32 *p, u32 v);
int func_0218E188(unsigned char *o);
void func_0218E18C(char *p, Vec *src);
void func_0218E260(void *a, void *b);
void func_0218E284(u8 *a);
int func_0218E298(u8 *a);
void func_0218E2B4(V *a, V *out, int i, int j, int e);
void func_0218E358(u8 *a);
void func_0218E404(u8 *a);
void func_0218E4B0(u8 *a);
void func_0218E540(u8 *a);
void func_0218E58C(u8 *a, u32 b);
void func_0218E5A0(u8 *a, u32 b);
void func_0218E5B8(u8 *a, u32 b);
void func_0218E5D0(u8 *a, u32 b);
void func_0218E5EC(u8 *p);
void func_0218E5F4(u8 *p);
void func_0218E5FC(u8 *p);
void func_0218E610(void *a, u16 *b, u16 *c, int *d);
void func_0218E674(u8 *a, u32 b);
void func_0218E6A4(u8 *a);
void func_0218E6F0(u8 *a);
void func_0218E73C(u8 *a);
void func_0218E764(u8 *a, void *b, void *c);
void func_0218E7DC(V *v, u16 h0, u16 h1, u16 *p0, u16 *p1);
u32 func_0218EC2C(u8 *p);
void func_0218EC30(u8 *a, const Vec3_0218EC30 *p);
void func_0218EC54(u8 *p);
u32 func_0218EC5C(u8 *p);
int func_0218EC60(u32 a);
void func_0218EC68(u8 *a, u32 first, ...);
void func_0218EC7C(u8 *a, u32 first, ...);
void func_0218EC90(u8 *a, const Vec3_0218EC90 *p);
void func_0218ECB4(u8 *a, Vec3_0218ECB4 *out);
void func_0218ECC4(u8 *a, Vec3_0218ECC4 *out);
void func_0218ECD4(u8 *a, const Vec3_0218ECD4 *p);
void func_0218ECE4(u8 *a, Vec3_0218ECE4 *out);
void func_0218ECF4(u8 *a, const Vec3_0218ECF4 *p);
void func_0218ED04(u8 *p, const Vec_0218ED04 *v);
void func_0218ED14(u8 *p, u32 q);
void func_0218ED20(void *p, void *out);
u16 func_0218ED2C(u8 *p);
void func_0218ED34(u8 *p, u16 v);
u8 *func_0218ED3C(u8 *p);
u16 func_0218ED40(u8 *p);
void func_0218ED48(u8 *p, u32 v);
u8 *func_0218ED50(u8 *p);
u32 func_0218ED54(u8 *p);
void func_0218ED58(u8 *p, u32 v);
void func_0218ED5C(void *a, u16 *b, u16 *c, int *d);
void func_0218ED64(u8 *a, u16 angle);
void func_0218ED9C(Delay *d, Vec_0218ED9C *inA, Vec_0218ED9C *inB, Vec_0218ED9C *outA, Vec_0218ED9C *outB);
void func_0218EEFC(int n, u32 x, u32 flags, u32 heap, void *a);
void func_0218EFD4(u8 *a);
void func_0218F004(u8 *a);
int func_0218F050(u32 a);
void func_0218F05C(unsigned char *a);
void func_0218F0A8(u8 *a);
void func_0218F0D4(u8 *a, int b);
u32 func_0218F0E8(u8 *a);
int func_0218F0F8(u8 *a);
void func_0218F114(char *arg0, char *arg1);
void func_0218F134(u8 *a);
void func_0218F14C(u8 *p, u32 a, u32 b);
void func_0218F18C(u8 *a, Vec3 *out);
void func_0218F19C(u8 *a, Vec3 *out);
void func_0218F1AC(u8 *p, u32 v);
u8 func_0218F1B4(u8 *p);
void func_0218F1BC(u32 *a, u32 b);
void func_0218F1DC(u32 *a, u32 b);
int func_0218F1FC(const Box *a, V *b, V *out);
int func_0218F310(const Ring *a, V *b, V *out);
int func_0218F460(Box *a, V *b, V *out);
void func_0218F780(u8 *s, u8 *d);
void func_0218F7D0(u8 *s, u8 *d);
void func_0218F818(u8 *a);
void func_0218F848(u8 *a);
void func_0218F878(u8 *a);
void func_0218F89C(u8 *p, u8 *src, u16 v);
void func_0218F900(u8 *a, u8 *p, u16 n);
void func_0218F918(u8 *a, u8 *p, u16 n);
void func_0218F930(u8 *p, u8 *a, u8 *b, u32 *c, u16 v);
void func_0218F9C4(u8 *p, u8 *src, u16 v);
void func_0218FA40(u8 *p, u16 v);
void func_0218FB1C(u8 *p);
void func_0218FC80(u8 *p);
void func_0218FD88(Vec3_0218FD88 *p, Vec3_0218FD88 *q, u16 n, u16 d, Vec3_0218FD88 *out);
int func_0218FDD4(int *p, int *q, int n, int d);
u16 func_0218FDF0(u16 *a, u16 *b, s32 d, s32 n);
void func_0218FE40(u8 *a);
int func_0218FE50(u8 *a);
u8 *func_0218FE70(u8 *p);
void func_0218FE78(u32 a, u8 *b);
void *func_0218FE80(void *a);
void func_0218FE98(void *a0);
void func_0218FEA0(u8 *p, u32 v);
int func_0218FEA4(u32 a, u32 b, u32 c, u32 d);
void func_0218FEC0(u8 *o);
void func_0218FF00(u8 *a);
void func_0218FF20(u8 *a);
void *func_0218FF30(u16 heap);
void func_0218FF48(void *a0);
void func_0218FF50(u32 *o, void *a);
u32 func_0218FF78(u32 *p);
void func_0218FFE8(u8 *a, u32 a1, u32 a2, u32 a3);
void func_02190000(u32 *p);
void func_02190058(u8 *o);
void func_021900A8(void *a);
void func_021900C4(u32 a, u8 *b);
void func_02190110(u8 *a);
void func_0219014C(u32 *a);
u32 func_021901E4(u8 *p);
u32 func_021901E8(u8 *p);
u8 *func_021901EC(u16 heap, u32 b);
void func_02190270(u32 a);
void func_0219027C(u8 *a);
void func_021902A4(u32 a0, u32 a1);
void func_021902AC(u16 *p, int v);
void func_021902BC(Obj_0218E610 *o);
void func_02190344(u8 *a);
int func_02190378(u8 *a);
void func_02190398(u32 *p);
int func_021903CC(u8 *p);
void func_021903E0(Link_02190344 *o);
void func_0219047C(u8 *p);
void func_02190490(u8 *p);
int func_0219049C(u8 *p);
u32 func_021904A8(u32 *p);
u32 func_021904AC(u8 *p);
int func_021904B0(u32 a, u32 b);
u32 func_021904C8(struct Rec *a0);
void func_021904D0(u8 *p);
void func_021904DC(u8 *p, u8 v);
Slot_021904EC *func_021904EC(u32 *p, u32 a, u32 b);
void func_02190538(struct Slot *s);
void func_02190550(struct Slot *s, int x, int y, u32 z);
void func_02190590(struct Slot *s, int x, int y, u32 z);
void func_021905C8(Slot *s, int x, int y, u32 z, u16 w, u32 v);
void func_02190604(struct Slot *s, int x, int y, u32 z, u16 w);
u32 func_0219061C(u32 *p);
int func_02190620(u32 a);
void func_0219063C(Slot *s, int x, int y, int w, int h);
u32 func_02190678(u8 *p);
u8 *func_0219067C(u8 *p);
Obj_02190680 *func_02190680(Fx_0218E610 *a, u32 b, u16 c, u16 d, u16 e, u16 f, u16 g);
void *func_02190708(Fx_0218E610 *p, u32 a, u16 b, u16 c, u16 d, u16 e);
int func_02190728(void *a);
int func_02190740(u32 a, u32 b, u32 c, u32 d);
void func_02190758(Slot **p, int x, int y, u32 z);
void func_02190764(Slot **p, int x, int y, u32 z, u16 w, u32 v);
int func_0219077C(u8 *p);
void func_02190788(u8 *p);
void func_02190794(Slot **p, int x, int y, int w, int h);
void func_021907A8(Fx_0218E610 *p, u32 a);
u32 func_021907C0(u8 *p);
Obj_02190344 *func_021907C4(Fx_0218E610 *a, u32 b, u32 c, u32 d, u16 e, u16 f);
int func_0219082C(void *a);
void func_02190844(Slot **p, int x, int y, u32 z);
void func_02190854(u32 *p);
Handle_02190344 *func_02190860(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i);
Handle_02190344 *func_02190938(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i);
Handle_02190344 *func_02190960(u16 *a, const u8 *b, u32 c, u16 d, u16 e);
u32 func_0219097C(u32 a, const void *b, u32 c);
Handle_02190344 *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
int func_021909BC(void *a);
int func_021909E4(Handle_02190344 *h);
void func_02190A14(u8 *p);
u32 func_02190A20(int n, u16 d);
u32 func_02190A28(const Pair *arr, int n, u32 c, u16 d);
int func_02190A64(u32 a, u32 b, u32 c, u32 d);
void func_02190A6C(u32 a);
u32 func_02190A74(u32 *obj, u32 *tab, u32 *out, u32 key);
unsigned func_02190AC4(void *p);
u32 func_02190ACC(u32 *obj, u32 *tab, u32 unused, u32 key);
unsigned func_02190AEC(unsigned a, unsigned b, unsigned c, int d);
int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f);
int func_02190B1C(u32 a);
void func_02190B2C(struct Dst *d, const struct Src *s);
u32 *func_02190BE4(u16 *a, u32 b);
int func_02190C78(Handle_02190A28 *h);
u32 *func_02190C94(u32 *a, u32 b, u32 c, u32 d, u16 e0, u32 f, u16 g);
int func_02190D08(int x);
u32 *func_02190D2C(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f);
int func_02190D48(void *a);
int func_02190D5C(u32 *p);
Obj2 *func_02190DCC(Fx_0218E610 *a, u32 b, u32 c, u16 d, u16 e, u16 f);
int func_02190E40(u32 a);
void func_02190E74(u32 *p, u32 b, u16 c, u32 d);
void func_02190EB8(P_0218E610 *p, u32 b, u16 c, u32 d);
u32 func_02190EF0(u32 *p);
struct Obj2 *func_02190F64(Fx_0218E610 *a, u32 b);
void func_02190F7C(P_0218E610 *p);
void *func_02190F9C(void **p);
Obj2 *func_02190FA0(Fx_0218E610 *a, u32 b, u32 c);
int func_02191008(u32 a);
void func_0219103C(u32 *p, u32 b, u16 c, u32 d);
void func_02191084(P_0218E610 *p, u32 b, u16 c, u32 d);
u32 func_021910C0(u32 *p);
void func_02191134(P_0218E610 *p);
void func_02191164(P_0218E610 *p);
void func_02191184(Q *q, u32 b, int c, u32 d);
u32 func_021911B4(u8 *p);
void func_021911B8(A *a, B_0218E610 *b, int mode, V3_02190344 *v, u32 d, u32 e, u32 f);
Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
int func_021912D8(u32 a);
int func_021912F8(u32 a, u32 b, u32 c, u32 d);
int func_0219131C(u32 a);
u32 func_02191348(u32 *a, u32 b);
u32 func_02191388(u32 *a);
void func_021914CC(S *s);
void func_02191504(u16 *a, u32 *b, u32 c, u32 d, u16 e, u16 f, u32 g);
R *func_02191558(Fx_0218E610 *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
int func_021915B4(void *a);
void func_021915EC(R *r);
void func_0219160C(int *p);
void func_0219161C(R *r, int b, int c, u32 d);
void func_02191648(R *r, int b, int c, u32 d);
void func_02191674(R *r, int b, int c, u32 d, u16 e);
void func_021916A8(R *r, u32 b, u16 c, u32 d);
u32 func_021916E0(u32 *a);
void func_02191794(R *r);
int func_021917C0(int *p);
void func_021917C4(u16 *a, u32 *b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u32 i);
void func_02191830(Q *q, u32 a, u8 *w, u8 *h);
void func_02191870(Fx_0218E610 *a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h);
void func_021918DC(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g);
int func_0219194C(void *a);
void func_0219196C(u32 a, u32 b);
void func_02191978(P_0219129C *p);
int func_021919AC(u8 *p);
int func_021919C8(struct Q *q);
void func_02191A04(u8 *p, int a);
u32 *func_02191A10(u16 *a, u32 b, u32 c);
void func_02191B14(u32 *a);
u32 func_02191BE8(u32 *p, u32 b);
void func_02191D88(u32 a, u32 b, u32 c, u32 d);
void func_02191DC8(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal);
void func_02191FA0(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal);
int func_02192138(u32 a, u32 b, u32 c);
int func_0219214C(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col);
int func_021921C8(struct Bmp *a, struct Bmp *b, struct Bmp *c, int n, u16 col);
void func_02192244(u32 unused, u32 a, u32 b);
void func_02192264(u32 a, u32 unused, u32 heap, u32 idx);
void func_021922A4(u32 bmp, u32 b, u32 heap);
void func_021924F0(u16 a, u16 b, u32 c, u32 d, u32 e, u16 f);
u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f);
void func_02192628(u32 *a);
void func_0219269C(T_0218E610 *t, u16 b, u16 c, u32 d);
int func_021926D8(U *u);
u32 func_0219270C(Q *q, int a, int n);
u32 func_0219272C(u16 *a, u32 b, u32 c);
G *func_02192788(Fx_0218E610 *a);
void func_021927B0(u8 *p);
void func_021927C0(struct G *g, struct Fx_0218E610 *a);
void func_021927E8(u32 *p);
u8 func_021927F8(u8 *p);
void func_021927FC(struct Cur *c, u32 win, u32 col);
extern struct _anon_Ent d_021D373C[];
extern u8 abs_id_83[];
extern const struct TileMsg data_021D3CE8[13];
extern const char d_021DD9CC[];
extern const Tbl d_021D3DC4;
extern unsigned char d_021D3D50[];
extern Entry_02189BBC d_021D3D58[];
extern struct Ops d_021D3D5C[];
extern s16 d_020A1B38[];
extern u8 d_021D3D88[];
extern u8 d_021D3D8A[];
extern const char d_021DD9EC[];
extern char d_021D3DDC[];
extern u16 d_021DD9E0[];
extern u16 g_021DD9E0[];
extern S6 d_021D3DD4;
extern const char d_021DDA28[];
extern StateFunc_02189BBC d_021DDA0C[];
extern StateFunc_02189BBC d_021DDA00[];
extern s16 tbl_020A1B38[];
extern StateFunc_0218E58C d_021D3E44[];
extern V d_021D3E2C;
extern s16 FX_SinCosTable_[];
extern Handler d_021DDA18[];
extern V d_021D3E38;
extern const char d_021DDA38[];
extern const char d_021DDA50[];
extern Blk32 d_021D3F38;
extern Blk16 d_021D3E68;
extern const Tri d_021D3E50;














int func_02189BBC(int x)
{
    return d_021D373C[(int)func_02189B28((unsigned int)x)].f8;
}














/*
 * Root of the field input tree: builds the FieldInput_02189BBC record on the stack
 * and runs the talk / step / menu / surf / script checks in order,
 * returning the first non-zero result.  The u16 local at sp+0x28 is the
 * out slot of func_021CD440; its address doubles as the base for the
 * in.f0 / in.f10 loads, which is why `add r1, sp, #0x28` sits above the
 * beq after the func_021CFAC0 test.
 */
/*
 * Root of the field input tree: builds the FieldInput record on the stack
 * and runs the talk / step / menu / surf / script checks in order,
 * returning the first non-zero result.  The u16 local at sp+0x28 is the
 * out slot of func_021CD440; its address doubles as the base for the
 * in.f0 / in.f10 loads, which is why `add r1, sp, #0x28` sits above the
 * beq after the func_021CFAC0 test.
 */
int func_02189BD0(void *sys, struct Obj00020 *pos, int *outA, int *outB)
{
    struct FieldInput_02189BBC in;
    int xyz[3];
    u32 out;
    u16 id;
    int r;
    u32 flags;
    void *ev;
    void *obj;
    void *model;

    *outA = 0;
    *outB = 0;
    func_0218A4E0((struct FieldInput_0218A4E0 *)(&in), sys, pos);
    r = func_0218A738((struct Ctx738 *)(&in));
    if (r != 0) {
        *outA = 1;
        return r;
    }
    r = func_021C868C((int)sys, (char *)(*func_02012ED0(in.f8)));
    if (r != 0)
        return r;
    r = func_021AE0CC((int)pos);
    if (r != 0) {
        *outA = 1;
        return r;
    }
    if (in.b2)
        func_0218A728(in.f8);
    if (in.b2) {
        r = func_0218A76C(&in);
        if (r != 0) {
            *outA = 1;
            return r;
        }
        r = func_0218ACD0((u8 *)(&in), pos, (void *)in.f34);
        if (r != 0)
            return r;
        r = (int)func_0218AD28((struct FieldCtx_0218AD28 *)((struct FieldCtx_02189BBC *)(&in)), (struct Obj00020 *)pos);
        if (r != 0)
            return r;
    }
    r = func_0218A9B0((struct Ctx9B0 *)(&in), (u8 *)pos);
    if (r != 0)
        return r;
    if (in.b3) {
        r = func_0218A7F0((struct FieldCtx_02189BBC *)(&in));
        if (r != 0)
            return r;
    }
    r = func_0218A824((struct FieldCtx_02189BBC *)(&in));
    if (r != 0)
        return r;
    r = (int)func_0218A878((u8 *)(&in), sys, pos);
    if (r != 0)
        return r;
    r = func_0218B208((struct FieldCtx *)((struct FieldCtx_02189BBC *)(&in)), sys, (u8 *)pos);
    if (r != 0)
        return r;

    flags = 0;
    if ((int)func_020142E8((void *)func_0201296C(in.f8), (u32)0x964) == 1)
        flags |= 1;
    r = func_021A2F20((u32 *)in.f18, in.trg, in.cont, flags);
    if (r != 0)
        return r;

    obj = (void *)func_02012138(sys);
    ev = (void *)func_02158344((int)obj);
    model = func_021A3074((u8 *)in.f18);
    if (func_0217BFD8((const struct Ctx *)sys, in.f10) == 1)
        return func_0217CA84(sys, 0);
    if ((int)func_02026454(obj) == 2 && ev != 0) {
        if (func_02012B70(in.f8) == 1 && func_0217C070(ev) == 1)
            return (int)func_0217B810(sys, (u8 *)pos);
        if (func_0217689C(ev, in.f10) == 1)
            return (int)func_0216B3A8((int)sys, 9, (u32)func_02012FB0(in.f8));
        if (in.b10 == 1 && func_021754B4(ev, (int *)(&out)) == 1) {
            func_021A2F6C((u32 *)in.f18);
            return (int)func_0217FC6C(sys, (int)pos, (int)ev, (int)model, out, in.f0);
        }
        if (in.b3) {
            r = func_0217BDE0((int)sys, ev, in.f18);
            if (r != 0)
                return r;
        }
        if (in.b0 && func_0217AFC4(ev, (u8 *)in.f18, (int *)(&out)) == 1) {
            func_021A2F6C((u32 *)in.f18);
            return (int)func_0217FB5C(sys, (int)pos, (int)ev, (int)model, out, in.f0);
        }
    }

    if (in.b0) {
        u32 dir = func_021A3050((u8 *)in.f18);
        int target;
        u32 msg;
        int x;
        int y;
        int z;
        void *map;

        func_021A3038((u8 *)in.f18, (struct VecFx32 *)xyz);
        func_02164208((u32)dir, xyz, 0x10000);
        target = func_0218B4B0((struct FieldCtx *)((struct FieldCtx_02189BBC *)(&in)), (u8 *)pos);
        if (target != 0) {
            u32 kind = func_0216D5B8((void *)target);

            if (func_02158D90(kind) == 1) {
                void *m = func_021A3074((u8 *)in.f18);

                func_021A2F6C((u32 *)in.f18);
                *outA = 1;
                return func_0219F01C((u32)sys, (u32)pos, kind, (u32)m, target, in.f0);
            }
        }
        msg = func_02162A54(in.fC, (void *)func_0201296C(in.f8), xyz, dir);
        if (msg != 0xFFFF)
            return (int)func_02158768((int)sys, msg, 0, in.f0);
        msg = func_0218B56C((struct FieldCtx_0218B56C *)((struct FieldCtx_02189BBC *)(&in)), (u8 *)pos);
        if (msg != 0xFFFF)
            return (int)func_02158768((int)sys, msg, 0, in.f0);
        x = xyz[0] >> 12;
        y = xyz[1] >> 12;
        z = xyz[2] >> 12;
        map = func_0200BE48(func_02012EBC(in.f8));
        msg = (u32)func_021CFAC0(map, (u16)func_02188C9C((u8 *)pos), (s16)(x / 16), (s16)(y / 16), (s16)(z / 16));
        if (msg != 0xFF)
            return (int)func_021CFC14(sys, (void *)in.f0, (void *)msg);
        if (func_021CD440(pos, &id) == 1)
            return (int)func_02158768((int)sys, 0x271B, 0, in.f0);
        if (func_02013FFC(in.f10)) {
            msg = func_02162940(in.fC, (void *)func_0201296C(in.f8), (int)xyz);
            if (msg != 0xFFFF)
                return (int)func_02158768((int)sys, msg, 0, in.f0);
        }
    }

    if (in.f1C == 3 || in.f1C == 0) {
        r = func_0218B408((char *)(&in), sys, pos);
        if (r != 0)
            return r;
    }
    if (in.b5) {
        r = func_0218AED4((char *)(&in), (int)sys, pos);
        if (r != 0)
            return r;
        r = func_0218AF90((struct FieldInput *)(&in), sys, (u8 *)pos);
        if (r != 0)
            return r;
    }
    if (in.b6 && func_020221A4()) {
        void *pl = (void *)func_02188CCC((u8 *)pos);

        if (func_0215FF34(sys) && func_021A0ED4((u32)pl)) {
            r = (int)func_0215FF54((int)sys, (int)pos, in.f0);
            if (r != 0)
                return r;
        }
    }
    if (func_0201212C(sys) == 1 && func_020221A4() && in.b10)
        return func_021C06CC(sys, (u8 *)pos);
    if (in.b1 && func_020221A4()) {
        if ((int)func_021A0F90((void *)func_02188CCC((u8 *)pos)) == 6)
            return 0;
        *outB = 1;
        return (int)func_0215FC40((int)sys, (int)pos, in.f0);
    }
    if (func_020221A4()) {
        r = func_021A0EB0((void *)func_02188CCC((u8 *)pos), in.b7);
        if (r != 0)
            return r;
    }
    if (in.b7 && func_020221A4()) {
        r = (int)func_0218ACA8(sys);
        if (r != 0)
            return r;
    }
    r = func_0217B410((int)pos, (int)sys, in.f18);
    if (r == 0)
        return 0;
    return r;
}














int func_0218A074(void *a, int b)
{
    int u;
    int v;
    int r;
    void *p;
    void *q;

    p = func_0201210C(a);
    q = (void *)func_02188CE8(p);
    func_021AA8F8();
    r = func_02189BD0(a, (struct Obj00020 *)b, &u, &v);
    if (r != 0) {
        if (u != 0)
            func_021AA8EC(q);
        func_021BC5BC((u8 *)((void *)func_02188D20(p)));
        func_021A3550(func_02188CB4(p), v);
        func_021A356C(func_02188CB4(p));
        if (func_02189A70(p) != 0)
            func_021F3B10();
        func_0218A6E8(a, p);
    }
    return r;
}














int func_0218A0E4(void *sys, struct Obj00020 *pos)
{
    struct FieldInput_02189BBC in;
    void *a;
    void *ev;
    int r;
    int obj;
    u32 k;
    void *m;

    a = (void *)func_02012138(sys);
    ev = (void *)func_02026474(a);
    func_0218A4E0((struct FieldInput_0218A4E0 *)(&in), sys, pos);
    if (ev == 0) {
        if (func_0200FB24() != 0) {
            if (func_020221A4() != 0)
                return func_021C06CC(sys, (u8 *)pos);
            return 0;
        }
        return (int)func_021850FC(sys, (u8 *)pos);
    }
    if (func_0217391C(ev) == 1) {
        if (func_02173928(ev) == 0)
            func_02026400(a);
        return 0;
    }
    if (in.b2 && (r = func_0218A784((struct Ctx784 *)(&in), 9)) != 0)
        return r;
    if ((r = func_0217B80C((int)sys, (int)pos)) != 0)
        return r;
    if (in.b0 && (r = func_0217B83C(sys, pos)) != 0)
        return r;
    if (in.b0 && func_0217394C(sys) == 1) {
        obj = func_0218B4B0((struct FieldCtx *)((struct FieldCtx_02189BBC *)(&in)), (u8 *)pos);
        if (obj != 0) {
            k = func_0216D5B8((void *)obj);
            if (func_02158D90(k) == 1) {
                m = func_021A3074((u8 *)in.f18);
                if (func_0217AF38(func_0216D588((void *)obj)) == 0) {
                    func_021A2F6C((u32 *)in.f18);
                    return func_0219F01C((u32)sys, (u32)pos, k, (u32)m, obj, in.f0);
                }
            }
        }
    }
    if (func_0201212C(sys) == 1 && func_020221A4() != 0)
        return func_021C06CC(sys, (u8 *)pos);
    if (func_0217394C(sys) == 0)
        return 0;
    if (in.b1 && func_020221A4() != 0)
        return func_0215FCE0((int)sys, (int)pos, in.f0);
    return 0;
}














int func_0218A240(void *p, struct Obj00020 *pos)
{
    void *h;
    int r = func_0218A278(p, pos);
    if (r != 0) {
        h = func_0201210C(p);
        func_021BC5BC((u8 *)func_02188D20(h));
        if (func_02189A70(h) != 0)
            func_021F3B10();
        func_0218A6E8(p, h);
    }
    return r;
}














/*
 * Addresses are Black-image addresses.
 */
int func_0218A278(void *sys, struct Obj00020 *pos)
{
    struct FieldInput_02189BBC in;
    Cell_02189BBC here;
    int cur[2];
    Cell_02189BBC copy;
    void *model;
    int r;
    u32 msg;

    func_0218A4E0((struct FieldInput_0218A4E0 *)(&in), sys, (struct Obj00020 *)pos);
    model = func_021A3074((u8 *)in.f18);
    func_0219E634(model, (int *)((u32)(&here)));
    r = func_0218A738((struct Ctx738 *)(&in));
    if (r != 0)
        return r;
    if (in.b2)
        func_0218A728(in.f8);
    if (in.b2) {
        void *obj = func_021A3074((u8 *)in.f18);
        void *flags = (void *)func_0201296C(in.f8);

        func_0219E2F4(obj, cur);
        msg = func_02162958(in.fC, flags, (int)cur);
        if (msg != 0xFFFF)
            return (int)func_02158768((int)sys, msg, 0, in.f0);
        r = func_0218B0CC((char *)(&in), sys, pos);
        if (r != 0)
            return r;
        r = func_0218A9B0((struct Ctx9B0 *)(&in), (u8 *)pos);
        if (r != 0)
            return r;
    }
    r = func_0218B208((struct FieldCtx *)((struct FieldCtx_02189BBC *)(&in)), sys, (u8 *)pos);
    if (r != 0)
        return r;
    if (in.b0) {
        int target = func_0218B53C((unsigned char *)(&in), pos);
        void *flags;
        u16 d;

        if (target != 0) {
            u32 kind = func_0216D5B8((void *)target);

            if (func_02158D90(kind) == 1) {
                void *m = func_021A3074((u8 *)in.f18);

                func_021A2F6C((u32 *)in.f18);
                return func_0219F01C((u32)sys, (u32)pos, kind, (u32)m, target, in.f0);
            }
        }
        flags = (void *)func_0201296C(in.f8);
        d = func_0216D5F8(model);
        copy = here;
        msg = func_02162A5C(in.fC, flags, &copy, d);
        if (msg != 0xFFFF)
            return (int)func_02158768((int)sys, msg, 0, in.f0);
    }
    if (in.b5 && func_0218B310(func_02188CB4(pos), (unsigned char *)(&in)) == 0) {
        r = func_0218B13C((char *)(&in), sys, pos, (int *)(&here));
        if (r != 0)
            return r;
    }
    r = func_0218B24C((char *)(&in), sys, pos);
    if (r != 0)
        return r;
    if (in.b6 && func_020221A4()) {
        void *pl = (void *)func_02188CCC((u8 *)pos);

        if (func_0215FF34(sys) && func_021A0ED4((u32)pl)) {
            r = (int)func_0215FF54((int)sys, (int)pos, in.f0);
            if (r != 0)
                return r;
        }
    }
    if (func_0201212C(sys) == 1 && func_020221A4() && in.b10)
        return func_021C06CC(sys, (u8 *)pos);
    if (in.b1 && func_020221A4()) {
        if (func_021A0F90((void *)func_02188CCC((u8 *)pos)) == 6)
            return 0;
        return (int)func_0215FC40((int)sys, (int)pos, in.f0);
    }
    {
        u32 f = (in.b7 && func_020221A4()) ? 1 : 0;

        r = func_021A0EB0((void *)func_02188CCC((u8 *)pos), f);
        if (r != 0)
            return r;
    }
    if (in.b7 && func_020221A4()) {
        r = (int)func_0218ACA8(sys);
        if (r != 0)
            return r;
    }
    return 0;
}














/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A4BC(u32 a, u32 b, u32 c, u32 d)
{
if (func_02188CFC((u8 *)b) == 0) {
    return func_0218A074((void *)a, b);
}
return func_0218A240((void *)a, (struct Obj00020 *)b);
}














/*
 * Fills the 0x40 byte field input record for one frame: pad trigger and held
 * keys, the held d-pad direction, the player object's position, facing and
 * movement state, and the request bitfield at 0x3C (talk on A, menu on X,
 * registered item on Y, no-input, step, surf and push flags).
 *
 * Addresses are Black-image addresses.
 */
void func_0218A4E0(struct FieldInput_0218A4E0 *p, void *sys, struct Obj00020 *pos)
{
    void *obj;

    func_02082BCC(p, 0, 0x40);
    p->f0 = func_02188C84((u8 *)pos);
    p->sys = sys;
    p->f8 = func_020120F4(sys);
    p->fC = (void *)func_02012844(p->f8);
    p->f10 = func_02188C9C((u8 *)pos);
    p->trg = func_020362DC();
    p->cont = func_0203630C();
    p->dir = 9;
    if (p->cont & 0x40)
        p->dir = 0;
    else if (p->cont & 0x80)
        p->dir = 1;
    else if (p->cont & 0x20)
        p->dir = 2;
    else if (p->cont & 0x10)
        p->dir = 3;
    p->pos = (u8 *)pos;
    p->f18 = func_02188CB4(pos);
    func_021A2FE4(p->f18);
    p->f20 = func_021A3080(p->f18);
    p->f1C = func_021A308C(p->f18);
    obj = func_021A3074(p->f18);
    p->f24 = func_0216D5F8(obj);
    p->f34 = (u32)func_0216D888(obj);
    p->f26 = func_02014478(func_02012B38(p->f8));
    p->f38 = func_021A30C8(p->f18);

    if (p->f1C == 3 || p->f1C == 0) {
        u8 n;

        p->b10 = 1;
        p->b0 = (p->trg & 1) ? 1 : 0;
        p->b1 = (p->trg & 0x400) ? 1 : 0;
        p->b6 = (p->trg & 0x800) ? 1 : 0;
        n = 0;
        n += p->b0;
        n += p->b1;
        n += p->b6;
        if (n == 0)
            p->b7 = 1;
    }
    p->b2 = 0;
    p->b9 = 0;
    if (p->f20 == 1)
        p->b2 = (p->f1C == 3) ? 1 : 0;
    if (func_021A3584(p->f18))
        p->b9 = 1;
    p->b3 = (p->f1C == 3) ? 1 : 0;
    p->b4 = 0;
    if (p->f1C != 3 && p->f20 == 2)
        p->b4 = 1;
    if ((p->f24 == 0 && (p->cont & 0x40)) || (p->f24 == 1 && (p->cont & 0x80))
        || (p->f24 == 2 && (p->cont & 0x20)) || (p->f24 == 3 && (p->cont & 0x10)))
        p->b5 = 1;
    else
        p->b5 = 0;
}














void func_0218A6E8(void *sys, void *q)
{
    void *r;

    r = (void *)func_021A1358((u32 *)func_02188CCC(q));
    if (r == 0) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4(sys)));
        return;
    }
    if (func_021F2AB8(r) == 0) {
        func_02028A70((struct SoundSys *)func_02012A30(func_020120F4(sys)));
        func_021F2AD4(r);
    }
}














int func_0218A728(void *a)
{
return func_02008DF0((struct Sub02008C20Obj *)func_02012F2C((int *)a), 0);
}














/*
 * Starts the pending script (field 0x26) through func_02158768, or else asks
 * func_02158B00 for the default one; returns the result.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A738(struct Ctx738 *c)
{
    int r;

    if (c->f26 != 0) {
        func_02014474(func_02012B38(c->f8), 0);
        return (int)func_02158768((int)c->f4, c->f26, 0, c->f0);
    }
    r = (int)func_02158B00(c->f4, c->f0);
    if (r == 0)
        return 0;
    return r;
}














/*
 * Tries func_0218A8BC, then func_0218A784 with direction 9.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A76C(void *p)
{
    int r = func_0218A8BC(p);

    if (r != 0)
        return r;
    return func_0218A784(p, 9);
}














/*
 * Unless the tile attribute under the object's position blocks it
 * (func_021AB188), asks ov010 func_02162928 for a message id and shows it
 * through func_02158768; returns 0 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A784(struct Ctx784 *c, int a)
{
    void *x = func_0201210C(c->f4);
    void *y = (void *)func_0201296C(c->f8);
    u32 pos[3];
    u32 msg;

    func_021A3038(c->f18, (struct VecFx32 *)pos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(x), pos))) == 1)
        return 0;
    msg = func_02162928(c->fC, y, (int)pos, a);
    if (msg != 0xFFFF)
        return (int)func_02158768((int)c->f4, msg, 0, c->f0);
    return 0;
}














/*
 * Tries func_0218A784 for the current facing, then for the direction from
 * func_021A2FA4 when that differs and is not 9.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A7F0(struct FieldCtx_02189BBC *p)
{
    int r = func_0218A784((struct Ctx784 *)p, p->f24);
    int dir;

    if (r != 0)
        return r;
    dir = func_021A2FA4(p->f18, p->f2C);
    if (dir == 9 || dir == p->f24)
        return 0;
    r = func_0218A784((struct Ctx784 *)p, dir);
    if (r == 0)
        return 0;
    return r;
}













/*
 * Maps the held d-pad bits (up, down, left, right) to a direction and, unless
 * it is the current facing, none, or the movement mode is 1 or 2, tries
 * func_0218A784 with it. The two-value mode test is a switch.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A824(struct FieldCtx_02189BBC *p)
{
    u32 keys = p->f2C;
    u32 mode = p->f1C;
    int dir = 9;

    if (keys & 0x40)
        dir = 0;
    else if (keys & 0x80)
        dir = 1;
    else if (keys & 0x20)
        dir = 2;
    else if (keys & 0x10)
        dir = 3;
    if (dir == p->f24)
        return 0;
    if (dir == 9)
        return 0;
    switch (mode) {
    case 1:
    case 2:
        return 0;
    }
    return func_0218A784((struct Ctx784 *)p, dir);
}













/*
 * When flag field 0x10 is set and func_021A2FA4 does not report 9, forwards
 * the object to ov018 func_0217B4D8; returns 0 otherwise.
 *
 * Addresses are Black-image addresses.
 */
void *func_0218A878(u8 *p, void *a, void *b)
{
    int r;

    if (func_02013D5C(((struct Obj04981 *)p)->f10) == 0)
        return 0;
    r = func_021A2FA4(((struct Obj04981 *)p)->f18, ((struct Obj04981 *)p)->f2C);
    if (r == 9)
        return 0;
    return func_0217B4D8(a, b, ((struct Obj04981 *)p)->f18, *(int * *)&((struct Obj04981 *)p)->f34, ((struct Obj04981 *)p)->f24, r);
}













/*
 * Checks the background event in front of the player: shows its message when
 * the player stands at the event's centre tile, or when the tile behaviour is
 * one of 0x58..0x5B or 0xA3..0xA6 (range test spelled as the add of the
 * complement,
 * docs/idioms/a-masked-byte-subtract-in-a-range-test-is-an-add-of-the-complement.md)
 * or func_021A3098 allows it.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A8BC(struct FieldCtx_02189BBC *p)
{
    void *obj = func_0201210C(p->f4);
    void *id = func_02188CB4(obj);
    int pos[3];
    struct BgEvent *e;
    int a;
    u16 b;
    u32 cx;
    u16 *r;
    u32 cz;

    func_021A3038(id, (struct VecFx32 *)pos);
    if (func_021AB188(func_021AB0F0(func_021AB0D4((void *)func_02188C98(obj), pos))) != 1)
        return 0;
    e = (struct BgEvent *)func_0216282C(p->fC, (void *)func_0201296C(p->f8), pos, 9);
    if (e == 0)
        return 0;
    if (e->f8 != 0)
        return 0;
    r = (u16 *)&e->rect;
    cz = r[1] + ((u32)r[3] >> 1);
    cx = e->rect.x + ((u32)r[2] >> 1);
    if (cx == (pos[0] >> 12) / 16 && cz == (pos[2] >> 12) / 16)
        return (int)func_02158768((int)p->f4, e->msg, 0, p->f0);
    a = func_021A3098(id);
    b = func_0216D7C4(func_021A3074(id));
    if (a != 0 || b == 0x58 || b == 0x59 || b == 0x5A || b == 0x5B || (u16)(b + 0xFF5D) <= 3)   /* b - 0xA3 */
        return (int)func_02158768((int)p->f4, e->msg, 0, p->f0);
    return 0;
}













/*
 * Field step handler: runs the step-triggered checks in order (func_0218AC84,
 * the 128-step counter, milestones, egg hatching, the save flag message) and
 * returns the first non-zero result. Flags come from the u32 bitfield at
 * 0x3C.
 *
 * Addresses are Black-image addresses.
 */
int func_0218A9B0(struct Ctx9B0 *p, u8 *pos)
{
    void *msg;
    void *sys;
    int r;

    func_02188C84(pos);
    msg = func_02188C80(pos);
    sys = func_020120F4(msg);
    if (p->b2 || p->b9) {
        r = func_0218AC84(pos, msg, sys);
        if (r != 0)
            return r;
    }
    if (!p->b2)
        return 0;
    func_0218AB9C(p->f8, pos);
    r = func_0218AC08(msg, pos, p->f10);
    if (r != 0)
        return r;
    r = func_0218AB50(p, pos, msg, sys);
    if (r != 0)
        return r;
    r = func_0218AC4C(pos, msg, sys);
    if (r == 0)
        return 0;
    return r;
}













/*
 * Returns 2 when a non-egg party member holds item 0x31 or 0x28, else 1.
 */
int func_0218AA2C(void *party)
{
    int count = func_0201AA18(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 item = func_02017E1C(mon, 0xA, 0);
        if (func_02017E1C(mon, 0x4C, 0) == 0 && (item == 0x31 || item == 0x28))
            return 2;
    }
    return 1;
}













/*
 * For every egg in the party, lowers field 9 (the step counter) by the amount
 * from func_0218AA2C, clamping at zero.
 *
 * Addresses are Black-image addresses.
 */
void func_0218AA74(void *party)
{
    int count = func_0201AA18(party);
    u32 amount = func_0218AA2C(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 flag = func_02017E1C(mon, 0x4C, 0);
        u32 v = func_02017E1C(mon, 9, 0);
        if (flag == 1) {
            u32 nv = 0;
            if (v >= amount)
                nv = v - amount;
            func_02017E40(mon, 9, nv);
        }
    }
}













/*
 * Adds func_02010FF4(0x100) to the step accumulator in the save block; once
 * it passes 0x10000 it advances the party's egg counters (func_0218AA74) and
 * resets it.
 *
 * Addresses are Black-image addresses.
 */
void func_0218AAD0(void *sys, void *party)
{
    void *save = func_02008854(func_02012EBC(sys));
    u32 steps;

    func_02008970(save, &steps);
    steps += func_02010FF4(0x100);
    if (steps > 0x10000) {
        func_0218AA74(party);
        steps = 0;
    }
    func_0200896C(save, steps);
}













/*
 * Returns 1 when some egg in the party has field 9 (the step counter) at
 * zero.
 */
int func_0218AB0C(void *party)
{
    int count = func_0201AA18(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 flag = func_02017E1C(mon, 0x4C, 0);
        u32 v = func_02017E1C(mon, 9, 0);
        if (flag == 1 && v == 0)
            return 1;
    }
    return 0;
}













/*
 * Step hook: updates func_021C3378, advances the party step counter
 * (func_0218AAD0) and, when an egg is ready (func_0218AB0C), shows message
 * 0x8CA.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AB50(void *p, u8 *pos, void *msg, void *sys)
{
    u16 v = func_02188C84(pos);
    void *party = func_02012934(sys);

    func_021C3378(func_02188D50(pos));
    func_0218AAD0(sys, party);
    if (func_0218AB0C(party))
        return (int)func_02158768((int)msg, 0x8CA, 0, v);
    return 0;
}













/*
 * Bumps a 7-bit counter in the save block; when it wraps, calls func_0201B7EC
 * on every party member with the two coordinates read from the position
 * object.
 *
 * Addresses are Black-image addresses.
 */
void func_0218AB9C(void *sys, u8 *pos)
{
    void *save = func_02008854(func_02012EBC(sys));
    int wrapped = 0;
    u16 count = func_02008978(save) + 1;

    if (count >= 0x80) {
        count = 0;
        wrapped = 1;
    }
    func_02008980(save, count);
    if (wrapped) {
        void *party = func_02012934(sys);
        int a;
        int b;
        int n;
        int i;

        a = func_02188C9C(pos);
        b = func_02188C84(pos);
        n = func_0201AA18(party);
        for (i = 0; i < n; i++)
            func_0201B7EC(func_0201AB28(party, i), a, b);
    }
}













/*
 * When func_02013FFC accepts the id, shows the milestone message
 * (func_021D220C) and increments the save block counter; returns the message
 * result.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AC08(void *msg, u8 *pos, u16 id)
{
    void *save = func_02008854(func_02012EBC(func_020120F4(msg)));
    int r = 0;

    if (func_02013FFC(id)) {
        r = func_021D220C(msg, pos);
        func_02008988(save, func_02008990(save) + 1);
    }
    return r;
}













int func_0218AC4C(u8 *pos, void *msg, void *sys)
{
    if ((u8)func_0200D564(func_0200D418(func_02012EBC(sys))))
        return (int)func_02158768((int)msg, 0x2792, 0, func_02188C84(pos));
    return 0;
}













/*
 * Runs func_021AA944 on the position's object; when it declines, calls
 * func_021AA80C and returns 0.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AC84(u8 *pos, void *msg, void *sys)
{
    void *obj;
    int r;

    func_02012EBC(sys);
    obj = (void *)func_02188CE8(pos);
    r = func_021AA944(obj);
    if (r == 0) {
        func_021AA80C(obj);
        return 0;
    }
    return r;
}













struct Desc *func_0218ACA8(void *a)
{
    if (func_02010F18() == 0x30) {
        return 0;
    }
    return func_020124AC(a, (u32)abs_id_83, (u32 (*)(void *, u32))func_021F532C, 0);
}











/*
 * For a usable entry id (func_0218AE04), unless ov010 func_021626EC reports
 * kind 1 or func_0218AEAC rejects it, builds its record (func_0218ADC8) and
 * dispatches it (func_0218AD80).
 *
 * code in ov010 (ldrh r2, [r0]; ldr r1, [pc, #0x14]; ...) with no func_
 * label, so no class attests it. It closes once ov010 0x021626EC is labelled.
 *
 * Addresses are Black-image addresses.
 */
int func_0218ACD0(u8 *p, void *a, void *arg)
{
    u32 id = func_0218AE04(p, arg);
    void *obj;

    if (id == 0xFFFF)
        return 0;
    obj = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
    if (func_021626EC(obj) == 1 || !func_0218AEAC(obj))
        return 0;
    func_0218ADC8(p, id, arg);
    return func_0218AD80(p, a, id, arg);
}












/*
 * Looks up the tile attribute under the position and starts the matching tile
 * task (func_021C8A30 or func_021C8C88); returns the task or 0.
 *
 * Addresses are Black-image addresses.
 */
void *func_0218AD28(struct FieldCtx_0218AD28 *p, struct Obj00020 *pos)
{
    int buf[3];
    u16 attr;

    func_021A3038(p->f18, (struct VecFx32 *)buf);
    attr = func_021AB0F0(func_021AB0D4((void *)func_02188C98((u8 *)pos), buf));
    if (func_021C8A74(attr))
        return func_021C8A30(0, p->f4, pos);
    if (func_021C8CF0(attr))
        return func_021C8C88(0, p->f4, pos);
    return 0;
}












/*
 * Looks up entry id through func_021625CC, optionally resolves its argument,
 * then dispatches to ov020 func_02185410 for kind 6 or func_02185360
 * otherwise.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AD80(u8 *p, void *a, int id, void *arg)
{
    void *obj = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
    void *d;

    if (arg != 0)
        d = (void *)func_021626A8(obj, arg);
    else
        d = 0;
    if (func_021626E8(obj) == 6)
        return (int)func_02185410(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
    else
        return (int)func_02185360(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
}












/*
 * Builds a 0x1C byte rectangle record with func_02014110 from the object's
 * map value, an id and three words, and hands it to func_02012878.
 *
 * Addresses are Black-image addresses.
 */
void func_0218ADC8(u8 *p, int id, u32 *pos)
{
    u8 buf[0x1C];

    func_02014110(buf, func_02188C9C(*(u8 * *)&((struct Obj00705 *)p)->f14), id, 0, 0, pos[0], pos[1], pos[2]);
    func_02012878(((struct Obj00705 *)p)->f8, (const struct Rec1C *)buf);
}












/*
 * Returns the current entry id from func_02162564 when it is usable
 * (func_0218AEAC or func_0218AECC accepts it), else 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0218AE04(u8 *p, void *arg)
{
    u32 id = (u32)func_02162564(((struct Obj00705 *)p)->fC, arg);
    void *obj;

    if (id == 0xFFFF)
        return 0xFFFF;
    obj = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
    if (!func_0218AEAC(obj) && !func_0218AECC(obj, ((struct Obj00705 *)p)->f24))
        return 0xFFFF;
    return id;
}












void func_0218AE48(struct Obj_02189BBC *p, struct Vec_02189BBC *out){
    *out = *p->pos;
    switch (p->dir) {
    case 0:
        out->z -= 0x10000;
        break;
    case 1:
        out->z += 0x10000;
        break;
    case 2:
        out->x -= 0x10000;
        break;
    case 3:
        out->x += 0x10000;
        break;
    }
}












/*
 * True when func_021626E8 reports kind 0, 5 or 6.
 *
 * Addresses are Black-image addresses.
 */
int func_0218AEAC(u8 *p)
{
    u8 v = func_021626E8(p);
    return v == 0 || v == 5 || v == 6;
}












/*
 * Unblocked by matching func_021626B8 (ov010, EXACT): the +0004 ABS32 site now
 * attests as `matched`.
 */
int func_0218AECC(char *a0, int a1)
{
    return func_021626B8(a0, a1);
}












int func_0218AED4(char *p, int unused, void *a)
{
    Vec_02189BBC v;
    int id;
    void *o;

    func_0218AE48((struct Obj_02189BBC *)p, &v);
    if ((func_021AB0F8(func_021AB0D4((void *)func_02188C98(a), &v)) & 1) == 0)
        return 0;
    id = (int)func_0218AE04((u8 *)p, *(Vec_02189BBC * *)&((struct Obj00705 *)p)->f34);
    if (id != 0xFFFF) {
        o = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
        if (func_021626EC(o) == 0 && func_021626E8(o) == 1) {
            func_0218ADC8((u8 *)p, id, (u32 *)(*(Vec_02189BBC * *)&((struct Obj00705 *)p)->f34));
            return func_0218AD80((u8 *)p, (void *)a, id, (void *)(*(Vec_02189BBC * *)&((struct Obj00705 *)p)->f34));
        }
    }
    id = (int)func_0218AE04((u8 *)p, &v);
    if (id != 0xFFFF) {
        if (func_021626EC(func_021625CC(((struct Obj00705 *)p)->fC, (u16)id)) == 0) {
            func_0218ADC8((u8 *)p, id, (u32 *)(*(Vec_02189BBC * *)&((struct Obj00705 *)p)->f34));
            return func_0218AD80((u8 *)p, (void *)a, id, (void *)(&v));
        }
    }
    return 0;
}












int func_0218AF90(struct FieldInput *p, void *a, u8 *pos)
{
    Vec_02189BBC v;
    Vec_02189BBC w;
    int h;
    u32 attr;
    void *m;

    func_0218AE48((struct Obj_02189BBC *)p, &v);
    if (func_021BE288(pos, 6))
        return func_021F3A88((int)a, v.x / 0x10000, v.z / 0x10000);
    if (func_021BE288(pos, 0x19) || func_021BE288(pos, 0x1A) || func_021BE288(pos, 0x1B))
        return func_021F38A4((int)pos, p->f24);
    attr = func_021AB0D4((void *)func_02188C98(pos), &v);
    if ((func_021AB0F8(attr) & 1) == 0)
        return 0;
    if (func_021A3098(p->f18) == 2 && func_0218B630(p->f8, 0x7F) != 6
        && func_021AB310(func_021AB0F0(attr)) == 1) {
        w = v;
        m = func_021A3074(p->f18);
        func_02164208(p->f24, (int *)(&w), 0x10000);
        if (func_02163E58(m, &w, &h) == 1 && v.y > h)
            return (int)func_02158768((int)p->sys, 0x271F, 0, p->f0);
    }
    if (func_0218AE04((u8 *)p, &v) == 0xFFFF) {
        if (func_021BE288(pos, 2))
            return func_021F404C(a);
        if (func_021BE288(pos, 5))
            return func_021F37E0(a);
    }
    return 0;
}












/*
 * Calls the unlabelled ov010 leaf func_021626EC (filed as pkt_ov010_021626EC).
 *
 * Addresses are Black-image addresses.
 */
int func_0218B0CC(char *p, void *unused, void *x)
{
    int buf[2];
    int r4;
    void *r6;

    func_0219E2F4(func_021A3074(func_02188CB4(x)), buf);
    r4 = func_02162598(((struct Obj04982 *)p)->fC, (struct Q *)buf);
    if (r4 == 0xFFFF)
        return 0;
    r6 = func_021625CC(((struct Obj04982 *)p)->fC, (u16)r4);
    if (func_021626EC(r6) == 1 || func_0218AEAC(r6) == 0)
        return 0;
    func_0218B2A8(p, r4, (u16 *)buf);
    return func_0218B2E8(p, x, r4, buf);
}












int func_0218B13C(char *p, void *unused, void *x, int *alt)
{
    int buf[2];
    int id;
    void *o;

    func_0219E2F4(func_021A3074(func_02188CB4(x)), buf);
    id = func_02162598(((struct Obj04983 *)p)->fC, (struct Q *)buf);
    if (id != 0xFFFF) {
        o = func_021625CC(((struct Obj04983 *)p)->fC, (u16)id);
        if (func_021626EC(o) == 0 && func_0218AECC(o, ((struct Obj04983 *)p)->f24) != 0
            && func_021626E8(o) == 1) {
            func_0218B2A8(p, id, (u16 *)buf);
            return func_0218B2E8(p, x, id, buf);
        }
    }
    id = func_02162598(((struct Obj04983 *)p)->fC, (struct Q *)alt);
    if (id == 0xFFFF)
        return 0;
    o = func_021625CC(((struct Obj04983 *)p)->fC, (u16)id);
    if (func_021626EC(o) == 0 && func_0218AECC(o, ((struct Obj04983 *)p)->f24) != 0) {
        func_0218B2A8(p, id, (u16 *)buf);
        return func_0218B2E8(p, x, id, buf);
    }
    return 0;
}












/*
 * When bit 3 of the flag word is set, runs the object's interaction:
 * func_021AA248 with the map value when func_02013DD0 accepts field 0x10,
 * else func_021A9F40(obj, 0).
 *
 * is an unlabelled Thumb veneer (ldr r1, [pc, #4]; ldr r3, [pc, #8]; movs r2,
 * #4; bx r3) with no witness; it closes once arm9 0x02013DD0 is labelled.
 *
 * Addresses are Black-image addresses.
 */
int func_0218B208(struct FieldCtx *p, void *unused, u8 *pos)
{
    void *obj = (void *)func_02188CE8(pos);

    if (!p->b3)
        return 0;
    if (func_02013DD0(p->f10))
        return func_021AA248(obj, func_0218DC70((u8 *)func_02188C98(pos)));
    return func_021A9F40(obj, 0);
}












int func_0218B24C(char *p, void *q, void *x)
{
    void *a = func_02188CB4(x);
    void *o = func_021A3074(a);
    int r = func_021A2FA4(a, ((struct Obj09449 *)p)->f2C);

    if (r == 1) {
        int t = ((struct Obj09449 *)p)->f1C;
        if (t == 0 || t == 3) {
            if (func_021BB188(func_021AB0F0(((struct Obj09449 *)p)->f38))) {
                if (func_0219E418((u32)o, r) & 3)
                    return func_021C46F8((u32)q, (u32)x, r);
            }
        }
    }
    return 0;
}












void func_0218B2A8(char *p, int s, u16 *v)
{
    int buf[7];

    func_02014134((u8 *)buf, func_02188C9C(((struct Obj04982 *)p)->f14), (s16)s, 0, 0, v[0], v[3], (s16)v[2]);
    func_02012878(((struct Obj04982 *)p)->f8, (const struct Rec1C *)buf);
}












int func_0218B2E8(char *p, void *x, int a, int *b)
{
    void *obj = func_021625CC(((struct Obj04982 *)p)->fC, (u16)a);
    return (int)func_02185360(((struct Obj04982 *)p)->f4, (int)x, (int)obj, func_021626B0(obj, b));
}












int func_0218B310(void *a, unsigned char *s)
{
    if ((func_0219E418((u32)func_021A3074(a), ((struct Obj19510 *)s)->f24) & 3) == 0)
        return 1;
    return 0;
}












int func_0218B32C(void *unused, int *st, char *ctx)
{
    void *a = func_02188CB4(((struct Obj05974 *)ctx)->fC);
    void *o;
    int r1;

    func_021A3098(a);
    o = func_021A3074(a);
    switch (*st) {
    case 0:
        func_0216D9A0(func_0216D67C(o));
        func_0216D5E0((int)o, ((struct Obj05974 *)ctx)->f4);
        *st = *st + 1;
        break;
    case 1:
        func_021ACBB8((u32)func_021A2F98(a), 0);
        func_021A2F48(a, 1);
        func_021A2F60(a);
        r1 = func_02197E7C(((struct Obj05974 *)ctx)->f4, 0x34);
        if (((struct Obj05974 *)ctx)->f6 == 1)
            r1 = func_02197E7C(((struct Obj05974 *)ctx)->f4, 0x38);
        func_0216D410(o, r1);
        *st = *st + 1;
        break;
    case 2:
        if (func_0216D454(o) == 1) {
            func_021A2FD0(a);
            *st = *st + 1;
        }
        break;
    case 3:
        func_0216D9E4(func_0216D67C(o));
        func_021A35A0(a, 1);
        return 1;
    }
    return 0;
}












int func_0218B3DC(int unused, int a, int b, int c, int d)
{
    int h = (int)func_020122C0((void *)a, 0, func_0218B32C, 0x10);
    Ent_02189BBC *e = func_020124E8((struct Obj_02189BBC *)h);
    e->f8 = a;
    e->fC = b;
    e->f4 = c;
    e->f6 = d;
    return h;
}












int func_0218B408(char *p, void *a, void *x)
{
    void *cam;
    int r7;
    int t;
    int flag;
    int t2;
    void *id;
    int v;
    int buf[3];

    id = func_02188CB4(x);
    if (func_021A3098(id) == 2) {
        cam = (void *)func_02188C98(x);
        r7 = func_021A2FA4((u8 *)(*(int *)&((struct Obj07410 *)p)->f18), ((struct Obj07410 *)p)->f2C);
        if (r7 != 9) {
            func_021A3364(id, r7, buf);
            t = func_021AB0D4(cam, buf);
            v = func_021AB0F8(t);
            t2 = func_021AB0F0(t);
            flag = 0;
            if (func_021AB2E8(t2) == 1) {
                func_02164208(r7, buf, 0x10000);
                v = func_021AB0F8(func_021AB0D4(cam, buf));
                flag = 1;
            }
            if (func_0218B6F8(p, x) == 1 && !(v & 1) && !(v & 2))
                return func_0218B3DC((int)p, (int)a, (int)x, r7, flag);
        }
    }
    return 0;
}












/*
 * Reads the object's grid position, and when the tile attribute in front
 * allows it (func_021AB194) steps it one tile in its facing direction, then
 * moves the camera object there (func_0216DDDC).
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
int func_0218B4B0(struct FieldCtx *p, u8 *pos){
    void *obj = func_021A3074(p->f18);
    s16 v[3];
    int xyz[3];
    void *cam;

    func_021A3460((u32)p->f18, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    func_02164294(v[2], v[1], v[0], xyz);
    if (func_021AB194(func_021AB0F0(func_021AB0D4((void *)func_02188C98(pos), xyz))) == 1)
        func_02164240(func_0216D5F8(obj), &v[2], &v[0], 1);
    cam = func_02188C7C(pos);
    return (int)func_0216DDDC((u32)cam, v[2], v[0], func_0216D8AC(obj), 0x10000, 0);
}












int func_0218B53C(unsigned char *p, void *b)
{
    int buf[2];
    if (func_0219E634(func_021A3074(((struct Obj19511 *)p)->f18), buf) != 0)
        return func_0219E570((u32)func_02188C7C(b), (u32)buf, 0);
    return 0;
}












/*
 * Picks the message for the tile the player faces: the first of the 13 table
 * entries at 0x021D3CE8 whose direction matches and whose attribute test
 * passes, else the water prompts 0x2712 (when a party member knows Surf) or
 * 0x2716; 0xFFFF for none.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0218B56C(struct FieldCtx_0218B56C *p, u8 *pos)
{
    u32 here;
    u32 ahead;
    u16 attr;
    u32 i;

    if (func_02012B70(p->f8) == 1)
        return 0xFFFF;
    here = func_021A30C8(p->f18);
    ahead = func_021A3128(p->f18, p->f24);
    attr = func_021AB0F0(ahead);
    for (i = 0; i < 13; i++) {
        if ((p->f24 == data_021D3CE8[i].dir || data_021D3CE8[i].dir == 9) && data_021D3CE8[i].test(attr))
            return data_021D3CE8[i].msg;
    }
    if (!func_02013E04(p->f10) || func_02012B70(p->f8) == 1)
        return 0xFFFF;
    if (func_021A3504((u8 *)p->f18, here, ahead) && func_0218B630(p->f8, 0x39) != 6)
        return 0x2712;
    if (func_021A3524((u8 *)p->f18, (u32)here, (u32)ahead))
        return 0x2716;
    return 0xFFFF;
}












/*
 * Returns the index of the first non-egg party member that knows the given
 * move (checks move slots 0x36..0x39), or 6 when none does. Called with 0x39
 * (Surf).
 *
 * Addresses are Black-image addresses.
 */
int func_0218B630(void *sys, u32 move)
{
    int n;
    void *party;
    int i;

    party = func_02012934(sys);
    n = func_0201AA18(party);

    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);

        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            if (move == func_02017E1C(mon, 0x36, 0) || move == func_02017E1C(mon, 0x37, 0)
                || move == func_02017E1C(mon, 0x38, 0) || move == func_02017E1C(mon, 0x39, 0))
                return i;
        }
    }
    return 6;
}












int func_0218B6AC(void *ctx)
{
    void *list;
    void *e;
    int n;
    int i;
    int cnt;

    list = func_02012934(func_020120F4(ctx));
    n = func_0201AA18(list);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        e = func_0201AB28(list, i);
        if (func_02017E1C(e, 0x4C, 0) == 0 && func_02017E1C(e, 0xA0, 0) != 0)
            cnt++;
    }
    return cnt;
}












int func_0218B6F8(char *p, void *q)
{
    void *o = func_021A3074(((struct Obj07410 *)p)->f18);
    u16 d = ((struct Obj07410 *)p)->f30;
    int x = func_0216D83C(o);
    int z = func_0216D86C(o);
    int i;

    for (i = 0; i < 2; i++) {
        x = (s16)(x + func_021641E8(d));
        z = (s16)(z + func_021641F8(d));
        if (func_0216DDC0((u32)func_02188C7C(q), x, z, 1))
            return 0;
    }
    return 1;
}












/*
 * Allocates and initialises a 0x13F8-byte object.
 *
 * Addresses are Black-image addresses.
 */
char *func_0218B754(u16 a, void *b, u16 c)
{
    char *p;
    int i;
    unsigned j;
    int z = 0;

    p = (char *)func_02030734(a, 0x13F8, 0, d_021DD9CC, 0x193);
    ((struct Obj02071 *)p)->f0 = a;
    *(void **)&((struct Obj02071 *)p)->f4 = b;
    func_0218BCE4((S_0218BCF4 *)(p + 8), c);
    for (i = 0; i < 7; i++)
        *(int *)(p + 0x1DC + i * 4) = z;
    for (j = 0; j < 0x120; j++)
        func_0218C490(p, (EntSlot *)(p + 0x1F8 + j * 16));
    ((struct Obj02071 *)p)->f1B0 = 0;
    ((struct Obj02071 *)p)->f1B4 = 0;
    ((struct Obj02071 *)p)->f1B8 = 0;
    ((struct Obj02071 *)p)->f1BC = 0;
    ((struct Obj02071 *)p)->f1C0 = 0;
    ((struct Obj02071 *)p)->f1C4 = 0;
    ((struct Obj02071 *)p)->f1C8 = 0;
    ((struct Obj02071 *)p)->f1CC = 0;
    ((struct Obj02071 *)p)->f1D4 = 0;
    ((struct Obj02071 *)p)->f1D8 = 0;
    return p;
}












void func_0218B7F8(char *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (*(void **)(p + 0x1DC + i * 4) != 0)
            func_0218C860(*(void **)(p + 0x1DC + i * 4));
    }
    func_0218BE84((u8 *)p, (u8 *)(p + 0x1B0));
    func_0218BD94((u8 *)p);
    func_0218BB64(p);
    func_0218BC6C((unsigned char *)p);
    func_020307B0(p);
}












void func_0218B83C(char *p)
{
    int i;
    unsigned u;

    func_0218BCF4((S_0218BCF4 *)(p + 8));
    for (i = 0; i < 7; i++) {
        char *q = *(char **)(p + 0x1DC + i * 4);
        if (q != 0)
            func_0218C124(p, (Obj_0218BDD8 *)(q + 0xC));
    }
    for (u = 0; u < ((struct Obj12562 *)p)->f1D4; u++)
        func_0218C124(p, (Obj_0218BDD8 *)(*(char * *)&((struct Obj12562 *)p)->f1D8 + u * 0x18));
}











void func_0218B88C(unsigned char *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (((void **)(p + 0x1DC))[i] != 0)
            func_0218C934(((void **)(p + 0x1DC))[i]);
    }
}











void func_0218B8AC(char *p, int a, int b, int c)
{
    void *s;
    int k1;
    int k2;
    int k3;

    s = (void *)func_0218BC1C(func_02013B38(a));
    if (func_020140D8((struct Sub020140BCObj *)b)) {
        k1 = 0xE5;
        k2 = 0xB0;
        k3 = 0x15;
    } else {
        k1 = 0xE6;
        k2 = 0xB1;
        k3 = 0x14;
    }
    func_0218BB0C((u8 *)p, k1, (u32)s);
    func_0218BC40((unsigned char *)p, (u16)k2, (int)s, c);
    func_0218BB78((u8 *)p, k3);
    func_0218BD28((FieldMsgbgWork *)p, c);
    func_0218BDD8((u8 *)p, (u32 *)(p + 0x1B0));
}











int func_0218B910(FieldMsgbgWork *p, u32 b)
{
    return func_0218BBF4(p->f18, func_0218BBD0(p, b));
}













/*
 * Tail-call thunk: the object's word at +0x18.
 *
 * Addresses are Black-image addresses.
 */
int func_0218B924(u8 *p, u32 a1)
{
    return func_0218BBF4(((struct Obj17893 *)p)->f18, a1);
}













static inline void Vec_Set(Vec_0218B924 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}













int func_0218B930(void *p, int a, Vec_0218B924 *pos, int *k)
{
    Ent_0218B924 *e = (Ent_0218B924 *)func_0218B910((FieldMsgbgWork *)p, a);
    if (e->id == 0xFFFF)
        return 0;
    *k = func_0218BBD0(p, e->id);
    Vec_Set(pos, e->x << 12, e->y << 12, e->z << 12);
    return 1;
}













/*
 * The const on s is load-bearing: with a plain Src_02189BBC * the compiler keeps
 * &s[i] in a register and spills s; const keeps s and i*16 in registers.
 */
/*
 * The const on s is load-bearing: with a plain Src * the compiler keeps
 * &s[i] in a register and spills s; const keeps s and i*16 in registers.
 */
int func_0218B974(void *p, int a, const Src_02189BBC *s, int n)
{
    Args_0218B924 args;
    int i;
    int cnt = 0;
    for (i = 0; i < n; i++) {
        func_0218BA04(p, a, s + i, cnt);
        if (func_0218B930(p, (unsigned short)(s[i].lo + (s[i].hi << 8)), &args.pos, &args.k) == 1) {
            cnt++;
            args.w = s[i].w;
            args.pos.x += s[i].x;
            args.pos.y += s[i].y;
            args.pos.z -= s[i].z;
            func_0218C4A0(p, a, &args, cnt);
        }
        cnt++;
    }
    return cnt;
}













/*
 * Tail-call thunk: forwards to func_0218C4EC with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_0218B9FC(int a, int obj)
{
    func_0218C4EC((unsigned char *)a, (void *)obj);
}













static inline void Args_SetPos(Args_0218BA04 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}













void func_0218BA04(void *p, int a, const Src_02189BBC *s, int d)
{
    Args_0218BA04 args;
    args.k = func_0218BBD0(p, (unsigned short)(s->lo + (s->hi << 8)));
    Args_SetPos(&args, s->x, s->y, -s->z);
    args.w = s->w;
    func_0218C4A0((void *)p, a, (Args_0218B924 *)(&args), d);
}













void func_0218BA48(FieldMsgbgWork *p, void *v)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (p->f1DC[i] == v) {
            p->f1DC[i] = 0;
            return;
        }
    }
}













void func_0218BA70(FieldMsgbgWork *p, void *v)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (p->f1DC[i] == 0) {
            p->f1DC[i] = v;
            return;
        }
    }
}













void *func_0218BA98(FieldMsgbgWork *p, int h)
{
    unsigned short idx = h & ~0xFFF0;
    if ((unsigned short)(h & 0xFFF0) != 0xFFF0)
        return 0;
    if (idx >= 7)
        return 0;
    return p->f1DC[idx];
}













unsigned short func_0218BACC(FieldMsgbgWork *p, void *v)
{
    int i;
    if (v == 0)
        return 0;
    for (i = 0; i < 7; i++) {
        if (p->f1DC[i] == v)
            return 0xFFF0 | i;
    }
    return 0;
}













/*
 * Returns the object pointer advanced by 432 bytes.
 */
u8 *func_0218BB04(u8 *p)
{
    return p + 432;
}













void func_0218BB0C(u8 *s, u16 a, u32 n)
{
    void *h;
    u8 *r;

    h = func_020490F4(a, (u16)((((struct Obj00572 *)s)->f0 & 0x7fff) | 0x8000));
    if (func_0204961C(h) <= n)
        n = 0;
    r = func_02049250(h, n, ((struct Obj00572 *)s)->f0);
    *(u8 * *)&((struct Obj00572 *)s)->f18 = r;
    ((struct Obj00572 *)s)->f1AC = (u32)r[2] >> 1;
    if (((struct Obj00572 *)s)->f1AC > 0x190)
        ((struct Obj00572 *)s)->f1AC = 0x80;
    func_02049238(h);
}












int func_0218BB64(char *a)
{
func_020307B0((void *)(((struct Obj01114 *)((u8 *)(a)))->f18));
*(u16 *)((u8 *)(a) + ((107 << 2))) = 0;
return (107 << 2);
}












void func_0218BB78(u8 *s, int k)
{
    u8 i;
    u8 v;
    int j;

    func_02082BCC(s + 0x1c, 0x80, 0x190);
    for (i = 0; i < ((struct Obj00572 *)s)->f1AC; i++)
        s[*((u16 *)func_0218B924(s, i)) + 0x1c] = i;
    v = (s + k)[0x1c];
    for (j = 0; j < 0x190; j++) {
        if (s[j + 0x1c] == 0x80)
            s[j + 0x1c] = v;
    }
}












int func_0218BBD0(FieldMsgbgWork *p, unsigned int i)
{
    unsigned char v;
    if (i >= 0x190)
        i = 0;
    v = p->f1C[i];
    if (v >= 0x80 || v >= p->f1AC)
        v = 0;
    return v;
}












int func_0218BBF4(u32 a, u32 b)
{
return (a + *(u32 *)((u8 *)((a + (b << 2))) + 4));
}











/*
 * Leaf: offset-table walk.  p[2] is a byte count; the table starts at p+4,
 * each entry a 32-bit relative offset.  Returns p + entry[i + (p[2]>>1)].
 * Callee of func_0218B8AC.
 */
char *func_0218BC00(char *p, int i)
{
    unsigned n = (unsigned char)p[2];
    return p + *(int *)(p + 4 + ((n >> 1) + i) * 4);
}












u8 *func_0218BC10(u8 *a, int b)
{
return (a + *(u32 *)((u8 *)((a + (b << 2))) + 4));
}











/*
 * Value remap: x >= 0xd2 maps to x-0xd2, x in [2,0xd2) maps to (x-2)/4,
 * x < 2 maps to 0.  The unsigned range tests force `blo` while the division
 * stays signed.  Callee of func_0218B8AC.  EXACT* (follower 0x0218BC40).
 */
unsigned short func_0218BC1C(int x)
{
    if ((unsigned)x >= 0xd2)
        return (unsigned short)(x - 0xd2);
    if ((unsigned)x >= 2)
        return (unsigned short)((x - 2) / 4);
    return 0;
}











/* The trailing guard is the function exit: only its cmp survives. */
void func_0218BC40(unsigned char *p, int a, int b, int c)
{
    ((struct Obj00572 *)p)->f1D0 = (int)func_02046DB8(a, b);
    if (c != 0)
        func_0218D0D8((void *)(((struct Obj00572 *)p)->f1D0), (void *)c);
    if (func_020470A8((void *)(((struct Obj00572 *)p)->f1D0)) == 0)
        return;
}











void func_0218BC6C(unsigned char *p)
{
    if (((struct Obj01114 *)p)->f1D0 != 0) {
        func_020470D0(((struct Obj01114 *)p)->f1D0);
        func_02046EFC(((struct Obj01114 *)p)->f1D0);
        ((struct Obj01114 *)p)->f1D0 = 0;
    }
}










int func_0218BC8C(int *p)
{
    unsigned int i;
    int n;
    for (i = 0, n = 0; i < 4; i++) {
        if (p[i + 1] != -1)
            n++;
    }
    return n;
}











/*
 * Returns the object pointer advanced by 0x10 bytes.
 */
u8 *func_0218BCAC(u8 *p)
{
    return p + 0x10;
}










unsigned char func_0218BCB0(unsigned short *p)
{
    Tbl t = d_021D3DC4;
    if (p[1] >= 16)
        return 0;
    return t.b[p[1]];
}










/*
 * Stores a tag and a byte, then tail calls with the same operands.
 *
 * Addresses are Black-image addresses.
 */
void func_0218BCE4(S_0218BCF4 *p, u8 v)
{
    p->cur = 5;
    p->id = v;
    func_0218BCF4(p);
}









void func_0218BCF4(S_0218BCF4 *p)
{
    p->prev = p->cur;
    p->cur = func_020113D8(p->id);
    p->changed = p->cur != p->prev;
    p->val = d_021D3D50[p->cur];
}









/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_0218BD20(u8 *p)
{
    return ((struct Obj17894 *)p)->f8;
}









/*
 * Loads the byte at +0xc of the object.
 */
u8 func_0218BD24(u8 *p)
{
    return ((struct Obj17895 *)p)->fC;
}









void func_0218BD28(FieldMsgbgWork *p, int arg)
{
    unsigned short n = p->f1AC;
    unsigned char i;
    if (n != 0) {
        p->f1C8 = n;
        p->f1CC = func_02030734(p->f0, n * 0x18, 1, d_021DD9CC, 0x45F);
        for (i = 0; i < p->f1C8; i++)
            func_0218BEE8((u8 *)p, (void **)(p->f1CC + i * 0x18), i, arg);
    }
}









void func_0218BD94(u8 *s)
{
    u32 i;

    if (*(u8 * *)&((struct Obj01114 *)s)->f1CC != 0) {
        for (i = 0; i < ((struct Obj01114 *)s)->f1C8; i++)
            func_0218BF84((S_0218BDD8 *)(*(u8 * *)&((struct Obj01114 *)s)->f1CC + i * 0x18));
        func_020307B0(*(u8 * *)&((struct Obj01114 *)s)->f1CC);
        ((struct Obj01114 *)s)->f1C8 = 0;
        *(u8 * *)&((struct Obj01114 *)s)->f1CC = 0;
    }
}












void func_0218BDD8(u8 *s, u32 *out)
{
    u32 n;
    u32 i;

    n = ((struct Obj00572 *)s)->f1AC;
    if (n != 0) {
        out[1] = n;
        out[0] = (u32)func_02030734(((struct Obj00572 *)s)->f0, n << 3, 1, d_021DD9CC, 0x490);
        ((struct Obj00572 *)s)->f1D4 = n;
        *(u32 *)&((struct Obj00572 *)s)->f1D8 = (u32)func_02030734(((struct Obj00572 *)s)->f0, n * 0x18, 1, d_021DD9CC, 0x494);
        for (i = 0; i < ((struct Obj00572 *)s)->f1D4; i++) {
            u8 *a = *(u8 * *)&((struct Obj00572 *)s)->f1D8;
            u8 *b = *(u8 * *)&((struct Obj00572 *)s)->f1CC;
            func_0218BFB4((FieldMsgbgWork *)s, (u32 *)(a + i * 0x18), (u32 *)(b + i * 0x18));
            *(u32 *)(*(u8 * *)&((struct Obj07411 *)out)->f0 + i * 8) = *(u32 *)(a + i * 0x18);
            *(u32 *)(*(u8 * *)&((struct Obj07411 *)out)->f0 + i * 8 + 4) = 0;
        }
    }
}












void func_0218BE84(u8 *s, u8 *e)
{
    u32 i;

    if (((struct Obj04986 *)e)->f0 != 0) {
        func_020307B0(((struct Obj04986 *)e)->f0);
        ((struct Obj04986 *)e)->f0 = 0;
    }
    if (((struct Obj04986 *)e)->f8 != 0) {
        func_020307B0(((struct Obj04986 *)e)->f8);
        ((struct Obj04986 *)e)->f8 = 0;
    }
    if (*(u8 * *)&((struct Obj01114 *)s)->f1D8 != 0) {
        for (i = 0; i < ((struct Obj01114 *)s)->f1D4; i++)
            func_0218C0D8((void **)(*(u8 * *)&((struct Obj01114 *)s)->f1D8 + i * 0x18));
        func_020307B0(*(u8 * *)&((struct Obj01114 *)s)->f1D8);
        ((struct Obj01114 *)s)->f1D4 = 0;
        *(u8 * *)&((struct Obj01114 *)s)->f1D8 = 0;
    }
}












void func_0218BEE8(u8 *s, void **out, int x, int unused)
{
    u8 *t;
    int cnt;
    int i;

    out[0] = (void *)func_0218B924(s, x);
    out[1] = func_02030734(((struct Obj09454 *)s)->f0, func_02046C94(), 1, d_021DD9CC, 0x4d0);
    func_02046CE0(out[1], (u32 *)func_0218BC00(((struct Obj09454 *)s)->f18, x));
    t = func_0218BCAC(out[0]);
    cnt = func_0218BC8C((int *)t);
    for (i = 0; i < 4; i++) {
        if (i < cnt) {
            out[2 + i] = func_02030734(((struct Obj09454 *)s)->f0, func_02046C94(), 1, d_021DD9CC, 0x4db);
            func_02046CE0(out[2 + i], (u32 *)func_0218BC10(t, i));
        } else {
            out[2 + i] = 0;
        }
    }
}












void func_0218BF84(S_0218BDD8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            func_020307B0(p->arr[i]);
            p->arr[i] = 0;
        }
    }
    if (p->f4 != 0) {
        func_020307B0(p->f4);
        p->f4 = 0;
    }
}












/*
 * The table index is narrowed in its own statement (`k = (u8)k;`): the
 * second definition makes k a two-definition web that is coloured after
 * the multiply product, so the ldrb lands in r4, the product in r3 and
 * the t reload in r0 (docs/idioms/a-self-narrowing-cast-statement-
 * recolours-a-table-index.md). A cast inside the subscript is inert.
 *
 * Addresses are Black-image addresses.
 */
void func_0218BFB4(FieldMsgbgWork *a, u32 *out, u32 *st)
{
    u32 buf[4];
    u8 *t;
    u32 h;
    int i;
    u8 k;

    t = func_0218BCAC((u8 *)st[0]);
    h = (u32)func_02047400((void *)st[1], 0, (void *)(((struct Obj19518 *)a)->f1D0));
    for (i = 0; i < 4; i++) {
        if (st[2 + i] != 0)
            buf[i] = (u32)func_02047564((struct G3dOwner *)h, (const struct G3dOwner *)st[2 + i], 0);
        else
            buf[i] = 0;
    }
    out[0] = (u32)func_0204767C(h, buf, 4);
    out[1] = (u32)st;
    k = t[0];
    k = (u8)k;
    d_021D3D58[k].fn(a, out);
}












/*
 * Entry_02189BBC of the d_021D3D58 dispatch table (pool word 0x0218C02D at +0x0 and
 * +0x18), called by func_0218BFB4 as fn(a, out): clears out[2..5].
 */
/*
 * Entry of the d_021D3D58 dispatch table (pool word 0x0218C02D at +0x0 and
 * +0x18), called by func_0218BFB4 as fn(a, out): clears out[2..5].
 */
void func_0218C02C(void *a, u32 *out)
{
    int i;

    for (i = 0; i < 4; i++) {
        out[2 + i] = 0;
    }
}












void func_0218C040(void *a, void **b)
{
    u8 *t;
    u32 n;
    int i;

    t = func_0218BCAC(*(void **)b[1]);
    n = t[2];
    for (i = 0; i < 4 && i < n; i++) {
        func_020477A4(b[0], (u16)i);
        func_02047804(b[0], i);
        b[2 + i] = (void *)1;
    }
    for (; i < 4; i++)
        b[2 + i] = 0;
}











void func_0218C08C(u8 *a, void **b)
{
    int i;
    u32 m;

    func_0218BCAC(*(void **)b[1]);
    m = func_0218BD24(a + 8);
    for (i = 0; i < 4; i++) {
        if (i != m) {
            b[2 + i] = 0;
        } else {
            func_020477A4(b[0], (u16)i);
            func_02047804(b[0], i);
            b[2 + i] = (void *)1;
        }
    }
}











void func_0218C0D8(void **s)
{
    int n;
    int i;
    void *r;

    if (s[0] != 0) {
        n = func_0204779C(s[0]);
        for (i = 0; i < n; i++) {
            void *o = (void *)func_02047790(s[0], (u16)i);
            if (o != 0)
                func_0204762C(o);
        }
        r = (void *)func_02047788(s[0]);
        func_02047738(s[0]);
        s[0] = 0;
        s[1] = 0;
        func_02047504(r);
    }
}









void func_0218C124(void *p, Obj_0218BDD8 *s)
{
    unsigned char k = *func_0218BCAC((u8 *)(*s->f4));
    if (s->f0 != 0)
        d_021D3D5C[k].f0(p, s);
}








void func_0218C150(void)
{
}










/*
 * Starts slot i of a four-slot effect set, or resets it.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C154(u8 *a, u32 *st)
{
    int i = func_0218BD24(a + 8);

    if (func_0218BD20(a + 8) != 0) {
        func_0218C388((S_0218C154 *)st);
        func_020477A4((struct G3dSys *)st[0], (u16)i);
        func_02047804((struct AnmCtl *)st[0], i);
        (st + i)[2] = 1;
    } else {
        func_02047910((void *)st[0], (u16)i, 0x1000);
    }
}











void func_0218C1A4(int unused, int *s)
{
    int i;
    for (i = 0; i < 4; i++)
        func_02047910((void *)(*s), (unsigned short)i, 0x1000);
}











/*
 * Per-slot state machine step over four slots.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C1C4(u32 unused, u32 *st)
{
    int i;

    for (i = 0; i < 4; i++) {
        switch (st[2 + i]) {
        case 0:
        case 2:
            break;
        case 3:
            if (func_020478B8((void *)st[0], (u16)i, 0x1000) == 0)
                st[2 + i] = 2;
            break;
        case 4:
            if (func_020478B8((void *)st[0], (u16)i, -0x1000) == 0) {
                func_0204784C((struct AnmCtl *)st[0], (u16)i, 0);
                st[2 + i] = 2;
            }
            break;
        case 1:
            func_02047910((void *)st[0], (u16)i, 0x1000);
            break;
        }
    }
}











/*
 * Starts a group of slots and marks them state 3.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C23C(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        func_020477A4((struct G3dSys *)st[0], (u16)(base + i));
        func_02047804((struct AnmCtl *)st[0], base + i);
        (st + base)[2 + i] = 3;
    }
}











/*
 * Starts a group of slots and marks them state 1.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C290(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        func_020477A4((struct G3dSys *)st[0], (u16)(base + i));
        func_02047804((struct AnmCtl *)st[0], base + i);
        (st + base)[2 + i] = 1;
    }
}











/*
 * Starts a group of slots, sets a parameter, marks them state 4.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C2E4(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;
    int v;

    for (i = 0; i < q[2]; i++) {
        func_020477A4((struct G3dSys *)st[0], (u16)(base + i));
        v = *(u16 *)(*(u8 **)(func_02047674((int)func_02047790((int *)st[0], (u16)(base + i))) + 8) + 4) << 12;
        func_0204784C((struct AnmCtl *)st[0], base + i, &v);
        (st + base)[2 + i] = 4;
    }
}











void func_0218C350(u32 *st, int n)
{
    u8 *q = func_0218BCAC(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        if ((st + base)[2 + i] != 0)
            (st + base)[2 + i] = 2;
    }
}











void func_0218C388(S_0218C154 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            func_020477D4((struct Owner *)p->h, (unsigned short)i);
            p->arr[i] = 0;
        }
    }
}










void func_0218C3B0(Obj_0218BDD8 *p, int i, int c)
{
    unsigned char k = *func_0218BCAC((u8 *)(*p->f4));
    unsigned char idx = i;
    if (idx >= 4)
        idx = 0;
    d_021D3D5C[k].f4(p, idx, c);
}










/*
 * Dispatches a slot-group operation by mode 0..4.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C3E0(u32 *st, int n, int mode)
{
    switch (mode) {
    case 0:
        func_0218C388((S_0218C154 *)st);
        func_0218C23C(st, n);
        break;
    case 1:
        func_0218C388((S_0218C154 *)st);
        func_0218C2E4(st, n);
        break;
    case 2:
        func_0218C388((S_0218C154 *)st);
        func_0218C290(st, n);
        break;
    case 3:
        func_0218C350(st, n);
        break;
    case 4:
        func_0218C388((S_0218C154 *)st);
        break;
    }
}








void func_0218C438(void)
{
}










/*
 * Reports whether slot i (0 if out of range) is in state 0 or 2.
 */
int func_0218C43C(u32 *st, int i)
{
    u8 j = i;

    if (j >= 4)
        j = 0;
    switch ((st + j)[2]) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
    case 4:
        return 0;
    }
    return 0;
}










int func_0218C47C(int *p, int id)
{
    int out;
    func_02047828((struct AnmCtl *)(*p), (unsigned short)id, &out);
    return out;
}










void func_0218C490(void *unused, EntSlot *s)
{
    s->key = 0;
    s->b = -1;
    s->c = 0;
    s->d = 0;
    s->e = 0;
}










/*
 * Claims the first free 16-byte entry of the table at +0x1F8.
 *
 * Addresses are Black-image addresses.
 */
u32 *func_0218C4A0(u8 *base, u32 a, void *b, int c)
{
    u32 *e = (u32 *)(base + 0x1F8);
    u32 i;

    for (i = 0; i < 0x120; i++) {
        e = (u32 *)(base + 0x1F8 + i * 16);
        if (e[0] == 0) {
            func_021693D4((u8 *)a, (u8 *)b, c);
            e[0] = a;
            e[1] = -1;
            ((struct Obj04988 *)e)->f8 = c;
            *((u16 *)(e + 2) + 1) = 1;
            e[3] = (u32)func_02169444((u8 *)a, c);
            return e;
        }
    }
    return 0;
}








void func_0218C4EC(unsigned char *p, void *key)
{
    EntSlot *e = (EntSlot *)(p + 0x1F8);
    int i;
    for (i = 0; i < 0x120; i++) {
        if (e[i].key == key)
            func_0218C518(p, &e[i]);
    }
}












/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216940C (0x0216940C) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_0218C518(u8 *base, EntSlot *e)
{
    func_0216940C(e->key, e->c);
    func_0218C490(base, e);
}













u8 func_0218C530(int a){
if (*(u32 *)((u8 *)(((struct Obj09173 *)((u8 *)(a)))->fC)) == (~0)) {
    return ((((struct Obj09173 *)((u8 *)(a)))->f4 << 24) >> 24);
}
return ((*(u32 *)((u8 *)(((struct Obj09173 *)((u8 *)(a)))->fC)) << 24) >> 24);
}













void func_0218C54C(S_0218C54C *p, int save)
{
    if (save) {
        *p->fC = p->f4;
        p->f4 = -1;
        p->fA = 1;
    } else {
        p->f4 = *p->fC;
        *p->fC = -1;
        p->fA = 0;
    }
}













void func_0218C574(FieldMsgbgWork *a, S_0218C574 *s, int b)
{
    *s->d = func_0218BBD0(a, b);
}











static inline int InRect(Rect *r, int x, int z)
{
    if (r->c <= x && r->d >= x && r->a <= z && r->b >= z)
        return 1;
    return 0;
}











/*
 * Collects the active 16-byte entries whose position lies inside a rect.
 *
 * Addresses are Black-image addresses.
 */
Ent_0218C518 **func_0218C584(u8 *s, Rect *r, int kind, int *count)
{
    Ent_0218C518 **list;
    Ent_0218C518 *e;
    Vec_0218C518 v;
    int n = 0;
    u32 i;

    list = func_02030734(((struct Obj19535 *)s)->f0, 0x80, 1, d_021DD9CC, 0x749);
    for (i = 0; i < 0x120; i++) {
        e = (Ent_0218C518 *)(s + 0x1F8) + i;
        if (e->obj == 0)
            continue;
        if (kind != 0 && kind != func_0218C674(s, (int)e))
            continue;
        func_02169510(e->obj, (Vec_0218C518 *)&v);
        func_0207C9D0((Vec_0218C518 *)(e->ref + 4), &v, &v);
        if (InRect(r, v.x, v.z) == 1) {
            list[n] = e;
            n++;
        }
    }
    *count = n;
    return list;
}













int func_0218C638(int a, int b, int c)
{
    int tmp;
    int *r = (int *)func_0218C584((u8 *)a, (Rect *)c, b, &tmp);
    int v = *r;
    func_020307B0(r);
    return v;
}














int func_0218C654(int a, int b, int c)
{
    unsigned char buf[16];
    func_0218C9C4((Rect *)buf, (int *__restrict)c);
    return func_0218C638(a, b, (int)buf);
}














int func_0218C674(unsigned char *p, int b)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj19537 *)p)->f1AC)
        v = 0;
    return func_0218BCB0((short unsigned int *)func_0218B924(p, v));
}













void func_0218C69C(unsigned char *p, int b, int i, int c)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj12572 *)p)->f1AC)
        v = 0;
    func_0218C3B0((Obj_0218BDD8 *)(*(unsigned char * *)&((struct Obj12572 *)p)->f1D8 + v * 0x18), i, c);
}













void func_0218C6D0(int *p, int b)
{
    int buf[3];
    func_02169510((int)((u8 *)p[0]), (Vec_0218C518 *)((struct V3_0218C518 *)buf));
    func_0207C9D0((void *)((unsigned char *)p[3] + 4), (void *)buf, (void *)b);
}













int func_0218C6F4(unsigned char *p, int b, int id)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj12574 *)p)->f1AC)
        v = 0;
    return func_0218C47C((int *)(*(unsigned char * *)&((struct Obj12574 *)p)->f1D8 + v * 0x18), id);
}












/*
 * Allocates a 0x60-byte node for a definition, builds its matrices, registers it.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_0218C724(FieldMsgbgWork *owner, u32 *obj)
{
    u8 *def = (u8 *)obj[3];
    u8 *p;
    Vec3 tmp;
    int k;

    p = func_02030734(((struct Obj04199 *)owner)->f0, 0x60, 0, d_021DD9CC, 0x7E9);
    *(FieldMsgbgWork **)&((struct Obj04200 *)p)->f0 = owner;
    *(u32 * *)&((struct Obj04200 *)p)->f8 = obj;
    ((struct Obj04200 *)p)->f4 = 0xFFFF;
    k = ((struct Obj12576 *)def)->f10 >> 4;
    func_0207AF1C(p + 0x3C, d_020A1B38[k * 2], d_020A1B38[k * 2 + 1]);
    func_02169510((int)((u8 *)obj[0]), (Vec_0218C518 *)((struct V3_0218C518 *)(p + 0x24)));
    func_0207C9D0(p + 0x24, def + 4, p + 0x24);
    func_0218DC5C((u8 *)((struct Obj04199 *)owner)->f4, &tmp);
    func_0207C9D0(p + 0x24, &tmp, p + 0x24);
    ((struct Obj04200 *)p)->f30 = 0x1000;
    ((struct Obj04200 *)p)->f34 = 0x1000;
    ((struct Obj04200 *)p)->f38 = 0x1000;
    func_0218BFB4(owner, (u32 *)(p + 0xC), (u32 *)(*(u8 * *)&((struct Obj04199 *)owner)->f1CC + ((struct Obj12576 *)def)->f0 * 0x18));
    func_0218BA70(owner, p);
    func_0218C54C((S_0218C54C *)(*(u32 *)&((struct Obj04200 *)p)->f8), 0);
    return p;
}












int func_0218C7D8(void *p, int b, int c)
{
    int r = func_0218C654((int)p, b, c);
    if (r == 0)
        return 0;
    return (int)func_0218C724(p, (u32 *)r);
}











/*
 * Allocates a 0x60-byte node, copies a 60-byte block into it, registers it.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_0218C7F0(FieldMsgbgWork *owner, u32 x, Blk *src)
{
    u8 *p = func_02030734(((struct Obj04199 *)owner)->f0, 0x60, 0, d_021DD9CC, 0x825);

    *(FieldMsgbgWork **)&((struct Obj09456 *)p)->f0 = owner;
    ((struct Obj09456 *)p)->f8 = 0;
    ((struct Obj09456 *)p)->f4 = 0xFFFF;
    *(Blk *)(p + 0x24) = *src;
    func_0218BFB4(owner, (u32 *)(p + 0xC),
                  (u32 *)(*(u8 * *)&((struct Obj04199 *)owner)->f1CC + func_0218BBD0(owner, x) * 0x18));
    func_0218BA70(owner, p);
    return p;
}











void func_0218C860(S_0218C518 *p)
{
    if (p != 0) {
        func_0218BA48(p->owner, p);
        func_0218C0D8((void **)p->fC);
        if (p->f8 != 0)
            func_0218C54C((S_0218C54C *)p->f8, 1);
        func_020307B0(p);
    }
}











void func_0218C88C(unsigned char *p, int v, int c)
{
    if (p != 0) {
        ((struct Obj19538 *)p)->f4 = v;
        func_0218C3B0((Obj_0218BDD8 *)(p + 0xC), v, c);
    }
}











void func_0218C89C(unsigned char *p, int v)
{
    if (p != 0)
        func_0218C3B0((Obj_0218BDD8 *)(p + 0xC), ((struct Obj19539 *)p)->f4, v);
}











int func_0218C8B0(void *p, int v)
{
    if (p == 0)
        return 1;
    if (func_0218C8FC(p, v) == 1) {
        func_0218C88C(p, v, 3);
        return 1;
    }
    return 0;
}











int func_0218C8D8(void *p)
{
    if (p == 0)
        return 1;
    if (func_0218C910(p) == 1) {
        func_0218C89C(p, 3);
        return 1;
    }
    return 0;
}











int func_0218C8FC(unsigned char *p, int i)
{
    if (p == 0)
        return 0;
    return func_0218C43C((u32 *)(p + 0xC), i);
}











int func_0218C910(unsigned char *p)
{
    if (p == 0)
        return 0;
    return func_0218C43C((u32 *)(p + 0xC), ((struct Obj19540 *)p)->f4);
}











unsigned short func_0218C924(unsigned char *p)
{
    if (p == 0)
        return 0;
    return (**(FieldMsgbgWork ** *)&((struct Obj19541 *)p)->f10)->f2;
}











void func_0218C934(unsigned char *p)
{
    if (p != 0)
        func_02047A60((void *)(((struct Obj19544 *)p)->fC), (struct Arg *)(p + 0x24));
}











/*
 * Looks up a 10-byte-stride table row by key and reads column idx.
 *
 * Addresses are Black-image addresses.
 */
int func_0218C944(void *p, u32 idx, u16 *out)
{
    u32 key;
    u32 j;

    if (p == 0)
        return 0;
    key = func_0218C924(p);
    *out = 0;
    if (idx >= 4)
        return 0;
    for (j = 0; j < 6; j++) {
        if (key == *(u16 *)(d_021D3D88 + j * 10)) {
            *out = *(u16 *)(d_021D3D8A + j * 10 + idx * 2);
            return 1;
        }
    }
    return 0;
}











int func_0218C990(unsigned char *p, int v)
{
    if (p == 0)
        return 0;
    return func_0218C944(p, ((struct Obj19545 *)p)->f4, (u16 *)v);
}











int func_0218C9A4(void *p)
{
    unsigned short v;
    if (func_0218C990(p, (int)(&v)) == 0)
        return 0;
    return func_02006224(func_02006148(v));
}











/*
 * `__restrict` on pos lets mwcc keep pos[2] in a register across the
 * out->a/out->b stores and sink the out->a store past the pos[0] load
 * (see docs/idioms/a-restrict-position-parameter-sinks-a-store-past-the-next-load.md).
 */
void func_0218C9C4(Rect *out, int *__restrict pos)
{
    out->a = pos[2] - 0x30000;
    out->b = pos[2] + 0x30000;
    out->c = pos[0] - 0x20000;
    out->d = pos[0] + 0x20000;
}











char *func_0218C9E8(u16 heap, u16 b)
{
    char *p = func_02030734(heap, 0x74, 1, d_021DD9EC, 0xf9);
    int z = 0;
    ((struct Obj01115 *)p)->f0 = heap;
    ((struct Obj01115 *)p)->f34 = z;
    ((struct Obj01115 *)p)->f38 = z;
    ((struct Obj01115 *)p)->f3C = z;
    ((struct Obj01115 *)p)->f14 = z;
    ((struct Obj01115 *)p)->f16 = z;
    ((struct Obj01115 *)p)->f18 = z;
    ((struct Obj01115 *)p)->f1C = z;
    ((struct Obj01115 *)p)->f4 = z;
    ((struct Obj01115 *)p)->f8 = z;
    ((struct Obj01115 *)p)->fC = 1;
    ((struct Obj01115 *)p)->f10 = -1;
    ((struct Obj01115 *)p)->f40 = z;
    ((struct Obj01115 *)p)->f68 = z;
    ((struct Obj01115 *)p)->f64 = (int)func_0218B754(((struct Obj01115 *)p)->f0, (void *)p, b);
    ((struct Obj01115 *)p)->f6C = (int)func_021938AC(heap);
    ((struct Obj01115 *)p)->f70 = func_021C05D4(0x10, (u8)heap);
    return p;
}











int func_0218CA4C(void *a)
{
func_021C0674((void **)(((struct Obj05856 *)((u8 *)(a)))->f70));
func_0218D05C((char *)a);
func_021938D4((void *)(((struct Obj05856 *)((u8 *)(a)))->f6C));
if (((struct Obj05856 *)((u8 *)(a)))->f64 != 0) {
    func_0218B7F8((char *)(((struct Obj05856 *)((u8 *)(a)))->f64));
    ((struct Obj05856 *)((u8 *)(a)))->f64 = 0;
}
return func_020307B0(a);
}









void func_0218CA78(char *p)
{
    int i;
    int a;
    int b;

    if (((struct Obj00806 *)p)->f1C == 0)
        return;
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        func_0218DD70((unsigned int)(*(char * *)&((struct Obj00806 *)p)->f28 + i * 16));
    switch (((struct Obj00806 *)p)->fC) {
    case 0:
        func_0218D1D0(p, p + 0x34, ((struct Obj00806 *)p)->f28);
        break;
    case 1:
    default:
        func_0218D304(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 2:
        func_0218D444(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 3:
        func_0218D570((Obj_0218D570 *)((struct Obj *)p), (Cam *)((struct Cam *)(p + 0x34)), (Cell_0218C518 *)(((struct Obj00806 *)p)->f28));
        break;
    }
    func_0218D7A8((Obj_0218D7A8 *)((struct Obj *)p), (Cell_0218C518 *)(((struct Obj00806 *)p)->f28));
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        func_0216932C(*(int *)(*(char * *)&((struct Obj00806 *)p)->f24 + i * 0x28));
    a = sub_0207C768(((struct Obj00806 *)p)->f34, ((struct Obj00806 *)p)->f4);
    b = sub_0207C768(((struct Obj00806 *)p)->f3C, ((struct Obj00806 *)p)->f4);
    ((struct Obj00806 *)p)->f30 = (a >> 12) + (b >> 12) * ((struct Obj00806 *)p)->f14;
}









int func_0218CB34(char *p)
{
    int i;
    int r;
    int x;
    int y;
    u16 *h;

    if (((struct Obj00807 *)p)->f1C == 0)
        return 0;
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++)
        func_0218DD70((unsigned int)(*(char * *)&((struct Obj00807 *)p)->f28 + i * 16));
    switch (((struct Obj00807 *)p)->fC) {
    case 0:
        func_0218D1D0(p, p + 0x34, ((struct Obj00807 *)p)->f28);
        break;
    case 1:
    default:
        func_0218D304(p, (int *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    case 2:
        func_0218D444(p, (int *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    case 3:
        func_0218D570((Obj_0218D570 *)((struct Obj *)p), (Cam *)((struct Cam *)(p + 0x34)), (Cell_0218C518 *)(((struct Obj00807 *)p)->f28));
        break;
    }
    func_0218D7A8((Obj_0218D7A8 *)((struct Obj *)p), (Cell_0218C518 *)(((struct Obj00807 *)p)->f28));
    r = 0;
    func_0218DE78(p);
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++) {
        func_02169520(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), (int)(&h));
        if (*h == 1)
            r = 1;
        func_02169308((u8 *)(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28)));
        func_0218DEFC(p, *(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), i);
    }
    func_0218DF80((u8 *)p);
    x = func_0207C768(((struct Obj00807 *)p)->f34, ((struct Obj00807 *)p)->f4);
    y = func_0207C768(((struct Obj00807 *)p)->f3C, ((struct Obj00807 *)p)->f4);
    ((struct Obj00807 *)p)->f30 = (x >> 12) + (y >> 12) * ((struct Obj00807 *)p)->f14;
    func_0218B83C(((struct Obj00807 *)p)->f64);
    if (((struct Obj00807 *)p)->f68 != 0)
        func_021A73DC(((struct Obj00807 *)p)->f68);
    return r;
}









void func_0218CC34(S_0218CA78 *p)
{
    int i;
    if (p->f1C != 0) {
        for (i = 0; i < p->n; i++)
            func_02169308((u8 *)p->f24[i].h);
        func_0218DEF0((char *)p);
    }
}









void func_0218CC64(char *p, int a, int m)
{
    int w[3];
    int v[3];
    int idx;
    int i;
    u8 *c;

    if (m == 0 && ((struct Obj02072 *)p)->f40 == 0)
        return;
    for (i = 0; i < ((struct Obj02072 *)p)->f2E; i++) {
        if (func_0218DFE0((u8 *)p, i, m, (u32 *)(&idx))) {
            int r;
            c = (u8 *)p + 0x43;
            func_02169510((int)((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28))), (Vec_0218C518 *)((struct V3_0218C518 *)w));
            v[0] = w[0] + ((struct Obj02072 *)p)->f54;
            v[1] = w[1] + ((struct Obj02072 *)p)->f58;
            v[2] = w[2] + ((struct Obj02072 *)p)->f5C;
            func_02169500((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (u8 *)v);
            r = func_02169354(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28), a);
            func_02169500((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (u8 *)w);
            if (r != 0 && ((struct Obj02072 *)p)->f43 < ((struct Obj02072 *)p)->f2E)
                *c = *c + 1;
        }
    }
    if (m == 1)
        func_0218B88C((unsigned char *)(((struct Obj02072 *)p)->f64));
}









/*
 * Appends a block of tile columns to the map grid and remaps cell indices.
 *
 * Map cells are 4-byte structs (Tile): the cell copies are struct
 * assignments, which is what gives the copy loops the image's load order
 * and colours. The block's own cells are plain words (.v store).
 *
 * Addresses are Black-image addresses.
 */
int func_0218CD20(u32 a, Map *m, void *blk)
{
    u32 *src;
    u32 nn;
    Tile *buf;
    u32 q;
    u32 p;
    u16 nh;
    int bh;
    u16 nw;
    u16 bw;
    int bn;
    u32 k;
    u32 w;
    Ent_0218CD20 *e;
    int i;
    int j;

    bw = func_02159BF4(blk);
    bh = func_02159BF8(blk);
    bn = func_02159BFC(blk);
    src = func_02159C20(blk);
    nw = m->w + bw;
    nh = m->h;
    nn = m->n + bn;
    if (nh != bh)
        return 0;
    if (nn > 900 || nw > 30 || nh > 30)
        return 0;

    buf = func_02030734((u16)((m->heap & 0x7FFF) | 0x8000), nn * 4, 0, d_021DD9EC, 0x25F);
    for (i = 0; i < m->h; i++) {
        for (j = 0; j < m->w; j++)
            buf[i * nw + j] = m->tiles[i * m->w + j];
    }
    for (i = 0; i < bh; i++) {
        for (j = 0; j < bw; j++)
            buf[i * nw + m->w + j].v = src[i * bw + j];
    }
    for (k = 0; k < nn; k++)
        m->tiles[k] = buf[k];

    w = m->w;
    p = m->pos;
    m->pos = p % w + p / w * nw;
    for (i = 0; i < m->nEnts; i++) {
        if (func_0218DD84((u32)(&m->ents[i].pos))) {
            w = m->w;
            e = &m->ents[i];
            q = e->pos;
            e->pos = q % w + q / w * nw;
        }
    }
    m->w = nw;
    m->h = nh;
    m->n = nn;
    func_02159C00((void *)func_02012974(func_020120F4(func_02188C80((void *)a))), nw, nh);
    func_020307B0(buf);
    return 1;
}









/*
 * Unlabelled 4-byte getter (ldr r0, [r0, #0x70]; bx lr), a leaf of
 * ov043 func_021F36C0.
 */
void *func_0218CEE0(void *p)
{
    return ((struct Obj19549 *)p)->f70;
}









/*
 * Addresses are Black-image addresses.
 *
 * src is const: that lets the scheduler pull the long-lived field loads
 * (n, type, cols, rows) above the stores into p, as in the image.
 */
void func_0218CEE4(Obj *p, const Src_0218C518 *src, void *c)
{
    Cfg cfg;
    int i;
    int off;
    int h;

    p->f04 = src->f00;
    p->f08 = src->f04;
    p->f10 = src->f10;
    p->f14 = src->f14;
    p->f16 = src->f16;
    p->n = src->n;
    p->type = src->type;
    p->f1c = src->f1c;
    p->f2c = src->cols;
    p->f2d = src->rows;
    p->f2e = src->cols * src->rows;
    p->f40 = src->f38;
    p->f42 = p->f2e;
    p->f43 = p->f2e;
    switch (src->type) {
    case 0:
        if (src->n > p->f2e)
            p->type = 1;
        break;
    case 3:
        if (p->f14 * p->f16 > p->f2e / 2)
            p->type = 1;
        break;
    }
    p->f20 = src->f20;
    func_0218D104((u8 *)p, (u8 *)src, c);
    p->f68 = func_0218DC84(p->f2e, p->f60, src->f2c, p->heap);
    cfg.size = src->f34;
    cfg.texSize = 0;
    cfg.f08 = (u32)d_021D3DDC;
    cfg.f0c = 0;
    cfg.f10 = 0x800;
    cfg.nA = 0x20;
    cfg.nB = 0;
    cfg.f18 = 0x1000000;
    cfg.f1c = 0x400000;
    p->f24 = func_02030734(p->heap, p->f2e * 0x28, 1, d_021DD9EC, 0x306);
    p->f28 = func_02030734(p->heap, p->f2e << 4, 1, d_021DD9EC, 0x307);
    p->f44 = func_02030734(p->heap, p->f2e, 1, d_021DD9EC, 0x308);
    for (i = 0; i < p->f2e; i++) {
        off = i * 0x28;
        func_0218DD70((u32)(p->f24 + off + 0x18));
        func_0218DD14((int *)(p->f24 + off + 4), (char *)p, i, p->heap);
        cfg.f0c = p->f24 + off + 4;
        h = (int)func_02169148(&cfg, p->heap);
        *(int *)(p->f24 + off) = h;
        func_0216937C((u8 *)h, p->f10, p->heap);
        if (p->f60 != 0)
            func_021693B4((char *)h, p->f60);
        func_021693C4((char *)h, (int)func_0218BB04((u8 *)p->f64));
    }
}









void func_0218D05C(char *p)
{
    int i;

    if (*(int *)&((struct Obj01208 *)p)->f24 != 0) {
        for (i = 0; i < ((struct Obj01208 *)p)->f2E; i++) {
            int off = i * 0x28;
            func_021693CC((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_021693BC((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_021693A0(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off));
            func_0216928C((void *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_0218DD38((void **)(*(char * *)&((struct Obj01208 *)p)->f24 + off + 4));
        }
        func_020307B0(((struct Obj01208 *)p)->f24);
        func_020307B0(((struct Obj01208 *)p)->f28);
        func_020307B0(((struct Obj01208 *)p)->f44);
        *(int *)&((struct Obj01208 *)p)->f28 = 0;
        *(int *)&((struct Obj01208 *)p)->f24 = 0;
        *(int *)&((struct Obj01208 *)p)->f44 = 0;
        ((struct Obj01208 *)p)->f2E = 0;
    }
    if (((struct Obj01208 *)p)->f68 != 0) {
        func_021A73C0(((struct Obj01208 *)p)->f68);
        ((struct Obj01208 *)p)->f68 = 0;
    }
    func_0218D13C((u8 *)p);
}









/*
 * 2026-10-01: MATCH, capped only by the call to func_02022040 (arm9, Thumb,
 * unlabelled, no witness outside this function). It is a ~64+ byte RGB555
 * pixel converter (luma weights 76/151/29 over a lookup table); filing it
 * as an arm9 witness would lift this to EXACT.
 */
int func_0218D0D8(void *a, void *b)
{
    u8 *p = func_0206E964(func_02046F48(a));
    if (p != 0) {
        u32 size = ((struct Obj12581 *)p)->f30 << 3;
        u32 off = ((struct Obj12581 *)p)->f38;
        if (b != 0)
            func_02022040((u16 *)(p + off), size >> 1, b);
        return 1;
    }
    return 0;
}









void func_0218D104(u8 *a, u8 *b, void *c)
{
    u32 v = ((struct Obj19550 *)b)->f20;
    if (v != 0) {
        if (v == 1) {
            u32 *q = (u32 *)(b + 0x24);
            ((struct Obj07415 *)a)->f60 = (u32)func_02046DB8(q[0], q[1]);
            if (c != 0)
                func_0218D0D8((void *)(((struct Obj07415 *)a)->f60), c);
            func_020470A8((void *)(((struct Obj07415 *)a)->f60));
        }
    } else {
        ((struct Obj07415 *)a)->f60 = 0;
    }
}









void func_0218D13C(u8 *a)
{
    if (((struct Obj07416 *)a)->f60 != 0) {
        func_020470D0((u32 *)(((struct Obj07416 *)a)->f60));
        func_02046EFC((struct Tagged *)(((struct Obj07416 *)a)->f60));
        ((struct Obj07416 *)a)->f60 = 0;
    }
}









static inline void set3(V3_0218C518 *d, s32 x, s32 y, s32 z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}









/*
 * Copies a vector into dst+0x34 through an inline set3 helper with a const
 * source.  The image's c,b,a load order with the b,a,c store order needs
 * both: without const (or with plain statements or locals) the stores come
 * out in a,b,c order.  EXACT* only for the 2-byte alignment pad.
 */
void func_0218D158(T_02189BBC *dst, const V3_0218C518 *src)
{
    set3(&dst->v, src->x, src->y, src->z);
}









int func_0218D168(char *p)
{
    int v[3];
    unsigned int i;

    for (i = 0; i < ((struct Obj01846 *)p)->f2E; i++) {
        if (func_021694FC((u8 *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28)))) {
            int h;
            int x;
            int z;
            int x0;
            int x1;
            int z0;
            int z1;
            func_02169510((int)((u8 *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28))), (Vec_0218C518 *)((struct V3_0218C518 *)v));
            h = *(int *)&((struct Obj01846 *)p)->f4 / 2;
            x = v[0];
            z = v[2];
            x0 = x - h;
            z0 = z - h;
            x1 = x + h;
            z1 = z + h;
            if (((struct Obj01846 *)p)->f34 >= x0 && ((struct Obj01846 *)p)->f34 < x1
                && ((struct Obj01846 *)p)->f3C >= z0 && ((struct Obj01846 *)p)->f3C < z1)
                return i;
        }
    }
    return 0;
}









static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}









void func_0218D1D0(char *p, void *a, Cell_0218C518 *e)
{
    int r;
    int c;
    int idx;
    int col;
    u32 rows;
    u32 n;
    int base;
    u32 row;
    int y;
    int t;
    int s;

    n = ((struct Obj02687 *)p)->f14 * ((struct Obj02687 *)p)->f16;
    rows = ((struct Obj02687 *)p)->f18 / n;
    if (((struct Obj02687 *)p)->f18 % n != 0)
        rows++;
    s = ((struct Obj02687 *)p)->f4;
    base = func_0207C768(((struct Obj02687 *)p)->f4, 0x2000);
    idx = 0;
    t = ((struct Obj02687 *)p)->f8;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < n; col++) {
            y = FX_Mul(row << 12, t);
            c = col % ((struct Obj02687 *)p)->f14;
            r = col / ((struct Obj02687 *)p)->f14;
            if (idx >= ((struct Obj02687 *)p)->f18)
                idx = -1;
            func_0218DD80((u8 *)(e + idx), idx);
            func_0218DD9C(e + idx, base + FX_Mul(c << 12, s), y, base + FX_Mul(r << 12, s));
            idx++;
        }
    }
}







/*
 * Addresses are Black-image addresses.
 *
 * The inner loop is a guarded do-while: a plain for with y hoisted by the
 * compiler re-tests the bound after the preheader (extra cmp/ble).
 */
void func_0218D304(char *p, int *v, Cell_0218C518 *e){
    int coloff;
    int rowoff;
    int x;
    int y;
    int base;
    int s;
    int row;
    int h;
    int w;
    int col;
    int rr;
    int cc;
    int k;

    w = ((struct Obj01652 *)p)->f14;
    h = ((struct Obj01652 *)p)->f16;
    s = ((struct Obj01652 *)p)->f4;
    base = func_0207C768(((struct Obj01652 *)p)->f4, 0x2000);
    if (((struct Obj01652 *)p)->f2C % 2 == 0)
        coloff = func_0218D934(((struct Obj01652 *)p)->f2C, s, v[0]);
    else
        coloff = func_0218D970(((struct Obj01652 *)p)->f2C, s, v[0]);
    if (((struct Obj01652 *)p)->f2D % 2 == 0)
        rowoff = func_0218D934(((struct Obj01652 *)p)->f2D, s, v[2]);
    else
        rowoff = func_0218D970(((struct Obj01652 *)p)->f2D, s, v[2]);
    for (row = 0; row < ((struct Obj01652 *)p)->f2D; row++) {
        rr = rowoff + row;
        if (rr < 0 || rr >= h)
            continue;
        col = 0;
        if (col >= ((struct Obj01652 *)p)->f2C)
            continue;

        y = FX_Mul(rr << 12, s);
        do {
            cc = coloff + col;
            if (cc < 0 || cc >= w)
                continue;
            k = col + row * ((struct Obj01652 *)p)->f2C;
            func_0218DD80((u8 *)(e + k), cc + rr * w);
            x = FX_Mul(cc << 12, s);
            func_0218DD9C((e + k), base + x, 0, base + y);
        } while (++col < ((struct Obj01652 *)p)->f2C);
    }
}








/*
 * Addresses are Black-image addresses.
 *
 * The fx32 multiplies use a long long copy of the scale (ls) assigned in the
 * outer loop body: LICM hoists it as a 64-bit temporary, which reserves the
 * 8-byte frame slot whose low word is never stored. The outer loop is an
 * explicit guard plus do-while (a plain for duplicates the guard around the
 * hoisted block), and func_0207C768 re-reads p+4 instead of taking s, which
 * puts s below the hoisted m*w temporary.
 */
void func_0218D444(char *p, int *a, Cell_0218C518 *e){
    int k;
    Cell_0218C518 *el;
    int col;
    int base;
    int w;
    int y;
    int row;
    int c0;
    int r0;
    int cc;
    int rr;
    int h;
    long long ls;
    int s;
    int m;

    w = ((struct Obj02688 *)p)->f14;
    h = ((struct Obj02688 *)p)->f16;
    s = ((struct Obj02688 *)p)->f4;
    base = func_0207C768(((struct Obj02688 *)p)->f4, 0x2000);
    c0 = func_0218D980(((struct Obj02688 *)p)->f2C, s, a[0]);
    r0 = func_0218D980(((struct Obj02688 *)p)->f2D, s, a[2]);
    row = 0;
    if (row < ((struct Obj02688 *)p)->f2D) {
        do {
            ls = s;
            rr = r0 + row;
            m = rr % h;
            if (m < 0)
                m += h;
            for (col = 0; col < ((struct Obj02688 *)p)->f2C; col++) {
                y = (int)(((long long)(rr << 12) * ls + 0x800LL) >> 12);
                cc = c0 + col;
                k = cc % w;
                if (k < 0)
                    k += w;
                el = &e[col + row * ((struct Obj02688 *)p)->f2C];
                func_0218DD80((u8 *)el, k + m * w);
                func_0218DD9C(el, base + (int)(((long long)(cc << 12) * ls + 0x800LL) >> 12), 0, base + y);
            }
            row++;
        } while (row < ((struct Obj02688 *)p)->f2D);
    }
}











static inline s32 FX_MUL(s32 a, s32 b)
{
    return (s32)(((fx64)a * b + 0x800) >> 12);
}











/*
 * Fills the cell array for the two grid layers nearest the camera: the
 * layer containing cam->pos, then its neighbour on the side cam->pos leans
 * toward.  Each cell gets its table index (or -1 past the end) and its
 * centred position.  `size` is loaded into a local but FX_Div is passed the
 * field read, which keeps the hoisted sign-extension pair off size's slot
 * (see docs/idioms/an-unused-frame-word-under-a-sign-extension-spill-is-a-
 * field-passed-to-an-earlier-call.md).
 */
void func_0218D570(Obj_0218D570 *p, Cam *cam, Cell_0218C518 *cells)
{
    u32 layer;
    u32 total;
    s32 height;
    s32 half;
    s32 y;
    s32 size;
    u16 w;
    int row;
    int dir;
    int col;
    u32 rem;
    int i;
    u32 n;
    u32 id;

    w = p->w;
    total = w * p->h;
    size = p->size;
    half = (int)sub_0207C768((int)p->size, (int)0x2000);
    height = p->height;
    layer = (int)sub_0207C768((int)cam->pos, (int)height) >> 12;
    rem = cam->pos - layer * height;
    if (rem > height / 2)
        dir = 1;
    else
        dir = -1;

    n = 0;
    for (i = 0; i < total; i++, n++) {
        y = FX_MUL(layer << 12, height);
        col = i % p->w;
        row = i / p->w;
        id = layer * total + row * w + col;
        if (id >= p->count)
            id = -1;
        func_0218DD80((u8 *)(&cells[n]), id);
        (Cell_0218C518 *)func_0218DD9C(&cells[n], half + FX_MUL(col << 12, size), y, half + FX_MUL(row << 12, size));
    }
    for (i = 0; i < total; i++, n++) {
        y = FX_MUL((layer + dir) << 12, height);
        col = i % p->w;
        row = i / p->w;
        id = (layer + dir) * total + row * w + col;
        if (id >= p->count)
            id = -1;
        func_0218DD80((u8 *)(&cells[n]), id);
        (Cell_0218C518 *)func_0218DD9C(&cells[n], half + FX_MUL(col << 12, size), y, half + FX_MUL(row << 12, size));
    }
}












/*
 * Reconciles the grid object's live entries with a freshly laid-out cell
 * array (func_0218CA78's tail): entries whose id survives move to the new
 * position, the rest are hidden and released; new cells then take a free
 * entry.  Returns 1 when any free entry was claimed.
 */
int func_0218D7A8(Obj_0218D7A8 *p, Cell_0218C518 *nc)
{
    int placed;
    int moved;
    int changed;
    int ret;
    int i;
    int j;

    ret = 0;
    for (i = 0; i < p->n; i++) {
        if (func_0218DD84((u32)(&p->entries[i].cell))) {
            u32 id;
            moved = 0;
            id = func_0218DD98((u8 *)(&p->entries[i].cell));
            for (j = 0; j < p->n; j++) {
                if (id == func_0218DD98((u8 *)(&nc[j])) && !moved) {
                    Vec_0218D570 v;
                    func_0218DDA4(&nc[j], (Vec_0218D570 *)&v);
                    func_02169500((u8 *)p->entries[i].obj, (u8 *)(&v));
                    func_0218DD70((u32)(&nc[j]));
                    moved = 1;
                }
            }
            if (!moved) {
                func_0218DD70((u32)(&p->entries[i].cell));
                func_021694F8((u8 *)p->entries[i].obj, 0);
                func_0218B9FC(p->f64, p->entries[i].obj);
                func_0218DD4C((void **)p->entries[i].desc);
                func_021694D4(p->entries[i].obj);
            }
        }
    }
    changed = 0;
    for (i = 0; i < p->n; i++) {
        if (func_0218DD84((u32)(&nc[i]))) {
            placed = 0;
            for (j = 0; j < p->n; j++) {
                if (!func_0218DD84((u32)(&p->entries[j].cell)) && !placed) {
                    int obj = p->table[func_0218DD98((u8 *)(&nc[i]))];
                    Vec_0218D570 v;
                    func_0218DDA4(&nc[i], (Vec_0218D570 *)&v);
                    if (obj != -1) {
                        func_02169470((u8 *)p->entries[j].obj, (u32)obj);
                        func_02169500((u8 *)p->entries[j].obj, (u8 *)(&v));
                        func_021694F8((u8 *)p->entries[j].obj, 1);
                    }
                    p->entries[j].cell = nc[i];
                    placed = 1;
                    changed = 1;
                }
            }
        }
    }
    if (changed == 1)
        ret = 1;
    return ret;
}












int func_0218D934(u32 a, int b, int c)
{
    int r = -(int)((a >> 1) - 1);
    int q = c / b;
    if (c % b < (int)func_0207C768((int)b, (int)0x2000))
        r += q - 1;
    else
        r += q;
    return r;
}












int func_0218D970(u32 a, int b, int c)
{
    int r = -(int)(a >> 1);
    r += c / b;
    return r;
}












int func_0218D980(u32 a, int b, int c)
{
    int r = ((int)func_0207C768((int)c, (int)b) >> 12) - (a >> 1);
    if ((a & 1) == 0) {
        int m = func_0207C994(c, b);
        if ((int)func_0207C768((int)b, (int)0x2000) < m)
            r++;
    }
    return r;
}











int func_0218D9B8(u32 a)
{
((struct Obj05857 *)((u8 *)(a)))->f0 = 0;
((struct Obj05857 *)((u8 *)(a)))->f2 = 0;
((struct Obj05857 *)((u8 *)(a)))->f4 = 0;
((struct Obj05857 *)((u8 *)(a)))->f8 = 0;
((struct Obj05857 *)((u8 *)(a)))->fC = 0;
return a;
}











void func_0218D9C8(u8 *p)
{
    int i;
    for (i = 0; i < 16; i++)
        func_0218D9B8((u32)(p + i * 16));
    ((struct Obj19551 *)p)->f100 = 0;
}









int func_0218D9E8(char *p, int *pos, List *dst)
{
    int v[3];
    Hits buf;
    int h;
    int i;
    u32 n;

    if (((struct Obj02370 *)p)->f1C == 0)
        return 0;
    func_0218D9C8((unsigned char *)dst);
    n = 0;
    h = ((struct Obj02370 *)p)->f4 >> 1;
    for (i = 0; i < ((struct Obj02370 *)p)->f2E; i++) {
        if (func_021694FC((u8 *)(*(int *)(*(char * *)&((struct Obj02370 *)p)->f24 + i * 0x28))) == 1) {
            int x;
            int z;
            int x0;
            int x1;
            int z0;
            int z1;
            func_02169510((int)((u8 *)(*(int *)(*(char * *)&((struct Obj02370 *)p)->f24 + i * 0x28))), (Vec_0218C518 *)((struct V3_0218D570 *)v));
            x = v[0];
            z = v[2];
            x0 = x - h;
            z0 = z - h;
            x1 = x + h;
            z1 = z + h;
            if (pos[0] >= x0 && pos[0] < x1 && pos[2] >= z0 && pos[2] < z1) {
                u32 j;
                func_02169800(&buf, (char *)(*(int *)(*(char * *)&((struct Obj02370 *)p)->f24 + i * 0x28)), (u32)pos, ((struct Obj02370 *)p)->f4);
                if (buf.count != 0) {
                    if (n + buf.count >= 16)
                        break;
                    for (j = 0; j < buf.count; j++) {
                        dst->e[n + j].a = buf.e[j].a;
                        dst->e[n + j].b = buf.e[j].b;
                        dst->e[n + j].c = buf.e[j].c;
                        dst->e[n + j].d = buf.e[j].d;
                        dst->e[n + j].e = buf.e[j].e;
                    }
                    n += buf.count;
                }
            }
        }
    }
    dst->count = n;
    func_0218DDB4(p, pos, (char *)dst);
    if (dst->count != 0)
        return 1;
    return 0;
}








int func_0218DAEC(char *p, char *q, E_0218D570 *out)
{
    B_02189BBC b;
    int i;
    int best;
    int mn;

    func_0218D9B8((unsigned int)out);
    if (func_0218D9E8((char *)p, (int *)q, (List *)(&b)) == 0)
        return 0;
    if (b.n == 1) {
        *out = b.e[0];
        return 1;
    }
    best = 0;
    mn = 0x00FFF000;
    for (i = 0; i < b.n; i++) {
        if (func_021AB100(b.e[i].p)) {
            int d = b.e[i].q - ((struct Obj04201 *)q)->f4;
            if (d < 0)
                d = (int)(((long long)d * -4096LL + 0x800LL) >> 12);
            if (d < mn) {
                best = i;
                mn = d;
            }
        }
    }
    *out = b.e[best];
    return 1;
}








int func_0218DBAC(u8 *a, int idx, u32 c, u8 *d)
{
    u32 buf[0x41];
    func_02169848(buf, (u8 *)(*(u32 *)(*(u8 * *)&((struct Obj01846 *)a)->f24 + idx * 0x28)), c, ((struct Obj01846 *)a)->f4);
    ((struct Obj12585 *)d)->f8 = buf[2];
    ((struct Obj12585 *)d)->fC = buf[3];
    return 1;
}








int func_0218DBD4(char *p, int i)
{
    if (((struct Obj01846 *)p)->f1C == 0)
        return 0;
    if (func_021694FC((u8 *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28))) == 0)
        return 0;
    return func_021697E0((char *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28)));
}








/*
 * Unlabelled ov021 leaf (a `.word` run in the listing, no lr save), the
 * sole blocker of ov010 func_021638CC. Returns 1 (outside) unless the
 * grid is present, not in state 2, and pos.x/pos.z fall inside the
 * w*cell by d*cell rectangle.
 */
int func_0218DC04(Grid *g, VecFx32 *pos)
{
    s32 w;
    s32 d;

    if (g->f1C == 0)
        return 1;
    if (g->f0C == 2)
        return 0;
    w = g->f14 * g->f04;
    d = g->f16 * g->f04;
    if (pos->x >= 0 && pos->x < w && pos->z >= 0 && pos->z < d)
        return 0;
    return 1;
}








/*
 * Unlabelled leaf: copies the 12-byte vector at r1 into the object at +0x54.
 * Filed as the only blocker of ov052 func_021F38F0.
 */
void func_0218DC4C(char *o, V3_0218D570 *v)
{
    *(V3_0218D570 *)(o + 0x54) = *v;
}







void func_0218DC5C(u8 *a, Vec3 *b)
{
    *b = *(Vec3 *)(a + 0x54);
}







/*
 * Loads the 32-bit word at byte +0x64 of the object.
 */
u32 func_0218DC6C(u8 *p)
{
    return ((struct Obj17896 *)p)->f64;
}







/*
 * Loads the 32-bit word at byte +0x6c of the object.
 */
void *func_0218DC70(u8 *p)
{
    return ((struct Obj17897 *)p)->f6C;
}







int func_0218DC74(u32 a, u32 b, u32 c)
{
return func_02193B04(((struct Obj12063 *)((u8 *)(a)))->f6C, b, c, ((struct Obj12063 *)((u8 *)(a)))->f0);
}







int func_0218DC84(int a, int b, const int *q, int c){
    int x;
    int y;

    d_021DD9E0[1] = a;
    x = q[0];
    if (x == -1) {
        d_021DD9E0[0] = d_021DD9E0[0] & ~0xff;
    } else {
        d_021DD9E0[0] = (d_021DD9E0[0] & ~0xff) | 1;
        d_021DD9E0[3] = x;
    }
    y = q[1];
    if (y == -1) {
        d_021DD9E0[0] = d_021DD9E0[0] & 0xffff00ff;
    } else {
        d_021DD9E0[0] = (d_021DD9E0[0] & 0xffff00ff) | 0x100;
        d_021DD9E0[5] = y;
    }
    func_021A7360((const struct D *)g_021DD9E0, b, (u16)c);
}







/*
 * Tail-call thunk: forwards to func_0218DD5C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DCF4(u32 *a0)
{
    return func_0218DD5C(a0);
}







/*
 * Tail-call thunk: forwards to func_0218DD6C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DCFC(u32 *a0)
{
    return func_0218DD6C(a0);
}







/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
int func_0218DD04(u8 *p)
{
    return ((struct Obj17898 *)p)->f4;
}







/*
 * Unlabelled leaf accessor: returns the word at +0x8.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD08(u8 *p)
{
    return ((struct Obj19552 *)p)->f8;
}







/*
 * Unlabelled leaf accessor: returns the word at +0xC.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD0C(u8 *p)
{
    return ((struct Obj19553 *)p)->fC;
}







/*
 * Loads the 16-bit halfword at +0x10 of the object.
 */
u16 func_0218DD10(u8 *p)
{
    return ((struct Obj17899 *)p)->f10;
}







/*
 * Fills a 0x14-byte descriptor from src: word0 from func_021A7404(src+0x68, a),
 * then src+0x64/+0x6c, the argument a, and b as a halfword at +0x10.
 * Callee of func_0218CEE4.  EXACT* (unlabelled follower 0x0218DD38).
 */
void func_0218DD14(int *dst, char *src, int a, int b)
{
    dst[0] = func_021A7404((u8 *)(((struct Obj00165 *)src)->f68), a);
    dst[1] = ((struct Obj00165 *)src)->f64;
    dst[2] = ((struct Obj00165 *)src)->f6C;
    dst[3] = a;
    ((struct Obj05978 *)dst)->f10 = b;
}







void func_0218DD38(void **a)
{
    if (*a != 0) {
        func_021A7418(*a);
        *a = 0;
    }
}







void func_0218DD4C(void **a)
{
    if (*a != 0)
        func_021A7418(*a);
}









/*
 * Disasm reads its bytes as `.word` because it saves no lr; it is the
 * callee of the thunk at 0x0218DCF4.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD5C(u32 *p)
{
    return *p != 0;
}







/*
 * Unlabelled leaf getter (no lr save), callee of func_0218DCFC.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0218DD6C(u32 *p)
{
    return *p;
}







int func_0218DD70(u32 a){
((struct Obj07208 *)((u8 *)(a)))->f0 = (~0);
((struct Obj07208 *)((u8 *)(a)))->f4 = 0;
((struct Obj07208 *)((u8 *)(a)))->f8 = 0;
((struct Obj07208 *)((u8 *)(a)))->fC = 0;
return a;
}







/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void func_0218DD80(u8 *p, u32 v)
{
    ((struct Obj17902 *)p)->f0 = v;
}







int func_0218DD84(u32 a)
{
if (((struct Obj17903 *)((u8 *)(a)))->f0 != (~0)) {
    return 1;
}
return 0;
}







/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0218DD98(u8 *p)
{
    return ((struct Obj17904 *)p)->f0;
}







Cell_0218C518 *func_0218DD9C(Cell_0218C518 *a, int x, int y, int z)
{
    a->x = x;
    a->y = y;
    a->z = z;
    return a;
}







void func_0218DDA4(Cell_0218C518 *a, Vec_0218D570 *b)
{
    *b = *(Vec_0218D570 *)&a->x;
}







void func_0218DDB4(const char *p, int *q, char *r)
{
    S6 tmp = d_021D3DD4;
    int cnt = 0;
    int base = ((struct Obj03107 *)r)->f100;
    int n = func_021C0688((u8 *)(((struct Obj02370 *)p)->f70));
    int z;
    int x;
    int i;

    x = q[0] / 0x10000;
    z = q[2] / 0x10000;
    for (i = 0; i < n; i++) {
        if (func_021C068C(x, z, ((struct Obj02370 *)p)->f70, i)) {
            int k = base + ++cnt - 1;
            char *e;
            if (k >= 0x10)
                break;
            e = r + k * 16;
            *(S6 *)e = tmp;
            ((struct Obj12588 *)e)->f8 = func_021C06B4(i, ((struct Obj02370 *)p)->f70);
            ((struct Obj12588 *)e)->fC = func_021C06A8(i, ((struct Obj02370 *)p)->f70);
        }
    }
    ((struct Obj03107 *)r)->f100 += (u16)cnt;
}







void func_0218DE78(char *p)
{
    int v;

    func_02082BCC(((struct Obj01847 *)p)->f44, 0xff, ((struct Obj01847 *)p)->f2E);
    ((struct Obj01847 *)p)->f41 = 0;
    ((struct Obj01847 *)p)->f42 = ((struct Obj01847 *)p)->f43;
    ((struct Obj01847 *)p)->f43 = 0;
    ((struct Obj01847 *)p)->f4C = 0;
    if (*(volatile int *)0x02FFFC3C - ((struct Obj01847 *)p)->f50 >= 2) {
        ((struct Obj01847 *)p)->f4D = 0xff;
        ((struct Obj01847 *)p)->f48 = 0;
        return;
    }
    v = *(volatile u16 *)0x04000006;
    ((struct Obj01847 *)p)->f4D = v;
    if (v > 0xc0 || v <= 10) {
        ((struct Obj01847 *)p)->f48 = 0xf000;
        return;
    }
    ((struct Obj01847 *)p)->f48 = 0xf000 - ((v - 10) << 10);
}







void func_0218DEF0(char *p)
{
    ((struct Obj19554 *)p)->f50 = *(u32 *)0x02FFFC3C;
}







void func_0218DEFC(char *p, int o, int v)
{
    int a;
    int b;
    int t;
    int c;
    int i;

    if (func_02169598((u8 *)o) == 0)
        return;
    if (func_021694FC((u8 *)o) == 0)
        return;
    func_02169538((unsigned char *)o, &a);
    t = ((struct Obj02689 *)p)->f48 - a;
    for (i = ((struct Obj02689 *)p)->f41; i > 0; i--) {
        func_02169538((unsigned char *)(*(int *)(*(char * *)&((struct Obj02689 *)p)->f24 + *(u8 *)(((struct Obj02689 *)p)->f44 + i - 1) * 0x28)), &b);
        c = ((struct Obj02689 *)p)->f48 - b;
        if (c >= 0 && t >= c)
            break;
        if (t < 0)
            break;
        *(u8 *)(((struct Obj02689 *)p)->f44 + i) = *(u8 *)(((struct Obj02689 *)p)->f44 + i - 1);
    }
    *(u8 *)(((struct Obj02689 *)p)->f44 + i) = v;
    ((struct Obj02689 *)p)->f41 = ((struct Obj02689 *)p)->f41 + 1;
}







/*
 * Counts how many leading entries fit the width budget.
 *
 * Addresses are Black-image addresses.
 */
void func_0218DF80(u8 *a)
{
    int n;
    int i;
    int sum = 0;
    int w;

    ((struct Obj04990 *)a)->f4C = 0;
    n = ((struct Obj04990 *)a)->f42 - (((struct Obj04990 *)a)->f2E - ((struct Obj04990 *)a)->f40);
    if (n > 0) {
        for (i = 0; i < n; i++) {
            u8 *cnt = a + 0x4C;
            int idx = (*(u8 **)(a + 0x44))[i];
            if (idx == 0xFF) break;
            func_02169538((unsigned char *)(*(int *)(*(u8 * *)&((struct Obj04990 *)a)->f24 + idx * 0x28)), &w);
            sum += w;
            if (((struct Obj04990 *)a)->f48 < sum) break;
            *cnt = *cnt + 1;
        }
    }
}







int func_0218DFE0(u8 *a, u32 idx, int flag, u32 *out)
{
    u32 v = (*(u8 **)(a + 0x44))[idx];
    if (v == 0xff)
        return 0;
    *out = v;
    if (flag == 0) {
        if (idx < *(a + 0x4c))
            return 1;
    } else {
        if (idx >= *(a + 0x4c))
            return 1;
    }
    return 0;
}







char *func_0218E018(int a0, int a1, struct Light *a2, int a3, u16 heap)
{
    int t;
    char *p = func_02030734(heap, 0x1b0, 1, d_021DDA28, 0x80);
    ((struct Obj00519 *)p)->f10 = a0;
    ((struct Obj00519 *)p)->f14 = a1;
    ((struct Obj00519 *)p)->fC = (int)a2;
    ((struct Obj00519 *)p)->f20 = 0;
    ((struct Obj00519 *)p)->f0 = heap;
    ((struct Obj00519 *)p)->f24 = 0;
    ((struct Obj00519 *)p)->f28 = 0;
    ((struct Obj00519 *)p)->f2C = 0;
    ((struct Obj00519 *)p)->f48 = 0;
    ((struct Obj00519 *)p)->f4C = 0;
    ((struct Obj00519 *)p)->f50 = 0;
    ((struct Obj00519 *)p)->f6C = 0;
    ((struct Obj00519 *)p)->f70 = 0;
    ((struct Obj00519 *)p)->f74 = 0;
    ((struct Obj00519 *)p)->f30 = 0;
    ((struct Obj00519 *)p)->f34 = 0;
    ((struct Obj00519 *)p)->f38 = 0;
    ((struct Obj00519 *)p)->f7A = 0;
    ((struct Obj00519 *)p)->f78 = 0;
    ((struct Obj00519 *)p)->f7C = 0x78;
    ((struct Obj00519 *)p)->fE9 = 1;
    if (func_02048B78((struct Light *)a2) == 0) {
        func_02048B88(a2, (unsigned int *)(&t));
        ((struct Obj00519 *)p)->f80 = func_0207D184(t);
    }
    ((struct Obj00519 *)p)->f4 = func_020490F4(0x3c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->f8 = func_020490F4(0x6c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->fEA = 0xffff;
    func_0218E18C(p, (Vec *)a3);
    func_0218EEFC(7, 6, 2, heap, p);
    ((struct Obj00519 *)p)->f1AC = 0;
    return p;
}







void func_0218E0E4(u8 *a)
{
    func_02049238((void *)(((struct Obj04202 *)a)->f4));
    func_02049238((void *)(((struct Obj04202 *)a)->f8));
    func_0218EFD4(a);
    func_020307B0(a);
}







void func_0218E104(u8 *a, u32 b)
{
    void (*fp)(void *, u32) = *(void (**)(void *, u32))(a + 0x1ac);
    if (fp != 0)
        fp(a, ((struct Obj01653 *)a)->f1A8);
    func_0218E58C(a, b);
}







void func_0218E124(u8 *a, u32 s)
{
    ((struct Obj19556 *)a)->f14 = s;
    d_021DDA0C[s](a);
}







/*
 * Loads the 32-bit word at byte +0x14 of the object.
 */
u32 func_0218E138(u8 *p)
{
    return ((struct Obj17905 *)p)->f14;
}







void func_0218E13C(u8 *a, u32 s)
{
    if (((struct Obj19557 *)a)->f14 != s) {
        d_021DDA00[s](a);
        func_0218E124(a, s);
    }
}







int func_0218E160(u32 a)
{
func_0218E124((u8 *)a, 0);
func_0218E18C((char *)a, (Vec *)(((struct Obj01653 *)((u8 *)(a)))->f18));
*(u8 *)((u8 *)((a + 233))) = 1;
return 1;
}







/*
 * Stores the word at +0x10, then tail calls with both arguments.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E17C(u32 *p, u32 v)
{
    p[4] = v;
    func_0218E160((u32)p);
}







/*
 * Unlabelled leaf (ldr r0,[r0,#0x10]; bx lr), filed for lane S30 (callee of
 * func_021A2148).
 */
int func_0218E188(unsigned char *o)
{
    return ((struct Obj19558 *)o)->f10;
}







void func_0218E18C(char *p, Vec *src)
{
    Info info;

    func_0218E260(p, &info);
    ((struct Obj01347 *)p)->f7C = info.a << 12;
    ((struct Obj01347 *)p)->f78 = info.b;
    ((struct Obj01347 *)p)->f7A = info.c;
    ((struct Obj01347 *)p)->f80 = info.ang;
    func_0218EC7C((u8 *)p, info.g);
    func_0218EC68((u8 *)p, info.f);
    switch (info.mode) {
    case 0:
        func_02046BE0(0, 0);
        break;
    case 1:
        func_02046BE0(0, 1);
        break;
    }
    if (func_02048B78((struct Light *)(((struct Obj01347 *)p)->fC)) == 0) {
        func_02048B80((struct Light *)(((struct Obj01347 *)p)->fC), tbl_020A1B38[(((struct Obj01347 *)p)->f80 >> 4) * 2]);
        func_02048B94((struct Light *)(((struct Obj01347 *)p)->fC), tbl_020A1B38[(((struct Obj01347 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (info.has != 0) {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = src;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = src;
        *(Vec *)(p + 0x48) = *src;
        *(Vec *)(p + 0x60) = info.v;
    } else {
        *(Vec * *)&((struct Obj01347 *)p)->f18 = 0;
        *(Vec * *)&((struct Obj01347 *)p)->f1C = 0;
        *(Vec *)(p + 0x48) = info.v;
        ((Vec *)(p + 0x60))->x = 0;
        ((Vec *)(p + 0x60))->y = 0;
        ((Vec *)(p + 0x60))->z = 0;
    }
}







void func_0218E260(void *a, void *b)
{
func_020493D4((struct ArcFile *)(((struct Obj09175 *)((u8 *)(a)))->f4), 0);
func_0204944C((struct ArcFile *)((struct Obj09175 *)((u8 *)(a)))->f4, 0, (44 * ((struct Obj09175 *)((u8 *)(a)))->f10), 44, b);
}







void func_0218E284(u8 *a)
{
    Vec3 *p = *(Vec3 * *)&((struct Obj00428 *)a)->f1C;
    if (p != 0)
        *(Vec3 *)(a + 0x48) = *p;
}







int func_0218E298(u8 *a)
{
    Vec3 *p = *(Vec3 * *)&((struct Obj00428 *)a)->f20;
    if (p != 0) {
        *(Vec3 *)(a + 0x24) = *p;
        return 1;
    }
    return 0;
}







/*
 * Builds a vector from two sin/cos table rows (fx 20.12 products), normalises it and copies it out.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E2B4(V *a, V *out, int i, int j, int e)
{
    V v;
    int x, y;
    s16 p, q;
    int k;

    k = (i >> 4) * 2;
    x = d_020A1B38[k];
    y = d_020A1B38[k + 1];
    p = d_020A1B38[(j >> 4) * 2];
    q = d_020A1B38[(j >> 4) * 2 + 1];
    if (q < 0) q = -q;
    if (q < 0x200) q = 0x200;
    v.x = (int)(((long long)x * q + 0x800) >> 12);
    v.y = p;
    v.z = (int)(((long long)y * q + 0x800) >> 12);
    func_0207CCA4(&v, &v);
    func_0207CEE4(e, &v, a, &v);
    *out = v;
}







/*
 * Copies +0x48 to +0x54, updates 24-byte children, rebuilds +0x24 then copies it to +0x3c and updates children again.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E358(u8 *a)
{
    int i;

    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
    func_0218E2B4((V *)(a + 0x54), (V *)(a + 0x24), ((struct Obj00428 *)a)->f7A, ((struct Obj00428 *)a)->f78, ((struct Obj00428 *)a)->f7C);
    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
}







/*
 * Mirror of func_0218E358 with the two halves swapped.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E404(u8 *a)
{
    int i;

    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
    func_0218E2B4((V *)(a + 0x3C), (V *)(a + 0x48), ((struct Obj00428 *)a)->f7A, ((struct Obj00428 *)a)->f78, ((struct Obj00428 *)a)->f7C);
    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
}







/*
 * Copies +0x24 to +0x3c and +0x48 to +0x54, updating the children after each.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E4B0(u8 *a)
{
    int i;

    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
}







/*
 * Builds two 12-byte vectors from matrix pairs and pushes them to the owner.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E540(u8 *a)
{
    u8 t1[12];
    u8 t0[12];

    func_0207C9D0(a + 0x54, a + 0x60, t1);
    func_0207C9D0(a + 0x3C, a + 0x30, t0);
    func_02048B44(((struct Obj00428 *)a)->fC, t1);
    func_02048AFC(((struct Obj00428 *)a)->fC, t0);
    func_0218F004(a);
    func_0218E764(a, t1, a + 0x3C);
}




void func_0218E58C(u8 *a, u32 b)
{
    d_021D3E44[*(u32 *)(a + 0x14)](a, b);
}




void func_0218E5A0(u8 *a, u32 b)
{
func_0218E284(a);
func_0218E358(a);
func_0218E540(a);
}




void func_0218E5B8(u8 *a, u32 b)
{
func_0218E298(a);
func_0218E404(a);
func_0218E540(a);
}




void func_0218E5D0(u8 *a, u32 b)
{
func_0218E284(a);
func_0218E298(a);
func_0218E4B0(a);
func_0218E540(a);
}


/*
 * Hidden leaf setters of the func_0218E018 object (covered by no member).
 */
void func_0218E5EC(u8 *p)
{
    ((struct Obj00519 *)p)->f20 = 0;
}


void func_0218E5F4(u8 *p)
{
    *(int *)(p + 0x1C) = 0;
}


void func_0218E5FC(u8 *p)
{
    ((struct Obj00519 *)p)->f78 = 0;
    ((struct Obj00519 *)p)->f7A = 0;
    ((struct Obj00519 *)p)->f7C = 0;
}










/*
 * Converts a vector to two 16-bit angles plus its length.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E610(void *a, u16 *b, u16 *c, int *d)
{
    V v;
    V w;
    u16 h[2];
    int len;

    len = func_0207CBD0(a);
    func_0207CCA4(a, &v);
    w.x = v.x;
    w.y = 0;
    w.z = v.z;
    h[1] = func_0207CFB8(v.y, func_0207CBD0(&w));
    h[0] = func_0207CFB8(v.x, v.z);
    func_0218E7DC(&v, h[0], h[1], h, &h[1]);
    *b = h[1];
    *c = h[0];
    *d = len;
}










void func_0218E674(u8 *a, u32 b)
{
    struct { u16 y, x; u32 z; } t;
    func_0218E610((void *)b, &t.x, &t.y, (int *)(&t.z));
    ((struct Obj01848 *)a)->f78 = t.x;
    ((struct Obj01848 *)a)->f7A = t.y;
    ((struct Obj01848 *)a)->f7C = t.z;
}










/*
 * Toggles a half-turn offset or converts a matrix pair to angles (mode 1).
 *
 * Addresses are Black-image addresses.
 */
void func_0218E6A4(u8 *a)
{
    u8 tmp[12];

    if (((struct Obj01848 *)a)->f14 == 1) {
        ((struct Obj01848 *)a)->f7A = ((struct Obj01848 *)a)->f7A + 0x8000;
        ((struct Obj01848 *)a)->f78 = ((struct Obj01848 *)a)->f78 + 0x8000;
    } else {
        func_0207CA00(a + 0x24, a + 0x54, tmp);
        func_0218E674(a, (u32)tmp);
    }
}










/*
 * Twin of func_0218E6A4 with mode 0 and the other matrix pair.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E6F0(u8 *a)
{
    u8 tmp[12];

    if (((struct Obj01848 *)a)->f14 == 0) {
        ((struct Obj01848 *)a)->f7A = ((struct Obj01848 *)a)->f7A + 0x8000;
        ((struct Obj01848 *)a)->f78 = ((struct Obj01848 *)a)->f78 + 0x8000;
    } else {
        func_0207CA00(a + 0x48, a + 0x3C, tmp);
        func_0218E674(a, (u32)tmp);
    }
}










void func_0218E73C(u8 *a)
{
    u32 s = ((struct Obj00428 *)a)->f14;
    if (s == 0) {
        func_0218E284(a);
        func_0218E358(a);
    } else if (s == 1) {
        func_0218E298(a);
        func_0218E404(a);
    }
}










/*
 * Derives two 16-bit angles from a matrix and stores them at +0x82/+0x84.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E764(u8 *a, void *b, void *c)
{
    V v;
    V k;
    V w;
    int r, t;
    int s;

    func_0207CA00(c, b, &v);
    func_0207CCA4(&v, &v);
    ((struct Obj00428 *)a)->f82 = func_0207CFB8(v.x, v.z);
    k = d_021D3E2C;
    r = func_0207CA68(&k, &v);
    w = v;
    s = 0;
    w.y = 0;
    func_0207CCA4(&w, &w);
    t = func_0207CA68(&w, &v);
    if (t != 0) {
        s = func_0207CFB8(r, t);
    }
    ((struct Obj00428 *)a)->f84 = s;
}










static inline int FXM(int a, int b)
{
    return (int)(((long long)a * b + 0x800) >> 12);
}










/*
 * Refines two 16-bit angles (yaw h0, pitch h1) toward a target vector: builds the unit
 * direction for the current angles and for yaw +/- one degree (0xb6), then nudges each
 * angle by a linear interpolation per quadrant. Writes the results to p0/p1.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E7DC(V *v, u16 h0, u16 h1, u16 *p0, u16 *p1)
{
    VS c = {0, 0, 0};
    VS b = {0, 0, 0};
    VS a = {0, 0, 0};
    int c1;
    int sb, sa;
    int k0, k1, kb, ka;

    *p0 = h0;
    *p1 = h1;

    k0 = (h0 >> 4) * 2;
    k1 = (h1 >> 4) * 2;
    c1 = d_020A1B38[k1 + 1];
    c.x = FXM(d_020A1B38[k0], c1);
    c.y = d_020A1B38[k1];
    c.z = FXM(d_020A1B38[k0 + 1], c1);
    kb = ((h0 - 0xb6) >> 4) * 2;
    b.x = FXM(d_020A1B38[kb], c1);
    b.z = FXM(d_020A1B38[kb + 1], c1);
    sb = d_020A1B38[((h1 - 0xb6) >> 4) * 2];
    ka = ((h0 + 0xb6) >> 4) * 2;
    a.x = FXM(d_020A1B38[ka], c1);
    a.z = FXM(d_020A1B38[ka + 1], c1);
    sa = d_020A1B38[((h1 + 0xb6) >> 4) * 2];

    if (h0 < 0x4000) {
        if (c.x < v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (v->x - c.x) / (b.x - c.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (c.z - v->z) / (c.z - b.z));
            }
        } else if (c.x > v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (c.x - v->x) / (c.x - a.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (v->z - c.z) / (a.z - c.z));
            }
        }
    } else if (h0 < 0x8000) {
        if (c.x > v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (c.x - v->x) / (c.x - b.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (c.z - v->z) / (c.z - b.z));
            }
        } else if (c.x < v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (v->x - c.x) / (a.x - c.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (v->z - c.z) / (a.z - c.z));
            }
        }
    } else if (h0 < 0xC000) {
        if (c.x > v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (c.x - v->x) / (c.x - b.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (v->z - c.z) / (b.z - c.z));
            }
        } else if (c.x < v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (v->x - c.x) / (a.x - c.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (c.z - v->z) / (c.z - a.z));
            }
        }
    } else {
        if (c.x < v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (v->x - c.x) / (b.x - c.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (v->z - c.z) / (b.z - c.z));
            }
        } else if (c.x > v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (c.x - v->x) / (c.x - a.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (c.z - v->z) / (c.z - a.z));
            }
        }
    }

    if (h1 < 0x4000) {
        if (c.y > v->y) {
            h1 = h1 - (u16)(0xb6 * (c.y - v->y) / (c.y - sb));
        } else if (c.y < v->y) {
            h1 = h1 + (u16)(0xb6 * (v->y - c.y) / (sa - c.y));
        }
    } else if (h1 >= 0xC000) {
        if (c.y > v->y) {
            h1 = h1 - (u16)(0xb6 * (c.y - v->y) / (c.y - sb));
        } else if (c.y < v->y) {
            h1 = h1 + (u16)(0xb6 * (v->y - c.y) / (sa - c.y));
        }
    }

    *p0 = h0;
    *p1 = h1;
}










/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_0218EC2C(u8 *p)
{
    return ((struct Obj17906 *)p)->fC;
}











void func_0218EC30(u8 *a, const Vec3_0218EC30 *p)
{
    *(const Vec3_0218EC30 * *)&((struct Obj01653 *)a)->f1C = p;
    *(Vec3_0218EC30 *)(a + 0x6c) = *p;
    *(Vec3_0218EC30 *)(a + 0x48) = *p;
}











/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_0218EC54(u8 *p)
{
    ((struct Obj17907 *)p)->f1C = 0;
}











/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
u32 func_0218EC5C(u8 *p)
{
    return ((struct Obj17908 *)p)->f1C;
}











int func_0218EC60(u32 a)
{
*(u32 *)&((struct Obj01653 *)((u8 *)(a)))->f1C = ((struct Obj01653 *)((u8 *)(a)))->f18;
return a;
}











void func_0218EC68(u8 *a, u32 first, ...)
{
    func_02048B60((struct Light *)(((struct Obj19562 *)a)->fC), &first);
}











void func_0218EC7C(u8 *a, u32 first, ...)
{
    func_02048B6C((struct Light *)(((struct Obj19563 *)a)->fC), &first);
}











void func_0218EC90(u8 *a, const Vec3_0218EC90 *p)
{
    *(Vec3_0218EC90 *)(a + 0x48) = *p;
    *(Vec3_0218EC90 *)(a + 0x6c) = *p;
}











void func_0218ECB4(u8 *a, Vec3_0218ECB4 *out)
{
    *out = *(Vec3_0218ECB4 *)(a + 0x48);
}











void func_0218ECC4(u8 *a, Vec3_0218ECC4 *out)
{
    *out = *(Vec3_0218ECC4 *)(a + 0x60);
}











void func_0218ECD4(u8 *a, const Vec3_0218ECD4 *p)
{
    *(Vec3_0218ECD4 *)(a + 0x60) = *p;
}











void func_0218ECE4(u8 *a, Vec3_0218ECE4 *out)
{
    *out = *(Vec3_0218ECE4 *)(a + 0x24);
}











void func_0218ECF4(u8 *a, const Vec3_0218ECF4 *p)
{
    *(Vec3_0218ECF4 *)(a + 0x24) = *p;
}











/*
 * Unlabelled leaf: copies a 12-byte vector into field 0x30 (setter twin of
 * func_0218ECF4 at 0x24). Blocker leaf of func_021D2D7C.
 */
void func_0218ED04(u8 *p, const Vec_0218ED04 *v)
{
    *(Vec_0218ED04 *)(p + 0x30) = *v;
}











/*
 * Unlabelled tail-call leaf: forwards field 0xc and the second argument.
 */
void func_0218ED14(u8 *p, u32 q)
{
    func_02048B20(((struct Obj19564 *)p)->fC, q);
}











/*
 * Unlabelled tail-call leaf: forwards the handle at +0xc to func_02048B0C.
 * Filed as the only unmatched callee of ov056 func_021F392C.
 */
void func_0218ED20(void *p, void *out)
{
    func_02048B0C(((struct Obj19565 *)p)->fC, out);
}











/*
 * Loads the halfword at byte +0x78 of the object.
 */
u16 func_0218ED2C(u8 *p)
{
    return ((struct Obj17909 *)p)->f78;
}











/*
 * Field setter at +0x78 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_0218ED34(u8 *p, u16 v)
{
    ((struct Obj17910 *)p)->f78 = v;
}











/*
 * Returns the object pointer advanced by 0x84 bytes.
 */
u8 *func_0218ED3C(u8 *p)
{
    return p + 0x84;
}











/*
 * Loads the halfword at byte +0x7a of the object.
 */
u16 func_0218ED40(u8 *p)
{
    return ((struct Obj17911 *)p)->f7A;
}











/*
 * Field setter at +0x7a through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_0218ED48(u8 *p, u32 v)
{
    ((struct Obj17912 *)p)->f7A = v;
}











/*
 * Returns the object pointer advanced by 0x82 bytes.
 */
u8 *func_0218ED50(u8 *p)
{
    return p + 0x82;
}











/*
 * Loads the 32-bit word at byte +0x7c of the object.
 */
u32 func_0218ED54(u8 *p)
{
    return ((struct Obj17913 *)p)->f7C;
}











void func_0218ED58(u8 *p, u32 v)
{
    ((struct Obj17914 *)p)->f7C = v;
}











void func_0218ED5C(void *a, u16 *b, u16 *c, int *d)
{
    func_0218E610(a, b, c, d);
}











void func_0218ED64(u8 *a, u16 angle)
{
    ((struct Obj05979 *)a)->f80 = angle;
    func_02048B80((struct Light *)(((struct Obj05979 *)a)->fC), FX_SinCosTable_[(((struct Obj05979 *)a)->f80 >> 4) * 2]);
    func_02048B94((struct Light *)(((struct Obj05979 *)a)->fC), FX_SinCosTable_[(((struct Obj05979 *)a)->f80 >> 4) * 2 + 1]);
}











void func_0218ED9C(Delay *d, Vec_0218ED9C *inA, Vec_0218ED9C *inB, Vec_0218ED9C *outA, Vec_0218ED9C *outB)
{
    int rd;
    int wr;

    if (d == 0) {
        *outA = *inA;
        *outB = *inB;
        return;
    }
    if (d->on == 0) {
        *outA = *inA;
        *outB = *inB;
        return;
    }
    rd = d->rd;
    wr = d->wr;
    if (d->hold == 0) {
        d->a[wr] = *inA;
        d->b[wr] = *inB;
        wr = (wr + 1) % d->n;
    }
    if (d->full != 0) {
        *outA = d->a[rd];
        *outB = d->b[rd];
    } else {
        *outA = d->a[d->delay];
        *outB = d->b[d->delay];
        if (rd == d->delay)
            d->full = 1;
    }
    if (d->hold != 0) {
        if (rd != wr) {
            rd = (rd + 1) % d->n;
            if (rd == wr)
                func_0218F050((u32)d);
        }
    } else {
        rd = (rd + 1) % d->n;
    }
    d->rd = rd;
    d->wr = wr;
    if (d->keepX == 0) {
        outA->x = inA->x;
        outB->x = inB->x;
    }
    if (d->keepY == 0) {
        outA->y = inA->y;
        outB->y = inB->y;
    }
    if (d->keepZ == 0) {
        outA->z = inA->z;
        outB->z = inB->z;
    }
}











/*
 * The fifth (stack) parameter is a void pointer reassigned to the address of
 * its +0xec slot before the store: the cast keeps it a live variable homed in
 * its own parameter slot (entry write-back, end adds/str).
 */
void func_0218EEFC(int n, u32 x, u32 flags, u32 heap, void *a)
{
    if (((struct Obj12593 *)a)->f1C != 0) {
        int i = 0;
        Track *t = func_02030734(heap, sizeof(Track), 0, d_021DDA28, 0x6aa);
        t->bufA = func_02030734(heap, n * sizeof(Vec3_0218EEFC), 0, d_021DDA28, 0x6ab);
        t->bufB = func_02030734(heap, n * sizeof(Vec3_0218EEFC), 0, d_021DDA28, 0x6ac);
        for (; i < n; i++) {
            Vec3_0218EEFC *v = &t->bufA[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
            v = &t->bufB[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
        }
        t->count = n;
        t->unk0C = x;
        t->unk10 = 0;
        t->unk04 = 0;
        t->unk08 = x;
        t->flag1 = 0;
        t->flag2 = 0;
        t->flag4 = 0;
        if (flags & 1)
            t->flag1 = 1;
        if (flags & 2)
            t->flag2 = 1;
        if (flags & 4)
            t->flag4 = 1;
        t->unk28 = 1;
        t->unk2C = 0;
        a = (u8 *)a + 0xec;
        *(Track * *)&((struct Obj12593 *)a)->f0 = t;
    }
}











void func_0218EFD4(u8 *a)
{
    if (*(u8 * *)&((struct Obj04202 *)a)->fEC != 0) {
        func_020307B0(((struct Obj19566 *)(*(u8 * *)&((struct Obj04202 *)a)->fEC))->f20);
        func_020307B0(((struct Obj19567 *)(*(u8 * *)&((struct Obj04202 *)a)->fEC))->f24);
        func_020307B0(((struct Obj04202 *)a)->fEC);
        ((struct Obj04202 *)a)->fEC = 0;
    }
}













/*
 * Fetches three vectors from the owner, calls the solver, writes two back.
 *
 * Addresses are Black-image addresses.
 */
void func_0218F004(u8 *a)
{
    if (*(int *)&((struct Obj00428 *)a)->f1C != 0) {
        u8 d[12];
        u8 v[12];
        u8 c[12];
        u8 b[12];

        func_02048B30(((struct Obj00428 *)a)->fC, v);
        func_02048AE8(((struct Obj00428 *)a)->fC, d);
        func_0218ED9C((Delay *)(((struct Obj00428 *)a)->fEC), (Vec_0218ED9C *)v, (Vec_0218ED9C *)d, (Vec_0218ED9C *)b, (Vec_0218ED9C *)c);
        func_02048B44(((struct Obj00428 *)a)->fC, b);
        func_02048AFC(((struct Obj00428 *)a)->fC, c);
    }
}













int func_0218F050(u32 a)
{
((struct Obj00612 *)((u8 *)(a)))->f2C = 0;
((struct Obj00612 *)((u8 *)(a)))->f28 = 0;
((struct Obj00612 *)((u8 *)(a)))->f10 = 0;
return a;
}













/*
 * Resets a table object's two entry arrays (12-byte entries) and cursors.
 *
 * Addresses are Black-image addresses.
 */
void func_0218F05C(unsigned char *a)
{
    int *p = *(int * *)&((struct Obj01653 *)a)->fEC;
    int i;

    if (p != 0) {
        for (i = 0; i < p[0]; i++) {
            int *e = (int *)((unsigned char *)p[8] + i * 12);
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
            e = (int *)((unsigned char *)p[9] + i * 12);
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
        }
        p[1] = 0;
        p[2] = p[3];
        p[4] = 0;
        p[10] = 1;
        p[11] = 0;
    }
}













void func_0218F0A8(u8 *a)
{
    u8 *p = *(u8 * *)&((struct Obj01653 *)a)->fEC;
    if (p != 0) {
        if (((struct Obj00612 *)p)->f10 == 0 && *(u32 *)&((struct Obj00612 *)p)->f8 == *(u32 *)&((struct Obj00612 *)p)->fC && *(u32 *)&((struct Obj00612 *)p)->f4 == 0)
            func_0218F050((u32)p);
        else
            ((struct Obj00612 *)p)->f2C = 1;
    }
}













void func_0218F0D4(u8 *a, int b)
{
    u8 *p = *(u8 * *)&((struct Obj19568 *)a)->fEC;
    if (p != 0) {
        ((struct Obj09464 *)p)->f2C = 0;
        ((struct Obj09464 *)p)->f28 = 0;
        ((struct Obj09464 *)p)->f10 = 0;
    }
}













u32 func_0218F0E8(u8 *a)
{
    u8 *p = *(u8 * *)&((struct Obj01653 *)a)->fEC;
    if (p == 0)
        return 0;
    return ((struct Obj19569 *)p)->f28;
}













int func_0218F0F8(u8 *a)
{
    if (*(u32 *)&((struct Obj01653 *)a)->f1C == 0)
        return 0;
    if (*(u32 *)&((struct Obj01653 *)a)->fEC != 0)
        return 1;
    return 0;
}













/*
 * Copies 0x18 * count bytes (count = *(int *)(arg1)) from arg0+0x88 to
 * arg1+4, then stores the low byte of count at arg0+0xe8.  Callee of
 * func_0218F14C.  EXACT* (unlabelled follower 0x0218F134).
 */
void func_0218F114(char *arg0, char *arg1)
{
    func_02082D44(arg1 + 4, arg0 + 0x88, 0x18 * ((struct Obj12594 *)arg1)->f0);
    ((struct Obj19570 *)arg0)->fE8 = ((struct Obj12594 *)arg1)->f0;
}













void func_0218F134(u8 *a)
{
    func_02082BCC(a + 0x88, 0, 0x60);
    *(a + 0xe8) = 0;
}













void func_0218F14C(u8 *p, u32 a, u32 b)
{
    u32 r;
    if (((struct Obj09465 *)p)->fEA != a) {
        r = (u32)func_0204A380((void *)(((struct Obj09465 *)p)->f8), a, 0, (u16)((b & 0x7fff) | 0x8000));
        func_0218F114((char *)p, (char *)r);
        func_020307B0((void *)r);
        ((struct Obj09465 *)p)->fEA = a;
    }
}













void func_0218F18C(u8 *a, Vec3 *out)
{
    *out = *(Vec3 *)(a + 0x54);
}













void func_0218F19C(u8 *a, Vec3 *out)
{
    *out = *(Vec3 *)(a + 0x3c);
}













/*
 * Field setter at +0xe9 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_0218F1AC(u8 *p, u32 v)
{
    ((struct Obj17915 *)p)->fE9 = v;
}













/*
 * Loads the byte at byte +0xe9 of the object.
 */
u8 func_0218F1B4(u8 *p)
{
    return ((struct Obj17916 *)p)->fE9;
}













void func_0218F1BC(u32 *a, u32 b)
{
    if (a[1] == 0) {
        Handler fp = d_021DDA18[a[0]];
        if (fp != 0)
            fp(a, b, b);
    }
}













void func_0218F1DC(u32 *a, u32 b)
{
    if (a[1] == 1) {
        Handler fp = d_021DDA18[a[0]];
        if (fp != 0)
            fp(a, b, b);
    }
}













/*
 * Clamps a point into the box [+8,+0xc] x [+0x10,+0x14] (whole units,
 * converted to fx32); returns 1 when it moved.  Same box as func_0218F460.
 */
int func_0218F1FC(const Box *a, V *b, V *out)
{
    V p;
    int r;

    p = *b;
    r = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(a->x0) > p.x) {
        r = 1;
        out->x = FX_F32_TO_FX32(a->x0);
    } else if (a->x1 * 4096 < p.x) {
        r = 1;
        out->x = FX_F32_TO_FX32(a->x1);
    }
    if (a->z0 * 4096 > p.z) {
        r = 1;
        out->z = FX_F32_TO_FX32(a->z0);
    } else if (a->z1 * 4096 < p.z) {
        r = 1;
        out->z = FX_F32_TO_FX32(a->z1);
    }
    return r;
}













/*
 * Clamps a point to a ring sector around the centre at +8/+0xc: radius
 * capped at +0x10, angle clamped to [+0x16, +0x14]; returns 1 when clamped.
 * `const` on a lets the a->cz load schedule above the c.y = 0 store
 * (docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md);
 * the table entry read into an s16 local puts it in r0:r1 of _ll_mul, and
 * `r = 1` repeated in both inner arms gives the cross-jumped clamp blocks.
 *
 * Addresses are Black-image addresses.
 */
int func_0218F310(const Ring *a, V *b, V *out)
{
    V k;
    V c;
    V d;
    V e;
    V n;
    V x;
    int m;
    int r;
    u16 ang;
    u16 lo, hi;
    int d1, d2;
    int i;
    s16 s;

    k = d_021D3E38;
    c = *b;
    d = *b;
    out->x = b->x;
    out->y = b->y;
    out->z = b->z;
    e.x = a->cx;
    e.y = 0;
    r = 0;
    c.y = 0;
    e.z = a->cz;
    VEC_Subtract(&c, &e, &n);
    m = VEC_Mag(&n);
    if (FX_Modf(m, &m) > 0) {
        m += 0x1000;
    }
    VEC_Normalize(&n, &n);
    VEC_CrossProduct(&k, &n, &x);
    ang = FX_AcosIdx(VEC_DotProduct(&k, &n));
    if (x.y < 0) {
        ang = 0x10000 - ang;
    }
    if (m > a->rmax) {
        m = a->rmax;
        r = 1;
    }
    lo = a->amin;
    hi = a->amax;
    if (hi != lo) {
        if (hi > lo) {
            if (lo < ang && hi >= ang) {
                d1 = hi - ang;
                if (d1 < 0) d1 = -d1;
                d2 = lo - ang;
                if (d2 < 0) d2 = -d2;
                if (d2 > d1) {
                    ang = hi;
                    r = 1;
                } else {
                    ang = lo;
                    r = 1;
                }
            }
        } else if (hi > ang) {
            ang = hi;
            r = 1;
        } else if (lo < ang) {
            ang = lo;
            r = 1;
        }
    }
    if (r != 0) {
        i = (ang >> 4) * 2;
        s = d_020A1B38[i];
        out->x = e.x + (int)(((long long)s * m + 0x800) >> 12);
        s = d_020A1B38[i + 1];
        out->z = e.z + (int)(((long long)s * m + 0x800) >> 12);
        out->y = d.y;
    }
    return r;
}













/*
 * Pushes a point inside the box [+8,+0xc] x [+0x10,+0x14] (whole units,
 * converted to fx32) out through the nearest side; returns 1 when it moved.
 * Reading p.z directly (no named local) is what puts its CSE slot below the
 * a->x0 temp.
 *
 * Addresses are Black-image addresses.
 */
int func_0218F460(Box *a, V *b, V *out)
{
    V p;
    int r;
    int best;
    int side;

    p = *b;
    r = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(a->x0) < p.x && FX_F32_TO_FX32(a->x1) > p.x &&
        FX_F32_TO_FX32(a->z0) < p.z && FX_F32_TO_FX32(a->z1) > p.z) {
        r = 1;
        best = out->x - FX_F32_TO_FX32(a->x0);
        side = 0;
        if (best > FX_F32_TO_FX32(a->x1) - out->x) {
            best = FX_F32_TO_FX32(a->x1) - out->x;
            side = 1;
        }
        if (best > out->z - FX_F32_TO_FX32(a->z0)) {
            best = out->z - FX_F32_TO_FX32(a->z0);
            side = 2;
        }
        if (best > FX_F32_TO_FX32(a->z1) - out->z) {
            best = FX_F32_TO_FX32(a->z1) - out->z;
            side = 3;
        }
        switch (side) {
        case 0:
            out->x = FX_F32_TO_FX32(a->x0);
            break;
        case 1:
            out->x = FX_F32_TO_FX32(a->x1);
            break;
        case 2:
            out->z = FX_F32_TO_FX32(a->z0);
            break;
        case 3:
            out->z = FX_F32_TO_FX32(a->z1);
            break;
        }
    }
    return r;
}













void func_0218F780(u8 *s, u8 *d)
{
    *(V3_0218E610 *)(d + 0)    = *(V3_0218E610 *)(s + 0x24);
    *(V3_0218E610 *)(d + 0xc)  = *(V3_0218E610 *)(s + 0x48);
    ((struct Obj07419 *)d)->f24 = ((struct Obj02371 *)s)->f78;
    ((struct Obj07419 *)d)->f26 = ((struct Obj02371 *)s)->f7A;
    ((struct Obj07419 *)d)->f28 = ((struct Obj02371 *)s)->f7C;
    ((struct Obj07419 *)d)->f2C = ((struct Obj02371 *)s)->f80;
    *(V3_0218E610 *)(d + 0x18) = *(V3_0218E610 *)(s + 0x60);
}













void func_0218F7D0(u8 *s, u8 *d)
{
    *(V3_0218E610 *)(d + 0) = *(V3_0218E610 *)(s + 0x24);
    func_0218F18C((u8 *)s, (Vec3 *)(d + 0xc));
    ((struct Obj07420 *)d)->f24 = ((struct Obj02371 *)s)->f78;
    ((struct Obj07420 *)d)->f26 = ((struct Obj02371 *)s)->f7A;
    ((struct Obj07420 *)d)->f28 = ((struct Obj02371 *)s)->f7C;
    ((struct Obj07420 *)d)->f2C = ((struct Obj02371 *)s)->f80;
    *(V3_0218E610 *)(d + 0x18) = *(V3_0218E610 *)(s + 0x60);
}












void func_0218F818(u8 *a)
{
    if (a != 0) {
        Sub_0218E610 *s = (Sub_0218E610 *)(a + 0xf0);
        if (s->active == 0) {
            s->saved = ((struct Obj02371 *)a)->f14;
            func_0218E13C(a, 0);
            func_0218F780(a, s->body);
            s->active = 1;
        }
    }
}












void func_0218F848(u8 *a)
{
    if (a != 0) {
        Sub_0218E610 *s = (Sub_0218E610 *)(a + 0xf0);
        if (s->active == 0) {
            s->saved = ((struct Obj02371 *)a)->f14;
            func_0218E13C(a, 0);
            func_0218F7D0(a, s->body);
            s->active = 1;
        }
    }
}












void func_0218F878(u8 *a)
{
    if (a != 0) {
        Sub_0218E610 *s = (Sub_0218E610 *)(a + 0xf0);
        if (s->active != 0) {
            func_0218E13C(a, s->saved);
            s->active = 0;
        }
    }
}












void func_0218F89C(u8 *p, u8 *src, u16 v)
{
    u8 *q;
    if (p) {
        q = p + 0xf0;
        func_0218E13C(p, 0);
        *(B48 *)(q + 0x64) = *(B48 *)src;
        ((struct Obj07423 *)q)->f96 = 0;
        ((struct Obj07423 *)q)->f94 = v;
        *(B24 *)(q + 0xa0) = *(B24 *)(src + 0x30);
        ((struct Obj02371 *)p)->f1AC = (void *)func_0218FB1C;
        ((struct Obj07423 *)q)->fB8 = 0;
        ((struct Obj07423 *)q)->f9C = 1;
    }
}











void func_0218F900(u8 *a, u8 *p, u16 n)
{
    if (a != 0) {
        func_0218F89C(a, p, n);
        func_0218F780(a, a + 0x124);
    }
}











void func_0218F918(u8 *a, u8 *p, u16 n)
{
    if (a != 0) {
        func_0218F89C(a, p, n);
        func_0218F7D0(a, a + 0x124);
    }
}











void func_0218F930(u8 *p, u8 *a, u8 *b, u32 *c, u16 v)
{
    u8 *q;
    B24 loc;
    if (p) {
        q = p + 0xf0;
        func_0218E13C(p, 2);
        func_0218F780(p, q + 0x34);
        *(B12 *)(q + 0x64) = *(B12 *)a;
        *(B12 *)(q + 0x70) = *(B12 *)b;
        ((struct Obj07424 *)q)->f96 = 0;
        ((struct Obj07424 *)q)->f94 = v;
        loc.w[5] = c[5];
        loc.w[1] = 0;
        loc.w[4] = c[4];
        loc.w[2] = 0;
        loc.w[3] = 0;
        loc.w[0] = c[0];
        *(B24 *)(q + 0xa0) = loc;
        ((struct Obj19572 *)p)->f1AC = (void *)func_0218FC80;
        ((struct Obj07424 *)q)->fB8 = 0;
        ((struct Obj07424 *)q)->f9C = 1;
    }
}











void func_0218F9C4(u8 *p, u8 *src, u16 v)
{
    u8 *q;
    if (p) {
        q = p + 0xf0;
        if (((struct Obj05980 *)q)->f98 != 0 && v != 0) {
            func_0218E13C(p, 0);
            func_0218F780(p, q + 0x34);
            *(B48 *)(q + 0x64) = *(B48 *)(q + 4);
            ((struct Obj05980 *)q)->f96 = 0;
            ((struct Obj05980 *)q)->f94 = v;
            *(B24 *)(q + 0xa0) = *(B24 *)src;
            ((struct Obj01653 *)p)->f1AC = (void *)func_0218FB1C;
            ((struct Obj05980 *)q)->fB8 = 0;
            ((struct Obj05980 *)q)->f9C = 1;
        }
    }
}











/*
 * Sibling of func_0218F9C4/func_0218F930: arms the +0xf0 motion block with
 * func_0218FB1C as the per-frame callback, seeded from func_0218E260's record.
 * The two +0x70 copies are tail-merged by the compiler (a shared source
 * pointer variable compiles the same).
 *
 * Addresses are Black-image addresses.
 */
void func_0218FA40(u8 *p, u16 v)
{
    u8 *q;
    Rec loc;

    if (p) {
        q = p + 0xf0;
        if (((struct Obj01117 *)q)->f98 != 0 && v != 0) {
            func_0218E13C(p, 0);
            func_0218F780(p, q + 0x34);
            func_0218E260(p, &loc);
            ((struct Obj01117 *)q)->f88 = loc.b;
            ((struct Obj01117 *)q)->f8A = loc.c;
            ((struct Obj01117 *)q)->f8C = loc.a << 12;
            ((struct Obj01117 *)q)->f90 = loc.h12;
            if (loc.flag != 0) {
                *(B12 *)(q + 0x7c) = loc.v;
                *(B12 *)(q + 0x70) = **(B12 * *)&((struct Obj12597 *)p)->f18;
            } else {
                ((struct Obj01117 *)q)->f7C = 0;
                ((struct Obj01117 *)q)->f80 = 0;
                ((struct Obj01117 *)q)->f84 = 0;
                *(B12 *)(q + 0x70) = loc.v;
            }
            ((struct Obj01117 *)q)->f96 = 0;
            ((struct Obj01117 *)q)->f94 = v;
            ((struct Obj01117 *)q)->fA0 = 1;
            ((struct Obj01117 *)q)->fA4 = 1;
            ((struct Obj01117 *)q)->fA8 = 1;
            ((struct Obj01117 *)q)->fAC = 1;
            ((struct Obj01117 *)q)->fB0 = 1;
            ((struct Obj01117 *)q)->fB4 = 1;
            ((struct Obj12597 *)p)->f1AC = (void *)func_0218FB1C;
            ((struct Obj01117 *)q)->fB8 = 0;
            ((struct Obj01117 *)q)->f9C = 1;
        }
    }
}











/*
 * Per-frame callback armed by func_0218F9C4/func_0218FA40: steps the +0xf0
 * block's frame counter and interpolates each enabled channel from the
 * start snapshot (+0x34) toward the target (+0x64).
 *
 * Addresses are Black-image addresses.
 */
void func_0218FB1C(u8 *p)
{
    u8 *q;
    u8 *s;
    u8 *t;

    q = p + 0xf0;
    if (((struct Obj00752 *)q)->f9C == 0) {
        return;
    }
    (((struct Obj00752 *)q)->f96)++;
    s = q + 0x34;
    t = q + 0x64;
    if (((struct Obj00752 *)q)->fA4 != 0) {
        ((struct Obj01491 *)p)->f78 = func_0218FDF0((u16 *)(s + 0x24), (u16 *)(t + 0x24),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fA8 != 0) {
        ((struct Obj01491 *)p)->f7A = func_0218FDF0((u16 *)(s + 0x26), (u16 *)(t + 0x26),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fB4 != 0) {
        func_0218FD88((Vec3_0218FD88 *)((s32 *)(s + 0xc)), (Vec3_0218FD88 *)((s32 *)(t + 0xc)), ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96, (Vec3_0218FD88 *)((s32 *)(p + 0x48)));
    }
    if (((struct Obj00752 *)q)->fB0 != 0) {
        ((struct Obj01491 *)p)->f80 = func_0218FDF0((u16 *)(s + 0x2c), (u16 *)(t + 0x2c),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
        func_02048B80(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2]);
        func_02048B94(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (((struct Obj00752 *)q)->fAC != 0) {
        ((struct Obj01491 *)p)->f7C = func_0218FDD4((s32 *)(s + 0x28), (s32 *)(t + 0x28),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fA0 != 0) {
        func_0218FD88((Vec3_0218FD88 *)((s32 *)(s + 0x18)), (Vec3_0218FD88 *)((s32 *)(t + 0x18)), ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96, (Vec3_0218FD88 *)((s32 *)(p + 0x60)));
    }
    if (((struct Obj00752 *)q)->f96 >= ((struct Obj00752 *)q)->f94) {
        ((struct Obj00752 *)q)->f9C = 0;
        func_0218FE40(p);
    }
}











/*
 * Per-frame callback armed by func_0218F930; the three-channel twin of
 * func_0218FB1C (+0x48 and +0x24 vectors, the +0x80 angle, the +0x60 vector).
 *
 * Addresses are Black-image addresses.
 */
void func_0218FC80(u8 *p)
{
    u8 *q;
    u8 *s;
    u8 *t;

    q = p + 0xf0;
    if (((struct Obj01348 *)q)->f9C == 0) {
        return;
    }
    (((struct Obj01348 *)q)->f96)++;
    s = q + 0x34;
    t = q + 0x64;
    if (((struct Obj01348 *)q)->fB4 != 0) {
        func_0218FD88((Vec3_0218FD88 *)((s32 *)(s + 0xc)), (Vec3_0218FD88 *)((s32 *)(t + 0xc)), ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (Vec3_0218FD88 *)((s32 *)(p + 0x48)));
        func_0218FD88((Vec3_0218FD88 *)((s32 *)s), (Vec3_0218FD88 *)((s32 *)t), ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (Vec3_0218FD88 *)((s32 *)(p + 0x24)));
    }
    if (((struct Obj01348 *)q)->fB0 != 0) {
        ((struct Obj01491 *)p)->f80 = func_0218FDF0((u16 *)(s + 0x2c), (u16 *)(t + 0x2c),
                                           ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96);
        func_02048B80(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2]);
        func_02048B94(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (((struct Obj01348 *)q)->fA0 != 0) {
        func_0218FD88((Vec3_0218FD88 *)((s32 *)(s + 0x18)), (Vec3_0218FD88 *)((s32 *)(t + 0x18)), ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (Vec3_0218FD88 *)((s32 *)(p + 0x60)));
    }
    if (((struct Obj01348 *)q)->f96 >= ((struct Obj01348 *)q)->f94) {
        ((struct Obj01348 *)q)->f9C = 0;
        func_0218FE40(p);
    }
}















/*
 * n and d are u16 (the caller passes u16 fields): with int parameters the
 * scheduler hoists the third call's pointer bumps above the store of out->y.
 */
void func_0218FD88(Vec3_0218FD88 *p, Vec3_0218FD88 *q, u16 n, u16 d, Vec3_0218FD88 *out)
{
    if (n == 0)
        *out = *q;
    out->x = func_0218FDD4(&p->x, &q->x, n, d);
    out->y = func_0218FDD4(&p->y, &q->y, n, d);
    out->z = func_0218FDD4(&p->z, &q->z, n, d);
}















int func_0218FDD4(int *p, int *q, int n, int d){
    int x0 = *p;
    int x1 = *q;
    int diff;
    if (n == d)
        return x1;
    diff = x1 - x0;
    return x0 + diff * d / n;
}















u16 func_0218FDF0(u16 *a, u16 *b, s32 d, s32 n)
{
    u16 x, delta, rem;
    if (d == 0)
        return *b;
    x = *a;
    delta = *b - x;
    rem = 0x10000 - delta;
    if (delta <= rem)
        return x + (u16)(delta * n / d);
    return x - (u16)(rem * n / d);
}















void func_0218FE40(u8 *a)
{
    ((struct Obj01491 *)a)->f1AC = 0;
    ((struct Obj01491 *)a)->f1A8 = 0;
}















int func_0218FE50(u8 *a)
{
    Sub_0218F900 *s = (Sub_0218F900 *)(a + 0xf0);
    if (((struct Obj19576 *)a)->f1AC != 0 && s->unk9c != 0)
        return 1;
    return 0;
}















/*
 * Returns the object pointer advanced by 340 bytes.
 */
u8 *func_0218FE70(u8 *p)
{
    return p + 340;
}















/*
 * Tail-call thunk: forwards to func_021900C4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FE78(u32 a, u8 *b)
{
    func_021900C4(a, b);
}















void *func_0218FE80(void *a)
{
    void *o = func_0218FF30(func_02188C84(a));
    func_0218FF50(o, a);
    return o;
}















/*
 * Tail-call thunk: forwards to func_0218FF48 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FE98(void *a0)
{
    func_0218FF48(a0);
}















/*
 * Field setter at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FEA0(u8 *p, u32 v)
{
    ((struct Obj17917 *)p)->f8 = v;
}















int func_0218FEA4(u32 a, u32 b, u32 c, u32 d)
{
func_0218FFE8((u8 *)a, b, c, d);
func_02190058((u8 *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
func_021900A8((void *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
return func_0218FF78((u32 *)a);
}














void func_0218FEC0(u8 *o)
{
    u8 *a = (u8 *)func_021901E4(o);
    u8 *b = (u8 *)(func_021901E8(o) + 4);
    func_0218ED34(a, ((struct Obj09470 *)b)->f0);
    func_0218ED48(a, ((struct Obj09470 *)b)->f2);
    func_0218ED58(a, ((struct Obj09470 *)b)->f4);
    func_0218EC90((u8 *)a, (const Vec3_0218EC90 *)(b + 8));
    func_0218ECD4((u8 *)a, (const Vec3_0218ECD4 *)(b + 0x14));
}














void func_0218FF00(u8 *a)
{
    if (((struct Obj17918 *)func_021901E8(a))->f0 == 0) {
        func_02190110(a);
        return;
    }
    func_0219014C((u32 *)a);
}














void func_0218FF20(u8 *a)
{
    if (((struct Obj04204 *)a)->fC != 0)
        func_02190000((u32 *)a);
}














void *func_0218FF30(u16 heap)
{
    return func_02030734(heap, 0x20, 0, d_021DDA38, 0xee);
}














/*
 * Unlabelled tail-call thunk; callee of the thunk at 0x0218FE98.
 *
 * Addresses are Black-image addresses.
 */
void func_0218FF48(void *a0)
{
    func_020307B0(a0);
}














void func_0218FF50(u32 *o, void *a)
{
    func_02082BCC(o, 0, 0x20);
    o[0] = (u32)a;
    o[1] = (u32)func_02188C58(a);
    o[2] = 0;
    o[3] = 0;
    o[5] = 0;
    o[6] = 0;
    o[7] = 0;
}














u32 func_0218FF78(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];
    u8 *r = (u8 *)func_021901E8((u8 *)p);
    if (func_02188CFC((u8 *)a) == 1)
        func_021BB260(func_02188C5C((u8 *)a), 0);
    if (((struct Obj12599 *)r)->f44 != 0) {
        if (func_0218EC5C((u8 *)p[1]) != 0) {
            p[7] = 1;
            p[6] = func_0218EC5C((u8 *)b);
            func_0218EC54((u8 *)b);
        }
    }
    if (((struct Obj12599 *)r)->f48 != 0) {
        p[5] = func_0218F1B4((u8 *)b);
        func_0218F1AC((u8 *)b, 0);
    }
    func_021AB75C((u8 *)func_02189A18((u8 *)a), 0);
    p[3] = 1;
    return p[3];
}













void func_0218FFE8(u8 *a, u32 a1, u32 a2, u32 a3)
{
    void *x = ((struct Obj02372 *)a)->f4;
    ((struct Obj02372 *)a)->f10 = func_0218E138(x);
    func_0218E13C(x, 0);
}













void func_02190000(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];
    u8 *r = (u8 *)func_021901E8((u8 *)p);
    func_021AB75C((u8 *)func_02189A18((u8 *)a), 1);
    if (((struct Obj19578 *)r)->f48 != 0)
        func_0218F1AC((u8 *)b, p[5]);
    if (p[7] != 0)
        func_0218EC30((u8 *)b, (const Vec3_0218EC30 *)p[6]);
    func_0218E13C((u8 *)b, p[4]);
    if (func_02188CFC((u8 *)a) == 1)
        func_021BB260(func_02188C5C((u8 *)a), 1);
}











void func_02190058(u8 *o)
{
    B12 v2, v1, v;
    u32 c;
    u16 b, a;
    func_0218F19C((u8 *)o, (Vec3 *)&v1);
    func_0218F18C((u8 *)o, (Vec3 *)&v2);
    func_0207CA00(&v1, &v2, &v);
    func_0218ED5C((void *)((u32)(&v)), (u16 *)((u32)(&b)), (u16 *)((u32)(&a)), (int *)((u32)(&c)));
    func_0218ED58(o, c);
    func_0218ED34(o, b);
    func_0218ED48(o, a);
}










void func_021900A8(void *a)
{
    Vec3_021900A8 t;
    func_0218F18C((u8 *)a, (Vec3 *)((B12 *)(&t)));
    func_0218EC90((u8 *)a, (const Vec3_0218EC90 *)((u8 *)(&t)));
}









void func_021900C4(u32 a, u8 *b)
{
    u8 v1[12];
    u8 v0[12];
    u8 v2[12];

    func_0218F19C((u8 *)a, (Vec3 *)v0);
    func_0218F18C((u8 *)a, (Vec3 *)v1);
    func_0207CA00(v0, v1, v2);
    func_0218ED5C((void *)((u32)v2), (u16 *)((u32)b), (u16 *)((u32)(b + 2)), (int *)((u32)(b + 4)));
    func_0218F18C((u8 *)a, (Vec3 *)(b + 8));
    func_0218ECC4((u8 *)a, (Vec3_0218ECC4 *)(b + 0x14));
}









void func_02190110(u8 *a)
{
    void *x = ((struct Obj19579 *)a)->f4;
    Params *p = (Params *)(func_021901E8(a) + 0x24);
    func_0218ED34(x, p->h0);
    func_0218ED48(x, p->h2);
    func_0218ED58(x, p->w4);
    func_0218EC90((u8 *)x, (const Vec3_0218EC90 *)(&p->v8));
    func_0218ECD4((u8 *)x, (const Vec3_0218ECD4 *)(&p->v14));
}









void func_0219014C(u32 *a)
{
    u32 h = *a;
    u8 *o = (u8 *)func_021901E8((u8 *)a);
    u32 k = ((struct Obj19581 *)o)->f0;
    u8 *q = o + 0x24;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = func_021C7058(h, k, ((struct Obj09472 *)q)->f0);
    v1 = func_021C701C(h, k, ((struct Obj09472 *)q)->f2);
    v2 = func_021C6F00(h, k, ((struct Obj09472 *)q)->f4);
    v3 = func_021C7C10(h, k, o + 0xc, q + 8);
    v4 = func_021C7AE4(h, k, q + 0x14);
    h = func_02188D38((u8 *)h);
    func_021C6DE0((u8 *)h, (u32 *)v0, 0);
    func_021C6DE0((u8 *)h, (u32 *)v1, 0);
    func_021C6DE0((u8 *)h, (u32 *)v2, 0);
    func_021C6DE0((u8 *)h, (u32 *)v3, 0);
    func_021C6DE0((u8 *)h, (u32 *)v4, 0);
}









u32 func_021901E4(u8 *p)
{
    return ((struct Obj17919 *)p)->f4;
}









u32 func_021901E8(u8 *p)
{
    return ((struct Obj17920 *)p)->f8;
}









u8 *func_021901EC(u16 heap, u32 b)
{
    u8 *o = func_02030734(heap, 0x17c, 1, d_021DDA50, 0x1a4);
    ((struct Obj01849 *)o)->f0 = heap;
    ((struct Obj01849 *)o)->f2 = 0xff;
    ((struct Obj01849 *)o)->f4 = 0xff;
    ((struct Obj01849 *)o)->f168 = b;
    ((struct Obj01849 *)o)->f8 = (u32)func_0201D7EC(0x17, 0, 0, 0, ((struct Obj01849 *)o)->f0);
    ((struct Obj01849 *)o)->fC = func_0201C440((void *)(((struct Obj01849 *)o)->f0));
    ((struct Obj01849 *)o)->f164 = (u32)func_0203101C(((struct Obj01849 *)o)->f0, ((struct Obj01849 *)o)->f0, 1, 4);
    func_021931F4((u32)(o + 0x160));
    ((struct Obj01849 *)o)->f174 = func_0204A1BC(5, 0xc, 0, heap);
    func_02062A4C((struct NitroFileHeader *)(((struct Obj01849 *)o)->f174), (void **)(o + 0x178));
    return o;
}









/*
 * Tail-call thunk: pins the second argument to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_02190270(u32 a)
{
    func_02192BD0((char *)a, 1);
}









void func_0219027C(u8 *a)
{
    func_02192CF0((char *)a, 0);
    if (((struct Obj12600 *)a)->f16C == 0)
        ((struct Obj12600 *)a)->f16C = func_020056A0(func_02192EB8, a, 0);
}









/*
 * Tail-call thunk: forwards to func_02192FA4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021902A4(u32 a0, u32 a1)
{
    func_02192FA4(a0, a1);
}









/*
 * Unlabelled tail-call forwarder, called from func_021BEF8C.
 */
void func_021902AC(u16 *p, int v)
{
    func_02192FEC(p[1], p[0], v);
}









void func_021902BC(Obj_0218E610 *o)
{
    int i;
    Slot *s;

    i = 0;
    s = o->slot;

    if (((u32 *)o)[0x5d] != 0) {
        func_020307B0((void *)((u32 *)o)[0x5d]);
    }
    if (((u32 *)o)[0x57] != 0) {
        func_02194798((unsigned char *)(((u32 *)o)[0x57]));
    }
    if (((u32 *)o)[0x59] != 0) {
        func_02031140((struct S02031140 *)(((u32 *)o)[0x59]));
    }
    if (o->f02 != 0xff) {
        func_02040DA8(o->f02, 1, 0);
        func_020403F4((u8)o->f02);
    }
    if (o->f04 != 0xff) {
        func_020403F4((u8)o->f04);
    }
    do {
        if (s->f18 != 0) {
            func_02045808((struct U16Vec *)s->f18);
        }
        i++;
        s++;
    } while (i < 4);
    if (o->f0c != 0) {
        func_0201C4C0((struct PrintSys *)o->f0c);
    }
    if (o->f08 != 0) {
        func_0201D83C((void *)o->f08);
    }
    func_020307B0(o);
}



















void func_02190344(u8 *a)
{
    if (((struct Obj04205 *)a)->f15C != 0) {
        func_02194798(((struct Obj04205 *)a)->f15C);
        ((struct Obj04205 *)a)->f15C = 0;
    }
    if (((struct Obj04205 *)a)->f2 != 0xff) {
        func_02040DA8(((struct Obj04205 *)a)->f2, 1, 0);
        func_020403F4((u8)(((struct Obj04205 *)a)->f2));
        ((struct Obj04205 *)a)->f2 = 0xff;
    }
}



















int func_02190378(u8 *a)
{
    if (((struct Obj09473 *)a)->f4 != 0xff) {
        func_020403F4((u8)(((struct Obj09473 *)a)->f4));
        ((struct Obj09473 *)a)->f4 = 0xff;
        return 1;
    }
    return 0;
}



















void func_02190398(u32 *p)
{
    if (p[0x57] != 0) {
        func_02194798((unsigned char *)p[0x57]);
    }
    func_02192E0C(p);
    if (p[0x5b] == 0) {
        p[0x5b] = (u32)func_020056A0(func_02192EB8, p, 0);
    }
}



















/*
 * Unlabelled leaf predicate, called from func_021BEF8C.
 */
int func_021903CC(u8 *p)
{
    if (((struct Obj19582 *)p)->f16C == 0)
        return 1;
    return 0;
}



















void func_021903E0(Link_02190344 *o)
{
    int i;
    u32 *w;
    Slot *s;
    int j;
    u32 t;

    func_0201C4E4((struct PrintSys *)o->f0c);
    i = 0;
    w = o->f0a0;
    for (; i < 8; i++, w++) {
        if (*w != 0) {
            func_021919C8((struct Q *)(*w));
        }
    }
    s = o->slot;
    for (j = 0; j < 4; j++, s++) {
        t = s->f0c;
        if (t != 0) {
            if (s->f20 != 0) {
                if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)s->f1c))) == 0) {
                    func_02045334((struct Descriptor *)s->f1c);
                    s->f20 = 0;
                }
            }
            s->f04 = (s->f20 == 0) ? 1 : 0;
        }
    }
    func_020310C4((struct Tcbl *)(((u32 *)o)[0x59]));
    if (((u32 *)o)[0x57] != 0) {
        func_0219470C((unsigned char *)(((u32 *)o)[0x57]));
        func_02194760(((u32 *)o)[0x57]);
    }
}



















void func_0219047C(u8 *p)
{
    void *q = ((struct Obj19583 *)p)->f15C;
    if (q != 0)
        func_02194764(q);
}



















/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_02190490(u8 *p)
{
    func_0201C6EC((struct PrintSys *)(((struct Obj17921 *)p)->fC));
}



















int func_0219049C(u8 *p)
{
    return func_0201C6B4((const struct PrintSys *)(((struct Obj17922 *)p)->fC));
}



















u32 func_021904A8(u32 *p)
{
    return p[3];
}



















u32 func_021904AC(u8 *p)
{
    return ((struct Obj17923 *)p)->f8;
}



















int func_021904B0(u32 a, u32 b)
{
return (int)func_02045B38(0, 2, ((b << 16) >> 16), ((struct Obj17924 *)((u8 *)(a)))->f0);
}



















/*
 * Tail-call thunk: forwards to func_02045C04 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021904C8(struct Rec *a0)
{
    return func_02045C04(a0);
}



















/*
 * Unlabelled leaf: sets the byte at +0x170.
 * Addresses are Black-image addresses.
 */
void func_021904D0(u8 *p)
{
    p[0x170] = 1;
}



















/*
 * Tail call on the object displaced by 0x160 bytes, forwarding the value.
 * The second parameter is what puts the offset temp in r2 instead of r1.
 *
 * Addresses are Black-image addresses.
 */
void func_021904DC(u8 *p, u8 v)
{
    func_02193208(p + 0x160, v);
}


















Slot_021904EC *func_021904EC(u32 *p, u32 a, u32 b)
{
    Slot_021904EC *e;
    int i;

    i = 0;
    e = (Slot_021904EC *)((u8 *)p + 0x10);
    for (; i < 4; i++, e++) {
        if (e->f0c == 0) {
            e->f00 = p;
            e->f14 = b;
            e->f04 = 1;
            e->f08 = p[2];
            e->f0c = p[3];
            e->f18 = (u32)func_020457B0(0xa0, ((struct Obj00126 *)p)->f0);
            e->f10 = a;
            e->f1c = b;
            e->f20 = 0;
            return e;
        }
    }
    return 0;
}


















void func_02190538(struct Slot *s){
    s->f08 = 0;
    s->f0c = 0;
    func_02045808((struct U16Vec *)s->f18);
    s->f18 = 0;
    s->f10 = 0;
}


















void func_02190550(struct Slot *s, int x, int y, u32 z){
    u32 t;

    func_02045CAC((struct MsgBank *)s->f10, z, (void *)s->f18);
    t = s->f0c;
    func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)s->f1c), (s16)x, (s16)y, (void *)s->f18, s->f08);
    s->f20 = 1;
}


















void func_02190590(struct Slot *s, int x, int y, u32 z){
    u32 t;

    t = s->f0c;
    func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)s->f1c), (s16)x, (s16)y, (void *)z, s->f08);
    s->f20 = 1;
}

















void func_021905C8(Slot *s, int x, int y, u32 z, u16 w, u32 v)
{
    u32 t;

    t = s->f0c;
    func_0201C724((void *)t, (u32)func_02045770((struct Descriptor *)s->f1c), (s16)x, (s16)y, z, v, w);
    s->f20 = 1;
}

















void func_02190604(struct Slot *s, int x, int y, u32 z, u16 w){
    func_021905C8(s, x, y, z, w, s->f08);
}

















/*
 * Unlabelled leaf getter, callee of the thunk at 0x0219077C.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0219061C(u32 *p)
{
    return p[1];
}

















int func_02190620(u32 a)
{
func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj12064 *)((u8 *)(a)))->f14)), 255);
return func_020409B4(func_02045730((struct Descriptor *)(((struct Obj12064 *)((u8 *)(a)))->f14)));
}
















void func_0219063C(Slot *s, int x, int y, int w, int h)
{
    func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)s->f14)), (s16)x, (s16)y, (u16)w, (u16)h, 0xFF);
    func_020409B4(func_02045730((struct Descriptor *)s->f14));
}
















u32 func_02190678(u8 *p)
{
    return ((struct Obj17926 *)p)->fC;
}
















/*
 * Returns the object pointer advanced by 0x1c bytes.
 */
u8 *func_0219067C(u8 *p)
{
    return p + 0x1c;
}















Obj_02190680 *func_02190680(Fx_0218E610 *a, u32 b, u16 c, u16 d, u16 e, u16 f, u16 g)
{
    u8 k;
    Obj_02190680 *r;

    k = a->f02;
    func_02192F74((struct W *)a);
    if (g == 0xe) {
        k = a->f04;
    }
    r = func_02030734(a->f00, 0xC, 1, d_021DDA50, 0x483);
    r->owner = a;
    r->id = func_021930C0(k, a->f00, c, d, e, f, g);
    r->slot = (u32)func_021904EC((u32 *)a, b, r->id);
    if (g == 0xe) {
        func_02193144(a->f00);
        func_02193044(1);
    } else {
        func_02193170(a->f00);
    }
    return r;
}















void *func_02190708(Fx_0218E610 *p, u32 a, u16 b, u16 c, u16 d, u16 e){
    p->f06 = 0xE;
    return func_02190680(p, a, b, c, d, e, p->f06);
}















int func_02190728(void *a)
{
func_02193130((struct Descriptor *)(((struct Obj12065 *)((u8 *)(a)))->f0));
func_02190538((struct Slot *)(((struct Obj12065 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}















int func_02190740(u32 a, u32 b, u32 c, u32 d)
{
func_02190550((struct Slot *)(((struct Obj12066 *)((u8 *)(a)))->f4), b, c, d);
return func_020409B4(func_02045730((struct Descriptor *)(((struct Obj12066 *)((u8 *)(a)))->f0)));
}














void func_02190758(Slot **p, int x, int y, u32 z)
{
    func_02190590(p[1], x, y, z);
}














void func_02190764(Slot **p, int x, int y, u32 z, u16 w, u32 v)
{
    func_021905C8(p[1], x, y, z, w, v);
}














/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_0219077C(u8 *p)
{
    return func_0219061C((u32 *)(((struct Obj17928 *)p)->f4));
}














void func_02190788(u8 *p)
{
    func_02190620(((struct Obj17929 *)p)->f4);
}














void func_02190794(Slot **p, int x, int y, int w, int h)
{
    func_0219063C(p[1], x, y, w, h);
}














void func_021907A8(Fx_0218E610 *p, u32 a)
{
    func_02190708(p, a, 1, 0x13, 0x1E, 4);
}














u32 func_021907C0(u8 *p)
{
    return ((struct Obj17930 *)p)->f0;
}

















Obj_02190344 *func_021907C4(Fx_0218E610 *a, u32 b, u32 c, u32 d, u16 e, u16 f)
{
    Obj_02190344 *r;

    a->f06 = 0xe;
    func_02192F74((struct W *)a);
    r = func_02030734(a->f00, 0xC, 1, d_021DDA50, 0x560);
    r->owner = a;
    r->id = func_02192B20(c, d, e, f, a->f00);
    r->slot = (u32)func_021904EC((u32 *)a, b, r->id);
    func_02193044(1);
    return r;
}

















int func_0219082C(void *a)
{
func_02192BC0((u8 *)(((struct Obj12067 *)((u8 *)(a)))->f0));
func_02190538((struct Slot *)(((struct Obj12067 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}

















void func_02190844(Slot **p, int x, int y, u32 z)
{
    func_02190590(p[1], (u16)(x + 8), y, z);
}
















/*
 * Unlabelled 12-byte leaf: passes the second word of its argument to func_02190620.
 */
void func_02190854(u32 *p)
{
    func_02190620(p[1]);
}

















/*
 * Allocates a 0x14-byte handle, builds a 0x34-byte template (func_02190B2C
 * plus the caller's words) and creates the object with func_0201FF30.
 * `const` on b is what interleaves its field loads with the r->c store.
 *
 * Addresses are Black-image addresses.
 */
Handle_02190344 *func_02190860(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i)
{
    Tmpl t;
    u8 k;
    Handle_02190344 *r;

    k = a[1];
    func_02192F74((struct W *)a);
    if (f == 0xe) {
        k = a[2];
    }
    r = func_02030734(a[0], 0x14, 1, d_021DDA50, 0x606);
    func_02190B2C((struct Dst *)(&t), (const struct Src *)b);
    r->owner = a;
    r->c = c;
    r->id = func_021930C0(k, a[0], *(const u16 *)&((struct Obj07430 *)b)->f14, *(const u16 *)&((struct Obj07430 *)b)->f16,
                          *(const u16 *)&((struct Obj07430 *)b)->f18, *(const u16 *)&((struct Obj07430 *)b)->f1A, f);
    r->slot = (u32)func_021904EC((u32 *)a, 0, r->id);
    t.w24 = 0;
    t.w28 = (u32)func_0219067C((u8 *)r->slot);
    t.w2c = func_02190678((u8 *)r->slot);
    t.w30 = ((struct Obj00126 *)a)->f8;
    t.w0c = r->id;
    t.w00 = c;
    t.w08 = h;
    t.w04 = g;
    t.w1c = i;
    r->obj = (u32)func_0201FF30((struct Src *)(&t), d, e, a[0]);
    func_02020CF8((struct Obj_02190344 *)r->obj, a[0]);
    if (f == 0xe) {
        func_02193144(a[0]);
        func_02193044(1);
    } else {
        func_02193170(a[0]);
    }
    return r;
}
















Handle_02190344 *func_02190938(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i)
{
    a[3] = 0xe;
    return func_02190860(a, b, c, d, e, a[3], g, h, i);
}
















Handle_02190344 *func_02190960(u16 *a, const u8 *b, u32 c, u16 d, u16 e)
{
    return func_02190938(a, b, c, d, e, 0, ((struct Obj19589 *)b)->f1C, 0);
}















u32 func_0219097C(u32 a, const void *b, u32 c)
{
return (int)func_02190960((u16 *)a, (const u8 *)b, c, 0, 0);
}















Handle_02190344 *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w)
{
    Handle_02190344 *r = func_02190860(a, b, c, y, z, a[3], d, 0, x);
    if (w == 0)
        func_02020D10((u8 *)r->obj, 1);
    return r;
}















int func_021909BC(void *a)
{
func_0202020C((struct Obj_02190344 *)(((struct Obj07209 *)((u8 *)(a)))->f10), 0, 0);
func_0201F868((void *)(((struct Obj07209 *)((u8 *)(a)))->fC));
func_02193130((struct Descriptor *)(((struct Obj07209 *)((u8 *)(a)))->f8));
func_02190538((struct Slot *)(((struct Obj07209 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}















int func_021909E4(Handle_02190344 *h)
{
    int v;

    if (func_0219049C((u8 *)h->owner) == 0)
        return -1;
    v = func_020200CC((struct Obj_02190344 *)h->obj);
    if (v == -1)
        return -1;
    if (v == -2)
        return -2;
    return v;
}














/*
 * Unlabelled leaf (no lr save): forwards p->f10 to func_02020234.
 *
 * Addresses are Black-image addresses.
 */
void func_02190A14(u8 *p)
{
    func_02020234((u8 *)(((struct Obj19590 *)p)->f10));
}














/*
 * Tail-call thunk: forwards to func_0201F81C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02190A20(int n, u16 d)
{
    return func_0201F81C(n, d);
}














u32 func_02190A28(const Pair *arr, int n, u32 c, u16 d)
{
    u32 obj;
    int i;

    obj = func_02190A20(n, d);
    for (i = 0; i < n; i++)
        func_0201F878((struct Slot *)obj, c, arr[i].a, arr[i].b, d);
    return obj;
}














int func_02190A64(u32 a, u32 b, u32 c, u32 d)
{
return func_0201F898(a, b, c, d);
}














/*
 * Tail-call thunk: forwards to func_0201F8F4 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02190A6C(u32 a)
{
    func_0201F8F4((struct Slot *)a);
}














u32 func_02190A74(u32 *obj, u32 *tab, u32 *out, u32 key)
{
    u32 k;
    u32 bestIdx;
    u32 best;
    u32 i;

    best = 0;
    bestIdx = 0;
    i = 0;
    if (tab[0] != -1) {
        k = (u16)key;
        do {
            u32 r;
            if (tab[0] == 0) {
                break;
            }
            r = func_0201D304((struct StrObj *)tab[0], obj[2], k);
            if (r > best) {
                best = r;
                bestIdx = i;
            }
            tab += 2;
            i++;
        } while (tab[0] != -1);
    }
    *out = bestIdx;
    return best;
}














/*
 * Unlabelled leaf (tail call through a pool word), sole blocker of
 * ov010 func_0215A864's MATCH.
 */
unsigned func_02190AC4(void *p)
{
    return func_0201F91C(p);
}














u32 func_02190ACC(u32 *obj, u32 *tab, u32 unused, u32 key)
{
    u32 tmp;
    u32 x;
    u32 r;

    x = func_02190A74(obj, tab, &tmp, key);
    x += key + 0x10;
    r = x >> 3;
    if (x & 7)
        r++;
    return r;
}













/*
 * Unlabelled leaf, sole blocker of ov010 func_0215A864's MATCH.
 */
unsigned func_02190AEC(unsigned a, unsigned b, unsigned c, int d)
{
    unsigned n = a * (b + c);
    unsigned r = (n + 7) >> 3;

    if (d && r * 8 - n < 6) {
        r++;
    }
    return r;
}














int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f)
{
((struct Obj05858 *)((u8 *)(a)))->f0 = b;
((struct Obj05858 *)((u8 *)(a)))->f16 = d;
((struct Obj05858 *)((u8 *)(a)))->f14 = c;
((struct Obj05858 *)((u8 *)(a)))->f18 = *(u16 *)((u8 *)((u8 *)&e0));
((struct Obj05858 *)((u8 *)(a)))->f1A = *(u16 *)((u8 *)((u8 *)&e0) + 4);
return a;
}














int func_02190B1C(u32 a)
{
return func_0201F73C(((struct Obj17931 *)((u8 *)(a)))->f8, 0, 1, 13);
}














void func_02190B2C(struct Dst *d, const struct Src *s){
    func_02082BCC(d, 0, 0x34);
    d->d10 = s->a00;
    d->d12 = s->a02;
    d->d14 = s->a04;
    d->d15 = s->a05;
    d->d16 = s->a06;
    d->d17lo = s->a07lo;
    d->d17hi = s->a07hi;
    d->d18lo = s->a08lo;
    d->d18hi = s->a08hi;
    d->d1a_lo = s->a0a_lo;
    d->d1a_mid = s->a0a_mid;
    d->d1a_z = s->a0c;
    d->d20 = s->a10;
    d->d22 = s->a12;
    d->d08 = s->a1c;
}














u32 *func_02190BE4(u16 *a, u32 b)
{
    Blk32 A = d_021D3F38;
    Blk16 B_0218E610 = d_021D3E68;
    u32 r7;
    u32 r18;
    u32 *res;

    r7 = func_021904B0((u32)a, 0xe9);
    r18 = func_02190A28((const struct Pair *)(&B_0218E610), 2, r7, a[0]);
    func_02045C04((struct Rec *)r7);
    func_02190B08((u32)(&A), 2, 0x18, 0xa, 7, 4);
    res = (u32 *)func_02190860(a, (const u8 *)&A, r18, 0, (u16)b, a[3], 0, 0, 0);
    func_02020D10((u8 *)res[4], 0);
    return res;
}














int func_02190C78(Handle_02190A28 *h)
{
    int v = func_021909E4((Handle_02190344 *)h);
    if (v == -1)
        return 2;
    if (v == -2)
        return 1;
    return v;
}














u32 *func_02190C94(u32 *a, u32 b, u32 c, u32 d, u16 e0, u32 f, u16 g)
{
    u32 *r;

    r = (u32 *)func_02030734(((struct Obj07432 *)a)->f0, 0xc, 1, d_021DDA50, 0x85e);
    r[2] = (u32)a;
    ((struct Obj07433 *)r)->f2 = f;
    r[1] = (u32)func_0201CD10(c, d, e0, b, a[2], f, a[0x59], 0, ((struct Obj07432 *)a)->f0, g,
                         (u32)((void *)func_02190D08));
    func_02193200(r[2] + 0x160);
    return r;
}














int func_02190D08(int x)
{
    switch (x) {
    case 3:
        func_020061E4(0x56B);
        break;
    case 6:
        return func_02006238();
    }
    return 0;
}














u32 *func_02190D2C(u32 *a, u32 b, u32 c, u32 d, u16 e, u32 f)
{
    return func_02190C94(a, b, c, d, e, f, 0xF);
}














int func_02190D48(void *a)
{
func_0201CE48((struct Rec3 *)(((struct Obj17932 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}













int func_02190D5C(u32 *p)
{
    int r = func_0201CE30((void *)p[1]);

    switch (r) {
    case 0:
        if (func_02193228((u8 *)(p[2] + 0x160)) != 0) {
            func_021932A0(p[1], 1);
        } else {
            func_021932A0(p[1], 0);
        }
        break;
    case 1:
        if (func_02193260((u8 *)(p[2] + 0x160), func_0201CE34((void *)p[1])) != 0) {
            if (func_0219320C((u8 *)(p[2] + 0x160)) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38((void *)p[1]);
            r = 0;
            func_021932A0(p[1], 0);
        }
        break;
    case 2:
        break;
    }
    return r;
}













Obj2 *func_02190DCC(Fx_0218E610 *a, u32 b, u32 c, u16 d, u16 e, u16 f){
    Obj2 *r;

    a->f06 = 0xe;
    func_02192F74((struct W *)a);
    r = func_02030734(a->f00, 0x20, 1, d_021DDA50, 0x8FF);
    r->owner = a;
    r->b = b;
    r->id = func_021930C0(a->f04, a->f00, c, d, e, f, a->f06);
    r->f10 = (u32)func_020457B0(0xA0, a->f00);
    func_021927C0((struct G *)r->sub, (struct Fx_0218E610 *)a);
    func_02193144(a->f00);
    func_02193044(1);
    return r;
}













int func_02190E40(u32 a)
{
func_02193130((struct Descriptor *)(((struct Obj04888 *)((u8 *)(a)))->f0));
if (((struct Obj04888 *)((u8 *)(a)))->f4 != 0) {
    func_02190D48((void *)(((struct Obj04888 *)((u8 *)(a)))->f4));
}
if (((struct Obj04888 *)((u8 *)(a)))->f8 != 0) {
    func_02190538((struct Slot *)(((struct Obj04888 *)((u8 *)(a)))->f8));
}
func_02045808((struct U16Vec *)(((struct Obj04888 *)((u8 *)(a)))->f10));
func_021927E8((u32 *)(a + 24));
return func_020307B0((void *)a);
}










void func_02190E74(u32 *p, u32 b, u16 c, u32 d)
{
    if (p[1] != 0) {
        func_02190D48((void *)p[1]);
    }
    func_02045CAC((struct MsgBank *)p[3], d, (void *)p[4]);
    p[1] = (u32)func_02190D2C((u32 *)p[5], p[4], p[0], b, c, func_02193210((u8 *)(p[5] + 0x160)));
}











void func_02190EB8(P_0218E610 *p, u32 b, u16 c, u32 d)
{
    if (p->f04 != 0)
        func_02190D48((void *)p->f04);
    p->f04 = (u32)func_02190D2C((u32 *)p->f14, d, p->f00, b, c, func_02193210((u8 *)p->f14 + 0x160));
}












u32 func_02190EF0(u32 *p)
{
    u32 r = func_02190D5C((u32 *)p[1]);
    func_020362DC();
    func_0203630C();
    switch (r) {
    case 0:
        if (func_021927F8((u8 *)(p + 6)) == 1) {
            func_021927FC((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            func_02045334((struct Descriptor *)p[0]);
        }
        break;
    case 1:
        if (func_0219320C((u8 *)(p[5] + 0x160)) == 0) {
            func_021928C0((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            func_02045334((struct Descriptor *)p[0]);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}












struct Obj2 *func_02190F64(Fx_0218E610 *a, u32 b)
{
    return func_02190DCC(a, b, 1, 0x13, 0x1E, 4);
}











void func_02190F7C(P_0218E610 *p)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->f00)), 0xFF);
    func_020409B4((u8)p->f14->f02);
}










/*
 * Getter: returns the first word of the object.  Unlabelled in the listing,
 * reached from func_021D1C8C.
 *
 * Addresses are Black-image addresses.
 */
void *func_02190F9C(void **p)
{
    return *p;
}











Obj2 *func_02190FA0(Fx_0218E610 *a, u32 b, u32 c)
{
    Obj2 *r;

    a->f06 = 0xe;
    func_02192F74((struct W *)a);
    r = func_02030734(a->f00, 0x20, 1, d_021DDA50, 0x9F4);
    r->owner = a;
    r->b = b;
    r->id = func_02192B20(1, c, 0x1E, 4, a->f00);
    r->f10 = (u32)func_020457B0(0xA0, a->f00);
    func_021927C0((struct G *)r->sub, (struct Fx_0218E610 *)a);
    func_02193144(a->f00);
    func_02193044(1);
    return r;
}











int func_02191008(u32 a)
{
func_02192BC0((u8 *)(((struct Obj00005 *)((u8 *)(a)))->f0));
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02190D48((void *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    func_02190538((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f10));
func_021927E8((u32 *)(a + 24));
return func_020307B0((void *)a);
}








void func_0219103C(u32 *p, u32 b, u16 c, u32 d)
{
    if (p[1] != 0) {
        func_02190D48((void *)p[1]);
    }
    func_02045CAC((struct MsgBank *)p[3], d, (void *)p[4]);
    p[1] = (u32)func_02190D2C((u32 *)p[5], p[4], p[0], (u16)(b + 8), c, func_02193210((u8 *)(p[5] + 0x160)));
}










void func_02191084(P_0218E610 *p, u32 b, u16 c, u32 d)
{
    if (p->f04 != 0)
        func_02190D48((void *)p->f04);
    p->f04 = (u32)func_02190D2C((u32 *)p->f14, d, p->f00, (u16)(b + 8), c, func_02193210((u8 *)p->f14 + 0x160));
}











u32 func_021910C0(u32 *p)
{
    u32 r = func_02190D5C((u32 *)p[1]);
    func_020362DC();
    func_0203630C();
    switch (r) {
    case 0:
        if (func_021927F8((u8 *)(p + 6)) == 1) {
            func_021927FC((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            func_02045334((struct Descriptor *)p[0]);
        }
        break;
    case 1:
        if (func_0219320C((u8 *)(p[5] + 0x160)) == 0) {
            func_021928C0((struct Cur *)(p + 6), (u32)func_02045770((struct Descriptor *)p[0]), 15);
            func_02045334((struct Descriptor *)p[0]);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}











void func_02191134(P_0218E610 *p)
{
    if (func_0219320C((u8 *)p->f14 + 0x160) == 0) {
        func_021928C0((struct Cur *)((u8 *)p + 0x18), (u32)func_02045770((struct Descriptor *)p->f00), 0xF);
        func_02045334((struct Descriptor *)p->f00);
    }
}










void func_02191164(P_0218E610 *p)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->f00)), 0xFF);
    func_020409B4((u8)p->f14->f02);
}










void func_02191184(Q *q, u32 b, int c, u32 d)
{
    if (q->f08 != 0)
        func_02190538(q->f08);
    q->f08 = func_021904EC(q->f14, 0, q->f00);
    func_02190590(q->f08, (u16)(b + 8), c, d);
}










u32 func_021911B4(u8 *p)
{
    return ((struct Obj17934 *)p)->f0;
}








void func_021911B8(A *a, B_0218E610 *b, int mode, V3_02190344 *v, u32 d, u32 e, u32 f)
{
    b->v = v;
    b->pos = *v;
    a->h[3] = 11;
    b->a = a;
    b->f08 = a->s.f0;
    b->mode = mode;
    func_02193170(a->h[0]);
    func_02193044(0);
    switch (mode) {
    case 0:
        func_02194848((u8 *)b->f08, 0, (u32)v, d, 15, e, f, func_02193210((u8 *)((u32)&a->s.f4)));
        break;
    case 1:
        func_02194888((u8 *)b->f08, 1, (u32)v, d, 15, e, f, func_02193210((u8 *)((u32)&a->s.f4)));
        break;
    default:
        func_021948CC((u8 *)b->f08, 2, (u32)v, d, 15, e, func_02193210((u8 *)((u32)&a->s.f4)));
        break;
    }
    func_02193200((u32)a + 0x160);
    func_02194940((u8 *)b->f08, b->mode);
    func_021927C0((struct G *)b->f0c, (struct Fx_0218E610 *)((struct Fx_0218E610 *)a->h));
    if (e == 1) {
        b->f02 = 8;
        func_020061E4(0x72C);
    }
}













Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g)
{
    Ent *e;

    if (idx < 3) {
        e = (Ent *)(base + 0xC0) + idx;
        if (e->f08 == 0) {
            func_021911B8((A *)base, (B_0218E610 *)e, idx, (V3_02190344 *)c, d, f, g);
            return e;
        }
    }
    return 0;
}














int func_021912D8(u32 a)
{
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
func_021927E8((u32 *)(a + 12));
return func_02194950(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8, *(u8 *)((u8 *)(a) + 1));
}














int func_021912F8(u32 a, u32 b, u32 c, u32 d)
{
if (func_02194960(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8, *(u8 *)((u8 *)(a) + 1), c, d) != 0) {
    func_02082BCC((void *)a, 0, 52);
    return 1;
}
return 0;
}













int func_0219131C(u32 a)
{
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
func_0219492C((u8 *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8), *(u8 *)((u8 *)(a) + 1));
func_021927E8((u32 *)(a + 12));
return func_02082BCC((void *)a, 0, 52);
}













u32 func_02191348(u32 *a, u32 b)
{
    u32 x = func_02194990(a[2], *((u8 *)a + 1));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)x)), 255);
    func_0219499C((u8 *)a[2], *((u8 *)a + 1), b, func_02193210((u8 *)(a[5] + 0x160)));
    return func_020409B4(func_02045730((struct Descriptor *)x));
}













u32 func_02191388(u32 *a)
{
    u32 h;
    u32 r;
    u32 w;
    u32 c;

    if (func_02194974((u8 *)a[2], *((u8 *)a + 1)) == 0) {
        return 0;
    }
    h = func_02194984(a[2], *((u8 *)a + 1));
    r = func_0201CE30((void *)h);
    func_02040618(1, 3, *(s16 *)((u8 *)a + 2));
    if (*(s16 *)((u8 *)a + 2) < 0) {
        *(s16 *)((u8 *)a + 2) += 2;
        if (*(s16 *)((u8 *)a + 2) > 0) {
            *(s16 *)((u8 *)a + 2) = 0;
        }
    }
    *(s16 *)((u8 *)a + 2) = -*(s16 *)((u8 *)a + 2);
    switch (r) {
    case 0:
        if (func_021927F8((u8 *)(a + 3)) == 1) {
            w = func_02194990(a[2], *((u8 *)a + 1));
            func_021927FC((struct Cur *)(a + 3), (u32)func_02045770((struct Descriptor *)w), 15);
            func_02045334((struct Descriptor *)w);
        }
        if (func_02193228((u8 *)(a[5] + 0x160)) != 0) {
            func_021932A0(h, 1);
        } else {
            func_021932A0(h, 0);
        }
        break;
    case 1:
        w = func_02194990(a[2], *((u8 *)a + 1));
        c = (u32)func_02045770((struct Descriptor *)w);
        if (func_0219320C((u8 *)(a[5] + 0x160)) == 0) {
            func_021928C0((struct Cur *)(a + 3), c, 15);
        }
        if (func_02193260((u8 *)(a[5] + 0x160), func_0201CE34((void *)h)) != 0) {
            if (func_0219320C((u8 *)(a[5] + 0x160)) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38((void *)h);
            func_021927FC((struct Cur *)(a + 3), c, 15);
            func_021932A0(h, 0);
        }
        func_02045334((struct Descriptor *)w);
        break;
    case 2:
        if (*(s16 *)((u8 *)a + 2) != 0) {
            *(s16 *)((u8 *)a + 2) = 0;
            func_02040618(1, 3, *(s16 *)((u8 *)a + 2));
        }
        return 1;
    }
    return 0;
}













void func_021914CC(S *s)
{
    u32 x;

    if (func_0219320C(s->f14 + 0x160) == 0) {
        x = func_02194990(s->f08, s->f01);
        func_021928C0((struct Cur *)s->sub, (u32)func_02045770((struct Descriptor *)x), 0xF);
        func_02045334((struct Descriptor *)x);
    }
}













void func_02191504(u16 *a, u32 *b, u32 c, u32 d, u16 e, u16 f, u32 g)
{
    a[3] = 11;
    b[4] = ((struct Obj00126 *)a)->f15C;
    func_02193170(a[0]);
    func_02193044(0);
    b[6] = func_02194A00(b[4], c, d, e, f, g);
    func_021927C0((struct G *)b, (struct Fx_0218E610 *)((struct Fx_0218E610 *)a));
}













R *func_02191558(Fx_0218E610 *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g)
{
    R *r;

    r = func_02030734(a->f00, 0x2C, 1, d_021DDA50, 0xCA7);
    r->f0c = a;
    r->f14 = b;
    r->f08 = (u32)func_020457B0(0xA0, a->f00);
    func_02191504((u16 *)a, (u32 *)r, d, e, f, g, c);
    if (c == 1)
        r->f28 = 8;
    return r;
}













int func_021915B4(void *a)
{
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C != 0) {
    func_02190D48((void *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20 != 0) {
    func_02190538((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    func_02045808((struct U16Vec *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
func_02194A48(((struct Obj00005 *)((u8 *)(a)))->f10, (struct Descriptor *)(((struct Obj00005 *)((u8 *)(a)))->f18));
func_021927E8((u32 *)a);
return func_020307B0(a);
}












void func_021915EC(R *r)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)r->f18)), 0xFF);
    func_020409B4((u8)r->f0c->f02);
}












void func_0219160C(int *p)
{
    func_02194A34(p[4], p[6]);
}












void func_0219161C(R *r, int b, int c, u32 d)
{
    if (r->f20 != 0)
        func_02190538(r->f20);
    r->f20 = func_021904EC((u32 *)r->f0c, r->f14, r->f18);
    func_02190550(r->f20, b, c, d);
}












void func_02191648(R *r, int b, int c, u32 d)
{
    if (r->f20 != 0)
        func_02190538(r->f20);
    r->f20 = func_021904EC((u32 *)r->f0c, 0, r->f18);
    func_02190590(r->f20, b, c, d);
}












void func_02191674(R *r, int b, int c, u32 d, u16 e)
{
    if (r->f20 != 0)
        func_02190538(r->f20);
    r->f20 = func_021904EC((u32 *)r->f0c, 0, r->f18);
    func_02190604(r->f20, b, c, d, e);
}












void func_021916A8(R *r, u32 b, u16 c, u32 d)
{
    if (r->f1c != 0)
        func_02190D48((void *)r->f1c);
    r->f1c = (u32)func_02190D2C((u32 *)r->f0c, d, r->f18, b, c, func_02193210((u8 *)r->f0c + 0x160));
}












u32 func_021916E0(u32 *a)
{
    u32 r;
    func_020362DC();
    func_0203630C();
    r = func_02190D5C((u32 *)a[7]);
    a[9] = func_0201CE30((void *)(*(u32 *)(a[7] + 4)));
    func_02040618(1, 3, ((struct Obj00005 *)a)->f28);
    if (((struct Obj00005 *)a)->f28 < 0) {
        ((struct Obj00005 *)a)->f28 += 2;
        if (((struct Obj00005 *)a)->f28 > 0) {
            ((struct Obj00005 *)a)->f28 = 0;
        }
    }
    ((struct Obj00005 *)a)->f28 = -((struct Obj00005 *)a)->f28;
    switch (r) {
    case 0:
        if (func_021927F8((u8 *)a) == 1) {
            func_021927FC((struct Cur *)a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            func_02045334((struct Descriptor *)a[6]);
        }
        break;
    case 1:
        if (func_0219320C((u8 *)(a[3] + 0x160)) == 0) {
            func_021928C0((struct Cur *)a, (u32)func_02045770((struct Descriptor *)a[6]), 15);
            func_02045334((struct Descriptor *)a[6]);
        }
        break;
    case 2:
        if (((struct Obj00005 *)a)->f28 != 0) {
            ((struct Obj00005 *)a)->f28 = 0;
            func_02040618(1, 3, ((struct Obj00005 *)a)->f28);
        }
        return 1;
    }
    return 0;
}











void func_02191794(R *r)
{
    if (func_0219320C((u8 *)r->f0c + 0x160) == 0) {
        func_021928C0((struct Cur *)r, (u32)func_02045770((struct Descriptor *)r->f18), 0xF);
        func_02045334((struct Descriptor *)r->f18);
    }
}










int func_021917C0(int *p)
{
    return p[9];
}











void func_021917C4(u16 *a, u32 *b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u32 i)
{
    a[3] = 11;
    b[3] = ((struct Obj03112 *)a)->f15C;
    b[2] = d;
    b[1] = i;
    func_02193170(a[0]);
    func_02193044(0);
    func_021947E8((u8 *)b[3], b[2], c, e, f, g, h, 0xFF, 0, func_02193210((u8 *)((u32)a + 0x15C + 4)), 2, 0);
    func_02194940((u8 *)b[3], b[2]);
}











/*
 * The margins are locals (mx = 2, my = 0): the `+ my` add is folded to a
 * move after coalescing, which is the original's `adds r0, r0, #0` at +0x22.
 * A literal `+ 0` folds early and loses it.
 *
 * Addresses are Black-image addresses.
 */
void func_02191830(Q *q, u32 a, u8 *w, u8 *h)
{
    u32 mx = 2, my = 0;
    u32 tw = func_0201D304((struct StrObj *)a, (int)q->f08, 0) + mx;
    u32 th = func_0201D42C((struct StrObj *)a, (void *)((int)q->f08)) + my;
    u32 m = tw;
    tw >>= 3;
    if (m & 7) tw++;
    m = th;
    th >>= 3;
    *w = tw;
    if (m & 7) th++;
    *h = th;
}










void func_02191870(Fx_0218E610 *a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h)
{
    O *o;
    int k;

    o = func_02030734(a->f00, 0x18, 1, d_021DDA50, 0xE2A);
    k = func_0219319C((u8 *)a, (u32)o);
    o->f00 = (u32)func_020457B0(0x40, a->f00);
    func_02045CAC((struct MsgBank *)b, c, (void *)o->f00);
    func_021917C4((u16 *)a, (u32 *)o, o->f00, (u16)(k + 3), e, f, g, h, d);
}










/* d is u8: its caller (0x021B11B6) truncates r3, and the narrow type is what
 * pins its home store to the front of the prologue. */
void func_021918DC(u16 *a, u32 b, u32 c, u8 d, u8 e, u8 f, u8 g)
{
    u32 *h;
    u32 t;

    h = (u32 *)func_02030734(*a, 0x18, 1, d_021DDA50, 0xE48);
    t = func_0219319C((u8 *)a, (u32)h);
    h[0] = (u32)func_020457B0(func_020458F8((struct U16Vec *)b) + 1, *a);
    func_02045838((struct U16Vec *)h[0], (struct U16Vec *)b);
    func_021917C4(a, h, h[0], (u16)(t + 3), d, e, f, g, c);
}








int func_0219194C(void *a)
{
if (((struct Obj07210 *)((u8 *)(a)))->f0 != 0) {
    func_02045808((struct U16Vec *)(((struct Obj07210 *)((u8 *)(a)))->f0));
}
func_0219492C((u8 *)(((struct Obj07210 *)((u8 *)(a)))->fC), ((struct Obj07210 *)((u8 *)(a)))->f8);
return func_020307B0(a);
}







void func_0219196C(u32 a, u32 b)
{
    func_0219194C(func_021931C4((u8 *)a, b));
}






void func_02191978(P_0219129C *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->arr[i] != 0) {
            p->arr[i] = 0;
            {
                u32 t = p->arr[i];
                p->arr[i] = 0;
                func_0219194C((void *)t);
            }
        }
    }
}







int func_021919AC(u8 *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((u32 *)(p + 0xA0))[i] != 0)
            return 1;
    }
    return 0;
}







int func_021919C8(struct Q *q){
    if (func_02194974((u8 *)q->f0c, (int)q->f08) == 0)
        return 0;
    func_020362DC();
    func_0203630C();
    switch (func_0201CE30((void *)func_02194984(q->f0c, (u32)q->f08))) {
    case 0:
    case 1:
        break;
    case 2:
        return 1;
    }
    return 0;
}







/*
 * Tail call passing the object, a pass-through argument and the word at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_02191A04(u8 *p, int a)
{
    func_02191A10((u16 *)p, a, ((struct Obj17935 *)p)->f8);
}







u32 *func_02191A10(u16 *a, u32 b, u32 c)
{
    u32 *p;
    u8 x;
    u8 y;
    u8 w;
    u8 h;

    p = (u32 *)func_02030734(a[0], 0x34, 1, d_021DDA50, 0xee0);
    p[0] = (u32)a;
    p[12] = c;
    p[7] = -48;
    func_02040618((u8)a[1], 0, 0);
    func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
    p[1] = func_020450F0((u8)a[1], 2, 0x13, 0x1c, 4, 9, 1);
    p[2] = (u32)func_02043678(0x1c, 4, 0x20, a[0]);
    p[3] = (u32)func_02043678(0x1c, 4, 0x20, a[0]);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[1])), 15);
    func_02045374((struct Cfg *)p[1]);
    func_02045334((struct Descriptor *)p[1]);
    func_02191D88(a[1], 9, b, a[0]);
    x = func_02045758((struct Descriptor *)p[1]);
    y = func_02045760((struct Descriptor *)p[1]);
    w = func_02045738((struct Descriptor *)p[1]);
    h = func_02045740((struct Descriptor *)p[1]);
    func_02191DC8((u8)a[1], x, y, w, h, 0x33, 9);
    func_020409B4((u8)a[1]);
    func_021927C0((struct G *)(p + 10), (struct Fx_0218E610 *)((struct Fx_0218E610 *)p[0]));
    a[3] = 11;
    func_02193044(0);
    return p;
}







void func_02191B14(u32 *a)
{
    u8 x;
    u8 y;
    u8 w;
    u8 h;

    func_02045770((struct Descriptor *)a[1]);
    x = func_02045758((struct Descriptor *)a[1]);
    y = func_02045760((struct Descriptor *)a[1]);
    w = func_02045738((struct Descriptor *)a[1]);
    h = func_02045740((struct Descriptor *)a[1]);
    func_02191FA0((u8)((u16 *)a[0])[1], x, y, w, h, 0, 15);
    func_020456F8((struct Descriptor *)a[1]);
    x = func_02045758((struct Descriptor *)a[1]);
    y = func_02045760((struct Descriptor *)a[1]);
    w = func_02045738((struct Descriptor *)a[1]);
    h = func_02045740((struct Descriptor *)a[1]);
    func_02041300((u8)((u16 *)a[0])[1], 0, x, y, w, h, 0x11);
    func_02045334((struct Descriptor *)a[1]);
    func_020452E8((struct Descriptor *)a[1]);
    func_020409B4((u8)((u16 *)a[0])[1]);
    func_02040618((u8)((u16 *)a[0])[1], 3, 0);
    func_020437AC((struct Obj020437AC *)a[3]);
    func_020437AC((struct Obj020437AC *)a[2]);
    if (a[5] != 0) {
        func_02045808((struct U16Vec *)a[5]);
    }
    func_021927E8(a + 10);
    func_020307B0(a);
}







u32 func_02191BE8(u32 *p, u32 b)
{
    switch (p[6]) {
    case 0:
        p[4] = b;
        p[5] = (u32)func_020457B0(func_020458F8((struct U16Vec *)b) + 2, *(u16 *)p[0]);
        func_0219214C((u32)func_02045770((struct Descriptor *)p[1]), p[12], p[4], p[5], p + 9, 15);
        func_02045334((struct Descriptor *)p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        p[6]++;
        break;
    case 1:
        *(int *)&p[7] += 12;
        if (*(int *)&p[7] >= 0) {
            p[7] = 0;
            p[6]++;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        break;
    case 2:
        if (func_02192138(p[4], p[5], p[9]) == 1) {
            p[6] = 5;
            break;
        }
        p[6]++;
    case 3:
        if ((func_020362DC() & 3) == 0) {
            func_021928C0((struct Cur *)(p + 10), (u32)func_02045770((struct Descriptor *)p[1]), 15);
            func_02045334((struct Descriptor *)p[1]);
            break;
        }
        func_021927FC((struct Cur *)(p + 10), (u32)func_02045770((struct Descriptor *)p[1]), 15);
        func_02043814((struct Bmp *)((u32)func_02045770((struct Descriptor *)p[1])), (const struct Bmp *)p[3]);
        func_0219214C(p[2], p[12], p[4], p[5], p + 9, 15);
        p[8] = 0;
        func_020061E4(0x547);
        p[6]++;
    case 4:
        if (func_021921C8((struct Bmp *)func_02045770((struct Descriptor *)p[1]), (struct Bmp *)p[3], (struct Bmp *)p[2], p[8], 15) == 1) {
            p[6] = 2;
        } else {
            p[8] += 4;
        }
        func_02045334((struct Descriptor *)p[1]);
        func_020409B4((u8)((u16 *)p[0])[1]);
        break;
    case 5:
        if ((func_020362DC() & 0xf3) == 0) {
            break;
        }
        p[6]++;
    case 6:
        *(int *)&p[7] -= 12;
        if (*(int *)&p[7] <= -48) {
            p[7] = -48;
        }
        func_02040618((u8)((u16 *)p[0])[1], 3, p[7]);
        if (*(int *)&p[7] == -48) {
            p[6]++;
            return 1;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}





void func_02191D88(u32 a, u32 b, u32 c, u32 d)
{
    if (c >= 4)
        c = 0;
    func_02049624(5, 6, a, 0x33, 0, 0, d);
    func_02049B90(5, 1, 0, c << 5, b << 5, 0x20, d);
}





void func_02191DC8(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal)
{
    func_02041300(layer, tile, x - 2, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 1, x - 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 2, x, y - 1, w, 1, pal);
    func_02041300(layer, tile + 4, x + w, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 5, x + w + 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile + 6, x - 2, y, 1, h, pal);
    func_02041300(layer, tile + 7, x - 1, y, 1, h, pal);
    func_02041300(layer, tile + 10, x + w, y, 1, h, pal);
    func_02041300(layer, tile + 11, x + w + 1, y, 1, h, pal);
    func_02041300(layer, tile + 12, x - 2, y + h, 1, 1, pal);
    func_02041300(layer, tile + 13, x - 1, y + h, 1, 1, pal);
    func_02041300(layer, tile + 14, x, y + h, w, 1, pal);
    func_02041300(layer, tile + 16, x + w, y + h, 1, 1, pal);
    func_02041300(layer, tile + 17, x + w + 1, y + h, 1, 1, pal);
}





void func_02191FA0(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal)
{
    func_02041300(layer, tile, x - 2, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x - 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x, y - 1, w, 1, pal);
    func_02041300(layer, tile, x + w, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x + w + 1, y - 1, 1, 1, pal);
    func_02041300(layer, tile, x - 2, y, 1, h, pal);
    func_02041300(layer, tile, x - 1, y, 1, h, pal);
    func_02041300(layer, tile, x + w, y, 1, h, pal);
    func_02041300(layer, tile, x + w + 1, y, 1, h, pal);
    func_02041300(layer, tile, x - 2, y + h, 1, 1, pal);
    func_02041300(layer, tile, x - 1, y + h, 1, 1, pal);
    func_02041300(layer, tile, x, y + h, w, 1, pal);
    func_02041300(layer, tile, x + w, y + h, 1, 1, pal);
    func_02041300(layer, tile, x + w + 1, y + h, 1, 1, pal);
}





int func_02192138(u32 a, u32 b, u32 c)
{
if (func_0201D37C((struct StrObj *)a, (struct StrObj *)b, c) == 0) {
    return 1;
}
return 0;
}





int func_0219214C(u32 a, u32 b, u32 c, u32 d, u32 *cnt, u8 col)
{
    int y;

    func_02043B5C((struct CharBuf *)a, col);
    if (func_0201D37C((struct StrObj *)c, (struct StrObj *)d, *cnt) == 0)
        return 1;
    func_0201C7A4((void *)a, 1, 1, (void *)d, (void *)b);
    y = 1;
    y += func_0201D42C((struct StrObj *)d, (void *)b) + 1;
    if (func_0201D37C((struct StrObj *)c, (struct StrObj *)d, ++*cnt) == 0)
        return 1;
    func_0201C7A4((void *)a, 1, y, (void *)d, (void *)b);
    ++*cnt;
    return 0;
}





int func_021921C8(struct Bmp *a, struct Bmp *b, struct Bmp *c, int n, u16 col)
{
    int w;
    int h;

    w = func_020437DC(a);
    h = func_020437E4(a);
    func_02043B5C((struct CharBuf *)a, col);
    if (n > h)
        n = h;
    func_020439A0(b, a, 0, n, 0, 0, w, h - n, col);
    func_020439A0(c, a, 0, 0, 0, h - n, w, n, col);
    if (n >= h) return 1;
    return 0;
}





void func_02192244(u32 unused, u32 a, u32 b)
{
    func_02049B90(5, 2, 0, 0, a * 32, 0x20, b);
}




void func_02192264(u32 a, u32 unused, u32 heap, u32 idx)
{
    enum { Z } i = Z;
    u8 *src;
    void *buf;
    CharData *cd;

    src = func_020437D4((const struct Bmp *)a);
    buf = (void *)func_0204A1BC(5, 8, 0, heap);
    func_02062A4C(buf, (void **)(&cd));
    func_02082EA4(cd->raw + i * 32 + idx * 32, src, 0x20);
    func_020307B0(buf);
}




static inline void blit(u32 tmp, u32 bmp, u16 x, u16 y)
{
    func_020439A0((struct Bmp *)tmp, (struct Bmp *)bmp, 0, 0, x * 8, y * 8, 8, 8, 0xFFFF);
}




/*
 * Nine-slice frame: loads each frame tile into an 8x8 scratch bitmap with
 * func_02192264 and blits it over the centre, the four edges and the four
 * corners of the target bitmap.
 *
 * Addresses are Black-image addresses.
 *
 * The edge loops use u16 locals truncated at their definition from the
 * CSE'd int w-1 / h-1 (spilled); the corners reuse the loop counters i
 * and j as the x/y tile positions, assigned before each tile load, so the
 * u16 truncation is scheduled ahead of the func_02192264 call.
 */
void func_021922A4(u32 bmp, u32 b, u32 heap)
{
    u16 w;
    u16 j;
    u16 h;
    u16 i;
    u32 tmp;
    u16 hm1;
    u16 wm1;

    w = func_020437DC((const struct Bmp *)bmp) >> 3;
    h = func_020437E4((const struct Bmp *)bmp) >> 3;
    tmp = (u32)func_02043678(1, 1, 0x20, heap);

    func_02192264(tmp, b, heap, 9);
    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
            blit(tmp, bmp, i, j);

    func_02192264(tmp, b, heap, 1);
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, 0);

    func_02192264(tmp, b, heap, 0x11);
    hm1 = h - 1;
    for (i = 0; i < w; i++)
        blit(tmp, bmp, i, hm1);

    func_02192264(tmp, b, heap, 8);
    for (i = 0; i < h; i++)
        blit(tmp, bmp, 0, i);

    func_02192264(tmp, b, heap, 0xA);
    wm1 = w - 1;
    for (i = 0; i < h; i++)
        blit(tmp, bmp, wm1, i);

    func_02192264(tmp, b, heap, 0);
    blit(tmp, bmp, 0, 0);
    i = w - 1;
    func_02192264(tmp, b, heap, 2);
    blit(tmp, bmp, i, 0);
    i = h - 1;
    func_02192264(tmp, b, heap, 0x10);
    blit(tmp, bmp, 0, i);
    i = w - 1;
    j = h - 1;
    func_02192264(tmp, b, heap, 0x12);
    blit(tmp, bmp, i, j);

    func_020437AC((struct Obj020437AC *)tmp);
}




void func_021924F0(u16 a, u16 b, u32 c, u32 d, u32 e, u16 f)
{
    int i;
    u32 h;
    int t;

    t = func_0201DC80((struct Font *)d) + 2;
    h = (u32)func_020457B0(func_020458F8((struct U16Vec *)e) + 1, f);
    for (i = 0; func_0201D37C((struct StrObj *)e, (struct StrObj *)h, i) == 1; i++) {
        func_0201C7A4((void *)c, (s16)a, (s16)b, (void *)h, (void *)d);
        b += (u16)t;
    }
    func_02045808((struct U16Vec *)h);
}




u32 *func_02192570(u16 *a, u32 b, u32 c, u16 d, u16 e, u16 f)
{
    u32 *t;

    t = (u32 *)func_02030734(*a, 0x18, 1, d_021DDA50, 0x115D);
    t[2] = (u32)a;
    t[0] = func_020450F0((u8)a[1], (u8)c, (u8)d, (u8)e, (u8)f, 9, 1);
    t[3] = (u32)func_02043678(1, 1, 0x20, *a);
    func_02192264(t[3], b, *a, 9);
    func_021922A4((u32)func_02045770((struct Descriptor *)t[0]), b, *a);
    func_02192244(a[1], 9, *a);
    func_02045374((struct Cfg *)t[0]);
    func_02045334((struct Descriptor *)t[0]);
    func_020409B4((u8)a[1]);
    func_021927C0((struct G *)(t + 4), (struct Fx_0218E610 *)a);
    a[3] = 0xB;
    func_02193044(0);
    return t;
}




void func_02192628(u32 *a)
{
    u8 x;
    u8 y;
    u8 w;
    u8 h;

    func_020456F8((struct Descriptor *)a[0]);
    x = func_02045758((struct Descriptor *)a[0]);
    y = func_02045760((struct Descriptor *)a[0]);
    w = func_02045738((struct Descriptor *)a[0]);
    h = func_02045740((struct Descriptor *)a[0]);
    func_02041300((u8)((u16 *)a[2])[1], 0, x, y, w, h, 0x11);
    func_02045334((struct Descriptor *)a[0]);
    func_020409B4((u8)((u16 *)a[2])[1]);
    func_021927E8(a + 4);
    func_020437AC((struct Obj020437AC *)a[3]);
    func_020452E8((struct Descriptor *)a[0]);
    func_020307B0(a);
}




void func_0219269C(T_0218E610 *t, u16 b, u16 c, u32 d)
{
    Fx_0218E610 *x = t->f08;

    func_021924F0(b, c, (u32)func_02045770((struct Descriptor *)t->f00), x->f08, d, x->f00);
    func_02045334((struct Descriptor *)t->f00);
    func_020409B4((u8)t->f08->f02);
}




int func_021926D8(U *u)
{
    u32 v = func_020362DC();
    func_0203630C();
    if (v & 3)
        return 1;
    func_021928F8((u8 *)u->sub, (u32)func_02045770((struct Descriptor *)u->f00), u->f0c);
    func_02045334((struct Descriptor *)u->f00);
    return 0;
}




u32 func_0219270C(Q *q, int a, int n)
{
    u32 x;
    u32 r;

    x = n * 2 + func_0201D304((struct StrObj *)a, (int)q->f08, 0);
    r = x >> 3;
    if (x & 7)
        r++;
    return r;
}




u32 func_0219272C(u16 *a, u32 b, u32 c)
{
    u32 n;
    u32 h;
    u32 i;

    n = c * 2 + func_0201D42C((struct StrObj *)b, (void *)(((struct Obj12612 *)a)->f8));
    h = (u32)func_02045874((struct U16Vec *)b, *a);
    i = 0;
    if (func_0201D37C((struct StrObj *)b, (struct StrObj *)h, 0) == 1) {
        while (++i < 0x18 && func_0201D37C((struct StrObj *)b, (struct StrObj *)h, i) == 1)
            ;
    }
    func_02045808((struct U16Vec *)h);
    n += (i - 1) * 2;
    if (n & 7)
        n += 8;
    return n >> 3;
}




G *func_02192788(Fx_0218E610 *a)
{
    G *g = func_02030734(a->f00, 8, 1, d_021DDA50, 0x1202);
    func_021927C0(g, a);
    return g;
}




void func_021927B0(u8 *p)
{
    func_021927E8((u32 *)p);
    ENV_SetResourceSet(p);
}




void func_021927C0(struct G *g, struct Fx_0218E610 *a){
    func_02082BCC(g, 0, 8);
    g->f04 = (u32)func_020436FC((void *)(((struct Obj19604 *)(*(u8 * *)&((struct Obj00126 *)a)->f178))->f14), 1, 1, 0x20, a->f00);
}




/*
 * Clears the leading byte and tail calls on the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021927E8(u32 *p)
{
    ((struct Obj12068 *)p)->f0 = 0;
    func_020437AC((struct Obj020437AC *)p[1]);
}




u8 func_021927F8(u8 *p)
{
    return ((struct Obj17936 *)p)->f0;
}




void func_021927FC(struct Cur *c, u32 win, u32 col){
    Tri t = d_021D3E50;
    u16 x;
    u16 y;

    x = func_020437DC((const struct Bmp *)win) - 8;
    y = func_020437E4((const struct Bmp *)win) - 8 - t.v[c->f01];
    func_02043AF4((struct Bmp *)win, (s16)x, (s16)y, (u16)8, (u16)8, (u8)col);
    c->f00 = 0;
}
