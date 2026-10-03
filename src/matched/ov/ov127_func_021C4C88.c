/*
 * function: func_021C4C88
 * address: 0x021C4C88
 * packet: pkt_ov127_021C4C88
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C601C 0x021C601C data a4
 */
typedef unsigned short u16;
struct pair {u16 a,b;};
extern void (*d_021C601C)(char *,struct pair,unsigned);
void func_021C4C88(char *p,char *q)
{
 (*(void (**)(char *,struct pair,unsigned))((unsigned)&d_021C601C+*(u16 *)(q+4)*4))(p,*(struct pair *)q,*(unsigned char *)(q+6));
 *(u16 *)(p+22)=0;
}
