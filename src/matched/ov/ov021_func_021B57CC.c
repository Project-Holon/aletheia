/*
 * function: SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames
 * address:  0x021B57CC
 * packet:   pkt_ov021_021B57CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * POKE_REGULATION_Load is filed as src/matched/arm9/POKE_REGULATION_Load.c (witness).
 *
 * symbols:
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList  0x021B5824  thumb  ov021
 *   WORDSET_Callback  0x0201EE60  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *POKE_REGULATION_Load(int a, int b);
extern u16 *SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList(u8 *a0, void *a1, u16 *a2, int a3);
struct WordSet;
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern u32 func_020307B0(void *p);

u16 SCRCMD_FLD_BATTLE_StoreAllowedSpeciesNames(void *a0, void *a1, u32 a2, int a3)
{
    u16 n = 0;
    u16 i = 0;
    void *t;
    u16 *v;

    t = POKE_REGULATION_Load(a2, a3);
    v = SCRCMD_FLD_BATTLE_CreateAllowedSpeciesList(t, a0, &n, a3);
    for (i = 0; i < n; i++) {
        WORDSET_Callback(a1, i, v[i]);
    }
    func_020307B0(v);
    func_020307B0(t);
    return n;
}
