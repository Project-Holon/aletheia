/*
 * function: func_021894E0
 * address:  0x021894E0
 * packet:   pkt_ov021_021894E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02162744  0x02162744  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
u16 func_02162744(u8 *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_02162740(u8 *p);
void func_0216CEAC(u32 a, u8 *p, u32 b, u32 n, u32 c);

void func_021894E0(int a, int b, int c, int d)
{
    int r = func_02162744((u8 *)c);
    int y;
    if (r != 0) {
        y = func_0201296C((const struct BigObj *)a);
        func_0216CEAC(b, (u8 *)func_02162740((u8 *)c), d, r, y);
    }
}
