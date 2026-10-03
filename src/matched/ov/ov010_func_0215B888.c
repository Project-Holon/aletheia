/*
 * function: func_0215B888
 * address:  0x0215B888
 * packet:   pkt_ov010_0215B888
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_0201AA88  0x0201AA88  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
struct BigObj;
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0201AA1C(void *p);
extern u32 func_0201AA50(void *p);
extern u32 func_0201AA88(void *p);
extern u32 func_0201AAD4(void *p);

int func_0215B888(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int sel = func_02159B10(a0, a1);
    void *h = func_02012934(func_0215A5E4(a1));
    int r;

    switch (sel) {
    case 0:
        r = func_0201AA18(h);
        break;
    case 1:
        r = func_0201AA1C(h);
        break;
    case 2:
        r = func_0201AA50(h);
        break;
    case 3:
        r = func_0201AA88(h);
        break;
    case 4:
        r = func_0201AAD4(h);
        break;
    case 5: {
        int a = func_0201AA14(h);
        int b = func_0201AA18(h);
        if (a < b) {
            r = 0;
        } else {
            r = a - b;
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
