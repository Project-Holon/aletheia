/*
 * unit:     yes
 * function: func_021562EC
 * address:  0x021562EC
 * packet:   pkt_ov009_021562EC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three functions: 0x021562EC, 0x0215631C, 0x02156330.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0216B838  0x0216B838  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern int func_0216B838(void);

int func_021562EC(void)
{
    u8 *g = g_021A8264;
    if (g != 0) {
        u32 s = *(u32 *)(g + 0x754);
        if (s == 9 || s == 10 || s == 0x12) {
            return func_0216B838();
        }
    }
    return -1;
}

void func_0215631C(void)
{
    *(u32 *)(g_021A8264 + 0x76c) = 0;
}

void func_02156330(void)
{
    *(u16 *)(g_021A8264 + 0x794) = 1;
}
