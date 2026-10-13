/*
 * file:     pokemontrade_3d.c
 * unit:     yes
 * function: func_021DEA24, func_021DEB34, func_021DEBA0, func_021DEBD4, func_021DEC4C, func_021DECA0, func_021DED58, func_021DED74, func_021DEDBC, func_021DEE00, func_021DEEA8, func_021DEEFC, func_021DEF1C, func_021DF0B8, func_021DF168, func_021DF1C8, func_021DF210, func_021DF338, func_021DF37C, func_021DF3E4, func_021DF404, func_021DF43C, func_021DF490, func_021DF4CC, func_021DF510, func_021DF548, func_021DF59C, func_021DF5D8, func_021DF614, func_021DF6B4, func_021DF6EC, func_021DF708, func_021DF78C, func_021DF7AC, func_021DF7D0, func_021DF7F0, func_021DF868, func_021DF8A0, func_021DF8E0, func_021DF904, func_021DF918, func_021DF978, func_021DF9E8, func_021DFA60, func_021DFA98, func_021DFAD0, func_021DFB4C, func_021DFB84, func_021DFBB4, func_021DFBF0, func_021DFC28, func_021DFC68, func_021DFD0C, func_021DFD24, func_021DFD30, func_021DFD3C, func_021DFD64, func_021DFD7C, func_021DFDA0, func_021DFE48, func_021DFF40, func_021DFFE0, func_021E0008, func_021E0030, func_021E0054, func_021E0138, func_021E017C, func_021E01A0, func_021E01E0, func_021E0200, func_021E0240, func_021E0260, func_021E02E8, func_021E0410, func_021E049C, func_021E08E8, func_021E0958, func_021E0980, func_021E0A64, func_021E0B34, func_021E0BA4, func_021E0BC4, func_021E0BE8, func_021E0C44, func_021E0C78, func_021E0CC0, func_021E0DA0, func_021E0DBC, func_021E0E4C, func_021E0E68, func_021E0EF4, func_021E0FF4, func_021E1024, func_021E1030, func_021E106C, func_021E1098, func_021E10D8, func_021E11A8, func_021E12AC, func_021E12F8, func_021E131C, func_021E1410, func_021E1430, func_021E14DC, func_021E1594, func_021E15F8, func_021E1670, func_021E1718, func_021E1778, func_021E17E8, func_021E1880, func_021E194C, func_021E198C, func_021E1A44, func_021E1AA8, func_021E1B14, func_021E1CA8, func_021E1CC8, func_021E1CE8, func_021E1D68, func_021E1E00, func_021E2054, func_021E2070, func_021E2140, func_021E219C, func_021E2438, func_021E2484, func_021E24E8, func_021E2680, func_021E26AC, func_021E272C, func_021E293C, func_021E2984, func_021E2A1C, func_021E2A80, func_021E2A98, func_021E2B14, func_021E2B68, func_021E2B78, func_021E2BD0, func_021E2C3C, func_021E2D70, func_021E2EA0, func_021E2EFC, func_021E2F2C, func_021E2F34, func_021E2FB0, func_021E3004, func_021E3034, func_021E3070, func_021E30EC, func_021E31B4, func_021E31BC, func_021E31FC, func_021E3208, func_021E3230, func_021E324C, func_021E32C4, func_021E32EC, func_021E33FC, func_021E35A0, func_021E36A8, func_021E36C8, func_021E36D8, func_021E3700, func_021E3730, func_021E3744, func_021E3758, func_021E37D8, func_021E380C, func_021E3838, func_021E38D8, func_021E3910, func_021E3A40, func_021E3B2C, func_021E3BB0, func_021E3C20, func_021E3D04, func_021E3D88, func_021E3DBC, func_021E3E00, func_021E3E40, func_021E3E60, func_021E3E80, func_021E3F08, func_021E3F30, func_021E3F70, func_021E3F74, func_021E3FE4, func_021E4000, func_021E4068, func_021E40EC, func_021E4174, func_021E41A0, func_021E421C, func_021E42B4, func_021E4324, func_021E43DC, func_021E4420, func_021E4570, func_021E4598, func_021E467C, func_021E4810, func_021E4888, func_021E48E0, func_021E496C, func_021E4984, func_021E49DC, func_021E4A1C, func_021E4A84, func_021E4AA4, func_021E4AB8, func_021E4AD0, func_021E4B00, func_021E4DBC, func_021E4E0C, func_021E4E64, func_021E4F28, func_021E5098, func_021E5158, func_021E5164, func_021E51A4, func_021E5284, func_021E53CC, func_021E53F8
 * address:  0x021DEA24
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
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_02045CAC 0x02045CAC arm
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE9E8 0x021DE9E8 thumb ov119
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE754 0x021DE754 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 *   func_021DD140 0x021DD140 thumb ov119
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_0207D658 0x0207D658 arm
 *   func_02040588 0x02040588 arm
 *   func_021E69C0 0x021E69C0 thumb ov119
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021E64B8 0x021E64B8 thumb ov119
 *   func_021DD588 0x021DD588 thumb ov119
 *   func_021DD9DC 0x021DD9DC thumb ov119
 *   func_021DD528 0x021DD528 thumb ov119
 *   func_02041570 0x02041570 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021E6B90 0x021E6B90 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_021DE8C0 0x021DE8C0 thumb ov119
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   DWC_RAPCOMMON_DestroySubHeap  0x02156ED0  thumb  ov009
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B99F0 0x021B99F0 thumb ov114
 *   func_021B99F4 0x021B99F4 thumb ov114
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   func_0202136C 0x0202136C thumb
 *   MAIL_Create 0x02008F08 thumb
 *   func_02008F88 0x02008F88 thumb
 *   func_02019B58 0x02019B58 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAPCOMMON_CreateSubHeapUnlimited 0x02156E24 thumb ov009
 *   func_0200853C 0x0200853C thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_020173EC 0x020173EC thumb
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   func_021D89CC 0x021D89CC thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021DD90C 0x021DD90C thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   d_021E76D4 0x021E76D4 data a4
 *   d_021E76EC 0x021E76EC data a4
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_021DD34C  0x021DD34C  thumb  ov119
 *   func_021DD4F4  0x021DD4F4  thumb  ov119
 *   func_021E62D4  0x021E62D4  thumb  ov119
 *   func_021E6718  0x021E6718  thumb  ov119
 *   func_021E6790  0x021E6790  thumb  ov119
 *   func_021E67A8  0x021E67A8  thumb  ov119
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021E67C4 0x021E67C4 thumb ov119
 *   func_021E68B4  0x021E68B4  thumb  ov119
 *   func_021E67E0 0x021E67E0 thumb ov119
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   func_021E5868  0x021E5868  thumb  ov119
 *   func_021E57FC  0x021E57FC  thumb  ov119
 *   func_021E6308 0x021E6308 thumb ov119
 *   func_021E6F0C 0x021E6F0C thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   g_021E7844      0x021E7844  data  ov119
 *   d_021E7794 0x021E7794 data a4
 *   MCSS_GetPosition   0x02015C30  thumb
 *   sub_02030734   0x02030734  arm
 *   d_021E80F4     0x021E80F4  data  ov119
 *   _s32_div_f      0x0209C0A4  arm
 *   FX_SinCosTable_    0x020A1B38  data
 *   MCSS_SetPosition   0x02015C48  thumb
 *   _s32_to_float    0x0209BDBC  arm
 *   __fdiv           0x0209CE10  arm
 *   __fmul           0x0209C77C  arm
 *   _fmul            0x0209C77C  arm
 *   _f2s             0x0209C494  arm
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0200960C 0x0200960C thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   sub_02009454  0x02009454  thumb
 *   func_02009470  0x02009470  thumb
 *   d_021E8130     0x021E8130  data  ov119
 *   func_02082D44 0x02082D44 arm
 *   func_0200C9EC  0x0200C9EC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   sub_02009D9C  0x02009D9C  thumb
 *   GAME_DATA_GetSaveBlock1F  0x02012F14  thumb
 *   func_02009D9C 0x02009D9C thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02008FEC 0x02008FEC thumb
 *   func_02008FFC 0x02008FFC thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008C20 0x02008C20 thumb
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   func_020086F8 0x020086F8 thumb
 *   func_02007AEC 0x02007AEC thumb
 *   func_02007AF4 0x02007AF4 thumb
 *   GAME_DATA_GetBoxSave 0x02012F98 thumb
 *   func_02007B5C 0x02007B5C thumb
 *   PERAPVOICE_IsRecorded   0x02007B50  thumb
 *   PERAPVOICE_ClearRecorded   0x02007B54  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MAIL_GetBoxSize   0x02008FFC  thumb
 *   MAIL_GetBox   0x02008FEC  thumb
 *   sub_02008C20   0x02008C20  thumb
 *   PLAYTIME_GetStamp   0x020086F0  thumb
 *   BOX_SAVEDATA_GetUsableBoxCount   0x020076A4  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   BOX_SAVEDATA_GetBoxPageSize   0x02007A9C  thumb
 *   BOX_SAVEDATA_GetBoxPokemon   0x02007AF4  thumb
 *   MAIL_FindEmptySlot  0x02009020  thumb
 *   MAIL_SetSlot   0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_02008574  0x02008574  thumb
 *   sub_02009DE8   0x02009DE8  thumb
 *   sub_0200949C   0x0200949C  thumb
 *   sub_020094D8   0x020094D8  thumb
 *   POKE_TOOL_HealFull  0x0201B9F0  thumb
 *   func_0202F190  0x0202F190  thumb
 *   sub_02008DF0   0x02008DF0  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   sub_02009EB0   0x02009EB0  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKEPARTY_SetMember   0x0201AB48  thumb
 *   POKE_TOOL_GetBoxParam   0x020185F4  thumb
 *   func_020075B0  0x020075B0  thumb
 *   sub_0201283C   0x0201283C  thumb
 *   sub_02009BB8   0x02009BB8  thumb
 *   sub_02009D1C   0x02009D1C  thumb
 *   d_021E8108     0x021E8108  data  ov119
 *   d_021E811C     0x021E811C  data  ov119
 *   POKEPARTY_InitEx 0x0201A954 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   func_020076A4 0x020076A4 thumb
 *   func_02012984 0x02012984 thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   FADE_Start 0x0204E720 arm
 *   func_020108C4 0x020108C4 thumb
 *   func_02010904 0x02010904 thumb
 *   func_02010934 0x02010934 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   func_021E57A4 0x021E57A4 thumb ov119
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 *   func_021E58A0 0x021E58A0 thumb ov119
 *   func_021DACE4 0x021DACE4 thumb ov119
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   func_020275E4 0x020275E4 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275EC 0x020275EC thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   func_02027720 0x02027720 thumb
 *   func_0202772C 0x0202772C thumb
 *   func_02027738 0x02027738 thumb
 *   func_02027740 0x02027740 thumb
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_02028470 0x02028470 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Create 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_0200566C 0x0200566C thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   d_021E7984 0x021E7984 data a4
 *   d_021E7934 0x021E7934 data a4
 *   d_021E7914 0x021E7914 data a4
 *   d_021E794C 0x021E794C data a4
 *   func_021D8ADC 0x021D8ADC thumb ov119
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   func_021E5BE4  0x021E5BE4  thumb  ov119
 *   func_021E5EF8  0x021E5EF8  thumb  ov119
 *   func_021E625C  0x021E625C  thumb  ov119
 *   func_021E5958 0x021E5958 thumb ov119
 *   func_021E5998 0x021E5998 thumb ov119
 *   d_021E7944 0x021E7944 data a4
 *   d_021E793C 0x021E793C data a4
 *   func_021E6294 0x021E6294 thumb ov119
 *   func_021E5DFC 0x021E5DFC thumb ov119
 *   func_021E5F14 0x021E5F14 thumb ov119
 *   d_021E7954 0x021E7954 data a4
 *   d_021E7964 0x021E7964 data a4
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   func_021E60BC 0x021E60BC thumb ov119
 *   func_021E6CB8 0x021E6CB8 thumb ov119
 *   func_021E6334 0x021E6334 thumb ov119
 *   func_021E6E7C 0x021E6E7C thumb ov119
 *   func_021E6DEC 0x021E6DEC thumb
 *   d_021E7924 0x021E7924 data a4
 *   d_021E791C 0x021E791C data a4
 *   d_021E7974 0x021E7974 data a4
 *   d_021E790C 0x021E790C data a4
 *   APP_TASKMENU_WIN_CreateEx 0x0202800C thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   d_021E792C 0x021E792C data
 *   func_02030EAC 0x02030EAC arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   d_021E799C 0x021E799C data a4
 *   d_021F4560 0x021F4560 data a4
 *   d_021E7B1C 0x021E7B1C data a4
 *   d_020A1DF8 0x020A1DF8 data a2
 *   func_02048C4C 0x02048C4C arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B20 0x02048B20 arm
 *   func_02048B60 0x02048B60 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   ICA_ANIME_SetCameraPos 0x02011CF0 thumb
 *   ICA_ANIME_SetCameraTarget 0x02011D0C thumb
 *   func_02048AD0 0x02048AD0 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02011610 0x02011610 thumb
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   d_021E79C8 0x021E79C8 data a4
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 *   func_020115EC 0x020115EC thumb
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   PARTICLE_InitManager 0x02050B80 arm
 *   func_02030734 0x02030734 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   d_021E81C0 0x021E81C0 data a4
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   func_02087A3C 0x02087A3C arm
 *   func_020056BC 0x020056BC thumb
 *   PARTICLE_SetupSystemBorrowed 0x02051360 arm
 *   PARTICLE_ExitManager  0x02050ED4  arm
 *   PARTICLE_SetupSystem  0x02051230  arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_021E7AF4 0x021E7AF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E7AC4 0x021E7AC4 data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   tbl_021E7AC4   0x021E7AC4  data   ov119  a4
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   d_021E7B3C 0x021E7B3C data a4
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   func_02047964  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   PARTICLE_DrawAllSystems  0x02051534  arm
 *   PARTICLE_UpdateAllSystems  0x02051574  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   d_021E7AC8  0x021E7AC8  data a4
 *   d_021E8144  0x021E8144  data a4
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   MCSS_GetSizeX 0x02015F04 thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   _fgr 0x0209BBB0 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _fflt 0x0209BDBC arm
 *   d_021E7B9C 0x021E7B9C data a4
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   data_021E7B00 0x021E7B00 data a4
 *   data_021E7B0C 0x021E7B0C data a4
 *   MCSS_Del  0x02015BA4  thumb
 *   d_021E8190 0x021E8190 data a2
 *   d_021E8178 0x021E8178 data a4
 *   d_021E8168 0x021E8168 data a4
 *   func_0207F7A0 0x0207F7A0 arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207F7FC 0x0207F7FC arm
 *   func_0207F9B4 0x0207F9B4 arm
 *   func_0207D84C 0x0207D84C arm
 *   func_0207D810 0x0207D810 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_0207DA8C 0x0207DA8C arm
 *   func_0207D7C4 0x0207D7C4 arm
 *   func_021D8A18 0x021D8A18 thumb ov119
 *   _ll_sdiv 0x0209C00C arm
 *   d_021E815C 0x021E815C data ov119 a4
 *   d_021E79AC 0x021E79AC data ov119 a4
 *   d_021E8150 0x021E8150 data ov119 a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02083194 0x02083194 arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetAllButtonsPriority 0x021B6520 thumb ov067
 *   d_021E7C0C 0x021E7C0C data a4
 *   func_02007A18  0x02007A18  thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   d_021E7CE4     0x021E7CE4  data  ov119
 *   d_021E7D40     0x021E7D40  data  ov119
 *   d_021E7CC8     0x021E7CC8  data  ov119  a4
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02040618 0x02040618 arm
 *   d_021E7DD0 0x021E7DD0 data a4
 *   func_020414EC 0x020414EC arm
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_02042FB0 0x02042FB0 arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   func_0200785C 0x0200785C thumb
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   func_021E69A4 0x021E69A4 thumb ov119
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_021D8E24 0x021D8E24 thumb ov119
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   d_021E82A4 0x021E82A4 data
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_02061CA4 0x02061CA4 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   func_02017E88 0x02017E88 thumb
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_02049DF4 0x02049DF4 arm
 *   d_021E8530 0x021E8530 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   d_021E7E24 0x021E7E24 data a4
 *   d_021E7F44 0x021E7F44 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 *   CLACT_SetActorObjMode  0x0204B688  arm  arm9
 */
#include "pokemontrade_types.h"
#include "../../matched/include/Obj22746.h"
#include "../../matched/include/Obj22747.h"
#include "../../matched/include/Obj10368.h"
#include "../../matched/include/Obj13906.h"
#include "../../matched/include/Obj10369.h"
#include "../../matched/include/Obj00826.h"
#include "../../matched/include/Obj22751.h"
#include "../../matched/include/Obj22752.h"
#include "../../matched/include/Obj22755.h"
#include "../../matched/include/Obj22758.h"
#include "../../matched/include/Obj13908.h"
#include "../../matched/include/Obj22760.h"
#include "../../matched/include/Obj22761.h"
#include "../../matched/include/Obj22762.h"
#include "../../matched/include/Obj22763.h"
#include "../../matched/include/Obj22764.h"
#include "../../matched/include/Obj22765.h"
#include "../../matched/include/Obj22766.h"
#include "../../matched/include/Obj22767.h"
#include "../../matched/include/Obj22768.h"
#include "../../matched/include/Obj10373.h"
#include "../../matched/include/Obj13909.h"
#include "../../matched/include/Obj08064.h"
#include "../../matched/include/Obj00673.h"
#include "../../matched/include/Obj02173.h"
#include "../../matched/include/Obj08067.h"
#include "../../matched/include/Obj04480.h"
#include "../../matched/include/Obj08068.h"
#include "../../matched/include/Obj13911.h"
#include "../../matched/include/Obj22795.h"
#include "../../matched/include/Obj22796.h"
#include "../../matched/include/Obj22808.h"

#define W(p, o) (*(int *)((p) + (o)))
#define H(p, o) (*(u16 *)((p) + (o)))
#define T(p)    (*(Trade **)((p) + 8))
#define P(k) (*(void **)(p+(k)))
#define Q ((void **)(p+0x844))
#define WININ (*(volatile u16 *)0x04001048)
#define WINOUT (*(volatile u16 *)0x0400104a)
#define DISPCNT (*(volatile u32_021DEA24 *)0x04001000)
#define F32_TO_FX32(f) ((int)(((f) > 0) ? ((f) * 4096.0f + 0.5f) : ((f) * 4096.0f - 0.5f)))
#define REG_VTX_16 (*(vu32 *)0x0400048C)
#define REG(a) (*(volatile u32_021E38D8 *)(a))
struct MsgBank;
struct Obj;
struct Entry;
struct Link;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
struct Sub0200852CObj;
struct TaskMenu;
struct S119DD4F4;
struct Bank;
struct WordSet;
struct Big;
struct Sub02009470Obj;
struct PerapVoice;
struct PlayTime;
struct PlayTimeStamp;
struct Rec534;
struct Sub02007AC8Entry;
struct Blk37;
struct Party;
struct PartyMon;
struct Sub02008EACObj;
struct Sub020097BCObj;
struct Sub02009D9CObj;
struct BigObj;
struct Sub020075B0Entry;
struct Sub02008C20Obj;
struct Sub0201088CObj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct R;
struct Tcbl;
struct PrintSys;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct Blk;
struct Ctx;
struct TaskMenuTmpl;
struct Node;
struct LightSet;
struct LightSlot;
struct Light;
struct IcaAnime;
struct Rec12;
struct G3dSys;
struct Arg;
struct Personal;
struct Sav;
struct Sub020079BCEntry;
struct Actor;
struct PtS;
struct Struct36;
struct Vec2;
struct DispVram;
typedef unsigned char u8;

typedef unsigned int u32_021DEA24;

typedef struct S_021DEA24 S_021DEA24;

typedef unsigned int u32_021DEB34;

typedef unsigned int   u32_021DEBA0;

typedef unsigned short u16;

typedef unsigned u32_021DEBD4;

typedef unsigned int   u32_021DEC4C;

typedef unsigned int   u32_021DECA0;

typedef unsigned int   u32_021DED74;

typedef unsigned int   u32_021DEDBC;

typedef unsigned int   u32_021DEE00;

typedef unsigned int   u32_021DEEA8;

typedef unsigned int u32_021DEF1C;

typedef unsigned int   u32_021DF0B8;

typedef unsigned int   u32_021DF168;

typedef unsigned int   u32_021DF1C8;

typedef unsigned int   u32_021DF210;

typedef unsigned int   u32_021DF338;

typedef unsigned int   u32_021DF37C;

typedef unsigned int   u32_021DF404;

typedef unsigned int   u32_021DF43C;

typedef struct { int a, b; } Pair_021DF490;

typedef unsigned int   u32_021DF4CC;

typedef unsigned int   u32_021DF510;

typedef unsigned int   u32_021DF548;

typedef struct { int a, b; } Pair_021DF59C;

typedef unsigned int   u32_021DF5D8;

typedef unsigned int   u32_021DF708;

typedef unsigned int   u32_021DF7F0;

typedef unsigned int   u32_021DF8A0;

typedef unsigned int   u32_021DF918;

typedef unsigned int   u32_021DF978;

typedef struct { u8 low:4;u8 high:4; } Flags;

typedef unsigned int   u32_021DF9E8;

typedef unsigned int u32_021DFA60;

typedef struct {
    u32_021DFA60 a;
    u32_021DFA60 b;
} Pair_021DFA60;

typedef struct {
    Pair_021DFA60 t[25];
} Table_021DEA24;

typedef struct { int id; int key; } Ent_021DFA98;

typedef struct { Ent_021DFA98 e[22]; } Tbl;

typedef unsigned int   u32_021DFA98;

typedef unsigned int u32_021DFAD0;

typedef struct { int fn; int id; } Ent_021DFAD0;

typedef struct { Ent_021DFAD0 e[2]; } T2;

typedef struct { Ent_021DFAD0 e[6]; } T6;

typedef unsigned int u32_021DFB4C;

typedef unsigned int u32_021DFB84;

typedef unsigned int u32_021DFBB4;

typedef unsigned int u32_021DFBF0;

typedef signed short s16_021DFBF0;

typedef signed int s32_021DFBF0;

typedef struct {
    u32_021DFBF0 f00;
    s32_021DFBF0 f04;
    s32_021DFBF0 f08;
    u32_021DFBF0 f0c;
    u32_021DFBF0 f10;
    u16 f14;
    u16 f16;
} S_021DFBF0;

typedef unsigned int u32_021DFC28;

typedef struct {
    u32_021DFC28 f00;
    u32_021DFC28 f04;
    u32_021DFC28 f08;
    u32_021DFC28 f0c;
    u32_021DFC28 f10;
    u32_021DFC28 f14;
    u32_021DFC28 f18;
    u32_021DFC28 f1c;
    u32_021DFC28 f20;
    u32_021DFC28 f24;
    u32_021DFC28 f28;
    u32_021DFC28 f2c;
    u32_021DFC28 f30;
    u32_021DFC28 f34;
} P;

typedef unsigned int u32_021DFC68;

typedef int s32_021DFC68;

typedef unsigned int u32_021DFD0C;

typedef short s16_021DFD24;

typedef signed char s8;

typedef unsigned int u32_021DFD24;

typedef int s32_021DFD24;

typedef short s16_021DFD30;

typedef unsigned int u32_021DFD30;

typedef int s32_021DFD30;

typedef unsigned int   u32_021DFD3C;

struct Packet {
    u32_021DEA24 prefix[8];
    u16 first,second;
    u8 a,b;
    u8 mode:3;
    u8 :5;
};

typedef char PacketMustBe40[sizeof(struct Packet)==40?1:-1];

typedef struct {
    u8   pad0[0x1C];
    void *party;
    u8   pad20[8];
    u16  box;
    u16  slot;
    u16  count;
} Trade;

typedef signed int     s32_021E0980;

typedef signed int     s32_021E0B34;

typedef struct Descriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} Descriptor;

typedef signed short s16_021E0EF4;

typedef short s16_021E1024;

typedef int s32_021E1024;

typedef signed int     s32_021E12AC;

typedef struct {u32_021DEA24 heap;u8 count;u8 pad[3];const void *items;u32_021DEA24 flag;u8 x,y,a,b;} Template_021DEA24;

typedef signed short   s16_021E1430;

typedef signed short   s16_021E14DC;

typedef signed short   s16_021E1594;

typedef signed short   s16_021E15F8;

typedef signed short s16_021E1718;

typedef signed short s16_021E1778;

typedef signed short s16_021E17E8;

typedef short s16_021E1880;

typedef struct { int v[5]; } T5;

typedef signed short s16_021E194C;

typedef signed short s16_021DEA24;

typedef struct {int a,b;} Pair_021DEA24;

typedef struct { int v[2]; } Pair_021E1D68;

typedef struct { int a,b,c,d; } Quad_021DEA24;

typedef signed short s16_021E2484;

typedef struct {int a,b;} Pair;

typedef struct {u32_021DEA24 a,b,c,d;} Quad_021E2484;

typedef int BOOL;

typedef struct {int a,b,c,d,e,f,g,h;} Config_021DEA24;

typedef struct {int x,y,z;} Vec_021DEA24;

typedef int fx32_021DEA24;

typedef struct { fx32_021DEA24 x, y, z; } VecFx32_021DEA24;

typedef struct { fx32_021DEA24 m[3][3]; } MtxFx33;

typedef struct { VecFx32_021DEA24 trans; VecFx32_021DEA24 scale; MtxFx33 rot; } Transform;

typedef struct {
    char pad0[0x90];
    u32_021DEA24 anim90;
    u32_021DEA24 anim94;
    u32_021DEA24 anim98;
    u32_021DEA24 anim9c;
    void *objA0;
    void *objA4;
    void *objA8;
    void *objAC;
} Sub_021DEA24;

typedef struct {
    char pad0[0xc];
    Sub_021DEA24 *sub;
    char pad10[0x83c - 0x10];
    void *x83c;
} Work_021DEA24;

typedef enum { SHADING_TOON, SHADING_HIGHLIGHT } Shading;

typedef signed int     s32_021E2D70;

typedef short s16_021E2C3C;

typedef int s32_021E2F2C;

typedef struct {
    void *a[9];         /* 0x000 */
    void *b[6];         /* 0x024 */
    u16 pad3C[0x3F];    /* 0x03C */
    u16 heap;           /* 0x0BA */
} S;

typedef short s16_021E3004;

typedef struct {u32_021DEA24 x,y,z;} Vec_021E3004;

typedef struct {void (*call)(char *);u32_021DEA24 other;} Callback;

typedef int s32_021E3004;

typedef void (*Fn)(void *);

typedef struct {int a,b,c; u16 d,e;} Entry_021E324C;

typedef struct {
    void (*fn)(char *p, void *out);
    int unused;
} Handler;

typedef struct {
    u16 a;
    u16 b;
    int amount;
    unsigned int c;
} Cfg;

typedef struct {
    char pad00[0x90];
    int *a90;           /* 0x090 */
    int *a94;           /* 0x094 */
    int *a98;           /* 0x098 */
    int *a9C;           /* 0x09C */
    int pada0[2];       /* 0x0A0 */
    int aA8;            /* 0x0A8 */
    int aAC;            /* 0x0AC */
} Sub_021E3004;

typedef signed int     s32_021E3208;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    float x;
    float y;
    float z;
} Entry_021E33FC;

typedef struct {
    int x;
    int y;
    int z;
} Vec_021E33FC;

typedef signed short   s16_021E33FC;

typedef struct { int x, y, z; } Vec_021E35A0;

typedef struct { u32_021DEA24 v[4]; } Table_021E3004;

typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad5f6[0x840 - 0x5f6];
    void *res;
    void *obj[4];
    char pad854[0x118c - 0x854];
    int mode;
} Work_021E3004;

typedef short s16_021E3700;

typedef s16_021E3700 fx16;

typedef volatile u32_021DEA24 vu32;

typedef unsigned long u32_021E38D8;

typedef short s16;

typedef long fx32_021E38D8;

typedef unsigned long u32_021E3A40;

typedef long fx32;

typedef struct { fx32 x,y,z; } VecFx32_021E3A40;

typedef struct { fx32 a[12]; } MtxFx43;

typedef unsigned int   u32_021E3B2C;

typedef unsigned int u32;

typedef struct { u32 f0, f4; u16 f8, fA, fC, fE, f10, f12; u32 f14, f18, f1C; } Element;

typedef struct { Element e[4]; } Template_021E3A40;

typedef struct { void *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1C; } Config_021E3A40;

typedef signed int     s32_021DEA24;

typedef struct { unsigned int w[2]; } Tbl2;

typedef struct {
    char pad00[0x24];
    u16 v[0x300];       /* 0x024 */
} Buf;

typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;

typedef struct { u16 id; u8 b2, b3; } Ent;

typedef struct { s16 x, y; } Pt;

typedef struct { int a, b, c, d[6]; } Info;

typedef short s16_021E4F28;

typedef struct Pt_021E4F28 { s16_021E4F28 x, y; } Pt_021E4F28;

typedef int s32_021E4F28;

typedef signed short s16_021E51A4;

typedef struct Pt_021E51A4 {s16_021E51A4 x,y;} Pt_021E51A4;

typedef struct Object {u8 pad[0xac0];void *actors[12][5];} Object;

typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;

extern void TOUCHBAR_Update(struct S_021DEA24 *p);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);
extern void func_02045CAC(struct MsgBank *,unsigned,void *);
extern void func_021DD09C(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DE9E8(void *);
extern int TOUCHPANEL_HitTrg(const void *);
extern u32_021DEA24 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void GFL_USE_PlaySeDefaultVolume(u32_021DEA24 a);
extern void func_021E68F4(int,int);
extern int func_021DE754(char *,int);
extern int func_021DE208(char *);
extern int func_021DD140(char *p);
extern int TOUCHPANEL_GetTrg(void);
extern int func_021D8980(char *p);
extern void func_0207D658(u32_021DEBD4,int,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_021E69C0(char *p);
extern u32_021DEC4C WIPE_SYS_EndCheck(void);
extern void func_021E64B8(void *);
extern void func_021DD588(char *p);
extern void func_021DD9DC(unsigned char *);
extern void func_021DD528(char *,int);
extern void func_02041570(int channel, u16 val);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021E6B90(char *p);
extern void WIPE_SYS_Start(void *p1, u32_021DECA0 p2, u32_021DECA0 p3, u32_021DECA0 p4, u32_021DECA0 p5, u32_021DECA0 p6, u32_021DECA0 p7);
extern int func_021D8A24(void *);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32_021DEDBC b, u32_021DEDBC c, u32_021DEDBC d);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void func_021DE8C0(char *p);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void func_021B9774(u8 *p);
extern void func_021B9838(u8 *p);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern int func_021B99DC(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern int func_021B99F0(u8 *p);
extern u32_021DEF1C func_021B99F4(u32_021DEF1C p, u32_021DEF1C i);
extern void func_021B99B8(u8 *);
extern int func_021D89EC(const u8 *p);
extern u32_021DEF1C func_02017E1C(void *,u32_021DEF1C,u32_021DEF1C);
extern void POKE_TOOL_SetPartyValue(void *,u32_021DEF1C,u32_021DEF1C);
extern u32_021DEF1C func_0202136C(u16);
extern void *MAIL_Create(int);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern void func_02019B58(void *);
extern struct MsgBank *func_02045B38(u32_021DEF1C resident, u32_021DEF1C arcId, u32_021DEF1C fileId, u32_021DEF1C heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32_021DEF1C index);
extern u32_021DEF1C MSGDATA_Delete(struct Rec *rec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32_021DEF1C func_020307B0(void *p);
extern void DWC_RAP_SetErrorCallback(int a0, int a1);
extern void DWC_RAPCOMMON_CreateSubHeapUnlimited(int,int,int);
extern u32_021DF0B8 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *func_021B9800(int,int,int);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *,int,int);
extern int func_021B98F8(u8 *);
extern int func_021B9748(u8 *);
extern u32_021DF0B8 func_020173EC(void);
extern void BG_SYS_SetSubVisiblePlanes(u32_021DF168 planes);
extern void WIPE_ResetBrightness(u32_021DF168 which);
extern void func_021D89CC(char *p);
extern void func_021D9434(void *);
extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);
extern int func_021DD24C(char *p);
extern void func_021DD294(char *p, int a, int b);
extern void func_021DD90C(u8 *p, int i, int msg, int force);
extern void func_021DAEF0(char *p);
extern void func_021DBBD0(char *p);
extern u32_021DF43C APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern int func_021D8AF4(int,char *);
extern int func_021D8B0C(int,int);
extern int func_021D8AA8(void *);
extern int TOUCHPANEL_GetCont(void);
extern int func_021DD34C(char *p, int a, int b);
extern void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
extern void func_021E62D4(void *p, int a, int b);
extern void func_021E6718(char *p, int i);
extern void func_021E6790(void *p, int i, int a);
extern void func_021E67A8(void *p, int i);
extern u32_021DF7F0 TOUCHPANEL_GetPointTrg(u32_021DF7F0 *outA, u32_021DF7F0 *outB);
extern void func_021E67C4(void *,int);
extern void func_021E68B4(int p, int n);
extern void func_021E67E0(void *, int, int);
extern int GFL_USE_IsSeqPlaying(u32_021DF8A0 a);
extern void func_021E5868(char *p);
extern void func_021E57FC(int p);
extern void func_021E6308(void *,int,int);
extern void func_021E6F0C(char *p, int side, void *mon);
extern void func_02041B6C(u32_021DF918 bit);
extern void func_02041300(int,int,unsigned char,int,int,int,int);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern u32_021DF9E8 GFL_NET_SendData(u32_021DF9E8 entry, u32_021DF9E8 sendID, u32_021DF9E8 c, u32_021DF9E8 d, u32_021DF9E8 e, u32_021DF9E8 f, u32_021DF9E8 g, u32_021DF9E8 h);
extern void MCSS_GetPosition(void *p, u32_021DFB4C *out);
extern void *sub_02030734(u32_021DFB84 heapId, u32_021DFB84 size, int clear, const char *site, u16 tag);
extern s32_021DFBF0 _s32_div_f(s32_021DFBF0, s32_021DFBF0);
extern void MCSS_SetPosition(void *p, u32_021DFC28 *src);
extern float _s32_to_float(s32_021DFC68);
extern float __fdiv(float, float);
extern float __fmul(float, float);
extern s32_021DFC68 _f2s(float);
extern void MCSS_SetAnmStopFlag(void *p);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32_021DFD3C a);
extern u32_021DEA24 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32_021DEA24 heapId);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_FadeOutBgm(u32_021DEA24 a);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void *func_0201F5DC(void *a0, u32_021DEA24 a1, u32_021DEA24 a2, u32_021DEA24 a3);
extern void *func_021D8FA4(void *,int);
extern void func_0201EEF4(struct WordSet *p, u32_021DEA24 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32_021DEA24 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 *func_02012944(void *p);
extern void MYSTATUS_Copy(void *,void *);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern u8 func_02009584(const struct Sub02009470Obj *obj);
extern u8 func_0200960C(const struct Sub02009470Obj *obj);
extern u32_021DEA24 sub_02009454(void);
extern void func_02082D44(const void *, void *, int);
extern u32_021DEA24 func_0200C9EC(void);
extern void *func_0200CA1C(void *p);
extern u32_021DEA24 sub_02009D9C(void);
extern void *GAME_DATA_GetSaveBlock1F(void **h);
extern unsigned func_02009D9C(void);
extern void MI_CpuFill8(void *,int,int);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern int GAME_DATA_GetPlayTime(int p0);
extern struct Sub02007AC8Entry *func_02007AF4(void **save, u32_021DEA24 box);
extern struct Sub02007AC8Entry *GAME_DATA_GetBoxSave(void *p);
extern u32_021DEA24 func_02008FFC(void);
extern u32_021DEA24 func_02008C20(void);
extern u32_021DEA24 func_02007AEC(void);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void func_020086F8(struct PlayTime *p, const struct PlayTimeStamp *in);
extern void func_02007B5C(struct PerapVoice *p);
extern void *PERAPVOICE_IsRecorded(void **p);
extern void PERAPVOICE_ClearRecorded(struct PerapVoice *p);
extern u32_021DEA24 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32_021DEA24 idx);
extern u32_021DEA24 MAIL_GetBoxSize(void);
extern struct Sub02008F80Obj *MAIL_GetBox(void *sys);
extern u32_021DEA24 sub_02008C20(void);
extern void PLAYTIME_GetStamp(const struct PlayTime *p, struct PlayTimeStamp *out);
extern u8 BOX_SAVEDATA_GetUsableBoxCount(void *save);
extern struct Party *POKEPARTY_Create(u32_021DEA24 heap);
extern u32_021DEA24 BOX_SAVEDATA_GetBoxPageSize(void);
extern struct Sub02007AC8Entry *BOX_SAVEDATA_GetBoxPokemon(void **save, u32_021DEA24 box);
extern int MAIL_FindEmptySlot(void *obj, int v);
extern void MAIL_SetSlot(struct Sub02008F80Obj *arr, u32_021DEA24 unused, int i, const struct Sub02008F80Obj *src);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32_021DEA24 func_02025C1C(u32_021DEA24 a, u32_021DEA24 b, u32_021DEA24 c);
extern u32_021DEA24 func_02025C30(u32_021DEA24 a, u32_021DEA24 b, u32_021DEA24 c);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern void sub_02009DE8(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p);
extern u32_021DEA24 sub_0200949C(const struct Sub02009470Obj *obj, int row, int col);
extern void sub_020094D8(struct Sub02009470Obj *obj, int row, int col, int value);
extern void POKE_TOOL_HealFull(void *mon);
extern void func_0202F190(void *a0, u32_021DEA24 a1, u32_021DEA24 a2, u32_021DEA24 a3, u16 a4);
extern u32_021DEA24 sub_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void sub_02009EB0(struct Sub02009D9CObj *obj);
extern u32_021DEA24 POKE_TOOL_ChangeForm(void *p, u32_021DEA24 a);
extern void POKEPARTY_SetMember(struct Party *p, u32_021DEA24 idx, const struct PartyMon *src);
extern void *POKE_TOOL_GetBoxParam(void *mon);
extern int func_020075B0(void *save, u32_021DEA24 box, u32_021DEA24 slot, const struct Sub020075B0Entry *src);
extern u32_021DEA24 sub_0201283C(const struct BigObj *p);
extern void sub_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c);
extern int sub_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32_021DEA24 *out);
extern void POKEPARTY_InitEx(struct Party *p, s32_021E0980 capacity);
extern u32_021DEA24 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u8 func_020076A4(void *);
extern u8 func_02012984(const struct BigObj *p);
extern u32_021DEA24 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32_021DEA24 context, u32_021DEA24 param, u8 timezone, u32_021DEA24 *methodOut, u16 heap);
extern void GFL_NET_RestartWithDefaultTimeout(u32_021DEA24 a, u32_021DEA24 b);
extern void FADE_Start(u32_021DEA24 a, s32_021E0B34 b, s32_021E0B34 c, s32_021E0B34 d);
extern void *func_020108C4(u32_021DEA24 heap, u32_021DEA24 a1, u32_021DEA24 a2, u32_021DEA24 a3);
extern u32_021DEA24 func_02010904(struct Sub0201088CObj *p);
extern void func_02010934(struct Sub0201088CObj *p);
extern void func_0203FB44(u32_021DEA24 layer, u32_021DEA24 offset, u32_021DEA24 size);
extern void BG_SYS_SetMainVisiblePlanes(u32_021DEA24 planes);
extern void func_021E57A4(int);
extern void func_021E57E8(int);
extern void func_021E5680(char *p);
extern void func_021E58A0(int);
extern void func_021DACE4(char *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
extern u32_021DEA24 func_020275E4(void);
extern u32_021DEA24 func_020275E8(void);
extern u32_021DEA24 func_020275F8(u32_021DEA24);
extern u32_021DEA24 func_020275FC(u32_021DEA24);
extern u32_021DEA24 func_02027600(u32_021DEA24);
extern u8 func_020275EC(int i);
extern void UI_SCENE_LoadActorGfx(void *,Descriptor *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u8,u8,u8,u16);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32_021DEA24 v, u32_021DEA24 flag);
extern int func_02027720(int);
extern int func_0202772C(int);
extern int func_02027738(int,int);
extern int func_02027740(int,int);
extern void func_02049B40(u32_021DEA24 a, u32_021DEA24 b, u32_021DEA24 c, u32_021DEA24 d, u32_021DEA24 e, u16 f);
extern u32_021DEA24 BMP_WIN_Create(u32_021DEA24 layer, u8 a, u32_021DEA24 b, u32_021DEA24 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32_021DEA24,u32_021DEA24,u32_021DEA24);
extern signed char func_02012FFC(void);
extern u32_021DEA24 PRINTSYS_PrintStream(u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u16,u16);
extern void func_02028470(u8 *,u32_021DEA24);
extern void PRINTSYS_Print(void *,s16_021E0EF4,s16_021E0EF4,void *,void *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void TIME_ICON_Delete(u8 *p);
extern u8 *TIME_ICON_CreateNode(u32_021DEA24 a, void *b, u8 c, u8 d, u16 e);
extern u32_021DEA24 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32_021DEA24 kind);
extern struct WordSet *func_0201EC64(u32_021DEA24 heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32_021DEA24 heapId);
extern struct U16Vec *STRBUF_Create(u32_021DEA24 capacity, u32_021DEA24 heapId);
extern u32_021DEA24 PRINTSYS_QUE_Create(void *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32_021DEA24 count, u32_021DEA24 workSize);
extern void *func_02028590(u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32_021DEA24 a2, u32_021DEA24 a3, u16 heap);
extern void func_0200566C(void);
extern int APP_KEYCURSOR_Delete(int a0);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32_021DEA24 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern s32_021E12AC func_02028484(struct Blk *blk, void *h);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_0201EE84(struct WordSet *p, u32_021DEA24 i, void *mon);
extern u16 *POKE_PERSONAL_LoadFormTable(u32_021DEA24 heap, u16 *countOut);
extern void func_0201EFA4(struct WordSet *p, u32_021DEA24 i, u32_021DEA24 a, u32_021DEA24 b, u32_021DEA24 c, u32_021DEA24 d);
extern void PRINTSYS_PrintColor(void *,short,short,int,int,int);
extern void func_0201EF40(struct WordSet *p, u32_021DEA24 i, u32_021DEA24 v);
extern void func_0201EF34(struct WordSet *p, u32_021DEA24 i, u32_021DEA24 v);
extern u8 func_02018598(void *p);
extern void func_0201EF8C(struct WordSet *p, u32_021DEA24 i, u32_021DEA24 v);
extern int func_021D8ADC(char *p);
extern void CLACT_SetActorBgPriority(void *,u32_021DEA24);
extern void func_021E5BE4(int a);
extern void func_021E5EF8(void *p);
extern void func_021E625C(void *p);
extern void func_021E5958(int p);
extern void func_021E5998(char *p);
extern void func_020056A0(void (*)(void *,void *),void *,int);
extern void func_021E6294(char *,int,u32_021DEA24);
extern void func_021E5DFC(char *,int,void *);
extern void func_021E5F14(char *,int,int,void *);
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetVanishFlag(void *);
extern void func_021E60BC(char *,void *,int);
extern void func_021E6CB8(char *);
extern void func_021E6334(char *,int,int,void *,int,u32_021DEA24);
extern void func_021E6E7C(int p);
extern void func_021E6DEC(int p);
extern u32_021DEA24 *APP_TASKMENU_WIN_CreateEx(u32_021DEA24 a0, u32_021DEA24 a1, u32_021DEA24 a2, u32_021DEA24 a3, u8 a4, u8 a5, u32_021DEA24 a6, u32_021DEA24 a7, u16 a8);
extern u32_021DEA24 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int func_021DD2F4(char *);
extern void func_02030EAC(struct Node *n);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32_021DEA24 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void G3D_SYSTEM_SetProjection(const u32_021DEA24 *src);
extern void func_02048C4C(void *);
extern void func_02048AFC(void *,Vec_021DEA24 *);
extern void func_02048B44(void *,Vec_021DEA24 *);
extern void func_02048B6C(struct Light *l, const u32_021DEA24 *in);
extern void func_02048B20(void *,Vec_021DEA24 *);
extern void func_02048B60(struct Light *l, const u32_021DEA24 *in);
extern void func_0207ADC4(MtxFx33 *m);
extern void ICA_ANIME_SetCameraPos(void *a0, void *a1);
extern void ICA_ANIME_SetCameraTarget(void *a0, void *a1);
extern void func_02048AD0(struct Light *l);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32_021DEA24 idx, const u16 *src);
extern u32_021DEA24 func_02011610(struct IcaAnime *t, struct Rec12 *out);
extern void BUTTON_MAN_SetEmitterPos(void *obj, VecFx32_021DEA24 *v);
extern void *ICA_ANIME_CreateStream(u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24);
extern void func_020115EC(struct IcaAnime *p, s32_021E2D70 v);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void PARTICLE_InitManager(u32_021DEA24 heap);
extern void *func_02030734(u32_021DEA24 heapId, u32_021DEA24 size, int clear, const char *site, u16 tag);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32_021DEA24 a, u32_021DEA24 b, u32_021DEA24 c);
extern void func_02087A3C(int clear, u32_021DEA24 flags);
extern u32_021DEA24 func_020056BC(void);
extern void PARTICLE_SetupSystemBorrowed(void *p, unsigned int a1, unsigned int a2, unsigned int a3);
extern void PARTICLE_ExitManager(void);
extern void PARTICLE_SetupSystem(void *, void *, int, int);
extern void *G3D_UTIL_Create(u16,u16,u16);
extern void *G3D_CAMERA_Create(u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,Vec_021E3004 *,Vec_021E3004 *,Vec_021E3004 *,u16);
extern unsigned int G3D_CAMERA_Delete(void *ptr);
extern void G3D_UTIL_Delete(struct Rec *p);
extern u16 G3D_UTIL_AddUnit(void *,const Entry_021E324C *);
extern u32_021DEA24 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern u32_021DEA24 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32_021DEA24 idx);
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32_021DEA24 i);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern int PARTICLE_DrawAllSystems(void);
extern int PARTICLE_UpdateAllSystems(void);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern u32_021DEA24 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32_021E3208 v);
extern u8 POKE_TOOL_GetGender(void *p);
extern u16 MCSS_GetSizeX(void *p);
extern s16_021E33FC MCSS_GetOfsX(void *p);
extern void MCSS_SetOfsPosition(void *p, u32_021DEA24 *src);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
extern u32_021DEA24 POKE_PERSONAL_GetParam(const struct Personal *p, u32_021DEA24 field);
extern void POKE_PERSONAL_Delete(void *h);
extern void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32_021DEA24 a2, u32_021DEA24 a3, u32_021DEA24 a4, u32_021DEA24 a5);
extern int MCSS_TOOL_SetAnimeStopCallback(int a0);
extern void MCSS_SetScale(void *p, u32_021DEA24 *src);
extern void MCSS_SetShadowVanishFlag(char *p, int v);
extern void MCSS_Del(void *sys, void *obj);
extern void func_0207F7A0(void);
extern void func_020862F0(void *, int);
extern void func_0207F7FC(void *, int, int);
extern void func_0207F9B4(void);
extern void func_0207D84C(fx32_021E38D8,fx32_021E38D8);
extern void func_0207D810(fx32_021E38D8,fx32_021E38D8);
extern void func_0207DA8C(void);
extern void func_0207D7C4(const VecFx32_021E3A40 *,const VecFx32_021E3A40 *,const VecFx32_021E3A40 *,int,MtxFx43 *);
extern u8 func_021D8A18(u8 *);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02049F78(void *a0, u32_021E3B2C a1, u32_021E3B2C a2, u32_021E3B2C a3);
extern void func_02083194(const void *, void *, int);
extern void func_0207FA0C(void);
extern void func_0207FA40(const void *, int, int);
extern void func_0207FADC(void);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *TOUCHBAR_Create(Config_021E3A40 *, int);
extern void TOUCHBAR_SetAllButtonsPriority(u8 *p, u32 v);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_020185F0(void *);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32_021DEA24 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021DEA24 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021DEA24 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021E6700(void *);
extern void func_020414EC(u32 i);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void func_0200785C(void *,u32,void *);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
extern void BMP_WIN_SetPosX(struct Descriptor *p, u8 v);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_ReleaseCharacter(u32 i);
extern void func_021E69A4(char *);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_021E7058(void *);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern char *func_021D8E24(int, int, char *);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern s32_021DEA24 func_02061CA4(void *p, u32 a, u32 b, s32_021DEA24 size);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void CLACT_SetActorDrawPriority(int, u8);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned int POKE_TOOL_GetGraphicIndex(void *mon);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32);
extern void func_020409B4(u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
void func_021DEA24(char *p);
void func_021DEB34(void *p);
void func_021DEBA0(char *p);
void func_021DEBD4(void *p);
void func_021DEC4C(void *p);
void func_021DECA0(char *p);
void func_021DED58(void *p);
void func_021DED74(void *p);
void func_021DEDBC(void *p);
void func_021DEE00(unsigned char *p);
void func_021DEEA8(void *p);
void func_021DEEFC(void **p);
void func_021DEF1C(u8 *p);
void func_021DF0B8(char *p);
void func_021DF168(void *p);
void func_021DF1C8(void *p);
void func_021DF210(char *p);
void func_021DF338(void *p);
void func_021DF37C(u8 *p);
void func_021DF3E4(void *p);
void func_021DF404(char *p);
void func_021DF43C(void *p);
void func_021DF490(void *p);
void func_021DF4CC(char *p);
void func_021DF510(char *p);
void func_021DF548(void *p);
void func_021DF59C(void *p);
void func_021DF5D8(char *p);
int func_021DF614(char *p,int a,int b);
int func_021DF6B4(char *p, int a, int b);
void func_021DF6EC(void *p);
void func_021DF708(void *p);
void func_021DF78C(void *p);
void func_021DF7AC(void *p, int a);
void func_021DF7D0(void *p);
void func_021DF7F0(void *p);
void func_021DF868(void *p);
void func_021DF8A0(void *p, int a, int b);
void func_021DF8E0(void *p);
void func_021DF904(void *p);
void func_021DF918(void *p,int i,void *v);
void func_021DF978(void *p);
int func_021DF9E8(char *p,void *src,int kind);
void func_021DFA60(u32_021DFA60 key);
void func_021DFA98(int key);
void func_021DFAD0(int a0, u8 *a1);
void func_021DFB4C(void *p, void *a1, void *a2);
void *func_021DFB84(void *a0, void *a1, void *a2, u32_021DFB84 heapId);
void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId);
int func_021DFBF0(int a0, int a1, S_021DFBF0 *a2, int a3);
void func_021DFC28(P *p, int a1);
void func_021DFC68(void *p, int a1);
void func_021DFD0C(char *p);
void func_021DFD24(u32_021DFD24 *p);
void func_021DFD30(u8 *p, u32_021DFD30 v);
void func_021DFD3C(void *p);
void func_021DFD64(void *p);
void func_021DFD7C(void *p);
void func_021DFDA0(void *p);
void func_021DFE48(char *p);
void func_021DFF40(char *p);
void func_021DFFE0(char *p);
void func_021E0008(char *p);
void func_021E0030(void *p);
void func_021E0054(char *p);
void *func_021E0138(void *sys, u16 heapId);
void func_021E017C(void *sys, void *buf);
void *func_021E01A0(void *src, u16 heapId);
void func_021E01E0(void *h, void *buf);
void *func_021E0200(void *sys, u16 heapId);
void func_021E0240(void **h, void *dst);
void func_021E0260(char *p);
void func_021E02E8(char *p);
int func_021E0410(char *p, void *party, int idx);
void func_021E049C(char *p);
void func_021E08E8(char *p);
void func_021E0958(char *p);
void func_021E0980(char *p);
void func_021E0A64(char *p);
void func_021E0B34(char *p);
void func_021E0BA4(void *p);
void func_021E0BC4(void *p);
void func_021E0BE8(char *p);
void func_021E0C44(char *p);
void func_021E0C78(char *p);
void func_021E0CC0(char *p);
void func_021E0DA0(char *p);
void func_021E0DBC(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b);
void func_021E0E4C(char *p);
void func_021E0E68(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c);
void func_021E0EF4(char *p,int flag,int x,int y,int w,int h);
void func_021E0FF4(void *p, int a, int flag);
void func_021E1024(void *p);
void func_021E1030(char *p);
void func_021E106C(char *p);
void func_021E1098(char *p);
void func_021E10D8(char *p);
void func_021E11A8(char *p);
int func_021E12AC(char *p);
void func_021E12F8(char *p);
void func_021E131C(char *p,int *ids,int count,int x,int y);
void func_021E1410(void *p, int *ids, int count);
void func_021E1430(void *a,void *b,int x,int y,int flag,int mode,char *p);
void func_021E14DC(void *a,void *b,int x,int y,int flag,char *p);
void func_021E1594(void *a,void *b,int x,int y,int flag,char *p);
void func_021E15F8(void *a,void *b,int x,int y,char *p);
void func_021E1670(void *a,void *b,int x,int y,char *p,int mode,int guard);
void func_021E1718(int a,int b,int x,int y,char *p);
void func_021E1778(int a,int b,int x,int y,char *p);
void func_021E17E8(int a,int b,int x,int y,char *p);
void func_021E1880(int a, int b, int c, int d, char *p);
void func_021E194C(int a,int b,int x,int y,char *p);
void func_021E198C(int a,int b,int x,int y,char *p);
void func_021E1A44(int a,int b,int x,int y,char *p);
void func_021E1AA8(int a,int b,int x,int y,char *p);
void func_021E1B14(char *p,int i,void *mon);
void func_021E1CA8(char *p);
void func_021E1CC8(char *p);
void func_021E1CE8(void *p, int a1);
void func_021E1D68(char *p,void *a);
void func_021E1E00(char *p,int mode,void *mon);
void func_021E2054(char *p, void *a, int b, int a3);
void func_021E2070(char *p,void *mon,Quad_021DEA24 *t);
void func_021E2140(char *p,int a);
void func_021E219C(char *p,void *mon,int side,int flag);
void func_021E2438(char *p,int i);
void func_021E2484(char *p,int a);
void func_021E24E8(char *p, int a1);
void func_021E2680(char *p);
void func_021E26AC(void *a0);
void func_021E272C(char *p,int i,void *mon);
void func_021E293C(char *p,int i);
void *func_021E2984(char *p,int a);
void func_021E2A1C(char *p,int a,int b);
int func_021E2A80(void *a0);
void func_021E2A98(void *a,char *p);
void func_021E2B14(int a);
void func_021E2B68(void);
void func_021E2B78(char *p);
void func_021E2BD0(char *p);
void func_021E2C34(char *p);
void func_021E2C3C(Work_021DEA24 *w, Transform *t);
void func_021E2D70(char *p,unsigned mode);
void func_021E2EA0(char *p);
void func_021E2EFC(char *p);
void func_021E2F2C(void *a0);
void func_021E2F34(char *p);
void func_021E2FB0(char *p);
void func_021E3004(char *p);
void func_021E3034(u32_021DEA24 *p, int a1);
void func_021E3070(S *p);
void func_021E30EC(char *p);
void func_021E31B4(void *p);
void func_021E31BC(char *p);
void func_021E31FC(void *p);
void func_021E3208(void *p, int a);
void func_021E3230(void *p);
void func_021E324C(char *p,int n);
void func_021E32C4(char *p);
void func_021E32EC(char *p);
void func_021E33FC(void *p0, int *dir, int p2, void *mon);
void func_021E35A0(Work_021E3004 *p, int idx, int side, void *mon, int flag);
void func_021E36A8(void *a, int b, int c, void *d, int e, int f);
void func_021E36C8(void *a, int b, int c, void *d, int e);
void func_021E36D8(void *p, int idx);
void func_021E3700(int n);
void func_021E3730(int n);
void func_021E3744(int n);
void func_021E3758(unsigned short *p, int x, int y, int colour);
void func_021E37D8(u16 *p, u8 *src, int k, int a3);
void func_021E380C(u16 *p, u8 *src, int a2);
void func_021E3838(char *p, int count);
void func_021E38D8(int a, int b);
void func_021E3910(int z,int index,u16 a,int b);
void func_021E3A40(const u8 *p);
void func_021E3B2C(char *p);
void func_021E3BB0(char *p);
void func_021E3C20(char *p);
unsigned char func_021E3D04(void *mon, unsigned int heap);
void func_021E3D88(char *p, int box, unsigned char *out);
void func_021E3DBC(char *p, void *party, unsigned char *out);
int func_021E3E00(char *p, int i);
void func_021E3E40(char *p);
void func_021E3E60(void *p);
void func_021E3E80(char *p);
void func_021E3F08(char *p);
void func_021E3F30(char *p);
void func_021E3F70(void *p);
void func_021E3F74(char *p);
void func_021E3FE4(char *p);
void func_021E4000(char *p);
void func_021E4068(char *p);
void func_021E40EC(char *p, int a1, int a2);
void func_021E4174(char *p);
unsigned short func_021E41A0(int i, int row, char *p, int mode);
int func_021E421C(char *p, int x, int y);
void func_021E42B4(char *p);
void func_021E4324(char *p, int d);
void func_021E43DC(char *p);
void func_021E4420(char *p);
void func_021E4570(char *p);
void func_021E4598(char *p);
void func_021E467C(char *p);
void func_021E4810(char *p, int n);
void func_021E4888(char *p);
void func_021E48E0(char *p);
void func_021E496C(int x, int y, unsigned short *out);
int func_021E4984(int v, int a, int b, char *p, int *out);
char *func_021E49DC(int a, int b, char *p);
void func_021E4A1C(char *p);
int func_021E4A84(char *p, int i);
int func_021E4AA4(int i, int x);
void func_021E4AB8(int a0, int a1, int a2);
void func_021E4AD0(char *p, int a1, int a2, int a3, int a4, int a5);
void func_021E4B00(char *p, int v, int a, int row, int flag);
int func_021E4DBC(char *p);
int func_021E4E0C(char *p, int *out);
void func_021E4E64(int a, char *p, int b);
void func_021E4F28(char *p);
void func_021E5098(char *p, int b);
s32_021E4F28 func_021E5158(s32_021E4F28 x);
void func_021E5164(int p);
int func_021E51A4(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow);
void func_021E5284(char *p,int mode);
void func_021E53CC(int p);
void func_021E53F8(char *p);
extern const char d_021E80C4[];
extern const Pair_021DF490 d_021E76D4;
extern const Pair_021DF59C d_021E76EC;
extern const Table_021DEA24 g_021E7844;
extern const Tbl d_021E7794;
extern s16_021DFBF0 FX_SinCosTable_[];
extern const char d_021E8130[];
extern const char d_021E8108[];
extern const char d_021E811C[];
extern const T5 d_021E7984;
extern const Pair_021DEA24 d_021E7934,d_021E7914,d_021E794C;
extern const Pair_021E1D68 d_021E7944, d_021E793C;
extern const Quad_021DEA24 d_021E7954,d_021E7964;
extern const Pair d_021E7924,d_021E791C,d_021E790C;
extern const Quad_021E2484 d_021E7974;
extern const char d_021E792C[];
extern const Config_021DEA24 d_021E7B1C;
extern char d_021E799C[];
extern void *d_021F4560;
extern short d_020A1DF8[];
extern char d_021E79C8[];
extern char d_021E81C0[];
extern Vec_021E3004 d_021E7AF4;
extern const s16_021E3004 d_020A1EB8[];
extern Callback d_021E7AC4[];
extern Fn tbl_021E7AC4[];
extern const Entry_021E324C d_021E7B3C[];
extern const Handler d_021E7AC8[];
extern Cfg d_021E8144;
extern Entry_021E33FC d_021E7B9C[4];
extern const Vec_021E35A0 data_021E7B00;
extern const Table_021E3004 data_021E7B0C;
extern u32_021DEA24 d_021E8178[];
extern u32_021DEA24 d_021E8168[];
extern const VecFx32_021E3A40 d_021E815C,d_021E79AC,d_021E8150;
extern const Template_021E3A40 d_021E7C0C;
extern const char d_021E7CE4[];
extern const char d_021E7D40[];
extern int d_021E7CC8;
extern const Tbl2 d_021E7DD0;
extern const unsigned char d_021E82A4[];
extern char d_021E8530[];
extern const BgTemplate d_021E7E24,d_021E7F44;










#define I(p, o) (*(void **)((p) + (o)))












static inline int poll(void) { int v=KEY_GetTrg(); if(v)func_020355D8(0); return v; }












/*
 * prototype: 02035C08 returns the r0 consumed by original after its forwarding call; matched 021D98AC documents full ARM9 forwarding proof.
 */
void func_021DEA24(char *p)
{
    int idx,sentinel;
    TOUCHBAR_Update(*(S_021DEA24 * *)&((TradeWork *)p)->f9C0);
    if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->f9C0)==1) {
        func_02045CAC(*(struct MsgBank * *)&((TradeWork *)p)->f720,148,(*(void * *)&((TradeWork *)p)->f738));
        func_021E1024(p);
        TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),1,0);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DE9E8);
        return;
    }
    sentinel=-1;
    if(TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((TradeWork *)p)->f9C0)==sentinel) {
        idx=TOUCHPANEL_HitTrg(d_021E80C4);
        if(idx!=sentinel) {
            func_020355D8(1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            func_021E68F4((int)p,sentinel);
            if(func_021DE754(p,idx)) return;
        }
        if(func_020355C4() && poll()) {
            ((TradeWork *)p)->f10A0%=6;
            if(((TradeWork *)p)->f10A0<0) ((TradeWork *)p)->f10A0=0;
            func_021E68F4((int)p,((TradeWork *)p)->f10A0);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return;
        }
        if(poll()==1) {
            if(func_021DE754(p,((TradeWork *)p)->f10A0)) return;
        }
        if(func_021DE208(p)) {
            func_021E68F4((int)p,((TradeWork *)p)->f10A0);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
}












void func_021DEB34(void *p)
{
    int v;
    if(func_021DD140(p) && func_021E12AC(p)) {
        v=KEY_GetTrg();
        if(v) func_020355D8(0);
        if(v==0) {
            v=TOUCHPANEL_GetTrg();
            if(v) func_020355D8(1);
            if(v==0) return;
        }
        if(func_020355C4()) func_021E68F4((int)p,-1);
        else func_021E68F4((int)p,0);
        func_021E1098(p);
        func_021D8980(p);
        func_021D8E84(p,(int)func_021DEA24);
    }
}













void func_021DEBA0(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x91, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    *(p + 0x11F1) = 0x78;
    func_021D8E84(p, (int)func_021DEB34);
}












static inline void inside(int wnd,int effect) {u32_021DEBD4 tmp=(*(volatile u16 *)0x04001048 & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x04001048=(u16)tmp;}












static inline void outside(int wnd,int effect) {u32_021DEBD4 tmp=(*(volatile u16 *)0x0400104a & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x0400104a=(u16)tmp;}












/*
 * volatile: hardware WININ 0x04001048, WINOUT 0x0400104A and DISPCNT 0x04001000 read-modify-written at 0x021DEBE8/0x021DEBF8, 0x021DEC0C/0x021DEC18, 0x021DEC1A/0x021DEC22.
 */
void func_021DEBD4(void *p) {
 func_0207D658(0x04001050,27,-8);
 inside(31,1);
 *(volatile u16 *)0x04001040=0x80ff;
 *(volatile u16 *)0x04001044=0xa9;
 outside(31,0);
 *(volatile u32_021DEBD4 *)0x04001000=(*(volatile u32_021DEBD4 *)0x04001000 & ~0xe000)|0x2000;
 func_02040588(3,1);func_02040588(5,1);func_02040588(4,1);
}












void func_021DEC4C(void *p) {
 if(func_021E69C0(p)) {
  if(func_020355C4()) {func_021E68F4((int)p,-1);((TradeWork *)p)->f10A0=0;}
  else {func_021E68F4((int)p,0);((TradeWork *)p)->f10A0=0;}
  if(WIPE_SYS_EndCheck()) {func_021DEBD4(p);func_021D8E84(p,(int)func_021DEBA0);}
 }
}












void func_021DECA0(char *p) {
 func_021E4000(p);func_021DF7D0(p);func_021DF8E0(p);func_021E64B8(p);func_021DD588(p);func_021E4570(p);func_021DD9DC((unsigned char *)p);func_021E4888(p);
 func_021DD528(p,1);func_02041570(6,0);CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04,0);
 func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,1);TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->f9C0),1,0);func_021E24E8(p,6);
 ((TradeWork *)p)->f108C=0;((TradeWork *)p)->f1084=1;func_021E6B90(p);
 WIPE_SYS_Start(0,1,1,0,6,1,((TradeWork *)p)->f5F4);func_021D8E84(p,(int)func_021DEC4C);
}













void func_021DED58(void *p)
{
    if (WIPE_SYS_EndCheck() != 0) {
        func_021D8E84(p, (int)func_021DECA0);
    }
}












void func_021DED74(void *p) {
 if(!func_021D8A24(p) || ((TradeWork *)p)->f1060) {
  WIPE_SYS_Start(0,0,0,0,6,1,((TradeWork *)p)->f5F4);
  func_021D8E84(p,(int)func_021DED58);
 }
}












void func_021DEDBC(void *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(func_021D8A24(p)) {
  b=1;
  if(GFL_NET_SendToHandle((void *)h,0xc0a,1,(u32_021DEDBC)(&b))) {func_021D8E84(p,(int)func_021DED74);return;}
 } else {func_021D8E84(p,(int)func_021DED74);}
}












void func_021DEE00(unsigned char *p) {
 int v;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,8)) {
  if(p[0x11e6]==0 && p[0x11e7]==0) {func_021D8E84(p,(int)func_021DEDBC);return;}
  if(p[0x11e6]==0xf0) v=0x9e;
  else if(p[0x11e6]==0xf1) v=0x9f;
  else if(p[0x11e6]==0xf2) v=0xa0;
  else if(p[0x11e6]==0xff) v=0xa1;
  else if((p[0x11e7]&0xf0)==0xf0) v=0xa1;
  else if(p[0x11e7]) v=0x8f;
  else v=0x90;
  func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),v,(void *)(((TradeWork *)p)->f738));
  func_021E1024(p);p[0x11f1]=120;((TradeWork *)p)->fF2C=0;
  func_021D8E84(p,(int)func_021DE8C0);
 }
}












void func_021DEEA8(void *p) {
 void *h=GFL_NET_HANDLE_GetCurrentHandle();
 ((TradeWork *)p)->f109A=0;
 if(GFL_NET_SendToHandle((void *)h,0xc11,1,(u32_021DEEA8)((char *)p+0x11e6))) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,8);
  if(((TradeWork *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(0);
  func_021D8E84(p,(int)func_021DEE00);
 }
}













void func_021DEEFC(void **p)
{
    if (*p != 0) {
        func_021B9774(*p);
        func_021B9838(*p);
        *p = 0;
        DWC_RAPCOMMON_DestroySubHeap();
    }
}












/*
 * lever: Nested success tests share the normal callback after the inner
 * guards. The bank allocation reads p+0x5f4 directly; the name allocation
 * reads the saved heap pointer, reproducing the original two load forms.
 * interface: 02019B58 receives the visibly loaded record pointer: its
 * empty 020185F0 call preserves r0 for 02019B64, which reads that input.
 */
void func_021DEF1C(u8 *p)
{
    int status, result, i, off1, off2;
    u8 n=0, error;
    u8 *data;
    const u16 *heap;
    void *mon, *bank, *text, *name;
    u32_021DEF1C value;
    status=func_021B99DC(*(u8 * *)&((TradeWork *)p)->f0);
    result=func_021B9790(*(u8 * *)&((TradeWork *)p)->f0);
    if(result==0) {
    if(status==200) {
        data=func_021B97F4(*(u8 * *)&((TradeWork *)p)->f0);
        p[0x11e6]=func_021B99F0(data);
        if(p[0x11e6]==1) {
            off1=0x109a;
            if(*(u16 *)(p+off1)==0) {
                i=n;
                heap=(const u16 *)(p+0x5f4);
                off2=off1;
                off2-=0xb6;
                off1-=0xb6;
                do {
                    if(func_021D89EC(*(void **)(p+i*4+off1))) {
                        mon=*(void **)(p+i*4+off2);
                        if(func_021B99F4((u32_021DEF1C)data,n)) {
                            value=func_02017E1C(mon,6,0);
                            bank=func_02045B38(0,2,81,((TradeWork *)p)->f5F4);
                            text=func_02045EC0(bank,15);
                            MSGDATA_Delete(bank);
                            if(func_0202136C(value)) {
                                name=MAIL_Create(*heap);
                                func_02017E1C(mon,167,(u32_021DEF1C)name);
                                func_02008F88(name,STRBUF_GetChars(text));
                                POKE_TOOL_SetPartyValue(mon,167,(u32_021DEF1C)name);
                                func_020307B0(name);
                            }
                            func_02019B58(mon);
                            POKE_TOOL_SetPartyValue(mon,142,(u32_021DEF1C)STRBUF_GetChars(text));
                            STRBUF_Delete(text);
                        }
                        n++;
                    }
                    i++;
                } while(i<3);
                ((TradeWork *)p)->f109A=1;
                func_021D8E84(p,(int)func_021DF0B8);
                goto cleanup;
            }
        }
        func_021D8E84(p,(int)func_021DEEA8);
    } else goto failed;
    } else goto failed;
    goto cleanup;
failed:
    {
        if(result==15 || status==200) return;
        switch(status) {
        case 400: error=240; break;
        case 401: error=241; break;
        case 408: error=242; break;
        default: error=255; break;
        }
        p[0x11e6]=error;
        func_021B9774(*(u8 * *)&((TradeWork *)p)->f0);
    }
    func_021D8E84(p,(int)func_021DEEA8);
cleanup:
    if(*(u8 * *)&((TradeWork *)p)->f0) {
        func_021B99B8(*(u8 * *)&((TradeWork *)p)->f0);
        func_021B9838(*(u8 * *)&((TradeWork *)p)->f0);
        *(u8 * *)&((TradeWork *)p)->f0=0;
        DWC_RAPCOMMON_DestroySubHeap();
        DWC_RAP_SetErrorCallback(0,0);
    }
}












void func_021DF0B8(char *p) {
 int n=0;
 int i;
 DWC_RAPCOMMON_CreateSubHeapUnlimited(13,0x10000,((TradeWork *)p)->f5F4);
 *(u8 * *)&((TradeWork *)p)->f0=func_021B9800(((TradeWork *)p)->f5F4,func_0200853C((*(void * *)&((TradeWork *)p)->f830)),((struct Obj22746 *)(((TradeWork *)p)->f8))->f24);
 DWC_RAP_SetErrorCallback((int)func_021DEEFC,(int)p);
 for(i=0;i<3;i++) if(func_021D89EC(*(void **)(p+0xfe4+i*4))) n++;
 func_021B98A0(*(u8 * *)&((TradeWork *)p)->f0,((TradeWork *)p)->f5F4,func_020173EC()*n,2);
 for(i=0;i<3;i++) if(func_021D89EC(*(void **)(p+i*4+0xfe4))) func_021B98D8(*(u8 * *)&((TradeWork *)p)->f0,*(int *)(p+i*4+0xfe4),func_020173EC());
 func_021B98F8(*(u8 * *)&((TradeWork *)p)->f0);func_021B9748(*(u8 * *)&((TradeWork *)p)->f0);func_021D8E84(p,(int)func_021DEF1C);
}












/*
 * volatile: field p+0x11fa re-read at 0x021DF18E after store at 0x021DF18C.
 */
void func_021DF168(void *p) {
 if(WIPE_SYS_EndCheck()) {
  func_021E4888(p);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(4);
  ++*(volatile unsigned char *)&((TradeWork *)p)->f11FA;
  if(*(volatile unsigned char *)&((TradeWork *)p)->f11FA>=3) {func_021D89CC(p);func_021D8E84(p,(int)func_021D9434);return;}
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),31,8);func_021D8E84(p,(int)func_021DF0B8);
 }
}












void func_021DF1C8(void *p) {
 WIPE_SYS_Start((void *)4,0,0,0,6,1,((TradeWork *)p)->f5F4);
 if(((TradeWork *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(1);
 func_021D8E84(p,(int)func_021DF168);
}












void func_021DF210(char *p)
{
    unsigned a, b;
    volatile int v; /* memory-resident on purpose: the original keeps v in [sp] and reads it uninitialised on the fall-through path; a plain local takes r7 */
    a = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    b = 1 - a;
    if (!func_021D8A24(p)) {
        a = 0;
        b = 1;
    }
    if (func_021D8A24(p)) {
        if (!GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1A, 8)) {
            func_021DD24C(p);
            return;
        }
    }
    func_021DD294(p, 0, 0);
    ((TradeWork *)p)->f11EA = 0;
    ((TradeWork *)p)->f11E8 = 3;
    ((TradeWork *)p)->f11E9 = 3;
    if (*(unsigned char *)(p + a + 0x11E0) == 10 && *(unsigned char *)(p + b + 0x11E0) == 10) {
        func_021DD90C((u8 *)p, 0, 1, 1);
        func_021DD90C((u8 *)p, 1, 1, 1);
        if (((TradeWork *)p)->f118C == 3) {
            func_021D8E84(p, (int)func_021DF1C8);
        } else {
            func_021D8E84(p, (int)func_021DEDBC);
        }
        return;
    }
    if (*(unsigned char *)(p + a + 0x11E0) == 4 && *(unsigned char *)(p + b + 0x11E0) == 4) {
        ((struct Obj22747 *)(((TradeWork *)p)->f8))->f8 = 3;
        func_021D8E84(p, (int)func_021D9434);
        return;
    }
    if (*(unsigned char *)(p + b + 0x11E0) == 4) {
        v = 0x61;
    } else if (*(unsigned char *)(p + a + 0x11E0) == 4) {
        v = 0x66;
    }
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), v, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    ((TradeWork *)p)->f11E0 = 0;
    ((TradeWork *)p)->f11E1 = 0;
    ((TradeWork *)p)->f11E8 = 0;
    ((TradeWork *)p)->f11E9 = 0;
    func_021D8E84(p, (int)func_021DAEF0);
}












void func_021DF338(void *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(func_021D8A24(p)) {
  b=1;
  if(GFL_NET_SendToHandle((void *)h,0xc0f,1,(u32_021DF338)(&b))) {func_021D8E84(p,(int)func_021DF210);return;}
 } else {func_021D8E84(p,(int)func_021DF210);}
}












void func_021DF37C(u8 *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(func_021E12AC((char *)p)) {
  if(func_021D8A24(p)) {
   b=10;
   if(GFL_NET_SendToHandle((void *)h,0xc00,1,(u32_021DF37C)(&b))) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);
    func_021D8E84(p,(int)func_021DF338);return;
   }
  } else {p[0x11e0]=10;p[0x11e1]=10;func_021D8E84(p,(int)func_021DF338);}
 }
}












void func_021DF3E4(void *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if (func_021E12AC(p)) {
        func_021D8E84(p, (int)func_021DBBD0);
    }
}












void func_021DF404(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x88, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    ((TradeWork *)p)->f11F1 = 0x78;
    func_021D8E84(p, (int)func_021DF37C);
}












void func_021DF43C(void *p)
{
    int v;
    if (!APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))) return;
    v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    ((TradeWork *)p)->f64C=0;
    if (v==0) {func_021D8E84(p,(int)func_021DF404);return;}
    func_021E1098(p);
    func_021D8E84(p,(int)func_021DF3E4);
}












void func_021DF490(void *p)
{
    Pair_021DF490 t;
    if (func_021E12AC(p)) {
        t = d_021E76D4;
        func_021E131C(p, (int *)&t, 2, 0x20, 0xc);
        func_021D8E84(p, (int)func_021DF43C);
    }
}












void func_021DF4CC(char *p)
{
    GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()));
    if (func_021E12AC(p) && func_021DD140(p)) {
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),0x89,(void *)(((TradeWork *)p)->f738));
        func_021E1024(p);
        func_021D8E84(p,(int)func_021DF490);
    }
}












void func_021DF510(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x88, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    ((TradeWork *)p)->f11F1 = 0x78;
    func_021D8E84(p, (int)func_021DF4CC);
}












void func_021DF548(void *p)
{
    int v;
    if (!APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->f64C))) return;
    v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->f64C));
    func_021E12F8(p);
    func_021E1098(p);
    ((TradeWork *)p)->f64C=0;
    if (v==0) {func_021D8E84(p,(int)func_021DF510);return;}
    func_021E1098(p);
    func_021D8E84(p,(int)func_021DBBD0);
}












void func_021DF59C(void *p)
{
    Pair_021DF59C t;
    if (func_021E12AC(p)) {
        t = d_021E76EC;
        func_021E131C(p, (int *)&t, 2, 0x20, 0xc);
        func_021D8E84(p, (int)func_021DF548);
    }
}












void func_021DF5D8(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x87, (*(void * *)&((TradeWork *)p)->f738));
    func_021E1024(p);
    TOUCHBAR_SetButtonEnabled((*(void * *)&((TradeWork *)p)->f9C0), 1, 0);
    func_021D8E84(p, (int)func_021DF59C);
    func_021E26AC(p);
}












int func_021DF614(char *p,int a,int b)
{
    int x,y,i;
    x=func_021D8AF4(a,p);
    y=func_021D8B0C(a,b);
    if(((TradeWork *)p)->fF7C==y && ((TradeWork *)p)->fF80==x) return 1;
    if(func_021D8AA8(p)) {
        for(i=0;i<3;i++) {
            if(*(int *)(p+i*4+0xfa4)==-1) continue;
            if(y==*(int *)(p+i*4+0xfa4) && x==*(int *)(p+i*4+0xfbc)) return 1;
        }
    } else {
        if(((TradeWork *)p)->fF84==y && ((TradeWork *)p)->fF88==x && ((TradeWork *)p)->fF7C==-1 && ((TradeWork *)p)->fF80==-1) return 1;
    }
    return 0;
}












int func_021DF6B4(char *p, int a, int b)
{
    int x = func_021D8AF4(a, p);
    int y = func_021D8B0C(a, b);
    if (((TradeWork *)p)->fF94 == y && ((TradeWork *)p)->fF98 == x) {
        return 1;
    }
    return 0;
}












void func_021DF6EC(void *p)
{
    if (TOUCHPANEL_GetCont() == 0) {
        func_021D8E84(p, (int)func_021DBBD0);
    }
}













void func_021DF708(void *p)
{
    int v = func_021DD34C(p, ((TradeWork *)p)->fF98,
                          ((TradeWork *)p)->fF94);

    if (func_021D8A24(p) == 0 ||
        GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc0b, 4, (u32_021DF708)(&v)) != 0) {
        ((TradeWork *)p)->fF84 = -1;
        ((TradeWork *)p)->fF88 = -1;
        ((TradeWork *)p)->fF7C = -1;
        ((TradeWork *)p)->fF80 = -1;
        ((TradeWork *)p)->fF94 = -1;
        ((TradeWork *)p)->fF98 = -1;
        if (v != -1) {
            func_021DD4F4(p, 0, v);
            func_021E62D4(p, 0, v);
        }
        func_021D8E84(p, 0x021DF6ED);
    }
}













/*
 * Init the four sub-objects when the object is in the first state.
 */
void func_021DF78C(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        func_021E6718(p, i);
}













void func_021DF7AC(void *p, int a)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        func_021E6790(p, i, a);
}













void func_021DF7D0(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        func_021E67A8(p, i);
}












void func_021DF7F0(void *p)
{
    unsigned x,y;
    unsigned char slot;
    if (!func_021D8AA8(p)) return;
    if (!TOUCHPANEL_GetPointTrg(&x,&y)) return;
    if(x<8 || x>=104 || y<144 || y>=168) return;
    slot=(x-8)/24U;
    if(slot>=4) slot=3;
    func_021E67C4(p,slot);
    func_021DF8A0(p,slot,0);
    if(func_021D8A24(p)) GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc0d,1,(u32_021DF7F0)(&slot));
}













/*
 * Count the two arm timers down and re-arm the ones that expired.
 */
void func_021DF868(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 2; i++) {
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            continue;
        ((unsigned char *)p)[0x11e4 + i]--;
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            func_021E68B4((int)p, i);
    }
}












void func_021DF8A0(void *p, int a, int b)
{
    if (func_021D8AA8(p)) {
        func_021E67E0(p,a,b);
        ((unsigned char *)p+b)[0x11e4]=60;
        if (!GFL_USE_IsSeqPlaying(0x54a)) GFL_USE_PlaySeDefaultVolume(0x54a);
    }
}













/*
 * Reset the two sub-objects and the decoder when in the first state.
 */
void func_021DF8E0(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 2; i++)
        func_021E68B4((int)p, i);
    func_021E5868(p);
}













/*
 * Tear the object down when it is in the first state.
 */
void func_021DF904(void *p)
{
    if (func_021D8AA8(p))
        func_021E57FC((int)p);
}












void func_021DF918(void *p,int i,void *v)
{
    int one;
    func_021E6308(p,i,0);
    if (((unsigned char *)p+i)[0x11e2]) {
        func_021E293C(p,i);
        func_021E36D8(p,i);
    }
    func_021E6F0C(p,i,v);
    func_021E272C(p,i,v);
    one=1;
    func_02041B6C(1);
    func_021E36A8(p,i,one-i,v,one-i,one);
}












void func_021DF978(void *p)
{
    int i;
    for(i=0;i<2;i++) {
        if (((unsigned char *)p+i)[0x11e2]==0) continue;
        ((unsigned char *)p+i)[0x11e2]--;
        func_021E6308(p,i,0);
        if (((unsigned char *)p+i)[0x11e2]==0) {
            func_021E293C(p,i);
            func_02041300(1,0,(unsigned char)(i<<4),0,16,24,16);
            func_02041B6C(1);
            func_021E36D8(p,i);
            func_021E6308(p,i,1);
        }
    }
}












int func_021DF9E8(char *p,void *src,int kind)
{
    unsigned id;
    int one;
    id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
    if(((Flags *)(p+0x11fb))->low) return 0;
    MI_CpuCopy8(src,((TradeWork *)p)->f106C,func_020173EC());
    one=1;
    if(!(int)GFL_NET_SendData(id,255,(u16)kind,func_020173EC(),(u32_021DF9E8)(((TradeWork *)p)->f106C),(int)0,(int)0,(int)one)) return 0;
    ((Flags *)(p+0x11fb))->low=one;
    return one;
}













void func_021DFA60(u32_021DFA60 key)
{
    Table_021DEA24 local;
    unsigned int i;

    local = g_021E7844;
    for (i = 0; i < 25; i++)
        if (key == local.t[i].b)
            GFL_USE_PlaySeDefaultVolume(local.t[i].a);
}












void func_021DFA98(int key)
{
    Tbl t = d_021E7794;
    unsigned i;
    for (i = 0; i < 22; i++) {
        if (key == t.e[i].key) {
            GFL_USE_PlaySeDefaultVolume(t.e[i].id);
        }
    }
}













/*
 * Recursive MATCH unblocker: the non-SDK callee of ov119 func_021DFC28
 * (+0038) and a dependency of the func_021D7130 tree.  Copies two constant
 * eight-byte-record tables from 0x021E7754 (two records) and 0x021E7764 (six
 * records) to the stack, gates on two bytes of the second argument, then
 * calls GFL_USE_PlaySeDefaultVolume on each record whose id matches arg0.  Both table
 * addresses are literal pool words, so they carry no relocation; the byte at
 * +0x11ED picks the six-record table (the `== 0` arm is the fall-through, the
 * unsigned counter is what makes the loop `blo`, not `blt`).
 *
 * Addresses are Black-image addresses.
 */
void func_021DFAD0(int a0, u8 *a1)
{
    T2 t1 = *(T2 *)0x021E7754;
    T6 t2 = *(T6 *)0x021E7764;
    unsigned int i;

    if (a1[0x11EF] != 0)
        return;
    if (a1[0x11ED] == 0) {
        for (i = 0; i < 2; i++)
            if (a0 == t1.e[i].id)
                GFL_USE_PlaySeDefaultVolume(t1.e[i].fn);
    } else {
        for (i = 0; i < 6; i++)
            if (a0 == t2.e[i].id)
                GFL_USE_PlaySeDefaultVolume(t2.e[i].fn);
    }
}













void func_021DFB4C(void *p, void *a1, void *a2)
{
    u8 buf[12];

    MCSS_GetPosition((void *)(((struct Obj10368 *)p)->f0), (u32_021DFB4C *)buf);
    ((struct Obj10368 *)p)->f8 = 0;
    ((struct Obj10368 *)p)->f4 = (u32_021DFB4C)a1;
    MI_CpuCopy8(a2, (char *)p + 0x28, 0xC);
    MI_CpuCopy8(buf, (char *)p + 0x1C, 0xC);
}













/*
 * Addresses are Black-image addresses.
 */
void *func_021DFB84(void *a0, void *a1, void *a2, u32_021DFB84 heapId)
{
    void *r = sub_02030734(heapId, 0x38, 1, (const char *)0x021E80F4, 0xD2);

    ((struct Obj13906 *)r)->f0 = a0;
    func_021DFB4C(r, a1, a2);
    ((struct Obj13906 *)r)->fC = 0;
    return r;
}













/*
 * Recursive MATCH unblocker: the alloc + store callee named by the parked
 * ov118 func_021D6CC4 (+0014 / +001E... it is the same pokemontrade_mcss.c
 * helper family as ov119 0x021DFB84) and by all three ov119 0x021DFBxx
 * entries.  func_021DFB84 is the four-argument form (line 0xD2) and this is
 * the five-argument form (a3 stored at +0x34, line 0xE7); the heap id is the
 * fifth parameter and reaches the debug allocator through its own stack home
 * (`ldrh r0,[sp,#0x20]`, a u16), which is what forces the 8-byte frame.
 *
 * Addresses are Black-image addresses.
 */
void *func_021DFBB4(void *a0, void *a1, void *a2, void *a3, u16 heapId)
{
    void *r = sub_02030734(heapId, 0x38, 1, (const char *)0x021E80F4, 0xE7);

    ((struct Obj10369 *)r)->f0 = a0;
    func_021DFB4C(r, a1, a2);
    ((struct Obj10369 *)r)->fC = 0;
    ((struct Obj10369 *)r)->f34 = (u32_021DFBB4)a3;
    return r;
}













/*
 * Recursive MATCH unblocker: callee of the parked ov119 func_021DFC68
 * (+0044) and part of the func_021D7130 tree.  Interpolates between a0 and a1
 * at record stride (the difference divided by f04, scaled by f08), then, when
 * the record's f16 is set and a3 is nonzero, re-derives the position from the
 * sine table FX_SinCosTable_ with the phase f14>>4.  The divide's destination
 * only reproduces when the quotient is bound to its own local first
 * (`int q = ...; int r = q * a2->f08 + a0;`).
 *
 * Addresses are Black-image addresses.
 */
int func_021DFBF0(int a0, int a1, S_021DFBF0 *a2, int a3)
{
    int q = (a1 - a0) / a2->f04;
    int r = q * a2->f08 + a0;

    if (a2->f16 != 0 && a3 != 0)
        r = a1 + FX_SinCosTable_[2 * (a2->f14 >> 4)] * 8;
    return r;
}













/*
 * Recursive MATCH unblocker: callee of the parked ov119 func_021DFC68
 * (+0060) and of func_021D7130's tree.  Reads the descriptor at p->f34 +
 * 0xc*p->f08 and hands three offset-adjusted words to MCSS_SetPosition, then
 * forwards p->f08 and its own second argument to func_021DFAD0.
 *
 * Addresses are Black-image addresses.
 */
void func_021DFC28(P *p, int a1)
{
    u32_021DFC28 vec[3];
    int idx = p->f08;
    u32_021DFC28 *e = (u32_021DFC28 *)(p->f34 + idx * 0xc);

    vec[0] = e[0] + p->f1c;
    vec[1] = e[1] + p->f20;
    vec[2] = e[2] + p->f24;
    MCSS_SetPosition((void *)p->f00, vec);
    func_021DFAD0(p->f08, (u8 *)a1);
}













/*
 * 2026-10-02 lane R1: the register shift (r2/r3 instead of r1/r2) was the incoming r1 kept
 * live: the function takes a second argument and forwards it to func_021DFC28 (p, a1), whose
 * matched definition reads r1. Callers in ov118 pass two arguments.
 *
 * Addresses are Black-image addresses.
 */
void func_021DFC68(void *p, int a1)
{
    u32_021DFC68 vec[6];
    s32_021DFC68 k, next, m;

    if (p == 0)
        return;
    k = *(s32_021DFC68 *)&((struct Obj00826 *)p)->f8;
    next = k + 1;
    m = ((struct Obj00826 *)p)->f4;
    *(s32_021DFC68 *)&((struct Obj00826 *)p)->f8 = next;
    if (m < next)
        return;
    if (m != next) {
        if (((struct Obj00826 *)p)->f34 != 0) {
            func_021DFC28(p, a1);
            return;
        }
        MCSS_GetPosition((void *)(((struct Obj00826 *)p)->f0), &vec[0]);
        vec[3] = func_021DFBF0(((struct Obj00826 *)p)->f1C, ((struct Obj00826 *)p)->f28, p, 0);
        if (((struct Obj00826 *)p)->f16 != 0) {
            float q = 374.0f * __fdiv(_s32_to_float((s32_021DFC68)(vec[0] - vec[3])), 4096.0f);
            ((struct Obj00826 *)p)->f14 -= (u16)_f2s(q);
        }
        vec[4] = func_021DFBF0(((struct Obj00826 *)p)->f20, ((struct Obj00826 *)p)->f2C, p, 1);
        vec[5] = func_021DFBF0(((struct Obj00826 *)p)->f24, ((struct Obj00826 *)p)->f30, p, 0);
        MCSS_SetPosition((void *)(((struct Obj00826 *)p)->f0), &vec[3]);
        return;
    }
    MCSS_SetPosition((void *)(((struct Obj00826 *)p)->f0), (u32_021DFC68 *)((char *)p + 0x28));
}













void func_021DFD0C(char *p)
{
    MCSS_SetAnmStopFlag((void *)(((TradeWork *)p)->f844));
    ((TradeWork *)p)->f854 = 1;
}












void func_021DFD24(u32_021DFD24 *p) { if (p) { func_020307B0((void *)((u32_021DFD24)p)); } }













void func_021DFD30(u8 *p, u32_021DFD30 v) { (*(unsigned int *)&((TradeWork *)p)->fF2C) = v; }













/*
 * Decrement the +0x11f8 guard byte (both its condition and the store use
 * that same pool word) and pulse the 0x3c delay. Non-SDK dep of
 * func_021DFDA0's case-5/6 arms.
 *
 * Addresses are Black-image addresses.
 */
void func_021DFD3C(void *p)
{
    u8 *b = p;

    if (((TradeWork *)b)->f11F8 != 0) {
        GFL_USE_PopBgm();
        ((TradeWork *)b)->f11F8 -= 1;
        GFL_USE_SetBgmPlayerParam(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}













void func_021DFD64(void *p)
{
    u8 *b = p;

    GFL_USE_PopBgm();
    ((TradeWork *)b)->f11F8 -= 1;
}













void func_021DFD7C(void *p)
{
    u8 *b = p;

    GFL_USE_PopBgm();
    ((TradeWork *)b)->f11F8 -= 1;
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(0x18);
}













/*
 * Slot-state teardown/rebuild, dispatched on *(p+0x118c): 5 and 6 run the
 * shared +8 slot teardown and hand func_021D8E84 either func_021D9434 or
 * NULL; the default path increments the +0x11f8 byte and hands
 * func_021DFE48. Target of func_021D6C78's ABS32 callback argument (ov119).
 *
 * Addresses are Black-image addresses.
 */
void func_021DFDA0(void *p)
{
    u8 *b = p;
    int st;

    CLACT_DeleteUnit((*(void * *)&((TradeWork *)b)->f9C4));
    CLACT_ExitSystem();
    func_021E3E60(p);
    (*(void * *)&((TradeWork *)b)->f9C4) = CLACT_CreateUnit(0x154, 0, ((TradeWork *)b)->f5F4);
    st = ((TradeWork *)b)->f118C;
    if (st == 5) {
        func_021DFD3C(p);
        ((struct Obj22751 *)(*(int * *)&((TradeWork *)b)->f8))->f8 = 3;
        func_021D8E84(p, (int)func_021D9434);
    } else if (st == 6) {
        func_021DFD3C(p);
        ((struct Obj22752 *)(*(int * *)&((TradeWork *)b)->f8))->f8 = 3;
        func_021D8E84(p, 0);
    } else {
        func_021E10D8(p);
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        (((TradeWork *)b)->f11F8)++;
        GFL_USE_FadeOutBgm(6);
        ((TradeWork *)b)->fF2C = 0;
        func_021D8E84(p, (int)func_021DFE48);
    }
}












/*
 * lever: Repeat the message call in each arm; an id local factors the argument loads and is 20 bytes short.
 */
void func_021DFE48(char *p)
{
    void *mon;
    int z,state;
    if(((TradeWork *)p)->fF2C<6) return;
    GFL_USE_CancelChangeAndPlayBgm(0x518,0xffff);
    GFL_USE_FadeInBgmFull(6);
    state=((TradeWork *)p)->f118C;
    if(state==7) func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),153,(void *)((*(int *)&((TradeWork *)p)->f73C)));
    else if(state==8) func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),156,(void *)((*(int *)&((TradeWork *)p)->f73C)));
    else if(((TradeWork *)p)->f11EE) func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),131,(void *)((*(int *)&((TradeWork *)p)->f73C)));
    else func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),48,(void *)((*(int *)&((TradeWork *)p)->f73C)));
    if(func_021D8AA8(p)) mon=func_021D8FA4(p,0);
    else mon=func_021D8FA4(p,1);
    func_0201EEF4((*(void * *)&((TradeWork *)p)->f724),1,mon);
    z=0;
    func_0201F02C((struct WordSet *)(((TradeWork *)p)->f724),0,(void *)(((TradeWork *)p)->f834));
    func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f738),(void *)((*(int *)&((TradeWork *)p)->f73C)));
    (*(int *)&((TradeWork *)p)->f644)=(int)func_0201F5DC((void *)6,15,0,((TradeWork *)p)->f5F4);
    func_021E0FF4(p,1,0);
    func_021DFD30((u8 *)p,0);
    func_02040588(6,1);
    ((TradeWork *)p)->fF2C=z;
    func_021D8E84(p,(int)func_021DFF40);
}












/*
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 */
void func_021DFF40(char *p)
{
    void *a;
    if (((TradeWork *)p)->fF2C < 0xC8) {
        return;
    }
    if (func_021D8AA8(p)) {
        a = func_021D8FA4(p, 0);
    } else {
        a = func_021D8FA4(p, 1);
    }
    func_0201EEF4((*(void * *)&((TradeWork *)p)->f724), 1, a);
    func_0201F02C((*(void * *)&((TradeWork *)p)->f724), 0, (void *)(((TradeWork *)p)->f834));
    if (((TradeWork *)p)->f118C != 7 && ((TradeWork *)p)->f118C != 8) {
        if (((TradeWork *)p)->f11EE) {
            func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x84, ((TradeWork *)p)->f73C);
            func_0201F250((*(void * *)&((TradeWork *)p)->f724), (*(void * *)&((TradeWork *)p)->f738), ((TradeWork *)p)->f73C);
            func_021E0FF4(p, 1, 0);
        } else {
            func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x31, ((TradeWork *)p)->f73C);
            func_0201F250((*(void * *)&((TradeWork *)p)->f724), (*(void * *)&((TradeWork *)p)->f738), ((TradeWork *)p)->f73C);
            func_021E0FF4(p, 1, 0);
        }
    }
    func_021D8E84(p, (int)func_021DFFE0);
}













void func_021DFFE0(char *p)
{
    if (((TradeWork *)p)->fF2C >= 0x10e) {
        func_021DFD7C(p);
        func_021D8E84(p, (int)func_021E0008);
    }
}













void func_021E0008(char *p)
{
    if (((TradeWork *)p)->fF2C >= 0x1a4) {
        func_021DFD30((u8 *)p, 0);
        func_021D8E84(p, (int)func_021E08E8);
    }
}













void func_021E0030(void *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, 8)) {
        func_021D8E84(p, (int)func_021E0980);
    }
}












void func_021E0054(char *p)
{
    struct Packet packet;
    void *saved,*first,*second;
    saved=func_02009470(GAME_DATA_GetSaveControl(((TradeWork *)p)->f82C));
    if(func_021D8AA8(p)) {
        first=func_021D8FA4(p,0);
        second=func_021D8FA4(p,1);
    } else {
        first=func_021D8FA4(p,1);
        second=func_021D8FA4(p,0);
    }
    MYSTATUS_Copy(func_02012944(((TradeWork *)p)->f82C),&packet);
    packet.first=func_02017E1C(first,5,0);
    packet.second=func_02017E1C(second,5,0);
    packet.a=func_02009628(saved);
    packet.b=func_02009584(saved);
    packet.mode=func_0200960C(saved);
    if(func_021D8A24(p)) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc12,40,(u32_021DEA24)(&packet))) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),23,8);
            func_021D8E84(p,(int)func_021E0030);
            return;
        }
    } else func_021D8E84(p,(int)func_021E0C78);
}













static inline void GFL_STD_MemCopy(const void *src, void *dst, u32_021DEA24 size)
{
    MI_CpuCopy8(src, dst, size);
}













void *func_021E0138(void *sys, u16 heapId)
{
    void *h = GAME_DATA_GetSaveControl(sys);
    void *buf = sub_02030734(heapId, sub_02009454(), 0, d_021E8130, 0x1A0);

    GFL_STD_MemCopy(func_02009470(h), buf, sub_02009454());
    return buf;
}












void func_021E017C(void *sys, void *buf)
{
    void *src = func_02009470(GAME_DATA_GetSaveControl(sys));
    func_02082D44(buf, src, sub_02009454());
    func_020307B0(buf);
}













void *func_021E01A0(void *src, u16 heapId)
{
    void *buf = sub_02030734(heapId, func_0200C9EC(), 0, d_021E8130, 0x1BD);

    GFL_STD_MemCopy(func_0200CA1C(src), buf, func_0200C9EC());
    return buf;
}












void func_021E01E0(void *h, void *buf)
{
    void *src = func_0200CA1C(h);
    func_02082D44(buf, src, func_0200C9EC());
    func_020307B0(buf);
}













void *func_021E0200(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02009D9C(), 0, d_021E8130, 0x1DA);

    GFL_STD_MemCopy(GAME_DATA_GetSaveBlock1F(sys), buf, sub_02009D9C());
    return buf;
}












void func_021E0240(void **h, void *dst)
{
    void *src = GAME_DATA_GetSaveBlock1F(h);
    func_02082D44(dst, src, func_02009D9C());
    func_020307B0(dst);
}












void func_021E0260(char *p)
{
    int zero;
    if (((TradeWork *)p)->f60C) func_020307B0(((TradeWork *)p)->f60C);
    if (((TradeWork *)p)->f610) func_020307B0(((TradeWork *)p)->f610);
    if (((TradeWork *)p)->f614) func_020307B0(((TradeWork *)p)->f614);
    if (((TradeWork *)p)->f618) func_020307B0(((TradeWork *)p)->f618);
    if (((TradeWork *)p)->f61C) func_020307B0(((TradeWork *)p)->f61C);
    if (((TradeWork *)p)->f620) func_020307B0(((TradeWork *)p)->f620);
    if (((TradeWork *)p)->f624) func_020307B0(((TradeWork *)p)->f624);
    zero=0;
    MI_CpuFill8(p+0x60c,zero,36);
    p[0x11f7]=zero;
}












void func_021E02E8(char *p)
{
    void *dest,*src;
    u32_021DEA24 n;
    dest=((TradeWork *)p)->f60C;
    if(dest) {
        src=((TradeWork *)p)->f82C;
        GAME_DATA_GetSaveControl(src);
        src=func_02008FEC(src);
        n=func_02008FFC();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    dest=((TradeWork *)p)->f610;
    if(dest) {
        src=GAME_DATA_GetTrainerRecord(((TradeWork *)p)->f82C);
        n=func_02008C20();
        func_02082D44(dest,src,n);
        func_020307B0(dest);
    }
    if(((TradeWork *)p)->f614) func_021E017C(((TradeWork *)p)->f82C,((TradeWork *)p)->f614);
    if(((TradeWork *)p)->f618) func_021E01E0(((TradeWork *)p)->f82C,((TradeWork *)p)->f618);
    if(((TradeWork *)p)->f61C) func_021E0240(((TradeWork *)p)->f82C,((TradeWork *)p)->f61C);
    if(((TradeWork *)p)->f620) {
        POKEPARTY_Copy(((TradeWork *)p)->f620,((TradeWork *)p)->f838);
        func_020086F8((void *)GAME_DATA_GetPlayTime((int)(((TradeWork *)p)->f82C)),(const struct PlayTimeStamp *)(p+0x628));
        func_020307B0(((TradeWork *)p)->f620);
        *(int *)&((TradeWork *)p)->f620=0;
    }
    if(((TradeWork *)p)->f624) {
        n=func_02007AEC();
        src=func_02007AF4((*(void * *)&((TradeWork *)p)->f828),((struct Obj22755 *)(((TradeWork *)p)->f8))->f28);
        func_02082D44(((TradeWork *)p)->f624,src,n);
        func_020307B0(((TradeWork *)p)->f624);
    }
    if(((TradeWork *)p)->f62C) func_02007B5C((struct PerapVoice *)GAME_DATA_GetBoxSave(((TradeWork *)p)->f82C));
    MI_CpuFill8(p+0x60c,0,0x24);
}













int func_021E0410(char *p, void *party, int idx)
{
    int count = 0;
    int i, n;
    void *voice = GAME_DATA_GetBoxSave(((TradeWork *)p)->f82C);

    if (!PERAPVOICE_IsRecorded(voice))
        return count;
    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(POKEPARTY_GetMember(party, i), 5, 0) == 0x1B9)
            count++;
    }
    if (count != 1)
        return 0;
    count = 0;
    if (func_02017E1C(POKEPARTY_GetMember(party, idx), 5, 0) == 0x1B9) {
        PERAPVOICE_ClearRecorded(voice);
        return 1;
    }
    return count;
}













static inline void *copy_a(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, MAIL_GetBoxSize(), 0, d_021E811C, 0x163);

    GFL_STD_MemCopy(MAIL_GetBox(sys), buf, MAIL_GetBoxSize());
    return buf;
}













static inline void *copy_b(void *sys, u16 heapId)
{
    void *buf = sub_02030734(heapId, sub_02008C20(), 0, d_021E8108, 0x182);

    GFL_STD_MemCopy(GAME_DATA_GetTrainerRecord(sys), buf, sub_02008C20());
    return buf;
}













/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * pokemontrade_save.c.  The first two buffer copies are inlined statics
 * (their arguments are spilled before the body, and each carries its own
 * copy of the __FILE__ string); the rest call the out-of-line copies.
 * Every copy goes through the GFL_STD_MemCopy inline wrapper, whose
 * arguments are evaluated last to first: the size call, then the
 * destination load, then the source call.
 *
 * Addresses are Black-image addresses.
 */
void func_021E049C(char *p)
{
    void *mon;
    void *obj;
    void *list[2];
    int i;
    int out;

    if (func_021D8AA8(p) == 0) {
        I(p, 0x60C) = copy_a(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x610) = copy_b(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x614) = func_021E0138(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x618) = func_021E01A0(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x61C) = func_021E0200(I(p, 0x82C), H(p, 0x5F4));
        PLAYTIME_GetStamp((void *)GAME_DATA_GetPlayTime((int)I(p, 0x82C)), (struct PlayTimeStamp *)(p + 0x628));
        if (T(p)->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            I(p, 0x620) = POKEPARTY_Create(H(p, 0x5F4));
            POKEPARTY_Copy(I(p, 0x838), I(p, 0x620));
            W(p, 0x62C) = func_021E0410(p, I(p, 0x838), T(p)->slot);
        } else {
            I(p, 0x624) = sub_02030734(H(p, 0x5F4), BOX_SAVEDATA_GetBoxPageSize(), 0, d_021E8130, 0x271);
            GFL_STD_MemCopy(BOX_SAVEDATA_GetBoxPokemon(I(p, 0x828), T(p)->box), I(p, 0x624), BOX_SAVEDATA_GetBoxPageSize());
        }
    } else {
        Trade *t = T(p);
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828)))
            func_021E0410(p, I(p, 0x838), t->slot);
        p[0x11F7] = 1;
    }

    {
        Trade *t = T(p);
        if (t->box != BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            mon = POKEPARTY_GetMember(t->party, 0);
            if (func_0202136C(func_02017E1C(mon, 6, 0))) {
                void *o = MAIL_GetBox(I(p, 0x82C));
                int idx = MAIL_FindEmptySlot(o, 0);
                if (idx != -1) {
                    void *buf = MAIL_Create(H(p, 0x5F4));
                    func_02017E1C(mon, 0xA7, (u32_021DEA24)buf);
                    MAIL_SetSlot(o, 0, idx, buf);
                    func_02008EAC(buf);
                    POKE_TOOL_SetPartyValue(mon, 0xA7, (u32_021DEA24)buf);
                    POKE_TOOL_SetPartyValue(mon, 6, 0);
                    func_020307B0(buf);
                }
            }
        }
    }

    {
        u8 a = func_0200856C(I(p, 0x834));
        u8 b = func_02008570(I(p, 0x834));
        u32_021DEA24 ra = func_02025C1C(a, b, func_02008564(I(p, 0x834)));
        u32_021DEA24 rb = func_02025C30(a, b, func_02008564(I(p, 0x834)));
        if (a != ra || b != rb)
            func_02008574(I(p, 0x834), 0, 0);
    }

    sub_02009DE8(GAME_DATA_GetSaveBlock1F(I(p, 0x82C)), I(p, 0x834));
    obj = func_02009470(GAME_DATA_GetSaveControl(I(p, 0x82C)));
    list[0] = I(p, 0x830);
    list[1] = I(p, 0x834);
    for (i = 0; i < 2; i++) {
        void *q = list[i];
        if (q) {
            u8 row = func_0200856C(q);
            u8 col = func_02008570(q);
            func_02008564(q);
            if (!sub_0200949C(obj, row, col))
                sub_020094D8(obj, row, col, 1);
        }
    }

    mon = POKEPARTY_GetMember(T(p)->party, 0);
    obj = GAME_DATA_GetTrainerRecord(I(p, 0x82C));
    POKE_TOOL_HealFull(mon);
    if (func_02017E1C(mon, 0x4C, 0) == 0)
        POKE_TOOL_SetPartyValue(mon, 9, (u32_021DEA24)((void *)0x46));
    if (func_02017E1C(mon, 0x4C, 0))
        func_0202F190(mon, 6, (u32_021DEA24)I(p, 0x830), 0x7533, H(p, 0x5F4));
    switch (W(p, 0x118C)) {
    case 2:
    case 3:
        sub_02008DF0(obj, 0x10);
        break;
    case 1:
        sub_02008DF0(obj, 0xC);
        break;
    case 0:
        sub_02008DF0(obj, 0x24);
        break;
    }
    func_0200CDE0(func_0200CA1C(I(p, 0x82C)), mon);
    if (W(p, 0x118C) == 3)
        sub_02009EB0(GAME_DATA_GetSaveBlock1F(I(p, 0x82C)));
    if (func_02017E1C(mon, 5, 0) == 0x1EC && func_02017E1C(mon, 0x6F, 0) == 1) {
        POKE_TOOL_ChangeForm(mon, 0);
        func_0200CDE0(func_0200CA1C(I(p, 0x82C)), mon);
    }
    {
        Trade *t = T(p);
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            POKEPARTY_SetMember(I(p, 0x838), t->slot, mon);
        } else {
            t = T(p);
            func_020075B0(I(p, 0x828), t->box, t->slot, POKE_TOOL_GetBoxParam(mon));
        }
    }
    switch (W(p, 0x118C)) {
    case 2:
        sub_02009BB8((void *)sub_0201283C(I(p, 0x82C)), T(p)->count - 1, 0, 0, 1);
        break;
    case 0:
    case 1:
        if (sub_02009D1C((void *)sub_0201283C(I(p, 0x82C)), I(p, 0x834), (u32_021DEA24 *)(&out)))
            sub_02009BB8((void *)sub_0201283C(I(p, 0x82C)), out, 0, 0, 1);
        break;
    }
}












void func_021E08E8(char *p)
{
    int state;
    func_021E36D8(p,0);func_021E36D8(p,1);
    func_021E36D8(p,2);func_021E36D8(p,3);
    state=((TradeWork *)p)->f118C;
    if(state==4 || (unsigned)(state-7)<=1) {
        ((struct Obj22758 *)(((TradeWork *)p)->f8))->f8=3;
        func_021DFD3C(p);
        func_021D8E84(p,(int)func_021D9434);
        return;
    }
    if((unsigned)(state-1)<=2) {
        func_021D8E84(p,(int)func_021E0054);
        return;
    } else {
        func_021D8E84(p,(int)func_021E0980);
        return;
    }
}












void func_021E0958(char *p)
{
    if (func_021E12AC(p) && ((TradeWork *)p)->fF2C > 0xB4) {
        func_021D8E84(p, (int)func_021E0A64);
    }
}












void func_021E0980(char *p)
{
    int i;
    void *mon;
    int z;
    char *t;
    if(func_021D8AA8(p)) {
        i=((TradeWork *)p)->fFA0%3;
        mon=func_021D8FA4(p,0);
        ((struct Obj22760 *)(((TradeWork *)p)->f8))->f28=*(int *)(p+i*4+0xfbc);
        ((struct Obj22761 *)(((TradeWork *)p)->f8))->f2A=*(int *)(p+i*4+0xfa4);
    } else {
        mon=func_021D8FA4(p,1);
        ((struct Obj22762 *)(((TradeWork *)p)->f8))->f28=((TradeWork *)p)->fF88;
        ((struct Obj22763 *)(((TradeWork *)p)->f8))->f2A=((TradeWork *)p)->fF84;
    }
    POKEPARTY_InitEx(((struct Obj22764 *)(((TradeWork *)p)->f8))->f1C,6);
    POKEPARTY_Add(((struct Obj22765 *)(((TradeWork *)p)->f8))->f1C,mon);
    func_0200CDE0(func_0200CA1C(((TradeWork *)p)->f82C),mon);
    t=((TradeWork *)p)->f8;
    if(((struct Obj13908 *)t)->f28!=func_020076A4((*(void * *)&((TradeWork *)p)->f828))) {
        z=0;
        if(func_0202136C(func_02017E1C(POKEPARTY_GetMember(((struct Obj13908 *)t)->f1C,0),6,0))) {
            func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),106,(void *)(((TradeWork *)p)->f738));
            func_021E1024(p);
            func_021D8E84(p,(int)func_021E0958);
            ((TradeWork *)p)->fF2C=z;
            return;
        }
    }
    func_021D8E84(p,(int)func_021E0A64);
}












/*
 * lever: Repeat callback calls, then goto the shared teardown; callback local shifts the join by two bytes.
 */
void func_021E0A64(char *p)
{
    void *a,*b;
    u32_021DEA24 out,result;
    if(*(int *)&((TradeWork *)p)->f82C==0) {
        func_021D8E84(p,(int)func_021E0C78);
        goto exit;
    }
    else {
    if(*(int *)&((TradeWork *)p)->f8!=0) {
        if(func_021D8AA8(p)) {a=func_021D8FA4(p,0);b=func_021D8FA4(p,1);}
        else {a=func_021D8FA4(p,1);b=func_021D8FA4(p,0);}
        result=SHINKA_CHECK_CheckEvolution(0,a,1,(u32_021DEA24)b,func_02012984(((TradeWork *)p)->f82C),&out,((TradeWork *)p)->f5F4);
        if(result) {
            ((struct Obj22766 *)(((TradeWork *)p)->f8))->f8=1;
            ((struct Obj22767 *)(((TradeWork *)p)->f8))->fC=result;
            ((struct Obj22768 *)(((TradeWork *)p)->f8))->f10=out;
            func_021D8E84(p,(int)func_021D9434);
            func_021DFD64(p);
            return;
        }
    }
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),50,(void *)(((TradeWork *)p)->f738));
    func_021E1024(p);func_021E1030(p);
    func_021D8E84(p,(int)func_021E0BA4);
    }
exit:
    func_021DFD3C(p);
}












void func_021E0B34(char *p) {func_021E10D8(p);func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),50,(void *)(((TradeWork *)p)->f738));*(int *)&((TradeWork *)p)->f644=(int)func_0201F5DC((void *)6,15,0,((TradeWork *)p)->f5F4);func_021E1024(p);func_021E1030(p);func_021DFD30((u8 *)p,0);func_02040588(6,1);GFL_NET_RestartWithDefaultTimeout(1,((TradeWork *)p)->f5F4);FADE_Start(3,16,0,2);func_021D8E84(p,(int)func_021E0BA4);}












void func_021E0BA4(void *p)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8);
    func_021D8E84(p, (int)func_021E0BC4);
}












void func_021E0BC4(void *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8)) {
        func_021D8E84(p, (int)func_021E0BE8);
    }
}












void func_021E0BE8(char *p) {if(func_021E12AC(p)) {if(func_021D8A24(p)) {func_021E049C(p);((TradeWork *)p)->fEF8=(int)func_020108C4(((TradeWork *)p)->f5F4,*(int *)&((TradeWork *)p)->f82C,(u32_021DEA24)func_021E0260,(u32_021DEA24)p);func_021D8E84(p,(int)func_021E0C44);return;}func_021D8E84(p,(int)func_021E0C78);}}












/*
 * 2026-10-02: byte-correct; the call to the tail-call stub 0x02010934 (inside
 * matched unit_0201088C) now resolves since that stub was seeded as a start.
 */
void func_021E0C44(char *p)
{
    if (func_02010904((*(void * *)&((TradeWork *)p)->fEF8))) {
        func_021E02E8(p);
        func_02010934((*(void * *)&((TradeWork *)p)->fEF8));
        ((TradeWork *)p)->fEF8 = 0;
        func_021D8E84(p, (int)func_021E0C78);
    }
}












void func_021E0C78(char *p) {int z;WIPE_SYS_Start(0,0,0,0,6,1,((TradeWork *)p)->f5F4);z=0;((TradeWork *)p)->fF2C=z;p[0x11f7]=z;func_021D8E84(p,(int)func_021E0CC0);}












void func_021E0CC0(char *p)
{
    if(((TradeWork *)p)->fF2C>=6 && WIPE_SYS_EndCheck()) {
        if(((TradeWork *)p)->f644) func_0203FB44((int)6,(u16)(((TradeWork *)p)->f644),(u16)(((TradeWork *)p)->f644>>16));
        *(int *)&((TradeWork *)p)->f644=0;
        BG_SYS_SetMainVisiblePlanes((int)0);BG_SYS_SetSubVisiblePlanes((int)0);
        CLACT_DeleteUnit((*(void * *)&((TradeWork *)p)->f9C4));
        (*(void * *)&((TradeWork *)p)->f9C4)=CLACT_CreateUnit(0x154,0,((TradeWork *)p)->f5F4);
        func_021E106C(p);func_021E57A4((int)p);func_021E53CC((int)p);
        func_021E57E8(0);func_021E5680(p);func_021E58A0((int)p);
        func_021E467C(p);func_021E4420(p);func_021E3E80(p);
        func_021E3FE4(p);func_021E3F74(p);func_021E3208(p,0);
        BG_SYS_SetMainVisiblePlanes((int)31);BG_SYS_SetSubVisiblePlanes((int)30);func_021E3C20(p);
        GFL_NET_RestartWithDefaultTimeout(1,((TradeWork *)p)->f5F4);
        ((TradeWork *)p)->f11FA=0;
        func_021D8E84(p,(int)func_021DACE4);
    }
}












void func_021E0DA0(char *p)
{
    if (((struct Obj10373 *)p)->f10) {
        CLACT_DeleteActor(((struct Obj10373 *)p)->f10);
        *(int *)&((struct Obj10373 *)p)->f10 = 0;
        UI_SCENE_FreeActorGfx((unsigned int *)p);
    }
}












void func_021E0DBC(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b) {Descriptor d;u8 v;int z=0;v=func_02017E1C(mon,index+174,0);d.a=a;d.b=z;d.c=func_020275E4();d.d=func_020275E8();d.e=func_020275F8(v);d.f=func_020275FC(2);d.g=func_02027600(2);d.h=8;d.i=z;d.j=3;UI_SCENE_LoadActorGfx(p,&d,slot,b);((struct Obj13909 *)p)->f10=UI_SCENE_CreateActor(p,slot,x,y,z,b);CLACT_SetActorPaletteOffset((struct Obj *)(((struct Obj13909 *)p)->f10),func_020275EC(v),1);}












void func_021E0E4C(char *p)
{
    if (((struct Obj08064 *)p)->f10) {
        CLACT_DeleteActor(((struct Obj08064 *)p)->f10);
        *(int *)&((struct Obj08064 *)p)->f10 = 0;
        UI_SCENE_FreeActorGfx((unsigned int *)p);
    }
}












/*
 * extent: two zero alignment bytes at 0x021E0EF2, labelled next function 0x021E0EF4.
 */
void func_021E0E68(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c) {Descriptor d;int v;v=func_02017E1C(mon,152,0);func_021E0E4C(p);d.a=a;d.b=0;d.c=func_020275E4();d.d=func_02027720(v);d.e=func_0202772C(v);d.f=func_02027738(v,2);d.g=func_02027740(v,2);d.h=c;d.i=0;d.j=1;UI_SCENE_LoadActorGfx(p,&d,slot,b);*(int *)&((struct Obj08064 *)p)->f10=UI_SCENE_CreateActor(p,slot,x,y,0,b);}












/*
 * prototype: 0201F73C arg2 is u16 because 021E0FC4..021E0FC6 truncates the loaded full word before the call.
 * prototype: 0201CCE4 forwarding wrapper leaves r0 live; caller stores it at 021E0F94 despite legacy void declaration.
 */
void func_021E0EF4(char *p,int flag,int x,int y,int w,int h)
{
    void *v;
    func_021E106C(p);
    func_02049B40(23,5,4,448,32,((TradeWork *)p)->f5F4);
    v=(void *)BMP_WIN_Create(6,(u8)x,(u8)y,(u8)w,h,(u32_021DEA24)14,(u32_021DEA24)0);
    (*(void * *)&((TradeWork *)p)->f71C)=v;
    BMP_Clear(BMP_WIN_GetBmp(v),15);
    GF_FONT_SetTextColor(1,2,15);
    if(flag==0) {
        (*(unsigned int *)&((TradeWork *)p)->f72C)=PRINTSYS_PrintStream((u32_021DEA24)v,0,0,*(u32_021DEA24 *)&((TradeWork *)p)->f738,*(u32_021DEA24 *)&((TradeWork *)p)->f728,func_02012FFC(),(*(unsigned int *)&((TradeWork *)p)->f744),2,((TradeWork *)p)->f5F4,15);
        func_02028470((u8 *)p+0x11d4,2);
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(v),0,0,(*(void * *)&((TradeWork *)p)->f738),((TradeWork *)p)->f728);
    }
    func_0201F73C(v,1,(u16)(((TradeWork *)p)->f644),15);
    BMP_WIN_TransferChars(v);BMP_WIN_MakeScreen(v);func_02041B6C(6);
}












void func_021E0FF4(void *p, int a, int flag)
{
    if (flag) {
        func_021E0EF4(p, a, 1, 0x12, 0x1E, 4);
        return;
    }
    func_021E0EF4(p, a, 1, 1, 0x1E, 4);
}












void func_021E1024(void *p) { func_021E0FF4(p, 0, 0); }












void func_021E1030(char *p)
{
    if (((TradeWork *)p)->f5F0) {
        TIME_ICON_Delete(((TradeWork *)p)->f5F0);
        ((TradeWork *)p)->f5F0 = 0;
    }
    ((TradeWork *)p)->f5F0 = TIME_ICON_CreateNode((u32_021DEA24)(((TradeWork *)p)->f744), (*(void * *)&((TradeWork *)p)->f71C), 0xF, 0x10, ((TradeWork *)p)->f5F4);
}












void func_021E106C(char *p)
{
    if (((TradeWork *)p)->f5F0) {
        TIME_ICON_Delete(((TradeWork *)p)->f5F0);
        ((TradeWork *)p)->f5F0 = 0;
    }
    if ((*(void * *)&((TradeWork *)p)->f71C)) {
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->f71C));
        (*(void * *)&((TradeWork *)p)->f71C) = 0;
    }
}












void func_021E1098(char *p) { if(*(int *)&((TradeWork *)p)->f5F0) {TIME_ICON_Delete((u8 *)(*(int *)&((TradeWork *)p)->f5F0));*(int *)&((TradeWork *)p)->f5F0=0;} if(((TradeWork *)p)->f71C) {BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f71C));func_02041B6C(6);func_0201F7A8((void *)(((TradeWork *)p)->f71C),2);BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f71C));((TradeWork *)p)->f71C=0;} }












void func_021E10D8(char *p)
{
    (*(void * *)&((TradeWork *)p)->f724)=func_0201EC64(((TradeWork *)p)->f5F4);
    (*(void * *)&((TradeWork *)p)->f720)=func_02045B38(0,2,159,((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f728=GF_FONT_Create(23,0,0,0,((TradeWork *)p)->f5F4);
    (*(void * *)&((TradeWork *)p)->f730)=STRBUF_Create(128,((TradeWork *)p)->f5F4);
    (*(void * *)&((TradeWork *)p)->f734)=STRBUF_Create(128,((TradeWork *)p)->f5F4);
    (*(void * *)&((TradeWork *)p)->f738)=STRBUF_Create(128,((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f73C=STRBUF_Create(128,((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f740=(void *)PRINTSYS_QUE_Create((void *)(((TradeWork *)p)->f5F4));
    GF_FONT_SetTextColor(1,2,15);
    ((TradeWork *)p)->f744=TCBL_Create(((TradeWork *)p)->f5F4,((TradeWork *)p)->f5F4,2,0);
    ((TradeWork *)p)->f74C=func_02028590(15,1,0,((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f6B0=APP_TASKMENU_RES_Create(6,9,*(u32_021DEA24 *)&((TradeWork *)p)->f728,*(u32_021DEA24 *)&((TradeWork *)p)->f740,((TradeWork *)p)->f5F4);
}












void func_021E11A8(char *p)
{
    int i;
    func_0200566C();
    if(*(int *)&((TradeWork *)p)->f744) {
        APP_KEYCURSOR_Delete((int)(((TradeWork *)p)->f74C));
        func_021E106C(p);
        func_021E12F8(p);
        if(((TradeWork *)p)->f72C) {PRINTSYS_PrintStreamDelete((struct Rec3 *)(((TradeWork *)p)->f72C));((TradeWork *)p)->f72C=0;}
        if(((TradeWork *)p)->f648) {APP_TASKMENU_WIN_Delete(((TradeWork *)p)->f648);((TradeWork *)p)->f648=0;}
        if(((TradeWork *)p)->f6B0) {APP_TASKMENU_RES_Delete(((TradeWork *)p)->f6B0);((TradeWork *)p)->f6B0=0;}
        if((*(void * *)&((TradeWork *)p)->f6B4)) {BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->f6B4));(*(void * *)&((TradeWork *)p)->f6B4)=0;}
        for(i=0;i<2;i++) {if(*(void **)(p+i*4+0x5bc)) {BMP_WIN_Delete(*(void **)(p+i*4+0x5bc));*(void **)(p+i*4+0x5bc)=0;}}
        func_0201ED04((*(void * *)&((TradeWork *)p)->f724));
        MSGDATA_Delete((*(void * *)&((TradeWork *)p)->f720));
        GF_FONT_Delete(((TradeWork *)p)->f728);
        STRBUF_Delete((*(void * *)&((TradeWork *)p)->f730));
        STRBUF_Delete((*(void * *)&((TradeWork *)p)->f734));
        STRBUF_Delete((*(void * *)&((TradeWork *)p)->f738));
        STRBUF_Delete(((TradeWork *)p)->f73C);
        PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned *)&((TradeWork *)p)->f740));
        PRINTSYS_QUE_Delete((struct PrintSys *)(*(unsigned *)&((TradeWork *)p)->f740));
        TCBL_Destroy(((TradeWork *)p)->f744);
        *(int *)&((TradeWork *)p)->f744=0;
    }
}












int func_021E12AC(char *p) {int v=1;if(((TradeWork *)p)->f72C) {if(((TradeWork *)p)->f71C)APP_KEYCURSOR_Update((struct Ctx *)(*(int *)&((TradeWork *)p)->f74C),(void *)(((TradeWork *)p)->f72C),(void *)(((TradeWork *)p)->f71C));v=func_02028484((struct Blk *)(p+0x11d4),(void *)(((TradeWork *)p)->f72C));if(v) {if(((TradeWork *)p)->f72C) {PRINTSYS_PrintStreamDelete((struct Rec3 *)(((TradeWork *)p)->f72C));((TradeWork *)p)->f72C=0;}}}return v;}












void func_021E12F8(char *p)
{
    if ((*(void * *)&((TradeWork *)p)->f64C)) {
        *(volatile unsigned short *)0x04000050 = 0;
        APP_TASKMENU_CloseMenu((*(void * *)&((TradeWork *)p)->f64C));
        (*(void * *)&((TradeWork *)p)->f64C) = 0;
    }
}












void func_021E131C(char *p,int *ids,int count,int x,int y)
{
    Template_021DEA24 t;
    int i;
    t.heap=((TradeWork *)p)->f5F4;
    t.count=count;
    t.items=p+0x650;
    t.flag=1;
    t.x=x;t.y=y;t.a=13;t.b=3;
    for(i=0;i<count;i++) {
        *(void **)(p+(u32_021DEA24)i*12+0x650)=STRBUF_Create(100,((TradeWork *)p)->f5F4);
        func_02045CAC((*(void * *)&((TradeWork *)p)->f720),ids[i],*(void **)(p+(u32_021DEA24)i*12+0x650));
        *(u16 *)(p+(u32_021DEA24)i*12+0x654)=0x39e3;
        if(ids[i]==5) *(int *)(p+(u32_021DEA24)i*12+0x658)=1;
        else *(int *)(p+(u32_021DEA24)i*12+0x658)=0;
    }
    (*(void * *)&((TradeWork *)p)->f64C)=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t),((TradeWork *)p)->f6B0);
    for(i=0;i<count;i++) STRBUF_Delete(*(void **)(p+(u32_021DEA24)i*12+0x650));
}












void func_021E1410(void *p, int *ids, int count)
{
    if (count == 1) {
        func_021E131C(p, ids, count, 0x20, 0x15);
        return;
    }
    func_021E131C(p, ids, count, 0x20, 0x18);
}












void func_021E1430(void *a,void *b,int x,int y,int flag,int mode,char *p) {if(!flag) {if(mode) {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),28,(void *)(((TradeWork *)p)->f734));func_0201EE84((*(void * *)&((TradeWork *)p)->f724),0,a);}else {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),29,(void *)(((TradeWork *)p)->f734));func_0201EEF4((*(void * *)&((TradeWork *)p)->f724),0,a);}func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));}else {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),105,(void *)(((TradeWork *)p)->f730));}PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->f730),(void *)(*(int *)&((TradeWork *)p)->f728));}












void func_021E14DC(void *a,void *b,int x,int y,int flag,char *p) {int v;u16 *t;if(!flag) {v=func_02017E1C(a,171,0);if(!((TradeWork *)p)->f11F6) {t=POKE_PERSONAL_LoadFormTable(((TradeWork *)p)->f5F4,0);v=t[v];func_020307B0(t);}if(v==999) {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),162,(void *)(((TradeWork *)p)->f730));}else {func_0201EFA4((struct WordSet *)(((TradeWork *)p)->f724),1,v,3,1,1);func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),27,(void *)(((TradeWork *)p)->f734));func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));}PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->f730),(void *)(*(int *)&((TradeWork *)p)->f728));}}












void func_021E1594(void *a,void *b,int x,int y,int flag,char *p) {if(!flag) {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),28,(void *)(((TradeWork *)p)->f734));func_0201EE84((*(void * *)&((TradeWork *)p)->f724),0,a);func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->f730),(void *)(*(int *)&((TradeWork *)p)->f728));}}












void func_021E15F8(void *a,void *b,int x,int y,char *p) {func_02017E1C(a,171,0);func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),18,(void *)(((TradeWork *)p)->f734));func_0201EFA4((struct WordSet *)(((TradeWork *)p)->f724),0,func_02017E1C(a,158,0),3,1,1);func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->f730),(void *)(*(int *)&((TradeWork *)p)->f728));}












void func_021E1670(void *a,void *b,int x,int y,char *p,int mode,int guard) {int v,w,id,color;v=func_02017E1C(a,110,0);w=func_02017E1C(a,173,0);id=func_02017E1C(a,5,0);if(v<=1 && w!=0 && !(guard && id==29) && !(guard && id==32)) {if(mode) {if(v==1)color=0x31a0;else color=0x39e0;}else {if(v==1)color=0xc80;else color=0x14c0;}func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),v+46,(void *)(((TradeWork *)p)->f730));PRINTSYS_PrintColor(b,x,y,((TradeWork *)p)->f730,*(int *)&((TradeWork *)p)->f728,color);}}












void func_021E1718(int a,int b,int x,int y,char *p)
{
    int i;
    for(i=0;i<6;i++) {
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),30+i,(void *)(((TradeWork *)p)->f730));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y+16*i,(*(void * *)&((TradeWork *)p)->f730),((TradeWork *)p)->f728);
    }
}












void func_021E1778(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),43,(void *)(((TradeWork *)p)->f734));
    v=func_02017E1C((void *)a,6,0);
    if(v) {
        func_0201EF40((struct WordSet *)(((TradeWork *)p)->f724),0,v);
        func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->f730),((TradeWork *)p)->f728);
    }
}












void func_021E17E8(int a,int b,int x,int y,char *p)
{
    int v,w;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),39,(void *)(((TradeWork *)p)->f734));
    v=func_02017E1C((void *)a,160,0);
    w=func_02017E1C((void *)a,161,0);
    func_0201EFA4((struct WordSet *)(((TradeWork *)p)->f724),0,v,3,1,1);
    func_0201EFA4((struct WordSet *)(((TradeWork *)p)->f724),1,w,3,1,1);
    func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->f730),((TradeWork *)p)->f728);
}












void func_021E1880(int a, int b, int c, int d, char *p)
{
    int i = 0;
    T5 t = d_021E7984;
    for (; i < 5; i++) {
        func_02045CAC((*(void * *)&((TradeWork *)p)->f720), 0x28, (*(void * *)&((TradeWork *)p)->f734));
        func_0201EFA4((*(void * *)&((TradeWork *)p)->f724), 0, func_02017E1C((void *)a, t.v[i], 0), 3, 1, 1);
        func_0201F250((*(void * *)&((TradeWork *)p)->f724), (*(void * *)&((TradeWork *)p)->f730), (*(void * *)&((TradeWork *)p)->f734));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b), (s16_021E1880)c, (s16_021E1880)(d + i * 16), (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
    }
}












void func_021E194C(int a,int b,int x,int y,char *p)
{
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),44,(void *)(((TradeWork *)p)->f730));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->f730),((TradeWork *)p)->f728);
}











void func_021E198C(int a,int b,int x,int y,char *p)
{
    int i,v;
    for(i=0;i<4;i++) {
        v=func_02017E1C((void *)a,54+i,0);
        if(v) {
            func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),45,(void *)(((TradeWork *)p)->f734));
            func_0201EF34((struct WordSet *)(((TradeWork *)p)->f724),0,v);
            func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));
            PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y+16*i,(*(void * *)&((TradeWork *)p)->f730),((TradeWork *)p)->f728);
        }
    }
}











void func_021E1A44(int a,int b,int x,int y,char *p)
{
    int s;
    s=(int)func_02045B38(0,2,24,((TradeWork *)p)->f5F4);
    func_02045CAC((struct MsgBank *)s,func_02018598((void *)a),(void *)(((TradeWork *)p)->f730));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->f730),((TradeWork *)p)->f728);
    MSGDATA_Delete((struct Rec *)s);
}











void func_021E1AA8(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720),42,(void *)(((TradeWork *)p)->f734));
    v=func_02017E1C((void *)a,10,0);
    func_0201EF8C((struct WordSet *)(((TradeWork *)p)->f724),0,v);
    func_0201F250((struct WordSet *)(((TradeWork *)p)->f724),(void *)(((TradeWork *)p)->f730),(void *)(((TradeWork *)p)->f734));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->f730),((TradeWork *)p)->f728);
}











/*
 * lever: retain the pre-increment byte index and independent old/base locals;
 * splitting old's base assignment and naming the else-side p+0x8c4
 * address settles the early r4/r7 allocation. No signature mutation.
 */
void func_021E1B14(char *p,int i,void *mon)
{
    Pair_021DEA24 a=d_021E7934;
    Pair_021DEA24 b=d_021E7914;
    Pair_021DEA24 c=d_021E794C;
    u32_021DEA24 flag;
    const char *old;
    u32_021DEA24 index;
    char *tmp;
    flag=func_02017E1C(mon,76,0);
    func_02049B40(23,5,0,448,32,((TradeWork *)p)->f5F4);
    old=p;
    old=old+0x5bc;
    index=i*4;
    if(*(const int *)(old+index))BMP_WIN_Delete((struct Descriptor *)(*(const int *)(old+index)));
    *(int *)(p+0x5bc+index)=(int)BMP_WIN_Create(3,(u8)(*(int *)((char *)&a+index)),1,14,20,14,0);
    GF_FONT_SetTextColor(15,2,0);
    {
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x5bc+index));
        func_021E1430(mon,window,16,0,flag,func_021D8ADC(p),p);
    }
    if(flag==0) {
        char *items=p+0x5bc;
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index));
        func_021E1670(mon,window,80,0,p,0,func_021D8ADC(p));
        GF_FONT_SetTextColor(15,2,0);
        func_021E15F8(mon,BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index)),16,19,p);
        func_021E1778((int)mon,*(int *)(items+index),16,128,p);
        i++;
        func_021E0E68(p+0x8c4+i*20,mon,((TradeWork *)p)->f9C4,*(int *)((char *)&b+index)+16,16,0,((TradeWork *)p)->f5F4,*(int *)((char *)&c+index));
        CLACT_SetActorBgPriority(*(void **)(p+i*20+0x8d4),1);
    } else {
        tmp=p+0x8c4;
        func_021E0E4C(tmp+(i+1)*20);
    }
    BMP_WIN_TransferChars((struct Descriptor *)*(const int *)(old+index));
    BMP_WIN_MakeScreen((struct Cfg *)(*(const int *)(old+index)));
    func_02041B6C(3);
}











void func_021E1CA8(char *p)
{
    char *q = p + 0x8C4;
    int i;
    for (i = 0; i < 3; i++) {
        func_021E0E4C(q + i * 0x14);
    }
}











void func_021E1CC8(char *p)
{
    char *q;
    int i = 0;
    q = p + 0x900;
    for (; i < 4; i++) {
        func_021E0DA0(q + i * 0x14);
    }
}












void func_021E1CE8(void *p, int a1)
{
    unsigned int v;

    func_021E5EF8((char *)p + 0x964);
    func_021E5EF8((char *)p + 0x978);
    func_021E625C(p);
    if (a1 != 0) {
        v = *(volatile unsigned int *)0x04001000;
        v &= 0xFFFF1FFF;
        *(volatile unsigned int *)0x04001000 = v;
    }
    func_021E1CA8(p);
    func_021E1CC8(p);
    func_021E5EF8((char *)p + 0x950);
    func_021E5BE4((int)p);
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f6B4));
    BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f6B4));
    ((TradeWork *)p)->f6B4 = 0;
    func_021E3F70(p);
}









#undef I








#undef I







#undef I






#undef I





#undef I




#undef I



#undef I


#undef I

#undef I

#define I(k) (*(int *)(p+(k)))










void func_021E1D68(char *p,void *a)
{
    func_02040588(3,0);
    func_021E3230(p);
    func_021E1098(p);
    func_021E2438(p,0);
    func_021E2438(p,1);
    func_021E5958((int)p);
    func_021E219C(p,a,0,1);
    if(func_021D8AA8(p)==0) {
        func_021E5998(p);
        func_021E3F30(p);
        BG_SYS_SetMainVisiblePlanes(29);
        BG_SYS_SetSubVisiblePlanes(31);
        func_0207D658(0x04001050,26,-8);
        p[0x11f9]=1;
        func_020056A0((void (*)(void *, void *))func_021E2A98,p,0);
    }
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),1,1);
}










/*
 * initialization: side is assigned 0/1 by the original signed p+f54 comparison; both Pair_021E1D68.v[2] snapshots are initialized by complete table copies.
 * arithmetic: ROM b={0,128} makes b.v[side]+16 equal 16/144; mode is forwarded unchanged and no input domain is added.
 * interface: 020450F0's second argument is explicitly narrowed to u8 at 021E1E5A/60; its own body accepts u32_021DEA24.
 */
void func_021E1E00(char *p,int mode,void *mon)
{
    Pair_021E1D68 a=d_021E7944;
    Pair_021E1D68 b=d_021E793C;
    int side=0;
    u32_021DEA24 flag;
    if(I(0xf54)<128) side=1;
    func_021E6294(p,11,4);
    if(P(0x6b4)) BMP_WIN_Delete(P(0x6b4));
    I(0x6b4)=BMP_WIN_Create(6,(u8)a.v[side],0,16,18,11,0);
    GF_FONT_SetTextColor(14,15,0);
    flag=func_02017E1C(mon,76,0);
    if(mode==0) {
        func_021E1430(mon,BMP_WIN_GetBmp(P(0x6b4)),32,0,flag,0,p);
        if(flag==0) {
            func_021E15F8(mon,BMP_WIN_GetBmp(P(0x6b4)),32,16,p);
            func_021E1718((int)mon,I(0x6b4),8,32,p);
            func_021E1778((int)mon,I(0x6b4),24,128,p);
            func_021E17E8((int)mon,I(0x6b4),64,32,p);
            func_021E1880((int)mon,I(0x6b4),80,48,p);
            func_021E1670(mon,BMP_WIN_GetBmp(P(0x6b4)),96,0,p,0,0);
            func_021E5DFC(p,side,mon);
            func_021E5F14(p,side,0,mon);
            func_021E0E68(p+0x8c4,mon,I(0x9c4),b.v[side]+16,16,1,((TradeWork *)p)->f5F4,13);
        } else {
            func_021E0E4C(p+0x8c4);
        }
    } else {
        func_021E0E4C(p+0x8c4);
        func_021E5EF8(p+0x950);
        func_021E5EF8(p+0x964);
        func_021E5EF8(p+0x978);
        if(flag==0) {
            func_021E194C((int)mon,I(0x6b4),8,0,p);
            func_021E198C((int)mon,I(0x6b4),16,16,p);
            func_02045CAC(P(0x720),36,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),8,80,P(0x730),P(0x728));
            func_021E1A44((int)mon,I(0x6b4),16,96,p);
            func_02045CAC(P(0x720),37,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),8,112,P(0x730),P(0x728));
            func_021E1AA8((int)mon,I(0x6b4),16,128,p);
        }
    }
    func_021E40EC(p,side,mode);
    BMP_WIN_MakeScreen(P(0x6b4));
    BMP_WIN_TransferChars(P(0x6b4));
    func_02041B6C(6);
}










void func_021E2054(char *p, void *a, int b, int a3)
{
    func_021E36D8(p, b);
    if ((*(void * *)&((TradeWork *)p)->f6B4)) {
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->f6B4));
    }
}








void func_021E2070(char *p,void *mon,Quad_021DEA24 *t)
{
    u32_021DEA24 a,b;
    func_021E0DA0(p+0x900+t->a*20);
    func_021E0DA0(p+0x900+t->b*20);
    func_021E0DBC(p+0x900+t->a*20,mon,0,((TradeWork *)p)->f9C4,176,95,0,((TradeWork *)p)->f5F4);
    a=func_02017E1C(mon,174,0);
    b=func_02017E1C(mon,175,0);
    if(a!=b)
        func_021E0DBC(p+0x900+t->b*20,mon,1,((TradeWork *)p)->f9C4,210,95,0,((TradeWork *)p)->f5F4);
    if(*(void **)(p+t->c*20+0x910))
        CLACT_SetActorDrawEnable(*(void **)(p+t->c*20+0x910),0);
    if(*(void **)(p+t->d*20+0x910))
        CLACT_SetActorDrawEnable(*(void **)(p+t->d*20+0x910),0);
}







void func_021E2140(char *p,int a)
{
    if(((TradeWork *)p)->f1098) {
        Quad_021DEA24 t;
        t=d_021E7954;
        func_021E2070((char *)p, (void *)a, &t);
        ((TradeWork *)p)->f1098=0;
    } else {
        Quad_021DEA24 t;
        t=d_021E7964;
        func_021E2070((char *)p, (void *)a, &t);
        ((TradeWork *)p)->f1098=1;
    }
}






#undef I





#undef I




#undef I



#undef I


#undef I

#undef I

#define I(k) (*(int *)(p+(k)))







/*
 * control: the pool-hole call func_021E35A0 is written in both arms (x==0, then flag != 0); the compiler cross-jumps the first copy into a b.
 */
void func_021E219C(char *p,void *mon,int side,int flag)
{
    u32_021DEA24 flag76;
    u32_021DEA24 v[3];
    int i;
    flag76=func_02017E1C(mon,76,0);
    func_021E2054(p,mon,side,flag);
    func_02049B40(23,5,0,448,32,((TradeWork *)p)->f5F4);
    if(Q[side]==0)
        func_021E35A0((Work_021E3004 *)p,side,1,mon,0);
    else if(flag!=0)
        func_021E35A0((Work_021E3004 *)p,side,1,mon,0);
    v[0]=0xe<<14;
    v[1]=1<<14;
    v[2]=0;
    MCSS_SetPosition(Q[side],v);
    MCSS_ResetVanishFlag(Q[side]);
    if(*(void **)(p+(1-side)*4+0x844))
        MCSS_SetVanishFlag(*(void **)(p+(1-side)*4+0x844));
    GF_FONT_SetTextColor(15,2,0);
    i=0;
    P(0x6b4)=(void *)BMP_WIN_Create(3,1,0,31,24,14,0);
    func_021E1430(mon,BMP_WIN_GetBmp(P(0x6b4)),16,0,flag76,0,p);
    if(flag76==0) {
        func_021E14DC(mon,BMP_WIN_GetBmp(P(0x6b4)),0,16,flag76,p);
        func_021E1594(mon,BMP_WIN_GetBmp(P(0x6b4)),56,16,flag76,p);
        func_021E15F8(mon,BMP_WIN_GetBmp(P(0x6b4)),96,i,p);
        func_021E1670(mon,BMP_WIN_GetBmp(P(0x6b4)),80,i,p,i,i);
        func_021E1718((int)mon,(int)P(0x6b4),0,32,p);
        for(i=0;i<2;i++) {
            func_02045CAC(P(0x720),i+36,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),0,i*16+0x88,P(0x730),P(0x728));
        }
        func_021E17E8((int)mon,(int)P(0x6b4),56,32,p);
        func_021E1880((int)mon,(int)P(0x6b4),72,48,p);
        func_021E1A44((int)mon,(int)P(0x6b4),56,136,p);
        func_021E1AA8((int)mon,(int)P(0x6b4),56,152,p);
        func_021E1778((int)mon,(int)P(0x6b4),40,168,p);
        func_021E194C((int)mon,(int)P(0x6b4),152,113,p);
        func_021E198C((int)mon,(int)P(0x6b4),152,128,p);
        func_021E2140(p,(int)mon);
        func_021E5DFC(p,2,mon);
        func_021E0E68(p+0x8c4,mon,I(0x9c4),12,7,0,((TradeWork *)p)->f5F4,12);
    } else {
        if(P(0x960)) CLACT_SetActorDrawEnable(P(0x960),i);
        func_021E1CC8(p);
        func_021E1CA8(p);
    }
    func_021E60BC(p,mon,flag76);
    func_021E5F14(p,0,1,mon);
    BMP_WIN_MakeScreen(P(0x6b4));
    BMP_WIN_TransferChars(P(0x6b4));
    func_02041B6C(3);
}







void func_021E2438(char *p,int i)
{
    if (*(int *)(p+0x5bc+4*i)) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x5bc+4*i)),0);
        BMP_WIN_ClearScreen((struct Descriptor *)(*(int *)(p+0x5bc+4*i)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5bc+4*i)));
        func_02041B6C(3);
        *(int *)(p+0x5bc+4*i)=0;
        func_021E0E4C(p+0x8c4+20*(i+1));
    }
}





#undef I




#undef I



#undef I


#undef I

#undef I

#define I(k) (*(int *)(p+(k)))







void func_021E2484(char *p,int a)
{
    func_021E0E4C(p+0x8c4);
    func_021E5EF8(p+0x950);
    func_021E5EF8(p+0x964);
    func_021E5EF8(p+0x978);
    if (((TradeWork *)p)->f6B4) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((TradeWork *)p)->f6B4),0);
        if(a) {
            BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f6B4));
            BMP_WIN_TransferChars((struct Descriptor *)((TradeWork *)p)->f6B4);
        }
        BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f6B4));
        ((TradeWork *)p)->f6B4=0;
    }
}







/*
 * zero: the literal 0 arguments of the first loop are hoisted and spilled to the slot k then reuses; k=0 is written just before the second GF_FONT_SetTextColor call, not before the loop.
 */
void func_021E24E8(char *p, int a1)
{
    void *arr[2];
    void *mon;
    u32_021DEA24 flag76;
    char *q1,*q2;
    int j,n;
    int k;
    func_021E6CB8(p);
    arr[0]=P(0x834);
    arr[1]=P(0x830);
    GF_FONT_SetTextColor(15,2,0);
    for(j=0;j<2;j++) {
        func_02045CAC(P(0x720),128,P(0x734));
        func_0201F02C(P(0x724),0,arr[j]);
        func_0201F250(P(0x724),P(0x730),P(0x734));
        PRINTSYS_Print(*(void **)(p+j*16+0x10f4),0,0,P(0x730),P(0x728));
    }
    k=0;
    GF_FONT_SetTextColor(15,2,k);
    for(;k<2;k++) {
        GF_FONT_SetTextColor(1,2,0);
        q1=p+(1-k)*12;
        q2=p+k*16;
        for(n=0;n<3;n++) {
            mon=*(void **)(q1+n*4+0xfd8);
            if(*(int *)(q1+n*4+0xfa4)!=-1) {
                flag76=func_02017E1C(mon,76,0);
                func_021E6334(p,k,n,mon,0,1);
                func_021E1430(mon,*(void **)(q2+n*4+0x10f8),0,0,flag76,func_021D8ADC(p),p);
                if(flag76==0) {
                    func_021E1670(mon,*(void **)(q2+n*4+0x10f8),56,16,p,0,func_021D8ADC(p));
                    func_021E15F8(mon,*(void **)(q2+n*4+0x10f8),0,16,p);
                }
            }
        }
    }
    func_021E6E7C((int)p);
}







void func_021E2680(char *p)
{
    int i;
    for (i=0;i<4;i++) {
        char *q = p+i*4;
        if (((TradeWork *)q)->f1038) {
            BMP_WIN_Delete(((TradeWork *)q)->f1038);
            ((TradeWork *)q)->f1038=0;
        }
    }
    func_021E6DEC((int)p);
}








void func_021E26AC(void *a0)
{
    u32_021DEA24 v;

    func_0207D658(0x04001050, 0x1A, -8);

    v = (*(volatile u16 *)0x04001048 & ~0x3F) | 0x1F;
    *(volatile u16 *)0x04001048 = v | 0x20;
    *(volatile u16 *)0x04001040 = 0x00FF;
    *(volatile u16 *)0x04001044 = 0x00C0;
    v = (*(volatile u16 *)0x04001048 & ~0x3F00) | 0x1F00;
    *(volatile u16 *)0x04001048 = v | 0x2000;
    *(volatile u16 *)0x04001042 = 0xFF00;
    *(volatile u16 *)0x04001046 = 0x00C0;
    v = (*(volatile u16 *)0x0400104A & ~0x3F) | 0x1F;
    *(volatile u16 *)0x0400104A = v;
    *(volatile u32_021DEA24 *)0x04001000 =
        (*(volatile u32_021DEA24 *)0x04001000 & 0xFFFF1FFF) | 0x6000;
}







/*
 * lever: each final handle index is recomputed through a 32-bit long local;
 * an int copy CSEs the shift and shortens the function by four bytes.
 */
void func_021E272C(char *p,int i,void *mon)
{
    Pair a=d_021E7924;
    Pair b=d_021E791C;
    Quad_021E2484 colors=d_021E7974;
    Pair c=d_021E790C;
    u32_021DEA24 flag;
    int layer,idx2;
    u32_021DEA24 col,col2;
    int index;
    char *items,*items2;
    flag=func_02017E1C(mon,76,0);
    index=i*4;
    if(*(int *)(p+i*4+0x5c4)) {
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5c4)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5cc)));
    }
    layer=*(int *)((char *)&a+index);
    items=p+0x5c4;
    *(int *)(items+index)=BMP_WIN_Create(1,layer,0,14,5,5,0);
    items2=p+0x5cc;
    *(int *)(items2+index)=BMP_WIN_Create(1,layer,17,13,2,5,0);
    idx2=i*2;
    col=((u32_021DEA24 *)&colors)[idx2];
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index)),(u8)(col|(col<<4)));
    col2=((u32_021DEA24 *)&colors)[idx2+1];
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items2+index)),(u8)(col2|(col2<<4)));
    GF_FONT_SetTextColor(1,2,(u8)col);
    {
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index));
        func_021E1430(mon,window,16,4,flag,func_021D8ADC(p),p);
    }
    if(flag==0) {
        char *first=p+0x5c4;
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(first+index));
        func_021E1670(mon,window,80,4,p,1,func_021D8ADC(p));
        func_021E15F8(mon,BMP_WIN_GetBmp((struct Descriptor *)*(int *)(first+index)),16,19,p);
        GF_FONT_SetTextColor(1,2,(u8)col2);
        func_021E1778((int)mon,*(int *)(items2+index),0,0,p);
        func_021E0E68(p+0x8c4+(i+1)*20,mon,((TradeWork *)p)->f9C4,*(int *)((char *)&b+index)+16,16,0,((TradeWork *)p)->f5F4,*(int *)((char *)&c+index));
    } else func_021E1CA8(p);
    {
        char *first=p+0x5c4;
        char *second=p+0x5cc;
        long endindex=(long)i*4;
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)(first+endindex));
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)(second+endindex));
        BMP_WIN_MakeScreen((struct Cfg *)(*(int *)(first+endindex)));
        BMP_WIN_MakeScreen((struct Cfg *)(*(int *)(second+endindex)));
    }
    func_02041B6C(1);
    *(u8 *)(p+i+0x11e2)=120;
}







void func_021E293C(char *p,int i)
{
    if (*(int *)(p+0x5c4+4*i)) {
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5c4+4*i)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5cc+4*i)));
        func_021E0E4C(p+0x8c4+20*(i+1));
        *(int *)(p+0x5c4+4*i)=0;
        *(int *)(p+0x5cc+4*i)=0;
    }
}







void *func_021E2984(char *p,int a) {
    void *t;
    t=STRBUF_Create(100,((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f650=t;
    func_02045CAC((*(void * *)&((TradeWork *)p)->f720),a,t);
    ((TradeWork *)p)->f654=0x39e3;
    ((TradeWork *)p)->f658=0;
    ((TradeWork *)p)->f648=APP_TASKMENU_WIN_CreateEx((u32_021DEA24)(((TradeWork *)p)->f6B0),(u32_021DEA24)(p+0x650),8,21,16,3,0,1,((TradeWork *)p)->f5F4);
    STRBUF_Delete(((TradeWork *)p)->f650);
    CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->fF04),0);
    func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),8,0);
    return ((TradeWork *)p)->f648;
}







void func_021E2A1C(char *p,int a,int b) {
    if (!PRINTSYS_QUE_IsFinished(((TradeWork *)p)->f740)) PRINTSYS_QUE_Clear(((TradeWork *)p)->f740);
    if(a) CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->fF04),1);
    if(b) func_021B6558((unsigned char *)(((TradeWork *)p)->f9C0),8,func_021DD2F4(p));
    if(((TradeWork *)p)->f648) {
        APP_TASKMENU_WIN_Delete(((TradeWork *)p)->f648);
        ((TradeWork *)p)->f648=0;
        func_02041B6C(6);
    }
}







int func_021E2A80(void *a0)
{
    if (TOUCHPANEL_HitTrg(d_021E792C) == 0) return 1;
    return 0;
}







static inline void W1Inside(int wnd,BOOL effect) {
    u32_021DEA24 tmp=(WININ & ~0x3f00)|((u32_021DEA24)wnd<<8);
    if(effect) tmp|=0x2000;
    WININ=(u16)tmp;
}







static inline void W0Inside(int wnd,BOOL effect) {
    u32_021DEA24 tmp=(WININ & ~0x3f)|((u32_021DEA24)wnd);
    if(effect) tmp|=0x20;
    WININ=(u16)tmp;
}







static inline void Outside(int wnd,BOOL effect) {
    u32_021DEA24 tmp=(WINOUT & ~0x3f)|((u32_021DEA24)wnd);
    if(effect) tmp|=0x20;
    WINOUT=(u16)tmp;
}







static inline void Position1(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04001042=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001046=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}







static inline void Position0(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04001040=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001044=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}







static inline void Visible(int window) {DISPCNT=(DISPCNT&~0xe000)|(window<<13);}







/*
 * volatile: WININ re-read at 021E2A9E and 021E2AB6; WINOUT and DISPCNT hardware read-modify-write, WIN0/1 positions hardware stores.
 */
void func_021E2A98(void *a,char *p) {
    W1Inside(0x10,0);
    Position1(0x30,0,0xd0,0x20);
    W0Inside(0x11,0);
    Position0(0xe0,0xa9,0xff,0xc0);
    Outside(0x1f,1);
    Visible(3);
    p[0x11f9]=0;
    func_02030EAC(a);
}







void func_021E2B14(int a) {
    Config_021DEA24 c;
    d_021F4560=func_02048BC4((const struct LightSet *)d_021E799C,a);
    func_02048C58(d_021F4560);
    c=d_021E7B1C;
    c.b=d_020A1DF8[12]; c.c=d_020A1DF8[13];
    G3D_SYSTEM_SetProjection((const u32_021DEA24 *)(&c));
}







void func_021E2B68(void)
{
    func_02048C4C(d_021F4560);
}







void func_021E2B78(char *p) {
    Vec_021DEA24 a;
    Vec_021DEA24 b;
    a.x=0; a.y=0x2b000; a.z=0xf1000;
    b.x=0; b.y=0x2b000; b.z=0;
    func_02048AFC(((TradeWork *)p)->f83C,&a);
    func_02048B44(((TradeWork *)p)->f83C,&b);
    a.z-=0x1000;
    func_02048B6C(((TradeWork *)p)->f83C,(const u32_021DEA24 *)(&a.z));
    b.x=0; b.y=0x1000; b.z=0;
    func_02048B20(((TradeWork *)p)->f83C,&b);
}







void func_021E2BD0(char *p) {
    Vec_021DEA24 a;
    Vec_021DEA24 b;
    int c=0x1f40000;
    int d=0x1000;
    a.x=0; a.y=0x3000; a.z=0xf000;
    b.x=0; b.y=0; b.z=0;
    func_02048AFC(((TradeWork *)p)->f83C,&a);
    func_02048B44(((TradeWork *)p)->f83C,&b);
    func_02048B60(((TradeWork *)p)->f83C,(const u32_021DEA24 *)(&d));
    func_02048B6C(((TradeWork *)p)->f83C,(const u32_021DEA24 *)(&c));
    b.x=0; b.y=0x10000; b.z=0x1000;
    func_02048B20(((TradeWork *)p)->f83C,&b);
}







void func_021E2C34(char *p) {func_021E3A40((const u8 *)p);}







static inline void shading(Shading s) { *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3002) | (s << 1)); }







static inline void antialias(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x10); else *(volatile u16 *)0x04000060 &= (u16)~0x3010; }







static inline void alphatest(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 4); else *(volatile u16 *)0x04000060 &= (u16)~0x3004; }







static inline void blend(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8); else *(volatile u16 *)0x04000060 &= (u16)~0x3008; }







static inline void edge(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x20); else *(volatile u16 *)0x04000060 &= (u16)~0x3020; }







/*
 * volatile: 0x04000060 reread at 021E2C9C, 021E2CAA, 021E2CB6, 021E2CC0, 021E2CC8; 0x04000580 hardware store at 021E2CEC.
 */
void func_021E2C3C(Work_021DEA24 *w, Transform *t)
{
    unsigned i;
    VecFx32_021DEA24 v1;
    VecFx32_021DEA24 v2;
    t->trans.x = 0;
    t->trans.y = 0;
    t->trans.z = 0;
    t->scale.x = 0x1000;
    t->scale.y = 0x1000;
    t->scale.z = 0x1000;
    func_0207ADC4(&t->rot);
    if (w->sub != 0) {
        if (w->sub->objA8 == 0) ICA_ANIME_SetCameraPos(w->x83c, (void *)w->sub->anim90);
        if (w->sub->objAC == 0) ICA_ANIME_SetCameraTarget(w->x83c, (void *)w->sub->anim94);
    }
    func_02048AD0(w->x83c);
    shading(SHADING_HIGHLIGHT); antialias(1); alphatest(0); blend(0); edge(0);
    G3X_SetFog(1, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((u8)i, (const u16 *)(d_021E79C8 + i * 8));
    if (w->sub != 0) {
        if (w->sub->objA0 != 0) {
            func_02011610((struct IcaAnime *)w->sub->anim98, (struct Rec12 *)&v1);
            BUTTON_MAN_SetEmitterPos(w->sub->objA0, &v1);
        }
        if (w->sub->objA4 != 0) {
            func_02011610((struct IcaAnime *)w->sub->anim9c, (struct Rec12 *)&v2);
            BUTTON_MAN_SetEmitterPos(w->sub->objA4, &v2);
        }
    }
}







void func_021E2D70(char *p,unsigned mode)
{
    switch(mode) {
    case 0:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x38,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x39,10);
        ((struct Obj00673 *)p)->f98=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        ((struct Obj00673 *)p)->f9C=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        break;
    case 1:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3f,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3e,10);
        ((struct Obj00673 *)p)->f98=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        break;
    case 2:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3d,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3c,10);
        break;
    case 3:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3b,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3a,10);
        ((struct Obj00673 *)p)->f9C=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        func_020115EC(((struct Obj00673 *)p)->f9C,0x2b5000);
        break;
    }
}







/*
 * follower: two-byte zero alignment padding at 0x021E2EFA.
 */
void func_021E2EA0(char *p) {
    if (((struct Obj02173 *)p)->f90) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f90); ((struct Obj02173 *)p)->f90=0;}
    if (((struct Obj02173 *)p)->f94) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f94); ((struct Obj02173 *)p)->f94=0;}
    if (((struct Obj02173 *)p)->f98) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f98); ((struct Obj02173 *)p)->f98=0;}
    if (((struct Obj02173 *)p)->f9C) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f9C); ((struct Obj02173 *)p)->f9C=0;}
}







/*
 * extent: 46-byte body followed by 2-byte alignment padding.
 */
void func_021E2EFC(char *p)
{
    ((struct Obj08067 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj08067 *)p)->fBA,0x68,0xb,10);
    ((struct Obj08067 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj08067 *)p)->fBA,0x68,0xc,10);
}







void func_021E2F2C(void *a0) { func_021E2EA0(a0); }







void func_021E2F34(char *p) {
    int i,flag;
    PARTICLE_InitManager(((struct Obj04480 *)p)->fBA);
    ((struct Obj04480 *)p)->fB4=0;
    for(i=0;i<9;i++) {
        ((void **)p)[9+i]=func_02030734(((struct Obj04480 *)p)->fBA,0x4800,1,d_021E81C0,0x201);
        switch(i) {
        case 0: case 1: case 2: case 5: case 6: case 8: flag=0; break;
        case 3: case 4: case 7: default: flag=1; break;
        }
        ((void **)p)[i]=(void *)PARTICLE_CreateSystemDefault((int)(((void **)p)[9+i]),0x4800,flag,((struct Obj04480 *)p)->fBA);
    }
}







void func_021E2FB0(char *p) {
    int i;
    ((struct Obj08068 *)p)->fB4=(void *)PARTICLE_LoadArchiveMember((int)0x67,(int)0x35,(u16)((((struct Obj08068 *)p)->fBA&0x7fff)|0x8000));
    for(i=0;i<4;i++) {
        int x;
        func_02087A3C(1,1);
        x=func_020056BC();
        PARTICLE_SetupSystemBorrowed(((void **)p)[i],(unsigned int)(((struct Obj08068 *)p)->fB4),1,x);
    }
}








void func_021E3004(char *p)
{
    int i;

    for (i = 4; i < 9; i++) {
        func_02087A3C(1, 1);
        PARTICLE_SetupSystemBorrowed(((void **)p)[i], (unsigned int)(((struct Obj13911 *)p)->fB4), 1, func_020056BC());
    }
}








/*
 * Teardown: release the +0xb4 pointer and the nine 32-bit slots at
 * +0x24, zeroing each. Target of func_021D6C78's second call (ov119).
 *
 * Addresses are Black-image addresses.
 */
void func_021E3034(u32_021DEA24 *p, int a1)
{
    int i;

    PARTICLE_ExitManager();
    if (p[0x2d] != 0) {
        func_020307B0((void *)p[0x2d]);
        p[0x2d] = 0;
    }
    for (i = 0; i < 9; i++) {
        if (p[9 + i] != 0) {
            func_020307B0((void *)p[9 + i]);
            p[9 + i] = 0;
        }
    }
}








void func_021E3070(S *p)
{
    int i;
    void *buf;
    void *h;
    void **q;

    PARTICLE_InitManager(p->heap);
    for (i = 0; i < 6; i++) {
        q = &p->a[i];
        buf = func_02030734(p->heap, 0x4800, 1, d_021E81C0, 0x273);
        q[9] = buf;
        *q = (void *)PARTICLE_CreateSystemDefault((int)buf, 0x4800, 0, p->heap);
    }
    h = (void *)PARTICLE_LoadArchiveMember(0x68, 10, p->heap);
    for (i = 0; i < 6; i++)
        PARTICLE_SetupSystem(p->a[i], h, 1, 0);
}







void func_021E30EC(char *p)
{
    ((TradeWork *)p)->f824=0xffff;
    ((TradeWork *)p)->f109C=~0u;
    func_021E2B14(0x91);
    ((TradeWork *)p)->f820=G3D_UTIL_Create(20,20,0x91);
    if (!((TradeWork *)p)->f83C) {
        Vec_021E3004 a={0,0,0};
        Vec_021E3004 b={0,0,0};
        Vec_021E3004 c;
        u16 heap;
        heap=((TradeWork *)p)->f5F4;
        c=d_021E7AF4;
        ((TradeWork *)p)->f83C=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&a,&c,&b,heap);
    }
    if (((TradeWork *)p)->f109C!=~0u)
        d_021E7AC4[*(u32_021DEA24 *)(p+0x109c)].call(p);
}







void func_021E31B4(void *p) { func_021E32EC(p); }







void func_021E31BC(char *p) {
    if (((TradeWork *)p)->f83C) G3D_CAMERA_Delete(((TradeWork *)p)->f83C);
    G3D_UTIL_Delete(((TradeWork *)p)->f820);
    if (((TradeWork *)p)->fC) {
        func_021E3034(((TradeWork *)p)->fC,6);
        func_021E2F2C(((TradeWork *)p)->fC);
        func_020307B0(((TradeWork *)p)->fC);
        ((TradeWork *)p)->fC=0;
    }
    func_021E2B68();
}







void func_021E31FC(void *p) { func_021E3838(p, 0x19); }








void func_021E3208(void *p, int a)
{
    func_021E324C(p, a);
    if (((TradeWork *)p)->f109C != 0xFFFFFFFF) {
        tbl_021E7AC4[*(u32_021DEA24 *)((char *)p + 0x109C) * 2](p);
    }
}








void func_021E3230(void *p)
{
    if (((TradeWork *)p)->f109C != 0xFFFFFFFF) {
        func_021E32C4(p);
        ((TradeWork *)p)->f109C = 0xFFFFFFFF;
    }
}







void func_021E324C(char *p,int n) {
    void *q;
    int i,count;
    if(d_021E7B3C[n].d) ((TradeWork *)p)->f824=G3D_UTIL_AddUnit(((TradeWork *)p)->f820,&d_021E7B3C[n]);
    else ((TradeWork *)p)->f824=0xffff;
    if(((TradeWork *)p)->f824!=0xffff) {
        q=(void *)func_02048A18(((TradeWork *)p)->f820,((TradeWork *)p)->f824);
        count=G3D_SYSTEM_GetObjectAnimeCount(q);
        for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime(q,(u16)i);
    }
    *(int *)&((TradeWork *)p)->f109C=n;
}








void func_021E32C4(char *p)
{
    u16 v;

    v = ((TradeWork *)p)->f824;
    if (v != 0xFFFF)
        G3D_UTIL_RemoveUnit(((TradeWork *)p)->f820, v);
    ((TradeWork *)p)->f824 = 0xFFFF;
}








void func_021E32EC(char *p)
{
    char buf[0x3C];
    void *q;
    int n;
    int i;
    int idx;

    idx = (*(int *)&((TradeWork *)p)->f109C);
    if (idx == -1)
        return;
    if (d_021E7AC8[idx].fn != 0)
        d_021E7AC8[idx].fn(p, buf);
    if (((TradeWork *)p)->f824 != 0xFFFF) {
        q = (void *)func_02048A18(((TradeWork *)p)->f820, ((TradeWork *)p)->f824);
        n = G3D_SYSTEM_GetObjectAnimeCount(q);
        for (i = 0; i < n; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(q, (u16)i, d_021E8144.amount);
    }
    func_02047964();
    func_02048AD0(((TradeWork *)p)->f83C);
    G3D_SYSTEM_ApplyLookAt();
    if (((TradeWork *)p)->fC != 0) {
        PARTICLE_DrawAllSystems();
        PARTICLE_UpdateAllSystems();
    }
    if (((TradeWork *)p)->f824 != 0xFFFF)
        G3D_SYSTEM_DrawObject((void *)func_02048A18(((TradeWork *)p)->f820, ((TradeWork *)p)->f824), (struct Arg *)buf);
    if (*(Sub_021E3004 * *)&((TradeWork *)p)->fC != 0) {
        if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a90 != 0) {
            if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aA8 == 0)
                (*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aA8 = ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a90), d_021E8144.amount);
            if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aAC == 0)
                (*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aAC = ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a94), d_021E8144.amount);
        }
        if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a9C != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a9C), d_021E8144.amount);
        if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a98 != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a98), d_021E8144.amount);
    }
}








/*
 * 2026-10-03 (wave B3): all concrete bytes match. The one open relocation is
 * the call to MCSS_GetSizeX (unlabelled arm9 Thumb leaf). Its witness is
 * filed as src/matched/arm9/MCSS_GetSizeX.c (EXACT); once the integrator
 * seeds 0x02015F04 in layout/function_starts.txt this re-verifies as EXACT.
 * The empty-then if/else on *dir gives the original `bge; b` shape.
 */
void func_021E33FC(void *p0, int *dir, int p2, void *mon)
{
    Vec_021E33FC v;
    int flag = 0;
    int a, b, c;
    int found;
    u8 i;
    float f;

    a = func_02017E1C(mon, 5, 0);
    b = func_02017E1C(mon, 0x6f, 0);
    c = POKE_TOOL_GetGender(mon);
    if (p2 == 0)
        flag = 1;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (a == d_021E7B9C[i].a && b == d_021E7B9C[i].b
            && (d_021E7B9C[i].c == 3 || c == d_021E7B9C[i].c)
            && (d_021E7B9C[i].d == 2 || flag == d_021E7B9C[i].d)) {
            v.x = F32_TO_FX32(d_021E7B9C[i].x);
            if (*dir >= 0)
                v.x = -v.x;
            v.y = F32_TO_FX32(d_021E7B9C[i].y);
            v.z = F32_TO_FX32(d_021E7B9C[i].z);
            found = 1;
            break;
        }
    }
    if (!found) {
        MCSS_GetSizeX(p0);
        c = MCSS_GetOfsX(p0);
        if (*dir < 0)
            f = 0.33f * (float)c;
        else
            f = 0.33f * (float)-c;
        v.x = F32_TO_FX32(f);
        v.y = 0;
        v.z = 0;
    }
    MCSS_SetOfsPosition(p0, (u32_021DEA24 *)(&v));
}







void func_021E35A0(Work_021E3004 *p, int idx, int side, void *mon, int flag)
{
    Vec_021E35A0 v = data_021E7B00;
    Table_021E3004 t = data_021E7B0C;
    if (flag) {
        u16 species = func_02017E1C(mon, 5, 0);
        u16 form = func_02017E1C(mon, 0x6f, 0);
        void *h = POKE_PERSONAL_Create(species, form, p->heap);
        u32_021DEA24 r = POKE_PERSONAL_GetParam(h, 0x22);
        POKE_PERSONAL_Delete(h);
        if (r == 0)
            v.x = -v.x;
    }
    if (p->mode == 2)
        DWC_RAP_SetVchatTalkLock(1);
    if (side)
        p->obj[idx] = MCSS_TOOL_AddPokeMcss(p->res, mon, 0, t.v[idx], -0x1C000, 0);
    else
        p->obj[idx] = MCSS_TOOL_AddPokeMcss(p->res, mon, 1, t.v[idx], -0x1C000, 0);
    if (p->mode == 2)
        DWC_RAP_SetVchatTalkLock(0);
    MCSS_TOOL_SetAnimeStopCallback((int)p->obj[idx]);
    MCSS_SetScale(p->obj[idx], (u32_021DEA24 *)(&v));
    MCSS_SetShadowVanishFlag(p->obj[idx], 1);
    func_021E33FC(p->obj[idx], (int *)(&v), side, mon);
}








void func_021E36A8(void *a, int b, int c, void *d, int e, int f)
{
    if (f != 0 && c == 0) {
        c = 1;
        e = 0;
    }
    func_021E35A0(a, b, c, d, e);
}








void func_021E36C8(void *a, int b, int c, void *d, int e)
{
    func_021E35A0(a, b, c, d, e);
}








/*
 * Teardown of one slot of the 0x844 vector: releases it through
 * MCSS_SetVanishFlag, hands (the shared 0x840 handle, the slot value) to
 * MCSS_Del, then clears the slot.
 *
 * Addresses are Black-image addresses.
 */
void func_021E36D8(void *p, int idx)
{
    u32_021DEA24 v = ((u32_021DEA24 *)((char *)p + 0x844))[idx];

    if (v != 0) {
        MCSS_SetVanishFlag((void *)v);
        MCSS_Del((void *)(*(u32_021DEA24 *)&((TradeWork *)p)->f840), (void *)(((u32_021DEA24 *)((char *)p + 0x844))[idx]));
        ((u32_021DEA24 *)((char *)p + 0x844))[idx] = 0;
    }
}








static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32_021DEA24)(u16)x | ((u32_021DEA24)(u16)y << 16);
    REG_VTX_16 = (u32_021DEA24)(u16)z;
}








/*
 * The cube vertex table (8 corners, x y z each). The values come from the
 * user's own ROM: tools/gendata.py writes build/gen/h16_ov119_021E8190.inc
 * (gitignored).
 */
static fx16 d_021E8190[24] = {
#include "../../../build/gen/h16_ov119_021E8190.inc"
};








/*
 * The vertex table is a non-const file static: as an extern (or a const
 * static) the allocator keeps n*3 in r1; as a writable file static it keeps
 * n*3 in r4 and the base in r3 like the original.
 */
void func_021E3700(int n)
{
    G3_Vtx(d_021E8190[n * 3], d_021E8190[n * 3 + 1], d_021E8190[n * 3 + 2]);
}








void func_021E3730(int n)
{
    *(u32_021DEA24 *)0x04000484 = d_021E8178[n];
}








void func_021E3744(int n)
{
    *(u32_021DEA24 *)0x04000488 = d_021E8168[n];
}







/*
 * extent: 126-byte body followed by two zero padding bytes at 0x021E37D6.
 */
void func_021E3758(unsigned short *p, int x, int y, int colour)
{
    int end;
    int col;
    int row;
    int start;
    int index;
    int shift;
    start = x * 5 + 2;
    row = y * 6 + 3;
    end = row + 3;
    for (; row < end; row++) {
        for (col = start; col < start + 3; col++) {
            index = col + row * 32;
            shift = (index % 4) * 4;
            p[index / 4] &= (unsigned short)~(15 << shift);
            p[index / 4] |= (unsigned short)(colour << shift);
        }
    }
}







void func_021E37D8(u16 *p, u8 *src, int k, int a3)
{
    u8 *row;
    int i;
    int j;

    i = 0;
    row = src + k * 30;
    for (; i < 5; i++) {
        for (j = 0; j < 6; j++)
            func_021E3758(p, j, i, row[i * 6 + j]);
    }
}







void func_021E380C(u16 *p, u8 *src, int a2)
{
    int i;

    for (i = 0; i < 6; i++)
        func_021E3758(p, i % 2 + 2, i / 2 + 1, src[i]);
}






void func_021E3838(char *p, int count)
{
    char *v;
    int i;
    func_0207F7A0();
    v = func_02030734(((TradeWork *)p)->f5F4, 0x200, 1, d_021E81C0, 0x510);
    for (i = 0; i < count; i++) {
        MI_CpuFill8(v, 0, 0x200);
        if (i == 0)
            func_021E380C((u16 *)v, (unsigned char *)(p + 0x5B6), 2);
        else
            func_021E37D8((u16 *)v, (u8 *)(p + 0x2E6), i - 1, 2);
        func_020862F0(v, 0x200);
        func_0207F7FC(v, i * 0x200 + 0x3000, 0x200);
    }
    func_020307B0(v);
    func_0207F9B4();
    func_021E3B2C(p);
}




/*
 * Program the two register bits selected by the two flags.
 */
void func_021E38D8(int a, int b)
{
    *(volatile unsigned int *)0x040004c0 = 0x6b5a5ef7 | ((a != 0) << 15);
    *(volatile unsigned int *)0x040004c4 = 0x00007fff | ((b != 0) << 15);
}




/*
 * lever: u16 third argument places its spill before hardware writes; caller supplies u16.
 * volatile: hardware command stores 021E391C..021E3A22, 04000440..04000504
 */
void func_021E3910(int z,int index,u16 a,int b)
{
    REG(0x04000444)=0;
    REG(0x04000440)=1;
    func_0207D84C(FX_SinCosTable_[(b>>4)*2],FX_SinCosTable_[(b>>4)*2+1]);
    REG(0x04000444)=0;
    func_0207D84C(FX_SinCosTable_[(a>>4)*2],FX_SinCosTable_[(a>>4)*2+1]);
    REG(0x04000470)=0;
    REG(0x04000470)=0;
    REG(0x04000470)=z;
    func_0207D84C(FX_SinCosTable_[(d_021E8144.a>>4)*2],FX_SinCosTable_[(d_021E8144.a>>4)*2+1]);
    func_0207D810(FX_SinCosTable_[(d_021E8144.b>>4)*2],FX_SinCosTable_[(d_021E8144.b>>4)*2+1]);
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x04000440)=3;
    REG(0x04000454)=0;
    REG(0x04000440)=2;
    func_021E38D8(1,1);
    REG(0x040004a8)=0x4d200000|(((u32_021E38D8)index*512+0x3000)>>3);
    REG(0x040004ac)=512;
    REG(0x040004a4)=0x1f0041|((u32_021E38D8)index<<24);
    REG(0x04000500)=1;
    func_021E3744(1); func_021E3730(0); func_021E3700(2);
    func_021E3744(0); func_021E3730(0); func_021E3700(0);
    func_021E3744(2); func_021E3730(0); func_021E3700(4);
    func_021E3744(3); func_021E3730(0); func_021E3700(6);
    REG(0x04000504)=0;
    REG(0x04000448)=1;
    REG(0x04000448)=1;
}







static inline fx32 fraction(int x,int y) { return (fx32)(((long long)x*65536)/y); }







/*
 * lever: separate x+=48 and remainder assignments restore numerator register setup.
 * volatile: hardware writes 021E3A5C,021E3A60 to 040004C8/040004CC
 */
void func_021E3A40(const u8 *p)
{
    int i,stage,count,total,base;
    int x;
    unsigned delta;
    u16 angle;
    func_0207DA8C();
    func_0207D7C4(&d_021E815C,&d_021E79AC,&d_021E8150,1,0);
    *(volatile u32_021E3A40 *)0x040004c8=0x2d8b6127;
    *(volatile u32_021E3A40 *)0x040004cc=0x7fff;
    stage=func_021D8A18((u8 *)p);
    count=stage+1;
    total=count*160;
    x=((TradeWork *)p)->f107E;
    if(x<96) {
        if(x<48) x=x*112/48;
        else x=x+64;
    } else x=x+64;
    base=stage*160;
    if(x>base) {
        delta=x-base;
        if(delta<80) x=base+delta*112U/80U;
        else x=base+(delta-80U)*48U/80U+112;
    }
    x=x+48;
    x=x%total;
    x=fraction(x,total);
    for(i=0;i<count;i++) {
        angle=0x10000-x;
        func_021E3910(d_021E8144.c,i,(u16)((i<<16)/count),angle);
    }
}







void func_021E3B2C(char *p)
{
    void *v;
    void *allocation;
    void *descriptor;
    char *data;
    v = func_020490F4(0x74, ((TradeWork *)p)->f5F4);
    allocation = func_02049F78(v, 0x48, (u32_021E3B2C)(&descriptor), ((TradeWork *)p)->f5F4);
    data = *(char * *)&((struct Obj22795 *)descriptor)->fC;
    func_020862F0(data + 32, 32);
    func_02083194(data + 32, data + 34, 30);
    ((struct Obj22796 *)data)->f20 = 0x14A5;
    func_020862F0(data + 32, 32);
    func_0207FA0C();
    func_0207FA40(data + 32, 0x2000, 32);
    func_0207FADC();
    func_02082D44(data + 32, p + 0x1134, 32);
    func_020307B0(allocation);
    ARC_TOOL_DeleteHandle(v);
}







void func_021E3BB0(char *p)
{
    int i;
    int j;
    int component;
    int shift;
    char *q;
    for (i = 0; i < 16; i++) {
        q = p + i * 2;
        ((TradeWork *)q)->f1154 = 0;
        for (j = 0; j < 3; j++) {
            shift = j * 5;
            component = (((TradeWork *)q)->f1134 >> shift) & 31;
            if (component)
                component--;
            ((TradeWork *)q)->f1154 |= (unsigned short)((component & 31) << shift);
        }
    }
    func_0207FA0C();
    func_0207FA40(p + 0x1154, 0x2000, 32);
    func_0207FADC();
}







void func_021E3C20(char *p)
{
    Template_021E3A40 t = d_021E7C0C;
    Config_021E3A40 c;
    u16 a, b, d;
    MI_CpuFill8(&c, 0, 32);
    c.f0 = &t;
    c.f4 = 4;
    c.f8 = ((TradeWork *)p)->f9C4;
    c.fC = 4;
    c.f1C = 1;
    c.f10 = 7;
    c.f14 = 0;
    c.f18 = 2;
    a = *(u32 *)&((TradeWork *)p)->f894;
    t.e[1].f8 = a;
    b = *(u32 *)&((TradeWork *)p)->f880;
    t.e[1].fA = b;
    d = *(u32 *)&((TradeWork *)p)->f8B0;
    t.e[1].fC = d;
    t.e[1].fE = 6; t.e[1].f10 = 5; t.e[1].f12 = 4;
    t.e[1].f18 = 0; t.e[1].f1C = 0x54C;
    t.e[2].f8 = a; t.e[2].fA = b; t.e[2].fC = d;
    t.e[2].fE = 9; t.e[2].f10 = 8; t.e[2].f12 = 7;
    t.e[2].f18 = 8; t.e[2].f1C = 0x54C;
    t.e[3].f8 = a; t.e[3].fA = b; t.e[3].fC = d;
    t.e[3].fE = 22; t.e[3].f10 = 21; t.e[3].f12 = 20;
    t.e[3].f18 = 48; t.e[3].f1C = 0x54C;
    (*(void * *)&((TradeWork *)p)->f9C0) = TOUCHBAR_Create(&c, ((TradeWork *)p)->f5F4);
    func_021B6558((*(void * *)&((TradeWork *)p)->f9C0), 9, 0);
    func_021B6558((*(void * *)&((TradeWork *)p)->f9C0), 8, 0);
    TOUCHBAR_SetAllButtonsPriority((*(void * *)&((TradeWork *)p)->f9C0), 2);
}







unsigned char func_021E3D04(void *mon, unsigned int heap)
{
    int old;
    unsigned short result;
    int species;
    void *data;
    result = 0;
    old = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    if (func_02017E88(mon, 0xA9, 0)) {
        if (!func_02017E88(mon, 0x4C, 0)) {
            unsigned short form = func_02017E88(mon, 0x6F, 0);
            data = POKE_PERSONAL_Create((unsigned short)species, form, heap);
            result = POKE_PERSONAL_GetParam(data, 0x21);
            POKE_PERSONAL_Delete(data);
        } else {
            result = 1;
            if (species != 0x1EA)
                result = 8;
        }
        result++;
    }
    func_02017DE4(mon, old);
    return result;
}








void func_021E3D88(char *p, int box, unsigned char *out)
{
    unsigned char i;

    for (i = 0; i < 30; i++)
        out[i] = func_021E3D04(func_02007A18((*(void * *)&((TradeWork *)p)->f828), box, i), ((TradeWork *)p)->f5F4);
}







void func_021E3DBC(char *p, void *party, unsigned char *out)
{
    int count;
    unsigned char i;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < 6; i++) {
        if (count > i)
            out[i] = func_021E3D04(func_020185F0(POKEPARTY_GetMember(party, i)), ((TradeWork *)p)->f5F4);
        else
            out[i] = 0;
    }
}







int func_021E3E00(char *p, int i)
{
    while (i < ((TradeWork *)p)->f630 + 1) {
        if (i == ((TradeWork *)p)->f630) {
            func_021E3DBC(p, ((TradeWork *)p)->f838, (unsigned char *)(p + 0x2E0));
            return 1;
        }
        func_021E3D88(p, i, (unsigned char *)(p + 0x10 + i * 30));
        break;
    }
    return 0;
}








/*
 * Unlabelled Thumb tail-call wrapper after pool_021E3E3C, seeded so that
 * ov117 func_021D4BF4 has a witness: forwards the two ov119 tables and the
 * u16 heap id held at +0x5F4 to the ARM function 0x0204A48C.
 *
 * Addresses are Black-image addresses.
 */
void func_021E3E40(char *p)
{
    CLACT_InitSystem((const struct Cfg *)d_021E7CE4, (u32)d_021E7D40, ((TradeWork *)p)->f5F4);
}







/*
 * Tail call: forward the two ov119 data pointers and *(u16*)(p+0x5f4) to
 * the ARM helper. Non-SDK dep of func_021DFDA0's preamble.
 *
 * Addresses are Black-image addresses.
 */
void func_021E3E60(void *p)
{
    CLACT_InitSystem((const struct Cfg *)(&d_021E7CC8), (u32)(&d_021E7D40), ((TradeWork *)p)->f5F4);
}






void func_021E3E80(char *p)
{
    void *v;
    int kind;
    int mode;
    v = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    mode = func_021D8AA8(p);
    kind = 4;
    if (mode == 0)
        kind = 11;
    func_02049B68(v, 9, 0, 0, 0, ((TradeWork *)p)->f5F4);
    if (((TradeWork *)p)->f86C == 0)
        ((TradeWork *)p)->f86C = func_02049740(v, 10, 2, 0, 0, ((TradeWork *)p)->f5F4);
    func_02049990(v, kind, (int)2, (int)0, (unsigned short)((*(unsigned int *)&((TradeWork *)p)->f86C)), (int)0, (int)0, (unsigned int)(((TradeWork *)p)->f5F4));
    ARC_TOOL_DeleteHandle(v);
}







void func_021E3F08(char *p)
{
    u32 v;

    v = (*(unsigned int *)&((TradeWork *)p)->f86C);
    if (v != 0)
        func_0203FB44((int)2, (u16)v, (u16)(v >> 16));
    (*(unsigned int *)&((TradeWork *)p)->f86C) = 0;
}






void func_021E3F30(char *p)
{
    void *v;
    v = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    func_02049990(v, 12, (int)4, (int)0, (unsigned short)(((TradeWork *)p)->f870), (int)0, (int)0, (unsigned int)(((TradeWork *)p)->f5F4));
    ARC_TOOL_DeleteHandle(v);
}






/*
 * Empty stub.
 */
void func_021E3F70(void *p)
{
}







void func_021E3F74(char *p)
{
    void *v;

    v = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    func_02049B68(v, 0x11, 4, 0, 0xC0, ((TradeWork *)p)->f5F4);
    (*(void * *)&((TradeWork *)p)->f874) = (void *)func_02049740(v, 0xD, 7, 0, 0, ((TradeWork *)p)->f5F4);
    (*(void * *)&((TradeWork *)p)->f870) = (void *)func_02049740(v, 0xD, 5, 0, 0, ((TradeWork *)p)->f5F4);
    ARC_TOOL_DeleteHandle(v);
    func_021E4324(p, (int)((*(void * *)&((TradeWork *)p)->f874)));
}







void func_021E3FE4(char *p)
{
    (*(void * *)&((TradeWork *)p)->f644) = func_0201F5DC((void *)6, 15, 0, ((TradeWork *)p)->f5F4);
}






void func_021E4000(char *p)
{
    func_021E43DC(p);
    if (((TradeWork *)p)->f870) {
        func_0203FB44((int)5, (unsigned short)(((TradeWork *)p)->f870), (unsigned short)(((TradeWork *)p)->f870 >> 16));
        *(int *)&((TradeWork *)p)->f870 = 0;
    }
    if (((TradeWork *)p)->f874) {
        func_0203FB44((int)7, (unsigned short)(((TradeWork *)p)->f874), (unsigned short)(((TradeWork *)p)->f874 >> 16));
        *(int *)&((TradeWork *)p)->f874 = 0;
    }
    if (((TradeWork *)p)->f644) {
        func_0203FB44((int)6, (unsigned short)(((TradeWork *)p)->f644), (unsigned short)(((TradeWork *)p)->f644 >> 16));
        *(int *)&((TradeWork *)p)->f644 = 0;
    }
}






void func_021E4068(char *p)
{
    void *v;
    int a;
    if (((TradeWork *)p)->f888 == 0) {
        v = func_020490F4(func_020275E4(), ((TradeWork *)p)->f5F4);
        ((TradeWork *)p)->f8A4 = CLACT_RegisterCharacter(v, func_02027618(), 0, 1, ((TradeWork *)p)->f5F4);
        ((TradeWork *)p)->f888 = CLACT_RegisterPaletteEx(v, func_02027614(), 1, 0, 0, 3, ((TradeWork *)p)->f5F4);
        a = func_0202761C(2);
        ((TradeWork *)p)->f8B8 = CLACT_RegisterCellAnim(v, a, func_02027620(2), ((TradeWork *)p)->f5F4);
        ARC_TOOL_DeleteHandle(v);
    }
}






void func_021E40EC(char *p, int a1, int a2)
{
    Tbl2 tbl = d_021E7DD0;
    void *v;
    v = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    func_02049990(v, tbl.w[a2], 4, 0, (unsigned short)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->f5F4);
    if (a1 != 0) {
        func_02040618(4, 0, 0x80);
    } else {
        func_02040618(4, 0, 0);
    }
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04, 0);
    ARC_TOOL_DeleteHandle(v);
    func_02040588(4, 1);
}






void func_021E4174(char *p)
{
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_021E6700(p);
    func_020414EC(4);
    func_02041B6C(4);
}






unsigned short func_021E41A0(int i, int row, char *p, int mode)
{
    if (i >= ((TradeWork *)p)->f638)
        i -= ((TradeWork *)p)->f638;
    if (i < 12) {
        if (mode)
            return (*(unsigned short **)(p + 0x1180))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1178))[i + (row * 32 + 18)];
    } else {
        i = (i - 12) % 20;
        if (mode)
            return (*(unsigned short **)(p + 0x117C))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1174))[i + (row * 32 + 18)];
    }
}






/*
 * lever: initialize the inner counter before calculating the two outer cursors.
 */
int func_021E421C(char *p, int x, int y)
{
    int i, j, a, b;
    char *q, *r, *s;
    for (i = 0; i < 12; i++) {
        j = 0;
        q = p + i * 5;
        s = p + i * 20;
        for (; j < 5; j++) {
            if (*(unsigned char *)(q + j + 0xebc)) {
                r = s + j * 4;
                a = ((TradeWork *)r)->fDCC - 5;
                b = ((TradeWork *)r)->fDCE - 8;
                if (a < 0) a -= 8;
                a /= 8;
                b /= 8;
                if (a <= x && a + 3 > x && b <= y && b + 3 > y) return 1;
            }
        }
    }
    return 0;
}






void func_021E42B4(char *p)
{
    int x, y, n, mode;
    n = ((TradeWork *)p)->f107C / 8;
    func_021E4DBC(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = func_021E421C(p, x, y);
            func_02042FB0(7, x, y, func_021E41A0(n + x, y, p, mode));
        }
    }
    ((TradeWork *)p)->f108C = ((TradeWork *)p)->f107C % 8;
    ((TradeWork *)p)->f1084 = 1;
    func_02041B6C(7);
}






/*
 * 2026-10-03 (wB3 lane07): EXACT. The doubled zero-extension of the loop-invariant
 * comes from an int parameter stored in a u16 local and then added as (int)e.
 */
void func_021E4324(char *p, int d)
{
    int i;
    u16 e;

    *(Buf * *)&((TradeWork *)p)->f1174 = ARC_TOOL_LoadMember(0x66, 0xE, ((TradeWork *)p)->f5F4);
    *(Buf * *)&((TradeWork *)p)->f1178 = ARC_TOOL_LoadMember(0x66, 0xF, ((TradeWork *)p)->f5F4);
    *(Buf * *)&((TradeWork *)p)->f117C = ARC_TOOL_LoadMember(0x66, 0x19, ((TradeWork *)p)->f5F4);
    *(Buf * *)&((TradeWork *)p)->f1180 = ARC_TOOL_LoadMember(0x66, 0x1A, ((TradeWork *)p)->f5F4);
    e = d;
    for (i = 0; i < 0x300; i++) {
        (*(Buf * *)&((TradeWork *)p)->f1174)->v[i] += (int)e;
        (*(Buf **)(p + 0x1178))->v[i] += (int)e;
        (*(Buf **)(p + 0x117C))->v[i] += (int)e;
        (*(Buf **)(p + 0x1180))->v[i] += (int)e;
    }
    (*(unsigned short *)&((TradeWork *)p)->f107C) = (*(unsigned int *)&((TradeWork *)p)->f63C) - 0x50;
    func_021E42B4(p);
}





void func_021E43DC(char *p)
{
    if (((TradeWork *)p)->f1174) {
        func_020307B0(((TradeWork *)p)->f1174);
        ((TradeWork *)p)->f1174 = 0;
        func_020307B0(((TradeWork *)p)->f1178);
        ((TradeWork *)p)->f1178 = 0;
        func_020307B0(((TradeWork *)p)->f117C);
        ((TradeWork *)p)->f117C = 0;
        func_020307B0(((TradeWork *)p)->f1180);
        ((TradeWork *)p)->f1180 = 0;
    }
}





/*
 * arithmetic: count additions wrap unsigned then compare signed results; indexed address uses typed word-pointer addition under valid-object preconditions; the guarded int counter never increments above INT_MAX.
 * note 2026-10-05 (wave D9r lane 131): removed the 11 dead first assignments
 * (`off1 = 0x5F4;` before `off1 = 0x6B8;`; `off3 = 0x828;` before `off3 =
 * 0x730;` and 9 more). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void func_021E4420(char *p)
{
    int off1, h, off, off2, off3;
    int a,b,c,d,e,f,g;
    int i, zero;
    char *q;
    off = 0x5F4;
    func_02049B40(23,5,4,448,32,*(u16 *)(p+off));
    i = 0;
    if (i >= (int)((u32)*(int *)(p+off+0x3C)+1u)) goto done;
        zero = 0;
        off1 = 0x6B8;
        off = 0x630;
        off3 = 0x730;
        off2 = 0x730;
        a = 0x6B8;
        b = 0x6B8;
        c = 0x728;
        d = 0x730;
        e = 0x6B8;
        f = 0x6B8;
        g = 0x630;
        h = 0x6B8;
        do {
            q = (char *)((u32 *)p+i);
            if (*(u32 *)(q+h) == 0)
                *(u32 *)(q+off1) = BMP_WIN_Create(5,0,0,15,2,14,0);
            if (i == *(int *)(p+off))
                func_02045CAC((*(void * *)&((TradeWork *)p)->f720),16,*(void **)(p+off2));
            else func_0200785C((*(void * *)&((TradeWork *)p)->f828),i,*(void **)(p+off3));
            GF_FONT_SetTextColor(15,2,zero);
            BMP_Clear(BMP_WIN_GetBmp(*(void **)(q+a)),zero);
            PRINTSYS_Print(BMP_WIN_GetBmp(*(void **)(q+b)),zero,1,*(void **)(p+d),*(void **)(p+c));
            BMP_WIN_TransferChars(*(void **)(q+e));
            BMP_WIN_SetPosY(*(void **)(q+f),zero);
        } while (++i < (int)((u32)*(int *)(p+g)+1u));
done:;
}





void func_021E4570(char *p)
{
    int i;
    for (i = 0; i < 25; i++) {
        if (*(void **)(p + i * 4 + 0x6B8)) {
            BMP_WIN_Delete(*(void **)(p + i * 4 + 0x6B8));
            *(void **)(p + i * 4 + 0x6B8) = 0;
        }
    }
}





/*
 * arithmetic: full-word index and scroll ADD/SUB/MUL use modulo-2^32 arithmetic; casts restore the original signed comparisons.
 * note 2026-10-05 (wave D9r lane 131): removed the 3 dead first assignments
 * (`off1 = 0x638;` before `off1 = 0x6B8;`; `off2 = 0x638;` before `off2 =
 * 0x6B8;` and 1 more). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void func_021E4598(char *p)
{
    int x, y, scroll, first, i, n, pos, idx;
    int off1, off2, bound;
    char *q;
    scroll = ((TradeWork *)p)->f107C / 8;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 64; x++) {
            func_02042FB0(5, x, y, 0);
        }
    }
    if (((TradeWork *)p)->f107C < 96) first = ((TradeWork *)p)->f630;
    else first = (((TradeWork *)p)->f107C - 96) / 160;
    i = 0;
    off1 = 0x6B8;
    off2 = 0x6B8;
    bound = 0x630;
    for (; i < 3; i++) {
        idx = (int)((u32)first+(u32)i);
        n = *(int *)(p + bound);
        if (idx > n) idx = (int)((u32)idx-(u32)n-1u);
        else if (idx < 0) idx = (int)((u32)idx+(u32)n+1u);
        if (idx == n) {
            pos = (int)((*(unsigned int *)&((TradeWork *)p)->f638)-(u32)scroll);
            if (scroll > pos) scroll = (int)((u32)scroll-(*(unsigned int *)&((TradeWork *)p)->f638));
            else pos = (int)(0u-(u32)scroll);
        } else pos = (int)((u32)idx*20u+12u-(u32)scroll);
        if (pos >= -10 && pos <= 33) {
            q = (char *)((u32)p+(u32)idx*4u);
            BMP_WIN_SetPosX(*(void **)(q + off1), pos + 1);
            BMP_WIN_MakeScreen(*(void **)(q + off2));
        }
    }
    func_02041B6C(5);
}





void func_021E467C(char *p)
{
    int i, j, z;
    void *arc;
    char *q;
    ObjTmpl t;
    arc = func_020490F4(7, ((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f87C = (void *)CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 1, 0x60, ((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f8AC = (void *)CLACT_RegisterCellAnim(arc, func_0201BC78(), func_0201BCB4(), ((TradeWork *)p)->f5F4);
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 5; j++) {
            z = 0;
            t.x = z;
            t.y = z;
            t.prio = 1;
            t.pal = 0x10;
            t.mode = 3;
            q = p + i * 20 + j * 4;
            ((TradeWork *)q)->f9CC = (void *)CLACT_RegisterCharacter(arc, 0x51b, z, 1, ((TradeWork *)p)->f5F4);
            ((TradeWork *)q)->fAC0 = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->f9C4), (unsigned int)((TradeWork *)q)->f9CC,
                (unsigned int)((TradeWork *)p)->f87C, (unsigned int)((TradeWork *)p)->f8AC, &t, 1, ((TradeWork *)p)->f5F4);
            t.prio = z;
            t.pal = 0xf;
            ((TradeWork *)q)->fBB0 = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->f9C4), (unsigned int)(*(void * *)&((TradeWork *)p)->f894),
                (unsigned int)(*(void * *)&((TradeWork *)p)->f880), (unsigned int)(*(void * *)&((TradeWork *)p)->f8B0), &t, 1, ((TradeWork *)p)->f5F4);
            CLACT_SetActorAutoAnim(((TradeWork *)q)->fAC0, z);
            CLACT_SetActorDrawEnable(((TradeWork *)q)->fAC0, z);
            CLACT_SetActorDrawEnable(((TradeWork *)q)->fBB0, z);
            CLACT_SetActorAutoAnim(((TradeWork *)q)->fBB0, 1);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}





/*
 * follower: two zero padding bytes at 0x021E4886 before labelled 021E4888.
 */
void func_021E4810(char *p, int n)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (*(int *)(p + n * 20 + i * 4 + 0xac0)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + n * 20 + i * 4 + 0xac0)));
            *(int *)(p + n * 20 + i * 4 + 0xac0) = 0;
        }
        if (*(int *)(p + n * 20 + i * 4 + 0xbb0)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + n * 20 + i * 4 + 0xbb0)));
            *(int *)(p + n * 20 + i * 4 + 0xbb0) = 0;
        }
        if (*(int *)(p + n * 20 + i * 4 + 0x9cc)) {
            CLACT_ReleaseCharacter(*(int *)(p + n * 20 + i * 4 + 0x9cc));
            *(int *)(p + n * 20 + i * 4 + 0x9cc) = 0;
        }
    }
}





void func_021E4888(char *p)
{
    int i;
    func_021E69A4(p);
    for (i = 0; i < 12; i++) func_021E4810(p, i);
    if ((*(int *)&((TradeWork *)p)->f87C)) {
        CLACT_ReleasePalette((*(int *)&((TradeWork *)p)->f87C));
        (*(int *)&((TradeWork *)p)->f87C) = 0;
    }
    if ((*(int *)&((TradeWork *)p)->f8AC)) {
        CLACT_ReleaseCellAnim((*(int *)&((TradeWork *)p)->f8AC));
        (*(int *)&((TradeWork *)p)->f8AC) = 0;
    }
    if (((TradeWork *)p)->f1184) func_020307B0(((TradeWork *)p)->f1184);
    ((TradeWork *)p)->f1184 = 0;
}





void func_021E48E0(char *p)
{
    int i;
    func_021E7058(p);
    func_021E1CA8(p);
    for (i = 0; i < 10; i++) {
        if (*(int *)(p + i * 4 + 0xefc)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + i * 4 + 0xefc)));
            *(int *)(p + i * 4 + 0xefc) = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleasePalette(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 12; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 18; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
}





void func_021E496C(int x, int y, unsigned short *out)
{
    out[0] = (x + 1) * 0x18;
    out[1] = y * 0x18 + 0x48;
}





int func_021E4984(int v, int a, int b, char *p, int *out)
{
    int n, m;
    if (a >= 2) {
        n = func_021D8AF4(a, p);
        m = func_021D8B0C(a, b);
        *out = 0;
        return (int)func_021D8DD0((void *)v, n, m, p);
    }
    if (b < 3) {
        *out = 1;
        return (int)func_021D8DD0((void *)v, ((TradeWork *)p)->f630, a + b * 2, p);
    }
    return 0;
}





char *func_021E49DC(int a, int b, char *p)
{
    int n;
    if (a >= 2) {
        n = func_021D8AF4(a, p);
        return func_021D8E24(n, func_021D8B0C(a, b), p);
    }
    if (b < 3)
        return func_021D8E24(((TradeWork *)p)->f630, a + b * 2, p);
    return 0;
}





void func_021E4A1C(char *p)
{
    short xy[2];
    int i, j;
    char *q, *r;
    for (i = 0; i < 5; i++) {
        q = p + i * 4;
        for (j = 0; j < 12; j++) {
            r = q + j * 20;
            if (CLACT_GetActorDrawEnable((struct Obj *)((*(int *)&((TradeWork *)r)->fBB0)))) {
                CLACT_GetActorSurfacePos((struct Actor *)(*(int *)&((TradeWork *)r)->fBB0), (struct PtS *)xy, 1);
                ((TradeWork *)p)->fF54 = xy[0];
                ((TradeWork *)p)->fF58 = xy[1];
            }
        }
    }
}





int func_021E4A84(char *p, int i)
{
    int v = ((TradeWork *)p)->f800;
    if (v != 0 && v - 1 == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}




int func_021E4AA4(int i, int x)
{
    if (x == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}





/*
 * Normalise the third argument to 0 or 1 and tail call the setter.
 */
void func_021E4AB8(int a0, int a1, int a2)
{
    CLACT_SetActorObjMode((struct Actor *)a1, a2 != 0);
}




void func_021E4AD0(char *p, int a1, int a2, int a3, int a4, int a5)
{
    int flag = 0;
    if (func_021DF614(p, a1, a2)) {
        flag = 1;
    }
    func_021E4AB8((int)p, ((int (*)[5])(p + 0xAC0))[a5][a2], flag);
}




void func_021E4B00(char *p, int v, int a, int row, int flag)
{
    int j, rec, id, b2, b3, idx, n;
    Ent *e;
    Info info;
    int kind;
    u16 pos[2];
    Pt pt;
    enum { VRAM_BASE = 0x06600000 } vram;
    if (a == ((TradeWork *)p)->fF74 && func_020355C4() == 0) {
        CLACT_SetActorDrawEnable(((void **)(p + row * 20 + 0xbb0))[((TradeWork *)p)->fF78], 1);
    }
    for (j = 0; j < 5; j++) {
        rec = func_021E4984(v, a, j, p, &kind);
        e = (Ent *)func_021E49DC(a, j, p);
        if (e == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        if (e->id == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        ((u8 *)(p + row * 5) + j)[0xd90] = a;
        b2 = e->b2;
        id = e->id;
        b3 = e->b3;
        if (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 == ((u8 *)(p + row * 5) + j)[0xd18]
            && b3 == ((u8 *)(p + row * 5) + j)[0xd54]) {
            CLACT_SetActorDrawEnable(*(void **)(p + row * 20 + j * 4 + 0xac0), 1);
            func_021E4AD0(p, a, j, rec, kind, row);
        } else if (id != *(u16 *)(p + row * 10 + j * 2 + 0xca0)
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 != ((u8 *)(p + row * 5) + j)[0xd18])
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b3 != ((u8 *)(p + row * 5) + j)[0xd54])) {
            *(u16 *)(p + row * 10 + j * 2 + 0xca0) = id;
            *(u8 *)(p + row * 5 + j + 0xd18) = b2;
            *(u8 *)(p + row * 5 + j + 0xd54) = b3;
            func_021E496C(a, j, pos);
            CLACT_GetActorImageProxy(*(void **)(p + row * 20 + j * 4 + 0xac0), (struct Struct36 *)(&info));
            n = func_021D8AF4(a, p);
            idx = func_021D8B0C(a, j);
            idx += n * 30;
            CLACT_GetActorSurfacePos((struct Actor *)*(void **)(p + row * 20 + j * 4 + 0xac0), (struct PtS *)&pt, 1);
            if (flag == 1 && pt.x >= -16 && pt.x <= 0x110) {
                if (func_02061CA4((void *)0x23, info.c, *(int *)(p + 0x1184) + idx * 0x200, 0x200) == 0) {
                    vram = VRAM_BASE;
                    func_02082D44((const void *)(*(int *)(p + 0x1184) + idx * 0x200), (void *)(vram + info.c), 0x200);
                }
            } else {
                vram = VRAM_BASE;
                func_02082D44((const void *)(*(int *)&((TradeWork *)p)->f1184 + idx * 0x200), (void *)(vram + info.c), 0x200);
            }
            func_021E4AD0(p, a, j, rec, kind, row);
            CLACT_SetActorPaletteOffset(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), POKE_TOOL_GetIconPalette((void *)rec), 1);
            CLACT_SetActorAutoAnim(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 0);
            CLACT_SetActorDrawEnable(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 1);
        }
        if (func_02017E88((void *)rec, 0x4c, 0) == 0 && func_021E4A84(p, id)) {
            ((u8 *)(p + row * 5) + j)[0xebc] = 1;
        }
    }
}




/*
 * lever: a separate adjusted-coordinate local keeps the subtraction before division.
 */
int func_021E4DBC(char *p)
{
    int x, q, r, v;
    x = ((TradeWork *)p)->f107C;
    if (x < 48) x = 0;
    else if (x < 96) x = 1;
    else {
        v = x - 96;
        q = v / 160;
        r = v - q * 160;
        x = q * 6 + 2;
        if (r >= 8) {
            if (r >= 152) x += 5;
            else x += (r - 8) / 24;
        }
    }
    return x;
}




int func_021E4E0C(char *p, int *out)
{
    int x, hi, n, t;
    x = func_021E4DBC(p);
    *out = x + 2;
    hi = x + 10;
    n = ((TradeWork *)p)->f634;
    if (*out >= n) *out -= n;
    n = ((TradeWork *)p)->f634;
    if (hi >= n) {
        t = ((TradeWork *)p)->fF74;
        if (t < 20) t = t + 1 + n;
        if (x <= t && t <= hi) return 1;
    } else {
        t = ((TradeWork *)p)->fF74;
        if (x <= t && t <= hi) return 1;
    }
    return 0;
}




/*
 * lever: i before n gives n the earlier spill slot.
 */
void func_021E4E64(int a, char *p, int b)
{
    int i, n, j;
    n = func_021E4DBC(p);
    if (((TradeWork *)p)->f1080 != n) {
        ((TradeWork *)p)->f1080 = n;
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 5; j++) {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xbb0), 0);
                *(unsigned char *)(p + i * 5 + j + 0xebc) = 0;
            }
        }
        ((TradeWork *)p)->f1090 = n;
        func_021E5164((int)p);
        for (i = 0; i < 12; i++) {
            func_021E4B00(p, a, n, func_021E5158(((TradeWork *)p)->f1080 + i), b);
            n++;
            if (n >= ((TradeWork *)p)->f634) n = 0;
        }
    }
    func_021E4F28(p);
}


/*
 * lever:    the hoisted column sum is written inside the else arm as two statements.
 */
void func_021E4F28(char *p)
{
    char *q;
    int i, off, y, row, j, x, ty, col;
    Pt_021E4F28 b, a;
    off = 0;
    y = ((TradeWork *)p)->f1080;
    for (i = 0; i < 12; i++) {
        row = func_021E5158(((TradeWork *)p)->f1080 + i);
        if (y >= ((TradeWork *)p)->f634) {
            y -= ((TradeWork *)p)->f634;
            off = ((TradeWork *)p)->f63C;
        }
        for (j = 0; j < 5; j++) {
            ty = j * 24 + 0x20;
            if (y == 0) x = 0x1c;
            else if (y == 1) x = 0x3c;
            else {
                col = (y - 2) / 6 * 160;
                col += (y - 2) % 6 * 24 + 0x14;
                x = col + 0x60;
            }
            b.x = off + (x - ((TradeWork *)p)->f107C);
            b.y = ty;
            a = b;
            if (func_021DF6B4(p, y, j) && func_020355C4() == 1) {
                b.y -= 8;
                q = p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority((*(int *)&((TradeWork *)q)->fAC0), 11);
            } else {
                q = p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority((*(int *)&((TradeWork *)q)->fAC0), 0x1c - i);
            }
            CLACT_AddActorSurfacePos((struct Obj *)((*(int *)&((TradeWork *)q)->fAC0)), (const struct Vec2 *)(&b), 1);
            if (*(u8 *)(p + row * 5 + j + 0xebc)) {
                *(Pt_021E4F28 *)(q + 0xdcc) = a;
            }
            b.y = ty + 3;
            CLACT_AddActorSurfacePos((struct Obj *)((*(int *)&((TradeWork *)q)->fBB0)), (const struct Vec2 *)(&b), 1);
        }
        y++;
    }
}


/*
 * lever: initial guard is a forward goto, with the exit after the body.
 */
void func_021E5098(char *p, int b)
{
    int i, n, x, t, out;
    void *a;
    if (b == 0) *(int *)&((TradeWork *)p)->f1184 = (int)func_02030734(((TradeWork *)p)->f5F4, 0x5ac00, 0, d_021E8530, 0x50b);
    a = func_020490F4(7, ((TradeWork *)p)->f5F4);
    goto check;
body:
    {
        n = b * 30;
        for (i = 0; i < 30; i++) {
            if (b == 24 && i == 6) break;
            x = (int)func_021D8DD0((void *)(((TradeWork *)p)->f828), b, i, p);
            if (x) x = POKE_TOOL_GetGraphicIndex((void *)x);
            else x = POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0);
            t = (int)func_02049DF4(a, x, 0, (u32)(&out), ((TradeWork *)p)->f5F4);
            func_02082D44(((struct Obj22808 *)out)->f14, (void *)(*(int *)&((TradeWork *)p)->f1184 + n * 512), 512);
            n++;
            func_020307B0((void *)t);
        }
    }
    goto done;
check:
    if (b < 25) goto body;
done:
    ARC_TOOL_DeleteHandle(a);
}



/*
 * Signed remainder by 12.  The MSL divide helper returns the quotient in r0
 * and the remainder in r1, so `x % 12` moves r1 down to r0.
 */
s32_021E4F28 func_021E5158(s32_021E4F28 x)
{
    return x % 12;
}


/*
 * extent: two zero padding bytes at 0x021E51A2.
 */
void func_021E5164(int p)
{
    int i, j;
    for (i = 0; i < 12; i++)
        for (j = 0; j < 5; j++)
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xac0), 0);
}


/*
 * lever: pos precedes the integer locals; a typed return-base temporary
 * keeps the row/column byte offsets spilled instead of reusing r7.
 * initialization: the only ov119 calls are D9EEC and D9F5C. D9F24
 * passes p+f80 as outA; D9EBC forwards outA from its only caller DA3BC,
 * where r1=p+f98. Thus all reachable hit paths enter the outA block
 * before reading slot through outSlot. No default value is invented.
 * 0204B454 writes both coordinate halfwords through 0204B53C and then
 * subtracts the origin, itself written through 0204CF74/0204B0C8.
 */
int func_021E51A4(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow)
{
 Pt_021E51A4 pos;
 int column,slot,row;
 Object *tmp;
 for(row=0;row<12;row++) {
  for(column=0;column<5;column++) {
   CLACT_GetActorSurfacePos((struct Actor *)((Object *)p)->actors[row][column],(struct PtS *)&pos,1);
   if(pos.x<=x && x<pos.x+24 && pos.y<=y && y<pos.y+24) {
    if(outA) {
     slot=*(u8 *)(p+0xd90+row*5+column);
     if(slot==255)return 0;
     if(func_021D8B0C(slot,column)!=-1) {
      *outA=func_021D8AF4(slot,p);
      *outB=func_021D8B0C(slot,column);
     } else return 0;
    }
    if(outSlot) {*outSlot=slot;*outColumn=column;*outRow=row;}
    tmp=(Object *)p;
    return (int)tmp->actors[row][column];
   }
  }
 }
 return 0;
}


/*
 * interface: 02040618's legacy fourth argument is forwarded only to
 * 02042360, whose complete matched body reads r0-r2 and never r3.
 * The original calls here set only r0-r2; retain its three-input API.
 */
void func_021E5284(char *p,int mode)
{
 BgTemplate a,b;
 void *v;
 func_021E57E8(1);p[0x11ec]=1;
 a=d_021E7E24;func_0203FCA0(6,&a,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 b=d_021E7F44;func_0203FCA0(7,&b,2);
 if(mode==0) {
  v=func_020490F4(0x67,((TradeWork *)p)->f5F4);
  func_02049B68(v,5,6,0x6000,0,((TradeWork *)p)->f5F4);
  func_02049658((void *)((u32)v),4,7,0,0,0,((TradeWork *)p)->f5F4);
  func_020498F4((void *)((u32)v),6,7,0,0,0,((TradeWork *)p)->f5F4);
  func_02040618(7,0,0);ARC_TOOL_DeleteHandle(v);
 } else {
  v=func_020490F4(0x68,((TradeWork *)p)->f5F4);
  func_02049B68(v,1,6,0x6000,0,((TradeWork *)p)->f5F4);
  func_02049658((void *)((u32)v),0,7,0,0,0,((TradeWork *)p)->f5F4);
  func_020498F4((void *)((u32)v),2,7,0,0,0,((TradeWork *)p)->f5F4);
  func_02040618(7,0,0);ARC_TOOL_DeleteHandle(v);
 }
}


void func_021E53CC(int p)
{
    if (((TradeWork *)p)->f11EC != 0) {
        func_02040DA8(6, 1, 0);
        func_020403F4(6);
        func_020403F4(7);
        ((TradeWork *)p)->f11EC = 0;
    }
}


void func_021E53F8(char *p)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021E7D40);
    CLACT_InitSystem((const struct Cfg *)(&d_021E7CC8), (unsigned int)d_021E7D40, ((TradeWork *)p)->f5F4);
    func_021E57E8(0);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
}
