/*
 * file:     fldmmdl_movecode.c
 * unit:     yes
 * function: FLDMMDL_MOVECODE_InitTurnRandom, FLDMMDL_MOVECODE_InitTurnRandomSet0, FLDMMDL_MOVECODE_InitTurnRandomSet1, FLDMMDL_MOVECODE_InitTurnRandomSet2, FLDMMDL_MOVECODE_InitTurnRandomSet3, FLDMMDL_MOVECODE_InitTurnRandomSet4, FLDMMDL_MOVECODE_InitTurnRandomSet5, FLDMMDL_MOVECODE_InitTurnRandomSet6, FLDMMDL_MOVECODE_InitTurnRandomSet7, FLDMMDL_MOVECODE_InitTurnRandomSet8, FLDMMDL_MOVECODE_InitTurnRandomSet9, FLDMMDL_MOVECODE_InitTurnRandomSet10, FLDMMDL_MOVECODE_MoveTurnRandom, FLDMMDL_MOVECODE_GetNextDirInRotation, FLDMMDL_MOVECODE_NoOp, FLDMMDL_MOVECODE_InitWalkRandomSet11, FLDMMDL_MOVECODE_InitWalkRandomSet12, FLDMMDL_MOVECODE_InitWalkRandomSet13, FLDMMDL_MOVECODE_InitWalkRandomSet13Bump, FLDMMDL_MOVECODE_InitWalkRandom, FLDMMDL_MOVECODE_MoveWalkRandom, FLDMMDL_MOVECODE_GetMoveRect, FLDMMDL_MOVECODE_IsDirInsideMoveRect, FLDMMDL_MOVECODE_InitFixedDir, FLDMMDL_MOVECODE_MoveFixedDir, FLDMMDL_MOVECODE_InitFixedDirUp, FLDMMDL_MOVECODE_InitFixedDirDown, FLDMMDL_MOVECODE_InitFixedDirLeft, FLDMMDL_MOVECODE_InitFixedDirRight, FLDMMDL_MOVECODE_InitSpin, FLDMMDL_MOVECODE_InitSpinLeft, FLDMMDL_MOVECODE_InitSpinRight, FLDMMDL_MOVECODE_MoveSpin, FLDMMDL_MOVECODE_SpinStepTurn, FLDMMDL_MOVECODE_SpinStepWaitTurn, FLDMMDL_MOVECODE_SpinStepWaitInterval, FLDMMDL_MOVECODE_SpinStepRotateDir, FLDMMDL_MOVECODE_InitSwing, FLDMMDL_MOVECODE_MoveSwing, FLDMMDL_MOVECODE_SwingStepTurn, FLDMMDL_MOVECODE_SwingStepWaitTurn, FLDMMDL_MOVECODE_SwingStepWaitInterval, FLDMMDL_MOVECODE_SwingStepRotateDir, FLDMMDL_MOVECODE_InitBackForth, FLDMMDL_MOVECODE_MoveBackForth, FLDMMDL_MOVECODE_BackForthStepFaceDir, FLDMMDL_MOVECODE_BackForthStepWalk, FLDMMDL_MOVECODE_BackForthStepWaitWalk, FLDMMDL_MOVECODE_InitRoutePatrol, FLDMMDL_MOVECODE_InitRoutePatrolRoute0E, FLDMMDL_MOVECODE_InitRoutePatrolRoute0F, FLDMMDL_MOVECODE_InitRoutePatrolRoute10, FLDMMDL_MOVECODE_InitRoutePatrolRoute11, FLDMMDL_MOVECODE_InitRoutePatrolRoute12, FLDMMDL_MOVECODE_InitRoutePatrolRoute13, FLDMMDL_MOVECODE_InitRoutePatrolRoute14, FLDMMDL_MOVECODE_InitRoutePatrolRoute15, FLDMMDL_MOVECODE_InitRoutePatrolRoute16, FLDMMDL_MOVECODE_InitRoutePatrolRoute17, FLDMMDL_MOVECODE_InitRoutePatrolRoute18, FLDMMDL_MOVECODE_InitRoutePatrolRoute19, FLDMMDL_MOVECODE_InitRoutePatrolRoute1A, FLDMMDL_MOVECODE_InitRoutePatrolRoute1B, FLDMMDL_MOVECODE_InitRoutePatrolRoute1C, FLDMMDL_MOVECODE_InitRoutePatrolRoute1D, FLDMMDL_MOVECODE_MoveRoutePatrol, FLDMMDL_MOVECODE_RoutePatrolStepWalk, FLDMMDL_MOVECODE_RoutePatrolStepWaitWalk, FLDMMDL_MOVECODE_InitRoutePatrolSwap, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute1E, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute1F, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute20, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute21, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute22, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute23, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute24, FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute25, FLDMMDL_MOVECODE_MoveRoutePatrolSwap, FLDMMDL_MOVECODE_AdvanceRouteIndex, FLDMMDL_MOVECODE_RoutePatrolSwapStepLookForPlayer, FLDMMDL_MOVECODE_RoutePatrolSwapStepSwapMoveCode, FLDMMDL_MOVECODE_RoutePatrolSwapStepWalk, FLDMMDL_MOVECODE_RoutePatrolSwapStepWaitWalk, FLDMMDL_MOVECODE_IsBButtonHeld, FLDMMDL_MOVECODE_IsPlayerWalking, FLDMMDL_MOVECODE_IsBButtonPressed, FLDMMDL_MOVECODE_FindTableEnd, FLDMMDL_MOVECODE_GetRandomTableEntry, FLDMMDL_MOVECODE_GetRandomDirFromSet, FLDMMDL_MOVECODE_GetDirSet, FLDMMDL_MOVECODE_GetSightDirToPlayer, FLDMMDL_MOVECODE_GetDirTowardPlayerInSet, FLDMMDL_MOVECODE_UpdateTriggerWait, FLDMMDL_MOVECODE_IsDashEventType, FLDMMDL_MOVECODE_IsMirrorEventType, FLDMMDL_MOVECODE_InitMirrorSide, FLDMMDL_MOVECODE_StartMirrorTurn, FLDMMDL_MOVECODE_EndMirrorTurn, FLDMMDL_MOVECODE_InitEventTypeProcThunk, FLDMMDL_MOVECODE_UpdateEventTypeProc, FLDMMDL_MOVECODE_InitByEventType, FLDMMDL_MOVECODE_CheckByEventType, FLDMMDL_MOVECODE_UpdateByEventType, FLDMMDL_MOVECODE_HasLeftOldGrid, FLDMMDL_MOVECODE_IsAtOldGrid, FLDMMDL_MOVECODE_NoOpHook, FLDMMDL_MOVECODE_ReturnFalseA, FLDMMDL_MOVECODE_ReturnFalseB, FLDMMDL_MOVE_InitWalkRepeat, FLDMMDL_MOVE_WalkRepeat, FLDMMDL_MOVE_TurnLookAround, FLDMMDL_MOVE_InitWalkRepeatSpin, FLDMMDL_MOVE_WalkRepeatSpin, FLDMMDL_MOVE_TurnSpin, FLDMMDL_MOVE_IsButtonBHeld, FLDMMDL_MOVE_InitLookPlayer, FLDMMDL_MOVE_LookPlayer, FLDMMDL_MOVE_DeleteLookPlayer, FLDMMDL_MOVE_LookPlayerTurn, FLDMMDL_MOVE_LookPlayerWaitTurn, FLDMMDL_MOVE_UpdatePlayerTracking, FLDMMDL_MOVE_StartPlayerTracking, FLDMMDL_MOVE_HasPlayerMoved, FLDMMDL_MOVE_SavePlayerGridPos, FLDMMDL_MOVE_GetTurnAcmdBase, FLDMMDL_MOVE_TurnToPlayer, FLDMMDL_MOVE_InitLookFellow, FLDMMDL_MOVE_LookFellow, FLDMMDL_MOVE_DeleteLookFellow, FLDMMDL_MOVE_ClearFellowTracking, FLDMMDL_MOVE_LookFellowTurn, FLDMMDL_MOVE_LookFellowWaitTurn, FLDMMDL_MOVE_FindFellow, FLDMMDL_MOVE_UpdateFellowTracking, FLDMMDL_MOVE_StartFellowTracking, FLDMMDL_MOVE_CanTurnToFellow, FLDMMDL_MOVE_TurnToFellow, FLDMMDL_MOVE_InitHide, FLDMMDL_MOVE_InitHideKind0, FLDMMDL_MOVE_InitHideKind1, FLDMMDL_MOVE_InitHideKind1Alt, FLDMMDL_MOVE_InitHideKind0Alt, FLDMMDL_MOVE_Hide, FLDMMDL_MOVE_DeleteHide, FLDMMDL_MOVE_RecoverHide, FLDEFF_HIDE_Create, FLDMMDL_MOVE_HideCreateEffect, FLDMMDL_MOVE_HideKeepEffect, FLDMMDL_MOVE_SetHideEffect, FLDMMDL_MOVE_GetHideEffect, FLDMMDL_MOVE_SetHideNoEffect, FLDMMDL_MOVE_InitFaceDir, FLDMMDL_MOVE_InitFaceDirUp, FLDMMDL_MOVE_InitFaceDirDown, FLDMMDL_MOVE_InitFaceDirLeft, FLDMMDL_MOVE_InitFaceDirRight, FLDMMDL_MOVE_InitFaceDirUpFlag, FLDMMDL_MOVE_InitFaceDirDownFlag, FLDMMDL_MOVE_InitFaceDirLeftFlag, FLDMMDL_MOVE_InitFaceDirRightFlag, FLDMMDL_MOVE_FaceDir, FLDMMDL_MOVE_FaceDirTurnSelf, FLDMMDL_MOVE_FaceDirWaitTurn, FLDMMDL_MOVE_FaceDirResolvePlayerDir, FLDMMDL_MOVE_FaceDirTurnPlayerDir, FLDMMDL_MOVE_FaceDirWaitPlayerTurn, FLDMMDL_MOVE_InitWallWalk, FLDMMDL_MOVE_InitWallWalkMode0Hand0, FLDMMDL_MOVE_InitWallWalkMode1Hand1, FLDMMDL_MOVE_InitWallWalkMode2Hand0, FLDMMDL_MOVE_InitWallWalkMode2Hand1, FLDMMDL_MOVE_WallWalk, FLDMMDL_MOVE_WallWalkStop, FLDMMDL_MOVE_WallWalkTryStep, FLDMMDL_MOVE_WallWalkWaitStep, FLDMMDL_MOVE_IsWallAtOffsetA, FLDMMDL_MOVE_IsWallAtOffsetB, FLDMMDL_MOVE_IsWallNearA, FLDMMDL_MOVE_IsWallNearB, FLDMMDL_MOVE_GetWallWalkDir, FLDMMDL_MOVE_HitCheckWallWalkDir, FLDMMDL_MOVE_WallWalkStepOnce
 * address:  0x0219A098
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from unit_02198D3C.c at 0x0219A098 (lane L138, move code handlers, step tables and helpers; original unknown).
 * Field model move codes: turn in place, random walk, fixed direction, spin, swing, back and forth, route patrol (work areas in fldmmdl_movecode_types.h), and the event type helpers they share.
 * Merged from unit_0219A098.c and unit_0219B508.c, which are one original (model move code file).
 *
 * symbols:
 *   FLDMMDL_ACMD_WalkTableInit  0x02198C08  thumb
 *   FLDMMDL_ACMD_WalkTableMove       0x02198C4C  thumb
 *   DWCca_ghttp_caList  0x021D4A44  data
 *   DWCca_ghttp_caList_b 0x021D4A80  data
 *   DWCca_ghttp_caList_c 0x021D4A9C  data
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_ACMD_AnimeDash4FStart  0x02198E44  thumb
 *   FLDMMDL_ACMD_AnimeDash6FStart  0x02198E60  thumb
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   FLDEFF_HIDE_RequestEnd  0x021D04A4  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   FLDEFF_HIDE_IsFinished  0x021D04C4  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   d_021D4C1C     0x021D4C1C  data   a4
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
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
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   d_021D4B44     0x021D4B44  data  ov021  a4
 *   d_021D4204     0x021D4204  data  ov021  a4
 *   d_021D4C04     0x021D4C04  data  a4
 *   d_021D41E0     0x021D41E0  data  ov021  a4
 *   d_021D4210     0x021D4210  data  a4
 *   d_021D4C10     0x021D4C10  data  a4
 *   d_021D4648     0x021D4648  data  a4
 *   d_021D4BF8     0x021D4BF8  data  a4
 *   d_021D4BEC     0x021D4BEC  data  a4
 *   d_021D4BE0     0x021D4BE0  data  a4
 *   d_021D4BD4     0x021D4BD4  data  a4
 *   d_021D4BC8     0x021D4BC8  data  a4
 *   d_021D4BBC     0x021D4BBC  data  a4
 *   d_021D4BB0     0x021D4BB0  data  a4
 *   d_021D4BA4     0x021D4BA4  data  a4
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
 *   _s32_div_f     0x0209C0A4  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_MOVE_UpdateGridPosDir  0x02163E7C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVectorPos  0x02163FC0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_DRAW_GetBlactAnimeTypeA  0x0219FC68  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   d_021D4ACC     0x021D4ACC  data  a4
 *   FLDMMDL_DRAW_GetBlactAnimeTypeB  0x0219FCC0  thumb  ov021
 *   FLDMMDL_DRAW_ResetBlactAnime  0x0219FE64  thumb  ov021
 *   FLDMMDL_DRAW_CheckBlactReady  0x0219FE20  thumb  ov021
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb
 *   gMmdlRandomWaitFrames     0x021D4FA4  data  a4
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
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 *   FLDMMDL_GetGridInitX  0x0216D7E8  thumb  ov010
 *   FLDMMDL_GetGridInitZ  0x0216D7F8  thumb  ov010
 *   FLDMMDL_GetMoveLimitX  0x0216D660  thumb  ov010
 *   FLDMMDL_GetMoveLimitZ  0x0216D66C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   gMmdlSpinSteps  0x021D4DE8  data  a4
 *   gMmdlSpinDirsLeft     0x021D5024  data  a4
 *   gMmdlSpinDirsRight     0x021D5038  data  a4
 *   gMmdlSwingSteps  0x021D4DB8  data  a4
 *   gMmdlSwingDirsLeft     0x021D504C  data  a4
 *   gMmdlSwingDirsRight     0x021D5060  data  a4
 *   FLDMMDL_GetDirHeader  0x0216D5D4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   gMmdlBackForthSteps  0x021D4D60  data  a4
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   gMmdlRoutePatrolSteps  0x021D4D04  data  a4
 *   gMmdlRoutePatrolSwapSteps  0x021D4D78  data  a4
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   EVENT_TRAINER_EYE_GetPlayerDistance  0x021AE198  thumb  ov021
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 *   gMmdlSwapMoveCodePairs     0x021D4F90  data    a2
 *   KEY_GetCont  0x0203630C  arm
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   gMmdlDirSets  0x021D50F8  data  a4
 *   FLDMMDL_MOVE_GetDirFromPoints  0x021642B4  thumb  ov010
 *   gMmdlSightMoveCodes  0x021D4FEC  data  a4
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   gMmdlMirrorDirCycles     0x021D4FCC  data    a4
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   gMmdlEventTypeInitProcs  0x021D5278  data   ov021  a4
 *   gMmdlEventTypeCheckProcs  0x021D52CC  data  a4
 *   gMmdlEventTypeUpdateProcs  0x021D5320  data  a4
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_InitMoveSubProcWork  0x0216D6A0  thumb  ov010
 *   FLDMMDL_GetMoveSubProcWork  0x0216D6B8  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   gLookAroundDirGroup     0x021D5238  data   ov021  a4
 *   gLookAroundDirTable     0x021D5248  data   ov021  a4
 *   gSpinDirTable     0x021D5258  data   ov021  a4
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   gLookPlayerStepTable  0x021D5374  data  a4
 *   gLookFellowStepTable  0x021D538C  data  a4
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   EVENT_TRAINER_EYE_GetTrainerId  0x021AE884  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   gHideDrawOffsetInit     0x021D5474  data   ov021  a4
 *   gHideStepTable  0x021D537C  data  a4
 *   gHideDrawOffsetRecover     0x021D5480  data   ov021  a4
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_HIDE_Start  0x021D046C  thumb  ov021
 *   FLDMMDL_CheckDrawInitComp  0x0216DB24  thumb  ov010
 *   gFaceDirStepTable  0x021D53A0  data  a4
 *   gWallWalkStepTable  0x021D5394  data  a4
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   gWallCheckOffsetAX  0x021D53B4  data  a4
 *   gWallCheckOffsetAZ  0x021D53D4  data  a4
 *   gWallCheckOffsetBX  0x021D5414  data  a4
 *   gWallCheckOffsetBZ  0x021D5434  data  a4
 *   gWallWalkRedirectDir  0x021D53F4  data  a4
 *   gWallWalkHandSwap     0x021D5384  data   a4
 *   gWallWalkBounceDir     0x021D5454  data   ov021  a4
 */
#include "fldmmdl_movecode_types.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

/* One step of a move code: returns 1 to run the next step in the same frame. */
typedef int (*MmdlStepProc)(Mmdl *mmdl, void *work);

extern u32 FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 v);
extern MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
extern u32 FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
extern int FLDMMDL_SetDirMove(Mmdl *mmdl, u16 dir);
extern int FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern int FLDMMDL_GetGridNowY(Mmdl *mmdl);
extern int FLDMMDL_GetGridNowZ(Mmdl *mmdl);
extern int FLDMMDL_MOVE_UpdateOldGridPos(Mmdl *mmdl);
extern void *FLDMMDL_InitMoveProcWork();
extern int FLDMMDL_OffMoveBitMove(Mmdl *mmdl);
extern void *FLDMMDL_GetMoveProcWork();
extern u16 FLDMMDL_GetEventType(Mmdl *mmdl);
extern int FLDMMDL_MOVE_IsNearPlayer(Mmdl *mmdl);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern u16 FLDMMDL_GetMoveCode(Mmdl *mmdl);
extern void FLDMMDL_OffMoveBitMoveEnd(Mmdl *mmdl);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int dir, int speed);
extern void FLDMMDL_SetLocalAcmd(Mmdl *mmdl, int acmd);
extern u32 FLDMMDL_ACMD_Update(Mmdl *mmdl);
extern void FLDMMDL_SetDirAll(Mmdl *mmdl, u16 dir);
extern int FLDMMDL_MOVE_HitCheckMoveDir(Mmdl *mmdl, u16 dir);
extern void FLDMMDL_OnMoveBitMove(Mmdl *mmdl);
extern int FLDMMDL_GetGridInitX(Mmdl *mmdl);
extern int FLDMMDL_GetGridInitZ(Mmdl *mmdl);
extern int FLDMMDL_GetMoveLimitX(Mmdl *mmdl);
extern int FLDMMDL_GetMoveLimitZ(Mmdl *mmdl);
extern int FLDMMDL_MOVE_GetDirAddGridX(int dir);
extern int FLDMMDL_MOVE_GetDirAddGridZ(u16 dir);
extern int FLDMMDL_GetDirHeader(Mmdl *mmdl);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int dir);
extern u16 FLDMMDL_GetDirMove(Mmdl *mmdl);
extern int FLDMMDL_GetParam(Mmdl *mmdl, int index);
extern int EVENT_TRAINER_EYE_GetPlayerDistance(Mmdl *mmdl, int a, int b, int c);
extern int FLDMMDL_ChangeMoveCode(Mmdl *mmdl, int moveCode);
extern unsigned int KEY_GetCont(void);
extern Mmdl *FLDMMDL_SysSearchPlayer(MmdlSys *sys);
extern u16 FLDMMDL_GetAcmdCode(Mmdl *mmdl);
extern u32 KEY_GetTrg(void);
extern u32 GFL_USE_GetRandom(u32 range);
extern u16 FLDMMDL_MOVE_GetDirFromPoints(int x0, int y0, int x1, int y1);
extern int FLDMMDL_CheckStatusBit(Mmdl *mmdl, int bit);
extern u32 *FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bit);
extern u32 *FLDMMDL_ClearStatusBit(Mmdl *mmdl, u32 bit);
extern int FLDMMDL_GetGridOldX(Mmdl *mmdl);
extern int FLDMMDL_GetGridOldZ(Mmdl *mmdl);

extern u32 gMmdlRandomWaitFrames[];
extern u16 gMmdlRotationDirRows[][6];
extern MmdlStepProc gMmdlSpinSteps[];
extern const MmdlDirCycle gMmdlSpinDirsLeft;
extern const MmdlDirCycle gMmdlSpinDirsRight;
extern MmdlStepProc gMmdlSwingSteps[];
extern const MmdlDirCycle gMmdlSwingDirsLeft;
extern const MmdlDirCycle gMmdlSwingDirsRight;
extern MmdlStepProc gMmdlBackForthSteps[];
extern MmdlStepProc gMmdlRoutePatrolSteps[];
extern MmdlStepProc gMmdlRoutePatrolSwapSteps[];
extern u16 gMmdlSwapMoveCodePairs[];
extern MmdlDirSetEntry gMmdlDirSets[];
extern u32 gMmdlSightMoveCodes[];
extern u32 gMmdlMirrorDirCycles[][4];
extern int (*const gMmdlEventTypeInitProcs[])(Mmdl *mmdl);
extern u32 (*const gMmdlEventTypeCheckProcs[])(Mmdl *mmdl);
extern u32 (*const gMmdlEventTypeUpdateProcs[])(Mmdl *mmdl);

int FLDMMDL_MOVECODE_IsBButtonHeld(void);
int FLDMMDL_MOVECODE_IsBButtonPressed(void);
int FLDMMDL_MOVECODE_FindTableEnd(u32 *table, u32 endMark);
int FLDMMDL_MOVECODE_GetRandomTableEntry(u32 *table, u32 endMark);
u32 FLDMMDL_MOVECODE_GetRandomDirFromSet(u32 setId, u32 endMark);
u32 *FLDMMDL_MOVECODE_GetDirSet(u32 setId);
int FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(Mmdl *mmdl, int setId, int endMark);
int FLDMMDL_MOVECODE_UpdateTriggerWait(Mmdl *mmdl, u8 *triggerCount);
int FLDMMDL_MOVECODE_IsDashEventType(Mmdl *mmdl);
int FLDMMDL_MOVECODE_IsMirrorEventType(Mmdl *mmdl);
void FLDMMDL_MOVECODE_InitMirrorSide(Mmdl *mmdl, MmdlMirrorState *mirror);
void FLDMMDL_MOVECODE_StartMirrorTurn(Mmdl *mmdl, MmdlMirrorState *mirror);
void FLDMMDL_MOVECODE_EndMirrorTurn(Mmdl *mmdl, MmdlMirrorState *mirror);
int FLDMMDL_MOVECODE_InitByEventType(Mmdl *mmdl);
u32 FLDMMDL_MOVECODE_CheckByEventType(Mmdl *mmdl);
u32 FLDMMDL_MOVECODE_UpdateByEventType(Mmdl *mmdl);
int FLDMMDL_MOVECODE_IsDirInsideMoveRect(Mmdl *mmdl, u32 dir);
void FLDMMDL_MOVECODE_GetMoveRect(Mmdl *mmdl, MmdlMoveRect *rect);
int FLDMMDL_MOVECODE_InitFixedDir(Mmdl *mmdl, u32 dir);
void FLDMMDL_MOVECODE_InitSpin(Mmdl *mmdl, u8 rotation);
void FLDMMDL_MOVECODE_InitRoutePatrol(Mmdl *mmdl, u32 speed, u32 axis, u32 routeId);
void FLDMMDL_MOVECODE_InitRoutePatrolSwap(Mmdl *mmdl, u32 speed, u32 axis, u32 routeId);
void FLDMMDL_MOVECODE_InitWalkRandom(Mmdl *mmdl, u32 acmdSpeed, u32 dirSetId, u32 limitMode);
int FLDMMDL_MOVECODE_InitTurnRandom(Mmdl *mmdl, u32 kind);
u16 FLDMMDL_MOVECODE_GetNextDirInRotation(u16 moveCode, u16 dir);
void FLDMMDL_MOVECODE_AdvanceRouteIndex(MmdlRoutePatrolSwapWork *work);
struct Actor;
struct VecFx32;

typedef struct DirGroupTable { u32 group[4]; } DirGroupTable;

typedef struct LookAroundDirTable { u32 dir[2][2]; } LookAroundDirTable;

typedef struct SpinDirTable { u32 dir[2][4]; } SpinDirTable;


extern void *FLDMMDL_InitMoveSubProcWork(Mmdl *mmdl, int size);
extern void *FLDMMDL_GetMoveSubProcWork(Mmdl *mmdl);
extern int FLDMMDL_CheckMoveBitMove(Mmdl *mmdl);
extern u32 FLDMMDL_SetStatusBitFellowHit(Mmdl *mmdl, u32 mode);
extern u16 FLDMMDL_GetZoneId(Mmdl *mmdl);
extern int EVENT_TRAINER_EYE_GetTrainerId(Mmdl *mmdl);
extern int FLDMMDL_SysSearchUseMmdl(void *mmdlSys, void **outMmdl, u32 *iter);
extern u32 FLDMMDL_CheckMoveBit(Mmdl *mmdl, u32 bits);
extern void *FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bits);
extern void FLDMMDL_SetDrawOffset(Mmdl *mmdl, void *offset);
extern void FIELD_EFFECT_DeleteObject(u32 effect);
extern u32 FLDMMDL_SysGetFieldMap(void *mmdlSys);
extern u32 FIELDMAP_GetEffect(u8 *fieldMap);
extern u32 FLDEFF_HIDE_Start(u32 fieldMap, Mmdl *mmdl, u32 kind);
extern int FLDMMDL_CheckDrawInitComp(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDir();
u32 FLDMMDL_MOVE_InitFaceDirUp(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDirDown(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDirLeft(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDirRight(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDirUpFlag(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDirDownFlag(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDirLeftFlag(Mmdl *mmdl);
u32 FLDMMDL_MOVE_InitFaceDirRightFlag(Mmdl *mmdl);
void FLDMMDL_MOVE_InitWallWalk();
void FLDMMDL_MOVE_FaceDir(Mmdl *mmdl);
int FLDMMDL_MOVE_FaceDirTurnSelf(Mmdl *mmdl, u32 unusedWork, u32 regR2, u32 regR3);
int FLDMMDL_MOVE_FaceDirWaitTurn(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3);
int FLDMMDL_MOVE_FaceDirResolvePlayerDir(Mmdl *mmdl, s8 *work);
int FLDMMDL_MOVE_FaceDirTurnPlayerDir(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3);
int FLDMMDL_MOVE_FaceDirWaitPlayerTurn(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3);
void FLDMMDL_MOVE_InitWallWalkMode0Hand0(Mmdl *mmdl);
void FLDMMDL_MOVE_InitWallWalkMode1Hand1(Mmdl *mmdl);
void FLDMMDL_MOVE_InitWallWalkMode2Hand0(Mmdl *mmdl);
void FLDMMDL_MOVE_InitWallWalkMode2Hand1(Mmdl *mmdl);
extern int FLDMMDL_MOVE_GetMapAttr(Mmdl *mmdl, MmdlVec *pos, u32 *outAttr);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern void FLDMMDL_GetPos(const struct Actor *mmdl, struct VecFx32 *pos);
void FLDMMDL_MOVE_InitWalkRepeat(Mmdl *mmdl);
int FLDMMDL_MOVE_WalkRepeat(Mmdl *mmdl);
int FLDMMDL_MOVE_TurnLookAround(Mmdl *mmdl);
void FLDMMDL_MOVE_InitWalkRepeatSpin(Mmdl *mmdl);
int FLDMMDL_MOVE_WalkRepeatSpin(Mmdl *mmdl);
int FLDMMDL_MOVE_TurnSpin(Mmdl *mmdl);
int FLDMMDL_MOVE_IsButtonBHeld(void);
int FLDMMDL_MOVE_InitLookPlayer(Mmdl *mmdl, u32 unusedWork, u32 regR2, u32 regR3);
void FLDMMDL_MOVE_LookPlayer(Mmdl *mmdl);
void FLDMMDL_MOVE_DeleteLookPlayer(void);
int FLDMMDL_MOVE_LookPlayerTurn(Mmdl *mmdl, MmdlLookWork *work);
int FLDMMDL_MOVE_LookPlayerWaitTurn(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3);
int FLDMMDL_MOVE_UpdatePlayerTracking(Mmdl *mmdl, MmdlLookWork *work);
void FLDMMDL_MOVE_StartPlayerTracking(Mmdl *mmdl, MmdlLookWork *work);
int FLDMMDL_MOVE_HasPlayerMoved(Mmdl *mmdl, MmdlLookWork *work);
void FLDMMDL_MOVE_SavePlayerGridPos(Mmdl *mmdl, MmdlLookWork *work);
int FLDMMDL_MOVE_GetTurnAcmdBase(Mmdl *mmdl);
int FLDMMDL_MOVE_TurnToPlayer(Mmdl *mmdl);
void FLDMMDL_MOVE_InitLookFellow(Mmdl *mmdl);
void FLDMMDL_MOVE_LookFellow(Mmdl *mmdl);
void FLDMMDL_MOVE_DeleteLookFellow(void);
void FLDMMDL_MOVE_ClearFellowTracking(void);
int FLDMMDL_MOVE_LookFellowTurn(Mmdl *mmdl, MmdlLookWork *work);
int FLDMMDL_MOVE_LookFellowWaitTurn(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3);
Mmdl *FLDMMDL_MOVE_FindFellow(Mmdl *mmdl);
int FLDMMDL_MOVE_UpdateFellowTracking(Mmdl *mmdl, MmdlLookWork *work);
int FLDMMDL_MOVE_StartFellowTracking(Mmdl *mmdl, MmdlLookWork *work, Mmdl *fellow);
int FLDMMDL_MOVE_CanTurnToFellow(Mmdl *mmdl, MmdlLookWork *work);
int FLDMMDL_MOVE_TurnToFellow(Mmdl *mmdl, MmdlLookWork *work);
void FLDMMDL_MOVE_InitHide(Mmdl *mmdl, u32 kind);
void FLDMMDL_MOVE_InitHideKind0(Mmdl *mmdl);
void FLDMMDL_MOVE_InitHideKind1(Mmdl *mmdl);
void FLDMMDL_MOVE_InitHideKind1Alt(Mmdl *mmdl);
void FLDMMDL_MOVE_InitHideKind0Alt(Mmdl *mmdl);
void FLDMMDL_MOVE_Hide(Mmdl *mmdl);
void FLDMMDL_MOVE_DeleteHide(Mmdl *mmdl);
void FLDMMDL_MOVE_RecoverHide(Mmdl *mmdl);
int FLDEFF_HIDE_Create(Mmdl *mmdl, u32 kind);
int FLDMMDL_MOVE_HideCreateEffect(Mmdl *mmdl, MmdlHideWork *work);
int FLDMMDL_MOVE_HideKeepEffect(Mmdl *mmdl, MmdlHideWork *work, u32 regR2, u32 regR3);
void FLDMMDL_MOVE_SetHideEffect(Mmdl *mmdl, u32 effect);
int FLDMMDL_MOVE_GetHideEffect(Mmdl *mmdl);
void FLDMMDL_MOVE_SetHideNoEffect(Mmdl *mmdl);
void FLDMMDL_MOVE_WallWalk(Mmdl *mmdl);
int FLDMMDL_MOVE_WallWalkStop(Mmdl *mmdl, MmdlWallWalkWork *work);
int FLDMMDL_MOVE_WallWalkTryStep(Mmdl *mmdl, MmdlWallWalkWork *work);
int FLDMMDL_MOVE_WallWalkWaitStep(Mmdl *mmdl, MmdlWallWalkWork *work, u32 regR2, u32 regR3);
int FLDMMDL_MOVE_IsWallAtOffsetA(Mmdl *mmdl, MmdlVec *pos, int dir, int hand);
int FLDMMDL_MOVE_IsWallAtOffsetB(Mmdl *mmdl, MmdlVec *pos, int dir, int hand);
int FLDMMDL_MOVE_IsWallNearA(Mmdl *mmdl, int dir, int hand);
int FLDMMDL_MOVE_IsWallNearB(Mmdl *mmdl, int dir, int hand);
int FLDMMDL_MOVE_GetWallWalkDir(Mmdl *mmdl, int dir, int hand);
int FLDMMDL_MOVE_HitCheckWallWalkDir(Mmdl *mmdl, int *dir, u32 hand);
int FLDMMDL_MOVE_WallWalkStepOnce(Mmdl *mmdl, MmdlWallWalkWork *work, u32 acmdKind);
extern DirGroupTable gLookAroundDirGroup;
extern LookAroundDirTable gLookAroundDirTable;
extern SpinDirTable gSpinDirTable;
extern MmdlStepProc gLookPlayerStepTable[];
extern MmdlStepProc gLookFellowStepTable[];
extern MmdlVec gHideDrawOffsetInit;
extern MmdlStepProc gHideStepTable[];
extern MmdlVec gHideDrawOffsetRecover;
extern MmdlStepProc gFaceDirStepTable[];
extern MmdlStepProc gWallWalkStepTable[];
extern int gWallCheckOffsetAX[][2];
extern int gWallCheckOffsetAZ[][2];
extern int gWallCheckOffsetBX[][2];
extern int gWallCheckOffsetBZ[][2];
extern int gWallWalkRedirectDir[][2];
extern u32 gWallWalkHandSwap[];
extern u32 gWallWalkBounceDir[][2];

/* Init of the turn-in-place move codes: kind selects the direction set. */
int FLDMMDL_MOVECODE_InitTurnRandom(Mmdl *mmdl, u32 kind)
{
    MmdlTurnRandomWork *work;
    int workSize = 8;
    work = FLDMMDL_InitMoveProcWork(mmdl, 8);
    work->waitFrames = FLDMMDL_MOVECODE_GetRandomTableEntry(gMmdlRandomWaitFrames, workSize - 9);
    work->dirSetId = kind;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    return FLDMMDL_OffMoveBitMove(mmdl);
}

int FLDMMDL_MOVECODE_InitTurnRandomSet0(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 0); }

int FLDMMDL_MOVECODE_InitTurnRandomSet1(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 1); }

int FLDMMDL_MOVECODE_InitTurnRandomSet2(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 2); }

int FLDMMDL_MOVECODE_InitTurnRandomSet3(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 3); }

int FLDMMDL_MOVECODE_InitTurnRandomSet4(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 4); }

int FLDMMDL_MOVECODE_InitTurnRandomSet5(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 5); }

int FLDMMDL_MOVECODE_InitTurnRandomSet6(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 6); }

int FLDMMDL_MOVECODE_InitTurnRandomSet7(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 7); }

int FLDMMDL_MOVECODE_InitTurnRandomSet8(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 8); }

int FLDMMDL_MOVECODE_InitTurnRandomSet9(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 9); }

int FLDMMDL_MOVECODE_InitTurnRandomSet10(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitTurnRandom(mmdl, 10); }

void FLDMMDL_MOVECODE_MoveTurnRandom(Mmdl *mmdl)
{
    MmdlTurnRandomWork *work;
    u32 dir;
    u16 curDir;
    u16 nextDir;
    work = FLDMMDL_GetMoveProcWork(mmdl);
    if (FLDMMDL_GetEventType(mmdl) == 11) {
        if (FLDMMDL_MOVE_IsNearPlayer(mmdl) == 1 && FLDMMDL_MOVECODE_IsBButtonPressed() == 1) {
            curDir = FLDMMDL_GetDirDisp(mmdl);
            nextDir = FLDMMDL_MOVECODE_GetNextDirInRotation(FLDMMDL_GetMoveCode(mmdl), curDir);
            if (nextDir != 9)
                FLDMMDL_SetDirDispCheckPause(mmdl, (u16)nextDir);
        }
    } else {
        dir = FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(mmdl, work->dirSetId, 9);
        if (dir != 9) {
            FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
        } else if (work->suspended == 0) {
            work->waitFrames = work->waitFrames - 1;
            if (work->waitFrames <= 0) {
                work->waitFrames = FLDMMDL_MOVECODE_GetRandomTableEntry(gMmdlRandomWaitFrames, -1);
                dir = FLDMMDL_MOVECODE_GetRandomDirFromSet(work->dirSetId, 9);
                FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
            }
        }
    }
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
}

static inline u16 GetNextDirInRow(u16 *row, u16 dir)
{
    int i;
    u16 *p;

    for (i = 1, p = row; p[i] != 9; i++) {
        if (dir == p[i]) {
            i++;
            if (p[i] == 9) i = 1;
            return p[i];
        }
    }
    return 9;
}

/*
 * Row lookup: find the 6-halfword record whose key (the model's move code)
 * matches, then return the entry after dir in its 9-terminated list (wrapping
 * to entry 1). The row is an inline argument formed through a (u8 *) byte
 * offset, so the add stays after the key compare; the helper's
 * `for (i = 1, p = row; ...)` local copy of the row gives the image's colours
 * (row r0, index r3, dir copied to r4).
 */
u16 FLDMMDL_MOVECODE_GetNextDirInRotation(u16 moveCode, u16 dir)
{
    int i = 0;

    do {
        if (moveCode == gMmdlRotationDirRows[i][0]) {
            return GetNextDirInRow((u16 *)((u8 *)gMmdlRotationDirRows + i * 12), dir);
        }
        i++;
    } while (gMmdlRotationDirRows[i][0] != 0xFF);
    return 9;
}

/*
 * Empty callback: its address 0x0219A24D is stored in ov021 data at 0x021D5738.
 */
void FLDMMDL_MOVECODE_NoOp(void)
{
}

void FLDMMDL_MOVECODE_InitWalkRandomSet11(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitWalkRandom(mmdl, 0xc, 0xb, 0x0);
}

void FLDMMDL_MOVECODE_InitWalkRandomSet12(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitWalkRandom(mmdl, 0xc, 0xc, 0x0);
}

void FLDMMDL_MOVECODE_InitWalkRandomSet13(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitWalkRandom(mmdl, 0xc, 0xd, 0x0);
}

void FLDMMDL_MOVECODE_InitWalkRandomSet13Bump(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitWalkRandom(mmdl, 0xc, 0xd, 0x2);
}

void FLDMMDL_MOVECODE_InitWalkRandom(Mmdl *mmdl, u32 acmdSpeed, u32 dirSetId, u32 limitMode)
{
    MmdlWalkRandomWork *work = FLDMMDL_InitMoveProcWork(mmdl, 16);
    work->limitMode = limitMode;
    work->acmdSpeed = acmdSpeed;
    work->dirSetId = dirSetId;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
}

void FLDMMDL_MOVECODE_MoveWalkRandom(Mmdl *mmdl)
{
    MmdlWalkRandomWork *work;
    u32 dir;
    int hit;

    work = FLDMMDL_GetMoveProcWork(mmdl);
    switch (work->state) {
    case 0:
        FLDMMDL_OffMoveBitMove(mmdl);
        FLDMMDL_OffMoveBitMoveEnd(mmdl);
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)((u32)FLDMMDL_GetDirDisp(mmdl)), (u16)0)));
        work->state++;
        break;
    case 1:
        if (FLDMMDL_ACMD_Update(mmdl) == 0)
            break;
        work->waitFrames = FLDMMDL_MOVECODE_GetRandomTableEntry(gMmdlRandomWaitFrames, -1);
        work->state++;
    case 2:
        work->waitFrames--;
        if (work->waitFrames != 0)
            break;
        work->state++;
    case 3:
        dir = FLDMMDL_MOVECODE_GetRandomDirFromSet(work->dirSetId, 9);
        FLDMMDL_SetDirAll(mmdl, dir);
        if (work->limitMode == 1 && FLDMMDL_MOVECODE_IsDirInsideMoveRect(mmdl, dir) == 0) {
            work->state = 0;
            return;
        }
        hit = FLDMMDL_MOVE_HitCheckMoveDir(mmdl, dir);
        if (hit != 0) {
            if (work->limitMode == 2) {
                if (hit & 1) {
                    work->state = 0;
                    return;
                }
            } else {
                work->state = 0;
                return;
            }
        }
        FLDMMDL_SetLocalAcmd(mmdl, (u16)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)work->acmdSpeed));
        FLDMMDL_OnMoveBitMove(mmdl);
        work->state++;
    case 4:
        if (FLDMMDL_ACMD_Update(mmdl) != 0) {
            FLDMMDL_OffMoveBitMove(mmdl);
            work->state = 0;
        }
        break;
    }
}

/*
 * The move code selects which side of the model the rectangle covers
 * (codes 6 to 13). Store order in each arm is left, right, top, bottom (x
 * pair, then y pair); the field order left, top, right, bottom puts stores to
 * +0/+8 first.
 */
void FLDMMDL_MOVECODE_GetMoveRect(Mmdl *mmdl, MmdlMoveRect *rect)
{
    int x;
    int y;
    int w;
    int h;

    x = FLDMMDL_GetGridInitX(mmdl);
    y = FLDMMDL_GetGridInitZ(mmdl);
    w = FLDMMDL_GetMoveLimitX(mmdl);
    h = FLDMMDL_GetMoveLimitZ(mmdl);
    switch (FLDMMDL_GetMoveCode(mmdl)) {
    case 6:
        rect->left = x - w;
        rect->right = x;
        rect->top = y - h;
        rect->bottom = y;
        break;
    case 7:
        rect->left = x;
        rect->right = x + w;
        rect->top = y - h;
        rect->bottom = y;
        break;
    case 8:
        rect->left = x - w;
        rect->right = x;
        rect->top = y;
        rect->bottom = y + h;
        break;
    case 9:
        rect->left = x;
        rect->right = x + w;
        rect->top = y;
        rect->bottom = y + h;
        break;
    case 10:
        rect->left = x - w;
        rect->right = x;
        rect->top = y - h;
        rect->bottom = y + h;
        break;
    case 11:
        rect->left = x;
        rect->right = x + w;
        rect->top = y - h;
        rect->bottom = y + h;
        break;
    case 12:
        rect->left = x - w;
        rect->right = x + w;
        rect->top = y - h;
        rect->bottom = y;
        break;
    case 13:
        rect->left = x - w;
        rect->right = x + w;
        rect->top = y;
        rect->bottom = y + h;
        break;
    }
}

/* Returns 1 when the cell one step in dir stays inside the move rectangle. */
int FLDMMDL_MOVECODE_IsDirInsideMoveRect(Mmdl *mmdl, u32 dir)
{
    int r[4];
    int x;
    int y;
    FLDMMDL_MOVECODE_GetMoveRect(mmdl, (MmdlMoveRect *)r);
    x = FLDMMDL_GetGridNowX(mmdl) + FLDMMDL_MOVE_GetDirAddGridX((u16)dir);
    y = FLDMMDL_GetGridNowZ(mmdl) + FLDMMDL_MOVE_GetDirAddGridZ(dir);
    if (r[0] > x || r[2] < x)
        return 0;
    if (r[1] > y || r[3] < y)
        return 0;
    return 1;
}

int FLDMMDL_MOVECODE_InitFixedDir(Mmdl *mmdl, u32 dir)
{
    MmdlFixedDirWork *work = FLDMMDL_InitMoveProcWork(mmdl, 8);
    work->dir = dir;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
    return FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
}

void FLDMMDL_MOVECODE_MoveFixedDir(Mmdl *mmdl)
{
    MmdlFixedDirWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    switch (work->state) {
    case 0:
        FLDMMDL_SetDirDispCheckPause(mmdl, (unsigned short)work->dir);
        work->state = work->state + 1;
        break;
    case 1:
        break;
    }
}

int FLDMMDL_MOVECODE_InitFixedDirUp(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitFixedDir(mmdl, 0); }

int FLDMMDL_MOVECODE_InitFixedDirDown(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitFixedDir(mmdl, 1); }

int FLDMMDL_MOVECODE_InitFixedDirLeft(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitFixedDir(mmdl, 2); }

int FLDMMDL_MOVECODE_InitFixedDirRight(Mmdl *mmdl) { return FLDMMDL_MOVECODE_InitFixedDir(mmdl, 3); }

void FLDMMDL_MOVECODE_InitSpin(Mmdl *mmdl, u8 rotation)
{
    MmdlSpinWork *work = FLDMMDL_InitMoveProcWork(mmdl, 8);
    work->rotation = rotation;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
}

void FLDMMDL_MOVECODE_InitSpinLeft(Mmdl *mmdl) { FLDMMDL_MOVECODE_InitSpin(mmdl, 2); }

void FLDMMDL_MOVECODE_InitSpinRight(Mmdl *mmdl) { FLDMMDL_MOVECODE_InitSpin(mmdl, 3); }

void FLDMMDL_MOVECODE_MoveSpin(Mmdl *mmdl)
{
    MmdlSpinWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    while (gMmdlSpinSteps[(s8)work->step](mmdl, work) == 1) {
    }
}

/* Spin step: turn toward the player, else keep the display direction. */
int FLDMMDL_MOVECODE_SpinStepTurn(Mmdl *mmdl, MmdlSpinWork *work)
{
    u32 dir = FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(mmdl, 0x26, 9);
    if (dir == 9) {
        dir = FLDMMDL_GetDirDisp(mmdl);
    }
    FLDMMDL_SetLocalAcmd(mmdl, (u16)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)0));
    work->step = 1;
    return 1;
}

/* Spin step: wait for the turn to end. */
int FLDMMDL_MOVECODE_SpinStepWaitTurn(Mmdl *mmdl, MmdlSpinWork *work)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 0) {
        return 0;
    }
    if (FLDMMDL_GetEventType(mmdl) != 11) {
        work->waitCount = 0;
    }
    work->step = 2;
    return 1;
}

/* Spin step: wait a number of frames, or for the player's button press (event type 11). */
int FLDMMDL_MOVECODE_SpinStepWaitInterval(Mmdl *mmdl, MmdlSpinWork *work)
{
    if (FLDMMDL_GetEventType(mmdl) == 11) {
        if (work->waitCount != 0) {
            work->waitCount = 0;
            return 0;
        }
        if (FLDMMDL_MOVE_IsNearPlayer(mmdl) == 0)
            return 0;
        if (FLDMMDL_MOVECODE_IsBButtonPressed() == 0)
            return 0;
        work->waitCount = work->waitCount + 1;
    } else {
        if (work->waitCount != 0) {
            if (FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(mmdl, 0x26, 9) != 9) {
                work->step = 0;
                return 1;
            }
        }
        work->waitCount = work->waitCount + 1;
        if (work->waitCount < 0x18)
            return 0;
    }
    work->step = 3;
    return 1;
}

/* Spin step: turn to the next direction of the cycle for the rotation. */
int FLDMMDL_MOVECODE_SpinStepRotateDir(Mmdl *mmdl, MmdlSpinWork *work)
{
    MmdlDirCycle left = gMmdlSpinDirsLeft;
    MmdlDirCycle right = gMmdlSpinDirsRight;
    int *cycle;
    int i;
    int cur;
    cycle = left.dirs;
    if (work->rotation != 2)
        cycle = right.dirs;
    cur = FLDMMDL_GetDirDisp(mmdl);
    i = 0;
    if (cycle[0] != 9) {
        do {
            if (cur == cycle[i])
                break;
            i++;
        } while (cycle[i] != 9);
    }
    i++;
    if (cycle[i] == 9)
        i = 0;
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)cycle[i]);
    work->step = 0;
    return 1;
}

void FLDMMDL_MOVECODE_InitSwing(Mmdl *mmdl) { FLDMMDL_MOVECODE_InitSpin(mmdl, 3); }

void FLDMMDL_MOVECODE_MoveSwing(Mmdl *mmdl)
{
    MmdlSpinWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    while (gMmdlSwingSteps[(s8)work->step](mmdl, work) == 1) {
    }
}

/* Swing step: turn toward the display direction (the turn acmd with speed 0). */
int FLDMMDL_MOVECODE_SwingStepTurn(Mmdl *mmdl, MmdlSpinWork *work)
{
    FLDMMDL_SetLocalAcmd(mmdl, (((u32)FLDMMDL_ACMD_ConvertCodeByDir((u32)(((u32)FLDMMDL_GetDirDisp(mmdl) << 16) >> 16), (u32)0) << 16) >> 16));
    work->step = 1;
    return 1;
}

/* Swing step: wait for the turn to end. */
int FLDMMDL_MOVECODE_SwingStepWaitTurn(Mmdl *mmdl, MmdlSpinWork *work)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 0) {
        return 0;
    }
    work->waitCount = 0;
    work->step = 2;
    return 1;
}

/* Swing step: wait 0x18 frames. */
int FLDMMDL_MOVECODE_SwingStepWaitInterval(Mmdl *mmdl, MmdlSpinWork *work)
{
    int count = work->waitCount + 1;
    work->waitCount = count;
    if (count < 0x18)
        return 0;
    work->step = 3;
    return 1;
}

/* Swing step: turn to the next direction; at the header direction reverse the rotation. */
int FLDMMDL_MOVECODE_SwingStepRotateDir(Mmdl *mmdl, MmdlSpinWork *work)
{
    MmdlDirCycle left = gMmdlSwingDirsLeft;
    MmdlDirCycle right = gMmdlSwingDirsRight;
    int *cycle;
    int i;
    int cur;
    cycle = left.dirs;
    if (work->rotation != 2)
        cycle = right.dirs;
    cur = FLDMMDL_GetDirDisp(mmdl);
    i = 0;
    if (cycle[0] != 9) {
        do {
            if (cur == cycle[i])
                break;
            i++;
        } while (cycle[i] != 9);
    }
    i++;
    if (cycle[i] == 9)
        i = 0;
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)cycle[i]);
    if (FLDMMDL_GetDirDisp(mmdl) == FLDMMDL_GetDirHeader(mmdl))
        work->rotation = FLDMMDL_MOVE_GetDirTableValue(work->rotation);
    work->step = 0;
    return 1;
}

void FLDMMDL_MOVECODE_InitBackForth(Mmdl *mmdl)
{
    MmdlBackForthWork *work = FLDMMDL_InitMoveProcWork(mmdl, 8);
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
        FLDMMDL_MOVECODE_InitMirrorSide(mmdl, &work->mirror);
    }
}

void FLDMMDL_MOVECODE_MoveBackForth(Mmdl *mmdl)
{
    MmdlBackForthWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    while (gMmdlBackForthSteps[work->step](mmdl, work) == 1) {
    }
}

/* Back and forth step: pick the direction (header direction, or its reverse) and face it. */
int FLDMMDL_MOVECODE_BackForthStepFaceDir(Mmdl *mmdl, MmdlBackForthWork *work)
{
    u32 cur = FLDMMDL_GetDirHeader(mmdl);
    if (work->reversed == 1)
        cur = FLDMMDL_MOVE_GetDirTableValue((u16)cur);
    FLDMMDL_SetDirMove(mmdl, cur);
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 0)
        FLDMMDL_SetDirDispCheckPause(mmdl, (u16)cur);
    work->step = 1;
    return 1;
}

/* Back and forth step: walk one cell, reversing at an obstacle or when back at the start. */
int FLDMMDL_MOVECODE_BackForthStepWalk(Mmdl *mmdl, MmdlBackForthWork *work)
{
    int x;
    int y;
    int tx;
    int ty;
    u32 dir;
    u32 moveDir;
    int hit;
    u32 speed;

    if (FLDMMDL_MOVECODE_UpdateTriggerWait(mmdl, &work->triggerCount) == 0)
        return 0;
    if (work->reversed != 0) {
        x = FLDMMDL_GetGridInitX(mmdl);
        y = FLDMMDL_GetGridInitZ(mmdl);
        tx = FLDMMDL_GetGridNowX(mmdl);
        ty = FLDMMDL_GetGridNowZ(mmdl);
        if (x == tx && y == ty) {
            dir = FLDMMDL_MOVE_GetDirTableValue((u16)FLDMMDL_GetDirMove(mmdl));
            FLDMMDL_SetDirMove(mmdl, dir);
            if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 0)
                FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
            work->reversed = 0;
        }
    }
    moveDir = FLDMMDL_GetDirMove(mmdl);
    hit = FLDMMDL_MOVE_HitCheckMoveDir(mmdl, moveDir);
    if (hit & 1) {
        work->reversed = 1;
        moveDir = FLDMMDL_MOVE_GetDirTableValue((u16)moveDir);
        hit = FLDMMDL_MOVE_HitCheckMoveDir(mmdl, moveDir);
    }
    speed = 12;
    if (FLDMMDL_MOVECODE_IsDashEventType(mmdl) != 0 && FLDMMDL_MOVECODE_IsBButtonHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer(mmdl) == 1)
        speed = 16;
    if (hit != 0)
        speed = 32;
    FLDMMDL_SetLocalAcmd(mmdl, (u16)FLDMMDL_ACMD_ConvertCodeByDir((u16)moveDir, (u16)speed));
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1)
        FLDMMDL_MOVECODE_StartMirrorTurn(mmdl, &work->mirror);
    FLDMMDL_OnMoveBitMove(mmdl);
    work->step = 2;
    return 1;
}

/* Back and forth step: wait for the walk to end. */
int FLDMMDL_MOVECODE_BackForthStepWaitWalk(Mmdl *mmdl, MmdlBackForthWork *work)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 1) {
        FLDMMDL_OffMoveBitMove(mmdl);
        if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
            FLDMMDL_MOVECODE_EndMirrorTurn(mmdl, &work->mirror);
        }
        work->step = 0;
    }
    return 0;
}

/* Init of the route patrol move codes: axis picks the compared coordinate, routeId the route. */
void FLDMMDL_MOVECODE_InitRoutePatrol(Mmdl *mmdl, u32 axisCheckIndex, u32 axis, u32 routeId)
{
    MmdlRoutePatrolWork *work = FLDMMDL_InitMoveProcWork(mmdl, 12);
    work->axisCheckIndex = axisCheckIndex;
    work->axis = axis;
    work->routeId = routeId;
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
        FLDMMDL_MOVECODE_InitMirrorSide(mmdl, &work->mirror);
    }
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute0E(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0xe);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute0F(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0xf);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute10(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x10);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute11(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x11);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute12(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0x12);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute13(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0x13);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute14(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x14);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute15(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x15);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute16(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x16);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute17(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x17);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute18(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0x18);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute19(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0x19);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute1A(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x1a);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute1B(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x1, 0x1b);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute1C(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0x1c);
}

void FLDMMDL_MOVECODE_InitRoutePatrolRoute1D(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrol(mmdl, 0x2, 0x0, 0x1d);
}

void FLDMMDL_MOVECODE_MoveRoutePatrol(Mmdl *mmdl)
{
    MmdlRoutePatrolWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    while (gMmdlRoutePatrolSteps[work->step](mmdl, work) == 1) {
    }
}

/* Route patrol step: walk to the next cell of the route (turn at the corner, reverse at an obstacle). */
int FLDMMDL_MOVECODE_RoutePatrolStepWalk(Mmdl *mmdl, MmdlRoutePatrolWork *work)
{
    u32 *route;
    u32 dir;
    int x0;
    int y0;
    int x1;
    int y1;
    int hit;
    int speed;

    if (FLDMMDL_MOVECODE_UpdateTriggerWait(mmdl, &work->triggerCount) == 0) {
        return 0;
    }
    if (work->routeIndex == work->axisCheckIndex) {
        if (work->axis == 0) {
            x0 = FLDMMDL_GetGridInitX(mmdl);
            if (x0 == FLDMMDL_GetGridNowX(mmdl)) {
                work->routeIndex++;
            }
        } else {
            x0 = FLDMMDL_GetGridInitZ(mmdl);
            if (x0 == FLDMMDL_GetGridNowZ(mmdl)) {
                work->routeIndex++;
            }
        }
    }
    if (work->routeIndex == 3) {
        x0 = FLDMMDL_GetGridInitX(mmdl);
        y0 = FLDMMDL_GetGridInitZ(mmdl);
        x1 = FLDMMDL_GetGridNowX(mmdl);
        y1 = FLDMMDL_GetGridNowZ(mmdl);
        if (x0 == x1 && y0 == y1) {
            work->routeIndex = 0;
        }
    }
    route = FLDMMDL_MOVECODE_GetDirSet(work->routeId);
    dir = route[work->routeIndex];
    FLDMMDL_SetDirMove(mmdl, (u16)dir);
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 0) {
        FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
    }
    hit = FLDMMDL_MOVE_HitCheckMoveDir(mmdl, (u16)dir);
    if (hit & 1) {
        work->routeIndex++;
        dir = route[work->routeIndex];
        FLDMMDL_SetDirMove(mmdl, (u16)dir);
        if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 0) {
            FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
        }
        hit = FLDMMDL_MOVE_HitCheckMoveDir(mmdl, (u16)dir);
    }
    speed = 12;
    if (FLDMMDL_MOVECODE_IsDashEventType(mmdl) != 0 && FLDMMDL_MOVECODE_IsBButtonHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer(mmdl) == 1) {
        speed = 16;
    }
    if (hit != 0) {
        speed = 32;
    }
    FLDMMDL_SetLocalAcmd(mmdl, (u16)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)speed));
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
        FLDMMDL_MOVECODE_StartMirrorTurn(mmdl, &work->mirror);
    }
    FLDMMDL_OnMoveBitMove(mmdl);
    work->step = 1;
    return 1;
}

/* Route patrol step: wait for the walk to end. */
int FLDMMDL_MOVECODE_RoutePatrolStepWaitWalk(Mmdl *mmdl, MmdlRoutePatrolWork *work)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 1) {
        FLDMMDL_OffMoveBitMove(mmdl);
        if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
            FLDMMDL_MOVECODE_EndMirrorTurn(mmdl, &work->mirror);
        }
        work->step = 0;
    }
    return 0;
}

/* Init of the swapping route patrol move codes; same arguments as the plain route patrol. */
void FLDMMDL_MOVECODE_InitRoutePatrolSwap(Mmdl *mmdl, u32 axisCheckIndex, u32 axis, u32 routeId)
{
    MmdlRoutePatrolSwapWork *work = FLDMMDL_InitMoveProcWork(mmdl, 12);
    work->axisCheckIndex = axisCheckIndex;
    work->axis = axis;
    work->routeId = routeId;
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
        FLDMMDL_MOVECODE_InitMirrorSide(mmdl, &work->mirror);
    }
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute1E(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x1, 0x1e);
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute1F(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x1, 0x1f);
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute20(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x0, 0x20);
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute21(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x0, 0x21);
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute22(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x1, 0x22);
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute23(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x1, 0x23);
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute24(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x0, 0x24);
}

void FLDMMDL_MOVECODE_InitRoutePatrolSwapRoute25(Mmdl *mmdl)
{
    FLDMMDL_MOVECODE_InitRoutePatrolSwap(mmdl, 0x2, 0x0, 0x25);
}

void FLDMMDL_MOVECODE_MoveRoutePatrolSwap(Mmdl *mmdl)
{
    MmdlRoutePatrolSwapWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    while (gMmdlRoutePatrolSwapSteps[work->step](mmdl, work) == 1) {
    }
}

/* Moves the route index one cell on, backwards when reverseRoute is set. */
void FLDMMDL_MOVECODE_AdvanceRouteIndex(MmdlRoutePatrolSwapWork *work)
{
    if (work->reverseRoute == 1) {
        work->routeIndex--;
        if (work->routeIndex < 0) {
            work->routeIndex = 3;
        }
    } else {
        work->routeIndex++;
    }
}

/* Swap patrol step: when the player is in sight (event type 10), turn toward it. */
int FLDMMDL_MOVECODE_RoutePatrolSwapStepLookForPlayer(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    u32 dir;
    if (FLDMMDL_GetEventType(mmdl) == 10) {
        dir = FLDMMDL_GetDirDisp(mmdl);
        if (EVENT_TRAINER_EYE_GetPlayerDistance(mmdl, dir, FLDMMDL_GetParam(mmdl, 0), 0) != -1) {
            FLDMMDL_SetLocalAcmd(mmdl, FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x30));
            FLDMMDL_OnMoveBitMove(mmdl);
            work->step = 1;
            return 1;
        }
    }
    work->step = 2;
    return 1;
}

/* Swap patrol step: after the turn, change to the mirrored move code and flip the route index. */
int FLDMMDL_MOVECODE_RoutePatrolSwapStepSwapMoveCode(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    u16 *pair;
    u32 code;
    u32 other;
    u32 moveCode;
    int flipped;

    if (FLDMMDL_ACMD_Update(mmdl) == 1) {
        other = 0xff;
        moveCode = FLDMMDL_GetMoveCode(mmdl);
        pair = gMmdlSwapMoveCodePairs;
        code = 0x25;
        do {
            if (code == moveCode) {
                other = pair[1];
            } else if (pair[1] == moveCode) {
                other = code;
            }
            if (other != 0xff) {
                flipped = 4 - (work->routeIndex + 1);
                FLDMMDL_ChangeMoveCode(mmdl, other);
                work->routeIndex = flipped;
                break;
            }
            pair += 2;
            code = pair[0];
        } while (code != 0xff);
        FLDMMDL_OffMoveBitMove(mmdl);
        work->step = 2;
    }
    return 0;
}

/*
 * Twin of FLDMMDL_MOVECODE_RoutePatrolStepWalk (same shape; the route index is signed and advanced
 * through FLDMMDL_MOVECODE_AdvanceRouteIndex).
 */
int FLDMMDL_MOVECODE_RoutePatrolSwapStepWalk(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    u32 *route;
    u32 dir;
    int x0;
    int y0;
    int x1;
    int y1;
    int hit;
    int speed;

    if (FLDMMDL_MOVECODE_UpdateTriggerWait(mmdl, &work->triggerCount) == 0) {
        return 0;
    }
    if (work->routeIndex == work->axisCheckIndex) {
        if (work->axis == 0) {
            x0 = FLDMMDL_GetGridInitX(mmdl);
            if (x0 == FLDMMDL_GetGridNowX(mmdl)) {
                FLDMMDL_MOVECODE_AdvanceRouteIndex(work);
            }
        } else {
            x0 = FLDMMDL_GetGridInitZ(mmdl);
            if (x0 == FLDMMDL_GetGridNowZ(mmdl)) {
                FLDMMDL_MOVECODE_AdvanceRouteIndex(work);
            }
        }
    }
    if (work->routeIndex == 3) {
        x0 = FLDMMDL_GetGridInitX(mmdl);
        y0 = FLDMMDL_GetGridInitZ(mmdl);
        x1 = FLDMMDL_GetGridNowX(mmdl);
        y1 = FLDMMDL_GetGridNowZ(mmdl);
        if (x0 == x1 && y0 == y1) {
            work->routeIndex = 0;
        }
    }
    route = FLDMMDL_MOVECODE_GetDirSet(work->routeId);
    dir = route[work->routeIndex];
    FLDMMDL_SetDirMove(mmdl, (u16)dir);
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 0) {
        FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
    }
    hit = FLDMMDL_MOVE_HitCheckMoveDir(mmdl, (u16)dir);
    if (1 & hit) {
        FLDMMDL_MOVECODE_AdvanceRouteIndex(work);
        dir = route[work->routeIndex];
        FLDMMDL_SetDirMove(mmdl, (u16)dir);
        if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 0) {
            FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
        }
        hit = FLDMMDL_MOVE_HitCheckMoveDir(mmdl, (u16)dir);
    }
    speed = 12;
    if (FLDMMDL_MOVECODE_IsDashEventType(mmdl) != 0 && FLDMMDL_MOVECODE_IsBButtonHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer(mmdl) == 1) {
        speed = 16;
    }
    if (hit != 0) {
        speed = 32;
    }
    FLDMMDL_SetLocalAcmd(mmdl, (u16)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)speed));
    if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
        FLDMMDL_MOVECODE_StartMirrorTurn(mmdl, &work->mirror);
    }
    FLDMMDL_OnMoveBitMove(mmdl);
    work->step = 3;
    return 1;
}

/* Swap patrol step: wait for the walk to end. */
int FLDMMDL_MOVECODE_RoutePatrolSwapStepWaitWalk(Mmdl *mmdl, MmdlRoutePatrolSwapWork *work)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 1) {
        FLDMMDL_OffMoveBitMove(mmdl);
        if (FLDMMDL_MOVECODE_IsMirrorEventType(mmdl) == 1) {
            FLDMMDL_MOVECODE_EndMirrorTurn(mmdl, &work->mirror);
        }
        work->step = 0;
    }
    return 0;
}

/* Returns 1 while the B button is held. */
int FLDMMDL_MOVECODE_IsBButtonHeld(void)
{
    if (KEY_GetCont() & 2) {
        return 1;
    }
    return 0;
}

/* Returns 1 when the player model runs one of the walk acmds. */
int FLDMMDL_MOVECODE_IsPlayerWalking(Mmdl *mmdl)
{
    Mmdl *player;

    player = FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys(mmdl));
    if (player != 0) {
        switch (FLDMMDL_GetAcmdCode(player)) {
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0xa3:
        case 0xa4:
        case 0xa5:
        case 0xa6:
            return 1;
        }
    }
    return 0;
}

/* Returns 1 on the frame the B button goes down. */
int FLDMMDL_MOVECODE_IsBButtonPressed(void)
{
    if (KEY_GetTrg() & 2) {
        return 1;
    }
    return 0;
}

/* Index of endMark in the table. */
int FLDMMDL_MOVECODE_FindTableEnd(u32 *table, u32 endMark)
{
    int i;
    for (i = 0; endMark != table[i]; i++) {
    }
    return i;
}

/* Random entry of a table ended by endMark. */
int FLDMMDL_MOVECODE_GetRandomTableEntry(u32 *table, u32 endMark)
{
    return table[GFL_USE_GetRandom(FLDMMDL_MOVECODE_FindTableEnd(table, endMark))];
}

/* Random direction of the direction set. */
u32 FLDMMDL_MOVECODE_GetRandomDirFromSet(u32 setId, u32 endMark)
{
    u32 *dirs = FLDMMDL_MOVECODE_GetDirSet(setId);
    return dirs[GFL_USE_GetRandom(FLDMMDL_MOVECODE_FindTableEnd(dirs, endMark))];
}

/*
 * The first key is the literal 0 held in a local (row 0 of the table has
 * key 0), then the walk reloads it at the loop bottom.
 */
u32 *FLDMMDL_MOVECODE_GetDirSet(u32 setId)
{
    MmdlDirSetEntry *entry = gMmdlDirSets;
    u32 key = 0;
    do {
        if (key == setId) {
            return entry->dirs;
        }
        entry++;
        key = entry->id;
    } while (key != 0x27);
    return 0;
}

/*
 * For a trainer-type model (event type 1 or 2) whose move code is in the
 * sight list, returns the direction to the player when the player walks in
 * the same height inside the sight range, else 9.
 */
int FLDMMDL_MOVECODE_GetSightDirToPlayer(Mmdl *mmdl)
{
    int eventType;
    u32 moveCode;
    u32 listed;
    int i;
    Mmdl *player;
    int playerX, playerZ, x, z, range;
    int minX, maxX, minZ, maxZ;

    eventType = FLDMMDL_GetEventType(mmdl);
    if (eventType != 1 && eventType != 2) {
        return 9;
    }
    if (FLDMMDL_MOVECODE_IsPlayerWalking(mmdl) == 0) {
        return 9;
    }
    i = 0;
    moveCode = FLDMMDL_GetMoveCode(mmdl);
    do {
        listed = gMmdlSightMoveCodes[i++];
    } while (listed != moveCode && listed != 0xFF);
    if (moveCode != listed) {
        return 9;
    }
    player = FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys(mmdl));
    if (player == 0) {
        return 9;
    }
    if (FLDMMDL_GetGridNowY(player) != FLDMMDL_GetGridNowY(mmdl)) {
        return 9;
    }
    playerX = FLDMMDL_GetGridNowX(player);
    playerZ = FLDMMDL_GetGridNowZ(player);
    range = FLDMMDL_GetParam(mmdl, 0);
    x = FLDMMDL_GetGridNowX(mmdl);
    z = FLDMMDL_GetGridNowZ(mmdl);
    minX = x - range;
    maxX = x + range;
    minZ = z - range;
    maxZ = z + range;
    if (minZ <= playerZ && maxZ >= playerZ && minX <= playerX && maxX >= playerX) {
        return FLDMMDL_MOVE_GetDirFromPoints(x, z, playerX, playerZ);
    }
    return 9;
}

/*
 * Picks a direction of the set that leads toward the player (the sight
 * direction if it is in the set, else a direction closing the x or z
 * distance); returns endMark's value 9 when none does.
 */
int FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(Mmdl *mmdl, int setId, int endMark)
{
    int *dirs;
    int count;
    int sightDir;
    int i;
    Mmdl *player;
    int x;
    int z;
    int playerX;
    int playerZ;
    int dirX;
    int dirZ;

    dirs = (int *)FLDMMDL_MOVECODE_GetDirSet(setId);
    count = FLDMMDL_MOVECODE_FindTableEnd((unsigned int *)dirs, endMark);
    if (count == 1) {
        return 9;
    }
    sightDir = FLDMMDL_MOVECODE_GetSightDirToPlayer(mmdl);
    if (sightDir != 9) {
        i = 0;
        do {
            if (sightDir == dirs[i]) {
                return sightDir;
            }
            i++;
        } while (i < count);
        player = FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys(mmdl));
        dirX = 9;
        dirZ = 9;
        x = FLDMMDL_GetGridNowX(mmdl);
        z = FLDMMDL_GetGridNowZ(mmdl);
        playerX = FLDMMDL_GetGridNowX(player);
        playerZ = FLDMMDL_GetGridNowZ(player);
        if (x > playerX) {
            dirX = 2;
        } else if (x < playerX) {
            dirX = 3;
        }
        if (z > playerZ) {
            dirZ = 0;
        } else if (z < playerZ) {
            dirZ = 1;
        }
        i = 0;
        if (dirX == 9) {
            do {
                if (dirZ == dirs[i]) {
                    return dirZ;
                }
                i++;
            } while (i < count);
        } else if (dirZ == 9) {
            do {
                if (dirX == dirs[i]) {
                    return dirX;
                }
                i++;
            } while (i < count);
        } else {
            do {
                if (dirX == dirs[i]) {
                    return dirX;
                }
                if (dirZ == dirs[i]) {
                    return dirZ;
                }
                i++;
            } while (i < count);
        }
        return 9;
    }
    return sightDir;
}

/*
 * Event type 12 waits for a B button press near the player before it moves
 * on; the count then waits the number of frames given by the model's
 * parameter 1. Other event types never wait.
 */
int FLDMMDL_MOVECODE_UpdateTriggerWait(Mmdl *mmdl, u8 *triggerCount)
{
    if (FLDMMDL_GetEventType(mmdl) != 12) {
        return 1;
    }
    if (triggerCount[0] == 0) {
        if (FLDMMDL_MOVE_IsNearPlayer(mmdl) == 0) {
            return 0;
        }
        if (FLDMMDL_MOVECODE_IsBButtonPressed() == 0) {
            return 0;
        }
        triggerCount[0] = FLDMMDL_GetParam(mmdl, 1);
    }
    if (triggerCount[0] != 0) {
        triggerCount[0]--;
    }
    return 1;
}

/* Event types that dash while the B button is held and the player is near. */
int FLDMMDL_MOVECODE_IsDashEventType(Mmdl *mmdl)
{
    u32 eventType = FLDMMDL_GetEventType(mmdl);
    if (eventType == 13 || (u16)(eventType + 0xFFF1) <= 4) {
        return 1;
    }
    return 0;
}

/* Event types that mirror the player's turns. */
int FLDMMDL_MOVECODE_IsMirrorEventType(Mmdl *mmdl)
{
    u32 eventType = FLDMMDL_GetEventType(mmdl);
    if (eventType == 7 || eventType == 8 || eventType - 17 <= 1) {
        return 1;
    }
    return 0;
}

/* Sets the mirror side from the event type (7 and 17 mirror to the left). */
void FLDMMDL_MOVECODE_InitMirrorSide(Mmdl *mmdl, MmdlMirrorState *mirror)
{
    u32 eventType = FLDMMDL_GetEventType(mmdl);
    if (eventType == 7 || eventType == 17) {
        mirror->side = 0;
    } else {
        mirror->side = 1;
    }
}

/* Turns to the next direction of the side's cycle and pauses the display direction. */
void FLDMMDL_MOVECODE_StartMirrorTurn(Mmdl *mmdl, MmdlMirrorState *mirror)
{
    int i;
    u32 dir;
    u32 nextDir;

    dir = FLDMMDL_GetDirDisp(mmdl);
    for (i = 0; i < 4 && dir != gMmdlMirrorDirCycles[mirror->side][i]; i++) {
    }
    i++;
    mirror->savedDir = dir;
    i %= 4;
    nextDir = gMmdlMirrorDirCycles[mirror->side][i];
    if (FLDMMDL_CheckStatusBit(mmdl, 8) != 0) {
        mirror->dirWasPaused = 1;
    } else {
        mirror->dirWasPaused = 0;
    }
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)nextDir);
    FLDMMDL_SetStatusBit(mmdl, 8);
}

/* Lifts the direction pause unless it was already set before the turn. */
void FLDMMDL_MOVECODE_EndMirrorTurn(Mmdl *mmdl, MmdlMirrorState *mirror)
{
    if (mirror->dirWasPaused == 0) {
        FLDMMDL_ClearStatusBit(mmdl, 8);
    }
}

/*
 * Recursive MATCH unblocker: callee of FLDMMDL_MOVE_SetupMove (ov010) +000A.  An
 * unlabelled Thumb tail-call thunk that disasm.py emitted as a word run
 * (`ldr r3,[pc,#0]; bx r3; .word FLDMMDL_MOVECODE_InitByEventType|1`), so no func_ label exists
 * for the caller to reach through `label`/`sole-ref/code`.  Matching it here
 * gives FLDMMDL_MOVE_SetupMove's call site a `matched` witness.  Region hint ov021 is
 * required: ov009 overlaps 0x0219B414 but holds unrelated code there.
 */
int FLDMMDL_MOVECODE_InitEventTypeProcThunk(Mmdl *mmdl)
{
    return FLDMMDL_MOVECODE_InitByEventType(mmdl);
}

int FLDMMDL_MOVECODE_UpdateEventTypeProc(Mmdl *mmdl)
{
    if (FLDMMDL_MOVECODE_CheckByEventType(mmdl) == 0) {
        return 0;
    }
    if (FLDMMDL_MOVECODE_UpdateByEventType(mmdl) != 0) {
        return 1;
    }
    return 0;
}

/*
 * Recursive MATCH dependency: target of the Thumb tail-call thunk
 * FLDMMDL_MOVECODE_InitEventTypeProcThunk (ov021).  Indexes the function-pointer table at 0x021D5278 by
 * the model's event type and tail-dispatches through it.
 */
int FLDMMDL_MOVECODE_InitByEventType(Mmdl *mmdl)
{
    int eventType = FLDMMDL_GetEventType(mmdl);

    return gMmdlEventTypeInitProcs[eventType](mmdl);
}

u32 FLDMMDL_MOVECODE_CheckByEventType(Mmdl *mmdl)
{
    return gMmdlEventTypeCheckProcs[FLDMMDL_GetEventType(mmdl)](mmdl);
}

u32 FLDMMDL_MOVECODE_UpdateByEventType(Mmdl *mmdl)
{
    return gMmdlEventTypeUpdateProcs[FLDMMDL_GetEventType(mmdl)](mmdl);
}

/* Returns 1 when the model's grid cell is not its previous cell. */
int FLDMMDL_MOVECODE_HasLeftOldGrid(Mmdl *mmdl)
{
    if (FLDMMDL_GetGridNowX(mmdl) != FLDMMDL_GetGridOldX(mmdl)) {
        return 1;
    }
    if (FLDMMDL_GetGridNowZ(mmdl) != FLDMMDL_GetGridOldZ(mmdl)) {
        return 1;
    }
    return 0;
}

/* Returns 1 when the model's grid cell is its previous cell. */
int FLDMMDL_MOVECODE_IsAtOldGrid(Mmdl *mmdl)
{
    if (FLDMMDL_GetGridNowX(mmdl) != FLDMMDL_GetGridOldX(mmdl)) {
        return 0;
    }
    if (FLDMMDL_GetGridNowZ(mmdl) == FLDMMDL_GetGridOldZ(mmdl)) {
        return 1;
    }
    return 0;
}

void FLDMMDL_MOVECODE_NoOpHook(void)
{
}

int FLDMMDL_MOVECODE_ReturnFalseA(void)
{
    return 0;
}

int FLDMMDL_MOVECODE_ReturnFalseB(void)
{
    return 0;
}

/* Walk repeat (init). */
void FLDMMDL_MOVE_InitWalkRepeat(Mmdl *mmdl)
{
    MmdlStepRepeatWork *work = FLDMMDL_InitMoveSubProcWork(mmdl, 9);
    work->countMax = FLDMMDL_GetParam(mmdl, 1);
}

/* Walk repeat: step, count, then wait for the move to end. */
int FLDMMDL_MOVE_WalkRepeat(Mmdl *mmdl)
{
    MmdlStepRepeatWork *work;
    work = FLDMMDL_GetMoveSubProcWork((void *)mmdl);
    switch (work->state) {
    case 0:
        if (FLDMMDL_MOVECODE_HasLeftOldGrid(mmdl) == 1) {
            work->state++;
        }
        break;
    case 1:
        if (FLDMMDL_MOVECODE_IsAtOldGrid(mmdl) == 0) {
            break;
        }
        work->count++;
        if (work->count < work->countMax) {
            work->state = 0;
            break;
        }
        work->state++;
    case 2:
        if (FLDMMDL_CheckMoveBitMove((void *)mmdl) == 1) {
            break;
        }
        work->state++;
        work->count = 0;
        work->waitFlag = 0;
    case 3:
        return 1;
    }
    return 0;
}

/* Turn sub proc: look left and right, four times. */
int FLDMMDL_MOVE_TurnLookAround(Mmdl *mmdl)
{
    MmdlTurnSubWork *work;
    int frameMax;
    work = FLDMMDL_GetMoveSubProcWork((void *)mmdl);
    switch (work->state) {
    case 0: {
        DirGroupTable groupTable = gLookAroundDirGroup;
        u16 dir = FLDMMDL_GetDirDisp((void *)mmdl);
        work->startDir = dir;
        work->dirGroup = groupTable.group[dir];
        work->state++;
    }
    case 1: {
        LookAroundDirTable dirTable = gLookAroundDirTable;
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dirTable.dir[work->dirGroup][work->dirIndex], (u16)0)));
        work->state++;
    }
    case 2:
        if (FLDMMDL_ACMD_Update(mmdl) == 0) {
            return 1;
        }
        work->state++;
    case 3:
        frameMax = 8;
        if (FLDMMDL_GetEventType(mmdl) == 14 && FLDMMDL_MOVE_IsButtonBHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer(mmdl) == 1) {
            frameMax = 4;
        }
        if (++work->frameCount < frameMax) {
            return 1;
        }
        work->frameCount = 0;
        if (++work->turnCount < 4) {
            work->dirIndex = (work->dirIndex + 1) & 1;
            work->state = 1;
            return 1;
        }
        FLDMMDL_SetDirDispCheckPause(mmdl, work->startDir);
        work->state++;
        work->turnCount = 0;
        work->busy = 0;
    }
    return 0;
}

/* Walk repeat with spin (init): spin direction from the event type. */
void FLDMMDL_MOVE_InitWalkRepeatSpin(Mmdl *mmdl)
{
    MmdlTurnSubWork *work = FLDMMDL_InitMoveSubProcWork(mmdl, 9);
    u32 eventType;
    u8 spinDir = 1;
    work->repeatParam = FLDMMDL_GetParam(mmdl, 1);
    eventType = FLDMMDL_GetEventType(mmdl);
    if (eventType == 5 || eventType == 20 || eventType == 15) {
        spinDir = 0;
    }
    work->dirGroup = spinDir;
}

/* Walk repeat with spin: same steps as FLDMMDL_MOVE_WalkRepeat. */
int FLDMMDL_MOVE_WalkRepeatSpin(Mmdl *mmdl)
{
    MmdlStepRepeatWork *work;
    work = FLDMMDL_GetMoveSubProcWork((void *)mmdl);
    switch (work->state) {
    case 0:
        if (FLDMMDL_MOVECODE_HasLeftOldGrid(mmdl) == 1) {
            work->state++;
        }
        break;
    case 1:
        if (FLDMMDL_MOVECODE_IsAtOldGrid(mmdl) == 0) {
            break;
        }
        work->count++;
        if (work->count < work->countMax) {
            work->state = 0;
            break;
        }
        work->state++;
    case 2:
        if (FLDMMDL_CheckMoveBitMove((void *)mmdl) == 1) {
            break;
        }
        work->state++;
        work->count = 0;
        work->waitFlag = 0;
    case 3:
        return 1;
    }
    return 0;
}

/* Turn sub proc: spin through the four directions, clockwise or not. */
int FLDMMDL_MOVE_TurnSpin(Mmdl *mmdl)
{
    SpinDirTable spinTable = gSpinDirTable;
    MmdlTurnSubWork *work;
    int frameMax;
    int i;
    u16 dir;
    u16 eventType;
    work = FLDMMDL_GetMoveSubProcWork((void *)mmdl);
    switch (work->state) {
    case 0:
        dir = FLDMMDL_GetDirDisp((void *)mmdl);
        for (i = 0; i < 4 && dir != spinTable.dir[work->dirGroup][i]; i++) {
        }
        i++;
        work->startDir = dir;
        work->dirIndex = i % 4;
        work->state++;
    case 1:
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)spinTable.dir[work->dirGroup][work->dirIndex], (u16)0)));
        work->state++;
    case 2:
        if (FLDMMDL_ACMD_Update(mmdl) == 0) {
            return 1;
        }
        work->state++;
    case 3:
        frameMax = 8;
        eventType = FLDMMDL_GetEventType(mmdl);
        if ((eventType == 15 || eventType == 16) && FLDMMDL_MOVE_IsButtonBHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer(mmdl) == 1) {
            frameMax = 4;
        }
        if (++work->frameCount < frameMax) {
            return 1;
        }
        work->frameCount = 0;
        if (++work->turnCount < 4) {
            work->dirIndex = (work->dirIndex + 1) % 4;
            work->state = 1;
            return 1;
        }
        FLDMMDL_SetDirDispCheckPause(mmdl, work->startDir);
        work->state++;
        work->turnCount = 0;
        work->busy = 0;
    }
    return 0;
}

/* Is the B button held (speeds up the turn animations). */
int FLDMMDL_MOVE_IsButtonBHeld(void)
{
    if (KEY_GetCont() & 2) {
        return 1;
    }
    return 0;
}

/*
 * The step functions below take four arguments (mmdl, work, r2, r3) so that
 * r2 and r3 reach the init call, whose old-style declaration passes them on.
 */

/* Look at the player (init). */
int FLDMMDL_MOVE_InitLookPlayer(Mmdl *mmdl, u32 unusedWork, u32 regR2, u32 regR3)
{
    FLDMMDL_MOVE_UpdatePlayerTracking(mmdl, FLDMMDL_InitMoveProcWork(mmdl, 8, regR2, regR3));
    FLDMMDL_SetDrawStatus((void *)mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
    return FLDMMDL_SetStatusBitFellowHit(mmdl, 0);
}

/* Look at the player (move). */
void FLDMMDL_MOVE_LookPlayer(Mmdl *mmdl)
{
    MmdlLookWork *work = FLDMMDL_GetMoveProcWork((void *)mmdl);
    if (FLDMMDL_MOVE_UpdatePlayerTracking(mmdl, work)) {
        FLDMMDL_SetStatusBitFellowHit(mmdl, 0);
        while (gLookPlayerStepTable[work->step](mmdl, work) == 1) {
        }
    }
}

/* Look at the player (delete). */
void FLDMMDL_MOVE_DeleteLookPlayer(void) {}

/* Look at the player, step 0: turn when the player has moved. */
int FLDMMDL_MOVE_LookPlayerTurn(Mmdl *mmdl, MmdlLookWork *work)
{
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_OffMoveBitMoveEnd(mmdl);
    if (FLDMMDL_MOVE_HasPlayerMoved(mmdl, work) == 1) {
        FLDMMDL_MOVE_SavePlayerGridPos(mmdl, work);
        if (FLDMMDL_MOVE_TurnToPlayer(mmdl) == 1) {
            FLDMMDL_OnMoveBitMove(mmdl);
            work->step++;
            return 1;
        }
    }
    return 0;
}

/* Look at the player, step 1: wait for the turn to end. */
int FLDMMDL_MOVE_LookPlayerWaitTurn(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 1) {
        FLDMMDL_OffMoveBitMove(mmdl);
        work->step = 0;
    }
    return 0;
}

/* Is the player present; start tracking him when he appears. */
int FLDMMDL_MOVE_UpdatePlayerTracking(Mmdl *mmdl, MmdlLookWork *work)
{
    if (FLDMMDL_SysSearchPlayer((void *)FLDMMDL_GetMmdlSys((void *)mmdl)) == 0) {
        work->tracking = 0;
        return 0;
    }
    if (work->tracking == 0) {
        FLDMMDL_MOVE_StartPlayerTracking(mmdl, work);
    }
    return 1;
}

/* Start tracking the player: remember his grid position. */
void FLDMMDL_MOVE_StartPlayerTracking(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 player = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)mmdl));
    work->tracking = 1;
    work->targetX = FLDMMDL_GetGridNowX((void *)player);
    work->targetZ = FLDMMDL_GetGridNowZ((void *)player);
    work->lastDir = 0xFF;
}

/* Has the player left the remembered grid position. */
int FLDMMDL_MOVE_HasPlayerMoved(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 player = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)mmdl));
    int x;
    int z;
    if (player != 0) {
        x = FLDMMDL_GetGridNowX((void *)player);
        z = FLDMMDL_GetGridNowZ((void *)player);
        if (x != work->targetX || z != work->targetZ) {
            return 1;
        }
    }
    return 0;
}

/* Remember the player's current grid position. */
void FLDMMDL_MOVE_SavePlayerGridPos(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 player = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)mmdl));
    work->targetX = FLDMMDL_GetGridNowX((void *)player);
    work->targetZ = FLDMMDL_GetGridNowZ((void *)player);
}

/* Acmd code base of the turn: the four 0x58..0x5B codes map to 0x10..0x13. */
int FLDMMDL_MOVE_GetTurnAcmdBase(Mmdl *mmdl)
{
    int acmdCode;
    FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)mmdl));
    acmdCode = FLDMMDL_GetAcmdCode(mmdl);
    switch (acmdCode) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    }
    return acmdCode;
}

/* Turn towards the player when he is on another grid cell. */
int FLDMMDL_MOVE_TurnToPlayer(Mmdl *mmdl)
{
    int player;
    int x;
    int z;
    int playerX;
    int playerZ;
    int turnBase;
    player = (int)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)mmdl));
    x = FLDMMDL_GetGridNowX((void *)mmdl);
    z = FLDMMDL_GetGridNowZ((void *)mmdl);
    playerX = FLDMMDL_GetGridOldX((void *)player);
    playerZ = FLDMMDL_GetGridOldZ((void *)player);
    if (x != playerX || z != playerZ) {
        turnBase = FLDMMDL_MOVE_GetTurnAcmdBase(mmdl);
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)((int)FLDMMDL_MOVE_GetDirFromPoints(x, z, playerX, playerZ)), (u16)turnBase)));
        return 1;
    }
    return 0;
}

/* Look at another model of the zone (init). */
void FLDMMDL_MOVE_InitLookFellow(Mmdl *mmdl)
{
    MmdlLookWork *work = FLDMMDL_InitMoveProcWork(mmdl, 12);
    FLDMMDL_MOVE_UpdateFellowTracking(mmdl, work);
    FLDMMDL_SetDrawStatus((void *)mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
    work->tracking = 0;
}

/* Look at another model of the zone (move). */
void FLDMMDL_MOVE_LookFellow(Mmdl *mmdl)
{
    MmdlLookWork *work = FLDMMDL_GetMoveProcWork((void *)mmdl);
    if (FLDMMDL_MOVE_UpdateFellowTracking(mmdl, work)) {
        while (gLookFellowStepTable[work->step](mmdl, work) == 1) {
        }
    }
}

/* Look at another model of the zone (delete). */
void FLDMMDL_MOVE_DeleteLookFellow(void) {}

/* Forget the other model being watched. */
void FLDMMDL_MOVE_ClearFellowTracking(void)
{
    MmdlLookWork *work = FLDMMDL_GetMoveProcWork();
    work->tracking = 0;
}

/* Look at another model, step 0: turn when it has moved. */
int FLDMMDL_MOVE_LookFellowTurn(Mmdl *mmdl, MmdlLookWork *work)
{
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_OffMoveBitMoveEnd(mmdl);
    if (FLDMMDL_MOVE_CanTurnToFellow(mmdl, work) == 1 && FLDMMDL_MOVE_TurnToFellow(mmdl, work) == 1) {
        FLDMMDL_OnMoveBitMove(mmdl);
        work->step++;
        return 1;
    }
    return 0;
}

/* Look at another model, step 1: wait for the turn to end. */
int FLDMMDL_MOVE_LookFellowWaitTurn(Mmdl *mmdl, MmdlLookWork *work, u32 regR2, u32 regR3)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 0) {
        return 0;
    }
    FLDMMDL_OffMoveBitMove(mmdl);
    work->step = 0;
    return 0;
}

/* Find another model of the same zone and area that this one can look at. */
Mmdl *FLDMMDL_MOVE_FindFellow(Mmdl *mmdl)
{
    Mmdl *other;
    u32 iter;
    u32 eventType;
    int zoneId;
    void *mmdlSys;
    int area;
    iter = 0;
    eventType = FLDMMDL_GetEventType(mmdl);
    zoneId = FLDMMDL_GetZoneId((void *)mmdl);
    mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    area = EVENT_TRAINER_EYE_GetTrainerId(mmdl);
    switch (eventType) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 20:
        while (FLDMMDL_SysSearchUseMmdl(mmdlSys, (void **)(&other), &iter) == 1) {
            if (mmdl != other && zoneId == FLDMMDL_GetZoneId((void *)other) && area == EVENT_TRAINER_EYE_GetTrainerId(other)) {
                return other;
            }
        }
        break;
    }
    return 0;
}

/* Search for the model to watch; start tracking it when first found. */
int FLDMMDL_MOVE_UpdateFellowTracking(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 iter;
    Mmdl *other;
    int zoneId;
    int area;
    void *mmdlSys;
    mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    iter = 0;
    zoneId = FLDMMDL_GetZoneId((void *)mmdl);
    area = EVENT_TRAINER_EYE_GetTrainerId(mmdl);
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, (void **)(&other), &iter) == 1) {
        if (mmdl != other && zoneId == FLDMMDL_GetZoneId((void *)other) && area == EVENT_TRAINER_EYE_GetTrainerId(other)) {
            if (work->tracking == 0) {
                FLDMMDL_MOVE_StartFellowTracking(mmdl, work, other);
            }
            return 1;
        }
    }
    work->tracking = 0;
    return 0;
}

/* Start tracking the other model: remember its grid position. */
int FLDMMDL_MOVE_StartFellowTracking(Mmdl *mmdl, MmdlLookWork *work, Mmdl *fellow)
{
    work->tracking = 1;
    work->targetX = FLDMMDL_GetGridNowX((void *)fellow);
    work->targetZ = FLDMMDL_GetGridNowZ((void *)fellow);
    work->lastDir = 255;
    work->target = fellow;
    return 255;
}

/* Did the watched model move off its cell and become able to be looked at. */
int FLDMMDL_MOVE_CanTurnToFellow(Mmdl *mmdl, MmdlLookWork *work)
{
    Mmdl *fellow = work->target;
    u32 x = FLDMMDL_GetGridNowX((void *)mmdl);
    u32 z = FLDMMDL_GetGridNowZ((void *)mmdl);
    u32 fellowX = FLDMMDL_GetGridOldX((void *)fellow);
    u32 fellowZ = FLDMMDL_GetGridOldZ((void *)fellow);
    if (x != fellowX || z != fellowZ) {
        if (FLDMMDL_CheckMoveBitMove((void *)fellow) == 1 || FLDMMDL_CheckMoveBit((void *)fellow, 0x1808) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Turn towards the watched model. */
int FLDMMDL_MOVE_TurnToFellow(Mmdl *mmdl, MmdlLookWork *work)
{
    u32 x = FLDMMDL_GetGridNowX((void *)mmdl);
    u32 z = FLDMMDL_GetGridNowZ((void *)mmdl);
    u32 savedX = FLDMMDL_GetGridNowX((void *)(work->target));
    u32 savedZ = FLDMMDL_GetGridNowZ((void *)(work->target));
    u32 fellowX = FLDMMDL_GetGridOldX((void *)(work->target));
    u32 fellowZ = FLDMMDL_GetGridOldZ((void *)(work->target));
    u32 dir;
    if (x == savedX && z == savedZ) {
        return 0;
    }
    dir = FLDMMDL_MOVE_GetDirFromPoints(x, z, fellowX, fellowZ);
    x += (u32)FLDMMDL_MOVE_GetDirAddGridX((u16)dir);
    z += FLDMMDL_MOVE_GetDirAddGridZ(dir);
    if (x != savedX || z != savedZ) {
        FLDMMDL_SetLocalAcmd(mmdl, (u16)FLDMMDL_ACMD_ConvertCodeByDir(dir & 0xFFFF, 12));
        return 1;
    }
    return 0;
}

/* Hide in a field effect (init, shared by the four hide move codes). */
void FLDMMDL_MOVE_InitHide(Mmdl *mmdl, u32 kind)
{
    MmdlVec drawOffset;
    u32 hideBit = 8;
    ((MmdlHideWork *)FLDMMDL_InitMoveProcWork(mmdl, 8))->kind = kind;
    FLDMMDL_SetDrawStatus((void *)mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_SetMoveBit((void *)mmdl, hideBit << 12);
    drawOffset = gHideDrawOffsetInit;
    FLDMMDL_SetDrawOffset(mmdl, &drawOffset);
}

void FLDMMDL_MOVE_InitHideKind0(Mmdl *mmdl) { FLDMMDL_MOVE_InitHide(mmdl, 0); }
void FLDMMDL_MOVE_InitHideKind1(Mmdl *mmdl) { FLDMMDL_MOVE_InitHide(mmdl, 1); }
void FLDMMDL_MOVE_InitHideKind1Alt(Mmdl *mmdl) { FLDMMDL_MOVE_InitHide(mmdl, 1); }
void FLDMMDL_MOVE_InitHideKind0Alt(Mmdl *mmdl) { FLDMMDL_MOVE_InitHide(mmdl, 0); }

/* Hide (move). */
void FLDMMDL_MOVE_Hide(Mmdl *mmdl)
{
    MmdlHideWork *work = FLDMMDL_GetMoveProcWork((void *)mmdl);
    while (gHideStepTable[work->step](mmdl, work) == 1) {
    }
}

/* Hide (delete): remove the field effect. */
void FLDMMDL_MOVE_DeleteHide(Mmdl *mmdl)
{
    u32 effect = FLDMMDL_MOVE_GetHideEffect(mmdl);
    if (effect != 0) {
        FIELD_EFFECT_DeleteObject(effect);
    }
}

/* Hide (recover after a map change). */
void FLDMMDL_MOVE_RecoverHide(Mmdl *mmdl)
{
    MmdlHideWork *work = FLDMMDL_GetMoveProcWork((void *)mmdl);
    MmdlVec drawOffset;
    work->step = 0;
    FLDMMDL_MOVE_SetHideEffect(mmdl, 0);
    if (work->noEffect == 0) {
        drawOffset = gHideDrawOffsetRecover;
        FLDMMDL_SetDrawOffset(mmdl, &drawOffset);
        FLDMMDL_SetMoveBit((void *)mmdl, 2 << 14);
    }
}

/* Create the hide field effect of the given kind. */
int FLDEFF_HIDE_Create(Mmdl *mmdl, u32 kind)
{
    return FLDEFF_HIDE_Start(FIELDMAP_GetEffect((u8 *)FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys((void *)mmdl))), mmdl, kind);
}

/* Hide, step 0: create the effect and pause the model's movement. */
int FLDMMDL_MOVE_HideCreateEffect(Mmdl *mmdl, MmdlHideWork *work)
{
    if (work->noEffect == 0) {
        FLDMMDL_MOVE_SetHideEffect(mmdl, FLDEFF_HIDE_Create(mmdl, work->kind));
    }
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_OffMoveBitMoveEnd(mmdl);
    work->step++;
    return 0;
}

/* Hide, step 1: keep the effect alive and the model hidden. */
int FLDMMDL_MOVE_HideKeepEffect(Mmdl *mmdl, MmdlHideWork *work, u32 regR2, u32 regR3)
{
    if (work->noEffect == 0) {
        if (FLDMMDL_MOVE_GetHideEffect(mmdl) == 0) {
            if (FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
                FLDMMDL_MOVE_SetHideEffect(mmdl, FLDEFF_HIDE_Create(mmdl, work->kind));
            }
        }
        FLDMMDL_SetMoveBit((void *)mmdl, (2 << 14));
    }
    return 0;
}

/* Store the hide field effect in the move proc work. */
void FLDMMDL_MOVE_SetHideEffect(Mmdl *mmdl, u32 effect)
{
    ((MmdlHideWork *)FLDMMDL_GetMoveProcWork())->effect = effect;
}

/* Get the hide field effect of the move proc work. */
int FLDMMDL_MOVE_GetHideEffect(Mmdl *mmdl)
{
    return ((MmdlHideWork *)FLDMMDL_GetMoveProcWork((void *)mmdl))->effect;
}

/* Do not create a field effect for this hidden model. */
void FLDMMDL_MOVE_SetHideNoEffect(Mmdl *mmdl)
{
    MmdlHideWork *work = FLDMMDL_GetMoveProcWork();
    work->noEffect = 1;
}

/*
 * Face a direction (init). The dir argument is unused here; the model
 * turns to direction 0 first and the step functions set the real one.
 */
u32 FLDMMDL_MOVE_InitFaceDir(mmdl, dir, flag, regR3)
Mmdl *mmdl;
u32 dir, flag, regR3;
{
    MmdlFaceDirWork *work = FLDMMDL_InitMoveProcWork(mmdl, 4, flag, regR3);
    work->dir = 9;
    work->flag = flag;
    return FLDMMDL_SetDirDispCheckPause(mmdl, 0);
}

u32 FLDMMDL_MOVE_InitFaceDirUp(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 0, 0); }
u32 FLDMMDL_MOVE_InitFaceDirDown(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 1, 0); }
u32 FLDMMDL_MOVE_InitFaceDirLeft(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 2, 0); }
u32 FLDMMDL_MOVE_InitFaceDirRight(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 3, 0); }
u32 FLDMMDL_MOVE_InitFaceDirUpFlag(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 0, 1); }
u32 FLDMMDL_MOVE_InitFaceDirDownFlag(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 1, 1); }
u32 FLDMMDL_MOVE_InitFaceDirLeftFlag(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 2, 1); }
u32 FLDMMDL_MOVE_InitFaceDirRightFlag(Mmdl *mmdl) { return FLDMMDL_MOVE_InitFaceDir(mmdl, 3, 1); }

/* Face a direction (move). */
void FLDMMDL_MOVE_FaceDir(Mmdl *mmdl)
{
    MmdlFaceDirWork *work = FLDMMDL_GetMoveProcWork((void *)mmdl);
    while (gFaceDirStepTable[work->step](mmdl, work) == 1) {
    }
}

/* Face a direction, step 0: turn to the model's display direction. */
int FLDMMDL_MOVE_FaceDirTurnSelf(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    FLDMMDL_SetLocalAcmd(mmdl, (((u32)FLDMMDL_ACMD_ConvertCodeByDir((u32)(((u32)FLDMMDL_GetDirDisp((void *)mmdl) << 16) >> 16), (u32)0) << 16) >> 16));
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_OffMoveBitMoveEnd(mmdl);
    ((MmdlFaceDirWork *)work)->step = 1;
    return 1;
}

/* Face a direction, step 1: wait for the turn to end. */
int FLDMMDL_MOVE_FaceDirWaitTurn(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 1) {
        ((MmdlFaceDirWork *)work)->step = 2;
        return 1;
    }
    return 0;
}

/* Face a direction, step 2: take the player's direction when none is set. */
int FLDMMDL_MOVE_FaceDirResolvePlayerDir(Mmdl *mmdl, s8 *work)
{
    u32 player;
    if (work[1] == 9) {
        player = (u32)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)mmdl));
        if (player != 0) {
            work[1] = FLDMMDL_GetDirMove((void *)player);
        }
    }
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_OffMoveBitMoveEnd(mmdl);
    work[0] = 3;
    return 1;
}

/* Face a direction, step 3: turn to the player's direction. */
int FLDMMDL_MOVE_FaceDirTurnPlayerDir(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    FLDMMDL_SetLocalAcmd(mmdl, (((u32)FLDMMDL_ACMD_ConvertCodeByDir((u32)FLDMMDL_GetDirMove(FLDMMDL_SysSearchPlayer((void *)FLDMMDL_GetMmdlSys((void *)mmdl))), (u32)0) << 16) >> 16));
    ((MmdlFaceDirWork *)work)->step = 4;
    return 1;
}

/* Face a direction, step 4: wait for the turn to end. */
int FLDMMDL_MOVE_FaceDirWaitPlayerTurn(Mmdl *mmdl, u32 work, u32 regR2, u32 regR3)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 0) {
        return 0;
    }
    FLDMMDL_OffMoveBitMove(mmdl);
    FLDMMDL_OffMoveBitMoveEnd(mmdl);
    ((MmdlFaceDirWork *)work)->step = 2;
    return 0;
}

/* Walk along a wall (init). */
void FLDMMDL_MOVE_InitWallWalk(mmdl, mode, hand, regR3)
u32 mmdl, mode, hand, regR3;
{
    MmdlWallWalkWork *work = FLDMMDL_InitMoveProcWork(mmdl, 12, hand, regR3);
    work->mode = mode;
    work->hand = hand;
}

void FLDMMDL_MOVE_InitWallWalkMode0Hand0(Mmdl *mmdl) { FLDMMDL_MOVE_InitWallWalk(mmdl, 0, 0); }
void FLDMMDL_MOVE_InitWallWalkMode1Hand1(Mmdl *mmdl) { FLDMMDL_MOVE_InitWallWalk(mmdl, 1, 1); }
void FLDMMDL_MOVE_InitWallWalkMode2Hand0(Mmdl *mmdl) { FLDMMDL_MOVE_InitWallWalk(mmdl, 2, 0); }
void FLDMMDL_MOVE_InitWallWalkMode2Hand1(Mmdl *mmdl) { FLDMMDL_MOVE_InitWallWalk(mmdl, 2, 1); }

/* Walk along a wall (move). */
void FLDMMDL_MOVE_WallWalk(Mmdl *mmdl)
{
    MmdlWallWalkWork *work = FLDMMDL_GetMoveProcWork((void *)mmdl);
    while (gWallWalkStepTable[work->step](mmdl, work) == 1) {
    }
}

/* Walk along a wall, step 0: stop the previous move. */
int FLDMMDL_MOVE_WallWalkStop(Mmdl *mmdl, MmdlWallWalkWork *work)
{
    FLDMMDL_OffMoveBitMove(mmdl);
    work->step++;
    return 1;
}

/* Walk along a wall, step 1: try a step. */
int FLDMMDL_MOVE_WallWalkTryStep(Mmdl *mmdl, MmdlWallWalkWork *work)
{
    FLDMMDL_MOVE_WallWalkStepOnce(mmdl, work, 12);
    work->step++;
    return 1;
}

/* Walk along a wall, step 2: wait for the step to end. */
int FLDMMDL_MOVE_WallWalkWaitStep(Mmdl *mmdl, MmdlWallWalkWork *work, u32 regR2, u32 regR3)
{
    if (FLDMMDL_ACMD_Update(mmdl) == 1) {
        FLDMMDL_OffMoveBitMove(mmdl);
        work->step = 0;
    }
    return 0;
}

/*
 * result = 0 is the first statement: its early live range pushes mmdl to a
 * stack spill and leaves ip for &checkPos.
 */
/* Is the cell next to pos (offset table A) a blocking attribute. */
int FLDMMDL_MOVE_IsWallAtOffsetA(Mmdl *mmdl, MmdlVec *pos, int dir, int hand)
{
    int result;
    s16 gridX;
    s16 gridZ;
    MmdlVec checkPos;
    u32 attr;
    result = 0;
    checkPos = *pos;
    gridX = (pos->x >> 4) / 4096;
    gridZ = (pos->z >> 4) / 4096;
    gridX += (s16)gWallCheckOffsetAX[dir][hand];
    gridZ += (s16)gWallCheckOffsetAZ[dir][hand];
    checkPos.x = gridX << 16;
    checkPos.z = gridZ << 16;
    if (FLDMMDL_MOVE_GetMapAttr(mmdl, &checkPos, &attr) == 1 && MAP_ATTR_IsBlocked(attr) != 0) {
        result = 1;
    }
    return result;
}

/* Same as FLDMMDL_MOVE_IsWallAtOffsetA with offset table B. */
int FLDMMDL_MOVE_IsWallAtOffsetB(Mmdl *mmdl, MmdlVec *pos, int dir, int hand)
{
    int result;
    s16 gridX;
    s16 gridZ;
    MmdlVec checkPos;
    u32 attr;
    result = 0;
    checkPos = *pos;
    gridX = (pos->x >> 4) / 4096;
    gridZ = (pos->z >> 4) / 4096;
    gridX += (s16)gWallCheckOffsetBX[dir][hand];
    gridZ += (s16)gWallCheckOffsetBZ[dir][hand];
    checkPos.x = gridX << 16;
    checkPos.z = gridZ << 16;
    if (FLDMMDL_MOVE_GetMapAttr(mmdl, &checkPos, &attr) == 1 && MAP_ATTR_IsBlocked(attr) != 0) {
        result = 1;
    }
    return result;
}

/* Table A wall check at the model's position. */
int FLDMMDL_MOVE_IsWallNearA(Mmdl *mmdl, int dir, int hand)
{
    MmdlVec pos;
    FLDMMDL_GetPos((const struct Actor *)mmdl, (struct VecFx32 *)&pos);
    return FLDMMDL_MOVE_IsWallAtOffsetA(mmdl, &pos, dir, hand);
}

/* Table B wall check at the model's position. */
int FLDMMDL_MOVE_IsWallNearB(Mmdl *mmdl, int dir, int hand)
{
    MmdlVec pos;
    FLDMMDL_GetPos((const struct Actor *)mmdl, (struct VecFx32 *)&pos);
    return FLDMMDL_MOVE_IsWallAtOffsetB(mmdl, &pos, dir, hand);
}

/* Direction to walk next along the wall; 9 when there is no wall. */
int FLDMMDL_MOVE_GetWallWalkDir(Mmdl *mmdl, int dir, int hand)
{
    if (FLDMMDL_MOVE_IsWallNearA(mmdl, dir, hand) == 0) {
        if (FLDMMDL_MOVE_IsWallNearB(mmdl, dir, hand) == 0) {
            return 9;
        }
        dir = gWallWalkRedirectDir[dir][hand];
    }
    return dir;
}

/* Pick the direction along the wall and hit-check it; 0 when 9 (none). */
int FLDMMDL_MOVE_HitCheckWallWalkDir(Mmdl *mmdl, int *dir, u32 hand)
{
    int newDir = FLDMMDL_MOVE_GetWallWalkDir(mmdl, *dir, hand);
    *dir = newDir;
    if (newDir != 9) {
        return FLDMMDL_MOVE_HitCheckMoveDir(mmdl, newDir);
    }
    return 0;
}

/* Walk one step along the wall, turning to the other hand when blocked. */
int FLDMMDL_MOVE_WallWalkStepOnce(Mmdl *mmdl, MmdlWallWalkWork *work, u32 acmdKind)
{
    u32 dir;
    u32 hand;
    u32 acmdCode;
    int hit;
    hand = work->hand;
    dir = FLDMMDL_GetDirMove((void *)mmdl);
    hit = FLDMMDL_MOVE_HitCheckWallWalkDir(mmdl, (int *)(&dir), hand);
    if (dir == 9) {
        dir = FLDMMDL_GetDirMove((void *)mmdl);
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)0x1c)));
        return 0;
    }
    if (hit == 0) {
        acmdCode = (u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)acmdKind);
        FLDMMDL_OnMoveBitMove(mmdl);
        FLDMMDL_SetLocalAcmd(mmdl, (u16)acmdCode);
        return 1;
    }
    if ((1 & hit) && work->mode == 2) {
        dir = FLDMMDL_MOVE_GetDirTableValue(FLDMMDL_GetDirMove((void *)mmdl));
        hand = gWallWalkHandSwap[hand];
        work->hand = hand;
        hit = FLDMMDL_MOVE_HitCheckWallWalkDir(mmdl, (int *)(&dir), hand);
        if (dir == 9) {
            dir = FLDMMDL_GetDirMove((void *)mmdl);
            FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)0x1c)));
            return 0;
        }
        if (hit == 0) {
            acmdCode = (u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)acmdKind);
            FLDMMDL_OnMoveBitMove(mmdl);
            FLDMMDL_SetLocalAcmd(mmdl, (u16)acmdCode);
            return 1;
        }
    }
    if (hit & 2) {
        dir = gWallWalkBounceDir[dir][hand];
        hit = FLDMMDL_MOVE_HitCheckWallWalkDir(mmdl, (int *)(&dir), hand);
        if (dir == 9) {
            dir = FLDMMDL_GetDirMove((void *)mmdl);
            FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)0x1c)));
            return 0;
        }
        if (hit == 0) {
            acmdCode = (u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)acmdKind);
            FLDMMDL_OnMoveBitMove(mmdl);
            FLDMMDL_SetLocalAcmd(mmdl, (u16)acmdCode);
            return 1;
        }
    }
    dir = FLDMMDL_GetDirMove((void *)mmdl);
    FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)0x1c)));
    return 0;
}
