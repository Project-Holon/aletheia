/*
 * function: func_02049030
 * address:  0x02049030
 * packet:   pkt_02049030
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02048DDC  0x02048DDC  arm
 *   func_02078A80  0x02078A80  arm
 *   func_02078B44  0x02078B44  arm
 *   func_02078B70  0x02078B70  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void func_02048DDC(void *dst, u32 a);
extern void func_02078A80(void *p);
extern void func_02078B44(void *p, u32 off, u32 v);
extern void func_02078B70(void *p, void *dst, u32 n);

u32 func_02049030(u32 a)
{
    char buf[0x48];
    int off;
    u16 hdr[3];

    off = 0;
    func_02048DDC(buf, a);
    func_02078B44(buf, 0xc, 0);
    func_02078B70(buf, &off, 2);
    func_02078B44(buf, off + 4, 0);
    func_02078B70(buf, hdr, 6);
    func_02078A80(buf);
    return hdr[2];
}
