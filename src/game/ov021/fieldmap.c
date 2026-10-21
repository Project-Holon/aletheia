/*
 * file:     fieldmap.c
 * unit:     yes
 * function: FIELDMAP_ProcInit, FIELDMAP_ProcMain, FIELDMAP_ProcExit, FIELDMAP_Create, FIELDMAP_Delete, FIELDMAP_SeqInitSystem, FIELDMAP_SeqCreateSubsystems, FIELDMAP_SeqStart, FIELDMAP_SeqUpdate, FIELDMAP_UpdateCameraAndDraw, FIELDMAP_SeqUpdateTop, FIELDMAP_SeqDeleteSubsystems, FIELDMAP_SeqExitSystem, FIELDMAP_Main, FIELDMAP_RequestClose, FIELDMAP_IsReady, FIELDMAP_ApplyPlayerFormRequest, FIELDMAP_GetMsgBg, FIELDMAP_GetCamera, FIELDMAP_GetNogridMapper, FIELDMAP_GetLight, FIELDMAP_GetFog, FIELDMAP_GetZoneFog, FIELDMAP_GetWeather, FIELDMAP_GetZoneWeatherId, FIELDMAP_GetMmdlSys, FIELDMAP_GetGameSystem, FIELDMAP_GetHeapId, FIELDMAP_GetEffectBbdAct, FIELDMAP_GetGroundBbdAct, FIELDMAP_GetG3dMapper, FIELDMAP_GetZoneId, FIELDMAP_GetCtrlWork, FIELDMAP_SetCtrlWork, FIELDMAP_GetFieldPlayer, FIELDMAP_IsFieldPlayerCreated, FIELDMAP_GetSubscreen, FIELDMAP_GetEffect, FIELDMAP_GetG3dObjCtrl, FIELDMAP_GetUnionEff, FIELDMAP_GetEncount, FIELDMAP_GetCtrlType, FIELDMAP_GetMoveKind, FIELDMAP_GetPlaceName, FIELDMAP_GetMapFunc, FIELDMAP_GetExpObj, FIELDMAP_GetTcblSys, FIELDMAP_GetTaskManager, FIELDMAP_SetTargetPos, FIELDMAP_GetInfoWindow, FIELDMAP_SetInfoWindow, FIELDMAP_GetSodateya, FIELDMAP_GetAreaData, FIELDMAP_InitBgSystem, FIELDMAP_SetBgMode, FIELDMAP_ResetBgAffineShowMsg, FIELDMAP_ResetBgAffineHideMsg, FIELDMAP_GetVReq, FIELDMAP_ExitBgSystem, FIELDMAP_SetupG3d, FIELDMAP_CreateG3dResources, FIELDMAP_UpdateG3d, FIELDMAP_DrawStart, FIELDMAP_DrawEnd, FIELDMAP_DeleteG3dResources, FIELDMAP_VBlankTask, FIELDMAP_BbdActTransCallback, FIELDMAP_SetupEdgeMarking, FIELDMAP_SetupBbdColor, FIELDMAP_SetupMmdlSys, FIELDMAP_DeleteMmdlSys, FIELDMAP_UpdateZoneChange, FIELDMAP_CheckPlayerMoved, FIELDMAP_CheckZoneBoundary, FIELDMAP_ChangeZone, FIELDMAP_AddZoneNpcs, FIELDMAP_ChangeZoneSound, FIELDMAP_ChangeZoneWeather, FIELDMAP_ChangeZoneFog, FIELDMAP_SetPlayerZoneId, FIELDMAP_ChangeZoneCamera, FIELDMAP_ClearCtrlWork, FIELDMAP_SetupCameraArea, FIELDMAP_SetupWfbc, FIELDMAP_SetupSceneArea, FIELDMAP_GetCommKind, FIELDMAP_CheckCommExit, FIELDMAP_InitCommonWork, FIELDMAP_AllocCommonWork, FIELDMAP_FreeCommonWork, FIELDMAP_GetCommonWork, FIELDMAP_ReflectFog, FIELDMAP_Draw3dNormal, FIELDMAP_Draw3dParticle, FIELDMAP_Draw3dEncEff, FIELDMAP_GetDrawMode, FIELDMAP_SetDrawMode, FIELDMAP_GetFld3dCi, FIELDMAP_GetEncEff, FIELDMAP_GetMapEff, FIELDMAP_GetSceneArea, FIELDMAP_SetScriptEffectBusy, FIELDMAP_GetScriptEffectBusy, FIELDMAP_IsEventActive, FIELDMAP_GetTimeZone, FIELDMAP_GetSubscreenBusy, FIELDMAP_SetSubscreenBusy, FIELDMAP_SetUpdateStopped, FIELDMAP_GetFaceUpWorkPtr, FIELDMAP_SetZoneEffectWork, FIELDMAP_GetZoneEffectWork, FIELDMAP_GetCameraPitchScale, FIELDMAP_CalcCameraPitchScale, FIELDMAP_GetProjDepthOffset, FIELDMAP_IsMmdlDrawEnabled, FIELDMAP_IsLoaderWaitZone, FIELDMAP_GetMapType, FIELDMAP_SetupMapperParam, FIELDMAP_GetCtrlFuncs
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
 *   GAMESYSTEM_SetFieldMap  0x02012110  thumb
 *   GAMESYSTEM_IsAlwaysNetFlagSet  0x0201214C  thumb
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
 *   GF_FONT_InitTextColor  0x0201DD60  thumb
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_G3D_MAPPER_Create  0x0218C9E8  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   FIELD_TASK_MANAGER_Create  0x021C6D10  thumb
 *   FLD_VREQ_Create  0x021D317C  thumb
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   UI_ChangeFrameRate  0x02035660  arm
 *   FIELD_MAP_CHANGE_Empty  0x0216447C  thumb  ov010
 *   FIELD_MSGBG_Create  0x021901EC  thumb  ov021
 *   FIELD_PLACE_NAME_Create  0x021BC388  thumb  ov021
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetMapEffectMask  0x02014470  thumb
 *   FIELDSKILL_MAPEFF_Create  0x021C7F70  thumb  ov021
 *   ZONEDATA_GetCameraId  0x02013BBC  thumb
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
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   FIELD_PLAYER_Create  0x021A2E50  thumb  ov021
 *   FIELD_G3D_MAPPER_SetFocusPos  0x0218D158  thumb  ov021
 *   FLD_EXP_OBJ_Create  0x021BE2A8  thumb  ov021
 *   FIELD_FOG_Create  0x021A0104  thumb  ov021
 *   FIELD_ZONEFOG_Create  0x021A02C4  thumb  ov021
 *   ZONEDATA_GetFogId  0x02013EEC  thumb
 *   ZONEDATA_GetLightId  0x02013F2C  thumb
 *   FIELD_ZONEFOG_SetUp  0x021A0338  thumb  ov021
 *   ZONEDATA_GetAreaLightType  0x020140DC  thumb
 *   GF_STANDARD_GetSecondsOfDay  0x0203F4FC  arm
 *   FIELD_LIGHT_Create  0x021A03D0  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   WEATHER_Create  0x021A19E8  thumb  ov021
 *   GAME_DATA_GetWeatherId  0x02012994  thumb
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
 *   FIELD_STATUS_GetFieldInitFlag  0x02014458  thumb
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
 *   UI_ResetFrameCounter  0x02035648  arm
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   FIELD_CLOCK_Update  0x02168EEC  thumb  ov010
 *   FIELD_PLACE_NAME_Main  0x021BC484  thumb  ov021
 *   FIELDSKILL_MAPEFF_Update  0x021C7FAC  thumb  ov021
 *   FIELD_PLAYER_SaveToPlayerWork  0x021A2EB8  thumb  ov021
 *   UNION_MAIN_UpdateField  0x021737A4  thumb  ov012
 *   INTRUDE_FIELD_Update  0x0217AE20  thumb  ov018
 *   FIELD_SUBSCREEN_Main  0x021A0D68  thumb  ov021
 *   FIELD_GIMMICK_RunMapCallback  0x021BE258  thumb  ov021
 *   UNION_EFF_Main  0x0217F914  thumb  ov019
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
 *   RECORD_AddOne  0x02008DF0  thumb
 *   WEATHER_GetZoneWeatherId  0x0202C794  thumb
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
 *   BG_SYS_EnableBg0WithPriority  0x0204044C  arm
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
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   sDrawStartFuncs     0x021D35D8  data  a4
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   sDrawEndFuncs     0x021D35B4  data  a4
 *   G3D_LIGHT_DeleteSlots  0x02048C4C  arm
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   BILLBOARD_ACT_Delete  0x0204FFFC  arm
 *   FIELD_G3DOBJ_Delete  0x021C6400  thumb  ov021
 *   GFL_USE_IsCardIrqEnabled  0x02005C8C  thumb
 *   FLDMMDL_UpdateSysBlAct  0x0216CD78  thumb  ov010
 *   FIELD_G3DOBJ_Update  0x021C6470  thumb  ov021
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   FLD_VREQ_VBlank  0x021D31AC  thumb  ov021
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   ZONEDATA_GetAreaEdgeMarkType  0x020140E0  thumb
 *   ZONEDATA_IsRawZoneGroup121To13C  0x02013DB8  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   data_021EE700  0x021EE700  data  a4
 *   data_021EE700b  0x021EE700  data
 *   ZONEDATA_GetAreaBillboardColor  0x020140E4  thumb
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
 *   FIELD_SOUND_SYSTEM_PostZoneBgmChange  0x02029CF0  thumb
 *   WEATHER_StoreZoneWeatherId  0x0202C83C  thumb
 *   WEATHER_RequestChange  0x021A1BDC  thumb  ov021
 *   FIELD_ZONEFOG_Clear  0x021A0358  thumb  ov021
 *   GAME_DATA_SetPlayerZoneId  0x02012AC4  thumb
 *   ZONEDATA_GetCameraAreaId  0x02013BD0  thumb
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
 *   BILLBOARD_ACT_Draw    0x02050790  arm
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
 *   ZONEDATA_GetMapChangeType  0x02013BA8  thumb
 *   ZONEDATA_GetMapType  0x02013B50  thumb
 *   MAP_MATRIX_GetWidth  0x02159BF4  thumb  ov010
 *   MAP_MATRIX_GetHeight  0x02159BF8  thumb  ov010
 *   MAP_MATRIX_GetCount  0x02159BFC  thumb  ov010
 *   MAP_MATRIX_GetMapGrid  0x02159C20  thumb  ov010
 *   ZONEDATA_GetAreaTexSetId  0x020140BC  thumb
 *   ZONEDATA_GetAreaItaAnimeId  0x020140C0  thumb
 *   ZONEDATA_GetAreaItpAnimeId  0x020140CC  thumb
 *   sMapTypeTable     0x021D3700  data  a4
 *   gMapTypeCtrlTable     0x021D373C  data  a4
 */
#include "fieldmap_types.h"
#include "../sdk_ioreg_reg.h"

typedef int (*FieldMapSeqFunc)(struct GameSystem *gameSystem, FieldMap *fieldMap);
typedef int (*FieldMapEventCheckFunc)(struct GameSystem *gameSystem, void *work);

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
#include "../types.h"

typedef enum { B_FALSE, B_TRUE } Bool;

#include "../sdk_fx.h"

/* NNS_G3dGlb (NitroSystem); fieldmap.c only clears bits of the flag word. */
typedef struct G3dGlobalState {
    u8 otherState[0x7C];    /* 0x00: not touched here */
    u32 flag;               /* 0x7C */
} G3dGlobalState;

typedef void (*FieldMapDrawFunc)(FieldMap *fieldMap);
typedef int (*FieldMapDrawEndFunc)(FieldMap *fieldMap);

#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
#include "field_event_check.h"
#include "../arm9/arc_tool.h"
#include "../arm9/billboard.h"
#include "../arm9/billboard_act.h"
#include "../arm9/bmp_win.h"
#include "../arm9/comm_player_support.h"
#include "../arm9/daycare.h"
#include "../arm9/field_status.h"
#include "../arm9/g3d_camera.h"
#include "../arm9/gf_font.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/gf_standard.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gfl_use.h"
#include "../arm9/key.h"
#include "../arm9/mi_memory.h"
#include "../arm9/mystatus.h"
#include "../arm9/net.h"
#include "../arm9/net_err.h"
#include "../arm9/nns_gfd_vram_transfer.h"
#include "../arm9/procsys.h"
#include "../arm9/record.h"
#include "../arm9/timezone.h"
#include "../arm9/ui.h"
#include "../arm9/wm_icon.h"
#include "../ov010/eventdata_system.h"
#include "../ov010/field_clock.h"
#include "../ov010/field_map_change.h"
#include "../ov010/fldmmdl.h"
#include "../ov010/intrude_comm_query.h"
#include "../ov010/map_matrix.h"
#include "../ov010/map_replace.h"
#include "../ov010/script_sys.h"
#include "../ov012/union_main.h"
#include "../ov018/intrude_field.h"
#include "../ov019/union_eff.h"
#include "effect_encount.h"
#include "enceff.h"
#include "field_bbd_color.h"
#include "field_buildmodel.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_encount.h"
#include "field_gimmick.h"
#include "field_light.h"
#include "field_msgbg.h"
#include "field_nogrid_mapper.h"
#include "field_palace_sys.h"
#include "field_place_name.h"
#include "field_player.h"
#include "field_subscreen.h"
#include "field_task_manager.h"
#include "field_zonefog.h"
#include "fieldmap_ctrl_hybrid.h"
#include "fieldmap_func.h"
#include "fieldskill_mapeff.h"
#include "fld3d_ci.h"
#include "fld_exp_obj.h"
#include "fld_particle.h"
#include "fld_vreq.h"
#include "fldmmdl_blact.h"
#include "fldmmdl_g3dobj.h"
#include "pleasure_boat.h"
#include "sodateya.h"
struct Proc;
#include "../arm9/game_comm.h"
/* Original DS prototype: the DS code passes plain ints and takes the area data as a struct pointer; the host build uses the header. */
#ifdef __MWERKS__
#define ZONEDATA_CreateAreaData ZONEDATA_CreateAreaData_header
#define ZONEDATA_SetExitLocation ZONEDATA_SetExitLocation_header
#define ZONEDATA_GetLightId ZONEDATA_GetLightId_header
#define ZONEDATA_GetCameraAreaId ZONEDATA_GetCameraAreaId_header
#endif
#include "../arm9/zonedata.h"
#ifdef __MWERKS__
#undef ZONEDATA_CreateAreaData
#undef ZONEDATA_SetExitLocation
#undef ZONEDATA_GetLightId
#undef ZONEDATA_GetCameraAreaId
extern int ZONEDATA_GetLightId(unsigned short id);
extern unsigned short ZONEDATA_GetCameraAreaId(unsigned short id);
extern void ZONEDATA_SetExitLocation(struct Location *loc, u16 zoneId, u16 exitId, u16 dir, u16 exitOffset, u32 x, u32 y, u32 z);
extern struct AreaData *ZONEDATA_CreateAreaData(int heapId, int areaId, int infoCode);
#endif
struct PlayerInfo;
#include "../arm9/bg_sys.h"
struct DispVramCfg;
struct SysInit;
#include "../arm9/clact.h"
struct FieldG3dMapper;
#include "field_g3d_mapper.h"
#include "field_g3dobj.h"
struct Tcb;
#include "../arm9/tcb_list.h"
struct TcbSystem;
struct FldVReq;
struct FieldMsgContext;
struct FieldPlaceName;
struct FieldSkillMapEff;
struct FldSceneArea;
#include "field_wfbc.h"
#include "fld_scenearea.h"
#include "fld_scenearea_loader.h"
struct FldSceneAreaLoader;
struct FieldNogridMapper;
struct FieldPalaceSys;
struct BuildModelMan;
struct BuildModelMan;
struct FieldG3dObjCtrl;
struct Location;
struct FieldG3dMapperSetup;
struct FieldEffectSys;
struct UnionEffWork;
struct MyStatus;
struct FieldMap;
struct FieldPlayer;
struct FldExpObjCnt;
/* Original DS prototype: the DS code passes the three fog values to FIELD_FOG_Reflect; the host build uses the header. */
#ifdef __MWERKS__
#define FIELD_FOG_Reflect FIELD_FOG_Reflect_header
#endif
#include "field_fog.h"
#ifdef __MWERKS__
#undef FIELD_FOG_Reflect
extern void FIELD_FOG_Reflect(FieldFog *fog, u32 fogEnable, u32 fogSlope, u32 fogOffset);
#endif
struct LightSlot;
/* Original DS prototype: the DS code passes plain ints for the zone and heap ids; the host build uses the header. */
#ifdef __MWERKS__
#define WEATHER_Create WEATHER_Create_header
#endif
#include "weather.h"
#ifdef __MWERKS__
#undef WEATHER_Create
extern WeatherSys *WEATHER_Create(struct FieldCamera *camera, struct FieldLight *light, struct FieldFog *fog, struct FieldZoneFog *zoneFog, struct FieldSoundSystem *soundSys, int zoneId, int heapId);
#endif
struct FieldSubscreen;
struct FieldSubprocMgr;
struct FieldMap;
struct EncEffWork;
struct SaveControl;
struct DaycareSave;
struct SodateyaWork;
struct MmdlSys;
struct GameEvent;
struct PleasureBoatWork;
/* Original DS prototype: the DS code passes plain unsigned values; the host build uses the header. */
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_Init_header
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u32 fifoSize, u32 heap, void (*setup)(void));
#endif
struct TcbTask;
#include "../arm9/zone_weather.h"
struct FieldMapCtrlHybridWork;
extern struct DispConfig sBgModeSetup;
#include "../arm9/button_man.h"
#include "../arm9/g2.h"
#include "../arm9/nns_g3d_ge.h"
#include "../arm9/g3x.h"
extern struct BbActSys *BILLBOARD_ACT_Create(u16 slotCount, u16 entryCount, void (*transCallback)(int, int, void *, int), int heapId);
struct BbBoard;
struct Blk3;
struct LightSetDesc;
struct LightSlotValue;
#include "../arm9/g3d_light.h"
struct FieldBbdColor;
struct EventDataSystem;
#include "../arm9/game_beacon.h"
struct MmdlHeader;
#include "../arm9/iss_sys.h"
/* Original DS prototype: the DS code passes the zone id as a halfword; the host build uses the header. */
#ifdef __MWERKS__
#define FIELD_SOUND_SYSTEM_PostZoneBgmChange FIELD_SOUND_SYSTEM_PostZoneBgmChange_header
#endif
#include "../arm9/field_sound_system.h"
#ifdef __MWERKS__
#undef FIELD_SOUND_SYSTEM_PostZoneBgmChange
extern void FIELD_SOUND_SYSTEM_PostZoneBgmChange(struct FieldSoundSystem *soundSys, struct GameData *gameData, u16 zoneId);
#endif
struct UnionInfo;
struct FieldWfbc;
#include "../arm9/nns_g3d_glb.h"
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
u32 FIELDMAP_ApplyPlayerFormRequest(FieldMap *fieldMap);
struct FieldMsgBg *FIELDMAP_GetMsgBg(FieldMap *fieldMap);
struct FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);
struct FieldNogridMapper *FIELDMAP_GetNogridMapper(FieldMap *fieldMap);
struct FieldLight *FIELDMAP_GetLight(FieldMap *fieldMap);
struct FieldFog *FIELDMAP_GetFog(FieldMap *fieldMap);
struct FieldZoneFog *FIELDMAP_GetZoneFog(FieldMap *fieldMap);
struct WeatherSys *FIELDMAP_GetWeather(FieldMap *fieldMap);
int FIELDMAP_GetZoneWeatherId(FieldMap *fieldMap, int switchId);
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
struct FieldEffectSys *FIELDMAP_GetEffect(FieldMap *fieldMap);
struct FieldG3dObjCtrl *FIELDMAP_GetG3dObjCtrl(FieldMap *fieldMap);
struct UnionEff *FIELDMAP_GetUnionEff(FieldMap *fieldMap);
struct FieldEncount *FIELDMAP_GetEncount(FieldMap *fieldMap);
unsigned int FIELDMAP_GetCtrlType(FieldMap *fieldMap);
u32 FIELDMAP_GetMoveKind(FieldMap *fieldMap);
struct FieldPlaceName *FIELDMAP_GetPlaceName(FieldMap *fieldMap);
struct FieldmapFunc *FIELDMAP_GetMapFunc(FieldMap *fieldMap);
struct FldExpObjCnt *FIELDMAP_GetExpObj(FieldMap *fieldMap);
struct TcbSystem *FIELDMAP_GetTcblSys(FieldMap *fieldMap);
struct FieldTaskManager *FIELDMAP_GetTaskManager(FieldMap *fieldMap);
void FIELDMAP_SetTargetPos(FieldMap *fieldMap, const VecFx32 *targetPos);
struct FieldMsgWin *FIELDMAP_GetInfoWindow(FieldMap *fieldMap);
void FIELDMAP_SetInfoWindow(FieldMap *fieldMap, struct FieldMsgWin *infoWindow);
struct SodateyaWork *FIELDMAP_GetSodateya(FieldMap *fieldMap);
struct AreaData *FIELDMAP_GetAreaData(FieldMap *fieldMap);
void FIELDMAP_InitBgSystem(FieldMap *fieldMap);
void FIELDMAP_SetBgMode(void);
void FIELDMAP_ResetBgAffineShowMsg(FieldMap *fieldMap);
void FIELDMAP_ResetBgAffineHideMsg(FieldMap *fieldMap);
struct FldVReq *FIELDMAP_GetVReq(FieldMap *fieldMap);
void FIELDMAP_ExitBgSystem(FieldMap *fieldMap);
void FIELDMAP_SetupG3d(void);
void FIELDMAP_CreateG3dResources(FieldMap *fieldMap);
void FIELDMAP_UpdateG3d(FieldMap *fieldMap);
void FIELDMAP_DrawStart(FieldMap *fieldMap);
void FIELDMAP_DrawEnd(FieldMap *fieldMap);
void FIELDMAP_DeleteG3dResources(FieldMap *fieldMap);
void FIELDMAP_VBlankTask(struct TcbTask *tcb, void *work);
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
void FIELDMAP_ReflectFog(FieldMap *fieldMap, u32 fogEnable, u32 fogSlope, u32 fogOffset);
void FIELDMAP_Draw3dNormal(FieldMap *fieldMap);
void FIELDMAP_Draw3dParticle(FieldMap *fieldMap);
void FIELDMAP_Draw3dEncEff(FieldMap *fieldMap);
int FIELDMAP_GetDrawMode(FieldMap *fieldMap);
void FIELDMAP_SetDrawMode(FieldMap *fieldMap, int drawMode);
struct Fld3dCi *FIELDMAP_GetFld3dCi(FieldMap *fieldMap);
struct EncEffWork *FIELDMAP_GetEncEff(FieldMap *fieldMap);
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
extern const struct ClactSysInit sClactSetup;
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
            FieldMapProcWork *work = PROCSYS_AllocProcWork((struct Proc *)proc, sizeof(FieldMapProcWork), 0x15);
            FieldMap *fieldMap = FIELDMAP_Create(gameSystem, 0x15);
            work->fieldMap = fieldMap;
            GAMESYSTEM_SetFieldMap(gameSystem, fieldMap);
        }
        (*seq)++;
        break;
    case 1:
        if (GAMESYSTEM_IsAlwaysNetFlagSet(gameSystem) == 0) {
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
    GAMESYSTEM_SetFieldMap(gameSystem, 0);
    PROCSYS_FreeProcWork((struct Proc *)proc);
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
        fieldMap->areaData = ZONEDATA_CreateAreaData(heapId, areaId, COMM_PLAYER_SUPPORT_GetInfoCode((struct PlayerInfo *)gameSystem));
    }
    fieldMap->ctrlFuncs = FIELDMAP_GetCtrlFuncs(fieldMap->zoneId);
    return fieldMap;
}

void FIELDMAP_Delete(FieldMap *fieldMap)
{
    struct GameSystem *gameSystem = fieldMap->gameSystem;
    ZONEDATA_DeleteAreaData(fieldMap->areaData);
    GFL_HEAP_Free(fieldMap);
    GAMESYSTEM_SetFieldMap(gameSystem, 0);
    GFL_NET_WM_ICON_SetDefaultPos(0, 0);
}

int FIELDMAP_SeqInitSystem(struct GameSystem *gameSystem, FieldMap *fieldMap)
{
    u16 heapId = fieldMap->heapId;
    BG_SYS_SetVramBanks((const struct DispVram *)sVramBankSetup);
    FIELDMAP_InitBgSystem(fieldMap);
    CLACT_InitSystem(&sClactSetup, (struct DispVramCfg *)sVramBankSetup, 0x89);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    BMP_WIN_Init(heapId);
    GF_FONT_InitTextColor();
    G3D_SYSTEM_Init(0, 3, 0, 1, 0x1000, fieldMap->heapId, FIELDMAP_SetupG3d);
    FIELDMAP_CreateG3dResources(fieldMap);
    fieldMap->g3dMapper = FIELD_G3D_MAPPER_Create(fieldMap->heapId, GAME_DATA_GetSeason(fieldMap->gameData));
    fieldMap->vblankTcb = (struct TcbTask *)GFL_USE_AddMainTask(FIELDMAP_VBlankTask, fieldMap, 0);
    fieldMap->tcblWork = GFL_HEAP_Alloc(heapId, TCB_GetTaskOffset(0x20), 0, sFieldMapSourceName, 0x26B);
    fieldMap->tcblSys = TCB_Init(0x20, fieldMap->tcblWork);
    fieldMap->taskManager = FIELD_TASK_MANAGER_Create(0xA, fieldMap->heapId);
    fieldMap->vreq = FLD_VREQ_Create(fieldMap->heapId);
    GF_OVERLAY_Load((ZONEDATA_IsUnionRoom(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1) ? (sptr)abs_id_19 : (sptr)abs_id_18);
    UI_ChangeFrameRate(0x1E);
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
        fieldMap->placeName = FIELD_PLACE_NAME_Create(gameSystem, 0x93, (struct FieldMsgContext *)msgBg);
        fieldMap->mapEff = FIELDSKILL_MAPEFF_Create(FIELD_STATUS_GetMapEffectMask(GAME_DATA_GetMoveModelSys(fieldMap->gameData)), fieldMap->heapId);
        fieldMap->camera = FIELD_CAMERA_Create(ZONEDATA_GetCameraId(fieldMap->zoneId), 0, fieldMap->g3dCamera, &fieldMap->nowPos, fieldMap->heapId);
        fieldMap->sceneArea = FLD_SCENEAREA_Create(fieldMap->heapId, fieldMap->camera, fieldMap);
        fieldMap->sceneAreaLoader = FLD_SCENEAREA_LOADER_Create(fieldMap->heapId);
        break;
    }
    case 1: {
        void *buildModel;
        void *palTable;
        fieldMap->nogridMapper = FIELD_NOGRID_MAPPER_Create((u32)fieldMap->heapId, (uptr)fieldMap->camera, fieldMap->sceneArea, fieldMap->sceneAreaLoader);
        fieldMap->palaceSys = FIELD_PALACE_SYS_Create(fieldMap->heapId, gameSystem, fieldMap, fieldMap->zoneId);
        buildModel = FIELD_G3D_MAPPER_GetBuildModel(fieldMap->g3dMapper);
        FIELDMAP_SetupMapperParam(fieldMap->zoneId, fieldMap->areaData, &fieldMap->mapperParam, (struct MapMatrix *)GAME_DATA_GetFieldWork(fieldMap->gameData));
        GAMESYSTEM_GetGameComm(fieldMap->gameSystem);
        palTable = FIELD_PALACE_SYS_GetPalTable(fieldMap->palaceSys);
        FIELD_BUILDMODEL_LoadArea(buildModel, (s32)fieldMap->zoneId, (sptr)fieldMap->areaData, (sptr)palTable);
        FIELD_G3DOBJ_SetPalTable(fieldMap->g3dObjCtrl, palTable);
        FIELDMAP_SetupWfbc(gameData, fieldMap, fieldMap->zoneId);
        break;
    }
    case 2: {
        int specialKind;
        ZONEDATA_SetExitLocation((struct Location *)(&fieldMap->location), fieldMap->zoneId, 0, 0, 0, fieldMap->nowPos.x, fieldMap->nowPos.y, fieldMap->nowPos.z);
        GAMESYSTEM_GetGameComm(fieldMap->gameSystem);
        FIELD_G3D_MAPPER_Setup(fieldMap->g3dMapper, (struct FieldG3dMapperSetup *)(&fieldMap->mapperParam), FIELD_PALACE_SYS_GetPalTable(fieldMap->palaceSys));
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
        FIELD_EFFECT_InitObjectSystem((struct FieldEffectSys *)fieldMap->effect, 0x5e);
        FIELD_EFFECT_SetPaletteTable((struct FieldEffectSys *)fieldMap->effect, (uptr)FIELD_PALACE_SYS_GetPalTable(fieldMap->palaceSys));
        FIELD_EFFECT_LoadResources((struct FieldEffectSys *)fieldMap->effect, sFieldEffectTaskTable, sFieldEffectTaskCount);
        if (ZONEDATA_IsUnionRoom(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1) {
            fieldMap->unionEff = (struct UnionEff *)UNION_EFF_Create(fieldMap->heapId);
        }
        break;
    case 4: {
        struct PlayerWork *playerWork;
        int dirType;
        VecFx32 *playerPos;
        int value;
        struct FieldSoundSystem *soundSys;
        int season;
        playerWork = GAMESYSTEM_GetMyPlayerWork(gameSystem);
        dirType = GAME_DATA_GetPlayerDirectionType(playerWork);
        playerPos = (VecFx32 *)((u8 *)playerWork + 4);
        if (GAME_DATA_GetPlayerObjectCode(playerWork) == 1 && ZONEDATA_IsBikeEnabled(fieldMap->zoneId) == 0) {
            GAME_DATA_SetPlayerObjectCode(playerWork, 0);
        }
        fieldMap->player = FIELD_PLAYER_Create(playerWork, fieldMap, playerPos, MYSTATUS_GetSex(GAME_DATA_GetMyStatus(gameData)), fieldMap->heapId);
        fieldMap->nowPos = *playerPos;
        fieldMap->ctrlFuncs->create(fieldMap, &fieldMap->nowPos, dirType);
        FIELD_G3D_MAPPER_SetFocusPos(fieldMap->g3dMapper, &fieldMap->nowPos);
        FIELDMAP_InitCommonWork(&fieldMap->commonWork);
        fieldMap->expObj = FLD_EXP_OBJ_Create(0x3c, 0x23, fieldMap->heapId);
        FIELDMAP_SetupEdgeMarking(fieldMap->areaData, FIELDMAP_GetZoneId(fieldMap));
        fieldMap->fog = FIELD_FOG_Create(fieldMap->heapId);
        fieldMap->zoneFog = FIELD_ZONEFOG_Create(fieldMap->heapId);
        value = ZONEDATA_GetFogId(fieldMap->zoneId);
        FIELD_ZONEFOG_SetUp(fieldMap->zoneFog, value, ZONEDATA_GetLightId(fieldMap->zoneId), 1);
        value = ZONEDATA_GetAreaLightType(fieldMap->areaData);
        season = GF_STANDARD_GetSecondsOfDay();
        fieldMap->light = FIELD_LIGHT_Create(value, season, COMM_PLAYER_SUPPORT_GetInfoCode((struct PlayerInfo *)gameSystem), fieldMap->fog, fieldMap->g3dLight, fieldMap->heapId);
        soundSys = GAME_DATA_GetBgmInfo(fieldMap->gameData);
        fieldMap->weather = WEATHER_Create(fieldMap->camera, fieldMap->light, fieldMap->fog, fieldMap->zoneFog, soundSys, COMM_PLAYER_SUPPORT_GetInfoCode((struct PlayerInfo *)gameSystem), 0x92);
        WEATHER_SetImmediate(fieldMap->weather, (u16)((int)GAME_DATA_GetWeatherId(fieldMap->gameData)), 0x92);
        FIELD_GIMMICK_Setup(fieldMap);
        break;
    }
    case 5:
        fieldMap->subscreen = FIELD_SUBSCREEN_Create(fieldMap->heapId, fieldMap, GAME_DATA_GetSubscreenType(gameData));
        break;
    case 6:
        fieldMap->encount = FIELD_ENCOUNT_Create(fieldMap);
        GAME_COMM_CallHandler(GAMESYSTEM_GetGameComm(gameSystem), (uptr)fieldMap);
        fieldMap->mapFunc = (struct FieldmapFunc *)FIELD_SUBPROC_MGR_Create(fieldMap, fieldMap->heapId, 0x20);
        fieldMap->particle = FLD_PARTICLE_Create(0x50);
        fieldMap->fld3dCi = FLD3D_CI_Create(0x50, fieldMap->particle);
        fieldMap->encEff = (struct EncEffWork *)ENCEFF_Create(fieldMap->heapId, fieldMap);
        fieldMap->sodateya = (struct SodateyaWork *)SODATEYA_Create(fieldMap->heapId, fieldMap, DAYCARE_GetFromSave(GAME_DATA_GetSaveControl(fieldMap->gameData)));
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
        FIELD_EFFECT_Update((struct FieldEffectSys *)fieldMap->effect);
        FIELD_SUBPROC_MGR_RunUpdate((struct FieldSubprocMgr *)fieldMap->mapFunc);
        fieldMap->subSeq++;
    case 1:
        if (FIELD_STATUS_GetContinueFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData)) == 1
            && FIELDMAP_IsLoaderWaitZone(fieldMap->zoneId) == 1
            && GFL_USE_IsLoaderBusy() != 0)
            return 0;
        if (FIELD_STATUS_GetFieldInitFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData)) != 0) {
            SCRIPT_SYS_RunFieldInitScript(fieldMap->gameSystem, fieldMap->heapId);
            FIELD_STATUS_SetFieldInitFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData), 0);
        } else {
            SCRIPT_SYS_RunFieldRecoverScript(fieldMap->gameSystem, fieldMap->heapId);
        }
        FIELD_STATUS_SetContinueFlag(GAME_DATA_GetMoveModelSys(fieldMap->gameData), 0);
        FIELD_G3D_MAPPER_UpdateBlocking(fieldMap->g3dMapper);
        if (ZONEDATA_IsUnionRoom(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1)
            GAMESYSTEM_SetEventCreator(gameSystem, (GameEventCreatorFn)FIELD_EVENT_CHECK_CheckCommEvents, fieldMap);
        else if (FIELDMAP_GetCtrlType(fieldMap) == 1)
            GAMESYSTEM_SetEventCreator(gameSystem, (GameEventCreatorFn)FIELD_EVENT_CHECK_RunRail, fieldMap);
        else if (FIELDMAP_GetCtrlType(fieldMap) == 2)
            GAMESYSTEM_SetEventCreator(gameSystem, (GameEventCreatorFn)FIELD_EVENT_CHECK_Run, fieldMap);
        else
            GAMESYSTEM_SetEventCreator(gameSystem, (GameEventCreatorFn)FIELD_EVENT_CHECK_RunGrid, fieldMap);
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
    UI_ResetFrameCounter();
    FIELDMAP_UpdateZoneChange(fieldMap);
    if (GAMESYSTEM_IsEventActive(gameSystem) == 0) {
        fieldMap->ctrlFuncs->main(fieldMap, &fieldMap->nowPos);
        FIELD_CLOCK_Update(fieldMap->gameData);
    }
    if (fieldMap->placeName != 0)
        FIELD_PLACE_NAME_Main(fieldMap->placeName);
    FIELDSKILL_MAPEFF_Update(fieldMap->mapEff);
    FIELD_PLAYER_SaveToPlayerWork(fieldMap->player);
    if (ZONEDATA_IsUnionRoom(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1)
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
    FIELD_EFFECT_Update((struct FieldEffectSys *)fieldMap->effect);
    if (fieldMap->unionEff != 0)
        UNION_EFF_Main((struct UnionEffWork *)fieldMap->unionEff);
    FIELD_SUBPROC_MGR_RunUpdate((struct FieldSubprocMgr *)fieldMap->mapFunc);
    if (fieldMap->msgBg != 0)
        FIELD_MSGBG_Main(fieldMap->msgBg);
    TCB_Main((struct TcbSystem *)fieldMap->tcblSys);
    FIELD_TASK_MANAGER_Update(fieldMap->taskManager);
    if (fieldMap->targetPos != 0)
        fieldMap->nowPos = *fieldMap->targetPos;
    FIELD_G3D_MAPPER_SetFocusPos(fieldMap->g3dMapper, &fieldMap->nowPos);
    FIELDMAP_UpdateG3d(fieldMap);
    PLEASURE_BOAT_AckEvent((struct PleasureBoatWork *)(*GAME_DATA_GetEventState(fieldMap->gameData)));
    CLACT_DrawSystem();
    FIELDMAP_UpdateCameraAndDraw(fieldMap);
    return 0;
}

void FIELDMAP_UpdateCameraAndDraw(FieldMap *fieldMap)
{
    volatile u16 *regPowerCnt = (volatile u16 *)REG_EXMEMCNT_ADDR;
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
    ENCEFF_Delete((struct EncEffWork *)fieldMap->encEff);
    FLD3D_CI_Delete(fieldMap->fld3dCi);
    FLD_PARTICLE_Delete(fieldMap->particle);
    GAMESYSTEM_SetEventCreator(gameSystem, 0, 0);
    FIELD_PLAYER_SaveToPlayerWork(fieldMap->player);
    FIELD_SUBPROC_MGR_Delete((struct FieldSubprocMgr *)fieldMap->mapFunc);
    GAME_COMM_CallKindNotify(GAMESYSTEM_GetGameComm(gameSystem), (uptr)fieldMap);
    if (fieldMap->placeName != 0)
        FIELD_PLACE_NAME_Delete(fieldMap->placeName);
    FIELD_GIMMICK_Exit(fieldMap);
    FLD_EXP_OBJ_Delete(fieldMap->expObj);
    FIELD_ENCOUNT_Delete(fieldMap->encount);
    GAME_DATA_SetSubscreenType(GAMESYSTEM_GetGameData(gameSystem), FIELD_SUBSCREEN_Delete(fieldMap->subscreen));
    FIELD_EFFECT_Delete((struct FieldEffectSys *)fieldMap->effect);
    if (fieldMap->unionEff != 0) {
        UNION_EFF_Delete((struct UnionEffWork *)fieldMap->unionEff);
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
    UI_ChangeFrameRate(0x3C);
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
    TCB_DeleteTask((struct TcbTask *)fieldMap->vblankTcb);
    FIELD_G3D_MAPPER_Delete(fieldMap->g3dMapper);
    FIELDMAP_DeleteG3dResources(fieldMap);
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    FIELDMAP_ExitBgSystem(fieldMap);
    if (ZONEDATA_IsUnionRoom(fieldMap->zoneId) == 1 || ZONEDATA_IsZone96Pair(fieldMap->zoneId) == 1)
        GF_OVERLAY_Unload((sptr)abs_id_13);
    else
        GF_OVERLAY_Unload((sptr)abs_id_12);
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

u32 FIELDMAP_ApplyPlayerFormRequest(FieldMap *fieldMap)
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
        RECORD_AddOne(GAME_DATA_GetTrainerRecord(fieldMap->gameData), 3);
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

int FIELDMAP_GetZoneWeatherId(FieldMap *fieldMap, int switchId)
{
    return WEATHER_GetZoneWeatherId(fieldMap->gameSystem, switchId);
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

struct FieldEffectSys *FIELDMAP_GetEffect(FieldMap *fieldMap)
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

struct TcbSystem *FIELDMAP_GetTcblSys(FieldMap *fieldMap)
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

struct SodateyaWork *FIELDMAP_GetSodateya(FieldMap *fieldMap)
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
    MtxFx22 affineMtx;

    BUTTON_MAN_RotScaleMtx22(&affineMtx, 0, 0x1000, 0x1000, 0);
    G2x_SetBGyAffine_(REG_BG2PA_ADDR, &affineMtx, 0, 0, 0, 0);
    BG_SYS_EnableBg0WithPriority(3);
    FIELD_MSGBG_SetupBg(fieldMap->msgBg);
}

void FIELDMAP_ResetBgAffineHideMsg(FieldMap *fieldMap)
{
    MtxFx22 affineMtx;

    BUTTON_MAN_RotScaleMtx22(&affineMtx, 0, 0x1000, 0x1000, 0);
    G2x_SetBGyAffine_(REG_BG2PA_ADDR, &affineMtx, 0, 0, 0, 0);
    BG_SYS_EnableBg0WithPriority(3);
    FIELD_MSGBG_SetupBgDelayed(fieldMap->msgBg);
}

struct FldVReq *FIELDMAP_GetVReq(FieldMap *fieldMap)
{
    return fieldMap->vreq;
}

void FIELDMAP_ExitBgSystem(FieldMap *fieldMap)
{
    BG_SYS_SetLcdSwap(1);
    NNS_G3dGeFlushBuffer();
    G3D_SYSTEM_Exit();
    BG_SYS_Delete();
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
    BILLBOARD_SetScale(board, (struct Blk3 *)(&groundScale));
    groundDrawFlag = 0;
    BILLBOARD_SetPolyIdBase(board, &groundDrawFlag);
    FIELDMAP_SetupBbdColor(fieldMap);
    fieldMap->g3dObjCtrl = FIELD_G3DOBJ_Create(fieldMap->heapId, 0x40, 0x40);
    heapId = fieldMap->heapId;
    cameraUp = sCameraUp;
    fieldMap->g3dCamera = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                        &sCameraPos, &cameraUp, &sCameraTarget, heapId);
    fieldMap->g3dLight = (struct LightSlot *)G3D_LIGHT_CreateSlots((struct LightSetDesc *)sLightSetup, fieldMap->heapId);
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
    FIELD_LIGHT_Main(fieldMap->light, GF_STANDARD_GetSecondsOfDay());
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    mapperBusy = FIELD_G3D_MAPPER_UpdateStep(fieldMap->g3dMapper);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    if (mapperBusy != 0)
        GFL_NET_SetDeviceModeIfRunning(2);
}

void FIELDMAP_DrawStart(FieldMap *fieldMap)
{
    FieldMapDrawFunc drawFunc;
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    drawFunc = sDrawStartFuncs[fieldMap->drawMode];
    if (drawFunc != 0)
        drawFunc(fieldMap);
}

void FIELDMAP_DrawEnd(FieldMap *fieldMap)
{
    sDrawEndFuncs[fieldMap->drawMode](fieldMap);
    G3D_SYSTEM_DrawEnd();
}

void FIELDMAP_DeleteG3dResources(FieldMap *fieldMap)
{
    G3D_LIGHT_DeleteSlots(fieldMap->g3dLight);
    G3D_CAMERA_Delete(fieldMap->g3dCamera);
    BILLBOARD_ACT_Delete(fieldMap->mmdlBbdAct);
    BILLBOARD_ACT_Delete(fieldMap->effectBbdAct);
    BILLBOARD_ACT_Delete(fieldMap->groundBbdAct);
    FIELD_G3DOBJ_Delete(fieldMap->g3dObjCtrl);
}

void FIELDMAP_VBlankTask(struct TcbTask *tcb, void *work)
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
    NNS_GfdRegisterNewVramTransferTask((void *)(vramTransfer == 0 ? B_FALSE : B_TRUE), destAddr, (uptr)src, size);
}

void FIELDMAP_SetupEdgeMarking(struct AreaData *areaData, u32 zoneId)
{
    u32 edgeMarkType = ZONEDATA_GetAreaEdgeMarkType(areaData);

    if (edgeMarkType == 0xFF) {
        *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
        return;
    }
    if (ZONEDATA_IsRawZoneGroup121To13C(zoneId) != 0)
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

    colorId = ZONEDATA_GetAreaBillboardColor(fieldMap->areaData);
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
    if (ZONEDATA_IsUnionRoom(zoneId) == 0 && ZONEDATA_IsZone96Pair(zoneId) == 0) {
        sex = INTRUDE_FIELD_GetHostGender(GAMESYSTEM_GetGameComm(fieldMap->gameSystem));
    } else {
        sex = MYSTATUS_GetSex(GAME_DATA_GetMyStatus(gameData));
    }
    FLDMMDL_BLACT_AddResByCode(mmdlSys, FIELD_PLAYER_GetObjCodeOfFormCode(sex, 0));
    FLDMMDL_G3DOBJ_Create((sptr)fieldMap->mmdlSys, (sptr)fieldMap->g3dObjCtrl);
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
    PlayerPosition *playerPos;

    location = &fieldMap->location;
    playerPos = GAME_DATA_GetPlayerPosition(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(fieldMap->gameSystem)));
    ZONEDATA_GetLocationVec((Location *)location, &lastPos);
    if (playerPos->x != lastPos.x || playerPos->z != lastPos.z) {
        ZONEDATA_SetLocationVec((Location *)location, (VecFx32 *)playerPos);
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
    mapMatrix = (struct MapMatrix *)GAME_DATA_GetFieldWork(fieldMap->gameData);
    ZONEDATA_GetLocationVec((Location *)location, &pos);
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
    mapMatrix = (struct MapMatrix *)GAME_DATA_GetFieldWork(fieldMap->gameData);
    GFL_NET_SetDeviceModeIfRunning(2);
    EFFECT_ENCOUNT_Reset(fieldMap->encount);
    ZONEDATA_GetLocationVec((Location *)location, &pos);
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
    GAME_BEACON_SetZone((u16)zoneId, (uptr)gameData);
    MAP_REPLACE_SetArriveFlag(gameData, zoneId);
    SCRIPT_SYS_RunZoneChangeScript(fieldMap->gameSystem, (s32)4);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FIELDMAP_AddZoneNpcs(gameData, mmdlSys, eventData, zoneId);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    INTRUDE_COMM_ClearHoldMode(GAMESYSTEM_GetGameComm(fieldMap->gameSystem));
}

void FIELDMAP_AddZoneNpcs(struct GameData *gameData, struct MmdlSys *mmdlSys, void *eventData, int zoneId)
{
    int npcCount = EVENTDATA_SYSTEM_GetNpcCount(eventData);
    sptr eventWork;
    if (npcCount != 0) {
        eventWork = (sptr)GAME_DATA_GetEventWork(gameData);
        FLDMMDL_AddMmdlHeaderList(mmdlSys, (struct MmdlHeader *)EVENTDATA_SYSTEM_GetNpcHeaders(eventData), zoneId, npcCount, (void *)eventWork);
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
    bgmInfo = GAME_DATA_GetBgmInfo(gameData);
    objCode = GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(gameData));
    ISS_SYS_ChangeZone(issSys, zoneId);
    if (objCode != 2)
        FIELD_SOUND_SYSTEM_PostZoneBgmChange(bgmInfo, gameData, zoneId);
}

void FIELDMAP_ChangeZoneWeather(FieldMap *fieldMap, int zoneId)
{
    struct WeatherSys *weather = FIELDMAP_GetWeather(fieldMap);
    unsigned short weatherId;
    WEATHER_StoreZoneWeatherId((struct Ctx *)fieldMap->gameSystem, zoneId);
    weatherId = (int)GAME_DATA_GetWeatherId(fieldMap->gameData);
    if (weatherId != 0xF)
        WEATHER_RequestChange(weather, weatherId);
}

void FIELDMAP_ChangeZoneFog(FieldMap *fieldMap, int zoneId)
{
    int fogId;
    FIELD_ZONEFOG_Clear(FIELDMAP_GetZoneFog(fieldMap));
    fogId = (int)ZONEDATA_GetFogId((unsigned short)zoneId);
    FIELD_ZONEFOG_SetUp(fieldMap->zoneFog, fogId, ZONEDATA_GetLightId(zoneId), 1);
}

int FIELDMAP_SetPlayerZoneId(struct GameData *gameData, u32 zoneId)
{
    return (sptr)GAME_DATA_SetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData), ((zoneId << 16) >> 16));
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
    int cameraAreaId = ZONEDATA_GetCameraAreaId(zoneId);
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
    struct FldSceneAreaRec *areaData;
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

void FIELDMAP_ReflectFog(FieldMap *fieldMap, u32 fogEnable, u32 fogSlope, u32 fogOffset)
{
#ifdef __MWERKS__
    FIELD_FOG_Reflect(fieldMap->fog, fogEnable, fogSlope, fogOffset);
#else
    FIELD_FOG_Reflect(fieldMap->fog);
#endif
    FIELD_LIGHT_Reflect(fieldMap->light, 0);
    G3D_CAMERA_Reset(fieldMap->g3dCamera);
    G3D_LIGHT_ApplySlots(fieldMap->g3dLight);
    FIELD_G3D_MAPPER_Draw(fieldMap->g3dMapper, fieldMap->g3dCamera, 0);
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
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
    FIELD_EFFECT_Draw(fieldMap->effect);
    FIELD_G3DOBJ_DrawAll(fieldMap->g3dObjCtrl);
    BILLBOARD_ACT_Draw(fieldMap->mmdlBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    BILLBOARD_ACT_Draw(fieldMap->groundBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    if (fieldMap->unionEff != 0)
        UNION_EFF_Draw((struct UnionEffWork *)fieldMap->unionEff);
    proj = savedProj;
    proj.m[3][2] += FX_MUL(proj.m[2][2], fieldMap->projDepthOffset / 2);
    MIi_CpuCopyFast(&proj, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    NNS_G3dGlbFlush();
    NNS_G3dGeFlushBuffer();
    BILLBOARD_ACT_Draw(fieldMap->effectBbdAct, fieldMap->g3dCamera, fieldMap->g3dLight);
    MIi_CpuCopyFast(&savedProj, &g_DefaultProjectionMtx, 0x40);
    SCREENTEX_CameraState.flag &= ~0x50;
    NNS_G3dGlbFlush();
    FIELD_SUBPROC_MGR_RunDraw((struct FieldSubprocMgr *)fieldMap->mapFunc);
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
    ENCEFF_RunUpdate((struct EncEffWork *)fieldMap->encEff);
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

struct EncEffWork *FIELDMAP_GetEncEff(FieldMap *fieldMap)
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
    if (ZONEDATA_GetMapChangeType(zoneId) == 1)
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
    return ZONEDATA_GetMapType(zoneId);
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
    param->texSetId = ZONEDATA_GetAreaTexSetId(areaData);
    param->itaAnimeId = ZONEDATA_GetAreaItaAnimeId(areaData);
    param->itpAnimeId = ZONEDATA_GetAreaItpAnimeId(areaData);
}

const FieldMapCtrlFuncs *FIELDMAP_GetCtrlFuncs(int zoneId)
{
    return gMapTypeCtrlTable[(int)FIELDMAP_GetMapType((unsigned int)zoneId)].ctrlFuncs;
}
