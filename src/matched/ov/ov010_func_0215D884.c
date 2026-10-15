/*
 * function: SCRCMD_MUSICAL_BufferString
 * address:  0x0215D884
 * packet:   pkt_ov010_0215D884
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: read a one-byte string kind and a word-set slot from the
 * script cursor, one argument word, and buffer the matching string into
 * the slot (player name, message-bank entries, link member names, or the
 * three placement labels of a four-way ranking).
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   MUSICAL_EVENT_AllocTitleString  0x02156914  thumb  ov010
 *   MUSICAL_EVENT_SetPlayerNameWord  0x02156A3C  thumb  ov010
 *   MUSICAL_EVENT_SetPokemonNameWord  0x02156AD4  thumb  ov010
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   MUSICAL_SAVE_GetEquippedProp  0x0200A7A0  thumb
 *   MUSICAL_SAVE_GetStageData  0x0200A7F8  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
struct Big;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Work;
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *MUSICAL_EVENT_AllocTitleString(int a0, int a1);
extern void MUSICAL_EVENT_SetPlayerNameWord(struct Work *w, u8 j, void *ws, u32 slot);
extern void MUSICAL_EVENT_SetPokemonNameWord(struct Work *w, u8 j, void *ws, u32 slot);
extern void *GAME_DATA_GetSaveBlock2A(void *h);
extern int GAME_DATA_GetExternalWork(char *base);
extern u8 MUSICAL_SAVE_GetEquippedProp(struct Big *p, u32 index);
extern u8 *MUSICAL_SAVE_GetStageData(struct Big *p);
struct WordSet;
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *dest, const u16 *src, u32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);

int SCRCMD_MUSICAL_BufferString(Ctx *c, void *vm)
{
    void *wsx = SCRCMD_WORK_GetScriptWork(vm);
    void *h = SCRCMD_WORK_GetGameData(vm);
    u32 heap = SCRCMD_WORK_GetHeapId(vm);
    void *ws = SCRIPT_WORK_GetWordSet(wsx);
    u8 op;
    u8 slot;
    u32 arg;
    void *bank;
    void *str;

    op = *c->pc;
    c->pc++;
    slot = *c->pc;
    c->pc++;
    arg = SCRIPT_WORK_ReadWorkValue(c, vm);

    switch (op) {
    case 0: {
        void *sv = GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(vm));

        str = STRBUF_Create(0x26, heap);
        STRBUF_SetStringN(str, (const u16 *)MUSICAL_SAVE_GetStageData(sv), 0x26);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        break;
    }
    case 1:
    case 8:
        if (op == 1)
            bank = func_02045B38(0, 2, 0x4F, heap);
        else
            bank = func_02045B38(0, 2, 0x11A, heap);
        str = func_02045EC0(bank, arg + 3);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(bank);
        break;
    case 2:
        str = MUSICAL_EVENT_AllocTitleString((int)(*((void **)GAME_DATA_GetExternalWork(h))), heap);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        break;
    case 3:
        bank = func_02045B38(0, 2, 0x4B, heap);
        str = func_02045EC0(bank, arg);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(bank);
        break;
    case 4:
        bank = func_02045B38(0, 2, 0x4B, heap);
        str = func_02045EC0(bank, arg + 4);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(bank);
        break;
    case 5:
        MUSICAL_EVENT_SetPlayerNameWord(*((void **)GAME_DATA_GetExternalWork(h)), arg, ws, slot);
        break;
    case 6:
        MUSICAL_EVENT_SetPokemonNameWord(*((void **)GAME_DATA_GetExternalWork(h)), arg, ws, slot);
        break;
    case 7: {
        void *sv = GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(vm));
        u16 ids[3];
        u8 idx[4];
        u8 val[4];
        u8 i;
        u8 j;

        for (i = 0; i < 4; i++) {
            idx[i] = i;
            val[i] = MUSICAL_SAVE_GetEquippedProp(sv, i);
        }
        for (i = 1; i < 4; i++) {
            for (j = 0; j < 4 - i; j++) {
                u8 n = j + 1;

                if (val[j] < val[n]) {
                    u8 t = val[j];

                    val[j] = val[n];
                    val[n] = t;
                    t = idx[j];
                    idx[j] = idx[n];
                    idx[n] = t;
                }
            }
        }
        if (val[0] == val[1] && val[0] == val[2]) {
            ids[0] = 9;
            ids[1] = 8;
        } else {
            ids[0] = idx[0] + 4;
            if (val[1] == val[2])
                ids[1] = 8;
            else
                ids[1] = idx[1] + 4;
        }
        if (val[1] == val[3])
            ids[2] = idx[1] + 4;
        else if (val[2] == val[3])
            ids[2] = idx[2] + 4;
        else
            ids[2] = idx[3] + 4;
        bank = func_02045B38(0, 2, 0x4B, heap);
        for (i = 0; i < 3; i++) {
            str = func_02045EC0(bank, ids[i]);
            func_0201EE0C(ws, i, str, 0, 1, 2);
            STRBUF_Delete(str);
        }
        MSGDATA_Delete(bank);
        break;
    }
    }
    return 0;
}
