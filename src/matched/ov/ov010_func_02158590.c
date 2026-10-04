/*
 * function: func_02158590
 * address: 0x02158590
 * packet: pkt_ov010_02158590
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   d_021700A8 0x021700A8 data a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *, int);
extern const u16 d_021700A8[2];
int func_02158590(void *p)
{
    void *q = (void *)func_0201296C(p);
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (func_020142E8(q, d_021700A8[i]) == 0)
            return 0;
    }
    return 1;
}
