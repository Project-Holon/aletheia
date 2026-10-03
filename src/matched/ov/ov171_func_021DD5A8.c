/*
 * function: func_021DD5A8
 * address: 0x021DD5A8
 * packet: pkt_ov171_021DD5A8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE5F4 0x021DE5F4 thumb ov171
 *   func_021DE0E4 0x021DE0E4 thumb ov171
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {s16 a,b;} Outputs;
extern int func_021DE5F4(char *);
extern void func_021DE0E4(u8 *,int,s16 *,s16 *);
int func_021DD5A8(u8 *p,int i)
{
    Outputs out;
    func_021DE0E4(p,(int)((u32)i+(u32)func_021DE5F4((char *)p)), &out.b, &out.a);
    if(out.b<128)return 1;
    return 0;
}
