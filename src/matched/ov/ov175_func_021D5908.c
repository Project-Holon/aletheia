/*
 * function: WIFIBATTLEMATCH_NET_TaskStepL
 * address: 0x021D5908
 * packet: pkt_ov175_021D5908
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * DC1A0's live return is tested here; DA434/DA36C receive the context r0.
 * symbols:
 *   WIFIBATTLEMATCH_NET_HandleCancel 0x021D6854 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepP 0x021D60E0 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepB 0x021D4608 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskCleanupA 0x021D61A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepL 0x021D5908 thumb ov175
 *   WIFIBATTLEMATCH_NET_TaskStepO 0x021D6048 thumb ov175
 *   WIFIBATTLEMATCH_NET_CopyBsubwayStat 0x021D6724 thumb ov175
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible 0x021E7E0C thumb ov177
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_CopyBoxRecord 0x021D65F0 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetMatchKey 0x021DA0D4 thumb ov175
 *   WIFIBATTLEMATCH_NET_ClearError 0x021D6954 thumb ov175
 *   WIFIBATTLEMATCH_NET_StartMatchmaking 0x021DA1E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetTimingSyncRange 0x021D9ED4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsTimingSyncRange 0x021D9EEC thumb ov175
 *   WIFIBATTLEMATCH_NET_SendRegData 0x021DC1A0 thumb ov175
 *   WIFIBATTLEMATCH_NET_TakeRegData 0x021DC1E4 thumb ov175
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_ToChars 0x02045A38 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_OAM_Check5BEC 0x02025BEC thumb
 *   PMSI_PARAM_IsValid 0x020245D4 thumb
 *   PMSI_PARAM_InitSentence 0x020242A4 thumb
 *   WIFIBATTLEMATCH_NET_VerifyPartySignature 0x021D67BC thumb ov175
 *   WIFIBATTLEMATCH_NET_DisconnectWifi 0x021DA36C thumb ov175
 *   WIFIBATTLEMATCH_NET_CheckProfanity 0x021DCA28 thumb ov175
 *   WIFIBATTLEMATCH_NET_ProfanityProcess 0x021DCAEC thumb ov175
 *   WIFIBATTLEMATCH_NET_TakeSessionResult 0x021DA45C thumb ov175
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIFIBATTLEMATCH_NET_DeleteSprite 0x021D65C8 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_NET_StartBoxAnim 0x021D63F8 thumb ov175
 *   func_02040588 0x02040588 arm
 *   WIFIBATTLEMATCH_NET_IsRegCardReady 0x021D6460 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   WIFIBATTLEMATCH_NET_SendSessionQuery 0x021DA434 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 */
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct MsgBank; struct U16Vec; struct MsgRec; struct T;
extern int WIFIBATTLEMATCH_NET_HandleCancel(char *, int, int);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);
extern void WIFIBATTLEMATCH_NET_TaskStepP(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepB(u32 sys, int *state, u32 *p);
extern void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_TaskStepO(unsigned sys, int *state, int *p);
extern void WIFIBATTLEMATCH_NET_CopyBsubwayStat(u32 *, u32 *);
extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **, int);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *, int, int, int);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
extern void WIFIBATTLEMATCH_NET_CopyBoxRecord(u32 *, u32 *);
struct Rec;
extern void WIFIBATTLEMATCH_NET_SetMatchKey(char *obj, int mode, int extra, int group, int *rec);
extern void WIFIBATTLEMATCH_NET_ClearError(char *);
extern int WIFIBATTLEMATCH_NET_StartMatchmaking(char *obj);
extern void WIFIBATTLEMATCH_NET_SetTimingSyncRange(char *, u32);
extern int WIFIBATTLEMATCH_NET_IsTimingSyncRange(char *);
extern u32 WIFIBATTLEMATCH_NET_SendRegData(char *obj, u32 data);
extern u32 WIFIBATTLEMATCH_NET_TakeRegData(char *, char **);
extern int POKE_REGULATION_GetDataSize(void);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u16 STRBUF_GetEosChar(void);
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *, u32);
extern void STRBUF_ToChars(struct U16Vec *, u16 *, unsigned int);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern unsigned int BMP_OAM_Check5BEC(unsigned int, unsigned int, unsigned int);
extern unsigned int PMSI_PARAM_IsValid(struct T *, unsigned int);
extern void PMSI_PARAM_InitSentence(void *, unsigned int);
extern int WIFIBATTLEMATCH_NET_VerifyPartySignature(char *, u16);
extern void WIFIBATTLEMATCH_NET_DisconnectWifi(int);
extern void WIFIBATTLEMATCH_NET_CheckProfanity(char *, u32, u16);
extern int WIFIBATTLEMATCH_NET_ProfanityProcess(char *, int *);
extern u32 WIFIBATTLEMATCH_NET_TakeSessionResult(char *);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void WIFIBATTLEMATCH_NET_DeleteSprite(char *);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(unsigned, unsigned);
extern void WIFIBATTLEMATCH_NET_StartBoxAnim(unsigned int *, unsigned int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int WIFIBATTLEMATCH_NET_IsRegCardReady(char *);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
extern int WIFIBATTLEMATCH_NET_SendSessionQuery(int);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(unsigned);
#define P(k) (*(int *)(p + (k)))
#define Q(k) (*(int *)(q + (k)))
#define TIMER (*(u32 *)(p + 0xe0))
#define TIMEOUT (*(u32 *)(p + 0xe8))
void WIFIBATTLEMATCH_NET_TaskStepL(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired;
    char *incoming, *data;
    int bad;
    u32 size;
    u32 buf[4];
    struct MsgBank *bank;
    struct U16Vec *str;
    if (*state >= 3 && *state < 13) enable = 1;
    if (*state < 11 || *state > 12) allow = 1; else allow = 0;
    result = WIFIBATTLEMATCH_NET_HandleCancel(p, enable, allow);
    if (result == 3) {
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepP);
        return;
    }
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_NET_CopyBsubwayStat((u32 *)Q(0x14), (u32 *)p); *state = 1; break;
    case 1:
        P(0xe4) = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(0x24), P(0x10), 33, 0);
        *state = 2; break;
    case 2:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepB); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        WIFIBATTLEMATCH_NET_CopyBoxRecord(buf, (u32 *)p);
        WIFIBATTLEMATCH_NET_SetMatchKey((void *)P(0x30), 3, 0, ((int *)Q(8))[1], (int *)buf);
        *state = 3; break;
    case 3:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepB);
            WIFIBATTLEMATCH_NET_ClearError(p); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        result = WIFIBATTLEMATCH_NET_StartMatchmaking((void *)P(0x30));
        if (result == 1) { TIMEOUT = 0; *state = 6; }
        else if (result == 2) *state = 2;
        break;
    case 4: case 5: break;
    case 6:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(0x30), 20); *state = 7; TIMEOUT = 0; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(0x30))) { TIMEOUT = 0; *state = 8; }
        timed = 1; break;
    case 8:
        if (result == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegData((char *)P(0x30), Q(0x14))) { TIMEOUT = 0; *state = 9; }
            timed = 1;
        }
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_TakeRegData((char *)P(0x30), &incoming)) {
            data = (char *)Q(0x18);
            size = POKE_REGULATION_GetDataSize() + 0xd4;
            MI_CpuCopy8(incoming, data, size);
            empty = 1;
            for (i = 0; i < 8; i++) if (((u16 *)data)[i] == STRBUF_GetEosChar()) empty = 0;
            if (empty) {
                bank = func_02045B38(0, 2, 0xd2, 0x8057);
                str = func_02045EC0(bank, 0x8057);
                STRBUF_ToChars(str, (u16 *)data, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete((struct Rec *)bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) data[0x1d] = 0;
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
            }
            if (!BMP_OAM_Check5BEC((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0;
            }
            if (!PMSI_PARAM_IsValid((struct T *)(data + 0x38), 0x8057)) PMSI_PARAM_InitSentence(data + 0x38, 1);
            TIMEOUT = 0; *state = 10;
        }
        timed = 1; break;
    case 10:
        if (WIFIBATTLEMATCH_NET_VerifyPartySignature((char *)Q(0x18), 0x57)) *state = 11;
        else {
            WIFIBATTLEMATCH_NET_DisconnectWifi(P(0x30));
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepL);
        }
        break;
    case 11:
        WIFIBATTLEMATCH_NET_CheckProfanity((char *)P(0x30), Q(0x18), 0x57); *state = 12; break;
    case 12:
        if (WIFIBATTLEMATCH_NET_ProfanityProcess((char *)P(0x30), &bad)) {
            *(int *)((int *)P(0x40))[16] = bad; *state = 13;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepO);
            WIFIBATTLEMATCH_NET_ClearError(p); break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 13:
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(0x30), 21); TIMEOUT = 0; *state = 14;
        }
        break;
    case 14:
        if (WIFIBATTLEMATCH_NET_TakeSessionResult((char *)P(0x30)) == 0 && WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(0x30))) *state = 15;
        timed = 1; break;
    case 15:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(0x30), 22); TIMEOUT = 0; *state = 16; break;
    case 16:
        timed = 1;
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(0x30))) *state = 17;
        break;
    case 17:
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
        GFL_USE_PlaySeDefaultVolume(0x63a); WIFIBATTLEMATCH_NET_DeleteSprite(p);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(0x24), P(0x10), 34, 1);
        *state = 25; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 18); break;
    case 18:
        if (TIMER++ > 120) {
            TIMER = 0; WIFIBATTLEMATCH_NET_StartBoxAnim((unsigned int *)p, Q(0x18)); func_02040588(0, 0); *state = 19;
        }
        break;
    case 19: if (WIFIBATTLEMATCH_NET_IsRegCardReady(p)) *state = 20; break;
    case 20: if (TIMER++ > 300) { TIMER = 0; *state = 21; } break;
    case 21:
        func_02040588(0, 1); WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(0x24), P(0x10), 36, 2);
        *state = 25; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 22); break;
    case 22:
        if (TIMER++ > 60) { TIMER = 0; Q(4) = 1; WIFIBATTLEMATCH_UTIL_ClearCallback(sys); }
        break;
    case 23: if (WIFIBATTLEMATCH_NET_SendSessionQuery(P(0x30))) *state = 24; break;
    case 24: WIFIBATTLEMATCH_NET_DisconnectWifi(P(0x30)); *state = 1; break;
    case 25: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)P(0x24))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
    if (timed) {
        expired = 0;
        if (TIMEOUT++ > 2400) { TIMEOUT = 0; expired = 1; }
        if (WIFIBATTLEMATCH_NET_TakeSessionResult((char *)P(0x30))) expired = 1;
        if (expired) *state = 23;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepO);
            WIFIBATTLEMATCH_NET_ClearError(p); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
    }
}
