/*
 * file:     fieldmap.c
 * unit:     yes
 * function: FIELDMAP_ProcInit, FIELDMAP_ProcMain, FIELDMAP_ProcExit, FIELDMAP_Create, FIELDMAP_Delete, FIELDMAP_SeqInitSystem, FIELDMAP_SeqCreateSubsystems, FIELDMAP_SeqStart, FIELDMAP_SeqUpdate, FIELDMAP_UpdateCameraAndDraw, FIELDMAP_SeqUpdateTop, FIELDMAP_SeqDeleteSubsystems, FIELDMAP_SeqExitSystem, FIELDMAP_Main, FIELDMAP_RequestClose, FIELDMAP_IsReady, FIELDMAP_CheckPlayerRequest, FIELDMAP_GetMsgBg, FIELDMAP_GetCamera, FIELDMAP_GetNogridMapper, FIELDMAP_GetLight, FIELDMAP_GetFog, FIELDMAP_GetZoneFog, FIELDMAP_GetWeather, FIELDMAP_QueryIssSwitch, FIELDMAP_GetMmdlSys, FIELDMAP_GetGameSystem, FIELDMAP_GetHeapId, FIELDMAP_GetEffectBbdAct, FIELDMAP_GetGroundBbdAct, FIELDMAP_GetG3dMapper, FIELDMAP_GetZoneId, FIELDMAP_GetCtrlWork, FIELDMAP_SetCtrlWork, FIELDMAP_GetFieldPlayer, FIELDMAP_IsFieldPlayerCreated, FIELDMAP_GetSubscreen, FIELDMAP_GetEffect, FIELDMAP_GetG3dObjCtrl, FIELDMAP_GetUnionEff, FIELDMAP_GetEncount, FIELDMAP_GetCtrlType, FIELDMAP_GetMoveKind, FIELDMAP_GetPlaceName, FIELDMAP_GetMapFunc, FIELDMAP_GetExpObj, FIELDMAP_GetTcblSys, FIELDMAP_GetTaskManager, FIELDMAP_SetTargetPos, FIELDMAP_GetInfoWindow, FIELDMAP_SetInfoWindow, FIELDMAP_GetSodateya, FIELDMAP_GetAreaData, FIELDMAP_InitBgSystem, FIELDMAP_SetBgMode, FIELDMAP_ResetBgAffineShowMsg, FIELDMAP_ResetBgAffineHideMsg, FIELDMAP_GetVReq, FIELDMAP_ExitBgSystem, FIELDMAP_SetupG3d, FIELDMAP_CreateG3dResources, FIELDMAP_UpdateG3d, FIELDMAP_DrawStart, FIELDMAP_DrawEnd, FIELDMAP_DeleteG3dResources, FIELDMAP_VBlankTask, FIELDMAP_BbdActTransCallback, FIELDMAP_SetupEdgeMarking, FIELDMAP_SetupBbdColor, FIELDMAP_SetupMmdlSys, FIELDMAP_DeleteMmdlSys, FIELDMAP_UpdateZoneChange, FIELDMAP_CheckPlayerMoved, FIELDMAP_CheckZoneBoundary, FIELDMAP_ChangeZone, FIELDMAP_AddZoneNpcs, FIELDMAP_ChangeZoneSound, FIELDMAP_ChangeZoneWeather, FIELDMAP_ChangeZoneFog, FIELDMAP_SetPlayerZoneId, FIELDMAP_ChangeZoneCamera, FIELDMAP_ClearCtrlWork, FIELDMAP_SetupCameraArea, FIELDMAP_SetupWfbc, FIELDMAP_SetupSceneArea, FIELDMAP_GetCommKind, FIELDMAP_CheckCommExit, FIELDMAP_InitCommonWork, FIELDMAP_AllocCommonWork, FIELDMAP_FreeCommonWork, FIELDMAP_GetCommonWork, FIELDMAP_ReflectFog, FIELDMAP_Draw3dNormal, FIELDMAP_Draw3dParticle, FIELDMAP_Draw3dEncEff, FIELDMAP_GetDrawMode, FIELDMAP_SetDrawMode, FIELDMAP_GetFld3dCi, FIELDMAP_GetEncEff, FIELDMAP_GetMapEff, FIELDMAP_GetSceneArea, FIELDMAP_SetScriptEffectBusy, FIELDMAP_GetScriptEffectBusy, FIELDMAP_IsEventActive, FIELDMAP_GetTimeZone, FIELDMAP_GetSubscreenBusy, FIELDMAP_SetSubscreenBusy, FIELDMAP_SetUpdateStopped, FIELDMAP_GetFaceUpWorkPtr, FIELDMAP_SetZoneEffectWork, FIELDMAP_GetZoneEffectWork, FIELDMAP_GetCameraPitchScale, FIELDMAP_CalcCameraPitchScale, FIELDMAP_GetProjDepthOffset, FIELDMAP_IsMmdlDrawEnabled, FIELDMAP_IsLoaderWaitZone, FIELDMAP_GetMapType, FIELDMAP_SetupMapperParam, FIELDMAP_GetCtrlFuncs
 * address:  0x02187F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   FIELDMAP_GetHeapSizeForMapType  0x02189BBC  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_RegisterBlockHeap  0x02030678  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   ICA_ANIME_SetField20  0x02012110  thumb
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   sFieldMapHeapBuffer     0x021DE700  data
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   ZONEDATA_CreateAreaData  0x0201407C  thumb
 *   sFieldMapSourceName     0x021DD9C0  data  a4
 *   ZONEDATA_DeleteAreaData  0x020140B4  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_NET_WM_ICON_SetDefaultPos  0x020371AC  arm
 *   sVramBankSetup     0x021D3688  data
 *   sClactSetup     0x021D3604  data
 *   sBgModeSetup     0x021D35F4  data
 *   abs_id_19      0x00000013  data
 *   abs_id_18      0x00000012  data
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   GF_FONT_ResetTextColor  0x0201DD60  thumb
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_G3D_MAPPER_Create  0x0218C9E8  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   FIELD_TASK_MANAGER_Create  0x021C6D10  thumb
 *   FLD_VREQ_Create  0x021D317C  thumb
 *   ZONEDATA_IsZone1A6  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   func_02035660  0x02035660  arm
 *   FIELD_MAP_CHANGE_Empty  0x0216447C  thumb  ov010
 *   FIELD_MSGBG_Create  0x021901EC  thumb  ov021
 *   FIELD_PLACE_NAME_Create  0x021BC388  thumb  ov021
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetMapEffectMask  0x02014470  thumb
 *   FIELDSKILL_MAPEFF_Create  0x021C7F70  thumb  ov021
 *   func_02013BBC  0x02013BBC  thumb
 *   FIELD_CAMERA_Create  0x0218E018  thumb  ov021
 *   FLD_SCENEAREA_Create  0x021AB5F4  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Create  0x021AB7E4  thumb  ov021
 *   FIELD_NOGRID_MAPPER_Create  0x021BB1F4  thumb  ov021
 *   FIELD_PALACE_SYS_Create  0x021D33A8  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   FIELD_PALACE_SYS_GetPalTable  0x021D33F8  thumb  ov021
 *   FIELD_BUILDMODEL_LoadArea  0x0218B8AC  thumb  ov021
 *   FIELD_G3DOBJ_SetPalTable  0x021C6534  thumb  ov021
 *   ZONEDATA_SetExitLocation  0x02014110  thumb
 *   FIELD_G3D_MAPPER_Setup  0x0218CEE4  thumb  ov021
 *   ZONEDATA_GetSpecialKind  0x02013C9C  thumb
 *   FIELD_NOGRID_MAPPER_LoadDataFromArc  0x021BB2F8  thumb  ov021
 *   FIELD_EFFECT_Create  0x021ABD50  thumb  ov021
 *   FIELD_EFFECT_InitObjectSystem  0x021ABF68  thumb  ov021
 *   FIELD_EFFECT_SetPaletteTable  0x021AC1EC  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   sFieldEffectTaskCount     0x021D8F00  data
 *   sFieldEffectTaskTable     0x021D8F10  data
 *   UNION_EFF_Create  0x0217F8C0  thumb  ov019
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   ZONEDATA_IsBikeEnabled  0x02013C20  thumb
 *   GAME_DATA_SetPlayerObjectCode  0x02012B2C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   FIELD_PLAYER_Create  0x021A2E50  thumb  ov021
 *   FIELD_G3D_MAPPER_SetFocusPos  0x0218D158  thumb  ov021
 *   FLD_EXP_OBJ_Create  0x021BE2A8  thumb  ov021
 *   FIELD_FOG_Create  0x021A0104  thumb  ov021
 *   FIELD_ZONEFOG_Create  0x021A02C4  thumb  ov021
 *   func_02013EEC  0x02013EEC  thumb
 *   ZONEDATA_GetLightId  0x02013F2C  thumb
 *   FIELD_ZONEFOG_SetUp  0x021A0338  thumb  ov021
 *   ZONEDATA_GetAreaLightType  0x020140DC  thumb
 *   GF_STANDARD_GetTime  0x0203F4FC  arm
 *   FIELD_LIGHT_Create  0x021A03D0  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   WEATHER_Create  0x021A19E8  thumb  ov021
 *   GAME_DATA_GetSubscreenMode  0x02012994  thumb
 *   WEATHER_SetImmediate  0x021A1B74  thumb  ov021
 *   FIELD_GIMMICK_Setup  0x021BE1DC  thumb  ov021
 *   GAME_DATA_GetSubscreenType  0x020129AC  thumb
 *   FIELD_SUBSCREEN_Create  0x021A0CF4  thumb  ov021
 *   FIELD_ENCOUNT_Create  0x021A9ED8  thumb  ov021
 *   GAME_COMM_CallHandler  0x02026388  thumb
 *   FIELD_SUBPROC_MGR_Create  0x021BB890  thumb  ov021
 *   FLD_PARTICLE_Create  0x021C1A08  thumb  ov021
 *   FLD3D_CI_Create  0x021C1AF4  thumb  ov021
 *   ENCEFF_Create  0x021CF45C  thumb  ov021
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   DAYCARE_GetFromSave  0x0200BDB0  thumb
 *   SODATEYA_Create  0x021C31D4  thumb  ov021
 *   FIELD_G3D_MAPPER_UpdateBlocking  0x0218CA78  thumb  ov021
 *   FLDMMDL_UpdateSysProc  0x0216CD64  thumb  ov010
 *   FLDMMDL_BLACT_RegisterLoadedRes  0x0219C624  thumb  ov021
 *   FLDMMDL_BLACT_IsReservePending  0x0219C630  thumb  ov021
 *   WEATHER_IsTaskActive  0x021A1B50  thumb  ov021
 *   WEATHER_Update  0x021A1AF4  thumb  ov021
 *   CLACT_DrawSystem  0x0204A600  arm
 *   FIELD_MSGBG_Main  0x021903E0  thumb  ov021
 *   FIELD_EFFECT_Update  0x021ABE04  thumb  ov021
 *   FIELD_SUBPROC_MGR_RunUpdate  0x021BB948  thumb  ov021
 *   FIELD_STATUS_GetContinueFlag  0x02014460  thumb
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   func_02014458  0x02014458  thumb
 *   SCRIPT_SYS_RunFieldInitScript  0x02158AC8  thumb  ov010
 *   FIELD_STATUS_SetFieldInitFlag  0x02014454  thumb
 *   SCRIPT_SYS_RunFieldRecoverScript  0x02158AD4  thumb  ov010
 *   FIELD_STATUS_SetContinueFlag  0x0201445C  thumb
 *   GAMESYSTEM_SetEventCreator  0x0201209C  thumb
 *   GAME_DATA_SetWalkCountEnabled  0x020129DC  thumb
 *   FIELD_EVENT_CHECK_CheckCommEvents  0x0218A0E4  thumb  ov021
 *   FIELD_EVENT_CHECK_RunRail  0x0218A240  thumb  ov021
 *   FIELD_EVENT_CHECK_Run  0x0218A4BC  thumb  ov021
 *   FIELD_EVENT_CHECK_RunGrid  0x0218A074  thumb  ov021
 *   GAMESYSTEM_GetEvent  0x02012104  thumb
 *   FIELD_STATUS_SwapSeasonDispFlag  0x0201447C  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   func_02035648  0x02035648  arm
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   FIELD_CLOCK_Update  0x02168EEC  thumb  ov010
 *   FIELD_PLACE_NAME_Main  0x021BC484  thumb  ov021
 *   FIELDSKILL_MAPEFF_Update  0x021C7FAC  thumb  ov021
 *   FIELD_PLAYER_SaveToPlayerWork  0x021A2EB8  thumb  ov021
 *   UNION_MAIN_UpdateField  0x021737A4  thumb  ov012
 *   INTRUDE_FIELD_Update  0x0217AE20  thumb  ov018
 *   FIELD_SUBSCREEN_Main  0x021A0D68  thumb  ov021
 *   FIELD_GIMMICK_RunMapCallback  0x021BE258  thumb  ov021
 *   EVENT_COMM_COMMON_CmdCallMissionInfoEvent  0x0217F914  thumb  ov018
 *   TCB_Main  0x02030D28  arm
 *   FIELD_TASK_MANAGER_Update  0x021C6D90  thumb  ov021
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   PLEASURE_BOAT_AckEvent  0x021C8660  thumb  ov021
 *   G3D_SYSTEM_ResetDrawCounts  0x02047CE4  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FIELD_CAMERA_Main  0x0218E104  thumb  ov021
 *   GAME_DATA_ResetWalkCount  0x020129F0  thumb
 *   FIELD_G3D_MAPPER_StepBlocks  0x0218CC34  thumb
 *   FIELD_SUBSCREEN_MainNoTransition  0x021A0E58  thumb
 *   FIELD_PLACE_NAME_Draw  0x021BC4F0  thumb
 *   ENCEFF_Delete  0x021CF480  thumb  ov021
 *   FLD3D_CI_Delete  0x021C1C04  thumb  ov021
 *   FLD_PARTICLE_Delete  0x021C1AD0  thumb  ov021
 *   FIELD_SUBPROC_MGR_Delete  0x021BB90C  thumb  ov021
 *   GAME_COMM_CallKindNotify  0x020263B0  thumb
 *   FIELD_PLACE_NAME_Delete  0x021BC424  thumb  ov021
 *   FIELD_GIMMICK_Exit  0x021BE218  thumb  ov021
 *   FLD_EXP_OBJ_Delete  0x021BE2E0  thumb  ov021
 *   FIELD_ENCOUNT_Delete  0x021A9F28  thumb  ov021
 *   FIELD_SUBSCREEN_Delete  0x021A0D44  thumb  ov021
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FIELD_EFFECT_Delete  0x021ABDE8  thumb  ov021
 *   UNION_EFF_Delete  0x0217F8EC  thumb  ov019
 *   WEATHER_Delete  0x021A1AAC  thumb  ov021
 *   FIELD_LIGHT_Delete  0x021A0448  thumb  ov021
 *   FIELD_ZONEFOG_Delete  0x021A02F4  thumb  ov021
 *   FIELD_FOG_Delete  0x021A0138  thumb  ov021
 *   FIELD_PALACE_SYS_Delete  0x021D33E0  thumb  ov021
 *   FIELD_NOGRID_MAPPER_Delete  0x021BB240  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Delete  0x021AB81C  thumb  ov021
 *   FLD_SCENEAREA_Delete  0x021AB624  thumb  ov021
 *   FIELD_CAMERA_Delete  0x0218E0E4  thumb  ov021
 *   FIELD_PLAYER_Delete  0x021A2E90  thumb  ov021
 *   FIELD_G3D_MAPPER_ReleaseBlocks  0x0218D05C  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   FIELD_MSGBG_Delete  0x021902BC  thumb  ov021
 *   SODATEYA_Delete  0x021C31FC  thumb  ov021
 *   FIELDSKILL_MAPEFF_Delete  0x021C7F9C  thumb  ov021
 *   TCB_Noop  0x02030DA4  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   FLD_VREQ_Delete  0x021D31A4  thumb
 *   FIELD_TASK_MANAGER_Delete  0x021C6D5C  thumb
 *   FIELD_G3D_MAPPER_Delete  0x0218CA4C  thumb
 *   abs_id_13  0x00000013  data
 *   abs_id_12  0x00000012  data
 *   sFieldMapSeqTable  0x021D36B8  data  a4
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   ISS_SWITCH_GetSubscreenMode  0x0202C794  thumb
 *   sCtrlMoveKindTable  0x021D35A8  data
 *   FIELDMAP_CTRL_HYBRID_GetMode  0x021A6DC0  thumb
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   sClearPalette     0x021D3620  data
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BUTTON_MAN_RotScaleMtx22  0x02051E74  arm
 *   G2x_SetBGyAffine_  0x0207D59C  arm
 *   BG_SYS_SetLowBit  0x0204044C  arm
 *   FIELD_MSGBG_SetupBg  0x02190270  thumb
 *   FIELD_MSGBG_SetupBgDelayed  0x0219027C  thumb
 *   NNS_G3dGeFlushBuffer  0x0206DB80  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   G3X_SetFog  0x0207DC44  arm
 *   G3X_SetFogTable  0x0207DD10  arm
 *   G3X_SetClearColor  0x0207DD24  arm
 *   G3X_SetEdgeColorTable  0x0207DCF8  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   sFogTable  0x021D3640  data  a4
 *   sEdgeColorTable  0x021D35E4  data  a4
 *   BILLBOARD_ACT_Create  0x0204FE94  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetQuadShape  0x0204EDBC  arm
 *   BILLBOARD_SetImageOffset  0x0204EDC4  arm
 *   BILLBOARD_SetScale  0x0204ED70  arm
 *   BILLBOARD_SetPolyIdBase  0x0204EDB0  arm
 *   FIELD_G3DOBJ_Create  0x021C63AC  thumb  ov021
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_LIGHT_CreateSlots  0x02048BC4  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_LIGHT_ApplySlots  0x02048C58  arm
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   sGroundBbdScale     0x021D36F4  data  a4
 *   sCameraUp     0x021D36E8  data  a4
 *   sCameraPos     0x021D35C0  data  a4
 *   sCameraTarget     0x021D35CC  data  a4
 *   sLightSetup     0x021D35AC  data  a4
 *   BILLBOARD_ACT_UpdateEntries  0x020504D8  arm
 *   FIELD_NOGRID_MAPPER_Main  0x021BB36C  thumb
 *   FLD_SCENEAREA_Update  0x021AB660  thumb
 *   FIELD_ZONEFOG_Main  0x021A030C  thumb
 *   FIELD_FOG_Main  0x021A0140  thumb
 *   FIELD_LIGHT_Main  0x021A0458  thumb
 *   FIELD_G3D_MAPPER_UpdateStep  0x0218CB34  thumb
 *   GFL_NET_SetDeviceModeIfRunning  0x0203D12C  arm
 *   func_02047964  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   sDrawStartFuncs     0x021D35D8  data  a4
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   sDrawEndFuncs     0x021D35B4  data  a4
 *   func_02048C4C  0x02048C4C  arm
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   BILLBOARD_ACT_Delete  0x0204FFFC  arm
 *   FIELD_G3DOBJ_Delete  0x021C6400  thumb  ov021
 *   GFL_USE_IsCardIrqEnabled  0x02005C8C  thumb
 *   FLDMMDL_UpdateSysBlAct  0x0216CD78  thumb  ov010
 *   FIELD_G3DOBJ_Update  0x021C6470  thumb  ov021
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   FLD_VREQ_VBlank  0x021D31AC  thumb  ov021
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   func_020140E0  0x020140E0  thumb
 *   func_02013DB8  0x02013DB8  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   data_021EE700  0x021EE700  data  a4
 *   data_021EE700b  0x021EE700  data
 *   func_020140E4  0x020140E4  thumb
 *   FIELD_BBD_COLOR_Create  0x021CD1C8  thumb
 *   FIELD_BBD_COLOR_Load  0x021CD204  thumb
 *   FIELD_BBD_COLOR_Apply  0x021CD214  thumb
 *   FIELD_BBD_COLOR_Delete  0x021CD1F0  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_SetupSysProc  0x0216CCDC  thumb  ov010
 *   FLDMMDL_BLACT_Init  0x0219C554  thumb
 *   FLDMMDL_BLACT_AddCachedRes  0x0219C680  thumb
 *   INTRUDE_FIELD_GetHostGender  0x0217C0A8  thumb  ov018
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb
 *   FLDMMDL_BLACT_AddResByCode  0x0219C658  thumb
 *   FLDMMDL_G3DOBJ_Create  0x0219D448  thumb
 *   FIELD_CAMERA_GetViewYawPtr  0x0218ED50  thumb
 *   FLDMMDL_SetAreaIdRef  0x0216CDB8  thumb  ov010
 *   FLDMMDL_SysPopAll  0x0216D2F8  thumb  ov010
 *   FLDMMDL_SysSetDrawEnable  0x0216D974  thumb  ov010
 *   FLDMMDL_SysPushAll  0x0216D2AC  thumb  ov010
 *   FLDMMDL_DeleteSysProc  0x0216CD50  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_IsEncountDataLoaded  0x02162458  thumb  ov010
 *   EVENTDATA_SYSTEM_LoadEncountData  0x02162438  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   ZONEDATA_GetLocationVec  0x020141E0  thumb
 *   ZONEDATA_SetLocationVec  0x020141F0  thumb
 *   MAP_MATRIX_IsInRangeByPos  0x02159C48  thumb  ov010
 *   MAP_MATRIX_GetZoneIdByPos  0x02159BD4  thumb  ov010
 *   EFFECT_ENCOUNT_Reset  0x021AA8EC  thumb  ov021
 *   FLDMMDL_SysDeleteZoneChangeMmdl  0x0216DF1C  thumb  ov010
 *   EVENTDATA_SYSTEM_Clear  0x021623DC  thumb  ov010
 *   EVENTDATA_SYSTEM_LoadEventData  0x0216242C  thumb  ov010
 *   FIELD_MAP_CHANGE_ApplyZoneHeader  0x021643AC  thumb  ov010
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   GAME_BEACON_SetZone  0x0202735C  thumb
 *   MAP_REPLACE_SetArriveFlag  0x0215A014  thumb  ov010
 *   SCRIPT_SYS_RunZoneChangeScript  0x02158AE0  thumb  ov010
 *   INTRUDE_COMM_ClearHoldMode  0x0215874C  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderList  0x0216CEAC  thumb  ov010
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   ISS_SYS_ChangeZone  0x0202B544  thumb
 *   func_02029CF0  0x02029CF0  thumb
 *   ISS_SWITCH_ApplySubscreenMode  0x0202C83C  thumb
 *   WEATHER_RequestChange  0x021A1BDC  thumb  ov021
 *   FIELD_ZONEFOG_Clear  0x021A0358  thumb  ov021
 *   GAME_DATA_SetPlayerZoneId  0x02012AC4  thumb
 *   func_02013BD0  0x02013BD0  thumb
 *   FIELD_CAMERA_LoadAreas  0x0218F14C  thumb  ov021
 *   FIELD_CAMERA_ClearAreas  0x0218F134  thumb  ov021
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   FIELD_STATUS_GetMapMode  0x0201444C  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   GAME_DATA_GetUnionInfo  0x020127D0  thumb
 *   FIELD_G3D_MAPPER_SetupWfbc  0x0218DC74  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   FIELD_WFBC_DisableUnusedConnects  0x021939C0  thumb  ov021
 *   FIELD_WFBC_SetUpCamera  0x02193ABC  thumb  ov021
 *   FIELD_WFBC_SetMmdlSys  0x02193AFC  thumb  ov021
 *   ZONEDATA_GetSecondSpecialKind  0x02013FA8  thumb
 *   ZONEDATA_HasSpecialKind  0x02013C80  thumb
 *   FLD_SCENEAREA_ClearData  0x021AB650  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Unload  0x021AB868  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Load  0x021AB840  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecs  0x021AB880  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecCount  0x021AB884  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetCallbacks  0x021AB888  thumb  ov021
 *   FLD_SCENEAREA_SetData  0x021AB634  thumb  ov021
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GAME_COMM_GetLastKind  0x0202647C  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   FIELD_FOG_Reflect  0x021A0170  thumb  ov021
 *   FIELD_LIGHT_Reflect  0x021A0568  thumb  ov021
 *   FIELD_G3D_MAPPER_Draw  0x0218CC64  thumb  ov021
 *   FIELD_MSGBG_DrawTalkSys    0x0219047C  thumb  ov021
 *   FIELDSKILL_MAPEFF_Apply    0x021C7FB4  thumb  ov021
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   NNS_G3dGlbFlush    0x0206A854  arm
 *   FIELD_EFFECT_Draw    0x021ABE0C  thumb  ov021
 *   FIELD_G3DOBJ_DrawAll    0x021C64E0  thumb  ov021
 *   LIST_PopFront    0x02050790  arm
 *   UNION_EFF_Draw    0x0217F928  thumb  ov019
 *   FIELD_SUBPROC_MGR_RunDraw    0x021BB954  thumb  ov021
 *   WEATHER_Draw    0x021A1B38  thumb  ov021
 *   FLD_EXP_OBJ_Draw    0x021BE4F8  thumb  ov021
 *   FLD_PARTICLE_Exit    0x021C1AEC  thumb  ov021
 *   FLD3D_CI_DrawEffect    0x021C1C4C  thumb  ov021
 *   g_DefaultProjectionMtx       0x02148B54  data
 *   SCREENTEX_CameraState       0x02148BCC  data
 *   ENCEFF_RunUpdate  0x021CF520  thumb  ov021
 *   TIMEZONE_GetNowTimeZone  0x020113D8  thumb
 *   FIELD_CAMERA_GetViewPitchPtr  0x0218ED3C  thumb  ov021
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   func_02013BA8  0x02013BA8  thumb
 *   func_02013B50  0x02013B50  thumb
 *   MAP_MATRIX_GetWidth  0x02159BF4  thumb  ov010
 *   MAP_MATRIX_GetHeight  0x02159BF8  thumb  ov010
 *   MAP_MATRIX_GetCount  0x02159BFC  thumb  ov010
 *   MAP_MATRIX_GetMapGrid  0x02159C20  thumb  ov010
 *   func_020140BC  0x020140BC  thumb
 *   func_020140C0  0x020140C0  thumb
 *   func_020140CC  0x020140CC  thumb
 *   sMapTypeTable     0x021D3700  data  a4
 *   gMapTypeCtrlTable     0x021D373C  data  a4
 */
#include "fieldmap_types.h"

typedef int (*FieldMapSeqFunc)(struct GameSystem *gameSystem, FieldMap *fieldMap);
typedef int (*FieldMapEventCheckFunc)(struct GameSystem *gameSystem, void *work);

#define REG_DISPCNT (*(volatile u32 *)0x04000000)
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
struct GameSystem;
struct GfProc;
struct GameComm;
struct PlayerWork;
struct DispVram;
struct GameData;
struct Cfg;
struct MapMatrix;
struct FieldStatus;
struct DispConfig;
struct Mtx22;
struct LightSet;
struct BbActSys;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed int     s32;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef int fx32;

typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

/* NNS_G3dGlb (NitroSystem); fieldmap.c only clears bits of the flag word. */
typedef struct G3dGlobalState {
    u8 otherState[0x7C];    /* 0x00: not touched here */
    u32 flag;               /* 0x7C */
} G3dGlobalState;

typedef void (*FieldMapDrawFunc)(FieldMap *fieldMap);
typedef int (*FieldMapDrawEndFunc)(FieldMap *fieldMap);

struct PlayerWork *GAMESYSTEM_GetMyPlayerWork(const struct GameSystem *x);
unsigned short GAME_DATA_GetPlayerZoneId(const struct PlayerWork *x);
int FIELDMAP_GetHeapSizeForMapType(int x);
void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);
void GFL_HEAP_RegisterBlockHeap(void *a, u32 b, u32 c);
void *PROCSYS_AllocProcWork(struct GfProc *proc, u32 size, u32 heapId);
void ICA_ANIME_SetField20(struct GameSystem *p, void *v);
unsigned int GAMESYSTEM_GetAlwaysNetFlag(const struct GameSystem *x);
struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);
u32 GAME_COMM_GetKind(struct GameComm *gameComm);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void PROCSYS_FreeProcWork(struct GfProc *proc);
void GFL_HEAP_DeleteChecked(unsigned int heap);
void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, u16 tag);
struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *p);
u32 ZONEDATA_GetAreaId(u32 id);
int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
struct AreaData *ZONEDATA_CreateAreaData(int heapId, int areaId, int infoCode);
u32 ZONEDATA_DeleteAreaData(struct AreaData *areaData);
u32 GFL_HEAP_Free(void *p);
void GFL_NET_WM_ICON_SetDefaultPos(unsigned short a, unsigned int b);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BMP_WIN_Init(u16 heapId);
extern void GF_FONT_ResetTextColor(void);
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u32 fifoSize, u32 heap, void (*setup)(void));
extern u8 GAME_DATA_GetSeason(const struct GameData *p);
extern struct FieldG3dMapper *FIELD_G3D_MAPPER_Create(int heapId, int b);
extern struct GFL_TCB *GFL_USE_AddMainTask(void (*cb)(struct GFL_TCB *, void *), void *work, int pri);
extern u32 TCB_GetTaskOffset(u32 idx);
extern struct TcblSys *TCB_Init(u32 capacity, void *work);
extern struct FieldTaskManager *FIELD_TASK_MANAGER_Create(int n, int heapId);
extern void *FLD_VREQ_Create(u32 heap);
extern u32 ZONEDATA_IsZone1A6(u32 id);
extern u32 ZONEDATA_IsZone96Pair(u32 id);
extern int GF_OVERLAY_Load(int id);
extern void func_02035660(u32 a);
extern void FIELD_MAP_CHANGE_Empty(struct GameData *gameData, u16 zoneId);
extern struct FieldMsgBg *FIELD_MSGBG_Create(u16 heapId, struct G3dCamera *g3dCamera);
extern struct FieldPlaceName *FIELD_PLACE_NAME_Create(struct GameSystem *gameSystem, int heapId, struct FieldMsgBg *msgBg);
extern struct FieldStatus *GAME_DATA_GetMoveModelSys(const struct GameData *gameData);
extern u16 FIELD_STATUS_GetMapEffectMask(struct FieldStatus *o);
extern struct FieldSkillMapEff *FIELDSKILL_MAPEFF_Create(int flags, u16 heapId);
extern u8 func_02013BBC(u32 id);
extern struct FieldCamera *FIELD_CAMERA_Create(int a0, int a1, struct G3dCamera *g3dCamera, const VecFx32 *target, u16 heapId);
extern struct FldSceneArea *FLD_SCENEAREA_Create(u16 heapId, struct FieldCamera *camera, void *work);
extern struct FldSceneAreaLoader *FLD_SCENEAREA_LOADER_Create(u16 heapId);
extern struct FieldNogridMapper *FIELD_NOGRID_MAPPER_Create(u32 heapId, struct FieldCamera *camera, struct FldSceneArea *sceneArea, struct FldSceneAreaLoader *loader);
extern struct FieldPalaceSys *FIELD_PALACE_SYS_Create(u16 heapId, struct GameSystem *gameSystem, FieldMap *fieldMap, u16 zoneId);
extern void *FIELD_G3D_MAPPER_GetBuildModel(struct FieldG3dMapper *g3dMapper);
extern struct MapMatrix *GAME_DATA_GetFieldWork(const struct GameData *gameData);
extern void *FIELD_PALACE_SYS_GetPalTable(struct FieldPalaceSys *palaceSys);
extern void FIELD_BUILDMODEL_LoadArea(void *buildModel, int zoneId, struct AreaData *areaData, void *palTable);
extern void FIELD_G3DOBJ_SetPalTable(struct FieldG3dObjCtrl *g3dObjCtrl, void *palTable);
extern void ZONEDATA_SetExitLocation(FieldMapLocation *location, u16 zoneId, int b, int c, int d, int x, int y, int z);
extern void FIELD_G3D_MAPPER_Setup(struct FieldG3dMapper *g3dMapper, const FieldMapMapperParam *param, void *palTable);
extern int ZONEDATA_GetSpecialKind(u16 key);
extern void FIELD_NOGRID_MAPPER_LoadDataFromArc(struct FieldNogridMapper *nogridMapper, u32 kind, u32 heapId);
extern struct FieldEffectCont *FIELD_EFFECT_Create(FieldMap *fieldMap, int b, u16 heapId);
extern void FIELD_EFFECT_InitObjectSystem(struct FieldEffectCont *effect, int n);
extern void FIELD_EFFECT_SetPaletteTable(struct FieldEffectCont *effect, void *palTable);
extern void FIELD_EFFECT_LoadResources(struct FieldEffectCont *effect, int *arr, int n);
extern struct UnionEff *UNION_EFF_Create(u16 heapId);
extern u32 GAME_DATA_GetPlayerDirectionType(const struct PlayerWork *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct PlayerWork *p);
extern u32 ZONEDATA_IsBikeEnabled(u32 id);
extern void GAME_DATA_SetPlayerObjectCode(struct PlayerWork *p, u32 v);
extern void *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern u8 func_02008550(const void *myStatus);
extern struct FieldPlayer *FIELD_PLAYER_Create(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, int sex, u16 heapId);
extern void FIELD_G3D_MAPPER_SetFocusPos(struct FieldG3dMapper *g3dMapper, const VecFx32 *pos);
extern struct FldExpObjCnt *FLD_EXP_OBJ_Create(int a, int b, u16 heapId);
extern struct FieldFog *FIELD_FOG_Create(u16 heapId);
extern struct FieldZoneFog *FIELD_ZONEFOG_Create(u16 heapId);
extern u32 func_02013EEC(u32 id);
extern int ZONEDATA_GetLightId(unsigned short id);
extern void FIELD_ZONEFOG_SetUp(struct FieldZoneFog *zoneFog, u32 id, u32 c, u8 d);
extern u8 ZONEDATA_GetAreaLightType(struct AreaData *areaData);
extern u32 GF_STANDARD_GetTime(void);
extern struct FieldLight *FIELD_LIGHT_Create(u32 a, u32 b, u32 c, struct FieldFog *fog, struct G3dLightSlots *g3dLight, u16 heapId);
extern u32 GAME_DATA_GetBgmInfo(const struct GameData *p);
extern struct WeatherSys *WEATHER_Create(struct FieldCamera *camera, struct FieldLight *light, struct FieldFog *fog, struct FieldZoneFog *zoneFog, int a4, int a5, int heapId);
extern u8 GAME_DATA_GetSubscreenMode(const struct GameData *p);
extern void WEATHER_SetImmediate(struct WeatherSys *weather, int a, int f);
extern void FIELD_GIMMICK_Setup(FieldMap *fieldMap);
extern u8 GAME_DATA_GetSubscreenType(const struct GameData *p);
extern struct FieldSubscreen *FIELD_SUBSCREEN_Create(u32 heapId, FieldMap *fieldMap, u32 c);
extern struct FieldEncount *FIELD_ENCOUNT_Create(FieldMap *fieldMap);
extern void GAME_COMM_CallHandler(struct GameComm *gameComm, FieldMap *fieldMap);
extern struct FieldmapFunc *FIELD_SUBPROC_MGR_Create(FieldMap *fieldMap, int b, int n);
extern struct FldParticle *FLD_PARTICLE_Create(u32 a);
extern struct Fld3dCi *FLD3D_CI_Create(u32 a, struct FldParticle *particle);
extern struct EncEff *ENCEFF_Create(u32 heapId, FieldMap *fieldMap);
extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void *DAYCARE_GetFromSave(void *sys);
extern struct Sodateya *SODATEYA_Create(u16 heapId, FieldMap *fieldMap, void *b);
extern void FIELD_G3D_MAPPER_UpdateBlocking(struct FieldG3dMapper *g3dMapper);
extern int FLDMMDL_UpdateSysProc(struct MmdlSys *mmdlSys);
extern int FLDMMDL_BLACT_RegisterLoadedRes(struct MmdlSys *mmdlSys);
extern int FLDMMDL_BLACT_IsReservePending(struct MmdlSys *mmdlSys);
extern int WEATHER_IsTaskActive(struct WeatherSys *weather);
extern void WEATHER_Update(struct WeatherSys *weather, int heapId);
extern void CLACT_DrawSystem(void);
extern void FIELD_MSGBG_Main(struct FieldMsgBg *msgBg);
extern void FIELD_EFFECT_Update(struct FieldEffectCont *effect);
extern void FIELD_SUBPROC_MGR_RunUpdate(struct FieldmapFunc *mapFunc);
extern u8 FIELD_STATUS_GetContinueFlag(struct FieldStatus *o);
extern int GFL_USE_IsLoaderBusy(void);
extern u8 func_02014458(struct FieldStatus *o);
extern void SCRIPT_SYS_RunFieldInitScript(struct GameSystem *gameSystem, int heapId);
extern void FIELD_STATUS_SetFieldInitFlag(struct FieldStatus *o, u8 v);
extern void SCRIPT_SYS_RunFieldRecoverScript(struct GameSystem *gameSystem, int heapId);
extern void FIELD_STATUS_SetContinueFlag(struct FieldStatus *o, u8 v);
extern void GAMESYSTEM_SetEventCreator(struct GameSystem *gameSystem, FieldMapEventCheckFunc checkFunc, FieldMap *fieldMap);
extern void GAME_DATA_SetWalkCountEnabled(struct GameData *p, u8 v);
extern int FIELD_EVENT_CHECK_CheckCommEvents(struct GameSystem *gameSystem, void *work);
extern int FIELD_EVENT_CHECK_RunRail(struct GameSystem *gameSystem, void *work);
extern int FIELD_EVENT_CHECK_Run(struct GameSystem *gameSystem, void *work);
extern int FIELD_EVENT_CHECK_RunGrid(struct GameSystem *gameSystem, void *work);
extern u32 GAMESYSTEM_GetEvent(const struct GameSystem *p);
extern u8 FIELD_STATUS_SwapSeasonDispFlag(struct FieldStatus *o, u8 v);
extern u8 GAME_DATA_IsSaving(const struct GameData *gameData);
extern void func_02035648(void);
extern int GAMESYSTEM_IsEventActive(struct GameSystem *gameSystem);
extern void FIELD_CLOCK_Update(struct GameData *gameData);
extern void FIELD_PLACE_NAME_Main(struct FieldPlaceName *placeName);
extern void FIELDSKILL_MAPEFF_Update(struct FieldSkillMapEff *mapEff);
extern void FIELD_PLAYER_SaveToPlayerWork(struct FieldPlayer *player);
extern void UNION_MAIN_UpdateField(struct GameComm *gameComm, FieldMap *fieldMap);
extern void INTRUDE_FIELD_Update(FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
extern void FIELD_SUBSCREEN_Main(struct FieldSubscreen *subscreen);
extern void FIELD_GIMMICK_RunMapCallback(FieldMap *fieldMap);
extern void EVENT_COMM_COMMON_CmdCallMissionInfoEvent(struct UnionEff *unionEff);
extern void TCB_Main(struct TcblSys *c);
extern void FIELD_TASK_MANAGER_Update(struct FieldTaskManager *taskManager);
extern u32 *GAME_DATA_GetEventState(struct GameData *gameData);
extern void PLEASURE_BOAT_AckEvent(u32 a);
void G3D_SYSTEM_ResetDrawCounts(void);
unsigned int KEY_GetCont(void);
extern void FIELD_CAMERA_Main(struct FieldCamera *camera, u32 b);
extern void GAME_DATA_ResetWalkCount(struct GameData *p);
extern void FIELD_G3D_MAPPER_StepBlocks(struct FieldG3dMapper *g3dMapper);
extern void FIELD_SUBSCREEN_MainNoTransition(struct FieldSubscreen *subscreen);
extern void FIELD_PLACE_NAME_Draw(struct FieldPlaceName *placeName);
extern int ENCEFF_Delete(struct EncEff *encEff);
extern void FLD3D_CI_Delete(struct Fld3dCi *fld3dCi);
extern void FLD_PARTICLE_Delete(struct FldParticle *particle);
extern void FIELD_SUBPROC_MGR_Delete(struct FieldmapFunc *mapFunc);
extern void GAME_COMM_CallKindNotify(struct GameComm *gameComm, FieldMap *fieldMap);
extern void FIELD_PLACE_NAME_Delete(struct FieldPlaceName *placeName);
extern void FIELD_GIMMICK_Exit(FieldMap *fieldMap);
extern void FLD_EXP_OBJ_Delete(struct FldExpObjCnt *expObj);
extern void FIELD_ENCOUNT_Delete(struct FieldEncount *encount);
extern u8 FIELD_SUBSCREEN_Delete(struct FieldSubscreen *subscreen);
extern void GAME_DATA_SetSubscreenType(struct GameData *p, u32 v);
extern void FIELD_EFFECT_Delete(struct FieldEffectCont *effect);
extern void UNION_EFF_Delete(struct UnionEff *unionEff);
extern void WEATHER_Delete(struct WeatherSys *weather);
extern void FIELD_LIGHT_Delete(struct FieldLight *light);
extern int FIELD_ZONEFOG_Delete(struct FieldZoneFog *zoneFog);
extern void FIELD_FOG_Delete(struct FieldFog *fog);
extern void FIELD_PALACE_SYS_Delete(struct FieldPalaceSys *palaceSys);
extern int FIELD_NOGRID_MAPPER_Delete(struct FieldNogridMapper *nogridMapper);
extern void FLD_SCENEAREA_LOADER_Delete(struct FldSceneAreaLoader *sceneAreaLoader);
extern void FLD_SCENEAREA_Delete(struct FldSceneArea *sceneArea);
extern void FIELD_CAMERA_Delete(struct FieldCamera *camera);
extern int FIELD_PLAYER_Delete(struct FieldPlayer *player);
extern void FIELD_G3D_MAPPER_ReleaseBlocks(struct FieldG3dMapper *g3dMapper);
extern int FIELD_MSGBG_DeleteMsgWin(struct FieldMsgWin *infoWindow);
extern void FIELD_MSGBG_Delete(struct FieldMsgBg *msgBg);
extern void SODATEYA_Delete(struct Sodateya *sodateya);
extern void FIELDSKILL_MAPEFF_Delete(struct FieldSkillMapEff *mapEff);
extern void TCB_Noop(struct TcblSys *tcblSys);
extern void TCB_DeleteTask(struct GFL_TCB *tcb);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void GF_OVERLAY_Unload(s32 handle);
extern void FLD_VREQ_Delete(struct FldVReq *vreq);
extern void FIELD_TASK_MANAGER_Delete(struct FieldTaskManager *taskManager);
extern int FIELD_G3D_MAPPER_Delete(struct FieldG3dMapper *g3dMapper);
extern u32 FIELD_PLAYER_GetFormCode(struct FieldPlayer *player);
extern void FIELD_PLAYER_StartFormChange(struct FieldPlayer *player, u32 a1);
extern int FIELD_PLAYER_StepFormChange(struct FieldPlayer *player);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *GAME_DATA_GetTrainerRecord(struct GameData *gameData);
extern u32 func_02008DF0(void *record, int i);
extern u8 ISS_SWITCH_GetSubscreenMode(void *a0, u32 a1);
extern u32 FIELDMAP_CTRL_HYBRID_GetMode(u8 *p);
extern void BG_SYS_Create(u16 heap);
extern void BG_SYS_LoadPltt(u32 a, void *b, u32 c, u32 d);
extern u32 BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_SetGraphicsMode(const struct DispConfig *cfg);
extern const struct DispConfig sBgModeSetup;
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void G2x_SetBGyAffine_(u32 a, void *buf, u32 b, u32 c, u32 d, u32 e);
extern void BG_SYS_SetLowBit(u32 a);
extern void FIELD_MSGBG_SetupBg(struct FieldMsgBg *msgBg);
extern void FIELD_MSGBG_SetupBgDelayed(struct FieldMsgBg *msgBg);
extern u32 BG_SYS_Delete(u32);
extern u32 G3D_SYSTEM_Exit(u32);
extern u32 NNS_G3dGeFlushBuffer(u32);
extern void G3X_SetFog(int enable, int fogMode, int fogSlope, int fogOffset);
extern void G3X_SetFogTable(void *a);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3X_SetEdgeColorTable(void *a);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern struct BbActSys *BILLBOARD_ACT_Create(u16 a0, u16 a1, void (*transCallback)(int, int, void *, int), int heapId);
extern void *BILLBOARD_ACT_GetBoard(struct BbActSys *bbdAct);
extern void BILLBOARD_SetQuadShape(u8 *dst, u8 val);
extern void BILLBOARD_SetImageOffset(u8 *dst, int a, int b);
extern void BILLBOARD_SetScale(void *board, const VecFx32 *scale);
extern void BILLBOARD_SetPolyIdBase(u8 *dst, u8 *src);
extern struct FieldG3dObjCtrl *FIELD_G3DOBJ_Create(u16 heapId, int a, int b);
extern struct G3dCamera *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern struct G3dLightSlots *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heapId);
extern void G3D_CAMERA_Reset(struct G3dCamera *g3dCamera);
extern void G3D_LIGHT_ApplySlots(struct G3dLightSlots *g3dLight);
extern void BILLBOARD_ACT_UpdateEntries(struct BbActSys *bbdAct);
extern void FIELD_NOGRID_MAPPER_Main(struct FieldNogridMapper *nogridMapper);
extern int FLD_SCENEAREA_Update(struct FldSceneArea *sceneArea, const VecFx32 *pos);
extern void FIELD_ZONEFOG_Main(struct FieldZoneFog *zoneFog, u32 heapId);
extern void FIELD_FOG_Main(struct FieldFog *fog);
extern void FIELD_LIGHT_Main(struct FieldLight *light, s32 b);
extern int FIELD_G3D_MAPPER_UpdateStep(struct FieldG3dMapper *g3dMapper);
extern void GFL_NET_SetDeviceModeIfRunning(int a);
void func_02047964(void);
void G3D_SYSTEM_ApplyLookAt(void);
void G3D_SYSTEM_DrawEnd(int x);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern u32 func_02048C4C(struct G3dLightSlots *g3dLight);
extern void BILLBOARD_ACT_Delete(struct BbActSys *o);
extern int FIELD_G3DOBJ_Delete(struct FieldG3dObjCtrl *g3dObjCtrl);
int GFL_USE_IsCardIrqEnabled(void);
int FLDMMDL_UpdateSysBlAct(struct MmdlSys *mmdlSys);
void FIELD_G3DOBJ_Update(struct FieldG3dObjCtrl *g3dObjCtrl);
void CLACT_VBlankSystem(void);
void FLD_VREQ_VBlank(struct FldVReq *vreq);
s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);
extern u8 func_020140E0(struct AreaData *areaData);
extern u32 func_02013DB8(u32 a);
extern void ARC_TOOL_ReadMember(void *a, u32 b, u32 c);
extern u8 func_020140E4(struct AreaData *areaData);
extern void *FIELD_BBD_COLOR_Create(u32 heapId);
extern void FIELD_BBD_COLOR_Load(void *bbdColor, u32 b);
extern void FIELD_BBD_COLOR_Apply(void *bbdColor, void *board);
extern int FIELD_BBD_COLOR_Delete(void *a);
extern struct MmdlSys *GAME_DATA_GetOccupyInfo(const struct GameData *gameData);
extern void FLDMMDL_SetupSysProc(struct MmdlSys *mmdlSys, int heapId, struct GameData *gameData, FieldMap *fieldMap, struct FieldG3dMapper *g3dMapper, struct FieldNogridMapper *nogridMapper);
extern void FLDMMDL_BLACT_Init(struct MmdlSys *mmdlSys, struct BbActSys *bbdAct, u32 c);
extern void FLDMMDL_BLACT_AddCachedRes(struct MmdlSys *mmdlSys);
extern u8 INTRUDE_FIELD_GetHostGender(void *a0);
extern int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
extern void FLDMMDL_BLACT_AddResByCode(struct MmdlSys *mmdlSys, u32 b);
extern void FLDMMDL_G3DOBJ_Create(struct MmdlSys *mmdlSys, struct FieldG3dObjCtrl *g3dObjCtrl);
extern void *FIELD_CAMERA_GetViewYawPtr(struct FieldCamera *camera);
extern void FLDMMDL_SetAreaIdRef(struct MmdlSys *mmdlSys, void *areaIdRef);
extern void FLDMMDL_SysPopAll(struct MmdlSys *mmdlSys);
extern void FLDMMDL_SysSetDrawEnable(struct MmdlSys *mmdlSys, unsigned int v);
extern int FLDMMDL_DeleteSysProc(struct MmdlSys *mmdlSys);
extern void FLDMMDL_SysPushAll(struct MmdlSys *mmdlSys);
extern void *GAME_DATA_GetEventData(const struct GameData *gameData);
extern u32 EVENTDATA_SYSTEM_IsEncountDataLoaded(u8 *p);
extern void EVENTDATA_SYSTEM_LoadEncountData(void *eventData, int a1, int a2);
extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern VecFx32 *GAME_DATA_GetPlayerPosition(struct PlayerWork *playerWork);
extern void ZONEDATA_GetLocationVec(const FieldMapLocation *location, VecFx32 *out);
extern void ZONEDATA_SetLocationVec(FieldMapLocation *location, const VecFx32 *pos);
extern int MAP_MATRIX_IsInRangeByPos(struct MapMatrix *mapMatrix, int x, int z);
extern int MAP_MATRIX_GetZoneIdByPos(struct MapMatrix *mapMatrix, int x, int z);
extern void EFFECT_ENCOUNT_Reset(struct FieldEncount *encount);
extern void FLDMMDL_SysDeleteZoneChangeMmdl(struct MmdlSys *mmdlSys);
extern void EVENTDATA_SYSTEM_Clear(char *p);
extern void EVENTDATA_SYSTEM_LoadEventData(void *a0, u16 a1, u8 a2);
extern void FIELD_MAP_CHANGE_ApplyZoneHeader(void *a, void *b);
extern void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);
extern void GAME_BEACON_SetZone(u32 a0, struct GameData *gameData);
extern void MAP_REPLACE_SetArriveFlag(void *a, int b);
extern void SCRIPT_SYS_RunZoneChangeScript(void *a0, void *a1);
extern void INTRUDE_COMM_ClearHoldMode(void *a);
u16 EVENTDATA_SYSTEM_GetNpcCount(u8 *p);
u32 GAME_DATA_GetEventWork(const struct GameData *p);
void *EVENTDATA_SYSTEM_GetNpcHeaders(void *eventData);
void FLDMMDL_AddMmdlHeaderList(struct MmdlSys *mmdlSys, void *headers, u32 b, u32 n, u32 c);
extern u32 GAMESYSTEM_GetIssSystem(struct GameSystem *gameSystem);
extern void ISS_SYS_ChangeZone(u32 a, u16 b);
extern void func_02029CF0(void *a, void *b, u16 c);
int ISS_SWITCH_ApplySubscreenMode(struct GameSystem *gameSystem, int a1);
void WEATHER_RequestChange(struct WeatherSys *weather, int k);
void FIELD_ZONEFOG_Clear(struct FieldZoneFog *zoneFog);
extern struct PlayerWork *GAME_DATA_SetPlayerZoneId(struct PlayerWork *p, u16 v);
unsigned short func_02013BD0(unsigned short id);
void FIELD_CAMERA_LoadAreas(struct FieldCamera *camera, u32 a, u32 b);
void FIELD_CAMERA_ClearAreas(struct FieldCamera *camera);
extern int ZONEDATA_IsZoneInTableDFC0(int v);
extern u32 FIELD_STATUS_GetMapMode(struct FieldStatus *o);
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern void *GAME_DATA_GetUnionInfo(struct GameData *gameData, u32 idx);
extern int FIELD_G3D_MAPPER_SetupWfbc(struct FieldG3dMapper *g3dMapper, void *wfbcData, u32 c);
extern void *FIELD_G3D_MAPPER_GetWfbc(struct FieldG3dMapper *g3dMapper);
extern void FIELD_WFBC_DisableUnusedConnects(void *buildModel, void *eventData, int skip, u32 heapId);
extern void FIELD_WFBC_SetUpCamera(void *buildModel, struct FieldCamera *camera, int b);
extern void FIELD_WFBC_SetMmdlSys(void *buildModel, struct MmdlSys *mmdlSys);
extern int ZONEDATA_GetSecondSpecialKind(u16 id);
extern int ZONEDATA_HasSpecialKind(int a0);
extern void FLD_SCENEAREA_ClearData(void *p);
extern void FLD_SCENEAREA_LOADER_Unload(void *p);
extern void FLD_SCENEAREA_LOADER_Load(void *p, int a, int b, int c);
extern u32 FLD_SCENEAREA_LOADER_GetRecs(struct FldSceneAreaLoader *sceneAreaLoader);
extern u32 FLD_SCENEAREA_LOADER_GetRecCount(struct FldSceneAreaLoader *sceneAreaLoader);
extern int FLD_SCENEAREA_LOADER_GetCallbacks(void *p);
extern void FLD_SCENEAREA_SetData(void *p, int a, int b, int c);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 GAME_COMM_GetLastKind(void *obj);
extern u32 GAME_COMM_IsTransition(void *obj);
extern u32 FIELD_G3D_MAPPER_Draw(struct FieldG3dMapper *g3dMapper, struct G3dCamera *g3dCamera, int m);
extern void FIELD_FOG_Reflect(struct FieldFog *fog, u32 a1, u32 a2, u32 a3);
extern void FIELD_LIGHT_Reflect(struct FieldLight *light, int force);
extern void FIELD_MSGBG_DrawTalkSys(struct FieldMsgBg *msgBg);
extern void FIELDSKILL_MAPEFF_Apply(struct FieldSkillMapEff *mapEff);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern u32 NNS_G3dGlbFlush(void);
extern void FIELD_EFFECT_Draw(struct FieldEffectCont *effect);
extern void FIELD_G3DOBJ_DrawAll(struct FieldG3dObjCtrl *g3dObjCtrl);
extern void LIST_PopFront(struct BbActSys *bbdAct, struct G3dCamera *g3dCamera, struct G3dLightSlots *g3dLight);
extern void UNION_EFF_Draw(struct UnionEff *unionEff);
extern void FIELD_SUBPROC_MGR_RunDraw(struct FieldmapFunc *mapFunc);
extern void WEATHER_Draw(struct WeatherSys *weather);
extern void FLD_EXP_OBJ_Draw(struct FldExpObjCnt *expObj);
extern void FLD_PARTICLE_Exit(void);
extern void FLD3D_CI_DrawEffect(struct Fld3dCi *fld3dCi);
void ENCEFF_RunUpdate(struct EncEff *encEff);
extern u32 TIMEZONE_GetNowTimeZone(u32);
extern void *FIELD_CAMERA_GetViewPitchPtr(struct FieldCamera *camera);
extern u8 func_02013BA8(u32 id);
extern u32 func_02013B50(u32 id);
extern unsigned short MAP_MATRIX_GetWidth(struct MapMatrix *mapMatrix);
extern unsigned short MAP_MATRIX_GetHeight(struct MapMatrix *mapMatrix);
extern int MAP_MATRIX_GetCount(struct MapMatrix *mapMatrix);
extern void *MAP_MATRIX_GetMapGrid(struct MapMatrix *mapMatrix);
extern u16 func_020140BC(struct AreaData *areaData);
extern u32 func_020140C0(struct AreaData *areaData);
extern u32 func_020140CC(struct AreaData *areaData);
int FIELDMAP_ProcInit(struct GfProc *proc, int *seq, struct GameSystem *gameSystem);
int FIELDMAP_ProcMain(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work);
int FIELDMAP_ProcExit(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work);
FieldMap *FIELDMAP_Create(struct GameSystem *gameSystem, int heapId);
void FIELDMAP_Delete(FieldMap *fieldMap);
int FIELDMAP_SeqInitSystem(struct GameSystem *gameSystem, FieldMap *fieldMap);
int FIELDMAP_SeqCreateSubsystems(struct GameSystem *gameSystem, FieldMap *fieldMap);
int FIELDMAP_SeqStart(struct GameSystem *gameSystem, FieldMap *fieldMap);
int FIELDMAP_SeqUpdate(struct GameSystem *gameSystem, FieldMap *fieldMap);
void FIELDMAP_UpdateCameraAndDraw(FieldMap *fieldMap);
int FIELDMAP_SeqUpdateTop(struct GameSystem *gameSystem, FieldMap *fieldMap);
int FIELDMAP_SeqDeleteSubsystems(struct GameSystem *gameSystem, FieldMap *fieldMap);
int FIELDMAP_SeqExitSystem(struct GameSystem *gameSystem, FieldMap *fieldMap);
int FIELDMAP_Main(struct GameSystem *gameSystem, FieldMap *fieldMap);
void FIELDMAP_RequestClose(FieldMap *fieldMap);
int FIELDMAP_IsReady(FieldMap *fieldMap);
u32 FIELDMAP_CheckPlayerRequest(FieldMap *fieldMap);
struct FieldMsgBg *FIELDMAP_GetMsgBg(FieldMap *fieldMap);
struct FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);
struct FieldNogridMapper *FIELDMAP_GetNogridMapper(FieldMap *fieldMap);
struct FieldLight *FIELDMAP_GetLight(FieldMap *fieldMap);
struct FieldFog *FIELDMAP_GetFog(FieldMap *fieldMap);
struct FieldZoneFog *FIELDMAP_GetZoneFog(FieldMap *fieldMap);
struct WeatherSys *FIELDMAP_GetWeather(FieldMap *fieldMap);
int FIELDMAP_QueryIssSwitch(FieldMap *fieldMap, int switchId);
struct MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);
struct GameSystem *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
struct BbActSys *FIELDMAP_GetEffectBbdAct(FieldMap *fieldMap);
struct BbActSys *FIELDMAP_GetGroundBbdAct(FieldMap *fieldMap);
struct FieldG3dMapper *FIELDMAP_GetG3dMapper(FieldMap *fieldMap);
u16 FIELDMAP_GetZoneId(FieldMap *fieldMap);
void *FIELDMAP_GetCtrlWork(FieldMap *fieldMap);
void FIELDMAP_SetCtrlWork(FieldMap *fieldMap, void *ctrlWork);
struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
int FIELDMAP_IsFieldPlayerCreated(FieldMap *fieldMap);
struct FieldSubscreen *FIELDMAP_GetSubscreen(FieldMap *fieldMap);
struct FieldEffectCont *FIELDMAP_GetEffect(FieldMap *fieldMap);
struct FieldG3dObjCtrl *FIELDMAP_GetG3dObjCtrl(FieldMap *fieldMap);
struct UnionEff *FIELDMAP_GetUnionEff(FieldMap *fieldMap);
struct FieldEncount *FIELDMAP_GetEncount(FieldMap *fieldMap);
unsigned int FIELDMAP_GetCtrlType(FieldMap *fieldMap);
u32 FIELDMAP_GetMoveKind(FieldMap *fieldMap);
struct FieldPlaceName *FIELDMAP_GetPlaceName(FieldMap *fieldMap);
struct FieldmapFunc *FIELDMAP_GetMapFunc(FieldMap *fieldMap);
struct FldExpObjCnt *FIELDMAP_GetExpObj(FieldMap *fieldMap);
struct TcblSys *FIELDMAP_GetTcblSys(FieldMap *fieldMap);
struct FieldTaskManager *FIELDMAP_GetTaskManager(FieldMap *fieldMap);
void FIELDMAP_SetTargetPos(FieldMap *fieldMap, const VecFx32 *targetPos);
struct FieldMsgWin *FIELDMAP_GetInfoWindow(FieldMap *fieldMap);
void FIELDMAP_SetInfoWindow(FieldMap *fieldMap, struct FieldMsgWin *infoWindow);
struct Sodateya *FIELDMAP_GetSodateya(FieldMap *fieldMap);
struct AreaData *FIELDMAP_GetAreaData(FieldMap *fieldMap);
void FIELDMAP_InitBgSystem(FieldMap *fieldMap);
void FIELDMAP_SetBgMode(void);
void FIELDMAP_ResetBgAffineShowMsg(FieldMap *fieldMap);
void FIELDMAP_ResetBgAffineHideMsg(FieldMap *fieldMap);
struct FldVReq *FIELDMAP_GetVReq(FieldMap *fieldMap);
int FIELDMAP_ExitBgSystem(FieldMap *fieldMap);
void FIELDMAP_SetupG3d(void);
void FIELDMAP_CreateG3dResources(FieldMap *fieldMap);
void FIELDMAP_UpdateG3d(FieldMap *fieldMap);
void FIELDMAP_DrawStart(FieldMap *fieldMap);
void FIELDMAP_DrawEnd(FieldMap *fieldMap);
int FIELDMAP_DeleteG3dResources(FieldMap *fieldMap);
void FIELDMAP_VBlankTask(struct GFL_TCB *tcb, void *work);
void FIELDMAP_BbdActTransCallback(int vramTransfer, int destAddr, void *src, int size);
void FIELDMAP_SetupEdgeMarking(struct AreaData *areaData, u32 zoneId);
void FIELDMAP_SetupBbdColor(FieldMap *fieldMap);
void FIELDMAP_SetupMmdlSys(FieldMap *fieldMap);
int FIELDMAP_DeleteMmdlSys(FieldMap *fieldMap);
u32 FIELDMAP_UpdateZoneChange(FieldMap *fieldMap);
int FIELDMAP_CheckPlayerMoved(FieldMap *fieldMap);
u32 FIELDMAP_CheckZoneBoundary(FieldMap *fieldMap);
void FIELDMAP_ChangeZone(FieldMap *fieldMap);
void FIELDMAP_AddZoneNpcs(struct GameData *gameData, struct MmdlSys *mmdlSys, void *eventData, int zoneId);
void FIELDMAP_ChangeZoneSound(FieldMap *fieldMap, unsigned int zoneId);
void FIELDMAP_ChangeZoneWeather(FieldMap *fieldMap, int zoneId);
void FIELDMAP_ChangeZoneFog(FieldMap *fieldMap, int zoneId);
int FIELDMAP_SetPlayerZoneId(struct GameData *gameData, u32 zoneId);
void FIELDMAP_ChangeZoneCamera(FieldMap *fieldMap, u32 zoneId);
FieldMap *FIELDMAP_ClearCtrlWork(FieldMap *fieldMap);
void FIELDMAP_SetupCameraArea(FieldMap *fieldMap, int zoneId, int heapId);
void FIELDMAP_SetupWfbc(struct GameData *gameData, FieldMap *fieldMap, u16 zoneId);
void FIELDMAP_SetupSceneArea(FieldMap *fieldMap, unsigned int zoneId);
int FIELDMAP_GetCommKind(struct GameComm *gameComm);
int FIELDMAP_CheckCommExit(struct GameComm *gameComm);
void FIELDMAP_InitCommonWork(FieldMapCommonWork *commonWork);
void *FIELDMAP_AllocCommonWork(FieldMap *fieldMap, int id, int heapId, int size);
void FIELDMAP_FreeCommonWork(FieldMap *fieldMap, int id);
void *FIELDMAP_GetCommonWork(FieldMap *fieldMap, int id);
int FIELDMAP_ReflectFog(FieldMap *fieldMap, u32 fogEnable, u32 fogSlope, u32 fogOffset);
void FIELDMAP_Draw3dNormal(FieldMap *fieldMap);
void FIELDMAP_Draw3dParticle(FieldMap *fieldMap);
void FIELDMAP_Draw3dEncEff(FieldMap *fieldMap);
int FIELDMAP_GetDrawMode(FieldMap *fieldMap);
void FIELDMAP_SetDrawMode(FieldMap *fieldMap, int drawMode);
struct Fld3dCi *FIELDMAP_GetFld3dCi(FieldMap *fieldMap);
struct EncEff *FIELDMAP_GetEncEff(FieldMap *fieldMap);
struct FieldSkillMapEff *FIELDMAP_GetMapEff(FieldMap *fieldMap);
struct FldSceneArea *FIELDMAP_GetSceneArea(FieldMap *fieldMap);
void FIELDMAP_SetScriptEffectBusy(FieldMap *fieldMap, int busy);
int FIELDMAP_GetScriptEffectBusy(FieldMap *fieldMap);
int FIELDMAP_IsEventActive(FieldMap *fieldMap);
int FIELDMAP_GetTimeZone(FieldMap *fieldMap);
int FIELDMAP_GetSubscreenBusy(FieldMap *fieldMap);
void FIELDMAP_SetSubscreenBusy(FieldMap *fieldMap, int busy);
void FIELDMAP_SetUpdateStopped(FieldMap *fieldMap, int stopped);
void **FIELDMAP_GetFaceUpWorkPtr(FieldMap *fieldMap);
void FIELDMAP_SetZoneEffectWork(FieldMap *fieldMap, void *zoneEffectWork);
void *FIELDMAP_GetZoneEffectWork(FieldMap *fieldMap);
int FIELDMAP_GetCameraPitchScale(FieldMap *fieldMap);
int FIELDMAP_CalcCameraPitchScale(FieldMap *fieldMap);
int FIELDMAP_GetProjDepthOffset(u32 zoneId);
int FIELDMAP_IsMmdlDrawEnabled(int zoneId);
int FIELDMAP_IsLoaderWaitZone(int zoneId);
u32 FIELDMAP_GetMapType(u32 zoneId);
void FIELDMAP_SetupMapperParam(int zoneId, struct AreaData *areaData, FieldMapMapperParam *param, struct MapMatrix *mapMatrix);
const FieldMapCtrlFuncs *FIELDMAP_GetCtrlFuncs(int zoneId);
extern char sFieldMapHeapBuffer[];
extern char sFieldMapSourceName[];
extern u8 sVramBankSetup[];
extern u8 sClactSetup[];
extern u8 abs_id_19[];
extern u8 abs_id_18[];
extern int sFieldEffectTaskCount;
extern int sFieldEffectTaskTable[];
extern u8 abs_id_13[];
extern u8 abs_id_12[];
extern FieldMapSeqFunc sFieldMapSeqTable[][2];
extern const u8 sCtrlMoveKindTable[];
extern u16 sClearPalette[];
extern u8 sFogTable[];
extern u8 sEdgeColorTable[];
extern const s16 d_020A1EB8[];
extern const VecFx32 sGroundBbdScale;
extern const VecFx32 sCameraUp;
extern VecFx32 sCameraPos;
extern VecFx32 sCameraTarget;
extern u8 sLightSetup[];
extern FieldMapDrawFunc sDrawStartFuncs[];
extern FieldMapDrawEndFunc sDrawEndFuncs[];
/*
 * The edge marking colour buffer has two names: the code loads its address
 * from two literal pool words, one per name, so the bytes need both.
 */
extern u8 data_021EE700[];
extern u16 data_021EE700b[];
extern MtxFx44 g_DefaultProjectionMtx;
extern G3dGlobalState SCREENTEX_CameraState;
extern short FX_SinCosTable_[];
extern FieldMapTypeEntry sMapTypeTable[];
extern FieldMapTypeEntryTail gMapTypeCtrlTable[];

int FIELDMAP_ProcInit(struct GfProc *proc, int *seq, struct GameSystem *gameSystem)
{
    switch (*seq) {
    case 0:
        {
            int fieldHeapSize = FIELDMAP_GetHeapSizeForMapType(GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem))) - 0xD000;
            GFL_HEAP_CreateChildHeap(1, 0x15, fieldHeapSize);
        }
        GFL_HEAP_CreateChildHeap(1, 0x70, 0xD000);
        GFL_HEAP_CreateChildHeap(0x15, 0x50, 0xC000);
        GFL_HEAP_RegisterBlockHeap(sFieldMapHeapBuffer, 0x10000, 0x89);
        GFL_HEAP_CreateChildHeap(0x89, 0x92, 0x6400);
        GFL_HEAP_CreateChildHeap(0x89, 0x93, 0x7400);
        GFL_HEAP_CreateChildHeap(0x89, 0x96, 0x500);
        {
            FieldMapProcWork *work = PROCSYS_AllocProcWork(proc, sizeof(FieldMapProcWork), 0x15);
            FieldMap *fieldMap = FIELDMAP_Create(gameSystem, 0x15);
            work->fieldMap = fieldMap;
            ICA_ANIME_SetField20(gameSystem, fieldMap);
        }
        (*seq)++;
        break;
    case 1:
        if (GAMESYSTEM_GetAlwaysNetFlag(gameSystem) == 0) {
            struct GameComm *gameComm = GAMESYSTEM_GetGameComm(gameSystem);
            switch (GAME_COMM_GetKind(gameComm)) {
            case 1:
            case 2:
                GAME_COMM_RequestExitNoCallback(gameComm);
                break;
            }
        }
        return 1;
    }
    return 0;
}

int FIELDMAP_ProcMain(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work)
{
    if (FIELDMAP_Main(gameSystem, work->fieldMap) == 1) {
        return 1;
    }
    return 0;
}

int FIELDMAP_ProcExit(struct GfProc *proc, int *seq, struct GameSystem *gameSystem, FieldMapProcWork *work)
{
    FIELDMAP_Delete(work->fieldMap);
    ICA_ANIME_SetField20(gameSystem, 0);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x96);
    GFL_HEAP_DeleteChecked(0x92);
    GFL_HEAP_DeleteChecked(0x93);
    GFL_HEAP_DeleteChecked(0x89);
    GFL_HEAP_DeleteChecked(0x50);
    GFL_HEAP_DeleteChecked(0x70);
    GFL_HEAP_DeleteChecked(0x15);
    return 1;
}

FieldMap *FIELDMAP_Create(struct GameSystem *gameSystem, int heapId)
{
    FieldMap *fieldMap = GFL_HEAP_Alloc(heapId, sizeof(FieldMap), 1, sFieldMapSourceName, 0x209);
    fieldMap->heapId = heapId;
    fieldMap->mainState = 0;
    fieldMap->gameSystem = gameSystem;
    fieldMap->gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap->zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem));
    {
        int areaId = ZONEDATA_GetAreaId(fieldMap->zoneId);
        fieldMap->areaData = ZONEDATA_CreateAreaData(heapId, areaId, COMM_PLAYER_SUPPORT_GetInfoCode(gameSystem));
    }
    fieldMap->ctrlFuncs = FIELDMAP_GetCtrlFuncs(fieldMap->zoneId);
    return fieldMap;
}

void FIELDMAP_Delete(FieldMap *fieldMap)
{
    struct GameSystem *gameSystem = fieldMap->gameSystem;
    ZONEDATA_DeleteAreaData(fieldMap->areaData);
    GFL_HEAP_Free(fieldMap);
    ICA_ANIME_SetField20(gameSystem, 0);
    GFL_NET_WM_ICON_SetDefaultPos(0, 0);
}

int FIELDMAP_SeqInitSystem(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    u16 heapId = fieldMap->heapId;
    BG_SYS_SetVramBanks((const struct DispVram *)sVramBankSetup);
    FIELDMAP_InitBgSystem(fieldMap);
    CLACT_InitSystem((const struct Cfg *)sClactSetup, (u32)sVramBankSetup, 0x89);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    BMP_WIN_Init(heapId);
    GF_FONT_ResetTextColor();
    G3D_SYSTEM_Init(0, 3, 0, 1, 0x1000, fieldMap->heapId, FIELDMAP_SetupG3d);
    FIELDMAP_CreateG3dResources(fieldMap);
    fieldMap->g3dMapper = FIELD_G3D_MAPPER_Create(fieldMap->heapId, GAME_DATA_GetSeason(fieldMap->gameData));
    fieldMap->vblankTcb = GFL_USE_AddMainTask(FIELDMAP_VBlankTask, fieldMap, 0);
    fieldMap->tcblWork = GFL_HEAP_Alloc(heapId, TCB_GetTaskOffset(0x20), 0, sFieldMapSourceName, 0x26B);
    fieldMap->tcblSys = TCB_Init(0x20, fieldMap->tcblWork);
    fieldMap->taskManager = FIELD_TASK_MANAGER_Create(0xA, fieldMap->heapId);
    fieldMap->vreq = FLD_VREQ_Create(fieldMap->heapId);
    GF_OVERLAY_Load((ZONEDATA_IsZone1A6(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1) ? (int)abs_id_19 : (int)abs_id_18);
    func_02035660(0x1E);
    return 1;
}

int FIELDMAP_SeqCreateSubsystems(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    int busy = 1;
    switch (fieldMap->subSeq) {
    case 0: {
        struct FieldMsgBg *msgBg;
        FIELD_MAP_CHANGE_Empty(gameData, fieldMap->zoneId);
        msgBg = FIELD_MSGBG_Create(fieldMap->heapId, fieldMap->g3dCamera);
        fieldMap->infoWindow = 0;
        fieldMap->msgBg = msgBg;
        fieldMap->placeName = FIELD_PLACE_NAME_Create(gameSystem, 0x93, msgBg);
        fieldMap->mapEff = FIELDSKILL_MAPEFF_Create(FIELD_STATUS_GetMapEffectMask(GAME_DATA_GetMoveModelSys(fieldMap->gameData)), fieldMap->heapId);
        fieldMap->camera = FIELD_CAMERA_Create(func_02013BBC(fieldMap->zoneId), 0, fieldMap->g3dCamera, &fieldMap->nowPos, fieldMap->heapId);
        fieldMap->sceneArea = FLD_SCENEAREA_Create(fieldMap->heapId, fieldMap->camera, fieldMap);
        fieldMap->sceneAreaLoader = FLD_SCENEAREA_LOADER_Create(fieldMap->heapId);
        break;
    }
    case 1: {
        void *buildModel;
        void *palTable;
        fieldMap->nogridMapper = FIELD_NOGRID_MAPPER_Create(fieldMap->heapId, fieldMap->camera, fieldMap->sceneArea, fieldMap->sceneAreaLoader);
        fieldMap->palaceSys = FIELD_PALACE_SYS_Create(fieldMap->heapId, gameSystem, fieldMap, fieldMap->zoneId);
        buildModel = FIELD_G3D_MAPPER_GetBuildModel(fieldMap->g3dMapper);
        FIELDMAP_SetupMapperParam(fieldMap->zoneId, fieldMap->areaData, &fieldMap->mapperParam, GAME_DATA_GetFieldWork(fieldMap->gameData));
        GAMESYSTEM_GetGameComm(fieldMap->gameSystem);
        palTable = FIELD_PALACE_SYS_GetPalTable(fieldMap->palaceSys);
        FIELD_BUILDMODEL_LoadArea(buildModel, fieldMap->zoneId, fieldMap->areaData, palTable);
        FIELD_G3DOBJ_SetPalTable(fieldMap->g3dObjCtrl, palTable);
        FIELDMAP_SetupWfbc(gameData, fieldMap, fieldMap->zoneId);
        break;
    }
    case 2: {
        int specialKind;
        ZONEDATA_SetExitLocation(&fieldMap->location, fieldMap->zoneId, 0, 0, 0, fieldMap->nowPos.x, fieldMap->nowPos.y, fieldMap->nowPos.z);
        GAMESYSTEM_GetGameComm(fieldMap->gameSystem);
        FIELD_G3D_MAPPER_Setup(fieldMap->g3dMapper, &fieldMap->mapperParam, FIELD_PALACE_SYS_GetPalTable(fieldMap->palaceSys));
        specialKind = ZONEDATA_GetSpecialKind(fieldMap->zoneId);
        if (specialKind != -1) {
            FIELD_NOGRID_MAPPER_LoadDataFromArc(fieldMap->nogridMapper, specialKind, fieldMap->heapId);
        }
        fieldMap->projDepthOffset = FIELDMAP_GetProjDepthOffset(fieldMap->zoneId);
        FIELDMAP_SetupCameraArea(fieldMap, (u16)fieldMap->zoneId, (u16)fieldMap->heapId);
        break;
    }
    case 3:
        FIELDMAP_SetupMmdlSys(fieldMap);
        fieldMap->effect = FIELD_EFFECT_Create(fieldMap, 0x18, fieldMap->heapId);
        FIELD_EFFECT_InitObjectSystem(fieldMap->effect, 0x5e);
        FIELD_EFFECT_SetPaletteTable(fieldMap->effect, FIELD_PALACE_SYS_GetPalTable(fieldMap->palaceSys));
        FIELD_EFFECT_LoadResources(fieldMap->effect, sFieldEffectTaskTable, sFieldEffectTaskCount);
        if (ZONEDATA_IsZone1A6(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1) {
            fieldMap->unionEff = UNION_EFF_Create(fieldMap->heapId);
        }
        break;
    case 4: {
        struct PlayerWork *playerWork;
        int dirType;
        VecFx32 *playerPos;
        int value;
        int season;
        playerWork = GAMESYSTEM_GetMyPlayerWork(gameSystem);
        dirType = GAME_DATA_GetPlayerDirectionType(playerWork);
        playerPos = (VecFx32 *)((u8 *)playerWork + 4);
        if (GAME_DATA_GetPlayerObjectCode(playerWork) == 1 && ZONEDATA_IsBikeEnabled(fieldMap->zoneId) == 0) {
            GAME_DATA_SetPlayerObjectCode(playerWork, 0);
        }
        fieldMap->player = FIELD_PLAYER_Create(playerWork, fieldMap, playerPos, func_02008550(GAME_DATA_GetMyStatus(gameData)), fieldMap->heapId);
        fieldMap->nowPos = *playerPos;
        fieldMap->ctrlFuncs->create(fieldMap, &fieldMap->nowPos, dirType);
        FIELD_G3D_MAPPER_SetFocusPos(fieldMap->g3dMapper, &fieldMap->nowPos);
        FIELDMAP_InitCommonWork(&fieldMap->commonWork);
        fieldMap->expObj = FLD_EXP_OBJ_Create(0x3c, 0x23, fieldMap->heapId);
        FIELDMAP_SetupEdgeMarking(fieldMap->areaData, FIELDMAP_GetZoneId(fieldMap));
        fieldMap->fog = FIELD_FOG_Create(fieldMap->heapId);
        fieldMap->zoneFog = FIELD_ZONEFOG_Create(fieldMap->heapId);
        value = func_02013EEC(fieldMap->zoneId);
        FIELD_ZONEFOG_SetUp(fieldMap->zoneFog, value, ZONEDATA_GetLightId(fieldMap->zoneId), 1);
        value = ZONEDATA_GetAreaLightType(fieldMap->areaData);
        season = GF_STANDARD_GetTime();
        fieldMap->light = FIELD_LIGHT_Create(value, season, COMM_PLAYER_SUPPORT_GetInfoCode(gameSystem), fieldMap->fog, fieldMap->g3dLight, fieldMap->heapId);
        value = GAME_DATA_GetBgmInfo(fieldMap->gameData);
        fieldMap->weather = WEATHER_Create(fieldMap->camera, fieldMap->light, fieldMap->fog, fieldMap->zoneFog, value, COMM_PLAYER_SUPPORT_GetInfoCode(gameSystem), 0x92);
        WEATHER_SetImmediate(fieldMap->weather, (u16)((int)GAME_DATA_GetSubscreenMode(fieldMap->gameData)), 0x92);
        FIELD_GIMMICK_Setup(fieldMap);
        break;
    }
    case 5:
        fieldMap->subscreen = FIELD_SUBSCREEN_Create(fieldMap->heapId, fieldMap, GAME_DATA_GetSubscreenType(gameData));
        break;
    case 6:
        fieldMap->encount = FIELD_ENCOUNT_Create(fieldMap);
        GAME_COMM_CallHandler(GAMESYSTEM_GetGameComm(gameSystem), fieldMap);
        fieldMap->mapFunc = FIELD_SUBPROC_MGR_Create(fieldMap, fieldMap->heapId, 0x20);
        fieldMap->particle = FLD_PARTICLE_Create(0x50);
        fieldMap->fld3dCi = FLD3D_CI_Create(0x50, fieldMap->particle);
        fieldMap->encEff = ENCEFF_Create(fieldMap->heapId, fieldMap);
        fieldMap->sodateya = SODATEYA_Create(fieldMap->heapId, fieldMap, DAYCARE_GetFromSave(GAME_DATA_GetSaveControl(fieldMap->gameData)));
        FIELDMAP_SetupSceneArea(fieldMap, fieldMap->zoneId);
        busy = 0;
        break;
    }
    (fieldMap->subSeq)++;
    fieldMap->drawMode = 0;
    return busy == 0;
}

int FIELDMAP_SeqStart(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    switch (fieldMap->subSeq) {
    case 0:
        FIELD_G3D_MAPPER_UpdateBlocking(fieldMap->g3dMapper);
        if (fieldMap->mmdlSys != 0) {
            do {
                FLDMMDL_UpdateSysProc(fieldMap->mmdlSys);
                FLDMMDL_BLACT_RegisterLoadedRes(fieldMap->mmdlSys);
            } while (FLDMMDL_BLACT_IsReservePending(fieldMap->mmdlSys) == 1);
        }
        while (WEATHER_IsTaskActive(fieldMap->weather) != 0)
            WEATHER_Update(fieldMap->weather, 0x92);
        FIELDMAP_UpdateG3d(fieldMap);
        FIELDMAP_DrawStart(fieldMap);
        FIELDMAP_DrawEnd(fieldMap);
        CLACT_DrawSystem();
        if (fieldMap->msgBg != 0)
            FIELD_MSGBG_Main(fieldMap->msgBg);
        FIELD_EFFECT_Update(fieldMap->effect);
        FIELD_SUBPROC_MGR_RunUpdate(fieldMap->mapFunc);
        fieldMap->subSeq++;
    case 1:
        if (FIELD_STATUS_GetContinueFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData)) == 1
            && FIELDMAP_IsLoaderWaitZone(fieldMap->zoneId) == 1
            && GFL_USE_IsLoaderBusy() != 0)
            return 0;
        if (func_02014458(GAME_DATA_GetMoveModelSys(fieldMap->gameData)) != 0) {
            SCRIPT_SYS_RunFieldInitScript(fieldMap->gameSystem, fieldMap->heapId);
            FIELD_STATUS_SetFieldInitFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData), 0);
        } else {
            SCRIPT_SYS_RunFieldRecoverScript(fieldMap->gameSystem, fieldMap->heapId);
        }
        FIELD_STATUS_SetContinueFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData), 0);
        FIELD_G3D_MAPPER_UpdateBlocking(fieldMap->g3dMapper);
        if (ZONEDATA_IsZone1A6(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1)
            GAMESYSTEM_SetEventCreator(gameSystem, FIELD_EVENT_CHECK_CheckCommEvents, fieldMap);
        else if (FIELDMAP_GetCtrlType(fieldMap) == 1)
            GAMESYSTEM_SetEventCreator(gameSystem, FIELD_EVENT_CHECK_RunRail, fieldMap);
        else if (FIELDMAP_GetCtrlType(fieldMap) == 2)
            GAMESYSTEM_SetEventCreator(gameSystem, FIELD_EVENT_CHECK_Run, fieldMap);
        else
            GAMESYSTEM_SetEventCreator(gameSystem, FIELD_EVENT_CHECK_RunGrid, fieldMap);
        fieldMap->mainState = 1;
        GAME_DATA_SetWalkCountEnabled(GAMESYSTEM_GetGameData(gameSystem), 1);
        break;
    }
    return 1;
}

int FIELDMAP_SeqUpdate(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    if (GAMESYSTEM_GetEvent(fieldMap->gameSystem) == 0)
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData), 0);
    if (GAME_DATA_IsSaving(fieldMap->gameData) != 0)
        return 0;
    if (fieldMap->updateStopped != 0) {
        FIELDMAP_UpdateCameraAndDraw(fieldMap);
        CLACT_DrawSystem();
        return 0;
    }
    func_02035648();
    FIELDMAP_UpdateZoneChange(fieldMap);
    if (GAMESYSTEM_IsEventActive(gameSystem) == 0) {
        fieldMap->ctrlFuncs->main(fieldMap, &fieldMap->nowPos);
        FIELD_CLOCK_Update(fieldMap->gameData);
    }
    if (fieldMap->placeName != 0)
        FIELD_PLACE_NAME_Main(fieldMap->placeName);
    FIELDSKILL_MAPEFF_Update(fieldMap->mapEff);
    FIELD_PLAYER_SaveToPlayerWork(fieldMap->player);
    if (ZONEDATA_IsZone1A6(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1)
        UNION_MAIN_UpdateField(GAMESYSTEM_GetGameComm(gameSystem), fieldMap);
    else
        INTRUDE_FIELD_Update(fieldMap, fieldMap->gameSystem, fieldMap->player);
    FIELD_SUBSCREEN_Main(fieldMap->subscreen);
    if (fieldMap->mmdlSys != 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        FLDMMDL_UpdateSysProc(fieldMap->mmdlSys);
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    FIELD_GIMMICK_RunMapCallback(fieldMap);
    FIELD_EFFECT_Update(fieldMap->effect);
    if (fieldMap->unionEff != 0)
        EVENT_COMM_COMMON_CmdCallMissionInfoEvent(fieldMap->unionEff);
    FIELD_SUBPROC_MGR_RunUpdate(fieldMap->mapFunc);
    if (fieldMap->msgBg != 0)
        FIELD_MSGBG_Main(fieldMap->msgBg);
    TCB_Main(fieldMap->tcblSys);
    FIELD_TASK_MANAGER_Update(fieldMap->taskManager);
    if (fieldMap->targetPos != 0)
        fieldMap->nowPos = *fieldMap->targetPos;
    FIELD_G3D_MAPPER_SetFocusPos(fieldMap->g3dMapper, &fieldMap->nowPos);
    FIELDMAP_UpdateG3d(fieldMap);
    PLEASURE_BOAT_AckEvent(*GAME_DATA_GetEventState(fieldMap->gameData));
    CLACT_DrawSystem();
    FIELDMAP_UpdateCameraAndDraw(fieldMap);
    return 0;
}

void FIELDMAP_UpdateCameraAndDraw(FieldMap *fieldMap)
{
    volatile u16 *regPowerCnt = (volatile u16 *)0x04000204;
    G3D_SYSTEM_ResetDrawCounts();
    FIELD_CAMERA_Main(fieldMap->camera, (u16)KEY_GetCont());
    fieldMap->cameraPitchScale = FIELDMAP_CalcCameraPitchScale(fieldMap);
    *regPowerCnt = *regPowerCnt & 0xFFFF7FFF;
    FIELDMAP_DrawStart(fieldMap);
    *regPowerCnt = *regPowerCnt | 0x8000;
}

int FIELDMAP_SeqUpdateTop(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    if (GAME_DATA_IsSaving(fieldMap->gameData) != 0) {
        GAME_DATA_ResetWalkCount(GAMESYSTEM_GetGameData(gameSystem));
        return 0;
    }
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FIELD_G3D_MAPPER_StepBlocks(fieldMap->g3dMapper);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    FIELD_SUBSCREEN_MainNoTransition(fieldMap->subscreen);
    if (fieldMap->msgBg != 0)
        FIELD_MSGBG_Main(fieldMap->msgBg);
    if (fieldMap->placeName != 0)
        FIELD_PLACE_NAME_Draw(fieldMap->placeName);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FIELDMAP_DrawEnd(fieldMap);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    GAME_DATA_ResetWalkCount(GAMESYSTEM_GetGameData(gameSystem));
    return 0;
}

int FIELDMAP_SeqDeleteSubsystems(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    ENCEFF_Delete(fieldMap->encEff);
    FLD3D_CI_Delete(fieldMap->fld3dCi);
    FLD_PARTICLE_Delete(fieldMap->particle);
    GAMESYSTEM_SetEventCreator(gameSystem, 0, 0);
    FIELD_PLAYER_SaveToPlayerWork(fieldMap->player);
    FIELD_SUBPROC_MGR_Delete(fieldMap->mapFunc);
    GAME_COMM_CallKindNotify(GAMESYSTEM_GetGameComm(gameSystem), fieldMap);
    if (fieldMap->placeName != 0)
        FIELD_PLACE_NAME_Delete(fieldMap->placeName);
    FIELD_GIMMICK_Exit(fieldMap);
    FLD_EXP_OBJ_Delete(fieldMap->expObj);
    FIELD_ENCOUNT_Delete(fieldMap->encount);
    GAME_DATA_SetSubscreenType(GAMESYSTEM_GetGameData(gameSystem), FIELD_SUBSCREEN_Delete(fieldMap->subscreen));
    FIELD_EFFECT_Delete(fieldMap->effect);
    if (fieldMap->unionEff != 0) {
        UNION_EFF_Delete(fieldMap->unionEff);
        fieldMap->unionEff = 0;
    }
    WEATHER_Delete(fieldMap->weather);
    fieldMap->weather = 0;
    FIELD_LIGHT_Delete(fieldMap->light);
    FIELD_ZONEFOG_Delete(fieldMap->zoneFog);
    FIELD_FOG_Delete(fieldMap->fog);
    FIELD_PALACE_SYS_Delete(fieldMap->palaceSys);
    FIELD_NOGRID_MAPPER_Delete(fieldMap->nogridMapper);
    FLD_SCENEAREA_LOADER_Delete(fieldMap->sceneAreaLoader);
    FLD_SCENEAREA_Delete(fieldMap->sceneArea);
    FIELD_CAMERA_Delete(fieldMap->camera);
    fieldMap->ctrlFuncs->destroy(fieldMap);
    FIELDMAP_ClearCtrlWork(fieldMap);
    FIELDMAP_DeleteMmdlSys(fieldMap);
    FIELD_PLAYER_Delete(fieldMap->player);
    FIELD_G3D_MAPPER_ReleaseBlocks(fieldMap->g3dMapper);
    if (fieldMap->infoWindow != 0)
        FIELD_MSGBG_DeleteMsgWin(fieldMap->infoWindow);
    if (fieldMap->msgBg != 0)
        FIELD_MSGBG_Delete(fieldMap->msgBg);
    GAME_DATA_SetWalkCountEnabled(GAMESYSTEM_GetGameData(gameSystem), 0);
    func_02035660(0x3C);
    SODATEYA_Delete(fieldMap->sodateya);
    FIELDSKILL_MAPEFF_Delete(fieldMap->mapEff);
    return 1;
}

int FIELDMAP_SeqExitSystem(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    TCB_Noop(fieldMap->tcblSys);
    GFL_HEAP_Free(fieldMap->tcblWork);
    FLD_VREQ_Delete(fieldMap->vreq);
    fieldMap->vreq = 0;
    FIELD_TASK_MANAGER_Delete(fieldMap->taskManager);
    TCB_DeleteTask(fieldMap->vblankTcb);
    FIELD_G3D_MAPPER_Delete(fieldMap->g3dMapper);
    FIELDMAP_DeleteG3dResources(fieldMap);
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    FIELDMAP_ExitBgSystem(fieldMap);
    if (ZONEDATA_IsZone1A6(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1)
        GF_OVERLAY_Unload((s32)abs_id_13);
    else
        GF_OVERLAY_Unload((s32)abs_id_12);
    return 2;
}

int FIELDMAP_Main(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    u32 frameCount = fieldMap->frameCount;
    s32 result = 0;
    FieldMapSeqFunc seqFunc;
    FieldMapSeqFunc *row;
    fieldMap->frameCount = frameCount + 1;
    row = sFieldMapSeqTable[fieldMap->seqNo];
    seqFunc = row[fieldMap->halfFrame];
    if (seqFunc != 0)
        result = seqFunc(gameSystem, fieldMap);
    switch (result) {
    case 0:
        fieldMap->halfFrame = (fieldMap->halfFrame == 0);
        break;
    case 1:
        fieldMap->seqNo = fieldMap->seqNo + 1;
        fieldMap->subSeq = 0;
        fieldMap->halfFrame = 0;
        break;
    case 2:
        return 1;
    }
    return 0;
}

void FIELDMAP_RequestClose(FieldMap *fieldMap)
{
    fieldMap->mainState = 2;
    fieldMap->seqNo = 4;
}

int FIELDMAP_IsReady(FieldMap *fieldMap)
{
    if (fieldMap->mainState == 1) {
        return 1;
    }
    return 0;
}

u32 FIELDMAP_CheckPlayerRequest(FieldMap *fieldMap)
{
    u32 handled = 0;
    u32 request = FIELD_PLAYER_GetFormCode(fieldMap->player);

    if (request == 1) {
        handled = 1;
        FIELD_PLAYER_StartFormChange(fieldMap->player, 1);
    } else if (request == 0) {
        handled = 1;
        GFL_USE_PlaySeDefaultVolume(0x55F);
        FIELD_PLAYER_StartFormChange(fieldMap->player, 2);
        func_02008DF0(GAME_DATA_GetTrainerRecord(fieldMap->gameData), 3);
    }
    if (handled == 1)
        FIELD_PLAYER_StepFormChange(fieldMap->player);
    return handled;
}

struct FieldMsgBg *FIELDMAP_GetMsgBg(FieldMap *fieldMap)
{
    return fieldMap->msgBg;
}

struct FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap)
{
    return fieldMap->camera;
}

struct FieldNogridMapper *FIELDMAP_GetNogridMapper(FieldMap *fieldMap)
{
    return fieldMap->nogridMapper;
}

struct FieldLight *FIELDMAP_GetLight(FieldMap *fieldMap)
{
    return fieldMap->light;
}

struct FieldFog *FIELDMAP_GetFog(FieldMap *fieldMap)
{
    return fieldMap->fog;
}

struct FieldZoneFog *FIELDMAP_GetZoneFog(FieldMap *fieldMap)
{
    return fieldMap->zoneFog;
}

struct WeatherSys *FIELDMAP_GetWeather(FieldMap *fieldMap)
{
    return fieldMap->weather;
}

int FIELDMAP_QueryIssSwitch(FieldMap *fieldMap, int switchId)
{
    return ISS_SWITCH_GetSubscreenMode(fieldMap->gameSystem, switchId);
}

struct MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap)
{
    return fieldMap->mmdlSys;
}

struct GameSystem *FIELDMAP_GetGameSystem(FieldMap *fieldMap)
{
    return fieldMap->gameSystem;
}

u16 FIELDMAP_GetHeapId(FieldMap *fieldMap)
{
    return fieldMap->heapId;
}

struct BbActSys *FIELDMAP_GetEffectBbdAct(FieldMap *fieldMap)
{
    return fieldMap->effectBbdAct;
}

struct BbActSys *FIELDMAP_GetGroundBbdAct(FieldMap *fieldMap)
{
    return fieldMap->groundBbdAct;
}

struct FieldG3dMapper *FIELDMAP_GetG3dMapper(FieldMap *fieldMap)
{
    return fieldMap->g3dMapper;
}

u16 FIELDMAP_GetZoneId(FieldMap *fieldMap)
{
    return fieldMap->location.zoneId;
}

void *FIELDMAP_GetCtrlWork(FieldMap *fieldMap)
{
    return fieldMap->ctrlWork;
}

void FIELDMAP_SetCtrlWork(FieldMap *fieldMap, void *ctrlWork)
{
    fieldMap->ctrlWork = ctrlWork;
}

struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap)
{
    return fieldMap->player;
}

int FIELDMAP_IsFieldPlayerCreated(FieldMap *fieldMap)
{
    if (fieldMap->player != 0) {
        return 1;
    }
    return 0;
}

struct FieldSubscreen *FIELDMAP_GetSubscreen(FieldMap *fieldMap)
{
    return fieldMap->subscreen;
}

struct FieldEffectCont *FIELDMAP_GetEffect(FieldMap *fieldMap)
{
    return fieldMap->effect;
}

struct FieldG3dObjCtrl *FIELDMAP_GetG3dObjCtrl(FieldMap *fieldMap)
{
    return fieldMap->g3dObjCtrl;
}

struct UnionEff *FIELDMAP_GetUnionEff(FieldMap *fieldMap)
{
    return fieldMap->unionEff;
}

struct FieldEncount *FIELDMAP_GetEncount(FieldMap *fieldMap)
{
    return fieldMap->encount;
}

unsigned int FIELDMAP_GetCtrlType(FieldMap *fieldMap)
{
    return fieldMap->ctrlFuncs->ctrlType;
}

u32 FIELDMAP_GetMoveKind(FieldMap *fieldMap)
{
    u32 moveKind;
    u32 kind = sCtrlMoveKindTable[fieldMap->ctrlFuncs->ctrlType];
    if (kind == 2)
        kind = FIELDMAP_CTRL_HYBRID_GetMode(fieldMap->ctrlWork);
    moveKind = kind;
    return moveKind;
}

struct FieldPlaceName *FIELDMAP_GetPlaceName(FieldMap *fieldMap)
{
    return fieldMap->placeName;
}

struct FieldmapFunc *FIELDMAP_GetMapFunc(FieldMap *fieldMap)
{
    return fieldMap->mapFunc;
}

struct FldExpObjCnt *FIELDMAP_GetExpObj(FieldMap *fieldMap)
{
    return fieldMap->expObj;
}

struct TcblSys *FIELDMAP_GetTcblSys(FieldMap *fieldMap)
{
    return fieldMap->tcblSys;
}

struct FieldTaskManager *FIELDMAP_GetTaskManager(FieldMap *fieldMap)
{
    return fieldMap->taskManager;
}

void FIELDMAP_SetTargetPos(FieldMap *fieldMap, const VecFx32 *targetPos)
{
    fieldMap->targetPos = targetPos;
}

struct FieldMsgWin *FIELDMAP_GetInfoWindow(FieldMap *fieldMap)
{
    return fieldMap->infoWindow;
}

void FIELDMAP_SetInfoWindow(FieldMap *fieldMap, struct FieldMsgWin *infoWindow)
{
    fieldMap->infoWindow = infoWindow;
}

struct Sodateya *FIELDMAP_GetSodateya(FieldMap *fieldMap)
{
    return fieldMap->sodateya;
}

struct AreaData *FIELDMAP_GetAreaData(FieldMap *fieldMap)
{
    return fieldMap->areaData;
}

void FIELDMAP_InitBgSystem(FieldMap *fieldMap)
{
    BG_SYS_Create(fieldMap->heapId);
    BG_SYS_LoadPltt(0, sClearPalette, 0x20, 0);
    BG_SYS_LoadPltt(4, sClearPalette, 0x20, 0);
    BG_SYS_SetLcdSwap(1);
    BG_SYS_ResetSubDisplay();
    REG_DISPCNT &= ~0xE000;
}

void FIELDMAP_SetBgMode(void)
{
    BG_SYS_SetGraphicsMode(&sBgModeSetup);
}

void FIELDMAP_ResetBgAffineShowMsg(FieldMap *fieldMap)
{
    u32 affineMtx[4];

    BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)affineMtx, 0, (const void *)0x1000, (const void *)0x1000, 0);
    G2x_SetBGyAffine_(0x04000020, affineMtx, 0, 0, 0, 0);
    BG_SYS_SetLowBit(3);
    FIELD_MSGBG_SetupBg(fieldMap->msgBg);
}

void FIELDMAP_ResetBgAffineHideMsg(FieldMap *fieldMap)
{
    u32 affineMtx[4];

    BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)affineMtx, 0, (const void *)0x1000, (const void *)0x1000, 0);
    G2x_SetBGyAffine_(0x04000020, affineMtx, 0, 0, 0, 0);
    BG_SYS_SetLowBit(3);
    FIELD_MSGBG_SetupBgDelayed(fieldMap->msgBg);
}

struct FldVReq *FIELDMAP_GetVReq(FieldMap *fieldMap)
{
    return fieldMap->vreq;
}

int FIELDMAP_ExitBgSystem(FieldMap *fieldMap)
{
    return BG_SYS_Delete(G3D_SYSTEM_Exit(NNS_G3dGeFlushBuffer(BG_SYS_SetLcdSwap(1))));
}

void FIELDMAP_SetupG3d(void)
{
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xFFFFCFFD;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x10;
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFFB;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 8;
    G3X_SetFog(0, 0, 5, 0xE00);
    *(volatile u32 *)0x04000358 = 0x7FFF;
    G3X_SetFogTable(sFogTable);
    G3X_SetClearColor(0, 0x1F, 0x7FFF, 0, 0);
    G3X_SetEdgeColorTable(sEdgeColorTable);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u32 *)0x04000580 = 0xBFFF0000;
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}

void FIELDMAP_CreateG3dResources(FieldMap *fieldMap)
{
    VecFx32 groundScale;
    VecFx32 cameraUp;
    u8 groundDrawFlag;
    void *board;
    u16 heapId;

    fieldMap->mmdlBbdAct = BILLBOARD_ACT_Create(0x40, 0x80, FIELDMAP_BbdActTransCallback, fieldMap->heapId);
    board = BILLBOARD_ACT_GetBoard(fieldMap->mmdlBbdAct);
    BILLBOARD_SetQuadShape(board, 2);
    BILLBOARD_SetImageOffset(board, 0, -0xA00);
    fieldMap->effectBbdAct = BILLBOARD_ACT_Create(0x3A, 0x50, FIELDMAP_BbdActTransCallback, fieldMap->heapId);
    fieldMap->groundBbdAct = BILLBOARD_ACT_Create(0x1E, 0x28, FIELDMAP_BbdActTransCallback, fieldMap->heapId);
    board = BILLBOARD_ACT_GetBoard(fieldMap->groundBbdAct);
    groundScale = sGroundBbdScale;
    BILLBOARD_SetScale(board, &groundScale);
    groundDrawFlag = 0;
    BILLBOARD_SetPolyIdBase(board, &groundDrawFlag);
    FIELDMAP_SetupBbdColor(fieldMap);
    fieldMap->g3dObjCtrl = FIELD_G3DOBJ_Create(fieldMap->heapId, 0x40, 0x40);
    heapId = fieldMap->heapId;
    cameraUp = sCameraUp;
    fieldMap->g3dCamera = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                        &sCameraPos, &cameraUp, &sCameraTarget, heapId);
    fieldMap->g3dLight = G3D_LIGHT_CreateSlots((const struct LightSet *)sLightSetup, fieldMap->heapId);
    G3D_CAMERA_Reset(fieldMap->g3dCamera);
    G3D_LIGHT_ApplySlots(fieldMap->g3dLight);
}

void FIELDMAP_UpdateG3d(FieldMap *fieldMap)
{
    u32 mapperBusy;

    BILLBOARD_ACT_UpdateEntries(fieldMap->mmdlBbdAct);
    BILLBOARD_ACT_UpdateEntries(fieldMap->effectBbdAct);
    BILLBOARD_ACT_UpdateEntries(fieldMap->groundBbdAct);
    FIELD_NOGRID_MAPPER_Main(fieldMap->nogridMapper);
    FLD_SCENEAREA_Update(fieldMap->sceneArea, &fieldMap->nowPos);
    FIELD_ZONEFOG_Main(fieldMap->zoneFog, fieldMap->heapId);
    WEATHER_Update(fieldMap->weather, 0x92);
    FIELD_FOG_Main(fieldMap->fog);
    FIELD_LIGHT_Main(fieldMap->light, GF_STANDARD_GetTime());
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    mapperBusy = FIELD_G3D_MAPPER_UpdateStep(fieldMap->g3dMapper);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    if (mapperBusy != 0)
        GFL_NET_SetDeviceModeIfRunning(2);
}

void FIELDMAP_DrawStart(FieldMap *fieldMap)
{
    FieldMapDrawFunc drawFunc;
    func_02047964();
    G3D_SYSTEM_ApplyLookAt();
    drawFunc = sDrawStartFuncs[fieldMap->drawMode];
    if (drawFunc != 0)
        drawFunc(fieldMap);
}

void FIELDMAP_DrawEnd(FieldMap *fieldMap)
{
    G3D_SYSTEM_DrawEnd(sDrawEndFuncs[fieldMap->drawMode](fieldMap));
}

int FIELDMAP_DeleteG3dResources(FieldMap *fieldMap)
{
    func_02048C4C(fieldMap->g3dLight);
    G3D_CAMERA_Delete(fieldMap->g3dCamera);
    BILLBOARD_ACT_Delete(fieldMap->mmdlBbdAct);
    BILLBOARD_ACT_Delete(fieldMap->effectBbdAct);
    BILLBOARD_ACT_Delete(fieldMap->groundBbdAct);
    return FIELD_G3DOBJ_Delete(fieldMap->g3dObjCtrl);
}

void FIELDMAP_VBlankTask(struct GFL_TCB *tcb, void *work)
{
    FieldMap *fieldMap = work;
    if (GFL_USE_IsCardIrqEnabled() == 0) {
        if (fieldMap->mmdlSys != 0)
            FLDMMDL_UpdateSysBlAct(fieldMap->mmdlSys);
        if (fieldMap->g3dObjCtrl != 0)
            FIELD_G3DOBJ_Update(fieldMap->g3dObjCtrl);
    }
    CLACT_VBlankSystem();
    if (fieldMap->vreq != 0)
        FLD_VREQ_VBlank(fieldMap->vreq);
}

void FIELDMAP_BbdActTransCallback(int vramTransfer, int destAddr, void *src, int size)
{
    NNS_GfdRegisterNewVramTransferTask((void *)(vramTransfer == 0 ? B_FALSE : B_TRUE), destAddr, (u32)src, size);
}

void FIELDMAP_SetupEdgeMarking(struct AreaData *areaData, u32 zoneId)
{
    u32 edgeMarkType = func_020140E0(areaData);

    if (edgeMarkType == 0xFF) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
        return;
    }
    if (func_02013DB8(zoneId) != 0)
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    else
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
    ARC_TOOL_ReadMember(data_021EE700, 0xF, edgeMarkType);
    data_021EE700b[7] = 0x4210;
    G3X_SetEdgeColorTable(data_021EE700);
}

void FIELDMAP_SetupBbdColor(FieldMap *fieldMap)
{
    u16 colorHeapId = (fieldMap->heapId & 0x7FFF) | 0x8000;
    void *bbdColor;
    u32 colorId;

    colorId = func_020140E4(fieldMap->areaData);
    bbdColor = FIELD_BBD_COLOR_Create(colorHeapId);
    FIELD_BBD_COLOR_Load(bbdColor, colorId);
    FIELD_BBD_COLOR_Apply(bbdColor, BILLBOARD_ACT_GetBoard(fieldMap->mmdlBbdAct));
    FIELD_BBD_COLOR_Delete(bbdColor);
}

void FIELDMAP_SetupMmdlSys(FieldMap *fieldMap)
{
    struct GameData *gameData;
    u32 zoneId;
    struct MmdlSys *mmdlSys;
    u32 sex;

    gameData = GAMESYSTEM_GetGameData(fieldMap->gameSystem);
    mmdlSys = GAME_DATA_GetOccupyInfo(gameData);
    fieldMap->mmdlSys = mmdlSys;
    FLDMMDL_SetupSysProc(mmdlSys, fieldMap->heapId, gameData, fieldMap, fieldMap->g3dMapper, fieldMap->nogridMapper);
    FLDMMDL_BLACT_Init(fieldMap->mmdlSys, fieldMap->mmdlBbdAct, 0x20);
    FLDMMDL_BLACT_AddCachedRes(fieldMap->mmdlSys);
    zoneId = fieldMap->location.zoneId;
    if (ZONEDATA_IsZone1A6(zoneId) == 0 && ZONEDATA_IsZone96Pair(zoneId) == 0) {
        sex = INTRUDE_FIELD_GetHostGender(GAMESYSTEM_GetGameComm(fieldMap->gameSystem));
    } else {
        sex = func_02008550(GAME_DATA_GetMyStatus(gameData));
    }
    FLDMMDL_BLACT_AddResByCode(mmdlSys, FIELD_PLAYER_GetObjCodeOfFormCode(sex, 0));
    FLDMMDL_G3DOBJ_Create(fieldMap->mmdlSys, fieldMap->g3dObjCtrl);
    FLDMMDL_SetAreaIdRef(fieldMap->mmdlSys, FIELD_CAMERA_GetViewYawPtr(fieldMap->camera));
    FLDMMDL_SysPopAll(fieldMap->mmdlSys);
    FLDMMDL_SysSetDrawEnable(mmdlSys, FIELDMAP_IsMmdlDrawEnabled(fieldMap->zoneId));
}

int FIELDMAP_DeleteMmdlSys(FieldMap *fieldMap)
{
    FLDMMDL_SysPushAll(fieldMap->mmdlSys);
    FLDMMDL_DeleteSysProc(fieldMap->mmdlSys);
    fieldMap->mmdlSys = 0;
    return 0;
}

u32 FIELDMAP_UpdateZoneChange(FieldMap *fieldMap)
{
    void *eventData;

    if (FIELDMAP_CheckPlayerMoved(fieldMap) == 1 && FIELDMAP_CheckZoneBoundary(fieldMap) == 1) {
        FIELDMAP_ChangeZone(fieldMap);
        return 1;
    }
    eventData = GAME_DATA_GetEventData(fieldMap->gameData);
    if (EVENTDATA_SYSTEM_IsEncountDataLoaded(eventData) == 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        EVENTDATA_SYSTEM_LoadEncountData(eventData, fieldMap->location.zoneId, GAME_DATA_GetSeason(fieldMap->gameData));
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    return 0;
}

int FIELDMAP_CheckPlayerMoved(FieldMap *fieldMap)
{
    VecFx32 lastPos;
    FieldMapLocation *location;
    VecFx32 *playerPos;

    location = &fieldMap->location;
    playerPos = GAME_DATA_GetPlayerPosition(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(fieldMap->gameSystem)));
    ZONEDATA_GetLocationVec(location, &lastPos);
    if (playerPos->x != lastPos.x || playerPos->z != lastPos.z) {
        ZONEDATA_SetLocationVec(location, playerPos);
        return 1;
    }
    return 0;
}

u32 FIELDMAP_CheckZoneBoundary(FieldMap *fieldMap)
{
    VecFx32 pos;
    FieldMapLocation *location;
    struct MapMatrix *mapMatrix;
    int zoneId;

    location = &fieldMap->location;
    mapMatrix = GAME_DATA_GetFieldWork(fieldMap->gameData);
    ZONEDATA_GetLocationVec(location, &pos);
    if (MAP_MATRIX_IsInRangeByPos(mapMatrix, pos.x, pos.z) == 1) {
        zoneId = MAP_MATRIX_GetZoneIdByPos(mapMatrix, pos.x, pos.z);
        if (zoneId != 0xFFFF && zoneId != (s16)location->zoneId)
            return 1;
    }
    return 0;
}

void FIELDMAP_ChangeZone(FieldMap *fieldMap)
{
    FieldMapLocation *location = &fieldMap->location;
    struct GameData *gameData;
    u32 zoneId;
    VecFx32 pos;
    void *eventData;
    struct MmdlSys *mmdlSys;
    struct MapMatrix *mapMatrix;

    gameData = GAMESYSTEM_GetGameData(fieldMap->gameSystem);
    eventData = GAME_DATA_GetEventData(gameData);
    mmdlSys = fieldMap->mmdlSys;
    mapMatrix = GAME_DATA_GetFieldWork(fieldMap->gameData);
    GFL_NET_SetDeviceModeIfRunning(2);
    EFFECT_ENCOUNT_Reset(fieldMap->encount);
    ZONEDATA_GetLocationVec(location, &pos);
    zoneId = MAP_MATRIX_GetZoneIdByPos(mapMatrix, pos.x, pos.z);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FLDMMDL_SysDeleteZoneChangeMmdl(mmdlSys);
    EVENTDATA_SYSTEM_Clear(eventData);
    EVENTDATA_SYSTEM_LoadEventData(eventData, zoneId, GAME_DATA_GetSeason(gameData));
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    FIELD_MAP_CHANGE_ApplyZoneHeader(gameData, fieldMap);
    FIELDMAP_ChangeZoneSound(fieldMap, zoneId);
    FIELDMAP_ChangeZoneFog(fieldMap, zoneId);
    FIELDMAP_ChangeZoneWeather(fieldMap, zoneId);
    FIELDMAP_ChangeZoneCamera(fieldMap, zoneId);
    FIELDMAP_SetPlayerZoneId(gameData, zoneId);
    FIELDMAP_SetupSceneArea(fieldMap, zoneId);
    if (fieldMap->placeName != 0 && GAMESYSTEM_IsEventActive(fieldMap->gameSystem) == 0)
        FIELD_PLACE_NAME_OnZoneChange(fieldMap->placeName, zoneId);
    location->zoneId = (s16)zoneId;
    GAME_BEACON_SetZone((u16)zoneId, gameData);
    MAP_REPLACE_SetArriveFlag(gameData, zoneId);
    SCRIPT_SYS_RunZoneChangeScript(fieldMap->gameSystem, (void *)4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FIELDMAP_AddZoneNpcs(gameData, mmdlSys, eventData, zoneId);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    INTRUDE_COMM_ClearHoldMode(GAMESYSTEM_GetGameComm(fieldMap->gameSystem));
}

void FIELDMAP_AddZoneNpcs(struct GameData *gameData, struct MmdlSys *mmdlSys, void *eventData, int zoneId)
{
    int npcCount = EVENTDATA_SYSTEM_GetNpcCount(eventData);
    int eventWork;
    if (npcCount != 0) {
        eventWork = GAME_DATA_GetEventWork(gameData);
        FLDMMDL_AddMmdlHeaderList(mmdlSys, EVENTDATA_SYSTEM_GetNpcHeaders(eventData), zoneId, npcCount, eventWork);
    }
}

void FIELDMAP_ChangeZoneSound(FieldMap *fieldMap, unsigned int zoneId)
{
    struct GameData *gameData;
    void *issSys;
    void *bgmInfo;
    int objCode;

    gameData = GAMESYSTEM_GetGameData(fieldMap->gameSystem);
    issSys = (void *)GAMESYSTEM_GetIssSystem(fieldMap->gameSystem);
    bgmInfo = (void *)GAME_DATA_GetBgmInfo(gameData);
    objCode = GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(gameData));
    ISS_SYS_ChangeZone((u32)issSys, zoneId);
    if (objCode != 2)
        func_02029CF0(bgmInfo, gameData, zoneId);
}

void FIELDMAP_ChangeZoneWeather(FieldMap *fieldMap, int zoneId)
{
    struct WeatherSys *weather = FIELDMAP_GetWeather(fieldMap);
    unsigned short weatherId;
    ISS_SWITCH_ApplySubscreenMode(fieldMap->gameSystem, zoneId);
    weatherId = (int)GAME_DATA_GetSubscreenMode(fieldMap->gameData);
    if (weatherId != 0xF)
        WEATHER_RequestChange(weather, weatherId);
}

void FIELDMAP_ChangeZoneFog(FieldMap *fieldMap, int zoneId)
{
    int fogId;
    FIELD_ZONEFOG_Clear(FIELDMAP_GetZoneFog(fieldMap));
    fogId = (int)func_02013EEC((unsigned short)zoneId);
    FIELD_ZONEFOG_SetUp(fieldMap->zoneFog, fogId, ZONEDATA_GetLightId(zoneId), 1);
}

int FIELDMAP_SetPlayerZoneId(struct GameData *gameData, u32 zoneId)
{
    return (int)GAME_DATA_SetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData), ((zoneId << 16) >> 16));
}

void FIELDMAP_ChangeZoneCamera(FieldMap *fieldMap, u32 zoneId)
{
    FIELDMAP_SetupCameraArea(fieldMap, zoneId, fieldMap->heapId);
}

FieldMap *FIELDMAP_ClearCtrlWork(FieldMap *fieldMap)
{
    fieldMap->ctrlWork = 0;
    return fieldMap;
}

void FIELDMAP_SetupCameraArea(FieldMap *fieldMap, int zoneId, int heapId)
{
    int cameraAreaId = func_02013BD0(zoneId);
    if (cameraAreaId != 0xFFFF)
        FIELD_CAMERA_LoadAreas(fieldMap->camera, cameraAreaId, heapId);
    else
        FIELD_CAMERA_ClearAreas(fieldMap->camera);
}

void FIELDMAP_SetupWfbc(struct GameData *gameData, FieldMap *fieldMap, u16 zoneId)
{
    struct FieldStatus *fieldStatus;
    int mapMode;
    void *wfbcData;
    void *buildModel;

    fieldStatus = GAME_DATA_GetMoveModelSys(gameData);
    if (ZONEDATA_IsZoneInTableDFC0(fieldMap->zoneId) != 0) {
        mapMode = FIELD_STATUS_GetMapMode(fieldStatus);
        if (mapMode == 0)
            wfbcData = GAME_DATA_GetSecondUnionInfo(fieldMap->gameData);
        else
            wfbcData = GAME_DATA_GetUnionInfo(fieldMap->gameData, 0);
        FIELD_G3D_MAPPER_SetupWfbc(fieldMap->g3dMapper, wfbcData, mapMode);
        buildModel = FIELD_G3D_MAPPER_GetWfbc(fieldMap->g3dMapper);
        FIELD_WFBC_DisableUnusedConnects(buildModel, GAME_DATA_GetEventData(gameData), mapMode, fieldMap->heapId);
        FIELD_WFBC_SetUpCamera(buildModel, fieldMap->camera, fieldMap->heapId);
        FIELD_WFBC_SetMmdlSys(buildModel, GAME_DATA_GetOccupyInfo(fieldMap->gameData));
    }
}

void FIELDMAP_SetupSceneArea(FieldMap *fieldMap, unsigned int zoneId)
{
    int sceneId;
    int areaData;
    int areaCount;

    sceneId = ZONEDATA_GetSecondSpecialKind(zoneId);
    if (sceneId != 0xFFFF) {
        FLD_SCENEAREA_ClearData(fieldMap->sceneArea);
        FLD_SCENEAREA_LOADER_Unload(fieldMap->sceneAreaLoader);
        FLD_SCENEAREA_LOADER_Load(fieldMap->sceneAreaLoader, 1, sceneId, 0x96);
        areaData = FLD_SCENEAREA_LOADER_GetRecs(fieldMap->sceneAreaLoader);
        areaCount = FLD_SCENEAREA_LOADER_GetRecCount(fieldMap->sceneAreaLoader);
        FLD_SCENEAREA_SetData(fieldMap->sceneArea, areaData, areaCount, FLD_SCENEAREA_LOADER_GetCallbacks(fieldMap->sceneAreaLoader));
        return;
    }
    if (ZONEDATA_HasSpecialKind((u16)zoneId) == 0) {
        FLD_SCENEAREA_ClearData(fieldMap->sceneArea);
        FLD_SCENEAREA_LOADER_Unload(fieldMap->sceneAreaLoader);
    }
}

int FIELDMAP_GetCommKind(struct GameComm *gameComm)
{
    int commKind = GAME_COMM_GetKind(gameComm);
    switch (commKind) {
    case 0:
        if (GFL_NET_ERR_GetErrorLevel() != 0)
            commKind = GAME_COMM_GetLastKind(gameComm);
        return commKind;
    case 1:
    case 2:
    case 5:
        return commKind;
    }
    return 2;
}

int FIELDMAP_CheckCommExit(struct GameComm *gameComm)
{
    if (GAME_COMM_GetKind(gameComm) == 0) {
        return 1;
    }
    if (GAME_COMM_IsTransition(gameComm) == 0) {
        GAME_COMM_RequestExitNoCallback(gameComm);
    }
    return 0;
}

void FIELDMAP_InitCommonWork(FieldMapCommonWork *commonWork)
{
    commonWork->id = -1;
    commonWork->buf = 0;
}

void *FIELDMAP_AllocCommonWork(FieldMap *fieldMap, int id, int heapId, int size)
{
    FieldMapCommonWork *commonWork = &fieldMap->commonWork;
    if (id == -1)
        return 0;
    if (commonWork->id != -1)
        return 0;
    commonWork->id = id;
    return commonWork->buf = GFL_HEAP_Alloc(heapId, size, 1, sFieldMapSourceName, 0xD7C);
}

void FIELDMAP_FreeCommonWork(FieldMap *fieldMap, int id)
{
    FieldMapCommonWork *commonWork = &fieldMap->commonWork;
    if (id != -1) {
        GFL_HEAP_Free(commonWork->buf);
        commonWork->id = -1;
    }
}

void *FIELDMAP_GetCommonWork(FieldMap *fieldMap, int id)
{
    FieldMapCommonWork *commonWork = &fieldMap->commonWork;
    if (id == -1)
        return 0;
    if (id != commonWork->id)
        return 0;
    return commonWork->buf;
}

int FIELDMAP_ReflectFog(FieldMap *fieldMap, u32 fogEnable, u32 fogSlope, u32 fogOffset)
{
    FIELD_FOG_Reflect(fieldMap->fog, fogEnable, fogSlope, fogOffset);
    FIELD_LIGHT_Reflect(fieldMap->light, 0);
    G3D_CAMERA_Reset(fieldMap->g3dCamera);
    G3D_LIGHT_ApplySlots(fieldMap->g3dLight);
    return FIELD_G3D_MAPPER_Draw(fieldMap->g3dMapper, fieldMap->g3dCamera, 0);
}

void FIELDMAP_Draw3dNormal(FieldMap *fieldMap)
{
    MtxFx44 savedProj;
    MtxFx44 proj;

    if (fieldMap->msgBg != 0)
        FIELD_MSGBG_DrawTalkSys(fieldMap->msgBg);
    FIELD_G3D_MAPPER_Draw(fieldMap->g3dMapper, fieldMap->g3dCamera, 1);
    FIELDSKILL_MAPEFF_Apply(fieldMap->mapEff);
    savedProj = g_DefaultProjectionMtx;
    proj = savedProj;
    proj.m[3][2] += FX_MUL(proj.m[2][2], fieldMap->projDepthOffset);
    MIi_CpuCopyFast(&proj, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    NNS_G3dGeFlushBuffer(NNS_G3dGlbFlush());
    FIELD_EFFECT_Draw(fieldMap->effect);
    FIELD_G3DOBJ_DrawAll(fieldMap->g3dObjCtrl);
    LIST_PopFront(fieldMap->mmdlBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    LIST_PopFront(fieldMap->groundBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    if (fieldMap->unionEff != 0)
        UNION_EFF_Draw(fieldMap->unionEff);
    proj = savedProj;
    proj.m[3][2] += FX_MUL(proj.m[2][2], fieldMap->projDepthOffset / 2);
    MIi_CpuCopyFast(&proj, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    NNS_G3dGeFlushBuffer(NNS_G3dGlbFlush());
    LIST_PopFront(fieldMap->effectBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    MIi_CpuCopyFast(&savedProj, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    NNS_G3dGlbFlush();
    FIELD_SUBPROC_MGR_RunDraw(fieldMap->mapFunc);
    WEATHER_Draw(fieldMap->weather);
    FLD_EXP_OBJ_Draw(fieldMap->expObj);
    FLD_PARTICLE_Exit();
    FLD3D_CI_DrawEffect(fieldMap->fld3dCi);
}

void FIELDMAP_Draw3dParticle(FieldMap *fieldMap)
{
    G3X_SetClearColor(0, 0, 0x7FFF, 0, 0);
    FLD_PARTICLE_Exit();
    FLD3D_CI_DrawEffect(fieldMap->fld3dCi);
}

void FIELDMAP_Draw3dEncEff(FieldMap *fieldMap)
{
    G3X_SetClearColor(0x4210, 0x1F, 0x7FFF, 0, 0);
    ENCEFF_RunUpdate(fieldMap->encEff);
}

int FIELDMAP_GetDrawMode(FieldMap *fieldMap)
{
    return fieldMap->drawMode;
}

void FIELDMAP_SetDrawMode(FieldMap *fieldMap, int drawMode)
{
    fieldMap->drawMode = drawMode;
}

struct Fld3dCi *FIELDMAP_GetFld3dCi(FieldMap *fieldMap)
{
    return fieldMap->fld3dCi;
}

struct EncEff *FIELDMAP_GetEncEff(FieldMap *fieldMap)
{
    return fieldMap->encEff;
}

struct FieldSkillMapEff *FIELDMAP_GetMapEff(FieldMap *fieldMap)
{
    return fieldMap->mapEff;
}

struct FldSceneArea *FIELDMAP_GetSceneArea(FieldMap *fieldMap)
{
    return fieldMap->sceneArea;
}

void FIELDMAP_SetScriptEffectBusy(FieldMap *fieldMap, int busy)
{
    fieldMap->scriptEffectBusy = busy;
}

int FIELDMAP_GetScriptEffectBusy(FieldMap *fieldMap)
{
    return fieldMap->scriptEffectBusy;
}

int FIELDMAP_IsEventActive(FieldMap *fieldMap)
{
    return GAMESYSTEM_IsEventActive(fieldMap->gameSystem);
}

int FIELDMAP_GetTimeZone(FieldMap *fieldMap)
{
    return TIMEZONE_GetNowTimeZone(GAME_DATA_GetSeason(fieldMap->gameData));
}

int FIELDMAP_GetSubscreenBusy(FieldMap *fieldMap)
{
    return fieldMap->subscreenBusy;
}

void FIELDMAP_SetSubscreenBusy(FieldMap *fieldMap, int busy)
{
    fieldMap->subscreenBusy = busy;
}

void FIELDMAP_SetUpdateStopped(FieldMap *fieldMap, int stopped)
{
    fieldMap->updateStopped = stopped;
}

void **FIELDMAP_GetFaceUpWorkPtr(FieldMap *fieldMap)
{
    return &fieldMap->faceUpWork;
}

void FIELDMAP_SetZoneEffectWork(FieldMap *fieldMap, void *zoneEffectWork)
{
    fieldMap->zoneEffectWork = zoneEffectWork;
}

void *FIELDMAP_GetZoneEffectWork(FieldMap *fieldMap)
{
    return fieldMap->zoneEffectWork;
}

int FIELDMAP_GetCameraPitchScale(FieldMap *fieldMap)
{
    return fieldMap->cameraPitchScale;
}

int FIELDMAP_CalcCameraPitchScale(FieldMap *fieldMap)
{
    unsigned short *pitch = (unsigned short *)FIELD_CAMERA_GetViewPitchPtr(fieldMap->camera);
    int sinIndex = (*pitch >> 4) * 2 + 1;
    int sinValue = FX_SinCosTable_[sinIndex];
    long long scaled;
    int pitchScale;
    if (sinValue < 0)
        sinValue = -sinValue;
    scaled = ((long long)sinValue << 14) + 0x800;
    pitchScale = (int)(scaled >> 12) - 0x4000;
    if (pitchScale < -0x2000)
        pitchScale = -0x2000;
    return pitchScale;
}

int FIELDMAP_GetProjDepthOffset(u32 zoneId)
{
    if (func_02013BA8(zoneId) == 1)
        return 0x1EE;
    return 0x136;
}

int FIELDMAP_IsMmdlDrawEnabled(int zoneId)
{
    if (zoneId == 0x3f)
        return 0;
    if (ZONEDATA_IsZone96Pair(zoneId) == 1)
        return 0;
    return 1;
}

int FIELDMAP_IsLoaderWaitZone(int zoneId)
{
    if (zoneId == 0x3F)
        return 1;
    if (zoneId == 0x8C)
        return 1;
    if (zoneId == 0x8D)
        return 1;
    if (zoneId == 0x8E)
        return 1;
    return 0;
}

u32 FIELDMAP_GetMapType(u32 zoneId)
{
    return func_02013B50(zoneId);
}

void FIELDMAP_SetupMapperParam(int zoneId, struct AreaData *areaData, FieldMapMapperParam *param, struct MapMatrix *mapMatrix)
{
    int mapType = (int)FIELDMAP_GetMapType((unsigned int)zoneId);
    *param = sMapTypeTable[mapType].param;
    if (sMapTypeTable[mapType].useMatrix != 0) {
        param->matrixWidth = MAP_MATRIX_GetWidth(mapMatrix);
        param->matrixHeight = MAP_MATRIX_GetHeight(mapMatrix);
        param->matrixCount = MAP_MATRIX_GetCount(mapMatrix);
        param->matrixGrid = MAP_MATRIX_GetMapGrid(mapMatrix);
    }
    param->enabled = 1;
    param->blockLoadMax = 0xe;
    param->texSetId = func_020140BC(areaData);
    param->itaAnimeId = func_020140C0(areaData);
    param->itpAnimeId = func_020140CC(areaData);
}

const FieldMapCtrlFuncs *FIELDMAP_GetCtrlFuncs(int zoneId)
{
    return gMapTypeCtrlTable[(int)FIELDMAP_GetMapType((unsigned int)zoneId)].ctrlFuncs;
}
