# Residues for parked overlay-SDK rows that already named a residue

68 named rows compiled under their own region, ISA, pin and lang. Verdicts: DIFF 66, MATCH 2. Classes: structure 41, size-exact 25, witness missing 2. 4 further named rows were skipped as already modified in the working tree.

| overlay | address | function | bytes | verdict | image vs ours | first divergence | pin |
|---|---|---|---|---|---|---|---|
| ov009 | 0x02157290 | func_02157290 | 256/256 | DIFF | size-exact: allocation or scheduling | +0010 str r0, [r2, #0x4c] | mov r5, #0 | 1.1p1 |
| ov009 | 0x0215C910 | func_0215C910 | 380/380 | DIFF | size-exact: allocation or scheduling | +0008 ldr r2, [pc, #0x164] | mov r1, #0 | 1.1p1 |
| ov009 | 0x0215D92C | func_0215D92C | 260/264 | DIFF | structure: -4 bytes | +0040 beq #0x215d9d0 | beq #0x215d9cc | 1.1p1 |
| ov009 | 0x0215d070 | SOCL_CreateSocket | 184/180 | DIFF | structure: +4 bytes | +0004 ldr r1, [pc, #0x9c] | ldr r1, [pc, #0xa0] | 1.1p1 |
| ov009 | 0x021602B8 | cert_item | 1192/1196 | DIFF | structure: -4 bytes | +000C ldr r4, [fp] | ldr r1, [fp] | 1.1p1 |
| ov009 | 0x021612C8 | create_key_block | 436/440 | DIFF | structure: -4 bytes | +0014 beq #0x21612fc | beq #0x21612f8 | 1.1p1 |
| ov009 | 0x02161C80 | parse_record_in_buf | 792/792 | DIFF | size-exact: allocation or scheduling | +0124 ldrb r3, [r5, #1] | ldrb r0, [r5, #2] | 1.1p1 |
| ov009 | 0x02163438 | CPSi_md5_calc | 184/184 | DIFF | size-exact: allocation or scheduling | +0000 push {r4, r5, r6, r7, r8, lr} | push {r3, r4, r5, r6, r7, lr} | 1.1p1 |
| ov009 | 0x02163628 | func_02163628 | 1652/1652 | DIFF | size-exact: allocation or scheduling | +0010 add r7, sp, #0x10 | add r8, sp, #0x10 | 1.1p1 |
| ov009 | 0x02163CF0 | CPSi_sha1_calc | 184/184 | DIFF | size-exact: allocation or scheduling | +0000 push {r4, r5, r6, r7, r8, lr} | push {r3, r4, r5, r6, r7, lr} | 1.1p1 |
| ov009 | 0x021671C0 | WcmWmcbScanEx | 636/648 | DIFF | structure: -12 bytes | +0024 b #0x2167410 | b #0x21673b0 | 1.1p1 |
| ov009 | 0x021674BC | WcmWmcbConnect | 552/552 | DIFF | size-exact: allocation or scheduling | +0088 pop {r4, r5, r6, pc} | b #0x2167670 | 1.1p1 |
| ov009 | 0x021679C0 | WcmWmcbReset | 756/756 | DIFF | size-exact: allocation or scheduling | +000C mov r5, #3 | bl #0x21657c8                          <- PC24 WCMi_GetSystemWork [resolved: label] | 1.1p1 |
| ov009 | 0x02167E20 | WcmWmcbSetDCFDataAsync | 100/104 | DIFF | structure: -4 bytes | +003C cmp r0, #0 | ldr r6, [r4, #0x2c] | 1.1p1 |
| ov009 | 0x02168AD4 | DWCi_FriendProcess | 684/680 | DIFF | structure: +4 bytes | +0008 ldr r4, [pc, #0x28c] | ldr sb, [pc, #0x290] | 1.1p1 |
| ov009 | 0x02169934 | DWCi_GPProfileSearchCallback | 636/636 | DIFF | size-exact: allocation or scheduling | +0030 mul r6, r8, r0 | mul r7, r8, r0 | 1.1p1 |
| ov009 | 0x0216D57C | DWCi_MatchProcess | 1028/3908 | DIFF | structure: -2880 bytes | +0000 push {r3, r4, r5, r6, r7, r8, sb, lr} | push {r4, lr} | 1.1p1 |
| ov009 | 0x0216F770 | func_0216F770 | 868/868 | DIFF | size-exact: allocation or scheduling | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r0, r1, r2, r3} | 1.1p1 |
| ov009 | 0x021702A0 | DWCi_ProcessRecvMatchCommand | 852/4396 | DIFF | structure: -3544 bytes | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r3, r4, r5, lr} | 1.1p1 |
| ov009 | 0x02173064 | DWCi_SendMatchSynPacket | 624/660 | DIFF | structure: -36 bytes | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r4, r5, r6, r7, r8, sb, sl, lr} | 1.1p1 |
| ov009 | 0x021732F8 | DWCi_ProcessMatchSynTimeout | 560/564 | DIFF | structure: -4 bytes | +0068 ldr r2, [pc, #0x1b8] | ldr r2, [pc, #0x1b4] | 1.1p1 |
| ov009 | 0x0217AB78 | DWCi_Netcheck_Thread | 1696/3184 | DIFF | structure: -1488 bytes | +0004 sub sp, sp, #0x290 | sub sp, sp, #0x90 | 1.1p1 |
| ov009 | 0x02181C2C | func_02181C2C | 228/228 | DIFF | size-exact: allocation or scheduling | +0058 ldr r3, [pc, #0x7c] | ldr r3, [pc, #0x74] | 1.1p1 |
| ov009 | 0x02182554 | func_02182554 | 224/232 | DIFF | structure: -8 bytes | +0050 ldr r3, [r6] | ldr r2, [r6] | 1.1p1 |
| ov009 | 0x02195EC4 | gti2ConnectionError | 156/152 | DIFF | structure: +4 bytes | +0048 bne #0x2195f54 | movne r4, #1 | 1.1p1 |
| ov009 | 0x02197458 | gti2BeginReliableMessage | 244/244 | DIFF | size-exact: allocation or scheduling | +0040 moveq r0, #0 | movne r0, #1 | 1.1p1 |
| ov009 | 0x0219C3A4 | func_0219C3A4 | 432/432 | MATCH | witness missing | | | 1.1p1 |
| ov016 | 0x021B9BF8 | ScanAP | 616/660 | DIFF | structure: -44 bytes | +0002 sub sp, #0x70 | sub sp, #0x68 | ../2.0/sp1p2 |
| ov016 | 0x021BA804 | AutoConfigThreadEx | 952/996 | DIFF | structure: -44 bytes | +0000 push {r4, r5, r6, r7, lr} | push {r3, r4, r5, r6, r7, lr} | ../2.0/sp1p2 |
| ov016 | 0x021C00A8 | disp | 624/640 | DIFF | structure: -16 bytes | +0008 ldr r3, [pc, #0x24c] | ldr r4, [pc, #0x240] | 1.1p1 |
| ov016 | 0x021C1210 | taskFramework | 596/632 | DIFF | structure: -36 bytes | +0014 ldr r6, [pc, #0x254] | ldr r6, [pc, #0x234] | 1.1p1 |
| ov016 | 0x021C2610 | drawInfo | 504/528 | DIFF | structure: -24 bytes | +0028 add sl, sp, #0x1a | add sb, sp, #0x1a | 1.1p1 |
| ov016 | 0x021C687C | input | 404/400 | DIFF | structure: +4 bytes | +0004 ldr r5, [pc, #0x178] | ldr r5, [pc, #0x17c] | 1.1p1 |
| ov016 | 0x021C73D0 | input | 748/704 | DIFF | structure: +44 bytes | +000C ldr r7, [pc, #0x2a0] | ldr r7, [pc, #0x2cc] | 1.1p1 |
| ov016 | 0x021C7D80 | drawMessage | 828/824 | DIFF | structure: +4 bytes | +001C ldr r0, [pc, #0x2e8] | ldr r0, [pc, #0x2ec] | 1.1p1 |
| ov016 | 0x021CD458 | func_021CD458 | 156/156 | MATCH | witness missing | | | 1.1p1 |
| ov016 | 0x021CFCC8 | write | 336/336 | DIFF | size-exact: allocation or scheduling | +012C str r2, [sp] | ldr r0, [r6] | 1.1p1 |
| ov016 | 0x021D04BC | taskBegin4 | 156/156 | DIFF | size-exact: allocation or scheduling | +0068 ldr r0, [r4, #4] | str r2, [sp, #4] | 1.1p1 |
| ov016 | 0x021D06A4 | taskEnd0 | 144/144 | DIFF | size-exact: allocation or scheduling | +0060 ldr r0, [r4, #4] | str r2, [sp, #4] | 1.1p1 |
| ov016 | 0x021D1208 | DWCi_WINlInitEx | 784/796 | DIFF | structure: -12 bytes | +0000 push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |
| ov016 | 0x021D2450 | ParentStateCallback | 792/796 | DIFF | structure: -4 bytes | +0000 push {r4, r5, r6, r7, r8, lr} | push {r3, r4, r5, r6, r7, lr} | 1.1p1 |
| ov107 | 0x021F2200 | MBi_CommParentRecvDataPerChild | 1216/1216 | DIFF | size-exact: allocation or scheduling | +0008 ldr sb, [pc, #0x4a4] | movs r4, r1 | 1.1p1 |
| ov107 | 0x021F2A44 | MBi_CommParentSendBlock | 632/632 | DIFF | size-exact: allocation or scheduling | +0128 ldr r6, [r5] | ldr r7, [r5] | 1.1p1 |
| ov107 | 0x021F3544 | MB_RegisterFile | 632/632 | DIFF | size-exact: allocation or scheduling | +01A8 add r7, r6, #0x1e8 | add r3, r6, #0x1e8 | 1.1p1 |
| ov107 | 0x021F4140 | MBi_SendFixedBeacon | 356/356 | DIFF | size-exact: allocation or scheduling | +0010 ldr r4, [r3, #0x1c] | ldr r0, [r3, #0x1c] | dsi/1.1p1 |
| ov107 | 0x021F42D4 | MBi_SendVolatBeacon | 600/612 | DIFF | structure: -12 bytes | +0008 ldr r7, [pc, #0x240] | ldr r7, [pc, #0x238] | 1.1p1 |
| ov107 | 0x021F46C8 | MBi_ParentCallback | 2000/2004 | DIFF | structure: -4 bytes | +001C ldr r4, [pc, #0x7a0] | ldr r4, [pc, #0x79c] | dsi/1.1p1 |
| ov107 | 0x021F4EFC | MBi_ChildCallback | 1720/2464 | DIFF | structure: -744 bytes | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r3, r4, r5, r6, r7, r8, lr} | dsi/1.1p1 |
| ov107 | 0x021F5904 | MB_Init | 472/472 | DIFF | size-exact: allocation or scheduling | +010C add r6, r6, #1 | str r1, [r0, #0xc] | dsi/1.1p1 |
| ov114 | 0x021BACFC | NHTTPi_setReqQueue | 152/152 | DIFF | size-exact: allocation or scheduling | +0064 ldr r2, [r6, #4] | mvn r1, #0 | dsi/1.1p1 |
| ov114 | 0x021BBA14 | NHTTPi_CancelRequestAsync | 148/152 | DIFF | structure: -4 bytes | +0030 beq #0x21bba7c | beq #0x21bba78 | dsi/1.1p1 |
| ov114 | 0x021BD7E8 | NHTTPi_ThreadSendProc | 896/896 | DIFF | size-exact: allocation or scheduling | +0014 mov r6, r0 | mov r7, r0 | 1.1p1 |
| ov114 | 0x021C07B8 | func_021C07B8 | 248/248 | DIFF | size-exact: allocation or scheduling | +00AC beq #0x21c087c | beq #0x21c0888 | 1.1p1 |
| ov114 | 0x021C2C28 | func_021C2C28 | 392/392 | DIFF | size-exact: allocation or scheduling | +0048 ldrb r2, [r0] | ldrb r3, [r0] | 1.1p1 |
| ov114 | 0x021C3218 | ghiPostStateDoPosting | 628/1564 | DIFF | structure: -936 bytes | +0000 push {r4, r5, r6, r7, r8, sb, sl, lr} | push {r3, r4, r5, r6, r7, lr} | 1.1p1 |
| ov114 | 0x021C68BC | req_callback | 664/648 | DIFF | structure: +16 bytes | +0008 mov r8, r0 | mov r7, r0 | 1.1p1 |
| ov114 | 0x021C7644 | DWCi_Ndi_response_list | 724/640 | DIFF | structure: +84 bytes | +0030 ldr r1, [pc, #0x244] | ldr r1, [pc, #0x298] | 1.1p1 |
| ov114 | 0x021CA5E4 | func_021CA5E4 | 180/184 | DIFF | structure: -4 bytes | +0004 ldr r4, [r0] | ldr lr, [r0] | 1.1p1 |
| ov114 | 0x021CB3B4 | func_021CB3B4 | 224/224 | DIFF | size-exact: allocation or scheduling | +0010 mov r2, #0 | moveq r0, r4 | 1.1p1 |
| ov114 | 0x021CD210 | CRYPTOi__BN_mod_exp_mont | 1764/1908 | DIFF | structure: -144 bytes | +0000 push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |
| ov172 | 0x021BE5C4 | func_021BE5C4 | 2444/2548 | DIFF | structure: -104 bytes | +0004 sub sp, sp, #0x350 | sub sp, sp, #0x348 | 1.1p1 |
| ov172 | 0x021BF690 | func_021BF690 | 896/984 | DIFF | structure: -88 bytes | +0004 ldr r4, [pc, #0x3bc] | ldr r4, [pc, #0x364] | 1.1p1 |
| ov172 | 0x021BFA68 | func_021BFA68 | 1424/1372 | DIFF | structure: +52 bytes | +0004 sub sp, sp, #0x2c | sub sp, sp, #0x34 | 1.1p1 |
| ov172 | 0x021C0D04 | Yos_JpegEncoderForwardDct | 848/840 | DIFF | structure: +8 bytes | +000C add r3, r0, ip | add lr, sp, #0x14 | 1.1p1 |
| ov172 | 0x021C104C | Yos_JpegEncoderHuffmanEncoderBuildTable | 520/508 | DIFF | structure: +12 bytes | +0008 mov r7, r2 | mov r8, r2 | 1.1p1 |
| ov172 | 0x021C131C | Yos_JpegEncoderComponentSequential | 476/484 | DIFF | structure: -8 bytes | +0010 mla r8, r6, r5, r7 | mla r7, r6, r5, r7 | 1.1p1 |
| ov172 | 0x021C1AE4 | SSPi_JpegEncoderDoSign | 732/680 | DIFF | structure: +52 bytes | +0008 ldr r2, [pc, #0x28c] | ldr r2, [pc, #0x2c0] | 1.1p1 |
| ov172 | 0x021C20B0 | Yos_JPEGEncode | 2512/2592 | DIFF | structure: -80 bytes | +0000 push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |

## Concrete byte count per row

The `bytes` column above is compiled/listing extent; this is how many of those bytes actually differ (the harness's `concrete` count, relocation fields excluded).

| overlay | address | function | concrete bytes | class |
|---|---|---|---|---|
| ov009 | 0x02157290 | func_02157290 | 16 | size-exact: allocation or scheduling |
| ov009 | 0x0215C910 | func_0215C910 | 24 | size-exact: allocation or scheduling |
| ov009 | 0x0215D92C | func_0215D92C | 101 | structure: -4 bytes |
| ov009 | 0x0215d070 | SOCL_CreateSocket | 78 | structure: +4 bytes |
| ov009 | 0x021602B8 | cert_item | 714 | structure: -4 bytes |
| ov009 | 0x021612C8 | create_key_block | 318 | structure: -4 bytes |
| ov009 | 0x02161C80 | parse_record_in_buf | 260 | size-exact: allocation or scheduling |
| ov009 | 0x02163438 | CPSi_md5_calc | 76 | size-exact: allocation or scheduling |
| ov009 | 0x02163628 | func_02163628 | 142 | size-exact: allocation or scheduling |
| ov009 | 0x02163CF0 | CPSi_sha1_calc | 90 | size-exact: allocation or scheduling |
| ov009 | 0x021671C0 | WcmWmcbScanEx | 372 | structure: -12 bytes |
| ov009 | 0x021674BC | WcmWmcbConnect | 12 | size-exact: allocation or scheduling |
| ov009 | 0x021679C0 | WcmWmcbReset | 594 | size-exact: allocation or scheduling |
| ov009 | 0x02167E20 | WcmWmcbSetDCFDataAsync | 35 | structure: -4 bytes |
| ov009 | 0x02168AD4 | DWCi_FriendProcess | 428 | structure: +4 bytes |
| ov009 | 0x02169934 | DWCi_GPProfileSearchCallback | 21 | size-exact: allocation or scheduling |
| ov009 | 0x0216D57C | DWCi_MatchProcess | 841 | structure: -2880 bytes |
| ov009 | 0x0216F770 | func_0216F770 | 372 | size-exact: allocation or scheduling |
| ov009 | 0x021702A0 | DWCi_ProcessRecvMatchCommand | 717 | structure: -3544 bytes |
| ov009 | 0x02173064 | DWCi_SendMatchSynPacket | 463 | structure: -36 bytes |
| ov009 | 0x021732F8 | DWCi_ProcessMatchSynTimeout | 106 | structure: -4 bytes |
| ov009 | 0x0217AB78 | DWCi_Netcheck_Thread | 1511 | structure: -1488 bytes |
| ov009 | 0x02181C2C | func_02181C2C | 9 | size-exact: allocation or scheduling |
| ov009 | 0x02182554 | func_02182554 | 78 | structure: -8 bytes |
| ov009 | 0x02195EC4 | gti2ConnectionError | 44 | structure: +4 bytes |
| ov009 | 0x02197458 | gti2BeginReliableMessage | 14 | size-exact: allocation or scheduling |
| ov009 | 0x0219C3A4 | func_0219C3A4 | 0 | witness missing |
| ov016 | 0x021B9BF8 | ScanAP | 494 | structure: -44 bytes |
| ov016 | 0x021BA804 | AutoConfigThreadEx | 801 | structure: -44 bytes |
| ov016 | 0x021C00A8 | disp | 457 | structure: -16 bytes |
| ov016 | 0x021C1210 | taskFramework | 416 | structure: -36 bytes |
| ov016 | 0x021C2610 | drawInfo | 141 | structure: -24 bytes |
| ov016 | 0x021C687C | input | 318 | structure: +4 bytes |
| ov016 | 0x021C73D0 | input | 601 | structure: +44 bytes |
| ov016 | 0x021C7D80 | drawMessage | 479 | structure: +4 bytes |
| ov016 | 0x021CD458 | func_021CD458 | 0 | witness missing |
| ov016 | 0x021CFCC8 | write | 9 | size-exact: allocation or scheduling |
| ov016 | 0x021D04BC | taskBegin4 | 12 | size-exact: allocation or scheduling |
| ov016 | 0x021D06A4 | taskEnd0 | 12 | size-exact: allocation or scheduling |
| ov016 | 0x021D1208 | DWCi_WINlInitEx | 567 | structure: -12 bytes |
| ov016 | 0x021D2450 | ParentStateCallback | 245 | structure: -4 bytes |
| ov107 | 0x021F2200 | MBi_CommParentRecvDataPerChild | 1018 | size-exact: allocation or scheduling |
| ov107 | 0x021F2A44 | MBi_CommParentSendBlock | 12 | size-exact: allocation or scheduling |
| ov107 | 0x021F3544 | MB_RegisterFile | 8 | size-exact: allocation or scheduling |
| ov107 | 0x021F4140 | MBi_SendFixedBeacon | 63 | size-exact: allocation or scheduling |
| ov107 | 0x021F42D4 | MBi_SendVolatBeacon | 401 | structure: -12 bytes |
| ov107 | 0x021F46C8 | MBi_ParentCallback | 1178 | structure: -4 bytes |
| ov107 | 0x021F4EFC | MBi_ChildCallback | 1473 | structure: -744 bytes |
| ov107 | 0x021F5904 | MB_Init | 9 | size-exact: allocation or scheduling |
| ov114 | 0x021BACFC | NHTTPi_setReqQueue | 17 | size-exact: allocation or scheduling |
| ov114 | 0x021BBA14 | NHTTPi_CancelRequestAsync | 66 | structure: -4 bytes |
| ov114 | 0x021BD7E8 | NHTTPi_ThreadSendProc | 46 | size-exact: allocation or scheduling |
| ov114 | 0x021C07B8 | func_021C07B8 | 26 | size-exact: allocation or scheduling |
| ov114 | 0x021C2C28 | func_021C2C28 | 48 | size-exact: allocation or scheduling |
| ov114 | 0x021C3218 | ghiPostStateDoPosting | 537 | structure: -936 bytes |
| ov114 | 0x021C68BC | req_callback | 513 | structure: +16 bytes |
| ov114 | 0x021C7644 | DWCi_Ndi_response_list | 507 | structure: +84 bytes |
| ov114 | 0x021CA5E4 | func_021CA5E4 | 80 | structure: -4 bytes |
| ov114 | 0x021CB3B4 | func_021CB3B4 | 48 | size-exact: allocation or scheduling |
| ov114 | 0x021CD210 | CRYPTOi__BN_mod_exp_mont | 1505 | structure: -144 bytes |
| ov172 | 0x021BE5C4 | func_021BE5C4 | 2098 | structure: -104 bytes |
| ov172 | 0x021BF690 | func_021BF690 | 658 | structure: -88 bytes |
| ov172 | 0x021BFA68 | func_021BFA68 | 1129 | structure: +52 bytes |
| ov172 | 0x021C0D04 | Yos_JpegEncoderForwardDct | 717 | structure: +8 bytes |
| ov172 | 0x021C104C | Yos_JpegEncoderHuffmanEncoderBuildTable | 241 | structure: +12 bytes |
| ov172 | 0x021C131C | Yos_JpegEncoderComponentSequential | 282 | structure: -8 bytes |
| ov172 | 0x021C1AE4 | SSPi_JpegEncoderDoSign | 568 | structure: +52 bytes |
| ov172 | 0x021C20B0 | Yos_JPEGEncode | 2209 | structure: -80 bytes |

## The pin and flag lever, measured shut

Brief rule 4 says to change the pin or the flags before re-spelling a size-exact body. That was done exhaustively for all 68 rows: every row was swept across the nine bundled dsi front ends (1.1, 1.1p1, 1.2, 1.2p1, 1.2p2, 1.3, 1.3p1, 1.6sp1, 1.6sp2) crossed with the harness's flag matrix, under its own region, ISA and lang — 4284 configurations, **no EXACT and no new MATCH** anywhere. The only MATCH verdicts the sweep produced are the two already-known witness-missing rows, and they are MATCH under every front end (a witness gap is not a codegen property).

At the vendor's own flag set (-O4,p), the parked pin is already the minimiser for 61 of the 64 rows whose parked front end is in the sweep set. For 3 rows a different front end shaves the concrete count at -O4,p, and every one of those wins is 1-2 bytes under 1.6sp1/1.6sp2 while the vendor object is stamped 1.1p1 or ../2.0/sp1p2 — a different compiler is not the build compiler, so none of them is a promotion. (The other 4 rows: 2 are pinned to `../2.0/sp1p2`, outside the sweep set, and the 2 MATCH rows have no concrete count to minimise.)

- `ov016` 0x021D1208 DWCi_WINlInitEx — parked pin 1.1p1 gives 567 concrete, 1.6sp1/1.6sp2 gives 565 (size 784/796 unchanged)
- `ov114` 0x021CD210 CRYPTOi__BN_mod_exp_mont — parked pin 1.1p1 gives 1505 concrete, 1.6sp1/1.6sp2 gives 1504 (size 1764/1908 unchanged)
- `ov172` 0x021C20B0 Yos_JPEGEncode — parked pin 1.1p1 gives 2209 concrete, 1.6sp1/1.6sp2 gives 2207 (size 2512/2592 unchanged)

Other flag sets (-O4,s, -O4, -O3, -O2, -O1, -O0, -inline off/all, -ipa function) lower the raw concrete count for 22 rows, but none of them is the vendor's build configuration, none reaches EXACT, and each one changes the emitted size as well — recorded in `scratch/S2/sweep_base.json`, not actionable.

The 25 size-exact rows were then swept a second time with `--extra`, which adds the `-inline off`, `-inline all`, `-ipa function` and `-O4,s -inline off` variants: 2475 configurations on those rows (900 beyond the base matrix), again **no EXACT and no new MATCH**. A size-exact row in this set that the sweep cannot move is capped by body shape, not by the pin (results in `scratch/S2/sweep_extra.json`).


## Measurement cross-check

Every row was measured twice by different paths: `match.py one` under the row's own pin (the residue column above) and the sweep's own cell for that same pin. The two agree on the emitted size for 66 of 68 rows and on the concrete count for the ones they share; the two exceptions (`ov016` 0x021B9BF8 and 0x021BA804) are pinned to `../2.0/sp1p2`, a front end outside `dsi/` that the sweep does not cover, and were measured directly. No row timed out and no row failed to compile.


## Rows skipped as already modified in the working tree

`git status --porcelain` shows a live modification on these 4 named rows, so they were left untouched and are NOT counted in the 68 measured rows above:

- `src/pending/ov_sdk/ov009_func_02174FE8.c`
- `src/pending/ov_sdk/ov009_func_0217E078.c`
- `src/pending/ov_sdk/ov016_func_021D0CEC.c`
- `src/pending/ov_sdk/ov107_func_021F2FA0.c`

## Promotions

None. No named-but-unclassified row is EXACT or EXACT* under its own pin, under any other dsi front end, or under any flag variant in the sweep, so there was nothing to copy into `src/matched/ov_sdk/` and no shard to write. The two MATCH rows (`ov009` 0x0219C3A4, `ov016` 0x021CD458) are one witness away from EXACT* but the target addresses their wildcarded relocations need (0x021A1B64 natNegBytes template, 0x020589C4 DWCi_BACKUPlGetWifi) have no shard, no catalog row and no listing-attested object start; a case-insensitive search of `layout/` finds neither.


## Reading the structure class

`structure: +N/-N bytes` is not one condition. Of the 41 structure rows, 5 are genuine **partial reconstructions** — the parked prose for each of them already says so, and the size gap is the code that is not written yet, not a codegen quarrel. The remaining 36 have a gap of at most 144 bytes (most under 64), which is the generated-code shape the parked prose describes: branch order, literal-pool order, one hoisted or sunk instruction, or a callee-saved register rotation. Only the second group is a codegen wall; the first group is unfinished work that no pin or spelling change can close.

| overlay | address | function | bytes | missing |
|---|---|---|---|---|
| ov009 | 0x021702A0 | DWCi_ProcessRecvMatchCommand | 852/4396 | 3544 |
| ov009 | 0x0216D57C | DWCi_MatchProcess | 1028/3908 | 2880 |
| ov009 | 0x0217AB78 | DWCi_Netcheck_Thread | 1696/3184 | 1488 |
| ov114 | 0x021C3218 | ghiPostStateDoPosting | 628/1564 | 936 |
| ov107 | 0x021F4EFC | MBi_ChildCallback | 1720/2464 | 744 |
