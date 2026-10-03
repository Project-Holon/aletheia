/*
 * function: func_021D3554
 * address:  0x021D3554
 * packet:   pkt_021D3554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D3554 0x021D3554 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_02013D74 0x02013D74 thumb
 *   func_020142E8 0x020142E8 thumb
 *   g_021DD944    0x021DD944 data
 */

typedef unsigned short u16;

extern void *func_0201296C(void *);
typedef signed int     s32;
typedef unsigned int   u32;
extern int func_02013D74(u32 key);
extern u32 func_020142E8(void *bitmap, s32 id);

struct Entry {
    u16 key;
    u16 val;
};

extern struct Entry g_021DD944[];

int func_021D3554(void *arg0, int arg1)
{
    void *r4 = func_0201296C(arg0);
    if (func_02013D74(arg1) == 1) {
        unsigned int i;
        for (i = 0; i < 25; i++) {
            if (arg1 == g_021DD944[i].key) {
                if (func_020142E8(r4, g_021DD944[i].val) == 1) {
                    return 1;
                }
                return 0;
            }
        }
    }
    return 1;
}
