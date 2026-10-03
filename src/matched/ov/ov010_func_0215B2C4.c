/*
 * function: func_0215B2C4
 * address:  0x0215B2C4
 * packet:   pkt_ov010_0215B2C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162748  0x02162748  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern int func_02159B10();
extern void *func_0215A5E4(void *a0);
struct BigObj;
extern u32 func_02012844(const struct BigObj *p);
extern int func_02162748(int, int, int, u16, int, u16);
int func_0215B2C4(int a0, int a1)
{
    int a = func_02159B10(a0, a1);
    int b = func_02159B10(a0, a1);
    s16 x = func_02159B10(a0, a1);
    s16 y = func_02159B10(a0, a1);
    s16 z = func_02159B10(a0, a1);
    func_02162748(func_02012844(func_0215A5E4((void *)a1)), a, b, x, y << 16, z);
    return 0;
}
