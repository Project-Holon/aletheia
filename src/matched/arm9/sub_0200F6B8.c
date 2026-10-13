/*
 * function: GFL_NET_ERR_CreateHeap
 * address:  0x0200F6B8
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0200F6B8_Obj  0x0214617C  data
 *   MI_CpuFill8       0x02082BCC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_ERR_CreateHeap.c \
 *       --func GFL_NET_ERR_CreateHeap --addr 0x0200F6B8 --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);

struct Sub0200F6B8Obj {
    unsigned char pad[0x60];
};

extern struct Sub0200F6B8Obj sub_0200F6B8_Obj;

void GFL_NET_ERR_CreateHeap(void)
{
    func_0203064C(1, 8, 0x4920);
    MI_CpuFill8(&sub_0200F6B8_Obj, 0, 0x64);
}
