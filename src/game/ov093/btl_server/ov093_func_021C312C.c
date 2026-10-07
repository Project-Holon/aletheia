/*
 * function: func_021C312C
 * address:  0x021C312C
 * packet:   pkt_ov093_021C312C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Note (final push 2026-10-05 G4L8): the script result is written back into the
 * stack parameter d (the caller func_021C3008 does value = func_021C312C(..., value)).
 * Assigning to a stack-passed parameter, instead of a fresh local r, keeps the end
 * line as its own pool word (no ldr + adds #7 fold). Both --lang c99 and c EXACT.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef enum { K0, K1, K10 = 10 } Kind;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);

int func_021C312C(u8 *p, u8 *a, Kind b, u8 c, u16 e, int d)
{
    func_021D74F8(8385);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, c);
    func_021D75EC(0x1F, b);
    func_021D7630(0x20, d);
    func_021D70F0(p, 0x5A);
    d = func_021D775C(0x20);
    func_021D7540(8392);
    return d;
}
