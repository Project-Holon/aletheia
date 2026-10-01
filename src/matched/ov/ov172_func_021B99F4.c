/*
 * function: func_021B99F4
 * address: 0x021B99F4
 * packet: pkt_ov172_021B99F4
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: Byte at q+15 re-read at 021B9A46 following store at 021B9A44; q+13 re-read at 021B9A7A following store at 021B9A78.
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0200616C 0x0200616C thumb
 *   func_02006268 0x02006268 thumb
 *   d_021C6F8F 0x021C6F8F data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern int func_02035C08(const void *);
extern int func_02035BA4(const void *);
extern void func_0204B878(struct Obj *, u16);
extern void func_0200616C(void *, int);
extern void func_02006268(int, int, int, int);
extern const u8 d_021C6F8F[];
void func_021B99F4(void *unused, u8 *q)
{
    u32 a = func_02035C08(d_021C6F8F);
    u32 b = func_02035BA4(d_021C6F8F);
    int flag = -1;
    int changed = 0;
    if (a != -1) {
        q[15] = 0;
        if (a <= 1) { q[14] = 0; flag = 0; }
        else { q[14] = 1; flag = 1; }
    } else if (b != -1) {
        int agree = 0;
        if (b <= 1) { if (q[14] == 0) agree = 1; }
        else { if (q[14] == 1) agree = 1; }
        if (agree == 1) {
            q[15]++;
            if (*(volatile u8 *)(q + 15) >= 25) {
                flag = q[14];
                q[15] = 10;
            }
        } else q[14] = 255;
    } else q[14] = 255;
    if (flag == 0) {
        if (q[13] < 8) {
            changed = 1; q[13]++;
            func_0204B878(*(struct Obj **)(q + 144), (u16)(*(volatile u8 *)(q + 13) + 25));
        }
    } else if (flag == 1) {
        if (q[13] > 0) {
            changed = 1; q[13]--;
            func_0204B878(*(struct Obj **)(q + 144), (u16)(*(volatile u8 *)(q + 13) + 25));
        }
    }
    if (changed == 1) {
        int angle;
        angle = (q[13] - 4) * 64;
        func_0200616C((void *)1644, 1);
        func_02006268(1, -1, angle, -1);
    }
}
