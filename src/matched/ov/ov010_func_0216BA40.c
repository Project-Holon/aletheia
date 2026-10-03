/*
 * function: func_0216BA40
 * address:  0x0216BA40
 * packet:   pkt_ov010_0216BA40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216BB90  0x0216BB90  thumb  ov010
 *   func_0216BB80  0x0216BB80  thumb  ov010
 *   func_0216BBB4  0x0216BBB4  thumb  ov010
 *   func_0216B970  0x0216B970  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0216BB90(int index, u8 *out);
extern int func_0216BB80(int index);
extern int func_0216BBB4(int index);
extern u32 func_0216B970();

int func_0216BA40(int c, int vm)
{
    int i;
    u8 buf[4];
    int n;

    func_0216BB90(vm, buf);
    n = (u8)func_0216BB80(vm);
    func_0216BBB4(vm);
    for (i = 0; i < n; i++) {
        if (func_0216B970(c, buf[i]) < 999999) {
            return 0;
        }
    }
    return 1;
}
