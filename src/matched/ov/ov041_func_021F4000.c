/*
 * function: func_021F4000
 * address:  0x021F4000
 * packet:   pkt_ov041_021F4000
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Extent after the 0x80-byte function and pool is rodata, not a follower.
 * symbols:
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a, b, c; } Vec3;
extern void func_0218ECE4(u8 *a, Vec3 *out);
extern void func_0218ECF4(u8 *a, const Vec3 *p);

void func_021F4000(u8 *p, u8 *obj)
{
    int step;
    Vec3 v;

    if (*(int *)p != 0) {
        p[15]++;
        if (p[12] == 0) {
            if (p[13] % 2 == 0) {
                step = 0x8000;
            } else {
                step = -0x8000;
                p[14]++;
            }
            p[13] = (p[13] + 1) % 2;
            func_0218ECE4(obj, &v);
            v.b += step;
            func_0218ECF4(obj, &v);
            p[12] = 1;
        } else {
            p[12]--;
        }
        if (p[14] >= 2) {
            *(int *)p = 0;
            *(int *)(p + 4) = 1;
        }
    }
}
