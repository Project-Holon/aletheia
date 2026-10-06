/*
 * function: func_02175144
 * address:  0x02175144
 * packet:   pkt_ov012_02175144
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02174ED8  0x02174ED8  thumb  ov012
 *   func_02174E9C  0x02174E9C  thumb  ov012
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_0203D378(void);
extern int func_0203D1B4(void);
extern u32 func_02174ED8(void);
extern u32 func_02174E9C(int v);

void func_02175144(u8 *p)
{
    int cnt;
    int i;
    int z;

    if (func_0203D378() == 0) {
        return;
    }
    cnt = 0;
    for (i = 0; i < 4; i++) {
        if (p[0xd4 + i] == 1) {
            cnt++;
        }
    }
    if (cnt == func_0203D1B4()) {
        if (func_02174ED8() == 1) {
            z = 0;
            for (i = 0; i < 4; i++) {
                p[0xd4 + i] = z;
                p[0xd8 + i] = z;
            }
        }
    } else {
        z = 0;
        for (i = 0; i < 4; i++) {
            if (p[0xd8 + i] == 1 && func_02174E9C(i) == 1) {
                p[0xd8 + i] = z;
            }
        }
    }
}
