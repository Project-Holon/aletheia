/*
 * function: func_021FAF24
 * address: 0x021FAF24
 * packet: pkt_ov186_021FAF24
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D18 0x02200D18 data a1
 */
extern int func_021FB7B0(void *p, int i);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_02200D18[];
int func_021FAF24(char *ctx, int kind)
{
    int result;
    switch (kind) {
    case 0: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 5); break;
    case 1: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 6); break;
    case 2: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 7); break;
    case 5: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 9); break;
    case 6: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 10); break;
    case 3: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 8); break;
    case 4: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 2); break;
    case 7: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 11); break;
    case 8: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 0); break;
    case 9: result = func_021FB7B0((void *)(*(int *)(ctx + 0xc)), 1); break;
    default: result = 0; func_02034714(d_02200D18, 0, d_02200D18); break;
    }
    return result;
}
