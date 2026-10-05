/*
 * function: func_0215F64C
 * address:  0x0215F64C
 * packet:   pkt_ov010_0215F64C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * former blocker: ABS32 0x000000CD (ov_id_00CD) has no witness outside the function (literal pool word only)
 *
 * symbols:
 *   func_02023F60  0x02023F60  thumb
 *   func_02012444  0x02012444  thumb
 *   d_021B9EC0     0x021B9EC0  data  a4
 *   ov_id_00CD     0x000000CD  data  a1
 *   func_0215FA1C  0x0215FA1C  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02158780  0x02158780  thumb  ov010
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02023F60();
extern void func_02012444();
extern u8 d_021B9EC0[];
extern u8 ov_id_00CD[];
extern int func_0215FA1C();
extern void func_02012374();
extern void func_02158780();

int func_0215F64C(int a0, int *st, int *a2)
{
    switch (*st) {
    case 0:
        func_02023F60(-16, 0x37, 1);
        func_02023F60(-16, 0x3f, 2);
        func_02012444(a0, ov_id_00CD, d_021B9EC0, a2);
        (*st)++;
        break;
    case 1:
        func_02023F60(0, 0x3f, 3);
        func_02012374(a0, func_0215FA1C(a2[0]));
        (*st)++;
        break;
    case 2:
        if (a2[1] == 0) {
            func_02158780(a0, 3, 0, 0, 0x15);
        } else {
            func_02158780(a0, 0x7d1, 0, 0, 0x15);
        }
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
