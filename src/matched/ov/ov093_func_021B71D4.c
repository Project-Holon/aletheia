/*
 * function: func_021B71D4
 * address: 0x021B71D4
 * packet: pkt_ov093_021B71D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021B6848 0x021B6848 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021B69FC 0x021B69FC thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021B6A3C 0x021B6A3C thumb ov093
 *   func_021B6A70 0x021B6A70 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAB40 0x021BAB40 thumb ov093
 *   func_021B83F4 0x021B83F4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B6818(int *);
struct T;
extern void func_021B6848(u8 *, struct T *);
extern void func_021B93E0(char *, u32, u32);
extern void func_021B9460(void *, void *, u8);
extern int func_021BA9C8(void *, void *, void *, int, u16);
extern void func_021B69FC(int, char *);
extern int func_021CD6F0(void *, void *, int, int, u16, u8, u8, int, u8, void *, u16);
extern void func_021B6A3C(unsigned char *p, unsigned char *q);
extern void func_021B6A70(unsigned char *p, unsigned char *q, int r);
extern int func_021CD978(int);
extern void func_021BAA94(int, int, u8, u8);
extern void func_021BAB40(int);
extern int func_021B83F4(int a);
int func_021B71D4(int unused, u8 *p)
{
    u8 *q;
    int t;
    q = *(u8 **)p;
    t = func_021B6818((int *)q);
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    p[0x42a] = 0;
    p[0x42b] = 1;
    p[0x42c] = 0;
    p[0x42d] = 1;
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460(p + 0xc8, p, 0);
    func_021B9460(p + 0xc8, p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460(p + 0x1b0, p, 0);
    func_021B9460(p + 0x1b0, p, 1);
    *(int *)(p + 8) = func_021BA9C8(p, p + 0x3f0, p + 0x1b0, t, *(u16 *)(p + 0x468));
    p[0x46e] = 1;
    func_021B69FC((int)p, (char *)q);
    *(int *)(p + 0x10) = func_021CD6F0(p, p + 0xc8, 0, *(int *)(q + 0x1c), 0, 1, 0, t, q[0x23], p + 0x3f0, *(u16 *)(p + 0x468));
    *(int *)(p + 0x14) = func_021CD6F0(p, p + 0xc8, 0, *(int *)(q + 0x1c), 1, 1, 1, t, q[0x23], p + 0x3f0, *(u16 *)(p + 0x468));
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94(*(int *)(p + 8), func_021CD978(*(int *)(p + 0x10)), 0, 1);
    func_021BAA94(*(int *)(p + 8), func_021CD978(*(int *)(p + 0x14)), 1, 1);
    func_021BAB40(*(int *)(p + 8));
    *(u32 *)(p + 0x464) = (u32)func_021B83F4;
    return 1;
}
