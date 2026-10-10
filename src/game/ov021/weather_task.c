/*
 * file:     weather_task.c
 * unit:     yes
 * function: func_021A1AAC, func_021A1AF4, func_021A1B38, func_021A1B50, func_021A1B74, func_021A1BDC, func_021A1BE4, func_021A1BF4, func_021A1BF8, func_021A1C04, func_021A1C1C, func_021A1C34, func_021A1C68, func_021A1D04, func_021A1D78, func_021A1DB4, func_021A1DF8, func_021A1E08, func_021A1FEC, func_021A2050, func_021A20C8, func_021A2108, func_021A2114, func_021A2120, func_021A2130, func_021A213C, func_021A2148, func_021A2154, func_021A2160, func_021A2170, func_021A2180, func_021A2190, func_021A21A0, func_021A21B0, func_021A21B8, func_021A21BC, func_021A21C8, func_021A21E0, func_021A21F8, func_021A2228, func_021A223C, func_021A2248, func_021A2254, func_021A22E0, func_021A231C, func_021A232C, func_021A2390, func_021A23B0, func_021A23D4, func_021A23E8, func_021A23F4, func_021A2400, func_021A240C, func_021A2418, func_021A2424, func_021A244C, func_021A2564, func_021A25BC, func_021A25CC, func_021A25DC, func_021A2604, func_021A2630, func_021A2638, func_021A2640, func_021A2654, func_021A26C4, func_021A26D8, func_021A2724, func_021A273C, func_021A274C, func_021A277C, func_021A27B8, func_021A27F8, func_021A282C, func_021A284C, func_021A2860, func_021A28A0, func_021A28CC, func_021A2924, func_021A2968, func_021A2970, func_021A2978, func_021A2994, func_021A29A8, func_021A29F4, func_021A2A18, func_021A2A68, func_021A2A84, func_021A2AAC, func_021A2AB8, func_021A2B8C, func_021A2BB8, func_021A2BC4, func_021A2BD4, func_021A2C10, func_021A2C24, func_021A2C28, func_021A2C2C, func_021A2C30, func_021A2C6C, func_021A2C98, func_021A2CC8, func_021A2CEC, func_021A2CF8, func_021A2D04, func_021A2D30, func_021A2D88, func_021A2DE4, func_021A2DF0, func_021A2E34, func_021A2E44, func_021A2E50, func_021A2E90, func_021A2EB8, func_021A2F20, func_021A2F48, func_021A2F54, func_021A2F60, func_021A2F6C, func_021A2F8C, func_021A2F98, func_021A2FA4, func_021A2FB0, func_021A2FD0, func_021A2FE4, func_021A3038, func_021A3044, func_021A3050, func_021A305C, func_021A3068, func_021A3074, func_021A3080, func_021A308C, func_021A3098, func_021A30A4, func_021A30B0, func_021A30BC, func_021A30C8, func_021A3128, func_021A3190, func_021A31A4, func_021A31D0, func_021A3208, func_021A3220, func_021A322C, func_021A3238, func_021A3244, func_021A3250, func_021A32A8, func_021A330C, func_021A3364, func_021A3460, func_021A3484, func_021A34EC, func_021A34F8, func_021A3504, func_021A3524, func_021A3550, func_021A356C, func_021A3584, func_021A35A0, func_021A35BC, func_021A35E0, func_021A35F0, func_021A35FC, func_021A3624, func_021A3644, func_021A3664, func_021A3674, func_021A3680, func_021A368C, func_021A3698, func_021A36A4, func_021A36B0, func_021A36BC, func_021A36C8, func_021A36D4, func_021A36E0, func_021A36E4, func_021A3810, func_021A3818, func_021A3898, func_021A38A4, func_021A3920, func_021A392C, func_021A3938, func_021A394C, func_021A395C, func_021A3960, func_021A3964, func_021A3968, func_021A396C, func_021A3970, func_021A3974, func_021A3980, func_021A398C, func_021A3990, func_021A3994, func_021A3998, func_021A39AC, func_021A39E4, func_021A3A10, func_021A3A20, func_021A3A3C, func_021A3AA0, func_021A3AB8, func_021A3AC4, func_021A3AD0, func_021A3AD4, func_021A3AD8, func_021A3B3C, func_021A3B78, func_021A3B94, func_021A3BB4, func_021A3C24, func_021A3C3C, func_021A3C54, func_021A3C6C, func_021A3C94, func_021A3CB0, func_021A3CC0, func_021A3CE8, func_021A3D08, func_021A3D50, func_021A3D6C, func_021A3DA0, func_021A3E14, func_021A3E48, func_021A3E54, func_021A3EE0, func_021A3F10, func_021A3F48, func_021A3F64, func_021A3F70, func_021A3F8C, func_021A3F98, func_021A3FB4, func_021A3FC0, func_021A3FDC, func_021A3FE8, func_021A408C, func_021A40A8, func_021A4114, func_021A4140, func_021A41A8, func_021A41B0, func_021A4224, func_021A4254, func_021A428C, func_021A43D8, func_021A4444, func_021A448C, func_021A44BC, func_021A44C8, func_021A4544, func_021A4598, func_021A4664, func_021A4698, func_021A46F0, func_021A4768, func_021A47B4, func_021A482C, func_021A4890, func_021A48A4, func_021A48C8, func_021A491C, func_021A4960, func_021A4994, func_021A4A74, func_021A4AA8, func_021A4B00, func_021A4B54, func_021A4B98, func_021A4C1C, func_021A4C50, func_021A4CA8, func_021A4CF4, func_021A4D8C, func_021A4D90, func_021A4DC0, func_021A4E78, func_021A4E9C, func_021A4ED8, func_021A4F04, func_021A4F0C, func_021A4F50, func_021A4F58, func_021A4FA8, func_021A5010, func_021A5014, func_021A5044, func_021A50BC, func_021A50E0, func_021A511C, func_021A5148, func_021A51A4, func_021A51A8, func_021A51D8, func_021A5204, func_021A5228, func_021A5264, func_021A5304, func_021A530C, func_021A5318, func_021A5328, func_021A5334, func_021A5340, func_021A5354, func_021A5360, func_021A536C, func_021A5378, func_021A5390, func_021A53A4, func_021A53BC, func_021A53D0, func_021A5408, func_021A5458, func_021A548C, func_021A54A0, func_021A54B4, func_021A550C, func_021A552C, func_021A5538, func_021A55A8, func_021A55DC, func_021A55FC, func_021A5610, func_021A5630, func_021A569C, func_021A56C0, func_021A56F4, func_021A5708, func_021A5728, func_021A572C, func_021A5738, func_021A575C, func_021A5764, func_021A5768, func_021A5778, func_021A5788, func_021A57C0, func_021A5810, func_021A5880, func_021A5920, func_021A5928, func_021A5964, func_021A596C, func_021A59DC, func_021A59EC, func_021A5A00, func_021A5A0C, func_021A5A18, func_021A5A24, func_021A5A30, func_021A5A34, func_021A5A68, func_021A5AD4, func_021A5B4C, func_021A5B6C, func_021A5B7C, func_021A5BC0, func_021A5C3C, func_021A5CA4, func_021A5D04, func_021A5DD8, func_021A5E28, func_021A5EA0, func_021A5EA4, func_021A5EDC, func_021A5F14, func_021A5F38, func_021A5F74, func_021A5F98, func_021A6014, func_021A607C, func_021A60DC, func_021A61B0, func_021A6200, func_021A6278, func_021A627C, func_021A62B4, func_021A62D8, func_021A62FC, func_021A6338, func_021A635C, func_021A63EC, func_021A63F0, func_021A6428, func_021A6454, func_021A6478, func_021A64B4, func_021A652C, func_021A658C, func_021A661C, func_021A666C, func_021A66E4, func_021A66EC, func_021A66F8, func_021A6708, func_021A6714, func_021A6720, func_021A672C, func_021A6738, func_021A6744, func_021A6750, func_021A675C, func_021A6768, func_021A6774, func_021A6780, func_021A678C, func_021A6798, func_021A67A4, func_021A682C, func_021A6870, func_021A6908, func_021A6974, func_021A69D8, func_021A6A3C, func_021A6A64, func_021A6A8C, func_021A6AA0, func_021A6B08, func_021A6B30, func_021A6B50, func_021A6B88, func_021A6B9C, func_021A6BAC, func_021A6BB4, func_021A6C30, func_021A6C4C, func_021A6C64, func_021A6C6C, func_021A6CB8, func_021A6D30, func_021A6D3C, func_021A6D48, func_021A6D58, func_021A6D9C, func_021A6DA4, func_021A6DC0, func_021A6DC4, func_021A6E30, func_021A6F18, func_021A6F24, func_021A6F4C, func_021A6F5C, func_021A7010, func_021A70D0, func_021A712C, func_021A7198, func_021A71E4, func_021A7258
 * address:  0x021A1AAC
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
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_021A15D4  0x021A15D4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DDE6C     0x021DDE6C  data  ov021  a4
 *   func_021A15F4  0x021A15F4  thumb  ov021
 *   d_021D886C     0x021D886C  data  ov021  a4
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021A1670  0x021A1670  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DDE80     0x021DDE80  data  ov021  a4
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_021A0590  0x021A0590  thumb  ov021
 *   func_021A05D8  0x021A05D8  thumb  ov021
 *   func_021A0618  0x021A0618  thumb  ov021
 *   func_021A065C 0x021A065C thumb ov021
 *   func_0218E188 0x0218E188 thumb ov021
 *   func_021A063C 0x021A063C thumb ov021
 *   func_021A16D4 0x021A16D4 thumb ov021
 *   func_021A16E4 0x021A16E4 thumb ov021
 *   func_021A16E8 0x021A16E8 thumb ov021
 *   func_021A16DC 0x021A16DC thumb ov021
 *   func_021A16E0 0x021A16E0 thumb ov021
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021A01AC  0x021A01AC  thumb  ov021
 *   func_021A01CC  0x021A01CC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01D8  0x021A01D8  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A0354  0x021A0354  thumb  ov021
 *   func_021A0380  0x021A0380  thumb  ov021
 *   func_021A0390  0x021A0390  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_021A03CC  0x021A03CC  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_0207C768  0x0207C768  arm
 *   g_02148B54  0x02148B54  data
 *   func_0204B53C  0x0204B53C  arm
 *   func_0204B528  0x0204B528  arm
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   func_020061F0  0x020061F0  thumb
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_02082BCC  0x02082BCC  arm
 *   data_021D88E8  0x021D88E8  data  a1
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021A1698  0x021A1698  thumb  ov021
 *   func_021A16D8  0x021A16D8  thumb  ov021
 *   d_021EE710     0x021EE710  data  a4
 *   d_021EE710b    0x021EE710  data  a4
 *   func_021A1680  0x021A1680  thumb  ov021
 *   func_0204B294  0x0204B294  arm
 *   func_0204BA20  0x0204BA20  arm
 *   data_021D88E0  0x021D88E0  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02028B50  0x02028B50  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021A0224  0x021A0224  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   d_021DDE90     0x021DDE90  data  a4
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   d_021DDEA8     0x021DDEA8  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02012A90  0x02012A90  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02012AD4  0x02012AD4  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02012AA4  0x02012AA4  thumb
 *   func_021C0CA4  0x021C0CA4  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021BB3C4  0x021BB3C4  thumb
 *   func_0219E664  0x0219E664  thumb
 *   data_021D890C  0x021D890C  data
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0219E634  0x0219E634  thumb
 *   func_0219E570  0x0219E570  thumb
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_021AB5AC  0x021AB5AC  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02012B34  0x02012B34  thumb
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   d_021DDEB8     0x021DDEB8  data  a1
 *   d_021D89A0     0x021D89A0  data  a4
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_02012B30  0x02012B30  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb
 *   func_02197C9C  0x02197C9C  thumb
 *   func_0219C648  0x0219C648  thumb
 *   func_020508EC  0x020508EC  arm
 *   func_0219D208  0x0219D208  thumb  ov021
 *   func_0216CD88  0x0216CD88  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   data_021D89C4  0x021D89C4  data  a4
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021D05D8  0x021D05D8  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 *   func_02164240  0x02164240  thumb  ov010
 *   func_0219F5C8  0x0219F5C8  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029D8C  0x02029D8C  thumb
 *   d_021DDECC     0x021DDECC  data  ov021  a4
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   d_021D8A00     0x021D8A00  data  ov021  a4
 *   d_021D8A0C     0x021D8A0C  data  ov021  a4
 *   d_021D89F4     0x021D89F4  data  ov021  a4
 *   d_021D8A2C     0x021D8A2C  data  a4
 *   func_0202E83C  0x0202E83C  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0219F7CC  0x0219F7CC  thumb  ov021
 *   func_021AB140  0x021AB140  thumb  ov021
 *   func_021AB404  0x021AB404  thumb  ov021
 *   func_021AB410  0x021AB410  thumb  ov021
 *   func_021AB328  0x021AB328  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021AB44C  0x021AB44C  thumb  ov021
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DCE8  0x0216DCE8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_021AB41C  0x021AB41C  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_02163994  0x02163994  thumb  ov010
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB348  0x021AB348  thumb  ov021
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_021640B0  0x021640B0  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   data_021D89EC  0x021D89EC  data  a4
 *   d_021D8A24  0x021D8A24  data  a2
 *   func_02012844  0x02012844  thumb
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626B8  0x021626B8  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   d_021DDF04     0x021DDF04  data  a4
 *   d_021DDEE0     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0219E424  0x0219E424  thumb  ov021
 *   func_0219D724  0x0219D724  thumb  ov021
 *   func_021BB1AC  0x021BB1AC  thumb  ov021
 *   func_021BB1B8  0x021BB1B8  thumb  ov021
 *   func_021BB1C4  0x021BB1C4  thumb  ov021
 *   func_021BB1D0  0x021BB1D0  thumb  ov021
 *   func_021BB1DC  0x021BB1DC  thumb  ov021
 *   func_021BB1E8  0x021BB1E8  thumb  ov021
 *   data_021D8AB8  0x021D8AB8  data  a4
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D5D8  0x0216D5D8  thumb
 *   d_021D8AB0  0x021D8AB0  data  ov021  a4
 *   func_02162598  0x02162598  thumb  ov010
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021BB3AC  0x021BB3AC  thumb  ov021
 *   sub_02030734   0x02030734  arm
 *   data_021DDF1C  0x021DDF1C  data  a1
 *   func_02012AC0  0x02012AC0  thumb
 *   func_0219F058  0x0219F058  thumb  ov021
 *   d_021DDF64     0x021DDF64  data  a1
 *   d_021DDF38  0x021DDF38  data  a4
 *   func_021BB1A0  0x021BB1A0  thumb  ov021
 *   func_021B7A84  0x021B7A84  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *   func_0216DC4C  0x0216DC4C  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_021BB3B8  0x021BB3B8  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218E160  0x0218E160  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0219F0B0  0x0219F0B0  thumb  ov021
 */
#include "../../matched/include/Obj07491.h"
#include "../../matched/include/Obj09548.h"
#include "../../matched/include/Obj00755.h"
#include "../../matched/include/Obj02701.h"
#include "../../matched/include/Obj17998.h"
#include "../../matched/include/Obj01356.h"
#include "../../matched/include/Obj03584.h"
#include "../../matched/include/Obj18000.h"
#include "../../matched/include/Obj18001.h"
#include "../../matched/include/Obj19728.h"
#include "../../matched/include/Obj00954.h"
#include "../../matched/include/Obj19729.h"
#include "../../matched/include/Obj19731.h"
#include "../../matched/include/Obj02702.h"
#include "../../matched/include/Obj12713.h"
#include "../../matched/include/Obj18002.h"
#include "../../matched/include/Obj19740.h"
#include "../../matched/include/Obj18003.h"
#include "../../matched/include/Obj12714.h"
#include "../../matched/include/Obj12084.h"
#include "../../matched/include/Obj19755.h"
#include "../../matched/include/Obj12085.h"
#include "../../matched/include/Obj02344.h"
#include "../../matched/include/Obj07494.h"
#include "../../matched/include/Obj18004.h"
#include "../../matched/include/Obj12086.h"
#include "../../matched/include/Obj18005.h"
#include "../../matched/include/Obj18006.h"
#include "../../matched/include/Obj12722.h"
#include "../../matched/include/Obj19760.h"
#include "../../matched/include/Obj19761.h"
#include "../../matched/include/Obj05861.h"
#include "../../matched/include/Obj18007.h"
#include "../../matched/include/Obj18008.h"
#include "../../matched/include/Obj19763.h"
#include "../../matched/include/Obj18009.h"
#include "../../matched/include/Obj18010.h"
#include "../../matched/include/Obj09180.h"
#include "../../matched/include/Obj00614.h"
#include "../../matched/include/Obj18011.h"
#include "../../matched/include/Obj18012.h"
#include "../../matched/include/Obj18013.h"
#include "../../matched/include/Obj19764.h"
#include "../../matched/include/Obj18014.h"
#include "../../matched/include/Obj18015.h"
#include "../../matched/include/Obj18016.h"
#include "../../matched/include/Obj18017.h"
#include "../../matched/include/Obj19765.h"
#include "../../matched/include/Obj19766.h"
#include "../../matched/include/Obj18018.h"
#include "../../matched/include/Obj19768.h"
#include "../../matched/include/Obj19769.h"
#include "../../matched/include/Obj18019.h"
#include "../../matched/include/Obj18020.h"
#include "../../matched/include/Obj18021.h"
#include "../../matched/include/Obj19771.h"
#include "../../matched/include/Obj12087.h"
#include "../../matched/include/Obj18022.h"
#include "../../matched/include/Obj06010.h"
#include "../../matched/include/Obj18023.h"
#include "../../matched/include/Obj18024.h"
#include "../../matched/include/Obj18025.h"
#include "../../matched/include/Obj18026.h"
#include "../../matched/include/Obj18027.h"
#include "../../matched/include/Obj18028.h"
#include "../../matched/include/Obj18029.h"
#include "../../matched/include/Obj18030.h"
#include "../../matched/include/Obj18031.h"
#include "../../matched/include/Obj18032.h"
#include "../../matched/include/Obj19775.h"
#include "../../matched/include/Obj18033.h"
#include "../../matched/include/Obj19776.h"
#include "../../matched/include/Obj18034.h"
#include "../../matched/include/Obj19777.h"
#include "../../matched/include/Obj18035.h"
#include "../../matched/include/Obj18036.h"
#include "../../matched/include/Obj18037.h"
#include "../../matched/include/Obj18039.h"
#include "../../matched/include/Obj18041.h"
#include "../../matched/include/Obj18042.h"
#include "../../matched/include/Obj18043.h"
#include "../../matched/include/Obj18044.h"
#include "../../matched/include/Obj18045.h"
#include "../../matched/include/Obj19778.h"
#include "../../matched/include/Obj12729.h"
#include "../../matched/include/Obj18046.h"
#include "../../matched/include/Obj18047.h"
#include "../../matched/include/Obj12730.h"
#include "../../matched/include/Obj12731.h"
#include "../../matched/include/Obj05862.h"
#include "../../matched/include/Obj09562.h"
#include "../../matched/include/Obj19780.h"
#include "../../matched/include/Obj12732.h"
#include "../../matched/include/Obj05025.h"
#include "../../matched/include/Obj09563.h"
#include "../../matched/include/Obj03586.h"
#include "../../matched/include/Obj00656.h"
#include "../../matched/include/Obj09565.h"
#include "../../matched/include/Obj18048.h"
#include "../../matched/include/Obj01657.h"
#include "../../matched/include/Obj12735.h"
#include "../../matched/include/Obj09566.h"
#include "../../matched/include/Obj12736.h"
#include "../../matched/include/Obj02083.h"
#include "../../matched/include/Obj19788.h"
#include "../../matched/include/Obj12737.h"
#include "../../matched/include/Obj02084.h"
#include "../../matched/include/Obj12738.h"
#include "../../matched/include/Obj09567.h"
#include "../../matched/include/Obj07498.h"
#include "../../matched/include/Obj19789.h"
#include "../../matched/include/Obj09568.h"
#include "../../matched/include/Obj00262.h"
#include "../../matched/include/Obj19790.h"
#include "../../matched/include/Obj04233.h"
#include "../../matched/include/Obj19791.h"
#include "../../matched/include/Obj19792.h"
#include "../../matched/include/Obj19794.h"
#include "../../matched/include/Obj19795.h"
#include "../../matched/include/Obj19797.h"
#include "../../matched/include/Obj06012.h"
#include "../../matched/include/Obj19798.h"
#include "../../matched/include/Obj19799.h"
#include "../../matched/include/Obj19800.h"
#include "../../matched/include/Obj07499.h"
#include "../../matched/include/Obj19801.h"
#include "../../matched/include/Obj07218.h"
#include "../../matched/include/Obj09569.h"
#include "../../matched/include/Obj09570.h"
#include "../../matched/include/Obj19803.h"
#include "../../matched/include/Obj12739.h"
#include "../../matched/include/Obj06014.h"
#include "../../matched/include/Obj09571.h"
#include "../../matched/include/Obj18049.h"
#include "../../matched/include/Obj18050.h"
#include "../../matched/include/Obj18051.h"
#include "../../matched/include/Obj12088.h"
#include "../../matched/include/Obj18052.h"
#include "../../matched/include/Obj01499.h"
#include "../../matched/include/Obj05027.h"
#include "../../matched/include/Obj09572.h"
#include "../../matched/include/Obj18054.h"
#include "../../matched/include/Obj18055.h"
#include "../../matched/include/Obj18056.h"
#include "../../matched/include/Obj18057.h"
#include "../../matched/include/Obj18058.h"
#include "../../matched/include/Obj04234.h"
#include "../../matched/include/Obj01119.h"
#include "../../matched/include/Obj19806.h"
#include "../../matched/include/Obj19808.h"
#include "../../matched/include/Obj01658.h"
#include "../../matched/include/Obj07501.h"
#include "../../matched/include/Obj18062.h"
#include "../../matched/include/Obj19810.h"
#include "../../matched/include/Obj18063.h"

struct Bank;
struct Node;
struct O;
struct Actor;
struct Pt_021A244C;
struct SoundSys2;
struct Obj_021A2564;
struct Vec2;
struct Obj_021A277C;
struct Obj_021A2AB8;
struct Obj00020;
struct H4;
struct Rec44;
struct Vec12;
struct V3;
struct BigObj;
struct Ctx;
struct VecFx32;
struct Q;
struct SaveBlock;
struct V;
struct VecFx32_021A6E30;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int (*Cb021A2724)(void *, int, int);

typedef struct {
    u8 pad[0x20];
    u32 items[2];
} Obj021A1B50;

typedef struct {
    u32 pad0;
    u32 pad4;
    u16 result;
    u16 busy;
    u16 cur;
    u16 next;
    u32 flag;
    u16 queued;
} Obj021A1C34;

typedef signed short s16;

typedef signed char s8;

typedef signed int s32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 *f20;
    u8 lo24 : 4;
    u8 hi24 : 4;
    u8 pad25;
    u8 state;
    u8 flag;
    u8 pad28[0x18];
    u8 sub40[4];
} Obj_021A1E08;

typedef struct O {
    u32 pad0[8];
    u32 f20;
    u8  lo : 4;
    u8  hi : 4;
    u8  f25;
    u8  f26;
    u8  pad27[0x19];
    u8  f40;
} O;

typedef struct O_021A2050 {
    u32 pad0[9];
    u8  lo : 4;
    u8  hi : 4;
    u8  f25;
    u8  f26;
} O_021A2050;

typedef struct O_021A20C8 {
    u32 pad0[8];
    u32 *f20;
    u8  pad24[2];
    u8  f26;
} O_021A20C8;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A2424;

typedef s32 fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32_021A244C;

typedef struct { short x, y; } Pt_021A244C;

typedef struct { char pad[0x774]; int *list; } Obj_021A2564;

struct PtS {
    s16 x;
    s16 y;
};

typedef short Pt_021A2654;

typedef struct {
    u8 pad[0x24];
    u8 lo : 4;
    u8 hi : 4;
} Obj021A2724;

typedef struct {
    u8 data[0x38];
} Slot021A274C;

typedef struct {
    u8 pad[0x74];
    Slot021A274C slots[0x20];
} Obj021A274C;

typedef struct Node021A277C {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A277C *prev;
    struct Node021A277C *next;
} Node021A277C;

typedef struct {
    u8 pad[0x774];
    Node021A277C *head;
    int count;
} Obj021A277C;

typedef struct Node021A27B8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27B8 *prev;
    struct Node021A27B8 *next;
} Node021A27B8;

typedef struct {
    u8 pad[0x774];
    Node021A27B8 *head;
    int count;
} Obj021A27B8;

typedef struct Node021A27F8 {
    u32 pad0;
    u32 handle;
    u8 pad8[0x28];
    struct Node021A27F8 *prev;
    struct Node021A27F8 *next;
} Node021A27F8;

typedef struct {
    u8 pad[0x48];
    void (*cb_021A1AAC)(Node021A27F8 *n);
} Ops021A27F8;

typedef struct {
    u8 pad[0x20];
    Ops021A27F8 *ops;
    u8 pad24[0x750];
    Node021A27F8 *head;
} Obj021A27F8;

typedef struct {
    char pad0[4];
    unsigned short count;
} Hdr;

typedef struct {
    char pad0[0x18];
    int *arr;
    int pad1c;
    Hdr *hdr;
    char pad24[4];
    char sub[4];
} Obj_021A277C;

typedef struct {
    u8 pad[4];
    u16 count;
} Info021A28A0;

typedef struct {
    u8 pad[0x18];
    u32 *items;
    u8 pad1C[4];
    Info021A28A0 *info;
    u8 pad24[4];
    u8 slots[1];
} Obj021A28A0;

typedef struct {
    char pad0[2];
    unsigned short n;
    char pad4[0x24];
    int f28;
} Hdr_021A28CC;

typedef struct {
    int f0;
    char pad4[0x18];
    int pad1c;
    Hdr_021A28CC *hdr;
    char pad24[4];
    char sub[0x14];
    int f3c;
} Obj_021A28CC;

typedef struct {
    char pad0[2];
    unsigned short n;
} Hdr_021A2924;

typedef struct {
    char pad0[0x20];
    Hdr_021A2924 *hdr;
    char pad24[0x18];
    void *f3c;
} Obj_021A2924;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    char pad8[8];
    int f10;
} Obj_021A29A8;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fa;
    u16 fc;
} Src;

typedef struct {
    char pad0[8];
    unsigned char b8;
    char pad9[3];
} Buf;

typedef struct {
    char pad0[4];
    int f4;
    int f8[2];
    int f10;
} Obj_021A2A18;

typedef struct {
    u32 f0;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
    s32 f14;
    void (*f18)(u32 a, s32 b, u32 c);
} Obj_021A2AB8;

typedef struct {
    u32 arg;
    short x4;
    short timer;
    short reload;
    u8 padA[0xE];
    void (*cb_021A2A84)(u32 arg, int x, int a);
} Obj021A2B8C;

typedef struct { u16 id; u16 x, y, z; } Q;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C30;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C6C;

typedef struct {
    u16 state;
    u16 id;
    u32 pad4;
    u32 flag;
} Snd021A2C98;

typedef struct {
    u8 pad[0x77C];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2CC8;

typedef struct {
    u32 pad0;
    u32 handle;
    u8 pad8[0x774];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2D04;

typedef struct V3 { int x, y, z; } V3;

typedef struct {
    int f0;
    int pad4[4];
    int f14;
} Obj_021A2D30;

typedef struct { s32 a, b; } Pair_021A2D30;

typedef struct {
    u16 a;
    u16 b;
} Pair_021A3190;

typedef struct {
    Pair_021A3190 e[10];
} Row;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A36E4;

typedef struct {
    s16 x;
    s16 z;
    int y;
} Pos021A36E4;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x18];
    Pos021A36E4 pos;
} Tmpl021A36E4;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u8 pad10[8];
    u32 f18;
    void *f1c;
    u16 f20;
    u16 f22;
} Obj021A36E4;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A38A4;

typedef struct {
    u8 pad[0x30];
    short step;
    u16 done;
} Obj021A3C6C;

typedef int (*Step021A3C6C)(Obj021A3C6C *p);

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3CC0;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3CE8;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3D6C;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3E14;

typedef int BOOL;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3EE0;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3F10;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F48;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F70;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F98;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3FC0;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A408C;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u32 wC;
    u32 w10;
} Req;

typedef struct {
    u32 pad0;
    int mode;
    u32 pad8;
    u32 h;
    u8 pad10[0xC];
    u32 x1c;
} Obj021A4224;

typedef struct {
    u32 pad0;
    u32 v;
} Arg021A4224;

typedef struct { u32 mask; int val; s16 a; s16 b; } T1;

typedef struct { int (*fn)(u16); u16 val; s8 a; s8 b; u8 kind; } T2;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A4F58;

typedef int (*Fn021A55A8)(u32 *p, int a);

typedef struct {
    int x;
    int y;
    int z;
} Vec021A56C0;

typedef struct {
    u8 pad[0x14];
    u16 saved;
    u8 flag;
} Obj021A5738;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A5788;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S_021A5EA4;

typedef struct {
    int f0;
    int f4;
} S_021A66F8;

typedef u32 (*Fn)(u8 *p, u32 a, u32 b);

typedef struct {
    int pad[7];
    int f1c;
} S_021A6A3C;

typedef struct S S;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

typedef struct {
    u8 on : 1;
    u8 keep : 1;
    u8 flag : 1;
    u8 st : 5;
    u8 pad;
    s16 cnt;
    u32 val;
} St;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    int f4;
} T;

typedef struct VecFx32_021A6E30 { s32 x; s32 y; s32 z; } VecFx32_021A6E30;

typedef struct Holder_021A6E30 {
    int mode;
    void *f04;
    void *f08;
} Holder_021A6E30;

typedef struct V { u32 x, y, z; } V;

typedef struct ModelParam {
    u8 f0;
    u8 f1;
    u16 f2;
} ModelParam;

typedef struct Record {
    void (*cb[2])(u32 a, u32 *p);
    ModelParam param;
} Record;

typedef struct Holder_021A7258 {
    int mode;
    void *f04;
} Holder_021A7258;

extern void func_02030EAC(struct Node *n);
extern void func_0204B084(u32 v);
extern u32 func_0204B1CC(struct Bank *bank);
extern int func_021A15D4(u32 a);
extern u32 func_020307B0(void *p);
void func_021A15F4(u32 x);
extern int func_02034AC4(s32 handle);
void func_02034A5C(int x);
void func_021A1670(u8 *p);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern int func_021A0244(u8 *p);
extern u32 func_021A0590(u32, u32, u32, u32);
void func_021A05D8(u8 *a);
extern void func_021A0618(u8 *p, u32 a, u32 b, u32 c);
extern int func_021A065C(u8 *p);
int func_0218E188(unsigned char *o);
extern void func_021A063C(u8 *p, u32 b, u32 c);
extern void func_021A16D4(unsigned char *p, unsigned int v);
extern void func_021A16E4(unsigned char *p, unsigned int v);
extern void func_021A16E8(unsigned char *p, unsigned int v);
extern void func_021A16DC(unsigned char *p, unsigned int v);
extern void func_021A16E0(unsigned char *p, unsigned int v);
int func_021A01AC(u32 a, u32 b);
int func_021A01CC(u32 a, u32 b);
int func_021A01B4(u32 a, u32 b);
int func_021A01BC(u32 a, u32 b);
void func_021A01D8(u8 *p);
int func_021A01A4(u32 a, u32 b);
extern void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
extern u32 func_021A01D4(u8 *p);
u8 func_021A0354(u8 *p);
int func_021A0380(int *p);
int func_021A0390(int *p);
int func_021A03A4(int *p);
int func_021A03B8(int *p);
int func_021A03CC(int *p);
void *func_0218EC2C(u8 *p);
void func_02048B30(void *x, Vec021A2424 *out);
extern void func_02048AE8(void *cam, VecFx32_021A244C *out);
extern fx32 func_0207CF3C(const VecFx32_021A244C *a, const VecFx32_021A244C *b);
extern u32 func_0207C768(u32 a, u32 b);
void func_0204B53C(const struct Actor *actor, struct Pt_021A244C *out);
void func_0204B528(struct Actor *actor, const struct Pt_021A244C *src);
int func_02005C64(void);
void func_02028A7C(struct SoundSys2 *s, u32 id);
void func_020061E4(u32 a);
void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who);
void func_020061F0(u32 a, u32 b);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
u32 func_0204B404(struct Obj_021A2564 *p, const struct Vec2 *delta, u32 which);
void func_02082BCC(void *p, int v, int n);
void func_0204B3DC(struct Obj_021A277C *h, unsigned int v);
void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(u32 v);
int func_0204A6C8(int a, int b, int c, int d, int e);
int func_0204AC18(int a, int b, int c, int d, int e, int f, int g);
s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_0204A8D4(u32 i);
void func_0204ADA4(u32 i);
void func_0204AFD8(u32 i);
void func_02082D44(void *src, void *dst, int n);
int func_021A1698(unsigned int a, int b, void *c, int d);
void func_021A16D8(u8 *p, u8 v);
void func_021A1680(u8 *p);
extern struct Obj_021A2AB8 *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B3B4(struct Obj_021A2AB8 *p);
void func_02028B50(u8 *p, int a0);
int func_02006148(u32 a0);
void func_020061F8(int h);
void func_021A0224(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
u16 func_02188C84(u8 *p);
void *func_02188CB4(struct Obj00020 *p);
void func_0216D5E0(int a0, int a1);
void *func_0216D888(void *a);
void func_02188D40(u8 *p, u32 v);
void func_02188CAC(u8 *p, u32 v);
extern u32 func_02188CA4(u8 *p);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_0216D88C(const struct Actor *, struct V3 *);
extern void func_02012A90(struct Rec44 *p, const struct Vec12 *src);
extern u16 func_0216D5F8(void *p);
extern void func_02012AD4(u8 *p, int i);
extern u32 func_02188CFC(u8 *p);
extern void func_02012ABC(struct Rec44 *p, u8 v);
extern void func_0219E2F4(void *o, void *out);
extern void func_02012AA4(struct Rec44 *p, const struct H4 *src);
int func_021C0CA4(u8 *a, int b, int c, int d);
extern u16 func_02188C98(void *p);
extern int func_021AB0D4(void *a, void *b);
extern u32 func_02188C5C(u8 *p);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern int func_0219E664(void *o, u32 k, void *buf);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern void func_0219E634();
extern u32 func_0219E570(u32 o, u32 k, u32 flag);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern u16 func_0216D83C(void *p);
extern u16 func_0216D854(void *p);
extern u16 func_0216D86C(void *p);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_02164280(int x, int y, int *p);
extern void *func_021BB480(void *p);
extern void func_021B7D38(u32, s16 *, int *);
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern int func_021B7C38(u8 *o);
extern void func_0207CCA4();
int func_021AB5AC(unsigned long a, unsigned long b);
int func_021AB11C(u32 attr);
u16 func_021AB0F0(u32 attr);
int func_021AB310(u16 id);
void *func_020120F4(const struct Ctx *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_020142E8(void *bitmap, s32 id);
extern void *func_02188C80(void *p);
extern void *func_0216DE94(void *a, u32 b);
extern u16 func_02012B34(const struct Rec44 *p);
extern void *func_0216CE60(void *a, Tmpl021A36E4 *b, int c);
extern void func_0216D844(void *h, s16 v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern void func_0216D89C(void *h, const Vec021A36E4 *v);
extern void func_0216DB80(unsigned int *p, unsigned int v);
extern int func_0216D3CC(int a0);
extern int func_0216D454();
void func_0216D80C(void *p, u16 v);
void func_0216D818(void *p, u16 v);
void func_0216D824(void *p, u16 v);
extern u32 func_02012B30(u32, u32);
extern u32 func_02012B28(const struct Rec44 *p);
extern void func_02012B2C(struct Rec44 *p, u32 v);
u16 func_0216D598(void *p);
int func_0216D7A8(void *p, unsigned int v);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern int func_02197C9C(u32 a);
extern int func_0219C648(u32 a);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
void func_0219D208(int a, unsigned int id);
int func_0216CD88(int a0);
void func_0216E204(char *a, u32 v);
extern u16 func_0216D608(void *p);
extern void func_021AC154(u32 a);
extern void func_0216D8E0(void *, u32 *);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021ACB38(u32, u32, u32 *, void *, int);
extern void func_021D05D8(void *a, void *b);
extern void func_021ACBC8(u32, int);
extern void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
extern void func_0219F5C8(void *, int);
u32 func_02012A30(const struct BigObj *x);
u16 func_02188C9C(u8 *p);
void func_02029D8C(u32 a0, u32 a1, u32 a2);
extern int func_02163E34(void *, void *, int *);
extern u16 func_021AB0F8(u32);
extern int func_0202E83C(void *a0);
extern void func_02164208(int dir, int *p, int amt);
extern int func_021AB158(u16);
extern int func_021AB164(u16);
extern int func_021AB170(u16);
extern int func_021AB17C(u16);
extern void *func_0216D4B4(char *p);
extern int func_0219F7CC(u32, u32);
int func_021AB140(int a);
int func_021AB404(int a);
int func_021AB410(int a);
int func_021AB328(int a);
int func_02197E7C(int k, int a);
void func_0216D410(int b, int v);
extern int func_021AB44C(u16 id);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DCE8(void *a0, int a1);
extern void *func_0216D568(void *p, u32 v);
int func_02163E58(void *h, Vec021A4F58 *v, int *lim);
char *func_0216D570(char *p, u32 v);
extern int func_021AB41C(u16 id);
extern void func_021AC528(u32, u32);
extern int func_02163994(void *, int, int, int, u32);
extern int func_021AB2DC(u16 id);
extern int func_0216E5B0(void *map, const struct V3 *pos);
void func_0216D674(void *p, u16 v);
u32 func_0216D7DC(void *p);
int func_021AB348(u32 id);
extern int func_02164010(int a);
extern int func_021640B0(int a);
extern int func_02163F10(int a0);
u32 *func_0216D550(u32 *p, u32 v);
extern u32 *func_0216D548(u32 *p, u32 v); /* its third parameter is a scratch it never reads */
extern u32 func_02012844(const struct BigObj *p);
extern int func_02162564(char *p, struct Q *q);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626B8(char *a0, int a1);
extern u16 func_0216D5A0(void *p);
extern void func_0216E0AC(void *o, void *d);
extern void *func_0219E348(void *a);
extern void func_0219E2C0(void *a, void *r);
extern void func_021B8028(u32 v);
extern int func_0219E424(u32 o, u32 k, u32 x);
extern int func_0219D724(u32 a, char *b);
extern int func_021BB1AC(int x);
extern int func_021BB1B8(int x);
extern int func_021BB1C4(int x);
extern int func_021BB1D0(int x);
extern int func_021BB1DC(int x);
extern int func_021BB1E8(int x);
extern u16 func_021642A4(int i);
extern int func_0216D60C(int a0, int a1);
extern void func_0216D5D8(int a, int b);
extern int func_02162598(char *p, struct Q *q);
extern void *func_02188C58(void *p);
extern void *func_020127A4(struct SaveBlock *p);
extern struct H4 *func_02012AB8(struct Rec44 *p);
extern void func_021BB3AC(u8 *p, u32 b);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 func_02012AC0(const struct Rec44 *p);
extern void func_0219F058(u32 a, u16 *o1, u16 *o2);
extern int func_021BB1A0(int x);
extern u32 func_021B7A84(u32 a, V *b, V *c, u16 *d, V *e);
extern u8 func_0201441C(int i);
extern void func_021B7CD8(u32 a, u16 *b, u32 c, u16 *d);
extern int func_0216DC4C(void *m);
extern void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
extern void func_021BB3B8(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);
extern int func_0218EC60(u32 a);
extern int func_0218E160(u32 a);
extern void func_0218F05C(unsigned char *a);
extern int func_0216D600(int a0, u16 a1);
extern void func_0219F0B0(u32 a, u32 b, u32 c);
void func_021A1AAC(u8 *p);
void func_021A1AF4(u8 *p, u16 x);
void func_021A1B38(u32 *p);
int func_021A1B50(Obj021A1B50 *p);
void func_021A1B74(u8 *p, int a, int f);
void func_021A1BDC(Obj021A1C34 *p, u16 x);
int func_021A1BE4(Obj021A1C34 *p, u16 x);
u16 func_021A1BF4(u8 *p);
void func_021A1BF8(u32 *p, u32 v);
void func_021A1C04(u8 *p);
void func_021A1C1C(int a, u32 *p);
int func_021A1C34(Obj021A1C34 *p, u16 x);
void func_021A1C68(u8 *p, int x);
void func_021A1D04(u8 *p, int x);
int func_021A1D78(u16 a, u16 b);
u32 *func_021A1DB4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i);
void func_021A1DF8(u8 *p);
void func_021A1E08(Obj_021A1E08 *o, u16 x);
void func_021A1FEC(O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g);
void func_021A2050(O_021A2050 *p, u32 a, u32 b);
void func_021A20C8(O_021A20C8 *p);
int func_021A2108(u32 a, int b, int c);
int func_021A2114(u32 a, int b, u32 c);
void func_021A2120(u32 *p, int x);
void func_021A2130(u8 *p, u32 b, u32 c, u32 d);
int func_021A213C(u8 *p);
int func_021A2148(unsigned char *o);
void func_021A2154(u8 *p, u32 b, u32 c);
void func_021A2160(unsigned char *o, unsigned int v, int i);
void func_021A2170(unsigned char *o, unsigned int v, int i);
void func_021A2180(unsigned char *o, unsigned int v, int i);
void func_021A2190(unsigned char *o, unsigned int v, int i);
void func_021A21A0(unsigned char *o, unsigned int v, int i);
int func_021A21B0(u8 *a0);
int *func_021A21B8(int *p);
int func_021A21BC(unsigned char *o);
void *func_021A21C8(void *p, int a1);
void func_021A21E0(u32 *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A2228(u8 *p, int a, int b, int c, int d);
int func_021A223C(unsigned char *o, int arg);
int func_021A2248(unsigned char *o, int arg);
void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
void func_021A22E0(u32 *p, int a, int b, int c);
void func_021A231C(u32 *p, int x);
void func_021A232C(u8 *p, u8 a, int b, int c, int d);
void func_021A2390(u32 *p, int a, int b, int c);
int func_021A23B0(u32 a);
int func_021A23D4(int *p);
int func_021A23E8(int *p);
int func_021A23F4(int *p);
int func_021A2400(int *p);
int func_021A240C(int *p);
int func_021A2418(int *p);
void func_021A2424(u8 *p);
void func_021A244C(u8 *o, s32 *outX, s32 *outY);
void func_021A2564(Obj_021A2564 *obj, int px, int py);
void func_021A25BC(unsigned char *o, u16 arg);
void func_021A25CC(u8 *p);
void func_021A25DC(u8 *p, int a);
void func_021A2604(u8 *p, int a, int b);
unsigned char *func_021A2630(unsigned char *o);
unsigned int func_021A2638(unsigned char *o);
void func_021A2640(u8 *a, struct PtS *b);
void func_021A2654(int obj, unsigned short *src);
int func_021A26C4(u32 a, u32 b);
void func_021A26D8(int *p);
int func_021A2724(void *p, Cb021A2724 cb_021A1AAC, int x);
u8 func_021A273C(u8 *p);
Slot021A274C *func_021A274C(Obj021A274C *p);
void func_021A277C(Obj021A277C *p, Node021A277C *n);
void func_021A27B8(Obj021A27B8 *p, Node021A27B8 *n);
void func_021A27F8(Obj021A27F8 *p);
void func_021A282C(void *o, int x);
void func_021A284C(void *o);
void func_021A2860(Obj_021A277C *o, u16 x);
void func_021A28A0(Obj021A28A0 *p);
void func_021A28CC(Obj_021A28CC *o, u16 heap);
void func_021A2924(Obj_021A2924 *o);
void func_021A2968(u8 *p);
u8 func_021A2970(u8 *p);
void func_021A2978(u8 *p, u16 *q, u32 c);
void func_021A2994(u8 *p);
void func_021A29A8(Obj_021A29A8 *o, Src *s, int heap);
void func_021A29F4(u16 *p);
void func_021A2A18(Obj_021A2A18 *o, int idx, void *p, void *src, unsigned short x);
void func_021A2A68(u8 *p, int i, int x);
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5);
void func_021A2AAC(char *p, int a, int b, int c, int d);
s32 func_021A2AB8(Obj_021A2AB8 *o, u32 arg);
int func_021A2B8C(Obj021A2B8C *p, int a);
void func_021A2BB8(void *a);
int func_021A2BC4(u32 a);
void func_021A2BD4(u32 *p, u32 a, const Q *q, int b, u16 e);
void func_021A2C10(u8 *p);
unsigned char *func_021A2C24(unsigned char *o);
u32 func_021A2C28(u8 *p);
void func_021A2C2C(u8 *p, u32 v);
void func_021A2C30(Snd021A2C30 *p, int a, u16 id);
void func_021A2C6C(Snd021A2C6C *p, int a);
void func_021A2C98(Snd021A2C98 *p, int a);
void func_021A2CC8(Obj021A2CC8 *p, u8 mode, u32 value, int n);
void func_021A2CEC(char *p);
u8 func_021A2CF8(char *p);
void func_021A2D04(Obj021A2D04 *p);
void func_021A2D30(Obj_021A2D30 *o, int v, int *out2, int *out1);
void func_021A2D88(int obj, int unused, int y);
int func_021A2DE4(u32 a, u32 b, u32 c, u32 d);
void func_021A2DF0(u32 a);
int func_021A2E34(u32 a, u32 b, u32 c, u32 d);
void func_021A2E44(int a, u32 v);
u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap);
int func_021A2E90(void *a);
void func_021A2EB8(u32 *a);
int func_021A2F20(u32 *p, int a, int b, int c);
void func_021A2F48(u8 *p, u32 a1);
int func_021A2F54(u8 *p);
void func_021A2F60(int *p);
void func_021A2F6C(u32 *p);
void func_021A2F8C(u8 *p, u32 b);
u32 func_021A2F98(u8 *p);
u16 func_021A2FA4(u8 *p, u32 a1);
u32 func_021A2FB0(u32 a);
void func_021A2FD0(void *a);
void func_021A2FE4(u32 *p);
void func_021A3038(u8 *p, struct V3 *out);
void func_021A3044(u8 *p, void *v);
u16 func_021A3050(u8 *p);
void func_021A305C(char *p, u32 b);
u32 func_021A3068(u8 *p);
void *func_021A3074(u8 *p);
u32 func_021A3080(u8 *p);
u32 func_021A308C(u8 *p);
u32 func_021A3098(u8 *p);
void func_021A30A4(u8 *p, u32 b);
u32 func_021A30B0(u8 *p);
int func_021A30BC(u8 *p);
u32 func_021A30C8(void **ctx);
u32 func_021A3128(u32 *a, u32 b);
u16 func_021A3190(int i, int j);
int func_021A31A4(int i, int v);
int func_021A31D0(u16 id);
int func_021A3208(u8 *a);
void func_021A3220(u8 *p, u32 res);
void func_021A322C(u8 *p);
int func_021A3238(u8 *p);
int func_021A3244(void *p);
void func_021A3250(u32 *a);
void func_021A32A8(unsigned char **a, u32 b);
void func_021A330C(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e);
void func_021A3364(u32 *a, int b, int *out);
void func_021A3460(unsigned char **a, s16 *b, s16 *c, s16 *d);
void func_021A3484(unsigned char **a, int b, s32 *c);
int func_021A34EC(u8 *p);
int func_021A34F8(u8 *p);
int func_021A3504(u8 *a, int b, int c);
int func_021A3524(u8 *a, int b, int c);
void func_021A3550(u32 *p, int a);
void func_021A356C(void **p);
int func_021A3584(void *a);
void func_021A35A0(u32 *p, int a);
int func_021A35BC(int a);
void func_021A35E0(u32 *p, u32 heap);
void func_021A35F0(void *a, u32 b, u32 c, u32 d);
void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c);
int func_021A3624(void *a);
void func_021A3644(void **p);
void func_021A3664(u32 *p, u32 heap);
void func_021A3674(u8 *p, u32 b, u32 c);
void func_021A3680(u8 *p, int a1);
void func_021A368C(u8 *p);
u32 func_021A3698(u8 *p);
u32 func_021A36A4(u8 *p);
void func_021A36B0(u8 *p, void *r);
void func_021A36BC(struct Obj18028 *p, void *a1);
int func_021A36C8(u8 *p, u32 k, void *buf);
void func_021A36D4(u8 *p, u32 v);
u32 func_021A36E0(u8 *p);
Obj021A36E4 *func_021A36E4(u32 a, u32 b, const Vec021A36E4 *pos, u32 d, u16 heap);
void func_021A3810(u32 a0);
void func_021A3818(u32 *p);
void func_021A3898(u8 *p, struct VecFx32 *out);
void func_021A38A4(u8 *p, Vec021A38A4 *v);
u16 func_021A3920(u8 *p);
void func_021A392C(void *p, int b);
int func_021A3938(u32 a, u32 b);
void func_021A394C(u8 *p);
u32 func_021A395C(u8 *p);
void *func_021A3960(u8 *p);
void func_021A3964(u8 *p, u32 v);
u32 func_021A3968(u32 *p);
void func_021A396C(u8 *p, u32 v);
u32 func_021A3970(u32 *p);
u32 func_021A3974(u8 *p);
void func_021A3980(u8 *p, u32 a1);
u32 func_021A398C(u8 *p);
u32 func_021A3990(u8 *p);
u32 func_021A3994(u8 *p);
void func_021A3998(u8 *a);
void func_021A39AC(u8 *p, int a);
int func_021A39E4(u8 *p);
int func_021A3A10(u32 a);
int func_021A3A20(u32 a);
int func_021A3A3C(u32 *p);
int func_021A3AA0(u32 a);
u16 func_021A3AB8(u32 a, u32 v);
void func_021A3AC4(u32 a, u32 v);
void func_021A3AD0(u8 *p, u32 v);
u32 func_021A3AD4(u8 *p);
void func_021A3AD8(u8 *p, int a);
void func_021A3B3C(u8 *p, int a);
int func_021A3B78(u8 *p);
int func_021A3B94(u32 *p);
u16 func_021A3BB4(u8 *p, u32 keys);
void func_021A3C24(u8 *p, int a);
int func_021A3C3C(u32 keys);
int func_021A3C54(u32 keys);
u16 func_021A3C6C(Obj021A3C6C *p, int idx);
int func_021A3C94(u32 x);
int func_021A3CB0(u32 a, u32 b);
int func_021A3CC0(Obj021A3CC0 *p);
void func_021A3CE8(void *p);
int func_021A3D08(u8 *p, u32 v);
int func_021A3D50(u32 a, u32 b);
int func_021A3D6C(Obj021A3D6C *p, int a);
int func_021A3DA0(u8 *p);
int func_021A3E14(Obj021A3E14 *p);
u32 func_021A3E48(u32 a1);
int func_021A3E54(u8 *p);
int func_021A3EE0(Obj021A3EE0 *p);
int func_021A3F10(Obj021A3F10 *p);
int func_021A3F48(Obj021A3F48 *p);
u32 func_021A3F64(u32 a1);
int func_021A3F70(Obj021A3F70 *p);
u32 func_021A3F8C(u32 a1);
int func_021A3F98(Obj021A3F98 *p);
u32 func_021A3FB4(u32 a1);
int func_021A3FC0(Obj021A3FC0 *p);
u32 func_021A3FDC(u32 a1);
int func_021A3FE8(u8 *p);
int func_021A408C(Obj021A408C *p);
int func_021A40A8(u8 *p);
void func_021A4114(u32 *p);
u32 *func_021A4140(u32 a, u32 b);
void func_021A41A8(void *a0);
void func_021A41B0(u8 *p, u32 a, u32 b, u32 c);
void func_021A4224(Obj021A4224 *p, int mode, const Arg021A4224 *q);
int func_021A4254(u32 *p, u32 a);
int func_021A428C(u8 *o, int unused, void *c, int flag, int kind);
void func_021A43D8(u8 *p, int k, int dir);
int func_021A4444(u8 *p, u8 *s);
int func_021A448C(u32 *p, int a);
void func_021A44BC(u8 *p);
int func_021A44C8(u8 *p, u8 *s);
int func_021A4544(u8 *p, void *r, u8 *q);
int func_021A4598(u8 *a, void *b, u8 *c);
int func_021A4664(u8 *a, void *b, u8 *c);
int func_021A4698(u8 *a, void *b, u8 *c);
int func_021A46F0(u8 *a, u8 *b);
int func_021A4768(u8 *a, void *b, u8 *c);
int func_021A47B4(u8 *a, void *b, u8 *c);
int func_021A482C(u8 *a, void *b, u8 *c);
int func_021A4890(u8 *a, void *b, u8 *c);
int func_021A48A4(u8 *a, void *b, u8 *c);
int func_021A48C8(u8 *a, u8 *b);
int func_021A491C(u8 *a, void *b, u8 *c);
int func_021A4960(int a);
int func_021A4994(u8 *a, void *b, u8 *c);
int func_021A4A74(u8 *a, void *b, u8 *c);
int func_021A4AA8(u8 *a, void *b, u8 *c);
int func_021A4B00(u8 *a, u8 *b);
int func_021A4B54(u8 *a, void *b, u8 *c);
int func_021A4B98(u8 *a, void *b, u8 *c);
int func_021A4C1C(u8 *a, void *b, u8 *c);
int func_021A4C50(u8 *a, void *b, u8 *c);
void func_021A4CA8(u32 a, u32 b, u32 c);
void func_021A4CF4(u32 a, u32 b, u32 c);
void func_021A4D8C(u32 a, u32 b, u32 c);
void func_021A4D90(u32 *p, int b, u8 *c);
void func_021A4DC0(u32 *a, u32 b, u32 *c);
void func_021A4E78(u32 *p, int b, u8 *c);
void func_021A4E9C(u32 *p, int b, u8 *c);
void func_021A4ED8(u32 *p, int b, u8 *c);
void func_021A4F04(u32 *a, void *a1, u32 a2);
void func_021A4F0C(u32 a, void *b, u32 c);
void func_021A4F50(u32 *a, void *a1, u32 a2);
int func_021A4F58(u32 *p, void *a1, u32 a2);
void func_021A4FA8(u32 a, u32 b, u32 c);
void func_021A5010(u32 a, u32 b, u32 c);
void func_021A5014(u32 *p, int b, u8 *c);
void func_021A5044(u32 *a, u32 b, u32 *c);
void func_021A50BC(u32 *p, int b, u8 *c);
void func_021A50E0(u32 *p, int b, u8 *c);
void func_021A511C(u32 *p, int b, u8 *c);
void func_021A5148(u32 a, u32 b, u32 c);
void func_021A51A4(u32 a, u32 b, u32 c);
void func_021A51A8(u32 *p, int b, u8 *c);
void func_021A51D8(u32 *p, int b, u8 *c);
void func_021A5204(u32 *p, int b, u8 *c);
void func_021A5228(u32 *p, int b, u8 *c);
int func_021A5264(u8 *a, void *b, u32 c, int *d);
int func_021A5304(u32 a, u32 b);
int func_021A530C(u32 a, u32 b);
int func_021A5318(u32 *p, u32 m);
void func_021A5328(u32 a);
void func_021A5334(u32 a);
int func_021A5340(u32 *p);
void func_021A5354(u32 a);
void func_021A5360(u32 a);
void func_021A536C(u32 a);
void func_021A5378(u32 *p, int on);
int func_021A5390(u32 a);
void func_021A53A4(u32 *p, int on);
int func_021A53BC(u32 a);
void func_021A53D0(u32 *p);
int func_021A5408(u8 *a);
int func_021A5458(u32 *p, int unused);
int func_021A548C(u32 *a);
int func_021A54A0(u32 a);
void func_021A54B4(u8 *p);
void func_021A550C(u32 *p);
u32 func_021A552C(u32 *p);
int func_021A5538(u8 *a);
int func_021A55A8(u32 *p, u32 a, int b);
int func_021A55DC(int a);
int func_021A55FC(int a);
int func_021A5610(u32 *p);
u32 func_021A5630(u32 a);
int func_021A569C(u8 *a, void *b, int c, int *d);
u32 func_021A56C0(u32 *p, u32 a1, u32 a2);
void func_021A56F4(u32 a);
void func_021A5708(u32 a);
u32 func_021A5728(u8 *p);
void *func_021A572C(u8 *p);
void func_021A5738(Obj021A5738 *p, int a);
void func_021A575C(u32 *p);
u32 func_021A5764(u8 *p);
int func_021A5768(u32 a, u32 b);
int func_021A5778(u32 a);
int func_021A5788(u32 *p, int k, int *out);
int func_021A57C0(u8 *p, int dir);
int func_021A5810(u8 *p, int dir);
u8 *func_021A5880(u8 *obj, int heap);
void func_021A5920(void *a0);
void func_021A5928(u8 *p, int v);
void func_021A5964(u32 *p);
void func_021A596C(u8 *p, u32 b, u32 c);
int func_021A59DC(u32 a);
u32 func_021A59EC(u32 p);
void func_021A5A00(u8 *p, void *r);
void func_021A5A0C(u8 *p, void *a1);
int func_021A5A18(u8 *p, u32 k, void *buf);
void func_021A5A24(u8 *p);
u32 func_021A5A30(u32 *p);
void func_021A5A34(u32 *p);
int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d);
void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021A5B4C(u32 *p, u32 a, int mode);
int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
void func_021A5B7C(u8 *p);
void func_021A5BC0(u8 *p, u32 k, u32 b, u32 c, u16 d, u32 e);
int func_021A5C3C(u8 *p, u32 b, u32 c, u16 d, u32 e);
int func_021A5CA4(u8 *p, void *b, u32 c, u32 d, u16 e, u32 f);
int func_021A5D04(void *a, void *b, int c, int d, u16 e, int f);
int func_021A5DD8(void *a, void *b, int c, int d, u16 e, int f);
int func_021A5E28(void *a, void *b, int c, int d, u16 e, int f);
void func_021A5EA0(void *p, void *a, int b, int c, int d, int e);
void func_021A5EA4(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A5EDC(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A5F14(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A5F38(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A5F74(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u16 e, u32 f);
int func_021A6014(int *a, int b, int c, u16 d, int e);
int func_021A607C(void *a, void *b, int c, int d, u16 e, int f);
int func_021A60DC(void *a, void *b, int c, int d, u16 e, int f);
int func_021A61B0(void *a, void *b, int c, int d, u16 e, int f);
int func_021A6200(void *a, void *b, int c, int d, u16 e, int f);
void func_021A6278(void *a, void *b, int c, int d, int e, int f);
void func_021A627C(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A62B4(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A62D8(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A62FC(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A6338(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A635C(S_021A5EA4 *a, int sel, int c, int d, u16 e, int f);
void func_021A63EC(void *a, void *b, int c, int d, int e, int f);
void func_021A63F0(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A6428(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A6454(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
void func_021A6478(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f);
int func_021A64B4(int *a, int b, int c, u16 d, int e);
int func_021A652C(void *a, void *b, int c, int d, u16 e, int f);
int func_021A658C(void *a, void *b, int c, int d, u16 e, int f);
int func_021A661C(void *a, void *b, int c, int d, u16 e, int f);
u32 func_021A666C(void *a, void *b, u32 c, u32 d, u16 e, u32 f);
void func_021A66E4(u32 *p, u32 v);
void func_021A66EC(u32 *p, u32 v);
int func_021A66F8(S_021A66F8 *a, int m);
void func_021A6708(void *a);
void func_021A6714(void *a);
void func_021A6720(void *a);
void func_021A672C(void *a);
void func_021A6738(void *a);
void func_021A6744(void *a);
void func_021A6750(void *a);
void func_021A675C(void *a);
void func_021A6768(void *a);
void func_021A6774(void *a);
void func_021A6780(void *a);
void func_021A678C(void *a);
void func_021A6798(void *a);
u32 func_021A67A4(u8 *p);
u32 func_021A682C(u8 *p, u32 a1, u32 a2);
void func_021A6870(u8 *p);
u32 func_021A6908(void *p, u32 a1, u32 a2);
u32 func_021A6974(u8 *p, u32 a1);
u32 func_021A69D8(u8 *p, u32 a1);
int func_021A6A3C(S_021A6A3C *a, int b, int c);
int func_021A6A64(S_021A6A3C *a, int b, int c);
int func_021A6A8C(S *a, int b, int c);
u32 func_021A6AA0(u8 *p, u32 a1);
void func_021A6B08(P *p, u8 v);
void func_021A6B30(P *p);
void func_021A6B50(P *p, int a);
int func_021A6B88(void *a);
void func_021A6B9C(u8 *a);
int func_021A6BAC(void *a);
void func_021A6BB4(St *p, u32 a1, u32 a2);
void func_021A6C30(T *t);
int func_021A6C4C(T *t, int x);
u32 func_021A6C64(u8 *p);
int func_021A6C6C(u8 *p, u32 k);
void func_021A6CB8(struct Obj00020 *a, u32 b, u32 c);
void func_021A6D30(u8 *a0);
void func_021A6D3C(u8 *a0);
int func_021A6D48(u32 a, u32 b, u32 c, u32 d);
u32 *func_021A6D58(void *a, u32 heap);
void func_021A6D9C(void *a0);
void func_021A6DA4(u32 *a);
u32 func_021A6DC0(u8 *p);
void func_021A6DC4(u32 *b, void *a);
void func_021A6E30(void *o, VecFx32_021A6E30 *pos, u16 e);
int func_021A6F18(u32 a, u32 b, u32 c, u32 d);
void func_021A6F24(u32 a, int *v);
int func_021A6F4C(u32 a, u32 b, u32 c, u32 d);
void func_021A6F5C(u32 a, u32 *b);
void func_021A7010(u32 a, u32 *b);
void func_021A70D0(u32 a, u32 *b, u16 c, u32 d, u32 e, u32 f, u32 g);
void func_021A712C(u32 a, u32 *b, u16 c, u32 d, u32 e, u32 f, u32 g);
int func_021A7198(u32 a, u32 *b, V *c, u32 d);
int func_021A71E4(u32 a, u32 *b, u16 *c, u32 d);
void func_021A7258(void *o, Holder_021A7258 *h, int mode, VecFx32_021A6E30 *pos, u16 e, u16 f, u16 g);
extern const u32 d_021D886C[];
extern const u32 d_021D8868[];
extern u8 d_021DDE80[];
extern u8 g_02148B54[];
extern const u8 data_021D88E8[];
extern unsigned char d_021EE710[12];
extern unsigned char d_021EE710b[12];
extern u32 data_021D88E0[];
extern int d_021DDE90;
extern int d_021DDEA8;
extern const Row data_021D890C[];
extern const char d_021DDEB8[];
extern Tmpl021A36E4 d_021D89A0;
extern Step021A3C6C *const data_021D89C4[];
extern u8 d_021DDECC[];
extern T1 d_021D8A00[];
extern T1 d_021D8A0C[];
extern T2 d_021D89F4[];
extern T2 d_021D8A2C[];
extern Fn021A55A8 const data_021D89EC[];
extern const u16 d_021D8A24[4];
extern char d_021DDF04;
extern u16  d_021DDEE0[2];
extern u16  d_021DDEE0b[2];
extern const Fn data_021D8AB8[];
extern const u8 d_021D8AB0[][4];
extern const char data_021DDF1C[];
extern char d_021DDF64;
extern Record d_021DDF38;































/*
 * Addresses are Black-image addresses.
 */
void func_021A1AAC(u8 *p)
{
    int i;

    func_02030EAC((struct Node *)(((struct Obj07491 *)p)->f2C));
    for (i = 0; i < 2; i++) {
        func_021A1DF8((u8 *)(*(u32 *)(p + 0x20 + i * 4)));
    }
    func_021A1C04(p);
    func_0204B084(((struct Obj07491 *)p)->f1C);
    func_0204B1CC((struct Bank *)(((struct Obj07491 *)p)->f18));
    for (i = 0; i < 2; i++) {
        func_021A15D4(((u32 *)p)[i]);
    }
    func_020307B0(p);
}































extern void (*const d_021DDE6C[])(void *p, int x);































void func_021A1AF4(u8 *p, u16 x)
{
    int i;
    u16 t;

    d_021DDE6C[*(u16 *)(p + 8)](p, x);
    if (((struct Obj09548 *)p)->fA == 0) {
        t = ((struct Obj09548 *)p)->f14;
        if (t != 0xFFFF) {
            func_021A1BDC((Obj021A1C34 *)p, t);
            ((struct Obj09548 *)p)->f14 = 0xFFFF;
        }
    }
    for (i = 0; i < 2; i++) {
        func_021A1E08((Obj_021A1E08 *)(*(u32 *)(p + 0x20 + i * 4)), x);
    }
}































void func_021A1B38(u32 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++)
            func_021A15F4(p[i]);
    }
}































int func_021A1B50(Obj021A1B50 *p)
{
    int i;

    if (p != 0) {
        for (i = 0; i < 2; i++) {
            if (func_021A21B0((u8 *)p->items[i]) == 1)
                return 1;
        }
    }
    return 0;
}































/*
 * Addresses are Black-image addresses.
 */
void func_021A1B74(u8 *p, int a, int f)
{
    int i;
    u32 t;

    if (a == ((struct Obj00755 *)p)->fC && a != 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        func_021A20C8((O_021A20C8 *)((struct O *)(*(u32 *)(p + 0x20 + i * 4))));
    }
    func_021A1C04(p);
    ((struct Obj00755 *)p)->fA = 0;
    func_021A1BF8((u32 *)p, d_021D886C[a * 2]);
    t = d_021D8868[a * 2];
    func_021A1FEC((O *)((struct O *)(((struct Obj00755 *)p)->f20)), t, 0, 0, 1, 1, f);
    ((struct Obj00755 *)p)->fC = a;
    ((struct Obj00755 *)p)->fE = 0xFFFF;
}































/*
 * Tail-call thunk: forwards to func_021A1C34 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1BDC(Obj021A1C34 *p, u16 x)
{
    func_021A1C34(p, x);
}































/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A1BE4(Obj021A1C34 *p, u16 x)
{
    func_021A1C34(p, x);
    p->flag = 0;
    return 0;
}







































/*
 * Loads the 16-bit halfword at +0xc of the object.
 */
u16 func_021A1BF4(u8 *p)
{
    return ((struct Obj17998 *)p)->fC;
}







































/*
 * Stores the word at +0x28, then tail calls on it.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1BF8(u32 *p, u32 v)
{
    p[0xa] = v;
    func_02034AC4(v);
}







































void func_021A1C04(u8 *p)
{
    if (((struct Obj00755 *)p)->f28 != -1) {
        func_02034A5C(((struct Obj00755 *)p)->f28);
        ((struct Obj00755 *)p)->f28 = -1;
    }
}







































void func_021A1C1C(int a, u32 *p)
{
    int i;

    for (i = 0; i < 2; i++)
        func_021A1670((u8 *)p[i]);
}







































int func_021A1C34(Obj021A1C34 *p, u16 x)
{
    if (p->busy != 0) {
        p->queued = x;
        return 0;
    }
    if (p->cur == x && x != 0)
        return 0;
    p->next = x;
    p->flag = 1;
    p->result = func_021A1D78(p->cur, p->next);
    p->busy = 1;
    return 1;
}







































/*
 * Addresses are Black-image addresses.
 */
void func_021A1C68(u8 *p, int x)
{
    switch (((struct Obj00755 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A2050((O_021A2050 *)((struct O *)(((struct Obj00755 *)p)->f20)), 1, 1);
        ((struct Obj00755 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0((u8 *)(((struct Obj00755 *)p)->f20)) == 0) {
            func_021A1C04(p);
            ((struct Obj00755 *)p)->fA = 3;
        }
        break;
    case 3:
        func_021A1BF8((u32 *)p, d_021D886C[((struct Obj00755 *)p)->fE * 2]);
        ((struct Obj00755 *)p)->fA = 4;
        break;
    case 4:
        func_021A1FEC((O *)((struct O *)(((struct Obj00755 *)p)->f20)), d_021D8868[((struct Obj00755 *)p)->fE * 2], 1, 1, 1, ((struct Obj00755 *)p)->f10, x);
        ((struct Obj00755 *)p)->f10 = 1;
        ((struct Obj00755 *)p)->fC = ((struct Obj00755 *)p)->fE;
        ((struct Obj00755 *)p)->fE = 0xFFFF;
        ((struct Obj00755 *)p)->fA = 0;
        break;
    }
}







































void func_021A1D04(u8 *p, int x)
{
    u32 t;

    switch (((struct Obj01356 *)p)->fA) {
    case 0:
        break;
    case 1:
        func_021A1FEC((O *)((struct O *)(((struct Obj01356 *)p)->f24)), d_021D8868[((struct Obj01356 *)p)->fE * 2], 1, 1, 2, ((struct Obj01356 *)p)->f10, x);
        func_021A2050((O_021A2050 *)((struct O *)(((struct Obj01356 *)p)->f20)), 1, 2);
        ((struct Obj01356 *)p)->fA = 2;
        break;
    case 2:
        if (func_021A21B0((u8 *)(((struct Obj01356 *)p)->f20)) == 0) {
            t = ((struct Obj01356 *)p)->f20;
            ((struct Obj01356 *)p)->f20 = ((struct Obj01356 *)p)->f24;
            ((struct Obj01356 *)p)->f24 = t;
            ((struct Obj01356 *)p)->fC = ((struct Obj01356 *)p)->fE;
            ((struct Obj01356 *)p)->fE = 0xFFFF;
            ((struct Obj01356 *)p)->f10 = 1;
            ((struct Obj01356 *)p)->fA = 0;
        }
        break;
    }
}







































int func_021A1D78(u16 a, u16 b)
{
    int r = 0;

    switch (a) {
    case 1:
        if ((u16)(b + 0xFFFC) <= 1)
            r = 1;
        break;
    case 4:
        if (b == 1 || b == 5)
            r = 1;
        break;
    case 5:
        if (b == 4 || b == 1)
            r = 1;
        break;
    }
    return r;
}







































u32 *func_021A1DB4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i)
{
    u32 *o;

    o = func_02030734(i, 0x784, 1, (const char *)d_021DDE80, 0x17E);
    o[0] = a;
    o[5] = b;
    o[1] = d;
    o[2] = c;
    o[4] = e;
    o[6] = f;
    o[3] = g;
    ((struct Obj03584 *)o)->f1C = h;
    return o;
}







































/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1DF8(u8 *p)
{
    func_021A20C8((O_021A20C8 *)((struct O *)p));
    func_020307B0(p);
}






































void func_021A1E08(Obj_021A1E08 *o, u16 x)
{
    if (func_021A2CF8((char *)o) != 0 && func_021A0244((u8 *)o->f4) == 0) {
        func_021A2D04((Obj021A2D04 *)o);
        func_021A2CEC((char *)o);
    }
    switch (((u8 *)o)[0x26]) {
    case 0:
        break;
    case 1:
        func_021A282C(o, x);
        func_021A2860((Obj_021A277C *)o, x);
        func_021A28CC((Obj_021A28CC *)o, x);
        func_021A2968((u8 *)o);
        ((u8 *)o)[0x26] = 5;
        break;
    case 2:
        func_021A282C(o, x);
        ((u8 *)o)[0x26] = 3;
        break;
    case 3:
        func_021A2860((Obj_021A277C *)o, x);
        ((u8 *)o)[0x26] = 4;
        break;
    case 4:
        func_021A28CC((Obj_021A28CC *)o, x);
        ((u8 *)o)[0x26] = 5;
        break;
    case 5:
        if (func_021A2724(o, (Cb021A2724)o->f20[11], x) != 0) {
            ((u8 *)o)[0x26] = o->hi24 != 0 ? 6 : 7;
        }
        func_021A2C98((Snd021A2C98 *)o->sub40, o->fC);
        func_021A2968((u8 *)o);
        break;
    case 6:
        if (func_021A2724(o, (Cb021A2724)o->f20[12], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        func_021A27F8((Obj021A27F8 *)o);
        func_021A2C98((Snd021A2C98 *)o->sub40, o->fC);
        break;
    case 7:
        if (func_021A2724(o, (Cb021A2724)o->f20[13], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        func_021A2C98((Snd021A2C98 *)o->sub40, o->fC);
        break;
    case 8:
        func_021A2724(o, (Cb021A2724)o->f20[14], x);
        func_021A27F8((Obj021A27F8 *)o);
        func_021A2C98((Snd021A2C98 *)o->sub40, o->fC);
        break;
    case 9:
        if (func_021A2724(o, (Cb021A2724)o->f20[15], x) != 0) {
            ((u8 *)o)[0x26] = 10;
        }
        func_021A27F8((Obj021A27F8 *)o);
        func_021A2C98((Snd021A2C98 *)o->sub40, o->fC);
        break;
    case 10:
        if (func_021A2724(o, (Cb021A2724)o->f20[16], x) != 0) {
            ((u8 *)o)[0x26] = 11;
        }
        func_021A27F8((Obj021A27F8 *)o);
        func_021A2C98((Snd021A2C98 *)o->sub40, o->fC);
        break;
    case 11:
        if (func_021A2970((u8 *)o) != 0) {
            func_021A2724(o, (Cb021A2724)o->f20[17], x);
        }
        ((u8 *)o)[0x26] = 12;
        break;
    case 12:
        func_021A2924((Obj_021A2924 *)o);
        func_021A28A0((Obj021A28A0 *)o);
        func_021A284C(o);
        func_021A26D8((int *)o);
        ((u8 *)o)[0x26] = 0;
        break;
    }
}






































void func_021A1FEC(O *p, u32 v, u8 b, u32 c, u32 d, u32 e, u32 g)
{
    p->f20 = v;
    p->lo = (u8)d;
    p->hi = (u8)c;
    p->f25 = b;
    if (p->f25 == 0) {
        p->f26 = 1;
    } else if (p->f25 == 1) {
        p->f26 = 2;
    }
    func_021A2C2C(&p->f40, e);
}





































void func_021A2050(O_021A2050 *p, u32 a, u32 b)
{
    u32 r;
    u32 s;

    r = func_021A273C((u8 *)p);
    s = p->f26;
    if (s == 0) {
        return;
    }
    if (r - 4 <= 1) {
        return;
    }
    p->hi = (u8)a;
    p->lo = (u8)b;
    if (s <= 5) {
        p->f26 = 0xb;
        return;
    }
    if (p->hi != 0) {
        p->f26 = 9;
        return;
    }
    p->f26 = 0xb;
}





































void func_021A20C8(O_021A20C8 *p)
{
    if (p->f26 == 0) {
        return;
    }
    if (p->f26 <= 0xb) {
        func_021A2724((Obj_021A1E08 *)p, (Cb021A2724)p->f20[0x11], 0);
    }
    if (p->f26 <= 0xc) {
        func_021A2924((Obj_021A2924 *)((Obj_021A1E08 *)p));
        func_021A28A0((Obj021A28A0 *)((Obj_021A1E08 *)p));
        func_021A284C((Obj_021A1E08 *)p);
    }
    func_021A26D8((int *)p);
}




































/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2108(u32 a, int b, int c)
{
return func_021A0590(((struct Obj18000 *)((u8 *)(a)))->f8, b, c, 60);
}




































int func_021A2114(u32 a, int b, u32 c)
{
return func_021A0590(((struct Obj18001 *)((u8 *)(a)))->f8, b, c, 1);
}




































void func_021A2120(u32 *p, int x)
{
    if (x == 1)
        func_021A05D8((u8 *)p[2]);
}




































void func_021A2130(u8 *p, u32 b, u32 c, u32 d)
{
    func_021A0618((u8 *)(((struct Obj19728 *)p)->f8), b, c, d);
}




































/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
int func_021A213C(u8 *p)
{
    return func_021A065C(*(u8 * *)&((struct Obj00954 *)p)->f8);
}




































/*
 * Unlabelled tail-call leaf (ldr r0,[r0,#0x14]; ldr r3,[pc]; bx r3), filed
 * for lane S30 (callee of ov028 functions).
 */
int func_021A2148(unsigned char *o)
{
    return func_0218E188((unsigned char *)(((struct Obj19729 *)o)->f14));
}




































void func_021A2154(u8 *p, u32 b, u32 c)
{
    func_021A063C(*(u8 * *)&((struct Obj00954 *)p)->f8, b, c);
}



































void func_021A2160(unsigned char *o, unsigned int v, int i)
{
    func_021A16D4((*(unsigned char ***)(o + 0x18))[i], v);
}



































void func_021A2170(unsigned char *o, unsigned int v, int i)
{
    func_021A16E4((*(unsigned char ***)(o + 0x18))[i], v);
}



































void func_021A2180(unsigned char *o, unsigned int v, int i)
{
    func_021A16E8((*(unsigned char ***)(o + 0x18))[i], v);
}



































void func_021A2190(unsigned char *o, unsigned int v, int i)
{
    func_021A16DC((*(unsigned char ***)(o + 0x18))[i], v);
}



































void func_021A21A0(unsigned char *o, unsigned int v, int i)
{
    func_021A16E0((*(unsigned char ***)(o + 0x18))[i], v);
}



































/*
 * Tail-call thunk: forwards to func_021A273C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021A21B0(u8 *a0)
{
    return func_021A273C(a0);
}


































/*
 * Unlabelled 4-byte leaf: returns field 0x3c (ldr r0,[r0,#0x3c]).
 */
int *func_021A21B8(int *p)
{
    return (int *)p[15];
}



































/*
 * Unlabelled leaf (ldr r1,[pc]; ldr r0,[r0,r1]; bx lr; pool 0x778), filed
 * for lane S30 (callee of ov027/ov028 functions).
 */
int func_021A21BC(unsigned char *o)
{
    return ((struct Obj19731 *)o)->f778;
}



































void *func_021A21C8(void *p, int a1)
{
    void *r = (void *)func_021A274C((Obj021A274C *)p);

    if (r != 0)
        func_021A277C((Obj021A277C *)p, (Node021A277C *)r);
    return r;
}



































void func_021A21E0(u32 *p)
{
    if (func_021A2BC4((u32)p) != 0)
        func_021A27B8((Obj021A27B8 *)p[0], (Node021A27B8 *)p);
}



































void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h)
{
    func_021A2A84((u32)(p + 0x4C), (u32)p, b, a, c, d, e, f, g, h);
}



































void func_021A2228(u8 *p, int a, int b, int c, int d)
{
    func_021A2AAC((char *)(p + 0x4C), a, b, c, d);
}



































int func_021A223C(unsigned char *o, int arg)
{
    return func_021A2AB8((Obj_021A2AB8 *)(o + 0x4C), arg);
}



































/*
 * Unlabelled tail-call stub, filed for lane S30 (callee of ov027 functions).
 */
int func_021A2248(unsigned char *o, int arg)
{
    return func_021A2B8C((Obj021A2B8C *)(o + 0x4C), arg);
}


































void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w)
{
    int j;
    u8 *cur;
    int cnt;
    int i;
    u8 *next;

    fn(p, n, w);
    cnt = 0;
    cur = *(u8 * *)&((struct Obj02702 *)p)->f774;
    if (cur == 0) {
        return;
    }
    next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        j = 0;
        if (cnt > 0) {
            do {
                ((void (*)(u8 *))(*(u32 *)(*(u32 *)(p + 0x20) + 0x48)))(cur);
                if (func_021A2BC4((u32)cur) == 0) {
                    break;
                }
                j++;
            } while (j < cnt);
        }
        cur = next;
        next = *(u8 * *)&((struct Obj12713 *)cur)->f34;
        if (i >= m) {
            if (i % m == 0) {
                cnt += k;
            }
        }
        if (cur == *(u8 * *)&((struct Obj02702 *)p)->f774) {
            break;
        }
        i++;
    } while (i < n);
}


































void func_021A22E0(u32 *p, int a, int b, int c)
{
    if (c == 1) {
        func_021A01AC(p[1], 0);
        func_021A01CC(p[1], 0x1F);
        func_021A01B4(p[1], a);
        func_021A01BC(p[1], b);
        func_021A01D8((u8 *)p[1]);
        func_021A01A4(p[1], 1);
    }
}


































void func_021A231C(u32 *p, int x)
{
    if (x == 1)
        func_021A01A4(p[1], 0);
}


































void func_021A232C(u8 *p, u8 a, int b, int c, int d)
{
    int h;

    if (d == 1) {
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
        return;
    }
    if (d == 2) {
        if (a == func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4))) {
            func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
            return;
        }
        h = c / 2;
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), 0x7FDF, func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4)), h);
        func_021A2CC8((Obj021A2CC8 *)p, a, b, h);
    }
}


































void func_021A2390(u32 *p, int a, int b, int c)
{
    if (c == 1)
        func_021A01FC((u8 *)p[1], a, func_021A01D4((u8 *)p[1]), b);
}


































int func_021A23B0(u32 a)
{
if (func_021A0244((u8 *)(((struct Obj18002 *)((u8 *)(a)))->f4)) != 0) {
    return 0;
}
if (func_021A2CF8((char *)a) == 0) {
    return 1;
}
return 0;
}


































int func_021A23D4(int *p)
{
    if (func_021A0354((u8 *)p[4]) == 1) {
        return 1;
    }
    return 0;
}

































/*
 * Unlabelled tail-call stub, filed as a blocker of the ov024 lane S26.
 */
int func_021A23E8(int *p)
{
    return func_021A0380((int *)p[4]);
}

































int func_021A23F4(int *p)
{
    return func_021A0390((int *)p[4]);
}

































int func_021A2400(int *p)
{
    return func_021A03A4((int *)p[4]);
}
































int func_021A240C(int *p)
{
    return func_021A03B8((int *)p[4]);
}
































int func_021A2418(int *p)
{
    return func_021A03CC((int *)p[4]);
}






























void func_021A2424(u8 *p)
{
    Vec021A2424 v;

    if (((struct Obj02702 *)p)->f14 != 0) {
        func_02048B30(func_0218EC2C((u8 *)(((struct Obj02702 *)p)->f14)), &v);
        *(Vec021A2424 *)(p + 0x68) = v;
    }
}


































/*
 * func_0207C768 is FX_Div, func_0207CF3C VEC_Distance.
 *
 * Addresses are Black-image addresses.
 */
void func_021A244C(u8 *o, s32 *outX, s32 *outY)
{
    VecFx32_021A244C pos;
    VecFx32_021A244C tgt;
    fx32 w;
    fx32 h;
    fx32 dx;
    fx32 dz;
    fx32 sx;
    fx32 sy;
    void *cam;

    if (((struct Obj00954 *)o)->f14 == 0) {
        *outX = 0;
        *outY = 0;
        return;
    }
    cam = func_0218EC2C((u8 *)((struct Obj00954 *)o)->f14);
    func_02048B30(cam, (Vec021A2424 *)&pos);
    func_02048AE8(cam, &tgt);
    dx = pos.x - ((VecFx32_021A244C *)(o + 0x68))->x;
    dz = pos.z - ((VecFx32_021A244C *)(o + 0x68))->z;
    if ((dx < 0 ? -dx : dx) > 0x3E8000 || (dz < 0 ? -dz : dz) > 0x64000) {
        *(VecFx32_021A244C *)(o + 0x68) = pos;
        *outX = 0;
        *outY = 0;
        return;
    }
    func_021A2D30((Obj_021A2D30 *)g_02148B54, func_0207CF3C(&pos, &tgt), (int *)&w, (int *)&h);
    w = func_0207C768(w, 0x100000);
    h = func_0207C768(h, 0xC0000);
    sx = 0x1000;
    if (dx < 0) {
        sx = -0x1000;
        dx = -dx;
    }
    dx = func_0207C768(dx, w);
    if (sx < 0) {
        dx = 0 - dx;
        dx += 0x1000;
    }
    sy = 0x1000;
    if (dz < 0) {
        sy = -0x1000;
        dz = -dz;
    }
    dz = func_0207C768(dz, h);
    if (sy < 0) {
        dz = 0 - dz;
        dz += 0x1000;
    }
    if (dx + dz != 0) {
        *(VecFx32_021A244C *)(o + 0x68) = pos;
    }
    *outX = dx >> 12;
    *outY = dz >> 12;
}



































void func_021A2564(Obj_021A2564 *obj, int px, int py)
{
    int *p = obj->list;
    int h;
    int y;
    int x;
    Pt_021A244C pt;

    if (p != 0) {
        x = (short)px;
        y = (short)py;
        do {
            h = func_021A2C28((u8 *)((int)p));
            func_0204B53C((const struct Actor *)h, (struct Pt_021A244C *)(&pt));
            pt.x = pt.x - x;
            pt.y = pt.y - y;
            func_0204B528((struct Actor *)h, (const struct Pt_021A244C *)(&pt));
            p = (int *)p[0x34 / 4];
        } while (p != obj->list);
    }
}



































/*
 * Unlabelled tail-call stub, filed for the ov026 lane.
 */
void func_021A25BC(unsigned char *o, u16 arg)
{
    func_021A2C30((Snd021A2C30 *)(o + 0x40), ((struct Obj19740 *)o)->fC, arg);
}



































/*
 * Tail call with the object displaced by 0x40 and the word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A25CC(u8 *p)
{
    func_021A2C6C((Snd021A2C6C *)(p + 0x40), ((struct Obj18003 *)p)->fC);
}



































void func_021A25DC(u8 *p, int a)
{
    if (func_02005C64() == 0) {
        if (((struct Obj00954 *)p)->f48 != 0)
            func_02028A7C((struct SoundSys2 *)(((struct Obj00954 *)p)->fC), a);
        else
            func_020061E4(a);
    }
}



































void func_021A2604(u8 *p, int a, int b)
{
    if (func_02005C64() == 0) {
        if (((struct Obj12714 *)p)->f48 != 0)
            func_02028ACC((struct SoundSys2 *)(((struct Obj12714 *)p)->fC), a, b);
        else
            func_020061F0(a, b);
    }
}



































unsigned char *func_021A2630(unsigned char *o)
{
    return func_021A2C24(o);
}



































unsigned int func_021A2638(unsigned char *o)
{
    return func_021A2C28(o);
}

































/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2640(u8 *a, struct PtS *b)
{
    func_0204B454((struct Actor *)func_021A2C28(a), b, 0);
}
































void func_021A2654(int obj, unsigned short *src)
{
    Pt_021A2654 pt[2];

    pt[0] = src[0];
    pt[1] = src[1];
    if (pt[0] > 320) {
        pt[0] = pt[0] % 320;
    } else if (pt[0] < -64) {
        pt[0] = pt[0] + 320;
    }
    if (pt[1] > 256) {
        Pt_021A2654 *py;
        py = &pt[1];
        *py = *py % 256;
    } else if (pt[1] < -64) {
        pt[1] = pt[1] + 256;
    }
    func_0204B404((struct Obj_021A2564 *)func_021A2C28((u8 *)obj), (const struct Vec2 *)pt, 0);
}































int func_021A26C4(u32 a, u32 b)
{
return func_0204B404((struct Obj_021A2564 *)(func_021A2C28((u8 *)a)), (const struct Vec2 *)b, 0);
}































void func_021A26D8(int *p)
{
    int f0;
    int f4;
    int f10;
    int f8;
    int f18;
    int f14;
    int fc;
    unsigned short h;

    f0 = p[0];
    f4 = p[1];
    f14 = p[5];
    f10 = p[4];
    fc = p[3];
    f8 = p[2];
    h = *(unsigned short *)&p[7];
    f18 = p[6];
    func_02082BCC(p, 0, 0x784);
    p[5] = f14;
    p[0] = f0;
    p[3] = fc;
    p[1] = f4;
    *(unsigned short *)&p[7] = h;
    p[2] = f8;
    p[6] = f18;
    p[4] = f10;
}































int func_021A2724(void *p, Cb021A2724 cb_021A1AAC, int x)
{
    if (cb_021A1AAC != 0)
        return cb_021A1AAC(p, ((Obj021A2724 *)p)->lo, x);
    return 1;
}































u8 func_021A273C(u8 *p)
{
    return data_021D88E8[p[0x26]];
}































Slot021A274C *func_021A274C(Obj021A274C *p)
{
    int i;
    for (i = 0; i < 0x20; i++) {
        if (func_021A2BC4((u32)((Slot021A274C *)((u8 *)p + 0x74) + i)) == 0) {
            p = (Obj021A274C *)((u8 *)p + 0x74);
            return (Slot021A274C *)p + i;
        }
    }
    return 0;
}






























void func_021A277C(Obj021A277C *p, Node021A277C *n)
{
    Node021A277C *tail;

    p->count++;
    if (p->head == 0) {
        p->head = n;
        n->next = n;
        p->head->prev = n;
        return;
    }
    tail = p->head->prev;
    n->prev = tail;
    n->next = tail->next;
    tail->next->prev = n;
    tail->next = n;
    func_0204B3DC((struct Obj_021A277C *)n->handle, 1);
}






























void func_021A27B8(Obj021A27B8 *p, Node021A27B8 *n)
{
    p->count--;
    if (p->head == n) {
        if (n->next == n)
            p->head = 0;
        else
            p->head = n->next;
    }
    n->next->prev = n->prev;
    n->prev->next = n->next;
    n->next = 0;
    n->prev = 0;
    func_0204B3DC((struct Obj_021A277C *)n->handle, 0);
}






























void func_021A27F8(Obj021A27F8 *p)
{
    Node021A27F8 *cur = p->head;
    Node021A27F8 *nx;

    if (cur != 0 && p->ops->cb_021A1AAC != 0) {
        nx = cur->next;
        do {
            p->ops->cb_021A1AAC(cur);
            cur = nx;
            nx = nx->next;
        } while (cur != p->head && p->head != 0);
    }
}






























/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021A282C(void *o, int x)
{
    u8 *b = (u8 *)o;
    func_021A2978(b + 0x28, *(u16 **)(b + 0x20), x);
    func_021A29A8((Obj_021A29A8 *)(b + 0x28), (Src *)(*(void **)(b + 0x20)), x);
}






























void func_021A284C(void *o)
{
    func_021A29F4((u16 *)((u8 *)o + 0x28));
    func_021A2994((u8 *)o + 0x28);
}






























void func_021A2860(Obj_021A277C *o, u16 x)
{
    int i;

    for (i = 0; i < o->hdr->count; i++) {
        func_021A2A18((Obj_021A2A18 *)o->sub, i, (void *)(o->arr[i]), (char *)o->hdr + 0xe + i * 12, x);
    }
}






























void func_021A28A0(Obj021A28A0 *p)
{
    int i;

    for (i = 0; i < p->info->count; i++)
        func_021A2A68(p->slots, i, p->items[i]);
}





























void func_021A28CC(Obj_021A28CC *o, u16 heap)
{
    int i;

    o->f3c = (int)func_02030734(heap, o->hdr->f28, 1, (const char *)&d_021DDE80, 0x874);
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            func_021A2BD4((u32 *)((char *)o + 0x74 + i * 0x38), (u32)o, (const Q *)o->sub, o->f0, heap);
        }
    }
}





























void func_021A2924(Obj_021A2924 *o)
{
    int i;

    if (o->f3c != 0) {
        func_020307B0(o->f3c);
        o->f3c = 0;
    }
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            func_021A2C10((u8 *)((char *)o + 0x74 + i * 0x38));
            func_021A2BB8((char *)o + 0x74 + i * 0x38);
        }
    }
    func_021A25CC((u8 *)o);
}





























/*
 * Unlabelled leaf (listed as .word data): sets the byte at offset 0x27.
 * Called by func_021A1E08.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2968(u8 *p)
{
    p[0x27] = 1;
}





























/*
 * Unlabelled leaf (listed as .word data): reads the byte at offset 0x27.
 * Called by func_021A1E08.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021A2970(u8 *p)
{
    return p[0x27];
}





























void func_021A2978(u8 *p, u16 *q, u32 c)
{
    if (q[1] != 0 || q[2] != 0)
        ((struct Obj19755 *)p)->f10 = func_020490F4(q[0], c);
}





























/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2994(u8 *p)
{
    u32 v = ((struct Obj12085 *)p)->f10;
    if (v != 0) {
        func_02049238(v);
        ((struct Obj12085 *)p)->f10 = 0;
    }
}





























void func_021A29A8(Obj_021A29A8 *o, Src *s, int heap)
{
    if (s->f2 != 0) {
        o->f2 = func_0204A6C8(o->f10, s->f6, 0, 0, heap);
        o->f4 = func_0204AC18(o->f10, s->f8, 0, 0, 0, 1, heap);
        o->f6 = func_0204AF28((void *)o->f10, s->fa, s->fc, heap);
        o->f0 = 1;
    }
}





























void func_021A29F4(u16 *p)
{
    if (p[0] != 0) {
        func_0204A8D4(p[1]);
        func_0204ADA4(p[2]);
        func_0204AFD8(p[3]);
        p[0] = 0;
    }
}





























/*
 * Note: the original loads the pool word for 0x021EE710 twice (once for the
 * memcpy dst and the 3rd argument, once for the byte-8 test); the second
 * name is an alias at the same address that stops the compiler CSEing them.
 */
void func_021A2A18(Obj_021A2A18 *o, int idx, void *p, void *src, unsigned short x)
{
    func_02082D44(src, d_021EE710, 12);
    if (d_021EE710b[8] != 0x1f) {
        d_021EE710b[8] = 0x1f;
    }
    func_021A1698((unsigned int)p, o->f10, d_021EE710, x);
    func_021A16D4(p, 0);
    func_021A16D8(p, 0x20);
    o->f8[idx] = 1;
}





























void func_021A2A68(u8 *p, int i, int x)
{
    u32 *s = (u32 *)(p + 8);

    if (s[i] != 0) {
        func_021A1680((u8 *)x);
        s[i] = 0;
    }
}
































/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2A84(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u32 e2, u32 e3, u32 e4, u32 e5)
{
((struct Obj02344 *)((u8 *)(a)))->f0 = b;
((struct Obj02344 *)((u8 *)(a)))->f6 = 0;
((struct Obj02344 *)((u8 *)(a)))->fA = 0;
((struct Obj02344 *)((u8 *)(a)))->f4 = d;
((struct Obj02344 *)((u8 *)(a)))->fC = e0;
((struct Obj02344 *)((u8 *)(a)))->f8 = c;
((struct Obj02344 *)((u8 *)(a)))->fE = e1;
((struct Obj02344 *)((u8 *)(a)))->f10 = e2;
((struct Obj02344 *)((u8 *)(a)))->f12 = e3;
((struct Obj02344 *)((u8 *)(a)))->f14 = e4;
((struct Obj02344 *)((u8 *)(a)))->f18 = e5;
return a;
}
































void func_021A2AAC(char *p, int a, int b, int c, int d)
{
    ((struct Obj07494 *)p)->fC = a;
    ((struct Obj07494 *)p)->fE = b;
    ((struct Obj07494 *)p)->f10 = c;
    ((struct Obj07494 *)p)->f14 = d;
}
































/*
 * Addresses are Black-image addresses.
 */
s32 func_021A2AB8(Obj_021A2AB8 *o, u32 arg)
{
    u32 flags;
    s32 neg;

    flags = 0;
    if (o->f10 == 0) {
        flags |= 1;
    } else {
        neg = o->f10 > 0 ? 0 : 1;
        if ((o->f8 >= o->fE && neg == 0) || (o->f8 <= o->fE && neg == 1)) {
            flags |= 1;
            o->f8 = o->fE;
        }
    }
    if (o->f14 == 0) {
        flags |= 2;
    } else {
        neg = o->f14 > 0 ? 0 : 1;
        if ((o->f4 >= o->fC && neg == 0) || (o->f4 <= o->fC && neg == 1)) {
            flags |= 2;
            o->f4 = o->fC;
        }
    }
    o->f6--;
    if (o->f6 <= 0) {
        o->f18(o->f0, o->f4, arg);
        o->f6 = o->f8;
        if (!(flags & 1)) {
            o->f8 += o->f10;
        }
        if (!(flags & 2)) {
            o->fA++;
            if (o->fA >= o->f12) {
                o->fA = 0;
                o->f4 += (s16)o->f14;
            }
        }
    }
    return (flags & 1) ? 1 : 0;
}
































int func_021A2B8C(Obj021A2B8C *p, int a)
{
    p->timer--;
    if (p->timer <= 0) {
        p->cb_021A2A84(p->arg, p->x4, a);
        p->timer = p->reload;
        return 1;
    }
    return 0;
}
































/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 56.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2BB8(void *a)
{
    func_02082BCC(a, 0, 56);
}
































int func_021A2BC4(u32 a)
{
if (((struct Obj18004 *)((u8 *)(a)))->f30 != 0) {
    return 1;
}
return 0;
}































void func_021A2BD4(u32 *p, u32 a, const Q *q, int b, u16 e)
{
    p[0] = a;
    p[1] = (u32)func_0204B294((void *)b, q->x, q->y, q->z, data_021D88E0, 0, e);
    func_0204B3DC((struct Obj_021A277C *)((struct Obj_021A2AB8 *)p[1]), 0);
    func_0204BA20((struct Actor *)p[1], 0);
}
































/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2C10(u8 *p)
{
    u32 v = ((struct Obj12086 *)p)->f4;
    if (v != 0) {
        func_0204B3B4((struct Obj_021A2AB8 *)v);
        ((struct Obj12086 *)p)->f4 = 0;
    }
}































/*
 * Unlabelled leaf (adds r0,#8; bx lr), filed for the ov026 lane.
 */
unsigned char *func_021A2C24(unsigned char *o)
{
    return o + 8;
}
































/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021A2C28(u8 *p)
{
    return ((struct Obj18005 *)p)->f4;
}
































/*
 * Field setter at +0x8.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2C2C(u8 *p, u32 v)
{
    ((struct Obj18006 *)p)->f8 = v;
}






























void func_021A2C30(Snd021A2C30 *p, int a, u16 id)
{
    func_021A2C6C((Snd021A2C6C *)p, a);
    if (func_02005C64() == 0) {
        p->state = 1;
        p->id = id;
        if (p->flag != 0)
            func_02028A7C((struct SoundSys2 *)a, p->id);
        else
            func_020061E4(p->id);
    } else {
        p->state = 2;
        p->id = id;
    }
}






























void func_021A2C6C(Snd021A2C6C *p, int a)
{
    if (p->state == 1) {
        p->state = 0;
        if (p->flag != 0)
            func_02028B50((u8 *)a, p->id);
        else
            func_020061F8(func_02006148(p->id));
    }
}






























void func_021A2C98(Snd021A2C98 *p, int a)
{
    if (p->state == 2 && func_02005C64() == 0) {
        p->state = 1;
        if (p->flag != 0)
            func_02028A7C((struct SoundSys2 *)a, p->id);
        else
            func_020061E4(p->id);
    }
}





























void func_021A2CC8(Obj021A2CC8 *p, u8 mode, u32 value, int n)
{
    p->active = 1;
    p->mode = mode;
    p->value = value;
    p->half = n / 2;
}




























void func_021A2CEC(char *p)
{
    p[0x77c] = 0;
}





























u8 func_021A2CF8(char *p)
{
    return p[0x77c];
}





























void func_021A2D04(Obj021A2D04 *p)
{
    func_021A0224((u8 *)p->handle, 0x7FDF, p->value, p->mode, p->mode, p->half);
}


































void func_021A2D30(Obj_021A2D30 *o, int v, int *out2, int *out1)
{
    *out1 = (int)(((long long)(int)func_0207C768((int)v, (int)o->f14) * 0x2000 + 0x800) >> 12);
    *out2 = (int)(((long long)(int)func_0207C768((int)v, (int)o->f0) * 0x2000 + 0x800) >> 12);
}


































void func_021A2D88(int obj, int unused, int y)
{
    int h;
    void *a;
    void *b;
    char *p;

    h = func_02188C84((u8 *)obj);
    p = (char *)func_02030734(h, 0x10, 1, (const char *)&d_021DDE90, 0x68);
    ((struct Obj12722 *)p)->f0 = h;
    ((struct Obj12722 *)p)->f4 = obj;
    a = func_02188CB4((void *)obj);
    b = func_021A3074((void *)a);
    func_0216D5E0((int)b, y);
    func_021A35E0(a, h);
    func_02188D40((u8 *)obj, (u32)func_0216D888(b));
    func_02188CAC((u8 *)obj, (u32)p);
}


































/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A2DE4(u32 a, u32 b, u32 c, u32 d)
{
return func_020307B0((void *)func_02188CA4((u8 *)a));
}


































/*
 * Addresses are Black-image addresses.
 */
void func_021A2DF0(u32 a)
{
    u8 *p = (u8 *)func_02188CA4((u8 *)a);
    void *q = func_02188CB4((void *)a);

    if (((struct Obj19760 *)p)->fC == 0) {
        u32 x = func_020362DC();
        u32 y = func_0203630C();
        u32 f = 0;

        if (func_021A35BC((int)q) == 1)
            f |= 1;
        func_021A35F0(q, x, y, f);
    }
}


































int func_021A2E34(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D888(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}


































void func_021A2E44(int a, u32 v)
{
    ((struct Obj19761 *)((char *)func_02188CA4((u8 *)a)))->fC = v;
}


































u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap)
{
    u32 *o = (u32 *)func_02030734(heap, 0x10, 1, (const char *)&d_021DDEA8, 0x4C);

    o[0] = b;
    o[1] = (u32)func_021A36E4(a, b, (const Vec021A36E4 *)c, d, heap);
    return o;
}


































int func_021A2E90(void *a)
{
if (((struct Obj05861 *)((u8 *)(a)))->f8 != 0) {
    func_021A41A8((void *)((struct Obj05861 *)((u8 *)(a)))->f8);
}
if (((struct Obj05861 *)((u8 *)(a)))->fC != 0) {
    func_021A5920((void *)((struct Obj05861 *)((u8 *)(a)))->fC);
}
func_021A3810(((struct Obj05861 *)((u8 *)(a)))->f4);
return func_020307B0(a);
}


































/*
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --thumb --region arm9 (symbols: data_0209DFA8
 * 0x0209DFA8 data a2):
 *   extern const u16 data_0209DFA8[];
 *   void func_02012AD4(u8 *p, int i) { *(u16 *)(p + 0x18) = data_0209DFA8[i]; }
 *
 * Addresses are Black-image addresses.
 */
void func_021A2EB8(u32 *a)
{
    u8 b[12];
    u8 c[8];
    u32 d = func_021A3994((u8 *)a[1]);
    void *e = func_021A3960((u8 *)a[1]);

    func_0216D88C(e, (struct V3 *)b);
    func_02012A90((struct Rec44 *)d, (const struct Vec12 *)b);
    func_02012AD4((u8 *)d, func_0216D5F8(e));
    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_02012ABC((struct Rec44 *)d, 0);
        return;
    }
    func_0219E2F4(e, c);
    func_02012AA4((struct Rec44 *)d, (const struct H4 *)c);
    func_02012ABC((struct Rec44 *)d, 1);
}


































int func_021A2F20(u32 *p, int a, int b, int c)
{
    int r = 0;

    if (func_02188CFC((u8 *)p[0]) == 0)
        r = func_021C0CA4((u8 *)p[2], a, b, c);
    return r;
}


































/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F48(u8 *p, u32 a1)
{
    func_021A3CB0(((struct Obj18007 *)p)->f4, a1);
}


































int func_021A2F54(u8 *p)
{
    return func_021A3CC0((Obj021A3CC0 *)(((struct Obj18008 *)p)->f4));
}


































/*
 * Unlabelled leaf (a .word run in the ov021 listing): tail-calls
 * func_021A3CE8 with the word at offset 4.  Callee of func_0218B32C.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F60(int *p)
{
    func_021A3CE8((void *)p[1]);
}


































void func_021A2F6C(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A53D0((u32 *)p[2]);
    else
        func_021A5A34((u32 *)p[3]);
}


































/*
 * Tail-call thunk: the object's word at +0x4, second argument forwarded.
 * Unlabelled leaf; its only blocker-caller is func_021C10B4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F8C(u8 *p, u32 b)
{
    func_021A3AD0((u8 *)(((struct Obj19763 *)p)->f4), b);
}

































u32 func_021A2F98(u8 *p)
{
    return func_021A3AD4((u8 *)(((struct Obj18009 *)p)->f4));
}

































u16 func_021A2FA4(u8 *p, u32 a1)
{
    return func_021A3AB8(((struct Obj18010 *)p)->f4, a1);
}

































u32 func_021A2FB0(u32 a)
{
if (func_02188CFC((u8 *)(((struct Obj09180 *)((u8 *)(a)))->f0)) == 0) {
    return func_021A5778(((struct Obj09180 *)((u8 *)(a)))->f8);
}
return func_021A59DC(((struct Obj09180 *)((u8 *)(a)))->fC);
}

































void func_021A2FD0(void *a)
{
func_021A3CB0(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4, 1);
func_021A3CE8((void *)*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4);
}

































void func_021A2FE4(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0) {
        if (func_021A548C((u32 *)p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
        if (func_021A54A0(p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    } else {
        if (func_021A59EC(p[3]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    }
    func_021A3818((u32 *)p[1]);
}

































void func_021A3038(u8 *p, struct V3 *out)
{
    func_021A3898((u8 *)((struct Obj18011 *)p)->f4, (struct VecFx32 *)out);
}

































void func_021A3044(u8 *p, void *v)
{
    func_021A38A4((u8 *)((struct Obj18012 *)p)->f4, (Vec021A38A4 *)v);
}
































u16 func_021A3050(u8 *p)
{
    return func_021A3920((u8 *)(((struct Obj18013 *)p)->f4));
}
































/*
 *          (ov009/ov021 overlap; the ov021 hint does not locate a func_ label).
 *
 * UNBLOCKED: func_021A392C is now an EXACT entry in layout/matched/ov021;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021A305C(char *p, u32 b)
{
    func_021A392C((void *)(((struct Obj19764 *)p)->f4), b);
}
































u32 func_021A3068(u8 *p)
{
    return func_021A395C((u8 *)(((struct Obj18014 *)p)->f4));
}
































void *func_021A3074(u8 *p)
{
    return func_021A3960(*(u8 * *)&((struct Obj00614 *)p)->f4);
}
































u32 func_021A3080(u8 *p)
{
    return func_021A3968((u32 *)(((struct Obj18015 *)p)->f4));
}
































u32 func_021A308C(u8 *p)
{
    return func_021A3970((u32 *)(((struct Obj18016 *)p)->f4));
}
































u32 func_021A3098(u8 *p)
{
    return func_021A3974((u8 *)(((struct Obj18017 *)p)->f4));
}































/*
 * Unlabelled leaf: tail-calls 0x021A3980 with the +4 member and the second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021A30A4(u8 *p, u32 b)
{
    func_021A3980((u8 *)(((struct Obj19765 *)p)->f4), b);
}































/*
 * Forwards the +4 member to 0x021A398C (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A30B0(u8 *p)
{
    return func_021A398C((u8 *)(((struct Obj19766 *)p)->f4));
}































int func_021A30BC(u8 *p)
{
    return func_021A3990((u8 *)(((struct Obj18018 *)p)->f4));
}






























u32 func_021A30C8(void **ctx)
{
    u32 r;

    if (func_02188CFC(ctx[0]) == 0) {
        V3 pos;
        u16 z = func_02188C98(ctx[0]);
        func_021A3038((unsigned char *)ctx, (struct V3 *)&pos);
        r = func_021AB0D4((void *)z, &pos);
    } else if (func_02188CFC(ctx[0]) == 1) {
        Pair_021A2D30 v;
        void *o = func_021A3074((u8 *)ctx);
        void *w = (void *)func_02188C5C(ctx[0]);
        func_0219E2F4(o, &v);
        r = func_021BB3C4(w, (char *)(&v));
    }
    return r;
}






























u32 func_021A3128(u32 *a, u32 b)
{
    u32 r;
    u8 d[12];
    u8 c[8];

    if (func_02188CFC((u8 *)a[0]) == 0) {
        u32 h = func_02188C98((u8 *)a[0]);

        func_021A3364(a, b, (int *)d);
        r = func_021AB0D4((void *)h, d);
    } else if (func_02188CFC((u8 *)a[0]) == 1) {
        void *t = func_021A3074((u8 *)a);
        u32 h = func_02188C5C((u8 *)a[0]);

        func_0219E664(t, b, c);
        r = func_021BB3C4((u8 *)h, (char *)c);
    }
    return r;
}





























/*
 * Halfword a of entry j in row i of the 10-entry table at 0x021D890C.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3190(int i, int j)
{
    return data_021D890C[i].e[j].a;
}





























/*
 * Looks up v in the b column of row i and returns the matching a, else 1.
 *
 * Addresses are Black-image addresses.
 */
int func_021A31A4(int i, int v)
{
    const Pair_021A3190 *e;
    int k;

    k = 0;
    e = data_021D890C[i].e;
    for (; k < 10; k++, e++) {
        if (e->b == v)
            return e->a;
    }
    return 1;
}



























int func_021A31D0(u16 id)
{
    int j;
    int i;
    const Pair_021A3190 *e;

    for (j = 0; j < 2; j++) {
        e = data_021D890C[j].e;
        for (i = 0; i < 10; i++) {
            if (e->a == id)
                return i;
            e++;
        }
    }
    return 10;
}



























int func_021A3208(u8 *a)
{
    switch (func_021A3098(a)) {
    case 2:
    case 3:
        return 0;
    }
    return 1;
}



























/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: tail call on the object's
 * word at +0x4, the second argument passing through in r1.
 */
void func_021A3220(u8 *p, u32 res)
{
    func_021A3938(((struct Obj19768 *)p)->f4, res);
}



























/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: tail call on the object's
 * word at +0x4, the same shape as func_021A3038.
 */
void func_021A322C(u8 *p)
{
    func_021A394C((u8 *)(((struct Obj19769 *)p)->f4));
}



























/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3238(u8 *p)
{
    return func_021A3A20(((struct Obj18019 *)p)->f4);
}



























/*
 * Tail-call thunk: ldr r0,[r0,#4]; ldr r3,[pc]; bx r3; .word func_021A3A3C.
 * Unlabelled in the ARM9 listings (the .word run at 0x021A3244 in ov021);
 * blocker target of ov010's func_0216A244 (pkt_0216A244).
 */
int func_021A3244(void *p)
{
    return func_021A3A3C(((struct Obj18020 *)p)->f4);
}



























/*
 * Addresses are Black-image addresses.
 * func_0216DDC0 forwards r0-r3 to func_0216DD60, so it takes four
 * arguments; the fourth is the literal 0 whose register the compiler also
 * uses as the v[0] index.
 */
void func_021A3250(u32 *a)
{
    s16 v[8];
    void *h = func_02188C7C((u8 *)a[0]);

    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_021A3460((unsigned char **)a, &v[2], &v[1], &v[0]);
        func_0216DDC0((u32)h, v[2], v[0], 0);
        return;
    }
    func_0219E634(func_021A3960((u8 *)a[1]), &v[3]);
    func_0219E570((u32)h, (u32)(&v[3]), 0);
}



























/*
 * Addresses are Black-image addresses.
 */
void func_021A32A8(unsigned char **a, u32 b)
{
    s16 v[8];
    void *h = func_02188C7C(a[0]);

    if (func_02188CFC(a[0]) == 0) {
        func_021A3460((unsigned char **)a, &v[2], &v[1], &v[0]);
        func_0216DDDC((u32)h, v[2], v[0], v[1] << 16, b, 0);
        return;
    }
    func_0219E634(func_021A3960(a[1]), &v[3]);
    func_0219E570((u32)h, (u32)(&v[3]), 0);
}



























void func_021A330C(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e)
{
    void *t = func_021A3074((unsigned char *)a);

    if (func_02188CFC(a[0]) == 0) {
        *c = func_0216D83C(t);
        *d = func_0216D854(t);
        *e = func_0216D86C(t);
        *c = *c + func_021641E8(b);
        *e = *e + func_021641F8(b);
    }
}



























void func_021A3364(u32 *a, int b, int *out)
{
    int v[3];
    s16 d[3];
    s16 r[4];
    s16 z;
    s16 y;
    s16 x;
    void *e;
    u32 h;
    int m;

    e = func_021A3960((void *)a[1]);
    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_021A330C((unsigned char **)a, b, &z, &y, &x);
        func_02164280(z, x, out);
        out[1] = y << 16;
        return;
    }
    h = (u32)func_021BB480((void *)func_02188C5C((u8 *)a[0]));
    func_0219E2F4(e, r);
    func_021B7D38(h, r, v);
    func_0219E784((u32)e, b, d);
    m = func_021B7C38((u8 *)h);
    out[0] = v[0] + (int)(((long long)d[0] * m + 0x800) >> 12);
    out[1] = v[1] + (int)(((long long)d[1] * m + 0x800) >> 12);
    out[2] = v[2] + (int)(((long long)d[2] * m + 0x800) >> 12);
}




























/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3460(unsigned char **a, s16 *b, s16 *c, s16 *d)
{
    func_021A330C(a, func_0216D5F8(func_021A3074((u8 *)a)), b, c, d);
}




























/*
 * Addresses are Black-image addresses.
 */
void func_021A3484(unsigned char **a, int b, s32 *c)
{
    s16 v[4];
    s32 t1;
    s32 t2;
    s32 t3;
    void *h = func_021A3960(a[1]);

    if (func_02188CFC(a[0]) == 0) {
        s32 t;

        c[1] = 0;
        c[0] = func_021641E8(b);
        t = func_021641F8(b);
        c[0] = c[0] << 16;
        c[2] = t << 16;
        func_0207CCA4(c, c);
        return;
    }
    func_0219E784((u32)h, b, v);
    t3 = v[2];
    t2 = v[1];
    t1 = v[0];
    c[0] = t1;
    c[1] = t2;
    c[2] = t3;
}




























/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_021A34EC(u8 *p)
{
    return func_021A3A10(((struct Obj18021 *)p)->f4);
}




























/*
 * Unlabelled leaf, tail-call thunk: the object's word at +0x4.
 * Sole blocker of the func_021645E0 MATCH (ov010).
 *
 * Addresses are Black-image addresses.
 */
int func_021A34F8(u8 *p)
{
    return func_021A39E4(*(u8 * *)&((struct Obj19771 *)p)->f4);
}




























int func_021A3504(u8 *a, int b, int c)
{
    int r = func_021A3098(a);

    if (r == 2 || r == 3)
        return 0;
    return func_021AB5AC(b, c);
}




























int func_021A3524(u8 *a, int b, int c)
{
    int r = func_021A3098(a);

    if (func_021AB11C(b) != 0 || r != 2)
        return 0;
    return func_021AB310(func_021AB0F0(c));
}




























void func_021A3550(u32 *p, int a)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A5738((Obj021A5738 *)p[2], a);
}




























void func_021A356C(void **p)
{
    if (func_02188CFC(p[0]) == 0)
        func_021A575C(p[2]);
}




























int func_021A3584(void *a)
{
if (func_02188CFC((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f0)) == 0) {
    return func_021A5764((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f8));
}
return 0;
}




























void func_021A35A0(u32 *p, int a)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A5768(p[2], a);
}




























int func_021A35BC(int a)
{
    if (func_020142E8((void *)func_0201296C(func_020120F4((const struct Ctx *)func_021A30BC((u8 *)a))), 0x963) != 0)
        return 1;
    return 0;
}




























void func_021A35E0(u32 *p, u32 heap)
{
    p[2] = (u32)func_021A4140(p[1], heap);
}




























void func_021A35F0(void *a, u32 b, u32 c, u32 d)
{
    func_021A41B0((u8 *)((struct Obj18022 *)((u8 *)(a)))->f8, b, c, d);
}




























void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c)
{
    void *h = func_021A3960(p[1]);

    *a = func_0216D83C(h);
    *b = func_0216D854(h);
    *c = func_0216D86C(h);
}




























int func_021A3624(void *a)
{
if (func_02188CFC((u8 *)(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f0)) == 0) {
    if (func_021A54A0(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f8) == 1) {
        return 1;
    }
}
return 0;
}




























void func_021A3644(void **p)
{
    if (func_02188CFC(p[0]) == 0 && func_021A54A0((u32)p[2]) == 1)
        func_021A54B4(p[2]);
}




























void func_021A3664(u32 *p, u32 heap)
{
    p[3] = (u32)func_021A5880((u8 *)p[1], heap);
}




























/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3674(u8 *p, u32 b, u32 c)
{
    func_021A596C((u8 *)(((struct Obj18023 *)p)->fC), b, c);
}



























void func_021A3680(u8 *p, int a1)
{
    func_021A5928((u8 *)(((struct Obj18024 *)p)->fC), a1);
}



























void func_021A368C(u8 *p)
{
    func_021A5964((u32 *)(((struct Obj18025 *)p)->fC));
}



























u32 func_021A3698(u8 *p)
{
    return func_021A59EC(((struct Obj18026 *)p)->fC);
}



























u32 func_021A36A4(u8 *p)
{
    return func_021A5A30((u32 *)(((struct Obj18027 *)p)->fC));
}



























/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36B0(u8 *p, void *r)
{
    func_021A5A00(*(u8 * *)&((struct Obj00614 *)p)->fC, r);
}



























/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36BC(struct Obj18028 *p, void *a1)
{
    func_021A5A0C((u8 *)(p->fC), a1);
}



























/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A18.
 *
 * Addresses are Black-image addresses.
 */
int func_021A36C8(u8 *p, u32 k, void *buf)
{
    return func_021A5A18(*(u8 * *)&((struct Obj18029 *)p)->fC, k, buf);
}


























/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A24.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36D4(u8 *p, u32 v)
{
    func_021A5A24((u8 *)(((struct Obj18030 *)p)->fC));
}


























/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021A36E0(u8 *p)
{
    return ((struct Obj18031 *)p)->f8;
}


























Obj021A36E4 *func_021A36E4(u32 a, u32 b, const Vec021A36E4 *pos, u32 d, u16 heap)
{
    Obj021A36E4 *o;
    void *m;
    int k;
    void *h;

    o = func_02030734(heap, 0x34, 1, d_021DDEB8, 0x97);
    o->fc = a;
    o->f8 = b;
    o->f4 = (u32)func_02188C80((void *)b);
    o->f20 = 9;
    o->f22 = 9;
    m = func_02188C7C((void *)b);
    o->f1c = func_0216DE94(m, 0xff);
    o->f18 = d;
    k = func_02012B34((const struct Rec44 *)o->fc);
    h = o->f1c;
    if (h == 0) {
        Tmpl021A36E4 t = d_021D89A0;
        Pos021A36E4 *ps = &t.pos;
        ps->x = (pos->x >> 4) / 4096;
        ps->z = (pos->z >> 4) / 4096;
        ps->y = pos->y;
        if (k == 0xFFFF)
            t.f2 = func_021A31A4(d, func_021A3974((u8 *)o));
        else
            t.f2 = k;
        o->f1c = func_0216CE60(m, &t, 0);
    } else {
        int y;
        int z;
        y = (pos->y >> 4) / 4096;
        z = (pos->z >> 4) / 4096;
        func_0216D844(h, (pos->x >> 4) / 4096);
        func_0216D85C(h, (s16)y);
        func_0216D874((int)h, (s16)z);
        func_0216D89C(h, pos);
        if (k == 0xFFFF)
            func_021A3998((u8 *)o);
    }
    func_0216DB80(o->f1c, 1);
    return o;
}




























/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3810(u32 a0)
{
    func_020307B0((void *)a0);
}




























/*
 * Addresses are Black-image addresses.
 */
void func_021A3818(u32 *p)
{
    u32 h = p[7];
    u32 m;
    u32 old = p[4];

    p[4] = 0;
    m = p[5];
    if (func_0216D3CC(h) == 0) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0 || old == 3)
                p[4] = 1;
            else
                p[4] = 2;
            break;
        case 2:
            p[4] = 2;
            break;
        }
    } else if (func_0216D454(h) == 1) {
        switch (m) {
        case 0:
            break;
        case 1:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        case 2:
            if (old == 0)
                break;
            if (old == 3)
                p[4] = 0;
            else
                p[4] = 3;
            break;
        }
    }
}




























/*
 * Tail-call thunk: the object's word at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3898(u8 *p, struct VecFx32 *out)
{
    func_0216D88C((const struct Actor *)((struct Obj18032 *)p)->f1C, (struct V3 *)out);
}




























void func_021A38A4(u8 *p, Vec021A38A4 *v)
{
    int x = (v->x >> 4) / 4096;
    int y = (v->y >> 4) / 4096;
    int z = (v->z >> 4) / 4096;
    u32 h = ((struct Obj19775 *)p)->f1C;

    func_0216D80C((void *)h, func_0216D83C((void *)h));
    func_0216D818((void *)h, func_0216D854((void *)h));
    func_0216D824((void *)h, func_0216D86C((void *)h));
    func_0216D844((void *)h, (short)x);
    func_0216D85C((void *)h, (short)y);
    func_0216D874(h, (short)z);
    func_0216D89C((void *)h, (const Vec021A36E4 *)v);
}




























u16 func_021A3920(u8 *p)
{
    return func_0216D5F8((void *)(((struct Obj18033 *)p)->f1C));
}




























/*
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x1c]; ldr r3,[pc,#4]; bx r3; nop; .word 0x0216D5E1
 * The pool word carries the Thumb bit for func_0216D5E0, which is traced
 * only in ov010 (0x0216D5E0 is data in ov009), so the hint names ov010.
 */
void func_021A392C(void *p, int b)
{
    func_0216D5E0(((struct Obj19776 *)p)->f1C, b);
}




























/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3938(u32 a, u32 b)
{
func_021A3AD8((u8 *)a, b);
return func_02012B30(((struct Obj18034 *)((u8 *)(a)))->fC, b);
}



























/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov021 func_021A322C (itself a blocker of
 * ov018 func_0217BCDC): tail call on the object's word at +0xC.
 */
void func_021A394C(u8 *p)
{
    func_02012B30((u32)((struct Rec44 *)(((struct Obj19777 *)p)->fC)), 0xFFFF);
}



























/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021A395C(u8 *p)
{
    return ((struct Obj18035 *)p)->f8;
}



























/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
void *func_021A3960(u8 *p)
{
    return ((struct Obj18036 *)p)->f1C;
}



























/*
 * Field setter at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3964(u8 *p, u32 v)
{
    ((struct Obj18037 *)p)->f14 = v;
}


























/*
 * Unlabelled leaf getter at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3968(u32 *p)
{
    return p[5];
}


























/*
 * Field setter at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021A396C(u8 *p, u32 v)
{
    ((struct Obj18039 *)p)->f10 = v;
}


























/*
 * Unlabelled leaf getter at +0x10.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3970(u32 *p)
{
    return p[4];
}


























/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A3974(u8 *p)
{
    return func_02012B28((const struct Rec44 *)(((struct Obj18041 *)p)->fC));
}


























void func_021A3980(u8 *p, u32 a1)
{
    func_02012B2C((struct Rec44 *)(((struct Obj18042 *)p)->fC), a1);
}


























/*
 * Loads the 32-bit word at byte +0x18 of the object.
 */
u32 func_021A398C(u8 *p)
{
    return ((struct Obj18043 *)p)->f18;
}


























/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021A3990(u8 *p)
{
    return ((struct Obj18044 *)p)->f4;
}

























/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021A3994(u8 *p)
{
    return ((struct Obj18045 *)p)->fC;
}

























void func_021A3998(u8 *a)
{
    func_021A3B3C(a, func_021A3974(a));
}

























void func_021A39AC(u8 *p, int a)
{
    u32 x = func_021A398C(p);
    void *h = func_021A3960(p);
    int v = func_021A3190(x, a);

    if (v != func_0216D598(h))
        func_021A3AD8(p, v);
    ((struct Obj19778 *)p)->f2C = 0;
}

























int func_021A39E4(u8 *p)
{
    if (func_0216D7A8(func_021A3960(p), 0) != 0xFFFF) {
        if (((struct Obj12729 *)p)->f2C == 1)
            return 1;
        (((struct Obj12729 *)p)->f2C)++;
    }
    return 0;
}

























int func_021A3A10(u32 a)
{
return func_021A31D0(func_0216D598(func_021A3960((u8 *)a)));
}

























int func_021A3A20(u32 a)
{
if (func_021A31D0(func_0216D598(func_021A3960((void *)a))) != 10) {
    return 1;
}
return 0;
}

























/*
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --arm --region arm9:
 *   int func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 0x28;
 *       u16 v = *(u16 *)(e + 0x1C);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * Addresses are Black-image addresses.
 */
int func_021A3A3C(u32 *p)
{
    u16 v;
    u32 h;
    u32 k;

    h = func_0219C9DC((u8 *)func_0216D520(func_0216D67C((void *)p[7])));
    if (func_02197C9C(p[7]) == 1 && func_0219C648(p[7]) == 1)
        return 1;
    k = func_0216D7A8((void *)p[7], 0);
    if (k != 0xFFFF && func_020508EC((u8 *)h, (u16)k, &v) != 0 && v == (0xFFFF >> 2))
        return 1;
    return 0;
}




































/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3AA0(u32 a)
{
if (func_0216D3CC((int)func_021A3960((u8 *)a)) == 1) {
    return 1;
}
return 0;
}




































/*
 * Widens the second argument to 16 bits before the tail call.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3AB8(u32 a, u32 v)
{
    return func_021A3BB4((u8 *)a, (u16)v);
}




































void func_021A3AC4(u32 a, u32 v)
{
    func_021A3C24((u8 *)a, (u16)v);
}




































/*
 * Field setter at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3AD0(u8 *p, u32 v)
{
    ((struct Obj18046 *)p)->f28 = v;
}




































/*
 * Loads the 32-bit word at byte +0x28 of the object.
 */
u32 func_021A3AD4(u8 *p)
{
    return ((struct Obj18047 *)p)->f28;
}




































void func_021A3AD8(u8 *p, int a)
{
    void *h = func_021A3960(p);
    u32 g = (u32)func_0216D67C(h);
    int r = func_0216D598(h);

    if (a == 1 || a == 4 || r == 1 || r == 4) {
        func_0219D208((int)h, a);
        func_0216CD88(g);
        return;
    }
    func_0216E204(h, func_021A31A4(func_021A398C(p), 0));
    func_0216CD88(g);
    func_0219D208((int)h, a);
    func_0216CD88(g);
}




































void func_021A3B3C(u8 *p, int a)
{
    u32 x = func_021A398C(p);
    void *h = func_021A3960(p);
    int v = func_021A31A4(x, a);

    if (v != func_0216D598(h))
        func_021A3AD8(p, v);
    func_021A3980(p, a);
}




































int func_021A3B78(u8 *p)
{
    int r = func_0216D598(func_021A3960(p));

    if (r == 1 || r == 4)
        return 1;
    return 0;
}




































int func_021A3B94(u32 *p)
{
    int r = 0;

    if ((u16)func_0216D7A8((void *)p[7], 0) != 0xFFFF)
        r = 1;
    return r;
}




































u16 func_021A3BB4(u8 *p, u32 keys)
{
    u32 a;
    u32 b;
    u32 c;
    u32 h1;
    u32 h2;

    a = func_021A3C3C(keys);
    b = func_021A3C54(keys);
    if (a == 9) {
        return b;
    }
    if (b == 9) {
        return a;
    }
    c = func_0216D608(func_021A3960(p));
    h1 = ((struct Obj12730 *)p)->f20;
    h2 = ((struct Obj12730 *)p)->f22;
    if (c != 9) {
        if (a == h1 && b == h2) {
            if (b == c) {
                return b;
            }
            if (a == c) {
                return a;
            }
        }
        if (b != h2) {
            return b;
        }
        return a;
    }
    return b;
}




































void func_021A3C24(u8 *p, int a)
{
    ((struct Obj12731 *)p)->f20 = func_021A3C3C(a);
    ((struct Obj12731 *)p)->f22 = func_021A3C54(a);
}




































/*
 * Unlabelled leaf (no lr save): maps a key mask to a direction, 9 for none.
 * Filed as a blocker of ov021 func_021A3BB4.
 */
int func_021A3C3C(u32 keys)
{
    if (keys & 0x20) {
        return 2;
    }
    if (keys & 0x10) {
        return 3;
    }
    return 9;
}




































int func_021A3C54(u32 keys)
{
    if (keys & 0x40) {
        return 0;
    }
    if (keys & 0x80) {
        return 1;
    }
    return 9;
}




































u16 func_021A3C6C(Obj021A3C6C *p, int idx)
{
    Step021A3C6C *tbl;

    if (p->done == 0) {
        tbl = data_021D89C4[idx];
        while (tbl[p->step](p) == 1)
            ;
    }
    return p->done;
}



































int func_021A3C94(u32 x)
{
    int i = 10;

    if (x != 0) {
        for (i = 0; i < 10; i++) {
            if (x & 1)
                break;
            x >>= 1;
        }
    }
    return i;
}



































int func_021A3CB0(u32 a, u32 b)
{
((struct Obj05862 *)((u8 *)(a)))->f24 = b;
((struct Obj05862 *)((u8 *)(a)))->f30 = 0;
((struct Obj05862 *)((u8 *)(a)))->f32 = 0;
((struct Obj05862 *)((u8 *)(a)))->f2C = 0;
((struct Obj05862 *)((u8 *)(a)))->f2E = 0;
return a;
}

































int func_021A3CC0(Obj021A3CC0 *p)
{
    int i = func_021A3C94(p->mask);

    if (i >= 10)
        return 1;
    if (func_021A3C6C((Obj021A3C6C *)p, i) == 1)
        return 1;
    return 0;
}
































void func_021A3CE8(void *p)
{
    int i = func_021A3C94(((Obj021A3CE8 *)p)->mask);

    if (i < 10) {
        while (func_021A3C6C((Obj021A3C6C *)p, i) == 0)
            ;
    }
}
































int func_021A3D08(u8 *p, u32 v)
{
    if (v == func_0216D598(func_021A3960(p))) {
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    if (func_021A3B78(p) == 1) {
        func_021A3AD8(p, v);
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    func_021A3AD8(p, func_021A3190(func_021A398C(p), 0));
    return 0;
}
































int func_021A3D50(u32 a, u32 b)
{
return func_021A3D08((u8 *)a, func_021A3190(func_021A398C((u8 *)a), b));
}
































int func_021A3D6C(Obj021A3D6C *p, int a)
{
    if (func_021A3B94((u32 *)p) == 1) {
        p->count++;
        func_021A3AD8((u8 *)p, func_021A3190(func_021A398C((u8 *)p), a));
        p->done = 1;
        return 1;
    }
    return 0;
}
































int func_021A3DA0(u8 *p)
{
    u32 buf[3] = { 0, 0, 0 };
    u32 a;
    void *b;
    u32 o;

    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 0);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    func_021A3980(p, 0);
    func_021A4114((u32 *)p);
    if ((o = func_021A3AD4(p)) != 0) {
        func_021AC154(o);
        func_021A3AD0(p, 0);
    }
    func_0216D8E0(b, buf);
    ((struct Obj19780 *)p)->f32 = 1;
    return 0;
}































int func_021A3E14(Obj021A3E14 *p)
{
    func_021A398C((u8 *)p);
    func_021A3960((u8 *)p);
    func_021A3980((u8 *)p, 1);
    func_021A4114((u32 *)p);
    if (func_021A3D50((u32)p, 1) != 1)
        p->step++;
    return 0;
}































/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x1) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x1) and returns 0x0.
 */
u32 func_021A3E48(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x1);

    return 0x0;
}































int func_021A3E54(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;

    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 2);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 2) {
        func_021A3980(p, 2);
    }
    func_021A4114((u32 *)p);
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj12732 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct V3 *)((struct VecFx32 *)buf));
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    ((struct Obj12732 *)p)->f32 = 1;
    return 0;
}































int func_021A3EE0(Obj021A3EE0 *p)
{
    int a = func_021A3974((u8 *)p);

    if (func_021A3D08((u8 *)p, func_021A31A4(func_021A398C((u8 *)p), a)) != 1)
        p->step++;
    return 0;
}































int func_021A3F10(Obj021A3F10 *p)
{
    int a;

    if (func_021A3B94((u32 *)p) == 1) {
        p->count++;
        a = func_021A3974((u8 *)p);
        func_021A3AD8((u8 *)p, func_021A31A4(func_021A398C((u8 *)p), a));
        p->done = 1;
    }
    return 0;
}































int func_021A3F48(Obj021A3F48 *p)
{
    if (func_021A3D50((u32)p, 4) != 1)
        p->step++;
    return 0;
}































/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x4) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x4) and returns 0x0.
 */
u32 func_021A3F64(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x4);

    return 0x0;
}































int func_021A3F70(Obj021A3F70 *p)
{
    if (func_021A3D50((u32)p, 5) != 1)
        p->step++;
    return 0;
}































/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x5) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x5) and returns 0x0.
 */
u32 func_021A3F8C(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x5);

    return 0x0;
}































int func_021A3F98(Obj021A3F98 *p)
{
    if (func_021A3D50((u32)p, 6) != 1)
        p->step++;
    return 0;
}































/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x6) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x6) and returns 0x0.
 */
u32 func_021A3FB4(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x6);

    return 0x0;
}































int func_021A3FC0(Obj021A3FC0 *p)
{
    if (func_021A3D50((u32)p, 9) != 1)
        p->step++;
    return 0;
}































/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x9) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x9) and returns 0x0.
 */
u32 func_021A3FDC(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x9);

    return 0x0;
}































int func_021A3FE8(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;
    u32 e;

    e = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 3);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 3) {
        func_021A3980(p, 3);
    }
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct V3 *)((struct VecFx32 *)buf));
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    func_021D05D8((void *)(((struct Obj05025 *)p)->f1C), (void *)e);
    if (((struct Obj05025 *)p)->f28 != 0) {
        func_021ACBC8(((struct Obj05025 *)p)->f28, 0);
    }
    ((struct Obj05025 *)p)->f32 = 1;
    return 0;
}






























int func_021A408C(Obj021A408C *p)
{
    if (func_021A3D50((u32)p, 8) != 1)
        p->step++;
    return 0;
}






























int func_021A40A8(u8 *p)
{
    s16 v[2];
    int f;
    void *a;
    u32 b;

    func_021A3D6C((Obj021A3D6C *)p, 8);
    if (((struct Obj09563 *)p)->f32 == 1 && func_021A3974(p) == 2) {
        f = 0;
        a = func_021A3960(p);
        b = (u32)func_0216D67C(a);
        v[1] = func_0216D83C(a);
        v[0] = func_0216D86C(a);
        func_02164240(1, &v[1], &v[0], 1);
        if (func_0216DDC0(b, v[1], v[0], 1) != 0) {
            f = 1;
        }
        func_0219F5C8(a, f);
    }
    return 0;
}






























void func_021A4114(u32 *p)
{
    int a = (int)func_020120F4(func_02188C80((void *)p[2]));
    int b = func_02012A30((const struct BigObj *)a);

    func_02029D8C(b, a, (u16)(int)func_02188C9C((u8 *)p[2]));
}





























/*
 * Addresses are Black-image addresses.
 */
u32 *func_021A4140(u32 a, u32 b)
{
    u32 *o;
    int k;

    o = func_02030734(b, 0x20, 1, (const char *)d_021DDECC, 0x17D);
    o[3] = a;
    o[4] = func_021A395C((u8 *)a);
    ((struct Obj03586 *)o)->f18 = 0x546;
    func_021A5354((u32)o);
    k = func_021A3974((u8 *)o[3]);
    switch (k) {
    case 2:
        func_021A3CB0(o[3], 4);
        func_021A3CE8((void *)o[3]);
        break;
    case 3:
        func_021A3CB0(o[3], 0x100);
        func_021A3CE8((void *)o[3]);
        break;
    }
    return o;
}





























/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A41A8(void *a0)
{
    func_020307B0(a0);
}



























void func_021A41B0(u8 *p, u32 a, u32 b, u32 c)
{
    Req s;
    u32 d;
    int e;

    d = func_021A3AB8(*(u32 *)&((struct Obj00656 *)p)->fC, b);
    if (func_021A4254((u32 *)p, d) == 1) {
        func_021A3CC0((Obj021A3CC0 *)(*(u32 *)&((struct Obj00656 *)p)->fC));
        if (func_021A55A8((u32 *)p, d, 0) == 0) {
            s.w0 = a;
            s.w4 = b;
            s.h8 = d;
            s.wC = c;
            s.w10 = 0;
            e = func_021A4444(p, (u8 *)(&s));
            func_021A4224((Obj021A4224 *)p, e, (const Arg021A4224 *)&s);
            func_021A4CA8((u32)p, e, (u32)(&s));
            func_021A43D8(p, e, d);
        }
    }
}


























void func_021A4224(Obj021A4224 *p, int mode, const Arg021A4224 *q)
{
    p->mode = mode;
    func_021A3AC4(p->h, q->v);
    func_021A536C((u32)p);
    func_021A530C((u32)p, 0x20);
    if (mode == 2)
        func_021A5360((u32)p);
    p->x1c = 0;
}


























int func_021A4254(u32 *p, u32 a)
{
    void *h = func_021A3960((unsigned char *)p[3]);

    if (func_0216D3CC((int)h) == 1)
        return 1;
    if (a != 9 && p[0] == 3 && a != func_0216D5F8(h))
        return 1;
    return 0;
}


























/*
 * Picks a sound id from two 12-byte-record tables (attribute-mask table,
 * then predicate-callback table), 0x546 meaning none, and plays it with a
 * repeat counter at +0x1a.
 *
 * Addresses are Black-image addresses.
 * d_021D8A2C carries no ov021 token: with it the hint reads as contested.
 */
int func_021A428C(u8 *o, int unused, void *c, int flag, int kind)
{
    int lim;
    int sel;
    u32 id;
    int mode;
    T1 *t;
    T2 *u;
    u32 bits;

    sel = 0x546;
    lim = 0;
    mode = 0;
    if (func_021A3974((u8 *)(*(u32 *)&((struct Obj00656 *)o)->fC)) == 1) {
        mode = 2;
    } else if (func_021A5318((u32 *)o, 0x20) != 0) {
        mode = 1;
    }
    if (mode == 0) {
        ((struct Obj00656 *)o)->f18 = 0x546;
        ((struct Obj00656 *)o)->f1A = 0;
    }
    if (func_02163E34(func_021A3960(((struct Obj00656 *)o)->fC), c, (int *)&id) == 1) {
        bits = func_021AB0F8(id);
        if (flag == 0) {
            t = d_021D8A00;
        } else {
            t = d_021D8A0C;
        }
        for (; t->mask != 0; t++) {
            if (t->mask & bits) {
                sel = t->val;
                if (mode == 1) {
                    lim = t->a;
                } else if (mode == 2) {
                    lim = t->b;
                }
                break;
            }
        }
        if (sel == 0x546) {
            u = d_021D89F4;
            if (flag != 0) {
                u = d_021D8A2C;
            }
            for (; u->fn != 0; u++) {
                if (u->fn((u16)id) == 1 && (u->kind == 4 || u->kind == kind)) {
                    sel = u->val;
                    if (mode == 1) {
                        lim = u->a;
                    } else if (mode == 2) {
                        lim = u->b;
                    }
                    break;
                }
            }
        }
        if (sel == 0x546) {
            if (flag == 1) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
        } else if (mode != 0) {
            if (((struct Obj00656 *)o)->f18 != sel) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            if (((struct Obj00656 *)o)->f1A != 0 && ((struct Obj00656 *)o)->f1A < lim) {
                sel = 0x546;
            }
            if (((struct Obj00656 *)o)->f1A >= lim) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            ((struct Obj00656 *)o)->f18 = sel;
            ((struct Obj00656 *)o)->f1A = ((struct Obj00656 *)o)->f1A + 1;
        }
        if (sel != 0x546) {
            func_020061E4(sel);
            return 1;
        }
    }
    return 0;
}


























void func_021A43D8(u8 *p, int k, int dir)
{
    u32 buf[3];
    void *a;
    u32 r;

    if (k != 2) {
        ((struct Obj00656 *)p)->f18 = 0x546;
        ((struct Obj00656 *)p)->f1A = 0;
        return;
    }
    a = func_021A3960(((struct Obj00656 *)p)->fC);
    r = func_0202E83C(func_02188C80((void *)(((struct Obj00656 *)p)->f10)));
    func_0216D88C(a, (struct V3 *)((struct VecFx32 *)buf));
    if (func_021A428C(p, k, buf, 0, r) == 0) {
        func_02164208(dir, (int *)buf, 0x10000);
        func_021A428C(p, k, buf, 1, r);
    }
}


























int func_021A4444(u8 *p, u8 *s)
{
    int r;

    r = 0;
    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj09565 *)p)->fC))) {
    case 0:
        r = func_021A44C8(p, s);
        break;
    case 1:
        r = func_021A48C8(p, s);
        break;
    case 2:
    case 3:
        r = func_021A4B00(p, s);
        break;
    }
    return r;
}


























int func_021A448C(u32 *p, int a)
{
    int r = func_0216D5F8(func_021A3960((unsigned char *)p[3]));

    if (a == 9)
        return 0;
    if (a != r && p[0] != 1 && p[0] != 3)
        return 2;
    return 1;
}


























/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A44BC(u8 *p)
{
    func_021A3AA0(((struct Obj18048 *)p)->fC);
}


























int func_021A44C8(u8 *p, u8 *s)
{
    void *a;
    int r;

    a = func_021A3960(((struct Obj09565 *)p)->fC);
    r = 0;
    if (func_021A5610((u32 *)p) == 1 || func_021A53BC((u32)p) == 1) {
        return func_021A46F0(p, s);
    }
    switch (((struct Obj09565 *)p)->f0) {
    case 0:
        r = func_021A4544(p, a, s);
        break;
    case 1:
        r = func_021A4598(p, a, s);
        break;
    case 2:
        r = func_021A4664(p, a, s);
        break;
    case 3:
        r = func_021A4698(p, a, s);
        break;
    }
    return r;
}

























int func_021A4544(u8 *p, void *r, u8 *q)
{
    if (func_0216D3CC((int)r) == 1) {
        if (((struct Obj01657 *)q)->f8 != 9) {
            if (((struct Obj01657 *)q)->f8 != func_0216D5F8(r) && ((struct Obj01657 *)q)->f10 == 0) {
                if ((((struct Obj01657 *)q)->fC & 1) == 0) {
                    return 3;
                }
                if ((2 & ((struct Obj01657 *)q)->f4) == 0) {
                    return 3;
                }
            }
            return func_021A4598(p, r, q);
        }
        return 1;
    }
    return 0;
}

























/*
 * Twin of func_021A4B98 with an extra tile-class check (ids
 * classed 0..3 by func_021AB158/164/170/17C) that returns 5.
 *
 * Addresses are Black-image addresses.
 */
int func_021A4598(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    u16 k;
    u32 t;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return func_021A4544(a, b, c);
    }
    r = func_021A5264(a, b, ((struct Obj01657 *)c)->f8, &sp);
    if (((struct Obj01657 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        k = func_021AB0F0(sp);
        t = func_021AB0F8(sp);
        if (r & 2) {
            cls = 9;
            if (func_021AB158(k)) {
                cls = 0;
            } else if (func_021AB164(k)) {
                cls = 1;
            } else if (func_021AB170(k)) {
                cls = 2;
            } else if (func_021AB17C(k)) {
                cls = 3;
            }
            if (cls != 9 && cls == ((struct Obj01657 *)c)->f8) {
                return 5;
            }
        }
        if (r == 0) {
            if (!(t & 2)) {
                return 2;
            }
            if (((struct Obj01657 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}

























int func_021A4664(u8 *a, void *b, u8 *c)
{
    if (func_0216D3CC((int)b) == 0)
        return 0;
    if (((struct Obj01657 *)c)->f8 == 9)
        return func_021A4544((u8 *)a, b, c);
    return func_021A4598(a, b, c);
}
























int func_021A4698(u8 *a, void *b, u8 *c)
{
    u32 r = func_0216D5F8(b);
    if (((struct Obj01657 *)c)->f8 != 9 && ((struct Obj01657 *)c)->f8 != r) {
        func_0216D4B4((char *)b);
        return func_021A4598(a, b, c);
    }
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return func_021A4544((u8 *)a, b, c);
    }
    return func_021A4598(a, b, c);
}
























int func_021A46F0(u8 *a, u8 *b)
{
    void *r = func_021A3960(((struct Obj12735 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12735 *)a)->f0) {
    case 0:
        ret = func_021A4768(a, r, b);
        break;
    case 1:
        ret = func_021A47B4(a, r, b);
        break;
    case 2:
        ret = func_021A4664(a, r, b);
        break;
    case 3:
        ret = func_021A4698(a, r, b);
        break;
    case 4:
        ret = func_021A482C(a, r, b);
        break;
    case 5:
    case 6:
        ret = func_021A4890(a, r, b);
        break;
    case 7:
        ret = func_021A48A4(a, r, b);
        break;
    }
    return ret;
}






















int func_021A4768(u8 *a, void *b, u8 *c)
{
    if (func_0216D3CC((int)b) == 1) {
        if (((struct Obj09566 *)c)->f8 != 9) {
            u32 r = func_0216D5F8(b);
            if (((struct Obj09566 *)c)->f8 != r && ((struct Obj09566 *)c)->f10 == 0) {
                return 3;
            }
            return func_021A47B4(a, b, c);
        }
        return func_021A482C(a, b, c);
    }
    return 0;
}






















int func_021A47B4(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj12736 *)c)->f8 == 9) {
        return func_021A4768(a, b, c);
    }
    r = func_021A569C(a, b, ((struct Obj12736 *)c)->f8, &sp);
    if (sp != -1) {
        if (r & 0x100) {
            if (!(r & 0xFFFFFEFF)) {
                return 2;
            }
        } else if (func_021AB11C(sp) == 0) {
            func_021A53A4((u32 *)a, 1);
            return 7;
        }
    }
    return 4;
}
























int func_021A482C(u8 *a, void *b, u8 *c)
{
    if (((struct Obj19788 *)c)->f8 == 9) {
        if (func_021A5390((u32)a) == 0) {
            func_021A56F4((u32)a);
        }
        if (((struct Obj02083 *)a)->f16 == 1) {
            if (func_0219F7CC((u32)b, ((struct Obj02083 *)a)->f14) != 0) {
                ((struct Obj02083 *)a)->f16 = 0;
            }
        }
        ((struct Obj02083 *)a)->f14 = ((struct Obj02083 *)a)->f14 + 1;
        if (((struct Obj02083 *)a)->f14 == 60) {
            func_021A5708((u32)a);
            func_021A53A4((u32 *)a, 1);
            return 7;
        }
    } else {
        func_021A5708((u32)a);
        return func_021A47B4(a, b, c);
    }
    return 6;
}
























/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A4890(u8 *a, void *b, u8 *c)
{
if (func_0216D3CC((int)b) == 1) {
    return 9;
}
return 8;
}
























int func_021A48A4(u8 *a, void *b, u8 *c)
{
    if (func_021A56C0((u32 *)a, (u32)b, (u32)c) == 1) {
        func_021A54B4((u8 *)a);
        func_021A53A4((u32 *)a, 0);
        return 1;
    }
    return 9;
}
























int func_021A48C8(u8 *a, u8 *b)
{
    void *r = func_021A3960(((struct Obj12737 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12737 *)a)->f0) {
    case 0:
        ret = func_021A491C(a, r, b);
        break;
    case 1:
        ret = func_021A4994(a, r, b);
        break;
    case 2:
        ret = func_021A4A74(a, r, b);
        break;
    case 3:
        ret = func_021A4AA8(a, r, b);
        break;
    }
    return ret;
}
























int func_021A491C(u8 *a, void *b, u8 *c)
{
    if (func_0216D3CC((int)b) == 1) {
        if (((struct Obj02084 *)c)->f8 != 9) {
            u32 r = func_0216D5F8(b);
            if (((struct Obj02084 *)c)->f8 != r && ((struct Obj02084 *)c)->f10 == 0) {
                return 3;
            }
            return func_021A4994(a, b, c);
        }
        return 1;
    }
    return 0;
}























int func_021A4960(int a)
{
    if (func_021AB140(a) != 0 || func_021AB404(a) != 0 || func_021AB410(a) != 0 || func_021AB328(a) != 0)
        return 1;
    return 0;
}























/*
 * Twin of func_021A4598; the final attribute test also consults
 * func_021A4960 on the tile id.
 *
 * Addresses are Black-image addresses.
 */
int func_021A4994(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    u16 k;
    u32 t;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj02084 *)c)->f8 == 9) {
        return func_021A491C(a, b, c);
    }
    r = func_021A5264(a, b, ((struct Obj02084 *)c)->f8, &sp);
    if (((struct Obj02084 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        k = func_021AB0F0(sp);
        t = func_021AB0F8(sp);
        if (r & 2) {
            cls = 9;
            if (func_021AB158(k)) {
                cls = 0;
            } else if (func_021AB164(k)) {
                cls = 1;
            } else if (func_021AB170(k)) {
                cls = 2;
            } else if (func_021AB17C(k)) {
                cls = 3;
            }
            if (cls != 9 && cls == ((struct Obj02084 *)c)->f8) {
                return 5;
            }
        }
        if (r == 0) {
            if (!(t & 2) && func_021A4960(k) == 0) {
                return 2;
            }
            if (((struct Obj02084 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}





















int func_021A4A74(u8 *a, void *b, u8 *c)
{
    if (func_0216D3CC((int)b) == 0)
        return 0;
    if (((struct Obj02084 *)c)->f8 == 9)
        return func_021A491C(a, b, c);
    return func_021A4994(a, b, c);
}




















int func_021A4AA8(u8 *a, void *b, u8 *c)
{
    u32 r = func_0216D5F8(b);
    if (((struct Obj02084 *)c)->f8 != 9 && ((struct Obj02084 *)c)->f8 != r) {
        func_0216D4B4((char *)b);
        return func_021A4994(a, b, c);
    }
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj02084 *)c)->f8 == 9) {
        return func_021A491C(a, b, c);
    }
    return func_021A4994(a, b, c);
}




















int func_021A4B00(u8 *a, u8 *b)
{
    void *r = func_021A3960(((struct Obj12738 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12738 *)a)->f0) {
    case 0:
        ret = func_021A4B54(a, r, b);
        break;
    case 1:
        ret = func_021A4B98(a, r, b);
        break;
    case 2:
        ret = func_021A4C1C(a, r, b);
        break;
    case 3:
        ret = func_021A4C50(a, r, b);
        break;
    }
    return ret;
}

























int func_021A4B54(u8 *a, void *b, u8 *c)
{
    if (func_0216D3CC((int)b) == 1) {
        if (((struct Obj09567 *)c)->f8 != 9) {
            u32 r = func_0216D5F8(b);
            if (((struct Obj09567 *)c)->f8 != r && ((struct Obj09567 *)c)->f10 == 0) {
                return 3;
            }
            return func_021A4B98(a, b, c);
        }
        return 1;
    }
    return 0;
}

























int func_021A4B98(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj07498 *)c)->f8 == 9) {
        return func_021A4B54(a, b, c);
    }
    r = func_021A5264(a, b, ((struct Obj07498 *)c)->f8, &sp);
    if (((struct Obj07498 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        u32 t;
        func_021AB0F0(sp);
        t = func_021AB0F8(sp);
        if (r == 0) {
            if (t & 2) {
                return 2;
            }
            if (((struct Obj07498 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}
























int func_021A4C1C(u8 *a, void *b, u8 *c)
{
    if (func_0216D3CC((int)b) == 0)
        return 0;
    if (((struct Obj19789 *)c)->f8 == 9)
        return func_021A4B54(a, b, c);
    return func_021A4B98(a, b, c);
}























int func_021A4C50(u8 *a, void *b, u8 *c)
{
    u32 r = func_0216D5F8(b);
    if (((struct Obj09568 *)c)->f8 != 9 && ((struct Obj09568 *)c)->f8 != r) {
        func_0216D4B4((char *)b);
        return func_021A4B98(a, b, c);
    }
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj09568 *)c)->f8 == 9) {
        return func_021A4B54(a, b, c);
    }
    return func_021A4B98(a, b, c);
}























/*
 * Addresses are Black-image addresses.
 */
void func_021A4CA8(u32 a, u32 b, u32 c)
{
    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj00262 *)a)->fC))) {
    case 0:
        func_021A4CF4(a, b, c);
        return;
    case 1:
        func_021A4FA8(a, b, c);
        return;
    case 2:
    case 3:
        func_021A5148(a, b, c);
        break;
    }
}























void func_021A4CF4(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: func_021A4D8C(a, (u32)x, c); return;
    case 1: func_021A4D90((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A4DC0((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: func_021A4E78((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A4E9C((u32 *)a, (int)x, (u8 *)c); return;
    case 5: func_021A4ED8((u32 *)a, (int)x, (u8 *)c); return;
    case 6: func_021A4F04((u32 *)a, x, c); return;
    case 7: func_021A4F0C(a, (void *)x, c); return;
    case 8: func_021A4F50((u32 *)((u32)((u32)((u32)((u32)((u32)((u32)a)))))), x, c); return;
    case 9: func_021A4F58((u32 *)((u32 *)a), x, c); break;
    }
}























/*
 * Unlabelled leaf (no lr save), filed because it blocks the caller's MATCH.
 *
 * Addresses are Black-image addresses.
 */
void func_021A4D8C(u32 a, u32 b, u32 c)
{
}























void func_021A4D90(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19790 *)c)->f8;

    if (k == 9)
        k = func_0216D5F8((void *)b);
    func_0216D410(b, func_02197E7C(k, 0));
    p[0] = 0;
    func_021A3964((u8 *)p[3], 0);
}























void func_021A4DC0(u32 *a, u32 b, u32 *c)
{
    int buf[3];
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else if ((c[3] & 1) && (c[1] & 2)) {
        if (func_021A3A20(a[3]) == 0) {
            r = 0x10;
        } else {
            r = 0x58;
            func_021A5304((u32)a, 0x20);
            func_021A3898((unsigned char *)a[3], (struct VecFx32 *)((struct V3 *)buf));
            if (func_02163E34((void *)b, buf, (int *)&v) != 0) {
                if (func_021AB44C(func_021AB0F0(v)) != 0) {
                    r = 0xc;
                    f = 0;
                    func_021A530C((u32)a, 0x20);
                }
            }
        }
    } else {
        r = 0xc;
    }
    if (f == 1) {
        if (func_021A57C0((u8 *)((u32)a), ((struct Obj04233 *)c)->f8) == 1) {
            switch (r) {
            case 0x10: r = 0x4c; break;
            case 0x58: r = 0xa3; break;
            case 0xc: r = 0xa7; break;
            }
        }
    }
    func_0216D410(b, func_02197E7C(((struct Obj04233 *)c)->f8, r));
    a[0] = 1;
    func_021A3964((u8 *)a[3], 1);
}























void func_021A4E78(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19791 *)c)->f8, 0x24));
    p[0] = 2;
    func_021A3964((u8 *)p[3], 2);
}























void func_021A4E9C(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj04233 *)c)->f8, 0x1C));
    p[0] = 3;
    func_021A3964((u8 *)p[3], 0);
    if (func_021A5810((u8 *)p, ((struct Obj04233 *)c)->f8) == 0)
        func_020061E4(0x55A);
}






















void func_021A4ED8(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19792 *)c)->f8, 0x38));
    p[0] = 1;
    func_021A3964((u8 *)p[3], 1);
    func_020061E4(0x55E);
}






















void func_021A4F04(u32 *a, void *a1, u32 a2)
{
    *a = 4;
}






















void func_021A4F0C(u32 a, void *b, u32 c)
{
    u32 x = ((struct Obj19795 *)c)->f8;
    if (x == 9) {
        x = func_021A5630(a);
    }
    func_0216D410((u32)b, func_02197E7C(x, 0x34));
    func_0216DB4C(b, 1);
    func_0216DCE8((void *)b, 1);
    func_0216D568((void *)b, 0x8000);
    ((struct Obj19794 *)a)->f0 = 5;
}






















void func_021A4F50(u32 *a, void *a1, u32 a2)
{
    *a = 6;
}






















/*
 * The function returns int: v.y when the height is already at or under the
 * limit, 7 (the new state) otherwise. The only caller (func_021A4CF4, case 9)
 * discards the value. Returning v.y on the early path ties the cross-block
 * v.y value to r0 (the return register), so the block-2 constant 0x8000 goes
 * to r1 and the subtract reads `subs r0, r0, r1`; the void form colours the
 * constant first into r0 and gives `subs r0, r1, r0` (three earlier rounds,
 * dozens of spellings). Leaving the final `return 7` out recolours the 7 to r1.
 * See docs/idioms/a-value-returned-on-the-early-path-precolours-its-register-to-r0.md.
 */
int func_021A4F58(u32 *p, void *a1, u32 a2)
{
    void *h = func_021A3960(*(unsigned char * *)&((struct Obj00262 *)p)->fC);
    Vec021A4F58 v;
    int lim;

    func_0216D88C(h, (struct V3 *)&v);
    func_02163E58(h, &v, &lim);
    if (v.y > lim) {
        v.y -= 0x8000;
        if (v.y < lim) {
            v.y = lim;
            func_0216D570(h, 0x8000);
            p[7] = 1;
        }
        func_0216D89C(h, (const Vec021A36E4 *)&v);
        p[0] = 7;
        return 7;
    }
    return v.y;
}






















void func_021A4FA8(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: func_021A5010(a, (u32)x, c); return;
    case 1: func_021A5014((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A5044((u32 *)a, (u32)x, (u32 *)c); return;
    case 3: func_021A50BC((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A50E0((u32 *)a, (int)x, (u8 *)c); return;
    case 5: func_021A511C((u32 *)a, (int)x, (u8 *)c); break;
    }
}






















void func_021A5010(u32 a, u32 b, u32 c)
{
}






















void func_021A5014(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19797 *)c)->f8;

    if (k == 9)
        k = func_0216D5F8((void *)b);
    func_0216D410(b, func_02197E7C(k, 0));
    p[0] = 0;
    func_021A3964((u8 *)p[3], 0);
}






















void func_021A5044(u32 *a, u32 b, u32 *c)
{
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else {
        r = 0x14;
        if (func_021A5788((u32 *)((u32)a), 9, (int *)&v) == 1) {
            if (func_021AB41C(func_021AB0F0(v)) == 1) {
                r = 0x9b;
                func_021AC528(b, func_02188CD0((u8 *)a[4]));
            }
        }
    }
    if (f == 1) {
        if (func_021A57C0((u8 *)((u32)a), ((struct Obj06012 *)c)->f8) == 1) {
            if (r == 0x14) {
                r = 0x10;
            }
        }
    }
    func_0216D410(b, func_02197E7C(((struct Obj06012 *)c)->f8, r));
    a[0] = 1;
    func_021A3964((u8 *)a[3], 1);
}






















void func_021A50BC(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19798 *)c)->f8, 0x24));
    p[0] = 2;
    func_021A3964((u8 *)p[3], 2);
}






















void func_021A50E0(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj06012 *)c)->f8, 0x1C));
    p[0] = 3;
    func_021A3964((u8 *)p[3], 0);
    if (func_021A5810((u8 *)p, ((struct Obj06012 *)c)->f8) == 0)
        func_020061E4(0x55A);
}






















void func_021A511C(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19799 *)c)->f8, 0x38));
    p[0] = 1;
    func_021A3964((u8 *)p[3], 1);
    func_020061E4(0x55E);
}






















void func_021A5148(u32 a, u32 b, u32 c)
{
    void *x = func_021A3960(((struct Obj00262 *)a)->fC);
    switch (b) {
    case 0: func_021A51A4(a, (u32)x, c); return;
    case 1: func_021A51A8((u32 *)a, (int)x, (u8 *)c); return;
    case 2: func_021A51D8((u32 *)a, (int)x, (u8 *)c); return;
    case 3: func_021A5204((u32 *)a, (int)x, (u8 *)c); return;
    case 4: func_021A5228((u32 *)a, (int)x, (u8 *)c); break;
    }
}






















void func_021A51A4(u32 a, u32 b, u32 c)
{
}






















void func_021A51A8(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19800 *)c)->f8;

    if (k == 9)
        k = func_0216D5F8((void *)b);
    func_0216D410(b, func_02197E7C(k, 0));
    p[0] = 0;
    func_021A3964((u8 *)p[3], 0);
}






















void func_021A51D8(u32 *p, int b, u8 *c)
{
    int a = (((struct Obj07499 *)c)->f10 == 1) ? 0x14 : 0x10;

    func_0216D410(b, func_02197E7C(((struct Obj07499 *)c)->f8, a));
    p[0] = 1;
    func_021A3964((u8 *)p[3], 1);
}






















void func_021A5204(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj19801 *)c)->f8, 0x24));
    p[0] = 2;
    func_021A3964((u8 *)p[3], 2);
}






















void func_021A5228(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(((struct Obj07499 *)c)->f8, 0x1C));
    p[0] = 3;
    func_021A3964((u8 *)p[3], 0);
    if (func_021A5810((u8 *)p, ((struct Obj07499 *)c)->f8) == 0)
        func_020061E4(0x55A);
}






















int func_021A5264(u8 *a, void *b, u32 c, int *d)
{
    V3 buf;
    int s2;
    int s1;
    int r4;
    int r3;
    r4 = func_0216D83C(b);
    s1 = func_0216D854(b);
    s2 = func_0216D86C(b);
    r4 = (short)(r4 + func_021641E8(c));
    r3 = (short)(s2 + func_021641F8(c));
    r4 = func_02163994(b, r4, s1, r3, c);
    func_0216D88C(b, (struct V3 *)&buf);
    func_02164208(c, (int *)(&buf), 0x10000);
    if (func_02163E34(b, &buf, d) == 0) {
        *d = -1;
    }
    if (r4 & 2) {
        if (func_021AB2DC(func_021AB0F0(*d)) == 1) {
            if (func_0216E5B0(func_0216D67C(b), (const struct V3 *)(&buf)) == 1) {
                r4 &= ~2;
            }
        }
    }
    return r4;
}






















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5304(u32 a, u32 b)
{
((struct Obj07218 *)((u8 *)(a)))->f8 = (b | ((struct Obj07218 *)((u8 *)(a)))->f8);
return a;
}






















int func_021A530C(u32 a, u32 b)
{
((struct Obj07218 *)((u8 *)(a)))->f8 = ((~b) & ((struct Obj07218 *)((u8 *)(a)))->f8);
return a;
}






















int func_021A5318(u32 *p, u32 m)
{
    if (p[2] & m)
        return 1;
    return 0;
}






















/*
 * Tail-call thunk: pins the second argument to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5328(u32 a)
{
    func_021A5304(a, 1);
}






















void func_021A5334(u32 a)
{
    func_021A530C(a, 1);
}






















int func_021A5340(u32 *p)
{
    int r = 1;

    if (func_021A5318(p, 1) == 0)
        r = 0;
    return r;
}






















/*
 * Tail-call thunk: pins the second argument to 2.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5354(u32 a)
{
    func_021A5304(a, 2);
}






















void func_021A5360(u32 a)
{
    func_021A530C(a, 2);
}






















/*
 * Tail-call thunk: pins the second argument to 4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A536C(u32 a)
{
    func_021A530C(a, 4);
}





















void func_021A5378(u32 *p, int on)
{
    if (on == 1)
        func_021A5304((u32)p, 8);
    else
        func_021A530C((u32)p, 8);
}





















int func_021A5390(u32 a)
{
if (func_021A5318((u32 *)a, 8) != 0) {
    return 1;
}
return 0;
}





















void func_021A53A4(u32 *p, int on)
{
    if (on == 1)
        func_021A5304((u32)p, 0x10);
    else
        func_021A530C((u32)p, 0x10);
}




















int func_021A53BC(u32 a)
{
if (func_021A5318((u32 *)a, 16) != 0) {
    return 1;
}
return 0;
}




















void func_021A53D0(u32 *p)
{
    void *h;
    int v;

    if (p[0] == 3) {
        h = func_021A3960(*(unsigned char * *)&((struct Obj09569 *)p)->fC);
        v = func_0216D5F8(h);
        func_0216D4B4(h);
        func_0216D5E0((int)h, v);
        func_0216D674(h, 0);
        func_021A3964((u8 *)p[3], 0);
    }
}


















/*
 * Addresses are Black-image addresses.
 */
int func_021A5408(u8 *a)
{
    u32 x;
    u32 y;
    switch (((struct Obj09570 *)a)->f0) {
    case 0:
        break;
    case 1:
        return 0;
    case 2:
    case 3:
        x = (u32)func_021A572C(a);
        y = func_0216D5F8((void *)x);
        func_0216D4B4((char *)x);
        func_0216D5E0(x, y);
        func_0216D674((void *)x, 0);
        func_021A3964((u8 *)(*(u32 *)&((struct Obj09570 *)a)->fC), 0);
        break;
    }
    return 1;
}


















int func_021A5458(u32 *p, int unused)
{
    int x = func_0216D7DC(func_021A3960(*(unsigned char * *)&((struct Obj19803 *)p)->fC));

    if (func_021A5318(p, 2) == 0 && func_021AB348(func_021AB0F0(x)) == 1)
        return 1;
    return 0;
}

















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A548C(u32 *a)
{
if (func_021A5458(a, 9) != 0) {
    return 1;
}
return 0;
}

















int func_021A54A0(u32 a)
{
if (func_021A53BC(a) == 1) {
    return 1;
}
return 0;
}

















/*
 * Addresses are Black-image addresses.
 */
void func_021A54B4(u8 *p)
{
    V3 v;
    void *o = func_021A3960(((struct Obj12739 *)p)->fC);

    func_0216DB4C(o, 0);
    func_0216DCE8(o, 0);
    func_0216D568(o, 0x140);
    func_02164010((int)o);
    func_0216D88C(o, (struct V3 *)&v);
    func_0216D85C(o, (s16)((v.y >> 4) / 4096));
    func_021640B0((int)o);
    func_02163F10((int)o);
}



















void func_021A550C(u32 *p)
{
    if (func_021A5340(p) == 1) {
        func_0216D550(func_021A3960(*(unsigned char * *)&((struct Obj06014 *)p)->fC), 0x18);
        func_021A5334((u32)p);
    }
}



















/*
 * Calls func_021A550C() and returns 0x0.
 */
u32 func_021A552C(u32 *p)
{
    func_021A550C(p);

    return 0x0;
}



















/*
 * Addresses are Black-image addresses.
 */
int func_021A5538(u8 *a)
{
    int v;
    void *x = func_021A3960(*(unsigned char * *)&((struct Obj06014 *)a)->fC);
    u32 y = func_0216D608(x);
    if (func_021A5264(a, x, y, &v) != 0) {
        func_021A550C((u32 *)a);
        func_021A5354((u32)a);
        func_021A3964(*(u8 * *)&((struct Obj06014 *)a)->fC, 0);
        return 0;
    }
    func_021A5328((u32)a);
    func_0216D410((int)x, func_02197E7C(y, 0x10));
    func_0216D548(x, 0x18);
    ((struct Obj06014 *)a)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj06014 *)a)->fC, 1);
    return 1;
}



















int func_021A55A8(u32 *p, u32 a, int b)
{
    if (b == 0) {
        if (data_021D89EC[func_021A5458(p, a)](p, a) == 1)
            return 1;
    }
    func_021A5334((u32)p);
    return 0;
}



















int func_021A55DC(int a)
{
    if (func_021AB404(a) == 1 || func_021AB410(a) == 1)
        return 1;
    return 0;
}



















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A55FC(int a)
{
if (func_021AB404(a) == 1) {
    return 1;
}
return 0;
}



















int func_021A5610(u32 *p)
{
    int x;

    func_021A5788((u32 *)((u32)p), 9, &x);
    if (func_021A55FC(func_021AB0F0(x)) == 1)
        return 1;
    return 0;
}


















u32 func_021A5630(u32 a)
{
    u32 v;
    u16 t[4];
    u16 i;
    u32 x;
    u16 *p = t;
    t[0] = d_021D8A24[0];
    t[1] = d_021D8A24[1];
    t[2] = d_021D8A24[2];
    t[3] = d_021D8A24[3];
    x = func_021A3920((u8 *)(*(u32 *)&((struct Obj09571 *)a)->fC));
    i = 0;
    do {
        if (func_021A5788((u32 *)((u32)a), x, (int *)&v) == 1) {
            if (func_021A55DC(func_021AB0F0(v)) == 0) {
                if (func_021AB11C(v) == 0) {
                    return x;
                }
            }
        }
        i = i + 1;
        x = p[x];
    } while (i < 4);
    return 9;
}


















int func_021A569C(u8 *a, void *b, int c, int *d)
{
    int r = func_021A5264(a, b, c, d);

    if (func_021A55DC(func_021AB0F0(*d)) == 1)
        r |= 0x100;
    return r;
}


















u32 func_021A56C0(u32 *p, u32 a1, u32 a2)
{
    void *h = func_021A3960(*(unsigned char * *)&((struct Obj12739 *)p)->fC);
    Vec021A56C0 v;
    int lim;

    func_0216D88C(h, (struct V3 *)((struct VecFx32 *)&v));
    func_02163E58(h, (Vec021A4F58 *)&v, &lim);
    if (v.y <= lim)
        return 1;
    return 0;
}


















void func_021A56F4(u32 a)
{
func_021A5378((u32 *)a, 1);
func_021A39AC((u8 *)(((struct Obj18049 *)((u8 *)(a)))->fC), 7);
}

















void func_021A5708(u32 a)
{
((struct Obj02083 *)((u8 *)(a)))->f14 = 0;
((struct Obj02083 *)((u8 *)(a)))->f16 = 0;
func_021A53A4((u32 *)a, 0);
func_021A5378((u32 *)a, 0);
func_021A3998((u8 *)(((struct Obj02083 *)((u8 *)(a)))->fC));
}

















/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021A5728(u8 *p)
{
    return ((struct Obj18050 *)p)->fC;
}

















/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void *func_021A572C(u8 *p)
{
    return func_021A3960(((struct Obj09570 *)p)->fC);
}

















void func_021A5738(Obj021A5738 *p, int a)
{
    u16 s;

    if (func_021A5390((u32)p) == 1) {
        s = p->saved;
        func_021A5708((u32)p);
        if (a == 1) {
            p->saved = s;
            p->flag = 1;
        }
    }
}

















/*
 * Tail-call thunk: forwards to func_021A550C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A575C(u32 *p)
{
    func_021A550C(p);
}

















/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
u32 func_021A5764(u8 *p)
{
    return ((struct Obj18051 *)p)->f1C;
}

















int func_021A5768(u32 a, u32 b)
{
if (b == 1) {
    ((struct Obj12088 *)((u8 *)(a)))->f1C = 1;
    return a;
}
((struct Obj12088 *)((u8 *)(a)))->f1C = 0;
return a;
}

















int func_021A5778(u32 a)
{
if (((struct Obj18052 *)((u8 *)(a)))->f0 == 3) {
    return 1;
}
return 0;
}
















int func_021A5788(u32 *p, int k, int *out)
{
    Vec021A5788 v;

    func_021A3898(*(unsigned char * *)&((struct Obj09571 *)p)->fC, (struct VecFx32 *)&v);
    if (k != 9)
        func_02164208(k, (int *)(&v), 0x10000);
    return func_02163E34(func_021A3960(*(unsigned char * *)&((struct Obj09571 *)p)->fC), &v, out);
}
















/*
 * Addresses are Black-image addresses.
 */
int func_021A57C0(u8 *p, int dir)
{
    u8 *a;
    int y;
    Vec3 pos;
    int lim;

    a = func_021A3960(*(u8 * *)&((struct Obj00262 *)p)->fC);
    func_0216D88C((const struct Actor *)a, (struct V3 *)((struct VecFx32 *)&pos));
    y = pos.y;
    func_02164208(dir, (int *)(&pos), 0x10000);
    if (func_02163E58(a, (Vec021A4F58 *)&pos, &lim) == 1) {
        if (y < lim) {
            return 1;
        }
        if (y > lim) {
            return 2;
        }
    }
    return 0;
}
















int func_021A5810(u8 *p, int dir)
{
    u8 *a;
    int h;
    int i;
    Vec3 pos;

    a = func_021A3960(*(u8 * *)&((struct Obj00262 *)p)->fC);
    h = func_02012844(func_020120F4(func_02188C80(*(u8 * *)&((struct Obj00262 *)p)->f10)));
    func_0216D88C((const struct Actor *)a, (struct V3 *)((struct VecFx32 *)&pos));
    func_02164208(dir, (int *)(&pos), 0x10000);
    i = func_02162564((char *)h, (struct Q *)(&pos));
    if (i == 0xffff) {
        return 0;
    }
    if (func_021626B8(func_021625CC((char *)h, (u16)i), dir)) {
        return 1;
    }
    return 0;
}















u8 *func_021A5880(u8 *obj, int heap)
{
    u8 *p;

    p = func_02030734(heap, 0x24, 1, &d_021DDF04, 0x1a0);
    *(u8 * *)&((struct Obj01499 *)p)->f14 = obj;
    ((struct Obj01499 *)p)->f18 = func_021A395C(obj);
    ((struct Obj01499 *)p)->f1C = func_021A3960(*(u8 * *)&((struct Obj01499 *)p)->f14);
    if (func_0216D5A0(((struct Obj01499 *)p)->f1C) != 0x45) {
        d_021DDEE0[1] = func_0216D598(((struct Obj01499 *)p)->f1C);
        func_0216E0AC(((struct Obj01499 *)p)->f1C, d_021DDEE0b);
    }
    ((struct Obj01499 *)p)->f20 = (int)func_0219E348(((struct Obj01499 *)p)->f1C);
    {
        u16 v[4] = {0, 0, 0, 0};
        func_0219E2C0(((struct Obj01499 *)p)->f1C, v);
    }
    func_021A6B88(p + 0xc);
    {
        int t = func_021A3974(*(u8 * *)&((struct Obj01499 *)p)->f14);
        switch (t) {
        case 2:
            func_021A3CB0((u32)(*(u8 * *)&((struct Obj01499 *)p)->f14), 4);
            func_021A3CE8(*(u8 * *)&((struct Obj01499 *)p)->f14);
            break;
        case 3:
            func_021A3CB0((u32)(*(u8 * *)&((struct Obj01499 *)p)->f14), 0x100);
            func_021A3CE8(*(u8 * *)&((struct Obj01499 *)p)->f14);
            break;
        }
    }
    return p;
}




















/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5920(void *a0)
{
    func_020307B0(a0);
}





















void func_021A5928(u8 *p, int v)
{
    if (func_0216D5A0((void *)(((struct Obj05027 *)p)->f1C)) != 0x45) {
        d_021DDEE0[1] = func_0216D598((void *)(((struct Obj05027 *)p)->f1C));
        func_0216E0AC((void *)(((struct Obj05027 *)p)->f1C), d_021DDEE0b);
    }
    ((struct Obj05027 *)p)->f20 = (int)func_0219E348((void *)(((struct Obj05027 *)p)->f1C));
    func_0219E2C0((void *)(((struct Obj05027 *)p)->f1C), (void *)v);
}





















/*
 * Unlabelled leaf: clears the word at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5964(u32 *p)
{
    p[8] = 0;
}




















void func_021A596C(u8 *p, u32 b, u32 c)
{
    u32 t;
    u32 x;
    u32 y;

    t = func_021A3AB8(((struct Obj09572 *)p)->f14, c);
    func_021A3CC0((Obj021A3CC0 *)(((struct Obj09572 *)p)->f14));
    func_021A6BB4((St *)(p + 0xc), t, ((struct Obj09572 *)p)->f1C);
    x = func_021A682C(p, t, 0);
    y = func_021A5A68(p, x, b, c, 0);
    func_021A5B4C((u32 *)p, c, y);
    func_021A5AD4(p, y, x, b, c, 0);
    func_021A5B7C(p);
    func_021A6C30((T *)(p + 0xc));
}




















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A59DC(u32 a)
{
if (((struct Obj18054 *)((u8 *)(a)))->f0 == 3) {
    return 1;
}
return 0;
}




















u32 func_021A59EC(u32 p)
{
    u32 r = 1;
    if (func_021A66F8((S_021A66F8 *)p, 1) == 0) {
        r = 0;
    }
    return r;
}




















/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E2C0.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A00(u8 *p, void *r)
{
    func_0219E2C0(((struct Obj18055 *)p)->f1C, r);
}




















/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E2F4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A0C(u8 *p, void *a1)
{
    func_0219E2F4((void *)(((struct Obj18056 *)p)->f1C), a1);
}




















/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E664.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5A18(u8 *p, u32 k, void *buf)
{
    return func_0219E664(((struct Obj18057 *)p)->f1C, k, buf);
}




















/*
 * Tail-call thunk: forwards the object's word at +0x20 to func_021B8028.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A24(u8 *p)
{
    func_021B8028(((struct Obj18058 *)p)->f20);
}



















/*
 * Unlabelled leaf getter at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A5A30(u32 *p)
{
    return p[8];
}



















void func_021A5A34(u32 *p)
{
    u32 h;
    int v;

    if (p[0] == 3) {
        h = p[7];
        v = func_0216D5F8((void *)h);
        func_0216D4B4((char *)h);
        func_0216D5E0(h, v);
        func_0216D674((void *)h, 0);
        func_021A3964((u8 *)p[5], 0);
    }
}



















int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d)
{
    int r;

    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj04234 *)p)->f14))) {
    case 0:
        r = func_021A5C3C(p, b, c, a, d);
        break;
    case 1:
        r = func_021A6014((int *)p, b, c, a, d);
        break;
    case 2:
    case 3:
        r = func_021A64B4((int *)p, b, c, a, d);
        break;
    }
    return r;
}



















void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj01119 *)p)->f14))) {
    case 0:
        func_021A5BC0(p, a, c, d, (u16)b, e);
        break;
    case 1:
        func_021A5F98((int *)p, a, c, d, b, e);
        break;
    case 2:
    case 3:
        func_021A635C((S_021A5EA4 *)p, a, c, d, (u16)b, e);
        break;
    }
}



















void func_021A5B4C(u32 *p, u32 a, int mode)
{
    func_021A3AC4(p[5], a);
    func_021A6738(p);
    if (mode == 2)
        func_021A672C(p);
}



















/*
 * Tail call with the last three arguments.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5B6C(u32 a, u32 b, u32 c, u32 d)
{
    return func_0219E424(b, c, d);
}



















void func_021A5B7C(u8 *p)
{
    if (func_021A66F8((S_021A66F8 *)((u32)p), 8)) {
        func_021A6B08((P *)(p + 8), 0);
    } else if (func_021A66F8((S_021A66F8 *)((u32)p), 0x10)) {
        func_021A6B08((P *)(p + 8), 1);
    } else {
        func_021A6B30((P *)(p + 8));
    }
    func_021A6B50((P *)(p + 8), ((struct Obj19806 *)p)->f1C);
}

















void func_021A5BC0(u8 *p, u32 k, u32 b, u32 c, u16 d, u32 e)
{
    void *a = ((struct Obj01119 *)p)->f1C;

    switch (k) {
    case 0:
        func_021A5EA0(p, a, b, c, d, e);
        break;
    case 1:
        func_021A5EA4((S_021A5EA4 *)p, a, b, c, d, e);
        break;
    case 2:
        func_021A5EDC((S_021A5EA4 *)p, a, b, c, d, e);
        break;
    case 3:
        func_021A5F14((S_021A5EA4 *)p, a, b, c, d, e);
        break;
    case 4:
        func_021A5F38((S_021A5EA4 *)p, a, b, c, d, e);
        break;
    case 5:
        func_021A5F74((S_021A5EA4 *)p, a, b, c, d, e);
        break;
    }
}
















int func_021A5C3C(u8 *p, u32 b, u32 c, u16 d, u32 e)
{
    int sw = ((struct Obj04234 *)p)->f0;
    int r = 0;
    void *a = ((struct Obj04234 *)p)->f1C;

    switch (sw) {
    case 0:
        r = func_021A5CA4(p, a, b, c, d, e);
        break;
    case 1:
        r = func_021A5D04(p, a, b, c, d, e);
        break;
    case 2:
        r = func_021A5DD8(p, a, b, c, d, e);
        break;
    case 3:
        r = func_021A5E28(p, a, b, c, d, e);
        break;
    }
    return r;
}













int func_021A5CA4(u8 *p, void *b, u32 c, u32 d, u16 e, u32 f)
{
    if (func_0216D3CC((int)b) == 1) {
        if (e != 9) {
            if (e != func_0216D5F8(b) && f == 0) {
                return 3;
            }
            return func_021A5D04(p, b, c, d, e, f);
        }
        return 1;
    }
    return 0;
}














/*
 * Same body as func_021A60DC with func_021A5CA4 as the e == 9 path.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5D04(void *a, void *b, int c, int d, u16 e, int f)
{
    u8 buf[8];
    u32 r;
    u32 t;
    u16 k;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4((u8 *)a, b, c, d, e, f);
    }
    r = func_021A5B6C((u32)a, (u32)b, e, 0);
    if (f == 1 && (r & 2)) {
        r = 0;
    }
    if (r == 0) {
        return 2;
    }
    if (r & 2) {
        func_0219E664(b, e, buf);
        t = func_0219D724((u32)b, (char *)buf);
        cls = 9;
        k = func_021AB0F0(t);
        func_021AB0F8(t);
        if (func_021AB158(k)) {
            cls = 0;
        } else if (func_021AB164(k)) {
            cls = 1;
        } else if (func_021AB170(k)) {
            cls = 2;
        } else if (func_021AB17C(k)) {
            cls = 3;
        }
        if (cls != 9 && cls == e) {
            return 5;
        }
    }
    return 4;
}














int func_021A5DD8(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4((u8 *)a, b, c, d, e, f);
    }
    return func_021A5D04(a, b, c, d, e, f);
}














int func_021A5E28(void *a, void *b, int c, int d, u16 e, int f)
{
    int t = func_0216D5F8(b);
    if (e != 9 && e != t) {
        func_0216D4B4(b);
        return func_021A5D04(a, b, c, d, e, f);
    }
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4((u8 *)a, b, c, d, e, f);
    }
    return func_021A5D04(a, b, c, d, e, f);
}













/*
 * Unlabelled leaf (a bare `bx lr` in a .word run): the empty arm-0 handler
 * called from func_021A5BC0's dispatch.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5EA0(void *p, void *a, int b, int c, int d, int e)
{
}














void func_021A5EA4(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410((int)b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}














void func_021A5EDC(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    int k;
    if (f == 1) {
        k = 0x14;
    } else if (d & 2) {
        k = 0x58;
    } else {
        k = 0xc;
    }
    func_0216D410((int)b, func_02197E7C(e, k));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}














void func_021A5F14(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x28));
    a->f0 = 2;
    func_021A3964(a->f14, 2);
}














void func_021A5F38(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}














void func_021A5F74(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x38));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}














void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u16 e, u32 f)
{
    void *p = ((void **)a)[7];
    switch (sel) {
    case 0: func_021A6278(a, p, c, d, e, f); break;
    case 1: func_021A627C((S_021A5EA4 *)a, p, c, d, e, f); break;
    case 2: func_021A62B4((S_021A5EA4 *)a, p, c, d, e, f); break;
    case 3: func_021A62D8((S_021A5EA4 *)a, p, c, d, e, f); break;
    case 4: func_021A62FC((S_021A5EA4 *)a, p, c, d, e, f); break;
    case 5: func_021A6338((S_021A5EA4 *)a, p, c, d, e, f); break;
    }
}














int func_021A6014(int *a, int b, int c, u16 d, int e)
{
    int sw = a[0];
    int r = 0;
    void *p = ((void **)a)[7];
    switch (sw) {
    case 0: r = func_021A607C(a, p, b, c, d, e); break;
    case 1: r = func_021A60DC(a, p, b, c, d, e); break;
    case 2: r = func_021A61B0(a, p, b, c, d, e); break;
    case 3: r = func_021A6200(a, p, b, c, d, e); break;
    }
    return r;
}











int func_021A607C(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 1) {
        if (e != 9) {
            if (e != func_0216D5F8(b) && f == 0) {
                return 3;
            }
            return func_021A60DC(a, b, c, d, e, f);
        }
        return 1;
    }
    return 0;
}














/*
 * Same body as func_021A5D04 with func_021A607C as the e == 9 path.
 *
 * Addresses are Black-image addresses.
 */
int func_021A60DC(void *a, void *b, int c, int d, u16 e, int f)
{
    u8 buf[8];
    u32 r;
    u32 t;
    u16 k;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A607C(a, b, c, d, e, f);
    }
    r = func_021A5B6C((u32)a, (u32)b, e, 0);
    if (f == 1 && (r & 2)) {
        r = 0;
    }
    if (r == 0) {
        return 2;
    }
    if (r & 2) {
        func_0219E664(b, e, buf);
        t = func_0219D724((u32)b, (char *)buf);
        cls = 9;
        k = func_021AB0F0(t);
        func_021AB0F8(t);
        if (func_021AB158(k)) {
            cls = 0;
        } else if (func_021AB164(k)) {
            cls = 1;
        } else if (func_021AB170(k)) {
            cls = 2;
        } else if (func_021AB17C(k)) {
            cls = 3;
        }
        if (cls != 9 && cls == e) {
            return 5;
        }
    }
    return 4;
}














int func_021A61B0(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A607C(a, b, c, d, e, f);
    }
    return func_021A60DC(a, b, c, d, e, f);
}














int func_021A6200(void *a, void *b, int c, int d, u16 e, int f)
{
    int t = func_0216D5F8(b);
    if (e != 9 && e != t) {
        func_0216D4B4(b);
        return func_021A60DC(a, b, c, d, e, f);
    }
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A607C(a, b, c, d, e, f);
    }
    return func_021A60DC(a, b, c, d, e, f);
}













/*
 * Empty leaf (bx lr) that saves nothing, so disasm.py does not label it.
 */
void func_021A6278(void *a, void *b, int c, int d, int e, int f)
{
}














void func_021A627C(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410((int)b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}














void func_021A62B4(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x14));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}













void func_021A62D8(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x28));
    a->f0 = 2;
    func_021A3964(a->f14, 2);
}













void func_021A62FC(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}













void func_021A6338(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x38));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}












void func_021A635C(S_021A5EA4 *a, int sel, int c, int d, u16 e, int f)
{
    void *x = func_021A3960(a->f14);
    switch (sel) {
    case 0: func_021A63EC(a, x, c, d, e, f); break;
    case 1: func_021A63F0((S_021A5EA4 *)a, x, c, d, e, f); break;
    case 2: func_021A6428((S_021A5EA4 *)a, x, c, d, e, f); break;
    case 3: func_021A6454((S_021A5EA4 *)a, x, c, d, e, f); break;
    case 4: func_021A6478((S_021A5EA4 *)a, x, c, d, e, f); break;
    }
}











void func_021A63EC(void *a, void *b, int c, int d, int e, int f)
{
}











void func_021A63F0(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410((int)b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}











void func_021A6428(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, (f == 1) ? 0x14 : 0x10));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}











void func_021A6454(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x28));
    a->f0 = 2;
    func_021A3964(a->f14, 2);
}











void func_021A6478(S_021A5EA4 *a, void *b, int c, int d, u16 e, int f)
{
    func_0216D410((int)b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}











int func_021A64B4(int *a, int b, int c, u16 d, int e)
{
    void *x = func_021A3960(*(unsigned char * *)&((struct Obj04234 *)a)->f14);
    int r = 0;
    switch (a[0]) {
    case 0: r = func_021A652C(a, x, b, c, d, e); break;
    case 1: r = func_021A658C(a, x, b, c, d, e); break;
    case 2: r = func_021A661C(a, x, b, c, d, e); break;
    case 3: r = func_021A666C(a, x, b, c, d, e); break;
    }
    return r;
}










int func_021A652C(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 1) {
        if (e != 9) {
            if (e != func_0216D5F8(b) && f == 0) {
                return 3;
            }
            return func_021A658C(a, b, c, d, e, f);
        }
        return 1;
    }
    return 0;
}










int func_021A658C(void *a, void *b, int c, int d, u16 e, int f)
{
    int r;
    int loc;
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A652C(a, b, c, d, e, f);
    }
    r = func_021A5B6C((u32)a, (u32)b, e, (u32)(&loc));
    if (f == 1 && r != 0 && (r & 0x10) == 0) {
        r = 0;
    }
    if (loc != -1) {
        int t;
        func_021AB0F0(loc);
        t = func_021AB0F8(loc);
        if (r == 0) {
            if (t & 2) {
                return 2;
            }
            if (f == 1) {
                return 2;
            }
        }
    }
    return 4;
}









int func_021A661C(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A652C(a, b, c, d, e, f);
    }
    return func_021A658C(a, b, c, d, e, f);
}










/*
 * Addresses are Black-image addresses.
 */
u32 func_021A666C(void *a, void *b, u32 c, u32 d, u16 e, u32 f)
{
    u32 r0 = func_0216D5F8(b);

    if (e != 9 && e != r0) {
        func_0216D4B4(b);
        return func_021A658C(a, b, c, d, e, f);
    }
    if (!func_0216D3CC((int)b))
        return 0;
    if (e == 9)
        return func_021A652C(a, b, c, d, e, f);
    return func_021A658C(a, b, c, d, e, f);
}











/*
 * Unlabelled leaf: sets bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A66E4(u32 *p, u32 v)
{
    p[1] |= v;
}











/*
 * Unlabelled leaf: clears bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A66EC(u32 *p, u32 v)
{
    p[1] &= ~v;
}











int func_021A66F8(S_021A66F8 *a, int m)
{
    if (a->f4 & m) {
        return 1;
    }
    return 0;
}











/*
 * Tail-call thunk: pins the second argument to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6708(void *a)
{
    func_021A66E4(a, 1);
}











void func_021A6714(void *a)
{
    func_021A66EC(a, 1);
}











/*
 * Tail-call thunk: pins the second argument to 2.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6720(void *a)
{
    func_021A66E4(a, 2);
}











void func_021A672C(void *a)
{
    func_021A66EC(a, 2);
}











/*
 * Tail-call thunk: pins the second argument to 4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6738(void *a)
{
    func_021A66EC(a, 4);
}











/*
 * Tail-call thunk: pins the second argument to 8.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6744(void *a)
{
    func_021A66E4(a, 8);
}











void func_021A6750(void *a)
{
    func_021A66EC(a, 8);
}











/*
 * Tail-call thunk: pins the second argument to 16.
 *
 * Addresses are Black-image addresses.
 */
void func_021A675C(void *a)
{
    func_021A66E4(a, 16);
}











void func_021A6768(void *a)
{
    func_021A66EC(a, 16);
}











/*
 * Tail-call thunk: pins the second argument to 32.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6774(void *a)
{
    func_021A66E4(a, 32);
}











void func_021A6780(void *a)
{
    func_021A66EC(a, 32);
}










/*
 * Tail-call thunk: pins the second argument to 64.
 *
 * Addresses are Black-image addresses.
 */
void func_021A678C(void *a)
{
    func_021A66E4(a, 64);
}










void func_021A6798(void *a)
{
    func_021A66EC(a, 64);
}










u32 func_021A67A4(u8 *p)
{
    u32 r4 = func_0216D7DC((void *)(((struct Obj19808 *)p)->f1C));

    if (!func_021A66F8((S_021A66F8 *)p, 2)) {
        r4 = func_021AB0F0(r4);
        if (func_021AB348(r4) == 1)
            return 1;
        if (func_021BB1AC(r4) == 1)
            return 2;
        if (func_021BB1B8(r4) == 1)
            return 3;
        if (func_021BB1C4(r4) == 1)
            return 4;
        if (func_021BB1D0(r4) == 1)
            return 5;
        if (func_021BB1DC(r4) == 1)
            return 6;
        if (func_021BB1E8(r4) == 1)
            return 7;
    }
    return 0;
}










u32 func_021A682C(u8 *p, u32 a1, u32 a2)
{
    u32 k;

    if (!func_0216D3CC(*(u32 *)&((struct Obj01658 *)p)->f1C))
        return a1;
    if (a2 == 0) {
        k = func_021A67A4(p);
        if (k != 0)
            return data_021D8AB8[k](p, a1, a2);
    }
    func_021A6870(p);
    return a1;
}










void func_021A6870(u8 *p)
{
    u32 o = *(u32 *)&((struct Obj01658 *)p)->f1C;

    if (func_021A66F8((S_021A66F8 *)p, 0x59))
        func_0216D550((u32 *)o, 0x18);
    if (func_021A66F8((S_021A66F8 *)p, 1)) {
        func_021A6714(p);
        func_021A6720(p);
        func_021A3964((u8 *)(*(u32 *)&((struct Obj01658 *)p)->f14), 0);
    }
    if (func_021A66F8((S_021A66F8 *)p, 0x18)) {
        func_021A6750(p);
        func_021A6768(p);
        func_0216D60C(o, func_021642A4(func_0216D608((void *)o)));
    }
    if (func_021A66F8((S_021A66F8 *)p, 0x20)) {
        func_021A6780(p);
        func_0216D60C(o, 3);
    }
    if (func_021A66F8((S_021A66F8 *)p, 0x40)) {
        func_021A6798(p);
        func_021A6BAC(p + 0xC);
    }
}










u32 func_021A6908(void *p, u32 a1, u32 a2)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r6 = func_0216D608(o);

    if (func_021A5B6C((u32)p, (u32)o, r6, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A6750(p);
    func_021A6768(p);
    func_0216D5E0((int)o, r6);
    func_0216D410((int)o, func_02197E7C(r6, 0x10));
    func_0216D548(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r6;
}










u32 func_021A6974(u8 *p, u32 a1)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r7 = func_0216D608(o);

    if (func_021A5B6C((u32)p, (u32)o, r7, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A6744(p);
    func_021A6768(p);
    func_0216D410((int)o, func_02197E7C(r7, 0x10));
    func_0216D548(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r7;
}








u32 func_021A69D8(u8 *p, u32 a1)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r7 = func_0216D608(o);

    if (func_021A5B6C((u32)p, (u32)o, r7, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A675C(p);
    func_021A6750(p);
    func_0216D410((int)o, func_02197E7C(r7, 0x10));
    func_0216D548(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r7;
}







int func_021A6A3C(S_021A6A3C *a, int b, int c)
{
    if (func_0216D608((void *)a->f1c) == 2) {
        func_020061E4(0x55e);
    }
    return func_021A6908(a, b, c);
}







int func_021A6A64(S_021A6A3C *a, int b, int c)
{
    if (func_0216D608((void *)a->f1c) == 3) {
        func_020061E4(0x55e);
    }
    return func_021A6908(a, b, c);
}







int func_021A6A8C(S *a, int b, int c)
{
    int r = func_021A6908(a, b, c);
    func_021A6774(a);
    return r;
}







/*
 * Addresses are Black-image addresses.
 */
u32 func_021A6AA0(u8 *p, u32 a1)
{
    u32 r5;

    if (!func_021A66F8((S_021A66F8 *)p, 0x40)) {
        func_021A678C(p);
        func_021A6B9C(p + 0xC);
    }
    r5 = (u16)func_021A6C4C((T *)(p + 0xC), a1);
    if (func_021A6C64(p + 0xC)) {
        func_0216D548(((struct Obj07501 *)p)->f1C, 0x18);
        func_0216D410((int)(((struct Obj07501 *)p)->f1C), func_02197E7C(r5, 8));
        func_021A3964(*(u8 * *)&((struct Obj07501 *)p)->f14, 1);
        r5 = 9;
    } else {
        func_0216D550(((struct Obj07501 *)p)->f1C, 0x18);
    }
    return r5;
}







void func_021A6B08(P *p, u8 v)
{
    if (p->b0 != 1 || v != p->b1) {
        func_020061E4(0x6d1);
        p->b0 = 1;
        p->b1 = v;
        p->h2 = 0;
    }
}







void func_021A6B30(P *p)
{
    if (p->b0) {
        p->b0 = 0;
        p->h2 = 0;
        func_020061F8(func_02006148(0x6d1));
    }
}







void func_021A6B50(P *p, int a)
{
    if (p->b0) {
        p->h2 = (p->h2 + 1) % 4;
        func_0216D5D8(a, d_021D8AB0[p->b1][p->h2]);
    }
}







/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A6B88(void *a)
{
    func_02082BCC(a, 0, 8);
    ((struct Obj18062 *)a)->f4 = 9;
    return 9;
}







void func_021A6B9C(u8 *a)
{
    *a = (1 | (*a & ~1));
}







/*
 * Tail-call thunk: forwards to func_021A6B88 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_021A6BAC(void *a)
{
    return func_021A6B88(a);
}







void func_021A6BB4(St *p, u32 a1, u32 a2)
{
    if (p->on) {
        if (p->st != 0) {
            if (a1 != 9) {
                p->cnt = 0;
                p->st = 0;
                if (p->keep)
                    p->val = a1;
            }
        } else if (a1 == 9) {
            if (p->cnt < 30)
                p->cnt = p->cnt + 1;
            else
                p->st = 1;
        }
        if (func_0216D3CC(a2) == 1) {
            if (p->st == 0) {
                p->keep = 0;
                p->flag = 0;
            } else {
                p->keep = 1;
                p->flag = 1;
            }
        }
    }
}







void func_021A6C30(T *t)
{
    if (t->b2) {
        t->b2 = 0;
    }
    if (!t->b1) {
        t->f4 = 9;
    }
}







int func_021A6C4C(T *t, int x)
{
    int r;
    if (t->b2) {
        return 1;
    }
    r = t->f4;
    if (r == 9) {
        r = x;
    }
    return r;
}







u32 func_021A6C64(u8 *p)
{
    return ((u32)*p << 30) >> 31;
}







int func_021A6C6C(u8 *p, u32 k)
{
    u32 buf[2];
    void *o = func_021A3960(*(unsigned char * *)&((struct Obj01119 *)p)->f14);
    u32 r4;

    r4 = func_02012844(func_020120F4(func_02188C80(*(u8 * *)&((struct Obj01119 *)p)->f18)));
    func_0219E664(o, k, buf);
    return func_02162598((char *)r4, (struct Q *)buf) != 0xFFFF;
}







void func_021A6CB8(struct Obj00020 *a, u32 b, u32 c)
{
    u8 *r4;

    func_02188C58(a);
    func_02188C5C((u8 *)a);
    r4 = func_02188CB4(a);
    func_02188CAC((u8 *)a, (u32)func_021A6D58(a, func_02188C84((u8 *)a)));
    func_02188D40((u8 *)a, (u32)func_0216D888(func_021A3074(r4)));
    func_021A36B0(r4, func_02012AB8(func_020127A4(func_020120F4(func_02188C80(a)))));
    func_021A36D4(r4, b);
    func_021A3044(r4, (void *)b);
    func_021A305C((char *)r4, c);
}







/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6D30(u8 *a0)
{
    func_021A6D9C((void *)func_02188CA4(a0));
}







void func_021A6D3C(u8 *a0)
{
    func_021A6DA4((u32 *)func_02188CA4(a0));
}







int func_021A6D48(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D888(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}







u32 *func_021A6D58(void *a, u32 heap)
{
    u32 r7 = func_02188C5C(a);
    u32 *p = sub_02030734(heap, 8, 1, data_021DDF1C, 0x3e);
    void *r6 = func_02188CB4(a);

    ((struct Obj19810 *)p)->f0 = r6;
    func_021A3664(r6, heap);
    func_021BB3AC((u8 *)r7, func_021A36A4(r6));
    return p;
}





/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6D9C(void *a0)
{
    func_020307B0(a0);
}





void func_021A6DA4(u32 *a)
{
    u32 x = func_020362DC();
    u32 y = func_0203630C();
    func_021A3674((u8 *)(*a), x, y);
}





/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021A6DC0(u8 *p)
{
    return ((struct Obj18063 *)p)->f0;
}





void func_021A6DC4(u32 *b, void *a)
{
    u16 out2[6];
    u16 out1[4];
    u16 k = func_0216D5F8(func_021A3074(((unsigned char **)b)[1]));
    if (b[0] == 0) {
        if (func_021A71E4((u32)a, b, out1, k) != 0) {
            func_021A70D0((u32)a, b, k, 0, (u32)out1, 0, 0);
        }
    } else {
        if (func_021A7198((u32)a, b, (V *)((struct V *)out2), k) != 0) {
            func_021A712C((u32)a, b, k, 0, (u32)out2, 0, 0);
        }
    }
    b[2] = 0;
}





/*
 * Creates the 12-byte model holder for a field-map object, loads its
 * model, and places it through func_021A7258 in the mode the object's
 * record asks for (0: at pos; else attached to the record's anchor).
 */
void func_021A6E30(void *o, VecFx32_021A6E30 *pos, u16 e)
{
    void *r;
    u16 heap;
    Holder_021A6E30 *h;
    int mode;
    void *m;
    VecFx32_021A6E30 *anchor;
    u16 anim[2];

    r = func_020127A4(func_020120F4(func_02188C80(o)));
    heap = func_02188C84(o);
    h = func_02030734(heap, sizeof(Holder_021A6E30), 1, &d_021DDF64, 0xbd);
    func_02188CAC(o, (u32)h);
    h->f04 = func_02188CB4(o);
    mode = func_02012AC0(r);
    h->mode = 2;
    m = func_021A3074(h->f04);
    func_0219F058((u32)m, &anim[0], &anim[1]);
    if (mode == 0) {
        func_021A35E0(h->f04, heap);
        func_021A3664(h->f04, heap);
        func_021A305C(h->f04, e);
        func_021A7258(o, (Holder_021A7258 *)h, mode, pos, e, anim[0], anim[1]);
    } else {
        anchor = (VecFx32_021A6E30 *)func_02012AB8(r);
        func_021A3664(h->f04, heap);
        func_021A35E0(h->f04, heap);
        func_021A305C(h->f04, e);
        func_021A7258(o, (Holder_021A7258 *)h, mode, anchor, e, anim[0], anim[1]);
    }
    func_02188D40(o, (u32)func_0216D888(m));
    func_021A3038(h->f04, (struct V3 *)pos);
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A6F18(u32 a, u32 b, u32 c, u32 d)
{
return func_020307B0((void *)func_02188CA4((u8 *)a));
}








void func_021A6F24(u32 a, int *v)
{
    u32 *p = (u32 *)func_02188CA4((u8 *)a);
    d_021DDF38.cb[p[0]](a, p);
    func_021A3038((unsigned char *)p[1], (struct V3 *)((struct VecFx32_021A6E30 *)v));
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A6F4C(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D888(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}





/*
 * Addresses are Black-image addresses.
 */
void func_021A6F5C(u32 a, u32 *b)
{
    u16 out[4];
    u32 v1c;
    u32 v18;
    void *v14;
    u32 v10;
    u32 r7;
    u32 fl;
    u16 r4;
    v10 = func_020362DC();
    r7 = func_0203630C();
    fl = 0;
    v14 = func_021A3074((unsigned char *)b[1]);
    r4 = func_021A2FA4((u8 *)b[1], r7);
    if (func_0216D3CC((int)v14) == 1 || func_021A2FB0(b[1]) == 1) {
        if (r4 != 9) {
            v18 = func_021A30C8((void **)b[1]);
            v1c = func_021A3128((u32 *)b[1], r4);
            if (func_021BB1A0(func_021AB0F0(v18)) != 0) {
                if (func_021AB11C(v1c) != 0) {
                    if (func_021A71E4(a, b, out, r4) != 0) {
                        func_021A70D0(a, b, r4, 1, (u32)out, v10, r7);
                        return;
                    }
                }
            }
        }
    }
    if (func_021A35BC(b[1]) == 1)
        fl |= 1;
    func_021A35F0((void *)b[1], v10, r7, fl);
}





void func_021A7010(u32 a, u32 *b)
{
    u16 out[6];
    u32 v1c;
    u32 v18;
    u32 v14;
    void *v10;
    u32 r6;
    u32 r7;
    u16 r4;
    v14 = func_020362DC();
    r6 = func_0203630C();
    v10 = func_021A3074((unsigned char *)b[1]);
    if (b[2] == 0) {
        r4 = func_021A2FA4((u8 *)b[1], r6);
        r7 = 1;
    } else {
        r4 = func_0216D608(v10);
        r7 = 0;
    }
    if (func_0216D3CC((int)v10) == 1 || func_021A2FB0(b[1]) == 1) {
        if (r4 != 9) {
            v18 = func_021A30C8((void **)b[1]);
            v1c = func_021A3128((u32 *)b[1], r4);
            if (func_021BB1A0(func_021AB0F0(v18)) != 0) {
                if (func_021AB11C(v1c) != 0) {
                    if (func_021A7198(a, b, (struct V *)out, r4) != 0) {
                        func_021A712C(a, b, r4, r7, (u32)out, v14, r6);
                        b[2] = 0;
                        return;
                    }
                }
            }
        }
    }
    b[2] = func_021A3698((u8 *)b[1]);
    func_021A3674((u8 *)b[1], v14, r6);
}





void func_021A70D0(u32 a, u32 *b, u16 c, u32 d, u32 e, u32 f, u32 g)
{
    u16 v[2];
    void *h;
    h = func_021A3074((unsigned char *)b[1]);
    func_0219F058((u32)h, &v[0], &v[1]);
    func_021A35F0((void *)b[1], 0, 0, 0);
    if (d == 0)
        c = func_0216D5F8(h);
    func_021A7258((void *)a, (Holder_021A7258 *)((Holder_021A6E30 *)b), 1, (VecFx32_021A6E30 *)e, c, v[0], v[1]);
    func_021A3674((u8 *)b[1], f, g);
}





void func_021A712C(u32 a, u32 *b, u16 c, u32 d, u32 e, u32 f, u32 g)
{
    u16 v[2];
    void *h;
    u32 fl;
    fl = 0;
    h = func_021A3074((unsigned char *)b[1]);
    func_0219F058((u32)h, &v[0], &v[1]);
    func_021A3674((u8 *)b[1], 0, 0);
    if (d == 0)
        c = func_0216D5F8(h);
    func_021A7258((void *)a, (Holder_021A7258 *)((Holder_021A6E30 *)b), 0, (VecFx32_021A6E30 *)e, c, v[0], v[1]);
    if (func_021A35BC(b[1]) == 1)
        fl |= 1;
    func_021A35F0((void *)b[1], f, g, fl);
}





int func_021A7198(u32 a, u32 *b, V *c, u32 d)
{
    u32 h;
    V v;
    h = func_02188C98((u8 *)a);
    func_021A3038((unsigned char *)b[1], (struct V3 *)((struct VecFx32 *)c));
    v = *c;
    func_02164208(d, (int *)(&v), 0x10000);
    if (func_021AB11C(func_021AB0D4((void *)h, &v)) == 0)
        return 1;
    return 0;
}



/*
 * Addresses are Black-image addresses.
 */
int func_021A71E4(u32 a, u32 *b, u16 *c, u32 d)
{
    V w;
    V in;
    V q;
    u16 r[8];
    u32 h;
    h = (u32)func_021BB480((void *)func_02188C5C((u8 *)a));
    func_021A3038((unsigned char *)b[1], (struct V3 *)((struct VecFx32_021A6E30 *)&in));
    q.x = in.x;
    q.y = in.y + 0x4000;
    q.z = in.z;
    in.y = in.y - 0x4000;
    if (func_021B7A84(h, &in, &q, &r[4], &w) != 0)
        func_021B7CD8(h, &r[4], func_0201441C(d), r);
    c[0] = r[4];
    c[1] = r[5];
    c[2] = r[6];
    c[3] = r[7];
}



/*
 * Switches an object's model between the placed mode (0: position copied
 * in and rotation set from whole-unit sixteenths) and the attached mode,
 * then applies the shared animation settings and records the new mode.
 * d_021DDF38 is one static record: two callbacks, then at +8 the
 * parameter block func_0216E0AC takes, whose u16 at +0xA is refreshed
 * here (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-
 * by-the-load-reach.md).
 */
void func_021A7258(void *o, Holder_021A7258 *h, int mode, VecFx32_021A6E30 *pos, u16 e, u16 f, u16 g)
{
    void *x;
    void *y;
    void *m;
    VecFx32_021A6E30 v;

    x = (void *)func_02188C5C(o);
    y = func_02188C58(o);
    if (h->mode == mode) {
        return;
    }
    m = func_021A3074(h->f04);
    if (func_0216DC4C(m) != 0) {
        func_0216D4B4(m);
    }
    if (mode == 0) {
        v = *pos;
        d_021DDF38.param.f2 = func_0216D598(m);
        func_021A368C(h->f04);
        func_0216E0AC(m, &d_021DDF38.param);
        func_0216E084(m, (s16)((v.x >> 12) / 16), (s16)((v.y >> 12) / 16), (s16)((v.z >> 12) / 16), e);
        func_0216D88C(m, (struct V3 *)&v);
        func_021A3044(h->f04, &v);
        func_021BB3B8(x);
        func_0218E13C(y, 0);
        func_0218EC60((u32)y);
        func_0218E160((u32)y);
    } else {
        func_021A3680(h->f04, (int)pos);
        func_021BB3AC(x, func_021A36A4(h->f04));
        func_0218F05C(y);
    }
    func_0216D5E0((int)m, e);
    func_0216D600((int)m, e);
    func_0219F0B0((u32)m, f, g);
    h->mode = mode;
}
