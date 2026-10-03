/*
 * function: func_021867C4
 * address:  0x021867C4
 * packet:   pkt_ov023_021867C4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203996C  0x0203996C  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_020399A8  0x020399A8  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern struct Entry *func_020399A8(void);

void func_021867C4(char *p)
{
    switch (*(int *)(p + 0x9270)) {
    case 0x2903:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2903, 1, (u32)(p + 0x9274)) != 0) {
            *(int *)(p + 0x9270) = 0;
        }
        break;
    case 0x2904:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2904, 0, 0) != 0) {
            *(int *)(p + 0x9270) = 0;
        }
        break;
    case 0x2905:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2905, 4, (u32)(p + 0x9278)) != 0) {
            *(int *)(p + 0x9270) = 0;
        }
        break;
    case 0x2906:
        break;
    case 0x2907:
        if (func_0203D3A8(func_020399A8(), 0x2907, 0, 0) != 0) {
            *(int *)(p + 0x9270) = 0;
        }
        break;
    }
}
