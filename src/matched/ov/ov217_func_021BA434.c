/*
 * function: func_021BA434
 * address: 0x021BA434
 * packet: pkt_ov217_021BA434
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 * symbols:
 *   func_021C09B4 0x021C09B4 thumb ov217
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 */
extern unsigned func_021C09B4(void *);
extern void *func_0201296C(unsigned);
extern unsigned func_020142E8(void *,int);
unsigned char func_021BA434(char *p)
{
    void *bitmap=func_0201296C(func_021C09B4(*(void **)p));
    int count=1;
    if(func_020142E8(bitmap,240)==1)count++;
    if(func_020142E8(bitmap,241)==1)count++;
    if(func_020142E8(bitmap,242)==1)count++;
    if(func_020142E8(bitmap,243)==1)count++;
    if(func_020142E8(bitmap,244)==1)count++;
    if(func_020142E8(bitmap,245)==1)count++;
    if(func_020142E8(bitmap,246)==1)count++;
    if(func_020142E8(bitmap,247)==1)count++;
    if(func_020142E8(bitmap,248)==1)count++;
    return count;
}
