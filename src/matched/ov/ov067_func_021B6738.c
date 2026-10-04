/*
 * function: func_021B6738
 * address:  0x021B6738
 * packet:   pkt_ov067_021B6738
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads a character-data resource, optionally adds a3 to each of its
 * k2 * k3 u16 cells, then (when func_0204162C(a2) allows) copies it into
 * background a2 and loads its palette, and frees the resource.
 * The u8 stack arguments are re-read with ldrb before each call because the
 * callees take them as u8 (widths from func_020410D0.c and
 * func_020413B0.c); with u32 callee parameters k4..k6 stayed in registers
 * and the frame grew (200 bytes against 192). The loop bound is the
 * expression k2 * k3 and the add is `+=` with the uncast a3: a total local,
 * k3 * k2 and `arr[i] + (u16)a3` each cost a copy or swapped the loads.
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0204A380(void *a0, u32 a1, u32 a2, u16 a3);
extern int func_02062B30(void *p, u8 **out);
extern int func_0204169C(u8 a);
extern int func_0204162C(u8 a);
extern void func_020410D0(u8 index, u32 a1, u32 a2, u32 a3, u8 a4, void *a5, u8 a6,
                          u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 a);
extern void func_020307B0(void *p);

void func_021B6738(u32 a0, u32 a1, u32 a2, u32 a3,
                   u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7,
                   u8 k8, u32 k9, u16 k10)
{
    void *h;
    u8 *out;
    int i;
    u16 *arr;

    h = func_0204A380((void *)a0, a1, k9, (u16)((k10 & 0x7fff) | 0x8000));
    func_02062B30(h, &out);
    if (a3 != 0) {
        if (func_0204169C(a2) == 0) {
            arr = (u16 *)(out + 0xc);
            for (i = 0; i < k2 * k3; i++) {
                arr[i] += a3;
            }
        }
    }
    if (func_0204162C(a2)) {
        func_020410D0(a2, k4, k5, k6, k7, out + 0xc, k0, k1, k2, k3);
        func_020413B0(a2, k4, k5, k6, k7, k8);
        func_020409B4(a2);
    }
    func_020307B0(h);
}
