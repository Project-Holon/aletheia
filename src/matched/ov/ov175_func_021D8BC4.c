/*
 * function: func_021D8BC4
 * address: 0x021D8BC4
 * packet: pkt_ov175_021D8BC4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D9D50 0x021D9D50 thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D9A1C 0x021D9A1C thumb ov175
 *   func_021D9A30 0x021D9A30 thumb ov175
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_021D8EC8 0x021D8EC8 thumb ov175
 *   func_021D8CF0 0x021D8CF0 thumb ov175
 *   func_021D9064 0x021D9064 thumb ov175
 *   func_021D9090 0x021D9090 thumb ov175
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern void func_021E8AA0(int *, int);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
extern int func_021D9D50(char *obj, u32 *rec);
extern int func_021D9F04(char *, void *, void *);
extern void func_021D9A1C(char *, void *);
extern u32 func_021D9A30(char *);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern void func_021D8EC8(u32 sys, int *state, char *p);
extern void func_021D8CF0(u32 sys, int *state, char *p);
extern void func_021D9064(void *obj, int unused, u8 *p);
extern void func_021D9090(u32 sys, int *state, char *p);
void func_021D8BC4(int *a, int *state, char *ctx)
{
    int r;
    u32 q;
    char *sub = *(char **)(ctx + 0x104);
    switch (*state) {
    case 0:
        func_021E8738(*(int **)(ctx + 0x2C), *(int *)(ctx + 0x14), 0x28, 2);
        *state = 5;
        func_021E8AB4((unsigned)a, 1);
        return;
    case 1:
        func_021D9D50(ctx, *(void **)(sub + 0x34));
        GAME_DATA_SaveStart(**(int **)(sub + 8));
        *state = 2;
        return;
    case 2:
        r = GAME_DATA_SaveMain(**(u8 ***)(sub + 8));
        if (r == 2) {
            *state = 3;
            return;
        }
        if (r == 3)
            func_021E8AA0(a, (int)func_021D8EC8);
        return;
    case 3:
        switch (func_021D9F04(*(char **)(ctx + 0x34), 0, 0)) {
        case 1:
            func_021E8AA0(a, (int)func_021D8CF0);
            return;
        case 2:
            func_021E8AA0(a, (int)func_021D9064);
            return;
        case 0:
            func_021D9A1C(ctx, (void *)func_021D9090);
            *state = 4;
            return;
        }
        return;
    case 4:
        q = func_021D9A30(ctx);
        if (q == 0)
            func_021E8AA0(a, (int)func_021D8CF0);
        else if (q - 1 <= 1)
            func_021E8AA0(a, (int)func_021D8EC8);
        else if (q == 3)
            func_021E8AA0(a, (int)func_021D9064);
        switch (func_021D9F04(*(char **)(ctx + 0x34), 0, 0)) {
        case 1:
            func_021E8AA0(a, (int)func_021D8CF0);
            return;
        case 2:
            func_021E8AA0(a, (int)func_021D9064);
            return;
        }
        return;
    case 5:
        if (func_021E8844(*(int **)(ctx + 0x2C)))
            func_021E8AB8((unsigned)a);
        return;
    }
}
