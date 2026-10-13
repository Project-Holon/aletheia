/*
 * file:     gsync_state.c
 * unit:     yes
 * function: func_021D4240, func_021D4244, func_021D424C, func_021D4384, func_021D43B8, func_021D4440, func_021D449C, func_021D44F4, func_021D451C, func_021D45F0, func_021D45F4, func_021D4730, func_021D4778, func_021D478C, func_021D4884, func_021D4A04, func_021D4A64, func_021D4AB4, func_021D4AFC, func_021D4B44, func_021D4BA8, func_021D4C24, func_021D4C4C, func_021D4CA0, func_021D4CBC, func_021D4D40, func_021D4DA4, func_021D4E34, func_021D4E64, func_021D4E7C, func_021D4EF0, func_021D4FAC, func_021D4FB8, func_021D4FEC, func_021D5020, func_021D504C, func_021D50F8, func_021D5120, func_021D5128, func_021D5320, func_021D53D0, func_021D54E0, func_021D54F4, func_021D562C, func_021D5644, func_021D56FC, func_021D57B8, func_021D57D0, func_021D580C, func_021D584C, func_021D5890, func_021D5950, func_021D5960, func_021D59E4, func_021D5A60, func_021D5A7C, func_021D5AB0, func_021D5AC0, func_021D5B10, func_021D5B70, func_021D5BA0, func_021D5BA8, func_021D5BD4, func_021D5C0C, func_021D5C2C, func_021D5C64, func_021D5C9C, func_021D5CAC, func_021D5CF8, func_021D5D24, func_021D5D58, func_021D5D7C, func_021D5D8C, func_021D5D94, func_021D5E60, func_021D5E8C, func_021D5F4C, func_021D60F8, func_021D614C, func_021D62A8, func_021D62B4, func_021D62BC, func_021D62D0, func_021D62E0, func_021D62F8, func_021D634C, func_021D63D4, func_021D63E4, func_021D6404, func_021D6458, func_021D651C, func_021D652C, func_021D6548, func_021D65F4, func_021D6650, func_021D6678, func_021D66D0, func_021D6720, func_021D679C, func_021D67B4, func_021D6830, func_021D6934, func_021D6A70, func_021D6AA8, func_021D6AB8, func_021D6C48, func_021D6C90, func_021D6CD8, func_021D6D5C, func_021D6E08, func_021D6E70, func_021D6EA4, func_021D6EBC, func_021D6EE0, func_021D6EE8, func_021D6F04, func_021D6F44, func_021D6F70, func_021D6FF0, func_021D706C, func_021D7088, func_021D70BC, func_021D7130, func_021D7180, func_021D7204, func_021D7224, func_021D72D8, func_021D7390, func_021D73D8, func_021D7430, func_021D746C, func_021D751C, func_021D7560, func_021D758C, func_021D75D0, func_021D768C, func_021D76B8, func_021D76F0, func_021D7798, func_021D77C4, func_021D7858, func_021D78C0, func_021D7910, func_021D7960, func_021D79A4, func_021D7A18, func_021D7A5C, func_021D7B68, func_021D7BDC, func_021D7C54, func_021D7CB4, func_021D7CEC, func_021D7D18, func_021D7DE8, func_021D7E20, func_021D7E58, func_021D7F5C, func_021D7F9C, func_021D80B8, func_021D8130, func_021D8154, func_021D81B4, func_021D81E4, func_021D8210, func_021D8244, func_021D8270, func_021D8304, func_021D834C, func_021D83A4, func_021D83C8, func_021D840C, func_021D8448, func_021D8490, func_021D8520, func_021D8590, func_021D85C4, func_021D85F0, func_021D8624, func_021D8650, func_021D8790, func_021D87F8, func_021D885C, func_021D88A0, func_021D88C0, func_021D8958, func_021D8A38, func_021D8A7C, func_021D8A9C, func_021D8B0C, func_021D8B7C, func_021D8C04, func_021D8D08, func_021D8D98, func_021D8DFC, func_021D8E28, func_021D8E68, func_021D8E98, func_021D8EC4, func_021D8F3C, func_021D8F58, func_021D8FBC, func_021D9158, func_021D920C, func_021D92B8, func_021D92CC, func_021D9404, func_021D941C, func_021D9514, func_021D95B4, func_021D95F0, func_021D9634, func_021D9670, func_021D9730, func_021D97B0, func_021D97CC, func_021D9844, func_021D9918, func_021D9958, func_021D9A14, func_021D9A1C, func_021D9AE8, func_021D9D34, func_021D9D3C, func_021D9F40, func_021D9FB0, func_021D9FD4, func_021DA034, func_021DA03C, func_021DA054, func_021DA090, func_021DA0B8, func_021DA0E4, func_021DA110, func_021DA138, func_021DA16C, func_021DA1A0, func_021DA1C8, func_021DA1EC, func_021DA244, func_021DA268, func_021DA290, func_021DA2DC, func_021DA308, func_021DA328, func_021DA3A0, func_021DA408, func_021DA434, func_021DA45C, func_021DA478, func_021DA54C
 * address:  0x021D4240
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021DA690 0x021DA690 data a4
 *   d_021DA6B0 0x021DA6B0 data a4
 *   d_021DA6D0 0x021DA6D0 data a4
 *   d_021DA6F0 0x021DA6F0 data a4
 *   d_021DA710 0x021DA710 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_020414EC 0x020414EC arm
 *   CLACT_ResetActorAnimCommand 0x0204BA10 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201DD68  0x0201DD68  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02049B40  0x02049B40  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021DA638 0x021DA638 data a1
 *   d_021DA634 0x021DA634 data a1
 *   d_021DA63C 0x021DA63C data a1
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   d_021DA9D0 0x021DA9D0 data a4
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   func_021DA9C0 0x021DA9C0 data a4
 *   d_021DA640 0x021DA640 data a4
 *   d_021DA648 0x021DA648 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_02012138 0x02012138 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0204BA00 0x0204BA00 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02041570 0x02041570 arm
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D534 0x0207D534 arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   TCBL_Create 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_020355D8 0x020355D8 arm
 *   d_021DA9F0 0x021DA9F0 data a4
 *   d_021DA680 0x021DA680 data a4
 *   d_021DA658 0x021DA658 data a4
 *   d_021DAA20 0x021DAA20 data a1
 *   func_02012204 0x02012204 thumb
 *   TCBL_Main 0x020310C4 arm
 *   func_02040618 0x02040618 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021DAA30 0x021DAA30 data a1
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0207D658 0x0207D658 arm
 *   func_0200F7DC 0x0200F7DC thumb
 *   func_02034714 0x02034714 arm
 *   d_021DAA40 0x021DAA40 data ov123 a1
 *   d_021DAA54 0x021DAA54 data ov123 a1
 *   g_021DAC20 0x021DAC20 data ov123 a4
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   func_021C5B80 0x021C5B80 arm ov114
 *   func_021C5928 0x021C5928 arm ov114
 *   d_021DAA58 0x021DAA58 data a1
 *   d_021DAA60 0x021DAA60 data a1
 *   STD_TSNPrintf 0x0208D80C arm
 *   func_021C5C04 0x021C5C04 arm ov114
 *   d_021DAA74 0x021DAA74 data a1
 *   func_021C5DB4 0x021C5DB4 arm ov114
 *   func_021C5C38 0x021C5C38 arm ov114
 *   func_021C5CFC 0x021C5CFC arm ov114
 *   func_021C5AB8  0x021C5AB8  arm  ov114
 *   ov067_id 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   d_021DAB68 0x021DAB68 data a1
 *   d_021DAA9C 0x021DAA9C data a4
 *   d_020A1464 0x020A1464 data a4
 *   d_021DAA78 0x021DAA78 data a4
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   d_021DA758 0x021DA758 data a4
 *   func_0207E3D0 0x0207E3D0 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DAACC 0x021DAACC data a4
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   d_021DA738 0x021DA738 data a4
 *   d_021DA748 0x021DA748 data a4
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   d_021DAA88 0x021DAA88 data a2
 *   func_02005624 0x02005624 thumb
 *   PMSI_PARAM_MakeSineTable 0x02024230 thumb
 *   _fflt 0x0209BDBC arm
 *   _f2d 0x0209BD38 arm
 *   _dmul 0x0209B2E8 arm
 *   _d2f 0x0209B64C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   d_021DA730 0x021DA730 data a2
 *   d_021DA750 0x021DA750 data a4
 *   d_021DA734 0x021DA734 data a2
 *   d_021DA740 0x021DA740 data a4
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_GetActorScale 0x0204B5C0 arm
 *   func_020056EC 0x020056EC thumb
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02062A98 0x02062A98 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02019D30 0x02019D30 thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_0207E51C 0x0207E51C arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   func_021B9774 0x021B9774 thumb ov114
 *   d_021DA844 0x021DA844 data a4
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   d_021DAB78 0x021DAB78 data a1
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_020093D4 0x020093D4 thumb
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_020092D0 0x020092D0 thumb
 *   func_020090F8 0x020090F8 thumb
 *   func_0203F1FC 0x0203F1FC arm
 *   func_02009108 0x02009108 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   func_0200734C 0x0200734C thumb
 *   func_0200E8E0 0x0200E8E0 thumb
 *   MUSICAL_DIST_SAVE_ProcessApply 0x0200C5F8 thumb
 *   d_021DAB88 0x021DAB88 data a1
 *   d_021DAB90 0x021DAB90 data a1
 *   d_021DAB9C 0x021DAB9C data a1
 *   MUSICAL_DIST_SAVE_GetBlockSize 0x0200C6E4 thumb
 *   func_02009390 0x02009390 thumb
 *   func_020093A8 0x020093A8 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_02009348 0x02009348 thumb
 *   func_0202A128 0x0202A128 thumb
 *   func_02019C90 0x02019C90 thumb
 *   func_02019D58 0x02019D58 thumb
 *   func_0202A19C 0x0202A19C thumb
 *   func_0200E0B0 0x0200E0B0 thumb
 *   func_0200E1A8 0x0200E1A8 thumb
 *   func_0202A170 0x0202A170 thumb
 *   func_020093D0 0x020093D0 thumb
 *   func_020092E0 0x020092E0 thumb
 *   SAVE_CONTROL_GetWorkArea 0x020071D8 thumb
 *   func_020093C8 0x020093C8 thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_0203F540 0x0203F540 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   GFL_NET_STATE_SetErrorMode 0x0203C938 arm
 *   func_020093D8 0x020093D8 thumb
 *   func_02009428 0x02009428 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_02009294 0x02009294 thumb
 *   func_021B9838  0x021B9838  thumb  ov114
 *   ov114_id 0x00000072 data
 *   func_020092EC 0x020092EC thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   d_021DABA4 0x021DABA4 data a1
 *   func_0200F7C0 0x0200F7C0 thumb
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   d_021DABA8 0x021DABA8 data ov123 a1
 *   STRBUF_Clear 0x0204581C arm
 *   STRBUF_AppendChar 0x02045AFC arm
 *   d_021DA868 0x021DA868 data a2
 *   d_021DA864 0x021DA864 data a2
 *   d_021DABFC 0x021DABFC data a1
 *   d_021DABCC 0x021DABCC data a4
 *   d_021DABBC 0x021DABBC data a4
 *   d_021DA8A8      0x021DA8A8  data
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   PALANM_BlendColors 0x02021F64 thumb
 *   func_020056A0 0x020056A0 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_02009448 0x02009448 thumb
 *   MUSICAL_DIST_SAVE_CreateFromData  0x0200C5C8  thumb  arm9
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb  arm9
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *   SAVE_CONTROL_LoadExtraSaveWithBuffer  0x020072CC  thumb  arm9
 *   WIH_DWC_PollStatus  0x0201058C  thumb  arm9
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb  arm9
 *   GAME_DATA_PartSaveStart  0x02012E4C  thumb  arm9
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb  arm9
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb  arm9
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb  arm9
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb  arm9
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb  arm9
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
#include "gsync_types.h"

struct Ctx;
struct Comm;
struct TaskMenu;
struct Actor;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Cfg;
struct CharBuf;
struct StrObj;
struct GfFont;
struct U16Vec;
struct Rec;
struct Cmd;
struct PalAnmSlot;
struct Chan02021FD8;
struct TaskMenuTmpl;
struct Rec3;
struct Big;
struct Sub020071E4Ctrl;
struct Obj0203159C;
struct Bank;
struct R;
struct Tcbl;
struct DispConfig;
struct DispVram;
struct IcaAnime;
struct PrintSys;
struct Node;
struct S02031140;
struct S020315D4;
struct TaskMenuState;
struct WordSet;
struct Blk;
struct Vec2;
struct PtS;
struct ArcFile;
struct NitroFileHeader;
struct Struct36;
struct Sub02009210Obj;
struct Sub02009448Obj;
struct Sub02007454Entry;
struct GsyncObj171;
struct Sub02007324Ctrl;
struct Sub020090B0Obj;
struct MusicalDist;
struct Sub02009210Ent;
struct Sub0200852CObj;
struct Ctrl020071D8;
struct Sub02008AECSession;
struct Sub02008C20Obj;
struct Mon;
struct Sub020079BCEntry;
struct Sav;
struct Sub020075B0Entry;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct BgTemplate_021D4240 {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
};

typedef struct {
    char pad00[8];
    int f08;
    u16 f0c;
    char pad0e[0x256];
    void *f264;
    char pad268[0x24];
    int f28c;
} Object_021D4440;

typedef short          s16_021D4240;

typedef struct {
    u32 a, b, c, d;
} Rec;

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 pad1[2];
    void *obj[4];
    void *res;
    void *bank;
    u8 pad2[8];
    void *font;
    u8 pad3[4];
    void *str;
    u8 pad4[0x25C - 0x3C];
    int n;
} Own;

typedef struct {
    char pad00[0x10];
    void *f10[4];
    void *f20;
    char pad24[0x238];
    int f25c;
} Object_021D4730;

typedef struct Callback Callback;

struct Callback { u32 first; int (*run)(void *,Callback *); };

struct Point_021D4240 { u16 x, y, z; u8 a, b; };

struct Triple { u8 v[3]; };

typedef signed int     s32;

typedef struct { u16 value; char *object; void (*callback)(char *); } NotifyCallback;

typedef struct { u32 heap; u8 mode; void *data; int flag; u8 a,b,c,d; } Descriptor;

typedef signed short   s16_021D4A04;

struct DispConfigWords { u32 words[4]; };

typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x,y,z,w; } Config;

typedef signed char s8;

typedef signed short s16;

typedef enum { C0 = 0 } Counter;

struct BgTemplate_021D5BD4 {
    u32 unk00, unk04, bufSize, unk0c;
    u8 unk10, unk11, unk12, unk13;
    u32 unk14;
    u8 unk18, unk19, unk1a, unk1b;
    u32 unk1c;
};

struct Point_021D5BD4 { s16 x, y; u16 f4; u8 f6, f7; };

typedef signed short s16_021D634C;

struct Point_021D634C { s16_021D634C x,y; u16 f4; u8 f6,f7; };

struct Entry { int x,y,n; };

struct Pair_021D634C { int a,b; };

struct Pos_021D634C { short x,y; };

typedef short s16_021D6830;

struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };

struct Pos_021D6830 { s16_021D6830 x,y; };

struct Pair_021D6830 { int x,y; };

struct Obj { u8 pad[0x40f4]; struct Record records[30]; };

typedef signed short s16_021D6A70;

typedef signed short s16_021D6AA8;

typedef struct { u32 x[9]; } Desc;

typedef signed short s16_021D6CD8;

struct Point_021D6830 { s16_021D6CD8 x,y; u16 f4; u8 f6,f7; };

struct Point { s16_021D634C x,y; u16 f4; u8 f6,f7; };

typedef struct { int x[8]; } Table_021D634C;

struct RtcDate_021D634C { int year; u32 month; int day, week; };

struct RtcDate_021D8A9C { u32 year, month, day, week; };

typedef unsigned long long u64;

typedef struct { u16 a[32]; } Table_021D8A9C;

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

typedef short s16_021D8A9C;

extern void func_0203FCA0(u32, const struct BgTemplate_021D4240 *, u32);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);
extern void TIME_ICON_Delete(u8 *);
extern u8 *TIME_ICON_CreateNode(u32,void *,u8,u8,u16);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern int GFL_NET_GetRunState(void);
extern u32 func_02012138(const struct Ctx *p);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void func_020414EC(u32 i);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void CLACT_ResetActorAnimCommand(struct Actor *a);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern int OS_IsRunOnTwl(void);
extern int func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201DD68(void);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_Print(void *x, s16_021D4240 y, s16_021D4240 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BUTTON_MAN_Delete(void *p);
extern void func_02041B6C(u32 bit);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *func_0201F5DC(void *, u32, u32, u32);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 GAME_COMM_GetKind(void *obj);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *p, int i);
extern void func_020862F0(void *, int);
extern void func_0207E5D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern int APP_TASKMENU_SetDisableKey(int a0, int a1);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern int TOUCHPANEL_GetCont(void);
extern signed char func_02012FFC(void);
extern void *PRINTSYS_PrintStream(void *, int, int, void *, void *, void *, void *, int, u16, int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02041570(int channel, u16 val);
extern int GAME_DATA_SaveMain(u8 *p);
extern int GAME_DATA_SaveStart(int a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void CLACT_VBlankSystem(void);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,u8,u32);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16 heapId);
extern void BMP_WIN_Init(u16);
extern void func_0201DD60(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020056A0(void *,void *,int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32,u32,u32,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *,int,int,int,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_020355D8(u8 v);
extern void APP_TASKMENU_UpdateMenu(void *);
extern u32 WIH_DWC_PollStatus(void *key);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void CLACT_DrawSystem(void);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 func_02012204(const struct Ctx *p);
extern void WIPE_SetBrightnessFadeOut(unsigned int,unsigned int);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern int APP_KEYCURSOR_Delete(int a0);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02028470(u8 *p, u32 v);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0200F7DC(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void DWC_RAP_SetErrorHookCallback(int a, int b);
extern int func_021C5B80(void);
extern int func_021C5928(void (*callback)(void *, u32, int), char *gamecd, char *passwd);
extern int STD_TSNPrintf(char *,int,const char *,...);
extern int func_021C5C04(char *attr1, char *attr2, char *attr3);
extern int func_021C5DB4(void);
extern int func_021C5C38(void *filelist, unsigned int offset, unsigned int num);
extern int func_021C5CFC(void *fileinfo, char *buf, unsigned int size);
extern void func_021C5AB8(void);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void func_0207E3D0(const void *, int, int);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern int func_0201BC3C(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 POKE_TOOL_GetGraphicIndex(void *mon);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void PMSI_PARAM_MakeSineTable(s16_021D634C *out, u32 count, u16 step, s32 amp);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair_021D634C *src);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_GetActorScale(const struct Obj *o, struct Pair_021D6830 *p);
extern u32 func_020056EC(u32 range);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern u32 func_02020E60(u16, int);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern u32 func_02019D30(u32 a, u32 n);
extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void func_0207E51C(void *,int,int);
extern u32 KEY_GetTrg(void);
extern void GAME_DATA_SaveCancel(char *p);
extern void func_021B9774(u8 *p);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 v);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern u32 func_020173EC(void);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern void *POKE_TOOL_GetBoxParam(void *p);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
extern void func_020093D4(struct Sub02009210Obj *obj, s32 value);
extern int func_020185F0(void *);
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern u8 *func_021B97F4(u8 *p);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B973C(char *p);
extern int func_021B9748(u8 *p);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void func_020092D0(struct Sub02009210Obj *obj, u8 value);
extern void func_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
extern int GAME_DATA_PartSaveMain(char *p, int a1);
extern void func_0200734C(struct Sub02007324Ctrl *,unsigned int);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090F8(struct Sub020090B0Obj *obj, unsigned char value);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern int SAVE_CONTROL_LoadExtraSaveWithBuffer(int,int,u16,int,int);
extern void func_0200E8E0(void *obj, u32 value);
extern void GAME_DATA_PartSaveStart(u8 *,u32);
extern void func_02009108(struct Sub020090B0Obj *obj, u16 value);
extern u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *p);
extern struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *sys, const void *src, u32 size, u32 heap);
extern u32 MUSICAL_DIST_SAVE_GetBlockSize(void);
extern u32 func_0200E8B0(void);
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_020093A8(struct Sub02009210Obj *obj, int i, const void *src);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
extern void *func_0202A128(int);
extern int func_02019C90(u16, int, int);
extern int func_02019D58(u16, int);
extern int func_0202A19C(u32, void *, u16, u16, int);
extern void *func_0200E0B0(void *);
extern void func_0200E1A8(void *, u16, u16, u8, int, u8, u32);
extern void func_0202A170(void *);
extern s32 func_020093D0(const struct Sub02009210Obj *obj);
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern void func_020092E0(struct Sub02009210Obj *obj, u8 value);
extern u8 *func_02012944(void *p);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void *SAVE_CONTROL_GetWorkArea(struct Ctrl020071D8 *ctrl, int *out);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_02008BD0(const struct Sub02008AECSession *s);
extern u32 func_020093C8(const struct Sub02009210Obj *obj);
extern void func_0203F4E4(struct RtcDate_021D634C *);
extern int func_0203F540(struct RtcDate_021D634C *);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern u32 GFL_NET_STATE_SetErrorMode(u8 mode);
extern void func_020093CC(struct Sub02009210Obj *obj, u32 value);
extern u32 func_020093D8(const struct Sub02009210Obj *obj);
extern void func_02009428(struct Sub02009210Obj *obj, int value);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void func_02009294(struct Sub02009210Obj *obj, const void *src);
extern void func_02007664(void *save, u32 box, u32 slot);
extern void func_021B9838(u8 *p);
extern u32 func_02009228(void);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void POKE_TOOL_ClearPartyParam(struct Sav *p);
extern u32 func_0201293C(const struct BigObj *p);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern u8 *func_021B9800(int,int,int);
extern void DWC_RAP_SetErrorCallback(int,int);
extern u32 func_0200FB24(void);
extern void func_0200F7C0(u32 value);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void STRBUF_AppendChar(struct U16Vec *vec, u16 value);
extern void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);
extern void GFL_USE_FadeOutBgm(u32 a);
void func_021D4240(void **p, GsyncStateObj3 *f);
void func_021D4244(GsyncStateObj3 *p,GsyncStateObj3 *f,int line);
void func_021D424C(GsyncStateObj3 *a0);
void func_021D4384(GsyncStateObj3 *p);
void func_021D43B8(u16 *p, const u16 *add, int n);
void func_021D4440(Object_021D4440 *p);
void func_021D449C(char *p);
void func_021D44F4(char *p);
void func_021D451C(char *p);
void func_021D45F0(void);
void func_021D45F4(int count, u32 *tbl, Own *owner, Rec *recs, u32 *xs, u32 *ys);
void func_021D4730(Object_021D4730 *p);
void func_021D4778(void *p,int flag,Callback *q);
void func_021D478C(GsyncStateObj3 *p);
void func_021D4884(GsyncStateObj3 *p);
void func_021D4A04(char *p);
void func_021D4A64(GsyncStateObj6 *p);
void func_021D4AB4(char *p);
void func_021D4AFC(char *p);
void func_021D4B44(char *p);
int func_021D4BA8(int n, char *p);
void func_021D4C24(GsyncStateObj3 *p, int v);
void func_021D4C4C(GsyncStateObj3 *p);
void func_021D4CA0(char *p);
void func_021D4CBC(GsyncStateObj3 *p, int n, int count);
void func_021D4D40(GsyncStateObj3 *p, int flag);
void func_021D4DA4(GsyncStateObj3 *p);
void func_021D4E34(GsyncStateObj3 *p);
void func_021D4E64(GsyncStateObj3 *p);
int func_021D4E7C(GsyncStateObj3 *p);
void func_021D4EF0(GsyncStateObj3 *p, int n, int flag);
void func_021D4FAC(GsyncStateObj3 *p);
void func_021D4FB8(char *p);
void func_021D4FEC(char *p);
void func_021D5020(char *p);
void func_021D504C(char *p);
void func_021D50F8(char *p);
void func_021D5120(void);
int func_021D5128(void *a,int b,GsyncStateObj16 *q);
int func_021D5320(int a,int b,int c,GsyncStateObj6 *p);
int func_021D53D0(void *a,int b,GsyncStateObj29 *out,GsyncStateObj6 *p);
void func_021D54E0(GsyncStateObj2 *p);
u8 *func_021D54F4(u32 heap,u32 bank);
void func_021D562C(GsyncStateObj2 *p);
void func_021D5644(GsyncStateObj2 *p);
void func_021D56FC(GsyncStateObj5 *p,int mode);
void func_021D57B8(GsyncStateObj5 *p, int a);
void func_021D57D0(void *p, int msg, int n, void *mon);
int func_021D580C(GsyncStateObj2 *p);
void func_021D584C(GsyncStateObj2 *p);
int func_021D5890(GsyncStateObj9 *p,int mode);
int func_021D5950(GsyncStateObj2 *p, int x);
void func_021D5960(GsyncStateObj5 *p,int a,int b);
void func_021D59E4(GsyncStateObj5 *p);
void func_021D5A60(GsyncStateObj2 *p);
void func_021D5A7C(GsyncStateObj9 *p);
void func_021D5AB0(GsyncStateObj2 *p, int x);
void func_021D5AC0(void *unused, u32 mode, int unused2);
char *func_021D5B10(int heap,int size);
void func_021D5B70(GsyncStateObj2 *p);
int func_021D5BA0(GsyncStateObj1 *p);
int func_021D5BA8(char *p);
int func_021D5BD4(GsyncStateObj11 *p);
int func_021D5C0C(GsyncStateObj1 *p);
int func_021D5C2C(GsyncStateObj1 *p);
int func_021D5C64(GsyncStateObj11 *p,void *arg,int value);
void func_021D5C9C(GsyncStateObj11 *p);
int func_021D5CAC(GsyncStateObj1 *p);
int func_021D5CF8(GsyncStateObj11 *p);
int func_021D5D24(GsyncStateObj11 *p);
int func_021D5D58(GsyncStateObj11 *p);
void func_021D5D7C(GsyncStateObj1 *p);
void *func_021D5D8C(GsyncStateObj2 *p);
u8 *func_021D5D94(u32 heap);
void func_021D5E60(GsyncStateObj2 *p);
void func_021D5E8C(GsyncStateObj2 *p);
void func_021D5F4C(GsyncStateObj2 *p);
void func_021D60F8(void *a, u8 *p);
void func_021D614C(GsyncStateObj2 *p);
void func_021D62A8(GsyncStateObj15 *p);
void func_021D62B4(GsyncStateObj17 *p,unsigned int i);
void func_021D62BC(u8 *p, int i, u32 v);
void func_021D62D0(u8 *p, int i, int v);
void func_021D62E0(u8 *p, int i);
void func_021D62F8(GsyncStateObj15 *p, int x, int y);
void func_021D634C(GsyncStateObj17 *p, unsigned int i);
void func_021D63D4(GsyncStateObj2 *p);
void func_021D63E4(GsyncStateObj2 *p);
void func_021D6404(GsyncStateObj2 *p);
void func_021D6458(struct GsyncObj171 *p, void *n, int i);
void func_021D651C(GsyncStateObj2 *p);
void func_021D652C(GsyncStateObj2 *p);
void func_021D6548(void *unused, u8 *p);
void func_021D65F4(GsyncStateObj2 *p);
void func_021D6650(GsyncStateObj1 *p,int flag);
void func_021D6678(GsyncStateObj1 *p);
void func_021D66D0(GsyncStateObj2 *p, int n);
void func_021D6720(GsyncStateObj2 *p, int i);
void func_021D679C(GsyncStateObj3 *p);
void func_021D67B4(GsyncStateObj2 *p, int i);
void func_021D6830(struct Record *p);
void func_021D6934(struct Obj *p);
void func_021D6A70(u8 *p,int i,int a,int b,int c);
void func_021D6AA8(char *p, int i, u16 v);
void func_021D6AB8(GsyncStateObj2 *p);
void func_021D6C48(GsyncStateObj2 *p,int i,void *h);
void func_021D6C90(GsyncStateObj2 *p,int i,void *h);
void func_021D6CD8(GsyncStateObj2 *p);
void func_021D6D5C(GsyncStateObj2 *p);
int func_021D6E08(GsyncStateObj1 *p,int x);
int func_021D6E70(GsyncStateObj1 *p);
int func_021D6EA4(GsyncStateObj1 *p);
int func_021D6EBC(GsyncStateObj1 *p);
void func_021D6EDC(GsyncStateObj1 *p,u32 v,int unused);
void func_021D6EE0(GsyncStateObj1 *p,u32 v,int unused);
void func_021D6EE8(char *p);
void func_021D6F04(char *p);
void func_021D6F44(u8 *p);
void func_021D6F70(unsigned char *a);
void func_021D6FF0(char *p);
void func_021D706C(char *p);
void func_021D7088(char *p);
void func_021D70BC(char *p);
void func_021D7130(char *p);
void func_021D7180(int a);
void func_021D7204(char *p);
void func_021D7224(GsyncStateObj1 *p);
void func_021D72D8(char *p);
void func_021D7390(char *p);
void func_021D73D8(char *p);
void func_021D7430(u8 *p);
void func_021D746C(int a);
void func_021D751C(int a);
void func_021D7560(u8 *p);
void func_021D758C(u8 *a);
void func_021D75D0(int a);
void func_021D768C(u8 *p);
void func_021D76B8(char *p);
void func_021D76F0(int a);
void func_021D7798(u8 *p);
void func_021D77C4(int a,int n);
void func_021D7858(int a);
void func_021D78C0(int a);
void func_021D7910(int a);
void func_021D7960(int a);
void func_021D79A4(int a);
void func_021D7A18(int a);
void func_021D7A5C(u8 *p);
void func_021D7B68(char *p);
void func_021D7BDC(char *p);
void func_021D7C54(void *p, char *q);
int func_021D7CB4(int a,u8 *p);
int func_021D7CEC(int a,GsyncStateObj3 *p);
void func_021D7D18(GsyncStateObj1 *p, int unused, int species, int gender, int form, int n, int value);
void func_021D7DE8(GsyncStateObj1 *p,int a,u8 *records);
void func_021D7E20(GsyncStateObj1 *p,GsyncStateObj3 *list);
void func_021D7E58(GsyncStateObj1 *p, void *h, GsyncStateObj3 *q, int *r);
int func_021D7F5C(GsyncStateObj1 *p);
void func_021D7F9C(char *p);
void func_021D80B8(char *p);
void func_021D8130(char *p);
void func_021D8154(char *p);
void func_021D81B4(char *p);
void func_021D81E4(char *p);
void func_021D8210(char *p);
void func_021D8244(char *p);
void func_021D8270(char *p);
void func_021D8304(char *p);
void func_021D834C(char *p);
void func_021D83A4(char *p);
void func_021D83C8(char *p);
void func_021D840C(char *p);
void func_021D8448(char *p);
void func_021D8490(char *p);
void func_021D8520(char *p);
void func_021D8590(char *p);
void func_021D85C4(char *p);
void func_021D85F0(char *p);
void func_021D8624(char *p);
void func_021D8650(GsyncStateObj1 *p,int x,int *q);
void func_021D8790(char *p);
void func_021D87F8(char *p);
void func_021D885C(char *p);
void func_021D88A0(char *p);
void func_021D88C0(char *p);
void func_021D8958(char *p);
void func_021D8A38(char *p);
void func_021D8A7C(char *p);
void func_021D8A9C(char *p);
void func_021D8B0C(char *p);
void func_021D8B7C(char *p);
void func_021D8C04(char *p);
void func_021D8D08(char *p);
void func_021D8D98(char *p);
void func_021D8DFC(char *p);
void func_021D8E28(char *p);
void func_021D8E68(char *p);
void func_021D8E98(char *p);
void func_021D8EC4(char *p);
void func_021D8F3C(char *p);
void func_021D8F58(GsyncStateObj1 *p);
int func_021D8FBC(void *a,int b,GsyncStateObj3 *q);
int func_021D9158(void *a, int b, int c, GsyncStateObj1 *p);
int func_021D920C(void *a, int b, int c, GsyncStateObj10 *p);
void func_021D92B8(GsyncStateObj2 *p);
u8 *func_021D92CC(u32 heap,u32 bank);
void func_021D9404(GsyncStateObj2 *p);
void func_021D941C(GsyncStateObj2 *p);
void func_021D9514(GsyncStateObj5 *p, int n);
void func_021D95B4(GsyncStateObj3 *p);
int func_021D95F0(GsyncStateObj2 *p);
void func_021D9634(GsyncStateObj2 *p);
int func_021D9670(char *p,int mode);
void func_021D9730(GsyncStateObj5 *p, int n);
void func_021D97B0(GsyncStateObj2 *p);
void func_021D97CC(int value, void *p);
void func_021D9844(GsyncStateObj2 *p, int n, int a2);
void func_021D9918(GsyncStateObj2 *p);
char *func_021D9958(int heap);
void func_021D9A14(int a0);
void func_021D9A1C(GsyncStateObj12 *p);
void func_021D9AE8(GsyncStateObj12 *a0);
void func_021D9D34(void);
void func_021D9D3C(GsyncStateObj12 *p);
void func_021D9F40(void *unused, char *p);
void func_021D9FB0(unsigned int p);
int func_021D9FD4(GsyncStateObj4 *p, int n);
void func_021DA030(GsyncStateObj4 *p, int n, int unused);
void func_021DA034(GsyncStateObj4 *p, int n, int unused);
void func_021DA03C(char *p);
void func_021DA054(char *p);
void func_021DA090(char *p);
void func_021DA0B8(char *p);
void func_021DA0E4(char *p);
void func_021DA110(char *p);
void func_021DA138(char *p);
void func_021DA16C(char *p);
void func_021DA1A0(char *p);
void func_021DA1C8(char *p);
void func_021DA1EC(char *p);
void func_021DA244(char *p);
void func_021DA268(char *p);
void func_021DA290(char *p);
void func_021DA2DC(char *p);
void func_021DA308(char *p);
void func_021DA328(char *p);
void func_021DA3A0(char *p);
void func_021DA408(char *p);
void func_021DA434(char *p);
void func_021DA45C(char *p);
int func_021DA478(void *a,int unused,GsyncStateObj14 *q);
int func_021DA54C(int a,int b,GsyncStateObj35 *c,GsyncStateObj1 *p);
extern const struct BgTemplate_021D4240 d_021DA690;
extern const struct BgTemplate_021D4240 d_021DA6B0;
extern const struct BgTemplate_021D4240 d_021DA6D0;
extern const struct BgTemplate_021D4240 d_021DA6F0;
extern const struct BgTemplate_021D4240 d_021DA710;
extern const struct Triple d_021DA638;
extern const struct Triple d_021DA634;
extern const struct Triple d_021DA63C;
extern const char d_021DA9D0[];
extern char func_021DA9C0[];
extern int d_021DA640[];
extern int d_021DA648[];
extern const struct DispConfigWords d_021DA680;
extern const u32 d_021DA9F0[];
extern const u32 d_021DA658[];
extern const char d_021DAA20[];
extern const char d_021DAA30[];
extern char d_021DAA40[];
extern char d_021DAA54[];
extern char *g_021DAC20;
extern char d_021DAA58[];
extern char d_021DAA60[];
extern const char d_021DAA74[];
extern const char d_021DAB68[];
extern char ov067_id[];
extern const u32 d_021DAA9C[];
extern const u32 d_020A1464[];
extern const u32 d_021DAA78[];
extern unsigned char ov_id[];
extern const struct BgTemplate_021D5BD4 d_021DA758[7];
extern struct Entry d_021DAACC[];
extern const struct Pair_021D634C d_021DA738;
extern const struct Pair_021D634C d_021DA748;
extern const u16 d_021DAA88[10];
extern const struct Pos_021D634C d_021DA730;
extern const struct Pair_021D634C d_021DA750;
extern const struct Pos_021D634C d_021DA734;
extern const struct Pair_021D634C d_021DA740;
extern const s16_021D6830 FX_SinCosTable_[][2];
extern const Table_021D634C d_021DA844;
extern const char d_021DAB78[];
extern const char d_021DAB88[];
extern const char d_021DAB90[];
extern const char d_021DAB9C[];
extern char ov114_id[];
extern const char d_021DABA4[];
extern const char d_021DABA8[];
extern const Table_021D8A9C d_021DA868;
extern const u16 d_021DA864;
extern const char d_021DABFC[];
extern const u32 d_021DABCC[];
extern const u32 d_021DABBC[];
extern const struct BgTemplate d_021DA8A8[8];





void func_021D4240(void **p, GsyncStateObj3 *f)
{
    *p=(void *)f;
}





void func_021D4244(GsyncStateObj3 *p,GsyncStateObj3 *f,int line) { func_021D4240((void **)p,f); }





void func_021D424C(GsyncStateObj3 *a0)
{
    struct BgTemplate_021D4240 b[5];
    b[4] = d_021DA690;
    func_0203FCA0(0, (const struct BgTemplate_021D4240 *)(&b[4]), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b[3] = d_021DA6B0;
    func_0203FCA0(4, (const struct BgTemplate_021D4240 *)(&b[3]), 0);
    func_02040588(4, 1);
    func_020409B4(4);
    b[2] = d_021DA6D0;
    func_0203FCA0(5, (const struct BgTemplate_021D4240 *)(&b[2]), 0);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    b[1] = d_021DA6F0;
    func_0203FCA0(6, (const struct BgTemplate_021D4240 *)(&b[1]), 0);
    func_02040588(6, 1);
    func_020409B4(6);
    b[0] = d_021DA710;
    func_0203FCA0(7, (const struct BgTemplate_021D4240 *)(&b[0]), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}





void func_021D4384(GsyncStateObj3 *p) { if(p->f288) { TIME_ICON_Delete(p->f288); *(u32 *)&p->f288=0; } p->f288=TIME_ICON_CreateNode((*(unsigned int *)&p->f230),p->f224,15,16,p->fC); }





void func_021D43B8(u16 *p, const u16 *add, int n)
{
    int i, j;
    u16 *row;
    u16 r, g, b;
    for (i = 0; i < n; i++) {
        row = p + i * 16;
        for (j = 0; j < 16; j++) {
            r = row[j] & 31;
            g = (row[j] & 0x3e0) >> 5;
            b = (row[j] & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            row[j] = r + (g << 5) + (b << 10);
        }
    }
}





void func_021D4440(Object_021D4440 *p)
{
    p->f28c = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, p->f0c);
    switch (p->f08) {
    case 2:
    case 3:
        if (GFL_NET_GetRunState())
            GAME_COMM_RequestExitNoCallback((struct Comm *)func_02012138(p->f264));
        break;
    }
    func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4AB4, 0x1aa);
}





void func_021D449C(char *p)
{
    if (APP_TASKMENU_IsFinish(((GsyncStateObj3 *)p)->f238)) {
        if (!APP_TASKMENU_GetCursorPos(((GsyncStateObj3 *)p)->f238)) {
            func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4FB8, 0x1b6);
        } else {
            func_020414EC(5);
            ((GsyncStateObj3 *)p)->f8 = 0;
            func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4A04, 0x1bb);
        }
        APP_TASKMENU_CloseMenu(((GsyncStateObj3 *)p)->f238);
        *(int *)&((GsyncStateObj3 *)p)->f238 = 0;
        func_021D4D40((GsyncStateObj3 *)p, 0);
    }
}





void func_021D44F4(char *p) { if(func_021D4E7C((GsyncStateObj3 *)p)) { func_021D4DA4((GsyncStateObj3 *)p); func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D449C,0x1c9); } }





/*
 * extent: follower 021D45F0 already filed separately.
 */
void func_021D451C(char *p)
{
    CLACT_ResetActorAnimCommand(*(void **)(p + ((GsyncStateObj3 *)p)->f270 * 4 + 0x2a0));
    CLACT_SetActorAutoAnim(*(void **)(p + ((GsyncStateObj3 *)p)->f270 * 4 + 0x2a0), 0);
    if (((GsyncStateObj3 *)p)->f8 == 3) {
        if (((GsyncStateObj3 *)p)->f224) {
            BMP_WIN_Delete(((GsyncStateObj3 *)p)->f224);
            ((GsyncStateObj3 *)p)->f224 = 0;
        }
        if (OS_IsRunOnTwl()) {
            func_02045CAC(((GsyncStateObj3 *)p)->f28, 0x20, ((GsyncStateObj3 *)p)->f38);
            func_021D4EF0((GsyncStateObj3 *)p, 10, 0);
            func_021D4D40((GsyncStateObj3 *)p, 1);
            func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4AFC, 0x1df);
        } else {
            func_02045CAC(((GsyncStateObj3 *)p)->f24, 7, ((GsyncStateObj3 *)p)->f38);
            func_021D4FAC((GsyncStateObj3 *)p);
            func_021D4D40((GsyncStateObj3 *)p, 1);
            func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D44F4, 0x1e6);
        }
    } else if (((GsyncStateObj3 *)p)->f8 == 2 || ((GsyncStateObj3 *)p)->f8 == 3) {
        func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4FB8, 0x1f2);
    } else {
        func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4440, 0x1f5);
    }
}





/*
 * extent: bx lr callback stub, two zero alignment bytes, then labelled func_021D45F4.
 */
void func_021D45F0(void) {}






/*
 * note 2026-10-05 (wD6 lane17): closed by the real callee prototypes: func_0201DD68 takes no
 *   argument (so count is spilled and reloaded for the +0x25C store) and the record pointer is not
 *   const (the a/b/c loads stay after the outgoing stack-argument stores).
 */
void func_021D45F4(int count, u32 *tbl, Own *owner, Rec *recs, u32 *xs, u32 *ys)
{
    int i;
    int j;
    int a;
    int b;

    owner->n = count;
    func_0201DD68();
    for (i = 0; i < 4; i++) {
        if (owner->obj[i] != 0) {
            BMP_WIN_ClearScreen(owner->obj[i]);
            func_0201F7A8(owner->obj[i], 2);
            BMP_WIN_Delete(owner->obj[i]);
        }
        owner->obj[i] = 0;
    }
    func_02049B40(0x17, 5, 4, 0x100, 0x20, owner->heap);
    for (j = 0; j < count; j++) {
        Rec *r = &recs[j];
        owner->obj[j] = (void *)BMP_WIN_Create(7, (u8)r->a, (u8)r->b, (u8)r->c, (u8)r->d, 8, 0);
        BMP_Clear(BMP_WIN_GetBmp(owner->obj[j]), 0);
        func_02045CAC(owner->bank, tbl[j], owner->str);
        GF_FONT_SetTextColor(0xF, 2, 0);
        if (xs != 0)
            a = xs[j] - func_0201D304(owner->str, (u32)owner->font, 0) / 2;
        else
            a = 0;
        if (ys != 0)
            b = ys[j] - func_0201D42C(owner->str, owner->font) / 2;
        else
            b = 0;
        PRINTSYS_Print(BMP_WIN_GetBmp(owner->obj[j]), (s16_021D4240)a, (s16_021D4240)b, owner->str, owner->font);
        BMP_WIN_TransferChars(owner->obj[j]);
        BMP_WIN_MakeScreen(owner->obj[j]);
    }
    if (owner->res != 0)
        BUTTON_MAN_Delete(owner->res);
    owner->res = 0;
    func_020409B4(7);
}





void func_021D4730(Object_021D4730 *p)
{
    int i;
    if (p->f20)
        BUTTON_MAN_Delete(p->f20);
    p->f20 = 0;
    for (i = 0; i < 4; i++) {
        if (p->f10[i]) {
            BMP_WIN_ClearScreen(p->f10[i]);
            func_02041B6C(5);
            func_0201F7A8(p->f10[i], 2);
            BMP_WIN_Delete(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    p->f25c = 0;
}





void func_021D4778(void *p,int flag,Callback *q) { if(flag) return; if(!q->run) return; if(q->run(p,q)) return; }





/*
 * lever: seven independent offset locals each receive 0x2ac then their final literal; both spill stores survive.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`o1 = 0x2ac;` before `o1 = 0x294;`; `o2 = 0x2ac;` before `o2 = 0x290;`
 * and 5 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021D478C(GsyncStateObj3 *p)
{
    struct Triple x, y, z;
    struct Point_021D4240 pt;
    int i;
    int o1, o2, o3, o4, o5, o6, o7;
    x = d_021DA638;
    y = d_021DA634;
    z = d_021DA63C;
    i = 0;
    o1 = 0x294;
    o2 = 0x290;
    o3 = 0x298;
    o4 = 0x2a0;
    o5 = 0x2a0;
    o6 = 0x2a0;
    o7 = 0x2a0;
    for (; i < 3; i++) {
        pt.x = x.v[i]; pt.y = y.v[i]; pt.z = z.v[i];
        pt.a = 0; pt.b = 2;
        *(void **)((char *)p + i * 4 + o4) = CLACT_CreateActor((void *)(*(unsigned int *)&p->f2AC), (unsigned int)*(void **)((char *)p + o1), *(u32 *)((char *)p + o2), *(u32 *)((char *)p + o3), &pt, 1, p->fC);
        CLACT_SetActorAutoAnim(*(void **)((char *)p + i * 4 + o5), 0);
        CLACT_SetActorDrawEnable(*(void **)((char *)p + i * 4 + o6), 1);
        CLACT_SetActorObjMode(*(void **)((char *)p + i * 4 + o7), 1);
    }
}





/*
 * interface: 02049990 arg5 is u16 at both original call-site truncations; 02049F78 arg3 is an unchanged address payload passed to 02062A98, whose body stores through it.
 */
void func_021D4884(GsyncStateObj3 *p)
{
    void *h;
    void *allocated;
    void *record;
    p->f38 = STRBUF_Create(300, p->fC);
    p->f30 = GF_FONT_Create(23, 0, 0, 0, p->fC);
    p->f24 = func_02045B38(0, 2, 39, p->fC);
    p->f28 = func_02045B38(0, 2, 232, p->fC);
    h = func_020490F4((u32)((void *)29), p->fC);
    func_02049B68(h, 1, 4, 0, 0, p->fC);
    func_02049B68(h, 0, 0, 0, 0, p->fC);
    allocated = func_02049F78(h, 1, (u32)(&record), p->fC);
    func_02082D44(((GsyncStateObj23 *)record)->fC, (char *)p + 0x44, 0xe0);
    func_02082D44(((GsyncStateObj23 *)record)->fC, (char *)p + 0x124, 0xe0);
    func_021D43B8((u16 *)((char *)p + 0x124), (const u16 *)d_021DA9D0, 7);
    func_020307B0(allocated);
    p->f40 = func_02049740(h, 4, 4, 0, 0, p->fC);
    func_02049990(h, 9, 4, 0, (u16)(p->f40), 0, 0, p->fC);
    func_02049990(h, 14, 6, 0, (u16)(p->f40), 0, 0, p->fC);
    ARC_TOOL_DeleteHandle(h);
    p->f3C = func_0201F5DC((void *)5, 12, 0, p->fC);
    func_02049B40(23, 5, 4, 0x1a0, 32, p->fC);
    h = func_020490F4((u32)((void *)29), p->fC);
    p->f294 = (void *)CLACT_RegisterCharacter(h, 5, 0, 1, p->fC);
    p->f290 = (void *)CLACT_RegisterPaletteEx(h, 3, 1, 0, 0, 10, p->fC);
    p->f298 = (void *)CLACT_RegisterCellAnim(h, 7, 16, p->fC);
    ARC_TOOL_DeleteHandle(h);
    func_021D478C(p);
}







void func_021D4A04(char *p)
{
    struct { int value; } zero = {0};
    func_021D45F4(1, (u32 *)&zero, (Own *)p, (Rec *)func_021DA9C0, (u32 *)d_021DA640, (u32 *)(d_021DA640 + 1));
    ((GsyncStateObj3 *)p)->f20 = BUTTON_MAN_Create((u8 *)d_021DA648, (int)func_021D4778, (int)p, ((GsyncStateObj3 *)p)->fC);
    ((GsyncStateObj3 *)p)->f4 = func_021D4BA8;
    func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4CA0, 0x321);
}







void func_021D4A64(GsyncStateObj6 *p)
{
    func_0201DD68();
    func_021D4730((Object_021D4730 *)p);
    func_02040DA8(5, 1, 0);
    func_0203FB44((int)5, (u16)(p->f3C), (u16)(p->f3C >> 16));
    func_020403F4(5);
    func_020403F4(4);
    MSGDATA_Delete(p->f24);
    MSGDATA_Delete(p->f28);
    GF_FONT_Delete(p->f30);
    STRBUF_Delete(p->f38);
}







void func_021D4AB4(char *p)
{
    if (WIPE_SYS_EndCheck() != 0) {
        switch ((*(unsigned int *)&((GsyncStateObj3 *)p)->f8)) {
        case 2:
        case 3:
            if (GAME_COMM_GetKind((void *)func_02012138(((GsyncStateObj3 *)p)->f264)) == 0)
                func_021D4244((GsyncStateObj3 *)p, 0, 0x345);
            break;
        default:
            func_021D4244((GsyncStateObj3 *)p, 0, 0x349);
            break;
        }
    }
}







void func_021D4AFC(char *p)
{
    if (func_021D4E7C((GsyncStateObj3 *)p) != 0 && TOUCHPANEL_GetTrg() != 0) {
        func_021D4E64((GsyncStateObj3 *)p);
        ((GsyncStateObj3 *)p)->f27C = 0;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        func_021D4D40((GsyncStateObj3 *)p, 0);
        func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4A04, 0x360);
    }
}







/*
 * evidence: callback 0x021D45F0 resolved by its verified ov123 shard.
 */
void func_021D4B44(char *p)
{
    NotifyCallback cb;
    cb.value = 0;
    cb.object = p;
    cb.callback = func_021D451C;
    CLACT_SetActorAutoAnim(*(void **)(p + ((GsyncStateObj3 *)p)->f270 * 4 + 0x2a0), 1);
    func_0204BA00(*(void **)(p + ((GsyncStateObj3 *)p)->f270 * 4 + 0x2a0), (const struct Cmd *)(&cb));
    CLACT_RestartActorAnim(*(void **)(p + ((GsyncStateObj3 *)p)->f270 * 4 + 0x2a0));
    func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D45F0, 0x376);
}







int func_021D4BA8(int n, char *p)
{
    ((GsyncStateObj3 *)p)->f270 = n;
    switch (n) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x73b);
        CLACT_SetActorAnimSeq(((GsyncStateObj3 *)p)->f2A0, 14);
        func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4B44, 0x389);
        (*(unsigned int *)&((GsyncStateObj3 *)p)->f8) = 2;
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x73b);
        (*(unsigned int *)&((GsyncStateObj3 *)p)->f8) = 3;
        func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4B44, 0x393);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73c);
        (*(unsigned int *)&((GsyncStateObj3 *)p)->f8) = 0;
        func_021D4244((GsyncStateObj3 *)p, (GsyncStateObj3 *)func_021D4B44, 0x399);
        break;
    }
    return 1;
}







void func_021D4C24(GsyncStateObj3 *p, int v) { if(v!=CLACT_GetActorAnimSeq(p->f2A0)) { CLACT_SetActorAutoAnim(p->f2A0,1); CLACT_SetActorAnimSeq(p->f2A0,v); } }







void func_021D4C4C(GsyncStateObj3 *p)
{
    u32 keys = p->f278;
    if (keys != p->f27C) {
        if (keys & 0x40) func_021D4C24(p, 0x18);
        else if (keys & 0x80) func_021D4C24(p, 0x16);
        else if (keys & 0x100) func_021D4C24(p, 0x15);
        else if (keys & 0x200) func_021D4C24(p, 0x15);
        else func_021D4C24(p, 0xe);
    }
}








/*
 * Addresses are Black-image addresses.
 */
void func_021D4CA0(char *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        BUTTON_MAN_UpdateSlots(((GsyncStateObj3 *)p)->f20);
    func_021D4C4C((GsyncStateObj3 *)p);
}







/*
 * extent: two zero padding bytes at 0x021D4D3E before next labelled function.
 */
void func_021D4CBC(GsyncStateObj3 *p, int n, int count)
{
    void *obj;
    void *buffer;
    int bytes;
    obj = PALANM_Create(p->fC);
    PALANM_AllocSlotBuffers(obj, n, 0x200, p->fC);
    bytes = count * 32;
    PALANM_CopyHwPaletteToSlot(obj, n, 0, bytes);
    PALANM_BlendChannel(obj, (int)n, (int)0, (u16)(count * 16), (int)6, (int)0);
    buffer = (void *)PALANM_GetTransWork(obj, n);
    func_020862F0(buffer, bytes);
    switch (n) {
    case 3: func_0207E5D0(buffer, 0, bytes); break;
    case 1: func_0207E468(buffer, 0, bytes); break;
    }
    PALANM_FreeSlotBuffers(obj, n);
    PALANM_Delete(obj);
}







void func_021D4D40(GsyncStateObj3 *p, int flag)
{
    if (flag) {
        func_02082D44((void *)0x05000600, p->f280, 0x200);
        func_02082D44((void *)0x05000400, p->f284, 0x200);
        func_021D4CBC(p, 3, 14);
        func_021D4CBC(p, 1, 9);
    } else {
        func_0207E5D0(p->f280, 0, 0x1c0);
        func_0207E468(p->f284, 0, 0x120);
    }
}







void func_021D4DA4(GsyncStateObj3 *p)
{
    Descriptor desc;
    desc.heap = p->fC;
    desc.mode = 2;
    desc.data = (char *)p + 0x23c;
    desc.flag = 1;
    desc.a = 32;
    desc.b = 14;
    desc.c = 13;
    desc.d = 3;
    p->f23C = STRBUF_Create(100, p->fC);
    func_02045CAC(p->f24, 4, p->f23C);
    p->f240 = 0x39e0;
    p->f248 = STRBUF_Create(100, p->fC);
    func_02045CAC(p->f24, 5, p->f248);
    p->f24C = 0x39e0;
    p->f238 = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&desc), p->f254);
    APP_TASKMENU_SetDisableKey((int)(p->f238), 1);
    STRBUF_Delete(p->f23C);
    STRBUF_Delete(p->f248);
}







void func_021D4E34(GsyncStateObj3 *p) { if(p->f288) { TIME_ICON_Delete(p->f288); *(u32 *)&p->f288=0; } func_0201F7A8(p->f224,2); BMP_WIN_ClearScreen(p->f224); func_02041B6C(5); }








void func_021D4E64(GsyncStateObj3 *p)
{
    func_021D4E34(p);
    BMP_WIN_Delete(p->f224);
    *(u32 *)&p->f224 = 0;
}







int func_021D4E7C(GsyncStateObj3 *p)
{
    if (p->f228) {
        if (p->f224)
            APP_KEYCURSOR_Update(p->f22C, p->f228, p->f224);
        switch (PRINTSYS_PrintStreamGetState(p->f228)) {
        case 2:
            PRINTSYS_PrintStreamDelete(p->f228);
            p->f228 = 0;
            break;
        case 1:
            if (TOUCHPANEL_GetTrg()) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(p->f228);
            }
            break;
        case 0:
            if (TOUCHPANEL_GetCont()) PRINTSYS_PrintStreamShortWait(p->f228, 0);
            break;
        }
        return 0;
    }
    return 1;
}







void func_021D4EF0(GsyncStateObj3 *p, int n, int flag)
{
    void *obj;
    if (p->f224 == 0)
        p->f224 = (void *)BMP_WIN_Create(5, 1, 3, 30, (u8)n, 13, 1);
    obj = p->f224;
    BMP_Clear(BMP_WIN_GetBmp(obj), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    if (flag) {
        void *value;
        value = (void *)func_02012FFC();
        p->f228 = PRINTSYS_PrintStream(obj, 0, 0, p->f38, p->f30, value, p->f230, 2, p->fC, 15);
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(obj), 0, 0, p->f38, p->f30);
    }
    func_0201F73C(obj, 1, (u16)((*(unsigned int *)&p->f3C)), 12);
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_02041B6C(5);
}







void func_021D4FAC(GsyncStateObj3 *p) { func_021D4EF0(p,4,1); }







/*
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 */
void func_021D4FB8(char *p) { func_021D4D40((GsyncStateObj3 *)p,1); func_02041570(5,0); func_02045CAC(*(void **)(p+36),3,*(void **)(p+56)); func_021D4FAC((GsyncStateObj3 *)p); func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D50F8,0x4d0); }







void func_021D4FEC(char *p) { if(GAME_DATA_SaveMain(((GsyncStateObj3 *)p)->f260)==2) { func_021D4E64((GsyncStateObj3 *)p); func_021D4D40((GsyncStateObj3 *)p,0); func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D4440,0x4ea); } }







void func_021D5020(char *p) { if(func_021D4E7C((GsyncStateObj3 *)p)) { GAME_DATA_SaveStart((int)(((GsyncStateObj3 *)p)->f260)); func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D4FEC,0x4fa); } }







void func_021D504C(char *p)
{
    if (APP_TASKMENU_IsFinish(((GsyncStateObj3 *)p)->f238)) {
        if (!APP_TASKMENU_GetCursorPos(((GsyncStateObj3 *)p)->f238)) {
            if (func_020071F0(GAME_DATA_GetSaveControl(((GsyncStateObj3 *)p)->f260))) {
                func_02045CAC(((GsyncStateObj3 *)p)->f24,46,((GsyncStateObj3 *)p)->f38);
                func_021D4FAC((GsyncStateObj3 *)p);
                func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D4AFC,0x50d);
            } else {
                func_02045CAC(((GsyncStateObj3 *)p)->f24,6,((GsyncStateObj3 *)p)->f38);
                func_021D4EF0((GsyncStateObj3 *)p,4,0);
                func_021D4384((GsyncStateObj3 *)p);
                func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D5020,0x519);
            }
        } else {
            func_020414EC(5);
            ((GsyncStateObj3 *)p)->f8=0;
            func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D4A04,0x51f);
            func_021D4D40((GsyncStateObj3 *)p,0);
        }
        APP_TASKMENU_CloseMenu(((GsyncStateObj3 *)p)->f238);
        ((GsyncStateObj3 *)p)->f238=0;
    }
}







void func_021D50F8(char *p){if(func_021D4E7C((GsyncStateObj3 *)p)){func_021D4DA4((GsyncStateObj3 *)p);func_021D4244((GsyncStateObj3 *)p,(GsyncStateObj3 *)func_021D504C,0x536);}}







/*
 * evidence: root claimed this sole blocker of 021D5128; target's matched
 * definition and original body read no incoming argument registers.
 */
void func_021D5120(void)
{
    CLACT_VBlankSystem();
}







/*
 * evidence: sole callback blocker ov123 021D5120 filed and verified before
 * caller recheck; ABS32 at +01E0 now resolves through its matched shard.
 * volatile: display register 04001000 read/write at 021D5198/021D519C.
 * interface: 0203159C leaves its allocation result in r0, which is used
 * throughout this caller; its legacy matched definition is void.
 */
int func_021D5128(void *a,int b,GsyncStateObj16 *q)
{
    GsyncStateObj3 *p;
    int bright;
    int color;
    struct DispConfigWords cfg;
    GFL_HEAP_CreateChildHeap(1,31,0x18000);
    p=(GsyncStateObj3 *) PROCSYS_AllocProcWork(a,0x2b4,31);
    MI_CpuFill8(p,0,0x2b4);
    p->fC=31;
    (*(unsigned int *)&p->f260)=q->f4; (*(unsigned int *)&p->f264)=q->f0;
    func_0204363C(1);
    if(q->f2C8) bright=16; else bright=-16;
    func_0207D534((void *)0x0400006c,bright); func_0207D534((void *)0x0400106c,bright);
    *(volatile u32 *)0x04001000|=0x10000; func_0207D46C();
    func_0203F8F4(p->fC); BMP_WIN_Init(p->fC); func_0201DD60();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DA9F0);
    cfg=d_021DA680; func_0203FC28((struct DispConfig *)(&cfg));
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct Cfg *)d_021DA658,(u32)d_021DA9F0,p->fC);
    p->f2AC=CLACT_CreateUnit(40,0,p->fC);
    p->f2B0=func_020056A0(func_021D5120,p,0);
    func_021D424C(p); func_021D4884(p);
    p->f280=func_02030734(p->fC,0x200,0,d_021DAA20,0x5a6);
    p->f284=func_02030734(p->fC,0x200,0,d_021DAA20,0x5a7);
    p->f230=TCBL_Create(p->fC,p->fC,3,0);
    (*(unsigned int *)&p->f22C)=func_02028590(15,0,1,p->fC);
    p->f234=PRINTSYS_QUE_Create((void *)(u32)p->fC);
    p->f254=APP_TASKMENU_RES_Create(5,9,(*(unsigned int *)&p->f30),p->f234,p->fC);
    func_0207D63C((void *)0x04001050,4,1,15,4);
    color=0; if(q->f2C8) color=0x7fff;
    WIPE_SYS_Start(0,1,1,(u16)color,6,1,p->fC);
    *(u32 *)&q->f2C8=0; BG_SYS_SetSubVisiblePlanes(31);
    func_021D4244(p,(GsyncStateObj3 *)func_021D4A04,0x5bf);
    p->f258=(u8 *)q;
    GFL_NET_RestartWithDefaultTimeout(0,p->fC); func_020355D8(1);
    return 1;
}







/*
 * extent: two bytes zero alignment padding follow the return.
 */
int func_021D5320(int a,int b,int c,GsyncStateObj6 *p)
{
    int result=1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)((char *)p);
        result=0;
    }
    if (p->f238) APP_TASKMENU_UpdateMenu(p->f238);
    if (GFL_NET_GetRunState()) {
        p->f27C=p->f278;
        p->f278=WIH_DWC_PollStatus(0);
    }
    TCBL_Main(p->f230);
    PRINTSYS_QUE_Main(p->f234);
    func_02040618(4,3,p->f268);
    --p->f268;
    CLACT_DrawSystem();
    if (!p->f28C) GAMESYSTEM_TryStartAutoComm(p->f264);
    if (WIPE_SYS_EndCheck() && func_02012204(p->f264)) {
        p->f8=0;
        result=1;
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
    }
    return result;
}







/*
 * extent: two zero alignment bytes at 021D54DE follow the return.
 */
int func_021D53D0(void *a,int b,GsyncStateObj29 *out,GsyncStateObj6 *p)
{
    int i;
    if(!WIPE_SYS_EndCheck()) return 0;
    for(i=0;i<3;i++) CLACT_DeleteActor(*(void **)((char *)p+i*4+0x2a0));
    CLACT_ReleasePalette((u32)(p->f290));
    CLACT_ReleaseCharacter((u32)(p->f294));
    CLACT_ReleaseCellAnim((u32)(p->f298));
    func_02030EAC(p->f2B0);
    CLACT_DeleteUnit(p->f2AC); CLACT_ExitSystem();
    if(p->f288) { TIME_ICON_Delete(p->f288); p->f288=0; }
    if(p->f228) PRINTSYS_PrintStreamDelete(p->f228);
    if(p->f238) { APP_TASKMENU_CloseMenu(p->f238); p->f238=0; }
    func_021D4A64(p);
    out->f1C8=p->f8;
    func_020307B0(p->f280); func_020307B0(p->f284);
    APP_KEYCURSOR_Delete((int)(p->f22C)); func_020403F4(5);
    PRINTSYS_QUE_Clear(p->f234); PRINTSYS_QUE_Delete(p->f234);
    if(p->f224) BMP_WIN_Delete(p->f224);
    TCBL_Destroy(p->f230); APP_TASKMENU_RES_Delete(p->f254);
    BMP_WIN_Exit(); func_0203F9B4(); func_020315D4(a); func_020306F0(31);
    return 1;
}








void func_021D54E0(GsyncStateObj2 *p)
{
    if (p->f1C) {
        BUTTON_MAN_Delete(p->f1C);
        *(u32 *)&p->f1C = 0;
    }
}







u8 *func_021D54F4(u32 heap,u32 bank)
{
    GsyncStateObj7 *p;
    p=(GsyncStateObj7 *) func_02030734(heap,0xb4,1,d_021DAA30,0x96);
    p->fB0=heap;
    p->f24=func_0201EC64(p->fB0);
    BMP_WIN_Init(p->fB0); func_0201DD60();
    p->f84=TCBL_Create(p->fB0,p->fB0,2,0);
    p->f88=PRINTSYS_QUE_Create((void *)(u32)p->fB0);
    p->f2C=STRBUF_Create(400,p->fB0);
    p->f30=STRBUF_Create(400,p->fB0);
    p->f28=GF_FONT_Create(23,0,0,0,p->fB0);
    p->f20=func_02045B38(0,2,(u16)bank,p->fB0);
    p->f40=func_02028590(15,1,1,p->fB0);
    p->fA4=APP_TASKMENU_RES_Create(5,9,*(u32 *)&p->f28,p->f88,p->fB0);
    p->f8=func_0201F5DC((void *)5,12,0,p->fB0);
    p->f4=func_0201F5DC((void *)6,12,0,p->fB0);
    func_02049B40(23,5,4,352,32,p->fB0);
    func_02049B40(23,5,0,352,32,p->fB0);
    return (u8 *)p;
}








void func_021D562C(GsyncStateObj2 *p)
{
    TCBL_Main(p->f84);
    PRINTSYS_QUE_Main(p->f88);
}







/*
 * lever: low and high halves of packed words pass to u16 callee parameters; no explicit high-half cast.
 */
void func_021D5644(GsyncStateObj2 *p)
{
    int i;
    u32 a;
    func_021D584C(p);
    if (p->f44) BMP_WIN_Delete(p->f44);
    if (p->f48) BMP_WIN_Delete(p->f48);
    for(i=0;i<12;i++) {
        if (*(void **)((char *)p+0x4c+i*4)) BMP_WIN_Delete(*(void **)((char *)p+0x4c+i*4));
    }
    a=p->f8>>16;
    func_0203FB44((int)5,(u16)(p->f8),(u16)a);
    a=p->f4>>16;
    func_0203FB44((int)6,(u16)(p->f4),(u16)a);
    func_021D54E0(p);
    APP_KEYCURSOR_Delete((int)(p->f40));
    func_0201ED04(p->f24);
    func_0201DD68();
    MSGDATA_Delete(p->f20);
    GF_FONT_Delete(p->f28);
    STRBUF_Delete(p->f2C);
    STRBUF_Delete(p->f30);
    APP_TASKMENU_RES_Delete(p->fA4);
    PRINTSYS_QUE_Clear(p->f88);
    PRINTSYS_QUE_Delete(p->f88);
    TCBL_Destroy(p->f84);
    BMP_WIN_Exit();
    func_020307B0(p);
}







void func_021D56FC(GsyncStateObj5 *p,int mode)
{
    void *q;
    if (!p->f44) p->f44=(void *)BMP_WIN_Create((int)5,(int)1,(u8)1,(int)30,4,11,1);
    q=p->f44;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    if (mode) {
        PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,p->f2C,p->f28);
    } else {
        p->f80=PRINTSYS_PrintStream(q, (int)0, (int)0, p->f2C, p->f28, (void *)((int)func_02012FFC()), p->f84, (int)2, p->fB0, 15);
        func_02028470((u8 *)((char *)p+0xa8),(int)6);
    }
    func_0201F73C(q,1,(u16)(p->f8),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(5);
}







void func_021D57B8(GsyncStateObj5 *p, int a)
{
    func_02045CAC(p->f20, a, p->f2C);
    func_021D56FC(p, 0);
}






void func_021D57D0(void *p, int msg, int n, void *mon) {
func_02045CAC(*(void **)((unsigned)p+0x20),msg,*(void **)((unsigned)p+0x30));
func_0201EEF4(*(void **)((unsigned)p+0x24),0,mon);
func_0201EFA4(*(void **)((unsigned)p+0x24),1,n,3,1,1);
func_0201F250(*(void **)((unsigned)p+0x24),*(void **)((unsigned)p+0x2c),*(void **)((unsigned)p+0x30));
}






int func_021D580C(GsyncStateObj2 *p)
{
    if (p->f80) {
        APP_KEYCURSOR_Update(p->f40, p->f80, p->f44);
        if (!func_02028484((struct Blk *)((char *)p+0xa8), p->f80)) return 0;
        PRINTSYS_PrintStreamDelete(p->f80);
        p->f80=0;
    }
    return 1;
}






void func_021D584C(GsyncStateObj2 *p)
{
    if (p->f7C) {
        TIME_ICON_Delete(p->f7C);
        p->f7C=0;
    }
    if (p->f80) {
        PRINTSYS_PrintStreamDelete(p->f80);
        p->f80=0;
    }
    if (p->f44) {
        func_0201F7A8(p->f44,2);
        BMP_WIN_ClearScreen(p->f44);
        func_02041B6C(5);
    }
}






int func_021D5890(GsyncStateObj9 *p,int mode)
{
    Config c;
    int result;
    c.size=p->fB0;
    c.flag=2;
    c.target=(char *)p+0x8c;
    switch (mode) {
    case 0: c.x=32; c.y=12; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    p->f8C=STRBUF_Create(100,p->fB0);
    func_02045CAC(p->f20,4,p->f8C);
    p->f90=0x39e0;
    p->f98=STRBUF_Create(100,p->fB0);
    func_02045CAC(p->f20,5,p->f98);
    p->f9C=0x39e0;
    result=(int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&c),p->fA4);
    STRBUF_Delete(p->f8C);
    STRBUF_Delete(p->f98);
    func_0207D658(0x04001050,9,-8);
    return result;
}







int func_021D5950(GsyncStateObj2 *p, int x)
{
    return func_02045CAC((struct MsgBank *)(p->f20), x, p->f2C);
}






void func_021D5960(GsyncStateObj5 *p,int a,int b)
{
    void *q;
    if (p->f48) BMP_WIN_Delete(p->f48);
    q=(void *)BMP_WIN_Create((int)6,(int)1,(u8)a,(int)30,b,11,1);
    p->f48=q;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,p->f2C,p->f28);
    func_0201F73C(q,1,(u16)(p->f4),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(6);
}






void func_021D59E4(GsyncStateObj5 *p)
{
    void *q;
    if (p->f48) BMP_WIN_Delete(p->f48);
    q=(void *)BMP_WIN_Create(6,1,9,30,6,11,1);
    p->f48=q;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,p->f2C,p->f28);
    func_0201F73C(q,1,(u16)(p->f4),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(6);
}






void func_021D5A60(GsyncStateObj2 *p)
{
    func_0201F7A8(p->f48, 2);
    BMP_WIN_ClearScreen(p->f48);
    func_02041B6C(6);
}





void func_021D5A7C(GsyncStateObj9 *p){if(p->f7C){TIME_ICON_Delete(p->f7C);p->f7C=0;}p->f7C=TIME_ICON_CreateNode(p->f84,p->f44,15,16,p->fB0);}






void func_021D5AB0(GsyncStateObj2 *p, int x)
{
    func_021D97CC(x, p->f2C);
}






static inline u32 func_021D5AC0_next(u32 mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
        break;
    case 3:
        return mode;
    case 6:
        *(u32 *)(g_021DAC20 + 0xC8) = 1;
        break;
    case 8:
        func_0200F7DC();
        break;
    }
    return mode;
}






/*
 * 2026-10-05 (wD9r lane99): EXACT. The switch is a static inline helper that returns the mode; case 3
 *   returns from inside the switch, the other cases break to the final `return mode;`. The inline return
 *   copy into the result keeps case 3's own `b end` block until after jump-table threading (the stub at
 *   +0x26). No redundant statement and no cast: only the return-versus-break shape of case 3.
 *   Earlier lanes (D2 to D9r) tried every in-function form of case 3; all merged it with the end label.
 */
void func_021D5AC0(void *unused, u32 mode, int unused2)
{
    u32 next = func_021D5AC0_next(mode);
    *(u32 *)(g_021DAC20 + 0xB0) = 1;
    *(u32 *)(g_021DAC20 + 0xB4) = next;
}





char *func_021D5B10(int heap,int size)
{
    GsyncStateObj25 *p;
    p=(GsyncStateObj25 *) func_02030734(heap,0xd4,1,d_021DAA40,0x88);
    if (g_021DAC20) func_02034714(d_021DAA54,0,d_021DAA54);
    g_021DAC20=(char *)p;
    p->fB8=func_02030734(heap,size+0x40,0,d_021DAA40,0x8c);
    p->fBC=size;
    return (char *)p;
}





void func_021D5B70(GsyncStateObj2 *p){if(g_021DAC20){DWC_RAP_SetErrorHookCallback(0,0);func_020307B0(p->fB8);func_020307B0(p);g_021DAC20=0;}}





int func_021D5BA0(GsyncStateObj1 *p){return p->fB8;}





int func_021D5BA8(char *p){if(!((GsyncStateObj11 *)p)->fC4){if(func_021C5B80())((GsyncStateObj11 *)p)->fC4=1;}return ((GsyncStateObj11 *)p)->fB0==0;}




int func_021D5BD4(GsyncStateObj11 *p){p->fB0=0;if(!func_021C5928(func_021D5AC0,d_021DAA58,d_021DAA60))return 0;DWC_RAP_SetErrorHookCallback((int)func_021D5BA8,(int)p);return 1;}




int func_021D5C0C(GsyncStateObj1 *p){if(*(int *)(g_021DAC20+0xb0)){if(!p->fB4)return 1;}return 0;}




int func_021D5C2C(GsyncStateObj1 *p){if(p->fD0&&p->fC8)return 1;if(*(int *)(g_021DAC20+0xb0)&&p->fB4)return 1;return 0;}




int func_021D5C64(GsyncStateObj11 *p,void *arg,int value){char buf[20];int ok=0;p->fB0=0;STD_TSNPrintf(buf,20,d_021DAA74,value);if(func_021C5C04(arg,buf,(char *)d_021DAA54))ok=1;return ok;}





void func_021D5C9C(GsyncStateObj11 *p)
{
    p->fCC = 0;
    p->fD0 = 0;
}




int func_021D5CAC(GsyncStateObj1 *p)
{
    if (p->fD0) return 0;
    if (p->fCC) {
        if (++p->fCC>3600) {
            p->fD0=1;
            if (!func_021C5DB4()) p->fC8=1;
            return 0;
        }
    }
    return 1;
}




int func_021D5CF8(GsyncStateObj11 *p){int ok=1;p->fB0=0;p->fCC=1;p->fD0=0;if(!func_021C5C38(p,0,1))ok=0;return ok;}




int func_021D5D24(GsyncStateObj11 *p){int ok=1;p->fB0=0;p->fCC=1;p->fD0=0;if(!func_021C5CFC(p,p->fB8,p->fBC+0x40))ok=0;return ok;}




int func_021D5D58(GsyncStateObj11 *p){int ok;if(!p->fC4){ok=0;p->fB0=0;if(!func_021C5B80())return ok;}return 1;}





void func_021D5D7C(GsyncStateObj1 *p)
{
    if (func_021D5CAC(p) != 0)
        func_021C5AB8();
}




void *func_021D5D8C(GsyncStateObj2 *p){return p->fAC;}




/*
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 */
u8 *func_021D5D94(u32 heap)
{
    GsyncStateObj2 *p;
    p=(GsyncStateObj2 *) func_02030734(heap,0x4568,1,d_021DAB68,0xfe);
    p->f43C4=heap;
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0); func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(p->f43C4);
    CLACT_InitSystem((const struct Cfg *)d_020A1464,(u32)d_021DAA9C,p->f43C4);
    p->fC=CLACT_CreateUnit(40,0,p->f43C4);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DAA9C); func_0203FC28((struct DispConfig *)d_021DAA78);
    func_021D5F4C(p); func_021D614C(p); func_021D6CD8(p); func_021D6D5C(p);
    p->f10=func_020056A0(func_021D60F8,p,0);
    p->f455C=200;
    BG_SYS_SetSubVisiblePlanes(31); BG_SYS_SetMainVisiblePlanes(27);
    return (u8 *)p;
}




void func_021D5E60(GsyncStateObj2 *p){(p->f43C6)++;if(p->f43C6>=192)p->f43C6=0;CLACT_DrawSystem();func_021D6678((GsyncStateObj1 *)(void *)p);func_021D6934((struct Obj *)p);}




void func_021D5E8C(GsyncStateObj2 *p)
{
    Counter i;
    func_021D63E4(p);
    func_020307B0(p->f1C);
    CLACT_DeleteActor(p->fB4);
    CLACT_DeleteActor(p->fB8);
    i=0;
    do { if(*(void **)((u8 *)p+i*4+0x20)) CLACT_ReleasePalette((u32)(*(void **)((u8 *)p+i*4+0x20))); i++; } while(i<6);
    for(;i<13;i++) if(*(void **)((u8 *)p+i*4+0x20)) CLACT_ReleaseCharacter((u32)(*(void **)((u8 *)p+i*4+0x20)));
    for(;i<20;i++) if(*(void **)((u8 *)p+i*4+0x20)) CLACT_ReleaseCellAnim((u32)(*(void **)((u8 *)p+i*4+0x20)));
    if(p->f14) func_02030EAC(p->f14);
    func_02030EAC(p->f10);
    CLACT_DeleteUnit(p->fC);
    CLACT_ExitSystem();
    func_02040DA8(1,1,0); func_02040DA8(6,1,0);
    func_020403F4(5); func_020403F4(4);
    func_02040588(5,0); func_0203F9B4(); func_020307B0(p);
    func_02034A5C((int)ov_id);
}




void func_021D5F4C(GsyncStateObj2 *p)
{
    struct BgTemplate_021D5BD4 b[7];
    b[6]=d_021DA758[0]; func_0203FCA0(0, (const struct BgTemplate_021D4240 *)(&b[6]), 0); func_02040588(0,1); func_020409B4(0);
    b[5]=d_021DA758[1]; func_0203FCA0(1, (const struct BgTemplate_021D4240 *)(&b[5]), 0); func_02040588(1,1); func_020409B4(1);
    b[4]=d_021DA758[2]; func_0203FCA0(3, (const struct BgTemplate_021D4240 *)(&b[4]), 0); func_02040588(3,1); func_020409B4(3);
    b[3]=d_021DA758[3]; func_0203FCA0(4, (const struct BgTemplate_021D4240 *)(&b[3]), 0); func_02040588(4,1); func_020409B4(4);
    b[2]=d_021DA758[4]; func_0203FCA0(5, (const struct BgTemplate_021D4240 *)(&b[2]), 0);
    func_02040C14(5,0,1,0); func_02041300(5,0,0,0,32,32,17); func_02040588(5,1); func_020409B4(5);
    b[1]=d_021DA758[5]; func_0203FCA0(6, (const struct BgTemplate_021D4240 *)(&b[1]), 0); func_02040588(6,1);
    func_02040C14(6,0,1,0); func_02041300(6,0,0,0,32,32,17); func_020409B4(6);
    b[0]=d_021DA758[6]; func_0203FCA0(7, (const struct BgTemplate_021D4240 *)(&b[0]), 0); func_02040588(7,1); func_020409B4(7);
}




void func_021D60F8(void *a, u8 *p)
{
    int n;
    u8 *base;
    int off;
    CLACT_VBlankSystem();
    n = ((GsyncStateObj3 *)p)->f4564 + 1;
    ((GsyncStateObj3 *)p)->f4564 = n;
    if (n % 10 == 1) {
        base = *(u8 * *)&((struct GsyncObj172 *)(((GsyncStateObj3 *)p)->f18))->fC;
        off = (n / 10 + 2) * 32;
        func_0207E3D0(base + off, 64, 32);
        func_0207E468(base + off, 64, 32);
    }
    if (((GsyncStateObj3 *)p)->f4564 >= 80) ((GsyncStateObj3 *)p)->f4564 = 0;
}




void func_021D614C(GsyncStateObj2 *p)
{
    void *h;
    h=func_020490F4((u32)((void *)143),p->f43C4);
    func_02049B68(h,2,4,0,0,p->f43C4);
    p->f0=func_02049740(h,8,4,0,0,p->f43C4);
    func_02049990(h,21,4,0,(u16)(p->f0),0,0,p->f43C4);
    func_02049990(h,24,7,0,(u16)(p->f4),0,0,p->f43C4);
    p->f1C=func_02049F78(h,2,(u32)((void **)((u8 *)p+0x18)),p->f43C4);
    func_02049B68(h,2,0,0,0,p->f43C4);
    p->f4=func_02049740(h,8,0,0,0,p->f43C4);
    func_02049990(h,23,0,0,(u16)(p->f4),0,0,p->f43C4);
    func_02049990(h,24,1,0,(u16)(p->f4),0,0,p->f43C4);
    p->f38=(void *)CLACT_RegisterCharacter(h,9,0,2,p->f43C4);
    p->f20=(void *)CLACT_RegisterPaletteEx(h,3,2,96,0,4,p->f43C4);
    p->f54=(void *)CLACT_RegisterCellAnim(h,12,25,p->f43C4);
    p->f3C=(void *)CLACT_RegisterCharacter(h,10,0,2,p->f43C4);
    p->f24=(void *)CLACT_RegisterPaletteEx(h,4,2,224,0,0,p->f43C4);
    p->f58=(void *)CLACT_RegisterCellAnim(h,13,26,p->f43C4);
    func_021D6404(p); ARC_TOOL_DeleteHandle(h);
}




void func_021D62A8(GsyncStateObj15 *p){func_021D62F8(p,133,128);}




void func_021D62B4(GsyncStateObj17 *p,unsigned int i){func_021D634C(p,i);}





void func_021D62BC(u8 *p, int i, u32 v)
{
    CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 0x74), (u16)v);
}





void func_021D62D0(u8 *p, int i, int v)
{
    func_0204BA00(*(void **)(p + i * 4 + 0x74), (const struct Cmd *)v);
}





void func_021D62E0(u8 *p, int i)
{
    if (*(u32 *)(p + 0x74 + i * 4)) {
        CLACT_DeleteActor(*(void **)(p + 0x74 + i * 4));
        *(u32 *)(p + 0x74 + i * 4) = 0;
    }
}




void func_021D62F8(GsyncStateObj15 *p, int x, int y)
{
    struct Point_021D5BD4 pt;
    if (p->fAC == 0) {
        pt.x = x; pt.y = y; pt.f4 = 0; pt.f6 = 0; pt.f7 = 1;
        p->fAC = CLACT_CreateActor((void *)p->fC, (u32)p->f3C, p->f24, p->f58, &pt, 1, p->f43C4);
        CLACT_SetActorAutoAnim(p->fAC, 1);
        CLACT_SetActorDrawEnable(p->fAC, 1);
    }
}











/*
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 */
void func_021D634C(GsyncStateObj17 *p, unsigned int i)
{
    struct Point_021D634C pt;
    if (*(void **)((u8 *)p + i*4 + 0x74)) CLACT_DeleteActor(*(void **)((u8 *)p+i*4+0x74));
    pt.x = d_021DAACC[i].x; pt.y = d_021DAACC[i].y;
    pt.f4 = i; pt.f6 = d_021DAACC[i].n; pt.f7 = 1;
    ((void **)((u8 *)p + 0x74))[i] = CLACT_CreateActor((void *)p->fC, (u32)p->f38, p->f20, p->f54, &pt, 0, p->f43C4);
    CLACT_SetActorAnimFrame(((void **)((u8 *)p+0x74))[i],0);
    CLACT_SetActorAutoAnim(((void **)((u8 *)p+0x74))[i],1);
    CLACT_SetActorDrawEnable(((void **)((u8 *)p+0x74))[i],1);
    CLACT_SetActorAffineMode(((void **)((u8 *)p+0x74))[i],2);
}












void func_021D63D4(GsyncStateObj2 *p)
{
    CLACT_SetActorAnimSeq(p->fA8, 2);
}











void func_021D63E4(GsyncStateObj2 *p){int i;for(i=0;i<16;i++){u8 *q=(u8 *)p+i*4;if(((GsyncStateObj18 *)q)->f74){CLACT_DeleteActor(((GsyncStateObj18 *)q)->f74);((GsyncStateObj18 *)q)->f74=0;}}}











void func_021D6404(GsyncStateObj2 *p)
{
    void *h;
    h = func_020490F4(7, p->f43C4);
    p->f28 = (void *)CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 2, 0, p->f43C4);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(143, p->f43C4);
    p->f5C = (void *)CLACT_RegisterCellAnim(h, 14, 27, p->f43C4);
    ARC_TOOL_DeleteHandle(h);
}











void func_021D6458(struct GsyncObj171 *p, void *n, int i)
{
    struct Pair_021D634C a = d_021DA738;
    struct Pair_021D634C b = d_021DA748;
    struct Point_021D634C pt;
    void *h;
    h = func_020490F4(7, p->f43C4);
    p->f40 = (void *)CLACT_RegisterCharacter(h,POKE_TOOL_GetGraphicIndex((void *)n),0,2,p->f43C4);
    if(i==0) { pt.x=a.b; pt.y=b.b; }
    else { pt.x=a.a; pt.y=b.a; }
    pt.f4=0; pt.f6=3; pt.f7=1;
    p->fA8 = CLACT_CreateActor((void *)p->fC,(unsigned int)p->f40,p->f28,p->f5C,&pt,(u16)i,p->f43C4);
    CLACT_SetActorAutoAnim(p->fA8,0);
    CLACT_SetActorDrawEnable(p->fA8,1);
    CLACT_SetActorPaletteOffset(p->fA8,POKE_TOOL_GetIconPalette(n),1);
    ARC_TOOL_DeleteHandle(h);
}












void func_021D651C(GsyncStateObj2 *p)
{
    CLACT_SetActorAutoAnim(p->fA8, 1);
}












void func_021D652C(GsyncStateObj2 *p)
{
    CLACT_SetActorAnimSeq(p->fA8, 1);
    CLACT_SetActorAutoAnim(p->fA8, 1);
}











void func_021D6548(void *unused, u8 *p)
{
    int line;
    int idx;
    int d;
    int v;
    idx = *(s16_021D634C *)(p + 0x43C6) + 1;
    line = *(volatile u16 *)0x04000006;
    idx = (line + idx) % 0xC0;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x0400001C = *(s16_021D634C *)(p + 0x43C8 + idx * 2) & 0x1FF;
        v = *(int *)(p + 0x455C);
        if (v >= 0xC0) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v == 0) {
            func_0207E3D0(&d_021DAA88[9], 0x142, 2);
            return;
        }
        if (line > 200) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v > line) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        d = line - v;
        if ((u32)d < 10 && d >= 0) {
            func_0207E3D0(&d_021DAA88[d], 0x142, 2);
            return;
        }
        func_0207E3D0(&d_021DAA88[9], 0x142, 2);
    }
}











void func_021D65F4(GsyncStateObj2 *p)
{
    void *h;
    h = func_020490F4(143, p->f43C4);
    func_02049990(h, 22, 3, 0, (u16)p->f4, 0, 0, p->f43C4);
    ARC_TOOL_DeleteHandle(h);
    p->f14 = func_02005624((u32)func_021D6548, (u32)p, 0);
    PMSI_PARAM_MakeSineTable((s16_021D634C *)((u8 *)p + 0x43c8), 192, 0x5b0, 0x1800);
}











void func_021D6650(GsyncStateObj1 *p,int flag){if(flag){p->f4554=0;p->f4558=1;}else{p->f4554=65536;p->f4558=-1;}}











void func_021D6678(GsyncStateObj1 *p)
{
    int v;
    if (p->f4558 != 0) {
        p->f4554 += p->f4558 << 10;
        v = p->f4554 >> 12;
        func_02040588(3, 1);
        if (v > 10) { p->f4558 = 0; return; }
        if (v < 0) { v = 0; func_02040588(3, 0); p->f4558 = v; return; }
        func_0207D63C((void *)0x04000050, 8, 55, v, 8);
    }
}











void func_021D66D0(GsyncStateObj2 *p, int n)
{
    float x = (float)(1.2 * (double)(float)n);
    int v;
    if (n > 100) v = 0;
    else v = (int)(120.0f - x);
    if (p->f455C > v) p->f455C = v;
}











void func_021D6720(GsyncStateObj2 *p, int i)
{
    struct Pos_021D634C pos;
    struct Pair_021D634C pair;
    void *h;
    func_021D6C48(p,i,p->fB4);
    h = p->fB4;
    pos = d_021DA730; pair = d_021DA750;
    CLACT_AddActorSurfacePos(h,(const struct Vec2 *)(&pos),0); CLACT_SetActorScale(h, (struct Pair_021D634C *)&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    *(void **)((u8 *)p+i*24+0x40f4) = h;
}











void func_021D679C(GsyncStateObj3 *p){if(p->f0)CLACT_SetActorDrawEnable(p->f0,0);p->f0=0;}











void func_021D67B4(GsyncStateObj2 *p, int i)
{
    struct Pos_021D634C pos;
    struct Pair_021D634C pair;
    void *h;
    func_021D6C90(p,i,p->fB8);
    h = p->fB8;
    pos = d_021DA734; pair = d_021DA740;
    CLACT_AddActorSurfacePos(h,(const struct Vec2 *)(&pos),0); CLACT_SetActorScale(h, (struct Pair_021D634C *)&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    *(void **)((u8 *)p+i*24+0x40f4) = h;
}










/*
 * lever: spelled-out x assignments reuse its already-loaded halfword.
 */
void func_021D6830(struct Record *p)
{
    struct Pos_021D6830 pos;
    struct Pair_021D6830 scale;
    int a,b;
    if (p == 0) return;
    a = (s16_021D6830)(FX_SinCosTable_[p->a >> 4][0] * 4) >> 12;
    b = (s16_021D6830)(FX_SinCosTable_[p->b >> 4][0] * 3) >> 12;
    if (p->h) {
        CLACT_GetActorSurfacePos(p->h, (struct PtS *)&pos, 0);
        pos.x = p->x + a + b;
        pos.y = (p->y + a + b + p->age) >> 2;
        if (p->age % 8 == 0) {
            if (p->x > 128) p->x = p->x - 1;
            else p->x = p->x + 1;
        }
        CLACT_AddActorSurfacePos(p->h, (const struct Vec2 *)(&pos), 0);
        CLACT_SetActorDrawEnable(p->h, 1);
        p->age++;
        if (pos.y > 25) {
            CLACT_GetActorScale(p->h, (struct Pair_021D6830 *)&scale);
            scale.x -= 16;
            scale.y -= 16;
            if (scale.x < 0 || scale.y < 0) func_021D679C((GsyncStateObj3 *)p);
            else CLACT_SetActorScale(p->h, (struct Pair_021D634C *)&scale);
        }
        if (pos.y > 50) func_021D679C((GsyncStateObj3 *)p);
    } else p->g = 1;
    if (p->g == 0) {
        p->a += (u16)(func_020056EC(12) + 200);
        p->b -= (u16)(func_020056EC(12) + 666);
    }
}










/*
 * lever: bind i+20 to n before indexing, sharing its scaled address.
 */
void func_021D6934(struct Obj *p)
{
    int active = 0;
    int i,n;
    for (i = 0; i < 20; i++) {
        if (p->records[i].c && !p->records[i].g) {
            func_021D6830(&p->records[i]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 20; i++) {
            n = func_020056EC(20);
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D67B4((GsyncStateObj2 *)p, n);
                break;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        n = i + 20;
        if (p->records[n].c && !p->records[n].g) {
            func_021D6830(&p->records[n]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 10; i++) {
            n = func_020056EC(10) + 20;
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D6720((GsyncStateObj2 *)p, n);
                return;
            }
        }
    }
}










void func_021D6A70(u8 *p,int i,int a,int b,int c){if(a!=0 && a<=493){*(s16_021D6A70 *)(p+(u32)i*24+0x4104)=a;*(s16_021D6A70 *)(p+(u32)i*24+0x4106)=b;if(c>2)c=0;*(s16_021D6A70 *)((u32)p+(u32)i*24+0x4108)=c;}}











void func_021D6AA8(char *p, int i, u16 v)
{
    *(u16 *)(p + i * 0x18 + 0x4104) = v;
}










/*
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 */
void func_021D6AB8(GsyncStateObj2 *p)
{
    void *h;
    void *h2;
    void *buf;
    void *buf2;
    u8 *out2;
    u8 *out;
    int i,n,species,form,gender;
    u32 value;
    u16 id;
    h = func_020490F4(25, p->f43C4);
    for (i = 0; i < 20; i++) {
        species = ((struct Obj *)p)->records[i].d;
        if (species) {
            buf = ARC_TOOL_LoadHandleMember(h,func_02020E60(species,2),p->f43C4);
            func_02062A98(buf,(void **)(&out));
            func_02082D44(((GsyncStateObj30 *)out)->fC,(u8 *)p+0xbc+i*0x224,32);
            func_020307B0(buf);
            buf2 = ARC_TOOL_LoadHandleMember(h,func_02020E60(species,1),p->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            func_02082D44(((GsyncStateObj24 *)out2)->f14,(u8 *)p+0xdc+i*0x224,512);
            func_020307B0(buf2);
        }
    }
    ARC_TOOL_DeleteHandle(h);
    h2 = func_020490F4(7, p->f43C4);
    for (i = 0; i < 10; i++) {
        n = i+20;
        species = ((struct Obj *)p)->records[n].d;
        if (species) {
            gender = ((struct Obj *)p)->records[n].f;
            form = (int)func_02019D30((u16)species,(u8)(((struct Obj *)p)->records[n].e));
            value = POKE_TOOL_CalcIconPalette(species,form,gender,0);
            id = POKE_TOOL_CalcGraphicIndex(species,form,gender,0);
            buf2 = ARC_TOOL_LoadHandleMember(h2,id,p->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            func_02082D44(((GsyncStateObj24 *)out2)->f14,(u8 *)p+0xdc+n*0x224,512);
            func_020307B0(buf2);
            *(u32 *)((u8 *)p+n*0x224+0x2dc) = value;
        }
    }
    ARC_TOOL_DeleteHandle(h2);
}










void func_021D6C48(GsyncStateObj2 *p,int i,void *h)
{
    Desc d;
    CLACT_GetActorImageProxy(h,(struct Struct36 *)(&d));
    func_02082D44((char *)p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    CLACT_SetActorPaletteOffset(h,(u8)(*(u32 *)((char *)p+i*0x224+0x2dc)),1);
}










void func_021D6C90(GsyncStateObj2 *p,int i,void *h)
{
    Desc d;
    CLACT_GetActorImageProxy(h,(struct Struct36 *)(&d));
    func_02082D44((char *)p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    func_020862F0((char *)p+0xbc+i*0x224,0x20);
    func_0207E51C((char *)p+0xbc+i*0x224,0x100,0x20);
}










/*
 * lever: narrow the helper result through a named u16 local before the call.
 */
void func_021D6CD8(GsyncStateObj2 *p)
{
    struct Point_021D6830 pt;
    void *h;
    u16 n;
    h=func_020490F4(7,p->f43C4);
    n=POKE_TOOL_CalcGraphicIndex(1,0,0,0);
    p->f44=(void *)CLACT_RegisterCharacter(h,n,0,0,p->f43C4);
    pt.x=133; pt.y=128; pt.f4=0; pt.f6=3; pt.f7=2;
    p->fB4=CLACT_CreateActor((void *)(*(unsigned int *)&p->fC),(u32)p->f44,(*(unsigned int *)&p->f28),(*(unsigned int *)&p->f5C),&pt,0,p->f43C4);
    CLACT_SetActorAutoAnim(p->fB4,0);
    CLACT_SetActorDrawEnable(p->fB4,0);
    ARC_TOOL_DeleteHandle(h);
}









void func_021D6D5C(GsyncStateObj2 *p)
{
    struct Point pt;
    void *h;
    h=func_020490F4(25,p->f43C4);
    p->f34=(void *)CLACT_RegisterPaletteEx(h,func_02020E60(1,2),0,256,0,1,p->f43C4);
    p->f50=(void *)CLACT_RegisterCharacter(h,func_02020E60(1,1),0,0,p->f43C4);
    p->f6C=(void *)CLACT_RegisterCellAnim(h,1,0,p->f43C4);
    ARC_TOOL_DeleteHandle(h);
    pt.x=156; pt.y=28; pt.f4=0; pt.f6=0; pt.f7=2;
    p->fB8=CLACT_CreateActor((void *)(*(unsigned int *)&p->fC),(unsigned int)p->f50,*(u32 *)&p->f34,*(u32 *)&p->f6C,&pt,0,p->f43C4);
    CLACT_SetActorAutoAnim(p->fB8,0);
    CLACT_SetActorDrawEnable(p->fB8,0);
}









int func_021D6E08(GsyncStateObj1 *p,int x)
{
    switch (x) {
    case 503:
        p->f80=0xfff1;
        func_021D6EE0(p,(int)func_021D6FF0,0xd3);
        return 1;
    case 502:
        p->f80=0xfff2;
        func_021D6EE0(p,(int)func_021D6FF0,0xd7);
        return 1;
    }
    if (x>=400) {
        p->f80=0xfff3;
        func_021D6EE0(p,(int)func_021D6FF0,0xdd);
        return 1;
    }
    return 0;
}









int func_021D6E70(GsyncStateObj1 *p){u8 *q=p->f20;if(((GsyncStateObj22 *)q)->f1C8==2)return 0;if(((GsyncStateObj22 *)q)->f50 && ((GsyncStateObj22 *)q)->fC==4)return 0;if(GFL_NET_GetRunState())return 1;return 0;}










int func_021D6EA4(GsyncStateObj1 *p)
{
    char *q = p->f20;

    return ((GsyncStateObj26 *)q)->f50 != 0 && ((GsyncStateObj26 *)q)->fC == 0;
}









int func_021D6EBC(GsyncStateObj1 *p){u8 *q=p->f20;if(((GsyncStateObj27 *)q)->f50){unsigned int x=((GsyncStateObj27 *)q)->fC;if(x==0)return 1;if(x==4)return 1;}return 0;}









void func_021D6EDC(GsyncStateObj1 *p,u32 v,int unused){p->f50=v;}









void func_021D6EE0(GsyncStateObj1 *p,u32 v,int unused){func_021D6EDC(p,v,unused);}










void func_021D6EE8(char *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        func_021D6EE0((GsyncStateObj1 *)p, 0, 0x157);
}









void func_021D6F04(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        WIPE_SYS_Start(0,0,0,0,6,1,((GsyncStateObj1 *)p)->f0);
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6EE8,0x16b);
    }
}









void func_021D6F44(u8 *p){if(func_021D5C0C((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)p)->f8)))){func_021D5B70((GsyncStateObj2 *)((char *)(((GsyncStateObj1 *)p)->f8)));((GsyncStateObj1 *)p)->f8=0;func_021D6EE0((GsyncStateObj1 *)p,(u32)func_021D706C,0x17c);}}










void func_021D6F70(unsigned char *a)
{
    if (((GsyncStateObj1 *)a)->fAB != 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((GsyncStateObj1 *)a)->fAD != 0) {
        GAME_DATA_SaveCancel((char *)(((GsyncStateObj1 *)a)->f2C));
        ((GsyncStateObj1 *)a)->fAD = 0;
    }
    func_021D8F58((GsyncStateObj1 *)a);
    if (((GsyncStateObj1 *)a)->f8 != 0) {
        if (func_021D5D58((GsyncStateObj11 *)((char *)(((GsyncStateObj1 *)a)->f8))) != 0)
            func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D6F44, 0x191);
        func_021D6EE0((GsyncStateObj1 *)a, 0x021D706D, 0x193);
    } else {
        func_021D6EE0((GsyncStateObj1 *)a, 0x021D706D, 0x196);
    }
}









/*
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 */
void func_021D6FF0(char *p)
{
    int n=((GsyncStateObj1 *)p)->f80+29;
    if (((GsyncStateObj1 *)p)->f10) func_021B9774(((GsyncStateObj1 *)p)->f10);
    if (((GsyncStateObj1 *)p)->f80==0xfff0) n=39;
    else if (((GsyncStateObj1 *)p)->f80==0xfff1) n=40;
    else if (((GsyncStateObj1 *)p)->f80==0xfff2) n=41;
    else if (((GsyncStateObj1 *)p)->f80==0xfff3) n=38;
    else if (((GsyncStateObj1 *)p)->f80<=0 || ((GsyncStateObj1 *)p)->f80>=10) n=38;
    func_021D584C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
    func_021D5950((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)p)->f18)),n);
    func_021D5960((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18),1,16);
    func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6F70,0x1b9);
}









void func_021D706C(char *p)
{
    ((struct GsyncObj173 *)(((GsyncStateObj1 *)p)->f20))->f1C8=6;
    func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6F04,0x1c9);
}









void func_021D7088(char *p) { if(func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18)) && (KEY_GetTrg() || TOUCHPANEL_GetTrg())) func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D706C,0x1d9); }









void func_021D70BC(char *p)
{
    Table_021D634C t=d_021DA844;
    if (((GsyncStateObj1 *)p)->fA8) {
        func_021D584C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
        func_021D5950((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)p)->f18)),t.x[((GsyncStateObj1 *)p)->fA8]);
        func_021D5960((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18),1,8);
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D7088,0x1f0);
    } else {
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D706C,0x1f3);
    }
}









void func_021D7130(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(*(char **)(p + 0x18))) != 0) {
        int n = *(int *)(p + 0x78) - 1;
        *(int *)(p + 0x78) = n;
        if (n <= 0) {
            if (n == 0) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPlayerParam(0);
                GFL_USE_FadeInBgmFull(6);
            }
            if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
                func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D70BC, 0x20B);
            }
        }
    }
}










void func_021D7180(int a)
{
    if (func_021D580C((GsyncStateObj2 *)((char *)((*(int *)&((GsyncStateObj1 *)a)->f18)))) == 0)
        return;
    if (KEY_GetTrg() == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    if (((GsyncStateObj1 *)a)->f6C == 0) {
        func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D70BC, 0x217);
        return;
    }
    func_021D5A60((GsyncStateObj2 *)((char *)((*(int *)&((GsyncStateObj1 *)a)->f18))));
    func_021D57D0((void *)((*(int *)&((GsyncStateObj1 *)a)->f18)), 0x16, ((GsyncStateObj1 *)a)->f6C,
                 (void *)((*(int *)&((GsyncStateObj1 *)a)->fC)));
    func_021D56FC((GsyncStateObj5 *)((char *)((*(int *)&((GsyncStateObj1 *)a)->f18))), 0);
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
    ((GsyncStateObj1 *)a)->f78 = 0xb4;
    func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D7130, 0x222);
}









void func_021D7204(char *p) { func_021D62BC(((GsyncStateObj1 *)p)->f14,0,0); func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)),12); func_021D63D4((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14)); }








/*
 * lever: update the call-result local in both clamp arms to preserve its register.
 */
void func_021D7224(GsyncStateObj1 *p)
{
    void *g;
    void *q;
    int size;
    int n;
    g=func_02009448(p->f28);
    if (p->fC) {
        func_020307B0(p->fC);
        p->fC=0;
    }
    if (func_020076D0(p->f24,(int *)((char *)p+0x48),(int *)((char *)p+0x4c))) {
        q=func_02030734(p->f0,func_020173EC(),1,d_021DAB78,0x245);
        size=func_020173EC();
        func_02082D44(func_02009290(g),q,size);
        if (p->f6C) {
            n=func_02017E1C(q,158,0);
            if (n==100) p->f6C=0;
            if (n+p->f6C>100) {
                p->f6C=100-n;
                n=100;
            } else {
                n+=p->f6C;
            }
            func_02019CA0(q,n);
        }
        func_020074D8(p->f24,(const struct Sub02007454Entry *)((int)POKE_TOOL_GetBoxParam(q)));
        p->fC=q;
        func_020092F8(g,0);
        func_020093D4(g,p->f7C);
    }
}








void func_021D72D8(char *p)
{
    NotifyCallback cb;
    func_02009448(((GsyncStateObj1 *)p)->f28);
    if (GAME_DATA_SaveMain((*(void * *)&((GsyncStateObj1 *)p)->f2C))==2) {
        ((GsyncStateObj1 *)p)->fAD=0;
        ((GsyncStateObj1 *)p)->fAB=0;
        ((GsyncStateObj1 *)p)->fAE=0;
        func_021D584C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
        func_021D57D0(((GsyncStateObj1 *)p)->f18,45,0,(void *)(*(int *)&((GsyncStateObj1 *)p)->fC));
        func_021D5960((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18),1,4);
        func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)),0);
        func_021D62BC((u8 *)(((GsyncStateObj1 *)p)->f14),6,7);
        func_021D62BC((u8 *)(((GsyncStateObj1 *)p)->f14),0,1);
        cb.value=0; cb.object=p; cb.callback=func_021D7204;
        func_021D62D0((u8 *)(((GsyncStateObj1 *)p)->f14),0,(int)&cb);
        func_021D6650((GsyncStateObj1 *)((u8 *)(((GsyncStateObj1 *)p)->f14)),0);
        func_021D6458((struct GsyncObj171 *)(((GsyncStateObj1 *)p)->f14),(void *)func_020185F0(((GsyncStateObj1 *)p)->fC),0);
        func_021D652C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14));
        GFL_USE_PlaySeDefaultVolume(0x658);
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D7180,0x295);
    }
}








void func_021D7390(char *p)
{
    if (func_021D6E08((GsyncStateObj1 *)p,func_021B99DC(((GsyncStateObj1 *)p)->f10))==0) {
        if (func_021B9790(((GsyncStateObj1 *)p)->f10)==0) {
            func_021B97F4(((GsyncStateObj1 *)p)->f10);
            func_02009448(((GsyncStateObj1 *)p)->f28);
            ((GsyncStateObj1 *)p)->fAE=1;
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D72D8,0x2ae);
        }
    }
}








void func_021D73D8(char *p)
{
    if (((GsyncStateObj1 *)p)->f78) {
        --((GsyncStateObj1 *)p)->f78;
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (func_021B95D4(8,((GsyncStateObj1 *)p)->f10)) {
            p[2]=1;
            p[3]=0;
            func_021BE79C((void *)func_021B973C(((GsyncStateObj1 *)p)->f10),(void *)((unsigned int)(p+2)),4);
            if (func_021B9748(((GsyncStateObj1 *)p)->f10)==0)
                func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D7390,0x2cd);
        }
    }
}








void func_021D7430(u8 *p) { if(((GsyncStateObj1 *)p)->f70<100) ++((GsyncStateObj1 *)p)->f70; func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70); if(GAME_DATA_SaveMain((*(void * *)&((GsyncStateObj1 *)p)->f2C))==1) { ((GsyncStateObj1 *)p)->f78=func_020056EC(190); func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D73D8,0x2e6); } }








void func_021D746C(int a)
{
    int b;
    int i;
    u8 *p;
    b=(int)func_02009448((void *)((*(int *)&((GsyncStateObj1 *)a)->f28)));
    ((GsyncStateObj1 *)a)->fAB=1;
    func_021D7224((GsyncStateObj1 *)a);
    if(func_021D6EBC((GsyncStateObj1 *)a)==0) {
        func_021D7CB4(b,(u8 *)(((GsyncStateObj1 *)a)->f38));
        func_021D7DE8((GsyncStateObj1 *)a,b,(u8 *)(((GsyncStateObj1 *)a)->f38));
        func_021D7C54((void *)b,(char *)(((GsyncStateObj1 *)a)->f38));
        func_020092D0((struct Sub02009210Obj *)b,*(u8 *)(((GsyncStateObj1 *)a)->f38+0x5a));
    } else {
        p=(u8 *)((GsyncStateObj1 *)a)->f20+0xc;
        func_021D7D18((GsyncStateObj1 *)a,b,((GsyncStateObj28 *)p)->f2,p[7],p[6],((GsyncStateObj28 *)p)->f4,func_020056EC(8));
        for(i=0;i<20;i++) func_02009348((struct Sub02009210Obj *)b,i,*(u16 *)(p+8+i*2),p[0x30+i]);
    }
    ((GsyncStateObj1 *)a)->fAD=1;
    GAME_DATA_SaveStart(((GsyncStateObj1 *)a)->f2C);
    func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D7430,0x311);
}








void func_021D751C(int a)
{
    if (func_021D5D58((GsyncStateObj11 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D7858, 0x319);
        return;
    }
    ((GsyncStateObj1 *)a)->f80 = 0xfff0;
    func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D6FF0, 0x31d);
}








void func_021D7560(u8 *p) { p[165]=0; func_020307B0(((GsyncStateObj1 *)p)->f40); p[174]=0; ((GsyncStateObj1 *)p)->f40=0; func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D751C,0x328); }








void func_021D758C(u8 *a)
{
    int b = (int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)a)->f2C));
    if(GAME_DATA_PartSaveMain((char *)(((GsyncStateObj1 *)a)->f2C),4)==2) {
        func_0200734C((struct Sub02007324Ctrl *)b,4);
        func_020090F8((struct Sub020090B0Obj *)func_02009210((void *)b),1);
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D7560,0x333);
    }
}








void func_021D75D0(int a)
{
    u16 checksum;
    int b;
    u8 *p;
    int x;
    b=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)a)->f2C));
    p=(u8 *)func_021D5BA0((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)));
    checksum=func_0203F1FC(p,0x2600);
    if(checksum!=((GsyncStateObj31 *)p)->f2600) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x345);
        return;
    }
    ((GsyncStateObj1 *)a)->fAE=1;
    x=(int)func_02030734(((GsyncStateObj1 *)a)->f0,0x3000,0,d_021DAB78,0x34a);
    (*(int *)&((GsyncStateObj1 *)a)->f40)=x;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(b,4,((GsyncStateObj1 *)a)->f0,x,0x3000);
    func_02082D44(p,(void *)x,0x2600);
    func_02009108((struct Sub020090B0Obj *)func_02009210((void *)b),checksum);
    GAME_DATA_PartSaveStart((u8 *)((GsyncStateObj1 *)a)->f2C,4);
    func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D758C,0x355);
}








void func_021D768C(u8 *p) { p[166]=0; func_020307B0(((GsyncStateObj1 *)p)->f3C); p[174]=0; ((GsyncStateObj1 *)p)->f3C=0; func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D751C,0x360); }








void func_021D76B8(char *p) { int v; v=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)p)->f2C)); if(GAME_DATA_PartSaveMain((char *)(((GsyncStateObj1 *)p)->f2C),7)==2) { func_0200734C((struct Sub02007324Ctrl *)v,7); func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D768C,0x36a); } }








void func_021D76F0(int a)
{
    int b;
    u8 *p;
    int x;
    u16 checksum;
    b=(int)GAME_DATA_GetSaveControl((struct Big *)(((GsyncStateObj1 *)a)->f2C));
    p=(u8 *)func_021D5BA0((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)));
    checksum=func_0203F1FC(p,0x6200);
    if(checksum!=((GsyncStateObj32 *)p)->f6200) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x378);
        return;
    }
    ((GsyncStateObj1 *)a)->fAE=1;
    x=(int)func_02030734(((GsyncStateObj1 *)a)->f0,0x6800,0,d_021DAB78,0x37d);
    *(int *)&((GsyncStateObj1 *)a)->f3C=x;
    SAVE_CONTROL_LoadExtraSaveWithBuffer(b,7,((GsyncStateObj1 *)a)->f0,*(int *)&((GsyncStateObj1 *)a)->f3C,0x6800);
    func_02082D44(p,((GsyncStateObj1 *)a)->f3C,0x6200);
    func_0200E8E0((void *)(*(int *)&((GsyncStateObj1 *)a)->f3C),1);
    GAME_DATA_PartSaveStart((u8 *)((GsyncStateObj1 *)a)->f2C,7);
    func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D76B8,0x383);
}








void func_021D7798(u8 *p) { if(MUSICAL_DIST_SAVE_ProcessApply(((GsyncStateObj1 *)p)->f30)) { p[174]=0; ((GsyncStateObj1 *)p)->f30=0; func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D751C,0x38e); } }








void func_021D77C4(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    ((GsyncStateObj1 *)a)->fA4=0;
    p=(u8 *)func_021D5BA0((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)));
    h=n/2;
    if(n>0x1fc0e) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x39d);
        return;
    }
    checksum=func_0203F1FC(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x3a3);
        return;
    }
    ((GsyncStateObj1 *)a)->fAE=1;
    (*(int *)&((GsyncStateObj1 *)a)->f30)=(int)MUSICAL_DIST_SAVE_CreateFromData((void *)(((GsyncStateObj1 *)a)->f2C),p,n,((GsyncStateObj1 *)a)->f0);
    func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D7798,0x3a9);
}







void func_021D7858(int a)
{
    if(func_021D5C0C((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        if(func_021D5C2C((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
            ((GsyncStateObj1 *)a)->f80=0xfff0;
            func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x3b6);
            return;
        }
        func_021D5B70((GsyncStateObj2 *)((char *)(((GsyncStateObj1 *)a)->f8)));
        ((GsyncStateObj1 *)a)->f8=0;
        if(((int *)a)[28]<100) ((int *)a)[28]+=10;
        func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)a)->f14),((GsyncStateObj1 *)a)->f70);
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D7BDC,0x3c3);
    }
}







void func_021D78C0(int a)
{
    switch(((GsyncStateObj1 *)a)->fA7) {
    case 0: func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D75D0,0x3cb); break;
    case 1: func_021D77C4(a,(int)func_021D5D8C((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)a)->f8)))-2); break;
    case 2: func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D76F0,0x3d1); break;
    }
}







void func_021D7910(int a)
{
    if(func_021D5C2C((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x3dd);
        return;
    }
    if(func_021D5C0C((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        func_021D5C9C((GsyncStateObj11 *)((char *)(((GsyncStateObj1 *)a)->f8)));
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D78C0,0x3e8);
    }
}







void func_021D7960(int a)
{
    if (func_021D5D24((GsyncStateObj11 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D7910, 0x3f1);
        return;
    }
    ((GsyncStateObj1 *)a)->f80 = 0xfff0;
    func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D6FF0, 0x3f5);
}






void func_021D79A4(int a)
{
    if(func_021D5C2C((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        ((GsyncStateObj1 *)a)->f80=0xfff0;
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x3fe);
        return;
    }
    if(func_021D5C0C((GsyncStateObj1 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        if((void *)(int)func_021D5D8C((GsyncStateObj2 *)((u8 *)((int)((u8 *)(((GsyncStateObj1 *)a)->f8)))))==0) {
            ((GsyncStateObj1 *)a)->f80=0xfff0;
            func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D6FF0,0x407);
            return;
        }
        func_021D5C9C((GsyncStateObj11 *)((char *)(((GsyncStateObj1 *)a)->f8)));
        func_021D6EE0((GsyncStateObj1 *)a,(int)func_021D7960,0x40d);
    }
}






void func_021D7A18(int a)
{
    if (func_021D5CF8((GsyncStateObj11 *)((char *)(((GsyncStateObj1 *)a)->f8)))) {
        func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D79A4, 0x415);
        return;
    }
    ((GsyncStateObj1 *)a)->f80 = 0xfff0;
    func_021D6EE0((GsyncStateObj1 *)a, (int)func_021D6FF0, 0x419);
}






void func_021D7A5C(u8 *p)
{
    if (func_021D5C0C((GsyncStateObj1 *)((*(void * *)&((GsyncStateObj1 *)p)->f8)))) {
        if (func_021D5C2C((GsyncStateObj1 *)((*(void * *)&((GsyncStateObj1 *)p)->f8)))) {
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D6FF0, 0x424);
            return;
        }
        switch (p[0xa7]) {
        case 0:
            if (func_021D5C64((GsyncStateObj11 *)((*(void * *)&((GsyncStateObj1 *)p)->f8)), (void *)d_021DAB88, p[0xa5])) {
                func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7A18, 0x42b);
                return;
            }
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D6FF0, 0x42f);
            return;
        case 1:
            if (func_021D5C64((GsyncStateObj11 *)((*(void * *)&((GsyncStateObj1 *)p)->f8)), (void *)d_021DAB90, p[0xa4])) {
                func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7A18, 0x434);
                return;
            }
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D6FF0, 0x438);
            return;
        case 2:
            if (func_021D5C64((GsyncStateObj11 *)((*(void * *)&((GsyncStateObj1 *)p)->f8)), (void *)d_021DAB9C, p[0xa6])) {
                func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7A18, 0x43d);
                return;
            }
            ((GsyncStateObj1 *)p)->f80 = 0xfff0;
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D6FF0, 0x441);
            return;
        }
    }
}






void func_021D7B68(char *p)
{
    switch (((GsyncStateObj1 *)p)->fA7) {
    case 0: (*(void * *)&((GsyncStateObj1 *)p)->f8) = func_021D5B10(((GsyncStateObj1 *)p)->f0, MUSICAL_DIST_SAVE_GetBlockSize() + 4); break;
    case 1: (*(void * *)&((GsyncStateObj1 *)p)->f8) = func_021D5B10(((GsyncStateObj1 *)p)->f0, 0x20000); break;
    case 2: (*(void * *)&((GsyncStateObj1 *)p)->f8) = func_021D5B10(((GsyncStateObj1 *)p)->f0, func_0200E8B0() + 4); break;
    }
    if (func_021D5BD4((GsyncStateObj11 *)((*(void * *)&((GsyncStateObj1 *)p)->f8)))) {
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7A5C, 0x458);
        return;
    }
    ((GsyncStateObj1 *)p)->f80 = 0xfff0;
    func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D6FF0, 0x45c);
}





void func_021D7BDC(char *p)
{
    if (((GsyncStateObj1 *)p)->fA5) {
        p[0xa7] = 0;
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7B68, 0x465);
        return;
    }
    if (((GsyncStateObj1 *)p)->fA4) {
        p[0xa7] = 1;
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7B68, 0x46a);
        return;
    }
    if (((GsyncStateObj1 *)p)->fA6) {
        p[0xa7] = 2;
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7B68, 0x46f);
        return;
    }
    func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D746C, 0x472);
}





/*
 * extent: two zero alignment bytes at 021D7CB2 follow the return.
 */
void func_021D7C54(void *p, char *q)
{
    int changed = 0;
    int i;
    for (i = 0; i < 5; i++) {
        if (func_0203EFC8((const u8 *)func_02009390(p, i), (const u8 *)(q + 0x98 + i * 26), 26)) {
            changed = 1;
            break;
        }
    }
    if (changed) {
        for (i = 0; i < 5; i++) func_020093A8(p, i, q + 0x98 + i * 26);
        func_020093F0(p, 127);
    }
}





int func_021D7CB4(int a,u8 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)(p+92+i*2); if(n!=0 && n<=626) { func_02009348((struct Sub02009210Obj *)a,i,n,p[132+i]); result=1; } } return result; }





int func_021D7CEC(int a,GsyncStateObj3 *p) { int i,result; u16 n; result=0; for(i=0;i<20;i++) { n=*(u16 *)((u8 *)p+92+i*2); if(n!=0 && n<=626) result=1; } return result; }





void func_021D7D18(GsyncStateObj1 *p, int unused, int species, int gender, int form, int n, int value)
{
    int f;
    u8 v = value;
    void *h;
    int kind;
    int mapped;
    int g;
    if (species == 0 || species > 493) return;
    h = func_0202A128(p->f0);
    kind = 3;
    f = (int)func_02019D30((u16)species, (u8)form);
    g = func_02019C90(species, f, 20);
    mapped = func_02019D58(species, f);
    switch (g) {
    case 0: gender = 0; break;
    case 254: gender = 1; break;
    case 255: gender = 2; break;
    default: if (gender > 1) gender = func_020056EC(2); break;
    }
    if (func_0202A19C((*(unsigned int *)&p->f2C), h, species, gender, mapped)) kind = 2;
    if (v > 8) v = 0;
    func_0200E1A8(func_0200E0B0(p->f28), species, n, gender, mapped, v, kind);
    func_0202A170(h);
}





void func_021D7DE8(GsyncStateObj1 *p,int a,u8 *records) { int i; GsyncStateObj21 *r; for(i=0;i<10;i++) { r=(GsyncStateObj21 *) (records+i*8); if(r->f4==0) break; func_021D7D18(p,a,r->f4,((u8 *)r)[9],((u8 *)r)[8],r->f6,((u8 *)r)[10]); } }





void func_021D7E20(GsyncStateObj1 *p,GsyncStateObj3 *list) { int i; u16 n; for(i=0;i<20;i++) { n=*(u16 *)((u8 *)list+92+i*2); if(n!=0 && ((u8 *)list)[132+i]!=0 && n<=626) func_021D6AA8(p->f14,i,n); } }





/*
 * lever: bind the record word before the call and use shared goto guards.
 */
void func_021D7E58(GsyncStateObj1 *p, void *h, GsyncStateObj3 *q, int *r)
{
    int i;
    int v;
    if (*r != 0) {
        p->f80 = *r;
        func_021D6EE0(p, (int)func_021D6FF0, 0x500);
        return;
    }
    if (((u8 *)q)[0x5b] != 0) goto unchanged;
    v = *(int *)q;
    if (v == func_020093D0(h)) goto unchanged;
    {
        p->f7C = v;
        ((u8 *)p)[0xa4] = ((u8 *)q)[0x57];
        ((u8 *)p)[0xa5] = ((u8 *)q)[0x58];
        ((u8 *)p)[0xa6] = ((u8 *)q)[0x59];
        p->f6C = q->f54;
        if (((u8 *)p)[0xa5]) ((u8 *)p)[0xa8] |= 1;
        if (((u8 *)p)[0xa4]) ((u8 *)p)[0xa8] |= 2;
        if (((u8 *)p)[0xa6]) ((u8 *)p)[0xa8] |= 4;
        for (i = 0; i < 10; i++) {
            if (*(u16 *)((u8 *)q+i*8+4) == 0) break;
            func_021D6A70(p->f14, i+20, *(u16 *)((u8 *)q+i*8+4), ((u8 *)q)[i*8+8], ((u8 *)q)[i*8+9]);
        }
        ((u8 *)p)[0xa9] = func_021D7CEC((int)h,q);
        func_021D7E20(p,q);
        func_021D6AB8((GsyncStateObj2 *)(p->f14));
    }
    goto done;
unchanged:
    ((u8 *)p)[0xa9] = 0;
done:
    func_021D7BDC((char *)p);
}




int func_021D7F5C(GsyncStateObj1 *p)
{
    int i, j;
    char *q;
    func_02009448(p->f28);
    q = (char *)p->f20 + 0xc;
    for (i = 0; i < 20; i++) {
        for (j = i + 1; j < 20; j++) {
            if (*(u16 *)(q + i * 2 + 8) != 0 &&
                *(u16 *)(q + j * 2 + 8) == *(u16 *)(q + i * 2 + 8))
                return 0;
        }
    }
    return 1;
}




void func_021D7F9C(char *p)
{
    char *q, *data;
    void *v, *allocated;
    if (func_021D6E70((GsyncStateObj1 *)p) && !func_021D6EBC((GsyncStateObj1 *)p)) {
        if (((GsyncStateObj1 *)p)->f70<30) ++((GsyncStateObj1 *)p)->f70;
        func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
        if (func_021D6E08((GsyncStateObj1 *)p,func_021B99DC(((GsyncStateObj1 *)p)->f10))) return;
        if (func_021B9790(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((GsyncStateObj1 *)p)->f10));
        v=func_02009448(((GsyncStateObj1 *)p)->f28);
        data=q+0x80;
        allocated=func_02030734(((GsyncStateObj1 *)p)->f0,0x11c,1,d_021DAB78,0x573);
        (*(void * *)&((GsyncStateObj1 *)p)->f38)=allocated;
        func_02082D44(data,allocated,0x11c);
        func_021D7E58((GsyncStateObj1 *)p,v,(GsyncStateObj3 *)data,(int *)q);
        return;
    } else {
        ++((GsyncStateObj1 *)p)->f74;
        if (((GsyncStateObj1 *)p)->f70<30) ++((GsyncStateObj1 *)p)->f70;
        if (((GsyncStateObj1 *)p)->f74==360) {
            func_021D5950((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18),43);
            func_021D59E4((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==720) {
            func_021D5950((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18),44);
            func_021D59E4((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==1080) {
            if (func_021D6EA4((GsyncStateObj1 *)p)) func_021D5A60((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
            if (func_021D7F5C((GsyncStateObj1 *)p)) {
                func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D746C,0x58c);
            } else {
                ((GsyncStateObj1 *)p)->f80=9;
                func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6FF0,0x591);
            }
        }
        func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
    }
}




void func_021D80B8(char *p)
{
    if (func_021D6E70((GsyncStateObj1 *)p) && !func_021D6EBC((GsyncStateObj1 *)p)) {
        if (func_021B95D4(2, ((GsyncStateObj1 *)p)->f10) && !func_021B9748(((GsyncStateObj1 *)p)->f10)) {
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7F9C, 0x59d);
            return;
        }
    } else {
        if (func_021D6EA4((GsyncStateObj1 *)p)) {
            ((GsyncStateObj1 *)p)->f74 = 0;
            func_021D5950((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)p)->f18)), 42);
            func_021D59E4((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18));
        } else {
            ((GsyncStateObj1 *)p)->f74 = 0x42e;
        }
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D7F9C, 0x5aa);
    }
}




void func_021D8130(char *p) { if(func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D80B8,0x5b3); }




void func_021D8154(char *p)
{
    func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 11);
    func_021D5A7C((GsyncStateObj9 *)(((GsyncStateObj1 *)p)->f18));
    func_021D62E0(((GsyncStateObj1 *)p)->f14, 8);
    func_021D65F4((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)p)->f14)));
    func_021D6650((GsyncStateObj1 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 1);
    func_021D62BC(((GsyncStateObj1 *)p)->f14, 6, 5);
    func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 0);
    func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 12);
    GFL_USE_PlaySeDefaultVolume(0x657);
    func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8130, 0x5c3);
}




void func_021D81B4(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D706C, 0x5d0);
        }
    }
}




void func_021D81E4(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 16);
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D81B4, 0x5de);
    }
}




void func_021D8210(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D706C, 0x5e9);
        }
    }
}




void func_021D8244(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 49);
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8210, 0x5f6);
    }
}




void func_021D8270(char *p)
{
    if (((GsyncStateObj1 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((GsyncStateObj1 *)p)->f64)++;
    if (APP_TASKMENU_IsFinish(((GsyncStateObj1 *)p)->f1C)) {
        if (APP_TASKMENU_GetCursorPos(((GsyncStateObj1 *)p)->f1C) == 0) {
            if (func_020076D0(((GsyncStateObj1 *)p)->f24, (int *)(p + 0x48), (int *)(p + 0x4c)) == 0)
                func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8244, 0x60f);
            else
                func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8154, 0x612);
        } else {
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D706C, 0x616);
        }
        func_021D584C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
        APP_TASKMENU_CloseMenu(((GsyncStateObj1 *)p)->f1C);
        *(unsigned short *)0x04001050 = 0;
        ((GsyncStateObj1 *)p)->f1C = 0;
    }
}




void func_021D8304(char *p)
{
    if (((GsyncStateObj1 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((GsyncStateObj1 *)p)->f64)++;
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        ((GsyncStateObj1 *)p)->f1C = (void *)func_021D5890((GsyncStateObj9 *)(((GsyncStateObj1 *)p)->f18), 0);
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8270, 0x632);
    }
}




void func_021D834C(char *p)
{
    func_021D584C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
    func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 0);
    func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 12);
    func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 6);
    func_021D62B4((GsyncStateObj17 *)((u8 *)(((GsyncStateObj1 *)p)->f14)), 8);
    if (func_02009370((const struct Sub02009210Obj *)func_02009448(((GsyncStateObj1 *)p)->f28)))
        func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 21);
    else
        func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 10);
    func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8304, 0x64c);
}




void func_021D83A4(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D834C, 0x68d);
    }
}




void func_021D83C8(char *p)
{
    if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
        func_021D5A60((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
        func_020092E0((struct Sub02009210Obj *)func_02009448(((GsyncStateObj1 *)p)->f28), 1);
        p[0xaf] = 1;
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8958, 0x6a2);
    }
}




void func_021D840C(char *p)
{
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
        func_021D5950((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)p)->f18)), 48);
        func_021D5960((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 7, 14);
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D83C8, 0x6ab);
    }
}




void func_021D8448(char *p)
{
    func_021D5AB0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18), func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct GsyncObj174 *)(((GsyncStateObj1 *)p)->f20))->f4)));
    func_021D56FC((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 1);
    func_021D5950((GsyncStateObj2 *)((u8 *)(((GsyncStateObj1 *)p)->f18)), 47);
    func_021D5960((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 7, 14);
    func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D840C, 0x6b7);
}




void func_021D8490(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (func_021D6E08((GsyncStateObj1 *)p, func_021B99DC(((GsyncStateObj1 *)p)->f10))) return;
        if (func_021B9790(((GsyncStateObj1 *)p)->f10)) return;
        q = (char *)func_021B97F4((u8 *)(((GsyncStateObj1 *)p)->f10));
        if (((GsyncStateObj19 *)q)->f0 == 2) {
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8958, 0x6d4);
            return;
        }
        if (((GsyncStateObj19 *)q)->f0 == 0) {
            func_021D584C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8448, 0x6d8);
            return;
        }
        ((GsyncStateObj1 *)p)->f80 = ((GsyncStateObj19 *)q)->f0;
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D6FF0, 0x6dc);
        return;
    } else {
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8958, 0x6e2);
    }
}




void func_021D8520(char *p)
{
    int x;
    unsigned int v;
    if (GFL_NET_GetRunState()) {
        if (func_021B95D4(9,*(void **)(p+0x10))) {
            v=(unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p+0x28),&x);
            func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
            if (!func_021B9748(*(void **)(p+0x10)))
                func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8490,0x6fa);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8490,0x700);
    }
}




void func_021D8590(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D83A4, 0x727);
        }
    }
}




void func_021D85C4(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 17);
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8590, 0x739);
    }
}




void func_021D85F0(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D706C, 0x746);
        }
    }
}




void func_021D8624(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 20);
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D85F0, 0x758);
    }
}




void func_021D8650(GsyncStateObj1 *p,int x,int *q)
{
    int state;
    switch (*q) {
    case 0:
        state=((struct GsyncObj175 *)(p->f20))->f1C8;
        switch (state) {
        case 0:
            if (x==0) func_021D6EE0(p,(int)func_021D83A4,0x774);
            else if (x==3) func_021D6EE0(p,(int)func_021D83A4,0x777);
            else if (x==1) func_021D6EE0(p,(int)func_021D85C4,0x77b);
            else if (x==2) func_021D6EE0(p,(int)func_021D8624,0x77f);
            else if (x==4) func_021D6EE0(p,(int)func_021D83A4,0x782);
            else func_021D6EE0(p,(int)func_021D83A4,0x787);
            break;
        case 3:
            if (p->fAF==0) func_021D6EE0(p,(int)func_021D8448,0x78c);
            else func_021D6EE0(p,(int)func_021D8958,0x78f);
            break;
        }
        break;
    case 5:
        if (((struct GsyncObj175 *)(p->f20))->f1C8==3)
            func_021D6EE0(p,(int)func_021D8958,0x797);
        else {
            p->f80=*q;
            func_021D6EE0(p,(int)func_021D6FF0,0x79b);
        }
        break;
    case 8:
        switch (((struct GsyncObj175 *)(p->f20))->f1C8) {
        case 0: func_021D6EE0(p,(int)func_021D83A4,0x7a2); break;
        case 3: func_021D6EE0(p,(int)func_021D8520,0x7a6); break;
        }
        break;
    default:
        p->f80=*q;
        func_021D6EE0(p,(int)func_021D6FF0,0x7ac);
        break;
    }
}




void func_021D8790(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (func_021D6E08((GsyncStateObj1 *)p,func_021B99DC(((GsyncStateObj1 *)p)->f10))) return;
        if (func_021B9790(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((GsyncStateObj1 *)p)->f10));
        func_02082D44(q+0x80,(char *)((GsyncStateObj1 *)p)->f20+0xc,0x44);
        ((struct GsyncObj175 *)(((GsyncStateObj1 *)p)->f20))->f50=1;
        func_021D8650((GsyncStateObj1 *)p,((GsyncStateObj3 *)q)->f80,(int *)q);
    } else {
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D83A4,0x7d4);
    }
}




void func_021D87F8(char *p)
{
    func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18),13);
    func_021D5A7C((GsyncStateObj9 *)(((GsyncStateObj1 *)p)->f18));
    if (GFL_NET_GetRunState()) {
        if (func_021B95D4(0,((GsyncStateObj1 *)p)->f10)) {
            if (!func_021B9748(((GsyncStateObj1 *)p)->f10))
                func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8790,0x7ea);
        }
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8790,0x7f1);
    }
}




void func_021D885C(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg()) {
            ((struct GsyncObj176 *)(((GsyncStateObj1 *)p)->f20))->f1C8 = 1;
            func_021D584C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
            func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D6F04, 0x808);
        }
    }
}




void func_021D88A0(char *p)
{
    func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18), 19);
    func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D885C, 0x817);
}




void func_021D88C0(char *p)
{
    char *q;
    int state;
    if (GFL_NET_GetRunState()) {
        if (func_021D6E08((GsyncStateObj1 *)p,func_021B99DC(((GsyncStateObj1 *)p)->f10))) return;
        if (func_021B9790(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((GsyncStateObj1 *)p)->f10));
        state=((GsyncStateObj33 *)q)->f0;
        if (state==0 || state==8) {
            func_02082D44(q+0x80,(char *)((GsyncStateObj1 *)p)->f20+0x1d8,0x80);
            ((struct GsyncObj175 *)(((GsyncStateObj1 *)p)->f20))->f1C8=5;
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6F04,0x837);
        } else {
            ((GsyncStateObj1 *)p)->f80=state;
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6FF0,0x842);
        }
    } else {
        ((struct GsyncObj175 *)(((GsyncStateObj1 *)p)->f20))->f1C8=5;
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6F04,0x849);
    }
}




void func_021D8958(char *p)
{
    struct RtcDate_021D634C saved, current;
    u32 value;
    int day;
    if (func_02008BD0(func_02008B14(((GsyncStateObj1 *)p)->f28)) && ((GsyncStateObj1 *)p)->fAC) {
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D81E4,0x85c);
        return;
    }
    value=func_020093C8((const struct Sub02009210Obj *)func_02009448(((GsyncStateObj1 *)p)->f28));
    saved.year=(u8)(value>>24);
    saved.month=(u8)(value>>16);
    saved.day=(u8)(value>>8);
    saved.week=(u8)value;
    func_0203F4E4((struct RtcDate_021D634C *)&current);
    day=func_0203F540((struct RtcDate_021D634C *)&saved);
    if (day==func_0203F540((struct RtcDate_021D634C *)&current)) {
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D81E4,0x869);
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (func_021B95D4(1,((GsyncStateObj1 *)p)->f10) && !func_021B9748(((GsyncStateObj1 *)p)->f10))
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D88C0,0x871);
    } else {
        if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D88C0,0x878);
    }
}




void func_021D8A38(char *p)
{
    if (((GsyncStateObj1 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    ++((GsyncStateObj1 *)p)->f64;
    if (KEY_GetTrg() || TOUCHPANEL_GetTrg())
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D706C, 0x88e);
}




void func_021D8A7C(char *p)
{
    if (func_021D580C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18))) {
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8A38, 0x8a0);
    }
}



void func_021D8A9C(char *p)
{
    if (((GsyncStateObj1 *)p)->f44) {
        func_020307B0(((GsyncStateObj1 *)p)->f44);
        ((GsyncStateObj1 *)p)->f44=0;
    }
    ((GsyncStateObj1 *)p)->f70=100;
    func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),100);
    func_021D57D0(((GsyncStateObj1 *)p)->f18,14,0,(void *)((*(int *)&((GsyncStateObj1 *)p)->fC)));
    func_021D56FC((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18),0);
    func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),8);
    func_021D6650((GsyncStateObj1 *)(((GsyncStateObj1 *)p)->f14),0);
    func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),0);
    func_021D62BC(((GsyncStateObj1 *)p)->f14,4,6);
    GFL_USE_PlaySeDefaultVolume(0x658);
    func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8A7C,0x8bd);
}



void func_021D8B0C(char *p)
{
    if (((GsyncStateObj1 *)p)->f70<100) ++((GsyncStateObj1 *)p)->f70;
    func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
    switch (GAME_DATA_SaveMain((*(void * *)&((GsyncStateObj1 *)p)->f2C))) {
    case 1:
        if (((GsyncStateObj1 *)p)->f34) {
            func_020307B0(((GsyncStateObj1 *)p)->f34);
            ((GsyncStateObj1 *)p)->f34=0;
        }
        break;
    case 3:
        GFL_NET_STATE_SetError(0,0,0,0x3f3);
        GFL_NET_STATE_SetErrorMode(0);
        break;
    case 2:
        p[0xad]=0;
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8A9C,0x8e6);
        break;
    }
}



/*
 * lever: GAME_DATA_GetTrainerRecord leaves its return in r0 for func_02008DF0.
 */
void func_021D8B7C(char *p)
{
    void *q;
    struct RtcDate_021D8A9C date;
    q=func_02009448(((GsyncStateObj1 *)p)->f28);
    p[0xaa]=0;
    func_0203F4E4((struct RtcDate_021D634C *)&date);
    func_020093CC(q, (date.year << 24) | ((date.month & 255) << 16) | ((date.day & 255) << 8) | date.week);
    if (func_020093D8(q)!=127) {
        func_02009428(q,1);
        func_020093F0(q,126);
    }
    ((GsyncStateObj1 *)p)->f70=50;
    func_02008DF0(GAME_DATA_GetTrainerRecord((*(void * *)&((GsyncStateObj1 *)p)->f2C)),119);
    p[0xad]=1;
    GAME_DATA_SaveStart((int)((*(void * *)&((GsyncStateObj1 *)p)->f2C)));
    func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8B0C,0x914);
}



void func_021D8C04(char *p)
{
    char *q;
    int state;
    func_02009448(((GsyncStateObj1 *)p)->f28);
    func_021D6934(((GsyncStateObj1 *)p)->f14);
    if (func_021D6EA4((GsyncStateObj1 *)p)) {
        if (((GsyncStateObj1 *)p)->f74==0) {
            func_021D5950((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18),42);
            func_021D59E4((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==360) {
            func_021D5950((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18),43);
            func_021D59E4((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18));
        } else if (((GsyncStateObj1 *)p)->f74==720) {
            func_021D5950((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18),44);
            func_021D59E4((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18));
        }
        ++((GsyncStateObj1 *)p)->f74;
    }
    if (func_021D6E70((GsyncStateObj1 *)p)) {
        if (((GsyncStateObj1 *)p)->f70<50) ++((GsyncStateObj1 *)p)->f70;
        func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f70);
        if (func_021D6E08((GsyncStateObj1 *)p,func_021B99DC(((GsyncStateObj1 *)p)->f10))) return;
        if (func_021B9790(((GsyncStateObj1 *)p)->f10)) return;
        q=(char *)func_021B97F4((u8 *)(((GsyncStateObj1 *)p)->f10));
        if (func_021D6EA4((GsyncStateObj1 *)p)) func_021D5A60((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
        state=((GsyncStateObj34 *)q)->f0;
        if (state==0) {
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8B7C,0x955);
            return;
        }
        ((GsyncStateObj1 *)p)->f80=state;
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D6FF0,0x959);
        return;
    } else {
        func_021D66D0((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14),((GsyncStateObj1 *)p)->f68);
        if (++((GsyncStateObj1 *)p)->f68==100) {
            if (func_021D6EA4((GsyncStateObj1 *)p)) func_021D5A60((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f18));
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8B7C,0x967);
        }
    }
}



/*
 *   Run 2 also left ov114 0x021B973C unresolved; S23 has since verified its
 *   pkt_ov114_021B973C shard. No caller retry while ARM9 remains blocked.
 *   extern unsigned int BACKUP_SYSTEM_GetWork(void *, int *);
 *   unsigned int SAVE_CONTROL_GetWorkArea(char *p, int *out) {
 *       return BACKUP_SYSTEM_GetWork(*(void **)(p + 0x10), out);
 *   }
 */
void func_021D8D08(char *p)
{
    int x;
    unsigned int v;
    func_02009448(*(void **)(p+0x28));
    if (func_021D580C((GsyncStateObj2 *)(*(char **)(p+0x18)))) {
        *(int *)(p+0x74)=0;
        if (func_021D6E70((GsyncStateObj1 *)p)) {
            if (func_021B95D4(3,*(void **)(p+0x10))) {
                v=(unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p+0x28),&x);
                func_021BE79C((void *)func_021B973C(*(void **)(p+0x10)),(void *)v,0x80000);
                func_021D66D0((GsyncStateObj2 *)(*(void **)(p+0x14)),0);
                *(int *)(p+0x70)=0;
                if (!func_021B9748(*(void **)(p+0x10)))
                    func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8C04,0x986);
            }
        } else {
            func_021D66D0((GsyncStateObj2 *)(*(void **)(p+0x14)),0);
            func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8C04,0x98c);
        }
    }
}



void func_021D8D98(char *p)
{
    if (--((GsyncStateObj1 *)p)->f60==0) {
        func_021D65F4((GsyncStateObj2 *)((unsigned char *)(((GsyncStateObj1 *)p)->f14)));
        func_021D57B8((GsyncStateObj5 *)(((GsyncStateObj1 *)p)->f18),8);
        func_021D5A7C((GsyncStateObj9 *)(((GsyncStateObj1 *)p)->f18));
        func_021D6650((GsyncStateObj1 *)(((GsyncStateObj1 *)p)->f14),1);
        func_021D62BC(((GsyncStateObj1 *)p)->f14,4,5);
        func_021D62BC(((GsyncStateObj1 *)p)->f14,0,0);
        func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),12);
        GFL_USE_PlaySeDefaultVolume(0x657);
        func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8D08,0x9a8);
    }
}



void func_021D8DFC(char *p) { if(--((GsyncStateObj1 *)p)->f60==0) { func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),4); ((GsyncStateObj1 *)p)->f60=60; func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8D98,0x9b9); } }



void func_021D8E28(char *p)
{
    if (--((GsyncStateObj1 *)p)->f60 == 0) {
        func_021D62BC(((GsyncStateObj1 *)p)->f14, 0, 1);
        func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14), 2);
        func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14), 3);
        ((GsyncStateObj1 *)p)->f60 = 15;
        func_021D6EE0((GsyncStateObj1 *)p, (int)func_021D8DFC, 0x9cf);
    }
}



void func_021D8E68(char *p) { if(--((GsyncStateObj1 *)p)->f60==0) { func_021D62A8((GsyncStateObj15 *)(((GsyncStateObj1 *)p)->f14)); func_021D651C((GsyncStateObj2 *)(((GsyncStateObj1 *)p)->f14)); ((GsyncStateObj1 *)p)->f60=70; func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8E28,0x9e4); } }



void func_021D8E98(char *p) { func_021D6458(((GsyncStateObj1 *)p)->f14,(void *)func_020185F0(((GsyncStateObj1 *)p)->fC),1); ((GsyncStateObj1 *)p)->f60=10; func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8E68,0x9f6); }



void func_021D8EC4(char *p)
{
    void *v;
    void *q;
    void *t;
    v=func_02009448(((GsyncStateObj1 *)p)->f28);
    if (((GsyncStateObj1 *)p)->fC) {
        func_020307B0(((GsyncStateObj1 *)p)->fC);
        ((GsyncStateObj1 *)p)->fC=0;
    }
    t=func_02007A18(((GsyncStateObj1 *)p)->f24,((GsyncStateObj1 *)p)->f48,((GsyncStateObj1 *)p)->f4C);
    if (t) {
        q=POKE_TOOL_CreateFromBoxParam(t,((GsyncStateObj1 *)p)->f0);
        func_02009294(v,q);
        ((GsyncStateObj1 *)p)->fC=q;
        func_02007664(((GsyncStateObj1 *)p)->f24,((GsyncStateObj1 *)p)->f48,((GsyncStateObj1 *)p)->f4C);
        func_020092F8(v,1);
        ((GsyncStateObj1 *)p)->fAA=1;
    }
    func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),0);
    func_021D62B4((GsyncStateObj17 *)(((GsyncStateObj1 *)p)->f14),12);
    func_021D6EE0((GsyncStateObj1 *)p,(int)func_021D8E98,0xa2a);
}




void func_021D8F3C(char *p)
{
    if (*(u32 *)&((GsyncStateObj1 *)p)->f10 != 0) {
        func_021B9774(((GsyncStateObj1 *)p)->f10);
        func_021B9838(((GsyncStateObj1 *)p)->f10);
        *(u32 *)&((GsyncStateObj1 *)p)->f10 = 0;
    }
}



/*
 * extent: two zero alignment bytes follow the return.
 */
void func_021D8F58(GsyncStateObj1 *p)
{
    void *v;
    void *q;
    v=func_02009448(p->f28);
    if (p->f34) {
        func_02082D44(p->f34,v,func_02009228());
        func_020307B0(p->f34);
        p->f34=0;
    }
    if (p->fAA) {
        q=func_02009290(v);
        func_020075B0(p->f24,p->f48,p->f4C,POKE_TOOL_GetBoxParam(q));
        POKE_TOOL_ClearPartyParam(q);
        func_020092F8(v,0);
        p->fAA=0;
    }
}



/*
 * interface: 0203159C returns the allocation live in r0 (original store
 * at 020315C0, then return); legacy matched definition says void.
 */
int func_021D8FBC(void *a,int b,GsyncStateObj3 *q)
{
    GsyncStateObj1 *p;
    int value;
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1,98,0x88000);
    p=(GsyncStateObj1 *) PROCSYS_AllocProcWork(a,0xb0,98);
    MI_CpuFill8(p,0,0xb0);
    p->f0=98;
    if (!q) func_02034714(d_021DABA4,0,d_021DABA4);
    if (q) {
        p->f20=(char *)q;
        (*(void * *)&p->f2C)=q->f4;
        p->f28=GAME_DATA_GetSaveControl(q->f4);
        value=func_0200853C((const struct Sub0200852CObj *)func_02012944(q->f4));
        (*(unsigned int *)&p->f24)=func_0201293C(q->f4);
        p->f48=q->f1D0;
        p->f4C=q->f1D2;
        p->fAC=func_020092EC((const struct Sub02009210Obj *)func_02009448(p->f28));
        p->fAF=p->fAC;
        func_02009448(p->f28);
        switch (q->f1C8) {
        case 0:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D87F8,0xa89);
            break;
        case 1:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D8EC4,0xa8d);
            break;
        case 2:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D8EC4,0xa91);
            break;
        case 3:
            if (!value) func_02034714(d_021DABA4,0,d_021DABA4);
            func_021D6EE0(p,(int)func_021D87F8,0xa95);
            break;
        case 4:
            func_021D6EE0(p,(int)func_021D88A0,0xa98);
            break;
        }
        if (*(int *)&q->f1C8!=4) {
            p->f10=func_021B9800(98,value,(int)((char *)q+0x54));
            DWC_RAP_SetErrorCallback((int)func_021D8F3C,(int)p);
        }
    }
    p->f14=func_021D5D94(p->f0);
    p->f18=func_021D54F4(p->f0,39);
    WIPE_SYS_Start(0,1,1,0,6,1,p->f0);
    GFL_NET_RestartWithDefaultTimeout(0,p->f0);
    return 1;
}



int func_021D9158(void *a, int b, int c, GsyncStateObj1 *p)
{
    void (*callback)(char *);
    int result;
    callback=*(void (**)(char *))((char *)p+0x50);
    result=1;
    if (WIPE_SYS_EndCheck() && !p->fAE && func_0200FB24()) {
        if ((*(void * *)&p->f8)) func_021D5D58((GsyncStateObj11 *)((*(void * *)&p->f8)));
        func_021B9774(p->f10);
        if (p->fAD) {
            GAME_DATA_SaveCancel((*(void * *)&p->f2C));
            p->fAD=0;
        }
        func_021D8F58(p);
        if (p->fAB) func_0200F7C0(41);
        WIPE_SetBrightnessFadeOut(0,0);
        WIPE_SetBrightnessFadeOut(1,0);
        DWC_RAPCOMMON_HandleNetError(1,0);
        ((struct GsyncObj177 *)(p->f20))->f1C8=7;
        return 1;
    }
    if (callback) { callback((char *)p); result=0; }
    if (p->f1C) APP_TASKMENU_UpdateMenu(p->f1C);
    if ((*(void * *)&p->f8)) func_021D5D7C((GsyncStateObj1 *)((*(void * *)&p->f8)));
    func_021D5E60((GsyncStateObj2 *)(p->f14));
    func_021D562C((GsyncStateObj2 *)(p->f18));
    return result;
}



/*
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 */
int func_021D920C(void *a, int b, int c, GsyncStateObj10 *p)
{
    if (!WIPE_SYS_EndCheck()) return 0;
    if (p->f1C) APP_TASKMENU_CloseMenu(p->f1C);
    if (p->f38) {
        func_020307B0(p->f38);
        p->f38=0;
    }
    func_021D5644((GsyncStateObj2 *)(p->f18));
    func_021D5E8C((GsyncStateObj2 *)(p->f14));
    func_021D5B70((GsyncStateObj2 *)(p->f8));
    if (p->f30) func_020307B0(p->f30);
    if (p->f3C) func_020307B0(p->f3C);
    if (p->f40) func_020307B0(p->f40);
    if (p->fC) func_020307B0(p->fC);
    if (p->f44) func_020307B0(p->f44);
    if (GFL_NET_GetRunState()) DWC_RAP_SetErrorHookCallback(0,0);
    if (p->f10) {
        func_021B9838(p->f10);
        DWC_RAP_SetErrorCallback(0,0);
    }
    func_020315D4(a);
    func_020306F0(98);
    func_02034A5C((int)ov114_id);
    return 1;
}




void func_021D92B8(GsyncStateObj2 *p)
{
    if (p->f1C) {
        BUTTON_MAN_Delete(p->f1C);
        *(u32 *)&p->f1C = 0;
    }
}



u8 *func_021D92CC(u32 heap,u32 bank)
{
    GsyncStateObj8 *p;
    p=(GsyncStateObj8 *) func_02030734(heap,0xb4,1,d_021DABA8,0x9b);
    p->fB0=heap;
    BMP_WIN_Init(p->fB0);
    func_0201DD60();
    p->f88=TCBL_Create(p->fB0,p->fB0,2,0);
    p->f8C=PRINTSYS_QUE_Create((void *)(u32)p->fB0);
    p->f2C=STRBUF_Create(400,p->fB0);
    p->f30=STRBUF_Create(400,p->fB0);
    p->f28=GF_FONT_Create(23,0,0,0,p->fB0);
    p->f20=func_02045B38(0,2,(u16)bank,p->fB0);
    p->f24=func_0201EC64(p->fB0);
    p->fAC=APP_TASKMENU_RES_Create(5,9,*(u32 *)&p->f28,p->f8C,p->fB0);
    p->f0=func_0201F5DC((void *)1,12,0,p->fB0);
    p->f8=func_0201F5DC((void *)5,12,0,p->fB0);
    p->f4=func_0201F5DC((void *)6,12,0,p->fB0);
    func_02049B40(23,5,4,352,32,p->fB0);
    func_02049B40(23,5,0,352,32,p->fB0);
    return (u8 *)p;
}




void func_021D9404(GsyncStateObj2 *p)
{
    TCBL_Main(p->f88);
    PRINTSYS_QUE_Main(p->f8C);
}



void func_021D941C(GsyncStateObj2 *p)
{
    u32 a;
    int i;
    func_0203FB44(1,(u16)(p->f0),(u16)(p->f0>>16));
    a=p->f8>>16;
    func_0203FB44(5,(u16)(p->f8),(u16)a);
    a=p->f4>>16;
    func_0203FB44(6,(u16)(p->f4),(u16)a);
    func_021D92B8(p);
    func_0201DD68();
    MSGDATA_Delete(p->f20);
    GF_FONT_Delete(p->f28);
    STRBUF_Delete(p->f2C);
    STRBUF_Delete(p->f30);
    func_0201ED04(p->f24);
    APP_TASKMENU_RES_Delete(p->fAC);
    PRINTSYS_QUE_Clear(p->f8C);
    PRINTSYS_QUE_Delete(p->f8C);
    if (p->f80) PRINTSYS_PrintStreamDelete(p->f80);
    if (p->f90) {
        TIME_ICON_Delete(p->f90);
        p->f90=0;
    }
    if (p->f40) BMP_WIN_Delete(p->f40);
    if (p->f44) BMP_WIN_Delete(p->f44);
    if (p->f48) BMP_WIN_Delete(p->f48);
    if (p->f4C) BMP_WIN_Delete(p->f4C);
    for(i=0;i<12;i++) if (*(void **)((u8 *)p+i*4+0x50)) BMP_WIN_Delete(*(void **)((u8 *)p+i*4+0x50));
    TCBL_Destroy(p->f88);
    BMP_WIN_Exit();
    func_020307B0(p);
}



void func_021D9514(GsyncStateObj5 *p, int n)
{
    void *q;
    func_02045CAC(p->f20,n,p->f2C);
    if (!p->f48) p->f48=(void *)BMP_WIN_Create(5,1,3,30,4,11,1);
    q=p->f48;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    p->f80=PRINTSYS_PrintStream(q, 0, 0, p->f2C, p->f28, (void *)(func_02012FFC()), p->f88, 2, p->fB0, 15);
    func_0201F73C(q,1,(u16)(p->f8),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(5);
}



/*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 */
void func_021D95B4(GsyncStateObj3 *p) { if(p->f90) { TIME_ICON_Delete(p->f90); p->f90=0; } p->f90=TIME_ICON_CreateNode(p->f88,p->f48,15,16,p->fB0); }



int func_021D95F0(GsyncStateObj2 *p)
{
    if (p->f80) {
        switch (PRINTSYS_PrintStreamGetState(p->f80)) {
        case 2:
            PRINTSYS_PrintStreamDelete(p->f80);
            p->f80=0;
            break;
        case 1:
            if (KEY_GetTrg()==1) PRINTSYS_PrintStreamReleasePause(p->f80);
            break;
        }
        return 0;
    }
    return 1;
}



void func_021D9634(GsyncStateObj2 *p) { if(p->f90) { TIME_ICON_Delete(p->f90); p->f90=0; } if(p->f48) { func_0201F7A8(p->f48,2); BMP_WIN_ClearScreen(p->f48); func_02041B6C(5); BMP_WIN_Delete(p->f48); p->f48=0; } }



int func_021D9670(char *p,int mode) {
    Config c;
    int result;
    c.size=*(u16 *)(p+0xb0);
    c.flag=2;
    c.target=p+0x94;
    switch (mode) {
    case 0: c.x=32; c.y=14; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    *(void **)(p+0x94)=STRBUF_Create(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),4,*(void **)(p+0x94));
    *(u16 *)(p+0x98)=0x39e0;
    *(void **)(p+0xa0)=STRBUF_Create(100,*(u16 *)(p+0xb0));
    func_02045CAC(*(void **)(p+0x20),5,*(void **)(p+0xa0));
    *(u16 *)(p+0xa4)=0x39e0;
    result=(int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&c),*(void **)(p+0xac));
    STRBUF_Delete(*(void **)(p+0x94));
    STRBUF_Delete(*(void **)(p+0xa0));
    func_0207D658(0x04001050,17,-8);
    return result;
}



void func_021D9730(GsyncStateObj5 *p, int n)
{
    void *q;
    func_02045CAC(p->f20,n,p->f2C);
    if (!p->f4C) p->f4C=(void *)BMP_WIN_Create(6,1,3,30,16,11,1);
    q=p->f4C;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,p->f2C,p->f28);
    func_0201F73C(q,1,(u16)(p->f4),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(6);
}




void func_021D97B0(GsyncStateObj2 *p)
{
    func_0201F7A8(p->f4C, 2);
    BMP_WIN_ClearScreen(p->f4C);
    func_02041B6C(6);
}



void func_021D97CC(int value, void *p)
{
    Table_021D8A9C table;
    int copy;
    u32 checksum;
    u16 arg;
    u64 v;
    int i;
    table=d_021DA868;
    copy=value;
    checksum=func_0203F1FC((const u8 *)(&copy),4);
    arg=d_021DA864;
    v=(u64)(long long)copy+((u64)checksum<<32);
    STRBUF_Clear(p);
    for (i=0;i<10;i++) {
        u16 index;
        index=(u16)(v&31);
        v>>=5;
        STRBUF_AppendChar(p,table.a[index]);
        func_0201D60C(p,189,4,1,&arg);
    }
}



void func_021D9844(GsyncStateObj2 *p, int n, int a2)
{
    void *q;
    func_021D97CC(n,p->f2C);
    if (!p->f40) p->f40=(void *)BMP_WIN_Create((int)1,(int)1,(u8)8,(int)30,4,11,1);
    q=p->f40;
    BMP_Clear(BMP_WIN_GetBmp(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,p->f2C,p->f28);
    func_0201F73C(q,1,(u16)((*(int *)&p->f0)),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    if (!p->f44) p->f44=(void *)BMP_WIN_Create((int)1,(int)3,(u8)3,(int)22,2,11,1);
    q=p->f44;
    GF_FONT_SetTextColor(1,2,0);
    func_02045CAC(p->f20,10,p->f2C);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),0,0,p->f2C,p->f28);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(5);
}



void func_021D9918(GsyncStateObj2 *p)
{
    if (p->f40) {
        func_0201F7A8(p->f40,2);
        BMP_WIN_ClearScreen(p->f40);
        func_0201F7A8(p->f44,2);
        BMP_WIN_ClearScreen(p->f44);
        BMP_WIN_Delete(p->f40);
        BMP_WIN_Delete(p->f44);
        func_02041B6C(5);
        p->f40=0;
        p->f44=0;
    }
}



/*
 * evidence: ov123 021D9D34 callback stub filed and verified before caller rerun.
 * volatile: hardware register 04001000 is read then written at 021D9990/021D9994.
 */
char *func_021D9958(int heap)
{
    GsyncStateObj12 *p;
    p=(GsyncStateObj12 *) func_02030734(heap,0xb70,1,d_021DABFC,201);
    p->f9E4=heap;
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(p->f9E4);
    CLACT_InitSystem((const struct Cfg *)d_020A1464,(u32)d_021DABCC,p->f9E4);
    p->f97C=CLACT_CreateUnit(40,0,p->f9E4);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DABCC);
    func_0203FC28((struct DispConfig *)d_021DABBC);
    func_021D9AE8(p);
    func_021D9D3C(p);
    p->f980=func_020056A0(func_021D9D34,p,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(27);
    return (char *)p;
}



void func_021D9A14(int a0) { CLACT_DrawSystem(); }



void func_021D9A1C(GsyncStateObj12 *p)
{
    Counter i;
    func_021D9FB0((unsigned int)p);
    if (p->f8) {
        func_02030EAC(p->f8);
        p->f8=0;
        p->fC=0;
    }
    i=0;
    do { if (*(void **)((u8 *)p+i*4+0x988)) CLACT_ReleasePalette((unsigned int)(*(void **)((u8 *)p+i*4+0x988))); i++; } while(i<3);
    for(;i<6;i++) if (*(void **)((u8 *)p+i*4+0x988)) CLACT_ReleaseCharacter((unsigned int)(*(void **)((u8 *)p+i*4+0x988)));
    for(;i<9;i++) if (*(void **)((u8 *)p+i*4+0x988)) CLACT_ReleaseCellAnim((unsigned int)(*(void **)((u8 *)p+i*4+0x988)));
    if (p->f984) func_02030EAC(p->f984);
    func_02030EAC(p->f980);
    CLACT_DeleteUnit(p->f97C);
    CLACT_ExitSystem();
    func_02040DA8(1,1,0);
    func_02040DA8(6,1,0);
    func_020403F4(5);
    func_020403F4(4);
    func_02040588(5,0);
    func_0203F9B4();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}




/*
 * BG-layer init, same shape as func_021D6100 (ov120) with its own template
 * table at 0x021DA8A8 (index order 1,4,3,7,5,0,6,2) and slight per-layer
 * differences in the enable/fill sequence.
 */
void func_021D9AE8(GsyncStateObj12 *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021DA8A8[1];
    func_0203FCA0(0, (const struct BgTemplate_021D4240 *)(&b[7]), 0);
    func_02040588(0, 1);
    func_020409B4(0);

    b[6] = d_021DA8A8[4];
    func_0203FCA0(1, (const struct BgTemplate_021D4240 *)(&b[6]), 0);
    func_02040588(1, 1);
    func_02040C14(1, 0, 1, 0);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(1);

    b[5] = d_021DA8A8[3];
    func_0203FCA0(2, (const struct BgTemplate_021D4240 *)(&b[5]), 0);
    func_02040588(2, 1);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);

    b[4] = d_021DA8A8[7];
    func_0203FCA0(3, (const struct BgTemplate_021D4240 *)(&b[4]), 0);
    func_02040588(3, 1);
    func_02040C14(3, 0, 1, 0);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(3);

    b[3] = d_021DA8A8[5];
    func_0203FCA0(4, (const struct BgTemplate_021D4240 *)(&b[3]), 0);
    func_02040588(4, 1);
    func_020409B4(4);

    b[2] = d_021DA8A8[0];
    func_0203FCA0(5, (const struct BgTemplate_021D4240 *)(&b[2]), 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    b[1] = d_021DA8A8[6];
    func_0203FCA0(6, (const struct BgTemplate_021D4240 *)(&b[1]), 0);
    func_02040588(6, 1);
    func_02040C14(6, 0, 1, 0);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(6);

    b[0] = d_021DA8A8[2];
    func_0203FCA0(7, (const struct BgTemplate_021D4240 *)(&b[0]), 0);
    func_02040588(7, 1);
    func_02040C14(7, 0, 1, 0);
    func_02041300(7, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(7);
}



/*
 * leaf: sole blocker of owned ov123 021D9958; parent ownership audit passed.
 * extent: 8-byte tailcall stub; next labelled function 021D9D3C follows.
 */
void func_021D9D34(void)
{
    CLACT_VBlankSystem();
}



/*
 * note 2026-10-05 (wD9r lane50): closed. func_02049658 returns a value (it ends in a call whose r0 it
 *   keeps; ov110 func_021BB328 declares it u32); declared void, it moved the constant 3 into r5 and
 *   tied the late zero arguments to j. The two palette bases are assigned inside the outer loop (mwcc
 *   hoists them after i = 0), and the source row is written inline in the 02021F64 call.
 */
void func_021D9D3C(GsyncStateObj12 *p)
{
    struct { u8 pad[0xc]; void *data; } *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 heap;
    h = func_020490F4(0x91, p->f9E4);
    j = 0;
    func_02049B68(h, 3, 4, 0, j, p->f9E4);
    func_02049658(h, 4, 4, 0, j, j, p->f9E4);
    func_020498F4(h, 6, 4, 0, j, j, p->f9E4);
    func_02049B68(h, 3, 0, 0, j, p->f9E4);
    func_02049658(h, 4, 0, 0, j, j, p->f9E4);
    func_020498F4(h, 5, 0, 0, j, j, p->f9E4);
    func_02049658(h, 4, 3, 0, j, j, p->f9E4);
    func_020498F4(h, 7, 3, 0, j, j, p->f9E4);
    heap = p->f9E4;
    MI_CpuFill8((char *)p + 8, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    func_02082D44(record->data, (char *)p + 0x10, 0x1e0);
    func_02082D44(record->data, (char *)p + 0x1f0, 0x1e0);
    func_020307B0(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)((char *)p + 0x1f0);
        base0 = (u16 *)((char *)p + 0x10);
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)((char *)p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            for (m = 4; m < 11; m++) {
                PALANM_BlendColors(dst + m, base1 + j * 16 + m, 1, (u8)(k >> 8), cur[m + 8]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    func_020862F0((char *)p + 0x1f0, 0x780);
    *(u32 *)((char *)p + 0xc) = 1;
    *(void **)((char *)p + 8) = func_020056A0((void *)func_021D9F40, (char *)p + 8, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    *(u8 *)((char *)p + 0x974) = 0;
    ARC_TOOL_DeleteHandle(h);
}



void func_021D9F40(void *unused, char *p)
{
    if (((GsyncStateObj13 *)p)->f4) {
        ((GsyncStateObj13 *)p)->f96B^=1;
        if (!(*(volatile u8 *)&((GsyncStateObj13 *)p)->f96B&1)) {
            func_0207E3D0(p+0x1f0+((GsyncStateObj13 *)p)->f968*32,40,14);
            func_0207E468(p+0x1f0+((GsyncStateObj13 *)p)->f968*32,40,14);
            ++((GsyncStateObj13 *)p)->f968;
            if (*(volatile s16_021D8A9C *)&((GsyncStateObj13 *)p)->f968>=60) ((GsyncStateObj13 *)p)->f968=0;
            func_02040618(((GsyncStateObj13 *)p)->f96C,2,7);
        }
    }
}



/*
 * lever: A named unsigned cursor q preserves counter r4 and cursor r5.
 */
void func_021D9FB0(unsigned int p) { int i; unsigned int q; for(i=0;i<13;i++) { q=p+(unsigned)i*4; if(((GsyncStateObj20 *)q)->f9B0) { CLACT_DeleteActor(((GsyncStateObj20 *)q)->f9B0); ((GsyncStateObj20 *)q)->f9B0=0; } } }



/*
 * extent: lead with store-and-return follower 021DA030 and tailcall follower 021DA034.
 */
int func_021D9FD4(GsyncStateObj4 *p, int n)
{
    switch (n) {
    case 503:
        (*(int *)&p->f70)=0xfff1;
        func_021DA034(p,(int)func_021DA1EC,0x99);
        return 1;
    case 502:
        (*(int *)&p->f70)=0xfff2;
        func_021DA034(p,(int)func_021DA1EC,0x9d);
        return 1;
    default:
        if (n>=400) {
            (*(int *)&p->f70)=0xfff3;
            func_021DA034(p,(int)func_021DA1EC,0xa3);
            return 1;
        }
        return 0;
    }
}



void func_021DA030(GsyncStateObj4 *p, int n, int unused)
{
    p->f30=n;
}



void func_021DA034(GsyncStateObj4 *p, int n, int unused)
{
    func_021DA030(p,n,unused);
}




void func_021DA03C(char *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        func_021DA034((GsyncStateObj4 *)p, 0, 0xd5);
}



void func_021DA054(char *p) { WIPE_SYS_Start(0,0,0,0x7fff,6,1,((GsyncStateObj4 *)p)->f0); GFL_USE_FadeOutBgm(6); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA03C,0xe7); }



void func_021DA090(char *p) { if(func_021D95F0((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10)) && KEY_GetTrg()!=0) func_021DA034((GsyncStateObj4 *)p,(int)func_021DA054,0xf1); }



/*
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 */
void func_021DA0B8(char *p) { if((unsigned int)(GAME_DATA_SaveMain(((GsyncStateObj4 *)p)->f20)-2)<=1) { ((GsyncStateObj4 *)p)->f6C=0; func_021D9514((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),11); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA090,0xfe); } }



void func_021DA0E4(char *p) { if(func_021D95F0((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10))) { ((GsyncStateObj4 *)p)->f6C=1; GAME_DATA_SaveStart((*(int *)&((GsyncStateObj4 *)p)->f20)); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA0B8,0x109); } }



void func_021DA110(char *p) { func_021D9514((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),6); func_021D95B4((GsyncStateObj3 *)(((GsyncStateObj4 *)p)->f10)); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA0E4,0x112); }



void func_021DA138(char *p) { if(KEY_GetTrg()) { func_021D97B0((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10)); func_020092E0((struct Sub02009210Obj *)func_02009448(((GsyncStateObj4 *)p)->f1C),1); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA110,0x11a); } }



void func_021DA16C(char *p) { if(KEY_GetTrg()) { func_021D9844((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10),((GsyncStateObj4 *)p)->f28,((GsyncStateObj4 *)p)->f28); func_021D9730((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),9); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA138,0x12a); } }



void func_021DA1A0(char *p) { func_021D9844((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10),((GsyncStateObj4 *)p)->f28,((GsyncStateObj4 *)p)->f28); func_021D9730((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),8); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA16C,0x13c); }



void func_021DA1C8(char *p) { if(KEY_GetTrg() & 3) func_021DA034((GsyncStateObj4 *)p,(int)func_021DA054,0x14b); }



void func_021DA1EC(char *p)
{
    unsigned n;
    n = ((GsyncStateObj4 *)p)->f70 + 11;
    if (((GsyncStateObj4 *)p)->f8) func_021B9774(((GsyncStateObj4 *)p)->f8);
    if (((GsyncStateObj4 *)p)->f70 == 0xfff1) n = 22;
    else if (((GsyncStateObj4 *)p)->f70 == 0xfff2) n = 23;
    else if (((GsyncStateObj4 *)p)->f70 == 0xfff3) n = 20;
    else if (((GsyncStateObj4 *)p)->f70 >= 10) n = 20;
    func_021D9730((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),n);
    func_021DA034((GsyncStateObj4 *)p,(int)func_021DA1C8,0x167);
}



void func_021DA244(char *p) { if(func_021D95F0((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10))) func_021DA034((GsyncStateObj4 *)p,(int)func_021DA3A0,0x172); }



void func_021DA268(char *p) { func_021D9514((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),3); func_021D95B4((GsyncStateObj3 *)(((GsyncStateObj4 *)p)->f10)); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA244,0x17b); }



void func_021DA290(char *p)
{
    if (APP_TASKMENU_IsFinish(((GsyncStateObj4 *)p)->f14)) {
        if (!APP_TASKMENU_GetCursorPos(((GsyncStateObj4 *)p)->f14))
            func_021DA034((GsyncStateObj4 *)p, (int)func_021DA268, 0x18d);
        else
            func_021DA034((GsyncStateObj4 *)p, (int)func_021DA054, 0x190);
        func_021D9634((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10));
        APP_TASKMENU_CloseMenu(((GsyncStateObj4 *)p)->f14);
        *(int *)&((GsyncStateObj4 *)p)->f14 = 0;
    }
}



void func_021DA2DC(char *p) { if(func_021D95F0((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10))) { (*(int *)&((GsyncStateObj4 *)p)->f14)=func_021D9670(((GsyncStateObj4 *)p)->f10,0); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA290,0x1a6); } }



void func_021DA308(char *p) { func_021D9514((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),2); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA2DC,0x1b7); }



void func_021DA328(char *p)
{
    int *q;
    if (GFL_NET_GetRunState() && !func_021D9FD4((GsyncStateObj4 *)p,func_021B99DC(((GsyncStateObj4 *)p)->f8)) && !func_021B9790(((GsyncStateObj4 *)p)->f8)) {
        q = (int *)(char *)func_021B97F4((u8 *)(((GsyncStateObj4 *)p)->f8));
        func_021D9634((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10));
        if (*q == 2) { func_021DA034((GsyncStateObj4 *)p,(int)func_021DA1A0,0x1d4); return; }
        if (*q == 0) { func_021DA034((GsyncStateObj4 *)p,(int)func_021DA1A0,0x1d7); return; }
        (*(int *)&((GsyncStateObj4 *)p)->f70) = *q;
        func_021DA034((GsyncStateObj4 *)p,(int)func_021DA1EC,0x1db);
    }
}



/*
 *   in scratch blocker071d8-r1.log, 12 bytes. the integrator owns filing it.
 *   extern unsigned BACKUP_SYSTEM_GetWork(void *, unsigned *);
 * evidence: 0x021B973C ov114 Thumb leaf now has S23's verified EXACT
 *   pkt_ov114_021B973C shard; no caller retry because ARM9 still blocks it.
 */
void func_021DA3A0(char *p)
{
    int a;
    unsigned b;
    if (GFL_NET_GetRunState()) {
        if (func_021B95D4(9,*(void **)(p + 8))) {
            b = (unsigned int)SAVE_CONTROL_GetWorkArea(*(void **)(p + 0x1c),&a);
            func_021BE79C((void *)func_021B973C(*(void **)(p + 8)),(void *)b,0x80000);
            if (!func_021B9748(*(void **)(p + 8))) {
                func_021DA034((GsyncStateObj4 *)p,(int)func_021DA328,0x1f6);
                return;
            }
        }
    } else if (KEY_GetTrg()) {
        func_021DA034((GsyncStateObj4 *)p,(int)func_021DA328,0x1fc);
    }
}



void func_021DA408(char *p) { if(WIPE_SYS_EndCheck() && KEY_GetTrg()) { func_021D9918((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10)); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA054,0x22c); } }



void func_021DA434(char *p) { func_021D9844((GsyncStateObj2 *)(((GsyncStateObj4 *)p)->f10),((GsyncStateObj4 *)p)->f28,((GsyncStateObj4 *)p)->f28); func_021D9730((GsyncStateObj5 *)(((GsyncStateObj4 *)p)->f10),7); func_021DA034((GsyncStateObj4 *)p,(int)func_021DA408,0x23c); }



void func_021DA45C(char *p) { if(((GsyncStateObj4 *)p)->f8) { func_021B9774(((GsyncStateObj4 *)p)->f8); func_021B9838(((GsyncStateObj4 *)p)->f8); ((GsyncStateObj4 *)p)->f8=0; } }



/*
 * interface: 0203159C retains the allocator result in r0; caller consumes that return.
 */
int func_021DA478(void *a,int unused,GsyncStateObj14 *q)
{
    GsyncStateObj4 *p;
    func_02034AC4((int)ov114_id);
    p=(GsyncStateObj4 *) PROCSYS_AllocProcWork(a,0x74,q->f8);
    MI_CpuFill8(p,0,0x74);
    p->f0=q->f8;
    p->f1C=GAME_DATA_GetSaveControl(q->f0);
    p->f20=q->f0;
    p->f28=func_0200853C((const struct Sub0200852CObj *)func_02012944(q->f0));
    if(GFL_NET_GetRunState()) {
        p->f8=func_021B9800(q->f8,p->f28,q->f4);
        DWC_RAP_SetErrorCallback((int)func_021DA45C,(int)p);
    }
    p->fC=func_021D9958(p->f0);
    p->f10=func_021D92CC(p->f0,87);
    WIPE_SYS_Start(0,1,1,0,6,1,p->f0);
    GFL_USE_CancelChangeAndPlayBgm(0x483,0xffff);
    switch(q->fC) {
    case 0: func_021DA034(p,(int)func_021DA308,0x276); break;
    case 1: func_021DA034(p,(int)func_021DA434,0x279); break;
    }
    q->f10=0;
    return 1;
}



int func_021DA54C(int a,int b,GsyncStateObj35 *c,GsyncStateObj1 *p)
{
    void (*f)(char *);
    int r;
    f = *(void (**)(char *))((char *)p + 0x30);
    r = 1;
    if (f) {
        if (!func_0200FB24()) f((char *)p);
        r = 0;
    }
    if (p->f14) APP_TASKMENU_UpdateMenu(p->f14);
    func_021D9A14((*(int *)&p->fC));
    func_021D9404((GsyncStateObj2 *)(p->f10));
    if (WIPE_SYS_EndCheck()) {
        if (func_0200FB24()) {
            func_021B9774((*(void * *)&p->f8));
            if (p->f6C) {
                GAME_DATA_SaveCancel(p->f20);
                p->f6C = 0;
            }
            WIPE_SetBrightnessFadeOut(0,0);
            WIPE_SetBrightnessFadeOut(1,0);
            r = 1;
            DWC_RAPCOMMON_HandleNetError(1,0);
            c->f10 = 1;
        }
    } else if (func_0200FB24()) r = 1;
    return r;
}
