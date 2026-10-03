/*
 * function: func_021E7D64
 * address: 0x021E7D64
 * packet: pkt_ov170_021E7D64
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021DF110 0x021DF110 thumb ov170
 *   func_021EF6A8 0x021EF6A8 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E01A8 0x021E01A8 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021ECB60 0x021ECB60 thumb ov170
 *   func_021EBBBC 0x021EBBBC thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void func_021EC000(char *, int, int);
extern void func_021ED508(u8 *, int, int);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(u8 *);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(u8 *, int (*)(u8 *), int);
extern int func_021E0190(u8 *);
extern unsigned func_021DD25C(void ***, unsigned short, int, unsigned, unsigned);
extern void func_021DF110(u8 *, unsigned);
extern void func_021EF6A8(struct WinMgr *mgr);
extern void func_020061E4(unsigned);
extern int func_021E01A8(u8 *);
extern void func_021EE364(char **, int, int);
extern void func_021ED888(char *, int);
extern void func_021ECB20(u8 *, int, int);
extern void func_021ECB60(char *, int, int);
extern void func_021EBBBC(u8 *, int);
extern int func_021E8F50(u8 *, int);
int func_021E7D64(u8 *p)
{
    switch (*(u32 *)(*(u8 **)(p + 44) + 0xa194)) {
    case 0:
        func_021EC000(*(char **)(p + 44), 4, 0);
        func_021ED508(p, 14, 0);
        func_021EBA5C(*(char **)(p + 44), 24);
        func_021DD14C(p);
        func_021EF57C(*(struct WinMgr **)(*(u8 **)(p + 44) + 116));
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0(p, func_021E0190, 85);
    case 1:
        *(u32 *)(*(u8 **)(p + 44) + 0xa174) = func_021DD25C((void ***)p, p[22], p[20], 11, 0);
        func_021DF110(p, *(u32 *)(*(u8 **)(p + 44) + 0xa174));
        func_021EF6A8(*(struct WinMgr **)(*(u8 **)(p + 44) + 116));
        func_020061E4(0x669);
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0(p, func_021E01A8, 85);
    case 2:
        func_021EE364((char **)p, 9, 0);
        func_021ED888(*(char **)(p + 44), 0);
        func_021ECB20(p, 1, 1);
        func_021ECB20(p, 2, 1);
        func_021ECB60(*(char **)(p + 44), p[22], 0);
        func_021EBBBC(p, 24);
        return func_021E8F50(p, 86);
    }
    return 85;
}
