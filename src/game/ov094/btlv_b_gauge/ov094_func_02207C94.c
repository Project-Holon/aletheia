/*
 * function: func_02207C94
 * address: 0x02207C94
 * packet: pkt_ov094_02207C94
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Flags { u32 bit0:1; u32 bit1:1; u32 bit2:1; u32 middle:25; u32 bit28:1; u32 high:3; };
int func_02207C94(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        struct Flags *f;
        f = (struct Flags *)(p + 0xb0 + (i << 7));
        if (f->bit0 || f->bit1 || f->bit2 || f->bit28) return 1;
    }
    return 0;
}
