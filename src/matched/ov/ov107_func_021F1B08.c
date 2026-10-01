/*
 * function: func_021F1B08
 * address: 0x021F1B08
 * packet: pkt_ov107_021F1B08
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: parent cleared original 12-byte Thumb tail getter. Full matched
 * 0201C6B4 returns only0/1 and reads its first input's pointer field10.
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
typedef struct { u8 pad00[0x30]; struct PrintSys *f30; } Context;
extern u32 func_0201C6B4(const struct PrintSys *);
int func_021F1B08(Context *p)
{
    return func_0201C6B4(p->f30);
}
