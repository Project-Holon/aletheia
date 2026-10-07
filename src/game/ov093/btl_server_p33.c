/*
 * file:     btl_server_p33.c
 * unit:     yes
 * function: func_021BEA60, func_021BEAB4
 * address:  0x021BEA60
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
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021BEB14 0x021BEB14 thumb ov093
 *   func_021BEB04 0x021BEB04 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);
extern int func_021BEB14(int a, u8 *b, int c, int d, u8 *e, u8 *g);
extern u8 func_021BEB04(u8 *p, int selector);
void func_021BEA60(u8 *p, u8 *a, u8 *b, u32 c);
int func_021BEAB4(u8 *p, u8 *a, int b, int c, u8 *q);


void func_021BEA60(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(4069);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(0x12, c);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 9);
    func_021D7540(4075);
}

/*
 * The byte loaded and compared in r1 remains the veneer call's second
 * argument. The veneer at 021BEB04 preserves r0/r1 to its target.
 */
int func_021BEAB4(u8 *p, u8 *a, int b, int c, u8 *q)
{
    u8 buf[2];
    buf[1] = 0x1F;
    buf[0] = 0x1F;
    func_021BEB14((int)p, a, b, c, &buf[1], &buf[0]);
    if (buf[1] != 0x1F) {
        q[7] = (buf[0] != 0x1F) ? func_021BEB04(p + 0x1AB8, buf[0]) : 6;
        q[1] = buf[1];
        q[0] = 1;
        return 1;
    }
    return 0;
}
