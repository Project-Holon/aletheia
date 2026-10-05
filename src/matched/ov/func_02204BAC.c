/*
 * function: func_02204BAC
 * address:  0x02204BAC
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02204BAC   0x02204BAC  thumb
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021F8884 0x021F8884 thumb ov094
 *   func_0220687C 0x0220687C thumb ov094

 *
 * lane O10 candidate
 */

extern void *func_021F8678(void);
extern void func_021F8884(int a);
extern void func_0220687C(char *p, void *q);

void func_02204BAC(int a, int *b)
{
    if (func_021F8678() != 0) {
        func_021F8884(b[1]);
        func_0220687C((char *)b[0], (void *)a);
    }
}

