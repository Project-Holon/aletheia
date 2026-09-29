/*
 * function: func_021E1B4C
 * address:  0x021E1B4C
 * packet:   pkt_ov093_021E1B4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D54E0  0x021D54E0  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern u8 func_021D5448(void *q);
extern u32 func_021D54C0(void *q, u8 i);
extern u32 func_021D54E0(void *q, u8 i);
extern int func_021D76BC(int key, int val);

void func_021E1B4C(int a, void *p, int id)
{
    void *q;
    u8 n;
    u8 i;
    u8 cnt;
    int flag;
    if (id == func_021D775C(2)) {
        q = func_021C7CF4(p, id);
        n = func_021D5448(q);
        cnt = 0;
        flag = 0;
        for (i = 0; i < n; i++) {
            if (func_021D54C0(q, i) == 0x183) {
                flag = 1;
            } else if (func_021D54E0(q, i)) {
                cnt++;
            }
        }
        if (flag == 0 || n < 2 || cnt < n - 1)
            func_021D76BC(0x22, 0x1a);
    }
}
