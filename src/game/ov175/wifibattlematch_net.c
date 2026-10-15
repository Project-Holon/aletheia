/*
 * file:     wifibattlematch_net.c
 * unit:     yes
 * function: func_021D4240, func_021D429C, func_021D42E0, func_021D4318, func_021D4448, func_021D44D4, func_021D458C, func_021D4608, func_021D4730, func_021D495C, func_021D4B3C, func_021D51BC, func_021D54E8, func_021D5560, func_021D5634, func_021D56D4, func_021D57BC, func_021D5908, func_021D5E24, func_021D6000, func_021D6048, func_021D60E0, func_021D61A4, func_021D61CC, func_021D61F0, func_021D62A4, func_021D639C, func_021D63B0, func_021D63BC, func_021D63C8, func_021D63DC, func_021D63F8, func_021D644C, func_021D6460, func_021D646C, func_021D6524, func_021D6550, func_021D65C8, func_021D65DC, func_021D65F0, func_021D6698, func_021D6724, func_021D6788, func_021D679C, func_021D67BC, func_021D6854, func_021D6954, func_021D6964, func_021D6A98, func_021D6B38, func_021D6BF4, func_021D6C54, func_021D6DB8, func_021D76D4, func_021D7BE4, func_021D7E18, func_021D8904, func_021D8BC4, func_021D8CF0, func_021D8E30, func_021D8EC8, func_021D8FA8, func_021D9064, func_021D9090, func_021D9344, func_021D95B0, func_021D965C, func_021D97A4, func_021D97B8, func_021D97C4, func_021D97D0, func_021D97E4, func_021D9804, func_021D9854, func_021D9868, func_021D9874, func_021D98B8, func_021D98CC, func_021D98D8, func_021D98E4, func_021D99F4, func_021D9A08, func_021D9A1C, func_021D9A30, func_021D9A50, func_021D9A9C, func_021D9B18, func_021D9B2C, func_021D9BC4, func_021D9C34, func_021D9D40, func_021D9D50, func_021D9DC8, func_021D9EA0, func_021D9ED0, func_021D9ED4, func_021D9EEC, func_021D9F04, func_021DA044, func_021DA054, func_021DA0D4, func_021DA1E4, func_021DA36C, func_021DA384, func_021DA390, func_021DA434, func_021DA45C, func_021DA470, func_021DA4B8, func_021DA4E8, func_021DA4F0, func_021DA4F8, func_021DA5B0, func_021DA6B8, func_021DADAC, func_021DADB4, func_021DADCC, func_021DAE00, func_021DAE18, func_021DAE54, func_021DAFB8, func_021DB160, func_021DB218, func_021DB228, func_021DB238, func_021DB248, func_021DB258, func_021DB294, func_021DB2D4, func_021DB300, func_021DB328, func_021DB350, func_021DB378, func_021DB3A4, func_021DB478, func_021DB6A0, func_021DB6A8, func_021DB72C, func_021DB7C0, func_021DBA00, func_021DBB00, func_021DBB54, func_021DBBAC, func_021DBC04, func_021DBDAC, func_021DBFA4, func_021DBFB4, func_021DC194, func_021DC1A0, func_021DC1E4, func_021DC200, func_021DC240, func_021DC268, func_021DC2A0, func_021DC2C0, func_021DC2D8, func_021DC2F4, func_021DC338, func_021DC5AC, func_021DC5C8, func_021DC5F8, func_021DC610, func_021DC66C, func_021DC680, func_021DC6A4, func_021DC6D0, func_021DC6FC, func_021DC738, func_021DC77C, func_021DC8A0, func_021DC8B4, func_021DC908, func_021DCA28, func_021DCAEC, func_021DCB58, func_021DCC28, func_021DCE08, func_021DCE24, func_021DCE40, func_021DCE48, func_021DCE50, func_021DCE58, func_021DCE60, func_021DCEE0, func_021DCFDC, func_021DCFFC, func_021DD008, func_021DD020, func_021DD02C, func_021DD034, func_021DD038, func_021DD040, func_021DD044
 * address:  0x021D4240
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ov177_id 0x000000B1 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034714 0x02034714 arm
 *   d_021E2C74 0x021E2C74 data a4
 *   d_021E2C80 0x021E2C80 data a4
 *   d_021E2DE0 0x021E2DE0 data
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E5440 0x021E5440 thumb ov177
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E567C 0x021E567C thumb ov177
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_021E7DF0 0x021E7DF0 thumb ov177
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_021E8628 0x021E8628 thumb ov177
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021E5868 0x021E5868 thumb ov177
 *   func_021E54E0 0x021E54E0 thumb ov177
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_021E5534 0x021E5534 thumb ov177
 *   func_021E867C 0x021E867C thumb ov177
 *   func_021E7E08 0x021E7E08 thumb ov177
 *   func_021E5980 0x021E5980 thumb ov177
 *   func_021E64C0 0x021E64C0 thumb ov177
 *   func_021E7774 0x021E7774 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02009448 0x02009448 thumb
 *   func_020092EC 0x020092EC thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_ToChars 0x02045A38 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_OAM_Check5BEC 0x02025BEC thumb
 *   PMSI_PARAM_IsValid 0x020245D4 thumb
 *   PMSI_PARAM_InitSentence 0x020242A4 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_02040588 0x02040588 arm
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   DWC_RAPCOMMON_CreateSubHeap 0x02156E30 thumb
 *   DWC_RAPCOMMON_SetHeapTag 0x02156F50 thumb
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb
 *   TRADE_HISTORY_GetFromSave 0x02009EC8 thumb
 *   func_021E8AC0 0x021E8AC0 thumb ov177
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   MISC_SAVEDATA_InsertRecentValue 0x0200ED54 thumb
 *   func_02008530 0x02008530 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_02012944 0x02012944 thumb
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   func_02008554 0x02008554 thumb
 *   func_021E5C20 0x021E5C20 thumb ov177
 *   func_021E5D40   0x021E5D40  thumb
 *   func_021E89D0   0x021E89D0  thumb
 *   func_021E8A00   0x021E8A00  thumb
 *   POKETRADE_2D_DeleteMarkingIcon   0x021E5EF8  thumb  ov119
 *   func_021E5F24   0x021E5F24  thumb
 *   func_021E64C8  0x021E64C8  thumb  ov177
 *   func_021E65FC  0x021E65FC  thumb  ov177
 *   func_021E7520 0x021E7520 thumb ov177
 *   func_021E7710   0x021E7710  thumb
 *   func_021E777C 0x021E777C thumb ov177
 *   BSUBWAY_SAVEDATA_SetStat 0x0200DFE4 thumb
 *   BSUBWAY_SAVEDATA_IncStat  0x0200E008  thumb
 *   func_021E888C 0x021E888C thumb ov177
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   func_0200E6E8 0x0200E6E8 thumb
 *   MISC_SAVEDATA_CopyQuadRecord 0x0200E6FC thumb
 *   GAME_DATA_GetField1A0 0x0201283C thumb
 *   WIFILIST_GetGsProfileId 0x02009CC0 thumb
 *   func_020173EC 0x020173EC thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   NHTTP_RAP_EvilCheckAllocArray 0x021B9A64 thumb ov114
 *   NHTTP_RAP_EvilCheckSetElement 0x021B9A94 thumb ov114
 *   NHTTP_RAP_VerifySignature 0x021B9A1C thumb ov114
 *   NHTTP_RAP_EvilCheckFreeArray 0x021B9A8C thumb ov114
 *   KEY_GetTrg                0x020362DC  arm
 *   func_0200FB24                0x0200FB24  thumb
 *   GFL_NET_GetRunState                0x0203CD98  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021E84F8 0x021E84F8 thumb ov177
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   BATTLE_BOX_SetLockFlags 0x0200BBC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   REGULATION_BuildParty 0x0200B2A4 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   REGULATION_InitParty 0x0200B1F8 thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   BUTTON_MAN_ConvertUcs2ToSjis  0x02052274  arm
 *   func_02167ED8 0x02167ED8 arm ov009
 *   RTC_ConvertDateTimeToSecond 0x02089004 arm
 *   RTC_ConvertSecondToDateTime 0x020891E0 arm
 *   RTC_ConvertDateToDay 0x02088F58 arm
 *   func_0200FA84 0x0200FA84 thumb
 *   REGULATION_Card_GetCupName  0x0200B074  thumb
 *   func_021E5D68  0x021E5D68  thumb  ov177
 *   func_021E7E3C 0x021E7E3C thumb ov177
 *   func_021E82BC  0x021E82BC  thumb  ov177
 *   func_021E8338 0x021E8338 thumb ov177
 *   func_021E8420 0x021E8420 thumb ov177
 *   func_021E88B0 0x021E88B0 thumb ov177
 *   POKEPARTY_Init 0x0201A948 thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   REGULATION_Card_CalcCrc  0x0200B1C4  thumb
 *   func_020185F0  0x020185F0  thumb
 *   POKE_TOOL_GetBoxParamSize  0x020173E8  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02030734 0x02030734 arm
 *   func_02009860 0x02009860 thumb
 *   func_0200853C 0x0200853C thumb
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   d_021E2EE0 0x021E2EE0 data a4
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2C90 0x021E2C90 data a4
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   DWC_RAPCOMMON_HandleNetError  0x02157170  thumb
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   func_0200FAAC  0x0200FAAC  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   STD_TSPrintf                 0x0208D7E0  arm
 *   d_021E2EFC                   0x021E2EFC  data
 *   DWC_RAP_StartMatchWithFilter  0x0215580C  thumb
 *   GFL_NET_STATE_WifiEnterRandomMatch  0x0203C304  arm
 *   DWC_RAP_SetVchatEnabled  0x02156BC4  thumb
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   DWC_RAP_IsStateInSession  0x02156CD0  thumb  ov009
 *   g_021E2C8C     0x021E2C8C  data
 *   DWC_AddMatchKeyInt  0x0216C8DC  arm  ov009
 *   d_021E2E10          0x021E2E10  data
 *   DWC_GetMatchIntValue  0x0216CB30  arm
 *   _s32_div_f            0x0209C0A4  arm
 *   DWC_ScInitialize 0x021DEE3C arm ov175
 *   DWC_ScGetLoginCertificate 0x021DF490 arm ov175
 *   DWC_ScCreateSessionAsync 0x021DF018 arm ov175
 *   DWC_ScGetSessionId 0x021DF20C arm ov175
 *   DWC_ScProcess 0x021DEFDC arm ov175
 *   DWC_ScGetConnectionId 0x021DF224 arm ov175
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   DWC_ScSetSessionId 0x021DF1C8 arm ov175
 *   DWC_ScSetReportIntentionAsync 0x021DF09C arm ov175
 *   DWC_ScSubmitReportAsync 0x021DF130 arm ov175
 *   DWC_ScDestroyReport  0x021DF458  arm
 *   DWC_ScShutdown       0x021DEF58  arm
 *   DWC_ScCreateReport  0x021DF23C  arm
 *   DWC_ScReportBeginGlobalData  0x021DF298  arm
 *   DWC_ScReportBeginPlayerData  0x021DF2C8  arm
 *   DWC_ScReportBeginTeamData  0x021DF2F8  arm
 *   DWC_ScReportBeginNewPlayer  0x021DF328  arm
 *   DWC_ScReportSetPlayerData  0x021DF358  arm
 *   DWC_ScReportEnd  0x021DF3B0  arm
 *   func_021DF420 0x021DF420 arm ov175
 *   DWC_ScReportAddIntValue 0x021DF3E8 arm ov175
 *   DWC_ScReportAddByteValue  0x021DF3E8  arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_DATA_GetPlayerStatusById 0x02012950 thumb
 *   g_021E2EF8  0x021E2EF8  data
 *   d_021E2DF4     0x021E2DF4  data
 *   d_021E2DEC     0x021E2DEC  data
 *   d_021E2DF0     0x021E2DF0  data
 *   DWC_GdbInitialize         0x021E10CC  arm
 *   DWC_GdbGetMyRecordsAsync  0x021E1618  arm
 *   DWC_GdbGetRecordsAsync    0x021E16F0  arm
 *   DWC_GdbProcess            0x021E1414  arm
 *   DWC_GdbGetState           0x021E1434  arm
 *   DWC_GdbGetAsyncResult     0x021E1454  arm
 *   DWC_GdbCancelRequest      0x021E11F0  arm
 *   d_021E2F1C                0x021E2F1C  data
 *   DWC_GdbShutdown  0x021E1340  arm
 *   d_021E2F2C 0x021E2F2C data a4
 *   d_021E2F38 0x021E2F38 data a4
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 *   GF_STANDARD_CompareString  0x0203F028  arm
 *   d_021E2F70     0x021E2F70  data
 *   d_021E2F7C 0x021E2F7C data a4
 *   d_021E2F8C 0x021E2F8C data a4
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E2DF8 0x021E2DF8 data a4
 *   DWC_GdbInitialize 0x021E10CC arm ov175
 *   DWC_GdbUpdateRecordAsync 0x021E1540 arm ov175
 *   DWC_GdbProcess 0x021E1414 arm ov175
 *   DWC_GdbGetState 0x021E1434 arm ov175
 *   DWC_GdbGetAsyncResult 0x021E1454 arm ov175
 *   DWC_GdbCancelRequest 0x021E11F0 arm ov175
 *   DWC_GdbCreateRecordAsync 0x021E1464 arm ov175
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   func_0208D7E0 0x0208D7E0 arm
 *   d_021E2FA4 0x021E2FA4 data a1
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   DWC_NdSetAttr 0x021C5C04 arm ov114
 *   DWC_NdGetFileListAsync 0x021C5C38 arm ov114
 *   DWC_NdGetFileAsync 0x021C5CFC arm ov114
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 *   DWC_NdProcess 0x021C5AB8 arm ov114
 *   DWC_NdGetProgress 0x021C5E14 arm ov114
 *   d_021E4B80 0x021E4B80 data a4
 *   d_021E2FA8 0x021E2FA8 data a4
 *   d_021E2FB0 0x021E2FB0 data a4
 *   d_021E2FC4 0x021E2FC4 data a4
 *   NHTTP_RAP_DeleteConnection   0x021B9774  thumb  ov114
 *   NHTTP_RAP_Destroy   0x021B9838  thumb  ov114
 *   DWC_NdCancelAsync 0x021C5DB4 arm ov114
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   func_02008510              0x02008510  thumb
 *   STRBUF_GetChars              0x02045A90  arm
 *   STRBUF_GetLength              0x020458F8  arm
 *   DWC_CheckProfanityExAsync  0x0217BC44  arm  ov009
 *   DWC_CheckProfanityProcess  0x0217BC90  arm  ov009
 *   func_020084E4  0x020084E4  thumb
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_RecordList_GetCount 0x021B99F0 thumb ov114
 *   NHTTP_RAP_RecordList_GetValue 0x021B99F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetRecord 0x021B9A14 thumb ov114
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   d_021E3270  0x021E3270  data
 *   d_021E3250  0x021E3250  data
 *   g_021E32C4   0x021E32C4  data
 *   g_021E32C8   0x021E32C8  data
 *   g_021E32E0   0x021E32E0  data
 *   g_021E32FC   0x021E32FC  data
 *   g_021E3318   0x021E3318  data
 *   g_021E3338   0x021E3338  data
 *   g_021E3354   0x021E3354  data
 *   g_021E3370   0x021E3370  data
 *   g_021E3390   0x021E3390  data
 *   g_021E33B0   0x021E33B0  data
 *   g_021E33D0   0x021E33D0  data
 *   g_021E33E8   0x021E33E8  data
 *   g_021E3400   0x021E3400  data
 *   g_021E3418   0x021E3418  data
 *   g_021E3430   0x021E3430  data
 *   g_021E3448   0x021E3448  data
 *   g_021E3460   0x021E3460  data
 *   g_021E347C   0x021E347C  data
 *   g_021E348C   0x021E348C  data
 *   g_021E34A4   0x021E34A4  data
 *   g_021E34C0   0x021E34C0  data
 *   g_021E34D4   0x021E34D4  data
 *   g_021E34F0   0x021E34F0  data
 *   g_021E3508   0x021E3508  data
 *   g_021E3520   0x021E3520  data
 *   g_021E3538   0x021E3538  data
 *   g_021E3550   0x021E3550  data
 *   g_021E356C   0x021E356C  data
 *   g_021E3584   0x021E3584  data
 *   g_021E359C   0x021E359C  data
 *   g_021E35B4   0x021E35B4  data
 *   g_021E35CC   0x021E35CC  data
 *   g_021E35E4   0x021E35E4  data
 *   g_021E3600   0x021E3600  data
 *   g_021E3618   0x021E3618  data
 */
#include "../../matched/include/Obj08273.h"
#include "../../matched/include/Obj02885.h"
#include "../../matched/include/Obj08274.h"
#include "../../matched/include/Obj24225.h"
#include "../../matched/include/Obj10679.h"
#include "../../matched/include/Obj03317.h"
#include "../../matched/include/Obj24227.h"
#include "../../matched/include/Obj10680.h"
#include "../../matched/include/Obj24228.h"
#include "../../matched/include/Obj24229.h"
#include "../../matched/include/Obj14327.h"
#include "../../matched/include/Obj00171.h"
#include "../../matched/include/Obj24230.h"
#include "../../matched/include/Obj01562.h"
#include "../../matched/include/Obj24232.h"
#include "../../matched/include/Obj01563.h"
#include "../../matched/include/Obj14328.h"
#include "../../matched/include/Obj00013.h"
#include "../../matched/include/Obj00013.h"
#include "../../matched/include/Obj24233.h"
#include "../../matched/include/Obj24253.h"
#include "../../matched/include/Obj24254.h"
#include "../../matched/include/Obj24255.h"
#include "../../matched/include/Obj24256.h"
#include "../../matched/include/Obj24260.h"
#include "../../matched/include/Obj00477.h"
#include "../../matched/include/Obj02512.h"
#include "../../matched/include/Obj24270.h"
#include "../../matched/include/Obj24273.h"
#include "../../matched/include/Obj24274.h"
#include "../../matched/include/Obj24276.h"
#include "../../matched/include/Obj02886.h"
#include "../../matched/include/Obj10683.h"
#include "../../matched/include/Obj24281.h"
#include "../../matched/include/Obj08276.h"
#include "../../matched/include/Obj24283.h"
#include "../../matched/include/Obj00728.h"
#include "../../matched/include/Obj08277.h"
#include "../../matched/include/Obj00781.h"
#include "../../matched/include/Obj08278.h"
#include "../../matched/include/Obj24288.h"
#include "../../matched/include/Obj24292.h"
#include "../../matched/include/Obj24293.h"
#include "../../matched/include/Obj03868.h"
#include "../../matched/include/Obj24294.h"
#include "../../matched/include/Obj24302.h"
#include "../../matched/include/Obj24303.h"
#include "../../matched/include/Obj14329.h"
#include "../../matched/include/Obj24304.h"
#include "../../matched/include/Obj24305.h"
#include "../../matched/include/Obj14330.h"
#include "../../matched/include/Obj24307.h"
#include "../../matched/include/Obj24308.h"
#include "../../matched/include/Obj24309.h"
#include "../../matched/include/Obj24310.h"
#include "../../matched/include/Obj24311.h"
#include "../../matched/include/Obj01067.h"
#include "../../matched/include/Obj00594.h"
#include "../../matched/include/Obj24319.h"
#include "../../matched/include/Obj24320.h"
#include "../../matched/include/Obj24321.h"
#include "../../matched/include/Obj24322.h"
#include "../../matched/include/Obj24323.h"
#include "../../matched/include/Obj24324.h"
#include "../../matched/include/Obj24325.h"
#include "../../matched/include/Obj24326.h"
#include "../../matched/include/Obj14331.h"
#include "../../matched/include/Obj24327.h"
#include "../../matched/include/Obj08279.h"
#include "../../matched/include/Obj14332.h"
#include "../../matched/include/Obj00629.h"
#include "../../matched/include/Obj05458.h"
#include "../../matched/include/Obj00839.h"
#include "../../matched/include/Obj24329.h"
#include "../../matched/include/Obj02513.h"
#include "../../matched/include/Obj14333.h"
#include "../../matched/include/Obj08280.h"
#include "../../matched/include/Obj01069.h"
#include "../../matched/include/Obj24330.h"
#include "../../matched/include/Obj14335.h"
#include "../../matched/include/Obj10685.h"
#include "../../matched/include/Obj14336.h"
#include "../../matched/include/Obj03320.h"
#include "../../matched/include/Obj24331.h"
#include "../../matched/include/Obj02887.h"
#include "../../matched/include/Obj14337.h"
#include "../../matched/include/Obj24332.h"
#include "../../matched/include/Obj14338.h"
#include "../../matched/include/Obj14339.h"
#include "../../matched/include/Obj24337.h"
#include "../../matched/include/Obj24338.h"
#include "../../matched/include/Obj24339.h"
#include "../../matched/include/Obj14340.h"
#include "../../matched/include/Obj01170.h"
#include "../../matched/include/Obj00840.h"
#include "../../matched/include/Obj01171.h"
#include "../../matched/include/Obj24341.h"
#include "../../matched/include/Obj24342.h"
#include "../../matched/include/Obj24343.h"
#include "../../matched/include/Obj24344.h"
#include "../../matched/include/Obj24345.h"
#include "../../matched/include/Obj24346.h"
#include "../../matched/include/Obj24347.h"
#include "../../matched/include/Obj24348.h"
#include "../../matched/include/Obj24349.h"
#include "../../matched/include/Obj24350.h"
#include "../../matched/include/Obj24351.h"
#include "../../matched/include/Obj24352.h"
#include "../../matched/include/Obj24353.h"
#include "../../matched/include/Obj24354.h"
#include "../../matched/include/Obj06574.h"
#include "../../matched/include/Obj00922.h"
#include "../../matched/include/Obj05461.h"
#include "../../matched/include/Obj14343.h"
#include "../../matched/include/Obj00312.h"
#include "../../matched/include/Obj24359.h"
#include "../../matched/include/Obj24360.h"
#include "../../matched/include/Obj24361.h"
#include "../../matched/include/Obj24362.h"
#include "../../matched/include/Obj24363.h"
#include "../../matched/include/Obj24364.h"
#include "../../matched/include/Obj24365.h"
#include "../../matched/include/Obj24366.h"
#include "../../matched/include/Obj24367.h"
#include "../../matched/include/Obj24368.h"
#include "../../matched/include/Obj24369.h"
#include "../../matched/include/Obj24370.h"
#include "../../matched/include/Obj24371.h"
#include "../../matched/include/Obj24372.h"
#include "../../matched/include/Obj24373.h"
#include "../../matched/include/Obj24374.h"
#include "../../matched/include/Obj24375.h"
#include "../../matched/include/Obj24376.h"
#include "../../matched/include/Obj24377.h"
#include "../../matched/include/Obj24378.h"
#include "../../matched/include/Obj24379.h"
#include "../../matched/include/Obj24380.h"
#include "../../matched/include/Obj24381.h"
#include "../../matched/include/Obj24382.h"
#include "../../matched/include/Obj24383.h"
#include "../../matched/include/Obj24384.h"
#include "../../matched/include/Obj24385.h"
#include "../../matched/include/Obj24386.h"
#include "../../matched/include/Obj24387.h"
#include "../../matched/include/Obj24388.h"
#include "../../matched/include/Obj00999.h"
#include "../../matched/include/Obj24391.h"
#include "../../matched/include/Obj14344.h"
#include "../../matched/include/Obj14345.h"
#include "../../matched/include/Obj14346.h"
#include "../../matched/include/Obj10689.h"
#include "../../matched/include/Obj14347.h"
#include "../../matched/include/Obj00841.h"
#include "../../matched/include/Obj10690.h"
#include "../../matched/include/Obj10691.h"
#include "../../matched/include/Obj10692.h"
#include "../../matched/include/Obj06575.h"
#include "../../matched/include/Obj06576.h"
#include "../../matched/include/Obj10693.h"
#include "../../matched/include/Obj01956.h"
#include "../../matched/include/Obj14349.h"
#include "../../matched/include/Obj14350.h"
#include "../../matched/include/Obj14351.h"
#include "../../matched/include/Obj14352.h"
#include "../../matched/include/Obj14353.h"
#include "../../matched/include/Obj14354.h"
#include "../../matched/include/Obj24396.h"
#include "../../matched/include/Obj24397.h"

#define P(k) (*(int *)(p + (k)))
#define Q(k) (*(int *)(q + (k)))
#define REC ((u32_021D62A4 *)CTX[2])
#define H ((char *)W(0x34))
struct Obj0203159C;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct S020315D4;
struct Big;
struct Sub02009448Obj;
struct Sub02009210Obj;
struct U16Vec;
struct MsgRec;
struct T;
struct L0200ED54;
struct Sub0200852CObj;
struct Record;
struct Work;
struct BigObj;
struct Rec0200E6FC;
struct Party;
struct Rec160;
struct Obj;
struct Rec1E;
struct RecBig;
struct Reg2;
struct Obj_021D76D4;
struct Entry;
struct Link;
struct Rec44;
struct Sub24;
struct Field_021DADAC;
typedef int (*Callback)(int,int,int *,int);

typedef struct { Callback create,other,close; } Table;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021D4B3C;

typedef unsigned int u32_021D51BC;

typedef struct { u32_021D51BC w[20]; } Rec80_021D4240;

typedef struct { Rec80_021D4240 data; u32_021D51BC last; } Rec84_021D4240;

typedef unsigned int   u32_021D56D4;

typedef unsigned int u32_021D57BC;

typedef unsigned int u32_021D5908;

typedef unsigned int ul;

typedef unsigned int u32_021D61F0;

typedef unsigned int u32_021D62A4;

typedef struct { u32_021D62A4 kind; u16 count,pad; u32_021D62A4 name,total; u16 a,b; } Desc_021D4240;

typedef unsigned int u32_021D639C;

typedef unsigned int u32_021D63B0;

typedef unsigned int u32_021D63DC;

typedef unsigned int u32_021D63F8;

typedef unsigned int u32_021D644C;

typedef unsigned int u32_021D646C;

typedef unsigned int u32_021D6524;

typedef unsigned int u32_021D6550;

typedef unsigned int u32_021D65C8;

typedef unsigned int u32_021D65DC;

typedef unsigned int u32_021D65F0;

typedef unsigned int u32_021D6698;

typedef unsigned int u32_021D6724;

typedef unsigned int u32_021D6788;

typedef unsigned int u32_021D679C;

typedef unsigned int u32_021D67BC;

typedef unsigned int u32_021D6854;

typedef unsigned int u32_021D6954;

typedef unsigned int u32_021D6964;

typedef struct { unsigned char a,b,c,d;u32 id;} Request;

typedef struct {char pad[0x104];u32 *ctx;u32 aux;} ObjectView;

typedef unsigned int u32_021D76D4;

typedef struct { unsigned char a,b,c,d; u32_021D76D4 id; } Request_021D76D4;

typedef struct {char pad[0x48];u32_021D76D4 slots[6];} SlotView;

typedef unsigned int u32_021D7BE4;

typedef unsigned int u32_021D7E18;

struct Sub {
    u32_021D7E18 f00;
    u32_021D7E18 f04;
    u32_021D7E18 f08;
    u32_021D7E18 f0c;
    u32_021D7E18 f10;
    u32_021D7E18 f14;
};

struct W {
    u32_021D7E18 f00;
    u32_021D7E18 f04;
    u32_021D7E18 *f08;
    u32_021D7E18 f0c;
    u32_021D7E18 f10;
    u8 *f14;
    u8 *f18;
    u32_021D7E18 f1c;
    u32_021D7E18 *f20;
    u32_021D7E18 f24;
    u32_021D7E18 *f28;
    u32_021D7E18 f2c;
    u32_021D7E18 f30;
    struct Sub *f34;
    u32_021D7E18 f38;
    u32_021D7E18 f3c;
    u32_021D7E18 *f40;
};

struct Obj_021D76D4 {
    u8 pad00[0x14];
    u32_021D7E18 f14;
    u8 pad18[0x10];
    u32_021D7E18 f28;
    u32_021D7E18 f2c;
    u32_021D7E18 pad30;
    void *f34;
    u8 pad38[0xa8];
    u32_021D7E18 fe0;
    u32_021D7E18 fe4;
    u32_021D7E18 fe8;
    u32_021D7E18 fec;
    u32_021D7E18 ff0;
    u32_021D7E18 ff4;
    u32_021D7E18 ff8;
    u32_021D7E18 ffc;
    u32_021D7E18 f100;
    struct W *f104;
    u32_021D7E18 f108;
};

struct Buf16 {
    u32_021D7E18 a;
    u32_021D7E18 b;
    u32_021D7E18 c;
    u32_021D7E18 d;
};

typedef unsigned int u32_021D8904;

typedef struct { u32_021D8904 w[20]; } Rec80_021D76D4;

typedef struct { Rec80_021D76D4 data; u32_021D8904 last; } Rec84_021D76D4;

typedef unsigned int u32_021D8BC4;

typedef unsigned int u32_021D8CF0;

typedef unsigned int u32_021D8E30;

typedef unsigned int u32_021D8EC8;

typedef unsigned int u32_021D8FA8;

typedef unsigned int u32_021D9064;

typedef unsigned int u32_021D9090;

typedef long long s64;

struct RTCDate { u32_021D9090 year,month,day,week; };

struct RTCTime { u32_021D9090 hour,minute,second; };

struct Request_021D8EC8 { u8 a,b,c,d; u32_021D9090 id; };

typedef unsigned int u32_021D9344;

typedef struct { u8 a,b,c,d; u32_021D9344 id; } Request_021D8EC8;

typedef unsigned int u32_021D95B0;

typedef unsigned int u32_021D965C;

struct Save_021D76D4 {
    u32_021D965C f00;
    u32_021D965C f04;
    u32_021D965C *f08;
    u32_021D965C f0c;
    u32_021D965C f10;
};

struct Obj_021D8EC8 {
    u32_021D965C f00;
    u32_021D965C f04;
    u32_021D965C f08;
    u32_021D965C f0c;
    u32_021D965C f10;
    u32_021D965C f14;
    u32_021D965C f18;
    u32_021D965C f1c;
    u8 pad20[0xe4];
    struct Save_021D76D4 *f104;
    u32_021D965C f108;
};

struct Profile {
    u8 name[0x94];
    u32_021D965C f94;
    u32_021D965C f98;
    u32_021D965C f9c;
    u16 fa0;
    u16 fa2;
    u32_021D965C fa4;
    u16 fa8;
    u16 faa;
};

typedef unsigned int u32_021D97A4;

typedef unsigned int u32_021D97B8;

typedef unsigned int u32_021D97C4;

typedef unsigned int u32_021D97D0;

typedef unsigned int u32_021D97E4;

typedef unsigned int u32_021D9804;

typedef unsigned int u32_021D9854;

typedef unsigned int u32_021D9868;

typedef unsigned int u32_021D98B8;

typedef struct Work Work;

typedef unsigned int u32_021D98E4;

typedef struct { u32_021D98E4 x0,x1,x2,x3,x4,x5,x6,x7; u16 a,b,c,d; int enabled; u16 kind,pad; } Desc_021D76D4;

typedef unsigned int u32_021D99F4;

typedef unsigned int u32_021D9A08;

typedef unsigned int u32_021D9A1C;

typedef unsigned int u32_021D9A30;

typedef unsigned int   u32_021D9A50;

typedef unsigned int u32_021D9A9C;

struct Save_021D9A50 {
    u8  pad_00[8];
    u32_021D9A9C *sav;
    u8  pad_0c[0x28];
    u32_021D9A9C *blk;
};

typedef unsigned int u32_021D9B2C;

typedef unsigned int u32_021D9BC4;

typedef unsigned int u32_021D9C34;

typedef unsigned int u32_021D9D40;

typedef unsigned int u32_021D9D50;

typedef unsigned int u32_021D9DC8;

typedef unsigned int u32_021D9EA0;

typedef unsigned int u32_021D9ED4;

typedef unsigned int u32_021D9EEC;

typedef unsigned int u32_021D9F04;

typedef enum { RES_NONE, RES_1, RES_2, RES_3, RES_4 } Res;

typedef unsigned int u32_021DA044;

typedef unsigned int u32_021DA0D4;

typedef int (*EvalFn)(int index, void *param);

typedef unsigned int u32_021DA1E4;

typedef unsigned int   u32_021DA36C;

typedef unsigned int u32_021DA384;

typedef unsigned int u32_021DA390;

typedef unsigned int u32_021DA434;

typedef unsigned int u32_021DA45C;

struct MatchKey {
    int  value;
    u8   id;
    u8   pad_05;
    char name[3];
    u8   term;
    u8   pad_0a[2];
};

typedef int (*ReportFn)(u32_021D9A50 *ctx);

typedef struct Sys {
    u32_021D9A50 f0;
    u32_021D9A50 f4;
    u32_021D9A50 f8;
    u32_021D9A50 fc;
} Sys;

typedef unsigned int u32_021DADAC;

typedef unsigned int u32_021DADCC;

typedef unsigned int u32_021DAE18;

typedef unsigned int u32_021DAE54;

typedef int (*RoundFn)(char *ctx, char *peer, int dir, int flag);

typedef unsigned int u32_021DAFB8;

typedef unsigned int u32_021DB218;

typedef signed char s8;

typedef unsigned int u32_021DB228;

typedef unsigned int u32_021DB238;

typedef unsigned int u32_021DB248;

typedef unsigned int u32_021DB258;

typedef unsigned int   u32_021DB294;

typedef unsigned int u32_021DB2D4;

typedef unsigned int u32_021DB300;

typedef unsigned int u32_021DB328;

typedef unsigned int u32_021DB350;

typedef unsigned int u32_021DB378;

typedef unsigned int u32_021DB3A4;

typedef void (*StepFn)(void);

typedef unsigned int u32_021DB478;

typedef unsigned int   u32_021DB6A8;

typedef unsigned int u32_021DB72C;

struct Field_021DADAC {
    const char *name;
    u32_021DB72C type;
    u32_021DB72C value;
    u32_021DB72C pad;
};

typedef void (*RecordsFn)(int count, struct Field_021DADAC **recs, u32_021DB72C a, int nfields);

struct Field_021DB7C0 { const char *name; u32_021DADAC type; u32_021DADAC value; u32_021DADAC pad; };

struct Blob { const void *data; u32_021DADAC size; };

union Payload { u32_021DADAC value; struct Blob blob; };

struct Field_021DBA00 { const char *name;u32_021DADAC type;union Payload payload; };

struct Field_021DBB54 {const char *name;unsigned int type;void *value;unsigned int size;};

struct Field {const char *name;unsigned int type;void *value;unsigned int size;};

typedef unsigned int u32_021DBC04;

struct Record {u32_021DBC04 words[21];};

typedef unsigned int u32_021DBDAC;

typedef struct DWCstAccUserData DWCstAccUserData;

typedef unsigned int u32_021DBFB4;

typedef unsigned int u32_021DC194;

typedef unsigned int u32_021DC1A0;

typedef unsigned int u32_021DC1E4;

typedef unsigned int   u32_021DC200;

typedef unsigned int u32_021DC240;

typedef unsigned int u32_021DC268;

typedef unsigned int u32_021DC2A0;

typedef unsigned int u32_021DC2C0;

typedef unsigned int u32_021DC2D8;

typedef unsigned int u32_021DC338;

typedef unsigned int u32_021DC5AC;

typedef unsigned int u32_021DC5C8;

typedef unsigned int u32_021DC5F8;

typedef unsigned int u32_021DC610;

typedef unsigned int u32_021DC680;

typedef unsigned int u32_021DC6A4;

typedef unsigned int u32_021DC6D0;

typedef unsigned int u32_021DC6FC;

typedef unsigned int   u32_021DC738;

typedef unsigned int u32_021DC77C;

typedef struct {u32_021DC77C a,b;} Pair;

typedef unsigned int u32_021DC8A0;

typedef struct { char pad[0x1220]; u32_021DC8A0 a,b; } Obj;

typedef unsigned int u32_021DC8B4;

typedef struct { u32_021DC8B4 a, b; } W;

typedef unsigned int u32_021DC908;

typedef unsigned long u32_021DCA28;

typedef unsigned int u32_021DCAEC;

typedef unsigned int   u32_021DCB58;

typedef unsigned int u32_021DCC28;

typedef unsigned int u32_021DCE08;

typedef unsigned int   u32_021DCE24;

typedef unsigned int u32_021DCE40;

typedef unsigned int u32_021DCE48;

typedef unsigned int u32_021DCE50;

typedef unsigned int u32_021DCE58;

typedef unsigned int u32_021DCE60;

typedef unsigned int u32_021DCEE0;

typedef unsigned int u32_021DCFDC;

typedef unsigned int u32_021DCFFC;

typedef unsigned int   u32_021DD008;

typedef unsigned int u32_021DD020;

typedef unsigned int u32_021DD02C;

typedef unsigned int u32_021DD034;

typedef unsigned int u32_021DD038;

typedef unsigned int u32_021DD040;

typedef unsigned int u32_021DD044;

extern int func_02034AC4(s32 handle);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02034A5C(int);
extern void GFL_USE_StopAllSe(void);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern int *func_021E5440(unsigned, int);
extern int func_021E5548(int *);
extern u32 *func_021E567C(int unused, int mode, int heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, unsigned short heap);
extern void *func_021E8568(unsigned, unsigned, unsigned, unsigned, void *, void *, unsigned);
extern int *func_021E8A3C(int, int, int);
extern void **func_021E7D20(void *, void *, unsigned);
extern void func_021E7E0C(void **, int);
extern void func_021E7DF0(int *p);
extern void func_021E8A78(void *p);
extern void func_021E8628(char *p);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021E5868(int);
extern void func_021E54E0(char *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021E8A80(unsigned);
extern int func_021E8A90(int **p);
extern void func_021E5534(u8 *p);
extern void func_021E867C(char *p);
extern void func_021E7E08(int);
extern void func_021E5980(int);
extern int func_021E64C0(unsigned char *,void *);
extern int func_021E7774(void *p, void *mgr);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(u32, u32);
extern int func_021E8844(const int *);
extern void func_021E8AB8(u32);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern struct Sub02009448Obj *func_02009448(void *);
extern u8 func_020092EC(const struct Sub02009210Obj *);
extern int POKE_REGULATION_GetDataSize();
extern void MI_CpuCopy8(const void *src, void *dst, u32_021D7E18 size);
extern u16 STRBUF_GetEosChar(void);
extern void *func_02045EC0(struct MsgBank *, u32_021D4B3C);
extern void STRBUF_ToChars(struct U16Vec *, u16 *, unsigned int);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int BMP_OAM_Check5BEC(unsigned int, unsigned int, unsigned int);
extern unsigned int PMSI_PARAM_IsValid(struct T *, unsigned int);
extern void PMSI_PARAM_InitSentence(void *, unsigned int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021E8AA8(int);
extern void DWC_RAPCOMMON_CreateSubHeap(int, int, int, int);
extern void DWC_RAPCOMMON_SetHeapTag(int);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern void *TRADE_HISTORY_GetFromSave(void *sys);
extern void func_021E8AC0(int, int);
extern void *MISC_SAVEDATA_GetBlock44(void *);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *, u32_021D51BC);
extern u32_021D51BC func_02008530(const struct Sub0200852CObj *obj);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern u32_021D4B3C func_0200FBB0(void);
extern u8 *func_02012944(void *p);
extern u32_021D62A4 BSUBWAY_SAVEDATA_GetStat(u32_021D62A4,u32_021D62A4,u32_021D62A4);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32_021D62A4 func_021E5C20(Desc_021D4240 *,int,u32_021D62A4,int,u32_021D62A4,u32_021D62A4,u32_021D62A4,u32_021D62A4,u32_021D62A4,int);
extern void func_021E5D40(u32_021D639C p);
extern u32_021D63B0 func_021E64C8(u32_021D63B0 p);
extern u32_021D63B0 func_021E65FC(u32_021D63B0 p);
extern u32_021D63F8 func_021E7520(u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8,u32_021D63F8);
extern void func_021E7710(u32_021D644C p);
extern int func_021E777C(void *);
extern void BSUBWAY_SAVEDATA_SetStat(u32_021D646C, u32_021D646C, u32_021D646C, u32_021D646C);
extern void BSUBWAY_SAVEDATA_IncStat(u8 *base, int a, int idx);
extern u32_021D6550 func_021E888C(void *, u32_021D6550);
extern void func_021E89D0(u32_021D65C8 p);
extern int func_021E8A00(u32_021D65DC p);
extern int MYSTATUS_GetSize(void);
extern void *func_0200E6E8(u32_021D6698 a);
extern void MISC_SAVEDATA_CopyQuadRecord(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32_021D6698 GAME_DATA_GetField1A0(const struct BigObj *p);
extern int WIFILIST_GetGsProfileId(void *a0);
extern u32_021D67BC func_020173EC(void);
extern u32_021D67BC POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32_021D67BC idx);
extern u8 *NHTTP_RAP_EvilCheckAllocArray(int a, int b, int c);
extern void NHTTP_RAP_EvilCheckSetElement(int p, int a, u32_021D67BC b, int n);
extern int NHTTP_RAP_VerifySignature(void *a, int b, int c, char *d, u16 e);
extern void NHTTP_RAP_EvilCheckFreeArray(void *);
extern u32_021D6854 KEY_GetTrg(void);
extern u32_021D6854 func_0200FB24(void);
extern int GFL_NET_GetRunState(void);
extern void DWC_CloseAllConnectionsHard(void);
extern void *BATTLE_COMPETITION_GetFromSave(void *sys);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32_021D6964 index);
extern struct Party *POKEPARTY_Create(u32_021D6964 heap);
extern u32 func_020307B0(void *p);
extern int func_021E84F8(char *p, void *q);
extern u32 POKEPARTY_GetBattleReadyCount(void *p);
extern int REGULATION_NoOp();
extern int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask);
extern void * BATTLE_BOX_GetFromSave(void *);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *p, u32 index);
extern void *func_0200BAF4(int a0, int a1);
extern void BATTLE_BOX_SetLockFlags(void *p, u32 v);
extern void REGULATION_Card_SetValue(struct Reg2 *p, u32 id, s32 value);
extern void REGULATION_BuildParty(int,int);
extern s32 REGULATION_Card_GetValue(struct Reg2 *p, u32 id);
extern u32 REGULATION_Card_IsCrcValid(struct Reg2 *p);
extern u32 BATTLE_BOX_IsLocked(void *p, u32 mask);
extern void BATTLE_BOX_ClearLockFlags(void *p, int v);
extern void REGULATION_InitParty(struct Rec1E *);
extern void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32_021D7E18 n);
extern int func_02167ED8(void *date, void *time);
extern void func_0200FA84(void);
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);
extern void RTC_ConvertSecondToDateTime(struct RTCDate *,struct RTCTime *,s64);
extern s32 RTC_ConvertDateToDay(struct RTCDate *date);
extern u8 *REGULATION_Card_GetCupName(struct Reg2 *p);
extern char *func_021E5D68(char *info, u32_021D965C a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
extern void POKETRADE_2D_DeleteMarkingIcon(void *p);
extern void func_021E5F24(u32_021D97E4 a, u32_021D97E4 b, u32_021D97E4 c, u32_021D97E4 d, u32_021D97E4 e, u32_021D97E4 f);
extern void *func_021E7E3C(void *, int, int, int, int, int, int);
extern void func_021E82BC(char *p);
extern int func_021E8338(Work *);
extern int func_021E8420(Work *);
extern u32_021D98E4 func_021E88B0(Desc_021D76D4 *, int, unsigned char, int, int, int);
extern void *POKEPARTY_Init(void *);
extern void MYSTATUS_Copy(void *src, void *dst);
extern u16 REGULATION_Card_CalcCrc(struct Reg2 *p);
extern u8 *func_020185F0(u32_021D9BC4 entry);
extern u32_021D9BC4 POKE_TOOL_GetBoxParamSize(void);
extern int func_0203EFC8(const u8 *a, const u8 *b, u32_021D9BC4 n);
extern void *func_02030734(u32_021D9DC8 heapId, u32_021D9DC8 size, int clear, const char *site, u16 tag);
extern u32_021D9DC8 func_02009860(void);
extern u32_021D9DC8 func_0200853C(const struct Sub0200852CObj *obj);
extern void GFL_NET_COMMAND_AddCommandTable(u32_021D9DC8, u32_021D9DC8, u32_021D9DC8, u32_021D9DC8);
extern void GFL_NET_SetWaitMode(int);
extern void DWC_RAP_SetErrorCallback(int, int);
extern void DWC_RAP_SetErrorHookCallback(int, int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32_021D9EA0);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *tick, unsigned int value, unsigned int line);
extern void GFL_NET_SetAutoExit(int a);
extern void GFL_NET_SetLoginOption(int a);
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern void GAME_DATA_SaveCancel(char *p);
extern void func_0200F7C0(u32_021D9F04 value);
extern int DWC_RAPCOMMON_HandleNetError(void *a, void *b);
extern void GFL_NET_STATE_ClearErrorMode(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_SetError(int a, u32_021D9F04 b, u32_021D9F04 c, u32_021D9F04 d);
extern void func_0200FAAC(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int STD_TSPrintf(char *dst, const char *fmt, ...);
extern int DWC_RAP_StartMatchWithFilter(char *filter, int n, void *cb, char *obj);
extern u32_021DA1E4 GFL_NET_STATE_WifiEnterRandomMatch(void);
extern void DWC_RAP_SetVchatEnabled(int v);
extern void GFL_NET_STATE_WifiDisconnect(u32_021DA1E4 a);
extern int GFL_NET_STATE_GetWifiState(void);
extern u32_021DA1E4 GFL_NET_STATE_GetError(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern u32_021DA1E4 GFL_NET_IsParentAid(void);
extern int DWC_RAP_IsStateInSession(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32_021DA434 b, u32_021DA434 c, u32_021DA434 d);
extern u8 DWC_AddMatchKeyInt(u8 keyID, const char *keyString, const int *valueSrc);
extern int DWC_GetMatchIntValue(int index, const char *key, int idefault);
extern int DWC_ScInitialize(int theGameId, int ssl_type);
extern int DWC_ScGetLoginCertificate(void **p);
extern int DWC_ScCreateSessionAsync(u32_021D9A50 a0, u32_021D9A50 a1, u32_021D9A50 a2);
extern void *DWC_ScGetSessionId(void);
extern s32 DWC_ScProcess(void);
extern void *DWC_ScGetConnectionId(void);
extern u32_021D9A50 DWC_ScSetSessionId(u32_021D9A50 a);
extern int DWC_ScSetReportIntentionAsync(u32_021D9A50 a0, u32_021D9A50 a1, u32_021D9A50 a2, u32_021D9A50 a3);
extern int DWC_ScSubmitReportAsync(u32_021D9A50 a0, u32_021D9A50 a1, u32_021D9A50 a2, u32_021D9A50 a3, char *a4);
extern void DWC_ScDestroyReport(u32_021DAE18 report);
extern void DWC_ScShutdown(void);
extern int DWC_ScCreateReport(u32_021DAE54 a0, u32_021DAE54 a1, u32_021DAE54 a2, u32_021DAE54 a3);
extern int DWC_ScReportBeginGlobalData(u32_021DAE54 *a0);
extern int DWC_ScReportBeginPlayerData(u32_021DAE54 *a0);
extern int DWC_ScReportBeginTeamData(u32_021DAE54 *a0);
extern int DWC_ScReportBeginNewPlayer(u8 *a0);
extern s32 DWC_ScReportSetPlayerData(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, char *a5, s32 a6);
extern int DWC_ScReportEnd(u32_021DAE54 h, u32_021DAE54 a, int flag);
extern int func_021DF420(int,int,int);
extern int DWC_ScReportAddIntValue(int,int,int);
extern int DWC_ScReportAddByteValue(u32_021DB218 report, u16 keyId, s8 value);
extern u32_021DB258 GFL_NET_GetHandleNetID(struct Link *p);
extern struct Rec44 *GAME_DATA_GetPlayerStatusById(struct Sub24 *p, u32_021DB294 i);
extern int DWC_GdbInitialize(u32_021DB478 gameId, u32_021DB478 user, int ssl);
extern int DWC_GdbGetMyRecordsAsync(const char *table, void *fields, int nfields, void *cb, void *param);
extern int DWC_GdbGetRecordsAsync(const char *table, int *ids, int nids, void *fields, int nfields, void *cb, void *param);
extern void DWC_GdbProcess(void);
extern int DWC_GdbGetState(void);
extern int DWC_GdbGetAsyncResult(void);
extern int DWC_GdbCancelRequest(void);
extern void DWC_GdbShutdown(void);
extern int GF_STANDARD_CompareString(const char *s1, const char *s2);
extern int DWC_GdbUpdateRecordAsync(char *,int,void *,int);
extern int DWC_GdbCreateRecordAsync(char *,void *,int,int *);
extern u32_021DC1A0 GFL_NET_SendData(u32_021DC1A0 a, u32_021DC1A0 b, u32_021DC1A0 c, u32_021DC1A0 d, u32_021DC1A0 e, u32_021DC1A0 f, u32_021DC1A0 g, u32_021DC1A0 h);
extern int func_0208D7E0(char *,const char *,...);
extern int DWC_NdInitAsync(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int DWC_NdSetAttr(char *,char *,char *);
extern int DWC_NdGetFileListAsync(void *,unsigned int,unsigned int);
extern int DWC_NdGetFileAsync(void *,char *,unsigned int);
extern int DWC_NdCleanupAsync(void);
extern void DWC_NdProcess(void);
extern int DWC_NdGetProgress(u32_021DC338 *,u32_021DC338 *);
extern u32_021DC338 _u32_div_f(u32_021DC338,u32_021DC338);
extern void NHTTP_RAP_DeleteConnection(u8 *p);
extern void NHTTP_RAP_Destroy(u8 *p);
extern int DWC_NdCancelAsync(void);
extern u8 *NHTTP_RAP_Create(int a, int b, int c);
extern int NHTTP_RAP_CreateRequest(int,u8 *);
extern int NHTTP_RAP_StartConnection(u8 *);
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);
extern void GFL_NET_ERR_RaiseFatal(unsigned int x);
extern int NHTTP_RAP_GetConnection(char *);
extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned int length);
extern void *func_02008510(void *a, int tag);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern int DWC_CheckProfanityExAsync(u16 **words, int wordsnum, char *reserved, int timeout,
                                     char *result, int *badwordsnum, int region);
extern int DWC_CheckProfanityProcess(void);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void NHTTP_RAP_AllocPostData(u8 *,int,int,int);
extern void NHTTP_RAP_AppendPostData(u8 *,int,int);
extern int NHTTP_RAP_CreatePostRequest(u8 *);
extern void NHTTP_RAP_FreePostData(u8 *);
extern int NHTTP_RAP_RecordList_GetCount(u8 *p);
extern u32_021DCC28 NHTTP_RAP_RecordList_GetValue(u32_021DCC28 p, u32_021DCC28 i);
extern u8 *NHTTP_RAP_RecordList_GetRecord(u8 *,u32_021DCC28);
extern void GFL_NET_RestartWithDefaultTimeout(u32_021DD008 a, u32_021DD008 b);
int func_021D4240(int a,int b,int *p,int d);
int func_021D429C(int a,int b,int *p,int d);
int func_021D42E0(int a,int b,int *p,int d);
int func_021D4318(void *sys, int *state, u32 *ctx);
int func_021D4448(int sys,int unused,int unused2,int *p);
int func_021D44D4(unsigned sys,int *state,int unused,int *p);
void func_021D458C(unsigned sys,int *state,int *p);
void func_021D4608(u32 sys, int *state, u32 *p);
void func_021D4730(u32 sys, int *state, u32 *p);
void func_021D495C(u32 sys, int *state, u32 *p);
void func_021D4B3C(unsigned sys, int *state, char *p);
void func_021D51BC(unsigned sys, int *state, char *p);
void func_021D54E8(unsigned sys,int *state,int *p);
void func_021D5560(unsigned sys, int *state, int *p);
void func_021D5634(unsigned sys,int *state,int *p);
void func_021D56D4(unsigned sys, int *state, int *p);
void func_021D57BC(unsigned sys, int *state, int *p);
void func_021D5908(unsigned sys, int *state, char *p);
void func_021D5E24(unsigned sys, int *state, char *p);
void func_021D6000(unsigned sys,int *state,int *p);
void func_021D6048(unsigned sys,int *state,int *p);
void func_021D60E0(u32_021D4B3C sys,int *state,u32_021D4B3C *p);
void func_021D61A4(void *obj,int unused,u8 *p);
void func_021D61CC(void *a, u32_021D4B3C **pp, char *p);
void func_021D61F0(u32_021D61F0 sys,int *state,char *p);
void func_021D62A4(u32_021D62A4 *p, u32_021D62A4 mode);
void func_021D639C(char *obj);
u32_021D63B0 func_021D63B0(char *obj);
u32_021D63B0 func_021D63BC(char *obj);
void func_021D63C8(char *obj, u32_021D63B0 arg);
void func_021D63DC(char *obj);
void func_021D63F8(u32_021D63F8 *p,u32_021D63F8 arg);
void func_021D644C(char *obj);
int func_021D6460(char *p);
int func_021D646C(u32_021D646C save, u32_021D646C kind, u32_021D646C obj);
void func_021D6524(int a, int b, u32_021D6524 c);
void func_021D6550(u32_021D6550 *p,int mode);
void func_021D65C8(char *obj);
int func_021D65DC(char *obj);
void func_021D65F0(u32_021D65F0 *p,u32_021D65F0 *q);
void func_021D6698(u32_021D6698 *p,u32_021D6698 *q);
void func_021D6724(u32_021D6724 *p, u32_021D6724 *q);
void func_021D6788(char *obj, void *fn);
u32_021D679C func_021D679C(char *obj);
int func_021D67BC(char *p, u16 heapId);
int func_021D6854(char *obj, int trigger, int go);
void func_021D6954(char *obj);
int func_021D6964(void *sys,int unused,u32_021D6964 *ctx);
int func_021D6A98(u32 sys,u32 unused,u32 arg,char *p);
int func_021D6B38(unsigned sys,int *state,int unused,int *p);
void func_021D6BF4(u32 sys,void *unused,char *p);
void func_021D6C54(u32 sys,int *state,u32 *p);
void func_021D6DB8(int *sys,int *state,char *p);
void func_021D76D4(u32_021D76D4 sys,int *state,char *p);
void func_021D7BE4(u32_021D7BE4 sys,int *state,char *p);
void func_021D7E18(u32_021D7E18 sys, int *state, struct Obj_021D76D4 *obj);
void func_021D8904(u32_021D8904 sys,int *state,char *p);
void func_021D8BC4(int *a, int *state, char *ctx);
void func_021D8CF0(u32_021D8CF0 sys,int *state,char *p);
void func_021D8E30(u32_021D8E30 sys, int *state, char *ctx);
void func_021D8EC8(u32_021D8EC8 sys,int *state,char *p);
void func_021D8FA8(u32_021D8FA8 sys, int *state, char *ctx);
void func_021D905C(u32_021D8FA8 sys);
void func_021D9064(void *obj,int unused,u8 *p);
void func_021D9090(u32_021D9090 sys,int *state,char *p);
void func_021D9344(u32_021D9344 sys,int *state,char *p);
void func_021D95B0(u32_021D95B0 sys, int *state, char *ctx);
void func_021D965C(struct Obj_021D8EC8 *obj);
void func_021D97A4(char *obj);
u32_021D97B8 func_021D97B8(char *obj);
int func_021D97C4(char *obj);
void func_021D97D0(char *obj);
void func_021D97E4(char *obj, u32_021D97E4 arg);
void func_021D9804(u32_021D9804 *obj, u32_021D9804 arg);
void func_021D9854(char *obj);
u32_021D9868 func_021D9868(char *obj);
void func_021D9874(char *ctx);
void func_021D98B8(char *obj);
int func_021D98CC(char *p);
int func_021D98D8(char *p);
void func_021D98E4(u32_021D98E4 *p, int mode);
void func_021D99F4(char *obj);
int func_021D9A08(char *obj);
void func_021D9A1C(char *obj, void *fn);
u32_021D9A30 func_021D9A30(char *obj);
void func_021D9A50(char *dest, char *ctx);
void func_021D9A9C(char *dst, char *obj);
void func_021D9B18(char *save, char *response);
u32_021D9B2C func_021D9B2C(char *obj, void *list, u32_021D9B2C heapId);
int func_021D9BC4(u32_021D9BC4 a, u32_021D9BC4 b);
int func_021D9C34(char *obj, int trigger, int go);
void func_021D9D40(char *obj);
int func_021D9D50(char *obj, u32_021D9D50 *rec);
char *func_021D9DC8(u32_021D9DC8 a, void *save, u32_021D9DC8 b, u16 heap);
void func_021D9EA0(u8 *p);
void func_021D9ED0(int a0);
void func_021D9ED4(char *obj, u32_021D9ED4 v);
int func_021D9EEC(char *obj);
int func_021D9F04(char *ctx, void *a, void *b);
void func_021DA044(u8 *p);
int func_021DA054(char *ctx);
void func_021DA0D4(char *obj, int mode, int extra, int group, int *rec);
int func_021DA1E4(char *obj);
void func_021DA36C();
void func_021DA384(char *obj);
int func_021DA390(char *obj);
int func_021DA434();
u32_021DA45C func_021DA45C(char *obj);
void func_021DA470(unsigned char *dest);
void func_021DA4B8(char *obj, int i, int value);
int func_021DA4E8(int index, void *param);
int func_021DA4F0(int index, void *param);
int func_021DA4F8(int index, void *param);
void func_021DA5B0(char *obj, int mode, int kind, u32_021D9A50 a3, u32_021D9A50 *rec, u32_021D9A50 slot);
int func_021DA6B8(char *p, u32_021D9A50 *out);
u32_021DADAC func_021DADAC(u8 *p);
void func_021DADB4(int result, char *obj);
void func_021DADCC(int result, char *obj);
void func_021DAE00(int result, char *obj);
void func_021DAE18(char *obj);
int func_021DAE54(char *ctx, char *other, char *peer, u32_021DAE54 a3, RoundFn cb, int flag, int have, int twoway);
void func_021DAFB8(int *ctx,const u32_021DAFB8 *record,int invert);
void func_021DB160(int *ctx, int *input, int invert);
int func_021DB218(u32_021DB218 *ctx);
int func_021DB228(u32_021DB228 *ctx);
int func_021DB238(u32_021DB238 *ctx);
int func_021DB248(u32_021DB248 *ctx);
void func_021DB258(int index,int unused,const void *src,u8 *p,int owner);
void func_021DB294(int index, int unused, void *dest, char *ctx, int owner);
int func_021DB2D4(int a, char *b);
void func_021DB300(u32_021DB300 a, u32_021DB300 b, u32_021DB300 c, char *d, u32_021DB300 e);
void func_021DB328(u32_021DB328 a, u32_021DB328 b, u32_021DB328 c, char *d, u32_021DB328 e);
void func_021DB350(u32_021DB350 a, u32_021DB350 b, u32_021DB350 c, char *d, u32_021DB350 e);
void func_021DB378(u32_021DB378 a, u32_021DB378 b, u32_021DB378 *c, char *d, u32_021DB378 e);
void func_021DB3A4(char *obj, u32_021DB3A4 target, int kind, u32_021DB3A4 arg);
int func_021DB478(char *obj);
void func_021DB6A0(char *obj);
void func_021DB6A8(char *ctx);
void func_021DB72C(int count, struct Field_021DADAC **recs, char *obj);
void func_021DB7C0(int count,struct Field_021DB7C0 **fields,char *p,int n);
void func_021DBA00(int count,struct Field_021DBA00 **fields,u8 *p,int n);
void func_021DBB00(int count, char **rows, int *out, int width);
void func_021DBB54(int count,struct Field_021DBB54 **recs,void *dst,int nfields);
void func_021DBBAC(int count,struct Field **recs,void *dst,int nfields);
void func_021DBC04(u8 *p,u32_021DBC04 mode,struct Record *src);
int func_021DBDAC(char *p);
void func_021DBFA4(char *ctx);
int func_021DBFB4(char *p);
u32_021DC194 func_021DC194(char *obj);
u32_021DC1A0 func_021DC1A0(char *obj, u32_021DC1A0 data);
u32_021DC1E4 func_021DC1E4(char *obj, char **out);
u32_021DC200 func_021DC200(char *p,unsigned int data);
u32_021DC240 func_021DC240(char *obj, u32_021DC240 arg);
int func_021DC268(char *obj, u32_021DC268 data);
u32_021DC2A0 func_021DC2A0(char *obj, u32_021DC2A0 arg);
int func_021DC2C0(u32_021DC2C0 ignored, void *p);
u32_021DC2D8 func_021DC2D8(char *obj, u32_021DC2D8 *out);
void func_021DC2F4(char *p,unsigned a);
int func_021DC338(u8 *p);
int func_021DC5AC(const u32_021DC5AC *p,u32_021DC5AC bytes);
void func_021DC5C8(void *p, int unused, int kind);
u32_021DC5F8 func_021DC5F8(char *p, int a, int kind);
int func_021DC610(unsigned int a);
void func_021DC66C(const char *p,void *out);
void func_021DC680(u8 *p,int state);
void func_021DC6A4(u8 *p,int state);
void func_021DC6D0(u8 *p,int state);
void func_021DC6FC(void *p,u32_021DC6FC kind);
void func_021DC738(char *p,unsigned heap);
int func_021DC77C(u8 *p);
void func_021DC8A0(const Obj *p,Pair *out);
void func_021DC8B4(u8 *p, const W *src, int x);
int func_021DC908(char *p);
void func_021DCA28(char *obj, u32_021DCA28 win, u16 tag);
int func_021DCAEC(char *obj, int *out);
void func_021DCB58(char *p,void *q,int mode);
int func_021DCC28(char *p,u8 *out);
void func_021DCE08(char *ctx, u32_021DCE08 v, int line);
void func_021DCE24(char *p, int v, int a2);
void func_021DCE40(char *ctx, u32_021DCE40 v, int line);
void func_021DCE48(char *ctx, u32_021DCE48 v, int line);
void func_021DCE50(char *ctx, u32_021DCE50 v, int line);
void func_021DCE58(char *ctx, u32_021DCE58 v, u32_021DCE58 a2);
u32_021DCE60 func_021DCE60(int a);
u32_021DCEE0 func_021DCEE0(int a, int b, int c);
u32_021DCFDC func_021DCFDC(u32_021DCFDC v);
void func_021DCFFC(void *p);
void func_021DD008(char *p, int flag);
u32_021DD020 func_021DD020(char *obj);
char *func_021DD02C(void);
u32_021DD034 func_021DD034(void);
char *func_021DD038(void);
u32_021DD040 func_021DD040(void);
int func_021DD044(int a);
extern const Table d_021E2C74,d_021E2C80;
extern const char d_021E2DE0[];
extern const char ov177_id[];
extern const char ov067_id[], ov114_id[];
extern const char ov114_id[],ov067_id[];
extern const char d_021E2EE0[], d_021E2EF8[];
extern const u32_021D9DC8 d_021E2C90[];
extern const char d_021E2EFC[];
extern u32_021DA434 g_021E2C8C[];
extern const char *const d_021E2E10[];
extern u32_021DB2D4 g_021E2EF8[];
extern char d_021E2DF4[];
extern char d_021E2DEC[];
extern char d_021E2DF0[];
extern const char d_021E2F1C[];
extern char d_021E2F2C[], d_021E2F4C[], d_021E2F60[];
extern const char d_021E2F38[];
extern const char d_021E2F70[];
extern const char d_021E2F7C[],d_021E2F8C[];
extern const char d_021E2F7C[];
extern const u32_021DBC04 d_021E2DF8[];
extern const char d_021E2FA4[];
extern u8 d_021E4B80[];
extern char d_021E2FA8[],d_021E2FB0[],d_021E2FC4[];
extern char d_021E3270[];
extern char d_021E3250[];
extern u32_021DD044 g_021E32C4[];
extern u32_021DD044 g_021E32C8[];
extern u32_021DD044 g_021E32E0[];
extern u32_021DD044 g_021E32FC[];
extern u32_021DD044 g_021E3318[];
extern u32_021DD044 g_021E3338[];
extern u32_021DD044 g_021E3354[];
extern u32_021DD044 g_021E3370[];
extern u32_021DD044 g_021E3390[];
extern u32_021DD044 g_021E33B0[];
extern u32_021DD044 g_021E33D0[];
extern u32_021DD044 g_021E33E8[];
extern u32_021DD044 g_021E3400[];
extern u32_021DD044 g_021E3418[];
extern u32_021DD044 g_021E3430[];
extern u32_021DD044 g_021E3448[];
extern u32_021DD044 g_021E3460[];
extern u32_021DD044 g_021E347C[];
extern u32_021DD044 g_021E348C[];
extern u32_021DD044 g_021E34A4[];
extern u32_021DD044 g_021E34C0[];
extern u32_021DD044 g_021E34D4[];
extern u32_021DD044 g_021E34F0[];
extern u32_021DD044 g_021E3508[];
extern u32_021DD044 g_021E3520[];
extern u32_021DD044 g_021E3538[];
extern u32_021DD044 g_021E3550[];
extern u32_021DD044 g_021E356C[];
extern u32_021DD044 g_021E3584[];
extern u32_021DD044 g_021E359C[];
extern u32_021DD044 g_021E35B4[];
extern u32_021DD044 g_021E35CC[];
extern u32_021DD044 g_021E35E4[];
extern u32_021DD044 g_021E3600[];
extern u32_021DD044 g_021E3618[];

#define W(k) (*(u32 *)(p+(k)))





int func_021D4240(int a,int b,int *p,int d)
{
    func_02034AC4((int)ov177_id);
    switch(((int *)p[2])[2]) {
    case 1: return d_021E2C74.create(a,b,p,d);
    case 0: return d_021E2C80.create(a,b,p,d);
    default: func_02034714(d_021E2DE0,0,d_021E2DE0); return 0;
    }
}





int func_021D429C(int a,int b,int *p,int d)
{
    int result;
    switch(((int *)p[2])[2]) {
    case 1: result=d_021E2C74.close(a,b,p,d); break;
    case 0: result=d_021E2C80.close(a,b,p,d); break;
    default: func_02034714(d_021E2DE0,0,d_021E2DE0); break;
    }
    GFL_USE_StopAllSe();
    func_02034A5C((int)ov177_id);
    return result;
}





int func_021D42E0(int a,int b,int *p,int d) {switch(((int *)p[2])[2]) {case 1:return d_021E2C74.other(a,b,p,d);case 0:return d_021E2C80.other(a,b,p,d);default:func_02034714(d_021E2DE0,0,d_021E2DE0);return 0;}}





/*
 * prototype: 0203159C's matched void body leaves allocated r0 live;
 *   caller captures r0 at 021D4348 as its cleared 0x100-byte buffer.
 */
int func_021D4318(void *sys, int *state, u32 *ctx)
{
    u32 *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 87, 0x35000);
    p = PROCSYS_AllocProcWork(sys, 0x100, 87);
    MI_CpuFill8(p, 0, 0x100);
    p[16] = (u32)ctx;
    p[0] = (u32)func_021E5440(1, 87);
    p[1] = (u32)func_021E567C(func_021E5548((int *)p[0]), 2, 87);
    func_021D6698((u32_021D6698 *)((u32 *)ctx[5]), (u32_021D6698 *)p);
    p[2] = (u32)GF_FONT_Create(23, 0, 0, 0, 87);
    p[3] = PRINTSYS_QUE_Create((void *)87);
    p[4] = (u32)func_02045B38(0, 2, 210, 87);
    p[5] = (u32)WORDSET_Create(8, 64, 87);
    p[12] = (u32)func_021D9DC8(((u32 *)p[16])[15], (void *)(((u32 *)ctx[2])[0]), ctx[7], 87);
    p[9] = (u32)func_021E8568(0, 15, 14, 10, (void *)p[3], (void *)p[2], 87);
    p[13] = (u32)func_021E8A3C((int)p, (int)func_021D458C, 87);
    p[14] = (u32)func_021E8A3C((int)p, 0, 87);
    p[8] = (u32)func_021E7D20((void *)func_021E5548((int *)p[0]), (void *)p[1], 87);
    func_021E7E0C((void **)p[8], 0);
    if (ctx[3] != 0) {
        if (ctx[0] == 0) {
            func_021D63C8((char *)p, 0);
        } else if (ctx[0] == 1) {
            if (ctx[3] == 1)
                func_021D6524(ctx[4], ((u32 *)ctx[2])[1], *(u32 *)ctx[11]);
            func_021D63C8((char *)p, 1);
        }
    }
    func_021DD008((char *)p[12], 1);
    return 1;
}





int func_021D4448(int sys,int unused,int unused2,int *p)
{
    func_021DD008((char *)p[12],0);
    func_021E7DF0((int *)p[8]);
    func_021E8A78((void *)p[14]);
    func_021E8A78((void *)p[13]);
    func_021E8628((char *)p[9]);
    if(p[12]) func_021D9EA0((u8 *)p[12]);
    func_021D644C((char *)p);
    func_021D639C((char *)p);
    func_021D65C8((char *)p);
    WORDSET_DeleteStrbufED04((struct WordSet *)p[5]);
    MSGDATA_Delete((void *)p[4]);
    PRINTSYS_QUE_Delete((struct PrintSys *)p[3]);
    GF_FONT_Delete((void *)p[2]);
    func_021E5868(p[1]);
    func_021E54E0((char *)p[0]);
    func_020315D4((struct S020315D4 *)sys);
    func_020306F0(0x57);
    func_02034A5C((int)ov114_id);
    func_02034A5C((int)ov067_id);
    return 1;
}





/*
 * Extent tail 021D458A..021D458C is two zero alignment bytes before 021D458C.
 */
int func_021D44D4(unsigned sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2:
        func_021E8A80(p[13]);
        if(func_021E8A90((int **)p[13])) *state=3;
        if(p[12]) func_021D9ED0(p[12]);
        break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    func_021E5534((u8 *)p[0]);
    PRINTSYS_QUE_Main((struct PrintSys *)p[3]);
    func_021E867C((char *)p[9]);
    func_021E7E08(p[8]);
    func_021E5980(p[1]);
    if(p[6]) func_021E64C0((unsigned char *)p[6],(void *)p[3]);
    if(p[7]) func_021E7774((void *)p[7],(void *)p[3]);
    return 0;
}





void func_021D458C(unsigned sys,int *state,int *p)
{
    int *q=(int *)p[16];
    switch(q[3]) {
    case 0: func_021E8AA0((int *)sys,(int)func_021D4608); break;
    case 2:
        func_021DA36C((void *)p[12]);
    case 1:
        if(q[0]==0) func_021E8AA0((int *)sys,(int)func_021D51BC);
        else if(q[0]==1) func_021E8AA0((int *)sys,(int)func_021D5E24);
        break;
    case 3:
        if(q[0]==0) func_021E8AA0((int *)sys,(int)func_021D54E8);
        else if(q[0]==1) func_021E8AA0((int *)sys,(int)func_021D6000);
        break;
    }
}





void func_021D4608(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0: func_021E7E0C((void **)p[8], 0); *state = 1; break;
    case 1:
        func_021E8738((int *)p[9], p[4], 25, 1);
        *state = 7; func_021E8AB4(sys, 2); break;
    case 2: func_021D6550((u32_021D6550 *)p, 1); *state = 3; break;
    case 3:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: ctx[0] = 1; func_021E8AA0((int *)sys, (int)func_021D57BC); break;
            case 1: ctx[0] = 0; func_021E8AA0((int *)sys, (int)func_021D4730); break;
            case 2: ctx[0] = 3; *state = 4; break;
            }
        }
        break;
    case 4:
        func_021E8738((int *)p[9], p[4], 30, 1);
        *state = 7; func_021E8AB4(sys, 5); break;
    case 5: func_021D6550((u32_021D6550 *)p, 0); *state = 6; break;
    case 6:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: ctx[1] = 0; func_021E8AA0((int *)sys, (int)func_021D61CC); break;
            case 1: *state = 1; break;
            }
        }
        break;
    case 7: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}





void func_021D4730(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    u32 result;
    switch (*state) {
    case 0:
        if (func_020092EC((const struct Sub02009210Obj *)func_02009448(GAME_DATA_GetSaveControl((struct Big *)*(u32 *)ctx[2])))) *state = 1;
        else *state = 6;
        break;
    case 1: func_021E8738((int *)p[9], p[4], 41, 1); *state = 14; func_021E8AB4(sys, 2); break;
    case 2: func_021E8738((int *)p[9], p[4], 24, 2); *state = 14; func_021E8AB4(sys, 3); break;
    case 3: MI_CpuFill8((void *)ctx[12], 0, 8); func_021DC738((char *)p[12], 87); *state = 4; break;
    case 4:
        switch (func_021DC77C((u8 *)p[12])) {
        case 0: break;
        case 1: func_021DC8A0((const Obj *)((char *)p[12]), (Pair *)((void *)((u32 *)p[16])[12])); *state = 5; break;
        case 3: MI_CpuFill8((void *)((u32 *)p[16])[12], 0, 8); func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        case 2:
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
            case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
            }
            break;
        }
        break;
    case 5: if (((u8 *)ctx[12])[6]) *state = 9; else *state = 6; break;
    case 6: func_021E8738((int *)p[9], p[4], 55, 1); *state = 14; func_021E8AB4(sys, 12); break;
    case 9:
        func_021D6788((char *)p, func_021D61F0); *state = 10;
        switch (func_021D9F04((char *)p[12], 0, 0)) {
        case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
        case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 10:
        result = func_021D679C((char *)p);
        if (result == 0) *state = 13;
        else if (result == 1) *state = 11;
        else if (result == 3) func_021E8AA0((int *)sys, (int)func_021D61A4);
        if (result != 0xffff) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1: func_021D63DC((char *)p); func_021E8AA0((int *)sys, (int)func_021D4608); break;
            case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
            }
        }
        break;
    case 11: func_021E8738((int *)p[9], p[4], 120, 1); *state = 14; func_021E8AB4(sys, 12); break;
    case 12: func_021E8AA0((int *)sys, (int)func_021D61CC); break;
    case 13: func_021E8AA0((int *)sys, (int)func_021D495C); break;
    case 14: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}



void func_021D495C(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 24, 2);
        func_021E8AB4(sys, 1); *state = 11; break;
    case 1:
        if (*(u32 *)ctx[8] == 0) {
            func_021DB3A4((char *)p[12], -1, 0, ctx[14]);
            *state = 2;
        }
        break;
    case 2:
        result = func_021DB478((char *)p[12]);
        if (result == 1) {
            *(u32 *)((u32 *)p[16])[8] = 1800;
            p[60] = func_021D646C(ctx[4], ((u32 *)ctx[2])[1], (u32)p);
            func_021D6724((u32_021D6724 *)((u32 *)ctx[5]), (u32_021D6724 *)p);
            *(u32 *)((u32 *)p[16])[10] = ((u32 *)((u32 *)p[16])[14])[21];
            *state = 3;
        }
        if (result != 0) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1:
                func_021D63DC((char *)p);
                func_021E8AA0((int *)sys, (int)func_021D4608);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            }
        }
        break;
    case 3:
        if (func_021DC194((char *)p[12]) == 0) {
            func_021DBFA4((char *)p[12]); *state = 4;
        } else *state = 5;
        break;
    case 4:
        result = func_021DBFB4((char *)p[12]);
        if (result == 1) *state = 1;
        if (result != 0) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1:
                func_021D63DC((char *)p);
                func_021E8AA0((int *)sys, (int)func_021D4608);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            }
        }
        break;
    case 5:
        if (p[6] == 0) *state = 8;
        else if (p[60]) *state = 6;
        else *state = 10;
        p[60] = 0;
        break;
    case 6: *state = 7; break;
    case 7:
        if (func_021D63BC((char *)p)) {
            func_021D639C((char *)p); *state = 8;
        }
        break;
    case 8: func_021D62A4((u32_021D62A4 *)((u32 *)p), 0); *state = 9; break;
    case 9: if (func_021D63B0((char *)p)) *state = 10; break;
    case 10: func_021E8AA0((int *)sys, (int)func_021D4B3C); break;
    case 11: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}



#define CTX ((u32_021D62A4 *)p[16])















#define TIMER (*(u32_021D4B3C *)(p + 0xe0))















#define TIMEOUT (*(u32_021D4B3C *)(p + 0xe8))

















void func_021D4B3C(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired, fixed;
    char *incoming, *data;
    int bad;
    u32_021D4B3C size;
    u32_021D4B3C buf[4];
    struct MsgBank *bank;
    struct U16Vec *str;
    if (*state >= 2 && *state < 8) enable = 1;
    if (*state < 6 || *state > 7) allow = 1; else allow = 0;
    result = func_021D6854(p, enable, allow);
    if (result == 3) {
        *state = 22;
        return;
    }
    switch (*state) {
    case 0:
        P(0xe4) = 0;
        func_021E7E0C((void **)P(0x20), 1);
        func_021E8738((int *)P(0x24), P(0x10), 33, 0);
        *state = 1; break;
    case 1:
        switch (func_021D9F04((char *)P(0x30), 0, 0)) {
        case 1:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D4608); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); return;
        }
        func_021D65F0((u32_021D65F0 *)((u32_021D4B3C *)buf), (u32_021D65F0 *)((u32_021D4B3C *)p));
        func_021DA0D4((void *)P(0x30), 2, 1, ((int *)Q(8))[1], (int *)buf);
        *state = 2; break;
    case 2:
        switch (func_021D9F04((char *)P(0x30), 0, 0)) {
        case 1:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D4608);
            func_021D6954(p); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); return;
        }
        result = func_021DA1E4((void *)P(0x30));
        if (result == 1) { TIMEOUT = 0; *state = 3; }
        else if (result == 2) *state = 1;
        break;
    case 3:
        if (result == 0) {
            if (func_021DC1A0((char *)P(0x30), Q(0x14))) { TIMEOUT = 0; *state = 4; }
            timed = 1;
        }
        break;
    case 4:
        if (func_021DC1E4((char *)P(0x30), &incoming)) {
            data = (char *)Q(0x18);
            size = POKE_REGULATION_GetDataSize() + 0xd4;
            MI_CpuCopy8(incoming, data, size);
            fixed = 0;
            empty = 1;
            for (i = 0; i < 8; i++) if (((u16 *)data)[i] == STRBUF_GetEosChar()) empty = 0;
            if (empty) {
                fixed++;
                bank = func_02045B38(0, 2, 0xd2, 0x8057);
                str = func_02045EC0(bank, 0x8057);
                STRBUF_ToChars(str, (u16 *)data, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete((struct Rec *)bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) { data[0x1d] = 0; fixed++; }
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
                fixed++;
            }
            if (!BMP_OAM_Check5BEC((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0; fixed++;
            }
            if (!PMSI_PARAM_IsValid((struct T *)(data + 0x38), 0x8057)) { PMSI_PARAM_InitSentence(data + 0x38, 1); fixed++; }
            if (fixed == 0) TRADE_HISTORY_GetFromSave(GAME_DATA_GetSaveControl(*(struct Big **)Q(8)));
            TIMEOUT = 0; *state = 5;
        }
        timed = 1; break;
    case 5:
        if (func_021D67BC((char *)Q(0x18), 0x57)) *state = 6;
        else {
            func_021DA36C((void *)(P(0x30)));
            func_021E8AA0((int *)sys, (int)func_021D4B3C);
        }
        break;
    case 6:
        func_021DCA28((char *)P(0x30), Q(0x18), 0x57); *state = 7; break;
    case 7:
        if (func_021DCAEC((char *)P(0x30), &bad)) {
            *(int *)((int *)P(0x40))[16] = bad; *state = 8;
        }
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D5560);
            func_021D6954(p); break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 8:
        if (result == 0) {
            func_021D9ED4((char *)P(0x30), 21); TIMEOUT = 0; *state = 9;
        }
        break;
    case 9:
        if (func_021DA45C((char *)P(0x30)) == 0 && func_021D9EEC((char *)P(0x30))) *state = 10;
        timed = 1; break;
    case 10:
        func_021D9ED4((char *)P(0x30), 22); TIMEOUT = 0; *state = 11; break;
    case 11:
        if (func_021D9EEC((char *)P(0x30))) *state = 12;
        timed = 1; break;
    case 12:
        func_021E7E0C((void **)P(0x20), 0);
        GFL_USE_PlaySeDefaultVolume(0x63a);
        func_021E8738((int *)P(0x24), P(0x10), 34, 1);
        *state = 30; func_021E8AB4(sys, 13); break;
    case 13:
        if (TIMER++ > 120) {
            TIMER = 0; func_021D63F8((u32_021D63F8 *)((unsigned int *)p), Q(0x18)); func_02040588(0, 0); *state = 14;
        }
        break;
    case 14: if (func_021D6460(p)) *state = 15; break;
    case 15: if (TIMER++ > 0) { TIMER = 0; *state = 16; } break;
    case 16:
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        func_021DA5B0((char *)P(0x30), 0, 2, 0, (u32_021D4B3C *)0, 0);
        P(0xfc) = 0;
        P(0xf4) = 0;
        *state = 17;
        break;
    case 17:
        if (P(0xfc) == 0) P(0xfc) = func_021DA6B8((void *)P(0x30), (u32_021D4B3C *)(p + 0xf4));
        if (P(0xfc) == 1) *state = 18;
        if (P(0xfc) != 0) {
            switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
            case 1: func_021DA36C((void *)(P(0x30)));
            case 2: case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                break;
            }
        }
        break;
    case 18:
        DWC_RAPCOMMON_DestroySubHeap(); *state = 19; break;
    case 19:
        func_02040588(0, 1); func_021E8738((int *)P(0x24), P(0x10), 36, 2);
        *state = 30; func_021E8AB4(sys, 20); break;
    case 20:
        if (TIMER++ > 60) { TIMER = 0; Q(4) = 1; func_021E8AA8(sys); }
        break;
    case 21:
        func_021DA36C((void *)(P(0x30)));
        Q(12) = 2;
        if (P(0xf4) != 0) {
            P(0xf8) = 1;
            func_021E8AA0((int *)sys, (int)func_021D51BC);
        } else {
            func_021E8AA0((int *)sys, (int)func_021D54E8);
        }
        break;
    case 22:
        func_021E8738((int *)P(0x24), P(0x10), 39, 1);
        *state = 30; func_021E8AB4(sys, 23); break;
    case 23:
        func_021D6550((u32_021D6550 *)((u32_021D4B3C *)p), 0); *state = 24; break;
    case 24:
        result = func_021D65DC(p);
        if (result == -1) break;
        func_021D65C8(p);
        switch (result) {
        case 0: func_021E8AA0((int *)sys, (int)func_021D56D4); break;
        case 1: *state = 25; break;
        }
        break;
    case 25:
        func_021E8738((int *)P(0x24), P(0x10), 38, 1);
        *state = 30; func_021E8AB4(sys, 26); break;
    case 26:
        func_021D6550((u32_021D6550 *)((u32_021D4B3C *)p), 0); *state = 27; break;
    case 27:
        result = func_021D65DC(p);
        if (result == -1) break;
        func_021D65C8(p);
        switch (result) {
        case 0: *state = 0; break;
        case 1: *state = 22; break;
        }
        break;
    case 28: if (func_021DA434(P(0x30))) *state = 29; break;
    case 29: func_021DA36C((void *)(P(0x30))); *state = 0; break;
    case 30: if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys); break;
    }
    if (timed) {
        expired = 0;
        if (TIMEOUT++ > 2400) { TIMEOUT = 0; expired = 1; }
        if (func_021DA45C((char *)P(0x30))) expired = 1;
        if (expired) *state = 28;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D5560);
            func_021D6954(p); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
    }
}

















/*
 * DA36C receives the live context in r0 here despite its no-argument body.
 */
void func_021D51BC(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    Rec84_021D4240 rec;
    void *list;
    int result;
    switch (*state) {
    case 0:
        if (Q(12) == 2 && P(0xf8) == 0) {
            func_021E8AA0((int *)sys, (int)func_021D54E8);
            return;
        }
        P(0xf8) = 0;
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        *state = 1;
        break;
    case 1:
        func_021E8738((int *)P(0x24), P(0x10), 37, 2);
        *state = 14;
        func_021E8AB4(sys, 2);
        break;
    case 2:
        func_021DA5B0((char *)P(0x30), 1, 2, ((u32_021D51BC *)Q(8))[1], (u32_021D4B3C *)((u32_021D51BC *)Q(0x2c)), Q(12) == 2);
        P(0xfc) = 0;
        P(0xf4) = 0;
        *state = 3;
        break;
    case 3:
        if (P(0xfc) == 0) {
            P(0xfc) = func_021DA6B8((void *)P(0x30), (u32_021D4B3C *)((u32_021D51BC *)(p + 0xf4)));
            if (P(0xfc) != 0 && P(0xf4) != 0)
                func_021E8AC0(*(int *)Q(8), *(int *)Q(0x2c));
        }
        if (P(0xfc) == 1) {
            ((u32_021D51BC *)Q(0x2c))[5] = func_021DADAC((u8 *)P(0x30));
            *state = 4;
        }
        if (P(0xfc) != 0) {
            switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
            case 1: func_021DA36C((void *)(P(0x30)));
            case 2: case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                break;
            }
        }
        break;
    case 4:
        DWC_RAPCOMMON_DestroySubHeap();
        if (Q(12) == 2) func_021E8AA0((int *)sys, (int)func_021D54E8);
        else *state = 5;
        break;
    case 5:
        list = MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(*(struct Big **)Q(8)));
        MISC_SAVEDATA_InsertRecentValue(list, func_02008530((void *)Q(0x18)));
        *state = 6;
        func_021DA384((char *)P(0x30));
        break;
    case 6:
        if (func_021DA390((char *)P(0x30))) {
            if (*(int *)((int *)P(0x40))[8] == 0) *state = 8;
            else {
                func_021E8738((int *)P(0x24), P(0x10), 42, 2);
                *state = 14;
                func_021E8AB4(sys, 7);
            }
        }
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: *state = 7; break;
        case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 7:
        if (*(int *)Q(0x20) == 0) *state = 8;
        break;
    case 8:
        MI_CpuFill8(&rec, 0, 0x54);
        rec.data = *(Rec80_021D4240 *)((int *)P(0x40))[9];
        rec.last = *(u32_021D51BC *)((int *)P(0x40))[10];
        func_021DBC04((u8 *)P(0x30), 3, (struct Record *)(&rec));
        *state = 9;
        break;
    case 9:
        result = func_021DBDAC((char *)P(0x30));
        if (result == 1) {
            *(int *)((int *)P(0x40))[8] = 0x708;
            *state = 10;
        }
        if (result != 0) {
            switch (func_021D9F04((char *)P(0x30), 0, 0)) {
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                *(int *)((int *)P(0x40))[8] = 0x708;
                break;
            case 1:
                *(int *)((int *)P(0x40))[8] = 0x708;
                *state = 10;
                break;
            }
        }
        break;
    case 10:
        func_021E8738((int *)P(0x24), P(0x10), 88, 1);
        *state = 14;
        func_021E8AB4(sys, 11);
        break;
    case 11:
        func_021E8738((int *)P(0x24), P(0x10), 40, 2);
        *state = 14;
        func_021E8AB4(sys, 12);
        break;
    case 12:
        GAME_DATA_SaveStart(*(int *)Q(8));
        *state = 13;
        break;
    case 13:
        switch (GAME_DATA_SaveMain(*(u8 **)Q(8))) {
        case 0: case 1: break;
        case 2: case 3:
            Q(4) = 2;
            func_021E8AA8(sys);
            break;
        }
        break;
    case 14:
        if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys);
        break;
    }
}

















void func_021D54E8(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0:
        switch(func_021D9F04((char *)p[12],0,(void *)1)) {
        case 0: state[0]=1; break;
        case 1: case 4: func_021E8AA0((int *)sys,(int)func_021D5560); break;
        case 2: func_021E8AA0((int *)sys,(int)func_021D61A4); break;
        case 3: break;
        }
        break;
    case 1: func_021E8AA0((int *)sys,(int)func_021D5560); break;
    case 2: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}

















void func_021D5560(unsigned sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0:
        switch (func_021D9F04((char *)p[12], 0, (void *)1)) {
        case 0: case 1: case 4: *state = 1; break;
        case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        case 3: break;
        }
        break;
    case 1:
        func_021E8738((int *)p[9], p[4], 0x26, 1);
        *state = 4;
        func_021E8AB4(sys, 2);
        break;
    case 2:
        func_021D6550((u32_021D6550 *)((u32_021D4B3C *)((u32_021D4B3C *)p)), 0);
        *state = 3;
        break;
    case 3:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: func_021E8AA0((int *)sys, (int)func_021D495C); break;
            case 1: func_021E8AA0((int *)sys, (int)func_021D5634); break;
            }
        }
        break;
    case 4:
        if (func_021E8844((const int *)p[9])) func_021E8AB8(sys);
        break;
    }
}

















void func_021D5634(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        func_021E8738((int *)p[9],p[4],0x27,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: func_021D6550((u32_021D6550 *)((u32_021D4B3C *)((u32_021D4B3C *)p)), 0); state[0]=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: func_021DA36C((void *)((int)((void *)p[12]))); func_021E8AA0((int *)sys,(int)func_021D56D4); break;
            case 1: func_021E8AA0((int *)sys,(int)func_021D5560); break;
            }
        }
        break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}















#undef TIMER














#undef TIMER













#undef TIMER












#undef TIMER











#undef TIMER










#undef TIMER









#undef TIMER








#undef TIMER







#undef TIMER






#undef TIMER





#undef TIMER




#undef TIMER



#undef TIMER


#undef TIMER

#undef TIMER
#define TIMER (*(u32_021D5908 *)(p + 0xe0))















#undef TIMEOUT














#undef TIMEOUT













#undef TIMEOUT












#undef TIMEOUT











#undef TIMEOUT










#undef TIMEOUT









#undef TIMEOUT








#undef TIMEOUT







#undef TIMEOUT






#undef TIMEOUT





#undef TIMEOUT




#undef TIMEOUT



#undef TIMEOUT


#undef TIMEOUT

#undef TIMEOUT
#define TIMEOUT (*(u32_021D5908 *)(p + 0xe8))
















/*
 * The original loads p[12] before the otherwise parameterless DA36C.
 */
void func_021D56D4(unsigned sys, int *state, int *p)
{
    char *q = (char *)p[16];
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 40, 2);
        func_021E8AB4(sys, 1);
        *state = 7;
        break;
    case 1:
        GAME_DATA_SaveStart(**(int * *)&((struct Obj08273 *)q)->f8);
        *state = 2;
        break;
    case 2:
        if (GAME_DATA_SaveMain((u8 *)**(int * *)&((struct Obj08273 *)q)->f8) == 2) *state = 3;
        break;
    case 3:
        func_021E8738((int *)p[9], p[4], 37, 2);
        *state = 7;
        func_021E8AB4(sys, 4);
        break;
    case 4:
        if (**(int * *)&((struct Obj08273 *)q)->f20 == 0) {
            func_021DBC04((u8 *)p[12], 2, 0);
            *state = 5;
        }
        break;
    case 5:
        if (func_021DBDAC((char *)p[12])) {
            **(int **)((char *)p[16] + 0x20) = 0x708;
            *state = 6;
            func_021D9F04((char *)p[12], (void *)1, 0);
        }
        break;
    case 6:
        func_021DA36C((void *)p[12]);
        ((struct Obj08273 *)q)->f4 = 0;
        func_021E8AA0((int *)sys, (int)func_021D61CC);
        break;
    case 7:
        if (func_021E8844((int *)p[9])) func_021E8AB8(sys);
        break;
    }
}
















void func_021D57BC(unsigned sys, int *state, int *p)
{
    unsigned int r;
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 26, 1);
        func_021D62A4((u32_021D62A4 *)((u32_021D57BC *)p), 1);
        *state = 1;
        break;
    case 1:
        if (func_021D63B0((char *)p)) *state = 2;
        break;
    case 2:
        if (func_021E8844((int *)p[9])) *state = 3;
        break;
    case 3:
        func_021E8738((int *)p[9], p[4], 24, 2);
        *state = 4;
        break;
    case 4:
        func_021D6788((char *)p, func_021D61F0);
        *state = 5;
        switch (func_021D9F04((char *)p[12], 0, 0)) {
        case 1:
            func_021D63DC((char *)p);
            func_021E8AA0((int *)sys, (int)func_021D4608);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D61A4);
            break;
        }
        break;
    case 5:
        r = func_021D679C((char *)p);
        if (r == 0) func_021E8AA0((int *)sys, (int)func_021D5908);
        else if (r == 1) *state = 6;
        else if (r == 3) func_021E8AA0((int *)sys, (int)func_021D61A4);
        if (r != 0xffff) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1:
                func_021D63DC((char *)p);
                func_021E8AA0((int *)sys, (int)func_021D4608);
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                break;
            }
        }
        break;
    case 6:
        func_021E8738((int *)p[9], p[4], 120, 1);
        *state = 7;
        break;
    case 7:
        if (func_021E8844((int *)p[9])) func_021E8AA0((int *)sys, (int)func_021D61CC);
        break;
    }
}
















/*
 * DC1A0's live return is tested here; DA434/DA36C receive the context r0.
 */
void func_021D5908(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired;
    char *incoming, *data;
    int bad;
    u32_021D5908 size;
    u32_021D5908 buf[4];
    struct MsgBank *bank;
    struct U16Vec *str;
    if (*state >= 3 && *state < 13) enable = 1;
    if (*state < 11 || *state > 12) allow = 1; else allow = 0;
    result = func_021D6854(p, enable, allow);
    if (result == 3) {
        func_021E8AA0((int *)sys, (int)func_021D60E0);
        return;
    }
    switch (*state) {
    case 0:
        func_021D6724((u32_021D6724 *)((u32_021D5908 *)Q(0x14)), (u32_021D6724 *)((u32_021D5908 *)p)); *state = 1; break;
    case 1:
        P(0xe4) = 0;
        func_021E7E0C((void **)P(0x20), 1);
        func_021E8738((int *)P(0x24), P(0x10), 33, 0);
        *state = 2; break;
    case 2:
        switch (func_021D9F04((char *)P(0x30), 0, 0)) {
        case 1:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D4608); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); return;
        }
        func_021D65F0((u32_021D65F0 *)((u32_021D4B3C *)buf), (u32_021D65F0 *)((u32_021D4B3C *)((u32_021D5908 *)p)));
        func_021DA0D4((void *)P(0x30), 3, 0, ((int *)Q(8))[1], (int *)buf);
        *state = 3; break;
    case 3:
        switch (func_021D9F04((char *)P(0x30), 0, 0)) {
        case 1:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D4608);
            func_021D6954(p); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); return;
        }
        result = func_021DA1E4((void *)P(0x30));
        if (result == 1) { TIMEOUT = 0; *state = 6; }
        else if (result == 2) *state = 2;
        break;
    case 4: case 5: break;
    case 6:
        func_021D9ED4((char *)P(0x30), 20); *state = 7; TIMEOUT = 0; break;
    case 7:
        if (func_021D9EEC((char *)P(0x30))) { TIMEOUT = 0; *state = 8; }
        timed = 1; break;
    case 8:
        if (result == 0) {
            if (func_021DC1A0((char *)P(0x30), Q(0x14))) { TIMEOUT = 0; *state = 9; }
            timed = 1;
        }
        break;
    case 9:
        if (func_021DC1E4((char *)P(0x30), &incoming)) {
            data = (char *)Q(0x18);
            size = POKE_REGULATION_GetDataSize() + 0xd4;
            MI_CpuCopy8(incoming, data, size);
            empty = 1;
            for (i = 0; i < 8; i++) if (((u16 *)data)[i] == STRBUF_GetEosChar()) empty = 0;
            if (empty) {
                bank = func_02045B38(0, 2, 0xd2, 0x8057);
                str = func_02045EC0(bank, 0x8057);
                STRBUF_ToChars(str, (u16 *)data, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete((struct Rec *)bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) data[0x1d] = 0;
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
            }
            if (!BMP_OAM_Check5BEC((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0;
            }
            if (!PMSI_PARAM_IsValid((struct T *)(data + 0x38), 0x8057)) PMSI_PARAM_InitSentence(data + 0x38, 1);
            TIMEOUT = 0; *state = 10;
        }
        timed = 1; break;
    case 10:
        if (func_021D67BC((char *)Q(0x18), 0x57)) *state = 11;
        else {
            func_021DA36C((void *)(P(0x30)));
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D5908);
        }
        break;
    case 11:
        func_021DCA28((char *)P(0x30), Q(0x18), 0x57); *state = 12; break;
    case 12:
        if (func_021DCAEC((char *)P(0x30), &bad)) {
            *(int *)((int *)P(0x40))[16] = bad; *state = 13;
        }
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D6048);
            func_021D6954(p); break;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 13:
        if (result == 0) {
            func_021D9ED4((char *)P(0x30), 21); TIMEOUT = 0; *state = 14;
        }
        break;
    case 14:
        if (func_021DA45C((char *)P(0x30)) == 0 && func_021D9EEC((char *)P(0x30))) *state = 15;
        timed = 1; break;
    case 15:
        func_021D9ED4((char *)P(0x30), 22); TIMEOUT = 0; *state = 16; break;
    case 16:
        timed = 1;
        if (func_021D9EEC((char *)P(0x30))) *state = 17;
        break;
    case 17:
        func_021E7E0C((void **)P(0x20), 0);
        GFL_USE_PlaySeDefaultVolume(0x63a); func_021D65C8(p);
        func_021E8738((int *)P(0x24), P(0x10), 34, 1);
        *state = 25; func_021E8AB4(sys, 18); break;
    case 18:
        if (TIMER++ > 120) {
            TIMER = 0; func_021D63F8((u32_021D63F8 *)((unsigned int *)p), Q(0x18)); func_02040588(0, 0); *state = 19;
        }
        break;
    case 19: if (func_021D6460(p)) *state = 20; break;
    case 20: if (TIMER++ > 300) { TIMER = 0; *state = 21; } break;
    case 21:
        func_02040588(0, 1); func_021E8738((int *)P(0x24), P(0x10), 36, 2);
        *state = 25; func_021E8AB4(sys, 22); break;
    case 22:
        if (TIMER++ > 60) { TIMER = 0; Q(4) = 1; func_021E8AA8(sys); }
        break;
    case 23: if (func_021DA434(P(0x30))) *state = 24; break;
    case 24: func_021DA36C((void *)(P(0x30))); *state = 1; break;
    case 25: if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys); break;
    }
    if (timed) {
        expired = 0;
        if (TIMEOUT++ > 2400) { TIMEOUT = 0; expired = 1; }
        if (func_021DA45C((char *)P(0x30))) expired = 1;
        if (expired) *state = 23;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D6048);
            func_021D6954(p); return;
        case 2:
            func_021E7E0C((void **)P(0x20), 0);
            func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
    }
}














#undef TIMER













#undef TIMER












#undef TIMER











#undef TIMER










#undef TIMER









#undef TIMER








#undef TIMER







#undef TIMER






#undef TIMER





#undef TIMER




#undef TIMER



#undef TIMER


#undef TIMER

#undef TIMER
#define TIMER (*(u32_021D4B3C *)(p + 0xe0))















/*
 * Lever: source arm order is 0,3,1,2,4..11; numeric ordering differs
 * by 119 concrete bytes although the compiled size remains 476.
 * DC2C0's return r0 is tested here despite its legacy void declaration.
 */
void func_021D5E24(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    void *list;
    switch (*state) {
    case 0:
        if (((struct Obj02885 *)q)->fC == 2) func_021E8AA0((int *)sys, (int)func_021D6000);
        else *state = 3;
        break;
    case 3:
        func_021E8738((int *)P(0x24), P(0x10), 43, 2);
        *state = 11;
        func_021E8AB4(sys, 1);
        TIMER = 0;
        break;
    case 1:
        if (func_021DC2C0(P(0x30), *(char * *)&((struct Obj02885 *)q)->f2C + 0x10)) *state = 2;
        break;
    case 2:
        if (func_021DC2D8((char *)P(0x30), (ul *)(*(char * *)&((struct Obj02885 *)q)->f2C + 0x14))) *state = 4;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 4:
        list = MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl((struct Big *)**(int * *)&((struct Obj02885 *)q)->f8));
        MISC_SAVEDATA_InsertRecentValue(list, func_02008530(((struct Obj02885 *)q)->f18));
        func_021E8AC0(**(int * *)&((struct Obj02885 *)q)->f8, **(int * *)&((struct Obj02885 *)q)->f2C);
        func_021DA384((char *)P(0x30));
        *state = 5;
        break;
    case 5:
        TIMER++;
        if (func_021DA390((char *)P(0x30))) *state = 6;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 6:
        if (TIMER++ > 30) { TIMER = 0; *state = 7; }
        break;
    case 7:
        *state = 8;
        break;
    case 8:
        func_021E8738((int *)P(0x24), P(0x10), 40, 2);
        *state = 11;
        func_021E8AB4(sys, 9);
        break;
    case 9:
        GAME_DATA_SaveStart(**(int * *)&((struct Obj02885 *)q)->f8);
        *state = 10;
        break;
    case 10:
        switch (GAME_DATA_SaveMain((u8 *)**(int * *)&((struct Obj02885 *)q)->f8)) {
        case 0: case 1: break;
        case 2: case 3: ((struct Obj02885 *)q)->f4 = 2; func_021E8AA8(sys); break;
        }
        break;
    case 11:
        if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys);
        break;
    }
}















void func_021D6000(unsigned sys,int *state,int *p)
{
    switch(state[0]) {
    case 0: state[0]=1; break;
    case 1: state[0]=2; break;
    case 2: func_021E8AA0((int *)sys,(int)func_021D6048); break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}















void func_021D6048(unsigned sys,int *state,int *p)
{
    int result;
    switch(state[0]) {
    case 0:
        func_021E8738((int *)p[9],p[4],0x26,1);
        state[0]=3;
        func_021E8AB4(sys,1);
        break;
    case 1: func_021D6550((u32_021D6550 *)((u32_021D4B3C *)((unsigned int *)p)), 0); state[0]=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: func_021E8AA0((int *)sys,(int)func_021D5908); break;
            case 1: func_021E8AA0((int *)sys,(int)func_021D60E0); break;
            }
        }
        break;
    case 3: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}













void func_021D60E0(u32_021D4B3C sys,int *state,u32_021D4B3C *p)
{
    u32_021D4B3C *ctx=(u32_021D4B3C *)p[16];
    int result;
    switch(*state) {
    case 0:
        func_021E8738((int *)p[9],p[4],39,1); *state=5; func_021E8AB4(sys,1); break;
    case 1: func_021D6550((u32_021D6550 *)((u32_021D4B3C *)p), 0); *state=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: ctx[1]=0; *state=3; break;
            case 1: func_021E8AA0((int *)sys,(int)func_021D6048); break;
            }
        }
        break;
    case 3: func_021E8738((int *)p[9],p[4],43,2); *state=5; func_021E8AB4(sys,4); break;
    case 4: func_021E8AA0((int *)sys,(int)func_021D61CC); break;
    case 5: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}












void func_021D61A4(void *obj,int unused,u8 *p) { ((struct Obj24225 *)(*(u8 * *)&((struct Obj08274 *)p)->f40))->f4=3; if(((struct Obj08274 *)p)->f30) { func_021D9EA0(((struct Obj08274 *)p)->f30); *(u32_021D4B3C *)&((struct Obj08274 *)p)->f30=0; } func_0200FBB0(); func_021E8AA8((int)obj); }












/*
 * (it is an unlabelled leaf in the overlapping window: ov093/ov170/ov177 hold
 * code or a pool word at that address but none traces a function start), so
 * no evidence class attests it.  Every concrete byte matches; --suggest-split
 * cannot help because the site is a direct `bl` with no second caller.
 */
void func_021D61CC(void *a, u32_021D4B3C **pp, char *p)
{
    if (*pp != 0)
        return;
    if (((struct Obj10679 *)p)->f30 != 0) {
        func_021D9EA0((u8 *)(((struct Obj10679 *)p)->f30));
        ((struct Obj10679 *)p)->f30 = 0;
    }
    func_021E8AA8((int)a);
}











void func_021D61F0(u32_021D61F0 sys,int *state,char *p)
{
    char *base=*(char * *)&((struct Obj24227 *)(*(char * *)&((struct Obj03317 *)p)->f40))->f14;
    int result;
    switch(*state) {
    case 0:
        ((struct Obj03317 *)p)->fE0=0;
        MI_CpuFill8(p+0x44,0,0x9c);
        (*state)++;
        break;
    case 1:
        func_021DCB58(((struct Obj03317 *)p)->f30,base+0xd4,1);
        (*state)++;
        break;
    case 2:
        result=func_021DCC28(((struct Obj03317 *)p)->f30,(u8 *)(p+0x44));
        if(result==1) *state=3;
        else if(result==2) { ((struct Obj03317 *)p)->f3C=2; *state=4; }
        else if(result==3) { ((struct Obj03317 *)p)->f3C=3; *state=4; }
        break;
    case 3:
        if(((struct Obj03317 *)p)->f44==0) {
            MI_CpuCopy8(p+0x60,base+0x54,0x80);
            ((struct Obj03317 *)p)->f3C=0; *state=4;
        } else { ((struct Obj03317 *)p)->f3C=1; *state=4; }
        break;
    case 4: func_021E8AA8(sys); break;
    }
}











void func_021D62A4(u32_021D62A4 *p, u32_021D62A4 mode)
{
    u32_021D62A4 sys;
    int base,flag;
    Desc_021D4240 desc;
    if(p[6]==0) {
        sys=(u32_021D62A4)func_02012944((void *)REC[0]);
        base=func_021E5548((int *)p[0]);
        MI_CpuFill8(&desc,0,20);
        if(mode==0) {
            desc.kind=REC[1]; flag=1;
            desc.count=BSUBWAY_SAVEDATA_GetStat(CTX[4],REC[1]+5,0);
            desc.a=BSUBWAY_SAVEDATA_GetStat(CTX[4],REC[1]+5,1);
            desc.b=BSUBWAY_SAVEDATA_GetStat(CTX[4],REC[1]+5,2);
            desc.total=desc.a+desc.b;
            if(desc.count==0 && desc.total==0) desc.count=1500;
        } else if(mode==1) {
            desc.kind=REC[1]; flag=0; desc.count=0;
            desc.a=BSUBWAY_SAVEDATA_GetStat(CTX[4],REC[1],1);
            desc.b=BSUBWAY_SAVEDATA_GetStat(CTX[4],REC[1],2);
            desc.total=desc.a+desc.b;
        }
        desc.name=func_02008554((const struct Sub0200852CObj *)sys);
        p[6]=func_021E5C20(&desc,flag,sys,base,p[1],p[2],p[3],p[4],p[5],87);
    }
}












/*
 * Release path for the ov175 object's 0x18 block pointer: free it
 *     through 0x021E5D40 and clear the field.  Null-safe, so a second call is a
 *     no-op.
 */
void func_021D639C(char *obj)
{
    u32_021D639C p = ((struct Obj10680 *)obj)->f18;

    if (p != 0) {
        func_021E5D40(p);
        ((struct Obj10680 *)obj)->f18 = 0;
    }
}











/*
 * Thunk: hands the +0x18 block to 0x021E64C8 and returns its result.  No
 *     lr save anywhere, so the compiler emitted the call as a pooled
 *     `ldr r3; bx r3` tail jump.
 */
u32_021D63B0 func_021D63B0(char *obj)
{
    return func_021E64C8(((struct Obj24228 *)obj)->f18);
}











/*
 * Thunk: hands the +0x18 block to 0x021E65FC and returns its result, the
 *     poll partner of func_021D63B0 on the same field.
 */
u32_021D63B0 func_021D63BC(char *obj)
{
    return func_021E65FC(((struct Obj24229 *)obj)->f18);
}











void func_021D63C8(char *obj, u32_021D63B0 arg)
{
    func_021D62A4((u32_021D62A4 *)((u32_021D63B0 *)obj), arg);
    while (func_021D63B0(obj) == 0)
        ;
}










/*
 * Only when the +0x18 pointer is live: spin on func_021D63BC until it
 *     reports ready, then hand the object to the func_021D639C release path.
 */
void func_021D63DC(char *obj)
{
    if (((struct Obj10680 *)obj)->f18 != 0) {
        while (func_021D63BC(obj) == 0)
            ;
        func_021D639C(obj);
    }
}









/*
 * mode: original assigns constructor selectors only for mode 0 or 1.
 */
void func_021D63F8(u32_021D63F8 *p,u32_021D63F8 arg)
{
    u32_021D63F8 b,a;
    if (p[7] == 0) {
        u32_021D63F8 base = func_021E5548((int *)p[0]);
        u32_021D63F8 mode = ((u32_021D63F8 *)p[16])[0];
        if (mode == 0) { a=1; b=2; }
        else if (mode == 1) { a=0; b=3; }
        p[7]=func_021E7520(arg,base,p[1],p[2],p[3],p[4],p[5],b,a,0,87);
    }
}










/*
 * Release path for the ov175 object's 0x1c pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void func_021D644C(char *obj)
{
    u32_021D644C p = ((struct Obj14327 *)obj)->f1C;

    if (p != 0) {
        func_021E7710(p);
        ((struct Obj14327 *)obj)->f1C = 0;
    }
}









/*
 * Unlabelled blocker leaf for func_021D5908; parent confirmed unowned.
 */
int func_021D6460(char *p)
{
    return func_021E777C(*(struct Work * *)&((struct Obj00171 *)p)->f1C);
}









int func_021D646C(u32_021D646C save, u32_021D646C kind, u32_021D646C obj)
{
    int *q;
    u32_021D646C a;
    u32_021D646C b;
    u32_021D646C c;
    int changed;
    switch (kind) {
    case 0:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[3];
        b = q[0x40 / 4];
        c = q[0x3C / 4];
        break;
    case 1:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[0];
        b = q[0x28 / 4];
        c = q[0x24 / 4];
        break;
    case 2:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[0x10 / 4];
        b = q[0x48 / 4];
        c = q[0x44 / 4];
        break;
    case 3:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[1];
        b = q[0x30 / 4];
        c = q[0x2C / 4];
        break;
    case 4:
        q = *(int **)(*(u32_021D646C *)(obj + 0x40) + 0x38);
        a = q[2];
        b = q[0x38 / 4];
        c = q[0x34 / 4];
        break;
    }
    changed = (a != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 0) || b != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 1) || c != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 2));
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 0, a);
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 1, b);
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 2, c);
    return changed;
}










/*
 * Thumb jump table over 0..4: modes 1 and 4 pass the constant 1, modes 0 and
 * 3 pass 2, mode 2 and everything above 4 do nothing.
 *
 * func_/sub_ label in asm/arm9/main.s and no other reference anywhere in the
 * listings, so the site reports "unresolved: 0200E008 (arm, from header) has
 * no witness outside 021D6524..021D6550".  Bytes and size are correct
 * (44 bytes, 2 relocation sites, both wildcarded); it needs an entry for the
 * arm9 target to promote.
 */
void func_021D6524(int a, int b, u32_021D6524 c)
{
    switch (c) {
    case 1:
    case 4:
        BSUBWAY_SAVEDATA_IncStat((u8 *)a, b, 1);
        break;
    case 0:
    case 3:
        BSUBWAY_SAVEDATA_IncStat((u8 *)a, b, 2);
        break;
    }
}








void func_021D6550(u32_021D6550 *p,int mode)
{
    struct { u32_021D6550 x0,x1,x2,x3,x4,x5,x6,x7; u16 a,b,c,d; int enabled; u16 kind,pad; } desc;
    if (p[10]==0) {
        MI_CpuFill8(&desc,0,48);
        desc.x0=p[4]; desc.x1=p[2]; desc.x2=p[3];
        desc.a=0; desc.b=15; desc.c=13; desc.d=1;
        switch(mode) {
        case 0:
            desc.x3=31; desc.x4=32; desc.x7=2;
            desc.enabled=1; desc.kind=1;
            break;
        case 1:
            desc.x3=27; desc.x4=28; desc.x5=29;
            desc.x7=3; desc.enabled=1; desc.kind=2;
            break;
        }
        p[11]=mode;
        p[10]=func_021E888C(&desc,87);
    }
}









void func_021D65C8(char *obj)
{
    u32_021D65C8 p = ((struct Obj00171 *)obj)->f28;

    if (p != 0) {
        func_021E89D0(p);
        ((struct Obj00171 *)obj)->f28 = 0;
    }
}









/*
 * Query brother of func_021D65C8: returns the +0x28 block's handler
 *     result through 0x021E8A00, or -1 when the field is empty.
 */
int func_021D65DC(char *obj)
{
    u32_021D65DC p = ((struct Obj24230 *)obj)->f28;

    if (p != 0)
        return func_021E8A00(p);
    return -1;
}








void func_021D65F0(u32_021D65F0 *p,u32_021D65F0 *q)
{
    u32_021D65F0 *ctx,*s;
    MI_CpuFill8(p,0,16);
    ctx=(u32_021D65F0 *)q[16]; s=(u32_021D65F0 *)ctx[14];
    p[1]=s[8]; p[2]=0;
    s=(u32_021D65F0 *)ctx[14];
    p[3]=s[13]+(s[14]+(s[11]+(s[12]+(s[17]+(s[18]+(s[9]+(s[10]+(s[16]+s[15]))))))));
    switch(((u32_021D65F0 *)ctx[2])[1]) {
    case 0: p[0]=((u32_021D65F0 *)ctx[14])[3]; break;
    case 1: p[0]=((u32_021D65F0 *)ctx[14])[0]; break;
    case 2: p[0]=((u32_021D65F0 *)ctx[14])[4]; break;
    case 3: p[0]=((u32_021D65F0 *)ctx[14])[1]; break;
    case 4: p[0]=((u32_021D65F0 *)ctx[14])[2]; break;
    }
}








void func_021D6698(u32_021D6698 *p,u32_021D6698 *q)
{
    u32_021D6698 save=((u32_021D6698 *)((u32_021D6698 *)q[16])[2])[0];
    u32_021D6698 profile=(u32_021D6698)GAME_DATA_GetSaveControl((struct Big *)save);
    u32_021D6698 blob;
    u32_021D6698 *ctx;
    p[17]=100;
    blob=(u32_021D6698)func_02012944((void *)save);
    MI_CpuCopy8((void *)blob,p,MYSTATUS_GetSize());
    MISC_SAVEDATA_CopyQuadRecord(func_0200E6E8(profile),0,(struct Rec0200E6FC *)((char *)(p+14)));
    ctx=(u32_021D6698 *)q[16];
    if(ctx[0]==0) {
        p[10]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32_021D6698 *)ctx[2])[1]+5,1);
        ctx=(u32_021D6698 *)q[16];
        p[11]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32_021D6698 *)ctx[2])[1]+5,2);
    } else {
        p[10]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32_021D6698 *)ctx[2])[1],1);
        ctx=(u32_021D6698 *)q[16];
        p[11]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32_021D6698 *)ctx[2])[1],2);
    }
    p[18]=WIFILIST_GetGsProfileId((void *)GAME_DATA_GetField1A0((const struct BigObj *)save));
}








/*
 * extent: two-byte alignment padding at 021D6786.
 */
void func_021D6724(u32_021D6724 *p, u32_021D6724 *q)
{
    u32_021D6724 *r = (u32_021D6724 *)q[16];
    if (r[0] == 0) {
        p[10] = BSUBWAY_SAVEDATA_GetStat(r[4], ((u32_021D6724 *)r[2])[1] + 5, 1);
        r = (u32_021D6724 *)q[16];
        p[11] = BSUBWAY_SAVEDATA_GetStat(r[4], ((u32_021D6724 *)r[2])[1] + 5, 2);
        r = (u32_021D6724 *)q[16];
        p[13] = BSUBWAY_SAVEDATA_GetStat(r[4], ((u32_021D6724 *)r[2])[1] + 5, 0);
    } else {
        p[10] = BSUBWAY_SAVEDATA_GetStat(r[4], ((u32_021D6724 *)r[2])[1], 1);
        r = (u32_021D6724 *)q[16];
        p[11] = BSUBWAY_SAVEDATA_GetStat(r[4], ((u32_021D6724 *)r[2])[1], 2);
    }
}








/*
 * Closes the +0x38 stream handle through 0x021E8AA0 and parks the +0x3c
 *     result word at its "no data" sentinel 0xFFFF.
 */
void func_021D6788(char *obj, void *fn)
{
    func_021E8AA0((int *)(((struct Obj01562 *)obj)->f38), (int)fn);
    ((struct Obj01562 *)obj)->f3C = 0xFFFF;
}








u32_021D679C func_021D679C(char *obj)
{
    func_021E8A80(((struct Obj01562 *)obj)->f38);
    if (func_021E8A90((int * *)(((struct Obj01562 *)obj)->f38)) != 0)
        return ((struct Obj01562 *)obj)->f3C;
    return 0xFFFF;
}








/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * The second call, at +0x0C, targets 0x021E8A90.  That address carries no
 * func_/sub_ label in ANY listing -- ov093 has a bare `bx lr` there and
 * ov177 has plain .word data -- so no class can attest it: four call
 * sites image-wide (ov175 x2, ov176 x3) are not enough without a traced
 * entry point.  Bytes are exact; only the relocation is unwitnessed.
 */

/*
 * lever: `int i` declared before the list pointer gives i r4 and list r5
 * (declaration-order-decides-which-register-a-local-gets.md); the earlier
 * DIFF was that r4/r5 swap alone.
 * leaf: +008A NHTTP_RAP_EvilCheckFreeArray resolves as matched through
 *   src/matched/ov/ov114_func_021B9A8C.c (pkt_ov114_021B9A8C), the
 *   unlabelled ov114 tail-call stub to 0x020307B0.
 */
int func_021D67BC(char *p, u16 heapId)
{
    int i;
    u32_021D67BC size;
    void *list=p+0xd4;
    int heap=(heapId&0x7fff)|0x8000;
    void *buf;
    u32_021D67BC ret;
    size=func_020173EC();
    buf=NHTTP_RAP_EvilCheckAllocArray(size,POKEPARTY_GetCount(list),(u16)heap);
    for(i=0;i<(int)POKEPARTY_GetCount(list);i++) {
        void *entry=POKEPARTY_GetMember(list,i);
        NHTTP_RAP_EvilCheckSetElement((int)buf,(int)entry,func_020173EC(),i);
    }
    size=func_020173EC();
    ret=NHTTP_RAP_VerifySignature(buf,size,POKEPARTY_GetCount(list),p+0x54,heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}








int func_021D6854(char *obj, int trigger, int go)
{
    int r;

    switch (((struct Obj00171 *)obj)->fE4) {
    case 0:
        if (trigger != 0 && (KEY_GetTrg() & 2))
            ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        else return 0;
        break;
    case 1:
        func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x23, 1);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 2:
        if (!func_021E8844((const int *)(((struct Obj00171 *)obj)->f24)))
            break;
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 3:
        func_021D6550((u32_021D6550 *)((u32_021D6854 *)obj), 0);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 4:
        r = func_021D65DC(obj);
        if (r == -1)
            break;
        func_021D65C8(obj);
        switch (r) {
        case 0:
            ((struct Obj00171 *)obj)->fE4 = 5;
            break;
        case 1:
            func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x21, 0);
            ((struct Obj00171 *)obj)->fE4 = 0;
            return 2;
        }
        break;
    case 5:
        func_021E8738((int *)(((struct Obj00171 *)obj)->f24), ((struct Obj00171 *)obj)->f10, 0x2b, 2);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        break;
    case 6:
        if (go == 0)
            break;
        func_021DA434(((struct Obj00171 *)obj)->f30);
        ((struct Obj00171 *)obj)->fE4 = ((struct Obj00171 *)obj)->fE4 + 1;
        func_021E7E0C((void **)(((struct Obj00171 *)obj)->f20), 0);
        func_021DA36C((void *)(((struct Obj00171 *)obj)->f30));
        if (!func_0200FB24() && GFL_NET_GetRunState())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct Obj00171 *)obj)->fE4 = 0;
        return 3;
    }
    return 1;
}








/*
 * Clears the word at +0xe4 (the last-read length) and then tail-calls the
 *     +0x28 release path func_021D65C8, which is why nothing is saved.
 */
void func_021D6954(char *obj)
{
    ((struct Obj24232 *)obj)->fE4 = 0;
    func_021D65C8(obj);
}







/*
 * PROCSYS_AllocProcWork's r0 is read after the call, requiring a returning declaration.
 */
int func_021D6964(void *sys,int unused,u32_021D6964 *ctx)
{
    u32_021D6964 *p;
    func_02034AC4((int)ov067_id); func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1,87,0x30000);
    p=PROCSYS_AllocProcWork(sys,0x270,87); MI_CpuFill8(p,0,0x270);
    p[0x104/4]=(u32_021D6964)ctx;
    p[0x108/4]=(u32_021D6964)REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*(u32_021D6964 *)ctx[2]))),0);
    p[0]=(u32_021D6964)func_021E5440(1,87);
    p[1]=(u32_021D6964)(u32_021D6964 *)func_021E567C(func_021E5548((int *)p[0]),0,87);
    p[2]=(u32_021D6964)GF_FONT_Create(0x17,0,0,0,87);
    p[3]=(u32_021D6964)GF_FONT_Create(0x17,3,0,0,87);
    p[4]=PRINTSYS_QUE_Create((void *)87); p[5]=(u32_021D6964)func_02045B38(0,2,0xd2,87);
    p[6]=(u32_021D6964)WORDSET_Create(8,0x40,87);
    p[0x34/4]=(u32_021D6964)func_021D9DC8(((u32_021D6964 *)p[0x104/4])[0xf],(void *)(*(u32_021D6964 *)ctx[2]),ctx[7],87);
    p[0x2c/4]=(u32_021D6964)func_021E8568(0, 15, 14, 10, (void *)p[4], (void *)p[2], 87);
    p[0x38/4]=(u32_021D6964)func_021E8A3C((int)p,(int)func_021D6BF4,87);
    p[0x3c/4]=(u32_021D6964)func_021E8A3C((int)p,0,87);
    p[0x28/4]=(u32_021D6964)func_021E7D20((void *)func_021E5548((int *)p[0]),(void *)p[1],87);
    func_021E7E0C((void **)p[0x28/4],0);
    p[0xfc/4]=(u32_021D6964)POKEPARTY_Create(87); func_021DD008((char *)p[0x34/4],1);
    return 1;
}






int func_021D6A98(u32 sys,u32 unused,u32 arg,char *p)
{
    func_020307B0(((struct Obj01563 *)p)->fFC);
    func_021DD008((char *)((u32 *)p)[13],0);
    func_021E7DF0((int *)(((u32 *)p)[10]));
    func_021E8A78((void *)(((u32 *)p)[15])); func_021E8A78((void *)(((u32 *)p)[14]));
    func_021E8628((char *)(((u32 *)p)[11]));
    if(((u32 *)p)[13]) func_021D9EA0((u8 *)(((u32 *)p)[13]));
    func_021D98B8(p); func_021D9854(p); func_021D97A4(p); func_021D99F4(p);
    WORDSET_DeleteStrbufED04((struct WordSet *)(((u32 *)p)[6])); MSGDATA_Delete((struct Rec *)(((u32 *)p)[5]));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((u32 *)p)[4])); GF_FONT_Delete((void *)(((u32 *)p)[3])); GF_FONT_Delete((void *)(((u32 *)p)[2]));
    func_021E5868(((u32 *)p)[1]); func_021E54E0((char *)(((u32 *)p)[0]));
    func_020315D4((struct S020315D4 *)sys); func_020306F0(87);
    func_02034A5C((int)ov114_id); func_02034A5C((int)ov067_id);
    return 1;
}






int func_021D6B38(unsigned sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2: func_021E8A80(p[14]); if(func_021E8A90((int * *)((u32_021D679C)((int **)p[14])))) *state=3; break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    func_021E5534((u8 *)p[0]); PRINTSYS_QUE_Main((struct PrintSys *)p[4]); func_021E867C((char *)p[11]);
    func_021E7E08(p[10]); func_021E5980(p[1]); func_021D9ED0(p[13]);
    if(p[7]) func_021E64C0((unsigned char *)p[7],(void *)p[4]);
    if(p[8]) func_021E7774((void *)p[8],(void *)p[4]);
    if(p[9]) func_021E84F8((char *)p[9],(void *)p[4]);
    return 0;
}






void func_021D6BF4(u32 sys,void *unused,char *p)
{
    switch (((u32 *)((struct Obj14328 *)p)->f104)[3]) {
    case 0: func_021E8AA0((int *)sys,(int)func_021D6C54); break;
    case 2:
        func_021DA36C((void *)(((struct Obj14328 *)p)->f34));
    case 1:
        func_021D97D0(p);
        func_021E8AA0((int *)sys,(int)func_021D8904);
        break;
    case 3: func_021D97D0(p); func_021E8AA0((int *)sys,(int)func_021D8BC4); break;
    }
}




void func_021D6C54(u32 sys,int *state,u32 *p)
{
    u32 *ctx=(u32 *)p[0x104/4];
    int r;
    switch(*state) {
    case 0:
        if(func_020092EC((const struct Sub02009210Obj *)func_02009448(GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))))) *state=1;
        else *state=5;
        break;
    case 1: func_021E8738((int *)p[0x2c/4],p[5],0x36,2); *state=2; break;
    case 2: MI_CpuFill8((void *)ctx[0xc],0,8); func_021DC738((char *)p[0x34/4],87); *state=3; break;
    case 3:
        r=func_021DC77C((u8 *)p[0x34/4]);
        if(r==1) { func_021DC8A0((const Obj *)((char *)p[0x34/4]), (Pair *)((void *)((u32 *)p[0x104/4])[0xc])); *state=4; }
        else if(r==3) func_021E8AA0((int *)sys,(int)func_021D9064);
        else if(r!=0) {
            r=func_021D9F04((char *)p[0x34/4],(void *)1,0);
            switch(r) {case 1: case 2: func_021E8AA0((int *)sys,(int)func_021D9064); break;}
        }
        break;
    case 4: if(*(unsigned char *)(ctx[0xc]+6)) *state=7; else *state=5; break;
    case 5: func_021E8738((int *)p[0x2c/4],p[5],0x37,1); *state=6; break;
    case 6: if(func_021E8844((const int *)p[0x2c/4])) func_021E8AA0((int *)sys,(int)func_021D905C); break;
    case 7: if(*(u32 *)ctx[8]==0) {func_021DA044((u8 *)p[0x34/4]); *state=8;} break;
    case 8:
        r=func_021DA054((char *)p[0x34/4]);
        if(r==1) { *(u32 *)((u32 *)p[0x104/4])[8]=0x708; *state=9; }
        if(r!=0) {
            r=func_021D9F04((char *)p[0x34/4],(void *)1,0);
            switch(r) {case 1: case 2: func_021E8AA0((int *)sys,(int)func_021D9064); break;}
        }
        break;
    case 9: func_021E8AA0((int *)sys,(int)func_021D6DB8); break;
    }
}



#undef CTX


#undef CTX

#undef CTX
#define CTX (*(u32 **)(p+offset))



/*
 * note: The listing stops at the epilogue label 021D76B8; the full body
 *       ends at 021D76D4 after its epilogue and pools, followed by our
 *       separately matched ov175_func_021D76D4.c.
 * lever: Enum context offset keeps 0x104 in r7; reload aux by literal 0x108.
 *        Distinct Request locals preserve the three eight-byte stack objects.
 *        The masked byte decrement is spelled as addition of 0xfc.
 */
void func_021D6DB8(int *sys,int *state,char *p)
{
    enum { CTX_OFFSET=0x104 } offset=CTX_OFFSET;
    u32 aux=*(u32 *)(p+(offset+4));
    u32 *ctx=CTX;
    int r;
    unsigned char b;
    u32 saved,temp,item;
    void *box;
    Request request1,request7,request40;
    switch(*state) {
    case 0: if(((unsigned char *)ctx[12])[4]==1) *state=1; else *state=3; break;
    case 1: {
        MI_CpuFill8(&request1,0,8); request1.b=0; request1.a=((unsigned char *)CTX[12])[4];
        request1.id=func_021DD020(H); ((unsigned char *)CTX[12])[5]=0;
        func_021DC8B4((u8 *)H, (const W *)&request1, 87); *state=2; break;
    }
    case 2:
        r=func_021DC908(H);
        if(r==1) *state=11; else if(r==3) func_021E8AA0(sys,(int)func_021D9064);
        if(r!=0) switch(func_021D9F04(H,(void *)1,0)) {case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}
        break;
    case 3:
        if(((unsigned char *)CTX[12])[5]==REGULATION_Card_GetValue((struct Reg2 *)aux,10)) *state=4;
        else if(REGULATION_Card_GetValue((struct Reg2 *)aux,10)==4 || REGULATION_Card_GetValue((struct Reg2 *)aux,10)==5) *state=7;
        else *state=4;
        break;
    case 4:
        b=((unsigned char *)ctx[12])[5];
        if(b==3) *state=5; else if((unsigned char)(b+0xfc)<=1) *state=6; else *state=11; break;
    case 5:func_021E8738((int *)W(0x2c),W(0x14),0x39,1);func_021E8AB4((u32)sys,46);*state=56;break;
    case 6:func_021E8738((int *)W(0x2c),W(0x14),0x39,1);func_021E8AB4((u32)sys,46);*state=56;break;
    case 7: {
        MI_CpuFill8(&request7,0,8); request7.b=REGULATION_Card_GetValue((struct Reg2 *)aux,10); request7.id=func_021DD020(H);
        ((unsigned char *)CTX[12])[5]=REGULATION_Card_GetValue((struct Reg2 *)aux,10);
        func_021DC8B4((u8 *)H, (const W *)&request7, 87);*state=8;break;
    }
    case 8:
        r=func_021DC908(H);if(r==1)*state=9;else if(r==3)func_021E8AA0(sys,(int)func_021D9064);
        if(r!=0)switch(func_021D9F04(H,(void *)1,0)){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}break;
    case 9:*state=6;break;
    case 10:
        r=func_021DBDAC(H);if(r==1){*(u32 *)CTX[8]=0x708;*state=6;}
        if(r!=0)switch(func_021D9F04(H,(void *)1,0)){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}break;
    case 11:func_021E8738((int *)W(0x2c),W(0x14),0x5b,2);func_021E8AB4((u32)sys,12);*state=56;break;
    case 12:func_021DC2F4(H,*(u32 *)ctx[12]);*state=13;break;
    case 13:
        r=func_021DC338((u8 *)H);
        if(r==1){func_021DC66C(H,p+0x10c);if(REGULATION_Card_IsCrcValid((struct Reg2 *)(p+0x10c)))*state=14;else *state=15;}
        else if(r==2)*state=15;
        if(r!=0)switch(func_021D9F04(H,(void *)1,0)){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}break;
    case 15:if(REGULATION_Card_GetValue((struct Reg2 *)aux,2)==0)*state=18;else *state=16;break;
    case 16:
        r=func_021D9F04(H,(void *)1,0);
        switch(r){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;case 0:func_021D9A1C(p,func_021D9090);*state=17;break;}break;
    case 17:
        r=func_021D9A30(p);if(r!=0xffff)*state=46;if(r==3)func_021E8AA0(sys,(int)func_021D9064);
        switch(func_021D9F04(H,(void *)1,0)){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}break;
    case 18:func_021E8738((int *)W(0x2c),W(0x14),0x3b,1);func_021E8AB4((u32)sys,55);*state=56;break;
    case 14:
        b=((unsigned char *)ctx[12])[5];if(b==0)*state=19;else if(b==1)*state=53;else if(b==2)*state=54;else *state=55;break;
    case 19:if(REGULATION_Card_GetValue((struct Reg2 *)aux,2)==0)*state=42;else *state=20;break;
    case 20:
        func_021D965C((struct Obj_021D8EC8 *)((struct Obj *)p));
        if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),1))func_021D97E4(p,0);else func_021D97E4(p,1);
        *state=21;break;
    case 21:if(func_021D97B8(p))*state=22;break;
    case 22:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),1))*state=23;else *state=29;break;
    case 23:func_021E8738((int *)W(0x2c),W(0x14),0x3d,1);func_021E8AB4((u32)sys,24);*state=56;break;
    case 24:func_021D98E4((u32_021D98E4 *)p, 0);*state=25;break;
    case 25:r=func_021D9A08(p);if(r!=-1){func_021D99F4(p);switch(r){case 0:*state=35;break;case 1:*state=26;break;}}break;
    case 26:func_021E8738((int *)W(0x2c),W(0x14),0x3e,1);func_021E8AB4((u32)sys,27);*state=56;break;
    case 27:func_021D98E4((u32_021D98E4 *)p, 0);*state=28;break;
    case 28:r=func_021D9A08(p);if(r!=-1){func_021D99F4(p);switch(r){case 0:*state=55;break;case 1:*state=23;break;}}break;
    case 29:func_021E8738((int *)W(0x2c),W(0x14),0x3c,1);func_021E8AB4((u32)sys,30);*state=56;break;
    case 30:func_021D98E4((u32_021D98E4 *)p, 0);*state=31;break;
    case 31:r=func_021D9A08(p);if(r!=-1){func_021D99F4(p);switch(r){case 0:*state=35;break;case 1:*state=32;break;}}break;
    case 32:func_021E8738((int *)W(0x2c),W(0x14),0x3e,1);func_021E8AB4((u32)sys,33);*state=56;break;
    case 33:func_021D98E4((u32_021D98E4 *)p, 0);*state=34;break;
    case 34:r=func_021D9A08(p);if(r!=-1){func_021D99F4(p);switch(r){case 0:*state=55;break;case 1:*state=29;break;}}break;
    case 35:if(func_021D97C4(p))*state=36;break;
    case 36:func_021D97A4(p);*state=42;break;
    case 37:func_021E8738((int *)W(0x2c),W(0x14),0x46,2);func_021E8AB4((u32)sys,38);*state=56;break;
    case 38:if(*(u32 *)ctx[8]==0){MI_CpuFill8((void *)(ctx[13]+0x18),0,0x534);func_021DBC04((u8 *)H,0,(void *)(CTX[13]+0x18));*state=39;}break;
    case 39:
        r=func_021DBDAC(H);if(r==1){*(u32 *)CTX[8]=0x708;*state=40;}
        if(r!=0)switch(func_021D9F04(H,(void *)1,0)){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}break;
    case 40:{
        MI_CpuFill8(&request40,0,8);request40.a=0;request40.b=1;request40.id=func_021DD020(H);
        ((unsigned char *)CTX[12])[5]=1;func_021DC8B4((u8 *)H, (const W *)&request40, 87);*state=41;break;
    }
    case 41:
        r=func_021DC908(H);if(r==1)*state=53;else if(r==3)func_021E8AA0(sys,(int)func_021D9064);
        if(r!=0)switch(func_021D9F04(H,(void *)1,0)){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}break;
    case 42:func_021E8738((int *)W(0x2c),W(0x14),0x3a,2);func_021E8AB4((u32)sys,43);*state=56;break;
    case 43:
        saved=(u32)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]));box=BATTLE_BOX_GetFromSave((void *)saved);
        item=(u32)REGULATION_GetParty((struct RecBig *)BATTLE_COMPETITION_GetFromSave((void *)saved),0);
        MI_CpuCopy8(p+0x10c,(void *)W(0x108),0x160);
        BATTLE_BOX_ClearLockFlags(box,1);REGULATION_Card_SetValue((struct Reg2 *)W(0x108),10,1);
        BSUBWAY_SAVEDATA_SetStat(ctx[4],10,0,0);BSUBWAY_SAVEDATA_SetStat(ctx[4],10,1,0);BSUBWAY_SAVEDATA_SetStat(ctx[4],10,2,0);
        REGULATION_InitParty((struct Rec1E *)item);GAME_DATA_SaveStart(*(u32 *)ctx[2]);*state=44;break;
    case 44:r=GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2]);if(r==2)*state=37;else if(r==3)*state=45;break;
    case 45:func_021E8738((int *)W(0x2c),W(0x14),0x40,1);func_021E8AB4((u32)sys,55);*state=56;break;
    case 46:func_021E8738((int *)W(0x2c),W(0x14),0x5a,2);func_021E8AB4((u32)sys,47);*state=56;break;
    case 47:if(*(u32 *)ctx[8]==0){func_021DB3A4(H,-1,1,ctx[13]);*state=48;}break;
    case 48:
        r=func_021DB478(H);if(r==1){*(u32 *)CTX[8]=0x708;*state=49;}
        if(r!=0)switch(func_021D9F04(H,(void *)1,0)){case 1:case 2:func_021E8AA0(sys,(int)func_021D9064);break;}break;
    case 49:if(((u32 *)CTX[13])[4]!=BSUBWAY_SAVEDATA_GetStat(ctx[4],10,0))*state=50;else *state=55;break;
    case 50:func_021E8738((int *)W(0x2c),W(0x14),0x3a,2);func_021E8AB4((u32)sys,51);*state=56;break;
    case 51:func_021D9D50(p,(void *)ctx[13]);GAME_DATA_SaveStart(*(u32 *)ctx[2]);*state=52;break;
    case 52:if(GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2])==2)*state=55;break;
    case 53:func_021E8AA0(sys,(int)func_021D76D4);break;
    case 54:func_021E8AA0(sys,(int)func_021D7BE4);break;
    case 55:ctx[1]=0;func_021E8AA0(sys,(int)func_021D905C);break;
    case 56:if(func_021E8844((const int *)W(0x2c)))func_021E8AB8((u32)sys);break;
    }
}

#undef W

#define W(k) (*(u32_021D76D4 *)(p+(k)))






void func_021D76D4(u32_021D76D4 sys,int *state,char *p)
{
    u32_021D76D4 *ctx=(u32_021D76D4 *)W(0x104);
    int r,i,n,empty;
    char *rec;
    void *box;
    u32_021D76D4 saved,tmp,out;
    Request_021D76D4 request;
    switch(*state) {
    case 0: func_021D965C((struct Obj_021D8EC8 *)((struct Obj_021D76D4 *)p)); func_021D97E4(p,2); func_021D9874(p); *state=1; break;
    case 1: r=1; r &= func_021D97B8(p); r &= func_021D98CC(p); if(r) *state=2; break;
    case 2: func_021E8738((int *)W(0x2c),W(0x14),0x41,1); func_021E8AB4(sys,3); *state=30; break;
    case 3: func_021D98E4((u32_021D76D4 *)p,2); *state=4; break;
    case 4: r=func_021D9A08(p); if(r!=-1) {func_021D99F4(p); switch(r) {case 0:*state=12;break;case 1:*state=5;break;}} break;
    case 5: func_021E8738((int *)W(0x2c),W(0x14),0x44,1); func_021E8AB4(sys,6); *state=30; break;
    case 6: func_021D98E4((u32_021D76D4 *)p,0); *state=7; break;
    case 7: r=func_021D9A08(p); if(r!=-1) {func_021D99F4(p); switch(r) {case 0:*state=8;break;case 1:*state=2;break;}} break;
    case 8: func_021E8738((int *)W(0x2c),W(0x14),0x45,1); func_021E8AB4(sys,9); *state=30; break;
    case 9: func_021D98E4((u32_021D76D4 *)p,0); *state=10; break;
    case 10: r=func_021D9A08(p); if(r!=-1) {func_021D99F4(p); switch(r) {case 0:*state=11;break;case 1:*state=2;break;}} break;
    case 11: if(func_021D98D8(p)) {func_021D98B8(p); *state=29;} break;
    case 12:
        rec=(char *)ctx[5]; func_021D9A50(rec,p);
        if(POKEPARTY_GetBattleReadyCount(rec+0xd4)==0) *state=14;
        else {out=0; if(POKE_REGULATION_CheckParty((void *)REGULATION_NoOp(W(0x108)),rec+0xd4,&out)==0) *state=15; else *state=13;}
        break;
    case 13: func_021E8738((int *)W(0x2c),W(0x14),0x49,1); func_021E8AB4(sys,29); *state=30; break;
    case 14: func_021E8738((int *)W(0x2c),W(0x14),0x61,1); func_021E8AB4(sys,29); *state=30; break;
    case 15: if(func_021D98D8(p)) {func_021D98B8(p); *state=16;} break;
    case 16: func_021E8738((int *)W(0x2c),W(0x14),0x46,2); func_021E8AB4(sys,17); *state=30; break;
    case 17:
        func_021DCB58((char *)W(0x34),(void *)(ctx[5]+0xd4),1);
        MI_CpuFill8(p+0x44,0,0x9c); *state=18; break;
    case 18:
        r=func_021DCC28((char *)W(0x34),(u8 *)(p+0x44));
        if(r==1) {
            n=POKEPARTY_GetCount((void *)(ctx[5]+0xd4)); empty=0;
            for(i=0;i<n;i++) if(((SlotView *)p)->slots[i]==0) empty++;
            if(((struct Obj00013 *)p)->f44==0 && empty==n) *state=20; else *state=19;
        } else if(r==3) func_021E8AA0((int *)sys,(int)func_021D9064);
        switch(func_021D9F04((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;}
        break;
    case 19: func_021E8738((int *)W(0x2c),W(0x14),0x47,1); func_021E8AB4(sys,29); *state=30; break;
    case 20: if(*(u32_021D76D4 *)ctx[8]==0) {func_021DBC04((u8 *)W(0x34),0,(void *)(ctx[5]+0xd4));*state=21;} break;
    case 21:
        r=func_021DBDAC((char *)W(0x34));
        if(r==1) {*(u32_021D76D4 *)((u32_021D76D4 *)W(0x104))[8]=0x708; *state=22;}
        if(r!=0) switch(func_021D9F04((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;}
        break;
    case 22:
        saved=(u32_021D76D4)GAME_DATA_GetSaveControl((struct Big *)(*(u32_021D76D4 *)ctx[2])); box=BATTLE_BOX_GetFromSave((void *)saved);
        tmp=(u32_021D76D4)REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave((void *)saved),0);
        saved=(u32_021D76D4)func_0200BAF4((int)box,0x8056); BATTLE_BOX_SetLockFlags(box, 1);
        REGULATION_Card_SetValue((struct Reg2 *)W(0x108),10,2); REGULATION_BuildParty(tmp,saved); func_020307B0((void *)saved);
        *state=23; break;
    case 23: GAME_DATA_SaveStart(*(u32_021D76D4 *)ctx[2]); *state=24; break;
    case 24: r=GAME_DATA_SaveMain((unsigned char *)*(u32_021D76D4 *)ctx[2]); if(r==2) *state=25; else if(r==3) *state=29; break;
    case 25:
        MI_CpuFill8(&request,0,8); request.b=2; request.id=func_021DD020((char *)W(0x34));
        ((unsigned char *)((u32_021D76D4 *)W(0x104))[12])[5]=2;
        func_021DC8B4((u8 *)W(0x34),(const W *)&request,87); *state=26; break;
    case 26:
        r=func_021DC908((char *)W(0x34)); if(r==1) *state=27; else if(r==3) func_021E8AA0((int *)sys,(int)func_021D9064);
        switch(func_021D9F04((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;} break;
    case 27: func_021D97E4(p,0); func_021E8738((int *)W(0x2c),W(0x14),0x48,1); func_021E8AB4(sys,28); *state=30; break;
    case 28: func_021E8AA0((int *)sys,(int)func_021D7BE4); break;
    case 29: ctx[1]=0; func_021E8AA0((int *)sys,(int)func_021D8EC8); break;
    case 30: if(func_021E8844((const int *)W(0x2c))) func_021E8AB8(sys); break;
    }
}







void func_021D7BE4(u32_021D7BE4 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00013 *)p)->f104;
    int v;
    switch(*state) {
    case 0:
        switch(func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 0:*state=1;break;
        case 1:case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 1:if(((struct Obj00013 *)p)->f1C==0) {
            func_021D965C((struct Obj_021D8EC8 *)((struct Obj_021D76D4 *)p));func_021D97E4(p,0);*state=2;
        } else *state=3;
        break;
    case 2:if(func_021D97B8(p)) *state=3;break;
    case 3:func_02040588(0,1);
        func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,74,1);
        func_021E8AB4(sys,4);*state=16;break;
    case 4:func_021D98E4((u32_021D76D4 *)((u32_021D7BE4 *)p), 3);*state=5;break;
    case 5:v=func_021D9A08(p);
        if(v!=-1) {
            func_021D99F4(p);
            switch(v) {
            case 0:*state=10;break;
            case 1:*state=7;break;
            case 2:*state=6;break;
            }
        }break;
    case 6:func_021E8AA0((int *)sys,(int)func_021D8E30);break;
    case 7:func_021D9A1C(p,func_021D9344);*state=8;break;
    case 8:v=func_021D9A30(p);
        if(v==1 || v==2) *state=1;
        else if(v==0) *state=9;
        else if(v==3) func_021E8AA0((int *)sys,(int)func_021D9064);
        switch(func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 9:func_021E8AA0((int *)sys,(int)func_021D8EC8);break;
    case 10:func_021D9A50(*(char * *)&((struct Obj24233 *)q)->f14,p);
        func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,24,2);
        func_021E8AB4(sys,11);*state=16;break;
    case 11:func_021D9A1C(p,func_021D95B0);*state=12;break;
    case 12:v=func_021D9A30(p);
        if(v==0) *state=13;
        else if(v==1) *state=13;
        else if(v==3) func_021E8AA0((int *)sys,(int)func_021D9064);
        switch(func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,0)) {
        case 1:func_021E8AA0((int *)sys,(int)func_021D7BE4);break;
        case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 13:func_021E8AA0((int *)sys,(int)func_021D7E18);break;
    case 14:func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,120,1);
        *state=16;func_021E8AB4(sys,15);break;
    case 15:func_021E8AA0((int *)sys,(int)func_021D8EC8);break;
    case 16:if(func_021E8844((const int *)(((struct Obj00013 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}








static inline void TouchParty(u8 *rec, u8 *buf)
{
    int i;

    BUTTON_MAN_ConvertUcs2ToSjis(rec, buf, 8);
    {
        void *p = rec + 0xd4;

        for (i = 0; i < (int)POKEPARTY_GetCount(p); i++)
            POKEPARTY_GetMember(p, i);
    }
}








/*
 * The ov175 link-battle main sequence: one step of a 54-state machine over
 *     *state (0..0x35) on the object in r2, with the frame's sys handle in r0.
 *     The listing cuts it at 0x021D885C, a bl-minted label on its own shared
 *     tail (the timeout and disconnect check); the real extent is
 *     0x021D7E18..0x021D8904, 2796 bytes.
 *
 * The six leaf calls that kept it at MATCH* (0x021E8AB4 x3, 0x021E8AB8,
 *     0x02156F50, 0x02009EC8) resolve since seeds_2 labelled and matched them.
 */
void func_021D7E18(u32_021D7E18 sys, int *state, struct Obj_021D76D4 *obj)
{
    struct Buf16 buf;
    char *rec38;
    u32_021D7E18 mask;
    u32_021D7E18 out;
    u8 b28[8];
    u8 b20[8];
    void *str;
    struct W *w18;
    int flag;
    int fresh;
    int bad;
    int s;
    int res;
    int i;
    int trig = 0;
    u8 *r;
    void *msg;

    w18 = obj->f104;
    flag = 0;
    s = *state;
    if (s >= 0xc && s < 0x1b)
        trig = 1;
    res = func_021D9C34((char *)obj, trig,
                        !((s >= 0x19 && s <= 0x1a) || (s >= 0x11 && s <= 0x12)));
    if (res == 3) {
        *state = 0x28;
        return;
    }

    switch (*state) {
    case 0:
        func_021E8738((int *)obj->f2c, obj->f14, 0x18, 2);
        func_021E8AB4(sys, 1);
        *state = 0x35;
        break;
    case 1:
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        case 0:
            func_021D9A1C((char *)obj, func_021D9090);
            *state = 2;
            break;
        }
        break;
    case 2:
        i = func_021D9A30((char *)obj);
        if (i == 0)
            *state = 4;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            func_021E8AA0((int *)sys, (int)func_021D9064);
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 3:
        func_021E8AA0((int *)sys, (int)func_021D8EC8);
        break;
    case 4:
        if (*obj->f104->f20 == 0) {
            func_021DB3A4(obj->f34, -1, 1, (u32_021D7E18)obj->f104->f34);
            *state = 5;
        }
        break;
    case 5:
        i = func_021DB478(obj->f34);
        if (i == 1) {
            r = w18->f14;
            *obj->f104->f20 = 0;
            func_021D9A9C((char *)r, (char *)obj);
            *obj->f104->f28 = obj->f104->f34->f14;
            if (func_021D9D50((char *)obj, (u32_021D7E18 *)obj->f104->f34) != 0)
                *state = 6;
            else
                *state = 0xa;
        }
        if (i != 0) {
            switch (func_021D9F04(obj->f34, 0, 0)) {
            case 1:
                func_021E8AA0((int *)sys, (int)func_021D7BE4);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 6:
        *state = 7;
        break;
    case 7:
        if (func_021D97C4((char *)obj) != 0) {
            func_021D97A4((char *)obj);
            *state = 8;
        }
        break;
    case 8:
        func_021D965C((struct Obj_021D8EC8 *)obj);
        *state = 9;
        break;
    case 9:
        if (func_021D97B8((char *)obj) != 0)
            *state = 0xa;
        break;
    case 0xa:
        obj->fec = 0;
        func_021E7E0C((void **)obj->f28, 1);
        func_021E8738((int *)obj->f2c, obj->f14, 0x55, 0);
        *state = 0x35;
        func_021E8AB4(sys, 0xb);
        break;
    case 0xb:
        i = obj->f108;
        MI_CpuFill8(&buf, 0, sizeof(buf));
        buf.a = obj->f104->f34->f10;
        buf.b = obj->f104->f34->f04;
        buf.c = REGULATION_Card_GetValue((struct Reg2 *)i, 2);
        buf.d = obj->f104->f34->f08 + obj->f104->f34->f0c;
        func_021DA0D4(obj->f34, 0, 0, w18->f08[1], (int *)(&buf));
        obj->fe4 = 0;
        obj->fe8 = 0;
        *state = 0xc;
        break;
    case 0xc:
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        i = func_021DA1E4(obj->f34);
        if (i == 1)
            *state = 0xd;
        else if (i == 2)
            *state = 0xb;
        break;
    case 0xd:
        if (res == 0) {
            if (func_021DC1A0(obj->f34, (u32_021D7E18)w18->f14) != 0) {
                *state = 0xe;
                obj->ff0 = 0;
            }
        } else {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                obj->fec = 0;
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D8CF0);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0xe:
        if (func_021DC1E4(obj->f34, &rec38) != 0) {
            MI_CpuCopy8(rec38, w18->f18, POKE_REGULATION_GetDataSize() + 0xd4);
            r = w18->f18;
            bad = 0;
            fresh = 1;
            for (i = 0; i < 8; i++) {
                if (((u16 *)r)[i] == STRBUF_GetEosChar())
                    fresh = 0;
            }
            if (fresh) {
                bad++;
                msg = func_02045B38(0, 2, 0xd2, 0x8057);
                str = func_02045EC0(msg, 0x8057);
                STRBUF_ToChars(str, (u16 *)r, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete(msg);
            }
            if (r[0x1d] != 0 && r[0x1d] != 1) {
                r[0x1d] = 0;
                bad++;
            }
            if ((u8)r[0x1c] >= 0x10) {
                r[0x1c] = r[0x1d] == 0 ? 0 : 8;
                bad++;
            }
            if (BMP_OAM_Check5BEC(r[0x18], r[0x19], r[0x1a]) == 0) {
                r[0x18] = 0;
                r[0x19] = 0;
                bad++;
            }
            if (PMSI_PARAM_IsValid((struct T *)(r + 0x38), 0x8057) == 0) {
                PMSI_PARAM_InitSentence(r + 0x38, 1);
                bad++;
            }
            if (bad == 0)
                TRADE_HISTORY_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*w18->f08)));
            *state = 0xf;
        }
        flag = 1;
        break;
    case 0xf:
        TouchParty(w18->f14, b28);
        TouchParty(w18->f18, b20);
        if (((struct Obj24253 *)(w18->f14))->f40 == ((struct Obj24254 *)(w18->f18))->f40
            && ((struct Obj24255 *)(w18->f14))->f50 == ((struct Obj24256 *)(w18->f18))->f50)
            *state = 0x10;
        else
            *state = 0x33;
        break;
    case 0x10:
        mask = 0;
        if (POKE_REGULATION_CheckParty((void *)REGULATION_NoOp(obj->f108), w18->f18 + 0xd4, (u32_021D76D4 *)&mask) == 0) {
            *state = 0x11;
        } else {
            obj->fe4++;
            *state = 0x16;
        }
        break;
    case 0x11:
        if (*obj->f104->f20 == 0) {
            func_021DB3A4(obj->f34, ((struct Obj24260 *)(obj->f104->f18))->f4C, 3, obj->ffc);
            *state = 0x12;
        }
        break;
    case 0x12:
        i = func_021DB478(obj->f34);
        if (i == 1) {
            *obj->f104->f20 = 0xe10;
            *state = 0x13;
        }
        if (i != 0) {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D8CF0);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0x13:
        func_021D9ED4(obj->f34, 0x17);
        *state = 0x14;
        break;
    case 0x14:
        if (func_021D9EEC(obj->f34) != 0)
            *state = 0x15;
        switch (func_021D9F04(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 0x15:
        if (func_021D9BC4(obj->ffc, (u32_021D7E18)(obj->f104->f18 + 0xd4)) == 0)
            obj->fe4++;
        if (func_021D9B2C((char *)obj->f104->f18, obj->f104->f18 + 0xd4, 0x57) == 0)
            obj->fe4++;
        *state = 0x16;
        break;
    case 0x16:
        if (res == 0) {
            if (func_021DC268(obj->f34, (u32_021D7E18)(&obj->fe4)) != 0) {
                *state = 0x17;
                obj->ff0 = 0;
            }
        } else {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                obj->fec = 0;
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D8CF0);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0x17:
        if (func_021DC2A0(obj->f34, (u32_021D7E18)(&obj->fe8)) != 0)
            *state = 0x18;
        else
            flag = 1;
        break;
    case 0x18:
        if (obj->fe8 == 0 && obj->fe4 == 0)
            *state = 0x19;
        else
            *state = 0x33;
        break;
    case 0x19:
        func_021DCA28(obj->f34, (u32_021D7E18)w18->f18, 0x57);
        *state = 0x1a;
        break;
    case 0x1a:
        if (func_021DCAEC(obj->f34, (int *)(&out)) != 0) {
            *obj->f104->f40 = out;
            *state = 0x1b;
        }
        switch (func_021D9F04(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 0x1b:
        if (res == 0) {
            func_021D9ED4(obj->f34, 0x15);
            obj->ff0 = 0;
            *state = 0x1c;
        }
        break;
    case 0x1c:
        if (func_021DA45C(obj->f34) == 0 && func_021D9EEC(obj->f34) != 0)
            *state = 0x1d;
        flag = 1;
        break;
    case 0x1d:
        func_021D9ED4(obj->f34, 0x16);
        *state = 0x1e;
        obj->ff0 = 0;
        break;
    case 0x1e:
        if (func_021D9EEC(obj->f34) != 0)
            *state = 0x1f;
        flag = 1;
        break;
    case 0x1f:
        func_021E7E0C((void **)obj->f28, 0);
        GFL_USE_PlaySeDefaultVolume(0x63a);
        func_021E8738((int *)obj->f2c, obj->f14, 0x57, 1);
        *state = 0x35;
        func_021E8AB4(sys, 0x20);
        obj->fe0 = 0;
        break;
    case 0x20:
        if (obj->fe0++ > 0x78) {
            obj->fe0 = 0;
            func_02040588(0, 0);
            func_021D9804((u32_021D7E18 *)obj, (u32_021D7E18)w18->f18);
            *state = 0x21;
        }
        break;
    case 0x21:
        if (func_021D9868((char *)obj) != 0)
            *state = 0x22;
        break;
    case 0x22:
        if (obj->fe0++ != 0) {
            obj->fe0 = 0;
            *state = 0x23;
        }
        break;
    case 0x23:
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        func_021DA5B0(obj->f34, 0, 0, 0, 0, 0);
        obj->ff4 = 0;
        *state = 0x24;
        obj->ff8 = 0;
        break;
    case 0x24:
        if (obj->ff8 == 0)
            obj->ff8 = func_021DA6B8((char *)obj->f34, (u32_021D9A50 *)(&obj->ff4));
        if (obj->ff8 == 1)
            *state = 0x25;
        if (obj->ff8 != 0) {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
                func_021DA36C(obj->f34);
            case 2:
            case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0x25:
        DWC_RAPCOMMON_DestroySubHeap();
        func_02040588(0, 1);
        func_021E8738((int *)obj->f2c, obj->f14, 0x24, 2);
        *state = 0x35;
        func_021E8AB4(sys, 0x26);
        break;
    case 0x26:
        if (obj->fe0++ > 0x3c) {
            obj->fe0 = 0;
            w18->f04 = 1;
            func_021E8AA8(sys);
        }
        break;
    case 0x27:
        func_021DA36C(obj->f34);
        func_021E7E0C((void **)obj->f28, 0);
        w18->f0c = 2;
        obj->f100 = 1;
        if (obj->ff4 != 0)
            func_021E8AA0((int *)sys, (int)func_021D8904);
        else
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
        break;
    case 0x28:
        func_021E8738((int *)obj->f2c, obj->f14, 0x4e, 1);
        *state = 0x35;
        func_021E8AB4(sys, 0x29);
        break;
    case 0x29:
        func_021D98E4((u32_021D76D4 *)((u32_021D7E18 *)obj), 0);
        *state = 0x2a;
        break;
    case 0x2a:
        i = func_021D9A08((char *)obj);
        if (i != -1) {
            func_021D99F4((char *)obj);
            switch (i) {
            case 0:
                func_021E8AA0((int *)sys, (int)func_021D8FA8);
                break;
            case 1:
                *state = 0x2b;
                break;
            }
        }
        break;
    case 0x2b:
        func_021E8738((int *)obj->f2c, obj->f14, 0x26, 1);
        *state = 0x35;
        func_021E8AB4(sys, 0x2c);
        break;
    case 0x2c:
        func_021D98E4((u32_021D76D4 *)((u32_021D7E18 *)obj), 0);
        *state = 0x2d;
        break;
    case 0x2d:
        i = func_021D9A08((char *)obj);
        if (i != -1) {
            func_021D99F4((char *)obj);
            switch (i) {
            case 0:
                *state = 0x2e;
                break;
            case 1:
                *state = 0x28;
                break;
            }
        }
        break;
    case 0x2e:
        *state = 0x2f;
        break;
    case 0x2f:
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        case 0:
            func_021D9A1C((char *)obj, func_021D9090);
            *state = 0x30;
            break;
        }
        break;
    case 0x30:
        i = func_021D9A30((char *)obj);
        if (i == 0)
            *state = 0xa;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            func_021E8AA0((int *)sys, (int)func_021D9064);
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 0x31:
        if (func_021DA434(obj->f34) != 0)
            *state = 0x32;
        break;
    case 0x32:
        func_021DA36C(obj->f34);
        *state = 0xa;
        break;
    case 0x33:
        func_021DA384(obj->f34);
        *state = 0x34;
        obj->ff0 = 0;
        break;
    case 0x34:
        flag = 1;
        if (func_021DA390(obj->f34) != 0)
            *state = 0xb;
        break;
    case 0x35:
        if (func_021E8844((const int *)obj->f2c) != 0)
            func_021E8AB8(sys);
        break;
    }

    if (flag) {
        i = 0;
        if (obj->ff0++ > 0x4b0) {
            obj->ff0 = 0;
            i = 1;
        }
        if (func_021DA45C(obj->f34) != 0)
            i = 1;
        if (i) {
            func_021DA36C(obj->f34);
            if (func_0200FB24() == 0 && GFL_NET_GetRunState() != 0)
                DWC_CloseAllConnectionsHard();
            *state = 0xa;
        }
        switch (func_021D9F04(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
    }
}







void func_021D8904(u32_021D8904 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00477 *)p)->f104;
    Rec84_021D76D4 rec;
    void *list;
    int v;
    switch(*state) {
    case 0:if(((struct Obj02512 *)q)->fC==2 && ((struct Obj00477 *)p)->f100==0) func_021E8AA0((int *)sys,(int)func_021D8BC4);
        else {
            ((struct Obj00477 *)p)->f100=0;
            GFL_HEAP_CreateChildHeap(1,134,0x60000);
            DWC_RAPCOMMON_CreateSubHeap(9,0x60000,1000,134);
            DWC_RAPCOMMON_SetHeapTag(134);*state=1;
        }break;
    case 1:func_021E8738((int *)(((struct Obj00477 *)p)->f2C),((struct Obj00477 *)p)->f14,70,2);
        *state=13;func_021E8AB4(sys,2);break;
    case 2:func_021DA5B0((char *)(*(char * *)&((struct Obj00477 *)p)->f34), 1, 0, (*(u32_021D8904 **)(q+8))[1], (u32_021D9A50 *)(*(u32_021D8904 * *)&((struct Obj02512 *)q)->f2C), ((struct Obj02512 *)q)->fC==2);
        ((struct Obj00477 *)p)->fF8=0;((struct Obj00477 *)p)->fF4=0;*state=3;break;
    case 3:
        if(((struct Obj00477 *)p)->fF8==0) {
            ((struct Obj00477 *)p)->fF8=func_021DA6B8((char *)(((struct Obj00477 *)p)->f34), (u32_021D9A50 *)((u32_021D8904 *)(p+244)));
            if(((struct Obj00477 *)p)->fF8!=0 && ((struct Obj00477 *)p)->fF4!=0)
                func_021E8AC0(**(int * *)&((struct Obj02512 *)q)->f8,**(int * *)&((struct Obj02512 *)q)->f2C);
        }
        if(((struct Obj00477 *)p)->fF8==1) {
            ((struct Obj24270 *)(*(char * *)&((struct Obj02512 *)q)->f2C))->f14=func_021DADAC((u8 *)(*(char * *)&((struct Obj00477 *)p)->f34));*state=4;
        }
        if(((struct Obj00477 *)p)->fF8!=0) {
            switch(func_021D9F04(*(char * *)&((struct Obj00477 *)p)->f34,0,(void *)1)) {
            case 1:func_021DA36C(*(char * *)&((struct Obj00477 *)p)->f34);
            case 2:case 4:func_021E8AA0((int *)sys,(int)func_021D9064);DWC_RAPCOMMON_DestroySubHeap();break;
            }
        }break;
    case 4:DWC_RAPCOMMON_DestroySubHeap();
        if(((struct Obj02512 *)q)->fC==2)func_021E8AA0((int *)sys,(int)func_021D8BC4);
        else *state=5;break;
    case 5:list=MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj02512 *)q)->f8));
        MISC_SAVEDATA_InsertRecentValue(list,func_02008530(((struct Obj02512 *)q)->f18));
        func_021DA384(*(char * *)&((struct Obj00477 *)p)->f34);*state=6;break;
    case 6:if(func_021DA390(*(char * *)&((struct Obj00477 *)p)->f34)) *state=7;
        switch(func_021D9F04(*(char * *)&((struct Obj00477 *)p)->f34,0,(void *)1)) {
        case 1:case 4:*state=7;break;
        case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 7:if(**(u32_021D8904 * *)&((struct Obj02512 *)q)->f20==0) {
        MI_CpuFill8(&rec,0,84);
        rec.data=**(Rec80_021D76D4 * *)&((struct Obj24273 *)(*(char * *)&((struct Obj00477 *)p)->f104))->f24;
        rec.last=**(u32_021D8904 * *)&((struct Obj24274 *)(*(char * *)&((struct Obj00477 *)p)->f104))->f28;
        func_021DBC04((u8 *)(*(char * *)&((struct Obj00477 *)p)->f34),3,(struct Record *)(&rec));*state=8;
        }break;
    case 8:v=func_021DBDAC(*(char * *)&((struct Obj00477 *)p)->f34);
        if(v==1) {
            **(u32_021D8904 * *)&((struct Obj24276 *)(*(char * *)&((struct Obj00477 *)p)->f104))->f20=1800;*state=9;
        }
        if(v!=0) {
            switch(func_021D9F04(*(char * *)&((struct Obj00477 *)p)->f34,0,0)) {
            case 1:func_021E8AA0((int *)sys,(int)func_021D8CF0);break;
            case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
            }
        }break;
    case 9:func_021E8738((int *)(((struct Obj00477 *)p)->f2C),((struct Obj00477 *)p)->f14,88,1);
        *state=13;func_021E8AB4(sys,10);break;
    case 10:((struct Obj02512 *)q)->f4=2;func_021E8AA8(sys);break;
    case 13:if(func_021E8844((const int *)(((struct Obj00477 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}







void func_021D8BC4(int *a, int *state, char *ctx)
{
    int r;
    u32_021D8BC4 q;
    char *sub = *(char **)(ctx + 0x104);
    switch (*state) {
    case 0:
        func_021E8738(*(int **)(ctx + 0x2C), *(int *)(ctx + 0x14), 0x28, 2);
        *state = 5;
        func_021E8AB4((unsigned)a, 1);
        return;
    case 1:
        func_021D9D50(ctx, *(void **)(sub + 0x34));
        GAME_DATA_SaveStart(**(int **)(sub + 8));
        *state = 2;
        return;
    case 2:
        r = GAME_DATA_SaveMain(**(u8 ***)(sub + 8));
        if (r == 2) {
            *state = 3;
            return;
        }
        if (r == 3)
            func_021E8AA0(a, (int)func_021D8EC8);
        return;
    case 3:
        switch (func_021D9F04(*(char **)(ctx + 0x34), 0, 0)) {
        case 1:
            func_021E8AA0(a, (int)func_021D8CF0);
            return;
        case 2:
            func_021E8AA0(a, (int)func_021D9064);
            return;
        case 0:
            func_021D9A1C(ctx, (void *)func_021D9090);
            *state = 4;
            return;
        }
        return;
    case 4:
        q = func_021D9A30(ctx);
        if (q == 0)
            func_021E8AA0(a, (int)func_021D8CF0);
        else if (q - 1 <= 1)
            func_021E8AA0(a, (int)func_021D8EC8);
        else if (q == 3)
            func_021E8AA0(a, (int)func_021D9064);
        switch (func_021D9F04(*(char **)(ctx + 0x34), 0, 0)) {
        case 1:
            func_021E8AA0(a, (int)func_021D8CF0);
            return;
        case 2:
            func_021E8AA0(a, (int)func_021D9064);
            return;
        }
        return;
    case 5:
        if (func_021E8844(*(int **)(ctx + 0x2C)))
            func_021E8AB8((unsigned)a);
        return;
    }
}







/*
 * Lever: the two-value tail dispatch is a switch; if (v==1 || v==2) folds into a range and compiles 316/320 bytes.
 */
void func_021D8CF0(u32_021D8CF0 sys,int *state,char *p)
{
    int v;
    switch(*state) {
    case 0:
        switch(func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,(void *)1)) {
        case 0:case 1:case 4:*state=1;break;
        case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 1:func_02040588(0,1);
        func_021E8738((int *)(((struct Obj00013 *)p)->f2C),((struct Obj00013 *)p)->f14,92,1);
        *state=7;func_021E8AB4(sys,2);break;
    case 2:func_021D98E4((u32_021D76D4 *)((u32_021D8CF0 *)p), 4);*state=3;break;
    case 3:v=func_021D9A08(p);
        if(v!=-1) {
            func_021D99F4(p);
            switch(v) {
            case 0:func_021E8AA0((int *)sys,(int)func_021D7E18);break;
            case 1:*state=4;break;
            case 2:func_021E8AA0((int *)sys,(int)func_021D8E30);break;
            }
        }break;
    case 4:func_021D9A1C(p,func_021D9344);*state=5;break;
    case 5:v=func_021D9A30(p);
        if(v==1 || v==2) *state=1;
        else if(v==0) *state=6;
        v=func_021D9F04(*(char * *)&((struct Obj00013 *)p)->f34,0,0);
        switch(v) {
        case 1:case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }
        break;
    case 6:func_021E8AA0((int *)sys,(int)func_021D8EC8);break;
    case 7:if(func_021E8844((const int *)(((struct Obj00013 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}







void func_021D8E30(u32_021D8E30 sys, int *state, char *ctx)
{
    int result;
    switch (*state) {
    case 0:
        func_021E8738((int *)(((struct Obj00013 *)ctx)->f2C), ((struct Obj00013 *)ctx)->f14, 0x4e, 1);
        *state = 3;
        func_021E8AB4(sys, 1);
        break;
    case 1:
        func_021D98E4((u32_021D76D4 *)((u32_021D8E30 *)ctx), 0);
        *state = 2;
        break;
    case 2:
        result = func_021D9A08(ctx);
        if (result != -1) {
            func_021D99F4(ctx);
            switch (result) {
            case 0: func_021E8AA0((int *)sys, (int)func_021D8FA8); break;
            case 1: func_021E8AA0((int *)sys, (int)func_021D8CF0); break;
            }
        }
        break;
    case 3:
        if (func_021E8844((const int *)(((struct Obj00013 *)ctx)->f2C))) func_021E8AB8(sys);
        break;
    }
}






void func_021D8EC8(u32_021D8EC8 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj02886 *)p)->f104;
    switch(*state) {
    case 0:func_021E8738((int *)(((struct Obj02886 *)p)->f2C),((struct Obj02886 *)p)->f14,40,2);
        func_021E8AB4(sys,1);*state=7;break;
    case 1:GAME_DATA_SaveStart((int)(**(void ** *)&((struct Obj10683 *)q)->f8));*state=2;break;
    case 2:if(GAME_DATA_SaveMain(**(void ** *)&((struct Obj10683 *)q)->f8)==2) *state=3;break;
    case 3:func_021E8738((int *)(((struct Obj02886 *)p)->f2C),((struct Obj02886 *)p)->f14,37,2);
        func_021E8AB4(sys,4);*state=7;break;
    case 4:if(**(u32_021D8EC8 * *)&((struct Obj10683 *)q)->f20==0) {func_021DBC04(((struct Obj02886 *)p)->f34,2,0);*state=5;}break;
    case 5:if(func_021DBDAC(((struct Obj02886 *)p)->f34)) {
        **(u32_021D8EC8 * *)&((struct Obj24281 *)(*(char * *)&((struct Obj02886 *)p)->f104))->f20=1800;*state=6;
        func_021D9F04(*(char * *)&((struct Obj02886 *)p)->f34,(void *)1,0);
    }break;
    case 6:func_021E8AA0((int *)sys,(int)func_021D905C);break;
    case 7:if(func_021E8844((const int *)(((struct Obj02886 *)p)->f2C))) func_021E8AB8(sys);break;
    }
}






/*
 * follower: 021D905C tail-call stub included; function_starts seed 021D905C.
 */
void func_021D8FA8(u32_021D8FA8 sys, int *state, char *ctx)
{
    int result;
    switch (*state) {
    case 0:
        result = func_021D9F04(((struct Obj00013 *)ctx)->f34, (void *)1, 0);
        switch (result) {
        case 1: case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        case 0:
            func_021D9A1C(ctx, func_021D9090);
            *state = 1;
            break;
        }
        break;
    case 1:
        result = func_021D9A30(ctx);
        if (result != 0xffff) *state = 2;
        if (result == 3) func_021E8AA0((int *)sys, (int)func_021D9064);
        result = func_021D9F04(((struct Obj00013 *)ctx)->f34, (void *)1, 0);
        switch (result) {
        case 1: case 2: func_021E8AA0((int *)sys, (int)func_021D9064); break;
        }
        break;
    case 2: func_021E8AA0((int *)sys, (int)func_021D8EC8); break;
    case 3:
        if (func_021E8844((const int *)(((struct Obj00013 *)ctx)->f2C))) func_021E8AB8(sys);
        break;
    }
}






void func_021D905C(u32_021D8FA8 sys)
{
    func_021E8AA8(sys);
}






void func_021D9064(void *obj,int unused,u8 *p) { ((struct Obj24283 *)(*(u8 * *)&((struct Obj08276 *)p)->f104))->f4=3; if(((struct Obj08276 *)p)->f34) { func_021D9EA0(((struct Obj08276 *)p)->f34); *(u32_021D9064 *)&((struct Obj08276 *)p)->f34=0; } func_0200FBB0(); func_021E8AA8((int)obj); }






/*
 * Lever: byte range test uses (u8)(value + 255), preserving adds #255.
 * Extent: final 021D9342..021D9344 is zero alignment padding.
 */
void func_021D9090(u32_021D9090 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj00728 *)p)->f104;
    struct RTCDate startDate;
    struct RTCDate endDate;
    struct RTCDate nowDate;
    struct RTCTime nowTime;
    struct Request_021D8EC8 req;
    struct Reg2 *reg;
    struct Obj_021D8EC8 *box;
    int got;
    int startDay,endDay,nowDay,v;
    switch(*state) {
    case 0:*state=1;break;
    case 1:reg=*(struct Reg2 * *)&((struct Obj00728 *)p)->f108;
        if(!GFL_NET_GetRunState())func_0200FA84();
        got=func_02167ED8((int *)&nowDate,(int *)&nowTime);
        if(got)RTC_ConvertSecondToDateTime(&nowDate,&nowTime,RTC_ConvertDateTimeToSecond(&nowDate,&nowTime));
        startDate.year=REGULATION_Card_GetValue(reg,4);
        startDate.month=REGULATION_Card_GetValue(reg,5);
        startDate.day=REGULATION_Card_GetValue(reg,6);startDate.week=0;
        endDate.year=REGULATION_Card_GetValue(reg,7);
        endDate.month=REGULATION_Card_GetValue(reg,8);
        endDate.day=REGULATION_Card_GetValue(reg,9);endDate.week=0;
        startDay=RTC_ConvertDateToDay(&startDate);
        endDay=RTC_ConvertDateToDay(&endDate);
        nowDay=RTC_ConvertDateToDay(&nowDate);
        if(got && nowDay<startDay) {((struct Obj00728 *)p)->f40=2;*state=2;}
        else if(got && startDay<=nowDay && nowDay<=endDay) {((struct Obj00728 *)p)->f40=0;*state=13;}
        else {((struct Obj00728 *)p)->f40=1;*state=3;}
        break;
    case 2:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,96,1);
        *state=14;func_021E8AB4(sys,13);break;
    case 3:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,80,1);
        *state=14;func_021E8AB4(sys,4);break;
    case 4:if((u8)((*(u8 **)(q+48))[5]+255)<=1) *state=5;
        else *state=13;break;
    case 5:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,40,2);
        *state=14;func_021E8AB4(sys,6);break;
    case 6:box=BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj08277 *)q)->f8));
        ((struct Obj00728 *)p)->f26C=BATTLE_BOX_IsLocked(box, 1);
        BATTLE_BOX_ClearLockFlags(box, 1);
        REGULATION_Card_SetValue(*(struct Reg2 * *)&((struct Obj00728 *)p)->f108,10,3);
        GAME_DATA_SaveStart(**(int * *)&((struct Obj08277 *)q)->f8);*state=7;break;
    case 7:if(GAME_DATA_SaveMain(**(void ** *)&((struct Obj08277 *)q)->f8)==2) *state=8;break;
    case 8:BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj08277 *)q)->f8));
        if(((struct Obj00728 *)p)->f26C!=0) *state=9;else *state=10;break;
    case 9:func_021D97E4(p,1);
        func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,81,1);
        *state=14;func_021E8AB4(sys,10);break;
    case 10:func_021E8738((int *)(((struct Obj00728 *)p)->f2C),((struct Obj00728 *)p)->f14,70,2);
        *state=14;func_021E8AB4(sys,11);break;
    case 11:MI_CpuFill8(&req,0,8);req.b=3;
        req.id=func_021DD020(*(char * *)&((struct Obj00728 *)p)->f34);
        (*(u8 **)(*(char * *)&((struct Obj00728 *)p)->f104+48))[5]=3;
        func_021DC8B4(*(u8 * *)&((struct Obj00728 *)p)->f34,(const W *)&req,87);*state=12;break;
    case 12:v=func_021DC908(*(char * *)&((struct Obj00728 *)p)->f34);
        if(v==1) *state=13;
        else if(v==3) {((struct Obj00728 *)p)->f40=3;*state=13;}
        break;
    case 13:func_021E8AA8(sys);break;
    case 14:if(func_021E8844((const int *)(((struct Obj00728 *)p)->f2C)))func_021E8AB8(sys);break;
    }
}






void func_021D9344(u32_021D9344 sys,int *state,char *p) {
    char *ctx=*(char * *)&((struct Obj00781 *)p)->f104;
    int r;
    Request_021D8EC8 request;
    switch(*state) {
    case 0:
        r=((struct Obj24288 *)(*(char * *)&((struct Obj08278 *)ctx)->f30))->f5;
        if((u8)(r+255)<=1) { ((struct Obj00781 *)p)->f40=1; *state=2; }
        else { ((struct Obj00781 *)p)->f40=2; *state=1; }
        break;
    case 1:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,82,1);
        *state=16; func_021E8AB4(sys,15); break;
    case 2:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,83,1);
        *state=16; func_021E8AB4(sys,3); break;
    case 3: func_021D98E4((u32_021D9344 *)p,5); *state=4; break;
    case 4:
        r=func_021D9A08(p);
        if(r!=-1) { func_021D99F4(p); switch(r) { case 0:*state=5;break; case 1:*state=15;break; } }
        break;
    case 5:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,84,1);
        *state=16; func_021E8AB4(sys,6); break;
    case 6: func_021D98E4((u32_021D9344 *)p,5); *state=7; break;
    case 7:
        r=func_021D9A08(p);
        if(r!=-1) { func_021D99F4(p); switch(r) { case 0:*state=8;break; case 1:*state=15;break; } }
        break;
    case 8:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,40,2);
        *state=16; func_021E8AB4(sys,9); break;
    case 9:
        BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(struct Big ** *)&((struct Obj08278 *)ctx)->f8)), 1);
        REGULATION_Card_SetValue((struct Reg2 *)(((struct Obj00781 *)p)->f108),10,4);
        GAME_DATA_SaveStart(**(int * *)&((struct Obj08278 *)ctx)->f8); *state=10; break;
    case 10:
        r=GAME_DATA_SaveMain(**(u8 ** *)&((struct Obj08278 *)ctx)->f8);
        if(r==2) { ((struct Obj00781 *)p)->f40=0; *state=11; }
        else if(r==3) *state=15;
        break;
    case 11:
        func_021D97E4(p,1);
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,81,1);
        *state=16; func_021E8AB4(sys,12); break;
    case 12:
        func_021E8738(*(int * *)&((struct Obj00781 *)p)->f2C,((struct Obj00781 *)p)->f14,70,2);
        *state=16; func_021E8AB4(sys,13); break;
    case 13:
        MI_CpuFill8(&request,0,8); request.b=4;
        request.id=func_021DD020(*(char * *)&((struct Obj00781 *)p)->f34);
        ((struct Obj24293 *)(*(char * *)&((struct Obj24292 *)(*(char * *)&((struct Obj00781 *)p)->f104))->f30))->f5=4;
        func_021DC8B4(*(u8 * *)&((struct Obj00781 *)p)->f34,(const W *)&request,87); *state=14; break;
    case 14:
        r=func_021DC908(*(char * *)&((struct Obj00781 *)p)->f34);
        if(r==1) *state=15;
        else if(r==3) { ((struct Obj00781 *)p)->f40=3; *state=15; }
        break;
    case 15: func_021E8AA8(sys); break;
    case 16: if(func_021E8844(*(int * *)&((struct Obj00781 *)p)->f2C)) func_021E8AB8(sys); break;
    }
}






void func_021D95B0(u32_021D95B0 sys, int *state, char *ctx)
{
    char *save;
    int result;
    save = *(char * *)&((struct Obj24294 *)(*(char * *)&((struct Obj03868 *)ctx)->f104))->f14;
    switch (*state) {
    case 0: *state = 1; break;
    case 1:
        MI_CpuFill8(ctx + 0x44, 0, 0x9c);
        func_021DCB58(((struct Obj03868 *)ctx)->f34, save + 0xd4, 1);
        *state = 2;
        break;
    case 2:
        result = func_021DCC28(((struct Obj03868 *)ctx)->f34, (u8 *)(ctx + 0x44));
        if (result == 1) *state = 3;
        else if (result == 2) { ((struct Obj03868 *)ctx)->f40 = 2; *state = 4; }
        else if (result == 3) { ((struct Obj03868 *)ctx)->f40 = 3; *state = 4; }
        break;
    case 3:
        if (((struct Obj03868 *)ctx)->f44 == 0) {
            func_021D9B18(save, ctx + 0x44);
            ((struct Obj03868 *)ctx)->f40 = 0;
            *state = 4;
        } else {
            ((struct Obj03868 *)ctx)->f40 = 1;
            *state = 4;
        }
        break;
    case 4: func_021E8AA8(sys); break;
    }
}







/*
 * Opens the +0x1c profile exchange when none is open: builds a 0xac-byte
 *     profile (0x92 bytes copied from the +0x108 block, three packed byte
 *     triples, the play-time words from the +0x104 save), then hands it to
 *     0x021E5D68 with the +0x04..+0x18 words.
 *
 * The three calls to 0x0200DFD8 resolve since seeds_2 labelled and matched
 *     it (src/matched/unit_0200DFD8.c).
 */
void func_021D965C(struct Obj_021D8EC8 *obj)
{
    struct Profile prof;
    u32_021D965C sys;
    u32_021D965C id;
    u32_021D965C kind;
    u32_021D965C a;
    u32_021D965C b;
    u32_021D965C data;
    u32_021D965C c;

    if (obj->f1c == 0) {
        data = obj->f108;
        sys = (u32_021D965C)func_02012944((void *)(*obj->f104->f08));
        id = func_021E5548((int *)obj->f00);
        kind = (u32_021D965C)REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*obj->f104->f08))), 0);
        MI_CpuFill8(&prof, 0, sizeof(prof));
        MI_CpuCopy8(REGULATION_Card_GetCupName((struct Reg2 *)data), &prof, 0x92);
        a = REGULATION_Card_GetValue((struct Reg2 *)data, 6);
        b = REGULATION_Card_GetValue((struct Reg2 *)data, 5);
        c = REGULATION_Card_GetValue((struct Reg2 *)data, 4);
        prof.f94 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        a = REGULATION_Card_GetValue((struct Reg2 *)data, 9);
        b = REGULATION_Card_GetValue((struct Reg2 *)data, 8);
        c = REGULATION_Card_GetValue((struct Reg2 *)data, 7);
        prof.f98 = (c << 24) | ((b << 24) >> 8) | ((a << 24) >> 16);
        prof.f9c = func_02008554((const struct Sub0200852CObj *)sys);
        prof.fa0 = BSUBWAY_SAVEDATA_GetStat(obj->f104->f10, 10, 0);
        a = BSUBWAY_SAVEDATA_GetStat(obj->f104->f10, 10, 1);
        prof.fa4 = a + BSUBWAY_SAVEDATA_GetStat(obj->f104->f10, 10, 2);
        prof.faa = REGULATION_Card_GetValue((struct Reg2 *)data, 11);
        if (prof.fa4 == 0 && prof.fa0 == 0)
            prof.fa0 = 1500;
        obj->f1c = (u32_021D965C)func_021E5D68((char *)(&prof), 0, (void *)sys, (void *)id, (void *)obj->f04, obj->f08, (void *)obj->f10, (void *)obj->f14, (void *)obj->f18, (void *)kind, 0, 0x57);
    }
}







/*
 * Release path for the +0x1c block pointer, freed through 0x021E5EF8
 *     and cleared; a second call is a no-op.  The callee address is shared by
 *     two overlays, so the symbols: line carries the ov177 hint that the
 *     image's call to it there fixes.
 */
void func_021D97A4(char *obj)
{
    u32_021D97A4 p = ((struct Obj00013 *)obj)->f1C;

    if (p != 0) {
        POKETRADE_2D_DeleteMarkingIcon((void *)p);
        ((struct Obj00013 *)obj)->f1C = 0;
    }
}







u32_021D97B8 func_021D97B8(char *obj)
{
    return func_021E64C8(((struct Obj24302 *)obj)->f1C);
}







/*
 * Thunk: hands the +0x1c block to 0x021E65FC (ov177) and returns its result.
 */
int func_021D97C4(char *obj)
{
    return func_021E65FC(((struct Obj24303 *)obj)->f1C);
}







/*
 * Start-op for the ov175 object's +0x1c stream: func_021D965C, then spin
 *     on func_021D97B8 until it reports ready.  Mirrors func_021D63C8.
 */
void func_021D97D0(char *obj)
{
    func_021D965C((struct Obj_021D8EC8 *)obj);
    while (func_021D97B8(obj) == 0)
        ;
}







/*
 * If the +0x1c block is live, forward it to 0x021E5F24 together with the
 *     function's own second argument, the +0x14 and +0x10 words and the +8
 *     word, plus the literal 0x57.  Six arguments, so the last two ride on the
 *     stack; the two-word frame exists only for them.
 */
void func_021D97E4(char *obj, u32_021D97E4 arg)
{
    if (((struct Obj00013 *)obj)->f1C != 0)
        func_021E5F24(((struct Obj00013 *)obj)->f1C, arg, ((struct Obj00013 *)obj)->f14,
                      ((struct Obj00013 *)obj)->f10, ((struct Obj00013 *)obj)->f8, 0x57);
}






/*
 * Lazy create: when the handle at +0x20 is empty, builds it through the eleven-argument ov177 constructor from the +0x0/+0x4/+0x8/+0x10/+0x14/+0x18 words and the heap id at +0x108.
 */
void func_021D9804(u32_021D9804 *obj, u32_021D9804 arg)
{
    if (obj[8] == 0) {
        u32_021D9804 base = func_021E5548((int *)obj[0]);
        obj[8] = func_021E7520(arg, base, obj[1], obj[2], obj[4], obj[5], obj[6], 0, 1,
                               REGULATION_Card_GetValue((struct Reg2 *)obj[0x42], 0xb), 0x57);
    }
}






/*
 * Release path for the ov175 object's 0x20 pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void func_021D9854(char *obj)
{
    u32_021D9854 p = ((struct Obj14329 *)obj)->f20;

    if (p != 0) {
        func_021E7710(p);
        ((struct Obj14329 *)obj)->f20 = 0;
    }
}






/*
 * Thunk: hands the +0x20 block to 0x021E777C (ov177) and returns its result.
 */
u32_021D9868 func_021D9868(char *obj)
{
    return func_021E777C((void *)(((struct Obj24304 *)obj)->f20));
}





/*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 */
void func_021D9874(char *ctx)
{
    int window;
    if (((struct Obj00013 *)ctx)->f24 == 0) {
        window = func_021E5548(*(int * *)&((struct Obj00013 *)ctx)->f0);
        ((struct Obj00013 *)ctx)->f24 = func_021E7E3C(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj24305 *)(*(char * *)&((struct Obj00013 *)ctx)->f104))->f8)), window, *(int *)&((struct Obj00013 *)ctx)->f4, ((struct Obj00013 *)ctx)->fC, *(int *)&((struct Obj00013 *)ctx)->f10, *(int *)&((struct Obj00013 *)ctx)->f14, 87);
    }
}






/*
 * Free-and-null on the +0x24 block: hands it to 0x021E82BC (ov177) and
 *  *  clears the field, so a second call is harmless.
 */
void func_021D98B8(char *obj)
{
    u32_021D98B8 p = ((struct Obj14330 *)obj)->f24;
    if (p != 0) {
        func_021E82BC((char *)p);
        ((struct Obj14330 *)obj)->f24 = 0;
    }
}





int func_021D98CC(char *p)
{
    return func_021E8338(*(Work * *)&((struct Obj24307 *)p)->f24);
}





int func_021D98D8(char *p)
{
    return func_021E8420(*(Work * *)&((struct Obj24308 *)p)->f24);
}





void func_021D98E4(u32_021D98E4 *p, int mode) {
    Desc_021D76D4 d;
    if (p[12] == 0) {
        MI_CpuFill8(&d, 0, 48);
        d.x0=p[5]; d.x1=p[2]; d.x2=p[4];
        d.a=0; d.b=15; d.c=13; d.d=1;
        switch (mode) {
        case 5: d.pad=1;
        case 0:
            d.x3=52; d.x4=53; d.x7=2; d.enabled=1; d.kind=1;
            p[12]=func_021E888C(&d,87); break;
        case 1:
            d.x3=47; d.x4=48; d.x5=49; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E888C(&d,87); break;
        case 2:
            d.x3=66; d.x4=67; d.x7=2; d.enabled=1; d.kind=1;
            p[12]=func_021E888C(&d,87); break;
        case 3:
            d.x3=75; d.x4=76; d.x5=77; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E88B0(&d,3,6,26,6,87); break;
        case 4:
            d.x3=93; d.x4=94; d.x5=95; d.x7=3; d.enabled=1; d.kind=2;
            p[12]=func_021E88B0(&d,3,6,26,6,87); break;
        }
    }
}






void func_021D99F4(char *obj)
{
    u32_021D99F4 p = ((struct Obj00013 *)obj)->f30;

    if (p != 0) {
        func_021E89D0(p);
        ((struct Obj00013 *)obj)->f30 = 0;
    }
}






/*
 * Field query: if the +0x30 pointer is live, hand it to the ov175-adjacent
 *     routine at 0x021E8A00 and return its result, else -1.  func_021D99F4 is
 *     the matching free path for the same field.
 */
int func_021D9A08(char *obj)
{
    u32_021D9A08 p = ((struct Obj24309 *)obj)->f30;

    if (p != 0)
        return func_021E8A00(p);
    return -1;
}






void func_021D9A1C(char *obj, void *fn)
{
    func_021E8AA0((int *)(((struct Obj00013 *)obj)->f3C), (int)fn);
    ((struct Obj00013 *)obj)->f40 = 0xFFFF;
}






/*
 * Reads back the +0x3c stream: 0x021E8A80 for pending data, 0x021E8A90
 *     for a byte read, returning the +0x40 word or the 0xFFFF sentinel.
 *     Mirrors func_021D679C.
 */
u32_021D9A30 func_021D9A30(char *obj)
{
    func_021E8A80(((struct Obj00013 *)obj)->f3C);
    if (func_021E8A90((int **)(((struct Obj00013 *)obj)->f3C)) != 0)
        return ((struct Obj00013 *)obj)->f40;
    return 0xFFFF;
}






/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * Identical blocker to func_021D679C: the call at +0x0C targets 0x021E8A90,
 * which is not a traced function label in any overlay listing.
 */



void func_021D9A50(char *dest, char *ctx)
{
    void *records;
    MI_CpuFill8(dest, 0, 212);
    records = func_0200BAF4((int)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct Obj24311 *)(*(char * *)&((struct Obj00013 *)ctx)->f104))->f8)), 87);
    MI_CpuCopy8(records, dest + 212, POKE_REGULATION_GetDataSize(POKEPARTY_Init(dest + 212)));
    func_020307B0(records);
    ((struct Obj24310 *)dest)->f44 = 100;
}






/*
 * Fills a profile record from the save data reached through +0x104: name, a 0x38 record, three words of the +0x34 block, the +0x34 id, a derived word and two values of the +0x108 block.
 *
 *     (MI_CpuCopy8 with size 0x20) with no witness. Seed and match it and this
 *     file is EXACT.
 */
void func_021D9A9C(char *dst, char *obj)
{
    u32_021D9A9C st = (u32_021D9A9C)GAME_DATA_GetSaveControl((struct Big *)(*(*(struct Save_021D9A50 * *)&((struct Obj00013 *)obj)->f104)->sav));
    u32_021D9A9C h;

    MYSTATUS_Copy(func_02012944((void *)(*(*(struct Save_021D9A50 * *)&((struct Obj00013 *)obj)->f104)->sav)), dst);
    MISC_SAVEDATA_CopyQuadRecord(func_0200E6E8(st), 0, (struct Rec0200E6FC *)(dst + 0x38));
    {
        const struct Save_021D9A50 *s = *(struct Save_021D9A50 * *)&((struct Obj00013 *)obj)->f104;
        ((struct Obj01067 *)dst)->f28 = s->blk[2];
        ((struct Obj01067 *)dst)->f2C = s->blk[3];
        ((struct Obj01067 *)dst)->f34 = s->blk[4];
    }
    ((struct Obj01067 *)dst)->f4C = func_021DC194((char *)(*(u32_021D9A9C *)&((struct Obj00013 *)obj)->f34));
    ((struct Obj01067 *)dst)->f48 = WIFILIST_GetGsProfileId((void *)GAME_DATA_GetField1A0((const struct BigObj *)(*(*(struct Save_021D9A50 * *)&((struct Obj00013 *)obj)->f104)->sav)));
    h = ((struct Obj00013 *)obj)->f108;
    ((struct Obj01067 *)dst)->f40 = REGULATION_Card_GetValue((struct Reg2 *)h, 2);
    ((struct Obj01067 *)dst)->f50 = REGULATION_Card_CalcCrc((struct Reg2 *)h);
}





/*
 * leaf: copy128 bytes from response+0x1c to save+0x54.
 */
void func_021D9B18(char *save, char *response)
{
    MI_CpuCopy8(response + 0x1c, save + 0x54, 128);
}






u32_021D9B2C func_021D9B2C(char *obj, void *list, u32_021D9B2C heapId)
{
    int heap = (heapId & 0x7fff) | 0x8000;
    u32_021D9B2C size = func_020173EC();
    void *buf = NHTTP_RAP_EvilCheckAllocArray(size, POKEPARTY_GetCount(list), (u16)heap);
    int i;
    u32_021D9B2C ret;

    for (i = 0; i < (int)POKEPARTY_GetCount(list); i++) {
        void *e = POKEPARTY_GetMember(list, i);
        NHTTP_RAP_EvilCheckSetElement((int)buf, (int)e, func_020173EC(), i);
    }
    size = func_020173EC();
    ret = NHTTP_RAP_VerifySignature(buf, size, POKEPARTY_GetCount(list), obj + 0x54, (u16)heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}






int func_021D9BC4(u32_021D9BC4 a, u32_021D9BC4 b)
{
    u32_021D9BC4 n = POKEPARTY_GetCount((void *)a);
    u32_021D9BC4 i;

    if (n == POKEPARTY_GetCount((void *)b)) {
        for (i = 0; i < n; i++) {
            u32_021D9BC4 ea = (u32_021D9BC4)POKEPARTY_GetMember((void *)a, i);
            u32_021D9BC4 eb = (u32_021D9BC4)POKEPARTY_GetMember((void *)b, i);
            u8 *pa = func_020185F0(ea);
            u8 *pb = func_020185F0(eb);
            if (func_0203EFC8(pa, pb, POKE_TOOL_GetBoxParamSize()) != 0)
                return 0;
        }
        return 1;
    }
    return 0;
}






/*
 * Quit-confirmation dialog step (state at +0xec): waits for the trigger and the button, prints the question, waits for the message, opens the yes/no window, then on yes prints the goodbye and closes the connection (returns 3 when finished), on no returns 2; returns 1 while the dialog is active and 0 when idle.
 *
 * Closed: the final state test is a switch, which keeps the `return 0` arm as the
 *     fall-through where every if/else spelling inverts it (EXACT* once the
 *     ov177 getter 0x021E8844 got its label).
 */
int func_021D9C34(char *obj, int trigger, int go)
{
    int r;

    switch (((struct Obj00594 *)obj)->fEC) {
    case 0:
        if (trigger == 0)
            break;
        if (!(KEY_GetTrg() & 2))
            break;
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 1:
        func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x23, 1);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 2:
        if (!func_021E8844((const int *)(((struct Obj00594 *)obj)->f2C)))
            break;
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 3:
        func_021D98E4((u32_021D98E4 *)((u32_021D9C34 *)obj), 0);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 4:
        r = func_021D9A08(obj);
        if (r == -1)
            break;
        func_021D99F4(obj);
        switch (r) {
        case 0:
            ((struct Obj00594 *)obj)->fEC = 5;
            break;
        case 1:
            func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x21, 0);
            ((struct Obj00594 *)obj)->fEC = 0;
            return 2;
        }
        break;
    case 5:
        func_021E8738((int *)(((struct Obj00594 *)obj)->f2C), ((struct Obj00594 *)obj)->f14, 0x2b, 2);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        break;
    case 6:
        if (go == 0)
            break;
        func_021DA434(((struct Obj00594 *)obj)->f34);
        ((struct Obj00594 *)obj)->fEC = ((struct Obj00594 *)obj)->fEC + 1;
        func_021E7E0C((void **)(((struct Obj00594 *)obj)->f28), 0);
        func_021DA36C(((struct Obj00594 *)obj)->f34);
        if (!func_0200FB24() && GFL_NET_GetRunState())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct Obj00594 *)obj)->fEC = 0;
        return 3;
    }
    switch (((struct Obj00594 *)obj)->fEC) {
    case 0:
        return 0;
    default:
        return 1;
    }
}






/*
 * Clears the +0xec last-read length and tail-calls the +0x30 release path
 *     func_021D99F4, so nothing is saved.  Mirrors func_021D6954.
 */
void func_021D9D40(char *obj)
{
    ((struct Obj24319 *)obj)->fEC = 0;
    func_021D99F4(obj);
}






/*
 * Syncs three words of a record (+0x10, +0x8, +0xc) into slots 0..2 of table 10 of the save block at +0x104; returns 1 when any of them differed from what was stored.
 *
 * Both callees 0x0200DFD8 and 0x0200DFE4 resolve since seeds_2 labelled and
 *     matched them (src/matched/unit_0200DFD8.c).
 */
int func_021D9D50(char *obj, u32_021D9D50 *rec)
{
    int changed = 0;

    if (rec[4] != BSUBWAY_SAVEDATA_GetStat(((struct Obj24320 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0)
        || rec[2] != BSUBWAY_SAVEDATA_GetStat(((struct Obj24321 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1)
        || rec[3] != BSUBWAY_SAVEDATA_GetStat(((struct Obj24322 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2))
        changed = 1;
    BSUBWAY_SAVEDATA_SetStat(((struct Obj24323 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0, rec[4]);
    BSUBWAY_SAVEDATA_SetStat(((struct Obj24324 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1, rec[2]);
    BSUBWAY_SAVEDATA_SetStat(((struct Obj24325 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2, rec[3]);
    return changed;
}





/*
 *   extern void GFL_NET_SYSTEM_SetWaitMode(int);
 *   void GFL_NET_SetWaitMode(int value) { GFL_NET_SYSTEM_SetWaitMode(value); }
 *   Its target stores its one word input at global +0x1ac; no extra input.
 *   Leaf returns *(u32_021D9A50 *)(p+0x1458) for kind 3 or 6, otherwise 0.
 * lever: u16 heap fixes allocator spill order; 02009860 leaves r0 live,
 *   and caller stores that return word despite the callee's void declaration.
 * note 2026-10-04 (lane 20, D2): leaf func_021DC5F8 is now filed EXACT as
 * src/matched/ov/ov175_func_021DC5F8.c (24 bytes). The tool still says "no witness" for it until
 * the integrator runs the manifest. The other blocker, ARM9 GFL_NET_SetWaitMode (veneer-like 12-byte
 * tail call), is the arm9 label lane's. Body is byte-correct; expect EXACT after manifest + label.
 */
char *func_021D9DC8(u32_021D9DC8 a, void *save, u32_021D9DC8 b, u16 heap) {
    char *p;
    p = func_02030734(heap, 0x149c, 0, d_021E2EE0, 0x2b0);
    MI_CpuFill8(p, 0, 0x149c);
    *(u32_021D9DC8 *)(p + 4) = GAME_DATA_GetField1A0(save);
    *(u32_021D9DC8 *)p = func_02009860();
    *(void **)(p + 0xc) = (void *)func_0200853C((const struct Sub0200852CObj *)func_02012944(save));
    *(void **)(p + 8) = save;
    *(u32_021D9DC8 *)(p + 0x10) = b;
    *(u32_021D9DC8 *)(p + 0x1464) = a;
    *(int *)(p + 0x19c) = 0x573;
    *(char **)(p + 0x190) = func_02030734(heap, 0x260, 0, d_021E2EE0, 0x2c0);
    MI_CpuFill8(*(void **)(p + 0x190), 0, 0x260);
    if (!GFL_NET_GetRunState()) func_02034714(d_021E2EF8, 0, d_021E2EF8);
    GFL_NET_COMMAND_AddCommandTable(0x2400, (u32_021D9DC8)d_021E2C90, 6, (u32_021D9DC8)p);
    GFL_NET_SetWaitMode(0);
    DWC_RAP_SetErrorCallback((int)func_021DC5C8, (int)p);
    DWC_RAP_SetErrorHookCallback((int)func_021DC5F8, (int)p);
    return p;
}





void func_021D9EA0(u8 *p) { DWC_RAP_SetErrorHookCallback(0,0); DWC_RAP_SetErrorCallback(0,0); GFL_NET_COMMAND_DeleteCommandTable(0x2400); func_020307B0(((struct Obj24326 *)p)->f190); func_020307B0(p); }





/*
 * Empty stub sitting between the func_021D9EA0 teardown and
 *     func_021D9ED4; nothing calls into it, disasm.py labelled it from its
 *     alignment padding.
 */
void func_021D9ED0(int a0)
{
}






/*
 * Stores the caller's word at +0x14 and forwards its low byte to
 *     0x02039C68 with the tick/state from 0x020399A8 and line 0x24.  The byte
 *     is re-read from the field after the first call, which is why the listing
 *     reloads +0x14.  func_021D9EEC is the same shape for the flush path.
 */
void func_021D9ED4(char *obj, u32_021D9ED4 v)
{
    ((struct Obj14331 *)obj)->f14 = v;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)((struct Obj14331 *)obj)->f14, 0x24);
}







/*
 * Flush partner of func_021D9ED4: sends the byte the object kept at
 *     +0x14 to 0x02039CB4 with the tick/state and line 0x24.
 */
int func_021D9EEC(char *obj)
{
    return GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)((struct Obj24327 *)obj)->f14, 0x24);
}







/*
 * Error poll: while the link is up, classifies the transport error through 0x02157170 (0..4); otherwise classifies the stored error record by its kind, and on a nonzero class shuts the screens down, runs the class action (1 reset, 2 fatal screen, 3 retry) and clears the record.
 */
int func_021D9F04(char *ctx, void *a, void *b)
{
    u32_021D9F04 *rec = (u32_021D9F04 *)(ctx + 0x18);
    Res r = RES_NONE;

    if (GFL_NET_GetRunState()) {
        if (func_0200FB24()) {
            GFL_NET_SetAutoExit(r);
            GFL_NET_SetLoginOption(r);
            GFL_USE_StopAllSe();
            if (GAME_DATA_IsSaving((const u8 *)(((struct Obj08279 *)ctx)->f8))) {
                GAME_DATA_SaveCancel((char *)(((struct Obj08279 *)ctx)->f8));
                func_0200F7C0(0x29);
            }
        }
        switch (DWC_RAPCOMMON_HandleNetError(a, b)) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = RES_1;
            break;
        case 2:
            r = RES_2;
            break;
        case 3:
            r = RES_3;
            break;
        case 4:
            r = RES_4;
            break;
        }
        return r;
    }
    if (r == RES_NONE) {
        switch (rec[7]) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = func_021DCE60(rec[0]);
            break;
        case 2:
            r = func_021DCEE0(rec[1], rec[2], rec[3]);
            break;
        case 3:
        case 4:
            r = RES_NONE;
            break;
        case 5:
            r = func_021DCFDC(rec[6]);
            break;
        default:
            r = RES_NONE;
            break;
        }
        if (r != RES_NONE) {
            GFL_NET_SetAutoExit(0);
            GFL_NET_SetLoginOption(0);
            GFL_USE_StopAllSe();
            if (GAME_DATA_IsSaving((const u8 *)(((struct Obj08279 *)ctx)->f8))) {
                GAME_DATA_SaveCancel((char *)(((struct Obj08279 *)ctx)->f8));
                func_0200F7C0(0x29);
            }
        }
        switch (r) {
        case RES_1:
            GFL_NET_STATE_ClearErrorMode();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ShowSimpleScreen();
            func_0200FBA0();
            break;
        case RES_2:
            if (!func_0200FB24()) {
                GFL_NET_STATE_SetError(0, 0, 0, 0x3F7);
                func_0200FAAC();
            }
            GFL_NET_ERR_RequestScreen();
            break;
        case RES_3:
            func_0200FA84();
            break;
        }
        if (r != RES_NONE)
            func_021DCFFC(rec);
    }
    return r;
}






void func_021DA044(u8 *p) { ((struct Obj14332 *)p)->f12C=0; ((struct Obj14332 *)p)->f128=0; }






int func_021DA054(char *ctx)
{
    int result;
    switch (((struct Obj00629 *)ctx)->f128) {
    case 0:
        func_021DB3A4(ctx, -1, 2, *(unsigned int *)&((struct Obj00629 *)ctx)->f1464);
        ((struct Obj00629 *)ctx)->f128 = 1;
        break;
    case 1:
        result = func_021DB478(ctx);
        if (result == 1) {
            if (**(int * *)&((struct Obj00629 *)ctx)->f1464 != 0) ((struct Obj00629 *)ctx)->f128 = 4;
            else ((struct Obj00629 *)ctx)->f128 = 2;
        } else if (result == 2) return 2;
        break;
    case 2:
        func_021DBFA4(ctx);
        ((struct Obj00629 *)ctx)->f128 = 3;
        break;
    case 3:
        result = func_021DBFB4(ctx);
        if (result == 1) ((struct Obj00629 *)ctx)->f128 = 4;
        else if (result == 2) return 2;
        break;
    case 4: return 1;
    }
    return 0;
}







/*
 * Sets up a matchmaking attempt: closes any connection, publishes the eight match keys (player count, group, 1, four record words, version 0x20015), formats the filter string and picks the evaluation callback for the mode (1 asserts).
 */
void func_021DA0D4(char *obj, int mode, int extra, int group, int *rec)
{
    int count = mode;

    if (mode == 1)
        count += extra;
    if (!GFL_NET_GetRunState())
        func_0200FA84();
    DWC_CloseAllConnectionsHard();
    func_021DA4B8(obj, 0, count);
    func_021DA4B8(obj, 1, group);
    func_021DA4B8(obj, 2, 1);
    func_021DA4B8(obj, 3, rec[0]);
    func_021DA4B8(obj, 5, rec[1]);
    func_021DA4B8(obj, 4, rec[2]);
    func_021DA4B8(obj, 6, rec[3]);
    func_021DA4B8(obj, 7, 0x20015);
    STD_TSPrintf(obj + 0x44, d_021E2EFC, count, group, 1);
    ((struct Obj05458 *)obj)->f40 = 0;
    ((struct Obj05458 *)obj)->f1A0 = 0;
    ((struct Obj05458 *)obj)->f1A4 = 0;
    MI_CpuFill8(obj + 0x138, 0, 0x18);
    switch (mode) {
    case 0:
        *(EvalFn *)&((struct Obj05458 *)obj)->f1218 = func_021DA4F8;
        break;
    case 1:
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
        break;
    case 2:
        *(EvalFn *)&((struct Obj05458 *)obj)->f1218 = func_021DA4E8;
        break;
    case 3:
        *(EvalFn *)&((struct Obj05458 *)obj)->f1218 = func_021DA4F0;
        break;
    default:
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
        break;
    }
}







/*
 * Matchmaking step (state at +0x40): 0 starts the search with the evaluation callback, then waits for the match, the peer handshake (with a 3600-tick timeout counted at +0x1a4) and the link check; returns 1 when done, 2 on a fatal error and 0 while still running.
 */
int func_021DA1E4(char *obj)
{
    switch (((struct Obj00839 *)obj)->f40) {
    case 0:
        if (DWC_RAP_StartMatchWithFilter(obj + 0x44, 2, ((struct Obj00839 *)obj)->f1218, obj)) {
            GFL_NET_STATE_WifiEnterRandomMatch();
            DWC_RAP_SetVchatEnabled(0);
            ((struct Obj00839 *)obj)->f40 = 1;
        } else {
            GFL_NET_STATE_WifiDisconnect(1);
            return 2;
        }
        break;
    case 1:
        ((struct Obj00839 *)obj)->f40 = 2;
        break;
    case 2:
        switch (GFL_NET_STATE_GetWifiState()) {
        case 0:
            if ((u32_021DA1E4)(*(u32_021DA1E4 *)(GFL_NET_STATE_GetError() + 0xc) - 0x3f0) > 1)
                break;
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        case 1:
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 3;
            GFL_NET_SetAutoExit(1);
            GFL_NET_SetLoginOption(1);
            break;
        default:
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
            break;
        }
        break;
    case 3:
        if (GFL_NET_SYSTEM_GetCurrentAid()) {
            if (GFL_NET_HANDLE_CheckNegotiation())
                ((struct Obj00839 *)obj)->f40 = 4;
            if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
                func_021DA384(obj);
                ((struct Obj00839 *)obj)->f40 = 7;
            }
        } else {
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 5;
        }
        break;
    case 4:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24);
        ((struct Obj00839 *)obj)->f1A4 = 0;
        ((struct Obj00839 *)obj)->f40 = 6;
        break;
    case 5:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (GFL_NET_HANDLE_GetNegotiationNum() && GFL_NET_HANDLE_CheckNegotiation()) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24);
            ((struct Obj00839 *)obj)->f1A4 = 0;
            ((struct Obj00839 *)obj)->f40 = 6;
        }
        break;
    case 6:
        if ((((struct Obj00839 *)obj)->f1A4)++ > 0xe10) {
            func_021DA384(obj);
            ((struct Obj00839 *)obj)->f40 = 7;
        } else if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24)) {
            ((struct Obj00839 *)obj)->f40 = 8;
        }
        break;
    case 7:
        if (func_021DA390(obj)) {
            if ((u32_021DA1E4)(*(u32_021DA1E4 *)(GFL_NET_STATE_GetError() + 0xc) - 0x3f0) <= 1) {
                GFL_NET_STATE_SetWifiError();
                GFL_NET_STATE_ClearErrorMode();
                func_0200FBA0();
                GFL_NET_STATE_WifiDisconnect(1);
            }
            return 2;
        }
        break;
    case 8:
        GFL_NET_IsParentAid();
        return 1;
    }
    return 0;
}







/*
 * Three-call init/reset sequence: 0x0203D7B0(0), 0x0203D7BC(0) and
 *     0x0203C554(1).
 */
void func_021DA36C()
{
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    GFL_NET_STATE_WifiDisconnect(1);
}







/*
 * Leaf: clears the word at +0x154.
 */
void func_021DA384(char *obj)
{
    ((struct Obj24329 *)obj)->f154 = 0;
}







/*
 * Link shutdown sequence stepped by the word at +0x154: sync 0x18, wait for the sync (600 frame timeout on +0x1a0), stop the two link services, wait 30 frames on +0x134, restart the parent service, then report done (1).
 */
int func_021DA390(char *obj)
{
    switch (((struct Obj02513 *)obj)->f154) {
    case 0:
        func_021D9ED4(obj, 0x18);
        ((struct Obj02513 *)obj)->f1A0 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 1:
        if (func_021D9EEC(obj) != 0)
            (((struct Obj02513 *)obj)->f154)++;
        else if ((((struct Obj02513 *)obj)->f1A0)++ > 600)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 2:
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        ((struct Obj02513 *)obj)->f134 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 3:
        if ((((struct Obj02513 *)obj)->f134)++ > 30)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 4:
        GFL_NET_STATE_WifiDisconnect(1);
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}







int func_021DA434()
{
    if (DWC_RAP_IsStateInSession() != 0)
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2402, 4, (u32_021DA434)g_021E2C8C);
    return 1;
}







u32_021DA45C func_021DA45C(char *obj)
{
    u32_021DA45C v = ((struct Obj14333 *)obj)->f140;

    if (v != 0)
        ((struct Obj14333 *)obj)->f140 = 0;
    return v;
}






/*
 * stack: four date words (including weekday), three time words.
 */
void func_021DA470(unsigned char *dest)
{
    int date[4];
    int time[3];
    if (!GFL_NET_GetRunState()) func_0200FA84();
    if (!func_02167ED8(date, time)) func_0200FA84();
    MI_CpuFill8(dest, 0, 6);
    dest[0] = date[0];
    dest[1] = date[1];
    dest[2] = date[2];
    dest[3] = time[0];
    dest[4] = time[1];
    dest[5] = time[2];
}







/*
 * Registers match key i: stores the value, copies the three-byte key name from the table at 0x021E2E10, and keeps the key id DWC_AddMatchKeyInt returns.
 */
void func_021DA4B8(char *obj, int i, int value)
{
    struct MatchKey *k = (struct MatchKey *)(obj + 0xc4) + i;

    k->value = value;
    MI_CpuCopy8(d_021E2E10[i], k->name, 3);
    k->term = 0;
    k->id = DWC_AddMatchKeyInt(k->id, k->name, &k->value);
}







/*
 * Matchmaking evaluation callback that forwards to the key-distance scorer func_021DA4F8 (unlabelled; its address is a code pointer in func_021DA0D4's pool).
 */
int func_021DA4E8(int index, void *param)
{
    return func_021DA4F8(index, param);
}






/*
 * Matchmaking evaluation callback that scores every candidate 1000 (unlabelled; its address is a code pointer in func_021DA0D4's pool).
 */
int func_021DA4F0(int index, void *param)
{
    return 1000;
}







/*
 * Matchmaking evaluation callback: reads the candidate's keys 3..6; a candidate with none of them scores 0, one whose key 4 differs from ours scores 0, otherwise 1000 less the key 3 distance and 32 times the distance between the two key5*50/(key6+5) ratios, floored at 0.
 */
int func_021DA4F8(int index, void *param)
{
    char *p = param;
    int b, a, c, d;
    int q1, q2, da, dq, score;

    a = DWC_GetMatchIntValue(index, p + 0xee, -1);
    b = DWC_GetMatchIntValue(index, p + 0x106, -1);
    c = DWC_GetMatchIntValue(index, p + 0x112, -1);
    d = DWC_GetMatchIntValue(index, p + 0xfa, -1);

    if (a == -1 && b == -1 && d == -1 && c == -1)
        return 0;
    if (d == ((struct Obj08280 *)p)->fF4) {
        q1 = b * 50 / (c + 5);
        q2 = ((struct Obj08280 *)p)->f100 * 50 / (((struct Obj08280 *)p)->f10C + 5);
        da = a - ((struct Obj08280 *)p)->fE8;
        if (da < 0)
            da = -da;
        dq = q1 - q2;
        if (dq < 0)
            dq = -dq;
        score = 1000 - da - dq * 32;
        if (score < 0)
            return 0;
        return score;
    }
    return 0;
}







/*
 * Arms a storage-server report: resets the report state words, stores mode and the result slot, and picks the report callback at +0x158 from mode (0: plain, 1 with a result slot, or 1 without one, which also stores a3 and the two record words) and kind (0 or 2; anything else asserts).
 */
void func_021DA5B0(char *obj, int mode, int kind, u32_021D9A50 a3, u32_021D9A50 *rec, u32_021D9A50 slot)
{
    ((struct Obj01069 *)obj)->f1494 = 0;
    ((struct Obj01069 *)obj)->f12C = 0;
    ((struct Obj01069 *)obj)->f1A8 = 1;
    ((struct Obj01069 *)obj)->f14C = 0;
    ((struct Obj01069 *)obj)->f138 = 0;
    ((struct Obj01069 *)obj)->f1AC = mode;
    ((struct Obj01069 *)obj)->f160 = slot;
    ((struct Obj01069 *)obj)->f164 = 0;
    ((struct Obj01069 *)obj)->f168 = 0;
    ((struct Obj01069 *)obj)->f16C = 0;
    if (mode == 0) {
        switch (kind) {
        case 0:
            *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB228;
            break;
        case 2:
            *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB218;
            break;
        default:
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    } else if (mode == 1) {
        if (slot != 0) {
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB248;
                break;
            case 2:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = func_021DB238;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        } else {
            GFL_NET_IsParentAid();
            ((struct Obj01069 *)obj)->f180 = a3;
            ((struct Obj01069 *)obj)->f184 = rec[0];
            ((struct Obj01069 *)obj)->f188 = rec[4];
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = (ReportFn)func_021DB160;
                break;
            case 2:
                *(ReportFn *)&((struct Obj01069 *)obj)->f158 = (ReportFn)func_021DAFB8;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
    }
}







int func_021DA6B8(char *p, u32_021D9A50 *out)
{
    Sys *s;
    int r;
    char *dst;
    void *src;

    if (out != 0)
        *out = *(u32_021D9A50 *)(p + 0x16c);
    s = (Sys *)GFL_NET_STATE_GetError();
    if (s->fc - 0x3f0 <= 1)
        *(u32_021D9A50 *)(p + 0x160) = 1;
    if (func_0200FB24() == 1) {
        if (s->f4 == 6 || s->f4 == 3) {
            func_021DAE18(p);
            return 2;
        }
    } else if (*(u32_021D9A50 *)(p + 0x160) == 0 && func_0200FB24() == 2) {
        func_021DAE18(p);
        return 2;
    }
    if (*(u32_021D9A50 *)(p + 0x160) != 0 && *(u32_021D9A50 *)(p + 0x1ac) != 0 && *(u32_021D9A50 *)(p + 0x164) == 0
        && *(u32_021D9A50 *)(p + 0x12c) > 7 && *(u32_021D9A50 *)(p + 0x12c) < 10) {
        *(u32_021D9A50 *)(p + 0x168) = 0;
        *(u32_021D9A50 *)(p + 0x12c) = 6;
    }

    switch (*(u32_021D9A50 *)(p + 0x12c)) {
    case 0:
        if (*(u32_021D9A50 *)(p + 0x160) != 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 4;
            break;
        }
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x24);
        *(u32_021D9A50 *)(p + 0x12c) = 1;
        break;
    case 1:
        if (*(u32_021D9A50 *)(p + 0x160) != 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 4;
            break;
        }
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x24) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
            *(u32_021D9A50 *)(p + 0x12c) = 2;
        break;
    case 2:
        if (*(u32_021D9A50 *)(p + 0x160) != 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 4;
            break;
        }
        if (func_021DC2C0((u32_021D9A50)p, p + 0x188) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
            *(u32_021D9A50 *)(p + 0x12c) = 3;
        break;
    case 3:
        if (*(u32_021D9A50 *)(p + 0x160) != 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 4;
            break;
        }
        if (func_021DC2D8(p, (u32_021D9A50 *)(p + 0x18c)) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
            *(u32_021D9A50 *)(p + 0x12c) = 4;
        break;
    case 4:
        *(u32_021D9A50 *)(p + 0x134) = 0;
        *(u32_021D9A50 *)(p + 0x170) = 1;
        r = DWC_ScInitialize(0xb5f, 0);
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x751);
            func_021DAE18(p);
            return 2;
        }
        *(u32_021D9A50 *)(p + 0x12c) = 5;
        break;
    case 5:
        r = DWC_ScGetLoginCertificate((void **)(*(char **)(p + 0x1464) + 4));
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x761);
            func_021DAE18(p);
            return 2;
        }
        *(u32_021D9A50 *)(p + 0x12c) = 6;
        break;
    case 6:
        if (GFL_NET_IsParentAid() != 0 || *(u32_021D9A50 *)(p + 0x160) != 0) {
        (*(u32_021D9A50 *)(p + 0x134))++;
        r = DWC_ScCreateSessionAsync((u32_021D9A50)func_021DADB4, 100, (u32_021D9A50)p);
        *(u32_021D9A50 *)(p + 0x164) = 1;
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x773);
            func_021DAE18(p);
            return 2;
        }
        *(u32_021D9A50 *)(p + 0x1a0) = 0;
        *(u32_021D9A50 *)(p + 0x12c) = 7;
        } else
            *(u32_021D9A50 *)(p + 0x12c) = 8;
        break;
    case 7:
        if (*(u32_021D9A50 *)(p + 0x134) == 0) {
            dst = *(char **)(p + 0x1464) + 0xc;
            src = DWC_ScGetSessionId();
            MI_CpuCopy8(src, dst, 0x28);
            *(u32_021D9A50 *)(p + 0x12c) = 8;
            break;
        }
        if ((*(u32_021D9A50 *)(p + 0x1a0))++ > 0xe10) {
            func_021DCE08(p + 0x18, 1, 0x78f);
            func_021DAE18(p);
            return 2;
        }
        DWC_ScProcess();
        if (*(u32_021D9A50 *)(p + 0x15c) != 0) {
            func_021DCE24(p + 0x18, *(u32_021D9A50 *)(p + 0x15c), 0x797);
            func_021DAE18(p);
            return 2;
        }
        break;
    case 8:
        if (*(u32_021D9A50 *)(p + 0x160) != 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 0xb;
            break;
        }
        dst = *(char **)(p + 0x1464) + 0x34;
        src = DWC_ScGetConnectionId();
        MI_CpuCopy8(src, dst, 0x28);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x24);
        *(u32_021D9A50 *)(p + 0x12c) = 9;
        break;
    case 9:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x24) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
            *(u32_021D9A50 *)(p + 0x12c) = 0xa;
        break;
    case 10:
        if (GFL_NET_IsParentAid() != 0 || *(u32_021D9A50 *)(p + 0x160) != 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2400, 0x68, *(u32_021D9A50 *)(p + 0x1464) + 4) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
                *(u32_021D9A50 *)(p + 0x12c) = 0xb;
        } else if (*(u32_021D9A50 *)(p + 0x138) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0) {
            *(u32_021D9A50 *)(p + 0x138) = 0;
            r = DWC_ScSetSessionId((u32_021D9A50)(*(char **)(p + 0x1464) + 0x74));
            dst = *(char **)(p + 0x1464) + 0xc;
            src = DWC_ScGetSessionId();
            MI_CpuCopy8(src, dst, 0x28);
            if (r != 0) {
                func_021DCE24(p + 0x18, r, 0x7cd);
                func_021DAE18(p);
                return 2;
            }
            *(u32_021D9A50 *)(p + 0x12c) = 0xb;
        }
        break;
    case 11:
        (*(u32_021D9A50 *)(p + 0x134))++;
        r = DWC_ScSetReportIntentionAsync(*(u32_021D9A50 *)(p + 0x1a8), (u32_021D9A50)func_021DADCC, 100, (u32_021D9A50)p);
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x7dd);
            func_021DAE18(p);
            return 2;
        }
        *(u32_021D9A50 *)(p + 0x1a0) = 0;
        *(u32_021D9A50 *)(p + 0x12c) = 0xc;
        break;
    case 12:
        if (*(u32_021D9A50 *)(p + 0x134) == 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 0xd;
            break;
        }
        if ((*(u32_021D9A50 *)(p + 0x1a0))++ > 0xe10) {
            func_021DCE08(p + 0x18, 1, 0x7f2);
            func_021DAE18(p);
            return 2;
        }
        DWC_ScProcess();
        if (*(u32_021D9A50 *)(p + 0x15c) != 0) {
            func_021DCE24(p + 0x18, *(u32_021D9A50 *)(p + 0x15c), 0x7fa);
            func_021DAE18(p);
            return 2;
        }
        break;
    case 13:
        if (*(u32_021D9A50 *)(p + 0x160) != 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 0x13;
            break;
        }
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x24);
        *(u32_021D9A50 *)(p + 0x12c) = 0xe;
        break;
    case 14:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x24) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
            *(u32_021D9A50 *)(p + 0x12c) = 0xf;
        break;
    case 15:
        if (GFL_NET_IsParentAid() != 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2400, 0x68, *(u32_021D9A50 *)(p + 0x1464) + 4) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
                *(u32_021D9A50 *)(p + 0x12c) = 0x10;
        } else if (*(u32_021D9A50 *)(p + 0x138) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0) {
            if (*(u32_021D9A50 *)(p + 0x160) == 0)
                *(u32_021D9A50 *)(p + 0x168) = 1;
            *(u32_021D9A50 *)(p + 0x138) = 0;
            *(u32_021D9A50 *)(p + 0x12c) = 0x10;
        }
        break;
    case 16:
        if (GFL_NET_IsParentAid() == 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2400, 0x68, *(u32_021D9A50 *)(p + 0x1464) + 4) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
                *(u32_021D9A50 *)(p + 0x12c) = 0x11;
        } else if (*(u32_021D9A50 *)(p + 0x138) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0) {
            if (*(u32_021D9A50 *)(p + 0x160) == 0)
                *(u32_021D9A50 *)(p + 0x168) = 1;
            *(u32_021D9A50 *)(p + 0x138) = 0;
            *(u32_021D9A50 *)(p + 0x12c) = 0x11;
        }
        break;
    case 17:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x24);
        *(u32_021D9A50 *)(p + 0x12c) = 0x12;
        break;
    case 18:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x24) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
            *(u32_021D9A50 *)(p + 0x12c) = 0x13;
        break;
    case 19:
        r = func_021DAE54(*(char **)(p + 0x1464) + 4, *(char **)(p + 0x1464) + 0x6c, p + 0x180, *(u32_021D9A50 *)(p + 0x1a8),
                          *(RoundFn *)(p + 0x158), *(u32_021D9A50 *)(p + 0x160), *(u32_021D9A50 *)(p + 0x1ac), *(u32_021D9A50 *)(p + 0x168));
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x86d);
            func_021DAE18(p);
            return 2;
        }
        *(u32_021D9A50 *)(p + 0x12c) = 0x14;
        break;
    case 20:
        (*(u32_021D9A50 *)(p + 0x134))++;
        r = DWC_ScSubmitReportAsync(*(u32_021D9A50 *)(*(char **)(p + 0x1464) + 8), *(u32_021D9A50 *)(p + 0x1a8), (u32_021D9A50)func_021DAE00, 100, p);
        if (r != 0) {
            func_021DCE24(p + 0x18, r, 0x87c);
            func_021DAE18(p);
            return 2;
        }
        *(u32_021D9A50 *)(p + 0x1a0) = 0;
        *(u32_021D9A50 *)(p + 0x12c) = 0x15;
        break;
    case 21:
        if (*(u32_021D9A50 *)(p + 0x134) == 0) {
            *(u32_021D9A50 *)(p + 0x12c) = 0x16;
            break;
        }
        if ((*(u32_021D9A50 *)(p + 0x1a0))++ > 0xe10) {
            func_021DCE08(p + 0x18, 1, 0x890);
            func_021DAE18(p);
            return 2;
        }
        DWC_ScProcess();
        if (*(u32_021D9A50 *)(p + 0x15c) != 0) {
            func_021DCE24(p + 0x18, *(u32_021D9A50 *)(p + 0x15c), 0x898);
            func_021DAE18(p);
            return 2;
        }
        break;
    case 22:
        *(u32_021D9A50 *)(p + 0x16c) = 1;
        func_021DAE18(p);
        *(u32_021D9A50 *)(p + 0x12c) = 0x17;
        break;
    case 23:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x24);
        *(u32_021D9A50 *)(p + 0x12c) = 0x18;
        break;
    case 24:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x24) != 0 || *(u32_021D9A50 *)(p + 0x160) != 0)
            *(u32_021D9A50 *)(p + 0x12c) = 0x19;
        break;
    case 25:
        return 1;
    }
    return 0;
}









u32_021DADAC func_021DADAC(u8 *p) { return ((struct Obj24330 *)p)->f150; }










/*
 * Competition-server completion callback: records a nonzero result at +0x15c and drops the pending-request count at +0x134 (unlabelled; its address is a code pointer in func_021DA6B8's pool).
 */
void func_021DADB4(int result, char *obj)
{
    if (result != 0)
        ((struct Obj14335 *)obj)->f15C = result;
    (((struct Obj14335 *)obj)->f134)--;
}










/*
 * Report-intention completion callback: on success copies the 0x28-byte session id into the report block (+0x34 of the record at +0x1464), otherwise records the result at +0x15c; then drops the pending-request count at +0x134.
 */
void func_021DADCC(int result, char *obj)
{
    char *p = *(char * *)&((struct Obj10685 *)obj)->f1464 + 4;

    if (result == 0)
        MI_CpuCopy8(DWC_ScGetConnectionId(), p + 0x30, 0x28);
    else
        ((struct Obj10685 *)obj)->f15C = result;
    (((struct Obj10685 *)obj)->f134)--;
}










void func_021DAE00(int result, char *obj)
{
    if (result != 0)
        ((struct Obj14336 *)obj)->f15C = result;
    (((struct Obj14336 *)obj)->f134)--;
}










/*
 * Report teardown: when the state word at +0x170 is 1, destroys the report once the +0x12c step is past 0x13, shuts the storage client down once the +0x12c step is 4 or more, and clears the state word.
 */
void func_021DAE18(char *obj)
{
    if (((struct Obj03320 *)obj)->f170 == 1) {
        if (((struct Obj03320 *)obj)->f12C > 0x13)
            DWC_ScDestroyReport(((struct Obj24331 *)(*(char * *)&((struct Obj03320 *)obj)->f1464))->f8);
        if (((struct Obj03320 *)obj)->f12C >= 4)
            DWC_ScShutdown();
        ((struct Obj03320 *)obj)->f170 = 0;
    }
}










/*
 * One exchange round: bails with the first nonzero status of the four session checks, sends the local record (mode from the peer kind), runs the callback, optionally sends the peer's record back and runs the callback again, then closes with the flag.
 */
int func_021DAE54(char *ctx, char *other, char *peer, u32_021DAE54 a3, RoundFn cb, int flag, int have, int twoway)
{
    int r;
    int mode;
    int mode2;

    if ((r = DWC_ScCreateReport(1, 2, 0, (u32_021DAE54)(ctx + 4))) != 0)
        return r;
    if ((r = DWC_ScReportBeginGlobalData((u32_021DAE54 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if ((r = DWC_ScReportBeginPlayerData((u32_021DAE54 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if ((r = DWC_ScReportBeginNewPlayer((u8 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;

    if (flag != 0 || have == 0) {
        mode = 5;
    } else {
        switch (((struct Obj14337 *)peer)->f4) {
        case 1:
        case 4:
            mode = 0;
            break;
        case 0:
        case 3:
            mode = 1;
            break;
        case 2:
            mode = 2;
            break;
        default:
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    }
    if ((r = DWC_ScReportSetPlayerData(((struct Obj02887 *)ctx)->f4, 0, (s32)(ctx + 0x30), 0, mode, (char *)(((struct Obj02887 *)ctx)->f0), (s32)(ctx + 0x58))) != 0)
        return r;
    if ((r = cb(ctx, peer, 1, flag)) != 0)
        return r;
    if ((r = DWC_ScReportBeginNewPlayer((u8 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;

    if (twoway == 1) {
        if (have == 0) {
            mode2 = 5;
        } else if (flag != 0) {
            mode2 = 3;
        } else {
            switch (((struct Obj14337 *)peer)->f4) {
            case 1:
            case 4:
                mode2 = 1;
                break;
            case 0:
            case 3:
                mode2 = 0;
                break;
            case 2:
                mode2 = 2;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
        if ((r = DWC_ScReportSetPlayerData(((struct Obj02887 *)ctx)->f4, 1, (s32)(other + 0x30), 0, mode2, (char *)(((struct Obj24332 *)other)->f0), (s32)(other + 0x58))) != 0)
            return r;
        if ((r = cb(ctx, peer, 0, flag)) != 0)
            return r;
    }
    if ((r = DWC_ScReportBeginTeamData((u32_021DAE54 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if (flag != 0)
        return DWC_ScReportEnd(((struct Obj02887 *)ctx)->f4, a3, 1);
    return DWC_ScReportEnd(((struct Obj02887 *)ctx)->f4, a3, 0);
}









void func_021DAFB8(int *ctx,const u32_021DAFB8 *record,int invert) {
    int first,second,flip=0,skip=0,present;
    present=record[2]!=0 || record[3]!=0;
    switch(record[1]) {
    case 0: case 3: first=0; second=1; flip=1; break;
    case 1: case 4: first=1; second=0; flip=1; break;
    case 2: first=0; second=0; skip=1; break;
    case 5: case 6: default: first=0; second=0; break;
    }
    if(!invert && flip) { first^=1; second^=1; }
    switch(record[0]) {
    case 0:
        if(!skip && func_021DF420(ctx[1],15,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],5,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],6,second)) return;
        break;
    case 1:
        if(!skip && func_021DF420(ctx[1],16,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],8,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],7,second)) return;
        break;
    case 2:
        if(!skip && func_021DF420(ctx[1],18,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],11,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],12,second)) return;
        break;
    case 3:
        if(!skip && func_021DF420(ctx[1],17,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],9,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],10,second)) return;
        break;
    case 4:
        if(!skip && func_021DF420(ctx[1],19,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],13,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],14,second)) return;
        break;
    default: func_02034714(d_021E2EF8,0,d_021E2EF8); break;
    }
    if(DWC_ScReportAddIntValue(ctx[1],20,present!=0)) return;
    DWC_ScReportAddIntValue(ctx[1],27,-1);
}









/*
 * tail: 021DB216..021DB218 is two zero alignment bytes.
 */
void func_021DB160(int *ctx, int *input, int invert)
{
    int flip = 0, skip = 0;
    int first, second;
    int present = 1;
    if (input[2] == 0 && input[3] == 0) present = 0;
    switch (input[1]) {
    case 0: case 3: first = 0; second = 1; flip = 1; break;
    case 1: case 4: first = 1; second = 0; flip = 1; break;
    case 2: first = 0; second = 0; skip = 1; break;
    case 5: case 6: default: first = 0; second = 0; break;
    }
    if (!invert && flip) { first ^= 1; second ^= 1; }
    if (!skip && func_021DF420(ctx[1], 0x15, 1)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x16, first)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x17, second)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x18, present != 0)) return;
    DWC_ScReportAddIntValue(ctx[1], 0x1c, -1);
}










/*
 * Report callback: adds byte key 0x1a with value 1 to the report at +0x4.
 */
int func_021DB218(u32_021DB218 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x1a, 1);
}










/*
 * Report callback: adds byte key 0x19 with value 1 to the report at +0x4.
 */
int func_021DB228(u32_021DB228 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x19, 1);
}










/*
 * Report callback: adds byte key 0x1b with value -1 to the report at +0x4.
 */
int func_021DB238(u32_021DB238 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x1b, -1);
}










int func_021DB248(u32_021DB248 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x1c, -1);
}









void func_021DB258(int index,int unused,const void *src,u8 *p,int owner) { if(owner==(int)GFL_NET_HANDLE_GetCurrentHandle() && index!=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) { MI_CpuCopy8(src,*(u8 * *)&((struct Obj14338 *)p)->f1464+0x6c,0x68); ((struct Obj14338 *)p)->f138=1; } }









void func_021DB294(int index, int unused, void *dest, char *ctx, int owner)
{
    void *record;
    record = GAME_DATA_GetPlayerStatusById(((struct Obj14339 *)ctx)->f8, index);
    MI_CpuCopy8(dest, record, MYSTATUS_GetSize());
    if (owner == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        if (index != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())))
            ((struct Obj14339 *)ctx)->f13C = 1;
    }
}









/*
 * Compare the caller's first word with the current 0x0203D1A4 handle of the 0x020399A8 block; a match releases the 0x021E2EF8 pair through 0x02034714, a mismatch yields the +0x218 sub-block.
 */
int func_021DB2D4(int a, char *b)
{
    if (GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())) == a) {
        func_02034714((const char *)((int)g_021E2EF8), 0, (const char *)((int)g_021E2EF8));
        return 0;
    }
    return (int)(b + 0x218);
}










/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x140 word of the fourth argument.
 */
void func_021DB300(u32_021DB300 a, u32_021DB300 b, u32_021DB300 c, char *d, u32_021DB300 e)
{
    if (e != (u32_021DB300)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32_021DB300)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct Obj24337 *)d)->f140 = 1;
}










/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x144 word of the fourth argument.
 */
void func_021DB328(u32_021DB328 a, u32_021DB328 b, u32_021DB328 c, char *d, u32_021DB328 e)
{
    if (e != (u32_021DB328)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32_021DB328)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct Obj24338 *)d)->f144 = 1;
}










/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the entry address from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x148 word of the fourth argument.
 */
void func_021DB350(u32_021DB350 a, u32_021DB350 b, u32_021DB350 c, char *d, u32_021DB350 e)
{
    if (e != (u32_021DB350)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32_021DB350)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct Obj24339 *)d)->f148 = 1;
}









/*
 * Same guard as func_021DB300 but it moves the word the third argument
 *     points at into the +0x150 slot of the fourth argument and sets +0x14c.
 */
void func_021DB378(u32_021DB378 a, u32_021DB378 b, u32_021DB378 *c, char *d, u32_021DB378 e)
{
    u32_021DB378 v = *c;

    if (e != (u32_021DB378)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32_021DB378)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct Obj14340 *)d)->f150 = v;
    ((struct Obj14340 *)d)->f14C = 1;
}









/*
 * Selects a request kind 0..4: stores the table and its count at +0x194/+0x198 and the step callback at +0x17c, after resetting the step word at +0x12c and storing the two arguments.
 */
void func_021DB3A4(char *obj, u32_021DB3A4 target, int kind, u32_021DB3A4 arg)
{
    ((struct Obj01170 *)obj)->f12C = 0;
    ((struct Obj01170 *)obj)->f178 = arg;
    ((struct Obj01170 *)obj)->f1B0 = target;
    switch (kind) {
    case 0:
        *(char * *)&((struct Obj01170 *)obj)->f194 = func_021DD02C();
        ((struct Obj01170 *)obj)->f198 = func_021DD034();
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DB7C0;
        break;
    case 1:
        *(char * *)&((struct Obj01170 *)obj)->f194 = func_021DD038();
        ((struct Obj01170 *)obj)->f198 = func_021DD040();
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBA00;
        break;
    case 2:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DF4;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBB00;
        break;
    case 3:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DEC;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBB54;
        break;
    case 4:
        *(char * *)&((struct Obj01170 *)obj)->f194 = d_021E2DF0;
        ((struct Obj01170 *)obj)->f198 = 1;
        *(StepFn *)&((struct Obj01170 *)obj)->f17C = (StepFn)func_021DBBAC;
        break;
    }
}









int func_021DB478(char *obj)
{
    int r;

    switch (((struct Obj00840 *)obj)->f12C) {
    case 0:
        r = DWC_GdbInitialize(0xb5f, ((struct Obj00840 *)obj)->f0, 0);
        if (r != 0) {
            func_021DCE40(obj + 0x18, r, 0xdef);
            func_021DB6A0(obj);
            return 2;
        }
        ((struct Obj00840 *)obj)->f12C = 1;
        break;
    case 1:
        if (((struct Obj00840 *)obj)->f198 >= 0x26)
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
        if (((struct Obj00840 *)obj)->f1B0 == -1)
            r = DWC_GdbGetMyRecordsAsync(d_021E2F1C, ((struct Obj00840 *)obj)->f194, ((struct Obj00840 *)obj)->f198, func_021DB72C, obj);
        else
            r = DWC_GdbGetRecordsAsync(d_021E2F1C, (int *)(obj + 0x1b0), 1, ((struct Obj00840 *)obj)->f194, ((struct Obj00840 *)obj)->f198, func_021DB72C, obj);
        if (r != 0) {
            func_021DCE40(obj + 0x18, r, 0xe0a);
            func_021DB6A0(obj);
            return 2;
        }
        ((struct Obj00840 *)obj)->f12C = 2;
        ((struct Obj00840 *)obj)->f1A0 = 0;
        break;
    case 2:
        if ((((struct Obj00840 *)obj)->f1A0)++ > 0xe10) {
            func_021DCE08(obj + 0x18, 1, 0xe17);
            ((struct Obj00840 *)obj)->f12C = 6;
            break;
        }
        DWC_GdbProcess();
        r = DWC_GdbGetState();
        if (r == 0 || r == 4) {
            func_021DCE48(obj + 0x18, r, 0xe26);
            ((struct Obj00840 *)obj)->f12C = 6;
        } else if (r == 1) {
            ((struct Obj00840 *)obj)->f12C = 3;
        }
        break;
    case 3:
        r = DWC_GdbGetAsyncResult();
        if (r == 0) {
            func_021DCE50(obj + 0x18, r, 0xe39);
            ((struct Obj00840 *)obj)->f12C = 6;
        } else if (r != 1) {
            func_021DCE50(obj + 0x18, r, 0xe3f);
            func_021DB6A0(obj);
            return 2;
        } else {
            ((struct Obj00840 *)obj)->f12C = 4;
        }
        break;
    case 4:
        func_021DB6A0(obj);
        ((struct Obj00840 *)obj)->f12C = 5;
        break;
    case 5:
        return 1;
    case 6:
        r = DWC_GdbCancelRequest();
        if (r == 0) {
            ((struct Obj00840 *)obj)->f1A0 = 0;
            ((struct Obj00840 *)obj)->f12C = 7;
        } else {
            func_021DCE40(obj + 0x18, r, 0xe5e);
            func_021DB6A0(obj);
            return 2;
        }
        break;
    case 7:
        if ((((struct Obj00840 *)obj)->f1A0)++ > 0xe10) {
            func_021DCE08(obj + 0x18, 1, 0xe6a);
            func_021DB6A0(obj);
            return 2;
        }
        DWC_GdbProcess();
        r = DWC_GdbGetState();
        if (r == 0 || r == 4) {
            func_021DB6A0(obj);
            return 2;
        }
        if (r == 1)
            ((struct Obj00840 *)obj)->f12C = 8;
        break;
    case 8:
        func_021DB6A0(obj);
        return 2;
    }
    return 0;
}









/*
 * Shuts the storage-server database client down (unlabelled; reached by bl from func_021DB478).
 */
void func_021DB6A0(char *obj)
{
    DWC_GdbShutdown();
}








void func_021DB6A8(char *ctx)
{
    void *record;
    record = func_02012944(((struct Obj01171 *)ctx)->f8);
    *(char * *)&((struct Obj24341 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f0 = d_021E2F2C;
    ((struct Obj24342 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f4 = 8;
    ((struct Obj24343 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f8 = record;
    ((struct Obj24344 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->fC = 32;
    func_021DA470((unsigned char *)ctx + 0x38);
    *(char * *)&((struct Obj24345 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f10 = (char *)d_021E2F38;
    ((struct Obj24346 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f14 = 8;
    *(char * *)&((struct Obj24347 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f18 = ctx + 0x38;
    ((struct Obj24348 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f1C = 6;
    *(char * *)&((struct Obj24349 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f20 = d_021E2F4C;
    ((struct Obj24350 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f24 = 2;
    ((struct Obj24351 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f28 = ((struct Obj01171 *)ctx)->fC;
    *(char * *)&((struct Obj24352 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f30 = d_021E2F60;
    ((struct Obj24353 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f34 = 2;
    ((struct Obj24354 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f38 = func_021DD020(ctx);
    ((struct Obj01171 *)ctx)->f198 = 4;
}









/*
 * Storage-server records callback: forwards the records to the user callback at +0x17c, then, when no record id is pending (+0x1b0 == -1), scans every field of every record for the id field and stores its value through the pointer at +0x1464.
 */
void func_021DB72C(int count, struct Field_021DADAC **recs, char *obj)
{
    int i, j;
    struct Field_021DADAC *f;

    (*(RecordsFn *)(obj + 0x17c))(count, recs, ((struct Obj06574 *)obj)->f178, ((struct Obj06574 *)obj)->f198);
    if (((struct Obj06574 *)obj)->f1B0 != -1)
        return;
    for (i = 0; i < count; i++) {
        for (j = 0; j < ((struct Obj06574 *)obj)->f198; j++) {
            f = &recs[i][j];
            if (GF_STANDARD_CompareString(f->name, d_021E2F70) == 0)
                **(u32_021DB72C * *)&((struct Obj06574 *)obj)->f1464 = f->value;
        }
    }
}







void func_021DB7C0(int count,struct Field_021DB7C0 **fields,char *p,int n) {
    int i,j;
    struct Field_021DB7C0 *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(9))) ((struct Obj00922 *)p)->f40=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(10))) ((struct Obj00922 *)p)->f3C=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(12))) ((struct Obj00922 *)p)->f28=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(11))) ((struct Obj00922 *)p)->f24=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(13))) ((struct Obj00922 *)p)->f30=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(14))) ((struct Obj00922 *)p)->f2C=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(15))) ((struct Obj00922 *)p)->f48=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(16))) ((struct Obj00922 *)p)->f44=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(17))) ((struct Obj00922 *)p)->f38=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(18))) ((struct Obj00922 *)p)->f34=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(19))) ((struct Obj00922 *)p)->fC=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(20))) ((struct Obj00922 *)p)->f0=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(21))) ((struct Obj00922 *)p)->f4=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(22))) ((struct Obj00922 *)p)->f10=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(23))) ((struct Obj00922 *)p)->f8=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(3))) ((struct Obj00922 *)p)->f20=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(24))) ((struct Obj00922 *)p)->f18=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F4C)) ((struct Obj00922 *)p)->f4C=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F60)) ((struct Obj00922 *)p)->f50=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F7C)) ((struct Obj00922 *)p)->f54=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F70)) ((struct Obj00922 *)p)->f58=f->value;
        }
    }
}







void func_021DBA00(int count,struct Field_021DBA00 **fields,u8 *p,int n)
{
    int i,j;
    const struct Field_021DBA00 *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(0x25))==0) ((struct Obj05461 *)p)->f8=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(0x26))==0) ((struct Obj05461 *)p)->fC=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(0x24))==0) ((struct Obj05461 *)p)->f10=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(0x28))==0) ((struct Obj05461 *)p)->f4=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)func_021DD044(0x27))==0) ((struct Obj05461 *)p)->f0=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,d_021E2F7C)==0) ((struct Obj05461 *)p)->f14=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,d_021E2F8C)==0) {
                const struct Blob *blob=&f->payload.blob;
                MI_CpuCopy8(blob->data,p+24,blob->size);
            }
        }
    }
}







void func_021DBB00(int count, char **rows, int *out, int width)
{
    int i, j;
    char *record;
    for (i = 0; i < count; i++) {
        for (j = 0; j < width; j++) {
            record = rows[i] + j * 16;
            if (GF_STANDARD_CompareString(*(char * *)&((struct Obj14343 *)record)->f0, d_021E2F70) == 0)
                *out = ((struct Obj14343 *)record)->f8;
        }
    }
}





void func_021DBB54(int count,struct Field_021DBB54 **recs,void *dst,int nfields)
{
    int i,j;
    struct Field_021DBB54 *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(GF_STANDARD_CompareString(f->name,d_021E2F8C)==0)
                MI_CpuCopy8(f->value,dst,f->size);
        }
    }
}




void func_021DBBAC(int count,struct Field **recs,void *dst,int nfields)
{
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(GF_STANDARD_CompareString(f->name,d_021E2F38)==0)
                MI_CpuCopy8(f->value,dst,f->size);
        }
    }
}





void func_021DBC04(u8 *p,u32_021DBC04 mode,struct Record *src)
{
    ((struct Obj00312 *)p)->f12C=0;
    if(**(u32_021DBC04 * *)&((struct Obj00312 *)p)->f1464==0)func_02034714((const char *)((int)d_021E2EF8),0,(const char *)((int)d_021E2EF8));
    switch(mode) {
    case 0:
        ((struct Obj24359 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f0=func_021DD044(36);
        ((struct Obj24360 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f4=2;
        ((struct Obj24361 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f8=1500;
        ((struct Obj24362 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f10=func_021DD044(39);
        ((struct Obj24363 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f14=2;
        ((struct Obj24364 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f18=0;
        ((struct Obj24365 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f20=func_021DD044(40);
        ((struct Obj24366 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f24=2;
        ((struct Obj24367 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f28=0;
        ((struct Obj24368 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f30=func_021DD044(38);
        ((struct Obj24369 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f34=2;
        ((struct Obj24370 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f38=0;
        ((struct Obj24371 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f40=func_021DD044(37);
        ((struct Obj24372 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f44=2;
        ((struct Obj24373 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f48=0;
        ((struct Obj24374 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f50=(u32_021DBC04)d_021E2F8C;
        ((struct Obj24375 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f54=8;
        ((struct Obj24376 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f58=(u32_021DBC04)src;
        ((struct Obj24377 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f5C=1332;
        ((struct Obj00312 *)p)->f198=6;
        break;
    case 1:
        func_021DA470(p+0x38);
        ((struct Obj00312 *)p)->f198=1;
        ((struct Obj24378 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f0=(u32_021DBC04)d_021E2F38;
        ((struct Obj24379 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f4=8;
        ((struct Obj24380 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f8=(u32_021DBC04)(p+0x38);
        ((struct Obj24381 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->fC=6;
        break;
    case 2:func_021DB6A8((char *)p);break;
    case 3:
        *(struct Record *)(p+0x1c4)=*src;
        ((struct Obj00312 *)p)->f198=2;
        ((struct Obj24382 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f0=d_021E2DF8[((struct Obj00312 *)p)->f214];
        ((struct Obj24383 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f4=8;
        ((struct Obj24384 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f8=(u32_021DBC04)(p+0x1c4);
        ((struct Obj24385 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->fC=80;
        ((struct Obj24386 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f10=(u32_021DBC04)d_021E2F7C;
        ((struct Obj24387 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f14=0;
        ((struct Obj24388 *)(*(u8 * *)&((struct Obj00312 *)p)->f190))->f18=(((struct Obj00312 *)p)->f214+1)%6;
        break;
    }
}






/*
 * lever: PC-relative slot audit binds error/cancel/timeout lines to 0x11a0,0x11be,0x11ca; fixing source constants removes three pool-byte mismatches.
 * extent: existing matched ov175_func_021DBFA4.c covers the final16 bytes; keep this504-byte lead alone.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives live entry r0 in case 4 despite its unused parameter.
 */
int func_021DBDAC(char *p)
{
    long r;
    switch(((struct Obj00999 *)p)->f12C) {
    case 0:
        r=((int (*)(int,DWCstAccUserData *,int))DWC_GdbInitialize)(0xb5f,*(DWCstAccUserData * *)&((struct Obj00999 *)p)->f0,0);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1161);func_021DB6A0(p);return 2;}
        ((struct Obj00999 *)p)->f12C=1;break;
    case 1:
        if(((struct Obj00999 *)p)->f198>=0x26)func_02034714(d_021E2EF8,0,d_021E2EF8);
        r=DWC_GdbUpdateRecordAsync((char *)d_021E2F1C,**(int * *)&((struct Obj00999 *)p)->f1464,((struct Obj00999 *)p)->f190,((struct Obj00999 *)p)->f198);
        if(r!=0) {func_021DCE40(p+0x18,r,0x116e);func_021DB6A0(p);return 2;}
        ((struct Obj00999 *)p)->f1A0=0;((struct Obj00999 *)p)->f12C=2;break;
    case 2:
        if((((struct Obj00999 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x117b);((struct Obj00999 *)p)->f12C=6;break;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {func_021DCE48(p+0x18,r,0x1186);((struct Obj00999 *)p)->f12C=6;}
        else if(r==1)((struct Obj00999 *)p)->f12C=3;
        break;
    case 3:
        r=DWC_GdbGetAsyncResult();
        if(r==0) {func_021DCE50(p+0x18,r,0x1199);((struct Obj00999 *)p)->f12C=6;}
        else if(r!=1) {func_021DB6A0(p);func_021DCE50(p+0x18,r,0x11a0);return 2;}
        else ((struct Obj00999 *)p)->f12C=4;
        break;
    case 4:
        func_021DB6A0(p);((struct Obj00999 *)p)->f12C=5;
    case 5:return 1;
    case 6:
        r=DWC_GdbCancelRequest();
        if(r==0) {((struct Obj00999 *)p)->f1A0=0;((struct Obj00999 *)p)->f12C=7;}
        else {func_021DCE40(p+0x18,r,0x11be);func_021DB6A0(p);return 2;}
        break;
    case 7:
        if((((struct Obj00999 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x11ca);func_021DB6A0(p);return 2;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {func_021DB6A0(p);return 2;}
        if(r==1)((struct Obj00999 *)p)->f12C=8;
        break;
    case 8:func_021DB6A0(p);return 2;
    }
    return 0;
}






/*
 * leaf: reset request step then prepare four database fields.
 */
void func_021DBFA4(char *ctx)
{
    ((struct Obj01171 *)ctx)->f12C = 0;
    func_021DB6A8(ctx);
}






/*
 * lever: PC-relative pool audit binds source-line constants 125c/126f/127b to the success/cancel-error/timeout calls, fixing the prior three concrete pool bytes.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives p where the caller visibly prepares r0.
 */
int func_021DBFB4(char *p)
{
    long r;
    switch(((struct Obj00629 *)p)->f12C) {
    case 0:
        r=((int (*)(int,DWCstAccUserData *,int))DWC_GdbInitialize)(0xb5f,*(DWCstAccUserData * *)&((struct Obj00629 *)p)->f0,0);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1215);return 2;}
        ((struct Obj00629 *)p)->f12C=1;break;
    case 1:
        r=DWC_GdbCreateRecordAsync((char *)d_021E2F1C,((struct Obj00629 *)p)->f190,((struct Obj00629 *)p)->f198,*(int * *)&((struct Obj00629 *)p)->f1464);
        if(r!=0) {func_021DCE40(p+0x18,r,0x1223);return 2;}
        ((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=2;break;
    case 2:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x122f);((struct Obj00629 *)p)->f12C=4;break;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {func_021DCE48(p+0x18,r,0x123b);((struct Obj00629 *)p)->f12C=4;}
        else if(r==1)((struct Obj00629 *)p)->f12C=3;
        break;
    case 3:
        r=DWC_GdbGetAsyncResult();
        if(r==0) {func_021DCE50(p+0x18,r,0x124f);((struct Obj00629 *)p)->f12C=4;}
        else if(r!=1) {func_021DB6A0(p);func_021DCE50(p+0x18,r,0x1256);return 2;}
        else {
            if(**(u32_021DBFB4 * *)&((struct Obj00629 *)p)->f1464==0)func_021DCE08(p+0x18,2,0x125c);
            func_021DB6A0(p);return 1;
        }
        break;
    case 4:
        r=DWC_GdbCancelRequest();
        if(r==0) {((struct Obj00629 *)p)->f1A0=0;((struct Obj00629 *)p)->f12C=5;}
        else {func_021DCE40(p+0x18,r,0x126f);func_021DB6A0(p);return 2;}
        break;
    case 5:
        if((((struct Obj00629 *)p)->f1A0)++>0xe10) {func_021DCE08(p+0x18,1,0x127b);func_021DB6A0(p);return 2;}
        DWC_GdbProcess();r=DWC_GdbGetState();
        if(r==0||r==4) {func_021DB6A0(p);return 2;}
        if(r==1)((struct Obj00629 *)p)->f12C=6;
        break;
    case 6:func_021DB6A0(p);return 2;
    }
    return 0;
}







/*
 * Two-level dereference: the pointer the object holds at +0x1464, then
 *     the word it points at.  Both loads are register-offset, so the listing
 *     pools one plain literal 0x1464.
 */
u32_021DC194 func_021DC194(char *obj)
{
    return *(u32_021DC194 *)(((struct Obj24391 *)obj)->f1464);
}







/*
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2401, size + 0xd4, data, 1, 1, 1); size is 0x0201A918's constant.
 */
u32_021DC1A0 func_021DC1A0(char *obj, u32_021DC1A0 data)
{
    u32_021DC1A0 busy = GFL_NET_GetHandleNetID((struct Link *)((u32_021DC1A0)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return GFL_NET_SendData((u32_021DC1A0)GFL_NET_HANDLE_GetCurrentHandle(), (u8)flag, 0x2401, POKE_REGULATION_GetDataSize() + 0xd4, data, 1, 1, 1);
}







/*
 * Take-and-clear: returns the word at +0x13c; when it is set, clears it and hands back the address of the +0x218 block through out.
 */
u32_021DC1E4 func_021DC1E4(char *obj, char **out)
{
    u32_021DC1E4 v = ((struct Obj14344 *)obj)->f13C;
    if (v != 0) {
        ((struct Obj14344 *)obj)->f13C = 0;
        *out = obj + 0x218;
    }
    return v;
}






u32_021DC200 func_021DC200(char *p,unsigned int data)
{
    unsigned int busy=GFL_NET_GetHandleNetID((struct Link *)((unsigned int)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag=1;
    if(busy!=0) flag=0;
    return GFL_NET_SendData((unsigned int)GFL_NET_HANDLE_GetCurrentHandle(),(unsigned char)flag,0x2403,POKE_REGULATION_GetDataSize(),data,1,1,1);
}







/*
 * Takes and clears the +0x144 block; when there was one, calls
 *     0x0201A918(0) and hands its result to 0x02082D44 together with the
 *     object's +0x218 port block and the caller's second argument.  Returns
 *     the block it took.
 */
u32_021DC240 func_021DC240(char *obj, u32_021DC240 arg)
{
    u32_021DC240 v = ((struct Obj14345 *)obj)->f144;

    if (v != 0) {
        ((struct Obj14345 *)obj)->f144 = 0;
        MI_CpuCopy8(obj + 0x218, (void *)arg, POKE_REGULATION_GetDataSize());
    }
    return v;
}







/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x0201A918
 * The call at +0x14 targets 0x0201A918, which has no label in the ARM9
 * listings and no branch to it from outside this function, so it fails
 * both the `label` and `sole-ref/code` classes.  Bytes are exact.
 */


/*
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2404, 4, data, 1, 1, 1); flag is 1 unless 0x0203D1A4 reports the link busy.
 */
int func_021DC268(char *obj, u32_021DC268 data)
{
    u32_021DC268 busy = GFL_NET_GetHandleNetID((struct Link *)((u32_021DC268)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return GFL_NET_SendData((u32_021DC268)GFL_NET_HANDLE_GetCurrentHandle(), (u8)flag, 0x2404, 4, data, 1, 1, 1);
}







u32_021DC2A0 func_021DC2A0(char *obj, u32_021DC2A0 arg)
{
    u32_021DC2A0 v = ((struct Obj14346 *)obj)->f148;

    if (v != 0) {
        ((struct Obj14346 *)obj)->f148 = 0;
        MI_CpuCopy8(obj + 0x218, (void *)arg, 4);
    }
    return v;
}







/*
 * Tagged log/emit: the tick from 0x020399A8, the id 0x2405, a length of
 *     4 and the caller's pointer go to 0x0203D3A8, which is the four-argument
 *     form the listing loads straight into r2/r3.
 */
int func_021DC2C0(u32_021DC2C0 ignored, void *p)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2405, 4, (u32_021DC2C0)p);
}







/*
 * Take-and-clear: returns the word at +0x14c; when it is set, clears it and hands back the word at +0x150 through out.
 */
u32_021DC2D8 func_021DC2D8(char *obj, u32_021DC2D8 *out)
{
    u32_021DC2D8 v = ((struct Obj10689 *)obj)->f14C;
    if (v != 0) {
        ((struct Obj10689 *)obj)->f14C = 0;
        *out = ((struct Obj10689 *)obj)->f150;
    }
    return v;
}






void func_021DC2F4(char *p,unsigned a)
{
    ((struct Obj14347 *)p)->f12C=0;
    ((struct Obj14347 *)p)->f1458=0;
    MI_CpuFill8(p+0x144c,0,10);
    MI_CpuFill8(p+0x1390,0,0xb0);
    func_0208D7E0(p+0x144c,d_021E2FA4,a);
}






/*
 * lever: case-local repeated error call+break reproduces merged error block and long-branch layout; tail goto displaced it.
 * extent: unlabelled28-byte zero-word test021DC5AC filed separately.
 */
int func_021DC338(u8 *p)
{
    u32_021DC338 count,percent;
    switch(((struct Obj00841 *)p)->f12C) {
    case 0:
        if(DWC_NdInitAsync((void (*)(int,  int,  int))func_021DC6FC,d_021E2FA8,d_021E2FB0)==0)return 3;
        ((struct Obj00841 *)p)->f1458=1;
        func_021DC680(p,1);break;
    case 1:
        if(DWC_NdSetAttr(d_021E2FC4,(char *)(p+0x144c),(char *)d_021E2EF8)==0){func_021DC6A4(p,8);break;}
        ((struct Obj00841 *)p)->f12C=2;break;
    case 2:
        if(DWC_NdGetFileListAsync(p+0x1390,0,1)==0){func_021DC6A4(p,8);break;}
        func_021DC680(p,3);break;
    case 3:
        count=0xb0;
        if(func_021DC5AC((const unsigned int *)(p+0x1390),0xb0)==0) {
            count+=0xb0;
            if(DWC_NdGetFileAsync(p+0x1390,(char *)(p+0x1230),count)==0){func_021DC6A4(p,8);break;}
            d_021E4B80[0]=0;*(u32_021DC338 *)(d_021E4B80+4)=0;
            ((struct Obj00841 *)p)->f12C=4;
        } else {
            if(DWC_NdCleanupAsync()==0) {((struct Obj00841 *)p)->f1458=0;return 2;}
            func_021DC680(p,7);
        }
        break;
    case 4:
        DWC_NdProcess();
        if((((struct Obj00841 *)p)->f1A0)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);func_021DC6D0(p,8);}
        if(d_021E4B80[0]==0) {
            if(DWC_NdGetProgress((u32_021DC338 *)(p+0x1444),(u32_021DC338 *)(p+0x1448))==1) {
                percent=_u32_div_f(((struct Obj00841 *)p)->f1444*100,((struct Obj00841 *)p)->f1448);
                if(((struct Obj00841 *)p)->f1440!=percent)((struct Obj00841 *)p)->f1440=percent;
            }
        } else {
            if(*(u32_021DC338 *)(d_021E4B80+4)!=0) {
                if(*(u32_021DC338 *)(d_021E4B80+4)==8)func_0200FA84();
                else func_021DC6A4(p,8);
            } else {
                if(DWC_NdCleanupAsync()==0) {((struct Obj00841 *)p)->f1458=0;return 3;}
                func_021DC680(p,5);
            }
        }
        break;
    case 5:((struct Obj00841 *)p)->f12C=6;break;
    case 6:
        if(REGULATION_Card_IsCrcValid((struct Reg2 *)(p+0x1230))!=0) {((struct Obj00841 *)p)->f1458=0;return 1;}
        ((struct Obj00841 *)p)->f1458=0;return 2;
    case 7:((struct Obj00841 *)p)->f1458=0;return 2;
    case 8:((struct Obj00841 *)p)->f1458=0;return 3;
    case 100:
        DWC_NdProcess();
        if((((struct Obj00841 *)p)->f1A0)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);func_021DC6D0(p,8);}
        if(*(u32_021DC338 *)(d_021E4B80+4)!=0) {
            if(*(u32_021DC338 *)(d_021E4B80+4)==8)func_0200FA84();
            else func_021DC6A4(p,8);
        }
        if(d_021E4B80[0]!=0) {
            d_021E4B80[0]=0;
            if(*(u32_021DC338 *)(d_021E4B80+4)==0)((struct Obj00841 *)p)->f12C=((struct Obj00841 *)p)->f130;
        }
        break;
    case 200:
        DWC_NdProcess();
        if(d_021E4B80[1]!=0) {d_021E4B80[1]=0;((struct Obj00841 *)p)->f12C=((struct Obj00841 *)p)->f130;}
        break;
    case 300:
        DWC_NdProcess();
        if(d_021E4B80[0]!=0) {d_021E4B80[0]=0;func_021DC6A4(p,((struct Obj00841 *)p)->f130);}
        break;
    }
    return 0;
}






/*
 * lever: unlabelled zero-word test blocking matched caller021DC338.
 */
int func_021DC5AC(const u32_021DC5AC *p,u32_021DC5AC bytes)
{
    u32_021DC5AC i;
    for(i=0;i<(bytes>>2);i++)if(p[i]!=0)return 0;
    return 1;
}







/*
 * note:     the listing extent (72 B) runs into the neighbour's `mov r8,r8`
 *           pad and pool word; all 48 compiled bytes match.
 *
 * Kind 3 or 6 teardown of the +0x121c sub-object: its handle is unregistered
 * from both pools, the slot cleared, and the object recomputed.
 */
void func_021DC5C8(void *p, int unused, int kind)
{
    if (kind != 3 && kind != 6)
        return;
    if (((struct Obj03320 *)p)->f121C != 0) {
        NHTTP_RAP_DeleteConnection((u8 *)(((struct Obj03320 *)p)->f121C));
        NHTTP_RAP_Destroy((u8 *)(((struct Obj03320 *)p)->f121C));
        ((struct Obj03320 *)p)->f121C = 0;
    }
    func_021DAE18(p);
}






u32_021DC5F8 func_021DC5F8(char *p, int a, int kind)
{
    if (kind == 3 || kind == 6) return *(u32_021DC5F8 *)(p + 0x1458);
    return 0;
}







/*
 * note:     the listing extent (148 B) covers the following leaf and pool
 *           words as well; every compiled byte of this 92-byte body matches.
 *
 * Thumb jump table over 0..9: the startup mode reports 0x34..0x3b from its own
 * single-return blocks, mode 0 runs the 0x02034714 job with the 0x021E2EF8
 * record on both the first and third argument and reports 0, and mode 9 shares
 * the default's 0x3c block (stacked `case 9: default:` labels, which is what
 * keeps the table at ten entries and the block count at nine).
 */
int func_021DC610(unsigned int a)
{
    switch (a) {
    case 0:
        func_02034714((const char *)((int)g_021E2EF8), 0, (const char *)((int)g_021E2EF8));
        return 0;
    case 1:
        return 0x34;
    case 2:
        return 0x35;
    case 3:
        return 0x36;
    case 4:
        return 0x37;
    case 5:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3a;
    case 8:
        return 0x3b;
    case 9:
    default:
        return 0x3c;
    }
}






void func_021DC66C(const char *p,void *out)
{
    MI_CpuCopy8(p+0x1230,out,0x160);
}






/*
 * lever: unlabelled asynchronous state setter blocking matched caller021DC338.
 */
void func_021DC680(u8 *p,int state)
{
    d_021E4B80[0]=0;
    *(u32_021DC680 *)(d_021E4B80+4)=0;
    ((struct Obj10690 *)p)->f130=state;
    ((struct Obj10690 *)p)->f12C=100;
    ((struct Obj10690 *)p)->f1A0=0;
}






void func_021DC6A4(u8 *p,int state) { d_021E4B80[0]=0; *(u32_021DC6A4 *)(d_021E4B80+4)=0; ((struct Obj10691 *)p)->f130=state; ((struct Obj10691 *)p)->f12C=200; if(DWC_NdCleanupAsync()==0) ((struct Obj10691 *)p)->f130=state; }






void func_021DC6D0(u8 *p,int state) { d_021E4B80[0]=0; *(u32_021DC6D0 *)(d_021E4B80+4)=0; ((struct Obj10692 *)p)->f130=state; ((struct Obj10692 *)p)->f12C=300; if(DWC_NdCancelAsync()==0) ((struct Obj10692 *)p)->f130=state; }






void func_021DC6FC(void *p,u32_021DC6FC kind) { switch(kind) { case 0:case 1:case 2:case 3:case 4:case 5:case 7: break; case 6:case 8: func_0200FA84(); break; } d_021E4B80[0]=1; *(u32_021DC6FC *)(d_021E4B80+4)=kind; d_021E4B80[1]=1; }






void func_021DC738(char *p,unsigned heap)
{
    if(*(int *)&((struct Obj06575 *)p)->f121C!=0) func_02034714(d_021E2EF8,0,d_021E2EF8);
    ((struct Obj06575 *)p)->f12C=0;
    ((struct Obj06575 *)p)->f121C=NHTTP_RAP_Create(heap,func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj06575 *)p)->f8)),((struct Obj06575 *)p)->f10);
}






/*
 * checks: 1 copied own ov114/DC610 signatures and ARM9 blocker input reads; 2 existing DC8A0 Pair twin used; 3 Pair replaces scalar two-word copy; 4 aggregate-copy idioms applied; 5 fresh directory and ov175 neighbours read. Caller TU MATCH has no viable split; only ARM90200FB4C blocks it.
 * lever: Pair aggregate assignment fixes all four payload-copy register bytes; TU --suggest-split confirms MATCH, no viable cut.
 * extent: lead 292 bytes; following 20-byte DC8A0 is already B7's src/matched/ov/ov175_func_021DC8A0.c.
 */
int func_021DC77C(u8 *p)
{
    int query,status;
    const u8 *r;
    if(*(u8 **)(p+0x121c)==0)return 2;
    switch(*(u32_021DC77C *)(p+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreateRequest(5,*(u8 **)(p+0x121c))!=0)*(u32_021DC77C *)(p+0x12c)=1;
        break;
    case 1:
        if(NHTTP_RAP_StartConnection(*(u8 **)(p+0x121c))==0) {*(u32_021DC77C *)(p+0x12c)=2;break;}
        if(*(u8 **)(p+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;}
        return 2;
    case 2:
        query=NHTTP_RAP_GetResultCode(*(u8 **)(p+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(p+0x121c));
        if(status==0) {
            r=NHTTP_RAP_GetRecvBuffer(*(u8 **)(p+0x121c));
            if(query!=0x1f6) {
                if(query==0x1f7) {*(u32_021DC77C *)(p+0x12c)=4;GFL_NET_ERR_RaiseFatal(62);return 0;}
            } else {*(u32_021DC77C *)(p+0x12c)=4;GFL_NET_ERR_RaiseFatal(63);return 0;}
            *(Pair *)(p+0x1220)=*(const Pair *)(r+0x80);
            if(*(u32_021DC77C *)r==0)*(u32_021DC77C *)(p+0x12c)=3;
            else {GFL_NET_ERR_RaiseFatal(func_021DC610(*(u32_021DC77C *)r));*(u32_021DC77C *)(p+0x12c)=4;}
        } else if(status!=15) {
            if(*(u8 **)(p+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 4:
        MI_CpuFill8(p+0x1220,0,8);
        if(*(u8 **)(p+0x121c)!=0) {
            NHTTP_RAP_DeleteConnection(*(u8 **)(p+0x121c));NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;
        }
        return 3;
    case 3:
        if(*(u8 **)(p+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u32_021DC77C *)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}






/*
 * Pair aggregate assignment preserves the forward load and store order.
 * leaf: coordinated transfer from B10's extent to unblock 021D6C54.
 */
void func_021DC8A0(const Obj *p,Pair *out)
{
    *out=*(const Pair *)((const char *)p+0x1220);
}






void func_021DC8B4(u8 *p, const W *src, int x)
{
    if (*(u32_021DC8B4 *)(p + 0x121C) != 0)
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
    *(u8 **)(p + 0x121C) = NHTTP_RAP_Create(x, func_0200853C((const struct Sub0200852CObj *)func_02012944(*(void **)(p + 8))), *(int *)(p + 0x10));
    *(W *)(p + 0x1228) = *src;
    *(u32_021DC8B4 *)(p + 0x12C) = 0;
}






int func_021DC908(char *p)
{
    int result;
    int status;
    u32_021DC908 *data;
    if(*(u8 **)(p+0x121c)==0) return 2;
    switch(*(u32_021DC908 *)(p+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreateRequest(6,*(u8 **)(p+0x121c))) {
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(*(char **)(p+0x121c)),(void *)((u32_021DC908)(p+0x1228)),8);
            *(u32_021DC908 *)(p+0x12c)=1;
        }
        break;
    case 1:
        if(!NHTTP_RAP_StartConnection(*(u8 **)(p+0x121c))) *(u32_021DC908 *)(p+0x12c)=2;
        else {
            if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 2:
        result=NHTTP_RAP_GetResultCode(*(u8 **)(p+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(p+0x121c));
        if(status==0) {
            data=(u32_021DC908 *)NHTTP_RAP_GetRecvBuffer(*(u8 **)(p+0x121c));
            switch(result) {
            case 0x1f7: *(u32_021DC908 *)(p+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3e);return 0;
            case 0x1f6: *(u32_021DC908 *)(p+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3f);return 0;
            default:
                if(*data==0) *(u32_021DC908 *)(p+0x12c)=4;
                else {GFL_NET_ERR_RaiseFatal(func_021DC610(*data));*(u32_021DC908 *)(p+0x12c)=3;}
                break;
            }
        } else if(status!=15) {
            func_021DCE58(p+0x18,status,0x16a0);
            if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 3:
        if(*(u8 **)(p+0x121c)) {
            NHTTP_RAP_DeleteConnection(*(u8 **)(p+0x121c));
            NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));
            *(u8 **)(p+0x121c)=0;
        }
        return 3;
    case 4:
        if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}







/*
 * Starts a profanity check of the string in window a1: copies it into the 20-character buffer at +0x1468 (the terminator code 0x02045A98 returns becomes 0), and submits it with DWC_CheckProfanityExAsync (one word, results at +0x1484/+0x1488, region 0x80).
 */
void func_021DCA28(char *obj, u32_021DCA28 win, u16 tag)
{
    u32_021DCA28 str;
    u16 *src;
    u32_021DCA28 i;

    ((struct Obj06576 *)obj)->f1490 = win;
    str = (u32_021DCA28)func_02008510((void *)win, ((struct Obj06576 *)obj)->f124);
    MI_CpuFill8(obj + 0x1468, 0, 0x28);
    ((struct Obj06576 *)obj)->f148C = tag;
    src = STRBUF_GetChars((struct U16Vec *)str);
    for (i = 0; i < STRBUF_GetLength((struct U16Vec *)str) + 1; i++) {
        u16 c = src[i];
        if (c == STRBUF_GetEosChar())
            *(u16 *)(obj + 0x1468 + i * 2) = 0;
        else
            *(u16 *)(obj + 0x1468 + i * 2) = c;
    }
    *(u16 * *)&((struct Obj06576 *)obj)->f1480 = (u16 *)(obj + 0x1468);
    ((struct Obj06576 *)obj)->f1488 = 0;
    DWC_CheckProfanityExAsync((u16 **)(obj + 0x1480), 1, 0, 0, obj + 0x1484, (int *)(obj + 0x1488), 0x80);
    STRBUF_Delete((struct U16Vec *)str);
}







/*
 * Polls the profanity check; once it has finished (state 2) reports whether the +0x1488 count is positive, and when it is, loads message 0x51 for the +0x124 id and hands it to the +0x1490 window.
 */
int func_021DCAEC(char *obj, int *out)
{
    int state = DWC_CheckProfanityProcess();
    int done = 1;

    if (state != 2)
        done = 0;
    if (done)
        *out = ((struct Obj10693 *)obj)->f1488 > 0 ? 1 : 0;
    if (done == 1 && *out == 1) {
        u32_021DCAEC msg = (u32_021DCAEC)func_02045B38(0, 2, 0x51, ((struct Obj10693 *)obj)->f124);
        u32_021DCAEC str = (u32_021DCAEC)func_02045EC0((struct MsgBank *)msg, 0xf);
        MSGDATA_Delete((struct Rec *)msg);
        func_020084E4((u16 *)((struct Obj10693 *)obj)->f1490, (struct U16Vec *)str);
        STRBUF_Delete((struct U16Vec *)str);
    }
    return done;
}






void func_021DCB58(char *p,void *q,int mode)
{
    int i;
    unsigned size;
    void *mon;
    i=0;
    ((struct Obj01956 *)p)->f12C=0;
    *(u8 * *)&((struct Obj01956 *)p)->f121C=NHTTP_RAP_Create(((struct Obj01956 *)p)->f124,(int)func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj01956 *)p)->f8)),((struct Obj01956 *)p)->f10);
    switch(mode) {
    case 0:
        NHTTP_RAP_AllocPostData(*(u8 * *)&((struct Obj01956 *)p)->f121C,((struct Obj01956 *)p)->f124,func_020173EC(),0);
        NHTTP_RAP_AppendPostData(*(u8 * *)&((struct Obj01956 *)p)->f121C,(int)q,func_020173EC());
        ((struct Obj01956 *)p)->f174=1;
        break;
    case 1:
        size=func_020173EC();
        NHTTP_RAP_AllocPostData(*(u8 * *)&((struct Obj01956 *)p)->f121C,((struct Obj01956 *)p)->f124,size*POKEPARTY_GetCount(q),0);
        for(i=0;i<(int)POKEPARTY_GetCount(q);i++) {
            mon=POKEPARTY_GetMember(q,i);
            NHTTP_RAP_AppendPostData(*(u8 * *)&((struct Obj01956 *)p)->f121C,(int)mon,func_020173EC());
        }
        ((struct Obj01956 *)p)->f174=POKEPARTY_GetCount(q);
        break;
    }
}






static inline void clear(char *p)
{
    if(*(u8 **)(p+0x121c)) {
        NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));
        *(u8 **)(p+0x121c)=0;
        *(u32_021DCC28 *)(p+0x12c)=0;
    }
}






static inline void release(char *p)
{
    if(*(u8 **)(p+0x121c)) {
        NHTTP_RAP_FreePostData(*(u8 **)(p+0x121c));
        NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));
        NHTTP_RAP_DeleteConnection(*(u8 **)(p+0x121c));
        *(u8 **)(p+0x121c)=0;
        *(u32_021DCC28 *)(p+0x12c)=0;
    }
}






/*
 * blocker-C: copied verified32B Thumb EXACT from ov116_func_021D7200.c header, prior scratch blocker-1.log, dsi/1.1p1 -O4,p.
 * extern unsigned char gNetErrWork[],g_021461BC[];
 * void GFL_NET_ERR_RaiseFatal(int a) {
 *   if(*(int *)(gNetErrWork+44)!=2) {
 *     *(int *)(gNetErrWork+96)=a;
 *     g_021461BC[26]=1;g_021461BC[25]=1;
 *     *(int *)(gNetErrWork+44)=2;
 *   }
 * }
 * Blocker symbols: gNetErrWork 0x0214617C data; g_021461BC 0x021461BC data.
 * abi: CE58 retains visibly loaded third argument despite its two-argument body; 9A14 reads live r1, the count last loaded by the loop.
 */
int func_021DCC28(char *p,u8 *out)
{
    int result;
    int status;
    u32_021DCC28 i;
    u8 *data;
    switch(*(u32_021DCC28 *)(p+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreatePostRequest(*(u8 **)(p+0x121c))) {
            if(!NHTTP_RAP_StartConnection(*(u8 **)(p+0x121c))) (*(u32_021DCC28 *)(p+0x12c))++;
            else {clear(p);return 2;}
        } else {clear(p);return 2;}
        break;
    case 1:
        result=NHTTP_RAP_GetResultCode(*(u8 **)(p+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(p+0x121c));
        if(status==0) {
            switch(result) {
            case 400: GFL_NET_ERR_RaiseFatal(0x41);release(p);return 3;
            case 401: GFL_NET_ERR_RaiseFatal(0x42);release(p);return 3;
            case 408: GFL_NET_ERR_RaiseFatal(0x44);release(p);return 3;
            default: GFL_NET_ERR_RaiseFatal(0x43);release(p);return 3;
            case 200: (*(u32_021DCC28 *)(p+0x12c))++;break;
            }
        } else if(status!=15) {
            func_021DCE58(p+0x18,status,0x17a4);
            NHTTP_RAP_FreePostData(*(u8 **)(p+0x121c));
            clear(p);
            return 2;
        }
        break;
    case 2:
        data=NHTTP_RAP_GetRecvBuffer(*(u8 **)(p+0x121c));
        *out=NHTTP_RAP_RecordList_GetCount(data);
        for(i=0;i<*(u32_021DCC28 *)(p+0x174);i++) *(u32_021DCC28 *)(out+4+i*4)=NHTTP_RAP_RecordList_GetValue((u32_021DCC28)data,i);
        if(*out==0) MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(data,*(u32_021DCC28 *)(p+0x174)),out+0x1c,128);
        NHTTP_RAP_FreePostData(*(u8 **)(p+0x121c));
        if(*(u8 **)(p+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}







/*
 * The +0x14 sibling of func_021DCE58: stores the caller's word at +0x18,
 *     hard-codes 5 at +0x1c and then calls 0x0203C9AC(0, 0, 0, 0x3F5).
 */
void func_021DCE08(char *ctx, u32_021DCE08 v, int line)
{
    ((struct Obj14349 *)ctx)->f18 = v;
    ((struct Obj14349 *)ctx)->f1C = 5;
    GFL_NET_STATE_SetError(0, 0, 0, 0x3F5);
}







/*
 * Set the word at +0 and mark the object armed at +0x1c, then start the
 * 0x3f7 service with a zeroed first three arguments.
 */
void func_021DCE24(char *p, int v, int a2)
{
    ((struct Obj14350 *)p)->f0 = v;
    ((struct Obj14350 *)p)->f1C = 1;
    GFL_NET_STATE_SetError(0, 0, 0, 0x3f7);
}







/*
 * Two-word setter: stores the caller's word at +4 and hard-codes 2 at +0x1c.
 */
void func_021DCE40(char *ctx, u32_021DCE40 v, int line)
{
    ((struct Obj14351 *)ctx)->f4 = v;
    ((struct Obj14351 *)ctx)->f1C = 2;
}







void func_021DCE48(char *ctx, u32_021DCE48 v, int line)
{
    ((struct Obj14352 *)ctx)->f8 = v;
    ((struct Obj14352 *)ctx)->f1C = 2;
}







/*
 * Two-word setter: stores the caller's word at +0xc and hard-codes 2 at +0x1c.
 */
void func_021DCE50(char *ctx, u32_021DCE50 v, int line)
{
    ((struct Obj14353 *)ctx)->fC = v;
    ((struct Obj14353 *)ctx)->f1C = 2;
}







/*
 * Symbols:
 *   (none)
 *
 * Two-word setter on an ov175 context block: stores the caller's word at
 * +0x14 and hard-codes 4 at +0x1c.  A leaf with no prologue, so disasm.py
 * only found it through a branch target.
 */
void func_021DCE58(char *ctx, u32_021DCE58 v, u32_021DCE58 a2)
{
    ((struct Obj14354 *)ctx)->f14 = v;
    ((struct Obj14354 *)ctx)->f1C = 4;
}







/*
 * Maps a code 0..14 to a class: 0 for code 0, 2 for codes 1 to 14; any other code asserts and yields 0.
 */
u32_021DCE60 func_021DCE60(int a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        return 2;
    case 4:
        return 2;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8:
        return 2;
    case 9:
        return 2;
    case 10:
        return 2;
    case 11:
        return 2;
    case 12:
        return 2;
    case 13:
        return 2;
    case 14:
        return 2;
    }
    func_02034714(d_021E2EF8, 0, d_021E2EF8);
    return 0;
}







/*
 * Three-level classifier: the first code decides when it can (1 or 2); codes 0 and 20 and unknown ones fall to the second, then the third; 0 when none decides.
 */
u32_021DCEE0 func_021DCEE0(int a, int b, int c)
{
    switch (a) {
    case 0:
        break;
    case 1: case 2: case 3: case 4: case 5:
        return 2;
    case 6: case 7: case 8: case 9: case 10: case 11:
    case 12: case 13: case 14: case 15: case 16:
        return 1;
    case 17: case 18:
        return 2;
    case 19:
        return 1;
    case 20:
        break;
    case 21: case 22:
        return 2;
    }
    switch (b) {
    case 0:
        return 1;
    case 1: case 2: case 3:
        break;
    case 4:
        return 2;
    }
    switch (c) {
    case 0: case 1:
        break;
    case 2:
        return 2;
    case 3:
        return 2;
    case 4:
        return 1;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8: case 9: case 10:
        return 2;
    case 11: case 12: case 13: case 14: case 15: case 16:
        return 1;
    case 17: case 18: case 19: case 20: case 21:
        return 1;
    case 22:
        return 2;
    case 23: case 24: case 25: case 26: case 27:
        return 1;
    case 28: case 29:
        return 2;
    case 30: case 31:
        return 2;
    }
    return 0;
}







/*
 * Maps 0, 1, 2 to themselves and everything else to 0.
 */
u32_021DCFDC func_021DCFDC(u32_021DCFDC v)
{
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 0;
}







/*
 * Tail call: clears the second and third arguments to 0 and 0x20 and
 *  *  hands r0 straight to 0x02082BCC (arm9); no lr save, so the call is a
 *  *  pooled `ldr r3; bx r3`.
 */
void func_021DCFFC(void *p)
{
    MI_CpuFill8(p, 0, 0x20);
}







void func_021DD008(char *p, int flag)
{
    if (flag == 0)
        return;
    GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj24396 *)p)->f124);
}







/*
 * Tail call to the arm9 Thumb routine 0x02009CC0 with the object's
 *  *  +0x04 field; pooled `ldr r3; bx r3`, so nothing is saved.
 */
u32_021DD020 func_021DD020(char *obj)
{
    return WIFILIST_GetGsProfileId((void *)(((struct Obj24397 *)obj)->f4));
}







/*
 * Returns the address of the ov175 table at 0x021E3270.
 */
char *func_021DD02C(void)
{
    return d_021E3270;
}







/*
 * Constant getter: returns 0x15.
 */
u32_021DD034 func_021DD034(void)
{
    return 0x15;
}







/*
 * Returns the address of the ov175 table at 0x021E3250.
 */
char *func_021DD038(void)
{
    return d_021E3250;
}







/*
 * Constant getter: returns 8.
 */
u32_021DD040 func_021DD040(void)
{
    return 8;
}







int func_021DD044(int a)
{
    if (a <= 0)
        return (int)g_021E32C4;
    if (a == 0x1e)
        return (int)g_021E32C8;
    if (a == 0x14)
        return (int)g_021E32E0;
    if (a == 0x15)
        return (int)g_021E32FC;
    if (a == 0x17)
        return (int)g_021E3318;
    if (a == 0x13)
        return (int)g_021E3338;
    if (a == 0x16)
        return (int)g_021E3354;
    if (a == 0x24)
        return (int)g_021E3370;
    if (a == 0x19)
        return (int)g_021E3390;
    if (a == 0x1a)
        return (int)g_021E33B0;
    if (a == 0x1c)
        return (int)g_021E33D0;
    if (a == 0x23)
        return (int)g_021E33E8;
    if (a == 0x1d)
        return (int)g_021E3400;
    if (a == 0x1f)
        return (int)g_021E3418;
    if (a == 0x20)
        return (int)g_021E3430;
    if (a == 0x21)
        return (int)g_021E3448;
    if (a == 0x1b)
        return (int)g_021E3460;
    if (a == 0x18)
        return (int)g_021E347C;
    if (a == 0x27)
        return (int)g_021E348C;
    if (a == 0x4)
        return (int)g_021E34A4;
    if (a == 0x3)
        return (int)g_021E34C0;
    if (a == 0x28)
        return (int)g_021E34D4;
    if (a == 0xb)
        return (int)g_021E34F0;
    if (a == 0xc)
        return (int)g_021E3508;
    if (a == 0xe)
        return (int)g_021E3520;
    if (a == 0xd)
        return (int)g_021E3538;
    if (a == 0x12)
        return (int)g_021E3550;
    if (a == 0x11)
        return (int)g_021E356C;
    if (a == 0xa)
        return (int)g_021E3584;
    if (a == 0x9)
        return (int)g_021E359C;
    if (a == 0x10)
        return (int)g_021E35B4;
    if (a == 0xf)
        return (int)g_021E35CC;
    if (a == 0x26)
        return (int)g_021E35E4;
    if (a == 0x25)
        return (int)g_021E3600;
    if (a == 0x22)
        return (int)g_021E3618;
    return (int)g_021E32C4;
}
