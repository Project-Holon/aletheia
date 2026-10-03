/*
 * function: func_021DE684
 * address: 0x021DE684
 * packet: pkt_ov171_021DE684
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE5F4 0x021DE5F4 thumb ov171
 *   func_021DE0E4 0x021DE0E4 thumb ov171
 *   func_0204B800 0x0204B800 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021DE5F4(char *);
extern void func_021DE0E4(u8 *,int,s16 *,s16 *);
struct Node;
extern void func_0204B800(struct Node *node, u32 val);
void func_021DE684(u8 *p)
{
    u8 order[6];
    s16 a[2],b[2];
    int start=func_021DE5F4((char *)p);
    u8 i,j,t;
    void *r;
    for(i=0;i<6;i++) order[i]=start+i;
    for(i=0;i<*(u16 *)(p+*(s8 *)(p+0xc5e)*0xbc+0xc4)-1;i++) {
        func_021DE0E4(p,order[i],&a[1],&a[0]);
        for(j=i+1;j<*(u16 *)(p+*(s8 *)(p+0xc5e)*0xbc+0xc4);j++) {
            func_021DE0E4(p,order[j],&b[1],&b[0]);
            if(a[0]<b[0]) {t=order[i];order[i]=order[j];order[j]=t;a[0]=b[0];}
        }
    }
    for(i=0;i<*(u16 *)(p+*(s8 *)(p+0xc5e)*0xbc+0xc4);i++) {
        r=*(void **)(p+order[i]*4+0xb74);
        if(r) func_0204B800(r,i);
    }
}
