/*
 * function: func_021FB8CC
 * address: 0x021FB8CC
 * packet: pkt_ov132_021FB8CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021FAEE8 0x021FAEE8 thumb ov132
 *   func_021F8084 0x021F8084 thumb ov112
 *   func_021FADF8 0x021FADF8 thumb ov132
 *   _u32_div_f 0x0209C2B0 arm
 *   _ll_mul 0x0209C054 arm
 *   d_020A1B38 0x020A1B38 data a2
 */
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
extern void *func_021F9DA0(char *p);
extern int func_021FAEE8(char *p);
extern void func_021F8084(void *, void *, const Vec *);
extern void func_021FADF8(char *p, char *q);
extern const s16 d_020A1B38[];
void func_021FB8CC(int unused, char *p)
{
    void *ctx;
    ctx = func_021F9DA0(*(void **)p);
    if (func_021FAEE8(p) == 2) {
        Vec zero = { 0, 0, 0 };
        func_021F8084(ctx, *(void **)(p + 0x10), &zero);
        func_021FADF8(*(void **)(p + 0x18), *(void **)(p + 0x1C));
        return;
    }
    else {
        Vec v;
        int sine;
        v.x = 0;
        sine = d_020A1B38[((int)(((u32)*(int *)(p + 4) << 15) / (u32)*(int *)(p + 8)) >> 4) * 2];
        v.y = -(int)(((long long)sine * *(int *)(p + 0x14) + 0x800) >> 12);
        v.z = 0;
        func_021F8084(ctx, *(void **)(p + 0x10), &v);
    }
}
