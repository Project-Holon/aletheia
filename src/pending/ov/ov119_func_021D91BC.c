/*
 * function: func_021D91BC
 * address: 0x021D91BC
 * packet: pkt_ov119_021D91BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * 2026-10-02: callee shapes are right (e == func_020399A8(), then a vs
 *  func_0203D1A4(func_020399A8())). The image saves a (r4=r0) and leaves a bare
 *  "cmp r4, r0" (flags unused) as the last instruction before pop {r4, pc}; our C
 *  drops the dead compare and the a save. Tried: expression statement, (void) cast,
 *  empty if body, return a == ... (materialises 0/1). Not resolved.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020399A8(void);
extern u32 func_0203D1A4(void *);
void func_021D91BC(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == func_020399A8())
        a == func_0203D1A4(func_020399A8());
}
