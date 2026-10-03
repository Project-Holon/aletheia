/*
 * function: func_021D495C
 * address: 0x021D495C
 * packet: pkt_ov175_021D495C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021DB3A4 0x021DB3A4 thumb ov175
 *   func_021DB478 0x021DB478 thumb ov175
 *   func_021D646C 0x021D646C thumb ov175
 *   func_021D6724 0x021D6724 thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D63DC 0x021D63DC thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D4608 0x021D4608 thumb ov175
 *   func_021D61A4 0x021D61A4 thumb ov175
 *   func_021DC194 0x021DC194 thumb ov175
 *   func_021DBFA4 0x021DBFA4 thumb ov175
 *   func_021DBFB4 0x021DBFB4 thumb ov175
 *   func_021D63BC 0x021D63BC thumb ov175
 *   func_021D639C 0x021D639C thumb ov175
 *   func_021D62A4 0x021D62A4 thumb ov175
 *   func_021D63B0 0x021D63B0 thumb ov175
 *   func_021D4B3C 0x021D4B3C thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 */
typedef unsigned int u32;
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(u32, u32);
extern void func_021DB3A4(char *, u32, int, u32);
extern int func_021DB478(char *);
extern int func_021D646C(u32, u32, u32 *);
extern void func_021D6724(u32 *, u32 *);
extern int func_021D9F04(char *, void *, void *);
extern void func_021D63DC(char *);
extern void func_021E8AA0(int *, int);
extern void func_021D4608(void);
extern void func_021D61A4(void);
extern u32 func_021DC194(char *);
extern void func_021DBFA4(char *);
extern int func_021DBFB4(char *);
extern u32 func_021D63BC(char *);
extern void func_021D639C(char *);
extern void func_021D62A4(char *, u32);
extern u32 func_021D63B0(char *);
extern void func_021D4B3C(void);
extern int func_021E8844(const int *);
extern void func_021E8AB8(u32);
void func_021D495C(u32 sys, int *state, u32 *p)
{
    u32 *ctx = (u32 *)p[16];
    int result;
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 24, 2);
        func_021E8AB4(sys, 1); *state = 11; break;
    case 1:
        if (*(u32 *)ctx[8] == 0) {
            func_021DB3A4((char *)p[12], -1, 0, ctx[14]);
            *state = 2;
        }
        break;
    case 2:
        result = func_021DB478((char *)p[12]);
        if (result == 1) {
            *(u32 *)((u32 *)p[16])[8] = 1800;
            p[60] = func_021D646C(ctx[4], ((u32 *)ctx[2])[1], p);
            func_021D6724((u32 *)ctx[5], p);
            *(u32 *)((u32 *)p[16])[10] = ((u32 *)((u32 *)p[16])[14])[21];
            *state = 3;
        }
        if (result != 0) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1:
                func_021D63DC((char *)p);
                func_021E8AA0((int *)sys, (int)func_021D4608);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            }
        }
        break;
    case 3:
        if (func_021DC194((char *)p[12]) == 0) {
            func_021DBFA4((char *)p[12]); *state = 4;
        } else *state = 5;
        break;
    case 4:
        result = func_021DBFB4((char *)p[12]);
        if (result == 1) *state = 1;
        if (result != 0) {
            switch (func_021D9F04((char *)p[12], 0, 0)) {
            case 1:
                func_021D63DC((char *)p);
                func_021E8AA0((int *)sys, (int)func_021D4608);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D61A4);
                *(u32 *)((u32 *)p[16])[8] = 1800;
                break;
            }
        }
        break;
    case 5:
        if (p[6] == 0) *state = 8;
        else if (p[60]) *state = 6;
        else *state = 10;
        p[60] = 0;
        break;
    case 6: *state = 7; break;
    case 7:
        if (func_021D63BC((char *)p)) {
            func_021D639C((char *)p); *state = 8;
        }
        break;
    case 8: func_021D62A4((char *)p, 0); *state = 9; break;
    case 9: if (func_021D63B0((char *)p)) *state = 10; break;
    case 10: func_021E8AA0((int *)sys, (int)func_021D4B3C); break;
    case 11: if (func_021E8844((int *)p[9])) func_021E8AB8(sys); break;
    }
}
