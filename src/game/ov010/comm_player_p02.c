/*
 * file:     comm_player_p02.c
 * unit:     yes
 * function: func_02167BFC, func_02167CB4, func_02167CF4, func_02167D00, func_02167D44, func_02167DB8, func_02167DEC, func_02167E28, func_02167E54, func_02167E88, func_02167EAC, func_02167ED0, func_02167EF4, func_02167FB4, func_021680C8, func_02168174, func_021681C8, func_021684E8, func_0216869C, func_02168800, func_0216880C, func_02168824, func_0216883C, func_02168878, func_021688BC, func_02168924, func_02168AC8, func_02168AEC, func_02168B18, func_02168B20, func_02168BBC, func_02168BF0, func_02168C74, func_02168CF4, func_02168D30, func_02168E5C, func_02168EB0, func_02168EEC, func_02168F54, func_02169004, func_02169068, func_021690A4, func_021690B4, func_021690D0, func_021690E0, func_021690F0, func_02169100, func_02169110, func_02169120, func_02169138, func_02169148, func_0216928C, func_02169308, func_0216932C, func_02169354, func_0216937C, func_021693A0, func_021693B4, func_021693BC, func_021693C4, func_021693CC, func_021693D4, func_0216940C, func_02169444, func_02169470, func_021694D4, func_021694F8, func_021694FC, func_02169500, func_02169510, func_02169520, func_02169528, func_02169530, func_02169538, func_02169540, func_02169550, func_02169560, func_02169568, func_02169578, func_02169580, func_02169598, func_0216959C, func_021695BC, func_02169620, func_0216968C, func_02169710, func_021697E0, func_02169800, func_02169848, func_02169880, func_0216990C, func_02169928, func_02169998, func_021699A0, func_02169A14, func_02169A68, func_02169A88, func_02169AB8, func_02169E0C, func_02169E4C, func_02169E98, func_02169EA4, func_02169EBC, func_02169F34, func_02169FB8, func_02169FFC, func_0216A07C, func_0216A0BC, func_0216A128, func_0216A148, func_0216A184, func_0216A1C0, func_0216A1F8, func_0216A21C, func_0216A244, func_0216A264, func_0216A280, func_0216A298, func_0216A2EC, func_0216A358, func_0216A390, func_0216A3F8, func_0216A420, func_0216A440, func_0216A470, func_0216A4CC, func_0216A510, func_0216A560, func_0216A594, func_0216A5C4, func_0216A5FC, func_0216A634, func_0216A674, func_0216A6B4, func_0216A6EC, func_0216A72C, func_0216A774, func_0216A7A0, func_0216A838, func_0216A884, func_0216A8F0, func_0216AAE4, func_0216ABD8, func_0216AC40, func_0216AC90, func_0216ACCC, func_0216AD1C, func_0216AD70, func_0216AE10, func_0216AED0, func_0216AEE8, func_0216AF1C, func_0216AF3C, func_0216AF74, func_0216B004
 * address:  0x02167BFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02167B44  0x02167B44  thumb
 *   func_02167B9C  0x02167B9C  thumb
 *   func_02167BB4  0x02167BB4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02167BCC  0x02167BCC  thumb
 *   func_02167BD8  0x02167BD8  thumb
 *   func_02167BE4  0x02167BE4  thumb
 *   func_02167BF0  0x02167BF0  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02039338  0x02039338  arm
 *   func_02082D44 0x02082D44 arm
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201A364 0x0201A364 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02188C54  0x02188C54  thumb ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0219129C  0x0219129C  thumb ov021
 *   func_02191388  0x02191388  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb
 *   func_021912F8  0x021912F8  thumb
 *   func_02045808  0x02045808  arm
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013644  0x02013644  thumb
 *   func_02013734  0x02013734  thumb
 *   func_02013810  0x02013810  thumb
 *   func_02013980  0x02013980  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02017528  0x02017528  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0202428C  0x0202428C  thumb
 *   func_0201394C  0x0201394C  thumb
 *   d_02172A2C     0x02172A2C  data
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020186C8  0x020186C8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02019C90  0x02019C90  thumb
 *   sub_02045B38   0x02045B38  arm
 *   func_02045F5C  0x02045F5C  arm
 *   d_02172084     0x02172084  data
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185B0  0x020185B0  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02018430  0x02018430  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   g_0217208C  0x0217208C  data  ov010  a2
 *   g_0217208E  0x0217208E  data  ov010  a2
 *   func_02188CCC  0x02188CCC  thumb ov021
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012158  0x02012158  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_021A0F7C  0x021A0F7C  thumb ov021
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0216E910 0x0216E910 thumb ov010
 *   func_02008550  0x02008550  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_02012444 0x02012444 thumb
 *   d_021BA39C 0x021BA39C data ov220 a4
 *   ov220_id 0x000000DC data
 *   func_02008B14  0x02008B14  thumb
 *   func_0203F49C  0x0203F49C  arm
 *   func_02008BE0  0x02008BE0  thumb
 *   func_02089004  0x02089004  arm
 *   func_02088F58  0x02088F58  arm
 *   _ll_sdiv       0x0209BE5C  arm
 *   func_0201296C  0x0201296C  thumb
 *   func_020143F0  0x020143F0  thumb
 *   func_0200D440  0x0200D440  thumb
 *   func_0201B100  0x0201B100  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008E30  0x02008E30  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200952C  0x0200952C  thumb
 *   func_021862A8  0x021862A8  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E518  0x0200E518  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200AB04  0x0200AB04  thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3C0 0x0200C3C0 thumb
 *   func_020113F0  0x020113F0  thumb
 *   func_0203F524 0x0203F524 arm
 *   func_02008BD0  0x02008BD0  thumb
 *   sub_02030734   0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   d_02172A40     0x02172A40  data
 *   g_020A8140     0x020A8140  data
 *   g_020A8148     0x020A8148  data
 *   d_020A814C     0x020A814C  data   a4
 *   d_020A8144     0x020A8144  data   a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049238  0x02049238  arm
 *   func_0204944C  0x0204944C  arm
 *   sub_02046C9C  0x02046C9C  arm
 *   func_02046C9C 0x02046C9C arm
 *   func_020493D4  0x020493D4  arm
 *   func_020495F4  0x020495F4  arm
 *   func_0206A9DC  0x0206A9DC  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0206AA0C  0x0206AA0C  arm
 *   func_0206A854  0x0206A854  arm
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_02047C8C  0x02047C8C  arm
 *   d_0217216C     0x0217216C  data   ov010  a4
 *   d_02172178     0x02172178  data   ov010  a4
 *   d_02148C08     0x02148C08  data   a4
 *   d_02148BCC     0x02148BCC  data   a4
 *   d_02172160     0x02172160  data   ov010  a4
 *   d_02148B98     0x02148B98  data   a4
 *   func_02047788  0x02047788  arm
 *   func_0204755C  0x0204755C  arm
 *   VEC_Add        0x0207C9D0  arm
 *   MTX_RotY33_    0x0207AF1C  thumb
 *   tbl_020A1B38   0x020A1B38  data
 *   g_02148B98     0x02148B98  data
 *   func_0207CA00  0x0207CA00  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E954  0x0206E954  arm
 *   func_0206E964  0x0206E964  arm
 *   func_0206A2CC  0x0206A2CC  arm
 *   func_0206A4AC  0x0206A4AC  arm
 *   func_02069D14  0x02069D14  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *   func_0204932C 0x0204932C arm
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A1518  0x021A1518  thumb  ov021
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1554  0x021A1554  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A0FB4  0x021A0FB4  thumb  ov021
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02006254  0x02006254  thumb
 *   func_0203101C  0x0203101C  arm
 *   d_02172A50     0x02172A50  data
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020450F0  0x020450F0  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020310C4  0x020310C4  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021904A8  0x021904A8  thumb  ov021
 *   func_02027F60  0x02027F60  thumb
 *   func_02027FD8   0x02027FD8  thumb
 *   func_0202784C  0x0202784C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3208  0x021A3208  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A2F54  0x021A2F54  thumb
 *   func_021A3244   0x021A3244  thumb  ov021
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 *   func_02017988  0x02017988  thumb
 *   func_02011400  0x02011400  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012F50  0x02012F50  thumb
 *   func_021D096C  0x021D096C  thumb
 *   func_021D0A48   0x021D0A48  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0A74  0x021D0A74  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021D0AC0  0x021D0AC0  thumb  ov021
 *   func_021D0BD8  0x021D0BD8  thumb  ov021
 *   func_021D0AB8  0x021D0AB8  thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008E68 0x02008E68 thumb
 *   func_02008E78  0x02008E78  thumb
 *   func_021D0BE4  0x021D0BE4  thumb  ov021
 *   func_021D0DB0  0x021D0DB0  thumb  ov021
 *   func_021D0FE0  0x021D0FE0  thumb
 *   func_021D0FE8  0x021D0FE8  thumb  ov021
 *   func_021D1028  0x021D1028  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   FX_SinCosTable_  0x020A1B38  data
 *   _ll_mul          0x0209C054  arm
 *   _u32_div_f       0x0209C2B0  arm
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021664CC  0x021664CC  thumb  ov010
 *   func_0217C37C  0x0217C37C  thumb  ov018
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0217C294  0x0217C294  thumb  ov018
 *   func_0200E18C  0x0200E18C  thumb
 *   func_0216628C  0x0216628C  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EE84  0x0201EE84  thumb
 *   func_021767A0  0x021767A0  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_02166618  0x02166618  thumb  ov010
 *   func_0216662C  0x0216662C  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021767F0  0x021767F0  thumb  ov011
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_021665F0  0x021665F0  thumb  ov010
 *   func_0216B3A8  0x0216B3A8  thumb  ov010
 *   func_0215901C 0x0215901C thumb ov010
 *   func_0217C274 0x0217C274 thumb ov018
 *   func_0217C2A0   0x0217C2A0  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217688C  0x0217688C  thumb  ov011
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0200E2BC  0x0200E2BC  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0200873C  0x0200873C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021B6100  0x021B6100  thumb  ov098
 *   func_021B6158  0x021B6158  thumb  ov098
 *   func_021B95A0  0x021B95A0  thumb  ov227
 *   func_021B95C8  0x021B95C8  thumb  ov227
 *   ov098_id       0x00000062  data
 *   ov227_id       0x000000E3  data
 *   d_021B6D74     0x021B6D74  data ov098
 *   d_021B98A4     0x021B98A4  data ov227
 */
#include "../../matched/include/Obj00116.h"
#include "../../matched/include/Obj09320.h"
#include "../../matched/include/Obj07315.h"
#include "../../matched/include/Obj12375.h"
#include "../../matched/include/Obj12376.h"
#include "../../matched/include/Obj12377.h"
#include "../../matched/include/Obj07204.h"
#include "../../matched/include/Obj09162.h"
#include "../../matched/include/Obj12052.h"
#include "../../matched/include/Obj04944.h"
#include "../../matched/include/Obj17735.h"
#include "../../matched/include/Obj17736.h"
#include "../../matched/include/Obj17737.h"
#include "../../matched/include/Obj17738.h"
#include "../../matched/include/Obj17739.h"
#include "../../matched/include/Obj17740.h"
#include "../../matched/include/Obj12384.h"
#include "../../matched/include/Obj04162.h"
#include "../../matched/include/Obj03541.h"
#include "../../matched/include/Obj00306.h"
#include "../../matched/include/Obj19036.h"
#include "../../matched/include/Obj12053.h"
#include "../../matched/include/Obj19037.h"
#include "../../matched/include/Obj19038.h"
#include "../../matched/include/Obj19039.h"
#include "../../matched/include/Obj19040.h"
#include "../../matched/include/Obj05901.h"
#include "../../matched/include/Obj12385.h"
#include "../../matched/include/Obj17742.h"
#include "../../matched/include/Obj17743.h"
#include "../../matched/include/Obj17744.h"
#include "../../matched/include/Obj19043.h"
#include "../../matched/include/Obj19045.h"
#include "../../matched/include/Obj19047.h"
#include "../../matched/include/Obj00281.h"
#include "../../matched/include/Obj19049.h"
#include "../../matched/include/Obj17745.h"
#include "../../matched/include/Obj19050.h"
#include "../../matched/include/Obj19051.h"
#include "../../matched/include/Obj09322.h"
#include "../../matched/include/Obj05902.h"
#include "../../matched/include/Obj19055.h"
#include "../../matched/include/Obj07317.h"
#include "../../matched/include/Obj12387.h"
#include "../../matched/include/Obj12388.h"
#include "../../matched/include/Obj17746.h"
#include "../../matched/include/Obj04164.h"
#include "../../matched/include/Obj02337.h"
#include "../../matched/include/Obj00029.h"
#include "../../matched/include/Obj17747.h"
#include "../../matched/include/Obj19072.h"
#include "../../matched/include/Obj19073.h"
#include "../../matched/include/Obj04885.h"
#include "../../matched/include/Obj09164.h"
#include "../../matched/include/Obj17748.h"
#include "../../matched/include/Obj17749.h"
#include "../../matched/include/Obj17750.h"
#include "../../matched/include/Obj17751.h"
#include "../../matched/include/Obj17752.h"
#include "../../matched/include/Obj17753.h"
#include "../../matched/include/Obj17754.h"
#include "../../matched/include/Obj17755.h"
#include "../../matched/include/Obj12054.h"
#include "../../matched/include/Obj17756.h"
#include "../../matched/include/Obj17757.h"
#include "../../matched/include/Obj17758.h"
#include "../../matched/include/Obj17760.h"
#include "../../matched/include/Obj03543.h"

#define F(o) (*(u32 *)((char *)p + (o)))
#define QB (*(u8 **)(p + 0x18))
#define H (*(u32 *)(QB + 0x10))
#define ST (*(u32 *)(QB + 0x20))
struct Entry;
struct Blk37;
struct Ctx;
struct Desc;
struct Obj;
struct SeqWork;
struct Evt;
struct Party;
struct PartyMon;
struct BigObj;
struct ModelObj;
struct Ent_02167BFC;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Actor;
struct VecFx32;
struct Strbuf;
struct BattleMon;
struct Obj02013734;
struct RecDC;
struct Sav;
struct ZoneData;
struct MsgData;
struct Mon;
struct Comm;
struct IcaAnime;
struct Big;
struct Bs;
struct Sub0200852CObj;
struct Sub02008AECSession;
struct RtcDate;
struct RtcTime;
struct RTCDate;
struct RTCTime;
struct Tally;
struct Rec0200AB04;
struct Sub02009470Obj;
struct Blk34;
struct ArcFile;
struct P02047C8C;
struct Tagged;
struct Sub020071E4Ctrl;
struct Sub02008C20Obj;
struct Tcbl;
struct WordSet;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Rec3;
struct PrintSys;
struct R;
struct TaskMenuState;
struct TaskMenu;
struct Orbit;
struct LinkRecord;
struct Record_02168CF4;
struct Obj00020;
struct MsgWork;
struct P;
struct Sub02008700Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent_02167BFC {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent_02167BFC;

typedef struct Work_02167BFC {
    void *sys;
    void *obj;
    Ent_02167BFC e[4];
} Work_02167BFC;

typedef struct CommPlayer {
    u8 pad00[9];
    u8 b09;
    u8 pad0a[1];
    u8 b0b;
    union {
        struct {
            u16 low : 3;
            u16 flag : 1;
            u16 high : 12;
        } a;
        struct {
            u16 lo : 5;
            u16 hi : 3;
            u16 rest : 8;
        } b;
    } bits0c;
    u8 pad0e[4];
    u16 h12;
    u8 pad14[4];
    u16 h18;
    u16 h1a;
    u16 h1c;
    u8 b1e[2];
    u8 pad20[2];
    u16 h22;
    u16 h24;
    u8 pad26[0x32 - 0x26];
    u8 b32[0x668 - 0x32];
    union {
        u32 w668;
        struct {
            u16 h668;
            u16 h66a[2];
            u16 h66e;
        } h;
        u8 b668[0x20];
    } v668;
    u8 pad688[0x724 - 0x688];
    u8 b724;
    u8 b725;
    u8 pad726[2];
    u16 h728;
} CommPlayer;

typedef struct 
{
  u8 pad0[8];
  int f8;
  u8 fc;
  u8 fd;
  u8 fe;
  u8 ff;
  u8 f10;
  u8 pad11[7];
  int f18;
} T;

typedef struct 
{
  u8 pad0[0x14];
  u8 *f14;
  u8 pad18[0x1c];
  int f34;
  int f38;
} Q;

typedef struct 
{
  int f0;
  int f4;
  int f8;
  u8 padc[0x30 - 0xc];
  int f30;
  u8 pad34[0xc8 - 0x34];
  u8 buf[0x184 - 0xc8];
  int f184;
  int f188;
  int f18c;
  int f190;
  int f194;
} P;

typedef struct SeqWork {
    u32 heap;           /* 0x000 */
    void *arg;          /* 0x004 */
    u8 f08[0x28];       /* 0x008 */
    u8 f30[0x3C];       /* 0x030 */
    u32 f6c;            /* 0x06C */
    u32 f70;            /* 0x070 */
    u8 pad74[5];
    u8 order[6];        /* 0x079 */
    u8 pad7F[0x105];
    u32 *out184;        /* 0x184 */
    u32 *out188;        /* 0x188 */
    u8 *order18c;       /* 0x18C */
    void *party190;     /* 0x190 */
    void *party194;     /* 0x194 */
} SeqWork;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u16 f1a;
    u8 pad1c[0x120 - 0x1c];
} E_02167BFC;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} R_02167BFC;

typedef signed int s32_02167BFC;

struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

typedef struct BattleMon {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    union {
        u32 ivs;        /* 0x14 */
        struct {
            u32 hpIv : 5;
            u32 atkIv : 5;
            u32 defIv : 5;
            u32 speIv : 5;
            u32 spaIv : 5;
            u32 spdIv : 5;
            u32 ivRest : 2;
        } b;
    } iv;
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 ability;         /* 0x20 */
    u8 friendship;      /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 nature;          /* 0x38 */
} BattleMon;

typedef struct FacRec {
    u16 species;        /* 0x00 */
    u16 moves[4];       /* 0x02 */
    u8 evMask;          /* 0x0A */
    u8 nature;          /* 0x0B */
    u16 item;           /* 0x0C */
    u16 form;           /* 0x0E */
} FacRec;

typedef struct FacGroup {
    u16 id;             /* 0x00 */
    u16 count;          /* 0x02 */
    u16 members[1];     /* 0x04 */
} FacGroup;

typedef struct FacDraw {
    u32 otId;           /* 0x00 */
    u16 ids[2];         /* 0x04 */
    u32 pids[2];        /* 0x08 */
    u8 natures[2];      /* 0x10 */
} FacDraw;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    u8 f8[16];
    u16 f18;
    u16 f1a;
    u8 pad1c[0x30 - 0x1c];
    BattleMon mons[4];
} Blk;

typedef struct { u16 v[8]; } W8;

typedef enum { SIDE_0, SIDE_1, SIDE_2, SIDE_3 } Side;

typedef struct Rec {
    u32 f00;
    u16 f04;
    u8 pad06[2];
    u8 f08[0x18];
    W8 w20;
    BattleMon mons[4];
} Rec;

typedef struct Spr {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    struct Strbuf *f14;
    W8 w18;
} Spr;

typedef struct Bs {
    u8 pad00[0x22];
    u8 f22;
    u8 pad23;
    struct Party *f24[4];
    u8 *f34[4];
    u8 pad44[4];
    Spr *f48[4];
} Bs;

typedef enum { ST_0, ST_1, ST_2, ST_3, ST_4, ST_5 } State;

typedef struct {
    void *f0;
    void *f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    void *f18;
    void *f1c;
    u32 pad[4];
    int f30;
} R_021688BC;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    u32 f30;
} C;

typedef enum { KIND_OFF = 0x12c } Offset;

typedef struct Record_02168CF4 {
    u8 pad[0x124];
    int count;
    void *save;
    Offset kind;
} Record_02168CF4;

typedef struct Result {
    u8 pad00[0x24];
    void *party;        /* 0x24 */
    u8 pad28[0xB4 - 0x28];
    u16 fb4;            /* 0xB4 */
    u8 fb6[11];         /* 0xB6 */
} Result;

typedef struct Record_02168D30 {
    u8 pad000[0x134];
    u16 f134[10];       /* 0x134 */
    u16 f148;           /* 0x148 */
    u16 f14a;           /* 0x14A */
} Record_02168D30;

typedef struct { u32 a, b, c, d; } Date;

typedef struct { u32 a, b, c; } Time;

typedef struct {
    int f0;
    Date date;
    Time time;
    int f20;
} A;

typedef long long s64;

typedef struct Cfg {
    u32 size;           /* 0x00 */
    u32 texSize;        /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
    u16 nA;             /* 0x14 */
    u16 nB;             /* 0x16 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
} Cfg;

typedef struct Node {
    u32 f00;
    u32 f04;
} Node;

typedef struct Mgr {
    u8 pad00[0x10];
    u32 f10;            /* 0x10 */
    u8 pad14[0x1C - 0x14];
    u32 size;           /* 0x1C */
    u32 texSize;        /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
    Node *head;         /* 0x2C */
    Node node;          /* 0x30 */
    u8 pad38[0x84 - 0x38];
    void *f84;          /* 0x84 */
    void *f88;          /* 0x88 */
    u32 texKey;         /* 0x8C */
    u32 plttKey;        /* 0x90 */
    u32 f94;            /* 0x94 */
    u8 pad98[4];
    void *listA;        /* 0x9C */
    void *listB;        /* 0xA0 */
    u16 nA;             /* 0xA4 */
    u16 nB;             /* 0xA6 */
    u32 fA8;            /* 0xA8 */
    u32 fAC;            /* 0xAC */
    u8 padB0[0xD4 - 0xB0];
    void *buf;          /* 0xD4 */
    u32 fD8;            /* 0xD8 */
} Mgr;

typedef void (*Cb)(u8 *, u32);

typedef struct V3 {
    u32 a, b, c;
} V3;

typedef signed short   s16_02167BFC;

typedef signed char    s8;

typedef struct {
u32 f0;
u32 f4;
u32 f8;
u32 fc;
u16 f10;
u16 pad;
} Entry;

typedef struct {
u8 pad0[0x9c];
Entry *table;
u32 f_a0;
u16 count;
} Obj;

typedef struct E_0216932C
{
  int key;
  int a;
  int b;
  int c;
} E_0216932C;

typedef struct S12 { u32 a, b, c; } S12;

typedef struct S_021695BC {
    u16 pad0;
    u16 busy;
    u8 pad4[0x0c];
    u32 h;
    u8 pad14[0x10];
    u32 n;
    u8 pad28[0x8c];
    u32 cur;
    u32 len;
    u32 tot;
    u8 padc0[0x14];
    u32 base;
} S_021695BC;

typedef struct S_02169620 {
    u8 pad0[0x10];
    u32 h;
    u8 pad14[0x10];
    u32 n;
    u8 pad28[0x8c];
    u32 cur;
    u32 len;
    u32 tot;
    u8 padc0[0x14];
    u32 base;
} S_02169620;

typedef short s16_0216959C;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct Mtx43 {
    int m[9];
    Vec t;
} Mtx43;

typedef struct Res_0216959C {
    void *f00;
    void *f04;
} Res_0216959C;

typedef struct ResTbl {
    Res_0216959C *tbl;
    u32 count;
} ResTbl;

typedef struct Ent_0216959C {
    u32 idx;        /* 0x00 */
    Vec pos;        /* 0x04 */
    u16 angle;      /* 0x10 */
    u16 pad12;
} Ent_0216959C;

typedef struct ModelObj {
    u32 f00;
    Vec pos;        /* 0x04 */
    char pad10[0x98 - 0x10];
    ResTbl *res;    /* 0x98 */
    Ent_0216959C *ents;      /* 0x9C */
    char padA0[4];
    u16 nents;      /* 0xA4 */
} ModelObj;

typedef void (*Cb_02169800)(void *a, u32 b, u32 *c, u32 d, u32 e);

typedef void (*Cb_02169848)(void *,u32,u32 *,u32,u32);

typedef struct E {
    int a;
    int b;
    int c;
    int d;
    u16 e;
} E;

typedef signed short s16_021699A0;

typedef struct Res_02167BFC {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
    u8 *f44;            /* 0x44 */
    u8 pad48[0x4C - 0x48];
    u32 f4C;            /* 0x4C */
} Res_02167BFC;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res_02167BFC *f18;           /* 0x18 */
} Work;

typedef struct Slot {
    void *f00;
    u8 f04;
} Slot;

typedef struct Res_0216A07C {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res_0216A07C;

typedef struct Desc {
    u32 heap;           /* 0x00 */
    u8 f04;             /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0C;            /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 f11;             /* 0x11 */
    u8 f12;             /* 0x12 */
    u8 f13;             /* 0x13 */
} Desc;

typedef struct {
    int a;
    int b;
    int c;
} Vec3;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    void *f8;
    Vec3 v;
} S_0216A7A0;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    int f8;
    Vec3 v;
} S_0216A838;

typedef short s16_0216A560;

typedef int s32_0216A560;

typedef s32_0216A560 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Orbit {
    u32 count;          /* 0x00 */
    void *obj;          /* 0x04 */
    VecFx32 pos;        /* 0x08 */
} Orbit;

typedef struct {
    u32 lo : 6;
    u32 mid : 12;
    u32 hi : 6;
    u32 rest : 8;
} Bits_02167BFC;

typedef struct {
    u32 lo : 11;
    u32 pad : 12;
    u32 f : 6;
    u32 rest : 3;
} Bits_0216ACCC;

typedef struct Key {
    u32 species : 11;
    u32 pad0 : 12;
    u32 form : 6;
    u32 pad1 : 3;
} Key;

typedef struct MsgWork {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 f10[0x10];       /* 0x10 */
    Key f20;            /* 0x20 */
    u16 f24;            /* 0x24 */
    u8 pad26[2];
    u16 *f28;           /* 0x28 */
} MsgWork;

typedef signed int     s32;

extern void func_02167B44(CommPlayer *o, void *t);
extern void func_02167B9C(CommPlayer *o);
extern void func_02167BB4(CommPlayer *o, u32 v);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *a, void *b);
extern void func_02167BCC(CommPlayer *o);
extern void func_02167BD8(CommPlayer *o, u32 v);
extern void func_02167BE4(CommPlayer *o, u32 v);
extern void func_02167BF0(CommPlayer *o, u32 v);
extern u32 func_0200FB24(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u16 func_02039338(void);
extern void func_02082D44(void *, void *, unsigned int);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0201A364(int a, unsigned int b);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200CA1C(void *a);
extern void func_02082BCC(void *, int, int);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_0201AA14(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_02188C54(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern struct Ent_02167BFC *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern int func_02191388();
extern u32 func_020362DC(void);
extern int func_021912D8();
extern int func_021912F8();
extern int func_02045808();
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void *func_02013090(u32 heap);
extern void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02013810(u8 *o, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u32 a6, u16 a7);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern void func_0201A954(struct Party *p, s32_02167BFC capacity);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02017528(struct Sav *p);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern u32 func_020307B0(void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0202428C(void *p);
extern void func_0201394C(struct ZoneData *o);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020185B0(void *p, u32 v);
extern u16 func_02045A98(void);
extern u32 func_02018430(void *p);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020056EC(u32 range);
extern int func_0209C2B0();
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045A38(struct U16Vec *, u16 *, u32);
extern u32 func_02188CCC(u8 *p);
extern unsigned int func_02012138(const struct Ctx *);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_02012158(char *p, unsigned int v);
extern u32 func_020121CC(struct IcaAnime *p);
extern int func_021A0F7C(u32 a, u32 b, u32 c, u32 d);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern int func_0216E910(void *, void *, void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0200E8F8(void *sys);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_0203F49C(struct RtcDate *date, struct RtcTime *time);
extern void func_02008BE0(struct Sub02008AECSession *s, u32 n);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern s32_02167BFC func_02088F58(struct RTCDate *date);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_020143F0(u8 *a);
extern void func_0200D440(void *sys);
extern void func_0201B100(void *, int);
extern void *func_02012F2C(int *p);
extern void func_02008E30(void *a0);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void func_0200952C(struct Sub02009470Obj *obj);
extern void func_021862A8(int, int, int);
extern void *func_0200E394(void *a0);
extern void func_0200E518(struct Tally *t);
extern void *func_0200A8A0(void *sys);
extern void func_0200AB04(struct Rec0200AB04 *o);
extern void *func_0201AD0C(void *sys);
extern u8 func_02012984(const struct BigObj *p);
extern void *func_0200C0F0(void *sys);
extern void func_0200C3C0(struct Blk34 *p, u16 v);
extern int func_020113F0(int row, int col);
extern u64 func_0203F524(void);
extern int func_02008BD0(const struct Sub02008AECSession *s);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02046C94(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *arc);
extern void func_0204944C(struct ArcFile *h, u32 b, u32 c, u32 d, void *out);
extern void sub_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern void func_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void func_0206A9DC(void *p);
extern void func_02082B60(void *a, void *b);
extern void func_0206AA0C(void *p);
extern void func_0206A854(void);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_02047C8C(struct P02047C8C *p);
extern int func_02047788(int *p);
extern int func_0204755C(int *p);
extern void  VEC_Add(const Vec *a, const Vec *b, Vec *dst);
extern void  MTX_RotY33_(void *m, s16_0216959C sinv, s16_0216959C cosv);
extern void func_0207CA00(u32 c, void *p, u32 *out);
extern void *func_02046F48(struct Tagged *p);
extern int func_0206E954(int p0);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_0206A2CC(void *a, void *b);
extern void func_0206A4AC(void *a, void *b);
extern void func_02069D14(void *a, void *b);
extern void func_0206DB80(void);
extern int func_0207DEA4(s32_02167BFC *in);
extern void func_0204932C(struct ArcFile *,u32,void *);
extern int func_021A0F30(u32 a, u32 b);
extern int func_021A0ED4(u32 a);
extern int func_021A1518(u32 *p);
extern void func_021A1524(u32 *p);
extern int func_021A1554(u32 *p);
extern void func_021A1530(u32 *p);
extern void func_021A1548(u32 *p);
extern int func_021A153C(u32 *p);
extern void func_021A0FB4(u32 *p, u32 a);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);
extern u32 func_0201C440(void *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void func_0201F7A8(void *p, u32 kind);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern int func_02012DAC(int a0);
extern int func_02012DD0(u8 *p);
extern void func_0202F038(u8 *p);
extern void func_020061E4(u32 a);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_02006254(u32 a);
extern int func_0201C4C0();
extern int func_02028604(int a0);
extern int func_02031140();
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern int func_0201F5BC();
extern int func_02049B40();
u32 func_020452E8(struct Descriptor *d);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_021904AC(u8 *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32_02167BFC v);
extern void func_0201CE38(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02035C60(void);
extern unsigned int func_0203630C(void);
extern int func_020310C4();
extern int func_020286C4();
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_021904A8(u32 *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern int func_0202784C(int a0, int a1);
extern int func_02027974();
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern int func_02027858();
extern void *func_02188CB4(unsigned char *p);
extern int func_021A3208();
extern void *func_021A3074(unsigned char *p);
extern int func_021A2F48();
extern char *func_0216DB04(void *a0);
extern u32 *func_0216D550(u32 *p, u32 v);
extern int func_021A2F54();
extern int func_021A3244(void *);
extern void *func_021D1164(u32 heap, u32 v);
extern int func_021D11B0();
extern int func_021D11D8();
extern int func_021D1194();
extern void func_02017988(void *mon, u16 form);
extern u8 func_02011400(int row, int col);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void *func_0215A5DC(void *a0);
extern void *func_02012F50(void *base);
extern void *func_021D096C(void *a);
extern void func_021D0A48(void *, void *);
extern void *func_0215A5F4(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_021D0A74();
extern u16 *func_02159AE8(void *a0, void *a1);
extern void func_0215897C(void *a, void *b);
extern u16 func_021D0AC0();
extern int func_021D0BD8(u32 a, u32 b, u32 c, u32 d);
extern int func_021D0AB8();
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void func_02008E68(struct Sub02008C20Obj *obj, u32 value);
extern u8 func_02008E78(struct Sub02008C20Obj *obj);
extern void *func_021D0BE4(void *a, u8 *b, u16 *c);
extern void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore);
extern int func_021D0FE0();
extern void *func_021D0FE8(void *a, int unused, int c);
extern int func_021D1028();
extern void *func_0215A5E4(void *a0);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D89C();
extern u16 func_0215A5CC(void *a0);
extern struct LinkRecord *func_021664CC(u16 heap, void *sys, u32 *start);
extern void func_0217C37C();
extern void *func_0200E0B0(void *p);
extern int func_0217C294(char *a0);
extern int func_0200E18C();
extern int func_0216628C(u32 *obj, u32 slot);
extern void *func_02158F74(void *p);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern u8 func_021767A0(void *a, void *b);
extern int func_02012FB0(unsigned char *base);
extern int func_02166618(int a0);
extern int func_0216662C(int a0);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021767F0();
extern void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);
extern int func_021665F0(int a0, int a1, int a2);
extern struct Desc *func_0216B3A8(int a0, int a1, int a2);
extern u32 func_0215901C(void *, void *, u32);
extern void func_0217C274(unsigned int *out, char *p);
extern int func_0217C2A0(int, void *, void *);
extern int func_02158344(int a0);
extern int func_0217688C();
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode);
extern void *func_020124E4(struct Obj *p);
extern void *func_02029BCC(void *a, u32 b);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *func_0200CA10(void *sv);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void *func_02029C00(void *h);
extern void *func_02029CC0(void *h);
extern int func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern struct P *func_021B6100(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap);
extern int func_021B6158(void *p);
extern void *func_021B95A0(u32 a, int b, u32 c, u32 heap);
extern void func_021B95C8(void *p);
void func_02167BFC(CommPlayer *o, u32 cmd, u32 arg);
int func_02167CB4(CommPlayer *o);
void func_02167CF4(CommPlayer *w, u8 v);
int func_02167D00(CommPlayer *o, u16 *out);
void func_02167D44(int a, int b, const u16 *c, CommPlayer *d);
void func_02167DB8(u16 a, int b, void *c, CommPlayer *p);
void func_02167DEC(u16 a, int b, u16 *c, CommPlayer *p);
void func_02167E28(u16 a, int b, void *c, CommPlayer *p);
void func_02167E54(u16 a, int b, u16 *c, CommPlayer *p);
void func_02167E88(u16 a, int b, u16 *c, CommPlayer *p);
void func_02167EAC(u16 a, int b, u16 *c, CommPlayer *p);
void func_02167ED0(u16 a, int b, u16 *c, CommPlayer *p);
int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
int func_02167FB4(void *evt, u32 *seq, SeqWork *w);
int func_021680C8(int a, E_02167BFC *b, int c, int d);
int func_02168174(int a0, int a1, int a2);
Bs *func_021681C8(void *sys, void *partyA, u32 mode0, Rec *recA, Rec *recB, int n);
u32 func_021684E8(BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
void func_0216869C(const BattleMon *src, void *mon);
void func_02168800(void *dst, u32 member);
void *func_0216880C(u32 group, u32 heap);
int func_02168824(void);
u8 func_0216883C(u32 n);
int func_02168878(Blk *a, u16 b, int c, u16 *d, u16 *e, FacDraw *f, u16 g);
FacGroup *func_021688BC(Blk *a, int b, int c);
int func_02168924(FacGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, FacDraw *draw, u16 heap);
int func_02168AC8(int a0);
u16 func_02168AEC(u16 a0);
void func_02168B18(int *p);
int func_02168B20(int a, int *b, int *c);
void *func_02168BBC(void *a, void *b);
struct Desc *func_02168BF0(int a, int b, int c, int d, u16 *e);
int func_02168C74(int a, int *b, C *c);
int func_02168CF4(void *a, Record_02168CF4 *p);
void func_02168D30(Record_02168D30 *r, Result *s);
int func_02168E5C(int a, int b, int c);
int func_02168EB0(void *a, int *state);
void func_02168EEC(int a);
int func_02168F54(A *a, Date *b, Time *c, int *d, int *e);
void func_02169004(int a, int b);
void func_02169068(int a,int b,Time *c);
void *func_021690A4(int a0);
int func_021690B4(int a0);
int func_021690D0(int a0);
int func_021690E0(int a0);
int func_021690F0(int a0);
int func_02169100(int a0);
int func_02169110(int a0);
void func_02169120(void *p);
int func_02169138(int a0);
Mgr *func_02169148(const Cfg *cfg, u32 heap);
void func_0216928C(void *p);
void func_02169308(u8 *p);
int func_0216932C(int a0);
int func_02169354(int a0, int a1);
void func_0216937C(u8 *p,int a,int b);
void func_021693A0(int a0);
void func_021693B4(char *p, int v);
void func_021693BC(char *p);
void func_021693C4(char *p, int v);
void func_021693CC(char *p);
void func_021693D4(u8 *base, u8 *src, u32 idx);
void func_0216940C(Obj *o, u32 i);
u32 *func_02169444(u8 *base, u32 idx);
void func_02169470(u8 *p, u32 b);
void func_021694D4(u8 *p, int a1);
void func_021694F8(u8 *p, u16 v);
u16 func_021694FC(u8 *p);
void func_02169500(u8 *p, u8 *q);
void func_02169510(u8 *src, V3 *dst);
int func_02169520(int a0, int a1);
void func_02169528(unsigned char *a, int *out);
void func_02169530(unsigned char *a, int *out);
void func_02169538(unsigned char *a, int *out);
void func_02169540(unsigned char *a, unsigned int v);
void func_02169550(char *p);
int func_02169560(unsigned char *a);
void func_02169568(char *p);
int func_02169578(unsigned char *a);
void func_02169580(int a0);
u32 func_02169598(u8 *p);
void func_0216959C(u8 *p);
void func_021695BC(S_021695BC *p, int b);
int func_02169620(S_02169620 *p);
int func_0216968C(u8 *p);
void func_02169710(ModelObj *obj, int unused);
int func_021697E0(char *p);
void func_02169800(void *a, char *b, u32 c, u32 d);
void func_02169848(void *a,u8 *b,u32 c,u32 d);
void func_02169880(u8 *p);
void func_0216990C(u8 *p);
void func_02169928(void *a, void *b, void *c);
int func_02169998(int a0, int a1);
int func_021699A0(void *p);
u32 func_02169A14(u32 a);
void *func_02169A68(int a0);
void func_02169A88(u8 *p,u32 n);
int func_02169AB8(Work *w, u32 *state);
int func_02169E0C(char *a0);
void func_02169E4C(int a0);
int func_02169E98(char *p);
void func_02169EA4(Work *w, u32 n);
void func_02169EBC(Work *w);
int func_02169F34(u8 *p);
int func_02169FB8(int a0);
void func_02169FFC(Work *w, u32 msg);
int func_0216A07C(Work *w);
void func_0216A0BC(Work *w);
void func_0216A128(void *p);
void func_0216A148(Work *w);
int func_0216A184(int a0);
int func_0216A1C0(int a0);
void func_0216A1F8(int a0);
int func_0216A21C(int a0);
int func_0216A244(void *a0);
int func_0216A264(int a0);
int func_0216A280(int a0);
void func_0216A298(void *a, void *list);
int func_0216A2EC(int a0, int a1, int a2, int *a3, int a4);
int func_0216A358(int a,int b,u32 *p,int c);
void func_0216A390(int a0, int a1);
int func_0216A3F8(int a0, int a1);
int func_0216A420(void *a0, void *a1);
int func_0216A440(int a0, int a1);
int func_0216A470(int a0, int a1);
int func_0216A4CC(int a0, int a1);
int func_0216A510(int a0, int a1);
int func_0216A560(int a0, int a1);
int func_0216A594(int a0, int a1);
int func_0216A5C4(void *a,void *b);
int func_0216A5FC(int a0, int a1);
int func_0216A634(int a0, int a1);
int func_0216A674(int a0, int a1);
int func_0216A6B4(int a0, int a1);
int func_0216A6EC(int a0, int a1);
int func_0216A72C(int a0, int a1);
int func_0216A774(int a0, int a1);
int func_0216A7A0(int a0, int a1);
int func_0216A838(int a0, int a1, S_0216A838 *p);
int func_0216A884(int a0, int a1);
int func_0216A8F0(void *unused, u32 *mode, Orbit *o);
void func_0216AAE4(void *sys, void *party, int season);
int func_0216ABD8(int a0, int a1);
int func_0216AC40(int a0, int a1);
int func_0216AC90(int a0, int a1);
int func_0216ACCC(int a0, int a1);
int func_0216AD1C(int a0, int a1, int a2, int a3);
int func_0216AD70(int a0, int a1);
int func_0216AE10(int a0, int a1);
void *func_0216AED0(void *p, u32 id);
void func_0216AEE8(int vm, int *out);
int func_0216AF1C(void *a0, void *a1, int a2, int *a3);
void func_0216AF3C(int a0);
struct Desc *func_0216AF74(int a0, int a1, int a2, int a3, u16 *a4, u16 a5);
int func_0216B004(void *evt, u32 *state, MsgWork *w);
extern const char d_02172A2C[];
extern const u16 d_02172084[];
extern u16 g_0217208C[];
extern u16 g_0217208E[];
extern const unsigned int d_021BA39C[];
extern unsigned char ov220_id[];
extern const char d_02172A40[];
extern u8 d_0217216C[];
extern u8 d_02172178[];
extern u8 d_02148C08[];
extern struct {
    u8 pad[0x7c];
    u32 f7c;
} d_02148BCC;
extern u8 d_02172160[];
extern u8 d_02148B98[];
extern s16_0216959C tbl_020A1B38[];
extern char g_02148B98[];
extern const char d_02172A50[];
extern const s16_0216A560 FX_SinCosTable_[];
extern u8 ov098_id[];
extern u8 ov227_id[];
extern u8 d_021B6D74[];
extern u8 d_021B98A4[];













/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void func_02167BFC(CommPlayer *o, u32 cmd, u32 arg)
{
    void *t;

    t = ((struct Obj00116 *)o)->f6C;
    switch (cmd) {
    case 0:
        o->h12 = 0x2C00;
        func_02167B44(o, t);
        return;
    case 1:
        o->h12 = 0x2C01;
        func_02167B9C(o);
        return;
    case 2:
        o->h12 = 0x2C02;
        func_02167BB4(o, arg);
        return;
    case 3:
        o->h12 = 0x2C03;
        func_02008494(func_02012944(t), o->v668.b668);
        return;
    case 4:
        o->h12 = 0x2C04;
        func_02167BCC(o);
        return;
    case 5:
        o->h12 = 0x2C05;
        func_02167BD8(o, arg);
        return;
    case 6:
        o->h12 = 0x2C06;
        func_02167BE4(o, arg);
        return;
    case 7:
        o->h12 = 0x2C07;
        func_02167BF0(o, arg);
        return;
    default:
        o->h12 = 0x2C08;
        return;
    }
}













int func_02167CB4(CommPlayer *o)
{
    u16 h;

    if (func_0200FB24() != 0)
        return 1;
    h = o->h12;
    if (h >= 0x2C08)
        return 1;
    if (func_0203D3A8(func_020399A8(), h, 0x46, (u32)o->v668.b668) == 1)
        return 1;
    return 0;
}














/*
 * Byte setter at +0x725. bl from ov021 func_021CA5C4 at 0x021CB596.
 */
void func_02167CF4(CommPlayer *w, u8 v)
{
    w->b725 = v;
}














int func_02167D00(CommPlayer *o, u16 *out)
{
    int want;

    if (func_0200FB24() != 0)
        return 1;
    want = 1;
    if (o->b725 != 1)
        want = 2;
    if (o->b724 == want) {
        o->b724 = 0;
        if (out != 0)
            *out = o->h728;
        return 1;
    }
    return 0;
}














/*
 * lever: Const source halfwords restores c[0]/c[1] load scheduling.
 */
void func_02167D44(int a, int b, const u16 *c, CommPlayer *d)
{
    u16 n = 0;
    u16 w;
    u16 v;
    d->b724++;
    if (a != func_02039338()) {
        w = c[0];
        v = c[1];
        d->b0b = w;
        d->h1a = v;
        d->h1c = c[2];
        d->h18 = c[3];
        d->bits0c.b.hi = d->b0b + 5;
        if (d->h22 == v || d->h22 == d->h1c)
            n += 1;
        if (d->h24 == v || d->h24 == d->h1c)
            n += 2;
        d->h728 = n;
    }
}













void func_02167DB8(u16 a, int b, void *c, CommPlayer *p)
{
    p->b724++;
    if (a != func_02039338() && func_02039338() != 0)
        func_02082D44(c, p->b32, 0x1c);
}













void func_02167DEC(u16 a, int b, u16 *c, CommPlayer *p)
{
    p->b724++;
    if (a != func_02039338()) {
        p->h728 = 0;
        if ((p)->bits0c.a.flag != 0 || *c != 0)
            p->h728 = 1;
    }
}













void func_02167E28(u16 a, int b, void *c, CommPlayer *p)
{
    p->b724++;
    if (a != func_02039338())
        func_02082D44(c, (u8 *)p + 0x72c, 0x20);
}













void func_02167E54(u16 a, int b, u16 *c, CommPlayer *p)
{
    p->b724++;
    if (a != func_02039338()) {
        if (p->b09 != *c)
            p->h728 = 0;
        else
            p->h728 = 1;
    }
}













void func_02167E88(u16 a, int b, u16 *c, CommPlayer *p)
{
    p->b724++;
    if (a != func_02039338())
        p->h728 = *c;
}













void func_02167EAC(u16 a, int b, u16 *c, CommPlayer *p)
{
    p->b724++;
    if (a != func_02039338())
        p->h728 = *c;
}













void func_02167ED0(u16 a, int b, u16 *c, CommPlayer *p)
{
    p->b724++;
    if (a != func_02039338())
        p->h728 = *c;
}













/*
 * lever: named temporaries keep Q+0x30 live across0201A364; bounded permuter47 compiles found byte-correct192.
 * Interface evidence: ov019_func_0217BA10.c records r0->r2, r1->r0, r1=0x69, jump via02048F4C. Original caller supplies d in r0 and p->buf in r1.
 * TU: MATCH192,9/10 relocations; suggest-split leaves sole function OUT.
 * checks: 1 020124E8 takes live hd from122C0, own matched accessor reads+0xc; 2 family/neighbours reread, no full twin; 3 unsigned b/c each retain31 before search; 4 pointer-copy idiom read; 5 neighbours/idioms reread, frame is scalar spills, no stack aggregate.
 * permuter: once budget300 types, emitted baseline agreed31/192; stopped at47 with MATCH; fixed one confirmsMATCH192.
 */
int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
  P *p;
  Q *q;
  T *t;
  int r7;
  int s;
  int hd;
  int x;
  Q *tmp1;
  u8 *tmp2;
  P *tmp3;
  u8 tmp;
  x = (int)func_0201210C((const struct Ctx *)a);
  hd = (int)func_020122C0((void *)a, 0, func_02167FB4, 0x198);
  tmp3 = func_020124E8((struct Obj *)hd);
  p = tmp3;
  q = (Q *) p;
  p->f0 = a;
  p->f4 = x;
  p->f18c = f;
  p->f188 = g;
  p->f184 = h;
  p->f190 = e;
  tmp2 = ((u8 *) q) + 0x30;
  p->f194 = i;
  tmp1 = (Q *) tmp2;
  func_0201A364(d, (unsigned int)p->buf);
  q = tmp1;
  p->f30 = e;
  q->f14 = p->buf;
  q->f38 = b;
  q->f34 = c;
  t = (T *) (((u8 *) p) + 8);
  r7 = (int)func_020120F4((const struct Ctx *)a);
  s = (int)func_0200CA1C((void *)r7);
  func_02082BCC(t, 0, 0x28);
  p->f8 = e;
  t->fc = 1;
  tmp = func_0201AA18((void *)e);
  t->fe = tmp;
  t->fd = 0;
  t->f10 = 0;
  t->f8 = r7;
  t->f18 = func_0200CA38((struct Blk37 *)s);
  return hd;
}














/*
 * Sub-process sequence: runs five child processes one after another
 * (two from ov021, three from arm9), copying the result of the fifth
 * back and re-adding the chosen party members.
 *
 * First draft plus one lever (2026-09-28 tree_ov010_4): w->heap read into
 * a local before the switch. The member index is taken before the range
 * fix-up, so a reset slot still passes its old index (the image does not
 * reload it).
 */
int func_02167FB4(void *evt, u32 *seq, SeqWork *w)
{
    int n;
    int i;
    int idx;
    u32 heap;

    heap = w->heap;
    switch (*seq) {
    case 0:
        func_02012374(evt, (struct Evt **)func_021BE8D4((void *)heap, (int)w->arg, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020144DC(heap, (int)w->arg));
        (*seq)++;
        break;
    case 2:
        func_02012374(evt, func_02014910((char *)heap, (int)w->arg, (int)w->f30, (int)w->f08));
        (*seq)++;
        break;
    case 3:
        func_02012374(evt, func_020145CC((void *)heap));
        (*seq)++;
        break;
    case 4:
        func_02012374(evt, (struct Evt **)func_021BE92C((void *)heap, (int)w->arg, 0, 0, 1, 0, 0));
        MI_CpuCopy8(w->order, w->order18c, 6);
        *w->out188 = w->f6c;
        *w->out184 = w->f70;
        if (*w->out188 != 7 && *w->out188 != 8 && w->party194 != 0) {
            n = func_0201AA14(w->party194);
            for (i = 0; i < n; i++) {
                idx = w->order18c[i] - 1;
                if (idx >= 6)
                    w->order18c[i] = 1;
                func_0201A98C(w->party194, func_0201AB28(w->party190, idx));
            }
        }
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}












/*
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x0216C778), so the call
 * attests as `label`.
 */
int func_021680C8(int a, E_02167BFC *b, int c, int d)
{
    int hd;
    int h;
    int g;
    R_02167BFC *p;
    h = (int)func_020120F4((const struct Ctx *)a);
    g = func_02188C54(func_0201210C((void *)a));
    hd = (int)func_020122C0((void *)a, 0, func_02168174, 0x1c);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = a;
    if (b->f18 == 0xFFFF) {
        int t;
        p->f14 = (int)func_020457B0(0x5c, 4);
        t = (int)func_02045B38(0, 2, 0xb8, 4);
        func_02045CAC((struct MsgBank *)t, b->f1a, (void *)p->f14);
        func_02045C04((struct Rec *)t);
    } else {
        p->f14 = (int)func_0202435C(&b[c].f18, 4);
    }
    func_0216D88C((const struct Actor *)func_0216DE94((void *)func_02012964((const struct BigObj *)h), d), (struct VecFx32 *)&p->f4);
    p->f10 = (int)func_0219129C((u8 *)g, 1, (u32)(&p->f4), p->f14, 0, 0);
    return hd;
}












int func_02168174(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09162 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216818A;
loc_02168180:
    if (a0 == 1) goto loc_0216819C;
loc_02168184:
    if (a0 == 2) goto loc_021681AE;
loc_02168188:
    goto loc_021681C2;
loc_0216818A:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_02191388(a0);
loc_02168190:
    if (a0 != 1) goto loc_021681C2;
loc_02168194:
a0 = ((struct Obj09162 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09162 *)((char *)t5))->f0 = a0;
    goto loc_021681C2;
loc_0216819C:
    a0 = func_020362DC();
loc_021681A0:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_021681C2;
loc_021681A6:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_021912D8(a0);
loc_021681AC:
    goto loc_02168194;
loc_021681AE:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_021912F8(a0);
loc_021681B4:
    if (a0 != 1) goto loc_021681C2;
loc_021681B8:
a0 = ((struct Obj07204 *)t4)->f14;
    a0 = func_02045808(a0);
loc_021681BE:
a0 = 1;
    return a0;
loc_021681C2:
a0 = 0;
    return a0;}












/*
 * Builds the battle-intro sprite set: a func_02013090 object, one party
 * list per side filled from 0x3C-byte records through func_0216869C.
 * Levers: side ids are an enum (an int index folds to a constant offset);
 * the mode truncation is a u16 local copied from a u32 parameter; the
 * mode==4 and func_02168AC8 arms each carry their own copy of the eight
 * halfword stores (the cross-jump leaves the `b` into the second copy);
 * one party local per side block sets the spill slots; the sprite pointer
 * of the third block is read before the record pointer moves.
 */
Bs *func_021681C8(void *sys, void *partyA, u32 mode0, Rec *recA, Rec *recB, int n)
{
    u16 mode;
    struct Info info;
    Bs *bs;
    void *ctx;
    void *mon;
    struct Party *party;
    struct Party *partyB;
    struct Party *partyC;
    struct Party *partyD;
    Spr *o;
    int i;
    Side k;
    int flag;
    void *e;
    u8 *vec;
    Rec *recC;

    ctx = func_020120F4((const struct Ctx *)sys);
    mode = mode0;
    func_021AA304(&info, ctx, func_0201210C((const struct Ctx *)sys));
    bs = func_02013090(4);
    switch (mode) {
    case 0:
    case 4:
    case 5:
        func_02013610((u8 *)bs, (u32)ctx, (u32)(&info), 0, 4);
        break;
    case 1:
    case 6:
        func_02013644((u8 *)bs, (u32)ctx, (u32)(&info), 0, 4);
        break;
    case 2:
    case 7:
        func_02013734((struct Obj02013734 *)bs, (u32)ctx, (u32)(&info), 0, 0, 0, 4);
        break;
    case 3:
    case 8:
        e = func_020399A8();
        flag = 0;
        if (func_02039338() != 0)
            flag = 2;
        func_02013810((u8 *)bs, (u32)ctx, (u32)e, 1, flag, 0, 0, 4);
        break;
    }
    func_02013980((struct ZoneData *)bs, 4);

    k = SIDE_0;
    i = 0;
    vec = func_02012944(ctx);
    bs->f34[k] = vec;
    party = bs->f24[k];
    func_0201A954(party, 6);
    mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x253);
    func_02017528(mon);
    for (; i < n; i++) {
        e = func_0201AB28(partyA, i);
        func_02019CE0(e, mon);
        if (func_02017E1C(e, 0x9E, 0) != 0x32)
            func_02019CA0(mon, 0x32);
        func_0201A98C(party, mon);
    }
    func_020307B0(mon);

    k = SIDE_1;
    o = bs->f48[k];
    o->f00 = recA->f00;
    o->f04 = recA->f04;
    o->f08 = 0x87;
    func_02045924(o->f14, (const u16 *)recA->f08);
    func_0202428C(&o->w18.v[0]);
    func_0202428C(&o->w18.v[4]);
    if (mode == 4) {
        o->w18.v[0] = recA->w20.v[0];
        o->w18.v[1] = recA->w20.v[1];
        o->w18.v[2] = recA->w20.v[2];
        o->w18.v[3] = recA->w20.v[3];
        o->w18.v[4] = recA->w20.v[4];
        o->w18.v[5] = recA->w20.v[5];
        o->w18.v[6] = recA->w20.v[6];
        o->w18.v[7] = recA->w20.v[7];
    } else if (func_02168AC8((int)recA) != 0) {
        o->w18.v[0] = recA->w20.v[0];
        o->w18.v[1] = recA->w20.v[1];
        o->w18.v[2] = recA->w20.v[2];
        o->w18.v[3] = recA->w20.v[3];
        o->w18.v[4] = recA->w20.v[4];
        o->w18.v[5] = recA->w20.v[5];
        o->w18.v[6] = recA->w20.v[6];
        o->w18.v[7] = recA->w20.v[7];
    }
    partyB = bs->f24[k];
    func_0201A954(partyB, 6);
    mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x29E);
    for (i = 0; i < n; i++) {
        func_0216869C(&recA->mons[i], mon);
        func_0201A98C(partyB, mon);
    }
    func_020307B0(mon);

    if (bs->f22 != 0) {
        k = SIDE_3;
        o = bs->f48[k];
        recC = recA + 1;
        o->f00 = recC->f00;
        o->f04 = recC->f04;
        o->f08 = 0x87;
        func_02045924(o->f14, (const u16 *)recC->f08);
        partyC = bs->f24[k];
        func_0201A954(partyC, 6);
        mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2C4);
        for (i = 0; i < n; i++) {
            func_0216869C(&recC->mons[i], mon);
            func_0201A98C(partyC, mon);
        }
        func_020307B0(mon);
    }
    if (bs->f22 == 3) {
        k = SIDE_2;
        o = bs->f48[k];
        o->f00 = recB->f00;
        o->f04 = recB->f04;
        o->f08 = 0x87;
        func_02045924(o->f14, (const u16 *)recB->f08);
        func_0202428C(&o->w18.v[0]);
        func_0202428C(&o->w18.v[4]);
        partyD = bs->f24[k];
        func_0201A954(partyD, 6);
        mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2F3);
        for (i = 0; i < n; i++) {
            func_0216869C(&recB->mons[i], mon);
            func_0201A98C(partyD, mon);
        }
        func_020307B0(mon);
    }
    func_0201394C((struct ZoneData *)bs);
    return bs;
}













/*
 * Build a battle-facility Pokemon from its a/2/1/4 record (the reader is
 * func_02168800). Levers: the pid store in both arms of an if/else, the
 * ability as a nested if storing in all three arms, and (2026-09-28
 * tree_ov010_4) the EV share as an int local computed straight from the
 * division with the count n reused as the second loop's counter.
 */
u32 func_021684E8(BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap)
{
    FacRec rec;
    int i;
    int n;
    u8 friendship;
    int ev;
    u32 ability;
    void *bank;

    MI_CpuFill8(out, 0, sizeof(BattleMon));
    func_02168800(&rec, member);
    out->species = rec.species;
    out->form = rec.form;
    if (useItem)
        out->item = d_02172084[itemIdx];
    else
        out->item = rec.item;
    friendship = 0xFF;
    for (i = 0; i < 4; i++) {
        out->moves[i] = rec.moves[i];
        if (rec.moves[i] == 0xDA)
            friendship = 0;
    }
    out->otId = otId;
    if (pid == 0) {
        pid = func_020186C8(otId, rec.species, rec.form, 2, 2, 0);
        out->pid = pid;
    } else {
        out->pid = pid;
    }
    out->nature = rec.nature;
    out->iv.b.hpIv = iv;
    out->iv.b.atkIv = iv;
    out->iv.b.defIv = iv;
    out->iv.b.speIv = iv;
    out->iv.b.spaIv = iv;
    out->iv.b.spdIv = iv;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (rec.evMask & (1 << i))
            n++;
    }
    ev = 510 / n;
    if (ev > 255)
        ev = 255;
    for (n = 0; n < 6; n++) {
        if (rec.evMask & (1 << n))
            out->ev[n] = ev;
    }
    out->ppUps = 0;
    out->lang = 0;
    ability = func_02019C90(out->species, 0, 0x1B);
    if (ability != 0) {
        if (out->pid & 1)
            out->ability = ability;
        else
            out->ability = func_02019C90(out->species, 0, 0x1A);
    } else {
        out->ability = func_02019C90(out->species, 0, 0x1A);
    }
    out->friendship = friendship;
    bank = sub_02045B38(0, 2, 0x46, heap);
    func_02045F5C(bank, out->species, out->nick, 11);
    func_02045C04(bank);
    return pid;
}













/*
 * Builds a level-50 party mon from a 0x3C-byte record. Two levers: the
 * PP-up count read back through func_02017E1C goes through a u8 local, and
 * the nickname copy reads through a `const u16 *` local (indexing
 * src->nick directly keeps the strbuf in a register and swaps r5/r6).
 */
void func_0216869C(const BattleMon *src, void *mon)
{
    u16 name[11];
    void *buf;
    u16 eos;
    int i;
    u8 pp;
    const u16 *n;

    func_02017528(mon);
    func_02017588(mon, src->species, 50, (u64)-1, src->iv.ivs & 0x3FFFFFFF, src->pid);
    func_02017E40(mon, 0x6F, (u8)src->form);
    func_02017E40(mon, 6, src->item);
    for (i = 0; i < 4; i++) {
        func_02017E40(mon, 0x36 + i, src->moves[i]);
        func_02017E40(mon, 0x3E + i, (u8)((src->ppUps >> (i * 2)) & 3));
        pp = func_02017E1C(mon, 0x42 + i, 0);
        func_02017E40(mon, 0x3A + i, pp);
    }
    func_02017E40(mon, 7, src->otId);
    func_02017E40(mon, 0xD, src->ev[0]);
    func_02017E40(mon, 0xE, src->ev[1]);
    func_02017E40(mon, 0xF, src->ev[2]);
    func_02017E40(mon, 0x10, src->ev[3]);
    func_02017E40(mon, 0x11, src->ev[4]);
    func_02017E40(mon, 0x12, src->ev[5]);
    func_02017E40(mon, 0xA, src->ability);
    func_02017E40(mon, 9, src->friendship);
    func_020185B0(mon, src->nature);
    buf = func_020457B0(11, 4);
    eos = func_02045A98();
    n = src->nick;
    for (i = 0; i < 11; i++)
        name[i] = n[i];
    name[i - 1] = eos;
    func_02045924(buf, name);
    func_02017E40(mon, 0x73, (u32)buf);
    func_02045808(buf);
    func_02017E40(mon, 0xC, src->lang);
    func_02017E40(mon, 0x9E, func_02018430(mon));
}













/*
 * The reader for a/2/1/4: copy one 16-byte record into the caller's buffer.
 * 214 is the archive id and it never appears as an immediate at any call to
 * the arc_tool.c entry points, because this accessor reaches func_02048F4C
 * by pool word and `bx` rather than by `bl`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): a plain scan of `bl`
 * sites misses it entirely.
 *
 * The record is a battle-facility Pokemon: func_021684E8, three functions
 * up in the same file (fld_btl_inst_tool.c, by the __FILE__ anchors either
 * side of this address), reads the buffer field by field into a party
 * slot: +0 species (masked to 11 bits), +2/+4/+6/+8 the four move ids,
 * +10 a six-bit "which stats are EV-invested" mask (the caller divides 510
 * EVs between the set bits), +11 the nature (0..24 over the whole archive),
 * +12 the held item and +14 the form (five bits, always zero here).  The
 * member ids come from a/2/1/5, whose own reader is func_0216880C
 * immediately below this one.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02168800.c \
 *       --func func_02168800 --addr 0x02168800 --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void func_02168800(void *dst, u32 member)
{
    func_02048F4C(dst, 214, member);
}













/*
 * The reader for a/2/1/5: allocate a buffer and load one group record.
 * func_0204A1BC(archive_id, member, flag, heap) is arc_util.c's
 * "allocate and read a member" helper, so the returned pointer is the
 * sub-file itself.
 *
 * Two things the bytes pin down.  The member is `group + 1`, truncated to
 * 16 bits before the call, so group 0 is sub-file 1 and sub-file 0 is the
 * usual unused sentinel.  And the record is the group list documented in
 * docs/ASSETS.md, [u16 group_id][u16 count][u16 member_id x count]: its
 * consumer func_02168924 takes `count` from +2, picks a random index below
 * it, reads `member_id` from +4 + 2*index, and hands that id to
 * func_02168800, the a/2/1/4 record reader immediately above this
 * function.  That is the direct evidence that a/2/1/5's member ids index
 * a/2/1/4, which the previous pass could only infer from the id range.
 *
 * Addresses are Black-image addresses.  --region ov010 is required.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216880C.c \
 *       --func func_0216880C --addr 0x0216880C --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void *func_0216880C(u32 group, u32 heap)
{
    return (void *)func_0204A1BC(215, (u16)(group + 1), 0, heap);
}













int func_02168824(void)
{
    int a0;
    int a1;
    int t4;

t4 = 0;
t4 = ~t4;
a0 = t4 + 0;
    a0 = func_020056EC(a0);
loc_02168830:
a1 = (unsigned)t4 >> 0x10;
    a0 = func_0209C2B0(a0, a1);
loc_02168836:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    return a0;}













/*
 * IV value for a battle-facility trainer index: a step table over the
 * index (3 below 50, up to 31 from 200). Returns u8: func_02168924
 * stores the result to its u8 local without an extension.
 */
u8 func_0216883C(u32 n)
{
    if (n < 50)
        return 3;
    if (n < 70)
        return 6;
    if (n < 90)
        return 9;
    if (n < 110)
        return 12;
    if (n < 160)
        return 15;
    if (n < 180)
        return 18;
    if (n < 200)
        return 21;
    return 31;
}











int func_02168878(Blk *a, u16 b, int c, u16 *d, u16 *e, FacDraw *f, u16 g)
{
    FacGroup *t = func_021688BC(a, b, g);
    int r = func_02168924(t, b, a->mons, (u8)c, d, e, f, g);
    func_020307B0((void *)t);
    return r;
}













FacGroup *func_021688BC(Blk *a, int b, int c)
{
    int h = (int)func_02045B38(0, 2, 11, c);
    FacGroup *r;
    int t;
    func_02082BCC(a, 0, 0x120);
    r = func_0216880C(b, c);
    a->f0 = b + 1;
    a->f18 = 0xFFFF;
    a->f1a = b * 3;
    a->f4 = r->id;
    t = (int)func_02045EC0((struct MsgBank *)h, b);
    func_02045A38((struct U16Vec *)t, (u16 *)a->f8, 16);
    func_02045808((struct U16Vec *)t);
    func_02045C04((struct Rec *)h);
    return r;
}













/*
 * Draws `count` distinct battle-facility Pokemon from an a/2/1/5 group
 * list (func_0216880C's record): no repeated species, none of the
 * excluded species, and for the first 50 tries no repeated or excluded
 * held item. Builds each one with func_021684E8 under one random trainer
 * id and optionally reports the first two draws. Returns 1 when the
 * item rule had to be dropped.
 *
 * Levers: locals declared in reverse of their frame order (the arrays
 * after natures, the scalars from otId down), the IV step as u8 (its
 * reader returns only constants up to 31), and a 16-bit `rank` parameter,
 * which moves the r1 spill ahead of the r3 copy (u8 matches equally; int
 * and u32 are 4 bytes out).
 */
int func_02168924(FacGroup *group, u16 rank, BattleMon *mons, int count, u16 *exclSpecies, u16 *exclItems, FacDraw *draw, u16 heap)
{
    u8 natures[4];
    int ids[4];
    u32 pids[4];
    FacRec other;
    FacRec rec;
    u32 otId;
    u8 iv;
    int id;
    int tries;
    int fail;
    int i;
    int n;

    fail = 0;
    tries = 0;
    n = 0;
    while (n != count) {
        id = group->members[(u8)(func_02168824() % group->count)];
        func_02168800(&rec, id);
        for (i = 0; i < n; i++) {
            func_02168800(&other, ids[i]);
            if (other.species == rec.species)
                break;
        }
        if (i != n)
            continue;
        if (exclSpecies != 0) {
            for (i = 0; i < count; i++) {
                if (rec.species == exclSpecies[i])
                    break;
            }
            if (i != count)
                continue;
        }
        if (tries < 50) {
            for (i = 0; i < n; i++) {
                func_02168800(&other, ids[i]);
                if (other.item != 0 && other.item == rec.item)
                    break;
            }
            if (i != n) {
                tries++;
                continue;
            }
            if (exclItems != 0) {
                for (i = 0; i < count; i++) {
                    if (rec.item == exclItems[i] && exclItems[i] != 0)
                        break;
                }
                if (i != count) {
                    tries++;
                    continue;
                }
            }
        }
        ids[n] = id;
        natures[n] = rec.nature;
        n++;
    }

    iv = func_0216883C(rank);
    otId = func_02168824() | (func_02168824() << 16);
    if (tries >= 50)
        fail = 1;
    for (i = 0; i < n; i++)
        pids[i] = func_021684E8(&mons[i], (u16)ids[i], otId, 0, iv, i, fail, heap);
    if (draw == 0)
        return fail;
    draw->otId = otId;
    for (i = 0; i < 2; i++) {
        draw->ids[i] = ids[i];
        draw->pids[i] = pids[i];
        draw->natures[i] = natures[i];
    }
    return fail;
}















int func_02168AC8(int a0)
{
    int a1;
    int a2;
    int a3;

a3 = 0;
loc_02168ACA:
a1 = a3 << 1;
a2 = a0 + a1;
a1 = ((struct Obj12052 *)a2)->f20;
    if (a1 == 0) goto loc_02168AD8;
loc_02168AD4:
a0 = 1;
    return a0;
loc_02168AD8:
a1 = ((struct Obj12052 *)a2)->f28;
    if (a1 == 0) goto loc_02168AE2;
loc_02168ADE:
a0 = 1;
    return a0;
loc_02168AE2:
a3 = a3 + 1;
    if (a3 < 4) goto loc_02168ACA;
loc_02168AE8:
a0 = 0;
    return a0;}













/*
 * Recursive MATCH unblocker: ABS32 target of func_021D0BCC (ov021) +0008.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
u16 func_02168AEC(u16 a0)
{
    u32 i;

    for (i = 0; i < 0x35; i++) {
        if (g_0217208C[i * 2] == a0)
            return g_0217208E[i * 2];
    }
    return 0xA;
}












/*
 * Unlabelled leaf callback (movs r1,#1; str r1,[r0]; bx lr); filed as the
 * sole blocker of func_02168B20 (its pool word).
 */
void func_02168B18(int *p)
{
    *p = 1;
}













/*
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 */
int func_02168B20(int a, int *b, int *c)
{
    int s = c[2];
    int x = func_02188CCC((u8 *)((int)func_0201210C((const struct Ctx *)s)));
    int y = func_02012138((const struct Ctx *)s);
    State t = (State)*b;
    switch (t) {
    case 0:
        if (func_02026454((void *)y) != 0)
            func_02026400((struct Comm *)y);
        (*b)++;
        break;
    case 1:
        if (func_02026454((void *)y) != 0)
            break;
        func_02012158((char *)s, 0);
        (*b)++;
        break;
    case 2:
        if (c[1] != 0) {
            func_02012158((char *)s, 1);
            func_020121CC((struct IcaAnime *)s);
        }
        (*b)++;
        break;
    case 3:
        func_021A0F7C(x, 8, (u32)func_02168B18, (u32)c);
        (*b)++;
        break;
    case 4:
        if (c[0] != 0)
            *b = t + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}












void *func_02168BBC(void *a, void *b)
{
    void *h;
    void **p;
    func_020120F4(a);
    h = func_020122C0(a, 0, func_02168B20, 0xc);
    p = func_020124E8(h);
    func_02082BCC(p, 0, 0xc);
    p[2] = a;
    p[1] = b;
    return h;
}













struct Desc *func_02168BF0(int a, int b, int c, int d, u16 *e)
{
    struct Desc *hd;
    void *h;
    R_021688BC *p;
    int k;
    void *v;
    h = func_020120F4((void *)a);
    hd = func_020122C0((void *)a, 0, (void *)func_02168C74, 0x34);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = (void *)a;
    p->f4 = func_0201210C((void *)a);
    p->fc = e;
    p->f30 = b;
    if (c == 0x14 || c == 0x15) {
        if (c == 0x14) {
            p->f10 = 0;
            k = 0x14;
        } else {
            p->f10 = 1;
            k = 0x15;
        }
    } else {
        p->f10 = 0;
        k = 0x14;
    }
    p->f14 = k;
    if (d == 0) {
        p->f1c = 0;
        v = func_02012934(h);
    } else {
        v = func_0200BAF4((int)func_0200BAC8(func_02012EBC(h)), 5);
        p->f1c = v;
    }
    p->f18 = v;
    return hd;
}













/*
 * Battle state step: state 0 starts the request and moves to state 1; state 1 releases the
 * object and stores the result flag. The flag store is written in each arm of the if/else
 * (2026-10-05 recoup), which keeps the store before the epilogue add sp.
 */
int func_02168C74(int a, int *b, C *c)
{
    int r0 = c->f0;
    switch (*b) {
    case 0: {
        int t = func_02167EF4(r0, c->f10, 0x17, c->f14, c->f18, (int)(&c->f28), (int)(&c->f20), (int)(&c->f24), *(int *)(c->f30 + 0x128));
        func_02012374((struct Evt *)a, (struct Evt **)t);
        *b = 1;
        break;
    }
    case 1:
        if (c->f1c != 0)
            func_020307B0((void *)c->f1c);
        if (c->f24 != 0 || (u32)(c->f20 - 7) <= 1)
            *c->fc = 0;
        else
            *c->fc = 1;
        return 1;
    }
    return 0;
}











/*
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 * recoup 2026-10-05 (P21L10): extent 60 B includes a 2-byte pad (movs r0,r0); code is 58 B.
 * The old draft (12 B off, only the ldr r2 position and the lsls/adds r6 order) closed by
 * dropping const from the record pointer and the byte-pointer casts: EXACT* in c99 and c.
 * Not filed as matched: the Offset enum local (off = KIND_OFF, then off - 4, off - 8) is only
 * there to stop mwcc folding 0x12c into the load offsets. With int k or a plain int typedef,
 * literals, struct fields or a named kind local the compiler folds to a 0x49 base (40 B off).
 * A human reason for the held 0x12c is not known; integrator decides. Callee func_021681C8
 * has u8 kind/n params in the ov021 twin caller but this caller passes full words (no
 * truncation), so the prototype here is int. pragmas scheduling/peephole/opt_lifetimes off:
 * no change on the old const form (12 B). unsigned kind: 15 B.
 */
int func_02168CF4(void *a, Record_02168CF4 *p)
{
    void *b;
    Offset kind;
    Offset off;
    b = func_0201210C(a);
    off = KIND_OFF;
    kind = (Offset)*(int *)((u8 *)p + off);
    return func_0216E910(a, b, func_021681C8(a, *(void *const *)((u8 *)p + (off - 4)), kind, (struct Rec *)p, 0, *(int *)((u8 *)p + (off - 8))));
}












/*
 * Add one battle's tallies into the running record and credit the
 * score share against the party's summed stat 0xA1. First draft.
 */
void func_02168D30(Record_02168D30 *r, Result *s)
{
    void *party;
    int n;
    int i;
    int sum;

    r->f134[0] += (u16)(s->fb6[0] + 1);
    r->f134[1] += s->fb6[1];
    r->f134[2] += s->fb6[2];
    r->f134[3] += s->fb6[3];
    r->f134[4] += s->fb6[4];
    r->f134[5] += s->fb6[5];
    r->f134[6] += s->fb6[6];
    r->f134[7] += s->fb6[7];
    r->f134[8] += s->fb6[8];
    r->f134[9] += s->fb6[9];
    r->f14a += s->fb6[10];
    party = s->party;
    n = func_0201AA18(party);
    sum = 0;
    for (i = 0; i < n; i++)
        sum += func_02017E1C(func_0201AB28(party, i), 0xA1, 0);
    r->f148 += (u16)(s->fb4 * 100 / sum);
}












int func_02168E5C(int a, int b, int c)
{
    int x = (int)func_020120F4((const struct Ctx *)a);
    int h = (int)func_020122C0((void *)a, 0, func_02168EB0, 0x18);
    int *p = func_020124E8((struct Obj *)h);
    p[0] = a;
    p[1] = (int)func_0201210C((void *)a); /* int-typed on purpose: field is int in record */
    ((struct Obj04944 *)p)->f8 = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)x));
    p[3] = (int)func_0200E8F8(func_02012EBC((struct Big *)x));
    p[4] = b;
    p[5] = c;
    return h;
}











/*
 * former blocker: pooled ov220_id is passed to func_02012444 r1, missing from
 * OVERLAY_ID_CONSUMERS. Its matched body stores a1 to payload[0]; matched
 * func_0201240C forwards item[0] as func_020120B4 r1 (known consumer).
 * The ov220 table hint is supported by that load chain; matcher refuses
 * it as contested until the ID site resolves. No code leaf blocks this.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_02168EB0(void *a, int *state)
{
    u8 *p;
    p = func_020124E8(a);
    switch (*state) {
    case 0:
        func_02012444(a, (unsigned int)ov220_id, (unsigned int)d_021BA39C, (unsigned int)(p + 8));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}












void func_02168EEC(int a)
{
    Date date;
    Time time;
    int y;
    int x;
    A *p = (A *)func_02008B14(func_02012EBC((struct Big *)a));
    if (p->f0 == 0)
        return;
    func_0203F49C((struct RtcDate *)&date, (struct RtcTime *)&time);
    if (func_02168F54(p, &date, &time, &y, &x) == 0)
        return;
    if (x == 0 && y != 0)
        return;
    if (x != 0) {
        func_02008BE0((struct Sub02008AECSession *)p, x);
        func_02169068(a, x, &time);
    }
    if (y != 0)
        func_02169004(a, y);
}












int func_02168F54(A *a, Date *b, Time *c, int *d, int *e)
{
    s64 sa = func_02089004((struct RTCDate *)(&a->date), (struct RTCTime *)(&a->time));
    s64 sb = func_02089004((struct RTCDate *)b, (struct RTCTime *)c);
    int day = func_02088F58((struct RTCDate *)b);
    int q;
    *d = 0;
    *e = 0;
    if (sb < sa) {
        a->date = *b;
        a->time = *c;
        a->f20 = day;
        return 0;
    }
    q = (int)((sb - sa) / 60);
    if (q > 0) {
        int dd;
        *e = q;
        a->date = *b;
        a->time = *c;
        dd = day - a->f20;
        if (dd != 0) {
            *d = dd;
            a->f20 = day;
        }
    }
    return 1;
}












/*
 * evidence: 0x0200E518 is an unlabelled ARM9 leaf ("push {r4, r5, r6, r7}",
 * no lr, right after the "pop {r4, pc}" at 0x0200E516) that the prologue
 * sweep misses.  The bl at +0x52 is its only reference in the image; its
 * start is seeded in layout/function_starts.txt, and the callee itself is
 * matched EXACT* (src/matched/arm9/func_0200E518.c), so +0x52 attests as
 * `matched`.
 */
void func_02169004(int a, int b)
{
    int x;
    func_02169138(a);
    x = (int)func_02012EBC((struct Big *)a);
    func_020143F0((u8 *)func_0201296C((const struct BigObj *)a));
    func_0200D440((void *)x);
    func_0201B100(func_02012934((void *)a), b);
    func_02008E30(func_02012F2C((int *)a));
    func_0200952C(func_02009470((void *)x));
    func_021862A8(a, b, 4);
    func_0200E518(func_0200E394((void *)x));
    func_0200AB04(func_0200A8A0((void *)x));
}











/*
 * extent: trailing two-byte alignment padding.
 * interface: final u16 argument follows the original lsls/lsrs #16 pair.
 */
void func_02169068(int a,int b,Time *c) { int t=(int)func_0201AD0C(func_02012EBC((struct Big *)a)); func_0216A2EC(a,t,b,(int *)c,func_02012984((const struct BigObj *)a)); func_0200C3C0((struct Blk34 *)((int)func_0200C0F0(func_02012EBC((struct Big *)a))),b); }












void *func_021690A4(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690AA:
    s = func_02008B14(big);
loc_021690AE:
    return (char *)s + 4;}












int func_021690B4(int a0)
{
    int a1;
    struct Sub02008AECSession *t4;
    void *big;
    int t5;

t5 = a0 + 0;
    big = func_02012EBC((struct Big *)a0);
loc_021690BC:
    t4 = func_02008B14(big);
loc_021690C0:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_021690C8:
a1 = ((struct Obj17735 *)t4)->f14;
    a0 = func_020113F0(a0, a1);
loc_021690CE:
    return a0;}












int func_021690D0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690D6:
    s = func_02008B14(big);
loc_021690DA:
a0 = ((struct Obj17736 *)s)->f8;
    return a0;}













int func_021690E0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690E6:
    s = func_02008B14(big);
loc_021690EA:
a0 = ((struct Obj17737 *)s)->fC;
    return a0;}













int func_021690F0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690F6:
    s = func_02008B14(big);
loc_021690FA:
a0 = ((struct Obj17738 *)s)->f10;
    return a0;}













int func_02169100(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_02169106:
    s = func_02008B14(big);
loc_0216910A:
a0 = ((struct Obj17739 *)s)->f14;
    return a0;}













int func_02169110(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_02169116:
    s = func_02008B14(big);
loc_0216911A:
a0 = ((struct Obj17740 *)s)->f18;
    return a0;}












void func_02169120(void *p) { char *q = (char *)func_02008B14(func_02012EBC(p)); *(u64 *)(q + 0x2c) = func_0203F524(); }













int func_02169138(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_0216913E:
    s = func_02008B14(big);
loc_02169142:
    a0 = func_02008BD0(s);
loc_02169146:
    return a0;}












extern u32 (*g_020A8140)(u32 size, u32 is4x4, u32 opt);












extern u32 (*g_020A8148)(u32 size, u32 is4pltt, u32 opt);













/*
 * Create the 0xDC-byte effect manager from its Cfg: two record lists,
 * work buffers, and texture/palette VRAM keys through the NNS default
 * allocator hooks. Levers: the buffer size from cfg (not the just-stored
 * copy), and the list terminator cleared through m->head.
 */
Mgr *func_02169148(const Cfg *cfg, u32 heap)
{
    Mgr *m;
    u32 sz;

    m = sub_02030734(heap, sizeof(Mgr), 1, d_02172A40, 0x6E);
    sz = func_02046C94();
    m->nA = cfg->nA;
    m->nB = cfg->nB;
    m->fA8 = cfg->f18;
    m->fAC = cfg->f1c;
    if (m->nA != 0)
        m->listA = sub_02030734(heap, cfg->nA * 20, 1, d_02172A40, 0x77);
    if (m->nB != 0)
        m->listB = sub_02030734(heap, cfg->nB * 20, 1, d_02172A40, 0x7A);
    func_0216990C((u8 *)m);
    m->f28 = cfg->f08;
    m->size = cfg->size;
    m->buf = sub_02030734(heap, cfg->size, 1, d_02172A40, 0x86);
    if (cfg->f10 == 0)
        m->f24 = 0x800;
    else
        m->f24 = cfg->f10;
    m->fD8 = cfg->f0c;
    m->head = &m->node;
    m->head->f04 = 0;
    m->f10 = 0;
    m->f84 = sub_02030734(heap, sz, 1, d_02172A40, 0x97);
    m->f88 = sub_02030734(heap, sz, 1, d_02172A40, 0x9A);
    m->f94 = 0;
    if (cfg->texSize != 0) {
        m->texSize = cfg->texSize;
        m->texKey = g_020A8140(cfg->texSize, 0, 0);
        m->plttKey = g_020A8148(0x200, 0, 0);
    } else {
        m->texSize = 0;
        m->texKey = 0;
        m->plttKey = 0;
    }
    return m;
}












extern void (*d_020A814C)(u32);












extern void (*d_020A8144)(u32);













void func_0216928C(void *p)
{
    func_021693A0((int)p);
    if (F(0x20) != 0) {
        d_020A814C(F(0x90));
        d_020A8144(F(0x8c));
    }
    func_020307B0((void *)F(0x88));
    func_020307B0((void *)F(0x84));
    func_020307B0((void *)F(0xd4));
    if (((struct Obj12384 *)p)->fA4 != 0)
        func_020307B0((void *)F(0x9c));
    if (((struct Obj12384 *)p)->fA6 != 0)
        func_020307B0((void *)F(0xa0));
    func_020307B0((void *)((u32)p));
}












/*
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 */
void func_02169308(u8 *p) { Cb cb; if (((struct Obj04162 *)p)->fB0) { cb = *(Cb *)(((struct Obj04162 *)p)->f28+((struct Obj04162 *)p)->f18*16u+4u); if(cb) cb(p,((struct Obj04162 *)p)->fD8); } }














int func_0216932C(int a0)
{
    int a1;
    int v0;
    int t4;
    int t5;
t5 = a0 + 0;
a0 = 1;
((struct Obj04162 *)t5)->f2 = a0;
t4 = (int)&v0;
loc_02169336:
a0 = t5 + 0;
    func_02169308((u8 *)a0);
loc_0216933C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02169520(a0, a1);
loc_02169344:
    a0 = v0;
a0 = ((struct Obj04162 *)((char *)a0))->f0;
    if (a0 != 0) goto loc_02169336;
loc_0216934C:
a0 = 0;
((struct Obj04162 *)t5)->f2 = a0;
    return a0;
}














int func_02169354(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = func_0216968C((u8 *)a0);
loc_02169360:
    if (a0 != 1) goto loc_02169378;
loc_02169364:
a0 = t5 + 0;
a0 = a0 + 0x98;
a0 = ((struct Obj03541 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_02169376;
loc_0216936E:
a0 = t5 + 0;
a1 = t6 + 0;
    func_02169710((struct ModelObj *)a0, a1);
loc_02169376:
t4 = 1;
loc_02169378:
a0 = t4 + 0;
    return a0;}













void func_0216937C(u8 *p,int a,int b) { func_0216990C(p); func_021693A0((int)p); ((struct Obj19036 *)(*(u8 * *)&((struct Obj00306 *)p)->f2C))->f4=0; ((struct Obj00306 *)p)->f10=func_020490F4(a,b); }














void func_021693A0(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12053 *)t4)->f10;
    if (a0 == 0) goto loc_021693B2;
loc_021693AA:
    func_02049238((void *)a0);
loc_021693AE:
a0 = 0;
((struct Obj12053 *)t4)->f10 = a0;
loc_021693B2:
    return;}














/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218CEE4.
 */
void func_021693B4(char *p, int v)
{
    ((struct Obj19037 *)p)->f94 = v;
}














/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218D05C.
 */
void func_021693BC(char *p)
{
    ((struct Obj19038 *)p)->f94 = 0;
}














void func_021693C4(char *p, int v)
{
    ((struct Obj19039 *)p)->f98 = v;
}














void func_021693CC(char *p)
{
    ((struct Obj19040 *)p)->f98 = 0;
}














/*
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Stores a 0x14-byte
 * record (word, 12 bytes, halfword) into entry idx of the table at +0x9C.
 */
void func_021693D4(u8 *base, u8 *src, u32 idx)
{
    *(u32 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14) = ((struct Obj12385 *)src)->f0;
    *(V3 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14 + 4) = *(V3 *)(src + 4);
    *(u16 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14 + 0x10) = ((struct Obj12385 *)src)->f10;
}














/*
 * Reset the 0x14-byte entry `i` of the table at +0x9c.
 *
 * Addresses are Black-image addresses.
 */
void func_0216940C(Obj *o, u32 i)
{
Entry *e;
if (i == 0xffffffff)
return;
if (i >= o->count)
return;
o->table[i].f0 = 0xffffffff;
e = &o->table[i];
e->f4 = 0;
e->f8 = 0;
e->fc = 0;
*(u16 *)((u8 *)&o->table[i] + 0x10) = 0;
}












/*
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Returns the 0x14-byte
 * entry idx of the table at +0x9C, or 0 if idx is out of range or the
 * entry is unused (first word -1).
 */
u32 *func_02169444(u8 *base, u32 idx)
{
    u32 *e;

    if (idx >= ((struct Obj05901 *)base)->fA4)
        return 0;
    e = (u32 *)(*(u8 * *)&((struct Obj05901 *)base)->f9C + idx * 0x14);
    if (e[0] == -1)
        return 0;
    return e;
}










inline static int Find(const u16 *pv, const E_0216932C *tbl)
{
  unsigned i;
  i = 0;
  while (tbl[i].key != (-1))
  {
    if ((*pv) == tbl[i].key)
      break;
    i++;
  }

  return i;
}










/*
 * lever: initialized table-read temporary in the once-only budget-300 permuter
 * gives table r1 and sentinel r0; validation agrees with all five relocations.
 */
void func_02169470(u8 *p, u32 b)
{
  u16 v;
  const E_0216932C *tbl;
  int i;
  E_0216932C *tmp;
  func_02169998((int)(*((void **) (p + 0x2c))), b);
  func_02169550((char *)p);
  func_02169568((char *)p);
  func_02169880(p);
  *((u32 *) (p + 0x14)) = b;
  func_0204944C((struct ArcFile *)*((u32 *) (p + 0x10)), b, 0, 2, &v);
  tmp = *((E_0216932C **) (p + 0x28));
  tbl = *((E_0216932C **) (p + 0x28));
  i = Find(&v, tmp);
  tbl = tbl;
  *((int *) (p + 0x18)) = i;
  *((u16 *) (p + 0xb0)) = 1;
}











void func_021694D4(u8 *p, int a1)
{
    func_02169998((int)(*((void **)(p + 0x2c))), a1);
    func_02169550((char *)p);
    func_02169568((char *)p);
    func_0216959C(p);
    func_0216990C(p);
}













/*
 * Stores the halfword at p.
 *
 * Addresses are Black-image addresses.
 */
void func_021694F8(u8 *p, u16 v)
{
    ((struct Obj17742 *)p)->f0 = v;
}













/*
 * Reads the halfword at p.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021694FC(u8 *p)
{
    return ((struct Obj17743 *)p)->f0;
}













/*
 * Copies a 12-byte record from q into p + 0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_02169500(u8 *p, u8 *q)
{
    *(S12 *)(p + 0x4) = *(S12 *)q;
}










/*
 * Unlabelled leaf (blocker of ov021 func_0218C724).  Copies the 12 bytes
 * at src+4 to dst.
 */
void func_02169510(u8 *src, V3 *dst)
{
    *dst = *(V3 *)(src + 4);
}












int func_02169520(int a0, int a1)
{

a0 = a0 + 0xb0;
((struct Obj17744 *)((char *)a1))->f0 = a0;
    return a0;}










/*
 * Unlabelled leaf accessor: copies the word at +0xD4 to *out.
 *
 * Addresses are Black-image addresses.
 */
void func_02169528(unsigned char *a, int *out)
{
    *out = ((struct Obj19043 *)a)->fD4;
}










/*
 * Unlabelled leaf accessor: copies the word at +0x14 to *out.
 *
 * Addresses are Black-image addresses.
 */
void func_02169530(unsigned char *a, int *out)
{
    *out = ((struct Obj19045 *)a)->f14;
}










/*
 * Unlabelled leaf accessor: copies the word at +0xBC to *out.
 *
 * Addresses are Black-image addresses.
 */
void func_02169538(unsigned char *a, int *out)
{
    *out = ((struct Obj19047 *)a)->fBC;
}










/*
 * Unlabelled leaf: tail call initialising the record at +0x84 in mode 1.
 *
 * Addresses are Black-image addresses.
 */
void func_02169540(unsigned char *a, unsigned int v)
{
    sub_02046C9C(((struct Obj00281 *)a)->f84, 1, v);
}









void func_02169550(char *p) { func_02046C9C(((struct Obj00306 *)p)->f84, 1, 0); }










/*
 * Unlabelled leaf accessor: returns the word at +0x84.
 *
 * Addresses are Black-image addresses.
 */
int func_02169560(unsigned char *a)
{
    return ((struct Obj19049 *)a)->f84;
}









void func_02169568(char *p) { func_02046C9C(((struct Obj00306 *)p)->f88, 2, 0); }










/*
 * Unlabelled leaf: forwarding tail call to func_02169A68.
 *
 * Addresses are Black-image addresses.
 */
int func_02169578(unsigned char *a)
{
    return (int)func_02169A68((int)a);
}










void func_02169580(int a0)
{
    int a1;
    int a2;
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_02169A68(a0);
loc_02169588:
a0 = ((struct Obj00281 *)t4)->f2C;
t4 = t4 + 0x84;
a1 = ((struct Obj00281 *)((char *)t4))->f0;
    func_02169928((void *)a0, (void *)a1, p);
loc_02169594:
    return;}











/*
 * Reads the word field at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02169598(u8 *p)
{
    return ((struct Obj17745 *)p)->f2C;
}











void func_0216959C(u8 *p)
{
    *(u32 *)(p + 0xB4) = 0;
    *(u32 *)(p + 0xC0) = 0;
    *(u32 *)(p + 0xC8) = 0;
    *(u32 *)(p + 0xCC) = 0;
    *(u32 *)(p + 0xD0) = 0;
}











/*
 * lever: The archive length call takes the still-live member argument; the remaining two bytes are zero alignment padding.
 */
void func_021695BC(S_021695BC *p, int b)
{
    u32 t;

    if (p->busy != 0) {
        func_02169A88((u8 *)p, b);
        return;
    }
    t = p->base + p->cur;
    p->tot = func_020493D4((struct ArcFile *)p->h, b);
    p->len = 0;
    func_0204944C((struct ArcFile *)p->h, b, 0, p->n, (void *)t);
    p->cur = p->cur + p->n;
    p->len = p->len + p->n;
}











int func_02169620(S_02169620 *p)
{
    u32 base;
    u32 cur;
    u32 len;
    u32 tot;
    u32 rem;

    base = p->base;
    cur = p->cur;
    len = p->len;
    tot = p->tot;
    if (tot <= len)
        return 0;
    rem = tot - len;
    if (rem > p->n) {
        func_020495F4((struct ArcFile *)p->h, p->n, (void *)(base + cur));
        p->cur = p->cur + p->n;
        p->len = p->len + p->n;
        return 1;
    }
    func_020495F4((struct ArcFile *)p->h, rem, (void *)(base + cur));
    p->cur = p->cur + rem;
    return 0;
}











int func_0216968C(u8 *p)
{
    int r;

    r = 0;
    if (*(u16 *)&((struct Obj03541 *)p)->f0 != 0 && ((struct Obj19050 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4 != 0) {
        func_0206A9DC(d_0217216C);
        func_02082B60(d_02172178, d_02148C08);
        d_02148BCC.f7c &= ~0xa4;
        func_0206AA0C(d_02172160);
        func_0206A854();
        func_0206DDA4(0x15, 0, 0);
        func_0206DDA4(0x17, d_02148B98, 0xc);
        func_0206DDA4(0x1c, p + 4, 3);
        if (func_021699A0(((struct Obj19051 *)(*(u8 * *)&((struct Obj03541 *)p)->f2C))->f4) == 1) {
            func_02047C8C(((struct Obj03541 *)p)->f2C);
            r = 1;
        }
    }
    return r;
}











/*
 * Draws each placed model of a list: for every 0x14-byte entry at +0x9C
 * (count u16 at +0xA4) whose index is valid in the resource table at +0x98,
 * loads the base matrix g_02148B98 (G3 cmd 0x17, MTX_LOAD_4x3), multiplies
 * in a Y rotation by the entry's angle translated by obj+4 plus the entry's
 * position (cmd 0x19, MTX_MULT_4x3), and draws it.  The handed 240-byte
 * extent also holds an unlabelled 32-byte leaf at 0x021697E0.
 */
void func_02169710(ModelObj *obj, int unused)
{
    Res_0216959C *tbl = obj->res->tbl;
    u32 count = obj->res->count;
    int i;

    if (count == 0 || tbl == 0) {
        return;
    }
    for (i = 0; i < obj->nents; i++) {
        u32 idx = obj->ents[i].idx;
        void *r;
        void *mdl;
        Mtx43 m;
        s16_0216959C s;
        s16_0216959C c;
        int a;

        if (idx == (u32)-1 || idx >= count) {
            continue;
        }
        r = (void *)func_0204755C((int *)func_02047788(tbl[idx].f00));
        mdl = ((void **)r)[1];
        if (mdl == 0) {
            continue;
        }
        a = obj->ents[i].angle >> 4;
        s = tbl_020A1B38[a * 2];
        c = tbl_020A1B38[a * 2 + 1];
        func_0206DDA4(0x17, g_02148B98, 12);
        VEC_Add(&obj->pos, &obj->ents[i].pos, &m.t);
        MTX_RotY33_(&m, s, c);
        func_0206DDA4(0x19, &m, 12);
        if (func_021699A0(mdl) == 1) {
            func_02047C8C(r);
        }
    }
}











/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218DBD4.
 */
int func_021697E0(char *p)
{
    if (((struct Obj09322 *)p)->fD0 == 0
        || *(int *)(*(char * *)&((struct Obj09322 *)p)->f28 + ((struct Obj09322 *)p)->f18 * 16 + 8) == 0)
        return 0;
    return 1;
}











void func_02169800(void *a, char *b, u32 c, u32 d)
{
    u32 buf[3];
    u32 e;
    Cb_02169800 cb;

    ((struct Obj19055 *)a)->f100 = 0;
    if (((struct Obj05902 *)b)->fD0 != 0) {
        e = ((struct Obj05902 *)b)->f8;
        func_0207CA00(c, b + 4, buf);
        cb = *(Cb_02169800 *)(*(char * *)&((struct Obj05902 *)b)->f28 + ((struct Obj05902 *)b)->f18 * 16 + 8);
        if (cb != 0)
            cb(a, ((struct Obj05902 *)b)->fD4, buf, d, e);
    }
}










/*
 * extent: trailing two-byte alignment padding.
 * output proof: func_0207CA00 stores buf[0:2] at 0207CA20/0207CA28;
 * callback receives that initialized three-word vector, with original arity.
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 */
void func_02169848(void *a,u8 *b,u32 c,u32 d) { u32 buf[3]; Cb_02169848 cb; func_0207CA00(c,b+4,buf); cb=*(Cb_02169848 *)(((struct Obj07317 *)b)->f28+((struct Obj07317 *)b)->f18*16u+12u); cb(a,((struct Obj07317 *)b)->fD4,buf,d,((struct Obj07317 *)b)->f8); }











/*
 * The second loop's final store goes through the +0x9C array, as the bytes show.
 */
void func_02169880(u8 *p)
{
    int i;
    E *e;

    for (i = 0; i < ((struct Obj12387 *)p)->fA4; i++) {
        (*(E **)(p + 0x9c))[i].a = -1;
        e = &(*(E **)(p + 0x9c))[i];
        e->b = 0;
        e->c = 0;
        e->d = 0;
        (*(E **)(p + 0x9c))[i].e = 0;
    }
    for (i = 0; i < ((struct Obj12387 *)p)->fA6; i++) {
        (*(E **)(p + 0xa0))[i].a = -1;
        e = &(*(E **)(p + 0xa0))[i];
        e->b = 0;
        e->c = 0;
        e->d = 0;
        (*(E **)(p + 0x9c))[i].e = 0;
    }
}










void func_0216990C(u8 *p) { ((struct Obj00306 *)p)->f0=0; ((struct Obj00306 *)p)->f4=0; ((struct Obj00306 *)p)->f8=0; ((struct Obj00306 *)p)->fC=0; ((struct Obj00306 *)p)->fB0=0; ((struct Obj00306 *)p)->f14=0; func_02169880(p); }











static inline u32 *Get(u8 *r, u32 idx)
{
    u8 *h;

    h = r + 8;
    if (h != 0 && idx < r[9])
        return (u32 *)(h + ((struct Obj12388 *)r)->fE + 4 + idx * 4);
    return 0;
}











void func_02169928(void *a, void *b, void *c)
{
    u8 *r;
    u32 *q;
    u8 *res;
    void *m;
    void *y;

    res = func_02046F48(b);
    y = func_02046F48(c);
    m = 0;
    r = (u8 *)func_0206E954((int)res);
    if (r != 0 && (q = Get(r, 0)) != 0)
        res = r + *q;
    else
        res = 0;
    if (y != 0)
        m = func_0206E964(y);
    if (m != 0) {
        func_0206A2CC(res, m);
        func_0206A4AC(res, m);
    }
    func_02069D14(a, res);
}













int func_02169998(int a0, int a1)
{

a1 = 0;
((struct Obj17746 *)a0)->f4 = a1;
    return a0;}











int func_021699A0(void *p)
{
    s16_021699A0 v[6];
    u32 w[3];
    u32 one;
    char *q;
    int r;

    r = 1;
    q = p ? (char *)p + 0x14 : 0;
    v[0] = ((struct Obj04164 *)q)->f18;
    v[1] = ((struct Obj04164 *)q)->f1A;
    v[2] = ((struct Obj04164 *)q)->f1C;
    v[3] = ((struct Obj04164 *)q)->f1E;
    v[4] = ((struct Obj04164 *)q)->f20;
    v[5] = ((struct Obj04164 *)q)->f22;
    func_0206DDA4(0x11, 0, 0);
    w[0] = ((struct Obj04164 *)q)->f24;
    w[1] = w[0];
    w[2] = w[0];
    func_0206DDA4(0x1b, w, 3);
    if (func_02169A14((u32)v) == 0)
        r = 0;
    one = 1;
    func_0206DDA4(0x12, &one, 1);
    return r;
}











u32 func_02169A14(u32 a)
{
    u32 x;
    u32 y;
    u32 z;

    x = 1;
    y = 0x30C1;
    func_0206DDA4(0x29, &y, 1);
    z = 0;
    func_0206DDA4(0x40, &z, 1);
    func_0206DDA4(0x41, 0, 0);
    func_0206DDA4(0x70, (void *)a, 3);
    func_0206DB80();
    while (func_0207DEA4((s32_02167BFC *)(&x)) != 0)
        ;
    return x;
}











void *func_02169A68(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
a0 = a0 + 0x88;
a0 = *(int *)&((struct Obj02337 *)((char *)a0))->f0;
    p = func_02046F48((struct Tagged *)a0);
loc_02169A74:
    if (p != 0) goto loc_02169A82;
loc_02169A78:
a0 = t4 + 0;
a0 = a0 + 0x94;
p = ((struct Obj02337 *)((char *)a0))->f0;
    if (p != 0) goto loc_02169A86;
loc_02169A82:
t4 = t4 + 0x88;
p = ((struct Obj02337 *)((char *)t4))->f0;
loc_02169A86:
    return p;}








void func_02169A88(u8 *p,u32 n) { void *out; u32 v; out=((struct Obj00281 *)p)->fD4; v=func_020493D4(*(struct ArcFile * *)&((struct Obj00281 *)p)->f10,n); func_0204932C(*(struct ArcFile * *)&((struct Obj00281 *)p)->f10,n,out); ((struct Obj00281 *)p)->fBC=v; ((struct Obj00281 *)p)->fB4=v; ((struct Obj00281 *)p)->fB8=v; }








/*
 * The 21-state setup and teardown machine of the ov010 program. First
 * draft; the call at 0x021A153C reaches an ov021 Thumb thunk
 * (`ldr r0, [r0, #0x20]; ldr r3, =target; bx r3`), declared `thumb ov021`
 * (the ISA evidence honours the ovNNN hint since tooling_3).
 */
int func_02169AB8(Work *w, u32 *state)
{
    void *ws;
    void *str;

    switch (*state) {
    case 0:
        func_021A0F30(func_02188CCC(w->f08), 7);
        *state = 1;
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(w->f08)) == 1
            && func_021A1518((u32 *)func_02188CCC(w->f08)) == 1) {
            w->f18 = func_02030734(w->f10, 0x50, 0, d_02172A50, 0x9F);
            w->f18->f04 = func_02045B38(0, 3, 0x9E, w->f10);
            w->f18->f18 = func_020457B0(0x200, w->f10);
            w->f18->f00 = func_0203101C(w->f10, w->f10, 1, 4);
            w->f18->f1C = func_02028590(0xF, 1, 1, w->f10);
            w->f18->f14 = (void *)func_0201C440((void *)w->f10);
            w->f18->f4C = 0;
            func_02169E4C((int)w);
            func_0216A0BC(w);
            *state = 2;
        }
        break;
    case 2:
        func_02169EA4(w, 2);
        *state = 3;
        break;
    case 3:
        if (func_02169FB8((int)w) == 0) {
            func_0216A148(w);
            *state = 4;
        }
        break;
    case 4:
        switch (func_0216A184((int)w)) {
        case 0:
            if (func_020071F0(w->f00) == 1) {
                func_02169EA4(w, 8);
                *state = 0xE;
            } else {
                func_0201F7A8(w->f18->f08, 1);
                *state = 5;
            }
            break;
        case 1:
            *state = 0x11;
            break;
        }
        break;
    case 5:
        func_02008DF0(func_02012F2C(func_020120F4(w->f04)), 1);
        func_021A1524((u32 *)func_02188CCC(w->f08));
        if (func_021A1554((u32 *)func_02188CCC(w->f08)) == 1)
            func_02169FFC(w, 10);
        else
            func_02169FFC(w, 4);
        *state = 6;
        break;
    case 6:
        if (func_0216A07C(w) == 1) {
            func_0216A1C0((int)w);
            *state = 7;
        }
        break;
    case 7:
        if (func_0216A21C((int)w) == 1)
            *state = 8;
        break;
    case 8:
        if (func_0216A244(w) != 0) {
            w->f18->f44 = func_0202EE30((void *)func_020056BC(), w->f18->f08, 0xF, 0x10, w->f10);
            func_021A1530((u32 *)func_02188CCC(w->f08));
            func_0216A264((int)w);
            func_02012DAC((int)func_020120F4(w->f04));
            *state = 9;
        }
        break;
    case 9:
        switch (func_02012DD0(func_020120F4(w->f04))) {
        case 0:
        case 1:
            break;
        case 2:
            *state = 10;
            break;
        case 3:
            func_021A1548((u32 *)func_02188CCC(w->f08));
            func_0216A280((int)w);
            func_0216A1F8((int)w);
            func_02169EA4(w, 7);
            func_0202F038(w->f18->f44);
            *state = 0xD;
            break;
        }
        break;
    case 10:
        if (func_021A153C((u32 *)func_02188CCC(w->f08)) == 1) {
            func_020061E4(0x558);
            func_0216A280((int)w);
            func_0216A1F8((int)w);
            ws = func_0201EC64(w->f10);
            str = func_02045EC0(w->f18->f04, 5);
            func_0201F02C(ws, 0, func_02012944(func_020120F4(w->f04)));
            func_0201F250(ws, w->f18->f18, str);
            func_02045808(str);
            func_0201ED04(ws);
            func_02169EBC(w);
            func_0202F038(w->f18->f44);
            *state = 0xB;
        }
        break;
    case 11:
        if (func_0216A21C((int)w) == 1 && func_0216A244(w) != 0 && func_02169FB8((int)w) == 0)
            *state = 0xC;
        break;
    case 12:
        if (func_02006254(0x558) == 0)
            *state = 0x10;
        break;
    case 13:
        if (func_0216A21C((int)w) != 1 || func_0216A244(w) == 0)
            break;
        *state = 0xE;
    case 14:
        if (func_02169FB8((int)w) == 0)
            *state = 0xF;
        break;
    case 15:
        if (func_020362DC() & 3)
            *state = 0x13;
        break;
    case 16:
        if (func_020362DC() & 3)
            *state = 0x13;
        if (w->f18->f4C >= 150)
            *state = 0x13;
        else
            w->f18->f4C++;
        break;
    case 17:
        func_02169E0C((char *)w);
        func_021A0F30(func_02188CCC(w->f08), 1);
        *state = 0x12;
        break;
    case 18:
        return 1;
    case 19:
        func_02169E0C((char *)w);
        func_021A0F30(func_02188CCC(w->f08), 0);
        *state = 0x14;
        break;
    case 20:
        func_021A0FB4((u32 *)func_02188CCC(w->f08), w->f10);
        return 0;
    }
    return 2;
}







int func_02169E0C(char *a0)
{
    int t4;

t4 = (int)(a0 + 0);
    func_0216A128(a0);
loc_02169E14:
a0 = (char *)(t4 + 0);
    a0 = (char *)func_02169E98(a0);
loc_02169E1A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f14);
    a0 = (char *)func_0201C4C0(a0);
loc_02169E22:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f1C);
    a0 = (char *)func_02028604((int)a0);
loc_02169E2A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)((char *)a0))->f0);
    a0 = (char *)func_02031140(a0);
loc_02169E32:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f18);
    a0 = (char *)func_02045808(a0);
loc_02169E3A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f4);
    func_02045C04((struct Rec *)a0);
loc_02169E42:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
    a0 = (char *)func_020307B0(a0);
loc_02169E48:
    return (int)a0;}








void func_02169E4C(int a0)
{
    int a1;
    int a2;
    int a3;
    unsigned char fr[12];
    int t4;
    int t5;
    int o4;
    int o5;
    int o6;
t5 = a0 + 0;
a0 = 4;
    o4 = a0;
a0 = 0xc;
    o5 = a0;
a0 = 1;
    o6 = a0;
a0 = 6;
a1 = 1;
a2 = 1;
a3 = 0x1e;
t4 = 6;
    a0 = func_020450F0(a0, a1, a2, a3, o4, o5, o6);
loc_02169E6C:
a1 = *(int *)&((struct Obj00029 *)t5)->f18;
a2 = 0xd;
((struct Obj17747 *)a1)->f8 = a0;
a0 = ((struct Obj00029 *)t5)->f10;
a1 = 1;
a3 = 0;
    o4 = a0;
a0 = 6;
    a0 = func_0201F5BC(a0, a1, a2, a3, o4);
loc_02169E80:
a0 = 0x20;
    o4 = a0;
a0 = ((struct Obj00029 *)t5)->f10;
a1 = 5;
a2 = 4;
    o5 = a0;
a0 = 0x17;
a3 = t4 << 6;
    a0 = func_02049B40(a0, a1, a2, a3, o4, o5);
loc_02169E94:
    return;
}








int func_02169E98(char *p)
{
    return func_020452E8((struct Descriptor *)(((struct Obj19073 *)(*(char * *)&((struct Obj19072 *)p)->f18))->f8));
}








void func_02169EA4(Work *w, u32 n)
{
    func_02045CAC(w->f18->f04, n, w->f18->f18);
    func_02169EBC(w);
}








void func_02169EBC(Work *w)
{
    Res_02167BFC *r;
    u32 a;
    void *p;

    func_02043B5C(func_02045770(w->f18->f08), 15);
    func_0201F73C(w->f18->f08, 2, 1, 13);
    r = w->f18;
    a = func_021904AC(w->f0C);
    w->f18->f10 = func_0201CCE4(r->f08, 0, 0, r->f18, a, func_02012FFC(), r->f00, 10, w->f10, 15);
    w->f18->f20 = 0;
    p = w->f18->f08;
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
}








int func_02169F34(u8 *p)
{
    switch (func_0201CE30((void *)H)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3) != 0)
            func_0201CE5C((struct Rec *)H, 0);
        ST = 0;
        break;
    case 1:
        if (ST == 0) {
            if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
                func_020061E4(0x547);
                func_0201CE38((void *)H);
                ST = 1;
            }
        }
        break;
    case 2:
        func_0201CE48((struct Rec3 *)H);
        ST = 0;
        return 0;
    }
    return 1;
}








int func_02169FB8(int a0)
{
    int a1;
    int a2;
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)((char *)a0))->f0;
    a0 = func_020310C4(a0);
loc_02169FC4:
a2 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = ((struct Obj04885 *)a2)->f1C;
a1 = ((struct Obj04885 *)a2)->f10;
a2 = ((struct Obj04885 *)a2)->f8;
    a0 = func_020286C4(a0, a1, a2);
loc_02169FD0:
a0 = t4 + 0;
    a0 = func_02169F34((u8 *)a0);
loc_02169FD6:
    if (a0 != 0) goto loc_02169FDE;
loc_02169FDA:
a0 = 0;
    return a0;
loc_02169FDE:
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)((char *)a0))->f0;
    a0 = func_020310C4(a0);
loc_02169FE6:
a2 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = ((struct Obj04885 *)a2)->f1C;
a1 = ((struct Obj04885 *)a2)->f10;
a2 = ((struct Obj04885 *)a2)->f8;
    a0 = func_020286C4(a0, a1, a2);
loc_02169FF2:
a0 = t4 + 0;
    a0 = func_02169F34((u8 *)a0);
loc_02169FF8:
    return a0;}








void func_02169FFC(Work *w, u32 msg)
{
    void *str;
    u32 a;
    Slot *s;
    void *t;
    void *p;

    func_02043B5C(func_02045770(w->f18->f08), 15);
    func_0201F73C(w->f18->f08, 2, 1, 13);
    str = func_02045EC0(w->f18->f04, msg);
    a = func_021904AC(w->f0C);
    s = (Slot *)&w->f18->f08;
    t = w->f18->f14;
    func_0201C6FC(t, (u32)func_02045770(s->f00), 0, 0, str, a);
    s->f04 = 1;
    func_02045808(str);
    p = w->f18->f08;
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
}








int func_0216A07C(Work *w)
{
    Slot *s;
    void *t;

    func_0201C4E4(w->f18->f14);
    t = w->f18->f14;
    s = (Slot *)&w->f18->f08;
    if (s->f04 != 0 && func_0201C6C4(t, func_02045770(s->f00)) == 0) {
        func_02045334(s->f00);
        s->f04 = 0;
    }
    return func_0201C6B4(w->f18->f14);
}








/*
 * Byte-correct (first draft). Blocker: 0x021904A8 has no func_ label in
 * any overlay listing (ov009 and ov021 overlap it); it sits four bytes before
 * ov021's func_021904AC and is almost certainly a Thumb accessor there. Seeding
 * it in ov021 closes this file.
 */
void func_0216A0BC(Work *w)
{
    void *bank;
    u32 a;

    bank = func_02045B38(0, 2, 0xA8, w->f10);
    w->f18->f24 = func_02045EC0(bank, 8);
    w->f18->f28 = 0x39E3;
    w->f18->f2C = 0;
    w->f18->f30 = func_02045EC0(bank, 9);
    w->f18->f34 = 0x39E3;
    w->f18->f38 = 0;
    func_02045C04(bank);
    a = func_021904AC(w->f0C);
    w->f18->f3C = func_02027F60(6, 14, a, func_021904A8(w->f0C), w->f10);
}








/*
 * Three teardown calls on the three arm9 handles the object carries.
 */
void func_0216A128(void *p)
{
    func_02027FD8(((struct Obj17748 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f3C);
    func_02045808(((struct Obj17749 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f30);
    func_02045808(((struct Obj17750 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f24);
}








void func_0216A148(Work *w)
{
    Desc d;

    d.heap = w->f10;
    d.f04 = 2;
    d.f08 = &w->f18->f24;
    d.f0C = 1;
    d.f10 = 0x20;
    d.f11 = 12;
    d.f12 = 8;
    d.f13 = 3;
    w->f18->f40 = (void *)func_0202784C((int)(&d), (int)w->f18->f3C);
}








int func_0216A184(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027974(a0);
loc_0216A190:
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_020279E8((struct TaskMenu *)a0);
loc_0216A198:
    if (a0 != 1) goto loc_0216A1B8;
loc_0216A19C:
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027A04((const u8 *)a0);
loc_0216A1A4:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027858(a0);
loc_0216A1AE:
a0 = 1;
    if (t4 != 0) goto loc_0216A1BC;
loc_0216A1B4:
a0 = 0;
    return a0;
loc_0216A1B8:
a0 = 0;
a0 = ~a0;
loc_0216A1BC:
    return a0;}








int func_0216A1C0(int a0)
{
    int a1;
    void *v0;
    void *v1;

a0 = ((struct Obj17751 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A1C8:
    a0 = func_021A3208(v0);
loc_0216A1CE:
    if (a0 != 1) goto loc_0216A1F6;
loc_0216A1D2:
    v1 = func_021A3074(v0);
loc_0216A1D8:
a1 = 0x20;
    a0 = func_021A2F48(v0, a1);
loc_0216A1E2:
    a0 = (int)func_0216DB04(v1);
loc_0216A1E8:
a1 = 0x10;
    a0 = (int)func_0216D550(v1, a1);
loc_0216A1F0:
    a0 = func_021A2F54(v0);
loc_0216A1F6:
    return a0;}








void func_0216A1F8(int a0)
{
    int a1;
    void *v0;

a0 = ((struct Obj17752 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A200:
    a0 = func_021A3208(v0);
loc_0216A206:
    if (a0 != 1) goto loc_0216A218;
loc_0216A20A:
a1 = 8;
    a0 = func_021A2F48(v0, a1);
loc_0216A212:
    a0 = func_021A2F54(v0);
loc_0216A218:
    return;}








int func_0216A21C(int a0)
{    void *v0;

a0 = ((struct Obj17753 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A224:
    a0 = func_021A3208(v0);
loc_0216A22A:
    if (a0 != 0) goto loc_0216A232;
loc_0216A22E:
a0 = 1;
    return a0;
loc_0216A232:
    a0 = func_021A2F54(v0);
loc_0216A238:
    if (a0 != 1) goto loc_0216A240;
loc_0216A23C:
a0 = 1;
    return a0;
loc_0216A240:
a0 = 0;
    return a0;}








/*
 * unblocked: func_021A3244 (ov021 tail-call thunk) matched bottom-up and
 *   filed as pkt_021A3244; the `ov021` token resolves its call as
 *   `matched, overlay`.  Extent runs 32 against 30 compiled: the unlabelled
 *   follower.
 *
 * The overlay's own status call takes the arm9 handle; anything but one
 * reads as failure.
 */
int func_0216A244(void *a0)
{
    void *v = func_02188CB4(((struct Obj17754 *)a0)->f8);

    if (func_021A3208(v) == 1)
        return func_021A3244(v);

    return 1;
}








int func_0216A264(int a0)
{
    int a1;
    int t4;
    void *p;

t4 = a0 + 0;
a0 = ((struct Obj00029 *)t4)->f10;
a1 = *(int *)&((struct Obj00029 *)t4)->f8;
    p = func_021D1164(a0, a1);
loc_0216A270:
a1 = *(int *)&((struct Obj00029 *)t4)->f18;
((struct Obj17755 *)a1)->f48 = p;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
p = ((struct Obj00029 *)a0)->f48;
    a0 = func_021D11B0(p, a1);
loc_0216A27C:
    return a0;}








int func_0216A280(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)a0)->f48;
    a0 = func_021D11D8(a0);
loc_0216A28C:
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)a0)->f48;
    a0 = func_021D1194(a0);
loc_0216A294:
    return a0;}








void func_0216A298(void *a, void *list)
{
    int i;
    int n;
    void *e;
    int x;
    int y;

    n = func_0201AA18(list);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        x = func_02017E1C(e, 5, 0);
        y = func_02017E1C(e, 0x6f, 0);
        if (x == 0x1ec && y == 1)
            func_02017988(e, 0);
    }
}








int func_0216A2EC(int a0, int a1, int a2, int *a3, int a4)
{
    int r6;
    int r0;
    int r1;
    int t;

    r6 = func_02011400(a4, 3);
    r0 = func_02011400(a4, 0);
    r1 = a3[0];
    if (!((u32)r1 < (u32)r6 && (u32)r1 >= (u32)r0)) {
        t = r1;
        if (t < r0) {
            t += 24;
        }
        t = t - r6;
        if (a3[1] + t * 60 < a2 + 1) {
            func_0216A298((void *)a0, (void *)a1);
            return 1;
        }
        return 0;
    }
    t = r1 - r0;
    if (a3[1] + t * 60 < a2) {
        func_0216A298((void *)a0, (void *)a1);
        return 1;
    }
    return 0;
}







int func_0216A358(int a,int b,u32 *p,int c) { u32 hi; u32 lo; int result; hi=func_02011400(c,3); lo=func_02011400(c,0); result=0; if (!(*p < hi && *p >= lo)) { func_0216A390(a,b); result=1; } return result; }








void func_0216A390(int a0, int a1)
{
    int found;
    int n;
    void *l4;
    int i;
    void *e;
    int v;
    int w;

    l4 = func_0200CA1C((void *)a0);
    found = 0;
    n = func_0201AA18((void *)a1);
    for (i = 0; i < n; i++) {
        e = func_0201AB28((void *)a1, i);
        v = func_02017E1C(e, 5, 0);
        w = func_02017E1C(e, 0x6f, 0);
        if (v == 0x1EC && w == 1) {
            func_02017988(e, 0);
            if (found == 0) {
                func_0200CFA0(l4, e);
                found = 1;
            }
        }
    }
}








/*
 * blocked:  listing 40 compiled 38
 */
int func_0216A3F8(int a0, int a1)
{    void *p;
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216A400:
    p = func_020120F4((const struct Ctx *)v0);
loc_0216A406:
    v1 = func_02012F50(p);
loc_0216A40A:
a0 = *(int *)&((struct Obj12054 *)((char *)v1))->f0;
    if (a0 != 0) goto loc_0216A41A;
loc_0216A412:
    p = func_021D096C(v0);
loc_0216A418:
((struct Obj12054 *)((char *)v1))->f0 = p;
loc_0216A41A:
a0 = 0;
    return a0;}








/*
 * blocked:  listing 32 compiled 30 wild=4
 *
 * Overlay index, then the record's handle and one arm9 probe go to the
 * overlay's own pair call.
 */
int func_0216A420(void *a0, void *a1)
{
    void *p = func_0215A5DC(a1);

    func_021D0A48(p, func_02012F50(func_020120F4(p)));

    return 0;
}








/*
 * blocked:
 */
int func_0216A440(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A44C:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A452:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A456:
    v2 = func_02012F50(p);
loc_0216A45A:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0216A464:
a1 = a0 + 0;
a0 = ((struct Obj17756 *)((char *)v2))->f0;
    a0 = func_021D0A74(a0, a1);
loc_0216A46C:
a0 = 0;
    return a0;}







int func_0216A470(int a0, int a1)
{
    void *r7;
    void *l4;
    int *r6;
    int l8;
    int lc;
    u16 *l0;

    r7 = func_0215A5F4((void *)a1);
    l4 = func_0215A5DC((void *)a1);
    r6 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l4));
    l8 = func_02159B10((void *)a0, (void *)a1);
    lc = func_02159B10((void *)a0, (void *)a1);
    l0 = func_02159AE8((void *)a0, (void *)a1);
    func_0215897C(r7, func_02168BF0((int)l4, *r6, l8, lc, l0));
    return 1;
}







int func_0216A4CC(int a0, int a1)
{
    void *r7;
    int *r6;
    int loc;
    u16 *p;

    func_0215A5F4((void *)a1);
    r7 = func_0215A5DC((void *)a1);
    r6 = func_02012F50(func_020120F4((const struct Ctx *)r7));
    loc = func_02159B10((void *)a0, (void *)a1);
    p = func_02159AE8((void *)a0, (void *)a1);
    *p = func_021D0AC0(r7, *r6, loc);
    return 0;
}







int func_0216A510(int a0, int a1)
{
    void *r7;
    void *l0;
    int *r6;
    int l4;

    r7 = func_0215A5F4((void *)a1);
    l0 = func_0215A5DC((void *)a1);
    r6 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l0));
    l4 = func_02159B10((void *)a0, (void *)a1);
    func_0215897C(r7, (void *)func_021D0BD8((u32)l0, *r6, l4, func_02159B10((void *)a0, (void *)a1)));
    return 1;
}







/*
 * blocked:  listing 52 compiled 50
 */
int func_0216A560(int a0, int a1)
{
    int t4;
    void *p;
    void *task;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A56A:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A572:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A578:
    v2 = func_02012F50(p);
loc_0216A57C:
a1 = ((struct Obj17757 *)((char *)v2))->f0;
    task = (void *)func_02168CF4(v1, (struct Record_02168CF4 *)a1);
loc_0216A586:
    func_0215897C(v0, task);
loc_0216A58E:
a0 = 1;
    return a0;}







/*
 * blocked:
 */
int func_0216A594(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A5A0:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A5A6:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A5AA:
    v2 = func_02012F50(p);
loc_0216A5AE:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216A5B8:
a1 = a0 + 0;
a0 = ((struct Obj17758 *)((char *)v2))->f0;
    a0 = func_021D0AB8(a0, a1);
loc_0216A5C0:
a0 = 0;
    return a0;}






int func_0216A5C4(void *a,void *b) { void *sys; u32 n; func_0215A5F4(b); sys=func_020120F4(func_0215A5DC(b)); n=func_02159B10(a,b); func_02008E68(func_02008C58(func_02012EBC(sys)),(u8)n); return 0; }







int func_0216A5FC(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *p;
    struct Sub02008C20Obj *obj;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A608:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A60E:
    t6 = func_020120F4((const struct Ctx *)v1);
loc_0216A612:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A61C:
    p = func_02012EBC(t6);
loc_0216A624:
    obj = func_02008C58(p);
loc_0216A628:
    a0 = func_02008E78(obj);
loc_0216A62C:
*q = a0;
a0 = 0;
    return a0;}







int func_0216A634(int a0, int a1)
{
    void *r7;
    void *l0;
    int *r4;

    r7 = func_0215A5F4((void *)a1);
    l0 = func_0215A5DC((void *)a1);
    r4 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l0));
    func_0215897C(r7, func_021D0BE4((void *)l0, (u8 *)*r4, func_02159AE8((void *)a0, (void *)a1)));
    return 1;
}







int func_0216A674(int a0, int a1)
{
    void *r7;
    int *r6;
    u16 *l0;

    func_0215A5F4((void *)a1);
    r7 = func_0215A5DC((void *)a1);
    r6 = (int *)func_02012F50(func_020120F4((const struct Ctx *)r7));
    l0 = func_02159AE8((void *)a0, (void *)a1);
    func_021D0DB0((u32)r7, (u8 *)(*r6), l0, func_02159AE8((void *)a0, (void *)a1));
    return 0;
}







/*
 * blocked:  listing 56 compiled 54
 */
int func_0216A6B4(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    u16 *q;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A6C0:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A6C6:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A6CC:
    v2 = func_02012F50(p);
loc_0216A6D0:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A6DA:
a1 = ((struct Obj17760 *)((char *)v2))->f0;
    a0 = func_021D0FE0(v1, a1);
loc_0216A6E4:
*q = a0;
a0 = 0;
    return a0;}







int func_0216A6EC(int a0, int a1)
{
    void *r7;
    void *l0;
    int *r4;

    r7 = func_0215A5F4((void *)a1);
    l0 = func_0215A5DC((void *)a1);
    r4 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l0));
    func_0215897C(r7, func_021D0FE8((void *)l0, *r4, func_02159B10((void *)a0, (void *)a1)));
    return 1;
}







int func_0216A72C(int a0, int a1)
{
    void *r6;
    void *r7;
    int l0;

    r6 = func_0215A5F4((void *)a1);
    r7 = func_0215A5DC((void *)a1);
    func_02012F50(func_020120F4((const struct Ctx *)r7));
    l0 = func_02159B10((void *)a0, (void *)a1);
    func_0215897C(r6, (void *)func_02168E5C((int)r7, l0, func_02159B10((void *)a0, (void *)a1)));
    return 1;
}







int func_0216A774(int a0, int a1)
{
    int t4;
    int t5;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A780:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A786:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A790:
    a0 = func_021D1028(v1);
loc_0216A798:
*q = a0;
a0 = 0;
    return a0;}







int func_0216A7A0(int a0, int a1)
{
    void *l0;
    void *r6;
    int l4;
    int r7;
    int r5;
    struct Desc *l8;
    void *obj;
    S_0216A7A0 *r4;

    func_0215A5E4((void *)a1);
    l0 = func_0215A5F4((void *)a1);
    r6 = func_0215A5DC((void *)a1);
    l4 = func_02159B10((void *)a0, (void *)a1);
    r7 = func_02159B10((void *)a0, (void *)a1);
    r5 = func_02159B10((void *)a0, (void *)a1);
    l8 = func_020122C0((void *)r6, 0, (void *)func_0216A838, 0x18);
    r4 = func_020124E8((struct Obj *)l8);
    r4->f4 = r5;
    r4->f6 = 0;
    obj = func_0216DE94((void *)func_02188C7C(func_0201210C((void *)r6)), l4);
    func_0216D88C(obj, (struct VecFx32 *)&r4->v);
    r4->f8 = obj;
    func_0216D568(obj, 0x8000);
    r4->f0 = (r7 << 15) - r4->v.b;
    func_0215897C(l0, l8);
    return 1;
}







int func_0216A838(int a0, int a1, S_0216A838 *p)
{
    Vec3 loc;

    p->f6 = p->f6 + 1;
    loc = p->v;
    loc.b += (p->f0 * p->f6) / p->f4;
    func_0216D89C(p->f8, &loc);
    if (p->f6 >= p->f4) {
        return 1;
    }
    return 0;
}







int func_0216A884(int a0, int a1)
{
    void *l0;
    void *r4;
    int r6;
    struct Desc *r7;
    void *m;
    int *r5;

    func_0215A5E4((void *)a1);
    l0 = func_0215A5F4((void *)a1);
    r4 = func_0215A5DC((void *)a1);
    r6 = func_02159B10((void *)a0, (void *)a1);
    r7 = func_020122C0((void *)r4, 0, (void *)func_0216A8F0, 0x14);
    r5 = func_020124E8((struct Obj *)r7);
    r5[0] = 0;
    m = func_0216DE94((void *)func_02188C7C(func_0201210C((void *)r4)), r6);
    func_0216D88C((const struct Actor *)m, (struct VecFx32 *)(r5 + 2));
    ((void **)r5)[1] = m;
    func_0215897C(l0, r7);
    return 1;
}







static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}








/*
 * Three-phase orbit step: spiral out over 110 frames, circle at radius 3
 * for 80, spiral in for 80, returning 1 when done. FX_Mul must be the
 * inline function with the table value first (the macro, or the radius
 * first, puts the radius in r0:r1 and spills its sign word: 368 out).
 */
int func_0216A8F0(void *unused, u32 *mode, Orbit *o)
{
    VecFx32 pos;
    u32 cnt;
    s32_0216A560 idx;
    fx32 r;

    pos = o->pos;
    cnt = ++o->count;
    switch (*mode) {
    case 0:
        idx = (cnt << 17) / 110;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        r = (cnt * 3 << 16) / 110;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], r);
        pos.z += FX_Mul(FX_SinCosTable_[idx], r);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 110) {
            o->count = 0;
            *mode = 1;
        }
        break;
    case 1:
        idx = (cnt << 16) / 80;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], 0x30000);
        pos.z += FX_Mul(FX_SinCosTable_[idx], 0x30000);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 80) {
            o->count = 0;
            *mode = 2;
        }
        break;
    case 2:
        idx = (cnt << 16) / 80;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        r = ((80 - cnt) * 3 << 16) / 80;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], r);
        pos.z += FX_Mul(FX_SinCosTable_[idx], r);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 80)
            return 1;
        break;
    }
    return 0;
}







/*
 * Season change: walks every mon of a party and sets the form (field 0x6F)
 * of species 585 and 586 to the season index, registering each species once
 * with func_0200CFA0 when one of its members actually changed.
 */
void func_0216AAE4(void *sys, void *party, int season)
{
    u32 dex;
    int i;
    int n;
    int formA;
    int formB;
    int doneA;
    int doneB;

    dex = (u32)func_0200CA1C(sys);
    doneA = 0;
    doneB = 0;

    switch (season) {
    case 0:
        formA = 0;
        formB = 0;
        break;
    case 1:
        formA = 1;
        formB = 1;
        break;
    case 2:
        formA = 2;
        formB = 2;
        break;
    case 3:
        formA = 3;
        formB = 3;
        break;
    default:
        formA = 0;
        formB = 0;
        break;
    }

    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);
        int species = func_02017E1C(mon, 5, 0);
        int form = func_02017E1C(mon, 0x6F, 0);

        if (species == 585 && form != formA) {
            func_02017988(mon, formA);
            if (!doneA) {
                func_0200CFA0((struct Blk37 *)dex, mon);
                doneA = 1;
            }
        } else if (species == 586 && form != formB) {
            func_02017988(mon, formB);
            if (!doneB) {
                func_0200CFA0((struct Blk37 *)dex, mon);
                doneB = 1;
            }
        }
    }
}






int func_0216ABD8(int a0, int a1)
{
    int buf;
    int *pb;
    int k;
    u16 *p;
    int q;
    void *s;
    void *t;
    void *r;

    pb = &buf;
    k = func_02159B10((void *)a0, (void *)a1);
    p = func_02159AE8((void *)a0, (void *)a1);
    r = func_0216AED0((void *)a1, k);
    if (r != 0) {
        q = func_0216AF1C((void *)a1, r, 4, pb);
        if (q != 0) {
            s = func_0215A5F4((void *)a1);
            t = func_0215A5DC((void *)a1);
            func_0215897C(s, func_0216AF74((int)t, (int)func_0201210C((void *)t), q, *pb, p, 4));
        }
    }
    return 1;
}






int func_0216AC40(int a0, int a1)
{
    void *w;
    void *h;
    u8 *e;
    int key;

    w = func_0215A5DC((void *)a1);
    h = func_0201210C((void *)w);
    func_02012138(w);
    e = (u8 *)func_021664CC(func_0215A5CC((void *)a1), w, (u32 *)(&key));
    if (e != 0) {
        func_0217C37C(h, key, e, ((Bits_02167BFC *)(e + 0x50))->lo, ((Bits_02167BFC *)(e + 0x50))->hi);
        func_020307B0(e);
    }
    return 0;
}






/*
 * Unblocked by matching func_0217C294 (ov018, EXACT; itself unblocked by
 * func_0216D63C): the +0026 call site now attests as `matched`.
 */
int func_0216AC90(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *w;
    void *r;

t5 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AC98:
t4 = a0 + 0;
a0 = t5 + 0;
    w = func_0215A5E4((void *)a0);
loc_0216ACA0:
    w = func_02012EBC(w);
loc_0216ACA4:
    t6 = func_0200E0B0(w);
loc_0216ACA8:
a0 = t5 + 0;
a1 = t4 + 0;
    r = func_0216AED0((void *)a0, a1);
loc_0216ACB2:
    if (r == 0) goto loc_0216ACC8;
loc_0216ACB6:
    a0 = func_0217C294(r);
loc_0216ACBA:
a1 = a0 + 0;
    a0 = func_0200E18C(t6, a1);
loc_0216ACC2:
a0 = t5 + 0;
    func_0216AF3C(a0);
loc_0216ACC8:
a0 = 0;
    return a0;}




/*
 * Unblocked by matching func_0217C294 (ov018, EXACT; itself unblocked by
 * func_0216D63C): the +0032 call site now attests as `matched`.
 */
int func_0216ACCC(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    int t7;
    void *w;
    void *r;
    u16 *q;

t4 = a0 + 0;
t5 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216ACD6:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t5 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216ACE0:
a0 = t5 + 0;
    w = func_0215A5E4((void *)a0);
loc_0216ACE8:
    w = func_02012EBC(w);
loc_0216ACEC:
    t6 = func_0200E0B0(w);
loc_0216ACF0:
a0 = t5 + 0;
a1 = t7 + 0;
    r = func_0216AED0((void *)a0, a1);
loc_0216ACFA:
    if (r == 0) goto loc_0216AD14;
loc_0216ACFE:
    a0 = func_0217C294(r);
loc_0216AD02:
a1 = a0 + 0;
    a0 = func_0216628C(t6, a1);
loc_0216AD0A:
*q = a0;
a0 = t5 + 0;
    func_0216AF3C(a0);
loc_0216AD12:
    goto loc_0216AD18;
loc_0216AD14:
a0 = 0;
*q = a0;
loc_0216AD18:
a0 = 0;
    return a0;}




int func_0216AD1C(int a0, int a1, int a2, int a3)
{
    int v0;
    int t4;
    int t5;
    int t6;
    int t7;
    void *obj;
    void *v1;
t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AD26:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AD30:
t7 = a0 + 0;
a0 = t4 + 0;
a1 = t6 + 0;
    obj = func_0216AED0((void *)a0, a1);
loc_0216AD3A:
    if (obj == 0) goto loc_0216AD6C;
loc_0216AD3E:
a0 = t4 + 0;
    a0 = func_0215A5CC((void *)a0);
loc_0216AD44:
a2 = a0 + 0;
a0 = t4 + 0;
a3 = (int)&v0;
    a0 = func_0216AF1C((void *)a0, (void *)obj, a2, (int *)a3);
loc_0216AD50:
t5 = a0 + 0;
    if (t5 == 0) goto loc_0216AD6C;
loc_0216AD54:
a0 = t4 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0216AD5A:
    a0 = (int)func_02158F74(v1);
loc_0216AD5E:
a1 = t7 + 0;
a2 = t5 + 0;
    func_0201EE84((void *)a0, a1, (void *)a2);
loc_0216AD66:
a0 = t5 + 0;
    func_020307B0((void *)a0);
loc_0216AD6C:
a0 = 0;
    return a0;
}




int func_0216AD70(int a0, int a1)
{
    int kind;
    u16 *out;
    void *x;
    void *y;
    int t;
    Bits_0216ACCC v;
    Bits_0216ACCC w;

    kind = func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    x = func_0215A5DC((void *)a1);
    y = func_0215A5E4((void *)a1);
    func_0200E0B0(func_02012EBC((struct Big *)y));
    t = func_02012138(x);
    switch (kind) {
    case 0:
        if (func_021767A0((void *)t, y) == 4)
            *out = 1;
        else
            *out = 0;
        break;
    case 1:
        *out = func_02166618(func_02012FB0(y));
        break;
    case 2:
        *out = func_0216662C(func_02012FB0(y));
        break;
    case 3:
        func_0216AEE8(a1, (int *)(&v));
        *out = v.lo;
        break;
    case 4:
        func_0216AEE8(a1, (int *)(&w));
        *out = w.f;
        break;
    }
    return 0;
}



int func_0216AE10(int a0, int a1)
{
    int buf[3];
    int q[3];
    void *hd;
    void *b;
    void *c;
    int kind;
    int v;
    void *x;
    void *y;
    void *r;
    int s;

    hd = func_0215A5F4((void *)a1);
    b = func_0215A5DC((void *)a1);
    c = func_0215A5E4((void *)a1);
    kind = func_02159B10((void *)a0, (void *)a1);
    v = func_02012FB0(c);
    if (kind == 1 && func_0216662C(v) != 0) {
        x = func_0201210C((void *)b);
        y = func_02188CB4((void *)x);
        s = func_02012138(b);
        func_021A3038(y, (struct VecFx32 *)q);
        func_021767F0(s, c, buf);
        buf[0] = buf[0] + (q[0] - (0x3E << 14));
        r = func_02184D38(b, (int)x, 0x117, buf, 1, 0);
    } else {
        if (kind != 9)
            v = func_021665F0((int)b, func_02012FB0(c), kind);
        r = (void *)func_0216B3A8((int)b, kind, v);
    }
    func_0215897C(hd, r);
    return 1;
}


void *func_0216AED0(void *p, u32 id) { return func_0216DE94(func_02188C7C(func_0201210C(func_0215A5DC(p))), id); }


void func_0216AEE8(int vm, int *out)
{
    void *ws;
    ws = func_0215A5F4((void *)vm);
    func_0217C274((unsigned int *)out, (char *)((int)func_0216AED0((void *)vm, func_0215901C(ws, func_0215A5E4((void *)vm), 0x8011))));
}



/*
 * Overlay index on the first argument, then the pair call is staged with
 * the fourth argument.
 */
int func_0216AF1C(void *a0, void *a1, int a2, int *a3)
{
    void *v = func_0215A5E4(a0);

    func_0217C274((unsigned int *)a3, a1);
    return func_0217C2A0(4, v, a3);
}



/*
 * Unblocked by matching func_0217688C (ov011, EXACT): the +0032 call site now
 * attests as `matched`.
 */
void func_0216AF3C(int a0)
{
    int a1;
    int t4;
    int t5;
    void *c;
    void *e;
    void *w;

t5 = a0 + 0;
    c = func_0215A5DC((void *)a0);
loc_0216AF44:
a0 = t5 + 0;
    e = func_0215A5E4((void *)a0);
loc_0216AF4C:
    w = func_02012EBC(e);
loc_0216AF52:
    func_0200E0B0(w);
loc_0216AF56:
    a0 = func_02012138(c);
loc_0216AF5C:
    a0 = func_02158344(a0);
loc_0216AF60:
t4 = a0 + 0;
    if (t4 == 0) goto loc_0216AF72;
loc_0216AF64:
    a0 = func_02012FB0(e);
loc_0216AF6A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0217688C(a0, a1);
loc_0216AF72:
    return;}



struct Desc *func_0216AF74(int a0, int a1, int a2, int a3, u16 *a4, u16 a5)
{
    void *h;
    struct Desc *r;
    u8 *p;

    h = func_020120F4((const struct Ctx *)a0);
    r = func_020122C0((void *)a0, 0, (void *)func_0216B004, 0x3C);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x3C);
    ((struct Obj03543 *)p)->f0 = a1;
    *(u16 * *)&((struct Obj03543 *)p)->f28 = a4;
    ((struct Obj03543 *)p)->f24 = a5;
    ((struct Obj03543 *)p)->fC = a2;
    *(int *)&((struct Obj03543 *)p)->f20 = a3;
    ((struct Obj03543 *)p)->f2C = func_0203F1FC((const u8 *)a2, func_020173EC());
    if (func_0200E2BC(func_02012EBC(h), (u32 *)(&a3), (void *)a5, 0) == 0)
        ((struct Obj03543 *)p)->f20 = (((struct Obj03543 *)p)->f20 & 0xFFFFF800) | 0x28B;
    func_021AA304((struct Info *)(p + 0x10), h, (void *)a1);
    return r;
}



/*
 * Proc main of an ov010 sub-sequence: a 9-state machine that registers the
 * party member's species/form key with the save (clearing the form to 12
 * when it is not yet seen), runs the ov098 screen and then the ov227 one,
 * and frees both work buffers when it runs past the last state.
 *
 * Byte-correct. Evidence gaps, not C: 0x02189A08 (ov021), 0x021B6158
 * (ov098) and 0x021B95C8 (ov227) carry no func_ label in their overlay
 * and have no second caller; d_021B6D74 and d_021B98A4 are the ov098 and
 * ov227 proc tables. Levers: `ok` at function scope (its slot sits above
 * the case-1 locals), heap declared before mon in both key blocks, and
 * the u16 flag stored in both arms of an if/else.
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216B004(void *evt, u32 *state, MsgWork *w)
{
    void *h = func_020124E4(evt);
    void *sys = func_020120F4(h);
    int ok;

    switch (*state) {
    case 0:
        func_02012374(evt, func_02029BCC(h, 0x468));
        (*state)++;
        break;
    case 1: {
        u32 heap;
        void *mon;
        Key key;

        mon = w->f0c;
        heap = w->f24;

        key.species = func_02017E1C(mon, 5, 0);
        key.form = func_02017E1C(mon, 0x6F, 0);
        if (func_0200E2BC(func_02012EBC(sys), (u32 *)(&key), (void *)heap, 1) == 0)
            w->f20.form = 12;
        func_021CF498((struct Ctx *)func_02189A08(w->f00), (u32)evt, 0);
        (*state)++;
        break;
    }
    case 2:
        (*state)++;
        break;
    case 3:
        func_02012374(evt, (struct Evt **)func_020144DC((int)h, (int)w->f00));
        (*state)++;
        break;
    case 4: {
        void *sv = func_02012EBC(sys);

        func_02007E50(func_0201292C(sys), 0x240, 1, w->f24);
        func_02034AC4((u32)ov098_id);
        w->f04 = func_021B6100((u32)sys, (u32)w->f0c, (u32)w->f10, (u32)func_02012944(sys), (u32)func_0201292C(sys),
                               (u32)func_0200873C(sv), (u32)func_0200CA10(sv), w->f24);
        func_02012444(evt, -1, (u32)d_021B6D74, (u32)w->f04);
        (*state)++;
        break;
    }
    case 5: {
        u32 heap;
        void *mon;
        Key key;

        ok = func_021B6158(w->f04);
        mon = w->f0c;
        heap = w->f24;

        key.species = func_02017E1C(mon, 5, 0);
        key.form = func_02017E1C(mon, 0x6F, 0);
        if (func_0200E2BC(func_02012EBC(sys), (u32 *)(&key), (void *)heap, 1) == 0
            || func_0200E2BC(func_02012EBC(sys), (u32 *)(&w->f20), (void *)w->f24, 0) == 0)
            ok = 0;
        if (ok == 1)
            *w->f28 = 1;
        else
            *w->f28 = 0;
        func_02034A5C((u32)ov098_id);
        func_02034AC4((u32)ov227_id);
        w->f08 = func_021B95A0((u32)sys, ok, (u32)w->f0c, w->f24);
        func_02012444(evt, -1, (u32)d_021B98A4, (u32)w->f08);
        func_02007F1C(func_0201292C(sys), 0x240, 1, w->f24);
        (*state)++;
        break;
    }
    case 6:
        func_021B95C8(w->f08);
        func_02034A5C((u32)ov227_id);
        func_02012374(evt, func_02029C00(h));
        (*state)++;
        break;
    case 7:
        func_02012374(evt, func_020145CC(h));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_02029CC0(h));
        (*state)++;
        break;
    default:
        func_020307B0(w->f0c);
        func_020307B0(w->f04);
        return 1;
    }
    return 0;
}
