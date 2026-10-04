/*
 * function: func_021DADAC
 * address:  0x021DADAC
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021E1030  0x021E1030  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02045CAC  0x02045CAC  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021D8A24(void *p);
extern void func_021D8E84(void *p, int v);
extern void func_021E1024(void *p);
struct Entry;
extern void func_021E1030(char *p);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
struct Link;
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern void func_02045CAC(int a, int b, int c);

void func_021DADAC(void *p)
{
    u8 b = 3;

    if (func_021D8A24(p) == 0) {
        func_02045CAC(*(int *)((char *)p + 0x720), 0x61,
                      *(int *)((char *)p + 0x738));
        func_021E1024(p);
        func_021D8E84(p, 0x021DAEF1);
        return;
    }
    if (func_0203D3A8(func_020399A8(), 0xc00, 1, &b) == 0)
        return;
    func_02039C68((struct Link *)func_020399A8(), 0x1b, 8);
    func_02045CAC(*(int *)((char *)p + 0x720), 6, *(int *)((char *)p + 0x738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, 0x021DAD85);
}
