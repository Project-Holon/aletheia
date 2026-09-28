/*
 * function: func_0215B190
 * address:  0x0215B190
 * packet:   pkt_ov010_0215B190
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_020072A4  0x020072A4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern int func_0215A5E4();
extern int func_0201296C();
extern int func_02159AE8();
extern int func_020142E8();
extern int func_02012EBC();
extern int func_0200725C();
extern int func_020073D8();
extern int func_0200ECB4();
extern int func_020072A4();
int func_0215B190(int a0, int a1)
{
    int p = func_0215A5E4(a1);
    int q = func_0201296C();
    u16 *out = (u16 *)func_02159AE8(a0, a1);
    int t, r;
    if (func_020142E8(q, 0x97B) != 0) {
        t = func_02012EBC(p);
        r = func_0200725C(t, 8, 4);
        switch (r) {
        case 0:
            *out = 0;
            break;
        case 1:
        case 2:
            func_020073D8(t, 8, 0);
            if (func_0200ECB4() == 0) {
                *out = 0;
            } else {
                *out = 1;
            }
            break;
        default:
            *out = 2;
            break;
        }
        func_020072A4(t, 8);
    } else {
        *out = 0;
    }
    return 0;
}
