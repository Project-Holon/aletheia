/*
 * function: func_021B9CBC
 * address: 0x021B9CBC
 * packet: pkt_ov133_021B9CBC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021F5158 0x021F5158 thumb ov112
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021F4F10(u8 *);
extern u8 *func_021BA20C(u8 *);
extern u8 func_021F5158(void *, int);
extern void *func_0201EC64(unsigned int);
extern void *func_02045EC0(void *, unsigned int);
extern void func_0201EE0C(void *, unsigned int, void *, unsigned int, unsigned int, unsigned int);
extern void func_021B9C08(u8 *, unsigned int, void *);
extern void func_02045808(void *);
extern void func_0201ED04(void *);
void func_021B9CBC(u8 *p, u8 *entry)
{
    void *manager = func_021F4F10(*(u8 **)(p + 0x1884));
    u8 *data = func_021BA20C(entry);
    int index = func_021F5158(manager, *(u16 *)data);
    void *obj = func_0201EC64(*(u16 *)p);
    void *a = func_02045EC0(*(void **)(p + 0x18dc), *(u16 *)data + 3);
    void *b = func_02045EC0(*(void **)(p + 0x18e0), index + 16);
    func_0201EE0C(obj, 0, a, 0, 1, 2);
    func_0201EE0C(obj, 1, b, 0, 1, 2);
    func_021B9C08(p, 3, obj);
    func_02045808(b);
    func_02045808(a);
    func_0201ED04(obj);
}
