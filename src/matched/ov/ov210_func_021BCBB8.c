/*
 * function: func_021BCBB8
 * address: 0x021BCBB8
 * packet: pkt_ov210_021BCBB8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021C0E80 0x021C0E80 data a4
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj05546.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern const char d_021C0E80[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02082A60(const void *, void *, u32);
extern void func_020307B0(void *p);
extern void func_02049238(void *);
void func_021BCBB8(char *p)
{
    void *out;
    void *h;
    void *blob;
    ((struct Obj05546 *)p)->f2BC = func_02030734(123, 384, 0, d_021C0E80, 0x3b0);
    h = func_020490F4(159, 0x807b);
    blob = func_02049EF4(h, 91, 0, (void **)&out, 0x807b);
    func_02082A60((char *)out + 12, ((struct Obj05546 *)p)->f2BC, 384);
    func_020307B0(blob);
    func_02049238(h);
}
