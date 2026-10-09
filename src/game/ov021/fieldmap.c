/*
 * file:     fieldmap.c
 * unit:     yes
 * function: func_02187F00, func_02187FD0, func_02187FE8, func_02188030, func_021880A4, func_021880C8, func_021881D8, func_021885E8, func_02188758, func_021888C8, func_02188910, func_02188990, func_02188AD4, func_02188B58, func_02188BD8, func_02188BE8, func_02188BF8, func_02188C54, func_02188C58, func_02188C5C, func_02188C60, func_02188C64, func_02188C68, func_02188C6C, func_02188C70, func_02188C7C, func_02188C80, func_02188C84, func_02188C88, func_02188C90, func_02188C98, func_02188C9C, func_02188CA4, func_02188CAC, func_02188CB4, func_02188CBC, func_02188CCC, func_02188CD0, func_02188CD8, func_02188CE0, func_02188CE8, func_02188CF0, func_02188CFC, func_02188D20, func_02188D24, func_02188D2C, func_02188D30, func_02188D38, func_02188D40, func_02188D48, func_02188D4C, func_02188D50, func_02188D58, func_02188D5C, func_02188DA0, func_02188DB0, func_02188DF0, func_02188E30, func_02188E38, func_02188E50, func_02188EE4, func_02189004, func_02189084, func_021890AC, func_021890C8, func_02189108, func_02189140, func_02189154, func_021891C0, func_02189204, func_021892B4, func_021892CC, func_0218932C, func_02189370, func_021893C0, func_021894E0, func_02189518, func_02189560, func_0218958C, func_021895BC, func_021895D0, func_021895DC, func_021895E8, func_02189614, func_02189684, func_021896F4, func_02189734, func_02189758, func_02189764, func_021897A0, func_021897BC, func_021897DC, func_02189810, func_02189998, func_021899C4, func_021899F0, func_021899F8, func_02189A00, func_02189A08, func_02189A10, func_02189A18, func_02189A1C, func_02189A24, func_02189A2C, func_02189A38, func_02189A48, func_02189A50, func_02189A58, func_02189A60, func_02189A68, func_02189A70, func_02189A78, func_02189A80, func_02189ACC, func_02189AE8, func_02189B04, func_02189B28, func_02189B30, func_02189BA8
 * address:  0x02187F00
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
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02189BBC  0x02189BBC  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_02030678  0x02030678  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02012110  0x02012110  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   d_021DE700     0x021DE700  data
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0201407C  0x0201407C  thumb
 *   d_021DD9C0     0x021DD9C0  data  a4
 *   func_020140B4  0x020140B4  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020371AC  0x020371AC  arm
 *   d_021D3688     0x021D3688  data
 *   d_021D3604     0x021D3604  data
 *   abs_id_19      0x00000013  data
 *   abs_id_18      0x00000012  data
 *   func_020433E0  0x020433E0  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02045088  0x02045088  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_02046440  0x02046440  arm
 *   func_02012984  0x02012984  thumb
 *   func_0218C9E8  0x0218C9E8  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_021C6D10  0x021C6D10  thumb
 *   func_021D317C  0x021D317C  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02035660  0x02035660  arm
 *   func_0216447C  0x0216447C  thumb  ov010
 *   func_021901EC  0x021901EC  thumb  ov021
 *   func_021BC388  0x021BC388  thumb  ov021
 *   func_02012B38  0x02012B38  thumb
 *   func_02014470  0x02014470  thumb
 *   func_021C7F70  0x021C7F70  thumb  ov021
 *   func_02013BBC  0x02013BBC  thumb
 *   func_0218E018  0x0218E018  thumb  ov021
 *   func_021AB5F4  0x021AB5F4  thumb  ov021
 *   func_021AB7E4  0x021AB7E4  thumb  ov021
 *   func_021BB1F4  0x021BB1F4  thumb  ov021
 *   func_021D33A8  0x021D33A8  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_02012974  0x02012974  thumb
 *   func_021D33F8  0x021D33F8  thumb  ov021
 *   func_0218B8AC  0x0218B8AC  thumb  ov021
 *   func_021C6534  0x021C6534  thumb  ov021
 *   func_02014110  0x02014110  thumb
 *   func_0218CEE4  0x0218CEE4  thumb  ov021
 *   func_02013C9C  0x02013C9C  thumb
 *   func_021BB2F8  0x021BB2F8  thumb  ov021
 *   func_021ABD50  0x021ABD50  thumb  ov021
 *   func_021ABF68  0x021ABF68  thumb  ov021
 *   func_021AC1EC  0x021AC1EC  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   d_021D8F00     0x021D8F00  data
 *   d_021D8F10     0x021D8F10  data
 *   func_0217F8C0  0x0217F8C0  thumb  ov019
 *   func_02012AE4  0x02012AE4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02013C20  0x02013C20  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021A2E50  0x021A2E50  thumb  ov021
 *   func_0218D158  0x0218D158  thumb  ov021
 *   func_021BE2A8  0x021BE2A8  thumb  ov021
 *   func_021A0104  0x021A0104  thumb  ov021
 *   func_021A02C4  0x021A02C4  thumb  ov021
 *   func_02013EEC  0x02013EEC  thumb
 *   func_02013F2C  0x02013F2C  thumb
 *   func_021A0338  0x021A0338  thumb  ov021
 *   func_020140DC  0x020140DC  thumb
 *   func_0203F4FC  0x0203F4FC  arm
 *   func_021A03D0  0x021A03D0  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_021A19E8  0x021A19E8  thumb  ov021
 *   func_02012994  0x02012994  thumb
 *   func_021A1B74  0x021A1B74  thumb  ov021
 *   func_021BE1DC  0x021BE1DC  thumb  ov021
 *   func_020129AC  0x020129AC  thumb
 *   func_021A0CF4  0x021A0CF4  thumb  ov021
 *   func_021A9ED8  0x021A9ED8  thumb  ov021
 *   func_02026388  0x02026388  thumb
 *   func_021BB890  0x021BB890  thumb  ov021
 *   func_021C1A08  0x021C1A08  thumb  ov021
 *   func_021C1AF4  0x021C1AF4  thumb  ov021
 *   func_021CF45C  0x021CF45C  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_021C31D4  0x021C31D4  thumb  ov021
 *   func_0218CA78  0x0218CA78  thumb  ov021
 *   func_0216CD64  0x0216CD64  thumb  ov010
 *   func_0219C624  0x0219C624  thumb  ov021
 *   func_0219C630  0x0219C630  thumb  ov021
 *   func_021A1B50  0x021A1B50  thumb  ov021
 *   func_021A1AF4  0x021A1AF4  thumb  ov021
 *   func_0204A600  0x0204A600  arm
 *   func_021903E0  0x021903E0  thumb  ov021
 *   func_021ABE04  0x021ABE04  thumb  ov021
 *   func_021BB948  0x021BB948  thumb  ov021
 *   func_02014460  0x02014460  thumb
 *   func_02005C64  0x02005C64  thumb
 *   func_02014458  0x02014458  thumb
 *   func_02158AC8  0x02158AC8  thumb  ov010
 *   func_02014454  0x02014454  thumb
 *   func_02158AD4  0x02158AD4  thumb  ov010
 *   func_0201445C  0x0201445C  thumb
 *   func_0201209C  0x0201209C  thumb
 *   func_020129DC  0x020129DC  thumb
 *   func_0218A0E4  0x0218A0E4  thumb  ov021
 *   func_0218A240  0x0218A240  thumb  ov021
 *   func_0218A4BC  0x0218A4BC  thumb  ov021
 *   func_0218A074  0x0218A074  thumb  ov021
 *   func_02012104  0x02012104  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02035648  0x02035648  arm
 *   func_020120D8  0x020120D8  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_021BC484  0x021BC484  thumb  ov021
 *   func_021C7FAC  0x021C7FAC  thumb  ov021
 *   func_021A2EB8  0x021A2EB8  thumb  ov021
 *   func_021737A4  0x021737A4  thumb  ov012
 *   func_0217AE20  0x0217AE20  thumb  ov018
 *   func_021A0D68  0x021A0D68  thumb  ov021
 *   func_021BE258  0x021BE258  thumb  ov021
 *   func_0217F914  0x0217F914  thumb  ov018
 *   func_02030D28  0x02030D28  arm
 *   func_021C6D90  0x021C6D90  thumb  ov021
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021C8660  0x021C8660  thumb  ov021
 *   func_02047CE4  0x02047CE4  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_020129F0  0x020129F0  thumb
 *   func_0218CC34  0x0218CC34  thumb
 *   func_021A0E58  0x021A0E58  thumb
 *   func_021BC4F0  0x021BC4F0  thumb
 *   func_021CF480  0x021CF480  thumb  ov021
 *   func_021C1C04  0x021C1C04  thumb  ov021
 *   func_021C1AD0  0x021C1AD0  thumb  ov021
 *   func_021BB90C  0x021BB90C  thumb  ov021
 *   func_020263B0  0x020263B0  thumb
 *   func_021BC424  0x021BC424  thumb  ov021
 *   func_021BE218  0x021BE218  thumb  ov021
 *   func_021BE2E0  0x021BE2E0  thumb  ov021
 *   func_021A9F28  0x021A9F28  thumb  ov021
 *   func_021A0D44  0x021A0D44  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_021ABDE8  0x021ABDE8  thumb  ov021
 *   func_0217F8EC  0x0217F8EC  thumb  ov019
 *   func_021A1AAC  0x021A1AAC  thumb  ov021
 *   func_021A0448  0x021A0448  thumb  ov021
 *   func_021A02F4  0x021A02F4  thumb  ov021
 *   func_021A0138  0x021A0138  thumb  ov021
 *   func_021D33E0  0x021D33E0  thumb  ov021
 *   func_021BB240  0x021BB240  thumb  ov021
 *   func_021AB81C  0x021AB81C  thumb  ov021
 *   func_021AB624  0x021AB624  thumb  ov021
 *   func_0218E0E4  0x0218E0E4  thumb  ov021
 *   func_021A2E90  0x021A2E90  thumb  ov021
 *   func_0218D05C  0x0218D05C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_021902BC  0x021902BC  thumb  ov021
 *   func_021C31FC  0x021C31FC  thumb  ov021
 *   func_021C7F9C  0x021C7F9C  thumb  ov021
 *   func_02030DA4  0x02030DA4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021D31A4  0x021D31A4  thumb
 *   func_021C6D5C  0x021C6D5C  thumb
 *   func_0218CA4C  0x0218CA4C  thumb
 *   abs_id_13  0x00000013  data
 *   abs_id_12  0x00000012  data
 *   data_021D36B8  0x021D36B8  data  a4
 *   func_021A3098  0x021A3098  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_021A2F54  0x021A2F54  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0202C794  0x0202C794  thumb
 *   data_021D35A8  0x021D35A8  data
 *   func_021A6DC0  0x021A6DC0  thumb
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02040E78  0x02040E78  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   d_021D3620     0x021D3620  data
 *   func_0203FC28  0x0203FC28  arm
 *   func_02051E74  0x02051E74  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_0204044C  0x0204044C  arm
 *   func_02190270  0x02190270  thumb
 *   func_0219027C  0x0219027C  thumb
 *   func_0206DB80  0x0206DB80  arm
 *   func_02046788  0x02046788  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 *   func_0207DD24  0x0207DD24  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   func_02046BE0  0x02046BE0  arm
 *   data_021D3640  0x021D3640  data  a4
 *   data_021D35E4  0x021D35E4  data  a4
 *   func_0204FE94  0x0204FE94  arm
 *   func_02050080  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204EDC4  0x0204EDC4  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   func_021C63AC  0x021C63AC  thumb  ov021
 *   func_02048A24  0x02048A24  arm
 *   func_02048BC4  0x02048BC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048C58  0x02048C58  arm
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   d_021D36F4     0x021D36F4  data  a4
 *   d_021D36E8     0x021D36E8  data  a4
 *   d_021D35C0     0x021D35C0  data  a4
 *   d_021D35CC     0x021D35CC  data  a4
 *   d_021D35AC     0x021D35AC  data  a4
 *   func_020504D8  0x020504D8  arm
 *   func_021BB36C  0x021BB36C  thumb
 *   func_021AB660  0x021AB660  thumb
 *   func_021A030C  0x021A030C  thumb
 *   func_021A0140  0x021A0140  thumb
 *   func_021A0458  0x021A0458  thumb
 *   func_0218CB34  0x0218CB34  thumb
 *   func_0203D12C  0x0203D12C  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   d_021D35D8     0x021D35D8  data  a4
 *   func_02047970  0x02047970  arm
 *   d_021D35B4     0x021D35B4  data  a4
 *   func_02048C4C  0x02048C4C  arm
 *   func_02048AC4  0x02048AC4  arm
 *   func_0204FFFC  0x0204FFFC  arm
 *   func_021C6400  0x021C6400  thumb  ov021
 *   func_02005C8C  0x02005C8C  thumb
 *   func_0216CD78  0x0216CD78  thumb  ov010
 *   func_021C6470  0x021C6470  thumb  ov021
 *   func_0204A648  0x0204A648  arm
 *   func_021D31AC  0x021D31AC  thumb  ov021
 *   func_02061CA4  0x02061CA4  arm
 *   func_020140E0  0x020140E0  thumb
 *   func_02013DB8  0x02013DB8  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   data_021EE700  0x021EE700  data  a4
 *   data_021EE700b  0x021EE700  data
 *   func_020140E4  0x020140E4  thumb
 *   func_021CD1C8  0x021CD1C8  thumb
 *   func_021CD204  0x021CD204  thumb
 *   func_021CD214  0x021CD214  thumb
 *   func_021CD1F0  0x021CD1F0  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216CCDC  0x0216CCDC  thumb  ov010
 *   func_0219C554  0x0219C554  thumb
 *   func_0219C680  0x0219C680  thumb
 *   func_0217C0A8  0x0217C0A8  thumb  ov018
 *   func_021A31A4  0x021A31A4  thumb
 *   func_0219C658  0x0219C658  thumb
 *   func_0219D448  0x0219D448  thumb
 *   func_0218ED50  0x0218ED50  thumb
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0216D2F8  0x0216D2F8  thumb  ov010
 *   func_0216D974  0x0216D974  thumb  ov010
 *   func_0216D2AC  0x0216D2AC  thumb  ov010
 *   func_0216CD50  0x0216CD50  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162458  0x02162458  thumb  ov010
 *   func_02162438  0x02162438  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_020141E0  0x020141E0  thumb
 *   func_020141F0  0x020141F0  thumb
 *   func_02159C48  0x02159C48  thumb  ov010
 *   func_02159BD4  0x02159BD4  thumb  ov010
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_0216DF1C  0x0216DF1C  thumb  ov010
 *   func_021623DC  0x021623DC  thumb  ov010
 *   func_0216242C  0x0216242C  thumb  ov010
 *   func_021643AC  0x021643AC  thumb  ov010
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_0202735C  0x0202735C  thumb
 *   func_0215A014  0x0215A014  thumb  ov010
 *   func_02158AE0  0x02158AE0  thumb  ov010
 *   func_0215874C  0x0215874C  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 *   func_02012134  0x02012134  thumb
 *   func_0202B544  0x0202B544  thumb
 *   func_02029CF0  0x02029CF0  thumb
 *   func_0202C83C  0x0202C83C  thumb
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 *   func_021A0358  0x021A0358  thumb  ov021
 *   func_02012AC4  0x02012AC4  thumb
 *   func_02013BD0  0x02013BD0  thumb
 *   func_0218F14C  0x0218F14C  thumb  ov021
 *   func_0218F134  0x0218F134  thumb  ov021
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_0218DC74  0x0218DC74  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_021939C0  0x021939C0  thumb  ov021
 *   func_02193ABC  0x02193ABC  thumb  ov021
 *   func_02193AFC  0x02193AFC  thumb  ov021
 *   func_02013FA8  0x02013FA8  thumb
 *   func_02013C80  0x02013C80  thumb
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_021A0170  0x021A0170  thumb  ov021
 *   func_021A0568  0x021A0568  thumb  ov021
 *   func_0218CC64  0x0218CC64  thumb  ov021
 *   func_0219047C    0x0219047C  thumb  ov021
 *   func_021C7FB4    0x021C7FB4  thumb  ov021
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_0206A854    0x0206A854  arm
 *   func_021ABE0C    0x021ABE0C  thumb  ov021
 *   func_021C64E0    0x021C64E0  thumb  ov021
 *   func_02050790    0x02050790  arm
 *   func_0217F928    0x0217F928  thumb  ov019
 *   func_021BB954    0x021BB954  thumb  ov021
 *   func_021A1B38    0x021A1B38  thumb  ov021
 *   func_021BE4F8    0x021BE4F8  thumb  ov021
 *   func_021C1AEC    0x021C1AEC  thumb  ov021
 *   func_021C1C4C    0x021C1C4C  thumb  ov021
 *   g_02148B54       0x02148B54  data
 *   g_02148BCC       0x02148BCC  data
 *   func_021CF520  0x021CF520  thumb  ov021
 *   func_020113D8  0x020113D8  thumb
 *   func_0218ED3C  0x0218ED3C  thumb  ov021
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02013BA8  0x02013BA8  thumb
 *   func_02013B50  0x02013B50  thumb
 *   func_02159BF4  0x02159BF4  thumb  ov010
 *   func_02159BF8  0x02159BF8  thumb  ov010
 *   func_02159BFC  0x02159BFC  thumb  ov010
 *   func_02159C20  0x02159C20  thumb  ov010
 *   func_020140BC  0x020140BC  thumb
 *   func_020140C0  0x020140C0  thumb
 *   func_020140CC  0x020140CC  thumb
 *   d_021D3700     0x021D3700  data  a4
 *   d_021D373C     0x021D373C  data  a4
 */
#include "../../matched/include/Obj17856.h"
#include "../../matched/include/Obj03102.h"
#include "../../matched/include/Obj01489.h"
#include "../../matched/include/Obj00571.h"
#include "../../matched/include/Obj00611.h"
#include "../../matched/include/Obj00518.h"
#include "../../matched/include/Obj12555.h"
#include "../../matched/include/Obj04193.h"
#include "../../matched/include/Obj00401.h"
#include "../../matched/include/Obj03103.h"
#include "../../matched/include/Obj02685.h"
#include "../../matched/include/Obj12061.h"
#include "../../matched/include/Obj17857.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj17858.h"
#include "../../matched/include/Obj17859.h"
#include "../../matched/include/Obj19487.h"
#include "../../matched/include/Obj19488.h"
#include "../../matched/include/Obj17860.h"
#include "../../matched/include/Obj17861.h"
#include "../../matched/include/Obj17862.h"
#include "../../matched/include/Obj17863.h"
#include "../../matched/include/Obj17864.h"
#include "../../matched/include/Obj17865.h"
#include "../../matched/include/Obj17866.h"
#include "../../matched/include/Obj17867.h"
#include "../../matched/include/Obj17868.h"
#include "../../matched/include/Obj17870.h"
#include "../../matched/include/Obj17871.h"
#include "../../matched/include/Obj17872.h"
#include "../../matched/include/Obj19490.h"
#include "../../matched/include/Obj17873.h"
#include "../../matched/include/Obj17875.h"
#include "../../matched/include/Obj17876.h"
#include "../../matched/include/Obj17877.h"
#include "../../matched/include/Obj17878.h"
#include "../../matched/include/Obj17879.h"
#include "../../matched/include/Obj17880.h"
#include "../../matched/include/Obj17881.h"
#include "../../matched/include/Obj17882.h"
#include "../../matched/include/Obj17883.h"
#include "../../matched/include/Obj17884.h"
#include "../../matched/include/Obj19493.h"
#include "../../matched/include/Obj19494.h"
#include "../../matched/include/Obj17885.h"
#include "../../matched/include/Obj01344.h"
#include "../../matched/include/Obj02367.h"
#include "../../matched/include/Obj19495.h"
#include "../../matched/include/Obj04980.h"
#include "../../matched/include/Obj09442.h"
#include "../../matched/include/Obj09172.h"
#include "../../matched/include/Obj09443.h"
#include "../../matched/include/Obj19496.h"
#include "../../matched/include/Obj05698.h"
#include "../../matched/include/Obj19497.h"
#include "../../matched/include/Obj03104.h"
#include "../../matched/include/Obj12557.h"
#include "../../matched/include/Obj19498.h"
#include "../../matched/include/Obj09444.h"
#include "../../matched/include/Obj03105.h"
#include "../../matched/include/Obj04887.h"
#include "../../matched/include/Obj00704.h"
#include "../../matched/include/G_Glb.h"
#include "../../matched/include/Obj19499.h"
#include "../../matched/include/Obj19500.h"
#include "../../matched/include/Obj19501.h"
#include "../../matched/include/Obj19502.h"
#include "../../matched/include/Obj19503.h"
#include "../../matched/include/Obj17887.h"
#include "../../matched/include/Obj17888.h"
#include "../../matched/include/Obj17889.h"
#include "../../matched/include/Obj17890.h"
#include "../../matched/include/Obj19506.h"
#include "../../matched/include/Obj19507.h"
#include "../../matched/include/Obj17891.h"
#include "../../matched/include/Obj17892.h"
#include "../../matched/include/Obj19508.h"
#include "../../matched/include/Obj03106.h"
#include "../../matched/include/G__anon_Ent.h"

#define F16(o)  (*(u16 *)(p + (o)))
#define F32(o)  (*(int *)(p + (o)))
#define REG_DISPCNT (*(volatile u32 *)0x04000000)
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
struct Ctx;
struct Rec44;
struct Obj0203159C;
struct Comm;
struct S020315D4;
struct DispVram;
struct BigObj;
struct Cfg;
struct Big;
struct Obj;
struct Src;
struct Sub0200852CObj;
struct Sub020140BCObj;
struct Sub02014444Obj;
struct Light;
struct T;
struct V3;
struct Obj00020;
struct Node;
struct Sub02008C20Obj;
struct DispConfig;
struct Mtx22;
struct LightSet;
struct LightSlot;
struct Blk3;
struct Owner;
struct BbActSys;
struct SaveBlock;
struct Rec020141E0;
struct Rec020141F0;
struct Vec020141E0;
struct Vec020141F0;
struct Vec12;
struct tagLISTCB;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int x;
    int y;
    int z;
} V3;

typedef struct {
    void *f0;
    void (*f4)(char *p, V3 *v, int c);
} Ops;

typedef struct {
    u32 w[3];
} Rec12;

typedef signed int     s32;

typedef u32 (*Fn)(void *a, void *b);

typedef struct {
    u32 w[3];
} Vec12;

typedef void (*Fn_02189084)(unsigned char *p);

typedef int (*Fn_021890AC)(unsigned char *p);

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct Vec_0218932C { int x, y, z; } Vec_0218932C;

typedef struct Vec_02189370 { int x, y, z; } Vec_02189370;

typedef struct {
    int x, y, z;
} Vec_021893C0;

typedef struct {
    int id;
    void *buf;
} Slot;

typedef int fx32;

typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct {
    u8 pad[0x7C];
    u32 flag;
} Glb;

typedef struct Obj {
    u8 pad00[0xA0];
    void *fa0;          /* 0xA0 */
} Obj;

typedef struct Rec { int w[15]; } Rec;

typedef struct Ent { Rec r; int f3c; int f40; int f44; } Ent;

unsigned char *func_020120F8(const struct Ctx *x);
unsigned short func_02012AC8(const struct Rec44 *x);
int func_02189BBC(int x);
void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
void func_02030678(void *a, u32 b, u32 c);
void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
void func_02012110(struct Ctx *p, void *v);
unsigned int func_0201214C(const struct Ctx *x);
unsigned int func_02012138(const struct Ctx *x);
u32 func_02026454(void *obj);
void func_02026400(struct Comm *p);
void func_020315D4(struct S020315D4 *p);
void func_020306F0(unsigned int heap);
void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, u16 tag);
void *func_020120F4(const struct Ctx *p);
u32 func_02013B38(u32 id);
int func_0202E83C(void *a0);
int func_0201407C(int a, int b, int c);
u32 func_020140B4(void *a);
u32 func_020307B0(void *p);
void func_020371AC(unsigned short a, unsigned int b);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02045088(u16 heapId);
extern void func_0201DD60(void);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u32 fifoSize, u32 heap, void (*setup)(void));
extern u8 func_02012984(const struct BigObj *p);
extern char *func_0218C9E8(int heap, int b);
extern void *func_020056A0(void (*cb)(int, u8 *), void *arg, int pri);
extern u32 func_02030CB0(u32 idx);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern u8 *func_021C6D10(int n, int heap);
extern void *func_021D317C(u32 heap);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern int func_02034AC4(int id);
extern void func_02035660(u32 a);
extern void func_0216447C(int sys, u16 id);
extern u8 *func_021901EC(u16 heap, u32 b);
extern int func_021BC388(int a, int b, int c);
extern void *func_02012B38(const struct BigObj *p);
extern u16 func_02014470(struct Sub02014444Obj *o);
extern int func_021C7F70(int flags, u16 heap);
extern u8 func_02013BBC(u32 id);
extern char *func_0218E018(int a0, int a1, struct Light *a2, int a3, u16 heap);
extern int func_021AB5F4(u16 heap, int a, void *b);
extern int func_021AB7E4(u16 heap);
extern u32 *func_021BB1F4(u32 a, u32 b, u32 c, u32 d);
extern void *func_021D33A8(u16 heapId, void *a1, void *a2, u16 a3);
extern u32 func_0218DC6C(u8 *p);
extern u32 func_02012974(const struct BigObj *p);
extern void *func_021D33F8(u32 *p);
extern void func_0218B8AC(char *p, int a, int b, int c);
extern void func_021C6534(u32 *p, u32 v);
extern void func_02014110(void *p, u16 a, int b, int c, int d, int e, int f, int g);
extern void func_0218CEE4(struct Obj *p, const struct Src *src, void *c);
extern int func_02013C9C(u16 key);
extern void func_021BB2F8(u32 a, u32 b, u32 c);
extern char *func_021ABD50(int a, int b, u16 c);
extern void func_021ABF68(int t, int n);
extern void func_021AC1EC(u32 *p, u32 v);
extern void func_021ABE30(int t, int *arr, int n);
extern void *func_0217F8C0(u16 id);
extern u32 func_02012AE4(const struct Rec44 *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern u32 func_02013C20(u32 id);
extern void func_02012B2C(struct Rec44 *p, u32 v);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 *func_021A2E50(int a, u32 b, int c, int d, u16 heap);
extern void func_0218D158(struct T *dst, const struct V3 *src);
extern int func_021BE2A8(int a, int b, u16 heap);
extern u8 *func_021A0104(u16 heap);
extern u8 *func_021A02C4(u16 heap);
extern u32 func_02013EEC(u32 id);
extern int func_02013F2C(unsigned short id);
extern void func_021A0338(u8 *p, u32 id, u32 c, u8 d);
extern u8 func_020140DC(struct Sub020140BCObj *p);
extern u32 func_0203F4FC(void);
extern u8 *func_021A03D0(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02012A30(const struct BigObj *p);
extern int func_021A19E8(int a0, int a1, int a2, int a3, int a4, int a5, int heap);
extern u8 func_02012994(const struct BigObj *p);
extern void func_021A1B74(u8 *p, int a, int f);
extern void func_021BE1DC(void *arg);
extern u8 func_020129AC(const struct BigObj *p);
extern u32 *func_021A0CF4(u32 a, u32 b, u32 c);
extern u32 *func_021A9ED8(u32 a);
extern void func_02026388(struct Obj *p, u32 a);
extern int *func_021BB890(int a, int b, int n);
extern u32 *func_021C1A08(u32 a);
extern u32 *func_021C1AF4(u32 a, u32 b);
extern void *func_021CF45C(u32 heap, u32 v);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BDB0(void *sys);
extern int func_021C31D4(u16 heap, void *a, int b);
extern void func_0218CA78(char *p);
extern int func_0216CD64(int a0);
extern int func_0219C624(void *p);
extern int func_0219C630(void *p);
extern int func_021A1B50(u32 a);
extern void func_021A1AF4(u8 *p, int x);
extern void func_0204A600(void);
extern void func_021903E0(struct Obj *o);
extern void func_021ABE04(u32 a);
extern void func_021BB948(u8 *p);
extern u8 func_02014460(struct Sub02014444Obj *o);
extern int func_02005C64(void);
extern u8 func_02014458(struct Sub02014444Obj *o);
extern void func_02158AC8(int a, int b);
extern void func_02014454(struct Sub02014444Obj *o, u8 v);
extern void func_02158AD4(int a, int b);
extern void func_0201445C(struct Sub02014444Obj *o, u8 v);
extern void func_0201209C(void *o, u32 v1, u32 v2);
extern void func_020129DC(struct BigObj *p, u8 v);
extern int func_0218A0E4(void *sys, struct Obj00020 *pos);
extern int func_0218A240(void *p, struct Obj00020 *pos);
extern int func_0218A4BC(u32 a, u32 b, u32 c, u32 d);
extern int func_0218A074(void *a, int b);
extern u32 func_02012104(const struct Ctx *p);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern u8 func_02012E40(const u8 *o);
extern void func_02035648(void);
extern int func_020120D8(char *a);
extern void func_02168EEC(int a);
extern void func_021BC484(u32 a);
extern void func_021C7FAC(u32 a);
extern void func_021A2EB8(u32 *a);
extern void func_021737A4(void *a, int b);
extern void func_0217AE20(u8 *a0, int a1, int a2);
extern void func_021A0D68(u32 *a);
extern void func_021BE258(void *p);
extern void func_0217F914(u32 a);
extern void func_02030D28(struct Ctx *c);
extern void func_021C6D90(u8 *p);
extern u32 *func_02012ED0(u32 a);
extern void func_021C8660(u32 a);
void func_02047CE4(void);
unsigned int func_0203630C(void);
void func_0218E104(u8 *a, u32 b);
extern void func_020129F0(struct BigObj *p);
extern void func_0218CC34(u32 a);
extern void func_021A0E58(u32 *a);
extern void func_021BC4F0(int a);
extern int func_021CF480(void *a);
extern void func_021C1C04(u32 *p);
extern void func_021C1AD0(u32 a);
extern void func_021BB90C(u32 a);
extern void func_020263B0(struct Obj *p, u32 a);
extern void func_021BC424(u32 a);
extern void func_021BE218(void *arg);
extern void func_021BE2E0(u32 a);
extern void func_021A9F28(u32 a);
extern u8 func_021A0D44(u32 *p);
extern void func_020129B8(struct BigObj *p, u32 v);
extern void func_021ABDE8(u32 a);
extern void func_0217F8EC(char *p);
extern void func_021A1AAC(u8 *p);
extern void func_021A0448(u8 *p);
extern int func_021A02F4(void *a);
extern void func_021A0138(u32 a);
extern void func_021D33E0(u32 *p);
extern int func_021BB240(u32 a);
extern void func_021AB81C(u32 a);
extern void func_021AB624(u8 *p);
extern void func_0218E0E4(u8 *a);
extern int func_021A2E90(void *a);
extern void func_0218D05C(char *p);
extern int func_02190728(void *a);
extern void func_021902BC(struct Obj *o);
extern void func_021C31FC(u32 a);
extern void func_021C7F9C(u8 *p);
extern void func_02030DA4(u32 a);
extern void func_02030EAC(struct Node *n);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_02034A5C(s32 handle);
extern void func_021D31A4(u32 a);
extern void func_021C6D5C(u32 a);
extern int func_0218CA4C(void *a);
extern u32 func_021A3098(u8 *p);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void func_020061E4(u32 a);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u8 func_0202C794(void *a0, u32 a1);
extern u32 func_021A6DC0(u8 *p);
extern void func_0203F8F4(u16 heap);
extern void func_02040E78(u32 a, void *b, u32 c, u32 d);
extern u32 func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(u32 a, void *buf, u32 b, u32 c, u32 d, u32 e);
extern void func_0204044C(u32 a);
extern void func_02190270(u32 a);
extern void func_0219027C(u8 *a);
extern u32 func_0203F9B4(u32);
extern u32 func_02046788(u32);
extern u32 func_0206DB80(u32);
extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(void *a);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_0207DCF8(void *a);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_0204FE94(u16 a0, u16 a1, u32 a2, int heap);
extern u32 func_02050080(u32 *p);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204EDC4(u8 *dst, int a, int b);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern u32 func_021C63AC(u16 heap, int a, int b);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048AD0(struct Light *l);
extern void func_02048C58(struct LightSlot *slots);
extern void func_020504D8(struct Owner *o);
extern void func_021BB36C(u32 a);
extern int func_021AB660(struct Obj *o, void *arg);
extern void func_021A030C(u8 *p, u32 a);
extern void func_021A0140(u8 *p);
extern void func_021A0458(u8 *a, s32 b);
extern int func_0218CB34(char *p);
extern void func_0203D12C(int a);
void func_02047964(void);
void func_020479D8(void);
void func_02047970(int x);
extern u32 func_02048AC4(void *ptr);
extern u32 func_02048C4C(u32 a);
extern void func_0204FFFC(struct BbActSys *o);
extern u32 func_021C6400(u32);
int func_02005C8C(void);
int func_0216CD78(int a0);
void func_021C6470(int h);
void func_0204A648(void);
void func_021D31AC(int h);
s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u8 func_020140E0(struct Sub020140BCObj *p);
extern u32 func_02013DB8(u32 a);
extern void func_02048F4C(void *a, u32 b, u32 c);
extern u8 func_020140E4(struct Sub020140BCObj *p);
extern u32 func_021CD1C8(u32 a);
extern void func_021CD204(u32 a, u32 b);
extern void func_021CD214(u8 *s, void *o);
extern int func_021CD1F0(void *a);
extern u32 func_02012964(const struct BigObj *p);
extern void func_0216CCDC(char *a, int b, int c, int d, int e, int f);
extern void func_0219C554(u32 a, u32 b, u32 c);
extern void func_0219C680(u32 a);
extern u8 func_0217C0A8(void *a0);
extern int func_021A31A4(int i, int v);
extern void func_0219C658(u32 a, u32 b);
extern void func_0219D448(int a, int b);
extern u8 *func_0218ED50(u8 *p);
extern void func_0216CDB8(u8 *p, u32 v);
extern void func_0216D2F8(u32 a);
extern void func_0216D974(unsigned int *p, unsigned int v);
extern int func_0216CD50(int a0);
extern void func_0216D2AC(u32 x);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162458(u8 *p);
extern void func_02162438(int a0, int a1, int a2);
extern void *func_020127A4(struct SaveBlock *p);
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void func_020141E0(const struct Rec020141E0 *p, struct Vec020141E0 *out);
extern void func_020141F0(struct Rec020141F0 *p, const struct Vec020141F0 *v);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern void func_021AA8EC(u8 *p);
extern void func_0216DF1C(u32 a);
extern void func_021623DC(char *p);
extern void func_0216242C(void *a0, u16 a1, u8 a2);
extern void func_021643AC(void *a, void *b);
extern void func_021BC550(void *p, int v);
extern void func_0202735C(u32 a0, u32 a1);
extern void func_0215A014(void *a, int b);
extern void func_02158AE0(void *a0, void *a1);
extern void func_0215874C(void *a);
u16 func_02162744(u8 *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_02162740(u8 *p);
void func_0216CEAC(u32 a, u8 *p, u32 b, u32 n, u32 c);
extern u32 func_02012134(u32 *p);
extern void func_0202B544(u32 a, u16 b);
extern void func_02029CF0(void *a, void *b, u16 c);
int func_0202C83C(int a0, int a1);
void func_021A1BDC(int x, int k);
void func_021A0358(int a);
extern struct Rec44 *func_02012AC4(struct Rec44 *p, u16 v);
unsigned short func_02013BD0(unsigned short id);
void func_0218F14C(u8 *p, u32 a, u32 b);
void func_0218F134(u8 *a);
extern int func_02013DD0(int v);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern u8 *func_020127C4(void *p);
extern u8 *func_020127D0(u8 *o, u32 idx);
extern int func_0218DC74(u32 a, u32 b, u32 c);
extern void *func_0218DC70(u8 *p);
extern void func_021939C0(u8 *o, void *dst, int skip, u32 heap);
extern void func_02193ABC(char *p, int a, int b);
extern void func_02193AFC(u8 *p, u32 v);
extern int func_02013FA8(u16 id);
extern int func_02013C80(int a0);
extern void func_021AB650(void *p);
extern void func_021AB868(void *p);
extern void func_021AB840(void *p, int a, int b, int c);
extern u32 func_021AB880(u8 *p);
extern u32 func_021AB884(u8 *p);
extern int func_021AB888(void *p);
extern void func_021AB634(void *p, int a, int b, int c);
extern u32 func_0200FB24(void);
extern u32 func_0202647C(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_0218CC64(char *p, int a, int m);
extern void func_021A0170(u8 *p, u32 a1, u32 a2, u32 a3);
extern void func_021A0568(u8 *p, int force);
extern void func_0219047C(u8 *p);
extern void func_021C7FB4(u32 a);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern u32 func_0206A854(void);
extern void func_021ABE0C(u32 a);
extern void func_021C64E0(u32 a);
extern void func_02050790(struct tagLISTCB *list, int b, int c);
extern void func_0217F928(char *p);
extern void func_021BB954(u8 *p);
extern void func_021A1B38(u32 *p);
extern void func_021BE4F8(char *p);
extern void func_021C1AEC(void);
extern void func_021C1C4C(char *p);
void func_021CF520(int h);
extern u32 func_020113D8(u32);
extern u8 *func_0218ED3C(u8 *p);
extern u8 func_02013BA8(u32 id);
extern u32 func_02013B50(u32 id);
extern unsigned short func_02159BF4(struct Obj *p);
extern unsigned short func_02159BF8(struct Obj *p);
extern int func_02159BFC(struct Obj *p);
extern char *func_02159C20(char *p);
extern u16 func_020140BC(struct Sub020140BCObj *p);
extern u32 func_020140C0(struct Sub020140BCObj *p);
extern u32 func_020140CC(struct Sub020140BCObj *p);
int func_02187F00(struct Obj0203159C *a, int *state, int b);
int func_02187FD0(u32 a, u32 b, u32 c, u32 d);
int func_02187FE8(int a, int unused, int b, int *c);
void *func_02188030(int a, int b);
void func_021880A4(int *p);
int func_021880C8(int unused, u8 *p);
int func_021881D8(int a, char *p);
int func_021885E8(void *a, u8 *p);
int func_02188758(void *a, u8 *p);
void func_021888C8(char *o);
u32 func_02188910(void *a, u8 *b);
int func_02188990(void *a, u8 *p);
u32 func_02188AD4(void *a, u8 *b);
u32 func_02188B58(void *a, u8 *b, u32 a2, u32 a3);
void func_02188BD8(u8 *obj);
int func_02188BE8(void *a);
u32 func_02188BF8(u8 *a);
u32 func_02188C54(u8 *p);
void *func_02188C58(void *p);
u32 func_02188C5C(u8 *p);
u32 func_02188C60(u8 *p);
u32 func_02188C64(u8 *p);
u32 func_02188C68(u8 *p);
u32 func_02188C6C(u8 *p);
int func_02188C70(int *p, int b);
void *func_02188C7C(u8 *p);
void *func_02188C80(void *p);
u16 func_02188C84(u8 *p);
u32 func_02188C88(u8 *p);
u32 func_02188C90(u8 *p);
u32 func_02188C98(u8 *p);
u16 func_02188C9C(u8 *p);
u32 func_02188CA4(u8 *p);
void func_02188CAC(u8 *p, u32 v);
void *func_02188CB4(struct Obj00020 *p);
int func_02188CBC(u32 a);
u32 func_02188CCC(u8 *p);
u32 func_02188CD0(u8 *p);
u32 func_02188CD8(u8 *p);
u32 func_02188CE0(u8 *p);
u32 func_02188CE8(u8 *p);
int func_02188CF0(u32 a);
u32 func_02188CFC(u8 *p);
u32 func_02188D20(u8 *p);
u32 func_02188D24(u8 *p);
int func_02188D2C(int *p);
u32 func_02188D30(u8 *p);
u32 func_02188D38(u8 *p);
void func_02188D40(u8 *p, u32 v);
u32 func_02188D48(u8 *p);
void func_02188D4C(u8 *p, u32 v);
void *func_02188D50(u8 *p);
u32 func_02188D58(u8 *p);
void func_02188D5C(u16 *p);
void func_02188DA0(void);
void func_02188DB0(u8 *a);
void func_02188DF0(u8 *a);
u32 func_02188E30(u8 *p);
int func_02188E38(u32 a);
void func_02188E50(void);
void func_02188EE4(u8 *p);
void func_02189004(u8 *a);
void func_02189084(unsigned char *p);
void func_021890AC(unsigned char *p);
int func_021890C8(u32 a);
void func_02189108(int unused, unsigned char *p);
void func_02189140(int x, int b, void *c, int d);
void func_02189154(void *a, u32 b);
void func_021891C0(u8 *a);
void func_02189204(u8 *a);
int func_021892B4(u8 *a);
u32 func_021892CC(u8 *a);
int func_0218932C(char *p);
u32 func_02189370(char *p);
void func_021893C0(u8 *p);
void func_021894E0(int a, int b, int c, int d);
void func_02189518(char *p, unsigned int idx);
void func_02189560(int *p, int b);
void func_0218958C(unsigned char *p, int id);
int func_021895BC(void *a, u32 b);
void func_021895D0(u8 *p, u32 a);
int func_021895DC(u32 a);
void func_021895E8(unsigned char *p, int id, int c);
void func_02189614(void *p, char *q, u16 id);
void func_02189684(char *p, unsigned int id);
int func_021896F4(void *p);
int func_02189734(u32 a, u32 b, u32 c, u32 d);
void func_02189758(int *p);
void *func_02189764(unsigned char *p, int id, int a, int b);
void func_021897A0(unsigned char *p, int id);
int *func_021897BC(char *p, int idx);
int func_021897DC(u32 a, u32 b, u32 c, u32 d);
void func_02189810(u8 *p);
void func_02189998(unsigned char *p);
void func_021899C4(unsigned char *p);
u32 func_021899F0(u8 *p);
void func_021899F8(u8 *p, u32 v);
void *func_02189A00(u8 *p);
int func_02189A08(unsigned char *p);
void *func_02189A10(Obj *p);
u32 func_02189A18(u8 *p);
void func_02189A1C(u8 *p, u32 v);
u32 func_02189A24(u8 *p);
int func_02189A2C(int *a);
int func_02189A38(int a);
int func_02189A48(char *p);
void func_02189A50(char *p, int v);
void func_02189A58(u8 *p, u32 v);
u8 *func_02189A60(u8 *p);
void func_02189A68(char *a, int b);
u32 func_02189A70(u8 *p);
u32 func_02189A78(u8 *p);
int func_02189A80(char *p);
int func_02189ACC(u32 a0);
int func_02189AE8(int a);
int func_02189B04(int x);
u32 func_02189B28(u32 id);
void func_02189B30(int a, int x, char *out, void *obj);
int func_02189BA8(int x);
extern char d_021DE700[];
extern char d_021DD9C0[];
extern u8 d_021D3688[];
extern u8 d_021D3604[];
extern u8 abs_id_19[];
extern u8 abs_id_18[];
extern int d_021D8F00;
extern int d_021D8F10[];
extern u8 abs_id_13[];
extern u8 abs_id_12[];
extern Fn data_021D36B8[][2];
extern const u8 data_021D35A8[];
extern u16 d_021D3620[];
extern u8 data_021D3640[];
extern u8 data_021D35E4[];
extern const s16 d_020A1EB8[];
extern const Vec12 d_021D36F4;
extern const Vec12 d_021D36E8;
extern Vec12 d_021D35C0;
extern Vec12 d_021D35CC;
extern u8 d_021D35AC[];
extern Fn_02189084 d_021D35D8[];
extern Fn_021890AC d_021D35B4[];
extern u8 data_021EE700[];
extern u16 data_021EE700b[];
extern MtxFx44 g_02148B54;
extern struct Glb g_02148BCC;
extern short d_020A1B38[];
extern Ent d_021D3700[];
extern struct _anon_Ent d_021D373C[];






int func_02187F00(struct Obj0203159C *a, int *state, int b)
{
    switch (*state) {
    case 0:
        {
            int sz = func_02189BBC(func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)b))) - 0xD000;
            func_0203064C(1, 0x15, sz);
        }
        func_0203064C(1, 0x70, 0xD000);
        func_0203064C(0x15, 0x50, 0xC000);
        func_02030678(d_021DE700, 0x10000, 0x89);
        func_0203064C(0x89, 0x92, 0x6400);
        func_0203064C(0x89, 0x93, 0x7400);
        func_0203064C(0x89, 0x96, 0x500);
        {
            void **w = (void **)func_0203159C(a, 4, 0x15);
            void *p = func_02188030(b, 0x15);
            *w = p;
            func_02012110((void *)b, p);
        }
        (*state)++;
        break;
    case 1:
        if (func_0201214C((const struct Ctx *)b) == 0) {
            int t = func_02012138((const struct Ctx *)b);
            switch (func_02026454((void *)t)) {
            case 1:
            case 2:
                func_02026400((struct Comm *)t);
                break;
            }
        }
        return 1;
    }
    return 0;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02187FD0(u32 a, u32 b, u32 c, u32 d)
{
if (func_02188B58((void *)c, (u8 *)(((struct Obj17856 *)((u8 *)(d)))->f0), c, d) == 1) {
    return 1;
}
return 0;
}






int func_02187FE8(int a, int unused, int b, int *c)
{
    func_021880A4((int *)(*c));
    func_02012110((void *)b, 0);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x96);
    func_020306F0(0x92);
    func_020306F0(0x93);
    func_020306F0(0x89);
    func_020306F0(0x50);
    func_020306F0(0x70);
    func_020306F0(0x15);
    return 1;
}






void *func_02188030(int a, int b)
{
    char *p = (char *)func_02030734(b, 0x154, 1, d_021DD9C0, 0x209);

    ((struct Obj03102 *)p)->f0 = b;
    ((struct Obj03102 *)p)->fC0 = 0;
    ((struct Obj03102 *)p)->f4 = a;
    ((struct Obj03102 *)p)->f8 = (int)func_020120F4((const struct Ctx *)a);
    ((struct Obj03102 *)p)->fD0 = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    {
        int r7 = func_02013B38(((struct Obj03102 *)p)->fD0);
        ((struct Obj03102 *)p)->fC = func_0201407C(b, r7, func_0202E83C((void *)a));
    }
    ((struct Obj03102 *)p)->f108 = func_02189BA8(((struct Obj03102 *)p)->fD0);
    return p;
}






void func_021880A4(int *p)
{
    int q = p[1];
    func_020140B4((void *)p[3]);
    func_020307B0(p);
    func_02012110((void *)q, 0);
    func_020371AC(0, 0);
}










int func_021880C8(int unused, u8 *p)
{
    u16 heap = ((struct Obj01489 *)p)->f0;

    func_020433E0((const struct DispVram *)d_021D3688);
    func_02188D5C((u16 *)p);
    func_0204A48C((const struct Cfg *)d_021D3604, (u32)d_021D3688, 0x89);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02045088(heap);
    func_0201DD60();
    func_02046440(0, 3, 0, 1, 0x1000, ((struct Obj01489 *)p)->f0, func_02188E50);
    func_02188EE4(p);
    *(char * *)&((struct Obj01489 *)p)->f48 = func_0218C9E8(((struct Obj01489 *)p)->f0, func_02012984((const struct BigObj *)(((struct Obj01489 *)p)->f8)));
    ((struct Obj01489 *)p)->fAC = func_020056A0(func_02189108, p, 0);
    ((struct Obj01489 *)p)->f114 = func_02030734(heap, func_02030CB0(0x20), 0, d_021DD9C0, 0x26B);
    ((struct Obj01489 *)p)->f110 = func_02030CBC(0x20, ((struct Obj01489 *)p)->f114);
    *(u8 * *)&((struct Obj01489 *)p)->f134 = func_021C6D10(0xA, ((struct Obj01489 *)p)->f0);
    ((struct Obj01489 *)p)->f14C = func_021D317C(((struct Obj01489 *)p)->f0);
    func_02034AC4((func_02013CC8(((struct Obj01489 *)p)->fD0) == 1 || func_02013CE0(((struct Obj01489 *)p)->fD0) == 1) ? (int)abs_id_19 : (int)abs_id_18);
    func_02035660(0x1E);
    return 1;
}










int func_021881D8(int a, char *p)
{
    int sys = (int)func_020120F4((const struct Ctx *)a);
    int flag = 1;

    switch (((struct Obj00571 *)p)->fC8) {
    case 0: {
        int x;
        func_0216447C(sys, F16(0xd0));
        x = (int)func_021901EC(F16(0), F32(0xa4));
        F32(0x2c) = 0;
        F32(0x28) = x;
        F32(0x30) = func_021BC388(a, 0x93, x);
        F32(0xa0) = func_021C7F70(func_02014470(func_02012B38((const struct BigObj *)F32(8))), F16(0));
        F32(0x10) = (int)func_0218E018(func_02013BBC(F16(0xd0)), 0, (struct Light *)F32(0xa4), (int)(p + 0xf4), F16(0));
        F32(0x40) = func_021AB5F4(F16(0), F32(0x10), p);
        F32(0x44) = func_021AB7E4(F16(0));
        break;
    }
    case 1: {
        int m;
        int t;
        F32(0x3c) = (int)func_021BB1F4(F16(0), F32(0x10), F32(0x40), F32(0x44));
        F32(0x9c) = (int)func_021D33A8(F16(0), (void *)a, p, F16(0xd0));
        m = func_0218DC6C((u8 *)F32(0x48));
        func_02189B30(F16(0xd0), F32(0xc), p + 0x50, (void *)func_02012974((const struct BigObj *)F32(8)));
        func_02012138((const struct Ctx *)F32(4));
        t = (int)func_021D33F8((u32 *)F32(0x9c));
        func_0218B8AC((char *)m, F16(0xd0), F32(0xc), t);
        func_021C6534((u32 *)F32(0x130), t);
        func_02189614((void *)sys, p, F16(0xd0));
        break;
    }
    case 2: {
        int v;
        func_02014110(p + 0xd4, F16(0xd0), 0, 0, 0, F32(0xf4), F32(0xf8), F32(0xfc));
        func_02012138((const struct Ctx *)F32(4));
        func_0218CEE4((struct Obj *)F32(0x48), (const struct Src *)(p + 0x50), func_021D33F8((u32 *)F32(0x9c)));
        v = func_02013C9C(F16(0xd0));
        if (v != -1) {
            func_021BB2F8(F32(0x3c), v, F16(0));
        }
        F32(0x104) = func_02189ACC(F16(0xd0));
        func_021895E8((unsigned char *)p, (u16)F16(0xd0), (u16)F16(0));
        break;
    }
    case 3:
        func_02189204((u8 *)p);
        F32(0x94) = (int)func_021ABD50((int)p, 0x18, F16(0));
        func_021ABF68(F32(0x94), 0x5e);
        func_021AC1EC((u32 *)F32(0x94), (u32)func_021D33F8((u32 *)F32(0x9c)));
        func_021ABE30(F32(0x94), d_021D8F10, d_021D8F00);
        if (func_02013CC8(F16(0xd0)) == 1 || func_02013CE0(F16(0xd0)) == 1) {
            F32(0x98) = (int)func_0217F8C0(F16(0));
        }
        break;
    case 4: {
        int w;
        int k;
        V3 *pos;
        int r;
        int g;
        w = (int)func_020120F8((const struct Ctx *)a);
        k = func_02012AE4((const struct Rec44 *)w);
        pos = (V3 *)(w + 4);
        if (func_02012B28((const struct Rec44 *)w) == 1 && func_02013C20(F16(0xd0)) == 0) {
            func_02012B2C((struct Rec44 *)w, 0);
        }
        F32(0x8c) = (int)func_021A2E50(w, (u32)p, (int)pos, func_02008550((const struct Sub0200852CObj *)func_02012944((void *)sys)), F16(0));
        *(V3 *)(p + 0xf4) = *pos;
        (*(Ops **)(p + 0x108))->f4(p, (V3 *)(p + 0xf4), k);
        func_0218D158((struct T *)F32(0x48), (const struct V3 *)(p + 0xf4));
        func_02189758((int *)(p + 0x118));
        F32(0x34) = func_021BE2A8(0x3c, 0x23, F16(0));
        func_02189154((void *)F32(0xc), (int)func_02188C9C((u8 *)p));
        F32(0x18) = (int)func_021A0104(F16(0));
        F32(0x1c) = (int)func_021A02C4(F16(0));
        r = func_02013EEC(F16(0xd0));
        func_021A0338((u8 *)F32(0x1c), r, func_02013F2C(F16(0xd0)), 1);
        r = func_020140DC((struct Sub020140BCObj *)F32(0xc));
        g = func_0203F4FC();
        F32(0x14) = (int)func_021A03D0(r, g, func_0202E83C((void *)a), F32(0x18), F32(0xa8), F16(0));
        r = func_02012A30((const struct BigObj *)F32(8));
        F32(0x20) = func_021A19E8(F32(0x10), F32(0x14), F32(0x18), F32(0x1c), r, func_0202E83C((void *)a), 0x92);
        func_021A1B74((u8 *)F32(0x20), (u16)((int)func_02012994((const struct BigObj *)F32(8))), 0x92);
        func_021BE1DC(p);
        break;
    }
    case 5:
        F32(0x24) = (int)func_021A0CF4(F16(0), (u32)p, func_020129AC((const struct BigObj *)sys));
        break;
    case 6:
        F32(0x90) = (int)func_021A9ED8((u32)p);
        func_02026388((struct Obj *)func_02012138((const struct Ctx *)a), (u32)p);
        F32(0xbc) = (int)func_021BB890((int)p, F16(0), 0x20);
        F32(0x120) = (int)func_021C1A08(0x50);
        F32(0x124) = (int)func_021C1AF4(0x50, F32(0x120));
        F32(0x13c) = (int)func_021CF45C(F16(0), (u32)p);
        F32(0x128) = func_021C31D4(F16(0), p, (int)func_0200BDB0(func_02012EBC((struct Big *)F32(8))));
        func_02189684(p, F16(0xd0));
        flag = 0;
        break;
    }
    (((struct Obj00571 *)p)->fC8)++;
    F32(0x12c) = 0;
    return flag == 0;
}










/*
 * Addresses are Black-image addresses.
 */
int func_021885E8(void *a, u8 *p)
{
    switch (p[0xC8]) {
    case 0:
        func_0218CA78((char *)(((struct Obj00611 *)p)->f48));
        if (((struct Obj00611 *)p)->f38 != 0) {
            do {
                func_0216CD64(((struct Obj00611 *)p)->f38);
                func_0219C624((void *)(((struct Obj00611 *)p)->f38));
            } while (func_0219C630((void *)(((struct Obj00611 *)p)->f38)) == 1);
        }
        while (func_021A1B50(((struct Obj00611 *)p)->f20) != 0)
            func_021A1AF4((u8 *)(((struct Obj00611 *)p)->f20), 0x92);
        func_02189004(p);
        func_02189084(p);
        func_021890AC(p);
        func_0204A600();
        if (((struct Obj00611 *)p)->f28 != 0)
            func_021903E0((struct Obj *)(((struct Obj00611 *)p)->f28));
        func_021ABE04(((struct Obj00611 *)p)->f94);
        func_021BB948((u8 *)(((struct Obj00611 *)p)->fBC));
        p[0xC8]++;
    case 1:
        if (func_02014460(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8))) == 1
            && func_02189B04(((struct Obj00611 *)p)->fD0) == 1
            && func_02005C64() != 0)
            return 0;
        if (func_02014458(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8))) != 0) {
            func_02158AC8(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
            func_02014454(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        } else {
            func_02158AD4(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
        }
        func_0201445C(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        func_0218CA78((char *)(((struct Obj00611 *)p)->f48));
        if (func_02013CC8(((struct Obj00611 *)p)->fD0) == 1 || func_02013CE0(((struct Obj00611 *)p)->fD0) == 1)
            func_0201209C(a, (u32)func_0218A0E4, (u32)p);
        else if (func_02188CF0((u32)p) == 1)
            func_0201209C(a, (u32)func_0218A240, (u32)p);
        else if (func_02188CF0((u32)p) == 2)
            func_0201209C(a, (u32)func_0218A4BC, (u32)p);
        else
            func_0201209C(a, (u32)func_0218A074, (u32)p);
        ((struct Obj00611 *)p)->fC0 = 1;
        func_020129DC(func_020120F4(a), 1);
        break;
    }
    return 1;
}










int func_02188758(void *a, u8 *p)
{
    if (func_02012104((const struct Ctx *)(((struct Obj00518 *)p)->f4)) == 0)
        func_0201447C(func_02012B38((const struct BigObj *)(((struct Obj00518 *)p)->f8)), 0);
    if (func_02012E40((const u8 *)(((struct Obj00518 *)p)->f8)) != 0)
        return 0;
    if (((struct Obj00518 *)p)->f140 != 0) {
        func_021888C8((char *)p);
        func_0204A600();
        return 0;
    }
    func_02035648();
    func_021892CC(p);
    if (func_020120D8(a) == 0) {
        (*(void (**)(u8 *, void *))(*(u8 **)(p + 0x108) + 8))(p, p + 0xF4);
        func_02168EEC(((struct Obj00518 *)p)->f8);
    }
    if (((struct Obj00518 *)p)->f30 != 0)
        func_021BC484(((struct Obj00518 *)p)->f30);
    func_021C7FAC(((struct Obj00518 *)p)->fA0);
    func_021A2EB8((u32 *)(((struct Obj00518 *)p)->f8C));
    if (func_02013CC8(((struct Obj00518 *)p)->fD0) == 1 || func_02013CE0(((struct Obj00518 *)p)->fD0) == 1)
        func_021737A4((void *)((void *)func_02012138(a)), (int)p);
    else
        func_0217AE20((u8 *)p, ((struct Obj00518 *)p)->f4, ((struct Obj00518 *)p)->f8C);
    func_021A0D68((u32 *)(((struct Obj00518 *)p)->f24));
    if (((struct Obj00518 *)p)->f38 != 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_0216CD64(((struct Obj00518 *)p)->f38);
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    func_021BE258(p);
    func_021ABE04(((struct Obj00518 *)p)->f94);
    if (((struct Obj00518 *)p)->f98 != 0)
        func_0217F914(((struct Obj00518 *)p)->f98);
    func_021BB948((u8 *)(((struct Obj00518 *)p)->fBC));
    if (((struct Obj00518 *)p)->f28 != 0)
        func_021903E0((struct Obj *)(((struct Obj00518 *)p)->f28));
    func_02030D28((struct Ctx *)(((struct Obj00518 *)p)->f110));
    func_021C6D90((u8 *)(((struct Obj00518 *)p)->f134));
    if (*(Rec12 * *)&((struct Obj00518 *)p)->fF0 != 0)
        *(Rec12 *)(p + 0xF4) = **(Rec12 * *)&((struct Obj00518 *)p)->fF0;
    func_0218D158((struct T *)(((struct Obj00518 *)p)->f48), (const struct V3 *)(p + 0xF4));
    func_02189004(p);
    func_021C8660(*func_02012ED0(((struct Obj00518 *)p)->f8));
    func_0204A600();
    func_021888C8((char *)p);
    return 0;
}










void func_021888C8(char *o)
{
    volatile u16 *r = (volatile u16 *)0x04000204;

    func_02047CE4();
    func_0218E104((u8 *)(((struct Obj12555 *)o)->f10), (u16)func_0203630C());
    ((struct Obj12555 *)o)->f100 = func_02189A80(o);
    *r = *r & 0xFFFF7FFF;
    func_02189084((unsigned char *)o);
    *r = *r | 0x8000;
}










u32 func_02188910(void *a, u8 *b)
{
    if (func_02012E40((const u8 *)(((struct Obj04193 *)b)->f8)) != 0) {
        func_020129F0(func_020120F4(a));
        return 0;
    }
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0218CC34(((struct Obj04193 *)b)->f48);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021A0E58((u32 *)(((struct Obj04193 *)b)->f24));
    if (((struct Obj04193 *)b)->f28 != 0)
        func_021903E0((struct Obj *)((struct Obj04193 *)b)->f28);
    if (((struct Obj04193 *)b)->f30 != 0)
        func_021BC4F0((int)((struct Obj04193 *)b)->f30);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021890AC(b);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_020129F0(func_020120F4(a));
    return 0;
}










int func_02188990(void *a, u8 *p)
{
    func_021CF480((void *)(((struct Obj00401 *)p)->f13C));
    func_021C1C04((u32 *)(((struct Obj00401 *)p)->f124));
    func_021C1AD0(((struct Obj00401 *)p)->f120);
    func_0201209C(a, 0, 0);
    func_021A2EB8((u32 *)(((struct Obj00401 *)p)->f8C));
    func_021BB90C(((struct Obj00401 *)p)->fBC);
    func_020263B0((void *)func_02012138(a), (u32)p);
    if (((struct Obj00401 *)p)->f30 != 0)
        func_021BC424(((struct Obj00401 *)p)->f30);
    func_021BE218(p);
    func_021BE2E0(((struct Obj00401 *)p)->f34);
    func_021A9F28(((struct Obj00401 *)p)->f90);
    func_020129B8(func_020120F4(a), func_021A0D44((u32 *)(((struct Obj00401 *)p)->f24)));
    func_021ABDE8(((struct Obj00401 *)p)->f94);
    if (((struct Obj00401 *)p)->f98 != 0) {
        func_0217F8EC((char *)(((struct Obj00401 *)p)->f98));
        ((struct Obj00401 *)p)->f98 = 0;
    }
    func_021A1AAC((u8 *)(((struct Obj00401 *)p)->f20));
    ((struct Obj00401 *)p)->f20 = 0;
    func_021A0448((u8 *)(((struct Obj00401 *)p)->f14));
    func_021A02F4((void *)(((struct Obj00401 *)p)->f1C));
    func_021A0138(((struct Obj00401 *)p)->f18);
    func_021D33E0((u32 *)(((struct Obj00401 *)p)->f9C));
    func_021BB240(((struct Obj00401 *)p)->f3C);
    func_021AB81C(((struct Obj00401 *)p)->f44);
    func_021AB624((u8 *)(((struct Obj00401 *)p)->f40));
    func_0218E0E4((u8 *)(((struct Obj00401 *)p)->f10));
    (*(void (**)(u8 *))(*(u8 **)(p + 0x108) + 0xC))(p);
    func_021895DC((u32)p);
    func_021892B4(p);
    func_021A2E90((void *)(((struct Obj00401 *)p)->f8C));
    func_0218D05C((char *)(((struct Obj00401 *)p)->f48));
    if (((struct Obj00401 *)p)->f2C != 0)
        func_02190728((void *)(((struct Obj00401 *)p)->f2C));
    if (((struct Obj00401 *)p)->f28 != 0)
        func_021902BC((struct Obj *)(((struct Obj00401 *)p)->f28));
    func_020129DC(func_020120F4(a), 0);
    func_02035660(0x3C);
    func_021C31FC(((struct Obj00401 *)p)->f128);
    func_021C7F9C((u8 *)(((struct Obj00401 *)p)->fA0));
    return 1;
}










u32 func_02188AD4(void *a, u8 *b)
{
    func_02030DA4(((struct Obj03103 *)b)->f110);
    func_020307B0((void *)(((struct Obj03103 *)b)->f114));
    func_021D31A4(((struct Obj03103 *)b)->f14C);
    ((struct Obj03103 *)b)->f14C = 0;
    func_021C6D5C(((struct Obj03103 *)b)->f134);
    func_02030EAC((struct Node *)(((struct Obj03103 *)b)->fAC));
    func_0218CA4C((void *)(((struct Obj03103 *)b)->f48));
    func_021890C8((u32)b);
    func_0204A5AC();
    func_020450C8();
    func_02188E38((u32)b);
    if (func_02013CC8(((struct Obj03103 *)b)->fD0) == 1 || func_02013CE0(((struct Obj03103 *)b)->fD0) == 1)
        func_02034A5C((s32)abs_id_13);
    else
        func_02034A5C((s32)abs_id_12);
    return 2;
}










u32 func_02188B58(void *a, u8 *b, u32 a2, u32 a3)
{
    u32 c = ((struct Obj02685 *)b)->fCC;
    s32 r = 0;
    Fn f;
    Fn *row;

    ((struct Obj02685 *)b)->fCC = c + 1;
    row = data_021D36B8[((struct Obj02685 *)b)->fC4];
    f = row[b[0xC9]];
    if (f != 0)
        r = f(a, b);
    switch (r) {
    case 0:
        b[0xC9] = (b[0xC9] == 0);
        break;
    case 1:
        ((struct Obj02685 *)b)->fC4 = ((struct Obj02685 *)b)->fC4 + 1;
        b[0xC8] = 0;
        b[0xC9] = 0;
        break;
    case 2:
        return 1;
    }
    return 0;
}









/*
 * Sets the two words at +0xC0 and +0xC4 of its argument to 2 and 4.  A leaf
 * with no lr-saving prologue that nothing in ov021 branches to (its caller
 * is sub_02014488 in arm9), so the listing emits it as data words after
 * pool_02188BD4.
 */
void func_02188BD8(u8 *obj)
{
    ((struct Obj12061 *)obj)->fC0 = 2;
    ((struct Obj12061 *)obj)->fC4 = 4;
}









int func_02188BE8(void *a)
{
if (((struct Obj17857 *)a)->fC0 == 1) {
    return 1;
}
return 0;
}









u32 func_02188BF8(u8 *a)
{
    u32 r = 0;
    u32 t = func_021A3098((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C));

    if (t == 1) {
        r = 1;
        func_021A2F48((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C), 1);
    } else if (t == 0) {
        r = 1;
        func_020061E4(0x55F);
        func_021A2F48((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C), 2);
        func_02008DF0(func_02012F2C((int *)(*(u32 *)&((struct Obj00020 *)a)->f8)), 3);
    }
    if (r == 1)
        func_021A2F54((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C));
    return r;
}









/*
 * Loads the 32-bit word at byte +0x28 of the object.
 */
u32 func_02188C54(u8 *p)
{
    return ((struct Obj17858 *)p)->f28;
}









/*
 * Loads the 32-bit word at byte +0x10 of the object.
 */
void *func_02188C58(void *p)
{
    return ((struct Obj00020 *)p)->f10;
}









/*
 * Loads the 32-bit word at byte +0x3c of the object.
 */
u32 func_02188C5C(u8 *p)
{
    return ((struct Obj17859 *)p)->f3C;
}









/*
 * Unlabelled leaf getter: the word at +0x14.
 * Addresses are Black-image addresses.
 */
u32 func_02188C60(u8 *p)
{
    return ((struct Obj19487 *)p)->f14;
}









/*
 * Unlabelled leaf accessor: returns the +0x18 member.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02188C64(u8 *p)
{
    return ((struct Obj19488 *)p)->f18;
}









/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
u32 func_02188C68(u8 *p)
{
    return ((struct Obj17860 *)p)->f1C;
}









/*
 * Loads the 32-bit word at byte +0x20 of the object.
 */
u32 func_02188C6C(u8 *p)
{
    return ((struct Obj17861 *)p)->f20;
}









/*
 * Unlabelled tail-call leaf (no lr saved): forwards p[1] and the second argument.
 */
int func_02188C70(int *p, int b)
{
    return func_0202C794((void *)p[1], b);
}









/*
 * Loads the 32-bit word at byte +0x38 of the object.
 */
void *func_02188C7C(u8 *p)
{
    return ((struct Obj00020 *)p)->f38;
}









/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
void *func_02188C80(void *p)
{
    return ((struct Obj00020 *)p)->f4;
}









/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02188C84(u8 *p)
{
    return ((struct Obj17862 *)p)->f0;
}









u32 func_02188C88(u8 *p)
{
    return ((struct Obj17863 *)p)->fB4;
}








/*
 * Loads the 32-bit word at byte +0xb8 of the object.
 */
u32 func_02188C90(u8 *p)
{
    return ((struct Obj17864 *)p)->fB8;
}








/*
 * Loads the 32-bit word at byte +0x48 of the object.
 */
u32 func_02188C98(u8 *p)
{
    return ((struct Obj17865 *)p)->f48;
}








/*
 * Loads the halfword at byte +0xd8 of the object.
 */
u16 func_02188C9C(u8 *p)
{
    return ((struct Obj17866 *)p)->fD8;
}








/*
 * Loads the 32-bit word at byte +0x10c of the object.
 */
u32 func_02188CA4(u8 *p)
{
    return ((struct Obj17867 *)p)->f10C;
}








/*
 * Stores the 32-bit word into byte +0x10c of the object.
 */
void func_02188CAC(u8 *p, u32 v)
{
    ((struct Obj17868 *)p)->f10C = v;
}








/*
 * Loads the 32-bit word at byte +0x8c of the object.
 */
void *func_02188CB4(struct Obj00020 *p)
{
    return p->f8C;
}








int func_02188CBC(u32 a)
{
if (*(u32 *)((u8 *)((a + 140))) != 0) {
    return 1;
}
return 0;
}








/*
 * Loads the 32-bit word at byte +0x24 of the object.
 */
u32 func_02188CCC(u8 *p)
{
    return ((struct Obj17870 *)p)->f24;
}








/*
 * Loads the 32-bit word at byte +0x94 of the object.
 */
u32 func_02188CD0(u8 *p)
{
    return ((struct Obj17871 *)p)->f94;
}








/*
 * Unlabelled leaf getter at +0x130.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02188CD8(u8 *p)
{
    return ((struct Obj17872 *)p)->f130;
}








/*
 * Unlabelled leaf getter at +0x98 (between func_02188CD8 and
 * func_02188CE8); sole blocker of ov019 func_0217B264's call.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02188CE0(u8 *p)
{
    return ((struct Obj19490 *)p)->f98;
}








/*
 * Loads the 32-bit word at byte +0x90 of the object.
 */
u32 func_02188CE8(u8 *p)
{
    return ((struct Obj17873 *)p)->f90;
}








int func_02188CF0(u32 a)
{
return *(u32 *)((u8 *)(*(u32 *)((u8 *)(a) + ((66 << 2)))));
}








u32 func_02188CFC(u8 *p)
{
    u32 r;
    u32 k = data_021D35A8[**(u32 * *)&((struct Obj00020 *)p)->f108];

    if (k == 2)
        k = func_021A6DC0(((struct Obj00020 *)p)->f10C);
    r = k;
    return r;
}








/*
 * Loads the 32-bit word at byte +0x30 of the object.
 */
u32 func_02188D20(u8 *p)
{
    return ((struct Obj17875 *)p)->f30;
}







/*
 * Loads the 32-bit word at byte +0xbc of the object.
 */
u32 func_02188D24(u8 *p)
{
    return ((struct Obj17876 *)p)->fBC;
}







/*
 * Unlabelled ov021 leaf accessor: returns the word at +0x34 of its argument.
 * Matched to supply the `matched` witness for the ten pending callers that
 * reference it.
 */
int func_02188D2C(int *p)
{
    return ((struct Obj17877 *)p)->f34;
}







/*
 * Loads the 32-bit word at byte +0x110 of the object.
 */
u32 func_02188D30(u8 *p)
{
    return ((struct Obj17878 *)p)->f110;
}







/*
 * Loads the 32-bit word at byte +0x134 of the object.
 */
u32 func_02188D38(u8 *p)
{
    return ((struct Obj17879 *)p)->f134;
}







/*
 * Field setter at +0xf0 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_02188D40(u8 *p, u32 v)
{
    ((struct Obj17880 *)p)->fF0 = v;
}







u32 func_02188D48(u8 *p)
{
    return ((struct Obj17881 *)p)->f2C;
}







/*
 * Field setter at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_02188D4C(u8 *p, u32 v)
{
    ((struct Obj17882 *)p)->f2C = v;
}






/*
 * Loads the 32-bit word at byte +0x128 of the object.
 */
void *func_02188D50(u8 *p)
{
    return ((struct Obj17883 *)p)->f128;
}






/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_02188D58(u8 *p)
{
    return ((struct Obj17884 *)p)->fC;
}






void func_02188D5C(u16 *p)
{
    func_0203F8F4(p[0]);
    func_02040E78(0, d_021D3620, 0x20, 0);
    func_02040E78(4, d_021D3620, 0x20, 0);
    func_0204363C(1);
    func_0204361C();
    REG_DISPCNT &= ~0xE000;
}






/*
 * Tail call with a fixed data pointer argument.
 *
 * Addresses are Black-image addresses.
 */
void func_02188DA0(void)
{
    func_0203FC28((struct DispConfig *)0x021D35F4);
}






void func_02188DB0(u8 *a)
{
    u32 buf[4];

    func_02051E74((struct Mtx22 *)buf, 0, (const void *)0x1000, (const void *)0x1000, 0);
    func_0207D59C(0x04000020, buf, 0, 0, 0, 0);
    func_0204044C(3);
    func_02190270(((struct Obj19493 *)a)->f28);
}






void func_02188DF0(u8 *a)
{
    u32 buf[4];

    func_02051E74((struct Mtx22 *)buf, 0, (const void *)0x1000, (const void *)0x1000, 0);
    func_0207D59C(0x04000020, buf, 0, 0, 0, 0);
    func_0204044C(3);
    func_0219027C((u8 *)(((struct Obj19494 *)a)->f28));
}






/*
 * Loads the 32-bit word at byte +0x14c of the object.
 */
u32 func_02188E30(u8 *p)
{
    return ((struct Obj17885 *)p)->f14C;
}






int func_02188E38(u32 a)
{
return func_0203F9B4(func_02046788(func_0206DB80(func_0204363C(1))));
}






void func_02188E50(void)
{
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xFFFFCFFD;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x10;
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFFB;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 8;
    func_0207DC44(0, 0, 5, 0xE00);
    *(volatile u32 *)0x04000358 = 0x7FFF;
    func_0207DD10(data_021D3640);
    func_0207DD24(0, 0x1F, 0x7FFF, 0, 0);
    func_0207DCF8(data_021D35E4);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u32 *)0x04000580 = 0xBFFF0000;
    func_02046BE0(1, 0);
}






void func_02188EE4(u8 *p)
{
    Vec12 v30;
    Vec12 v24;
    u8 v20;
    u8 *h;
    u16 heap;

    ((struct Obj01344 *)p)->fB0 = (u32)func_0204FE94(0x40, 0x80, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    h = (u8 *)func_02050080((u32 *)(((struct Obj01344 *)p)->fB0));
    func_0204EDBC(h, 2);
    func_0204EDC4(h, 0, -0xA00);
    ((struct Obj01344 *)p)->fB4 = (u32)func_0204FE94(0x3A, 0x50, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    ((struct Obj01344 *)p)->fB8 = (u32)func_0204FE94(0x1E, 0x28, (u32)func_02189140, ((struct Obj01344 *)p)->f0);
    h = (u8 *)func_02050080((u32 *)(((struct Obj01344 *)p)->fB8));
    v30 = d_021D36F4;
    func_0204ED70(h, (struct Blk3 *)(&v30));
    v20 = 0;
    func_0204EDB0(h, &v20);
    func_021891C0(p);
    ((struct Obj01344 *)p)->f130 = func_021C63AC(((struct Obj01344 *)p)->f0, 0x40, 0x40);
    heap = ((struct Obj01344 *)p)->f0;
    v24 = d_021D36E8;
    ((struct Obj01344 *)p)->fA4 = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                       &d_021D35C0, &v24, &d_021D35CC, heap);
    ((struct Obj01344 *)p)->fA8 = (u32)func_02048BC4((const struct LightSet *)d_021D35AC, ((struct Obj01344 *)p)->f0);
    func_02048AD0((struct Light *)(((struct Obj01344 *)p)->fA4));
    func_02048C58((struct LightSlot *)(((struct Obj01344 *)p)->fA8));
}






void func_02189004(u8 *a)
{
    u32 t;

    func_020504D8((struct Owner *)(((struct Obj02367 *)a)->fB0));
    func_020504D8((struct Owner *)(((struct Obj02367 *)a)->fB4));
    func_020504D8((struct Owner *)(((struct Obj02367 *)a)->fB8));
    func_021BB36C(((struct Obj02367 *)a)->f3C);
    func_021AB660((struct Obj *)(((struct Obj02367 *)a)->f40), a + 0xF4);
    func_021A030C((u8 *)(((struct Obj02367 *)a)->f1C), ((struct Obj02367 *)a)->f0);
    func_021A1AF4((u8 *)(((struct Obj02367 *)a)->f20), 0x92);
    func_021A0140((u8 *)(((struct Obj02367 *)a)->f18));
    func_021A0458((u8 *)(((struct Obj02367 *)a)->f14), func_0203F4FC());
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    t = func_0218CB34((char *)(((struct Obj02367 *)a)->f48));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    if (t != 0)
        func_0203D12C(2);
}






void func_02189084(unsigned char *p)
{
    Fn_02189084 fn;
    func_02047964();
    func_020479D8();
    fn = d_021D35D8[((struct Obj19495 *)p)->f12C];
    if (fn != 0)
        fn(p);
}






void func_021890AC(unsigned char *p)
{
    func_02047970(d_021D35B4[*(int *)(p + 0x12C)](p));
}






int func_021890C8(u32 a)
{
func_02048C4C(*(u32 *)((u8 *)((a + 168))));
func_02048AC4((void *)(*(u32 *)((u8 *)((a + 164)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 176)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 180)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 184)))));
return func_021C6400(*(u32 *)((u8 *)(a) + ((19 << 4))));
}






void func_02189108(int unused, unsigned char *p)
{
    if (func_02005C8C() == 0) {
        if (((struct Obj04980 *)p)->f38 != 0)
            func_0216CD78(((struct Obj04980 *)p)->f38);
        if (((struct Obj04980 *)p)->f130 != 0)
            func_021C6470(((struct Obj04980 *)p)->f130);
    }
    func_0204A648();
    if (((struct Obj04980 *)p)->f14C != 0)
        func_021D31AC(((struct Obj04980 *)p)->f14C);
}






/* Callback: forwards its last three arguments, with the first folded to 0/1. */
void func_02189140(int x, int b, void *c, int d)
{
    func_02061CA4((void *)(x == 0 ? B_FALSE : B_TRUE), b, (u32)c, d);
}






void func_02189154(void *a, u32 b)
{
    u32 r = func_020140E0(a);

    if (r == 0xFF) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
        return;
    }
    if (func_02013DB8(b) != 0)
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    else
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
    func_02048F4C(data_021EE700, 0xF, r);
    data_021EE700b[7] = 0x4210;
    func_0207DCF8(data_021EE700);
}






void func_021891C0(u8 *a)
{
    u16 v = (((struct Obj09442 *)a)->f0 & 0x7FFF) | 0x8000;
    u32 h;
    u32 t;

    t = func_020140E4((struct Sub020140BCObj *)(((struct Obj09442 *)a)->fC));
    h = func_021CD1C8(v);
    func_021CD204(h, t);
    func_021CD214((u8 *)h, (void *)func_02050080((u32 *)(((struct Obj09442 *)a)->fB0)));
    func_021CD1F0((void *)h);
}






void func_02189204(u8 *a)
{
    u32 h;
    u32 x;
    u32 r;
    u32 t;

    h = (u32)func_020120F4((const struct Ctx *)(((struct Obj00571 *)a)->f4));
    r = func_02012964((const struct BigObj *)h);
    ((struct Obj00571 *)a)->f38 = r;
    func_0216CCDC((char *)r, ((struct Obj00571 *)a)->f0, h, (int)a, *(u32 *)&((struct Obj00571 *)a)->f48, ((struct Obj00571 *)a)->f3C);
    func_0219C554(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->fB0, 0x20);
    func_0219C680(((struct Obj00571 *)a)->f38);
    x = ((struct Obj00571 *)a)->fD8;
    if (func_02013CC8(x) == 0 && func_02013CE0(x) == 0) {
        t = func_0217C0A8((void *)((void *)func_02012138((const struct Ctx *)((struct Obj00571 *)a)->f4)));
    } else {
        t = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)h));
    }
    func_0219C658(r, func_021A31A4(t, 0));
    func_0219D448(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->f130);
    func_0216CDB8((u8 *)(((struct Obj00571 *)a)->f38), (u32)func_0218ED50((u8 *)(((struct Obj00571 *)a)->f10)));
    func_0216D2F8(((struct Obj00571 *)a)->f38);
    func_0216D974((unsigned int *)r, func_02189AE8(((struct Obj00571 *)a)->fD0));
}






int func_021892B4(u8 *a)
{
func_0216D2AC(((struct Obj09172 *)((u8 *)(a)))->f38);
func_0216CD50(((struct Obj09172 *)((u8 *)(a)))->f38);
((struct Obj09172 *)((u8 *)(a)))->f38 = 0;
return 0;
}






u32 func_021892CC(u8 *a)
{
    u32 h;

    if (func_0218932C((char *)a) == 1 && func_02189370((char *)a) == 1) {
        func_021893C0(a);
        return 1;
    }
    h = func_02012844((const struct BigObj *)(((struct Obj09443 *)a)->f8));
    if (func_02162458((u8 *)h) == 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_02162438(h, ((struct Obj09443 *)a)->fD8, func_02012984((const struct BigObj *)(((struct Obj09443 *)a)->f8)));
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    return 0;
}






int func_0218932C(char *p)
{
    Vec_0218932C v;
    char *q;
    Vec_0218932C *pos;

    q = p + 0xd4;
    pos = (Vec_0218932C *)func_02012AA0(func_020127A4(func_020120F4(((struct Obj19496 *)p)->f4)));
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&v));
    if (pos->x != v.x || pos->z != v.z) {
        func_020141F0((struct Rec020141F0 *)q, (const struct Vec020141F0 *)pos);
        return 1;
    }
    return 0;
}






u32 func_02189370(char *p)
{
    Vec_02189370 v;
    char *q;
    void *m;
    int r;

    q = p + 0xd4;
    m = (void *)func_02012974(((struct Obj19497 *)p)->f8);
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&v));
    if (func_02159C48((int)m, v.x, v.z) == 1) {
        r = func_02159BD4((int)m, v.x, v.z);
        if (r != 0xFFFF && r != ((struct Obj05698 *)q)->f4)
            return 1;
    }
    return 0;
}






void func_021893C0(u8 *p)
{
    u8 *q = p + 0xD4;
    void *sys;
    u32 v;
    Vec_021893C0 pos;
    u32 s4;
    u32 s0;

    sys = func_020120F4((const struct Ctx *)(((struct Obj03104 *)p)->f4));
    s4 = func_02012844(sys);
    s0 = ((struct Obj03104 *)p)->f38;
    v = func_02012974((const struct BigObj *)(((struct Obj03104 *)p)->f8));
    func_0203D12C(2);
    func_021AA8EC((u8 *)(((struct Obj03104 *)p)->f90));
    func_020141E0((const struct Rec020141E0 *)q, (struct Vec020141E0 *)(&pos));
    v = func_02159BD4(v, pos.x, pos.z);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0216DF1C(s0);
    func_021623DC((char *)s4);
    func_0216242C((void *)s4, v, func_02012984(sys));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021643AC(sys, p);
    func_02189518((char *)p, v);
    func_0218958C(p, v);
    func_02189560((int *)p, (u32)v);
    func_021895D0(p, v);
    func_021895BC(sys, v);
    func_02189684((char *)p, v);
    if (((struct Obj03104 *)p)->f30 != 0 && func_020120D8((char *)((struct Obj03104 *)p)->f4) == 0)
        func_021BC550((void *)(((struct Obj03104 *)p)->f30), v);
    ((struct Obj05698 *)q)->f4 = v;
    func_0202735C((u16)v, (u32)sys);
    func_0215A014(sys, v);
    func_02158AE0((void *)(((struct Obj03104 *)p)->f4), (void *)4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021894E0((int)sys, s0, s4, v);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_0215874C((void *)func_02012138((const struct Ctx *)((struct Obj03104 *)p)->f4));
}






void func_021894E0(int a, int b, int c, int d)
{
    int r = func_02162744((u8 *)c);
    int y;
    if (r != 0) {
        y = func_0201296C((const struct BigObj *)a);
        func_0216CEAC(b, (u8 *)func_02162740((u8 *)c), d, r, y);
    }
}






void func_02189518(char *p, unsigned int idx)
{
    void *a;
    void *b;
    void *c;
    int k;

    a = func_020120F4(((struct Obj12557 *)p)->f4);
    b = (void *)func_02012134(((struct Obj12557 *)p)->f4);
    c = (void *)func_02012A30(a);
    k = func_02012B28(func_020127A4(a));
    func_0202B544((u32)b, idx);
    if (k != 2)
        func_02029CF0(c, a, idx);
}






void func_02189560(int *p, int b)
{
    int r = (int)func_02188C6C((u8 *)p);
    unsigned short k;
    func_0202C83C(p[1], b);
    k = (int)func_02012994((const struct BigObj *)p[2]);
    if (k != 0xF)
        func_021A1BDC(r, k);
}






void func_0218958C(unsigned char *p, int id)
{
    int a;
    func_021A0358(func_02188C68(p));
    a = (int)func_02013EEC((unsigned short)id);
    func_021A0338((u8 *)(((struct Obj19498 *)p)->f1C), a, func_02013F2C(id), 1);
}






int func_021895BC(void *a, u32 b)
{
return (int)func_02012AC4((struct Rec44 *)func_020127A4((struct SaveBlock *)a), ((b << 16) >> 16));
}






/*
 * Tail call passing the object, a pass-through argument and the leading u16.
 *
 * Addresses are Black-image addresses.
 */
void func_021895D0(u8 *p, u32 a)
{
    func_021895E8(p, a, ((struct Obj09444 *)p)->f0);
}






int func_021895DC(u32 a)
{
*(u32 *)((u8 *)(a) + ((67 << 2))) = 0;
return a;
}






void func_021895E8(unsigned char *p, int id, int c)
{
    int r = func_02013BD0(id);
    if (r != 0xFFFF)
        func_0218F14C((u8 *)(((struct Obj09444 *)p)->f10), r, c);
    else
        func_0218F134((u8 *)(((struct Obj09444 *)p)->f10));
}






void func_02189614(void *p, char *q, u16 id)
{
    void *t;
    int k;
    void *m;
    void *a;

    t = func_02012B38(p);
    if (func_02013DD0(((struct Obj00571 *)q)->fD0) != 0) {
        k = func_0201444C(t);
        if (k == 0)
            m = func_020127C4(((struct Obj00571 *)q)->f8);
        else
            m = func_020127D0(((struct Obj00571 *)q)->f8, 0);
        func_0218DC74((u32)(((struct Obj00571 *)q)->f48), (u32)m, k);
        a = func_0218DC70(((struct Obj00571 *)q)->f48);
        func_021939C0(a, (void *)func_02012844(p), k, ((struct Obj00571 *)q)->f0);
        func_02193ABC(a, *(int *)&((struct Obj00571 *)q)->f10, ((struct Obj00571 *)q)->f0);
        func_02193AFC(a, func_02012964(((struct Obj00571 *)q)->f8));
    }
}






void func_02189684(char *p, unsigned int id)
{
    int k;
    int a;
    int b;

    k = func_02013FA8(id);
    if (k != 0xFFFF) {
        func_021AB650(((struct Obj03105 *)p)->f40);
        func_021AB868(((struct Obj03105 *)p)->f44);
        func_021AB840(((struct Obj03105 *)p)->f44, 1, k, 0x96);
        a = func_021AB880(((struct Obj03105 *)p)->f44);
        b = func_021AB884(((struct Obj03105 *)p)->f44);
        func_021AB634(((struct Obj03105 *)p)->f40, a, b, func_021AB888(((struct Obj03105 *)p)->f44));
        return;
    }
    if (func_02013C80((u16)id) == 0) {
        func_021AB650(((struct Obj03105 *)p)->f40);
        func_021AB868(((struct Obj03105 *)p)->f44);
    }
}






int func_021896F4(void *p)
{
    int r = func_02026454(p);

    switch (r) {
    case 0:
        if (func_0200FB24() != 0)
            r = func_0202647C(p);
        return r;
    case 1:
    case 2:
    case 5:
        return r;
    }
    return 2;
}






int func_02189734(u32 a, u32 b, u32 c, u32 d)
{
if (func_02026454((void *)a) == 0) {
    return 1;
}
if (func_02026460((void *)a) == 0) {
    func_02026400((struct Comm *)a);
}
return 0;
}






void func_02189758(int *p)
{
    p[0] = -1;
    p[1] = 0;
}






void *func_02189764(unsigned char *p, int id, int a, int b)
{
    Slot *s = (Slot *)(p + 0x118);
    if (id == -1)
        return 0;
    if (s->id != -1)
        return 0;
    s->id = id;
    return s->buf = func_02030734(a, b, 1, d_021DD9C0, 0xD7C);
}





void func_021897A0(unsigned char *p, int id)
{
    Slot *s = (Slot *)(p + 0x118);
    if (id != -1) {
        func_020307B0(s->buf);
        s->id = -1;
    }
}




int *func_021897BC(char *p, int idx)
{
    int *q = (int *)(p + 0x118);

    if (idx == -1)
        return 0;
    if (idx != q[0])
        return 0;
    return (int *)q[1];
}





int func_021897DC(u32 a, u32 b, u32 c, u32 d)
{
func_021A0170((u8 *)(((struct Obj04887 *)((u8 *)(a)))->f18), b, c, d);
func_021A0568((u8 *)(((struct Obj04887 *)((u8 *)(a)))->f14), 0);
func_02048AD0((struct Light *)(*(u32 *)((u8 *)((a + 164)))));
func_02048C58((struct LightSlot *)(*(u32 *)((u8 *)((a + 168)))));
return func_0218CC64((char *)((struct Obj04887 *)((u8 *)(a)))->f48, *(u32 *)((u8 *)((a + 164))), 0);
}





void func_02189810(u8 *p)
{
    MtxFx44 saved;
    MtxFx44 m;

    if (((struct Obj00704 *)p)->f28 != 0)
        func_0219047C((u8 *)(((struct Obj00704 *)p)->f28));
    func_0218CC64((char *)(((struct Obj00704 *)p)->f48), ((struct Obj00704 *)p)->fA4, 1);
    func_021C7FB4(((struct Obj00704 *)p)->fA0);
    saved = g_02148B54;

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], ((struct Obj00704 *)p)->f104);
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206DB80(func_0206A854());
    func_021ABE0C(((struct Obj00704 *)p)->f94);
    func_021C64E0(((struct Obj00704 *)p)->f130);
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB0), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB8), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);
    if (((struct Obj00704 *)p)->f98 != 0)
        func_0217F928((char *)(((struct Obj00704 *)p)->f98));

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], ((struct Obj00704 *)p)->f104 / 2);
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206DB80(func_0206A854());
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB4), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);

    MIi_CpuCopyFast(&saved, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();

    func_021BB954((u8 *)(((struct Obj00704 *)p)->fBC));
    func_021A1B38((u32 *)(((struct Obj00704 *)p)->f20));
    func_021BE4F8((char *)(((struct Obj00704 *)p)->f34));
    func_021C1AEC();
    func_021C1C4C((char *)(((struct Obj00704 *)p)->f124));
}





void func_02189998(unsigned char *p)
{
    func_0207DD24(0, 0, 0x7FFF, 0, 0);
    func_021C1AEC();
    func_021C1C4C((char *)(((struct Obj19499 *)p)->f124));
}





void func_021899C4(unsigned char *p)
{
    func_0207DD24(0x4210, 0x1F, 0x7FFF, 0, 0);
    func_021CF520(((struct Obj19500 *)p)->f13C);
}





/*
 * Unlabelled leaf getter: the word at +0x12C (func_021899F8 is its setter).
 * Addresses are Black-image addresses.
 */
u32 func_021899F0(u8 *p)
{
    return ((struct Obj19501 *)p)->f12C;
}





/*
 * Unlabelled leaf setter: the word at +0x12C.
 * Addresses are Black-image addresses.
 */
void func_021899F8(u8 *p, u32 v)
{
    ((struct Obj19502 *)p)->f12C = v;
}





/*
 * Loads the 32-bit word at byte +0x124 of the object.
 */
void *func_02189A00(u8 *p)
{
    return ((struct Obj00020 *)p)->f124;
}





int func_02189A08(unsigned char *p)
{
    return ((struct Obj19503 *)p)->f13C;
}





/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the pointer at +0xA0.
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */
void *func_02189A10(Obj *p)
{
    return p->fa0;
}





/*
 * Loads the 32-bit word at byte +0x40 of the object.
 */
u32 func_02189A18(u8 *p)
{
    return ((struct Obj17887 *)p)->f40;
}





/*
 * Stores the 32-bit word into byte +0x138 of the object.
 */
void func_02189A1C(u8 *p, u32 v)
{
    ((struct Obj17888 *)p)->f138 = v;
}





/*
 * Loads the 32-bit word at byte +0x138 of the object.
 */
u32 func_02189A24(u8 *p)
{
    return ((struct Obj17889 *)p)->f138;
}





int func_02189A2C(int *a)
{
    return func_020120D8((char *)a[1]);
}




int func_02189A38(int a)
{
return func_020113D8(func_02012984((const struct BigObj *)(((struct Obj17890 *)((u8 *)(a)))->f8)));
}



int func_02189A48(char *p)
{
    return *(unsigned int *)(p + 0x144);
}



/*
 * Unlabelled leaf (saves no lr): stores r1 at +0x144.  Callee of ov020
 * func_02187CEC and func_02187CFC.
 */
void func_02189A50(char *p, int v)
{
    *(int *)(p + 0x144) = v;
}




/*
 * Unlabelled leaf setter, called from func_021BEF8C.
 */
void func_02189A58(u8 *p, u32 v)
{
    ((struct Obj19506 *)p)->f140 = v;
}




u8 *func_02189A60(u8 *p)
{
    return p + 0x148;
}




void func_02189A68(char *a, int b)
{
    ((struct Obj19507 *)a)->f150 = b;
}




/*
 * Loads the 32-bit word at byte +0x150 of the object.
 */
u32 func_02189A70(u8 *p)
{
    return ((struct Obj17891 *)p)->f150;
}




/*
 * Loads the 32-bit word at byte +0x100 of the object.
 */
u32 func_02189A78(u8 *p)
{
    return ((struct Obj17892 *)p)->f100;
}




int func_02189A80(char *p)
{
    unsigned short *q = (short unsigned int *)func_0218ED3C(((struct Obj19508 *)p)->f10);
    int i = (*q >> 4) * 2 + 1;
    int s = d_020A1B38[i];
    long long v;
    int r;

    if (s < 0)
        s = -s;
    v = ((long long)s << 14) + 0x800;
    r = (int)(v >> 12) - 0x4000;
    if (r < -0x2000)
        r = -0x2000;
    return r;
}




/*
 * Leaf: returns one of two pooled constants (0x1EE / 0x136) depending on
 * func_02013BA8() == 1.  Callee of func_021881D8 (assigns p->x104).
 */
int func_02189ACC(u32 a0)
{
    if (func_02013BA8(a0) == 1)
        return 0x1EE;
    return 0x136;
}




/*
 * Leaf: 0 for id 0x3f, else 0 when func_02013CE0() reports 1, else 1.
 * Callee of func_02189204.  EXACT* because the unlabelled follower
 * (0x02189B04) has no seed; no byte differs.
 */
int func_02189AE8(int a)
{
    if (a == 0x3f)
        return 0;
    if (func_02013CE0(a) == 1)
        return 0;
    return 1;
}



int func_02189B04(int x)
{
    if (x == 0x3F)
        return 1;
    if (x == 0x8C)
        return 1;
    if (x == 0x8D)
        return 1;
    if (x == 0x8E)
        return 1;
    return 0;
}




/*
 * Tail-call thunk: forwards to func_02013B50 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02189B28(u32 id)
{
    return func_02013B50(id);
}




void func_02189B30(int a, int x, char *out, void *obj)
{
    int i = (int)func_02189B28((unsigned int)a);

    *(Rec *)out = d_021D3700[i].r;
    if (d_021D3700[i].f40 != 0) {
        ((struct Obj03106 *)out)->f14 = func_02159BF4(obj);
        ((struct Obj03106 *)out)->f16 = func_02159BF8(obj);
        ((struct Obj03106 *)out)->f18 = func_02159BFC(obj);
        ((struct Obj03106 *)out)->f1C = (int)func_02159C20(obj);
    }
    ((struct Obj03106 *)out)->f20 = 1;
    ((struct Obj03106 *)out)->f24 = 0xe;
    ((struct Obj03106 *)out)->f28 = func_020140BC((struct Sub020140BCObj *)x);
    ((struct Obj03106 *)out)->f2C = func_020140C0((struct Sub020140BCObj *)x);
    ((struct Obj03106 *)out)->f30 = func_020140CC((struct Sub020140BCObj *)x);
}




int func_02189BA8(int x)
{
    return d_021D373C[(int)func_02189B28((unsigned int)x)].f0;
}
