/*
 * function: func_020490A8
 * address:  0x020490A8
 * packet:   pkt_02049030
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02048DDC  0x02048DDC  arm
 *   func_02048E34  0x02048E34  arm
 *   func_02078A80  0x02078A80  arm
 */

typedef unsigned int u32;

struct ArcFile;
struct ArcHandle;
extern void func_02048DDC(struct ArcFile *arc, u32 id);
extern u32 func_02048E34(struct ArcHandle *arc, u32 member, u32 base, u32 size);
extern void func_02078A80(void *p);

u32 func_020490A8(u32 a, u32 b)
{
    char buf[0x48];
    u32 r;

    func_02048DDC((struct ArcFile *)buf, a);
    r = func_02048E34((struct ArcHandle *)buf, b, 0, 0);
    func_02078A80(buf);
    return r;
}
