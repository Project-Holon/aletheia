/*
 * function: func_021B8254
 * address: 0x021B8254
 * packet: pkt_ov133_021B8254
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA124 0x021BA124 thumb ov133
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 */
typedef unsigned char u8;
typedef struct { int x,y,z; } Vec;
extern u8 *func_021BA218(u8 *);
extern void func_021BA148(void *, u8 *);
extern void func_021BA124(void *, u8 *);
extern u8 *func_021BA184(void *);
extern u8 *func_021BA208(u8 *);
extern void func_021F4EB4(int, int, short, short);
extern void func_021F4EA4(int, int, Vec *);
extern void func_021F4E8C(int, int, Vec *);
void func_021B8254(u8 *p)
{
    Vec v;
    u8 *e, *s;
    int z = 0xa000;
    s = func_021BA218(*(u8 **)(p + 0x38));
    func_021BA148(*(void **)(p + 0x1820), *(u8 **)(p + 0x38));
    func_021BA124(*(void **)(p + 0x1820), *(u8 **)(p + 0x38));
    func_021F4EB4(*(int *)(p + 0x1884), (int)s, 4096, 4096);
    e = func_021BA184(*(void **)(p + 0x1820));
    while (e) {
        s = func_021BA218(e);
        func_021F4EA4(*(int *)(p + 0x1884), (int)s, &v);
        v.z = z;
        func_021F4E8C(*(int *)(p + 0x1884), (int)s, &v);
        z -= 1024;
        e = func_021BA208(e);
    }
}
