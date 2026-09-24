/*
 * function: func_021BD880
 * address:  0x021BD880
 * packet:   pkt_021BD880
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)

 * BLOCKED.  DIFF: the listing order is ldrh/ldr/strh where the compiler emits ldrh/strh/ldr; two rewrites of the first block did not close it.
 */


extern void func_0204B878(int);
extern void func_020061E4(int);

void func_021BD880(char *p)
{
    unsigned short h = *(unsigned short *)(p + 0x28);
    int v = *(int *)p;

    *(unsigned short *)(p + 8) = h;
    func_0204B878(v);
    if (*(int *)(p + 0x30) != 0)
        func_020061E4(*(int *)(p + 0x30));
}
