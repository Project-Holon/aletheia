/*
 * function: GFL_USE_UpdateFrameSubsystems
 * address:  0x020052EC
 * packet:   pkt_0200520C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02023FD8, 0200F734, 02026728 and 02010DCC (all arm) each reached only by the `bl` inside this function, so `label` has no witness outside the compared range; all 32 concrete bytes are right
 *
 * symbols:
 *   BRIGHTNESS_ChangeMain  0x02023FD8  thumb
 *   WIPE_SYS_Main  0x02022174  thumb
 *   func_0200F734  0x0200F734  thumb
 *   GFL_USE_UpdateSound  0x02005BC0  thumb
 *   PM_VOICE_StopFinished  0x020065FC  thumb
 *   GAME_BEACON_Update  0x02026728  thumb
 *   GPOWER_CountDownTimers  0x02010DCC  thumb
 *
 * Seven unconditional calls in a row, no arguments and no return value: the
 * tail of the boot sequence, run immediately after GFL_USE_VBlankHandler.  Every
 * callee is an ordinary Thumb `bl` (the second halfword's bit 12 is set in
 * all seven encodings, so none of them is a BLX to ARM code).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_UpdateFrameSubsystems.c \
 *       --func GFL_USE_UpdateFrameSubsystems --addr 0x020052EC --cc 1.1p1 --thumb
 */

extern void BRIGHTNESS_ChangeMain(void);
extern void WIPE_SYS_Main(void);
extern void func_0200F734(void);
extern void GFL_USE_UpdateSound(void);
extern void PM_VOICE_StopFinished(void);
extern void GAME_BEACON_Update(void);
extern void GPOWER_CountDownTimers(void);

void GFL_USE_UpdateFrameSubsystems(void)
{
    BRIGHTNESS_ChangeMain();
    WIPE_SYS_Main();
    func_0200F734();
    GFL_USE_UpdateSound();
    PM_VOICE_StopFinished();
    GAME_BEACON_Update();
    GPOWER_CountDownTimers();
}
