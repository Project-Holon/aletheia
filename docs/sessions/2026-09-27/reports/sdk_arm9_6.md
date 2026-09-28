# sdk_arm9_6 lane report (2026-09-28)

Everything here was compiled under dsi/1.1p1 with no pins. I worked only from vendor objects (sdkobj), `match.py show` and the idiom index, and did not open any file under sdk/.

**19 functions are EXACT.** Each shard was verified twice, the second pass rewrote nothing, and `manifest --check` is clean.

- MATH_QSort 02081BE4 is asm in the vendor object (clz, swp, a computed stack). I transcribed it from the image.
- MTX_Concat43 0207B9F0 and MTX_Concat33 0207B388. For Concat43, b's translation has to be added inside the 64-bit expression; the image's `adds` is the low half of that add.
- FSi_FindPathDefault 02079558 and its leaf FSi_IncrementSjisPositionToSlash 020787E0. The leaf needed the lead-byte test to take `str[pos] & 0xFF`.
- MTX_OrthoW 0207C554 and MTX_PerspectiveW 0207C408.
- GX_SetBankForBG 0207FDCC, GX_SetBankForTex 02080294, GX_SetBankForOBJ 0207FFD0 and GX_VRAMCNT_SetLCDC_ 0207FD34. Nested bank sets fall through into their subsets. In the BG function the E+G arm sits between the E chain and the F+G chain.
- The dgt_sha1.o tree: MATH_SHA1GetHash 020814C0, MATH_SHA1Update 0208142C, MATHi_SHA1Fill 0208130C, MATH_SHA1Init 020813D8, MATH_CalcSHA1 020816B8, MATHi_SetOverlayTableMode 0208139C and MATHi_SHA1ProcessBlockForOverlay 020812E0. In GetHash the footer sums put the wider shift first, and the five swaps are written out.
- MATHi_CalcHMAC 02081790. The locals are declared in the exact reverse of the sdkobj listing.

**MATCH:** src/pending/MATH_CalcHMACSHA1.c (020816FC) is byte-correct. The one wildcarded relocation is the aggregate initialiser's template (0x020A5CB8, the vendor's @12151). The `symbols:` block rejects `@N` names, so it cannot be attested. Integrator: this needs a tooling rule.

**Near miss:** src/pending/TP_CalcCalibrateParam.c (0208AF18) is 492/492 bytes with 17 bytes out, all in the y tail, where two registers are swapped (r0/r1). Permuter seed 9301 gave no improvement. The dated note is in docs/notes/pkt_0208AF18.c.txt.

**Integrator, stage:**
- the 19 src/matched files above
- their 19 shards: arm9/pkt_02081BE4, 0207B9F0, 0207B388, 020787E0, 02079558, 0207C554, 0207C408, 0207FDCC, 02080294, 0207FFD0, 0207FD34, 020814C0, 0208142C, 0208130C, 020813D8, 020816B8, 0208139C, 020812E0, 02081790
- the two pending files and the note

src/matched/MTX_Concat44.c is sdk_arm9_3's leftover and not this lane's.

**Remainder:**
- TP_CalcCalibrateParam (17 bytes).
- WmInitCore and WM_StepDataSharing: not attempted.
- Next open rows: GX_LoadTex 0207F7FC, SND_GetNextInstData 0208A48C, FSi_NextCommand 02077AD8, SND_FlushCommand 02089B38, CARDi_RequestStreamCommandCore 02076540, FX_Atan2Idx 0207CFB8, CARDi_ReadRom 020771B4, GX_Init 0207D204, WMi_StartMP 0208FA28, FS_LoadOverlayInfo 02078D34, MTX_RotAxis33 0207AF50, then the rest of fs_proc_default.o.

Seeds: none. MATHi_SHA1ProcessBlock 02081E7C already carries the label func_02081E7C.
