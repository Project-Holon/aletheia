/*
 * function: func_021E695C
 * address: 0x021E695C
 * packet: pkt_ov170_021E695C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Assign selection = 0 after the setter getter in case 1's else arm;
 *   a function-entry initializer hoists zero into the switch dispatch (256 B DIFF).
 * symbols:
 *   func_021DF040 0x021DF040 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EF3EC 0x021EF3EC thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021DF040(char *);
extern void func_021EC000(char *, int, int);
extern void func_021EF3A0(int);
extern void func_021ED888(char *, int);
extern void func_021ECB20(u8 *, int, int);
extern void func_021EF3EC(int);
extern void func_020061E4(unsigned);
extern int func_021E8FC0(u8 *, int (*)(u8 *), int);
extern int func_021E01B0(u8 *);
extern void func_021ED544(u8 *, int);
extern void func_021ED508(u8 *, int, int);
extern void func_021EE038(u8 *, int, int, int);
extern u8 func_020260E0(void *);
extern void func_021EE364(char **, int, int);
extern void func_021DEFEC(u8 *, int);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
int func_021E695C(u8 *p)
{
    u8 index;
    u8 selection;
    switch (*(u32 *)(*(u8 **)(p + 44) + 0xa194)) {
    case 0:
        func_021DF040((char *)p);
        func_021EC000(*(char **)(p + 44), 4, 0);
        if (p[30] == 0) {
            func_021EF3A0(*(int *)(*(u8 **)(p + 44) + 116));
        } else {
            func_021ED888(*(char **)(p + 44), 0);
            func_021ECB20(p, 1, 1);
            func_021EF3EC(*(int *)(*(u8 **)(p + 44) + 116));
        }
        func_020061E4(0x669);
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return func_021E8FC0(p, func_021E01B0, 65);
    case 1:
        *(u32 *)(*(u8 **)(p + 44) + 0xa194) = 0;
        func_021ED544(p, 6);
        func_021ED508(p, 14, 1);
        func_021EE038(p, 0, 0, 1);
        if (p[30] == 0) {
            index = func_020260E0(*(void **)(*(u8 **)(p + 44) + 112));
            if (index >= 36)
                index = 0;
            else if (index >= 30)
                index = 0;
            func_021EE364((char **)p, 7, index);
            func_021DEFEC(p, index);
            func_021EF670(*(char **)(p + 44));
            return 57;
        } else {
            index = func_020260E0(*(void **)(*(u8 **)(p + 44) + 112));
            selection = 0;
            if (index < 36 && index >= 30)
                selection = index - 30;
            func_021EE364((char **)p, 8, selection);
            func_021DEFEC(p, selection + 30);
            func_021EF68C(*(char **)(p + 44));
            return 70;
        }
    }
    return 65;
}
