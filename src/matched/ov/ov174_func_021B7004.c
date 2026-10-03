/*
 * function: func_021B7004
 * address: 0x021B7004
 * packet: pkt_ov174_021B7004
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0204B294 leaves its forwarder's result in r0, captured at
 *   021B712A and 021B715A; declared with the observed word result.
 * symbols:
 *   func_021B7180 0x021B7180 thumb ov174
 *   func_021B71A0 0x021B71A0 thumb ov174
 *   func_020307B0 0x020307B0 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B974 0x0204B974 arm
 *   d_021B7481 0x021B7481 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y; u16 id; u8 a, b; } Request;
extern const u8 d_021B7481[];
extern void func_021B7180(u8 *, u8 *, int);
extern void func_021B71A0(int, int *, int, int, int);
extern void func_020307B0(void *);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0204AF28(void *, u32, u32, u32);
extern u32 func_0204B294(u32, u32, u32, u32, u32, u16, u16);
extern void func_0204B3DC(void *, unsigned);
extern void func_0204B92C(void *, int);
extern void func_0204B974(void *);
void func_021B7004(u8 *p, u8 *q)
{
    int step;
    int base;
    Request req;
    if (*(int *)(p + 8) == 2) { step = 0x6000; base = 0; }
    else { step = 0x3000; base = 0x1c00; }
    func_021B7180(p, q, (d_021B7481 + 4)[q[2] * 3]);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x10000, step);
    func_020307B0(*(void **)(q + 16));
    func_021B7180(p, q, d_021B7481[q[3] * 2] + *(int *)(p + 16) * 2);
    func_021B71A0((int)p, (int *)q, base, step * q[0] + 0x28000, step);
    func_020307B0(*(void **)(q + 16));
    *(int *)(q + 28) = func_0204ACEC(*(void **)(p + 24), (d_021B7481 + 5)[q[2] * 3], 0, (u16)((q[0] * 2 + 4) << 5), *(u16 *)p);
    *(int *)(q + 32) = func_0204A6C8(*(void **)(p + 24), (d_021B7481 + 5)[q[2] * 3] + 1, 0, 0, *(u16 *)p);
    *(int *)(q + 36) = func_0204AF28(*(void **)(p + 24), (d_021B7481 + 5)[q[2] * 3] + 2, (d_021B7481 + 5)[q[2] * 3] + 3, *(u16 *)p);
    req.a = 10; req.b = 1;
    req.x = (q[0] % 2) * 128 + 64;
    req.y = (q[0] / 2) * 96 + 48;
    if (*(int *)(p + 8) == 2) req.y += 56;
    req.id = 0;
    *(u32 *)(q + 40) = func_0204B294(*(u32 *)(p + 80), *(u32 *)(q + 32), *(u32 *)(q + 28), *(u32 *)(q + 36), (u32)&req, 0, *(u16 *)p);
    func_0204B3DC(*(void **)(q + 40), 1);
    func_0204B92C(*(void **)(q + 40), 1);
    func_0204B974(*(void **)(q + 40));
    req.id = 1;
    *(u32 *)(q + 44) = func_0204B294(*(u32 *)(p + 80), *(u32 *)(q + 32), *(u32 *)(q + 28), *(u32 *)(q + 36), (u32)&req, 0, *(u16 *)p);
    func_0204B3DC(*(void **)(q + 44), 1);
    func_0204B92C(*(void **)(q + 44), 1);
    func_0204B974(*(void **)(q + 44));
}
