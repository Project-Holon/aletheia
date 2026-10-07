/*
 * file:     btl_net_p06.c
 * unit:     yes
 * function: func_021D4648, func_021D4674
 * address:  0x021D4648
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4394 0x021D4394 thumb ov093
 *   func_021D4CEC  0x021D4CEC  thumb  ov093
 *   func_021D4A6C  0x021D4A6C  thumb  ov093
 */
typedef unsigned int u32;

typedef unsigned char u8;

struct S { u8 pad[0x3ae4]; u32 a[4],b[4]; };

extern u8 func_021D4394(u32);
void func_021D4CEC(void);
void func_021D4A6C(void);
u32 func_021D4648(u32 a);
void func_021D4674(void);
extern struct S *d_021F3B88;

/*
 * Indexed struct arrays preserve scaled-index-before-base-load order.
 */
u32 func_021D4648(u32 a) { u32 r; r=func_021D4394(a); if(r!=40) { if(d_021F3B88->b[r]) return d_021F3B88->a[r]; } return 0; }


void func_021D4674(void)
{
    func_021D4CEC();
    func_021D4A6C();
}
