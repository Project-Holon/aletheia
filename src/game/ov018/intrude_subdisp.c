/*
 * file:     intrude_subdisp.c
 * unit:     yes
 * function: func_0217C758, func_0217C820, func_0217C914, func_0217CA1C, func_0217CA40, func_0217CA84, func_0217CAFC, func_0217CDBC, func_0217CDD0, func_0217CE08, func_0217CE6C, func_0217CEE8, func_0217CF0C, func_0217CF68, func_0217CF88, func_0217CFE4, func_0217D160, func_0217D1C0, func_0217D3AC, func_0217D4DC, func_0217D5AC, func_0217D624, func_0217D6C8, func_0217D720, func_0217D870, func_0217D890, func_0217D904, func_0217D918, func_0217DA18, func_0217DA54, func_0217DA90, func_0217DAA8, func_0217DB4C, func_0217DBAC, func_0217DC14, func_0217DC9C, func_0217DCFC, func_0217DD48, func_0217DE44, func_0217DE68, func_0217E014, func_0217E0F4, func_0217E2E0, func_0217E3D0, func_0217E4D0, func_0217E524, func_0217E638, func_0217E714, func_0217EBD8, func_0217EC08, func_0217EC44, func_0217EC5C, func_0217EC7C, func_0217EEB4, func_0217EF44, func_0217EF70, func_0217EFCC, func_0217F008, func_0217F0C4, func_0217F0FC, func_0217F118, func_0217F174, func_0217F194, func_0217F1E8, func_0217F214, func_0217F240, func_0217F284, func_0217F2B4, func_0217F318, func_0217F36C, func_0217F390, func_0217F3A4, func_0217F3C4, func_0217F3E4, func_0217F40C, func_0217F420, func_0217F434, func_0217F45C, func_0217F470, func_0217F4A0, func_0217F4C4, func_0217F4D8, func_0217F508, func_0217F528, func_0217F574, func_0217F58C, func_0217F5A0, func_0217F5F0, func_0217F648, func_0217F67C, func_0217F6A0, func_0217F8A0, func_0217F8D0, func_0217F914, func_0217F938, func_0217F95C, func_0217FA1C, func_0217FA24, func_0217FA38, func_0217FAE0, func_0217FB2C, func_0217FB5C, func_0217FB94, func_0217FC08, func_0217FC6C, func_0217FCAC, func_0217FD34, func_0217FDA0, func_0217FE38, func_0217FE6C, func_021800A4, func_021802A8, func_0218034C, func_021803F0, func_021804F8, func_02180538, func_021808C4, func_021808E8, func_02180978, func_02180980, func_021809A4, func_02180B14, func_02180B38, func_02180BDC, func_02180C00, func_02180CA4, func_02180CC8, func_02180DE8, func_02180E0C, func_02180EB0, func_02180ED4, func_02180FA8, func_02180FCC, func_0218111C, func_02181140, func_021811E4, func_0218123C, func_0218152C, func_02181584, func_0218186C, func_021818C4, func_0218191C, func_02181940, func_021819D0, func_021819F4, func_02181A74, func_02181A98, func_02181B44, func_02181B68, func_02181BE8, func_02181C0C, func_02181D8C, func_02181DD4, func_02181E6C, func_02181E90, func_02181F10, func_02181F34, func_02181FB4, func_02181FD8, func_02182080, func_021820A4, func_02182124, func_02182150, func_021821B0, func_02182214, func_0218236C, func_021823A8, func_021825F8, func_0218261C, func_021828A8, func_021828B0
 * address:  0x0217C758
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   d_02183AF0     0x02183AF0  data  a4
 *   g_02183AF0     0x02183AF0  data  a4
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F37B8  0x021F37B8  thumb  ov060
 *   func_020061E4  0x020061E4  thumb
 *   func_021F37D8  0x021F37D8  thumb  ov060
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02173A2C  0x02173A2C  thumb  ov011
 *   func_02175514  0x02175514  thumb  ov011
 *   func_020362DC  0x020362DC  arm
 *   func_02173B9C  0x02173B9C  thumb  ov011
 *   func_021753B8  0x021753B8  thumb  ov011
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_0217BED4 0x0217BED4 thumb ov018
 *   func_02185588 0x02185588 thumb ov020
 *   func_02012138  0x02012138  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02175710  0x02175710  thumb  ov011
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_0217C094  0x0217C094  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012114  0x02012114  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_0202648C  0x0202648C  thumb
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_0217C658  0x0217C658  thumb  ov018
 *   func_0217C688  0x0217C688  thumb  ov018
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_0201212C  0x0201212C  thumb
 *   func_021C06CC  0x021C06CC  thumb  ov021
 *   func_02026484  0x02026484  thumb
 *   func_020264F4  0x020264F4  thumb
 *   func_02185214  0x02185214  thumb  ov020
 *   func_02012B70  0x02012B70  thumb
 *   func_02185140  0x02185140  thumb  ov020
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D324C  0x021D324C  thumb  ov093
 *   func_021A0F40  0x021A0F40  thumb  ov021
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0217BF84 0x0217BF84 thumb ov018
 *   func_0217BBCC  0x0217BBCC  thumb  ov018
 *   func_0217BBD8  0x0217BBD8  thumb  ov018
 *   func_0217BC94  0x0217BC94  thumb  ov018
 *   func_0217C194  0x0217C194  thumb  ov018
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02037174  0x02037174  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   str_02183B14   0x02183B14  data  a1
 *   func_02030EAC  0x02030EAC  arm
 *   func_02082A48  0x02082A48  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02037190  0x02037190  arm
 *   func_0201283C            0x0201283C  thumb
 *   func_0201058C            0x0201058C  thumb
 *   func_020310C4            0x020310C4  arm
 *   func_0201C4E4            0x0201C4E4  thumb
 *   func_02045770            0x02045770  arm
 *   func_0201C6C4            0x0201C6C4  thumb
 *   func_02045334            0x02045334  arm
 *   func_020257D0            0x020257D0  thumb
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_0215841C            0x0215841C  thumb  ov010
 *   func_0203D1C0            0x0203D1C0  arm
 *   func_021746AC            0x021746AC  thumb  ov011
 *   func_02158428            0x02158428  thumb  ov010
 *   func_02188CCC            0x02188CCC  thumb  ov021
 *   func_02034714            0x02034714  arm
 *   str_02183B28             0x02183B28  data  a1
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_02158378  0x02158378  thumb  ov010
 *   func_020862F0  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E804  0x0207E804  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_02025538  0x02025538  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   d_021836B4     0x021836B4  data   a4
 *   func_02045808  0x02045808  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02031140  0x02031140  arm
 *   func_02025588  0x02025588  thumb
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0203FCA0            0x0203FCA0  arm
 *   MIi_CpuClear32           0x02082A7C  arm
 *   func_02049658            0x02049658  arm
 *   func_020498F4            0x020498F4  arm
 *   func_02049EF4            0x02049EF4  arm
 *   MIi_CpuCopy16            0x02082A60  arm
 *   func_02049B68            0x02049B68  arm
 *   func_02049B40            0x02049B40  arm
 *   func_02040588            0x02040588  arm
 *   d_0218370C               0x0218370C  data  a4
 *   d_0218372C               0x0218372C  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_02049DF4  0x02049DF4  arm
 *   func_0204ABBC  0x0204ABBC  arm
 *   func_02082A60  0x02082A60  arm
 *   d_02183B14     0x02183B14  data   a1
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836CC     0x021836CC  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 *   func_0204B6F4  0x0204B6F4  arm
 *   d_021836E4  0x021836E4  data  a4
 *   d_021836DC  0x021836DC  data  a4
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   d_021836D4  0x021836D4  data  a4
 *   d_021836EC  0x021836EC  data  a4
 *   d_021836C4  0x021836C4  data  a4
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02025774  0x02025774  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_021836AA     0x021836AA  data   a2
 *   d_021836F4     0x021836F4  data   a4
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02021F64  0x02021F64  thumb
 *   func_0204B404  0x0204B404  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B714  0x0204B714  arm
 *   func_0204B454  0x0204B454  arm
 *   d_021836A4     0x021836A4  data   a1
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_020127B8  0x020127B8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02012950  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02026608  0x02026608  thumb
 *   func_021585BC  0x021585BC  thumb  ov010
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_021762C0  0x021762C0  thumb  ov011
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_021D3554  0x021D3554  thumb  ov021
 *   func_020127AC 0x020127AC thumb
 *   func_02035D20  0x02035D20  arm
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_02013DD0  0x02013DD0  thumb
 *   func_020257C4  0x020257C4  thumb
 *   func_0204989C  0x0204989C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_021758C8  0x021758C8  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_02041300 0x02041300 arm
 *   func_020410D0  0x020410D0  arm
 *   func_02158590 0x02158590 thumb ov010
 *   func_0201EC74  0x0201EC74  thumb
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   d_02183B2C     0x02183B2C  data
 *   func_02190708 0x02190708 thumb ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02190758 0x02190758 thumb ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   func_02190C78 0x02190C78 thumb ov021
 *   func_02026478 0x02026478 thumb
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 *   func_02012B80  0x02012B80  thumb
 *   func_021757A8  0x021757A8  thumb  ov011
 *   func_0217BF1C  0x0217BF1C  thumb  ov018
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02173D2C  0x02173D2C  thumb  ov011
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_02173C6C  0x02173C6C  thumb  ov011
 *   func_0217BF28  0x0217BF28  thumb  ov018
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_0217C458  0x0217C458  thumb  ov018
 *   func_0201235C  0x0201235C  thumb
 *   func_02176230  0x02176230  thumb  ov011
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF10 0x0200BF10 thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_02175368  0x02175368  thumb  ov011
 *   func_0217545C  0x0217545C  thumb ov011
 *   func_02167A54  0x02167A54  thumb ov010
 *   func_02167A14 0x02167A14 thumb ov010
 *   func_02008494 0x02008494 thumb
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02082D44 0x02082D44 arm
 *   func_02174E14 0x02174E14 thumb ov011
 *   func_02175DCC  0x02175DCC  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_0217620C  0x0217620C  thumb  ov011
 *   func_02182A08  0x02182A08  thumb  ov018
 *   func_02182998  0x02182998  thumb  ov018
 *   func_02182988  0x02182988  thumb  ov018
 *   func_02174258  0x02174258  thumb  ov011
 *   func_02175C40  0x02175C40  thumb  ov011
 *   func_0217553C  0x0217553C  thumb  ov011
 *   func_02173C04  0x02173C04  thumb  ov011
 *   func_0217537C  0x0217537C  thumb  ov011
 *   str_02183B30   0x02183B30  data   a1
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021829F8  0x021829F8  thumb ov018
 *   d_02183B30  0x02183B30  data ov018 a1
 *   d_02183B44  0x02183B44  data ov018 a1
 *   d_0218374C  0x0218374C  data ov018 a4
 *   d_021837C4  0x021837C4  data ov018 a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb ov021
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_021756A4  0x021756A4  thumb  ov011
 *   func_02175DE4  0x02175DE4  thumb  ov011
 *   func_0200BE24  0x0200BE24  thumb
 *   func_0200BE00  0x0200BE00  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0200823C  0x0200823C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0200BF78  0x0200BF78  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   str_02183B48   0x02183B48  data   ov018  a1
 *   func_0201232C 0x0201232C thumb
 *   d_0218383C     0x0218383C  data ov018 a2
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0201F184  0x0201F184  thumb
 *   d_02183870     0x02183870  data   a2
 *   d_0218387A     0x0218387A  data   a2
 *   d_02183884     0x02183884  data   a2
 *   d_02183848     0x02183848  data ov018 a2
 *   d_02183866     0x02183866  data ov018 a2
 *   func_020124AC  0x020124AC  thumb
 *   func_021F5260  0x021F5260  thumb  ov083
 *   ov083_id       0x00000053  data
 *   d_02183852     0x02183852  data   a2
 *   d_0218385C     0x0218385C  data   a2
 *   d_021838B8     0x021838B8  data ov018 a2
 *   d_02183890     0x02183890  data  a2
 *   d_021838A4     0x021838A4  data  a2
 *   d_021838AE     0x021838AE  data  a2
 *   d_0218389A     0x0218389A  data ov018 a2
 *   func_0215839C  0x0215839C  thumb  ov010
 *   func_021756F0  0x021756F0  thumb
 *   func_021744D0  0x021744D0  thumb
 *   func_021766CC  0x021766CC  thumb
 *   d_021838F6     0x021838F6  data  a2
 *   d_02183900     0x02183900  data  a2
 *   d_0218390A     0x0218390A  data  a2
 *   d_02183914     0x02183914  data  a2
 *   d_0218391E     0x0218391E  data  a2
 *   func_021763D8  0x021763D8  thumb  ov011
 *   d_021838C4     0x021838C4  data  a2
 *   d_021838CE     0x021838CE  data  a2
 *   d_021838D8     0x021838D8  data  a2
 *   d_021838E2     0x021838E2  data  a2
 *   d_021838EC     0x021838EC  data  a2
 *   d_02183928     0x02183928  data  a2
 *   d_0218393C     0x0218393C  data  a2
 *   d_02183932     0x02183932  data  a2
 *   d_02183946     0x02183946  data  a2
 *   func_0217456C  0x0217456C  thumb  ov011
 *   d_02183950     0x02183950  data  a2
 *   d_0218395A     0x0218395A  data  a2
 *   d_02183964     0x02183964  data  a2
 *   func_02012F20  0x02012F20  thumb
 *   func_0200846C  0x0200846C  thumb
 *   func_0202E82C  0x0202E82C  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   d_02183970     0x02183970  data  a2
 *   d_02183984     0x02183984  data  a2
 *   d_0218397A     0x0218397A  data   a2
 *   d_0218398E     0x0218398E  data   a2
 *   func_020084F8  0x020084F8  thumb
 *   func_021745F8  0x021745F8  thumb  ov011
 *   func_0201EF40  0x0201EF40  thumb
 *   d_02183998     0x02183998  data  a2
 *   func_021756D0 0x021756D0 thumb ov011
 *   d_021839E0     0x021839E0  data  a2
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0200C29C  0x0200C29C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   d_021839A4     0x021839A4  data  a2
 *   func_0218236C  0x0218236C  thumb  ov018
 *   func_021825F8  0x021825F8  thumb  ov018
 */
#include "../../matched/include/G_Tmpl.h"
#include "../../matched/include/Obj02674.h"
#include "../../matched/include/Obj00703.h"
#include "../../matched/include/Obj00399.h"
#include "../../matched/include/Obj03091.h"
#include "../../matched/include/Obj02676.h"
#include "../../matched/include/Obj12491.h"
#include "../../matched/include/Obj03092.h"
#include "../../matched/include/Obj12492.h"
#include "../../matched/include/Obj09396.h"
#include "../../matched/include/Obj00092.h"
#include "../../matched/include/Obj12494.h"
#include "../../matched/include/Obj19364.h"
#include "../../matched/include/Obj12499.h"
#include "../../matched/include/Obj07367.h"
#include "../../matched/include/Obj04178.h"
#include "../../matched/include/Obj00566.h"
#include "../../matched/include/Obj03562.h"
#include "../../matched/include/Obj12502.h"
#include "../../matched/include/Obj12503.h"
#include "../../matched/include/Obj19375.h"
#include "../../matched/include/Obj12504.h"
#include "../../matched/include/Obj09400.h"
#include "../../matched/include/Obj05933.h"
#include "../../matched/include/Obj05935.h"
#include "../../matched/include/Obj05937.h"
#include "../../matched/include/Obj05940.h"
#include "../../matched/include/Obj05941.h"
#include "../../matched/include/Obj04961.h"
#include "../../matched/include/Obj04963.h"
#include "../../matched/include/Obj04964.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT_SUB (*(volatile u16 *)0x04001050)
struct BigObj;
struct Ctx;
struct Obj00020;
struct VecFx32;
struct T;
struct V3;
struct Desc;
struct Obj;
struct Comm;
struct Rec;
struct Evt;
struct Fx;
struct Obj2;
struct Obj_0217CEE8;
struct State;
struct Rec44;
struct Node;
struct Descriptor;
struct PrintSys;
struct Tcbl;
struct GfFont;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Bank;
struct S02031140;
struct Cfg;
struct Sub0200852CObj;
struct Bmp;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
struct Vec2;
struct Actor;
struct PtS;
struct Obj_0217E524;
struct CharBuf;
struct Sub24;
struct SaveBlock;
struct Obj_0217EC7C;
struct Rec_0217EC7C;
struct P;
struct Handle;
struct S0201235C;
struct Big;
struct Rec1B0;
struct Work;
struct S;
struct Outer_021821B0;
struct Blk34;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    void *f14;
} Rec;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad04[8];
    u16 fC;
} Tmpl_0217C758;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct { int x, y, z; } V12;

typedef struct {
    unsigned char pad00[0x20];
    int f20;
    int f24;
} Ov018Work_0217CA84;

/* 0x28-byte task work, allocated by func_0217CA84 through func_020122C0 */
typedef struct {
    void *f00;
    void *f04;
    unsigned char f08[0x18];
    int f20;
    int f24;
} Ov018Work_0217CAFC;

typedef signed int     s32;

typedef struct { int f0, f4, f8; } Obj_0217CEE8;

typedef struct {
    int f0;
    int f4;
    int f8;
} Obj_0217CF0C;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8_0217C758;

typedef struct {
    void *f0;
    unsigned char pad004[0xDC];
    int fE0;
    unsigned char pad0E4[0x88];
    unsigned char f16C;
} Ov018Menu_0217D3AC;

typedef struct { unsigned char a : 7; unsigned char b : 1; } FlagsF8_0217D3AC;

typedef struct {
    void *f0;
    unsigned char pad004[0x10C];
    unsigned short f110;
    unsigned char f112;
    unsigned char pad113[0x55];
    unsigned char f168;
} Ov018Menu_0217D4DC;

struct State {
    u8 pad00[0x1C];
    struct GfFont *font;      /* 0x1C */
    struct Tcbl *tcbl;        /* 0x20 */
    struct WordSet *words;    /* 0x24 */
    int unk28;                /* 0x28 */
    struct MsgBank *msg2C;    /* 0x2C */
    struct MsgBank *msg30;    /* 0x30 */
    u8 pad34[4];
    struct U16Vec *str38;     /* 0x38 */
    struct U16Vec *str3C;     /* 0x3C */
    struct U16Vec *str40;     /* 0x40 */
    u8 pad44[0x10];
    struct Bank *bank;        /* 0x54 */
    struct Obj *obj;          /* 0x58 */
    u8 pad5C[0x54];
    void *unkB0;              /* 0xB0 */
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct {
    char pad[0x44];
    int a;
    char b;
    char pad2[3];
    int c;
    char d;
} S;

typedef struct { u16 a, b, c, d; } Rect_0217DAA8;

typedef struct {
    void *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
} Tmpl_0217DAA8;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    int f0c;
    void *f10;
    u8 pad14[0x1c - 0x14];
    void *f1c;
    u8 pad20[0x28 - 0x20];
    void *f28;
    void *f2c;
    u8 pad30[0x54 - 0x30];
    void *f54;
    u8 pad58[0x9c - 0x58];
    void *f9c;
    u8 padA0[0xb0 - 0xa0];
    void *fb0;
    void *fb4[3];
    void *fc0[2];
    u8 padC8[0x168 - 0xc8];
    u8 f168;
} Work_0217DD48;

typedef signed char s8;

typedef signed short s16_0217DAA8;

typedef struct {
    void *f00;
    u8 pad04[0x5c - 0x04];
    void *f5c[8];
    void *f7c;
    u8 pad80[0xd8 - 0x80];
    u8 fd8;
    u8 padD9[0x113 - 0xd9];
    u8 f113;
    u8 f114;
    u8 f115;
    u8 pad116[2];
    s16_0217DAA8 f118;
    s8 f11a;
    u8 f11b;
    u8 f11c;
    u8 pad11D[3];
    u16 f120[4];
    u16 f128[4];
    u16 f130[4];
} Work_0217DE68;

typedef struct {
    s16_0217DAA8 x;
    s16_0217DAA8 y;
} Pos;

typedef struct {
    u8 slot[4];
    Pos pos;
} Layout;

typedef struct {
    void *ptr;
    u16 id;
} Slot_0217DAA8;

typedef struct {
    void *f00;
    u8 pad04[0x80 - 0x04];
    void *f80[3];
    void *f8c[3];
    u8 pad98[0xa0 - 0x98];
    void *fa0[3];
    u8 padAC[0xd8 - 0xac];
    u8 fd8;
    u8 fd9;
    u8 padDA[0xec - 0xda];
    Slot_0217DAA8 fec[3];
} Work_0217E0F4;

typedef struct {
    u8 pad00[0x14];
    u16 f14;
    u16 lo : 3;
    u16 mid : 6;
    u16 hi : 6;
    u8 pad18[4];
} Ent_0217E0F4;

typedef struct {
    u8 pad00[0x8c];
    Ent_0217E0F4 ent[3];
} Mon_Ents;

typedef struct {
    Pos p2;
    Pos p;
} Pair;

typedef struct {
    u8 pad00[0x5c];
    void *f5c[16];
    u8 pad9C[0xdc - 0x9c];
    int fdc;
    u8 padE0[4];
    u8 *fe4;
    u8 padE8[0x16a - 0xe8];
    u8 f16a;
    u8 f16b;
} Work;

typedef short s16_0217E2E0;

typedef struct { u16 a, b; u8 x, y; } Ent;

typedef struct {
    unsigned int id : 10;
    unsigned int id2 : 10;
    unsigned int id3 : 10;
    unsigned int hi : 2;
    u8 pad04[0x0A - 0x04];
    u8 x;
    u8 y;
} Mon_0217E524;

typedef struct {
    Mon_0217E524 *mon;
    u16 id;
    u16 pad06;
} Slot_0217E2E0;

typedef struct {
    int f00;
    u8 pad04[0x98 - 0x04];
    int f98;
    u8 pad9C[0xEC - 0x9C];
    Slot_0217E2E0 slots[1];
} Obj;

typedef struct {
    u8 pad00[0x14];
    u8 *f14;
} Gfx;

typedef struct {
    int f00;
    u8 pad04[0xAC - 0x04];
    int fAC;
    u8 padB0[0xCC - 0xB0];
    Gfx *fCC;
    u8 *fD0;
    u8 padD4[0xDC - 0xD4];
    int fDC;
    int fE0;
    u8 padE4[0x10A - 0xE4];
    s16_0217E2E0 f10A;
    u8 pad10C[0x10F - 0x10C];
    u8 f10F;
} Obj_0217E524;

typedef struct {
    int f00;
    u8 pad04[0x1C - 0x04];
    int f1C;
    u8 pad20[0x24 - 0x20];
    int f24;
    int f28;
    int f2C;
    u8 pad30[0x38 - 0x30];
    int f38;
    u8 pad3C[0x40 - 0x3C];
    int f40;
    int f44;
    u8 f48;
    u8 pad49[0xD8 - 0x49];
    u8 fD8;
    u8 padD9[0x10C - 0xD9];
    u8 f10C;
} Obj_0217E638;

typedef struct {
    u8 pad00[4];
    unsigned int a : 4;
    unsigned int b : 3;
    unsigned int c : 11;
    unsigned int d : 14;
    u8 pad08[0x18 - 0x08];
    u8 f18[0x28 - 0x18];
    u8 f28;
} Sel;

typedef struct {
    u32 f00;
    u8 pad04[0x1C - 0x04];
    int f1C;
    u8 pad20[0x24 - 0x20];
    void *f24;
    int f28;
    void *f2C;
    void *f30;
    u8 pad34[0x38 - 0x34];
    void *f38;
    void *f3C;
    u8 pad40[0x4C - 0x40];
    void *f4C;
    u8 f50;
    u8 pad51[0xD8 - 0x51];
    u8 fD8;
    u8 padD9[0xDC - 0xD9];
    int fDC;
    u8 padE0[0xE4 - 0xE0];
    Sel *fE4;
    u8 fE8;
    u8 fE9;
    u8 fEA;
    u8 padEB[0xEC - 0xEB];
    Slot_0217E2E0 slots[3];
    u8 pad104[0x108 - 0x104];
    s16_0217E2E0 f108;
    u8 pad10A[0x10D - 0x10A];
    u8 f10D;
    u8 f10E;
    u8 pad10F[0x169 - 0x10F];
    u8 f169;
} W;

typedef struct { unsigned short a : 9; unsigned short b : 6; unsigned short c : 1; } Fld;

typedef struct { int x; int y; int z; } Vec3;

typedef struct {
    u32 ptr[2];
    u8 slot[2];
    u8 par[2];
    u16 msg;
} Buf;

typedef struct { int l, t, r, b; } Rect_0217E2E0;

typedef struct {
    u16 id;
    u8 pad02[0x1A];
} QEnt;

typedef struct {
    u8 pad00[0xA0];
    QEnt e[3];
} Q;

typedef struct {
    int f00;
    u8 pad04[0x8C - 0x04];
    int f8C[3];
    u8 pad98[0xC4 - 0x98];
    int fC4;
    u8 padC8[0xD8 - 0xC8];
    u8 fD8;
    u8 fD9;
    u8 padDA[0x106 - 0xDA];
    u8 f106;
    u8 f107;
    u8 pad108[0x110 - 0x108];
    u16 f110;
    u8 f112;
    u8 f113;
    u8 pad114[0x168 - 0x114];
    u8 f168;
    u8 f169;
} Obj_0217EC7C;

typedef struct { u8 a, b, c, d; int e, f; } State;

typedef struct { u16 lo : 3; u16 hi : 13; } Bf_0217EC7C;

typedef struct { u8 pad[0x28]; u8 idx; } T;

typedef struct {
    u8 a, b, c, d;
    int e;
    int f;
    T *g;
    u8 h, i, j;
} O;

typedef struct {
    u8 pad0[0x5C];
    void *tbl[9];
    u8 pad80[0x114 - 0x80];
    u8 f114;
    u8 pad115[3];
    u16 f118;
    u8 f11A;
    u8 f11B;
} Ov018Sel;

typedef struct {
    u8 pad0[0x9C];
    void *f9C;
    u8 padA0[0x116 - 0xA0];
    u8 f116;
    u8 f117;
} Ov018Blink;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    u8 f28;
} Ov018Obj_0217EC7C;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
} Ov018Obj_0217F528;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
} Rec_0217EC7C;

typedef struct {
    u8 pad0[0x1A5];
    u8 lo1A5 : 2;
    u8 bit1A5 : 1;
} Ov018Obj_0217F5A0;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u8 f1A : 4;
} Ent_0217F3E4;

typedef struct {
    u8 pad0[4];
    void *f04;
    u8 pad8[0x70 - 8];
    Ent_0217F3E4 cur;
    Ent_0217F3E4 arr[];
} Ov018Obj_0217F5F0;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fC;
} Ctx;

typedef struct {
    u8 pad0[0x93F];
    u8 lo93F : 3;
    u8 bit93F : 1;
} Sys;

typedef struct { int f0; int f4; int f8; u16 fC; } Req;

typedef struct {
    int w[13];
} S52;

typedef struct {
    unsigned char pad00[0x10];
    Ov018Obj obj;
} Ov018Outer;

typedef struct {
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 2];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 f41;             /* 0x41 */
    u8 pad42[0x98 - 0x42];
    u8 f98;             /* 0x98 */
    u8 f99;             /* 0x99 */
} Outer_0217EC7C;

typedef struct {
    u16 lo : 9;
    u16 f9 : 6;
    u16 f15 : 1;
} Bits;

typedef struct {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[4];
    void *f0C;          /* 0x0C */
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 f41;             /* 0x41 */
    u8 pad42[0x99 - 0x42];
    u8 f99;             /* 0x99 */
} Outer_021800A4;

typedef struct { u8 pad : 5; u8 f : 1; u8 rest : 2; } Bf_021800A4;

typedef struct {
    u32 f00;
    u32 lo : 4;
    u32 mid : 14;
    u32 f18 : 11;
    u32 hi : 3;
    u8 rest[0x3C - 8];
} Rec3C;

typedef struct {
    u16 f00;            /* 0x00 */
    u16 pad02;
    Ov018Obj obj;       /* 0x04 */
    void *f34;          /* 0x34 */
    u8 pad38[0xEC - 0x38];
    Rec3C fEC;          /* 0xEC */
    u16 f128;           /* 0x128 */
    u16 f12A;           /* 0x12A */
    int f12C;           /* 0x12C */
    u32 f130;           /* 0x130 */
    u8 f134;            /* 0x134 */
    u8 f135;            /* 0x135 */
    u16 f136;           /* 0x136 */
} Outer_Sub_a;

typedef struct {
    u8 f0 : 1;
    u8 rest : 7;
} B1;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
} Outer_021809A4;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0xA0 - 0x78]; /* 0x78 */
    int fA0;            /* 0xA0 */
} Outer_0218034C;

typedef struct {
    u32 a;
    u32 zero;
} Args;

typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj_021800A4;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[4];          /* 0x78 */
} Ov018Outer_Sub_a;

typedef struct {
    u8 pad00[0x40];
    u8 f40;
    u8 pad41[0x17];
    u16 f58;
} Ov018Src;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 pad41;
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
    u8 fA0;
    u8 fA1;             /* 0xA1 */
    u8 padA2[2];
    int fA4;            /* 0xA4 */
    int fA8;            /* 0xA8 */
    int fAC;            /* 0xAC */
} Ov018Outer_0218034C;

typedef struct {
    unsigned char pad00[0x10];
    Ov018Obj obj;
    unsigned char pad40[2];
    unsigned char f42;
    unsigned char pad43[0x35];
    int f78;
} Ov018Outer_0218191C_b;

typedef struct {
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 0x02];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 pad41;
    u8 f42;             /* 0x42 */
    u8 pad43;
    u8 f44[0x5C - 0x44]; /* 0x44 */
    u8 f5C[0x98 - 0x5C]; /* 0x5C */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
    int fA0;            /* 0xA0 */
} Ov018Outer_02181BE8;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
    void *f30;
} Ov018Obj_02181DD4;

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x78 - 0x43];
    u8 f78[0x98 - 0x78]; /* 0x78 */
} Outer_0218191C;

typedef struct { u32 words[13]; } Rec_021800A4;

typedef struct {
    u8 pad00[0x30];
    u8 f30[8];
    u8 pad38[8];
    u16 f40;
    u8 f42;
    u8 pad43;
    u16 f44;
} Task;

typedef struct {
    u8 pad00[0x14];
    u16 f14;
    u16 f16;
    u8 pad18[0x28 - 0x18];
    u8 f28;
} Src;

typedef struct {
    Ov018Obj obj;       /* 0x00 */
    u8 f30[0x40 - 0x30]; /* 0x30 */
    u16 f40;            /* 0x40 */
    u8 pad42[2];
    u16 f44;            /* 0x44 */
    u8 pad46[2];
    int f48;            /* 0x48 */
    int f4C;            /* 0x4C */
    int f50;            /* 0x50 */
} Ov018Work;

typedef struct Outer_021821B0 {
    u8   pad00[0x10];
    void *p10;
    u8   pad14[0x42 - 0x14];
    u8   b42;
    u8   pad43[0x58 - 0x43];
    u16  h58[2];
    u8   pad5C[0x78 - 0x5C];
    u8   f78[0x98 - 0x78];
    int  f98;
    int  f9C;
    int  fA0;
} Outer_021821B0;

typedef struct Outer_021825F8 {
    u8   pad00[0x10];
    void *p10;
    u8   pad14[0x42 - 0x14];
    u8   b42;
    u8   pad43[0x58 - 0x43];
    u16  h58[2];
    u8   pad5C[0x78 - 0x5C];
    u8   f78[0x98 - 0x78];
    int  f98;
} Outer_021825F8;

extern void func_02082BCC(void *, int, int);
extern void *func_020120F4(const void *p);
extern u32 func_02012964(const void *p);
extern void *func_02188CB4(void *p);
extern void *func_021A3074(void *p);
extern u16 func_02188C9C(void *);
extern u16 func_0216D598(void *);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern u32 func_0216D8AC(void *p);
extern void func_0216E618(void *, u16, u16, int);
extern void *func_0216CE60(int, void *, int);
extern void func_0217BCDC(void *p, void *a1, int id, u8 kind, u8 flag);
extern void func_0216DAC8(void *, unsigned int);
extern void func_0216D410(void *, int);
extern void func_021A3038(void *, void *);
extern void func_021F37B8(int, void *);
extern void func_020061E4(u32 a);
extern int func_021F37D8(void *);
extern int func_0216D454(int);
extern int func_0216D480(void *p);
extern void func_0216CF2C(int);
extern int func_02173A2C(void *p, int b, void *c, int d);
extern int func_02175514(void *);
extern u32 func_020362DC(void);
extern int func_02173B9C(int a, int b);
extern void func_021753B8(void *);
extern int func_02173AE0(int a, int b, int c, int d);
extern int func_0217BED4(int, void *);
extern void *func_02185588(void *owner, u16 id, const void *pos);
extern unsigned int func_02012138(const void *p);
extern u8 func_02012B58(const void *p);
extern void func_02012B8C(void *p, unsigned int v);
extern int func_02158344(int a0);
extern void func_02175710(void *o, u32 v);
struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
void *func_020124E8(void *p);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
u32 func_0202647C(void *obj);
u32 func_02012204(const void *p);
void func_0217C094(void *);
void *func_020124E4(void *p);
void func_02012374(void *evt, void *out);
u32 func_0200FB24(void);
u32 func_02026460(void *obj);
void func_02026400(void *p);
u32 func_02012114(const void *p);
void *func_0201210C(const void *p);
int func_02188BE8(void *);
u32 func_02188C54(void *p);
int func_021904B0(u32 a, u32 b);
struct Obj2 *func_02190F64(void *a, u32 b);
u32 func_0202648C(void *obj);
void func_02190E74(void *p, u32 b, u32 c, u32 d);
void *func_02029830(void *a, u32 b);
int func_02005F38(void);
void *func_02029620(void *a, u32 b, u32 c);
u32 func_02190EF0(void *p);
int func_02190E40(u32 a);
u32 func_02045C04(void *rec);
int func_021A3238(void *p);
void func_0217C658(void *, void *, void *, int, int, int);
int func_0217C688(void *, int);
u32 func_0201296C(const void *p);
u32 func_020142E8(void *bitmap, s32 id);
int func_02158780(void *p, u16 b, int c, int d, u16 e);
u8 func_0201212C(const void *p);
int func_021C06CC(void *, void *);
void func_02026484(void *);
void func_020264F4(void *p);
void *func_02185214(void *a);
extern int func_02012B70(const void *p);
extern void *func_02185140();
extern void *func_0217BEA8(int);
extern void *func_02184D38(void *p, int unused, int a, const void *q, u16 s, int t);
extern u32 func_02188E30(void *p);
extern void func_021D324C();
extern void func_021A0F40(void *p, u32 v);
extern void *func_0215A5DC(void *);
extern void func_0217BF84(int a);
extern void func_0217BBCC(int a, int b, void *p);
extern void func_0217BBD8(void *a, int b, void *c);
extern void func_0217BC94(int a, int n);
extern void func_0217C194();
void *func_02030734(u32 heapId, u32 size, int clear, const void *site, u16 tag);
void *func_020490F4(u32 id, u32 heap);
void func_02049238(void *bg);
void func_0203D34C(u32 a, u32 b);
void func_02037174(void);
void *func_020056A0(void (*cb)(void), void *arg, int pri);
u8 *func_020120F8(const void *p);
u16 func_02012AC8(const void *p);
extern void func_02030EAC(void *n);
extern void func_02082A48();
extern u32 func_020307B0(void *p);
extern void func_02037190();
u32 func_0201283C(const void *p);
u32 func_0201058C(void *key);
void func_020310C4(void *p);
u32 func_0201C4E4(void *ps);
void *func_02045770(void *p);
u32 func_0201C6C4(void *p, void *v);
void func_02045334(void *d);
void func_020257D0(void *o);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
u8 func_0215841C(void *p);
u32 func_0203D1C0(u32 index);
int func_021746AC(void *a, int b);
u8 func_02158428(void *p);
u32 func_02188CCC(void *p);
void func_02034714(const void *expr, u32 line, const void *file);
u32 func_02013D5C(u32 id);
int func_02175DA8(void *p);
int func_02175B8C(void *p);
int func_02158378(void *);
extern void func_020862F0();
extern void func_0207E5D0();
extern void func_0207E804();
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(void *a0, unsigned int a1, unsigned int heap);
extern void func_0204B258(void *bank, void *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(void *vec);
extern void func_0201C6EC(void *p);
extern void func_0201C4C0(void *p);
extern unsigned int func_0201ED04(void *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(void *p);
extern void func_02025588(void *p);
extern void func_0204B084(int);
extern u32 func_0204B1CC(void *bank);
void func_0203FCA0(u32 bgId, const void *tmpl, u32 type);
void MIi_CpuClear32(u32 data, void *dest, u32 size);
u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void *func_02049EF4(void *p, u32 a, u32 b, void *out, u16 d);
void MIi_CpuCopy16(const void *src, void *dest, u32 size);
void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned int);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(void *cfg);
extern u8 func_02045730(void *p);
extern void func_020409B4(unsigned int);
extern u32 func_020452E8(void *d);
extern s32 func_0204AC18(void *a, unsigned int b, unsigned int c, unsigned int d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern int func_0204ACEC(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern void *func_02049DF4(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern int func_0204ABBC(unsigned int idx, unsigned int flag);
extern void func_02082A60(const void *, void *, int);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B3B4(void *p);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(void *, unsigned int);
extern void func_0204B92C(void *p, unsigned int v);
extern void func_0204B6F4(void *o, unsigned int v, unsigned int flag);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const void *obj);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(void *sys, const void *param);
extern void func_02025774(void *g, u32 a);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0202570C(void *g);
extern void func_020437AC(void *p);
extern void func_02021F64(void *, void *, int, u8, u16);
extern void func_0204B404(void *p, const void *delta, u32 which);
extern void func_0204B954(void *a, u32 v);
extern u32 func_0204B714(void *o);
extern void func_0204B454(void *actor, void *out, u16 space);
extern unsigned int func_0204B3F4(void *p);
extern void *func_020127B8(void *p);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);
void func_02043B5C(void *buf, u8 value);
struct Rec44 *func_02012950(void *p, u32 i);
void func_0201F02C(void *p, u32 i, void *a);
void func_02045CAC(void *bank, u32 index, void *dest);
void func_0201F250(void *ws, void *dst, void *src);
u32 func_02013D9C(u32 id);
int func_0203D1B4(void);
void func_0201EE0C(void *p, u32 i, const void *src, u32 n, u32 f, u32 c);
int func_02026608(void *p, void *out);
int func_021585BC(int a0);
int func_021583EC(void *a0, int a1);
void func_021762C0(void *win, u32 slot, void *src, u16 heap);
void func_021762D8();
int func_021D3554(void *arg0, int arg1);
extern void *func_020127AC(void *p, u32 idx);
extern u32 func_02035D20(void *outA, void *outB);
extern int func_021A0F94(u32 a);
extern int func_02013DD0(int a0);
extern int func_020257C4(const void *p);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02041B6C(u32 bit);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int func_02080D24(unsigned int x);
extern int func_021758C8(void *o);
extern u8 *func_02175B34(void *p);
extern int func_0217C070(void *p);
extern void func_02041300(unsigned int, int, int, int, u8, u8, u8);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern int func_02158590(void *);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
u32 func_021904C8(void *a0);
void func_02190EB8(void *p, u32 b, u16 c, u32 d);
void func_02190F7C(void *p);
extern void *func_02190708(void *p, u32 a, u16 b, u16 c, u16 d, u16 e);
int func_02190728(void *a);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
int func_021909BC(void *a);
extern u32 *func_02190BE4(void *a, u32 b);
extern int func_02190C78(void *h);
unsigned int func_02026478(void *obj);
extern void *func_0215A5F4(void *);
extern u16 *func_02159AE8(void *, void *);
extern void func_0215897C(void *, void *);
u8 func_02012B80(const void *p);
void func_021757A8(void *p);
void func_0217BF1C(void *p);
int func_021907A8(void *a0, int a1);
int func_02190740(u32 a, u32 b, u32 c, u32 d);
int func_02173D2C(int a0, int a1);
int func_02175FB4(void *p);
int func_02173C6C(int a, int b);
u8 func_0217BF28(void *p);
int func_0219077C(void *p);
struct Desc *func_0217C458(void *a0, void *a1, void *a2, int a3);
void func_0201235C(void *o, void *out);
u8 func_02176230(void *p, void *q);
extern void *func_02012EBC(void *p);
extern u16 *func_0200BE48(void *);
extern u8 func_0200BF10(void *p);
void *func_02188C7C(void *p);
void func_0216D9A0(void *x);
u32 *func_0216D9E4(void *c);
void func_0217538C(void *w, int a);
void func_02175368(void *p);
void func_0217545C(void *p);
int func_02167A54(void *p, int i);
u32 func_02167A14(void *w, int i);
void func_02008494(void *src, void *dst);
int func_02175B14(void *a);
void func_02082D44(const void *src, void *dst, int n);
void func_02174E14(void *a, int b);
int func_02175DCC(void *p);
u8 *func_02175BCC(void *p);
int func_0217620C(void *, int);
void func_02182A08(void *, void *);
void func_02182998(void *, void *);
void func_02182988(void *, void *);
int func_02174258(void *a);
int func_02175C40(void *p);
void func_0217553C(void *);
int func_02173C04(int, int);
u8 *func_0217537C(void *);
int func_0216D3CC(int a0);
void MI_CpuCopy8(const void *src, void *dst, unsigned int n);
void func_021829F8(void *a, void *b);
extern void *func_02188C80(void *p);
u16 func_02188C84(void *p);
int func_02175E90(void *p, void *q);
u8 func_021756A4(void *p);
int func_02175DE4(void *p, void *a1);
void func_0200BE24(void *p, s32 v);
void func_0200BE00(void *p, s32 v);
void *func_0201292C(const void *p);
u32 func_02007FB8(void *base, u16 id, u16 d);
u32 func_0200823C(u32 a);
u32 func_02007E50(void *base, u16 id, u16 qty, u16 d);
u32 func_0200BF78(void *p);
void func_0201EFA4(void *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201232C(void *p, int a1, int a2);
int func_0217405C(void *a, void *b);
int func_02175CF4(void *p, void *q);
void func_0201F184(void *p, u32 i, s32 v);
struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
void *func_021F5260(void *a0, void *a1);
int func_0215839C(void *p, int m, int a2);
void func_021756F0(void *, int);
int func_021744D0(void *, int, int);
void *func_021766CC(void *, void *);
void func_021763D8(void *p, u32 key);
int func_0217456C(int a, int b, int c, ...);
int func_02012F20(int p0);
void *func_0200846C(int a0);
void *func_0202E82C(void *p);
struct Desc *func_02158768(int a0, int a1, int a2, int a3);
int func_021589D0(int a0);
int func_02159058(int a, int b, int c, int d, u16 e);
extern u32 func_020084F8(void *dst, u32 value, u32 size);
int func_021745F8(u32 a, u32 b);
void func_0201EF40(void *p, u32 i, u32 v);
extern int func_021756D0(u32 x);
extern void *func_02012F08(void *p);
extern u32 func_0200C274(void *p);
extern u32 func_0200C29C(void *p, u32 v);
extern u32 func_02007E3C(void *base, u16 id, u16 qty, u16 d);
void func_0217C758(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind, u8 flag, u16 idx, int place);
int func_0217C820(Rec *r);
int func_0217C914(u8 *v, u8 *w, u8 *state);
void *func_0217CA1C(void *p);
void *func_0217CA40(int a0);
int func_0217CA84(void *a, int b);
int func_0217CAFC(void *a, int *seq, Ov018Work_0217CAFC *work);
void *func_0217CDBC(void *p);
int func_0217CDD0(void *p, int *state);
void *func_0217CE08(void *a0, void *a1, u16 a2, int a3);
void *func_0217CE6C(void *a0, void *a1, int a2);
void *func_0217CEE8(void *p, int a, int b);
int func_0217CF0C(int a0, int *state, Obj_0217CF0C *o);
int func_0217CF68(void *unused, void *p);
int func_0217CF88(int a0, int a1);
u8 *func_0217CFE4(void *a);
void func_0217D160(int a0);
void func_0217D1C0(u8 *w, int b);
void func_0217D3AC(Ov018Menu_0217D3AC *w);
void *func_0217D4DC(Ov018Menu_0217D4DC *w, int b, int c);
void func_0217D5AC(int a0, u8 *p);
void func_0217D624(struct State *o);
void func_0217D6C8(int *p);
void func_0217D720(u8 *w, void *bg);
void func_0217D870(int a0);
void func_0217D890(S *p);
void func_0217D904(char *p);
void func_0217D918(u8 *p, void *bg);
void func_0217DA18(u32 *p);
void func_0217DA54(void *p, void *bg);
void func_0217DA90(void **p);
void func_0217DAA8(int *p, void *a1);
void func_0217DB4C(int *p, void *a1);
void func_0217DBAC(int *p, void *a1);
void func_0217DC14(int *p, void *a1);
void func_0217DC9C(int *p, void *a1);
void func_0217DCFC(int *p, void *a1);
void func_0217DD48(Work_0217DD48 *p, void *z2);
void func_0217DE44(void **p);
void func_0217DE68(void *, int z2);
void func_0217E014(u8 *p, int a1);
void func_0217E0F4(void *, void *, int z3);
void func_0217E2E0(void *p_v);
void func_0217E3D0(void *, int a1, u16 id);
void func_0217E4D0(int *p, int a1);
void func_0217E524(void *, int z2);
void func_0217E638(void *, int z2);
void func_0217E714(void *, u8 *p, u16 q);
void *func_0217EBD8(u8 *p);
int func_0217EC08(u16 a, u16 b, u16 c);
void func_0217EC44(int x, int y, int w, int h, Rect_0217E2E0 *r);
int func_0217EC5C(int x, int y, const Rect_0217E2E0 *r);
void func_0217EC7C(void *, void *, int id);
void func_0217EEB4(int *p);
void func_0217EF44(void *, void *z2);
void func_0217EF70(int *p, int x);
void func_0217EFCC(char *p, char *q);
void func_0217F008(char *p, char *q);
void func_0217F0C4(u8 *p);
int func_0217F0FC(u8 *p);
void func_0217F118(void *p_v, int n);
void func_0217F174(u8 *p);
void func_0217F194(void *);
int func_0217F1E8(u8 *p);
void func_0217F214(void);
void func_0217F240(u8 *p, int mode);
int func_0217F284(u8 *p);
void func_0217F2B4(void *p_v, void *a);
void func_0217F318(void *p_v);
void func_0217F36C(Ov018Obj *p);
void func_0217F390(Ov018Obj *p);
void func_0217F3A4(Ov018Obj *p, void *a);
void func_0217F3C4(void *, u16 a);
void func_0217F3E4(Ov018Obj *p);
int func_0217F40C(void *);
int func_0217F420(void);
void func_0217F434(void **p);
void func_0217F45C(Ov018Obj *p);
void func_0217F470(void **p, void *bank, void *handle, unsigned int index, int a, int b);
void func_0217F4A0(void **p, unsigned int index, int a, int b);
void func_0217F4C4(void *p_v);
void func_0217F4D8(void **p, int a);
int func_0217F508(void **p);
void func_0217F528(Ov018Obj_0217F528 *p, int a, int b, int c, int d, int e);
void func_0217F574(void **p, unsigned int index, int a, int b);
void func_0217F58C(Ov018Obj *p);
int func_0217F5A0(Ov018Obj_0217F5A0 *p);
int func_0217F5F0(void *p_v, u8 idx);
int func_0217F648(void *a, void *vm);
void *func_0217F67C(void *owner, u16 *out);
int func_0217F6A0(void *a0, int *state, Ctx *c);
int func_0217F8A0(void *a, void *vm);
int func_0217F8D0(void *a0, int a);
int func_0217F914(void *unused, void *vm);
void *func_0217F938(void *owner);
int func_0217F95C(void *a0, int *state, void *a2);
void func_0217FA1C(void *p);
void *func_0217FA24(void *owner);
int func_0217FA38(void *a, int *state);
int func_0217FAE0(void *unused, int a);
int func_0217FB2C(void *a, void *vm);
void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f);
int func_0217FB94(int a, int *state, Req *req);
void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f);
void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e);
int func_0217FCAC(int x, int *st, int *obj);
void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f);
void func_0217FDA0(int a, u8 *b, u8 *c, int d, int e, int f, u16 g);
void func_0217FE38(void *v, void *c_);
int func_0217FE6C(void *a, int *state, Outer_0217EC7C *c);
int func_021800A4(void *a, int *state, Outer_021800A4 *c);
void func_021802A8(int x, u8 *y, int z);
void func_0218034C(int x, u8 *y, int z);
int func_021803F0(u8 *a, u8 *b);
void *func_021804F8(void *p, int a);
int func_02180538(void *a, int *state, Outer_Sub_a *c);
void func_021808C4(void *task, const void *src);
int func_021808E8(int x, int *st, u8 *obj);
void func_02180978(int id, void *dst);
void func_02180980(void *task, const void *src);
int func_021809A4(void *a, int *state, Outer_021809A4 *c);
void func_02180B14(void *task, const void *src);
int func_02180B38(int x, int *st, u8 *obj);
void func_02180BDC(void *task, const void *src);
int func_02180C00(int x, int *st, u8 *obj);
void func_02180CA4(void *task, const void *src);
int func_02180CC8(void *a, int *state, Outer_0218034C *c);
void func_02180DE8(Obj_021800A4 *task, const void *src);
int func_02180E0C(int x, int *st, u8 *obj);
void func_02180EB0(Obj_021800A4 *task, const void *src);
int func_02180ED4(void *a, int *state, Ov018Outer_Sub_a *c);
void func_02180FA8(Obj_021800A4 *task, const void *src);
int func_02180FCC(void *a, int *state, Outer_021809A4 *c);
void func_0218111C(Obj_021800A4 *task, const void *src);
int func_02181140(int x, int *st, u8 *obj);
void func_021811E4(void *a, Ov018Src *src);
int func_0218123C(void *a, int *state, Ov018Outer_0218034C *c);
void func_0218152C(void *a, Ov018Src *src);
int func_02181584(void *a, int *state, Ov018Outer_0218034C *c);
void func_0218186C(void *a, Ov018Src *src);
void func_021818C4(void *a, Ov018Src *src);
void func_0218191C(Obj_021800A4 *task, const void *src);
int func_02181940(void *a, int *state, Ov018Outer_0218191C_b *c);
void func_021819D0(Obj_021800A4 *task, const void *src);
int func_021819F4(void *a, int *state, Ov018Outer_0218191C_b *c);
void func_02181A74(Obj_021800A4 *task, const void *src);
int func_02181A98(void *a, int *state, Ov018Outer_0218191C_b *c);
void func_02181B44(Obj_021800A4 *task, const void *src);
int func_02181B68(void *a, int *state, Ov018Outer_0218191C_b *c);
void func_02181BE8(Obj_021800A4 *task, const void *src);
int func_02181C0C(void *a, int *state, Ov018Outer_02181BE8 *c);
void *func_02181D8C(void *a, void *b);
int func_02181DD4(void *a, int *state, Ov018Obj_02181DD4 *c);
void func_02181E6C(Obj_021800A4 *task, const void *src);
int func_02181E90(void *a, int *state, Ov018Outer_0218191C_b *c);
void func_02181F10(Obj_021800A4 *task, const void *src);
int func_02181F34(void *a, int *state, Ov018Outer_0218191C_b *c);
void func_02181FB4(Obj_021800A4 *task, const void *src);
int func_02181FD8(void *a, int *state, Outer_0218191C *c);
void func_02182080(void *a, void *b);
int func_021820A4(void *a, int *state, Outer_0218191C *c);
void *func_02182124(void *a, void *unused, Rec_021800A4 *b);
int func_02182150(void *a, int *state, int c);
void *func_021821B0(void *a, Src *b);
int func_02182214(void *a, int *state, Ov018Work *c);
void func_0218236C(void *a, void *b);
int func_021823A8(void *a, int *state, Outer_021821B0 *c);
void func_021825F8(void *a, void *b);
int func_0218261C(void *a, int *state, Outer_021825F8 *c);
extern Tmpl_0217C758 d_02183AF0;
extern Tmpl_0217C758 g_02183AF0;
extern char str_02183B14[];
extern char str_02183B28[];
extern unsigned char d_021836B4[];
extern const struct BgTemplate d_0218370C;
extern const struct BgTemplate d_0218372C;
extern const char d_02183B14[];
extern const Rect_0217DAA8 d_021836CC;
extern const Ent d_02176AA0[];
extern const Rect_0217DAA8 d_021836E4;
extern const Rect_0217DAA8 d_021836DC;
extern const Rect_0217DAA8 d_021836D4;
extern const Rect_0217DAA8 d_021836EC;
extern const Rect_0217DAA8 d_021836C4;
extern const unsigned short d_021836AA[];
extern const Tmpl_0217DAA8 d_021836F4;
extern const s8 d_021836A4[3][2];
extern unsigned char d_02183B2C[];
extern char str_02183B30[];
extern char d_02183B30[];
extern char d_02183B44[];
extern char str_02183B48[];
extern u16 d_0218383C[];
extern u16 d_02183870[];
extern u16 d_0218387A[];
extern u16 d_02183884[];
extern u16 d_02183848[];
extern u16 d_02183866[];
extern u8 ov083_id[];
extern u16 d_02183852[];
extern u16 d_0218385C[];
extern u16 d_021838B8[];
extern const u16 d_02183890[];
extern const u16 d_021838A4[];
extern const u16 d_021838AE[];
extern u16 d_0218389A[];
extern const u16 d_021838F6[];
extern const u16 d_02183900[];
extern const u16 d_0218390A[];
extern const u16 d_02183914[];
extern const u16 d_0218391E[];
extern const u16 d_021838C4[];
extern const u16 d_021838CE[];
extern const u16 d_021838D8[];
extern const u16 d_021838E2[];
extern const u16 d_021838EC[];
extern unsigned short d_02183928[];
extern unsigned short d_0218393C[];
extern unsigned short d_02183932[];
extern unsigned short d_02183946[];
extern const u16 d_02183950[];
extern const u16 d_0218395A[];
extern const u16 d_02183964[];
extern unsigned short d_02183970[];
extern unsigned short d_02183984[];
extern u16 d_0218397A[];
extern u16 d_0218398E[];
extern const u16 d_02183998[];
extern const u16 d_021839E0[5][5];
extern const u16 d_021839A4[6][5];





/*
 * Initialises a 0x18-byte record (cleared by the fill below) and, when the
 * last argument is set, places its field object. The pool carries
 * 0x02183AF0 twice (stores, then call arguments), so two extern names:
 * see docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 */
void func_0217C758(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind,
                   u8 flag, u16 idx, int place)
{
    int sys;
    void *obj;
    int zone;
    int x;
    int y;

    func_02082BCC(r, 0, 0x18);
    r->f0 = a1;
    r->f4 = a2;
    r->fC = id;
    r->fE = kind;
    r->fF = flag;
    r->fA = 15;
    r->f8 = r->fA;
    r->f13 = idx;
    if (place != 0) {
        sys = func_02012964(func_020120F4(a1));
        obj = func_021A3074(func_02188CB4(a2));
        zone = func_02188C9C(a2);
        d_02183AF0.f2 = func_0216D598(obj);
        d_02183AF0.fC = idx;
        x = func_0216D83C(obj);
        y = func_0216D86C(obj);
        func_0216E618(((Tmpl_0217C758 *)&g_02183AF0), x, y, func_0216D8AC(obj));
        r->f14 = func_0216CE60(sys, ((Tmpl_0217C758 *)&g_02183AF0), zone);
        func_0217BCDC(a3, r->f0, r->fC, r->fE, r->fF);
        func_0216DAC8(obj, 1);
        func_0216DAC8(r->f14, 0);
    }
}
void func_021828A8(void *a, void *b);
void func_021828B0(void *a, void *b);





/*
 * Per-frame step of the 0x18-byte record (same layout as func_0217C688's).
 */
int func_0217C820(Rec *r)
{
    void *fld;
    void *obj;
    u16 anim;
    Vec v;

    fld = func_02188CB4(r->f4);
    obj = func_021A3074((void *)fld);
    switch (r->f10) {
    case 0:
        anim = r->f13 == 3 ? 7 : 6;
        func_0216D410(obj, anim);
        if (r->f14 != 0)
            func_0216D410(r->f14, anim);
        func_021A3038(fld, (struct VecFx32 *)&v);
        if (r->f13 == 3)
            v.x += 0x8000;
        else
            v.x -= 0x8000;
        func_021F37B8((int)r->f4, &v);
        func_020061E4(0x774);
        r->f10++;
        break;
    case 1:
        r->fA--;
        if (r->fA <= 0) {
            if (r->f14 != 0) {
                func_0216DAC8(obj, 0);
                func_0216DAC8(r->f14, 1);
            }
            r->f10++;
        }
        break;
    case 2:
        if (func_021F37D8(r->f4) == 0 && func_0216D454((int)obj) == 1) {
            func_0216D480(obj);
            if (r->f14 != 0)
                func_0216D480(r->f14);
            r->f10++;
        }
        break;
    case 3:
        if (r->f14 != 0) {
            func_0216CF2C((int)r->f14);
            r->f14 = 0;
        }
        return 1;
    }
    return 0;
}





int func_0217C914(u8 *v, u8 *w, u8 *state)
{
    switch (*state) {
    case 0:
        func_0217F3C4(w + 0x10, 0);
        (*state)++;
        break;
    case 1:
        if (func_02173A2C(v, v[0x154], (struct T *)(w + 0x44), w[0x41]) == 1)
            (*state)++;
        break;
    case 2:
        switch (func_02175514(v)) {
        case 1:
            *state = 6;
            break;
        case 2:
        case 3:
            *state = 3;
            break;
        default:
            if (func_0217F40C(w + 0x10) == 1) {
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    *state = 9;
                }
            }
            break;
        }
        break;
    case 3:
        if (func_0217F40C(w + 0x10) == 1) {
            func_0217F3C4(w + 0x10, 2);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(w + 0x10) == 1)
            (*state)++;
        break;
    case 5:
        if (func_0217F420() == 1)
            *state = 8;
        break;
    case 6:
        if (func_02173AE0((int)v, v[0x154], 1, v[0x158]) == 1)
            *state = 7;
        break;
    case 7:
        if (func_0217F40C(w + 0x10) == 1)
            return 1;
        break;
    case 8:
        return 2;
    case 9:
        return 3;
    }
    return 0;
}




void *func_0217CA1C(void *p)
{
    V12 v;
    func_0217BED4(0x117, &v);
    return func_02185588(p, 0x117, (const struct V3 *)(&v));
}





void *func_0217CA40(int a0)
{
    int h;
    void *c;
    int p;

    h = func_02012138((const struct Ctx *)a0);
    c = func_020120F4((const struct Ctx *)a0);
    p = func_02158344(h);
    if (p != 0) {
        func_02175710((u8 *)p, func_02012B58(c));
    } else {
        func_02012B8C(c, func_02012B58(c));
    }
    return func_0217CA1C((void *)a0);
}







int func_0217CA84(void *a, int b)
{
    void *sys;
    int ret;
    Ov018Work_0217CA84 *work;
    unsigned char *x;

    sys = (void *)func_02012138(a);
    ret = (int)func_020122C0(a, 0, func_0217CAFC, 0x28);
    work = func_020124E8((struct Obj *)ret);
    work->f20 = b;
    if (func_02026454(sys) == 2) {
        x = (unsigned char *)func_02026474(sys);
        if (x != 0) {
            func_0217C094((unsigned char *)func_02026474(sys));
            x[0x8F8] |= 0x80;
        }
    }
    if (func_02012204(a) == 1) {
        if (func_0202647C(sys) == 1) {
            work->f24 = 1;
        }
    }
    func_020061E4(0x737);
    return ret;
}







int func_0217CAFC(void *a, int *seq, Ov018Work_0217CAFC *work)
{
    void *x;
    void *s2;
    void *s1;
    void *y;
    void *z;
    void *t;
    int flag;
    int msg;
    int v;
    int r;

    x = func_020124E4(a);
    s2 = func_020120F4(x);
    s1 = (void *)func_02012138(x);
    switch (*seq) {
    case 0:
        func_02012374(a, (struct Evt **)func_0217CA40((int)x));
        (*seq)++;
        break;
    case 1:
        if (func_0200FB24() == 0 && (int)func_02026460(s1) != 0) {
            break;
        }
        if (func_0200FB24() == 0 && ((int)func_02026454(s1) == 2 || (int)func_02026454(s1) == 1)) {
            func_02026400(s1);
        }
        (*seq)++;
        break;
    case 2:
        if (func_0200FB24() == 0 && (int)func_02026454(s1) != 0) {
            break;
        }
        if (work->f24 == 1) {
            *seq = 7;
        } else {
            (*seq)++;
        }
        break;
    case 3:
        if (func_02012114(x) != 1) {
            break;
        }
        flag = 0;
        y = func_0201210C(x);
        if (func_02188BE8(y) != 1) {
            break;
        }
        z = (void *)func_02188C54(y);
        work->f00 = t = (void *)func_021904B0((u32)z, 0x2D);
        work->f04 = func_02190F64(z, (u32)t);
        switch (work->f20) {
        case 1:
        case 2:
            msg = 0x5C;
            goto set;
        default:
            msg = 0x59;
        set:
            flag = 1;
            break;
        case 0:
            switch ((int)func_0202648C(s1)) {
            case 1:
                msg = 0x5A;
                break;
            case 2:
                msg = 0x56;
                break;
            case 3:
                msg = 0x57;
                flag = 1;
                break;
            case 4:
                msg = 0x58;
                flag = 1;
                break;
            case 0:
            case 5:
            default:
                msg = 0x59;
                break;
            }
            break;
        }
        func_02190E74(work->f04, (int)0, (int)0, (int)msg);
        if (flag == 1) {
            func_02012374(a, func_02029830(x, 0x52D));
            *seq = 4;
        } else {
            *seq = 5;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(x, 0, 6));
            *seq = 5;
        }
        break;
    case 5:
        if ((int)func_02190EF0(work->f04) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            func_02190E40((u32)work->f04);
            func_02045C04(work->f00);
            (*seq)++;
        }
        break;
    case 7:
        y = func_0201210C(x);
        if (func_02188BE8(y) == 1) {
            if (func_021A3238(func_02188CB4(y)) == 0) {
                func_0217C658(work->f08, x, y, 0, 0, 0);
                (*seq)++;
            } else {
                *seq = 10;
            }
        }
        break;
    case 8:
        if (func_0217C688(work->f08, 0) == 1) {
            if (work->f24 == 1) {
                *seq = 10;
            } else {
                (*seq)++;
            }
        }
        break;
    case 9:
        if ((int)func_020142E8((void *)func_0201296C(s2), 0x980) == 0) {
            r = (int)func_0202648C(s1);
            v = 0;
            switch (r) {
            case 0:
            case 1:
                break;
            case 2:
                v = 0xC;
                break;
            case 3:
            case 4:
                v = 0xD;
                break;
            case 5:
                break;
            }
            func_02158780(a, (u16)v, 0, 0, (int)0x8015);
        }
        *seq = 10;
        break;
    case 10:
        if ((func_02012B58(s2) != 0 || (int)func_02012204(x) == 1) && func_0201212C(x) == 1) {
            func_02012374(a, (struct Evt **)func_021C06CC(x, func_0201210C(x)));
        }
        (*seq)++;
        break;
    case 11:
        func_02026484(s1);
        func_020264F4(s1);
        if (func_02012B58(s2) != 0 || (int)func_02012204(x) == 1) {
            func_02012374(a, func_02185214(x));
        }
        (*seq)++;
        break;
    case 12:
        return 1;
    }
    return 0;
}






void *func_0217CDBC(void *p)
{
    return func_020122C0(p, 0, func_0217CDD0, 0);
}






int func_0217CDD0(void *p, int *state)
{
    switch (*state) {
    case 0:
        func_02158780(p, 0x279e, 0, 0, 0x15);
        ++*state;
        break;
    case 1:
        return 1;
    }
    return 0;
}







void *func_0217CE08(void *a0, void *a1, u16 a2, int a3)
{
    int h;
    void *c;
    V12 v;

    h = func_02012138(a0);
    c = func_020120F4(a0);
    func_02158344(h);
    if (func_0217BED4(a2, &v) == 0)
        return 0;
    if (func_02012B70(c) == 0 && a2 == 0x117)
        return func_02185140(a0, a2, &v, a3);
    return func_02185588(a0, a2, &v);
}







void *func_0217CE6C(void *a0, void *a1, int a2)
{
    u8 *p;
    u32 *q;
    V12 v;
    u16 s;

    p = (u8 *)func_02158344(func_02012138(a0));
    if (p == 0 || !(p[0x8FB] & (1 << a2)))
        return 0;
    q = func_0217BEA8(*(u16 *)(p + a2 * 0x1C + 0xA0));
    if (q == 0)
        return 0;
    s = (*q << 2) >> 22;
    v = *(V12 *)(p + a2 * 0x1C + 0x90);
    v.z += 0x20000;
    return func_02184D38(a0, (int)a1, s, (const int *)(&v), 0, 0);
}






void *func_0217CEE8(void *p, int a, int b)
{
    void *task;
    int *work;
    task = func_020122C0(p, 0, func_0217CF0C, 12);
    work = func_020124E8(task);
    work[0] = a;
    work[1] = b;
    return task;
}







int func_0217CF0C(int a0, int *state, Obj_0217CF0C *o)
{
    switch (*state) {
    case 0:
        o->f8 += 1;
        if (o->f8 > 15) {
            func_021D324C(func_02188E30((u8 *)o->f0), -16);
            *state += 1;
        }
        break;
    case 1:
        func_021A0F40((u32 *)o->f4, 0);
        *state += 1;
        break;
    case 2:
        func_021D324C(func_02188E30((u8 *)o->f0), 0);
        *state += 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}






int func_0217CF68(void *unused, void *p)
{
    void *sys;
    void *obj;
    sys = func_0215A5DC(p);
    obj = func_0201210C(sys);
    func_02012138(sys);
    func_0217BF84((int)obj);
    return 0;
}







int func_0217CF88(int a0, int a1)
{
    void *w;
    void *c;
    int h;
    int v;

    w = func_0215A5DC((void *)a1);
    func_020120F4((const struct Ctx *)w);
    c = func_0201210C((void *)w);
    h = func_02012138(w);
    v = 0;
    if (func_02026454((void *)h) == 2)
        v = func_02026474((void *)h);
    if (v != 0) {
        func_0217BBCC((int)c, (int)w, (char *)v);
        func_0217BBD8((u8 *)c, (int)w, (u8 *)v);
    } else {
        func_0217BC94((int)c, 1);
    }
    func_0217C194(c);
    return 0;
}






u8 *func_0217CFE4(void *a)
{
    void *s;
    u8 *w;
    u8 *p;
    void *bg;
    int i;
    int q;
    int k;
    u32 tmp;

    s = (void *)func_02012138(a);
    w = func_02030734(0x70, 0x170, 1, str_02183B14, 0x240);
    ((struct Obj02674 *)w)->f0 = a;
    w[0x105] = 0xFF;
    w[0x11B] = 0xFF;
    w[0x169] = 4;
    w[0x16A] = 4;
    ((struct Obj02674 *)w)->f10A = -1;
    for (i = 0; i < 3; i++) {
        *(u16 *)(w + 0xF0 + i * 8) = 0x1AB;
    }
    p = 0;
    if (func_02026454(s) == 2) {
        p = (u8 *)func_02026474(s);
    }
    if (p != 0 && ((FlagsF8_0217C758 *)(p + 0x8F8))->b == 1) {
        p = 0;
    }
    func_0217EFCC((char *)w, (char *)p);
    w[0x11E] = w[0xDA];
    bg = func_020490F4(0x24, 0x15);
    func_0217D624((struct State *)w);
    func_0217D720(w, bg);
    func_0217D890((S *)w);
    func_0217D918(w, bg);
    func_0217DA54(w, bg);
    func_02049238(bg);
    func_0203D34C(0, 0x15);
    func_02037174();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    ((struct Obj02674 *)w)->f34 = func_020056A0((void (*)(void))func_0217D5AC, w, 10);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj02674 *)w)->f0));
    k = (int)func_0217EBD8(w);
    func_0217E638(w, q);
    func_0217DE68(w, k);
    func_0217E014(w, k);
    func_0217E0F4(w, (u8 *)func_02158344((int)s), k);
    ((void (*)())func_0217E3D0)(w, k, q);
    func_0217E4D0((int *)w, k);
    func_0217E524(w, k);
    return w;
}






void func_0217D160(int a0)
{
    func_02030EAC((struct Node *)(((struct Obj00703 *)a0)->f34));
    func_02082A48(0, 0x05000400, 2);
    func_0217DE44((void **)a0);
    func_0217DA90((void **)a0);
    func_0217DA18((u32 *)a0);
    func_0217D904((char *)a0);
    func_0217D870(a0);
    func_0217D6C8((int *)a0);
    func_020307B0((void *)a0);
    func_02037190();
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u16 *)0x04001050 = 0;
}






void func_0217D1C0(u8 *w, int b)
{
    void *s1;
    void *s2;
    u8 *p;
    int q;
    int i;
    int v;
    void *h;

    s1 = (void *)func_02012138(((struct Obj00399 *)w)->f0);
    s2 = func_020120F4(((struct Obj00399 *)w)->f0);
    p = (u8 *)func_02158344((int)s1);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj00399 *)w)->f0));
    func_0201058C((void *)func_0201283C(s2));
    func_02037174();
    if (p == 0 || (p != 0 && ((FlagsF8_0217C758 *)(p + 0x8F8))->b == 0)) {
        func_0217F008((char *)w, (char *)p);
    }
    if (w[0x11E] < w[0xDA]) {
        if (func_02012B70(s2) == 1) {
            func_020061E4(0x699);
        }
        w[0x11E] = w[0xDA];
    }
    func_020310C4(((struct Obj00399 *)w)->f20);
    func_0201C4E4(((struct Obj00399 *)w)->f28);
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x48] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f44)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f44);
            w[0x48] = 0;
        }
    }
    h = ((struct Obj00399 *)w)->f28;
    if (w[0x50] != 0) {
        if (func_0201C6C4(h, func_02045770(((struct Obj00399 *)w)->f4C)) == 0) {
            func_02045334(((struct Obj00399 *)w)->f4C);
            w[0x50] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (func_0201C6C4(((struct Obj00399 *)w)->f28, *(void **)(w + 0xB4 + i * 4)) == 0) {
            func_020257D0(*(void **)(w + 0xC0 + i * 4));
        }
    }
    if (b == 0) {
        if (func_0217F0FC(w) == 1 || w[0x116] == 1) {
            REG_DB_BLDCNT_SUB = 0;
        } else {
            G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
            return;
        }
    } else {
        REG_DB_BLDCNT_SUB = 0;
    }
    if (b == 1) {
        func_0217EC7C(p, w, q);
    }
    if (p != 0 && w[0x106] == 1) {
        v = func_0215841C(s2);
        if ((int)func_0203D1C0((u8)v) == 0) {
            w[0x106] = 0;
            return;
        }
        switch (w[0x107]) {
        case 0:
            if (func_021746AC((char *)p, (u8)v) == 1) {
                w[0x107]++;
            }
            break;
        case 1:
            if (func_02158428(p) == 1) {
                func_02188CCC(func_0201210C(((struct Obj00399 *)w)->f0));
                ((struct Obj00399 *)w)->f110 = 0x126;
                w[0x112] = 1;
                w[0x106] = 0;
            }
            break;
        default:
            func_02034714(str_02183B28, 0, str_02183B28);
            break;
        }
    }
}





void func_0217D3AC(Ov018Menu_0217D3AC *w)
{
    void *s1;
    void *s2;
    unsigned char *p;
    int q;
    int flag;
    int k;

    s1 = (void *)func_02012138(w->f0);
    s2 = func_020120F4(w->f0);
    p = (unsigned char *)func_02158344((int)s1);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(w->f0));
    flag = 0;
    k = (int)func_0217EBD8((u8 *)w);
    if (p != 0 && func_02175DA8(p + 0x1AC) == 0) {
        flag = 1;
    } else if (p == 0 && func_02012B70(s2) == 1 && func_02026454(s1) != 2
               && func_0202648C(s1) == 0 && func_02013D5C(q) == 1) {
        flag = 1;
    }
    if (p != 0 && ((FlagsF8_0217D3AC *)(p + 0x8F8))->b == 1) {
        flag = 0;
    }
    if (flag == 1) {
        func_0217EEB4((int *)w);
        func_0217EF44(w, p);
        func_0217E638((u8 *)w, q);
        ((void (*)())func_0217E714)(w, p, q);
        func_0217DE68((u8 *)w, k);
        func_0217E014((u8 *)w, k);
        func_0217E0F4((u8 *)w, p, k);
        ((void (*)())func_0217E3D0)((u8 *)w, k, q);
        func_0217E4D0((int *)w, k);
        func_0217E524((u8 *)w, k);
        func_0217F194(w);
        return;
    }
    if (p != 0 && func_02175DA8(p + 0x1AC) == 1 && func_02175B8C(p + 0x1AC) == 1
        && w->f16C == 0 && w->fE0 == 0) {
        func_0217E524((u8 *)w, k);
        w->f16C = 1;
    }
}





void *func_0217D4DC(Ov018Menu_0217D4DC *w, int b, int c)
{
    void *s1;
    void *s2;
    void *r;
    void *ret;

    s1 = (void *)func_02012138(w->f0);
    s2 = func_020120F4(w->f0);
    r = func_0201210C(w->f0);
    ret = 0;
    if (b == 0 || r == 0) {
        return 0;
    }
    if (w->f168 == 1 || (func_02012B70(s2) == 0 && func_02158344((int)s1) == 0)) {
        func_020061E4(0x551);
        func_0217F174((u8 *)w);
        return func_0217CEE8(w->f0, (int)r, c);
    }
    switch (w->f112) {
    case 1:
        func_020061E4(0x737);
        func_0217F0C4((u8 *)w);
        ret = func_0217CE08(w->f0, r, w->f110, 0);
        break;
    case 2:
        func_020061E4(0x737);
        ret = func_0217CE6C(w->f0, r, func_02158378(s1));
        break;
    }
    if (ret != 0) {
        w->f112 = 0;
        return ret;
    }
    return 0;
}





void func_0217D5AC(int a0, u8 *p)
{
    p[0x11D] ^= 1;
    if (p[0x11D] != 0) {
        if (p[0x11C] != 0) {
            func_020862F0(p + 0x130, 8);
            func_0207E5D0(p + 0x130, 0x102, 8);
            p[0x11C] = 0;
        }
        if (p[0x10F] != 0) {
            func_020862F0(((struct Obj03091 *)p)->fD0, 0x200);
            func_0207E804(((struct Obj03091 *)p)->fD0, ((struct Obj03091 *)p)->fD4, 0x200);
            p[0x10F] = 0;
        }
    }
}





void func_0217D624(struct State *o)
{
    struct Obj *t;

    o->bank = func_0204B100(0x29, 5, 0x70);
    t = func_0204B034(d_021836B4, 1, 0x70);
    o->obj = t;
    func_0204B258(o->bank, t);
    o->unkB0 = func_02025538(0x70, o->bank);
    o->tcbl = func_0203101C(0x70, 0x70, 4, 0x20);
    o->font = func_0201D7EC(0x17, 0, 0, 0, 0x70);
    o->words = func_0201EC64(0x70);
    o->unk28 = func_0201C440((void *)0x70);
    o->msg2C = func_02045B38(0, 2, 0x2D, 0x70);
    o->msg30 = func_02045B38(0, 2, 0x42, 0x70);
    o->str38 = func_020457B0(0x80, 0x70);
    o->str3C = func_020457B0(0x80, 0x70);
    o->str40 = func_020457B0(0x80, 0x70);
}





void func_0217D6C8(int *p)
{
    func_02045808((struct U16Vec *)p[0x38 / 4]);
    func_02045808((struct U16Vec *)p[0x3c / 4]);
    func_02045808((struct U16Vec *)p[0x40 / 4]);
    func_02045C04((struct Rec *)p[0x2c / 4]);
    func_02045C04((struct Rec *)p[0x30 / 4]);
    func_0201C6EC((struct PrintSys *)p[0x28 / 4]);
    func_0201C4C0((struct PrintSys *)p[0x28 / 4]);
    func_0201ED04((struct WordSet *)p[0x24 / 4]);
    func_0201D83C((void *)p[0x1c / 4]);
    func_02031140((struct S02031140 *)p[0x20 / 4]);
    func_02025588((void *)p[0xb0 / 4]);
    func_0204B084(p[0x58 / 4]);
    func_0204B1CC((struct Bank *)p[0x54 / 4]);
}





void func_0217D720(u8 *w, void *bg)
{
    int layer;
    u8 *pal;
    void *res;

    layer = 6;
    func_0203FCA0(6, &d_0218370C, 0);
    func_0203FCA0(7, &d_0218372C, 0);
    MIi_CpuClear32(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    func_02049658(bg, 4, 7, 0, 0, 1, 0x15);
    func_020498F4(bg, 5, 7, 0, 0x800, 1, 0x15);
    if (w[0xDA] <= 1) {
        w[0x11F] = 0;
    } else {
        layer = 7;
        w[0x11F] = 1;
    }
    func_020498F4(bg, layer, 6, 0, 0x800, 1, 0x15);
    func_0217EF70((int *)w, w[0xD8]);
    res = func_02049EF4(bg, 8, 1, (void **)&pal, 0x15);
    MIi_CpuCopy16(pal + 0xC, w + 0x138, 0x30);
    func_020307B0(res);
    if (func_0217F1E8(w) == 1) {
        func_0217F240(w, 0);
    }
    func_02049B68(bg, 9, 4, 0, 0x140, 0x15);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, 0x15);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
}




void func_0217D870(int a0)
{
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020403F4(6);
    func_020403F4(7);
}





void func_0217D890(S *p)
{
    int r;
    int r2;
    char z;

    z = 0;
    r = func_020450F0(6, 0, 0, 0x20, 2, 14, 1);
    p->a = r;
    p->b = z;
    func_02045334((struct Descriptor *)r);
    func_02045374((struct Cfg *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    r2 = func_020450F0(6, 1, 0x12, 0x1e, 4, 14, 1);
    p->c = r2;
    p->d = z;
    func_02045334((struct Descriptor *)r2);
    func_02045374((struct Cfg *)r2);
    func_020409B4(func_02045730((struct Descriptor *)r2));
}




void func_0217D904(char *p)
{
    func_020452E8(*(struct Descriptor * *)&((struct Obj00703 *)p)->f44);
    func_020452E8(*(struct Descriptor * *)&((struct Obj00703 *)p)->f4C);
}





void func_0217D918(u8 *p, void *bg)
{
    void *t;

    ((struct Obj02676 *)p)->f8 = (void *)func_0204AC18(bg, 3, 1, 0, 0, 9, 0x15);
    ((struct Obj02676 *)p)->f4 = (void *)func_0204A6C8(bg, 0, 1, 1, 0x15);
    ((struct Obj02676 *)p)->f10 = (void *)func_0204AF28(bg, 1, 2, 0x70);
    t = func_020490F4(0x17, 0x15);
    ((struct Obj02676 *)p)->fC = (void *)func_0204ACEC(t, 5, 1, 0x1a0, 0x15);
    func_02049238(t);
    ((struct Obj02676 *)p)->f14 = (void *)func_0204A6C8(bg, 10, 1, 1, 0x15);
    ((struct Obj02676 *)p)->f18 = (void *)func_0204AF28(bg, 12, 13, 0x70);
    ((struct Obj02676 *)p)->fC8 = func_02049DF4(bg, 10, 1, (unsigned int)(p + 0xcc), 0x70);
    ((struct Obj02676 *)p)->fD4 = (void *)func_0204ABBC((unsigned int)(((struct Obj02676 *)p)->f14), 2);
    ((struct Obj02676 *)p)->fD0 = func_02030734(0x70, 0x200, 1, d_02183B14, 0x495);
    func_02082A60((void *)0x050006E2, p + 0x120, 8);
    func_02082A60(p + 0x120, p + 0x130, 8);
    func_02082A60((void *)0x05000702, p + 0x128, 8);
}




void func_0217DA18(u32 *p)
{
    func_020307B0((void *)p[0xd0 / 4]);
    func_020307B0((void *)p[0xc8 / 4]);
    func_0204ADA4(p[3]);
    func_0204ADA4(p[2]);
    func_0204A8D4(p[1]);
    func_0204A8D4(p[5]);
    func_0204AFD8(p[4]);
    func_0204AFD8(p[6]);
}




/*
 * interface: r1 is visibly restored before every call; preserve incoming bg.
 * Callees' matched definitions omit this unused input; no callee edits.
 */
void func_0217DA54(void *p, void *bg)
{
    func_0217DAA8(p, bg);
    func_0217DB4C(p, bg);
    func_0217DBAC(p, bg);
    func_0217DC14(p, bg);
    func_0217DC9C(p, bg);
    func_0217DCFC(p, bg);
    func_0217DD48(p, bg);
}




void func_0217DA90(void **p)
{
    int i;
    for (i = 0; i < 21; i++) func_0204B3B4(p[23 + i]);
}




void func_0217DAA8(int *p, void *a1)
{
    Rect_0217DAA8 r;
    int i;

    r = d_021836CC;
    for (i = 0; i <= 7; i++) {
        r.a = d_02176AA0[i].x;
        r.b = d_02176AA0[i].y;
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
        func_0204B92C((struct Obj *)p[0x5c / 4 + i], 1);
    }
    r.c = 8;
    r.a = 0x80;
    r.b = 0x5c;
    p[0x7c / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
    func_0204B3DC((struct Obj *)p[0x7c / 4], 0);
    func_0204B92C((struct Obj *)p[0x7c / 4], 1);
}




void func_0217DB4C(int *p, void *a1)
{
    Rect_0217DAA8 r;
    int i;

    r = d_021836E4;
    for (i = 9; i <= 11; i++) {
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 8), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
    }
}




void func_0217DBAC(int *p, void *a1)
{
    Rect_0217DAA8 r;
    int i;

    r = d_021836DC;
    for (i = 12; i <= 14; i++) {
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 11), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
        func_0204B92C((struct Obj *)p[0x5c / 4 + i], 1);
    }
}




void func_0217DC14(int *p, void *a1)
{
    Rect_0217DAA8 r;
    int h;

    r = d_021836D4;
    h = (int)func_020120F4((const struct Ctx *)p[0]);
    if (func_02008550((const struct Sub0200852CObj *)func_02012944((void *)h)) == 1) {
        r.c = 3;
    }
    p[0x98 / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
    func_0204B6F4((struct Obj *)p[0x98 / 4], (u8)(func_02012B58((const struct BigObj *)h) + 1), 1);
    func_0204B3DC((struct Obj *)p[0x98 / 4], 0);
    func_0204B92C((struct Obj *)p[0x98 / 4], 1);
}




void func_0217DC9C(int *p, void *a1)
{
    Rect_0217DAA8 r;
    int i;

    r = d_021836EC;
    for (i = 17; i <= 19; i++) {
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 16), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
    }
}




void func_0217DCFC(int *p, void *a1)
{
    Rect_0217DAA8 r;
    int h;

    r = d_021836C4;
    h = func_0217F1E8((u8 *)p);
    p[0xac / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[5], p[2], p[6], &r, 0, 0x70);
    func_0204B3DC((struct Obj *)p[0xac / 4], h);
}




void func_0217DD48(Work_0217DD48 *p, void *z2)
{
    void *sys;
    int i;
    void *str;
    Tmpl_0217DAA8 a;
    Tmpl_0217DAA8 t;

    sys = func_020120F4(p->f00);
    p->f9c = func_0204B294(p->f54, (unsigned int)p->f04, (unsigned int)p->f08, (unsigned int)p->f10, d_021836AA, 0, 0x70);
    func_0204B3DC(p->f9c, 0);
    t = d_021836F4;
    for (i = 0; i < 2; i++) {
        a = t;
        p->fb4[i] = func_02043678(6, 2, 0x20, 0x70);
        a.f00 = p->fb4[i];
        a.f08 = p->f0c;
        p->fc0[i] = func_020255A0(p->fb0, (const struct Param *)(&a));
        func_02025774(p->fc0[i], 0);
        str = func_02045EC0(p->f2c, i + 0x45);
        func_0201C724(p->f28, (u32)p->fb4[i], 0, 0, (u32)str, (u32)p->f1c, 0x3c40);
        func_02045808(str);
    }
    if (p->f168 == 0 && func_02012B70(sys) == 0) {
        func_0204B3DC(p->f9c, 1);
        func_02025774(p->fc0[1], 1);
    }
}



void func_0217DE44(void **p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_0202570C(p[0xc0 / 4 + i]);
        func_020437AC(p[0xb4 / 4 + i]);
    }
}




void func_0217DE68(void *p_v, int z2)
{    Work_0217DE68 *p = (Work_0217DE68 *)p_v;
    void *sys;
    int i;
    int c;
    int q;
    void *act;

    sys = func_020120F4(p->f00);
    if (func_0217F284((u8 *)p) == 1) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 0);
        }
        func_0204B3DC(p->f7c, 0);
    } else if (p->fd8 == func_02012B58(sys) || func_02012B70(sys) == 0) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 0);
        }
        func_0204B3DC(p->f7c, 0);
    } else {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 1);
        }
        func_0204B3DC(p->f7c, 1);
    }
    for (i = 6; i <= 8; i++) {
        func_02082A60((void *)(0x05000602 + (p->fd8 + 1) * 32), (void *)(0x0500060C + i * 32), 2);
    }
    if (p->f114 == 1) {
        if (p->f115 % 2 == 0) {
            if (((unsigned)p->f115 >> 1) & 1) {
                c = 6;
            } else {
                c = 7;
            }
            q = p->f113;
            if (q != 8) {
                act = p->f5c[q];
            } else {
                act = p->f7c;
            }
            func_0204B6F4(act, (u8)c, (int)1);
        }
        if (p->f115 < 10) {
            p->f115++;
        }
        return;
    }
    if (p->f11b == 0xff) {
        return;
    }
    if (p->f11a == 0) {
        p->f118 += 0x100;
        if (p->f118 >= 0x1100) {
            p->f118 = 0x2000 - p->f118;
            p->f11a = 1;
        }
    } else {
        p->f118 -= 0x100;
        if (p->f118 < 0) {
            p->f118 = 0x100 - p->f118;
            p->f11a = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        func_02021F64(&p->f120[i], &p->f130[i], 1, p->f118 >> 8, p->f128[i]);
    }
    p->f11c = 1;
}




#pragma opt_propagation off



/*
 * final push 2026-10-05 G7L8: closed with opt_propagation off, a named slot
 * pointer `s` (declared first, assigned after the call, used for the three
 * zero stores and the first loop), n zeroed right before the first loop,
 * do-while loops (for loops gain entry guards under the pragma), an explicit
 * `if (n > 0)` guard on the second loop, and the mask test written as
 * `p[0xd9] & (1 << i)`.
 */
void func_0217E014(u8 *p, int a1)
{
    u8 *s;
    void *act;
    int cur;
    int sel;
    int max;
    int n;
    int i;
    int j;
    Layout l;

    func_020120F4(*(void **)p);
    s = l.slot;
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
    max = p[0xda];
    cur = p[0xd8];
    sel = 0;
    l.pos.y = 0x1c;
    n = 0;
    i = 0;
    do {
        if (p[0xd9] & (1 << i)) {
            s[n] = i;
            if (i == cur) {
                sel = n;
            }
            n++;
        }
        i++;
    } while (i < 3);
    j = 0;
    i = 0;
    if (n > 0) {
        do {
            if (sel != i) {
                if (l.slot[i] == cur + 1 || (l.slot[i] == 0 && cur == max - 1)) {
                    l.pos.x = 0xa0;
                } else {
                    l.pos.x = 0x60;
                }
                act = ((void **)(p + 0x80))[j];
                func_0204B404(act, (const struct Vec2 *)(&l.pos), 0);
                func_0204B6F4(act, (u8)(l.slot[i] + 1), 1);
                func_0204B3DC(act, 1);
                j++;
            }
            i++;
        } while (i < n);
    }
    for (; i < 3; i++) {
        func_0204B3DC(((void **)(p + 0x80))[i], 0);
    }
}



#pragma opt_propagation reset




void func_0217E0F4(void *p_v, void *m_v, int z3)
{    Mon_Ents *m = (Mon_Ents *)m_v;    Work_0217E0F4 *p = (Work_0217E0F4 *)p_v;
    void *sys;
    int cur;
    int i;
    int k;
    void *a;
    Ent_0217E0F4 *e;
    u8 *prev;
    u16 previd;
    u8 *obj;
    void *b;
    Pair l;

    sys = func_020120F4(p->f00);
    cur = p->fd8;
    func_0217E2E0(p);
    for (i = 0; i < 3; i++) {
        obj = 0;
        prev = p->fec[i].ptr;
        previd = p->fec[i].id;
        if (i != func_02012B58(sys)) {
            p->fec[i].ptr = 0;
            p->fec[i].id = 0x1ab;
        }
        a = p->f8c[i];
        b = p->fa0[i];
        if (i == func_02012B58(sys)) {
            func_0204B3DC(a, 0);
            func_0204B3DC(b, 0);
            continue;
        }
        if (m == 0) {
            func_0204B3DC(a, 0);
            func_0204B3DC(b, 0);
            continue;
        }
        if (p->fd9 & (1 << i)) {
            e = &m->ent[i];
        } else {
            func_0204B3DC(a, 0);
            func_0204B3DC(b, 0);
            continue;
        }
        if (e->hi == 2) {
            func_0204B954(a, 0x2000);
        } else {
            func_0204B954(a, 0x1000);
        }
        if (e->lo == cur) {
            if (func_02013D5C(e->f14) == 1) {
                l.p.x = d_021836A4[i][0] + 0x80;
                l.p.y = d_021836A4[i][1] + 0x4c;
                func_0204B3DC(b, 0);
            } else {
                if (e->f14 != previd) {
                    obj = func_0217BEA8(e->f14);
                } else {
                    obj = prev;
                }
                if (obj != 0) {
                    l.p.x = obj[0xa] + d_021836A4[i][0];
                    l.p.y = obj[0xb] + d_021836A4[i][1];
                    func_0204B3DC(b, 0);
                } else {
                    l.p.x = 0xe8;
                    l.p.y = i * 0x18 + 0x50;
                    l.p2 = l.p;
                    l.p2.x = 0xf0;
                    func_0204B404(b, (const struct Vec2 *)(&l.p2), 0);
                    func_0204B3DC(b, 1);
                }
            }
            func_0204B404(a, (const struct Vec2 *)(&l.p), 0);
            p->fec[i].ptr = obj;
            p->fec[i].id = e->f14;
        } else {
            func_0204B3DC(b, 0);
            for (k = 0; k < 3; k++) {
                if (func_0204B714(p->f80[k]) == i + 1) {
                    func_0204B454(p->f80[k], (struct PtS *)&l.p, 0);
                    break;
                }
            }
            if (k == 3) {
                func_0204B3DC(a, 0);
                continue;
            }
            l.p.x += d_021836A4[i][0];
            l.p.y += d_021836A4[i][1];
            func_0204B404(a, (const struct Vec2 *)(&l.p), 0);
        }
        func_0204B3DC(a, 1);
    }
}







void func_0217E2E0(void *p_v)
{    Work *p = (Work *)p_v;
    int sel;
    int v;
    int c;
    u16 buf[16];

    if (p->fdc == 3 && p->fe4 != 0) {
        sel = p->fe4[0x28];
        c = -1;
        v = p->f16a;
        if (v != 4 && v != sel) {
            func_0204B6F4(p->f5c[v + 12], (u8)(v + 1), (int)1);
        }
        if (p->f16a != sel) {
            func_02082A60((void *)(0x05000600 + (sel + 1) * 32), buf, 0x20);
            func_02021F64(buf, buf, 0x10, 8, 0x7fff);
            func_02082A60(buf, (void *)0x05000720, 0x20);
            p->f16a = sel;
        }
        p->f16b++;
        if (p->f16b == 15) {
            c = 9;
        } else if (p->f16b >= 30) {
            c = sel + 1;
            p->f16b = 0;
        }
        if (c != -1) {
            func_0204B6F4(p->f5c[sel + 12], (u8)c, (int)1);
        }
        return;
    }
    v = p->f16a;
    if (v != 4) {
        func_0204B6F4(p->f5c[v + 12], (u8)(v + 1), (int)1);
        p->f16a = 4;
        p->f16b = 0;
    }
}







void func_0217E3D0(void *p_v, int a1, u16 id)
{    Obj *p = (Obj *)p_v;
    s16_0217E2E0 pos[2];
    int sel;
    int idx;
    Mon_0217E524 *m;
    int i;
    int v;
    int h;

    idx = func_02012B58(func_020120F4((const struct Ctx *)p->f00));
    sel = 0xFF;
    if (func_02013D5C(id) == 1) {
        pos[0] = d_021836A4[idx][0] + 0x80;
        pos[1] = d_021836A4[idx][1] + 0x4C;
        sel = 8;
        p->slots[idx].mon = 0;
    } else {
        if (id != p->slots[idx].id) {
            m = func_0217BEA8(id);
        } else {
            m = p->slots[idx].mon;
        }
        p->slots[idx].mon = m;
        p->slots[idx].id = id;
        if (m != 0) {
            pos[0] = m->x + d_021836A4[idx][0];
            pos[1] = m->y + d_021836A4[idx][1];
            v = m->id;
            for (i = 0; i < 8; i++) {
                if (v == d_02176AA0[i].a || v == d_02176AA0[i].b) {
                    sel = i;
                    break;
                }
            }
        } else {
            pos[0] = 0xE8;
            pos[1] = idx * 0x18 + 0x50;
            sel = 0xFF;
            p->slots[idx].mon = 0;
        }
    }
    h = p->f98;
    func_0204B404((struct Obj *)h, (const struct Vec2 *)pos, 0);
    func_0204B3DC((struct Obj *)h, 1);
    func_0217F118(p, sel);
    p->slots[idx].id = id;
}






void func_0217E4D0(int *p, int a1)
{
    int h;

    h = (int)func_020120F4((const struct Ctx *)p[0]);
    if (*((u8 *)p + 0xe9) == 0 && func_02012B70((const struct BigObj *)h) == 1) {
        switch (p[0xdc / 4]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0204B3DC((struct Obj *)p[0x9c / 4], 0);
            func_02025774((u8 *)p[0xc0 / 4], 0);
            break;
        }
    }
}







void func_0217E524(void *p_v, int z2)
{    Obj_0217E524 *p = (Obj_0217E524 *)p_v;
    int h;
    int v;
    int i;
    int rem;
    u8 *base;

    h = (int)func_020120F4((const struct Ctx *)p->f00);
    if (func_0217F1E8((u8 *)p) == 0) {
        if (func_0204B3F4((struct Obj_0217E524 *)p->fAC) == 1) {
            func_0204B3DC((struct Obj_0217E524 *)p->fAC, 0);
            func_0217F214();
        }
        return;
    }
    if (func_0204B3F4((struct Obj_0217E524 *)p->fAC) == 0) {
        func_0204B3DC((struct Obj_0217E524 *)p->fAC, 1);
        func_0217F240((u8 *)p, 1);
    }
    func_020127B8((void *)h);
    v = p->fE0;
    if (p->f10A != -1 && p->f10A != v && v <= 5 && p->fDC == 3) {
        func_020061E4(0x550);
    }
    if (p->f10A == v) {
        return;
    }
    base = p->fCC->f14;
    p->f10A = v;
    for (i = 0; i < 3; i++) {
        rem = v % 10;
        v = v / 10;
        MIi_CpuCopy32(base + rem * 0x40, p->fD0 + (2 - i) * 0x40, 0x40);
        MIi_CpuCopy32(base + (rem * 0x40 + 0x280), p->fD0 + ((2 - i) * 0x40 + 0x100), 0x40);
    }
    p->f10F = 1;
}







void func_0217E638(void *p_v, int z2)
{    Obj_0217E638 *p = (Obj_0217E638 *)p_v;
    int h;
    int anim;
    int mode;
    int v;

    h = (int)func_020120F4((const struct Ctx *)p->f00);
    if (func_0201C6C4((struct PrintSys *)p->f28, (void *)((int)func_02045770((struct Descriptor *)p->f44))) == 1) {
        return;
    }
    if (func_02012B70((const struct BigObj *)h) == 1) {
        v = p->fD8;
        if (v == func_02012B58((const struct BigObj *)h)) {
            mode = 2;
            anim = 0x43;
        } else {
            mode = v + 3;
            anim = 0x44;
        }
    } else {
        mode = 7;
    }
    if (p->f10C == mode || mode == 0) {
        return;
    }
    p->f10C = mode;
    if (mode == 7) {
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f44)), 0);
        func_02045334((struct Descriptor *)p->f44);
        return;
    }
    if (mode >= 3 && mode <= 6) {
        func_0201F02C((struct WordSet *)p->f24, 0, func_02012950((struct Sub24 *)h, p->fD8));
    }
    func_02045CAC((struct MsgBank *)p->f2C, anim, (void *)p->f38);
    func_0201F250((struct WordSet *)p->f24, (void *)p->f40, (void *)p->f38);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f44)), 0);
    v = p->f28;
    func_0201C724((void *)v, (int)func_02045770((struct Descriptor *)p->f44), 0, 0, p->f40, p->f1C, 0x3C40);
    p->f48 = 1;
}







void func_0217E714(void *w_v, u8 *p, u16 q)
{    W *w = (W *)w_v;
    u32 sys;
    void *h;
    int done;
    int cur;
    int prev;
    int i;
    int n;
    int msg;
    int off;
    void *t;
    Mon_0217E524 *m1;
    Mon_0217E524 *m2;
    Mon_0217E524 *e;
    Buf b;
    Vec3 v;

    sys = func_02012138((const struct Ctx *)w->f00);
    h = func_020120F4((const struct Ctx *)w->f00);
    done = 0;
    if (w->f108 > 0) {
        w->f108--;
        if (w->f108 == 0 && p == 0) {
            func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)w->f4C), done);
            func_02045334((struct Descriptor *)w->f4C);
        }
        return;
    }
    prev = w->f10D;
    w->f10D = 0;
    cur = func_02012B58(h);
    if (p != 0 && func_0203D1B4() <= 1) {
        off = 0x93A;
        n = p[off - 0x15];
        if (n != 0) {
            if (n == 1) {
                msg = 0x29;
            } else {
                msg = 0x2A;
            }
            for (i = 0; i < p[off - 0x15]; i++) {
                func_0201EE0C((struct WordSet *)w->f24, i, *(void **)(p + i * 4 + off - 0x12),
                              p[i + off - 2], 1, p[i + off]);
            }
            func_02045CAC((struct MsgBank *)w->f2C, msg, w->f38);
            func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
        } else {
            func_02045CAC((struct MsgBank *)w->f2C, 0x33, w->f3C);
        }
        done = 1;
    }
    if (done == 0 && p != 0 && func_0203D1B4() > 1 && func_021585BC((int)p) != 0) {
        func_02045CAC((struct MsgBank *)w->f2C, 0x35, w->f3C);
        done = 1;
    }
    if (done == 0 && func_02012B70(h) == 0) {
        e = w->slots[cur].mon;
        if (e != 0) {
            for (i = 0; i < 3; i++) {
                if (cur != i && w->slots[i].mon != 0
                    && e->x == w->slots[i].mon->x && e->y == w->slots[i].mon->y) {
                    func_02045CAC((struct MsgBank *)w->f2C, 0x31, w->f3C);
                    done = 1;
                    break;
                }
            }
        }
        if (done == 0 && w->fE9 == 1) {
            func_02045CAC((struct MsgBank *)w->f2C, 0x34, w->f3C);
            done = 1;
        }
        if (done == 0 && w->fEA == 1) {
            func_02045CAC((struct MsgBank *)w->f2C, 0x32, w->f3C);
            done = 1;
        }
    }
    if (done == 0 && p != 0 && w->f169 != 4 && func_021583EC(h, w->f169) != 0) {
        t = (void *)func_021583EC(h, w->f169);
        if (((Fld *)(p + w->f169 * 0x1C + 0xA2))->b == 2) {
            msg = 0x36;
        } else {
            msg = 0x28;
        }
        func_02045CAC((struct MsgBank *)w->f2C, msg, w->f38);
        func_0201F02C((struct WordSet *)w->f24, 0, t);
        func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
        w->f169 = 4;
        done = 1;
    } else if (w->fDC != 0 && w->fE4 != 0 && (w->fDC == 3 || prev != w->fDC)) {
        if (w->fDC == 3 && p != 0 && w->fE4->a != 4) {
            u32 *ep;
            Mon_0217E524 *mm;
            t = func_0201210C((const struct Ctx *)w->f00);
            ep = (u32 *)(p + 0x8C + w->fE4->f28 * 0x1C);
            func_021A3038(func_02188CB4(t), (struct VecFx32 *)(&v));
            func_021762C0(w->f24, 0, w->fE4->f18, 0x70);
            mm = func_0217BEA8(((u16 *)ep)[10]);
            if (w->fD8 == w->fE8 && mm != 0
                && func_0217EC08(q, mm->id, mm->id2) == 1) {
                if (ep[0] == 1) {
                    func_02045CAC((struct MsgBank *)w->f2C, 0x2F, w->f38);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                } else {
                    int dx = ep[1] - v.x;
                    int dy = ep[3] - v.z;
                    int ady = dy < 0 ? -dy : dy;
                    int adx = dx < 0 ? -dx : dx;
                    if (adx > ady) {
                        msg = 0x2D;
                        if (dx <= 0) {
                            msg = 0x2E;
                        }
                    } else {
                        msg = 0x2C;
                        if (dy <= 0) {
                            msg = 0x2B;
                        }
                    }
                    func_02045CAC((struct MsgBank *)w->f2C, msg, w->f38);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                }
            } else {
                m1 = func_0217BEA8(((u16 *)ep)[10]);
                m2 = func_0217BEA8(q);
                if (m1 != 0 && m2 != 0 && m1->x == m2->x && m1->y == m2->y) {
                    func_02045CAC((struct MsgBank *)w->f2C, 0x2F, w->f38);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                    done = 1;
                }
            }
        }
        if (done == 0 && func_02012B70(h) == 1) {
            w->f10D = 0;
            switch (w->fDC) {
            case 1:
                func_02045CAC((struct MsgBank *)w->f2C, 0x21, w->f3C);
                break;
            case 2:
                func_02045CAC((struct MsgBank *)w->f2C, 0x22, w->f3C);
                break;
            case 3:
                if (w->f10E == 0) {
                    func_02045CAC((struct MsgBank *)w->f2C, w->fE4->a + 0x37, w->f3C);
                } else {
                    func_02045CAC(w->f30, w->fE4->c, w->f38);
                    func_021762D8(w->fE4, w->fE4->f18, w->f24, (void *)0x70);
                    func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
                }
                w->f10E ^= 1;
                break;
            case 0:
            case 4:
                return;
            default:
                return;
            }
            if (w->fDC != 3) {
                w->f10E = 0;
            }
            w->f10D = w->fDC;
            done = 1;
        }
    } else {
        if (func_02026608((u8 *)sys, (u8 *)(&b)) == 1) {
            w->f10D = 0;
            func_02045CAC((struct MsgBank *)w->f2C, b.msg, w->f38);
            done = 1;
            for (i = 0; i < 2; i++) {
                if (b.ptr[i] != 0) {
                    func_0201EE0C((struct WordSet *)w->f24, b.slot[i], (void *)b.ptr[i], b.par[i], 1, 2);
                }
            }
            func_0201F250((struct WordSet *)w->f24, w->f3C, w->f38);
            done = 1;
        }
    }
    if (done == 0 && func_02012B70(h) == 1 && func_02013D5C(q) == 0 && func_02013D9C(q) == 0
        && func_021D3554(h, q) == 0) {
        func_02045CAC((struct MsgBank *)w->f2C, 0x30, w->f3C);
        done = 1;
    }
    w->f169 = 4;
    if (done == 1) {
        func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)w->f4C), 0);
        n = w->f28;
        func_0201C724((void *)n, (int)func_02045770((struct Descriptor *)w->f4C), 0, 0, (u32)w->f3C, w->f1C, 0x3C40);
        w->f50 = 1;
        w->f108 = 0x5A;
    }
}






/*
 * extent: two zero padding bytes at 0x0217EC06.
 * interface: func_020127B8 tail-forwards func_020127AC's pointer result.
 */
void *func_0217EBD8(u8 *p)
{
    void *h;
    int i;
    h = func_020120F4(((struct Obj12491 *)p)->f0);
    i = p[0xd8];
    if (i == func_02012B58(h) || i == 0x80) {
        return func_020127B8(h);
    } else {
        return func_020127AC(h, i);
    }
}






/*
 * lever: integer t initialized to 0x126 and incremented conditionally retains
 * the u16 assignment's shift pair; assigning either u16 constant removes it.
 */
int func_0217EC08(u16 a, u16 b, u16 c)
{
    int t;
    if (a == b || a == c) return 1;
    if ((u16)(a + 0xfeda) <= 1) {
        t = 0x126;
        if (a == t) t++;
        a = t;
        if (a == b || a == c) return 1;
    }
    return 0;
}






void func_0217EC44(int x, int y, int w, int h, Rect_0217E2E0 *r)
{
    r->t = y - h;
    r->b = y + h;
    r->l = x - w;
    r->r = x + w;
}






int func_0217EC5C(int x, int y, const Rect_0217E2E0 *r)
{
    if (r->l < x && r->r > x && r->t < y && r->b > y) return 1;
    return 0;
}












/*
 *           witness: 0x02013DD0 is an unlabelled arm9 leaf inside
 *           func_02013D9C's listing extent, called only from here. Verified
 *           EXACT (match.py one --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int func_02013B10(int a0, const int *a1, int a2);
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 *           Once that leaf is filed and in a shard, this file verifies EXACT.
 */
void func_0217EC7C(void *q_v, void *p_v, int id)
{    Obj_0217EC7C *p = (Obj_0217EC7C *)p_v;    Q *q = (Q *)q_v;
    Rect_0217E2E0 rect;
    u32 tx;
    u32 ty;
    s16_0217E2E0 pt[2];
    int x;
    int sel;
    int h;
    int i;
    int w;
    int a;
    const Ent *e;
    Mon_0217E524 *m;

    x = func_02188CCC(func_0201210C((const struct Ctx *)p->f00));
    func_02012138((const struct Ctx *)p->f00);
    h = (int)func_020120F4((const struct Ctx *)p->f00);
    if (p->f112 != 0 || p->f106 == 1 || !func_02035D20(&tx, &ty) || func_021A0F94(x) != 0) {
        return;
    }
    sel = func_02012B58((const struct BigObj *)h);
    for (i = 0; i < 3; i++) {
        if (i == sel) {
            continue;
        }
        if (!(p->fD9 & (1 << i))) {
            continue;
        }
        w = p->f8C[i];
        if (func_0204B3F4((struct Obj_0217EC7C *)w) != 1) {
            continue;
        }
        func_0204B454((struct Actor *)w, (struct PtS *)pt, 0);
        if (tx - 12 > pt[0] || tx + 12 < pt[0]) {
            continue;
        }
        if (ty - 12 > pt[1] || ty + 12 < pt[1]) {
            continue;
        }
        if (q == 0) {
            continue;
        }
        if (func_0217BEA8(q->e[i].id) == 0) {
            continue;
        }
        p->f169 = i;
        return;
    }
    if (func_0217F284((u8 *)p) == 1) {
        return;
    }
    if (p->fD8 != func_02012B58((const struct BigObj *)h)) {
        for (i = 0; i < 8; i++) {
            e = &d_02176AA0[i];
            func_0217EC44(e->x, e->y, 0x10, 0x10, &rect);
            if (func_0217EC5C(tx, ty, &rect) != 1) {
                continue;
            }
            a = e->a;
            if (id == a || id == e->b || (func_02013DD0(id) == 1 && func_02013DD0(a) == 1)) {
                func_020061E4(0x557);
                return;
            }
            if (i == 7) {
                p->f106 = 1;
                p->f107 = 0;
            } else {
                m = func_0217BEA8(a);
                if (m == 0) {
                    continue;
                }
                p->f110 = m->id3;
                p->f112 = 1;
            }
            p->f113 = i;
            return;
        }
    }
    if (p->fD8 != func_02012B58((const struct BigObj *)h)) {
        func_0217EC44(0x80, 0x5C, 0x10, 0x10, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            if (func_02013D5C(id) == 1) {
                func_020061E4(0x557);
                return;
            }
            p->f110 = 0x117;
            p->f112 = 1;
            p->f113 = 8;
            return;
        }
    }
    if (p->f168 == 0 && func_020257C4((const int *)p->fC4) == 1) {
        func_0217EC44(0xE0, 0x80, 0x1E, 0xC, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            p->f168 = 1;
        }
    }
}












void func_0217EEB4(int *p)
{
    int n;

    n = 0;
    if (*((u8 *)p + 0x11f) == 0) {
        if (*((u8 *)p + 0xda) > 1) {
            func_0204989C(0x24, 7, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 1;
            n++;
        }
    } else {
        if (*((u8 *)p + 0xda) <= 1) {
            func_0204989C(0x24, 6, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 0;
            n++;
        }
    }
    if (n != 0) {
        func_02045374((struct Cfg *)p[0x44 / 4]);
        func_02045374((struct Cfg *)p[0x4c / 4]);
        func_02041B6C(6);
        if (func_0217F1E8((u8 *)p) == 1) {
            func_0217F240((u8 *)p, 1);
        }
    }
}











/*
 * interface: r1 holds p[0xd8] at 0x0217EF64 and EF70 reads it.
 */
void func_0217EF44(void *p_v, void *z2)
{    u8 *p = (u8 *)p_v;
    func_020120F4(((struct Obj03092 *)p)->f0);
    func_02012138(((struct Obj03092 *)p)->f0);
    if (p[0xd8] != p[0x105]) func_0217EF70((int *)p, p[0xd8]);
}












void func_0217EF70(int *p, int x)
{
    func_020413B0(7, 0, 2, 0x20, 0x10, (u8)(x + 5));
    func_020413B0(6, 0, 2, 0x20, 0x10, (u8)(x + 1));
    if (p[0x44 / 4] != 0) {
        func_02045374((struct Cfg *)p[0x44 / 4]);
        func_02045374((struct Cfg *)p[0x4c / 4]);
    }
    func_02041B6C(7);
    func_02041B6C(6);
    *((u8 *)p + 0x105) = x;
}











/*
 * extent: two zero padding bytes at 0x0217F006.
 * lever: assign the shifted mask before the flag; its flag store schedules
 * ahead of the shift while retaining separate constant-one registers.
 */
void func_0217EFCC(char *p, char *q)
{
    State *s;
    void *h;
    s = (State *)(p + 0xd8);
    h = func_020120F4(((struct Obj00399 *)p)->f0);
    if (q == 0) {
        s->a = func_02012B58(h);
        s->b = 1 << s->a;
        s->c = 1;
        s->d = 0;
        s->e = 0;
        s->f = 0;
    } else {
        func_0217F008(p, q);
    }
}












void func_0217F008(char *p, char *q)
{
    O *o;
    int h;
    int n;
    int i;

    o = (O *)(p + 0xd8);
    h = (int)func_020120F4((const struct Ctx *)(*(int *)&((struct Obj00399 *)p)->f0));
    if (q == 0) {
        func_02082BCC(p + 0xd8, 0, 0x14);
        *(p + 0x11e) = 1;
        return;
    }
    n = func_02012B58((const struct BigObj *)h);
    o->a = ((Bf_0217EC7C *)(q + 0x86))->lo;
    o->b = ((struct Obj12492 *)q)->f8FB;
    o->c = func_02080D24(o->b);
    o->d = ((struct Obj12492 *)q)->f910;
    o->e = func_0217F5A0((Ov018Obj_0217F5A0 *)(q + 0x1ac));
    o->f = func_021758C8((u8 *)(q + 0x1ac));
    o->g = (T *)func_02175B34((u8 *)(q + 0x1ac));
    if (o->g != 0) {
        o->h = ((Bf_0217EC7C *)(q + o->g->idx * 0x1c + 0xa2))->lo;
    }
    o->i = func_0217C070((u8 *)q);
    o->j = 0;
    for (i = 0; i < 3; i++) {
        if (i != n && o->a == ((Bf_0217EC7C *)(q + i * 0x1c + 0xa2))->lo) {
            o->j = 1;
            return;
        }
    }
}











void func_0217F0C4(u8 *p)
{
    int i;
    p[0x115] = 0;
    p[0x114] = 1;
    for (i = 0; i < 7; i++) func_0204B6F4(((void **)p)[23 + i], 6, 1);
    func_0204B6F4(((void **)p)[31], 6, 1);
}











int func_0217F0FC(u8 *p)
{
    if (p[0x114] == 1 && p[0x115] < 10) return 1;
    return 0;
}












void func_0217F118(void *p_v, int n)
{    Ov018Sel *p = (Ov018Sel *)p_v;
    u8 c;

    c = p->f11B;
    if (c != n && p->f114 != 1) {
        if (c < 8) {
            func_0204B6F4(p->tbl[c], 6, 1);
        } else if (c == 8) {
            func_0204B6F4(p->tbl[8], 6, 1);
        }
        if (n < 8) {
            func_0204B6F4(p->tbl[n], 8, 1);
        } else if (n == 8) {
            func_0204B6F4(p->tbl[8], 8, 1);
        }
        p->f11B = n;
        p->f118 = 0;
        p->f11A = 0;
    }
}











void func_0217F174(u8 *p)
{
    p[0x117] = 0;
    p[0x116] = 1;
    func_0204B6F4(((struct Obj09396 *)p)->f9C, 6, 1);
}












void func_0217F194(void *p_v)
{    Ov018Blink *p = (Ov018Blink *)p_v;
    int t;

    if (p->f116 != 0) {
        t = p->f117;
        if (t % 2 == 0) {
            func_0204B6F4(p->f9C, (u8)(((unsigned)t >> 1) & 1 ? 6 : 7), (int)1);
        }
        if (p->f117 < 10) {
            p->f117++;
        }
    }
}











/*
 * extent: Two bytes of alignment padding at 0x0217F212.
 */
int func_0217F1E8(u8 *p)
{
    if (func_02012B70(func_020120F4(((struct Obj00092 *)p)->f0)) == 1) {
        switch (((struct Obj00092 *)p)->fDC) {
        case 2: case 3: case 4: return 1;
        }
    }
    return 0;
}











void func_0217F214(void)
{
    func_02041300(6, 0x3001, 0x14, 0x16, 0xc, 2, 0x11);
    func_02041B6C(6);
}












void func_0217F240(u8 *p, int mode)
{
    func_020410D0(6, 0x14, 0x16, 0xC, 2, (u32)(p + 0x138), 0, 0, 0xC, 2);
    if (mode == 1) {
        func_02041B6C(6);
    } else {
        func_020409B4(6);
    }
}











/*
 * extent: Two bytes of alignment padding at 0x0217F2B2.
 */
int func_0217F284(u8 *p)
{
    void *q = func_020120F4(((struct Obj12494 *)p)->f0);
    if (((struct Obj12494 *)p)->fE4 == 0 && func_02012B58(q) == 0 && func_02158590(q) == 0) return 1;
    return 0;
}












void func_0217F2B4(void *p_v, void *a)
{    Ov018Obj_0217EC7C *p = (Ov018Obj_0217EC7C *)p_v;
    void *r;

    r = (void *)func_02188C54(func_0201210C(a));
    if (p->f00 == 0) {
        p->f00 = func_0201EC74(6, 0x20, 4);
        p->f04 = func_020457B0(0x1F0, 4);
        p->f08 = func_020457B0(0x1D0, 4);
        p->f0C = (void *)func_021904B0((u32)r, 0x44);
        p->f10 = (void *)func_021904B0((u32)r, 0x42);
        p->f14 = (void *)func_021904B0((u32)r, 0x43);
        p->f24 = r;
        p->f28 = 0;
    }
}











void func_0217F318(void *p_v)
{    Ov018Obj *p = (Ov018Obj *)p_v;
    func_0217F390(p);
    func_0217F58C((Ov018Obj *)p);
    func_0217F45C((Ov018Obj *)p);
    if (p->f00 != 0) {
        if (p->f18 != 0) {
            func_02190E40((u32)p->f18);
            p->f18 = 0;
        }
        func_021904C8(p->f0C);
        func_021904C8(p->f10);
        func_021904C8(p->f14);
        func_02045808(p->f08);
        func_02045808(p->f04);
        func_0201ED04(p->f00);
        p->f00 = 0;
    }
}











void func_0217F36C(Ov018Obj *p)
{
    if (p->f18 != 0) {
        if (p->f28 == 1) {
            func_0217F3E4((Ov018Obj *)p);
        }
    } else {
        p->f18 = func_02190F64(p->f24, (u32)p->f0C);
    }
}











void func_0217F390(Ov018Obj *p)
{
    if (p->f18 != 0) {
        func_02190E40((u32)p->f18);
        p->f18 = 0;
    }
}











void func_0217F3A4(Ov018Obj *p, void *a)
{
    func_0217F36C(p);
    func_02190EB8(p->f18, 0, 0, (u32)a);
    p->f28 = 1;
}











void func_0217F3C4(void *p_v, u16 a)
{    Ov018Obj *p = (Ov018Obj *)p_v;
    func_02045CAC(p->f0C, a, p->f08);
    func_0201F250(p->f00, p->f04, p->f08);
    func_0217F3A4(p, p->f04);
}











void func_0217F3E4(Ov018Obj *p)
{
    if (p->f18 == 0) {
        func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    }
    func_02190F7C(p->f18);
    p->f28 = 0;
}











int func_0217F40C(void *p_v)
{    Ov018Obj *p = (Ov018Obj *)p_v;
    if (p->f18 == 0) {
        return 1;
    }
    return func_02190EF0(p->f18);
}










int func_0217F420(void)
{
    if (func_020362DC() & 0xf3) return 1;
    return 0;
}










/*
 * extent: Two bytes of alignment padding at 0x0217F45A.
 */
void func_0217F434(void **p)
{
    if (p[7] == 0) p[7] = func_02190708(p[9], (u32)p[3], 1, 0x13, 0x1e, 4);
}











void func_0217F45C(Ov018Obj *p)
{
    if (p->f1C != 0) {
        func_02190728((void *)p->f1C);
        p->f1C = 0;
    }
}










void func_0217F470(void **p, void *bank, void *handle, unsigned int index, int a, int b)
{
    func_02045CAC(bank, index, p[2]);
    func_0201F250(p[0], p[1], p[2]);
    func_02190758((u32)handle, (u16)a, (u16)b, (u32)p[1]);
}










void func_0217F4A0(void **p, unsigned int index, int a, int b)
{
    func_0217F434(p);
    func_0217F470(p, p[3], p[7], index, a, b);
}











void func_0217F4C4(void *p_v)
{    Ov018Obj *p = (Ov018Obj *)p_v;
    if (p->f2C != 0) {
        func_021909BC((void *)p->f2C);
        p->f2C = 0;
    }
}










void func_0217F4D8(void **p, int a)
{
    func_0201210C((const struct Ctx *)a);
    if (p[11] != 0 || p[3] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    p[11] = func_02190BE4(p[9], 0);
}










int func_0217F508(void **p)
{
    if (p[11] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    return func_02190C78(p[11]);
}











void func_0217F528(Ov018Obj_0217F528 *p, int a, int b, int c, int d, int e)
{
    func_0201210C((void *)a);
    if (p->f20 != 0) {
        func_02034714((const char *)d_02183B2C, (int)0, (const char *)d_02183B2C);
    }
    p->f20 = func_02190708(p->f24, (u32)p->f0C, (u16)b, (u16)c, d, e);
}










void func_0217F574(void **p, unsigned int index, int a, int b)
{
    func_0217F470(p, p[5], p[8], index, a, b);
}











void func_0217F58C(Ov018Obj *p)
{
    if (p->f20 != 0) {
        func_02190728((void *)p->f20);
        p->f20 = 0;
    }
}











int func_0217F5A0(Ov018Obj_0217F5A0 *p)
{
    Rec_0217EC7C *r;

    if (func_02175DA8((u8 *)p) == 1) {
        return 4;
    }
    r = (Rec_0217EC7C *)func_02175B34((u8 *)p);
    if (r == 0) {
        return 0;
    }
    if (r->f30 == 0) {
        if (p->bit1A5 == 1) {
            return 3;
        }
        return 1;
    }
    if (p->bit1A5 == 1) {
        return 2;
    }
    return 1;
}











/*
 * lever: a switch with empty sentinel and default arms retains the dead
 * comparison before the shared bitfield return.
 */
int func_0217F5F0(void *p_v, u8 idx)
{    Ov018Obj_0217F5F0 *p = (Ov018Obj_0217F5F0 *)p_v;
    Ent_0217F3E4 *e;
    enum Guard { ZERO, INVALID = 0xFFFF } h;

    void *sub;

    sub = (void *)func_02026478(p->f04);
    if (idx == func_02012B58(sub)) {
        e = &p->cur;
    } else {
        e = &p->arr[idx];
    }
    h = e->f18;
    switch (h) {
    case 0:
        if (func_02008550((const struct Sub0200852CObj *)func_02012950((struct Sub24 *)func_02026478(p->f04), idx)) == 0) {
            return 3;
        }
        return 4;
    case 0xFFFF:
        break;
    default:
        break;
    }
    return e->f1A;
}










/*
 * extent: Two bytes of alignment padding at 0x0217F67A.
 */
int func_0217F648(void *a, void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *sys = func_0215A5DC(vm);
    func_0215897C(owner, func_0217F67C(sys, func_02159AE8(a, vm)));
    return 1;
}










void *func_0217F67C(void *owner, u16 *out)
{
    void *task;
    u8 *work;
    int zero;
    zero = 0;
    task = func_020122C0(owner, 0, func_0217F6A0, 0x10);
    work = func_020124E8(task);
    *(u16 * *)&((struct Obj19364 *)work)->fC = out;
    *out = zero;
    return task;
}











int func_0217F6A0(void *a0, int *state, Ctx *c)
{
    void *h;
    void *s;
    u32 k;
    u8 *w;
    void *t;
    int flag;

    h = func_020124E4(a0);
    s = func_020120F4(h);
    k = func_02012138(h);
    t = func_0201210C(h);
    flag = 0;
    w = (u8 *)func_02158344(k);
    if (w == 0 && *state > 0 && *state < 5) {
        *state = 5;
    }
    switch (*state) {
    case 0: {
        void *g;
        int a;
        int b;

        if (func_0200FB24() != 0 || (w == 0 && func_02012B80(s) != func_02012B58(s))) {
            *state = 7;
            break;
        }
        if (w != 0) {
            func_021757A8(w + 0x1AC);
            func_0217BF1C(w + 0x914);
        }
        g = (void *)func_02188C54(t);
        c->f0 = func_021904B0((int)g, 0x2D);
        c->f4 = func_021907A8(g, c->f0);
        c->f8 = (int)func_0201EC64(4);
        func_020061E4(0x547);
        if (w == 0 || func_0215841C(s) == func_02012B58(s)) {
            func_02190740(c->f4, 0, 0, 0x49);
            flag = 1;
        } else {
            a = (int)func_020457B0(0x100, 0x15);
            b = (int)func_02045EC0((struct MsgBank *)c->f0, 0x4A);
            func_0201F02C((struct WordSet *)c->f8, 0, (void *)func_021583EC(s, func_0215841C(s)));
            func_0201F250((struct WordSet *)c->f8, (void *)a, (void *)b);
            func_02190758(c->f4, 0, 0, a);
            func_02045808((struct U16Vec *)b);
            func_02045808((struct U16Vec *)a);
        }
        if (func_0203D1B4() <= 1) {
            if (flag == 0) {
                *c->fC = 0;
            } else {
                *c->fC = 1;
            }
            *state = 5;
            break;
        }
        (*state)++;
    }
    case 1:
        if (func_02173D2C((int)w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (func_02175FB4(w + 0x1AC + func_0215841C(s) * 0x28) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (func_02173C6C((int)w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_0217BF28(w + 0x914) == 1) {
            *c->fC = 1;
            *state = 5;
        }
        break;
    case 5:
        if (func_0219077C((u8 *)c->f4) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            func_0201ED04((struct WordSet *)c->f8);
            func_02190728((void *)c->f4);
            func_02045C04((struct Rec_0217EC7C *)c->f0);
            (*state)++;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}










/*
 * extent: two bytes of zero alignment padding follow at 0x0217F8CE.
 * lever: stores in both arms keep the branch to the shared store.
 */
int func_0217F8A0(void *a, void *vm)
{
    u16 *out;
    u8 *p;
    int v;
    out = func_02159AE8(a, vm);
    p = (u8 *)func_02158344((int)((void *)func_02012138(func_0215A5DC(vm))));
    if (p == 0 || ((struct Obj12499 *)p)->f88 == 0) {
        *out = 0;
    } else {
        *out = ((struct Obj12499 *)p)->f88;
    }
    return 0;
}











int func_0217F8D0(void *a0, int a)
{
    u16 *out;
    Sys *s;
    int v;

    out = func_02159AE8(a0, (void *)a);
    s = (Sys *)func_02158344(func_02012138(func_0215A5DC((void *)a)));
    if (s != 0 && s->bit93F == 0 && func_02175B8C((u8 *)s + 0x1AC) == 1) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}










int func_0217F914(void *unused, void *vm)
{
    void *owner;
    owner = func_0215A5F4(vm);
    func_0215897C(owner, func_0217F938(func_0215A5DC(vm)));
    return 1;
}









void *func_0217F938(void *owner)
{
    void *task;
    task = func_020122C0(owner, 0, func_0217F95C, 0x30);
    func_02082BCC(func_020124E8(task), 0, 0x30);
    return task;
}










int func_0217F95C(void *a0, int *state, void *a2)
{
    void *h;
    u8 *w;
    struct Desc *r;

    h = func_020124E4(a0);
    w = (u8 *)func_02158344(func_02012138(h));
    if (w == 0 && *state < 3) {
        *state = 3;
    }
    switch (*state) {
    case 0:
        w[0x93F] |= 8;
        func_0217F2B4((Ov018Obj_0217EC7C *)a2, h);
        if (func_0217F5A0((Ov018Obj_0217F5A0 *)(w + 0x1AC)) == 3) {
            *state = 2;
        } else {
            func_0217F4A0(a2, 0x1A, 0, 0);
            (*state)++;
        }
        break;
    case 1:
        switch (func_0217F5A0((Ov018Obj_0217F5A0 *)(w + 0x1AC))) {
        case 2:
            break;
        case 3:
        default:
            (*state)++;
            break;
        }
        break;
    case 2:
        r = func_0217C458(h, func_0201210C(h), w, 0x15);
        func_0217FA1C(a2);
        func_0201235C(a0, (u32 *)r);
        return 0;
    case 3:
        func_0217FA1C(a2);
        return 1;
    }
    return 0;
}










void func_0217FA1C(void *p)
{
    func_0217F318((Ov018Obj *)p);
}









void *func_0217FA24(void *owner)
{
    return func_020122C0(owner, 0, func_0217FA38, 0);
}










int func_0217FA38(void *a, int *state)
{
    void *s;
    u32 h;
    void *p2;
    void *p3;
    u8 *w;
    void *r;

    s = func_020124E4(a);
    h = func_02012138(s);
    p2 = func_020120F4(s);
    p3 = func_0201210C(s);
    w = (u8 *)func_02158344(h);
    switch (*state) {
    case 0:
        if (w == 0) {
            func_02012B58(p2);
        } else {
            func_02176230(w, w + 0x1AC);
        }
        r = func_0217CE08(s, p3, 0x117, 1);
        if (r == 0) {
            return 1;
        }
        func_02012374(a, r);
        (*state)++;
        break;
    case 1:
        if (func_02013D5C(func_02012AC8((const struct Rec44 *)func_020120F8(s))) == 1) {
            func_02012374(a, func_0217F938(s));
        }
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}










/*
 * What closed it: the store through `out` is written in each arm of the
 * if/else (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md)
 * rather than once after it through a shared `v`; the single store made
 * `v` live across the join and coloured out/q/temp as r6/r4/r5 instead of
 * r5/r6/r4 (docs/notes/pkt_ov018_0217FAE0.c.txt has the earlier miss).
 */
int func_0217FAE0(void *unused, int a)
{
    u16 *out;
    void *t;
    void *q;
    int v;

    out = func_02159AE8(unused, (void *)a);
    t = func_0215A5DC((void *)a);
    func_02012138(t);
    q = func_020120F4(t);
    if (func_0215841C(q) == func_02012B58(q)) {
        *out = 0;
    } else {
        v = func_0215841C(q) - func_02012B58(q);
        if (v < 0) {
            v += 3;
        }
        *out = v;
    }
    return 0;
}









int func_0217FB2C(void *a, void *vm)
{
    u16 *out;
    int v;
    out = func_02159AE8(a, vm);
    if (func_0200BF10((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4(func_0215A5DC(vm))))) != 0x30) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}









void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f)
{
    Req *work;
    void *task;
    task = func_020122C0(owner, 0, func_0217FB94, 0x10);
    work = func_020124E8(task);
    func_02082BCC(work, 0, 0x10);
    work->f0 = b;
    work->f4 = d;
    work->f8 = e;
    work->fC = f;
    return task;
}










int func_0217FB94(int a, int *state, Req *req)
{
    int s;
    u8 *w;

    s = (int)func_020124E4((struct Obj_0217EC7C *)a);
    w = (u8 *)func_02158344(func_02012138((const struct Ctx *)s));
    switch (*state) {
    case 0:
        if (w == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((u8 *)req->f0));
        func_02012374((struct Evt *)a, func_0217FC08(s, req->f0, w, req->f4, req->f8, req->fC));
        (*state)++;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((u8 *)req->f0));
        return 1;
    }
    return 0;
}










void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_0217FE6C, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (u8 *)((int *)c), q, b, d, e, f);
    func_0217538C(c, e);
    func_02175368((char *)c);
    q[0x41] = func_021803F0(q, c);
    return r;
}










void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e)
{
    void *r = func_020122C0(p, 0, func_0217FCAC, 0x10);
    int *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x10);
    q[0] = a;
    q[1] = c;
    q[2] = d;
    ((struct Obj07367 *)q)->fC = e;
    func_0217545C((u8 *)b);
    return r;
}










int func_0217FCAC(int x, int *st, int *obj)
{
    int v = (int)func_020124E4((struct Obj_0217EC7C *)x);
    int *m;

    m = (int *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        if (m == 0) {
            return 1;
        }
        if (func_02167A54((int *)m[2], obj[2]) == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((unsigned char *)obj[0]));
        func_02012374((struct Evt *)x, func_0217FD34(v, obj[0], (u8 *)m, obj[1], obj[2], ((struct Obj04178 *)obj)->fC));
        *st = *st + 1;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((unsigned char *)obj[0]));
        return 1;
    }
    return 0;
}










void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_021800A4, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (u8 *)((int *)c), q, b, d, e, f);
    q[0x41] = c[0x11c];
    *(S52 *)(q + 0x44) = *(S52 *)(c + 0x120);
    return r;
}








void func_0217FDA0(int a, u8 *b, u8 *c, int d, int e, int f, u16 g)
{
    enum Local { LOCAL_ZERO } loc;

    ((struct Obj03562 *)c)->f0 = g;
    ((struct Obj03562 *)c)->f4 = e;
    loc = f;
    ((struct Obj03562 *)c)->f8 = func_02167A14((struct Work *)(((struct Obj00566 *)b)->f8), loc);
    ((struct Obj03562 *)c)->fC = d;
    c[0x40] = (u8)f;
    c[0x42] = func_0217F5F0((Ov018Obj_0217F5F0 *)b, (u8)f);
    func_02008494((void *)func_021583EC(func_020120F4((const struct Ctx *)a), loc), c + 0x78);
    if (func_02175B14(b + 0x1ac) == 1) {
        func_02082D44(func_02175B34(b + 0x1ac), c + 0x44, 0x34);
    }
    func_0217F2B4((Ov018Obj_0217EC7C *)(c + 0x10), (void *)a);
    func_02174E14(b, 1);
    func_02175368((char *)b);
    b[0x93f] = b[0x93f] & ~0x30;
}








void func_0217FE38(void *v, void *c_)
{
    Ov018Outer *c = (Ov018Outer *)c_;
    func_0217F4C4((Ov018Obj *)(&c->obj));
    func_0217F318((Ov018Obj *)(&c->obj));
    if (v != 0) {
        func_02174E14(v, 0);
        func_0217538C(v, 4);
        func_02175368(v);
    }
}






/*
 * Task callback in the shape of func_02182AA4: a 10-state sequence; state 0
 * copies the 0x98-byte work block into a temporary allocation (lines 493
 * and 517 of the file string at 0x02183B30) and hands it to one of the
 * follow-up task starters.
 */
int func_0217FE6C(void *a, int *state, Outer_0217EC7C *c)
{
    u8 *v;
    u8 *p;
    void *t;
    int kind;
    Bits *b;

    v = (u8 *)func_02158344((int)((void *)func_02012138(func_020124E4(a))));
    if (v == 0) {
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 0) {
            return 0;
        }
        if (*state <= 6) {
            func_0217F3C4((Ov018Obj *)(&c->obj), 4);
            *state = 8;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        kind = func_02175DCC(v + 0x1AC);
        b = (Bits *)(v + 0xA2 + c->f40 * 0x1C);
        if (b->f15 == 1) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 493);
            func_02082D44(c, t, 0x98);
            if (func_02175BCC(v + 0x1AC) == 0 && func_02175B14(v + 0x1AC) == 1
                && func_02175B8C(v + 0x1AC) == 1 && func_0217620C(v + 0x1AC, c->f40) == 1) {
                func_02182A08(a, t);
            } else {
                func_02182998(a, t);
            }
            func_020307B0(t);
        } else if (b->f9 != 0) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 517);
            func_02082D44(c, t, 0x98);
            if (((Bits *)(v + c->f40 * 0x1C + 0xA2))->f9 == 2) {
                if (kind == 5) {
                    func_02181BE8(a, t);
                } else {
                    func_02182988(a, t);
                }
            } else {
                func_02182998(a, t);
            }
            func_020307B0(t);
        } else {
            (*state)++;
        }
        break;
    case 1:
        if (func_02174258((char *)v) == 1) {
            (*state)++;
        }
        break;
    case 2:
        switch (func_02175C40(v + 0x1AC)) {
        case 1:
            c->f99 = 1;
            (*state)++;
            break;
        case 2:
            (*state)++;
            break;
        }
        break;
    case 3:
        switch (func_0217C914(v, (u8 *)c, &c->f98)) {
        case 1:
            func_0217553C(v);
            *state = 4;
            break;
        case 2:
            *state = 9;
            break;
        case 3:
            *state = 7;
            break;
        }
        break;
    case 4:
        if (func_02173C04(c->f40, c->f99) == 1) {
            (*state)++;
        }
        break;
    case 5:
        p = func_0217537C(v);
        if (p != 0) {
            if (p[1] != c->f99 || c->f99 == 1) {
                c->f41 = 0;
            }
            (*state)++;
        }
        break;
    case 6:
        func_021802A8((int)a, (u8 *)c, (int)v);
        return 0;
    case 7:
        *state = 9;
        break;
    case 8:
        if (func_0217F420() == 1) {
            *state = 9;
        }
        break;
    case 9:
        func_0217FE38(v, (Ov018Outer *)c);
        return 1;
    }
    return 0;
}







/*
 * Task callback in the shape of func_02182AA4: a 12-state sequence driving
 * the Ov018Obj at +0x10, with an early skip to state 10 while the owner
 * object is absent.
 */
int func_021800A4(void *a, int *state, Outer_021800A4 *c)
{
    void *sub;
    void *t;
    void *w;
    u8 *v;
    u8 *p;
    int k;
    int m;
    int flag;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    w = func_020120F4(sub);
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 10) {
            func_0217F3C4(&c->obj, 4);
            *state = 10;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0217553C(v);
        func_0216D9A0(func_02188C7C(c->f0C));
        func_0201F02C(c->obj.f00, 0, func_02012950(w, v[0x154]));
        func_0217F3C4(&c->obj, 1);
        (*state)++;
        break;
    case 1:
        if (func_0216D3CC((int)c->f04) == 1) {
            k = *(u16 *)(v + c->f40 * 0x1C + 0x9C);
            if (k == 2) {
                m = 3;
            } else if (k == 3) {
                m = 2;
            } else {
                m = 0;
                if (k != 1) {
                    m = 1;
                }
            }
            func_0216D410(c->f04, m);
            (*state)++;
        }
        break;
    case 2:
        if (func_0216D480(c->f04) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (func_02174258((char *)v) == 1) {
            (*state)++;
        }
        break;
    case 4:
        switch (func_02175C40(v + 0x1AC)) {
        case 1:
            c->f99 = 1;
            (*state)++;
            break;
        case 2:
            (*state)++;
            break;
        }
        break;
    case 5:
        if (func_02173AE0((int)v, v[0x154], v[0x156], v[0x158]) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_0217F40C(&c->obj) == 1) {
            k = func_02175514(v);
            flag = 0;
            switch (k) {
            case 0:
                break;
            case 1:
                *state = 7;
                break;
            case 2:
            case 3:
            default:
                flag = 1;
                break;
            }
            if (flag == 1) {
                func_0217F3C4(&c->obj, 4);
                *state = 10;
            }
        }
        break;
    case 7:
        if (func_02173C04(v[0x154], c->f99) == 1) {
            (*state)++;
        }
        break;
    case 8:
        p = func_0217537C(v);
        if (p != 0) {
            if (p[1] != c->f99 || c->f99 == 1) {
                c->f41 = 0;
            }
            *state = 9;
        }
        break;
    case 9:
        func_0218034C((int)a, (u8 *)c, (int)v);
        return 0;
    case 10:
        if (func_0217F420() == 1) {
            *state = 11;
        }
        break;
    case 11:
        if (func_0217F40C(&c->obj) == 1) {
            func_0216D9E4(func_02188C7C(c->f0C));
            func_0217FE38(v, (Ov018Outer *)c);
            return 1;
        }
        break;
    }
    return 0;
}






extern void (*d_0218374C[])(int, void *);







void func_021802A8(int x, u8 *y, int z)
{
    void *p = func_02030734((u16)((((struct Obj12502 *)y)->f0 & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x329);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        func_021808C4((void *)x, p);
    } else if (c == 1) {
        func_021829F8((void *)x, p);
    } else if (c == 2) {
        func_021808C4((void *)x, p);
    } else if (c >= 3) {
        if (d_0218374C[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_0218374C[y[0x41] - 8](x, p);
    } else {
        func_021808C4((void *)x, p);
    }
    func_020307B0(p);
}

















extern void (*d_021837C4[])(int, void *);


















void func_0218034C(int x, u8 *y, int z)
{
    void *p = func_02030734((u16)((((struct Obj12503 *)y)->f0 & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x354);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        func_02180978(x, p);
    } else if (c == 1) {
        func_021829F8((void *)x, p);
    } else if (c == 2) {
        func_02180978(x, p);
    } else if (c >= 3) {
        if (d_021837C4[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_021837C4[y[0x41] - 8](x, p);
    } else {
        func_02180978(x, p);
    }
    func_020307B0(p);
}


















static inline int state(u8 *a, u8 *b, u8 cur)
{
    if (func_02175BCC(b + 0x1AC) == 0 && func_02175B14(b + 0x1AC) == 1) {
        if (func_02175B8C(b + 0x1AC) == 1) {
            if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
                return 3;
            if (((Bf_021800A4 *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 4;
            return 5;
        }
        if (func_0217620C(b + 0x1AC, cur) == 1) {
            if (((Bf_021800A4 *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 6;
            return 7;
        }
        if (((Bf_021800A4 *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
            return 1;
        if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
            return 2;
        return 0;
    }
    return 0;
}


















int func_021803F0(u8 *a, u8 *b)
{
    u8 cur;
    int kind;
    int r;

    cur = (int)func_02012B58((const struct BigObj *)((int)func_020120F4(func_02188C80(((struct Obj19375 *)a)->fC))));
    kind = func_02175DCC(b + 0x1AC);
    r = state(a, b, cur);
    if (r >= 3) {
        switch (kind) {
        case 0: r += 8; break;
        case 1: r += 13; break;
        case 2: r += 18; break;
        case 3: r += 23; break;
        case 4: r += 28; break;
        case 5: r += 33; break;
        }
        r -= 3;
    }
    return r;
}


















void *func_021804F8(void *p, int a)
{
    void *v = func_0201210C(p);
    void *r = func_020122C0(p, 0, func_02180538, 0x138);
    u16 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x138);
    *q = func_02188C84(v);
    ((struct Obj12504 *)q)->f34 = a;
    return r;
}


















/*
 * Task callback: a 13-state sequence driving the Ov018Obj at +0x04. State 0
 * waits for the link partner and snapshots its 0x3C-byte record into +0xEC.
 */
int func_02180538(void *a, int *state, Outer_Sub_a *c)
{
    void *sub;
    void *t;
    void *w;
    u8 *v;
    Rec3C *e;
    void *h;
    void *m;
    u32 x;
    u32 n;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    w = func_020120F4(sub);
    func_0201210C(sub);
    switch (*state) {
    case 0:
        v = 0;
        if (func_02026454(t) == 2) {
            v = (u8 *)func_02026474(t);
        }
        if (c->f34 == 0) {
            if (v != 0 && func_0200FB24() == 0 && func_02175E90(v, v + 0x1AC) == 1) {
                ((B1 *)(v + 0x904))->f0 = 1;
            }
            return 1;
        }
        if (v != 0 && func_02175DA8(v + 0x1AC) == 1 && func_021756A4((char *)v) == 1) {
            if (func_02175E90(v, v + 0x1AC) == 0) {
                return 1;
            }
            c->f134 = v[0x358];
            c->f135 = v[0x359];
            func_0217F2B4((Ov018Obj_0217EC7C *)&c->obj, sub);
            e = (Rec3C *)func_02175BCC(v + 0x1AC);
            h = func_020127B8(w);
            if (e == 0) {
                func_02034714(str_02183B48, 0, str_02183B48);
            }
            c->fEC = *e;
            c->f128 = e->lo;
            c->f12A = e->f18;
            c->f12C = func_02175E90(v, v + 0x1AC);
            c->f130 = func_02175DE4(v, v + 0x1AC);
            func_0200BE24(h, c->f135);
            func_0200BE00(h, c->f134);
            (*state)++;
            break;
        }
        if (v == 0 || func_0200FB24() != 0) {
            return 1;
        }
        break;
    case 1:
        func_021762D8(&c->fEC, (u8 *)c + 0x104, c->obj.f00, c->f00);
        func_0217F528((Ov018Obj_0217F528 *)&c->obj, (int)sub, 1, 4, 0x1E, 0x10);
        func_0217F574((void **)(&c->obj), c->f128, 8, 0);
        func_0217F574((void **)(&c->obj), c->f12A, 8, 0x10);
        (*state)++;
        break;
    case 2:
        c->f136++;
        if (c->f136 > 60) {
            func_0217F58C(&c->obj);
            *state = 3;
        }
        break;
    case 3:
        if (c->f12C == 1) {
            func_0217F4A0((void **)(&c->obj), 0x19, 0, 0);
            func_02012374(a, func_02029830(sub, 0x52C));
            *state = 4;
        } else {
            func_0217F4A0((void **)(&c->obj), 0x17, 0, 0);
            func_02012374(a, func_02029830(sub, 0x52D));
            *state = 11;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(sub, 0, 6));
            m = func_0201292C(w);
            x = func_02007FB8(m, 0x23F, c->f00);
            n = c->f130;
            if (func_0200823C(0x23F) < x + n) {
                n = func_0200823C(0x23F) - x;
            }
            func_02007E50(m, 0x23F, n, c->f00);
            func_0200BF78((struct Rec1B0 *)func_0200BE48(func_02012EBC(w)));
            func_0201EFA4(c->obj.f00, 0, c->f130, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x18);
            (*state)++;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (c->f135 != 0) {
            func_0201EFA4(c->obj.f00, 0, c->f135, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x30);
            (*state)++;
        } else {
            *state = 8;
        }
        break;
    case 7:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (c->f134 != 0) {
            func_0201EFA4(c->obj.f00, 0, c->f134, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x31);
            (*state)++;
        } else {
            *state = 10;
        }
        break;
    case 9:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 10;
        }
        break;
    case 10:
        *state = 12;
        break;
    case 11:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(sub, 0, 6));
            *state = 12;
        }
        break;
    case 12:
        func_0217F318(&c->obj);
        func_0201235C(a, (void *)func_0217CA84(sub, 0));
        return 0;
    }
    return 0;
}

















void func_021808C4(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_021808E8, 0xA8);
    work = func_020124E8(task);
    func_02082D44((void *)src, work, 0x98);
}

















int func_021808E8(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj_021800A4 *)x);
    int w = (int)func_020120F4((const struct Ctx *)v);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj09400 *)obj)->f10), 0, func_02012950((struct Sub24 *)w, obj[0x40]));
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_0218383C[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = *st + 1;
        }
        break;
    case 3:
        func_0217FE38(m, (Ov018Outer *)obj);
        return 1;
    }
    return 0;
}

















void func_02180978(int id, void *dst)
{
    func_021808C4((void *)id, dst);
}
















void func_02180980(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_021809A4, 0xA4);
    work = func_020124E8(task);
    func_02082D44((void *)src, work, 0x98);
}















/*
 * Task callback in the shape of func_02182AA4: an 8-state sequence driving
 * the Ov018Obj at +0x10, with an early skip to state 5 while the owner
 * object is absent.
 */
int func_021809A4(void *a, int *state, Outer_021809A4 *c)
{
    void *sub;
    u8 *v;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 1) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 5) {
            func_0217F3C4(&c->obj, 4);
            *state = 5;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if (func_02175CF4((char *)v, v + 0x1AC) != 0) {
            c->f9C = 1;
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_02183870[c->f42]);
        (*state)++;
        break;
    case 3:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_0218387A[c->f42]);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_02183884[c->f42]);
            func_020061E4(0x5E0);
            (*state)++;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 6;
        }
        break;
    case 6:
        if (func_0217F420() == 1) {
            *state = 7;
        }
        break;
    case 7:
        func_0217FE38(v, (u8 *)c);
        func_0201235C(a, func_021804F8(sub, c->f9C));
        return 0;
    }
    return 0;
}















void func_02180B14(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_02180B38, 0xA4);
    work = func_020124E8(task);
    func_02082D44((void *)src, work, 0x98);
}
















int func_02180B38(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj_021800A4 *)x);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05933 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05933 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05933 *)obj)->f10), 2, ((struct Obj05933 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_02183848[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, (Ov018Outer *)obj);
        return 1;
    }
    return 0;
}















void func_02180BDC(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_02180C00, 0xA4);
    work = func_020124E8(task);
    func_02082D44((void *)src, work, 0x98);
}
















int func_02180C00(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj_021800A4 *)x);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05935 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05935 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05935 *)obj)->f10), 2, ((struct Obj05935 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_02183866[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, (Ov018Outer *)obj);
        return 1;
    }
    return 0;
}















void func_02180CA4(void *task, const void *src)
{
    void *work;
    func_0201232C(task, (int)func_02180CC8, 0xA4);
    work = func_020124E8(task);
    func_02082D44((void *)src, work, 0x98);
}














/*
 * Task callback in the shape of func_02182AA4: a 7-state sequence driving
 * the Ov018Obj at +0x10; state 2 pushes an ov083 child task.
 */
int func_02180CC8(void *a, int *state, Outer_0218034C *c)
{
    void *sub;
    int v;
    Args args;

    sub = func_020124E4(a);
    v = func_02158344((int)((void *)func_02012138(sub)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        c->fA0 = c->f42;
        func_0217F3C4(&c->obj, d_02183852[c->fA0]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318(&c->obj);
        args.a = c->f58;
        args.zero = 0;
        func_02012374(a, (struct Evt **)func_020124AC(sub, (u32)ov083_id, (u32 (*)(void *, u32))func_021F5260, (u32)(&args)));
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_0217F2B4((Ov018Obj_0217EC7C *)&c->obj, sub);
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4(&c->obj, d_0218385C[c->fA0]);
        (*state)++;
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1 && func_0217F420() == 1) {
            (*state)++;
        }
        break;
    case 6:
        func_0217FE38((void *)v, (u8 *)c);
        return 1;
    }
    return 0;
}














/*
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 */
void func_02180DE8(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180E0C, 0xA0);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}












int func_02180E0C(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj_021800A4 *)x);
    void *m;

    m = (void *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05937 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05937 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05937 *)obj)->f10), 2, ((struct Obj05937 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_021838B8[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, (Ov018Outer *)obj);
        return 1;
    }
    return 0;
}












void func_02180EB0(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180ED4, 0xA0);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}












int func_02180ED4(void *a, int *state, Ov018Outer_Sub_a *c)
{
    void *sub;
    int v;
    Args args;

    sub = func_020124E4(a);
    v = func_02158344((int)((void *)func_02012138(sub)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_02183890[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318(&c->obj);
        args.a = c->f58;
        args.zero = 0;
        func_02012374(a, (struct Evt **)func_020124AC(sub, (u32)ov083_id, (u32 (*)(void *, u32))func_021F5260, (u32)(&args)));
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_0217FE38((void *)v, (u8 *)c);
        return 1;
    }
    return 0;
}











void func_02180FA8(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02180FCC, 0xA0);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}











int func_02180FCC(void *a, int *state, Outer_021809A4 *c)
{
    void *sub;
    u8 *v;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 1) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 4) {
            func_0217F3C4(&c->obj, 4);
            *state = 4;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if (func_02175CF4((char *)v, (u8 *)(v + 0x1AC)) != 0) {
            c->f9C = 1;
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, func_02012944(func_020120F4(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        func_0217F3C4(&c->obj, d_021838A4[c->f42]);
        (*state)++;
        break;
    case 3:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F3C4(&c->obj, d_021838AE[c->f42]);
            func_020061E4(0x5E0);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 5;
        }
        break;
    case 5:
        if (func_0217F420() == 1) {
            *state = 6;
        }
        break;
    case 6:
        func_0217FE38(v, (u8 *)c);
        func_0201235C(a, func_021804F8(sub, c->f9C));
        return 0;
    }
    return 0;
}










void func_0218111C(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181140, 0xA0);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}










int func_02181140(int x, int *st, u8 *obj)
{
    int v = (int)func_020124E4((struct Obj_021800A4 *)x);
    void *m;

    m = (void *)func_02158344((int)func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C((struct WordSet *)(((struct Obj05940 *)obj)->f10), 0, (void *)((int)(obj + 0x78)));
        func_0201F02C((struct WordSet *)(((struct Obj05940 *)obj)->f10), 1, func_02012944(func_020120F4((const struct Ctx *)v)));
        func_0201F184((struct WordSet *)(((struct Obj05940 *)obj)->f10), 2, ((struct Obj05940 *)obj)->f58);
        func_0217F3C4((Ov018Obj *)(obj + 0x10), d_0218389A[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(obj + 0x10)) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, (Ov018Outer *)obj);
        return 1;
    }
    return 0;
}










void func_021811E4(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_0218123C, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj05941 *)t)->fA4 = 0;
    ((struct Obj05941 *)t)->f9C = r;
    t[0xA0] = src->f40;
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}









int func_0218123C(void *a, int *state, Ov018Outer_0218034C *c)
{
    void *sub;
    void *t;
    u8 *v;
    void *r;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 13) {
            func_0217F2B4((Ov018Obj_0217EC7C *)&c->obj, sub);
            func_0217F3C4(&c->obj, 4);
            *state = 13;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201EFA4(c->obj.f00, 1, c->fA1, 3, 0, 1);
        func_0217F3C4(&c->obj, c->fA4 == 0 ? d_021838F6[c->f42] : d_02183900[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            switch (func_02175514(v)) {
            case 4:
                *state = 2;
                break;
            case 2:
            case 3:
                *state = 11;
                break;
            default:
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    *state = 12;
                }
                break;
            }
        }
        break;
    case 2:
        func_0217F3C4(&c->obj, d_0218390A[c->f42]);
        *state = 3;
        break;
    case 3:
        if (func_0217405C(v, v + 0x1AC) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_02175CF4(v, v + 0x1AC) != 0) {
            func_021756F0(v, 1);
            *state = 5;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1 && func_021744D0(v, c->f40, 1) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_0215839C(v, 1, c->f40) == 1) {
            *state = 7;
        } else if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
            func_021753B8(v);
            *state = 12;
        }
        break;
    case 7:
        if (func_021744D0(v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (func_0215839C(v, 2, c->f40) == 1) {
            func_0217F318(&c->obj);
            *state = 9;
        } else if (func_02175514(v) == 3) {
            func_0217F3C4(&c->obj, 4);
            *state = 13;
        }
        break;
    case 9:
        c->fA8 = 1;
        func_02012374(a, func_021766CC(sub, &c->f9C));
        (*state)++;
        break;
    case 10:
        func_0217F2B4((Ov018Obj_0217EC7C *)&c->obj, sub);
        func_0217F3C4(&c->obj, d_02183914[c->f42]);
        *state = 13;
        break;
    case 11:
        func_0217F3C4(&c->obj, d_0218391E[c->f42]);
        *state = 13;
        break;
    case 12:
        c->fAC = 1;
        *state = 15;
        break;
    case 13:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 14;
        }
        break;
    case 14:
        if (func_0217F420() == 1) {
            *state = 15;
        }
        break;
    case 15:
        func_0217FE38(v, (Ov018Outer *)c);
        if (func_02026454(t) == 2 && func_02026474(t) != 0) {
            func_021756F0((void *)func_02026474(t), 0);
        }
        if (c->fA8 == 1) {
            r = func_021804F8(sub, c->fA8);
        } else if (c->fAC == 0) {
            r = (void *)func_0217CA84(sub, 1);
        } else {
            r = (void *)func_0217CA84(sub, 0);
        }
        func_0201235C(a, r);
        return 0;
    }
    return 0;
}









void func_0218152C(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_02181584, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj04961 *)t)->fA4 = 0;
    ((struct Obj04961 *)t)->f9C = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}









int func_02181584(void *a, int *state, Ov018Outer_0218034C *c)
{
    void *sub;
    void *t;
    u8 *v;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 14 && *state != 1 && *state != 2) {
            func_0217F2B4((Ov018Obj_0217EC7C *)&c->obj, sub);
            func_0217F3C4(&c->obj, 4);
            *state = 14;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201EFA4(c->obj.f00, 1, c->fA1, 3, 0, 1);
        func_0217F3C4(&c->obj, c->fA4 == 0 ? d_021838C4[c->f42] : d_021838CE[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            func_0217F4D8((void **)(&c->obj), (int)sub);
            (*state)++;
        }
        break;
    case 2:
        switch (func_0217F508((void **)(&c->obj))) {
        case 0:
            func_0217F4C4(&c->obj);
            *state = 3;
            break;
        case 1:
            func_0217F4C4(&c->obj);
            *state = 11;
            break;
        }
        break;
    case 3:
        if (func_02173AE0((int)v, v[0x154], 4, v[0x158]) == 1) {
            func_021756F0(v, 1);
            *state = 4;
        }
        break;
    case 4:
        func_0217F3C4(&c->obj, d_021838D8[c->f42]);
        (*state)++;
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1 && func_021744D0(v, c->f40, 1) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_0215839C(v, 1, c->f40) == 1) {
            *state = 7;
        } else if (func_020362DC() & 2) {
            if (func_02173B9C(v[0x154], v[0x158]) == 1) {
                func_021753B8(v);
                *state = 13;
                func_02026400(t);
            }
        } else if (func_02175514(v) == 3) {
            func_0217F3C4(&c->obj, 4);
            *state = 14;
        }
        break;
    case 7:
        if (func_021744D0(v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (func_0215839C(v, 2, c->f40) == 1) {
            func_0217F318(&c->obj);
            *state = 9;
        } else if (func_02175514(v) == 3) {
            func_0217F3C4(&c->obj, 4);
            *state = 14;
        }
        break;
    case 9:
        func_02012374(a, func_021766CC(sub, &c->f9C));
        (*state)++;
        break;
    case 10:
        func_0217F2B4((Ov018Obj_0217EC7C *)&c->obj, sub);
        func_0217F3C4(&c->obj, d_021838E2[c->f42]);
        *state = 14;
        break;
    case 11:
        if (func_02173AE0((int)v, v[0x154], 2, v[0x158]) == 1) {
            func_021763D8(func_020127B8(func_020120F4(sub)), 0);
            *state = 12;
        }
        break;
    case 12:
        func_0217F3C4(&c->obj, d_021838EC[c->f42]);
        *state = 14;
        break;
    case 13:
        *state = 16;
        break;
    case 14:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 15;
        }
        break;
    case 15:
        if (func_0217F420() == 1) {
            *state = 16;
        }
        break;
    case 16:
        func_0217FE38(v, (Ov018Outer *)c);
        if (func_02026454(t) == 2 && func_02026474(t) != 0) {
            func_021756F0((void *)func_02026474(t), 0);
        }
        return 1;
    }
    return 0;
}









void func_0218186C(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_0218123C, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj04963 *)t)->fA4 = 1;
    ((struct Obj04963 *)t)->f9C = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}









void func_021818C4(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, (int)func_02181584, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    ((struct Obj04964 *)t)->fA4 = 1;
    ((struct Obj04964 *)t)->f9C = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}















/*
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 */
void func_0218191C(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181940, 0xA4);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}















int func_02181940(void *a, int *state, Ov018Outer_0218191C_b *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_02183928[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 3;
        }
        break;
    case 3:
        if (func_0217F420() == 1) {
            *state = 4;
        }
        break;
    case 4:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        return 1;
    }
    return 0;
}















void func_021819D0(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_021819F4, 0xA4);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}















int func_021819F4(void *a, int *state, Ov018Outer_0218191C_b *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_0218393C[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        return 1;
    }
    return 0;
}















void func_02181A74(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181A98, 0xA4);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}















int func_02181A98(void *a, int *state, Ov018Outer_0218191C_b *c)
{
    void *sub;
    void *sys;
    int v;

    sub = func_020124E4(a);
    sys = (void *)func_02012138(sub);
    v = func_02158344((int)sys);
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_02183932[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        if (func_02158344((int)sys) != 0) {
            func_020061E4(0x737);
            func_0201235C(a, func_0217CA1C(sub));
            return 0;
        }
        return 1;
    }
    return 0;
}















void func_02181B44(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181B68, 0xA4);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}















int func_02181B68(void *a, int *state, Ov018Outer_0218191C_b *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_02183946[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        return 1;
    }
    return 0;
}














void func_02181BE8(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181C0C, 0xA4);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}














int func_02181C0C(void *a, int *state, Ov018Outer_02181BE8 *c)
{
    void *sub;
    u8 *v;
    int r;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 2 && *state < 6) {
        func_0217F3C4((Ov018Obj *)(&c->obj), 4);
        *state = 6;
        c->f98 = 1;
        return 0;
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        r = c->fA0 = func_02175CF4((char *)v, v + 0x1AC);
        switch (r) {
        case 1:
            *state = 2;
            break;
        case 2:
            *state = 5;
            break;
        }
        break;
    case 2:
        if (func_0217456C((int)v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 3:
        c->f9C = 1;
        func_021762D8(c->f44, c->f5C, c->obj.f00, c->f00);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_02183950[c->f42]);
        (*state)++;
        break;
    case 4:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            func_0217F3C4((Ov018Obj *)(&c->obj), d_0218395A[c->f42]);
            func_020061E4(0x5E0);
            *state = 6;
        }
        break;
    case 5:
        c->f9C = 1;
        func_021762D8(c->f44, c->f5C, c->obj.f00, c->f00);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_02183964[c->f42]);
        *state = 6;
        break;
    case 6:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 7;
        }
        break;
    case 7:
        if (func_0217F420() == 1) {
            *state = 8;
        }
        break;
    case 8:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        if (c->fA0 == 1) {
            func_0201235C(a, func_021804F8(sub, c->f9C));
            return 0;
        }
        return 1;
    }
    return 0;
}














/*
 *   0x02008494 (unresolved site +0034), 0x0202E82C (site +002E). Verified EXACT in scratch:
 *     void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }   (func_02082D44 arm)
 *     typedef struct { int f00; int f04; } S;
 *     void *func_0202E82C(S *p) { if (p->f04 != 0) return (char *)p + 0x2C; return (char *)p + 0xC; }
 */
void *func_02181D8C(void *a, void *b)
{
    void *w;
    void *r;
    u8 *t;

    w = (void *)func_02012F20((int)func_020120F4(a));
    r = func_020122C0(a, 0, func_02181DD4, 0x34);
    t = func_020124E8(r);
    *(void **)(t + 0x30) = func_0200846C((int)b);
    func_02008494(func_0202E82C(w), *(void **)(t + 0x30));
    func_0217F2B4(t, a);
    return r;
}












int func_02181DD4(void *a, int *state, Ov018Obj_02181DD4 *c)
{
    void *sub;
    void *w;

    sub = func_020124E4(a);
    switch (*state) {
    case 0:
        func_0201F02C(c->f00, 0, c->f30);
        func_0217F3C4((Ov018Obj *)c, 0x1C);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)c) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318((Ov018Obj_02181DD4 *)c);
        w = func_02158768((int)sub, 0xAFD, 0, 4);
        func_02159058(func_021589D0((int)w), 0x1C, 1, 0, 0);
        func_02012374(a, w);
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_020307B0(c->f30);
        return 1;
    }
    return 0;
}













void func_02181E6C(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181E90, 0x9C);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}













int func_02181E90(void *a, int *state, Ov018Outer_0218191C_b *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_02183970[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        return 1;
    }
    return 0;
}













void func_02181F10(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181F34, 0x9C);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}













int func_02181F34(void *a, int *state, Ov018Outer_0218191C_b *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_02183984[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        return 1;
    }
    return 0;
}













void func_02181FB4(Obj_021800A4 *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181FD8, 0x9C);
    dst = func_020124E8((struct Obj_021800A4 *)task);
    func_02082D44(src, dst, 0x98);
}











/*
 * Task callback in the shape of func_021809A4: a 4-state sequence with an exit that retasks the callback driving
 * the Ov018Obj at +0x10.
 */
int func_02181FD8(void *a, int *state, Outer_0218191C *c)
{
    void *h;
    u8 *v;

    h = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(h)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4((Ov018Obj *)(&c->obj), d_0218397A[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((void *)v, (Ov018Outer_0218191C_b *)c);
        if (v != 0) {
            func_020061E4(0x737);
            func_0201235C(a, func_0217CA1C(h));
            return 0;
        }
        return 1;
    }
    return 0;
}










/*
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */
void func_02182080(void *a, void *b) { func_0201232C(a,(int)((void *)func_021820A4),0x9c); func_02082D44(b,func_020124E8(a),0x98); }










/*
 * Task callback in the shape of func_021809A4: a 4-state sequence driving
 * the Ov018Obj at +0x10.
 */
int func_021820A4(void *a, int *state, Outer_0218191C *c)
{
    u8 *v;

    v = (u8 *)func_02158344((int)((void *)func_02012138(func_020124E4(a))));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4(&c->obj, d_0218398E[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((void *)v, c);
        return 1;
    }
    return 0;
}









void *func_02182124(void *a, void *unused, Rec_021800A4 *b) { void *r; r = func_020122C0(a,0,(void *)func_02182150,0x34); *(Rec_021800A4 *)func_020124E8(r) = *b; return r; }










int func_02182150(void *a, int *state, int c)
{
    void *h;
    u8 *r;

    h = func_020124E4(a);
    r = func_0201210C(h);
    switch (*state) {
    case 0:
        func_0216D9A0((void *)func_02188C7C(r));
        func_02012374(a, func_021821B0(h, (Src *)c));
        (*state)++;
        break;
    case 1:
        if (r != 0 && func_02188BE8(r) == 1) {
            func_0216D9E4((void *)func_02188C7C(r));
            return 1;
        }
        break;
    }
    return 0;
}











void *func_021821B0(void *a, Src *b)
{
    void *s;
    void *t;
    Task *p;
    u16 *q;
    void *t0;

    t0 = func_020120F4(a);
    q = &b->f14;
    s = func_02012944(t0);
    t = func_020122C0(a, 0, func_02182214, 0x54);
    p = func_020124E8(t);
    func_020084F8(s, (u32)p->f30, 8);
    p->f40 = q[1];
    p->f42 = q[0];
    p->f44 = b->f28;
    func_0217F2B4(p, a);
    return t;
}











int func_02182214(void *a, int *state, Ov018Work *c)
{
    void *sub;
    void *x;
    u8 *v;
    int idx;

    sub = func_020124E4(a);
    v = (u8 *)func_02012138(sub);
    x = func_020120F4(sub);
    func_0201210C(sub);
    v = (u8 *)func_02158344((int)v);
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state < 4) {
            func_0217F3C4(&c->obj, 6);
            *state = 4;
            c->f48 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if ((c->f50 = func_02175CF4((char *)v, v + 0x1AC)) != 0) {
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, func_02012944(x));
        func_0201EF40(c->obj.f00, 1, c->f40);
        if (c->f50 == 1) {
            idx = d_02183998[func_0217F5F0(v, (int)func_02012B58(x))];
            c->f4C = 1;
        } else {
            idx = 5;
        }
        func_0217F3C4(&c->obj, idx);
        (*state)++;
        break;
    case 3:
        if (c->f4C == 1) {
            if (func_021745F8((u8)c->f44, (u32)c->f30) == 1) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 5;
        }
        break;
    case 5:
        if (func_0217F420() == 1) {
            *state = 6;
        }
        break;
    case 6:
        func_0217F318(&c->obj);
        func_0201235C(a, func_021804F8(sub, c->f4C));
        return 0;
    }
    return 0;
}










/*
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */
void func_0218236C(void *a, void *b) { u16 *h; func_0201232C(a,(int)((void *)func_021823A8),0xa4); a = func_020124E8(a); func_02082D44(b,a,0x98); h = (u16 *)((u8 *)a+0x58); if (func_021756D0(*h) == 0) *h = 17; }










/*
 * lever: func_021804F8 reads the live r1 as its second argument.
 * The f9C comparison value is forwarded unchanged on the taken arm.
 * Addresses are Black-image addresses.
 */
int func_021823A8(void *a, int *state, Outer_021821B0 *c)
{
    void *sub;
    u8 *v;
    u16 *h;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 4) {
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 0) {
            return 0;
        }
        if (*state < 9) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), 4);
            *state = 9;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->p10, 0, c->f78);
        h = c->h58;
        func_0201EF40(c->p10, 1, h[0]);
        func_0201EFA4(c->p10, 2, h[1], 5, 0, 1);
        func_0201F02C(c->p10, 3, func_02012944(func_020120F4(sub)));
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            switch (func_02175514(v)) {
            case 7:
                *state = 2;
                break;
            case 3:
            case 8:
                *state = 5;
                break;
            case 9:
                *state = 6;
                break;
            case 10:
                *state = 7;
                break;
            default:
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    c->fA0 = 1;
                    *state = 8;
                }
                break;
            }
        }
        break;
    case 2:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[4][c->b42]);
        (*state)++;
        break;
    case 3:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_02175CF4((char *)v, v + 0x1AC) != 0) {
            c->f9C = 1;
            *state = 9;
        }
        break;
    case 5:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[1][c->b42]);
        *state = 9;
        break;
    case 6:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[2][c->b42]);
        *state = 9;
        break;
    case 7:
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839E0[3][c->b42]);
        *state = 9;
        break;
    case 8:
        *state = 11;
        break;
    case 9:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            *state = 10;
        }
        break;
    case 10:
        if (func_0217F420() == 1) {
            *state = 11;
        }
        break;
    case 11:
        func_0217FE38((void *)v, (Outer_021821B0 *)c);
        if (c->f9C == 1) {
            func_0201235C(a, func_021804F8(sub, c->f9C));
            return 0;
        }
        if (c->fA0 == 0) {
            func_0201235C(a, (u32 *)func_0217CA84(sub, 2));
            return 0;
        }
        func_0201235C(a, (u32 *)func_0217CA84(sub, 0));
        return 0;
    }
    return 0;
}









void func_021825F8(void *a, void *b) { func_0201232C(a,(int)((void *)func_0218261C),0xa4); func_02082D44(b,func_020124E8(a),0x98); }










/*
 * EXACT*: the listing extent runs into two unlabelled 8-byte Thumb
 * followers at 0x021828A8 and 0x021828B0 (ldr r3,[pc,#0]; bx r3 thunks
 * to 0x0218236D and 0x021825F9).
 *
 * Addresses are Black-image addresses.
 */
int func_0218261C(void *a, int *state, Outer_021825F8 *c)
{
    void *sub;
    void *x;
    u8 *v;
    u16 *h;
    void *t;
    int flag;
    int r;

    sub = func_020124E4(a);
    x = func_020120F4(sub);
    t = (void *)func_02012138(sub);
    h = c->h58;
    v = (u8 *)func_02158344((int)t);
    if (v == 0) {
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 0) {
            return 0;
        }
        if (*state < 8 && *state != 2 && *state != 3) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), 4);
            *state = 8;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->p10, 0, c->f78);
        func_0201EF40(c->p10, 1, h[0]);
        func_0201EFA4(c->p10, 2, h[1], 5, 0, 1);
        func_0201F02C(c->p10, 3, func_02012944(func_020120F4(sub)));
        func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[1][c->b42]);
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            func_0217F4D8((void **)((u8 *)c + 0x10), (int)sub);
            (*state)++;
        }
        break;
    case 3:
        r = func_0217F508((void **)((u8 *)c + 0x10));
        flag = 0;
        switch (r) {
        case 0:
            func_0217F4C4((u8 *)c + 0x10);
            if (h[1] > func_0200C274(func_02012F08(x))) {
                flag = 1;
                *state = 5;
            } else if (func_02007E3C(func_0201292C(x), h[0], 1, 0x15) == 0) {
                flag = 1;
                *state = 6;
            } else {
                *state = 4;
            }
            break;
        case 1:
            func_0217F4C4((u8 *)c + 0x10);
            flag = 1;
            *state = 7;
            break;
        }
        if (flag == 1) {
            func_021763D8(func_020127B8(x), 3);
        }
        break;
    case 4:
        if (func_02173AE0((int)v, v[0x154], 7, v[0x158]) == 1) {
            func_0200C29C(func_02012F08(x), h[1]);
            func_02007E50(func_0201292C(x), h[0], 1, 0x15);
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[5][c->b42]);
            *state = 8;
        }
        break;
    case 5:
        if (func_02173AE0((int)v, v[0x154], 9, v[0x158]) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[3][c->b42]);
            *state = 8;
        }
        break;
    case 6:
        if (func_02173AE0((int)v, v[0x154], 10, v[0x158]) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[4][c->b42]);
            *state = 8;
        }
        break;
    case 7:
        if (func_02173AE0((int)v, v[0x154], 8, v[0x158]) == 1) {
            func_0217F3C4((Ov018Obj *)((u8 *)c + 0x10), d_021839A4[2][c->b42]);
            *state = 8;
        }
        break;
    case 8:
        if (func_0217F40C((Ov018Obj *)((u8 *)c + 0x10)) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if (func_0217F420() == 1) {
            *state = 10;
        }
        break;
    case 10:
        func_0217FE38((void *)v, (Outer_021821B0 *)c);
        return 1;
    }
    return 0;
}

void func_021828A8(void *a, void *b)
{
    func_0218236C(a, b);
}

void func_021828B0(void *a, void *b)
{
    func_021825F8(a, b);
}
