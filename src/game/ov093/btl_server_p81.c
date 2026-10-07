/*
 * file:     btl_server_p81.c
 * unit:     yes
 * function: func_021C6DD0, func_021C6E00, func_021C6E3C, func_021C6F0C
 * address:  0x021C6DD0
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
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D70E4 0x021D70E4 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_021E8DA8 0x021E8DA8 thumb ov093
 *   func_021C7038 0x021C7038 thumb ov093
 *   func_021D79E8 0x021D79E8 thumb ov093
 *   func_021C5750 0x021C5750 thumb ov093
 *   func_021C6FC0 0x021C6FC0 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021C6F34 0x021C6F34 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_021D74F8(int);
extern void func_021D7540(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D75A8(int, u32);
extern void func_021D70E4(void *a, int id);
extern u16 func_021D57FC(void *);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int);
extern int func_021E8DA8(int);
extern int func_021C7038(u8 *, u8 *, u8 *, u32, u8);
extern int func_021D79E8(int, int);
extern void func_021C5750(u8 *, u8 *);
extern void func_021C6FC0(u8 *, u8 *);
extern int func_021EF948(int);
extern int func_021C6F34(u8 *, u8 *, int);
void func_021C6DD0(u8 *p, u8 *a);
void func_021C6E00(u8 *p, u8 *a, u8 k);
int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag);
int func_021C6F0C(u8 *p, u8 *a, int k);

void func_021C6DD0(u8 *p, u8 *a)
{
    int line = 12077;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D70F0(p, 114);
    func_021D7540(line + 3);
}

void func_021C6E00(u8 *p, u8 *a, u8 k)
{
    int line = 12093;
    func_021D74F8(line);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(3, k);
    func_021D70E4(p, 115);
    func_021D7540(line + 4);
}

int func_021C6E3C(u8 *p, u8 *a, u8 *b, u8 *q, int flag)
{
    int r, x;
    int changed = 0;
    if (q[6] == 17) return 3;
    x = func_021D57FC(b);
    r = func_021C7038(p, a, b, q[6], func_021E8CFC(x));
    if (func_021E8DA8(x) == 0)
        r = func_021D79E8(r, func_021C7038(p, a, b, q[6], func_021E8D04(x)));
    if (r != 0) {
        if (q[6] != 4) return r;
        changed = func_021C6F0C(p, b, 0);
        if (changed == 0) return r;
        r = 0;
    } else if (q[6] == 4) {
        if (func_021C6F0C(p, b, 1) == 0) return 3;
    }
    if (r == 0 && flag != 0) {
        if (changed == 0) func_021C5750(p, b);
        else func_021C6FC0(p, b);
    }
    return r;
}

int func_021C6F0C(u8 *p, u8 *a, int k)
{
    if (func_021EF948(2) == 0 && func_021C6F34(p, a, k) != 0)
        return 1;
    return 0;
}
