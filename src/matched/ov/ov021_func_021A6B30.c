/*
 * function: FIELD_PLAYER_NOGRID_StopSpin
 * address:  0x021A6B30
 * packet:   pkt_ov021_021A6B30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 b0;
    u8 b1;
    short h2;
} P;

typedef unsigned int   u32;
extern int GFL_USE_GetSeSlot(u32 a0);
extern void GFL_USE_StopSeSlot(void);

void FIELD_PLAYER_NOGRID_StopSpin(P *p)
{
    if (p->b0) {
        p->b0 = 0;
        p->h2 = 0;
        GFL_USE_GetSeSlot(0x6d1);
        GFL_USE_StopSeSlot();
    }
}
