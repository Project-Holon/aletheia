/*
 * function: DWCi_NdCleanupAsync
 * address:  0x021C651C
 * packet:   pkt_ov114_021C651C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlDWC/libdwcnd.TWL.HYB.a(dwci_nd.o).  decl_line 519, param callback.
 *
 * symbols:
 *   d_021D3B9C   0x021D3B9C  data
 *   nhttpCleanupCallback   0x021C64E0  arm
 */
typedef unsigned long u32;

extern char d_021D3B9C[];
extern int func_021C654C(void * volatile handle);
extern void func_021BE680(int a);
extern void nhttpCleanupCallback(void);

void DWCi_NdCleanupAsync(void *callback)
{
    *(u32 *)(d_021D3B9C + 8) = 0;
    *(void **)(d_021D3B9C + 0x24) = callback;
    func_021C654C(*(void **)(d_021D3B9C + 0x10));
    func_021BE680((int)nhttpCleanupCallback);
}
