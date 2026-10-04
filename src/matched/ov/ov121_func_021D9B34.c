/*
 * function: func_021D9B34
 * address: 0x021D9B34
 * packet: pkt_ov121_021D9B34
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021D9B9A.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern int func_0201C6C4(u32, u32);
extern void func_02045334(u32);
int func_021D9B34(u8 *p)
{
    u32 q;
    if (*(u32 *)(p + 0x24) == 0) {
        q = *(u32 *)(p + 8);
        if (p[4]) {
            if (func_0201C6C4(q, (u32)func_02045770((struct Descriptor *)*(u32 *)p)) == 0) {
                func_02045334(*(u32 *)p);
                p[4] = 0;
            }
        }
        if (p[4] == 0) return 1;
        return 0;
    } else {
        if (p[4]) {
            if (func_0201C6C4(*(u32 *)(p + 8), (u32)func_02045770((struct Descriptor *)*(u32 *)p)) == 0)
                p[4] = 0;
        }
        if (p[4] == 0) return 1;
        return 0;
    }
}
