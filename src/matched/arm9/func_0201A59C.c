/*
 * function: POKE_REGULATION_FindValidOrder
 * address:  0x0201A59C
 * packet:   pkt_0201A59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0201A858 (label), 0209E424 (literal) - every concrete byte is right (0 differing bytes, 96 of 96)
 *
 * symbols:
 *   POKE_REGULATION_InitialOrder      0x0209E424  data
 *   POKE_REGULATION_NextOrder   0x0201A858  thumb
 *   POKE_REGULATION_CheckOrder   0x0201A5FC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/POKE_REGULATION_FindValidOrder.c \
 *       --func POKE_REGULATION_FindValidOrder --addr 0x0201A59C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u8 POKE_REGULATION_InitialOrder[6];
extern int POKE_REGULATION_NextOrder(u8 *a);
extern int POKE_REGULATION_CheckOrder(void *a0, void *a1, u8 *a2, char *a3, u32 *a4);

int POKE_REGULATION_FindValidOrder(void *a0, void *a1, void *a2)
{
    char buf[6];

    buf[0] = POKE_REGULATION_InitialOrder[0];
    buf[1] = POKE_REGULATION_InitialOrder[1];
    buf[2] = POKE_REGULATION_InitialOrder[2];
    buf[3] = POKE_REGULATION_InitialOrder[3];
    buf[4] = POKE_REGULATION_InitialOrder[4];
    buf[5] = POKE_REGULATION_InitialOrder[5];

    if (POKE_REGULATION_NextOrder((u8 *)buf) != 0) {
        do {
            if (POKE_REGULATION_CheckOrder(a0, a1, (u8 *)buf, a2, 0) == 1) {
                return 1;
            }
        } while (POKE_REGULATION_NextOrder((u8 *)buf) != 0);
    }

    return 0;
}
