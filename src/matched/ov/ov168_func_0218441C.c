/*
 * function: MICTEST_UpdateMic
 * address:  0x0218441C
 * packet:   pkt_0218441C
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SND_MIC_AddElapsed   0x02006D64  thumb
 *   SND_MIC_IsLimitReached   0x02006D94  thumb
 *   MICTEST_DisarmMic   0x0218448C  thumb
 *   MICTEST_ArmMic   0x02184470  thumb
 *
 * Latch the polled flag into p[0x34], arming and disarming the p[0x2c]
 *   work item while p[0x30] tracks the busy state.
 */


typedef unsigned int   u32;
extern void SND_MIC_AddElapsed(u32 n);
extern u32 SND_MIC_IsLimitReached(void);
extern void MICTEST_DisarmMic(int *);
extern void MICTEST_ArmMic(int *);

void MICTEST_UpdateMic(int *p)
{
    int x;
    int y;
    SND_MIC_AddElapsed(1);
    x = SND_MIC_IsLimitReached();
    if (x != 0 && p[13] != 0)
        goto end;
    if (p[12] == 0) {
        if (p[10] != 0) {
            MICTEST_DisarmMic(p);
            p[11] = 1;
        }
        p[12] = 1;
    }
    if (x == 0)
        goto end;
    if (p[13] != 0)
        goto end;
    y = p[11];
    p[12] = 0;
    if (y != 0) {
        MICTEST_ArmMic(p);
        p[11] = 0;
    }
end:
    p[13] = x;
}
