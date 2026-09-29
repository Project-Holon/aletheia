/*
 * function: func_021C2250
 * address:  0x021C2250
 * packet:   pkt_ov093_021C2250
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C7AD0  0x021C7AD0  thumb  ov093
 *   func_021C7B0C  0x021C7B0C  thumb  ov093
 *   func_021C60EC  0x021C60EC  thumb  ov093
 *   func_021C6134  0x021C6134  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021DCF5C  0x021DCF5C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D6730  0x021D6730  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D5440(u8 *a);
extern int func_021D5B40(u8 *a);
extern void func_021D5B44(u8 *a, u32 v);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(void *lock, u32 v, int line);
extern void func_021C7AD0(u8 *p, u8 *a, u32 b);
extern void func_021C7B0C(u8 *p, u8 *a);
extern void func_021C60EC(u8 *p, u8 *a, int k);
extern void func_021C6134(u8 *p, u8 *a, int k);
extern void func_021DCF24(u8 *a);
extern void func_021DCF5C(u8 *a);
extern void func_021CD4B0(void *w, u32 id, ...);
extern void func_021D6730(u8 *a, u32 v);

void func_021C2250(u8 *p, u8 *a, u32 b, u32 c)
{
    u32 s;
    u32 t;
    int name;
    name = func_021D5440(a);
    t = (u16)func_021D5B40(a);
    s = func_021CC8D8(p + 0x1D74, 7469);
    func_021C7AD0(p, a, b);
    func_021CC95C(p + 0x1D74, s, 7471);
    if (b == 0)
        func_021C60EC(p, a, 15);
    func_021DCF24(a);
    func_021CD4B0(*(void **)(p + 0xC), 0x1E, name, b);
    func_021D5B44(a, b);
    if (b != 0)
        func_021DCF5C(a);
    s = func_021CC8D8(p + 0x1D74, 7485);
    func_021C7B0C(p, a);
    func_021CC95C(p + 0x1D74, s, 7487);
    if (c != 0) {
        func_021D6730(a, t);
        func_021CD4B0(*(void **)(p + 0xC), 0x17, name, t);
        func_021C6134(p, a, 8);
    }
}
