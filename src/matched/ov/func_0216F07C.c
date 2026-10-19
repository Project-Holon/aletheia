/*
 * function: EVENT_BATTLE_IntegrityDecoyC
 * address:  0x0216F07C
 * packet:   pkt_0216F07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GF_STANDARD_Rand(void);

int EVENT_BATTLE_IntegrityDecoyC(int a0)
{

    a0 = GF_STANDARD_Rand();
loc_0216F082:
    a0 = GF_STANDARD_Rand();
loc_0216F086:
    return a0;}
