/*
 * function: func_02184BAC
 * address: 0x02184BAC
 * packet: pkt_ov219_02184BAC
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 */
typedef unsigned short u16;
struct MsgBank;struct R;
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern struct R *func_02027F60(u16,u16,unsigned,unsigned,u16);
void func_02184BAC(char *p)
{
    *(void **)(p+0xc064)=func_02045EC0(*(struct MsgBank **)(p+0xc070),13);
    *(void **)(p+0xc068)=func_02045EC0(*(struct MsgBank **)(p+0xc070),16);
    *(struct R **)(p+0xc058)=func_02027F60(2,9,*(unsigned *)(p+0xc06c),*(unsigned *)(p+0xc080),(u16)*(unsigned *)p);
    *(void **)(p+0xc08c)=*(void **)(p+0xc064);
    *(u16 *)(p+0xc090)=0x39e3;*(unsigned *)(p+0xc094)=0;
    *(void **)(p+0xc098)=*(void **)(p+0xc068);
    *(u16 *)(p+0xc09c)=0x39e3;*(unsigned *)(p+0xc0a0)=1;
}
