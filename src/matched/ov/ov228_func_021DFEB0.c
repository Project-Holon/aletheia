/*
 * function: func_021DFEB0
 * address: 0x021DFEB0
 * packet: pkt_ov228_021DFEB0
 * region: ov228
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020071CC 0x020071CC thumb
 *   func_0200A50C 0x0200A50C thumb
 *   func_0200A4B8 0x0200A4B8 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Blk { u32 w[51]; };
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void func_0200A50C(void *base, u32 kind);
extern void func_0200A4B8(void *p, int v);
void func_021DFEB0(char *p, void *ctrl)
{
    u8 *buf;
    u8 *src;
    int i;
    int j;
    buf = func_020071CC(ctrl, 0x22);
    src = (u8 *)p + 0xC;
    func_0200A50C(buf, 1);
    func_0200A50C(src, 0);
    for (i = 0; i < 256; i++)
        buf[i] = src[i];
    for (j = 0; j < 3; j++)
        *(struct Blk *)(buf + 0x100 + j * 0xCC) = *(struct Blk *)(src + 0x100 + j * 0xCC);
    func_0200A4B8(buf, 1);
    func_0200A4B8(src, 0);
}
