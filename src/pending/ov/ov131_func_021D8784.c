/*
 * function: func_021D8784
 * address: 0x021D8784
 * packet: pkt_ov131_021D8784
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x0202F688 and 0x0202F6D8 lack outside witnesses; scratch one
 * verified EXACT at 80 and 84 bytes respectively. Caller one MATCH*, tu MATCH.
 * blocker: 0x0202F688 thumb verified C:
 * unsigned int func_0202F688(unsigned int n) {
 *   if(n<0x7531) return 89;
 *   if(n<0x9c41) { if(n-0x7531>=14) return 89; return 92; }
 *   if(n<0xea61) { if(n-0x9c41>=109) return 89; return 90; }
 *   if(n<=65535) return 91;
 *   return 89;
 * }
 * blocker: 0x0202F6D8 thumb verified C:
 * unsigned int func_0202F6D8(unsigned int n) {
 *   if(n<0x7531) { if(n>=117) return 2; }
 *   else if(n<0x9c41) { n-=0x7531; if(n>=14) return 2; }
 *   else if(n<0xea61) { n-=0x9c41; if(n>=109) return 2; }
 *   else { if(n<=65535) { n-=0xea61; if(n>=3) return 0; } else return 2; }
 *   return n;
 * }
 * symbols:
 *   func_0202F688 0x0202F688 thumb
 *   func_0202F6D8 0x0202F6D8 thumb
 *   func_02045EC0 0x02045EC0 arm
 */

extern unsigned int func_0202F688(unsigned int);
extern unsigned int func_0202F6D8(unsigned int);
extern void *func_02045EC0(void *, unsigned int);
void func_021D8784(void *a, unsigned char *p, unsigned int n)
{
    unsigned int bank = func_0202F688(n);
    unsigned int index = func_0202F6D8(n);
    switch (bank) {
    case 89: func_02045EC0(*(void **)(p + 0x3c), index); break;
    case 92: func_02045EC0(*(void **)(p + 0x40), index); break;
    case 90: func_02045EC0(*(void **)(p + 0x44), index); break;
    case 91: func_02045EC0(*(void **)(p + 0x48), index); break;
    default: func_02045EC0(*(void **)(p + 0x3c), 0); break;
    }
}
