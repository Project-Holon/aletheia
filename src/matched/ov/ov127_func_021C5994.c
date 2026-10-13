/*
 * unit: yes
 * function: func_021C5994, func_021C59D0
 * address: 0x021C5994
 * packet: pkt_ov127_021C5994
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4ADC 0x021C4ADC thumb ov127
 *   func_021C59DC 0x021C59DC thumb ov127
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef signed short s16;
typedef struct { s16 x, y; } Pos;
extern Pos func_021C4ADC(void *);
extern void func_021C59DC(s16 *p, s16 a, s16 b);
extern void MI_CpuFill8(void *, int, int);
void func_021C5994(void *p, void *q)
{
    Pos v = func_021C4ADC(q);
    func_021C59DC(p, v.y - 96, v.x - 112);
}
void func_021C59D0(void *p) { MI_CpuFill8(p, 0, 4); }
