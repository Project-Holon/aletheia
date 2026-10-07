/*
 * file:     unit_021F36C0_p07.c
 * unit:     yes
 * function: func_021F3D60, func_021F3D9C
 * address:  0x021F3D60
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4040  0x021F4040  thumb  ov056
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_021F42A0     0x021F42A0  data  a4
 *   d_021F43A4     0x021F43A4  data  a4
 *   func_021F408C  0x021F408C  thumb  ov056
 *   func_02082BCC  0x02082BCC  arm
 */
struct IcaAnime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 *func_021F4040(void *a, u32 b, u32 c, u32 d, u16 e);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_021F408C(struct IcaAnime **pp);
extern void func_02082BCC(void *p, int c, u32 n);
void func_021F3D60(void *o, int idx, u16 heap);
void func_021F3D9C(void *o);
extern u32 d_021F42A0[];
extern u8 d_021F43A4[];


/*
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of func_021F4040's u16 parameter (an int heap adds lsls/lsrs).
 */
void func_021F3D60(void *o, int idx, u16 heap)
{
    if (d_021F42A0[idx] != 0) {
        *(u32 **)o = func_021F4040(d_021F43A4 + idx * 0x12, 0x96, idx + 0x1c, 10, heap);
        return;
    }
    MI_CpuFill8(o, 0, 4);
}


void func_021F3D9C(void *o)
{
    if (*(void **)o != 0) {
        func_021F408C(*(void **)o);
    }
    func_02082BCC(o, 0, 4);
}
