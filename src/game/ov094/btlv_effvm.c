/*
 * file:     btlv_effvm.c
 * unit:     yes
 * function: func_021F6560, func_021F6898, func_021F6934, func_021F69B0, func_021F69E8, func_021F6A18, func_021F6A28, func_021F6AA8, func_021F6AD0, func_021F6B04, func_021F6CF0, func_021F6D5C, func_021F6DD4, func_021F6DEC, func_021F6E1C, func_021F6E2C, func_021F6E3C, func_021F6EC0, func_021F6ED4, func_021F6EDC, func_021F6F20, func_021F6F48, func_021F7000, func_021F70F0, func_021F7108, func_021F7208, func_021F722C, func_021F723C, func_021F73A4, func_021F73F0, func_021F745C, func_021F7544, func_021F7808, func_021F78E4, func_021F7998, func_021F7A28, func_021F7AAC, func_021F7B2C, func_021F7BEC, func_021F7C0C, func_021F7C2C, func_021F7CE4, func_021F7CFC, func_021F7D44, func_021F7D80, func_021F7E38, func_021F7E74, func_021F7E84, func_021F7E94, func_021F7EA4, func_021F7EB4, func_021F7EE8, func_021F7F04, func_021F7F1C, func_021F7F58, func_021F8010, func_021F803C, func_021F8090, func_021F80E4, func_021F80FC, func_021F8118, func_021F8134, func_021F8150, func_021F8168, func_021F8180, func_021F8198, func_021F81B4, func_021F81D0, func_021F81EC, func_021F8204, func_021F821C, func_021F823C, func_021F8260, func_021F827C, func_021F8298, func_021F8324, func_021F839C, func_021F8414, func_021F84B4, func_021F84D0, func_021F84E8, func_021F8504, func_021F8524, func_021F853C, func_021F8554, func_021F8628, func_021F8678, func_021F8684, func_021F8694, func_021F86A4, func_021F86B4, func_021F86C4, func_021F86D4, func_021F86E0, func_021F86F0, func_021F8700, func_021F8710, func_021F8720, func_021F8730, func_021F8740, func_021F8754, func_021F8764, func_021F8774, func_021F878C, func_021F87D4, func_021F87EC, func_021F882C, func_021F883C, func_021F8884, func_021F88A8, func_021F88BC, func_021F88E0, func_021F88F4, func_021F8914, func_021F8934, func_021F896C, func_021F899C, func_021F89BC, func_021F8A10, func_021F8A40, func_021F8A78, func_021F8AC0, func_021F8AE8, func_021F8AFC, func_021F8B10, func_021F8B28, func_021F8B40, func_021F8B6C, func_021F8B90, func_021F8BAC, func_021F8C78, func_021F8CB0, func_021F8EF8, func_021F8F30, func_021F8FB0, func_021F8FE8, func_021F9028, func_021F903C, func_021F9154, func_021F918C, func_021F9220, func_021F9260, func_021F935C, func_021F9364, func_021F93F4, func_021F9478, func_021F94D8, func_021F94F8, func_021F97E4, func_021F9814, func_021F9824, func_021F9844, func_021F9858, func_021F9948, func_021F9A7C, func_021F9AA4, func_021F9AB8, func_021F9EFC, func_021F9FC0, func_021FA048, func_021FA09C, func_021FA108, func_021FA12C, func_021FA288, func_021FA358, func_021FA458, func_021FA5D0, func_021FA758, func_021FA794, func_021FA884, func_021FA988, func_021FAB0C, func_021FAC94, func_021FACA0, func_021FACAC, func_021FAD2C, func_021FADC0, func_021FAE48, func_021FAECC, func_021FAF44, func_021FAFBC, func_021FB034, func_021FB09C, func_021FB0E8, func_021FB168, func_021FB1C4, func_021FB214, func_021FB298, func_021FB2D0, func_021FB328, func_021FB390, func_021FB3C8, func_021FB3DC, func_021FB49C, func_021FB500, func_021FB524, func_021FB550, func_021FB574, func_021FB5D4, func_021FB624, func_021FB648, func_021FB6F4, func_021FB790, func_021FB7F8, func_021FB864, func_021FB894, func_021FB8F4, func_021FB91C, func_021FBA64, func_021FBAD8, func_021FBAF8, func_021FBC78, func_021FBCEC, func_021FBD10, func_021FBD34, func_021FBD44, func_021FBD88, func_021FBDD4, func_021FBE28, func_021FBE60, func_021FBE74, func_021FBE90, func_021FBF48, func_021FBFA0, func_021FBFC0, func_021FC134, func_021FC148, func_021FC20C, func_021FC2DC, func_021FC334, func_021FC354, func_021FC374, func_021FC3D8, func_021FC434, func_021FC448, func_021FC744, func_021FC9D0, func_021FC9E4, func_021FC9F4, func_021FCA04, func_021FCD14, func_021FCF2C, func_021FD04C, func_021FD070, func_021FD088, func_021FD15C, func_021FD19C, func_021FD1A8, func_021FD1C0, func_021FD1CC, func_021FD8CC, func_021FD9F0, func_021FDA28, func_021FDB08, func_021FDB20, func_021FDB40, func_021FDBB0, func_021FDD60, func_021FDFA0, func_021FE1B8, func_021FE254, func_021FE38C, func_021FE410, func_021FE4D0, func_021FE4F8, func_021FE520, func_021FE54C, func_021FE580, func_021FE594, func_021FE690, func_021FE6A4, func_021FE750, func_021FE768, func_021FE79C, func_021FE8AC, func_021FE8D8, func_021FE930, func_021FE9BC, func_021FE9F0, func_021FEAA0, func_021FEAC0, func_021FEB78, func_021FEBAC, func_021FEE9C, func_021FEEA8, func_021FF088, func_021FF0F8, func_021FF134, func_021FF144, func_021FF16C, func_021FF1B0, func_021FF1F4, func_021FF228, func_021FF260, func_021FF2D8, func_021FF304, func_021FF348, func_021FF374, func_021FF3F4, func_021FF3FC, func_021FF468, func_021FF470, func_021FF498, func_021FF4C0, func_021FF5B0, func_021FF630, func_021FF6B0, func_021FF730, func_021FF7B0, func_021FF870, func_021FF924, func_021FFA18, func_021FFB04, func_021FFBBC, func_021FFCB0, func_021FFD6C, func_021FFD9C, func_021FFDB4, func_021FFDF8, func_021FFE24, func_021FFE48, func_021FFF0C, func_021FFF38, func_021FFF68, func_021FFFAC, func_021FFFD8, func_02200108, func_02200140, func_022001DC, func_02200218, func_02200344, func_022003C4, func_022003EC, func_0220041C, func_02200468, func_02200494, func_022004BC, func_0220055C, func_022005C4, func_02200608, func_02200654, func_022006A0, func_022006B4, func_0220074C, func_02200904, func_02200990, func_022009C8, func_02200A50, func_02200A84, func_02200B10, func_02200B48, func_02200BD4, func_02200C0C, func_02200C98, func_02200CD0, func_02200D30, func_02200D68, func_02200DE4, func_02200E1C, func_02201098, func_022010D0, func_022011FC, func_02201234, func_022012CC, func_02201304, func_02201408, func_02201700, func_02201718, func_02201810, func_02201894, func_022018A8, func_02201934, func_022019F4, func_02201A20, func_02201A8C, func_02201AC4, func_02201AF0, func_02201AF8, func_02201B20, func_02201CA4, func_02201CD0, func_02201D5C, func_02201DA0, func_02201DB4, func_02201E04, func_02201F98, func_02201FD8, func_02201FF4, func_0220203C, func_02202058, func_0220207C, func_022020A0, func_022021F4, func_02202228, func_02202238, func_02202248, func_022023D0, func_0220255C, func_022025B4, func_022025D8, func_0220266C, func_022026FC, func_0220270C, func_02202DC4, func_02203040, func_022030F0, func_022033CC, func_022033F0, func_022033F4, func_022035C0, func_022036C4, func_02203880, func_02203978, func_02203A78, func_02203B08, func_02203BC0, func_02203C2C, func_02203D40, func_02203E30, func_02203FDC, func_022040FC, func_022041E0, func_022042E4, func_022043AC, func_022043C0, func_02204438, func_022044A0, func_022044C0, func_0220453C, func_02204588, func_022045A8, func_0220461C, func_02204678, func_02204698, func_022047CC, func_022047F8, func_02204838, func_022048A4, func_02204940, func_02204960, func_022049C8, func_02204A3C, func_02204A70, func_02204A88, func_02204AEC, func_02204B0C, func_02204BAC, func_02204BCC, func_02204C48, func_02204C98, func_02204CC0, func_022050F0, func_02205340, func_022053DC, func_0220558C, func_022056B4, func_02205768, func_022057CC, func_02205AB8, func_02205B80, func_02205B90, func_02205D34, func_02205D58, func_02205E30, func_02205E80, func_02205F40, func_02205F64, func_02205F88, func_02206128, func_02206140, func_0220648C, func_022064CC, func_02206578, func_0220663C, func_02206710, func_02206728, func_022067E8, func_0220680C, func_0220684C, func_02206864, func_0220687C, func_022068C4, func_022068E8, func_02206908, func_02206950, func_02206A14, func_02206A58, func_02206A7C, func_02206AF8, func_02206B14, func_02206B30, func_02206B58, func_02206B74, func_02206B90, func_02206BAC, func_02206BC8, func_02206E28, func_02206EB4, func_022070C0, func_02207288, func_02207430, func_0220778C, func_0220785C, func_0220793C, func_02207960
 * address:  0x021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   sub_020307B0 0x020307B0 arm
 *   d_0220AC40 0x0220AC40 data
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_0220AC50 0x0220AC50 data ov094 a1
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   d_0220AC60     0x0220AC60  data   ov094  a1
 *   d_02209CF4     0x02209CF4  data   ov094
 *   d_02209D00     0x02209D00  data   ov094
 *   d_02209CE8     0x02209CE8  data   ov094
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B44  0x02048B44  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207C768  0x0207C768  arm
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 *   _ll_mul 0x0209C054 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   d_0220AC90     0x0220AC90  data   ov094  a1
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   func_021B8FE4 0x021B8FE4 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9000 0x021B9000 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetFieldSituation 0x021B8714 thumb ov093
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_0220AF20     0x0220AF20  data   a4
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_0201493C  0x0201493C  thumb
 *   G3D_SYSTEM_SetLight  0x02046A94  arm
 *   func_02209224  0x02209224  thumb  ov094
 *   func_0220975C  0x0220975C  thumb  ov094
 *   PARTICLE_InitManager  0x02050B80  arm
 *   func_020056A0  0x020056A0  thumb
 *   PM_VOICE_AllocBuffers  0x02006674  thumb
 *   PM_VOICE_FreeBuffers 0x020066E8 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_022092E8 0x022092E8 thumb ov094
 *   func_0220977C 0x0220977C thumb ov094
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28  0x02030D28  arm
 *   func_02047964  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   PARTICLE_Main  0x02050BE8  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   func_02030DA8  0x02030DA8  arm
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   d_02209D0C     0x02209D0C  data   ov094  a1
 *   func_02207B4C  0x02207B4C  thumb  ov094
 *   func_02207B68  0x02207B68  thumb  ov094
 *   func_02207B84 0x02207B84 thumb ov094
 *   func_02207BAC 0x02207BAC thumb ov094
 *   func_022089AC 0x022089AC thumb ov094
 *   func_02207C94 0x02207C94 thumb ov094
 *   func_02207CC4 0x02207CC4 thumb ov094
 *   func_02207D04  0x02207D04  thumb  ov094
 *   func_02208814  0x02208814  thumb  ov094
 *   func_02208870 0x02208870 thumb ov094
 *   func_02207D60 0x02207D60 thumb ov094
 *   func_02208958 0x02208958 thumb ov094
 *   func_02208DAC  0x02208DAC  thumb  ov094
 *   func_02209068 0x02209068 thumb ov094
 *   func_022090A4 0x022090A4 thumb ov094
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   func_02040588  0x02040588  arm
 *   func_02209318 0x02209318 thumb ov094
 *   func_022094BC  0x022094BC  thumb  ov094
 *   func_02209500  0x02209500  thumb ov094
 *   g_0220AF20  0x0220AF20  data
 *   func_022088F4 0x022088F4 thumb ov094
 *   func_02208900  0x02208900  thumb  ov094
 *   func_0220893C  0x0220893C  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_02208918  0x02208918  thumb  ov094
 *   func_02208924  0x02208924  thumb  ov094
 *   func_021BA1EC 0x021BA1EC thumb ov093
 *   func_021BA20C 0x021BA20C thumb ov093
 *   sub_02030EAC   0x02030EAC  arm
 *   TCBL_IsDeletePending   0x02030EE8  arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   TCBL_IsDeletePending 0x02030EE8 arm
 *   d_0220AC70 0x0220AC70 data a4
 *   d_0220AC78 0x0220AC78 data a4
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   sub_0207C768  0x0207C768  arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   func_02061CA4  0x02061CA4  arm
 *   d_0220AE68     0x0220AE68  data   ov094  a1
 *   d_02209DCC     0x02209DCC  data   ov094  a4
 *   func_02030734  0x02030734  arm
 *   VM_Create  0x0201121C  thumb
 *   VM_Init  0x0201126C  thumb
 *   VM_Control  0x02011298  thumb
 *   func_02011324  0x02011324  thumb
 *   VM_Delete 0x02011264 thumb
 *   VM_Start  0x0201127C  thumb
 *   func_02082A48  0x02082A48  arm
 *   PM_VOICE_StopSlot 0x02006BB4 thumb
 *   VM_GetU32  0x0201134C  thumb
 *   d_0220ACA0  0x0220ACA0  data  a4
 *   d_0220ACE8  0x0220ACE8  data  a4
 *   d_0220AD00  0x0220AD00  data  a4
 *   d_0220AD78  0x0220AD78  data  a4
 *   d_0220ADA8  0x0220ADA8  data  a4
 *   d_0220ADD8  0x0220ADD8  data  a4
 *   d_0220AE20  0x0220AE20  data  a4
 *   func_0207C9D0  0x0207C9D0  arm
 *   VM_SetWait 0x020113D0 thumb
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_CreateSystem 0x02050C30 arm
 *   PARTICLE_SetupSystemNoHandlers 0x02051380 arm
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   BUTTON_MAN_GetBlock 0x02051788 arm
 *   d_02209E1C 0x02209E1C data a4
 *   d_02209D90 0x02209D90 data a4
 *   d_02209D78 0x02209D78 data a4
 *   d_02209E04 0x02209E04 data a4
 *   d_02209DC0 0x02209DC0 data ov094 a4
 *   d_02209D84 0x02209D84 data ov094 a4
 *   d_02209DA8 0x02209DA8 data ov094 a4
 *   d_02209D9C 0x02209D9C data ov094 a4
 *   func_0204047C  0x0204047C  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   func_02209784  0x02209784  thumb  ov094
 *   func_022097CC  0x022097CC  thumb  ov094
 *   func_0207D63C  0x0207D63C  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_022079C0  0x022079C0  thumb  ov094
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   func_020061F8 0x020061F8 thumb
 *   VM_Jump  0x020113B0  thumb
 *   PALANM_GetPairedCodeForFirst  0x0202142C  thumb
 *   VM_Call 0x020113B4 thumb
 *   VM_Return  0x020113C4  thumb
 *   func_02011290 0x02011290 thumb
 *   BTLV_SCU_ReloadGraphics 0x021EB2A8 thumb ov093
 *   func_02040618 0x02040618 arm
 *   func_0220985C 0x0220985C thumb ov094
 *   PARTICLE_GetEffectCount 0x02051614 arm
 *   func_02006238 0x02006238 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   func_02006BD0 0x02006BD0 thumb
 *   d_02209E58 0x02209E58 data a4
 *   d_02209E28 0x02209E28 data ov094 a4
 *   d_0220AD18 0x0220AD18 data ov094 a4
 *   d_0220AD38 0x0220AD38 data ov094 a4
 *   d_0220AD58     0x0220AD58  data   ov094
 *   func_02051774 0x02051774 arm
 *   BUTTON_MAN_SetUserData 0x02051A2C arm
 *   BUTTON_MAN_SetCallback 0x02051A24 arm
 *   func_0207CF3C 0x0207CF3C arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   func_0207CA68 0x0207CA68 arm
 *   FX_AcosIdx 0x0207D184 arm
 *   func_0207CAE8 0x0207CAE8 arm
 *   MTX_RotAxis43 0x0207B65C arm
 *   MTX_MultVec43 0x0207BC08 arm
 *   BUTTON_MAN_SetRow2 0x020519C4 arm
 *   BUTTON_MAN_SetRow5 0x02051A04 arm
 *   BUTTON_MAN_GetRot 0x020517B4 arm
 *   BUTTON_MAN_SetRow3Half 0x020519E4 arm
 *   BUTTON_MAN_SetRot 0x02051880 arm
 *   BUTTON_MAN_GetScaleX 0x020517D0 arm
 *   BUTTON_MAN_GetAlpha 0x02051830 arm
 *   BUTTON_MAN_GetAngle 0x02051820 arm
 *   BUTTON_MAN_GetScaleY 0x020517E0 arm
 *   BUTTON_MAN_SetScaleX 0x020517D8 arm
 *   BUTTON_MAN_SetScaleY 0x020517E8 arm
 *   BUTTON_MAN_SetAlpha 0x020518A4 arm
 *   BUTTON_MAN_SetAngle 0x0205189C arm
 *   BUTTON_MAN_GetPos 0x02051790 arm
 *   BUTTON_MAN_SetPos 0x020517A4 arm
 *   BUTTON_MAN_GetOffsetX 0x020517F0 arm
 *   BUTTON_MAN_SetOffsetX 0x02051800 arm
 *   BUTTON_MAN_GetOffsetY 0x02051808 arm
 *   BUTTON_MAN_SetOffsetY 0x02051818 arm
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   BUTTON_MAN_GetUserData  0x02051A34  arm
 *   PARTICLE_GetWorkBase  0x02051640  arm
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   GFL_USE_GetSeHandle  0x02006138  thumb
 *   GFL_USE_SetSeSlotParams  0x02006268  thumb
 *   NNS_SndHandleSetSeqPriority  0x02072F34  arm
 *   NNS_SndHandleSetTrackModDepth  0x02073058  arm
 *   NNS_SndHandleSetTrackModSpeed  0x02073078  arm
 *   _s32_div_f 0x0209C0A4 arm
 *   d_02209E10 0x02209E10 data
 *   d_02209DB4 0x02209DB4 data
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   FX_Div           0x0207C768  arm
 *   g_renderStateDrawParams       0x02148B98  data
 *   SCREENTEX_ProjectionMatrix       0x02148B54  data
 *   func_0200F698  0x0200F698  thumb
 *   PARTICLE_ApplyLoadHandlers  0x02051394  arm
 *   d_02209DD8  0x02209DD8  data  ov094
 *   MCSS_Init  0x02014B08  thumb
 *   MCSS_SetSysParam  0x020163B0  thumb
 *   MCSS_SetSysFlag  0x020163B4  thumb
 *   d_0220AE7C     0x0220AE7C  data   ov094
 *   MCSS_Exit  0x02014BA8  thumb
 *   MCSS_RestartAnime 0x02016374 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw  0x02014D2C  thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_0202D034 0x0202D034 thumb
 *   MCSS_Add 0x020159C8 thumb
 *   MCSS_SetShadowAlpha 0x02015FD4 thumb
 *   MCSS_SetShadowOffset 0x02015D94 thumb
 *   MCSS_SetShadowRotateZ 0x02015D88 thumb
 *   func_02015F2C 0x02015F2C thumb
 *   MCSS_Del  0x02015BA4  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_SetOrthoMode   0x02015BF0  thumb
 *   MCSS_ResetOrthoMode   0x02015C00  thumb
 *   MCSS_SetOrthoBillboardFlag  0x02015C0C  thumb
 *   MCSS_ResetOrthoBillboardFlag  0x02015C1C  thumb
 *   MCSS_SetMepachiFlag  0x02015DB0  thumb
 *   MCSS_ResetMepachiFlag  0x02015DC0  thumb
 *   MCSS_FlipMepachiFlag  0x02015DD4  thumb
 *   MCSS_GetAnmStopFlag  0x02015DF8  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetAnmStopFlagAlways  0x02015E28  thumb
 *   MCSS_ResetAnmStopFlagAlways  0x02015E70  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   MCSS_GetVanishFlag  0x02015E94  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_FlipVanishFlag  0x02015EC4  thumb
 *   d_0220A050  0x0220A050  data  ov094
 *   d_0220A080  0x0220A080  data  ov094
 *   d_0220A158  0x0220A158  data  ov094
 *   d_0220A1A0  0x0220A1A0  data  ov094
 *   MCSS_SetShadowVanishFlag  0x02015FF0  thumb
 *   MCSS_SetAnimeSpeed  0x020160C4  thumb
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_GetShadowScale  0x02015CC4  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_GetRotate  0x02015CF8  thumb
 *   func_022089BC  0x022089BC  thumb  ov094
 *   MCSS_GetAlpha 0x02015FAC thumb
 *   MCSS_GetMosaic 0x02016068 thumb
 *   MCSS_CheckPaletteFade  0x0201600C  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_CreatePaletteTransTask  0x020160D4  thumb
 *   MCSS_CreatePaletteCopyTask  0x0201624C  thumb
 *   MCSS_GetStopCellFlags  0x02015F24  thumb
 *   MCSS_TOOL_SetSpindaSpotHook 0x020172AC thumb
 *   MCSS_ReloadResource 0x02014CF8 thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   MCSS_SetMosaic  0x02016078  thumb
 *   MCSS_ReloadResource   0x02014CF8  thumb
 *   func_021B994C  0x021B994C  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   PM_VOICE_AddVolume  0x02006A8C  thumb
 *   PM_VOICE_AddFrequency  0x02006AEC  thumb
 *   d_02209FC0  0x02209FC0  data  ov094
 *   d_02209FE0  0x02209FE0  data  ov094
 *   d_02209FF0  0x02209FF0  data  ov094
 *   d_0220A068  0x0220A068  data  ov094
 *   MCSS_TOOL_MakeAddWorkFromPP  0x02017100  thumb
 *   MCSS_GetAnimSeqNumEx  0x020160CC  thumb
 *   MCSS_SetAnimeIndex   0x02016028  thumb
 *   MCSS_GetOfsPosition  0x02015C60  thumb
 *   MCSS_SetOfsPosition  0x02015C78  thumb
 *   MCSS_SetWorkFlag  0x02016394  thumb
 *   MCSS_TOOL_MakeAddWorkFromTrainer  0x02017214  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   MCSS_SetOfsScale  0x02015D30  thumb
 *   MCSS_SetShadowScale  0x02015CDC  thumb
 *   MCSS_GetDrawScale  0x02015D4C  thumb
 *   MCSS_SetDrawScale  0x02015D64  thumb
 *   MCSS_SetRotate  0x02015D14  thumb
 *   MCSS_SetAlpha  0x02015FBC  thumb
 *   _fdiv 0x0209CE10 arm
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   MCSS_SetCellCallback 0x02015F40 thumb
 *   d_0220AE78 0x0220AE78 data a4
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   d_0220A0C8     0x0220A0C8  data
 *   d_0220A0B0     0x0220A0B0  data
 *   d_0220A0E0     0x0220A0E0  data
 *   MCSS_GetStopCellNum 0x02015EF4 thumb
 *   MCSS_GetAnimSeqNum 0x02015EEC thumb
 *   MCSS_GetStopCellIndex  0x02015EFC  thumb
 *   d_0220A110  0x0220A110  data  ov094
 *   d_02209FC8  0x02209FC8  data  ov094
 *   d_02209FD0  0x02209FD0  data  ov094
 *   d_0220A008  0x0220A008  data  ov094
 *   d_0220A020  0x0220A020  data  ov094
 *   d_0220A038  0x0220A038  data  ov094
 *   d_0220A1E8  0x0220A1E8  data  ov094
 *   d_0220A1EA  0x0220A1EA  data  ov094
 *   d_0220A1EC  0x0220A1EC  data  ov094
 *   d_0220A1EE  0x0220A1EE  data  ov094
 *   d_0220AE88  0x0220AE88  data  a4
 *   CLACT_DrawSystem  0x0204A600  arm
 *   d_0220A368 0x0220A368 data a4
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   func_0204B92C 0x0204B92C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   CLACT_SetActorScale  0x0204B5AC  arm
 *   d_0220AEB0  0x0220AEB0  data  a4
 *   func_02209B30  0x02209B30  thumb  ov094
 *   func_0203FC6C 0x0203FC6C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   INFOWIN_Init 0x02024A20 thumb
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   d_0220A3D4 0x0220A3D4 data ov094 a4
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_020452E8 0x020452E8 arm
 *   INFOWIN_Exit 0x02024DCC thumb
 *   d_0220A8BC  0x0220A8BC  data  a4
 *   PALANM_RequestFadeOverwrite  0x02021848  thumb
 *   CLACT_GetUnitDrawEnable  0x0204B248  arm
 *   func_0204B22C  0x0204B22C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   func_0203630C  0x0203630C  arm
 *   d_0689E090     0x0689E090  data   ov095
 *   d_0689E0B0     0x0689E0B0  data   ov095
 *   d_0689E560     0x0689E560  data   ov095
 *   d_0689E704     0x0689E704  data   ov095
 *   d_0220A598     0x0220A598  data   a4
 *   func_02209A7C  0x02209A7C  thumb  ov094
 *   func_02209B60  0x02209B60  thumb  ov094
 *   func_02209C2C  0x02209C2C  thumb  ov094
 *   sec_0220A380   0x0220A380  data
 *   d_0220A380     0x0220A380  data
 *   d_0220AE98     0x0220AE98  data
 *   d_0220AEA4     0x0220AEA4  data
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   func_02082A60 0x02082A60 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_020275F8 0x020275F8 thumb
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 *   func_0207AD58  0x0207AD58  thumb
 *   func_02040820  0x02040820  arm
 *   d_0220A46C     0x0220A46C  data  ov094  a4
 *   d_0220A53C  0x0220A53C  data  a4
 *   d_0220A85C  0x0220A85C  data  a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   d_0220A3B4     0x0220A3B4  data   ov094  a4
 *   d_0220A38C     0x0220A38C  data   ov094  a1
 *   d_0220A3E4     0x0220A3E4  data   ov094  a4
 *   func_0207D658  0x0207D658  arm
 *   d_0220A5B0  0x0220A5B0  data
 *   d_0220A5D0  0x0220A5D0  data
 *   d_0220A5F0  0x0220A5F0  data
 *   d_0220A392  0x0220A392  data
 *   d_0220A3C4  0x0220A3C4  data
 *   d_0220A4AC  0x0220A4AC  data
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02049F34  0x02049F34  arm
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   d_0220A7FC     0x0220A7FC  data
 *   d_0220A94C     0x0220A94C  data
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   func_021D5528 0x021D5528 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   d_0220A386 0x0220A386 data a1
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02041300  0x02041300  arm
 *   d_0220A50C 0x0220A50C data a4
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   d_0220A558 0x0220A558 data ov094 a4
 *   d_0220A56C 0x0220A56C data ov094 a4
 *   d_0220A544 0x0220A544 data ov094 a4
 *   d_0220A580     0x0220A580  data   ov094  a4
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0203633C  0x0203633C  arm
 *   func_02207D78  0x02207D78  thumb  ov094
 *   func_020276B8 0x020276B8 thumb
 *   func_020276BC 0x020276BC thumb
 *   func_020276C0 0x020276C0 thumb
 *   func_020276B4 0x020276B4 thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   func_02049E74 0x02049E74 arm
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   func_02208BFC 0x02208BFC thumb ov094
 *   d_0220AEC0 0x0220AEC0 data a1
 *   d_0220AABC 0x0220AABC data a2
 *   func_02208D24  0x02208D24  thumb  ov094
 *   func_02208D50 0x02208D50 thumb ov094
 *   func_02207F6C 0x02207F6C thumb ov094
 *   func_022082FC 0x022082FC thumb ov094
 *   func_02207E1C 0x02207E1C thumb ov094
 *   func_02207EF0 0x02207EF0 thumb ov094
 *   func_022086F8 0x022086F8 thumb ov094
 *   func_022087C4 0x022087C4 thumb ov094
 *   func_022089D4 0x022089D4 thumb ov094
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   func_02018584 0x02018584 thumb
 *   BTL_MAIN_CheckZukanSeen 0x021B8724 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   BTL_POKEPARAM_GetSickContRaw 0x021D6314 thumb ov093
 *   BTLV_CORE_IsSlotKind1Index15 0x021E8A78 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   func_0200CED4 0x0200CED4 thumb
 *   POKE_TOOL_GetStatusCondition 0x02017F90 thumb
 *   d_0220AAC8 0x0220AAC8 data
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   func_022080F4 0x022080F4 thumb ov094
 *   func_02208268 0x02208268 thumb ov094
 *   func_02208420 0x02208420 thumb ov094
 *   func_02208550 0x02208550 thumb ov094
 *   func_02208650 0x02208650 thumb ov094
 *   func_02208B10 0x02208B10 thumb ov094
 *   func_02208D38 0x02208D38 thumb ov094
 *   d_0220AAB4     0x0220AAB4  data   ov094  a2
 *   CLACT_GetActorImageProxy  0x0204B7C8  arm  arm9
 *   INFOWIN_Update  0x02024ABC  thumb  arm9
 *   BMP_Create  0x02043678  arm  arm9
 *   BMP_Delete  0x020437AC  arm  arm9
 *   BMP_GetPixels  0x020437D4  arm  arm9
 *   MSGDATA_Delete  0x02045C04  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   FADE_Start  0x0204E720  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 */
#include "../../matched/include/Obj18549.h"
#include "../../matched/include/Obj18551.h"
#include "../../matched/include/Obj18557.h"
#include "../../matched/include/Obj10136.h"
#include "../../matched/include/Obj21656.h"
#include "../../matched/include/Obj13584.h"
#include "../../matched/include/Obj12208.h"
#include "../../matched/include/Obj00325.h"
#include "../../matched/include/Obj00177.h"
#include "../../matched/include/Obj13586.h"
#include "../../matched/include/Obj21660.h"
#include "../../matched/include/Obj21661.h"
#include "../../matched/include/Obj21662.h"
#include "../../matched/include/Obj04398.h"
#include "../../matched/include/Obj21663.h"
#include "../../matched/include/Obj21664.h"
#include "../../matched/include/Obj21665.h"
#include "../../matched/include/Obj13587.h"
#include "../../matched/include/Obj13588.h"
#include "../../matched/include/Obj21666.h"
#include "../../matched/include/Obj21667.h"
#include "../../matched/include/Obj07879.h"
#include "../../matched/include/Obj21668.h"
#include "../../matched/include/Obj21669.h"
#include "../../matched/include/Obj21670.h"
#include "../../matched/include/Obj13589.h"
#include "../../matched/include/Obj21671.h"
#include "../../matched/include/Obj21673.h"
#include "../../matched/include/Obj07880.h"
#include "../../matched/include/Obj13592.h"
#include "../../matched/include/Obj13593.h"
#include "../../matched/include/Obj21675.h"
#include "../../matched/include/Obj21678.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj21679.h"
#include "../../matched/include/Obj13594.h"
#include "../../matched/include/Obj13595.h"
#include "../../matched/include/Obj21680.h"
#include "../../matched/include/Obj09236.h"
#include "../../matched/include/Obj13596.h"
#include "../../matched/include/Obj21682.h"
#include "../../matched/include/Obj13597.h"
#include "../../matched/include/Obj03713.h"
#include "../../matched/include/Obj21683.h"
#include "../../matched/include/Obj21684.h"
#include "../../matched/include/Obj13598.h"
#include "../../matched/include/Obj21685.h"
#include "../../matched/include/Obj18571.h"
#include "../../matched/include/Obj07881.h"
#include "../../matched/include/Obj13601.h"
#include "../../matched/include/Obj21693.h"
#include "../../matched/include/Obj13604.h"
#include "../../matched/include/Obj12218.h"
#include "../../matched/include/Obj12219.h"
#include "../../matched/include/Obj12220.h"
#include "../../matched/include/Obj06309.h"
#include "../../matched/include/Obj12223.h"
#include "../../matched/include/Obj12224.h"
#include "../../matched/include/Obj01047.h"
#include "../../matched/include/Obj12226.h"
#include "../../matched/include/Obj12228.h"
#include "../../matched/include/Obj06316.h"
#include "../../matched/include/Obj00264.h"
#include "../../matched/include/Obj06318.h"
#include "../../matched/include/Obj02439.h"
#include "../../matched/include/Obj06319.h"
#include "../../matched/include/Obj05243.h"
#include "../../matched/include/Obj21725.h"
#include "../../matched/include/Obj21726.h"
#include "../../matched/include/Obj21727.h"
#include "../../matched/include/Obj21729.h"
#include "../../matched/include/Obj13608.h"
#include "../../matched/include/Obj12236.h"
#include "../../matched/include/Obj03216.h"
#include "../../matched/include/Obj07895.h"
#include "../../matched/include/Obj21735.h"
#include "../../matched/include/Obj21736.h"
#include "../../matched/include/Obj00083.h"
#include "../../matched/include/Obj01049.h"
#include "../../matched/include/Obj03718.h"
#include "../../matched/include/Obj21763.h"
#include "../../matched/include/Obj21770.h"
#include "../../matched/include/Obj21781.h"
#include "../../matched/include/Obj21782.h"
#include "../../matched/include/Obj01909.h"
#include "../../matched/include/Obj00168.h"
#include "../../matched/include/Obj02440.h"
#include "../../matched/include/Obj21785.h"
#include "../../matched/include/Obj00896.h"
#include "../../matched/include/Obj06327.h"
#include "../../matched/include/Obj21787.h"
#include "../../matched/include/Obj01384.h"
#include "../../matched/include/Obj10158.h"
#include "../../matched/include/Obj00823.h"
#include "../../matched/include/Obj21789.h"
#include "../../matched/include/Obj21791.h"
#include "../../matched/include/Obj21793.h"
#include "../../matched/include/Obj21794.h"
#include "../../matched/include/Obj21796.h"
#include "../../matched/include/Obj21798.h"
#include "../../matched/include/Obj05249.h"
#include "../../matched/include/Obj21799.h"
#include "../../matched/include/Obj21800.h"
#include "../../matched/include/Obj10159.h"
#include "../../matched/include/Obj18616.h"
#include "../../matched/include/Obj04404.h"
#include "../../matched/include/Obj21803.h"
#include "../../matched/include/Obj06328.h"
#include "../../matched/include/Obj13619.h"
#include "../../matched/include/Obj21804.h"
#include "../../matched/include/Obj00380.h"
#include "../../matched/include/Obj00974.h"

#define REG_04000604 (*(volatile u16 *)0x04000604)
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
#define REG16(a) (*(volatile u16 *)(a))
#define REG32(a) (*(volatile unsigned int *)(a))
#define FIX(x) ((int)(((x) > 0.0f) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
#define DROP_ID(k, f) if (*(int *)(p + (k)) != -1) { f(*(int *)(p + (k))); *(int *)(p + (k)) = -1; }
#define DROP_ZERO_ID(k, f) if (*(int *)(p + (k)) != 0) { f((struct Bank *)*(int *)(p + (k))); *(int *)(p + (k)) = 0; }
#define DROP_PTR(k, f) if (*(void **)(p + (k)) != 0) { f(*(void **)(p + (k))); *(void **)(p + (k)) = 0; }
#define S_INT(o) (*(int *)(s + (o)))
#define S_PTR(o) (*(void **)(s + (o)))
#define F68_(s) (*(F68 *)((s) + 0x68))
#define F6C_(s) (*(F6C *)((s) + 0x6c))
#define HEAP(s) ((u16)((*(u16 *)((s) + 0x240) & 0x7fff) | 0x8000))
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_G2S_DB_WININ   (*(volatile u16 *)0x04001048)
#define reg_G2S_DB_WINOUT  (*(volatile u16 *)0x0400104A)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
#define INDEX (((Flags_02201B20 *)m)->index)
#define OBJECT (*(u8 **)(m + INDEX * 4 + 0x2a4))
struct G3dOwner;
struct G3dRec;
struct Tagged;
struct G3dSys;
struct Rec_v6560;
struct Arg_v6560;
struct Light;
struct Ctx;
struct Res;
struct Obj02021EE4;
struct PalAnmSlot;
struct Node;
struct W;
struct O;
struct S02030EE8;
struct S02021D50;
struct ScriptVm;
struct ScriptVmParams;
struct Cursor;
struct Dst648;
struct Src648;
struct Cur;
struct Ring;
struct Obj_vD04C;
struct S12;
struct Vec3;
struct McssSys;
struct Obj_vE254;
struct Rec_vE254;
struct Sub150;
struct McssFade;
struct Sub02014CF8Ctx;
struct Sub02014CF8Rec;
struct Stats;
struct Bank;
struct Obj;
struct Actor;
struct PtS;
struct Obj_02201DA0;
struct Vec2;
struct Pair_02201B20;
struct MsgBank;
struct Rec;
struct BgVramReq;
struct Main;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct BgTemplate;
struct Info;
struct Out;
struct Slots;
struct U16Vec;
struct Work_02201B20;
struct R5;
struct Obj_02203E30;
struct Ctx_v3E30;
struct StrObj;
struct WordSet;
struct Struct36;
struct QG;
struct Ctx_v53DC;
struct Bmp;
struct Obj020437AC;
struct QF;
struct Unk021D62A8;
struct Work_v64CC;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int kind, a, b, c; } Ent_021F6560;

typedef struct {
    int f0;
    int ids[4][4];
} Rec_v6560;

typedef struct {
    int f0, f4, f8;
    int sx, sy, sz;
    int matrix[9];
} Xf;

typedef struct {
    void *f0;
    int n;
    Ent_021F6560 *arr[2];
    void **f10;
    void **f14[2];
    void *h1c[2];
    void *h24[2];
    Xf xf[2];
    void **fa4;
    void **fa8;
    u8 fac, fad;
    u8 padae[10];
    u16 heap;
    u16 padba;
} Obj_021F6560;

typedef struct {
    void *f0;           /* 0x00 */
    int n;              /* 0x04 */
    void *f8[2];        /* 0x08 */
    void **f10;         /* 0x10 */
    void **f14[2];      /* 0x14 */
    void *f1c[2];       /* 0x1c */
    void *f24[2];       /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    void *fa4;          /* 0xa4 */
    void **fa8;         /* 0xa8 */
} Obj_021F6898;

typedef struct {
    int kind;       /* 0x00 */
    int f4;
    int f8;
    int fc;
} Ent_021F6934;

typedef struct {
    int f0;
    int n;              /* 0x04 */
    Ent_021F6934 *arr[2];        /* 0x08 */
    char pad10[0x24 - 0x10];
    void *h[2];         /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    char sub[0x10];     /* 0xa4 */
} Obj_021F6934;

typedef struct {
    char pad[0x24];
    void *h[2];             /* 0x24 */
    char xf[2][0x3c];       /* 0x2c */
    char padA4[0xb4 - 0xa4];
    unsigned off : 2;       /* 0xb4 */
} Obj_021F69B0;

typedef struct {
    char pad[0xac];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
} S69E8;

typedef struct { char pad[0xB4]; u32 f : 2; u32 rest : 30; } Obj_021F6A28;

typedef struct {
    int state;
    int armed;
    int a;
    int b;
} Entry_021F6560;

typedef struct {
    char pad[8];
    Entry_021F6560 *tab[1];
} Obj_021F6AA8;

typedef struct {
    int pad0;
    int n;              /* 0x04 */
    Entry_021F6560 *x;           /* 0x08 */
    Entry_021F6560 *y;           /* 0x0c */
} Obj_021F6AD0;

typedef struct { int kind, a, b, c; } Ent_021F6B04;

typedef struct {
    void *f0;
    int n;
    Ent_021F6B04 *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    int f1c, f20, f24;
    int f28, f2c, f30;
    int matrix[9];
    void **f58;
    void **f5c;
    u8 f60, f61;
    u8 pad62[10];
    u16 heap;
    u16 pad6e;
} Obj_021F6B04;

typedef struct {
    void *f0;
    int n;              /* 0x04 */
    void *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    char pad1c[0x58 - 0x1c];
    void *f58;
    void **f5c;
} Obj_021F6CF0;

typedef struct {
    int kind;       /* 0x00 */
    int f4;
    int f8;
    int fc;
} Ent_021F6D5C;

typedef struct {
    int f0;
    int n;              /* 0x04 */
    Ent_021F6D5C *arr;           /* 0x08 */
    char pad0c[0x0c];
    void *h18;          /* 0x18 */
    char pad1c[0x58 - 0x1c];
    char sub[0x10];     /* 0x58 */
    u32 bit0 : 1;       /* 0x68 */
    u32 bit1 : 1;
} Obj_021F6D5C;

typedef struct {
    char pad[0x18];
    void *h;            /* 0x18 */
    int v[3];           /* 0x1c */
    char pad28[0x68 - 0x28];
    unsigned b0 : 1;    /* 0x68 */
} Obj_021F6DD4;

typedef struct {
    char pad[0x60];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
} S6DEC;

typedef struct { char pad[0x68]; u32 f : 1; u32 rest : 31; } Obj_021F6E2C;

typedef struct {
    int x, y, z;
} VecFx32_v6560;

typedef struct {
    int f0;
    int h4;
    char pad08[0x10];
    VecFx32_v6560 v18;        /* 0x18 */
    VecFx32_v6560 v24;        /* 0x24 */
    char pad30[0xb4 - 0x30];
    u16 hb4;            /* 0xb4 */
} Obj_021F6E3C;

typedef struct {
    char pad[4];
    void *h;            /* 0x04 */
    char pad08[0x18 - 8];
    int m[3];           /* 0x18 */
    int v[3];           /* 0x24 */
} Obj_021F6F20;

typedef int fx32;

typedef struct {
    char pad00[0x14];
    unsigned int flags;     /* 0x14 */
    VecFx32_v6560 cur0;           /* 0x18 */
    VecFx32_v6560 cur1;           /* 0x24 */
    VecFx32_v6560 dst0;           /* 0x30 */
    VecFx32_v6560 dst1;           /* 0x3c */
    VecFx32_v6560 step0;          /* 0x48 */
    VecFx32_v6560 step1;          /* 0x54 */
    char pad60[0x0c];
    int f6c;                /* 0x6c */
    int f70;                /* 0x70 */
    int f74;                /* 0x74 */
} Cam_021F6F48;

typedef struct {
    char pad00[0x14];
    unsigned int flags;     /* 0x14 */
    char pad18[0x60];
    int f78;                /* 0x78 */
    int f7c;                /* 0x7c */
    int f80;                /* 0x80 */
    int f84;                /* 0x84 */
    fx32 f88;               /* 0x88 */
    fx32 f8c;               /* 0x8c */
    int f90;                /* 0x90 */
    fx32 f94;               /* 0x94 */
    fx32 f98;               /* 0x98 */
    int f9c;                /* 0x9c */
    int fa0;                /* 0xa0 */
    int fa4;                /* 0xa4 */
    int fa8;                /* 0xa8 */
    int fac;                /* 0xac */
    int fb0;                /* 0xb0 */
} Cam_021F7000;

typedef signed short s16_021F6560;

typedef struct {
    int w[4];
} Q_v6560;

typedef struct {
    int f0;
    int f4;
    Q_v6560 q;            /* 0x08 */
    u16 h[4];       /* 0x18 */
    int f20;
    int f24;
    int f28;
} Obj_v6560;

typedef struct {
    int f0;          /* 0x00 */
    int f4;          /* 0x04 */
    int f8;          /* 0x08 */
    int fc;          /* 0x0c */
    u8 f10;          /* 0x10 */
    u8 f11;          /* 0x11 */
    u16 f12;         /* 0x12 */
    u8 f14;          /* 0x14 */
    u8 f15;          /* 0x15 */
    char pad16[0x28 - 0x16];
    void *battle;    /* 0x28 */
} Param;

typedef struct {
    void *owner;     /* 0x000 */
    void *buf;       /* 0x004 */
    char pad08[0x188 - 8];
    void *h188;      /* 0x188 */
    int h18c;        /* 0x18c */
    void *h190;      /* 0x190 */
    void *h194;      /* 0x194 */
    void *h198;      /* 0x198 */
    void *h19c;      /* 0x19c */
    void *h1a0;      /* 0x1a0 */
    void *h1a4;      /* 0x1a4 */
    char pad1a8[8];
    void *h1b0;      /* 0x1b0 */
    void *h1b4;      /* 0x1b4 */
    void *h1b8;      /* 0x1b8 */
    Param param;     /* 0x1bc */
    int f1e8;        /* 0x1e8 */
    char pad1ec[4];
    u16 heap;        /* 0x1f0 */
    char pad1f2[6];
    int slots[8];    /* 0x1f8 */
    char pad218[0x244 - 0x218];
    int f244;        /* 0x244 */
    int f248;        /* 0x248 */
} Work_v6560;

typedef struct {
    u8 f0;
    u8 f1;
    u8 a2[0x13 - 2];
    u8 a13[0x24 - 0x13];
} Entry_021F7208;

typedef struct {
    s16_021F6560 x;
    s16_021F6560 y;
    s16_021F6560 z;
    u16 w;
} Rect;

typedef struct BtlvEff {
    void *owner;                /* 0x000 */
    void *buf;                  /* 0x004 */
    void *handle[32];           /* 0x008 */
    void (*cb[32])(void *);     /* 0x088 */
    int arg[32];                /* 0x108 */
    void *h188;                 /* 0x188 */
    void *h18c;
    void *h190;                 /* 0x190 */
    void *h194;
    void *h198;
    void *h19c;
    void *h1a0;
    void *h1a4;
    void *h1a8[2];              /* 0x1a8 */
    void *h1b0;                 /* 0x1b0 */
    void *h1b4;
    void *h1b8;
    int mode;                   /* 0x1bc */
    int f1c0;
    char pad1c4[0x10];
    unsigned short f1d4[4];                /* 0x1d4 */
    int f1dc;
    int f1e0;
    void *param_battle;         /* 0x1e4 */
    int f1e8;                   /* 0x1e8 */
    unsigned int m0 : 8;                 /* 0x1ec */
    unsigned int m1 : 8;
    unsigned int m2 : 2;
    unsigned int v : 8;
    unsigned int b26 : 1;
    unsigned short heap;                   /* 0x1f0 */
    char pad1f2[2];
    int f1f4;                   /* 0x1f4 */
    int slots[8];               /* 0x1f8 */
    unsigned int tbl[8];                 /* 0x218 */
    int f238;                   /* 0x238 */
    int f23c;
    int f240;
    int f244;
    int f248;
} BtlvEff;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} Job_021F7998;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} Job_021F7A28;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} Job_021F7AAC;

typedef struct {
    u8 b0, b1, b2, b3;
    int f4;
    int f8;
    u16 fc;
} Arg_v6560;

typedef struct {
    u8 b0, b1, b2;
} Small;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    Small *s;           /* 0x10 */
} Job_021F7B2C;

typedef struct {
    u16 h0;
    int f4;
    int f8;
    u8 c;               /* 0x0c */
    u8 d;               /* 0x0d */
    int f10;
} Req_021F7208;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Job_021F7208;

typedef struct {
    int w[3];
    unsigned short v;
} Req_021F7D44;

typedef struct {
    int f0;
    int f4;
    int buf[9];         /* 0x08 */
} Job_021F7D80;

typedef struct {
    char pad[0x190];
    void *h190;
} Work_021F7E38;

typedef signed char s8;

typedef struct {
    int state;              /* 0 */
    u8 b;                   /* 4 */
    int c;                  /* 8 */
    int d;                  /* 0xC */
} St;

typedef struct { int x, y, z; } VecFx32_021F8204;

typedef struct {
    char pad[0x1ec];
    unsigned m : 8;
    unsigned lo : 10;
    unsigned v : 8;
    unsigned b26 : 1;
} Work_021F88A8;

typedef struct {
    char pad[0x1ec];
    unsigned lo : 26;
    unsigned b26 : 1;
} Work_021F88E0;

typedef enum { SLOT_ZERO, SLOT_LAST = 14 } Slot_021F6560;

typedef struct {
    int pad0;
    int a;              /* 4 */
    u32 b;              /* 8 */
    u32 c;              /* 0xC */
    void *d;            /* 0x10 */
} Arg_v8204;

typedef unsigned long long u64;

typedef struct {
    fx32 x, y, z;
} VecFx32_021F8F30;

typedef struct {
    int mode;               /* 0x00 */
    VecFx32_021F8F30 end;            /* 0x04 */
    VecFx32_021F8F30 start;          /* 0x10 */
    VecFx32_021F8F30 step;           /* 0x1c */
    int count;              /* 0x28 */
    int countReset;         /* 0x2c */
    int wait;               /* 0x30 */
    int waitReset;          /* 0x34 */
    int repeat;             /* 0x38 */
} Mover_v8204;

typedef struct {
    u32 **a0;           /* 0 */
    u16 **a4;           /* 4 */
    u8 en;              /* 8 */
    u8 n;               /* 9 */
    u8 cur;             /* 0xA */
    u8 tgt;             /* 0xB */
    u8 cnt;             /* 0xC */
    u8 rl;              /* 0xD */
    u16 col;            /* 0xE */
} P;

typedef struct {
    char pad[0x2C];
    u32 w2c;            /* 0x2C */
    u16 h30;            /* 0x30 */
    char pad2[6];
    u32 o38;            /* 0x38 */
} Q_v8204;

typedef signed int     s32;

typedef struct {
    char pad0[8];
    void *a;            /* 8 */
    char pad1[0x40];
    int v4c[16];        /* 0x4C */
    char padx[0x40];
    int vcc[4];         /* 0xCC */
    char pad2[0x238 - 0xDC];
    u16 h238;           /* 0x238 */
    char pad3[2];
    int f23c;           /* 0x23C */
    char pad4[4];
    int f244;           /* 0x244 */
    char pad5[0x26C - 0x248];
    int e26c[6];        /* 0x26C */
} T_021F93F4;

typedef struct {
    u32 lo : 6;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 rest : 24;
    char pad[0x1E4];
    void *h;            /* 0x1E8 */
} T_021F9478;

typedef struct {
    u32 w[4];
} Quad_v8204;

typedef struct {
    u32 lo : 6;
    u32 b6 : 1;
    u32 b7 : 5;
    u32 b12 : 1;
    u32 b13 : 4;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 rest : 13;
    int f4;
    char pad0[0xdc - 8];
    u32 fdc;            /* 0x0DC */
    u32 fe0;            /* 0x0E0 */
    char pad1[0x1e8 - 0xe4];
    u8 *f1e8;           /* 0x1E8 */
    u8 *f1ec;           /* 0x1EC */
    int f1f0;           /* 0x1F0 */
    char pad2[0x238 - 0x1f4];
    u16 h238;           /* 0x238 */
    char pad3[0x244 - 0x23a];
    int f244;           /* 0x244 */
    Quad_v8204 q248;          /* 0x248 */
    u16 h258;           /* 0x258 */
    char pad4[2];
    int f25c;           /* 0x25C */
    char pad5[0x2a4 - 0x260];
    u32 f2a4;           /* 0x2A4 */
    u32 f2a8;           /* 0x2A8 */
} T;

typedef struct {
    unsigned lo : 6;
    unsigned b6 : 1;
} Flags_021F9814;

typedef struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int  w1;
    unsigned int  w2;
    unsigned short h1;
} S9844;

typedef struct {
    u32 flags;
    u32 f4;
    void *owner;
    char pad[0x238 - 12];
    u16 heap;
} Work_v9814;

typedef struct {
    Work_v9814 *work;
    u32 a;
    int b;
    int c;
    int d;
    int e;
    u32 f;
    int g;
    int h;
} Job_021F9858;

typedef struct {
    Work_v9814 *work;
    u32 a;
    int mode;
    int c;
    int x;
    int dest;
    int fx;
    int delta;
    int e;
    int f;
    int remaining;
    int zero;
    int g;
    int duration;
} Job_021F9948;

typedef struct {
    int x, y, z;
} VecFx32_v9814;

typedef struct {
    unsigned b0:1;
    unsigned f1:1;
    unsigned b2:11;
    unsigned f13:1;
    unsigned b14:1;
    unsigned f15:1;
    unsigned rest:16;
} Flags_021F9AB8;

typedef struct {
    Flags_021F9AB8 flags;
    char pad04[0xdc - 4];
    int dc;             /* 0xdc */
    int e0;             /* 0xe0 */
    char pade4[0x23c - 0xe4];
    int ret;            /* 0x23c */
    char pad240[0x248 - 0x240];
    u8 b248;            /* 0x248 */
    char pad249[0x284 - 0x249];
    int h284;           /* 0x284 */
    VecFx32_v9814 a288;       /* 0x288 */
    VecFx32_v9814 b294;       /* 0x294 */
} Ctx_021F9814;

typedef struct {
    char pad[0x23C];
    int ret;            /* 0x23C */
} Ctx_021F9EFC;

typedef struct {
    char pad[0x23C];
    int ret;            /* 0x23C */
} Ctx_v9814;

typedef struct {
    char pad[0x23C];
    int f23c;
    char pad2[4];
    int f244;
} State;

typedef struct { char *state; void *emitter; void *resource; } Callback;

typedef struct { int x, y, z; } Vec_021F6560;

typedef struct { u32 v[8]; } Desc_021F6560;

typedef struct {
    char pad[0x23C];
    int f23c;
} State_021FA758;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    char pad[0x14];
} Req_021FAD2C;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
} Req_021FADC0;

typedef short s16_021FA758;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
} State_021FB3C8;

typedef struct {
    char pad[0xdc];
    int fdc;            /* 0xdc */
    char pade0[0x23c - 0xe0];
    int ret;            /* 0x23c */
} State_021FB91C;

typedef struct { short x, y; } Pt_021FB8F4;

typedef struct {
    char pad[0x23c];
    int f23c;
} State_021FBA64;

typedef struct {
    char pad[0x23c];
    int f23c;
} State_021FBC78;

typedef struct {
    char pad[0x23c];
    int f23c;
} State_021FB8F4;

typedef struct {
    unsigned f0_lo : 13;
    unsigned f0_b13 : 1;
    unsigned f0_b14 : 1;
    unsigned f0_b15 : 1;
    unsigned f0_hi : 16;
    char pad[0x244];
    char f248;
    char f249;
    char f24a;
    char f24b;
    int f24c;
    int f250;
    short f254;
    char pad2[0x284 - 0x256];
    int f284;
    char pad3[0x2a0 - 0x288];
    int f2a0;
} State_021FBE28;

typedef struct { unsigned low : 10; unsigned bit10 : 1; unsigned high : 21; } Flags_021FB8F4;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
    char pad2[0x254 - 0x240];
    u16 f254;
} State_021FC148;

typedef struct {
    int x;
    int y;
    int z;
} Pt_021FC148;

typedef struct {
    int pad0;
    int f4;
    char pad1[0xdc - 8];
    int fdc;
    int fe0;
    int a0[16];
    int a1[16];
    int a2[16];
    int a3[16];
    int f1e4;
    int *f1e8;
    char pad2[0x238 - 0x1ec];
    u16 h238;
    char pad3[2];
    int f23c;
    char pad4[0x260 - 0x240];
    int f260;
} State_021FC20C;

typedef struct {
    int pad0;
    int f4;
    char pad1[0xdc - 8];
    int fdc;
    int fe0;
    int a0[16];
    int a1[16];
    int a2[16];
    int a3[16];
    int f1e4;
    void *f1e8;
    char pad2[0x23c - 0x1ec];
    int f23c;
    char pad3[0x260 - 0x240];
    int f260;
} State_021FC2DC;

typedef struct {
    int pad0;
    int pad4;
    void *f8;
    char pad1[0x238 - 0xc];
    u16 h238;
    char pad2[2];
    int f23c;
} State_021FC3D8;

typedef union {
    unsigned word;
    struct {
        unsigned gap0 : 4;
        unsigned b4 : 1;
        unsigned b5 : 1;
        unsigned b6 : 1;
        unsigned gap7 : 5;
        unsigned b12 : 1;
        unsigned gap13 : 4;
        unsigned b17 : 1;
        unsigned b18 : 1;
    } bit;
} Flags_021FC448;

typedef struct {
    Flags_021FC448 flags;
    int f4;
    int pad8;
    void *objects[16];
    int ids[16];
    char pad8c[0xcc - 0x8c];
    int res[4];
    int fdc;
    char pade0[0x1e8 - 0xe0];
    char *f1e8;
    char *f1ec;
    int f1f0;
    void *bufs[16];
    int nbufs;
    u16 h238;
    char pad23a[2];
    int f23c;
    char pad240[0x249 - 0x240];
    u8 b249;
    char pad24a[0x258 - 0x24a];
    u16 h258;
    char pad25a[0x264 - 0x25a];
    int f264;
    int f268;
} State_021FC448;

typedef union {
    unsigned word;
    struct {
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned gap4 : 3;
        unsigned b7 : 1;
        unsigned b8 : 1;
        unsigned gap9 : 2;
        unsigned b11 : 1;
        unsigned gap12 : 4;
        unsigned b16 : 1;
    } bit;
} Flags_021FC744;

typedef struct {
    Flags_021FC744 flags;
    char pad[8];
    void *objects[16];
    char pad2[0x240 - 0x4c];
    unsigned mode;
    int f244;
    char pad3[0x26c - 0x248];
    int slots[6];
} State_021FC744;

typedef struct {
    unsigned lo : 7;
    unsigned bit : 1;
} Flags_021FC9E4;

typedef struct {
    unsigned lo : 16;
    unsigned bit : 1;
} Flags_021FC9F4;

typedef enum { KEY_ZERO, KEY_ONE, KEY_TWO, KEY_THREE, KEY_MAX = 7 } Key_021F6560;

typedef struct {
    char pad00[0xdc];
    int dc, e0;
    char pade4[0x164];
    u8 kind;
} State_021FC9F4;

typedef struct { int v[4][3]; } Targets;

typedef struct {
    unsigned int word0;
    char pad[0xd8];
    int dc;
    int e0;
} Unit_vB8F4;

typedef struct {
    unsigned int bit0 : 1;
} Unit_021FD04C;

struct OneBit {
    unsigned int v : 1;
};

typedef struct {
    unsigned int pad0 : 6;
    unsigned int flag : 1;
    unsigned int pad7 : 25;
    char pad[0xd8];
    int dc;
    int e0;
    char pad2[0x248 - 0xe4];
    unsigned char kind;
} Unit_021FD088;

typedef struct {
    char pad[0x4c];
    int slot[16];
} Tbl_vD04C;

typedef long long s64;

typedef struct { s16_021F6560 x, y, z; } Vec16;

typedef struct { int m[12]; } Mtx;

typedef struct { u16 on; Vec16 dir; } Dir;

typedef struct {
    int vm;         /* 0x00 */
    int k1;         /* 0x04 */
    int k2;         /* 0x08 */
    Vec_021F6560 ofs;        /* 0x0c */
    int f18;        /* 0x18 */
    int f1c;        /* 0x1c */
    int kind;       /* 0x20 */
    int f24;        /* 0x24 */
    Vec_021F6560 pa;         /* 0x28 */
    Vec_021F6560 pb;         /* 0x34 */
    int mode;       /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int flip;       /* 0x58 */
} Rec_021FD04C;

typedef struct {
    int m[9];       /* 0x00 */
    Vec_021F6560 pos;        /* 0x24 */
    int f30;        /* 0x30 */
    int f34;        /* 0x34 */
    int f38;        /* 0x38 */
    int f3c;        /* 0x3c */
    int f40;        /* 0x40 */
    int f44;        /* 0x44 */
    int f48;        /* 0x48 */
    int f4c;        /* 0x4c */
    int f50;        /* 0x50 */
    int f54;        /* 0x54 */
    int f58;        /* 0x58 */
    int f5c;        /* 0x5c */
} Obj_vD04C;

typedef struct { int x, y, z; } VecFx32_021FD04C;

typedef struct {
    char pad00[0x0c];
    int k0c;                /* 0x0c */
    char pad10[0x2c];
    int k3c;                /* 0x3c */
} State_021FD04C;

typedef struct {
    char pad[0x244];
    int f244;
} State_021FDB20;

typedef struct {
    unsigned int pad0:13;
    unsigned int f13:1;
    unsigned int pad14:1;
    unsigned int f15:1;
    unsigned int pad16:16;
    int f4;
    char pad8[0xd4];
    int dc, e0;
    char pade4[0x164];
    u8 b248, b249, b24a, b24b;
    int f24c, f250;
    u16 f254;
    char pad256[0x2e];
    int f284;
    char pad288[0x18];
    int f2a0;
} State_021FDBB0;

typedef struct { unsigned low:6; unsigned b6:1; } Flags_021F6560;

typedef struct {
    Flags_021F6560 flags;
    char pad04[8];
    int *objects[16];
    char pad4c[0x90];
    int dc;
    char pade0[0x158];
    u16 heap;
    char pad23a[0xe];
    u8 kind;
    char pad249[0xf];
    u16 f258;
} State_021FDD60;

typedef struct { int v[23]; } Rec_021FDD60;

typedef long long fx64;

typedef struct { fx32 x, y, z; } VecFx32_021FE1B8;

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    unsigned int f0 : 9;
    unsigned int f9 : 1;
    unsigned int f10 : 1;
} Flags_021FE254;

typedef struct {
    Flags_021FE254 *fl;
    int a;
    int b;
    int v[3];
} Rec_vE254;

typedef struct {
    Flags_021FE254 fl;
    char pad04[4];
    int h;
    char pad0c[0xd0];
    unsigned int heap : 32;
} Obj_021FE254;

typedef enum { KEY_0 } Key_021FD04C;

typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags_021FE690;

typedef struct {
    Flags_021FE690 fl;
    char pad04[4];
    int h;
} Obj_021FE690;

typedef struct {
    Obj_021FE690 *obj;
    int a1, a2, a3;
    int a4, a5, a6;
    int cnt;
} Req;

typedef struct {
    unsigned int *reg;      /* 0x00 */
    char pad04[0x20];
    int k24;                /* 0x24 */
} Ctx_021FE254;

typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags_vE254;

typedef struct {
    Flags_vE254 fl;
    char pad04[0x268];
    int tbl[6];
} Obj_vE254;

typedef struct {
    int pad0;
    int side;
    int mask;
} Arg_vE254;

typedef struct {
    unsigned int *reg;      /* 0x00 */
    void *obj;              /* 0x04 */
} Ctx_021FE9BC;

typedef enum { SLOT_0, SLOT_MAX = 8 } Slot_021FD04C;

typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FEAC0;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags_021FEAC0;

typedef struct {
    int *cb;                /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEAC0 e[14];            /* 0x008 */
    Flags_021FEAC0 flags;            /* 0x510 */
    char pad514[0x534 - 0x514];
    int active;             /* 0x534 */
    int scaleEven;          /* 0x538 */
    int scaleOdd;           /* 0x53c */
    u16 heap;               /* 0x540 */
} Work_021FEAC0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FEB78;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEB78 e[14];            /* 0x008 */
} Work_021FEB78;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int f2 : 5;
    unsigned int f7 : 1;
    unsigned int f8 : 1;
    unsigned int f9 : 2;
    unsigned int f11 : 1;
    int f50;                /* 0x50 */
    int f54;                /* 0x54 */
    int f58;                /* 0x58 */
} Entry_021FEBAC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEBAC e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;
    int m518;
    int m51c;
    int m520;
    int m524;
    int m528;               /* 0x528 */
} Work_021FEBAC;

typedef struct { int x, y, z; } Vec_021FE254;

typedef struct { Vec_021FE254 orient, pos; } Vectors;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b34 : 2;
    unsigned int b5 : 1;
} Flags_021FEEA8;

typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FE254;

typedef struct {
    int pad00;
    void *obj;
    Entry_021FE254 e[14];
} Work_vE254;

typedef struct { u32 x, y, z; } Vec_021FF088;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FF0F8;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF0F8 e[14];            /* 0x008 */
} Work_021FF0F8;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FF144;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF144 e[14];            /* 0x008 */
} Work_021FF144;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF16C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF16C e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_021FF16C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF1B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF1B0 e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_021FF1B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF228;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF228 e[14];            /* 0x008 */
} Work_021FF228;

typedef struct {
    void *h;
    char pad04[0x48];
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF260;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF2D8;

typedef struct {
    void *h;
    char pad[0x58];
} Entry_021FF304;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF228 e[14];            /* 0x008 */
} Work_021FF348;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 5;    /* 0x4c */
    unsigned int f5 : 1;
    char pad50[0x0c];
} Entry_021FF374;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF374 e[14];            /* 0x008 */
} Work_vF228;

typedef struct {
    int x, y, z;
} Vec3_vF228;

typedef struct {
    fx32 x, y, z;
} VecFx32_vF5B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_021FF5B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF5B0 e[14];            /* 0x008 */
    char pad510[0x518 - 0x510];
    int mask[4];            /* 0x518 */
    char pad528[0x550 - 0x528];
    u8 cnt[4][14];          /* 0x550 */
} Work_021FF5B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF630;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF630 e[14];            /* 0x008 */
    char pad514[0x520 - 0x008 - 14 * 0x5c];
    int mask;               /* 0x520 */
    char pad524[0x534 - 0x524];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
    char pad540[0x55e - 0x540];
    unsigned char cnt[14];  /* 0x55e */
} Work_021FF630;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_vF5B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vF5B0 e[14];            /* 0x008 */
    char pad510[0x518 - 0x510];
    int mask[4];            /* 0x518 */
    char pad528[0x550 - 0x528];
    u8 cnt[4][14];          /* 0x550 */
} Work_vF5B0;

typedef struct {
    int x, y, z;
} Vec3_vF7B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x44];
    int key;                /* 0x48 */
    unsigned int pad4c : 6; /* 0x4c */
    unsigned int f6 : 1;
    char pad50[0x0c];
} Entry_021FF7B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF7B0 e[14];            /* 0x008 */
} Work_021FF7B0;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x520 - 4];
    int mask[4];            /* 0x520 */
    char pad530[0x540 - 0x530];
    u16 heap;               /* 0x540 */
    char pad542[0x588 - 0x542];
    u8 cnt[4][14];          /* 0x588 */
} Work_021FF870;

typedef struct {
    Work_021FF870 *w;                /* 0x00 */
    int i;                  /* 0x04 */
    char pad08[0x0c];
    int kind;               /* 0x14 */
    char pad18[0x2c];
    int f44;                /* 0x44 */
    int f48;                /* 0x48 */
    int f4c;                /* 0x4c */
    int f50;                /* 0x50 */
} Obj_021FF870;

typedef struct {
    void *owner;
    char pad04[0x514 - 4];
    int mask;
    char pad518[0x540 - 0x518];
    u16 heap;
    u8 cnt[14];
} Work_021FFA18;

typedef struct {
    Work_021FFA18 *w;
    int key, kind, direction, f10, f14, f18, f1c, f20, f24;
    int f28, f2c, f30, f34, f38;
} Obj_021FFA18;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x5c - 4];
} Entry_021FFB04;

typedef struct {
    void *owner;            /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFB04 e[14];            /* 0x008 */
    char pad510[0x514 - 0x510];
    int mask[6];            /* 0x514 */
    char pad52c[0x540 - 0x52c];
    u16 heap;               /* 0x540 */
    u8 cnt[6][14];          /* 0x542 */
} Work_vF7B0;

typedef struct {
    Work_vF7B0 *w;                /* 0x00 */
    int key;                /* 0x04 */
    int v[3];               /* 0x08 */
    char pad14[0x14];
    int f28;                /* 0x28 */
} Obj_vF7B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_021FFCB0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFCB0 e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;              /* 0x514 */
    int m518;               /* 0x518 */
    int m51c;               /* 0x51c */
    int m520;               /* 0x520 */
    int m524;               /* 0x524 */
    int m528;               /* 0x528 */
    int m52c;               /* 0x52c */
    int m530;               /* 0x530 */
} Work_021FFCB0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FFD6C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFD6C e[14];            /* 0x008 */
} Work_021FFD6C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry_021FFDB4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFDB4 e[14];            /* 0x008 */
} Work_vFCB0;

typedef struct {
    int w[9];
} Rec_vFCB0;

typedef struct {
    void *h;                /* 0x00 */
    Rec_vFCB0 rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_021FFDF8;

typedef struct {
    int w[9];
} Rec_vFE24;

typedef struct {
    void *h;                /* 0x00 */
    Rec_vFE24 rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_vFE24;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE24 e[14];            /* 0x008 */
} Work_vFE24;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 a;                  /* 0x2c (w+0x34) */
    u32 b;                  /* 0x30 (w+0x38) */
    u32 c;                  /* 0x34 (w+0x3c) */
    u16 d;                  /* 0x38 (w+0x40) */
    u16 e;                  /* 0x3a (w+0x42) */
    u32 f;                  /* 0x3c (w+0x44) */
    u32 flags0;             /* 0x40 (w+0x48) */
    char pad44[0x08];
    u32 flags;              /* 0x4c (w+0x54) */
    char pad50[0x0c];
} Entry_021FFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFE48 e[14];            /* 0x008 */
} Work_021FFE48;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 a;                  /* 0x2c (w+0x34) */
    u32 b;                  /* 0x30 (w+0x38) */
    char pad34[0x28];
} Entry_021FFF68;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFF68 e[14];            /* 0x008 */
} Work_021FFF68;

typedef struct {
    int w[9];
} Rec_021FFFAC;

typedef struct {
    void *h;                /* 0x00 */
    Rec_021FFFAC rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_021FFFAC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFFAC e[14];            /* 0x008 */
} Work_021FFFAC;

typedef struct { u32 v[9]; } Rec_021FFFD8;

typedef struct {
    int w[9];
} Rec_02200108;

typedef struct {
    void *h;                /* 0x00 */
    Rec_02200108 rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_02200108;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200108 e[14];            /* 0x008 */
} Work_02200108;

typedef struct {
    int a, b, c, d;
} Quad_vFE48;

typedef struct {
    void *h;                /* 0x00 */
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char pad24[0x08];
    Quad_vFE48 q;                 /* 0x2c */
    char pad3c[0x20];
} Entry_02200140;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200140 e[14];            /* 0x008 */
} Work_02200140;

typedef struct {
    int w[9];
} Rec_022001DC;

typedef struct {
    void *h;                /* 0x00 */
    Rec_022001DC rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_022001DC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022001DC e[14];            /* 0x008 */
} Work_022001DC;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 k2c;                /* 0x2c */
    u32 k30;                /* 0x30 */
    char pad34[0x06];
    u16 k3a;                /* 0x3a */
    char pad3c[0x20];
} Entry_02200218;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags_vFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200218 e[14];            /* 0x008 */
    Flags_vFE48 flags;            /* 0x510 */
} Work_02200218;

typedef struct {
    void *owner;            /* 0x000 */
    char pad004[0x510 - 4];
    u32 flags;              /* 0x510 */
    char pad514[0x540 - 0x514];
    u16 heap;               /* 0x540 */
} Work_02200344;

typedef struct {
    Work_02200344 *w;                /* 0x00 */
    u32 a : 31;             /* 0x04 */
    u32 flag : 1;
    int f8;                 /* 0x08 */
    int fc;                 /* 0x0c */
} Obj_vFE48;

typedef struct {
    int pad00;              /* 0x00 */
    void *obj;              /* 0x04 */
} Work_022003EC;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x40];
    int f44;                /* 0x44 */
    char pad48[0x14];
} Entry_0220041C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220041C e[14];            /* 0x008 */
} Work_0220041C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_02200468;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200468 e[14];            /* 0x008 */
} Work_02200468;

typedef struct {
    int x, y, z;
} Vec_vFE48;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry_022004BC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022004BC e[14];            /* 0x008 */
} Work_022004BC;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_0220055C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220055C e[14];            /* 0x008 */
} Work_0220055C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 9;    /* 0x4c */
    unsigned int f9 : 1;
    unsigned int hi : 22;
    char pad50[0x0c];
} Entry_022005C4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022005C4 e[14];            /* 0x008 */
} Work_022005C4;

typedef enum { SLOT_FE48_0, SLOT_FE48_MAX = 8 } Slot_021FFE48;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 10;   /* 0x4c */
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry_02200608;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200608 e[14];            /* 0x008 */
} Work_02200608;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 5;    /* 0x4c */
    unsigned int f5 : 1;
    unsigned int mid : 4;
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry_02200654;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200654 e[14];            /* 0x008 */
} Work_02200654;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_022006B4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022006B4 e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_022006B4;

typedef struct {
    fx32 x, y, z;
} VecFx32_vFE48;

typedef struct {
    void *owner;        /* 0x000 */
    char pad[0x540 - 4];
    u16 heap;           /* 0x540 */
} Work_0220074C;

typedef struct {
    Work_0220074C *w;            /* 0x00 */
    int i;              /* 0x04 */
    VecFx32_vFE48 cur;        /* 0x08 */
    int kind;           /* 0x14 */
    VecFx32_vFE48 start;      /* 0x18 */
    VecFx32_vFE48 end;        /* 0x24 */
    VecFx32_vFE48 step;       /* 0x30 */
    int frames;         /* 0x3c */
    int left;           /* 0x40 */
    int count;          /* 0x44 */
    int f48;            /* 0x48 */
    int f4c;            /* 0x4c */
    int f50;            /* 0x50 */
} Mover_0220074C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_0220074C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220074C e[14];            /* 0x008 */
    char pad[0x542 - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x542 */
} Work_02200904;

typedef struct {
    char body[0x3c];
} Mover_02200904;

typedef struct {
    Work_02200904 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_02200904 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_021FFE48;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_vFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x514 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x514 */
    char pad518[0x542 - 0x518];
    u8 tag[1];              /* 0x542 */
} Work_02200990;

typedef struct {
    char body[0x3c];
} Mover_vFE48;

typedef struct {
    Work_02200990 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200990;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x550 - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x550 */
} Work_vFE48;

typedef struct {
    Work_vFE48 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_vFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x518 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x518 */
    char pad51c[0x550 - 0x51c];
    u8 tag[1];              /* 0x550 */
} Work_02200A50;

typedef struct {
    Work_02200A50 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200A50;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x55e - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x55e */
} Work_02200A84;

typedef struct {
    Work_02200A84 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200A84;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x520 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x520 */
    char pad524[0x55e - 0x524];
    u8 tag[1];              /* 0x55e */
} Work_02200B10;

typedef struct {
    Work_02200B10 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200B10;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x56c - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x56c */
} Work_02200B48;

typedef struct {
    Work_02200B48 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200B48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x524 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x524 */
    char pad528[0x56c - 0x528];
    u8 tag[1];              /* 0x56c */
} Work_02200BD4;

typedef struct {
    Work_02200BD4 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200BD4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x57a - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x57a */
} Work_02200C0C;

typedef struct {
    Work_02200C0C *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200C0C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vFE48 e[14];            /* 0x008 */
    char pad[0x51c - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x51c */
    char pad520[0x57a - 0x520];
    u8 tag[1];              /* 0x57a */
} Work_02200C98;

typedef struct {
    Work_02200C98 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_vFE48 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_02200C98;

typedef struct {
    char pad000[0x588];
    u8 tag[1];              /* 0x588 */
} Work_02200CD0;

typedef struct {
    Work_02200CD0 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x3c];
    int wait;               /* 0x44 */
    int reload;             /* 0x48 */
    int count;              /* 0x4c */
    int tag;                /* 0x50 */
} Ctx_02200CD0;

typedef struct {
    fx32 x, y, z;
} VecFx32_v0D30;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_v0D30;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v0D30 e[14];            /* 0x008 */
    char pad[0x528 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x528 */
    char pad52c[0x588 - 0x52c];
    u8 tag[1];              /* 0x588 */
} Work_v0D30;

typedef struct {
    char body[0x3c];
} Mover_v0D30;

typedef struct {
    Work_v0D30 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_v0D30 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_v0D30;

typedef struct {
    fx32 x, y, z;
} VecFx32_v0DE4;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_v0DE4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v0DE4 e[14];            /* 0x008 */
    char pad[0x52c - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x52c */
    char pad530[0x596 - 0x530];
    u8 tag[1];              /* 0x596 */
} Work_v0DE4;

typedef struct {
    char body[0x3c];
} Mover_v0DE4;

typedef struct {
    Work_v0DE4 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_v0DE4 mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_v0DE4;

typedef short s16_021FFE48;

typedef struct Vec_021FFE48 { int x, y, z; } Vec_021FFE48;

typedef struct {
    fx32 x, y, z;
} VecFx32_v1098;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_v1098;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v1098 e[14];            /* 0x008 */
    char pad[0x514 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x514 */
    char pad518[0x542 - 0x518];
    u8 tag[1];              /* 0x542 */
} Work_v1098;

typedef struct {
    char body[0x24];
} Mover_v1098;

typedef struct {
    Work_v1098 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_v1098 mv;               /* 0x14 */
    int tag;                /* 0x38 */
} Ctx_v1098;

typedef short s16_02201098;

typedef struct Vec_02201098 { int x, y, z; } Vec_02201098;

typedef struct {
    char body[0x14];
} Mover_022011FC;

typedef struct {
    Work_v1098 *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_022011FC mv;               /* 0x14 */
    int tag;                /* 0x28 */
} Ctx_022011FC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_v1098 e[14];            /* 0x008 */
    char pad[0x530 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x530 */
    char pad534[0x5a4 - 0x534];
    u8 tag[1];              /* 0x5a4 */
} Work_022012CC;

typedef struct {
    char body[0x3c];
} Mover_022012CC;

typedef struct {
    Work_022012CC *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover_022012CC mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx_022012CC;

typedef struct {
    int x, y, z;
} Vec_022011FC;

typedef struct {
    int v[2][3];
} Tab6;

typedef struct {
    int v[2][2][3];
} Tab12;

typedef struct {
    char pad00[0x30];
    int busy;           /* 0x30 */
    char pad34[0x1c];
    int target;         /* 0x50 */
    char pad54[0x08];
} Slot_02201098;

typedef struct {
    char *p;            /* 0x00 */
    u32 state : 31;     /* 0x04 */
    u32 sound : 1;
    int idx;            /* 0x08 */
    int dir;            /* 0x0c */
    int ang[3];         /* 0x10 */
    int cnt;            /* 0x1c */
    int step;           /* 0x20 */
} Work_02201408;

typedef struct Flags_02201098 { unsigned low:3; unsigned count:2; unsigned high:27; } Flags_02201098;

typedef struct GlobalFlags { unsigned low:2; unsigned disabled:1; unsigned high:29; } GlobalFlags;

typedef struct {
    int pad[2];
    void *h;
    char pad2[0x5C - 12];
} Row;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags_02201894;

typedef struct {
    char pad[0x510];
    Flags_02201894 flags;
} Unit_v1098;

typedef signed short s16_02201894;

typedef struct {
    u16 key : 14;
    u16 flag : 1;
    u16 hi : 1;
} Ent_02201894;

typedef struct Res_02201894 {
    void *owner;
    void *h;
    char pad[0x80 - 8];
    u16 heap;
} Res_02201894;

typedef struct Ent_02201AC4 { void *h8; void *hc; void *h10; void *h14; } Ent_02201AC4;

typedef struct Res_02201AC4 { void *owner; void *h; Ent_02201AC4 e[7]; } Res_02201AC4;

typedef short s16_02201B20;

typedef struct Config { s16_02201B20 x, y; u32 rest[2]; u32 a, b, last; } Config;

typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;

typedef struct Res_02201B20 { void *owner; void *h; Ent e[7]; } Res_02201B20;

typedef struct {
    int x, y, z;
} Vec_v1B20;

typedef signed short s16_02201DA0;

typedef struct { int x, y, z; } Vec;

typedef struct { void *owner; Vec start; int idx, mode; Vec a, b, delta; int n1, n2, zero, s2, s3; } Job;

typedef struct {
    int a, b;
    void *h;
    int d;
} Ent_02201DA0;

typedef struct {
    Ent_02201DA0 *tbl;   /* 0x00 */
    int x, y;   /* 0x04 */
    int pad;    /* 0x0c */
    int idx;    /* 0x10 */
    int mover[1]; /* 0x14 */
} Obj_02201DA0;

typedef struct Bits_02201DA0 { unsigned lo:9; unsigned k:4; unsigned rest:19; } Bits_02201DA0;

typedef struct Obj_022020A0 {
    void *h0;
    void *h4;
    char pad08[0x4c - 8];
    int a4c;
    int a50;
    int a54;
    char pad58[0x5c - 0x58];
    int a5c;
    char pad60[0x64 - 0x60];
    int a64;
    Bits_02201DA0 f68;
    char pad6c[0x70 - 0x6c];
    int a70;
    char pad74[0x104 - 0x74];
    int b104[5];
    char pad118[0x1b0 - 0x118];
    int b1b0[3];
    int b1bc;
    int b1c0;
    char pad1c4[0x1e0 - 0x1c4];
    int b1e0[4];
    int b1f0;
    int b1f4;
    char pad1f8[0x224 - 0x1f8];
    int a224;
    char pad228[0x23c - 0x228];
    int a23c;
    u16 heap;
    char pad242[0x274 - 0x242];
    int a274;
} Obj_022020A0;

typedef struct Res_02201DA0 { Obj_022020A0 *owner; int v; } Res_02201DA0;

typedef struct Obj_022021F4 {
    void *h0;
    void *h4;
    char pad[0x5c - 8];
    void *h5c;
    void *h60;
} Obj_022021F4;

typedef struct Ent_02202238 { char pad[0x20]; int f20; } Ent_02202238;

typedef struct Bits_0220266C { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_0220266C;

typedef struct Obj_0220266C {
    void *h0;
    char pad[0x68 - 4];
    Bits_0220266C f68;
    char pad2[0x240 - 0x6c];
    u16 heap;
} Obj_0220266C;

struct W { unsigned char pad[0x68]; unsigned int pad15 : 15; unsigned int f : 2; };

typedef struct F68 {
    u32 b0 : 1;
    u32 b1 : 3;
    u32 b4 : 1;
    u32 b5 : 4;
    u32 b9 : 4;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 mode : 2;
    u32 b17 : 2;
    u32 b19 : 2;
    u32 b21 : 2;
    u32 b23 : 4;
    u32 b27 : 5;
} F68;

typedef struct F6C {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 x : 8;
    u32 rest : 22;
} F6C;

typedef struct T12 {
    int v[3];
} T12;

typedef struct Task_v1DA0 {
    char *s;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    void *f1c;
    int f20;
} Task_v1DA0;

typedef struct Arg1 {
    T12 a[6];
    T12 b[6];
    int f90;
    int f94;
    u8 pad98[0xbc - 0x98];
    int fbc;
    u8 padc0[5];
    u8 bc5;
} Arg1;

typedef struct Arg2 {
    u16 h[4];
    int f8;
    int fc;
    int f10;
    int f14;
} Arg2;

typedef struct Arg5 {
    int a[3];
    int b[3][4];
} Arg5;

typedef struct S5 {
    u8 pad[0x2a4];
    int a[3];
    int b[3][4];
} S5;

typedef struct {
    char pad0[0xa];
    s8 id;              /* 0x0a */
    char padb;
} Ent_v1DA0;

typedef struct {
    void *key;          /* 0x00 */
    int f4;
    int *vals;          /* 0x08 */
} Cmd;

typedef struct {
    char pad0[0x50];
    int f50;            /* 0x50 */
    int f54;
    int mode;           /* 0x58 */
    char pad5c[0x64 - 0x5c];
    int f64;            /* 0x64 */
    u32 busy : 1;       /* 0x68 */
    u32 f68_1 : 30;
    u32 lock : 1;
    u32 f6c_0 : 1;      /* 0x6c */
    u32 flag : 1;
    u32 sel : 8;
    u32 f6c_10 : 22;
    int pending;        /* 0x70 */
    char pad74[0x242 - 0x74];
    u8 slot[3][8];      /* 0x242 */
    u8 en[8];           /* 0x25a */
    u8 en2[8];          /* 0x262 */
    char pad26a[0x27c - 0x26a];
    int cur;            /* 0x27c */
    int f280;           /* 0x280 */
} Obj_v1DA0;

typedef struct Main_02203040 {
    unsigned char pad00[0x60];
    int f60;
    int f64;
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int pad4 : 11;
    unsigned int mode : 2;
    unsigned int pad17 : 6;
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int top : 1;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_02203040;

typedef struct Pair_02201B20 {
    int x;
    int y;
} Pair_02201B20;

typedef struct Tbl_v1DA0 {
    Pair_02201B20 p[3];
} Tbl_v1DA0;

typedef struct Main_022030F0 {
    void *owner;
    unsigned char pad04[0x58 - 4];
    int f58;
    unsigned char pad5c[0x64 - 0x5c];
    int f64;
    u32 b0 : 1;
    u32 lo : 4;
    u32 f5 : 4;
    u32 mid : 10;
    u32 mode : 2;
    u32 hi : 10;
    u32 b31 : 1;
    u32 f6c;
    int f70;
    unsigned char pad74[0x220 - 0x74];
    int f220;
    unsigned char pad224[0x242 - 0x224];
    u8 tbl[3][8];
    u8 b25a[8];
    u8 b262[4];
    unsigned char pad266[0x27c - 0x266];
    int f27c;
    unsigned char pad280[0x2a4 - 0x280];
    void *f2a4[3];
} Main_022030F0;

typedef struct Desc_02201B20 {
    void *a;
    void *b;
    const int *c;
} Desc_02201B20;

/* The rodata objects at 0x0220A380..0x0220A3B4 are one section to the compiler: loads go
 * through the section base (sec_0220A380 + field) and addresses taken get their own words;
 * the 3-byte object at the section start is a second name at the same address. */
typedef struct Sec {
    u8 b0[3];
    u8 key[3];
    u8 pal[3][2];
    u8 mode[3][2];
    u16 h[5];
    Desc_02201B20 da;
    Desc_02201B20 db;
} Sec;

typedef struct Bits_02201B20 { unsigned b0:1; unsigned mid:30; unsigned b31:1; } Bits_02201B20;

typedef struct Obj { char pad[0x64]; void *h64; Bits_02201B20 f68; } Obj;

typedef struct Main_022033F4 {
    unsigned char pad00[0x48];
    void *f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;
    unsigned char pad68[0x104 - 0x68];
    int h104;
    int h108;
    int h10c;
    int h110;
    int h114;
    int h118;
    unsigned char pad11c[0x1e0 - 0x11c];
    int h1e0[4];
    int h1f0;
    int h1f4;
    unsigned char pad1f8[0x23c - 0x1f8];
    int f23c;
    u16 heap;
    unsigned char pad242[0x284 - 0x242];
    unsigned char buf284[0x20];
} Main_022033F4;

typedef struct Main_022035C0 {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_022035C0;

typedef struct Ctx_022033F4 {
    Main_022035C0 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_022033F4;

typedef signed short s16_022033F4;

typedef struct Main_v33F4 {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[4];
    int mode;
    unsigned char pad54[0x64 - 0x54];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_v33F4;

typedef struct Ctx_022036C4 {
    Main_v33F4 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_022036C4;

typedef struct Main_02203880 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4c[0x68 - 0x4c];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[0x240 - 0x22c];
    u16 h240;
} Main_02203880;

typedef struct Ctx_02203880 {
    Main_02203880 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_02203880;

typedef struct Main_02203978 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4c[0x68 - 0x4c];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_02203978;

typedef struct Ctx_02203978 {
    Main_02203978 *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx_02203978;

typedef struct Main_02203A78 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x50 - 0x4C];
    int f50;
    unsigned char pad54[0x228 - 0x54];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main_02203A78;

typedef struct Ctx_02203A78 {
    Main_02203A78 *main;
    unsigned char pad04[0xC - 0x4];
    int f0c;
} Ctx_02203A78;

typedef struct Main_02203B08 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x1f8 - 0x4C];
    void *obj1f8;
    unsigned char pad1FC[0x228 - 0x1FC];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main_02203B08;

typedef struct Ctx_02203B08 {
    Main_02203B08 *main;
    int state;
    int f8;
    int fc;
} Ctx_02203B08;

typedef struct Main_02203BC0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main_02203BC0;

typedef struct Ctx_02203BC0 {
    Main_02203BC0 *main;
    int state;
} Ctx_02203BC0;

typedef struct Main_02203C2C {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main_02203C2C;

typedef struct Ctx_02203C2C {
    Main_02203C2C *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
    int f1c;
    int mode;
} Ctx_02203C2C;

typedef struct Main_v3880 {
    void *owner;
    char pad04[0x60];
    void *pal64;
    unsigned int f0:1, st:3, hi:28;
    char pad6c[0x1bc];
    void *obj228;
} Main_v3880;

typedef struct { Main_v3880 *main; int state; } Ctx;

typedef signed short s16_02203E30;

typedef struct Main_02203E30 {
    void *owner;
    char pad04[0x44];
    u32 f48;
    char pad4c[0x18];
    void *pal64;
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
    char pad22c[0x14];
    u16 h240;
} Main_02203E30;

typedef struct { Main_02203E30 *main; int state, f8, fc, f10, f14, timer; } Ctx_02203E30;

typedef struct { int a, b; } Pair_022033F4;

typedef struct Main_02203FDC {
    void *owner;
    char pad04[0x44];
    u32 f48;
    char pad4c[0x18];
    void *pal64;
    unsigned int f0:1, st:3, hi:28;
    char pad6c[0x1b8];
    void *obj224, *obj228, *obj22c;
    char pad230[0x10];
    u16 h240;
} Main_02203FDC;

typedef struct { Main_02203FDC *main; int state, f8, fc, f10, f14, timer; void *obj1c; } Ctx_02203FDC;

typedef struct Main_022041E0 {
    char pad00[0x48];
    u32 f48;
    char pad4c[0x1c];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
    char pad22c[0x14];
    u16 h240;
} Main_022041E0;

typedef struct { Main_022041E0 *main; int state, f8, fc, f10, f14, timer; } Ctx_022041E0;

typedef struct Main_022042E4 {
    char pad00[0x68];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
} Main_022042E4;

typedef struct { Main_022042E4 *main; int state; } Ctx_022042E4;

typedef struct Main_022043C0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022043C0;

typedef struct Obj_02203E30 {
    Main_022043C0 *main;
    int f4;
    int f8;
    int fc;
    int f10;
} Obj_02203E30;

typedef struct Ctx_02204438 {
    char *main;
    int cur;
    int target;
    int step;
    int ang;
} Ctx_02204438;

typedef struct Bits_022044A0 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_022044A0;

typedef struct Main_022044C0 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022044C0;

typedef struct Obj_022044C0 {
    Main_022044C0 *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Obj_022044C0;

typedef struct Ctx_0220453C {
    char *main;
    int state;
    int a8;
    int ac;
    int d10;
    int cnt;
} Ctx_0220453C;

typedef struct Bits_02204588 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204588;

typedef struct Main_022045A8 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_022045A8;

typedef struct Obj_022045A8 {
    Main_022045A8 *main;
    int idx;
    int set;
    int cnt;
} Obj_022045A8;

typedef struct Ent_v3E30 {
    int v0;
    int v1;
} Ent_v3E30;

typedef struct Ctx_0220461C {
    char *main;
    int idx;
    int set;
    int cnt;
} Ctx_0220461C;

typedef struct Bits_02204678 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204678;

typedef struct Bits_02204698 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204698;

typedef struct Obj_02204698 {
    void *h0;
    char pad04[0x68 - 4];
    Bits_02204698 f68;
    char pad6c[0x104 - 0x6c];
    int h104;
    int h108;
    int h10c;
    char pad110[0x240 - 0x110];
    u16 heap;
} Obj_02204698;

typedef struct Quad { u16 v[4]; } Quad;

typedef struct Pos_02203E30 { short x; short y; } Pos_02203E30;

typedef struct Row_02201B20 { Pos_02203E30 pos[6]; int val[2]; } Row_02201B20;

typedef struct Res_02203E30 { Obj_02204698 *owner; void *h; void *e[6]; } Res_02203E30;

typedef struct Main_022047F8 {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
} Main_022047F8;

typedef struct Ctx_022047F8 {
    Main_022047F8 *main;
    int h4;
    void *ent[6];
} Ctx_022047F8;

typedef struct Main_02204838 {
    void *f0;
    unsigned char pad04[0x68 - 4];
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main_02204838;

typedef struct Obj_02204838 {
    Main_02204838 *main;
    int f4;
} Obj_02204838;

typedef short s16_022044A0;

typedef struct Main_022048A4 {
    unsigned char pad00[0x68];
    u32 f68;
} Main_022048A4;

typedef struct Ctx_022048A4 {
    Main_022048A4 *main;
    int f4;
} Ctx_022048A4;

typedef struct Bits_02204940 { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204940;

typedef struct Main_02204960 {
    unsigned char pad00[0x240];
    u16 h240;
} Main_02204960;

typedef struct Obj_02204960 {
    Main_02204960 *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Obj_02204960;

typedef struct Ctx_022049C8 {
    void *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Ctx_022049C8;

typedef struct Bits_02204A3C { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_02204A3C;

typedef struct Bits_02204A70 { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits_02204A70;

typedef struct Main_02204A88 {
    unsigned char pad00[0x210];
    void *o210;
    void *o214;
} Main_02204A88;

typedef struct Ctx_v3E30 {
    Main_02204A88 *main;
} Ctx_v3E30;

typedef struct Bits_02204AEC { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits_02204AEC;

typedef struct Main_02204B0C {
    void *owner;
    unsigned char pad04[0x68 - 4];
    u32 b0 : 1;
    u32 lo : 18;
    u32 mode : 2;
    u32 hi : 11;
    unsigned char pad6c[0x240 - 0x6c];
    u16 h240;
} Main_02204B0C;

typedef struct Obj_02204A70 {
    Main_02204B0C *main;
} Obj_02204A70;

typedef int BOOL;

typedef short s16_02204CC0;

typedef struct Point_02201B20 { s16_02204CC0 x, y; } Point_02201B20;

typedef struct Pos_02204C98 { int x, y; } Pos_02204C98;

typedef struct PosTab { Pos_02204C98 v[4]; } PosTab;

typedef struct { int w[9]; } Struct36;

typedef struct Slots {
    u16 id[4];
    u8 a[4];
    u8 b[4];
} Slots;

typedef struct Work_v3E30 {
    char pad0[0x50];
    int mode;           /* 0x50 */
    char pad54[0x5c - 0x54];
    void *msgdata;      /* 0x5c */
    char pad60[0x64 - 0x60];
    void *bg;           /* 0x64 */
    char pad68[0x1e0 - 0x68];
    u32 res[4];         /* 0x1e0 */
    u32 r1f0;           /* 0x1f0 */
    u32 r1f4;           /* 0x1f4 */
    void *sys;          /* 0x1f8 */
    void *obj[4];       /* 0x1fc */
    char pad20c[0x224 - 0x20c];
    void *fnt;          /* 0x224 */
    char pad228[0x22c - 0x228];
    void *win;          /* 0x22c */
    char pad230[0x240 - 0x230];
    u16 heap;           /* 0x240 */
    char pad242[0x25a - 0x242];
    u8 f25a[8];         /* 0x25a */
    u8 f262[4];         /* 0x262 */
} Work_v3E30;

typedef struct Entry_v3E30 {
    u8 kind : 2;
    u8 flag : 1;
    u8 pad0 : 5;
    u8 pad1[3];
    short show;
    short pad6;
    void *text;
} Entry_v3E30;

typedef struct Info_v3E30 {
    Entry_v3E30 e[6];
    u8 b48;
    u8 b49;
} Info_v3E30;

typedef struct Bits6C {
    u32 lo : 2;
    u32 x : 8;
    u32 hi : 22;
} Bits6C;

typedef struct Out {
    u32 pad[3];
    int fc;
} Out;

typedef struct Res_02204C98 {
    u32 pad[3];
    u16 *fc;
} Res_02204C98;

typedef signed short   s16_022050F0;

typedef short s16_02205340;

typedef struct Main_v3E30 {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x224 - 0x4C];
    int o224;
    unsigned char pad228[0x22c - 0x228];
    int o22c;
    unsigned char pad230[0x240 - 0x230];
    u16 h240;
    unsigned char pad242[0x25a - 0x242];
    u8 b25a;
    u8 b25b;
} Main_v3E30;

typedef signed short s16_022053DC;

typedef struct { u16 value[4]; u8 a[4], b[4]; u8 pad10[8]; } Buffer;

typedef struct { u8 first, second; } Palette;

typedef struct { char pad[0x68]; u32 lo : 19; u32 index : 2; } Flags_02201B20;

typedef struct Main_022053DC {
    void *owner;
    unsigned char pad04[0x64 - 4];
    int f64;
    unsigned char pad68[0x6c - 0x68];
    u32 f6c;
    unsigned char pad70[0x228 - 0x70];
    int o228;
    int o22c;
    int o230;
    int o234;
    unsigned char pad238[0x25a - 0x238];
    u8 b25a[8];
    u8 b262[4];
} Main_022053DC;

typedef short s16_022057CC;

typedef struct Point_022053DC { s16_022057CC x, y; } Point_022053DC;

typedef struct Pair { void *obj; u32 pad; } Pair;

typedef struct Main_022057CC {
    unsigned char pad00[0x50];
    int mode;
    unsigned char pad54[0x64 - 0x54];
    void *pal;
    unsigned char pad68[0x1b0 - 0x68];
    u32 h1b0[3];
    u32 h1bc;
    u32 h1c0;
    u32 h1c4;
    Pair h1c8[3];
    unsigned char pad1e0[0x240 - 0x1e0];
    u16 heap;
} Main_022057CC;

typedef struct Info_v53DC {
    unsigned char pad00[0x98];
    u32 species[3];
    u32 form[3];
    u32 gender[3];
    int sel;
} Info_v53DC;

typedef struct { void *entry; int extra; } Entry;

typedef struct { char pad[0x1c8]; Entry entries[3]; } Work_02201B20;

typedef struct Five { int v[5]; } Five;

typedef struct Bits_022053DC { u32 low : 1; u32 count : 3; u32 high : 28; } Bits_022053DC;

typedef struct { void *h; } E_02201B20;

typedef struct { char pad[0x210]; E_02201B20 a[2]; } W_022053DC;

typedef struct { void *h; int x; } Slot;

typedef struct {
    int v[6];
} Q_v53DC;

typedef struct { void *h; int x; } E_02205F40;

typedef struct { char pad[0x180]; E_02205F40 a[6]; } W_02205F40;

typedef struct { void *h; } E_02205F64;

typedef struct { char pad[0x1fc]; E_02205F64 a[4]; } W_02205F64;

typedef short s16;

typedef struct Point_02205F40 { s16 x, y; } Point_02205F40;

typedef struct {
    char p0[0x58];
    int f58;
    char p5c[0x68 - 0x5c];
    u32 lo : 4;
    u32 b4 : 1;
    u32 cur : 4;
    u32 prev : 4;
    u32 redraw : 1;
    u32 rest68 : 18;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest6c : 30;
    char p70[0x17c - 0x70];
    void *f17c;
    char p180[0x220 - 0x180];
    int f220;
    char p224[0x242 - 0x224];
    u8 tbl[3][8];
    u8 f25a[8];
    u8 f262[4];
    u16 f266[3];
    u16 f26c[4];
    u8 *f274;
    int f278;
    int f27c;
} W_02206140;

typedef struct {
    u8 (*tab)[4];
    int *flags;
} Ctx_v53DC;

typedef short s16_022064CC;

typedef struct Point_022064CC { s16_022064CC x, y; } Point_022064CC;

typedef struct {
    char p0[0x68];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x180 - 0x6c];
    Slot slots[6];
    char p1b0[0x274 - 0x1b0];
    u8 *f274;
} W_022064CC;

typedef struct {
    unsigned int lo : 31;
    unsigned int top : 1;
} Top;

typedef struct {
    char *s;
    int f4;
    int f8;
    int fc;
} Ctx_022064CC;

typedef signed short s16_0220663C;

typedef struct PalAnmObj PalAnmObj;

typedef struct { char *p; int state, colour, flag; } Ctx_0220663C;

typedef struct { char pad[0x68]; unsigned int f68; } W_02206710;

typedef struct {
    unsigned int lo : 4;
    unsigned int b4 : 1;
} Bf_022064CC;

typedef struct {
    char p0[0x58];
    int f58;
    char p5c[0x68 - 0x5c];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x242 - 0x6c];
    u8 row[4][8];
    char p262[0x266 - 0x262];
    u16 a266[3];
    u16 a26c[8];
    int k;
} W_02206950;

typedef struct { s16 x, y; } Pt_02206BC8;

typedef struct {
    char pad00[0x40];
    int kind;
    char pad44[0x3c];
} Slot_02206BC8;

typedef struct {
    void *f00;
    void *h04;
    int f08;
    void *f0c;
    void *f10;
    int f14;
    int f18[6];
    int f30, f34, f38, f3c;
    Slot_02206BC8 slot[8];
    int f440;
    int f444;
    u16 heap;
} Obj_02206BC8;

typedef struct {
    Obj_02206BC8 *obj;
    int pad[3];
} Task_v64CC;

typedef enum { SLOT_6E28_0, SLOT_6E28_MAX = 8 } Slot_02206E28;

typedef struct {
    unsigned int lo : 2;
    unsigned int b2 : 1;
} Bf_02206BC8;

typedef struct Obj_02206EB4 Obj_02206EB4;

typedef struct {
    char pad[0xc];
    Obj_02206EB4 *h;
    char pad10[0x38];
    int a, b, f90;
    char pad54[0x1c];
    u32 b0:1, b1:1, b2:1, b3:1, lo:4, count:8, mid:4, b20:1, flash:5, b26:1, b27:1, b28:1, b29:1, hi:2;
    char pad74[0xc];
} Row_02206BC8;

typedef struct W_02206BC8 {
    char pad[0x40];
    Row_02206BC8 rows[8];
    struct { u32 lo:4, b4:1, mid:16, b21:1, b22:1, hi:9; } flags;
} W_02206BC8;

typedef struct O_022064CC O_022064CC;

typedef struct { char pad[0x40]; u32 mode, side, a, b, f90, f94, f98, f9c, fa0, fa4, fa8; u8 level, sex, fae, seen; u32 flags, fb4, fb8, fbc; } Row_022070C0;

typedef struct W_022070C0 { char pad[0x40]; Row_022070C0 rows[8]; } W_022070C0;

typedef struct S S;

typedef struct { short x, y; } Pt_022070C0;

typedef struct { u32 v; } Word;

typedef struct { char pad[0x40]; u32 mode, side, a, b, f90, f94, f98, f9c, fa0, fa4, fa8; u8 level, sex, fae, seen; u32 flags, fb4, fb8, fbc; } Row_022064CC;

typedef struct W_02207288 { char pad[0x40]; Row_022064CC rows[8]; } W_02207288;

typedef struct { short x, y; } Pt_022064CC;

typedef struct { s16 x, y, z; u8 pri, f7; } Cfg;

typedef struct {
    u32 f40, f44, f48, f4c, f50, f54;
    u32 f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry_v64CC;

typedef struct {
    u32 f0, f4;
    char pad08[0x10];
    u32 pal[6];
    u32 f30, f34, f38, f3c;
    Entry_v64CC entries[8];
    char pad440[8];
    u16 heap;
} Work_v64CC;

typedef struct {
    void *f40, *f44, *f48, *f4c, *f50, *f54;
    unsigned int f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry_v778C;

typedef struct { char pad[0x40]; Entry_v778C entries[8]; } Work_022064CC;

typedef struct E_022064CC {
    void *f00;
    char p04[0x0c];
    void *f10;
    char p14[0x30];
    int f44, f48, f4c, f50, f54, f58, f5c, f60, f64;
    char p68[8];
    u32 lo : 3;
    u32 b3 : 1;
    u32 mid : 12;
    u32 mode : 4;
    u32 hi : 12;
    char p74[8];
    void *f7c;
} E_022064CC;

typedef struct O_0220778C { char pad[0x40]; E_022064CC e[8]; } O_0220778C;

typedef struct {
    short x;
    short y;
} Pt_0220778C;

typedef struct {
    unsigned int lo : 3;
    unsigned int b3 : 1;
} Bf;

extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void *ARC_TOOL_LoadMember(u32, u32, u32);
extern void *G3D_SYSTEM_CreateResourceArc(u32, u32);
extern int G3D_SYSTEM_TransVramTexture(int *);
extern void *G3D_SYSTEM_CreateRender(void *, u32, void *);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void func_0207ADC4(int *);
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void func_0207DCF8(void *);
extern u32 sub_020307B0(void *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec_v6560 *p);
extern void func_02046EFC(struct Tagged *p);
extern u32 func_020307B0(void *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec_v6560 *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec_v6560 *p);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg_v6560 *a1);
extern u32 G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void func_02048AD0(struct Light *l);
extern unsigned int G3D_CAMERA_Delete(void *ptr);
extern void func_02048AFC(int, const int *);
extern void func_02048B44(int, int);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_02048AE8(void *, void *);
extern void func_02048B30(void *, int);
extern int func_0207CFB8(int, int);
extern int func_0207CBD0(int *);
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern u8 func_021B8FE4(u8 *p);
extern u8 func_021B8FF4(u8 *);
extern u8 func_021B9000(u8 *p);
extern u16 func_021BA020(char *, int);
extern u8 func_021B904C(u8 *p, int k);
extern u32 BTL_MAIN_GetRule(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern char *BTL_MAIN_GetFieldSituation(char **);
extern unsigned func_02030CB0(unsigned);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *PALANM_Create(u32 heap);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern int func_021BA1A8(char **p, int m);
extern void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3, u32 b0, u16 *b1, u16 heap);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void *func_02209224(u16 heap);
extern void *func_0220975C(void *a, u16 heap);
extern void PARTICLE_InitManager(u32);
extern void *func_020056A0(void (*)(void *, void *), void *, int);
extern void PM_VOICE_AllocBuffers(int n, u32 heap);
extern void PM_VOICE_FreeBuffers(void);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_022092E8(void *);
extern void func_0220977C(void *);
extern void PARTICLE_ExitManager(void);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(void *);
extern void * func_02030D28(struct Ctx *c);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void PARTICLE_Main(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);
extern int WAZA_TOOL_GetDamageType(int);
extern void func_02207B4C(char *p, int i, int n);
extern void func_02207B68(char *p, int i, int n);
extern void func_02207B84(void *, int, u32);
extern void func_02207BAC(void *, void *, int);
extern void func_022089AC(void *);
extern int func_02207C94(u8 *p);
extern void func_02207CC4(struct O *obj, int a, int c);
extern void func_02207D04(struct O *obj, int a, int idx);
extern void func_02208814(struct O *obj, int k, int idx);
void func_02208870(void *w, int sel);
extern int func_02207D60(u8 *, int);
extern int func_02208958(void *, int, int *, int *);
extern u32 func_02208DAC(u32 *p, u32 v);
extern void func_02209068(void *);
extern int func_022090A4(int *);
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16_021F6560 step, u8 b, u8 c, u16 d, void *ctx);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02209318(void *, int, int);
extern void func_022094BC(u8 *p, int i, int a, int b);
extern int func_02209500(struct W *w, int i);
extern int func_022088F4(void *);
extern void func_02208900(u32 obj, u32 v);
extern void func_0220893C(u32 obj, u32 v);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u16 b);
extern void func_02208918(char *p, int v);
extern void func_02208924(void *o, u32 v);
extern int func_021BA1EC(char **p);
extern int func_021BA20C(char **p);
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern void sub_02030EAC(struct Node *n);
extern void CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 func_0203F0A8(void);
extern u32 sub_0207C768(u32 a, u32 b);
extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
extern void VM_Init(struct ScriptVm *vm, void *user);
extern int VM_Control(struct ScriptVm *vm);
extern void *func_02011324(void *vm);
extern void VM_Delete(void *);
extern void VM_Start(struct ScriptVm *vm, u8 *pc);
extern void func_02082A48(u16 data, void *destp, u32 size);
extern void PM_VOICE_StopSlot(u32 i);
extern u32 VM_GetU32(struct Cursor *p);
extern void func_0207C9D0(int *a, int *b, int *c);
extern void VM_SetWait(char *p, int val);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern void *PARTICLE_CreateSystem(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
extern void PARTICLE_SetupSystemNoHandlers(void *, void *);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void PARTICLE_InitCamera(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u16 a6);
extern int BUTTON_MAN_GetBlock(char *p);
extern void func_0204047C(int idx, unsigned short val);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern u32 func_020407E8(u32 layer);
extern u32 func_02040804(u32 layer);
extern void func_02209784(int a, int b, int c);
extern void func_022097CC(int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_0207D63C(int reg, int a, int b, int c, int d);
extern void func_0206DF3C(int *p, int *q, int *r);
extern void func_022079C0(char *p, int i, Pt_021FB8F4 *pt);
extern void GFL_USE_StopAllSe(void);
extern void func_020061F8(int i);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern void VM_Jump(struct Cur *c, u32 v);
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
extern void VM_Call(struct Ring *r, unsigned int v);
extern u32 VM_Return(struct Ring *r);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void BTLV_SCU_ReloadGraphics(const u8 *a);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern int func_0220985C(void *);
extern int PARTICLE_GetEffectCount(int **p);
extern int func_02006238(void);
extern int GFL_USE_IsSeSlotBusy(unsigned);
extern u32 func_02006BD0(u32 i);
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern int func_0207CF3C(const Vec_021F6560 *a, const Vec_021F6560 *b);
extern void VEC_Normalize(const Vec_021F6560 *a, Vec_021F6560 *b);
extern int func_0207CA68(const Vec_021F6560 *a, const Vec_021F6560 *b);
extern u16 FX_AcosIdx(int a);
extern void func_0207CAE8(const Vec_021F6560 *a, const Vec_021F6560 *b, Vec_021F6560 *c);
extern void MTX_RotAxis43(void *m, const Vec_021F6560 *axis, int s, int c);
extern void MTX_MultVec43(const Vec_021F6560 *a, const void *m, Vec_021F6560 *out);
extern void BUTTON_MAN_SetRow2(void *p, struct S12 *q);
extern void BUTTON_MAN_SetRow5(void *p, struct S12 *q);
extern void BUTTON_MAN_GetRot(void *p, Vec16 *v);
extern void BUTTON_MAN_SetRow3Half(void *p, u16 *q);
extern void BUTTON_MAN_SetRot(struct Obj_vD04C *o, const struct Vec3 *v);
extern int BUTTON_MAN_GetScaleX(char *p);
extern unsigned short BUTTON_MAN_GetAlpha(char *p);
extern short BUTTON_MAN_GetAngle(char *p);
extern int BUTTON_MAN_GetScaleY(char *p);
extern void BUTTON_MAN_SetScaleX(char *p, int v);
extern void BUTTON_MAN_SetScaleY(char *p, int v);
extern void BUTTON_MAN_SetAlpha(struct Obj_vD04C *o, u16 v);
extern void BUTTON_MAN_SetAngle(struct Obj_vD04C *o, u32 v);
extern void BUTTON_MAN_GetPos(void *p, Vec_021F6560 *v);
extern void BUTTON_MAN_SetPos(void *p, const Vec_021F6560 *v);
extern short BUTTON_MAN_GetOffsetX(char *p);
extern void BUTTON_MAN_SetOffsetX(char *p, int v);
extern short BUTTON_MAN_GetOffsetY(char *p);
extern void BUTTON_MAN_SetOffsetY(char *p, int v);
extern void BUTTON_MAN_SetEmitterPos(void *p, const Vec_021F6560 *v);
extern int BUTTON_MAN_GetUserData(void *p);
extern void *PARTICLE_GetWorkBase(char *p);
extern void PARTICLE_DeleteSystem(u8 *p);
extern void func_020061E4(u32 a);
extern int GFL_USE_GetSeSlot(u32 a);
extern void func_0200616C(void *arg, int i);
extern u32 *GFL_USE_GetSeHandle(int i);
extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);
extern void NNS_SndHandleSetSeqPriority(char *p, unsigned int v);
extern void NNS_SndHandleSetTrackModDepth(struct Obj_vD04C *o, u32 v, u32 w);
extern void NNS_SndHandleSetTrackModSpeed(struct Obj_vD04C *o, u32 v, u32 w);
extern int _s32_div_f(int, int);
void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);
void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
fx32 FX_Div(fx32 numer, fx32 denom);
extern void func_0200F698(void *a, void *b);
extern void PARTICLE_ApplyLoadHandlers(u32 *p);
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetSysParam(char *p, int v);
extern void MCSS_SetSysFlag(void *o, int v);
extern void MCSS_Exit(u8 *a0);
extern void MCSS_RestartAnime(void *h);
extern void MCSS_Main(char *self);
void MCSS_Draw(struct McssSys *sys);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_02017EAC(void *p);
extern u32 func_02019C90(u16, u16, u32);
extern int func_0202D034(u32, u32);
extern struct Rec_vE254 *MCSS_Add(struct Obj_vE254 *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void MCSS_SetShadowAlpha(char *p, int v);
extern void MCSS_SetShadowOffset(char *p, int *src);
extern void MCSS_SetShadowRotateZ(char *p, u16 value);
extern void func_02015F2C(void *, u32, void *, u32);
extern void MCSS_Del(void *obj, void *h);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_SetOrthoMode(void *obj);
extern void MCSS_ResetOrthoMode(void *obj);
extern void MCSS_SetOrthoBillboardFlag(void *h);
extern void MCSS_ResetOrthoBillboardFlag(void *h);
extern void MCSS_SetMepachiFlag(void *p);
extern void MCSS_ResetMepachiFlag(void *p);
extern void MCSS_FlipMepachiFlag(void *p);
extern int MCSS_GetAnmStopFlag(void *h);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetAnmStopFlagAlways(void *p);
extern void MCSS_ResetAnmStopFlagAlways(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern int MCSS_GetVanishFlag(void *h);
extern void MCSS_SetVanishFlag(void *h);
extern void MCSS_ResetVanishFlag(void *h);
extern void MCSS_FlipVanishFlag(void *h);
extern void MCSS_SetShadowVanishFlag(char *p, int v);
extern void MCSS_SetAnimeSpeed(char *p, int v);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_GetShadowScale(void *p, u32 *out);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_GetRotate(void *p, u32 *out);
extern void func_022089BC(char *p, int i);
extern u8 MCSS_GetAlpha(void *p);
extern u8 MCSS_GetMosaic(void *p);
extern int MCSS_CheckPaletteFade(void *h);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void MCSS_CreatePaletteTransTask(void *obj, void *h, int a, int b);
extern void MCSS_CreatePaletteCopyTask(u8 *a0, u8 *a1);
extern int MCSS_GetStopCellFlags(void *h);
extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);
extern void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);
extern int POKEGRA_GetArcID(void);
extern void MCSS_SetMosaic(void *obj, void *h, int v);
extern void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);
extern int func_021B994C(void *p, int key, u32 *out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void PM_VOICE_AddVolume(u32 idx, int delta);
extern void PM_VOICE_AddFrequency(u32 idx, u32 delta);
extern void MCSS_TOOL_MakeAddWorkFromPP(void *p, struct Stats *out, u32 lvl);
extern int MCSS_GetAnimSeqNumEx(void *h);
extern void MCSS_SetAnimeIndex(void *h, u32 n);
extern void MCSS_GetOfsPosition(void *p, u32 *out);
extern void MCSS_SetOfsPosition(void *p, u32 *src);
extern void MCSS_SetWorkFlag(void *h, int flag);
extern void MCSS_TOOL_MakeAddWorkFromTrainer(void *p, struct Stats *out, void *q);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetOfsScale(void *p, u32 *src);
extern void MCSS_SetShadowScale(void *p, u32 *src);
extern void MCSS_GetDrawScale(void *p, u32 *out);
extern void MCSS_SetDrawScale(void *p, u32 *src);
extern void MCSS_SetRotate(void *p, u32 *src);
extern void MCSS_SetAlpha(char *p, int v);
extern void *MCSS_GetAnimCtrl(void *);
extern void MCSS_SetCellCallback(char *p, unsigned flags, void *callback);
extern void MCSS_SetAnimeIndex(void *, u32);
extern u8 MCSS_GetStopCellNum(char *p);
extern u16 MCSS_GetAnimSeqNum(char *p);
extern u8 MCSS_GetStopCellIndex(char *p, u8 i);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
void CLACT_DrawSystem(void);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern u32 CLACT_SetActorAnimSeq(void *obj, u16 v);
extern void func_0204B404(struct Obj_02201DA0 *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorScale(struct Obj_02201DA0 *dst, struct Pair_02201B20 *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void func_02209B30(void *);
extern void INFOWIN_Update(void *);
extern void func_0203FC6C(const struct BgVramReq *req, u32 which);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void INFOWIN_Init(u8, u8, void *, u16);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern int INFOWIN_Exit(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204152C(int channel, u16 val);
extern void func_020403F4(u32 i);
extern int func_0207D55C(volatile u16 *reg);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int PALANM_RequestFadeOverwrite(void *, u16, u16, s16_02201DA0, u8, u8, u16, void *);
extern u32 CLACT_GetUnitDrawEnable(struct Bank *bank);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_Print(void *x, s16_02201DA0 y, s16_02201DA0 z, void *s, void *w);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int TOUCHPANEL_HitTrg(const void *p);
extern unsigned int func_0203630C(void);
extern int func_02209A7C(int a, int b, int c);
extern int func_02209B60(int h, int x, int y, int k, int m, int n);
extern int func_02209C2C(int h);
extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern int PALANM_GetDefaultWork(char *p, int i);
extern void func_02082A60(const void *, void *, u32);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern u32 func_020275E4(void);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern u32 func_020275E8(void);
extern u32 func_020275F8(u32);
extern void func_0207AD58(void *dst, int a, int b);
extern void func_02040820(u32 layer, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern int FADE_IsActive(void);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern int func_0207C994(int n, int d);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201BD28(u16 id, u32 field);
extern u8 func_020275EC(int i);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(u32 p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 func_021D5528(u8 *, u8, u8 *, u8 *);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern int func_0201BC3C(void);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void BMP_Delete(struct Obj020437AC *p);
extern unsigned int func_0203633C(void);
extern int func_02207D78(char *p, int i);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32 i);
extern u32 func_020276C0(u32 i);
extern u32 func_020276B4(void);
extern void PALANM_BlendChannelMask(unsigned, unsigned, u16, unsigned, unsigned);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 GFL_USE_GetBgmNo(void);
extern void func_02208BFC(void *, void *);
extern void func_02208D24(int a);
extern void func_02208D50(W_02206BC8 *, int, int);
extern int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
extern void func_022082FC(struct O_022064CC *o, int idx, int k);
extern void func_02207E1C(struct O_022064CC *obj, int idx);
extern void func_02207EF0(struct O_022064CC *obj, int idx);
extern void func_022086F8(O_022064CC *, int);
extern void func_022087C4(char *, int);
extern void func_022089D4(W_02206BC8 *);
extern int func_021D59B4(u8 *p, int k);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern u32 func_02018584(u16, u16, u16);
extern int BTL_MAIN_CheckZukanSeen(char *p, void *m);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work_v64CC *p);
extern u8 POKE_TOOL_GetGender(void *);
extern Word BTL_POKEPARAM_GetSickContRaw(void *, int);
extern int BTLV_CORE_IsSlotKind1Index15(Word);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern u32 POKE_TOOL_GetStatusCondition(void *);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_022080F4(O_0220778C *, E_022064CC *, void *);
extern void func_02208268(O_0220778C *, E_022064CC *);
extern void func_02208420(O_0220778C *, E_022064CC *, int);
extern void func_02208550(O_0220778C *, E_022064CC *);
extern void func_02208650(O_0220778C *, E_022064CC *);
extern void func_02208B10(void *, void *);
extern int func_02208D38(int a, int b, int c);
Obj_021F6560 *func_021F6560(int mode, int group, int variant, u16 heap);
void func_021F6898(Obj_021F6898 *o);
void func_021F6934(Obj_021F6934 *o);
void func_021F69B0(Obj_021F69B0 *p);
void func_021F69E8(S69E8 *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);
int func_021F6A18(char *p);
void func_021F6A28(Obj_021F6A28 *o, u32 mode, u32 on);
void func_021F6AA8(Obj_021F6AA8 *p, int i, int j, int a, int b);
int func_021F6AD0(Obj_021F6AD0 *p);
Obj_021F6B04 *func_021F6B04(int unused, int group, u8 variant, u16 heap);
void func_021F6CF0(Obj_021F6CF0 *o);
void func_021F6D5C(Obj_021F6D5C *o);
void func_021F6DD4(Obj_021F6DD4 *p);
void func_021F6DEC(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d);
int func_021F6E1C(char *p);
void func_021F6E2C(Obj_021F6E2C *o, u32 v);
Obj_021F6E3C *func_021F6E3C(int a, u16 b);
void func_021F6EC0(void **p);
void func_021F6ED4(int *p);
void func_021F6EDC(int *p, int *a, int *b);
void func_021F6F20(Obj_021F6F20 *p, int a, int b);
void func_021F6F48(Cam_021F6F48 *c, VecFx32_v6560 *a, VecFx32_v6560 *b, int n, int s, int t);
void func_021F7000(Cam_021F7000 *c, int mode, fx32 v, int unused, int n, int g, int h);
void func_021F70F0(void **p, void *b, int c);
void func_021F7108(int *p, int a, int b, int *out, int *base);
void func_021F7208(VecFx32_v6560 *a, VecFx32_v6560 *b);
int func_021F722C(char *p);
void func_021F723C(int *p);
void func_021F73A4(int *p);
Obj_v6560 *func_021F73F0(int a, int b, Q_v6560 *q, int c, u16 *h, int e, int f, u16 heap);
void *func_021F745C(u8 *p, int a, u16 heap);
void func_021F7544(Param *p, int arg, u16 heap);
void func_021F7808(void);
void func_021F78E4(void);
void func_021F7998(u32 a);
void func_021F7A28(int a, u32 b);
void func_021F7AAC(int a, int b, u32 c);
void func_021F7B2C(const Req_021F7208 *r);
void func_021F7BEC(void);
void func_021F7C0C(void);
void func_021F7C2C(int a, int b);
void func_021F7CE4(int a);
void func_021F7CFC(u32 a, u16 b, u8 c, int d, int e);
void func_021F7D44(int a, unsigned short b);
void func_021F7D80(void *a, int b);
void func_021F7E38(void *a, int b);
void func_021F7E74(u32 a);
void func_021F7E84(u32 a);
void func_021F7E94(int a);
void func_021F7EA4(u32 a);
int func_021F7EB4(void);
void func_021F7EE8(void *m, int key);
void func_021F7F04(int a);
int func_021F7F1C(int i);
void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);
void func_021F8010(int a);
void func_021F803C(u32 a, void *m, u32 c);
void func_021F8090(u32 a, u32 b, u32 c);
void func_021F80E4(u32 a);
void func_021F80FC(u32 a, u32 b);
void func_021F8118(u32 a, u32 b);
void func_021F8134(int index, u32 amount);
void func_021F8150(int index, void *obj);
void func_021F8168(void);
int func_021F8180(void);
void func_021F8198(int a, int b);
void func_021F81B4(u32 a, u32 b);
void func_021F81D0(u32 a, u32 b);
void func_021F81EC(int sel);
int func_021F8204(int index);
int func_021F821C(int a, int *b, int *c);
void func_021F823C(u32 *p);
void func_021F8260(u32 i);
int func_021F827C(u32 i);
void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e);
int func_021F8324(u32 a);
void func_021F839C(u32 a, u32 b);
void func_021F8414(int a, int b, int c);
void func_021F84B4(u32 a, u32 b);
int func_021F84D0(int a);
void func_021F84E8(int a, int b);
void func_021F8504(u32 a, u32 b, u32 c);
int func_021F8524(int i);
int func_021F853C(int a);
void func_021F8554(u32 flags, int kind, int n, int s, int t);
void func_021F8628(u32 a, int *out, int *p);
void *func_021F8678(void);
int func_021F8684(void);
int func_021F8694(void);
int func_021F86A4(void);
int func_021F86B4(void);
int func_021F86C4(void);
void *func_021F86D4(void);
int func_021F86E0(void);
int func_021F86F0(void);
int func_021F8700(void);
int func_021F8710(void);
int func_021F8720(void);
int func_021F8730(void);
unsigned short func_021F8740(int a);
int func_021F8754(void);
int func_021F8764(void);
void func_021F8774(void);
void func_021F878C(u32 a);
void func_021F87D4(u32 v);
void func_021F87EC(u32 v);
int func_021F882C(void);
void func_021F883C(u32 a);
void func_021F8884(int a);
int func_021F88A8(void);
void func_021F88BC(int a);
int func_021F88E0(void);
int func_021F88F4(void);
int func_021F8914(void);
void func_021F8934(int a);
void func_021F896C(void *h, void (*cb)(void *), int arg);
int func_021F899C(void *h);
void func_021F89BC(void *h);
void func_021F8A10(int a);
void func_021F8A40(int a);
void func_021F8A78(void);
void func_021F8AC0(int a);
void func_021F8AE8(int i, u32 v);
int func_021F8AFC(int i);
void func_021F8B10(void);
void func_021F8B28(void);
int func_021F8B40(void);
void func_021F8B6C(void);
void func_021F8B90(void *h, void *arg);
void func_021F8BAC(void *h, void *arg);
void func_021F8C78(void *h);
void func_021F8CB0(void *h, void *arg);
void func_021F8EF8(void *h);
void func_021F8F30(void *h, void *p);
void func_021F8FB0(void *h);
void func_021F8FE8(void *h, void *arg);
void func_021F9028(void *h);
void func_021F903C(void);
void func_021F9154(int a, int b, int *out, int c);
void func_021F918C(const VecFx32_021F8F30 *a, const VecFx32_021F8F30 *b, VecFx32_021F8F30 *out, fx32 div);
void func_021F9220(int *p, int *d, int *lim, int *flag);
int func_021F9260(Mover_v8204 *m, VecFx32_021F8F30 *out);
int func_021F935C(int x);
void func_021F9364(P *p);
void *func_021F93F4(void *a, u32 b);
int func_021F9478(void *vm);
void func_021F94D8(void *a);
void func_021F94F8(void *vm, u32 a1, u32 a2, u16 id, Quad_v8204 *q);
void func_021F97E4(void *a);
void func_021F9814(void *a);
int func_021F9824(void *a);
void func_021F9844(S9844 *p);
void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d);
void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration);
void func_021F9A7C(void *a);
void func_021F9AA4(void *a);
int func_021F9AB8(void *r, Ctx_021F9814 *c);
int func_021F9EFC(void *r, Ctx_021F9EFC *c);
int func_021F9FC0(void *r, Ctx_v9814 *c);
int func_021FA048(void *r, Ctx_v9814 *c);
int func_021FA09C(void *a, State *s);
int func_021FA108(int a, char *b);
int func_021FA12C(void *a, char *s);
int func_021FA288(void *a, char *s);
int func_021FA358(void *a, char *s);
int func_021FA458(void *a, char *s);
int func_021FA5D0(void *a, char *s);
int func_021FA758(void *a, char *s);
int func_021FA794(void *a, char *s);
int func_021FA884(void *a, char *s);
int func_021FA988(void *a, char *s);
int func_021FAB0C(void *a, char *s);
void func_021FAC94(void *a, void *b);
void func_021FACA0(void *a, void *b);
int func_021FACAC(void *a, State_021FA758 *s);
int func_021FAD2C(void *a, State_021FA758 *s);
int func_021FADC0(void *a, State_021FA758 *s);
int func_021FAE48(void *a, State_021FA758 *s);
int func_021FAECC(void *a, State_021FA758 *s);
int func_021FAF44(void *a, State_021FA758 *s);
int func_021FAFBC(void *a, State_021FA758 *s);
int func_021FB034(void *a, State_021FA758 *s);
int func_021FB09C(void *a, State_021FA758 *s);
int func_021FB0E8(void *a, State_021FA758 *s);
int func_021FB168(void *a, State_021FA758 *s);
int func_021FB1C4(struct Cursor *a, char *b);
int func_021FB214(struct Cursor *a, char *b);
int func_021FB298(void *a, char *s);
int func_021FB2D0(struct Cursor *a, char *b);
int func_021FB328(struct Cursor *a, char *b);
int func_021FB390(void *a, char *s);
int func_021FB3C8(void *a, char *s);
int func_021FB3DC(struct Cursor *a, char *b);
int func_021FB49C(struct Cursor *a, char *b);
int func_021FB500(void *a, char *s);
int func_021FB524(void *a, char *s);
int func_021FB550(void *a, char *s);
int func_021FB574(struct Cursor *a, unsigned int *b);
int func_021FB5D4(struct Cursor *a, char *b);
int func_021FB624(void *a, char *s);
int func_021FB648(struct Cursor *a, char *b);
int func_021FB6F4(struct Cursor *a, char *b);
int func_021FB790(struct Cursor *a, char *b);
int func_021FB7F8(struct Cursor *a, char *b);
int func_021FB864(void *a, char *s);
int func_021FB894(struct Cursor *a, State_021FB3C8 *s);
int func_021FB8F4(void *a, char *s);
int func_021FB91C(void *r, State_021FB91C *s);
int func_021FBA64(struct Cursor *a, State_021FBA64 *s);
int func_021FBAD8(void *a, char *s);
int func_021FBAF8(void *a, char *s);
int func_021FBC78(struct Cursor *a, State_021FBC78 *s);
int func_021FBCEC(void *a, char *s);
int func_021FBD10(void *a, char *s);
void func_021FBD34(void *a, char *s);
int func_021FBD44(struct Cursor *a, State_021FB8F4 *s);
int func_021FBD88(struct Cursor *a, State_021FB8F4 *s);
void func_021FBDD4(int a, int b, int c, int op, int e);
int func_021FBE28(struct Cursor *a, char *s);
int func_021FBE60(void *a, char *s);
int func_021FBE74(void *a, char *s);
int func_021FBE90(struct Cursor *a, State_021FBE28 *s);
int func_021FBF48(struct Cursor *a, State_021FB8F4 *s);
int func_021FBFA0(int a, char *b);
int func_021FBFC0(void *a, char *s);
int func_021FC134(void *a, char *s);
int func_021FC148(struct Cursor *a, State_021FC148 *s);
int func_021FC20C(struct Ring *a, State_021FC20C *s);
int func_021FC2DC(int a, State_021FC2DC *s);
int func_021FC334(struct Cursor *a, char *s);
int func_021FC354(void *a, char *s);
int func_021FC374(void *a, char *s);
int func_021FC3D8(struct Cursor *a, State_021FC3D8 *s);
int func_021FC434(void *a, char *s);
int func_021FC448(void *a, State_021FC448 *s);
int func_021FC744(int a, State_021FC744 *s);
int func_021FC9D0(void *a, char *s);
int func_021FC9E4(void *a, Flags_021FC9E4 *s);
int func_021FC9F4(void *a, Flags_021FC9F4 *s);
int func_021FCA04(State_021FC9F4 *s, int cmd, int *out);
int func_021FCD14(State_021FC9F4 *s, int unused, int *out);
int func_021FCF2C(int a, int idx);
int func_021FD04C(Unit_021FD04C *s, int i);
int func_021FD070(int a, int b);
int func_021FD088(int a, int *out);
int func_021FD15C(Tbl_vD04C *p, int key, int *out);
void func_021FD19C(char *p, int i, char *q);
int func_021FD1A8(char *p, int v);
int func_021FD1C0(char *p, int i);
void func_021FD1CC(void *p);
void func_021FD8CC(void *p, int active);
void func_021FD9F0(void *p);
void func_021FDA28(void *p, int active);
void func_021FDB08(void *p);
void func_021FDB20(State_021FDB20 *s);
void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g);
int func_021FDBB0(State_021FDBB0 *s, unsigned int key);
void func_021FDD60(State_021FDD60 *s, Rec_021FDD60 *r, int slot, int arg);
int func_021FDFA0(void *a, char *s, int mode);
void func_021FE1B8(VecFx32_021FE1B8 *v, const VecFx32_021FE1B8 *ofs);
void func_021FE254(const VecFx32 *v, const MtxFx44 *m, fx32 *out, fx32 *w);
unsigned int func_021FE38C(char *p, unsigned int k);
void func_021FE410(Obj_021FE254 *o, int a, int b, int n);
int func_021FE4D0(char *p);
void func_021FE4F8(void *unused);
void func_021FE520(void *unused);
void func_021FE54C(void *h, void *arg);
void func_021FE580(void *h);
void func_021FE594(void *h, void *arg);
void func_021FE690(void *h);
void func_021FE6A4(void *h, void *arg);
void func_021FE750(void *h);
void func_021FE768(void *h, void *arg);
void func_021FE79C(void *h, void *arg);
void func_021FE8AC(void *h);
void func_021FE8D8(void *h, void *arg);
void func_021FE930(void *h, void *arg);
void func_021FE9BC(void *h, void *arg);
void func_021FE9F0(fx32 a, fx32 b, int n, int f48, int f4c);
int func_021FEAA0(int v);
Work_021FEAC0 *func_021FEAC0(int mode, int a1, u16 a2);
void func_021FEB78(Work_021FEB78 *w);
void func_021FEBAC(Work_021FEBAC *w);
void func_021FEE9C(int *p);
void func_021FEEA8(char *w, void *src, int key);
void func_021FF088(Work_vE254 *w, void *src, int key);
void func_021FF0F8(Work_021FF0F8 *w, int key);
void func_021FF134(char *p, int a, int b);
void func_021FF144(Work_021FF144 *w, int key, fx32 x, fx32 y, fx32 z);
void func_021FF16C(Work_021FF16C *w);
void func_021FF1B0(Work_021FF1B0 *w);
void func_021FF1F4(Work_vE254 *w, int key);
void func_021FF228(Work_021FF228 *w, int key);
void func_021FF260(Work_021FF228 *w, int key, int mode);
int func_021FF2D8(Work_021FF228 *w, int key);
void func_021FF304(Work_021FF228 *w, int key, int mode);
int func_021FF348(Work_021FF348 *w, int key);
void func_021FF374(Work_vF228 *w, int key, int kind);
void func_021FF3F4(void *obj, void *out, int idx);
void func_021FF3FC(const Vec3_vF228 *def, Vec3_vF228 *out, int idx, int kind);
int func_021FF468(void *u, int i, int mode);
void func_021FF470(char *p, int key, u8 v);
void func_021FF498(char *p, int key, void *v);
void func_021FF4C0(char *w, int key, int kind, Vec_021F6560 *q, int a, int b, int c);
void func_021FF5B0(Work_021FF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);
void func_021FF630(Work_021FF630 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);
void func_021FF6B0(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);
void func_021FF730(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c);
void func_021FF7B0(Work_021FF7B0 *w, int a, int b);
void func_021FF870(Work_021FF870 *w, int key, int kind, int a, int b);
void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c);
void func_021FFA18(Work_021FFA18 *w, Obj_021FFA18 *s);
void func_021FFB04(Work_vF7B0 *w, Obj_vF7B0 *s);
void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c);
int func_021FFCB0(Work_021FFCB0 *w, int key);
int func_021FFD6C(Work_021FFD6C *w);
int func_021FFD9C(char *p, int key);
void func_021FFDB4(Work_vFCB0 *w, int key, u8 cur, u8 target, u8 step, u32 e);
void func_021FFDF8(Work_vFCB0 *w, int key, int a, int b);
void func_021FFE24(Work_vFE24 *w, int key);
void func_021FFE48(Work_021FFE48 *w, int key, void *p);
int func_021FFF0C(char *p, int key);
int func_021FFF38(char *p, int key);
int func_021FFF68(Work_021FFF68 *w, int key);
int func_021FFFAC(Work_021FFFAC *w, int key);
void func_021FFFD8(char *w, int key, int flag, int clear);
void func_02200108(Work_02200108 *w, int key, int v);
void func_02200140(Work_02200140 *w, int key1, int key2);
void func_022001DC(Work_022001DC *w, int key, Rec_022001DC *r);
int func_02200218(Work_02200218 *w, int key, int pitch, int pan, int a4, int a5, int a6);
void func_02200344(Work_02200344 *w, int a, int b, int flag);
int func_022003C4(char *p, int key);
void func_022003EC(Work_022003EC *w, void *p, int *a, int flags);
int func_0220041C(Work_0220041C *w, int key, int n);
void func_02200468(Work_02200468 *w, int key);
int func_02200494(char *p, int key);
void func_022004BC(Work_022004BC *w, int key);
void func_0220055C(Work_0220055C *w, int key, int mode);
int func_022005C4(Work_022005C4 *w, int key);
void func_02200608(Work_02200608 *w);
void func_02200654(Work_02200654 *w);
void func_022006A0(void *p, void *out, int flags);
void func_022006B4(Work_022006B4 *w, int i);
void func_0220074C(Work_0220074C *w, int i, int kind, VecFx32_vFE48 *p, VecFx32_vFE48 *q, int n, int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);
void func_02200904(void *h, Ctx_021FFE48 *c);
void func_02200990(void *h);
void func_022009C8(void *h, Ctx_vFE48 *c);
void func_02200A50(void *h);
void func_02200A84(void *h, Ctx_02200A84 *c);
void func_02200B10(void *h);
void func_02200B48(void *h, Ctx_02200B48 *c);
void func_02200BD4(void *h);
void func_02200C0C(void *h, Ctx_02200C0C *c);
void func_02200C98(void *h);
void func_02200CD0(void *h, void *arg);
void func_02200D30(void *h);
void func_02200D68(void *o, char *q);
void func_02200DE4(void *h);
void func_02200E1C(void *task, void *arg);
void func_02201098(void *h);
void func_022010D0(void *task, void *arg);
void func_022011FC(void *h);
void func_02201234(void *o, char *q);
void func_022012CC(void *h);
void func_02201304(void *task, void *arg);
void func_02201408(void *task, void *arg);
void func_02201700(void *h);
void func_02201718(int i);
int func_02201810(u32 flags, int a, int *out, int key);
void func_02201894(int i);
void func_022018A8(Unit_v1098 *u, Vec3_vF228 *out, int i);
int func_02201934(Unit_v1098 *u, int i, int mode);
int func_022019F4(char *p, int key);
int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3);
Res_02201894 *func_02201A8C(void *owner, u16 heap);
void func_02201AC4(Res_02201AC4 *r);
void func_02201AF0(void *a0);
int func_02201AF8(int a, int b, int c, short d, short e, int f, int g);
int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16_02201B20 x, s16_02201B20 y, u32 e, u32 f);
void func_02201CA4(Res_02201B20 *r, int i);
void func_02201CD0(char *o, int idx, int c, s16_02201B20 *p, int s1, int s2, int s3);
void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3);
u32 func_02201DA0(char *p, int i, int v);
void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d);
void func_02201E04(char *o, int idx, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3, void (*f1)(void *, void *), void (*f2)(void *));
void func_02201F98(void *a, void *b);
void func_02201FD8(void *h);
void func_02201FF4(void *a, void *b);
void func_0220203C(void *h);
struct Obj_02201DA0 *func_02202058(int a, int b, int c, int d, int e, u16 k);
void func_0220207C(int a, int b, int c, int d, int e, int f, int g, u16 k);
Obj_022020A0 *func_022020A0(int a, int b, int c, int d, int e, int f, int g, int h, u16 heap);
void func_022021F4(Obj_022021F4 *p);
void func_02202228(void **p);
void func_02202238(void *unused, void *arg);
void func_02202248(char *p);
void func_022023D0(char *p);
void func_0220255C(void *p);
void func_022025B4(void);
void func_022025D8(char *o, int flag);
void func_0220266C(Obj_0220266C *p);
int func_022026FC(struct W *p);
void func_0220270C(char *s, int mode, void *arg);
int func_02202DC4(Obj_v1DA0 *o, Cmd *c, int x);
int func_02203040(Main_02203040 *m);
int func_022030F0(Main_022030F0 *m, u8 *key, int *out);
int func_022033CC(Obj *p);
int func_022033F0(int *p);
void func_022033F4(Main_022033F4 *m);
void func_022035C0(void *task, void *arg);
void func_022036C4(void *task, void *arg);
void func_02203880(void *task, void *arg);
void func_02203978(void *task, void *arg);
void func_02203A78(void *a0, void *arg);
void func_02203B08(void *a0, void *arg);
void func_02203BC0(void *a0, void *arg);
void func_02203C2C(void *task, void *arg);
void func_02203D40(void *h, void *arg);
void func_02203E30(void *h, void *arg);
void func_02203FDC(void *h, void *arg);
void func_022040FC(void *h, void *arg);
void func_022041E0(void *h, void *arg);
void func_022042E4(void *h, void *arg);
void func_022043AC(void *h);
void func_022043C0(Main_022043C0 *m, int a1, int a2, int a3, int a4);
void func_02204438(void *a0, void *arg);
void func_022044A0(void *h);
void func_022044C0(Main_022044C0 *m, int a1, int a2, int a3, int a4);
void func_0220453C(void *a0, void *arg);
void func_02204588(void *h);
void func_022045A8(Main_022045A8 *m, int a1, int a2);
void func_0220461C(void *a0, void *arg);
void func_02204678(void *h);
void func_02204698(Obj_02204698 *p, int a, int b);
void func_022047CC(void *a, void *arg);
void func_022047F8(void *h);
void func_02204838(Main_02204838 *m, int a1);
void func_022048A4(void *a0, void *arg);
void func_02204940(void *h);
void func_02204960(Main_02204960 *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
void func_022049C8(void *a0, void *arg);
void func_02204A3C(void *a, void *arg);
void func_02204A70(void *h);
void func_02204A88(void *a0, void *arg);
void func_02204AEC(void *h);
void func_02204B0C(Main_02204B0C *m, int c);
void func_02204BAC(void *a, void *arg);
void func_02204BCC(void *a0, void *arg);
void func_02204C48(void *a0, void *arg);
void func_02204C98(struct StrObj *a, int b, int *outn, int *outq);
void func_02204CC0(Work_v3E30 *p, const Slots *q);
void func_022050F0(char *s, Out *out, const Info_v3E30 *p);
void func_02205340(Main_v3E30 *m, const int *c);
void func_022053DC(char *m);
void func_0220558C(char *s, const int *b);
void func_022056B4(Main_022053DC *m);
int func_02205768(int a, int b);
void func_022057CC(Main_022057CC *m, Info_v53DC *q);
void func_02205AB8(char *p);
void func_02205B80(char *p, int a);
void func_02205B90(char *p, int n);
void func_02205D34(W_022053DC *p);
void func_02205D58(char *p, int mode);
void func_02205E30(char *o);
void func_02205E80(char *m);
void func_02205F40(W_02205F40 *p);
void func_02205F64(W_02205F64 *p);
void func_02205F88(char *p);
void func_02206128(char *p);
int func_02206140(W_02206140 *p, const Ctx_v53DC *c, s8 (*rows)[12], u8 *list, int ret, int arg6);
int func_0220648C(char *p);
void func_022064CC(W_022064CC *p, u8 (* __restrict tab)[4], s8 (*rows)[12]);
int func_02206578(char *s, int a, int b);
void func_0220663C(void *task, void *arg);
void func_02206710(void *h);
void func_02206728(char *s, char *b);
void func_022067E8(char *p);
void func_0220680C(char *p);
void func_0220684C(char *p, int a, int b);
int func_02206864(char *p, int v);
void func_0220687C(char *p, void *q);
int func_022068C4(char *p);
void func_022068E8(char *p);
int func_02206908(char *p, char *q, int i);
void func_02206950(W_02206950 *p);
void func_02206A14(char *p);
void func_02206A58(char *p);
int func_02206A7C(char *p);
void func_02206AF8(char *p);
void func_02206B14(char *p);
void func_02206B30(char *p);
void func_02206B58(char *p);
void func_02206B74(char *p);
void func_02206B90(char *p);
void func_02206BAC(char *p);
Obj_02206BC8 *func_02206BC8(int a, u16 heap);
void func_02206E28(char *p);
void func_02206EB4(W_02206BC8 *p);
void func_022070C0(W_022070C0 *p, void *a, void *q, int mode, int i);
void func_02207288(W_02207288 *p, void *a, void *q, int mode, int i);
void func_02207430(Work_v64CC *p, int mode, int i);
void func_0220778C(Work_022064CC *p, int i);
void func_0220785C(O_0220778C *o, int unused, int idx, void *data);
void func_0220793C(char *p);
void func_02207960(char *p, int i);
extern const char d_0220AC40[];
extern const char d_0220AC50[];
extern const char d_0220AC60[];
extern char d_02209CF4[];
extern char d_02209D00[];
extern char d_02209CE8[];
extern const s16_021F6560 d_020A1B38[];
extern const char d_0220AC90[];
extern BtlvEff *d_0220AF20;
extern u8 d_02209D0C[];
extern BtlvEff *g_0220AF20;
extern u32 d_0220AC70[];
extern u32 d_0220AC78[];
extern const char d_0220AE68[];
extern char d_02209DCC[];
extern const VecFx32_v9814 d_0220ACA0[2];
extern const VecFx32_v9814 d_0220ACE8[];
extern const VecFx32_v9814 d_0220AD00[];
extern const VecFx32_v9814 d_0220AD78[];
extern const VecFx32_v9814 d_0220ADA8[];
extern const VecFx32_v9814 d_0220ADD8[];
extern const VecFx32_v9814 d_0220AE20[];
extern const Vec_021F6560 d_02209E1C, d_02209D90;
extern const Vec_021F6560 d_02209D78, d_02209E04;
extern const Vec_021F6560 d_02209DC0, d_02209D84;
extern const Vec_021F6560 d_02209DA8, d_02209D9C;
extern const Targets d_02209E58;
extern const Targets d_02209E28;
extern const int d_0220AD18[], d_0220AD38[];
extern const int d_0220AD58[];
extern const Vec_021F6560 d_02209E10, d_02209DB4;
extern MtxFx43 g_renderStateDrawParams;
extern MtxFx44 SCREENTEX_ProjectionMatrix;
extern int d_02209DD8[];
extern char d_0220AE7C[];
extern const Vec3_vF228 d_0220A050[];
extern const Vec3_vF228 d_0220A080[];
extern const Vec3_vF228 d_0220A158[];
extern const Vec3_vF228 d_0220A1A0[];
extern u32 d_02209FC0[];
extern u32 d_02209FE0[];
extern u32 d_02209FF0[];
extern u32 d_0220A068[];
extern const u8 d_0220AE78[];
extern const Tab6 d_0220A0C8;
extern const Tab6 d_0220A0B0;
extern const Tab12 d_0220A0E0;
extern const Vec3_vF228 d_0220A110[];
extern const int d_02209FC8[];
extern const int d_02209FD0[];
extern const int d_0220A008[];
extern const int d_0220A020[];
extern const int d_0220A038[];
extern const char d_0220A1E8[];
extern const char d_0220A1EA[];
extern const char d_0220A1EC[];
extern const char d_0220A1EE[];
extern const char d_0220AE88[];
extern const Config d_0220A368;
extern const char d_0220AEB0[];
extern char d_0220A3D4[];
extern const Ent_02202238 d_0220A8BC[];
extern u8 d_0689E090[][15];
extern u8 d_0689E0B0[][15];
extern Ent_v1DA0 *d_0689E560[][15];
extern Ent_v1DA0 *d_0689E704[][15];
extern const Tbl_v1DA0 d_0220A598;
extern const Sec sec_0220A380;
extern const u8 d_0220A380[3];
extern void *const d_0220AE98[];
extern void *const d_0220AEA4[];
extern const Pair_022033F4 d_0220A4EC[];
extern const Ent_v3E30 d_0220A46C[][2];
extern const Quad d_0220A53C;
extern Row_02201B20 d_0220A85C[];
extern const int d_0220A3B4[][2];
extern const u8 d_0220A38C[][2];
extern const int d_0220A3E4[][2];
extern const PosTab d_0220A5B0;
extern const PosTab d_0220A5D0;
extern const int d_0220A5F0[];
extern const u16 d_0220A392[];
extern const Point_02201B20 d_0220A3C4[];
extern const Pos_02204C98 d_0220A4AC[];
extern const int d_0220A7FC[2][6][2];
extern const int d_0220A94C[2][3][15];
extern const Palette d_0220A386[];
extern const Point_022053DC d_0220A50C[][3];
extern const Five d_0220A558, d_0220A56C, d_0220A544;
extern const Q_v53DC d_0220A580;
extern const char d_0220AEC0[];
extern const Pt_02206BC8 d_0220AABC;
extern const Cfg d_0220AAC8;
extern const Pt_0220778C d_0220AAB4;



#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))



#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))



#define FX(x) ((int)(((x) > 0) ? (0.5f + (float)((x) << 12)) : ((float)((x) << 12) - 0.5f)))















Obj_021F6560 *func_021F6560(int mode, int group, int variant, u16 heap)
{
    Obj_021F6560 *o;
    Rec_v6560 *table;
    int i, k, m;
    int bytes;
    o = sub_02030734(heap, 0xbc, 1, d_0220AC40, 0x63);
    table = ARC_TOOL_LoadMember(0x98, 2, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (mode == 3)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, 0x56);
    else if (table[group].ids[0][variant] != -1)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[0][variant]);
    else
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[0][0]);
    G3D_SYSTEM_TransVramTexture(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group].ids[i][variant] != -1) o->n++;
    o->h1c[0] = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    o->h1c[1] = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    if (mode == 3) {
        o->n = 1;
        o->f10 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0x93);
        *o->f10 = G3D_SYSTEM_CreateResourceArc(11, 0x57);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, 4, 0, d_0220AC40, 0x98);
            o->arr[i] = sub_02030734(o->heap, 0x10, 1, d_0220AC40, 0x99);
            *o->f14[i] = G3D_SYSTEM_CreateAnime(o->h1c[i], *o->f10, 0);
            o->arr[i]->kind = 1;
            o->h24[i] = G3D_SYSTEM_CreateObject((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            G3D_SYSTEM_EnableObjectAnime(o->h24[i], (u16)0);
        }
    } else if (o->n != 0) {
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, d_0220AC40, 0xa7);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, o->n * 4, 0, d_0220AC40, 0xab);
            o->arr[i] = sub_02030734(o->heap, o->n * 16, 1, d_0220AC40, 0xac);
        }
        k = 0;
        for (i = 1; i < 4; i++) {
            if (table[group].ids[i][variant] != -1) {
                o->f10[k] = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[i][variant]);
                for (m = 0; m < 2; m++) {
                    o->f14[m][k] = G3D_SYSTEM_CreateAnime(o->h1c[m], o->f10[k], 0);
                    o->arr[m][k].kind = 0;
                }
                k++;
            }
        }
        for (i = 0; i < 2; i++) {
            o->h24[i] = G3D_SYSTEM_CreateObject((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            for (m = 0; m < o->n; m++) G3D_SYSTEM_EnableObjectAnime(o->h24[i], (u16)m);
        }
    } else {
        o->h24[0] = G3D_SYSTEM_CreateObject((u32)o->h1c[0], 0, (u16)0);
        o->h24[1] = G3D_SYSTEM_CreateObject((u32)o->h1c[1], 0, (u16)0);
    }
    bytes = *(u16 *)(NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(o->f0)) + 0x30) * 8;
    o->fa4 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0xd6);
    o->fa8 = sub_02030734(o->heap, 4, 0, d_0220AC40, 0xd7);
    *o->fa4 = o->f0;
    *o->fa8 = sub_02030734(o->heap, bytes, 0, d_0220AC40, 0xda);
    o->fac = 0;
    o->fad = 1;
    o->xf[0].f0 = 0;
    o->xf[0].f4 = 0;
    o->xf[0].f8 = 0x572f;
    o->xf[0].sx = 0x1000;
    o->xf[0].sy = 0x1000;
    o->xf[0].sz = 0x1000;
    func_0207ADC4(o->xf[0].matrix);
    o->xf[1].f0 = 0;
    o->xf[1].f4 = 0;
    o->xf[1].f8 = -0xcb7d;
    o->xf[1].sx = 0x1000;
    o->xf[1].sy = 0x1000;
    o->xf[1].sz = 0x1000;
    func_0207ADC4(o->xf[1].matrix);
    if (mode == 3) {
        o->xf[0].f8 = 0xa000;
        o->xf[1].f8 = -0xf000;
    }
    func_0207DCF8(&table[group]);
    sub_020307B0(table);
    return o;
}















void func_021F6898(Obj_021F6898 *o)
{
    int i;
    int j;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++)
                G3D_SYSTEM_DeleteAnime(o->f14[j][i]);
            func_02046EFC(o->f10[i]);
        }
        for (j = 0; j < 2; j++) {
            func_020307B0(o->f14[j]);
            func_020307B0(o->f8[j]);
        }
        func_020307B0(o->f10);
    }
    for (j = 0; j < 2; j++) {
        G3D_SYSTEM_DeleteObject(o->f24[j]);
        G3D_SYSTEM_DeleteRender(o->f1c[j]);
    }
    func_02046EFC(o->f0);
    func_020307B0(*o->fa8);
    func_020307B0(o->fa8);
    func_020307B0(o->fa4);
    func_020307B0(o);
}















/*
 * Lever: the element address is `i * 16 + (u32)o->arr[j]` (integer first);
 * `&o->arr[j][i]` is normalised pointer-first and swaps the add operands.
 */
void func_021F6934(Obj_021F6934 *o)
{
    int i;
    int j;
    int amt;

    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            for (j = 0; j < 2; j++) {
                Ent_021F6934 *e;

                e = (Ent_021F6934 *)(i * 16 + (u32)o->arr[j]);
                amt = 0;
                switch (e->kind) {
                case 0:
                    amt = 0x1000;
                    break;
                case 1:
                    if (e->f4 == 1) {
                        amt = e->f8;
                        e->fc--;
                        if (((Ent_021F6934 *)(i * 16 + (u32)o->arr[j]))->fc == 0)
                            ((Ent_021F6934 *)(i * 16 + (u32)o->arr[j]))->f4 = 0;
                    }
                    break;
                }
                if (amt != 0)
                    G3D_SYSTEM_LoopObjectAnimeFrame(o->h[j], (u16)i, amt);
            }
        }
    }
    func_021F9364((P *)o->sub);
}















/*
 * Applies each of the two transforms whose disable bit is clear.
 */
void func_021F69B0(Obj_021F69B0 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (!(p->off & (1 << i)))
            G3D_SYSTEM_DrawObject(p->h[i], (struct Arg_v6560 *)p->xf[i]);
    }
}















/*
 * lane O10 candidate
 */
void func_021F69E8(S69E8 *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d)
{
    p->f0 = 1;
    p->f2 = a;
    p->f3 = b;
    p->f4 = 0;
    p->f5 = c;
    p->f6 = d;
}















int func_021F6A18(char *p)
{
    return ((struct Obj18549 *)p)->fAC != 0;
}















void func_021F6A28(Obj_021F6A28 *o, u32 mode, u32 on)
{
    if (mode == 2) {
        if (on)
            o->f = 3;
        else
            o->f = 0;
    } else {
        if (on)
            o->f = o->f | (1 << mode);
        else
            o->f = o->f & ((1 << mode) ^ 3);
    }
}















/*
 * Arms entry j of table i when its state is 1: sets the flag and stores the two values.
 */
void func_021F6AA8(Obj_021F6AA8 *p, int i, int j, int a, int b)
{
    if (p->tab[i][j].state == 1) {
        p->tab[i][j].armed = 1;
        p->tab[i][j].a = a;
        p->tab[i][j].b = b;
    }
}















/*
 * Returns 1 when any entry of either table is armed.
 */
int func_021F6AD0(Obj_021F6AD0 *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        if (p->x[i].armed == 1 || p->y[i].armed == 1)
            return 1;
    }
    return 0;
}















/*
 * Lever: u8 variant spills at entry before the other parameter copies;
 * int variant moves that spill three instructions later (8 differing bytes).
 * The ov094 caller at 021F76D6 passes the byte-derived selector.
 */
Obj_021F6B04 *func_021F6B04(int unused, int group, u8 variant, u16 heap)
{
    Obj_021F6B04 *o;
    int (*table)[4][4];
    int i, j;
    int bytes;
    o = sub_02030734(heap, 0x70, 1, d_0220AC50, 0x56);
    table = ARC_TOOL_LoadMember(0x98, 1, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (table[group][0][variant] != -1)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group][0][variant]);
    else
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group][0][0]);
    G3D_SYSTEM_TransVramTexture(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group][i][variant] != -1) o->n++;
    o->f14 = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    j = 0;
    if (o->n != 0) {
        o->fc = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7e);
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7f);
        o->f8 = sub_02030734(o->heap, o->n * 16, 1, d_0220AC50, 0x80);
        for (i = 1; i < 4; i++) {
            if (table[group][i][variant] != -1) {
                o->fc[j] = G3D_SYSTEM_CreateResourceArc(11, table[group][i][variant]);
                o->f10[j] = G3D_SYSTEM_CreateAnime(o->f14, o->fc[j], 0);
                o->f8[j].kind = 0;
                j++;
            }
        }
        o->f18 = G3D_SYSTEM_CreateObject((u32)o->f14, (u32 *)o->f10, (u16)o->n);
        for (j = 0; j < o->n; j++) G3D_SYSTEM_EnableObjectAnime(o->f18, (u16)j);
    } else {
        o->f18 = G3D_SYSTEM_CreateObject((u32)o->f14, 0, (u16)0);
    }
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0x1000;
    o->f2c = 0x1000;
    o->f30 = 0x1000;
    func_0207ADC4(o->matrix);
    bytes = *(u16 *)(NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(o->f0)) + 0x30) * 8;
    o->f58 = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xaa);
    o->f5c = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xab);
    *o->f58 = o->f0;
    *o->f5c = sub_02030734(o->heap, bytes, 0, d_0220AC50, 0xae);
    o->f60 = 0;
    o->f61 = 1;
    sub_020307B0(table);
    return o;
}















void func_021F6CF0(Obj_021F6CF0 *o)
{
    int i;

    G3D_SYSTEM_DeleteObject(o->f18);
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            G3D_SYSTEM_DeleteAnime(o->f10[i]);
            func_02046EFC(o->fc[i]);
        }
        func_020307B0(o->f8);
        func_020307B0(o->f10);
        func_020307B0(o->fc);
    }
    G3D_SYSTEM_DeleteRender(o->f14);
    func_02046EFC(o->f0);
    func_020307B0(*o->f5c);
    func_020307B0(o->f5c);
    func_020307B0(o->f58);
    func_020307B0(o);
}















/*
 * Lever: the `adds r6, r4, #0` before the loop is a zero (r4 is 0 there) that
 * the loop-back branch skips; it is the constant 0 (default amount and the
 * cleared field), not a copy of i. Flags_021F6560 word is a bitfield (lsls/lsrs).
 */
void func_021F6D5C(Obj_021F6D5C *o)
{
    int i;
    int amt;

    if (o->bit1) {
        o->bit1 = 0;
        return;
    }
    if (o->n != 0) {
        for (i = 0; i < o->n; i++) {
            Ent_021F6D5C *e;

            e = &o->arr[i];
            amt = 0;
            switch (e->kind) {
            case 0:
                amt = 0x1000;
                break;
            case 1:
                if (e->f4 == 1) {
                    amt = e->f8;
                    e->fc--;
                    if (o->arr[i].fc == 0)
                        o->arr[i].f4 = 0;
                }
                break;
            }
            if (amt != 0)
                G3D_SYSTEM_LoopObjectAnimeFrame(o->h18, (u16)i, amt);
        }
    }
    func_021F9364((P *)o->sub);
}















/*
 * Unless flag bit 0 at 0x68 is set, applies the vector at 0x1c to the handle at 0x18.
 */
void func_021F6DD4(Obj_021F6DD4 *p)
{
    if (!p->b0)
        G3D_SYSTEM_DrawObject(p->h, (struct Arg_v6560 *)p->v);
}















void func_021F6DEC(S6DEC *p, unsigned char a, unsigned char b, unsigned char c, unsigned short d)
{
    p->f0 = 1;
    p->f2 = a;
    p->f3 = b;
    p->f4 = 0;
    p->f5 = c;
    p->f6 = d;
}















int func_021F6E1C(char *p)
{
    return ((struct Obj18551 *)p)->f60 != 0;
}















/*
 * Unlabelled leaf, filed as the blocker of ov094 func_021F839C (lane S22).
 */
void func_021F6E2C(Obj_021F6E2C *o, u32 v)
{
    o->f = v;
}















Obj_021F6E3C *func_021F6E3C(int a, u16 b)
{
    Obj_021F6E3C *o = sub_02030734(b, 0xb8, 1, d_0220AC60, 0x56);

    o->hb4 = b;
    o->f0 = a;
    o->h4 = G3D_CAMERA_Create(0, 0x399, 0xf97, 0x159a, 0, 0x1000, 0x200000, 0,
                          d_02209CF4, d_02209D00, d_02209CE8, b);
    func_021F73A4((int *)o);
    func_02048AD0((struct Light *)o->h4);
    func_021F7208((VecFx32_v6560 *)(&o->v18), (VecFx32_v6560 *)(&o->v24));
    return o;
}















/*
 * Releases the handle at word 1, then frees the object.
 */
void func_021F6EC0(void **p)
{
    G3D_CAMERA_Delete(p[1]);
    func_020307B0(p);
}















void func_021F6ED4(int *p)
{
    func_021F723C(p);
}













/*
 * EXACT*: inferred extent is two bytes long; the follower is an unlabelled
 * leaf that disasm.py did not label.
 */
void func_021F6EDC(int *p, int *a, int *b)
{
    if (a) {
        p[6] = a[0];
        p[7] = a[1];
        p[8] = a[2];
        func_02048AFC(p[1], a);
    }
    if (b) {
        p[9] = b[0];
        p[10] = b[1];
        p[11] = b[2];
        func_02048B44(p[1], (int)b);
    }
    func_02048AD0((struct Light *)p[1]);
    func_021F73A4(p);
}












/*
 * Builds the transform at 0x18/0x24, then loads it into the handle at word 1 and commits.
 */
void func_021F6F20(Obj_021F6F20 *p, int a, int b)
{
    func_021F7108((int *)p, a, b, p->m, p->v);
    func_02048AFC((int)p->h, (const int *)p->m);
    func_02048AD0(p->h);
}












void func_021F6F48(Cam_021F6F48 *c, VecFx32_v6560 *a, VecFx32_v6560 *b, int n, int s, int t)
{
    c->f74 = t;
    c->f6c = s;
    c->f70 = s;
    if (a != 0) {
        c->dst0.x = a->x;
        c->dst0.y = a->y;
        c->dst0.z = a->z;
        func_021F918C((const VecFx32_021F8F30 *)((const VecFx32_v6560 *)(&c->cur0)), (const VecFx32_021F8F30 *)((const VecFx32_v6560 *)a), (VecFx32_021F8F30 *)((VecFx32_v6560 *)(&c->step0)), FX_INT_TO_FX32(n));
        c->flags |= 1;
    }
    if (b != 0) {
        c->dst1.x = b->x;
        c->dst1.y = b->y;
        c->dst1.z = b->z;
        func_021F918C((const VecFx32_021F8F30 *)((const VecFx32_v6560 *)(&c->cur1)), (const VecFx32_021F8F30 *)((const VecFx32_v6560 *)b), (VecFx32_021F8F30 *)((VecFx32_v6560 *)(&c->step1)), FX_INT_TO_FX32(n));
        c->flags |= 2;
    }
}












/*
 * Follower of func_021F6F48; bl from ov094 at 0x021FA08E.
 */
void func_021F7000(Cam_021F7000 *c, int mode, fx32 v, int unused, int n, int g, int h)
{
    c->f78 = 3;
    c->fa0 = n;
    c->fa4 = n;
    c->fa8 = 0;
    c->fac = g;
    c->f7c = 0;
    c->fb0 = h * 4;
    c->f80 = 0;
    c->f84 = 0;
    if (mode == 1) {
        c->f88 = v;
        c->f8c = 0;
        c->f94 = func_0207C768(v, FX_INT_TO_FX32(n));
        c->f98 = 0;
    } else {
        c->f88 = 0;
        c->f8c = v;
        c->f94 = 0;
        c->f98 = func_0207C768(v, FX_INT_TO_FX32(n));
    }
    c->f90 = 0;
    c->f9c = 0;
    c->flags |= 4;
}










/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Copies the light at word 1's vectors at +0x20 and +0x38 out to b and c.
 */
void func_021F70F0(void **p, void *b, int c)
{
    func_02048AE8(p[1], b);
    func_02048B30(p[1], c);
}









void func_021F7108(int *p, int a, int b, int *out, int *base)
{
    func_02048B30((void *)p[1], (int)base);
    p[2] += a;
    p[3] += b;
    out[0] = MUL(d_020A1B38[(p[3] >> 4) * 2 + 1], d_020A1B38[(p[2] >> 4) * 2 + 1]);
    out[1] = d_020A1B38[(p[2] >> 4) * 2];
    out[2] = MUL(d_020A1B38[(p[3] >> 4) * 2], d_020A1B38[(p[2] >> 4) * 2 + 1]);
    out[0] = MUL(out[0], p[4]);
    out[1] = MUL(out[1], p[4]);
    out[2] = MUL(out[2], p[4]);
    out[0] += base[0];
    out[1] += base[1];
    out[2] += base[2];
}

























void func_021F7208(VecFx32_v6560 *a, VecFx32_v6560 *b)
{
    a->x = 0x6b33;
    a->y = 0x6b33;
    a->z = 0x114cd;
    b->x = 0;
    b->y = 0x299a;
    b->z = 0;
}

























int func_021F722C(char *p)
{
    return ((struct Obj18557 *)p)->f14 != 0;
}

























void func_021F723C(int *p)
{
    int a[3];
    int b[3];
    int ret = 1;
    int n;
    if (p[5] == 0) return;
    if (p[27] == 0) {
        p[27] = p[28];
        if (p[29] != 0) {
            if (--p[29] == 0) {
                n = p[18] >> 1; if (n) p[18] = n;
                n = p[19] >> 1; if (n) p[19] = n;
                n = p[20] >> 1; if (n) p[20] = n;
                n = p[21] >> 1; if (n) p[21] = n;
                n = p[22] >> 1; if (n) p[22] = n;
                n = p[23] >> 1; if (n) p[23] = n;
            }
        }
        if (p[5] & 1) {
            func_021F9220(&p[6], &p[18], &p[12], &ret);
            func_021F9220(&p[7], &p[19], &p[13], &ret);
            func_021F9220(&p[8], &p[20], &p[14], &ret);
            if (ret == 1) p[5] &= ~1;
        }
        if (p[5] & 2) {
            func_021F9220(&p[9], &p[21], &p[15], &ret);
            func_021F9220(&p[10], &p[22], &p[16], &ret);
            func_021F9220(&p[11], &p[23], &p[17], &ret);
            if (ret == 1) p[5] &= ~2;
        }
        if (p[5] & 4) {
            ret = func_021F9260((Mover_v8204 *)(&p[30]), (VecFx32_021F8F30 *)(&p[24]));
            if (ret == 1) p[5] &= ~4;
        }
        a[0] = p[6] + p[24];
        a[1] = p[7] + p[25];
        a[2] = p[8] + p[26];
        b[0] = p[9] + p[24];
        b[1] = p[10] + p[25];
        b[2] = p[11] + p[26];
        func_02048AFC(p[1], (const int *)a);
        func_02048B44(p[1], (int)b);
        func_02048AD0((struct Light *)p[1]);
        func_021F73A4(p);
    } else {
        p[27]--;
    }
}

























void func_021F73A4(int *p)
{
    int a[3];
    int b[3];
    func_02048AE8((void *)p[1], a);
    func_02048B30((void *)p[1], (int)b);
    a[0] -= b[0];
    a[1] -= b[1];
    a[2] -= b[2];
    p[2] = func_0207CFB8(a[1], a[2]);
    p[3] = func_0207CFB8(a[2], a[0]);
    p[4] = func_0207CBD0(a);
}

























Obj_v6560 *func_021F73F0(int a, int b, Q_v6560 *q, int c, u16 *h, int e, int f, u16 heap)
{
    Obj_v6560 *o;
    int i = 0;

    o = sub_02030734((u16)((heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AC90, 0xca);
    o->f0 = a;
    o->f4 = b;
    o->q = *q;
    o->f20 = c;
    o->f24 = f;
    o->f28 = e;
    for (; i < 4; i++)
        o->h[i] = h[i];
    return o;
}

























void *func_021F745C(u8 *p, int a, u16 heap)
{
    u16 h[4];
    unsigned int i;
    int side, idx, other;
    int mode, type;
    Q_v6560 *q;
    for (i = 0; i < 4; i++) h[i] = 0;
    if (BTL_MAIN_IsMultiMode((unsigned char **)p) == 1) {
        side = func_021B8FE4(p);
        idx = func_021B8FF4(p);
        other = func_021B9000(p);
        h[side * 2] = func_021BA020((char *)p, idx);
        if (other != 4) h[(side ^ 1) * 2] = func_021BA020((char *)p, other);
        h[1] = func_021BA020((char *)p, func_021B904C(p, 0));
        h[3] = func_021BA020((char *)p, func_021B904C(p, 1));
    } else {
        h[0] = func_021BA020((char *)p, func_021B8FF4(p));
        h[1] = func_021BA020((char *)p, func_021B904C(p, 0));
        h[2] = 0;
        h[3] = 0;
    }
    mode = BTL_MAIN_GetRule((void **)p);
    type = (int)BTL_MAIN_GetCompetitor((void ***)p);
    q = (Q_v6560 *)BTL_MAIN_GetFieldSituation((char **)p);
    return func_021F73F0(mode, type, q, BTL_MAIN_IsMultiMode((unsigned char **)p), h, (int)p, a, heap);
}























/*
 * note:     the two func_021F6B04 calls and the two f244 stores are written per arm;
 *           the compiler tail-merges them, which is what keeps the 0x194-based
 *           offsets and the reload of &d_0220AF20 seen in the listing.
 */
void func_021F7544(Param *p, int arg, u16 heap)
{
    Work_v6560 *w;
    Entry_021F7208 *tbl;
    u8 v;
    int i;
    Rect r;
    u16 out[10];

    w = sub_02030734(heap, sizeof(Work_v6560), 1, d_0220AC90, 0x116);
    d_0220AF20 = (BtlvEff *)(w);
    w->param = *p;
    w->heap = heap;
    d_0220AF20->buf = sub_02030734(heap, func_02030CB0(0x20), 1, d_0220AC90, 0x11c);
    d_0220AF20->owner = func_02030CBC(0x20, d_0220AF20->buf);
    d_0220AF20->h188 = func_021F93F4(d_0220AF20->owner, heap);
    d_0220AF20->h18c = (void *)PALANM_Create(heap);
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)d_0220AF20->h18c, 1);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 0, 0x200, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 1, 0x1e0, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 2, 0x200, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)d_0220AF20->h18c, 3, 0x1e0, heap);
    v = 0;
    d_0220AF20->h190 = (void *)func_021FEAC0(p->f0, (int)d_0220AF20->owner, heap);
    tbl = ARC_TOOL_LoadMember(0x98, 0, (u16)((d_0220AF20->heap & 0x7fff) | 0x8000));
    if (tbl[p->f8].f1 != 0) {
        v = p->f11;
    }
    d_0220AF20->h194 = (void *)func_021F6560(p->f0, tbl[p->f8].a13[p->fc], v, heap);
    if (d_0220AF20->param_battle != 0) {
        d_0220AF20->h198 = (void *)func_021F6B04(func_021BA1A8(d_0220AF20->param_battle, 0x400), tbl[p->f8].a2[p->fc], v, heap);
    } else {
        d_0220AF20->h198 = (void *)func_021F6B04(0, tbl[p->f8].a2[p->fc], v, heap);
    }
    if (tbl[p->f8].f0 != 0) {
        func_0201493C(p->f12, p->f14, p->f15, p->f10, p->f11, out, d_0220AF20->heap);
        r.w = out[0];
        r.x = 0;
        r.y = -0x1000;
        r.z = 0;
        G3D_SYSTEM_SetLight(0, (const u16 *)(&r));
    }
    func_020307B0(tbl);
    d_0220AF20->h19c = (void *)func_021F6E3C((int)d_0220AF20->owner, heap);
    d_0220AF20->h1a0 = (struct Res *)func_02201A8C(d_0220AF20->owner, heap);
    d_0220AF20->h1a4 = (void *)func_02206BC8(arg, heap);
    d_0220AF20->h1b0 = func_02209224(heap);
    d_0220AF20->h1b4 = func_0220975C(d_0220AF20->owner, heap);
    func_021FF16C((Work_021FF16C *)d_0220AF20->h190);
    PARTICLE_InitManager(heap);
    for (i = 0; i < 8; i++) {
        d_0220AF20->slots[i] = -1;
    }
    if (d_0220AF20->param_battle != 0) {
        if (func_021BA1A8(d_0220AF20->param_battle, 0x800)) {
            d_0220AF20->f244 = 300;
        } else {
            d_0220AF20->f244 = 900;
        }
    }
    d_0220AF20->h1b8 = func_020056A0(func_021F8B90, 0, 1);
    PM_VOICE_AllocBuffers(2, d_0220AF20->heap);
}






















void func_021F7808(void)
{
    if (d_0220AF20 != 0) {
        PM_VOICE_FreeBuffers();
        func_021F8B6C();
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 0);
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 1);
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 2);
        PALANM_FreeSlotBuffers(d_0220AF20->h18c, 3);
        PALANM_Delete(d_0220AF20->h18c);
        func_021FEB78((Work_021FEB78 *)d_0220AF20->h190);
        func_021F6898((Obj_021F6898 *)d_0220AF20->h194);
        func_021F6CF0((Obj_021F6CF0 *)d_0220AF20->h198);
        func_021F6EC0(d_0220AF20->h19c);
        func_02201AC4((Res_02201AC4 *)d_0220AF20->h1a0);
        func_02206E28(d_0220AF20->h1a4);
        func_022092E8(d_0220AF20->h1b0);
        func_0220977C(d_0220AF20->h1b4);
        PARTICLE_ExitManager();
        func_021F94D8(d_0220AF20->h188);
        func_02030EAC(d_0220AF20->h1b8);
        func_02030DA4(d_0220AF20->owner);
        func_020307B0(d_0220AF20->buf);
        func_020307B0(d_0220AF20);
        d_0220AF20 = 0;
    }
}





















/*
 * volatile: 0x021F7980 0x021F7986 (0x04000604 read twice, results unused)
 */
void func_021F78E4(void)
{
    if (d_0220AF20 != 0) {
        d_0220AF20->f1e8 = func_021F9478(d_0220AF20->h188);
        func_021F903C();
        func_02030D28(d_0220AF20->owner);
        func_021FEBAC((Work_021FEBAC *)d_0220AF20->h190);
        func_021F6934((Obj_021F6934 *)d_0220AF20->h194);
        func_021F6D5C((Obj_021F6D5C *)d_0220AF20->h198);
        func_021F6ED4(d_0220AF20->h19c);
        func_02206EB4((W_02206BC8 *)d_0220AF20->h1a4);
        func_02201AF0(d_0220AF20->h1a0);
        func_02047964();
        G3D_SYSTEM_ApplyLookAt();
        func_021F69B0((Obj_021F69B0 *)d_0220AF20->h194);
        func_021F6DD4((Obj_021F6DD4 *)d_0220AF20->h198);
        func_021FEE9C(d_0220AF20->h190);
        REG_04000604;
        PARTICLE_Main();
        REG_04000604;
        G3D_SYSTEM_DrawEnd();
    }
}





















void func_021F7998(u32 a)
{
    Job_021F7998 *o;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, 0xff, 0xff, a, (Quad_v8204 *)0);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x14, 1, d_0220AC90, 0x210);
    o->f4 = 0xff;
    o->f8 = 0xff;
    o->fc = a;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}





















void func_021F7A28(int a, u32 b)
{
    Job_021F7A28 *o;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, a, 0xff, b, (Quad_v8204 *)0);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734(d_0220AF20->heap, 0x14, 1, d_0220AC90, 0x22c);
    o->f4 = a;
    o->f8 = 0xff;
    o->fc = b;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}





















void func_021F7AAC(int a, int b, u32 c)
{
    Job_021F7AAC *o;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, a, b, c, (Quad_v8204 *)0);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734(d_0220AF20->heap, 0x14, 1, d_0220AC90, 0x249);
    o->f4 = a;
    o->f8 = b;
    o->fc = c;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}





















void func_021F7B2C(const Req_021F7208 *r)
{
    Job_021F7B2C *o;
    Arg_v6560 l;

    if (func_021F7EB4() == 0) {
        func_021F9844((S9844 *)&l);
        l.b0 = r->f10;
        l.b1 = r->c;
        l.b2 = r->d;
        func_021F94F8(d_0220AF20->h188, r->f4, r->f8, r->h0, (Quad_v8204 *)&l);
        d_0220AF20->f1e8 = 1;
        return;
    }
    o = sub_02030734(d_0220AF20->heap, 0x14, 1, d_0220AC90, 0x26b);
    o->s = sub_02030734(d_0220AF20->heap, 0x10, 1, d_0220AC90, 0x26c);
    o->f4 = r->f4;
    o->f8 = r->f8;
    o->fc = r->h0;
    o->s->b0 = r->f10;
    o->s->b1 = r->c;
    o->s->b2 = r->d;
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8FE8, o, 0), func_021F9028, 0);
}




















/*
 * Calls func_021F97E4 on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 0.
 */
void func_021F7BEC(void)
{
    func_021F97E4(d_0220AF20->h188);
    d_0220AF20->f1e8 = 0;
}




















/*
 * Calls func_021F9814 on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 1.
 */
void func_021F7C0C(void)
{
    func_021F9814(d_0220AF20->h188);
    d_0220AF20->f1e8 = 1;
}



















/*
 * witness: arm9 WAZA_TOOL_GetDamageType filed as src/matched/arm9/WAZA_TOOL_GetDamageType.c.
 */
void func_021F7C2C(int a, int b)
{
    Job_021F7208 *o;

    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x18, 0, d_0220AC90, 0x29b);
    o->f4 = 0;
    o->f0 = a;
    o->f8 = 3;
    o->fc = 0;
    o->f14 = func_021FF348((Work_021FF348 *)d_0220AF20->h190, a);
    if (WAZA_TOOL_GetDamageType(b) == 1)
        o->f10 = 0x842;
    else
        o->f10 = 0x6318;
    d_0220AF20->m0 |= func_021F935C(a);
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8BAC, o, 0), func_021F8C78, 0);
}



















/*
 * Runs func_021F7A28 with code 0x23b, then func_021F8AE8 with 0.
 */
void func_021F7CE4(int a)
{
    func_021F7A28(a, 0x23b);
    func_021F8AE8(a, 0);
}

















void func_021F7CFC(u32 a, u16 b, u8 c, int d, int e)
{
    Arg_v6560 l;

    func_021F9844((S9844 *)&l);
    l.b3 = c;
    l.f8 = e;
    l.f4 = d;
    l.fc = b;
    func_021F94F8(d_0220AF20->h188, 0, a, 0x23a, (Quad_v8204 *)&l);
    d_0220AF20->f1e8 = 1;
}
















/*
 * Queues request 0x23d with value b on the handle at 0x188, then sets the word at 0x1e8 to 1.
 */
void func_021F7D44(int a, unsigned short b)
{
    Req_021F7D44 req;

    func_021F9844((S9844 *)((Arg_v6560 *)&req));
    req.v = b;
    func_021F94F8(d_0220AF20->h188, 0, a, 0x23d, (Quad_v8204 *)&req);
    d_0220AF20->f1e8 = 1;
}

















void func_021F7D80(void *a, int b)
{
    Job_021F7D80 *o;

    o = sub_02030734((u16)((d_0220AF20->heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AC90, 0x2f9);
    o->f4 = 0;
    o->f0 = b;
    func_021FFE48((Work_021FFE48 *)d_0220AF20->h190, b, a);
    func_022003EC((Work_022003EC *)d_0220AF20->h190, a, o->buf, b);
    d_0220AF20->m1 |= func_021F935C(b);
    func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8CB0, o, 0), func_021F8EF8, 0);
}

















void func_021F7E38(void *a, int b)
{
    int buf[9];

    func_021FFE48((Work_021FFE48 *)d_0220AF20->h190, b, a);
    func_022003EC((Work_022003EC *)d_0220AF20->h190, a, buf, b);
    func_022001DC((Work_022001DC *)d_0220AF20->h190, b, (Rec_022001DC *)buf);
}

















void func_021F7E74(u32 a)
{
    func_021F7A28(a, 0x285);
}

















/*
 * Unlabelled tail-call stub, filed as a witness for the caller ov093 func_021EA354 (wave B3 lane 17).
 */
void func_021F7E84(u32 a)
{
    func_021F7A28(a, 0x286);
}

















/*
 * Thumb tail call through r3 with a constant second argument. Labelled in wave D8.
 */
void func_021F7E94(int a)
{
    func_021F7A28(a, 0x26E);
}

















/*
 * Unlabelled tail-call stub, filed for the caller ov093 func_021D284C (lane S16).
 */
void func_021F7EA4(u32 a)
{
    func_021F7A28(a, 0x26F);
}














int func_021F7EB4(void)
{
    BtlvEff *p = d_0220AF20;
    u32 t = p->f1e8 | p->m0 | p->m1 | p->m2;

    if (t != 0)
        return 1;
    return 0;
}














/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S15).
 */
void func_021F7EE8(void *m, int key)
{
    func_021FEEA8((char *)d_0220AF20->h190, m, key);
}














/*
 * Tail call to func_021FF0F8 with the handle at 0x190 of the global work block.
 */
void func_021F7F04(int a)
{
    func_021FF0F8((Work_021FF0F8 *)d_0220AF20->h190, a);
}












int func_021F7F1C(int i)
{
    if (i < 8)
        return func_021FFD9C((char *)d_0220AF20->h190, i);
    if (d_0220AF20->slots[i - 8] != -1)
        return 1;
    return 0;
}














void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e)
{
    if (!(b & 1)) {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 4;
            break;
        case 0x3D:
            a = 2;
            break;
        case 0x25:
            a = 3;
            break;
        default:
            if (d_02209D0C[a] == 0)
                a = 0;
            else
                a = 1;
            break;
        }
    } else {
        switch (a) {
        case 0:
        case 1:
            if (func_021F88F4())
                a += 0x67;
            break;
        }
    }
    func_021FF088((Work_vE254 *)((u32)d_0220AF20->h190), (void *)a, b);
    if (c != 0 || d != 0 || e != 0)
        func_021FF144((Work_021FF144 *)((u32)d_0220AF20->h190), b, c, d, e);
    d_0220AF20->slots[b - 8] = b;
}














void func_021F8010(int a)
{
    func_021FF0F8((Work_021FF0F8 *)d_0220AF20->h190, a);
    d_0220AF20->slots[a - 8] = -1;
}














void func_021F803C(u32 a, void *m, u32 c)
{
    switch ((u32)d_0220AF20->mode) {
    case 2:
        func_022070C0((W_022070C0 *)((struct W *)d_0220AF20->h1a4), (void *)a, m, 2, c);
        break;
    case 3:
        func_022070C0((W_022070C0 *)((struct W *)d_0220AF20->h1a4), (void *)a, m, 3, c);
        break;
    default:
        func_022070C0((W_022070C0 *)((struct W *)d_0220AF20->h1a4), (void *)a, m, 0, c);
        break;
    }
}














/*
 * extent: Already matched followers begin at 0x021F80E4.
 */
void func_021F8090(u32 a, u32 b, u32 c)
{
    switch ((u32)d_0220AF20->mode) {
    case 2:
        func_02207288((W_02207288 *)((struct W *)d_0220AF20->h1a4), (void *)a, (void *)b, 2, c);
        break;
    case 3:
        func_02207288((W_02207288 *)((struct W *)d_0220AF20->h1a4), (void *)a, (void *)b, 3, c);
        break;
    default:
        func_02207288((W_02207288 *)((struct W *)d_0220AF20->h1a4), (void *)a, (void *)b, 0, c);
        break;
    }
}














/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S17).
 */
void func_021F80E4(u32 a)
{
    func_02207960((char *)d_0220AF20->h1a4, a);
}














void func_021F80FC(u32 a, u32 b)
{
    func_02207B4C((char *)d_0220AF20->h1a4, a, b);
}












void func_021F8118(u32 a, u32 b)
{
    func_02207B68((char *)d_0220AF20->h1a4, a, b);
}










void func_021F8134(int index, u32 amount)
{
    func_02207B84(d_0220AF20->h1a4, index, amount);
}










void func_021F8150(int index, void *obj)
{
    func_02207BAC(d_0220AF20->h1a4, obj, index);
}












/*
 * Tail call to func_022089AC with the handle at 0x1a4 of the global work block.
 */
void func_021F8168(void)
{
    func_022089AC(d_0220AF20->h1a4);
}












/*
 * Tail call to func_02207C94 with the handle at 0x1a4 of the global work block.
 */
int func_021F8180(void)
{
    return func_02207C94(d_0220AF20->h1a4);
}












/*
 * Tail call to func_02207CC4 with the handle at 0x1a4 of the global work block.
 */
void func_021F8198(int a, int b)
{
    func_02207CC4(d_0220AF20->h1a4, a, b);
}












void func_021F81B4(u32 a, u32 b)
{
    func_02207D04((struct O *)d_0220AF20->h1a4, a, b);
}










/*
 * Unlabelled leaf, filed as the blocker of ov093 func_021D2234 (lane S15).
 */
void func_021F81D0(u32 a, u32 b)
{
    func_02208814((struct O *)d_0220AF20->h1a4, a, b);
}







void func_021F81EC(int sel)
{
    func_02208870((void *)d_0220AF20->h1a4, sel);
}


































int func_021F8204(int index)
{
    return func_02207D60((u8 *)d_0220AF20->h1a4, index);
}






































/*
 * Forwards three arguments to func_02208958 with the handle at 0x1a4 of the global work block.
 */
int func_021F821C(int a, int *b, int *c)
{
    return func_02208958(d_0220AF20->h1a4, a, b, c);
}






































void func_021F823C(u32 *p)
{
    u32 r = func_02208DAC(p, d_0220AF20->heap);

    d_0220AF20->h1a8[p[0]] = (void *)r;
}





































/*
 * Leaf blocking ov093 BTLV_SCU_ProcEntrySingleTrainer.
 */
void func_021F8260(u32 i)
{
    func_02209068(d_0220AF20->h1a8[i]);
}





































int func_021F827C(u32 i)
{
    return func_022090A4((int *)d_0220AF20->h1a8[i]);
}






































void func_021F8298(u32 a, u8 b, u8 c, u8 d, u16 e)
{
    if (a == 0 || a == 2 || a == 4)
        func_021F69E8((S69E8 *)((u32)d_0220AF20->h194), b, c, d, e);
    if (a == 1 || a == 2 || a == 4)
        func_021F6DEC((S6DEC *)((u32)d_0220AF20->h198), b, c, d, e);
    if (a - 3 <= 1)
        PALANM_RequestFade(d_0220AF20->h18c, 1, 0xFF00, (s8)d, b, c, e, *(void **)d_0220AF20);
}






































int func_021F8324(u32 a)
{
    int x = 0;
    int y = 0;
    int z = 0;

    if (a == 0 || a == 2 || a == 4)
        x = func_021F6A18((char *)d_0220AF20->h194);
    if (a == 1 || a == 2 || a == 4)
        y = func_021F6E1C((char *)d_0220AF20->h198);
    if (a - 3 <= 1) {
        z = PALANM_GetFadeRequestBits((const char *)d_0220AF20->h18c) != 0;
    }
    if (x == 1 || y == 1 || z == 1)
        return 1;
    return 0;
}




































void func_021F839C(u32 a, u32 b)
{
    switch (a) {
    case 0:
        func_021F6A28((Obj_021F6A28 *)((u32)d_0220AF20->h194), 2, b);
        break;
    case 1:
        func_021F6E2C((Obj_021F6E2C *)((u32)d_0220AF20->h198), b);
        break;
    case 2:
        func_02040588(3, (u8)(b ^ 1));
        break;
    case 3:
        func_021F6A28((Obj_021F6A28 *)((u32)d_0220AF20->h194), 0, b);
        break;
    case 4:
        func_021F6A28((Obj_021F6A28 *)((u32)d_0220AF20->h194), 1, b);
        break;
    }
}


































void func_021F8414(int a, int b, int c)
{
    St *s = sub_02030734((u16)((d_0220AF20->heap & 0x7FFF) | 0x8000), 0x10, 0, d_0220AC90, 0x538);

    if (a != 1) {
        s->state = 0;
        s->b = (a == 3) ? 0 : 1;
        s->c = b;
        s->d = c;
        d_0220AF20->m2 |= func_021F935C(b);
        func_021F896C(func_02030DA8(d_0220AF20->owner, func_021F8F30, s, 0), func_021F8FB0, 0);
    }
}



































void func_021F84B4(u32 a, u32 b)
{
    func_021FF7B0((Work_021FF7B0 *)((u32)d_0220AF20->h190), a, b);
}



































/*
 * Returns slot a-8 of the table at 0x1f8 of the global work block.
 */
int func_021F84D0(int a)
{
    return d_0220AF20->slots[a - 8];
}



































/*
 * Tail call to func_02209318 with the handle at 0x1b0 of the global work block.
 */
void func_021F84E8(int a, int b)
{
    func_02209318(d_0220AF20->h1b0, a, b);
}



































void func_021F8504(u32 a, u32 b, u32 c)
{
    func_022094BC((u8 *)d_0220AF20->h1b0, a, b, c);
}



































/*
 * Thumb tail call through r3: the work record at +0x1B0 of d_0220AF20 and the argument. Labelled in wave D8.
 */
int func_021F8524(int i)
{
    return func_02209500((struct W *)d_0220AF20->h1b0, i);
}



































/*
 * Tail call to func_021FF348 with the handle at 0x190 of the global work block.
 * Unlabelled; filed as a witness for the caller ov093 func_021EA354 (wave B3 lane 17).
 */
int func_021F853C(int a)
{
    return func_021FF348((Work_021FF348 *)d_0220AF20->h190, a);
}
































void func_021F8554(u32 flags, int kind, int n, int s, int t)
{
    VecFx32_021F8204 a;
    VecFx32_021F8204 b;

    if (flags & 1) {
        func_021F8628(flags, (int *)(&a), (int *)(&b));
        switch (kind) {
        case 0:
            func_021F6EDC(d_0220AF20->h19c, (int *)(&a), (int *)(&b));
            break;
        case 1:
            func_021F6F48((Cam_021F6F48 *)d_0220AF20->h19c, (VecFx32_v6560 *)&a, (VecFx32_v6560 *)&b, n, s, t);
            break;
        }
        return;
    }
    switch (d_0220AF20->mode) {
    case 0:
        func_021F7998(0x23F);
        break;
    case 1:
        if (flags == 2) {
            func_021F7998(0x240);
        } else {
            func_021F7998(0x241);
        }
        break;
    case 2:
        if (flags == 2) {
            func_021F7998(0x242);
        } else if (flags == 4) {
            func_021F7998(0x23F);
        } else {
            func_021F7998(0x243);
        }
        break;
    case 3:
        func_021F7998(0x245);
        break;
    }
}
































void func_021F8628(u32 a, int *out, int *p)
{
    func_021FF3F4((void *)d_0220AF20->h190, p, a);
    out[0] = p[0] + 0x4B33;
    out[1] = p[1] + 0x2299;
    out[2] = p[2] + 0x99CD;
    p[1] = p[1] + 0x2000;
}

































void *func_021F8678(void)
{
    return g_0220AF20;
}

































int func_021F8684(void)
{
    return (int)d_0220AF20->h19c;
}






























int func_021F8694(void)
{
    return (int)d_0220AF20->h190;
}































int func_021F86A4(void)
{
    return (int)d_0220AF20->h194;
}
































/*
 * Returns the word at 0x1a4 of the global work block.
 */
int func_021F86B4(void)
{
    return (int)d_0220AF20->h1a4;
}
































/*
 * Returns the word at 0x188 of the global work block.
 */
int func_021F86C4(void)
{
    return (int)d_0220AF20->h188;
}
































void *func_021F86D4(void)
{
    return *(void **)g_0220AF20;
}
































/*
 * Returns the word at 0x18c of the global work block.
 */
int func_021F86E0(void)
{
    return (int)d_0220AF20->h18c;
}































/*
 * Returns the word at 0x1a0 of the global work block.
 */
int func_021F86F0(void)
{
    return (int)d_0220AF20->h1a0;
}































/*
 * Returns the word at 0x1b4 of the global work block.
 */
int func_021F8700(void)
{
    return (int)d_0220AF20->h1b4;
}




























int func_021F8710(void)
{
    return d_0220AF20->mode;
}






























/*
 * Returns the word at 0x1c0 of the global work block.
 */
int func_021F8720(void)
{
    return d_0220AF20->f1c0;
}































/*
 * Returns the word at 0x1dc of the global work block.
 */
int func_021F8730(void)
{
    return d_0220AF20->f1dc;
}































/*
 * Returns halfword a of the table at 0x1d4 of the global work block.
 */
unsigned short func_021F8740(int a)
{
    return d_0220AF20->f1d4[a];
}































/*
 * Returns the word at 0x1e4 of the global work block.
 */
int func_021F8754(void)
{
    return (int)d_0220AF20->param_battle;
}































/*
 * Returns the word at 0x1e0 of the global work block.
 */
int func_021F8764(void)
{
    return d_0220AF20->f1e0;
}





























/*
 * Tail call to func_022088F4 with the handle at 0x1a4 of the global work block.
 */
void func_021F8774(void)
{
    func_022088F4(d_0220AF20->h1a4);
}




























void func_021F878C(u32 a)
{
    if (func_022088F4((void *)d_0220AF20->h1a4)) {
        func_02208900((u32)d_0220AF20->h1a4, 0);
        GFL_USE_PopBgm();
    }
    func_0220893C((u32)d_0220AF20->h1a4, 1);
    GFL_USE_CancelChangeAndPlayBgm(a, 0xFFFF);
}


























/*
 * Witness leaf for ov093 func_021ED4E4: tail call (obj, v) to func_0220893C.
 */
void func_021F87D4(u32 v)
{
    func_0220893C((u32)d_0220AF20->h1a4, v);
}

























void func_021F87EC(u32 v)
{
    d_0220AF20->f1f4 = 1;
    func_02208918(d_0220AF20->h1a4, v);
    if (func_022088F4(d_0220AF20->h1a4) == 0)
        func_02208924(d_0220AF20->h1a4, 1);
}
























int func_021F882C(void)
{
    return d_0220AF20->f1f4;
}























void func_021F883C(u32 a)
{
    if (func_022088F4(d_0220AF20->h1a4) == 1)
        GFL_USE_PopBgm();
    func_0220893C((u32)d_0220AF20->h1a4, 1);
    func_02208900((u32)d_0220AF20->h1a4, 0);
    GFL_USE_CancelChangeAndPlayBgm(a, 0x0000FFFF);
}























/*
 * Stores the low 8 bits of the argument in bits 18..25 of the word at 0x1ec of the global work block.
 */
void func_021F8884(int a)
{
    d_0220AF20->v = a;
}























/*
 * Returns bits 18..25 of the word at 0x1ec of the global work block.
 */
int func_021F88A8(void)
{
    return d_0220AF20->v;
}






















/*
 * Sets flag bit 26 of the word at 0x1ec of the global work block.
 */
void func_021F88BC(int a)
{
    d_0220AF20->b26 = a;
}






















int func_021F88E0(void)
{
    return d_0220AF20->b26;
}






















/*
 * Returns func_021BA1EC of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int func_021F88F4(void)
{
    int r = 0;
    void *h = d_0220AF20->param_battle;
    if (h != 0)
        r = func_021BA1EC(h);
    return r;
}






















/*
 * Returns func_021BA20C of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int func_021F8914(void)
{
    int r = 0;
    void *h = d_0220AF20->param_battle;
    if (h != 0)
        r = func_021BA20C(h);
    return r;
}





















/*
 * Runs func_0220055C with a (enum counter keeps the entry guard) on each of the first 8 active slots of the handle at 0x190.
 */
void func_021F8934(int a)
{
    Slot_021F6560 i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(d_0220AF20->h190, i) != 0)
            func_0220055C((Work_0220055C *)d_0220AF20->h190, i, a);
    }
}




















void func_021F896C(void *h, void (*cb)(void *), int arg)
{
    int i = func_021F8B40();

    d_0220AF20->handle[i] = h;
    d_0220AF20->cb[i] = cb;
    d_0220AF20->arg[i] = arg;
}





















int func_021F899C(void *h)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->handle[i] == h)
            break;
    }
    return i;
}





















void func_021F89BC(void *h)
{
    int i = func_021F899C(h);
    void *w;

    if (h == 0)
        return;
    w = (void *)TCBL_IsDeletePending(h);
    if (d_0220AF20->cb[i] != 0)
        d_0220AF20->cb[i](h);
    if (w != 0)
        sub_020307B0(w);
    sub_02030EAC(h);
    d_0220AF20->handle[i] = 0;
    d_0220AF20->cb[i] = 0;
}


















/*
 * Runs func_021F89BC on each live object owned by a.
 */
void func_021F8A10(int a)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->handle[i] != 0 && a == d_0220AF20->arg[i])
            func_021F89BC(d_0220AF20->handle[i]);
    }
}

















void func_021F8A40(int a)
{
    d_0220AF20->f238 = a;
    if (d_0220AF20->f238 != 2) {
        d_0220AF20->f23c = 0;
        d_0220AF20->f240 = 0;
    }
    if (a == 3)
        func_02200608((Work_02200608 *)d_0220AF20->h190);
}
















void func_021F8A78(void)
{
    func_021F7BEC();
    if (d_0220AF20->f238 == 3 && func_021BA1A8(d_0220AF20->param_battle, 0x400))
        func_021F7998(0x251);
    else
        func_021F7998(0x236);
    d_0220AF20->f238 = 0;
}















/*
 * Calls func_021F7BEC, then stores the argument at 0x238 and clears 0x23c and 0x240 of the global work block.
 */
void func_021F8AC0(int a)
{
    func_021F7BEC();
    d_0220AF20->f238 = a;
    d_0220AF20->f23c = 0;
    d_0220AF20->f240 = 0;
}














void func_021F8AE8(int i, u32 v)
{
    d_0220AF20->tbl[i] = v;
}














int func_021F8AFC(int i)
{
    return d_0220AF20->tbl[i];
}














void func_021F8B10(void)
{
    func_021F9A7C(d_0220AF20->h188);
}














void func_021F8B28(void)
{
    func_021F9AA4(d_0220AF20->h188);
}













int func_021F8B40(void)
{
    BtlvEff *w;
    int i;

    i = 0;
    w = d_0220AF20;
    for (; i < 32; i++) {
        if (w->handle[i] == 0)
            break;
    }
    if (i == 32) {
        func_021F89BC(w->handle[0]);
        i = 0;
    }
    return i;
}














/*
 * Runs func_021F89BC on each of the 32 live objects at 8 of the global work block.
 */
void func_021F8B6C(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->handle[i] != 0)
            func_021F89BC(d_0220AF20->handle[i]);
    }
}














/*
 * Calls CLACT_VBlankSystem, then PALANM_TransferPalettes on the handle at 0x18c of the global work block.
 */
void func_021F8B90(void *h, void *arg)
{
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(d_0220AF20->h18c);
}













void func_021F8BAC(void *h, void *arg)
{
    int *p = arg;

    if (p[3] != 0) {
        p[3]--;
        return;
    }
    switch (p[1]) {
    case 0:
        if (p[5] == 0)
            func_021FFDB4((Work_vFCB0 *)d_0220AF20->h190, p[0], 16, 16, 0, p[4]);
        p[3] = 3;
        p[1] = 1;
        break;
    case 1:
        if (p[5] == 0)
            func_021FF374((Work_vF228 *)d_0220AF20->h190, p[0], 1);
        p[3] = 3;
        p[1] = 2;
        break;
    case 2:
        p[1] = 0;
        if (p[5] == 0) {
            func_021FF374((Work_vF228 *)d_0220AF20->h190, p[0], 0);
            func_021FFDB4((Work_vFCB0 *)d_0220AF20->h190, p[0], 0, 0, 0, 0x7fff);
        }
        p[3] = 3;
        if (--p[2] == 0)
            func_021F89BC(h);
        break;
    }
}











/*
 * Clears the current task's mask bits from the low byte at 0x1ec of the global work block.
 */
void func_021F8C78(void *h)
{
    int m = func_021F935C(*((int *)TCBL_IsDeletePending(h)));
    d_0220AF20->m0 &= m ^ 0xffffffff;
}










void func_021F8CB0(void *h, void *arg)
{
    int *p = arg;

    switch (p[1]) {
    case 0:
        func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x253, 0);
        d_0220AF20->f1e8 = 1;
        p[1]++;
        break;
    case 1:
        if (d_0220AF20->f1e8 == 0) {
            if (func_021FFF38(d_0220AF20->h190, p[0]) & 1) {
                func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x264, 0);
                d_0220AF20->f1e8 = 1;
            }
            p[1]++;
        }
        break;
    case 2:
        if (d_0220AF20->f1e8 == 0) {
            func_021FF924(d_0220AF20->h190, p[0], 0, 16, 0, 0, 0);
            func_021FFBBC(d_0220AF20->h190, p[0], 1, 8, 8, 1, 0);
            func_021F9858(d_0220AF20->h188, 0x5aa, 1, 14, -500, 127, 0, 0, 0);
            func_021F9948(d_0220AF20->h188, 1, 0, 1, 127, 0, 30, 10, 0, 0);
            p[1]++;
        }
        break;
    case 3:
        if (func_021FFCB0((Work_021FFCB0 *)d_0220AF20->h190, p[0]) == 0) {
            func_022001DC((Work_022001DC *)d_0220AF20->h190, p[0], (Rec_022001DC *)(&p[2]));
            p[1]++;
        }
        break;
    case 4:
        func_021FFBBC(d_0220AF20->h190, p[0], 1, 0, 8, 1, 0);
        p[1]++;
        break;
    case 5:
        if (func_021FFCB0((Work_021FFCB0 *)d_0220AF20->h190, p[0]) == 0) {
            func_021F9858(d_0220AF20->h188, 0x560, 1, 14, 0, 0, 0, 0, 0);
            func_021FF924(d_0220AF20->h190, p[0], 0, 31, 0, 0, 0);
            if (func_021FFF38(d_0220AF20->h190, p[0]) & 1) {
                func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x265, 0);
                d_0220AF20->f1e8 = 1;
            }
            p[1]++;
        }
        break;
    case 6:
        if (d_0220AF20->f1e8 == 0) {
            func_021F94F8(d_0220AF20->h188, p[0], 0xff, 0x254, 0);
            d_0220AF20->f1e8 = 1;
            p[1]++;
        }
        break;
    case 7:
        if (d_0220AF20->f1e8 == 0)
            func_021F89BC(h);
        break;
    }
}









/*
 * Clears the current task's mask bits from bits 8..15 of the word at 0x1ec of the global work block.
 */
void func_021F8EF8(void *h)
{
    int m = func_021F935C(((int *)TCBL_IsDeletePending(h))[0]);
    d_0220AF20->m1 &= m ^ 0xffffffff;
}











void func_021F8F30(void *h, void *p)
{
    St *s = p;
    int st;
    u32 m;

    st = s->state;
    switch (st) {
    case 0:
        m = d_0220AF20->m0 | d_0220AF20->f1e8 | d_0220AF20->m1;
        if (m)
            return;
        s->state = st + 1;
    case 1:
        func_02200344((Work_02200344 *)d_0220AF20->h190, s->c, s->b, s->d);
        s->state = s->state + 1;
        return;
    case 2:
        if (func_021F6AD0((Obj_021F6AD0 *)d_0220AF20->h194))
            return;
        if (func_021FFD6C((Work_021FFD6C *)d_0220AF20->h190))
            return;
        func_021F89BC(h);
        return;
    }
}











void func_021F8FB0(void *h)
{
    int m = func_021F935C(((int *)TCBL_IsDeletePending(h))[2]);
    d_0220AF20->m2 &= m ^ 0xffffffff;
}










void func_021F8FE8(void *h, void *arg)
{
    Arg_v8204 *p = arg;

    if (func_021F7EB4() == 0) {
        func_021F94F8(d_0220AF20->h188, p->a, p->b, p->c, p->d);
        d_0220AF20->f1e8 = 1;
        func_021F89BC(h);
    }
}













/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Frees the buffer at 0x10 of the current task's work, if any.
 */
void func_021F9028(void *h)
{
    void *p = *(void **)(TCBL_IsDeletePending(h) + 0x10);
    if (p != 0)
        func_020307B0(p);
}













/*
 * lever: Assign table lookups to a shared local before the call; duplicated
 * calls cross-jump the indexed load and shorten the function by four bytes.
 */
void func_021F903C(void)
{
    int a, b;
    u32 n, value;
    a = func_020362DC();
    b = TOUCHPANEL_GetTrg();
    if (d_0220AF20->f238 == 0)
        return;
    if (d_0220AF20->f238 != 2 && d_0220AF20->f238 != 3 && (a != 0 || b != 0)) {
        func_021F7BEC();
        func_021F7998(0x252);
        d_0220AF20->f23c = 0;
        d_0220AF20->f240 = 0;
    }
    switch (d_0220AF20->f23c) {
    case 0:
        if (d_0220AF20->f240 < d_0220AF20->f244) {
            d_0220AF20->f240++;
            return;
        }
        d_0220AF20->f23c = 1;
    case 1:
        if (func_021F7EB4() == 0) {
            if (d_0220AF20->f238 == 3 && func_021BA1A8(d_0220AF20->param_battle, 0x400)) {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 2) >> 32);
                } while (d_0220AF20->f248 == n);
                d_0220AF20->f248 = n;
                value = d_0220AC70[d_0220AF20->f248];
            } else {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 6) >> 32);
                } while (d_0220AF20->f248 == n);
                d_0220AF20->f248 = n;
                value = d_0220AC78[d_0220AF20->f248];
            }
            func_021F7998(value);
            d_0220AF20->f1e8 = 1;
        }
        break;
    }
}













/*
 * Signed step from a to b in units of c (default 0x1000), at least one unit.
 */
void func_021F9154(int a, int b, int *out, int c)
{
    *out = 0;
    if (b - a == 0)
        return;
    if (c == 0)
        c = 0x1000;
    *out = func_0207C768(b - a, c);
    if (*out == 0) {
        if (b > a)
            *out = 1;
        else
            *out = -1;
    }
}













void func_021F918C(const VecFx32_021F8F30 *a, const VecFx32_021F8F30 *b, VecFx32_021F8F30 *out, fx32 div)
{
    out->x = 0;
    out->y = 0;
    out->z = 0;
    if (div == 0)
        div = 0x1000;
    if (b->x - a->x != 0) {
        out->x = sub_0207C768(b->x - a->x, div);
        if (out->x == 0)
            out->x = (b->x > a->x) ? 1 : -1;
    }
    if (b->y - a->y != 0) {
        out->y = sub_0207C768(b->y - a->y, div);
        if (out->y == 0)
            out->y = (b->y > a->y) ? 1 : -1;
    }
    if (b->z - a->z != 0) {
        out->z = sub_0207C768(b->z - a->z, div);
        if (out->z == 0)
        {
            if (b->z > a->z)
                out->z = 1;
            else
                out->z = -1;
        }
    }
}












/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
void func_021F9220(int *p, int *d, int *lim, int *flag)
{
    int n = *p + *d;
    *p = n;
    if (*d < 0) {
        if (n <= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    } else {
        if (n >= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    }
}













int func_021F9260(Mover_v8204 *m, VecFx32_021F8F30 *out)
{
    int ret = 1;

    switch (m->mode) {
    case 0:
        out->x = m->start.x;
        out->y = m->start.y;
        out->z = m->start.z;
        break;
    case 1:
    case 4:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            func_021F9220(&out->x, &m->step.x, &m->start.x, &ret);
            func_021F9220(&out->y, &m->step.y, &m->start.y, &ret);
            func_021F9220(&out->z, &m->step.z, &m->start.z, &ret);
        } else {
            m->wait--;
            ret = 0;
        }
        break;
    case 2:
    case 3:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            out->x += m->step.x;
            out->y += m->step.y;
            out->z += m->step.z;
            if (--m->count == 0) {
                m->repeat--;
                m->count = m->countReset;
                if (m->mode == 2 || (m->mode == 3 && (m->repeat & 1))) {
                    m->step.x *= -1;
                    m->step.y *= -1;
                    m->step.z *= -1;
                }
            }
        } else {
            m->wait--;
        }
        if (m->repeat != 0) {
            ret = 0;
        } else {
            out->x = m->end.x;
            out->y = m->end.y;
            out->z = m->end.z;
        }
        break;
    }
    return ret;
}












int func_021F935C(int x)
{
    return 1 << x;
}













void func_021F9364(P *p)
{
    int i;
    Q_v8204 *q;
    u32 sz;
    u32 off;

    if (p->en != 0) {
        if (p->cnt == 0) {
            p->cnt = p->rl;
            for (i = 0; i < p->n; i++) {
                q = (Q_v8204 *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile((struct Tagged *)p->a0[i]));
                sz = q->h30 << 3;
                off = (u16)q->w2c << 3;
                PALANM_BlendColors((u16 *)((char *)q + q->o38), p->a4[i], (u16)(sz >> 1), p->cur, p->col);
                func_02061CA4((void *)1, off, (u32)p->a4[i], sz);
            }
            if (p->cur == p->tgt) {
                p->en = 0;
            } else if (p->cur > p->tgt) {
                p->cur = p->cur - 1;
            } else {
                p->cur = p->cur + 1;
            }
        } else {
            p->cnt = p->cnt - 1;
        }
    }
}













void *func_021F93F4(void *a, u32 b)
{
    T_021F93F4 *t;
    void *vm;
    int i;

    t = func_02030734(b, 0x2AC, 1, d_0220AE68, 0x27D);
    t->h238 = b;
    t->a = a;
    t->f23c = 1;
    t->f244 = 1;
    for (i = 0; i < 16; i++)
        t->v4c[i] = -1;
    for (i = 0; i < 4; i++)
        t->vcc[i] = -1;
    for (i = 0; i < 6; i++)
        t->e26c[i] = -1;
    vm = VM_Create(b, (const struct ScriptVmParams *)d_02209DCC);
    VM_Init(vm, t);
    return vm;
}













int func_021F9478(void *vm)
{
    int r;
    T_021F9478 *t;

    r = VM_Control(vm);
    t = func_02011324(vm);
    if (t->b7)
        return 0;
    if (r == 0 && t->h != 0) {
        func_021F8198(1, 2);
        if (t->b6 == 0)
            func_021FE410((Obj_021FE254 *)t, 0x6B000, 0x7F000, 0x14);
        func_020307B0(t->h);
        t->h = 0;
    }
    return r;
}












/*
 * Tears down the owner's work: func_021F97E4, free, then VM_Delete.
 */
void func_021F94D8(void *a)
{
    void *s = func_02011324(a);
    func_021F97E4(a);
    func_020307B0(s);
    VM_Delete(a);
}












void func_021F94F8(void *vm, u32 a1, u32 a2, u16 id, Quad_v8204 *q)
{
    T *t;
    int off;
    int flag;
    u8 *p;

    t = func_02011324(vm);
    t->f1e8 = 0;
    func_021F8A10(1);
    if (q != 0)
        t->q248 = *q;
    else
        func_02082A48(0, &t->q248, 0x10);
    t->fdc = a1;
    t->fe0 = a2;
    t->f244 = 1;
    t->h258 = id;
    if (t->h258 >= 0x231 && (u16)(t->h258 + 0xFD9F) <= 1
        && t->f2a4 == t->h258 && t->f2a8 == a1)
        return;
    t->f2a4 = t->h258;
    t->f2a8 = a1;
    if (func_021FEAA0(t->h258) == 0)
        func_021F8934(0);
    if (t->h258 < 0x231) {
        t->f1e8 = ARC_TOOL_LoadMember(0x42, id, (u16)((t->h238 & 0x7fff) | 0x8000));
        if (t->h258 != 0x90 && t->h258 != 0x77 && t->h258 != 0x10b)
            func_021F8198(0, 2);
        func_02040588(1, 0);
        func_02040588(2, 0);
        func_02040588(3, 0);
        t->b6 = 0;
        func_021FE410((Obj_021FE254 *)((T_021F9478 *)t), 0x7F000, 0x6B000, 0x14);
    } else {
        t->f1e8 = ARC_TOOL_LoadMember(0x43, id - 0x231, (u16)((t->h238 & 0x7fff) | 0x8000));
        t->b6 = 1;
        if (id >= 0x256 && (*(volatile u16 *)0x04000052 & 0x1f) == 0)
            func_02040588(1, 0);
    }
    off = 4;
    if (q != 0) {
        if (*t->f1e8 <= ((u8 *)q)[1])
            ((u8 *)q)[1] = 0;
        off += ((u8 *)q)[1] * 0x38;
    }
    flag = 0;
    if (func_021FFD9C((char *)func_021F8694(), t->fdc)) {
        if (((t->h258 == 0xf8 || t->h258 == 0x161) && ((u8 *)q)[1] == 1)
            || t->h258 == 0x90 || t->h258 == 0x77 || t->h258 == 0x10b) {
        } else {
            flag = func_021FFF38((char *)func_021F8694(), t->fdc) & 1;
        }
    }
    if (t->h258 == 0x27e)
        t->b18 = 1;
    if (t->h258 == 0x291)
        t->b18 = 0;
    if (t->h258 == 0x27e && flag) {
        t->f1ec = t->f1e8;
        t->f1f0 = off;
        t->f1e8 = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((t->h238 & 0x7fff) | 0x8000));
        t->b6 = 1;
        t->b17 = 1;
        off = 4;
    } else if (!t->b6 && t->h258 != 0x90 && !t->b17 && flag) {
        t->f1ec = t->f1e8;
        t->f1f0 = off;
        t->f1e8 = ARC_TOOL_LoadMember(0x43, 0x33, (u16)((t->h238 & 0x7fff) | 0x8000));
        t->b6 = 1;
        off = 4;
    }
    p = t->f1e8;
    t->f4 = 0;
    t->b12 = 0;
    t->f25c = 8;
    VM_Start(vm, t->f1e8 + *(int *)(p + off));
}










/*
 * Releases the owner's buffer at 0x1e8 after func_021FC448.
 */
void func_021F97E4(void *a)
{
    char *s = func_02011324(a);

    if (((struct Obj10136 *)s)->f1E8 != 0) {
        func_021FC448(a, (State_021FC448 *)(func_02011324(a)));
        func_020307B0(((struct Obj10136 *)s)->f1E8);
        ((struct Obj10136 *)s)->f1E8 = 0;
    }
}












/*
 * Clears flag bit 7 of the owner's work.
 */
void func_021F9814(void *a)
{
    *(u32 *)func_02011324(a) &= ~0x80;
}













/*
 * Returns flag bit 6 of the owner's work when the handle at 0x1e8 is set, else -1.
 */
int func_021F9824(void *a)
{
    Flags_021F9814 *s = (void *)func_02011324(a);
    int r = -1;

    if (((struct Obj21656 *)s)->f1E8 != 0)
        r = s->b6;
    return r;
}













void func_021F9844(S9844 *p)
{
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 0;
    p->b3 = 0;
    p->w1 = 0;
    p->w2 = 0;
    p->h1 = 0;
}












void func_021F9858(void *vm, u32 a, int b, u32 c, int e, u32 f, int g, int h, int d)
{
    Work_v9814 *w;
    Job_021F9858 *j;
    w = (void *)func_02011324(vm);
    if (func_021F88E0() == 1)
        return;
    w->flags |= 0x1000;
    if (c == 2)
        c = 0;
    else if (c <= 1) {
        if (c & 1)
            c = 127;
        else
            c = -128;
    } else {
        if (func_021FCF2C((int)vm, c) & 1)
            c = 127;
        else
            c = -128;
    }
    if (g > 255)
        g = 255;
    if (h > 255)
        h = 255;
    if (d == 0) {
        func_021FDB40(a, b, c, e, f, g, h);
        return;
    }
    j = func_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x24, 0, d_0220AE68, 0x431);
    j->work = w;
    j->a = a;
    j->b = b;
    j->c = c;
    j->d = d;
    j->e = e;
    j->f = f;
    j->g = g;
    j->h = h;
    w->flags |= 4;
    func_021F896C(func_02030DA8(w->owner, func_021FE54C, j, 0), func_021FE580, 1);
}












void func_021F9948(void *vm, u32 a, int mode, int c, int x, int dest, int e, int f, int g, int duration)
{
    Work_v9814 *w;
    Job_021F9948 *j;
    float ff;
    int fd;
    w = (void *)func_02011324(vm);
    j = func_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0x455);
    j->work = w;
    j->a = a;
    j->mode = mode;
    j->c = c;
    j->x = x;
    j->dest = dest;
    j->e = e;
    j->f = f;
    j->remaining = f;
    j->zero = 0;
    j->g = g;
    j->duration = duration * 2;
    if (mode == 1 && j->duration == 0)
        j->duration = 2;
    j->fx = FX(j->x);
    if (j->f > 0)
        ff = 0.5f + (float)(j->f << 12);
    else
        ff = (float)(j->f << 12) - 0.5f;
    fd = FX(j->dest - j->x);
    j->delta = func_0207C768(fd, (int)ff);
    func_021F896C(func_02030DA8(w->owner, func_021FE594, j, 0), func_021FE690, 1);
    w->flags |= 8;
}












/*
 * Stops every live sound slot of the owner's work (six words at 0x26c, -1 = free).
 */
void func_021F9A7C(void *a)
{
    char *s = (void *)func_02011324(a);
    int i;

    for (i = 0; i < 6; i++) {
        if (((int *)(s + 0x26c))[i] != -1)
            PM_VOICE_StopSlot(((int *)(s + 0x26c))[i]);
    }
}












/*
 * Clears the two words at 0x2a4 and 0x2a8 of the owner's work.
 */
void func_021F9AA4(void *a)
{
    char *s = (void *)func_02011324(a);
    ((struct Obj13584 *)s)->f2A4 = 0;
    ((struct Obj13584 *)s)->f2A8 = 0;
}










/*
 * note: d_0220ACA0 holds six vectors but is declared with a short bound. Cases 14, 18 and
 *   19 index past it; MWCC then treats those loads as possibly aliasing A/B and keeps each
 *   load after the preceding store (any bound 1..4 matches; in-bounds models such as [6],
 *   [2][3] or a pair struct hoist the last load above the B.y store).
 */
int func_021F9AB8(void *r, Ctx_021F9814 *c)
{
    VecFx32_v9814 A;
    VecFx32_v9814 B;
    int type;
    int mode;
    int n;
    int s;
    int t;
    int k;
    int v;

    type = VM_GetU32(r);
    mode = VM_GetU32(r);
    n = VM_GetU32(r);
    s = VM_GetU32(r);
    t = VM_GetU32(r);
    if (c->flags.f15) {
        return c->ret;
    }
    if (mode == 13 && c->h284 == 0) {
        mode = 8;
    }
    if (mode != 8 && mode != 15 && mode != 16 && mode != 14 && mode != 17) {
        func_021FDB20((State_021FDB20 *)((Ctx_021F9814 *)c));
    } else {
        c->flags.f1 = 1;
    }
    switch (mode) {
    case 15:
    case 16:
        k = func_021F8710();
        if (mode == 15) {
            v = c->dc;
        } else {
            v = c->e0;
        }
        switch (k) {
        case 0:
            return c->ret;
        case 1:
        case 2:
            switch (v) {
            case 2:
                mode = 2;
                break;
            case 3:
                mode = 8;
                if (k != 1) {
                    mode = 18;
                }
                break;
            case 4:
                mode = 4;
                if (k != 1) {
                    mode = 8;
                }
                break;
            case 5:
                mode = 8;
                break;
            case 6:
                mode = 8;
                if (k != 1) {
                    mode = 6;
                }
                break;
            case 7:
            default:
                return c->ret;
            }
            break;
        case 3:
            if (v == 4 || v == 6) {
                mode = 19;
            }
            break;
        }
        break;
    case 14:
        k = func_021F8710();
        if (k == 0 || k == 3) {
            return c->ret;
        }
        break;
    case 20:
        k = func_021F8710();
        if (k == 0 || k == 3) {
            func_021FF16C((Work_021FF16C *)((void *)func_021F8694()));
            return c->ret;
        }
        mode = 14;
        break;
    case 21:
        k = func_021F8710();
        if (k == 0 || k == 3) {
            mode = c->dc;
        } else if (c->dc & 1) {
            mode = 1;
        } else {
            mode = 14;
        }
        break;
    case 17:
        mode = 8;
        break;
    case 9:
    case 10:
        k = func_021F8710();
        mode = c->dc;
        if (k == 3 && (mode == 4 || mode == 6)) {
            mode = 19;
        }
        break;
    case 11:
    case 12:
        switch (c->b248) {
        case 0:
        case 1:
        case 2:
        case 3:
            mode = c->e0;
            if (mode == 0xff) {
                mode = (c->dc & 1) ^ 1;
            }
            break;
        case 5:
        case 7:
        case 9:
        case 13:
            mode = c->e0;
            if (mode != 0xff) {
                break;
            }
        case 11:
            mode = (c->dc & 1) ^ 1;
            break;
        case 6:
        case 12:
            mode = c->dc & 1;
            break;
        case 4:
        case 8:
        case 10:
            k = func_021F8710();
            if (k == 0 || k == 3) {
                mode = (c->dc & 1) ^ 1;
            } else {
                mode = 14;
            }
            break;
        }
        break;
    }
    switch (mode) {
    case 0:
    case 1:
        A.x = d_0220ACE8[mode].x;
        A.y = d_0220ACE8[mode].y;
        A.z = d_0220ACE8[mode].z;
        B.x = d_0220AD00[mode].x;
        B.y = d_0220AD00[mode].y;
        B.z = d_0220AD00[mode].z;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        k = func_021F8710();
        if (k == 3) {
            A.x = d_0220ACE8[mode - 2].x;
            A.y = d_0220ACE8[mode - 2].y;
            A.z = d_0220ACE8[mode - 2].z;
            B.x = d_0220AD00[mode - 2].x;
            B.y = d_0220AD00[mode - 2].y;
            B.z = d_0220AD00[mode - 2].z;
        } else if (k == 1) {
            A.x = d_0220AD78[mode - 2].x;
            A.y = d_0220AD78[mode - 2].y;
            A.z = d_0220AD78[mode - 2].z;
            B.x = d_0220ADA8[mode - 2].x;
            B.y = d_0220ADA8[mode - 2].y;
            B.z = d_0220ADA8[mode - 2].z;
        } else {
            A.x = d_0220ADD8[mode - 2].x;
            A.y = d_0220ADD8[mode - 2].y;
            A.z = d_0220ADD8[mode - 2].z;
            B.x = d_0220AE20[mode - 2].x;
            B.y = d_0220AE20[mode - 2].y;
            B.z = d_0220AE20[mode - 2].z;
        }
        break;
    case 6:
    case 7:
        A.x = d_0220ADD8[mode - 2].x;
        A.y = d_0220ADD8[mode - 2].y;
        A.z = d_0220ADD8[mode - 2].z;
        B.x = d_0220AE20[mode - 2].x;
        B.y = d_0220AE20[mode - 2].y;
        B.z = d_0220AE20[mode - 2].z;
        break;
    case 13:
        A.x = c->a288.x;
        A.y = c->a288.y;
        A.z = c->a288.z;
        B.x = c->b294.x;
        B.y = c->b294.y;
        B.z = c->b294.z;
        break;
    case 14:
        A.x = d_0220ACA0[0].x;
        A.y = d_0220ACA0[0].y;
        A.z = d_0220ACA0[0].z;
        B.x = d_0220ACA0[2].x;
        B.y = d_0220ACA0[2].y;
        B.z = d_0220ACA0[2].z;
        if (c->flags.f1) {
            func_021FE9F0(0xa66, 0xb9a, n, s, 0);
            c->flags.f13 = 1;
        }
        break;
    case 19:
        A.x = d_0220ACA0[3].x;
        A.y = d_0220ACA0[3].y;
        A.z = d_0220ACA0[3].z;
        B.x = d_0220ACA0[1].x;
        B.y = d_0220ACA0[1].y;
        B.z = d_0220ACA0[1].z;
        if (c->flags.f1) {
            func_021FE9F0(0xa66, 0xb9a, n, s, 0);
            c->flags.f13 = 1;
        }
        break;
    case 18:
        A.x = d_0220ACA0[5].x;
        A.y = d_0220ACA0[5].y;
        A.z = d_0220ACA0[5].z;
        B.x = d_0220ACA0[4].x;
        B.y = d_0220ACA0[4].y;
        B.z = d_0220ACA0[4].z;
        break;
    default:
        func_021F7208((VecFx32_v6560 *)&A, (VecFx32_v6560 *)&B);
        if (c->flags.f13) {
            func_021FE9F0(0x1000, 0x1000, n, s, 0);
            c->flags.f13 = 0;
        }
        break;
    }
    switch (type) {
    case 0:
        func_021F6EDC((int *)func_021F8684(), (int *)(&A), (int *)(&B));
        break;
    case 1:
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)&A, (VecFx32_v6560 *)&B, n, s, t);
        break;
    }
    return c->ret;
}









int func_021F9EFC(void *r, Ctx_021F9EFC *c)
{
    int A[3];
    int B[3];
    int C[3];
    int D[3];
    int n;
    int s;
    int t;
    int type;

    type = VM_GetU32(r);
    A[0] = VM_GetU32(r);
    A[1] = VM_GetU32(r);
    A[2] = VM_GetU32(r);
    B[0] = VM_GetU32(r);
    B[1] = VM_GetU32(r);
    B[2] = VM_GetU32(r);
    n = VM_GetU32(r);
    s = VM_GetU32(r);
    t = VM_GetU32(r);
    func_021FDB20((State_021FDB20 *)((Ctx_021F9814 *)c));
    switch (type) {
    case 0:
        func_021F6EDC((int *)func_021F8684(), A, B);
        break;
    case 1:
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)((VecFx32_v9814 *)A), (VecFx32_v6560 *)((VecFx32_v9814 *)B), n, s, t);
        break;
    case 2:
        func_021F70F0((void **)func_021F8684(), C, (int)D);
        func_0207C9D0(C, A, A);
        func_0207C9D0(D, B, B);
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)((VecFx32_v9814 *)A), (VecFx32_v6560 *)((VecFx32_v9814 *)B), n, s, t);
        break;
    }
    return c->ret;
}









int func_021F9FC0(void *r, Ctx_v9814 *c)
{
    int E[3];
    int F[3];
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int type;

    type = VM_GetU32(r);
    v1 = VM_GetU32(r);
    v2 = VM_GetU32(r);
    v3 = VM_GetU32(r);
    v4 = VM_GetU32(r);
    v5 = VM_GetU32(r);
    func_021FDB20((State_021FDB20 *)((Ctx_021F9814 *)c));
    switch (type) {
    case 0:
        func_021F6F20((Obj_021F6F20 *)(func_021F8684()), v1, v2);
        break;
    case 1:
        func_021F7108((int *)func_021F8684(), v1, v2, E, F);
        func_021F6F48((Cam_021F6F48 *)(func_021F8684()), (VecFx32_v6560 *)((VecFx32_v9814 *)E), (VecFx32_v6560 *)((VecFx32_v9814 *)F), v3, v4, v5);
        break;
    }
    return c->ret;
}









int func_021FA048(void *r, Ctx_v9814 *c)
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;

    v0 = VM_GetU32(r);
    v1 = VM_GetU32(r);
    v2 = VM_GetU32(r);
    v3 = VM_GetU32(r);
    v4 = VM_GetU32(r);
    v5 = VM_GetU32(r);
    func_021F7000((Cam_021F7000 *)(func_021F8684()), v0, v1, v2, v3, v4, v5);
    return c->ret;
}








int func_021FA09C(void *a, State *s)
{
    int buf[8];
    int x;
    int n;
    int i;

    x = VM_GetU32(a);
    if (VM_GetU32(a) == 0) {
        s->f244 = x;
        func_021FDB20((State_021FDB20 *)((Ctx_021F9814 *)s));
    } else {
        n = func_021FCA04((State_021FC9F4 *)s, 14, buf);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (x == 1)
                    func_021FF228((Work_021FF228 *)((void *)func_021F8694()), buf[i]);
                else
                    func_021FF1F4((Work_vE254 *)((void *)func_021F8694()), buf[i]);
            }
        }
    }
    return s->f23c;
}








int func_021FA108(int a, char *b)
{
    ((struct Obj12208 *)b)->f284 = 1;
    func_021F70F0((void **)func_021F8684(), b + 0x288, (int)(b + 0x294));
    return ((struct Obj12208 *)b)->f23C;
}








/*
 * witness: arm9 PARTICLE_SetupSystemNoHandlers filed as src/matched/arm9/PARTICLE_SetupSystemNoHandlers.c.
 * witness: func_021FC9F4 filed as src/matched/ov/ov094_func_021FC9F4.c.
 */
int func_021FA12C(void *a, char *s)
{
    int slot;
    int key;
    void *buffer;
    void *resource;
    Callback *cb;
    int line;

    key = func_021FE38C(s, VM_GetU32(a));
    if (func_021FD15C((Tbl_vD04C *)s, key, &slot) == 1) {
        line = 0x715;
        buffer = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x4800, 0, d_0220AE68, line);
        resource = (void *)PARTICLE_LoadArchiveMember(6, key, (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
        if (buffer != 0 && resource != 0) {
            *(void **)(s + 12 + slot * 4) = PARTICLE_CreateSystem((u32)buffer, 0x4800, 0, 5, 6, 0x36, (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
            if (*(void **)(s + 12 + slot * 4) != 0) {
                PARTICLE_SetupSystemNoHandlers(*(void **)(s + 12 + slot * 4), resource);
                line += 10;
                cb = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 12, 0, d_0220AE68, line);
                cb->state = s;
                cb->emitter = *(void **)(s + 12 + slot * 4);
                cb->resource = resource;
                ((struct Obj00325 *)s)->f0 |= 0x10000;
                func_021F896C(func_020056A0(func_021FE9BC, cb, 0), 0, 1);
                VM_SetWait(a, (int)func_021FC9F4);
                func_021FD19C(s, slot, resource);
            }
        }
        if (*(void **)(s + 12 + slot * 4) == 0) {
            if (buffer != 0)
                func_020307B0(buffer);
            if (resource != 0)
                func_020307B0(resource);
            *(int *)(s + 0x4c + slot * 4) = -1;
        }
    }
    return 1;
}








int func_021FA288(void *a, char *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x74a);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[6] = VM_GetU32(a);
    VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16)
        func_021FDD60((State_021FDD60 *)s, (Rec_021FDD60 *)p, slot, arg);
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}








int func_021FA358(void *a, char *s)
{
    int *p;
    int slot;
    int arg;
    int result;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x77d);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = 8;
    p[2] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[13] = VM_GetU32(a);
    p[14] = VM_GetU32(a);
    p[15] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[6] = VM_GetU32(a);
    VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    if (slot != 16) {
        result = PARTICLE_StartEffectWithCallback(*(int **)(s + 12 + slot * 4), arg, (int)func_021FD1CC, (int)p);
        if (result == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}








/*
 * witness: arm9 BUTTON_MAN_GetBlock filed as src/matched/arm9/BUTTON_MAN_GetBlock.c.
 */
int func_021FA458(void *a, char *s)
{
    Desc_021F6560 desc;
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7b6);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    p[16] = 1;
    if (p[1] == 13) {
        p[1] = 9;
        p[16] = 2;
    }
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16) {
        Vec_021F6560 zero = {0, 0, 0};
        Vec_021F6560 v1;
        Vec_021F6560 v2;
        v1 = d_02209E1C;
        v2 = d_02209D90;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(*(void **)(s + 12 + slot * 4)) == 0)
            PARTICLE_InitCamera(*(void **)(s + 12 + slot * 4), (struct Src648 *)(&desc), 0x2000, (int *)(&zero), (int *)(&v1), (int *)(&v2), (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
        func_021FDD60((State_021FDD60 *)s, (Rec_021FDD60 *)p, slot, arg);
    }
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}








int func_021FA5D0(void *a, char *s)
{
    Desc_021F6560 desc;
    int *p;
    int slot;
    int count;
    int arg;
    int i;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7ff);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    count = func_021FD1C0(s, slot);
    p[0] = (int)a;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[6] = VM_GetU32(a);
    arg = VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    if (slot != 16) {
        if (arg != 0) {
            Vec_021F6560 zero = {0, 0, 0};
            Vec_021F6560 v1;
            Vec_021F6560 v2;
            v1 = d_02209D78;
            v2 = d_02209E04;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            if (BUTTON_MAN_GetBlock(*(void **)(s + 12 + slot * 4)) == 0)
                PARTICLE_InitCamera(*(void **)(s + 12 + slot * 4), (struct Src648 *)(&desc), 0x2000, (int *)(&zero), (int *)(&v1), (int *)(&v2), (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
            p[16] = 2;
        }
        if (p[2] == 8)
            p[2] = p[1];
        for (i = 0; i < count; i++)
            func_021FDD60((State_021FDD60 *)s, (Rec_021FDD60 *)p, slot, i);
    }
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}












int func_021FA758(void *a, char *s)
{
    int slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));

    if (slot != 16) {
        void **e = (void **)(s + 0xc) + slot;
        func_021FDB08(*e);
        *e = 0;
        ((int *)(s + 0x4c))[slot] = -1;
    }
    return ((struct Obj00325 *)s)->f23C;
}












int func_021FA794(void *a, char *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x868);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[19] = 0x1000;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    if (p[21] == 0)
        p[21] = 1;
    if (slot != 16) {
        if (PARTICLE_StartEffectWithCallback(*(int **)(s + 12 + slot * 4), arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}











int func_021FA884(void *a, char *s)
{
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8a2);
    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[19] = 0x1000;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        if (PARTICLE_StartEffectWithCallback(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}











int func_021FA988(void *a, char *s)
{
    Desc_021F6560 desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8e0);
    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0xc00;
    p[18] = VM_GetU32(a);
    p[19] = 0xc00;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    p[16] = 3;
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        Vec_021F6560 zero = {0, 0, 0};
        Vec_021F6560 v1;
        Vec_021F6560 v2;
        v1 = d_02209DC0;
        v2 = d_02209D84;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(*(void **)(s + 0xc + idx * 4)) == 0)
            PARTICLE_InitCamera((struct Dst648 *)(*(void **)(s + 0xc + idx * 4)), (struct Src648 *)&desc, 0x2000, (int *)&zero, (int *)&v1, (int *)&v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        if (PARTICLE_StartEffectWithCallback(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}











/*
 * witness: arm9 BUTTON_MAN_GetBlock filed as src/matched/arm9/BUTTON_MAN_GetBlock.c.
 * trailing: 021FAC94 and 021FACA0 are tail-call stubs; not filed while ARM9 blocks.
 */
int func_021FAB0C(void *a, char *s)
{
    Desc_021F6560 desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x92d);
    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[16] = 3;
    if (idx != 16) {
        Vec_021F6560 zero = {0, 0, 0};
        Vec_021F6560 v1;
        Vec_021F6560 v2;
        v1 = d_02209DA8;
        v2 = d_02209D9C;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(*(void **)(s + 0xc + idx * 4)) == 0)
            PARTICLE_InitCamera((struct Dst648 *)(*(void **)(s + 0xc + idx * 4)), (struct Src648 *)&desc, 0x2000, (int *)&zero, (int *)&v1, (int *)&v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        if (PARTICLE_StartEffectWithCallback(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}












/*
 * Tail call to func_021FDFA0 with mode 0.
 */
void func_021FAC94(void *a, void *b)
{
    func_021FDFA0(a, b, 0);
}












/*
 * Tail call to func_021FDFA0 with mode 1.
 */
void func_021FACA0(void *a, void *b)
{
    func_021FDFA0(a, b, 1);
}












int func_021FACAC(void *a, State_021FA758 *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    t[0] = VM_GetU32(a);
    t[1] = VM_GetU32(a);
    i = 0;
    t[2] = 0;
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (; i < n; i++)
            func_021FF4C0((char *)((void *)func_021F8694()), buf[i], x, (Vec_021F6560 *)t, r, u, v);
    }
    return s->f23c;
}












int func_021FAD2C(void *a, State_021FA758 *s)
{
    Req_021FAD2C q;
    int buf[8];
    int n;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, (int)VM_GetU32(a), buf);
    q.f8 = (int)VM_GetU32(a);
    q.fc = (int)VM_GetU32(a);
    q.f10 = (int)VM_GetU32(a);
    q.f14 = (int)VM_GetU32(a);
    q.f18 = (int)VM_GetU32(a) >> 12;
    q.f1c = (int)VM_GetU32(a) >> 12;
    q.f20 = (int)VM_GetU32(a) >> 12;
    q.f24 = (int)VM_GetU32(a);
    if (n != 0 && q.f20 != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFA18((Work_021FFA18 *)((void *)func_021F8694()), (Obj_021FFA18 *)&q);
        }
    }
    return s->f23c;
}












int func_021FADC0(void *a, State_021FA758 *s)
{
    Req_021FADC0 q;
    int buf[8];
    int n;
    int p;
    int r;
    int t;
    int u;
    int v;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    q.f18 = r;
    q.f24 = v;
    q.f14 = p;
    q.f20 = u;
    q.f1c = func_0207C768(t - r, v << 12);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFB04((Work_vF7B0 *)((void *)func_021F8694()), (Obj_vF7B0 *)&q);
        }
    }
    return s->f23c;
}












int func_021FAE48(void *a, State_021FA758 *s)
{
    int t[3];
    int buf[8];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    t[0] = VM_GetU32(a);
    t[1] = VM_GetU32(a);
    t[2] = 0x1000;
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF5B0((Work_021FF5B0 *)((void *)func_021F8694()), buf[i], x, (VecFx32_vF5B0 *)t, r, u, v);
    }
    return s->f23c;
}












int func_021FAECC(void *a, State_021FA758 *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    i = 0;
    t[0] = 0;
    t[1] = 0;
    t[2] = VM_GetU32(a);
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (; i < n; i++)
            func_021FF730((Work_vF5B0 *)((void *)func_021F8694()), buf[i], x, (VecFx32_vF5B0 *)t, r, u, v);
    }
    return s->f23c;
}












int func_021FAF44(void *a, State_021FA758 *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int u;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF924((char *)func_021F8694(), buf[i], p, q, r, t, u);
    }
    return s->f23c;
}












int func_021FAFBC(void *a, State_021FA758 *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int u;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFBBC((char *)func_021F8694(), buf[i], p, q, r, t, u);
    }
    return s->f23c;
}












int func_021FB034(void *a, State_021FA758 *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    y = VM_GetU32(a);
    z = VM_GetU32(a);
    if (n != 0) {
        if (z == 0)
            z = 1;
        for (i = 0; i < n; i++)
            func_021FF870((Work_021FF870 *)((void *)func_021F8694()), buf[i], x, y, z);
    }
    return s->f23c;
}












int func_021FB09C(void *a, State_021FA758 *s)
{
    int buf[8];
    int n;
    int v;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF304((Work_021FF228 *)((void *)func_021F8694()), buf[i], v);
    }
    return s->f23c;
}











int func_021FB0E8(void *a, State_021FA758 *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFDB4((Work_vFCB0 *)((void *)func_021F8694()), buf[i], p, q, r, t);
    }
    return s->f23c;
}











int func_021FB168(void *a, State_021FA758 *s)
{
    int buf[8];
    int n;
    int v;
    int i;

    n = func_021FCA04((State_021FC9F4 *)s, VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (v == 5) {
        func_02200654((Work_02200654 *)((void *)func_021F8694()));
    } else if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF374((Work_vF228 *)((void *)func_021F8694()), buf[i], v);
    }
    return s->f23c;
}










int func_021FB1C4(struct Cursor *a, char *b)
{
    int buf[8];
    int n;
    int i;
    int v;

    n = func_021FCA04((State_021FC9F4 *)((State_021FA758 *)((int)b)), VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF470((char *)((void *)func_021F8694()), buf[i], v);
    }
    return ((struct Obj00177 *)b)->f23C;
}










int func_021FB214(struct Cursor *a, char *b)
{
    int arr[3];
    int buf[8];
    int n;
    int i;
    int t1, t4, t5, t6;

    n = func_021FCA04((State_021FC9F4 *)((State_021FA758 *)((int)b)), VM_GetU32(a), buf);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = 0x1000;
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF6B0((Work_vF5B0 *)((void *)func_021F8694()), buf[i], t1, (VecFx32_vF5B0 *)arr, t4, t5, t6);
    }
    return ((struct Obj00177 *)b)->f23C;
}









/*
 * Script command: runs func_021F7F04 on each id listed by func_021FCA04.
 */
int func_021FB298(void *a, char *s)
{
    int ids[8];
    int n;
    int i;

    n = func_021FCA04((State_021FC9F4 *)((State_021FA758 *)s), VM_GetU32(a), ids);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021F7F04(ids[i]);
    }
    return ((struct Obj00177 *)s)->f23C;
}









int func_021FB2D0(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4;

    t0 = VM_GetU32(a);
    t1 = func_021FCF2C((int)a, VM_GetU32(a));
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    if (t0 == -1)
        t0 = ((struct Obj13586 *)b)->f4;
    func_021F7F58(t0, t1, t2, t3, t4);
    return ((struct Obj13586 *)b)->f23C;
}









int func_021FB328(struct Cursor *a, char *b)
{
    int arr[3];
    int t1;
    int t0;
    int t5, t6, t7;

    t0 = func_021F84D0(VM_GetU32(a));
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    t7 = VM_GetU32(a);
    func_021FF4C0((char *)((void *)func_021F8694()), t0, t1, (Vec_021F6560 *)arr, t5, t6, t7);
    return ((struct Obj21660 *)b)->f23C;
}









/*
 * Script command: when func_0220041C(x, y) reports 1, calls func_02200468(x).
 */
int func_021FB390(void *a, char *s)
{
    int x = VM_GetU32(a);
    int y = VM_GetU32(a);

    if (func_0220041C((Work_0220041C *)((void *)func_021F8694()), x, y) == 1)
        func_02200468((Work_02200468 *)((void *)func_021F8694()), x);
    return ((struct Obj21661 *)s)->f23C;
}








/*
 * Script command: passes one argument to func_021F8010.
 */
int func_021FB3C8(void *a, char *s)
{
    func_021F8010(VM_GetU32(a));
    return ((struct Obj21662 *)s)->f23C;
}








int func_021FB3DC(struct Cursor *a, char *b)
{
    int t;

    t = VM_GetU32(a);
    func_0204047C(3, 1);
    func_02049624((void *)0x5f, (void *)(t + 1), (void *)3, 0, 0, 0, (((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000);
    func_0204989C(0x5f, t, 3, 0, 0, 0, (((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)func_021F86E0(), (int)0x5f, (int)(t + 2), (u16)((((struct Obj04398 *)b)->f238 & 0x7fff) | 0x8000), (int)0, (int)0, (int)0x80, (int)0);
    ((struct Obj04398 *)b)->f264 = func_020407E8(3);
    ((struct Obj04398 *)b)->f268 = func_02040804(3);
    func_02209784(func_021F8700(), 0, 0);
    ((struct Obj04398 *)b)->f0 |= 0x10;
    return ((struct Obj04398 *)b)->f23C;
}








int func_021FB49C(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4, t5, v;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    v = func_021FCF2C((int)a, 14);
    func_022097CC(func_021F8700(), v, t0, t1, t2, t3, t4, t5);
    return ((struct Obj21663 *)b)->f23C;
}








/*
 * Script command: no-op that skips 4 arguments.
 */
int func_021FB500(void *a, char *s)
{
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    return ((struct Obj21664 *)s)->f23C;
}








/*
 * Script command: no-op that skips 5 arguments.
 */
int func_021FB524(void *a, char *s)
{
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    return ((struct Obj21665 *)s)->f23C;
}








/*
 * Script command: func_0204047C(3, arg) and sets flag bit 4.
 */
int func_021FB550(void *a, char *s)
{
    func_0204047C(3, (unsigned char)VM_GetU32(a));
    ((struct Obj13587 *)s)->f0 |= 0x10;
    return ((struct Obj13587 *)s)->f23C;
}








int func_021FB574(struct Cursor *a, unsigned int *b)
{
    int t2;

    VM_GetU32(a);
    VM_GetU32(a);
    t2 = VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    VM_GetU32(a);
    if (t2 == 0x1f)
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
    else
        func_0207D63C(0x04000050, 10, 0x35, 0x1f, t2);
    *b |= 0x20;
    return ((struct Obj13588 *)b)->f23C;
}








int func_021FB5D4(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    func_021F8298(t0, t1, t2, t3, t4);
    return ((struct Obj21666 *)b)->f23C;
}








/*
 * Script command: passes two arguments to func_021F839C.
 */
int func_021FB624(void *a, char *s)
{
    int x = VM_GetU32(a);
    func_021F839C(x, VM_GetU32(a));
    return ((struct Obj21667 *)s)->f23C;
}








int func_021FB648(struct Cursor *a, char *b)
{
    int *p;

    p = func_02030734((u16)((((struct Obj07879 *)b)->f238 & 0x7fff) | 0x8000), 0x28, 1, d_0220AE68, 0xd88);
    p[0] = (int)b;
    p[2] = VM_GetU32(a);
    p[3] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    p[6] = VM_GetU32(a);
    p[8] = VM_GetU32(a);
    p[9] = VM_GetU32(a);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_021F896C((void *)func_02030DA8((void *)((struct Obj07879 *)b)->f8, func_021FE79C, p, 0), func_021FE8AC, 1);
    ((struct Obj07879 *)b)->f0 |= 0x100;
    return ((struct Obj07879 *)b)->f23C;
}








/*
 * (pt is 3 words: the third is unused padding that sets the 0x30 frame)
 */
int func_021FB6F4(struct Cursor *a, char *b)
{
    int pt[3];
    int o1, o2;
    int t0, t1, t2, t3, t4, t5, t6;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = func_021FCF2C((int)a, VM_GetU32(a));
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    func_021FF3F4((void *)func_021F8694(), pt, t2);
    pt[0] += t3;
    pt[1] += t4;
    func_0206DF3C(pt, &o1, &o2);
    *(int *)(b + t0 * 4 + 0xcc) =
        func_02201AF8(func_021F86F0(), 0x5f, t1, o1, o2, t5, t6);
    return ((struct Obj21668 *)b)->f23C;
}








int func_021FB790(struct Cursor *a, char *b)
{
    s16_021FA758 arr[2];
    int t0, t1, t3, t4, t5;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    func_02201CD0((char *)func_021F86F0(), *(int *)(b + t0 * 4 + 0xcc), t1, (s16_02201B20 *)((s16_021FA758 *)arr), t3, t4, t5);
    return ((struct Obj21669 *)b)->f23C;
}








int func_021FB7F8(struct Cursor *a, char *b)
{
    int arr[3];
    int t0, t1, t3, t4, t5;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = 0x1000;
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    func_02201D5C((char *)func_021F86F0(), *(int *)(b + t0 * 4 + 0xcc), t1, arr, t3, t4, t5);
    return ((struct Obj21670 *)b)->f23C;
}








/*
 * Script command: passes slot arg of the table at 0xcc and a value to func_02201DA0.
 */
int func_021FB864(void *a, char *s)
{
    int i = VM_GetU32(a);
    int x = VM_GetU32(a);

    func_02201DA0((char *)func_021F86F0(), ((int *)(s + 0xcc))[i], x);
    return ((struct Obj13589 *)s)->f23C;
}








int func_021FB894(struct Cursor *a, State_021FB3C8 *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);

    func_02201DB4((char *)func_021F86F0(), s->t[v0], v1, v2, v3, v4);
    return s->f23c;
}














/*
 * Script command: releases slot arg of the table at 0xcc and marks it free.
 */
int func_021FB8F4(void *a, char *s)
{
    int *tab = (int *)(s + 0xcc);
    int i = VM_GetU32(a);

    func_02201CA4((Res_02201B20 *)((struct Res *)func_021F86F0()), tab[i]);
    tab[i] = -1;
    return ((struct Obj21671 *)s)->f23C;
}














/*
 * The last loop reads the list through `((int *)ids)[i]`. The cast stops
 * the element address folding into sp-relative form, so the compiler hoists
 * `add r6, sp, #0x10` to function entry (ahead of the s spill) and reloads
 * the element after each call, while the case 4 call still takes a fresh
 * `add r2, sp, #0x10`. A `p = ids` pointer local instead CSEs that argument
 * into r6 and leaves 6 bytes out. `pt.x *= -1` and `Pt_021FB8F4 pt = {0, 0};` in the
 * loop block are required for the rest.
 */
int func_021FB91C(void *r, State_021FB91C *s)
{
    int ids2[8];
    int ids[8];
    u32 a;
    u32 b;
    int n;
    int i;

    a = VM_GetU32(r);
    b = VM_GetU32(r);
    if (a <= 1) {
        switch (b) {
        case 3:
            func_021F81B4(a, s->fdc);
            break;
        case 4:
            n = func_021FCA04((State_021FC9F4 *)s, 0x10, ids2);
            if (n != 0) {
                for (i = 0; i < n; i++)
                    func_021F81B4(a, ids2[n]);
            }
            break;
        default:
            func_021F8198(a, b);
            break;
        }
    } else {
        n = 0;
        switch (b) {
        case 0:
            for (i = 0; i < 8; i += 2) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 1:
            for (i = 1; i < 8; i += 2) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 2:
            for (i = 0; i < 8; i++) {
                if (func_021F7F1C(i)) {
                    ids[n] = i;
                    n++;
                }
            }
            break;
        case 3:
            n = 1;
            ids[0] = s->fdc;
            break;
        case 4:
            n = func_021FCA04((State_021FC9F4 *)s, 0x10, ids);
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Pt_021FB8F4 pt = {0, 0};

                pt.x = (a == 2) ? 0x80 : -0x10;
                if (((int *)ids)[i] & 1)
                    pt.x *= -1;
                func_022079C0((char *)func_021F86B4(), ((int *)ids)[i], (Pt_021FB8F4 *)&pt);
            }
        }
    }
    return s->ret;
}














int func_021FBA64(struct Cursor *a, State_021FBA64 *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);
    int v5 = VM_GetU32(a);
    int v6 = VM_GetU32(a);
    int v7 = VM_GetU32(a);

    VM_GetU32(a);
    func_021F9858((void *)a, v0, v1, v2, v4, v5, v6, v7, v3);
    return s->f23c;
}














/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Script command: mode 5 calls GFL_USE_StopAllSe, any other mode is passed to
 * func_020061F8.
 */
int func_021FBAD8(void *a, char *s)
{
    int r = VM_GetU32(a);

    if (r == 5)
        GFL_USE_StopAllSe();
    else
        func_020061F8(r);
    return ((struct Obj21673 *)s)->f23C;
}













int func_021FBAF8(void *a, char *s)
{
    int *p;
    int x;
    int y;
    int diff;
    float f;
    float g;
    p = func_02030734((u16)((((struct Obj07880 *)s)->f238 & 0x7fff) | 0x8000), 0x38, 0, d_0220AE68, 0xf17);
    p[0] = (int)s;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 2;
    x = func_021FCF2C((int)a, VM_GetU32(a));
    y = func_021FCF2C((int)a, VM_GetU32(a));
    p[4] = (x & 1) ? 127 : -128;
    p[5] = (y & 1) ? 127 : -128;
    p[8] = VM_GetU32(a);
    p[9] = VM_GetU32(a);
    p[10] = p[9];
    p[11] = 0;
    p[12] = VM_GetU32(a);
    p[13] = VM_GetU32(a) * 2;
    if (p[2] == 1 && p[13] == 0) p[13] = 2;
    if (p[4] > 0) p[6] = _ffix(_fadd(0.5f, _fflt(p[4] << 12)));
    else p[6] = _ffix(_fsub(_fflt(p[4] << 12), 0.5f));
    if (p[9] > 0) f = _fadd(0.5f, _fflt(p[9] << 12));
    else f = _fsub(_fflt(p[9] << 12), 0.5f);
    diff = p[5] - p[4];
    if (diff > 0) g = _fadd(0.5f, _fflt(diff << 12));
    else g = _fsub(_fflt(diff << 12), 0.5f);
    x = _ffix(g);
    y = _ffix(f);
    p[7] = func_0207C768(x, y);
    func_021F896C(func_02030DA8(((struct Obj07880 *)s)->f8, func_021FE594, p, 0), func_021FE690, 1);
    ((struct Obj07880 *)s)->f0 |= 8;
    return ((struct Obj07880 *)s)->f23C;
}














int func_021FBC78(struct Cursor *a, State_021FBC78 *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);
    int v5 = VM_GetU32(a);
    int v6 = VM_GetU32(a);
    int v7 = VM_GetU32(a);
    int v8 = VM_GetU32(a);

    func_021F9948((void *)a, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    return s->f23c;
}














/*
 * Script command: stores one argument at 0x240, waits on func_021FC744, and suspends.
 */
int func_021FBCEC(void *a, char *s)
{
    ((struct Obj13592 *)s)->f240 = VM_GetU32(a);
    VM_SetWait(a, (int)func_021FC744);
    ((struct Obj13592 *)s)->f23C = 1;
    return 1;
}














/*
 * Script command: stores one argument at 0x1e4, waits on func_021FC9D0, and suspends.
 */
int func_021FBD10(void *a, char *s)
{
    ((struct Obj13593 *)s)->f1E4 = VM_GetU32(a);
    VM_SetWait(a, (int)func_021FC9D0);
    ((struct Obj13593 *)s)->f23C = 1;
    return 1;
}














/*
 * Script command: stores one argument at 0x23c of the state.
 */
void func_021FBD34(void *a, char *s)
{
    ((struct Obj21675 *)s)->f23C = VM_GetU32(a);
}














int func_021FBD44(struct Cursor *a, State_021FB8F4 *s)
{
    int x = func_021FDBB0((State_021FDBB0 *)((State_021FB8F4 *)s), VM_GetU32(a));
    int op = VM_GetU32(a);
    int y = VM_GetU32(a);
    int z = VM_GetU32(a);

    func_021FBDD4((int)a, x, y, op, z);
    return s->f23c;
}














int func_021FBD88(struct Cursor *a, State_021FB8F4 *s)
{
    int x = func_021FDBB0((State_021FDBB0 *)((State_021FB8F4 *)s), VM_GetU32(a));
    int op = VM_GetU32(a);
    int y = func_021FDBB0((State_021FDBB0 *)((State_021FB8F4 *)s), VM_GetU32(a));
    int z = VM_GetU32(a);

    func_021FBDD4((int)a, x, y, op, z);
    return s->f23c;
}














void func_021FBDD4(int a, int b, int c, int op, int e)
{
    int t = 0;

    switch (op) {
    case 0:
        if (b == c)
            t = 1;
        break;
    case 1:
        if (b != c)
            t = 1;
        break;
    case 2:
        if (b < c)
            t = 1;
        break;
    case 3:
        if (b > c)
            t = 1;
        break;
    case 4:
        if (b <= c)
            t = 1;
        break;
    case 5:
        if (b >= c)
            t = 1;
        break;
    }
    if (t == 1)
        VM_Jump((struct Cur *)a, ((struct Obj21678 *)a)->f14 + e);
}













/*
 * Script command: relative jump when func_021F7F1C(x) equals y.
 */
int func_021FBE28(struct Cursor *a, char *s)
{
    int x = VM_GetU32(a);
    int y = VM_GetU32(a);
    int off = VM_GetU32(a);

    if (y == func_021F7F1C(x))
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return ((struct Obj21679 *)s)->f23C;
}













/*
 * Script command: stores one argument at 4 of the state.
 */
int func_021FBE60(void *a, char *s)
{
    ((struct Obj13594 *)s)->f4 = VM_GetU32(a);
    return ((struct Obj13594 *)s)->f23C;
}













/*
 * Script command: stores func_021FDBB0((State_021FDBB0 *)((State_021FB8F4 *)s), arg) at 4 of the state.
 */
/*
 * Script command: stores func_021FDBB0(s, arg) at 4 of the state.
 */
int func_021FBE74(void *a, char *s)
{
    ((struct Obj13595 *)s)->f4 = func_021FDBB0((State_021FDBB0 *)((State_021FB8F4 *)s), VM_GetU32(a));
    return ((struct Obj13595 *)s)->f23C;
}













int func_021FBE90(struct Cursor *a, State_021FBE28 *s)
{
    int sel = VM_GetU32(a);
    int v = VM_GetU32(a);

    switch (sel) {
    case 9:
        s->f248 = v;
        break;
    case 10:
        s->f249 = v;
        break;
    case 11:
        s->f24a = v;
        break;
    case 12:
        s->f24b = v;
        break;
    case 13:
        s->f24c = v;
        break;
    case 14:
        s->f250 = v;
        break;
    case 15:
        s->f254 = v;
        break;
    case 0x35:
        s->f0_b13 = v;
        break;
    case 0x36:
        s->f284 = v;
        break;
    case 0x37:
        s->f2a0 = v;
        break;
    case 0x38:
        s->f0_b15 = v;
        break;
    }
    return ((struct Obj21680 *)s)->f23C;
}












int func_021FBF48(struct Cursor *a, State_021FB8F4 *s)
{
    int buf[8];
    int x = VM_GetU32(a);
    int n = func_021FCA04((State_021FC9F4 *)((State_021FB91C *)s), VM_GetU32(a), buf);
    int y = VM_GetU32(a);
    int i;

    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFFD8((char *)func_021F8694(), buf[i], x, y);
    }
    return s->f23c;
}












int func_021FBFA0(int a, char *b)
{
    func_02200140((Work_02200140 *)(func_021F8694()), ((struct Obj09236 *)b)->fE0, ((struct Obj09236 *)b)->fDC);
    return ((struct Obj09236 *)b)->f23C;
}










int func_021FBFC0(void *a, char *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int q;
    int r;
    int duration;
    int i;
    int slot;
    int *p;
    n = func_021FCA04((State_021FC9F4 *)((State_021FB91C *)s), VM_GetU32(a), buf);
    x = VM_GetU32(a);
    y = VM_GetU32(a);
    z = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    duration = VM_GetU32(a);
    if (n != 0) {
        if (duration == 0) {
            for (i = 0; i < n; i++) {
                slot = func_021FE4D0(s);
                *(int *)(s + slot * 4 + 0x26c) = func_02200218((Work_02200218 *)((char *)func_021F8694()), buf[i], x, y, z, q, r);
            }
            func_021FE410((Obj_021FE254 *)((T_021F9478 *)s), 0x7f000, 0x6b000, 10);
            if (!((Flags_021FB8F4 *)s)->bit10) {
                p = func_02030734((u16)((((struct Obj00177 *)s)->f238 & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x10f9);
                p[0] = (int)s;
                func_021F896C(func_02030DA8(((struct Obj00177 *)s)->f8, func_021FE8D8, (int *)p, 0), 0, 0);
            }
        } else {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((((struct Obj00177 *)s)->f238 & 0x7fff) | 0x8000), 0x20, 0, d_0220AE68, 0x1104);
                p[0] = (int)s;
                p[1] = buf[i];
                p[2] = x;
                p[3] = y;
                p[4] = z;
                p[5] = q;
                p[6] = r;
                p[7] = duration;
                ((struct Obj00177 *)s)->f0 |= 0x800;
                func_021F896C(func_02030DA8(((struct Obj00177 *)s)->f8, func_021FE6A4, (int *)p, 0), func_021FE750, 1);
            }
        }
    }
    return ((struct Obj00177 *)s)->f23C;
}











/*
 * Script command: stores one argument at 0x25c of the state.
 */
int func_021FC134(void *a, char *s)
{
    ((struct Obj13596 *)s)->f25C = VM_GetU32(a);
    return ((struct Obj13596 *)s)->f23C;
}










int func_021FC148(struct Cursor *a, State_021FC148 *s)
{
    int idx = VM_GetU32(a);
    int q = func_021FCF2C((int)a, VM_GetU32(a));
    int dx = VM_GetU32(a);
    int dy = VM_GetU32(a);
    int p5 = VM_GetU32(a);
    int p6 = VM_GetU32(a);
    Pt_021FC148 pt;
    int o1;
    int o2;
    int m;

    func_021FF3F4((void *)func_021F8694(), &pt, q);
    pt.x += dx;
    pt.y += dy;
    func_0206DF3C((int *)((Pt_021FC148 *)&pt), &o1, &o2);
    m = PALANM_GetPairedCodeForFirst(s->f254);
    m = (m == 0 || m > 0x19) ? 4 : m;
    m = (m == 0x19) ? 0x11 : m;
    m *= 2;
    s->t[idx] = (int)func_02201B20((char *)func_021F86F0(), 0x5f, m + 0x81, m + 0x82, 0x81, 0x82, o1, o2, p5, p6);
    return s->f23c;
}










int func_021FC20C(struct Ring *a, State_021FC20C *s)
{
    int n = VM_GetU32((struct Cursor *)a);
    int v = VM_GetU32((struct Cursor *)a);
    int w = VM_GetU32((struct Cursor *)a);
    int *p;

    s->a0[s->f260] = s->fdc;
    s->a1[s->f260] = s->fe0;
    s->a2[s->f260] = (int)s->f1e8;
    s->a3[s->f260] = s->f4;
    if (v != 14) s->fdc = v;
    if (w != 16) s->fe0 = w;
    s->f4 = 0;
    p = ARC_TOOL_LoadMember(0x43, n - 0x231, (u16)((s->h238 & 0x7fff) | 0x8000));
    s->f1e8 = p;
    VM_Call(a, (unsigned int)((char *)p + p[1]));
    s->f260++;
    return s->f23c;
}










int func_021FC2DC(int a, State_021FC2DC *s)
{
    int n;

    s->f260--;
    func_020307B0(s->f1e8);
    n = s->f260;
    s->fdc = s->a0[n];
    s->fe0 = s->a1[n];
    s->f1e8 = (void *)s->a2[n];
    s->f4 = s->a3[n];
    VM_Return((struct Ring *)a);
    return s->f23c;
}










/*
 * Script command: jumps the reader by a relative offset.
 */
int func_021FC334(struct Cursor *a, char *s)
{
    int off = VM_GetU32(a);
    VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return ((struct Obj21682 *)s)->f23C;
}









/*
 * Script command: sets flag bit 7, waits on func_021FC9E4, and suspends.
 */
int func_021FC354(void *a, char *s)
{
    ((struct Obj13597 *)s)->f0 |= 0x80;
    VM_SetWait(a, (int)func_021FC9E4);
    ((struct Obj13597 *)s)->f23C = 1;
    return 1;
}









/*
 * Script command: loads script id (archive 0x42 below 0x231, else 0x43) into the buffer at 0x1e8 and jumps into it.
 */
int func_021FC374(void *a, char *s)
{
    int id = VM_GetU32(a);
    char *p;

    func_020307B0(((struct Obj03713 *)s)->f1E8);
    if (id < 0x231)
        *(char * *)&((struct Obj03713 *)s)->f1E8 = ARC_TOOL_LoadMember((int)0x42, (int)id, (u16)((((struct Obj03713 *)s)->f238 & 0x7fff) | 0x8000));
    else
        *(char * *)&((struct Obj03713 *)s)->f1E8 = ARC_TOOL_LoadMember((int)0x43, (int)(id - 0x231), (u16)((((struct Obj03713 *)s)->f238 & 0x7fff) | 0x8000));
    p = *(char * *)&((struct Obj03713 *)s)->f1E8;
    ((struct Obj03713 *)s)->f4 = 0;
    VM_Jump(a, (u32)(p + ((struct Obj21683 *)p)->f4));
    return ((struct Obj03713 *)s)->f23C;
}









int func_021FC3D8(struct Cursor *a, State_021FC3D8 *s)
{
    int v = VM_GetU32(a);
    int *p;

    p = func_02030734((u16)((s->h238 & 0x7fff) | 0x8000), 0xc, 0, d_0220AE68, 0x1250);
    p[0] = (int)s;
    p[1] = v;
    p[2] = 0;
    func_021F896C(func_02030DA8((void *)s->f8, func_021FE930, (void *)(int *)p, 0), 0, 1);
    return s->f23c;
}









/*
 * Script command: passes one argument to func_021F8934.
 */
int func_021FC434(void *a, char *s)
{
    func_021F8934(VM_GetU32(a));
    return ((struct Obj21684 *)s)->f23C;
}









/*
 * Script reset: frees slot objects and buffers, restores display state, then resumes the
 * pending script at 0x1ec or reloads script 0x34 when the follow-up conditions hold.
 */
int func_021FC448(void *a, State_021FC448 *s)
{
    int i;
    int v;
    u16 id;
    u16 id2;
    int b;
    int off;
    char *p;
    void *q;

    for (i = 0; i < 16; i++) {
        if (s->objects[i] != 0) {
            func_021FDB08(s->objects[i]);
            s->objects[i] = 0;
        }
        s->ids[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        if (s->res[i] != -1) {
            func_02201CA4((Res_02201B20 *)((struct Res *)func_021F86F0()), s->res[i]);
            s->res[i] = -1;
        }
    }
    for (i = 0; i < s->nbufs; i++)
        func_020307B0(s->bufs[i]);
    s->nbufs = 0;
    func_021F8A10(1);
    func_021FE4F8(s);
    func_021FE520(s);
    if (s->flags.bit.b18 == 0)
        func_021F8934(1);
    func_02011290(a);
    s->f23c = 1;
    if (s->flags.bit.b4) {
        q = (void *)func_021F8764();
        if (q != 0)
            BTLV_SCU_ReloadGraphics(q);
        func_0204047C(3, 0);
        s->flags.bit.b4 = 0;
        func_02040618(3, 0, s->f264);
        func_02040618(3, 3, s->f268);
    }
    if (s->flags.bit.b5) {
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
        s->flags.bit.b5 = 0;
    }
    if (s->flags.bit.b12)
        GFL_USE_StopAllSe();
    v = 0;
    if (func_021FFD9C((char *)func_021F8694(), s->fdc) != 0) {
        id = s->h258;
        if (((id == 0xf8 || id == 0x161) && s->b249 == 1) || id == 0x90 || id == 0x77 || id == 0x10b) {
        } else {
            v = func_021FFF38((char *)func_021F8694(), s->fdc) & 1;
        }
    }
    if (s->f1ec != 0) {
        func_020307B0(s->f1e8);
        p = s->f1ec;
        s->f1e8 = p;
        s->f1ec = 0;
        s->flags.bit.b6 = 0;
        off = s->f1f0;
        func_02040588(1, 0);
        func_02040588(2, 0);
        func_02040588(3, 0);
        s->f4 = 0;
        VM_Start(a, (u8 *)(s->f1e8 + *(int *)(p + off)));
        return 1;
    }
    b = s->flags.bit.b17;
    if (b == 1 && s->h258 == 0x291) {
        func_020307B0(s->f1e8);
        s->h258 = 0x34;
        p = ARC_TOOL_LoadMember(0x43, s->h258, (u16)((s->h238 & 0x7fff) | 0x8000));
        s->f1e8 = p;
        s->flags.bit.b6 = 1;
        s->f4 = 0;
        s->flags.bit.b17 = 0;
        VM_Start(a, (u8 *)(p + ((struct Obj13598 *)p)->f4));
        return 1;
    }
    id2 = s->h258;
    if ((id2 == 0x286 || s->flags.bit.b6 == 0) && id2 != 0x90 && id2 != 0xe2 && b == 0 && v != 0) {
        if (id2 == 0x1f6)
            func_021FF374((Work_vF228 *)((void *)func_021F8694()), s->fdc, 0);
        func_020307B0(s->f1e8);
        s->h258 = 0x34;
        p = ARC_TOOL_LoadMember(0x43, s->h258, (u16)((s->h238 & 0x7fff) | 0x8000));
        s->f1e8 = p;
        s->flags.bit.b6 = 1;
        s->f4 = 0;
        s->flags.bit.b17 = 0;
        VM_Start(a, (u8 *)(p + ((struct Obj13598 *)p)->f4));
        return 1;
    }
    if (id2 != 0x27e) {
        func_02040588(1, 1);
        func_02040588(2, 1);
        func_02040588(3, 1);
    }
    return 1;
}









/*
 * witness: arm9 PARTICLE_GetEffectCount filed as src/matched/arm9/PARTICLE_GetEffectCount.c.
 * followers: 021FC9D0 countdown <=0; 021FC9E4 !flags bit7;
 *   021FC9F4 !flags bit16 (filed as their own packets).
 * lever: enum loop counters retain entry guards; flag bitfields retain
 *   shift-pair tests (raw unsigned mask expressions added 16 bytes).
 */
int func_021FC744(int a, State_021FC744 *s)
{
    int i;
    Slot_021F6560 j;

    if (s->mode <= 1) {
        if (func_021F722C((char *)func_021F8684()) == 1) return 0;
        if (s->flags.bit.b1) {
            s->flags.bit.b1 = 0;
            s->f244 = 1;
            func_021FF16C((Work_021FF16C *)((void *)func_021F8694()));
        }
    }
    if (s->mode == 0 || s->mode == 3) {
        for (j = 0; j < 14; j++) {
            if (func_021FFCB0((Work_021FFCB0 *)((void *)func_021F8694()), j) == 1) return 0;
        }
    }
    if (s->mode == 4) {
        for (j = 8; j < 14; j++) {
            if (func_021FFD9C((char *)func_021F8694(), j)) {
                if (func_02200494((char *)func_021F8694(), j) == 1) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 5) {
        if (func_0220985C((void *)func_021F8700()) == 1) return 0;
    }
    if (s->mode == 0 || s->mode == 2) {
        for (i = 0; i < 16; i++) {
            if (s->objects[i] != 0) {
                if (PARTICLE_GetEffectCount(s->objects[i]) != 0) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 6 || s->mode == 8) {
        if (func_021F8324(0) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 7 || s->mode == 8) {
        if (func_021F8324(1) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 9) {
        if (func_021F8324(3) != 0) return 0;
    }
    if (s->mode == 10) {
        if (func_02006238() != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 11) {
        if (GFL_USE_IsSeSlotBusy(1) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 12) {
        if (GFL_USE_IsSeSlotBusy(2) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 13) {
        if (GFL_USE_IsSeSlotBusy(4) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 14) {
        if (GFL_USE_IsSeSlotBusy(3) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 15) {
        if (GFL_USE_IsSeSlotBusy(0) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 16) {
        if (s->flags.bit.b11) return 0;
        for (i = 0; i < 6; i++) {
            if (s->slots[i] != -1) {
                if (func_02006BD0(s->slots[i]) != 0) return 0;
                s->slots[i] = -1;
            }
        }
    }
    if (s->mode == 0 || s->mode == 17) {
        if (s->flags.bit.b8) return 0;
    }
    return 1;
}








/*
 * Wait callback: decrements the countdown at 0x1e4, done when it reaches zero.
 */
int func_021FC9D0(void *a, char *s)
{
    return --((struct Obj21685 *)s)->f1E4 <= 0;
}









/*
 * Wait callback: done once flag bit 7 of the state word is clear.
 */
int func_021FC9E4(void *a, Flags_021FC9E4 *s)
{
    if (s->bit)
        return 0;
    return 1;
}








/*
 * Wait callback: done once flag bit 16 of the state word is clear.
 */
int func_021FC9F4(void *a, Flags_021FC9F4 *s)
{
    if (s->bit)
        return 0;
    return 1;
}








int func_021FCA04(State_021FC9F4 *s, int cmd, int *out)
{
    Key_021F6560 k;
    int n = 1;
    int mode;
    Targets t;
    int group;
    int *p;
    int i;
    int hi;

    switch (cmd) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        out[0] = cmd;
        break;
    case 14:
        out[0] = s->dc;
        if (out[0] == 0xff) {
            if (func_021F7F1C(0) == 1) {
                out[0] = 0;
            } else if (func_021F7F1C(2) == 1) {
                out[0] = 2;
            } else if (func_021F7F1C(4) == 1) {
                out[0] = 4;
            } else if (func_021F7F1C(4) == 1) {
                out[0] = 6;
            }
        }
        break;
    case 15:
        if (s->dc > 1) {
            out[0] = s->dc ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 16:
        out[0] = s->e0;
        if (out[0] == 0xff) {
            mode = func_021F8710();
            n = 0;
            if (mode == 0 || mode == 3) {
                if (s->kind == 8 || s->kind == 10) {
                    out[0] = s->dc;
                    n = 1;
                    if (func_021F7F1C(s->dc ^ 1)) {
                        out[1] = s->dc ^ 1;
                        n++;
                    }
                } else {
                    k = KEY_ONE;
                    n = 0;
                    if (func_021F7F1C(s->dc ^ k)) {
                        out[0] = s->dc ^ k;
                        n++;
                    }
                }
            } else {
                switch (s->kind) {
                case 0: case 1: case 2: case 3:
                    break;
                case 4:
                    if (mode == 2 && s->dc != 4 && s->dc != 5) {
                        t = d_02209E58;
                        group = s->dc > 3 ? 2 : 0;
                        i = 0;
                        p = t.v[(s->dc & 1) + group];
                        for (; i < 3; i++) {
                            if (func_021F7F1C(p[i])) {
                                out[n] = p[i];
                                n++;
                            }
                        }
                    } else {
                        for (k = KEY_TWO; k <= KEY_MAX; k++) {
                            if (s->dc != k && func_021F7F1C(k)) {
                                out[n] = k;
                                n++;
                            }
                        }
                    }
                    break;
                case 5: case 7: case 9: case 13:
                    k = (s->dc & 1) ? KEY_TWO : KEY_THREE;
                    hi = (mode == 2) ? 7 : 5;
                    if (mode == 2) {
                        if (s->dc <= 3)
                            k += 2;
                        if (s->dc >= 6)
                            hi -= 2;
                    }
                    for (; k <= hi; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 11:
                    k = (s->dc & 1) ? KEY_TWO : KEY_THREE;
                    for (; k <= KEY_MAX; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 6: case 12:
                    k = (s->dc & 1) ? KEY_THREE : KEY_TWO;
                    for (; k <= KEY_MAX; k += 2) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                case 8: case 10:
                    for (k = KEY_TWO; k <= KEY_MAX; k++) {
                        if (func_021F7F1C(k)) {
                            out[n] = k;
                            n++;
                        }
                    }
                    break;
                }
            }
        }
        break;
    case 17:
        if (s->e0 > 1) {
            out[0] = s->e0 ^ 2;
        } else {
            out[0] = 0xff;
        }
        break;
    case 18:
        n = 0;
        for (k = KEY_ZERO; k <= KEY_MAX; k++) {
            if (func_021F7F1C(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    case 19: case 20:
        k = (cmd == 19) ? KEY_ZERO : (Key_021F6560)n;
        n = 0;
        for (; k <= KEY_MAX; k += 2) {
            if (func_021F7F1C(k)) {
                out[n] = k;
                n++;
            }
        }
        break;
    }
    if (out[0] != 0xff && out[0] < 8) {
        if (func_021F7F1C(out[0]) == 1) {
            out[0] = func_021FD04C((Unit_021FD04C *)((State_021FC9F4 *)s), out[0]);
        } else {
            out[0] = 0xff;
            n = 0;
        }
    }
    return n;
}








/*
 * lever: enum key retains loop entry guards and constant one; shared outer
 *   exit, separate output store/increment, and branch-local n=0 reproduce
 *   the original scheduling (r1 266 bytes DIFF; r2 532 bytes; r3 EXACT).
 */
int func_021FCD14(State_021FC9F4 *s, int unused, int *out)
{
    Key_021F6560 k = KEY_ONE;
    int n = 1;
    int mode;
    Targets t;
    int group;
    int *p;
    int i;

    out[0] = s->e0;
    if (out[0] == 0xff) {
    mode = func_021F8710();
    n = 0;
    if (mode == 0 || mode == 3) {
        if (s->kind == 8 || s->kind == 10) {
            out[0] = s->dc;
            n = 1;
            if (func_021F7F1C(s->dc ^ 1)) {
                out[1] = s->dc ^ 1;
                n++;
            }
        } else {
            n = 0;
            if (func_021F7F1C(s->dc ^ 1)) {
                out[0] = s->dc ^ 1;
                n++;
            }
        }
    } else {
        switch (s->kind) {
        case 0: case 1: case 2: case 3:
            break;
        case 4:
            if (mode == 2 && s->dc != 4 && s->dc != 5) {
                t = d_02209E28;
                group = s->dc > 3 ? 2 : 0;
                i = 0;
                p = t.v[(s->dc & 1) + group];
                for (; i < 3; i++) {
                    if (func_021F7F1C(p[i]) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), p[i])) {
                        out[n] = p[i];
                        n++;
                    }
                }
            } else {
                for (k = KEY_TWO; k <= KEY_MAX; k++) {
                    if (s->dc != k && func_021F7F1C(k) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), k)) {
                        out[n] = k;
                        n++;
                    }
                }
            }
            break;
        case 5: case 7: case 9: case 13:
            if (mode == 1) {
                out[0] = (s->dc & k) ? 0 : k;
                n = 1;
            } else {
                if (s->dc != 4 && s->dc != 5) {
                    out[0] = d_0220AD18[s->dc];
                    n = k;
                } else {
                    out[0] = s->dc ^ 1;
                    n = 1;
                }
            }
            break;
        case 11:
            if (mode == 1) {
                out[0] = (s->dc & k) ? 0 : k;
                n = 1;
            } else {
                if (s->dc != 4 && s->dc != 5) {
                    out[0] = d_0220AD38[s->dc];
                    n = k;
                } else {
                    out[0] = s->dc ^ 1;
                    n = 1;
                }
            }
            break;
        case 6: case 12:
            k = (s->dc & k) ? KEY_THREE : KEY_TWO;
            for (; k <= KEY_MAX; k += 2) {
                if (func_021F7F1C(k) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), k)) {
                    out[n] = k;
                    n++;
                }
            }
            break;
        case 8: case 10:
            for (k = KEY_TWO; k <= KEY_MAX; k++) {
                if (func_021F7F1C(k) && !func_021FF348((Work_021FF348 *)((void *)func_021F8694()), k)) {
                    out[n] = k;
                    n++;
                }
            }
            break;
        }
    }
    }
    return n;
}








int func_021FCF2C(int a, int idx)
{
    Unit_vB8F4 *s = func_02011324((struct ScriptVm *)a);
    int v;

    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        v = idx;
        break;
    case 14:
        v = s->dc;
        if (v == 0xff) {
            if (func_021F7F1C(2) == 1)
                return 2;
            if (func_021F7F1C(4) == 1)
                return 4;
            if (func_021F7F1C(6) == 1)
                return 6;
            return 0;
        }
        break;
    case 15:
        if (s->dc > 1)
            v = s->dc ^ 2;
        else
            v = 0xff;
        break;
    case 16:
        v = s->e0;
        if (v == 0xff) {
            if (s->dc & 1) {
                if (func_021F7F1C(2) == 1)
                    return 2;
                if (func_021F7F1C(4) == 1)
                    return 4;
                if (func_021F7F1C(6) == 1)
                    return 6;
                return 0;
            } else {
                if (func_021F7F1C(3) == 1)
                    return 3;
                if (func_021F7F1C(5) == 1)
                    return 5;
                if (func_021F7F1C(7) == 1)
                    return 7;
                return 1;
            }
        }
        break;
    case 17:
        if (s->e0 > 1)
            v = s->e0 ^ 2;
        else
            v = 0xff;
        break;
    }
    return func_021FD070(a, v);
}



#undef FX


#undef FX

#undef FX
#define FX(x) ((int)(((x) > 0) ? ((float)((x) << 12) + .5f) : ((float)((x) << 12) - .5f)))



#undef MUL


#undef MUL

#undef MUL











#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))

















int func_021FD04C(Unit_021FD04C *s, int i)
{
    if (func_021F7F1C(i) == 1) {
        if (s->bit0)
            i ^= 1;
    } else {
        i = 0xff;
    }
    return i;
}

















int func_021FD070(int a, int b)
{
    int r = b;

    if (((struct OneBit *)func_02011324((void *)a))->v)
        r ^= 1;
    return r;
}

















int func_021FD088(int a, int *out)
{
    Unit_021FD088 *s = (void *)func_02011324((void *)a);
    int mode = func_021F8710();
    int v;

    *out = s->e0;
    if (*out != 0xff)
        return mode;
    if (mode == 0 || mode == 3 || s->flag == 1) {
        *out = s->dc ^ 1;
        return mode;
    }
    switch (s->kind) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 8:
    case 10:
        if (mode == 1) {
            mode = 0;
            *out = !(s->dc & 1);
        } else {
            v = s->dc;
            if (v != 4 && v != 5) {
                mode = 1;
                *out = d_0220AD58[v];
            } else {
                *out = v ^ 1;
            }
        }
        break;
    case 7:
    case 9:
    case 13:
        *out = s->dc ^ 1;
        break;
    case 11:
        mode = 0;
        *out = !(s->dc & 1);
        break;
    case 6:
    case 12:
        mode = 0;
        *out = (s->dc & 1) != 0;
        break;
    }
    return mode;
}

















int func_021FD15C(Tbl_vD04C *p, int key, int *out)
{
    int i;
    int r = 1;

    for (i = 0; i < 16; i++) {
        if (key == p->slot[i]) {
            r = 0;
            break;
        }
    }
    if (i == 16) {
        for (i = 0; i < 16; i++) {
            if (p->slot[i] == -1) {
                p->slot[i] = key;
                break;
            }
        }
    }
    *out = i;
    return r;
}
















void func_021FD19C(char *p, int i, char *q)
{
    *(int *)(p + i * 4 + 0x8c) = ((struct Obj18571 *)q)->f8;
}















int func_021FD1A8(char *p, int v)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (*(int *)(p + 0x4c + i * 4) == v)
            break;
    }
    return i;
}















int func_021FD1C0(char *p, int i)
{
    return *(int *)(p + i * 4 + 0x8c);
}
















/*
 * 2026-10-02: the kind == 4 swap closed. It is a per-axis swap through
 * temps from a (tx = a.x; a.x = b.x; ...), then the sums read the new a:
 * b.x = tx + a.x. Grouped temps, temps from b and `b.x = b.x + tx` all
 * leave the spill on old b.y or the add operands reversed.
 */
void func_021FD1CC(void *p)
{
    Vec_021F6560 a;
    Vec_021F6560 b;
    Vec_021F6560 c;
    Vec_021F6560 axis;
    Vec_021F6560 d;
    Vec_021F6560 e;
    Mtx m;
    Vec_021F6560 v1;
    Vec_021F6560 v2;
    Vec_021F6560 axis2;
    Vec_021F6560 sc;
    Dir dir;
    Rec_021FD04C *r;
    int flip;
    char *s;
    Obj_vD04C *o;
    u16 ang;
    int t0, t1, t2, t3;
    int n;
    int tx, ty, tz;

    r = (Rec_021FD04C *)func_02051774();
    flip = r->flip;
    switch (r->k1) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k1 = func_021FD070(r->vm, r->k1);
        break;
    case 9:
    case 11:
        r->k1 = func_021FCF2C(r->vm, r->k1 + 5);
        break;
    case 8:
        a.x = r->pa.x;
        a.y = r->pa.y;
        a.z = r->pa.z;
        break;
    case 14: case 15: case 16: case 17:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&a, r->k1 - 12, 1);
        r->k1 = -1;
        break;
    case 18: case 19: case 20: case 21:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&a, r->k1 - 16, 1);
        switch (r->k1) {
        case 18: a.z += 0x1a00; break;
        case 19: a.z += 0x2600; break;
        case 20: a.z += 0x600; break;
        case 21: a.z += 0x3900; break;
        }
        r->k1 = -1;
        break;
    }
    if (r->k1 != -1 && r->k1 != 8)
        func_021FF3F4((void *)func_021F8694(), &a, r->k1);
    switch (r->k2) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        r->k2 = func_021FD070(r->vm, r->k2);
        break;
    case 9:
        r->k2 = func_021FCF2C(r->vm, r->k2 + 5);
        break;
    case 10:
        flip = 1;
        r->k2 = func_021FCF2C(r->vm, r->k2 + 4);
        break;
    case 12:
        flip = 1;
    case 11:
        n = func_021FD088(r->vm, &r->k2);
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&b, r->k2, n);
        r->k2 = -1;
        break;
    case 8:
        b.x = r->pb.x;
        b.y = r->pb.y;
        b.z = r->pb.z;
        break;
    case 14: case 15: case 16: case 17:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&b, r->k2 - 12, 1);
        r->k2 = -1;
        break;
    case 18: case 19: case 20: case 21:
        func_021FF3FC((const Vec3_vF228 *)((const Vec_021F6560 *)func_021F8694()), (Vec3_vF228 *)&b, r->k2 - 16, 1);
        switch (r->k1) {
        case 18: b.z += 0x1a00; break;
        case 19: b.z += 0x2600; break;
        case 20: b.z += 0x600; break;
        case 21: b.z += 0x3900; break;
        }
        r->k2 = -1;
        break;
    }
    if (r->k2 != -1 && r->k2 != 8)
        func_021FF3F4((void *)func_021F8694(), &b, r->k2);
    func_021F8710();
    a.z += 0x500;
    b.z += 0x500;
    if ((u32)(r->mode - 1) <= 1) {
        func_021FE1B8((VecFx32_021FE1B8 *)&a, (const VecFx32_021FE1B8 *)(&r->ofs));
        func_021FE1B8((VecFx32_021FE1B8 *)&b, (const VecFx32_021FE1B8 *)(&r->ofs));
    } else if (r->mode == 3) {
        c.x = a.x;
        c.y = a.y;
        c.z = a.z;
        a.y += r->ofs.y;
        func_021FE1B8((VecFx32_021FE1B8 *)&c, (const VecFx32_021FE1B8 *)(&r->ofs));
    } else {
        a.y += r->ofs.y;
    }
    b.y += r->ofs.y;
    if (r->kind != 0) {
        s = (void *)func_02011324((void *)r->vm);
        *(Obj_vD04C **)(s + 0x1f4 + ((struct Obj07881 *)s)->f234 * 4) = func_02030734((u16)((((struct Obj07881 *)s)->f238 & 0x7fff) | 0x8000), 0x60, 0, d_0220AE68, 0x194a);
        o = *(Obj_vD04C **)(s + 0x1f4 + ((struct Obj07881 *)s)->f234 * 4);
        BUTTON_MAN_SetUserData(p, (int)o);
        BUTTON_MAN_SetCallback(p, (int)func_021FD8CC);
        ((struct Obj07881 *)s)->f234 += 1;
        o->f38 = 0;
        o->f50 = 0;
        o->f54 = 0;
        o->f58 = 0;
        o->f4c = r->kind;
        o->f48 = r->f24 >> 12;
        o->f5c = r->mode;
        if (r->kind == 3) {
            o->f40 = func_0207C768(0x6000000, r->f24);
        } else if ((u32)(r->kind - 5) <= 1) {
            o->f40 = func_0207C768(0x8000000, r->f24);
            o->f44 = func_0207C768(0x10000000, r->f24);
            o->f44 = MUL(o->f44, r->f54);
        } else {
            o->f40 = func_0207C768(0x8000000, r->f24);
        }
        if (o->f40 == 0)
            o->f40 = 1;
        o->f30 = func_0207CF3C((const Vec_021F6560 *)&a, (const Vec_021F6560 *)&b) / 2;
        if (r->kind == 1 || r->kind == 4)
            o->f34 = 0;
        else
            o->f34 = r->f1c;
        if (r->kind == 4) {
            tx = a.x;
            a.x = b.x;
            ty = a.y;
            a.y = b.y;
            tz = a.z;
            a.z = b.z;
            b.x = tx + a.x;
            b.y = ty + a.y;
            b.z = tz + a.z;
        }
        d.x = b.x - a.x;
        d.y = b.y - a.y;
        d.z = b.z - a.z;
        VEC_Normalize((const Vec_021F6560 *)&d, (Vec_021F6560 *)&d);
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
        ang = FX_AcosIdx(func_0207CA68((const Vec_021F6560 *)&e, (const Vec_021F6560 *)&d));
        func_0207CAE8((const Vec_021F6560 *)&e, (const Vec_021F6560 *)&d, (Vec_021F6560 *)&axis);
        VEC_Normalize((const Vec_021F6560 *)&axis, (Vec_021F6560 *)&axis);
        MTX_RotAxis43(o, (const Vec_021F6560 *)&axis, d_020A1B38[(ang >> 4) * 2], d_020A1B38[(ang >> 4) * 2 + 1]);
        o->pos.x = a.x;
        o->pos.y = a.y;
        o->pos.z = a.z;
    }
    if (r->k1 != 8 && r->k2 != 8 && r->k1 != r->k2) {
        dir.on = 2;
        b.x -= a.x;
        b.y -= a.y;
        b.z -= a.z;
        BUTTON_MAN_SetRow2(p, (struct S12 *)(&b));
        BUTTON_MAN_SetRow5(p, (struct S12 *)(&b));
        v2.x = b.x;
        v2.y = 0;
        v2.z = b.z;
        BUTTON_MAN_GetRot(p, &dir.dir);
        v1.x = dir.dir.x;
        v1.y = 0;
        v1.z = dir.dir.z;
        VEC_Normalize((const Vec_021F6560 *)&v1, (Vec_021F6560 *)&v1);
        VEC_Normalize((const Vec_021F6560 *)&v2, (Vec_021F6560 *)&v2);
        ang = FX_AcosIdx(func_0207CA68((const Vec_021F6560 *)&v1, (const Vec_021F6560 *)&v2));
        func_0207CAE8((const Vec_021F6560 *)&v1, (const Vec_021F6560 *)&v2, (Vec_021F6560 *)&axis2);
        VEC_Normalize((const Vec_021F6560 *)&axis2, (Vec_021F6560 *)&axis2);
        MTX_RotAxis43(&m, (const Vec_021F6560 *)&axis2, d_020A1B38[(ang >> 4) * 2], d_020A1B38[(ang >> 4) * 2 + 1]);
        v1.x = dir.dir.x;
        v1.y = dir.dir.y;
        v1.z = dir.dir.z;
        MTX_MultVec43((const Vec_021F6560 *)&v1, &m, (Vec_021F6560 *)&v1);
        VEC_Normalize((const Vec_021F6560 *)&v1, (Vec_021F6560 *)&v1);
        if (flip == 1) {
            v1.x *= -1;
            v1.z *= -1;
        }
        dir.dir.x = v1.x;
        dir.dir.y = v1.y;
        dir.dir.z = v1.z;
        if (ang < 0x2000 || (ang > 0x6000 && ang < 0xa000) || ang > 0xe000)
            dir.on = 0;
        BUTTON_MAN_SetRow3Half(p, (u16 *)(&dir));
        BUTTON_MAN_SetRot(p, (const struct Vec3 *)(&dir.dir));
    }
    if ((r->mode != 0 && (r->k1 & 1)) || r->mode == 0 || (u32)(r->mode - 2) <= 1) {
        t0 = BUTTON_MAN_GetScaleX(p);
        t1 = BUTTON_MAN_GetAlpha(p) << 12;
        t2 = BUTTON_MAN_GetAngle(p);
        t3 = BUTTON_MAN_GetScaleY(p);
        if (r->f44 != 0) {
            BUTTON_MAN_SetScaleX(p, MUL(t0, r->f44));
            BUTTON_MAN_SetScaleY(p, MUL(t3, r->f44));
        }
        if (r->f48 != 0)
            BUTTON_MAN_SetAlpha(p, (u16)(MUL(t1, r->f48) >> 12));
        if (r->f4c != 0)
            BUTTON_MAN_SetAngle(p, (s16_021F6560)MUL(t2, r->f4c));
        if (r->f50 != 0) {
            BUTTON_MAN_GetPos(p, (Vec_021F6560 *)&sc);
            sc.x = MUL(sc.x, r->f50);
            sc.y = MUL(sc.y, r->f50);
            sc.z = MUL(sc.z, r->f50);
            BUTTON_MAN_SetPos(p, (const Vec_021F6560 *)&sc);
            t0 = BUTTON_MAN_GetOffsetX(p);
            BUTTON_MAN_SetOffsetX(p, (s16_021F6560)MUL(t0, r->f50));
            t0 = BUTTON_MAN_GetOffsetY(p);
            BUTTON_MAN_SetOffsetY(p, (s16_021F6560)MUL(t0, r->f50));
        }
    }
    if (r->mode == 3)
        BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&c);
    else
        BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&a);
    func_020307B0(r);
}













#undef MUL












#undef MUL











#undef MUL










#undef MUL









#undef MUL








#undef MUL







#undef MUL






#undef MUL





#undef MUL




#undef MUL



#undef MUL


#undef MUL

#undef MUL
#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))














/*
 * The 5 and default arms are separate `else if` / `else` blocks with the
 * whole MUL repeated; the compiler cross-jumps their common tail, and the
 * 0 high word of the rounding addend stays CSE'd in r4 across all three
 * arms (a ternary index colours it differently).
 * Caller func_021FD1CC (same lane) shows s is a 0x60 object: 3x3 matrix,
 * pos at 0x24, counters from 0x30.
 */
void func_021FD8CC(void *p, int active)
{
    VecFx32_021FD04C v;
    u16 a;
    u16 b;
    int *s;

    s = (int *)BUTTON_MAN_GetUserData(p);
    if (s[18] == 0 || active == 0)
        return;
    if (s[19] == 3) {
        if (s[20] != 0) {
            s[20]--;
            return;
        }
        s[22] += 0xc;
        s[21] += s[22];
        s[20] = s[21] >> 12;
    }
    s[18]--;
    s[14] += s[16];
    s[15] += s[17];
    a = (s[14] >> 12) + 0xc000;
    b = (s[15] >> 12) + 0xc000;
    v.x = d_020A1B38[(a >> 4) * 2];
    v.x = MUL(v.x, s[12]);
    v.x += s[12];
    if (s[19] == 6) {
        v.z = d_020A1B38[(b >> 4) * 2 + 1];
        v.z = MUL(v.z, s[13]);
        v.y = 0;
    } else if (s[19] == 5) {
        v.y = d_020A1B38[(b >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    } else {
        v.y = d_020A1B38[(a >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    }
    MTX_MultVec43((const Vec_021F6560 *)&v, s, (Vec_021F6560 *)&v);
    if (s[23] != 0)
        func_021FE1B8((VecFx32_021FE1B8 *)((Vec_021F6560 *)&v), (const VecFx32_021FE1B8 *)((const Vec_021F6560 *)0));
    BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&v);
}















void func_021FD9F0(void *p)
{
    State_021FD04C *s = (State_021FD04C *)func_02051774();

    if (s->k3c != 0 && s->k0c < 0)
        BUTTON_MAN_SetAngle(p, 0x800);
    BUTTON_MAN_SetUserData(p, (int)s);
    BUTTON_MAN_SetCallback(p, (int)func_021FDA28);
}














void func_021FDA28(void *p, int active)
{
    int *s;
    VecFx32_021FD04C v;
    s = (int *)BUTTON_MAN_GetUserData(p);
    if (active == 0)
        return;
    if (s[13] == 0) {
        if (s[10] == 0) {
            s[10] = s[11];
            if (s[0] & 1)
                s[6] -= s[7];
            else
                s[6] += s[7];
            s[6] = (u16)s[6];
            v.x = d_020A1B38[(s[6] >> 4) * 2];
            v.x = MUL(v.x, s[4]);
            v.x += s[1];
            v.y = s[2];
            v.z = d_020A1B38[(s[6] >> 4) * 2 + 1];
            v.z = MUL(v.z, s[5]);
            v.z += s[3];
            if (s[15] != 0)
                func_021FE1B8((VecFx32_021FE1B8 *)((Vec_021F6560 *)&v), (const VecFx32_021FE1B8 *)((const Vec_021F6560 *)0));
            BUTTON_MAN_SetEmitterPos(p, (const Vec_021F6560 *)&v);
            if (s[8] != 0) {
                s[8]--;
            } else {
                s[8] = s[9];
                s[13] = s[14];
            }
        } else {
            s[10]--;
        }
    } else {
        s[13]--;
    }
}















void func_021FDB08(void *p)
{
    void *q = PARTICLE_GetWorkBase(p);

    PARTICLE_DeleteSystem(p);
    func_020307B0(q);
}














void func_021FDB20(State_021FDB20 *s)
{
    if (s->f244 == 1)
        func_021FF1B0((Work_021FF1B0 *)((void *)func_021F8694()));
    else
        func_021FF16C((Work_021FF16C *)((void *)func_021F8694()));
}














void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g)
{
    if (m == 5) {
        func_020061E4(a0);
        m = GFL_USE_GetSeSlot(a0);
    } else {
        func_0200616C((void *)a0, m);
    }
    NNS_SndHandleSetSeqPriority((char *)GFL_USE_GetSeHandle(m), e);
    GFL_USE_SetSeSlotParams(m, -1, -1, a2);
    GFL_USE_SetSeSlotParams(m, -1, a3, -1);
    if (f) {
        NNS_SndHandleSetTrackModDepth((struct Obj_vD04C *)GFL_USE_GetSeHandle(m), 0xffff, f);
        NNS_SndHandleSetTrackModSpeed((struct Obj_vD04C *)GFL_USE_GetSeHandle(m), 0xffff, g);
    }
}













/*
 * leaves: parent-cleared ov094 getters 0x021F8730 and 0x021F8740 filed separately.
 * domain: selector values 0..57; out-of-range result is unspecified.
 */
int func_021FDBB0(State_021FDBB0 *s, unsigned int key)
{
    switch (key) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        return func_021FFF0C((char *)func_021F8694(), key);
    case 8: return func_021FFF0C((char *)func_021F8694(), s->dc);
    case 9: return s->b248;
    case 10: return s->b249;
    case 11: return s->b24a;
    case 12: return s->b24b;
    case 13: return s->f24c;
    case 14: return s->f250;
    case 15: return s->f254;
    case 16: return s->f4;
    case 17: return s->dc;
    case 18: return func_021FF348((Work_021FF348 *)((void *)func_021F8694()), s->dc);
    case 19: return s->dc & 1;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
        if (func_021FFF38((char *)func_021F8694(), key - 20) & 2)
            return 1;
        return 0;
    case 28:
        if (func_021FFF38((char *)func_021F8694(), s->dc) & 2)
            return 1;
        return 0;
    case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36:
        return func_021FFF68((Work_021FFF68 *)((void *)func_021F8694()), key - 29);
    case 37: return func_021FFF68((Work_021FFF68 *)((void *)func_021F8694()), s->dc);
    case 38: return func_021F8730();
    case 39: return func_021F8710();
    case 40: case 41: case 42: case 43: return func_021F8740(key - 40);
    case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51:
        return func_021FFFAC((Work_021FFFAC *)((void *)func_021F8694()), key - 44);
    case 52: return func_021FFFAC((Work_021FFFAC *)((void *)func_021F8694()), s->dc);
    case 53: return s->f13;
    case 54: return s->f284;
    case 55: return s->f2a0;
    case 56: return s->f15;
    case 57: return s->e0;
    }
}













/*
 * lever: declare count before n to place them at sp+0x18 and sp+0x14;
 *   reversed declarations produced five differing spill/reload bytes.
 */
void func_021FDD60(State_021FDD60 *s, Rec_021FDD60 *r, int slot, int arg)
{
    int targets[8];
    int keys[8];
    int count;
    int n;
    int i;
    Rec_021FDD60 *p;

    if (r->v[2] == r->v[1] && (u32)(r->v[2] - 11) <= 1) {
        if (r->v[2] == 12)
            r->v[22] = 1;
        count = func_021FCD14((State_021FC9F4 *)((State_021FDD60 *)s), 16, targets);
        if (count != 0) {
            for (i = 0; i < count; i++) {
                p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c0e);
                *p = *r;
                p->v[1] = targets[i];
                p->v[2] = targets[i];
                if (PARTICLE_StartEffectWithCallback(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else if (r->v[2] == r->v[1] && s->kind == 12 && !s->flags.b6 && s->f258 != 0x16e && (u32)(r->v[2] - 9) <= 1) {
        if (r->v[2] == 10)
            r->v[22] = 1;
        switch (func_021F8710()) {
        default:
        case 0: case 3:
            keys[0] = s->dc;
            n = 1;
            break;
        case 1:
            keys[0] = (s->dc & 1) ? 1 : 0;
            n = 1;
            break;
        case 2:
            keys[0] = (s->dc & 1) ? 19 : 18;
            keys[1] = (s->dc & 1) ? 21 : 20;
            n = 2;
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c45);
                *p = *r;
                p->v[1] = keys[i];
                p->v[2] = keys[i];
                if (PARTICLE_StartEffectWithCallback(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
                    func_020307B0(p);
            }
        }
    } else {
        p = func_02030734((u16)((s->heap & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x1c56);
        *p = *r;
        if (PARTICLE_StartEffectWithCallback(s->objects[slot], arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    }
}












int func_021FDFA0(void *a, char *s, int mode)
{
    int *p;
    int idx;
    int x;
    int y;
    int flags;

    idx = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    flags = 0;
    *(int **)(s + 0x1f4 + ((struct Obj00325 *)s)->f234 * 4) = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x40, 0, d_0220AE68, 0x1c79);
    p = *(int **)(s + 0x1f4 + ((struct Obj00325 *)s)->f234 * 4);
    ((struct Obj00325 *)s)->f234 += 1;
    p[0] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    y = VM_GetU32(a);
    p[6] = 0;
    p[9] = p[8] = VM_GetU32(a);
    p[10] = 0;
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[13] = 0;
    p[14] = VM_GetU32(a);
    p[7] = _s32_div_f(0x10000, p[8]);
    p[15] = mode;
    if (idx == 16)
        goto end;
    if (mode == 1) {
        if (BUTTON_MAN_GetBlock(*(void **)(s + 0xc + idx * 4)) == 0) {
            Desc_021F6560 desc;
            Vec_021F6560 zero = {0, 0, 0};
            Vec_021F6560 v1;
            Vec_021F6560 v2;
            v1 = d_02209E10;
            v2 = d_02209DB4;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            PARTICLE_InitCamera((struct Dst648 *)(*(void **)(s + 0xc + idx * 4)), (struct Src648 *)&desc, 0x2000, (int *)&zero, (int *)&v1, (int *)&v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        }
    }
    switch (p[0]) {
    case 0:
    case 1:
        flags = func_021FCF2C((int)a, 14);
        func_021FF3F4((void *)func_021F8694(), &p[1], flags);
        break;
    case 2:
    case 3:
        flags = func_021FCF2C((int)a, 16);
        func_021FF3F4((void *)func_021F8694(), &p[1], flags);
        break;
    case 4:
    case 5:
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        break;
    }
    if (flags & 1)
        p[6] = 0x8000;
    p[2] += y;
    if (PARTICLE_StartEffectWithCallback(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD9F0, (int)p) == -1)
        func_020307B0(p);
end:
    return ((struct Obj00325 *)s)->f23C;
}











void func_021FE1B8(VecFx32_021FE1B8 *v, const VecFx32_021FE1B8 *ofs)
{
    fx32 w;
    MtxFx44 m;

    MTX_Copy43To44_(&g_renderStateDrawParams, &m);
    MTX_Concat44(&m, &SCREENTEX_ProjectionMatrix, &m);
    if (ofs != 0) {
        v->x += ofs->x;
        v->y += ofs->y;
        v->z += ofs->z;
    }
    func_021FE254((const VecFx32 *)((const VecFx32_021FE1B8 *)v), &m, (fx32 *)((VecFx32_021FE1B8 *)v), &w);
    v->x = FX_MUL(FX_Div(v->x, w), 0x4000);
    v->y = FX_MUL(FX_Div(v->y, w), 0x3000);
    v->z = -v->z;
}
















void func_021FE254(const VecFx32 *v, const MtxFx44 *m, fx32 *out, fx32 *w)
{
    fx64 y = v->y;
    fx64 x = v->x;
    fx64 z = v->z;
    fx64 t;

    t = z * m->m[2][0] + (x * m->m[0][0] + y * m->m[1][0]);
    out[0] = (fx32)(t >> 12) + m->m[3][0];
    t = z * m->m[2][1] + (x * m->m[0][1] + y * m->m[1][1]);
    out[1] = (fx32)(t >> 12) + m->m[3][1];
    t = z * m->m[2][2] + (x * m->m[0][2] + y * m->m[1][2]);
    out[2] = (fx32)(t >> 12) + m->m[3][2];
    t = z * m->m[2][3] + (x * m->m[0][3] + y * m->m[1][3]);
    *w = (fx32)(t >> 12) + m->m[3][3];
}

















/*
 * Levers: v and k unsigned (bhi/bhs/blo compares); the middle arm is
 * `mode != 8` and the mode==8 arm last, which puts its block after the
 * cross-jumped func_022003C4 call.
 */
unsigned int func_021FE38C(char *p, unsigned int k)
{
    int mode = ((struct Obj00325 *)p)->f25C;
    unsigned int v;

    if (mode == 9)
        v = func_022003C4((char *)func_021F8694(), ((struct Obj00325 *)p)->fDC);
    else if (mode != 8)
        v = func_022003C4((char *)func_021F8694(), mode);
    else
        v = PALANM_GetPairedCodeForFirst(((struct Obj00325 *)p)->f254);
    if (v == 0 || v > 0x19)
        v = 4;
    v--;
    switch (k) {
    case 3:
        k += v;
        break;
    case 0x1d:
        if (v + 1 == 0x19)
            v = 0x10;
        else if (v + 1 >= 0x10)
            v = 3;
        k += v;
        break;
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
        k += v << 2;
        break;
    }
    return k;
}

















/*
 * Sets/clears the 0x200/0x400 flag bits of *o, allocates a 0x10-byte record
 * (heap from the u16 at +0x238), converts n to fx32 (n<<12, +-0.5 rounding)
 * and registers func_021FE768 as a task callback through func_02030DA8.
 */
void func_021FE410(Obj_021FE254 *o, int a, int b, int n)
{
    Rec_vE254 *r;
    int fx;

    if (a > b) {
        if (o->fl.f9) {
            o->fl.f10 = 1;
            return;
        }
        o->fl.f9 = 1;
    } else {
        o->fl.f9 = 0;
    }
    r = func_02030734((u16)(((u16)((struct Obj13601 *)o)->f238 & 0x7fff) | 0x8000), 0x10, 0, d_0220AE68, 0x1d78);
    r->a = a;
    r->b = b;
    r->fl = (Flags_021FE254 *)o;
    if (n > 0)
        fx = _ffix(_fadd(0.5f, _fflt(n << 12)));
    else
        fx = _ffix(_fsub(_fflt(n << 12), 0.5f));
    func_021F9154(r->a, r->b, r->v, fx);
    func_021F896C((void *)func_02030DA8((void *)((struct Obj13601 *)o)->f8, func_021FE768, r, 0), 0, 1);
}
















int func_021FE4D0(char *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(int *)(p + 0x26c + i * 4) == -1)
            break;
    }
    if (i == 6)
        i = 0;
    return i;
}
















void func_021FE4F8(void *unused)
{
    Key_021FD04C i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i) == 1)
            func_022004BC((Work_022004BC *)((void *)func_021F8694()), i);
    }
}

















void func_021FE520(void *unused)
{
    Key_021FD04C i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i) == 1)
            func_021FF470((char *)func_021F8694(), i, 0);
    }
}

















void func_021FE54C(void *h, void *arg)
{
    int *s = arg;

    if (--s[4] == 0) {
        func_021FDB40(s[1], s[2], s[3], s[5], s[6], s[7], s[8]);
        func_021F89BC(h);
    }
}

















void func_021FE580(void *h)
{
    unsigned int *p = *((unsigned int **)TCBL_IsDeletePending(h));

    *p &= ~4u;
}
















/*
 * trailing: two zero alignment bytes at 0x021FE68E.
 */
void func_021FE594(void *h, void *arg)
{
    int *s = arg;

    int done;
    int v;
    done = 0;
    if (s[8] != 0) {
        s[8]--;
        return;
    }
    if (s[11] == 0) {
        s[11] = s[12];
        s[6] += s[7];
        v = s[6] >> 12;
        if (s[13] & 1) {
            if (s[7] < 0) {
                if (v < s[4])
                    v = s[4];
            } else {
                if (v > s[4])
                    v = s[4];
            }
        } else {
            if (s[7] < 0) {
                if (v < s[5])
                    v = s[5];
            } else {
                if (v > s[5])
                    v = s[5];
            }
        }
        if (v > 0)
            s[6] = _ffix(_fadd(0.5f, _fflt(v << 12)));
        else
            s[6] = _ffix(_fsub(_fflt(v << 12), 0.5f));
        switch (s[3]) {
        case 0: GFL_USE_SetSeSlotParams(s[1], -1, v, -1); break;
        case 1: NNS_SndHandleSetSeqPriority((char *)GFL_USE_GetSeHandle(s[1]), v); break;
        case 2: GFL_USE_SetSeSlotParams(s[1], -1, -1, v); break;
        }
        if (s[9] == 0) {
            s[9] = s[10];
            switch (s[2]) {
            case 0: done = 1; break;
            case 1:
                s[13]--;
                if (s[13] != 0)
                    s[7] *= -1;
                else
                    done = 1;
                break;
            }
        } else {
            s[9]--;
        }
    } else {
        s[11]--;
    }
    if (done == 1)
        func_021F89BC(h);
}
















void func_021FE690(void *h)
{
    unsigned int *p = *((unsigned int **)TCBL_IsDeletePending(h));

    *p &= ~8u;
}
















void func_021FE6A4(void *h, void *arg)
{
    Req *r = arg;

    int slot;
    Obj_021FE690 **cell;

    r->cnt--;
    if (r->cnt != 0)
        return;
    slot = func_021FE4D0((char *)r->obj);
    *(int *)((char *)r->obj + 0x26c + slot * 4) =
        func_02200218((Work_02200218 *)((char *)func_021F8694()), r->a1, r->a2, r->a3, r->a4, r->a5, r->a6);
    func_021FE410((Obj_021FE254 *)r->obj, 0x7f000, 0x6b000, 10);
    if (!r->obj->fl.f10) {
        cell = func_02030734((u16)(((u16)((struct Obj21693 *)((char *)r->obj))->f238 & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x1e6d);
        *cell = r->obj;
        func_021F896C((void *)func_02030DA8((void *)r->obj->h, func_021FE8D8, cell, 0), 0, 0);
    }
    func_021F89BC(h);
}
















void func_021FE750(void *h)
{
    unsigned int *p = *((unsigned int **)TCBL_IsDeletePending(h));

    *p &= ~0x800u;
}
















void func_021FE768(void *h, void *arg)
{
    int *s = arg;

    int flag = 1;

    func_021F9220(&s[1], &s[3], &s[2], &flag);
    func_0200F698((void *)0xffff, (void *)(s[1] >> 12));
    if (flag)
        func_021F89BC(h);
}














static inline void window0(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}














static inline void window1(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}














/*
 * volatile: WININ re-read at 0x021FE7BE; WINOUT and display register accesses.
 */
void func_021FE79C(void *h, void *arg)
{
    int *s = arg;

    switch (s[1]) {
    case 0:
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f) | (u8)s[5]);
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f00) | (u16)(s[5] << 8));
        REG16(0x0400004a) = (u16)((REG16(0x0400004a) & ~0x3f) | ((s[5] & 0xff00) >> 8));
        REG32(0x04000000) = (REG32(0x04000000) & ~0xe000) | 0x6000;
        REG16(0x04000042) = 0;
        REG16(0x04000046) = 0;
        s[1]++;
    case 1:
        if (s[7] == 0) {
            s[7] = s[8];
            switch (s[2]) {
            case 0: s[4] -= 0x100; s[4]++; break;
            case 1: s[4] += 0x100; s[4]--; break;
            case 2: s[3] -= 0x100; s[3]++; break;
            case 3: s[3] += 0x100; s[3]--; break;
            }
            window0(s[3] >> 8, s[4] >> 8, s[3], s[4]);
            if ((u8)s[3] == 0xff) {
                window1(1, s[4] >> 8, 0, s[4]);
            } else {
                window1(0, 0, 0, 0);
            }
            s[6]--;
            if (s[6] == 0)
                func_021F89BC(h);
        } else {
            s[7]--;
        }
        break;
    }
}















void func_021FE8AC(void *h)
{
    Ctx_021FE254 *c = (Ctx_021FE254 *)TCBL_IsDeletePending(h);

    if (c->k24 == 0)
        *(volatile unsigned int *)0x04000000 &= ~0xE000u;
    *c->reg &= ~0x100u;
}















void func_021FE8D8(void *h, void *arg)
{
    Obj_vE254 **pp = arg;

    int i;

    for (i = 0; i < 6; i++) {
        if ((*pp)->tbl[i] != -1) {
            if (func_02006BD0((*pp)->tbl[i]) != 0)
                return;
            (*pp)->tbl[i] = -1;
        }
    }
    func_021FE410((Obj_021FE254 *)(*pp), 0x6b000, 0x7f000, 10);
    (*pp)->fl.f10 = 0;
    func_021F89BC(h);
}















/*
 * Lever: the `mask |= 1 << i` tail is written out in both arms (then-arm
 * innermost, and the else arm); the compiler cross-jumps them and leaves the
 * `b` to the next instruction.  A single shared tail (goto/continue) gives no
 * `b` and hoists r7/r4 in the other order.
 */
void func_021FE930(void *h, void *arg)
{
    Arg_vE254 *a = arg;

    int i = 1;
    int want;

    if (a->side == 0)
        i = 0;
    if (a->side != 0)
        want = 0xaa;
    else
        want = 0x55;
    while (i <= 7) {
        if (func_021F7F1C(i)) {
            if (func_021FFCB0((Work_021FFCB0 *)((char *)func_021F8694()), i) == 0) {
                if ((func_021F935C(i) & a->mask) == 0) {
                    func_021FF304((Work_021FF228 *)((char *)func_021F8694()), i, 0);
                    func_021FF470((char *)func_021F8694(), i, 0);
                    a->mask |= func_021F935C(i);
                }
            }
        } else {
            a->mask |= func_021F935C(i);
        }
        i += 2;
    }
    if (want == a->mask)
        func_021F89BC(h);
}














void func_021FE9BC(void *h, void *arg)
{
    Ctx_021FE9BC *c = arg;

    u16 line = *(volatile u16 *)0x04000006;

    if (line >= 0xc0 && line <= 0xc8) {
        PARTICLE_ApplyLoadHandlers(c->obj);
        *c->reg &= ~0x10000u;
        func_021F89BC(h);
    }
}














/*
 * Lever: the loop counter is an enum (keeps the `cmp r4,#8; bge` entry guard
 * and the unfolded (1<<12)>>1 rounding constants after it), see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 */
void func_021FE9F0(fx32 a, fx32 b, int n, int f48, int f4c)
{
    Slot_021FD04C i;
    VecFx32 v;
    fx32 s;
    fx32 t;

    func_021FF134((char *)func_021F8694(), a, b);
    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)func_021F8694(), i)) {
            s = func_021FF468((void *)func_021F8694(), i, 1);
            if (i & 1)
                t = (fx32)(((fx64)s * b + ((fx64)(1 << 12) >> 1)) >> 12);
            else
                t = (fx32)(((fx64)s * a + ((fx64)(1 << 12) >> 1)) >> 12);
            v.x = t;
            v.y = t;
            v.z = 1 << 12;
            func_021FF630((Work_021FF630 *)((char *)func_021F8694()), i, 1, (VecFx32_vF5B0 *)&v, n, f48, f4c);
        }
    }
}














int func_021FEAA0(int v)
{
    unsigned int i;

    for (i = 0; i < 11; i++) {
        if (v == d_02209DD8[i])
            return 1;
    }
    return 0;
}














/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Lever: `u16 a2` (the strh of the heap id makes the parameter 16-bit; it
 * is spilled at entry and reloaded, as the image does).
 *
 * witness outside the range): MCSS_SetSysParam (0x020163B0) and MCSS_SetSysFlag
 * (0x020163B4).  Both are the integrator's; verified C (one --thumb, no --region,
 * EXACT each):
 *     void MCSS_SetSysParam(char *p, int v) { *(int *)(p + 0x48) = v; }
 *     typedef struct { char pad[0x2c]; unsigned int b0 : 1; unsigned int b1 : 1; } Obj_vE254;
 *     void MCSS_SetSysFlag(Obj_vE254 *p, int v) { p->b1 = v; }
 * Re-run this file once layout/matched/arm9 shards for both exist.
 */
Work_021FEAC0 *func_021FEAC0(int mode, int a1, u16 a2)
{
    Work_021FEAC0 *w;
    int v = 0xe;
    int i;

    w = func_02030734(a2, 0x5b4, 1, d_0220AE7C, 0x184);
    w->obj = MCSS_Init(v, (void *)a2);
    w->cb = (int *)a1;
    w->heap = a2;
    v += 0xf2;
    MCSS_SetSysParam(w->obj, v);
    MCSS_SetSysFlag(w->obj, 1);
    w->active = 1;
    w->scaleEven = 0x1000;
    w->scaleOdd = 0x1000;
    w->flags.b0 = (mode == 2);
    w->flags.b1 = (mode == 3);
    for (i = 0; i < 14; i++)
        w->e[i].k48 = 0xff;
    return w;
}














void func_021FEB78(Work_021FEB78 *w)
{
    Key_021FD04C i;

    for (i = 0; i < 14; i++) {
        if (func_021FFD9C((char *)w, i))
            func_021FF0F8((Work_021FF0F8 *)w, i);
    }
    MCSS_Exit(w->obj);
    func_020307B0(w);
}














/*
 * lever: enum loop counter keeps both entry guards; a separate local k for the
 *   first loop index puts idx at sp+8 and flag at sp+4 (one shared idx swapped them).
 */
void func_021FEBAC(Work_021FEBAC *w)
{
    Key_021FD04C i;
    int k;
    int idx;
    int flag;
    int a;
    int b;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            k = func_022019F4((char *)w, i);
            if (w->e[k].f11) {
                w->e[k].f11 = 0;
                MCSS_RestartAnime(w->e[k].h);
            }
        }
    }
    MCSS_Main(w->obj);
    if (w->f510 == 0) {
        for (i = 0; i < 8; i++) {
            if (func_021FFD9C((char *)w, i)
                && (u32)(((u64)func_0203F0A8() * 100) >> 32) == 0
                && (func_021F935C(i) & w->m528) == 0
                && func_021FF2D8((Work_021FF228 *)w, i) == 0)
                func_021FF870((Work_021FF870 *)w, i, 2, 4, 1);
            if (func_021FFD9C((char *)w, i) == 0)
                continue;
            idx = func_022019F4((char *)w, i);
            flag = 0;
            if (func_021F7EB4() && w->e[idx].f8) {
                w->e[idx].f8 = 0;
                w->e[idx].f7 = 1;
            }
            if (func_021F7EB4() && w->e[idx].f7)
                continue;
            w->e[idx].f7 = 0;
            if (func_021FFF38((char *)w, i) & 4)
                continue;
            if (func_021F821C(i, &a, &b) == 0)
                continue;
            if (w->e[idx].f1 == 1) {
                if (w->e[idx].f54 == 0)
                    w->e[idx].f54 = 1;
                if (w->e[idx].f58++ > 0x18) {
                    flag = 1;
                    w->e[idx].f58 = 0;
                    w->e[idx].f50 += w->e[idx].f54;
                    if (w->e[idx].f50 == 0 || w->e[idx].f50 == 12)
                        w->e[idx].f54 *= -1;
                }
            }
            switch (b) {
            case 3:
                func_021FFE24((Work_vFE24 *)w, i);
                func_021FF260((Work_021FF228 *)w, i, 3);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                func_021FF498((char *)w, i, (void *)0x555);
                w->e[idx].f1 = 1;
                break;
            case 1:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, (u8)w->e[idx].f50, 0x1ef);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                w->e[idx].f1 = 1;
                break;
            case 2:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, 8, 0x7def);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 2);
                w->e[idx].f1 = 1;
                break;
            case 5:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, (u8)w->e[idx].f50, 0xf);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                w->e[idx].f1 = 1;
                break;
            case 4:
            case 7:
                if (flag == 1)
                    func_021FFDF8((Work_vFCB0 *)w, i, (u8)w->e[idx].f50, 0x3c0f);
                func_021FF260((Work_021FF228 *)w, i, 4);
                func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                w->e[idx].f1 = 1;
                break;
            case 8:
            default:
                if (w->e[idx].f1 == 1) {
                    func_021FFE24((Work_vFE24 *)w, i);
                    func_021FF260((Work_021FF228 *)w, i, 4);
                    func_021FF304((Work_021FF228 *)((char *)w), i, 3);
                    func_021FF498((char *)w, i, (void *)0x1000);
                    w->e[idx].f1 = 0;
                    w->e[idx].f54 = 0;
                    w->e[idx].f50 = 0;
                    w->e[idx].f58 = 0;
                }
                break;
            }
            if (b == 8) {
                if ((u32)(a - 2) <= 1)
                    func_021FF498((char *)w, i, (void *)0x555);
                else
                    func_021FF498((char *)w, i, (void *)0x1000);
            }
        }
    }
}














void func_021FEE9C(int *p)
{
    MCSS_Draw((struct McssSys *)p[1]);
}













/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * levers: grouped vectors fix stack order; integer address arithmetic on the
 * second buffer argument prevents CSE; b34 is one two-bit assignment.
 * Verified scratch C, EXACT (blocker_02015D94_r1.log):
 * void MCSS_SetShadowOffset(char *p, int *src) {
 *     *(int *)(p + 0x17c) = src[0];
 *     *(int *)(p + 0x180) = src[1];
 *     *(int *)(p + 0x184) = src[2];
 * }
 * Verified scratch C, EXACT (blocker_02015D88_r1.log):
 * typedef unsigned short u16;
 * void MCSS_SetShadowRotateZ(char *p, u16 value) { *(u16 *)(p + 0x17a) = value; }
 */
void func_021FEEA8(char *w, void *src, int key)
{
    int i;
    int off;
    int visible;
    u16 angle;
    Vectors vectors;
    u32 a, b;
    for (i = 0; i < 14; i++) {
        if (*(void **)(w + i * 0x5c + 8) == 0)
            break;
    }
    if (key < 14 && i < 14) {
        off = i * 0x5c;
        *(int *)(w + 0x48 + off) = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b0 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b1 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b5 = 0;
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b2 = ((struct Obj13604 *)w)->f534;
        *(int *)(w + 0x50 + off) = key;
        *(u32 *)(w + 0x3c + off) = func_02017E1C(src, 0, 0);
        *(u32 *)(w + 0x44 + off) = func_02017E1C(src, 0x98, 0);
        if (func_02017EAC(src) == 1)
            *(int *)(w + 0x48 + off) |= 2;
        func_022003EC((Work_022003EC *)w, src, (int *)(w + 0xc + off), key);
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)(&vectors.pos)), key);
        *(void **)(w + 8 + off) = MCSS_Add(((struct Obj13604 *)w)->f4, vectors.pos.x, vectors.pos.y, vectors.pos.z, (void *)((u32)w + 0xc + off));
        func_0220055C((Work_0220055C *)w, key, 1);
        *(u32 *)(w + 0x34 + off) = func_02017E1C(src, 5, 0);
        *(u32 *)(w + 0x38 + off) = func_02017E1C(src, 0x6f, 0);
        *(u16 *)(w + 0x40 + off) = func_02019C90(*(u32 *)(w + 0x34 + off), *(u32 *)(w + 0x38 + off), 0x26);
        a = func_02017E1C(src, 0xa0, 0);
        b = func_02017E1C(src, 0xa1, 0);
        *(u16 *)(w + 0x42 + off) = func_0202D034(a, b);
        if (func_02201A20(*(int *)(w + 0x34 + off), key, (int *)(&vectors.orient), &angle, &visible) == 0) {
            vectors.orient.x = -0x400;
            vectors.orient.y = 0;
            vectors.orient.z = -0x600;
            angle = 0xf800;
            visible = 1;
        }
        if (visible == 0)
            MCSS_SetShadowAlpha(*(void **)(w + 8 + off), 0);
        else {
            MCSS_SetShadowOffset(*(void **)(w + 8 + off), (int *)(&vectors.orient));
            MCSS_SetShadowRotateZ(*(void **)(w + 8 + off), angle);
        }
        ((Flags_021FEEA8 *)(w + 0x54 + off))->b34 = 3;
        func_022006B4((Work_022006B4 *)w, key);
        func_02015F2C(*(void **)(w + 8 + off), i, (void *)func_02201718, 1);
    }
}












void func_021FF088(Work_vE254 *w, void *src, int key)
{
    int i;
    char buf[0x24];
    Vec_021FF088 v;

    for (i = 0; i < 14; i++) {
        if (w->e[i].h == 0)
            break;
    }
    if (key < 14 && i < 14) {
        w->e[i].flip = 1;
        w->e[i].k48 = key;
        func_022006A0(src, buf, key);
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)&v), key);
        w->e[i].h = MCSS_Add(w->obj, v.x, v.y, v.z, (const struct Sub150 *)buf);
        func_022006B4((Work_022006B4 *)w, key);
    }
}















void func_021FF0F8(Work_021FF0F8 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    MCSS_Del(w->obj, w->e[idx].h);
    w->e[idx].h = 0;
    if (w->e[idx].task != 0) {
        func_020307B0((void *)TCBL_IsDeletePending(w->e[idx].task));
        func_02030EAC(w->e[idx].task);
        w->e[idx].task = 0;
    }
}















void func_021FF134(char *p, int a, int b)
{
    ((struct Obj12218 *)p)->f538 = a;
    ((struct Obj12218 *)p)->f53C = b;
}















void func_021FF144(Work_021FF144 *w, int key, fx32 x, fx32 y, fx32 z)
{
    int idx = func_022019F4((char *)w, key);
    VecFx32 v;

    v.x = x;
    v.y = y;
    v.z = z;
    MCSS_SetPosition(w->e[idx].h, (u32 *)(&v));
}















void func_021FF16C(Work_021FF16C *w)
{
    int i;
    int idx;

    MCSS_SetOrthoMode(w->obj);
    w->active = 1;
    for (i = 0; i < 14; i++) {
        idx = func_022019F4((char *)w, i);
        if (idx != -1) {
            w->e[idx].flip = 1;
            func_022006B4((Work_022006B4 *)w, i);
        }
    }
}













void func_021FF1B0(Work_021FF1B0 *w)
{
    int i;
    int idx;

    MCSS_ResetOrthoMode(w->obj);
    w->active = 0;
    for (i = 0; i < 14; i++) {
        idx = func_022019F4((char *)w, i);
        if (idx != -1) {
            w->e[idx].flip = 0;
            func_022006B4((Work_022006B4 *)((Work_021FF16C *)w), i);
        }
    }
}












void func_021FF1F4(Work_vE254 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    w->e[idx].flip = 1;
    MCSS_SetOrthoBillboardFlag(w->e[idx].h);
    func_022006B4((Work_022006B4 *)((Work_021FF16C *)w), key);
}














void func_021FF228(Work_021FF228 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    w->e[idx].flip = 0;
    MCSS_ResetOrthoBillboardFlag(w->e[idx].h);
    func_022006B4((Work_022006B4 *)w, key);
}














/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   MCSS_SetMepachiFlag, MCSS_ResetMepachiFlag, MCSS_FlipMepachiFlag.  All the integrator's; verified C
 *   (one --thumb, no --region, EXACT each; +0x140 is a register-like word):
 *     struct R { unsigned int : 8; unsigned int f : 1; };
 *     void MCSS_SetMepachiFlag(void *p) { *(unsigned int *)((char *)p + 0x140) |= 0x100u; }
 *     void MCSS_ResetMepachiFlag(void *p) { *(unsigned int *)((char *)p + 0x140) &= ~0x100u; }
 *     void MCSS_FlipMepachiFlag(void *p) { ((struct R *)((char *)p + 0x140))->f ^= 1; }
 *   Re-run this file once layout/matched/arm9 shards for all three exist.
 */
void func_021FF260(Work_021FF228 *w, int key, int mode)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 4) {
        MCSS_ResetMepachiFlag(w->e[idx].h);
        w->e[idx].f0 = 0;
    }
    if (w->e[idx].f0)
        return;
    if (mode == 2) {
        MCSS_FlipMepachiFlag(w->e[idx].h);
    } else if (mode == 1) {
        MCSS_SetMepachiFlag(w->e[idx].h);
    } else if (mode == 3) {
        MCSS_SetMepachiFlag(w->e[idx].h);
        w->e[idx].f0 = 1;
    } else {
        MCSS_ResetMepachiFlag(w->e[idx].h);
    }
}














int func_021FF2D8(Work_021FF228 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return MCSS_GetAnmStopFlag(w->e[idx].h);
}














/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   MCSS_SetAnmStopFlagAlways (0x02015E28) and MCSS_ResetAnmStopFlagAlways (0x02015E70).  Both are the integrator's;
 *   verified C (one --thumb, no --region, EXACT each):
 *     struct R { unsigned int : 9; unsigned int f : 2; };
 *     void MCSS_SetAnmStopFlagAlways(void *p) { ((struct R *)((char *)p + 0x140))->f |= 2; }
 *     void MCSS_ResetAnmStopFlagAlways(void *p) { ((struct R *)((char *)p + 0x140))->f &= ~2u; }
 *   Re-run this file once layout/matched/arm9 shards for both exist.
 */
void func_021FF304(Work_021FF228 *w, int key, int mode)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 1)
        MCSS_SetAnmStopFlag(w->e[idx].h);
    else if (mode == 2)
        MCSS_SetAnmStopFlagAlways(w->e[idx].h);
    else if (mode == 3)
        MCSS_ResetAnmStopFlagAlways(w->e[idx].h);
    else
        MCSS_ResetAnmStopFlag(w->e[idx].h);
}













int func_021FF348(Work_021FF348 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return MCSS_GetVanishFlag(w->e[idx].h);
}












void func_021FF374(Work_vF228 *w, int key, int kind)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    switch (kind) {
    case 2:
        MCSS_FlipVanishFlag(w->e[idx].h);
        break;
    case 1:
        MCSS_SetVanishFlag(w->e[idx].h);
        break;
    case 0:
        MCSS_ResetVanishFlag(w->e[idx].h);
        break;
    case 3:
        if (MCSS_GetVanishFlag(w->e[idx].h))
            w->e[idx].f5 = 1;
        MCSS_SetVanishFlag(w->e[idx].h);
        break;
    case 4:
        if (w->e[idx].f5)
            w->e[idx].f5 = 0;
        else
            MCSS_ResetVanishFlag(w->e[idx].h);
        break;
    }
}












void func_021FF3F4(void *obj, void *out, int idx)
{
    func_022018A8((Unit_v1098 *)obj, (Vec3_vF228 *)((Vec_021FE254 *)out), idx);
}












/*
 * Unlabelled: no func_ label in the listing (leaf, saves no lr); reached
 * by bl from func_021FD1CC.
 */
void func_021FF3FC(const Vec3_vF228 *def, Vec3_vF228 *out, int idx, int kind)
{
    switch (idx) {
    case 0:
    case 1:
        def = &d_0220A050[idx];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (kind == 3)
            def = &d_0220A1A0[idx - 2];
        else if (kind == 2)
            def = &d_0220A158[idx - 2];
        else
            def = &d_0220A080[idx - 2];
        break;
    case 6:
    case 7:
        if (kind == 3)
            def = &d_0220A1A0[idx - 2];
        else
            def = &d_0220A158[idx - 2];
        break;
    }
    out->x = def->x;
    out->y = def->y;
    out->z = def->z;
}











int func_021FF468(void *u, int i, int mode)
{
    return func_02201934((Unit_v1098 *)u, i, mode);
}











/*
 * Byte-identical to the original; parked because the +0014 call to 0x02015FF0
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The +0006 call to 0x022019F4 is an ov094 Thumb function.
 */
void func_021FF470(char *p, int key, u8 v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12219 *)e)->f8 == 0)
        return;
    MCSS_SetShadowVanishFlag((char *)(((struct Obj12219 *)e)->f8), v);
}











/*
 * Byte-identical to the original; parked because the call to 0x020160C4
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The call to 0x022019F4 is an ov094 Thumb function.
 */
void func_021FF498(char *p, int key, void *v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (((struct Obj12220 *)e)->f8 == 0)
        return;
    MCSS_SetAnimeSpeed((char *)(((struct Obj12220 *)e)->f8), (int)v);
}










void func_021FF4C0(char *w, int key, int kind, Vec_021F6560 *q, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec_021F6560 start;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    MCSS_GetPosition(*(void **)(e + off), (u32 *)&start);
    if (kind == 1) {
        if (key & 1)
            q->x = start.x - q->x;
        else
            q->x += start.x;
        q->y += start.y;
        q->z += start.z;
    }
    if (kind == 5) {
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)q), key);
        kind = 1;
    }
    if (kind == 6) {
        func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)q), key);
        kind = 0;
    }
    if (kind == 0) {
        MCSS_SetPosition(*(void **)(e + off), (u32 *)q);
        return;
    }
    (*(u8 *)(w + 0x542 + key))++;
    func_0220074C((Work_0220074C *)w, key, kind, (VecFx32_vFE48 *)&start, (VecFx32_vFE48 *)q, a, b, c, (void *)func_02200904, (void (*)(void *))func_02200990, 1, *(u8 *)(w + 0x542 + key));
    ((struct Obj06309 *)w)->f514 |= func_021F935C(key);
}










void func_021FF5B0(Work_021FF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetShadowScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[0][i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_022009C8, (void (*)(void *))((void ( *)(void *))func_02200A50), 0, w->cnt[0][i]);
    w->mask[0] |= func_021F935C(i);
}










void func_021FF630(Work_021FF630 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_02200A84, (void (*)(void *))((void ( *)(void *))func_02200B10), 0, w->cnt[i]);
    w->mask |= func_021F935C(i);
}










/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (the integrator's; no
 * witness outside the range): MCSS_GetShadowScale (copies three words from +0x128).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void MCSS_GetShadowScale(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x128);
 *       out[1] = *(u32 *)((char *)p + 0x12C);
 *       out[2] = *(u32 *)((char *)p + 0x130);
 *   }
 * Twin of matched func_021FF630.
 */
void func_021FF6B0(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetShadowScale(w->e[idx].h, (u32 *)(&cur));
    w->cnt[2][i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_02200B48, (void (*)(void *))((void ( *)(void *))func_02200BD4), 0, w->cnt[2][i]);
    w->mask[3] |= func_021F935C(i);
}










/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * Byte-correct; MATCH blocked on one unlabelled ARM9 Thumb leaf (the integrator's; no
 * witness outside the range): MCSS_GetRotate (copies three words from +0xF8).
 * Verified C (match.py one, no --region, --thumb, EXACT):
 *   typedef unsigned int u32;
 *   void MCSS_GetRotate(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0xF8);
 *       out[1] = *(u32 *)((char *)p + 0xFC);
 *       out[2] = *(u32 *)((char *)p + 0x100);
 *   }
 * Twin of matched func_021FF630.
 */
void func_021FF730(Work_vF5B0 *w, int i, int kind, VecFx32_vF5B0 *q, int n, int f48, int f4c)
{
    int idx = func_022019F4((char *)w, i);
    VecFx32_vF5B0 cur;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_GetRotate(w->e[idx].h, (u32 *)(&cur));
    w->cnt[3][i]++;
    func_0220074C((Work_0220074C *)((Work_021FF5B0 *)w), i, kind, (VecFx32_vFE48 *)((Vec_021F6560 *)&cur), (VecFx32_vFE48 *)((Vec_021F6560 *)q), n, f48, f4c, (void *)func_02200C0C, (void (*)(void *))((void ( *)(void *))func_02200C98), 1, w->cnt[3][i]);
    w->mask[1] |= func_021F935C(i);
}









void func_021FF7B0(Work_021FF7B0 *w, int a, int b)
{
    int keys[2];
    int idx[2];
    Vec3_vF7B0 v;
    int i;

    keys[0] = a;
    keys[1] = b;
    for (i = 0; i < 2; i++) {
        idx[i] = func_022019F4((char *)w, keys[i]);
        if (func_021FFD9C((char *)w, keys[i])) {
            func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)((Vec_021FE254 *)&v), keys[i ^ 1]);
            func_021FF4C0((char *)w, keys[i], 0, (Vec_021F6560 *)&v, 0, 0, 0);
            func_022089BC((char *)func_021F86B4(), keys[i]);
            if (w->e[idx[i]].f6) {
                w->e[idx[i]].f6 = 0;
                func_021FF374((Work_vF228 *)w, keys[i], 0);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (idx[i] != -1)
            w->e[idx[i]].key = keys[i ^ 1];
    }
}









void func_021FF870(Work_021FF870 *w, int key, int kind, int a, int b)
{
    Obj_021FF870 *o;

    switch (kind) {
    case 3:
        func_021FF260((Work_021FF228 *)w, key, 1);
        return;
    case 4:
        func_021FF260((Work_021FF228 *)w, key, 0);
        return;
    case 2:
        o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0x5e5);
        o->w = w;
        o->i = key;
        o->kind = kind;
        o->f44 = 0;
        o->f48 = a;
        o->f4c = b * 2;
        w->cnt[0][key]++;
        o->f50 = w->cnt[0][key];
        func_021F896C((void *)func_02030DA8((void *)w->owner, func_02200CD0, o, 0), func_02200D30, 2);
        w->mask[2] |= func_021F935C(key);
        return;
    }
}








/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * Verified scratch C, EXACT (blocker_02015FAC_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int value : 8; } Data;
 * u8 MCSS_GetAlpha(Data *p) { return p->value; }
 */
void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec_021F6560 start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(MCSS_GetAlpha(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x596 + key))++;
    func_0220074C((Work_0220074C *)w, key, kind, (VecFx32_vFE48 *)&start, (VecFx32_vFE48 *)&end, a, b, c, (void *)func_02200D68, (void (*)(void *))func_02200DE4, 0, *(u8 *)(w + 0x596 + key));
    ((struct Obj06309 *)w)->f52C |= func_021F935C(key);
}








/*
 * lever: the 4/5 kind test is an unsigned range check; individual equality tests cost two bytes.
 */
void func_021FFA18(Work_021FFA18 *w, Obj_021FFA18 *s)
{
    Obj_021FFA18 *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x3c, 0, d_0220AE7C, 0x627);
    o->w = w;
    o->key = s->key;
    o->kind = s->kind;
    o->direction = s->direction;
    o->f10 = s->f10;
    o->f14 = s->f14;
    o->f18 = s->f18;
    o->f1c = s->f1c;
    o->f20 = s->f20;
    o->f24 = s->f24;
    o->f30 = 0;
    o->f34 = 0;
    if (o->key & 1) {
        if ((o->kind != 0 && o->kind != 1 && (unsigned)(o->kind - 4) > 1)
            || (s->direction != 2 && s->direction != 3))
            o->direction ^= 1;
    }
    o->f28 = (o->kind & 1) ? 0x10000 : 0;
    o->f2c = 0x10000 / s->f18;
    w->cnt[o->key]++;
    o->f38 = w->cnt[o->key];
    func_021F896C((void *)func_02030DA8(w->owner, func_02200E1C, o, 0), func_02201098, 2);
    w->mask |= func_021F935C(o->key);
}









void func_021FFB04(Work_vF7B0 *w, Obj_vF7B0 *s)
{
    Obj_vF7B0 *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x2c, 0, d_0220AE7C, 0x660);
    int idx = func_022019F4((char *)w, s->key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    *o = *s;
    o->w = w;
    MCSS_GetPosition(w->e[idx].h, (u32 *)o->v);
    w->cnt[0][o->key]++;
    o->f28 = w->cnt[0][o->key];
    func_021F896C((void *)func_02030DA8(w->owner, func_022010D0, o, 0), func_022011FC, 2);
    w->mask[0] |= func_021F935C(o->key);
}








/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * Verified scratch C, EXACT (blocker_02016068_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int padbits : 24; unsigned int value : 4; } Data;
 * u8 MCSS_GetMosaic(Data *p) { return p->value; }
 */
void func_021FFBBC(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec_021F6560 start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(MCSS_GetMosaic(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x5a4 + key))++;
    func_0220074C((Work_0220074C *)w, key, kind, (VecFx32_vFE48 *)&start, (VecFx32_vFE48 *)&end, a, b, c, (void *)func_02201234, (void (*)(void *))func_022012CC, 0, *(u8 *)(w + 0x5a4 + key));
    ((struct Obj06309 *)w)->f530 |= func_021F935C(key);
}








int func_021FFCB0(Work_021FFCB0 *w, int key)
{
    int r = 0;

    if (func_021FFD9C((char *)w, key))
        r = MCSS_CheckPaletteFade(w->e[func_022019F4((char *)w, key)].h);
    if (func_021F935C(key) & w->m514
        || func_021F935C(key) & w->m518
        || func_021F935C(key) & w->m524
        || func_021F935C(key) & w->m520
        || func_021F935C(key) & w->m51c
        || func_021F935C(key) & w->m528
        || func_021F935C(key) & w->m52c
        || func_021F935C(key) & w->m530
        || w->f510
        || r)
        return 1;
    return 0;
}








int func_021FFD6C(Work_021FFD6C *w)
{
    Key_021FD04C i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i) && func_021FFCB0((Work_021FFCB0 *)w, i))
            return 1;
    }
    return 0;
}








int func_021FFD9C(char *p, int key)
{
    if (func_022019F4(p, key) != -1)
        return 1;
    return 0;
}








void func_021FFDB4(Work_vFCB0 *w, int key, u8 cur, u8 target, u8 step, u32 e)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_SetPaletteFade(w->e[idx].h, cur, target, (s8)step, e);
    w->e[idx].flags |= 0x100;
}








void func_021FFDF8(Work_vFCB0 *w, int key, int a, int b)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_CreatePaletteTransTask(w->obj, w->e[idx].h, a, b);
}





void func_021FFE24(Work_vFE24 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_CreatePaletteCopyTask(w->obj, w->e[idx].h);
}


#undef FX_INT_TO_FX32

#undef FX_INT_TO_FX32

#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f)                                             : ((float)((x) << 12) - .5f)))


#undef MUL

#undef MUL

#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))














void func_021FFE48(Work_021FFE48 *w, int key, void *p)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    w->e[idx].a = func_02017E1C(p, 5, 0);
    w->e[idx].b = func_02017E1C(p, 0x6f, 0);
    w->e[idx].d = func_02019C90(w->e[idx].a, w->e[idx].b, 0x26);
    w->e[idx].c = func_02017E1C(p, 0, 0);
    w->e[idx].f = func_02017E1C(p, 0x98, 0);
    if (func_02017EAC(p) == 1)
        w->e[idx].flags0 |= 2;
    w->e[idx].e = func_0202D034(func_02017E1C(p, 0xa0, 0), func_02017E1C(p, 0xa1, 0));
    w->e[idx].flags |= 0x200;
}















int func_021FFF0C(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12223 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12223 *)e)->f40;
}















int func_021FFF38(char *p, int key)
{
    int i;
    char *e;

    if (key == 0xff)
        return 0;
    i = func_022019F4(p, key);
    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12224 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12224 *)e)->f48;
}














int func_021FFF68(Work_021FFF68 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    if (func_02019C90(w->e[idx].a, w->e[idx].b, 0x10))
        return 1;
    return 0;
}














int func_021FFFAC(Work_021FFFAC *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return MCSS_GetStopCellFlags(w->e[idx].h);
}














void func_021FFFD8(char *w, int key, int flag, int clear)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Rec_021FFFD8 r;
    int odd;

    if (idx == -1)
        return;
    e = w;
    e += 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    if (flag == 0) {
        MCSS_TOOL_SetSpindaSpotHook((int)(((struct Obj01047 *)w)->f4), *(u32 *)(w + off + 0x3c));
        MCSS_ReloadResource(((struct Obj01047 *)w)->f4, *(void **)(w + 8 + off), (const struct Sub02014CF8Rec *)(w + 0xc + off));
        func_02015F2C(*(void **)(w + 8 + off), idx, (void *)func_02201718, 1);
        if (clear)
            *(u32 *)(w + 0x48 + off) &= ~1u;
        *(u32 *)(w + 0x48 + off) &= ~4u;
    } else {
        r.v[0] = POKEGRA_GetArcID();
        odd = key & 1;
        r.v[1] = odd ? 0x37a0 : 0x37a6;
        r.v[2] = 0x37ac;
        r.v[3] = odd ? 0x37a1 : 0x37a7;
        r.v[4] = odd ? 0x37a2 : 0x37a8;
        r.v[5] = odd ? 0x37a3 : 0x37a9;
        r.v[6] = odd ? 0x37a4 : 0x37aa;
        r.v[7] = odd ? 0x37a5 : 0x37ab;
        r.v[8] = 0;
        MCSS_ReloadResource(((struct Obj01047 *)w)->f4, *(void **)(e + off), (const struct Sub02014CF8Rec *)(&r));
        func_021FFE24((Work_vFE24 *)w, key);
        if (clear)
            *(u32 *)(w + 0x48 + off) |= 1;
        *(u32 *)(w + 0x48 + off) |= 4;
    }
}














void func_02200108(Work_02200108 *w, int key, int v)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, w->e[idx].k34);
    MCSS_SetMosaic(w->obj, w->e[idx].h, v);
}














void func_02200140(Work_02200140 *w, int key1, int key2)
{
    int i1 = func_022019F4((char *)w, key1);
    int i2 = func_022019F4((char *)w, key2);

    w->e[i2].f04 = w->e[i1].f04;
    w->e[i2].f0c = w->e[i1].f0c;
    if (key1 & 1) {
        w->e[i2].f08 = w->e[i1].f08 + 9;
        w->e[i2].f10 = w->e[i1].f10 + 9;
        w->e[i2].f14 = w->e[i1].f14 + 9;
        w->e[i2].f18 = w->e[i1].f18 + 9;
        w->e[i2].f1c = w->e[i1].f1c + 9;
        w->e[i2].f20 = w->e[i1].f20 + 9;
    } else {
        w->e[i2].f08 = w->e[i1].f08 - 9;
        w->e[i2].f10 = w->e[i1].f10 - 9;
        w->e[i2].f14 = w->e[i1].f14 - 9;
        w->e[i2].f18 = w->e[i1].f18 - 9;
        w->e[i2].f1c = w->e[i1].f1c - 9;
        w->e[i2].f20 = w->e[i1].f20 - 9;
    }
    w->e[i2].q = w->e[i1].q;
    MCSS_ReloadResource(w->obj, w->e[i2].h, (const struct Sub02014CF8Rec *)(&w->e[i2].f04));
}














void func_022001DC(Work_022001DC *w, int key, Rec_022001DC *r)
{
    int idx = func_022019F4((char *)w, key);

    w->e[idx].rec = *r;
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, w->e[idx].k34);
    MCSS_ReloadResource(w->obj, w->e[idx].h, (const struct Sub02014CF8Rec *)(&w->e[idx].rec));
}














int func_02200218(Work_02200218 *w, int key, int pitch, int pan, int a4, int a5, int a6)
{
    int idx = func_022019F4((char *)w, key);
    u32 id;
    u32 buf;
    u32 *out;
    int flag;
    void *p;
    u32 r;

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    switch (key) {
    case 0:
    case 1:
        id = d_02209FC0[key];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else if (w->flags.b0)
            id = d_0220A068[key - 2];
        else
            id = d_02209FE0[key - 2];
        break;
    case 6:
    case 7:
        if (w->flags.b1)
            id = d_02209FF0[key - 2];
        else
            id = d_0220A068[key - 2];
        break;
    }
    p = (void *)func_021F8754();
    out = &buf;
    flag = 0;
    if (p != 0) {
        if (func_021B994C(p, key, out) == 0)
            out = 0;
    } else {
        out = 0;
    }
    if (a4 != 0 || a5 != 0)
        flag = 1;
    if (pitch == (int)0x80000000) {
        if (w->e[idx].k3a == 1)
            pitch = -0xa00;
        else
            pitch = 0;
    }
    r = PM_VOICE_Play(w->e[idx].k2c, w->e[idx].k30, (u8)id, flag, a4, a5, a6, (u32)out);
    PM_VOICE_AddVolume(r, (signed char)pan);
    PM_VOICE_AddFrequency(r, pitch);
    return r;
}














void func_02200344(Work_02200344 *w, int a, int b, int flag)
{
    Obj_vFE48 *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x24, 0, d_0220AE7C, 0x8f2);

    o->w = w;
    o->a = 0;
    o->flag = flag;
    o->f8 = a;
    o->fc = b;
    w->flags |= 4;
    func_021F896C(func_02030DA8(w->owner, func_02201408, o, 0), func_02201700, 2);
}













int func_022003C4(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12226 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12226 *)e)->f44;
}













void func_022003EC(Work_022003EC *w, void *p, int *a, int flags)
{
    int v = 1;

    if (flags & 1)
        v = 0;
    MCSS_TOOL_MakeAddWorkFromPP(p, (struct Stats *)a, v);
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, func_02017E1C(p, 0, 0));
}













/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical (one prints MATCH*); blocked on 0x020160CC, an
 * unfiled unlabelled ARM9 Thumb leaf (the integrator's) with no witness outside this
 * range. Verified C for it (EXACT, `one --thumb`, no --region, cc 1.1p1,
 * -O4,p; packet pkt_020160CC, 64 B extent):
 *
 *   typedef unsigned short u16;
 *   typedef struct { char pad[0x28]; u16 *p28; } S;
 *   u16 MCSS_GetAnimSeqNumEx(S *s) { return *s->p28; }
 *
 * The extern here takes `int` as return type (u16 not needed at the caller).
 */
int func_0220041C(Work_0220041C *w, int key, int n)
{
    int r = 0;
    int i = func_022019F4((char *)w, key);

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (n < MCSS_GetAnimSeqNumEx(w->e[i].h)) {
        MCSS_SetAnimeIndex(w->e[i].h, n);
        r = 1;
        w->e[i].f44 = r;
    }
    return r;
}













void func_02200468(Work_02200468 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_02015F2C(w->e[idx].h, idx, (void *)func_02201894, 1);
}













int func_02200494(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12228 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12228 *)e)->f4C;
}













/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on 0x02015C60, an unfiled unlabelled ARM9
 * Thumb leaf (the integrator's) with no witness outside this range. Verified C for it
 * (EXACT, `one --thumb`, no --region, cc 1.1p1, -O4,p; packet pkt_02015C60,
 * 64 B extent, out-direction twin of MCSS_SetOfsPosition):
 *
 *   typedef unsigned int u32;
 *   void MCSS_GetOfsPosition(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x11C);
 *       out[1] = *(u32 *)((char *)p + 0x120);
 *       out[2] = *(u32 *)((char *)p + 0x124);
 *   }
 */
void func_022004BC(Work_022004BC *w, int key)
{
    Vec_vFE48 want;
    Vec_vFE48 cur;
    Vec_vFE48 off;
    int i = func_022019F4((char *)w, key);

    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    func_022018A8((Unit_v1098 *)w, (Vec3_vF228 *)&want, key);
    MCSS_GetPosition(w->e[i].h, (u32 *)(&cur));
    MCSS_GetOfsPosition(w->e[i].h, (u32 *)(&off));
    w->e[i].flags &= ~0x40;
    if (want.x == cur.x && want.y == cur.y && want.z == cur.z
        && off.x == 0 && off.y == 0 && off.z == 0)
        return;
    w->e[i].flags |= 0x40;
    off.x = 0;
    off.y = 0;
    off.z = 0;
    MCSS_SetPosition(w->e[i].h, (u32 *)(&want));
    MCSS_SetOfsPosition(w->e[i].h, (u32 *)(&off));
    MCSS_SetVanishFlag(w->e[i].h);
}













/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   0220055C..022005C2). Every concrete byte matches (MATCH*, the extent's 2 extra bytes
 *   are the pad); only the final bl relocation stays wildcarded.
 *   Verified C (match.py one, --thumb, no --region, dsi/1.1p1 -O4,p), EXACT, 28 bytes:
 *
 *     typedef struct { char pad[0x140]; unsigned int lo : 30; unsigned int f : 1;
 *                      unsigned int hi : 1; } S;
 *     void MCSS_SetWorkFlag(S *s, int f)        // 0x02016394
 *     {
 *         s->f = f;
 *     }
 *
 * lever: each arm of the result switch writes `f = 1` out in its own inner switch
 *   (`switch (key) { case 3: case 4: f = 1; break; }`), so the case-1 copy is
 *   cross-jumped into a `b` after threading and the key == 3 beq keeps pointing at it
 *   (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md); a
 *   shared `set:` label lets the beq be threaded straight to `f = 1` (2 bytes out), and
 *   `key == 3 || key == 4` folds to a range test.
 */
void func_0220055C(Work_0220055C *w, int key, int mode)
{
    int f = 0;
    int i;

    i = func_022019F4((char *)w, key);
    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    if (mode == 1) {
        switch (func_021F8710()) {
        case 0:
        case 3:
            break;
        case 1:
            switch (key) {
            case 3:
            case 4:
                f = 1;
                break;
            }
            break;
        case 2:
            switch (key) {
            case 2:
            case 5:
            case 6:
                f = 1;
                break;
            }
            break;
        }
    }
    MCSS_SetWorkFlag(w->e[i].h, f);
}













int func_022005C4(Work_022005C4 *w, int key)
{
    int i = func_022019F4((char *)w, key);
    int r;

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (w->e[i].f9)
        r = 1;
    else
        r = 0;
    w->e[i].f9 = 0;
    return r;
}












void func_02200608(Work_02200608 *w)
{
    Slot_021FFE48 i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            j = func_022019F4((char *)w, i);
            w->e[j].f10 = func_021FF348((Work_021FF348 *)w, i);
        }
    }
}












void func_02200654(Work_02200654 *w)
{
    Slot_021FFE48 i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            j = func_022019F4((char *)w, i);
            func_021FF374((Work_vF228 *)w, i, w->e[j].f10);
            w->e[j].f5 = 0;
        }
    }
}












/*
 * Tail-call stub: forwards (p, out) and passes !(flags & 1) as the third
 * argument of MCSS_TOOL_MakeAddWorkFromTrainer.
 */
void func_022006A0(void *p, void *out, int flags)
{
    MCSS_TOOL_MakeAddWorkFromTrainer(p, out, (void *)((flags & 1) == 0));
}












static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}












/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on 0x02015D30, an unlabelled ARM9 Thumb
 * leaf (stores a VecFx32_vFE48 at +0x104, beside the matched MCSS_SetScale) with no
 * witness. Filing that ARM9 leaf closes this.
 */
void func_022006B4(Work_022006B4 *w, int i)
{
    int idx = func_022019F4((char *)w, i);
    fx32 v;
    VecFx32_vFE48 s;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    v = func_02201934((Unit_v1098 *)w, i, w->e[idx].flip);
    if (i & 1)
        v = FX_Mul(v, w->scaleOdd);
    else
        v = FX_Mul(v, w->scaleEven);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    MCSS_SetScale(w->e[idx].h, (u32 *)(&s));
    v = func_02201934((Unit_v1098 *)w, i, 0);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    MCSS_SetOfsScale(w->e[idx].h, (u32 *)(&s));
}











void func_0220074C(Work_0220074C *w, int i, int kind, VecFx32_vFE48 *p, VecFx32_vFE48 *q, int n,
                   int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50)
{
    Mover_0220074C *o = sub_02030734((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, d_0220AE7C, 0xa4e);

    o->w = w;
    o->i = i;
    o->kind = kind;
    o->frames = n;
    o->left = n;
    o->count = 0;
    o->f48 = f48;
    o->f4c = f4c * 2;
    o->start.x = p->x;
    o->start.y = p->y;
    o->start.z = p->z;
    o->end.x = q->x;
    o->end.y = q->y;
    o->end.z = q->z;
    o->cur.x = p->x;
    o->cur.y = p->y;
    o->cur.z = p->z;
    o->f50 = f50;
    switch (kind) {
    case 0:
        break;
    case 1:
    case 4:
        func_021F918C((const VecFx32_021F8F30 *)(&o->start), (const VecFx32_021F8F30 *)q, (VecFx32_021F8F30 *)(&o->step), FX_INT_TO_FX32(n));
        break;
    case 3:
        o->f4c *= 2;
    case 2:
        o->step.x = sub_0207C768(q->x, FX_INT_TO_FX32(n));
        o->step.y = sub_0207C768(q->y, FX_INT_TO_FX32(n));
        o->step.z = sub_0207C768(q->z, FX_INT_TO_FX32(n));
        if ((i & 1) && flip) {
            o->step.x *= -1;
            o->step.z *= -1;
        }
        break;
    }
    func_021F896C(func_02030DA8(w->owner, fn, o, 0), cb, 2);
}











/*
 * Task callback, twin of func_02200A84 on the +0xE0 vector.
 */
void func_02200904(void *h, Ctx_021FFE48 *c)
{
    Work_02200904 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetPosition(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)(&c->mv), (VecFx32_021F8F30 *)&v);
    MCSS_SetPosition(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}









void func_02200990(void *h)
{
    Ctx_02200990 *c = (Ctx_02200990 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}








void func_022009C8(void *h, Ctx_vFE48 *c)
{
    Work_vFE48 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetShadowScale(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetShadowScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}








void func_02200A50(void *h)
{
    Ctx_02200A50 *c = (Ctx_02200A50 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}








/*
 * Task callback passed by func_021FF630.
 */
void func_02200A84(void *h, Ctx_02200A84 *c)
{
    Work_02200A84 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetScale(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}








/*
 * Task destructor passed by func_021FF630.
 */
void func_02200B10(void *h)
{
    Ctx_02200B10 *c = (Ctx_02200B10 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}








/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on two unfiled ARM9 Thumb leaves (the integrator's),
 * no witness outside this range. Verified C, each EXACT with `one --thumb`
 * and no --region (cc 1.1p1, -O4,p), packets pkt_02015D4C / pkt_02015D64:
 *
 *   typedef unsigned int u32;
 *   void MCSS_GetDrawScale(void *p, u32 *out)   // 0x02015D4C, 64 B extent
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x110);
 *       out[1] = *(u32 *)((char *)p + 0x114);
 *       out[2] = *(u32 *)((char *)p + 0x118);
 *   }
 *   void MCSS_SetDrawScale(void *p, u32 *src)  // 0x02015D64, inverse
 *   {
 *       *(u32 *)((char *)p + 0x110) = src[0];
 *       *(u32 *)((char *)p + 0x114) = src[1];
 *       *(u32 *)((char *)p + 0x118) = src[2];
 *   }
 *
 * Task callback, twin of func_02200A84.
 */
void func_02200B48(void *h, Ctx_02200B48 *c)
{
    Work_02200B48 *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetDrawScale(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetDrawScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}








void func_02200BD4(void *h)
{
    Ctx_02200BD4 *c = (Ctx_02200BD4 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}








void func_02200C0C(void *h, Ctx_02200C0C *c)
{
    Work_02200C0C *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32_vFE48 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    MCSS_GetRotate(w->e[i].h, (u32 *)(&v));
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(&c->mv)), (VecFx32_021F8F30 *)&v);
    MCSS_SetRotate(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}








void func_02200C98(void *h)
{
    Ctx_02200C98 *c = (Ctx_02200C98 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}








/*
 * Task callback.
 */
void func_02200CD0(void *h, void *arg)
{
    Ctx_02200CD0 *c = arg;

    Work_02200CD0 *w = c->w;

    if (func_021FFD9C((char *)w, c->key) == 0 || c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    if (c->wait == 0) {
        c->wait = c->reload;
        func_021FF260((Work_021FF228 *)c->w, c->key, 2);
        if (--c->count == 0) {
            func_021FF260((Work_021FF228 *)c->w, c->key, 0);
            func_021F89BC(h);
        }
    } else {
        c->wait--;
    }
}







void func_02200D30(void *h)
{
    Ctx_v0D30 *c = (Ctx_v0D30 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}







void func_02200D68(void *o, char *q)
{
    char *p = *(char * *)&((struct Obj06316 *)q)->f0;
    int i = func_022019F4(p, ((struct Obj06316 *)q)->f4);
    char *e;
    int off;
    int r;

    if (i == -1) {
        func_021F89BC(o);
        return;
    }
    e = p + 8;
    off = i * 0x5C;
    if (*(int *)(e + off) == 0) {
        func_021F89BC(o);
        return;
    }
    if (((struct Obj06316 *)q)->f50 != *(u8 *)(p + ((struct Obj06316 *)q)->f4 + 0x596)) {
        func_021F89BC(o);
        return;
    }
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(q + 0x14)), (VecFx32_021F8F30 *)((VecFx32_vFE48 *)((int *)(q + 8))));
    MCSS_SetAlpha(*(char **)(e + off), (u8)(((struct Obj06316 *)q)->f8 >> 12));
    if (r == 1)
        func_021F89BC(o);
}






void func_02200DE4(void *h)
{
    Ctx_v0DE4 *c = (Ctx_v0DE4 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}





void func_02200E1C(void *task, void *arg)
{
    char *q = arg;

    char *p = *(char * *)&((struct Obj00264 *)q)->f0;
    Vec_021FFE48 v = {0, 0, 0};
    int i = func_022019F4(p, ((struct Obj00264 *)q)->f4);
    char *e;
    int off;
    int x, y;
    int j;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj00264 *)q)->f38 != *(u8 *)(p + ((struct Obj00264 *)q)->f4 + 0x542)) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj00264 *)q)->f34 == 0) {
        if (((struct Obj00264 *)q)->f30 == ((struct Obj00264 *)q)->f1C) {
        ((struct Obj00264 *)q)->f30 = 0;
        if (((struct Obj00264 *)q)->f8 & 1)
            ((struct Obj00264 *)q)->f28 -= ((struct Obj00264 *)q)->f2C;
        else
            ((struct Obj00264 *)q)->f28 += ((struct Obj00264 *)q)->f2C;
        if (((struct Obj00264 *)q)->f28 & 0xffff0000) {
            ((struct Obj00264 *)q)->f28 = (u16)((struct Obj00264 *)q)->f28;
            ((struct Obj00264 *)q)->f20 -= 1;
            ((struct Obj00264 *)q)->f34 = ((struct Obj00264 *)q)->f24;
        }
        if (((struct Obj00264 *)q)->f20 != 0) {
            switch (((struct Obj00264 *)q)->fC) {
            case 0:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = d_020A1B38[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = d_020A1B38[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                x += ((struct Obj00264 *)q)->f10;
                break;
            case 1:
                j = ((u16)(((struct Obj00264 *)q)->f28 + 0x4000) >> 4) * 2;
                x = d_020A1B38[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10) - ((struct Obj00264 *)q)->f10;
                y = d_020A1B38[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14);
                break;
            case 2:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = d_020A1B38[j];
                x = -MUL(x, ((struct Obj00264 *)q)->f10);
                y = d_020A1B38[j + 1];
                y = -MUL(y, ((struct Obj00264 *)q)->f14);
                y += ((struct Obj00264 *)q)->f14;
                break;
            case 3:
                j = (((struct Obj00264 *)q)->f28 >> 4) * 2;
                x = d_020A1B38[j];
                x = MUL(x, ((struct Obj00264 *)q)->f10);
                y = d_020A1B38[j + 1];
                y = MUL(y, ((struct Obj00264 *)q)->f14) - ((struct Obj00264 *)q)->f14;
                break;
            }
            switch ((((struct Obj00264 *)q)->f8 & 7) >> 1) {
            default:
            case 0:
                v.z = x;
                v.y = y;
                break;
            case 1:
                v.x = x;
                v.z = y;
                break;
            case 2:
                v.x = x;
                v.y = y;
                break;
            }
        }
        MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
        } else {
            ((struct Obj00264 *)q)->f30 += 1;
        }
    } else {
        ((struct Obj00264 *)q)->f34 -= 1;
    }
    if (((struct Obj00264 *)q)->f20 == 0)
        func_021F89BC(task);
}



#undef MUL


#undef MUL

#undef MUL
#define MUL(a, b) ((int)(((long long)(a) * (b) + 0x800) >> 12))







/*
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)c + 4)) while the tag index uses c->key, as in sibling
 * func_022011FC. With one spelling CSE hoists key ahead of the index and it
 * loads first (the +0x50 twins' order); with two spellings key is
 * copy-propagated and c->w loads first, as the image does.
 */
void func_02201098(void *h)
{
    Ctx_v1098 *c = (Ctx_v1098 *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(((struct Obj06318 *)c)->f4) ^ 0xFFFFFFFF;
}






/*
 * lever: Separate x/y/z clears preserve the original store order.
 */
void func_022010D0(void *task, void *arg)
{
    char *q = arg;

    char *p = *(char * *)&((struct Obj02439 *)q)->f0;
    Vec_02201098 v = {0, 0, 0};
    int i = func_022019F4(p, ((struct Obj02439 *)q)->f4);
    char *e;
    int off;
    int n, f;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (((struct Obj02439 *)q)->f28 != *(u8 *)(p + ((struct Obj02439 *)q)->f4 + 0x542)) {
        func_021F89BC(task);
        return;
    }
    ((struct Obj02439 *)q)->f18 += ((struct Obj02439 *)q)->f1C;
    n = d_020A1B38[((((struct Obj02439 *)q)->f18 & 0x0ffff000) >> 16) * 2];
    f = FIX((float)n / 4096.0f);
    f = (int)(((s64)f * ((struct Obj02439 *)q)->f20 + 0x800) >> 12);
    if (((struct Obj02439 *)q)->f14 != 0) v.y = f;
    else v.x = f;
    MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
    ((struct Obj02439 *)q)->f24 -= 1;
    if (((struct Obj02439 *)q)->f24 == 0) {
        v.x = 0;
        v.y = 0;
        v.z = 0;
        MCSS_SetOfsPosition(*(void **)(e + off), (u32 *)&v);
        func_021F89BC(task);
    }
}









/*
 * 2026-10-02 EXACT: the call argument is spelled as a raw offset load
 * (*(int *)((char *)c + 4)) while the tag index uses c->key. With the same
 * field name on both uses, CSE makes key a temp ahead of the index
 * expression and it loads first (the twins' order); with distinct
 * spellings key is copy-propagated instead and c->w loads first.
 */
void func_022011FC(void *h)
{
    Ctx_022011FC *c = (Ctx_022011FC *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(((struct Obj06319 *)c)->f4) ^ 0xFFFFFFFF;
}









void func_02201234(void *o, char *q)
{
    char *p = *(char * *)&((struct Obj05243 *)q)->f0;
    int i = func_022019F4(p, ((struct Obj05243 *)q)->f4);
    char *e;
    int off;
    int r;

    if (i == -1) {
        func_021F89BC(o);
        return;
    }
    e = p + 8;
    off = i * 0x5C;
    if (*(int *)(e + off) == 0) {
        func_021F89BC(o);
        return;
    }
    if (((struct Obj05243 *)q)->f50 != *(u8 *)(p + ((struct Obj05243 *)q)->f4 + 0x5A4)) {
        func_021F89BC(o);
        return;
    }
    r = func_021F9260((Mover_v8204 *)((Mover_02200904 *)(q + 0x14)), (VecFx32_021F8F30 *)((VecFx32_vFE48 *)((int *)(q + 8))));
    func_02200108((Work_02200108 *)p, ((struct Obj05243 *)q)->f4, ((struct Obj05243 *)q)->f8 >> 12);
    if (r == 1) {
        func_02015F2C(*(void **)(e + off), i, (void *)func_02201718, 1);
        func_021F89BC(o);
    }
}









void func_022012CC(void *h)
{
    Ctx_022012CC *c = (Ctx_022012CC *)TCBL_IsDeletePending(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}








/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015F40 belongs to the integrator.
 * Verified C: one, Thumb dsi/1.1p1 -O4,p EXACT 16 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/f40-proof.log
 * symbols for blocker: NNSi_G2dMCEnumAnimBank 0x02064D70 arm
 *   extern void NNSi_G2dMCEnumAnimBank(void *, void *, unsigned);
 *   void MCSS_SetCellCallback(char *p, unsigned flags, void *callback)
 *   { NNSi_G2dMCEnumAnimBank(p + 0x68, callback, flags); }
 * lever: Offset local precedes the entry pointer, and is initialized first.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces; both
 * 02015F40 witnesses are inside this callback. No overlay leaves filed.
 */
void func_02201304(void *task, void *arg)
{
    int *q = arg;

    char *p = (char *)func_021F8694();
    int i = q[1];
    int off;
    char *e;
    if (i == -1) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    off = i * 0x5c;
    e = p + 8;
    if (*(void **)(e + off) == 0) {
        func_020307B0(q);
        func_02030EAC(task);
        return;
    }
    switch (q[0]) {
    case 0:
        ((struct Obj21726 *)((char *)MCSS_GetAnimCtrl(*(void **)(e + off))))->fC = 0;
        MCSS_SetCellCallback(*(void **)(e + off), i | 0x80000000, func_02201810);
        q[0]++;
        q[2] = d_0220AE78[(u32)(((u64)func_0203F0A8() * 3) >> 32)];
        return;
    case 1:
        q[2]--;
        if (q[2] != 0 && ((struct Obj21725 *)p)->f51C == 0 && func_021F9824((void *)func_021F86C4()) != 0) break;
        MCSS_SetAnimeIndex(*(void **)(e + off), 0);
        ((struct Obj21727 *)((char *)MCSS_GetAnimCtrl(*(void **)(e + off))))->fC = 1;
        MCSS_SetCellCallback(*(void **)(e + off), i, func_02201810);
        q[0]++;
        return;
    case 2:
        func_02015F2C(*(void **)(e + off), i, (void *)func_02201718, 1);
        func_020307B0(q);
        func_02030EAC(task);
        *(int *)(p + off + 0x30) = 0;
        break;
    }
}









/*
 * lever: the slot test written as char-pointer arithmetic (p + k * 0x5c + 0x30)
 * swaps the row and base registers in the case-0 loop; indexing a 0x5c-byte
 * Slot_02201098 struct array evaluates the row first, as the original does.
 */
void func_02201408(void *task, void *arg)
{
    Work_02201408 *w = arg;

    Tab6 keys = d_0220A0C8;
    Tab6 angs = d_0220A0B0;
    Tab12 tgt = d_0220A0E0;
    Vec_022011FC v;
    Vec_022011FC pos;
    int idx[3];
    int i;
    int step;

    switch (w->state) {
    case 0:
        for (i = 0; i < 3; i++) {
            if (((Slot_02201098 *)w->p)[keys.v[w->idx][i]].busy != 0)
                break;
        }
        if (i != 3)
            return;
        for (i = 0; i < 3; i++)
            w->ang[i] = angs.v[w->idx][i];
        step = (w->dir == 0) ? 0x1000 : -0x1000;
        func_021F6AA8((Obj_021F6AA8 *)(func_021F86A4()), w->idx, 0, step, 0x3c);
        w->step = (w->dir == 0) ? 0x16c : -0x16c;
        w->cnt = 0x3c;
        if (w->sound)
            func_0200616C((void *)0x6ca, 2);
        w->state++;
        return;
    case 1:
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                v.x = MUL(d_020A1B38[((u16)w->ang[i] >> 4) * 2], 0x5000);
                v.y = 0x666;
                v.z = (w->idx == 0) ? 0xc000 : -0xd000;
                v.z += MUL(d_020A1B38[((u16)w->ang[i] >> 4) * 2 + 1], 0x5000);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, (Vec_021F6560 *)&v, 0, 0, 0);
            }
            w->ang[i] += w->step;
        }
        if (--w->cnt != 0)
            return;
        for (i = 0; i < 3; i++) {
            if (func_021FFD9C(w->p, keys.v[w->idx][i])) {
                func_022018A8((Unit_v1098 *)w->p, (Vec3_vF228 *)&pos, tgt.v[w->dir][w->idx][i]);
                func_021FF4C0(w->p, keys.v[w->idx][i], 0, (Vec_021F6560 *)&pos, 0, 0, 0);
            }
        }
        w->state++;
        return;
    case 2:
        if (*(int *)(w->p + 0x514) != 0)
            return;
        for (i = 0; i < 3; i++) {
            idx[i] = func_022019F4(w->p, keys.v[w->idx][i]);
            func_022089BC((char *)func_021F86B4(), keys.v[w->idx][i]);
        }
        for (i = 0; i < 3; i++) {
            if (idx[i] != -1)
                ((Slot_02201098 *)w->p)[idx[i]].target = tgt.v[w->dir][w->idx][i];
        }
        if (w->sound) {
            func_020061F8(2);
            func_0200616C((void *)0x57a, 1);
        }
        func_021F89BC(task);
        return;
    }
}









void func_02201700(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((struct Obj21729 *)p)->f510 &= ~4;
}







/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 sole-ref/code 02015EF4 and 02015EEC are integrator-owned.
 * Verified C for 02015EF4 reused from ov094_func_02201810.c:
 *   typedef unsigned char u8;
 *   u8 MCSS_GetStopCellNum(char *p) { return **(u8 **)(p + 0x30); }
 * Verified C for 02015EEC: one, Thumb dsi/1.1p1 -O4,p EXACT 6 bytes;
 * proof: scratchpad/overlay-goal-20260930-w29/B6/eec-proof.log
 *   typedef unsigned short u16;
 *   u16 MCSS_GetAnimSeqNum(char *p) { return **(u16 **)(p + 0x28); }
 * lever: Bind the random draw before the variable 64-bit product.
 * split: Caller-only tu --suggest-split MATCH, zero viable pieces;
 * 02015EEC has only this caller. No overlay leaves filed.
 */
void func_02201718(int i)
{
    char *p = (char *)func_021F8694();
    char *e;
    int off;
    unsigned n;
    u32 draw;
    int *q;
    if (i == -1) return;
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) return;
    if (func_021F9824((void *)func_021F86C4()) == 0) return;
    if (((GlobalFlags *)(p + 0x510))->disabled) return;
    if (MCSS_GetStopCellNum(*(void **)(e + off)) == 0xff) {
        *(u32 *)(p + 0x54 + off) |= 0x800;
        return;
    }
    n = ((Flags_02201098 *)(p + 0x54 + off))->count;
    ((Flags_02201098 *)(p + 0x54 + off))->count = n - 1;
    draw = func_0203F0A8();
    if ((u32)(((u64)draw * n) >> 32) != 0) return;
    ((Flags_02201098 *)(p + 0x54 + off))->count = 3;
    q = func_02030734((u16)((((struct Obj13608 *)p)->f540 & 0x7fff) | 0x8000), 12, 1, d_0220AE7C, 0xd5e);
    q[1] = i;
    if (MCSS_GetAnimSeqNum(*(void **)(e + off)) > 1) MCSS_SetAnimeIndex(*(void **)(e + off), 1);
    *(void **)(p + off + 0x30) = func_02030DA8(((struct Obj13608 *)p)->f0, func_02201304, q, 0);
}








/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): two unlabelled arm9 Thumb leaves (the integrator's; no witness outside this range).
 *   Every concrete byte matches; only the two bl relocation sites stay wildcarded.
 *   Verified C (match.py one --arm9 no --region, --thumb, dsi/1.1p1 -O4,p), both EXACT:
 *
 *     typedef unsigned char u8;
 *     u8 MCSS_GetStopCellNum(char *p)              // 0x02015EF4, 6 bytes
 *     {
 *         return **(u8 **)(p + 0x30);
 *     }
 *     u8 MCSS_GetStopCellIndex(char *p, int i)       // 0x02015EFC, 8 bytes
 *     {
 *         return (*(u8 **)(p + 0x30) + i)[2];  // `[i + 2]` is 5 bytes out
 *     }
 *
 * lever: the first test reads the row through the indexed base (`base[idx].h`), the loop
 *   through `e = &base[idx]` inside the loop body; a shared `base + off` char cast is CSE'd
 *   into one register and comes out 8 bytes short. `idx == -1` (u16 against int -1) is not
 *   folded: it keeps the movs/mvns pair. The two `v = 1` arms cross-jump only when the
 *   found test is `if (found == 0) v = 0; else v = 1;`.
 */
int func_02201810(u32 flags, int a, int *out, int key)
{
    Row *base = (Row *)func_021F8694();
    u16 idx = flags;
    int found;
    int n;
    int i;
    int v;

    if (idx == -1)
        return 0;
    if (base[idx].h == 0)
        return 0;
    if (flags & 0x80000000) {
        found = 0;
        n = MCSS_GetStopCellNum(base[idx].h);
        for (i = 0; i < n; i++) {
            Row *e = &base[idx];

            if (key == MCSS_GetStopCellIndex(e->h, i))
                found = 1;
        }
        if (found == 0)
            v = 0;
        else
            v = 1;
    } else {
        v = 1;
    }
    out[3] = v;
    return 1;
}









void func_02201894(int i)
{
    *(int *)((char *)func_021F8694() + i * 0x5c + 0x4c) = 0;
}









void func_022018A8(Unit_v1098 *u, Vec3_vF228 *out, int i)
{
    const Vec3_vF228 *t = (const Vec3_vF228 *)u;

    switch (i) {
    case 0:
    case 1:
        t = &d_0220A050[i];
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        if (u->flags.b1)
            t = &d_0220A1A0[i - 2];
        else if (u->flags.b0)
            t = &d_0220A158[i - 2];
        else
            t = &d_0220A080[i - 2];
        break;
    case 6:
    case 7:
        if (u->flags.b1)
            t = &d_0220A1A0[i - 2];
        else
            t = &d_0220A158[i - 2];
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        t = &d_0220A110[i - 8];
        break;
    }
    out->x = t->x;
    out->y = t->y;
    out->z = t->z;
}









int func_02201934(Unit_v1098 *u, int i, int mode)
{
    if (mode == 0) {
        switch (i) {
        case 0:
        case 1:
            return d_02209FC8[i];
        case 2:
        case 3:
        case 4:
        case 5:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            if (u->flags.b0)
                return d_0220A038[i - 2];
            return d_02209FD0[i - 2];
        case 6:
        case 7:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            return d_0220A038[i - 2];
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            return d_0220A020[i - 8];
        }
    } else {
        if (i < 8) {
            if (i & 1)
                return 0x10000;
            return 0x20000;
        }
        return 0x10000;
    }
}









int func_022019F4(char *p, int key)
{
    int i;

    for (i = 0; i < 14; i++) {
        char *e = p + i * 0x5c;

        if (((struct Obj12236 *)e)->f8 != 0 && key == ((struct Obj12236 *)e)->f50)
            return i;
    }
    return -1;
}









/*
 * lever: `(b & 1) == e->flag` written inline in the condition; a hoisted local `f = b & 1` costs a different register order.
 */
int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3)
{
    int found = 0;
    unsigned i;

    for (i = 0; i < 0x30; i++) {
        const Ent_02201894 *e = (const Ent_02201894 *)(d_0220A1E8 + i * 8);
        unsigned o = i * 8;

        if (a == e->key && (b & 1) == e->flag) {
            o1[0] = *(const s16_02201894 *)(d_0220A1EA + o);
            o1[1] = 0;
            o1[2] = *(const s16_02201894 *)(d_0220A1EC + o);
            *o2 = *(const u16 *)(d_0220A1EE + o);
            *o3 = e->hi;
            found = 1;
            break;
        }
    }
    return found;
}









Res_02201894 *func_02201A8C(void *owner, u16 heap)
{
    Res_02201894 *r = func_02030734(heap, 0x84, 1, d_0220AE88, 0x4f);
    r->owner = owner;
    r->heap = heap;
    r->h = CLACT_CreateUnit(7, 0, heap);
    return r;
}








void func_02201AC4(Res_02201AC4 *r)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (r->e[i].h8 != 0)
            func_02201CA4((Res_02201B20 *)((struct Res *)r), i);
    }
    CLACT_DeleteUnit(r->h);
    func_020307B0(r);
}








void func_02201AF0(void *a0)
{
    CLACT_DrawSystem();
}






int func_02201AF8(int a, int b, int c, short d, short e, int f, int g)
{
    return func_02201B20((char *)a, b, c, c + 1, c + 2, c + 3, d, e, f, g);
}






int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16_02201B20 x, s16_02201B20 y, u32 e, u32 f)
{
    Config cfg = d_0220A368;
    void *archive = func_020490F4(archiveId, (u16)((((struct Obj03216 *)p)->f80 & 0x7fff) | 0x8000));
    int i, off;
    void *slots;
    u32 pal;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 16 + 8) == 0) break;
    }
    off = i * 16;
    *(int *)(p + 12 + off) = CLACT_RegisterCharacter(archive, a, 0, 0, ((struct Obj03216 *)p)->f80);
    *(int *)(p + 16 + off) = CLACT_RegisterPaletteCompressed(archive, b, 0, (u16)(i * 32 + 0x140), ((struct Obj03216 *)p)->f80);
    *(int *)(p + 20 + off) = CLACT_RegisterCellAnim(archive, c, d, ((struct Obj03216 *)p)->f80);
    slots = (void *)func_021F86E0();
    pal = CLACT_GetPaletteVramAddress(*(int *)(p + 16 + off), 0);
    PALANM_LoadArcPaletteToSlot(slots, archiveId, b, ((struct Obj03216 *)p)->f80, 2, 32, (pal & 0x3ff) >> 1);
    cfg.x = x;
    cfg.y = y;
    if (e == 0 && f == 0) {
        *(u32 *)(p + 8 + off) = (u32)CLACT_CreateActor((void *)((struct Obj03216 *)p)->f4, *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), &cfg, 0, ((struct Obj03216 *)p)->f80);
    } else {
        cfg.a = e;
        cfg.b = f;
        *(u32 *)(p + 8 + off) = (u32)CLACT_CreateAffineActor(((struct Obj03216 *)p)->f4, *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), (u32)(&cfg), 0, ((struct Obj03216 *)p)->f80);
    }
    func_0204B92C((struct Obj *)*(u32 *)(p + 8 + off), 1);
    ARC_TOOL_DeleteHandle(archive);
    return i;
}








void func_02201CA4(Res_02201B20 *r, int i)
{
    CLACT_ReleaseCharacter((u32)r->e[i].hc);
    CLACT_ReleasePalette((u32)r->e[i].h10);
    CLACT_ReleaseCellAnim((u32)r->e[i].h14);
    CLACT_DeleteActor(r->e[i].h8);
    r->e[i].h8 = 0;
}








void func_02201CD0(char *o, int idx, int c, s16_02201B20 *p, int s1, int s2, int s3)
{
    Vec_v1B20 b;
    Vec_v1B20 a;
    s16_02201B20 t[2];

    a.x = p[0] << 12;
    a.y = p[1] << 12;
    a.z = 0;
    CLACT_GetActorSurfacePos(*(void **)(o + idx * 16 + 8), (struct PtS *)t, 0);
    b.x = t[0] << 12;
    b.y = t[1] << 12;
    b.z = 0;
    if (c == 1) {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
    }
    func_02201E04((char *)o, idx, c, (Vec *)&b, (Vec *)&a, s1, s2, s3, func_02201F98, func_02201FD8);
    ((struct Obj07895 *)o)->f78 |= 1 << idx;
}








/*
 * lever: a brace-initialised Vec_v1B20 local compiles to an @N rodata template; three field stores do not.
 */
/*
 * lever: a brace-initialised Vec local compiles to an @N rodata template; three field stores do not.
 */
void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3)
{
    Vec_v1B20 v;

    v.x = 0x1000;
    v.y = 0x1000;
    v.z = 0x1000;

    func_02201E04((char *)o, idx, c, (Vec *)&v, (Vec *)d, s1, s2, s3, func_02201FF4, func_0220203C);
    ((struct Obj07895 *)o)->f7C |= 1 << idx;
}















u32 func_02201DA0(char *p, int i, int v)
{
    return CLACT_SetActorAnimSeq(*(void **)(p + i * 16 + 8), (u16)v);
}















void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d)
{
    u16 m = 1 << (((u32)CLACT_GetPaletteVramAddress((u32)(*(void **)(base + idx * 16 + 0x10)), (int)0) & 0x3FF) >> 5);
    void *p = (void *)func_021F86E0();

    PALANM_RequestFade(p, 4, m, step, b, c, d, func_021F86D4());
}














static inline int Round(int x)
{
    if (x > 0) return _ffix(_fadd(0.5f, _fflt(x << 12)));
    else return _ffix(_fsub(_fflt(x << 12), 0.5f));
}














void func_02201E04(char *o, int idx, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                   void (*f1)(void *, void *), void (*f2)(void *))
{
    Job *p;
    p = func_02030734((u16)((((struct Obj07895 *)o)->f80 & 0x7fff) | 0x8000), 0x50, 0, d_0220AE88, 0x197);
    p->owner = o;
    p->idx = idx;
    p->start.x = v->x;
    p->start.y = v->y;
    p->start.z = v->z;
    p->mode = mode;
    p->n1 = s1;
    p->n2 = s1;
    p->zero = 0;
    p->s2 = s2;
    p->s3 = s3 * 2;
    p->a.x = v->x;
    p->a.y = v->y;
    p->a.z = v->z;
    p->b.x = w->x;
    p->b.y = w->y;
    p->b.z = w->z;
    switch (mode) {
    case 1:
        func_021F918C((const VecFx32_021F8F30 *)(&p->a), (const VecFx32_021F8F30 *)w, (VecFx32_021F8F30 *)(&p->delta), Round(s1));
        break;
    case 3:
        p->n2 *= 2;
        p->s3 *= 2;
    case 2:
        p->delta.x = func_0207C768(w->x, Round(s1));
        p->delta.y = func_0207C768(w->y, Round(s1));
        p->delta.z = func_0207C768(w->z, Round(s1));
        break;
    case 0:
    default:
        break;
    }
    func_021F896C(func_02030DA8(((struct Obj07895 *)o)->f0, f1, p, 0), f2, 0);
}















void func_02201F98(void *a, void *b)
{
    Obj_02201DA0 *o = (Obj_02201DA0 *)b;
    Ent_02201DA0 *t = o->tbl;
    int r = func_021F9260((Mover_v8204 *)o->mover, (VecFx32_021F8F30 *)(&o->x));
    short v[2];

    v[0] = o->x >> 12;
    v[1] = o->y >> 12;
    func_0204B404((struct Obj_02201DA0 *)(t[o->idx].h), (const struct Vec2 *)v, 0);
    if (r == 1)
        func_021F89BC(a);
}















void func_02201FD8(void *h)
{
    int *q = (int *)TCBL_IsDeletePending(h);
    char *p = (char *)q[0];
    ((struct Obj21735 *)p)->f78 &= (1 << q[4]) ^ -1;
}















void func_02201FF4(void *a, void *b)
{
    Obj_02201DA0 *o = (Obj_02201DA0 *)b;
    Ent_02201DA0 *t = o->tbl;
    int r = func_021F9260((Mover_v8204 *)o->mover, (VecFx32_021F8F30 *)(&o->x));
    int v[2];

    v[0] = o->x;
    v[1] = o->y;
    CLACT_SetActorAffineMode(t[o->idx].h, 1);
    CLACT_SetActorScale((struct Obj_02201DA0 *)(t[o->idx].h), (struct Pair_02201B20 *)v);
    if (r == 1)
        func_021F89BC(a);
}















void func_0220203C(void *h)
{
    int *q = (int *)TCBL_IsDeletePending(h);
    char *p = (char *)q[0];
    ((struct Obj21736 *)p)->f7C &= (1 << q[4]) ^ -1;
}















struct Obj_02201DA0 *func_02202058(int a, int b, int c, int d, int e, u16 k)
{
    return (struct Obj_02201DA0 *)(struct Obj_v1DA0 *)func_022020A0(a, b, 0, c, d, e, 0, 0, k);
}














void func_0220207C(int a, int b, int c, int d, int e, int f, int g, u16 k)
{
    func_022020A0(a, b, c, d, e, f, g, 1, k);
}














Obj_022020A0 *func_022020A0(int a, int b, int c, int d, int e, int f, int g, int h, u16 heap)
{
    Obj_022020A0 *p;
    Res_02201DA0 *r;
    int i;

    p = func_02030734(heap, 0x2e0, 1, d_0220AEB0, 0x39a);
    p->heap = heap;
    p->h4 = func_02030734(p->heap, func_02030CB0(8), 1, d_0220AEB0, 0x39e);
    p->h0 = func_02030CBC(8, p->h4);
    p->a4c = a;
    p->a224 = e;
    p->a50 = b;
    p->a54 = c;
    p->a274 = f;
    p->f68.k = 15;
    p->a23c = h;
    p->a64 = d;
    p->b104[0] = -1;
    p->b104[1] = -1;
    p->b104[2] = -1;
    p->b104[3] = -1;
    p->b104[4] = -1;
    p->b1bc = -1;
    p->b1c0 = -1;
    p->b1f0 = -1;
    p->b1f4 = -1;
    for (i = 0; i < 3; i++) {
        p->b1b0[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        p->b1e0[i] = -1;
    }
    p->a5c = (int)func_02045B38(0, 2, 12, p->heap);
    p->a70 = -1;
    func_02202248((char *)p);
    r = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x3cc);
    r->owner = p;
    r->v = g;
    func_0220684C((char *)p, (int)func_02030DA8(p->h0, (void ( *)(void *, void *))(func_02204BAC), r, 0), 0);
    return p;
}














void func_022021F4(Obj_022021F4 *p)
{
    if (p == 0)
        return;
    func_022068E8((char *)p);
    func_022023D0((char *)p);
    MSGDATA_Delete(p->h5c);
    if (p->h60 != 0)
        func_02209B30(p->h60);
    func_02030DA4(p->h0);
    func_020307B0(p->h4);
    func_020307B0(p);
}














void func_02202228(void **p)
{
    INFOWIN_Update(func_02030D28((struct Ctx *)(*p)));
}













void func_02202238(void *unused, void *arg)
{
    void **p = arg;

    INFOWIN_Update(func_02030D28((struct Ctx *)(*p)));
}












void func_02202248(char *p)
{
    func_0203FC6C((const struct BgVramReq *)d_0220A3D4, 1);
    ((struct Obj00083 *)p)->f48 = func_020490F4(0xb, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1F8 = (int)CLACT_CreateUnit(4, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f118 = (int)CLACT_CreateUnit(0xc, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f17C = (int)CLACT_CreateUnit(6, 0, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1C4 = (int)CLACT_CreateUnit(3, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f20C = (int)CLACT_CreateUnit(2, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f218 = (int)CLACT_CreateUnit(1, 1, ((struct Obj00083 *)p)->f240);
    func_0220255C(p);
    func_022033F4((Main_022033F4 *)((struct Main *)p));
    func_02205E80(p);
    ((struct Obj00083 *)p)->f228 = (void *)BMP_WIN_Create(6, 0, 4, 32, 12, 13, 1);
    ((struct Obj00083 *)p)->f22C = func_02045770(((struct Obj00083 *)p)->f228);
    ((struct Obj00083 *)p)->f230 = (void *)BMP_WIN_Create(6, 3, 22, 3, 2, 13, 1);
    ((struct Obj00083 *)p)->f234 = func_02045770(((struct Obj00083 *)p)->f230);
    BMP_Clear(((struct Obj00083 *)p)->f22C, 0);
    BMP_Clear(((struct Obj00083 *)p)->f234, 0);
    BMP_WIN_TransferChars(((struct Obj00083 *)p)->f228);
    BMP_WIN_TransferChars(((struct Obj00083 *)p)->f230);
    BMP_WIN_MakeScreen(((struct Obj00083 *)p)->f228);
    BMP_WIN_MakeScreen(((struct Obj00083 *)p)->f230);
    func_020409B4(6);
    INFOWIN_Init(6, 15, ((struct Obj00083 *)p)->f4C, ((struct Obj00083 *)p)->f240);
    func_02040588(6, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00083 *)p)->f240);
    PALANM_CopyHwPaletteToSlot(((struct Obj00083 *)p)->f64, 3, 0xe0, 0x20);
    ((struct Obj00083 *)p)->f68 |= 0x2000;
    if (((struct Obj00083 *)p)->f23C == 1)
        ((struct Obj00083 *)p)->f238 = func_02030DA8(func_021F86D4(), func_02202238, p, 0);
    func_0220270C(p, 0, 0);
}












void func_022023D0(char *p)
{
    int i;
    func_02205F64((W_02205F64 *)p);
    func_02205E30(p);
    func_02205F40((W_02205F40 *)p);
    func_02205AB8(p);
    func_02205D34((W_022053DC *)p);
    DROP_ID(0x104, CLACT_ReleaseCharacter);
    DROP_ID(0x108, CLACT_ReleasePalette);
    DROP_ID(0x10c, CLACT_ReleaseCellAnim);
    DROP_ID(0x110, CLACT_ReleaseCharacter);
    DROP_ID(0x114, CLACT_ReleaseCellAnim);
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x1e0) != -1) {
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x1e0));
            *(int *)(p + i * 4 + 0x1e0) = -1;
        }
    }
    DROP_ID(0x1f4, CLACT_ReleaseCellAnim);
    DROP_ID(0x1f0, CLACT_ReleasePalette);
    DROP_ZERO_ID(0x1f8, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x118, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x17c, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x1c4, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x20c, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x218, CLACT_DeleteUnit);
    DROP_PTR(0x228, func_020452E8);
    DROP_PTR(0x230, func_020452E8);
    INFOWIN_Exit();
    func_022025B4();
    DROP_PTR(0x238, func_02030EAC);
    if (*(int *)(p + 0x48) != 0) { ARC_TOOL_DeleteHandle((void *)*(int *)(p + 0x48)); *(int *)(p + 0x48) = 0; }
    ((struct Obj01049 *)p)->f58 = 0;
}













void func_0220255C(void *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0203FCA0((u8)(i + 4), (const struct BgTemplate *)(&d_0220A8BC[i]), (u8)d_0220A8BC[i].f20);
        func_0204152C((u8)(i + 4), (int)0x3ff);
        func_02204960((Main_02204960 *)p, i + 4, 0, 0, 2, 2, 2, 2);
    }
}












void func_022025B4(void)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_02040588((u8)(i + 4), (int)0);
        func_020403F4((u8)(i + 4));
    }
}












/*
 * lever: the flag test is two whole PALANM_RequestFade calls, one per arm, differing only
 *   in the fifth argument (0 / 0xC). The compiler cross-jumps them after the [sp] store,
 *   hoists the shared `ldr r2, =0xFFFF` above the branch and pools the three zeros of the
 *   two calls in r6 before the alloc call. A u8 local set in an if/else (or an enum
 *   zero) gave the same size with flag and the zero in each other's registers
 *   (docs/notes/pkt_ov094_022025D8.c.txt).
 */
void func_022025D8(char *o, int flag)
{
    int *p;

    p = func_02030734((u16)((((struct Obj03718 *)o)->f240 & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x4F7);
    if (flag == 1)
        PALANM_RequestFade(((struct Obj03718 *)o)->f64, 0xA, 0xFFFF, 1, 0, 0x10, 0, ((struct Obj03718 *)o)->f0);
    else
        PALANM_RequestFade(((struct Obj03718 *)o)->f64, 0xA, 0xFFFF, 1, 0xC, 0x10, 0, ((struct Obj03718 *)o)->f0);
    ((struct Obj03718 *)o)->f68 = (((struct Obj03718 *)o)->f68 & 0xFFFE7FFF) | 0x8000;
    p[0] = (int)o;
    func_0220684C(o, (int)func_02030DA8(((struct Obj03718 *)o)->f0, (void ( *)(void *, void *))(func_02204A3C), p, 0), (int)func_02204A70);
}











/*
 * note: the two zero arguments of FADE_Start sit in r6 because the call is written in
 *   both arms of the if (the arms are cross-jumped and the shared zero is hoisted).
 * trailing: 022026FC..0220270C is an unlabelled getter (mode bits 15..16 of +0x68 != 0).
 */
void func_0220266C(Obj_0220266C *p)
{
    Obj_0220266C **q;
    q = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x50c);
    if (func_0207D55C((volatile u16 *)0x0400106c) <= 0)
        FADE_Start(2, 0x10, 0, 0);
    else
        FADE_Start(8, 0x10, 0, 0);
    func_02202248((char *)p);
    p->f68.mode = 2;
    *q = p;
    func_0220684C((char *)p, (int)func_02030DA8(p->h0, (void ( *)(void *, void *))(func_02204A3C), q, 0), (int)func_02204A70);
}











/*
 * notes:    tests a 2-bit field at bits 15..16 of the word at +0x68, returns 1 if nonzero. Witness for calls in ov098 func_021B6578 (2026-10-05, lane W-B).
 */
int func_022026FC(struct W *p)
{
    if (p->f) return 1;
    return 0;
}










void func_0220270C(char *s, int mode, void *arg)
{
    Task_v1DA0 *t;
    void *w;
    int i;
    int j;

    func_022056B4((Main_022053DC *)((struct Main *)s));
    F68_(s).b23 = 0;
    F6C_(s).b0 = 1;
    switch (mode) {
    case 0:
        S_INT(0x70) = -1;
        if (S_INT(0x58) == 0) {
            func_022043C0((Main_022043C0 *)((struct Main *)s), 0x3000, 0x3000, 0, 0x98);
            func_02204960((Main_02204960 *)((struct Main *)s), -1, 0, 0, 0, 0, 2, 1);
            PALANM_RequestFade(S_PTR(0x64), 2, 3, 1, 12, 12, 0x842, S_PTR(0));
        } else {
            t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x549);
            F68_(s).b0 = 1;
            t->s = s;
            if (S_INT(0x23c) == 1)
                func_021F8A78();
            func_02205E30(s);
            func_02205AB8(s);
            if (S_INT(0x58) == 1 || S_INT(0x58) == 4) {
                func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203BC0, t, 1), (int)func_022043AC);
            } else {
                t->f20 = S_INT(0x58);
                func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203C2C, t, 1), (int)func_022043AC);
            }
            PALANM_RequestFadeOverwrite(S_PTR(0x64), 2, 3, 1, 0, 12, 0x842, S_PTR(0));
            if (CLACT_GetUnitDrawEnable(S_PTR(0x17c)) != 0) {
                F68_(s).b5 = 0;
                F68_(s).b9 = 15;
                F68_(s).b13 = 1;
                func_0204B22C(S_PTR(0x17c), 0);
            }
        }
        break;
    case 1: {
        Arg1 *a = arg;
        Task_v1DA0 *t1;
        t1 = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x570);
        S_INT(0x278) = a->fbc;
        func_022067E8(s);
        func_021F8A40(2);
        if (a->fbc >= 2)
            a->fbc = (a->fbc - 2) / 2;
        F68_(s).b0 = 1;
        F68_(s).b4 = a->f90;
        t1->s = s;
        t1->f8 = a->fbc;
        S_INT(0x27c) = a->fbc;
        if (S_INT(0x58) == 0)
            func_0220680C(s);
        for (i = 0; i < 6; i++) {
            ((T12 *)(s + 0x74))[i] = a->a[i];
            ((T12 *)(s + 0xbc))[i] = a->b[i];
        }
        for (j = 0; j < 4; j++)
            s[0x25a + j] = 1;
        s[0x25b] = func_021F8914();
        func_02205AB8(s);
        func_022057CC((Main_022057CC *)((struct Main *)s), (Info_v53DC *)((struct Info *)a));
        func_02205B90(s, a->bc5);
        t1->fc = func_02206A7C(s);
        func_02206728(s, (char *)a);
        if (S_INT(0x58) == 2 || S_INT(0x58) == 5) {
            func_02205B80(s, 0);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203978, t1, 1), (int)func_022043AC);
        } else {
            func_02205D58(s, 0);
            if (a->f94 != 0)
                func_02205D58(s, 1);
            F68_(s).b14 = a->f94;
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_022035C0, t1, 1), (int)func_022043AC);
        }
        break;
    }
    case 2: {
        Arg2 *a = arg;
        Task_v1DA0 *t2;
        t2 = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5bd);
        func_02204CC0((Work_v3E30 *)((struct Work_02201B20 *)s), (const Slots *)((const struct Slots *)a));
        F68_(s).b0 = 1;
        t2->s = s;
        t2->f8 = a->f10;
        S_INT(0x280) = a->f14;
        t2->fc = func_02206A7C(s);
        for (j = 0; j < 4; j++)
            ((u16 *)(s + 0x26c))[j] = a->h[j];
        if (S_INT(0x23c) == 1 && (S_INT(0x50) == 1 || S_INT(0x50) == 2)) {
            func_021F8AC0(2);
            func_021F7998(0x244);
        }
        if (S_INT(0x58) == 3) {
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203B08, t2, 1), (int)func_022043AC);
        } else if (S_INT(0x58) == 0) {
            func_02205D58(s, 0);
            if (F68_(s).b14)
                func_02205D58(s, 1);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_022036C4, t2, 1), (int)func_022043AC);
        } else {
            func_02205AB8(s);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203880, t2, 1), (int)func_022043AC);
        }
        break;
    }
    case 3:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5ec);
        func_022050F0(s, (Out *)((struct Out *)t), (const Info_v3E30 *)arg);
        F68_(s).b0 = 1;
        t->s = s;
        t->f8 = ((u8 *)arg)[0x48];
        func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203A78, t, 1), (int)func_022043AC);
        break;
    case 4:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x5f8);
        func_02205340((Main_v3E30 *)((struct Main *)s), arg);
        F68_(s).b0 = 1;
        t->s = s;
        F6C_(s).b0 = ((int *)arg)[2];
        func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203D40, t, 1), (int)func_022043AC);
        break;
    case 5: {
        Arg5 *a = arg;
        int k;
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x605);
        if (S_INT(0x58) != 0) {
            F68_(s).b17 = 0;
            F68_(s).b19 = 0;
        }
        for (i = 0; i < 3; i++) {
            ((S5 *)s)->a[i] = a->a[i];
            for (k = 0; k < 4; k++)
                ((S5 *)s)->b[i][k] = a->b[i][k];
        }
        func_022053DC(s);
        F68_(s).b0 = 1;
        t->s = s;
        if (S_INT(0x58) == 0) {
            func_02205D58(s, 0);
            if (F68_(s).b14)
                func_02205D58(s, 1);
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203E30, t, 1), (int)func_022043AC);
        } else {
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_022041E0, t, 1), (int)func_022043AC);
        }
        break;
    }
    case 6: {
        Arg2 *a = arg;
        w = 0;
        for (j = 0; j < 3; j++)
            s[0x25a + j] = 1;
        func_0220558C(s, (const int *)a);
        switch (a->fc) {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            GF_FONT_SetTextColor(1, 2, 0);
            w = func_02045EC0(S_PTR(0x5c), a->fc + 8);
            break;
        }
        if (S_INT(0x58) == 0) {
            t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x65f);
            F68_(s).b0 = 1;
            t->s = s;
            if (a->fc == 0) {
                t->f10 = 0;
                t->f14 = 0x100;
            } else {
                t->f10 = 0x100;
                t->f14 = 0;
            }
            t->f1c = w;
            func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_02203FDC, t, 1), (int)func_022043AC);
        } else {
            if (a->fc == 0)
                func_02204960((Main_02204960 *)((struct Main *)s), 4, 0, 0x100, 2, 2, 2, 2);
            else
                func_02204960((Main_02204960 *)((struct Main *)s), 4, 0x100, 0, 2, 2, 2, 2);
            if (w != 0) {
                PRINTSYS_Print((void *)S_INT(0x22c), 0x18, 0x38, w, (void *)S_INT(0x224));
                STRBUF_Delete(w);
            }
            BMP_WIN_MakeScreen(S_PTR(0x228));
            func_020409B4(6);
            BMP_WIN_TransferChars(S_PTR(0x228));
        }
        break;
    }
    case 7:
        t = func_02030734(HEAP(s), 0x24, 1, d_0220AEB0, 0x68c);
        F68_(s).b0 = 1;
        t->s = s;
        func_0220684C(s, (int)func_02030DA8(S_PTR(0), func_022040FC, t, 1), (int)func_022043AC);
        s[0x25a] = 1;
        s[0x25b] = 1;
        break;
    }
    S_INT(0x58) = mode;
}










int func_02202DC4(Obj_v1DA0 *o, Cmd *c, int x)
{
    int r;
    int k;
    u32 keys;
    int ret;
    int i;
    int cnt;
    int idx;
    Ent_v1DA0 *e;
    int mode;

    if (o->busy || PALANM_GetFadeRequestBits((const char *)o->f64) != 0 || o->lock)
        return -1;
    ret = o->pending;
    if (ret != -1) {
        o->flag = 0;
        o->pending = -1;
        return ret;
    }
    if (func_020362DC() & 8) {
        if ((u32)(o->mode - 1) <= 2)
            func_021F8168();
    }
    if (o->mode == 6) {
        r = TOUCHPANEL_HitTrg(c->key);
        if (r != -1) {
            if (o->en[r] == 0)
                r = -1;
            else if (r == 2)
                func_02206B58((char *)o);
            else
                func_02206B30((char *)o);
        } else {
            r = func_0220648C((char *)o);
        }
        if (r != -1)
            r = func_02206578((char *)o, r, c->vals[r]);
        return r;
    }

    k = TOUCHPANEL_HitTrg(c->key);
    r = func_02206140((W_02206140 *)o, (const Ctx_v53DC *)c, (s8 (*)[12])x, (u8 *)0, k, o->f280);
    if (r != -1) {
        keys = func_0203630C();
        if (o->en[r] == 0 && (!(keys & 0x200) || o->mode != 2)) {
            if (o->en2[r] != 0 && o->mode == 2)
                func_02206BAC((char *)o);
            r = -1;
        } else if (r < 4 && (keys & 0x200) && o->mode == 2 && o->f280 == 1) {
            r = -1;
        } else if (r < 4 && (keys & 0x200) && o->mode == 2 && o->en2[r] == 0) {
            r = -1;
        } else if (k != -1) {
            if (func_02206908((char *)o, (char *)c, r) == 0 && !o->flag) {
                func_02206B30((char *)o);
                mode = o->mode;
                switch (mode) {
                case 1:
                case 2:
                case 5:
                    o->slot[o->cur][mode] = r;
                    break;
                case 3:
                    idx = 0;
                    if (o->f50 != 2)
                        cnt = d_0689E090[o->cur][o->sel];
                    else
                        cnt = d_0689E0B0[o->cur][o->sel];
                    if (o->f50 != 2)
                        e = d_0689E560[o->cur][o->sel];
                    else
                        e = d_0689E704[o->cur][o->sel];
                    for (i = 0; i < cnt; i++) {
                        if (r == e[i].id) {
                            idx = i;
                            break;
                        }
                    }
                    o->slot[o->cur][mode] = (o->slot[o->cur][2] << 4) | idx;
                    break;
                }
            } else {
                func_02206B58((char *)o);
            }
        }
    }
    if (r != -1)
        r = func_02206578((char *)o, r, c->vals[r]);
    return r;
}









int func_02203040(Main_02203040 *m)
{
    int r = 0;
    Tbl_v1DA0 t;

    switch (m->a) {
    case 0:
        t = d_0220A598;
        if (m->f60 == 0)
            m->f60 = func_02209A7C(m->f64, 0xb, m->h240);
        if (func_02209B60(m->f60, t.p[m->b].x, t.p[m->b].y, 2, 7, 0x10) != 0) {
            m->a = m->a + 1;
            m->b = m->b + 1;
        }
        break;
    case 1:
        r = func_02209C2C(m->f60);
        if (r == 1)
            func_02206B30((char *)m);
        break;
    }
    return r;
}









int func_022030F0(Main_022030F0 *m, u8 *key, int *out)
{
    int i;
    int a;
    u32 held;
    int r;

    if (m->b0 || PALANM_GetFadeRequestBits((const char *)m->f64) != 0 || m->b31)
        return 0;
    if (func_020362DC() & 8)
        func_021F8168();
    if (m->f70 != -1) {
        i = m->f70 & 0xFFFF7FFF;
        if (i < 5) {
            if (i < 4 && m->f220 == 1)
                m->f70 = 7;
            *out = m->f70;
            *key = sec_0220A380.key[m->mode];
            m->f70 = -1;
            m->f6c &= ~2;
            PALANM_RequestFadeOverwrite((void *)m->f64, 2, 0x3e00, 0, 0, 0, 0, m->owner);
            PALANM_RequestFadeOverwrite((void *)m->f64, 8, 0x700, 0, 0, 0, 0, m->owner);
            return 1;
        }
        m->f5 = 0;
        m->tbl[m->f27c][m->f58] = 0;
        m->f6c &= ~2;
        func_02206B74((char *)m);
        func_02204B0C((Main_02204B0C *)m, i);
        m->f70 = -1;
        return 0;
    }
    if (m->f220 == 1) {
        a = TOUCHPANEL_HitTrg(sec_0220A380.db.a);
        i = func_02206140((W_02206140 *)((Obj_v1DA0 *)m), (const Ctx_v53DC *)((Cmd *)(&sec_0220A380.db)), (s8 (*)[12])((int)(d_0220AE98[m->mode])), (u8 *)((int)0), a, BTL_POKEPARAM_IsTransformed(m->f2a4[m->mode]));
    } else {
        a = TOUCHPANEL_HitTrg(sec_0220A380.da.a);
        i = func_02206140((W_02206140 *)((Obj_v1DA0 *)m), (const Ctx_v53DC *)((Cmd *)(&sec_0220A380.da)), (s8 (*)[12])((int)(d_0220AEA4[m->mode])), (u8 *)((int)d_0220A380), a, BTL_POKEPARAM_IsTransformed(m->f2a4[m->mode]));
    }
    if (i != -1) {
        held = func_0203630C();
        if (m->b25a[i] == 0 && !(held & 0x200)) {
            if (m->b262[i] != 0)
                func_02206BAC((char *)m);
            i = -1;
        } else if (i > 4 && m->b25a[i] == 0) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && (BTL_POKEPARAM_IsTransformed(m->f2a4[m->mode]) == 1 || m->f220 == 1)) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && m->b262[i] == 0) {
            i = -1;
        }
    }
    if (i != -1) {
        if (m->f220 == 1) {
            r = func_02206908((char *)m, (char *)(&sec_0220A380.db), i);
            if (r == 0 && !(m->f6c << 30 >> 31)) {
                m->tbl[m->f27c][m->f58] = i;
                func_02206B90((char *)m);
            } else if (r == 1 && !(m->f6c << 30 >> 31)) {
                func_02206B58((char *)m);
            }
            i = func_02206578((char *)m, i, sec_0220A380.db.c[i]);
        } else {
            r = func_02206908((char *)m, (char *)(&sec_0220A380.da), i);
            if (r == 0 && !(m->f6c << 30 >> 31)) {
                m->tbl[m->f27c][m->f58] = i;
                func_02206B90((char *)m);
            } else if (r == 1 && !(m->f6c << 30 >> 31)) {
                func_02206B58((char *)m);
            }
            i = func_02206578((char *)m, i, sec_0220A380.da.c[i]);
        }
    }
    if (i != -1)
        return 1;
    return 0;
}







/*
 * trailing: 022033F0..022033F4 is an unlabelled 4-byte getter (ldr r0, [r0, #0x58]; bx lr).
 */
int func_022033CC(Obj *p)
{
    if (p->f68.b0 || PALANM_GetFadeRequestBits(p->h64) != 0 || p->f68.b31)
        return 1;
    return 0;
}








int func_022033F0(int *p)
{
    return p[0x58 / 4];
}




/*
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 at +0072 has no admissible outside witness.
 * Verified C copied from ov029_func_021F0DB4.c's EXACT 8-byte scratch proof:
 * int PALANM_GetDefaultWork(char *p, int i) { return *(int *)(p + i * 0x14); }
 * ARM9 belongs to the integrator. Caller sets r0 to the palette object, r1 to 1.
 */
void func_022033F4(Main_022033F4 *m)
{
    void *arc;
    u32 file;
    int i;

    func_02049658(m->f48, 0x5b, 4, 0, 0, 0, m->heap);
    func_02049658(m->f48, 0x71, 7, 0, 0x8000, 0, m->heap);
    func_020498F4(m->f48, 0x72, 7, 0, 0, 0, m->heap);
    PALANM_LoadHandlePaletteToSlot(m->pal, m->f48, 0x5c, m->heap, 1, 0x1e0, 0);
    if (m->f23c == 1)
        func_02082A60((const void *)(PALANM_GetDefaultWork((char *)func_021F86E0(), 1) + 0x40), m->buf284, 0x20);
    m->h104 = CLACT_RegisterCharacter(m->f48, 0x73, 0, 1, m->heap);
    m->h10c = CLACT_RegisterCellAnim(m->f48, 0x75, 0x76, m->heap);
    m->h108 = CLACT_RegisterPalette(m->f48, 0x74, 1, 0, m->heap);
    PALANM_CopyHwPaletteToSlot(m->pal, 3, (u16)(CLACT_GetPaletteVramAddress(m->h108, 1) >> 1), 0x100);
    m->h110 = CLACT_RegisterCharacter(m->f48, 0x77, 0, 1, m->heap);
    m->h114 = CLACT_RegisterCellAnim(m->f48, 0x78, 0x79, m->heap);
    arc = func_020490F4(func_020275E4(), (u16)((m->heap & 0x7fff) | 0x8000));
    file = func_020275FC(0);
    m->h1f4 = CLACT_RegisterCellAnim(arc, file, func_02027600(0), m->heap);
    m->h1f0 = CLACT_RegisterPalette(arc, func_020275E8(), 1, 0x100, m->heap);
    PALANM_CopyHwPaletteToSlot(m->pal, 3, (u16)(CLACT_GetPaletteVramAddress(m->h1f0, 1) >> 1), 0x60);
    for (i = 0; i < 4; i++)
        m->h1e0[i] = CLACT_RegisterCharacter(arc, func_020275F8(0), 0, 1, m->heap);
    ARC_TOOL_DeleteHandle(arc);
}








/*
 * lever: case 1 and default share the completion arm.
 */
void func_022035C0(void *task, void *arg)
{
    Ctx_022033F4 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        func_02206AF8((char *)c->main);
        func_02204960((Main_02204960 *)((Main_022035C0 *)c->main), 5, 0, 0, 1, 0, 2, 1);
        func_022043C0((Main_022043C0 *)((Main_022035C0 *)c->main), 0x3000, 0x1000, -0x400, 0x98);
        func_022044C0((Main_022044C0 *)((Main_022035C0 *)c->main), 0, 0x1c0, 8, 8);
        func_02206A14((char *)c->main);
        BMP_WIN_MakeScreen(c->main->obj230);
        func_020409B4(6);
        PALANM_RequestFadeOverwrite(c->main->pal, 2, 3, 1, 12, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj230);
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(7, 0);
            func_0220687C((char *)c->main, task);
        }
        break;
    }
}







void func_022036C4(void *task, void *arg)
{
    Ctx_022036C4 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6f, 5, 0, 0, 0, c->main->h240);
        func_02206AF8((char *)c->main);
        func_02204960((Main_02204960 *)((Main_022035C0 *)c->main), 5, 0, 0, 0, 0, 2, 1);
        func_022043C0((Main_022043C0 *)((Main_022035C0 *)c->main), 0x3000, 0x1000, -0x400, 0x98);
        func_020409B4(6);
        PALANM_RequestFadeOverwrite(c->main->pal, 2, 3, 1, 12, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
        if (c->main->st == 0) {
            if (c->main->mode == 2 && c->f8 != 4) {
                func_020498F4((void *)c->main->f48, 0x5e, 4, 0, 0, 0, c->main->h240);
            } else {
                func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
            }
            BMP_WIN_MakeScreen(c->main->obj228);
            func_020409B4(6);
            func_022044C0((Main_022044C0 *)((Main_022035C0 *)c->main), 0x100, 0x1c0, 8, 8);
            func_022045A8((Main_022045A8 *)((Main_022035C0 *)c->main), 0, 0);
            func_02204838((Main_02204838 *)((Main_022035C0 *)c->main), 0);
            func_02204960((Main_02204960 *)((Main_022035C0 *)c->main), -1, 0, 0, 1, 1, 2, 0);
            c->timer = 4;
            c->state++;
        }
        break;
    case 2:
        if (--c->timer == 0) {
            func_02204698((Obj_02204698 *)((struct Obj *)c->main), 0, 0);
            c->state++;
        }
        break;
    case 3:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960((Main_02204960 *)((Main_022035C0 *)c->main), 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, task);
        }
        break;
    }
}










/*
 * trailing: 02203976..02203978 is two-byte alignment padding.
 * lever: case 2 shares its body with default, retaining the dead compare.
 */
void func_02203880(void *task, void *arg)
{
    Ctx_02203880 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        BMP_WIN_MakeScreen(c->main->obj228);
        func_020409B4(6);
        func_022044C0((Main_022044C0 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 0x100, 0x1c0, 8, 8);
        func_022045A8((Main_022045A8 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 0, 0);
        func_02204838((Main_02204838 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 0);
        func_02206A58((char *)c->main);
        func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), -1, 0, 0, 1, 1, 2, 0);
        c->timer = 4;
        c->state++;
        break;
    case 1:
        if (--c->timer == 0) {
            func_02204698((Obj_02204698 *)((struct Obj *)c->main), 0, 0);
            c->state++;
        }
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, task);
        }
        break;
    }
}











void func_02203978(void *task, void *arg)
{
    Ctx_02203978 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        BMP_WIN_MakeScreen(c->main->obj230);
        func_02206A14((char *)c->main);
        func_020409B4(6);
        func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 5, 0, 0xc0, 1, 1, 2, 0);
        c->state++;
        break;
    case 1:
        func_02204698((Obj_02204698 *)((struct Obj *)c->main), 0, 1);
        c->timer = 4;
        c->state++;
        break;
    case 2:
        if (--c->timer == 0) {
            func_022044C0((Main_022044C0 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 0, 0x1c0, 8, 8);
            func_022045A8((Main_022045A8 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 0, 1);
            func_02204838((Main_02204838 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 1);
            c->state++;
        }
        break;
    case 3:
    default:
        if (c->main->st == 0) {
            func_02205B80((char *)c->main, 1);
            BMP_WIN_TransferChars(c->main->obj230);
            func_0220687C((char *)c->main, task);
        }
        break;
    }
}












void func_02203A78(void *a0, void *arg)
{
    Ctx_02203A78 *c = arg;

    int z = 0;

    func_020498F4((void *)c->main->f48, 0x5d, 4, 0, z, z, c->main->h240);
    func_020498F4((void *)c->main->f48, c->f0c, 4, 0x440, 0x380, z, c->main->h240);
    BMP_WIN_MakeScreen(c->main->obj228);
    func_020409B4(6);
    if (c->main->f50 == 2) {
        func_020498F4((void *)c->main->f48, 0x6a, 5, 0, z, z, c->main->h240);
    } else {
        func_020498F4((void *)c->main->f48, 0x69, 5, 0, z, z, c->main->h240);
    }
    BMP_WIN_TransferChars(c->main->obj228);
    func_0220687C((char *)c->main, (void *)a0);
}











void func_02203B08(void *a0, void *arg)
{
    Ctx_02203B08 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 5, 0, 0xc0, 2, 2, 2, 2);
        c->state = c->state + 1;
        break;
    case 1:
        BMP_WIN_MakeScreen(c->main->obj228);
        func_020409B4(6);
        func_020498F4((void *)c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        BMP_WIN_TransferChars(c->main->obj228);
        func_0204B22C(c->main->obj1f8, 1);
        func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 5, 0x100, 0xc0, 2, 2, 2, 2);
        func_0220687C((char *)c->main, (void *)a0);
        break;
    }
}











void func_02203BC0(void *a0, void *arg)
{
    Ctx_02203BC0 *c = arg;

    switch (c->state) {
    case 0:
        func_022043C0((Main_022043C0 *)((Main_022035C0 *)c->main), 0x1000, 0x3000, 0x400, 0xa8);
        c->state = c->state + 1;
        break;
    case 1:
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02040588(7, 1);
        c->state = c->state + 1;
        break;
    case 2:
    default:
        if (c->main->st == 0)
            func_0220687C((char *)c->main, (void *)a0);
        break;
    }
}








void func_02203C2C(void *task, void *arg)
{
    Ctx_02203C2C *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6e, 5, 0, 0, 0, c->main->h240);
        func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 5, 0, 0xc0, 1, 1, 2, 0);
        c->state++;
        break;
    case 1:
        if (c->mode == 2 || c->mode == 5)
            func_02204698((Obj_02204698 *)((struct Obj *)c->main), 0, 1);
        c->state++;
        c->timer = 4;
        break;
    case 2:
        if (--c->timer == 0) {
            func_022045A8((Main_022045A8 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 0, 1);
            c->state++;
        }
        break;
    case 3:
        if (c->main->st == 0) {
            func_022043C0((Main_022043C0 *)((Main_022035C0 *)((Main_02203BC0 *)c->main)), 0x1000, 0x3000, 0x400, 0xa8);
            c->state++;
        }
        break;
    case 4:
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02040588(7, 1);
        c->state++;
        break;
    case 5:
    default:
        if (c->main->st == 0)
            func_0220687C((char *)c->main, task);
        break;
    }
}







void func_02203D40(void *h, void *arg)
{
    Ctx *c = arg;

    switch (c->state) {
    case 0:
        func_02206AF8((char *)c->main);
        func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 5, 0, 0, 0, 0, 2, 1);
        func_022043C0((Main_022043C0 *)((Main_022035C0 *)((Main_02203BC0 *)c->main)), 0x3000, 0x1000, -0x400, 0x98);
        func_02206A58((char *)c->main);
        PALANM_RequestFade(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
        if (c->main->st == 0) {
            func_022045A8((Main_022045A8 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 0, 0);
            func_02040588(5, 1);
            func_02040588(7, 0);
            c->state++;
        }
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            BMP_WIN_MakeScreen(c->main->obj228);
            func_020409B4(6);
            BMP_WIN_TransferChars(c->main->obj228);
            func_02204960((Main_02204960 *)((Main_022035C0 *)((Main_02203880 *)c->main)), 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}












void func_02203E30(void *h, void *arg)
{
    Ctx_02203E30 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6f, 5, 0, 0, 0, c->main->h240);
        func_02206AF8((char *)c->main);
        func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), 5, 0, 0, 0, 0, 2, 1);
        func_022043C0((Main_022043C0 *)((Main_02203E30 *)c->main), 0x3000, 0x1000, -0x400, 0x98);
        func_020409B4(6);
        PALANM_RequestFadeOverwrite(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
        if (c->main->st == 0) {
            func_020498F4((void *)c->main->f48, 0x64, 4, 0, 0, 0, c->main->h240);
            BMP_WIN_MakeScreen(c->main->obj228);
            func_020409B4(6);
            func_022044C0((Main_022044C0 *)((Main_02203E30 *)c->main), d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
            func_022045A8((Main_022045A8 *)((Main_02203E30 *)c->main), 0, 0);
            func_02204838((Main_02204838 *)((Main_02203E30 *)c->main), 0);
            func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), -1, 0, 0, 1, 1, 2, 0);
            c->timer = 4;
            c->state++;
        }
        break;
    case 2:
        if (--c->timer == 0) {
            func_02204698((Obj_02204698 *)((struct Obj_02203E30 *)c->main), 0, 0);
            c->state++;
        }
        break;
    case 3:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}












void func_02203FDC(void *h, void *arg)
{
    Ctx_02203FDC *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x62, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6d, 5, 0, 0, 0, c->main->h240);
        func_02206AF8((char *)c->main);
        func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), 5, 0, 0, 1, 0, 2, 1);
        func_022043C0((Main_022043C0 *)((Main_02203E30 *)c->main), 0x3000, 0x1000, -0x400, 0x98);
        func_022044C0((Main_022044C0 *)((Main_02203E30 *)c->main), 0, 0x1c0, 8, 8);
        PALANM_RequestFade(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
    default:
        if (c->main->st == 0) {
            if (c->obj1c != 0) {
                PRINTSYS_Print(c->main->obj22c, 0x18, 0x38, c->obj1c, c->main->obj224);
                STRBUF_Delete(c->obj1c);
            }
            BMP_WIN_MakeScreen(c->main->obj228);
            func_020409B4(6);
            BMP_WIN_TransferChars(c->main->obj228);
            func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), 4, c->f10, c->f14, 1, 1, 2, 0);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}











void func_022040FC(void *h, void *arg)
{
    Ctx_02203E30 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x63, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6b, 5, 0, 0, 0, c->main->h240);
        func_02206AF8((char *)c->main);
        func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), 5, 0, 0, 1, 0, 2, 1);
        func_022043C0((Main_022043C0 *)((Main_02203E30 *)c->main), 0x3000, 0x1000, -0x400, 0x98);
        func_022044C0((Main_022044C0 *)((Main_02203E30 *)c->main), 0, 0x1c0, 8, 8);
        PALANM_RequestFade(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
    default:
        if (c->main->st == 0) {
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(7, 0);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}










void func_022041E0(void *h, void *arg)
{
    Ctx_022041E0 *c = arg;

    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x64, 4, 0, 0, 0, c->main->h240);
        BMP_WIN_MakeScreen(c->main->obj228);
        func_02206A58((char *)c->main);
        func_020409B4(6);
        func_022044C0((Main_022044C0 *)((Main_02203E30 *)c->main), d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
        func_022045A8((Main_022045A8 *)((Main_02203E30 *)c->main), 0, 0);
        func_02204838((Main_02204838 *)((Main_02203E30 *)c->main), 0);
        func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), -1, 0, 0, 1, 1, 2, 0);
        c->timer = 4;
        c->state++;
        break;
    case 1:
        if (--c->timer == 0) {
            func_02204698((Obj_02204698 *)((struct Obj_02203E30 *)c->main), 0, 0);
            c->state++;
        }
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}










void func_022042E4(void *h, void *arg)
{
    Ctx_022042E4 *c = arg;

    switch (c->state) {
    case 0:
        func_022056B4((Main_022053DC *)((struct Main *)c->main));
        c->state++;
        break;
    case 1:
        func_022053DC((char *)c->main);
        BMP_WIN_MakeScreen(c->main->obj228);
        func_020409B4(6);
        func_022044C0((Main_022044C0 *)((Main_02203E30 *)c->main), d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
        func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), -1, 0, 0, 1, 1, 2, 0);
        c->state++;
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            func_0204B22C(c->main->obj1f8, 1);
            func_02204960((Main_02204960 *)((Main_02203E30 *)c->main), 5, 0x100, 0xc0, 2, 2, 2, 2);
            func_0220687C((char *)c->main, h);
        }
        break;
    }
}











void func_022043AC(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((struct Obj21763 *)p)->f68 &= ~1;
}











void func_022043C0(Main_022043C0 *m, int a1, int a2, int a3, int a4)
{
    Obj_02203E30 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x14, 0, d_0220AEB0, 0xb97);
    o->main = m;
    o->f4 = a1;
    o->f8 = a2;
    o->fc = a3;
    o->f10 = a4;
    func_0220684C((char *)m, (int)func_020056A0(func_02204438, o, 0), (int)func_022044A0);
    m->st = m->st + 1;
}











void func_02204438(void *a0, void *arg)
{
    Ctx_02204438 *c = arg;

    int m[4];

    c->cur = c->cur + c->step;
    if (c->step > 0)
        c->ang = c->ang - 2;
    else if (c->step < 0)
        c->ang = c->ang + 2;
    func_0207AD58(m, c->cur, c->cur);
    func_02040820(7, 0, 0x80, (u32)m, 0x100, 0x100);
    func_02040820(7, 3, c->ang, (u32)m, 0x100, 0x100);
    if (c->cur == c->target)
        func_0220687C(c->main, (void *)a0);
}










void func_022044A0(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits_022044A0 *)(p + 0x68))->n--;
}










void func_022044C0(Main_022044C0 *m, int a1, int a2, int a3, int a4)
{
    Obj_022044C0 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x18, 0, d_0220AEB0, 0xbd5);
    o->main = m;
    o->f4 = 0;
    o->f8 = a1;
    o->fc = a2;
    o->f10 = a3;
    o->f14 = a4;
    func_0220684C((char *)m, (int)func_020056A0(func_0220453C, o, 0), (int)func_02204588);
    m->st = m->st + 1;
}










void func_0220453C(void *a0, void *arg)
{
    Ctx_0220453C *c = arg;

    if (c->state == 0) {
        func_02040618(4, 0, c->a8);
        func_02040618(4, 3, c->ac);
        c->state = c->state + 1;
        return;
    }
    c->ac = c->ac + c->d10;
    func_02040618(4, 3, c->ac);
    c->cnt = c->cnt - 1;
    if (c->cnt == 0)
        func_0220687C(c->main, (void *)a0);
}










void func_02204588(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits_02204588 *)(p + 0x68))->n--;
}










void func_022045A8(Main_022045A8 *m, int a1, int a2)
{
    Obj_022045A8 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0xc10);
    o->main = m;
    o->idx = 0;
    o->set = a2;
    o->cnt = 2;
    func_0220684C((char *)m, (int)func_020056A0(func_0220461C, o, 0), (int)func_02204678);
    m->st = m->st + 1;
}










/*
 * lever:    the table extern is `const` (non-const put the cnt store before the address add)
 */
void func_0220461C(void *a0, void *arg)
{
    Ctx_0220461C *c = arg;

    int i;

    c->cnt = c->cnt - 1;
    if (c->cnt == 0) {
        c->cnt = 2;
        func_02040618(5, 0, d_0220A46C[c->set][c->idx].v0);
        i = c->idx;
        c->idx = i + 1;
        func_02040618(5, 3, d_0220A46C[c->set][i].v1);
        if (c->idx >= 2)
            func_0220687C(c->main, (void *)a0);
    }
}










void func_02204678(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits_02204678 *)(p + 0x68))->n--;
}










/*
 * note: the row offset goes into the row pointer first and the table base is added
 *   to it (base + offset); that order gives the original r0/r1 colouring at +0056.
 */
void func_02204698(Obj_02204698 *p, int a, int b)
{
    Res_02203E30 *r;
    u16 v;
    int i;
    Row_02201B20 *row;
    Quad quad;

    r = func_02030734((u16)((p->heap & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xc53);
    quad = d_0220A53C;
    r->owner = p;
    r->h = CLACT_CreateUnit(6, 0, p->heap);
    row = (Row_02201B20 *)(a << 5);
    row = (Row_02201B20 *)((u32)d_0220A85C + (u32)row);
    v = row->val[b];
    for (i = 0; i < 6; i++) {
        if (row->pos[i].x == -1) {
            r->e[i] = 0;
        } else {
            r->e[i] = (struct Obj_02204698 *)CLACT_CreateActor(r->h, p->h104, p->h108, p->h10c, &quad, 1, p->heap);
            func_0204B404((struct Obj_02201DA0 *)(r->e[i]), (const struct Vec2 *)(&row->pos[i]), 1);
            CLACT_SetActorAffineMode(r->e[i], 2);
            func_0204B92C((struct Obj *)(r->e[i]), 1);
            CLACT_SetActorAnimSeq(r->e[i], v);
        }
    }
    func_0220684C((char *)p, (int)func_02030DA8(p->h0, func_022047CC, r, 0), (int)func_022047F8);
    p->f68.n++;
}










void func_022047CC(void *a, void *arg)
{
    void **s = arg;

    int i;
    for (i = 0; i < 6; i++) {
        if (s[i + 2] != 0 && CLACT_IsActorAnimActive(s[i + 2]) != 0)
            return;
    }
    func_0220687C(s[0], a);
}










void func_022047F8(void *h)
{
    Ctx_022047F8 *c = (Ctx_022047F8 *)TCBL_IsDeletePending(h);
    int i;

    for (i = 0; i < 6; i++) {
        if (c->ent[i] != 0)
            CLACT_DeleteActor((struct Obj *)((struct Obj_02203E30 *)(c->ent[i])));
    }
    CLACT_DeleteUnit((struct Bank *)((int)((struct Bank *)c->h4)));
    c->main->st = c->main->st - 1;
}










void func_02204838(Main_02204838 *m, int a1)
{
    Obj_02204838 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0xcc9);
    o->main = m;
    o->f4 = a1;
    func_0220684C((char *)m, (int)func_02030DA8(m->f0, func_022048A4, o, 0), (int)func_02204940);
    m->st = m->st + 1;
}










void func_022048A4(void *a0, void *arg)
{
    Ctx_022048A4 *c = arg;

    int k;
    int changed = 0;
    int target;
    char *p;
    int j;
    s16_022044A0 v[2];

    for (k = 0; k < 2; k++) {
        target = d_0220A3B4[k][c->f4];
        if (k == 0) {
            p = (char *)c->main + 0x47 * 4;
        } else {
            if (((c->main->f68 << 17) >> 31) == 0) {
                break;
            }
            p = (char *)c->main + 0x53 * 4;
        }
        for (j = 0; j < 6; j++) {
            CLACT_GetActorSurfacePos(*(void **)(p + j * 8), (struct PtS *)v, 1);
            if (v[1] > target) {
                v[1] = v[1] - 4;
                changed = 1;
            } else if (v[1] < target) {
                v[1] = v[1] + 4;
                changed = 1;
            }
            func_0204B404((struct Obj_02201DA0 *)(*(void **)(p + j * 8)), (const struct Vec2 *)v, 1);
        }
    }
    if (changed == 0) {
        func_0220687C((char *)c->main, (void *)a0);
    }
}










void func_02204940(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits_02204940 *)(p + 0x68))->n--;
}










void func_02204960(Main_02204960 *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Obj_02204960 *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xd1d);
    o->main = m;
    o->f4 = a1;
    o->f8 = a2;
    o->fc = a3;
    o->f10 = a4;
    o->f14 = a5;
    o->f18 = a6;
    o->f1c = a7;
    func_0220684C((char *)m, (int)func_020056A0(func_022049C8, o, 0), 0);
}










void func_022049C8(void *a0, void *arg)
{
    Ctx_022049C8 *c = arg;

    if (c->f4 != -1) {
        func_02040618((u8)c->f4, (int)0, (int)c->f8);
        func_02040618((u8)c->f4, (int)3, (int)c->fc);
    }
    if (c->f10 != 2) {
        func_02040588((int)4, (u8)c->f10);
    }
    if (c->f14 != 2) {
        func_02040588((int)5, (u8)c->f14);
    }
    if (c->f18 != 2) {
        func_02040588((int)6, (u8)c->f18);
    }
    if (c->f1c != 2) {
        func_02040588((int)7, (u8)c->f1c);
    }
    func_0220687C(c->main, (void *)a0);
}










void func_02204A3C(void *a, void *arg)
{
    char **s = arg;

    if (PALANM_GetFadeRequestBits(((struct Obj21770 *)(*s))->f64) != 0)
        return;
    if (FADE_IsActive() != 0)
        return;
    if (((Bits_02204A3C *)(*s + 0x68))->mode == 1)
        func_022023D0(*s);
    func_0220687C(*s, a);
}









void func_02204A70(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits_02204A70 *)(p + 0x68))->mode = 0;
}









void func_02204A88(void *a0, void *arg)
{
    Ctx_v3E30 *c = arg;

    s16_02203E30 v[2];

    CLACT_GetActorSurfacePos(c->main->o210, (struct PtS *)v, 1);
    v[0] -= 8;
    func_0204B404((struct Obj_02201DA0 *)((struct Obj_02204698 *)c->main->o210), (const struct Vec2 *)v, 1);
    CLACT_GetActorSurfacePos(c->main->o214, (struct PtS *)v, 1);
    v[0] -= 8;
    func_0204B404((struct Obj_02201DA0 *)((struct Obj_02204698 *)c->main->o214), (const struct Vec2 *)v, 1);
    if (v[0] == 0xe0) {
        func_0220687C((char *)c->main, (void *)a0);
    }
}









void func_02204AEC(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits_02204AEC *)(p + 0x68))->n--;
}









void func_02204B0C(Main_02204B0C *m, int c)
{
    Obj_02204A70 *o;
    int k;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x24, 1, d_0220AEB0, 0xd8c);
    k = m->mode;
    m->mode = d_0220A38C[k][c - 5];
    m->b0 = 1;
    o->main = m;
    func_0220684C((char *)m, (int)func_02030DA8(m->owner, func_022042E4, o, 1), (int)((void *)func_022043AC));
    func_021F8AC0(2);
    func_021F7998(d_0220A3E4[k][c - 5]);
}









void func_02204BAC(void *a, void *arg)
{
    int *b = arg;

    if (func_021F8678() != 0) {
        func_021F8884(b[1]);
        func_0220687C((char *)b[0], (void *)a);
    }
}









static inline void GXS_SetVisibleWnd(int mask)
{
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0xe000) | ((u32)mask << 13);
}









static inline void G2S_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}









static inline void G2S_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f00) | ((u32)wnd << 8));
    if (effect) {
        tmp |= (0x20 << 8);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}









static inline void G2S_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}









static inline void G2S_SetBlendBrightness(int plane, int brightness)
{
    func_0207D658((u32)&reg_G2S_DB_BLDCNT, plane, brightness);
}









/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204BD4..0x02204C20)
 */
void func_02204BCC(void *a0, void *arg)
{
    int *c = arg;

    GXS_SetVisibleWnd(3);
    G2S_SetWnd0InsidePlane(0x1f, c[1] > 1);
    G2S_SetWnd1InsidePlane(0x1f, c[1] == 3);
    G2S_SetWndOutsidePlane(0x1f, 0);
    G2S_SetBlendBrightness(0x10, -8);
    func_0220687C((void *)c[0], a0);
}









static inline void G2S_BlendNone(void)
{
    func_0207D658((u32)&reg_G2S_DB_BLDCNT, 0, 0);
}









/*
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204C4C..0x02204C76)
 */
void func_02204C48(void *a0, void *arg)
{
    int *c = arg;

    GXS_SetVisibleWnd(0);
    G2S_SetWnd0InsidePlane(0, 0);
    G2S_SetWnd1InsidePlane(0, 0);
    G2S_SetWndOutsidePlane(0, 0);
    G2S_BlendNone();
    func_0220687C((void *)c[0], a0);
}








void func_02204C98(struct StrObj *a, int b, int *outn, int *outq)
{
    int n = func_0201D304(a, b, 0);
    int q = n / 8;
    if (func_0207C994(n, 8) != 0)
        q++;
    *outn = n;
    *outq = q;
}









#pragma opt_common_subs off







#pragma opt_propagation off







/*
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of func_020275E4. Left: register allocation. The image keeps q in r6 and
 *   recomputes p + i*4, q + i*2 and q + i after every call (only i*8 lives in r7, k
 *   and font are spilled, font at sp+0x9c just under c); 1.1p1 CSEs those sums
 *   across the calls, so q spills, k takes r7 and every slot shifts. Breaking the
 *   CSEs with (u32)i / (s32)(u32)i casts per call group plus a temporary for the
 *   CLACT_CreateActor result (so the store address is formed after the call) gets the
 *   p/i registers and the per-call recompute, but q still lands in r7 and k in r6.
 *   Also open: GF_FONT_SetTextColor's colour arguments are evaluated r2, r1, r0 in the
 *   image (col kept in r0), ours evaluates r0 first and copies col to r3.
 * note (2026-10-02, lane A2-06): source now has the casts per call group (the
 *   recompute pattern of every p/q/i sum matches the image), the obj temporary,
 *   a Work_v3E30 struct for p, and (&tbl[i].x)[1] for the three y arguments: plain
 *   .y makes 1.1p1 form tbl + i*8 at the head of the call and spill it (sibling
 *   022050F0 does that, this image does not); the (&x)[1] spelling reproduces
 *   the image's x-load, w/2, late y-address order (checked in a loop probe).
 *   Measured inert for the allocator: block-scoped k/arc/chr/obj, heap inline,
 *   if/else inverted, x in a local, u8 locals or u8/u32 prototype for the
 *   colour call, font as a pointer, u32, long or u16, the cast spelling set itself, a
 *   q copy local, dead q uses. Still open, all allocator: q r7 (image r6), k
 *   and pltt take r6 (image spills both, k at sp+0x30, pltt at sp+0x3c), the
 *   second w/2 temp lands in r6 (image spills it to sp+0x68), frame 0x10c vs
 *   0x118, and the image's t1 call copies i*8 (adds r2, r7, #0). Slot order in
 *   the image is reverse declaration with font last (sp+0x9c); ours spills font
 *   right after file. volatile font declared last puts font just under c but
 *   flips p/i (image p r4, i r5); a 4-byte struct Font gets frame 0x118.
 *   Witness gaps once bytes match: func_020275F8, func_020275EC (arm, no caller
 *   outside this body) and the six d_0220Axxx tables are unresolved relocations.
 * note (2026-10-02, lane A2 follow-up): cause found, not closable under the
 *   lane rules. The image is this body compiled with global CSE off: with
 *   `#pragma opt_common_subs off` above the function, the natural spelling
 *   (no index casts, no obj temporary, plain tbl[i].y) gives 1072 bytes, frame
 *   0x118, p r4 / i r5, font at sp+0x9c and every spill and hoist slot of the
 *   image's prologue, and only 308 bytes differ. The casts, obj and (&x)[1]
 *   in this draft are stand-ins that emulate CSE-off. The `(i < 4) ? 1 : 0`
 *   condition is still needed (CSE-off alone still rotates a plain loop: 547).
 *   Left with the pragma: q r7 / i*8 r6 (image q r6 / i*8 r7), the slot order
 *   of the 0x224/0x22c hoisted constants (first print group lowest, image
 *   highest), the w/2 sign temp spilled in the first print (image: third), the
 *   colour call channels evaluated r0 first (image r2 first; u8 r/g/b locals
 *   are copy-propagated, inert), and 0x06600000 + buf operand order.
 *   Measured as NOT disabling the CSE (probes and full body): int/u8/u16/s16_02203E30/
 *   u32/long/enum counter, register on params/counter, volatile Slots, void *
 *   params cast per use, static inline accessor, raw `char *` offsets in every
 *   form ((s + i * 4) + K, s + (i * 4 + K), ((T *)(s + K))[i]), up to 100
 *   extra locals, 3000 extra statements, 1500 extra branches, switch, static
 *   local, function pointer, struct copy/return, varargs, bit-field, float,
 *   division, long long. `asm { nop }` disables it but also constant
 *   propagation (offsets go to the pool), so not that either. The pragma is
 *   user-approved 2026-10-02.
 * note (2026-10-02, lane A2 pragma): neighbour check. The CSE-off pattern is
 *   per-function, not per-file: the EXACT next function func_022050F0 (same
 *   Work_v3E30 struct, same print callees, normal settings) keeps i*12 at sp+0x14
 *   and p+i*12 at sp+0x10 and reuses both after calls (ldr r2,[sp,#0x10] at
 *   0x022051B4 after blx 0x02045EC0; ldr r0,[sp,#0x14] at 0x02205212 after
 *   blx 0x02045808), which CSE off cannot produce. So the pragma is scoped
 *   to this function (opt_common_subs off ... reset).
 *   Result: CSE off alone leaves 309 bytes. The image also needs
 *   `#pragma opt_propagation off` (user-approved 2026-10-02). `#pragma
 *   opt_dead_assignments off` in its place gives byte-identical output, so
 *   which of the two the original used cannot be recovered. Both are scoped
 *   to this function with reset after it: the neighbour evidence above
 *   (022050F0 compiled with normal settings) shows the settings are
 *   per-function.
 *   What closes the rest once both pragmas are on: (1) the colour channels
 *   as u8 locals assigned b, g, r and passed r, g, b (keeps col in r0, the
 *   image's r2-first order, and with it q r6 / i*8 r7, the 0x224/0x22c hoist
 *   slot order and the w/2 spill in the third print); (2) `const Slots *q`
 *   (q + i formed before the stack-argument stores of both func_0201EFA4
 *   calls); (3) the enum VRAM_BASE local of the EXACT sibling func_02205F88
 *   for the 0x06600000 + buf operand order. Measured inert or worse:
 *   opt_lifetimes off (alone 713, with CSE off no change), optimization_level
 *   0..3, global_optimizer off, optimize_for_size, opt_dead_code off,
 *   opt_strength_reduction off, scheduling off, declaration order of every
 *   register local, colour/EFA4/02049F34 prototypes (incl. unprototyped),
 *   the EFA4 third-argument spelling, inline heap/arc, loop-condition forms.
 *   The last relocation, func_020275EC, resolved once arm9 0x020275EC was
 *   seeded as a Thumb leaf (src/matched/arm9/func_020275EC.c, EXACT).
 */
/*
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of func_020275E4. Left: register allocation. The image keeps q in r6 and
 *   recomputes p + i*4, q + i*2 and q + i after every call (only i*8 lives in r7, k
 *   and font are spilled, font at sp+0x9c just under c); 1.1p1 CSEs those sums
 *   across the calls, so q spills, k takes r7 and every slot shifts. Breaking the
 *   CSEs with (u32)i / (s32)(u32)i casts per call group plus a temporary for the
 *   CLACT_CreateActor result (so the store address is formed after the call) gets the
 *   p/i registers and the per-call recompute, but q still lands in r7 and k in r6.
 *   Also open: GF_FONT_SetTextColor's colour arguments are evaluated r2, r1, r0 in the
 *   image (col kept in r0), ours evaluates r0 first and copies col to r3.
 * note (2026-10-02, lane A2-06): source now has the casts per call group (the
 *   recompute pattern of every p/q/i sum matches the image), the obj temporary,
 *   a Work struct for p, and (&tbl[i].x)[1] for the three y arguments: plain
 *   .y makes 1.1p1 form tbl + i*8 at the head of the call and spill it (sibling
 *   022050F0 does that, this image does not); the (&x)[1] spelling reproduces
 *   the image's x-load, w/2, late y-address order (checked in a loop probe).
 *   Measured inert for the allocator: block-scoped k/arc/chr/obj, heap inline,
 *   if/else inverted, x in a local, u8 locals or u8/u32 prototype for the
 *   colour call, font as a pointer, u32, long or u16, the cast spelling set itself, a
 *   q copy local, dead q uses. Still open, all allocator: q r7 (image r6), k
 *   and pltt take r6 (image spills both, k at sp+0x30, pltt at sp+0x3c), the
 *   second w/2 temp lands in r6 (image spills it to sp+0x68), frame 0x10c vs
 *   0x118, and the image's t1 call copies i*8 (adds r2, r7, #0). Slot order in
 *   the image is reverse declaration with font last (sp+0x9c); ours spills font
 *   right after file. volatile font declared last puts font just under c but
 *   flips p/i (image p r4, i r5); a 4-byte struct Font gets frame 0x118.
 *   Witness gaps once bytes match: func_020275F8, func_020275EC (arm, no caller
 *   outside this body) and the six d_0220Axxx tables are unresolved relocations.
 * note (2026-10-02, lane A2 follow-up): cause found, not closable under the
 *   lane rules. The image is this body compiled with global CSE off: with
 *   `#pragma opt_common_subs off` above the function, the natural spelling
 *   (no index casts, no obj temporary, plain tbl[i].y) gives 1072 bytes, frame
 *   0x118, p r4 / i r5, font at sp+0x9c and every spill and hoist slot of the
 *   image's prologue, and only 308 bytes differ. The casts, obj and (&x)[1]
 *   in this draft are stand-ins that emulate CSE-off. The `(i < 4) ? 1 : 0`
 *   condition is still needed (CSE-off alone still rotates a plain loop: 547).
 *   Left with the pragma: q r7 / i*8 r6 (image q r6 / i*8 r7), the slot order
 *   of the 0x224/0x22c hoisted constants (first print group lowest, image
 *   highest), the w/2 sign temp spilled in the first print (image: third), the
 *   colour call channels evaluated r0 first (image r2 first; u8 r/g/b locals
 *   are copy-propagated, inert), and 0x06600000 + buf operand order.
 *   Measured as NOT disabling the CSE (probes and full body): int/u8/u16/s16/
 *   u32/long/enum counter, register on params/counter, volatile Slots, void *
 *   params cast per use, static inline accessor, raw `char *` offsets in every
 *   form ((s + i * 4) + K, s + (i * 4 + K), ((T *)(s + K))[i]), up to 100
 *   extra locals, 3000 extra statements, 1500 extra branches, switch, static
 *   local, function pointer, struct copy/return, varargs, bit-field, float,
 *   division, long long. `asm { nop }` disables it but also constant
 *   propagation (offsets go to the pool), so not that either. The pragma is
 *   user-approved 2026-10-02.
 * note (2026-10-02, lane A2 pragma): neighbour check. The CSE-off pattern is
 *   per-function, not per-file: the EXACT next function func_022050F0 (same
 *   Work struct, same print callees, normal settings) keeps i*12 at sp+0x14
 *   and p+i*12 at sp+0x10 and reuses both after calls (ldr r2,[sp,#0x10] at
 *   0x022051B4 after blx 0x02045EC0; ldr r0,[sp,#0x14] at 0x02205212 after
 *   blx 0x02045808), which CSE off cannot produce. So the pragma is scoped
 *   to this function (opt_common_subs off ... reset).
 *   Result: CSE off alone leaves 309 bytes. The image also needs
 *   `#pragma opt_propagation off` (user-approved 2026-10-02). `#pragma
 *   opt_dead_assignments off` in its place gives byte-identical output, so
 *   which of the two the original used cannot be recovered. Both are scoped
 *   to this function with reset after it: the neighbour evidence above
 *   (022050F0 compiled with normal settings) shows the settings are
 *   per-function.
 *   What closes the rest once both pragmas are on: (1) the colour channels
 *   as u8 locals assigned b, g, r and passed r, g, b (keeps col in r0, the
 *   image's r2-first order, and with it q r6 / i*8 r7, the 0x224/0x22c hoist
 *   slot order and the w/2 spill in the third print); (2) `const Slots *q`
 *   (q + i formed before the stack-argument stores of both func_0201EFA4
 *   calls); (3) the enum VRAM_BASE local of the EXACT sibling func_02205F88
 *   for the 0x06600000 + buf operand order. Measured inert or worse:
 *   opt_lifetimes off (alone 713, with CSE off no change), optimization_level
 *   0..3, global_optimizer off, optimize_for_size, opt_dead_code off,
 *   opt_strength_reduction off, scheduling off, declaration order of every
 *   register local, colour/EFA4/02049F34 prototypes (incl. unprototyped),
 *   the EFA4 third-argument spelling, inline heap/arc, loop-condition forms.
 *   The last relocation, func_020275EC, resolved once arm9 0x020275EC was
 *   seeded as a Thumb leaf (src/matched/arm9/func_020275EC.c, EXACT).
 */
void func_02204CC0(Work_v3E30 *p, const Slots *q)
{
    PosTab t1 = d_0220A5B0;
    PosTab t2 = d_0220A5D0;
    int font;
    void *pltt;
    void *chr;
    u32 arc;
    int k;
    int file;
    void *str1;
    void *m0;
    void *str2;
    void *m2;
    void *m1;
    u16 heap;
    int i;
    Struct36 buf;
    int w;
    int h;
    void *cd;
    void *pd;
    u8 c[3];
    int col;
    u8 cr, cg, cb;
    enum { VRAM_BASE = 0x06600000 } vram;

    str1 = STRBUF_Create(0x10, p->heap);
    m0 = func_02045EC0(p->msgdata, 0);
    m1 = func_02045EC0(p->msgdata, 1);
    font = (int)func_0201EC64(p->heap);
    str2 = STRBUF_Create(0x10, p->heap);
    m2 = func_02045EC0(p->msgdata, 2);
    func_0204B22C(p->sys, 0);
    for (i = 0; (i < 4) ? 1 : 0; i++) {
        if (q->id[i] != 0) {
            k = func_0201BD28(q->id[i], 0);
            file = d_0220A5F0[k];
            p->obj[i] = (struct Obj_02204698 *)CLACT_CreateActor(p->sys, p->res[i], p->r1f0, p->r1f4, d_0220A392, 1, p->heap);
            func_0204B404((struct Obj_02201DA0 *)(p->obj[i]), (const struct Vec2 *)(&d_0220A3C4[i]), (int)1);
            heap = (p->heap & 0x7fff) | 0x8000;
            arc = func_020275E4();
            chr = func_02049E34(arc, func_020275F8((u8)k), 0, (u32)(&cd), heap);
            func_0204B6F4(p->obj[i], func_020275EC((u8)k), 1);
            CLACT_GetActorImageProxy(p->obj[i], (struct Struct36 *)(&buf));
            vram = VRAM_BASE;
            func_02082A60(((struct Obj21781 *)cd)->f14, (void *)(vram + buf.w[2]), 0x100);
            func_020307B0(chr);
            GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
            GF_FONT_SetTextColor(1, 2, 0);
            func_0201EF34((struct WordSet *)font, 0, q->id[i]);
            func_0201F250((struct WordSet *)font, str1, m0);
            func_02204C98(str1, (int)p->fnt, &w, &h);
            PRINTSYS_Print(p->win, d_0220A4AC[i].x - w / 2, d_0220A4AC[i].y, str1, p->fnt);
            func_0201EFA4(font, 0, q->a[i], 2, 1, 1);
            func_0201EFA4(font, 1, q->b[i], 2, 1, 1);
            func_0201F250((struct WordSet *)font, str2, m2);
            col = func_02205768(q->a[i], q->b[i]);
            cb = (u8)(col & 0x1f);
            cg = (u8)((col >> 5) & 0x1f);
            cr = (u8)((col >> 10) & 0x1f);
            GF_FONT_SetTextColor(cr, cg, cb);
            PRINTSYS_Print(p->win, t1.v[i].x, t1.v[i].y, m1, p->fnt);
            func_02204C98(str2, (int)p->fnt, &w, &h);
            PRINTSYS_Print(p->win, t2.v[i].x - w / 2, t2.v[i].y, str2, p->fnt);
            GF_FONT_SetTextColor(c[2], c[1], c[0]);
            p->f25a[i] = q->a[i] != 0;
            p->f262[i] = q->id[i] != 0;
        } else {
            file = 0xc1;
        }
        heap = (p->heap & 0x7fff) | 0x8000;
        pltt = func_02049F34(0xb, file, (u32)(&pd), heap);
        PALANM_CopyToSlot(p->bg, ((struct Obj21782 *)pd)->fC, (int)1, (u16)(i * 16 + 0x90), 0x20);
        func_020307B0(pltt);
    }
    p->f25a[i] = 1;
    if (p->mode == 2) {
        p->f25a[i + 1] = 1;
    }
    func_0201ED04((struct WordSet *)font);
    STRBUF_Delete(str1);
    STRBUF_Delete(m1);
    STRBUF_Delete(m0);
    STRBUF_Delete(m2);
    STRBUF_Delete(str2);
}







#pragma opt_propagation reset







#pragma opt_common_subs reset








void func_022050F0(char *s, Out *out, const Info_v3E30 *p)
{
    int n;
    int k;
    int i;
    int m;
    int idx;
    void *v;
    int h;
    void *w;
    void *r;
    int ww;
    int hh;
    Res_02204C98 *res;
    u8 c[3];

    n = (((struct Obj01909 *)s)->f50 == 2) ? 6 : 4;
    k = (((struct Obj01909 *)s)->f50 == 2) ? 1 : 0;
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    v = STRBUF_Create(12, (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    h = (int)func_0201EC64((u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    GF_FONT_SetTextColor(1, 2, 0);
    for (i = 0; i < n; i++) {
        if (p->e[i].show != 0) {
            w = func_02045EC0(((struct Obj01909 *)s)->f5C, p->e[i].kind + 3);
            func_0201EEF4((void *)h, 0, p->e[i].text);
            func_0201F250((struct WordSet *)h, v, w);
            func_02204C98((struct StrObj *)v, ((struct Obj01909 *)s)->f224, &ww, &hh);
            PRINTSYS_Print((void *)(((struct Obj01909 *)s)->f22C), d_0220A7FC[k][i][0] - ww / 2, d_0220A7FC[k][i][1], v, (void *)(((struct Obj01909 *)s)->f224));
            STRBUF_Delete(w);
        }
        (s + i)[0x25a] = p->e[i].flag;
    }
    (s + i)[0x25a] = 1;
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    STRBUF_Delete(v);
    idx = (p->b48 - 2) / 2;
    ((Bits6C *)(s + 0x6c))->x = p->b49;
    out->fc = d_0220A94C[k][idx][p->b49];
    m = 3;
    if (((struct Obj01909 *)s)->f50 != 2)
        m = 2;
    for (i = 0; i < m; i++) {
        r = func_02049F34(11, 0xd3, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
    for (m *= 2; i < m; i++) {
        r = func_02049F34(11, 0xd4, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
}








void func_02205340(Main_v3E30 *m, const int *c)
{
    int w;
    int h;

    GF_FONT_SetTextColor(1, 2, 0);
    func_02204C98((struct StrObj *)c[0], m->o224, &w, &h);
    PRINTSYS_Print((void *)m->o22c, 0x80 - w / 2, 0x10, (void *)c[0], (void *)m->o224);
    func_02204C98((struct StrObj *)c[1], m->o224, &w, &h);
    PRINTSYS_Print((void *)m->o22c, 0x80 - w / 2, 0x40, (void *)c[1], (void *)m->o224);
    m->b25a = 1;
    m->b25b = 1;
    func_020498F4((void *)m->f48, 0x6b, 5, 0, 0, 0, m->h240);
}








/*
 * lever: 022053DE reserves 0x28 bytes: 16 outgoing argument bytes plus
 *   a 24-byte local. Only its first 16 bytes are read/initialized here;
 *   pad10 preserves the observed allocation without naming unknown fields.
 *   Palette field reads retain the A386/A387 pools as one extern plus addend.
 */
void func_022053DC(char *m)
{
    int i;
    Buffer buf;
    for (i = 0; i < 4; i++) {
        buf.value[i] = 0;
        buf.a[i] = 0;
        buf.b[i] = 0;
    }
    for (i = 0; i < BTL_POKEPARAM_GetMoveCount((struct QG *)OBJECT); i++)
        buf.value[i] = func_021D5528(OBJECT, i, &buf.a[i], &buf.b[i]);
    func_02204CC0((Work_v3E30 *)((struct Work_02201B20 *)m), (const Slots *)((const struct Slots *)(&buf)));
    ((struct Obj00168 *)m)->f25F = d_0220A386[INDEX].first;
    ((struct Obj00168 *)m)->f260 = d_0220A386[INDEX].second;
    ((struct Obj00168 *)m)->f220 = 1;
    for (i = 0; i < 4; i++) {
        if (*(int *)(m + INDEX * 16 + i * 4 + 0x2b0) == 1)
            ((struct Obj00168 *)m)->f220 = 0;
    }
    if (BTL_POKEPARAM_IsFainted(OBJECT)) {
        for (i = 0; i < 4; i++)
            *(u8 *)(m + i + 0x25a) = 0;
        ((struct Obj00168 *)m)->f220 = 0;
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        return;
    }
    if (((struct Obj00168 *)m)->f220 == 1) {
        ((struct Obj00168 *)m)->f25A = 1;
        func_02205F88(m);
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 8, 8, 0, ((struct Obj00168 *)m)->f0);
        return;
    }
    PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 2, 0x3e00, 0, 0, 0, 0, ((struct Obj00168 *)m)->f0);
    PALANM_RequestFadeOverwrite(((struct Obj00168 *)m)->f64, 8, 0x700, 0, 0, 0, 0, ((struct Obj00168 *)m)->f0);
}








/*
 * trailing: 022056B2..022056B4 is two-byte alignment padding.
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 lacks an outside witness at +010C.
 * Verified EXACT C copied from ov029_func_021F0DB4.c:
 * int PALANM_GetDefaultWork(char *p, int i) { return *(int *)(p + i * 0x14); }
 */
void func_0220558C(char *s, const int *b)
{
    int h;
    void *v;
    void *w;
    void *extra;
    u8 c[3];
    h = (int)func_0201EC64(((struct Obj02440 *)s)->f240);
    v = STRBUF_Create(8, ((struct Obj02440 *)s)->f240);
    w = func_02045EC0(((struct Obj02440 *)s)->f5C, 6);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(9, 10, 0);
    func_0201EFA4(h, 0, b[2], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x8c, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    if (b[0] != b[1])
        GF_FONT_SetTextColor(7, 8, 0);
    func_0201EFA4(h, 0, b[1], 3, 2, 1);
    func_0201F250((void *)h, v, w);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x60, 8, v, (void *)(((struct Obj02440 *)s)->f224));
    GF_FONT_SetTextColor(1, 2, 0);
    extra = func_02045EC0(((struct Obj02440 *)s)->f5C, 7);
    PRINTSYS_Print((void *)(((struct Obj02440 *)s)->f22C), 0x7c, 8, extra, (void *)(((struct Obj02440 *)s)->f224));
    STRBUF_Delete(extra);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
    PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj02440 *)s)->f64), (u16 *)(PALANM_GetDefaultWork((char *)func_021F86E0(), 1) + 0x40), 1, 0x70, 0x20);
}









void func_022056B4(Main_022053DC *m)
{
    int i;
    int j;

    m->f6c &= ~2;
    for (i = 0; i < 8; i++) {
        m->b25a[i] = 0;
    }
    for (j = 0; j < 4; j++) {
        m->b262[j] = 0;
    }
    BMP_Clear((struct CharBuf *)m->o22c, 0);
    BMP_WIN_TransferChars((struct Descriptor *)m->o228);
    BMP_Clear((struct CharBuf *)m->o234, 0);
    BMP_WIN_TransferChars((struct Descriptor *)m->o230);
    func_02205F64((W_02205F64 *)((Main_022053DC *)m));
    func_02206128((char *)m);
    func_02205D34((W_022053DC *)m);
    func_02041300(4, 0, 0x20, 2, 0x20, 0x20, 0);
    PALANM_RequestFadeOverwrite((void *)m->f64, 2, 0x3e00, 0, 0, 0, 0, m->owner);
    PALANM_RequestFadeOverwrite((void *)m->f64, 8, 0x700, 0, 0, 0, 0, m->owner);
}








int func_02205768(int a, int b)
{
    if (a == 0) {
        return 0x1d00;
    }
    if (b == a) {
        return 0x440;
    }
    if (b <= 2) {
        if (a == 1) {
            return 0x14c0;
        }
    } else if (b <= 7) {
        switch (a) {
        case 1:
            return 0x14c0;
        case 2:
            return 0xc80;
        }
    } else {
        if (a <= b / 4) {
            return 0x14c0;
        }
        if (a <= b / 2) {
            return 0xc80;
        }
    }
    return 0x440;
}







void func_022057CC(Main_022057CC *m, Info_v53DC *q)
{
    int n;
    void *arc;
    int i;
    int k;
    void **r;
    const Point_022053DC *pt;
    s16_022057CC x, y;

    n = (m->mode == 3) ? 2 : m->mode + 1;
    k = 0;
    if (m->mode == 0 || m->mode == 3)
        return;
    arc = func_020490F4(7, (u16)((m->heap & 0x7fff) | 0x8000));
    m->h1c0 = CLACT_RegisterCellAnim(arc, func_0201BC78(), func_0201BCEC(), m->heap);
    m->h1bc = CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 1, 0x160, m->heap);
    PALANM_CopyHwPaletteToSlot(m->pal, 3, (u16)(CLACT_GetPaletteVramAddress(m->h1bc, 1) >> 1), 0x60);
    *(volatile u16 *)0x04001040 = 0x100;
    *(volatile u16 *)0x04001044 = 0;
    *(volatile u16 *)0x04001042 = 0x100;
    *(volatile u16 *)0x04001046 = 0;
    if (n > 1) {
        r = func_02030734((u16)((m->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x1145);
        r[0] = m;
        r[1] = (void *)n;
        func_0220684C((char *)m, (int)func_020056A0(func_02204BCC, r, 0), 0);
    }
    for (i = 0; i < n; i++) {
        if (q->species[i] != 0) {
            m->h1b0[i] = CLACT_RegisterCharacter(arc, POKE_TOOL_CalcGraphicIndex(q->species[i], q->form[i], q->gender[i], 0), 0, 1, m->heap);
            m->h1c8[i].obj = CLACT_CreateActor((void *)m->h1c4, m->h1b0[i], m->h1bc, m->h1c0, d_0220A392, 1, m->heap);
            func_0204B404((struct Obj_02201DA0 *)(m->h1c8[i].obj), (const struct Vec2 *)(&d_0220A50C[m->mode][i]), 1);
            func_0204B92C(m->h1c8[i].obj, 1);
            if (q->sel == i) {
                CLACT_SetActorAnimSeq(m->h1c8[i].obj, 1);
            } else if (k == 0) {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001040 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001044 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
                k++;
            } else {
                pt = &d_0220A50C[m->mode][i];
                x = pt->x;
                y = pt->y;
                *(volatile u16 *)0x04001042 = (((x - 16) << 8) & 0xff00) | (u8)(x + 16);
                *(volatile u16 *)0x04001046 = (((y - 16) << 8) & 0xff00) | (u8)(y + 16);
            }
            func_0204B6F4(m->h1c8[i].obj, func_0201BB5C(q->species[i], q->form[i], q->gender[i], 0), 0);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}







/*
 * lever: entry reads use the indexed aggregate; the zero store uses its raw
 * offset. This avoids retaining a common entry pointer across both frees.
 */
void func_02205AB8(char *p)
{
    int i;
    int empty = 1;
    int *ctx;
    for (i = 0; i < 3; i++) {
        if (((Work_02201B20 *)p)->entries[i].entry != 0) {
            CLACT_DeleteActor(((Work_02201B20 *)p)->entries[i].entry);
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x1b0));
            *(void **)(p + i * 8 + 0x1c8) = 0;
            *(int *)(p + i * 4 + 0x1b0) = -1;
            empty = 0;
        }
    }
    if (((struct Obj01049 *)p)->f1C0 != -1) {
        CLACT_ReleaseCellAnim(((struct Obj01049 *)p)->f1C0);
        ((struct Obj01049 *)p)->f1C0 = -1;
    }
    if (((struct Obj01049 *)p)->f1BC != -1) {
        CLACT_ReleasePalette(((struct Obj01049 *)p)->f1BC);
        ((struct Obj01049 *)p)->f1BC = -1;
    }
    if (!empty) {
        ctx = func_02030734((u16)((((struct Obj01049 *)p)->f240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0x11b2);
        ctx[0] = (int)p;
        func_0220684C(p, (int)func_020056A0(func_02204C48, ctx, 0), 0);
    }
}








void func_02205B80(char *p, int a)
{
    func_0204B22C(((struct Obj21785 *)p)->f1C4, a);
}







void func_02205B90(char *p, int n)
{
    Five a = d_0220A558;
    Five b = d_0220A56C;
    Five c = d_0220A544;
    Point_022053DC v;
    int index;
    void **q;
    if (n == 0) return;
    ((struct Obj00896 *)p)->f210 = CLACT_CreateActor((void *)((struct Obj00896 *)p)->f20C, ((struct Obj00896 *)p)->f104, ((struct Obj00896 *)p)->f108, ((struct Obj00896 *)p)->f10C, d_0220A392, 1, ((struct Obj00896 *)p)->f240);
    index = n - 1;
    v.x = 0x130 + b.v[index];
    v.y = 0x20 + c.v[index];
    func_0204B404((struct Obj_02201DA0 *)(((struct Obj00896 *)p)->f210), (const struct Vec2 *)(&v.x), (int)1);
    func_0204B92C(((struct Obj00896 *)p)->f210, 1);
    n += 14;
    CLACT_SetActorAnimSeq(((struct Obj00896 *)p)->f210, n);
    ((struct Obj00896 *)p)->f214 = CLACT_CreateActor((void *)((struct Obj00896 *)p)->f20C, ((struct Obj00896 *)p)->f104, ((struct Obj00896 *)p)->f108, ((struct Obj00896 *)p)->f10C, d_0220A392, 1, ((struct Obj00896 *)p)->f240);
    v.x = 0x130;
    v.y = 0x20;
    func_0204B404((struct Obj_02201DA0 *)(((struct Obj00896 *)p)->f214), (const struct Vec2 *)(&v.x), (int)1);
    func_0204B92C(((struct Obj00896 *)p)->f214, 1);
    CLACT_SetActorAnimSeq(((struct Obj00896 *)p)->f214, 14);
    func_0204B6F4(((struct Obj00896 *)p)->f214, (u8)a.v[index], 0);
    q = func_02030734((u16)((((struct Obj00896 *)p)->f240 & 0x7fff) | 0x8000), 4, 0, d_0220AEB0, 0x11ec);
    q[0] = p;
    func_0220684C(p, (int)func_02030DA8((void *)((struct Obj00896 *)p)->f0, func_02204A88, q, 0), (int)((void *)func_02204AEC));
    ((Bits_022053DC *)(p + 0x68))->count++;
}








void func_02205D34(W_022053DC *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}








void func_02205D58(char *p, int mode)
{
    Slot *slots;
    Point_022053DC pos;
    int add;
    int step;
    char *row;
    int i;

    if (mode == 1) {
        slots = (Slot *)(p + 0x14c);
        pos.x = 0x94;
        pos.y = 0x30;
        step = -8;
        add = 4;
    } else {
        slots = (Slot *)(p + 0x11c);
        pos.x = 0x58;
        pos.y = 0x88;
        step = 0x10;
        add = 0;
    }
    i = 0;
    row = p + mode * 0x48;
    for (; i < 6; i++) {
        slots[i].h = CLACT_CreateActor((void *)((struct Obj06327 *)p)->f118, ((struct Obj06327 *)p)->f104, ((struct Obj06327 *)p)->f108, ((struct Obj06327 *)p)->f10C, d_0220A392, 1, ((struct Obj06327 *)p)->f240);
        func_0204B404((struct Obj_02201DA0 *)slots[i].h, (const struct Vec2 *)(&pos), 1);
        func_0204B92C(slots[i].h, 1);
        CLACT_SetActorAnimSeq(slots[i].h, add + *(u8 *)(row + i * 12 + 0x75));
        pos.x += (s16_022057CC)step;
    }
}








/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`off = 0x11c;` before `off = 0x14c;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_02205E30(char *o)
{
    int i;
    int j;
    int off;
    char *p;

    i = 0;
    off = 0x14c;
    for (; i < 2; i++) {
        if (i != 0) {
            p = o + off;
        } else {
            p = o + 0x47 * 4;
        }
        for (j = 0; j < 6; j++) {
            if (*(void **)(p + j * 8) != 0) {
                CLACT_DeleteActor(*(void **)(p + j * 8));
                *(void **)(p + j * 8) = 0;
            }
        }
    }
}








/*
 * note 2026-10-05 (wave D9r lane 131): removed the 5 dead first assignments
 * (`o0 = 0x240;` before `o0 = 0x17c;`; `o1 = 0x110;` before `o1 = 0x108;`
 * and 3 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_02205E80(char *m)
{
    Q_v53DC q = d_0220A580;
    int o0;
    int o1;
    int o2;
    int o3;
    int o4;
    int o5;
    char *p;
    int j;

    o0 = 0x17c;
    o1 = 0x108;
    o2 = 0x114;
    o3 = 0x180;
    o4 = 0x180;
    o5 = 0x180;
    for (j = 0; j < 6; j++) {
        p = m + j * 8;
        *(u32 *)(p + o3) = (u32)CLACT_CreateActor((void *)*(u32 *)(m + o0), ((struct Obj00083 *)m)->f110, *(u32 *)(m + o1),
                                         *(u32 *)(m + o2), d_0220A392, 1, ((struct Obj00083 *)m)->f240);
        func_0204B92C((struct Obj *)*(int *)(p + o4), 1);
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + o5)), q.v[j]);
        func_0204B3DC((struct Obj *)((struct Obj21787 *)p)->f180, 0);
    }
}







void func_02205F40(W_02205F40 *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}







void func_02205F64(W_02205F64 *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}







void func_02205F88(char *p)
{
    void *str;
    void *msg;
    int font;
    void *bmp;
    Point_02205F40 pos;
    int w;
    int h;
    u8 c[3];
    Struct36 buf;
    char *pixels;
    int i;
    enum { VRAM_BASE = 0x06600000 } vram;

    ((struct Obj01384 *)p)->f21C = CLACT_CreateActor((void *)((struct Obj01384 *)p)->f218, ((struct Obj01384 *)p)->f104, ((struct Obj01384 *)p)->f108, ((struct Obj01384 *)p)->f10C, d_0220A392, 1, ((struct Obj01384 *)p)->f240);
    pos.x = 0x80;
    pos.y = 0x50;
    func_0204B404((struct Obj_02201DA0 *)(((struct Obj01384 *)p)->f21C), (const struct Vec2 *)(&pos), 1);
    func_0204B92C(((struct Obj01384 *)p)->f21C, 1);
    CLACT_SetActorAnimSeq(((struct Obj01384 *)p)->f21C, 0x14);
    str = STRBUF_Create(0x10, ((struct Obj01384 *)p)->f240);
    msg = func_02045EC0(((struct Obj01384 *)p)->f5C, 0);
    font = (int)func_0201EC64(((struct Obj01384 *)p)->f240);
    bmp = BMP_Create(0xe, 4, 0x20, ((struct Obj01384 *)p)->f240);
    BMP_Clear(bmp, 0);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(0xe, 0xa, 0);
    func_0201EF34((struct WordSet *)font, 0, 0xa5);
    func_0201F250((struct WordSet *)font, str, msg);
    func_02204C98((struct StrObj *)str, (int)(((struct Obj01384 *)p)->f224), &w, &h);
    PRINTSYS_Print(bmp, 0x38 - w / 2, 8, str, ((struct Obj01384 *)p)->f224);
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    pixels = BMP_GetPixels(bmp);
    CLACT_GetActorImageProxy(((struct Obj01384 *)p)->f21C, (struct Struct36 *)(&buf));
    vram = VRAM_BASE;
    for (i = 0; i < 4; i++) {
        func_02082A60(pixels + i * 0x1c0, (void *)(vram + (i * 8 + 0xcd) * 32 + buf.w[2]), 0x100);
        func_02082A60(pixels + (i * 0x1c0 + 0x100), (void *)(vram + (i * 4 + 0xed) * 32 + buf.w[2]), 0x80);
        func_02082A60(pixels + (i * 0x1c0 + 0x180), (void *)(vram + (i * 2 + 0xfd) * 32 + buf.w[2]), 0x40);
    }
    STRBUF_Delete(str);
    STRBUF_Delete(msg);
    func_0201ED04((struct WordSet *)font);
    BMP_Delete(bmp);
}







void func_02206128(char *p)
{
    if (((struct Obj10158 *)p)->f21C != 0) {
        CLACT_DeleteActor(((struct Obj10158 *)p)->f21C);
        ((struct Obj10158 *)p)->f21C = 0;
    }
}






/*
 * `const Ctx_v53DC *c` lets the scheduler hoist the reload of c above the
 * bitfield store in the ret != -1 arm.
 */
/*
 * `const Ctx *c` lets the scheduler hoist the reload of c above the
 * bitfield store in the ret != -1 arm.
 */
int func_02206140(W_02206140 *p, const Ctx_v53DC *c, s8 (*rows)[12], u8 *list, int ret, int arg6)
{
    int keys;
    int cont;
    int done;
    s8 *row;
    int i;
    int k;
    int v;

    keys = func_020362DC();
    cont = func_0203630C();
    done = 0;
    if (p->b0 == 0)
        keys &= ~2;
    if (p->redraw) {
        p->redraw = 0;
        func_02206950((W_02206950 *)p);
        func_022064CC((W_022064CC *)p, (u8 (*)[4])c->tab, rows);
        func_0204B22C(p->f17c, 1);
    }
    v = -1;
    if (ret != v) {
        *p->f274 = 0;
        p->cur = 0;
        p->prev = 0xF;
        func_022064CC((W_022064CC *)p, (u8 (*)[4])c->tab, rows);
        return ret;
    }
    if (keys == 0)
        goto end;
    if (*p->f274 != 0) {
        v = -128;
        row = rows[p->cur];
        switch (keys) {
        case 0x40:
            v = row[6];
            break;
        case 0x80:
            v = row[7];
            break;
        case 0x20:
            v = row[8];
            break;
        case 0x10:
            v = row[9];
            break;
        case 2:
            k = row[11];
            if (k < 0) {
                if (p->b4 == 1)
                    v = (s8)-k;
            } else {
                v = k;
            }
            break;
        }
        if (keys == 1) {
            ret = row[10];
            if (ret < 4 && (cont & 0x200) && p->f58 == 5 && (arg6 == 1 || p->f220 == 1))
                goto draw;
            if (ret < 4 && (cont & 0x200) && p->f58 == 2 && arg6 == 1)
                goto draw;
            if (p->f25a[ret] == 1) {
                if (func_02206908((char *)p, (char *)c, ret) == 0)
                    func_02206B30((char *)p);
                else
                    func_02206B58((char *)p);
                done = 1;
            } else if (ret < 4 && (cont & 0x200) && p->f58 == 2 && p->f262[ret] == 1) {
                func_02206B30((char *)p);
            }
        } else if (v != -128) {
            func_02206B14((char *)p);
            if (v < 0) {
                if (-v != p->prev && p->prev != 0xF)
                    v = (s8)p->prev;
                else
                    v *= -1;
            } else if (v & 0x40) {
                i = 0;
                v &= ~0x40;
                for (; list[i] != 0xff; i++) {
                    if (p->prev == list[i]) {
                        v = (s8)p->prev;
                        break;
                    }
                }
            }
            p->prev = p->cur;
            p->cur = v;
            if (keys == 2) {
                if (v != 0xF)
                    func_02206B58((char *)p);
                ret = v;
                done = 1;
            }
        }
    } else if (keys & 0xcf3) {
        *p->f274 = 1;
        func_02206950((W_02206950 *)p);
        func_02206B14((char *)p);
    }
draw:
    func_022064CC((W_022064CC *)p, (u8 (*)[4])c->tab, rows);
end:
    if (done == 1) {
        switch (p->f58) {
        case 2:
            if (func_02206908((char *)p, (char *)c, p->cur) == 0)
                p->f266[p->f27c] = p->f26c[p->cur];
        case 1:
        case 5:
            if (func_02206908((char *)p, (char *)c, p->cur) == 0)
                p->tbl[p->f27c][p->f58] = p->cur;
            p->b1 = 1;
            break;
        case 3:
            if (func_02206908((char *)p, (char *)c, ret) == 0)
                p->tbl[p->f27c][p->f58] = p->cur | (p->tbl[p->f27c][2] << 4);
            p->b1 = 1;
            break;
        }
        p->cur = 0;
        p->prev = 0xF;
        p->redraw = 1;
        func_0204B22C(p->f17c, 0);
    }
    return ret;
}






int func_0220648C(char *p)
{
    u32 k = func_0203633C();

    if (k & 2) {
        func_02206B58(p);
        return 2;
    }
    if (k & 0x20) {
        func_02206B30(p);
        return 0;
    }
    if (k & 0x10) {
        func_02206B30(p);
        return 1;
    }
    return -1;
}










/*
 * The table parameter is `__restrict`: with it the scheduler hoists the y
 * load above the x store in cases 2..5 (e[1] vs pos.x) but not in cases 0/1
 * (e[0] vs pos.x, same offset), which is the original's mixed schedule.
 */
void func_022064CC(W_022064CC *p, u8 (* __restrict tab)[4], s8 (*rows)[12])
{
    Point_022064CC pos;
    u8 *e;
    int k;
    int i;

    for (i = 0; i < 6; i++) {
        k = rows[p->sel][i];
        if (k >= 0) {
            e = tab[k];
            switch (i) {
            case 0:
                pos.x = e[2];
                pos.y = e[0];
                break;
            case 1:
                pos.x = e[3];
                pos.y = e[0];
                break;
            case 2:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 3:
                pos.x = e[3];
                pos.y = e[1];
                break;
            case 4:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 5:
                pos.x = e[3];
                pos.y = e[1];
                break;
            }
            func_0204B3DC(p->slots[i].h, *p->f274);
            func_0204B404((struct Obj_02201DA0 *)(p->slots[i].h), (const struct Vec2 *)(&pos), 1);
        } else {
            func_0204B3DC(p->slots[i].h, 0);
        }
    }
}










int func_02206578(char *s, int a, int b)
{
    Ctx_022064CC *c;
    int flag;

    if (b < 0)
        return a;
    if ((func_0203630C() & 0x200) && a < 4 && (((struct Obj00823 *)s)->f58 == 2 || ((struct Obj00823 *)s)->f58 == 5))
        ((struct Obj00823 *)s)->f70 = a | 0x8000;
    else
        ((struct Obj00823 *)s)->f70 = a;
    c = func_02030734((u16)((((struct Obj00823 *)s)->f240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0x1440);
    flag = 0;
    if ((0x10000 & b) == 0)
        flag = 1;
    ((Top *)(s + 0x68))->top = flag;
    c->s = s;
    c->f4 = 0;
    c->f8 = (u16)b;
    if (((struct Obj00823 *)s)->f220 == 1 && c->f8 == 0)
        c->fc = 1;
    else
        c->fc = 0;
    func_0220684C(s, (int)func_02030DA8(((struct Obj00823 *)s)->f0, func_0220663C, c, 0), (int)((void *)func_02206710));
    return -1;
}









void func_0220663C(void *task, void *arg)
{
    Ctx_0220663C *c = arg;

    switch (c->state) {
    case 0:
        if (c->flag == 1)
            PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21789 *)(c->p))->f64, 8, 2, 0, 0, 8, 0x7fff, *(void **)c->p);
        else
            PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21791 *)(c->p))->f64, 2, c->colour, 0, 0, 8, 0x7fff, *(void **)c->p);
        c->state++;
        break;
    case 1:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj21793 *)(c->p))->f64) == 0) {
            if (c->flag == 1)
                PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21794 *)(c->p))->f64, 8, 2, 0, 8, 0, 0x7fff, *(void **)c->p);
            else
                PALANM_RequestFade(*(PalAnmObj * *)&((struct Obj21796 *)(c->p))->f64, 2, c->colour, 0, 8, 0, 0x7fff, *(void **)c->p);
            c->state++;
        }
        break;
    case 2:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj21798 *)(c->p))->f64) == 0)
            func_0220687C(c->p, task);
        break;
    }
}










void func_02206710(void *h)
{
    (*(W_02206710 * *)TCBL_IsDeletePending((struct S02030EE8 *)h))->f68 &= 0x7fffffff;
}










void func_02206728(char *s, char *b)
{
    int h;
    void *v;
    void *w;
    int v18;
    int v14;
    u8 c[3];

    if (func_021F88F4() == 0)
        return;
    h = (int)func_0201EC64(((struct Obj05249 *)s)->f240);
    v = STRBUF_Create(6, ((struct Obj05249 *)s)->f240);
    w = func_02045EC0(((struct Obj05249 *)s)->f5C, 8);
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    GF_FONT_SetTextColor(1, 2, 0);
    func_0201EFA4((u32)((struct WordSet *)h), 0, ((struct Obj21799 *)b)->fC4, 2, 0, 1);
    func_0201F250((struct WordSet *)h, v, w);
    func_02204C98((struct StrObj *)v, ((struct Obj05249 *)s)->f224, &v18, &v14);
    PRINTSYS_Print((void *)(((struct Obj05249 *)s)->f234), 12 - v18 / 2, 0, v, (void *)(((struct Obj05249 *)s)->f224));
    GF_FONT_SetTextColor(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    STRBUF_Delete(w);
    STRBUF_Delete(v);
}










void func_022067E8(char *p)
{
    func_021F8AC0(2);
    func_021F8554((u32)(((struct Obj21800 *)p)->f278), 1, 10, 0, 8);
}










void func_0220680C(char *p)
{
    int a = func_02207D78((char *)func_021F86B4(), ((struct Obj10159 *)p)->f278);
    int b = func_022005C4((Work_022005C4 *)((void *)func_021F8694()), ((struct Obj10159 *)p)->f278);
    int i;

    if ((b | a) == 1) {
        for (i = 0; i < 8; i++)
            *(char *)(p + ((struct Obj10159 *)p)->f27C * 8 + i + 0x242) = 0;
    }
}










void func_0220684C(char *p, int a, int b)
{
    int i = func_022068C4(p);

    *(int *)(p + i * 4 + 8) = a;
    *(int *)(p + i * 4 + 0x28) = b;
}









/*
 * lane S13 leaf of func_0220687C
 */
int func_02206864(char *p, int v)
{
    int i;
    int x;

    for (i = 0; i < 8; i++) {
        x = *(int *)(p + i * 4 + 8);
        if (x == v)
            break;
    }
    return i;
}










void func_0220687C(char *p, void *q)
{
    int i = func_02206864(p, (int)q);
    int off;

    if (q != 0) {
        void *r = (void *)(W_02206710 * *)TCBL_IsDeletePending((struct S02030EE8 *)q);
        char *t = p + 0x28;
        void (*cb)(void *);

        off = i * 4;
        cb = *(void (**)(void *))(t + off);
        if (cb != 0)
            cb(q);
        if (r != 0)
            func_020307B0(r);
        func_02030EAC(q);
        *(int *)(p + off + 8) = 0;
        *(int *)(t + off) = 0;
    }
}










int func_022068C4(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (*(int *)(p + 8 + i * 4) == 0)
            break;
    }
    if (i == 8) {
        func_0220687C(p, (void *)(((struct Obj18616 *)p)->f8));
        i = 0;
    }
    return i;
}










void func_022068E8(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        int v = *(int *)(p + 8 + i * 4);

        if (v != 0)
            func_0220687C(p, (void *)v);
    }
}










int func_02206908(char *p, char *q, int i)
{
    int r;

    if (!((Bf_022064CC *)(p + 0x68))->b4 || ((struct Obj00823 *)p)->f58 != 1)
        return 1 & ((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i];
    r = (((int *)*(int * *)&((struct Obj04404 *)q)->f4)[i] & 2) >> 1;
    if (r == 1)
        *(char *)(p + ((struct Obj00823 *)p)->f27C * 8 + 0x242 + ((struct Obj00823 *)p)->f58) = 0;
    return r;
}










void func_02206950(W_02206950 *p)
{
    u8 b;

    switch (p->f58) {
    case 2:
        if (p->a266[p->k] != p->a26c[p->row[p->k][p->f58]])
            p->row[p->k][3] = 0;
    case 1:
    case 5:
        p->sel = p->row[p->k][p->f58];
        break;
    case 3:
        b = p->row[p->k][p->f58];
        if (((b & 0xf0) >> 4) == p->row[p->k][2])
            p->sel = b;
        else
            p->sel = 0;
        break;
    default:
        p->sel = 0;
        break;
    }
}










void func_02206A14(char *p)
{
    u16 buf[16];

    if ((int)BTL_MAIN_GetCompetitor((void ***)func_021F8754()) != 4 && func_021F8914() == 0) {
        PALANM_BlendColors((u16 *)(p + 0x284), buf, 0x10, 8, 0);
        PALANM_CopyToSlot((struct PalAnmSlot *)func_021F86E0(), buf, 1, 0x20, 0x20);
    }
}










void func_02206A58(char *p)
{
    if (((struct Obj21803 *)p)->f23C == 1)
        PALANM_CopyToSlot((struct PalAnmSlot *)func_021F86E0(), (u16 *)(p + 0x284), 1, 0x20, 0x20);
}










int func_02206A7C(char *p)
{
    if (!((Bf_022064CC *)(p + 0x68))->b4) {
        if (((struct Obj06328 *)p)->f50 == 2) {
            if (func_021F88A8() == 1) {
                if (((struct Obj06328 *)p)->f278 == 4)
                    return 0x65;
                return 0x5f;
            }
            if (((struct Obj06328 *)p)->f278 == 4)
                return 0x5d;
            return 0x5e;
        }
        if (func_021F88A8() == 1)
            return 0x65;
        return 0x5d;
    }
    if (((struct Obj06328 *)p)->f50 == 2 && ((struct Obj06328 *)p)->f278 != 4) {
        if (func_021F88A8() == 1)
            return 0x67;
        return 0x61;
    }
    if (func_021F88A8() == 1)
        return 0x66;
    return 0x60;
}










void func_02206AF8(char *p)
{
    if (((struct Obj13619 *)p)->f54 != 3 || ((struct Obj13619 *)p)->f58 == 6)
        func_020061E4(0x555);
}









void func_02206B14(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x548);
}









/*
 * lane S13 leaf of func_0220648C
 */
void func_02206B30(char *p)
{
    if (((struct Obj00823 *)p)->f58 != 6) {
        if (((struct Obj00823 *)p)->f54 != 3) {
            func_020061E4(0x54d);
        }
    } else {
        func_020061E4(0x54c);
    }
}









/*
 * lane S13 leaf of func_022064CC-area callers (func_0220648C)
 */
void func_02206B58(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x552);
}









void func_02206B74(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x579);
}








void func_02206B90(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x54d);
}








void func_02206BAC(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x557);
}









Obj_02206BC8 *func_02206BC8(int a, u16 heap)
{
    char *hdr;
    Pt_02206BC8 pos;
    Pt_02206BC8 base;
    Obj_02206BC8 *s;
    int i;
    void *arc;
    Task_v64CC *t;
    int lo, hi, kind;

    s = func_02030734(heap, sizeof(Obj_02206BC8), 1, d_0220AEC0, 0x14b);
    s->heap = heap;
    s->h04 = func_020490F4(0xb, (u16)s->heap);
    s->f00 = CLACT_CreateUnit(0x28, 0, s->heap);
    for (i = 0; i < 6; i++) {
        s->f18[i] = CLACT_RegisterPalette(s->h04, 0xa2, 0, (u16)(i * 0x20), s->heap);
        PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f18[i], 0) >> 1), 0x20);
    }
    arc = func_020490F4(func_020275E4(), (u16)((s->heap & 0x7fff) | 0x8000));
    s->f30 = CLACT_RegisterCharacter(arc, func_020276B8(), 0, 0, s->heap);
    s->f34 = CLACT_RegisterCellAnim(arc, func_020276BC(1), func_020276C0(1), s->heap);
    s->f38 = CLACT_RegisterPalette(arc, func_020276B4(), 0, 0x100, s->heap);
    s->f3c = CLACT_RegisterPalette(arc, func_020276B4(), 0, 0x120, s->heap);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f38, 0) >> 1), 0x20);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(s->f3c, 0) >> 1), 0x20);
    PALANM_BlendChannelMask((unsigned)func_021F86E0(), 2, 0x200, 8, 0);
    ARC_TOOL_DeleteHandle(arc);
    s->f10 = func_02049E74((void *)s->h04, 0xa4, 0, (u32)(&hdr), s->heap);
    s->f14 = ((struct Obj21804 *)hdr)->f14;
    s->f08 = a;
    s->f444 = GFL_USE_GetBgmNo();
    t = func_02030734(heap, sizeof(Task_v64CC), 1, d_0220AEC0, 0x185);
    t->obj = s;
    s->f0c = func_02030DA8(func_021F86D4(), func_02208BFC, t, 0);
    switch (func_021F8710()) {
    case 0:
        lo = 0;
        hi = 1;
        kind = 0;
        break;
    case 1:
        lo = 2;
        hi = 5;
        kind = 1;
        break;
    case 2:
    default:
        lo = 2;
        hi = 7;
        kind = 2;
        break;
    case 3:
        lo = 2;
        hi = 7;
        kind = 3;
        break;
    }
    for (i = lo; i <= hi; i++) {
        base = d_0220AABC;
        pos = base;
        if (i & 1)
            pos.x *= -1;
        func_02207430((Work_v64CC *)((Obj_02206BC8 *)s), kind, i);
        s->slot[i].kind = kind;
        func_022079C0((char *)((Obj_02206BC8 *)s), i, (Pt_021FB8F4 *)((Pt_02206BC8 *)&pos));
    }
    return s;
}









void func_02206E28(char *p)
{
    Slot_02206E28 i;
    int j;

    for (i = SLOT_6E28_0; i < SLOT_6E28_MAX; i++) {
        func_02207960(p, i);
        func_0220778C((Work_022064CC *)p, i);
    }
    if (((Bf_02206BC8 *)(p + 0x440))->b2) {
        GFL_USE_PopBgm();
        func_02208D24(0);
    }
    for (j = 0; j < 6; j++)
        CLACT_ReleasePalette(*(int *)(p + j * 4 + 0x18));
    CLACT_ReleaseCharacter(((struct Obj00380 *)p)->f30);
    CLACT_ReleaseCellAnim(((struct Obj00380 *)p)->f34);
    CLACT_ReleasePalette(((struct Obj00380 *)p)->f38);
    CLACT_ReleasePalette(((struct Obj00380 *)p)->f3C);
    CLACT_DeleteUnit((struct Bank *)((int)((struct Bank *)(((struct Obj00380 *)p)->f0))));
    func_020307B0(((struct Obj00380 *)p)->f10);
    ARC_TOOL_DeleteHandle((void *)(((struct Obj00380 *)p)->f4));
    func_020307B0((void *)(u32)(W_02206710 * *)TCBL_IsDeletePending((struct S02030EE8 *)(((struct Obj00380 *)p)->fC)));
    func_02030EAC(((struct Obj00380 *)p)->fC);
    func_020307B0(p);
}







/*
 * lever: int mode, i, found puts the scan index in r0 and found in r1; mode, found, i differed at seven bytes.
 */
void func_02206EB4(W_02206BC8 *p)
{
    int mode, i, found;
    func_020362DC();
    if (p->flags.b22) {
        mode = func_021F8710();
        p->flags.b22 = 0;
        if (mode != 0 && mode != 1) {
            found = 0;
            for (i = 0; i < 8; i++) {
                if (p->rows[i].b0) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                p->flags.b4 ^= 1;
                for (i = 0; i < 8; i++) {
                    if (!(i & 1) && p->rows[i].b29 == 1 && p->rows[i].b3) {
                        func_02208D50((W_02206BC8 *)p, i, 1);
                        func_02207F6C(p->rows[i].b, p->rows[i].a, 0, &p->rows[i].f90, 6, 1);
                        func_022082FC((struct O_022064CC *)((O_022064CC *)p), i, 0);
                    }
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (p->rows[i].b0)
            func_02207E1C((struct O_022064CC *)((O_022064CC *)p), i);
        if (p->rows[i].b1) {
            if (p->rows[i].count == 0)
                func_020061E4(0x56d);
            func_02207EF0((struct O_022064CC *)((O_022064CC *)p), i);
        }
        if (p->rows[i].b28) {
            if (p->rows[i].count < 16)
                p->rows[i].count++;
            if (!p->rows[i].b1 && p->rows[i].count == 16) {
                GFL_USE_StopAllSe();
                p->rows[i].count++;
                p->rows[i].b28 = 0;
            }
        }
        if (p->rows[i].b2)
            func_022086F8((O_022064CC *)p, i);
        if (p->rows[i].b20)
            func_022087C4((char *)p, i);
        if (p->rows[i].h != 0 && p->rows[i].b26) {
            if (p->rows[i].flash == 0 || !p->rows[i].b3 || !p->rows[i].b29) {
                func_0204B3DC((struct Obj *)((struct Obj_02206EB4 *)(p->rows[i].h)), 0);
                p->rows[i].b26 = 0;
            } else {
                func_0204B3DC((struct Obj *)((struct Obj_02206EB4 *)(p->rows[i].h)), p->rows[i].flash & 1);
                p->rows[i].flash--;
            }
            if (p->flags.b4 && !(i & 1))
                func_0204B3DC((struct Obj *)((struct Obj_02206EB4 *)(p->rows[i].h)), 0);
        }
    }
    if (!p->flags.b21)
        func_022089D4((W_02206BC8 *)p);
}







/*
 * trailing: 02207286..02207288 is two zero alignment bytes.
 *
 * Battle-side twin of func_02207288 (same row layout).
 *
 * lever: BTL_POKEPARAM_GetSickContRaw returns a one-word struct (Word) passed by value to
 * BTLV_CORE_IsSlotKind1Index15, as in the ov093 callers. The struct-return temporary
 * reserves the extra frame word (push r3, sub sp #0x28, slot sp+0x24 never
 * touched) and that one change also flips the row stores to share p + i*0x80
 * in a scratch register; with int prototypes both residues remained
 * (2026-10-01 note: Row pointer local, char* offsets, inline helpers,
 * nested sub-struct, u8 index, x/y locals were all inert).
 */
void func_022070C0(W_022070C0 *p, void *a, void *q, int mode, int i)
{
    u32 exp;
    u16 species;
    int item;

    func_02082A48(0, &p->rows[i].mode, 0x40);
    p->rows[i].a = func_021D59B4(q, 0xd);
    p->rows[i].b = func_021D59B4(q, 0xe);
    p->rows[i].f90 = 0x80000000;
    p->rows[i].fa8 = 0;
    p->rows[i].level = func_021D59B4(q, 0xf);
    p->rows[i].mode = mode;
    p->rows[i].side = i & 1;
    p->rows[i].flags |= 0x08000000;
    if (p->rows[i].level < 100) {
        exp = func_02018584(BTL_POKEPARAM_GetSpecies(q), func_021D59B4(q, 0x13), func_021D59B4(q, 0xf));
        p->rows[i].f94 = func_021D59B4(q, 0x14) - exp;
        p->rows[i].f98 = func_02018584(BTL_POKEPARAM_GetSpecies(q), func_021D59B4(q, 0x13), func_021D59B4(q, 0xf) + 1) - exp;
    } else {
        p->rows[i].f94 = 0;
        p->rows[i].f98 = 0;
    }
    p->rows[i].fa4 = 0x80000000;
    p->rows[i].fa0 = 0;
    p->rows[i].fae = 0;
    p->rows[i].seen = BTL_MAIN_CheckZukanSeen(a, q);
    species = BTL_POKEPARAM_GetSpecies(q);
    if (species != 32 && species != 29)
        p->rows[i].sex = POKE_TOOL_GetGender(BTL_POKEPARAM_GetDisplayMon(q));
    else
        p->rows[i].sex = 2;
    if (BTLV_CORE_IsSlotKind1Index15(BTL_POKEPARAM_GetSickContRaw(q, 5)) == 1 && BTL_POKEPARAM_GetMajorStatusIndex(q) == 5)
        item = 6;
    else
        item = BTL_POKEPARAM_GetMajorStatusIndex(q);
    func_02208814((struct O *)((struct O_022064CC *)((O_022064CC *)p)), item, i);
    func_022079C0((char *)((Obj_02206BC8 *)((char *)p)), i, (Pt_021FB8F4 *)((Pt_02206BC8 *)0));
    func_02208D50((W_02206BC8 *)p, i, 1);
    func_0220793C((char *)((S *)&p->rows[i]));
    func_0220785C((O_0220778C *)((struct O_022064CC *)p), mode, i, BTL_POKEPARAM_GetDisplayMon(q));
}





/*
 * trailing: 0220742E..02207430 is two zero alignment bytes.
 * lever: rows are an array member of the object; raw offset casts gave 416 bytes and the wrong field-base spills, while the member form gives exact 422 bytes.
 */
void func_02207288(W_02207288 *p, void *a, void *q, int mode, int i)
{
    u32 x, y, exp;
    u16 species;
    func_02082A48(0, &p->rows[i].mode, 0x40);
    p->rows[i].a = func_02017E1C(q, 0xa0, 0);
    p->rows[i].b = func_02017E1C(q, 0xa1, 0);
    p->rows[i].f90 = 0x80000000;
    p->rows[i].fa8 = 0;
    p->rows[i].level = func_02017E1C(q, 0x9e, 0);
    p->rows[i].mode = mode;
    p->rows[i].side = i & 1;
    p->rows[i].flags |= 0x08000000;
    if (p->rows[i].level < 100) {
        x = func_02017E1C(q, 5, 0);
        y = func_02017E1C(q, 0x6f, 0);
        exp = func_02018584(x, y, p->rows[i].level);
        p->rows[i].f94 = func_02017E1C(q, 8, 0) - exp;
        p->rows[i].f98 = func_02018584(x, y, p->rows[i].level + 1) - exp;
    } else {
        p->rows[i].f94 = 0;
        p->rows[i].f98 = 0;
    }
    p->rows[i].fa4 = 0x80000000;
    p->rows[i].fa0 = 0;
    p->rows[i].fae = 0;
    species = func_02017E1C(q, 5, 0);
    p->rows[i].seen = func_0200CED4(a, species);
    if (species != 32 && species != 29)
        p->rows[i].sex = POKE_TOOL_GetGender(q);
    else
        p->rows[i].sex = 2;
    func_02208814((struct O *)((struct O_022064CC *)((O_022064CC *)p)), POKE_TOOL_GetStatusCondition(q), i);
    func_022079C0((char *)((Obj_02206BC8 *)((char *)p)), i, (Pt_021FB8F4 *)((Pt_02206BC8 *)0));
    func_02208D50((W_02206BC8 *)((W_02207288 *)p), i, 1);
    func_0220793C((char *)((S *)&p->rows[i]));
    func_0220785C((O_0220778C *)((struct O_022064CC *)p), mode, i, q);
}





void func_02207430(Work_v64CC *p, int mode, int i)
{
    int chr, pal, cell, cpal, j, n, side;
    Cfg cfg;
    switch (mode) {
    case 0:
    case 1:
    default:
        chr = (i & 1) ? 0xa5 : 0xa8;
        pal = (i & 1) ? 0xa6 : 0xa9;
        cell = (i & 1) ? 0xa7 : 0xaa;
        break;
    case 2:
    case 3:
        chr = (i & 1) ? 0xab : 0xae;
        pal = (i & 1) ? 0xac : 0xaf;
        cell = (i & 1) ? 0xad : 0xb0;
        break;
    case 4:
        break;
    }
    if (mode == 3) {
        j = i;
        if (i >= 2)
            j = i - 2;
        cpal = (i < 4) ? 0xa2 : 0xa3;
        CLACT_ReleasePalette(p->pal[j]);
        p->pal[j] = CLACT_RegisterPaletteEx((void *)p->f4, cpal, 0, (u16)(j << 5), 0, 1, p->heap);
        PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(p->pal[j], 0) >> 1), 0x20);
    }
    p->entries[i].f58 = CLACT_RegisterCharacter((void *)p->f4, chr, 0, 0, p->heap);
    p->entries[i].f5c = CLACT_RegisterCellAnim((void *)p->f4, pal, cell, p->heap);
    p->entries[i].f60 = CLACT_RegisterCharacter((void *)p->f4, 0xba, 0, 0, p->heap);
    p->entries[i].f64 = CLACT_RegisterCellAnim((void *)p->f4, 0xbb, 0xbc, p->heap);
    p->entries[i].f68 = CLACT_RegisterCharacter((void *)p->f4, 0xb1, 0, 0, p->heap);
    p->entries[i].f6c = CLACT_RegisterCellAnim((void *)p->f4, 0xb2, 0xb3, p->heap);
    p->entries[i].f70 = CLACT_RegisterCharacter((void *)p->f4, 0xb4, 0, 0, p->heap);
    p->entries[i].f74 = CLACT_RegisterCellAnim((void *)p->f4, 0xb5, 0xb3, p->heap);
    side = i & 1;
    if (side == 0) {
        p->entries[i].f78 = CLACT_RegisterCharacter((void *)p->f4, 0xb7, 0, 0, p->heap);
        p->entries[i].f7c = CLACT_RegisterCellAnim((void *)p->f4, 0xb8, 0xb9, p->heap);
    }
    cfg = d_0220AAC8;
    j = i;
    if (i >= 2)
        j = i - 2;
    n = (7 - i) * 3;
    cfg.pri = n + 2;
    p->entries[i].f40 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f58, p->pal[j], p->entries[i].f5c, &cfg, 0, p->heap);
    cfg.pri = n + 1;
    p->entries[i].f44 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f60, p->pal[j], p->entries[i].f64, &cfg, 0, p->heap);
    p->entries[i].f48 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f68, p->pal[j], p->entries[i].f6c, &cfg, 0, p->heap);
    if (func_021F8710() == 3 && i >= 4)
        p->entries[i].f54 = (u32)CLACT_CreateActor((void *)p->f0, p->f30, p->f3c, p->f34, &cfg, 0, p->heap);
    else
        p->entries[i].f54 = (u32)CLACT_CreateActor((void *)p->f0, p->f30, p->f38, p->f34, &cfg, 0, p->heap);
    func_0204B92C((struct Obj *)p->entries[i].f54, 1);
    cfg.pri = n;
    p->entries[i].f4c = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f70, p->pal[j], p->entries[i].f74, &cfg, 0, p->heap);
    func_0204B3DC((struct Obj *)p->entries[i].f4c, 0);
    if (side == 0 && mode != 2 && mode != 3)
        p->entries[i].f50 = (u32)CLACT_CreateActor((void *)p->f0, p->entries[i].f78, p->pal[j], p->entries[i].f7c, &cfg, 0, p->heap);
}




/*
 * extent: two zero bytes at 0220785A align the next function.
 * lever: indexed entries in the owning structure retain per-field bases;
 *   a raw offset or cast Entry_v778C array caches the element and is 138/144 bytes.
 */
void func_0220778C(Work_022064CC *p, int i)
{
    if (p->entries[i].f40 == 0)
        return;
    CLACT_ReleaseCharacter(p->entries[i].f58);
    CLACT_ReleaseCharacter(p->entries[i].f60);
    CLACT_ReleaseCharacter(p->entries[i].f68);
    CLACT_ReleaseCharacter(p->entries[i].f70);
    CLACT_ReleaseCellAnim(p->entries[i].f5c);
    CLACT_ReleaseCellAnim(p->entries[i].f64);
    CLACT_ReleaseCellAnim(p->entries[i].f6c);
    CLACT_ReleaseCellAnim(p->entries[i].f74);
    CLACT_DeleteActor(p->entries[i].f40);
    CLACT_DeleteActor(p->entries[i].f44);
    CLACT_DeleteActor(p->entries[i].f48);
    CLACT_DeleteActor(p->entries[i].f4c);
    CLACT_DeleteActor(p->entries[i].f54);
    p->entries[i].f40 = 0;
    p->entries[i].f44 = 0;
    p->entries[i].f48 = 0;
    p->entries[i].f4c = 0;
    p->entries[i].f54 = 0;
    if ((i & 1) == 0) {
        CLACT_ReleaseCharacter(p->entries[i].f78);
        CLACT_ReleaseCellAnim(p->entries[i].f7c);
    }
    if (p->entries[i].f50 != 0) {
        CLACT_DeleteActor(p->entries[i].f50);
        p->entries[i].f50 = 0;
    }
}




void func_0220785C(O_0220778C *o, int unused, int idx, void *data)
{
    func_02207F6C(o->e[idx].f4c, o->e[idx].f48, 0, &o->e[idx].f50, 6, 1);
    func_022082FC((struct O_022064CC *)o, idx, 0);
    if (o->e[idx].f10 != 0) {
        func_02207F6C(o->e[idx].f58, o->e[idx].f54, 0, &o->e[idx].f64, 10, 1);
        func_022082FC((struct O_022064CC *)o, idx, 1);
    }
    func_022080F4((O_0220778C *)o, (E_022064CC *)(&o->e[idx]), data);
    func_02208268((O_0220778C *)o, (E_022064CC *)(&o->e[idx]));
    func_02208420((O_0220778C *)o, (E_022064CC *)(&o->e[idx]), o->e[idx].f48);
    func_02208550((O_0220778C *)o, (E_022064CC *)(&o->e[idx]));
    if (o->e[idx].f44 != 0 && func_021F8720() == 0)
        func_02208650((O_0220778C *)o, (E_022064CC *)(&o->e[idx]));
    o->e[idx].b3 = 1;
    o->e[idx].mode = 2;
    o->e[idx].f7c = func_02030DA8(func_021F86D4(), func_02208B10, &o->e[idx], 0);
}





void func_0220793C(char *p)
{
    int a = ((struct Obj00974 *)p)->f48;
    int b = ((struct Obj00974 *)p)->f4C;

    if (b < 0x30)
        ((struct Obj00974 *)p)->f78 = (unsigned int)func_02208D38(a << 8, b, 0x30) >> 8;
    else
        ((struct Obj00974 *)p)->f78 = (unsigned int)func_02208D38(a, b, 0x30);
}





void func_02207960(char *p, int i)
{
    char *q = p + 0xb0;
    int o = i * 128;
    void *t;

    if (((Bf *)(q + o))->b3) {
        Pt_0220778C pt = d_0220AAB4;

        if (i & 1)
            pt.x *= -1;
        func_022079C0((char *)((Obj_02206BC8 *)p), i, (Pt_021FB8F4 *)((Pt_02206BC8 *)&pt));
        ((Bf *)(q + o))->b3 = 0;
    }
    t = *(void **)(p + o + 0xbc);
    if (t != 0) {
        func_02030EAC(t);
        *(int *)(p + o + 0xbc) = 0;
    }
}
