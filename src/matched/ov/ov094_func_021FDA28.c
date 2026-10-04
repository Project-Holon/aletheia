/*
 * function: func_021FDA28
 * address: 0x021FDA28
 * packet: pkt_ov094_021FDA28
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02051A34 0x02051A34 arm
 *   func_02051838 0x02051838 arm
 *   func_021FE1B8 0x021FE1B8 thumb ov094
 *   _ll_mul 0x0209C054 arm
 *   d_020A1B38 0x020A1B38 data a2
 */
typedef signed short s16;
typedef unsigned short u16;
typedef struct { int x, y, z; } VecFx32;
extern const s16 d_020A1B38[];
extern int func_02051A34(void *p);
extern void func_02051838(void *p, const VecFx32 *v);
extern void func_021FE1B8(VecFx32 *v, const VecFx32 *ofs);
#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))
void func_021FDA28(void *p, int active)
{
    int *s;
    VecFx32 v;
    s = (int *)func_02051A34(p);
    if (active == 0)
        return;
    if (s[13] == 0) {
        if (s[10] == 0) {
            s[10] = s[11];
            if (s[0] & 1)
                s[6] -= s[7];
            else
                s[6] += s[7];
            s[6] = (u16)s[6];
            v.x = d_020A1B38[(s[6] >> 4) * 2];
            v.x = MUL(v.x, s[4]);
            v.x += s[1];
            v.y = s[2];
            v.z = d_020A1B38[(s[6] >> 4) * 2 + 1];
            v.z = MUL(v.z, s[5]);
            v.z += s[3];
            if (s[15] != 0)
                func_021FE1B8(&v, 0);
            func_02051838(p, &v);
            if (s[8] != 0) {
                s[8]--;
            } else {
                s[8] = s[9];
                s[13] = s[14];
            }
        } else {
            s[10]--;
        }
    } else {
        s[13]--;
    }
}
