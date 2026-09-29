/*
 * function: func_02164B6C
 * address:  0x02164B6C
 * packet:   pkt_ov010_02164B6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and initialises an 0x84-byte work record.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202647C  0x0202647C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02164FC4  0x02164FC4  thumb ov010
 *   d_021729BC     0x021729BC  data  ov010  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   func_020120F4(void *a);
extern void *func_02012138(void *a);
extern u8   *func_02030734(int a, int b, int c, const char *file, int line);
extern int   func_0202647C(void *a);
extern int   func_0202648C(void *a);
extern void  func_02164FC4(u8 *p);
extern const char d_021729BC[];

u8 *func_02164B6C(void *unused, void *arg)
{
    u32 v = func_020120F4(arg);
    void *w = func_02012138(arg);
    u8 *p = func_02030734(5, 0x84, 1, d_021729BC, 0x9c);
    *(u32 *)p = v;
    *(u16 *)(p + 0xa) = 0x1ab;
    if (func_0202647C(w) == 2 && func_0202648C(w) == 5) {
        func_02164FC4(p);
    }
    return p;
}
