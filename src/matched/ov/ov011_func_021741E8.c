/*
 * function: func_021741E8
 * address:  0x021741E8
 * packet:   pkt_ov011_021741E8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
void func_02082D44(void *d, void *s, int n);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_021741E8(char *a, char *b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x218) == 1) {
        return 0;
    }
    func_02082D44(b + 0xac, a + 0x424, 0x3c);
    return func_0203D3F8((int)func_020399A8(), 0xff, 0x218, 0x3c, (u32)(a + 0x424), 0, 0, 1);
}
