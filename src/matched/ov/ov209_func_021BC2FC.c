/*
 * function: func_021BC2FC
 * address: 0x021BC2FC
 * packet: pkt_ov209_021BC2FC
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: larger follower 021BC308 filed separately, EXACT104
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02030EAC(void *);
void func_021BC2FC(char *p)
{
    func_02030EAC(*(void **)(p + 8));
}
