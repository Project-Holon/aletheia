/*
 * function: func_021B6934
 * address:  0x021B6934
 * packet:   pkt_ov021_021B6934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Sub0200852CObj;
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *, u32, u32);

int func_021B6934(void *a)
{
    void *party = func_02012934(a);
    void *p = func_02012944(a);
    int n = func_0201AA18(party);
    u32 t0 = func_02008530(p);
    int i;

    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);

        if (t0 == func_02017E1C(mon, 7, 0)
            && func_02017E1C(mon, 5, 0) == 0x283
            && func_02017E1C(mon, 0x4c, 0) == 0)
            return i;
    }
    return -1;
}
