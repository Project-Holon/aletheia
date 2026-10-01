/*
 * function: func_02187FB0
 * address: 0x02187FB0
 * packet: pkt_ov096_02187FB0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned count/u64 draw reproduce the guarded high multiply;
 *   the callee result is returned through the final flag clear, keeping r0 live.
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_0218814C 0x0218814C thumb ov096
 *   func_02188284 0x02188284 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u8 *func_02011324(u8 *);
extern int func_0218814C(u8 *, u8 *);
extern int func_02188284(u8 *, u8 *);
extern int func_0218A2FC(u8 *, int);
extern int func_021D5B68(int);
extern u32 func_0203F0A8(void);
int func_02187FB0(u8 *a)
{
    u8 *p;
    u32 n;
    int candidates[3];
    u64 r;
    int result;
    p = func_02011324(a);
    if (*(u32 *)(p + 0x98) == 0) {
        p[0x95] = p[0x94] ^ 1;
        return func_0218814C(a, p);
    }
    if (*(u32 *)(p + 0x98) == 1 || *(u32 *)(p + 0x98) == 2) {
        return func_02188284(a, p);
    }
    n = 0;
    for (p[0x95] = 0; p[0x95] < 6; p[0x95]++) {
        if (p[0x95] != p[0x94] && (p[0x95] & 1) != (p[0x94] & 1)) {
            if (func_021D5B68(func_0218A2FC(p, p[0x95])) != 1)
                candidates[n++] = p[0x95];
        }
    }
    r = func_0203F0A8();
    if (n != 0)
        r = (r * n) >> 32;
    p[0x95] = candidates[r];
    result = func_0218814C(a, p);
    if (result == 0)
        p[0x47] = 0;
    return result;
}
