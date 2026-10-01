/*
 * function: func_021BDA40
 * address: 0x021BDA40
 * packet: pkt_ov204_021BDA40
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BDC18 0x021BDC18 thumb ov204
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_021BF594 0x021BF594 thumb ov204
 *   func_021BF8DC 0x021BF8DC thumb ov204
 *   func_021BFC24 0x021BFC24 thumb ov204
 *   func_021BEF20 0x021BEF20 thumb ov204
 *   ov067_id 0x00000043 data
 */
struct Obj0203159C; struct GfFont; struct MsgBank;
extern int func_02034AC4(int);
extern void func_0203064C(void *, unsigned, unsigned);
extern char *func_0203159C(struct Obj0203159C *, unsigned, unsigned);
extern void func_02082BCC(void *, unsigned, unsigned);
extern unsigned char *func_021BDC18(int, int, unsigned short);
extern struct GfFont *func_0201D7EC(int, int, int, int, unsigned);
extern struct MsgBank *func_02045B38(unsigned, unsigned, unsigned, unsigned);
extern char *func_021BF594(unsigned short, int);
extern void *func_021BF8DC(unsigned char *, int, unsigned short);
extern void *func_021BFC24(unsigned char *, unsigned short);
extern char *func_021BEF20(void *, unsigned, unsigned, char *, unsigned, unsigned short);
extern const char ov067_id[];
int func_021BDA40(struct Obj0203159C *owner, int unused, char *args)
{
    char *p;
    func_02034AC4((int)ov067_id);
    func_0203064C((void *)1, 111, 0x100000);
    p = func_0203159C(owner, 0x24, 111);
    func_02082BCC(p, 0, 0x24);
    *(unsigned short *)p = 111;
    *(char **)(p + 4) = args;
    *(unsigned char **)(p + 8) = func_021BDC18(1, *(int *)(args + 8), *(unsigned short *)p);
    *(struct GfFont **)(p + 0xC) = func_0201D7EC(23, 0, 0, 0, *(unsigned short *)p);
    *(struct MsgBank **)(p + 0x10) = func_02045B38(0, 2, 65, *(unsigned short *)p);
    *(char **)(p + 0x18) = func_021BF594(*(unsigned short *)p, *(int *)(*(char **)(p + 4) + 8));
    *(void **)(p + 0x1C) = func_021BF8DC(*(unsigned char **)(p + 8), *(int *)(*(char **)(p + 4) + 8), *(unsigned short *)p);
    *(void **)(p + 0x20) = func_021BFC24(*(unsigned char **)(p + 8), *(unsigned short *)p);
    *(char **)(p + 0x14) = func_021BEF20(*(void **)(p + 0x1C), *(unsigned *)(p + 0x20), *(unsigned *)(p + 0x18), *(char **)(p + 4), *(unsigned *)(p + 8), *(unsigned short *)p);
    return 1;
}
