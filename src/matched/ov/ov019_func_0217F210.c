/*
 * function: func_0217F210
 * address: 0x0217F210
 * packet: pkt_ov019_0217F210
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0217F098 0x0217F098 thumb ov019
 *   func_0217EE90 0x0217EE90 thumb ov019
 *   func_0217F188 0x0217F188 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0217F098(u8 *p, int a);
extern void func_0217EE90(void *p);
extern void func_0217F188(char *p, u32 a);
void func_0217F210(u8 *p, int a, u32 b)
{
    func_0217F098(p, a);
    func_0217EE90(p);
    func_0217F188((char *)p, b);
}
