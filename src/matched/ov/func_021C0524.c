/*
 * function: func_021C0524
 * address:  0x021C0524
 * packet:   pkt_021C0524
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   (none)

 * Releases each of the 0x3D handles held from +0xDC on.
 */


struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_021C0524(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++)
        CLACT_DeleteActor((struct Obj *)(*(int *)(p + i * 4 + 0xdc)));
}

