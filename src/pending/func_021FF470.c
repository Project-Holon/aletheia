/*
 * function: func_021FF470
 * address:  0x021FF470
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocking: 02015FF0 has no witness outside the compared range (ov094 target, no outside caller attestation)
 *
 * Byte-identical to the original; parked because 02015FF0 has no witness outside the compared range (ov094 target, no outside caller attestation).
 */


extern int  func_022019F4(char *p, int key);
extern void func_02015FF0(int a, void *v);

void func_021FF470(char *p, int key, void *v)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return;
    e = p + i * 0x5c;
    if (*(int *)(e + 8) == 0)
        return;
    func_02015FF0(*(int *)(e + 8), v);
}

