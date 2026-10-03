/*
 * function: func_021BC898
 * address: 0x021BC898
 * packet: pkt_ov110_021BC898
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
int func_021BC898(u8 *p)
{
    if (*(int *)(p + 24) == 0) {
        if (*(int *)(p + 20) == 0) {
            func_02030EAC(*(void **)(p + 28));
            *(int *)(p + 24) += 1;
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}
