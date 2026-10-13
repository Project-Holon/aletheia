/*
 * function: ARC_TOOL_DeleteHandle
 * address:  0x02049238
 * packet:   pkt_02049238
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   FS_CloseFile 0x02078A80 arm
 */

extern void FS_CloseFile(void *p);
extern unsigned int func_020307B0(void *p);

void ARC_TOOL_DeleteHandle(void *arc)
{
    FS_CloseFile(arc);
    func_020307B0(arc);
}
