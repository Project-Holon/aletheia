/*
 * function: func_021B64E0
 * address:  0x021B64E0
 * packet:   pkt_021B64E0
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frame-paced step: accumulates OS_GetTick deltas in microseconds and
 * advances one 66,667 us (15 Hz) step at a time. The entry table must be
 * const: that is what lets the e->b load schedule ahead of the count store.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_021B669C  0x021B669C  thumb  ov179
 *   data_021B6A1C  0x021B6A1C  data  ov179
 *   _ull_mul       0x0209C054  arm
 *   _ll_udiv       0x0209C00C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct {
    u16 unk0;
    u16 count;
    int a;
    int b;
} Entry;

extern const Entry data_021B6A1C[];
extern u64 func_020870D0(void);
extern void func_0204047C(u8, u8);
extern void func_021B669C(int, int, int, int, int);

int func_021B64E0(char *p)
{
    const Entry *e = &data_021B6A1C[**(u16 **)p];

    if (*(u64 *)(p + 0x6040) == 0) {
        *(u64 *)(p + 0x6040) = func_020870D0();
    } else {
        u64 now = func_020870D0();
        *(u64 *)(p + 0x6048) += (now - *(u64 *)(p + 0x6040)) * 64000 / 33514;
        *(u64 *)(p + 0x6040) = now;
        if (*(u64 *)(p + 0x6048) < 66667)
            return 4;
        *(u64 *)(p + 0x6048) -= 66667;
    }

    switch (*(u8 *)(p + 0x603F)) {
    case 0:
        func_021B669C(*(int *)(p + 4), *(u16 *)(p + 0x603C), e->b, e->a, 0);
        (*(u16 *)(p + 0x603C))++;
        func_021B669C(*(int *)(p + 4), *(u16 *)(p + 0x603C), e->b, e->a, 1);
        (*(u16 *)(p + 0x603C))++;
        func_0204047C(2, 0);
        func_0204047C(3, 1);
        *(u8 *)(p + 0x603F) = 1;
        break;
    case 1:
        func_0204047C((*(u8 *)(p + 0x603E) ^ 1) + 2, 0);
        func_0204047C(*(u8 *)(p + 0x603E) + 2, 1);
        func_021B669C(*(int *)(p + 4), *(u16 *)(p + 0x603C), e->b, e->a, *(u8 *)(p + 0x603E));
        (*(u16 *)(p + 0x603C))++;
        if (*(u16 *)(p + 0x603C) >= e->count) {
            *(u8 *)(p + 0x603F) = 2;
        } else {
            *(u8 *)(p + 0x603E) ^= 1;
        }
        break;
    case 2:
        func_0204047C(*(u8 *)(p + 0x603E) + 2, 0);
        func_0204047C((*(u8 *)(p + 0x603E) ^ 1) + 2, 1);
        *(u8 *)(p + 0x603F) = 3;
        break;
    case 3:
        return 5;
    }
    return 4;
}
