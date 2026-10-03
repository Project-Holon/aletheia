/*
 * unit: yes
 * function: func_021D8FA8, func_021D905C
 * address: 0x021D8FA8
 * packet: pkt_ov175_021D8FA8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021D905C tail-call stub included; function_starts seed 021D905C.
 * symbols:
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D9A1C 0x021D9A1C thumb ov175
 *   func_021D9A30 0x021D9A30 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D9064 0x021D9064 thumb ov175
 *   func_021D9090 0x021D9090 thumb ov175
 *   func_021D8EC8 0x021D8EC8 thumb ov175
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
typedef unsigned long u32;
extern int func_021D9F04(void *, int, int);
extern void func_021D9A1C(char *, void *);
extern u32 func_021D9A30(char *);
extern void func_021E8AA0(u32, void *);
extern int func_021E8844(u32);
extern void func_021E8AB8(u32);
extern void func_021E8AA8(int a);
extern void func_021D9064(void), func_021D9090(void), func_021D8EC8(void);
void func_021D8FA8(u32 sys, int *state, char *ctx)
{
    int result;
    switch (*state) {
    case 0:
        result = func_021D9F04(*(void **)(ctx + 0x34), 1, 0);
        switch (result) {
        case 1: case 2:
            func_021E8AA0(sys, func_021D9064);
            break;
        case 0:
            func_021D9A1C(ctx, func_021D9090);
            *state = 1;
            break;
        }
        break;
    case 1:
        result = func_021D9A30(ctx);
        if (result != 0xffff) *state = 2;
        if (result == 3) func_021E8AA0(sys, func_021D9064);
        result = func_021D9F04(*(void **)(ctx + 0x34), 1, 0);
        switch (result) {
        case 1: case 2: func_021E8AA0(sys, func_021D9064); break;
        }
        break;
    case 2: func_021E8AA0(sys, func_021D8EC8); break;
    case 3:
        if (func_021E8844(*(u32 *)(ctx + 0x2c))) func_021E8AB8(sys);
        break;
    }
}
void func_021D905C(u32 sys)
{
    func_021E8AA8(sys);
}
