/*
 * function: func_021BD5A0
 * address: 0x021BD5A0
 * packet: pkt_ov110_021BD5A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD764 0x021BD764 thumb ov110
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021BD764(u8 *,void *);
extern void func_020306F0(int);
extern void func_02034A5C(void *);
extern char ov067_id[];
int func_021BD5A0(void *a,int b,int c,u8 *p)
{
    func_021BD764(p,a);
    func_020306F0(41);
    func_020306F0(42);
    func_02034A5C(ov067_id);
    return 1;
}
