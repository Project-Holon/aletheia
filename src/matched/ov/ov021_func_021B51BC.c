/*
 * function: func_021B51BC
 * address:  0x021B51BC
 * packet:   pkt_ov021_021B51BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0215E2B8 clears and fills a 0xE8-byte record (its own memset size).
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 *   func_021B5190  0x021B5190  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_02005728  0x02005728  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DE234     0x021DE234  data  a1
 *   d_021D98D0     0x021D98D0  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 id : 11;
    u16 lv : 5;
    u16 pad;
} Ent;

typedef struct {
    u8  pad0[5];
    u8  hasA;
    u8  hasB;
    u8  pad7[0xc0 - 7];
    Ent a[5];
    Ent b[5];
} Rec;

extern const char d_021DE234[];
extern const u16 d_021D98D0[];

extern void *func_0215A5E4(void *vm);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0215E2B8(Rec *r, void *h, u32 k, u32 x);
extern u16 func_021B5190(u16 *list, int n, u16 v);
extern u32 func_02012984(void *);
extern u32 func_02005728(u32 range);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049238(void *h);
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern void func_020307B0(void *p);

int func_021B51BC(void *a, void *b)
{
    Rec rec;
    u32 x;
    u16 i;
    void *h;
    u16 *out;
    void *sys;
    u16 *list;
    u16 j;
    u16 n;

    n = 0;
    sys = func_0215A5E4(b);
    out = func_02159AE8(a, b);
    x = func_02012984(sys);
    h = func_020490F4(0x7e, 0x8015);
    list = func_02030734(0x8015, 0x78, 1, d_021DE234, 0xf8);
    for (i = 0; i < 6; i++) {
        if (func_0215E2B8(&rec, h, d_021D98D0[i], x)) {
            if (rec.hasA) {
                for (j = 0; j < 5; j++) {
                    n = func_021B5190(list, n, rec.a[j].id);
                }
            }
            if (rec.hasB) {
                for (j = 0; j < 5; j++) {
                    n = func_021B5190(list, n, rec.b[j].id);
                }
            }
        }
    }
    *out = list[func_02005728(n)];
    func_020307B0(list);
    func_02049238(h);
    return 0;
}
