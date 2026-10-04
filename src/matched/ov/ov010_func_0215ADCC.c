/*
 * function: func_0215ADCC
 * address:  0x0215ADCC
 * packet:   pkt_ov010_0215ADCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  func_02014184 (0x02014184) has no witness outside the range (sole-ref class fails: no other referrer)
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02014184  0x02014184  thumb
 *   func_0201289C  0x0201289C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern int func_0215A5E4();
extern int func_02159B10();
extern int func_02014184();
extern int func_0201289C();

int func_0215ADCC(int a0, int a1)
{
    int buf[7];
    int v8 = func_0215A5E4(a1);
    int c = func_02159B10(a0, a1);
    int r6 = func_02159B10(a0, a1);
    int r7 = func_02159B10(a0, a1);
    int v10 = func_02159B10(a0, a1);
    int v0 = func_02159B10(a0, a1);
    func_02014184(buf, c, (s16)r6, r7 << 16, v10 << 16, v0 << 16);
    func_0201289C(v8, buf);
    return 0;
}
