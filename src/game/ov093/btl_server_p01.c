/*
 * file:     btl_server_p01.c
 * unit:     yes
 * function: func_021B8CB0, func_021B8CE8, func_021B8CFC, func_021B8D08, func_021B8D38, func_021B8D8C, func_021B8DC0, func_021B8DDC, func_021B8DE4, func_021B8DEC, func_021B8E28, func_021B8E70, func_021B8ED8, func_021B8F38, func_021B8F5C, func_021B8F7C, func_021B8FC0, func_021B8FE4, func_021B8FF4, func_021B9000, func_021B9010, func_021B902C, func_021B904C, func_021B9064, func_021B9090, func_021B90BC, func_021B90E8, func_021B90F0, func_021B90F8, func_021B9114, func_021B911C, func_021B9120, func_021B916C, func_021B917C, func_021B9184, func_021B919C, func_021B91E4, func_021B9210, func_021B9234, func_021B9244, func_021B92A0, func_021B92B0, func_021B92D4, func_021B9358, func_021B937C, func_021B93E0, func_021B9424, func_021B9460, func_021B9634, func_021B9674, func_021B969C, func_021B97A0, func_021B985C, func_021B9864, func_021B98A4, func_021B98AC, func_021B990C, func_021B9920, func_021B9934, func_021B9940, func_021B994C, func_021B997C, func_021B99B8, func_021B99C0, func_021B99E0, func_021B99F0, func_021B9A00, func_021B9A24, func_021B9A40, func_021B9A50, func_021B9A5C, func_021B9A6C, func_021B9AB0, func_021B9AC8, func_021B9AE0, func_021B9AEC, func_021B9AF8, func_021B9B04, func_021B9B10, func_021B9B40, func_021B9B54, func_021B9B60, func_021B9B94, func_021B9B98, func_021B9BC4, func_021B9BF0, func_021B9C00, func_021B9C10, func_021B9C24, func_021B9C50, func_021B9C98, func_021B9CBC, func_021B9CE8, func_021B9D10, func_021B9DB8, func_021B9DE8, func_021B9E38, func_021B9E7C, func_021B9EF0, func_021B9F70, func_021B9F84, func_021B9FAC, func_021B9FBC, func_021BA004, func_021BA020, func_021BA02C, func_021BA064, func_021BA080, func_021BA08C, func_021BA094, func_021BA0CC, func_021BA128, func_021BA178, func_021BA1A8, func_021BA1B4, func_021BA1CC, func_021BA1E4, func_021BA1EC, func_021BA20C, func_021BA238, func_021BA250, func_021BA2D4, func_021BA2E4, func_021BA534, func_021BA54C, func_021BA5C4, func_021BA5D0, func_021BA5D8, func_021BA618, func_021BA648, func_021BA670, func_021BA698, func_021BA6C0, func_021BA710, func_021BA73C, func_021BA7F8, func_021BA820, func_021BA82C, func_021BA878, func_021BA9C8, func_021BAA94, func_021BAACC, func_021BAB10, func_021BAB40, func_021BAB5C, func_021BAB9C, func_021BABDC, func_021BABEC, func_021BABF4, func_021BAC04, func_021BACAC, func_021BAE60, func_021BAEF8, func_021BB040, func_021BB0A0, func_021BB0E0, func_021BB208, func_021BB280, func_021BB320, func_021BB368, func_021BB3B0, func_021BB3F8, func_021BB43C, func_021BB484, func_021BB4E0, func_021BB56C, func_021BB570, func_021BB5FC, func_021BB628, func_021BB650, func_021BB6A8, func_021BB718, func_021BB724, func_021BB768, func_021BB798, func_021BB7D0, func_021BB7FC, func_021BB828, func_021BB830, func_021BB840, func_021BB848, func_021BB85C, func_021BB878, func_021BB890, func_021BB8A8, func_021BB8B0, func_021BB8BC, func_021BB8DC, func_021BB908, func_021BB914, func_021BB920, func_021BB930, func_021BB964, func_021BB968, func_021BB9D0, func_021BB9D8, func_021BBB48, func_021BBB60, func_021BBC34, func_021BBC44, func_021BBCD4, func_021BBD20, func_021BBD2C, func_021BBD80, func_021BBD8C, func_021BBFA8, func_021BC0E8, func_021BC220, func_021BC2B0, func_021BC310, func_021BC360, func_021BC390, func_021BC3B0, func_021BC418, func_021BC4DC, func_021BC550, func_021BC55C, func_021BC568, func_021BC610, func_021BC874, func_021BC8EC, func_021BC948, func_021BCA08, func_021BCA50, func_021BCAAC, func_021BCB14, func_021BCB68, func_021BCB98, func_021BCC50, func_021BCCE0, func_021BCEFC, func_021BCF34, func_021BCF70, func_021BCFAC, func_021BD080, func_021BD0C0, func_021BD148, func_021BD170, func_021BD1B0, func_021BD1D0, func_021BD1E0, func_021BD200, func_021BD2B4, func_021BD338, func_021BD34C, func_021BD3E8, func_021BD43C, func_021BD4E4, func_021BD518, func_021BD554, func_021BD584, func_021BD60C, func_021BD6B8, func_021BD708, func_021BD850, func_021BD8AC, func_021BD8F0, func_021BD9D4, func_021BDA00
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
 *   func_021BDC98 0x021BDC98 thumb ov093
 *   func_021C5200 0x021C5200 thumb ov093
 *   func_021C4614 0x021C4614 thumb ov093
 *   func_021C6158 0x021C6158 thumb ov093
 *   func_021BDC2C 0x021BDC2C thumb ov093
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
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021BDE98 0x021BDE98 thumb ov093
 *   func_021CB730 0x021CB730 thumb ov093
 *   func_021C54BC 0x021C54BC thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021C85B8 0x021C85B8 thumb ov093
 *   func_02018480 0x02018480 thumb
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021B85A0 0x021B85A0 thumb ov093
 *   func_02018488 0x02018488 thumb
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021BDE48  0x021BDE48  thumb  ov093
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
 *   func_021BDBEC 0x021BDBEC thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021BDB58 0x021BDB58 thumb ov093
 *   func_021BDB68 0x021BDB68 thumb ov093
 *   func_021BDB88 0x021BDB88 thumb ov093
 *   func_021BDB78 0x021BDB78 thumb ov093
 *   func_021BDC0C 0x021BDC0C thumb ov093
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
extern void func_021BDC98(Server *p, u8 *a, u8 v);
extern int func_021C5200(Server *p);
extern void func_021C4614(Server *p);
extern void func_021C6158(Server *p, u8 *a);
extern void func_021BDC2C(Server *p);
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
extern void func_021C0780(Server *, u8 *, int, u8);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern void func_021BDE98(Server *, u8 *, Action *, u32);
extern int func_021CB730(Server *, u8 *, u16, u8, u8);
extern void func_021C54BC(Server *, u8 *);
extern void func_021C60EC(Server *p, u8 *a, u32 n);
extern void func_021C85B8(Server *);
extern int func_021B871C(char *);
extern int func_02018480(void *, int);
extern u8 func_021B85A0(u8 **p);
extern void func_021D7630(int key, u32 val);
extern u16 func_021BDE48(void *p, Action *m);
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
extern void func_021BDBEC(Server *);
extern int func_021C88E4(Server *);
extern void func_021BDB58(void *);
extern u8 *func_021BDB68(void *);
extern void func_021BDB88(Server *, u8 *);
extern u8 *func_021BDB78(void *);
extern void func_021BDC0C(Server *);
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
int func_021BD170(Server *p, u8 x);
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
extern const u8 data_021EFCF0[4];
extern u8 d_021EFCF4[2][3];
extern u8 d_021EFCFA[2][3];
extern struct Unk021EFD70 data_021EFD70[];
extern u8 d_021F3A60[];
extern u8 d_021F3A70[];









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







int func_021BD170(Server *p, u8 x)
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
