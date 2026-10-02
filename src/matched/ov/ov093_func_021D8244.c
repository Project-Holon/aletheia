/*
 * function: func_021D8244
 * address: 0x021D8244
 * packet: pkt_ov093_021D8244
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct B { u32 count; u8 val[4]; };
void func_021D8244(struct B *p, int n) { u32 i; for(i=0;i<4;i++) { if(p->val[i]==n) return; if(p->val[i]==4) { p->val[i]=n; ++p->count; return; } } }
