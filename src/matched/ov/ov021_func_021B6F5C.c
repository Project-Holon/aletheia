/*
 * function: SCRCMD_POKEMON_FLD_GetGiftMonReceiveType
 * address:  0x021B6F5C
 * packet:   pkt_ov021_021B6F5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_POKEMON_FLD_CreateGiftMon  0x021B6EE0  thumb ov021
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int SCRCMD_POKEMON_FLD_CreateGiftMon(u32 a, u32 b);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 func_020307B0(void *p);

int SCRCMD_POKEMON_FLD_GetGiftMonReceiveType(void *a, void *b, void *c)
{
    void *t;
    int r;

    t = (void *)SCRCMD_POKEMON_FLD_CreateGiftMon((u32)a, (u32)c);
    if (t == 0) {
        return 1;
    }
    r = POKE_TOOL_GetPartyValue(t, 0x4C, 0);
    func_020307B0(t);
    return r == 1 ? 2 : 1;
}
