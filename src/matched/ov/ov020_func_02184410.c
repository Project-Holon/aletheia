/*
 * function: func_02184410
 * address:  0x02184410
 * packet:   pkt_ov020_02184410
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte-correct (MATCH*: 242 compiled against a 244-byte listing extent, the
 * two bytes are alignment padding).  The one wildcarded site is +0x4C,
 * `bl func_02013DD0`: an unlabelled arm9 leaf (Ilias's) with no witness
 * outside this range, the documented near miss after unit_02013D9C.c.  Its
 * bytes (ldr r1,=0x0209DFC0; ldr r3,=sub_02013B10+1; movs r2,#4; bx r3) are
 *     extern const unsigned short tbl_0209DFC0[];      (data)
 *     extern int sub_02013B10(int v, const unsigned short *t, int n);
 *     int func_02013DD0(int v) { return sub_02013B10(v, tbl_0209DFC0, 4); }
 * which now verifies EXACT on its own (2026-09-29, `match.py one --region
 * arm9 --thumb`: the table by sole-ref/data, sub_02013B10 by literal), so
 * the unit_02013D9C.c note that it has no witness is out of date.  Once
 * that leaf is filed in an arm9 shard, this file goes EXACT unchanged.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0218409C  0x0218409C  thumb  ov020
 *   func_021BD648  0x021BD648  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02184120  0x02184120  thumb  ov020
 *   func_021BD9BC  0x021BD9BC  thumb  ov021
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_021746AC  0x021746AC  thumb  ov011
 *   func_02158428  0x02158428  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int func_02012138(int a);
extern u8 *func_02158344(int a);
extern void *func_02188C7C(int a);
extern void func_0216D9A0(void *a);
extern void func_0216D9E4(void *a);
extern int func_02013DD0(int a);
extern void func_0218409C(u8 *p, int a);
extern int func_021BD648(u8 *p);
extern void func_02012374(int a, int b);
extern int func_02184360(u8 *p, int a);
extern void func_02184120(u8 *p, int a);
extern int func_021BD9BC(u8 *p);
extern int func_0215841C(int a);
extern int func_021746AC(u8 *p, int a);
extern u8 func_02158428(u8 *p);

int func_02184410(int a, int *state, u8 *p)
{
    int z;
    int y;
    u8 *w;

    z = *(int *)(p + 8);
    y = *(int *)(p + 4);
    w = func_02158344(func_02012138(*(int *)(p + 0)));

    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(z));
        if (func_02013DD0(*(u16 *)(p + 0x14)) == 1) {
            *state = 5;
        } else {
            *state = 1;
        }
        break;
    case 1:
        func_0218409C(p, a);
        func_02012374(a, func_021BD648(p + 0x4c));
        (*state)++;
        return 0x21;
    case 2:
        func_02012374(a, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02184120(p, a);
        func_02012374(a, func_021BD9BC(p + 0x4c));
        (*state)++;
        break;
    case 4:
        return 1;
    case 5:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (func_021746AC(w, func_0215841C(y)) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (func_02158428(w) == 1) {
            *state = 1;
        }
        break;
    case 7:
        func_0216D9E4(func_02188C7C(z));
        return 1;
    }
    return 0;
}
