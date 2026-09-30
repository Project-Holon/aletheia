/*
 * function: func_021D8EC4
 * address: 0x021D8EC4
 * packet: pkt_ov123_021D8EC4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02009294 0x02009294 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8E98 0x021D8E98 thumb ov123
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void *func_02009448(void *);
extern void func_020307B0(void *);
extern void *func_02007A18(void *,int,int);
extern void *func_0201747C(void *,u16);
extern void func_02009294(void *,void *);
extern void func_02007664(void *,int,int);
extern void func_020092F8(void *,u8);
extern void func_021D62B4(void *,int);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8E98(void);
void func_021D8EC4(char *p)
{
    void *v;
    void *q;
    void *t;
    v=func_02009448(*(void **)(p+0x28));
    if (*(void **)(p+0xc)) {
        func_020307B0(*(void **)(p+0xc));
        *(void **)(p+0xc)=0;
    }
    t=func_02007A18(*(void **)(p+0x24),*(int *)(p+0x48),*(int *)(p+0x4c));
    if (t) {
        q=func_0201747C(t,*(u16 *)p);
        func_02009294(v,q);
        *(void **)(p+0xc)=q;
        func_02007664(*(void **)(p+0x24),*(int *)(p+0x48),*(int *)(p+0x4c));
        func_020092F8(v,1);
        *(u8 *)(p+0xaa)=1;
    }
    func_021D62B4(*(void **)(p+0x14),0);
    func_021D62B4(*(void **)(p+0x14),12);
    func_021D6EE0(p,(int)func_021D8E98,0xa2a);
}
