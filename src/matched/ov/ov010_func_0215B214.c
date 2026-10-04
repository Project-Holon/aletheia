/*
 * function: func_0215B214
 * address:  0x0215B214
 * packet:   pkt_ov010_0215B214
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
 *   func_02162A74  0x02162A74  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
struct BigObj;
extern u32 func_02012844(const struct BigObj *p);
extern int func_02162A74(int, int, u16, u16, u16);
int func_0215B214(int a0, int a1)
{
    int v = (int)func_02159B10((void *)a0, (void *)a1);
    s16 x = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 y = (s16)func_02159B10((void *)a0, (void *)a1);
    s16 z = (s16)func_02159B10((void *)a0, (void *)a1);
    func_02162A74(func_02012844(func_0215A5E4((void *)a1)), v, x, y, z);
    return 0;
}
