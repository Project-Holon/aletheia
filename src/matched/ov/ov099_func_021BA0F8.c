/*
 * function: WIFICLUBACTOR_FindCursorStartTile
 * address:  0x021BA0F8
 * packet:   pkt_ov099_021BA0F8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: declaration order j, n2, i, n1 (stack slots and r4/r5 follow it).
 *
 * symbols:
 *   func_021C47F8  0x021C47F8  thumb  ov127
 *   func_021C47FC  0x021C47FC  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef struct {
    char pad00[0x588];
    void *f588;
} W;

extern u16 func_021C47F8(u16 *p);
extern u16 func_021C47FC(u16 *p);
extern u32 func_021C4864(u8 *p, u16 x, u16 y);

void WIFICLUBACTOR_FindCursorStartTile(W *w, u16 *out)
{
    u32 j;
    u32 n2;
    u32 i;
    u32 n1;

    n1 = func_021C47F8(w->f588);
    n2 = func_021C47FC(w->f588);
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            if (func_021C4864(w->f588, i, j) == 0xf) {
                out[0] = i * 16;
                out[1] = j * 16;
                return;
            }
        }
    }
}
