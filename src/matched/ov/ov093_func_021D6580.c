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
struct S;
struct UtilWork;
extern void func_021D5364(struct UtilWork *p);
extern void func_021D6D70(unsigned char *p);
extern void func_021D63B8(u8 *p, int all);
extern void func_021D4EFC(struct S *a, void *mon, u32 c, u32 d);
extern void func_021D53C0(unsigned char *p);

void func_021D6580(Obj *p)
{
    func_021D4EFC((struct S *)p, p->w, 0, 1);
    func_02082BCC((u8 *)p + 0x155, 0, 2);
    func_02082BCC((u8 *)p + 0x153, 0, 2);
    func_021D6D70((unsigned char *)p);
    func_021D5364((struct UtilWork *)p);
    func_021D63B8((u8 *)p, 0);
    func_021D53C0((unsigned char *)((char *)p + 0xfc));
}
