/*
 * file:     unit_021F36C0_p05.c
 * unit:     yes
 * function: func_021F4864, func_021F4894, func_021F48C0, func_021F4928
 * address:  0x021F4864
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F4D78 0x021F4D78 data a4
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 *   d_021F4BE4 0x021F4BE4 data a2
 *   _ll_mul  0x0209C054  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef long long s64;

extern int func_021F3DE4(void *p, u16 delta, u16 i);
int func_021F4864(u32 a, u32 b, u8 *out);
int func_021F4894(void *p, int i, u8 j);
void func_021F48C0(u8 *a, int idx, int x, int *out);
void func_021F4928(int *out, int frame, const u32 *data, const u8 *base);
extern const u32 d_021F4D78[][2];
extern const u16 d_021F4BE4[];

int func_021F4864(u32 a, u32 b, u8 *out) { u8 i; for (i = 0; i < 2; i++) { if (d_021F4D78[a][i] == b) { *out = i; return 1; } } return 0; }

int func_021F4894(void *p, int i, u8 j) { if (func_021F3DE4(p, (u8)i, j + 1) <= (int)(d_021F4BE4[i] << 12)) return 1; return 0; }


void func_021F48C0(u8 *a, int idx, int x, int *out)
{
    u16 off;
    u32 flags;
    u8 *p;
    int c;
    int b;
    int d;

    off = *(u16 *)(a + idx * 2 + 0x14);
    flags = *(u32 *)(a + off);
    p = a + off + 4;
    if (flags & 6) {
        return;
    }
    if (!(flags & 8)) {
        func_021F4928(&c, x, (const u32 *)p, a);
        p += 8;
        out[0] = c;
    }
    if (!(flags & 0x10)) {
        func_021F4928(&b, x, (const u32 *)p, a);
        p += 8;
        out[1] = b;
    }
    if (flags & 0x20) {
        return;
    }
    func_021F4928(&d, x, (const u32 *)p, a);
    out[2] = d;
}


/*
 * An animation-curve sampler (step-1/2/4 keys, fx16 or fx32 array).  The
 * 1:3 weight's own idx_sub variable puts idx in r2 on every path; the fx16
 * 1:3 sum needs v = v + (v << 1) as its own statement or the second load
 * is hoisted; the interpolation reads spelled *(p + idx) / *(p + idx + 1)
 * share p + idx after the first load, where p[idx] / p[idx + 1] recomputes
 * (idx + 1) * 2 and a pointer local p + idx hoists the add above the load.
 */
void func_021F4928(int *out, int frame, const u32 *data, const u8 *base)
{
    const u8 *arr;
    u32 f;
    u32 info;
    u32 last;
    u32 idx;

    f = frame >> 12;
    arr = base + data[1];
    info = data[0];
    if (!(info & 0xC0000000)) {
        idx = f;
        goto plain;
    }
    last = (info & 0x1FFF0000) >> 16;
    if (info & 0x40000000) {
        if (f & 1) {
            if (f > last) {
                idx = (last >> 1) + 1;
                goto plain;
            } else {
                idx = f >> 1;
                goto interp2;
            }
        } else {
            idx = f >> 1;
            goto plain;
        }
    } else {
        if (f & 3) {
            if (f > last) {
                idx = (last >> 2) + (f & 3);
                goto plain;
            }
            if (f & 1) {
                int v;
                u32 idx_sub;
                if (f & 2) {
                    idx_sub = f >> 2;
                    idx = idx_sub + 1;
                } else {
                    idx = f >> 2;
                    idx_sub = idx + 1;
                }
                if (info & 0x20000000) {
                    const s16 *p16 = (const s16 *)arr;
                    v = p16[idx];
                    v = v + (v << 1);
                    *out = (v + p16[idx_sub]) >> 2;
                } else {
                    const int *p32 = (const int *)arr;
                    v = p32[idx];
                    *out = (int)(((s64)v * 3 + (s64)p32[idx_sub]) >> 2);
                }
                return;
            } else {
                idx = f >> 2;
                goto interp2;
            }
        } else {
            idx = f >> 2;
            goto plain;
        }
    }
interp2:
    if (info & 0x20000000) {
        const s16 *p16 = (const s16 *)arr;
        *out = (*(p16 + idx) + *(p16 + idx + 1)) >> 1;
    } else {
        const int *p32 = (const int *)arr;
        *out = (*(p32 + idx) >> 1) + (*(p32 + idx + 1) >> 1);
    }
    return;
plain:
    if (info & 0x20000000) {
        *out = ((const s16 *)arr)[idx];
    } else {
        *out = ((const int *)arr)[idx];
    }
}
