/*
 * function: FIELD_WFBC_BLOCK_BuildGrid
 * address:  0x02194128
 * packet:   pkt_ov021_02194128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   _ull_mul       0x0209C054  arm
 *   FIELD_WFBC_BLOCK_SetCell  0x02194014  thumb  ov021
 *
 * Seeds a NitroSDK MATHRandContext32 at the head of e (MATH_InitRand32
 * inline) and fills an 8x8 grid of 4-byte cells through FIELD_WFBC_BLOCK_SetCell.
 * Spill-slot order (u64 max temp at the top, then row, j, d, k) needs the
 * explicit locals in this declaration order; the index `r += k * 8` must be
 * folded into r before the call or the tail's loads schedule differently.
 * Addresses are Black-image addresses.
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}

static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max) {
        return (u32)(((context->x >> 32) * max) >> 32);
    } else {
        return (u32)(context->x >> 32);
    }
}

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
    u8 b;
} P;

typedef struct {
    P cells[8][8];
    u32 vals[1][16];
} T;

typedef struct {
    MATHRandContext32 rand;
    u16 max;
    u16 base;
    int f1c;
    u32 seed;
} E;

extern void FIELD_WFBC_BLOCK_SetCell(u8 *out, int i, int j, P t, u16 c);

void FIELD_WFBC_BLOCK_BuildGrid(E *e, T *tbl, u8 *out)
{
    P t;
    u32 mx;
    P *row;
    int j;
    u8 d;
    u8 k;
    int i;
    int r;
    int dx;
    int dy;

    MATH_InitRand32(&e->rand, e->seed);
    for (j = 0; j < 8; j++) {
        row = tbl->cells[j];
        for (i = 0; i < 8; i++) {
            t = row[i];
            d = t.b;
            if (d == 0xFF) {
                continue;
            }
            if (t.lo != 0 || t.hi != 0) {
                FIELD_WFBC_BLOCK_SetCell(out, i, j, t, *(u16 *)(out + (j - t.hi) * 0x20 + (i - t.lo) * 4 + 2));
            } else {
                dx = i - t.lo;
                dy = j - t.hi;
                k = (u8)((u8)((u8)e->base + (u8)(dx + dy)) / (u32)((dx + 3) + (dy + 1))) % 2;
                r = (e->f1c * 8) / 10;
                mx = e->max;
                r += MATH_Rand32(&e->rand, mx);
                if (r >= 8) {
                    r = 7;
                }
                r += k * 8;
                FIELD_WFBC_BLOCK_SetCell(out, i, j, t, tbl->vals[d][r]);
            }
        }
    }
}
