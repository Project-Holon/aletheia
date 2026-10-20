#ifndef BTL_CLIENT_TYPES_H
#define BTL_CLIENT_TYPES_H

/* Battle client: one per side of the battle (player, opponent or remote player).
   Allocated by the constructor at the start of btl_client.c. The including file
   defines u8, s8, u16, u32 and u64 first. */

#include "../ov093/btl_calc_types.h"
#include "../ov093/btlv_core_types.h"
#include "../ov093/btl_field_types.h"
#include "../ov093/btl_rec_types.h"
#include "../ov095/btl_pick_list_types.h"

struct BtlMain;
struct BtlSide;
struct BtlSideSlot;
struct BtlPokeParam;
struct BtlvCore;
struct BtlServer;

struct BtlClient;
typedef struct BtlClient BtlClient;

/* Step function: returns nonzero when the step is finished. The state int is
   BtlClient.stepState. */
typedef int (*BtlClientStepFn)(BtlClient *, int *);
/* Sequence function: arguments are the client, the sequence state and the cursor buffer. */
typedef int (*BtlClientSeqFn)(BtlClient *, int *, int *);
typedef int (*BtlClientTickFn)(BtlClient *);
typedef u32 (*BtlClientSubFn)(BtlClient *, u32 *);

/* State bits of the client, byte 0x1B2. */
typedef struct {
    u8 resultPending : 1;
    u8 commandIssued : 1;
    u8 moveSelected : 1;
    u8 requestSet : 1;
    u8 windowOpen : 1;
    u8 windowDone : 1;
    u8 reserved : 2;
} BtlClientFlags;

typedef union {
    u8 raw;
    BtlClientFlags bit;
} BtlClientFlagsUnion;

/* Replay position counter of a remote client: the viewer steps a target
   number up or down, and the client confirms it or times out. */
typedef struct {
    u8 state; /* 0 selecting, 1 fading out, 2 finished */
    u8 mode; /* how the selection ended: 1 confirmed by the viewer, 2 timed out */
    u8 replaying : 1; /* a replay target is set */
    u8 fadeStarted : 1;
    u8 fadeDone : 1;
    u8 advancePending : 1; /* current should move one step */
    u8 locked : 1; /* selection not allowed yet */
    u8 disabled : 1;
    u8 rest : 2;
    u8 pad3;
    u16 confirmDelay; /* frames until the target is confirmed on its own */
    u16 current; /* position reached */
    u16 target; /* position the viewer selected */
    u16 maximum; /* highest selectable position */
    u16 tick; /* replay step counter */
} BtlClientCounter;

struct BtlClient {
    struct BtlMain *main; /* 0x000 battle main object */
    struct BtlSide *side; /* 0x004 battle side data */
    struct BtlPokeParam *activeMon; /* 0x008 party member the client is acting for */
    union BtlAction *actionCursor; /* 0x00C cursor into the chosen action record */
    BtlRecBuffer *recBuffer; /* 0x010 buffer that records the battle packets, or 0 */
    BtlRecReader *recReader; /* 0x014 reader of the recording that a replay client plays */
    BtlClientCounter counter; /* 0x018 replay position counter */
    u8 pad026[2];
    BtlClientTickFn tickFn; /* 0x028 per-frame function */
    struct BtlClientSet defeatedClients; /* 0x02C clients defeated, sent by the remote */
    BtlFieldState *battleField; /* 0x034 field state */
    BtlRngState rngSave; /* 0x038 scratch copy of the random number state, written by the target preview */
    void *netChannel; /* 0x050 network channel */
    struct BtlvCore *view; /* 0x054 battle view the client draws to */
    struct BtlvMessage messageA; /* 0x058 message parameters, first set */
    struct BtlvMessage messageB; /* 0x07C message parameters, second set */
    struct BtlServer *requestParam; /* 0x0A0 parameter of the pending request */
    u8 recvEntry[0x18]; /* 0x0A4 entry received from the remote */
    u32 recordKey; /* 0x0BC key of the record being played */
    u32 actionKey; /* 0x0C0 key of the action being sent */
    u8 windowMode; /* 0x0C4 message window mode */
    u8 pad0C5[0x3];
    BtlClientStepFn stepFn; /* 0x0C8 current step function */
    int stepState; /* 0x0CC state of the current step */
    BtlClientSubFn subFn; /* 0x0D0 sub step function */
    u32 subState; /* 0x0D4 state of the sub step */
    u8 *sendData; /* 0x0D8 data to send */
    u32 sendSize; /* 0x0DC size of the data to send */
    int sendFlag; /* 0x0E0 send flag word */
    u16 timeLimit; /* 0x0E4 time limit */
    u16 timeElapsed; /* 0x0E6 time elapsed */
    u16 trainerItems[4]; /* 0x0E8 items the trainer can use in battle, 0 for an empty entry */
    void *recorder; /* 0x0F0 battle recorder */
    BtlRngState rng; /* 0x0F4 random number generator state */
    s8 slotOrder[6]; /* 0x10C order of the slots */
    u8 chosenSlots[4]; /* 0x112 slots chosen this turn */
    u8 pad116[0x2];
    struct BtlSideSlot *sideData; /* 0x118 side data of this client */
    u8 slotCount; /* 0x11C number of slots */
    u8 slotIndex; /* 0x11D slot being handled */
    s8 prevSlotIndex; /* 0x11E slot handled before */
    u8 slotsDone; /* 0x11F all slots handled */
    u8 redrawRequest; /* 0x120 redraw request */
    u8 clientIdCopy; /* 0x121 copy of the client id */
    u8 pad122[0x2];
    union BtlAction actions[3]; /* 0x124 action word per slot */
    u8 slotFlags[3]; /* 0x130 flag byte per slot */
    u8 pad133;
    void *workBuffer; /* 0x134 work buffer (0xBC0 bytes) */
    u32 seqArgs[16]; /* 0x138 arguments of the running command, filled by the server command reader */
    int seqCode; /* 0x178 code of the running sequence */
    BtlClientSeqFn seqFn; /* 0x17C function of the running sequence */
    int seqState; /* 0x180 state of the running sequence */
    BtlSlotChoices slotChoices; /* 0x184 choice record per slot, filled by the choice builder and passed to the view */
    BtlPickList choiceFlags; /* 0x190 slots picked so far, filled with slotChoices */
    u8 pad199;
    u16 heapId; /* 0x19A heap the client allocates from */
    u16 lastMonValue; /* 0x19C last value of party member parameter 13, compared on later turns */
    u16 receivedCode; /* 0x19E command code read from the remote */
    u16 slotLinkWords[3]; /* 0x1A0 word per slot exchanged over the link */
    u8 clientId; /* 0x1A6 client id */
    u8 kind; /* 0x1A7 0 player, 1 opponent, 2 remote */
    u8 stepPhase; /* 0x1A8 phase of the step function state machine (0 to 6) */
    u8 viewLocked; /* 0x1A9 set while the view is held for a message, cleared on release */
    u8 isComm; /* 0x1AA communication battle */
    u8 pointCounter; /* 0x1AB points shown by the view, capped at 14 */
    u8 sendByte; /* 0x1AC one byte send buffer (sendData points here) */
    u8 limitReady; /* 0x1AD time limit wait finished */
    u8 requestId; /* 0x1AE id of the pending request, 0 when none */
    u8 extraActionCount; /* 0x1AF actions added beyond slotCount */
    u8 highlightSlot; /* 0x1B0 slot the view highlights */
    u8 highlightKind; /* 0x1B1 kind of the highlighted slot, 4 when none */
    BtlClientFlagsUnion flags; /* 0x1B2 state flags */
    u8 pairCount; /* 0x1B3 number of pairs */
    u8 pad1B4;
    u8 pairs[3]; /* 0x1B5 pairs */
};

typedef char BtlClient_SizeCheck[(sizeof(BtlClient) == 0x1B8) ? 1 : -1];

#endif
