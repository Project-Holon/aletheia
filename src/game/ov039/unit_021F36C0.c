/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: GIMMICK39_FindDockAt, GIMMICK39_GetActiveCart, GIMMICK39_Setup, GIMMICK39_UpdateTask, GIMMICK39_End, GIMMICK39_SaveCartFrames, GIMMICK39_TransferSound, GIMMICK39_GetDockCart, GIMMICK39_GetDockLane, GIMMICK39_IsCartAtDock, GIMMICK39_GetAnimeFrame, GIMMICK39_SetAnimeFrame, GIMMICK39_CreateSwitchEvent, GIMMICK39_SwitchEventMain, GIMMICK39_CheckRideEvent, GIMMICK39_UnlockLaneFromScript, GIMMICK39_IsLaneLocked, GIMMICK39_UnlockLane, GIMMICK39_RideEventMain, GIMMICK39_RideRefusedEventMain, GIMMICK39_ApplySwitch, GIMMICK39_SwapCartAnimes, GIMMICK39_FindStopAtFrame, GIMMICK39_IsCartBeforeSwitchLimit, GIMMICK39_SampleJointTranslation, GIMMICK39_SampleJointTrack
 * address:  0x021F36C0
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_AllocCommonWork 0x02189764 thumb ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive 0x021BE760 thumb ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeLoop 0x021BE6B8 thumb ov021
 *   FIELDMAP_GetTcblSys 0x02188D30 thumb ov021
 *   func_02030DA8 0x02030DA8 arm
 *   sCartSetup 0x021F4C18 data ov039 a4
 *   sModelPos00 0x021F4D60 data ov039 a4
 *   sModelPos01 0x021F4D0C data ov039 a4
 *   sModelPos02 0x021F4D6C data ov039 a4
 *   sModelPos03 0x021F4D18 data ov039 a4
 *   sModelPos04 0x021F4D24 data ov039 a4
 *   sModelPos05 0x021F4D3C data ov039 a4
 *   sModelPos06 0x021F4D00 data ov039 a4
 *   sModelPos07 0x021F4CD0 data ov039 a4
 *   sModelPos08 0x021F4CDC data ov039 a4
 *   sModelPos09 0x021F4D30 data ov039 a4
 *   sModelPos10 0x021F4D48 data ov039 a4
 *   sModelPos11 0x021F4CE8 data ov039 a4
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   ICA_ANIME_CreateWithFullBuffer 0x02011428 thumb
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FIELD_SOUND_SYSTEM_ClaimSlot 0x02028A7C thumb
 *   func_020061E4 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   FIELD_SOUND_SYSTEM_TransferSlot 0x02028B18 thumb
 *   GFL_USE_GetSeHandle 0x02006138 thumb
 *   NNS_SndHandleSetSeqPriority 0x02072F34 arm
 *   func_021BE6E8 0x021BE6E8 thumb ov021
 *   FIELD_SOUND_SYSTEM_ReleaseSlot 0x02028B50 thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   ICA_ANIME_GetTranslateAt 0x02011688 thumb
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_SetPos 0x021A3044 thumb ov021
 *   GIMMICK39_UpdateCartSound 0x021F4A18 thumb ov039
 *   sRideAnimeIds    0x021F4C38 data a4
 *   sStopDocks    0x021F4C28 data ov039 a1
 *   sRideAnimeOrigin    0x021F4D54 data ov039 a4
 *   sLaneRideOffsets    0x021F4CA0 data a4
 *   func_02030EAC 0x02030EAC arm
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   sDockLanes    0x021F4C0C data ov039 a1
 *   FLD_EXP_OBJ_GetModelObject 0x021BE4C4 thumb ov021
 *   G3D_SYSTEM_GetObjectAnimeFrame 0x02047828 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4 0x020124E4 thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeFrame 0x021BE6CC thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   FIELD_PLAYER_GetDirDisp 0x021A3050 thumb ov021
 *   FIELD_PLAYER_GetPos 0x021A3038 thumb ov021
 *   GIMMICK39_FindDockAt 0x021F36C0 thumb ov039
 *   FLD_EXP_OBJ_GetAnimeLastFrame 0x021BE748 thumb ov021
 *   func_020061F8 0x020061F8 thumb
 *   func_0203630C 0x0203630C arm
 *   G3D_SYSTEM_GetObjectAnime 0x02047790 arm
 *   G3D_SYSTEM_GetAnimeObj 0x02047674 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   SCRIPT_SYS_CallScriptEvent 0x02158780 thumb ov010
 *   FIELD_PLAYER_GetMmdl 0x021A3074 thumb ov021
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb
 *   FLDMMDL_SetDirDispCheckPause 0x0216D5E0 thumb
 *   sDockCells    0x021F4C58 data ov039 a4
 *   sRideExitPos    0x021F4CF4 data ov039 a4
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   func_021BE6B4  0x021BE6B4  thumb  ov021
 *   sStopFrames 0x021F4D78 data a4
 *   sSwitchFrameLimits 0x021F4BE4 data a2
 *   _ll_mul  0x0209C054  arm
 */
#include "unit_021F36C0_types.h"

/* Index of the dock tile at tile (x, z), GIMMICK39_NO_DOCK if the tile is no dock. */
u8 GIMMICK39_FindDockAt(int x, int z)
{
    u8 dock;

    for (dock = 0; dock < GIMMICK39_DOCK_COUNT; dock++) {
        if (sDockCells[dock].x == x && sDockCells[dock].z == z) {
            return dock;
        }
    }
    return GIMMICK39_NO_DOCK;
}

/* The cart in use on a lane. */
u8 GIMMICK39_GetActiveCart(Gimmick39Work *work, int lane)
{
    return work->activeCart[lane];
}

/*
 * Gimmick setup: allocates the work, adds the model unit, places the 12
 * models, shows the cart of each lane that its lever selects and starts the
 * per-frame task.
 */
void GIMMICK39_Setup(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    Gimmick39Work *work;
    struct GameData *gameData;
    Gimmick39Save *save;
    struct FieldSoundSystem *soundSys;
    u32 lane;
    int n;
    int leverStateA, leverStateB;
    u8 *laneStatePtr; /* stand-in: row pointer (save + lane), see GIMMICK39_SAVE_LANE_STATE */
    u8 animeIndex;
    u8 model;
    FldExpObjAnime *anime;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(gameData), GIMMICK39_SAVE_ID);
    soundSys = GAME_DATA_GetBgmInfo(gameData);
    FIELDMAP_AllocCommonWork(fieldMap, 1, FIELDMAP_GetHeapId(fieldMap), GIMMICK39_WORK_SIZE);
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &sCartSetup, 0);
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 0)->trans = sModelPos00;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 1)->trans = sModelPos01;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 2)->trans = sModelPos02;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 3)->trans = sModelPos03;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 4)->trans = sModelPos04;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 5)->trans = sModelPos05;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 6)->trans = sModelPos06;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 7)->trans = sModelPos07;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 8)->trans = sModelPos08;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 9)->trans = sModelPos09;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 10)->trans = sModelPos10;
    FLD_EXP_OBJ_GetModelStatus(expObj, 0, 11)->trans = sModelPos11;
    for (lane = 0; lane < GIMMICK39_LANE_COUNT; lane = (u8)(lane + 1)) {
        model = lane;
        laneStatePtr = (u8 *)save + lane;
        animeIndex = laneStatePtr[GIMMICK39_SAVE_LANE_STATE] ? lane * 2 + 2 : lane * 2 + 1;
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, animeIndex, 1);
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, 0, 1);
        anime = FLD_EXP_OBJ_GetAnime(expObj, 0, model, 0);
        FLD_EXP_OBJ_SetAnimePaused(anime, 1);
        FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, model, animeIndex, save->laneFrame[lane]);
        model = lane + GIMMICK39_LANE_COUNT;
        leverStateA = laneStatePtr[GIMMICK39_SAVE_LANE_STATE];
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, leverStateA, 1);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, model, 0), 0);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, model, 1), 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, model, leverStateA, FLD_EXP_OBJ_GetAnimeLastFrame(FLD_EXP_OBJ_GetAnime(expObj, 0, model, leverStateA)));
        leverStateB = laneStatePtr[GIMMICK39_SAVE_LANE_STATE];
        model = lane + GIMMICK39_LANE_COUNT * 2;
        FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, leverStateB, 1);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, model, 0), 0);
        FLD_EXP_OBJ_SetAnimeLoop(FLD_EXP_OBJ_GetAnime(expObj, 0, model, 1), 0);
        FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, model, leverStateB, FLD_EXP_OBJ_GetAnimeLastFrame(FLD_EXP_OBJ_GetAnime(expObj, 0, model, leverStateB)));
    }
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    work->task = func_02030DA8(FIELDMAP_GetTcblSys(fieldMap), GIMMICK39_UpdateTask, fieldMap, 0);
    for (n = 0; n < GIMMICK39_LANE_COUNT; n++) {
        work->switchRequest[n] = 0;
        work->activeCart[n] = n * 2 + save->laneState[n];
        work->parkedDock[n] = -1;
    }
    work->switchLane = -1;
    work->rideLane = -1;
    work->selectedCart = GIMMICK39_NO_CART;
    FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
    FIELD_SOUND_SYSTEM_TransferSlot(soundSys, GIMMICK39_SLOT_CART_LOOP, 0);
}

/*
 * Per-frame task. First applies the lever requests that wait for their cart
 * animation to reach frame 0. Then, for each lane, counts down the dock
 * timer or watches the cart animation reach one of its two stop frames
 * (the cart is then parked at that dock). While a ride runs the player
 * follows the ride animation, otherwise the sound of the nearest cart is
 * updated.
 *
 * Compiler note: spill slots follow reverse declaration order (last declared,
 * lowest slot): oldState, cart, saveRow, laneTwice, parkedRow, cartAnimeIndex,
 * laneModel give a 8, b 0xc, sr 0x10, j2 0x14, qr 0x18, v 0x1c, d 0x20. The
 * row pointers saveRow (save + lane) and parkedRow (work + lane) and
 * laneTwice = 2 * lane are named locals so they take their declared places,
 * and `cartAnimeIndex = cart + 1` keeps cart a real variable (with
 * `cartAnimeIndex = work->activeCart[lane] + 1` a CSE temporary takes the
 * first slot instead). sStopDocks and sRideAnimeOrigin need the ov039 token.
 */
void GIMMICK39_UpdateTask(struct Tcb *tcb, struct FieldMap *fieldMap)
{
    u8 i;
    int lane;
    FldExpObjCnt *expObj;
    Gimmick39Work *work;
    struct GameData *gameData;
    Gimmick39Save *save;
    struct FieldSoundSystem *soundSys;
    int oldState;
    u8 cart;
    u8 *saveRow; /* stand-in: row pointer (save + lane), see GIMMICK39_SAVE_LANE_STATE */
    int laneTwice;
    s8 *parkedRow; /* stand-in: row pointer (work + lane), see GIMMICK39_WORK_PARKED_DOCK */
    u8 cartAnimeIndex;
    u8 laneModel;
    FldExpObjAnime *cartAnime;
    int seSlot;
    u8 rideLane;
    VecFx32 ridePos;
    u8 stopIndex[4];
    u32 laneState;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap));
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(gameData), GIMMICK39_SAVE_ID);
    soundSys = GAME_DATA_GetBgmInfo(gameData);
    for (i = 0; i < GIMMICK39_LANE_COUNT; i++) {
        lane = i;
        if (work->switchRequest[lane] != 0) {
            saveRow = (u8 *)save + lane;
            oldState = (u8)((saveRow[GIMMICK39_SAVE_LANE_STATE] + 1) % 2);
            laneTwice = lane * 2;
            if (GIMMICK39_GetAnimeFrame(expObj, (u8)lane, (u8)(oldState + (laneTwice + 1))) == 0) {
                GIMMICK39_SwapCartAnimes(expObj, oldState, lane);
                laneState = saveRow[GIMMICK39_SAVE_LANE_STATE];
                work->activeCart[lane] = laneTwice + laneState;
                if (work->selectedCart != GIMMICK39_NO_CART && ((u32)work->selectedCart >> 1) == lane
                    && work->selectedCart != work->activeCart[lane]) {
                    work->selectedCart = work->activeCart[lane];
                    ICA_ANIME_Delete(work->rideAnime);
                    work->rideAnime = ICA_ANIME_CreateWithFullBuffer(GIMMICK39_HEAP_ID, GIMMICK39_RIDE_ANIME_ARC,
                                                                     sRideAnimeIds[work->selectedCart], work->rideAnimeBuffer,
                                                                     GIMMICK39_RIDE_ANIME_BUFFER_SIZE);
                }
                work->switchRequest[lane] = 0;
            }
        }
    }
    for (i = 0; i < GIMMICK39_LANE_COUNT; i++) {
        lane = i;
        parkedRow = (s8 *)work + lane;
        cart = work->activeCart[lane];
        cartAnimeIndex = cart + 1;
        laneModel = lane;
        cartAnime = FLD_EXP_OBJ_GetAnime(expObj, 0, laneModel, cartAnimeIndex);
        if (work->dockTimer[lane] != 0) {
            if (work->rideLane != lane && --work->dockTimer[lane] == 0) {
                FLD_EXP_OBJ_SetAnimePaused(cartAnime, 0);
                if (work->selectedCart != GIMMICK39_NO_CART && lane == ((u32)work->selectedCart >> 1)) {
                    FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                    func_020061E4(GIMMICK39_SE_CART_RUN);
                    seSlot = GFL_USE_GetSeSlot(GIMMICK39_SE_CART_RUN);
                    FIELD_SOUND_SYSTEM_TransferSlot(soundSys, GIMMICK39_SLOT_CART_LOOP, 0x7f);
                    NNS_SndHandleSetSeqPriority(GFL_USE_GetSeHandle(seSlot), 0);
                }
                parkedRow[GIMMICK39_WORK_PARKED_DOCK] = -1;
            }
        } else if (GIMMICK39_FindStopAtFrame(cart, func_021BE6E8(expObj, 0, laneModel, cartAnimeIndex), stopIndex)) {
            FLD_EXP_OBJ_SetAnimePaused(cartAnime, 1);
            if (work->selectedCart != GIMMICK39_NO_CART && lane == ((u32)work->selectedCart >> 1)) {
                FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                GFL_USE_StopAllSe();
            }
            work->dockTimer[lane] = GIMMICK39_DOCK_TIMER;
            parkedRow[GIMMICK39_WORK_PARKED_DOCK] = sStopDocks[cart][stopIndex[0]];
        }
    }
    if (work->rideActive != 0) {
        ridePos = sRideAnimeOrigin;
        rideLane = work->selectedCart >> 1;
        if (ICA_ANIME_GetTranslateAt(work->rideAnime, &ridePos,
                                     func_021BE6E8(expObj, 0, rideLane, work->selectedCart + 1) / 4096)) {
            ridePos.x += sLaneRideOffsets[rideLane].x;
            ridePos.y += sLaneRideOffsets[rideLane].y;
            ridePos.z += sLaneRideOffsets[rideLane].z;
            FIELD_PLAYER_SetPos(FIELDMAP_GetFieldPlayer(fieldMap), &ridePos);
        }
    } else {
        GIMMICK39_UpdateCartSound(fieldMap, work);
    }
}

/* Gimmick end: stops the cart sound, ends the task, frees the work and the models. */
void GIMMICK39_End(struct FieldMap *fieldMap)
{
    FldExpObjCnt *expObj = FIELDMAP_GetExpObj(fieldMap);
    Gimmick39Work *work = FIELDMAP_GetCommonWork(fieldMap, 1);

    FIELD_SOUND_SYSTEM_ReleaseSlot(GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SLOT_CART_LOOP);
    func_02030EAC(work->task);
    FIELDMAP_FreeCommonWork(fieldMap, 1);
    FLD_EXP_OBJ_RemoveUnit(expObj, 0);
}

/* Gimmick save step: keeps the frame of the active cart animation of each lane. */
void GIMMICK39_SaveCartFrames(struct FieldMap *fieldMap)
{
    Gimmick39Save *save;
    FldExpObjCnt *expObj;
    int i;
    Gimmick39Work *work;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SAVE_ID);
    FLD_EXP_OBJ_UpdateAnimes(expObj);
    for (i = 0; i < GIMMICK39_LANE_COUNT; i++)
        save->laneFrame[i] = GIMMICK39_GetAnimeFrame(expObj, (unsigned char)i, (unsigned char)(work->activeCart[i] + 1));
}

/* Script entry: starts the cart sound slot and transfers it. */
void GIMMICK39_TransferSound(struct GameSystem *gameSystem)
{
    struct FieldSoundSystem *soundSys;

    soundSys = GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(gameSystem));
    FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
    FIELD_SOUND_SYSTEM_TransferSlot(soundSys, GIMMICK39_SLOT_CART_LOOP, 0);
}

/* The cart in use on the lane of a dock. */
u8 GIMMICK39_GetDockCart(Gimmick39Work *work, int dock)
{
    return GIMMICK39_GetActiveCart(work, GIMMICK39_GetDockLane(dock));
}

/* The lane a dock belongs to. */
unsigned char GIMMICK39_GetDockLane(int dock)
{
    return sDockLanes[dock];
}

/* 1 if the cart of the dock's lane waits at that dock. */
int GIMMICK39_IsCartAtDock(Gimmick39Work *work, int dock)
{
    int parkedDock;

    parkedDock = work->parkedDock[GIMMICK39_GetDockLane(dock)];
    if (parkedDock == -1) return 0;
    return parkedDock == dock;
}

/* Frame of a cart animation of a lane model. */
int GIMMICK39_GetAnimeFrame(FldExpObjCnt *expObj, u16 lane, u16 animeIndex)
{
    int frame = 0;

    G3D_SYSTEM_GetObjectAnimeFrame(FLD_EXP_OBJ_GetModelObject(expObj, 0, lane), animeIndex, &frame);
    return frame;
}

/* Sets the frame of an animation of a lane model. */
void GIMMICK39_SetAnimeFrame(FldExpObjCnt *expObj, u8 lane, u16 animeIndex, int frame)
{
    G3D_SYSTEM_SetObjectAnimeFrame(FLD_EXP_OBJ_GetModelObject(expObj, 0, lane), animeIndex, &frame);
}

/*
 * Script entry: creates the event that throws the lever of a lane (0 to 3).
 * Returns no event for other values.
 */
struct GameEvent *GIMMICK39_CreateSwitchEvent(struct GameSystem *gameSystem, u32 lane)
{
    struct FieldMap *fieldMap;
    Gimmick39Work *work;
    struct GameEvent *event;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SAVE_ID);
    if (lane >= GIMMICK39_LANE_COUNT) {
        return 0;
    }
    event = func_020122C0(gameSystem, 0, GIMMICK39_SwitchEventMain, 0);
    work->switchLane = lane;
    return event;
}

/*
 * Event: throws the lever of work->switchLane. Step 0 hides the lever pose
 * that is left and shows the other one, and plays the lever sound; step 1
 * waits for both lever animations, then updates the carts and ends.
 *
 * Compiler note: case 1 reads work->switchLane once into a local (int or s8;
 * u8 differs); re-reading the field per call reloads it and shifts the
 * field map to r6.
 */
int GIMMICK39_SwitchEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick39Work *work;
    Gimmick39Save *save;
    u8 leverModelA;
    u8 leverModelB;
    FldExpObjAnime *leverAnimeA;
    FldExpObjAnime *leverAnimeB;
    int lane;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SAVE_ID);
    switch (*seq) {
    case 0:
        work->switchState = save->laneState[work->switchLane];
        leverModelA = work->switchLane + 4;
        leverModelB = work->switchLane + 8;
        if (work->switchState == 0) {
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelA, 0, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelB, 0, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelA, 1, 1);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelB, 1, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, leverModelA, 1), 0);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, leverModelB, 1), 0);
            FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, leverModelA, 1, 0);
            FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, leverModelB, 1, 0);
            work->switchState = 1;
        } else {
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelA, 1, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelB, 1, 0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelA, 0, 1);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, leverModelB, 0, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, leverModelA, 0), 0);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, leverModelB, 0), 0);
            FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, leverModelA, 0, 0);
            FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, leverModelB, 0, 0);
            work->switchState = 0;
        }
        func_020061E4(GIMMICK39_SE_SWITCH);
        *seq = *seq + 1;
        break;
    case 1:
        lane = work->switchLane;
        leverAnimeA = FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)(lane + 4), work->switchState);
        leverAnimeB = FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)(lane + 8), work->switchState);
        if (FLD_EXP_OBJ_IsAnimeStopped(leverAnimeA) && FLD_EXP_OBJ_IsAnimeStopped(leverAnimeB)) {
            GIMMICK39_ApplySwitch(fieldMap, expObj);
            work->switchLane = -1;
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Interaction check (the player faces nothing else): when the player stands
 * on a dock where the cart of the lane waits, creates the ride event, or
 * the refusal event for a lane that a script has not unlocked.
 *
 * Compiler note: FLD_EXP_OBJ_GetAnime's third parameter is u8 here (the caller
 * truncates the int local before the bl); the FIELDMAP_GetExpObj result bound to
 * a named local keeps `cartAnimeIndex` computed before that call.
 */
struct GameEvent *GIMMICK39_CheckRideEvent(struct GameSystem *gameSystem)
{
    struct FieldMap *fieldMap;
    Gimmick39Save *save;
    Gimmick39Work *work;
    struct FieldPlayer *player;
    VecFx32 playerPos;
    u8 dock;
    int lane;
    u8 cartAnimeIndex;
    FldExpObjCnt *expObj;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SAVE_ID);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    if (FIELD_PLAYER_GetDirDisp(player)) {
        return 0;
    }
    FIELD_PLAYER_GetPos(player, &playerPos);
    dock = GIMMICK39_FindDockAt(playerPos.x / GIMMICK39_TILE_SIZE, playerPos.z / GIMMICK39_TILE_SIZE);
    if (dock == GIMMICK39_NO_DOCK) {
        return 0;
    }
    if (GIMMICK39_IsCartAtDock(work, dock)) {
        lane = GIMMICK39_GetDockLane(dock);
        work->selectedCart = GIMMICK39_GetDockCart(work, dock);
        cartAnimeIndex = work->selectedCart + 1;
        expObj = FIELDMAP_GetExpObj(fieldMap);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, (u8)lane, cartAnimeIndex), 1);
        work->rideLane = lane;
        if (GIMMICK39_IsLaneLocked(save, lane)) {
            return func_020122C0(gameSystem, 0, GIMMICK39_RideRefusedEventMain, 0);
        }
        return func_020122C0(gameSystem, 0, GIMMICK39_RideEventMain, 0);
    }
    return 0;
}

/* Script entry: unlocks lane 1 or 2 (value 1 or 2). */
void GIMMICK39_UnlockLaneFromScript(struct GameSystem *gameSystem, u32 lane)
{
    GIMMICK39_UnlockLane(GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(gameSystem)))),
                                GIMMICK39_SAVE_ID),
                  lane);
}

/*
 * 1 if the lane (1 or 2) still has to be unlocked by a script. The lane is
 * turned into the index of laneUnlocked (1 -> 0, 2 -> 1); other lanes are
 * always unlocked.
 */
int GIMMICK39_IsLaneLocked(Gimmick39Save *save, int lane)
{
    int zero = 0;
    int isGated = 0;

    if (lane == 1) {
        isGated = 1;
        lane = zero;
    } else if (lane == 2) {
        isGated = 1;
        lane = 1;
    }
    if (isGated && save->laneUnlocked[lane] == 0) return 1;
    return 0;
}

/* Unlocks lane 1 or 2 (see GIMMICK39_IsLaneLocked). */
void GIMMICK39_UnlockLane(Gimmick39Save *save, u8 lane)
{
    int zero = 0;
    int isGated = 0;

    if (lane == 1) {
        isGated = 1;
        lane = zero;
    } else if (lane == 2) {
        isGated = 1;
        lane = 1;
    }
    if (isGated) save->laneUnlocked[lane] = 1;
}

/*
 * Ride event. Opens the gate of the lane, shows the board script, closes the
 * gate and starts the ride animation of the cart; the player then follows
 * the animation (work->rideActive) until the cart is parked at a dock and
 * the player presses Down; the player is put on the dock, the arrive script
 * runs and the gate closes.
 *
 * 2026-10-05 final push G2L1: closed. Case 5 stored work->rideLane before
 * movs r1,#1 only when FLD_EXP_OBJ_GetAnime takes (expObj, int, u8 model, u8 anime), as the
 * matched caller GIMMICK39_CheckRideEvent declares it (earlier drafts used unsigned int
 * model, int anime; with u8 parameters the call site is the same but the pair
 * order in case 5 follows the original). The GIMMICK39_GetAnimeFrame call keeps
 * (u8)(work->selectedCart + 1) for its u16 parameter.
 */
int GIMMICK39_RideEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick39Work *work;
    struct FieldSoundSystem *soundSys;
    int seSlot;
    int lane;
    struct G3dObject *cartObj;
    u8 model;
    FldExpObjAnime *gateAnime;
    FldExpObjAnime *cartAnime;
    struct Mmdl *playerMmdl;
    struct FieldPlayer *player;
    NNSG3dAnmObj *animObj;
    int nextFrame;
    u8 animeIndex;
    int frame;
    int frameCount;
    int distance;
    u8 priority;
    VecFx32 exitPos;
    VecFx32 samplePos;
    VecFx32 sampleNextPos;
    VecFx32 step;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    soundSys = GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    seSlot = GFL_USE_GetSeSlot(GIMMICK39_SE_CART_RUN);
    lane = (u8)(work->selectedCart >> 1);
    model = lane;
    gateAnime = FLD_EXP_OBJ_GetAnime(expObj, 0, model, 0);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SAVE_ID);
    switch (*seq) {
    case 0:
        work->rideAnime = ICA_ANIME_CreateWithFullBuffer(GIMMICK39_HEAP_ID, GIMMICK39_RIDE_ANIME_ARC,
                                                         sRideAnimeIds[work->selectedCart], work->rideAnimeBuffer,
                                                         GIMMICK39_RIDE_ANIME_BUFFER_SIZE);
        GIMMICK39_SetAnimeFrame(expObj, model, 0, 0);
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 0);
        func_020061E4(GIMMICK39_SE_GATE);
        *seq = *seq + 1;
        break;
    case 1:
        if (GIMMICK39_GetAnimeFrame(expObj, model, 0) < GIMMICK39_GATE_OPEN_FRAME) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 1);
        SCRIPT_SYS_CallScriptEvent(event, GIMMICK39_SCRIPT_BOARD, 0, 0, GIMMICK39_HEAP_ID);
        *seq = *seq + 1;
        break;
    case 2:
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 0);
        func_020061E4(GIMMICK39_SE_GATE);
        *seq = *seq + 1;
        break;
    case 3:
        if (FLD_EXP_OBJ_IsAnimeStopped(gateAnime) == 0) {
            break;
        }
        FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 1);
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, model, (u8)(work->selectedCart + 1)), 0);
        work->dockTimer[lane] = 0;
        work->parkedDock[lane] = -1;
        work->rideLane = -1;
        FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
        func_020061E4(GIMMICK39_SE_CART_RUN);
        NNS_SndHandleSetSeqPriority(GFL_USE_GetSeHandle(seSlot), 0);
        FIELD_SOUND_SYSTEM_TransferSlot(soundSys, GIMMICK39_SLOT_CART_LOOP, 0x7f);
        work->rideActive = 1;
        *seq = *seq + 1;
        break;
    case 4:
        if (work->parkedDock[lane] == -1) {
            break;
        }
        if (func_0203630C() & GIMMICK39_KEY_DOWN) {
            *seq = *seq + 1;
        }
        break;
    case 5:
        cartAnime = FLD_EXP_OBJ_GetAnime(expObj, 0, model, (u8)(work->selectedCart + 1));
        work->rideLane = lane;
        FLD_EXP_OBJ_SetAnimePaused(cartAnime, 1);
        GIMMICK39_SetAnimeFrame(expObj, model, 0, 0);
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 0);
        func_020061E4(GIMMICK39_SE_GATE);
        playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
        FLDMMDL_SetDirDispCheckPause(playerMmdl, 1);
        FLDMMDL_SetStatusBitVanish(playerMmdl, 0);
        *seq = *seq + 1;
        break;
    case 6:
        if (GIMMICK39_GetAnimeFrame(expObj, model, 0) < GIMMICK39_GATE_OPEN_FRAME) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 1);
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        exitPos = sRideExitPos;
        animeIndex = work->parkedDock[lane];
        exitPos.x = (sDockCells[animeIndex].x << 16) + 0x8000;
        exitPos.z = ((sDockCells[animeIndex].z - 2) << 16) + 0x8000;
        FIELD_PLAYER_SetPos(player, &exitPos);
        work->rideActive = 0;
        *seq = *seq + 1;
        break;
    case 7:
        SCRIPT_SYS_CallScriptEvent(event, GIMMICK39_SCRIPT_ARRIVE, 0, 0, GIMMICK39_HEAP_ID);
        *seq = *seq + 1;
        break;
    case 8:
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 0);
        func_020061E4(GIMMICK39_SE_GATE);
        *seq = *seq + 1;
        break;
    case 9:
        if (FLD_EXP_OBJ_IsAnimeStopped(gateAnime) == 0) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, model, (u8)(work->selectedCart + 1)), 0);
        work->dockTimer[lane] = 0;
        work->parkedDock[lane] = -1;
        ICA_ANIME_Delete(work->rideAnime);
        work->rideLane = -1;
        work->selectedCart = GIMMICK39_NO_CART;
        FIELD_SOUND_SYSTEM_ClaimSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
        FIELD_SOUND_SYSTEM_TransferSlot(soundSys, GIMMICK39_SLOT_CART_LOOP, 0);
        func_020061F8(seSlot);
        return 1;
    }
    if ((u8)(work->selectedCart + 0xFE) <= 3) {
        frame = GIMMICK39_GetAnimeFrame(expObj, model, (u8)(work->selectedCart + 1));
        switch (work->selectedCart) {
        case 2:
            if (frame == 0xBF000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                GFL_USE_StopAllSe();
                func_020061E4(GIMMICK39_SE_RIDE_START);
            } else if (frame == 0xEB000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                GFL_USE_StopAllSe();
            } else if (frame == 0xFF000) {
                func_020061E4(GIMMICK39_SE_RIDE_END);
            }
            break;
        case 3:
            if (frame == 0x108000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                GFL_USE_StopAllSe();
                func_020061E4(GIMMICK39_SE_RIDE_START);
            } else if (frame == 0x131000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                GFL_USE_StopAllSe();
            } else if (frame == 0x148000) {
                func_020061E4(GIMMICK39_SE_RIDE_END);
            }
            break;
        case 4:
            if (frame == 0xB1000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                GFL_USE_StopAllSe();
                func_020061E4(GIMMICK39_SE_RIDE_BUMP);
            }
            break;
        case 5:
            if (frame == 0xB6000) {
                FIELD_SOUND_SYSTEM_ReleaseSlot(soundSys, GIMMICK39_SLOT_CART_LOOP);
                GFL_USE_StopAllSe();
                func_020061E4(GIMMICK39_SE_RIDE_BUMP);
            }
            break;
        }
    }
    cartObj = FLD_EXP_OBJ_GetModelObject(expObj, 0, model);
    animeIndex = work->selectedCart + 1;
    frameCount = FLD_EXP_OBJ_GetAnimeLastFrame(FLD_EXP_OBJ_GetAnime(expObj, 0, model, animeIndex));
    frame = GIMMICK39_GetAnimeFrame(expObj, model, animeIndex);
    nextFrame = frame + 0x1000;
    if (nextFrame >= frameCount) {
        nextFrame = 0;
    }
    animObj = G3D_SYSTEM_GetAnimeObj(G3D_SYSTEM_GetObjectAnime(cartObj, (u16)animeIndex));
    priority = 0;
    GIMMICK39_SampleJointTranslation((const u8 *)animObj->resAnm, 0, frame, &samplePos);
    GIMMICK39_SampleJointTranslation((const u8 *)animObj->resAnm, 0, nextFrame, &sampleNextPos);
    func_0207CA00(&samplePos, &sampleNextPos, &step);
    distance = func_0207CBD0(&step);
    if (distance >= 0x20000) {
        priority = 0x7f;
    } else if (distance >= 0x18000) {
        priority = 0x5a;
    } else if (distance >= 0x10000) {
        priority = 0x3c;
    } else if (distance >= 0x8000) {
        priority = 0x1e;
    }
    NNS_SndHandleSetSeqPriority(GFL_USE_GetSeHandle(seSlot), priority);
    return 0;
}

/*
 * Event for a lane that is not unlocked yet: runs the refusal scripts with
 * the gate animation between them, then drops the cart selection.
 */
int GIMMICK39_RideRefusedEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    Gimmick39Work *work;
    int lane;
    u8 model;
    FldExpObjAnime *gateAnime;

    fieldMap = GAMESYSTEM_GetFieldMap(func_020124E4(event));
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    lane = (u8)(work->selectedCart >> 1);
    model = lane;
    gateAnime = FLD_EXP_OBJ_GetAnime(expObj, 0, model, 0);
    GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SAVE_ID);
    switch (*seq) {
    case 0:
        SCRIPT_SYS_CallScriptEvent(event, GIMMICK39_SCRIPT_LOCKED_A, 0, 0, GIMMICK39_HEAP_ID);
        *seq = *seq + 1;
        break;
    case 1:
        GIMMICK39_SetAnimeFrame(expObj, model, 0, 0);
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 0);
        func_020061E4(GIMMICK39_SE_GATE);
        *seq = *seq + 1;
        break;
    case 2:
        if (GIMMICK39_GetAnimeFrame(expObj, model, 0) < GIMMICK39_GATE_OPEN_FRAME) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 1);
        SCRIPT_SYS_CallScriptEvent(event, GIMMICK39_SCRIPT_LOCKED_B, 0, 0, GIMMICK39_HEAP_ID);
        *seq = *seq + 1;
        break;
    case 3:
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 0);
        func_020061E4(GIMMICK39_SE_GATE);
        *seq = *seq + 1;
        break;
    case 4:
        if (FLD_EXP_OBJ_IsAnimeStopped(gateAnime) == 0) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(gateAnime, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, model, (u8)(work->selectedCart + 1)), 0);
        work->dockTimer[lane] = 0;
        work->parkedDock[lane] = -1;
        work->selectedCart = GIMMICK39_NO_CART;
        SCRIPT_SYS_ChangeScriptEvent(event, GIMMICK39_SCRIPT_LOCKED_END, 0, GIMMICK39_HEAP_ID);
        *seq = *seq + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}

/*
 * Applies the lever of work->switchLane to the cart: flips the saved lever
 * state; if the cart animation of the lane is still near its start the carts
 * are swapped at once, otherwise the swap is requested for the per-frame
 * task (a second throw before the swap cancels the request).
 */
void GIMMICK39_ApplySwitch(struct FieldMap *fieldMap, FldExpObjCnt *expObj)
{
    Gimmick39Work *work;
    Gimmick39Save *save;
    u8 *laneState;
    u8 oldState;
    s8 lane;

    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    save = GIMMICK_WORK_GetSaveArea(GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), GIMMICK39_SAVE_ID);
    lane = work->switchLane;
    if (lane == -1) {
        return;
    }
    laneState = save->laneState;
    oldState = laneState[lane];
    laneState[lane] = (oldState + 1) % 2;
    if (GIMMICK39_IsCartBeforeSwitchLimit(expObj, (u8)lane, work->activeCart[work->switchLane]) != 0) {
        GIMMICK39_SwapCartAnimes(expObj, oldState, (u8)work->switchLane);
        lane = work->switchLane;
        work->activeCart[lane] = lane * 2 + save->laneState[lane];
    } else {
        u8 *request = work->switchRequest;

        lane = work->switchLane;
        if (request[lane] != 0) {
            request[lane] = 0;
        } else {
            request[lane] = 1;
        }
    }
}

/*
 * Swaps the carts of a lane: the cart animation of the old lever state is
 * hidden and the other one is shown at the same frame and pause state.
 */
void GIMMICK39_SwapCartAnimes(FldExpObjCnt *expObj, int oldState, int lane)
{
    u8 oldAnime;
    u8 newAnime;
    u8 model;
    u8 paused;
    int frame;

    if (oldState == 0) {
        oldAnime = lane * 2 + 1;
        newAnime = oldAnime + 1;
    } else {
        newAnime = lane * 2 + 1;
        oldAnime = newAnime + 1;
    }
    model = lane;
    frame = GIMMICK39_GetAnimeFrame(expObj, model, oldAnime);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, oldAnime, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, model, newAnime, 1);
    GIMMICK39_SetAnimeFrame(expObj, model, newAnime, frame);
    paused = func_021BE6B4(FLD_EXP_OBJ_GetAnime(expObj, 0, model, oldAnime));
    FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(expObj, 0, model, newAnime), paused);
}

/* 1 and the stop index when the animation frame is one of the two stop frames of the cart. */
int GIMMICK39_FindStopAtFrame(u32 cart, u32 frame, u8 *stopIndex)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (sStopFrames[cart][i] == frame) {
            *stopIndex = i;
            return 1;
        }
    }
    return 0;
}

/* 1 while the cart animation of the lane is not past its lever limit frame. */
int GIMMICK39_IsCartBeforeSwitchLimit(FldExpObjCnt *expObj, int lane, u8 cart)
{
    if (GIMMICK39_GetAnimeFrame(expObj, (u8)lane, cart + 1) <= (int)(sSwitchFrameLimits[lane] << 12)) return 1;
    return 0;
}

/*
 * Samples the translation of a joint (joint 0 is the cart) of a joint
 * animation at a frame. Only the axes that are not constant are written.
 */
void GIMMICK39_SampleJointTranslation(const u8 *resAnm, int jointIndex, int frame, VecFx32 *out)
{
    u16 tagOffset;
    u32 flags;
    const Gimmick39JointTrack *track;
    int x;
    int y;
    int z;

    tagOffset = ((const Gimmick39JointAnim *)resAnm)->tagOffset[jointIndex];
    flags = ((const Gimmick39JointTag *)(resAnm + tagOffset))->flags;
    track = ((const Gimmick39JointTag *)(resAnm + tagOffset))->track;
    if (flags & GIMMICK39_JOINT_NO_TRANSLATE) {
        return;
    }
    if (!(flags & GIMMICK39_JOINT_X_CONSTANT)) {
        GIMMICK39_SampleJointTrack(&x, frame, track, resAnm);
        track++;
        out->x = x;
    }
    if (!(flags & GIMMICK39_JOINT_Y_CONSTANT)) {
        GIMMICK39_SampleJointTrack(&y, frame, track, resAnm);
        track++;
        out->y = y;
    }
    if (flags & GIMMICK39_JOINT_Z_CONSTANT) {
        return;
    }
    GIMMICK39_SampleJointTrack(&z, frame, track, resAnm);
    out->z = z;
}

/*
 * An animation-curve sampler (step-1/2/4 keys, fx16 or fx32 array). The
 * 1:3 weight's own idx_sub variable puts idx in r2 on every path; the fx16
 * 1:3 sum needs v = v + (v << 1) as its own statement or the second load
 * is hoisted; the interpolation reads spelled *(p + idx) / *(p + idx + 1)
 * share p + idx after the first load, where p[idx] / p[idx + 1] recomputes
 * (idx + 1) * 2 and a pointer local p + idx hoists the add above the load.
 */
void GIMMICK39_SampleJointTrack(int *out, int frame, const Gimmick39JointTrack *track, const u8 *base)
{
    const u8 *keys;
    u32 f;
    u32 info;
    u32 last;
    u32 idx;

    f = frame >> 12;
    keys = base + track->dataOffset;
    info = track->info;
    if (!(info & 0xC0000000)) {
        idx = f;
        goto plain;
    }
    last = (info & 0x1FFF0000) >> 16;
    if (info & 0x40000000) {
        if (f & 1) {
            if (f > last) {
                idx = (last >> 1) + 1;
                goto plain;
            } else {
                idx = f >> 1;
                goto interp2;
            }
        } else {
            idx = f >> 1;
            goto plain;
        }
    } else {
        if (f & 3) {
            if (f > last) {
                idx = (last >> 2) + (f & 3);
                goto plain;
            }
            if (f & 1) {
                int v;
                u32 idxSub;
                if (f & 2) {
                    idxSub = f >> 2;
                    idx = idxSub + 1;
                } else {
                    idx = f >> 2;
                    idxSub = idx + 1;
                }
                if (info & 0x20000000) {
                    const s16 *keys16 = (const s16 *)keys;
                    v = keys16[idx];
                    v = v + (v << 1);
                    *out = (v + keys16[idxSub]) >> 2;
                } else {
                    const int *keys32 = (const int *)keys;
                    v = keys32[idx];
                    *out = (int)(((s64)v * 3 + (s64)keys32[idxSub]) >> 2);
                }
                return;
            } else {
                idx = f >> 2;
                goto interp2;
            }
        } else {
            idx = f >> 2;
            goto plain;
        }
    }
interp2:
    if (info & 0x20000000) {
        const s16 *keys16 = (const s16 *)keys;
        *out = (*(keys16 + idx) + *(keys16 + idx + 1)) >> 1;
    } else {
        const int *keys32 = (const int *)keys;
        *out = (*(keys32 + idx) >> 1) + (*(keys32 + idx + 1) >> 1);
    }
    return;
plain:
    if (info & 0x20000000) {
        *out = ((const s16 *)keys)[idx];
    } else {
        *out = ((const int *)keys)[idx];
    }
}
