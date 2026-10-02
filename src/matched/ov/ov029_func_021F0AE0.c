/*
 * function: func_021F0AE0
 * address: 0x021F0AE0
 * packet: pkt_ov029_021F0AE0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F1290 0x021F1290 thumb ov029
 *   func_021F0C00 0x021F0C00 thumb ov029
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 on:1, cnt:15; u16 f2; u8 f4, f5, f6, f7; } Ent;
extern void func_021F1290(void *, int, int, int);
extern void func_021F0C00(Ent *, int);
void func_021F0AE0(Ent *p, void *q, int c)
{
    p->f4 = 0;
    func_021F1290(q, p->f6, p->f7, c);
    func_021F0C00(p, 0);
}
