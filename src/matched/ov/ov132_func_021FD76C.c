/*
 * unit: yes
 * function: func_021FD76C, func_021FD7AC, func_021FD7C8
 * address: 0x021FD76C
 * packet: pkt_ov132_021FD76C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FDA74 0x021FDA74 thumb ov132
 *   func_0203996C 0x0203996C arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021FDA74(u32, u32, int);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
void func_021FD76C(u8 *p)
{
    u32 *q = *(u32 **)(p + 0x140);
    u32 id;
    func_021FDA74(q[2], q[9], 1);
    id = (u32)func_0203996C(255);
    func_0203D3F8(id, 255, 0x1107, (*(u32 **)(p + 0x140))[9], (*(u32 **)(p + 0x140))[2], 1, 0, 1);
}
void func_021FD7AC(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    *(u32 *)(p + 0x174) = 1;
    q = *(u32 **)(p + 0x140);
    func_021FDA74(q[2], q[9], 11);
}
u32 func_021FD7C8(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[2];
}
