/*
 * function: FLD_BTL_INST_TOOL_BattleMonToPokemon
 * address:  0x0216869C
 * packet:   pkt_ov010_0216869C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a level-50 party mon from a 0x3C-byte record. Two levers: the
 * PP-up count read back through POKE_TOOL_GetPartyValue goes through a u8 local, and
 * the nickname copy reads through a `const u16 *` local (indexing
 * src->nick directly keeps the strbuf in a register and swaps r5/r6).
 *
 * symbols:
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetNature  0x020185B0  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_SetString  0x02045924  arm
 *   STRBUF_Delete  0x02045808  arm
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct BattleMon {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    u32 ivs;            /* 0x14 */
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 f20;             /* 0x20 */
    u8 f21;             /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 f38;             /* 0x38 */
} BattleMon;

struct Mon;
struct Sav;
struct Strbuf;
struct U16Vec;
extern void POKE_TOOL_ClearPartyParam(struct Sav *p);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetNature(void *p, u32 v);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 POKE_TOOL_CalcLevel(void *p);

void FLD_BTL_INST_TOOL_BattleMonToPokemon(const BattleMon *src, void *mon)
{
    u16 name[11];
    void *buf;
    u16 eos;
    int i;
    u8 pp;
    const u16 *n;

    POKE_TOOL_ClearPartyParam(mon);
    POKE_TOOL_SetupPartyParamEx(mon, src->species, 50, (u64)-1, src->ivs & 0x3FFFFFFF, src->pid);
    POKE_TOOL_SetPartyValue(mon, 0x6F, (u8)src->form);
    POKE_TOOL_SetPartyValue(mon, 6, src->item);
    for (i = 0; i < 4; i++) {
        POKE_TOOL_SetPartyValue(mon, 0x36 + i, src->moves[i]);
        POKE_TOOL_SetPartyValue(mon, 0x3E + i, (u8)((src->ppUps >> (i * 2)) & 3));
        pp = POKE_TOOL_GetPartyValue(mon, 0x42 + i, 0);
        POKE_TOOL_SetPartyValue(mon, 0x3A + i, pp);
    }
    POKE_TOOL_SetPartyValue(mon, 7, src->otId);
    POKE_TOOL_SetPartyValue(mon, 0xD, src->ev[0]);
    POKE_TOOL_SetPartyValue(mon, 0xE, src->ev[1]);
    POKE_TOOL_SetPartyValue(mon, 0xF, src->ev[2]);
    POKE_TOOL_SetPartyValue(mon, 0x10, src->ev[3]);
    POKE_TOOL_SetPartyValue(mon, 0x11, src->ev[4]);
    POKE_TOOL_SetPartyValue(mon, 0x12, src->ev[5]);
    POKE_TOOL_SetPartyValue(mon, 0xA, src->f20);
    POKE_TOOL_SetPartyValue(mon, 9, src->f21);
    POKE_TOOL_SetNature(mon, src->f38);
    buf = STRBUF_Create(11, 4);
    eos = STRBUF_GetEosChar();
    n = src->nick;
    for (i = 0; i < 11; i++)
        name[i] = n[i];
    name[i - 1] = eos;
    STRBUF_SetString(buf, name);
    POKE_TOOL_SetPartyValue(mon, 0x73, (u32)buf);
    STRBUF_Delete(buf);
    POKE_TOOL_SetPartyValue(mon, 0xC, src->lang);
    POKE_TOOL_SetPartyValue(mon, 0x9E, POKE_TOOL_CalcLevel(mon));
}
