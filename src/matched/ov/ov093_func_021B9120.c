/*
 * function: func_021B9120
 * address: 0x021B9120
 * packet: pkt_ov093_021B9120
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8CFC 0x021B8CFC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B8CFC(u8 *p, int i);
void func_021B9120(u8 *p, u8 n)
{
    u8 cnt;
    u8 t;
    u8 m;
    if (*(u8 *)(*(u32 *)p + 0x90) == 6) {
        m = n;
        t = func_021B8CFC(p, n);
        cnt = 0;
        while (m--) {
            if (t == *(u8 *)(p + m + 0x428))
                cnt++;
        }
        *(u8 *)(*(u32 *)p + 0x90) = cnt;
    }
}
