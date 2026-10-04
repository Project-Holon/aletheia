/*
 * function: func_02173EEC
 * address:  0x02173EEC
 * packet:   pkt_ov011_02173EEC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D578  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D578(int a, int b);
void func_02082D44(char *d, char *s, int n);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_02173EEC(char *a, char *b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x212) == 1) {
        return 0;
    }
    func_02082D44(b + 0x78, a + 0x3F0, 0x34);
    return func_0203D3F8((int)func_020399A8(), 0xFF, 0x212, 0x34, (u32)(a + 0x3F0), 0, 0, 1);
}
