# Residues for parked overlay-SDK rows that named none

101 rows compiled under their own region, ISA, pin and lang. Verdicts: DIFF 99, MATCH 2. Classes: size-exact 55, structure 44, witness missing 2.

| overlay | address | function | bytes | verdict | image vs ours | first divergence | pin |
|---|---|---|---|---|---|---|---|
| ov009 | 0x021573C4 | func_021573C4 | 536/536 | DIFF | size-exact: allocation or scheduling | +0008 mov r4, r0 | mov r5, r0 | 1.1p1 |
| ov009 | 0x02158524 | func_02158524 | 180/180 | DIFF | size-exact: allocation or scheduling | +0018 ldr r2, [pc, #0x90] | strh r4, [r5, #0x22] | 1.1p1 |
| ov009 | 0x02159A80 | func_02159A80 | 1384/1384 | DIFF | size-exact: allocation or scheduling | +00A8 str r0, [sp] | mov fp, r0 | 1.1p1 |
| ov009 | 0x0215BF88 | func_0215BF88 | 876/880 | DIFF | structure: -4 bytes | +0008 ldr r2, [pc, #0x354] | ldr r2, [pc, #0x350] | 1.1p1 |
| ov009 | 0x0215CB24 | SOCLi_StartupCPS | 388/380 | DIFF | structure: +8 bytes | +0004 ldr r7, [pc, #0x140] | ldr r7, [pc, #0x148] | 1.1p1 |
| ov009 | 0x0215E2C0 | func_0215E2C0 | 36/36 | DIFF | size-exact: allocation or scheduling | +0008 ldrh r1, [r0] | ldrh r1, [r0, #2] | 1.1p1 |
| ov009 | 0x0215E588 | func_0215E588 | 152/152 | DIFF | size-exact: allocation or scheduling | +0020 ldrh r3, [r5, #0x3a] | ldrh r2, [r5, #0x3a] | 1.1p1 |
| ov009 | 0x0215E6B8 | func_0215E6B8 | 156/172 | DIFF | structure: -16 bytes | +0004 mov r4, r0 | mov r5, r0 | 1.1p1 |
| ov009 | 0x0215F0F0 | func_0215F0F0 | 152/148 | DIFF | structure: +4 bytes | +0000 push {r4, lr} | push {r3, r4, r5, lr} | 1.1p1 |
| ov009 | 0x02163E40 | func_02163E40 | 120/120 | DIFF | size-exact: allocation or scheduling | +0010 add r4, r0, #2 | add lr, r0, #2 | 1.1p1 |
| ov009 | 0x02164D74 | func_02164D74 | 364/364 | DIFF | size-exact: allocation or scheduling | +0018 ldr sb, [pc, #0x148] | mov r1, #0 | 1.1p1 |
| ov009 | 0x02166600 | func_02166600 | 120/128 | DIFF | structure: -8 bytes | +000C cmp r0, #1 | mov r6, r1 | 1.1p1 |
| ov009 | 0x021685CC | func_021685CC | 268/276 | DIFF | structure: -8 bytes | +0008 ldr r6, [pc, #0xf0] | ldr r4, [pc, #0xec] | 1.1p1 |
| ov009 | 0x0216980C | func_0216980C | 184/180 | DIFF | structure: +4 bytes | +0004 ldr r4, [pc, #0xa4] | mov r5, #0 | 1.1p1 |
| ov009 | 0x0216C230 | DWCi_GT2ClosedProcess | 1368/1368 | DIFF | size-exact: allocation or scheduling | +0080 bne #0x216c3b0 | bne #0x216c410 | 1.1p1 |
| ov009 | 0x0216C8DC | func_0216C8DC | 296/296 | DIFF | size-exact: allocation or scheduling | +0004 movs r6, r1 | movs r7, r1 | dsi/1.1p1 |
| ov009 | 0x0216CA04 | func_0216CA04 | 300/300 | DIFF | size-exact: allocation or scheduling | +0004 movs r6, r1 | movs r7, r1 | 1.1p1 |
| ov009 | 0x021700C8 | func_021700C8 | 160/160 | DIFF | size-exact: allocation or scheduling | +0030 ldr ip, [pc, #0x64] | ldr r0, [pc, #0x64] | 1.1p1 |
| ov009 | 0x0217273C | func_0217273C | 384/380 | DIFF | structure: +4 bytes | +0000 push {r3, r4, r5, r6, r7, lr} | push {r4, r5, r6, lr} | 1.1p1 |
| ov009 | 0x02176164 | func_02176164 | 236/240 | DIFF | structure: -4 bytes | +0080 bge #0x217623c | bge #0x2176238 | 1.1p1 |
| ov009 | 0x02176CF8 | func_02176CF8 | 236/244 | DIFF | structure: -8 bytes | +0004 ldr r3, [pc, #0xe0] | ldr r6, [pc, #0xdc] | 1.1p1 |
| ov009 | 0x021782B4 | func_021782B4 | 256/264 | DIFF | structure: -8 bytes | +0004 ldr r5, [pc, #0xe4] | ldr r5, [pc, #0xe0] | 1.1p1 |
| ov009 | 0x0217CF5C | func_0217CF5C | 564/556 | DIFF | structure: +8 bytes | +0008 ldr ip, [pc, #0x214] | ldr ip, [pc, #0x21c] | 1.1p1 |
| ov009 | 0x0217D280 | func_0217D280 | 172/172 | DIFF | size-exact: allocation or scheduling | +001C add r6, sb, #0x29 | add r7, sb, #0x29 | 1.1p1 |
| ov009 | 0x0217D8E0 | func_0217D8E0 | 32/36 | DIFF | structure: -4 bytes | +0004 mov lr, r1 | str r3, [sp] | 1.1p1 |
| ov009 | 0x0217D904 | func_0217D904 | 936/928 | DIFF | structure: +8 bytes | +0008 mov r5, r1 | mov r8, r1 | 1.1p1 |
| ov009 | 0x0217DE94 | func_0217DE94 | 484/484 | DIFF | size-exact: allocation or scheduling | +0014 mov r0, #7 | str r6, [sp, #0x14] | 1.1p1 |
| ov009 | 0x0217E504 | func_0217E504 | 704/704 | DIFF | size-exact: allocation or scheduling | +0010 mov r4, r2 | mov r7, r0 | 1.1p1 |
| ov009 | 0x02180A64 | func_02180A64 | 408/408 | DIFF | size-exact: allocation or scheduling | +0064 add r4, sp, #0x30 | add r3, sp, #0x30 | 1.1p1 |
| ov009 | 0x02180C94 | func_02180C94 | 436/436 | DIFF | size-exact: allocation or scheduling | +0050 ldr r3, [sp, #0x94] | ldr r4, [sp, #0x94] | 1.1p1 |
| ov009 | 0x02182414 | func_02182414 | 320/320 | DIFF | size-exact: allocation or scheduling | +0038 ldrsb r3, [sl, r0] | ldrsb r2, [sl, r0] | 1.1p1 |
| ov009 | 0x0218263C | func_0218263C | 720/720 | DIFF | size-exact: allocation or scheduling | +0008 mov r5, r1 | mov r4, r1 | 1.1p1 |
| ov009 | 0x021870B8 | gpiProcessRecvBuddyMessage | 3212/3240 | DIFF | structure: -28 bytes | +001C ldr r1, [pc, #0xc40] | ldr r1, [pc, #0xc24] | 1.1p1 |
| ov009 | 0x02187D60 | gpiProcessRecvBuddyStatusInfo | 2204/2264 | DIFF | structure: -60 bytes | +002C ldr r1, [pc, #0x85c] | ldr r1, [pc, #0x820] | 1.1p1 |
| ov009 | 0x021894D8 | func_021894D8 | 364/364 | DIFF | size-exact: allocation or scheduling | +0118 ldr r2, [r1] | ldr r3, [r1] | dsi/1.1p1 |
| ov009 | 0x02189780 | func_02189780 | 520/524 | DIFF | structure: -4 bytes | +0078 ldr r1, [pc, #0x174] | ldr r1, [pc, #0x170] | dsi/1.1p1 |
| ov009 | 0x0218DD88 | func_0218DD88 | 908/908 | DIFF | size-exact: allocation or scheduling | +0128 ldr r0, [r7, #0x1c] | strb r4, [r3, #7] | 1.1p1 |
| ov009 | 0x0219091C | func_0219091C | 232/9460 | DIFF | structure: -9228 bytes | +0000 push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r4, r5, r6, r7, lr} | dsi/1.1p1 |
| ov009 | 0x02194B74 | func_02194B74 | 248/248 | DIFF | size-exact: allocation or scheduling | +0084 eor r0, r0, r2 | eor r0, r2, r0 | 1.1p1 |
| ov009 | 0x02195278 | gti2SendFilterCallback | 200/200 | DIFF | size-exact: allocation or scheduling | +0024 cmp r0, #0 | movs r2, r0 | 1.1p1 |
| ov009 | 0x021986C4 | func_021986C4 | 328/324 | DIFF | structure: +4 bytes | +002C beq #0x21987e4 | beq #0x21987e8 | 1.1p1 |
| ov009 | 0x02198A0C | func_02198A0C | 1128/1128 | DIFF | size-exact: allocation or scheduling | +011C mov r3, #0xa | mov sb, #0xa | 1.1p1 |
| ov009 | 0x021990A0 | func_021990A0 | 52/52 | DIFF | size-exact: allocation or scheduling | +0020 mvn r1, #0x80000000 | sub r1, r0, #0x80000002 | 1.1p1 |
| ov009 | 0x0219A52C | func_0219A52C | 244/244 | DIFF | size-exact: allocation or scheduling | +0000 push {r3, r4, r5, r6, r7, r8, sb, lr} | push {r4, r5, r6, lr} | 1.1p1 |
| ov009 | 0x0219B73C | func_0219B73C | 192/192 | DIFF | size-exact: allocation or scheduling | +0004 lsl r1, r1, #0x10 | mov r4, #0 | 1.1p1 |
| ov009 | 0x0219C5B8 | func_0219C5B8 | 364/364 | DIFF | size-exact: allocation or scheduling | +0024 mov r0, r5 | sub r8, r5, #1 | 1.1p1 |
| ov009 | 0x0219C7C0 | qr2_parse_queryA | 1472/1532 | DIFF | structure: -60 bytes | +0000 push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |
| ov009 | 0x0219D5C4 | QEStartQuery | 672/672 | DIFF | size-exact: allocation or scheduling | +000C mov r8, #0 | mov r7, #0 | 1.1p1 |
| ov009 | 0x0219E9F4 | func_0219E9F4 | 464/464 | MATCH | witness missing | | | 1.1p1 |
| ov009 | 0x0219FE44 | func_0219FE44 | 236/236 | DIFF | size-exact: allocation or scheduling | +007C eor r0, r0, r2 | eor r0, r2, r0 | 1.1p1 |
| ov009 | 0x021A153C | func_021A153C | 220/228 | DIFF | structure: -8 bytes | +0060 add r0, r2, r0 | add r2, r2, r0 | 1.1p1 |
| ov009 | 0x021A174C | func_021A174C | 180/184 | DIFF | structure: -4 bytes | +000C ldr r5, [sp, #0x44] | ldr r4, [sp, #0x44] | 1.1p1 |
| ov015 | 0x02179F74 | func_02179F74 | 80/80 | DIFF | size-exact: allocation or scheduling | +0024 mov r3, #0xff | mov r2, #0xff | 1.1p1 |
| ov015 | 0x0217A034 | func_0217A034 | 152/152 | DIFF | size-exact: allocation or scheduling | +0058 strb r0, [r6, #2] | strb r1, [r6, #3] | 1.1p1 |
| ov015 | 0x0217A7AC | func_0217A7AC | 328/320 | DIFF | structure: +8 bytes | +0004 ldr r2, [pc, #0x118] | ldr r2, [pc, #0x120] | 1.1p1 |
| ov016 | 0x021B87F0 | func_021B87F0 | 464/464 | DIFF | size-exact: allocation or scheduling | +00EA movs r4, r5 | lsls r6, r6, #2 | ../2.0/sp1p2 |
| ov016 | 0x021B97A8 | func_021B97A8 | 188/164 | DIFF | structure: +24 bytes | +0002 adds r6, r0, #0 | sub sp, #8 | 1.1p1 |
| ov016 | 0x021B9FE0 | func_021B9FE0 | 186/196 | DIFF | structure: -10 bytes | +0002 sub sp, #8 | adds r6, r3, #0 | ../2.0/sp1p2 |
| ov016 | 0x021BC63C | func_021BC63C | 236/232 | DIFF | structure: +4 bytes | +0006 ldr r0, [pc, #0xc8] | ldr r0, [pc, #0xcc] | ../2.0/sp1p2 |
| ov016 | 0x021BC820 | func_021BC820 | 204/204 | DIFF | size-exact: allocation or scheduling | +0000 push {r4, r5, r6, lr} | push {r3, r4, r5, r6, r7, lr} | 1.1p1 |
| ov016 | 0x021BD8D8 | DWCi_KBlInit | 876/844 | DIFF | structure: +32 bytes | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |
| ov016 | 0x021BE844 | disp | 652/656 | DIFF | structure: -4 bytes | +0004 sub sp, sp, #0x18 | sub sp, sp, #0x20 | 1.1p1 |
| ov016 | 0x021C78A0 | func_021C78A0 | 164/192 | DIFF | structure: -28 bytes | +0000 push {r4, r5, r6, r7, r8, sb, lr} | push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |
| ov016 | 0x021C84BC | initGraphics | 508/508 | DIFF | size-exact: allocation or scheduling | +0144 ldr r2, [r5, #8] | ldr r1, [r5, #8] | 1.1p1 |
| ov016 | 0x021C9A94 | isPush | 620/636 | DIFF | structure: -16 bytes | +0008 ldr r0, [pc, #0x258] | ldr r0, [pc, #0x248] | 1.1p1 |
| ov016 | 0x021CBDF8 | func_021CBDF8 | 264/264 | DIFF | size-exact: allocation or scheduling | +0050 lsl r2, r3, #2 | add r1, r1, sl, lsl #2 | 1.1p1 |
| ov016 | 0x021CC0E8 | button | 288/288 | DIFF | size-exact: allocation or scheduling | +00B8 add ip, r5, #1 | mov r2, r4 | 1.1p1 |
| ov016 | 0x021D0B44 | func_021D0B44 | 372/372 | DIFF | size-exact: allocation or scheduling | +002C ldr r3, [r5] | ldr r4, [r5] | 1.1p1 |
| ov016 | 0x021D0DE0 | func_021D0DE0 | 144/148 | DIFF | structure: -4 bytes | +0010 ldr r1, [pc, #0x78] | ldr r1, [pc, #0x74] | 1.1p1 |
| ov016 | 0x021D0E74 | func_021D0E74 | 332/344 | DIFF | structure: -12 bytes | +0004 str r0, [sp] | mov fp, r0 | 1.1p1 |
| ov016 | 0x021D15F0 | func_021D15F0 | 184/192 | DIFF | structure: -8 bytes | +0000 push {r4, r5, r6, lr} | push {r3, r4, r5, lr} | 1.1p1 |
| ov016 | 0x021D1868 | func_021D1868 | 396/396 | DIFF | size-exact: allocation or scheduling | +0128 ldr r4, [pc, #0x44] | lsl r5, r0, #2 | 1.1p1 |
| ov016 | 0x021D3638 | func_021D3638 | 120/120 | DIFF | size-exact: allocation or scheduling | +0068 moveq r0, r5 | movne r5, r4 | 1.1p1 |
| ov016 | 0x021D5A58 | func_021D5A58 | 360/360 | DIFF | size-exact: allocation or scheduling | +00AC str r5, [r5, #0x18] | add r0, r0, r4, lsl #3 | 1.1p1 |
| ov016 | 0x021D657C | func_021D657C | 280/272 | DIFF | structure: +8 bytes | +0004 ldr r0, [pc, #0xf4] | ldr r0, [pc, #0xfc] | 1.1p1 |
| ov107 | 0x021F2E58 | func_021F2E58 | 120/124 | DIFF | structure: -4 bytes | +0000 ldr r1, [pc, #0x68] | ldr r1, [pc, #0x64] | 1.1p1 |
| ov107 | 0x021F3830 | func_021F3830 | 348/348 | DIFF | size-exact: allocation or scheduling | +0028 beq #0x21f3960 | beq #0x21f395c | 1.1p1 |
| ov107 | 0x021F6658 | MBi_SetTask | 348/356 | DIFF | structure: -8 bytes | +0004 ldr r4, [pc, #0x154] | ldr r4, [pc, #0x14c] | dsi/1.1p1 |
| ov114 | 0x021BA150 | func_021BA150 | 176/164 | DIFF | structure: +12 bytes | +0008 mov r4, #0 | mov r6, #0 | - |
| ov114 | 0x021BA988 | NHTTPi_CleanupAsync | 140/140 | DIFF | size-exact: allocation or scheduling | +0064 ldr r2, [r5, #0xc] | ldr r0, [r5, #0xc] | 1.1p1 |
| ov114 | 0x021BBBC8 | func_021BBBC8 | 292/296 | DIFF | structure: -4 bytes | +0008 mov sl, r0 | mov r3, #0 | 1.1p1 |
| ov114 | 0x021BC2FC | func_021BC2FC | 132/136 | DIFF | structure: -4 bytes | +0034 beq #0x21bc378 | beq #0x21bc370 | - |
| ov114 | 0x021BC740 | func_021BC740 | 484/484 | DIFF | size-exact: allocation or scheduling | +0020 str r0, [sp, #0xc] | mov sl, r0 | 1.1p1 |
| ov114 | 0x021BD270 | func_021BD270 | 328/328 | DIFF | size-exact: allocation or scheduling | +006C ldr r2, [r4, #0xc] | ldr r0, [r4, #0xc] | - |
| ov114 | 0x021C4E7C | func_021C4E7C | 1460/1460 | MATCH | witness missing | | | 1.1p1 |
| ov114 | 0x021C60C8 | func_021C60C8 | 248/248 | DIFF | size-exact: allocation or scheduling | +0004 mov r7, r2 | mov r8, r2 | 1.1p1 |
| ov114 | 0x021C7A74 | func_021C7A74 | 208/212 | DIFF | structure: -4 bytes | +0008 ldr r4, [pc, #0xb8] | ldr r4, [pc, #0xb4] | 1.1p1 |
| ov114 | 0x021C98E0 | func_021C98E0 | 240/240 | DIFF | size-exact: allocation or scheduling | +00A8 ldrb r0, [r8, #1] | ldrb r1, [r8, #1] | 1.1p1 |
| ov114 | 0x021C9B64 | func_021C9B64 | 568/568 | DIFF | size-exact: allocation or scheduling | +0084 ldr r3, [pc, #0x19c] | ldr ip, [pc, #0x19c] | 1.1p1 |
| ov114 | 0x021CB764 | func_021CB764 | 332/332 | DIFF | size-exact: allocation or scheduling | +0004 mov r7, r1 | mov r5, r1 | 1.1p1 |
| ov114 | 0x021CC674 | func_021CC674 | 408/408 | DIFF | size-exact: allocation or scheduling | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r4, r5, r6, r7, r8, sb, sl, lr} | 1.1p1 |
| ov172 | 0x021BE468 | func_021BE468 | 348/348 | DIFF | size-exact: allocation or scheduling | +0014 mov r8, r0 | mov r6, r2 | 1.1p1 |
| ov172 | 0x021BF0B0 | func_021BF0B0 | 172/172 | DIFF | size-exact: allocation or scheduling | +0004 movs r6, r3 | movs r4, r3 | 1.1p1 |
| ov172 | 0x021C0370 | func_021C0370 | 80/80 | DIFF | size-exact: allocation or scheduling | +0010 ldrb r3, [r0, r1] | ldrb r1, [r0, r1] | 1.1p1 |
| ov172 | 0x021C0440 | GetAPP1 | 1924/1908 | DIFF | structure: +16 bytes | +0000 push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |
| ov172 | 0x021C1D8C | func_021C1D8C | 388/376 | DIFF | structure: +12 bytes | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | 1.1p1 |
| ov172 | 0x021C1F04 | func_021C1F04 | 328/332 | DIFF | structure: -4 bytes | +0000 push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} | push {r4, r5, r6, r7, r8, sb, sl, fp, lr} | dsi/1.1p1 |
| ov172 | 0x021C2050 | func_021C2050 | 96/96 | DIFF | size-exact: allocation or scheduling | +000C add r4, r3, ip, lsl #1 | add r1, r3, ip, lsl #1 | 1.1p1 |
| ov172 | 0x021C3DF4 | func_021C3DF4 | 3496/3496 | DIFF | size-exact: allocation or scheduling | +0204 ldrsh r1, [sb, #4] | ldr r1, [pc, #0xb60] | dsi/1.1p1 |
| ov175 | 0x021DF65C | func_021DF65C | 200/216 | DIFF | structure: -16 bytes | +000C ldr r1, [pc, #0xc0] | ldr r1, [pc, #0xb0] | 1.1p1 |
| ov175 | 0x021E11F0 | func_021E11F0 | 336/336 | DIFF | size-exact: allocation or scheduling | +0004 ldr r6, [pc, #0x128] | ldr r7, [pc, #0x128] | 1.1p1 |
