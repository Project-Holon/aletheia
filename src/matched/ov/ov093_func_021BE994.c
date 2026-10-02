/*
 * function: func_021BE994
 * address: 0x021BE994
 * packet: pkt_ov093_021BE994
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Interface: getter's matched Lock return is one full word; original
 * 021CC8DA loads old [r0] into r1; 021CC900 copies r1 to r0 unchanged.
 * This caller
 * saves r0 at 021BE9A8 and restores all bits through r1 at 021BE9BA;
 * 021CC95C is str r1,[r0]; bx lr. Scalar spelling follows matched caller
 * 021BC568 and retains the same word ABI. Struct/union locals used a
 * 12-byte frame and separate 4019 pool; scalar uses original 4-byte frame.
 * symbols:
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021BE9D0 0x021BE9D0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021CC8D8(void *,int);
extern void func_021CC95C(void *,u32,int);
extern void func_021BE9D0(u8 *,u8 *,u32,u32);
void func_021BE994(u8 *p,u8 *a,u32 c,u32 d)
{
    u32 old;
    old=func_021CC8D8(p+0x1d74,4017);
    func_021BE9D0(p,a,c,d);
    func_021CC95C(p+0x1d74,old,4019);
}
