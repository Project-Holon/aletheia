/*
 * function: func_021FF470
 * address:  0x021FF470
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015FF0  0x02015FF0  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 *
 * Byte-identical to the original; parked because the +0014 call to 0x02015FF0
 * (an unlabelled ARM9 leaf, no traced label) has no witness outside the
 * compared range.  The +0006 call to 0x022019F4 is an ov094 Thumb function.
 */


extern int  func_022019F4(char *p, int key);
extern void func_02015FF0(char *p, int v);

void func_021FF470(char *p, int key, void *v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (*(int *)(e + 8) == 0)
        return;
    func_02015FF0((char *)(*(int *)(e + 8)), (int)v);
}

