/*
 * function: BTL_MSG_SetPokeName
 * address:  0x021EED00
 * packet:   pkt_ov093_021EED00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlMsgState  0x021F6398  data  a4
 *   BTL_SIDE_GetPokeById  0x021B9940  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    void *f8;
    u32 fc;
    u32 t[8];
} D;

extern D gBtlMsgState;
extern u8 *BTL_SIDE_GetPokeById(char *p, u8 i);
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
struct WordSet;
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);

void BTL_MSG_SetPokeName(u8 a, u32 b)
{
    WORDSET_SetSlotMonNickname(gBtlMsgState.f8, b, BTL_POKEPARAM_GetDisplayMon((struct Work *)BTL_SIDE_GetPokeById((char *)gBtlMsgState.f4, a)));
}
