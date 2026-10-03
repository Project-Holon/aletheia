/*
 * function: func_021BDDD0
 * address: 0x021BDDD0
 * packet: pkt_ov099_021BDDD0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201293C 0x0201293C thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA1C 0x0201AA1C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0201293C(const void *);
extern void *func_02012934(const void *);
extern u32 func_0201AA1C(void *);
int func_021BDDD0(char *p)
{
    func_0201293C(*(void **)(p + 0xc4));
    if ((int)func_0201AA1C(func_02012934(*(void **)(p + 0xc4))) >= 2) return 1;
    return 0;
}
