/*
 * function: func_021DD528
 * address: 0x021DD528
 * packet: pkt_ov119_021DD528
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern void func_02049238(void *);
void func_021DD528(char *p,int n)
{
    void *v;int off;int a;v=func_020490F4(7,*(u16 *)(p+0x5f4));off=96;if(n!=1)off=0;*(int *)(p+0x890)=func_0204ACEC(v,func_0201BC3C(),n,(u16)off,*(u16 *)(p+0x5f4));a=func_0201BC78();*(int *)(p+0x8c0)=func_0204AF28(v,a,func_0201BCB4(),*(u16 *)(p+0x5f4));func_02049238(v);
}
