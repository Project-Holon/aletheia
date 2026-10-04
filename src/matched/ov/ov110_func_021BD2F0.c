/*
 * function: func_021BD2F0
 * address: 0x021BD2F0
 * packet: pkt_ov110_021BD2F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BD342.
 * symbols:
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, unsigned int);
extern void func_020307B0(void *);
void func_021BD2F0(u8 *p) {
    void *obj;
    void *handle;
    u8 *data;
    handle = func_02049F34(43, 7, (u32)(&obj), 42);
    data = *(u8 **)((u8 *)obj + 12);
    func_02082D44(data + 0x96, p + 0x98, 10);
    func_02082D44(data + 0x76, p + 0xa2, 10);
    func_020307B0(handle);
    func_02082D44(p + 0x98, p + 0xac, 10);
    *(int *)(p + 0xb8) = 0;
}
