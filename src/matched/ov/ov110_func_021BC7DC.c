/*
 * function: func_021BC7DC
 * address: 0x021BC7DC
 * packet: pkt_ov110_021BC7DC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC828 0x021BC828 thumb ov110
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021BC828(void *, u8 *);
struct Node;
extern void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
extern void func_02030EAC(struct Node *n);
int func_021BC7DC(u8 *p)
{
    switch (*(u16 *)(p+0x16)) {
    case 0:
        *(void **)(p+0x18)=func_021B9BA4(func_021BC828,p,0);
        ++*(u16 *)(p+0x16);
        break;
    case 1:
        if (*(u16 *)(p+0x14)==0) {
            func_02030EAC(*(void **)(p+0x18));
            ++*(u16 *)(p+0x16);
            return 1;
        }
        break;
    case 2: return 1;
    }
    return 0;
}
