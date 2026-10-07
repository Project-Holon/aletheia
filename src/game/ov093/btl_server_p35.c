/*
 * file:     btl_server_p35.c
 * unit:     yes
 * function: func_021BF168, func_021BF1B4
 * address:  0x021BF168
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021BF204  0x021BF204  thumb  ov093
 *   func_021BF214  0x021BF214  thumb  ov093
 *   func_021BF224  0x021BF224  thumb  ov093
 *   func_021BF234  0x021BF234  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75A8(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021BF204(int c);
extern int func_021BF214(int c);
extern void func_021BF224(int c, int x);
extern int func_021BF234(int c);
extern u32 func_021D6D7C(u8 *p);
extern u32 func_0201BEB8(u16 id, u32 bit);
int func_021BF168(u8 *p, u16 *a, u8 *b);
void func_021BF1B4(int u, u16 *b, int s, int c, int e);


int func_021BF168(u8 *p, u16 *a, u8 *b)
{
    int r;
    func_021D74F8(4500);
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x12, *a);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x3d);
    r = func_021D775C(0x51);
    func_021D7540(4506);
    return r;
}


void func_021BF1B4(int u, u16 *b, int s, int c, int e)
{
    int x;
    func_021BF204(c);
    x = func_021BF214(c);
    while (x != 0) {
        if (s != x && func_021D6D7C((u8 *)x) != 0 && e == 0 && func_0201BEB8((u16)((void *)*b), 0xd) == 0)
            func_021BF224(c, x);
        x = func_021BF234(c);
    }
}
