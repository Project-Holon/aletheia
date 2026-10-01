/*
 * function: func_021B9914
 * address: 0x021B9914
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9914
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_02047910 0x02047910 arm
 *   func_02011590 0x02011590 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02048A18(unsigned char *,int);
extern int func_0204779C(int *);
extern int func_02047910(void *,int,int);
extern u32 func_02011590(void *,int);
extern void *func_021BC52C(void *);
extern void func_02011B8C(void *,void *);
void func_021B9914(char *p)
{
    int *obj;
    u32 n;
    u16 i,j;
    for(i=0;i<*(u16 *)(p+58);i++) {
        obj=func_02048A18(*(unsigned char **)(p+40),*(u16 *)(*(char **)(p+60)+i*68));
        n=func_0204779C(obj);
        for(j=0;j<n;j++) func_02047910(obj,j,2048);
    }
    func_02011590(*(void **)(p+64),2048);
    func_02011B8C(func_021BC52C(*(void **)(p+20)),*(void **)(p+64));
    (*(u32 *)(p+80))++;
}
