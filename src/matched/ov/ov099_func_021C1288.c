/*
 * unit: yes
 * function: func_021C1288, func_021C12CC
 * address: 0x021C1288
 * packet: pkt_ov099_021C1288
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * size: 72
 * follower: empty return at 0x021C12CC.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0200ED48 0x0200ED48 thumb
 */
extern int func_020399A8(void);
extern void *func_02012950(void *, int);
extern void func_02008494(void *, void *);
extern void *func_0200ED48(void *);
extern unsigned func_02008530(void *);
extern void func_0200ED54(void *, unsigned);
void func_021C1288(int index, int unused, void *src, char *p, int handle)
{
    void *q;
    void *list;
    if (handle == func_020399A8()) {
        q = func_02012950(*(void **)(p + 0xc4), index);
        func_02008494(src, q);
        list = func_0200ED48(*(void **)(p + 0xc0));
        func_0200ED54(list, func_02008530(q));
    }
}
void func_021C12CC(void) {}
