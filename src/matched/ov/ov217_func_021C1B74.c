/*
 * function: func_021C1B74
 * address: 0x021C1B74
 * packet: pkt_ov217_021C1B74
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: the last block as a ternary on the float then one cast lets the ffix tail be shared;
 *   max kept in an int local loaded before min.
 * symbols:
 *   func_021C1B28 0x021C1B28 thumb ov217
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C77C arm
 *   _fsub 0x0209CB8C arm
 *   _fadd 0x0209C95C arm
 *   _fdiv 0x0209CE10 arm
 *   _fgr 0x0209BBB0 arm
 *   _ffix 0x0209C494 arm
 *   _f2d 0x0209BD38 arm
 *   _d2f 0x0209B64C arm
 *   cos 0x0209A390 arm
 *   sin 0x0209AA08 arm
 */
typedef unsigned char u8;
typedef signed short s16;
extern void func_021C1B28(u8 *, u8 *, u8 *);
extern double cos(double);
extern double sin(double);
struct Range { u8 max, min; };
void func_021C1B74(u8 *p, u8 *rec, s16 *out)
{
    struct Range r;
    int mx;
    float f1, ang, cs, sn, pz, cx, cy, cz;
    func_021C1B28(rec, &r.min, &r.max);
    mx = r.max;
    f1 = (float)(r.min + mx + 1);
    ang = 1.5707964f - 0.01f * (3.1415927f * f1);
    cs = 0.42f * (float)cos((double)ang);
    sn = 0.42f * (float)sin((double)ang);
    pz = (float)*(s16 *)(p + mx * 6 + 0x1be) / 4096.0f;
    cx = (float)*(s16 *)(p + 0x1b4) / 4096.0f;
    cy = (float)*(s16 *)(p + 0x1b6) / 4096.0f;
    cz = (float)*(s16 *)(p + 0x1b8) / 4096.0f;
    if (cx + cs > 0.0f) out[0] = (s16)(0.5f + 4096.0f * (cx + cs));
    else out[0] = (s16)(4096.0f * (cx + cs) - 0.5f);
    if (cy + sn > 0.0f) out[1] = (s16)(0.5f + 4096.0f * (cy + sn));
    else out[1] = (s16)(4096.0f * (cy + sn) - 0.5f);
    out[2] = (s16)((cz + pz > 0.0f) ? (0.5f + 4096.0f * (cz + pz)) : (4096.0f * (cz + pz) - 0.5f));
}
