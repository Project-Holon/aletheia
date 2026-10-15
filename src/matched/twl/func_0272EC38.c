/*
 * function: CARDi_CompareHash
 * address:  0x0272EC38
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732E98 0x02732E98 data twl
 *   data_02732E34 0x02732E34 data twl
 *   MI_CpuCopy8 0x02082D44 arm
 *   MSL_C_LIB_TwlCall3 0x02091200 thumb
 *   MSL_C_LIB_TwlCall2 0x02091230 thumb
 *   OS_GetBootType 0x02087B04 arm
 *   CARD_IsPulledOut 0x020774B0 arm
 *   MI_CpuFill 0x02082C60 arm
 *   OS_Terminate 0x02088234 arm
 */
typedef unsigned int u32;
extern u32 data_02732E98[], data_02732E34[];
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void MSL_C_LIB_TwlCall3(void *ctx, void *data, u32 len);
extern void MSL_C_LIB_TwlCall2(void *ctx, void *out);
extern int OS_GetBootType(void);
extern void *CARD_IsPulledOut(void);
extern void MI_CpuFill(void *p, int v, u32 n);
extern void OS_Terminate(void);
void CARDi_CompareHash(u32 *expect, void *data, u32 len)
{
    unsigned char dbuf[20];
    u32 *digest = (u32 *)dbuf;
    unsigned char ctx[0x64];
    u32 diff = 0;

    MI_CpuCopy8(data_02732E98, ctx, 0x64);
    MSL_C_LIB_TwlCall3(ctx, data, len);
    MSL_C_LIB_TwlCall2(ctx, digest);
    MI_CpuCopy8(data_02732E34, ctx, 0x64);
    MSL_C_LIB_TwlCall3(ctx, digest, 0x14);
    MSL_C_LIB_TwlCall2(ctx, digest);
    diff |= expect[0] ^ digest[0];
    diff |= expect[1] ^ digest[1];
    diff |= expect[2] ^ digest[2];
    diff |= expect[3] ^ digest[3];
    diff |= expect[4] ^ digest[4];
    if (diff == 0)
        return;
    if (OS_GetBootType() == 1 && CARD_IsPulledOut() != 0) {
        MI_CpuFill(data, 0, len);
        return;
    }
    OS_Terminate();
}
