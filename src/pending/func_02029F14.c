/*
 * function: func_02029F14
 * address:  0x02029F14
 * packet:   pkt_02029E74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02029F6C label
 * blocker:  020A76BC literal
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   g_020A76BC     0x020A76BC  data
 *   g_02146944     0x02146944  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void  *func_02030734(u32 heap, u32 size, u32 flags, void *file, u32 line);
extern char   g_020A76BC[];
extern u32   *g_02146944;
extern void   func_02029F6C(void);

u32 *func_02029F14(u32 a0, u32 a1)
{
    u32 *p = func_02030734(a0, 0xc, 1, g_020A76BC, 0x72);

    *(u16 *)((char *)p + 4) = 0;
    p[2] = a1;
    g_02146944 = p;
    func_02029F6C();
    return p;
}
