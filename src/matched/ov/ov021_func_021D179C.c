/*
 * function: SCRCMD_SetWifiFriendNameWord
 * address:  0x021D179C
 * packet:   pkt_ov021_021D179C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * GAME_DATA_GetGameSync (arm9 Thumb leaf) is filed as src/matched/arm9/GAME_DATA_GetGameSync.c
 * to give the witness.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   GAME_DATA_GetGameSync  0x02012F8C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_02009390  0x02009390  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Sub02009210Ent;
struct Sub02009210Obj;
struct U16Vec;
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 GAME_DATA_GetGameSync(u32 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
struct WordSet;
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);

int SCRCMD_SetWifiFriendNameWord(u32 a, u32 b)
{
    void *r6 = SCRCMD_WORK_GetScriptWork((void *)b);
    void *r7;
    u32 s8;
    u32 s12;
    u32 k0;
    u32 k1;
    u16 *e;
    u32 h;
    u32 id;

    SCRCMD_WORK_GetGameSystem((void *)b);
    r7 = SCRCMD_WORK_GetGameData((void *)b);
    s8 = SCRCMD_WORK_GetHeapId((void *)b);
    s12 = (u32)SCRIPT_WORK_GetWordSet(r6);
    id = GAME_DATA_GetGameSync(r7);
    k0 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    k1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    e = (u16 *)func_02009390((struct Sub02009210Obj *)id, k1);
    if (e != 0 && e[0] != 0x7E && e[0] != 0) {
        h = (u32)STRBUF_Create(0xE, s8);
        STRBUF_SetStringN((struct Strbuf *)h, e + 1, 0xD);
        WORDSET_SetSlotTag((struct WordSet *)s12, k0, (const void *)h, 0, 0, 2);
        STRBUF_Delete((struct U16Vec *)h);
    }
    return 0;
}
