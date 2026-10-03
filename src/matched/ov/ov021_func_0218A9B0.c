/*
 * function: func_0218A9B0
 * address:  0x0218A9B0
 * packet:   pkt_ov021_0218A9B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field step handler: runs the step-triggered checks in order (func_0218AC84,
 * the 128-step counter, milestones, egg hatching, the save flag message) and
 * returns the first non-zero result. Flags come from the u32 bitfield at
 * 0x3C.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb
 *   func_02188C80  0x02188C80  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0218AC84  0x0218AC84  thumb
 *   func_0218AB9C  0x0218AB9C  thumb
 *   func_0218AC08  0x0218AC08  thumb
 *   func_0218AB50  0x0218AB50  thumb
 *   func_0218AC4C  0x0218AC4C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ctx9B0 {
    char pad00[0x08];
    void *f8;
    char pad0C[0x04];
    u16 f10;
    char pad12[0x2A];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
};

extern u16 func_02188C84(u8 *p);
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_0218AC84(u8 *pos, void *msg, void *sys);
extern void func_0218AB9C(void *sys, u8 *pos);
extern int func_0218AC08(void *msg, u8 *pos, u16 id);
extern int func_0218AB50(void *p, u8 *pos, void *msg, void *sys);
extern int func_0218AC4C(u8 *pos, void *msg, void *sys);

int func_0218A9B0(struct Ctx9B0 *p, u8 *pos)
{
    void *msg;
    void *sys;
    int r;

    func_02188C84(pos);
    msg = func_02188C80(pos);
    sys = func_020120F4(msg);
    if (p->b2 || p->b9) {
        r = func_0218AC84(pos, msg, sys);
        if (r != 0)
            return r;
    }
    if (!p->b2)
        return 0;
    func_0218AB9C(p->f8, pos);
    r = func_0218AC08(msg, pos, p->f10);
    if (r != 0)
        return r;
    r = func_0218AB50(p, pos, msg, sys);
    if (r != 0)
        return r;
    r = func_0218AC4C(pos, msg, sys);
    if (r == 0)
        return 0;
    return r;
}
