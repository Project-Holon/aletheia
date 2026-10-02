/*
 * function: func_021D7840
 * address: 0x021D7840
 * packet: pkt_ov093_021D7840
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6360 0x021F6360 data a4
 *   d_021F3AB8 0x021F3AB8 data a1
 *   func_02030734 0x02030734 arm
 */
typedef struct { unsigned int v[6]; } Words;
typedef struct { unsigned int f0; void *f4; Words words; } State;
extern State d_021F6360;
extern const unsigned char d_021F3AB8[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
void func_021D7840(const Words *p, unsigned int heap) { d_021F6360.f4=func_02030734(heap,0x460,1,(const char *)d_021F3AB8,0x50); d_021F6360.words=*p; }
