/*
 * function: STA_NET_SendRandomOrder
 * address: 0x021FD84C
 * packet: pkt_ov132_021FD84C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * padding: two zero bytes at 021FD8C2 before next labelled function.
 * lever: bind the inline random draw to u32 before the multiply-high.
 * symbols:
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   MUS_COMM_FUNC_SendCommandWait 0x021FCEA8 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u32 GF_STANDARD_Rand(void);
extern u32 MUS_COMM_FUNC_SendCommandWait(int unused, int kind, u32 value, u32 id);
static inline u8 random4(void)
{
    u32 draw;
    draw = GF_STANDARD_Rand();
    return ((u64)draw * 4) >> 32;
}
int STA_NET_SendRandomOrder(u8 *p)
{
    u8 slots[4];
    u8 i, j, n;
    int result = 0;
    for (i = 0; i < 4; i++) slots[i] = i;
    for (n = 0; n < 10; n++) {
        for (i = 0; i < 4; i++) {
            int t;
            j = random4();
            t = slots[i];
            slots[i] = slots[j];
            slots[j] = t;
        }
    }
    for (i = 0; i < 4; i++) result += slots[i] << (i * 4);
    return MUS_COMM_FUNC_SendCommandWait((int)p, 1, result, 255);
}
