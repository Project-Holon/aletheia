/*
 * unit:     yes
 * function: func_02008AF0
 * address:  0x02008AF0
 * packet:   pkt_02008AF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   func_02008B9C  0x02008B9C  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MIi_CpuClearFast(u32 val, void *dst, u32 size);
struct Sub02008AECSession;
extern void func_02008B9C(struct Sub02008AECSession *s);

void func_02008AF0(void *obj)
{
    MIi_CpuClearFast(0, obj, 0x5C);
    func_02008B9C((struct Sub02008AECSession *)((u8 *)obj + 0x10));
}
