/*
 * function: EVENT_FIELD_PROCLINK_ReturnMail
 * address: 0x02161484
 * packet: pkt_ov010_02161484
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: second state writes f0c separately in each arm; cross-jumping
 * retains the dead branch after MAILTOOL_StoreMailToPartyMon rather than after movs #0.
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   func_02034A5C 0x02034A5C arm
 *   MAILTOOL_HasMail 0x021C3E00 thumb ov136
 *   MAILTOOL_StoreMailToPartyMon 0x021C3E04 thumb ov136
 *   ov136_id 0x00000088 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ctx {
    u8 pad00[8];
    u32 f08;
    u32 f0c;
    u8 pad10[8];
    u32 **f18;
    u8 pad1c[0x60 - 0x1C];
    u8 f60;
    u8 pad61[7];
    u32 f68;
} Ctx;
extern u8 ov136_id[];
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef signed int     s32;
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *a, u32 b);
extern void func_02034A5C(s32 handle);
extern u32 MAILTOOL_HasMail(u32 *p);
extern int MAILTOOL_StoreMailToPartyMon(u32 *p, void *q);
int EVENT_FIELD_PROCLINK_ReturnMail(Ctx *c, void *p)
{
    void *sv;
    u32 v;
    sv = GAMESYSTEM_GetGameData((const struct Ctx *)(*c->f18));
    if (c->f08 == 0) {
        if (c->f68 == 0 || c->f68 == 2) {
            if (MAILTOOL_HasMail(p) == 1) {
                MAILTOOL_StoreMailToPartyMon(p, POKEPARTY_GetMember(GAME_DATA_GetMyParty(sv), c->f60));
                v = 0;
            } else if (c->f68 == 0) {
                v = 2;
            } else {
                v = 0;
            }
        } else {
            v = 0;
        }
        c->f0c = v;
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    if (c->f08 == 2) {
        if (c->f68 == 2) {
            if (MAILTOOL_HasMail(p) == 1) {
                MAILTOOL_StoreMailToPartyMon(p, POKEPARTY_GetMember(GAME_DATA_GetMyParty(sv), c->f60));
                c->f0c = 0;
            } else {
                c->f0c = 0;
            }
        } else {
            c->f0c = 2;
        }
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    c->f0c = 2;
    func_02034A5C((u32)ov136_id);
    return 4;
}
