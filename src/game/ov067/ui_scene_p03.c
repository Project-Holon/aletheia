/*
 * file:     ui_scene_p03.c
 * unit:     yes
 * function: func_021B66FC, func_021B6730, func_021B6738
 * address:  0x021B66FC
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02082BCC 0x02082BCC arm
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

extern void func_0204AFD8(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02082BCC(void *, u32, u32);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 a);
extern u32 func_020307B0(void *p);
void func_021B66FC(u32 *p);
int func_021B6730(void *p, int i);
void func_021B6738(u32 a0, u32 a1, u32 a2, u32 a3, u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7, u8 k8, u32 k9, u16 k10);

void func_021B66FC(u32 *p)
{
    func_0204AFD8(p[2]);
    func_0204A8D4(p[1]);
    func_0204ADA4(p[0]);
    func_0203FB44(p[3], (u16)p[4], (u16)(p[4] >> 16));
    func_02082BCC(p, 0, 0x14);
}

int func_021B6730(void *p, int i)
{
    return ((int *)p)[i];
}


/*
 * Loads a character-data resource, optionally adds a3 to each of its
 * k2 * k3 u16 cells, then (when func_0204162C(a2) allows) copies it into
 * background a2 and loads its palette, and frees the resource.
 * The u8 stack arguments are re-read with ldrb before each call because the
 * callees take them as u8 (widths from func_020410D0.c and
 * func_020413B0.c); with u32 callee parameters k4..k6 stayed in registers
 * and the frame grew (200 bytes against 192). The loop bound is the
 * expression k2 * k3 and the add is `+=` with the uncast a3: a total local,
 * k3 * k2 and `arr[i] + (u16)a3` each cost a copy or swapped the loads.
 */
void func_021B6738(u32 a0, u32 a1, u32 a2, u32 a3,
                   u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7,
                   u8 k8, u32 k9, u16 k10)
{
    void *h;
    u8 *out;
    int i;
    u16 *arr;

    h = func_0204A380((void *)a0, a1, k9, (u16)((k10 & 0x7fff) | 0x8000));
    func_02062B30(h, (void **)(&out));
    if (a3 != 0) {
        if (func_0204169C((u8)a2) == 0) {
            arr = (u16 *)(out + 0xc);
            for (i = 0; i < k2 * k3; i++) {
                arr[i] += a3;
            }
        }
    }
    if ((int)func_0204162C((u8)a2)) {
        func_020410D0((u8)a2, k4, k5, k6, k7, (u32)(out + 0xc), k0, k1, k2, k3);
        func_020413B0(a2, k4, k5, k6, k7, k8);
        func_020409B4(a2);
    }
    func_020307B0(h);
}
