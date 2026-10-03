/*
 * function: func_021C9360
 * address:  0x021C9360
 * packet:   pkt_ov021_021C9360
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DAC44  0x021DAC44  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *p);
typedef struct { u32 a[6]; u32 b[9]; } T;
typedef struct { u8 pad[0x14]; u32 f14; } E;
extern T d_021DAC44;
extern void func_0207ADC4(void *p);
extern void func_021AC1B8(u32 a, T *t);
extern void func_02047AC8(u32 h, T *t);
void func_021C9360(u32 a, E *e)
{
    T t = d_021DAC44;
    func_0207ADC4(t.b);
    func_021AC1B8(a, &t);
    func_02047AC8(e->f14, &t);
}
