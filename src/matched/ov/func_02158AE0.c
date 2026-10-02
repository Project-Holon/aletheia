/*
 * function: func_02158AE0
 * address:  0x02158AE0
 * packet:   pkt_02158AE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two arm9 frame calls, an overlay reset, then the four-argument submit.
 *
 * symbols:
 *   func_020120F4   0x020120F4  thumb
 *   func_0201296C   0x0201296C  thumb
 *   func_021589F4   0x021589F4  thumb  ov010
 *   func_02158A90   0x02158A90  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020120F4(void *p);
extern u32 func_0201296C(void *p);
extern int func_021589F4(int a0);
extern void func_02158A90(void *, void *, int, int);

void func_02158AE0(void *a0, void *a1)
{
    func_021589F4(func_0201296C(func_020120F4(a0)));
    func_02158A90(a0, a1, 2, 2);
}

