/*
 * function: func_02029F6C
 * address:  0x02029F6C
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02029FD0 label
 * blocker:  02029FE4 label
 *
 * symbols:
 *   func_02029FD0  0x02029FD0  thumb
 *   func_02029FE4  0x02029FE4  thumb
 *   func_0203508C  0x0203508C  arm
 *   g_02146944     0x02146944  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32  g_02146944;
extern void func_02029FD0(void);
extern void func_02029FE4(void);
extern void func_0203508C(void *a, void *b, u32 c);

void func_02029F6C(void)
{
    if (g_02146944 != 0) {
        func_0203508C((void *)func_02029FD0, (void *)func_02029FE4, g_02146944);
    }
}
