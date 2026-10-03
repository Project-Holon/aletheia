/*
 * function: func_0200846C
 * address:  0x0200846C
 * packet:   pkt_0200846C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_020A70AC      0x020A70AC  data
 *   g_020A70C4      0x020A70C4  data
 *   g_0209DDB4      0x0209DDB4  data
 *   g_020A716C      0x020A716C  data
 */

extern char g_020A70AC[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Sub0200852CObj;
extern void func_020084A0(struct Sub0200852CObj *obj);
void *func_0200846C(int a0)
{
    void *p = func_02030734((unsigned short)a0, 0x20, 0, g_020A70AC, 0x34);
    func_020084A0(p);
    return p;
}
