/*
 * function: func_021F6164
 * address: 0x021F6164
 * packet: pkt_ov215_021F6164
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201F73C(void *, int, u16, int);
struct Cfg;
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void *func_02045730(void *);
extern void func_020409B4(void *);
void func_021F6164(void *unused, char *p)
{
    void *obj;
    func_0201F73C(*(void **)(p + 0x58), 0, *(unsigned *)(p + 0x60), 2);
    obj = *(void **)(p + 0x58);
    func_02045334(obj);
    func_02045374(obj);
    func_020409B4(func_02045730(obj));
}
