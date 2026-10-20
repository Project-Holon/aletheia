/*
 * file:     field_rail.c
 * unit:     yes
 * function: FIELD_RAIL_Create, FIELD_RAIL_Delete, FIELD_RAIL_SetSetting, FIELD_RAIL_ClearSetting, FIELD_RAIL_ActivateFreeWork, FIELD_RAIL_ReleaseWork, FIELD_RAIL_SetFocusWork, FIELD_RAIL_ClearFocusWork, FIELD_RAIL_GetFocusPos, FIELD_RAIL_Update, FIELD_RAIL_UpdateCamera, FIELD_RAIL_FindSegmentLocation, FIELD_RAIL_SetLineEnable, FIELD_RAIL_GetUnitScale, FIELD_RAIL_MakeLineLocation, FIELD_RAIL_StepLocation, FIELD_RAIL_TryStepLocation, FIELD_RAIL_GetLocationPos, FIELD_RAIL_GetLocationWidthGrid, FIELD_RAIL_UpdateCameraAtLocation, FIELD_RAIL_WORK_GetLocation, FIELD_RAIL_WORK_IsLocationValid, FIELD_RAIL_WORK_QueryStep, FIELD_RAIL_WORK_GetPrevPos, FIELD_RAIL_WORK_SetLocation, FIELD_RAIL_WORK_GetPos, FIELD_RAIL_WORK_GetLastKey, FIELD_RAIL_WORK_IsMoving, FIELD_RAIL_WORK_HasStepped, FIELD_RAIL_WORK_GetStepVector, FIELD_RAIL_WORK_GetLineKey, FIELD_RAIL_WORK_StartStep, FIELD_RAIL_WORK_UpdateStep, FIELD_RAIL_GetFieldCamera, FIELD_RAIL_GetFocusWork, FIELD_RAIL_GetPoint, FIELD_RAIL_GetLine, FIELD_RAIL_GetLinePos, FIELD_RAIL_GetUnitScaleRaw, FIELD_RAIL_GetProbeWork, FIELD_RAIL_ClampLocation, FIELD_RAIL_WORK_GetMode, FIELD_RAIL_WORK_GetSpot, FIELD_RAIL_WORK_GetLineOffset, FIELD_RAIL_WORK_GetLineEndOffset, FIELD_RAIL_WORK_GetWidthOffsetRaw, FIELD_RAIL_WORK_GetWidthLimit, FIELD_RAIL_WORK_GetUnitScale, FIELD_RAIL_WORK_GetCamera, FIELD_RAIL_WORK_GetCentrePos, FIELD_RAIL_WORK_GetPosAtLineOffset, FIELD_RAIL_WORK_GetStartPoint, FIELD_RAIL_WORK_GetEndPoint, FIELD_RAIL_WORK_GetLinePos, FIELD_RAIL_WORK_GetPointCamera, FIELD_RAIL_RoundToGrid, FIELD_RAIL_IsPosNear, FIELD_RAIL_WORK_GetLocationParts, FIELD_RAIL_WORK_SetLineLocation, FIELD_RAIL_POINT_FindLine, FIELD_RAIL_WORK_TryEnterLine, FIELD_RAIL_WORK_EnterLine, FIELD_RAIL_LINE_StartsAtPoint, FIELD_RAIL_LINE_EndsAtPoint, FIELD_RAIL_GetNeighbourLimits, FIELD_RAIL_SETTING_Clear, FIELD_RAIL_SETTING_Copy, FIELD_RAIL_SETTING_GetPoint, FIELD_RAIL_SETTING_GetLine, FIELD_RAIL_SETTING_GetCamera, FIELD_RAIL_SETTING_GetLinePos, FIELD_RAIL_SETTING_GetCameraFunc, FIELD_RAIL_SETTING_GetLinePosFunc, FIELD_RAIL_SETTING_GetLineFunc, FIELD_RAIL_WORK_Advance, FIELD_RAIL_WORK_Init, FIELD_RAIL_WORK_Reset, FIELD_RAIL_WORK_IsInUse, FIELD_RAIL_WORK_IsActive, FIELD_RAIL_WORK_GetSpotCamera, FIELD_RAIL_WORK_GetSpotPos, FIELD_RAIL_WORK_GetLocationFromSpot, FIELD_RAIL_LINE_GetLength, FIELD_RAIL_LINE_GetWidthAt, FIELD_RAIL_WORK_ClampWidth, FIELD_RAIL_ProbeStep, FIELD_RAIL_KEY_Opposite, FIELD_RAIL_KEY_TurnRight, FIELD_RAIL_KEY_TurnLeft, FIELD_RAIL_CLOSED_Clear, FIELD_RAIL_CLOSED_Add, FIELD_RAIL_CLOSED_Remove, FIELD_RAIL_CLOSED_Contains, FIELD_RAIL_CLOSED_ContainsLine, FIELD_RAIL_GetOpenLine, FIELD_RAIL_WORK_MoveClamped, FIELD_RAIL_IsLocationInLine, FIELD_RAIL_POINT_GetLineKey, FIELD_RAIL_LINE_IsConsistent, FIELD_RAIL_POINT_IsConsistent, FIELD_RAIL_DebugPrintPos, FIELD_RAIL_POINT_DebugPrint, FIELD_RAIL_WORK_DebugCheck, FIELD_RAIL_SETTING_GetPointIndex, FIELD_RAIL_SETTING_GetLineIndex, FIELD_RAIL_IntersectSegmentPlane, FIELD_RAIL_SlerpDir, FIELD_RAIL_SlerpVec, FIELD_RAIL_LINEPOS_Straight, FIELD_RAIL_LINEPOS_ArcFlat, FIELD_RAIL_LINEPOS_Arc, FIELD_RAIL_LINEFUNC_Straight, FIELD_RAIL_LINEFUNC_Arc, FIELD_RAIL_CAMERA_EyeOffsetFromFocus, FIELD_RAIL_CAMERA_FixedAngle, FIELD_RAIL_CAMERA_FixedAngleAtCentre, FIELD_RAIL_CAMERA_BlendAngles, FIELD_RAIL_CAMERA_BlendAnglesAtFocus, FIELD_RAIL_CAMERA_BlendAnglesAtCentre, FIELD_RAIL_CAMERA_FixedEyeTarget, FIELD_RAIL_CAMERA_BlendEyeTarget, FIELD_RAIL_CAMERA_BlendOrbit, FIELD_RAIL_CAMERA_Orbit, FIELD_RAIL_CAMERA_SetOrbit, FIELD_RAIL_CAMERA_OrbitMovingPoint, FIELD_RAIL_CAMERA_YawFromPoint, FIELD_RAIL_CAMERA_FollowHeading, FIELD_RAIL_CAMERA_FollowHeadingSlope, FIELD_RAIL_CAMERA_FollowHeadingAtCentre, FIELD_RAIL_CAMERA_ApplyLineStart, FIELD_RAIL_CAMERA_ApplyLineEnd, FIELD_RAIL_CAMERA_FixedAngleShift, FIELD_RAIL_CAMERA_FixedAngleShiftAtFocus, FIELD_RAIL_CAMERA_BlendAnglesShift, FIELD_RAIL_ProjectOnSegment, FIELD_RAIL_CAMERA_ApplyPoint
 * address:  0x021B7884
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field rail system: the rail manager and rail works, the line shape functions and the rail camera functions.
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_RAIL_WORK_Init  0x021B9164  thumb
 *   sRailFileName     0x021DE2A0  data  a1
 *   FIELD_RAIL_CLOSED_Clear  0x021B9464  thumb  ov021
 *   FIELD_RAIL_WORK_IsInUse  0x021B91A8  thumb ov021
 *   FIELD_RAIL_WORK_IsActive  0x021B91AC  thumb
 *   FIELD_RAIL_SETTING_GetCameraFunc  0x021B8870  thumb
 *   FIELD_RAIL_GetOpenLine  0x021B9510  thumb  ov021
 *   FIELD_RAIL_SETTING_GetLinePos  0x021B8848  thumb  ov021
 *   FIELD_RAIL_SETTING_GetLineFunc  0x021B88B8  thumb  ov021
 *   FIELD_RAIL_IntersectSegmentPlane  0x021B9828  thumb  ov021
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_Distance  0x0207CF3C  arm
 *   gRailUpAxis     0x021D9A00  data   a4
 *   FIELD_RAIL_CLOSED_Contains  0x021B94C0  thumb ov021
 *   FIELD_RAIL_CLOSED_Add  0x021B9478  thumb ov021
 *   FIELD_RAIL_CLOSED_Remove  0x021B949C  thumb ov021
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   FIELD_RAIL_LINE_GetLength  0x021B9278  thumb ov021
 *   FIELD_RAIL_LINE_GetWidthAt  0x021B9280  thumb ov021
 *   MI_CpuCopy8  0x02082D44  arm
 *   FIELD_RAIL_WORK_Reset  0x021B919C  thumb  ov021
 *   FIELD_RAIL_WORK_GetSpotPos  0x021B91F8  thumb  ov021
 *   FIELD_RAIL_WORK_GetLocationFromSpot  0x021B9238  thumb  ov021
 *   FIELD_RAIL_ProbeStep  0x021B9368  thumb  ov021
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   FIELD_RAIL_WORK_Advance  0x021B88DC  thumb  ov021
 *   FIELD_RAIL_WORK_DebugCheck  0x021B977C  thumb  ov021
 *   gRailStepSizes     0x021DE298  data
 *   FIELD_RAIL_WORK_GetSpotCamera  0x021B91C8  thumb
 *   FIELD_RAIL_IsLocationInLine  0x021B95C0  thumb
 *   FIELD_RAIL_KEY_Opposite  0x021B93D4  thumb
 *   FIELD_RAIL_LINE_IsConsistent  0x021B963C  thumb
 *   FIELD_RAIL_KEY_TurnLeft  0x021B9434  thumb
 *   FIELD_RAIL_KEY_TurnRight  0x021B9404  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   gRailDefaultCamera     0x021D9A0C  data  a4
 *   gRailDefaultLinePos     0x021D9A30  data  a4
 *   FIELD_RAIL_POINT_FindLine  0x021B8514  thumb  ov021
 *   FIELD_RAIL_WORK_TryEnterLine  0x021B854C  thumb  ov021
 *   FIELD_RAIL_LINE_StartsAtPoint  0x021B8674  thumb  ov021
 *   FIELD_RAIL_LINE_EndsAtPoint  0x021B868C  thumb  ov021
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb  ov021
 *   FIELD_RAIL_SETTING_GetCamera  0x021B8820  thumb  ov021
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FIELD_RAIL_WORK_StartStep  0x021B80E0  thumb  ov021
 *   FIELD_RAIL_WORK_UpdateStep  0x021B810C  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FIELD_RAIL_WORK_IsLocationValid  0x021B7DE0  thumb  ov021
 *   FIELD_RAIL_SETTING_GetLine  0x021B87FC  thumb
 *   FIELD_RAIL_GetNeighbourLimits  0x021B86A4  thumb
 *   d_021DE2B0     0x021DE2B0  data  a4
 *   d_021DE2B4     0x021DE2B4  data  a4
 *   d_021DE2BC     0x021DE2BC  data  a4
 *   VEC_Mag          0x0207CBD0  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   FX_Div           0x0207C768  arm
 *   _ll_mul          0x0209C054  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   VEC_Add          0x0207C9D0  arm
 *   BUTTON_MAN_ScaleVec    0x020520A4  arm
 *   FX_SinCosTable_       0x020A1B38  data   a2
 *   VEC_Mag  0x0207CBD0  arm
 *   VEC_MultAdd  0x0207CEE4  arm
 *   FIELD_RAIL_WORK_GetSpot  0x021B82F4  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineOffset  0x021B82F8  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineEndOffset  0x021B82FC  thumb  ov021
 *   FIELD_RAIL_WORK_GetWidthOffsetRaw  0x021B8300  thumb  ov021
 *   FIELD_RAIL_WORK_GetUnitScale  0x021B8308  thumb  ov021
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_WORK_GetEndPoint  0x021B834C  thumb  ov021
 *   FX_Div  0x0207C768  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   d_021D9A54     0x021D9A54  data  ov021  a4
 *   FIELD_RAIL_WORK_GetLinePos  0x021B835C  thumb  ov021
 *   VEC_Add  0x0207C9D0  arm
 *   d_021D9A60     0x021D9A60  data  a4
 *   FIELD_RAIL_GetPoint  0x021B8224  thumb  ov021
 *   FIELD_RAIL_GetLine  0x021B8230  thumb  ov021
 *   FIELD_RAIL_GetLinePos  0x021B823C  thumb  ov021
 *   FIELD_RAIL_GetUnitScaleRaw  0x021B8248  thumb  ov021
 *   FIELD_RAIL_ClampLocation  0x021B8250  thumb  ov021
 *   FIELD_RAIL_RoundToGrid  0x021B8378  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   FIELD_RAIL_GetProbeWork  0x021B824C  thumb  ov021
 *   FIELD_RAIL_WORK_GetWidthLimit  0x021B8304  thumb  ov021
 *   VEC_DotProduct  0x0207CA68  arm
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_RAIL_WORK_GetCentrePos  0x021B8314  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_RAIL_WORK_GetPointCamera  0x021B836C  thumb  ov021
 *   FIELD_RAIL_WORK_GetMode  0x021B82F0  thumb  ov021
 *   FX_Atan2Idx  0x0207CFB8  arm
 *   FIELD_RAIL_WORK_GetStepVector  0x021B8050  thumb  ov021
 *   VEC_Fx16Mag  0x0207CC30  arm
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   VEC_Distance      0x0207CF3C  arm
 *   FIELD_RAIL_WORK_GetPosAtLineOffset  0x021B8328  thumb  ov021
 *   d_021DE2C4     0x021DE2C4  data  a4
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   FIELD_RAIL_Create  0x021B7884  thumb  ov021
 *   FIELD_RAIL_LOADER_Create  0x0219EF44  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 *   FIELD_RAIL_Delete  0x021B791C  thumb  ov021
 *   FIELD_RAIL_LOADER_Delete  0x0219EF6C  thumb  ov021
 *   FLD_SCENEAREA_SetEnabled  0x021AB75C  thumb  ov021
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   FIELD_RAIL_LOADER_Load  0x0219EF7C  thumb  ov021
 *   FIELD_RAIL_LOADER_GetSetting  0x0219F018  thumb  ov021
 *   FIELD_RAIL_SetSetting  0x021B7934  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Load  0x021AB840  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecs  0x021AB880  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecCount  0x021AB884  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetCallbacks  0x021AB888  thumb  ov021
 *   FLD_SCENEAREA_SetData  0x021AB634  thumb  ov021
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FLD_SCENEAREA_ClearData  0x021AB650  thumb  ov021
 *   FIELD_RAIL_ClearSetting  0x021B7954  thumb  ov021
 *   FIELD_RAIL_LOADER_Unload  0x0219EFFC  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Unload  0x021AB868  thumb  ov021
 *   FIELD_RAIL_Update  0x021B79E4  thumb  ov021
 *   FIELD_RAIL_UpdateCamera  0x021B79F0  thumb  ov021
 *   FIELD_RAIL_ActivateFreeWork  0x021B7970  thumb
 *   FIELD_RAIL_ReleaseWork  0x021B79AC  thumb
 *   FIELD_RAIL_SetFocusWork  0x021B79C4  thumb  ov021
 *   FIELD_RAIL_ClearFocusWork  0x021B79CC  thumb  ov021
 *   FIELD_RAIL_UpdateCameraAtLocation  0x021B7D68  thumb ov021
 *   FIELD_RAIL_SetLineEnable  0x021B7C04  thumb  ov021
 *   ZONEDATA_GetSpecialKind  0x02013C9C  thumb
 *   FIELD_RAIL_MakeLineLocation  0x021B7C58  thumb  ov021
 *   d_021DE2E8     0x021DE2E8  data  a4
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   sGyoeResIds     0x021D9A6C  data  a4
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FLDEFF_GYOE_PlaySe  0x021BB778  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sGyoeTaskHeader     0x021D9A7C  data  a4
 *   RAIL_ATTR_Create  0x021BB088  thumb  ov021
 *   RAIL_ATTR_Delete  0x021BB0A4  thumb  ov021
 *   RAIL_ATTR_Load  0x021BB0B4  thumb  ov021
 *   RAIL_ATTR_Release  0x021BB11C  thumb  ov021
 *   RAIL_ATTR_GetAttribute  0x021BB13C  thumb  ov021
 *   RAIL_ATTR_IsSignBoard  0x021BB188  thumb  ov021
 *   RAIL_ATTR_IsJumpStart  0x021BB1A0  thumb  ov021
 *   RAIL_ATTR_IsForceMoveUp  0x021BB1AC  thumb  ov021
 *   RAIL_ATTR_IsForceMoveDown  0x021BB1B8  thumb  ov021
 *   RAIL_ATTR_IsForceMoveLeft  0x021BB1C4  thumb  ov021
 *   RAIL_ATTR_IsForceMoveRight  0x021BB1D0  thumb  ov021
 *   RAIL_ATTR_IsForceMoveStop  0x021BB1DC  thumb  ov021
 *   RAIL_ATTR_IsSlipDown  0x021BB1E8  thumb  ov021
 *   FIELD_NOGRID_MAPPER_Create  0x021BB1F4  thumb  ov021
 *   FIELD_NOGRID_MAPPER_Delete  0x021BB240  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   FIELD_NOGRID_MAPPER_LoadData  0x021BB278  thumb  ov021
 *   FIELD_NOGRID_MAPPER_LoadDataFromArc  0x021BB2F8  thumb  ov021
 *   FIELD_NOGRID_MAPPER_ReleaseData  0x021BB348  thumb  ov021
 *   FIELD_NOGRID_MAPPER_Main  0x021BB36C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_UpdateCameraForced  0x021BB388  thumb  ov021
 *   FIELD_NOGRID_MAPPER_CreateRailWork  0x021BB394  thumb  ov021
 *   FIELD_NOGRID_MAPPER_DeleteRailWork  0x021BB3A0  thumb  ov021
 *   FIELD_NOGRID_MAPPER_BindCameraWork  0x021BB3AC  thumb  ov021
 *   FIELD_NOGRID_MAPPER_UnbindCameraWork  0x021BB3B8  thumb  ov021
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetCameraLocation  0x021BB3D0  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetLineEnable  0x021BB3DC  thumb  ov021
 *   FIELD_NOGRID_MAPPER_CalcZoneRailLocation  0x021BB3E8  thumb  ov021
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FLDEFF_GYOE_Init  0x021BB484  thumb  ov021
 *   FLDEFF_GYOE_Delete  0x021BB4A8  thumb  ov021
 *   FLDEFF_GYOE_InitResource  0x021BB4BC  thumb  ov021
 *   FLDEFF_GYOE_DeleteResource  0x021BB504  thumb  ov021
 *   FLDEFF_GYOE_SetMMdl  0x021BB528  thumb  ov021
 */
#include "field_rail_types.h"

#define FX32_ONE ((int)0x00001000L)
#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gf_standard.h"
#include "../arm9/mi_memory.h"
#include "../arm9/fx_vec.h"

extern void FIELD_RAIL_WORK_Init(RailWork *work, FieldRailSetting *setting, RailManager *manager);
extern void FIELD_RAIL_WORK_Reset(RailWork *work, FieldRailSetting *setting);
extern u16 FIELD_RAIL_WORK_IsInUse(RailWork *work);
extern int FIELD_RAIL_WORK_IsActive(RailWork *work);
extern RailCamera *FIELD_RAIL_WORK_GetSpotCamera(RailWork *work);
extern void FIELD_RAIL_WORK_GetSpotPos(RailWork *work, VecFx32 *outPos);
extern void FIELD_RAIL_WORK_GetLocationFromSpot(const RailWork *work, RailLocation *outLocation);
extern int FIELD_RAIL_LINE_GetLength(const RailLine *line, int unitScale, const FieldRailSetting *setting);
extern int FIELD_RAIL_LINE_GetWidthAt(const RailLine *line, u32 offset, u32 length, const FieldRailSetting *setting);
extern int FIELD_RAIL_ProbeStep(RailManager *manager, RailLocation *location, u32 key, int steps, VecFx32 *outPos);
extern int FIELD_RAIL_KEY_Opposite(int key);
extern int FIELD_RAIL_KEY_TurnRight(int key);
extern int FIELD_RAIL_KEY_TurnLeft(int key);
extern RailClosedLines *FIELD_RAIL_CLOSED_Clear(RailClosedLines *closedLines);
extern void FIELD_RAIL_CLOSED_Add(RailClosedLines *closedLines, u16 lineIndex);
extern void FIELD_RAIL_CLOSED_Remove(RailClosedLines *closedLines, u16 lineIndex);
extern int FIELD_RAIL_CLOSED_Contains(RailClosedLines *closedLines, u16 lineIndex);
extern RailLine *FIELD_RAIL_GetOpenLine(RailClosedLines *closedLines, FieldRailSetting *setting, u32 lineIndex);
extern int FIELD_RAIL_IsLocationInLine(RailClosedLines *closedLines, RailLine *line, int lineOffset, int widthOffset,
                         FieldRailSetting *setting, int unitScale);
extern int FIELD_RAIL_LINE_IsConsistent(RailLine *line, FieldRailSetting *setting);
extern void FIELD_RAIL_WORK_DebugCheck(RailWork *work);
extern int FIELD_RAIL_IntersectSegmentPlane(VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *d, VecFx32 *e, VecFx32 *out);
extern int FIELD_RAIL_WORK_Advance(RailWork *work, int key, int step);

RailManager *FIELD_RAIL_Create(u16 heapId, u32 workMax, struct FieldCamera *fieldCamera);
void FIELD_RAIL_Delete(RailManager *manager);
void FIELD_RAIL_SetSetting(RailManager *manager, FieldRailSetting *setting);
u32 FIELD_RAIL_ClearSetting(RailManager *manager);
RailWork *FIELD_RAIL_ActivateFreeWork(RailManager *manager);
int FIELD_RAIL_ReleaseWork(RailManager *manager, RailWork *work);
void FIELD_RAIL_SetFocusWork(RailManager *manager, RailWork *work);
void FIELD_RAIL_ClearFocusWork(RailManager *manager);
void FIELD_RAIL_GetFocusPos(RailManager *manager, VecFx32 *outPos);
void FIELD_RAIL_Update(RailManager *manager);
int FIELD_RAIL_UpdateCamera(RailManager *manager, int force);
int FIELD_RAIL_FindSegmentLocation(RailManager *manager, const VecFx32 *startPos, const VecFx32 *endPos, RailLocation *outLocation,
                  VecFx32 *outPos);
void FIELD_RAIL_SetLineEnable(RailManager *manager, int lineIndex, int enable);
int FIELD_RAIL_GetUnitScale(RailManager *manager);
void FIELD_RAIL_MakeLineLocation(RailManager *manager, FieldRailSetting *setting, u16 railIndex, u16 lineGrid, u16 widthPos,
                   RailLocation *outLocation);
int FIELD_RAIL_StepLocation(RailManager *manager, RailLocation *location, u16 key, VecFx32 *outPos);
int FIELD_RAIL_TryStepLocation(RailManager *manager, const RailLocation *location, u32 key, RailLocation *outLocation);
void FIELD_RAIL_GetLocationPos(RailManager *manager, RailLocation *location, VecFx32 *outPos);
int FIELD_RAIL_GetLocationWidthGrid(RailManager *manager, RailLocation *location);
void FIELD_RAIL_UpdateCameraAtLocation(RailManager *manager, const RailLocation *location);
void FIELD_RAIL_WORK_GetLocation(RailWork *work, RailLocation * __restrict outLocation);
int FIELD_RAIL_WORK_IsLocationValid(RailWork *work, RailLocation *location);
u8 FIELD_RAIL_WORK_QueryStep(RailWork *work, u32 key, RailLocation *outLocation, VecFx32 *outPos);
void FIELD_RAIL_WORK_GetPrevPos(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_WORK_SetLocation(RailWork *work, const RailLocation *location);
void FIELD_RAIL_WORK_GetPos(RailWork *work, VecFx32 *outPos);
u8 FIELD_RAIL_WORK_GetLastKey(RailWork *work);
u8 FIELD_RAIL_WORK_IsMoving(RailWork *work);
u8 FIELD_RAIL_WORK_HasStepped(RailWork *work);
void FIELD_RAIL_WORK_GetStepVector(RailWork *work, s16 *outStep);
u32 FIELD_RAIL_WORK_GetLineKey(RailWork *work);
int FIELD_RAIL_WORK_StartStep(RailWork *work, u32 speedIndex, u32 stepKey);
void FIELD_RAIL_WORK_UpdateStep(RailWork *work);
struct FieldCamera *FIELD_RAIL_GetFieldCamera(RailManager *manager);
RailWork *FIELD_RAIL_GetFocusWork(RailManager *manager);
RailPoint *FIELD_RAIL_GetPoint(RailManager *manager, u32 pointIndex);
RailLine *FIELD_RAIL_GetLine(RailManager *manager, u32 lineIndex);
RailLinePos *FIELD_RAIL_GetLinePos(RailManager *manager, int linePosIndex);
u32 FIELD_RAIL_GetUnitScaleRaw(RailManager *manager);
RailWork *FIELD_RAIL_GetProbeWork(RailManager *manager);
void FIELD_RAIL_ClampLocation(const RailManager *manager, const RailLocation *location, RailLocation *outLocation);
u16 FIELD_RAIL_WORK_GetMode(RailWork *work);
RailSpot *FIELD_RAIL_WORK_GetSpot(RailWork *work);
u32 FIELD_RAIL_WORK_GetLineOffset(RailWork *work);
u32 FIELD_RAIL_WORK_GetLineEndOffset(RailWork *work);
u32 FIELD_RAIL_WORK_GetWidthOffsetRaw(RailWork *work);
u32 FIELD_RAIL_WORK_GetWidthLimit(RailWork *work);
u32 FIELD_RAIL_WORK_GetUnitScale(RailWork *work);
RailCamera *FIELD_RAIL_WORK_GetCamera(RailWork *work);
void FIELD_RAIL_WORK_GetCentrePos(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_WORK_GetPosAtLineOffset(RailWork *work, int lineOffset, VecFx32 *outPos);
RailPoint *FIELD_RAIL_WORK_GetStartPoint(RailWork *work);
RailPoint *FIELD_RAIL_WORK_GetEndPoint(RailWork *work);
RailLinePos *FIELD_RAIL_WORK_GetLinePos(RailWork *work);
RailCamera *FIELD_RAIL_WORK_GetPointCamera(RailWork *work, RailPoint *point);
int FIELD_RAIL_RoundToGrid(int x);
int FIELD_RAIL_IsPosNear(const s32 *a, const s32 *b, s32 r);
void FIELD_RAIL_WORK_GetLocationParts(RailWork *work, u16 *outRailIndex, u16 *outLineGrid, u16 *outWidthGrid);
void FIELD_RAIL_WORK_SetLineLocation(RailWork *work, u32 railIndex, u32 lineGrid, int widthPos);
RailLine *FIELD_RAIL_POINT_FindLine(RailPoint *point, u32 key, FieldRailSetting *setting, RailClosedLines *closedLines, int checkClosed);
int FIELD_RAIL_WORK_TryEnterLine(RailWork *work, RailLine *line, u32 key, int lineOffset, int widthOffset, int lineLength, int widthMax);
void FIELD_RAIL_WORK_EnterLine(RailWork *work, RailLine *line, u32 key, u32 lineOffset, u32 widthOffset, u32 lineEnd, u32 widthLimit);
int FIELD_RAIL_LINE_StartsAtPoint(FieldRailSetting *setting, RailLine *line, RailPoint *point);
int FIELD_RAIL_LINE_EndsAtPoint(FieldRailSetting *setting, RailLine *line, RailPoint *point);
void FIELD_RAIL_GetNeighbourLimits(FieldRailSetting *setting, const RailLine *line, int *outLengthLimit, int *outWidthLimit,
                   RailClosedLines *closedLines, int unitScale);
void FIELD_RAIL_SETTING_Clear(FieldRailSetting *setting);
void FIELD_RAIL_SETTING_Copy(FieldRailSetting *dst, const FieldRailSetting *src);
RailPoint *FIELD_RAIL_SETTING_GetPoint(FieldRailSetting *setting, u32 pointIndex);
RailLine *FIELD_RAIL_SETTING_GetLine(FieldRailSetting *setting, u32 lineIndex);
RailCamera *FIELD_RAIL_SETTING_GetCamera(FieldRailSetting *setting, u32 cameraIndex);
extern RailLinePos *FIELD_RAIL_SETTING_GetLinePos(FieldRailSetting *setting, u32 linePosIndex);
extern RailCameraFunc FIELD_RAIL_SETTING_GetCameraFunc(FieldRailSetting *setting, u32 funcIndex);
extern RailLineFunc FIELD_RAIL_SETTING_GetLineFunc(FieldRailSetting *setting, u32 funcIndex);

extern const char sRailFileName[];
extern const VecFx32 gRailUpAxis;
extern const u8 gRailStepSizes[];

#include "../arm9/button_man.h"
#include "../arm9/fx_atanidx.h"
#include "../arm9/fx_cp.h"
#include "../arm9/fx_asinacosidx.h"
#include "field_camera.h"
extern s16 FX_SinCosTable_[];
extern VecFx32 d_021D9A54;
extern VecFx32 d_021D9A60;
extern const char d_021DE2B0[];
extern const char d_021DE2B4[];
extern const char d_021DE2BC[];

RailLinePosFunc FIELD_RAIL_SETTING_GetLinePosFunc(FieldRailSetting *setting, u32 funcIndex);
int FIELD_RAIL_WORK_ClampWidth(RailWork *work, RailLine *line, u32 lineEnd, int key);
int FIELD_RAIL_CLOSED_ContainsLine(RailClosedLines *closedLines, RailLine *line, FieldRailSetting *setting);
void FIELD_RAIL_WORK_MoveClamped(RailClosedLines *closedLines, RailWork *work, int lineDelta, int widthDelta, int key);
u32 FIELD_RAIL_POINT_GetLineKey(RailPoint *point, RailLine *line, FieldRailSetting *setting);
int FIELD_RAIL_POINT_IsConsistent(RailPoint *point, FieldRailSetting *setting);
void FIELD_RAIL_DebugPrintPos(const char *label, VecFx32 *pos);
void FIELD_RAIL_POINT_DebugPrint(const char *prefix, RailPoint *point, const char *suffix);
int FIELD_RAIL_SETTING_GetPointIndex(FieldRailSetting *setting, RailPoint *point);
int FIELD_RAIL_SETTING_GetLineIndex(FieldRailSetting *setting, RailLine *line);
void FIELD_RAIL_SlerpDir(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t);
void FIELD_RAIL_SlerpVec(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t);
void FIELD_RAIL_LINEPOS_Straight(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_LINEPOS_ArcFlat(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_LINEPOS_Arc(RailWork *work, VecFx32 *outPos);
int FIELD_RAIL_LINEFUNC_Straight(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos);
int FIELD_RAIL_LINEFUNC_Arc(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos);
void FIELD_RAIL_CAMERA_EyeOffsetFromFocus(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngle(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngleAtCentre(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAngles(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAnglesAtFocus(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAnglesAtCentre(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedEyeTarget(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendEyeTarget(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendOrbit(RailManager *manager);
void FIELD_RAIL_CAMERA_Orbit(RailManager *manager);
void FIELD_RAIL_CAMERA_SetOrbit(RailManager *manager, u16 pitch, int distance, VecFx32 *point);
void FIELD_RAIL_CAMERA_OrbitMovingPoint(RailManager *manager);
void FIELD_RAIL_CAMERA_YawFromPoint(RailManager *manager);
void FIELD_RAIL_CAMERA_FollowHeading(RailManager *manager);
void FIELD_RAIL_CAMERA_FollowHeadingSlope(RailManager *manager);
void FIELD_RAIL_CAMERA_FollowHeadingAtCentre(RailManager *manager);
void FIELD_RAIL_CAMERA_ApplyLineStart(RailManager *manager);
void FIELD_RAIL_CAMERA_ApplyLineEnd(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngleShift(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngleShiftAtFocus(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAnglesShift(RailManager *manager);
int FIELD_RAIL_ProjectOnSegment(RailPoint *startPoint, RailPoint *endPoint, const VecFx32 *pos, VecFx32 *outHit, fx32 *outDist,
                  VecFx32 *outAxis);
void FIELD_RAIL_CAMERA_ApplyPoint(RailManager *manager, RailWork *work, RailPoint *point);

RailManager *FIELD_RAIL_Create(u16 heapId, u32 workMax, struct FieldCamera *fieldCamera)
{
    u32 i;
    RailManager *manager;

    manager = GFL_HEAP_Alloc(heapId, 0x74, 1, sRailFileName, 302);
    manager->heapId = heapId;
    manager->dataLoaded = 0;
    manager->running = 1;
    manager->fieldCamera = fieldCamera;
    manager->focusWork = 0;
    manager->works = GFL_HEAP_Alloc(heapId, 0x7c * workMax, 1, sRailFileName, 311);
    manager->workCount = workMax;
    for (i = 0; i < workMax; i++)
        FIELD_RAIL_WORK_Init(&manager->works[i], &manager->setting, manager);
    manager->probeWork = GFL_HEAP_Alloc(heapId, 0x7c, 1, sRailFileName, 319);
    FIELD_RAIL_WORK_Init(manager->probeWork, &manager->setting, manager);
    manager->probeWork->inUse = 1;
    return manager;
}

void FIELD_RAIL_Delete(RailManager *manager)
{
    GFL_HEAP_Free(manager->probeWork);
    GFL_HEAP_Free(manager->works);
    GFL_HEAP_Free(manager);
}

void FIELD_RAIL_SetSetting(RailManager *manager, FieldRailSetting *setting)
{
    manager->dataLoaded = 1;
    FIELD_RAIL_CLOSED_Clear(&manager->closedLines);
    FIELD_RAIL_SETTING_Copy(&manager->setting, setting);
}

u32 FIELD_RAIL_ClearSetting(RailManager *manager)
{
    manager->dataLoaded = 0;
    FIELD_RAIL_SETTING_Clear(&manager->setting);
    return (uptr)FIELD_RAIL_CLOSED_Clear(&manager->closedLines);
}

RailWork *FIELD_RAIL_ActivateFreeWork(RailManager *manager)
{
    RailWork *found = 0;
    int i;

    for (i = 0; i < manager->workCount; i++) {
        if (FIELD_RAIL_WORK_IsInUse(&manager->works[i]) == 0) {
            found = &manager->works[i];
            break;
        }
    }
    found->inUse = 1;
    return found;
}

int FIELD_RAIL_ReleaseWork(RailManager *manager, RailWork *work)
{
    FIELD_RAIL_WORK_Init(work, &manager->setting, manager);
    work->inUse = 0;
    return 0;
}

void FIELD_RAIL_SetFocusWork(RailManager *manager, RailWork *work)
{
    manager->focusWork = work;
    manager->forceCamera = 1;
}

void FIELD_RAIL_ClearFocusWork(RailManager *manager)
{
    manager->focusWork = 0;
}

void FIELD_RAIL_GetFocusPos(RailManager *manager, VecFx32 *outPos)
{
    if (manager->focusWork != 0) {
        FIELD_RAIL_WORK_GetPos(manager->focusWork, outPos);
    }
}

void FIELD_RAIL_Update(RailManager *manager)
{
    if (manager->dataLoaded == 0)
        return;
    if (manager->running)
        return;
}

int FIELD_RAIL_UpdateCamera(RailManager *manager, int force)
{
    RailWork *work;
    u32 index;
    RailCameraFunc cameraFunc;

    cameraFunc = 0;
    work = manager->focusWork;
    if (manager->dataLoaded == 0)
        return 0;
    if (manager->running == 0)
        return 0;
    if (work == 0)
        return 0;
    if (FIELD_RAIL_WORK_IsActive(work) == 0)
        return 0;
    if (FIELD_RAIL_WORK_HasStepped(work) == 0 && manager->forceCamera == 0 && force == 0)
        return 0;
    switch (work->mode) {
    case RAIL_WORK_ON_POINT:
        index = work->spot->point.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = FIELD_RAIL_SETTING_GetCameraFunc(work->setting, FIELD_RAIL_SETTING_GetCamera(work->setting, index)->funcIndex);
        break;
    case RAIL_WORK_ON_LINE:
        index = work->spot->line.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = FIELD_RAIL_SETTING_GetCameraFunc(work->setting, FIELD_RAIL_SETTING_GetCamera(work->setting, index)->funcIndex);
        break;
    }
    if (cameraFunc)
        cameraFunc(manager);
    manager->forceCamera = 0;
    return 1;
}

int FIELD_RAIL_FindSegmentLocation(RailManager *manager, const VecFx32 *startPos, const VecFx32 *endPos, RailLocation *outLocation,
                  VecFx32 *outPos)
{
    VecFx32 hitPos;
    VecFx32 lineDir;
    VecFx32 lineNormal;
    VecFx32 upAxis;
    VecFx32 bestPos;
    VecFx32 segStart;
    VecFx32 segEnd;
    RailLocation bestLocation;
    int i;
    fx32 bestDist;
    int found;
    RailLine *line;
    RailPoint *startPoint;
    RailPoint *endPoint;
    RailLinePos *linePos;
    RailLineFunc lineFunc;
    fx32 dist;

    upAxis = gRailUpAxis;
    segStart = *startPos;
    segEnd = *endPos;
    found = 0;
    for (i = 0; i < manager->setting.lineCount; i++) {
        line = FIELD_RAIL_GetOpenLine(&manager->closedLines, &manager->setting, i);
        if (line == 0) {
            continue;
        }
        startPoint = FIELD_RAIL_SETTING_GetPoint(&manager->setting, line->startPoint);
        endPoint = FIELD_RAIL_SETTING_GetPoint(&manager->setting, line->endPoint);
        linePos = FIELD_RAIL_SETTING_GetLinePos(&manager->setting, line->linePosIndex);
        VEC_Subtract(&startPoint->pos, &endPoint->pos, &lineDir);
        VEC_CrossProduct(&lineDir, &upAxis, &lineNormal);
        if (FIELD_RAIL_IntersectSegmentPlane(&lineDir, &lineNormal, &endPoint->pos, &segStart, &segEnd, &hitPos) == 0) {
            continue;
        }
        lineFunc = FIELD_RAIL_SETTING_GetLineFunc(&manager->setting, linePos->funcIndex);
        if (lineFunc == 0) {
            continue;
        }
        if (lineFunc(i, manager, &hitPos, outLocation, outPos) == 0) {
            continue;
        }
        if (!found) {
            bestLocation = *outLocation;
            bestPos = *outPos;
            bestDist = VEC_Distance(&segStart, outPos);
            found = 1;
        } else {
            dist = VEC_Distance(&segStart, outPos);
            if (dist < bestDist) {
                bestLocation = *outLocation;
                bestPos = *outPos;
                bestDist = dist;
            }
        }
    }
    if (found) {
        *outLocation = bestLocation;
        *outPos = bestPos;
    }
    return found;
}

void FIELD_RAIL_SetLineEnable(RailManager *manager, int lineIndex, int enable)
{
    if (enable == 0) {
        if (FIELD_RAIL_CLOSED_Contains(&manager->closedLines, lineIndex) == 0) {
            FIELD_RAIL_CLOSED_Add(&manager->closedLines, lineIndex);
        }
    } else {
        FIELD_RAIL_CLOSED_Remove(&manager->closedLines, lineIndex);
    }
}

int FIELD_RAIL_GetUnitScale(RailManager *manager)
{
    return (int)(((s64)manager->setting.unitScale * 0x10000 + 0x800) >> 12);
}

void FIELD_RAIL_MakeLineLocation(RailManager *manager, FieldRailSetting *setting, u16 railIndex, u16 lineGrid, u16 widthPos,
                   RailLocation *outLocation)
{
    RailWork *probe = manager->probeWork;
    probe->setting = setting;
    outLocation->railIndex = railIndex;
    outLocation->type = 1;
    outLocation->widthGrid = 0;
    outLocation->lineGrid = lineGrid;
    FIELD_RAIL_WORK_SetLocation(probe, outLocation);
    outLocation->widthGrid = widthPos - probe->widthLimit / 16;
    probe->setting = &manager->setting;
}

int FIELD_RAIL_StepLocation(RailManager *manager, RailLocation *location, u16 key, VecFx32 *outPos)
{
    FIELD_RAIL_WORK_SetLocation(manager->probeWork, location);
    FIELD_RAIL_WORK_StartStep(manager->probeWork, 4, key);
    FIELD_RAIL_WORK_UpdateStep(manager->probeWork);
    FIELD_RAIL_WORK_GetPos(manager->probeWork, outPos);
    if (GF_STANDARD_CompareBytes((u8 *)location, (u8 *)(&manager->probeWork->location), 8) == 0)
        return 0;
    return FIELD_RAIL_WORK_IsLocationValid(manager->probeWork, &manager->probeWork->location);
}

int FIELD_RAIL_TryStepLocation(RailManager *manager, const RailLocation *location, u32 key, RailLocation *outLocation)
{
    RailLocation startLocation = *location;
    FIELD_RAIL_WORK_SetLocation(manager->probeWork, location);
    FIELD_RAIL_WORK_StartStep(manager->probeWork, 4, key);
    FIELD_RAIL_WORK_UpdateStep(manager->probeWork);
    FIELD_RAIL_WORK_GetLocation(manager->probeWork, outLocation);
    if (GF_STANDARD_CompareBytes((u8 *)(&startLocation), (u8 *)outLocation, 8) == 0)
        return 0;
    return FIELD_RAIL_WORK_IsLocationValid(manager->probeWork, outLocation);
}

void FIELD_RAIL_GetLocationPos(RailManager *manager, RailLocation *location, VecFx32 *outPos)
{
    FIELD_RAIL_WORK_SetLocation(manager->probeWork, location);
    FIELD_RAIL_WORK_GetPos(manager->probeWork, outPos);
}

int FIELD_RAIL_GetLocationWidthGrid(RailManager *manager, RailLocation *location)
{
    FIELD_RAIL_WORK_SetLocation(manager->probeWork, location);
    return manager->probeWork->widthLimit / 16;
}

void FIELD_RAIL_UpdateCameraAtLocation(RailManager *manager, const RailLocation *location)
{
    RailCameraFunc cameraFunc;
    RailWork *prevFocus;
    RailWork *work;
    u32 index;

    cameraFunc = 0;
    FIELD_RAIL_WORK_SetLocation(manager->probeWork, location);
    prevFocus = manager->focusWork;
    work = manager->probeWork;
    manager->focusWork = work;
    switch (work->mode) {
    case RAIL_WORK_ON_POINT:
        index = work->spot->point.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = FIELD_RAIL_SETTING_GetCameraFunc(work->setting, FIELD_RAIL_SETTING_GetCamera(work->setting, index)->funcIndex);
        break;
    case RAIL_WORK_ON_LINE:
        index = work->spot->line.cameraIndex;
        if (index == RAIL_NONE_INDEX)
            break;
        cameraFunc = FIELD_RAIL_SETTING_GetCameraFunc(work->setting, FIELD_RAIL_SETTING_GetCamera(work->setting, index)->funcIndex);
        break;
    }
    if (cameraFunc)
        cameraFunc(manager);
    manager->focusWork = prevFocus;
}

/*
 * The out parameter is __restrict: it lets the scheduler pair the last two
 * halfword loads ahead of their stores (see docs/idioms/a-restrict-table-parameter-
 * hoists-a-load-above-a-store-only-at-a-different-offset.md).
 */
void FIELD_RAIL_WORK_GetLocation(RailWork *work, RailLocation * __restrict outLocation)
{
    *outLocation = work->location;
}

int FIELD_RAIL_WORK_IsLocationValid(RailWork *work, RailLocation *location)
{
    FieldRailSetting *setting;
    u8 *lines;
    int off;
    int x;
    int y;
    int length;
    int width;
    int pad;

    if (location->type == 0) {
        if (location->railIndex >= work->setting->pointCount) {
            return 0;
        }
    } else {
        setting = work->setting;
        if (location->railIndex >= setting->lineCount) {
            return 0;
        }
        lines = (u8 *)setting->lines;
        off = location->railIndex * 0x48;
        pad = 0;
        x = location->lineGrid << 4;
        y = location->widthGrid << 4;
        length = FIELD_RAIL_LINE_GetLength((RailLine *)(lines + (off + pad)), work->unitScale, setting);
        width = FIELD_RAIL_LINE_GetWidthAt((RailLine *)(lines + off), x, length, work->setting);
        if (-width > y || y > width) {
            return 0;
        }
        if (x > length || x < 0) {
            return 0;
        }
    }
    return 1;
}

u8 FIELD_RAIL_WORK_QueryStep(RailWork *work, u32 key, RailLocation *outLocation, VecFx32 *outPos)
{
    if (work->queryValid == 0 || key != work->queryKey) {
        work->queryResult = FIELD_RAIL_TryStepLocation(work->manager, &work->location, key, &work->queryLocation);
        FIELD_RAIL_GetLocationPos(work->manager, &work->queryLocation, &work->queryPos);
        work->queryValid = 1;
        work->queryKey = key;
    }
    if (outLocation != 0)
        MI_CpuCopy8(&work->queryLocation, outLocation, 8);
    if (outPos != 0)
        *outPos = work->queryPos;
    return work->queryResult;
}

void FIELD_RAIL_WORK_GetPrevPos(RailWork *work, VecFx32 *outPos)
{
    *outPos = work->prevPos;
}

void FIELD_RAIL_WORK_SetLocation(RailWork *work, const RailLocation *location)
{
    RailLine *line;
    int i;
    u32 lineLength;
    u32 lineOffset;
    u32 widthOffset;
    u32 key;
    u32 lineGrid;

    line = 0;
    FIELD_RAIL_WORK_Reset(work, work->setting);
    if (location->type == 0) {
        work->mode = RAIL_WORK_ON_POINT;
        work->spot = (RailSpot *)&work->setting->points[location->railIndex];
        work->widthLimit = work->spot->point.lineWidth[0];
        for (i = 0; i < 4; i++) {
            if (work->spot->point.lineIndex[i] != RAIL_NONE_INDEX && line == 0) {
                line = &work->setting->lines[work->spot->point.lineIndex[i]];
                if (line->startPoint == location->railIndex) {
                    lineOffset = 0;
                    widthOffset = 0;
                    key = work->spot->point.lineKey[i];
                } else if (line->endPoint == location->railIndex) {
                    lineOffset = FIELD_RAIL_LINE_GetLength(line, work->unitScale, work->setting);
                    widthOffset = 0;
                    key = work->spot->point.lineKey[i];
                }
            }
        }
    } else {
        line = &work->setting->lines[location->railIndex];
        lineGrid = location->lineGrid;
        if (lineGrid >= line->length) {
            lineGrid--;
        }
        lineOffset = lineGrid << 4;
        widthOffset = location->widthGrid << 4;
        key = location->key;
    }
    lineLength = FIELD_RAIL_LINE_GetLength(line, work->unitScale, work->setting);
    FIELD_RAIL_WORK_EnterLine(work, line, key, lineOffset, widthOffset, lineLength,
                  FIELD_RAIL_LINE_GetWidthAt(line, lineOffset, lineLength, work->setting));
    work->lastSpeedIndex = 1;
    work->lastKey = key;
    work->located = 1;
    FIELD_RAIL_WORK_GetSpotPos(work, &work->pos);
    work->location = *location;
    work->prevLocation = *location;
    work->prevPos = work->pos;
}

void FIELD_RAIL_WORK_GetPos(RailWork *work, VecFx32 *outPos)
{
    *outPos = work->pos;
}

u8 FIELD_RAIL_WORK_GetLastKey(RailWork *work)
{
    return work->lastKey;
}

u8 FIELD_RAIL_WORK_IsMoving(RailWork *work)
{
    return work->moving;
}

u8 FIELD_RAIL_WORK_HasStepped(RailWork *work)
{
    return work->stepped;
}

static inline void storeVecS16(s16 *dst, int x, int y, int z)
{
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

void FIELD_RAIL_WORK_GetStepVector(RailWork *work, s16 *outStep)
{
    VecFx32 curPos;
    VecFx32 nextPos;
    RailLocation nextLocation;
    s32 lineOffset;
    s32 lineEnd;
    s32 endOffset;
    u32 savedWidthOffset;

    savedWidthOffset = work->widthOffset;
    work->widthOffset = 0;
    FIELD_RAIL_WORK_GetSpotPos(work, &curPos);
    lineOffset = work->lineOffset;
    work->widthOffset = savedWidthOffset;
    lineEnd = work->lineEnd;
    endOffset = lineOffset + 0x10;
    if (endOffset < lineEnd) {
        work->lineOffset += 0x10;
        work->widthOffset = 0;
        FIELD_RAIL_WORK_GetSpotPos(work, &nextPos);
        work->widthOffset = savedWidthOffset;
        work->lineOffset = lineOffset;
    } else {
        FIELD_RAIL_WORK_GetLocationFromSpot(work, &nextLocation);
        nextLocation.widthGrid = 0;
        FIELD_RAIL_ProbeStep(work->manager, &nextLocation, work->spot->line.key, endOffset - lineEnd, &nextPos);
    }
    VEC_Subtract(&nextPos, &curPos, &nextPos);
    VEC_Normalize(&nextPos, &nextPos);
    storeVecS16(outStep, nextPos.x, nextPos.y, nextPos.z);
}

u32 FIELD_RAIL_WORK_GetLineKey(RailWork *work)
{
    RailSpot *spot = work->spot;
    return spot->line.key;
}

int FIELD_RAIL_WORK_StartStep(RailWork *work, u32 speedIndex, u32 stepKey)
{
    if (work->moving == 0) {
        work->moving = 1;
        work->stepProgress = 0;
        work->stepKey = stepKey;
        work->speedIndex = speedIndex;
        return 1;
    }
    return 0;
}

/*
 * The table byte is also FIELD_RAIL_WORK_Advance's third argument: the callee's
 * matched prototype is (p, dir, d), and the image leaves the ldrb value in
 * r2 untouched up to the call. That extra use keeps the byte live across
 * the stepProgress update, so its sign extension lands in a fresh register (r3).
 * See docs/idioms/a-byte-kept-live-into-a-call-argument-register-pushes-its-sign-extension-to-a-fresh-register.md.
 */
void FIELD_RAIL_WORK_UpdateStep(RailWork *work)
{
    int newKey;
    u16 prevMode;
    u16 stepKey;
    u8 stepSize;
    s32 remainder;

    if (work->manager->dataLoaded == 0)
        return;
    if (work->located == 0)
        return;
    if (FIELD_RAIL_WORK_IsActive(work) == 0)
        return;
    newKey = 0;
    work->stepped = 0;
    if (work->moving == 0)
        return;
    prevMode = work->mode;
    stepKey = work->stepKey;
    stepSize = gRailStepSizes[work->speedIndex];
    work->stepProgress += (s8)stepSize;
    if (prevMode == RAIL_WORK_ON_LINE)
        newKey = FIELD_RAIL_WORK_Advance(work, stepKey, stepSize);
    if (newKey != 0) {
        work->lastKey = newKey;
        work->lastSpeedIndex = work->speedIndex;
        work->stepped = 1;
        FIELD_RAIL_WORK_GetSpotPos(work, &work->pos);
    }
    if (prevMode != work->mode)
        FIELD_RAIL_WORK_DebugCheck(work);
    if (work->stepProgress < 0x10 && newKey != 0)
        return;
    work->moving = 0;
    work->queryValid = 0;
    work->prevLocation = work->location;
    FIELD_RAIL_WORK_GetLocationFromSpot(work, &work->location);
    work->prevPos = work->pos;
    remainder = work->lineOffset % 16;
    if (remainder == 0)
        return;
    if (remainder > 8)
        work->lineOffset = work->lineOffset + (16 - remainder);
    else
        work->lineOffset = work->lineOffset - remainder;
}

struct FieldCamera *FIELD_RAIL_GetFieldCamera(RailManager *manager)
{
    return manager->fieldCamera;
}

RailWork *FIELD_RAIL_GetFocusWork(RailManager *manager)
{
    return manager->focusWork;
}

RailPoint *FIELD_RAIL_GetPoint(RailManager *manager, u32 pointIndex)
{
    return FIELD_RAIL_SETTING_GetPoint(&manager->setting, pointIndex);
}

RailLine *FIELD_RAIL_GetLine(RailManager *manager, u32 lineIndex)
{
    return FIELD_RAIL_SETTING_GetLine(&manager->setting, lineIndex);
}

RailLinePos *FIELD_RAIL_GetLinePos(RailManager *manager, int linePosIndex)
{
    return FIELD_RAIL_SETTING_GetLinePos(&manager->setting, linePosIndex);
}

u32 FIELD_RAIL_GetUnitScaleRaw(RailManager *manager)
{
    return manager->setting.unitScale;
}

RailWork *FIELD_RAIL_GetProbeWork(RailManager *manager)
{
    return manager->probeWork;
}

/*
 * Twin of FIELD_RAIL_WORK_IsLocationValid. The first call adds a zero-valued local to off,
 * which gives the early multiply, the spilled offset and the
 * `adds r0,r3,#0` copy. `const RailManager *manager` lets the base load schedule into the
 * struct copy (`ldr r7,[r6,#0x34]` between the stores to location).
 */
void FIELD_RAIL_ClampLocation(const RailManager *manager, const RailLocation *location, RailLocation *outLocation)
{
    RailLocation loc;
    u8 *lines;
    s32 off;
    s32 x;
    s32 y;
    s32 length;
    s32 width;
    s32 pad;

    loc = *location;
    lines = (u8 *)manager->setting.lines;
    *outLocation = loc;
    off = loc.railIndex * 0x48;
    pad = 0;
    y = loc.lineGrid << 4;
    x = loc.widthGrid << 4;
    length = FIELD_RAIL_LINE_GetLength((RailLine *)(lines + (off + pad)), manager->setting.unitScale, &manager->setting);
    width = FIELD_RAIL_LINE_GetWidthAt((RailLine *)(lines + off), y, length, &manager->setting);
    if (y >= length)
        outLocation->lineGrid = (length - 1) / 16;
    if ((x < 0 ? -x : x) > width) {
        if (x > 0)
            outLocation->widthGrid = width / 16;
        else
            outLocation->widthGrid = -width / 16;
    }
}

u16 FIELD_RAIL_WORK_GetMode(RailWork *work)
{
    return work->mode;
}

RailSpot *FIELD_RAIL_WORK_GetSpot(RailWork *work)
{
    return work->spot;
}

u32 FIELD_RAIL_WORK_GetLineOffset(RailWork *work)
{
    return work->lineOffset;
}

u32 FIELD_RAIL_WORK_GetLineEndOffset(RailWork *work)
{
    return work->lineEnd;
}

u32 FIELD_RAIL_WORK_GetWidthOffsetRaw(RailWork *work)
{
    return work->widthOffset;
}

u32 FIELD_RAIL_WORK_GetWidthLimit(RailWork *work)
{
    return work->widthLimit;
}

u32 FIELD_RAIL_WORK_GetUnitScale(RailWork *work)
{
    return work->unitScale;
}

RailCamera *FIELD_RAIL_WORK_GetCamera(RailWork *work)
{
    return FIELD_RAIL_WORK_GetSpotCamera(work);
}

void FIELD_RAIL_WORK_GetCentrePos(RailWork *work, VecFx32 *outPos)
{
    int savedWidthOffset = work->widthOffset;
    work->widthOffset = 0;
    FIELD_RAIL_WORK_GetSpotPos(work, outPos);
    work->widthOffset = savedWidthOffset;
}

void FIELD_RAIL_WORK_GetPosAtLineOffset(RailWork *work, int lineOffset, VecFx32 *outPos)
{
    int savedLineOffset = work->lineOffset;
    work->lineOffset = lineOffset;
    FIELD_RAIL_WORK_GetSpotPos(work, outPos);
    work->lineOffset = savedLineOffset;
}

RailPoint *FIELD_RAIL_WORK_GetStartPoint(RailWork *work)
{
    return FIELD_RAIL_SETTING_GetPoint(work->setting, work->spot->line.startPoint);
}

RailPoint *FIELD_RAIL_WORK_GetEndPoint(RailWork *work)
{
    return FIELD_RAIL_SETTING_GetPoint(work->setting, work->spot->line.endPoint);
}

RailLinePos *FIELD_RAIL_WORK_GetLinePos(RailWork *work)
{
    return FIELD_RAIL_SETTING_GetLinePos(work->setting, work->spot->line.linePosIndex);
}

RailCamera *FIELD_RAIL_WORK_GetPointCamera(RailWork *work, RailPoint *point)
{
    return FIELD_RAIL_SETTING_GetCamera(work->setting, point->cameraIndex);
}

int FIELD_RAIL_RoundToGrid(int x)
{
    u32 ax = x < 0 ? -x : x;
    if ((ax & 15) >= 8) {
        if (x >= 0) {
            return x / 16 + 1;
        } else {
            return x / 16 - 1;
        }
    }
    return x / 16;
}

int FIELD_RAIL_IsPosNear(const s32 *a, const s32 *b, s32 r)
{
    s32 dx, dz, dy, rr, d2, r2;
    dx = (a[0] >> 12) - (b[0] >> 12);
    dz = (a[2] >> 12) - (b[2] >> 12);
    d2 = dx * dx + dz * dz;
    dy = a[1] - b[1];
    if (dy < 0)
        dy = -dy;
    rr = (r >> 12) * 2;
    r2 = rr * rr;
    if (dy < 0x8000 && d2 < r2)
        return 1;
    return 0;
}

void FIELD_RAIL_WORK_GetLocationParts(RailWork *work, u16 *outRailIndex, u16 *outLineGrid, u16 *outWidthGrid)
{
    s32 index, i, width, widthEnd;
    width = FIELD_RAIL_LINE_GetWidthAt((RailLine *)work->spot, 0, work->lineEnd, work->setting);
    widthEnd = FIELD_RAIL_LINE_GetWidthAt((RailLine *)work->spot, work->lineEnd, work->lineEnd, work->setting);
    if (width < widthEnd)
        width = widthEnd;
    index = 0;
    for (i = 0; i < work->setting->lineCount; i++) {
        if ((RailLine *)work->spot == work->setting->lines + i)
            index = i;
    }
    *outRailIndex = index;
    *outLineGrid = work->lineOffset / 16;
    *outWidthGrid = work->widthOffset / 16 + width / 16;
}

void FIELD_RAIL_WORK_SetLineLocation(RailWork *work, u32 railIndex, u32 lineGrid, int widthPos)
{
    RailLocation location;

    FIELD_RAIL_WORK_GetLocation(work, &location);
    location.railIndex = railIndex;
    location.widthGrid = 0;
    location.lineGrid = lineGrid;
    FIELD_RAIL_WORK_SetLocation(work, &location);
    location.widthGrid = widthPos - work->widthLimit / 16;
    FIELD_RAIL_WORK_GetSpotPos(work, &work->pos);
    work->location = location;
    work->prevLocation = location;
    work->prevPos = work->pos;
}

RailLine *FIELD_RAIL_POINT_FindLine(RailPoint *point, u32 key, FieldRailSetting *setting, RailClosedLines *closedLines, int checkClosed)
{
    int i;
    /* stand-in: the point is indexed as one word array (key at i + 4, line at i);
     * the field form point->lineKey[i] folds into a strided pointer and is 4 bytes shorter. */
    for (i = 0; i < 4; i++) {
        if (key == ((u32 *)point)[i + 4]) {
            if (checkClosed)
                return FIELD_RAIL_GetOpenLine(closedLines, setting, ((u32 *)point)[i]);
            return FIELD_RAIL_SETTING_GetLine(setting, ((u32 *)point)[i]);
        }
    }
    return 0;
}

/*
 * closed 2026-09-27 (tree_ov018): the early exit is one guard,
 * if (lineOffset < lineLength && lineOffset >= 0) goto tail; ahead of a plain if/else for the
 * two row lookups, and lineLength is reassigned in place of a separate local.
 */
int FIELD_RAIL_WORK_TryEnterLine(RailWork *work, RailLine *line, u32 key, int lineOffset, int widthOffset, int lineLength, int widthMax)
{
    RailLine *nextLine;
    if (FIELD_RAIL_IsLocationInLine(work->closedLines, line, lineOffset, widthOffset, work->setting, work->unitScale) == 0)
        return 0;
    if ((widthOffset < 0 ? -widthOffset : widthOffset) > widthMax)
        return 0;
    if (lineOffset < lineLength && lineOffset >= 0)
        goto tail;
    if (lineOffset >= lineLength) {
        RailPoint *point = FIELD_RAIL_SETTING_GetPoint(work->setting, line->endPoint);
        nextLine = FIELD_RAIL_POINT_FindLine(point, line->key, work->setting, work->closedLines, 1);
    } else {
        RailPoint *point = FIELD_RAIL_SETTING_GetPoint(work->setting, line->startPoint);
        nextLine = FIELD_RAIL_POINT_FindLine(point, FIELD_RAIL_KEY_Opposite(line->key), work->setting, work->closedLines, 1);
    }
    if (nextLine == 0) {
        if (lineOffset > lineLength)
            return 0;
        goto tail;
    }
    line = nextLine;
    if (lineOffset >= lineLength) {
        lineOffset -= lineLength;
        lineLength = FIELD_RAIL_LINE_GetLength(nextLine, work->unitScale, work->setting);
        widthMax = FIELD_RAIL_LINE_GetWidthAt(nextLine, lineOffset, lineLength, work->setting);
    } else if (lineOffset < 0) {
        lineLength = FIELD_RAIL_LINE_GetLength(nextLine, work->unitScale, work->setting);
        lineOffset += lineLength;
        widthMax = FIELD_RAIL_LINE_GetWidthAt(nextLine, lineOffset, lineLength, work->setting);
    }
    if (lineOffset >= lineLength)
        return 0;
    if ((widthOffset < 0 ? -widthOffset : widthOffset) > widthMax)
        return 0;
tail:
    FIELD_RAIL_WORK_EnterLine(work, line, key, lineOffset, widthOffset, lineLength, widthMax);
    FIELD_RAIL_LINE_IsConsistent(line, work->setting);
    return key;
}

void FIELD_RAIL_WORK_EnterLine(RailWork *work, RailLine *line, u32 key, u32 lineOffset, u32 widthOffset, u32 lineEnd, u32 widthLimit)
{
    work->mode = RAIL_WORK_ON_LINE;
    work->spot = (RailSpot *)line;
    work->widthOffset = widthOffset;
    work->lineEnd = lineEnd;
    work->moveKey = key;
    work->lineOffset = lineOffset;
    work->widthLimit = widthLimit;
}

int FIELD_RAIL_LINE_StartsAtPoint(FieldRailSetting *setting, RailLine *line, RailPoint *point)
{
    return FIELD_RAIL_SETTING_GetPoint(setting, line->startPoint) == point;
}

int FIELD_RAIL_LINE_EndsAtPoint(FieldRailSetting *setting, RailLine *line, RailPoint *point)
{
    return FIELD_RAIL_SETTING_GetPoint(setting, line->endPoint) == point;
}

/*
 * Scores three neighbouring cells (row from FIELD_RAIL_SETTING_GetPoint, then one
 * FIELD_RAIL_POINT_FindLine lookup per direction) against the start cell line.
 * line is read through a const pointer: with a plain pointer the outgoing
 * flag store `str r6, [sp]` lands before `adds r2, r5` in the first two
 * FIELD_RAIL_POINT_FindLine calls (8 bytes).  Declaration order of point/lengthLimit sets their
 * stack slots (lengthLimit at sp+0xc, point at sp+0x10).
 */
void FIELD_RAIL_GetNeighbourLimits(FieldRailSetting *setting, const RailLine *line, int *outLengthLimit, int *outWidthLimit,
                   RailClosedLines *closedLines, int unitScale)
{
    RailPoint *point;
    int lengthLimit;
    RailLine *oppositeLine;
    RailLine *previousLine;
    RailLine *nextLine;
    int widthLimit;
    int length;
    int limit;

    lengthLimit = 0;
    point = FIELD_RAIL_SETTING_GetPoint(setting, line->startPoint);
    oppositeLine = FIELD_RAIL_POINT_FindLine(point, FIELD_RAIL_KEY_Opposite(line->key), setting, closedLines, 1);
    previousLine = FIELD_RAIL_POINT_FindLine(point, FIELD_RAIL_KEY_TurnLeft(line->key), setting, closedLines, 1);
    nextLine = FIELD_RAIL_POINT_FindLine(point, FIELD_RAIL_KEY_TurnRight(line->key), setting, closedLines, 1);
    widthLimit = FIELD_RAIL_LINE_GetWidthAt(line, 0, FIELD_RAIL_LINE_GetLength(line, unitScale, setting), setting);
    if (oppositeLine) {
        length = FIELD_RAIL_LINE_GetLength(oppositeLine, unitScale, setting);
        limit = FIELD_RAIL_LINE_GetWidthAt(oppositeLine, length, length, setting);
        if (limit > widthLimit)
            widthLimit = limit;
    }
    if (previousLine) {
        length = FIELD_RAIL_LINE_GetLength(previousLine, unitScale, setting);
        if (FIELD_RAIL_LINE_StartsAtPoint(setting, previousLine, point))
            limit = FIELD_RAIL_LINE_GetWidthAt(previousLine, 0, length, setting);
        else
            limit = FIELD_RAIL_LINE_GetWidthAt(previousLine, length, length, setting);
        if (limit > lengthLimit)
            lengthLimit = limit;
    }
    if (nextLine) {
        length = FIELD_RAIL_LINE_GetLength(nextLine, unitScale, setting);
        if (FIELD_RAIL_LINE_StartsAtPoint(setting, nextLine, point))
            limit = FIELD_RAIL_LINE_GetWidthAt(nextLine, 0, length, setting);
        else
            limit = FIELD_RAIL_LINE_GetWidthAt(nextLine, length, length, setting);
        if (limit > lengthLimit)
            lengthLimit = limit;
    }
    *outLengthLimit = lengthLimit;
    *outWidthLimit = widthLimit;
}

void FIELD_RAIL_SETTING_Clear(FieldRailSetting *setting)
{
    MI_CpuFill8(setting, 0, 48);
}

void FIELD_RAIL_SETTING_Copy(FieldRailSetting *dst, const FieldRailSetting *src)
{
    MI_CpuCopy8(src, dst, 0x30);
}

RailPoint *FIELD_RAIL_SETTING_GetPoint(FieldRailSetting *setting, u32 pointIndex)
{
    if (setting->pointCount > pointIndex)
        return &setting->points[pointIndex];
    if (pointIndex == RAIL_NONE_INDEX)
        return 0;
    return setting->points;
}

RailLine *FIELD_RAIL_SETTING_GetLine(FieldRailSetting *setting, u32 lineIndex)
{
    if (setting->lineCount > lineIndex)
        return &setting->lines[lineIndex];
    if (lineIndex == RAIL_NONE_INDEX)
        return 0;
    return setting->lines;
}

RailCamera *FIELD_RAIL_SETTING_GetCamera(FieldRailSetting *setting, u32 cameraIndex)
{
    if (setting->cameraCount > cameraIndex) {
        return &setting->cameras[cameraIndex];
    }
    if (cameraIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return &gRailDefaultCamera;
}

RailLinePos *FIELD_RAIL_SETTING_GetLinePos(FieldRailSetting *setting, u32 linePosIndex)
{
    if (setting->linePosCount > linePosIndex) {
        return &setting->linePoses[linePosIndex];
    }
    if (linePosIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return &gRailDefaultLinePos;
}

RailCameraFunc FIELD_RAIL_SETTING_GetCameraFunc(FieldRailSetting *setting, u32 funcIndex)
{
    if (setting->cameraFuncCount > funcIndex) {
        return setting->cameraFuncs[funcIndex];
    }
    if (funcIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return setting->cameraFuncs[0];
}

RailLinePosFunc FIELD_RAIL_SETTING_GetLinePosFunc(FieldRailSetting *setting, u32 funcIndex)
{
    if (setting->linePosFuncCount > funcIndex) {
        return setting->linePosFuncs[funcIndex];
    }
    if (funcIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return setting->linePosFuncs[0];
}

RailLineFunc FIELD_RAIL_SETTING_GetLineFunc(FieldRailSetting *setting, u32 funcIndex)
{
    if (setting->lineFuncCount > funcIndex) {
        return setting->lineFuncs[funcIndex];
    }
    if (funcIndex == RAIL_NONE_INDEX) {
        return 0;
    }
    return setting->lineFuncs[0];
}

/*
 * closed 2026-10-02 (share-A lane A2-09).  Three source facts turned the
 * 2026-09-27 near miss (lineEnd spilled, frame 0x54) into the image's allocation
 * (lineEnd in r7 for the whole body, frame 0x6c):
 *  - arm 93D4: reachedEnd = 0 is assigned after the 9404 call, through a local
 *    (r = 9404(dir); reachedEnd = 0; e1 = 8514(row, r, ...)); with reachedEnd = 0 ahead
 *    of the nested call, reachedEnd takes r6 and lineEnd is spilled.
 *  - arm 93D4: the lineTurnB probe is two sequential ifs (8674, then 868C), not an
 *    else-if as in the other two-way probes of arms f08/93D4.
 *  - arms 9404/9434: each half has its own point/line locals; in arm 9434 the two
 *    spilled 8674-path lengths are block-level locals declared second-half
 *    first (the image has the first half's at the lower slot).
 * Arm-subset compiles (only f08, f08+9404, f08+9434) matched the image's
 * allocation exactly, which isolated the 93D4 arm as the cause.
 */
int FIELD_RAIL_WORK_Advance(RailWork *work, int key, int step)
{
    int lineEnd;
    RailLine *line;
    int result;

    line = &work->spot->line;
    lineEnd = work->lineEnd;
    if (key == line->key) {
        RailPoint *point;
        RailLine *lineAhead;
        RailLine *lineTurnA;
        RailLine *lineTurnB;
        int reachedEnd;

        point = FIELD_RAIL_SETTING_GetPoint(work->setting, line->endPoint);
        reachedEnd = 0;
        lineAhead = FIELD_RAIL_POINT_FindLine(point, key, work->setting, work->closedLines, reachedEnd);
        lineTurnA = FIELD_RAIL_POINT_FindLine(point, FIELD_RAIL_KEY_TurnLeft(key), work->setting, work->closedLines, reachedEnd);
        lineTurnB = FIELD_RAIL_POINT_FindLine(point, FIELD_RAIL_KEY_TurnRight(key), work->setting, work->closedLines, reachedEnd);
        FIELD_RAIL_WORK_MoveClamped(work->closedLines, work, step, 0, key);
        if (work->lineOffset < lineEnd) {
            result = FIELD_RAIL_LINE_GetWidthAt(line, work->lineOffset, lineEnd, work->setting);
            if (result >= (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset)) {
                return key;
            }
            reachedEnd = 1;
        }
        if (lineAhead != 0 && reachedEnd == 0) {
            int lineLength;
            int widthMax;
            FIELD_RAIL_POINT_IsConsistent(point, work->setting);
            lineLength = FIELD_RAIL_LINE_GetLength(lineAhead, work->unitScale, work->setting);
            widthMax = FIELD_RAIL_LINE_GetWidthAt(lineAhead, work->lineOffset - lineEnd, lineLength, work->setting);
            result = FIELD_RAIL_WORK_TryEnterLine(work, lineAhead, key, work->lineOffset - lineEnd, work->widthOffset, lineLength, widthMax);
            if (result != 0) {
                return result;
            }
        }
        if (lineTurnA != 0 && work->widthOffset <= 0) {
            if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnA, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnA, -work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnA, key, -work->widthOffset, work->lineOffset - lineEnd, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            } else if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnA, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnA, lineLength + work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnA, key, lineLength + work->widthOffset, -(work->lineOffset - lineEnd), lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (lineTurnB != 0 && work->widthOffset >= 0) {
            if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnB, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnB, work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnB, key, work->widthOffset, -(work->lineOffset - lineEnd), lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            } else if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnB, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnB, lineLength - work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnB, key, lineLength - work->widthOffset, work->lineOffset - lineEnd, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (reachedEnd) {
            return FIELD_RAIL_WORK_ClampWidth(work, line, lineEnd, key);
        }
        if (work->lineOffset <= lineEnd) {
            return key;
        }
        work->lineOffset = work->lineOffset - step;
        return 0;
    } else if (key == FIELD_RAIL_KEY_Opposite(line->key)) {
        RailPoint *point;
        RailLine *lineTurnA;
        RailLine *lineTurnB;
        RailLine *lineAhead;
        int reachedEnd;

        point = FIELD_RAIL_SETTING_GetPoint(work->setting, line->startPoint);
        result = FIELD_RAIL_KEY_TurnRight(key);
        reachedEnd = 0;
        lineTurnA = FIELD_RAIL_POINT_FindLine(point, result, work->setting, work->closedLines, reachedEnd);
        lineTurnB = FIELD_RAIL_POINT_FindLine(point, FIELD_RAIL_KEY_TurnLeft(key), work->setting, work->closedLines, reachedEnd);
        lineAhead = FIELD_RAIL_POINT_FindLine(point, key, work->setting, work->closedLines, reachedEnd);
        FIELD_RAIL_WORK_MoveClamped(work->closedLines, work, -step, 0, key);
        if (work->lineOffset >= 0) {
            result = FIELD_RAIL_LINE_GetWidthAt(line, work->lineOffset, lineEnd, work->setting);
            if (result >= (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset)) {
                return key;
            }
            reachedEnd = 1;
        }
        if (lineAhead != 0 && reachedEnd == 0) {
            int lineLength;
            int widthMax;
            FIELD_RAIL_POINT_IsConsistent(point, work->setting);
            lineLength = FIELD_RAIL_LINE_GetLength(lineAhead, work->unitScale, work->setting);
            widthMax = FIELD_RAIL_LINE_GetWidthAt(lineAhead, lineLength - (work->lineOffset < 0 ? -work->lineOffset : work->lineOffset), lineLength, work->setting);
            result = FIELD_RAIL_WORK_TryEnterLine(work, lineAhead, key, lineLength - (work->lineOffset < 0 ? -work->lineOffset : work->lineOffset), work->widthOffset, lineLength, widthMax);
            if (result != 0) {
                return result;
            }
        }
        if (lineTurnA != 0 && work->widthOffset <= 0) {
            if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnA, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnA, -work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnA, key, -work->widthOffset, work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            } else if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, lineTurnA, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnA, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnA, lineLength + work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnA, key, lineLength + work->widthOffset, -work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (lineTurnB != 0 && work->widthOffset >= 0) {
            if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnB, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnB, work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnB, key, work->widthOffset, -work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
            if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, lineTurnB, point)) {
                int lineLength;
                int widthMax;
                FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                lineLength = FIELD_RAIL_LINE_GetLength(lineTurnB, work->unitScale, work->setting);
                widthMax = FIELD_RAIL_LINE_GetWidthAt(lineTurnB, lineLength - work->widthOffset, lineLength, work->setting);
                result = FIELD_RAIL_WORK_TryEnterLine(work, lineTurnB, key, lineLength - work->widthOffset, work->lineOffset, lineLength, widthMax);
                if (result != 0) {
                    return result;
                }
            }
        }
        if (reachedEnd) {
            return FIELD_RAIL_WORK_ClampWidth(work, line, lineEnd, key);
        }
        work->lineOffset = work->lineOffset + step;
        return 0;
    } else if (key == FIELD_RAIL_KEY_TurnRight(line->key)) {
        FIELD_RAIL_WORK_MoveClamped(work->closedLines, work, 0, step, key);
        if (work->widthOffset > 0 && work->widthOffset % 16 == 0) {
            RailPoint *point;
            RailLine *lineAhead;
            RailPoint *farPoint;
            RailLine *farLine;

            point = FIELD_RAIL_SETTING_GetPoint(work->setting, line->startPoint);
            lineAhead = FIELD_RAIL_POINT_FindLine(point, key, work->setting, work->closedLines, 0);
            if (lineAhead != 0) {
                if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, lineAhead, point)) {
                    int lineLength;
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                    lineLength = FIELD_RAIL_LINE_GetLength(lineAhead, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(lineAhead, work->widthOffset, lineLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, lineAhead, key, work->widthOffset, -work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, lineAhead, point)) {
                    int lineLength;
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                    lineLength = FIELD_RAIL_LINE_GetLength(lineAhead, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(lineAhead, lineLength - work->widthOffset, lineLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, lineAhead, key, lineLength - work->widthOffset, work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
            farPoint = FIELD_RAIL_SETTING_GetPoint(work->setting, line->endPoint);
            farLine = FIELD_RAIL_POINT_FindLine(farPoint, key, work->setting, work->closedLines, 0);
            if (farLine != 0) {
                if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, farLine, farPoint)) {
                    int lineLength;
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(farPoint, work->setting);
                    lineLength = FIELD_RAIL_LINE_GetLength(farLine, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(farLine, work->widthOffset, lineLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, farLine, key, work->widthOffset, lineEnd - work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, farLine, farPoint)) {
                    int lineLength;
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(farPoint, work->setting);
                    lineLength = FIELD_RAIL_LINE_GetLength(farLine, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(farLine, lineLength - work->widthOffset, lineLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, farLine, key, lineLength - work->widthOffset, -(lineEnd - work->lineOffset), lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
        }
        if (work->widthOffset > 0 && work->widthOffset <= work->widthLimit) {
            return FIELD_RAIL_WORK_ClampWidth(work, line, lineEnd, key);
        }
        return key;
    } else if (key == FIELD_RAIL_KEY_TurnLeft(line->key)) {
        FIELD_RAIL_WORK_MoveClamped(work->closedLines, work, 0, -step, key);
        if (work->widthOffset < 0 && (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset) % 16 == 0) {
            RailPoint *point;
            RailLine *lineAhead;
            RailPoint *farPoint;
            RailLine *farLine;
            int farLength;
            int aheadLength;

            point = FIELD_RAIL_SETTING_GetPoint(work->setting, line->startPoint);
            lineAhead = FIELD_RAIL_POINT_FindLine(point, key, work->setting, work->closedLines, 0);
            if (lineAhead != 0) {
                if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, lineAhead, point)) {
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                    aheadLength = FIELD_RAIL_LINE_GetLength(lineAhead, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(lineAhead, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), aheadLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, lineAhead, key, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), work->lineOffset, aheadLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, lineAhead, point)) {
                    int lineLength;
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(point, work->setting);
                    lineLength = FIELD_RAIL_LINE_GetLength(lineAhead, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(lineAhead, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), lineLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, lineAhead, key, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), -work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
            farPoint = FIELD_RAIL_SETTING_GetPoint(work->setting, line->endPoint);
            farLine = FIELD_RAIL_POINT_FindLine(farPoint, key, work->setting, work->closedLines, 0);
            if (farLine != 0) {
                if (FIELD_RAIL_LINE_StartsAtPoint(work->setting, farLine, farPoint)) {
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(farPoint, work->setting);
                    farLength = FIELD_RAIL_LINE_GetLength(farLine, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(farLine, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), farLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, farLine, key, (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), -(lineEnd - work->lineOffset), farLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
                if (FIELD_RAIL_LINE_EndsAtPoint(work->setting, farLine, farPoint)) {
                    int lineLength;
                    int widthMax;
                    FIELD_RAIL_POINT_IsConsistent(farPoint, work->setting);
                    lineLength = FIELD_RAIL_LINE_GetLength(farLine, work->unitScale, work->setting);
                    widthMax = FIELD_RAIL_LINE_GetWidthAt(farLine, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), lineLength, work->setting);
                    result = FIELD_RAIL_WORK_TryEnterLine(work, farLine, key, lineLength - (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset), lineEnd - work->lineOffset, lineLength, widthMax);
                    if (result != 0) {
                        return result;
                    }
                }
            }
        }
        if (work->widthOffset < 0 && (work->widthOffset < 0 ? -work->widthOffset : work->widthOffset) <= work->widthLimit) {
            return FIELD_RAIL_WORK_ClampWidth(work, line, lineEnd, key);
        }
        return key;
    }
    return 0;
}

/*
 * The mode value 2 is an enum-typed local initialised at declaration: the enum
 * keeps it out of constant propagation, so it is materialised at entry, overlaps
 * setting and the loaded unitScale (r1) and takes r3, which the later zero then reuses.
 */
void FIELD_RAIL_WORK_Init(RailWork *work, FieldRailSetting *setting, RailManager *manager)
{
    RailWorkMode mode = RAIL_WORK_UNSET;
    work->setting = setting;
    work->unitScale = setting->unitScale;
    work->mode = mode;
    work->lastSpeedIndex = 0;
    work->lastKey = 0;
    work->moving = 0;
    work->manager = manager;
    work->spot = 0;
    work->lineOffset = 0;
    work->widthOffset = 0;
    work->moveKey = 0;
    work->closedLines = &manager->closedLines;
    work->queryValid = 0;
    work->located = 0;
}

void FIELD_RAIL_WORK_Reset(RailWork *work, FieldRailSetting *setting)
{
    FIELD_RAIL_WORK_Init(work, setting, work->manager);
}

u16 FIELD_RAIL_WORK_IsInUse(RailWork *work)
{
    return work->inUse;
}

int FIELD_RAIL_WORK_IsActive(RailWork *work)
{
    if (work->mode < 2) {
        if (work->spot != 0) {
            if (work->inUse != 0) {
                return 1;
            }
        }
    }
    return 0;
}

RailCamera *FIELD_RAIL_WORK_GetSpotCamera(RailWork *work)
{
    switch (work->mode) {
    case 0:
        return FIELD_RAIL_SETTING_GetCamera(work->setting, work->spot->point.cameraIndex);
    case 1:
        return FIELD_RAIL_SETTING_GetCamera(work->setting, work->spot->line.cameraIndex);
    }
    return &gRailDefaultCamera;
}

void FIELD_RAIL_WORK_GetSpotPos(RailWork *work, VecFx32 *outPos)
{
    RailLinePosFunc linePosFunc;

    if (work->mode == 0) {
        *outPos = work->spot->point.pos;
        return;
    }
    if (work->mode == 1) {
        RailLinePos *linePos = FIELD_RAIL_SETTING_GetLinePos(work->setting, work->spot->line.linePosIndex);
        linePosFunc = FIELD_RAIL_SETTING_GetLinePosFunc(work->setting, linePos->funcIndex);
        if (linePosFunc)
            linePosFunc(work, outPos);
    }
}

void FIELD_RAIL_WORK_GetLocationFromSpot(const RailWork *work, RailLocation *outLocation)
{
    int railIndex;
    u32 mode;

    mode = work->mode;
    outLocation->type = mode;
    if (mode == 0)
        railIndex = FIELD_RAIL_SETTING_GetPointIndex(work->setting, &work->spot->point);
    else
        railIndex = FIELD_RAIL_SETTING_GetLineIndex(work->setting, &work->spot->line);
    outLocation->railIndex = railIndex;
    outLocation->lineGrid = work->lineOffset / 16;
    outLocation->widthGrid = work->widthOffset / 16;
    outLocation->key = work->moveKey;
}

int FIELD_RAIL_LINE_GetLength(const RailLine *line, int unitScale, const FieldRailSetting *setting)
{
    return (line->length << 4);
}

int FIELD_RAIL_LINE_GetWidthAt(const RailLine *line, u32 offset, u32 length, const FieldRailSetting *setting)
{
    RailPoint *startPoint = &setting->points[line->startPoint];
    RailPoint *endPoint = &setting->points[line->endPoint];
    int startWidth;
    int endWidth;
    int width;
    int i;

    endWidth = -1;
    startWidth = -1;
    for (i = 0; i < 4; i++) {
        u32 startLineIndex = startPoint->lineIndex[i];
        if (startLineIndex != RAIL_NONE_INDEX) {
            if (line == setting->lines + startLineIndex)
                startWidth = startPoint->lineWidth[i];
        }
        {
            u32 endLineIndex = endPoint->lineIndex[i];
            if (endLineIndex != RAIL_NONE_INDEX) {
                if (line == setting->lines + endLineIndex)
                    endWidth = endPoint->lineWidth[i];
            }
        }
    }
    if (startWidth < 0)
        startWidth = endWidth;
    if (endWidth < 0)
        endWidth = startWidth;
    if (offset > length - 0x10)
        offset = length - 0x10;
    width = endWidth - startWidth;
    if (length - 0x10 != 0)
        width = (int)((u32)width * offset) / (int)(length - 0x10);
    return width + startWidth;
}

int FIELD_RAIL_WORK_ClampWidth(RailWork *work, RailLine *line, u32 lineEnd, int key)
{
    int limit = FIELD_RAIL_LINE_GetWidthAt(line, work->lineOffset, lineEnd, work->setting);
    int width = work->widthOffset;

    work->widthLimit = limit;
    if ((width < 0 ? -width : width) >= limit) {
        if (width > 0)
            work->widthOffset = limit;
        else
            work->widthOffset = -limit;
    }
    return key;
}

int FIELD_RAIL_ProbeStep(RailManager *manager, RailLocation *location, u32 key, int steps, VecFx32 *outPos)
{
    int i;

    FIELD_RAIL_WORK_SetLocation(manager->probeWork, location);
    FIELD_RAIL_WORK_StartStep(manager->probeWork, 4, key);
    FIELD_RAIL_WORK_UpdateStep(manager->probeWork);
    FIELD_RAIL_WORK_StartStep(manager->probeWork, 0, key);
    for (i = 0; i < 16; i++) {
        if (steps == i)
            FIELD_RAIL_WORK_GetPos(manager->probeWork, outPos);
        FIELD_RAIL_WORK_UpdateStep(manager->probeWork);
    }
    if (GF_STANDARD_CompareBytes((u8 *)location, (u8 *)(&manager->probeWork->location), 8) == 0)
        return 0;
    return FIELD_RAIL_WORK_IsLocationValid(manager->probeWork, &manager->probeWork->location);
}

int FIELD_RAIL_KEY_Opposite(int key)
{
    switch (key) {
    case 1: return 3;
    case 3: return 1;
    case 4: return 2;
    case 2: return 4;
    }
    return 0;
}

int FIELD_RAIL_KEY_TurnRight(int key)
{
    switch (key) {
    case 1: return 2;
    case 3: return 4;
    case 4: return 1;
    case 2: return 3;
    }
    return 0;
}

int FIELD_RAIL_KEY_TurnLeft(int key)
{
    switch (key) {
    case 1: return 4;
    case 3: return 2;
    case 4: return 3;
    case 2: return 1;
    }
    return 0;
}

RailClosedLines *FIELD_RAIL_CLOSED_Clear(RailClosedLines *closedLines)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        closedLines->lineIndex[i] = RAIL_NONE_INDEX;
    }
    return closedLines;
}

void FIELD_RAIL_CLOSED_Add(RailClosedLines *closedLines, u16 lineIndex)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (closedLines->lineIndex[i] == RAIL_NONE_INDEX) {
            closedLines->lineIndex[i] = lineIndex;
            return;
        }
    }
}

void FIELD_RAIL_CLOSED_Remove(RailClosedLines *closedLines, u16 lineIndex)
{
    int i;

    for (i = 0; i < 0x12; i++) {
        if (lineIndex == closedLines->lineIndex[i]) {
            closedLines->lineIndex[i] = RAIL_NONE_INDEX;
            return;
        }
    }
}

int FIELD_RAIL_CLOSED_Contains(RailClosedLines *closedLines, u16 lineIndex)
{
    int i;
    for (i = 0; i < 0x12; i++)
        if (closedLines->lineIndex[i] == lineIndex)
            return 1;
    return 0;
}

/*
 * The line count is a volatile u16: the original reads it once for the
 * loop entry guard and again on every bottom test, while the array base is
 * hoisted.  A plain u16 count is CSEd into one register (6 bytes shorter).
 */
int FIELD_RAIL_CLOSED_ContainsLine(RailClosedLines *closedLines, RailLine *line, FieldRailSetting *setting)
{
    int i;
    int found = 0;
    for (i = 0; i < setting->lineCount; i++) {
        if (line == &setting->lines[i])
            found = i;
    }
    return FIELD_RAIL_CLOSED_Contains(closedLines, found);
}

RailLine *FIELD_RAIL_GetOpenLine(RailClosedLines *closedLines, FieldRailSetting *setting, u32 lineIndex)
{
    if (FIELD_RAIL_CLOSED_Contains(closedLines, (u16)lineIndex) == 0)
        return FIELD_RAIL_SETTING_GetLine(setting, lineIndex);
    return 0;
}

void FIELD_RAIL_WORK_MoveClamped(RailClosedLines *closedLines, RailWork *work, int lineDelta, int widthDelta, int key)
{
    if (FIELD_RAIL_CLOSED_ContainsLine(closedLines, &work->spot->line, work->setting) != 0) {
        RailPoint *point = FIELD_RAIL_SETTING_GetPoint(work->setting, work->spot->line.startPoint);
        RailLine *nextLine = FIELD_RAIL_POINT_FindLine(point, key, work->setting, closedLines, 0);
        int lengthLimit, widthLimit;

        FIELD_RAIL_GetNeighbourLimits(work->setting, &work->spot->line, &lengthLimit, &widthLimit, closedLines, work->unitScale);
        work->lineOffset += lineDelta;
        work->widthOffset += widthDelta;
        if (work->lineOffset > lengthLimit)
            work->lineOffset = lengthLimit;
        if (nextLine == 0) {
            int width = work->widthOffset;
            int absWidth = width < 0 ? -width : width;
            if (absWidth > widthLimit) {
                if (width > 0)
                    work->widthOffset = widthLimit;
                else
                    work->widthOffset = -widthLimit;
            }
        }
        return;
    }
    work->lineOffset += lineDelta;
    work->widthOffset += widthDelta;
}

int FIELD_RAIL_IsLocationInLine(RailClosedLines *closedLines, RailLine *line, int lineOffset, int widthOffset,
                  FieldRailSetting *setting, int unitScale)
{
    int lengthLimit, widthLimit;

    if (FIELD_RAIL_CLOSED_ContainsLine(closedLines, line, setting) == 0)
        goto ok;
    FIELD_RAIL_GetNeighbourLimits(setting, line, &lengthLimit, &widthLimit, closedLines, unitScale);
    if (lineOffset > lengthLimit)
        goto fail;
    if (widthOffset < 0)
        widthOffset = -widthOffset;
    if (widthOffset > widthLimit)
        goto fail;
    return 1;
fail:
    return 0;
ok:
    return 1;
}

u32 FIELD_RAIL_POINT_GetLineKey(RailPoint *point, RailLine *line, FieldRailSetting *setting)
{
    int i;
    RailLine *pointLine;
    for (i = 0; i < 4; i++) {
        pointLine = FIELD_RAIL_SETTING_GetLine(setting, point->lineIndex[i]);
        if (pointLine == line)
            return point->lineKey[i];
    }
    return 0;
}

int FIELD_RAIL_LINE_IsConsistent(RailLine *line, FieldRailSetting *setting)
{
    RailPoint *startPoint, *endPoint;
    u32 startKey, endKey;

    if (line->startPoint == RAIL_NONE_INDEX || line->endPoint == RAIL_NONE_INDEX)
        return 0;
    startPoint = FIELD_RAIL_SETTING_GetPoint(setting, line->startPoint);
    endPoint = FIELD_RAIL_SETTING_GetPoint(setting, line->endPoint);
    startKey = FIELD_RAIL_POINT_GetLineKey(startPoint, line, setting);
    if (startKey == 0)
        return 0;
    if (startKey != line->key)
        return 0;
    endKey = FIELD_RAIL_POINT_GetLineKey(endPoint, line, setting);
    if (endKey == 0)
        return 0;
    if (endKey != (u32)FIELD_RAIL_KEY_Opposite(line->key))
        return 0;
    return 1;
}

int FIELD_RAIL_POINT_IsConsistent(RailPoint *point, FieldRailSetting *setting)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        u32 lineKey = point->lineKey[i];
        u32 lineIndex = point->lineIndex[i];
        RailLine *line;
        RailPoint *startPoint;
        RailPoint *endPoint;

        if ((lineKey == 0) != (lineIndex == RAIL_NONE_INDEX))
            return 0;
        if (lineIndex == RAIL_NONE_INDEX)
            continue;
        line = FIELD_RAIL_SETTING_GetLine(setting, lineIndex);
        startPoint = FIELD_RAIL_SETTING_GetPoint(setting, line->startPoint);
        endPoint = FIELD_RAIL_SETTING_GetPoint(setting, line->endPoint);
        if (startPoint != point && endPoint != point)
            return 0;
        if (point->lineKey[i] == 0)
            continue;
        for (j = i + 1; j < 4; j++) {
            if (point->lineKey[i] == (u32)FIELD_RAIL_KEY_Opposite(point->lineKey[j])) {
                if (line->key != FIELD_RAIL_SETTING_GetLine(setting, point->lineIndex[j])->key)
                    return 0;
            }
        }
    }
    return 1;
}

void FIELD_RAIL_DebugPrintPos(const char *label, VecFx32 *pos)
{
}

void FIELD_RAIL_POINT_DebugPrint(const char *prefix, RailPoint *point, const char *suffix)
{
    if (point != 0) {
        FIELD_RAIL_DebugPrintPos(prefix, &point->pos);
    }
}

void FIELD_RAIL_WORK_DebugCheck(RailWork *work)
{
    RailPoint *startPoint;
    RailPoint *endPoint;

    if (work->mode == 0) {
        FIELD_RAIL_POINT_DebugPrint(0, &work->spot->point, d_021DE2B0);
    } else if (work->mode == 1) {
        startPoint = FIELD_RAIL_SETTING_GetPoint(work->setting, work->spot->line.startPoint);
        endPoint = FIELD_RAIL_SETTING_GetPoint(work->setting, work->spot->line.endPoint);
        FIELD_RAIL_POINT_DebugPrint(d_021DE2B4, startPoint, 0);
        FIELD_RAIL_POINT_DebugPrint(d_021DE2BC, endPoint, d_021DE2B0);
    }
}

int FIELD_RAIL_SETTING_GetPointIndex(FieldRailSetting *setting, RailPoint *point)
{
    int i;

    for (i = 0; i < setting->pointCount; i++) {
        if (point == &setting->points[i]) {
            return i;
        }
    }
    return 0;
}

/*
 * 2026-10-02: the per-iteration reload of the count (ldrh in the loop) that
 * kept the earlier draft at DIFF comes from a volatile count field; every
 * non-volatile spelling hoists it like FIELD_RAIL_SETTING_GetPointIndex.
 */
int FIELD_RAIL_SETTING_GetLineIndex(FieldRailSetting *setting, RailLine *line)
{
    int i;

    for (i = 0; i < setting->lineCount; i++) {
        if (line == &setting->lines[i]) {
            return i;
        }
    }
    return 0;
}

static inline int FX_Mul(int a, int b)
{
    return (int)(((long long)a * b + 0x800LL) >> 12);
}

static inline void VEC_Set(VecFx32 *v, fx32 x, fx32 y, fx32 z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

/*
 * Segment/plane intersection: the plane through planePoint spanned by dirA and
 * dirB, the segment from segStart to segEnd; writes the hit point to out and
 * returns 1.
 * The hit point is computed z, y, x and stored x, y, z: an inline VEC_Set
 * evaluates its arguments last to first
 * (docs/idioms/an-inline-wrappers-arguments-are-evaluated-last-to-first.md).
 *
 * Addresses are Black-image addresses.
 */
int FIELD_RAIL_IntersectSegmentPlane(VecFx32 *dirA, VecFx32 *dirB, VecFx32 *planePoint, VecFx32 *segStart, VecFx32 *segEnd,
                  VecFx32 *out)
{
    VecFx32 normal;
    VecFx32 segDir;
    VecFx32 unitA;
    VecFx32 unitB;
    int segLength;
    int numerator;
    int denominator;
    int hitDist;

    VEC_Subtract(segEnd, segStart, &segDir);
    segLength = VEC_Mag(&segDir);
    VEC_Normalize(&segDir, &segDir);
    VEC_Normalize(dirA, &unitA);
    VEC_Normalize(dirB, &unitB);
    VEC_CrossProduct(&unitA, &unitB, &normal);
    VEC_Normalize(&normal, &normal);
    numerator = (FX_Mul(normal.x, planePoint->x) + FX_Mul(normal.y, planePoint->y) + FX_Mul(normal.z, planePoint->z))
        - (FX_Mul(normal.x, segStart->x) + FX_Mul(normal.y, segStart->y) + FX_Mul(normal.z, segStart->z));
    denominator = FX_Mul(normal.x, segDir.x) + FX_Mul(normal.y, segDir.y) + FX_Mul(normal.z, segDir.z);
    if (denominator == 0) {
        return 0;
    }
    hitDist = FX_Div(numerator, denominator);
    if (hitDist > segLength) {
        return 0;
    }
    if (hitDist <= 0x1000) {
        return 0;
    }
    VEC_Set(out, segStart->x + FX_Mul(segDir.x, hitDist), segStart->y + FX_Mul(segDir.y, hitDist),
            segStart->z + FX_Mul(segDir.z, hitDist));
    return 1;
}

void FIELD_RAIL_SlerpDir(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t)
{
    VecFx32 unitFrom;
    VecFx32 unitTo;
    u16 angle;
    int sinAngle;
    int angleFx;

    VEC_Normalize(from, &unitFrom);
    VEC_Normalize(to, &unitTo);
    angle = FX_AcosIdx(VEC_DotProduct(&unitFrom, &unitTo));
    sinAngle = ((u16 *)FX_SinCosTable_)[(angle >> 4) * 2];
    if (sinAngle == 0) {
        *out = unitTo;
        return;
    }
    angleFx = angle << 12;
    BUTTON_MAN_ScaleVec(&unitFrom, FX_Div(((u16 *)FX_SinCosTable_)[(FX_Mul(angleFx, FX32_ONE - t) >> 16) * 2], sinAngle), &unitFrom);
    BUTTON_MAN_ScaleVec(&unitTo, FX_Div(((u16 *)FX_SinCosTable_)[(FX_Mul(angleFx, t) >> 16) * 2], sinAngle), &unitTo);
    VEC_Add(&unitFrom, &unitTo, out);
    VEC_Normalize(out, out);
}

void FIELD_RAIL_SlerpVec(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t)
{
    VecFx32 origin = {0, 0, 0};
    int lengthFrom;
    int lengthTo;
    int lengthDiff;

    FIELD_RAIL_SlerpDir(out, from, to, t);
    lengthFrom = VEC_Mag(from);
    lengthTo = VEC_Mag(to);
    lengthDiff = lengthTo - lengthFrom;
    VEC_MultAdd(lengthFrom + (int)(((s64)lengthDiff * t + 0x800) >> 12), out, &origin, out);
}

void FIELD_RAIL_LINEPOS_Straight(RailWork *work, VecFx32 *outPos)
{
    VecFx32 delta;
    VecFx32 up;
    VecFx32 side;
    int progress;
    RailPoint *startPoint;
    RailPoint *endPoint;
    VecFx32 *startPos;
    int widthOffset;
    int unitScale;

    FIELD_RAIL_WORK_GetSpot(work);
    progress = FX_Div(FIELD_RAIL_WORK_GetLineOffset(work) << 12, FIELD_RAIL_WORK_GetLineEndOffset(work) << 12);
    startPoint = FIELD_RAIL_WORK_GetStartPoint(work);
    endPoint = FIELD_RAIL_WORK_GetEndPoint(work);
    startPos = &startPoint->pos;
    VEC_Subtract(&endPoint->pos, startPos, &delta);
    VEC_MultAdd(progress, &delta, startPos, outPos);
    up = d_021D9A54;
    widthOffset = FIELD_RAIL_WORK_GetWidthOffsetRaw(work);
    unitScale = FIELD_RAIL_WORK_GetUnitScale(work);
    VEC_CrossProduct(&delta, &up, &side);
    VEC_Normalize(&side, &side);
    VEC_MultAdd((int)(((s64)(widthOffset << 12) * unitScale + 0x800) >> 12), &side, outPos, outPos);
}

void FIELD_RAIL_LINEPOS_ArcFlat(RailWork *work, VecFx32 *outPos)
{
    VecFx32 centre;
    VecFx32 fromStart;
    VecFx32 fromEnd;
    VecFx32 axis;
    VecFx32 dir;
    VecFx32 radial;
    VecFx32 side;
    int progress;
    int lineEnd;
    int lineOffset;
    VecFx32 *startPos;
    VecFx32 *endPos;
    RailLinePos *linePos;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int offset;

    FIELD_RAIL_WORK_GetSpot(work);
    startPoint = FIELD_RAIL_WORK_GetStartPoint(work);
    endPoint = FIELD_RAIL_WORK_GetEndPoint(work);
    startPos = &startPoint->pos;
    endPos = &endPoint->pos;
    lineOffset = FIELD_RAIL_WORK_GetLineOffset(work);
    lineEnd = FIELD_RAIL_WORK_GetLineEndOffset(work);
    progress = FX_Div((int)((u32)lineOffset << 12), (int)((u32)lineEnd << 12));
    outPos->y = endPos->y - startPos->y;
    outPos->y = FX_Div(FX_Mul(outPos->y, lineOffset << 12), lineEnd << 12);
    outPos->y += startPos->y;
    linePos = FIELD_RAIL_WORK_GetLinePos(work);
    centre.x = linePos->pos.x;
    centre.y = outPos->y;
    centre.z = linePos->pos.z;
    VEC_Subtract(startPos, &centre, &fromStart);
    VEC_Subtract(endPos, &centre, &fromEnd);
    fromStart.y = 0;
    fromEnd.y = 0;
    VEC_Subtract(&fromEnd, &fromStart, &dir);
    dir.y = 0;
    VEC_Normalize(&dir, &dir);
    FIELD_RAIL_SlerpVec(&axis, &fromStart, &fromEnd, progress);
    VEC_Add(&centre, &axis, outPos);
    offset = (int)(((s64)((int)FIELD_RAIL_WORK_GetWidthOffsetRaw(work) << 12) * (int)FIELD_RAIL_WORK_GetUnitScale(work) + 0x800) >> 12);
    VEC_Normalize(&axis, &radial);
    VEC_CrossProduct(&radial, &dir, &side);
    if (side.y < 0) {
        VEC_MultAdd(-offset, &radial, outPos, outPos);
    } else {
        VEC_MultAdd(offset, &radial, outPos, outPos);
    }
}

void FIELD_RAIL_LINEPOS_Arc(RailWork *work, VecFx32 *outPos)
{
    VecFx32 centre;
    VecFx32 fromStart;
    VecFx32 fromEnd;
    VecFx32 axis;
    VecFx32 dir;
    VecFx32 radial;
    VecFx32 side;
    VecFx32 up;
    int progress;
    VecFx32 *startPos;
    VecFx32 *endPos;
    RailLinePos *linePos;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int offset;

    FIELD_RAIL_WORK_GetSpot(work);
    startPoint = FIELD_RAIL_WORK_GetStartPoint(work);
    endPoint = FIELD_RAIL_WORK_GetEndPoint(work);
    startPos = &startPoint->pos;
    endPos = &endPoint->pos;
    progress = FX_Div(FIELD_RAIL_WORK_GetLineOffset(work) << 12, FIELD_RAIL_WORK_GetLineEndOffset(work) << 12);
    linePos = FIELD_RAIL_WORK_GetLinePos(work);
    centre.x = linePos->pos.x;
    centre.y = linePos->pos.y;
    centre.z = linePos->pos.z;
    VEC_Subtract(startPos, &centre, &fromStart);
    VEC_Subtract(endPos, &centre, &fromEnd);
    VEC_Subtract(&fromEnd, &fromStart, &dir);
    VEC_Normalize(&dir, &dir);
    FIELD_RAIL_SlerpVec(&axis, &fromStart, &fromEnd, progress);
    VEC_Add(&centre, &axis, outPos);
    offset = (int)(((s64)((int)FIELD_RAIL_WORK_GetWidthOffsetRaw(work) << 12) * (int)FIELD_RAIL_WORK_GetUnitScale(work) + 0x800) >> 12);
    if (axis.x != 0 && axis.z != 0) {
        axis.y = 0;
    } else {
        up = d_021D9A60;
        VEC_Subtract(endPos, startPos, &axis);
        VEC_CrossProduct(&axis, &up, &axis);
    }
    VEC_Normalize(&axis, &radial);
    VEC_CrossProduct(&radial, &dir, &side);
    if (side.y < 0) {
        VEC_MultAdd(-offset, &radial, outPos, outPos);
    } else {
        VEC_MultAdd(offset, &radial, outPos, outPos);
    }
}

/*
 * Builds the 8-byte location on line `lineIndex` at pos between the two points of the
 * line (FIELD_RAIL_GetLine): horizontal distance and height offset scaled by
 * FIELD_RAIL_GetUnitScaleRaw and rounded by FIELD_RAIL_RoundToGrid; returns 0 when out of range,
 * else 1 when the location round-trips unchanged through FIELD_RAIL_ClampLocation and
 * FIELD_RAIL_GetLocationPos.
 * pos->x and pos->z go through locals: stored straight into flatPos, the y = 0
 * stores interleave with them and the loads split; the out-of-range
 * `return 0` is the fall-out of an if around the rest (it sits after the
 * final epilogue). The spill slots follow startWidth, endWidth, length, dist, diff declared
 * in that order.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_RAIL_LINEFUNC_Straight(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos)
{
    VecFx32 hitPos;
    VecFx32 axis;
    VecFx32 flatPos;
    VecFx32 flatHit;
    int hitDist;
    RailLocation checkLocation;
    RailLine *line;
    int unitScale;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int startWidth;
    int endWidth;
    u32 length;
    u32 dist;
    int diff;
    int i;
    int x;
    int z;

    line = FIELD_RAIL_GetLine(manager, lineIndex);
    startPoint = FIELD_RAIL_GetPoint(manager, line->startPoint);
    endPoint = FIELD_RAIL_GetPoint(manager, line->endPoint);
    unitScale = FIELD_RAIL_GetUnitScaleRaw(manager);
    if (FIELD_RAIL_ProjectOnSegment(startPoint, endPoint, pos, &hitPos, &hitDist, &axis) == 0) {
        return 0;
    }
    x = pos->x;
    z = pos->z;
    flatPos.x = x;
    flatHit.x = hitPos.x;
    flatPos.z = z;
    flatHit.z = hitPos.z;
    flatPos.y = 0;
    flatHit.y = 0;
    dist = FX_Div(VEC_Distance(&flatPos, &flatHit), unitScale) >> 12;
    FIELD_RAIL_GetLinePos(manager, line->linePosIndex);
    length = line->length << 4;
    diff = length - (FX_Div(hitDist, unitScale) >> 12);
    for (i = 0; i < 4; i++) {
        if (lineIndex == startPoint->lineIndex[i]) {
            startWidth = startPoint->lineWidth[i];
        }
        if (lineIndex == endPoint->lineIndex[i]) {
            endWidth = endPoint->lineWidth[i];
        }
    }
    if (dist <= startWidth + (endWidth - startWidth) * diff / length + 0x10) {
        outLocation->railIndex = lineIndex;
        outLocation->type = 1;
        outLocation->key = 3;
        if (axis.y >= 0) {
            outLocation->widthGrid = FIELD_RAIL_RoundToGrid(dist);
        } else {
            outLocation->widthGrid = -FIELD_RAIL_RoundToGrid(dist);
        }
        outLocation->lineGrid = FIELD_RAIL_RoundToGrid(diff);
        FIELD_RAIL_ClampLocation(manager, outLocation, &checkLocation);
        FIELD_RAIL_GetLocationPos(manager, &checkLocation, outPos);
        if (GF_STANDARD_CompareBytes((u8 *)outLocation, (u8 *)(&checkLocation), 8) == 0) {
            return 1;
        }
        return 0;
    }
    return 0;
}

int FIELD_RAIL_LINEFUNC_Arc(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos)
{
    VecFx32 curPos;
    VecFx32 prevPos;
    VecFx32 segment;
    VecFx32 toPos;
    VecFx32 segmentDir;
    VecFx32 hitPos;
    VecFx32 axis;
    VecFx32 flatPos;
    VecFx32 flatHit;
    VecFx32 unitSegment;
    VecFx32 unitToPos;
    int hitDist;
    RailLocation checkLocation;
    int segmentLength;
    u32 widthLimit;
    u32 cellCount;
    int unitScale;
    u32 cell;
    RailLine *line;
    RailPoint *startPoint;
    RailPoint *endPoint;
    RailWork *probe;
    int toPosLength;
    int ratio;
    int along;
    int alongScaled;
    u32 dist;
    int x;
    int z;

    line = FIELD_RAIL_GetLine(manager, lineIndex);
    startPoint = FIELD_RAIL_GetPoint(manager, line->startPoint);
    endPoint = FIELD_RAIL_GetPoint(manager, line->endPoint);
    if (FIELD_RAIL_ProjectOnSegment(startPoint, endPoint, pos, &hitPos, &hitDist, &axis) == 0) {
        return 0;
    }
    outLocation->railIndex = lineIndex;
    outLocation->type = 1;
    outLocation->key = 3;
    outLocation->widthGrid = 0;
    outLocation->lineGrid = 0;
    probe = FIELD_RAIL_GetProbeWork(manager);
    FIELD_RAIL_WORK_SetLocation(probe, outLocation);
    cellCount = FIELD_RAIL_WORK_GetLineEndOffset(probe) >> 4;
    FIELD_RAIL_WORK_GetPos(probe, &curPos);
    prevPos.x = curPos.x;
    prevPos.y = curPos.y;
    prevPos.z = curPos.z;
    unitScale = FIELD_RAIL_GetUnitScaleRaw(manager);
    for (cell = 1; cell < cellCount; cell++) {
        outLocation->lineGrid = cell;
        FIELD_RAIL_WORK_SetLocation(probe, outLocation);
        FIELD_RAIL_WORK_GetPos(probe, &curPos);
        widthLimit = FIELD_RAIL_WORK_GetWidthLimit(probe);
        VEC_Subtract(&prevPos, &curPos, &segment);
        VEC_Subtract(pos, &curPos, &toPos);
        VEC_Normalize(&segment, &segmentDir);
        segmentLength = VEC_Mag(&segment);
        VEC_Normalize(&segment, &unitSegment);
        VEC_Normalize(&toPos, &unitToPos);
        VEC_CrossProduct(&unitSegment, &unitToPos, &axis);
        segment = segmentDir;
        toPosLength = VEC_Mag(&toPos);
        VEC_Normalize(&toPos, &toPos);
        ratio = FX_Div(toPosLength, segmentLength);
        toPos.x = FX_Mul(toPos.x, ratio);
        toPos.y = FX_Mul(toPos.y, ratio);
        toPos.z = FX_Mul(toPos.z, ratio);
        along = VEC_DotProduct(&segment, &toPos);
        if (along <= 0x1000 && along >= 0) {
            alongScaled = FX_Mul(along, segmentLength);
            hitPos.x = FX_Mul(segmentDir.x, alongScaled);
            hitPos.y = FX_Mul(segmentDir.y, alongScaled);
            hitPos.z = FX_Mul(segmentDir.z, alongScaled);
            VEC_Add(&curPos, &hitPos, &hitPos);
            x = pos->x;
            z = pos->z;
            flatPos.x = x;
            flatPos.z = z;
            flatPos.y = 0;
            flatHit.x = hitPos.x;
            flatHit.y = 0;
            flatHit.z = hitPos.z;
            dist = FX_Div(VEC_Distance(&flatPos, &flatHit), unitScale) >> 12;
            widthLimit += 0x10;
            if (widthLimit >= dist) {
                if (axis.y >= 0) {
                    outLocation->widthGrid = FIELD_RAIL_RoundToGrid(dist);
                } else {
                    outLocation->widthGrid = -FIELD_RAIL_RoundToGrid(dist);
                }
                FIELD_RAIL_ClampLocation(manager, outLocation, &checkLocation);
                FIELD_RAIL_GetLocationPos(manager, outLocation, outPos);
                if (GF_STANDARD_CompareBytes((u8 *)outLocation, (u8 *)(&checkLocation), 8) == 0) {
                    return 1;
                }
                return 0;
            }
        }
        prevPos.x = curPos.x;
        prevPos.y = curPos.y;
        prevPos.z = curPos.z;
    }
    return 0;
}

void FIELD_RAIL_CAMERA_EyeOffsetFromFocus(RailManager *manager)
{
    VecFx32 eye;
    RailCamera *camera;

    camera = FIELD_RAIL_WORK_GetCamera(FIELD_RAIL_GetFocusWork(manager));
    FIELD_RAIL_GetFocusPos(manager, &eye);
    FIELD_CAMERA_EnterMode(FIELD_RAIL_GetFieldCamera(manager), 2);
    eye.x += camera->param[0];
    eye.y += camera->param[1];
    eye.z += camera->param[2];
    FIELD_CAMERA_SetEyeRaw(FIELD_RAIL_GetFieldCamera(manager), &eye);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
}

void FIELD_RAIL_CAMERA_FixedAngle(RailManager *manager)
{
    VecFx32 focusPos;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;
    u16 pitch, yaw;
    u32 distance;

    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    camera = FIELD_RAIL_WORK_GetCamera(FIELD_RAIL_GetFocusWork(manager));
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    FIELD_RAIL_GetFocusPos(manager, &focusPos);
    pitch = camera->param[0];
    yaw = camera->param[1];
    distance = camera->param[2];
    FIELD_CAMERA_SetYaw(fieldCamera, yaw);
    FIELD_CAMERA_SetPitch(fieldCamera, pitch);
    FIELD_CAMERA_SetDistance(fieldCamera, distance);
}

void FIELD_RAIL_CAMERA_FixedAngleAtCentre(RailManager *manager)
{
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    VecFx32 centrePos;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_RAIL_CAMERA_FixedAngle(manager);
    FIELD_CAMERA_StopTargetTrace(fieldCamera);
    FIELD_RAIL_WORK_GetCentrePos(focusWork, &centrePos);
    FIELD_CAMERA_SetTarget(fieldCamera, &centrePos);
}

/*
 * Twin of FIELD_RAIL_CAMERA_BlendAnglesShift without the vector part.  The angle and scalar
 * locals are int with explicit (u16) casts: as u16 locals the camera0 loads
 * reorder and the ratio stays in a register pair instead of its
 * [sp]/[sp+4] spill.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_RAIL_CAMERA_BlendAngles(RailManager *manager)
{
    RailCamera *camera0;
    RailCamera *camera1;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    struct FieldCamera *fieldCamera;
    int ratio;
    int lineEnd;
    int lineOffset;
    int pitch0;
    int yaw0;
    int distance0;
    int yaw1;
    int distance1;
    int pitchDelta;
    int yawDelta;
    u16 pitch;
    u16 yaw;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    startPoint = FIELD_RAIL_WORK_GetStartPoint(focusWork);
    endPoint = FIELD_RAIL_WORK_GetEndPoint(focusWork);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    camera0 = FIELD_RAIL_WORK_GetPointCamera(focusWork, startPoint);
    camera1 = FIELD_RAIL_WORK_GetPointCamera(focusWork, endPoint);
    lineEnd = FIELD_RAIL_WORK_GetLineEndOffset(focusWork);
    lineOffset = FIELD_RAIL_WORK_GetLineOffset(focusWork);
    ratio = FX_Div(lineOffset << 12, lineEnd << 12);
    pitch0 = (u16)camera0->param[0];
    yaw0 = (u16)camera0->param[1];
    distance0 = camera0->param[2];
    yaw1 = (u16)camera1->param[1];
    distance1 = camera1->param[2];
    pitchDelta = (u16)camera1->param[0] - pitch0;
    if (pitchDelta >= 0x8000)
        pitchDelta -= 0x10000;
    else if (pitchDelta <= -0x8000)
        pitchDelta += 0x10000;
    pitch = pitch0 + (FX_Mul(pitchDelta << 12, ratio) >> 12);
    yawDelta = yaw1 - yaw0;
    if (yawDelta >= 0x8000)
        yawDelta -= 0x10000;
    else if (yawDelta <= -0x8000)
        yawDelta += 0x10000;
    yaw = yaw0 + (FX_Mul(yawDelta << 12, ratio) >> 12);
    FIELD_CAMERA_SetYaw(fieldCamera, yaw);
    FIELD_CAMERA_SetPitch(fieldCamera, pitch);
    FIELD_CAMERA_SetDistance(fieldCamera, distance0 + FX_Mul(distance1 - distance0, ratio));
}

void FIELD_RAIL_CAMERA_BlendAnglesAtFocus(RailManager *manager)
{
    struct FieldCamera *fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    VecFx32 focusPos;

    FIELD_RAIL_CAMERA_BlendAngles(manager);
    FIELD_CAMERA_StopTargetTrace(fieldCamera);
    FIELD_RAIL_GetFocusPos(manager, &focusPos);
    FIELD_CAMERA_SetTarget(fieldCamera, &focusPos);
}

void FIELD_RAIL_CAMERA_BlendAnglesAtCentre(RailManager *manager)
{
    VecFx32 centrePos;
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_RAIL_CAMERA_BlendAngles(manager);
    FIELD_CAMERA_StopTargetTrace(fieldCamera);
    FIELD_RAIL_WORK_GetCentrePos(focusWork, &centrePos);
    FIELD_CAMERA_SetTarget(fieldCamera, &centrePos);
}

void FIELD_RAIL_CAMERA_FixedEyeTarget(RailManager *manager)
{
    VecFx32 eye;
    VecFx32 target;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;

    camera = FIELD_RAIL_WORK_GetCamera(FIELD_RAIL_GetFocusWork(manager));
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 2);
    FIELD_CAMERA_StopTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    eye.x = camera->param[0];
    eye.y = camera->param[1];
    eye.z = camera->param[2];
    target.x = camera->param[3];
    target.y = camera->param[4];
    target.z = camera->param[5];
    FIELD_CAMERA_SetEyeRaw(fieldCamera, &eye);
    FIELD_CAMERA_SetTarget(fieldCamera, &target);
}

void FIELD_RAIL_CAMERA_BlendEyeTarget(RailManager *manager)
{
    VecFx32 eye;
    VecFx32 target;
    RailCamera *camera0;
    RailCamera *camera1;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    struct FieldCamera *fieldCamera;
    int lineEnd;
    int lineOffset;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    startPoint = FIELD_RAIL_WORK_GetStartPoint(focusWork);
    endPoint = FIELD_RAIL_WORK_GetEndPoint(focusWork);
    camera0 = FIELD_RAIL_WORK_GetPointCamera(focusWork, startPoint);
    camera1 = FIELD_RAIL_WORK_GetPointCamera(focusWork, endPoint);
    FIELD_CAMERA_EnterMode(fieldCamera, 2);
    FIELD_CAMERA_StopTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    lineEnd = FIELD_RAIL_WORK_GetLineEndOffset(focusWork);
    lineOffset = FIELD_RAIL_WORK_GetLineOffset(focusWork);
    eye.x = FX_Div(FX_Mul(camera1->param[0] - camera0->param[0], lineOffset << 12), lineEnd << 12);
    eye.y = FX_Div(FX_Mul(camera1->param[1] - camera0->param[1], lineOffset << 12), lineEnd << 12);
    eye.z = FX_Div(FX_Mul(camera1->param[2] - camera0->param[2], lineOffset << 12), lineEnd << 12);
    target.x = FX_Div(FX_Mul(camera1->param[3] - camera0->param[3], lineOffset << 12), lineEnd << 12);
    target.y = FX_Div(FX_Mul(camera1->param[4] - camera0->param[4], lineOffset << 12), lineEnd << 12);
    target.z = FX_Div(FX_Mul(camera1->param[5] - camera0->param[5], lineOffset << 12), lineEnd << 12);
    eye.x += camera0->param[0];
    eye.y += camera0->param[1];
    eye.z += camera0->param[2];
    target.x += camera0->param[3];
    target.y += camera0->param[4];
    target.z += camera0->param[5];
    FIELD_CAMERA_SetEyeRaw(fieldCamera, &eye);
    FIELD_CAMERA_SetTarget(fieldCamera, &target);
}

void FIELD_RAIL_CAMERA_BlendOrbit(RailManager *manager)
{
    VecFx32 point;
    RailCamera *camera0;
    RailCamera *camera1;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    int lineEnd;
    int lineOffset;
    u16 pitch;
    int pitch0;
    int distance;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    FIELD_RAIL_GetFieldCamera(manager);
    if (FIELD_RAIL_WORK_GetMode(focusWork) == 1) {
        startPoint = FIELD_RAIL_WORK_GetStartPoint(focusWork);
        endPoint = FIELD_RAIL_WORK_GetEndPoint(focusWork);
        camera0 = FIELD_RAIL_WORK_GetPointCamera(focusWork, startPoint);
        camera1 = FIELD_RAIL_WORK_GetPointCamera(focusWork, endPoint);
        lineEnd = FIELD_RAIL_WORK_GetLineEndOffset(focusWork);
        lineOffset = FIELD_RAIL_WORK_GetLineOffset(focusWork);
    } else {
        camera0 = FIELD_RAIL_WORK_GetCamera(focusWork);
        camera1 = FIELD_RAIL_WORK_GetCamera(focusWork);
        lineEnd = 1;
        lineOffset = 0;
    }
    pitch0 = camera0->param[0];
    pitch = pitch0 + (camera1->param[0] - pitch0) * lineOffset / lineEnd;
    distance = camera0->param[1] + FX_Div(FX_Mul(camera1->param[1] - camera0->param[1], lineOffset << 12), lineEnd << 12);
    point.x = camera0->param[2];
    point.y = camera0->param[3];
    point.z = camera0->param[4];
    FIELD_RAIL_CAMERA_SetOrbit(manager, pitch, distance, &point);
}

void FIELD_RAIL_CAMERA_Orbit(RailManager *manager)
{
    RailCamera *camera;
    u16 pitch;
    int distance;
    VecFx32 point;

    camera = FIELD_RAIL_WORK_GetCamera(FIELD_RAIL_GetFocusWork(manager));
    pitch = camera->param[0];
    distance = camera->param[1];
    point.x = camera->param[2];
    point.y = camera->param[3];
    point.z = camera->param[4];
    FIELD_RAIL_CAMERA_SetOrbit(manager, pitch, distance, &point);
}

void FIELD_RAIL_CAMERA_SetOrbit(RailManager *manager, u16 pitch, int distance, VecFx32 *point)
{
    VecFx32 toFocus;
    VecFx32 anchor;
    VecFx32 dir;
    VecFx32 eye;
    struct FieldCamera *fieldCamera;
    int anchorY;
    int i;
    int horizontalDist;

    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 2);
    FIELD_CAMERA_StopTargetTrace(fieldCamera);
    anchor = *point;
    anchorY = anchor.y;
    anchor.y = 0;
    FIELD_RAIL_GetFocusPos(manager, &toFocus);
    toFocus.y = 0;
    VEC_Subtract(&toFocus, &anchor, &toFocus);
    VEC_Normalize(&toFocus, &dir);
    i = (pitch >> 4) * 2;
    eye.y = FX_Mul(FX_SinCosTable_[i], distance);
    horizontalDist = FX_Mul(FX_SinCosTable_[i + 1], distance);
    eye.x = FX_Mul(dir.x, horizontalDist);
    eye.z = FX_Mul(dir.z, horizontalDist);
    eye.x += anchor.x;
    eye.y += anchorY;
    eye.z += anchor.z;
    FIELD_CAMERA_SetTarget(fieldCamera, point);
    FIELD_CAMERA_SetEyeRaw(fieldCamera, &eye);
}

void FIELD_RAIL_CAMERA_OrbitMovingPoint(RailManager *manager)
{
    VecFx32 point;
    RailCamera *camera;
    RailWork *focusWork;
    int lineEnd;
    int lineOffset;
    u16 pitch;
    int distance;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    FIELD_RAIL_WORK_GetMode(focusWork);
    lineEnd = FIELD_RAIL_WORK_GetLineEndOffset(focusWork);
    lineOffset = FIELD_RAIL_WORK_GetLineOffset(focusWork);
    camera = FIELD_RAIL_WORK_GetCamera(focusWork);
    pitch = camera->param[0];
    distance = camera->param[1];
    point.x = camera->param[2] + FX_Div(FX_Mul(camera->param[5] - camera->param[2], lineOffset << 12), lineEnd << 12);
    point.y = camera->param[3] + FX_Div(FX_Mul(camera->param[6] - camera->param[3], lineOffset << 12), lineEnd << 12);
    point.z = camera->param[4] + FX_Div(FX_Mul(camera->param[7] - camera->param[4], lineOffset << 12), lineEnd << 12);
    FIELD_RAIL_CAMERA_SetOrbit(manager, pitch, distance, &point);
}

void FIELD_RAIL_CAMERA_YawFromPoint(RailManager *manager)
{
    VecFx32 anchor;
    VecFx32 toFocus;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;
    int yaw;

    camera = FIELD_RAIL_WORK_GetCamera(FIELD_RAIL_GetFocusWork(manager));
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    FIELD_RAIL_GetFocusPos(manager, &toFocus);
    toFocus.y = 0;
    anchor.x = camera->param[2];
    anchor.y = 0;
    anchor.z = camera->param[3];
    VEC_Subtract(&toFocus, &anchor, &toFocus);
    VEC_Normalize(&toFocus, &toFocus);
    yaw = FX_Atan2Idx(toFocus.x, toFocus.z);
    FIELD_CAMERA_SetPitch(fieldCamera, camera->param[0]);
    FIELD_CAMERA_SetDistance(fieldCamera, camera->param[1]);
    FIELD_CAMERA_SetYaw(fieldCamera, yaw);
}

void FIELD_RAIL_CAMERA_FollowHeading(RailManager *manager)
{
    s16 stepVec[4];
    RailCamera *camera;
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    int heading;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    camera = FIELD_RAIL_WORK_GetCamera(focusWork);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    FIELD_RAIL_WORK_GetStepVector(focusWork, stepVec);
    heading = FX_Atan2Idx(-stepVec[0], -stepVec[2]);
    FIELD_CAMERA_SetPitch(fieldCamera, camera->param[1]);
    FIELD_CAMERA_SetDistance(fieldCamera, camera->param[2]);
    FIELD_CAMERA_SetYaw(fieldCamera, (u16)(heading + camera->param[0]));
}

void FIELD_RAIL_CAMERA_FollowHeadingSlope(RailManager *manager)
{
    s16 stepVec[6];
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    RailCamera *camera;
    int heading, slope;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    camera = FIELD_RAIL_WORK_GetCamera(focusWork);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    FIELD_RAIL_WORK_GetStepVector(focusWork, &stepVec[3]);
    heading = FX_Atan2Idx(-stepVec[3], -stepVec[5]);
    stepVec[0] = stepVec[3];
    stepVec[2] = stepVec[5];
    stepVec[1] = 0;
    slope = FX_Atan2Idx(-stepVec[4], VEC_Fx16Mag( (const VecFx16 *)stepVec));
    FIELD_CAMERA_SetPitch(fieldCamera, slope + camera->param[1]);
    FIELD_CAMERA_SetDistance(fieldCamera, camera->param[2]);
    FIELD_CAMERA_SetYaw(fieldCamera, (u16)(heading + camera->param[0]));
}

void FIELD_RAIL_CAMERA_FollowHeadingAtCentre(RailManager *manager)
{
    s16 stepVec[4];
    VecFx32 centrePos;
    RailWork *focusWork;
    struct FieldCamera *fieldCamera;
    RailCamera *camera;
    int heading;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    camera = FIELD_RAIL_WORK_GetCamera(focusWork);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_StopTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    FIELD_RAIL_WORK_GetStepVector(focusWork, stepVec);
    heading = FX_Atan2Idx(-stepVec[0], -stepVec[2]);
    FIELD_CAMERA_SetPitch(fieldCamera, camera->param[1]);
    FIELD_CAMERA_SetDistance(fieldCamera, camera->param[2]);
    FIELD_CAMERA_SetYaw(fieldCamera, (u16)(heading + camera->param[0]));
    FIELD_RAIL_WORK_GetCentrePos(focusWork, &centrePos);
    FIELD_CAMERA_SetTarget(FIELD_RAIL_GetFieldCamera(manager), &centrePos);
}

void FIELD_RAIL_CAMERA_ApplyLineStart(RailManager *manager)
{
    RailWork *focusWork = FIELD_RAIL_GetFocusWork(manager);
    int mode = FIELD_RAIL_WORK_GetMode(focusWork);
    RailPoint *startPoint = FIELD_RAIL_WORK_GetStartPoint(focusWork);

    if (mode == 1) {
        FIELD_RAIL_CAMERA_ApplyPoint(manager, focusWork, startPoint);
    }
}

void FIELD_RAIL_CAMERA_ApplyLineEnd(RailManager *manager)
{
    RailWork *focusWork = FIELD_RAIL_GetFocusWork(manager);
    int mode = FIELD_RAIL_WORK_GetMode(focusWork);
    RailPoint *endPoint = FIELD_RAIL_WORK_GetEndPoint(focusWork);

    if (mode == 1) {
        FIELD_RAIL_CAMERA_ApplyPoint(manager, focusWork, endPoint);
    }
}

void FIELD_RAIL_CAMERA_FixedAngleShift(RailManager *manager)
{
    VecFx32 focusPos;
    VecFx32 shift;
    struct FieldCamera *fieldCamera;
    RailCamera *camera;
    u16 pitch, yaw;
    u32 distance;

    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    camera = FIELD_RAIL_WORK_GetCamera(FIELD_RAIL_GetFocusWork(manager));
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    FIELD_RAIL_GetFocusPos(manager, &focusPos);
    pitch = camera->param[0];
    yaw = camera->param[1];
    distance = camera->param[2];
    FIELD_CAMERA_SetYaw(fieldCamera, yaw);
    FIELD_CAMERA_SetPitch(fieldCamera, pitch);
    FIELD_CAMERA_SetDistance(fieldCamera, distance);
    shift.x = camera->param[3];
    shift.y = camera->param[4];
    shift.z = camera->param[5];
    FIELD_CAMERA_SetTargetShift(fieldCamera, &shift);
}

void FIELD_RAIL_CAMERA_FixedAngleShiftAtFocus(RailManager *manager)
{
    VecFx32 focusPos;
    struct FieldCamera *fieldCamera = FIELD_RAIL_GetFieldCamera(manager);

    FIELD_RAIL_CAMERA_FixedAngleShift(manager);
    FIELD_CAMERA_StopTargetTrace(fieldCamera);
    FIELD_RAIL_GetFocusPos(manager, &focusPos);
    FIELD_CAMERA_SetTarget(fieldCamera, &focusPos);
    FIELD_CAMERA_RestartDelay(fieldCamera);
}

/*
 * Keyframe lerp between two FIELD_RAIL_WORK_GetPointCamera records: two wrapped 16-bit
 * angles (param 0 and 1), a scalar (param 2) and a vector (param 3 to 5).  The
 * angle and scalar locals are int with explicit (u16) casts: as u16
 * locals the pitch0 load sinks below the camera1 loads and every spill slot moves.
 * camera1 is declared before camera0 to put camera0 in r5.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_RAIL_CAMERA_BlendAnglesShift(RailManager *manager)
{
    VecFx32 shift;
    RailCamera *camera1;
    RailCamera *camera0;
    RailWork *focusWork;
    RailPoint *startPoint;
    RailPoint *endPoint;
    struct FieldCamera *fieldCamera;
    int ratio;
    int lineEnd;
    int lineOffset;
    int pitch0;
    int yaw0;
    int distance0;
    int yaw1;
    int distance1;
    int pitchDelta;
    int yawDelta;
    u16 pitch;
    u16 yaw;

    focusWork = FIELD_RAIL_GetFocusWork(manager);
    startPoint = FIELD_RAIL_WORK_GetStartPoint(focusWork);
    endPoint = FIELD_RAIL_WORK_GetEndPoint(focusWork);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(manager));
    camera0 = FIELD_RAIL_WORK_GetPointCamera(focusWork, startPoint);
    camera1 = FIELD_RAIL_WORK_GetPointCamera(focusWork, endPoint);
    lineEnd = FIELD_RAIL_WORK_GetLineEndOffset(focusWork);
    lineOffset = FIELD_RAIL_WORK_GetLineOffset(focusWork);
    ratio = FX_Div(lineOffset << 12, lineEnd << 12);
    pitch0 = (u16)camera0->param[0];
    yaw0 = (u16)camera0->param[1];
    distance0 = camera0->param[2];
    yaw1 = (u16)camera1->param[1];
    distance1 = camera1->param[2];
    pitchDelta = (u16)camera1->param[0] - pitch0;
    if (pitchDelta >= 0x8000)
        pitchDelta -= 0x10000;
    else if (pitchDelta <= -0x8000)
        pitchDelta += 0x10000;
    pitch = pitch0 + (FX_Mul(pitchDelta << 12, ratio) >> 12);
    yawDelta = yaw1 - yaw0;
    if (yawDelta >= 0x8000)
        yawDelta -= 0x10000;
    else if (yawDelta <= -0x8000)
        yawDelta += 0x10000;
    yaw = yaw0 + (FX_Mul(yawDelta << 12, ratio) >> 12);
    FIELD_CAMERA_SetYaw(fieldCamera, yaw);
    FIELD_CAMERA_SetPitch(fieldCamera, pitch);
    FIELD_CAMERA_SetDistance(fieldCamera, distance0 + FX_Mul(distance1 - distance0, ratio));
    shift.x = camera0->param[3] + FX_Mul(camera1->param[3] - camera0->param[3], ratio);
    shift.y = camera0->param[4] + FX_Mul(camera1->param[4] - camera0->param[4], ratio);
    shift.z = camera0->param[5] + FX_Mul(camera1->param[5] - camera0->param[5], ratio);
    FIELD_CAMERA_SetTargetShift(fieldCamera, &shift);
}

/*
 * EXACT*: 406 bytes compiled against a 408-byte extent (trailing pad).
 * The result vector is written through the SDK's inline VEC_Set, whose
 * arguments are evaluated z, y, x before the three stores.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_RAIL_ProjectOnSegment(RailPoint *startPoint, RailPoint *endPoint, const VecFx32 *pos, VecFx32 *outHit, fx32 *outDist,
                  VecFx32 *outAxis)
{
    VecFx32 segment;
    VecFx32 toPos;
    VecFx32 segmentDir;
    VecFx32 unitSegment;
    VecFx32 unitToPos;
    fx32 segmentLength;
    fx32 toPosLength;
    fx32 ratio;
    fx32 hitDist;
    fx32 heightDiff;

    VEC_Subtract(&startPoint->pos, &endPoint->pos, &segment);
    VEC_Subtract(pos, &endPoint->pos, &toPos);
    VEC_Normalize(&segment, &segmentDir);
    segmentLength = VEC_Mag(&segment);
    segment = segmentDir;
    toPosLength = VEC_Mag(&toPos);
    VEC_Normalize(&toPos, &toPos);
    ratio = FX_Div(toPosLength, segmentLength);
    toPos.x = FX_MUL(toPos.x, ratio);
    toPos.y = FX_MUL(toPos.y, ratio);
    toPos.z = FX_MUL(toPos.z, ratio);
    *outDist = VEC_DotProduct(&segment, &toPos);
    if (*outDist > 0x1000) {
        return 0;
    }
    if (*outDist < 0) {
        return 0;
    }
    *outDist = FX_MUL(*outDist, segmentLength);
    VEC_Normalize(&segment, &unitSegment);
    VEC_Normalize(&toPos, &unitToPos);
    VEC_CrossProduct(&unitSegment, &unitToPos, outAxis);
    hitDist = *outDist;
    VEC_Set(outHit, FX_MUL(segmentDir.x, hitDist), FX_MUL(segmentDir.y, hitDist), FX_MUL(segmentDir.z, hitDist));
    VEC_Add(&endPoint->pos, outHit, outHit);
    if (VEC_Distance(pos, outHit) >= 0x100000) {
        return 0;
    }
    heightDiff = pos->y - outHit->y;
    if (heightDiff < 0) {
        heightDiff = -heightDiff;
    }
    if (heightDiff > 0x8000) {
        return 0;
    }
    return 1;
}

void FIELD_RAIL_CAMERA_ApplyPoint(RailManager *manager, RailWork *work, RailPoint *point)
{
    VecFx32 centrePos;
    u32 lineOffset;
    RailCamera *camera;
    struct FieldCamera *fieldCamera;
    RailPoint *startPoint;

    startPoint = FIELD_RAIL_WORK_GetStartPoint(work);
    if (startPoint == point)
        lineOffset = 0;
    else
        lineOffset = FIELD_RAIL_WORK_GetLineEndOffset(work);
    FIELD_RAIL_WORK_GetPosAtLineOffset(work, lineOffset, &centrePos);
    camera = FIELD_RAIL_WORK_GetPointCamera(work, point);
    fieldCamera = FIELD_RAIL_GetFieldCamera(manager);
    FIELD_CAMERA_EnterMode(fieldCamera, 0);
    FIELD_CAMERA_StopTargetTrace(fieldCamera);
    FIELD_CAMERA_SetTarget(fieldCamera, &centrePos);
    FIELD_CAMERA_SetPitch(fieldCamera, camera->param[0]);
    FIELD_CAMERA_SetYaw(fieldCamera, (u16)camera->param[1]);
    FIELD_CAMERA_SetDistance(fieldCamera, camera->param[2]);
}
