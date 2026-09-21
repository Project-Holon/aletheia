/*
 * function: func_02029EB4
 * address:  0x02029EB4
 * packet:   pkt_02029EB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02029E58  0x02029E58  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02029E74  0x02029E74  thumb
 *   func_02013C30  0x02013C30  thumb
 *   func_02029E64  0x02029E64  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_02029E58(void *a);
extern u32  func_02012A30(void *a);
extern u32  func_02029E74(void *a, u32 id);
extern int  func_02013C30(u16 id);
extern u32  func_02029E64(void *a, u32 id, u32 which);

u32 func_02029EB4(void *a, u32 id, u32 which)
{
    int mode;

    u32 r;

    mode = func_02029E58(a);
    func_02012A30(a);
    r = func_02029E74(a, id);
    if (r == (u32)-1) {
        if (mode == 2) {
            if (func_02013C30((u16)id)) {
                return 0x3f5;
            }
        }
        if (mode == 1) {
            if (func_02013C30((u16)id)) {
                return 0x3f4;
            }
        }
        return func_02029E64(a, id, which);
    }
    return r;
}
