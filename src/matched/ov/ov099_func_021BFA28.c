/*
 * function: func_021BFA28
 * address: 0x021BFA28
 * packet: pkt_ov099_021BFA28
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0203C3EC 0x0203C3EC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021C23B8(int);
extern void func_021C27E0(void *);
extern u8 func_021BDD48(char *, void *);
extern int func_02156A3C(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern int func_0203C3EC(void);
extern void func_021BA8EC(char *);
extern void func_021C282C(void *);
extern void func_021C18C8(char *, int, unsigned);
extern void func_021C24A4(char *, int);
extern void func_021BAADC(char *, int, int);
int func_021BFA28(char *p, int ret)
{
    void *s;
    unsigned v;
    s = func_021C23B8(*(u16 *)(p + 0x242) - 1);
    func_021C27E0(s);
    v = func_021BDD48(p, s);
    *(int *)(p + 0x1c4) -= 1;
    if (*(int *)(p + 0x1c4) < 0) {
        *(int *)(p + 0x1cc) = 0x3d;
    } else if (v != 1 && v != 2) {
        func_021BA874(p, func_02156A3C());
        func_021BAAB8(p, 0xd, 0);
        *(int *)(p + 0x1cc) = 0x13;
    } else if (func_0203C3EC() == 1) {
        func_021BA8EC(p);
        func_021C282C(*(void **)(p + 8));
        *(u8 *)(p + 0x1351) = 0;
        func_021C18C8(p, 4, 4);
        *(u8 *)(p + 0x1355) = 0;
        *(int *)(p + 0x1cc) = 0x10;
        func_021C24A4(p, 0);
        func_021BAADC(p, 0x7b, 0);
    }
    return ret;
}
