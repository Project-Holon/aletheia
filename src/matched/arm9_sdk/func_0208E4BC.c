/*
 * function: WMi_GetSystemWork
 * address:  0x0208E4BC
 * packet:   pkt_0208E4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gWmSystemWork  0x02153058  data
 *
 * Global state member accessor.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WMi_GetSystemWork.c \
 *       --func WMi_GetSystemWork --addr 0x0208E4BC --arm
 */

struct Struct_02153058 {
    void *pad0;
    void *val;
};

extern struct Struct_02153058 gWmSystemWork;

void *WMi_GetSystemWork(void)
{
    return gWmSystemWork.val;
}
