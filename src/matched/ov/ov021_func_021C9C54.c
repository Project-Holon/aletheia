/*
 * function: func_021C9C54
 * address:  0x021C9C54
 * packet:   pkt_ov021_021C9C54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Classifies the kind into the +8 count and reads two stats per slot into +0x22 and +0x2a.
 *
 * symbols:
 *   func_021CA270  0x021CA270  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_021CA210  0x021CA210  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0x22];
    u16 a22[4];
    u16 a2a[4];
} Stats;

extern int func_021CA270(int kind);
extern int func_0200D884(u32 h, int id, void *val);
extern void *func_021CA210(u8 *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u16 func_02017E1C(u32 m, int id, int c);

void func_021C9C54(u8 *p)
{
    void *h;
    int i;
    u32 m;

    p[8] = func_021CA270(p[9]);
    func_0200D884(*(u32 *)(p + 0x70), 5, p + 0x1e);
    h = func_021CA210(p);
    for (i = 0; i < p[8]; i++) {
        m = (u32)func_0201AB28(h, p[0x1e + i]);
        ((Stats *)p)->a22[i] = func_02017E1C(m, 5, 0);
        ((Stats *)p)->a2a[i] = func_02017E1C(m, 6, 0);
    }
}
