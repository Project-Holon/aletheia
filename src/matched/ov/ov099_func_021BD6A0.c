/*
 * function: func_021BD6A0
 * address: 0x021BD6A0
 * packet: pkt_ov099_021BD6A0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C18C8(char *, int, int);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *, u32, u32);
int func_021BD6A0(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    func_02039C68((struct Link *)func_020399A8(), 0x19, 10);
    *(u32 *)(p + 0x135c) = 0;
    *(u32 *)(p + 0x1cc) = 0x9c;
    return v;
}
