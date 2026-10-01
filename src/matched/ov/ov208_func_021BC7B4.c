/*
 * function: func_021BC7B4
 * address: 0x021BC7B4
 * packet: pkt_ov208_021BC7B4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202173C 0x0202173C thumb
 */
extern int func_0202173C(void *,unsigned short,unsigned short,short,unsigned char,unsigned char,unsigned short,void *);
void func_021BC7B4(char *p,short b,unsigned char c,unsigned char d)
{
    if(*(unsigned short *)(p+0xc)&1)func_0202173C(*(void **)(p+8),1,0x1fff,b,c,d,0,*(void **)p);
    if(*(unsigned short *)(p+0xc)&4)func_0202173C(*(void **)(p+8),4,0xff,b,c,d,0,*(void **)p);
    if(*(unsigned short *)(p+0xc)&2)func_0202173C(*(void **)(p+8),2,0x1fff,b,c,d,0,*(void **)p);
    if(*(unsigned short *)(p+0xc)&8)func_0202173C(*(void **)(p+8),8,0x3fff,b,c,d,0,*(void **)p);
}
