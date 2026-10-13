/*
 * file:     pokemontrade_proc.c
 * unit:     yes
 * function: func_021D8980, func_021D89A8, func_021D89CC, func_021D89EC, func_021D8A18, func_021D8A24, func_021D8A50, func_021D8AA8, func_021D8ADC, func_021D8AF4, func_021D8B0C, func_021D8B38, func_021D8B54, func_021D8C0C, func_021D8C6C, func_021D8C84, func_021D8CCC, func_021D8D4C, func_021D8DD0, func_021D8E24, func_021D8E80, func_021D8E84, func_021D8E90, func_021D8EAC, func_021D8EC8, func_021D8EEC, func_021D8F20, func_021D8F60, func_021D8FA4, func_021D8FE4, func_021D9038, func_021D90AC, func_021D90C0, func_021D90D4, func_021D90E8, func_021D9124, func_021D913C, func_021D9154, func_021D916C, func_021D9190, func_021D91BC, func_021D91D8, func_021D921C, func_021D9248, func_021D92DC, func_021D92FC, func_021D9328, func_021D935C, func_021D9384, func_021D93AC, func_021D93D4, func_021D93E0, func_021D9404, func_021D9410, func_021D941C, func_021D9434, func_021D9468, func_021D94A0, func_021D94D4, func_021D9548, func_021D95A0, func_021D95D0, func_021D95F0, func_021D9610, func_021D9670, func_021D9750, func_021D9780, func_021D9810, func_021D98AC, func_021D99F4, func_021D9A50, func_021D9AD8, func_021D9B34, func_021D9B84, func_021D9BC4, func_021D9C00, func_021D9CFC, func_021D9D60, func_021D9DC4, func_021D9E0C, func_021D9E54, func_021D9EA8, func_021D9EBC, func_021D9F24, func_021DA064, func_021DA0CC, func_021DA110, func_021DA158, func_021DA1B4, func_021DA1DC, func_021DA254, func_021DA27C, func_021DA2F4, func_021DA318, func_021DA640, func_021DA700, func_021DA76C, func_021DA798, func_021DA898, func_021DA8F8, func_021DA9F0, func_021DAA18, func_021DAA4C, func_021DAA7C, func_021DAAE4, func_021DAB0C, func_021DAB34, func_021DABB0, func_021DABE8, func_021DAC20, func_021DAC60, func_021DACE4, func_021DAD84, func_021DADAC, func_021DAE2C, func_021DAEC8, func_021DAEF0, func_021DAF68, func_021DAFB8, func_021DB030, func_021DB0A0, func_021DB10C, func_021DB164, func_021DB198, func_021DB1BC, func_021DB278, func_021DB290, func_021DB2E8, func_021DB304, func_021DB41C, func_021DB45C, func_021DB4B4, func_021DB4EC, func_021DB52C, func_021DB7AC, func_021DB89C, func_021DB998, func_021DB9B4, func_021DBA38, func_021DBA80, func_021DBAF8, func_021DBB6C, func_021DBBD0, func_021DBC3C, func_021DBC98, func_021DBD3C, func_021DBD70, func_021DBDB4, func_021DBE70, func_021DC2B0, func_021DC370, func_021DC3EC, func_021DC428, func_021DC458, func_021DC484, func_021DC494, func_021DC500, func_021DC538, func_021DC5D0, func_021DC5F0, func_021DC62C, func_021DC720, func_021DC818, func_021DC854, func_021DC894, func_021DCA84, func_021DCAAC, func_021DCAD4, func_021DCB30, func_021DCBA4, func_021DCC38, func_021DCC78, func_021DCCB8, func_021DCCF8, func_021DCD38, func_021DCF24, func_021DD018, func_021DD080, func_021DD09C, func_021DD0CC, func_021DD140, func_021DD174, func_021DD1B8, func_021DD21C, func_021DD24C, func_021DD294, func_021DD2A8, func_021DD2F4, func_021DD34C, func_021DD380, func_021DD3D4, func_021DD428, func_021DD4F4, func_021DD528, func_021DD588, func_021DD5B4, func_021DD68C, func_021DD90C, func_021DD9DC, func_021DDA50, func_021DDAD4, func_021DDB10, func_021DDB64, func_021DDB90, func_021DDBF0, func_021DDCF0, func_021DDD60, func_021DDDB8, func_021DDDF4, func_021DDE4C, func_021DDE90, func_021DDED4, func_021DDF28, func_021DDF74, func_021DE0F0, func_021DE12C, func_021DE1B4, func_021DE208, func_021DE2C4, func_021DE3BC, func_021DE3E8, func_021DE518, func_021DE5C4, func_021DE66C, func_021DE6AC, func_021DE70C, func_021DE754, func_021DE820, func_021DE8C0, func_021DE918, func_021DE950, func_021DE988, func_021DE9E8
 * address:  0x021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   TOUCHBAR_ResetAndEnableButton 0x021B65B4 thumb ov067
 *   func_021B6558 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_02008FEC 0x02008FEC thumb
 *   MAIL_FindEmptySlot 0x02009020 thumb
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_020173EC 0x020173EC thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_0209C0A4 0x0209C0A4 arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_021E66E8  0x021E66E8  thumb  ov119
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E4AB8  0x021E4AB8  thumb  ov119
 *   func_021E64DC  0x021E64DC  thumb  ov119
 *   func_02007A18  0x02007A18  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   func_02082D44  0x02082D44  arm
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_021E6334 0x021E6334 thumb ov119
 *   func_021DF918 0x021DF918 thumb ov119
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02008574  0x02008574  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_0202EB7C  0x0202EB7C  thumb
 *   func_021E62D4 0x021E62D4 thumb ov119
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_021DF8A0 0x021DF8A0 thumb ov119
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021E36A8  0x021E36A8  thumb  ov119
 *   func_021E1B14  0x021E1B14  thumb  ov119
 *   func_021E2438  0x021E2438  thumb  ov119
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F738 0x0202F738 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021E12AC 0x021E12AC thumb ov119
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_021E5B6C 0x021E5B6C thumb ov119
 *   func_021E219C 0x021E219C thumb ov119
 *   d_021E7580 0x021E7580 data a2
 *   d_021E757C 0x021E757C data a2
 *   func_02040588 0x02040588 arm
 *   func_021E1CE8 0x021E1CE8 thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E75F0 0x021E75F0 data a4
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   func_021E1D68 0x021E1D68 thumb ov119
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021E1410 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   d_021E75E4 0x021E75E4 data
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_0207D658 0x0207D658 arm
 *   d_021E7584 0x021E7584 data a4
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021E51A4 0x021E51A4 thumb ov119
 *   func_021DF708 0x021DF708 thumb ov119
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021E2484 0x021E2484 thumb ov119
 *   func_021E1E00 0x021E1E00 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_021DF5D8 0x021DF5D8 thumb ov119
 *   APP_TASKMENU_IsDecide 0x02027A20 thumb
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   APP_TASKMENU_SetCursorActive 0x02027A08 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021E5EF8 0x021E5EF8 thumb ov119
 *   func_021E4174 0x021E4174 thumb ov119
 *   d_021E7594 0x021E7594 data a4
 *   func_021D4B88 0x021D4B88 thumb ov117
 *   func_021D6F2C 0x021D6F2C thumb ov118
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_021DF904 0x021DF904 thumb ov119
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   func_021DF78C 0x021DF78C thumb ov119
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021E31FC 0x021E31FC thumb ov119
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   func_021E3E00 0x021E3E00 thumb ov119
 *   func_021E5098 0x021E5098 thumb ov119
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   func_021E131C 0x021E131C thumb ov119
 *   d_021E758C 0x021E758C data a4
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   func_021E4AA4 0x021E4AA4 thumb ov119
 *   func_021E5D84 0x021E5D84 thumb ov119
 *   func_021E71E0 0x021E71E0 thumb ov119
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021E707C 0x021E707C thumb ov119
 *   d_021E8044 0x021E8044 data a1
 *   func_021E6FD4 0x021E6FD4 thumb ov119
 *   func_021E0EF4 0x021E0EF4 thumb ov119
 *   func_021E5C64 0x021E5C64 thumb ov119
 *   _s32_div_f 0x0209C0A4 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_021E4E0C 0x021E4E0C thumb ov119
 *   d_021E7FE0 0x021E7FE0 data a4
 *   func_021E42B4 0x021E42B4 thumb ov119
 *   func_021E4598 0x021E4598 thumb ov119
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_NET_IsNetTypeWifi 0x0203D29C arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_021E665C 0x021E665C thumb ov119
 *   KEY_GetCont 0x0203630C arm
 *   func_021DF7F0 0x021DF7F0 thumb
 *   func_021E4A1C 0x021E4A1C thumb
 *   func_021E6544 0x021E6544 thumb
 *   func_021E55BC 0x021E55BC thumb ov119
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_021E53F8 0x021E53F8 thumb ov119
 *   func_021E5430 0x021E5430 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_021E4068 0x021E4068 thumb ov119
 *   func_02049B40 0x02049B40 arm
 *   func_021E58A0 0x021E58A0 thumb ov119
 *   func_021E467C 0x021E467C thumb ov119
 *   func_021E3F74 0x021E3F74 thumb ov119
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_02040618 0x02040618 arm
 *   func_02030734 0x02030734 arm
 *   func_0201293C 0x0201293C thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012934 0x02012934 thumb
 *   func_02012950 0x02012950 thumb
 *   d_021E80B0 0x021E80B0 data a4
 *   func_020076A4 0x020076A4 thumb
 *   func_021E64B8 0x021E64B8 thumb ov119
 *   func_021E3230 0x021E3230 thumb ov119
 *   func_021DF8E0 0x021DF8E0 thumb ov119
 *   func_021E4570 0x021E4570 thumb ov119
 *   func_021E69A4 0x021E69A4 thumb ov119
 *   func_021DF7D0 0x021DF7D0 thumb ov119
 *   func_021E2680 0x021E2680 thumb ov119
 *   func_021E4888 0x021E4888 thumb ov119
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   func_021E48E0 0x021E48E0 thumb ov119
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_021E11A8 0x021E11A8 thumb ov119
 *   func_021E293C 0x021E293C thumb ov119
 *   func_021E3F08 0x021E3F08 thumb ov119
 *   func_021E4000 0x021E4000 thumb ov119
 *   func_021E57A4 0x021E57A4 thumb ov119
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_HEAP_RegisterBlockHeap 0x02030678 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   d_021E8560 0x021E8560 data a4
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov117_id 0x00000075 data a1
 *   ov118_id 0x00000076 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_0204363C 0x0204363C arm
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021E7614 0x021E7614 data a4
 *   func_020056A0 0x020056A0 thumb
 *   func_021E30EC 0x021E30EC thumb ov119
 *   func_021E0B34 0x021E0B34 thumb ov119
 *   func_021E10D8 0x021E10D8 thumb ov119
 *   func_021E3FE4 0x021E3FE4 thumb ov119
 *   func_021E3C20 0x021E3C20 thumb ov119
 *   func_021E36C8 0x021E36C8 thumb ov119
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   FADE_Start 0x0204E720 arm
 *   func_021D59B0 0x021D59B0 thumb ov118
 *   func_021D4AB4 0x021D4AB4 thumb ov118
 *   BEACON_STATUS_IsLocked 0x020275DC thumb
 *   func_021DF868 0x021DF868 thumb ov119
 *   CLACT_DrawSystem 0x0204A600 arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021DF978 0x021DF978 thumb ov119
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   func_021E31B4 0x021E31B4 thumb ov119
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200F7C0 0x0200F7C0 thumb
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb ov009
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   BEACON_STATUS_DoNothing 0x020275E0 thumb
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   func_021E31BC 0x021E31BC thumb ov119
 *   func_02030EAC 0x02030EAC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   d_00000072 0x00000072 data a1
 *   d_00000043 0x00000043 data a1
 *   d_00000075 0x00000075 data a1
 *   d_00000076 0x00000076 data a1
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   POKE_REGULATION_IsInSpeciesTable 0x02019D84 thumb
 *   d_021E7718 0x021E7718 data ov119 a4
 *   func_021E2984 0x021E2984 thumb ov119
 *   func_021E2A80 0x021E2A80 thumb ov119
 *   func_021E2A1C 0x021E2A1C thumb ov119
 *   func_02007984 0x02007984 thumb
 *   d_021E80E0 0x021E80E0 data a4
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   func_021DF9E8 0x021DF9E8 thumb ov119
 *   d_021E7704     0x021E7704  data  a4
 *   func_020275E4  0x020275E4  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   d_021E76FC 0x021E76FC data a4
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_021DEBD4  0x021DEBD4  thumb  ov119
 *   d_021E76F4 0x021E76F4 data a4
 *   func_021DEA24 0x021DEA24 thumb ov119
 *   d_021E76E4 0x021E76E4 data a4
 *   func_021E6440 0x021E6440 thumb ov119
 *   func_02049990 0x02049990 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   d_021E770C 0x021E770C data a4
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   d_021E76DC     0x021E76DC  data  a4
 *   GFL_NET_GetRunState  0x0203CD98  arm  arm9
 */
#include "pokemontrade_types.h"
#include "../../matched/include/Obj22698.h"
#include "../../matched/include/Obj22699.h"
#include "../../matched/include/Obj22708.h"
#include "../../matched/include/Obj22709.h"
#include "../../matched/include/Obj22710.h"
#include "../../matched/include/Obj22727.h"
#include "../../matched/include/Obj22732.h"
#include "../../matched/include/Obj04478.h"
#include "../../matched/include/Obj04478.h"
#include "../../matched/include/Obj22735.h"
#include "../../matched/include/Obj01728.h"

#define P(o) (*(void **)(p+(o)))
#define B(o) (*(u8 *)(p+(o)))
struct Sub02008F80Obj;
struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Node;
struct Sub020079BCEntry;
struct Mon;
struct Entry;
struct Link;
struct Big;
struct Sub02009470Obj;
struct Sub0200852CObj;
struct S119DD4F4;
struct MsgBank;
struct S;
struct TaskMenu;
struct WordSet;
struct Bank;
struct Obj0203159C;
struct Blk37;
struct Light;
struct McssSys;
struct Tcbl;
struct PrintSys;
struct S020315D4;
struct Sav;
struct BigObj;
struct State_021DCAD4;
struct Cfg;
struct Descriptor;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef short s16_021D8A18;

typedef signed char s8;

typedef int s32_021D8980;

typedef signed short s16_021D8B54;

typedef signed short s16_021D8C0C;

typedef signed short s16;

typedef struct Pt { u16 x; u16 y; } Pt;

typedef struct {int a,b,c;} Triple_021D9124;

typedef struct { int a,b; } Pair;

typedef short s16_021D9124;

typedef struct { u8 a,b,c,d; } Rect;

typedef unsigned int   u32_021DB52C;

typedef unsigned u32_021DB7AC;

typedef unsigned int   u32_021DB89C;

typedef unsigned int   u32_021DB9B4;

typedef struct Record {u16 value;u8 a,b;} Record;

typedef signed int     s32_021D8EC8;

typedef unsigned u32_021DCD38;

typedef struct Bits {u8 low:4,high:4;} Bits;

typedef unsigned int   u32_021DCF24;

typedef unsigned int   u32_021DD0CC;

typedef unsigned int   u32_021DD174;

typedef unsigned int   u32_021DD1B8;

typedef unsigned int   u32_021DD2A8;

typedef unsigned int   u32_021DD380;

typedef unsigned int u32_021DD428;

typedef struct State_021DCAD4 {
    char pad[0xfa4];
    int a[2][3];
    int b[2][3];
    char gap[4];
    void *value[2][3];
} State_021DCAD4;

typedef unsigned int   u32_021DD4F4;

struct S { char pad[0xFA4]; int a[3][3]; int b[3][3]; int c[3][3]; };

struct S119DD4F4 { char pad[0xFA4]; int a[2][3]; int b[2][3]; int gap; int c[2][3]; };

typedef unsigned int   u32_021DD528;

typedef unsigned int   u32_021DD588;

typedef unsigned int   u32_021DD5B4;

typedef unsigned int u32_021DD68C;

typedef signed short s16_021DBB6C;

typedef struct {
    int a;
    int b;
} Pair_021DD68C;

typedef unsigned int u32_021DD90C;

typedef struct { int a,b; } Pair_021DD90C;

typedef unsigned int   u32_021DD9DC;

typedef unsigned int   u32_021DDA50;

typedef struct { int a,b; } Pair_021DDAD4;

typedef struct { int a,b; } Pair_021DC2B0;

typedef struct { char pad[0xfd8]; void *obj[2][3]; } State_021DDB90;

typedef struct S S;

typedef struct { char pad[0xfd8]; void *obj[2][3]; } State_021DE518;

typedef struct { int a,b,c; } Triple_021DBB6C;

typedef struct { u8 pad[0x11fb]; u8 state:4; u8 other:4; } Flags;

typedef struct { char pad[0xfa4]; int entry[2][3]; char gap[0x1c]; void *mon[2][3]; int value[2][3]; } State;

typedef struct {
    int a;
    int b;
} Pair_021DE3E8;

extern void TOUCHBAR_ResetAndEnableButton(u32 *p, u32 a1);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern int MAIL_FindEmptySlot(void *obj, int v);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern u32 func_020173EC(void);
extern int GFL_NET_GetRunState(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern int func_0209C0A4(int a, int b);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021E66E8(void *p);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void MI_CpuFill8(void *,int,int);
extern void func_021E4AB8(int a0, int a1, int a2);
extern void func_021E64DC(int p, int i, int j, int x, int y, void *q);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern u32 POKEPARTY_GetCount(void *m);
extern void *POKEPARTY_GetMember(void *m, u32 c);
extern void *POKE_TOOL_Create(u16 species, u16 level, unsigned long long id, u16 heap);
extern void func_02082D44(void *dst, const void *src, int n);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern unsigned int func_02017E1C(void *,unsigned int,unsigned int);
extern void func_021E6334(char *p, int i, int j, void *mon, int selected, u32 visible);
extern void func_021DF918(void *,int,void *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern u32 func_0202EB7C(u32 a0, u32 a1);
extern void func_021E62D4(void *, int, int);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void func_021DF8A0(void *, int, int);
extern u32 WIPE_SYS_EndCheck(void);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021E36D8(void *p, int idx);
extern void func_021E36A8(void *p, int a, int b, void *c, int d, int e);
extern void func_021E1B14(char *p, int i, void *mon);
extern void func_021E2438(char *p, int i);
extern u32 POKEPARTY_GetAliveNonEggCount(void *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_0202F738(void *p, int a1);
extern u32 func_0202136C(u16 v);
extern int func_021E12AC(char *p);
extern int GFL_NET_SendToHandle(void *a, u16 b, u16 c, void *d);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern u8 func_020355C4(void);
extern void func_021E5B6C(int p, int b, int c);
extern void func_021E219C(char *p, void *mon, int side, int flag);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021E1CE8(void *,int);
extern void func_021E3E80(char *p);
extern void func_021E3208(void *,int);
extern void func_02041B6C(u32 bit);
extern int TOUCHPANEL_HitTrg(const void *);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void TOUCHBAR_Update(struct S *p);
extern void func_021E1D68(char *p, void *a);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021E1410(void *p, int *ids, int count);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern unsigned int TOUCHPANEL_GetPointTrg(unsigned int *outA, unsigned int *outB);
extern int func_021E51A4(char *p, int x, int y, int *outA, int *outB, int *outSlot, int *outColumn, int *outRow);
extern void func_021DF708(void *p);
extern void func_021E0FF4(void *p, int a, int flag);
extern int TOUCHPANEL_GetTrg(void);
extern void func_021E4E64(int a, char *p, int b);
extern void func_021E2484(char *p, int a);
extern void func_021E1E00(char *p, int mode, void *mon);
extern u32 func_020307B0(void *p);
extern void func_021DF5D8(char *p);
extern unsigned APP_TASKMENU_IsDecide(char *p);
extern int TOUCHPANEL_GetCont(void);
extern void func_021DF7AC(void *,int);
extern void func_021E5EF8(void *);
extern void func_021E4174(char *p);
extern u32 APP_TASKMENU_SetCursorActive(struct TaskMenu *tm, u32 arg);
extern void func_021D4B88(u8 *p);
extern void func_021D6F2C(u8 *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_021DF904(void *);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void func_021DF78C(void *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void func_021E4420(char *p);
extern void func_021E6700(void *);
extern void func_021E31FC(void *);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_021E3E00(char *,int);
extern void func_021E5098(char *,int);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void WIPE_ResetBrightness(u32 which);
extern void func_021E131C(char *p, int *ids, int count, int x, int y);
extern int func_021E4DBC(char *);
extern int func_021E4AA4(int,int);
extern void func_021E5D84(char *p);
extern void func_021E71E0(void *,int);
extern void func_021E7058(void *);
extern int func_021E707C(void *);
extern void func_021E6FD4(char *,int,int);
extern void func_021E0EF4(char *p, int flag, int x, int y, int w, int h);
extern void func_021E5C64(char *p);
extern unsigned int KEY_GetRepeat(void);
extern int func_021E4E0C(char *, int *);
extern void func_021E42B4(char *);
extern void func_021E4598(char *);
extern int GFL_USE_IsAnySeBusy(void);
extern u32_021DB7AC GFL_NET_IsNetTypeWifi(void);
extern int func_021E665C(char *p);
extern unsigned int KEY_GetCont(void);
extern void func_021DF7F0(void *p);
extern void func_021E4A1C(char *p);
extern void func_021E6544(char *p);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *p);
extern void func_021E55BC(char *p);
extern void *MCSS_Init(int, unsigned short);
extern void MCSS_SetTextureTransAdrs(void *, unsigned int);
extern void MCSS_SetOrthoMode(void *);
extern void MCSS_Exit(u8 *a0);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void func_0203F8F4(u16 heapId);
extern void BMP_WIN_Init(unsigned short);
extern void func_021E53F8(char *p);
extern void func_021E5430(void *);
extern void func_021E5680(char *p);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_021E4068(char *p);
extern void func_02049B40(int,int,int,int,int,int);
extern void func_021E58A0(void *);
extern void func_021E467C(void *);
extern void func_021E3F74(void *);
extern void CLACT_VBlankSystem(void);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern unsigned int func_0201293C(const void *);
extern int func_02012944(void *);
extern void *func_02012934(void *p);
extern int func_02012950(void *,int);
extern u8 func_020076A4(void *save);
extern void func_021E64B8(void *);
extern void func_021E3230(void *);
extern void func_021DF8E0(void *);
extern void func_021E4570(char *p);
extern void TOUCHBAR_Delete(u8 *p);
extern void func_021E48E0(char *);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
extern void func_021E11A8(char *);
extern void func_021E293C(char *p, int i);
extern void func_021E3F08(char *);
extern void func_021E4000(char *);
extern void func_021E57A4(int);
extern int GFL_USE_PopBgm(void);
extern void GFL_HEAP_RegisterBlockHeap(void *a, u32 b, u32 c);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern int func_02034AC4(int);
extern void func_0204363C(unsigned int swap);
extern void *func_0200CA1C(void *);
extern u32 func_0200CA38(struct Blk37 *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void GFL_NET_COMMAND_AddCommandTable(unsigned,unsigned,unsigned,unsigned);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
extern void func_021E30EC(char *);
extern void func_021E0B34(char *p);
extern void func_021E10D8(char *p);
extern void func_021E3FE4(char *p);
extern void func_021E3C20(char *p);
extern void func_021E36C8(void *,int,int,void *,int);
extern void MCSS_SetVanishFlag(void *p);
extern void FADE_Start(u32 a, s32_021D8EC8 b, s32_021D8EC8 c, s32_021D8EC8 d);
extern void func_021D59B0(unsigned char *);
extern void func_021D4AB4(unsigned char *);
extern int BEACON_STATUS_IsLocked(void);
extern u32_021DCD38 func_0200FB24(void);
extern void func_021DF868(void *);
extern void CLACT_DrawSystem(void),APP_TASKMENU_UpdateMenu(void *),APP_TASKMENU_WIN_Update(u8 *);
extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *);
extern void GF_FONT_SetTextColor(u32_021DCD38,u32_021DCD38,u32_021DCD38);
extern void TCBL_Main(struct Tcbl *p);
extern u32_021DCD38 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021DF978(void *);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void MCSS_Main(char *);
extern void MCSS_Draw(struct McssSys *sys);
extern void func_021E31B4(void *);
extern void G3D_SYSTEM_DrawEnd(void);
extern void func_0200F7C0(unsigned);
extern void func_021B9774(u8 *);
extern void func_021B9838(u8 *);
extern void DWC_RAP_SetErrorCallback(int,int);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern int DWC_RAPCOMMON_HandleNetError(int a0, int a1);
extern void GFL_NET_ERR_RequestScreen(void);
extern void WIPE_SetBrightnessFadeOut(unsigned,unsigned);
extern void BEACON_STATUS_DoNothing(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32_021DCF24 key);
extern void func_021E31BC(char *);
extern void func_02030EAC(struct Node *n);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_02034A5C(int);
extern void func_021E68F4(int p, int i);
extern u32_021DD0CC func_02017DBC(struct Sav *p);
extern u32_021DD0CC func_02017DE4(struct Sav *p, u32_021DD0CC f);
extern int POKE_REGULATION_IsInSpeciesTable(unsigned short);
extern void *func_021E2984(char *p, int a);
extern int func_021E2A80(void *);
extern void func_021E2A1C(char *p, int a, int b);
extern int func_02007984(void *save);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32_021DD528 a1, u32_021DD528 a2, u32_021DD528 a3, u16 a4);
extern s32_021D8EC8 CLACT_RegisterCellAnim(void *owner, u32_021DD528 first, u32_021DD528 second, u32_021DD528 mode);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleasePalette(u32_021DD588 i);
extern void CLACT_ReleaseCellAnim(u32_021DD588 i);
extern int func_021DF9E8(char *,void *,int);
extern u32_021DD68C func_020275E4(void);
extern u32_021DD68C BMP_WIN_Delete(struct Descriptor *d);
extern u32_021DD68C BMP_WIN_Create(u32_021DD68C layer, u32_021DD68C a, u32_021DD68C b, u32_021DD68C tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *, s16_021DBB6C, s16_021DBB6C, void *, void *);
extern void func_0201F02C(struct WordSet *p, u32_021DD68C i, void *a);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_021DEBD4(void *p);
extern void func_021DEA24(char *p);
extern void func_021E6440(int p, int a, int b);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_021E57E8(int);
int func_021D8980(char *p);
int func_021D89A8(char *p);
void func_021D89CC(char *p);
int func_021D89EC(const u8 *p);
u8 func_021D8A18(u8 *p);
int func_021D8A24(void *p);
void func_021D8A50(void *p);
int func_021D8AA8(void *p);
int func_021D8ADC(char *p);
int func_021D8AF4(int a, char *p);
int func_021D8B0C(int a, int b);
void func_021D8B38(char *p);
void func_021D8B54(void *p);
void func_021D8C0C(void *p);
void func_021D8C6C(void *p);
void func_021D8C84(void *p);
void func_021D8CCC(void *p, int x, int y, int z, int a4);
void *func_021D8D4C(void **a, int b, int c, char *p);
void *func_021D8DD0(void *a, int b, int c, char *p);
char *func_021D8E24(int a, int b, char *p);
void func_021D8E80(void *a0);
void func_021D8E84(void *p, int v);
u32 func_021D8EC8(u32 a, u32 b);
void func_021D8EEC(u32 a, u32 b, u8 *src, u8 *base, void *e);
int func_021D8F20(void *p,int idx);
void func_021D8F60(void *p,int idx,int x);
void *func_021D8FA4(void *p, int idx);
void func_021D8FE4(int idx,int a,int b,void *p,int id);
void func_021D9038(int a,int b,int c,u8 *p,int e,int f);
void func_021D90AC(int a, int b, int c, u8 *d, int e);
void func_021D90C0(int a, int b, int c, u8 *d, int e);
void func_021D90D4(int a, int b, int c, u8 *d, int e);
void func_021D90E8(u32 a, u32 b, u32 c, u8 *base, void *e);
void func_021D9124(u32 a, int b, int c, u8 *d, void *e);
void func_021D913C(u32 a, int b, int c, u8 *d, void *e);
void func_021D9154(u32 a, int b, int c, u8 *d, void *e);
void func_021D916C(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9190(u32 a, u32 b, u32 c, u8 *base, void *e);
void func_021D91BC(u32 a, u32 b, u32 c, u32 d, void *e);
void func_021D91D8(int a,int b,const u8 *c,u8 *p,int e);
void func_021D921C(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9248(void *p, int a1, void *a2, char *a3, int a4);
void func_021D92DC(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D92FC(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9328(u32 a, u32 b, int *src, void *base, void *e);
void func_021D935C(u32 a, u32 b, u32 c, void *base, void *e);
void func_021D9384(u32 a, u32 b, short *src, u8 *base, void *e);
void func_021D93AC(u32 a, u32 b, u8 *src, void *base, void *e);
void func_021D93D4(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021D93E0(u32 a, u32 b, u8 *src, u8 *base, void *e);
void func_021D9404(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021D9410(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_021D941C(void *p);
void func_021D9434(void *p);
void func_021D9468(void *p, int a, void *b);
void func_021D94A0(void *p, int a);
int func_021D94D4(char *p);
int func_021D9548(char *p,int a,int b);
u32 func_021D95A0(void *mon);
int func_021D95D0(void *p);
u32 func_021D95F0(void *p);
int func_021D9610(unsigned char *p);
void func_021D9670(char *p);
void func_021D9750(char *p);
void func_021D9780(char *p, int a1, int a2);
void func_021D9810(char *p);
void func_021D98AC(char *p);
void func_021D99F4(char *p);
void func_021D9A50(char *p);
void func_021D9AD8(char *p);
void func_021D9B34(char *p);
void func_021D9B84(void *p);
void func_021D9BC4(char *p);
void func_021D9C00(char *p);
void func_021D9CFC(u8 *p);
void func_021D9D60(char *p);
void func_021D9DC4(void *p);
void func_021D9E0C(char *p);
void func_021D9E54(char *p);
void func_021D9EA8(char *p,int a,int b);
int func_021D9EBC(char *p,int *a,int *b,int *c,int *d);
int func_021D9F24(char *p,int save);
void func_021DA064(char *p);
void func_021DA0CC(char *p);
void func_021DA110(char *p);
void func_021DA158(char *p);
void func_021DA1B4(char *p);
void func_021DA1DC(char *p);
void func_021DA254(char *p);
void func_021DA27C(char *p);
void func_021DA2F4(void *p);
void func_021DA318(char *p);
void func_021DA640(char *p);
void func_021DA700(char *p);
void func_021DA76C(void *p);
void func_021DA798(char *p);
void func_021DA898(char *p);
void func_021DA8F8(char *p);
void func_021DA9F0(void *p);
void func_021DAA18(char *p);
void func_021DAA4C(void *p);
void func_021DAA7C(char *p);
void func_021DAAE4(char *p);
void func_021DAB0C(char *p);
void func_021DAB34(char *p);
void func_021DABB0(char *p);
void func_021DABE8(char *p);
void func_021DAC20(void *p);
void func_021DAC60(char *p);
void func_021DACE4(char *p);
void func_021DAD84(void *p);
void func_021DADAC(void *p);
void func_021DAE2C(char *p);
void func_021DAEC8(void *p);
void func_021DAEF0(char *p);
void func_021DAF68(void *p);
void func_021DAFB8(char *p);
void func_021DB030(char *p);
int func_021DB0A0(char *p);
void func_021DB10C(char *p);
void func_021DB164(char *p);
void func_021DB198(void *p);
int func_021DB1BC(char *p,int kind);
void func_021DB278(void *p);
void func_021DB290(void *p);
void func_021DB2E8(void *p);
void func_021DB304(char *p);
void func_021DB41C(char *p);
void func_021DB45C(char *p);
int func_021DB4B4(int a);
int func_021DB4EC(char *p, int index);
void func_021DB52C(char *p);
void func_021DB7AC(char *p,int a,int b);
void func_021DB89C(char *p);
void func_021DB998(char *p);
void func_021DB9B4(char *p);
void func_021DBA38(void *p);
void func_021DBA80(char *p);
void func_021DBAF8(char *p);
void func_021DBB6C(char *p);
void func_021DBBD0(char *p);
void func_021DBC3C(char *p);
void func_021DBC98(char *p);
void func_021DBD3C(char *p);
int func_021DBD70(char *p,int a,int b);
int func_021DBDB4(char *p);
void func_021DBE70(char *p);
void func_021DC2B0(char *p);
void func_021DC370(char *p);
void func_021DC3EC(char *p);
void func_021DC428(char *p);
void func_021DC458(char *p);
void func_021DC484(void *a0);
void func_021DC494(char *p);
void func_021DC500(int a, char *p);
void func_021DC538(char *p,void *q,u16 r);
void func_021DC5D0(char *p, int a1);
void func_021DC5F0(char *p);
void func_021DC62C(char *p,int n);
void func_021DC720(char *p);
void func_021DC818(char *p);
void *func_021DC854(void *a,int t);
int func_021DC894(void *a,int b,char *q,char *p,int n);
void func_021DCA84(void *a, int b, int c);
void func_021DCAAC(void *a, int b, int c);
void func_021DCAD4(void *a,int b,char *c);
void func_021DCB30(void *a,int b,char *c);
void func_021DCBA4(char *a, char *p);
int func_021DCC38(void *a, int b, char *c);
int func_021DCC78(void *a, int b, char *c);
int func_021DCCB8(void *a, int b, char *c);
int func_021DCCF8(void *a, int b, char *c);
int func_021DCD38(int a,int b,int c,char *p);
int func_021DCF24(void *owner,int unused,int keep,char *p);
void func_021DD018(char *p, int flag);
void func_021DD080(void *a, void *b, void *c);
void func_021DD09C(char *p);
int func_021DD0CC(char *p, int a);
int func_021DD140(char *p);
void func_021DD174(char *p);
void func_021DD1B8(char *p);
int func_021DD21C(char *p);
int func_021DD24C(char *p);
void func_021DD294(char *p, int a, int b);
int func_021DD2A8(char *p);
int func_021DD2F4(char *p);
int func_021DD34C(char *p, int a, int b);
void func_021DD380(char *p,int i,void *src);
int func_021DD3D4(const char *p, int n, int a, int b);
int func_021DD428(State_021DCAD4 *p,int side,int a,int b,void *value);
void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
void func_021DD528(char *p,int n);
void func_021DD588(char *p);
int func_021DD5B4(char *p,int a,int b);
void func_021DD68C(char *p);
void func_021DD90C(u8 *p,int i,int msg,int force);
void func_021DD9DC(unsigned char *p);
void func_021DDA50(void *p);
void func_021DDAD4(char *p);
void func_021DDB10(unsigned char *p);
void func_021DDB64(unsigned char *p);
void func_021DDB90(unsigned char *p);
void func_021DDBF0(char *p);
void func_021DDCF0(unsigned char *p);
void func_021DDD60(unsigned char *p);
void func_021DDDB8(unsigned char *p);
void func_021DDDF4(unsigned char *p);
void func_021DDE4C(unsigned char *p);
void func_021DDE90(unsigned char *p);
void func_021DDED4(unsigned char *p);
void func_021DDF28(char *p);
void func_021DDF74(char *p);
void func_021DE0F0(void *p);
void func_021DE12C(char *p);
void func_021DE1B4(State_021DDB90 *p,int index);
int func_021DE208(char *p);
void func_021DE2C4(char *p);
void func_021DE3BC(char *p);
void func_021DE3E8(char *p);
void func_021DE518(State_021DE518 *p);
void func_021DE5C4(char *p);
void func_021DE66C(char *p);
void func_021DE6AC(char *p);
void func_021DE70C(void *p);
int func_021DE754(char *p,int idx);
void func_021DE820(char *p);
void func_021DE8C0(char *p);
void func_021DE918(void *p);
void func_021DE950(char *p);
void func_021DE988(char *p);
void func_021DE9E8(void *p);
extern const Pt d_021E7580;
extern const Pt d_021E757C;
extern const char d_021E75F0[];
extern const Triple_021D9124 d_021E75E4;
extern const Pair d_021E7584;
extern const Pair d_021E7594;
extern const Pair d_021E758C;
extern Rect d_021E8044[];
extern const int d_021E7FE0[];
extern char d_021E80B0[];
extern char d_021E8560[];
extern char ov067_id[],ov114_id[],ov117_id[],ov118_id[];
extern char d_021E7614[];
extern char d_00000072[],d_00000043[],d_00000075[],d_00000076[];
extern const int d_021E7718[];
extern const char d_021E80E0[];
extern const Pair_021DD68C d_021E7704;
extern const Pair_021DD90C d_021E76FC;
extern const Pair_021DDAD4 d_021E76F4;
extern const Pair_021DC2B0 d_021E76E4;
extern const char d_021E80C4[];
extern const Triple_021DBB6C d_021E770C;
extern const Pair_021DE3E8 d_021E76DC;




/*
 * 2026-10-02: the first call's target 021B65B4 (thumb, ov067 window) was an
 *  unlabelled tail-call stub; seeded in layout/function_starts.txt and matched
 *  as src/matched/ov/ov067_func_021B65B4.c, so every call now resolves.
 */
int func_021D8980(char *p)
{
    TOUCHBAR_ResetAndEnableButton(*(u32 * *)&((TradeWork *)p)->f9C0, 1);
    func_021B6558((unsigned char *)(*(u32 * *)&((TradeWork *)p)->f9C0), 1, 1);
    return TOUCHBAR_SetButtonEnabled((unsigned char *)(*(u32 * *)&((TradeWork *)p)->f9C0), 1, 1);
}





int func_021D89A8(char *p)
{
    void *o = func_02008FEC(((TradeWork *)p)->f82C);
    int r = 0;
    if (MAIL_FindEmptySlot(o, 0) == -1)
        r = 1;
    return r;
}





void func_021D89CC(char *p)
{
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    GFL_NET_STATE_WifiDisconnect(0);
    ((struct Obj22699 *)(*(char * *)&((struct Obj22698 *)p)->f8))->f8 = 3;
}





int func_021D89EC(const u8 *p)
{
    int n;
    int i;

    n = func_020173EC();
    if (p == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (p[i] != 0) {
            return 1;
        }
    }
    return 0;
}





u8 func_021D8A18(u8 *p) { return ((TradeWork *)p)->f11F2; }





/*
 * True when the object has a session and its state index is in range.
 */
int func_021D8A24(void *p)
{
    int v;

    if (*(int *)&((TradeWork *)p)->f8 == 0)
        return 0;
    v = ((TradeWork *)p)->f118C;
    if (v >= 4)
        return 0;
    return GFL_NET_GetRunState() != 0;
}




void func_021D8A50(void *p) {
 int v;
 if(((TradeWork *)p)->f1094!=0) {
 v=++((TradeWork *)p)->f1094;
 if(v==2) {GFL_USE_FadeOutBgm(6); return;}
 if(v==8) {
 GFL_USE_SetBgmPlayerParam((void *)1); GFL_USE_PushBgm();
 ++((TradeWork *)p)->f11F8;
 GFL_USE_CancelChangeAndPlayBgm(0x3f3,0xffff); GFL_USE_FadeInBgmFull(1);
 ((TradeWork *)p)->f1094=0;
 }
 }
}





int func_021D8AA8(void *p)
{
    unsigned int x = (*(unsigned int *)&((TradeWork *)p)->f118C);
    int r = 0;

    switch (x) {
    case 0:
    case 4:
    case 6:
    case 7:
    case 8:
        break;
    default:
        r = 1;
    }
    return r;
}




int func_021D8ADC(char *p)
{
    int r = 0;
    int v = ((TradeWork *)p)->f118C;
    if (v == 3 || v == 9)
        r = 1;
    return r;
}




int func_021D8AF4(int a, char *p)
{
    if (a >= 2)
        return func_0209C0A4(a - 2, 6);
    return ((TradeWork *)p)->f630;
}




int func_021D8B0C(int a, int b)
{
    if (a >= 2) {
        return (a - 2) % 6 + b * 6;
    }
    if (b < 3)
        return a + b * 2;
    return -1;
}




void func_021D8B38(char *p)
{
    ((TradeWork *)p)->f1080 += 1;
    ((TradeWork *)p)->f1084 = 1;
    func_021DB7AC(p, 0, 0);
}





void func_021D8B54(void *p)
{
    int o1, o2;
    int d;

    if (TOUCHPANEL_GetPointCont((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    if (((TradeWork *)p)->fF60 == 0)
        ((TradeWork *)p)->fF5C = 0;
    if (((TradeWork *)p)->fF60 != 0) {
        d = ((s16_021D8B54)((TradeWork *)p)->fF64 - (s16_021D8B54)((TradeWork *)p)->fF68) - o1;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((TradeWork *)p)->fF5C = 1;
        d = ((s16_021D8B54)((TradeWork *)p)->fF66 - (s16_021D8B54)((TradeWork *)p)->fF6A) - o2;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((TradeWork *)p)->fF5C = 1;
        d = (s16_021D8B54)((TradeWork *)p)->fF64 - o1;
        if (d < 0)
            d = -d;
        if (d > 6) {
            d = (s16_021D8B54)((TradeWork *)p)->fF66 - o2;
            if (d < 0)
                d = -d;
            if (d > 6)
                ((TradeWork *)p)->fF70 = 0;
        }
    }
    if ((unsigned int)o2 >= 0x10 && (unsigned int)o2 < 0x90) {
        ((TradeWork *)p)->fF54 = o1;
        ((TradeWork *)p)->fF58 = o2;
    }
}




void func_021D8C0C(void *p) {
 int x,y; s16_021D8C0C pos[2];
 if(((TradeWork *)p)->fF60!=0) {
 if(TOUCHPANEL_GetPointCont((unsigned int *)(&x),(unsigned int *)(&y))!=0) {
 CLACT_GetActorSurfacePos((struct Actor *)((TradeWork *)p)->fF60,(struct PtS *)((char *)p+0xf6c),1);
 pos[0]=x+((TradeWork *)p)->fF68;
 pos[1]=y+((TradeWork *)p)->fF6A;
 if(pos[1]>150) pos[1]=150;
 CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF60),(const struct Vec2 *)pos,1);
 }
 }
}





/*
 * Clear the pending pointer and hand the object to the updater.
 */
void func_021D8C6C(void *p)
{
    if (((TradeWork *)p)->fF60 != 0)
        ((TradeWork *)p)->fF60 = 0;
    func_021E66E8(p);
}




void func_021D8C84(void *p) {
 if(((TradeWork *)p)->fF60!=0) {
 CLACT_SetActorDrawPriority((struct Node *)(((TradeWork *)p)->fF60),16);
 CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF60),(const struct Vec2 *)((char *)p+0xf64),1);
 CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF60,1);
 ((TradeWork *)p)->fF7C=-1;
 ((TradeWork *)p)->fF80=-1;
 func_021D8C6C(p); MI_CpuFill8((char *)p+4,0,2);
 }
}





void func_021D8CCC(void *p, int x, int y, int z, int a4)
{
    int o1, o2;

    ((TradeWork *)p)->fF60 = x;
    CLACT_GetActorSurfacePos((struct Actor *)x, (struct PtS *)((char *)p + 0xf64), 1);
    func_021E4AB8((int)p, ((TradeWork *)p)->fF60, 1);
    if (TOUCHPANEL_GetPointCont((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    ((TradeWork *)p)->fF68 = (s16)((TradeWork *)p)->fF64 - o1;
    ((TradeWork *)p)->fF6A = (s16)((TradeWork *)p)->fF66 - o2;
    func_021E64DC((int)p, y, z,
                  o1 + (s16)((TradeWork *)p)->fF68,
                  o2 + (s16)((TradeWork *)p)->fF6A,
                  (void *)a4);
    ((TradeWork *)p)->fF60 = ((TradeWork *)p)->fF20;
}





void *func_021D8D4C(void **a, int b, int c, char *p)
{
    int n;
    void *res = 0;

    if (b == -1)
        goto out;
    n = ((TradeWork *)p)->f630;
    if (b > n)
        return 0;
    if (b != n && c != -1) {
        res = POKE_TOOL_CreateFromBoxParam((struct Mon *)func_02007A18(a, b, c), ((TradeWork *)p)->f5F4);
    } else {
        void *m = ((TradeWork *)p)->f838;
        if (c >= (int)POKEPARTY_GetCount(m))
            goto out;
        if (c == -1)
            goto out;
        {
            void *mon = POKE_TOOL_Create(1, 1, 1, ((TradeWork *)p)->f5F4);
            int sz = func_020173EC();
            func_02082D44(POKEPARTY_GetMember(m, c), mon, sz);
            res = mon;
        }
    }
out:
    return res;
}





void *func_021D8DD0(void *a, int b, int c, char *p)
{
    void *m;
    int n;

    if (b != -1) {
        n = ((TradeWork *)p)->f630;
        if (b > n)
            return 0;
        if (b != n && c != -1)
            return func_02007A18(a, b, c);
        m = ((TradeWork *)p)->f838;
        if (c < (int)POKEPARTY_GetCount(m) && c != -1)
            return POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(m, c));
    }
    return 0;
}





char *func_021D8E24(int a, int b, char *p)
{
    int n;

    if (a != -1) {
        n = ((TradeWork *)p)->f630;
        if (a > n)
            return 0;
        if (a != n && b != -1)
            return p + 0x11fc + (a * 0x1e + 6 + b) * 4;
        if (b >= 0 && b < 6)
            return p + 0x11fc + b * 4;
        return 0;
    }
    return 0;
}




/*
 * Empty stub.
 */
void func_021D8E80(void *a0)
{
}



void func_021D8E84(void *p, int v)
{
    ((TradeWork *)p)->f5EC = v;
}

/*
 * Hidden leaf (no caller seen): slot lookup by index, 0 when out of range.
 */
int func_021D8E90(int i, char *p)
{
    if (i >= 0 && i < 2)
        return *(int *)(p + i * 4 + 0x1064);
    return 0;
}

/*
 * Hidden leaf (no caller seen): same lookup as func_021D8E90.
 */
int func_021D8EAC(int i, char *p)
{
    if (i >= 0 && i < 2)
        return *(int *)(p + i * 4 + 0x1064);
    return 0;
}





u32 func_021D8EC8(u32 a, u32 b)
{
    if (a == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
        return b + 0x10;
    return b + 0x2e6;
}





void func_021D8EEC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        u32 idx = (a == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) ? 0 : 1;
        *(base + idx + 0x11e8) = *src;
    }
}





int func_021D8F20(void *p,int idx) {
 unsigned v=func_021D8A24(p);
 if(v==0) return *(int *)((char *)p+idx*4+0x5e4);
 if(GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()))==0) return *(int *)((char *)p+idx*4+0x5e4);
 return *(int *)((char *)p+(1-idx)*4+0x5e4);
}





void func_021D8F60(void *p,int idx,int x) {
 unsigned v=func_021D8A24(p);
 if(v==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 if(GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()))==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 *(int *)((char *)p+(1-idx)*4+0x5e4)=x;
}






/*
 * Addresses are Black-image addresses.
 */
void *func_021D8FA4(void *p, int idx)
{
    u32 v = func_021D8A24(p);
    if (v == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    if (GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    return *(void **)((char *)p + (1 - idx) * 4 + 0x5DC);
}





void func_021D8FE4(int idx,int a,int b,void *p,int id) {
 if(id==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
 int n=func_020173EC();
 func_02082D44(*(void **)((char *)p+idx*4+0x1064),*(void **)((char *)p+idx*4+0x5dc),n);
 if(idx!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
 ((TradeWork *)p)->fF9C=idx+1;
 ((TradeWork *)p)->f11FB=(((TradeWork *)p)->f11FB&~0xf0)|0x10;
 }
 }
}



void func_021D9038(int a,int b,int c,u8 *p,int e,int f) { int z;if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {z=0;if(func_02017E1C((void *)*(int *)(p+0x1064+a*4),169,0)) {func_021DD380((char *)p,f,(void *)(*(int *)(p+0x1064+a*4)));func_021E6334((char *)p,1,f,(void *)(*(int *)(p+0x1064+a*4)),1,z);func_021DF918(p,1,*(void **)(p+0x1064+a*4));}p[0x11fb]=(p[0x11fb]&~240)|16;} } }






/*
 * DWCi_EncSessionGetAsync: sixth argument is zero.
 */
void func_021D90AC(int a, int b, int c, u8 *d, int e)
{
    func_021D9038(a, b, c, d, e, 0);
}






void func_021D90C0(int a, int b, int c, u8 *d, int e)
{
    func_021D9038(a, b, c, d, e, 1);
}






/*
 * Third entry point of the encoder session getter.
 */
void func_021D90D4(int a, int b, int c, u8 *d, int e)
{
    func_021D9038(a, b, c, d, e, 2);
}





void func_021D90E8(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (c == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            *(u32 *)(base + b * 4 + 0xff0) = a;
        else
            *(u32 *)(base + b * 4 + 0xffc) = a;
    }
}





#define I(o) (*(int *)(p+(o)))




#define H(o) (*(s16_021D9124 *)(p+(o)))












/*
 * Encoder session getter on the byte pointed at by the third argument.
 */
void func_021D9124(u32 a, int b, int c, u8 *d, void *e)
{
    func_021D90E8(((struct Obj22708 *)c)->f0, 0, a, d, e);
}












void func_021D913C(u32 a, int b, int c, u8 *d, void *e)
{
    func_021D90E8(((struct Obj22709 *)c)->f0, 1, a, d, e);
}












void func_021D9154(u32 a, int b, int c, u8 *d, void *e)
{
    func_021D90E8(((struct Obj22710 *)c)->f0, 2, a, d, e);
}











void func_021D916C(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        *(u32 *)(base + a * 4 + 0x5e4) = *src;
}











void func_021D9190(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            base[0x11fb] = base[0x11fb] & ~0xf;
    }
}











void func_021D91BC(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            return;
    }
}











void func_021D91D8(int a,int b,const u8 *c,u8 *p,int e) {
 if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
  if(a!=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {
   p[0x11f2]=c[0]; p[0x11f4]=c[1];
   (*(unsigned short *)&((TradeWork *)p)->f107E)=p[0x11f2]*160+16;
  }
 }
}











void func_021D921C(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            base[0x11e7] = *src;
    }
}












void func_021D9248(void *p, int a1, void *a2, char *a3, int a4)
{
    u8 buf[0x28];
    u8 x, y;
    u32 r1, r2;
    void *saved;

    if (a4 != (int)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (p == (void *)GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    saved = func_02009470(GAME_DATA_GetSaveControl(((TradeWork *)a3)->f82C));
    func_02082D44(a2, buf, 0x28);
    x = func_0200856C((const struct Sub0200852CObj *)buf);
    y = func_02008570((const struct Sub0200852CObj *)buf);
    r1 = func_02025C1C(x, y, func_02008564((const struct Sub0200852CObj *)buf));
    r2 = func_02025C30(x, y, func_02008564((const struct Sub0200852CObj *)buf));
    if (x == r1 && y == r2)
        func_02008574((struct Sub0200852CObj *)buf, x, y);
    else
        func_02008574((struct Sub0200852CObj *)buf, 0, 0);
    func_0202EB7C((u32)saved, (u32)buf);
}










void func_021D92DC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        (base + a)[0x11e0] = *src;
}










void func_021D92FC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            (*(unsigned int *)&((TradeWork *)base)->f1060) = *src;
    }
}










void func_021D9328(u32 a, u32 b, int *src, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
            func_021DD4F4(base, 1, *src);
            func_021E62D4(base, 1, *src);
        }
    }
}










void func_021D935C(u32 a, u32 b, u32 c, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            func_021D94A0(base, 1);
    }
}










void func_021D9384(u32 a, u32 b, short *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            ((TradeWork *)base)->f107E = *src;
    }
}










void func_021D93AC(u32 a, u32 b, u8 *src, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            func_021DF8A0(base, *src, 1);
    }
}











void func_021D93D4(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}










void func_021D93E0(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            (*(unsigned int *)&((TradeWork *)base)->fFA0) = *src;
    }
}











void func_021D9404(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}











/*
 * Byte-identical twin of func_021D93D4 (same 12-byte predicate stub).
 */
void func_021D9410(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}










void func_021D941C(void *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        func_021D8E84(p, 0);
}











/*
 * Start a 7-argument timer/slot request (0,0,0,0,6,1,*(u16*)(p+0x5f4)) then
 * hand func_021D8E84 the func_021D941C callback. Non-SDK dep of
 * func_021DFDA0's case-5 arm.
 *
 * Addresses are Black-image addresses.
 */
void func_021D9434(void *p)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((TradeWork *)p)->f5F4);
    func_021D8E84(p, (int)func_021D941C);
}











/*
 * Start a transfer on the object when the length is non-zero.
 */
void func_021D9468(void *p, int a, void *b)
{
    int t;

    if (b == 0)
        return;
    func_021E36D8(p, a);
    t = func_021D8AA8(p);
    func_021E36A8(p, a, 1 - a, b, 1, t);
    func_021E1B14(p, a, b);
}











/*
 * Arm or re-arm the three receivers depending on the object state.
 */
void func_021D94A0(void *p, int a)
{
    int i;

    if (func_021D8AA8(p) == 0) {
        func_021E36D8(p, a);
        func_021E2438(p, a);
        return;
    }
    for (i = 0; i < 3; i++)
        func_021E62D4(p, a, i);
}










int func_021D94D4(char *p) { int w; void *v; int z; if(func_021D8AA8(p)==0) {v=func_021D8FA4(p,0);w=func_021D8F20(p,0);} else {v=func_021D8FA4(p,1);w=func_021D8F20(p,1);} z=0;if(func_02017E1C(v,160,0)==0)return z;if(func_02017E1C(v,76,0))return z;if(POKEPARTY_GetAliveNonEggCount((void *)((*(int *)&((TradeWork *)p)->f838)))==1 && w!=0)return 1;return 0; }









int func_021D9548(char *p,int a,int b) { int v=(int)func_021D8DD0((void *)(((TradeWork *)p)->f828),a,b,p); int r; if(((TradeWork *)p)->f118C) return 0; if(a!=((TradeWork *)p)->f630) return 0; r=0; if(func_02017E88((void *)v,76,0)) return r; if(func_0202F738((void *)v,r)==0) r=1; return r; }









u32 func_021D95A0(void *mon)
{
    u32 r = 0;
    if (func_02017E1C(mon, 3, 0) == 1)
        return 1;
    if ((int)func_02017E1C(mon, 5, r) > 0x28b)
        r = 1;
    return r;
}










/*
 * Select the alternate buffer when the object is idle.
 */
int func_021D95D0(void *p)
{
    int b = 0;

    if (func_021D8AA8(p))
        b = 1;
    return func_021D95A0(func_021D8FA4(p, b));
}









u32 func_021D95F0(void *p)
{
    int r = 1;
    if (func_021D8AA8(p) != 0)
        r = 0;
    return func_021D95A0(func_021D8FA4(p, r));
}









int func_021D9610(unsigned char *p) { void *v; int w; if(func_021D8AA8(p)==0) {v=func_021D8FA4(p,0); w=func_021D8F20(p,1);} else {v=func_021D8FA4(p,1); w=func_021D8F20(p,0);} if(func_0202136C(func_02017E1C(v,6,0)) && p[0x11f4]!=0 && w==0) return 1; return 0; }










void func_021D9670(char *p)
{
    u8 b[5];
    int r;
    int kind = func_021D8A24(p);

    if (func_021E12AC(p) == 0)
        return;
    if (kind != 0) {
        if (func_021D94D4(p)) {
            b[4] = 5;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[4]);
        } else if (func_021D95D0(p)) {
            b[3] = 7;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[3]);
        } else if (func_021D95F0(p)) {
            b[2] = 8;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[2]);
        } else if (func_021D9610((unsigned char *)p)) {
            b[1] = 6;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[1]);
        } else {
            b[0] = 2;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[0]);
        }
        if (r == 0)
            return;
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
        func_021D8E84(p, (int)func_021DA798);
        return;
    }
    p[0x11e0] = 2;
    p[0x11e1] = 2;
    func_021D8E84(p, (int)func_021DA798);
}









void func_021D9750(char *p)
{
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), 6, (void *)(((TradeWork *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, (int)func_021D9670);
}









/*
 * 2026-10-02: the 0204B404 call is written in each branch of the a1 test (tail-merged
 *  by the compiler, so the 0xf0c pool constant is not hoisted across blocks);
 *  020355C4 is a void getter called on its own; the 021D8FA4 result is a local.
 */
void func_021D9780(char *p, int a1, int a2)
{
    Pt t0, t1;
    if (a1 == 0) {
        t0 = d_021E7580;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF0C), (const struct Vec2 *)(&t0), 1);
    } else {
        t1 = d_021E757C;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF0C), (const struct Vec2 *)(&t1), 1);
    }
    if (func_020355C4()) {
        func_021E5B6C((int)p, a1, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF0C, 0);
    } else {
        func_021E5B6C((int)p, a1, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF0C, 1);
    }
    if (a2 != 0) {
        void *v;

        v = func_021D8FA4(p, ((TradeWork *)p)->f10A0);
        func_021E219C(p, v, ((TradeWork *)p)->f10A0, 1);
    }
}









void func_021D9810(char *p) { int z,one; if(WIPE_SYS_EndCheck()) {z=0;func_02040588(3,0);one=1;func_021E1CE8(p,1);func_02040588(4,0);func_021E3E80(p);func_021E3208(p,0);func_02041B6C(3);*(u16 *)0x04000050=z;func_021D9468(p,0,func_021D8FA4(p,0));func_021D9468(p,1,func_021D8FA4(p,1));func_021D8B38(p);WIPE_SYS_Start((void *)3,1,1,0,6,one,((TradeWork *)p)->f5F4);func_021D8E84(p,(int)func_021D9AD8); } }









static inline int poll(void) {int v=KEY_GetTrg();if(v)func_020355D8(0);return v;}









/*
 * prototype: 02035C08 is declared int here: original consumes r0 after
 * its 02035BBC forwarding call; the matched void spelling leaves r0 live.
 * Full matched ARM9 02035BBC returns int through 02035ADC, or -1.
 * wrap: the 10a0 toggle uses full-width unsigned subtraction to preserve
 * the original SUB for every 32-bit field pattern without a domain claim.
 */
void func_021D98AC(char *p)
{
 int done=0;
 if(((TradeWork *)p)->f11F9==0 && WIPE_SYS_EndCheck()) {
  if(func_020355C4() && poll()) {func_020355D8(0);func_021D9780(p,((TradeWork *)p)->f10A0,0);return;}
  func_02040588(3,1);
  switch(TOUCHPANEL_HitTrg(d_021E75F0)) {
  case 0:
   if(((TradeWork *)p)->f10A0!=0 || !func_020355C4()) {
    ((TradeWork *)p)->f10A0=0;func_020355D8(1);GFL_USE_PlaySeDefaultVolume(0x548);func_021D9780(p,((TradeWork *)p)->f10A0,1);
   }
   break;
  case 1:
   if(((TradeWork *)p)->f10A0!=1 || !func_020355C4()) {
    ((TradeWork *)p)->f10A0=1;func_020355D8(1);GFL_USE_PlaySeDefaultVolume(0x548);func_021D9780(p,((TradeWork *)p)->f10A0,1);
   }
   break;
  case 2:done=1;break;
  }
  if(poll()==32 || poll()==16) {
   *(unsigned *)&((TradeWork *)p)->f10A0=1u-*(unsigned *)&((TradeWork *)p)->f10A0;GFL_USE_PlaySeDefaultVolume(0x548);func_020355D8(0);func_021D9780(p,((TradeWork *)p)->f10A0,1);
  }
  TOUCHBAR_Update((*(void * *)&((TradeWork *)p)->f9C0));
  if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->f9C0)==1)done=1;
  if(done) {WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->f5F4);func_021D8E84(p,(int)func_021D9810);}
 }
}









void func_021D99F4(char *p) { if(WIPE_SYS_EndCheck()) { ((TradeWork *)p)->f10A0=0; func_021E1D68(p,func_021D8FA4(p,0));func_021D8B38(p);WIPE_SYS_Start((void *)3,1,1,0,6,1,((TradeWork *)p)->f5F4);func_021D8E84(p,(int)func_021D98AC); } }









void func_021D9A50(char *p) { int v; if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))) {v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));func_021E12F8(p);func_021E1098(p);((TradeWork *)p)->f64C=0;switch(v) {case 0:func_021D8E84(p,(int)func_021D9750);return;case 1:WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->f5F4);func_021D8E84(p,(int)func_021D99F4);return;case 2:func_021D8E84(p,(int)func_021DADAC);return;} } }









void func_021D9AD8(char *p) { int i; func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),17,(void *)((*(int *)&((TradeWork *)p)->f73C)));for(i=0;i<2;i++) func_0201EEF4((*(void * *)&((TradeWork *)p)->f724),i,func_021D8FA4(p,i));func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f738),(void *)((*(int *)&((TradeWork *)p)->f73C)));func_021E1024(p);func_021D8E84(p,(int)func_021D9B34); }









void func_021D9B34(char *p) { if(func_021E12AC(p)) { Triple_021D9124 t=d_021E75E4; func_021E1410(p,(int *)(&t),3); BG_SYS_SetMainVisiblePlanes(31); func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,0); func_021D8E84(p,(int)func_021D9A50); } }









void func_021D9B84(void *p) {
 if(func_021D8A24(p)) {
  if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),20,8)) {
   func_021E1098(p); func_021D8E84(p,(int)func_021D9434);
  }
 } else { func_021E1098(p); func_021D8E84(p,(int)func_021D9434); }
}









void func_021D9BC4(char *p) {
 if(func_021E12AC(p) && ((TradeWork *)p)->fF2C>30) {
  if(func_021D8A24(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),20,8);
  func_021D8E84(p,(int)func_021D9B84);
 }
}










void func_021D9C00(char *p)
{
    int cmd;
    u32 other;
    u32 me;
    u32 a;

    me = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    other = 1 - me;
    if (func_021D8A24(p) == 0) {
        me = 0;
        other = 1;
    }
    if (func_021D8A24(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1a, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    func_021DD294(p, 1, 1);
    a = ((u8 *)p + me)[0x11e0];
    if (a == 1 && ((u8 *)p + other)[0x11e0] == 1) {
        func_021D8E84(p, (int)func_021D9AD8);
        return;
    }
    if (a == 4 && ((u8 *)p + other)[0x11e0] == 4) {
        ((struct Obj22727 *)(((TradeWork *)p)->f8))->f8 = 3;
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), 0x8d, (void *)(((TradeWork *)p)->f738));
        func_021E1024(p);
        func_021E1030(p);
        ((TradeWork *)p)->fF2C = 0;
        func_021D8E84(p, (int)func_021D9BC4);
        return;
    }
    if (((u8 *)p + other)[0x11e0] == 4)
        cmd = 0x61;
    else if (a == 4)
        cmd = 0x66;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), cmd, (void *)(((TradeWork *)p)->f738));
    func_021E1024(p);
    p[0x11e0] = 0;
    p[0x11e1] = 0;
    func_021D8E84(p, (int)func_021DAEF0);
}









void func_021D9CFC(u8 *p) { int kind=func_021D8A24(p); u8 b; if(func_021E12AC((char *)p)) { if(kind==0) {p[0x11e0]=1;p[0x11e1]=1;func_021D8E84(p,(int)func_021D9C00);return;} b=1; if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&b)==0) return; GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);func_021D8E84(p,(int)func_021D9C00); } }









void func_021D9D60(char *p) {
    int v;
    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))) {
        v=APP_TASKMENU_GetCursorPos((const unsigned char *)(((TradeWork *)p)->f64C));
        func_021E12F8(p);
        ((TradeWork *)p)->f64C=0;
        if (v==0) {
            func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),6,(void *)(((TradeWork *)p)->f738));
            func_021E1024(p);
            func_021E1030(p);
            func_021D8E84(p,(int)func_021D9CFC);
            return;
        }
        func_021D8E84(p,(int)func_021DBA80);
    }
}









void func_021D9DC4(void *p)
{
    if (func_021DB0A0(p)) {
        Pair t = d_021E7584;
        func_021E1410(p,(int *)(&t),2);
        func_0207D658(0x04001050,0x1B,-8);
        func_021D8E84(p,(int)func_021D9D60);
    }
}









void func_021D9E0C(char *p)
{
    int v = 0;
    if (((TradeWork *)p)->fF88 == ((TradeWork *)p)->f630) v=1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xC16,1,&v))
        func_021D8E84(p,(int)func_021D9DC4);
}









void func_021D9E54(char *p) {
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),7,0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),8,0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),9,0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04,0);
    func_021D8C6C(p);
    func_021D8E84(p,(int)func_021D9E0C);
}









void func_021D9EA8(char *p,int a,int b) {
 ((TradeWork *)p)->fF74=a;
 ((TradeWork *)p)->fF78=b;
 func_021D8B38(p);
}









int func_021D9EBC(char *p,int *a,int *b,int *c,int *d) {
    int x,y,z,n;
    if(TOUCHPANEL_GetPointTrg((unsigned int *)(&x),(unsigned int *)(&y))==1) {
        if(func_021E51A4(p,x+12,y+12,a,b,c,d,&z)) {
            n=(int)func_021D8DD0((void *)(((TradeWork *)p)->f828),*a,*b,p);
            if(n && func_02017E88((void *)n,0xA9,0)) return 1;
        }
    }
    return 0;
}









int func_021D9F24(char *p,int save)
{
 int x,y,a,b,c,hit,e,result=0;
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))==1) {
  hit=func_021E51A4(p,x+12,y+12,(int *)(p+0xf80),(int *)(p+0xf7c),&a,&b,&c);
  if(hit) {
   e=(int)func_021D8DD0((void *)I(0x828),I(0xf80),I(0xf7c),p);
   if(func_021DBD70(p,I(0xf80),I(0xf7c))) {
    GFL_USE_PlaySeDefaultVolume(0x626);
    if(!func_021D8AA8(p)) {func_021D8E84(p,(int)func_021DB9B4);return 3;}
    I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);func_021D8E84(p,(int)func_021DF708);return 3;
   }
   func_021D8C84(p);
   if(e && func_02017E88((void *)e,0xa9,0)) {
    if(func_021DD0CC(p,e)) {
     func_02045CAC((struct MsgBank *)I(0x720),0x8e,(void *)I(0x738));func_021E0FF4(p,1,0);func_021D8E84(p,(int)func_021DA064);return 2;
    }
    func_021D8CCC(p,hit,c,b,e);func_021D9EA8(p,a,b);
    if(save) {I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);}
    func_021D8B38(p);result=1;
   }
  }
 }
 return result;
}









void func_021DA064(char *p) {
    int v;
    if (func_021E12AC(p)) {
        v=KEY_GetTrg();
        if(v) func_020355D8(0);
        if(!v) {
            v=TOUCHPANEL_GetTrg();
            if(v) func_020355D8(1);
            if(!v) return;
        }
        ((TradeWork *)p)->fF80=-1;
        ((TradeWork *)p)->fF7C=-1;
        func_021E1098(p);
        func_021D8E84(p,(int)func_021DBE70);
        ((TradeWork *)p)->f1080=-1;
        func_021E4E64(((TradeWork *)p)->f828,p,1);
    }
}









void func_021DA0CC(char *p)
{
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), 0x65, (void *)(((TradeWork *)p)->f738));
    func_021E1024(p);
    ((TradeWork *)p)->f1080 = -1;
    func_021E4E64(((TradeWork *)p)->f828, p, 0);
    func_021D8E84(p, (int)func_021DA064);
}









void func_021DA110(char *p)
{
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), 0x8E, (void *)(((TradeWork *)p)->f738));
    func_021E0FF4(p,1,0);
    ((TradeWork *)p)->f1080 = -1;
    func_021E4E64(((TradeWork *)p)->f828, p, 0);
    func_021D8E84(p, (int)func_021DA064);
}









void func_021DA158(char *p) {
    int v=(int)func_021D8D4C(*(void ** *)&((TradeWork *)p)->f828,((TradeWork *)p)->fF98,((TradeWork *)p)->fF94,p);
    func_021E2484(p,0);
    func_021E1E00(p,((TradeWork *)p)->f10A0,(void *)v);
    if (func_020355C4()) func_021D8B38(p);
    func_020307B0((void *)v);
    func_021D8E84(p,(int)func_021DA318);
}









void func_021DA1B4(char *p) {
 if(func_021DD5B4(p,((TradeWork *)p)->fF84,((TradeWork *)p)->fF88)) func_021D8E84(p,(int)func_021DBBD0);
}









void func_021DA1DC(char *p) {
    int v=0;
    int n;
    if(((TradeWork *)p)->fF88==((TradeWork *)p)->f630) v=1;
    n=func_021DD3D4(p,0,((TradeWork *)p)->fF84,((TradeWork *)p)->fF88);
    if(n!=-1) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xC13),(u16)1,&v)) {
            func_021D8E84(p,(int)func_021DA1B4);
            return;
        }
    } else func_021D8E84(p,(int)func_021DA1B4);
}









void func_021DA254(char *p) {
 if(func_021DD5B4(p,((TradeWork *)p)->fF84,((TradeWork *)p)->fF88)) func_021D8E84(p,(int)func_021DF5D8);
}









void func_021DA27C(char *p) {
    int v=0;
    int n;
    if(((TradeWork *)p)->fF88==((TradeWork *)p)->f630) v=1;
    n=func_021DD3D4(p,0,((TradeWork *)p)->fF84,((TradeWork *)p)->fF88);
    if(n!=-1) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xC13),(u16)1,&v)) {
            func_021D8E84(p,(int)func_021DA254);
            return;
        }
    } else func_021D8E84(p,(int)func_021DA254);
}









void func_021DA2F4(void *p) {
 int a,b;
 if(!TOUCHPANEL_GetPointCont((u32 *)(&a),(u32 *)(&b))) func_021D8E84(p,(int)func_021DBE70);
}









void func_021DA318(char *p)
{
    u32 x,y;
    int slot,column;
    int changed=0;
    int keep=1;
    int choice=keep-2;
    int active=0;
    int n;
    if(!APP_TASKMENU_IsDecide(P(0x64c))) {
        n=TOUCHPANEL_GetTrg();
        if(n) func_020355D8(keep);
        if(n) func_021D8C84(p);
        TOUCHBAR_Update(P(0x9c0));
        if(TOUCHBAR_GetPressedButtonIdIfPressing(P(0x9c0))==9 && func_020355C4()) APP_TASKMENU_SetCursorActive(P(0x64c),0);
        if(TOUCHBAR_GetPressedButtonIdIfDone(P(0x9c0))==9) {
            changed=1;
            (*(unsigned int *)&((TradeWork *)p)->f10A0)=1U-(*(unsigned int *)&((TradeWork *)p)->f10A0);
        }
        if(TOUCHPANEL_GetPointTrg(&x,&y)==1) {
            func_020355D8(1);
            APP_TASKMENU_SetCursorActive(P(0x64c),0);
            if(func_021D9EBC(p,(int *)(p+0xf98),(int *)(p+0xf94),&slot,&column)) {
                I(0xf78)=column;
                I(0xf74)=slot;
                (*(unsigned int *)&((TradeWork *)p)->fF54)=x;
                (*(unsigned int *)&((TradeWork *)p)->fF58)=y;
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed=1;
            } else if(y>=16 && y<144) active=1;
        }
        if(changed) {
            func_021E2484(p,1);
            func_021D8E84(p,(int)func_021DA158);
            return;
        }
        func_021D8C0C(p);
        if(!active && !TOUCHPANEL_GetCont() && I(0xf34)) {
            if(I(0xf60) && I(0xf5c)) {
                GFL_USE_PlaySeDefaultVolume(0x72a);
                choice=0;
                active=1;
            } else func_021D8C84(p);
        }
        func_021D8B54(p);
        func_021D8C0C(p);
    }
    if(APP_TASKMENU_IsFinish(P(0x64c))) {
        choice=APP_TASKMENU_GetCursorPos(P(0x64c));
        active=1;
    }
    if(active) {
        if(choice==0) {
            n=(int)func_021D8DD0((void *)I(0x828),I(0xf98),I(0xf94),p);
            if(func_021DBD70(p,I(0xf98),I(0xf94)) && func_021D8AA8(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA1DC);
            } else if(func_021D9548(p,I(0xf98),I(0xf94))) {
                func_021DF7AC(p,1);
                func_021D8E84(p,(int)func_021DA0CC);
            } else if(func_021DD0CC(p,n)) {
                func_021D8E84(p,(int)func_021DA110);
                func_021DF7AC(p,1);
            } else if(!func_021D8AA8(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021D9E54);
                func_021B6558((unsigned char *)I(0x9c0),7,0);
                func_021B6558((unsigned char *)I(0x9c0),8,0);
                func_021B6558((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else if(func_021DD2A8(p) && !func_020355C4()) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA27C);
                func_021B6558((unsigned char *)I(0x9c0),7,0);
                func_021B6558((unsigned char *)I(0x9c0),8,0);
                func_021B6558((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA1DC);
            }
        } else {
            func_021DF7AC(p,1);
            func_021D8E84(p,(int)func_021DA2F4);
        }
        I(0xf98)=-1;
        I(0xf94)=-1;
        if(keep) {
            func_021DBB6C(p);
            CLACT_SetActorDrawEnable(P(0xf04),1);
        }
        func_021E5EF8(p+0x950);
        func_021E5EF8(p+0x964);
        func_021E5EF8(p+0x978);
        func_021E2484(p,1);
        func_02041B6C(6);
        func_021E4174(p);
        func_021E12F8(p);
        P(0x64c)=0;
    }
    I(0xf34)=TOUCHPANEL_GetCont();
}









void func_021DA640(char *p) {
    Pair t;
    int n;
    int zero=0;
    func_021DF7AC(p,0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),7,0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),9,1);
    t=d_021E7594;
    func_021E1410(p,(int *)(&t),2);
    n=(int)func_021D8D4C(*(void ** *)&((TradeWork *)p)->f828,((TradeWork *)p)->fF98,((TradeWork *)p)->fF94,p);
    ((TradeWork *)p)->f10A0=zero;
    func_021E1E00(p,0,(void *)n);
    func_020307B0((void *)n);
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04,0);
    func_021D8C84(p);
    func_021D8B38(p);
    if(func_020355C4()) APP_TASKMENU_SetCursorActive((struct TaskMenu *)(((TradeWork *)p)->f64C),zero);
    else APP_TASKMENU_SetCursorActive((struct TaskMenu *)(((TradeWork *)p)->f64C),1);
    func_021D8E84(p,(int)func_021DA318);
}









void func_021DA700(char *p) {
 u8 b=((TradeWork *)p)->f10A0;
 if(func_021D8A24(p)) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,1,&b)==0) return;}
 *(unsigned *)0x04001000 &= 0xffff1fff;
 if(func_021D8AA8(p)==0) func_021D8E84(p,(int)func_021D4B88);
 else func_021D8E84(p,(int)func_021D6F2C);
}









void func_021DA76C(void *p) {
 if(!func_021D8A24(p) || GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),13,8)) func_021D8E84(p,(int)func_021DA700);
}









void func_021DA798(char *p) {
 int i, j, v;
 unsigned char a, b;
 i = GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()));
 j = 1 - i;
 if(func_021D8A24(p) && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),27,8)==0) {
  func_021DD24C(p);
  return;
 }
 func_021DD294(p,1,1);
 a = (p+i)[0x11e0];
 if(a==2 && ((unsigned char *)(p+j))[0x11e0]==2) {
  if(func_021D8A24(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),13,8);
  func_021D8E84(p,(int)func_021DA76C);
  return;
 }
 b = (p+j)[0x11e0];
 if(b==5) v=0x61;
 else if(a==5) v=0x62;
 else if(b==7) v=0x63;
 else if(a==7) v=0x64;
 else if(b==8) v=0x64;
 else if(a==8) v=0x63;
 else if(b==9) v=0x61;
 else if(a==9) v=0x65;
 else if(b==6) v=0x61;
 else if(a==6) v=0x6f;
 else if(b==3) v=0x61;
 else if(a==3) v=0x66;
 func_02045CAC((struct MsgBank *)((*(unsigned int *)&((TradeWork *)p)->f720)),v,(void *)((*(unsigned int *)&((TradeWork *)p)->f738)));
 func_021E1024(p);
 p[0x11e0]=0;
 p[0x11e1]=0;
 func_021D8E84(p,(int)func_021DAEF0);
}









void func_021DA898(char *p) {
 if(func_021D8AA8(p)) {func_021DBA80(p);func_021DBAF8(p);func_021D8E84(p,(int)func_021DC370);}
 else {func_021DBA80(p);func_021DBAF8(p);}
 WIPE_SYS_Start(0,1,1,0,6,1,((TradeWork *)p)->f5F4);
 BG_SYS_SetMainVisiblePlanes(31);BG_SYS_SetSubVisiblePlanes(30);
}









void func_021DA8F8(char *p)
{
 if(func_021D8A24(p) && !GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,8)) return;
 func_021E1098(p);
 if(func_021D8AA8(p)) {
  func_021DD1B8(p);func_021DF904(p);
  if(((TradeWork *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(0);
  func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),134,(void *)(((TradeWork *)p)->f738));func_021E1024(p);
  func_021DD528(p,0);func_021DD68C(p);
  ((TradeWork *)p)->f11E8=0;((TradeWork *)p)->f11E9=0;
  func_021DF78C(p);func_021DF7AC(p,1);
  MI_CpuFill8(p+0xca0,0,0x78);MI_CpuFill8(p+0xd18,0,0x3c);MI_CpuFill8(p+0xd54,0,0x3c);
  func_021D8C84(p);
  if(((TradeWork *)p)->f64C) {APP_TASKMENU_CloseMenu((struct TaskMenu *)(((TradeWork *)p)->f64C));((TradeWork *)p)->f64C=0;}
  func_021E4420(p);func_021E6700(p);func_021DBB6C(p);
 }
 func_021D8E84(p,(int)func_021DA898);func_021DB7AC(p,0,1);
}









void func_021DA9F0(void *p) {
 if(func_021E12AC(p) && WIPE_SYS_EndCheck()) {
  func_021E1098(p);
  func_021D8E84(p,(int)func_021DA8F8);
 }
}









void func_021DAA18(char *p) {
 WIPE_SYS_Start((void *)4,0,0,0,6,1,((TradeWork *)p)->f5F4);
 func_021D8E84(p,(int)func_021DA9F0);
}









void func_021DAA4C(void *p) {
 if(!func_021D8A24(p) || GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,8)!=0) {
  func_021E31FC(p);
  func_021D8E84(p,(int)func_021DAA18);
 }
}









void func_021DAA7C(char *p) {
 if(func_021D8A24(p)) {
  if(GFL_NET_SendData((unsigned)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0e,0x2d6,(u32)(p+16),0,0,1)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,8);func_021D8E84(p,(int)func_021DAA4C);
  }
 } else {func_021E31FC(p);func_021D8E84(p,(int)func_021DAA4C);}
}









void func_021DAAE4(char *p) {
 func_021DC62C(p,((TradeWork *)p)->fF2C-1);
 if(((TradeWork *)p)->fF2C>=24) func_021D8E84(p,(int)func_021DAA7C);
}









void func_021DAB0C(char *p) {
 if(func_021E3E00(p,((TradeWork *)p)->fF2C-1)) {
  ((TradeWork *)p)->fF2C=0;
  func_021D8E84(p,(int)func_021DAAE4);
 }
}









void func_021DAB34(char *p) {
 u8 b[2];
 if(func_021D8A24(p)) {
  b[0]=((TradeWork *)p)->f630;b[1]=func_021D89A8(p);
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc10,2,(void *)b)) {((TradeWork *)p)->fF2C=0;func_021D8E84(p,(int)func_021DAB0C);}
 } else {
  p[0x11f2]=((TradeWork *)p)->f630;(*(unsigned short *)&((TradeWork *)p)->f107E)=((TradeWork *)p)->f11F2*160+16;
  ((TradeWork *)p)->fF2C=0;func_021D8E84(p,(int)func_021DAB0C);
 }
}









void func_021DABB0(char *p) {
 func_021E5098(p,((TradeWork *)p)->fF2C-1);
 if(((TradeWork *)p)->fF2C>25) {
  func_021E4E64(((TradeWork *)p)->f828,p,0);
  func_021D8E84(p,(int)func_021DAB34);
 }
}









void func_021DABE8(char *p) {
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),22,8)) {
  GFL_NET_SetAutoExit(1);
  GFL_NET_SetLoginOption(1);
  ((TradeWork *)p)->fF2C=0;
  func_021D8E84(p,(int)func_021DABB0);
 }
}









void func_021DAC20(void *p) {
 if(WIPE_SYS_EndCheck()) {
  if(func_021D8A24(p)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),22,8);
   func_021D8E84(p,(int)func_021DABE8);
  } else { func_021D8E84(p,(int)func_021DAB34); }
 }
}









void func_021DAC60(char *p) {
 GFL_NET_RestartWithDefaultTimeout(1,((TradeWork *)p)->f5F4);if(((TradeWork *)p)->f118C==2)DWC_RAP_SetVchatTalkLock(1);
 func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),6,(void *)(((TradeWork *)p)->f738));func_021E0FF4(p,1,0);func_021E1030(p);
 BG_SYS_SetMainVisiblePlanes(16);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(0);
 WIPE_SYS_Start((void *)4,1,1,0,6,1,((TradeWork *)p)->f5F4);func_021D8E84(p,(int)func_021DAC20);
}









void func_021DACE4(char *p) {
 int i;
 GFL_NET_SYSTEM_GetCurrentAid();((TradeWork *)p)->fF88=-1;((TradeWork *)p)->fF84=-1;((TradeWork *)p)->f800=0;((TradeWork *)p)->fF60=0;((TradeWork *)p)->f1060=0;
 func_021E36D8(p,0);func_021E36D8(p,1);if(func_021D8AA8(p))func_021DD1B8(p);
 MI_CpuFill8(((TradeWork *)p)->f5DC,0,func_020173EC());MI_CpuFill8(((TradeWork *)p)->f5E0,0,func_020173EC());
 for(i=0;i<10;i++) {if(*(int *)(p+0xefc+4*i))CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p+0xefc+4*i),1);}
 func_021E1098(p);func_021D8E84(p,(int)func_021DAC60);
}









void func_021DAD84(void *p) {
 if(func_021E12AC(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),27,8);
  func_021D8E84(p,(int)func_021DA798);
 }
}










void func_021DADAC(void *p)
{
    u8 b = 3;

    if (func_021D8A24(p) == 0) {
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), 0x61,
                      (void *)(((TradeWork *)p)->f738));
        func_021E1024(p);
        func_021D8E84(p, 0x021DAEF1);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b) == 0)
        return;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), 6, (void *)(((TradeWork *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, 0x021DAD85);
}









void func_021DAE2C(char *p) {
 int i;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {func_021DD24C(p);return;}
 func_021DD294(p,1,1);func_021E1098(p);
 p[0x11e0]=0;p[0x11e1]=0;p[0x11e8]=0;p[0x11e9]=0;
 for(i=0;i<6;i++) {
  char *q=p+(i/3)*12+(i%3)*4;
  ((TradeWork *)q)->fFA4=-1;
  if(((TradeWork *)q)->fFD8)MI_CpuFill8(((TradeWork *)q)->fFD8,0,func_020173EC());
 }
 func_021D8E84(p,(int)func_021DBA80);
}









void func_021DAEC8(void *p) {
 if(func_021E12AC(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8);
  func_021D8E84(p,(int)func_021DAE2C);
 }
}









static inline int poll_a(void) {int r=KEY_GetTrg();if(r)func_020355D8(0);return r;}









static inline int poll_b(void) {int r=TOUCHPANEL_GetTrg();if(r)func_020355D8(1);return r;}









void func_021DAEF0(char *p) {
 if(func_021E12AC(p)) {
  if(poll_a() || poll_b()) {
   func_021E1098(p);
   if(func_021D8A24(p)) {
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),50,(void *)(((TradeWork *)p)->f738));func_021E1024(p);func_021E1030(p);func_021D8E84(p,(int)func_021DAEC8);
   } else func_021D8E84(p,(int)func_021DBA80);
  }
 }
}








void func_021DAF68(void *p) {
 unsigned id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(func_021E12AC(p)) {
  if(func_021D8A24(p)) {
   b=2;
   if(GFL_NET_SendToHandle((void *)id,0xc0f,1,&b)) func_021D8E84(p,(int)func_021D9C00);
  } else { func_021D8E84(p,(int)func_021D9C00); }
 }
}








void func_021DAFB8(char *p) {
 u8 b;
 if(func_021D8A24(p)) {
  b=4;
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&b)) {
   func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),136,(void *)(((TradeWork *)p)->f738));func_021E1024(p);func_021E1030(p);
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);func_021D8E84(p,(int)func_021DAF68);
  }
 } else {((struct Obj22732 *)(((TradeWork *)p)->f8))->f8=3;func_021D8E84(p,(int)func_021D9434);}
}








/*
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16_021D9124 derives -1 from zero.
 */
/*
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16 derives -1 from zero.
 */
void func_021DB030(char *p) {
 int v;
 if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))) {
  v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));func_021E12F8(p);((TradeWork *)p)->f64C=0;
  switch(v) {
  case 0:func_021D8E84(p,(int)func_021DAFB8);return;
  case 1:func_021E1098(p);func_021D8E84(p,(int)func_021DBE70);
   ((TradeWork *)p)->f1080=-1;func_021E4E64(((TradeWork *)p)->f828,p,0);func_021E6700(p);return;
  }
 }
}








int func_021DB0A0(char *p)
{
    int t=(int)func_021D8D4C(*(void ** *)&((TradeWork *)p)->f828,((TradeWork *)p)->fF88,((TradeWork *)p)->fF84,p);
    if(func_021D8A24(p)) {
        unsigned id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
        if(GFL_NET_SendToHandle((void *)id,(u16)0xc01,(u16)func_020173EC(),(void *)t)==0) {
            func_020307B0((void *)t);
            return 0;
        }
    }
    func_021D9468(p,0,(void *)t);
    func_020307B0((void *)t);
    return 1;
}








void func_021DB10C(char *p)
{
    if(func_021E12AC(p)) {
        Pair t=d_021E758C;
        func_021E131C(p,(int *)(&t),2,0x20,0xc);
        ((TradeWork *)p)->f1080=-1;
        func_021E4E64(((TradeWork *)p)->f828,p,0);
        func_021D8E84(p,(int)func_021DB030);
    }
}








void func_021DB164(char *p) {
 func_02045CAC((struct MsgBank *)((*(unsigned int *)&((TradeWork *)p)->f720)),0x8c,(void *)((*(unsigned int *)&((TradeWork *)p)->f738)));
 func_021E1024(p);
 ((TradeWork *)p)->f1074=1;
 func_021D8E84(p,(int)func_021DB10C);
}








void func_021DB198(void *p) {
 func_0207D658((u32)((void *)0x04001050),27,-8);
 func_021D8E84(p,(int)func_021DB164);
}








int func_021DB1BC(char *p,int kind)
{
    int index=func_021E4DBC(p);
    int outer;
    for(outer=0;outer<((TradeWork *)p)->f634;outer++) {
        int inner;
        index++;
        if(index>=((TradeWork *)p)->f634) index=0;
        for(inner=0;inner<5;inner++) {
            int a=func_021D8AF4(index,p);
            int b=func_021D8B0C(index,inner);
            int obj=(int)func_021D8DD0((void *)(((TradeWork *)p)->f828),a,b,p);
            if(obj && func_021E4AA4(func_02017E88((void *)obj,0xab,0),kind) && !func_02017E88((void *)obj,0x4c,0)) {
                ((TradeWork *)p)->f1080+=1;
                ((TradeWork *)p)->f107C=func_021DB4B4(index)-0x20;
                ((TradeWork *)p)->f1084=1;
                func_021DB7AC(p,0,1);
                return 1;
            }
        }
    }
    return 0;
}








void func_021DB278(void *p) {
 BG_SYS_SetSubVisiblePlanes(30);
 func_021D8E84(p,(int)func_021DBE70);
}








/*
 * volatile: hardware read/write at 021DB2AA/021DB2AE
 */
void func_021DB290(void *p)
{
    BG_SYS_SetSubVisiblePlanes(0x1a);
    func_021E5D84(p);
    func_021E1098(p);
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    func_021DF7AC(p,1);
    func_021E71E0(p,0);
    func_021DBB6C(p);
    func_021E6700(p);
    func_021E7058(p);
    func_021D8E84(p,(int)func_021DB278);
}








void func_021DB2E8(void *p) {
 if(func_021E707C(p)==0) func_021D8E84(p,(int)func_021DB290);
}








/*
 * lever: non-const table keeps reads after the p+0x800 store (const: 16 bytes differ).
 * volatile: hardware read/write at 021DB358/021DB35C and 021DB3C6/021DB3CA.
 * prototype: 02035C08 returns the live r0 result of 02035BBC (full original
 * 02035BBC and matched forwarder read); caller uses it despite void header.
 */
void func_021DB304(char *p)
{
    int index;
    BG_SYS_SetSubVisiblePlanes(31);
    if(func_021E12AC(p)) {
        index=TOUCHPANEL_HitTrg(d_021E8044);
        if(index!=-1) {
            (*(unsigned int *)&((TradeWork *)p)->f800)=(u32)index+1u;
            func_021E6FD4(p,d_021E8044[index].c,d_021E8044[index].a);
            if(func_021DB1BC(p,index)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                *(volatile u32 *)0x04001000 &= 0xffff1fff;
                func_021D8E84(p,(int)func_021DB2E8);
                return;
            }
            func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),0x34,(void *)(((TradeWork *)p)->f738));
            func_021E0EF4(p,1,1,1,0x1d,4);
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
        TOUCHBAR_Update((*(void * *)&((TradeWork *)p)->f9C0));
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->f9C0)==1) {
            BG_SYS_SetSubVisiblePlanes(0x1a);
            ((TradeWork *)p)->f800=0;
            func_021E5D84(p);
            func_021E1098(p);
            *(volatile u32 *)0x04001000 &= 0xffff1fff;
            func_021DF7AC(p,1);
            func_021E71E0(p,0);
            func_021DBB6C(p);
            func_021E6700(p);
            func_021E7058(p);
            func_021D8E84(p,(int)func_021DB290);
        }
    }
}








void func_021DB41C(char *p)
{
    func_021E5C64(p);
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),0x33,(void *)(((TradeWork *)p)->f738));
    func_021E0EF4(p,1,1,1,0x1d,4);
    func_021D8E84(p,(int)func_021DB304);
}








void func_021DB45C(char *p)
{
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),7,0);
    func_021DF7AC(p,0);
    func_0207D658((u32)((void *)0x04001050),10,-8);
    func_021E71E0(p,1);
    if(func_021DD2F4(p))
        TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),8,0);
    func_021D8E84(p,(int)func_021DB41C);
}







/*
 * Position of a slot: 0 and 1 are special, the rest on a 6-column grid.
 * Lever: the remainder is stored back into the same local as the dividend
 * (b = b % 6); a separate remainder local stays in r1 and changes colours.
 */
int func_021DB4B4(int a)
{
    int b, q;

    if (a == 0)
        return 0;
    if (a == 1)
        return 0x30;
    b = a - 2;
    q = b / 6;
    b = b % 6;
    return q * 0xa0 + 0x60 + b * 0x1a;
}







int func_021DB4EC(char *p, int index)
{
    int position = func_021DB4B4(index);
    int start = ((TradeWork *)p)->f107C;
    if (start < position && start + 0xe0 > position)
        return 1;
    position += ((TradeWork *)p)->f63C;
    if (start < position && start + 0xe0 > position)
        return 1;
    return 0;
}







void func_021DB52C(char *p)
{
    int changed = 0;
    int i, v;
    unsigned int k = KEY_GetRepeat();
    if (((TradeWork *)p)->fF60 != 0)
        return;
    if (k & 0x100) {
        func_020355D8(0);
        for (i = 0; i < ((TradeWork *)p)->f630 + 1; i++) {
            if (d_021E7FE0[i] > ((TradeWork *)p)->f107C) {
                ((TradeWork *)p)->f107C = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((TradeWork *)p)->f107C = d_021E7FE0[0];
        }
        func_021DD018(p, changed);
    } else if (k & 0x200) {
        func_020355D8(0);
        for (i = ((TradeWork *)p)->f630; i >= 0; i--) {
            if (d_021E7FE0[i] < ((TradeWork *)p)->f107C) {
                ((TradeWork *)p)->f107C = d_021E7FE0[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((TradeWork *)p)->f107C = d_021E7FE0[((TradeWork *)p)->f630];
        }
        func_021DD018(p, changed);
    } else if (KEY_GetRepeat() == 0x40) {
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            ((TradeWork *)p)->fF74 = v;
        if (--((TradeWork *)p)->fF78 < 0) {
            if (((TradeWork *)p)->fF74 < 2)
                ((TradeWork *)p)->fF78 = 2;
            else
                ((TradeWork *)p)->fF78 = 4;
        }
        ((TradeWork *)p)->f1080 = ((TradeWork *)p)->f1080 - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x80) {
        int x;
        func_020355D8(0);
        if (func_021E4E0C(p, &v) == 0)
            ((TradeWork *)p)->fF74 = v;
        x = ++((TradeWork *)p)->fF78;
        if (((TradeWork *)p)->fF74 < 2) {
            if (x >= 3)
                ((TradeWork *)p)->fF78 = 0;
        } else if (x >= 5)
            ((TradeWork *)p)->fF78 = 0;
        ((TradeWork *)p)->f1080 = ((TradeWork *)p)->f1080 - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x10) {
        func_020355D8(0);
        ((TradeWork *)p)->f1080 = ((TradeWork *)p)->f1080 - 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            ((TradeWork *)p)->fF74 = v;
        } else {
            ((TradeWork *)p)->fF74 = ((TradeWork *)p)->fF74 + 1;
            if (func_021DB4EC(p, ((TradeWork *)p)->fF74) == 0) {
                ((TradeWork *)p)->f107C = func_021DB4B4(((TradeWork *)p)->fF74 + 1) - 0x100;
                ((TradeWork *)p)->f1080 = -1;
            }
        }
        if (((TradeWork *)p)->fF74 >= ((TradeWork *)p)->f634)
            ((TradeWork *)p)->fF74 = 0;
        if (((TradeWork *)p)->fF74 < 2 && ((TradeWork *)p)->fF78 >= 3)
            ((TradeWork *)p)->fF78 = 2;
    } else if (KEY_GetRepeat() == 0x20) {
        func_020355D8(0);
        ((TradeWork *)p)->f1080 = ((TradeWork *)p)->f1080 + 1;
        changed = 1;
        if (func_021E4E0C(p, &v) == 0) {
            ((TradeWork *)p)->fF74 = v;
        } else {
            ((TradeWork *)p)->fF74 = ((TradeWork *)p)->fF74 - 1;
            if (((TradeWork *)p)->fF74 < 0)
                ((TradeWork *)p)->fF74 = ((TradeWork *)p)->f634 - 1;
            if (func_021DB4EC(p, ((TradeWork *)p)->fF74) == 0) {
                ((TradeWork *)p)->f107C = func_021DB4B4(((TradeWork *)p)->fF74);
                ((TradeWork *)p)->f1080 = -1;
            }
        }
        if (((TradeWork *)p)->fF74 < 0)
            ((TradeWork *)p)->fF74 = ((TradeWork *)p)->f634 - 1;
        if (((TradeWork *)p)->fF74 < 2 && ((TradeWork *)p)->fF78 >= 3)
            ((TradeWork *)p)->fF78 = 2;
    }
    if (changed) {
        ((TradeWork *)p)->f1084 = 1;
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DB7AC(p, 0, 1);
    }
}







void func_021DB7AC(char *p,int a,int b)
{
    if(H(0x107c)<0) H(0x107c)+=(s16_021D9124)I(0x63c);
    if(I(0x63c)<=H(0x107c)) H(0x107c)-=(s16_021D9124)I(0x63c);
    func_021E4E64(I(0x828),p,1);
    func_021E42B4(p);
    func_021E4598(p);
    if(GFL_USE_IsAnySeBusy()==0 && a) GFL_USE_PlaySeDefaultVolume(0x72b);
    if(func_021D8A24(p) && b) {
        if(GFL_NET_IsNetTypeWifi()) {
            if(H(0x107c)%16==0) {
                GFL_NET_SendData((u32_021DB7AC)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(u32_021DB7AC)(p+0x107c),0,1,1);
                return;
            }
        } else {
            GFL_NET_SendData((u32_021DB7AC)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(u32_021DB7AC)(p+0x107c),0,1,1);
            return;
        }
    } else {
        if(func_021D8A24(p)==0) H(0x107e)=H(0x107c);
    }
}







void func_021DB89C(char *p)
{
    int x,y,i;
    if(I(0xf60)) return;
    if(TOUCHPANEL_GetPointCont((u32_021DB89C *)(&x),(u32_021DB89C *)(&y))) {
        if(I(0x1088)) {
            if((unsigned)x>=64 && (unsigned)x<192 && (unsigned)y>=168 && (unsigned)y<188) {
                int previous;
                CLACT_SetActorAutoAnim((struct Obj *)I(0xf04),1);
                previous=H(0x1078);
                H(0x107a)=(x-previous)*2;
                H(0x1078)=x;
                H(0x107c)-=H(0x107a);
                if(H(0x107a)>12) func_021DB7AC(p,1,1);
                else func_021DB7AC(p,0,1);
            } else H(0x107a)=0;
        }
        H(0x1078)=x;
    } else H(0x1078)=0;
    if(TOUCHPANEL_GetCont()==0 && H(0x107a)!=0) {
        for(i=2;i!=0 && H(0x107a)!=0;i--) {
            if(H(0x107a)<0) H(0x107a)++;
            if(H(0x107a)>0) H(0x107a)--;
        }
        H(0x107c)-=H(0x107a);
        func_021DB7AC(p,1,1);
    }
}







void func_021DB998(char *p)
{
    if (TOUCHPANEL_GetCont() == 0)
        func_021D8E84(p, (int)func_021DBE70);
}







void func_021DB9B4(char *p)
{
    func_021DD34C(p,((TradeWork *)p)->fF98,((TradeWork *)p)->fF94);
    if(func_021D8A24(p)) {
        if(!GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)) return;
    }
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),8,0);
    ((TradeWork *)p)->fF84=-1;
    ((TradeWork *)p)->fF88=-1;
    ((TradeWork *)p)->fF7C=-1;
    ((TradeWork *)p)->fF80=-1;
    ((TradeWork *)p)->fF94=-1;
    ((TradeWork *)p)->fF98=-1;
    func_021D94A0(p,0);
    func_021D8B38(p);
    func_021D8E84(p,(int)func_021DB998);
}






void func_021DBA38(void *p)
{
    if (func_021D8A24(p)==0) {
        func_021D94A0(p,1);
        func_021D8E80(p);
        func_021D8E84(p,(int)func_021DBAF8);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)!=0)
        func_021D8E84(p,(int)func_021DBAF8);
}






void func_021DBA80(char *p)
{
    ((TradeWork *)p)->f1088=0;
    ((TradeWork *)p)->f1078=0;
    ((TradeWork *)p)->f107A=0;
    MI_CpuFill8(p+0xca0,0,0x78);
    MI_CpuFill8(p+0xd18,0,0x3c);
    MI_CpuFill8(p+0xd54,0,0x3c);
    func_021D8C84(p);
    func_021DF7AC(p,1);
    if(((TradeWork *)p)->f64C) {
        APP_TASKMENU_CloseMenu((struct TaskMenu *)(((TradeWork *)p)->f64C));
        ((TradeWork *)p)->f64C=0;
    }
    func_021D94A0(p,0);
    func_021D8E84(p,(int)func_021DBA38);
}






void func_021DBAF8(char *p)
{
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),8,0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),7,1);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),9,0);
    func_021D8980(p);
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04,1);
    func_021E4420(p);
    func_021E6700(p);
    ((TradeWork *)p)->fF84=-1;
    ((TradeWork *)p)->fF88=-1;
    func_021D8B38(p);
    func_021D8E84(p,(int)func_021DBE70);
}




#undef I



#undef I


#undef I

#undef I


#define I(p, o) (*(int *)((p) + (o)))




#undef H



#undef H


#undef H

#undef H

#define H(p, o) (*(short *)((p) + (o)))








void func_021DBB6C(char *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04,1);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),8,func_021DD2F4(p));
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),8,func_021DD2F4(p));
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),7,1);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),9,0);
    func_021D8980(p);
    func_021D8B38(p);
}








void func_021DBBD0(char *p) { func_021DF7AC(p,1); MI_CpuFill8(p+0xca0,0,0x78); MI_CpuFill8(p+0xd18,0,0x3c); MI_CpuFill8(p+0xd54,0,0x3c); func_021D8C84(p); if(((TradeWork *)p)->f64C) {APP_TASKMENU_CloseMenu((struct TaskMenu *)((TradeWork *)p)->f64C); ((TradeWork *)p)->f64C=0;} func_021E4420(p);func_021E6700(p);func_021DBB6C(p);func_021D8E84(p,(int)func_021DBE70);}








void func_021DBC3C(char *p) {
 if(func_021D8AA8(p)) { if(func_021DD5B4(p,((TradeWork *)p)->fF84,((TradeWork *)p)->fF88)==0) return; }
 else { if(func_021DB0A0(p)==0) return; }
 ((TradeWork *)p)->fF98=-1; ((TradeWork *)p)->fF94=-1;
 ((TradeWork *)p)->fF7C=-1; ((TradeWork *)p)->fF80=-1;
 func_021D8B38(p); func_021D8E84(p,(int)func_021DBE70);
}








void func_021DBC98(char *p) {int same=0;if(((TradeWork *)p)->fF88==((TradeWork *)p)->f630)same=1;if(func_021D8AA8(p)) {int n=func_021DD3D4(p,0,((TradeWork *)p)->fF84,((TradeWork *)p)->fF88);if(n!=-1) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),n+0xc13,1,&same)) {func_021D8E84(p,(int)func_021DBC3C);return;}} else {func_021D8E84(p,(int)func_021DBC3C);return;}} else {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc16,1,&same))func_021D8E84(p,(int)func_021DBC3C);}}








void func_021DBD3C(char *p)
{
    if (func_021E665C(p)) {
        if (func_021D8A24(p)) {
            func_021D8E84(p, (int)func_021DBC98);
            return;
        }
        func_021D8E84(p, (int)func_021DBC3C);
    }
}








int func_021DBD70(char *p,int a,int b) {
 if(func_021D8AA8(p)==0) {
  if(((TradeWork *)p)->fF84==b && ((TradeWork *)p)->fF88==a) return 1;
 } else { if(func_021DD34C(p,a,b)!=-1) return 1; }
 return 0;
}








int func_021DBDB4(char *p) {int e=(int)func_021D8DD0((void *)(((TradeWork *)p)->f828),((TradeWork *)p)->fF98,((TradeWork *)p)->fF94,p);if(func_021DBD70(p,((TradeWork *)p)->fF98,((TradeWork *)p)->fF94)) {GFL_USE_PlaySeDefaultVolume(0x626);if(func_021D8AA8(p)==0){func_021D8E84(p,(int)func_021DB9B4);return 1;}func_021D8E84(p,(int)func_021DF708);return 1;}if(e && func_02017E88((void *)e,0xa9,0)) {GFL_USE_PlaySeDefaultVolume(0x54b);func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0), 8, 0);func_021E12F8(p);func_021D8E84(p,(int)func_021DA640);return 1;}func_021D8C84(p);((TradeWork *)p)->fF98=-1;((TradeWork *)p)->fF94=-1;return 0;}















/*
 * The bound block after func_021E4DBC closes only with its six locals
 * declared without initialisers and assigned afterwards; about a fifth of
 * the declaration orders then match (docs/notes/pkt_ov119_021DBE70.c.txt).
 */
void func_021DBE70(char *p)
{
    int n;
    int e;
    p[0x11EA] = 1;
    if (TOUCHPANEL_GetCont()) {
        func_020355D8(1);
        if (KEY_GetCont())
            return;
    }
    if (func_020355C4() && poll_a()) {
        func_020355D8(0);
        if (func_021E4E0C(p, &n) == 0) {
            int v = n;
            I(p, 0xF74) = v;
            if (v < 2 && I(p, 0xF78) >= 3)
                I(p, 0xF78) = 2;
        } else if (func_021DB4EC(p, I(p, 0xF74)) == 0) {
            int end;
            int a;
            int t;
            int cur;
            int b;
            int lim;
            t = func_021E4DBC(p);
            cur = I(p, 0xF74);
            a = t + 5;
            b = t + 10;
            lim = I(p, 0x634);
            end = cur;
            if (b >= lim && cur < 0x14)
                end = cur + (lim + 1);
            if (a < end)
                H(p, 0x107C) = func_021DB4B4(cur + 1) - 0x100;
            else
                H(p, 0x107C) = func_021DB4B4(cur);
            H(p, 0x1080) = -1;
            I(p, 0x1084) = 1;
            func_021DB7AC(p, 0, 1);
            H(p, 0x107A) = 0;
            return;
        }
        func_021D8B38(p);
        H(p, 0x107A) = 0;
        return;
    }
    if (poll_a() || poll_b())
        H(p, 0x107A) = 0;
    if (poll_b()) {
        func_021D8C84(p);
        I(p, 0xF98) = -1;
        I(p, 0xF94) = -1;
    }
    func_021D8B54(p);
    func_021D8C0C(p);
    func_021DB52C(p);
    func_021DF7F0(p);
    if (poll_a() == 1) {
        func_020355D8(0);
        if (func_021E4E0C(p, &n) == 0) {
            int v = n;
            I(p, 0xF74) = v;
            if (v < 2) {
                if (I(p, 0xF78) >= 3)
                    I(p, 0xF78) = 0;
            } else if (I(p, 0xF78) >= 5)
                I(p, 0xF78) = 0;
        }
        e = (int)func_021D8DD0((void *)I(p, 0x828), func_021D8AF4(I(p, 0xF74), p), func_021D8B0C(I(p, 0xF74), I(p, 0xF78)), p);
        if (e && func_02017E88((void *)e, 0xA9, 0)) {
            if (func_021DD0CC(p, e)) {
                func_02045CAC((struct MsgBank *)I(p, 0x720), 0x8E, (void *)I(p, 0x738));
                func_021E0FF4(p, 1, 0);
                func_021D8E84(p, (int)func_021DA064);
                return;
            }
            I(p, 0xF98) = func_021D8AF4(I(p, 0xF74), p);
            I(p, 0xF94) = func_021D8B0C(I(p, 0xF74), I(p, 0xF78));
            func_020355D8(0);
            if (func_021D8AA8(p) && func_021DD34C(p, I(p, 0xF98), I(p, 0xF94)) != -1) {
                GFL_USE_PlaySeDefaultVolume(0x626);
                func_021D8E84(p, (int)func_021DF708);
                return;
            }
            func_021D8DD0((void *)I(p, 0x828), I(p, 0xF98), I(p, 0xF94), p);
            func_021D8C84(p);
            func_021E4A1C(p);
            func_021DBDB4(p);
            return;
        }
    }
    switch (func_021D9F24(p, 0)) {
    case 3:
        return;
    case 2:
        break;
    case 1:
        func_020355D8(1);
        I(p, 0xF70) = 1;
    default:
        if (!TOUCHPANEL_GetCont()) {
            if (I(p, 0x1088) && I(p, 0xF5C) && I(p, 0xF60)) {
                I(p, 0x1088) = 0;
                I(p, 0xF5C) = 0;
                if (func_021D9548(p, I(p, 0xF80), I(p, 0xF7C))) {
                    I(p, 0xF80) = -1;
                    I(p, 0xF7C) = -1;
                    func_021D8C6C(p);
                    func_021D8E84(p, (int)func_021DA0CC);
                    return;
                }
                I(p, 0xF98) = I(p, 0xF80);
                I(p, 0xF94) = I(p, 0xF7C);
                I(p, 0xF84) = I(p, 0xF7C);
                I(p, 0xF88) = I(p, 0xF80);
                I(p, 0xF60) = 0;
                func_021B6558((unsigned char *)I(p, 0x9C0), 8, 1);
                TOUCHBAR_SetButtonEnabled((unsigned char *)I(p, 0x9C0), 8, 1);
                func_021E6544(p);
                GFL_USE_PlaySeDefaultVolume(0x72A);
                func_021D8E84(p, (int)func_021DBD3C);
                return;
            }
            if (I(p, 0x1088) && I(p, 0xF60) && I(p, 0xF70)) {
                I(p, 0xF98) = I(p, 0xF80);
                I(p, 0xF94) = I(p, 0xF7C);
                func_021DBDB4(p);
                return;
            }
            if (I(p, 0xF7C) != -1 && I(p, 0xF80) != -1) {
                func_021D8C84(p);
                func_021D8B38(p);
            } else {
                func_021D8C84(p);
            }
            I(p, 0x1088) = 0;
            I(p, 0xF5C) = 0;
            CLACT_SetActorAutoAnim((struct Obj *)I(p, 0xF04), 0);
        }
        func_021DB89C(p);
        if (TOUCHPANEL_GetCont())
            I(p, 0x1088) = 1;
        TOUCHBAR_Update((struct S *)I(p, 0x9C0));
        switch (TOUCHBAR_GetPressedButtonIdIfPressing((u8 *)I(p, 0x9C0))) {
        case 1:
        case 7:
        case 8:
            func_021D8E84(p, (int)func_021DC2B0);
            break;
        }
        break;
    }
}





#undef I




#undef I



#undef I


#undef I

#undef I
#define I(o) (*(int *)(p+(o)))





#undef H




#undef H



#undef H


#undef H

#undef H
#define H(o) (*(u16 *)(p+(o)))










void func_021DC2B0(char *p){TOUCHBAR_Update((struct S *)(((TradeWork *)p)->f9C0));switch(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->f9C0)) {case 1:func_021D8E84(p,(int)func_021DB198);return;case 7:func_021D8E84(p,(int)func_021DB45C);return;case 8:if(func_021D8AA8(p)){if(func_021DD2F4(p)){func_021B6558((unsigned char *)((TradeWork *)p)->f9C0,7,0);func_021B6558((unsigned char *)((TradeWork *)p)->f9C0,8,0);func_021D8C6C(p);func_021D8E84(p,(int)func_021DF5D8);return;}else{func_021B6558((unsigned char *)((TradeWork *)p)->f9C0,7,1);func_021B6558((unsigned char *)((TradeWork *)p)->f9C0,8,0);}}else{if(((TradeWork *)p)->fF84==-1){func_021B6558((unsigned char *)((TradeWork *)p)->f9C0,7,1);func_021B6558((unsigned char *)((TradeWork *)p)->f9C0,8,0);}else{func_021D8E84(p,(int)func_021D9E54);return;}}func_021D8E84(p,(int)func_021DBE70);return;}}



























void func_021DC370(char *p) {int hit=0;if(func_021E12AC(p)) {if(poll_a()) {func_020355D8(0);hit=1;}if(poll_b()){hit=1;func_020355D8(1);}if(hit){func_021E1098(p);func_021E6700(p);func_021D8E84(p,(int)func_021DBE70);((TradeWork *)p)->f1080=-1;func_021E4E64(((TradeWork *)p)->f828,p,1);}}}











void func_021DC3EC(char *p)
{
    func_021E55BC(p);
    ((TradeWork *)p)->f840 = MCSS_Init(4, (((TradeWork *)p)->f5F4 & 0x7FFF) | 0x8000);
    MCSS_SetTextureTransAdrs(((TradeWork *)p)->f840, 3 << 16);
    MCSS_SetOrthoMode(((TradeWork *)p)->f840);
}










void func_021DC428(char *p)
{
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    MCSS_Exit(((TradeWork *)p)->f840);
    ((TradeWork *)p)->f840 = 0;
    G3D_CAMERA_Delete((*(void * *)&((TradeWork *)p)->f810));
    G3D_SYSTEM_Exit();
}










void func_021DC458(char *p)
{
    func_0203F8F4(0x91);
    BMP_WIN_Init(((TradeWork *)p)->f5F4);
    func_021E53F8(p);
    func_021E5430(p);
    func_021E5680(p);
}










void func_021DC484(void *a0)
{
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    func_0203F9B4();
}










void func_021DC494(char *p) {func_021E4068(p);func_02049B40(23,5,4,448,32,((TradeWork *)p)->f5F4);func_021DF904(p);if(((TradeWork *)p)->f118C<4)func_021E58A0(p);func_021E467C(p);func_021E3F74(p);func_021E3E80(p);func_021E4420(p);func_021E4E64(((TradeWork *)p)->f828,p,0);}










void func_021DC500(int a, char *p)
{
    CLACT_VBlankSystem();
    if (((TradeWork *)p)->f1084) {
        func_02040618(7, 0, ((TradeWork *)p)->f108C);
        func_02040618(5, 0, ((TradeWork *)p)->f108C);
        ((TradeWork *)p)->f1084 = 0;
    }
}










void func_021DC538(char *p,void *q,u16 r) {unsigned i;for(i=0;i<3;i++)*(int *)(p+0x1064+i*4)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0xfde);if(q){((TradeWork *)p)->f82C=q;((TradeWork *)p)->f828=func_0201293C(q);((TradeWork *)p)->f830=func_02012944(q);((TradeWork *)p)->f838=func_02012934(q);if(((TradeWork *)p)->f834==0){if(func_021D8A24(p)){((TradeWork *)p)->f834=func_02012950(q,1-GFL_NET_SYSTEM_GetCurrentAid());return;}((TradeWork *)p)->f834=func_02012950(q,1);}}}










void func_021DC5D0(char *p, int a1)
{
    unsigned i;
    for (i = 0; i < 3; i++)
        func_020307B0((void *)(*(int *)(p + i * 4 + 0x1064)));
}










void func_021DC5F0(char *p)
{
    int v = func_020076A4((void *)(((TradeWork *)p)->f828));
    ((TradeWork *)p)->f634 = v * 6 + 2;
    ((TradeWork *)p)->f630 = v;
    ((TradeWork *)p)->f638 = v * 0x14 + 0xC;
    ((TradeWork *)p)->f63C = v * 0xA0 + 0x60;
}










/*
 * lever: output pointer declared before scalar locals; counter zero before base assignment.
 * arithmetic: signed n guard/callee argument; unsigned base/index preserve low-word MUL/ADD wrapping at 021DC6A6/021DC6A8/021DC6B2.
 */
void func_021DC62C(char *p,int n)
{
    Record *out=(Record *)(p+0x11fc);
    int i,mon,v;
    unsigned index,base;
    if(n==0) {
        MI_CpuFill8(out,0,0xb58);
        for(i=0;i<6;i++) {
            mon=(int)func_021D8DD0((void *)(((TradeWork *)p)->f828),((TradeWork *)p)->f630,i,p);
            if(mon && func_02017E88((void *)mon,0xa9,0)) {
                v=func_02017E88((void *)mon,0xab,0);
                if(v) {
                    out[i].value=v;
                    out[i].a=func_02017E88((void *)mon,0x6f,0);
                    out[i].b=func_02017E88((void *)mon,0x6e,0);
                }
            }
        }
    }
    while(n<24) {
        i=0;
        base=(unsigned)n*30u+6u;
        for(;i<30;i++) {
            index=(unsigned)i+base;
            mon=(int)func_021D8DD0((void *)(((TradeWork *)p)->f828),n,i,p);
            if(mon && func_02017E88((void *)mon,0xa9,0)) {
                v=func_02017E88((void *)mon,0xab,0);
                if(v) {
                    out[index].value=v;
                    out[index].a=func_02017E88((void *)mon,0x6f,0);
                    out[index].b=func_02017E88((void *)mon,0x6e,0);
                }
            }
        }
        return;
    }
}










/*
 * volatile: 021DC726 reads hardware DISPCNT 0x04001000 before updating it.
 */
void func_021DC720(char *p)
{
    int i;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_021E64B8(p);func_021E3230(p);func_021DD588(p);func_021DF8E0(p);func_021DD9DC((unsigned char *)p);func_021E4570(p);
    func_021E36D8(p,1);func_021E69A4(p);func_021DF7D0(p);func_021E2680(p);func_021E4888(p);
    func_021E2438(p,0);func_021E2438(p,1);
    if(P(0x9c0)) {TOUCHBAR_Delete(P(0x9c0));P(0x9c0)=0;}
    func_021E48E0(p);
    if(P(0x9c4)) {CLACT_DeleteUnit(P(0x9c4));P(0x9c4)=0;}
    func_021E11A8(p);func_021DD174(p);
    func_021E293C(p,0);func_021E293C(p,1);func_021E3F08(p);func_021E4000(p);func_021E57A4((int)p);
    if(P(0x818)) {func_020307B0(P(0x818));P(0x818)=0;}
    for(i=0;i<4;i++) {
        char *q=p+i*4;
        if(((TradeWork *)q)->f85C) {func_020307B0(((TradeWork *)q)->f85C);((TradeWork *)q)->f85C=0;}
    }
}










void func_021DC818(char *p)
{
    switch (((TradeWork *)p)->f11F8) {
    case 0:
        break;
    case 2:
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPlayerParam(0);
    case 1:
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPlayerParam(0);
        GFL_USE_FadeInBgmFull(30);
    }
    ((TradeWork *)p)->f11F8 = 0;
}










void *func_021DC854(void *a,int t) {
 void *p;
 GFL_HEAP_RegisterBlockHeap(d_021E8560,0xc000,0x91);
 GFL_HEAP_CreateChildHeap(1,31,t);
 p=PROCSYS_AllocProcWork(a,0x1d54,0x91);
 MI_CpuFill8(p,0,0x1d54);
 return p;
}










int func_021DC894(void *a,int b,char *q,char *p,int n)
{
    if(n<5) {func_02034AC4((int)ov067_id);func_02034AC4((int)ov114_id);}
    if(n==0 || n==4) func_02034AC4((int)ov117_id);
    else func_02034AC4((int)ov118_id);
    func_0204363C(1);
    H(0x5f4)=31;
    I(0x118c)=n;
    ((TradeWork *)p)->f8=q;
    I(0x5dc)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0x110b);
    I(0x5e0)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0x110c);
    I(0x10a4)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110d);
    I(0x10a8)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110e);
    ((TradeWork *)p)->f11F6=func_0200CA38(func_0200CA1C(((struct Obj04478 *)q)->f14));
    if(q) func_021DC538(p,((struct Obj04478 *)q)->f14,((struct Obj04478 *)q)->f2E);
    func_021DC5F0(p);func_021DC3EC(p);func_021DC458(p);
    I(0x9c4)=(int)CLACT_CreateUnit(0x154,0,H(0x5f4));
    if(func_021D8A24(p)) {
        GFL_NET_COMMAND_AddCommandTable(0xc00,(unsigned)d_021E7614,24,(unsigned)p);
        GFL_NET_SetAutoExit(1);GFL_NET_SetLoginOption(1);
    }
    I(0x9c8)=(int)func_020056A0((void (*)(void *, void *))func_021DC500,p,0);
    I(0xf60)=0;
    I(0xf84)=-1;I(0x109c)=-1;I(0xf7c)=-1;I(0xf80)=-1;I(0xf98)=-1;I(0xf94)=-1;
    func_021E30EC(p);
    if(((struct Obj04478 *)q)->f8==1) {
        BG_SYS_SetMainVisiblePlanes(16);func_021D8E84(p,(int)func_021E0B34);((struct Obj04478 *)q)->f8=0;return 1;
    }
    func_021E10D8(p);func_021E3FE4(p);
    if(I(0x118c)<4) {func_021DC494(p);func_021E3C20(p);GFL_NET_RestartWithDefaultTimeout(1,H(0x5f4));}
    func_021E3208(p,0);BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);func_021D8E84(p,(int)func_021DAC60);
    return 1;
}











/*
 * Send a two-descriptor request with the timer base 0xc6000.
 */
void func_021DCA84(void *a, int b, int c)
{
    int r = (int)func_021DC854(a, 0xc6000);

    func_021DC894(a, b, (char *)c, (char *)r, 2);
}










/*
 * Send a one-descriptor request with the timer base 0xc6000.
 */
void func_021DCAAC(void *a, int b, int c)
{
    int r = (int)func_021DC854(a, 0xc6000);

    func_021DC894(a, b, (char *)c, (char *)r, 0);
}












void func_021DCAD4(void *a,int b,char *c) {char *p=func_021DC854(a,0xc6000);int i; for(i=0;i<2;i++) {char *d=p+i*4;((TradeWork *)d)->f1048=0;((TradeWork *)d)->f1050=1;} ((TradeWork *)p)->f834=func_02012950((void *)*(int *)&((struct Obj04478 *)c)->f14,1-GFL_NET_SYSTEM_GetCurrentAid());func_021DC894(a,b,c,p,1);}













void func_021DCB30(void *a,int b,char *c) {const char *q=*(char * *)&((struct Obj04478 *)c)->f18;char *p=func_021DC854(a,0xc6000);if(q) {if(((struct Obj22735 *)q)->f1B0==2) {int i;for(i=0;i<2;i++) {const int *s=(const int *)(q+i*8);char *d=p+i*4;((TradeWork *)d)->f1048=s[2];((TradeWork *)d)->f1050=s[1];}} else {int j;for(j=0;j<2;j++){char *d=p+j*4;((TradeWork *)d)->f1048=-1;((TradeWork *)d)->f1050=-1;}}}func_021DC894(a,b,c,p,3);}













void func_021DCBA4(char *a, char *p)
{
    func_02082D44(((struct Obj01728 *)a)->f34,((TradeWork *)p)->f5DC,func_020173EC());
    func_02082D44(((struct Obj01728 *)a)->f38,((TradeWork *)p)->f5E0,func_020173EC());
    func_021E36C8(p,0,1,((struct Obj01728 *)a)->f34,1);
    func_021E36C8(p,1,1,((struct Obj01728 *)a)->f38,1);
    MCSS_SetVanishFlag((void *)(*(unsigned *)(p+(func_021D8AA8(p) == 0 ? 0x848 : 0x844))));
    ((TradeWork *)p)->f830=((struct Obj01728 *)a)->f3C;
    ((TradeWork *)p)->f834=((struct Obj01728 *)a)->f40;
    GFL_NET_RestartWithDefaultTimeout(0,((TradeWork *)p)->f5F4);
    FADE_Start(3,16,0,2);
}












int func_021DCC38(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0xc6000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((void *)((int)a), b, c, p, 4);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D4B88);
    return r;
}












int func_021DCC78(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((void *)((int)a), b, c, p, 7);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D59B0);
    return r;
}












int func_021DCCB8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((void *)((int)a), b, c, p, 8);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D6F2C);
    return r;
}












int func_021DCCF8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((void *)((int)a), b, c, p, 6);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D4AB4);
    return r;
}











int func_021DCD38(int a,int b,int c,char *p)
{
    int result=1;
    void (*callback)(char *)=*(void (**)(char *))(p+0x5ec);
    int i;
    u8 rgb[3];
    if(BEACON_STATUS_IsLocked()) return 0;
    if(callback) {
        callback(p);
        I(0xf2c)++;
        result=0;
        for(i=0;i<2;i++) func_021DD90C((u8 *)p,i,*(u8 *)(p+i+0x11e8),0);
    }
    if(I(0xf9c) && B(0x11f3)==0) {
        func_021D9468(p,1,*(void **)(p+(I(0xf9c)-1)*4+0x5dc));I(0xf9c)=0;
    }
    func_021D8A50(p);func_021DF868(p);CLACT_DrawSystem();
    if(P(0x64c)) APP_TASKMENU_UpdateMenu(P(0x64c));
    if(P(0x648)) APP_TASKMENU_WIN_Update(P(0x648));
    if(((Bits *)(p+0x11fb))->high) {
        if(GFL_NET_SendToHandle((struct Entry *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),0xc17,0,0)) ((Bits *)(p+0x11fb))->high=0;
    }
    if(P(0x744)) {
        GF_FONT_GetTextColor(&rgb[2],&rgb[1],&rgb[0]);
        GF_FONT_SetTextColor(1,2,15);
        TCBL_Main(P(0x744));
        GF_FONT_SetTextColor(rgb[2],rgb[1],rgb[0]);
        PRINTSYS_QUE_Main(P(0x740));
    }
    func_021DF978(p);func_02047964();func_02048AD0(P(0x810));G3D_SYSTEM_ApplyLookAt();
    MCSS_Main(P(0x840));MCSS_Draw(P(0x840));func_021E31B4(p);G3D_SYSTEM_DrawEnd();
    if(func_021D8A24(p) && I(0xef8)==0 && func_0200FB24()) {
        if(B(0x11f7)) func_0200F7C0(41);
        if(P(0)) {
            func_021B9774(P(0));func_021B9838(P(0));P(0)=0;
            DWC_RAP_SetErrorCallback(0,0);DWC_RAPCOMMON_DestroySubHeap();
        }
        if(GFL_NET_IsNetTypeWifi()) DWC_RAPCOMMON_HandleNetError(1,1);
        else if(I(0x118c)!=1) GFL_NET_ERR_RequestScreen();
        *(int *)((char *)P(8)+8)=2;
        func_021DC818(p);
        result=1;
        WIPE_SetBrightnessFadeOut(0,0);WIPE_SetBrightnessFadeOut(1,0);
    }
    return result;
}











int func_021DCF24(void *owner,int unused,int keep,char *p)
{
    int state=((TradeWork *)p)->f118C;
    if(WIPE_SYS_EndCheck()==0)return 0;
    func_020307B0(((TradeWork *)p)->f10A4);
    func_020307B0(((TradeWork *)p)->f10A8);
    func_021E5EF8(p+0x950);func_021E5EF8(p+0x964);func_021E5EF8(p+0x978);
    func_021E5D84(p);func_021DC720(p);BEACON_STATUS_DoNothing();
    if(func_021D8A24(p))GFL_NET_COMMAND_DeleteCommandTable(0xc00);
    func_021E31BC(p);
    func_020307B0(((TradeWork *)p)->f5DC);func_020307B0(((TradeWork *)p)->f5E0);
    func_02030EAC(((TradeWork *)p)->f9C8);
    func_021DC5D0(p,keep!=0);
    func_021DC428(p);func_021DC484(p);func_020315D4(owner);
    func_020306F0(31);func_020306F0(145);
    if(state<5) {func_02034A5C((int)d_00000072);func_02034A5C((int)d_00000043);}
    func_02034A5C(state==0 || state==4 ?(int)d_00000075:(int)d_00000076);
    return 1;
}











void func_021DD018(char *p, int flag)
{
    int n;
    if (flag) {
        n = func_021E4DBC(p) + 2;
        if (n >= ((TradeWork *)p)->f634) n -= ((TradeWork *)p)->f634;
        if (((TradeWork *)p)->f107C == d_021E7FE0[0]) n = 2;
        else if (((TradeWork *)p)->f107C == d_021E7FE0[((TradeWork *)p)->f630]) {
            n = 0;
            if (((TradeWork *)p)->fF78 >= 3) ((TradeWork *)p)->fF78 = 2;
        }
        ((TradeWork *)p)->fF74 = n;
        ((TradeWork *)p)->f1080 = -1;
    }
}











void func_021DD080(void *a, void *b, void *c)
{
    if (func_021D8A24(c))
        GFL_NET_HANDLE_SetTimingSyncRange(a, (unsigned int)b, 8);
}











void func_021DD09C(char *p)
{
    if (func_020355C4()) {
        func_021E68F4((int)p, -1);
        return;
    }
    {
        int v = ((TradeWork *)p)->f10A0;
        if (v != -1)
            func_021E68F4((int)p, v);
    }
}











int func_021DD0CC(char *p, int a)
{
    int v, lock, r;
    unsigned i;
    v = func_02017E88((void *)a,5,0);
    i = 0;
    if (((TradeWork *)p)->f118C == 3) {
        lock = func_02017DBC((struct Sav *)a);
        for (; i < 15; i++) {
            r = func_02017E88((void *)a,d_021E7718[i],0);
            if (r == 1) break;
        }
        func_02017DE4((struct Sav *)a,lock);
        if (r) return 1;
        if (POKE_REGULATION_IsInSpeciesTable(v)) return 1;
    }
    return 0;
}











int func_021DD140(char *p)
{
    if (((TradeWork *)p)->f11F1) {
        if (func_021D8ADC(p))
            ((TradeWork *)p)->f11F1 = ((TradeWork *)p)->f11F1 - 1;
        else
            ((TradeWork *)p)->f11F1 = 0;
    }
    return ((TradeWork *)p)->f11F1 == 0;
}











void func_021DD174(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            if (((TradeWork *)q)->fFD8) {
                func_020307B0(((TradeWork *)q)->fFD8);
                ((TradeWork *)q)->fFD8 = 0;
            }
        }
    }
}











void func_021DD1B8(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            ((TradeWork *)q)->fFA4 = -1;
            ((TradeWork *)q)->fFBC = -1;
            if (((TradeWork *)q)->fFD8) MI_CpuFill8(((TradeWork *)q)->fFD8, 0, func_020173EC());
        }
    }
}











int func_021DD21C(char *p)
{
    int i, n = 0;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 4 + 0xFA4) != -1 && *(int *)(p + i * 4 + 0xFBC) != -1)
            n++;
    }
    return n;
}











int func_021DD24C(char *p)
{
    if (((TradeWork *)p)->f118C == 3) {
        if (*(int *)&((TradeWork *)p)->f648 == 0) func_021E2984(p, 0x9a);
        if (func_021E2A80(p)) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return 1;
        }
    }
    return 0;
}











void func_021DD294(char *p, int a, int b)
{
    if (((TradeWork *)p)->f118C == 3)
        func_021E2A1C(p, a, b);
}











int func_021DD2A8(char *p)
{
    int a, b, n;
    a = func_0201293C((const struct BigObj *)(*(int *)&((TradeWork *)p)->f82C));
    b = func_021DD21C(p);
    n = POKEPARTY_GetCount(func_02012934(((TradeWork *)p)->f82C));
    n += func_02007984((void *)a);
    if (n == 2 && b >= 1) return 1;
    if (n > 2 && b >= 2) return 1;
    return 0;
}











int func_021DD2F4(char *p)
{
    int i;
    if (func_021D8AA8(p)) {
        for (i = 0; i < 3; i++) {
            if (*(int *)(p + i * 4 + 0xfa4) != -1 && *(int *)(p + i * 4 + 0xfbc) != -1) return 1;
        }
    } else {
        if (((TradeWork *)p)->fF84 != -1 && ((TradeWork *)p)->fF88 != -1) return 1;
    }
    return 0;
}











int func_021DD34C(char *p, int a, int b)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (b == *(int *)(p + i * 4 + 0xFA4) && a == *(int *)(p + i * 4 + 0xFBC))
            return i;
    }
    return -1;
}











void func_021DD380(char *p,int i,void *src)
{
    *(int *)(p+0xfb0+i*4)=i; *(int *)(p+0xfc8+i*4)=i; if(*(void **)(p+0xfe4+i*4)==0) *(void **)(p+0xfe4+i*4)=func_02030734(((TradeWork *)p)->f5F4,func_020173EC(),1,(void *)d_021E80E0,0x122);func_02082D44(src,*(void **)(p+0xfe4+i*4),func_020173EC());
}











/*
 * lever: Spell the indexed object base at each field read; a cached q local
 * swaps the first-loop counter and pooled-offset registers (10 bytes).
 */
int func_021DD3D4(const char *p, int n, int a, int b)
{
    int j;
    long i;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + n * 12 + 0xfa4 + i * 4) == a &&
            *(int *)(p + n * 12 + 0xfbc + i * 4) == b)
            return -1;
    }
    for (j = 0; j < 3; j++) {
        if (*(int *)(p + n * 12 + 0xfa4 + j * 4) == -1)
            return j;
    }
    return 2;
}











/*
 * lever: Separate two-by-three struct fields recompute the side offset;
 * raw combined offsets cached it in ip and produced 208 rather than 204 bytes.
 */
int func_021DD428(State_021DCAD4 *p,int side,int a,int b,void *value)
{
    int i;
    for(i=0;i<3;i++) {
        if(a==p->a[side][i] && b==p->b[side][i])
            return -1;
    }
    for(i=0;i<3;i++) {
        if(p->a[side][i]==-1 || i==2) {
            p->a[side][i]=a;
            p->b[side][i]=b;
            if(p->value[side][i]==0)
                p->value[side][i]=func_02030734(((TradeWork *)p)->f5F4,func_020173EC(),1,d_021E80E0,0x14c);
            func_02082D44(value,p->value[side][i],func_020173EC());
            func_021DF918(p,side,value);
            return i;
        }
    }
    return -1;
}











void func_021DD4F4(struct S119DD4F4 *p, int i, int j)
{
    p->a[i][j] = -1;
    p->b[i][j] = -1;
    if (p->c[i][j])
        func_020307B0((void *)p->c[i][j]);
    p->c[i][j] = 0;
}











void func_021DD528(char *p,int n)
{
    void *v;int off;int a;v=func_020490F4(7,((TradeWork *)p)->f5F4);off=96;if(n!=1)off=0;(*(int *)&((TradeWork *)p)->f890)=CLACT_RegisterPaletteCompressed(v,func_0201BC3C(),n,(u16)off,((TradeWork *)p)->f5F4);a=func_0201BC78();(*(int *)&((TradeWork *)p)->f8C0)=CLACT_RegisterCellAnim(v,a,func_0201BCB4(),((TradeWork *)p)->f5F4);ARC_TOOL_DeleteHandle(v);
}












void func_021DD588(char *p)
{
    if (((TradeWork *)p)->f890 != 0) {
        CLACT_ReleasePalette((u32_021DD588)(((TradeWork *)p)->f890));
        ((TradeWork *)p)->f890 = 0;
    }
    if (((TradeWork *)p)->f8C0 != 0) {
        CLACT_ReleaseCellAnim((u32_021DD588)(((TradeWork *)p)->f8C0));
        ((TradeWork *)p)->f8C0 = 0;
    }
}











int func_021DD5B4(char *p,int a,int b)
{
    int value,slot;
    unsigned i;
    GFL_NET_HANDLE_GetCurrentHandle();
    value=(int)func_021D8D4C(*(void ** *)&((TradeWork *)p)->f828,((TradeWork *)p)->fF88,((TradeWork *)p)->fF84,p);
    if(func_021D8A24(p)) {
        i=0;
        slot=func_021DD428((struct State_021DCAD4 *)p,0,a,b,(void *)value);
        if(slot!=-1) {
            if(func_021DF9E8(p,*(void **)(p+slot*4+0xfd8),slot+0xc07)==0) {
                func_021DD4F4((struct S119DD4F4 *)p,0,slot);
                func_020307B0((void *)value);
                return 0;
            }
            for(i=0;i<(unsigned)func_020173EC();i++) {}
        }
    } else {
        slot=func_021DD428((struct State_021DCAD4 *)p,0,a,b,(void *)value);
    }
    if(slot==-1) {func_020307B0((void *)value);return 1;}
    func_021E6334(p,0,slot,(void *)value,1,0);
    func_020307B0((void *)value);
    return 1;
}












void func_021DD68C(char *p)
{
    Pair_021DD68C t;
    Pair_021DD68C u;
    void *h;
    int q;
    void *h2;
    int i;
    int k;
    int m;
    int x;

    t = d_021E7704;
    u.a = ((TradeWork *)p)->f830;
    u.b = ((TradeWork *)p)->f834;
    func_02049B40(func_020275E4(), 0x1F, 0, 0x1A0, 0x20, ((TradeWork *)p)->f5F4);
    if ((*(void * *)&((TradeWork *)p)->f5D4) != 0) {
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->f5D4));
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->f5D8));
    }
    h = (void *)BMP_WIN_Create(3, 0, 0, 0x20, 2, 13, 0);
    (*(void * *)&((TradeWork *)p)->f5D4) = h;
    GF_FONT_SetTextColor(14, 15, 0);
    if (((TradeWork *)p)->f118C == 3 && ((TradeWork *)p)->f1050 != -1) {
        func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x85, (*(void * *)&((TradeWork *)p)->f730));
        PRINTSYS_Print(BMP_WIN_GetBmp(h), 8, 2, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
        func_02045CAC((*(void * *)&((TradeWork *)p)->f720), ((TradeWork *)p)->f1050 + 0x7B, (*(void * *)&((TradeWork *)p)->f730));
        PRINTSYS_Print(BMP_WIN_GetBmp(h), 0x88, 2, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
    }
    BMP_WIN_TransferChars(h);
    BMP_WIN_MakeScreen(h);
    i = 0;
    h2 = (void *)BMP_WIN_Create(3, 0, 3, 0x20, 8, 5, 0);
    (*(void * *)&((TradeWork *)p)->f5D8) = h2;
    for (i = 0; i < 2; i++) {
        k = i * 4;
        q = *(int *)((char *)&u + k);
        if (q != 0) {
            if (((TradeWork *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                m = 0x75;
            } else {
                m = 0x80;
            }
            GF_FONT_SetTextColor(1, 2, 0);
            func_02045CAC((*(void * *)&((TradeWork *)p)->f720), m, (*(void * *)&((TradeWork *)p)->f734));
            func_0201F02C((*(void * *)&((TradeWork *)p)->f724), 0, (void *)q);
            func_0201F250((*(void * *)&((TradeWork *)p)->f724), (*(void * *)&((TradeWork *)p)->f730), (*(void * *)&((TradeWork *)p)->f734));
            x = *(int *)((char *)&t + k) * 8;
            PRINTSYS_Print(BMP_WIN_GetBmp(h2), x, 2, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
            if (((TradeWork *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                GF_FONT_SetTextColor(3, 4, 0);
                func_02045CAC((*(void * *)&((TradeWork *)p)->f720), *(int *)(p + k + 0x1048) + 0x76, (*(void * *)&((TradeWork *)p)->f730));
                PRINTSYS_Print(BMP_WIN_GetBmp(h2), x + 4, 0x22, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
            }
        }
    }
    BMP_WIN_TransferChars(h2);
    BMP_WIN_MakeScreen(h2);
    func_02041B6C(3);
}











/*
 * 2026-10-02 lane R1: closed by storing the call result straight into items[i] and reading it back
 * (w=items[i]): the pointer local stays live across the call and the forwarded value is spilled.
 */
void func_021DD90C(u8 *p,int i,int msg,int force)
{
    Pair_021DD90C t=d_021E76FC;
    int w;
    int *items;
    if(force==0) {
        if((p+i)[0x11e8]==3) return;
        if(p[0x11ea]==0) return;
        if(func_021D8AA8(p)==0) return;
    }
    if(*(int *)(p+i*4+0x5bc)) BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5bc)));
    items=(int *)(p+0x5bc); items[i]=(int)BMP_WIN_Create(3,(u8)(((int *)&t)[i]),16,12,2,5,0); w=items[i];
    GF_FONT_SetTextColor(5,6,0);
    msg+=0x72;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),msg,(void *)(((TradeWork *)p)->f730));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)w),0,0,(void *)(((TradeWork *)p)->f730),(void *)(*(int *)&((TradeWork *)p)->f728));
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_02041B6C(3);
    (p+i)[0x11e8]=3;
}












void func_021DD9DC(unsigned char *p)
{
    if(((TradeWork *)p)->f5BC){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5BC));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5BC));((TradeWork *)p)->f5BC=0;}if(((TradeWork *)p)->f5C0){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5C0));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5C0));((TradeWork *)p)->f5C0=0;}if(((TradeWork *)p)->f5D4){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5D4));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5D4));((TradeWork *)p)->f5D4=0;}if(((TradeWork *)p)->f5D8){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5D8));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5D8));((TradeWork *)p)->f5D8=0;}func_02041B6C(3);
}












void func_021DDA50(void *p)
{
    int v;

    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C)) == 0)
        return;
    v = APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    ((TradeWork *)p)->f64C = 0;
    switch (v) {
    case 0:
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, ((TradeWork *)p)->f5F4);
        func_021D8E84(p, 0x021DE519);
        return;
    case 1:
        func_021D8980(p);
        func_021DEBD4(p);
        func_021DD09C(p);
        func_021D8E84(p, 0x021DEA25);
        return;
    }
}











void func_021DDAD4(char *p)
{
    Pair_021DDAD4 t=d_021E76F4;
    func_021E1410(p,(int *)(&t),2);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
    func_021D8E84(p,(int)func_021DDA50);
}












void func_021DDB10(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle(); if(func_021D8A24(p)) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {func_021DD24C((char *)p);return;} } func_021E1098((char *)p);func_021DD294((char *)p,0,0);func_021D8980((char *)p);func_021DD09C((char *)p);func_021D8E84(p,(int)func_021DEA24);
}












void func_021DDB64(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(func_021E12AC((char *)p)) {
        func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)25,p);
        func_021D8E84(p,(int)func_021DDB10);
    }
}











void func_021DDB90(unsigned char *p)
{
    int v;GFL_NET_HANDLE_GetCurrentHandle();if(func_021E12AC((char *)p)){v=KEY_GetTrg();if(v)func_020355D8(0);if(v==0){v=TOUCHPANEL_GetTrg();if(v)func_020355D8(1);if(v==0)return;}func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),0x88,(void *)(((TradeWork *)p)->f738));func_021E1024(p);func_021E1030((char *)p);func_021D8E84(p,(int)func_021DDB64);}
}











void func_021DDBF0(char *p)
{
    int a, b, c, d, m;
    a = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    b = 1 - a;
    if (func_021E12AC(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (func_021D8A24(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1D, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    func_021DD294(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 13 && (unsigned char)(p + b)[0x11E0] == 13) {
        func_021DD080((void *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), (void *)13, p);
        func_021D8E84(p, (int)func_021DA76C);
        return;
    }
    d = (unsigned char)(p + b)[0x11E0];
    if (d == 5) m = 0x61;
    else if (c == 5) m = 0x62;
    else if (d == 7) m = 0x63;
    else if (c == 7) m = 0x64;
    else if (d == 8) m = 0x64;
    else if (c == 8) m = 0x63;
    else if (d == 6) m = 0x61;
    else if (c == 6) m = 0x6F;
    else if (d == 14) m = 0x97;
    else if (c == 14) m = 0x96;
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), m, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    func_021D8E84(p, (int)func_021DDB90);
}










void func_021DDCF0(unsigned char *p)
{
    unsigned char b=13;if(func_021D94D4((char *)p))b=5;else if(func_021D95D0(p))b=7;else if(func_021D95F0(p))b=8;else if(func_021D9610(p))b=6;if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&b)){func_021DD080(GFL_NET_HANDLE_GetCurrentHandle(),(void *)29,p);func_021D8E84(p,(int)func_021DDBF0);}
}











void func_021DDD60(unsigned char *p)
{
    if(func_021D8A24(p)==0){p[0x11e0]=13;p[0x11e1]=13;func_021D8E84(p,(int)func_021DDBF0);return;} if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),30,8)==0){func_021DD24C((char *)p);return;}func_021DD294((char *)p,0,0);func_021D8E84(p,(int)func_021DDCF0);
}











void func_021DDDB8(unsigned char *p)
{
    unsigned char v=14;
    if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&v)) {
        func_021DD080(GFL_NET_HANDLE_GetCurrentHandle(),(void *)29,p);
        func_021D8E84(p,(int)func_021DDBF0);
    }
}











void func_021DDDF4(unsigned char *p)
{
    if(func_021D8A24(p)==0){p[0x11e0]=14;p[0x11e1]=14;func_021D8E84(p,(int)func_021DDBF0);return;} if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),30,8)==0){func_021DD24C((char *)p);return;}func_021DD294((char *)p,0,0);func_021D8E84(p,(int)func_021DDDB8);
}











void func_021DDE4C(unsigned char *p)
{
    func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)30,p); func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),0x88,(void *)(((TradeWork *)p)->f738)); func_021E1024(p); func_021E1030((char *)p); p[0x11f1]=120; func_021D8E84(p,(int)func_021DDD60);
}











void func_021DDE90(unsigned char *p)
{
    func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)30,p); func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),0x88,(void *)(((TradeWork *)p)->f738)); func_021E1024(p); func_021E1030((char *)p); p[0x11f1]=120; func_021D8E84(p,(int)func_021DDDF4);
}











void func_021DDED4(unsigned char *p)
{
    int v; if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))==0)return;v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));func_021E12F8((char *)p);func_021E1098((char *)p);((TradeWork *)p)->f64C=0;switch(v){case 0:func_021D8E84(p,(int)func_021DDE4C);return;case 1:func_021D8E84(p,(int)func_021DDE90);return;}
}










void func_021DDF28(char *p)
{
    if(func_021E12AC(p)) {
        Pair_021DC2B0 t=d_021E76E4;
        func_021E1410(p,(int *)(&t),2);
        BG_SYS_SetMainVisiblePlanes(31);
        func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
        func_021D8E84(p,(int)func_021DDED4);
    }
}











void func_021DDF74(char *p)
{
    int a, b, c, i, m;
    a = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    b = 1 - a;
    if (func_021E12AC(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (func_021D8A24(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    i = 0;
    func_021DD294(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 11 && (unsigned char)(p + b)[0x11E0] == 11) {
        func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x92, ((TradeWork *)p)->f73C);
        do {
            func_0201EEF4((*(void * *)&((TradeWork *)p)->f724), i, func_021D8FA4(p, i));
            i++;
        } while (i < 2);
        func_0201F250((*(void * *)&((TradeWork *)p)->f724), (*(void * *)&((TradeWork *)p)->f738), ((TradeWork *)p)->f73C);
        func_021E1024(p);
        func_021D8E84(p, (int)func_021DDF28);
        return;
    }
    if ((unsigned char)(p + b)[0x11E0] == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x93;
        if (((TradeWork *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return;
        }
    } else if (c == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x95;
        if (((TradeWork *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return;
        }
    }
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), m, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    if (func_021D8A24(p) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 8);
    }
    ((TradeWork *)p)->fF2C = 0;
    func_021D8E84(p, (int)func_021DE8C0);
}











void func_021DE0F0(void *p)
{
    u8 cmd;
    cmd = 0xB;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xC00, 1, &cmd) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8);
        func_021D8E84(p, (int)func_021DDF74);
    }
}










void func_021DE12C(char *p)
{
    void *obj;
    int n;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),0x88,(void *)(((TradeWork *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    p[0x11f1]=120;
    if(func_021D8A24(p)==0) {
        p[0x11e0]=11;
        p[0x11e1]=11;
        obj=((TradeWork *)p)->fFD8;
        func_021D9468(p,1,obj);
        n=func_020173EC();
        func_02082D44(obj,func_021D8FA4(p,1),n);
        func_021D8E84(p,(int)func_021DDF74);
        return;
    }
    func_021D8E84(p,(int)func_021DE0F0);
}










void func_021DE1B4(State_021DDB90 *p,int index)
{
    int col=index%3;
    int row=index/3;
    int other=1-row;
    void *obj=p->obj[other][col];
    if(func_021D89EC(obj)) {
        func_021E219C((char *)p,obj,other,1);
        func_021E6440((int)p,row,col);
    }
}















int func_021DE208(char *p)
{
    int changed=0;
    int v;
    if(poll()==16) { ((TradeWork *)p)->f10A0=(((TradeWork *)p)->f10A0+3)%6; changed=1; }
    if(poll()==32) {
        ((TradeWork *)p)->f10A0=(((TradeWork *)p)->f10A0-3)%6;
        if(((TradeWork *)p)->f10A0<0) ((TradeWork *)p)->f10A0+=6;
        changed=1;
    }
    if(poll()==64) {
        v=((TradeWork *)p)->f10A0;
        if(v==0 || v==3) ((TradeWork *)p)->f10A0+=3;
        ((TradeWork *)p)->f10A0-=1; changed=1;
    }
    if(poll()==128) {
        v=((TradeWork *)p)->f10A0;
        if(v==2 || v==5) ((TradeWork *)p)->f10A0-=3;
        ((TradeWork *)p)->f10A0+=1; changed=1;
    }
    return changed;
}









void func_021DE2C4(char *p)
{
    void *resource;
    int zero,slot;
    void *mon;
    if(WIPE_SYS_EndCheck()) {
        zero=0;
        func_02040588(3,zero);
        func_021E6440((int)p,-1,-1);
        func_021E1CE8(p,0);
        resource=func_020490F4(102,((TradeWork *)p)->f5F4);
        func_02049990(resource,11,2,0,(u16)((TradeWork *)p)->f86C,zero,zero,((TradeWork *)p)->f5F4);
        ARC_TOOL_DeleteHandle(resource);
        func_021E3208(p,0);
        func_02041B6C(3);
        p[0x11f3]=zero;
        slot=1;
        if(func_021D89EC(func_021D8FA4(p,slot))) {
            mon=func_021D8FA4(p,slot);
            func_021D9468(p,slot,mon);
        }
        slot=0;
        if(func_021D89EC(func_021D8FA4(p,slot))) {
            mon=func_021D8FA4(p,slot);
            func_021D9468(p,slot,mon);
        }
        func_021DEBD4(p);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DEA24);
        func_021D8980(p);
        WIPE_SYS_Start((void *)3,1,1,0,6,1,((TradeWork *)p)->f5F4);
    }
}










void func_021DE3BC(char *p)
{
    int lim;
    lim = 3;
    if (GFL_NET_IsNetTypeWifi() != 0) {
        lim = 10;
    }
    if (((TradeWork *)p)->fF2C > lim) {
        func_021D8E84(p, (int)func_021DE3E8);
    }
}












/*
 * prototype: 02035C08 return is consumed in r0; full 02035BBC forwarding body returns int, as in matched 021D98AC.
 */
void func_021DE3E8(char *p)
{
    int idx;
    func_02040588(3,1);
    if(WIPE_SYS_EndCheck()) {
        TOUCHBAR_Update(*(S * *)&((TradeWork *)p)->f9C0);
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->f9C0)==1) {
            WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->f5F4);
            func_021D8E84(p,(int)func_021DE2C4);
            return;
        }
        if(TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((TradeWork *)p)->f9C0)==-1) {
            idx=TOUCHPANEL_HitTrg(d_021E80C4);
            if(idx!=-1) {
                func_020355D8(1);
                ((TradeWork *)p)->f10A0=idx;
                func_021E68F4((int)p,-1);
                func_021DE1B4((State_021DDB90 *)p,((TradeWork *)p)->f10A0);
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((TradeWork *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_020355C4() && poll()) {
                func_020355D8(0);
                func_021E68F4((int)p,((TradeWork *)p)->f10A0);
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((TradeWork *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_021DE208(p)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                func_021E68F4((int)p,((TradeWork *)p)->f10A0);
                func_021DE1B4((State_021DDB90 *)p,((TradeWork *)p)->f10A0);
                ((TradeWork *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
            }
        }
    }
}








void func_021DE518(State_021DE518 *p)
{
    char *b=(char *)p;
    u16 idx;
    int col,row;
    void *obj;
    int other;
    if(WIPE_SYS_EndCheck()) {
        idx=(u16)((TradeWork *)b)->f10A0;
        col=idx%3; row=idx/3;
        other=1-row;
        obj=p->obj[other][col];
        b[0x11f3]=1;
        if(obj && func_02017E1C(obj,169,0)) {
            func_021E1D68((char *)p,obj); func_021E6440((int)p,row,col);
        }
        func_021DEBD4(p);
        WIPE_SYS_Start((void *)3,1,1,0,6,1,((TradeWork *)b)->f5F4);
        func_021D8980((char *)p); func_021DD09C((char *)p);
        func_021D8E84(p,(int)func_021DE3E8);
    }
}








void func_021DE5C4(char *p)
{
    int v;
    if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))) {
        v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));
        func_021E12F8(p); func_021E1098(p);
        ((TradeWork *)p)->f64C=0;
        switch(v) {
        case 0: func_021D8E84(p,(int)func_021DE12C); return;
        case 1:
            WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->f5F4);
            TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
            func_021D8E84(p,(int)func_021DE518); return;
        case 2:
            func_021DEBD4(p); func_021D8980(p); func_021DD09C(p);
            func_021D8E84(p,(int)func_021DEA24); return;
        }
    }
}








void func_021DE66C(char *p)
{
    Triple_021DBB6C t=d_021E770C;
    func_021E1410(p,(int *)(&t),3);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
    func_021D8E84(p,(int)func_021DE5C4);
}








void func_021DE6AC(char *p)
{
    unsigned id;
    if(((Flags *)p)->state==1) return;
    if(func_021D8A24(p)!=0) {
        id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
        if(!GFL_NET_SendToHandle((void *)id,(u16)0xc01,(u16)func_020173EC(),(void *)(((TradeWork *)p)->f106C))) return;
    }
    p[0x11fb]=((u8)p[0x11fb]&~15)|1;
    func_021D8E84(p,(int)func_021DE66C);
}









void func_021DE70C(void *p)
{
    u8 v;
    if (func_021D8A24(p) != 0) {
        v = func_021D8F20(p, 0);
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)0xC16, (u16)func_020173EC(), &v) == 0) {
            return;
        }
    }
    func_021D8E84(p, (int)func_021DE6AC);
}








/*
 * lever: Shared failure label; padded two-dimensional array members reproduce index scheduling.
 */
int func_021DE754(char *p,int idx)
{
    int row,col,entry;
    void *mon;
    int value;
    State *s=(State *)p;
    row=idx/3;
    col=idx%3;
    if(idx==-1) goto fail;
    entry=s->entry[1-row][col];
    if(entry==-1) goto fail;
    mon=s->mon[1-row][col];
    value=s->value[1-row][col];
    if(mon==0 || func_02017E1C(mon,169,0)==0) goto fail;
    ((TradeWork *)p)->f10A0=idx;
    GFL_USE_PlaySeDefaultVolume(0x54c);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
    if(row!=0) {
        func_021D8E84(p,(int)func_021DDAD4);
    } else {
        func_021D9468(p,row,mon);
        func_02082D44(mon,((TradeWork *)p)->f106C,func_020173EC());
        func_021D8F60(p,0,value);
        func_021D8E84(p,(int)func_021DE70C);
    }
    return 1;
fail:
    return 0;
}








/*
 * volatile: 0x021DE89A reads 0x04001000 before the store at 0x021DE89E.
 */
void func_021DE820(char *p)
{
    if(WIPE_SYS_EndCheck()) {
        func_021DC720(p); func_021E57E8(0); func_021E5680(p);
        (*(void * *)&((TradeWork *)p)->f9C4)=CLACT_CreateUnit(0x154,0,((TradeWork *)p)->f5F4);
        func_021E10D8(p); func_021E58A0(p); func_021E467C(p);
        func_021E3E80(p); func_021E3FE4(p); func_021E3F74(p);
        func_021E3208(p,0); BG_SYS_SetMainVisiblePlanes(31); BG_SYS_SetSubVisiblePlanes(30);
        func_021E3C20(p); GFL_NET_RestartWithDefaultTimeout(0,((TradeWork *)p)->f5F4);
        *(volatile unsigned *)0x04001000 &= 0xffff1fff;
        func_021D8E84(p,(int)func_021DACE4);
    }
}








void func_021DE8C0(char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(func_021E12AC(p) && func_021DD140(p) && ((TradeWork *)p)->fF2C>=120) {
        WIPE_SYS_Start(0,0,0,0,6,1,((TradeWork *)p)->f5F4);
        func_021D8E84(p,(int)func_021DE820);
    }
}









void func_021DE918(void *p)
{
    u8 cmd;
    cmd = 0xC;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xC00, 1, &cmd) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8);
        func_021D8E84(p, (int)func_021DDF74);
    }
}









void func_021DE950(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x88, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    *(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DE918);
}








void func_021DE988(char *p)
{
    int v;
    if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))) {
        v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));
        func_021E12F8(p);
        func_021E1098(p);
        ((TradeWork *)p)->f64C=0;
        if(v==0) {
            func_021D8E84(p,(int)func_021DE950);
            return;
        }
        func_021E1098(p);
        func_021D8980(p);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DEA24);
    }
}









void func_021DE9E8(void *p)
{
    Pair_021DE3E8 t;
    if (func_021E12AC(p) != 0) {
        t = d_021E76DC;
        func_021E131C(p, (int *)&t, 2, 0x20, 12);
        func_021D8E84(p, (int)func_021DE988);
    }
}
