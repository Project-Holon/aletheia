/*
 * function: func_021F3B88
 * address: 0x021F3B88
 * packet: pkt_ov051_021F3B88
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two-byte alignment padding at 0x021F3BC2 follows the return.
 * symbols:
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02188CD0 0x02188CD0 thumb ov021
 *   func_021C9064 0x021C9064 thumb ov021
 *   func_021C909C 0x021C909C thumb ov021
 *   func_021F3C98 0x021F3C98 thumb ov051
 * note: func_021C9064's result is stored and read by caller; extern preserves r0 despite its void definition.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 x,y,z; } V;
extern void func_0216D88C(const void *, V *);
extern u32 func_02188CD0(u8 *);
extern u32 func_021C9064(u32, V *, u32);
extern void func_021C909C(u32);
extern int func_021F3C98(int *, u32 *);
void func_021F3B88(int *a, u32 *out, u32 c)
{
    V v;
    out[0]=c;
    func_0216D88C((void *)c,&v);
    out[1]=func_021C9064(func_02188CD0((u8 *)a[2]),&v,out[0]);
    if(func_021F3C98(a,out)==1) func_021C909C(out[1]);
}
