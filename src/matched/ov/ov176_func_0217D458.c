/*
 * function: func_0217D458
 * address: 0x0217D458
 * packet: pkt_ov176_0217D458
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217D4FC 0x0217D4FC thumb ov176
 *   func_0217D730 0x0217D730 thumb ov176
 *   func_0217D964 0x0217D964 thumb ov176
 *   func_0217DA38 0x0217DA38 thumb ov176
 *   func_0217DB0C 0x0217DB0C thumb ov176
 *   func_0217DBE0 0x0217DBE0 thumb ov176
 */
struct Big;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *sys);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec160;
struct Reg2;
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern void func_021E8AA0(int *p, int v);
extern void func_0217D4FC(int *a, int *state, int *p);
extern void func_0217D730(int *a, int *state, int *p);
extern void func_0217D964(int *a, int *state, int *p);
extern void func_0217DA38(int sys, int *state, int *p);
extern void func_0217DB0C(int sys, int *state, int *p);
extern void func_0217DBE0(int a, int *state, int *p);
void func_0217D458(int a, int unused, char *p)
{
    void *m;
    unsigned x;
    unsigned y;
    m = func_0200B1D4(func_0200B358(func_02012EBC(*(void **)(p + 0x30))), *(int *)(p + 0x14));
    x = func_0200B078(m, 2);
    y = func_0200B078(m, 10);
    if (x && y == 1) {
        func_021E8AA0((int *)a, (int)func_0217D4FC);
        return;
    }
    if (x && y == 2) {
        func_021E8AA0((int *)a, (int)func_0217D730);
        return;
    }
    if (x && y == 3) {
        func_021E8AA0((int *)a, (int)func_0217D964);
        return;
    }
    if (x && y == 4) {
        func_021E8AA0((int *)a, (int)func_0217DA38);
        return;
    }
    if (x && y == 5) {
        func_021E8AA0((int *)a, (int)func_0217DB0C);
        return;
    }
    func_021E8AA0((int *)a, (int)func_0217DBE0);
}
