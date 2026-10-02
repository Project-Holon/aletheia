/*
 * function: func_021B8D88
 * address: 0x021B8D88
 * packet: pkt_ov070_021B8D88
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6100 0x021B6100 thumb ov070
 */
typedef unsigned short u16;
typedef void (*Callback)(void *);
extern void func_021B6100(void *p, Callback callback);
void func_021B8D88(char *p)
{
    if (*(u16 *)(p + 0x866) == 0) {
        *(u16 *)(p + 0x864) = 0;
        func_021B6100(p, *(Callback *)(p + 0x868));
    } else {
        *(u16 *)(p + 0x866) -= 1;
    }
}
