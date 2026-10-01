/*
 * function: func_021B6B5C,func_021B6B8C,func_021B6B94
 * address: 0x021B6B5C
 * packet: pkt_ov174_021B6B5C
 * region: ov174
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: counter at +0x8a is read at 021B6BAA and reread at 021B6BB6 after store 021B6BB2.
 * symbols:
 *   func_021B68E8 0x021B68E8 thumb ov174
 *   func_021B6754 0x021B6754 thumb ov174
 *   func_021B6994 0x021B6994 thumb ov174
 *   func_021B7378 0x021B7378 thumb ov174
 * Extent includes clear-counter stub 021B6B8C and counter query 021B6B94.
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B68E8(char *);
extern void func_021B6754(char *);
extern void func_021B6994(char *);
extern void func_021B7378(char *);
int func_021B6B5C(char *p)
{
    if(func_021B68E8(p)==1) {
        func_021B6754(p);
        func_021B6994(p);
        func_021B7378(*(char **)(p+0x1c+*(u8 *)(p+0x88)*4));
        return 1;
    }
    return 0;
}
void func_021B6B8C(char *p)
{
    *(u16 *)(p+0x8a)=0;
}
int func_021B6B94(char *p)
{
    u8 threshold=*(u16 *)(*(char **)(p+0x40)+*(u8 *)(p+0x89)*4+2);
    ++*(volatile u16 *)(p+0x8a);
    if(*(volatile u16 *)(p+0x8a)>threshold) return 1;
    return 0;
}
