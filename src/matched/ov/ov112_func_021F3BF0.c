/*
 * function: func_021F3BF0
 * address: 0x021F3BF0
 * packet: pkt_ov112_021F3BF0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F3C4E.
 * symbols:
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_021F3ED0 0x021F3ED0 thumb ov112
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F6C7C(u32);
extern void func_021F6F4C(u32);
extern void func_021F7120(void *);
extern void func_021F51B0(u32);
extern void func_021F4948(u8 *);
extern void func_021F3ED0(u8 *);
extern void func_020452E8(void *);
extern void func_0201D83C(void *);
extern void func_020307B0(void *);
void func_021F3BF0(u8 *p)
{
    u8 i;
    func_021F6C7C(*(u32 *)(p+0x40));
    func_021F6F4C(*(u32 *)(p+0x28));
    func_021F7120(*(void **)(p+0x2c));
    func_021F51B0(*(u32 *)(p+0x20));
    func_021F4948(*(u8 **)(p+0x24));
    func_020452E8(*(void **)(p+0x58));
    func_020452E8(*(void **)(p+0x54));
    func_0201D83C(*(void **)(p+0x60));
    func_0201D83C(*(void **)(p+0x5c));
    func_021F3ED0(p);
    for(i=0;i<4;i++) func_020307B0(*(void **)(p+i*4+8));
    func_020307B0(p);
}
