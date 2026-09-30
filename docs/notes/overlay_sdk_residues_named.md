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
