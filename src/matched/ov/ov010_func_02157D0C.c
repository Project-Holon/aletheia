/*
 * function: func_02157D0C
 * address:  0x02157D0C
 * packet:   pkt_ov010_02157D0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02157960  0x02157960  thumb
 *   func_02157C48  0x02157C48  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_02157960();
extern void func_02157C48();

void func_02157D0C(int *p)
{
    if (*((u8 *)p + 0x675) == 0) {
        *(int *)((u8 *)p + 0x67C) = p[4];
        *(int *)((u8 *)p + 0x680) = p[5];
        if (func_0203D3A8(func_020399A8(), (p[0] << 8) + 2, 8, (u8 *)p + 0x67C) == 0)
            return;
        func_02157960(p, (void *)func_02157C48, 0x1A2);
        return;
    }
    func_02157960(p, (void *)func_02157C48, 0x1A6);
}
