/*
 * function: func_021EF140
 * address: 0x021EF140
 * packet: pkt_ov188_021EF140
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045924 0x02045924 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02045A98 0x02045A98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Strbuf;
struct U16Vec;
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_02045A98(void);
void func_021EF140(u8 *a, u8 *b)
{
    unsigned i;
    u16 *p;
    *(u32 *)a = *(u16 *)(b+4);
    *(u32 *)(a+4) = *(u16 *)(b+6);
    *(u32 *)(a+8) = *(u32 *)b;
    *(u16 *)(a+0x18) = *(u16 *)(b+0x30);
    *(u16 *)(a+0x1a) = *(u16 *)(b+0x32);
    *(u16 *)(a+0x1c) = *(u16 *)(b+0x34);
    *(u16 *)(a+0x1e) = *(u16 *)(b+0x36);
    *(u16 *)(a+0x20) = *(u16 *)(b+0x38);
    *(u16 *)(a+0x22) = *(u16 *)(b+0x3a);
    *(u16 *)(a+0x24) = *(u16 *)(b+0x3c);
    *(u16 *)(a+0x26) = *(u16 *)(b+0x3e);
    for(i=0;i<4;i++) *(u16 *)(a+12+i*2) = *(u16 *)(b+8+i*2);
    func_02045924(*(void **)(a+20), (u16 *)(b+16));
    p = func_02045A90(*(void **)(a+20));
    while (*p != func_02045A98()) p++;
}
