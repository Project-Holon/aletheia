/*
 * function: func_021EEE24
 * address:  0x021EEE24
 * packet:   pkt_ov093_021EEE24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Variadic: copies n words into an eight-word table at d_021F6398 + 0x30
 * (zero-filling the rest), then hands the table (named separately at its
 * own address d_021F63C8) to func_021EEE80.
 *
 * symbols:
 *   func_021EEE80  0x021EEE80  thumb  ov093
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   d_021F63C8     0x021F63C8  data  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed int s32;
typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

typedef struct {
    u8 pad[0x30];
    s32 a[8];
} Tbl;

extern Tbl d_021F6398;
extern s32 d_021F63C8[];
extern void func_021EEE80(u32 a, u16 k, s32 *p);

void func_021EEE24(u32 a, u16 k, u32 n, ...)
{
    va_list ap;
    u32 i;

    va_start(ap, n);
    for (i = 0; i < n; i++) {
        d_021F6398.a[i] = va_arg(ap, s32);
    }
    for (; i < 8; i++) {
        d_021F6398.a[i] = 0;
    }
    func_021EEE80(a, k, d_021F63C8);
}
