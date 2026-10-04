/*
 * function: func_021E7D3C
 * address:  0x021E7D3C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBB64  0x021EBB64  thumb  ov170
 *   func_021E8F50  0x021E8F50  thumb  ov170
 *
 * candidate func_021E7D3C: state machine step
 */


extern void func_021EBB64(unsigned char *p, unsigned v, int i);
extern int func_021E8F50(char *p, int v);
void func_021E7D3C(char *p)
{
    int v;
    func_021EBB64((unsigned char *)((int)p), *(unsigned short *)(p + 0x10), 0x18);
    v = *(int *)(*(int *)p + 0x24);
    if (v == 3)
        *(int *)(p + 0x28) = 0x3c;
    else
        *(int *)(p + 0x28) = 0xe;
    func_021E8F50((char *)((int)p), 6);
}

