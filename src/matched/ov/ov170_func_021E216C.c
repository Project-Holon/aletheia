/*
 * function: func_021E216C
 * address: 0x021E216C
 * packet: pkt_ov170_021E216C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * spelling: Member addresses keep the +0 and +4 table pool addends separate.
 * symbols:
 *   d_021EFA2C 0x021EFA2C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void (*callback)(u8 *); u32 value; u32 next; } Dispatch;
extern Dispatch d_021EFA2C;
int func_021E216C(u8 *p){if(*(int *)(p+8)!=1){(*(void (**)(u8 *))((u32)&d_021EFA2C.callback+p[0x12]*12))(p);*(u32 *)(p+0x28)=*(u32 *)((u32)&d_021EFA2C.value+p[0x12]*12);return 0;}return 10;}
