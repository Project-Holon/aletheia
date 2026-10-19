/*
 * function: WIFIBATTLEMATCH_NET_TaskStepF
 * address: 0x021D51BC
 * packet: pkt_ov175_021D51BC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * DA36C receives the live context in r0 here despite its no-argument body.
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepG 0x021D54E8 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   DWC_RAPCOMMON_CreateSubHeap 0x02156E30 thumb
 *   DWC_RAPCOMMON_SetHeapTag 0x02156F50 thumb
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetSaveState 0x021E8AC0 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupMatchReport 0x021DA5B0 thumb ov175
 *   WIFIBATTLEMATCH_NET_ScProcess 0x021DA6B8 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetReportState 0x021DADAC thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_DisconnectWifi 0x021DA36C thumb ov175
 *   WIFIBATTLEMATCH_NET_ClearCancelFlag 0x021DA384 thumb ov175
 *   WIFIBATTLEMATCH_NET_StopMatchmaking 0x021DA390 thumb ov175
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   MET_TRAINERS_Insert 0x0200ED54 thumb
 *   func_02008530 0x02008530 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_NET_SetupGdbUpload 0x021DBC04 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbUpdateRecord 0x021DBDAC thumb ov175
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 w[20]; } Rec80;
typedef struct { Rec80 data; u32 last; } Rec84;
struct Big;
struct L0200ED54;
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
struct Sub0200852CObj;
extern void WIFIBATTLEMATCH_NET_TaskStepG(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void DWC_RAPCOMMON_CreateSubHeap(int, int, int, int);
extern void DWC_RAPCOMMON_SetHeapTag(int);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *, int, int, int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(unsigned, unsigned);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
extern void WIFIBATTLEMATCH_UTIL_SetSaveState(int, int);
extern void WIFIBATTLEMATCH_NET_SetupMatchReport(char *, int, int, u32, u32 *, u32);
struct Record;
extern int WIFIBATTLEMATCH_NET_ScProcess(char *p, u32 *out);
extern u32 WIFIBATTLEMATCH_NET_GetReportState(u8 *p);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(int);
extern void WIFIBATTLEMATCH_NET_ClearCancelFlag(char *);
extern int WIFIBATTLEMATCH_NET_StopMatchmaking(char *);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *MET_TRAINERS_GetFromSave(void *);
extern void MET_TRAINERS_Insert(struct L0200ED54 *, u32);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MI_CpuFill8(void *, int, unsigned);
extern void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *p, u32 mode, struct Record *src);
extern int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
#define P(k) (*(int *)(p + (k)))
#define Q(k) (*(int *)(q + (k)))
void WIFIBATTLEMATCH_NET_TaskStepF(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    Rec84 rec;
    void *list;
    int result;
    switch (*state) {
    case 0:
        if (Q(12) == 2 && P(0xf8) == 0) {
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepG);
            return;
        }
        P(0xf8) = 0;
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        *state = 1;
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(0x24), P(0x10), 37, 2);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2);
        break;
    case 2:
        WIFIBATTLEMATCH_NET_SetupMatchReport((char *)P(0x30), 1, 2, ((u32 *)Q(8))[1], (u32 *)Q(0x2c), Q(12) == 2);
        P(0xfc) = 0;
        P(0xf4) = 0;
        *state = 3;
        break;
    case 3:
        if (P(0xfc) == 0) {
            P(0xfc) = WIFIBATTLEMATCH_NET_ScProcess((void *)P(0x30), (u32 *)(p + 0xf4));
            if (P(0xfc) != 0 && P(0xf4) != 0)
                WIFIBATTLEMATCH_UTIL_SetSaveState(*(int *)Q(8), *(int *)Q(0x2c));
        }
        if (P(0xfc) == 1) {
            ((u32 *)Q(0x2c))[5] = WIFIBATTLEMATCH_NET_GetReportState((u8 *)P(0x30));
            *state = 4;
        }
        if (P(0xfc) != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, (void *)1)) {
            case 1: WIFIBATTLEMATCH_NET_DisconnectWifi(P(0x30));
            case 2: case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 4:
        DWC_RAPCOMMON_DestroySubHeap();
        if (Q(12) == 2) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepG);
        else *state = 5;
        break;
    case 5:
        list = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(*(struct Big **)Q(8)));
        MET_TRAINERS_Insert(list, func_02008530((void *)Q(0x18)));
        *state = 6;
        WIFIBATTLEMATCH_NET_ClearCancelFlag((char *)P(0x30));
        break;
    case 6:
        if (WIFIBATTLEMATCH_NET_StopMatchmaking((char *)P(0x30))) {
            if (*(int *)((int *)P(0x40))[8] == 0) *state = 8;
            else {
                WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(0x24), P(0x10), 42, 2);
                *state = 14;
                WIFIBATTLEMATCH_UTIL_SetRequest(sys, 7);
            }
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: *state = 7; break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 7:
        if (*(int *)Q(0x20) == 0) *state = 8;
        break;
    case 8:
        MI_CpuFill8(&rec, 0, 0x54);
        rec.data = *(Rec80 *)((int *)P(0x40))[9];
        rec.last = *(u32 *)((int *)P(0x40))[10];
        WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)P(0x30), 3, (struct Record *)(&rec));
        *state = 9;
        break;
    case 9:
        result = WIFIBATTLEMATCH_NET_GdbUpdateRecord((char *)P(0x30));
        if (result == 1) {
            *(int *)((int *)P(0x40))[8] = 0x708;
            *state = 10;
        }
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, 0)) {
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                *(int *)((int *)P(0x40))[8] = 0x708;
                break;
            case 1:
                *(int *)((int *)P(0x40))[8] = 0x708;
                *state = 10;
                break;
            }
        }
        break;
    case 10:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(0x24), P(0x10), 88, 1);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 11);
        break;
    case 11:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(0x24), P(0x10), 40, 2);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12);
        break;
    case 12:
        GAME_DATA_SaveStart(*(int *)Q(8));
        *state = 13;
        break;
    case 13:
        switch (GAME_DATA_SaveMain(*(u8 **)Q(8))) {
        case 0: case 1: break;
        case 2: case 3:
            Q(4) = 2;
            WIFIBATTLEMATCH_UTIL_ClearCallback(sys);
            break;
        }
        break;
    case 14:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)P(0x24))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}
