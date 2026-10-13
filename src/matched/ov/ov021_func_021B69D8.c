/*
 * function: SCRCMD_POKEMON_FLD_RegisterBirthdayEntry
 * address:  0x021B69D8
 * packet:   pkt_ov021_021B69D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   FIELD_CLOCK_GetDate  0x021690A4  thumb  ov010
 *   func_02087C88  0x02087C88  arm
 *   func_0200A940  0x0200A940  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_0200A8C8  0x0200A8C8  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetString  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Owner {
    u8 f0;
    u8 f1;
    u8 month;
    u8 day;
    u8 rest[0x50];
};

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
struct Big;
struct Rec;
struct U16Vec;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200A8A0(void *);
struct Entry;
struct Strbuf;
extern void *FIELD_CLOCK_GetDate(int a0);
struct OSOwnerInfo;
extern void func_02087C88(struct OSOwnerInfo *info);
extern int func_0200A940(void *, int, int, void *);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern struct Entry *func_0200A8C8(struct Rec *r, u32 index);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
struct WordSet;
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);

u32 SCRCMD_POKEMON_FLD_RegisterBirthdayEntry(void *a, void *b)
{
    void *r5 = SCRCMD_WORK_GetGameData(b);
    u32 s8 = SCRIPT_WORK_ReadWorkValue(a, b);
    void *r4;
    int r6;
    int fl;
    void *v;
    u32 r7;
    struct Owner o;

    r4 = func_0200A8A0(GAME_DATA_GetSaveControl(r5));
    r5 = FIELD_CLOCK_GetDate((int)r5);
    func_02087C88((struct OSOwnerInfo *)(&o));
    r6 = func_0200A940(r4, o.month, o.day, r5);
    fl = func_0200A8F8(r4, r6);
    fl = fl != 1;
    r6 = (int)func_0200A8C8(r4, r6);
    r7 = (u32)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(b));
    v = STRBUF_Create(8, 0x8001);
    STRBUF_SetString(v, (const u16 *)r6);
    func_0201EE0C((struct WordSet *)r7, s8, v, fl, 1, 2);
    STRBUF_Delete(v);
    return 0;
}
