/*
 * function: func_021BD348
 * address: 0x021BD348
 * packet: pkt_ov110_021BD348
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD4 lane19): still DIFF. Orig keeps i*2 in r7 and spills bh (blue lerp already shifted) to [sp,#8]; ours spills i*2. No new test closed it; the first hypothesis this wave (checking mask constants) shows the 0x7C00/0x3E0 mask spills already match.
 * note: 2026-10-04 (wD1 lane17): DIFF. Angle update, table lookup and t=(tbl[2*j+1]+0x1000)/2 as s16 match (field read as raw *(int*)(p+0xB8) each time). Residue is in the 5-iteration RGB555 lerp loop: orig keeps i*2 in r7 and addresses p+r7+0x98/0xA2/0xAC, ours spills it to [sp,#8]; blue is `(c&0x7C00)>>10` on signed int (asrs), result bh=(u8)lerp<<10 spilled to [sp,#8]. Tried: char *q = p+i*2, int o=i*2, bh local, extraction order.
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern s16 tbl_020A1B38[];
extern void func_02061CA4(u32 a, u32 b, void *src, u32 n);
#define F (*(int *)(p + 0xB8))
void func_021BD348(char *p)
{
    int j;
    s16 t;
    u8 i;
    if (F + 0x400 >= 0x10000)
        F = F - 0xFC00;
    else
        F = F + 0x400;
    j = F >> 4;
    t = (tbl_020A1B38[j * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        int o = i * 2;
        int c = *(u16 *)(p + o + 0x98);
        int d = *(u16 *)(p + o + 0xA2);
        u8 cr = c & 0x1F;
        u8 cg = (c & 0x3E0) >> 5;
        u8 cb = (c & 0x7C00) >> 10;
        u8 dr = d & 0x1F;
        u8 dg = (d & 0x3E0) >> 5;
        u8 db = (d & 0x7C00) >> 10;
        u32 bh = (u8)(cb + (((db - cb) * t) >> 12)) << 10;
        u8 g = cg + (((dg - cg) * t) >> 12);
        u8 r = cr + (((dr - cr) * t) >> 12);
        *(u16 *)(p + o + 0xAC) = bh | (g << 5) | r;
    }
    func_02061CA4(14, 0x56, p + 0xAC, 10);
}
