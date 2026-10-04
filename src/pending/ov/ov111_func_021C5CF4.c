/*
 * function: func_021C5CF4
 * address: 0x021C5CF4
 * packet: pkt_ov111_021C5CF4
 * region: ov111
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * symbols:
 *
 * note 2026-10-04: DIFF, 158 bytes. Semantics settled (4x4 tile blit into 8x8-tile
 * layout, 24 tiles per row). Original keeps sel (sp+0x34) in r7 and hoists only
 * yb=(yy/8)*24 (lr) and yo=(yy%8)*8 (sp+0xc) in the outer loop; dst is added last
 * (strb [dst,idx], dst at sp+0x10). Ours also hoists dst+yo and spills dst at sp+0.
 * Tried: continue vs combined || conditions, nested ifs, idx association orders,
 * yb/yo locals. None changed the allocation.
 */
typedef unsigned char u8;
void func_021C5CF4(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel)
{
    int j, k, n = 0;
    for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++, n++) {
            int xx = x + k;
            int yy = y + j;
            int c;
            int v;
            int idx;
            if (xx < 0 || yy < 0 || xx >= w || yy >= h) continue;
            if (mode == 1 && ((sel == 0 && xx >= 0x60) || (sel == 1 && xx <= 0x5f))) continue;
            c = src[n];
            if (c == 1) v = 7;
            else if (c == 2) v = 0;
            else continue;
            idx = xx % 8 + ((yy % 8) * 8 + ((yy / 8) * 24 + xx / 8) * 64);
            dst[idx] = v;
        }
    }
}
