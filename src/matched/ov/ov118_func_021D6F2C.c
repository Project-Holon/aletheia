/*
 * function: func_021D6F2C
 * address:  0x021D6F2C
 * packet:   pkt_ov118_021D6F2C
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6744  0x021D6744  thumb
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   func_021D8AA8  0x021D8AA8  thumb ov119
 *   func_021D6738  0x021D6738  thumb
 *   func_021D8E84  0x021D8E84  thumb
 *   func_021D6750  0x021D6750  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_021D6744(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern int func_021D8AA8(void *p);
extern void func_021D6738(u8 *p, u32 v);
extern void func_021D8E84(void *p, int next);
extern void func_021D6750(u8 *p);

#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define FLAG(i) (((int *)(p + 0x854))[i])

void func_021D6F2C(u8 *p)
{
    u32 t;

    func_021D6744(p);
    FLAG(0) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(0), 0);
    FLAG(1) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(1), 0);
    if (func_021D8AA8(p)) {
        t = OBJ(0);
        OBJ(0) = OBJ(1);
        OBJ(1) = t;
    }
    func_021D6738(p, 0);
    func_021D8E84(p, (int)func_021D6750);
}
