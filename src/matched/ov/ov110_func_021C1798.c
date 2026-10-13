/*
 * function: func_021C1798
 * address: 0x021C1798
 * packet: pkt_ov110_021C1798
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: observed 44-byte table rows use a typed Row pointer; integer address
 * arithmetic swaps base/index colours, Row member access is EXACT.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021C3A74 0x021C3A74 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020403F4(u32);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *,int,u32);
typedef struct {u32 id; u32 rest[10];} Row;
extern Row d_021C3A74[];
void func_021C1798(void *p) { const Row *base; unsigned long i; base=d_021C3A74; for(i=0;i<6;i++) func_020403F4((u8)base[i].id); BMP_WIN_Exit(); func_0203F9B4(); func_02082BCC(p,0,4); }
