/*
 * unit:     yes
 * function: func_021DE668, func_021DE6C0
 * address:  0x021DE668
 * packet:   pkt_ov093_021DE668
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F13E4     0x021F13E4  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern u32 func_021DCFF8(int a, int k);
extern void func_021D7704(int key, int m);
extern int d_021F13E4;

void func_021DE668(int a, int b, int c)
{
    u16 v;
    float x;

    if (c == func_021D775C(4)) {
        v = 100 - func_021DCFF8(a, 2);
        if (v != 0)
            x = 0.5f + (float)(v << 12);
        else
            x = (float)(v << 12) - 0.5f;
        func_021D7704(0x35, (int)x / 100);
    }
}

int *func_021DE6C0(int *p)
{
    *p = 1;
    return &d_021F13E4;
}
