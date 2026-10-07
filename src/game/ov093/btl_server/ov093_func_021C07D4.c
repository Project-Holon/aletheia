/*
 * function: func_021C07D4
 * address:  0x021C07D4
 * packet:   pkt_ov093_021C07D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * c and d are narrow parameters: their home stores (`str r2,[sp]` first,
 * `str r3,[sp,#4]` after `adds r7,r1`) sit where the narrow-parameter idiom
 * puts them; as u32 both sink below `ldr r5`. u8 and u16 compile the same
 * (any mix of the two); nothing in the image fixes the width, u16 chosen.
 * func_021C0868/0878/0888 are `bx pc` ARM veneers declared as thumb externs.
 * `i = 0;` as its own statement before the func_021C0868 call puts
 * `movs r4,#0` between `adds r0,r5` and that bl.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021C0868  0x021C0868  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021C0878  0x021C0878  thumb  ov093
 *   func_021C0888  0x021C0888  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021D74F8(int line);
extern u32 func_021C0868(int e);
extern void func_021D75EC(int key, u32 val);
extern u8 *func_021C0878(int e, int i);
extern u8 *func_021C0888(int e, int i);
extern u8 func_021D5440(u8 *p);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);

int func_021C07D4(u8 *p, u8 *a, u16 c, u16 d, int e)
{
    int i;
    u8 *r;
    int res;
    func_021D74F8(0x16ef);
    i = 0;
    func_021D75EC(5, func_021C0868(e));
    r = func_021C0878(e, 0);
    if (r != 0) {
        do {
            func_021D75EC(i + 6, func_021D5440(r));
            i++;
            r = func_021C0888(e, i);
        } while (r != 0);
    }
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, d);
    func_021D75EC(0x17, c);
    func_021D75A8(0x20, 1);
    func_021D70F0(p, 0x4e);
    res = func_021D775C(0x20);
    func_021D7540(0x1704);
    return res;
}
