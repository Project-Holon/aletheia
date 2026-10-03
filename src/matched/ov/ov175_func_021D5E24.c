/*
 * function: func_021D5E24
 * address: 0x021D5E24
 * packet: pkt_ov175_021D5E24
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: source arm order is 0,3,1,2,4..11; numeric ordering differs
 * by 119 concrete bytes although the compiled size remains 476.
 * DC2C0's return r0 is tested here despite its legacy void declaration.
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D6000 0x021D6000 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021DC2C0 0x021DC2C0 thumb ov175
 *   func_021DC2D8 0x021DC2D8 thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_021E8AC0 0x021E8AC0 thumb ov177
 *   func_021DA384 0x021DA384 thumb ov175
 *   func_021DA390 0x021DA390 thumb ov175
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
typedef unsigned int u32;
typedef unsigned long ul;
typedef unsigned char u8;
struct Big;
struct L0200ED54;
extern void func_021E8AA0(int *, int);
extern void func_021D6000(void);
extern void func_021D61A4(void);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
extern int func_021DC2C0(ul, void *);
extern ul func_021DC2D8(char *, ul *);
extern int func_021D9F04(char *, void *, void *);
extern void *func_02012EBC(struct Big *);
extern void *func_0200ED48(void *);
extern u32 func_02008530(void *);
extern void func_0200ED54(struct L0200ED54 *, u32);
extern void func_021E8AC0(int, int);
extern void func_021DA384(char *);
extern int func_021DA390(char *);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void func_021E8AA8(int);
#define P(k) (*(int *)(p + (k)))
#define TIMER (*(u32 *)(p + 0xe0))
void func_021D5E24(unsigned sys, int *state, char *p)
{
    char *q = (char *)P(0x40);
    void *list;
    switch (*state) {
    case 0:
        if (*(int *)(q + 12) == 2) func_021E8AA0((int *)sys, (int)func_021D6000);
        else *state = 3;
        break;
    case 3:
        func_021E8738((int *)P(0x24), P(0x10), 43, 2);
        *state = 11;
        func_021E8AB4(sys, 1);
        TIMER = 0;
        break;
    case 1:
        if (func_021DC2C0(P(0x30), *(char **)(q + 0x2c) + 0x10)) *state = 2;
        break;
    case 2:
        if (func_021DC2D8((char *)P(0x30), (ul *)(*(char **)(q + 0x2c) + 0x14))) *state = 4;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 4:
        list = func_0200ED48(func_02012EBC((struct Big *)**(int **)(q + 8)));
        func_0200ED54(list, func_02008530(*(void **)(q + 0x18)));
        func_021E8AC0(**(int **)(q + 8), **(int **)(q + 0x2c));
        func_021DA384((char *)P(0x30));
        *state = 5;
        break;
    case 5:
        TIMER++;
        if (func_021DA390((char *)P(0x30))) *state = 6;
        switch (func_021D9F04((char *)P(0x30), 0, (void *)1)) {
        case 1: case 4: TIMER = 0; *state = 7; break;
        case 2: TIMER = 0; func_021E8AA0((int *)sys, (int)func_021D61A4); break;
        }
        break;
    case 6:
        if (TIMER++ > 30) { TIMER = 0; *state = 7; }
        break;
    case 7:
        *state = 8;
        break;
    case 8:
        func_021E8738((int *)P(0x24), P(0x10), 40, 2);
        *state = 11;
        func_021E8AB4(sys, 9);
        break;
    case 9:
        func_02012DAC(**(int **)(q + 8));
        *state = 10;
        break;
    case 10:
        switch (func_02012DD0((u8 *)**(int **)(q + 8))) {
        case 0: case 1: break;
        case 2: case 3: *(int *)(q + 4) = 2; func_021E8AA8(sys); break;
        }
        break;
    case 11:
        if (func_021E8844((int *)P(0x24))) func_021E8AB8(sys);
        break;
    }
}
