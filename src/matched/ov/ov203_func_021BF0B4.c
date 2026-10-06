/*
 * function: func_021BF0B4
 * address: 0x021BF0B4
 * packet: pkt_ov203_021BF0B4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02023F60 0x02023F60 thumb
 *   func_02031194 0x02031194 arm
 */
struct TcblNode;
typedef unsigned int   u32;
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02031194(struct TcblNode *);
void func_021BF0B4(struct TcblNode *node,int *s)
{
    if(*(int *)((char *)s[0]+12)!=0){
        func_02023F60((short)s[6],s[3],s[2]);
        if(s[9]!=0)--*(int *)s[9];
        func_02031194(node);return;
    }
    if(s[4]-->0){func_02023F60((short)(s[7]>>12),s[3],s[2]);s[7]+=s[8];}
    else {func_02023F60((short)s[6],s[3],s[2]);if(s[9]!=0)--*(int *)s[9];func_02031194(node);}
}
