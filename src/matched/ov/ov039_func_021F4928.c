/*
 * function: GIMMICK39_SampleJointTrack
 * address:  0x021F4928
 * packet:   pkt_ov039_021F4928
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An animation-curve sampler (step-1/2/4 keys, fx16 or fx32 array).  The
 * 1:3 weight's own idx_sub variable puts idx in r2 on every path; the fx16
 * 1:3 sum needs v = v + (v << 1) as its own statement or the second load
 * is hoisted; the interpolation reads spelled *(p + idx) / *(p + idx + 1)
 * share p + idx after the first load, where p[idx] / p[idx + 1] recomputes
 * (idx + 1) * 2 and a pointer local p + idx hoists the add above the load.
 *
 * symbols:
 *   _ll_mul  0x0209C054  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
typedef long long s64;

void GIMMICK39_SampleJointTrack(int *out, int frame, const u32 *data, const u8 *base)
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
