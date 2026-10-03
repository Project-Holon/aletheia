/*
 * function: func_021C41E0
 * address: 0x021C41E0
 * packet: pkt_ov136_021C41E0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_021C4184 0x021C4184 thumb ov136
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0203F8F4 0x0203F8F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0203064C(unsigned, unsigned, unsigned);
extern void *func_0203159C(void *, unsigned, unsigned);
extern void func_02082AC0(unsigned, void *, unsigned);
extern signed char func_02012FFC(void);
extern void func_021C4184(void *, u8 *);
extern void *func_0201D7EC(unsigned, unsigned, unsigned, unsigned, u16);
extern void *func_0203101C(u16, u16, unsigned, unsigned);
extern void func_0203F8F4(u16);
int func_021C41E0(void *a, void *b, u8 *p)
{
    u8 *q;
    u8 v;
    func_0203064C(1, 0x64, 0x20000);
    q = func_0203159C(a, 0x15C, 0x64);
    func_02082AC0(0, q, 0x15C);
    *(unsigned *)q = 0x64;
    *(void **)(q + 0x1C) = p;
    q[0xB] = *(u16 *)p;
    q[0xC] = q[0xB];
    q[0x16] = p[2];
    q[0x17] = p[3];
    v = q[0x16];
    q[0x1A] = v;
    q[0x1B] = v;
    *(u16 *)p = 0xFFFF;
    q[0x15] = func_02012FFC();
    func_021C4184(q, *(u8 **)(q + 0x1C));
    *(void **)(q + 0x24) = func_0201D7EC(0x17, 0, 0, 0, *(unsigned *)q);
    *(void **)(q + 0x100) = func_0203101C(*(unsigned *)q, *(unsigned *)q, 0x20, 0x20);
    q[0xA] = 1;
    func_0203F8F4(*(unsigned *)q);
    return 1;
}
