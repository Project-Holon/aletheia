/*
 * function: func_0217F8A0
 * address: 0x0217F8A0
 * packet: pkt_ov018_0217F8A0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow at 0x0217F8CE.
 * lever: stores in both arms keep the branch to the shared store.
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02012138 0x02012138 thumb
 *   func_02158344 0x02158344 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 *func_02159AE8(void *, void *);
extern void *func_0215A5DC(void *);
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *);
extern u8 *func_02158344(void *);
int func_0217F8A0(void *a, void *vm)
{
    u16 *out;
    u8 *p;
    int v;
    out = func_02159AE8(a, vm);
    p = func_02158344((void *)func_02012138(func_0215A5DC(vm)));
    if (p == 0 || *(u16 *)(p + 0x88) == 0) {
        *out = 0;
    } else {
        *out = *(u16 *)(p + 0x88);
    }
    return 0;
}
