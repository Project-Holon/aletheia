/*
 * function: func_0215FEF4
 * address:  0x0215FEF4
 * packet:   pkt_ov010_0215FEF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020129B8  0x020129B8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

extern void *func_020120F4(const struct Ctx *p);
extern void func_020129B8();

int func_0215FEF4(u32 *a0, u32 *a1)
{
    void *h = func_020120F4((const struct Ctx *)a1[2]);

    switch (a0[9]) {
    case 4:
        func_020129B8(h, 6);
        break;
    case 0:
        func_020129B8(h, 1);
        break;
    case 1:
    case 2:
    case 3:
        func_020129B8(h, (u8)a1[6]);
        break;
    default:
        break;
    }
    return 1;
}
