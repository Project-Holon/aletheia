/*
 * function: func_021D57BC
 * address: 0x021D57BC
 * packet: pkt_ov175_021D57BC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D62A4 0x021D62A4 thumb ov175
 *   func_021D63B0 0x021D63B0 thumb ov175
 *   func_021D6788 0x021D6788 thumb ov175
 *   func_021D679C 0x021D679C thumb ov175
 *   func_021D63DC 0x021D63DC thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D61F0 0x021D61F0 thumb ov175
 *   func_021D4608 0x021D4608 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021D5908 0x021D5908 thumb ov175
 *   func_021D61CC 0x021D61CC thumb ov175
 */
typedef unsigned int u32;
extern void func_021E8738(int *, int, int, int);
extern int func_021E8844(const int *);
extern void func_021E8AA0(int *, int);
extern void func_021D62A4(char *, u32);
extern unsigned long func_021D63B0(char *);
extern void func_021D6788(char *, void *);
extern unsigned long func_021D679C(char *);
extern void func_021D63DC(char *);
extern int func_021D9F04(char *, void *, void *);
typedef unsigned char  u8;
extern void func_021D61F0(u32 sys, int *state, char *p);
extern void func_021D4608(u32 sys, int *state, u32 *p);
extern void func_021D61A4(void *obj, int unused, u8 *p);
extern void func_021D5908(unsigned sys, int *state, char *p);
extern void func_021D61CC(void *, unsigned **, char *);
void func_021D57BC(unsigned sys, int *state, int *p)
{
    unsigned long r;
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 26, 1);
        func_021D62A4((char *)p, 1);
        *state = 1;
        break;
    case 1:
        if (func_021D63B0((char *)p)) *state = 2;
        break;
    case 2:
        if (func_021E8844((int *)p[9])) *state = 3;
        break;
    case 3:
        func_021E8738((int *)p[9], p[4], 24, 2);
        *state = 4;
        break;
    case 4:
        func_021D6788((char *)p, func_021D61F0);
        *state = 5;
        switch (func_021D9F04((char *)p[12], 0, 0)) {
        case 1:
            func_021D63DC((char *)p);
            func_021E8AA0((int *)sys, (int)func_021D4608);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D61A4);
            break;
        }
        break;
    case 5:
        r = func_021D679C((char *)p);
        if (r == 0) func_021E8AA0((int *)sys, (int)func_021D5908);
        else if (r == 1) *state = 6;
        else if (r == 3) func_021E8AA0((int *)sys, (int)func_021D61A4);
        if (r != 0xffff) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1:
                func_021D63DC((char *)p);
                func_021E8AA0((int *)sys, (int)func_021D4608);
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                break;
            }
        }
        break;
    case 6:
        func_021E8738((int *)p[9], p[4], 120, 1);
        *state = 7;
        break;
    case 7:
        if (func_021E8844((int *)p[9])) func_021E8AA0((int *)sys, (int)func_021D61CC);
        break;
    }
}
