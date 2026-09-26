/*
 * function: func_021BE7A8
 * address:  0x021BE7A8
 * packet:   pkt_ov204_021BE7A8
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02006238  0x02006238  thumb
 *   func_02006A64  0x02006A64  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_021BF744  0x021BF744  thumb ov204
 *   func_021BF864  0x021BF864  thumb ov204
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020061E4(u32);
extern int  func_02006238(void);
extern void func_02006A64(u32);
extern int  func_02006BD0(u32);
extern void func_021BF744(u32, int, int, int);
extern int  func_021BF864(u32, u32, u32);

int func_021BE7A8(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (q[1] == 3) {
            q[1] = 0;
            (*q)++;
        } else {
            q[1] = q[1] + 1;
        }
        break;
    case 1:
        if (func_021BF864(*(u32 *)(p + 8), 0x1000, 0xFFFF4800) == 1) {
            func_020061E4(0x7F5);
            (*q)++;
        }
        break;
    case 2:
        if (func_02006238() == 0) {
            func_021BF744(*(u32 *)(p + 8), 1, 0, 1);
            func_02006A64(*(u32 *)(*(u32 *)(p + 4) + 0x10));
            (*q)++;
        }
        break;
    case 3:
        if (func_02006BD0(*(u32 *)(*(u32 *)(p + 4) + 0x10)) == 0) {
            *q = 0;
            return 1;
        }
        break;
    }
    return 0;
}
