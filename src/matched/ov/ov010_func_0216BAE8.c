/*
 * function: func_0216BAE8
 * address: 0x0216BAE8
 * packet: pkt_ov010_0216BAE8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * arithmetic: subtract in u32, then interpret the resulting sign bit as
 * target int before the BPL clamp; this preserves SUB wrapping without bounds.
 * interface: BB18's old file says void, but this caller loads p into r0
 * at 0216BAFC and BB18 forwards entry r0 to 0200C0F0; preserve that input.
 * symbols:
 *   func_0200E394 0x0200E394 thumb
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C32C 0x0200C32C thumb
 *   func_0216BB18 0x0216BB18 thumb ov010
 *   func_0216BBC4 0x0216BBC4 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0200E394(void *a0);
extern void *func_0200C0E8(int);
extern u8 func_0200C32C(void *);
extern int func_0216BB18(int);
extern int func_0216BBC4(u8);
u16 func_0216BAE8(int p)
{
    int index, elapsed, x;
    func_0200E394((void *)p);
    index = func_0200C32C(func_0200C0E8(p));
    elapsed = func_0216BB18(p);
    x = (int)((u32)func_0216BBC4(index) - (u32)elapsed);
    if (x < 0) x = 0;
    return (u16)x;
}
