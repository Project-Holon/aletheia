/*
 * function: func_021D4608
 * address: 0x021D4608
 * packet: pkt_ov175_021D4608
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021D6550 0x021D6550 thumb ov175
 *   func_021D65DC 0x021D65DC thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D57BC 0x021D57BC thumb ov175
 *   func_021D4730 0x021D4730 thumb ov175
 *   func_021D61CC 0x021D61CC thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 */
typedef unsigned int u32;
extern void func_021E7E0C(void **, int);
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(u32, u32);
extern void func_021D6550(u32 *, int);
extern int func_021D65DC(char *);
extern void func_021D65C8(char *);
extern void func_021E8AA0(int *, int);
extern void func_021D57BC(void);
extern void func_021D4730(void);
extern void func_021D61CC(void);
extern int func_021E8844(const int *);
extern void func_021E8AB8(u32);
void func_021D4608(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0: func_021E7E0C((void **)p[8], 0); *state = 1; break;
    case 1:
        func_021E8738((int *)p[9], p[4], 25, 1);
        *state = 7; func_021E8AB4(sys, 2); break;
    case 2: func_021D6550(p, 1); *state = 3; break;
    case 3:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: ctx[0] = 1; func_021E8AA0((int *)sys, (int)func_021D57BC); break;
            case 1: ctx[0] = 0; func_021E8AA0((int *)sys, (int)func_021D4730); break;
            case 2: ctx[0] = 3; *state = 4; break;
            }
        }
        break;
    case 4:
        func_021E8738((int *)p[9], p[4], 30, 1);
        *state = 7; func_021E8AB4(sys, 5); break;
    case 5: func_021D6550(p, 0); *state = 6; break;
    case 6:
        result = func_021D65DC((char *)p);
        if (result != -1) {
            func_021D65C8((char *)p);
            switch (result) {
            case 0: ctx[1] = 0; func_021E8AA0((int *)sys, (int)func_021D61CC); break;
            case 1: *state = 1; break;
            }
        }
        break;
    case 7: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}
