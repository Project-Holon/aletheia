/*
 * function: func_021BC93C, func_021BC964
 * unit: yes
 * address: 0x021BC93C
 * packet: pkt_ov110_021BC93C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: callback func_021BC964 included in unit; function_starts seed.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_0207D658 0x0207D658 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_0207D658(u32 addr, int plane, int brightness);
int func_021BC93C(u8 *p)
{
    if (*(int *)(p+0x18)==0) {
        if (*(int *)(p+0x14)==0) {
            func_02030EAC(*(void **)(p+0x1c));
            ++*(int *)(p+0x18);
            return 1;
        }
    } else return 1;
    return 0;
}
void func_021BC964(void *unused,u8 *p)
{
    int value;
    if (*(int *)(p+0x14)) {
        *(int *)(p+8)+=*(int *)(p+0x10);
        value=*(int *)(p+8)>>12;
        --*(int *)(p+0x14);
    } else value=*(int *)(p+0xc)>>12;
    func_0207D658(0x4000050,*(int *)p,value);
}
