/*
 * function: func_021BEF84
 * address: 0x021BEF84
 * packet: pkt_ov203_021BEF84
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 021BEFC2.
 * symbols:
 *   func_02023F60 0x02023F60 thumb
 *   func_021BF7AC 0x021BF7AC thumb ov203
 *   func_021BEFC4 0x021BEFC4 thumb ov203
 */
typedef unsigned int   u32;
struct Owner;
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern int func_021BF7AC(char *,int);
extern void func_021BEFC4(struct Owner *owner, int mask, int kind, int start, int end, int duration, int *counter);
void func_021BEF84(char *p,int unused,int *s)
{
    if(s[1]==0){func_02023F60((short)s[2],0x3f,s[0]);}
    else {func_021BEFC4((struct Owner *)p,s[0],0x3f,s[2],s[3],func_021BF7AC(p,s[1]),0);}
}
