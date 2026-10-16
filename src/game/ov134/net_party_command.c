/*
 * file:     net_party_command.c
 * unit:     yes
 * function: NET_PARTY_COMMAND_GetEntry, NET_PARTY_COMMAND_IsHandleFor, NET_PARTY_COMMAND_Init, NET_PARTY_COMMAND_Exit, NET_PARTY_COMMAND_Main, NET_PARTY_COMMAND_BuildPartyList, NET_PARTY_COMMAND_BuildStatusParam
 * address:  0x021DC860
 * region:   ov134
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   sNetPartyCommandTable 0x021DCC9C data a4
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   ov90_id 0x0000005A data a1
 *   PLIST_COMM_End 0x021B6108 thumb ov090
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   PLIST_COMM_Update 0x021B6114 thumb ov090
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   gPartyListProcData 0x021BED00 data a4 ov091
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov91_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   POKE_REGULATION_AdjustPartyLevels 0x0201A2A8 thumb
 *   func_0200873C 0x0200873C thumb
 *   PLIST_COMM_Start 0x021B6100 thumb ov090
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb  arm9
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb  arm9
 */
#include "../ov131/p_status_types.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct NetHandle;
struct Party;
struct PartyMon;

/* Entry table indexed by NET_PARTY_COMMAND_GetEntry. */
typedef struct NetPartyEntryTable {
    u8 pad_0[0xF0];
    int entries[1];
} NetPartyEntryTable;

/* Arguments of the ov134 party exchange network command (0x2C bytes). */
typedef struct NetPartyArgs {
    u8 *status;         /* 0x00: my status block */
    void *party;        /* 0x04: party array handed to the list */
    u32 listArgB;       /* 0x08: copied to the list parameter at 0x78 */
    u8 listArgC;        /* 0x0C: copied to the list parameter at 0x7C */
    u8 pad_0D[3];
    u32 listArgA;       /* 0x10: copied to the list parameter at 0x74 */
    void *save;         /* 0x14: save control block */
    u8 pad_18[0x14];    /* 0x18..0x2B */
} NetPartyArgs;

/* View of the ov090/ov091 party list parameter block (PartyListParam in ov012). */
typedef struct NetPartyParam {
    void *party;            /* 0x00: party array */
    u32 selectedCount;      /* 0x04 */
    u32 listArgB_out;       /* 0x08 */
    void *options;          /* 0x0C: POKE_REGULATION data (options in ov012) */
    u32 listArgA_out;       /* 0x10 */
    u8 *status;             /* 0x14: my status block */
    u8 pad_18[0x18];        /* 0x18..0x2F */
    u16 listType;           /* 0x30 */
    u16 pad_32;
    u32 maxCount;           /* 0x34: 26 */
    u32 mode;               /* 0x38: from status[0xBA] */
    u32 cursor;             /* 0x3C: position returned by the list */
    u32 resultKind;         /* 0x40: 1 when the list is ready */
    u16 resultAux;          /* 0x44 */
    u16 resultAux2;         /* 0x46 */
    u8 confirm;             /* 0x48 */
    u8 selectedOrder[6];    /* 0x49: 1-based slots chosen by the player */
    u8 pad_4F;
    u32 scroll;             /* 0x50 */
    u16 cursorPos;          /* 0x54 */
    u16 pad_56;
    u32 page;               /* 0x58 */
    u32 pad_5C;
    u16 countdown;          /* 0x60: from status[0xB9] */
    u16 commStep;           /* 0x62: PLIST_COMM syncStep and commFinished */
    u32 partyMode;          /* 0x64: 1 or 2 from status[0xBA] */
    u8 pad_68[0x0C];        /* 0x68..0x73 */
    u32 listArgA;           /* 0x74: from the command arguments */
    u32 listArgB;           /* 0x78: from the command arguments */
    u8 listArgC;            /* 0x7C: from the command arguments */
    u8 pad_7D[0x0F];        /* 0x7D..0x8B */
    u32 statusFlags;        /* 0x8C: from status[0xB8] */
    u32 statusPresent;      /* 0x90: 1 when the countdown runs */
    u8 receivedCount;       /* 0x94: PLIST_COMM status message count */
    u8 pad_95[3];           /* 0x95..0x97: gap before the status parameter */
} NetPartyParam;

/* Work of the ov091 party list process that exchanges the parties. */
typedef struct NetPartyListProc {
    u8 pad_0[4];
    void *sourceParty;      /* 0x04: party to read the members from */
    u8 pad_8[0x14];
    void *destParty;        /* 0x1C: party to add the members to */
    u8 pad_20[8];
    u32 aborted;            /* 0x28: 1 when a network error ended the exchange */
} NetPartyListProc;

/* Work of the ov134 party exchange network command (0x100 bytes). */
typedef struct NetPartyWork {
    u32 state;              /* 0x00: step of the exchange sequence */
    NetPartyParam list;     /* 0x04: party list parameter block */
    PStatusParam status;    /* 0x9C: status screen parameter block */
    u8 elapsedAccum;        /* 0xC4: accumulated frames of the current step */
    u8 pad_C5[3];
    u32 lastFrame;          /* 0xC8: frame of the last update */
    void *procHandle;       /* 0xCC: PROCSYS handle of the party list process */
    NetPartyArgs args;      /* 0xD0: copy of the command arguments */
    u16 kind;               /* 0xFC: PROCSYS work kind (4) */
    u8 pad_FE[2];
} NetPartyWork;

extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct NetHandle *handle);
extern void *PROCSYS_AllocProcWork(void *sys, u32 size, u32 heap);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void *PROCSYS_Create(int kind);
extern void GFL_NET_COMMAND_AddCommandTable(u32 commandBase, const void *table, u32 count, void *work);
extern void PLIST_COMM_End(void *work);
extern void GF_OVERLAY_Unload(int overlayId);
extern void PROCSYS_Delete(void *handle);
extern void PROCSYS_FreeProcWork(void *handle);
extern void PLIST_COMM_Update(void *work);
extern int GF_OVERLAY_Load(int overlayId);
extern void PROCSYS_Push(void *handle, int a, const void *procData, void *work);
extern u32 PROCSYS_Main(void *handle);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern u32 POKEPARTY_Add(struct Party *party, const struct PartyMon *mon);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 GFL_NET_SendData(struct NetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 c, u32 d, u32 e);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct NetHandle *handle, unsigned int syncNo, unsigned int syncGroup);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct NetHandle *handle, unsigned int syncNo, unsigned int syncGroup);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern int GFL_NET_GetRunState(void);
extern int DWC_RAPCOMMON_HandleNetError(int a, int b);
extern void *GAME_DATA_GetSaveControl(void *sys);
extern void POKE_REGULATION_AdjustPartyLevels(void *regulation, void *party);
extern void *func_0200873C(void *sys);
extern void PLIST_COMM_Start(void *work);
extern u8 *GAME_DATA_GetMyStatus(void *sys);
extern void *ZUKAN_SAVE_GetFromGameData(void *sys);
extern u32 POKEPARTY_GetCount(void *party);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(void *save);
int NET_PARTY_COMMAND_GetEntry(int index, NetPartyEntryTable *table);
void NET_PARTY_COMMAND_IsHandleFor(u32 value, u32 a, u32 b, u32 c, void *expected);
int NET_PARTY_COMMAND_Init(void *sys, int unused, const NetPartyArgs *args);
int NET_PARTY_COMMAND_Exit(void *arg0, u32 a, u32 b, char *work);
int NET_PARTY_COMMAND_Main(void *unused0, void *unused1, u8 *listProc, u8 *work);
void NET_PARTY_COMMAND_BuildPartyList(NetPartyArgs *args, void *unused, NetPartyParam *param);
void NET_PARTY_COMMAND_BuildStatusParam(NetPartyArgs *args, void *unused, PStatusParam *statusParam);
extern const u32 sNetPartyCommandTable[];
extern u32 g_02FFFC3C;
extern const char ov90_id[];
extern const u32 gPartyListProcData[], gPokeStatusProcData[];
extern const char ov91_id[], ov131_id[];



int NET_PARTY_COMMAND_GetEntry(int index, NetPartyEntryTable *table)
{
    return table->entries[index];
}



/*
 * extent: trailing 2-byte alignment padding; early return keeps the final unused compare.
 */
void NET_PARTY_COMMAND_IsHandleFor(u32 value, u32 a, u32 b, u32 c, void *expected)
{
    if (expected == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (value != GFL_NET_GetHandleNetID((struct NetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) return;
    }
}



int NET_PARTY_COMMAND_Init(void *sys, int unused, const NetPartyArgs *args)
{
    u8 *work;
    work = PROCSYS_AllocProcWork(sys, 0x100, 4);
    MI_CpuFill8(work, 0, 0x100);
    *(NetPartyArgs *)(work + 0xd0) = *args;
    ((NetPartyWork *)work)->kind = 4;
    ((NetPartyWork *)work)->procHandle = PROCSYS_Create(((NetPartyWork *)work)->kind);
    GFL_NET_COMMAND_AddCommandTable(0x2f00, (const void *)sNetPartyCommandTable, 1, work);
    NET_PARTY_COMMAND_BuildPartyList((NetPartyArgs *)args, work, (NetPartyParam *)(work + 4));
    NET_PARTY_COMMAND_BuildStatusParam((NetPartyArgs *)args, work, (PStatusParam *)(work + 0x9c));
    work[0xc4] = 0;
    ((NetPartyWork *)work)->lastFrame = g_02FFFC3C;
    ((NetPartyWork *)work)->state = 0;
    return 1;
}



int NET_PARTY_COMMAND_Exit(void *arg0, u32 a, u32 b, char *work)
{
    PLIST_COMM_End(work + 4);
    GF_OVERLAY_Unload((int)ov90_id);
    PROCSYS_Delete(((NetPartyWork *)work)->procHandle);
    PROCSYS_FreeProcWork(arg0);
    return 1;
}



int NET_PARTY_COMMAND_Main(void *unused0, void *unused1, u8 *listProc, u8 *work)
{
    u32 frame;
    u8 elapsed;
    u8 i;
    void *handle;
    int dataSize;
    if (((NetPartyWork *)work)->list.statusPresent == 1 && ((NetPartyWork *)work)->list.countdown != 0) {
        frame = g_02FFFC3C;
        elapsed = frame - ((NetPartyWork *)work)->lastFrame;
        ((NetPartyWork *)work)->elapsedAccum += elapsed;
        ((NetPartyWork *)work)->lastFrame = frame;
        if (((NetPartyWork *)work)->elapsedAccum > 60) {
            ((NetPartyWork *)work)->list.countdown -= 1;
            ((NetPartyWork *)work)->elapsedAccum -= 60;
        }
    }
    PLIST_COMM_Update(work + 4);
    switch (((NetPartyWork *)work)->state) {
    case 0:
        GF_OVERLAY_Load((int)ov91_id);
        PROCSYS_Push(((NetPartyWork *)work)->procHandle, -1, gPartyListProcData, work + 4);
        ((NetPartyWork *)work)->state = 1;
        break;
    case 1:
        if (PROCSYS_Main(((NetPartyWork *)work)->procHandle) == 0) ((NetPartyWork *)work)->state = 2;
        break;
    case 2:
        GF_OVERLAY_Unload((int)ov91_id);
        if (((NetPartyWork *)work)->list.resultKind == 1) {
            ((NetPartyWork *)work)->status.pos = ((NetPartyWork *)work)->list.cursor;
            ((NetPartyWork *)work)->state = 3;
        } else {
            ((NetPartyListProc *)listProc)->aborted = 0;
            ((NetPartyWork *)work)->state = 6;
        }
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            if (((NetPartyWork *)work)->list.selectedOrder[i] != 0) {
                void *mon;
                mon = POKEPARTY_GetMember(((NetPartyListProc *)listProc)->sourceParty, ((NetPartyWork *)work)->list.selectedOrder[i] - 1);
                POKEPARTY_Add(((NetPartyListProc *)listProc)->destParty, mon);
            }
        }
        ((NetPartyWork *)work)->state = 7;
        break;
    case 7:
        handle = GFL_NET_HANDLE_GetCurrentHandle();
        dataSize = POKE_REGULATION_GetDataSize();
        if (GFL_NET_SendData((struct NetHandle *)handle, 255, 0x2f00, dataSize, (const void *)*(u32 *)&((NetPartyListProc *)listProc)->destParty, 0, 0, 1) != 0) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct NetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 20, 47);
            ((NetPartyWork *)work)->state = 8;
        }
        break;
    case 8:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct NetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 20, 47) != 0) return 1;
        break;
    case 3:
        GF_OVERLAY_Load((int)ov131_id);
        PROCSYS_Push(((NetPartyWork *)work)->procHandle, -1, gPokeStatusProcData, work + 156);
        ((NetPartyWork *)work)->state = 4;
        break;
    case 4:
        if (((NetPartyWork *)work)->list.statusPresent == 1 && ((NetPartyWork *)work)->list.countdown == 0) ((NetPartyWork *)work)->status.forceExit = 1;
        if (GFL_NET_ERR_GetErrorLevel() != 0) ((NetPartyWork *)work)->status.forceExit = 1;
        if (PROCSYS_Main(((NetPartyWork *)work)->procHandle) == 0) ((NetPartyWork *)work)->state = 5;
        break;
    case 5:
        GF_OVERLAY_Unload((int)ov131_id);
        ((NetPartyWork *)work)->list.cursor = ((NetPartyWork *)work)->status.pos;
        ((NetPartyWork *)work)->state = 0;
        break;
    }
    if (GFL_NET_GetRunState() != 0 && ((NetPartyWork *)work)->state != 1 && ((NetPartyWork *)work)->state != 2 && ((NetPartyWork *)work)->state != 4 && ((NetPartyWork *)work)->state != 5) {
        if (DWC_RAPCOMMON_HandleNetError(1, 1) != 0) {
            ((NetPartyListProc *)listProc)->aborted = 1;
            return 1;
        }
    }
    return 0;
}



void NET_PARTY_COMMAND_BuildPartyList(NetPartyArgs *args, void *unused, NetPartyParam *param)
{
    u8 *status;
    void *save;
    u8 i;
    status = args->status;
    save = GAME_DATA_GetSaveControl(args->save);
    param->party = args->party;
    POKE_REGULATION_AdjustPartyLevels(status, param->party);
    param->selectedCount = 0;
    param->listArgB_out = 0;
    param->options = func_0200873C(save);
    param->listArgA_out = 0;
    param->listType = 0;
    param->maxCount = 26;
    param->status = status;
    switch (status[0xba]) {
    case 0:
        param->mode = 0;
        param->partyMode = 1;
        break;
    case 1:
        param->mode = 1;
        param->partyMode = 1;
        break;
    case 2:
        param->mode = 1;
        param->partyMode = 1;
        break;
    case 3:
        param->mode = 1;
        param->partyMode = 1;
        break;
    case 4:
        param->mode = 2;
        param->partyMode = 2;
        break;
    }
    param->resultAux = 0;
    param->resultAux2 = 0;
    param->confirm = 0;
    param->cursor = 0;
    param->resultKind = 0;
    for (i = 0; i < 6; i++) param->selectedOrder[i] = 0;
    param->scroll = 0;
    param->page = 0;
    param->cursorPos = 0;
    param->listArgA = args->listArgA;
    param->listArgB = args->listArgB;
    param->listArgC = args->listArgC;
    param->statusFlags = status[184];
    if (status[185] != 0) {
        param->statusPresent = 1;
        param->countdown = status[185];
    } else {
        param->statusPresent = 0;
        param->countdown = 0;
    }
    param->receivedCount = 0;
    GF_OVERLAY_Load((int)ov90_id);
    PLIST_COMM_Start(param);
}

void NET_PARTY_COMMAND_BuildStatusParam(NetPartyArgs *args, void *unused, PStatusParam *statusParam)
{
    void *save;
    void *zukan;
    save = GAME_DATA_GetSaveControl(args->save);
    GAME_DATA_GetMyStatus(args->save);
    zukan = ZUKAN_SAVE_GetFromGameData(args->save);
    statusParam->ppd = (void *)*(u32 *)&args->party;
    statusParam->config = (void *)*(u32 *)&args->save;
    statusParam->callerData = func_0200873C(save);
    statusParam->ppt = 1;
    statusParam->mode = 1;
    statusParam->max = POKEPARTY_GetCount(args->party);
    statusParam->pos = 0;
    statusParam->page = 0;
    statusParam->retMovePos = 0;
    statusParam->retSel = 0;
    statusParam->newMove = 0;
    statusParam->isNationalDex = ZUKAN_SAVE_IsNationalDexEnabled(zukan);
    statusParam->canUseButtons = 0;
    statusParam->forceExit = 0;
}
