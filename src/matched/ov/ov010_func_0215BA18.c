/*
 * function: func_0215BA18
 * address:  0x0215BA18
 * packet:   pkt_ov010_0215BA18
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
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *, void *);
extern u32 func_02159B10(void *, void *);
extern void *func_0215A5E4(void *);
extern void *func_02012934(void *);
extern int func_0201AA18(void *);
extern void *func_0201AB28(void *, int);
extern u32 func_02017E1C(void *, int, int);

int func_0215BA18(void *a0, void *a1)
{
    u32 key = func_02159B10(a0, a1);
    u16 *out = func_02159AE8(a0, a1);
    u16 *idx = func_02159AE8(a0, a1);
    void *list = func_02012934(func_0215A5E4(a1));
    u16 n = func_0201AA18(list);
    int i;

    if (key != 0 && key <= 0x289) {
        for (i = 0; i < n; i++) {
            void *e = func_0201AB28(list, i);
            u16 t;

            if (e != 0 && func_02017E1C(e, 0x4C, 0) == 0) {
                t = func_02017E1C(e, 5, 0);
                if (t == key) {
                    break;
                }
            }
        }
        if (i < n) {
            *out = 1;
            *idx = i;
        } else {
            *out = 0;
        }
    } else {
        *out = 0;
    }
    return 0;
}
