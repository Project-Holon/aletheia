/*
 * function: func_021D51BC
 * address: 0x021D51BC
 * packet: pkt_ov175_021D51BC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * DA36C receives the live context in r0 here despite its no-argument body.
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D54E8 0x021D54E8 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_0203064C 0x0203064C arm
 *   func_02156E30 0x02156E30 thumb
 *   func_02156F50 0x02156F50 thumb
 *   func_02156ED0 0x02156ED0 thumb
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021E8AC0 0x021E8AC0 thumb ov177
 *   func_021DA5B0 0x021DA5B0 thumb ov175
 *   func_021DA6B8 0x021DA6B8 thumb ov175
 *   func_021DADAC 0x021DADAC thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021DA384 0x021DA384 thumb ov175
 *   func_021DA390 0x021DA390 thumb ov175
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_02008530 0x02008530 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021DBC04 0x021DBC04 thumb ov175
 *   func_021DBDAC 0x021DBDAC thumb ov175
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 w[20]; } Rec80;
typedef struct { Rec80 data; u32 last; } Rec84;
struct Big;
struct L0200ED54;
extern void func_021E8AA0(int *, int);
extern void func_021D54E8(void);
extern void func_021D61A4(void);
extern void func_0203064C(void *, u32, u32);
extern void func_02156E30(int, int, int, int);
extern void func_02156F50(int);
extern void func_02156ED0(void);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
extern void func_021E8AA8(int);
extern void func_021E8AC0(int, int);
extern void func_021DA5B0(char *, int, int, u32, u32 *, u32);
extern int func_021DA6B8(void *, u32 *);
extern u32 func_021DADAC(char *);
extern int func_021D9F04(char *, void *, void *);
extern void func_021DA36C(int);
extern void func_021DA384(char *);
extern int func_021DA390(char *);
extern void *func_02012EBC(struct Big *);
extern void *func_0200ED48(void *);
extern void func_0200ED54(struct L0200ED54 *, u32);
extern u32 func_02008530(void *);
extern void func_02082BCC(void *, int, unsigned);
extern void func_021DBC04(char *, unsigned, void *);
extern int func_021DBDAC(char *);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
#define P(k) (*(int *)(p + (k)))
#define Q(k) (*(int *)(q + (k)))
void func_021D51BC(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    Rec84 rec;
    void *list;
    int result;
    switch (*state) {
    case 0:
        if (Q(12) == 2 && P(0xf8) == 0) {
            func_021E8AA0((int *)sys, (int)func_021D54E8);
            return;
        }
        P(0xf8) = 0;
        func_0203064C((void *)1, 0x86, 0x60000);
        func_02156E30(9, 0x60000, 1000, 0x86);
        func_02156F50(0x86);
        *state = 1;
        break;
    case 1:
        func_021E8738((int *)P(0x24), P(0x10), 37, 2);
        *state = 14;
        func_021E8AB4(sys, 2);
        break;
    case 2:
        func_021DA5B0((char *)P(0x30), 1, 2, ((u32 *)Q(8))[1], (u32 *)Q(0x2c), Q(12) == 2);
        P(0xfc) = 0;
        P(0xf4) = 0;
        *state = 3;
        break;
    case 3:
        if (P(0xfc) == 0) {
            P(0xfc) = func_021DA6B8((void *)P(0x30), (u32 *)(p + 0xf4));
            if (P(0xfc) != 0 && P(0xf4) != 0)
                func_021E8AC0(*(int *)Q(8), *(int *)Q(0x2c));
        }
        if (P(0xfc) == 1) {
            ((u32 *)Q(0x2c))[5] = func_021DADAC((char *)P(0x30));
            *state = 4;
        }
        if (P(0xfc) != 0) {
            switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
            case 1: func_021DA36C(P(0x30));
            case 2: case 4:
                func_02156ED0();
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                break;
            }
        }
        break;
    case 4:
        func_02156ED0();
        if (Q(12) == 2) func_021E8AA0((int *)sys, (int)func_021D54E8);
        else *state = 5;
        break;
    case 5:
        list = func_0200ED48(func_02012EBC(*(struct Big **)Q(8)));
        func_0200ED54(list, func_02008530((void *)Q(0x18)));
        *state = 6;
        func_021DA384((char *)P(0x30));
        break;
    case 6:
        if (func_021DA390((char *)P(0x30))) {
            if (*(int *)((int *)P(0x40))[8] == 0) *state = 8;
            else {
                func_021E8738((int *)P(0x24), P(0x10), 42, 2);
                *state = 14;
                func_021E8AB4(sys, 7);
            }
        }
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: *state = 7; break;
        case 2: func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 7:
        if (*(int *)Q(0x20) == 0) *state = 8;
        break;
    case 8:
        func_02082BCC(&rec, 0, 0x54);
        rec.data = *(Rec80 *)((int *)P(0x40))[9];
        rec.last = *(u32 *)((int *)P(0x40))[10];
        func_021DBC04((char *)P(0x30), 3, &rec);
        *state = 9;
        break;
    case 9:
        result = func_021DBDAC((char *)P(0x30));
        if (result == 1) {
            *(int *)((int *)P(0x40))[8] = 0x708;
            *state = 10;
        }
        if (result != 0) {
            switch (func_021D9F04((char *)P(0x30), 0, 0)) {
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                *(int *)((int *)P(0x40))[8] = 0x708;
                break;
            case 1:
                *(int *)((int *)P(0x40))[8] = 0x708;
                *state = 10;
                break;
            }
        }
        break;
    case 10:
        func_021E8738((int *)P(0x24), P(0x10), 88, 1);
        *state = 14;
        func_021E8AB4(sys, 11);
        break;
    case 11:
        func_021E8738((int *)P(0x24), P(0x10), 40, 2);
        *state = 14;
        func_021E8AB4(sys, 12);
        break;
    case 12:
        func_02012DAC(*(int *)Q(8));
        *state = 13;
        break;
    case 13:
        switch (func_02012DD0(*(u8 **)Q(8))) {
        case 0: case 1: break;
        case 2: case 3:
            Q(4) = 2;
            func_021E8AA8(sys);
            break;
        }
        break;
    case 14:
        if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys);
        break;
    }
}
