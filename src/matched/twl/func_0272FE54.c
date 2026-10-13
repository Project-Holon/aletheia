/*
 * function: MI_Camera_NDmaRecvAsync
 * address:  0x0272FE54
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_GetNDmaConfig 0x0272FDC0 arm twl
 *   MIi_NDmaAsync_withConfig_Dev 0x0272F9C4 arm twl
 */
typedef unsigned int u32;
extern void MI_GetNDmaConfig(u32, void *);
extern void MIi_NDmaAsync_withConfig_Dev(u32, u32, u32, u32, u32, u32, void (*)(), u32, void *, u32, u32);

void MI_Camera_NDmaRecvAsync(u32 a0, u32 a1, u32 a2, u32 a3, int s0, void (*s1)(), u32 s2)
{
    u32 buf[4];
    u32 n = 10;
    if (s0 == 0) {
        n = 3;
    }
    MI_GetNDmaConfig(a0, buf);
    buf[0] = 2;
    buf[1] = 0;
    buf[2] = 0x40000;
    buf[3] = a2;
    MIi_NDmaAsync_withConfig_Dev(n, a0, 0x04004204, a1, 0, a3, s1, s2, buf, 0x0b000000, 0x80000000);
}


