/*
 * function: SCRCMD_POKEMON_FLD_ReceiveGiftItem
 * address:  0x021B6FF0
 * packet:   pkt_ov021_021B6FF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb ov010
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void func_02007E50(void *, u32, int, u32);

void SCRCMD_POKEMON_FLD_ReceiveGiftItem(void *a, void *b, u32 *c)
{
    u32 v;
    void *r;
    u16 x;

    v = SCRCMD_WORK_GetHeapId(a);
    r = GAME_DATA_GetMyItem(b);
    x = *c;
    if (x != 0 && x <= 0x272) {
        func_02007E50(r, x, 1, v);
    }
}
