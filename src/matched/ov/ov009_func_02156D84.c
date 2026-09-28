/*
 * unit:     yes
 * function: func_02156D84
 * address:  0x02156D84
 * packet:   pkt_ov009_02156D84
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two functions: 0x02156D84, 0x02156DB0.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;

int func_02156D84(void)
{
    u8 *g = g_021A8264;
    if (g == 0) {
        return 1;
    }
    {
        u32 s = *(u32 *)(g + 0x754);
        if (s == 0x13 || s == 0x10 || s == 0x14) {
            return 1;
        }
    }
    return 0;
}

void func_02156DB0(u32 v)
{
    g_021A8264[0x7a3] = v;
}
