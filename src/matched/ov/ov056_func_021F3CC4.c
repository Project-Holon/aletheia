/*
 * function: func_021F3CC4
 * address:  0x021F3CC4
 * packet:   pkt_ov056_021F3CC4
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_0216DC18  0x0216DC18  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

struct Actor;
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_0216E084(void *m, s16 x, s16 y, s16 z, u16 e);
extern void func_02164010(void *m);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_021A3044(void *p, const VecFx32 *v);
extern void func_0216DC18(void *m, u32 v);

void func_021F3CC4(u8 *p, int flag)
{
    VecFx32 v;

    if (flag) {
        *(int *)(p + 0x5c) = 1;
        func_0216DAC8(*(void **)(p + 0x68), 1);
        return;
    }
    *(int *)(p + 0x5c) = 0;
    func_0216DAC8(*(void **)(p + 0x68), 0);
    func_0216E084(*(void **)(p + 0x68), *(int *)(p + 0x6c), *(int *)(p + 0x70),
                  *(int *)(p + 0x74), *(u16 *)(p + 0x78));
    func_02164010(*(void **)(p + 0x68));
    func_0216D88C(*(void **)(p + 0x68), &v);
    func_021A3044(*(void **)(p + 0x64), &v);
    func_0216DC18(*(void **)(p + 0x68), 0);
}
