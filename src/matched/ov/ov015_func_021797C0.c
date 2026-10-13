/*
 * function: func_021797C0
 * address:  0x021797C0
 * packet:   pkt_021797C0
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_0217993C  0x0217993C  thumb  ov015
 *   func_021799CC  0x021799CC  thumb  ov015
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *GFL_NET_GetInitParam(void);
extern void func_0217993C(u32 a, u8 b);
extern void  func_021799CC(void);

struct s67 { char pad[0x67]; unsigned char f67; };
struct s68 { char pad[0x68]; int f68; };

int func_021797C0(void)
{
    struct s67 *a = (struct s67 *)GFL_NET_GetInitParam();
    struct s68 *b = (struct s68 *)GFL_NET_GetInitParam();

    func_0217993C(b->f68, a->f67);
    func_021799CC();
    return 1;
}
