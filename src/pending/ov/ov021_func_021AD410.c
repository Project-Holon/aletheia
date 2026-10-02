/*
 * function: func_021AD410
 * address:  0x021AD410
 * packet:   pkt_ov021_021AD410
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * 2026-10-02: logic, order and frame match; residue is one register choice.
 * The original keeps the buffer address in r7 (add r7, sp, #0) and
 * rematerialises the 0 third argument of each func_021C6574 call; here the
 * 0 is commoned into r7 and the address rebuilt per call. Measured: the
 * address wins with 1-2 func_021C6574 calls and loses from 3 on (same flip
 * when a third call is added to the EXACT 021ACA70); inert: pointer local,
 * register/const pointer, struct or cast byte buffer, reused parameter
 * (r1 or a fifth stack parameter), enum/typed/cast zeros, inline helper with
 * a shared buffer. Helper-local or block-local buffers get the address
 * register but take five 0x24 frames.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021ABE18(u32 a);
extern u32 func_021ABE24(u32 a);
extern void func_021C6AE0(u32 *a);
extern u32 func_021C6AF0(u32 *a, u32 b, u32 c);
extern void func_021C6AF8(u32 *a, u32 b);
extern void func_021C6AFC(u32 *a, u32 b);
extern u32 func_021C6574(u32 a, u32 *b, u32 c);


void func_021AD410(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r6 = func_021ABE18(a[0]);
    u32 r4 = func_021ABE24(a[0]);
    func_021C6AE0(buf);
    func_021C6AF0(buf, r4, 0x37);
    func_021C6AF8(buf, r4);
    func_021C6AFC(buf, 0x80);
    func_021C6AFC(buf, 0x6c);
    h[2] = func_021C6574(r6, buf, 0);
    func_021C6AE0(buf);
    func_021C6AF0(buf, r4, 0x3a);
    func_021C6AF8(buf, r4);
    func_021C6AFC(buf, 0x6f);
    func_021C6AFC(buf, 0x63);
    h[3] = func_021C6574(r6, buf, 0);
    func_021C6AE0(buf);
    func_021C6AF0(buf, r4, 0x39);
    func_021C6AF8(buf, r4);
    func_021C6AFC(buf, 0x6e);
    func_021C6AFC(buf, 0x62);
    h[5] = func_021C6574(r6, buf, 0);
    func_021C6AE0(buf);
    func_021C6AF0(buf, r4, 0x3b);
    func_021C6AF8(buf, r4);
    func_021C6AFC(buf, 0x70);
    func_021C6AFC(buf, 0x64);
    h[4] = func_021C6574(r6, buf, 0);
    func_021C6AE0(buf);
    func_021C6AF0(buf, r4, 0x38);
    func_021C6AF8(buf, r4);
    func_021C6AFC(buf, 0x6d);
    func_021C6AFC(buf, 0x61);
    h[6] = func_021C6574(r6, buf, 0);
}
