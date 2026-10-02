/*
 * function: func_021D70C8
 * address: 0x021D70C8
 * packet: pkt_ov093_021D70C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned int u32;
typedef struct { u32 pad[6]; u32 low:24, active:1, rest:7; } Node;
void func_021D70C8(Node *p)
{
    if (p->active) *(u32 *)((unsigned char *)p + 0x18) |= 0x10000000;
}
