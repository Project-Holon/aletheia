/*
 * function: SCRCMD_POKEMON_FLD_RegisterStoredName
 * address:  0x021B6628
 * packet:   pkt_ov021_021B6628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The else arm zero is an array initialiser: `u16 s[1] = {0}` keeps &s in r6
 * for the call argument while the result store gets a fresh add sp.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveBlock43  0x02012FD8  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb ov010
 *   SCRIPT_WORK_GetTempBuffer  0x02158F7C  thumb ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb ov010
 *   func_0200E740  0x0200E740  thumb
 *   func_0200E7AC  0x0200E7AC  thumb
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_SetString  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
struct Strbuf;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveBlock43(void **p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u32 SCRIPT_WORK_GetTempBuffer(u8 *p);
extern void *SCRIPT_WORK_GetWordSet(void *);
extern u32 func_0200E740(const void *obj, u32 idx);
extern void *func_0200E7AC(void *obj, u32 idx);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
struct WordSet;
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);

int SCRCMD_POKEMON_FLD_RegisterStoredName(void *a, void *b)
{
    void *t;
    void *w;
    u32 i;
    u32 j;
    void *x;
    void *y;

    t = SCRCMD_WORK_GetScriptWork(b);
    w = GAME_DATA_GetSaveBlock43(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(b)));
    i = SCRIPT_WORK_ReadWorkValue(a, b);
    j = SCRIPT_WORK_ReadWorkValue(a, b);
    x = (void *)SCRIPT_WORK_GetTempBuffer(t);
    y = SCRIPT_WORK_GetWordSet(t);
    if (func_0200E740(w, i)) {
        STRBUF_SetString(x, func_0200E7AC(w, i));
    } else {
        u16 s[1] = {0};
        s[0] = STRBUF_GetEosChar();
        STRBUF_SetString(x, s);
    }
    func_0201EE0C(y, j, x, 0, 1, 2);
    return 0;
}
