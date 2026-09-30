/*
 * unit: yes
 * function: func_021F6B80, func_021F6B9C, func_021F6BB0
 * address: 0x021F6B80
 * packet: pkt_ov112_021F6B80
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204F5A8 0x0204F5A8 arm
 *   func_0204F150 0x0204F150 arm
 */
typedef unsigned int u32;
extern void func_0204F5A8(void *, u32);
extern void func_0204F150(void *, int);
void func_021F6B80(u32 *a, u32 *b)
{
    func_0204F5A8((void *)a[1], b[6]);
    func_0204F150((void *)a[1], b[5]);
    b[0]=0;
}
void func_021F6B9C(void *a, u32 *b, u32 *c)
{
    b[2]=c[0]; b[3]=c[1]; b[4]=c[2]; b[1]=1;
}
void func_021F6BB0(void *a, u32 *b, u32 *c)
{
    c[0]=b[2]; c[1]=b[3]; c[2]=b[4];
}
