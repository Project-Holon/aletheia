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
 *   d_021D35F4     0x021D35F4  data
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
#include "fieldmap_types.h"

typedef int (*FieldMapSeqFunc)(struct GameSystem *gameSystem, FieldMap *fieldMap);
typedef int (*FieldMapEventCheckFunc)(struct GameSystem *gameSystem, void *work);

#define REG_DISPCNT (*(volatile u32 *)0x04000000)
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
struct GameSystem;
struct GfProc;
struct GameComm;
struct PlayerWork;
struct DispVram;
struct GameData;
struct Cfg;
struct MapMatrix;
struct FieldStatus;
struct DispConfig;
struct Mtx22;
struct LightSet;
struct BbActSys;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed int     s32;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef int fx32;

typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

/* NNS_G3dGlb (NitroSystem); fieldmap.c only clears bits of the flag word. */
typedef struct G3dGlobalState {
    u8 otherState[0x7C];    /* 0x00: not touched here */
    u32 flag;               /* 0x7C */
} G3dGlobalState;

typedef void (*FieldMapDrawFunc)(FieldMap *fieldMap);
typedef int (*FieldMapDrawEndFunc)(FieldMap *fieldMap);

struct PlayerWork *func_020120F8(const struct GameSystem *x);
unsigned short func_02012AC8(const struct PlayerWork *x);
int func_02189BBC(int x);
void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
void func_02030678(void *a, u32 b, u32 c);
void *func_0203159C(struct GfProc *proc, u32 size, u32 heapId);
void func_02012110(struct GameSystem *p, void *v);
unsigned int func_0201214C(const struct GameSystem *x);
struct GameComm *func_02012138(const struct GameSystem *gameSystem);
u32 func_02026454(struct GameComm *gameComm);
void func_02026400(struct GameComm *gameComm);
void func_020315D4(struct GfProc *proc);
void func_020306F0(unsigned int heap);
void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, u16 tag);
struct GameData *func_020120F4(const struct GameSystem *p);
u32 func_02013B38(u32 id);
int func_0202E83C(void *a0);
struct AreaData *func_0201407C(int heapId, int areaId, int infoCode);
u32 func_020140B4(struct AreaData *areaData);
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
extern u8 func_02012984(const struct GameData *p);
extern struct FieldG3dMapper *func_0218C9E8(int heapId, int b);
extern struct GFL_TCB *func_020056A0(void (*cb)(struct GFL_TCB *, void *), void *work, int pri);
extern u32 func_02030CB0(u32 idx);
extern struct TcblSys *func_02030CBC(u32 capacity, void *work);
extern struct FieldTaskManager *func_021C6D10(int n, int heapId);
extern void *func_021D317C(u32 heap);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern int func_02034AC4(int id);
extern void func_02035660(u32 a);
extern void func_0216447C(struct GameData *gameData, u16 zoneId);
extern struct FieldMsgBg *func_021901EC(u16 heapId, struct G3dCamera *g3dCamera);
extern struct FieldPlaceName *func_021BC388(struct GameSystem *gameSystem, int heapId, struct FieldMsgBg *msgBg);
extern struct FieldStatus *func_02012B38(const struct GameData *gameData);
extern u16 func_02014470(struct FieldStatus *o);
extern struct FieldSkillMapEff *func_021C7F70(int flags, u16 heapId);
extern u8 func_02013BBC(u32 id);
extern struct FieldCamera *func_0218E018(int a0, int a1, struct G3dCamera *g3dCamera, const VecFx32 *target, u16 heapId);
extern struct FldSceneArea *func_021AB5F4(u16 heapId, struct FieldCamera *camera, void *work);
extern struct FldSceneAreaLoader *func_021AB7E4(u16 heapId);
extern struct FieldNogridMapper *func_021BB1F4(u32 heapId, struct FieldCamera *camera, struct FldSceneArea *sceneArea, struct FldSceneAreaLoader *loader);
extern struct FieldPalaceSys *func_021D33A8(u16 heapId, struct GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId);
extern void *func_0218DC6C(struct FieldG3dMapper *g3dMapper);
extern struct MapMatrix *func_02012974(const struct GameData *gameData);
extern void *func_021D33F8(struct FieldPalaceSys *palaceSys);
extern void func_0218B8AC(void *buildModel, int zoneId, struct AreaData *areaData, void *palTable);
extern void func_021C6534(struct FieldG3dObjCtrl *g3dObjCtrl, void *palTable);
extern void func_02014110(FieldMapLocation *location, u16 zoneId, int b, int c, int d, int x, int y, int z);
extern void func_0218CEE4(struct FieldG3dMapper *g3dMapper, const FieldMapMapperParam *param, void *palTable);
extern int func_02013C9C(u16 key);
extern void func_021BB2F8(struct FieldNogridMapper *nogridMapper, u32 kind, u32 heapId);
extern struct FieldEffectCont *func_021ABD50(FieldMap *fieldMap, int b, u16 heapId);
extern void func_021ABF68(struct FieldEffectCont *effect, int n);
extern void func_021AC1EC(struct FieldEffectCont *effect, void *palTable);
extern void func_021ABE30(struct FieldEffectCont *effect, int *arr, int n);
extern struct UnionEff *func_0217F8C0(u16 heapId);
extern u32 func_02012AE4(const struct PlayerWork *p);
extern u32 func_02012B28(const struct PlayerWork *p);
extern u32 func_02013C20(u32 id);
extern void func_02012B2C(struct PlayerWork *p, u32 v);
extern void *func_02012944(struct GameData *gameData);
extern u8 func_02008550(const void *myStatus);
extern struct FieldPlayer *func_021A2E50(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, int sex, u16 heapId);
extern void func_0218D158(struct FieldG3dMapper *g3dMapper, const VecFx32 *pos);
extern struct FldExpObjCnt *func_021BE2A8(int a, int b, u16 heapId);
extern struct FieldFog *func_021A0104(u16 heapId);
extern struct FieldZoneFog *func_021A02C4(u16 heapId);
extern u32 func_02013EEC(u32 id);
extern int func_02013F2C(unsigned short id);
extern void func_021A0338(struct FieldZoneFog *zoneFog, u32 id, u32 c, u8 d);
extern u8 func_020140DC(struct AreaData *areaData);
extern u32 func_0203F4FC(void);
extern struct FieldLight *func_021A03D0(u32 a, u32 b, u32 c, struct FieldFog *fog, struct G3dLightSlots *g3dLight, u16 heapId);
extern u32 func_02012A30(const struct GameData *p);
extern struct WeatherSys *func_021A19E8(struct FieldCamera *camera, struct FieldLight *light, struct FieldFog *fog, struct FieldZoneFog *zoneFog, int a4, int a5, int heapId);
extern u8 func_02012994(const struct GameData *p);
extern void func_021A1B74(struct WeatherSys *weather, int a, int f);
extern void func_021BE1DC(FieldMap *fieldMap);
extern u8 func_020129AC(const struct GameData *p);
extern struct FieldSubscreen *func_021A0CF4(u32 heapId, FieldMap *fieldMap, u32 c);
extern struct FieldEncount *func_021A9ED8(FieldMap *fieldMap);
extern void func_02026388(struct GameComm *gameComm, FieldMap *fieldMap);
extern struct FieldmapFunc *func_021BB890(FieldMap *fieldMap, int b, int n);
extern struct FldParticle *func_021C1A08(u32 a);
extern struct Fld3dCi *func_021C1AF4(u32 a, struct FldParticle *particle);
extern struct EncEff *func_021CF45C(u32 heapId, FieldMap *fieldMap);
extern void *func_02012EBC(struct GameData *gameData);
extern void *func_0200BDB0(void *sys);
extern struct Sodateya *func_021C31D4(u16 heapId, FieldMap *fieldMap, void *b);
extern void func_0218CA78(struct FieldG3dMapper *g3dMapper);
extern int func_0216CD64(struct MmdlSys *mmdlSys);
extern int func_0219C624(struct MmdlSys *mmdlSys);
extern int func_0219C630(struct MmdlSys *mmdlSys);
extern int func_021A1B50(struct WeatherSys *weather);
extern void func_021A1AF4(struct WeatherSys *weather, int heapId);
extern void func_0204A600(void);
extern void func_021903E0(struct FieldMsgBg *msgBg);
extern void func_021ABE04(struct FieldEffectCont *effect);
extern void func_021BB948(struct FieldmapFunc *mapFunc);
extern u8 func_02014460(struct FieldStatus *o);
extern int func_02005C64(void);
extern u8 func_02014458(struct FieldStatus *o);
extern void func_02158AC8(struct GameSystem *gameSystem, int heapId);
extern void func_02014454(struct FieldStatus *o, u8 v);
extern void func_02158AD4(struct GameSystem *gameSystem, int heapId);
extern void func_0201445C(struct FieldStatus *o, u8 v);
extern void func_0201209C(struct GameSystem *gameSystem, FieldMapEventCheckFunc checkFunc, FieldMap *fieldMap);
extern void func_020129DC(struct GameData *p, u8 v);
extern int func_0218A0E4(struct GameSystem *gameSystem, void *work);
extern int func_0218A240(struct GameSystem *gameSystem, void *work);
extern int func_0218A4BC(struct GameSystem *gameSystem, void *work);
extern int func_0218A074(struct GameSystem *gameSystem, void *work);
extern u32 func_02012104(const struct GameSystem *p);
extern u8 func_0201447C(struct FieldStatus *o, u8 v);
extern u8 func_02012E40(const struct GameData *gameData);
extern void func_02035648(void);
extern int func_020120D8(struct GameSystem *gameSystem);
extern void func_02168EEC(struct GameData *gameData);
extern void func_021BC484(struct FieldPlaceName *placeName);
extern void func_021C7FAC(struct FieldSkillMapEff *mapEff);
extern void func_021A2EB8(struct FieldPlayer *player);
extern void func_021737A4(struct GameComm *gameComm, FieldMap *fieldMap);
extern void func_0217AE20(FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
extern void func_021A0D68(struct FieldSubscreen *subscreen);
extern void func_021BE258(FieldMap *fieldMap);
extern void func_0217F914(struct UnionEff *unionEff);
extern void func_02030D28(struct TcblSys *c);
extern void func_021C6D90(struct FieldTaskManager *taskManager);
extern u32 *func_02012ED0(struct GameData *gameData);
extern void func_021C8660(u32 a);
void func_02047CE4(void);
unsigned int func_0203630C(void);
extern void func_0218E104(struct FieldCamera *camera, u32 b);
extern void func_020129F0(struct GameData *p);
extern void func_0218CC34(struct FieldG3dMapper *g3dMapper);
extern void func_021A0E58(struct FieldSubscreen *subscreen);
extern void func_021BC4F0(struct FieldPlaceName *placeName);
extern int func_021CF480(struct EncEff *encEff);
extern void func_021C1C04(struct Fld3dCi *fld3dCi);
extern void func_021C1AD0(struct FldParticle *particle);
extern void func_021BB90C(struct FieldmapFunc *mapFunc);
extern void func_020263B0(struct GameComm *gameComm, FieldMap *fieldMap);
extern void func_021BC424(struct FieldPlaceName *placeName);
extern void func_021BE218(FieldMap *fieldMap);
extern void func_021BE2E0(struct FldExpObjCnt *expObj);
extern void func_021A9F28(struct FieldEncount *encount);
extern u8 func_021A0D44(struct FieldSubscreen *subscreen);
extern void func_020129B8(struct GameData *p, u32 v);
extern void func_021ABDE8(struct FieldEffectCont *effect);
extern void func_0217F8EC(struct UnionEff *unionEff);
extern void func_021A1AAC(struct WeatherSys *weather);
extern void func_021A0448(struct FieldLight *light);
extern int func_021A02F4(struct FieldZoneFog *zoneFog);
extern void func_021A0138(struct FieldFog *fog);
extern void func_021D33E0(struct FieldPalaceSys *palaceSys);
extern int func_021BB240(struct FieldNogridMapper *nogridMapper);
extern void func_021AB81C(struct FldSceneAreaLoader *sceneAreaLoader);
extern void func_021AB624(struct FldSceneArea *sceneArea);
extern void func_0218E0E4(struct FieldCamera *camera);
extern int func_021A2E90(struct FieldPlayer *player);
extern void func_0218D05C(struct FieldG3dMapper *g3dMapper);
extern int func_02190728(struct FieldMsgWin *infoWindow);
extern void func_021902BC(struct FieldMsgBg *msgBg);
extern void func_021C31FC(struct Sodateya *sodateya);
extern void func_021C7F9C(struct FieldSkillMapEff *mapEff);
extern void func_02030DA4(struct TcblSys *tcblSys);
extern void func_02030EAC(struct GFL_TCB *tcb);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_02034A5C(s32 handle);
extern void func_021D31A4(struct FldVReq *vreq);
extern void func_021C6D5C(struct FieldTaskManager *taskManager);
extern int func_0218CA4C(struct FieldG3dMapper *g3dMapper);
extern u32 func_021A3098(struct FieldPlayer *player);
extern void func_021A2F48(struct FieldPlayer *player, u32 a1);
extern int func_021A2F54(struct FieldPlayer *player);
extern void func_020061E4(u32 a);
extern void *func_02012F2C(struct GameData *gameData);
extern u32 func_02008DF0(void *record, int i);
extern u8 func_0202C794(void *a0, u32 a1);
extern u32 func_021A6DC0(u8 *p);
extern void func_0203F8F4(u16 heap);
extern void func_02040E78(u32 a, void *b, u32 c, u32 d);
extern u32 func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_0203FC28(const struct DispConfig *cfg);
extern const struct DispConfig d_021D35F4;
extern void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(u32 a, void *buf, u32 b, u32 c, u32 d, u32 e);
extern void func_0204044C(u32 a);
extern void func_02190270(struct FieldMsgBg *msgBg);
extern void func_0219027C(struct FieldMsgBg *msgBg);
extern u32 func_0203F9B4(u32);
extern u32 func_02046788(u32);
extern u32 func_0206DB80(u32);
extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(void *a);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_0207DCF8(void *a);
extern void func_02046BE0(u32 a, u32 b);
extern struct BbActSys *func_0204FE94(u16 a0, u16 a1, void (*transCallback)(int, int, void *, int), int heapId);
extern void *func_02050080(struct BbActSys *bbdAct);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204EDC4(u8 *dst, int a, int b);
extern void func_0204ED70(void *board, const VecFx32 *scale);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern struct FieldG3dObjCtrl *func_021C63AC(u16 heapId, int a, int b);
extern struct G3dCamera *func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern struct G3dLightSlots *func_02048BC4(const struct LightSet *s, u32 heapId);
extern void func_02048AD0(struct G3dCamera *g3dCamera);
extern void func_02048C58(struct G3dLightSlots *g3dLight);
extern void func_020504D8(struct BbActSys *bbdAct);
extern void func_021BB36C(struct FieldNogridMapper *nogridMapper);
extern int func_021AB660(struct FldSceneArea *sceneArea, const VecFx32 *pos);
extern void func_021A030C(struct FieldZoneFog *zoneFog, u32 heapId);
extern void func_021A0140(struct FieldFog *fog);
extern void func_021A0458(struct FieldLight *light, s32 b);
extern int func_0218CB34(struct FieldG3dMapper *g3dMapper);
extern void func_0203D12C(int a);
void func_02047964(void);
void func_020479D8(void);
void func_02047970(int x);
extern u32 func_02048AC4(void *ptr);
extern u32 func_02048C4C(struct G3dLightSlots *g3dLight);
extern void func_0204FFFC(struct BbActSys *o);
extern int func_021C6400(struct FieldG3dObjCtrl *g3dObjCtrl);
int func_02005C8C(void);
int func_0216CD78(struct MmdlSys *mmdlSys);
void func_021C6470(struct FieldG3dObjCtrl *g3dObjCtrl);
void func_0204A648(void);
void func_021D31AC(struct FldVReq *vreq);
s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u8 func_020140E0(struct AreaData *areaData);
extern u32 func_02013DB8(u32 a);
extern void func_02048F4C(void *a, u32 b, u32 c);
extern u8 func_020140E4(struct AreaData *areaData);
extern void *func_021CD1C8(u32 heapId);
extern void func_021CD204(void *bbdColor, u32 b);
extern void func_021CD214(void *bbdColor, void *board);
extern int func_021CD1F0(void *a);
extern struct MmdlSys *func_02012964(const struct GameData *gameData);
extern void func_0216CCDC(struct MmdlSys *mmdlSys, int heapId, struct GameData *gameData, FieldMap *fieldMap, struct FieldG3dMapper *g3dMapper, struct FieldNogridMapper *nogridMapper);
extern void func_0219C554(struct MmdlSys *mmdlSys, struct BbActSys *bbdAct, u32 c);
extern void func_0219C680(struct MmdlSys *mmdlSys);
extern u8 func_0217C0A8(void *a0);
extern int func_021A31A4(int i, int v);
extern void func_0219C658(struct MmdlSys *mmdlSys, u32 b);
extern void func_0219D448(struct MmdlSys *mmdlSys, struct FieldG3dObjCtrl *g3dObjCtrl);
extern void *func_0218ED50(struct FieldCamera *camera);
extern void func_0216CDB8(struct MmdlSys *mmdlSys, void *areaIdRef);
extern void func_0216D2F8(struct MmdlSys *mmdlSys);
extern void func_0216D974(struct MmdlSys *mmdlSys, unsigned int v);
extern int func_0216CD50(struct MmdlSys *mmdlSys);
extern void func_0216D2AC(struct MmdlSys *mmdlSys);
extern void *func_02012844(const struct GameData *gameData);
extern u32 func_02162458(u8 *p);
extern void func_02162438(void *eventData, int a1, int a2);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern VecFx32 *func_02012AA0(struct PlayerWork *playerWork);
extern void func_020141E0(const FieldMapLocation *location, VecFx32 *out);
extern void func_020141F0(FieldMapLocation *location, const VecFx32 *pos);
extern int func_02159C48(struct MapMatrix *mapMatrix, int x, int z);
extern int func_02159BD4(struct MapMatrix *mapMatrix, int x, int z);
extern void func_021AA8EC(struct FieldEncount *encount);
extern void func_0216DF1C(struct MmdlSys *mmdlSys);
extern void func_021623DC(char *p);
extern void func_0216242C(void *a0, u16 a1, u8 a2);
extern void func_021643AC(void *a, void *b);
extern void func_021BC550(void *p, int v);
extern void func_0202735C(u32 a0, struct GameData *gameData);
extern void func_0215A014(void *a, int b);
extern void func_02158AE0(void *a0, void *a1);
extern void func_0215874C(void *a);
u16 func_02162744(u8 *p);
u32 func_0201296C(const struct GameData *p);
void *func_02162740(void *eventData);
void func_0216CEAC(struct MmdlSys *mmdlSys, void *headers, u32 b, u32 n, u32 c);
extern u32 func_02012134(struct GameSystem *gameSystem);
extern void func_0202B544(u32 a, u16 b);
extern void func_02029CF0(void *a, void *b, u16 c);
int func_0202C83C(struct GameSystem *gameSystem, int a1);
void func_021A1BDC(struct WeatherSys *weather, int k);
void func_021A0358(struct FieldZoneFog *zoneFog);
extern struct PlayerWork *func_02012AC4(struct PlayerWork *p, u16 v);
unsigned short func_02013BD0(unsigned short id);
void func_0218F14C(struct FieldCamera *camera, u32 a, u32 b);
void func_0218F134(struct FieldCamera *camera);
extern int func_02013DD0(int v);
extern u32 func_0201444C(struct FieldStatus *o);
extern u8 *func_020127C4(void *p);
extern void *func_020127D0(struct GameData *gameData, u32 idx);
extern int func_0218DC74(struct FieldG3dMapper *g3dMapper, void *wfbcData, u32 c);
extern void *func_0218DC70(struct FieldG3dMapper *g3dMapper);
extern void func_021939C0(void *buildModel, void *eventData, int skip, u32 heapId);
extern void func_02193ABC(void *buildModel, struct FieldCamera *camera, int b);
extern void func_02193AFC(void *buildModel, struct MmdlSys *mmdlSys);
extern int func_02013FA8(u16 id);
extern int func_02013C80(int a0);
extern void func_021AB650(void *p);
extern void func_021AB868(void *p);
extern void func_021AB840(void *p, int a, int b, int c);
extern u32 func_021AB880(struct FldSceneAreaLoader *sceneAreaLoader);
extern u32 func_021AB884(struct FldSceneAreaLoader *sceneAreaLoader);
extern int func_021AB888(void *p);
extern void func_021AB634(void *p, int a, int b, int c);
extern u32 func_0200FB24(void);
extern u32 func_0202647C(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_0218CC64(struct FieldG3dMapper *g3dMapper, struct G3dCamera *g3dCamera, int m);
extern void func_021A0170(struct FieldFog *fog, u32 a1, u32 a2, u32 a3);
extern void func_021A0568(struct FieldLight *light, int force);
extern void func_0219047C(struct FieldMsgBg *msgBg);
extern void func_021C7FB4(struct FieldSkillMapEff *mapEff);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern u32 func_0206A854(void);
extern void func_021ABE0C(struct FieldEffectCont *effect);
extern void func_021C64E0(struct FieldG3dObjCtrl *g3dObjCtrl);
extern void func_02050790(struct BbActSys *bbdAct, struct G3dCamera *g3dCamera, struct G3dLightSlots *g3dLight);
extern void func_0217F928(struct UnionEff *unionEff);
extern void func_021BB954(struct FieldmapFunc *mapFunc);
extern void func_021A1B38(struct WeatherSys *weather);
extern void func_021BE4F8(struct FldExpObjCnt *expObj);
extern void func_021C1AEC(void);
extern void func_021C1C4C(struct Fld3dCi *fld3dCi);
void func_021CF520(struct EncEff *encEff);
extern u32 func_020113D8(u32);
extern void *func_0218ED3C(struct FieldCamera *camera);
extern u8 func_02013BA8(u32 id);
extern u32 func_02013B50(u32 id);
extern unsigned short func_02159BF4(struct MapMatrix *mapMatrix);
extern unsigned short func_02159BF8(struct MapMatrix *mapMatrix);
extern int func_02159BFC(struct MapMatrix *mapMatrix);
extern void *func_02159C20(struct MapMatrix *mapMatrix);
extern u16 func_020140BC(struct AreaData *areaData);
extern u32 func_020140C0(struct AreaData *areaData);
extern u32 func_020140CC(struct AreaData *areaData);
int func_02187F00(struct GfProc *proc, int *seq, struct GameSystem *gameSystem);
int func_02187FD0(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work);
int func_02187FE8(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work);
FieldMap *func_02188030(struct GameSystem *gameSystem, int heapId);
void func_021880A4(FieldMap *fieldMap);
int func_021880C8(struct GameSystem *gameSystem, FieldMap *fieldMap);
int func_021881D8(struct GameSystem *gameSystem, FieldMap *fieldMap);
int func_021885E8(struct GameSystem *gameSystem, FieldMap *fieldMap);
int func_02188758(struct GameSystem *gameSystem, FieldMap *fieldMap);
void func_021888C8(FieldMap *fieldMap);
int func_02188910(struct GameSystem *gameSystem, FieldMap *fieldMap);
int func_02188990(struct GameSystem *gameSystem, FieldMap *fieldMap);
int func_02188AD4(struct GameSystem *gameSystem, FieldMap *fieldMap);
int func_02188B58(struct GameSystem *gameSystem, FieldMap *fieldMap);
void func_02188BD8(FieldMap *fieldMap);
int func_02188BE8(FieldMap *fieldMap);
u32 func_02188BF8(FieldMap *fieldMap);
struct FieldMsgBg *func_02188C54(FieldMap *fieldMap);
struct FieldCamera *func_02188C58(FieldMap *fieldMap);
struct FieldNogridMapper *func_02188C5C(FieldMap *fieldMap);
struct FieldLight *func_02188C60(FieldMap *fieldMap);
struct FieldFog *func_02188C64(FieldMap *fieldMap);
struct FieldZoneFog *func_02188C68(FieldMap *fieldMap);
struct WeatherSys *func_02188C6C(FieldMap *fieldMap);
int func_02188C70(FieldMap *fieldMap, int switchId);
struct MmdlSys *func_02188C7C(FieldMap *fieldMap);
struct GameSystem *func_02188C80(FieldMap *fieldMap);
u16 func_02188C84(FieldMap *fieldMap);
struct BbActSys *func_02188C88(FieldMap *fieldMap);
struct BbActSys *func_02188C90(FieldMap *fieldMap);
struct FieldG3dMapper *func_02188C98(FieldMap *fieldMap);
u16 func_02188C9C(FieldMap *fieldMap);
void *func_02188CA4(FieldMap *fieldMap);
void func_02188CAC(FieldMap *fieldMap, void *ctrlWork);
struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
int func_02188CBC(FieldMap *fieldMap);
struct FieldSubscreen *func_02188CCC(FieldMap *fieldMap);
struct FieldEffectCont *func_02188CD0(FieldMap *fieldMap);
struct FieldG3dObjCtrl *func_02188CD8(FieldMap *fieldMap);
struct UnionEff *func_02188CE0(FieldMap *fieldMap);
struct FieldEncount *func_02188CE8(FieldMap *fieldMap);
unsigned int func_02188CF0(FieldMap *fieldMap);
u32 func_02188CFC(FieldMap *fieldMap);
struct FieldPlaceName *func_02188D20(FieldMap *fieldMap);
struct FieldmapFunc *func_02188D24(FieldMap *fieldMap);
struct FldExpObjCnt *func_02188D2C(FieldMap *fieldMap);
struct TcblSys *func_02188D30(FieldMap *fieldMap);
struct FieldTaskManager *func_02188D38(FieldMap *fieldMap);
void func_02188D40(FieldMap *fieldMap, const VecFx32 *targetPos);
struct FieldMsgWin *func_02188D48(FieldMap *fieldMap);
void func_02188D4C(FieldMap *fieldMap, struct FieldMsgWin *infoWindow);
struct Sodateya *func_02188D50(FieldMap *fieldMap);
struct AreaData *func_02188D58(FieldMap *fieldMap);
void func_02188D5C(FieldMap *fieldMap);
void func_02188DA0(void);
void func_02188DB0(FieldMap *fieldMap);
void func_02188DF0(FieldMap *fieldMap);
struct FldVReq *func_02188E30(FieldMap *fieldMap);
int func_02188E38(FieldMap *fieldMap);
void func_02188E50(void);
void func_02188EE4(FieldMap *fieldMap);
void func_02189004(FieldMap *fieldMap);
void func_02189084(FieldMap *fieldMap);
void func_021890AC(FieldMap *fieldMap);
int func_021890C8(FieldMap *fieldMap);
void func_02189108(struct GFL_TCB *tcb, void *work);
void func_02189140(int vramTransfer, int destAddr, void *src, int size);
void func_02189154(struct AreaData *areaData, u32 zoneId);
void func_021891C0(FieldMap *fieldMap);
void func_02189204(FieldMap *fieldMap);
int func_021892B4(FieldMap *fieldMap);
u32 func_021892CC(FieldMap *fieldMap);
int func_0218932C(FieldMap *fieldMap);
u32 func_02189370(FieldMap *fieldMap);
void func_021893C0(FieldMap *fieldMap);
void func_021894E0(struct GameData *gameData, struct MmdlSys *mmdlSys, void *eventData, int zoneId);
void func_02189518(FieldMap *fieldMap, unsigned int zoneId);
void func_02189560(FieldMap *fieldMap, int zoneId);
void func_0218958C(FieldMap *fieldMap, int zoneId);
int func_021895BC(struct GameData *gameData, u32 zoneId);
void func_021895D0(FieldMap *fieldMap, u32 zoneId);
FieldMap *func_021895DC(FieldMap *fieldMap);
void func_021895E8(FieldMap *fieldMap, int zoneId, int heapId);
void func_02189614(struct GameData *gameData, FieldMap *fieldMap, u16 zoneId);
void func_02189684(FieldMap *fieldMap, unsigned int zoneId);
int func_021896F4(struct GameComm *gameComm);
int func_02189734(struct GameComm *gameComm);
void func_02189758(FieldMapCommonWork *commonWork);
void *func_02189764(FieldMap *fieldMap, int id, int heapId, int size);
void func_021897A0(FieldMap *fieldMap, int id);
void *func_021897BC(FieldMap *fieldMap, int id);
int func_021897DC(FieldMap *fieldMap, u32 fogEnable, u32 fogSlope, u32 fogOffset);
void func_02189810(FieldMap *fieldMap);
void func_02189998(FieldMap *fieldMap);
void func_021899C4(FieldMap *fieldMap);
int func_021899F0(FieldMap *fieldMap);
void func_021899F8(FieldMap *fieldMap, int drawMode);
struct Fld3dCi *func_02189A00(FieldMap *fieldMap);
struct EncEff *func_02189A08(FieldMap *fieldMap);
struct FieldSkillMapEff *func_02189A10(FieldMap *fieldMap);
struct FldSceneArea *func_02189A18(FieldMap *fieldMap);
void func_02189A1C(FieldMap *fieldMap, int busy);
int func_02189A24(FieldMap *fieldMap);
int func_02189A2C(FieldMap *fieldMap);
int func_02189A38(FieldMap *fieldMap);
int func_02189A48(FieldMap *fieldMap);
void func_02189A50(FieldMap *fieldMap, int busy);
void func_02189A58(FieldMap *fieldMap, int stopped);
void **func_02189A60(FieldMap *fieldMap);
void func_02189A68(FieldMap *fieldMap, void *zoneEffectWork);
void *func_02189A70(FieldMap *fieldMap);
int func_02189A78(FieldMap *fieldMap);
int func_02189A80(FieldMap *fieldMap);
int func_02189ACC(u32 zoneId);
int func_02189AE8(int zoneId);
int func_02189B04(int zoneId);
u32 func_02189B28(u32 zoneId);
void func_02189B30(int zoneId, struct AreaData *areaData, FieldMapMapperParam *param, struct MapMatrix *mapMatrix);
const FieldMapCtrlFuncs *func_02189BA8(int zoneId);
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
extern FieldMapSeqFunc data_021D36B8[][2];
extern const u8 data_021D35A8[];
extern u16 d_021D3620[];
extern u8 data_021D3640[];
extern u8 data_021D35E4[];
extern const s16 d_020A1EB8[];
extern const VecFx32 d_021D36F4;
extern const VecFx32 d_021D36E8;
extern VecFx32 d_021D35C0;
extern VecFx32 d_021D35CC;
extern u8 d_021D35AC[];
extern FieldMapDrawFunc d_021D35D8[];
extern FieldMapDrawEndFunc d_021D35B4[];
/*
 * The edge marking colour buffer has two names: the code loads its address
 * from two literal pool words, one per name, so the bytes need both.
 */
extern u8 data_021EE700[];
extern u16 data_021EE700b[];
extern MtxFx44 g_02148B54;
extern G3dGlobalState g_02148BCC;
extern short d_020A1B38[];
extern FieldMapTypeEntry d_021D3700[];
extern FieldMapTypeEntryTail d_021D373C[];

int func_02187F00(struct GfProc *proc, int *seq, struct GameSystem *gameSystem)
{
    switch (*seq) {
    case 0:
        {
            int fieldHeapSize = func_02189BBC(func_02012AC8(func_020120F8(gameSystem))) - 0xD000;
            func_0203064C(1, 0x15, fieldHeapSize);
        }
        func_0203064C(1, 0x70, 0xD000);
        func_0203064C(0x15, 0x50, 0xC000);
        func_02030678(d_021DE700, 0x10000, 0x89);
        func_0203064C(0x89, 0x92, 0x6400);
        func_0203064C(0x89, 0x93, 0x7400);
        func_0203064C(0x89, 0x96, 0x500);
        {
            FieldMapProcWork *work = func_0203159C(proc, sizeof(FieldMapProcWork), 0x15);
            FieldMap *fieldMap = func_02188030(gameSystem, 0x15);
            work->fieldMap = fieldMap;
            func_02012110(gameSystem, fieldMap);
        }
        (*seq)++;
        break;
    case 1:
        if (func_0201214C(gameSystem) == 0) {
            struct GameComm *gameComm = func_02012138(gameSystem);
            switch (func_02026454(gameComm)) {
            case 1:
            case 2:
                func_02026400(gameComm);
                break;
            }
        }
        return 1;
    }
    return 0;
}

int func_02187FD0(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work)
{
    if (func_02188B58(gameSystem, work->fieldMap) == 1) {
        return 1;
    }
    return 0;
}

int func_02187FE8(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work)
{
    func_021880A4(work->fieldMap);
    func_02012110(gameSystem, 0);
    func_020315D4(proc);
    func_020306F0(0x96);
    func_020306F0(0x92);
    func_020306F0(0x93);
    func_020306F0(0x89);
    func_020306F0(0x50);
    func_020306F0(0x70);
    func_020306F0(0x15);
    return 1;
}

FieldMap *func_02188030(struct GameSystem *gameSystem, int heapId)
{
    FieldMap *fieldMap = func_02030734(heapId, sizeof(FieldMap), 1, d_021DD9C0, 0x209);
    fieldMap->heapId = heapId;
    fieldMap->mainState = 0;
    fieldMap->gameSystem = gameSystem;
    fieldMap->gameData = func_020120F4(gameSystem);
    fieldMap->zoneId = func_02012AC8(func_020120F8(gameSystem));
    {
        int areaId = func_02013B38(fieldMap->zoneId);
        fieldMap->areaData = func_0201407C(heapId, areaId, func_0202E83C(gameSystem));
    }
    fieldMap->ctrlFuncs = func_02189BA8(fieldMap->zoneId);
    return fieldMap;
}

void func_021880A4(FieldMap *fieldMap)
{
    struct GameSystem *gameSystem = fieldMap->gameSystem;
    func_020140B4(fieldMap->areaData);
    func_020307B0(fieldMap);
    func_02012110(gameSystem, 0);
    func_020371AC(0, 0);
}

int func_021880C8(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    u16 heapId = fieldMap->heapId;
    func_020433E0((const struct DispVram *)d_021D3688);
    func_02188D5C(fieldMap);
    func_0204A48C((const struct Cfg *)d_021D3604, (u32)d_021D3688, 0x89);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02045088(heapId);
    func_0201DD60();
    func_02046440(0, 3, 0, 1, 0x1000, fieldMap->heapId, func_02188E50);
    func_02188EE4(fieldMap);
    fieldMap->g3dMapper = func_0218C9E8(fieldMap->heapId, func_02012984(fieldMap->gameData));
    fieldMap->vblankTcb = func_020056A0(func_02189108, fieldMap, 0);
    fieldMap->tcblWork = func_02030734(heapId, func_02030CB0(0x20), 0, d_021DD9C0, 0x26B);
    fieldMap->tcblSys = func_02030CBC(0x20, fieldMap->tcblWork);
    fieldMap->taskManager = func_021C6D10(0xA, fieldMap->heapId);
    fieldMap->vreq = func_021D317C(fieldMap->heapId);
    func_02034AC4((func_02013CC8(fieldMap->zoneId) == 1 || func_02013CE0(fieldMap->zoneId) == 1) ? (int)abs_id_19 : (int)abs_id_18);
    func_02035660(0x1E);
    return 1;
}

int func_021881D8(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    int busy = 1;
    switch (fieldMap->subSeq) {
    case 0: {
        struct FieldMsgBg *msgBg;
        func_0216447C(gameData, fieldMap->zoneId);
        msgBg = func_021901EC(fieldMap->heapId, fieldMap->g3dCamera);
        fieldMap->infoWindow = 0;
        fieldMap->msgBg = msgBg;
        fieldMap->placeName = func_021BC388(gameSystem, 0x93, msgBg);
        fieldMap->mapEff = func_021C7F70(func_02014470(func_02012B38(fieldMap->gameData)), fieldMap->heapId);
        fieldMap->camera = func_0218E018(func_02013BBC(fieldMap->zoneId), 0, fieldMap->g3dCamera, &fieldMap->nowPos, fieldMap->heapId);
        fieldMap->sceneArea = func_021AB5F4(fieldMap->heapId, fieldMap->camera, fieldMap);
        fieldMap->sceneAreaLoader = func_021AB7E4(fieldMap->heapId);
        break;
    }
    case 1: {
        void *buildModel;
        void *palTable;
        fieldMap->nogridMapper = func_021BB1F4(fieldMap->heapId, fieldMap->camera, fieldMap->sceneArea, fieldMap->sceneAreaLoader);
        fieldMap->palaceSys = func_021D33A8(fieldMap->heapId, gameSystem, fieldMap, fieldMap->zoneId);
        buildModel = func_0218DC6C(fieldMap->g3dMapper);
        func_02189B30(fieldMap->zoneId, fieldMap->areaData, &fieldMap->mapperParam, func_02012974(fieldMap->gameData));
        func_02012138(fieldMap->gameSystem);
        palTable = func_021D33F8(fieldMap->palaceSys);
        func_0218B8AC(buildModel, fieldMap->zoneId, fieldMap->areaData, palTable);
        func_021C6534(fieldMap->g3dObjCtrl, palTable);
        func_02189614(gameData, fieldMap, fieldMap->zoneId);
        break;
    }
    case 2: {
        int specialKind;
        func_02014110(&fieldMap->location, fieldMap->zoneId, 0, 0, 0, fieldMap->nowPos.x, fieldMap->nowPos.y, fieldMap->nowPos.z);
        func_02012138(fieldMap->gameSystem);
        func_0218CEE4(fieldMap->g3dMapper, &fieldMap->mapperParam, func_021D33F8(fieldMap->palaceSys));
        specialKind = func_02013C9C(fieldMap->zoneId);
        if (specialKind != -1) {
            func_021BB2F8(fieldMap->nogridMapper, specialKind, fieldMap->heapId);
        }
        fieldMap->projDepthOffset = func_02189ACC(fieldMap->zoneId);
        func_021895E8(fieldMap, (u16)fieldMap->zoneId, (u16)fieldMap->heapId);
        break;
    }
    case 3:
        func_02189204(fieldMap);
        fieldMap->effect = func_021ABD50(fieldMap, 0x18, fieldMap->heapId);
        func_021ABF68(fieldMap->effect, 0x5e);
        func_021AC1EC(fieldMap->effect, func_021D33F8(fieldMap->palaceSys));
        func_021ABE30(fieldMap->effect, d_021D8F10, d_021D8F00);
        if (func_02013CC8(fieldMap->zoneId) == 1 || func_02013CE0(fieldMap->zoneId) == 1) {
            fieldMap->unionEff = func_0217F8C0(fieldMap->heapId);
        }
        break;
    case 4: {
        struct PlayerWork *playerWork;
        int dirType;
        VecFx32 *playerPos;
        int value;
        int season;
        playerWork = func_020120F8(gameSystem);
        dirType = func_02012AE4(playerWork);
        playerPos = (VecFx32 *)((u8 *)playerWork + 4);
        if (func_02012B28(playerWork) == 1 && func_02013C20(fieldMap->zoneId) == 0) {
            func_02012B2C(playerWork, 0);
        }
        fieldMap->player = func_021A2E50(playerWork, fieldMap, playerPos, func_02008550(func_02012944(gameData)), fieldMap->heapId);
        fieldMap->nowPos = *playerPos;
        fieldMap->ctrlFuncs->create(fieldMap, &fieldMap->nowPos, dirType);
        func_0218D158(fieldMap->g3dMapper, &fieldMap->nowPos);
        func_02189758(&fieldMap->commonWork);
        fieldMap->expObj = func_021BE2A8(0x3c, 0x23, fieldMap->heapId);
        func_02189154(fieldMap->areaData, func_02188C9C(fieldMap));
        fieldMap->fog = func_021A0104(fieldMap->heapId);
        fieldMap->zoneFog = func_021A02C4(fieldMap->heapId);
        value = func_02013EEC(fieldMap->zoneId);
        func_021A0338(fieldMap->zoneFog, value, func_02013F2C(fieldMap->zoneId), 1);
        value = func_020140DC(fieldMap->areaData);
        season = func_0203F4FC();
        fieldMap->light = func_021A03D0(value, season, func_0202E83C(gameSystem), fieldMap->fog, fieldMap->g3dLight, fieldMap->heapId);
        value = func_02012A30(fieldMap->gameData);
        fieldMap->weather = func_021A19E8(fieldMap->camera, fieldMap->light, fieldMap->fog, fieldMap->zoneFog, value, func_0202E83C(gameSystem), 0x92);
        func_021A1B74(fieldMap->weather, (u16)((int)func_02012994(fieldMap->gameData)), 0x92);
        func_021BE1DC(fieldMap);
        break;
    }
    case 5:
        fieldMap->subscreen = func_021A0CF4(fieldMap->heapId, fieldMap, func_020129AC(gameData));
        break;
    case 6:
        fieldMap->encount = func_021A9ED8(fieldMap);
        func_02026388(func_02012138(gameSystem), fieldMap);
        fieldMap->mapFunc = func_021BB890(fieldMap, fieldMap->heapId, 0x20);
        fieldMap->particle = func_021C1A08(0x50);
        fieldMap->fld3dCi = func_021C1AF4(0x50, fieldMap->particle);
        fieldMap->encEff = func_021CF45C(fieldMap->heapId, fieldMap);
        fieldMap->sodateya = func_021C31D4(fieldMap->heapId, fieldMap, func_0200BDB0(func_02012EBC(fieldMap->gameData)));
        func_02189684(fieldMap, fieldMap->zoneId);
        busy = 0;
        break;
    }
    (fieldMap->subSeq)++;
    fieldMap->drawMode = 0;
    return busy == 0;
}

int func_021885E8(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    switch (fieldMap->subSeq) {
    case 0:
        func_0218CA78(fieldMap->g3dMapper);
        if (fieldMap->mmdlSys != 0) {
            do {
                func_0216CD64(fieldMap->mmdlSys);
                func_0219C624(fieldMap->mmdlSys);
            } while (func_0219C630(fieldMap->mmdlSys) == 1);
        }
        while (func_021A1B50(fieldMap->weather) != 0)
            func_021A1AF4(fieldMap->weather, 0x92);
        func_02189004(fieldMap);
        func_02189084(fieldMap);
        func_021890AC(fieldMap);
        func_0204A600();
        if (fieldMap->msgBg != 0)
            func_021903E0(fieldMap->msgBg);
        func_021ABE04(fieldMap->effect);
        func_021BB948(fieldMap->mapFunc);
        fieldMap->subSeq++;
    case 1:
        if (func_02014460(func_02012B38(fieldMap->gameData)) == 1
            && func_02189B04(fieldMap->zoneId) == 1
            && func_02005C64() != 0)
            return 0;
        if (func_02014458(func_02012B38(fieldMap->gameData)) != 0) {
            func_02158AC8(fieldMap->gameSystem, fieldMap->heapId);
            func_02014454(func_02012B38(fieldMap->gameData), 0);
        } else {
            func_02158AD4(fieldMap->gameSystem, fieldMap->heapId);
        }
        func_0201445C(func_02012B38(fieldMap->gameData), 0);
        func_0218CA78(fieldMap->g3dMapper);
        if (func_02013CC8(fieldMap->zoneId) == 1 || func_02013CE0(fieldMap->zoneId) == 1)
            func_0201209C(gameSystem, func_0218A0E4, fieldMap);
        else if (func_02188CF0(fieldMap) == 1)
            func_0201209C(gameSystem, func_0218A240, fieldMap);
        else if (func_02188CF0(fieldMap) == 2)
            func_0201209C(gameSystem, func_0218A4BC, fieldMap);
        else
            func_0201209C(gameSystem, func_0218A074, fieldMap);
        fieldMap->mainState = 1;
        func_020129DC(func_020120F4(gameSystem), 1);
        break;
    }
    return 1;
}

int func_02188758(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    if (func_02012104(fieldMap->gameSystem) == 0)
        func_0201447C(func_02012B38(fieldMap->gameData), 0);
    if (func_02012E40(fieldMap->gameData) != 0)
        return 0;
    if (fieldMap->updateStopped != 0) {
        func_021888C8(fieldMap);
        func_0204A600();
        return 0;
    }
    func_02035648();
    func_021892CC(fieldMap);
    if (func_020120D8(gameSystem) == 0) {
        fieldMap->ctrlFuncs->main(fieldMap, &fieldMap->nowPos);
        func_02168EEC(fieldMap->gameData);
    }
    if (fieldMap->placeName != 0)
        func_021BC484(fieldMap->placeName);
    func_021C7FAC(fieldMap->mapEff);
    func_021A2EB8(fieldMap->player);
    if (func_02013CC8(fieldMap->zoneId) == 1 || func_02013CE0(fieldMap->zoneId) == 1)
        func_021737A4(func_02012138(gameSystem), fieldMap);
    else
        func_0217AE20(fieldMap, fieldMap->gameSystem, fieldMap->player);
    func_021A0D68(fieldMap->subscreen);
    if (fieldMap->mmdlSys != 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_0216CD64(fieldMap->mmdlSys);
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    func_021BE258(fieldMap);
    func_021ABE04(fieldMap->effect);
    if (fieldMap->unionEff != 0)
        func_0217F914(fieldMap->unionEff);
    func_021BB948(fieldMap->mapFunc);
    if (fieldMap->msgBg != 0)
        func_021903E0(fieldMap->msgBg);
    func_02030D28(fieldMap->tcblSys);
    func_021C6D90(fieldMap->taskManager);
    if (fieldMap->targetPos != 0)
        fieldMap->nowPos = *fieldMap->targetPos;
    func_0218D158(fieldMap->g3dMapper, &fieldMap->nowPos);
    func_02189004(fieldMap);
    func_021C8660(*func_02012ED0(fieldMap->gameData));
    func_0204A600();
    func_021888C8(fieldMap);
    return 0;
}

void func_021888C8(FieldMap *fieldMap)
{
    volatile u16 *regPowerCnt = (volatile u16 *)0x04000204;
    func_02047CE4();
    func_0218E104(fieldMap->camera, (u16)func_0203630C());
    fieldMap->cameraPitchScale = func_02189A80(fieldMap);
    *regPowerCnt = *regPowerCnt & 0xFFFF7FFF;
    func_02189084(fieldMap);
    *regPowerCnt = *regPowerCnt | 0x8000;
}

int func_02188910(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    if (func_02012E40(fieldMap->gameData) != 0) {
        func_020129F0(func_020120F4(gameSystem));
        return 0;
    }
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0218CC34(fieldMap->g3dMapper);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021A0E58(fieldMap->subscreen);
    if (fieldMap->msgBg != 0)
        func_021903E0(fieldMap->msgBg);
    if (fieldMap->placeName != 0)
        func_021BC4F0(fieldMap->placeName);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021890AC(fieldMap);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_020129F0(func_020120F4(gameSystem));
    return 0;
}

int func_02188990(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    func_021CF480(fieldMap->encEff);
    func_021C1C04(fieldMap->fld3dCi);
    func_021C1AD0(fieldMap->particle);
    func_0201209C(gameSystem, 0, 0);
    func_021A2EB8(fieldMap->player);
    func_021BB90C(fieldMap->mapFunc);
    func_020263B0(func_02012138(gameSystem), fieldMap);
    if (fieldMap->placeName != 0)
        func_021BC424(fieldMap->placeName);
    func_021BE218(fieldMap);
    func_021BE2E0(fieldMap->expObj);
    func_021A9F28(fieldMap->encount);
    func_020129B8(func_020120F4(gameSystem), func_021A0D44(fieldMap->subscreen));
    func_021ABDE8(fieldMap->effect);
    if (fieldMap->unionEff != 0) {
        func_0217F8EC(fieldMap->unionEff);
        fieldMap->unionEff = 0;
    }
    func_021A1AAC(fieldMap->weather);
    fieldMap->weather = 0;
    func_021A0448(fieldMap->light);
    func_021A02F4(fieldMap->zoneFog);
    func_021A0138(fieldMap->fog);
    func_021D33E0(fieldMap->palaceSys);
    func_021BB240(fieldMap->nogridMapper);
    func_021AB81C(fieldMap->sceneAreaLoader);
    func_021AB624(fieldMap->sceneArea);
    func_0218E0E4(fieldMap->camera);
    fieldMap->ctrlFuncs->destroy(fieldMap);
    func_021895DC(fieldMap);
    func_021892B4(fieldMap);
    func_021A2E90(fieldMap->player);
    func_0218D05C(fieldMap->g3dMapper);
    if (fieldMap->infoWindow != 0)
        func_02190728(fieldMap->infoWindow);
    if (fieldMap->msgBg != 0)
        func_021902BC(fieldMap->msgBg);
    func_020129DC(func_020120F4(gameSystem), 0);
    func_02035660(0x3C);
    func_021C31FC(fieldMap->sodateya);
    func_021C7F9C(fieldMap->mapEff);
    return 1;
}

int func_02188AD4(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    func_02030DA4(fieldMap->tcblSys);
    func_020307B0(fieldMap->tcblWork);
    func_021D31A4(fieldMap->vreq);
    fieldMap->vreq = 0;
    func_021C6D5C(fieldMap->taskManager);
    func_02030EAC(fieldMap->vblankTcb);
    func_0218CA4C(fieldMap->g3dMapper);
    func_021890C8(fieldMap);
    func_0204A5AC();
    func_020450C8();
    func_02188E38(fieldMap);
    if (func_02013CC8(fieldMap->zoneId) == 1 || func_02013CE0(fieldMap->zoneId) == 1)
        func_02034A5C((s32)abs_id_13);
    else
        func_02034A5C((s32)abs_id_12);
    return 2;
}

int func_02188B58(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    u32 frameCount = fieldMap->frameCount;
    s32 result = 0;
    FieldMapSeqFunc seqFunc;
    FieldMapSeqFunc *row;
    fieldMap->frameCount = frameCount + 1;
    row = data_021D36B8[fieldMap->seqNo];
    seqFunc = row[fieldMap->halfFrame];
    if (seqFunc != 0)
        result = seqFunc(gameSystem, fieldMap);
    switch (result) {
    case 0:
        fieldMap->halfFrame = (fieldMap->halfFrame == 0);
        break;
    case 1:
        fieldMap->seqNo = fieldMap->seqNo + 1;
        fieldMap->subSeq = 0;
        fieldMap->halfFrame = 0;
        break;
    case 2:
        return 1;
    }
    return 0;
}

void func_02188BD8(FieldMap *fieldMap)
{
    fieldMap->mainState = 2;
    fieldMap->seqNo = 4;
}

int func_02188BE8(FieldMap *fieldMap)
{
    if (fieldMap->mainState == 1) {
        return 1;
    }
    return 0;
}

u32 func_02188BF8(FieldMap *fieldMap)
{
    u32 handled = 0;
    u32 request = func_021A3098(fieldMap->player);

    if (request == 1) {
        handled = 1;
        func_021A2F48(fieldMap->player, 1);
    } else if (request == 0) {
        handled = 1;
        func_020061E4(0x55F);
        func_021A2F48(fieldMap->player, 2);
        func_02008DF0(func_02012F2C(fieldMap->gameData), 3);
    }
    if (handled == 1)
        func_021A2F54(fieldMap->player);
    return handled;
}

struct FieldMsgBg *func_02188C54(FieldMap *fieldMap)
{
    return fieldMap->msgBg;
}

struct FieldCamera *func_02188C58(FieldMap *fieldMap)
{
    return fieldMap->camera;
}

struct FieldNogridMapper *func_02188C5C(FieldMap *fieldMap)
{
    return fieldMap->nogridMapper;
}

struct FieldLight *func_02188C60(FieldMap *fieldMap)
{
    return fieldMap->light;
}

struct FieldFog *func_02188C64(FieldMap *fieldMap)
{
    return fieldMap->fog;
}

struct FieldZoneFog *func_02188C68(FieldMap *fieldMap)
{
    return fieldMap->zoneFog;
}

struct WeatherSys *func_02188C6C(FieldMap *fieldMap)
{
    return fieldMap->weather;
}

int func_02188C70(FieldMap *fieldMap, int switchId)
{
    return func_0202C794(fieldMap->gameSystem, switchId);
}

struct MmdlSys *func_02188C7C(FieldMap *fieldMap)
{
    return fieldMap->mmdlSys;
}

struct GameSystem *func_02188C80(FieldMap *fieldMap)
{
    return fieldMap->gameSystem;
}

u16 func_02188C84(FieldMap *fieldMap)
{
    return fieldMap->heapId;
}

struct BbActSys *func_02188C88(FieldMap *fieldMap)
{
    return fieldMap->effectBbdAct;
}

struct BbActSys *func_02188C90(FieldMap *fieldMap)
{
    return fieldMap->groundBbdAct;
}

struct FieldG3dMapper *func_02188C98(FieldMap *fieldMap)
{
    return fieldMap->g3dMapper;
}

u16 func_02188C9C(FieldMap *fieldMap)
{
    return fieldMap->location.zoneId;
}

void *func_02188CA4(FieldMap *fieldMap)
{
    return fieldMap->ctrlWork;
}

void func_02188CAC(FieldMap *fieldMap, void *ctrlWork)
{
    fieldMap->ctrlWork = ctrlWork;
}

struct FieldPlayer *func_02188CB4(FieldMap *fieldMap)
{
    return fieldMap->player;
}

int func_02188CBC(FieldMap *fieldMap)
{
    if (fieldMap->player != 0) {
        return 1;
    }
    return 0;
}

struct FieldSubscreen *func_02188CCC(FieldMap *fieldMap)
{
    return fieldMap->subscreen;
}

struct FieldEffectCont *func_02188CD0(FieldMap *fieldMap)
{
    return fieldMap->effect;
}

struct FieldG3dObjCtrl *func_02188CD8(FieldMap *fieldMap)
{
    return fieldMap->g3dObjCtrl;
}

struct UnionEff *func_02188CE0(FieldMap *fieldMap)
{
    return fieldMap->unionEff;
}

struct FieldEncount *func_02188CE8(FieldMap *fieldMap)
{
    return fieldMap->encount;
}

unsigned int func_02188CF0(FieldMap *fieldMap)
{
    return fieldMap->ctrlFuncs->ctrlType;
}

u32 func_02188CFC(FieldMap *fieldMap)
{
    u32 moveKind;
    u32 kind = data_021D35A8[fieldMap->ctrlFuncs->ctrlType];
    if (kind == 2)
        kind = func_021A6DC0(fieldMap->ctrlWork);
    moveKind = kind;
    return moveKind;
}

struct FieldPlaceName *func_02188D20(FieldMap *fieldMap)
{
    return fieldMap->placeName;
}

struct FieldmapFunc *func_02188D24(FieldMap *fieldMap)
{
    return fieldMap->mapFunc;
}

struct FldExpObjCnt *func_02188D2C(FieldMap *fieldMap)
{
    return fieldMap->expObj;
}

struct TcblSys *func_02188D30(FieldMap *fieldMap)
{
    return fieldMap->tcblSys;
}

struct FieldTaskManager *func_02188D38(FieldMap *fieldMap)
{
    return fieldMap->taskManager;
}

void func_02188D40(FieldMap *fieldMap, const VecFx32 *targetPos)
{
    fieldMap->targetPos = targetPos;
}

struct FieldMsgWin *func_02188D48(FieldMap *fieldMap)
{
    return fieldMap->infoWindow;
}

void func_02188D4C(FieldMap *fieldMap, struct FieldMsgWin *infoWindow)
{
    fieldMap->infoWindow = infoWindow;
}

struct Sodateya *func_02188D50(FieldMap *fieldMap)
{
    return fieldMap->sodateya;
}

struct AreaData *func_02188D58(FieldMap *fieldMap)
{
    return fieldMap->areaData;
}

void func_02188D5C(FieldMap *fieldMap)
{
    func_0203F8F4(fieldMap->heapId);
    func_02040E78(0, d_021D3620, 0x20, 0);
    func_02040E78(4, d_021D3620, 0x20, 0);
    func_0204363C(1);
    func_0204361C();
    REG_DISPCNT &= ~0xE000;
}

void func_02188DA0(void)
{
    func_0203FC28(&d_021D35F4);
}

void func_02188DB0(FieldMap *fieldMap)
{
    u32 affineMtx[4];

    func_02051E74((struct Mtx22 *)affineMtx, 0, (const void *)0x1000, (const void *)0x1000, 0);
    func_0207D59C(0x04000020, affineMtx, 0, 0, 0, 0);
    func_0204044C(3);
    func_02190270(fieldMap->msgBg);
}

void func_02188DF0(FieldMap *fieldMap)
{
    u32 affineMtx[4];

    func_02051E74((struct Mtx22 *)affineMtx, 0, (const void *)0x1000, (const void *)0x1000, 0);
    func_0207D59C(0x04000020, affineMtx, 0, 0, 0, 0);
    func_0204044C(3);
    func_0219027C(fieldMap->msgBg);
}

struct FldVReq *func_02188E30(FieldMap *fieldMap)
{
    return fieldMap->vreq;
}

int func_02188E38(FieldMap *fieldMap)
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

void func_02188EE4(FieldMap *fieldMap)
{
    VecFx32 groundScale;
    VecFx32 cameraUp;
    u8 groundDrawFlag;
    void *board;
    u16 heapId;

    fieldMap->mmdlBbdAct = func_0204FE94(0x40, 0x80, func_02189140, fieldMap->heapId);
    board = func_02050080(fieldMap->mmdlBbdAct);
    func_0204EDBC(board, 2);
    func_0204EDC4(board, 0, -0xA00);
    fieldMap->effectBbdAct = func_0204FE94(0x3A, 0x50, func_02189140, fieldMap->heapId);
    fieldMap->groundBbdAct = func_0204FE94(0x1E, 0x28, func_02189140, fieldMap->heapId);
    board = func_02050080(fieldMap->groundBbdAct);
    groundScale = d_021D36F4;
    func_0204ED70(board, &groundScale);
    groundDrawFlag = 0;
    func_0204EDB0(board, &groundDrawFlag);
    func_021891C0(fieldMap);
    fieldMap->g3dObjCtrl = func_021C63AC(fieldMap->heapId, 0x40, 0x40);
    heapId = fieldMap->heapId;
    cameraUp = d_021D36E8;
    fieldMap->g3dCamera = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                        &d_021D35C0, &cameraUp, &d_021D35CC, heapId);
    fieldMap->g3dLight = func_02048BC4((const struct LightSet *)d_021D35AC, fieldMap->heapId);
    func_02048AD0(fieldMap->g3dCamera);
    func_02048C58(fieldMap->g3dLight);
}

void func_02189004(FieldMap *fieldMap)
{
    u32 mapperBusy;

    func_020504D8(fieldMap->mmdlBbdAct);
    func_020504D8(fieldMap->effectBbdAct);
    func_020504D8(fieldMap->groundBbdAct);
    func_021BB36C(fieldMap->nogridMapper);
    func_021AB660(fieldMap->sceneArea, &fieldMap->nowPos);
    func_021A030C(fieldMap->zoneFog, fieldMap->heapId);
    func_021A1AF4(fieldMap->weather, 0x92);
    func_021A0140(fieldMap->fog);
    func_021A0458(fieldMap->light, func_0203F4FC());
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    mapperBusy = func_0218CB34(fieldMap->g3dMapper);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    if (mapperBusy != 0)
        func_0203D12C(2);
}

void func_02189084(FieldMap *fieldMap)
{
    FieldMapDrawFunc drawFunc;
    func_02047964();
    func_020479D8();
    drawFunc = d_021D35D8[fieldMap->drawMode];
    if (drawFunc != 0)
        drawFunc(fieldMap);
}

void func_021890AC(FieldMap *fieldMap)
{
    func_02047970(d_021D35B4[fieldMap->drawMode](fieldMap));
}

int func_021890C8(FieldMap *fieldMap)
{
    func_02048C4C(fieldMap->g3dLight);
    func_02048AC4(fieldMap->g3dCamera);
    func_0204FFFC(fieldMap->mmdlBbdAct);
    func_0204FFFC(fieldMap->effectBbdAct);
    func_0204FFFC(fieldMap->groundBbdAct);
    return func_021C6400(fieldMap->g3dObjCtrl);
}

void func_02189108(struct GFL_TCB *tcb, void *work)
{
    FieldMap *fieldMap = work;
    if (func_02005C8C() == 0) {
        if (fieldMap->mmdlSys != 0)
            func_0216CD78(fieldMap->mmdlSys);
        if (fieldMap->g3dObjCtrl != 0)
            func_021C6470(fieldMap->g3dObjCtrl);
    }
    func_0204A648();
    if (fieldMap->vreq != 0)
        func_021D31AC(fieldMap->vreq);
}

void func_02189140(int vramTransfer, int destAddr, void *src, int size)
{
    func_02061CA4((void *)(vramTransfer == 0 ? B_FALSE : B_TRUE), destAddr, (u32)src, size);
}

void func_02189154(struct AreaData *areaData, u32 zoneId)
{
    u32 edgeMarkType = func_020140E0(areaData);

    if (edgeMarkType == 0xFF) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
        return;
    }
    if (func_02013DB8(zoneId) != 0)
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    else
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
    func_02048F4C(data_021EE700, 0xF, edgeMarkType);
    data_021EE700b[7] = 0x4210;
    func_0207DCF8(data_021EE700);
}

void func_021891C0(FieldMap *fieldMap)
{
    u16 colorHeapId = (fieldMap->heapId & 0x7FFF) | 0x8000;
    void *bbdColor;
    u32 colorId;

    colorId = func_020140E4(fieldMap->areaData);
    bbdColor = func_021CD1C8(colorHeapId);
    func_021CD204(bbdColor, colorId);
    func_021CD214(bbdColor, func_02050080(fieldMap->mmdlBbdAct));
    func_021CD1F0(bbdColor);
}

void func_02189204(FieldMap *fieldMap)
{
    struct GameData *gameData;
    u32 zoneId;
    struct MmdlSys *mmdlSys;
    u32 sex;

    gameData = func_020120F4(fieldMap->gameSystem);
    mmdlSys = func_02012964(gameData);
    fieldMap->mmdlSys = mmdlSys;
    func_0216CCDC(mmdlSys, fieldMap->heapId, gameData, fieldMap, fieldMap->g3dMapper, fieldMap->nogridMapper);
    func_0219C554(fieldMap->mmdlSys, fieldMap->mmdlBbdAct, 0x20);
    func_0219C680(fieldMap->mmdlSys);
    zoneId = fieldMap->location.zoneId;
    if (func_02013CC8(zoneId) == 0 && func_02013CE0(zoneId) == 0) {
        sex = func_0217C0A8(func_02012138(fieldMap->gameSystem));
    } else {
        sex = func_02008550(func_02012944(gameData));
    }
    func_0219C658(mmdlSys, func_021A31A4(sex, 0));
    func_0219D448(fieldMap->mmdlSys, fieldMap->g3dObjCtrl);
    func_0216CDB8(fieldMap->mmdlSys, func_0218ED50(fieldMap->camera));
    func_0216D2F8(fieldMap->mmdlSys);
    func_0216D974(mmdlSys, func_02189AE8(fieldMap->zoneId));
}

int func_021892B4(FieldMap *fieldMap)
{
    func_0216D2AC(fieldMap->mmdlSys);
    func_0216CD50(fieldMap->mmdlSys);
    fieldMap->mmdlSys = 0;
    return 0;
}

u32 func_021892CC(FieldMap *fieldMap)
{
    void *eventData;

    if (func_0218932C(fieldMap) == 1 && func_02189370(fieldMap) == 1) {
        func_021893C0(fieldMap);
        return 1;
    }
    eventData = func_02012844(fieldMap->gameData);
    if (func_02162458(eventData) == 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_02162438(eventData, fieldMap->location.zoneId, func_02012984(fieldMap->gameData));
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    return 0;
}

int func_0218932C(FieldMap *fieldMap)
{
    VecFx32 lastPos;
    FieldMapLocation *location;
    VecFx32 *playerPos;

    location = &fieldMap->location;
    playerPos = func_02012AA0(func_020127A4(func_020120F4(fieldMap->gameSystem)));
    func_020141E0(location, &lastPos);
    if (playerPos->x != lastPos.x || playerPos->z != lastPos.z) {
        func_020141F0(location, playerPos);
        return 1;
    }
    return 0;
}

u32 func_02189370(FieldMap *fieldMap)
{
    VecFx32 pos;
    FieldMapLocation *location;
    struct MapMatrix *mapMatrix;
    int zoneId;

    location = &fieldMap->location;
    mapMatrix = func_02012974(fieldMap->gameData);
    func_020141E0(location, &pos);
    if (func_02159C48(mapMatrix, pos.x, pos.z) == 1) {
        zoneId = func_02159BD4(mapMatrix, pos.x, pos.z);
        if (zoneId != 0xFFFF && zoneId != (s16)location->zoneId)
            return 1;
    }
    return 0;
}

void func_021893C0(FieldMap *fieldMap)
{
    FieldMapLocation *location = &fieldMap->location;
    struct GameData *gameData;
    u32 zoneId;
    VecFx32 pos;
    void *eventData;
    struct MmdlSys *mmdlSys;
    struct MapMatrix *mapMatrix;

    gameData = func_020120F4(fieldMap->gameSystem);
    eventData = func_02012844(gameData);
    mmdlSys = fieldMap->mmdlSys;
    mapMatrix = func_02012974(fieldMap->gameData);
    func_0203D12C(2);
    func_021AA8EC(fieldMap->encount);
    func_020141E0(location, &pos);
    zoneId = func_02159BD4(mapMatrix, pos.x, pos.z);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_0216DF1C(mmdlSys);
    func_021623DC(eventData);
    func_0216242C(eventData, zoneId, func_02012984(gameData));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_021643AC(gameData, fieldMap);
    func_02189518(fieldMap, zoneId);
    func_0218958C(fieldMap, zoneId);
    func_02189560(fieldMap, zoneId);
    func_021895D0(fieldMap, zoneId);
    func_021895BC(gameData, zoneId);
    func_02189684(fieldMap, zoneId);
    if (fieldMap->placeName != 0 && func_020120D8(fieldMap->gameSystem) == 0)
        func_021BC550(fieldMap->placeName, zoneId);
    location->zoneId = (s16)zoneId;
    func_0202735C((u16)zoneId, gameData);
    func_0215A014(gameData, zoneId);
    func_02158AE0(fieldMap->gameSystem, (void *)4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    func_021894E0(gameData, mmdlSys, eventData, zoneId);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    func_0215874C(func_02012138(fieldMap->gameSystem));
}

void func_021894E0(struct GameData *gameData, struct MmdlSys *mmdlSys, void *eventData, int zoneId)
{
    int npcCount = func_02162744(eventData);
    int eventWork;
    if (npcCount != 0) {
        eventWork = func_0201296C(gameData);
        func_0216CEAC(mmdlSys, func_02162740(eventData), zoneId, npcCount, eventWork);
    }
}

void func_02189518(FieldMap *fieldMap, unsigned int zoneId)
{
    struct GameData *gameData;
    void *issSys;
    void *bgmInfo;
    int objCode;

    gameData = func_020120F4(fieldMap->gameSystem);
    issSys = (void *)func_02012134(fieldMap->gameSystem);
    bgmInfo = (void *)func_02012A30(gameData);
    objCode = func_02012B28(func_020127A4(gameData));
    func_0202B544((u32)issSys, zoneId);
    if (objCode != 2)
        func_02029CF0(bgmInfo, gameData, zoneId);
}

void func_02189560(FieldMap *fieldMap, int zoneId)
{
    struct WeatherSys *weather = func_02188C6C(fieldMap);
    unsigned short weatherId;
    func_0202C83C(fieldMap->gameSystem, zoneId);
    weatherId = (int)func_02012994(fieldMap->gameData);
    if (weatherId != 0xF)
        func_021A1BDC(weather, weatherId);
}

void func_0218958C(FieldMap *fieldMap, int zoneId)
{
    int fogId;
    func_021A0358(func_02188C68(fieldMap));
    fogId = (int)func_02013EEC((unsigned short)zoneId);
    func_021A0338(fieldMap->zoneFog, fogId, func_02013F2C(zoneId), 1);
}

int func_021895BC(struct GameData *gameData, u32 zoneId)
{
    return (int)func_02012AC4(func_020127A4(gameData), ((zoneId << 16) >> 16));
}

void func_021895D0(FieldMap *fieldMap, u32 zoneId)
{
    func_021895E8(fieldMap, zoneId, fieldMap->heapId);
}

FieldMap *func_021895DC(FieldMap *fieldMap)
{
    fieldMap->ctrlWork = 0;
    return fieldMap;
}

void func_021895E8(FieldMap *fieldMap, int zoneId, int heapId)
{
    int cameraAreaId = func_02013BD0(zoneId);
    if (cameraAreaId != 0xFFFF)
        func_0218F14C(fieldMap->camera, cameraAreaId, heapId);
    else
        func_0218F134(fieldMap->camera);
}

void func_02189614(struct GameData *gameData, FieldMap *fieldMap, u16 zoneId)
{
    struct FieldStatus *fieldStatus;
    int mapMode;
    void *wfbcData;
    void *buildModel;

    fieldStatus = func_02012B38(gameData);
    if (func_02013DD0(fieldMap->zoneId) != 0) {
        mapMode = func_0201444C(fieldStatus);
        if (mapMode == 0)
            wfbcData = func_020127C4(fieldMap->gameData);
        else
            wfbcData = func_020127D0(fieldMap->gameData, 0);
        func_0218DC74(fieldMap->g3dMapper, wfbcData, mapMode);
        buildModel = func_0218DC70(fieldMap->g3dMapper);
        func_021939C0(buildModel, func_02012844(gameData), mapMode, fieldMap->heapId);
        func_02193ABC(buildModel, fieldMap->camera, fieldMap->heapId);
        func_02193AFC(buildModel, func_02012964(fieldMap->gameData));
    }
}

void func_02189684(FieldMap *fieldMap, unsigned int zoneId)
{
    int sceneId;
    int areaData;
    int areaCount;

    sceneId = func_02013FA8(zoneId);
    if (sceneId != 0xFFFF) {
        func_021AB650(fieldMap->sceneArea);
        func_021AB868(fieldMap->sceneAreaLoader);
        func_021AB840(fieldMap->sceneAreaLoader, 1, sceneId, 0x96);
        areaData = func_021AB880(fieldMap->sceneAreaLoader);
        areaCount = func_021AB884(fieldMap->sceneAreaLoader);
        func_021AB634(fieldMap->sceneArea, areaData, areaCount, func_021AB888(fieldMap->sceneAreaLoader));
        return;
    }
    if (func_02013C80((u16)zoneId) == 0) {
        func_021AB650(fieldMap->sceneArea);
        func_021AB868(fieldMap->sceneAreaLoader);
    }
}

int func_021896F4(struct GameComm *gameComm)
{
    int commKind = func_02026454(gameComm);
    switch (commKind) {
    case 0:
        if (func_0200FB24() != 0)
            commKind = func_0202647C(gameComm);
        return commKind;
    case 1:
    case 2:
    case 5:
        return commKind;
    }
    return 2;
}

int func_02189734(struct GameComm *gameComm)
{
    if (func_02026454(gameComm) == 0) {
        return 1;
    }
    if (func_02026460(gameComm) == 0) {
        func_02026400(gameComm);
    }
    return 0;
}

void func_02189758(FieldMapCommonWork *commonWork)
{
    commonWork->id = -1;
    commonWork->buf = 0;
}

void *func_02189764(FieldMap *fieldMap, int id, int heapId, int size)
{
    FieldMapCommonWork *commonWork = &fieldMap->commonWork;
    if (id == -1)
        return 0;
    if (commonWork->id != -1)
        return 0;
    commonWork->id = id;
    return commonWork->buf = func_02030734(heapId, size, 1, d_021DD9C0, 0xD7C);
}

void func_021897A0(FieldMap *fieldMap, int id)
{
    FieldMapCommonWork *commonWork = &fieldMap->commonWork;
    if (id != -1) {
        func_020307B0(commonWork->buf);
        commonWork->id = -1;
    }
}

void *func_021897BC(FieldMap *fieldMap, int id)
{
    FieldMapCommonWork *commonWork = &fieldMap->commonWork;
    if (id == -1)
        return 0;
    if (id != commonWork->id)
        return 0;
    return commonWork->buf;
}

int func_021897DC(FieldMap *fieldMap, u32 fogEnable, u32 fogSlope, u32 fogOffset)
{
    func_021A0170(fieldMap->fog, fogEnable, fogSlope, fogOffset);
    func_021A0568(fieldMap->light, 0);
    func_02048AD0(fieldMap->g3dCamera);
    func_02048C58(fieldMap->g3dLight);
    return func_0218CC64(fieldMap->g3dMapper, fieldMap->g3dCamera, 0);
}

void func_02189810(FieldMap *fieldMap)
{
    MtxFx44 savedProj;
    MtxFx44 proj;

    if (fieldMap->msgBg != 0)
        func_0219047C(fieldMap->msgBg);
    func_0218CC64(fieldMap->g3dMapper, fieldMap->g3dCamera, 1);
    func_021C7FB4(fieldMap->mapEff);
    savedProj = g_02148B54;
    proj = savedProj;
    proj.m[3][2] += FX_MUL(proj.m[2][2], fieldMap->projDepthOffset);
    MIi_CpuCopyFast(&proj, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206DB80(func_0206A854());
    func_021ABE0C(fieldMap->effect);
    func_021C64E0(fieldMap->g3dObjCtrl);
    func_02050790(fieldMap->mmdlBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    func_02050790(fieldMap->groundBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    if (fieldMap->unionEff != 0)
        func_0217F928(fieldMap->unionEff);
    proj = savedProj;
    proj.m[3][2] += FX_MUL(proj.m[2][2], fieldMap->projDepthOffset / 2);
    MIi_CpuCopyFast(&proj, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206DB80(func_0206A854());
    func_02050790(fieldMap->effectBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    MIi_CpuCopyFast(&savedProj, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_021BB954(fieldMap->mapFunc);
    func_021A1B38(fieldMap->weather);
    func_021BE4F8(fieldMap->expObj);
    func_021C1AEC();
    func_021C1C4C(fieldMap->fld3dCi);
}

void func_02189998(FieldMap *fieldMap)
{
    func_0207DD24(0, 0, 0x7FFF, 0, 0);
    func_021C1AEC();
    func_021C1C4C(fieldMap->fld3dCi);
}

void func_021899C4(FieldMap *fieldMap)
{
    func_0207DD24(0x4210, 0x1F, 0x7FFF, 0, 0);
    func_021CF520(fieldMap->encEff);
}

int func_021899F0(FieldMap *fieldMap)
{
    return fieldMap->drawMode;
}

void func_021899F8(FieldMap *fieldMap, int drawMode)
{
    fieldMap->drawMode = drawMode;
}

struct Fld3dCi *func_02189A00(FieldMap *fieldMap)
{
    return fieldMap->fld3dCi;
}

struct EncEff *func_02189A08(FieldMap *fieldMap)
{
    return fieldMap->encEff;
}

struct FieldSkillMapEff *func_02189A10(FieldMap *fieldMap)
{
    return fieldMap->mapEff;
}

struct FldSceneArea *func_02189A18(FieldMap *fieldMap)
{
    return fieldMap->sceneArea;
}

void func_02189A1C(FieldMap *fieldMap, int busy)
{
    fieldMap->scriptEffectBusy = busy;
}

int func_02189A24(FieldMap *fieldMap)
{
    return fieldMap->scriptEffectBusy;
}

int func_02189A2C(FieldMap *fieldMap)
{
    return func_020120D8(fieldMap->gameSystem);
}

int func_02189A38(FieldMap *fieldMap)
{
    return func_020113D8(func_02012984(fieldMap->gameData));
}

int func_02189A48(FieldMap *fieldMap)
{
    return fieldMap->subscreenBusy;
}

void func_02189A50(FieldMap *fieldMap, int busy)
{
    fieldMap->subscreenBusy = busy;
}

void func_02189A58(FieldMap *fieldMap, int stopped)
{
    fieldMap->updateStopped = stopped;
}

void **func_02189A60(FieldMap *fieldMap)
{
    return &fieldMap->faceUpWork;
}

void func_02189A68(FieldMap *fieldMap, void *zoneEffectWork)
{
    fieldMap->zoneEffectWork = zoneEffectWork;
}

void *func_02189A70(FieldMap *fieldMap)
{
    return fieldMap->zoneEffectWork;
}

int func_02189A78(FieldMap *fieldMap)
{
    return fieldMap->cameraPitchScale;
}

int func_02189A80(FieldMap *fieldMap)
{
    unsigned short *pitch = (unsigned short *)func_0218ED3C(fieldMap->camera);
    int sinIndex = (*pitch >> 4) * 2 + 1;
    int sinValue = d_020A1B38[sinIndex];
    long long scaled;
    int pitchScale;
    if (sinValue < 0)
        sinValue = -sinValue;
    scaled = ((long long)sinValue << 14) + 0x800;
    pitchScale = (int)(scaled >> 12) - 0x4000;
    if (pitchScale < -0x2000)
        pitchScale = -0x2000;
    return pitchScale;
}

int func_02189ACC(u32 zoneId)
{
    if (func_02013BA8(zoneId) == 1)
        return 0x1EE;
    return 0x136;
}

int func_02189AE8(int zoneId)
{
    if (zoneId == 0x3f)
        return 0;
    if (func_02013CE0(zoneId) == 1)
        return 0;
    return 1;
}

int func_02189B04(int zoneId)
{
    if (zoneId == 0x3F)
        return 1;
    if (zoneId == 0x8C)
        return 1;
    if (zoneId == 0x8D)
        return 1;
    if (zoneId == 0x8E)
        return 1;
    return 0;
}

u32 func_02189B28(u32 zoneId)
{
    return func_02013B50(zoneId);
}

void func_02189B30(int zoneId, struct AreaData *areaData, FieldMapMapperParam *param, struct MapMatrix *mapMatrix)
{
    int mapType = (int)func_02189B28((unsigned int)zoneId);
    *param = d_021D3700[mapType].param;
    if (d_021D3700[mapType].useMatrix != 0) {
        param->matrixWidth = func_02159BF4(mapMatrix);
        param->matrixHeight = func_02159BF8(mapMatrix);
        param->matrixCount = func_02159BFC(mapMatrix);
        param->matrixGrid = func_02159C20(mapMatrix);
    }
    param->enabled = 1;
    param->blockLoadMax = 0xe;
    param->texSetId = func_020140BC(areaData);
    param->itaAnimeId = func_020140C0(areaData);
    param->itpAnimeId = func_020140CC(areaData);
}

const FieldMapCtrlFuncs *func_02189BA8(int zoneId)
{
    return d_021D373C[(int)func_02189B28((unsigned int)zoneId)].ctrlFuncs;
}
