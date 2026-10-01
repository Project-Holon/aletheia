/*
 * function: func_021F660C
 * address: 0x021F660C
 * packet: pkt_ov112_021F660C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 310-byte code; 021F6742 is two zero alignment bytes.
 * lever: a named unsigned 64-bit sum pins carry accumulation before translation.
 * semantics: signed 32-bit products fit s64; u64 additions wrap like ADDS/ADCS.
 * symbols:
 *   _ll_mul 0x0209C054 arm
 */
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
void func_021F660C(const int *p, const int *m, u32 *out, u32 *w)
{
    s64 y = p[1];
    s64 x = p[0];
    s64 z = p[2];
    u64 sum;
    sum = (u64)(x * m[0]) + (u64)(y * m[4]) + (u64)(z * m[8]);
    out[0] = (u32)(sum >> 12) + (u32)m[12];
    sum = (u64)(x * m[1]) + (u64)(y * m[5]) + (u64)(z * m[9]);
    out[1] = (u32)(sum >> 12) + (u32)m[13];
    sum = (u64)(x * m[2]) + (u64)(y * m[6]) + (u64)(z * m[10]);
    out[2] = (u32)(sum >> 12) + (u32)m[14];
    sum = (u64)(x * m[3]) + (u64)(y * m[7]) + (u64)(z * m[11]);
    *w = (u32)(sum >> 12) + (u32)m[15];
}
