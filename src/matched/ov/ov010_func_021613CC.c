/*
 * function: EVENT_FIELD_PROCLINK_CreateMailParam
 * address:  0x021613CC
 * packet:   pkt_ov010_021613CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   FILE_UTIL_GetItemSlot  0x0202138C  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MAILTOOL_CreateWriteArgs  0x021C3CC0  thumb  ov136
 *   MAILTOOL_CreateArgsFromPartyMon  0x021C3D44  thumb  ov136
 *   MAILTOOL_CreateArgsFromMail  0x021C3DA4  thumb  ov136
 *   ov136_id       0x00000088  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x18];
    u32 **f18;          /* 0x18 */
    u8 pad1c[0x60 - 0x1C];
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u8 pad64[4];
    u32 f68;            /* 0x68 */
} Ctx;

typedef struct Src {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
    u8 pad30[8];
    u32 f38;            /* 0x38 */
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
} Src;

extern u8 ov136_id[];

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef signed int     s32;
struct BigObj;
extern int func_02034AC4(s32 handle);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u8 FILE_UTIL_GetItemSlot(u16 v);
extern void *POKEPARTY_GetMember(void *a, u32 b);
extern void *MAILTOOL_CreateWriteArgs(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern void *MAILTOOL_CreateArgsFromPartyMon(void *a, void *b, unsigned heap);
extern void *MAILTOOL_CreateArgsFromMail(void *a, void *b, unsigned heap);

int EVENT_FIELD_PROCLINK_CreateMailParam(Ctx *c, int a1, int mode, const Src *src)
{
    void *sv;
    void *t;
    u32 v;
    int r;
    u16 h;

    sv = GAMESYSTEM_GetGameData((const struct Ctx *)(*c->f18));
    func_02034AC4((u32)ov136_id);
    if (mode == 0) {
        t = GAME_DATA_GetMyParty(sv);
        v = src->f3c;
        c->f60 = v;
        h = src->f44;
        c->f62 = h;
        if (src->f40 == 6)
            return (int)MAILTOOL_CreateWriteArgs(sv, 2, (u8)src->f3c, FILE_UTIL_GetItemSlot(h), 4);
        c->f68 = 1;
        return (int)MAILTOOL_CreateArgsFromPartyMon(sv, POKEPARTY_GetMember(t, v), 4);
    }
    if (src->f2c == 2) {
        r = (int)MAILTOOL_CreateWriteArgs(sv, 2, (u8)src->f38, FILE_UTIL_GetItemSlot((u16)src->f38), 4);
        c->f62 = src->f38;
        return r;
    }
    c->f68 = 1;
    return (int)MAILTOOL_CreateArgsFromMail(sv, (void *)FILE_UTIL_GetItemSlot((u16)src->f38), 4);
}
