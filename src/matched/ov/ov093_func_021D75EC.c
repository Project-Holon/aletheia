/*
 * function: func_021D75EC
 * address:  0x021D75EC
 * packet:   pkt_ov093_021D75EC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021F3ECC     0x021F3ECC  data
 *   func_021D77C4  0x021D77C4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
    u32 a[0x60];
    u32 b[0x60];
    u8 c[0x60];
} Tbl;

extern Tbl g_021F3ECC;
extern u32 func_021D77C4(Tbl *p, int key);

void func_021D75EC(int key, u32 val)
{
    u32 i = func_021D77C4(&g_021F3ECC, key);
    g_021F3ECC.keys[i] = key;
    g_021F3ECC.vals[i] = val;
    g_021F3ECC.b[i] = 0;
    g_021F3ECC.a[i] = 0;
    g_021F3ECC.c[i] = 4;
}
