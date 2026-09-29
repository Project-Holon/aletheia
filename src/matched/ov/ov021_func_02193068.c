/*
 * function: func_02193068
 * address:  0x02193068
 * packet:   pkt_ov021_02193068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040DA8  0x02040DA8  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02192FA4  0x02192FA4  thumb  ov021
 *   func_02195588  0x02195588  thumb  ov021
 */

typedef unsigned short u16;

extern void func_02040DA8(int, int, int);
extern void func_02040C14(int, int, int, int);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(int);
extern void func_02192FA4(int, int);
extern void func_02195588(int);

void func_02193068(char *p)
{
    func_02040DA8(*(u16 *)(p + 2), 1, 0);
    func_02040C14(*(u16 *)(p + 2), 0, 1, 0);
    func_02041300(*(u16 *)(p + 2) & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(*(u16 *)(p + 2) & 0xff);
    func_02192FA4(*(u16 *)(p + 2), *(u16 *)p);
    func_02195588(*(int *)(p + 0x15c));
}
