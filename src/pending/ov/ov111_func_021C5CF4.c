/*
 * function: func_021C5CF4
 * address: 0x021C5CF4
 * packet: pkt_ov111_021C5CF4
 * region: ov111
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD4 lane16): moving idx = ... BEFORE `c = src[n]` (the original computes idx first, then loads src and picks v) removes the dst+yo hoist and puts sel in r7: 190 bytes, 140 differ (was 196/158). Still open: original colours n=r4,k=r3,xx=r2,yy=r6 (ours n=r2,k=r1,xx=r4,yy=r3) and uses `bge ok; b skip` stubs. Tried: inline in-range helper (206 bytes, worse), yy/yb/yo declared in the outer loop (same colours), u8/u32 counters.
 * symbols:
 *
 * note 2026-10-04: DIFF, 158 bytes. Semantics settled (4x4 tile blit into 8x8-tile
 * layout, 24 tiles per row). Original keeps sel (sp+0x34) in r7 and hoists only
 * yb=(yy/8)*24 (lr) and yo=(yy%8)*8 (sp+0xc) in the outer loop; dst is added last
 * (strb [dst,idx], dst at sp+0x10). Ours also hoists dst+yo and spills dst at sp+0.
 * Tried: continue vs combined || conditions, nested ifs, idx association orders,
 * yb/yo locals. None changed the allocation.
  *
 * note 2026-10-04 (lane 20, D2): extra residue facts from the listing. In the original every
 * rejection test branches to a short `b skip` (xx<0 via `adds; bmi`, then `cmp yy; bge next; b skip`),
 * sel (param 8) is loaded once into r7 and never re-spilled while w, h, mode are reloaded from
 * their stack slots; v lives in r2 (strb r2,[dst,idx]), j in ip, n in r4, k in r3, yy in r6.
 * Ours spills all stack params, uses r7 for v and branches directly. Not retried this lane.
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
            idx = xx % 8 + ((yy % 8) * 8 + ((yy / 8) * 24 + xx / 8) * 64);
            c = src[n];
            if (c == 1) v = 7;
            else if (c == 2) v = 0;
            else continue;
            dst[idx] = v;
        }
    }
}
