/*
 * function: MAP_REPLACE_SetDirectLocation
 * address: 0x0215A048
 * packet: pkt_ov010_0215A048
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: owner commit f860957 supplies the matched ARM9 Thumb02014184
 * witness. Recheck the caller against that witness; no owner C compiled.
 * prototype: owner's u16 id is widened to int here because original r1
 * is passed unchanged without narrowing. Remaining payloads retain 32 bits.
 * prior: wave49 one MATCH; tu --suggest-split left caller OUT.
 * symbols:
 *   ZONEDATA_SetDirectLocation 0x02014184 thumb
 */
typedef unsigned short u16;
extern void ZONEDATA_SetDirectLocation(void *, int, short, int, int, int);
void MAP_REPLACE_SetDirectLocation(void *a, int b, int c, unsigned d, u16 e) {
 ZONEDATA_SetDirectLocation(a, b, 1, d << 16, 0, (unsigned)e << 16);
}
