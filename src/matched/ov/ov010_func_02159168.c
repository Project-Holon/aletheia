/*
 * function: func_02159168
 * address: 0x02159168
 * packet: pkt_ov010_02159168
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum-typed BIT keeps the shifted mask opaque; plain int folds
 * the complement to mvns and shortens the body by four bytes.
 * Input evidence: ov010 sites 0215F298/021649D6/02164A14 pass 11/7/7;
 * ov021 flag clearers pass fixed IDs 0..13 (021B52D8 passes 0,
 * 021AF03A passes 13; 021B10C8 forwards its saved literal 3).
 * On these traced paths n is nonnegative and below 14 before the shift.
 * symbols:
 *   func_02159198 0x02159198 thumb ov010
 *   d_02172BA0 0x02172BA0 data a4
 */
extern int d_02172BA0;
extern int func_02159198(int);
typedef enum { BIT = 1 } Mask;
void func_02159168(int n)
{
    if (n < 14 && func_02159198(n)) {
        Mask bit = BIT;
        d_02172BA0 &= (bit << n) ^ -1;
    }
}
