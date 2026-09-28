/*
 * function: func_0215B994
 * address:  0x0215B994
 * packet:   pkt_ov010_0215B994
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02007984  0x02007984  thumb
 *   func_020079A0  0x020079A0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *, void *);
extern int func_02159B10(void *, void *);
extern void *func_0215A5E4(void *);
extern void *func_0201293C(void *);
extern void *func_02012934(void *);
extern int func_02007984(void *);
extern int func_020079A0(void *);

int func_0215B994(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int sel = func_02159B10(a0, a1);
    void *h = func_0215A5E4(a1);
    void *d = func_0201293C(h);
    int r;

    func_02012934(h);
    switch (sel) {
    case 0:
        r = func_02007984(d);
        break;
    case 1:
    case 2:
        r = func_020079A0(d);
        break;
    case 3:
        r = func_02007984(d) - func_020079A0(d);
        break;
    case 5: {
        int v = func_02007984(d);
        if (v > 720) {
            r = 0;
        } else {
            r = 720 - v;
        }
        break;
    }
    default:
        r = 0;
        break;
    }
    *out = r;
    return 0;
}
