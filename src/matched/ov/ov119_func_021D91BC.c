/*
 * function: func_021D91BC
 * address: 0x021D91BC
 * packet: pkt_ov119_021D91BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * 2026-10-02 R3: the bare "cmp r4, r0" before pop is an inner
 *  "if (a == ...) return;" whose branch to the epilogue is the next
 *  instruction, so the branch is dropped after allocation and the compare stays.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
void func_021D91BC(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == func_020399A8()) {
        if (a == func_0203D1A4((struct Link *)func_020399A8()))
            return;
    }
}
