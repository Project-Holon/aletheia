/*
 * function: func_0201DADC
 * address:  0x0201DADC
 * packet:   pkt_0201DADC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0209E744  0x0209E744  data
 */

typedef unsigned int u32;

extern void *g_0209E744[];

void func_0201DADC(void *ptr)
{
    typedef void (*FuncPtr)(void *);
    u32 idx = *(u32 *)ptr;
    FuncPtr fn = (FuncPtr)g_0209E744[idx];
    fn(ptr);
}
