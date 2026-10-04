/*
 * function: func_021B8CB4
 * address: 0x021B8CB4
 * packet: pkt_ov070_021B8CB4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_021B6100 0x021B6100 thumb ov070
 */
typedef unsigned short u16;
typedef void (*Callback)(void *);
typedef unsigned int   u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
extern void func_021B6100(void *p, Callback callback);
void func_021B8CB4(char *p)
{
    if (func_0204B98C((struct Actor *)(*(int *)(p + 0x710 + *(u16 *)(p + 0x864) * 4))) == 0) {
        *(u16 *)(p + 0x864) = 0;
        func_021B6100(p, *(Callback *)(p + 0x868));
    }
}
