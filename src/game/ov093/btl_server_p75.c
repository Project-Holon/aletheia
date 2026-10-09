/*
 * file:     btl_server_p75.c
 * unit:     yes
 * function: func_021C6848, func_021C6878, func_021C68A8
 * address:  0x021C6848
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
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021C6928  0x021C6928  thumb  ov093
 *   func_021C6938  0x021C6938  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, unsigned int);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern u32 func_021C6928(u8 *d);
extern u8 *func_021C6938(u8 *d, u32 i);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
void func_021C6848(u8 *p, u8 *a);
void func_021C6878(u8 *p, u8 *a, int a2);
int func_021C68A8(u8 *p, u8 *a, u8 *d, u16 a3);


void func_021C6848(u8 *p, u8 *a)
{
    func_021D74F8(11692);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x96);
    func_021D7540(11695);
}


void func_021C6878(u8 *p, u8 *a, int a2)
{
    func_021D74F8(11709);
    func_021D75EC(3, func_021D5440(a));
    func_021D70F0(p, 0x97);
    func_021D7540(11712);
}


int func_021C68A8(u8 *p, u8 *a, u8 *d, u16 a3)
{
    u32 n;
    u32 i;
    u8 t;
    n = func_021C6928(d);
    func_021D74F8(11731);
    func_021D75EC(3, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C6938(d, i)));
    }
    func_021D70F0(p, 0x98);
    t = func_021D775C(0x41);
    func_021D7540(11742);
    return t == 0;
}
