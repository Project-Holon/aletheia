/*
 * file:     fldmmdl_acmd.c
 * unit:     yes
 * function: FLDMMDL_ACMD_DeleteDrawSys, FLDMMDL_ACMD_DrawIfInitialized, FLDMMDL_ACMD_CheckAnimePaused, FLDMMDL_ACMD_GetDrawPos, FLDMMDL_ACMD_ListCreate, FLDMMDL_ACMD_ListCheckEnd, FLDMMDL_ACMD_ListDelete, FLDMMDL_ACMD_ListTaskMain, FLDMMDL_ACMD_ListStateStart, FLDMMDL_ACMD_ListStateWaitPossible, FLDMMDL_ACMD_ListStateSetCmd, FLDMMDL_ACMD_ListStateWaitEnd, FLDMMDL_ACMD_ListStateNext, FLDMMDL_ACMD_ListStateFinished, FLDMMDL_ACMD_ConvertCodeByDir, FLDMMDL_ACMD_RunCmds, FLDMMDL_ACMD_Update, FLDMMDL_ACMD_RunCmdStep, FLDMMDL_ACMD_EndCmd, FLDMMDL_ACMD_TurnInit, FLDMMDL_ACMD_DirUp, FLDMMDL_ACMD_DirDown, FLDMMDL_ACMD_DirLeft, FLDMMDL_ACMD_DirRight, FLDMMDL_ACMD_WalkInit, FLDMMDL_ACMD_WalkMove, FLDMMDL_ACMD_WalkUp32F, FLDMMDL_ACMD_WalkDown32F, FLDMMDL_ACMD_WalkLeft32F, FLDMMDL_ACMD_WalkRight32F, FLDMMDL_ACMD_WalkUp16F, FLDMMDL_ACMD_WalkDown16F, FLDMMDL_ACMD_WalkLeft16F, FLDMMDL_ACMD_WalkRight16F, FLDMMDL_ACMD_WalkUp8F, FLDMMDL_ACMD_WalkDown8F, FLDMMDL_ACMD_WalkLeft8F, FLDMMDL_ACMD_WalkRight8F, FLDMMDL_ACMD_WalkUp4F, FLDMMDL_ACMD_WalkDown4F, FLDMMDL_ACMD_WalkLeft4F, FLDMMDL_ACMD_WalkRight4F, FLDMMDL_ACMD_WalkUp2F, FLDMMDL_ACMD_WalkDown2F, FLDMMDL_ACMD_WalkLeft2F, FLDMMDL_ACMD_WalkRight2F, FLDMMDL_ACMD_WalkUp1F, FLDMMDL_ACMD_WalkDown1F, FLDMMDL_ACMD_WalkLeft1F, FLDMMDL_ACMD_WalkRight1F, FLDMMDL_ACMD_DashUp4F, FLDMMDL_ACMD_DashDown4F, FLDMMDL_ACMD_DashLeft4F, FLDMMDL_ACMD_DashRight4F, FLDMMDL_ACMD_WalkUp16FFastAnime, FLDMMDL_ACMD_WalkDown16FFastAnime, FLDMMDL_ACMD_WalkLeft16FFastAnime, FLDMMDL_ACMD_WalkRight16FFastAnime, FLDMMDL_ACMD_StayWalkInit, FLDMMDL_ACMD_StayWalkMove, FLDMMDL_ACMD_StayWalkUp32F, FLDMMDL_ACMD_StayWalkDown32F, FLDMMDL_ACMD_StayWalkLeft32F, FLDMMDL_ACMD_StayWalkRight32F, FLDMMDL_ACMD_StayWalkUp16F, FLDMMDL_ACMD_StayWalkDown16F, FLDMMDL_ACMD_StayWalkLeft16F, FLDMMDL_ACMD_StayWalkRight16F, FLDMMDL_ACMD_StayWalkUp8F, FLDMMDL_ACMD_StayWalkDown8F, FLDMMDL_ACMD_StayWalkLeft8F, FLDMMDL_ACMD_StayWalkRight8F, FLDMMDL_ACMD_StayWalkUp4F, FLDMMDL_ACMD_StayWalkDown4F, FLDMMDL_ACMD_StayWalkLeft4F, FLDMMDL_ACMD_StayWalkRight4F, FLDMMDL_ACMD_StayWalkUp2F, FLDMMDL_ACMD_StayWalkDown2F, FLDMMDL_ACMD_StayWalkLeft2F, FLDMMDL_ACMD_StayWalkRight2F, FLDMMDL_ACMD_JumpInit, FLDMMDL_ACMD_JumpInitWithSe, FLDMMDL_ACMD_JumpMove, FLDMMDL_ACMD_StayJumpUp16F, FLDMMDL_ACMD_StayJumpDown16F, FLDMMDL_ACMD_StayJumpLeft16F, FLDMMDL_ACMD_StayJumpRight16F, FLDMMDL_ACMD_StayJumpUp8F, FLDMMDL_ACMD_StayJumpDown8F, FLDMMDL_ACMD_StayJumpLeft8F, FLDMMDL_ACMD_StayJumpRight8F, FLDMMDL_ACMD_JumpUp1G8F, FLDMMDL_ACMD_JumpDown1G8F, FLDMMDL_ACMD_JumpLeft1G8F, FLDMMDL_ACMD_JumpRight1G8F, FLDMMDL_ACMD_JumpUp2G16F, FLDMMDL_ACMD_JumpDown2G16F, FLDMMDL_ACMD_JumpLeft2G16F, FLDMMDL_ACMD_JumpRight2G16F, FLDMMDL_ACMD_JumpLeft1G16F, FLDMMDL_ACMD_JumpRight1G16F, FLDMMDL_ACMD_JumpLeft3G12F, FLDMMDL_ACMD_JumpRight3G12F, FLDMMDL_ACMD_JumpUp3G24FNoSe, FLDMMDL_ACMD_JumpDown3G24FNoSe, FLDMMDL_ACMD_JumpLeft3G24FNoSe, FLDMMDL_ACMD_JumpRight3G24FNoSe, FLDMMDL_ACMD_WaitInit, FLDMMDL_ACMD_WaitMove, FLDMMDL_ACMD_Wait1F, FLDMMDL_ACMD_Wait2F, FLDMMDL_ACMD_Wait4F, FLDMMDL_ACMD_Wait8F, FLDMMDL_ACMD_Wait15F, FLDMMDL_ACMD_Wait16F, FLDMMDL_ACMD_Wait32F, FLDMMDL_ACMD_RiseInit, FLDMMDL_ACMD_RiseMove, FLDMMDL_ACMD_FallInit, FLDMMDL_ACMD_FallMove, FLDMMDL_ACMD_VanishOn, FLDMMDL_ACMD_VanishOff, FLDMMDL_ACMD_DirPauseOn, FLDMMDL_ACMD_DirPauseOff, FLDMMDL_ACMD_AnimePauseOn, FLDMMDL_ACMD_AnimePauseOff, FLDMMDL_ACMD_MarkInit, FLDMMDL_ACMD_MarkWait, FLDMMDL_ACMD_MarkGyoe, FLDMMDL_ACMD_MarkGyoeSlot1, FLDMMDL_ACMD_MarkGyoeSlot2, FLDMMDL_ACMD_MarkType1, FLDMMDL_ACMD_MarkType2, FLDMMDL_ACMD_MarkType3, FLDMMDL_ACMD_WalkTableInit, FLDMMDL_ACMD_WalkTableMove, FLDMMDL_ACMD_WalkUp6F, FLDMMDL_ACMD_WalkDown6F, FLDMMDL_ACMD_WalkLeft6F, FLDMMDL_ACMD_WalkRight6F, FLDMMDL_ACMD_DashUp6F, FLDMMDL_ACMD_DashDown6F, FLDMMDL_ACMD_DashLeft6F, FLDMMDL_ACMD_DashRight6F, FLDMMDL_ACMD_Walk6FMove, FLDMMDL_ACMD_WalkUp3F, FLDMMDL_ACMD_WalkDown3F, FLDMMDL_ACMD_WalkLeft3F, FLDMMDL_ACMD_WalkRight3F, FLDMMDL_ACMD_Walk3FMove, FLDMMDL_ACMD_WalkUp7F, FLDMMDL_ACMD_WalkDown7F, FLDMMDL_ACMD_WalkLeft7F, FLDMMDL_ACMD_WalkRight7F, FLDMMDL_ACMD_Walk7FMove, FLDMMDL_ACMD_WalkUp12F, FLDMMDL_ACMD_WalkDown12F, FLDMMDL_ACMD_WalkLeft12F, FLDMMDL_ACMD_WalkRight12F, FLDMMDL_ACMD_Walk12FMove, FLDMMDL_ACMD_AnimeDash4FStart, FLDMMDL_ACMD_AnimeDash6FStart, FLDMMDL_ACMD_AnimeDash2FStart, FLDMMDL_ACMD_AnimeDash4FStartSe, FLDMMDL_ACMD_AnimeDash6FStartSe, FLDMMDL_ACMD_AnimeWaitEndStop, FLDMMDL_ACMD_AnimeWaitEnd, FLDMMDL_ACMD_HideOffInit, FLDMMDL_ACMD_HideOffMove, FLDMMDL_ACMD_StayInit, FLDMMDL_ACMD_StayMove, FLDMMDL_ACMD_StayWalk32F40F, FLDMMDL_ACMD_StayWalk16F40F, FLDMMDL_ACMD_StayStop12F, FLDMMDL_ACMD_BounceInit, FLDMMDL_ACMD_BounceMove, FLDMMDL_ACMD_StepInit, FLDMMDL_ACMD_StepMove, FLDMMDL_ACMD_StepUpFaceLeft8F, FLDMMDL_ACMD_StepDownFaceRight8F, FLDMMDL_ACMD_StepLeftFaceDown8F, FLDMMDL_ACMD_StepRightFaceUp8F, FLDMMDL_ACMD_StepUpFaceRight8F, FLDMMDL_ACMD_StepDownFaceLeft8F, FLDMMDL_ACMD_StepLeftFaceUp8F, FLDMMDL_ACMD_StepLeftFaceDown8FAlt, FLDMMDL_ACMD_StepUpFaceDown8F, FLDMMDL_ACMD_StepDownFaceUp8F, FLDMMDL_ACMD_StepLeftFaceRight8F, FLDMMDL_ACMD_StepRightFaceLeft8F, FLDMMDL_ACMD_StepUpFaceDown4F, FLDMMDL_ACMD_StepDownFaceUp4F, FLDMMDL_ACMD_StepLeftFaceRight4F, FLDMMDL_ACMD_StepRightFaceLeft4F, FLDMMDL_ACMD_StepUpFaceDown2F, FLDMMDL_ACMD_StepDownFaceUp2F, FLDMMDL_ACMD_StepLeftFaceRight2F, FLDMMDL_ACMD_StepRightFaceLeft2F, FLDMMDL_ACMD_DashStepUpFaceLeft4F, FLDMMDL_ACMD_DashStepDownFaceRight4F, FLDMMDL_ACMD_DashStepLeftFaceDown4F, FLDMMDL_ACMD_DashStepRightFaceUp4F, FLDMMDL_ACMD_DashStepUpFaceRight4F, FLDMMDL_ACMD_DashStepDownFaceLeft4F, FLDMMDL_ACMD_DashStepLeftFaceUp4F, FLDMMDL_ACMD_DashStepLeftFaceDown4FAlt, FLDMMDL_ACMD_DashStepUpFaceDown4F, FLDMMDL_ACMD_DashStepDownFaceUp4F, FLDMMDL_ACMD_DashStepLeftFaceRight4F, FLDMMDL_ACMD_DashStepRightFaceLeft4F, FLDMMDL_ACMD_HopInit, FLDMMDL_ACMD_HopMove, FLDMMDL_ACMD_HopUpFaceLeft8F, FLDMMDL_ACMD_HopDownFaceRight8F, FLDMMDL_ACMD_HopLeftFaceDown8F, FLDMMDL_ACMD_HopRightFaceUp8F, FLDMMDL_ACMD_HopUpFaceRight8F, FLDMMDL_ACMD_HopDownFaceLeft8F, FLDMMDL_ACMD_HopLeftFaceUp8F, FLDMMDL_ACMD_HopLeftFaceDown8FAlt, FLDMMDL_ACMD_HopUpFaceDown8F, FLDMMDL_ACMD_HopDownFaceUp8F, FLDMMDL_ACMD_HopLeftFaceRight8F, FLDMMDL_ACMD_HopRightFaceLeft8F, FLDMMDL_ACMD_StayWalk22FInit, FLDMMDL_ACMD_StayWalk22FMove, FLDMMDL_ACMD_AnimeDash4FSetNext, FLDMMDL_ACMD_DashLeft2F, FLDMMDL_ACMD_Dash2FMove, FLDMMDL_ACMD_FlyUpInit, FLDMMDL_ACMD_FlyUpMove, FLDMMDL_ACMD_AnimeDash4FSetNextAlt, FLDMMDL_ACMD_AnimeDash6FSetAlt, FLDMMDL_ACMD_AnimeWaitEndFaceDown, FLDMMDL_ACMD_ResetDrawOffset, FLDMMDL_ACMD_FlyReadyInit, FLDMMDL_ACMD_FlyReadyMove, FLDMMDL_ACMD_AnimeDash4FSet, FLDMMDL_ACMD_AnimeDash6FSet, FLDMMDL_ACMD_AnimeDash2FSetReset, FLDMMDL_ACMD_DrawReadyWaitStop, FLDMMDL_ACMD_DrawReadyWait
 * address:  0x02197C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from ircbattlemenu.c at 0x02197C4C (lane CL131, __FILE__ fldmmdl_acmd.c on 0x02197D3C; 02197C4C..02197D3C work on fldmmdl objects and are called only from fldmmdl code).
 *
 * Joined by lane L138c with the former unit_02198D24.c and fldmmdl_acmd_p01.c (02198D24..0219A07C).
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_Exit  0x0219C5D0  thumb  ov021
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb
 *   FLDMMDL_G3DOBJ_Delete  0x0219D488  thumb  ov021
 *   FLDMMDL_SysSetDrawInit  0x0216D95C  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysCheckStatusBit  0x0216D4D4  thumb  ov010
 *   FLDMMDL_CheckMoveBitDrawInitComp  0x0216DAA0  thumb  ov010
 *   FLDMMDL_CallDrawProc  0x0216D758  thumb  ov010
 *   FLDMMDL_CheckMoveBitMovePause  0x0216DB10  thumb  ov010
 *   FLDMMDL_CheckMoveBitAcmd  0x0216DC4C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_GetDrawOffsetOutside  0x0216D8D0  thumb  ov010
 *   FLDMMDL_GetAttrOffset  0x0216D8F0  thumb  ov010
 *   FLDMMDL_GetModelOffset  0x0216D92C  thumb  ov010
 *   FLDMMDL_SysGetHeapId  0x0216D4F8  thumb  ov010
 *   FLDMMDL_SysGetTcbPriority  0x0216D4F4  thumb  ov010
 *   FLDMMDL_SysGetTcbSys  0x0216D514  thumb  ov010
 *   TCB_AddTask  0x02030DA8  arm
 *   d_021DDBE0  0x021DDBE0  data  a4
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   d_021D4A50  0x021D4A50  data  a4
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   d_021D5D6C  0x021D5D6C  data  a4
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 *   FLDMMDL_GetAcmdSeq  0x0216D7D4  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_SetAcmdCode  0x0216D7C0  thumb  ov010
 *   FLDMMDL_SetAcmdSeq  0x0216D7C8  thumb  ov010
 *   d_021D624C  0x021D624C  data  a4
 *   d_021D5F58  0x021D5F58  data  a4
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_MOVE_UpdateGridPosDir  0x02163E7C  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVectorPos  0x02163FC0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   d_021DDBD4  0x021DDBD4  data   ov021  a4
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 *   FLDEFF_GYOE_IsFinished  0x021BB5C8  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_ACMD_WalkTableMove  0x02198C4C  thumb
 *   FLDMMDL_ACMD_WalkTableInit  0x02198C08  thumb
 *   FLDMMDL_ACMD_AnimeDash4FStart  0x02198E44  thumb
 *   FLDMMDL_ACMD_AnimeDash6FStart  0x02198E60  thumb
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   FLDMMDL_MOVE_GetHideEffect  0x0219BF48  thumb  ov021
 *   FLDEFF_HIDE_RequestEnd  0x021D04A4  thumb  ov021
 *   FLDEFF_HIDE_IsFinished  0x021D04C4  thumb  ov021
 *   FLDMMDL_MOVE_SetHideEffect  0x0219BF3C  thumb  ov021
 *   FLDMMDL_MOVE_SetHideNoEffect  0x0219BF54  thumb  ov021
 *   d_021D4C1C  0x021D4C1C  data   a4
 *   FLDMMDL_SetDirMove  0x0216D600  thumb  ov010
 *   FLDMMDL_OnMoveBitMoveStart  0x0216DA70  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   FLDMMDL_AddGridNowX  0x0216D848  thumb  ov010
 *   FLDMMDL_AddGridNowY  0x0216D860  thumb  ov010
 *   FLDMMDL_AddGridNowZ  0x0216D87C  thumb  ov010
 *   FLDMMDL_MOVE_AddVectorPos  0x02163F8C  thumb  ov010
 *   d_021D4B44  0x021D4B44  data  ov021  a4
 *   d_021D4204  0x021D4204  data  ov021  a4
 *   d_021D4C04  0x021D4C04  data  a4
 *   d_021D41E0  0x021D41E0  data  ov021  a4
 *   d_021D4210  0x021D4210  data  a4
 *   d_021D4C10  0x021D4C10  data  a4
 *   d_021D4648  0x021D4648  data  a4
 *   d_021D4BF8  0x021D4BF8  data  a4
 *   d_021D4BEC  0x021D4BEC  data  a4
 *   d_021D4BE0  0x021D4BE0  data  a4
 *   d_021D4BD4  0x021D4BD4  data  a4
 *   d_021D4BC8  0x021D4BC8  data  a4
 *   d_021D4BBC  0x021D4BBC  data  a4
 *   d_021D4BB0  0x021D4BB0  data  a4
 *   d_021D4BA4  0x021D4BA4  data  a4
 *   d_021D4B98  0x021D4B98  data  a4
 *   d_021D4B8C  0x021D4B8C  data  a4
 *   d_021D4B80  0x021D4B80  data  a4
 *   d_021D4B74  0x021D4B74  data  a4
 *   d_021D4B68  0x021D4B68  data  a4
 *   d_021D4B5C  0x021D4B5C  data  a4
 *   d_021D4B50  0x021D4B50  data  a4
 *   d_021D45E8  0x021D45E8  data  a4
 *   d_021D4B38  0x021D4B38  data  a4
 *   d_021D4B2C  0x021D4B2C  data  a4
 *   d_021D4B20  0x021D4B20  data  a4
 *   d_021D4B14  0x021D4B14  data  a4
 *   d_021D4B08  0x021D4B08  data  a4
 *   d_021D4AFC  0x021D4AFC  data  a4
 *   d_021D4AF0  0x021D4AF0  data  a4
 *   d_021D4AE4  0x021D4AE4  data  a4
 *   d_021D4AD8  0x021D4AD8  data  a4
 *   _s32_div_f  0x0209C0A4  arm
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_DRAW_GetBlactAnimeTypeA  0x0219FC68  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   d_021D4ACC  0x021D4ACC  data  a4
 *   FLDMMDL_DRAW_GetBlactAnimeTypeB  0x0219FCC0  thumb  ov021
 *   FLDMMDL_DRAW_ResetBlactAnime  0x0219FE64  thumb  ov021
 *   FLDMMDL_DRAW_CheckBlactReady  0x0219FE20  thumb  ov021
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   gMmdlRandomWaitFrames  0x021D4FA4  data  a4
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_MOVE_IsNearPlayer  0x02164168  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   gMmdlRotationDirRows  0x021D5074  data  a4
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 *   FLDMMDL_GetGridInitX  0x0216D7E8  thumb  ov010
 *   FLDMMDL_GetGridInitZ  0x0216D7F8  thumb  ov010
 *   FLDMMDL_GetMoveLimitX  0x0216D660  thumb  ov010
 *   FLDMMDL_GetMoveLimitZ  0x0216D66C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   gMmdlSpinSteps  0x021D4DE8  data  a4
 *   gMmdlSpinDirsLeft  0x021D5024  data  a4
 *   gMmdlSpinDirsRight  0x021D5038  data  a4
 *   gMmdlSwingSteps  0x021D4DB8  data  a4
 *   gMmdlSwingDirsLeft  0x021D504C  data  a4
 *   gMmdlSwingDirsRight  0x021D5060  data  a4
 *   FLDMMDL_GetDirHeader  0x0216D5D4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   gMmdlBackForthSteps  0x021D4D60  data  a4
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   gMmdlRoutePatrolSteps  0x021D4D04  data  a4
 *   gMmdlRoutePatrolSwapSteps  0x021D4D78  data  a4
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   EVENT_TRAINER_EYE_GetPlayerDistance  0x021AE198  thumb  ov021
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 *   gMmdlSwapMoveCodePairs  0x021D4F90  data    a2
 *   KEY_GetCont  0x0203630C  arm
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   gMmdlDirSets  0x021D50F8  data  a4
 *   FLDMMDL_MOVE_GetDirFromPoints  0x021642B4  thumb  ov010
 *   gMmdlSightMoveCodes  0x021D4FEC  data  a4
 *   gMmdlMirrorDirCycles  0x021D4FCC  data    a4
 *   gMmdlEventTypeInitProcs  0x021D5278  data   ov021  a4
 *   gMmdlEventTypeCheckProcs  0x021D52CC  data  a4
 *   gMmdlEventTypeUpdateProcs  0x021D5320  data  a4
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   d_021D4A44  0x021D4A44  data  a4
 *   d_021D4A68  0x021D4A68  data  a4
 *   d_021D4A80  0x021D4A80  data  a4
 *   d_021D4A9C  0x021D4A9C  data  a4
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

#include "../ov010/fldmmdl_types.h"

#define NULL ((void *)0)

/* Directions of a field model (Mmdl.dirDisp, Mmdl.dirMove). */
#define MMDL_DIR_UP    0
#define MMDL_DIR_DOWN  1
#define MMDL_DIR_LEFT  2
#define MMDL_DIR_RIGHT 3

/* Mmdl.statusBit bit 0x10: pauses the model's animation. */
#define MMDL_STABIT_PAUSE_ANIME 0x0010

/* MmdlSys.statusBit bit 0x04: the model draw procedures are suspended. */
#define MMDLSYS_STABIT_DRAW_SUSPEND 0x0004

/* Draw status of a model (Mmdl.drawStatus) while an animation command runs. */
#define MMDL_DRAWSTA_STOP     0
#define MMDL_DRAWSTA_WALK_32F 1
#define MMDL_DRAWSTA_WALK_16F 2
#define MMDL_DRAWSTA_WALK_8F  3
#define MMDL_DRAWSTA_WALK_4F  4
#define MMDL_DRAWSTA_WALK_2F  5
#define MMDL_DRAWSTA_WALK_6F  6
#define MMDL_DRAWSTA_WALK_3F  7
#define MMDL_DRAWSTA_WALK_7F  8
#define MMDL_DRAWSTA_WALK_12F 9
#define MMDL_DRAWSTA_DASH_4F  0x0A
#define MMDL_DRAWSTA_DASH_6F  0x0B
#define MMDL_DRAWSTA_DASH_2F  0x0C

/* Animation command code 0xFF: none running. 0xFE ends a command list. */
#define MMDL_ACMD_NONE     0xFF
#define MMDL_ACMD_LIST_END 0xFE

/* One grid is 0x10000 in position units; a walk of N frames moves 1/N grid per frame. */
#define ACMD_GRID_FIXED 0x10000
#define ACMD_GRID_SPEED(frames) (ACMD_GRID_FIXED / (frames))

/* Sound effect numbers played by jump commands. */
#define SE_JUMP 0x55E
#define SE_FALL 0x676
#define SE_LAND 0x67B
#define SE_DASH_START   0x7B7
#define SE_FLY_FLAP_A   0x7E5
#define SE_FLY_FLAP_B   0x7E6
#define SE_FLY_TAKEOFF  0x7E7

/* Object codes of the flying models (draw animation lookups of fldmmdl_draw.c). */
#define MMDL_OBJCODE_FLY_A 0xD3
#define MMDL_OBJCODE_FLY_B 0xDD

/* Axis numbers of a jump or step command: the component of the position vector. */
#define ACMD_AXIS_X 0
#define ACMD_AXIS_Y 1
#define ACMD_AXIS_Z 2

/* Flight: height speed per frame and the frames before the model starts to rise. */
#define ACMD_FLY_SPEED           0x2000
#define ACMD_FLY_TAKEOFF_FRAMES  0x5F

/* One entry of a command list: run the command code, then count more times. */
typedef struct MmdlAcmdListEntry {
    u16 code;
    u16 count;
} MmdlAcmdListEntry;

/* Work of the command list task (0x14 bytes). */
typedef struct MmdlAcmdListWork {
    int state;
    int endFlag;
    int cmdIndex;
    Mmdl *mmdl;
    const MmdlAcmdListEntry *list;
} MmdlAcmdListWork;

/* Per-command work kept in Mmdl.moveCmdWork (0x10 bytes). */
typedef struct AcmdWalkWork {
    u16 drawStatus;
    s16 framesLeft;
    u32 dir;
    u32 speed;
} AcmdWalkWork;

typedef struct AcmdJumpWork {
    int speed;
    int progress;       /* distance moved inside the current grid */
    u16 heightStep;
    u16 height;
    s8 dir;
    s8 framesLeft;
    u8 drawStatus;
    s8 heightTable;
} AcmdJumpWork;

typedef struct AcmdWaitWork {
    u32 framesLeft;
} AcmdWaitWork;

typedef struct AcmdRiseWork {
    int height;
    int step;
} AcmdRiseWork;

typedef struct AcmdMarkWork {
    u32 markType;
    u32 effect;
} AcmdMarkWork;

typedef struct AcmdWalkTableWork {
    u16 dir;
    u16 drawStatus;
    s16 frames;
    s16 frameIndex;
} AcmdWalkTableWork;

/* Work of the anime start commands (4 bytes, never read). */
typedef struct AcmdAnimeWork {
    u32 state;
} AcmdAnimeWork;

/* Work of the commands that count frames. */
typedef struct AcmdCounterWork {
    int count;
} AcmdCounterWork;

/* Work of the hide off hop: index into height table 0. */
typedef struct AcmdHideWork {
    u32 heightIndex;
} AcmdHideWork;

/* Work of the walk in place commands. */
typedef struct AcmdStayWork {
    u16 elapsed;
    u16 frames;
} AcmdStayWork;

/* Work of the step commands (0x10 bytes): frames left and the position step per frame. */
typedef struct AcmdStepWork {
    int framesLeft;
    MmdlVec step;
} AcmdStepWork;

/* Offsets of the bounce, one per frame. */
typedef struct AcmdBounceTable {
    int height[10];
} AcmdBounceTable;

/* Work of the hop commands (0x10 bytes). */
typedef struct AcmdHopWork {
    u8 frames;          /* frames left */
    u8 arcAxis;         /* axis of the rise (height table 1) */
    u8 moveAxis;        /* axis of the move */
    u8 negate;          /* nonzero: the rise goes down */
    int speed;          /* position units per frame along the move axis */
    int progress;       /* distance moved inside the current grid */
    u16 angle;          /* index into the height table, 0x100 per entry */
    u16 angleStep;
} AcmdHopWork;

/* Work of the flight (0x10 bytes). */
typedef struct AcmdFlyWork {
    int height;
    int speed;
    u16 elapsed;
    u8 lastFrame;
    u8 padding[5];
} AcmdFlyWork;

/* Work of the wait before the flight (6 bytes). */
typedef struct AcmdFlyReadyWork {
    u16 elapsed;
    u8 lastFrame;
    u8 padding[3];
} AcmdFlyReadyWork;

extern void FLDMMDL_MOVE_UpdateGridPosDir(Mmdl *mmdl, int dir);
extern void FLDMMDL_MOVE_UpdateOldGridPos(Mmdl *mmdl);
extern void FLDMMDL_MOVE_AddDirVectorPos(Mmdl *mmdl, int dir, int amount);
struct Mmdl;
extern s32 FLDMMDL_MOVE_UpdateHeight(Mmdl *mmdl);
extern int FLDMMDL_CheckPossibleAcmd(Mmdl *mmdl);
extern void FLDMMDL_SetAcmd(Mmdl *mmdl, u16 code);
extern int FLDMMDL_CheckEndAcmd(Mmdl *mmdl);
extern int FLDMMDL_EndAcmd(Mmdl *mmdl);
extern u32 FLDMMDL_SysCheckStatusBit(MmdlSys *sys, u32 bit);
extern u16 FLDMMDL_SysGetTcbPriority(MmdlSys *sys);
extern u32 FLDMMDL_SysGetHeapId(MmdlSys *sys);
extern void *FLDMMDL_SysGetTcbSys(MmdlSys *sys);
extern void *FLDMMDL_SysGetBlActCont(MmdlSys *sys);
extern void *FLDMMDL_SysGetG3dObjCont(MmdlSys *sys);
extern void *FLDMMDL_SysGetFieldMap(MmdlSys *sys);
extern void FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_ClearStatusBit(Mmdl *mmdl, u32 bit);
extern u32 FLDMMDL_CheckStatusBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_ClearMoveBit(Mmdl *mmdl, u32 bit);
extern u32 FLDMMDL_CheckMoveBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
extern void FLDMMDL_SetDirAll(Mmdl *mmdl, u16 dir);
extern void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 drawStatus);
extern MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
extern void *FLDMMDL_InitMoveCmdWork(Mmdl *mmdl, int size);
extern void *FLDMMDL_GetMoveCmdWork(Mmdl *mmdl);
extern void FLDMMDL_CallDrawProc(Mmdl *mmdl);
extern void FLDMMDL_SetAcmdCode(Mmdl *mmdl, u16 code);
extern u16 FLDMMDL_GetAcmdCode(Mmdl *mmdl);
extern void FLDMMDL_SetAcmdSeq(Mmdl *mmdl, u16 seq);
extern int FLDMMDL_IncAcmdSeq(Mmdl *mmdl);
extern u16 FLDMMDL_GetAcmdSeq(Mmdl *mmdl);
extern void FLDMMDL_GetPos(const Mmdl *mmdl, MmdlVec *out);
extern void FLDMMDL_GetDrawOffset(Mmdl *mmdl, MmdlVec *out);
extern void FLDMMDL_SetDrawOffset(Mmdl *mmdl, const MmdlVec *offset);
extern void FLDMMDL_GetDrawOffsetOutside(Mmdl *mmdl, MmdlVec *out);
extern void FLDMMDL_GetAttrOffset(Mmdl *mmdl, MmdlVec *out);
extern void FLDMMDL_GetModelOffset(Mmdl *mmdl, MmdlVec *out);
extern void FLDMMDL_SysSetDrawInit(MmdlSys *sys, int flag);
extern int FLDMMDL_CheckMoveBitDrawInitComp(Mmdl *mmdl);
extern int FLDMMDL_CheckMoveBitMovePause(Mmdl *mmdl);
extern int FLDMMDL_CheckMoveBitAcmd(Mmdl *mmdl);

extern void FLDMMDL_BLACT_Exit(MmdlSys *sys);
struct MmdlSys;
extern void FLDMMDL_G3DOBJ_Delete(struct MmdlSys *mmdlSys);
struct FieldMap;
struct FieldEffectCont;
extern struct FieldEffectCont *FIELDMAP_GetEffect(struct FieldMap *fieldMap);
extern void *FLDEFF_GYOE_SetMMdl(void *fieldEffectSys, Mmdl *mmdl, u32 type, u32 sePlay);
extern int FLDEFF_GYOE_IsFinished(void *task);
struct FieldEffectObj;
extern void FIELD_EFFECT_DeleteObject(struct FieldEffectObj *obj);

extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *mem);
struct TcbSystem;
struct TcbTask;
extern struct TcbTask *TCB_AddTask(struct TcbSystem *sys, void (*func)(void *, MmdlAcmdListWork *), void *work, u32 priority);
extern void TCB_DeleteTask(struct TcbTask *task);
struct TcblSystem;
extern u32 TCBL_IsDeletePending(struct TcblSystem *tcbl);

extern u8 d_021DDBE0;
extern int (*const d_021D4A50[])(MmdlAcmdListWork *);
extern int *d_021D5D6C[];
extern int (**const d_021D624C[])(Mmdl *);
extern int (**const d_021D5F58[])(Mmdl *);
extern int *d_021DDBD4[];
extern void FLDMMDL_MOVE_AddVectorPos(Mmdl *mmdl, const MmdlVec *step);
extern u16 FLDMMDL_GetObjCode(Mmdl *mmdl);
extern void FLDMMDL_SetDirMove(struct Mmdl *mmdl, s32 dir);
extern int FLDMMDL_CallDrawGetProc(Mmdl *mmdl, u32 kind);
extern void FLDMMDL_SetGridOldX(Mmdl *mmdl, int grid);
extern int FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern void FLDMMDL_SetGridOldY(Mmdl *mmdl, int grid);
extern int FLDMMDL_GetGridNowY(Mmdl *mmdl);
extern void FLDMMDL_SetGridOldZ(Mmdl *mmdl, int grid);
extern int FLDMMDL_GetGridNowZ(Mmdl *mmdl);
extern void FLDMMDL_AddGridNowX(Mmdl *mmdl, s16 amount);
extern void FLDMMDL_AddGridNowY(Mmdl *mmdl, s16 amount);
extern void FLDMMDL_AddGridNowZ(Mmdl *mmdl, s16 amount);
extern void FLDMMDL_SetPos(Mmdl *mmdl, const MmdlVec *pos);
extern void FLDMMDL_OnMoveBitMoveStart(Mmdl *mmdl);
struct BlactSys;
struct BbActSys;
extern struct BbActSys *FLDMMDL_BLACT_GetBbActSys(struct BlactSys *cont);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *sys, s32 entryIndex, u16 *lastCommand);
extern s32 FLDMMDL_MOVE_GetHideEffect(Mmdl *mmdl);
extern void FLDMMDL_MOVE_SetHideEffect(Mmdl *mmdl, u32 effect);
extern void FLDMMDL_MOVE_SetHideNoEffect(Mmdl *mmdl);
extern void FLDEFF_HIDE_RequestEnd(struct FieldEffectObj *effect);
extern int FLDEFF_HIDE_IsFinished(struct FieldEffectObj *effect);
extern int FLDMMDL_DRAW_GetBlactAnimeTypeA(Mmdl *mmdl, u16 *animeState, u16 *animeFrame);
extern int FLDMMDL_DRAW_GetBlactAnimeTypeB(Mmdl *mmdl, u16 *animeState, u16 *animeFrame);
extern void FLDMMDL_DRAW_ResetBlactAnime(Mmdl *mmdl);
extern u32 FLDMMDL_DRAW_CheckBlactReady(Mmdl *mmdl);

extern const u32 d_021D4A44[];
extern const u32 d_021D4A68[];
extern const u32 d_021D4A80[];
extern const u32 d_021D4A9C[];
extern const AcmdBounceTable d_021D4C1C;
extern const MmdlVec d_021D41E0;
extern const MmdlVec d_021D4204;
extern const MmdlVec d_021D4210;
extern const MmdlVec d_021D45E8;
extern const MmdlVec d_021D4648;
extern const MmdlVec d_021D4ACC;
extern const MmdlVec d_021D4AD8;
extern const MmdlVec d_021D4AE4;
extern const MmdlVec d_021D4AF0;
extern const MmdlVec d_021D4AFC;
extern const MmdlVec d_021D4B08;
extern const MmdlVec d_021D4B14;
extern const MmdlVec d_021D4B20;
extern const MmdlVec d_021D4B2C;
extern const MmdlVec d_021D4B38;
extern const MmdlVec d_021D4B44;
extern const MmdlVec d_021D4B50;
extern const MmdlVec d_021D4B5C;
extern const MmdlVec d_021D4B68;
extern const MmdlVec d_021D4B74;
extern const MmdlVec d_021D4B80;
extern const MmdlVec d_021D4B8C;
extern const MmdlVec d_021D4B98;
extern const MmdlVec d_021D4BA4;
extern const MmdlVec d_021D4BB0;
extern const MmdlVec d_021D4BBC;
extern const MmdlVec d_021D4BC8;
extern const MmdlVec d_021D4BD4;
extern const MmdlVec d_021D4BE0;
extern const MmdlVec d_021D4BEC;
extern const MmdlVec d_021D4BF8;
extern const MmdlVec d_021D4C04;
extern const MmdlVec d_021D4C10;

int FLDMMDL_ACMD_RunCmdStep(Mmdl *mmdl, u32 code, u32 seq);
void FLDMMDL_ACMD_ListTaskMain(void *tcb, MmdlAcmdListWork *work);

void FLDMMDL_ACMD_DeleteDrawSys(MmdlSys *mmdlSys)
{
    if (FLDMMDL_SysGetBlActCont(mmdlSys) != NULL) {
        FLDMMDL_BLACT_Exit(mmdlSys);
    }
    if (FLDMMDL_SysGetG3dObjCont(mmdlSys) != NULL) {
        FLDMMDL_G3DOBJ_Delete(mmdlSys);
    }
    FLDMMDL_SysSetDrawInit(mmdlSys, 0);
}

void FLDMMDL_ACMD_DrawIfInitialized(Mmdl *mmdl)
{
    if (FLDMMDL_SysCheckStatusBit(FLDMMDL_GetMmdlSys(mmdl), MMDLSYS_STABIT_DRAW_SUSPEND) == 0 && FLDMMDL_CheckMoveBitDrawInitComp(mmdl) != 0) {
        FLDMMDL_CallDrawProc(mmdl);
    }
}

int FLDMMDL_ACMD_CheckAnimePaused(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBitMovePause(mmdl) != 0) {
        if (FLDMMDL_CheckMoveBitAcmd(mmdl) == 0) {
            return 1;
        }
    }
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_PAUSE_ANIME) != 0) {
        return 1;
    }
    return 0;
}

/* Draw position: position plus the draw, outside draw, attribute and model offsets. */
void FLDMMDL_ACMD_GetDrawPos(Mmdl *mmdl, MmdlVec *out)
{
    MmdlVec pos;
    MmdlVec drawOffset;
    MmdlVec drawOffsetOutside;
    MmdlVec attrOffset;
    MmdlVec modelOffset;

    FLDMMDL_GetPos(mmdl, &pos);
    FLDMMDL_GetDrawOffset(mmdl, &drawOffset);
    FLDMMDL_GetDrawOffsetOutside(mmdl, &drawOffsetOutside);
    FLDMMDL_GetAttrOffset(mmdl, &attrOffset);
    FLDMMDL_GetModelOffset(mmdl, &modelOffset);
    out->x = pos.x + drawOffset.x + drawOffsetOutside.x + attrOffset.x + modelOffset.x;
    out->y = pos.y + drawOffset.y + drawOffsetOutside.y + attrOffset.y + modelOffset.y;
    out->z = pos.z + drawOffset.z + drawOffsetOutside.z + attrOffset.z + modelOffset.z;
}

/* Starts a task that runs a command list: entries of (code, count), ended by code 0xFE. */
void FLDMMDL_ACMD_ListCreate(Mmdl *mmdl, const MmdlAcmdListEntry *list)
{
    MmdlSys *mmdlSys;
    MmdlAcmdListWork *work;
    u32 priority;

    mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    work = GFL_HEAP_Alloc((u16)(0x8000 | (FLDMMDL_SysGetHeapId(mmdlSys) & 0x7fff)), sizeof(MmdlAcmdListWork), 1, (const char *)&d_021DDBE0, 0x115);
    priority = FLDMMDL_SysGetTcbPriority(FLDMMDL_GetMmdlSys(mmdl)) - 2;
    TCB_AddTask(FLDMMDL_SysGetTcbSys(mmdlSys), FLDMMDL_ACMD_ListTaskMain, work, priority);
    work->mmdl = mmdl;
    work->list = list;
}

int FLDMMDL_ACMD_ListCheckEnd(void *tcb)
{
    return ((MmdlAcmdListWork *)TCBL_IsDeletePending(tcb))->endFlag;
}

void FLDMMDL_ACMD_ListDelete(void *tcb)
{
    MmdlAcmdListWork *work;

    work = (struct MmdlAcmdListWork *)TCBL_IsDeletePending(tcb);
    FLDMMDL_EndAcmd(work->mmdl);
    GFL_HEAP_Free(work);
    TCB_DeleteTask(tcb);
}

void FLDMMDL_ACMD_ListTaskMain(void *tcb, MmdlAcmdListWork *work)
{
    while (d_021D4A50[work->state](work) == 1) {
    }
}

int FLDMMDL_ACMD_ListStateStart(MmdlAcmdListWork *work)
{
    work->cmdIndex = 0;
    work->state = 1;
    return 1;
}

int FLDMMDL_ACMD_ListStateWaitPossible(MmdlAcmdListWork *work)
{
    if (FLDMMDL_CheckPossibleAcmd(work->mmdl) == 0) {
        return 0;
    }
    work->state = 2;
    return 1;
}

int FLDMMDL_ACMD_ListStateSetCmd(MmdlAcmdListWork *work)
{
    FLDMMDL_SetAcmd(work->mmdl, work->list->code);
    work->state = 3;
    return 0;
}

int FLDMMDL_ACMD_ListStateWaitEnd(MmdlAcmdListWork *work)
{
    if (FLDMMDL_CheckEndAcmd(work->mmdl) == 0) {
        return 0;
    }
    work->state = 4;
    return 1;
}

int FLDMMDL_ACMD_ListStateNext(MmdlAcmdListWork *work)
{
    const MmdlAcmdListEntry *entry = work->list;
    int index = ++work->cmdIndex;
    if (index < entry->count) {
        work->state = 1;
        return 1;
    }
    work->list = entry + 1;
    if (entry[1].code != MMDL_ACMD_LIST_END) {
        work->state = 0;
        return 1;
    }
    work->endFlag = 1;
    work->state = 5;
    return 0;
}

int FLDMMDL_ACMD_ListStateFinished(void)
{
    return 0;
}

/* Finds the code in one of the code groups and returns the group member at the index. */
int FLDMMDL_ACMD_ConvertCodeByDir(int index, int code)
{
    int i;
    int **group;
    int *members;
    group = d_021D5D6C;
    do {
        members = *group;
        for (i = 0; i < 4; i++) {
            if (code == members[i]) {
                return (u16)members[index];
            }
        }
        group++;
    } while (*group != 0);
    return code;
}

void FLDMMDL_ACMD_RunCmds(Mmdl *mmdl)
{
    u32 code;
    do {
        code = FLDMMDL_GetAcmdCode(mmdl);
        if (code == MMDL_ACMD_NONE) {
            return;
        }
    } while (FLDMMDL_ACMD_RunCmdStep(mmdl, code, FLDMMDL_GetAcmdSeq(mmdl)) != 0);
}

u32 FLDMMDL_ACMD_Update(Mmdl *mmdl)
{
    if (FLDMMDL_GetAcmdCode(mmdl) != MMDL_ACMD_NONE) {
        FLDMMDL_ACMD_RunCmds(mmdl);
        if (FLDMMDL_CheckMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END) == 0) {
            return 0;
        }
    }
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_SetAcmdCode(mmdl, MMDL_ACMD_NONE);
    FLDMMDL_SetAcmdSeq(mmdl, 0);
    return 1;
}

int FLDMMDL_ACMD_RunCmdStep(Mmdl *mmdl, u32 code, u32 seq)
{
    if (FLDMMDL_CheckStatusBit(mmdl, MMDL_STABIT_RAIL_MOVE) != 0) {
        return d_021D624C[code][seq](mmdl);
    }
    return d_021D5F58[code][seq](mmdl);
}

int FLDMMDL_ACMD_EndCmd(Mmdl *mmdl)
{
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END);
    return 0;
}

int FLDMMDL_ACMD_TurnInit(Mmdl *mmdl, u32 dir)
{
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    return FLDMMDL_IncAcmdSeq(mmdl);
}

u32 FLDMMDL_ACMD_DirUp(Mmdl *mmdl)
{
    FLDMMDL_ACMD_TurnInit(mmdl, MMDL_DIR_UP);
    return 1;
}

u32 FLDMMDL_ACMD_DirDown(Mmdl *mmdl)
{
    FLDMMDL_ACMD_TurnInit(mmdl, MMDL_DIR_DOWN);
    return 1;
}

u32 FLDMMDL_ACMD_DirLeft(Mmdl *mmdl)
{
    FLDMMDL_ACMD_TurnInit(mmdl, MMDL_DIR_LEFT);
    return 1;
}

u32 FLDMMDL_ACMD_DirRight(Mmdl *mmdl)
{
    FLDMMDL_ACMD_TurnInit(mmdl, MMDL_DIR_RIGHT);
    return 1;
}

void FLDMMDL_ACMD_WalkInit(Mmdl *mmdl, u32 dir, u32 speed, u16 frames, u16 drawStatus)
{
    AcmdWalkWork *work;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdWalkWork));
    work->drawStatus = drawStatus;
    work->framesLeft = frames;
    work->dir = dir;
    work->speed = speed;
    FLDMMDL_MOVE_UpdateGridPosDir(mmdl, (u16)dir);
    FLDMMDL_SetDirAll(mmdl, dir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_START);
    FLDMMDL_IncAcmdSeq(mmdl);
}

u32 FLDMMDL_ACMD_WalkMove(Mmdl *mmdl)
{
    AcmdWalkWork *work;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    FLDMMDL_MOVE_AddDirVectorPos(mmdl, (u16)work->dir, work->speed);
    FLDMMDL_MOVE_UpdateHeight(mmdl);
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_WalkUp32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int FLDMMDL_ACMD_WalkDown32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int FLDMMDL_ACMD_WalkLeft32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int FLDMMDL_ACMD_WalkRight32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(32), 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

int FLDMMDL_ACMD_WalkUp16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int FLDMMDL_ACMD_WalkDown16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int FLDMMDL_ACMD_WalkLeft16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int FLDMMDL_ACMD_WalkRight16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

int FLDMMDL_ACMD_WalkUp8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_WalkDown8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_WalkLeft8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_WalkRight8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_WalkUp4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_WalkDown4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_WalkLeft4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_WalkRight4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_WalkUp2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_WalkDown2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_WalkLeft2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_WalkRight2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(2), 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_WalkUp1F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int FLDMMDL_ACMD_WalkDown1F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int FLDMMDL_ACMD_WalkLeft1F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int FLDMMDL_ACMD_WalkRight1F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(1), 1, MMDL_DRAWSTA_STOP);
    return 1;
}

int FLDMMDL_ACMD_DashUp4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashDown4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashLeft4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashRight4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(4), 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_WalkUp16FFastAnime(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_WalkDown16FFastAnime(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_WalkLeft16FFastAnime(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_WalkRight16FFastAnime(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkInit(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

void FLDMMDL_ACMD_StayWalkInit(Mmdl *mmdl, u32 dir, u16 frames, u16 drawStatus)
{
    AcmdWalkWork *work;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdWalkWork));
    work->drawStatus = drawStatus;
    work->framesLeft = frames;
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_ACMD_StayWalkMove(Mmdl *mmdl)
{
    AcmdWalkWork *work;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    work->framesLeft--;
    if (work->framesLeft > 0) {
        return 0;
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

u32 FLDMMDL_ACMD_StayWalkUp32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_UP, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkDown32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_DOWN, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkLeft32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_LEFT, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkRight32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_RIGHT, 32, MMDL_DRAWSTA_WALK_32F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkUp16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_UP, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkDown16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_DOWN, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkLeft16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_LEFT, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkRight16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_RIGHT, 16, MMDL_DRAWSTA_WALK_16F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkUp8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkDown8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkLeft8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkRight8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkUp4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_UP, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkDown4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkLeft4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkRight4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkUp2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_UP, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkDown2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_DOWN, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkLeft2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_LEFT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

u32 FLDMMDL_ACMD_StayWalkRight2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayWalkInit(mmdl, MMDL_DIR_RIGHT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

void FLDMMDL_ACMD_JumpInit(Mmdl *mmdl, u32 dir, u32 speed, u32 frames, u16 drawStatus, s16 heightTable, u16 heightStep, u32 se)
{
    AcmdJumpWork *work;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdJumpWork));
    work->dir = dir;
    work->speed = speed;
    work->framesLeft = frames;
    work->drawStatus = drawStatus;
    work->heightTable = heightTable;
    work->heightStep = heightStep;
    if (speed == 0) {
        FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    } else {
        FLDMMDL_MOVE_UpdateGridPosDir(mmdl, (u16)dir);
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_JUMP_START | MMDL_MOVEBIT_MOVE_START);
    FLDMMDL_SetDirAll(mmdl, dir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_IncAcmdSeq(mmdl);
    if (se != 0) {
        GFL_USE_PlaySeDefaultVolume(se);
    }
}

void FLDMMDL_ACMD_JumpInitWithSe(Mmdl *mmdl, u32 dir, u32 speed, u32 frames, u16 drawStatus, s16 heightTable, u16 heightStep)
{
    FLDMMDL_ACMD_JumpInit(mmdl, dir, speed, frames, drawStatus, heightTable, heightStep, SE_JUMP);
}

int FLDMMDL_ACMD_JumpMove(Mmdl *mmdl)
{
    AcmdJumpWork *work;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    if (work->speed != 0) {
        FLDMMDL_MOVE_AddDirVectorPos(mmdl, work->dir, work->speed);
        FLDMMDL_MOVE_UpdateHeight(mmdl);
        if (work->progress >= ACMD_GRID_FIXED) {
            work->progress = 0;
            FLDMMDL_MOVE_UpdateGridPosDir(mmdl, work->dir);
            FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_START);
        }
        work->progress += (work->speed < 0) ? -work->speed : work->speed;
    }
    work->height += work->heightStep;
    if (work->height > 0xF00) {
        work->height = 0xF00;
    }
    {
        MmdlVec offset;
        u16 index;
        int table;

        index = work->height / 256;
        table = work->heightTable;
        offset.x = 0;
        offset.y = d_021DDBD4[table][index];
        offset.z = 0;
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    {
        MmdlVec offset = { 0, 0, 0 };
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_JUMP_END | MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_IncAcmdSeq(mmdl);
    GFL_USE_PlaySeDefaultVolume(SE_LAND);
    return 1;
}

int FLDMMDL_ACMD_StayJumpUp16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_UP, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int FLDMMDL_ACMD_StayJumpDown16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_DOWN, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int FLDMMDL_ACMD_StayJumpLeft16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_LEFT, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int FLDMMDL_ACMD_StayJumpRight16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_RIGHT, 0, 16, MMDL_DRAWSTA_WALK_16F, 1, 0x100);
    return 1;
}

int FLDMMDL_ACMD_StayJumpUp8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_UP, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int FLDMMDL_ACMD_StayJumpDown8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_DOWN, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int FLDMMDL_ACMD_StayJumpLeft8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_LEFT, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int FLDMMDL_ACMD_StayJumpRight8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_RIGHT, 0, 8, MMDL_DRAWSTA_WALK_8F, 1, 0x200);
    return 1;
}

int FLDMMDL_ACMD_JumpUp1G8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_UP, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int FLDMMDL_ACMD_JumpDown1G8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_DOWN, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int FLDMMDL_ACMD_JumpLeft1G8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int FLDMMDL_ACMD_JumpRight1G8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(8), 8, MMDL_DRAWSTA_WALK_8F, 0, 0x200);
    return 1;
}

int FLDMMDL_ACMD_JumpUp2G16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_UP, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int FLDMMDL_ACMD_JumpDown2G16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_DOWN, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int FLDMMDL_ACMD_JumpLeft2G16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_LEFT, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int FLDMMDL_ACMD_JumpRight2G16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_RIGHT, 2 * ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_8F, 0, 0x100);
    return 1;
}

int FLDMMDL_ACMD_JumpLeft1G16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_LEFT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F, 0, 0xF0);
    return 1;
}

int FLDMMDL_ACMD_JumpRight1G16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_RIGHT, ACMD_GRID_SPEED(16), 16, MMDL_DRAWSTA_WALK_16F, 0, 0xF0);
    return 1;
}

int FLDMMDL_ACMD_JumpLeft3G12F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_LEFT, 0x4000, 12, MMDL_DRAWSTA_WALK_8F, 0, 0x140);
    return 1;
}

int FLDMMDL_ACMD_JumpRight3G12F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInitWithSe(mmdl, MMDL_DIR_RIGHT, 0x4000, 12, MMDL_DRAWSTA_WALK_8F, 0, 0x140);
    return 1;
}

int FLDMMDL_ACMD_JumpUp3G24FNoSe(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInit(mmdl, MMDL_DIR_UP, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int FLDMMDL_ACMD_JumpDown3G24FNoSe(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInit(mmdl, MMDL_DIR_DOWN, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int FLDMMDL_ACMD_JumpLeft3G24FNoSe(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInit(mmdl, MMDL_DIR_LEFT, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int FLDMMDL_ACMD_JumpRight3G24FNoSe(Mmdl *mmdl)
{
    FLDMMDL_ACMD_JumpInit(mmdl, MMDL_DIR_RIGHT, 0x2000, 24, MMDL_DRAWSTA_WALK_8F, 0, 0xA0, 0);
    return 1;
}

int FLDMMDL_ACMD_WaitInit(Mmdl *mmdl, u32 frames)
{
    ((AcmdWaitWork *)FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdWaitWork)))->framesLeft = frames;
    return FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_ACMD_WaitMove(Mmdl *mmdl)
{
    AcmdWaitWork *work;
    work = (AcmdWaitWork *)FLDMMDL_GetMoveCmdWork(mmdl);
    if (work->framesLeft != 0) {
        work->framesLeft -= 1;
        return 0;
    }
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

u32 FLDMMDL_ACMD_Wait1F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WaitInit(mmdl, 1);
    return 1;
}

u32 FLDMMDL_ACMD_Wait2F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WaitInit(mmdl, 2);
    return 1;
}

u32 FLDMMDL_ACMD_Wait4F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WaitInit(mmdl, 4);
    return 1;
}

u32 FLDMMDL_ACMD_Wait8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WaitInit(mmdl, 8);
    return 1;
}

u32 FLDMMDL_ACMD_Wait15F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WaitInit(mmdl, 15);
    return 1;
}

u32 FLDMMDL_ACMD_Wait16F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WaitInit(mmdl, 16);
    return 1;
}

u32 FLDMMDL_ACMD_Wait32F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WaitInit(mmdl, 32);
    return 1;
}

int FLDMMDL_ACMD_RiseInit(Mmdl *mmdl)
{
    ((AcmdRiseWork *)FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdRiseWork)))->step = ACMD_GRID_FIXED;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_RiseMove(Mmdl *mmdl)
{
    AcmdRiseWork *work;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    work->height = work->height + work->step;
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = work->height;
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    if (work->height / 0x8000 < 0x28) {
        return 0;
    }
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_FallInit(Mmdl *mmdl)
{
    AcmdRiseWork *work;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdRiseWork));
    work->height = 0x140000;
    work->step = -ACMD_GRID_FIXED;
    GFL_USE_PlaySeDefaultVolume(SE_FALL);
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_FallMove(Mmdl *mmdl)
{
    AcmdRiseWork *work;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    work->height = work->height + work->step;
    if (work->height < 0) {
        work->height = 0;
    }
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = work->height;
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    if (work->height > 0) {
        return 0;
    }
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_VanishOn(Mmdl *mmdl)
{
    FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_VANISH);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_VanishOff(Mmdl *mmdl)
{
    FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_VANISH);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_DirPauseOn(Mmdl *mmdl)
{
    FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_PAUSE_DIR);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_DirPauseOff(Mmdl *mmdl)
{
    FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_PAUSE_DIR);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_AnimePauseOn(Mmdl *mmdl)
{
    FLDMMDL_SetStatusBit(mmdl, MMDL_STABIT_PAUSE_ANIME);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_AnimePauseOff(Mmdl *mmdl)
{
    FLDMMDL_ClearStatusBit(mmdl, MMDL_STABIT_PAUSE_ANIME);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

void FLDMMDL_ACMD_MarkInit(Mmdl *mmdl, u32 markType, u32 reserved)
{
    AcmdMarkWork *work;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdMarkWork));
    work->markType = markType;
    work->effect = (u32)FLDEFF_GYOE_SetMMdl(FIELDMAP_GetEffect(FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys(mmdl))), mmdl, markType, 1);
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_ACMD_MarkWait(Mmdl *mmdl)
{
    AcmdMarkWork *work;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    if (FLDEFF_GYOE_IsFinished((void *)work->effect) == 1) {
        FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)work->effect);
        FLDMMDL_IncAcmdSeq(mmdl);
        return 1;
    }
    return 0;
}

u32 FLDMMDL_ACMD_MarkGyoe(Mmdl *mmdl)
{
    FLDMMDL_ACMD_MarkInit(mmdl, 0, 0);
    return 0;
}

u32 FLDMMDL_ACMD_MarkGyoeSlot1(Mmdl *mmdl)
{
    FLDMMDL_ACMD_MarkInit(mmdl, 0, 0);
    return 0;
}

u32 FLDMMDL_ACMD_MarkGyoeSlot2(Mmdl *mmdl)
{
    FLDMMDL_ACMD_MarkInit(mmdl, 0, 0);
    return 0;
}

u32 FLDMMDL_ACMD_MarkType1(Mmdl *mmdl)
{
    FLDMMDL_ACMD_MarkInit(mmdl, 1, 0);
    return 0;
}

u32 FLDMMDL_ACMD_MarkType2(Mmdl *mmdl)
{
    FLDMMDL_ACMD_MarkInit(mmdl, 2, 0);
    return 0;
}

u32 FLDMMDL_ACMD_MarkType3(Mmdl *mmdl)
{
    FLDMMDL_ACMD_MarkInit(mmdl, 3, 0);
    return 0;
}

void FLDMMDL_ACMD_WalkTableInit(Mmdl *mmdl, u32 dir, u32 frames, u16 drawStatus)
{
    AcmdWalkTableWork *work;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdWalkTableWork));
    work->dir = dir;
    work->drawStatus = drawStatus;
    work->frames = frames;
    FLDMMDL_MOVE_UpdateGridPosDir(mmdl, (dir << 16) >> 16);
    FLDMMDL_SetDirAll(mmdl, dir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_START);
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_ACMD_WalkTableMove(Mmdl *mmdl, const u32 *stepTable)
{
    AcmdWalkTableWork *work;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    FLDMMDL_MOVE_AddDirVectorPos(mmdl, work->dir, stepTable[work->frameIndex]);
    FLDMMDL_MOVE_UpdateHeight(mmdl);
    work->frameIndex = work->frameIndex + 1;
    if (work->frameIndex < work->frames) {
        return 0;
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

u32 FLDMMDL_ACMD_WalkUp6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_UP, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkDown6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_DOWN, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkLeft6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_LEFT, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkRight6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_RIGHT, 6, MMDL_DRAWSTA_WALK_6F);
    return 1;
}

u32 FLDMMDL_ACMD_DashUp6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_UP, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

u32 FLDMMDL_ACMD_DashDown6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_DOWN, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

u32 FLDMMDL_ACMD_DashLeft6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_LEFT, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

u32 FLDMMDL_ACMD_DashRight6F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_RIGHT, 6, MMDL_DRAWSTA_DASH_6F);
    return 1;
}

/* Step of the 6 frame walks: the speed of each frame comes from d_021D4A68. */
int FLDMMDL_ACMD_Walk6FMove(Mmdl *mmdl)
{
    if (FLDMMDL_ACMD_WalkTableMove(mmdl, d_021D4A68) == 1) {
        return 1;
    }
    return 0;
}

/* Walks of 3 frames (step table d_021D4A44), 7 frames (d_021D4A80) and 12 frames (d_021D4A9C). */
u32 FLDMMDL_ACMD_WalkUp3F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_UP, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkDown3F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_DOWN, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkLeft3F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_LEFT, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkRight3F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_RIGHT, 3, MMDL_DRAWSTA_WALK_3F);
    return 1;
}

int FLDMMDL_ACMD_Walk3FMove(Mmdl *mmdl)
{
    if (FLDMMDL_ACMD_WalkTableMove(mmdl, d_021D4A44) == 1) {
        return 1;
    }
    return 0;
}

u32 FLDMMDL_ACMD_WalkUp7F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_UP, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkDown7F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_DOWN, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkLeft7F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_LEFT, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkRight7F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_RIGHT, 7, MMDL_DRAWSTA_WALK_7F);
    return 1;
}

int FLDMMDL_ACMD_Walk7FMove(Mmdl *mmdl)
{
    if (FLDMMDL_ACMD_WalkTableMove(mmdl, d_021D4A80) == 1) {
        return 1;
    }
    return 0;
}

u32 FLDMMDL_ACMD_WalkUp12F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_UP, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkDown12F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_DOWN, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkLeft12F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_LEFT, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

u32 FLDMMDL_ACMD_WalkRight12F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_WalkTableInit(mmdl, MMDL_DIR_RIGHT, 12, MMDL_DRAWSTA_WALK_12F);
    return 1;
}

int FLDMMDL_ACMD_Walk12FMove(Mmdl *mmdl)
{
    if (FLDMMDL_ACMD_WalkTableMove(mmdl, d_021D4A9C) == 1) {
        return 1;
    }
    return 0;
}

/* Starts a draw status (dash animation) and goes on at the next frame. */
int FLDMMDL_ACMD_AnimeDash4FStart(Mmdl *mmdl)
{
    FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdAnimeWork));
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_4F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_AnimeDash6FStart(Mmdl *mmdl)
{
    FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdAnimeWork));
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_6F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_AnimeDash2FStart(Mmdl *mmdl)
{
    FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdAnimeWork));
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_2F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_AnimeDash4FStartSe(Mmdl *mmdl)
{
    GFL_USE_PlaySeDefaultVolume(SE_DASH_START);
    return FLDMMDL_ACMD_AnimeDash4FStart(mmdl);
}

int FLDMMDL_ACMD_AnimeDash6FStartSe(Mmdl *mmdl)
{
    GFL_USE_PlaySeDefaultVolume(SE_DASH_START);
    return FLDMMDL_ACMD_AnimeDash6FStart(mmdl);
}

/* Waits for the end of the draw animation, then stops the draw status. */
int FLDMMDL_ACMD_AnimeWaitEndStop(Mmdl *mmdl)
{
    u32 animeId;
    u16 animeFlag;

    FLDMMDL_GetMoveCmdWork(mmdl);
    animeId = FLDMMDL_CallDrawGetProc(mmdl, 0);
    if (animeId != 0xFFFF) {
        if (BILLBOARD_ACT_GetEntryLastCommand(FLDMMDL_BLACT_GetBbActSys(FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl))), (u16)animeId, &animeFlag) == 1) {
            FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_STOP);
            FLDMMDL_IncAcmdSeq(mmdl);
            return 1;
        }
    }
    return 0;
}

/* Waits for the end of the draw animation. */
int FLDMMDL_ACMD_AnimeWaitEnd(Mmdl *mmdl)
{
    u32 animeId;
    u16 animeFlag;

    FLDMMDL_GetMoveCmdWork(mmdl);
    animeId = FLDMMDL_CallDrawGetProc(mmdl, 0);
    if (animeId != 0xFFFF) {
        if (BILLBOARD_ACT_GetEntryLastCommand(FLDMMDL_BLACT_GetBbActSys(FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl))), (u16)animeId, &animeFlag) == 1) {
            FLDMMDL_IncAcmdSeq(mmdl);
            return 1;
        }
    }
    return 0;
}

/* Leaves the hide effect: a hop along height table 0. */
int FLDMMDL_ACMD_HideOffInit(Mmdl *mmdl)
{
    u32 effect;

    FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdHideWork));
    effect = FLDMMDL_MOVE_GetHideEffect(mmdl);
    if (effect != 0) {
        FLDEFF_HIDE_RequestEnd((struct FieldEffectObj *)effect);
    }
    {
        MmdlVec offset = { 0, 0, 0 };
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_JUMP_START | MMDL_MOVEBIT_MOVE_START);
    FLDMMDL_ClearMoveBit(mmdl, MMDL_MOVEBIT_SHOAL_SET);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_HideOffMove(Mmdl *mmdl)
{
    AcmdHideWork *work;
    u32 effect;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = d_021DDBD4[0][work->heightIndex];
        FLDMMDL_SetDrawOffset(mmdl, &offset);
        effect = FLDMMDL_MOVE_GetHideEffect(mmdl);
        if (effect != 0) {
            if (FLDEFF_HIDE_IsFinished((struct FieldEffectObj *)effect) == 1) {
                FIELD_EFFECT_DeleteObject((struct FieldEffectObj *)effect);
                FLDMMDL_MOVE_SetHideEffect(mmdl, 0);
            }
        }
        work->heightIndex = work->heightIndex + 2;
        if (work->heightIndex < 16) {
            return 0;
        }
        offset.y = 0;
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_JUMP_END | MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_MOVE_SetHideNoEffect(mmdl);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

/* Walks in place with a draw status for the given number of frames. */
void FLDMMDL_ACMD_StayInit(Mmdl *mmdl, u16 drawStatus, u32 frames)
{
    ((AcmdStayWork *)FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdStayWork)))->frames = frames;
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
}

int FLDMMDL_ACMD_StayMove(Mmdl *mmdl)
{
    AcmdStayWork *work;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    work->elapsed++;
    if (work->elapsed >= work->frames) {
        FLDMMDL_IncAcmdSeq(mmdl);
    }
    return 0;
}

int FLDMMDL_ACMD_StayWalk32F40F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayInit(mmdl, MMDL_DRAWSTA_WALK_32F, 40);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_StayWalk16F40F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayInit(mmdl, MMDL_DRAWSTA_WALK_16F, 40);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_StayStop12F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_StayInit(mmdl, MMDL_DRAWSTA_STOP, 12);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

/* Starts a bounce in place: the height of each frame comes from d_021D4C1C. */
int FLDMMDL_ACMD_BounceInit(Mmdl *mmdl)
{
    FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdCounterWork));
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_WALK_32F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_BounceMove(Mmdl *mmdl)
{
    MmdlVec offset = { 0, 0, 0 };
    AcmdBounceTable heights;
    AcmdCounterWork *work;
    int index;

    heights = d_021D4C1C;
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    index = work->count;
    if (index >= 10) {
        index = 9;
    }
    offset.y = heights.height[index];
    FLDMMDL_SetDrawOffset(mmdl, &offset);
    work->count = work->count + 1;
    if (work->count >= 20) {
        FLDMMDL_IncAcmdSeq(mmdl);
    }
    return 0;
}

/* Starts a step of the given frames along the vector, facing dispDir while moving to moveDir. */
void FLDMMDL_ACMD_StepInit(Mmdl *mmdl, const MmdlVec *step, u32 dispDir, u32 moveDir, u32 frames, u8 drawStatus)
{
    AcmdStepWork *work;

    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdStepWork));
    work->framesLeft = frames;
    work->step = *step;
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dispDir);
    FLDMMDL_SetDirMove(mmdl, (u16)moveDir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_OnMoveBitMoveStart(mmdl);
    FLDMMDL_SetGridOldX(mmdl, FLDMMDL_GetGridNowX(mmdl));
    FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
    FLDMMDL_SetGridOldZ(mmdl, FLDMMDL_GetGridNowZ(mmdl));
    if (step->x < 0) {
        FLDMMDL_AddGridNowX(mmdl, -1);
    } else if (step->x > 0) {
        FLDMMDL_AddGridNowX(mmdl, 1);
    }
    if (step->y < 0) {
        FLDMMDL_AddGridNowY(mmdl, -1);
    } else if (step->y > 0) {
        FLDMMDL_AddGridNowY(mmdl, 1);
    }
    if (step->z < 0) {
        FLDMMDL_AddGridNowZ(mmdl, -1);
    } else if (step->z > 0) {
        FLDMMDL_AddGridNowZ(mmdl, 1);
    }
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_ACMD_StepMove(Mmdl *mmdl)
{
    AcmdStepWork *work;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    FLDMMDL_MOVE_AddVectorPos(mmdl, &work->step);
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_STOP);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

/* Steps of 8, 4 and 2 frames, then 4 frame dash steps, along one vector: the model faces dispDir while it moves to moveDir. */
int FLDMMDL_ACMD_StepUpFaceLeft8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B44;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepDownFaceRight8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4204;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepLeftFaceDown8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4C04;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepRightFaceUp8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D41E0;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepUpFaceRight8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4210;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepDownFaceLeft8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4C10;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepLeftFaceUp8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4648;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepLeftFaceDown8FAlt(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BF8;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepUpFaceDown8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BEC;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepDownFaceUp8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BE0;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepLeftFaceRight8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BD4;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepRightFaceLeft8F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BC8;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F);
    return 1;
}

int FLDMMDL_ACMD_StepUpFaceDown4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BBC;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_StepDownFaceUp4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BB0;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_StepLeftFaceRight4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4BA4;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_StepRightFaceLeft4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B98;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_WALK_4F);
    return 1;
}

int FLDMMDL_ACMD_StepUpFaceDown2F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B8C;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_StepDownFaceUp2F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B80;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_StepLeftFaceRight2F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B74;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_StepRightFaceLeft2F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B68;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 2, MMDL_DRAWSTA_WALK_2F);
    return 1;
}

int FLDMMDL_ACMD_DashStepUpFaceLeft4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B5C;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_UP, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepDownFaceRight4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B50;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepLeftFaceDown4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D45E8;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepRightFaceUp4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B38;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepUpFaceRight4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B2C;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_UP, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepDownFaceLeft4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B20;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepLeftFaceUp4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B14;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepLeftFaceDown4FAlt(Mmdl *mmdl)
{
    MmdlVec step = d_021D4B08;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepUpFaceDown4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AFC;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_DOWN, MMDL_DIR_UP, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepDownFaceUp4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AF0;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_UP, MMDL_DIR_DOWN, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepLeftFaceRight4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AE4;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

int FLDMMDL_ACMD_DashStepRightFaceLeft4F(Mmdl *mmdl)
{
    MmdlVec step = d_021D4AD8;
    FLDMMDL_ACMD_StepInit(mmdl, &step, MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 4, MMDL_DRAWSTA_DASH_4F);
    return 1;
}

/* Starts a jump of the given frames that moves along moveAxis and rises along arcAxis (height table 1). */
void FLDMMDL_ACMD_HopInit(Mmdl *mmdl, int speed, u32 dispDir, u32 moveDir, u8 frames, u8 drawStatus, u8 moveAxis, u8 arcAxis, u8 negate)
{
    AcmdHopWork *work;
    int sign;

    sign = 1;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdHopWork));
    work->frames = frames;
    work->speed = speed;
    work->moveAxis = moveAxis;
    work->arcAxis = arcAxis;
    work->negate = negate;
    work->angleStep = 0x1000 / work->frames;
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dispDir);
    FLDMMDL_SetDirMove(mmdl, (u16)moveDir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_OnMoveBitMoveStart(mmdl);
    FLDMMDL_SetGridOldX(mmdl, FLDMMDL_GetGridNowX(mmdl));
    FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
    FLDMMDL_SetGridOldZ(mmdl, FLDMMDL_GetGridNowZ(mmdl));
    if (speed != 0) {
        switch (moveAxis) {
        case ACMD_AXIS_X:
            if (speed < 0)
                sign = -1;
            FLDMMDL_AddGridNowX(mmdl, sign);
            break;
        case ACMD_AXIS_Y:
            if (speed < 0)
                sign = -1;
            FLDMMDL_AddGridNowY(mmdl, sign * 2);
            break;
        case ACMD_AXIS_Z:
            if (speed < 0)
                sign = -1;
            FLDMMDL_AddGridNowZ(mmdl, sign);
            break;
        }
    }
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_ACMD_HopMove(Mmdl *mmdl)
{
    AcmdHopWork *work;
    MmdlVec pos;
    int speedAbs;
    int height;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    FLDMMDL_GetPos(mmdl, &pos);
    switch (work->moveAxis) {
    case ACMD_AXIS_X:
        pos.x += work->speed;
        break;
    case ACMD_AXIS_Y:
        pos.y += work->speed;
        break;
    case ACMD_AXIS_Z:
        pos.z += work->speed;
        break;
    }
    FLDMMDL_SetPos(mmdl, &pos);
    speedAbs = work->speed;
    if (speedAbs < 0)
        speedAbs = -speedAbs;
    work->progress += speedAbs;
    work->angle += work->angleStep;
    if (work->angle > 0xF00)
        work->angle = 0xF00;
    {
        MmdlVec offset = { 0, 0, 0 };
        height = d_021DDBD4[1][(u16)(work->angle / 256)];
        if (work->negate == 1)
            height = -height;
        switch (work->arcAxis) {
        case ACMD_AXIS_X:
            offset.x = height;
            break;
        case ACMD_AXIS_Y:
            offset.y = height;
            break;
        case ACMD_AXIS_Z:
            offset.z = height;
            break;
        }
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    work->frames--;
    if (work->progress >= ACMD_GRID_FIXED && work->frames != 0) {
        int speed;
        int sign;

        work->progress -= ACMD_GRID_FIXED;
        sign = 1;
        speed = work->speed;
        FLDMMDL_SetGridOldX(mmdl, FLDMMDL_GetGridNowX(mmdl));
        FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
        FLDMMDL_SetGridOldZ(mmdl, FLDMMDL_GetGridNowZ(mmdl));
        switch (work->moveAxis) {
        case ACMD_AXIS_X:
            if (speed < 0)
                sign = -1;
            FLDMMDL_AddGridNowX(mmdl, sign);
            break;
        case ACMD_AXIS_Y:
            if (speed < 0)
                sign = -1;
            FLDMMDL_AddGridNowY(mmdl, sign * 2);
            break;
        case ACMD_AXIS_Z:
            if (speed < 0)
                sign = -1;
            FLDMMDL_AddGridNowZ(mmdl, sign);
            break;
        }
    }
    if (work->frames != 0)
        return 0;
    {
        MmdlVec offset = { 0, 0, 0 };
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_JUMP_END | MMDL_MOVEBIT_ACMD_END);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_STOP);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

/* Jumps of 8 frames that move one grid and rise along height table 1, with the directions of the steps above. */
int FLDMMDL_ACMD_HopUpFaceLeft8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_LEFT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopDownFaceRight8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_RIGHT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopLeftFaceDown8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopRightFaceUp8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_UP, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopUpFaceRight8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_RIGHT, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopDownFaceLeft8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_LEFT, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Y, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopLeftFaceUp8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_UP, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopLeftFaceDown8FAlt(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_DOWN, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopUpFaceDown8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_DOWN, MMDL_DIR_UP, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopDownFaceUp8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_UP, MMDL_DIR_DOWN, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_Z, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopLeftFaceRight8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, -ACMD_GRID_SPEED(8), MMDL_DIR_RIGHT, MMDL_DIR_LEFT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_X, ACMD_AXIS_Y, 0);
    return 1;
}

int FLDMMDL_ACMD_HopRightFaceLeft8F(Mmdl *mmdl)
{
    FLDMMDL_ACMD_HopInit(mmdl, ACMD_GRID_SPEED(8), MMDL_DIR_LEFT, MMDL_DIR_RIGHT, 8, MMDL_DRAWSTA_WALK_8F, ACMD_AXIS_X, ACMD_AXIS_Y, 0);
    return 1;
}

/* Walks in place for 22 frames. */
int FLDMMDL_ACMD_StayWalk22FInit(Mmdl *mmdl)
{
    FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdCounterWork));
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_WALK_32F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_StayWalk22FMove(Mmdl *mmdl)
{
    AcmdCounterWork *work;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    if (++work->count >= 22) {
        FLDMMDL_IncAcmdSeq(mmdl);
    }
    return 0;
}

int FLDMMDL_ACMD_AnimeDash4FSetNext(Mmdl *mmdl)
{
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_4F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

/* Moves one grid to the left in 2 frames with the 2 frame dash status. */
int FLDMMDL_ACMD_DashLeft2F(Mmdl *mmdl)
{
    AcmdWalkWork *work;

    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdWalkWork));
    work->drawStatus = MMDL_DRAWSTA_DASH_2F;
    work->framesLeft = 2;
    work->dir = MMDL_DIR_LEFT;
    work->speed = ACMD_GRID_SPEED(2);
    FLDMMDL_MOVE_UpdateGridPosDir(mmdl, (u16)work->dir);
    FLDMMDL_SetDrawStatus(mmdl, work->drawStatus);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_Dash2FMove(Mmdl *mmdl)
{
    AcmdWalkWork *work;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    FLDMMDL_MOVE_AddDirVectorPos(mmdl, (u16)work->dir, work->speed);
    FLDMMDL_MOVE_UpdateHeight(mmdl);
    work->framesLeft = work->framesLeft - 1;
    if (work->framesLeft > 0) {
        return 0;
    }
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

/* Flies up out of sight: the model rises with a dash animation and wing sounds. */
int FLDMMDL_ACMD_FlyUpInit(Mmdl *mmdl)
{
    AcmdFlyWork *work;

    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdFlyWork));
    work->speed = ACMD_FLY_SPEED;
    work->elapsed = 0;
    work->lastFrame = 0;
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_6F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_FlyUpMove(Mmdl *mmdl)
{
    AcmdFlyWork *work;
    u16 animeState;
    u16 animeFrame;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    if (FLDMMDL_DRAW_GetBlactAnimeTypeA(mmdl, &animeState, &animeFrame) != 1)
        return 0;
    work->elapsed = work->elapsed + 1;
    animeFrame = animeFrame - 1;
    if (FLDMMDL_GetObjCode(mmdl) == MMDL_OBJCODE_FLY_A) {
        if (animeState == 2 && work->lastFrame != animeFrame) {
            work->lastFrame = animeFrame;
            switch (animeFrame) {
            case 7:
            case 12:
            case 17:
                GFL_USE_PlaySeDefaultVolume(SE_FLY_FLAP_A);
                break;
            case 10:
            case 15:
            case 20:
                GFL_USE_PlaySeDefaultVolume(SE_FLY_FLAP_B);
                break;
            }
        }
    } else if (work->elapsed == ACMD_FLY_TAKEOFF_FRAMES) {
        GFL_USE_PlaySeDefaultVolume(SE_FLY_TAKEOFF);
    }
    if (work->elapsed < ACMD_FLY_TAKEOFF_FRAMES)
        return 0;
    work->height += work->speed;
    {
        MmdlVec offset = { 0, 0, 0 };
        offset.y = work->height;
        FLDMMDL_SetDrawOffset(mmdl, &offset);
    }
    if (work->height / 0x8000 < 16)
        return 0;
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_STOP);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_AnimeDash4FSetNextAlt(Mmdl *mmdl)
{
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_4F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_AnimeDash6FSetAlt(Mmdl *mmdl)
{
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_6F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

/* Waits for the end of the draw animation, then faces down and stops the draw status. */
int FLDMMDL_ACMD_AnimeWaitEndFaceDown(Mmdl *mmdl)
{
    void *blActSys;
    u32 animeId;
    u16 animeFlag;

    blActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys(mmdl)));
    animeId = FLDMMDL_CallDrawGetProc(mmdl, 0);
    if (animeId != 0xFFFF) {
        if (BILLBOARD_ACT_GetEntryLastCommand(blActSys, (u16)animeId, &animeFlag) == 0) {
            return 0;
        }
    }
    FLDMMDL_SetDirDispCheckPause(mmdl, MMDL_DIR_DOWN);
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_STOP);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_ResetDrawOffset(Mmdl *mmdl)
{
    MmdlVec offset = { 0, 0, 0 };

    FLDMMDL_SetDrawOffset(mmdl, &offset);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

/* Starts the wait before the flight: the model hovers half a grid up with a dash animation. */
int FLDMMDL_ACMD_FlyReadyInit(Mmdl *mmdl)
{
    AcmdFlyReadyWork *work;
    MmdlVec offset = d_021D4ACC;

    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(AcmdFlyReadyWork));
    work->elapsed = 0;
    work->lastFrame = 0;
    FLDMMDL_SetDrawOffset(mmdl, &offset);
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_4F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_FlyReadyMove(Mmdl *mmdl)
{
    AcmdFlyReadyWork *work;
    u16 animeState;
    u16 animeFrame;

    work = FLDMMDL_GetMoveCmdWork(mmdl);
    if (FLDMMDL_DRAW_GetBlactAnimeTypeB(mmdl, &animeState, &animeFrame) != 1)
        return 0;
    work->elapsed = work->elapsed + 1;
    animeFrame = animeFrame - 1;
    if (FLDMMDL_GetObjCode(mmdl) == MMDL_OBJCODE_FLY_B && animeState == 0 && work->lastFrame != animeFrame) {
        work->lastFrame = animeFrame;
        switch (animeFrame) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(SE_FLY_FLAP_A);
            break;
        case 3:
            GFL_USE_PlaySeDefaultVolume(SE_FLY_FLAP_B);
            break;
        }
    }
    if (work->elapsed < ACMD_FLY_TAKEOFF_FRAMES)
        return 0;
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_ACMD_AnimeDash4FSet(Mmdl *mmdl)
{
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_4F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_AnimeDash6FSet(Mmdl *mmdl)
{
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_6F);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

int FLDMMDL_ACMD_AnimeDash2FSetReset(Mmdl *mmdl)
{
    FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_DASH_2F);
    FLDMMDL_DRAW_ResetBlactAnime(mmdl);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

/* Waits until the draw object is ready, then stops the draw status. */
int FLDMMDL_ACMD_DrawReadyWaitStop(Mmdl *mmdl)
{
    if (FLDMMDL_DRAW_CheckBlactReady(mmdl) == 1) {
        FLDMMDL_SetDrawStatus(mmdl, MMDL_DRAWSTA_STOP);
        FLDMMDL_IncAcmdSeq(mmdl);
        return 1;
    }
    return 0;
}

int FLDMMDL_ACMD_DrawReadyWait(Mmdl *mmdl)
{
    if (FLDMMDL_DRAW_CheckBlactReady(mmdl) == 1) {
        FLDMMDL_IncAcmdSeq(mmdl);
        return 1;
    }
    return 0;
}
