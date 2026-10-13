/*
 * function: BTL_MSG_SetClientValue
 * address:  0x021EED6C
 * packet:   pkt_ov093_021EED6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlMsgState  0x021F6398  data  a4
 *   BTL_MAIN_GetTrainerType  0x021BA020  thumb  ov093
 *   func_0201F0F8  0x0201F0F8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern D gBtlMsgState;
extern unsigned short BTL_MAIN_GetTrainerType(char *p, int i);
struct WordSet;
extern void func_0201F0F8(struct WordSet *p, u32 i, u32 v);

void BTL_MSG_SetClientValue(void *a, u8 b, u8 c)
{
    func_0201F0F8((struct WordSet *)a, b, (u8)BTL_MAIN_GetTrainerType((void *)gBtlMsgState.f0, c));
}
