/*
 * file:     unit_0272E9E8_p02.c
 * unit:     yes
 * function: func_0272EBDC, func_0272EC38
 * address:  0x0272EBDC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

asm u32 func_0272EBDC(void *r0);
void func_0272EC38(u32 *expect, void *data, u32 len);

asm u32 func_0272EBDC(void *r0)
{
    ldr r2, [r0, #0x204]
    mov r1, #0x14
    mul r1, r2, r1
    add r1, r1, #0xff
    ldr r2, [r0, #0x1fc]
    ldr r0, [r0, #0x200]
    mov ip, #0
    add r2, r2, #0x1f
    mov r0, r0, lsl #5
    bic r3, r2, #0x1f
    add r2, r0, #0x1f
    add r1, r1, #0x500
    sub r0, ip, #0x600
    and r0, r1, r0
    mov r0, r0, lsl #2
    add r0, r0, #0x1f
    add r3, r3, #0
    bic r1, r2, #0x1f
    add r1, r3, r1
    bic r0, r0, #0x1f
    add r0, r1, r0
    add r0, r0, #0x260
    bx lr
}

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
