/*
 * function: func_021579B0
 * address:  0x021579B0
 * packet:   pkt_ov010_021579B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0203F328  0x0203F328  arm
 *   func_02157960  0x02157960  thumb  ov010
 *   func_021579AC  0x021579AC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0203CD98(void);
extern void func_02082D44(void *, void *, u32);
extern u32 func_0203F1FC(void *, u32);
extern void func_0203F328(void *, u32, u32);
extern void func_02157960(void *, void (*)(void), int);
extern void func_021579AC(void);

void func_021579B0(u8 *p)
{
    if (func_0203CD98() != 0)
        return;
    if (p[0x675] == 0) {
        if (*(int *)(p + 0x66C) == 1) {
            p[0x674] = 3;
        } else {
            p[0x674] = 1;
            func_02082D44(p + 0x7C, *(void **)(p + 0xC), *(u32 *)(p + 8));
            if (*(u16 *)(p + 0x672) != func_0203F1FC(*(void **)(p + 0xC), *(u32 *)(p + 8)))
                p[0x674] = 2;
            func_0203F328(*(void **)(p + 0xC), *(u32 *)(p + 8), *(u32 *)(p + 0x668));
        }
    } else {
        if (p[0x676] == 1)
            p[0x674] = 1;
        else
            p[0x674] = 3;
    }
    func_02157960(p, func_021579AC, 0xF8);
}
