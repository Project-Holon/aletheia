/*
 * function: func_02173D38
 * address:  0x02173D38
 * packet:   pkt_ov012_02173D38
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02008468  0x02008468  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;

struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
typedef unsigned int   u32;
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void func_02173D38(u8 *p)
{
    p[0x282B] = 0;
    func_0203D3F8((u32)func_020399A8(), 0, 0x140A, func_02008468(),
                  (u32)func_02012944((void *)(*(int *)(*(u8 **)p + 8))), 1, 0, 0);
}
