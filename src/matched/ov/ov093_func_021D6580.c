/*
 * function: func_021D6580
 * address:  0x021D6580
 * packet:   pkt_ov093_021D6580
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021D5364  0x021D5364  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021D63B8  0x021D63B8  thumb  ov093
 *   func_021D53C0  0x021D53C0  thumb  ov093
 *   func_021D4EFC  0x021D4EFC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct {
    void *w;
    u8 pad4[0x12];
    u16 f16;
    u8 pad18[3];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;
extern void func_02082BCC(void *dst, u8 v, u32 n);
extern void func_021D5364(Obj *p);
extern void func_021D6D70(Obj *p);
extern void func_021D63B8(Obj *p, int k);
extern void func_021D4EFC(Obj *p, void *w, int a, int b);
extern void func_021D53C0(char *p);

void func_021D6580(Obj *p)
{
    func_021D4EFC(p, p->w, 0, 1);
    func_02082BCC((u8 *)p + 0x155, 0, 2);
    func_02082BCC((u8 *)p + 0x153, 0, 2);
    func_021D6D70(p);
    func_021D5364(p);
    func_021D63B8(p, 0);
    func_021D53C0((char *)p + 0xfc);
}
