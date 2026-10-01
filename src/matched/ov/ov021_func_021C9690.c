/*
 * function: func_021C9690
 * address:  0x021C9690
 * packet:   pkt_ov021_021C9690
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DAC94  0x021DAC94  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_020307B0(void *p);
typedef struct { u32 a[6]; u32 b[9]; } T;
typedef struct { u32 f0; u32 f4; } E;
extern T d_021DAC94;
extern void func_0207ADC4(void *p);
extern void func_021AC1B8(u32 a, T *t);
extern void func_02047AC8(u32 h, T *t);
void func_021C9690(u32 a, E *e)
{
    T t = d_021DAC94;
    func_0207ADC4(t.b);
    func_021AC1B8(a, &t);
    func_02047AC8(e->f4, &t);
}
