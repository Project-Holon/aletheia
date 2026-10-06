/*
 * function: func_021D7200
 * address: 0x021D7200
 * packet: pkt_ov116_021D7200
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 func_0200FB4C 0x0200FB4C, unlabelled code has no outside witness.
 * Verified C: EXACT in scratch blocker-1.log, 32 bytes, Thumb:
 * extern unsigned char g_0214617C[], g_021461BC[];
 * void func_0200FB4C(int a) {
 *   if (*(int *)(g_0214617C+44)!=2) {
 *     *(int *)(g_0214617C+96)=a;
 *     g_021461BC[26]=1; g_021461BC[25]=1;
 *     *(int *)(g_0214617C+44)=2;
 *   }
 * }
 * Blocker symbols: g_0214617C 0x0214617C data; g_021461BC 0x021461BC data.
 * symbols:
 *   func_0200FB4C 0x0200FB4C thumb
 */
extern void func_0200FB4C(unsigned int x);
int func_021D7200(int *p) {
    int v;
    if(p[3]==3) {
        switch(p[4]) {
        case 200: case 400: v=65; break;
        case 401: v=66; break;
        case 408: v=68; break;
        default: v=67; break;
        }
        func_0200FB4C(v);
        return 1;
    }
    return 0;
}
