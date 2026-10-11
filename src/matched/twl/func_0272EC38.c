/*
 * function: func_0272EC38
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
 *   func_02082D44 0x02082D44 arm
 *   func_02091200 0x02091200 thumb
 *   func_02091230 0x02091230 thumb
 *   func_02087B04 0x02087B04 arm
 *   func_020774B0 0x020774B0 arm
 *   func_02082C60 0x02082C60 arm
 *   func_02088234 0x02088234 arm
 */
typedef unsigned int u32;
extern u32 data_02732E98[], data_02732E34[];
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_02091200(void *ctx, void *data, u32 len);
extern void func_02091230(void *ctx, void *out);
extern int func_02087B04(void);
extern void *func_020774B0(void);
extern void func_02082C60(void *p, int v, u32 n);
extern void func_02088234(void);
void func_0272EC38(u32 *expect, void *data, u32 len)
{
    unsigned char dbuf[20];
    u32 *digest = (u32 *)dbuf;
    unsigned char ctx[0x64];
    u32 diff = 0;

    func_02082D44(data_02732E98, ctx, 0x64);
    func_02091200(ctx, data, len);
    func_02091230(ctx, digest);
    func_02082D44(data_02732E34, ctx, 0x64);
    func_02091200(ctx, digest, 0x14);
    func_02091230(ctx, digest);
    diff |= expect[0] ^ digest[0];
    diff |= expect[1] ^ digest[1];
    diff |= expect[2] ^ digest[2];
    diff |= expect[3] ^ digest[3];
    diff |= expect[4] ^ digest[4];
    if (diff == 0)
        return;
    if (func_02087B04() == 1 && func_020774B0() != 0) {
        func_02082C60(data, 0, len);
        return;
    }
    func_02088234();
}
