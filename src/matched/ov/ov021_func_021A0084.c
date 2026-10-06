/*
 * function: func_021A0084
 * address:  0x021A0084
 * packet:   pkt_ov021_021A0084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_02197C9C  0x02197C9C  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219D49C  0x0219D49C  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C6678  0x021C6678  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_0216D6F0(void *p);
extern u32 func_0219D49C(u32);
extern void func_02197CCC(u8 *p, s32 *out);
extern int func_0216DAB4(void *a0);
extern u32 func_02197C9C(u32);
extern void func_021C6664(u32, u32, u32 *);
extern void func_021C6678(u32, u32, u32);
extern int func_021C66EC(u32 *a, int idx, int v);

void func_021A0084(u32 a)
{
    u32 f;
    u32 q;
    u32 buf[3];
    u16 *p;

    p = func_0216D6F0((void *)a);
    q = func_0219D49C(a);
    func_02197CCC((u8 *)a, (s32 *)buf);
    func_021C6664(q, *p, buf);
    f = 0;
    if (func_0216DAB4((void *)a) == 1) f = 1;
    func_021C6678(q, *p, f);
    if (func_02197C9C(a) == 0) {
        func_021C66EC((u32 *)q, *p, 0x1000);
    }
}
