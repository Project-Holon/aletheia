/*
 * function: func_021BF924
 * address: 0x021BF924
 * packet: pkt_ov203_021BF924
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BE9E8 0x021BE9E8 thumb ov203
 *   func_0203115C 0x0203115C arm
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02049238 0x02049238 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 */
extern void func_021BE9E8(int),func_0203115C(void *),func_02005DE4(void *),func_02005DF8(int),func_02049238(void *),func_0201D83C(void *),func_02031140(void *);
extern int func_02005E9C(int);
void func_021BF924(char *p)
{
    if(*(int *)(p+0x2C)) func_021BE9E8(*(int *)(p+0x2C));
    func_0203115C(*(void **)(p+0x20));
    if(*(unsigned char *)(p+0x19)) {
        func_02005E9C(*(unsigned char *)(p+0x19));func_02005DE4(0);func_02005DF8(60);
    }
    func_02049238(*(void **)(p+0x28));func_0201D83C(*(void **)(p+0x24));func_02031140(*(void **)(p+0x20));
}
