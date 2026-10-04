/*
 * function: func_021C4838
 * address:  0x021C4838
 * packet:   pkt_ov093_021C4838
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C48E0  0x021C48E0  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C4910  0x021C4910  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 *   func_021C48F0  0x021C48F0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C4F64  0x021C4F64  thumb  ov093
 *   func_021C4900  0x021C4900  thumb  ov093
 *   func_021C5200  0x021C5200  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021C48E0(u8 *a);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C4910(u8 *p, u32 a, int k);
extern void func_021CC95C(void *lock, u32 v, int line);
extern int func_021BC2B0(u8 *p);
extern u8 *func_021C48F0(u8 *a);
extern u8 func_021D5440(u8 *p);
extern void func_021C4F64(u8 *p, u8 *q);
extern u8 *func_021C4900(u8 *a);
extern int func_021C5200(u8 *p);

void func_021C4838(u8 *p, u8 *a, u8 *b)
{
    u32 s;
    u8 *q;
    func_021C48E0(a);
    s = func_021CC8D8(p + 0x1D74, 9644);
    func_021C4910(p, 0x1f, (int)b);
    func_021CC95C(p + 0x1D74, s, 9646);
    if (func_021BC2B0(p) == 0) {
        q = func_021C48F0(a);
        if (q != 0) {
            do {
                s = func_021CC8D8(p + 0x1D74, 9652);
                func_021C4910(p, func_021D5440(q), (int)b);
                func_021CC95C(p + 0x1D74, s, 9654);
                func_021C4F64(p, q);
                if (func_021BC2B0(p) != 0) {
                    break;
                }
                q = func_021C4900(a);
            } while (q != 0);
        }
    }
    func_021C5200(p);
}
