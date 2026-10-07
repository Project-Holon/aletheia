/*
 * file:     btl_server_p56.c
 * unit:     yes
 * function: func_021C2AB0, func_021C2AF0, func_021C2B3C, func_021C2BA4, func_021C2BF0, func_021C2C50, func_021C2CA8, func_021C2CD8
 * address:  0x021C2AB0
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
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021EF884  0x021EF884  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C2D10 0x021C2D10 thumb ov093
 *   func_021C2E64 0x021C2E64 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021EF884(void);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7674(int a, u32 b, u32 c, u32 d);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70E4(void *a, int id);
extern int func_021D5B68(void *);
extern int func_021C2D10(u8 *, u16 *, u8 *, u8 *);
extern int func_021C2E64(u8 *, const u16 *, u8 *, u8 *, int);
int func_021C2AB0(u8 *p);
int func_021C2AF0(u8 *p, u8 *a);
int func_021C2B3C(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2BA4(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2BF0(u8 *p, u8 *a, u8 *b, u32 c, u32 d);
void func_021C2C50(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C2CA8(u8 *p, u8 *a);
void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b);


int func_021C2AB0(u8 *p)
{
    int r;
    int t;
    func_021D74F8(7971);
    func_021D7630(0x41, 0);
    r = 0;
    func_021D70F0(p, 0x7a);
    t = func_021D775C(0x41);
    func_021D7540(7975);
    if (t == 0)
        r = func_021EF884();
    return r;
}


int func_021C2AF0(u8 *p, u8 *a)
{
    int r;
    func_021D74F8(7997);
    func_021D75EC(2, func_021D5440(a));
    func_021D7674(0x35, 2 << 11, 410, 2 << 16);
    func_021D70F0(p, 0x7B);
    r = func_021D775C(0x35);
    func_021D7540(8002);
    return r;
}


int func_021C2B3C(u8 *p, u8 *a, u8 *b, u32 c)
{
    int r;
    func_021D74F8(8021);
    func_021D75EC(3, a ? func_021D5440(a) : 0x1F);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x1D, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x65);
    r = func_021D775C(0x41);
    func_021D7540(8028);
    return r;
}


void func_021C2BA4(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8042);
    func_021D75A8(4, func_021D5440(a));
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x1D, c);
    func_021D70F0(p, 0x67);
    func_021D7540(8047);
}


void func_021C2BF0(u8 *p, u8 *a, u8 *b, u32 c, u32 d)
{
    func_021D74F8(8062);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D75EC(0x1E, d);
    func_021D70F0(p, 0x68);
    func_021D7540(8071);
}


void func_021C2C50(u8 *p, u8 *a, u8 *b, u32 c)
{
    func_021D74F8(8085);
    func_021D75EC(4, func_021D5440(a));
    func_021D75EC(3, (u8)(b ? func_021D5440(b) : 0x1F));
    func_021D75EC(0x1D, c);
    func_021D70F0(p, 0x69);
    func_021D7540(8093);
}

void func_021C2CA8(u8 *p, u8 *a)
{
    func_021D74F8(8105);
    func_021D75EC(2, func_021D5440(a));
    func_021D70E4(p, 0x6a);
    func_021D7540(8108);
}

/*
 * extent: two bytes of zero alignment padding at 0x021C2D0E.
 */
void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b)
{
    if (func_021D5B68(b) == 0) {
        if (func_021C2D10(p, q, a, b) != 0)
            func_021C2E64(p, q, a, b, 0);
    }
}
