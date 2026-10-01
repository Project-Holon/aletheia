/*
 * function: func_0218519C
 * address: 0x0218519C
 * packet: pkt_ov219_0218519C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 457B0 heap input is explicitly narrowed to u16 in original;
 * retain all observed narrow inputs to matching4D30 stack-byte interface.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02184968 0x02184968 thumb ov219
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02184D30 0x02184D30 thumb ov219
 *   func_02045808 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   d_02185DCB 0x02185DCB data ov219 a1
 */
typedef unsigned char u8;typedef unsigned short u16;
struct U16Vec;struct Descriptor;struct WordSet;struct MsgBank;
struct Record {struct Descriptor *descriptor;u8 active;};
extern struct U16Vec *func_020457B0(unsigned,u16);
extern struct Descriptor *func_02184968(const unsigned char *,int);
extern void func_0201F048(struct WordSet *,unsigned,unsigned),func_0201F094(struct WordSet *,unsigned,unsigned,unsigned);
extern void func_02045CAC(struct MsgBank *,unsigned,void *),func_0201F250(struct WordSet *,void *,void *);
extern void func_02184D30(char *,struct Record *,struct Descriptor *,void *,u8,u8);
extern void func_02045808(struct U16Vec *),func_0201F73C(void *,int,int,int),func_02045334(struct Descriptor *);
extern const unsigned char d_02185DCB[];
void func_0218519C(char *p)
{
    struct U16Vec *dst,*src;
    dst=func_020457B0(1024,*(unsigned *)p);src=func_020457B0(1024,*(unsigned *)p);
    *(struct Descriptor **)(p+0xc040)=func_02184968(d_02185DCB,1);
    func_0201F048(*(struct WordSet **)(p+0xc0a8),0,*(unsigned *)(p+0xc33c));
    func_0201F094(*(struct WordSet **)(p+0xc0a8),1,*(unsigned *)(p+0xc33c),*(unsigned *)(p+0xc340));
    func_02045CAC(*(struct MsgBank **)(p+0xc070),14,src);
    func_0201F250(*(struct WordSet **)(p+0xc0a8),dst,src);
    func_02184D30(p,(struct Record *)(p+0xc044),*(struct Descriptor **)(p+0xc040),dst,0,0);
    func_02045808(src);func_02045808(dst);
    func_0201F73C(*(void **)(p+0xc040),0,34,7);
    func_02045334(*(struct Descriptor **)(p+0xc040));
}
