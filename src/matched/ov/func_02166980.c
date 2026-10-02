/*
 * function: func_02166980
 * address:  0x02166980
 * packet:   pkt_02166980
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 64 compiled 62
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02166824  0x02166824  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;

extern void *func_020120F4(const struct Ctx *p);
extern int func_02012F38();
extern int func_02011330();
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern int func_02166824();

int func_02166980(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    void *ctx;
    void *v0;
    void *v1;
    unsigned short *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216698C:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_02166992:
    ctx = func_020120F4((const struct Ctx *)v1);
loc_02166996:
    a0 = func_02012F38(ctx);
loc_0216699A:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02011330(a0);
loc_021669A2:
a0 = a0 << 0x18;
t4 = (unsigned)a0 >> 0x18;
a0 = t5 + 0;
a1 = t6 + 0;
    v2 = func_02159AE8((void *)a0, (void *)a1);
loc_021669AE:
a0 = t7 + 0;
a1 = t4 + 0;
    a0 = func_02166824(a0, a1);
loc_021669B8:
*(u16 *)((char *)v2) = a0;
a0 = 0;
    return a0;}
