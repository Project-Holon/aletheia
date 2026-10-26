/*
 * file:     ringtone_sys.c
 * unit:     yes
 * function: RINGTONE_SYS_Create, RINGTONE_SYS_Delete, RINGTONE_SYS_Update, RINGTONE_SYS_Start, RINGTONE_SYS_Stop, RINGTONE_SYS_RegisterSleepCallbacks, RINGTONE_SYS_TickRing, RINGTONE_SYS_OnSleep, RINGTONE_SYS_OnWake, RINGTONE_SYS_StartRing, RINGTONE_SYS_StopRing, RINGTONE_SYS_SetBgmMuted, RINGTONE_SYS_PostEvent, RINGTONE_SYS_HandleRingTimeout
 * address:  0x02029F14
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ringtone_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   sRingtoneSysFileName     0x020A76BC  data
 *   gRingtone     0x02146944  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   UI_SetResumeAndSuspendHooks  0x0203508C  arm
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   sRingtoneTransitions   0x0209FED4  data  a1
 *   NNS_SndSetMasterVolume  0x02072788  arm
 *   PLAYER_VOLUME_FADER_SetMute  0x020287A8  thumb
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 */
#include "field_sound_system_shared_types.h"

/* Ringtone states: the sum of the two flags. */
enum RingtoneState {
    RINGTONE_STATE_IDLE = 0,
    RINGTONE_STATE_RINGING = 1,
    RINGTONE_STATE_ASLEEP = 2,
    RINGTONE_STATE_RINGING_ASLEEP = 3
};

enum RingtoneEvent {
    RINGTONE_EVENT_STOP = 0,
    RINGTONE_EVENT_START = 1,
    RINGTONE_EVENT_WAKE = 2,
    RINGTONE_EVENT_SLEEP = 3
};

#include "gfl_heap_wrap.h"


#include "ui.h"

#include "gfl_use.h"



#include "nns_snd_system.h"

#include "nns_snd_player.h"

#include "player_volume_fader.h"

extern const char sRingtoneSysFileName[];

extern Ringtone *gRingtone;

extern const u8 sRingtoneTransitions[][4];

Ringtone *RINGTONE_SYS_Create(u32 heapId, struct Fader *volumeFader);

void RINGTONE_SYS_Delete(Ringtone *ringtone);

void RINGTONE_SYS_Update(Ringtone *ringtone);

void RINGTONE_SYS_Start(Ringtone *ringtone);

void RINGTONE_SYS_Stop(Ringtone *ringtone);

void RINGTONE_SYS_RegisterSleepCallbacks(void);

int RINGTONE_SYS_TickRing(Ringtone *ringtone);

void RINGTONE_SYS_OnSleep(void *unused0);

void RINGTONE_SYS_OnWake(void *unused0);

void RINGTONE_SYS_StartRing(Ringtone *ringtone);

void RINGTONE_SYS_StopRing(Ringtone *ringtone);

void RINGTONE_SYS_SetBgmMuted(Ringtone *ringtone, u32 muted);

void RINGTONE_SYS_PostEvent(Ringtone *ringtone, int event);

void RINGTONE_SYS_HandleRingTimeout(Ringtone *ringtone);

/*
 * Creates the ringtone object (the ringtone of the Xtransceiver call), keeps
 * it in the global and registers the sleep callbacks.
 */
Ringtone *RINGTONE_SYS_Create(u32 heapId, struct Fader *volumeFader)
{
    Ringtone *ringtone = GFL_HEAP_Alloc(heapId, sizeof(*ringtone), 1, sRingtoneSysFileName, 0x72);

    ringtone->ringFramesLeft = 0;
    ringtone->volumeFader = volumeFader;
    gRingtone = ringtone;
    RINGTONE_SYS_RegisterSleepCallbacks();
    return ringtone;
}

void RINGTONE_SYS_Delete(Ringtone *ringtone)
{
    GFL_HEAP_Free(ringtone);
}

/* Per frame update. */
void RINGTONE_SYS_Update(Ringtone *ringtone)
{
    RINGTONE_SYS_HandleRingTimeout(ringtone);
}

/*
 * Start and stop are twelve byte forwarding thunks that pin the event
 * argument (a pool word and a bx); each sits in its own file so that the pool
 * word of the other stays outside its range.
 */
void RINGTONE_SYS_Start(Ringtone *ringtone)
{
    RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_START);
}

void RINGTONE_SYS_Stop(Ringtone *ringtone)
{
    RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_STOP);
}

/* Registers the sleep and wake callbacks for the global ringtone. */
void RINGTONE_SYS_RegisterSleepCallbacks(void)
{
    if (gRingtone != 0) {
        UI_SetResumeAndSuspendHooks(RINGTONE_SYS_OnSleep, RINGTONE_SYS_OnWake, gRingtone);
    }
}

/* Counts the ring time down and keeps the ring sound (slot 4) playing. Returns 1 while the ring time lasts. */
int RINGTONE_SYS_TickRing(Ringtone *ringtone)
{
    if (ringtone->ringFramesLeft != 0) {
        ringtone->ringFramesLeft = ringtone->ringFramesLeft - 1;
    }
    if (ringtone->ringFramesLeft == 0) {
        if (GFL_USE_IsSeSlotBusy(4) == 1) {
            GFL_USE_StopSeSlot(4);
        }
        return 0;
    }
    if (GFL_USE_IsSeSlotBusy(4) == 0) {
        GFL_USE_PlaySeInSlot(0x662, 4);
    }
    return 1;
}

/* Sleep callback: posts the sleep event to the global ringtone (a pool word tail call). */
void RINGTONE_SYS_OnSleep(void *unused0)
{
    RINGTONE_SYS_PostEvent(gRingtone, RINGTONE_EVENT_SLEEP);
}

/* Wake callback: posts the wake event to the global ringtone (a pool word tail call). */
void RINGTONE_SYS_OnWake(void *unused0)
{
    RINGTONE_SYS_PostEvent(gRingtone, RINGTONE_EVENT_WAKE);
}

/* Starts the ring sound (slot 4) if it is not playing and loads the ring time, 0x384 frames (15 seconds). */
void RINGTONE_SYS_StartRing(Ringtone *ringtone)
{
    if (GFL_USE_IsSeSlotBusy(4) == 0) {
        GFL_USE_PlaySeInSlot(0x662, 4);
    }
    ringtone->ringFramesLeft = 0x384;
}

/* Stops the ring sound. */
void RINGTONE_SYS_StopRing(Ringtone *ringtone)
{
    GFL_USE_StopSeSlot(4);
    ringtone->ringFramesLeft = 0;
}

/* Mutes (muted == 1) or restores the BGM sound players, and the volume fader. */
void RINGTONE_SYS_SetBgmMuted(Ringtone *ringtone, u32 muted)
{
    if (muted == 1) {
        NNS_SndPlayerSetPlayerVolume(1, 0);
        NNS_SndPlayerSetPlayerVolume(2, 0);
        NNS_SndPlayerSetPlayerVolume(3, 0);
        NNS_SndPlayerSetPlayerVolume(4, 0);
    } else {
        NNS_SndPlayerSetPlayerVolume(1, 0x7f);
        NNS_SndPlayerSetPlayerVolume(2, 0x7f);
        NNS_SndPlayerSetPlayerVolume(3, 0x7f);
        NNS_SndPlayerSetPlayerVolume(4, 0x7f);
    }
    PLAYER_VOLUME_FADER_SetMute(ringtone->volumeFader, muted);
}

/*
 * The ringtone state machine. The next state is a byte of the 4-column
 * transition table at 0x0209FED4, table[state][event]; a plain 2D subscript is
 * the addressing the image has (base + state * 4, then ldrb [event, base]).
 * State 1 and state 3 are written out separately with the same body: the image
 * has a lone b from case 1 into case 3 (cross-jumped), not a shared label.
 */
void RINGTONE_SYS_PostEvent(Ringtone *ringtone, int event)
{
    u8 nextState = sRingtoneTransitions[ringtone->state][event];

    switch (nextState) {
    case RINGTONE_STATE_IDLE:
        NNS_SndSetMasterVolume(0x7f);
        RINGTONE_SYS_SetBgmMuted(ringtone, 0);
        RINGTONE_SYS_StopRing(ringtone);
        break;
    case RINGTONE_STATE_RINGING:
        NNS_SndSetMasterVolume(0x7f);
        RINGTONE_SYS_SetBgmMuted(ringtone, 1);
        RINGTONE_SYS_StartRing(ringtone);
        break;
    case RINGTONE_STATE_ASLEEP:
        NNS_SndSetMasterVolume(0);
        RINGTONE_SYS_StopRing(ringtone);
        break;
    case RINGTONE_STATE_RINGING_ASLEEP:
        NNS_SndSetMasterVolume(0x7f);
        RINGTONE_SYS_SetBgmMuted(ringtone, 1);
        RINGTONE_SYS_StartRing(ringtone);
        break;
    }
    ringtone->state = nextState;
}

/* Per frame: when the ring time of a ringing ringtone has run out, post stop (awake) or wake (asleep). */
void RINGTONE_SYS_HandleRingTimeout(Ringtone *ringtone)
{
    int isRinging = RINGTONE_SYS_TickRing(ringtone);

    switch (ringtone->state) {
    case RINGTONE_STATE_IDLE:
        break;
    case RINGTONE_STATE_RINGING:
        if (isRinging == 0) {
            RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_STOP);
        }
        break;
    case RINGTONE_STATE_ASLEEP:
        break;
    case RINGTONE_STATE_RINGING_ASLEEP:
        if (isRinging == 0) {
            RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_WAKE);
        }
        break;
    }
}
