/*
 * function: func_0689905C
 * address: 0x0689905C
 * packet: pkt_ov095_0689905C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_06899098 0x06899098 thumb ov095
 *   func_068990A8 0x068990A8 thumb ov095
 *   func_068990B8 0x068990B8 thumb ov095
 *   func_068990C8 0x068990C8 thumb ov095
 *   func_068990D8 0x068990D8 thumb ov095
 */
typedef unsigned char u8;
extern int func_06899098(int);
extern int func_068990A8(int);
extern int func_068990B8(int);
extern int func_068990C8(int);
extern int func_068990D8(int, int);
void func_0689905C(int a0, int a1, int value, int *out)
{
    u8 v;
    v = func_06899098(2);
    if (value == func_068990A8(v)) {
        if (func_068990B8(0x20) < 0) {
            if (v != func_068990C8(3)) {
                *out = func_068990D8(0x41, 1);
            }
        }
    }
}
