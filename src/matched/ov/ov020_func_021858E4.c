/*
 * function: func_021858E4
 * address:  0x021858E4
 * packet:   pkt_ov020_021858E4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012844  0x02012844  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
u32 func_02012844(const struct BigObj *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_02012964(const struct BigObj *p);
u16 func_02162744(u8 *p);
u32 func_02162740(u8 *p);
void func_0216CEAC(u32 a, u8 *p, u32 b, u32 n, u32 c);

void func_021858E4(int a, const short *p)
{
    int t = func_02012844((const struct BigObj *)a);
    int v = func_02162744((u8 *)t);

    if (v != 0) {
        int r6 = func_0201296C((const struct BigObj *)a);
        int r5 = func_02012964((const struct BigObj *)a);
        int r1 = func_02162740((u8 *)t);
        int s = p[2];
        func_0216CEAC(r5, (u8 *)r1, s, v, r6);
    }
}
