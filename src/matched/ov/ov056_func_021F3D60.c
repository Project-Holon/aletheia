/*
 * function: func_021F3D60
 * address:  0x021F3D60
 * packet:   pkt_ov056_021F3D60
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of func_021F4040's u16 parameter (an int heap adds lsls/lsrs).
 * symbols:
 *   func_021F4040  0x021F4040  thumb  ov056
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_021F42A0     0x021F42A0  data  a4
 *   d_021F43A4     0x021F43A4  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 *func_021F4040(void *a, u32 b, u32 c, u32 d, u16 e);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern u32 d_021F42A0[];
extern u8 d_021F43A4[];

void func_021F3D60(void *o, int idx, u16 heap)
{
    if (d_021F42A0[idx] != 0) {
        *(u32 **)o = func_021F4040(d_021F43A4 + idx * 0x12, 0x96, idx + 0x1c, 10, heap);
        return;
    }
    MI_CpuFill8(o, 0, 4);
}
