/*
 * function: func_021FC6A4
 * address: 0x021FC6A4
 * packet: pkt_ov186_021FC6A4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02200D5C 0x02200D5C data a1
 */
extern const char d_02200D5C[];
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void *func_020457B0(unsigned,unsigned short);
extern void *func_020450F0(unsigned char,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d),func_02045374(void *);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
void *func_021FC6A4(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap)
{
    char *p;
    void *bmp;
    p=func_02030734(heap,0x24,0,d_02200D5C,0x5f);
    func_02082BCC(p,0,0x24);
    *(unsigned short *)(p+0x14)=0;
    *(void **)(p+8)=owner;
    *(unsigned short *)(p+0x16)=plane;
    *(void **)(p+0x10)=func_020457B0(0xff,heap);
    bmp=func_020450F0(plane,a,b,c,d,e,1);
    *(void **)(p+0xc)=bmp;
    *(void **)p=bmp;
    p[4]=0;
    func_02043B5C(func_02045770(bmp),*(unsigned short *)(p+0x14));
    bmp=*(void **)(p+0xc);
    func_02045334(bmp);
    func_02045374(bmp);
    func_020409B4(func_02045730(bmp));
    return p;
}
