/*
 * function: func_021E543C
 * address: 0x021E543C
 * packet: pkt_ov170_021E543C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020260E4 has no outside code-start witness. Scratch one EXACT.
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_021EC61C 0x021EC61C thumb ov170
 *   func_021EF35C 0x021EF35C thumb ov170
 *   func_021EF36C 0x021EF36C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021ECB84 0x021ECB84 thumb ov170
 *   func_021EA1C0 0x021EA1C0 thumb ov170
 *   func_021E0068 0x021E0068 thumb ov170
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_021DF040 0x021DF040 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020061E4(unsigned);
extern void func_021EC61C(u8 *);
extern void func_021EF35C(int);
extern void func_021EF36C(int);
extern int func_021E8FC0(u8 *, int (*)(u8 *), int);
extern int func_021E01B0(u8 *);
extern void func_021ECB84(char *, unsigned);
extern void func_021EA1C0(u8 *);
extern int func_021E0068(u8 *);
extern void func_021DD530(u8 *);
extern void func_021EA1E8(u8 *);
extern void func_021DF040(char *);
extern void func_021EF3A0(int);
extern void func_020260E4(void *, u8);
extern void func_021EE3E4(char **, unsigned);
extern void func_021ED55C(char **, int);
int func_021E543C(u8 *p)
{
    switch (*(u32 *)(*(u8 **)(p + 44) + 0xa194)) {
    case 0:
        func_020061E4(0x669);
        func_021EC61C(p);
        func_021EF35C(*(int *)(*(u8 **)(p + 44) + 116));
        func_021EF36C(*(int *)(*(u8 **)(p + 44) + 116));
        p[26] = 2;
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0(p, func_021E01B0, 47);
    case 1:
        p[23] = p[20];
        func_021ECB84(*(char **)(p + 44), p[22]);
        func_021EA1C0(p);
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0(p, func_021E0068, 47);
    case 2:
        func_020061E4(0x669);
        func_021DD530(p);
        func_021EA1E8(p);
        func_021DF040((char *)p);
        func_021EF3A0(*(int *)(*(u8 **)(p + 44) + 116));
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0(p, func_021E01B0, 47);
    case 3:
        func_020260E4(*(void **)(*(u8 **)(p + 44) + 112), p[22]);
        func_021EE3E4((char **)p, p[22]);
        func_021ED55C((char **)p, 1);
        p[22] = 255;
        *(u32 *)(*(u8 **)(p + 44) + 0xa194) = 0;
        return 44;
    }
    return 47;
}
