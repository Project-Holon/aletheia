/*
 * function: func_0215BAF4
 * address:  0x0215BAF4
 * packet:   pkt_ov010_0215BAF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0215B500  0x0215B500  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *, void *);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_0215B500(void *, void *);

int func_0215BAF4(void *a0, void *a1)
{
    void *list = func_02012934(func_0215A5E4(a1));
    u16 *out = func_02159AE8(a0, a1);
    void *key = (void *)func_02159B10(a0, a1);
    int i;
    int n = func_0201AA18(list);

    *out = 6;
    for (i = 0; i < n; i++) {
        if (func_0215B500(func_0201AB28(list, i), key) == 1) {
            *out = i;
            break;
        }
    }
    return 0;
}
